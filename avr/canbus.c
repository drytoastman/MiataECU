

#define ERR_GEN_MSK ((1<<SERG)|(1<<CERG)|(1<<FERG)|(1<<AERG))            //! MaSK for GENeral ERRors INTerrupts
#define INT_GEN_MSK ((1<<BOFFIT)|(1<<BXOK)|(ERR_GEN_MSK))                //! MaSK for GENeral INTerrupts

#define HPMOB_MSK   ((1<<HPMOB3)|(1<<HPMOB2)|(1<<HPMOB1)|(1<<HPMOB0))    //! MaSK for MOb in HPMOB
#define MOBNB_MSK   ((1<<MOBNB3)|(1<<MOBNB2)|(1<<MOBNB1)|(1<<MOBNB0))    //! MaSK for MOb in CANPAGE

#define ERR_MOB_MSK ((1<<BERR)|(1<<SERR)|(1<<CERR)|(1<<FERR)|(1<<AERR))  //! MaSK for MOb ERRors
#define INT_MOB_MSK ((1<<TXOK)|(1<<RXOK)|(1<<BERR)|(1<<SERR)|(1<<CERR)|(1<<FERR)|(1<<AERR)) //! MaSK for MOb INTerrupts

#define CONMOB_MSK  ((1<<CONMOB1)|(1<<CONMOB0))                          //! MaSK for CONfiguration MOb
#define DLC_MSK     ((1<<DLC3)|(1<<DLC2)|(1<<DLC1)|(1<<DLC0))            //! MaSK for Data Length Coding
#define CONMOB      (CONMOB0)                                            //! CONfiguration MOb
#define DLC         (DLC0)                                               //! Data Length Coding

    // ----------
#define NB_MOB       15
#define NB_DATA_MAX  8
#define LAST_MOB_NB  (NB_MOB-1)
#define NO_MOB       0xFF
    // ----------
#define STATUS_CLEARED            0x00
    // ----------
#define MOB_NOT_COMPLETED         0x00                                              // 0x00
#define MOB_TX_COMPLETED        (1<<TXOK)                                           // 0x40
#define MOB_RX_COMPLETED        (1<<RXOK)                                           // 0x20
#define MOB_RX_COMPLETED_DLCW  ((1<<RXOK)|(1<<DLCW))                                // 0xA0
#define MOB_ACK_ERROR           (1<<AERR)                                           // 0x01
#define MOB_FORM_ERROR          (1<<FERR)                                           // 0x02
#define MOB_CRC_ERROR           (1<<CERR)                                           // 0x04
#define MOB_STUFF_ERROR         (1<<SERR)                                           // 0x08
#define MOB_BIT_ERROR           (1<<BERR)                                           // 0x10
#define MOB_PENDING            ((1<<RXOK)|(1<<TXOK))                                // 0x60
#define MOB_NOT_REACHED        ((1<<AERR)|(1<<FERR)|(1<<CERR)|(1<<SERR)|(1<<BERR))  // 0x1F
#define MOB_DISABLE               0xFF                                              // 0xFF
    // ----------
#define MOB_Tx_ENA  1
#define MOB_Rx_ENA  2
#define MOB_Rx_BENA 3
    // ----------

    // ----------

    // ----------
#define Can_set_mob(mob)       { CANPAGE = ((mob) << 4);}
#define Can_set_mask_mob()     {  CANIDM4=0xFF; CANIDM3=0xFF; CANIDM2=0xFF; CANIDM1=0xFF; }
#define Can_clear_mask_mob()   {  CANIDM4=0x00; CANIDM3=0x00; CANIDM2=0x00; CANIDM1=0x00; }
#define Can_clear_status_mob() { CANSTMOB=0x00; }

    // ----------
#define Can_mob_abort()   ( DISABLE_MOB )
    // ----------
#define Can_set_dlc(dlc)  ( CANCDMOB |= (dlc)        )
#define Can_set_ide()     ( CANCDMOB |= (1<<IDE)     )
#define Can_set_rtr()     ( CANIDT4  |= (1<<RTRTAG)  )
#define Can_set_rplv()    ( CANCDMOB |= (1<<RPLV)    )
    // ----------
#define Can_clear_dlc()   ( CANCDMOB &= ~DLC_MSK     )
#define Can_clear_ide()   ( CANCDMOB &= ~(1<<IDE)    )
#define Can_clear_rtr()   ( CANIDT4  &= ~(1<<RTRTAG) )
#define Can_clear_rplv()  ( CANCDMOB &= ~(1<<RPLV)   )
    // ----------
