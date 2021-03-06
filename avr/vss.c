
#include "PNPAddOns.h"

U16 lastTime;

void vss_init()
{
	EICRB  |= 0x30; // int on rising edge INT6 for vss signal
	EIMSK  |= _BV(INT6); // enable interupt
	//PORTE  |= _BV(6); // pull up on

	lastTime = 0;
	data.vss = SWAP16(42);
}

ISR(INT6_vect)
{
	U16 tmp = TCNT3;
	signed int vss;

	vss = tmp - lastTime;
	if (vss < 0)
		vss = 0x00FFFF - vss;

	data.vss = SWAP16(vss);
	lastTime = tmp;
}

