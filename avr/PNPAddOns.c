/*
 * PNPAddOns.c
 */ 

#include "PNPAddOns.h"

int main(void)
{
	// Timer 3 used by VSS ( no more logging )
	// clk/1024 = 64uS/tick
	// 62500 = 4.000 seconds
	// 625   = 40.000ms  (25 samples/second)
	// 1250  = 80.000ms  (12.5 samples/second)

	TCCR3A = 0; // OCpins disconnected
	TCCR3B = 0b00001101; // clk/1024, WGM Mode 4 = CTC, rollover at OC3A
	TCCR3C = 0;
	OCR3A  = 62500; // overflow at 4.000 seconds, we are using CTC so it rolls over automatically

	// Timer 0 is used for Idle PWM
	// clk/64 => fPWM = 16MHz/(64*510) = 490Hz
	TCCR0A = 0b01100011; // Phase correct PWM, OC0A SetUP/ClearDOWN, Clk/64
	OCR0A = 0; // initial is 0V
	DDRB |= _BV(7); // OC0A/PB7 is output

	// Enable SPI bus
	SPCR = 0b01010000; // enabled as master, no interrtupt, 4MHz, to be reconfigured by different users
	DDRB |= _BV(0) | _BV(1) | _BV(2) | _BV(4) | _BV(5); // SS, MOSI, SCK, WINDOW, KNKCS are output

	// F0 is cell, make it output
	DDRF |= _BV(0);

	data_init();  // read config data before doing anything else
	knock_init();
	vss_init();
	can_init();
	sei();

	while (1) 
	{
		knock_main();
		data_main();
		can_main();
	}
}

void idle_changed()
{
	OCR0A = data.idle;
}



// make sure any other forgotten interrupts don't haunt us

EMPTY_INTERRUPT(_VECTOR(1))
EMPTY_INTERRUPT(_VECTOR(2))
EMPTY_INTERRUPT(_VECTOR(3))
EMPTY_INTERRUPT(_VECTOR(4))
// 5. extint 4, crank
// 6. extint 5, cam
// 7. extint 6, vss
EMPTY_INTERRUPT(_VECTOR(8))
EMPTY_INTERRUPT(_VECTOR(9))
EMPTY_INTERRUPT(_VECTOR(10))
EMPTY_INTERRUPT(_VECTOR(11))
EMPTY_INTERRUPT(_VECTOR(12))
// 13. timer1 compB, knock window
EMPTY_INTERRUPT(_VECTOR(14))
EMPTY_INTERRUPT(_VECTOR(15))
EMPTY_INTERRUPT(_VECTOR(16))
EMPTY_INTERRUPT(_VECTOR(17))
// 18. CAN, communications
EMPTY_INTERRUPT(_VECTOR(19))
EMPTY_INTERRUPT(_VECTOR(20))
EMPTY_INTERRUPT(_VECTOR(21))
EMPTY_INTERRUPT(_VECTOR(22))
EMPTY_INTERRUPT(_VECTOR(23))
EMPTY_INTERRUPT(_VECTOR(24))
EMPTY_INTERRUPT(_VECTOR(25))
EMPTY_INTERRUPT(_VECTOR(26))
EMPTY_INTERRUPT(_VECTOR(27))
EMPTY_INTERRUPT(_VECTOR(28))
EMPTY_INTERRUPT(_VECTOR(29))
EMPTY_INTERRUPT(_VECTOR(30))
EMPTY_INTERRUPT(_VECTOR(31))
EMPTY_INTERRUPT(_VECTOR(32))
EMPTY_INTERRUPT(_VECTOR(33))
EMPTY_INTERRUPT(_VECTOR(34))
EMPTY_INTERRUPT(_VECTOR(35))
EMPTY_INTERRUPT(_VECTOR(36))

