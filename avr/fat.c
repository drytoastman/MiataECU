
#include "PNPAddOns.h"

#include "test.c"

void read_sdcard(DiskInfo *disk, int lba)
{
	if (disk->bufferlba == lba)
		return;
	
	switch(lba)
	{
		case 0: memcpy(disk->buffer, block0, 512); break;
		case 8: memcpy(disk->buffer, block8, 512); break;
		case 9: memcpy(disk->buffer, block9, 512); break;
		case 504: memcpy(disk->buffer, block504, 512); break;
		case 505: memcpy(disk->buffer, block505, 512); break;
	}
		
	disk->bufferlba = lba;
}	

void flush_sdcard(DiskInfo *disk)
{
	// write buffer to bufferlba	
}

void initInfo(DiskInfo *disk)
{
	disk->partition = 0xFFFFFFFF;
	disk->nextTens = '0';
	disk->nextOnes = '1';
	disk->bufferlba = 0xFFFFFFFF;
}	

uint8 scanMBR(DiskInfo *disk)
{
	read_sdcard(disk, 0);
	
	if (disk->buffer[SIG55_LOCATION] != 0x55 || disk->buffer[SIGAA_LOCATION] != 0xAA) // partition signature
		return 1;

	// Check the partition type code
	disk->partition = 0xFFFFFFFF;
	switch (disk->buffer[PARTITION1_TYPECODE_LOCATION])
	{
		case 0x05:
		case 0x06: 
		case 0x0B: 
		case 0x0C: 
		case 0x0E: 
		case 0x0F: 
			disk->partition = WORD32(disk->buffer, PARTITION1_LBA_BEGIN_LOCATION);
			return 0;
	}	

	disk->partition = 0;
	return 0; // default assume MBR less disk with FAT at block 0
}

/**
Assumes we can read the entire root directory in one cluster/section, either reserved FAT16 or clusterized FAT32
*/
void scanFAT(DiskInfo *disk)
{
	// read partition volume id
	read_sdcard(disk, disk->partition);
	
	// parameters that we assume to be X	
	if (disk->buffer[0x0C] != 0x02)  // top byte of 512 
		return;
	if (disk->buffer[0x1FE] != 0x55 || disk->buffer[0x1FF] != 0xAA) // partition signature
		return;
	if (disk->buffer[0x10] != 2) // fatcount
		return;
		
	// readable parameters
	disk->sectorsPerCluster = disk->buffer[0x0D];
	uint16 reservedSectors = WORD16(disk->buffer, 0x0E);
	disk->rootCount = WORD16(disk->buffer, 0x11);
	disk->fatsize = WORD16(disk->buffer, 0x16);

	// calculatable parameters
	disk->fat1 = disk->partition + reservedSectors;  // where fat tables are
	disk->data = disk->fat1 + (disk->fatsize * 2); // where data clusters start
	
	if (disk->fatsize == 0) // special case for FAT32
	{
		disk->fatsize = WORD32(disk->buffer, 0x24);  // get real value for FAT32
		uint32 rootCluster = WORD32(disk->buffer, 0x2C); // get real value for FAT32
		disk->data = disk->fat1 + (disk->fatsize * FATCOUNT);
		disk->root = disk->data + (rootCluster-2)*disk->sectorsPerCluster;
		disk->rootCount = BYTESPERSECTOR * disk->sectorsPerCluster / DIRENTRY_SIZE;  // for simplicity, assume a single cluster, thats 128 files for 4K cluster size
		disk->fatEntries = disk->fatsize * BYTESPERSECTOR / 32;
	}
	else // finalize for FAT16 and skip the root dir
	{
		disk->root = disk->data;
		disk->data += (disk->rootCount * DIRENTRY_SIZE) / BYTESPERSECTOR;
		disk->fatEntries = (uint32)disk->fatsize * BYTESPERSECTOR / 16;
	}
}

void determineFileName(DiskInfo *disk)
{
	uint32 lba = disk->root;
	uint16 direntry = 0;
	uint16 freeentry = 0xFFFF;
	uint16 ptr = 512;
	DirEntry *file;
	
	disk->rootCount = 32;
	while (direntry < disk->rootCount)
	{
		if 	(ptr >= 512)   // sector boundary
		{
			// read lba into buffer
			read_sdcard(disk, lba);
			lba++;
			ptr = 0; //disk->buffer;
		}
		
		file = (DirEntry*)&(disk->buffer[ptr]);
		if (file->attribute & 0b11011110)
		{
			// attribute flags we avoid, Unused, Device, Subdirectory, Volume, System, Hidden
		}
		else if ((file->basename[0] == 0xE5) || (file->basename[0] == 0x00))
		{
			// open entry, make note for later if we don't have one yet
			if (freeentry == 0xFFFF)
				freeentry = direntry;			
		}
		else if (!memcmp(file->ext, "ms3", 3))
		{
			// low library use to find our next counter using two digits
			if (file->tens > disk->nextTens)
			{
				disk->nextTens = file->tens+1;
				disk->nextOnes = '0';
			}			
			
			if (file->ones > disk->nextOnes)
			{
				disk->nextOnes = file->ones+1;
				if (disk->nextOnes > '9')
				{
					disk->nextOnes = '0';
					disk->nextTens++;	
				}					
			}			
		}			
		
		ptr += DIRENTRY_SIZE;
		direntry++;
	}
	
	// determine where to put our file			
	lba = freeentry/DIRENTRY_PERSECTOR;  // block freeentry is in relative to root start, this is DIV, i.e. no remainder
	disk->fileoffset = freeentry - lba*DIRENTRY_PERSECTOR; // how much farther into this block, subtract the blocks we skipped over
	disk->fileLBA = disk->root + lba; // get the real LBA of the root
			
	file = (DirEntry*)&(disk->fileInfo);
	memcpy(file->basename, "logger", 6);
	file->tens = disk->nextTens;
	file->ones = disk->nextOnes;
	memcpy(file->ext, "mp3", 3);
	file->attribute = 0;
	file->createFine = 0;
	file->createTime = 0; // get time
	file->createDate = 0; // get date
	file->accessDate = file->createDate;
	file->modTime = file->createTime;
	file->modDate = file->createDate;
	
	file->clusterHi = 0;
	file->clusterLo = 0;
	file->fileSize = 0; 
}

void findNextFreeCluster(DiskInfo *disk)
{	
}

