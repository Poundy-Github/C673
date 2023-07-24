//
// Copyright 2020 Horizon Robotics.
//

#ifndef COMMON_PLATFORM_H_
#define COMMON_PLATFORM_H_

#include "os.h"
#include "spi.h"

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
/* Changed by Crazy, 20210219, No one use this ReadTable */
#if 0
typedef unsigned char boolean;     // TODO: adapt to customer
typedef signed char sint8;         // TODO: adapt to customer
typedef unsigned char uint8;       // TODO: adapt to customer
typedef signed short sint16;       // TODO: adapt to customer
typedef unsigned short uint16;     // TODO: adapt to customer
typedef signed long sint32;        // TODO: adapt to customer
typedef unsigned long uint32;      // TODO: adapt to customer
typedef unsigned long long uint64; // TODO: adapt to customer
typedef signed long long sint64;   // TODO: adapt to customer

#define FALSE 0u                   // TODO: adapt to customer
#define TRUE 1u                    // TODO: adapt to customer
#endif

#ifndef NULL_PTR
 #define NULL_PTR  ((void *)0)
#endif

#define SPITP_MASTER_ENTER() SuspendAllInterrupts() // TODO: adapt to customer
#define SPITP_MASTER_EXIT() ResumeAllInterrupts()   // TODO: adapt to customer

#define HB_MEMORY_ENTER() SuspendAllInterrupts() // TODO: adapt to customer
#define HB_MEMORY_EXIT() ResumeAllInterrupts()  // TODO: adapt to customer

#define SPITP_J3A_HWUNIT	SPI_QSPI3_INDEX
#define SPITP_J2_CHANNEL	SpiConf_SpiChannel_SpiChannel_J3
#define SPITP_J2_SEQUENCE	SpiConf_SpiSequence_SeqSPI3_J3
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/
#if 1
typedef enum {
    SpiIf_Status_ok,
    SpiIf_Status_busy,
    SpiIf_Status_unknown
} SpiIf_Status;
#else
#include "SpiIf.h"
#endif
/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern SpiIf_Status hb_SpiMaster_getStatus(void);
extern SpiIf_Status hb_SpiMaster_exchange(const void *src, void *dest,
                                          uint32 count);
extern void hb_masterPrepareNotify(void);
extern void hb_timerReset(uint32 *time);
extern boolean hb_timerCheck(uint32 time, uint32 expired);
extern void hb_Memory_Init(void);
extern void SpiTp_MasterInit(void);
extern void SpiTp_MasterDeInit(void);
extern void SpiTp_MasterMainFunction(void);
extern void SpiTp_masterFiniNotification(void);
extern void SpiTp_masterErrNotification(void);
extern void SpiTp_masterFrameExchange(void);
void SpiTp_vHwIntEnable(void);
void SpiTp_masterAck(void);
#endif // COMMON_PLATFORM_H
