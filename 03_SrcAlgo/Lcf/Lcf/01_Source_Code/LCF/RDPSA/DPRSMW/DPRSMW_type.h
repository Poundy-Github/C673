/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSMW_type.h
//! @brief     (DPRSMW) Module Type Header.

#ifndef DPRSMW_TYPE_H_
#define DPRSMW_TYPE_H_

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

/*! DPRSMW module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m15_15_1em3_t D_DPRSMW_DlcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPRSMW_DlcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPRSMW_DlcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPRSMW_DlcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPRSMW_DrcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Drc Threshold for the left road edge. \n\n
	*	\@asap_name: D_DPRSMW_DrcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPRSMW_DrcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Drc Threshold for the right road edge. \n\n
	*	\@asap_name: D_DPRSMW_DrcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t D_DPRSMW_TlcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPRSMW_TlcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPRSMW_TlcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPRSMW_TlcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPRSMW_TrcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Trc Threshold for the left road edge. \n\n
	*	\@asap_name: D_DPRSMW_TrcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPRSMW_TrcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Trc Threshold for the right road edge. \n\n
	*	\@asap_name: D_DPRSMW_TrcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_DPRSMI_TrgReasType_t S_DPRSMW_TriggerReason_nu; /*!< @description
	*	Trigger Reason of the RDW function. \n\n
	*	\@asap_name: S_DPRSMW_TriggerReason_nu \n
	*	\@values: E_DPRSMI_TrgReasType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4
	*/
	
	E_LCF_DangerousSideType_t S_DPRSMW_DangerousSide_nu; /*!< @description
	*	Carries the information of the side of the warning, 1 for trigger to the left and 2 for trigger to the right. \n\n
	*	\@asap_name: S_DPRSMW_DangerousSide_nu \n
	*	\@values: E_LCF_DangerousSideType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPRSMW_ReadyToTrigger_bool; /*!< @description
	*	The signal is true when the RDW strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
	*	\@asap_name: S_DPRSMW_ReadyToTrigger_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_Cancel_btf; /*!< @description
	*	Bitfield with the RDW cancel conditions. \n\n
	*	\@asap_name: D_DPRSMW_Cancel_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_StrongReady_btf; /*!< @description
	*	Bitfield with the RDW strong ready conditions. \n\n
	*	\@asap_name: D_DPRSMW_StrongReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_SysStateRDW_btf; /*!< @description
	*	Bitfield with the RDW state machine inputs. \n\n
	*	\@asap_name: D_DPRSMW_SysStateRDW_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_TriggerLnLe_btf; /*!< @description
	*	Bitfield for Trigger lane for the left side. \n\n
	*	\@asap_name: D_DPRSMW_TriggerLnLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_TriggerLnReLe_btf; /*!< @description
	*	Bitfield for Trigger lane and road for the left side. \n\n
	*	\@asap_name: D_DPRSMW_TriggerLnReLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_TriggerLnReRi_btf; /*!< @description
	*	Bitfield for Trigger lane and road for the right side. \n\n
	*	\@asap_name: D_DPRSMW_TriggerLnReRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_TriggerLnRi_btf; /*!< @description
	*	Bitfield for Trigger lane for the right side. \n\n
	*	\@asap_name: D_DPRSMW_TriggerLnRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_TriggerReLe_btf; /*!< @description
	*	Bitfield for Trigger road for the left side. \n\n
	*	\@asap_name: D_DPRSMW_TriggerReLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_TriggerReRi_btf; /*!< @description
	*	Bitfield for Trigger road for the right side. \n\n
	*	\@asap_name: D_DPRSMW_TriggerReRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMW_WeakReady_btf; /*!< @description
	*	Bitfield with the RDW weak ready conditions. \n\n
	*	\@asap_name: D_DPRSMW_WeakReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPRSMW_SenDbgType; /*!< @description DPRSMW module sensor debug data structure for MTS measurement. */

/*! DPRSMW module sensor output data structure. */
typedef struct
{
	
	E_LCF_SysStateDirectionType_t S_DPRSMW_SysStateRDWLe_nu; /*!< @description
	*	System State for the left side of the RDW function. \n\n
	*	\@asap_name: S_DPRSMW_SysStateRDWLe_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateDirectionType_t S_DPRSMW_SysStateRDWRi_nu; /*!< @description
	*	System State for the right side of the RDW function. \n\n
	*	\@asap_name: S_DPRSMW_SysStateRDWRi_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateType_t S_DPRSMW_SysStateRDW_nu; /*!< @description
	*	System State of the RDW function. \n\n
	*	\@asap_name: S_DPRSMW_SysStateRDW_nu \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
} DPRSMW_SenOutType; /*!< @description DPRSMW module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DPRSMW_TYPE_H_
