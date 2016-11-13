
#include "PNPAddOns.h"
#define NOP() asm("nop");

/**

Miata Wheel:

 CAM 1pulse
Tooth 0 - 80BTDC #1
   70
Tooth 1 - 10BTDC #1
  110
Tooth 2 - 80BTDC #3
   70
Tooth 3 - 10BTDC #3
  110 and CAM 2pulses
Tooth 4 - 80BTDC #4
   70
Tooth 5 - 10BTDC #4
  110
Tooth 6 - 80BTDC #2
   70
Tooth 7 - 10BTDC #2
  110

*/

#define CLK16  0b01001100
#define CHN1   0b11100000

#define NOSYNC   0
#define SYNC1    1
#define FULLSYNC 2

#define KNK_SELECT()   PORTB &= ~_BV(PB5);
#define KNK_DESELECT() PORTB |= _BV(PB5);

#define SPISETUP()   SPCR = 0b01010100; // master enabled, clk/4 (4MHz), CPOL=0, CPHA=1

void knock_stop_measurement();
void knock_cache_slope();
U16 knock_get_threshold(U16 rpm);

U8 knockReadFlag;
U8 settingsChangedFlag;
U8 camCount = 0;
U8 sync = 0;
U8 tooth = 0;
U8 lastcylinder = 0;

U16 times[8];
U16 knockCount[4]; // local copy due to need to swap bytes all the time
signed int kslope[TABLESIZE];  // precompute slope at each config interval to get rid of unecessary division


void knock_init()
{
	EICRB  |= 0x0F; // int on rising edge INT4 and INT5 for cam/crank signals
	EIMSK  |= _BV(INT4) | _BV(INT5); // enable interupts

	TCCR1A = 0; 		 // OCpins disconnected
	TCCR1B = 0b00000011; // clk/64 (4uS ticks), regular count
	TCCR1C = 0;
	TIMSK1 = 0; // no interrupts yet
	//OCR1B use for triggering next event

	knockReadFlag = 0;
	settingsChangedFlag = 0;
	memset(times, 0, sizeof(times));
	memset(knockCount, 0, sizeof(knockCount));

	knock_stop_measurement();

	// Setup the TPIC8101
	SPISETUP();
	knock_write(CLK16); // set CLK=16MHz
	knock_write(CHN1);  // set channel 1
	knock_write(0x00 | config.filterIndex);
	knock_write(0x80 | config.gainIndex);
	knock_write(0xC0 | config.integratorIndex);
	knock_write(0b01110001); // set advanced mode
	// SPDR should equal 10001110 on next read
	knock_cache_slope();
}

// precalcuate static slope values whenever we get a config change, extra *8 multiplier added for resolution
void knock_cache_slope()
{
	U8 ii;
	for (ii = 1; ii < TABLESIZE; ii++)
	{
		signed int x0 = SWAP16(config.krpm[ii-1]);
		signed int x1 = SWAP16(config.krpm[ii]);
		signed int y0 = SWAP16(config.kthreshold[ii-1]);
		signed int y1 = SWAP16(config.kthreshold[ii]);
		kslope[ii] = (y1 - y0) * 256 / (x1 - x0);
	}
}

U16 knock_get_threshold(U16 rpm)
{
	U8 ii;
	for (ii = 1; ii < TABLESIZE; ii++)
	{
		if (rpm < SWAP16(config.krpm[ii]))  // use previous
		{
			U16 x0 = SWAP16(config.krpm[ii-1]);
			U16 y0 = SWAP16(config.kthreshold[ii-1]);
			signed int temp = kslope[ii] * (rpm - x0);
			U16 threshold = y0  +  (temp >> 8);  // remove the x256 multiplier here 
			return threshold;	
		}
	}

	return 0xFFFF;
}

void knock_sensor_setting_changed()
{
	settingsChangedFlag = 1;
}

void knock_start_measurement(U16 stopat)
{
	OCR1B = stopat;  // overflow works in our favor
	TIFR1  |= _BV(OCF1B); // clear any open OC1B interrupt
	TIMSK1 |= _BV(OCF1B); // enable interrupt for OC1B
	PORTB |= _BV(PB4); // WINDOW ON
}