#define DISABLE_MOB       ( CANCDMOB &= (~CONMOB_MSK) )
#define Can_config_tx()        { DISABLE_MOB; CANCDMOB |= (MOB_Tx_ENA  << CONMOB); }
#define Can_config_rx()        { DISABLE_MOB; CANCDMOB |= (MOB_Rx_ENA  << CONMOB); }
#define Can_config_rx_buffer() {              CANCDMOB |= (MOB_Rx_BENA << CONMOB); }
    // ----------
#define Can_get_dlc()      ((CANCDMOB &  DLC_MSK)     >> DLC   )
#define Can_get_ide()      ((CANCDMOB &  (1<<IDE))    >> IDE   )
#define Can_get_rtr()      ((CANIDT4  &  (1<<RTRTAG)) >> RTRTAG)
    // ----------
#define Can_set_rtrmsk()   ( CANIDM4 |= (1<<RTRMSK) )
#define Can_set_idemsk()   ( CANIDM4 |= (1<<IDEMSK) )
    // ----------
#define Can_clear_rtrmsk() ( CANIDM4 &= ~(1<<RTRMSK) )
#define Can_clear_idemsk() ( CANIDM4 &= ~(1<<IDEMSK) )
    // ----------
                //!< STD ID TAG Reading
#define Can_get_std_id(identifier)  { *((U8 *)(&(identifier))+1) =  CANIDT1>>5              ; \
                                      *((U8 *)(&(identifier))  ) = (CANIDT2>>5)+(CANIDT1<<3); }
    // ----------
                //!< EXT ID TAG Reading
#define Can_get_ext_id(identifier)  { *((U8 *)(&(identifier))+3) =  CANIDT1>>3              ; \
                                      *((U8 *)(&(identifier))+2) = (CANIDT2>>3)+(CANIDT1<<5); \
                                      *((U8 *)(&(identifier))+1) = (CANIDT3>>3)+(CANIDT2<<5); \
                                      *((U8 *)(&(identifier))  ) = (CANIDT4>>3)+(CANIDT3<<5); }
    // ----------
                //!< STD ID Construction
#define CAN_SET_STD_ID_10_4(identifier)  (((*((U8 *)(&(identifier))+1))<<5)+((* (U8 *)(&(identifier)))>>3))
#define CAN_SET_STD_ID_3_0( identifier)  (( * (U8 *)(&(identifier))   )<<5)
    // ----------
                //!< STD ID TAG writing
#define Can_set_std_id(identifier)  { CANIDT1   = CAN_SET_STD_ID_10_4(identifier); \
                                      CANIDT2   = CAN_SET_STD_ID_3_0( identifier); \
                                      CANCDMOB &= (~(1<<IDE))                    ; }
    // ----------
                //!< STD ID MASK writing
#define Can_set_std_msk(mask)       { CANIDM1   = CAN_SET_STD_ID_10_4(mask); \
                                      CANIDM2   = CAN_SET_STD_ID_3_0( mask); }
    // ----------
                //!< EXT ID Construction
#define CAN_SET_EXT_ID_28_21(identifier)  (((*((U8 *)(&(identifier))+3))<<3)+((*((U8 *)(&(identifier))+2))>>5))
#define CAN_SET_EXT_ID_20_13(identifier)  (((*((U8 *)(&(identifier))+2))<<3)+((*((U8 *)(&(identifier))+1))>>5))
#define CAN_SET_EXT_ID_12_5( identifier)  (((*((U8 *)(&(identifier))+1))<<3)+((* (U8 *)(&(identifier))   )>>5))
#define CAN_SET_EXT_ID_4_0(  identifier)   ((* (U8 *)(&(identifier))   )<<3)
    // ----------
                //!< EXT ID TAG writing
#define Can_set_ext_id(identifier)  { CANIDT1   = CAN_SET_EXT_ID_28_21(identifier); \
                                      CANIDT2   = CAN_SET_EXT_ID_20_13(identifier); \
                                      CANIDT3   = CAN_SET_EXT_ID_12_5( identifier); \
                                      CANIDT4   = CAN_SET_EXT_ID_4_0(  identifier); \
                                      CANCDMOB |= (1<<IDE);                         }
    // ----------
                //!< EXT ID MASK writing
#define Can_set_ext_msk(mask)       { CANIDM1   = CAN_SET_EXT_ID_28_21(mask); \
                                      CANIDM2   = CAN_SET_EXT_ID_20_13(mask); \
                                      CANIDM3   = CAN_SET_EXT_ID_12_5( mask); \
                                      CANIDM4   = CAN_SET_EXT_ID_4_0(  mask); }
