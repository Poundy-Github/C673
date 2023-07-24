/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSMI_type.h
//! @brief     (DPLSMI) Module Type Header.

#ifndef DPLSMI_TYPE_H_
#define DPLSMI_TYPE_H_

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

/*! DPLSMI module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m15_15_1em3_t D_DPLSMI_DlcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPLSMI_DlcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPLSMI_DlcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPLSMI_DlcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t D_DPLSMI_TlcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPLSMI_TlcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPLSMI_TlcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPLSMI_TlcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_LCF_DangerousSideType_t S_DPLSMI_DangerousSide_nu; /*!< @description
	*	Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
	*	\@asap_name: S_DPLSMI_DangerousSide_nu \n
	*	\@values: E_LCF_DangerousSideType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSMI_FunctionAborted_bool; /*!< @description
	*	The signal is 1 for the whole rampout duration if the rampout was caused by an abort condition. \n\n
	*	\@asap_name: S_DPLSMI_FunctionAborted_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSMI_ReadyToTrigger_bool; /*!< @description
	*	The signal is true when the LDP strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
	*	\@asap_name: S_DPLSMI_ReadyToTrigger_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMI_Cancel_btf; /*!< @description
	*	Bitfield with the LDP cancel conditions. \n\n
	*	\@asap_name: D_DPLSMI_Cancel_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMI_StrongReady_btf; /*!< @description
	*	Bitfield with the LDP strong ready conditions. \n\n
	*	\@asap_name: D_DPLSMI_StrongReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMI_SysStateLDP_btf; /*!< @description
	*	Bitfield with the LDP state machine inputs. \n\n
	*	\@asap_name: D_DPLSMI_SysStateLDP_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMI_TriggerLe_btf; /*!< @description
	*	Bitfield for Trigger condition for left side. \n\n
	*	\@asap_name: D_DPLSMI_TriggerLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMI_TriggerRi_btf; /*!< @description
	*	Bitfield for Trigger condition for right side. \n\n
	*	\@asap_name: D_DPLSMI_TriggerRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPLSMI_WeakReady_btf; /*!< @description
	*	Bitfield with the LDP weak ready conditions. \n\n
	*	\@asap_name: D_DPLSMI_WeakReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPLSMI_SenDbgType; /*!< @description DPLSMI module sensor debug data structure for MTS measurement. */

/*! DPLSMI module sensor output data structure. */
typedef struct
{
	
	E_LCF_SysStateDirectionType_t S_DPLSMI_SysStateLDPLe_nu; /*!< @description
	*	System State for the left side of the LDP function. \n\n
	*	\@asap_name: S_DPLSMI_SysStateLDPLe_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateDirectionType_t S_DPLSMI_SysStateLDPRi_nu; /*!< @description
	*	System State for the right side of the LDP function. \n\n
	*	\@asap_name: S_DPLSMI_SysStateLDPRi_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateType_t S_DPLSMI_SysStateLDP_nu; /*!< @description
	*	System State of the LDP function. \n\n
	*	\@asap_name: S_DPLSMI_SysStateLDP_nu \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
} DPLSMI_SenOutType; /*!< @description DPLSMI module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DPLSMI_TYPE_H_
