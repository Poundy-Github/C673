#ifndef __FS_CHECK_H__
#define __FS_CHECK_H__

/*==================[inclusions]============================================*/
#include "Std_Types.h"
#include "function_safety.h"
#include "esm/fs_adc.h"
#include "exec/fs_exec.h"
#include "exec/fs_catx.h"
#include "exec/fs_soc.h"
#include "fs_pdo.h"
#include "fs_common.h"

/*==================[macros definitions]====================================*/

#ifndef NULL
#define NULL ((void *)0)
#endif

#define FSCHECK_MAINFUNCTION_PERIOD              (5) // 5ms
#define FS_SOC_DIAG_GROUPID_CAMERA               (3)
#define FS_BITPOS_CAMERA_TEMP_ERROR              (5) /*bit  5*/
#define FS_SOC_DIAG_GROUPID_SYSSERVICE           (1)
#define FS_BITPOS_CPU_TEMP_LEVEL                 (15) /*bit  15*/
#define FS_SOC_DIAG_GROUPID_SAFETYLIB            (4)
#define FS_BITPOS_SOC_TEMP_CHECK                 (9) /*bit  9*/


#define Fs_GetBit(source, bitmask)   ( ((source) & (bitmask)) == (bitmask) )   // Get the corresponding Bit on the basis of the BITMASK

#define Fs_GetBitMask(bitpos)        ((uint16)1u << (((uint16)bitpos) % 16u))  // Get the bit mask base on 16bit wide

#define FS_IPC_SERVER_COMM_NORMAL		1
#define FS_IPC_SERVER_COMM_ABNORMAL		0
#define FS_IPC_SERVER_COUNT_TIMENR_MAX	65530


#define FS_ADC_MONITOR_STATUS_INVALID    (0U)
#define FS_ADC_MONITOR_STATUS_LOW        (1U)
#define FS_ADC_MONITOR_STATUS_NORMAL     (2U)
#define FS_ADC_MONITOR_STATUS_HIGH1      (3U)
#define FS_ADC_MONITOR_STATUS_HIGH2      (4U)

#define FS_CHECK_NUM                     (9)

/*==================[type definitions]=======================================*/
typedef void (* tFSAdcMonitorReport) (enum exec_range_t range);

typedef enum
{
    CAT2 = 0,
    CAT3,
    CAT4
}e_Fs_CAlevel_t;
	
typedef struct
{
    float   LowValue;
    float   High1Value;
    float   High2Value;
    uint32  LowCount;
    uint32  NormalCount; //ms
    uint32  High1Count;
    uint32  High2Count;
    tFSAdcMonitorReport  Report;
}s_Fs_AdcMonitorCfg_t;

typedef struct
{
    uint8 Status;
    uint32 Counter;
}s_Fs_AdcMonitorInfo_t;

typedef struct 
{
    uint32* addr;
    uint32 mask;
    uint32 expectValue;
} s_Fs_PortRegvalType_t;

typedef struct 
{
    uint8 groupid;
    uint8 bitpos;
    e_Fs_CAlevel_t CATtype;
}s_Fs_SocErrorlist_t;

typedef struct
{
   boolean enable; //True: active check case False: Deactive Check case
   uint8 period; //base time :5ms
   void (*CheckFunc)(void);
   boolean WdgMenable;
   uint16 SEID;
   uint16 CheckpointID;
}s_Fs_RuntimeCheckType_t;

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

extern void FSCheck_InitFunction(void);
extern void FSCheck_MainFunction(void);
extern void FSCheck_SetSpiAliveFlag(void);
extern void FSCheck_WdgKeepFeed(boolean keep_feed);
extern uint8 FsCheck_IpcServersGetSocState(void);
extern uint8 FsCheck_IpcServerSetSocState(uint8 u8State);

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

#endif /* __FS_CHECK_H__ */