extern  void can_clear_all_mob(void);
extern  U8 can_get_mob_free(void);
extern  U8 can_get_mob_status(void);
extern  void can_get_data(U8* p_can_message_data);
extern U8 can_fixed_baudrate(U8 eval);

#define CAN_CMD_REFUSED  0xFF
#define CAN_CMD_ACCEPTED         0x00
#define CAN_STATUS_COMPLETED     0x00
#define CAN_STATUS_NOT_COMPLETED 0x01
#define CAN_STATUS_ERROR         0x02

typedef enum {
  CMD_NONE,
  CMD_TX_DATA,
  CMD_RX_DATA_MASKED,
} can_cmd_t;

typedef union{
  U16 std;
  U8  tab[2];
} can_id_t;

typedef union{
  U16 std;
  U8  tab[2];
} can_msk_t;

typedef  struct{
  U8         handle;
  can_cmd_t  cmd;
  can_id_t   id;
  can_msk_t  msk;           //- Added element versus "can_lib.h"
  U8         dlc;
  U8*        pt_data;
  U8         status;
} st_cmd_t;


extern U8 can_init(U8 mode);
extern U8 can_cmd (st_cmd_t *);
extern U8 can_get_status (st_cmd_t *);




/*
	CANGCON - CAN General Control
	CANGSTA - CAN General Status Register
    CANGIT - CAN General Interrupt Flags
    CANGIE - CAN General Interrupt Enable

	CANEN1
	CANEN2 - status of mob (ready or not)

	CANIE1
	CANIE2 - interrupt enable for mob

    CANSIT1
	CANSIT2 - interrupt status for mob (flag)

	CANBT1
	CANBT2
	CANBT3
	CANTCON - timing setup

	CANTIML
	CANTIMH 
	CANTTCL
	CANTTCH - can timer, ignored

	CANTEC
	CANREC - error counters

	CANHPMOB - mob prority

	CANPAGE - Mob pointer setup
*/

/*
	Per Mob

	CANSTMOB - status
	CANCDMOB - control
	CANIDT(1-4) - ID 
	CANIDM(1-4) - mask
	CANSTM(L,H) - timestamp
	CANMSG - data byte
*/



#define CAN_Reset()   CANGCON  =  _BV(SWRES) 
#define CAN_Enable()  CANGCON |=  _BV(ENASTB)
#define CAN_Disable() CANGCON &= ~_BV(ENASTB)
#define CAN_Abort()   CANGCON |=  (1<<ABRQ); CANGCON &= ~(1<<ABRQ);
#define ClearMob() { U8  volatile *__i_; for (__i_=&CANSTMOB; __i_<&CANSTML; __i_++) { *__i_=0x00 ;}}

void can_init()
{

	CAN_Reset();
	CANBT1 = 0x06; 
	CANBT2 = 0x04; 
	CANBT3 = 0x13;

	for (ii = 0; ii < 15; ii++)
	{
		CANPAGE = ii << 4;
		ClearMob();
	}

	CANGIE = 0b10111110;   // interupts for general, rx, tx, MOb error, frame buffer, general error
	CANIE1 = MOb interrupt;

	// 0 to 6 set aside for receive
	for (ii = 0; ii < 7; ii++)
	{
		CANPAGE = ii << 4;

		CANIDT1 = ;
		CANIDT2 = ;
		CANIDT3 = ;
		CANIDT4 = ;
		CANIDM1 = ;
		CANIDM2 = ;
		CANIDM3 = ;
		CANIDM4 = ;
		CANCDMOB = ;
	}

	// 7 to 14 set aside for transmit
	for (ii = 7; ii < 14; ii++)
	{
		CANPAGE = ii << 4;

		CANIDT1 = ;
		CANIDT2 = ;
		CANIDT3 = ;
		CANIDT4 = ;
		CANIDM1 = ;
		CANIDM2 = ;
		CANIDM3 = ;
		CANIDM4 = ;
		CANCDMOB = ;

	}


	CAN_Enable();
}





