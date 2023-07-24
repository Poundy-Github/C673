/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSMI_type.h
//! @brief     (DPRSMI) Module Type Header.

#ifndef DPRSMI_TYPE_H_
#define DPRSMI_TYPE_H_

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

/*! DPRSMI module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m15_15_1em3_t D_DPRSMI_DlcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPRSMI_DlcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPRSMI_DlcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPRSMI_DlcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPRSMI_DrcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Drc Threshold for the left road edge. \n\n
	*	\@asap_name: D_DPRSMI_DrcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_DPRSMI_DrcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Drc Threshold for the right road edge. \n\n
	*	\@asap_name: D_DPRSMI_DrcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t D_DPRSMI_TlcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_DPRSMI_TlcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPRSMI_TlcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_DPRSMI_TlcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPRSMI_TrcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Trc Threshold for the left road edge. \n\n
	*	\@asap_name: D_DPRSMI_TrcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_DPRSMI_TrcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Trc Threshold for the right road edge. \n\n
	*	\@asap_name: D_DPRSMI_TrcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_DPRSMI_TrgReasType_t S_DPRSMI_TriggerReason_nu; /*!< @description
	*	Trigger Reason of the RDP function. \n\n
	*	\@asap_name: S_DPRSMI_TriggerReason_nu \n
	*	\@values: E_DPRSMI_TrgReasType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4
	*/
	
	E_LCF_DangerousSideType_t S_DPRSMI_DangerousSide_nu; /*!< @description
	*	Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
	*	\@asap_name: S_DPRSMI_DangerousSide_nu \n
	*	\@values: E_LCF_DangerousSideType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPRSMI_FunctionAborted_bool; /*!< @description
	*	RDP aborted a lateral intervention. \n\n
	*	\@asap_name: S_DPRSMI_FunctionAborted_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPRSMI_ReadyToTrigger_bool; /*!< @description
	*	The signal is true when the RDP strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
	*	\@asap_name: S_DPRSMI_ReadyToTrigger_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_Cancel_btf; /*!< @description
	*	Bitfield with the RDP cancel conditions. \n\n
	*	\@asap_name: D_DPRSMI_Cancel_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_StrongReady_btf; /*!< @description
	*	Bitfield with the RDP strong ready conditions. \n\n
	*	\@asap_name: D_DPRSMI_StrongReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_SysStateRDP_btf; /*!< @description
	*	Bitfield with the RDP state machine inputs. \n\n
	*	\@asap_name: D_DPRSMI_SysStateRDP_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_TriggerLnLe_btf; /*!< @description
	*	Bitfield for Trigger lane on the left side. \n\n
	*	\@asap_name: D_DPRSMI_TriggerLnLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_TriggerLnReLe_btf; /*!< @description
	*	Bitfield for Trigger lane and road on the left side. \n\n
	*	\@asap_name: D_DPRSMI_TriggerLnReLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_TriggerLnReRi_btf; /*!< @description
	*	Bitfield for Trigger lane and road on the right side. \n\n
	*	\@asap_name: D_DPRSMI_TriggerLnReRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_TriggerLnRi_btf; /*!< @description
	*	Bitfield for Trigger lane on the right side. \n\n
	*	\@asap_name: D_DPRSMI_TriggerLnRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_TriggerReLe_btf; /*!< @description
	*	Bitfield for Trigger road on the left side. \n\n
	*	\@asap_name: D_DPRSMI_TriggerReLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_TriggerReRi_btf; /*!< @description
	*	Bitfield for Trigger road on the right side. \n\n
	*	\@asap_name: D_DPRSMI_TriggerReRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_DPRSMI_WeakReady_btf; /*!< @description
	*	Bitfield with the RDP weak ready conditions. \n\n
	*	\@asap_name: D_DPRSMI_WeakReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPRSMI_SenDbgType; /*!< @description DPRSMI module sensor debug data structure for MTS measurement. */

/*! DPRSMI module sensor output data structure. */
typedef struct
{
	
	E_LCF_SysStateDirectionType_t S_DPRSMI_SysStateRDPLe_nu; /*!< @description
	*	System State for the left side of the RDP function. \n\n
	*	\@asap_name: S_DPRSMI_SysStateRDPLe_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateDirectionType_t S_DPRSMI_SysStateRDPRi_nu; /*!< @description
	*	System State for the right side of the RDP function. \n\n
	*	\@asap_name: S_DPRSMI_SysStateRDPRi_nu \n
	*	\@values: E_LCF_SysStateDirectionType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateType_t S_DPRSMI_SysStateRDP_nu; /*!< @description
	*	System State of the RDP function. \n\n
	*	\@asap_name: S_DPRSMI_SysStateRDP_nu \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
} DPRSMI_SenOutType; /*!< @description DPRSMI module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // DPRSMI_TYPE_H_
