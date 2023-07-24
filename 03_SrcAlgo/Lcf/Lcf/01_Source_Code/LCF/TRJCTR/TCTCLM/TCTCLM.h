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
//! @file     TCTCLM.h
//! @brief     (TCTCLM) Module Header.

#ifndef TCTCLM_H_
#define TCTCLM_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH/LCFVEH_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TCTCLM module vehicle initialization function. Function initializes TCTCLM vehicle debug data pointer.
 *	
 *	@param
 *		[in] TCTCLM_VehDbgArg Pointer to TCTCLM vehicle debug data.
 *		
 *	@return
 *		void
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void TCTCLM_VehInitDbgPtr(TCTCLM_VehDbgType *TCTCLM_VehDbgArg);

/*!
 *	TCTCLM module vehicle reset function.
 *	
 *	@pre
 *		- The TCTCLM vehicle initialization function(s) must be called once.
 *		- The TCTCLM vehicle debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		[Debug  Signal] [D_TCTCLM_FlagTimerLastCall_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_FlagTimerLastCall_nu) \n
 *		[Debug  Signal] [D_TCTCLM_FrozenVehCrv_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_FrozenVehCrv_1pm) \n
 *		[Debug  Signal] [D_TCTCLM_LimiterWthtErrCntr_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_LimiterWthtErrCntr_nu) \n
 *		[Debug  Signal] [D_TCTCLM_PlausiChkLowLimit_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausiChkLowLimit_1pm) \n
 *		[Debug  Signal] [D_TCTCLM_PlausiChkUpLimit_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausiChkUpLimit_1pm) \n
 *		[Debug  Signal] [D_TCTCLM_PlausibCheckActive_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausibCheckActive_nu) \n
 *		[Debug  Signal] [D_TCTCLM_PlausibCheckPrecond_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausibCheckPrecond_nu) \n
 *		[Debug  Signal] [D_TCTCLM_QuServErrMemReset_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_QuServErrMemReset_nu) \n
 *		[Debug  Signal] [D_TCTCLM_QuServErrMemSet_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_QuServErrMemSet_nu) \n
 *		[Debug  Signal] [D_TCTCLM_QualifierService_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_QualifierService_nu) \n
 *		[Debug  Signal] [D_TCTCLM_SumCtrlSignal_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_SumCtrlSignal_1pm) \n
 *		[Debug  Signal] [D_TCTCLM_TimerValue_sec](@ref TCTCLM_VehDbgType::D_TCTCLM_TimerValue_sec) \n
 *		[Debug  Signal] [D_TCTCLM_UnplsblDrctnOfRqst_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_UnplsblDrctnOfRqst_nu) \n
 *		[Debug  Signal] [S_TCTCLM_DeltaFCmd_deg](@ref TCTCLM_VehDbgType::S_TCTCLM_DeltaFCmd_deg) \n
 *		[Debug  Signal] [S_TCTCLM_FbcDc_1pm](@ref TCTCLM_VehDbgType::S_TCTCLM_FbcDc_1pm) \n
 *		[Debug  Signal] [S_TCTCLM_Ffc_1pm](@ref TCTCLM_VehDbgType::S_TCTCLM_Ffc_1pm) \n
 *		[Debug  Signal] [S_TCTCLM_LimiterWarning_nu](@ref TCTCLM_VehDbgType::S_TCTCLM_LimiterWarning_nu) \n
 *		[Debug  Signal] [S_TCTCLM_Limiter_TgtCrv_1pm](@ref TCTCLM_VehDbgType::S_TCTCLM_Limiter_TgtCrv_1pm) \n
 *		[Debug  Signal] [S_TCTCLM_QuServTrajCtr_nu](@ref TCTCLM_VehDbgType::S_TCTCLM_QuServTrajCtr_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TCTCLM_VehProcess_Globals) of the function @ref TCTCLM_VehProcess.
 *		
 *	@InOutCorrelation
 *		Resets all static global variables.
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern void TCTCLM_VehReset(void);

/*!
 *	TCTCLM module vehicle process function.
 *	
 *	@pre
 *		- The TCTCLM vehicle initialization function(s) must be called once.
 *		- The TCTCLM vehicle debug/output data pointer(s) should not be NULL.
 *		
 *	@post
 *		
 *	@param
 *		void
 *		
 *	@return
 *		void
 *		
 *	@globals
 *		@anchor TCTCLM_VehProcess_Globals
 *		[D_TCTCLM_FlagTimerLastCall_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_FlagTimerLastCall_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_FrozenVehCrv_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_FrozenVehCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_LimiterWthtErrCntr_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_LimiterWthtErrCntr_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_PlausiChkLowLimit_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausiChkLowLimit_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_PlausiChkUpLimit_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausiChkUpLimit_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_PlausibCheckActive_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausibCheckActive_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_PlausibCheckPrecond_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_PlausibCheckPrecond_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_QuServErrMemReset_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_QuServErrMemReset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Reset condition for Flip-Flop which holds degradation request \n\n
 *		[D_TCTCLM_QuServErrMemSet_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_QuServErrMemSet_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Set condition for Flip-Flop which holds degradation request \n\n
 *		[D_TCTCLM_QualifierService_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_QualifierService_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Qualifier signal of TCTCLM: \n
 *		xxxx xxx1: Feedforward control signal exceeds the gradient limiter \n
 *		xxxx xx1x: Feedforward control signal exceeds the saturation limiter \n
 *		xxxx x1xx: Feedback control signal exceeds the gradient limiter \n
 *		xxxx 1xxx: Feedback control signal exceeds the saturation limiter \n
 *		xxx1 xxxx: Unplausible Direction of Request \n\n
 *		[D_TCTCLM_SumCtrlSignal_1pm](@ref TCTCLM_VehDbgType::D_TCTCLM_SumCtrlSignal_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_TimerValue_sec](@ref TCTCLM_VehDbgType::D_TCTCLM_TimerValue_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TCTCLM_UnplsblDrctnOfRqst_nu](@ref TCTCLM_VehDbgType::D_TCTCLM_UnplsblDrctnOfRqst_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTCLM_DeltaFCmd_deg](@ref TCTCLM_VehDbgType::S_TCTCLM_DeltaFCmd_deg) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTCLM_FbcDc_1pm](@ref TCTCLM_VehDbgType::S_TCTCLM_FbcDc_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Control signal of the Feedback Controller + Disturbance Compensator after safety checks \n\n
 *		[S_TCTCLM_Ffc_1pm](@ref TCTCLM_VehDbgType::S_TCTCLM_Ffc_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Control signal of the Feedforward Controller after safety checks \n\n
 *		[S_TCTCLM_LimiterWarning_nu](@ref TCTCLM_VehDbgType::S_TCTCLM_LimiterWarning_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTCLM_Limiter_TgtCrv_1pm](@ref TCTCLM_VehDbgType::S_TCTCLM_Limiter_TgtCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TCTCLM_QuServTrajCtr_nu](@ref TCTCLM_VehDbgType::S_TCTCLM_QuServTrajCtr_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Trajectory controller qualifier. Includes relevant information for the Situation Assessment components. \n\n
 *		@ref S_CSCLTA_LimiterActivated_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LimiterTimeDuration_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_SysStateLCF_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_LCFRCV_LaneStatusLaKMC_st \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_LaKMCLaneStatusType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Side of xDP Intervention \n\n
 *		@ref S_LCFRCV_SysCycleTimeVeh_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p03_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.03 \n
 *		\@description: \n
 *		Cycle Time for VEH task \n\n
 *		@ref S_LCFRCV_VehCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Vehicle curvature \n\n
 *		@ref S_LCFRCV_VehOdoState_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_VehVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Vehicle Speed in miles/hour, computed based on the wheel speeds \n
 *		Negative values when vehicle moves backward \n\n
 *		@ref S_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_TCTCDC_QualifierService_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Qualifier signal of TCTCDC: \n
 *		xxxx xxx1: Too high deviation in the control error regarding the Y-Coordinate \n
 *		xxxx xx1x: Too high deviation in the control error regarding the Course Angle \n
 *		xxxx x1xx: Too high deviation in the control error regarding the Course Angle with Preview \n\n
 *		@ref S_TCTDTE_CrvReqBnkAglComp_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTDTE_CrvReqDstrbComp_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTEST_QualifierService_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u32_NoUnit_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTLGC_CtrlCrv_DE_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TCTLGC_DeltaFCmd_deg \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Steering Angle Command for DMC \n\n
 *		@ref S_TCTLGC_FFCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLCEN_ReplanCurValues_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_TCTCLM_ErrCntrCyclesToCheck_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_10_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Error Counter -> Number of Cycles to Check for the sliding sum \n\n
 *		@ref P_TCTCLM_ErrCntrDisengageThr_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_20_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Thresold of the Error Counter leading to a function disengagement \n\n
 *		@ref P_TCTCLM_FbcCrvInterface_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Select interface for the feedback controller \n
 *		0: Steer Angle Interface \n
 *		1: Curvature Interface \n\n
 *		@ref P_TCTCLM_FfcCrvInterface_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Select interface for the feedforward controller \n
 *		0: Steer Angle Interface \n
 *		1: Curvature Interface \n\n
 *		@ref P_TCTCLM_QuServiceErrMemAct_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Activate/Deactivate hold functionality of degradation request \n
 *		0: Deactivate \n
 *		1: Activate \n\n
 *		@ref P_TCTCLM_QuServiceMaxTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum hold time of degradation request \n\n
 *		@ref P_TCTCLM_QuServiceMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum hold time of degradation request \n\n
 *		@ref P_TCTCLM_QuServiceOverride_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Force degradation request via signal S_TCTCLM_QuServTrajCtr \n
 *		0: Use conventional degradation request conditions \n
 *		1: Force degradation request \n\n
 *		@ref P_TCTCLM_WtchdgCDCQuSv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask for selecting the bits to be checked in the signal S_TCTCDC_QualifierService_nu \n\n
 *		@ref P_TCTCLM_WtchdgCLMQuSv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask for selecting the bits to be checked in the signal D_TCTCLM_QualifierService_nu \n\n
 *		@ref P_VEH_DistCogToFrontAxle_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Distance between front axle and the vehicle's center of gravity \n\n
 *		@ref P_VEH_DistCogToRearAxle_m \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Distance between rear axle and the vehicle's center of gravity \n\n
 *		@ref P_VEH_SelfSteeringGrd_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Self Steering Gradient of the Vehicle \n\n
 *		@ref X_TCTCLM_ControllingFunction_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		X-Axis: Controlling Function \n\n
 *		@ref X_TCTCLM_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Velocity vector along the vehicle's longitudinal axis / (m/s) \n\n
 *		@ref Y_TCTCLM_GrdLimitDeltaFCmd_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_0_360_1em2_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: °/s \n
 *		\@min: 0 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Absolut value of the gradient limitation of the set value send to the LaDMC \n\n
 *		@ref Y_TCTCLM_GrdLimitFbcDc_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_10_1em6_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Absolute value / (1/(m*s)) of the maximal allowed gradient of the control signal "Feedback Controller + Disturbance Compensator" send to the LaDMC \n\n
 *		@ref Y_TCTCLM_GrdLimitFfc_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_10_1em6_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Absolute value / (1/(m*s)) of the maximal allowed gradient of the control signal Feedforward Controller" send to the LaDMC \n\n
 *		@ref Y_TCTCLM_GrdLimitGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Gain of the gradient limitation in dependence on the controlling function \n\n
 *		@ref Y_TCTCLM_LimitDeltaFCmd_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m90_90_1em8_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: ° \n
 *		\@min: -90 \n
 *		\@max: 90 \n
 *		\@description: \n
 *		Absolute value of the saturation of the set value send to the LaDMC \n\n
 *		@ref Y_TCTCLM_LimitFbcDc_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p5001_1em8_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.5001 \n
 *		\@description: \n
 *		Absolute value / (1/m) of the maximal allowed control signal "Feedback Controller + Disturbance Compensator" send to the LaDMC \n\n
 *		@ref Y_TCTCLM_LimitFfc_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p5001_1em8_t \n
 *		\@size: 1x15x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.5001 \n
 *		\@description: \n
 *		Absolute value / (1/m) of the maximal allowed control signal "Feedforward Controller" send to the LaDMC \n\n
 *		@ref Y_TCTCLM_LimitGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Gain of the saturation in dependence on the controlling function \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TCTCLM Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TCTCLM_Testcase_Initialization) Initialization of the TCTCLM
 *		-# [Testcase_LimiterTgtCrv](@ref TCTCLM_Testcase_LimiterTgtCrv) Sum of S_TCTCLM_FbcDc_1pm and S_TCTCLM_Ffc_1pm (FCT_CMP_TRJCTR_493, FCT_CMP_TRJCTR_591, FCT_CMP_TRJCTR_589, FCT_CMP_TRJCTR_592)
 *		-# [Testcase_Stage2GrdLimit_FFCrv_1pm](@ref TCTCLM_Testcase_Stage2GrdLimit_FFCrv_1pm) Stage 2 Gradient Limiter of S_TrjC_FFCrv_1pm (FCT_CMP_TRJCTR_516)
 *		-# [Testcase_Stage2GrdLimit_CtrlCrvDE_1pm](@ref TCTCLM_Testcase_Stage2GrdLimit_CtrlCrvDE_1pm) Stage 2 Gradient Limiter of S_TrjC_CtrlCrv_DE_1pm (FCT_CMP_TRJCTR_518)
 *		-# [Testcase_Stage2GrdLimit_DeltaFCmd_deg](@ref TCTCLM_Testcase_Stage2GrdLimit_DeltaFCmd_deg) Stage 2 Gradient Limiter of S_TCTLGC_DeltaFCmd_deg (FCT_CMP_TRJCTR_520)
 *		-# [Testcase_SatLimit_FFCrv_1pm](@ref TCTCLM_Testcase_SatLimit_FFCrv_1pm) Saturation of S_TrjC_FFCrv_1pm (FCT_CMP_TRJCTR_523)
 *		-# [Testcase_SatLimit_CtrlCrvDE_1pm](@ref TCTCLM_Testcase_SatLimit_CtrlCrvDE_1pm) Saturation of S_TrjC_CtrlCrv_DE_1pm (FCT_CMP_TRJCTR_525)
 *		-# [Testcase_SatLimit_DeltaFCmd_1pm](@ref TCTCLM_Testcase_SatLimit_DeltaFCmd_1pm) Saturation of S_TCTLGC_DeltaFCmd_deg (FCT_CMP_TRJCTR_527)
 *		-# [Testcase_PlausibCheckPrecond](@ref TCTCLM_Testcase_PlausibCheckPrecond) D_TCTCLM_PlausibCheckPrecond_nu (FCT_CMP_TRJCTR_530)
 *		-# [Testcase_PlausibCheckTimer](@ref TCTCLM_Testcase_PlausibCheckTimer) D_TCTCLM_TimerValue_sec, D_TCTCLM_FlagTimerLastCall_nu (FCT_CMP_TRJCTR_531)
 *		-# [Testcase_PlausibCheckActive](@ref TCTCLM_Testcase_PlausibCheckActive) D_TCTCLM_PlausibCheckActive_nu (FCT_CMP_TRJCTR_532)
 *		-# [Testcase_FreezeVehCrv](@ref TCTCLM_Testcase_FreezeVehCrv) D_TCTCLM_FrozenVehCrv_1pm (FCT_CMP_TRJCTR_533)
 *		-# [Testcase_PlausibCheckUpperLim](@ref TCTCLM_Testcase_PlausibCheckUpperLim) D_TCTCLM_PlausiChkUpLimit_1pm (FCT_CMP_TRJCTR_534, FCT_CMP_TRJCTR_535, FCT_CMP_TRJCTR_538)
 *		-# [Testcase_PlausibCheckLowerLim](@ref TCTCLM_Testcase_PlausibCheckLowerLim) D_TCTCLM_PlausiChkLowLimit_1pm (FCT_CMP_TRJCTR_536, FCT_CMP_TRJCTR_537, FCT_CMP_TRJCTR_538)
 *		-# [Testcase_PlausibCheckWarning](@ref TCTCLM_Testcase_PlausibCheckWarning) S_TCTCLM_LimiterWarning_nu (FCT_CMP_TRJCTR_539)
 *		-# [Testcase_PlausibCheckWarningStorage](@ref TCTCLM_Testcase_PlausibCheckWarningStorage) D_TCTCLM_UnplsblDrctnOfRqst_nu (FCT_CMP_TRJCTR_540)
 *		-# [Testcase_Degradation](@ref TCTCLM_Testcase_Degradation) Test conditions for degradation (S_TCTCLM_QuServTrajCtr_nu = 1) and output Freeze (DOORS ID FCT_CMP_TRJCTR_544, FCT_CMP_TRJCTR_545)
 *		-# [Testcase_DegradationHoldMechanism](@ref TCTCLM_Testcase_DegradationHoldMechanism) Test conditions for degradation (S_TCTCLM_QuServTrajCtr_nu = 1) hold mechanism (DOORS ID FCT_CMP_TRJCTR_544)
 *		-# [Testcase_SteerToCrvConv](@ref TCTCLM_Testcase_SteerToCrvConv) D_TCTCLM_SumCtrlSignal_1pm
 *		-# [Testcase_Coverage](@ref TCTCLM_Testcase_Coverage) 
 *		
 *	@traceability
 *		[\@link: TCTCLM Module Requirements]()
 */
extern void TCTCLM_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TCTCLM_H_
