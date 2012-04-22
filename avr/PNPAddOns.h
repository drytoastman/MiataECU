#ifndef _ADDONS_H_
#define _ADDONS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

//typedef unsigned char uint8;
//typedef unsigned short uint16;
//typedef unsigned int uint32;
typedef signed char S8;
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

typedef struct
{
	unsigned short krpm[16];
	unsigned short kthreshold[16];
	unsigned char  integratorIndex; // 0-31
	unsigned char  filterIndex;     // 0-63
	unsigned char  gainIndex;       // 0-63
} ConfigData;


typedef struct 
{
	unsigned short cylnoise[4];
	unsigned short cylknkcount[4];
	unsigned short vss;
	unsigned short myrpm;
	unsigned char  idle;
	unsigned char  freebyte;
	unsigned char  flags;
} IOData;


void idle_changed();
void vss_init();
void can_init();

void knock_init();
void knock_main();
U8   knock_write(U8 byte);
void knock_sensor_setting_changed();

void data_init();
void data_burn();
void data_changed(U8 offset, U8 length);
void config_changed(U8 offset, U8 length);
void data_main();

extern ConfigData config;
extern IOData data;
extern U8 signature[];
extern U8 titlebar[];

#define SWAP16(x) ((x << 8) | (x >> 8))


/*
#define WORD32(b, l) *((uint32*)&b[l])
#define WORD16(b, l) *((uint16*)&b[l])

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

typedef struct
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


void initInfo(DiskInfo *disk);
U8   scanMBR(DiskInfo *disk);
void scanFAT(DiskInfo *disk);
void determineFileName(DiskInfo *disk);
char findNextFreeCluster(DiskInfo *disk);

#define CEL_ON()       PORTF |= _BV(PF0);
#define CEL_OFF()      PORTF &= ~_BV(PF0);

*/

#endif
