/**
 * \file SpiSync_Type.h
 *
 * \brief This file contains related data types of Cps.
 *
 * \version refer the SpiSync_Type.h.
 *
 */

#ifndef _SPISYNC_TYPE_H_
#define _SPISYNC_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common_Type.h"
#include "CSC_Platform_Common.h"


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_SpiSync_TimeSyncState_t,
 * */
typedef enum
{
	SpiSync_TimeSync_State_None 	        = 0x00,
    SpiSync_TimeSync_State_Init             = 0x01,
    SpiSync_TimeSync_State_UpdatedOffset    = 0x02, ///<brief Wait the External offset,before spi time sync.
    SpiSync_TimeSync_State_Sync             = 0x03,
    SpiSync_TimeSync_State_Sync_Success     = 0x04,
    SpiSync_TimeSync_State_Sync_Failed      = 0x05,
	SpiSync_TimeSync_State_Max 	            = 0xFF
}e_SpiSync_TimeSyncState_t;

typedef struct
{
    uint32 TimeSyncCycle;   /*unit is ms*/
}s_SpiSync_TimeSyncConfig_t;

typedef struct
{
    e_SpiSync_TimeSyncState_t State;
    uint32 TimeSyncCycleCounter;
    uint32 TimeSyncWaitStartUpCounter;
    uint32 TimeSyncWaitOffsetCounter;
    uint64 TimestampOffset; ///< unit is ns
}s_SpiSync_TimeSyncStatus_t;

typedef union 
{
   uint8 raw[8];
   sint64 data; 
}u_SpiSync_TimeStamp_t;

typedef struct 
{
    u_SpiSync_TimeStamp_t TimeStamp;
    uint8 CheckSum;
    uint8 CycleCounter;
    uint8 Reserve[2];
}s_SipSync_TimeSyncMessage_t;



#endif /* _SPISYNC_TYPE_H_ */