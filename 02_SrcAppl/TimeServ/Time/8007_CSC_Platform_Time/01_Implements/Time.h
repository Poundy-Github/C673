/**
 * \file Time.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.05.16			Mingfen XIAO			Init version
 * V0.0.2       2022.05.23          Mingfen XIAO            Added Total and Average time of s_Time_RunCycleMeas_t and s_Time_RunIntervalMeas_t.
 * V0.0.3       2022.06.07          Mingfen XIAO            Fixed the MeasRunCycle Average issue
 * V0.0.4       2022.06.10          Mingfen XIAO            Not used the Time_StbmTimeStamp.secondsHi to generated timestamp;
 *                                                          Added a global variable to store the StbM global timestamp,useful debug
 *                                                          Added a function of Time_InitFunction when the ecu is timesync master,shall be called this funcion.
 * V0.0.5       2022.09.13          Mingfen XIAO            Get the StbM global time via RTE interface
 *                                                          The other SWC get time stamp via RTE interface
 * V0.0.6       2022.09.14          Mingfen XIAO            Fixed an issue which the TIME_STBM_RTE_USAGE use error
 * V0.0.7       2022.09.20          Mingfen XIAO            Updated the arxml,fixed the sybmol name incorrect with the function name.
 * V0.1.0		2022.11.20			Mingfen XIAO			V0.1.0 develop baseline
 * V0.1.1       2022.12.24          Mingfen XIAO            Created the Time_MemMap.h files.
 *                                                          Modified the data type of MeasStatus for s_Time_RunIntervalMeas_t which from uint8_t to uint32_t,according to fixed the Byte alignment in MTS.
 * V0.2.0       2023.01.30          Mingfen XIAO            Split the software components of Time into separate software modules from CSC_Platform
 */

#ifndef _TIME_H_
#define _TIME_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "CSC_Platform_Common_Type.h"
#include "Time_Cfg.h"
#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
#include "StbM.h"
#include "Os_api.h"
#endif

/*==================[macros]=================================================*/
/*
 * \brief 	TIME_SW_MAJOR_VERSION,
 * */
#ifndef TIME_SW_MAJOR_VERSION
#define TIME_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (TIME_SW_MAJOR_VERSION > 99)
#error TIME_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	TIME_SW_MINOR_VERSION,
 * */
#ifndef TIME_SW_MINOR_VERSION
#define TIME_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (TIME_SW_MINOR_VERSION > 99)
#error TIME_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	TIME_SW_PATCH_VERSION,
 * */
#ifndef TIME_SW_PATCH_VERSION
#define TIME_SW_PATCH_VERSION			(7u)
#endif

/*TODO : Check the version number range*/
#if (TIME_SW_PATCH_VERSION > 99)
#error TIME_SW_PATCH_VERSION out of range
#endif

#if (TIME_TIMESTAMP_SOURCE_MODE == TIME_TIMESTAMP_SOURCE_MODE_STBM)
/*refer <<AUTOSAR_SWS_SynchronizedTimeBaseManager.pdf>>  */
#define TIME_GLOBAL_TIME_STATUS_MASK_TIMEOUT                   STBM_TIMEOUT_FLAG               /*bit 0 (LSB)*/
#define TIME_GLOBAL_TIME_STATUS_MASK_SYNC_TO_GATEWAY           STBM_SYNC_TO_GATEWAY_FLAG       /*bit 2 */
#define TIME_GLOBAL_TIME_STATUS_MASK_GLOBAL_TIME_BASE          STBM_GLOBAL_TIME_BASE_FLAG      /*bit 3 */
#define TIME_GLOBAL_TIME_STATUS_MASK_TIME_LEAP_FUTURE          STBM_TIME_LEAP_FUTURE_FLAG      /*bit 4 */
#define TIME_GLOBAL_TIME_STATUS_MASK_TIME_LEAP_PAST            STBM_TIME_LEAP_PAST_FLAG        /*bit 5 */
#else
#define TIME_GLOBAL_TIME_STATUS_MASK_TIMEOUT                   0x01         /*bit 0 (LSB)*/
#define TIME_GLOBAL_TIME_STATUS_MASK_SYNC_TO_GATEWAY           0x04         /*bit 2 */
#define TIME_GLOBAL_TIME_STATUS_MASK_GLOBAL_TIME_BASE          0x08         /*bit 3 */
#define TIME_GLOBAL_TIME_STATUS_MASK_TIME_LEAP_FUTURE          0x10         /*bit 4 */
#define TIME_GLOBAL_TIME_STATUS_MASK_TIME_LEAP_PAST            0x20         /*bit 5 */
#endif

/*
 * \brief 	TIME_ENTER_EXCLUSIVE_AREA_0 and TIME_EXIT_EXCLUSIVE_AREA_0
 *          Enter and Exit exclusive area
 * 
 * */
#define TIME_ENTER_EXCLUSIVE_AREA_0             SuspendAllInterrupts
#define TIME_EXIT_EXCLUSIVE_AREA_0              ResumeAllInterrupts

/*==================[type definitions]=======================================*/
typedef struct
{
    uint32 RunCounter;
    uint32 CurrentTimeStamp;
    uint32 LastTimeStamp;   
    float32 RunCycleMs;         /*unit is ms*/
    float32 RunCycleMs_Min;     /*unit is ms*/
    float32 RunCycleMs_Max;     /*unit is ms*/
    float32 RunCycleMs_Average;    
    float64 RunCycleMs_Total;
}s_Time_RunCycleMeas_t;

typedef struct
{
    uint32 MeasStatus;   /*0x00 : Init, 0x01 : Start, 0x02 : End, 0x03 : Error*/
    uint32 RunCounter;
    uint32 StartTimeStamp;
    uint32 EndTimeStamp;
    float32 RunIntervalMs;         /*unit is ms*/
    float32 RunIntervalMs_Min;     /*unit is ms*/
    float32 RunIntervalMs_Max;     /*unit is ms*/
    float32 RunIntervalMs_Average;
    float64 RunIntervalMs_Total;
}s_Time_RunIntervalMeas_t;

/*==================[external function declarations]========================*/
#define TIME_START_SEC_CODE
#include "Time_MemMap.h"

extern uint8 Time_GetTimeStampNs(uint64 *ts_ns);
extern uint8 Time_GetTimeStampMs(uint64 *ts_ms);
extern uint8 Time_GetTimeStampSec(uint64 *ts_sec);
extern uint8 Time_GetGlobalTimeStatus(uint8 *status);
extern uint8 Time_MeasRunCycleTimeMs(s_Time_RunCycleMeas_t *RunCycleMeas);
extern uint8 Time_MeasRunIntervalTimeMs_Start(s_Time_RunIntervalMeas_t *RunIntervalTimeMeas);
extern uint8 Time_MeasRunIntervalTimeMs_End(s_Time_RunIntervalMeas_t *RunIntervalTimeMeas);

#define TIME_STOP_SEC_CODE
#include "Time_MemMap.h"
#endif/*_TIME_H_*/