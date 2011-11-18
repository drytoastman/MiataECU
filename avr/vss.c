
#include "PNPAddOns.h"

uint8 speedValid;
uint16 speed;
uint16 lastTime;
uint16 speedFactor;

void vss_init()
{
	speedValid = 0;
	speed = 0;
	lastTime = 0;
	speedFactor = 1;
}

ISR(TIMER1_CAPT_vect)
{
	uint16 tmp = TCNT1;
	if (speedValid)  // don't bother with measure when we wrap or other
		speed = (tmp - lastTime) * speedFactor;
	lastTime = tmp;
	speedValid = 1;
}

ISR(TIMER1_COMPA_vect) // this is timer overflow
{
	speedValid = 0;
}
