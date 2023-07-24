/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMDAE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMDAE_type.h
//! @brief     (DRMDAE) Module Type Header.

#ifndef DRMDAE_TYPE_H_
#define DRMDAE_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! DRMDAE module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	E_DRMDAE_SysWarnType_t S_DRMDAE_SysWarning_nu; /*!< @description
	*	0 - NoWarning \n
	*	1 - AttentivnessRequest \n
	*	2 - TakeOverRequest  \n
	*	3 - DegradationTrigger \n\n
	*	\@asap_name: S_DRMDAE_SysWarning_nu \n
	*	\@values: E_DRMDAE_SysWarnType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	u8_NoUnit_0_1_0_1_t S_DRMDAE_AbuseWarning_bool; /*!< @description
	*	Warning signal if driver is handsOff while funciton is interveening. \n
	*	1 - audiovisual warning on \n
	*	0 - stop abuse warning \n\n
	*	\@asap_name: S_DRMDAE_AbuseWarning_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} DRMDAE_VehDbgType; /*!< @description DRMDAE module vehicle debug data structure for MTS measurement. */

/*! DRMDAE module vehicle output data structure. */
typedef struct
{
	
	f32_Perc_0_100_1em3_t S_DRMDAE_DrvAttention_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DRMDAE_DrvAttention_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_s_0_100000_1em3_t D_DRMDAE_AbuseWarnDuration_sec; /*!< @description
	*	Duration of the Driver Abuse Warning \n\n
	*	\@asap_name: D_DRMDAE_AbuseWarnDuration_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_s_0_100000_1em3_t D_DRMDAE_ElapsedTime_sec; /*!< @description
	*	Time without Driver Abuse of Functions \n\n
	*	\@asap_name: D_DRMDAE_ElapsedTime_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	s8_Perc_m128_127_0_1_t S_DRMDAE_DrvAttentionConf_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_DRMDAE_DrvAttentionConf_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: -128 \n
	*	\@max: 127
	*/
	
	u8_NoUnit_0_1_0_1_t D_DRMDAE_ActToi_nu; /*!< @description
	*	1 if in a critical momment (one of the monitored funcitons is in controlling) \n\n
	*	\@asap_name: D_DRMDAE_ActToi_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DRMDAE_SpeedOk_bool; /*!< @description
	*	Speed Check Flag \n\n
	*	\@asap_name: D_DRMDAE_SpeedOk_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_DRMDAE_CriticalEventsNo_nu; /*!< @description
	*	Number of critical events since last reset \n
	*	Used for Driver Abuse Monitoring \n\n
	*	\@asap_name: D_DRMDAE_CriticalEventsNo_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DRMDAE_HoffTrigger_nu; /*!< @description
	*	Debug trigger signal \n\n
	*	\@asap_name: D_DRMDAE_HoffTrigger_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DRMDAE_ResetWarnCnt_nu; /*!< @description
	*	Debug reset for warning signal \n\n
	*	\@asap_name: D_DRMDAE_ResetWarnCnt_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DRMDAE_VehOutType; /*!< @description DRMDAE module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DRMDAE_TYPE_H_
