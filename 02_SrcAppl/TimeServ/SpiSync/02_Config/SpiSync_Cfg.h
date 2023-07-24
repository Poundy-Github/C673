/**
 * \file SpiSync_Cfg.h
 *
 * \brief 
 *
 * \version refer the SpiSync_Core.h.
 *
 */

#ifndef _SPISYNC_CFG_H_
#define _SPISYNC_CFG_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Dio.h"
#include "SpiSync_Stubs.h"

/*==================[macros]=================================================*/
/*
 * \brief 	SPISYNC_FUNCTION_ENABLE,
 *          STD_ON : enable the SpiSync function
 *          STD_OFF : disable the SpiSync function
 * */
#define SPISYNC_FUNCTION_ENABLE                                 STD_ON
/*
 * \brief 	SPISYNC_DEBUG_ENABLE,
 * */
#define SPISYNC_DEBUG_ENABLE                                    STD_ON
/*
 * \brief 	SPISYNC_USE_RTE_INTERFACE,
 *          STD_ON : use rte interface call the StbM and Dio
 *          STD_OFF : direct call the StbM and Dio
 * */
#define SPISYNC_USE_RTE_INTERFACE								STD_OFF

#if (SPISYNC_USE_RTE_INTERFACE == STD_OFF)
/*
 * \brief 	SPISYNC_PPS_DIO_CHANNEL,
 *          refer the Dio configuration parameters
 * */
#define SPISYNC_PPS_DIO_CHANNEL                                 DioConf_DioChannel_DIO_DO_MCU_P1401_J3_GPIO25
#define SPISYNC_PPS_DIO_SET                                     Dio_WriteChannel
#else
#define SPISYNC_PPS_DIO_SET                                     /*TBD*/
#endif
/*
 * \brief 	SPISYNC_PPS_DIO_SYNC_LEVEL,
 *          When the time sync,the dio set vlotage level
 * */
#define SPISYNC_PPS_DIO_SYNC_LEVEL                              STD_LOW
/*
 * \brief 	SPISYNC_TIMESYNC_DYNAMIC_OFFSET_ENABLE,
 *          STD_ON : The offset from external signal,e.g.can signal or NvM data? dynamic offset via 
 *          STD_OFF : The offset is static,it from the macro of SPISYNC_TIMESYNC_STATIC_TIMESTAMP_OFFSET
 * */
#define SPISYNC_TIMESYNC_DYNAMIC_OFFSET_ENABLE                  STD_ON         
/*
 * \brief 	SPISYNC_TIMESYNC_DYNAMIC_OFFSET_WAIT_TIME,
 *          wait external dynamic offset time,unit is ms
 * */
#define SPISYNC_TIMESYNC_DYNAMIC_OFFSET_WAIT_TIME               (10000u)
/*
 * \brief 	SPISYNC_TIMESYNC_START_UP_WAIT_TIME,
 *          SpiSync module wait start up time,unit is ms
 * */
#define SPISYNC_TIMESYNC_START_UP_WAIT_TIME                     (1000u)
/*
 * \brief 	SPISYNC_TIMESYNC_DYNAMIC_OFFSET_WAIT_TIME,
 *          wait external dynamic offset time,unit is s
 * */
#define SPISYNC_TIMESYNC_DYNAMIC_DEFAULT_TIMESTAMP_OFFSET       (946656000ul) ///<2000-1-1 0:0:0
/*
 * \brief 	SPISYNC_TIMESYNC_DYNAMIC_GET_TIMESTAMP,
 *          get dynamic timestamp via API
 * */
#define SPISYNC_TIMESYNC_DYNAMIC_GET_TIMESTAMP                  SpiSync_Cot_GetTimestampOffset
/*
 * \brief 	SPISYNC_TIMESYNC_STATIC_TIMESTAMP_OFFSET,
 *          unit is ns,the Spi Time Sync message of Time stamp unit is s.
 * \comments When the J3 time stamp base not 1970 and not support time goes back,it may be set a offset
 * */
#define SPISYNC_TIMESYNC_STATIC_TIMESTAMP_OFFSET                 (0u)
/*
 * \brief 	SPISYNC_MAIN_FUNCTION_PERIOD_TIME,
 *          unit is ms
 * */
#define SPISYNC_MAIN_FUNCTION_PERIOD_TIME						5u
/*
 * \brief 	SPISYNC_TIMESYNC_CHANNEL_NUMBER,
 *          
 * */
#define SPISYNC_TIMESYNC_CHANNEL_NUMBER                         1U
/*
 * \brief 	SPISYNC_TIMESYNC_CHECK_GLOBAL_STATUS,
 *          
 * */
#define SPISYNC_TIMESYNC_CHECK_GLOBAL_STATUS                    STD_ON
/*
 * \brief 	SPISYNC_SEND_TIMESYNCMSG_API,
 *          
 * */
#define SPISYNC_SEND_TIMESYNCMSG_API                            Rte_Call_RP_Sdc_TimeSync_TimeSyncMsg
/*
 * \brief 	SPISYNC_USERFUNCTION_ENABLE,
 *          The user function include user init function and user main function
 *          
 * */
#define SPISYNC_USERFUNCTION_ENABLE                             STD_ON
/***
 * @brief   The byte position of Signal UTC valid   
*/
#define SPISYNC_SIG_UTCVALID_BYTE_POS                           4u
/***
 * @brief   The bit mask of Signal UTC valid
 *          Bit 5 -> 0x20
*/
#define SPISYNC_SIG_UTCVALID_BIT_MASK                           0x20
#if(SPISYNC_USERFUNCTION_ENABLE == STD_ON)
extern void SpiSync_UserInitFunction(void);
extern void SpiSync_UserMainFunction(void);
#endif

#endif /* _SPISYNC_CFG_H_ */