U8 can_get_mob_status(void)
{
    U8 mob_status, canstmob_copy;

    // Test if MOb ENABLE or DISABLE
    if ((CANCDMOB & 0xC0) == 0x00) {return(MOB_DISABLE);}

    canstmob_copy = CANSTMOB; // Copy for test integrity

    // If MOb is ENABLE, test if MOb is COMPLETED
    // - MOb Status = 0x20 then MOB_RX_COMPLETED
    // - MOb Status = 0x40 then MOB_TX_COMPLETED
    // - MOb Status = 0xA0 then MOB_RX_COMPLETED_DLCW
    mob_status = canstmob_copy & ((1<<DLCW)|(1<<TXOK)|(1<<RXOK));
    if ( (mob_status==MOB_RX_COMPLETED) ||   \
         (mob_status==MOB_TX_COMPLETED) ||   \
         (mob_status==MOB_RX_COMPLETED_DLCW) ) { return(mob_status); }

    // If MOb is ENABLE & NOT_COMPLETED, test if MOb is in ERROR
    // - MOb Status bit_0 = MOB_ACK_ERROR
    // - MOb Status bit_1 = MOB_FORM_ERROR
    // - MOb Status bit_2 = MOB_CRC_ERROR
    // - MOb Status bit_3 = MOB_STUFF_ERROR
    // - MOb Status bit_4 = MOB_BIT_ERROR
    mob_status = canstmob_copy & ERR_MOB_MSK;
    if (mob_status != 0) { return(mob_status); }

    // If CANSTMOB = 0 then MOB_NOT_COMPLETED
    return(MOB_NOT_COMPLETED);
}


U8 can_cmd(st_cmd_t* cmd)
{
	U8  cpt;
	U8  rtn_val;

    rtn_val = CAN_CMD_ACCEPTED;
    cmd->status = MOB_PENDING;

    //------------ special for "reduced_can_lib.c"
    if ((cmd->cmd) == CMD_TX_DATA)
    {
        cmd->handle = MOB_14;
        Can_set_mob(MOB_14);
        Can_clear_mob();
        Can_clear_ide();
        Can_set_std_id(cmd->id.std);
        for (cpt=0; cpt<cmd->dlc; cpt++) CANMSG = *(cmd->pt_data + cpt);
        Can_clear_rtr();
        Can_set_dlc(cmd->dlc);
        Can_config_tx();
    }
    //------------ special for "reduced_can_lib.c"
    else if ((cmd->cmd) == CMD_RX_DATA_MASKED)
    {
        cmd->handle = MOB_0;
        Can_set_mob(MOB_0);
        Can_clear_mob();
        Can_clear_ide();
        Can_set_std_id(cmd->id.std);
        Can_set_std_msk(cmd->msk.std);
        Can_set_rtrmsk(); Can_clear_rtr();
        Can_set_idemsk();
        Can_config_rx();
    }
    // case CMD_NONE or not implemented command
    else rtn_val= CAN_CMD_REFUSED;

    return rtn_val;
}

U8 can_get_status (st_cmd_t* cmd)
{
	U8 a_status;
	U8 rtn_val;

    a_status = cmd->status;
    if ( (a_status==STATUS_CLEARED)||(a_status==MOB_NOT_REACHED)||(a_status==MOB_DISABLE) )
    {
        return CAN_STATUS_ERROR;
    }

    Can_set_mob(cmd->handle);
    a_status = can_get_mob_status();

    switch (a_status)
    {
        case MOB_NOT_COMPLETED:
            // cmd->status not updated
            rtn_val = CAN_STATUS_NOT_COMPLETED;
            break;
        //--------------- special for "reduced_can_lib.c"
        case MOB_RX_COMPLETED:
        case MOB_RX_COMPLETED_DLCW:
            cmd->dlc = Can_get_dlc();
            can_get_data(cmd->pt_data);
            // Always standard frame
            Can_get_std_id(cmd->id.std);    //- Warning[Pa082]: undefined behavior: the order of volatile accesses is undefined in this statement
            // Status field of descriptor: 0x20 if Rx completed
            // Status field of descriptor: 0xA0 if Rx completed with DLCWarning
            cmd->status = a_status;
            Can_mob_abort();        // Freed the MOB
            Can_clear_status_mob(); //   and reset MOb status
            rtn_val = CAN_STATUS_COMPLETED;
            break;
        //--------------- special for "reduced_can_lib.c"
        case MOB_TX_COMPLETED:
            // Status field of descriptor: 0x40 if Tx completed
            cmd->status = a_status;
            Can_mob_abort();        // Freed the MOB
            Can_clear_status_mob(); //   and reset MOb status
            rtn_val = CAN_STATUS_COMPLETED;
            break;
        //---------------
        default:
            // Status field of descriptor: (bin)000b.scfa if MOb error
            cmd->status = a_status;
            Can_mob_abort();        // Freed the MOB
            Can_clear_status_mob(); //   and reset MOb status
            rtn_val = CAN_STATUS_ERROR;
            break;
    }

    return (rtn_val);
}

