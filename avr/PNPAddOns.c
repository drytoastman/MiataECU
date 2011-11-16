/*
 * PNPAddOns.c
 *
 * Created: 11/12/2011 3:32:50 PM
 *  Author: bwilson
 */ 

#include "PNPAddOns.h"
DiskInfo disk;

int main(void)
{
	initInfo(&disk);
	scanMBR(&disk);
	scanFAT(&disk);
	//determineFileName(&disk);
	findNextFreeCluster(&disk);
	// write data into disk at clusterNumber
	// when full
		// save offset and buffer
		// disk.clusterOffset++;
	findNextFreeCluster(&disk);
		// write new cluster number into old location
}