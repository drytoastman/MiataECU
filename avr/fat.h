#ifndef __FAT_DEFS_H__
#define __FAT_DEFS_H__

#include <avr/io.h>
//#include "fat_types.h"

#define FATFS_IS_LITTLE_ENDIAN			0
#define FATFS_MAX_LONG_FILENAME			260
#define FATFS_MAX_OPEN_FILES			1
#define FAT_BUFFER_SECTORS				1
#define FAT_BUFFERS						1
//#define FAT_CLUSTER_CACHE_ENTRIES		128
#define FATFS_INC_WRITE_SUPPORT			1
#define FATFS_INC_LFN_SUPPORT			0	
#define FATFS_DIR_LIST_SUPPORT			1
#define FATFS_INC_FORMAT_SUPPORT		0

// Sector size used
#define FAT_SECTOR_SIZE					512

//-----------------------------------------------------------------------------
//			FAT32 Offsets
//		Name				Offset
//-----------------------------------------------------------------------------

// Boot Sector
#define BS_JMPBOOT				0	// Length = 3
#define BS_OEMNAME				3	// Length = 8
#define BPB_BYTSPERSEC			11	// Length = 2
#define BPB_SECPERCLUS			13	// Length = 1
#define BPB_RSVDSECCNT			14	// Length = 2
#define BPB_NUMFATS				16	// Length = 1
#define BPB_ROOTENTCNT			17	// Length = 2
#define BPB_TOTSEC16			19	// Length = 2
#define BPB_MEDIA				21	// Length = 1
#define	BPB_FATSZ16				22	// Length = 2
#define BPB_SECPERTRK			24	// Length = 2
#define BPB_NUMHEADS			26	// Length = 2
#define BPB_HIDDSEC				28	// Length = 4
#define BPB_TOTSEC32			32	// Length = 4

// FAT 12/16
#define BS_FAT_DRVNUM			36	// Length = 1
#define BS_FAT_BOOTSIG			38	// Length = 1
#define BS_FAT_VOLID			39	// Length = 4
#define BS_FAT_VOLLAB			43	// Length = 11
#define BS_FAT_FILSYSTYPE		54	// Length = 8

// FAT 32
#define BPB_FAT32_FATSZ32		36	// Length = 4
#define BPB_FAT32_EXTFLAGS		40	// Length = 2
#define BPB_FAT32_FSVER			42	// Length = 2
#define BPB_FAT32_ROOTCLUS		44	// Length = 4
#define BPB_FAT32_FSINFO		48	// Length = 2
#define BPB_FAT32_BKBOOTSEC		50	// Length = 2
#define BS_FAT32_DRVNUM			64	// Length = 1
#define BS_FAT32_BOOTSIG		66	// Length = 1
#define BS_FAT32_VOLID			67	// Length = 4
#define BS_FAT32_VOLLAB			71	// Length = 11
#define BS_FAT32_FILSYSTYPE		82	// Length = 8

//-----------------------------------------------------------------------------
// FAT Types
//-----------------------------------------------------------------------------
#define	FAT_TYPE_FAT12			1
#define	FAT_TYPE_FAT16			2
#define	FAT_TYPE_FAT32			3

//-----------------------------------------------------------------------------
// FAT32 Specific Statics
//-----------------------------------------------------------------------------
#define SIGNATURE_POSITION						 510
#define SIGNATURE_VALUE							 0xAA55
#define PARTITION1_TYPECODE_LOCATION	 		 450
#define FAT32_TYPECODE1						 	 0x0B
#define FAT32_TYPECODE2						 	 0x0C
#define PARTITION1_LBA_BEGIN_LOCATION	 		 454
#define PARTITION1_SIZE_LOCATION	 			 458

#define FAT_DIR_ENTRY_SIZE						 32
#define FAT_SFN_SIZE_FULL						 11			
#define FAT_SFN_SIZE_PARTIAL					 8

//-----------------------------------------------------------------------------
// FAT32 File Attributes and Types
//-----------------------------------------------------------------------------
#define FILE_ATTR_READ_ONLY   	0x01
#define FILE_ATTR_HIDDEN 		0x02
#define FILE_ATTR_SYSTEM 		0x04
#define FILE_ATTR_SYSHID		0x06
#define FILE_ATTR_VOLUME_ID 	0x08
#define FILE_ATTR_DIRECTORY		0x10
#define FILE_ATTR_ARCHIVE  		0x20
#define FILE_ATTR_LFN_TEXT		0x0F
#define FILE_HEADER_BLANK		0x00
#define FILE_HEADER_DELETED		0xE5
#define FILE_TYPE_DIR			0x10
#define FILE_TYPE_FILE			0x20

