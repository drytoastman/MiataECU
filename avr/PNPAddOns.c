/*
 * PNPAddOns.c
 *
 * Created: 11/12/2011 3:32:50 PM
 *  Author: bwilson
 */ 


#include "PNPAddOns.h"
//DiskInfo disk;


int main(void)
{
	/*
	initInfo(&disk);
	scanMBR(&disk);
	scanFAT(&disk);
	determineFileName(&disk);
	findNextFreeCluster(&disk);
	// write data into disk at clusterNumber
	// when full
		// save offset and buffer
		// disk.clusterOffset++;
	findNextFreeCluster(&disk);
		// write new cluster number into old location
	*/

	knock_init();
	vss_init();

	TCCR1A = 0; // no wave generation
	TCCR1B = 0b00001101; // clk/1024, WGM Mode 4 = CTC, rollover at OC1A but no pin changes
	TCCR1C = 0;
	TIMSK1 = 0b01001110; // interupts: ICP1, OC1A, OC1B, OC1C
	OCR1A = 62500; // overflow at 4.000 seconds
	OCR1B = 1250; // used by logging, initial 80ms


	/*
	clk/1024 = 6uS/tick
	OVF=4.194seconds
	62500=4.000 seconds
	65000=4.160 seconds

	625 = 40.000ms   (25 samples/second)
	1250 = 80.000ms  (12.5 samples/second)
	*/
}


/** */
ISR(CANIT_vect)
{
}

ISR(SPI_STC_vect)
{
}

ISR(TWI_vect)
{
}

