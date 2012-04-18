
#include "PNPAddOns.h"

uint16 lastTime;
uint16 speedFactor;

void vss_init()
{
	EICRB  |= 0x30; // int on rising edge INT6 for vss signal
	EIMSK  |= _BV(INT6); // enable interupt

	// shared Timer3 with logging piece

	lastTime = 0;
	speedFactor = 1;
	can_set_adc(VSS, 0);
}

ISR(INT6_vect)
{
	uint16 tmp = TCNT3;
	if (tmp <= lastTime)  // don't bother with measure when we wrap or other
		can_set_adc(VSS, (tmp - lastTime) * speedFactor);
	lastTime = tmp;
}