//-----------------------------------------------------------------------------
// Other Defines
//-----------------------------------------------------------------------------
#define FAT32_LAST_CLUSTER		0xFFFFFFFF
#define FAT32_INVALID_CLUSTER	0xFFFFFFFF

#define FAT_INIT_OK							0
#define FAT_INIT_MEDIA_ACCESS_ERROR			(-1)
#define FAT_INIT_INVALID_SECTOR_SIZE		(-2)
#define FAT_INIT_INVALID_SIGNATURE			(-3)
#define FAT_INIT_ENDIAN_ERROR				(-4)
#define FAT_INIT_WRONG_FILESYS_TYPE			(-5)
#define FAT_INIT_WRONG_PARTITION_TYPE		(-6)
#define FAT_INIT_STRUCT_PACKING				(-7)

#define FAT_DIR_ENTRIES_PER_SECTOR			(FAT_SECTOR_SIZE / FAT_DIR_ENTRY_SIZE)

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

#define GET_32BIT_WORD(buffer, location)	( ((uint32)buffer[location+3]<<24) + ((uint32)buffer[location+2]<<16) + ((uint32)buffer[location+1]<<8) + (uint32)buffer[location+0] )
#define GET_16BIT_WORD(buffer, location)	( ((uint16)buffer[location+1]<<8) + (uint16)buffer[location+0] )

/*
#define FAT32_GET_32BIT_WORD(pbuf, location)	( GET_32BIT_WORD(pbuf->ptr, location) )
#define FAT32_SET_32BIT_WORD(pbuf, location, value)	{ SET_32BIT_WORD(pbuf->ptr, location, value); pbuf->dirty = 1; }
#define FAT16_GET_16BIT_WORD(pbuf, location)	( GET_16BIT_WORD(pbuf->ptr, location) )
#define FAT16_SET_16BIT_WORD(pbuf, location, value)	{ SET_16BIT_WORD(pbuf->ptr, location, value); pbuf->dirty = 1; }
*/

typedef enum eFatType
{
	FAT_TYPE_16,
	FAT_TYPE_32
} tFatType;

typedef int (*fn_diskio_read_sector) (uint32 sector, uint8 *buffer);
typedef int (*fn_diskio_write_sector)(uint32 sector, uint8 *buffer);

typedef struct disk_if
{
	// User supplied function pointers for disk IO
	fn_diskio_read_sector		read_media;
	fn_diskio_write_sector		write_media;
} disk_if;

typedef struct fat_dir_entry
{
	uint8 Name[11];
	uint8 Attr;
	uint8 NTRes;
	uint8 CrtTimeTenth;
	uint8 CrtTime[2];
	uint8 CrtDate[2];
	uint8 LstAccDate[2];
	uint16 FstClusHI;
	uint8 WrtTime[2];
	uint8 WrtDate[2];
	uint16 FstClusLO;
	uint32 FileSize;
} fat_dir_entry;


typedef struct fatfs
{
	// Filesystem globals
	uint8		sectors_per_cluster;
	uint32		cluster_begin_lba;
	uint32		rootdir_first_cluster;
	uint32		rootdir_first_sector;
	uint32		rootdir_sectors;
	uint32		fat_begin_lba;
	uint16		fs_info_sector;
	uint32		lba_begin;
	uint32		fat_sectors;
	uint32		next_free_cluster;
	uint16		root_entry_count;
	uint16		reserved_sectors;
	uint8		num_of_fats;
	tFatType	fat_type;

	// Disk/Media API
	struct disk_if			disk_io;

	// [Optional] Thread Safety
	//void					(*fl_lock)(void);
	//void					(*fl_unlock)(void);

	// Working buffer
	//struct fat_buffer		currentsector;
	
	// FAT Buffer
	//struct fat_buffer		*fat_buffer_head;
	//struct fat_buffer		fat_buffers[FAT_BUFFERS];
	uint8 buffer[512];
	uint32 bufferlba;
	
} fatfs;


uint32 fatfs_find_next_cluster(struct fatfs *fs, uint32 current_cluster);
struct fat_buffer *fatfs_fat_read_sector(struct fatfs *fs, uint32 sector);

#endif
