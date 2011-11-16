#include <avr/io.h>
#include <string.h>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

#define FATCOUNT 2
#define DIRENTRY_SIZE 32
#define DIRENTRY_PERSECTOR 16
#define BYTESPERSECTOR 512
#define SIG55_LOCATION 510
#define SIGAA_LOCATION 511
#define PARTITION1_TYPECODE_LOCATION 450
#define PARTITION1_LBA_BEGIN_LOCATION 454

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
	
	uint32 fat1;  // lba for start of FAT1
	uint8  fatsize; // how many LBA in a fat
	uint32 fatEntries; // how many clusters in each FAT
	
	uint32 root;  // lba for start of root directory info (only scan one cluster for FAT32 for simplicity)
	uint16 rootCount; // number of entries in sequence
	uint8  sectorsPerCluster; // how big is a cluster?
	
	uint32 data;  // lba for start of data clusters
	
	uint8 nextTens;
	uint8 nextOnes;
	
	uint32 bufferlba; // lba of current buffer;
	uint8_t buffer[512];
	
	// store our log file info that we can write back later
	DirEntry fileInfo;
	uint32 fileLBA;
	uint16 fileoffset;
} DiskInfo;



//#define WORD32(b, l) (((uint32)b[l+3]<<24) + ((uint32)b[l+2]<<16) + ((uint32)b[l+1]<<8) + (uint32)b[l+0] )
//#define WORD16(b, l) (((uint16)b[l+1]<<8) + (uint16)b[l+0] )
#define WORD32(b, l) *((uint32*)&b[l])
#define WORD16(b, l) *((uint16*)&b[l])

void initInfo(DiskInfo *disk);
uint8 scanMBR(DiskInfo *disk);
void scanFAT(DiskInfo *disk);
void determineFileName(DiskInfo *disk);
