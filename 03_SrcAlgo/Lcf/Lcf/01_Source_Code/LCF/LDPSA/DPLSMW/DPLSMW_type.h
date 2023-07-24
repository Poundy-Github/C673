/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSMW_type.h
//! @brief     (DPLSMW) Module Type Header.

#ifndef DPLSMW_TYPE_H_
#define DPLSMW_TYPE_H_

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

/*! DPLSMW module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m15_15_1em3_t D_DPLSMW_DlcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPLSMW_DlcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPLSMW_DlcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPLSMW_DlcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t D_DPLSMW_TlcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPLSMW_TlcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPLSMW_TlcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPLSMW_TlcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_LCF_DangerousSideType_t S_DPLSMW_DangerousSide_nu; /*!< @description
	*	Carries the information of the side of the warning, 1 for trigger to the left and 2 for trigger to the right. \n\n
	*	\@asap_name: S_DPLSMW_DangerousSide_nu \n
	*	\@values: E_LCF_DangerousSideType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSMW_ReadyToTrigger_bool; /*!< @description
	*	The signal is true when the LDW strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
	*	\@asap_name: S_DPLSMW_ReadyToTrigger_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMW_Cancel_btf; /*!< @description
	*	Bitfield with the LDW cancel conditions. \n\n
	*	\@asap_name: D_DPLSMW_Cancel_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMW_StrongReady_btf; /*!< @description
	*	Bitfield with the LDW strong ready conditions. \n\n
	*	\@asap_name: D_DPLSMW_StrongReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMW_SysStateLDW_btf; /*!< @description
	*	Bitfield with the LDW state machine inputs. \n\n
	*	\@asap_name: D_DPLSMW_SysStateLDW_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMW_TriggerLe_btf; /*!< @description
	*	Bitfield for Trigger on the left side. \n\n
	*	\@asap_name: D_DPLSMW_TriggerLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMW_TriggerRi_btf; /*!< @description
	*	Bitfield for Trigger on the right side. \n\n
	*	\@asap_name: D_DPLSMW_TriggerRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMW_WeakReady_btf; /*!< @description
	*	Bitfield with the LDW weak ready conditions. \n\n
	*	\@asap_name: D_DPLSMW_WeakReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPLSMW_SenDbgType; /*!< @description DPLSMW module sensor debug data structure for MTS measurement. */

/*! DPLSMW module sensor output data structure. */
typedef struct
{
	
	E_LCF_SysStateDirectionType_t S_DPLSMW_SysStateLDWLe_nu; /*!< @description
	*	LDW System State. Left side. \n\n
	*	\@asap_name: S_DPLSMW_SysStateLDWLe_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateDirectionType_t S_DPLSMW_SysStateLDWRi_nu; /*!< @description
	*	LDW System State. Right side. \n\n
	*	\@asap_name: S_DPLSMW_SysStateLDWRi_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateType_t S_DPLSMW_SysStateLDW_nu; /*!< @description
	*	System State of the LDW function. \n\n
	*	\@asap_name: S_DPLSMW_SysStateLDW_nu \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
} DPLSMW_SenOutType; /*!< @description DPLSMW module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DPLSMW_TYPE_H_
