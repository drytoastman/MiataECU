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

#define TABLESIZE 16

typedef struct
{
	unsigned short krpm[TABLESIZE];
	unsigned short kthreshold[TABLESIZE];
	unsigned char  integratorIndex; // 0-31
	unsigned char  filterIndex;     // 0-63
	unsigned char  gainIndex;       // 0-63
} ConfigData;


#define FLAG_KNOCK _BV(0)
#define FLAG_SYNC  _BV(1)

typedef struct 
{
	/* 8 16bit adc values as seen by msextra CAN */
	unsigned short cylnoise[4];
	unsigned char  cylknkcount[4];  // becomes two 16bit values they 'share' the counters
	unsigned short vss;
	unsigned short myrpm;
	/* three bytes as seen by msextra CAN, (output, input, input) */
	unsigned char  idle;
	unsigned char  lostcount;
	unsigned char  flags;  // 1: sync, 0: knock

} IOData;


void idle_changed();
void vss_init();

void can_init();
void can_main();

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

#define CEL_ON()       PORTF |= _BV(PF0);
#define CEL_OFF()      PORTF &= ~_BV(PF0);

#endif
