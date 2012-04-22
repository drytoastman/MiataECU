
#include "PNPAddOns.h"
#define NOP() asm("nop");

/**

Miata Wheel:

 CAM 1pulse
Tooth 1 - 80BTDC #1
   70
Tooth 2 - 10BTDC #1
  110
Tooth 3 - 80BTDC #3
   70
Tooth 4 - 10BTDC #3
  110 and CAM 2pulses
Tooth 5 - 80BTDC #4
   70
Tooth 6 - 10BTDC #4
  110
Tooth 7 - 80BTDC #2
   70
Tooth 8 - 10BTDC #2
  110

For calculating knock window we have the latest number of ticks to go 70deg.
We want to get the ticks for 20 and 50 degrees but we don't have a div operator.
Instead we add together divisions using powers of 2 for quick approximate

70/4 + 70/32 = 19.69deg  (ticks>>2 + ticks>>5)  or (ticks * 9/32)
70/2 + 70/4  = 52.50deg  (ticks>>1 + ticks>>2)  or (ticks * 3/4)


*/

#define MODE_NONE 0
#define MODE_WAIT 1
#define MODE_MEASURE 2
#define MODE_BLOCKED 3

#define TABLESIZE 32
#define CLK16  0b01001100
#define CHN1   0b11100000

#define WINDOW_ISON()  (PORTB & _BV(PB4))
#define WINDOW_ON()    PORTB |= _BV(PB4)
#define WINDOW_OFF()   PORTB &= ~_BV(PB4);

#define KNK_SELECT()   PORTB &= ~_BV(PB5);
#define KNK_DESELECT() PORTB |= _BV(PB5);

#define DEGREES_20 ((ticksFor70>>2) + (ticksFor70>>5))
#define DEGREES_52 ((ticksFor70>>1) + (ticksFor70>>2))
#define SPISETUP()   SPCR = 0b01010100; // master enabled, clk/4 (4MHz), CPOL=0, CPHA=1

void stop_measurement();

U8 knockMode;
U8 knockReadFlag;
U8 settingsChangedFlag;

U16 times[8];
U16 knockCount[4]; // local copy due to need to swap bytes all the time
U16 ticksFor70 = 0xFFFF;

S8 lastCylinder = -1;
U8 camCount = 0;
U8 sync = 0;
U8 tooth = 0;

void knock_init()
{
	EICRB  |= 0x0F; // int on rising edge INT4 and INT5 for cam/crank signals
	EIMSK  |= _BV(INT4) | _BV(INT5); // enable interupts

	TCCR1A = 0; 		 // OCpins disconnected
	TCCR1B = 0b00000011; // clk/64 (4uS ticks), regular count
	TCCR1C = 0;
	TIMSK1 = 0; // no interrupts yet
	//OCR1B use for triggering next event

	knockMode = MODE_NONE;
	knockReadFlag = 0;
	settingsChangedFlag = 0;
	memset(times, 0, sizeof(times));
	memset(knockCount, 0, sizeof(times));
	memset(data.cylknkcount, 0, sizeof(data.cylknkcount));

	WINDOW_OFF();

	// Setup the TPIC8101
	SPISETUP();
	knock_write(CLK16); // set CLK=16MHz
	knock_write(CHN1);  // set channel 1
	knock_write(0x00 | config.filterIndex);
	knock_write(0x80 | config.gainIndex);
	knock_write(0xC0 | config.integratorIndex);
	knock_write(0b01110001); // set advanced mode
	// SPDR should equal 10001110 on next read
}

void knock_sensor_setting_changed()
{
	settingsChangedFlag = 1;
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
	U16 level, rpm, ticks;
	U8 ii;

	if (settingsChangedFlag)
	{
		stop_measurement(); // window can't be on

		knock_write(0x00 | config.filterIndex);
		knock_write(0x80 | config.gainIndex);
		knock_write(0xC0 | config.integratorIndex);

		knockReadFlag = 0;  // clear all our flags
		settingsChangedFlag = 0;
		return;
	}

	if (knockReadFlag)
	{
		if (sync && (lastCylinder >= 0))
		{
			ticks = times[4] - times[0]; // autowrap
			rpm = 15000000/ticks;

			knock_write(CLK16);
			level = knock_write(CHN1); // repsonse to CLK16 (see advanced mode)
			level = (knock_write(CHN1) << 2) | level; // response to first CHN1

			data.myrpm = SWAP16(rpm);
			data.cylnoise[lastCylinder] = SWAP16(level);

			for (ii = 1; ii < TABLESIZE; ii++)
			{
				if (rpm < SWAP16(config.krpm[ii]))  // use previous
				{
					if (level > SWAP16(config.kthreshold[ii]))
					{
						knockCount[lastCylinder]++;
						data.cylknkcount[lastCylinder] = SWAP16(knockCount[lastCylinder]);
						data.flags |= 0x01;
					}
					else
					{
						data.flags &= 0xFE;
					}
					break;
				}			
			}
		}

		knockReadFlag = 0;
	}
}


void start_degree_timer(U16 ticks)
{
	U32 tmp = TCNT1 + ticks;
	OCR1B = tmp;  // overflow works in our favor
	TIFR1  |= _BV(OCF1B); // clear any open OC1B interrupt
	TIMSK1 |= _BV(OCF1B); // enable interrupt for OC1B
}

void stop_measurement()
{
	TIMSK1 &= ~_BV(OCF1B); // clear interrupt for OC1B
	WINDOW_OFF();
	knockMode = MODE_NONE;
}


/* Knock timer */
ISR(TIMER1_COMPB_vect)
{
	if (knockMode == MODE_WAIT)
	{  // set timer for length of Window
		if (!settingsChangedFlag)  // not if we are updating settings
		{
			start_degree_timer(DEGREES_52);
			knockMode = MODE_MEASURE;
			WINDOW_ON();
		}
	}
	else if (knockMode == MODE_MEASURE)
	{
		stop_measurement();
		if (!settingsChangedFlag)
			knockReadFlag = 1;      // let main function know its time to read in measure
		switch (tooth)
		{
			case 1:  lastCylinder = 0;  // 1
			case 3:  lastCylinder = 2;  // 3
			case 5:  lastCylinder = 3;  // 4
			case 7:  lastCylinder = 1;  // 2
			default: lastCylinder = -1; // invalid
		}
	}
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
	tooth = (tooth + 1)%8; // inc our tooth count

	if (!sync)
	{
		if (camCount == 1)
		{
			sync = 1;
			tooth = 0;
		}
		else if (camCount == 2)
		{
			sync = 1;
			tooth = 4;
		}
		// else can't sync until we see one of the cam sides
	}
	else if ((camCount > 2) || ((camCount == 1) && (tooth != 0)) || ((camCount == 2) && (tooth != 4)))
	{
		// check if we lost sync
		sync = 0;
		ticksFor70 = 0;
		memset(times, 0xFF, 16);
	}

	camCount = 0; // reset

	if (sync)
	{
		U16 now = TCNT1;  // 4uS/tick
		times[tooth] = now;

		// start measurements on 1,3,5,7 (10BTDC) but only if we aren't updating settings
		if ((!settingsChangedFlag) && (tooth & 0x01))
		{
			ticksFor70 = now - times[tooth-1];  // auto wrap around 16bit counter
			start_degree_timer(DEGREES_20); // we are at 10BTDC when this is called, wait until 10ATDC
			knockMode = MODE_WAIT;
		}
	}
}




