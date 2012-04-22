
#include "PNPAddOns.h"

U16 lastTime;

void vss_init()
{
	EICRB  |= 0x30; // int on rising edge INT6 for vss signal
	EIMSK  |= _BV(INT6); // enable interupt

	// share Timer3 with logging piece

	lastTime = 0;
	data.vss = SWAP16(42);

}

ISR(INT6_vect)
{
	U16 tmp = TCNT3;
	U16 vss;
	if (tmp <= lastTime)  // don't bother with measure when we wrap (62500) or other
	{
		vss = (tmp - lastTime);
		data.vss = SWAP16(vss);
	}

	lastTime = tmp;
}

