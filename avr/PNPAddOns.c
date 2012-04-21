/*
 * PNPAddOns.c
 */ 

#include "PNPAddOns.h"

int main(void)
{
	// Timer 3 shared between logging and VSS 
	// clk/1024 = 64uS/tick
	// 62500 = 4.000 seconds
	// 625   = 40.000ms  (25 samples/second)
	// 1250  = 80.000ms  (12.5 samples/second)

	TCCR3A = 0; // OCpins disconnected
	TCCR3B = 0b00001101; // clk/1024, WGM Mode 4 = CTC, rollover at OC1A
	TCCR3C = 0;
	TIMSK3 = 0b00000110; // interupts: OC3A, OC3B
	OCR3A  = 62500; // overflow at 4.000 seconds, we are using CTC so it rolls over automatically
	OCR3B  = 1250; // used by logging, initial 80ms (1250*50 == 62500)

	// Timer 0 is used for Idle PWM
	// clk/64 => fPWM = 16MHz/(64*510) = 490Hz
	TCCR0A = 0b01100011; // Phase correct PWM, OC0A SetUP/ClearDOWN, Clk/64
	OCR0A = 255; // initial is 0V
	DDRB |= _BV(7); // OC0A/PB7 is output

	// Enable SPI bus
	SPCR = 0b01010000; // enabled as master, no interrtupt, 4MHz, to be reconfigured by different users
	DDRB |= _BV(0) | _BV(1) | _BV(2) | _BV(4) | _BV(5); // SS, MOSI, SCK, WINDOW, KNKCS are output

	can_set_adc(0, 720);
	can_set_adc(1, 360);
	can_set_adc(2, 48);
	can_set_adc(3, 49);

	knock_init();
	vss_init();
	can_init();

	sei();

	while (1) 
	{
		can_main();
		knock_main();
	}
}

/* notification that a byte has been sent to us */
void can_byte_changed(U16 offset)
{
	if (offset == BYTE_IDL)
		OCR0A = can_get_byte(BYTE_IDL);
}


EMPTY_INTERRUPT(TIMER3_COMPA_vect) // our counter overflow at 62500
EMPTY_INTERRUPT(TIMER3_COMPB_vect) // start logging

// make sure any other forgotten interrupts don't haunt us

EMPTY_INTERRUPT(_VECTOR(1))
EMPTY_INTERRUPT(_VECTOR(2))
EMPTY_INTERRUPT(_VECTOR(3))
EMPTY_INTERRUPT(_VECTOR(4))
EMPTY_INTERRUPT(_VECTOR(8))
EMPTY_INTERRUPT(_VECTOR(9))
EMPTY_INTERRUPT(_VECTOR(10))
EMPTY_INTERRUPT(_VECTOR(11))
EMPTY_INTERRUPT(_VECTOR(12))
EMPTY_INTERRUPT(_VECTOR(14))
EMPTY_INTERRUPT(_VECTOR(15))
EMPTY_INTERRUPT(_VECTOR(16))
EMPTY_INTERRUPT(_VECTOR(17))
EMPTY_INTERRUPT(_VECTOR(19))
EMPTY_INTERRUPT(_VECTOR(20))
EMPTY_INTERRUPT(_VECTOR(21))
EMPTY_INTERRUPT(_VECTOR(22))
EMPTY_INTERRUPT(_VECTOR(23))
EMPTY_INTERRUPT(_VECTOR(24))
EMPTY_INTERRUPT(_VECTOR(25))
EMPTY_INTERRUPT(_VECTOR(26))
EMPTY_INTERRUPT(_VECTOR(27))
EMPTY_INTERRUPT(_VECTOR(30))
EMPTY_INTERRUPT(_VECTOR(31))
EMPTY_INTERRUPT(_VECTOR(32))
EMPTY_INTERRUPT(_VECTOR(33))
EMPTY_INTERRUPT(_VECTOR(34))
EMPTY_INTERRUPT(_VECTOR(35))
EMPTY_INTERRUPT(_VECTOR(36))