void knock_stop_measurement()
{
	TIMSK1 &= ~_BV(OCF1B); // clear interrupt for OC1B
	PORTB &= ~_BV(PB4); // WINDOW OFF
}

/* 
	write the command and get the resposne, adds some delays around de/select (62.5ns)
 	for finallity based on tpic8101 datasheet.  Probably not necessary due to natural
	delays in the movement of the SPI system but just in case.
*/
U8 knock_write(U8 byte) 
{
	KNK_SELECT();
	NOP();

	SPDR = byte; 
	while(!(SPSR & (1<<SPIF)));

	NOP();
	KNK_DESELECT();
	return SPDR;
}


/* called during main loop */
void knock_main()
{
	signed int ticks;
	U16 level, rpm;
	U8 cyl;

	if (settingsChangedFlag)
	{
		knock_stop_measurement(); // window can't be on

		knock_write(0x00 | config.filterIndex);
		knock_write(0x80 | config.gainIndex);
		knock_write(0xC0 | config.integratorIndex);
		knock_cache_slope();

		knockReadFlag = 0;  // clear all our flags
		settingsChangedFlag = 0;
		return;
	}

	if (knockReadFlag)
	{
		if (sync == FULLSYNC)
		{
			cyl = lastcylinder - 1;

			knock_write(CLK16);
			level = knock_write(CHN1); // repsonse to CLK16 (see advanced mode)
			level = (knock_write(CHN1) << 2) | level; // response to first CHN1

			ticks = times[tooth] - times[(tooth+4)%8];
			if (ticks < 0)	
				ticks = 0x00FFFF - ticks;
			rpm = 15000000/ticks;
			data.myrpm = SWAP16(rpm);
			data.cylnoise[cyl] = SWAP16(level);

			U16 threshold = knock_get_threshold(rpm);
			if (level > threshold)
			{
				knockCount[cyl]++;
				data.cylknkcount[cyl] = SWAP16(knockCount[cyl]);
				data.flags |= FLAG_KNOCK;
			}
			else
			{
				data.flags &= ~FLAG_KNOCK;
			}
		}

		knockReadFlag = 0;
	}
}


/* Knock timer */
ISR(TIMER1_COMPB_vect)
{
	knock_stop_measurement();
	knockReadFlag = 1;      // let main function know its time to read in measure
}


/* CAM Signal */
ISR(INT5_vect)
{
	camCount++;
}


/**
	Crank signal
	This will tell us when we are 10BTDC as well as determining the degrees per clock tick
	that the engine is currently turning.  Tooth sync is done by cam signal input.
*/
ISR(INT4_vect)
{
	U16 now = TCNT1;  // 4uS/tick
	tooth = (tooth + 1)%8; // inc our tooth count
	times[tooth] = now;

	if (sync == NOSYNC)
	{
		if (camCount == 1)
		{
			sync = SYNC1;
			tooth = 0;
		}
		else if (camCount == 2)
		{
			sync = SYNC1;
			tooth = 4;
		}
		// else can't sync until we see one of the cam sides
	}
	else if (sync == SYNC1)
	{
		if (((camCount == 1) && (tooth == 0)) || ((camCount == 2) && (tooth == 4)))
		{
			sync = FULLSYNC;
			data.flags |= FLAG_SYNC;
		}
		else if (camCount != 0) // got cam but bad tooth, reset
		{
			sync = NOSYNC;
		}

	}
	else // should be synced here, double check sanity
	{
		if ((camCount > 2) || ((camCount == 1) && (tooth != 0)) || ((camCount == 2) && (tooth != 4)))
		{
			sync = NOSYNC; 
			data.flags &= ~FLAG_SYNC; 
			data.lostcount += 1;
		}
	}

	camCount = 0; // reset

	if (sync == FULLSYNC)
	{
		switch (tooth)
		{
			case 1: lastcylinder = 1; break;
			case 3: lastcylinder = 3; break;
			case 5: lastcylinder = 4; break;
			case 7: lastcylinder = 2; break;
		}

		// start measurements on 1,3,5,7 (10BTDC) but only if we aren't updating settings
		if ((!settingsChangedFlag) && (tooth & 0x01))
		{
			knock_start_measurement(now + (now - times[tooth-1]));  // we want to wait another 70 deg
		}
	}
}




