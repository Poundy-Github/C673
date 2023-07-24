/**
 * \file Time_Cfg.h
 *
 * \brief
 *
 * \version refer Time.h
 * 
 */

#ifndef _TIME_CFG_H_
#define _TIME_CFG_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros]=================================================*/
/*
 * \brief 	TIME_TIMESTAMP_SOURCE_MODE,
 *          
 * 
 * */
#define TIME_TIMESTAMP_SOURCE_MODE_STBM         (0x01u) /*The timestamp source is StbM*/
#define TIME_TIMESTAMP_SOURCE_MODE_STM0         (0x02u) /*The timestamp source is System Timer 0*/
#define TIME_TIMESTAMP_SOURCE_MODE              TIME_TIMESTAMP_SOURCE_MODE_STBM

#define TIME_STBM_TIMEBASE_ID                   (0x00u)  

#define TIME_STM0_CLK_FREQ                      (100000000ul) /*unit is Hz*/

/*
 * \brief 	TIME_TIMESYNC_MASTER,
 *          STD_ON : Shall be set the StbM via StbM_SetGlobalTime
 *          STD_OFF : 
 * 
 * */
#define TIME_TIMESYNC_MASTER                    STD_OFF
#if (TIME_TIMESYNC_MASTER == STD_ON)
#define TIME_TIMESYNC_MASTER_INIT_SEC           (14400ul)           
#define TIME_TIMESYNC_MASTER_INIT_NS            (0u)
#endif

/*
 * \brief 	TIME_STBM_RTE_USAGE,
 *          means get the STBM current time use the RTE
 * 
 * */
#define TIME_STBM_RTE_USAGE                             STD_ON

#if (TIME_STBM_RTE_USAGE == STD_ON)
/*
 * \brief 	Time_StbMGlobalTime_Slave_GetCurrentTime
 * 
 * */
#define Time_StbMGlobalTime_Slave_GetCurrentTime        Rte_Call_GlobalTime_Slave_StbMSynchronizedTimeBase_0_GetCurrentTime
/*
 * \brief 	Time_StbMGlobalTime_Slave_GetRateDeviation
 * 
 * */
#define Time_StbMGlobalTime_Slave_GetRateDeviation      Rte_Call_GlobalTime_Slave_StbMSynchronizedTimeBase_0_GetRateDeviation
/*
 * \brief 	Time_StbMGlobalTime_Slave_GetTimeBaseStatus
 * 
 * */
#define Time_StbMGlobalTime_Slave_GetTimeBaseStatus     Rte_Call_GlobalTime_Slave_StbMSynchronizedTimeBase_0_GetTimeBaseStatus
#endif/*TIME_STBM_RTE_USAGE*/

#endif/*_TIME_CFG_H_*/