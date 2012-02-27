
#include "PNPAddOns.h"

#define NONE 0
#define WAIT 1
#define MEASURE 2

uint8 knockMode;
uint16 milliDegreePerTick;  // range from about 300 to 3100

uint8 windowStart = 10;
uint8 windowLength = 50;

uint16 times[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
uint8 camCount = 0;
uint8 sync = 0;
uint8 tooth = 0;

void knock_init()
{
	knockMode = NONE;

	/* Knock Detection */
	EICRA  = 0b00111100; // int on rising edge INT1 and IN2
	EICRB  = 0;
	TCCR2A = 0; // timer off initially
}

#define DEGREE_DELAY_TICKS(x) ((x) * 1000 / milliDegreePerTick)

inline void startKnockTimer()
{
	TCNT2 = 0;
	OCR2A = DEGREE_DELAY_TICKS(10 + windowStart); // we are at 10BTDC when this is called, windowStart ATDC
	TCCR2A = 0b00000111; // normal mode, clk/1024,  that is 64uS per tick
	TIMSK2 = 0b00000010; // interrupt at OCR1A
	knockMode = WAIT;
}

inline void openWindow()
{
	PORTB |= PB4;
}

inline void closeWindow()
{
	PORTB &= ~PB4;
}

inline void scheduleKnockRead()
{
}

/**
	This will tell us when we are 10BTDC as well as determining the degrees per clock tick
	that the engine is currently turning.  Tooth sync is done by cam signal input.
*/
inline void toothLog()
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
		memset(times, 0, 8);
	}

	camCount = 0; // reset


	if (sync)
	{
		uint16 tmp = TCNT3;  // same timer used for logging, 64usec/tick
		if ((tooth == 0) && (tmp > times[0])) // happens often enough, don't bother on wrap around or other error
			milliDegreePerTick = 720000/(tmp - times[0]); // 720 of rotation, use millideg to increase integer resolution
		times[tooth] = tmp;

		if (tooth & 0x01) // 1, 3, 5, 7, means 10 BTDC
			startKnockTimer();
	}
}



ISR(TIMER2_COMP_vect)
{
	if (knockMode == WAIT)
	{  // set timer for length of Window
		TCNT2 = 0;
		OCR2A = DEGREE_DELAY_TICKS(windowLength);
		knockMode = MEASURE;
		openWindow();
	}
	else
	{
		TCCR2A = 0; // turn off timer
		closeWindow();
		scheduleKnockRead();
		knockMode = NONE;
	}
}


/* Crank Signal */
ISR(INT1_vect)
{
	toothLog();
}


/* CAM Signal */
ISR(INT2_vect)
{
	camCount++;
}


