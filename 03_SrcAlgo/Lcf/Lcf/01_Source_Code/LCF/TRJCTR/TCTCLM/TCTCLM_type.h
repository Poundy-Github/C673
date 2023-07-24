/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCLM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTCLM_type.h
//! @brief     (TCTCLM) Module Type Header.

#ifndef TCTCLM_TYPE_H_
#define TCTCLM_TYPE_H_

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

/*! TCTCLM module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTCLM_FrozenVehCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_FrozenVehCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTCLM_PlausiChkLowLimit_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_PlausiChkLowLimit_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTCLM_PlausiChkUpLimit_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_PlausiChkUpLimit_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTCLM_SumCtrlSignal_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_SumCtrlSignal_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTCLM_FbcDc_1pm; /*!< @description
	*	Control signal of the Feedback Controller + Disturbance Compensator after safety checks \n\n
	*	\@asap_name: S_TCTCLM_FbcDc_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTCLM_Ffc_1pm; /*!< @description
	*	Control signal of the Feedforward Controller after safety checks \n\n
	*	\@asap_name: S_TCTCLM_Ffc_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTCLM_Limiter_TgtCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTCLM_Limiter_TgtCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_deg_m720_720_1em3_t S_TCTCLM_DeltaFCmd_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTCLM_DeltaFCmd_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -720 \n
	*	\@max: 720
	*/
	
	f32_s_0_60_1em3_t D_TCTCLM_TimerValue_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_TimerValue_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCLM_FlagTimerLastCall_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_FlagTimerLastCall_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCLM_PlausibCheckActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_PlausibCheckActive_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCLM_PlausibCheckPrecond_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_PlausibCheckPrecond_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCLM_QuServErrMemReset_nu; /*!< @description
	*	Reset condition for Flip-Flop which holds degradation request \n\n
	*	\@asap_name: D_TCTCLM_QuServErrMemReset_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCLM_QuServErrMemSet_nu; /*!< @description
	*	Set condition for Flip-Flop which holds degradation request \n\n
	*	\@asap_name: D_TCTCLM_QuServErrMemSet_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCLM_UnplsblDrctnOfRqst_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_UnplsblDrctnOfRqst_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TCTCLM_LimiterWarning_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTCLM_LimiterWarning_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_TCTCLM_LimiterWthtErrCntr_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCLM_LimiterWthtErrCntr_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t D_TCTCLM_QualifierService_nu; /*!< @description
	*	Qualifier signal of TCTCLM: \n
	*	xxxx xxx1: Feedforward control signal exceeds the gradient limiter \n
	*	xxxx xx1x: Feedforward control signal exceeds the saturation limiter \n
	*	xxxx x1xx: Feedback control signal exceeds the gradient limiter \n
	*	xxxx 1xxx: Feedback control signal exceeds the saturation limiter \n
	*	xxx1 xxxx: Unplausible Direction of Request \n\n
	*	\@asap_name: D_TCTCLM_QualifierService_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_TCTCLM_QuServTrajCtr_nu; /*!< @description
	*	Trajectory controller qualifier. Includes relevant information for the Situation Assessment components. \n\n
	*	\@asap_name: S_TCTCLM_QuServTrajCtr_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TCTCLM_VehDbgType; /*!< @description TCTCLM module vehicle debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // TCTCLM_TYPE_H_
