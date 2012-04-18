#ifndef _ADDONS_H_
#define _ADDONS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

typedef struct
{
	uint8 basename[6];
	uint8 tens;
	uint8 ones;
	uint8 ext[3];
	uint8 attribute;
	uint8 reserved;
	uint8 createFine;
	uint16 createTime;
	uint16 createDate;
	uint16 accessDate;
	uint16 clusterHi;
	uint16 modTime;
	uint16 modDate;
	uint16 clusterLo;
	uint32 fileSize;
} DirEntry;

typedef struct DiskInfo
{
	uint32 partition; // lba of partition
	
	uint8  isFat32; // true for FAT32, false for FAT16
	uint32 fat1;  // lba for start of FAT1
	uint32 fat2;  // lba for start of FAT2
	uint8  fatsize; // how many LBA in a fat
	uint32 fatEntries; // how many clusters in each FAT
	
	uint32 root;  // lba for start of root directory info (only scan one cluster for FAT32 for simplicity)
	uint16 rootCount; // number of entries in sequence
	uint8  sectorsPerCluster; // how big is a cluster?
	
	uint32 data;  // lba for start of data clusters
	
	uint8 nextTens;
	uint8 nextOnes;
	
	uint32 bufferlba; // lba of current buffer;
	uint8  *buffer;
	uint8  buffer1[512];
	uint8  buffer2[512];
	
	// store our 'open' log file info that we can write back later
	DirEntry fileInfo;
	uint32 fileLBA;
	uint16 fileoffset;
	
	// store info of which FAT entry we are currently using and the recorded 
	uint32 clusterLBA;
	uint16 clusterOffset;
	uint32 clusterNumber;
} DiskInfo;


#define WORD32(b, l) *((uint32*)&b[l])
#define WORD16(b, l) *((uint16*)&b[l])

#define KNOCKSIG  0  // remote analog data (as 16 bit locations)
#define RPM       4
#define VSS       5

#define BYTE_IDL   16  // byte locations for byte data
#define BYTE_FREE  17
#define BYTE_KNOCK 18

/*
#define LOGSWITCH PORTD & BV_(7)
#define CARDDETECT PORTD & BV_(4)
#define SDCS PORTB & BV_(0)
#define ACCELCS PORTB & BV_(6)
*/

#define WINDOW_ON()    PORTB |= PB4
#define WINDOW_OFF()   PORTB &= ~PB4;

#define KNK_SELECT()   PORTB |= PB5
#define KNK_DESELECT() PORTB &= ~PB5;

#define CEL_ON()       PORTF |= PF0;
#define CEL_OFF()      PORTF &= ~PF0;

#define KNK_DETECT()   candata[BYTE_KNOCK] |= 0x01
#define KNK_DONE()     candata[BYTE_KNOCK] &= 0xFE

extern U8 candata[];

void initInfo(DiskInfo *disk);
U8   scanMBR(DiskInfo *disk);
void scanFAT(DiskInfo *disk);
void determineFileName(DiskInfo *disk);
char findNextFreeCluster(DiskInfo *disk);

void vss_init();
void knock_init();
void knock_main();
void can_init();
void can_set_adc(U8 pos, U16 value);
U16 can_get_adc(U8 pos);
void can_byte_changed(U16 offset);
void can_data_sent(U16 offset, U8 length);

#endif
