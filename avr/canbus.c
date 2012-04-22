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

#include "PNPAddOns.h"

#define MS_TYPE()   ((CANIDT2 >> 2) & 0x07)
#define MS_BLOCK()  (((CANIDT3 << 2) | (CANIDT4 >> 6)) & 0x0F)
//#define MS_OFFSET() (((CANIDT1 << 3) | (CANIDT2 >> 5)) & 0x07FF)
#define MS_OFFSET8() (((CANIDT1 << 3) | (CANIDT2 >> 5)) & 0x0FF)
#define MS_TO()      ((CANIDT3 >> 2) & 0x0F)
#define MS_FROM()   (((CANIDT2 << 2) | (CANIDT3 >> 6)) & 0x0F)

#define MSG_CMD  0
#define MSG_REQ  1
#define MSG_RSP  2
#define MSG_XSUB 3
#define MSG_BURN 4

#define CAN_RESET()   CANGCON  =  _BV(SWRES) 
#define CAN_ENABLE()  CANGCON |=  _BV(ENASTB)
#define CAN_SETPAGE(x) CANPAGE = ((x)<<4)
#define GENERALERROR ((1<<SERG)|(1<<CERG)|(1<<FERG)|(1<<AERG))

#define MYADDRESS 7

void can_set_receive();


/**
	Initialize the CAN driver and prepare some receive buffers
*/
void can_init()
{
	U8 ii;

	CAN_RESET();
	CANBT1 = 0x02;  // BRP=1 (clkio/2)  TQ=
	CANBT2 = 0x6C;  // SJW=4, PROP=7+1
	CANBT3 = 0x37;  // P2=3+1, P1=3+1, SMP=1
	CANTCON = 0; // don't make use of the CAN timer

	// 0 to 7 set aside for receive (CANEN2)
	CANIE2 = 0xFF; 
	for (ii = 0; ii <= 7; ii++)
	{
		CAN_SETPAGE(ii);
		can_set_receive();
	}

	// 8 to 14 set aside for transmit (CANEN1)
	CANIE1 = 0x7F;
	for (ii = 8; ii <= 14; ii++)
	{
		CAN_SETPAGE(ii);
		CANSTMOB = 0;
		CANCDMOB = 0;
	}

	CANGIE = 0b10111010;   // interupts for general, rx, tx, MOb error, general error
	CAN_ENABLE();
}


void can_set_receive()
{
	CANIDT1 = 0x00;
	CANIDT2 = 0x00;
	CANIDT3 = MYADDRESS << 2;
	CANIDT4 = 0x00;

	CANIDM1 = 0x00;
	CANIDM2 = 0x00;
	CANIDM3 = 0x3C; // only look at To field
	CANIDM4 = 0x00;

	CANSTMOB = 0x00;
	CANCDMOB = 0x90;   // set to receive with IDE=1, 0 DLC
}


/**
	Send a message back to the requestor.  CAN header is built from
	from, to, type, block, offset
	Data is retrieved from buffer[0:len]
*/
void can_send(U8 from, U8 to, U8 type, U8 block, U16 offset, U8 *buffer, U8 len)
{
	U8 ii;
	for (ii = 0; ii < 7; ii++)
	{
		// find open buffer (CANEN shows no activity)
		if (!(CANEN1 & (1<<ii)))
		{
			CAN_SETPAGE(ii+8);

			CANIDT1 = offset >> 3;
			CANIDT2 = (offset << 5) | (type << 2) | (from >> 2);
			CANIDT3 = (from << 6) | (to << 2) | (block >> 2);
			CANIDT4 = (block << 6);

			for (ii = 0; ii < len; ii++)
				CANMSG = buffer[ii];

			CANCDMOB = 0x50 | (len & 0x0F);  // set to transmit, IDE=1 and length
			return;
		}
	}
}


/* Process a data push from the MS */
void can_process_CMD()
{
	U8 ii, len, *ptr;
	U8 myblock = MS_BLOCK();
	U8 offset = MS_OFFSET8();
	len = CANCDMOB & 0x0F;

	switch (myblock)
	{
		case 1:
			ptr = (U8*)&config; 
			break;
		case 2: 
			ptr = (U8*)&data;
			break;
		default: 
			return;
	}

	for (ii = 0; ii < len; ii++)
	{
		ptr[offset+ii] = CANMSG;
	}

	switch (myblock)
	{
		case 1:
			config_changed(offset, len);
			break;
		case 2: 
			data_changed(offset, len);
			break;
	}
}


/* Process a request for us to send data back to the MS */
void can_process_REQ()
{
	/*
		These are the first three data bytes as written by the msextra code
        CAN_TB0_DSR0 = can[ix].cx_myvarblk[jx];
        CAN_TB0_DSR1 = (unsigned char)(can[ix].cx_myvaroff[jx] >> 3);
        CAN_TB0_DSR2 = (unsigned char)((can[ix].cx_myvaroff[jx] & 0x0007) << 5) | an[ix].cx_varbyt[jx];
	*/

	U8 requestsrc, dstblock, length, myblock, myoffset, tmp;
	U16 dstoffset;

	dstblock = CANMSG;
	dstoffset = CANMSG;
	tmp = CANMSG;

	dstoffset = (dstoffset << 3) | (tmp >> 5);
	length = tmp & 0x1F;

	myoffset = MS_OFFSET8(); // get my offset from CAN header
	requestsrc = MS_FROM();  // find out who to send data to
	myblock = MS_BLOCK();  // get page from CAN heaer

	// save our current CAN ptr and send data
	tmp = CANPAGE;
	switch (myblock)
	{
		case 0x0F:  // signature request
			can_send(MYADDRESS, requestsrc, MSG_RSP, dstblock, dstoffset, &signature[myoffset], length);
			break;
		case 0x0E:  // title bar output
			can_send(MYADDRESS, requestsrc, MSG_RSP, dstblock, dstoffset, &titlebar[myoffset], length);
			break;
		case 0x02:
			can_send(MYADDRESS, requestsrc, MSG_RSP, dstblock, dstoffset, &(((U8*)&data)[myoffset]), length);
			break;
		case 0x01:
			can_send(MYADDRESS, requestsrc, MSG_RSP, dstblock, dstoffset, &(((U8*)&config)[myoffset]), length);
			break;
	}
		
	CANPAGE = tmp;
}



ISR(CANIT_vect)
{
	U8 ii;

	if (CANGIT & GENERALERROR)
	{
		CANGIT = 0xFF; // just clear it
	}

	if (CANSIT2) // something was received
	{
		// Process any completed receivers ( or clear their errors )
		for (ii = 0; ii < 8; ii++) 
		{
			if (CANSIT2 & (1<<ii)) 
			{
				CAN_SETPAGE(ii);
				if (CANSTMOB & (_BV(DLCW) | _BV(RXOK)))  // catch DLC as well, we don't know ahead of time
				{
					switch(MS_TYPE())
					{
						case MSG_CMD: //sending us data
						case MSG_RSP:
							can_process_CMD();
							break;
						case MSG_REQ: // request for data
							can_process_REQ();
							break;
						case MSG_XSUB: // xsub
							break;
						case 4: // burn
							data_burn();
							break;
					}
				}
				// else some kind of error

				can_set_receive();
			}
		}
	}

	if (CANSIT1)
	{
		// Clear transmit complete (or error) from any noted flags
		for (ii = 0; ii < 7; ii++) 
		{
			if (CANSIT1 & (1<<ii)) 
			{
				CAN_SETPAGE(ii+8);
				CANSTMOB = 0;
				CANCDMOB = 0; 
			}
		}
	}
}

