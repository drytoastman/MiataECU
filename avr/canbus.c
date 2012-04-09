
#include <avr/io.h>
#include <avr/interrupt.h>

typedef unsigned char U8;
typedef unsigned short U16;

/*
	CANGCON - CAN General Control   (set at boot time, leave after that)
	CANGSTA - CAN General Status Register (read-only) 
    CANGIT - CAN General Interrupt Flags   (clear in handler for general interrupt)
    CANGIE - CAN General Interrupt Enable  (set for desired interrupts)

	CANEN1
	CANEN2 - status of mob, ready or not (read-only)

	CANIE1
	CANIE2 - interrupt enable for mob  (set all)

    CANSIT1
	CANSIT2 - interrupt status for mob (read-only)

	CANTEC
	CANREC - error counters (read-only)

	CANHPMOB - mob prority (not used)
	CANPAGE - Mob pointer setup (pager for below)

	--- Per Mob ---

	CANSTMOB - status
	CANCDMOB - control
	CANIDT(1-4) - ID 
	CANIDM(1-4) - mask  (for receivers only)
	CANSTM(L,H) - timestamp (unused)
	CANMSG - data byte
*/

/*
MS Wire Format to CANID
VarOffset (11bits) - 28-18
MsgType (3bits)    - 17-15
FromID (4bits)     - 14-11
ToID (4bits)       - 10-07
VarBlk(4bits)      - 06-03
MS3VarBlk4(1bit)   - 02
Spare(2bits)       - 01-00

AVR Registers
CANIDT1(28:21) - VarOffset(11-3)
CANIDT2(20:13) - VarOffset(2-0), MsgType, FromID(3,2)
CANIDT3(12:05) - FromID(1,0), ToID, VarBlk(3,2)
CANIDT4(5:0,*) - VarBlk(1,0), MS3VarBlkBit, 5 to ignore
*/


#define MS_TYPE()   ((CANIDT2 >> 2) & 0x07)
#define MS_BLOCK()  (((CANIDT3 << 2) | (CANIDT4 >> 6)) & 0x0F)
#define MS_OFFSET() (((CANIDT1 << 3) | (CANIDT2 >> 5)) & 0x07FF)
#define MS_TO()      ((CANIDT3 >> 2) & 0x0F)
#define MS_FROM()   (((CANIDT2 << 2) | (CANIDT3 >> 6)) & 0x0F)

#define CAN_Reset()   CANGCON  =  _BV(SWRES) 
#define CAN_Enable()  CANGCON |=  _BV(ENASTB)
#define CAN_Disable() CANGCON &= ~_BV(ENASTB)
#define CAN_Abort()   CANGCON |=  (1<<ABRQ); CANGCON &= ~(1<<ABRQ);

#define MYADDRESS 7


U8 mybuffer[20];


inline void ms_set_receive()
{
	CANIDT1 = 0x00;
	CANIDT2 = 0x00;
	CANIDT3 = MYADDRESS << 2;
	CANIDT4 = 0x00;

	CANIDM1 = 0x00;
	CANIDM2 = 0x00;
	CANIDM3 = 0x3C; // only look at To field
	CANIDM4 = 0x00;

	CANCDMOB = 0x90;   // set to receive with IDE=1, 0 DLC
}


inline void ms_send(U8 from, U8 to, U8 type, U8 block, U16 offset, U8 *buffer, U8 len)
{
	U8 ii;
	for (ii = 0; ii < 7; ii++)
	{
		// find open buffer (CANEN shows no activity)
		if (!(CANEN1 & (1<<ii)))
		{
			CANPAGE = (ii+8) << 4;

			CANIDT1 = offset >> 3;
			CANIDT2 = (offset << 5) | (type << 2) | (from >> 2);
			CANIDT3 = (from << 6) | (to << 2) | (block >> 2);
			CANIDT4 = (block << 6);

			for (ii = 0; ii < len; ii++)
				CANMSG = buffer[offset+ii];

			CANCDMOB = 0x50 | (len & 0x0F);  // set to transmit, IDE=1 and length
			return;
		}
	}
}


void can_init()
{
	U8 ii;

	CAN_Reset();
	CANBT1 = 0x06; // bit timing for 500kbps, 16MHz clkio, TQ=8
	CANBT2 = 0x04; 
	CANBT3 = 0x13;
	CANTCON = 0; // ???

	for (ii = 0; ii < 15; ii++)
	{
		CANPAGE = (ii << 4);
		CANSTMOB = 0;
		CANCDMOB = 0;
	}

	CANGIE = 0b10111010;   // interupts for general, rx, tx, MOb error, general error

	// 0 to 7 set aside for receive (CANEN2)
	CANIE2 = 0xFF; 
	for (ii = 0; ii <= 7; ii++)
	{
		CANPAGE = (ii << 4);
		ms_set_receive();
	}

	// 8 to 14 set aside for transmit (CANEN1)
	CANIE1 = 0x7F;

	CAN_Enable();
}



/* Process a data push from the MS */
inline void processData()
{
	U8 ii, len;
	U16 offset = MS_OFFSET();
	len = CANCDMOB & 0x0F;

	for (ii = 0; ii < len; ii++, offset++)
	{
		mybuffer[offset] = CANMSG;
	}
}

/* Process a request for us to send data back to the MS */
inline void processRequest()
{
	/*
		These are the first three data bytes as written by the msextra code
        CAN_TB0_DSR0 = can[ix].cx_myvarblk[jx];
        CAN_TB0_DSR1 = (unsigned char)(can[ix].cx_myvaroff[jx] >> 3);
        CAN_TB0_DSR2 = (unsigned char)((can[ix].cx_myvaroff[jx] & 0x0007) << 5) | an[ix].cx_varbyt[jx];
	*/

	U8 myblock, dstblock, length, tmp;
	U16 myoffset, dstoffset;

	dstblock = CANMSG;
	dstoffset = CANMSG;
	tmp = CANMSG;

	dstoffset = (dstoffset << 3) | (tmp >> 5);
	length = tmp & 0x1F;

	myoffset = MS_OFFSET(); // get my offset from CAN header
	myblock = MS_BLOCK();  // get my block from CAN heaer

	// find open transmit
	tmp = CANPAGE;
	ms_send(MYADDRESS, MS_FROM(), 2, dstblock, dstoffset, mybuffer, length);  // type 2 == MSG_RSP
	CANPAGE = tmp;
}


#define GENERALERROR ((1<<SERG)|(1<<CERG)|(1<<FERG)|(1<<AERG))

ISR(CANIT_vect)
{
	U8 ii;

	if (CANGIT & GENERALERROR)
	{
		CANGIT = 0x7F; // just clear it
	}

	else if (CANSIT2) // something was received
	{
		// Find the first interrupted receiver
		for (ii = 0; ii < 8; ii++) {
			if (CANSIT2 & (1<<ii)) {
				CANPAGE = (ii << 4);
				break;
		}}

		if (CANSTMOB & (DLCW | RXOK))  // catch DLC as well, we don't know ahead of time
		{
			switch(MS_TYPE())
			{
				case 0: //sending us data
					processData();
					break;
				case 1: // request for data
					processRequest();
					break;
			}
		}
		// else some kind of error

		CANSTMOB = 0;
		CANCDMOB = 0; 
	}

	else if (CANSIT1)
	{
		// Find the first interrupted transmitter and silence them
		for (ii = 0; ii < 7; ii++) {
			if (CANSIT1 & (1<<ii)) {
				CANPAGE = ((ii+8)<<4);
				break;
		}}

		CANSTMOB = 0;
		CANCDMOB = 0; 
	}
}

