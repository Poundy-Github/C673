/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTVG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRTVG.h
//! @brief     (LCRTVG) Module Header.

#ifndef LCRTVG_H_
#define LCRTVG_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCRTVG module sensor initialization function. Function initializes LCRTVG sensor debug data pointer.
 *	
 *	@param
 *		[in] LCRTVG_SenDbgArg Pointer to LCRTVG sensor debug data.
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
extern void LCRTVG_SenInitDbgPtr(LCRTVG_SenDbgType *LCRTVG_SenDbgArg);

/*!
 *	LCRTVG module sensor initialization function. Function initializes LCRTVG sensor output data pointer.
 *	
 *	@param
 *		[in] LCRTVG_SenOutArg Pointer to LCRTVG sensor output data.
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
extern void LCRTVG_SenInitOutPtr(LCRTVG_SenOutType *LCRTVG_SenOutArg);

/*!
 *	LCRTVG module sensor reset function.
 *	
 *	@pre
 *		- The LCRTVG sensor initialization function(s) must be called once.
 *		- The LCRTVG sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_LCRTVG_DistYTolLeTgtArea_met](@ref LCRTVG_SenDbgType::S_LCRTVG_DistYTolLeTgtArea_met) \n
 *		[Debug  Signal] [S_LCRTVG_DistYTolRiTgtArea_met](@ref LCRTVG_SenDbgType::S_LCRTVG_DistYTolRiTgtArea_met) \n
 *		[Debug  Signal] [S_LCRTVG_FTireAclMax_mps2](@ref LCRTVG_SenDbgType::S_LCRTVG_FTireAclMax_mps2) \n
 *		[Debug  Signal] [S_LCRTVG_FTireAclMin_mps2](@ref LCRTVG_SenDbgType::S_LCRTVG_FTireAclMin_mps2) \n
 *		[Debug  Signal] [S_LCRTVG_GrdLimitTgtCrvTGC_1pms](@ref LCRTVG_SenDbgType::S_LCRTVG_GrdLimitTgtCrvTGC_1pms) \n
 *		[Debug  Signal] [S_LCRTVG_HighStatAccu_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_HighStatAccu_bool) \n
 *		[Debug  Signal] [S_LCRTVG_LimiterActivated_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_LimiterActivated_bool) \n
 *		[Debug  Signal] [S_LCRTVG_LimiterTimeDuration_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_LimiterTimeDuration_sec) \n
 *		[Debug  Signal] [S_LCRTVG_LtcyCompActivated_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_LtcyCompActivated_bool) \n
 *		[Debug  Signal] [S_LCRTVG_MaxCrvGrdBuildup_1pms](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxCrvGrdBuildup_1pms) \n
 *		[Debug  Signal] [S_LCRTVG_MaxCrvGrdRed_1pms](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxCrvGrdRed_1pms) \n
 *		[Debug  Signal] [S_LCRTVG_MaxCrvTrajGuiCtrl_1pm](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		[Debug  Signal] [S_LCRTVG_MaxTrqScalGrad_1ps](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxTrqScalGrad_1ps) \n
 *		[Debug  Signal] [S_LCRTVG_MaxTrqScalLimit_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxTrqScalLimit_nu) \n
 *		[Debug  Signal] [S_LCRTVG_ObstacleAclX_mps2](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleAclX_mps2) \n
 *		[Debug  Signal] [S_LCRTVG_ObstacleDistX_met](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleDistX_met) \n
 *		[Debug  Signal] [S_LCRTVG_ObstacleDistY_met](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleDistY_met) \n
 *		[Debug  Signal] [S_LCRTVG_ObstacleVelX_mps](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleVelX_mps) \n
 *		[Debug  Signal] [S_LCRTVG_ObstacleWidth_met](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleWidth_met) \n
 *		[Debug  Signal] [S_LCRTVG_PlanningHorizon_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_PlanningHorizon_sec) \n
 *		[Debug  Signal] [S_LCRTVG_PredTimeCrv_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_PredTimeCrv_sec) \n
 *		[Debug  Signal] [S_LCRTVG_PredTimeHeadAng_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_PredTimeHeadAng_sec) \n
 *		[Debug  Signal] [S_LCRTVG_StrWhStifGrad_1ps](@ref LCRTVG_SenDbgType::S_LCRTVG_StrWhStifGrad_1ps) \n
 *		[Debug  Signal] [S_LCRTVG_StrWhStifLimit_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_StrWhStifLimit_nu) \n
 *		[Debug  Signal] [S_LCRTVG_TrajGuiQu_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_TrajGuiQu_nu) \n
 *		[Debug  Signal] [S_LCRTVG_TrajPlanServQu_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_TrajPlanServQu_nu) \n
 *		[Debug  Signal] [S_LCRTVG_TriggerReplan_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_TriggerReplan_bool) \n
 *		[Debug  Signal] [S_LCRTVG_TrqRampGrad_1ps](@ref LCRTVG_SenDbgType::S_LCRTVG_TrqRampGrad_1ps) \n
 *		[Debug  Signal] [S_LCRTVG_WeightEndTime_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_WeightEndTime_nu) \n
 *		[Debug  Signal] [S_LCRTVG_WeightTgtDistY_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_WeightTgtDistY_nu) \n
 *		[Output Signal] [S_LCRTVG_DeratingLevel_nu](@ref LCRTVG_SenOutType::S_LCRTVG_DeratingLevel_nu) \n
 *		[Output Signal] [S_LCRTVG_MaxJerkAllowed_mps3](@ref LCRTVG_SenOutType::S_LCRTVG_MaxJerkAllowed_mps3) \n
 *		[Output Signal] [S_LCRTVG_SensorTStamp_sec](@ref LCRTVG_SenOutType::S_LCRTVG_SensorTStamp_sec) \n\n
 *		For signal details, see sub-section [Globals](@ref LCRTVG_SenProcess_Globals) of the function @ref LCRTVG_SenProcess.
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
extern void LCRTVG_SenReset(void);

/*!
 *	LCRTVG module sensor process function.
 *	
 *	@pre
 *		- The LCRTVG sensor initialization function(s) must be called once.
 *		- The LCRTVG sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor LCRTVG_SenProcess_Globals
 *		[S_LCRTVG_DistYTolLeTgtArea_met](@ref LCRTVG_SenDbgType::S_LCRTVG_DistYTolLeTgtArea_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_DistYTolRiTgtArea_met](@ref LCRTVG_SenDbgType::S_LCRTVG_DistYTolRiTgtArea_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_FTireAclMax_mps2](@ref LCRTVG_SenDbgType::S_LCRTVG_FTireAclMax_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_FTireAclMin_mps2](@ref LCRTVG_SenDbgType::S_LCRTVG_FTireAclMin_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_GrdLimitTgtCrvTGC_1pms](@ref LCRTVG_SenDbgType::S_LCRTVG_GrdLimitTgtCrvTGC_1pms) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_HighStatAccu_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_HighStatAccu_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		[S_LCRTVG_LimiterActivated_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_LimiterActivated_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_LimiterTimeDuration_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_LimiterTimeDuration_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_LtcyCompActivated_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_LtcyCompActivated_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_MaxCrvGrdBuildup_1pms](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxCrvGrdBuildup_1pms) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_MaxCrvGrdRed_1pms](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxCrvGrdRed_1pms) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_MaxCrvTrajGuiCtrl_1pm](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxCrvTrajGuiCtrl_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_MaxTrqScalGrad_1ps](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxTrqScalGrad_1ps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		[S_LCRTVG_MaxTrqScalLimit_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_MaxTrqScalLimit_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		[S_LCRTVG_ObstacleAclX_mps2](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleAclX_mps2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_ObstacleDistX_met](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleDistX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_ObstacleDistY_met](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_ObstacleVelX_mps](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleVelX_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_ObstacleWidth_met](@ref LCRTVG_SenDbgType::S_LCRTVG_ObstacleWidth_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_PlanningHorizon_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_PlanningHorizon_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_PredTimeCrv_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_PredTimeCrv_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_PredTimeHeadAng_sec](@ref LCRTVG_SenDbgType::S_LCRTVG_PredTimeHeadAng_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_StrWhStifGrad_1ps](@ref LCRTVG_SenDbgType::S_LCRTVG_StrWhStifGrad_1ps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		[S_LCRTVG_StrWhStifLimit_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_StrWhStifLimit_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		[S_LCRTVG_TrajGuiQu_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_TrajGuiQu_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		[S_LCRTVG_TrajPlanServQu_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_TrajPlanServQu_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_TriggerReplan_bool](@ref LCRTVG_SenDbgType::S_LCRTVG_TriggerReplan_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_TrqRampGrad_1ps](@ref LCRTVG_SenDbgType::S_LCRTVG_TrqRampGrad_1ps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		[S_LCRTVG_WeightEndTime_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_WeightEndTime_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_WeightTgtDistY_nu](@ref LCRTVG_SenDbgType::S_LCRTVG_WeightTgtDistY_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRTVG_DeratingLevel_nu](@ref LCRTVG_SenOutType::S_LCRTVG_DeratingLevel_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the ALCA function \n\n
 *		[S_LCRTVG_MaxJerkAllowed_mps3](@ref LCRTVG_SenOutType::S_LCRTVG_MaxJerkAllowed_mps3) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		[S_LCRTVG_SensorTStamp_sec](@ref LCRTVG_SenOutType::S_LCRTVG_SensorTStamp_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		@ref S_ABPLBP_ABDTimeStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		ABD data timestamp in seconds \n\n
 *		@ref S_LCFRCV_DrivingMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Driving Mode Selection Signal. It can be selected among driving modes such as Sport, Eco or Comfort. \n\n
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
 *		@ref S_LCRSIA_CurveTypeLe_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_LCRSIA_CurveTypeRi_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_LCRSIA_VelLatLeALCA_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the ALCA \n\n
 *		@ref S_LCRSIA_VelLatRiALCA_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the ALCA \n\n
 *		@ref S_LCRSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRSMI_FunctionAborted_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRSMI_SysStateALCA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_FTireAclMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_FTireAclMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_HighStatAccu_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_LimiterActivated_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_LimiterMaxCrvGrd_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_LimiterMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_LimiterTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_MaxTrqScalRampInGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_MaxTrqScalRampOutGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_PredTimeCrv_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_PredTimeHeadAng_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_StrWhStifAbortROGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_StrWhStifLimit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_StrWhStifRampOutGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_TrajPlanServQu_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_TriggerReplan_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_TrqAbortROGrd_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_TrqRampInGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Standard Ramp In Gradient \n\n
 *		@ref P_LCRTVG_TrqRampOutGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_UseLtcyComp_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRTVG_WeightTgtDistY_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_LCF_Curvature_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		X-axis for all the curvature dependant parameters. \n\n
 *		@ref X_LCF_DistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		X-axis for the Lateral Distance Dependant Look-Up Tables along LCF. \n\n
 *		@ref X_LCF_VelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_LCF_VelY_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_LCRTVG_CrvICPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an inner curve. \n\n
 *		@ref Y_LCRTVG_CrvOCPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Curvature dependant for an outer curve. \n\n
 *		@ref Y_LCRTVG_D2TPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. Distance to target dependant. \n\n
 *		@ref Y_LCRTVG_VXPlanHorizonScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Planning Horizon Scaling Factor for the calculation in the TRJPLN. VX dependant. \n\n
 *		@ref Y_LCRTVG_VXWeightEndtime_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Weight of the end time for the calculation in the TRJPLN. Speed dependant. \n\n
 *		@ref Y_LCRTVG_VYMD1DerLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function when Driving Mode is either equal to 1 or to a default value. Lateral Velocity dependant. \n\n
 *		@ref Y_LCRTVG_VYMD2DerLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function when Driving Mode is equal to 2. Lateral Velocity dependant. \n\n
 *		@ref Y_LCRTVG_VYMD3DerLevel_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function when Driving Mode is equal to 3. Lateral Velocity dependant. \n\n
 *		@ref Y_LCRTVG_VYPlanningHorizon_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Planning Horizon for the calculation in the TRJPLN. VY dependant. \n\n
 *		@ref Y_LCRTVG_VYStrWhStifRIGrad_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Standard Steering Wheel Stiffness Ramp In Gradient. VY dependant. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: LCRTVG Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref LCRTVG_Testcase_Initialization) Initialization of the LCRTVG
 *		-# [Testcase1](@ref LCRTVG_Testcase1) 
 *		-# [Testcase_new](@ref LCRTVG_Testcase_new) 
 *		-# [Testcase_Updated](@ref LCRTVG_Testcase_Updated) 
 *		-# [Testcase_Updated1_branch](@ref LCRTVG_Testcase_Updated1_branch) 
 *		
 *	@traceability
 *		[\@link: LCRTVG Module Requirements]()
 */
extern void LCRTVG_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // LCRTVG_H_
