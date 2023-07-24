/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLCEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLCEN.h
//! @brief     (TPLCEN) Module Header.

#ifndef TPLCEN_H_
#define TPLCEN_H_

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
 *	TPLCEN module vehicle initialization function. Function initializes TPLCEN vehicle debug data pointer.
 *	
 *	@param
 *		[in] TPLCEN_VehDbgArg Pointer to TPLCEN vehicle debug data.
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
extern void TPLCEN_VehInitDbgPtr(TPLCEN_VehDbgType *TPLCEN_VehDbgArg);

/*!
 *	TPLCEN module vehicle initialization function. Function initializes TPLCEN vehicle output data pointer.
 *	
 *	@param
 *		[in] TPLCEN_VehOutArg Pointer to TPLCEN vehicle output data.
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
extern void TPLCEN_VehInitOutPtr(TPLCEN_VehOutType *TPLCEN_VehOutArg);

/*!
 *	TPLCEN module vehicle reset function.
 *	
 *	@pre
 *		- The TPLCEN vehicle initialization function(s) must be called once.
 *		- The TPLCEN vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TPLCEN_CorridorJumpDetected_nu](@ref TPLCEN_VehDbgType::D_TPLCEN_CorridorJumpDetected_nu) \n
 *		[Debug  Signal] [D_TPLCEN_LatDMCReqFinished_nu](@ref TPLCEN_VehDbgType::D_TPLCEN_LatDMCReqFinished_nu) \n
 *		[Debug  Signal] [D_TPLCEN_TrigLargeDeviation_nu](@ref TPLCEN_VehDbgType::D_TPLCEN_TrigLargeDeviation_nu) \n
 *		[Debug  Signal] [S_TPLCEN_DelayVehGui_sec](@ref TPLCEN_VehDbgType::S_TPLCEN_DelayVehGui_sec) \n
 *		[Debug  Signal] [S_TPLCEN_EnblSpecPlanStrategy_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_EnblSpecPlanStrategy_nu) \n
 *		[Debug  Signal] [S_TPLCEN_PredictionTimeCrv_sec](@ref TPLCEN_VehDbgType::S_TPLCEN_PredictionTimeCrv_sec) \n
 *		[Debug  Signal] [S_TPLCEN_PredictionTimeHead_sec](@ref TPLCEN_VehDbgType::S_TPLCEN_PredictionTimeHead_sec) \n
 *		[Debug  Signal] [S_TPLCEN_ReplanCurValues_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_ReplanCurValues_nu) \n
 *		[Debug  Signal] [S_TPLCEN_ReplanModeArcLength_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_ReplanModeArcLength_nu) \n
 *		[Debug  Signal] [S_TPLCEN_ReplanTgtValues_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_ReplanTgtValues_nu) \n
 *		[Debug  Signal] [S_TPLCEN_TrajGuiQuChange_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrajGuiQuChange_nu) \n
 *		[Debug  Signal] [S_TPLCEN_TrajPlanEnbl_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrajPlanEnbl_nu) \n
 *		[Debug  Signal] [S_TPLCEN_TrigCustFctActn_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrigCustFctActn_nu) \n
 *		[Debug  Signal] [S_TPLCEN_TrigReplanTgtTraj_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrigReplanTgtTraj_nu) \n
 *		[Debug  Signal] [S_TPLCEN_TrigTrajReplan_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrigTrajReplan_nu) \n
 *		[Output Signal] [D_TPLCEN_TrigCustFctChange_nu](@ref TPLCEN_VehOutType::D_TPLCEN_TrigCustFctChange_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref TPLCEN_VehProcess_Globals) of the function @ref TPLCEN_VehProcess.
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
extern void TPLCEN_VehReset(void);

/*!
 *	TPLCEN module vehicle process function.
 *	
 *	@pre
 *		- The TPLCEN vehicle initialization function(s) must be called once.
 *		- The TPLCEN vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TPLCEN_VehProcess_Globals
 *		[D_TPLCEN_CorridorJumpDetected_nu](@ref TPLCEN_VehDbgType::D_TPLCEN_CorridorJumpDetected_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Boolean indicates if there is jump in corridor info. \n\n
 *		[D_TPLCEN_LatDMCReqFinished_nu](@ref TPLCEN_VehDbgType::D_TPLCEN_LatDMCReqFinished_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates if DMC and EPS handshake is finished \n\n
 *		[D_TPLCEN_TrigLargeDeviation_nu](@ref TPLCEN_VehDbgType::D_TPLCEN_TrigLargeDeviation_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Trigger indicates if the deviation is too large \n\n
 *		[S_TPLCEN_DelayVehGui_sec](@ref TPLCEN_VehDbgType::S_TPLCEN_DelayVehGui_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_EnblSpecPlanStrategy_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_EnblSpecPlanStrategy_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_PredictionTimeCrv_sec](@ref TPLCEN_VehDbgType::S_TPLCEN_PredictionTimeCrv_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Prediction time of the curvature, saterated, ramped up \n\n
 *		[S_TPLCEN_PredictionTimeHead_sec](@ref TPLCEN_VehDbgType::S_TPLCEN_PredictionTimeHead_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Prediction time of the heading, saturated, ramped up \n\n
 *		[S_TPLCEN_ReplanCurValues_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_ReplanCurValues_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_ReplanModeArcLength_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_ReplanModeArcLength_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_ReplanTgtValues_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_ReplanTgtValues_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_TrajGuiQuChange_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrajGuiQuChange_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Signal indicates the trajectory guidance qualifier change \n\n
 *		[S_TPLCEN_TrajPlanEnbl_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrajPlanEnbl_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_TrigCustFctActn_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrigCustFctActn_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_TrigReplanTgtTraj_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrigReplanTgtTraj_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_TPLCEN_TrigTrajReplan_nu](@ref TPLCEN_VehDbgType::S_TPLCEN_TrigTrajReplan_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_TPLCEN_TrigCustFctChange_nu](@ref TPLCEN_VehOutType::D_TPLCEN_TrigCustFctChange_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_CSCLTA_PredTimeHeadAng_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_PredictionTimeCrv_sec \n
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
 *		@ref S_CSCLTA_TrajGuiQualifier_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		@ref S_CSCLTA_TriggerReplan_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_LCFRCV_EPS_ManualTrqActualVal_Nm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Nm_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Rename of S_RTE_EPS_ManualTrqActualVal_Nm \n\n
 *		@ref S_LCFRCV_SysCycleTimeVeh_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p03_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.03 \n
 *		\@description: \n
 *		Cycle Time for VEH task \n\n
 *		@ref S_LCFRCV_SysStOffLatDMC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if DMC_LAT_STATUS = 0 (LCF_LADMC_OFF) \n\n
 *		@ref S_LCFRCV_SysStReqLatDMC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if DMC_LAT_STATUS = 6 (LCF_LADMC_REQ) \n\n
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
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TPLFBT_CtrlErrDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLFBT_CtrlErrHeadAglPrev_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_TPLLCO_DevDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		vehicle ego lateral distance in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_DevHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		vehicle heading angle in right corridor coordinate system \n\n
 *		@ref S_TPLLCO_TargetPathHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		heading angle of the target path (target corridor with X0 = 0) \n\n
 *		@ref S_TPLLCO_TargetPathY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		lateral position of the target path (target corridor with X0 = 0) \n\n
 *		@ref S_TPLLCO_TriggerReplan_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		trigger for replanning \n\n
 *		@ref S_TPLTJC_TrajEnd_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_ActivebyRampout_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_AllowReplanOBF_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		allow replanning by OBF mode switch \n\n
 *		@ref P_TPLCEN_AllowSpePlanStrategy_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Allow the special plan strategy for TJA function (by pass with the checks) \n\n
 *		@ref P_TPLCEN_CyCTimeTrajCalc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p1_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.1 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_CycEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_DTGradLimitDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Duration of the gradient limitation for dead time change. \n\n
 *		@ref P_TPLCEN_EnableFcnChngDetect_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable the function change detection by jump detection for triggering the reinitialization \n\n
 *		@ref P_TPLCEN_EnableJumpDetectOBF_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable jump detection for replan by OBF \n\n
 *		@ref P_TPLCEN_EnableJumpDetectOFRQ_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable the jump detection for reinitialization by OBF request \n\n
 *		@ref P_TPLCEN_ErrDistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_ErrHeadAglPrev_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m6_6_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -6 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_LCOReplanEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable replan triggered by LCO \n\n
 *		@ref P_TPLCEN_ManualTrqMaxTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time buffer to make sure if the manual torque is smaller than the threshold \n\n
 *		@ref P_TPLCEN_ManualTrqMax_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Threshold to detect if the manaul torque is small enough \n\n
 *		@ref P_TPLCEN_ManualTrqMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time buffer to make sure if the manual torque is larger than the threshold and have been hold \n\n
 *		@ref P_TPLCEN_ManualTrqMin_Nm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Nm_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: Nm \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Threshold to detect if the manaul torque is big enough \n\n
 *		@ref P_TPLCEN_MaxPredictionTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Limitation of prediction time on curvature and heading \n\n
 *		@ref P_TPLCEN_PTCrvGradLimitDur_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Duration of the gradient limitation for prediction time curvature change. \n\n
 *		@ref P_TPLCEN_PTHeadGradLimitDur_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Duration of the gradient limitation for prediction time heading change. \n\n
 *		@ref P_TPLCEN_ReIniDeltaDistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Threshold for reinitialization w.r.t the lateral deviation. \n\n
 *		@ref P_TPLCEN_ReIniDeltaHead_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Threshold for reinitialization w.r.t the heading. \n\n
 *		@ref P_TPLCEN_ReIniWrtDMCReq_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Reinitialization w.r.t DMC status (req finisched) \n\n
 *		@ref P_TPLCEN_ReplanLargeErrorMode_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask to choose the trigger condition for reinitialization the trajectory by large deviation. \n
 *		Bit0: Edge rising by large PosY and Heading Deviations and small driver torque \n
 *		Bit1: Edge rising by large PosY and Heading Deviations \n
 *		Bit2: Large PosY and Heading Deviations and large driver torque \n
 *		Bit3: Edge rising by Large PosY and Heading Deviations and large driver torque \n\n
 *		@ref P_TPLCEN_ReplanbyTJA2X_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable reinitialization when the controlling function changes from TJA to other functions. \n\n
 *		@ref P_TPLCEN_TrajPlanEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLCEN_UseJumpDetectOBFTrig_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable jump detection by function change to TJA OBF mode \n\n
 *		@ref P_TPLCEN_UseJumpDetection_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to activate the jump detection, by off function change detection will be active. \n\n
 *		@ref P_TPLCEN_VMinTimeBasedTraj_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_TPLCEN_PotVecDynVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TPLCEN_DeadTimeVehCtrl_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x7x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		 \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TPLCEN Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TPLCEN_Testcase_Initialization) Initialization of the TPLCEN
 *		-# [Testcase_S_TPLCEN_TrajPlanEnbl_nu](@ref TPLCEN_Testcase_S_TPLCEN_TrajPlanEnbl_nu) Doors ID FCT_CMP_TRJPLN_241
 *		-# [Testcase_S_TPLCEN_EnblSpecPlanStrategy_nu](@ref TPLCEN_Testcase_S_TPLCEN_EnblSpecPlanStrategy_nu) S_TPLCEN_EnblSpecPlanStrategy_nu
 *		-# [Testcase_D_TPLCEN_TrigLargeDeviation_nu](@ref TPLCEN_Testcase_D_TPLCEN_TrigLargeDeviation_nu) Doors ID FCT_CMP_TRJPLN_305
 *		-# [Testcase_S_TPLCEN_TrajGuiQuChange_nu](@ref TPLCEN_Testcase_S_TPLCEN_TrajGuiQuChange_nu) Doors ID FCT_CMP_TRJPLN_287
 *		-# [Testcase_D_TPLCEN_TrigCustFctChange_nu](@ref TPLCEN_Testcase_D_TPLCEN_TrigCustFctChange_nu) D_TPLCEN_TrigCustFctChange_nu
 *		-# [Testcase_D_TPLCEN_CorridorJumpDetected_nu](@ref TPLCEN_Testcase_D_TPLCEN_CorridorJumpDetected_nu) D_TPLCEN_CorridorJumpDetected_nu
 *		-# [Testcase_D_TPLCEN_LatDMCReqFinished_nu](@ref TPLCEN_Testcase_D_TPLCEN_LatDMCReqFinished_nu) D_TPLCEN_LatDMCReqFinished_nu
 *		-# [Testcase_S_TPLCEN_TrigCustFctActn_nu](@ref TPLCEN_Testcase_S_TPLCEN_TrigCustFctActn_nu) S_TPLCEN_TrigCustFctActn_nu
 *		-# [Testcase_S_TPLCEN_ReplanModeArcLength_nu](@ref TPLCEN_Testcase_S_TPLCEN_ReplanModeArcLength_nu) Doors ID FCT_CMP_TRJPLN_268
 *		-# [Testcase_S_TPLCEN_ReplanTgtValues_nu](@ref TPLCEN_Testcase_S_TPLCEN_ReplanTgtValues_nu) S_TPLCEN_ReplanTgtValues_nu
 *		-# [Testcase_S_TPLCEN_ReplanCurValues_nu](@ref TPLCEN_Testcase_S_TPLCEN_ReplanCurValues_nu) Doors ID FCT_CMP_TRJPLN_289
 *		-# [Testcase_S_TPLCEN_TrigReplanTgtTraj_nu](@ref TPLCEN_Testcase_S_TPLCEN_TrigReplanTgtTraj_nu) S_TPLCEN_TrigReplanTgtTraj_nu
 *		-# [Testcase_S_TPLCEN_TrigPlwTgtCrvDrvVeh_nu](@ref TPLCEN_Testcase_S_TPLCEN_TrigPlwTgtCrvDrvVeh_nu) S_TPLCEN_TrigPlwTgtCrvDrvVeh_nu
 *		-# [Testcase_S_TPLCEN_DelayVehGui_sec](@ref TPLCEN_Testcase_S_TPLCEN_DelayVehGui_sec) S_TPLCEN_DelayVehGui_sec
 *		-# [Testcase_S_TPLCEN_TrigTrajReplan_nu](@ref TPLCEN_Testcase_S_TPLCEN_TrigTrajReplan_nu) S_TPLCEN_TrigTrajReplan_nu
 *		-# [Testcase_S_TPLCEN_PredictionTimeCrv_sec](@ref TPLCEN_Testcase_S_TPLCEN_PredictionTimeCrv_sec) Doors ID FCT_CMP_TRJPLN_306
 *		-# [Testcase_S_TPLCEN_PredictionTimeHead_sec](@ref TPLCEN_Testcase_S_TPLCEN_PredictionTimeHead_sec) Doors ID FCT_CMP_TRJPLN_307
 *		
 *	@traceability
 *		[\@link: TPLCEN Module Requirements]()
 */
extern void TPLCEN_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TPLCEN_H_
