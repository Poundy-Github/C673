/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRSMI_type.h
//! @brief     (LCRSMI) Module Type Header.

#ifndef LCRSMI_TYPE_H_
#define LCRSMI_TYPE_H_

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

/*! LCRSMI module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	E_LCF_DangerousSideType_t S_LCRSMI_DangerousSide_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSMI_DangerousSide_nu \n
	*	\@values: E_LCF_DangerousSideType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	E_LCF_SysStateType_t S_LCRSMI_SysStateALCA_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSMI_SysStateALCA_nu \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSMI_Cancel_btf; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSMI_Cancel_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSMI_StrongReady_btf; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSMI_StrongReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSMI_SysStateALCA_btf; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSMI_SysStateALCA_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSMI_WeakReady_btf; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSMI_WeakReady_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_LCRSMI_FunctionAborted_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSMI_FunctionAborted_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_LCRSMI_ReadyToTrigger_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSMI_ReadyToTrigger_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	// luhui.2023.01.30. move from out to dbg
	f32_m_m15_15_1em3_t D_LCRSMI_DlcLeThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_LCRSMI_DlcLeThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t D_LCRSMI_DlcRiThreshold_met; /*!< @description
	*	Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_LCRSMI_DlcRiThreshold_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_s_0_60_1em3_t D_LCRSMI_TlcLeThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
	*	\@asap_name: D_LCRSMI_TlcLeThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t D_LCRSMI_TlcRiThreshold_sec; /*!< @description
	*	Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
	*	\@asap_name: D_LCRSMI_TlcRiThreshold_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/

} LCRSMI_SenDbgType; /*!< @description LCRSMI module sensor debug data structure for MTS measurement. */

/*! LCRSMI module sensor output data structure. */
typedef struct
{

	// f32_m_m15_15_1em3_t D_LCRSMI_DlcLeThreshold_met; /*!< @description
	// *	Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
	// *	\@asap_name: D_LCRSMI_DlcLeThreshold_met \n
	// *	\@type: value \n
	// *	\@unit: m \n
	// *	\@min: -15 \n
	// *	\@max: 15
	// */
	
	// f32_m_m15_15_1em3_t D_LCRSMI_DlcRiThreshold_met; /*!< @description
	// *	Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
	// *	\@asap_name: D_LCRSMI_DlcRiThreshold_met \n
	// *	\@type: value \n
	// *	\@unit: m \n
	// *	\@min: -15 \n
	// *	\@max: 15
	// */
	
	// f32_s_0_60_1em3_t D_LCRSMI_TlcLeThreshold_sec; /*!< @description
	// *	Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
	// *	\@asap_name: D_LCRSMI_TlcLeThreshold_sec \n
	// *	\@type: value \n
	// *	\@unit: s \n
	// *	\@min: 0 \n
	// *	\@max: 60
	// */
	
	// f32_s_0_60_1em3_t D_LCRSMI_TlcRiThreshold_sec; /*!< @description
	// *	Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
	// *	\@asap_name: D_LCRSMI_TlcRiThreshold_sec \n
	// *	\@type: value \n
	// *	\@unit: s \n
	// *	\@min: 0 \n
	// *	\@max: 60
	// */

	
	E_LCF_SysStateDirObjType_t S_LCRSMI_SysStateALCALe_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSMI_SysStateALCALe_nu \n
	*	\@values: E_LCF_SysStateDirObjType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
	E_LCF_SysStateDirObjType_t S_LCRSMI_SysStateALCARi_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSMI_SysStateALCARi_nu \n
	*	\@values: E_LCF_SysStateDirObjType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 15
	*/
	
} LCRSMI_SenOutType; /*!< @description LCRSMI module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // LCRSMI_TYPE_H_
