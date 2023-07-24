/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : CTRSC
  MODULE        : CSCLTA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     CSCLTA.h
//! @brief     (CSCLTA) Module Header.

#ifndef CSCLTA_H_
#define CSCLTA_H_

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
 *	CSCLTA module sensor initialization function. Function initializes CSCLTA sensor output data pointer.
 *	
 *	@param
 *		[in] CSCLTA_SenOutArg Pointer to CSCLTA sensor output data.
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
extern void CSCLTA_SenInitOutPtr(CSCLTA_SenOutType *CSCLTA_SenOutArg);

/*!
 *	CSCLTA module sensor reset function.
 *	
 *	@pre
 *		- The CSCLTA sensor initialization function(s) must be called once.
 *		- The CSCLTA sensor debug/output data pointer(s) should not be NULL.
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
 *		[Output Signal] [S_CSCLTA_DeratingLevel_nu](@ref CSCLTA_SenOutType::S_CSCLTA_DeratingLevel_nu) \n
 *		[Output Signal] [S_CSCLTA_DistYTolLeTgtArea_met](@ref CSCLTA_SenOutType::S_CSCLTA_DistYTolLeTgtArea_met) \n
 *		[Output Signal] [S_CSCLTA_DistYTolRiTgtArea_met](@ref CSCLTA_SenOutType::S_CSCLTA_DistYTolRiTgtArea_met) \n
 *		[Output Signal] [S_CSCLTA_FTireAclMax_mps2](@ref CSCLTA_SenOutType::S_CSCLTA_FTireAclMax_mps2) \n
 *		[Output Signal] [S_CSCLTA_FTireAclMin_mps2](@ref CSCLTA_SenOutType::S_CSCLTA_FTireAclMin_mps2) \n
 *		[Output Signal] [S_CSCLTA_GrdLimitTgtCrvTGC_1pms](@ref CSCLTA_SenOutType::S_CSCLTA_GrdLimitTgtCrvTGC_1pms) \n
 *		[Output Signal] [S_CSCLTA_HighStatAccu_bool](@ref CSCLTA_SenOutType::S_CSCLTA_HighStatAccu_bool) \n
 *		[Output Signal] [S_CSCLTA_LatencyCompActivated_nu](@ref CSCLTA_SenOutType::S_CSCLTA_LatencyCompActivated_nu) \n
 *		[Output Signal] [S_CSCLTA_LeCridrBndCrvChng_1pm2](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndCrvChng_1pm2) \n
 *		[Output Signal] [S_CSCLTA_LeCridrBndCrv_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndCrv_1pm) \n
 *		[Output Signal] [S_CSCLTA_LeCridrBndHeadAng_rad](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndHeadAng_rad) \n
 *		[Output Signal] [S_CSCLTA_LeCridrBndLength_met](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndLength_met) \n
 *		[Output Signal] [S_CSCLTA_LeCridrBndPosX0_met](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndPosX0_met) \n
 *		[Output Signal] [S_CSCLTA_LeCridrBndPosY0_met](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndPosY0_met) \n
 *		[Output Signal] [S_CSCLTA_LimiterActivated_nu](@ref CSCLTA_SenOutType::S_CSCLTA_LimiterActivated_nu) \n
 *		[Output Signal] [S_CSCLTA_LimiterTimeDuration_sec](@ref CSCLTA_SenOutType::S_CSCLTA_LimiterTimeDuration_sec) \n
 *		[Output Signal] [S_CSCLTA_MaxCrvGrdBuildup_1pms](@ref CSCLTA_SenOutType::S_CSCLTA_MaxCrvGrdBuildup_1pms) \n
 *		[Output Signal] [S_CSCLTA_MaxCrvGrdRed_1pms](@ref CSCLTA_SenOutType::S_CSCLTA_MaxCrvGrdRed_1pms) \n
 *		[Output Signal] [S_CSCLTA_MaxCrvTrajGuiCtrl_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_MaxCrvTrajGuiCtrl_1pm) \n
 *		[Output Signal] [S_CSCLTA_MaxJerkAllowed_mps3](@ref CSCLTA_SenOutType::S_CSCLTA_MaxJerkAllowed_mps3) \n
 *		[Output Signal] [S_CSCLTA_MaxTrqScalGrad_1ps](@ref CSCLTA_SenOutType::S_CSCLTA_MaxTrqScalGrad_1ps) \n
 *		[Output Signal] [S_CSCLTA_MaxTrqScalLimit_nu](@ref CSCLTA_SenOutType::S_CSCLTA_MaxTrqScalLimit_nu) \n
 *		[Output Signal] [S_CSCLTA_ObstacleAclX_mps2](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleAclX_mps2) \n
 *		[Output Signal] [S_CSCLTA_ObstacleDistX_met](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleDistX_met) \n
 *		[Output Signal] [S_CSCLTA_ObstacleDistY_met](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleDistY_met) \n
 *		[Output Signal] [S_CSCLTA_ObstacleVelX_mps](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleVelX_mps) \n
 *		[Output Signal] [S_CSCLTA_ObstacleWidth_met](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleWidth_met) \n
 *		[Output Signal] [S_CSCLTA_PlanningHorizon_sec](@ref CSCLTA_SenOutType::S_CSCLTA_PlanningHorizon_sec) \n
 *		[Output Signal] [S_CSCLTA_PredTimeHeadAng_sec](@ref CSCLTA_SenOutType::S_CSCLTA_PredTimeHeadAng_sec) \n
 *		[Output Signal] [S_CSCLTA_PredictionTimeCrv_sec](@ref CSCLTA_SenOutType::S_CSCLTA_PredictionTimeCrv_sec) \n
 *		[Output Signal] [S_CSCLTA_RiCridrBndCrvChng_1pm2](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndCrvChng_1pm2) \n
 *		[Output Signal] [S_CSCLTA_RiCridrBndCrv_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndCrv_1pm) \n
 *		[Output Signal] [S_CSCLTA_RiCridrBndHeadAng_rad](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndHeadAng_rad) \n
 *		[Output Signal] [S_CSCLTA_RiCridrBndLength_met](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndLength_met) \n
 *		[Output Signal] [S_CSCLTA_RiCridrBndPosX0_met](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndPosX0_met) \n
 *		[Output Signal] [S_CSCLTA_RiCridrBndPosY0_met](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndPosY0_met) \n
 *		[Output Signal] [S_CSCLTA_SensorTStamp_sec](@ref CSCLTA_SenOutType::S_CSCLTA_SensorTStamp_sec) \n
 *		[Output Signal] [S_CSCLTA_StrWhStifGrad_1ps](@ref CSCLTA_SenOutType::S_CSCLTA_StrWhStifGrad_1ps) \n
 *		[Output Signal] [S_CSCLTA_StrWhStifLimit_nu](@ref CSCLTA_SenOutType::S_CSCLTA_StrWhStifLimit_nu) \n
 *		[Output Signal] [S_CSCLTA_SysStateLCF_enum](@ref CSCLTA_SenOutType::S_CSCLTA_SysStateLCF_enum) \n
 *		[Output Signal] [S_CSCLTA_TgtTrajCrvChng_1pm2](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajCrvChng_1pm2) \n
 *		[Output Signal] [S_CSCLTA_TgtTrajCrv_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajCrv_1pm) \n
 *		[Output Signal] [S_CSCLTA_TgtTrajHeadAng_rad](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajHeadAng_rad) \n
 *		[Output Signal] [S_CSCLTA_TgtTrajLength_met](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajLength_met) \n
 *		[Output Signal] [S_CSCLTA_TgtTrajPosX0_met](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajPosX0_met) \n
 *		[Output Signal] [S_CSCLTA_TgtTrajPosY0_met](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajPosY0_met) \n
 *		[Output Signal] [S_CSCLTA_TrajGuiQualifier_nu](@ref CSCLTA_SenOutType::S_CSCLTA_TrajGuiQualifier_nu) \n
 *		[Output Signal] [S_CSCLTA_TrajPlanServQu_nu](@ref CSCLTA_SenOutType::S_CSCLTA_TrajPlanServQu_nu) \n
 *		[Output Signal] [S_CSCLTA_TriggerReplan_nu](@ref CSCLTA_SenOutType::S_CSCLTA_TriggerReplan_nu) \n
 *		[Output Signal] [S_CSCLTA_TrqRampGrad_1ps](@ref CSCLTA_SenOutType::S_CSCLTA_TrqRampGrad_1ps) \n
 *		[Output Signal] [S_CSCLTA_WeightEndTime_nu](@ref CSCLTA_SenOutType::S_CSCLTA_WeightEndTime_nu) \n
 *		[Output Signal] [S_CSCLTA_WeightTgtDistY_nu](@ref CSCLTA_SenOutType::S_CSCLTA_WeightTgtDistY_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref CSCLTA_SenProcess_Globals) of the function @ref CSCLTA_SenProcess.
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
extern void CSCLTA_SenReset(void);

/*!
 *	CSCLTA module sensor process function.
 *	
 *	@pre
 *		- The CSCLTA sensor initialization function(s) must be called once.
 *		- The CSCLTA sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor CSCLTA_SenProcess_Globals
 *		[S_CSCLTA_DeratingLevel_nu](@ref CSCLTA_SenOutType::S_CSCLTA_DeratingLevel_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LCF \n\n
 *		[S_CSCLTA_DistYTolLeTgtArea_met](@ref CSCLTA_SenOutType::S_CSCLTA_DistYTolLeTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_DistYTolRiTgtArea_met](@ref CSCLTA_SenOutType::S_CSCLTA_DistYTolRiTgtArea_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_FTireAclMax_mps2](@ref CSCLTA_SenOutType::S_CSCLTA_FTireAclMax_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_FTireAclMin_mps2](@ref CSCLTA_SenOutType::S_CSCLTA_FTireAclMin_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_GrdLimitTgtCrvTGC_1pms](@ref CSCLTA_SenOutType::S_CSCLTA_GrdLimitTgtCrvTGC_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m2_2_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -2 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_HighStatAccu_bool](@ref CSCLTA_SenOutType::S_CSCLTA_HighStatAccu_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		[S_CSCLTA_LatencyCompActivated_nu](@ref CSCLTA_SenOutType::S_CSCLTA_LatencyCompActivated_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LeCridrBndCrvChng_1pm2](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LeCridrBndCrv_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LeCridrBndHeadAng_rad](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LeCridrBndLength_met](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LeCridrBndPosX0_met](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LeCridrBndPosY0_met](@ref CSCLTA_SenOutType::S_CSCLTA_LeCridrBndPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LimiterActivated_nu](@ref CSCLTA_SenOutType::S_CSCLTA_LimiterActivated_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_LimiterTimeDuration_sec](@ref CSCLTA_SenOutType::S_CSCLTA_LimiterTimeDuration_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_MaxCrvGrdBuildup_1pms](@ref CSCLTA_SenOutType::S_CSCLTA_MaxCrvGrdBuildup_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m2_2_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -2 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_MaxCrvGrdRed_1pms](@ref CSCLTA_SenOutType::S_CSCLTA_MaxCrvGrdRed_1pms) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pms_m2_2_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -2 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_MaxCrvTrajGuiCtrl_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_MaxCrvTrajGuiCtrl_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_MaxJerkAllowed_mps3](@ref CSCLTA_SenOutType::S_CSCLTA_MaxJerkAllowed_mps3) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		[S_CSCLTA_MaxTrqScalGrad_1ps](@ref CSCLTA_SenOutType::S_CSCLTA_MaxTrqScalGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		[S_CSCLTA_MaxTrqScalLimit_nu](@ref CSCLTA_SenOutType::S_CSCLTA_MaxTrqScalLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		[S_CSCLTA_ObstacleAclX_mps2](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleAclX_mps2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_ObstacleDistX_met](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleDistX_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_ObstacleDistY_met](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleDistY_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_ObstacleVelX_mps](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleVelX_mps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_ObstacleWidth_met](@ref CSCLTA_SenOutType::S_CSCLTA_ObstacleWidth_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_PlanningHorizon_sec](@ref CSCLTA_SenOutType::S_CSCLTA_PlanningHorizon_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_PredTimeHeadAng_sec](@ref CSCLTA_SenOutType::S_CSCLTA_PredTimeHeadAng_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_PredictionTimeCrv_sec](@ref CSCLTA_SenOutType::S_CSCLTA_PredictionTimeCrv_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_RiCridrBndCrvChng_1pm2](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_RiCridrBndCrv_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_RiCridrBndHeadAng_rad](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_RiCridrBndLength_met](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_RiCridrBndPosX0_met](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_RiCridrBndPosY0_met](@ref CSCLTA_SenOutType::S_CSCLTA_RiCridrBndPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_SensorTStamp_sec](@ref CSCLTA_SenOutType::S_CSCLTA_SensorTStamp_sec) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Timestamp of the corridor information signals \n\n
 *		[S_CSCLTA_StrWhStifGrad_1ps](@ref CSCLTA_SenOutType::S_CSCLTA_StrWhStifGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		[S_CSCLTA_StrWhStifLimit_nu](@ref CSCLTA_SenOutType::S_CSCLTA_StrWhStifLimit_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		[S_CSCLTA_SysStateLCF_enum](@ref CSCLTA_SenOutType::S_CSCLTA_SysStateLCF_enum) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TgtTrajCrvChng_1pm2](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajCrvChng_1pm2) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TgtTrajCrv_1pm](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TgtTrajHeadAng_rad](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajHeadAng_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TgtTrajLength_met](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajLength_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TgtTrajPosX0_met](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TgtTrajPosY0_met](@ref CSCLTA_SenOutType::S_CSCLTA_TgtTrajPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TrajGuiQualifier_nu](@ref CSCLTA_SenOutType::S_CSCLTA_TrajGuiQualifier_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		[S_CSCLTA_TrajPlanServQu_nu](@ref CSCLTA_SenOutType::S_CSCLTA_TrajPlanServQu_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TriggerReplan_nu](@ref CSCLTA_SenOutType::S_CSCLTA_TriggerReplan_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_TrqRampGrad_1ps](@ref CSCLTA_SenOutType::S_CSCLTA_TrqRampGrad_1ps) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		[S_CSCLTA_WeightEndTime_nu](@ref CSCLTA_SenOutType::S_CSCLTA_WeightEndTime_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		[S_CSCLTA_WeightTgtDistY_nu](@ref CSCLTA_SenOutType::S_CSCLTA_WeightTgtDistY_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_DPLSMI_SysStateLDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the LDP function. \n\n
 *		@ref S_DPLTTG_LeCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_LeCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_LeCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_LeCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_LeCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_LeCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_RiCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_RiCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_RiCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_RiCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_RiCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTTG_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_DeratingLevel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDP function \n\n
 *		@ref S_DPLTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_FTireAclMax_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_FTireAclMin_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_HighStatAccu_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		@ref S_DPLTVG_LimiterActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		@ref S_DPLTVG_LimiterTimeDuration_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_LtcyCompActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for the latency compensation in the TRJPLN. \n\n
 *		@ref S_DPLTVG_MaxCrvGrdBuildup_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_MaxCrvGrdRed_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_MaxCrvTrajGuiCtrl_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref S_DPLTVG_MaxTrqScalGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		@ref S_DPLTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		@ref S_DPLTVG_ObstacleAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_ObstacleDistX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_ObstacleDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_ObstacleVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_ObstacleWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_PlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_PredTimeCrv_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_PredTimeHeadAng_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_SensorTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		@ref S_DPLTVG_StrWhStifGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		@ref S_DPLTVG_StrWhStifLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		@ref S_DPLTVG_TrajGuiQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		@ref S_DPLTVG_TrajPlanServQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_TriggerReplan_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		It has to be 1 for TRJPLN to calculate a trajectory. \n\n
 *		@ref S_DPLTVG_TrqRampGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		@ref S_DPLTVG_WeightEndTime_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPLTVG_WeightTgtDistY_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOSTM_SysStateLDPOC_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of LDPOC \n
 *		Enum: \n
 *		E_LCF_SYSSTATE_NOTPRESENT = 0; \n
 *		E_LCF_SYSSTATE_DISABLED = 1; \n
 *		E_LCF_SYSSTATE_PASSIVE = 2; \n
 *		E_LCF_SYSSTATE_REQUEST = 3; \n
 *		E_LCF_SYSSTATE_CONTROLLING = 4; \n
 *		E_LCF_SYSSTATE_RAMPOUT = 5; \n
 *		E_LCF_SYSSTATE_ERROR = 6; \n\n
 *		@ref S_DPOTTG_LeCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_LeCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_LeCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_LeCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_LeCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_LeCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_RiCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_RiCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_RiCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_RiCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_RiCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_TgtTrajCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_TgtTrajHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_TgtTrajLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTTG_TgtTrajPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Longitudinal distance to Target Clothoid \n\n
 *		@ref S_DPOTTG_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Lateral distance to Target Clothoid \n\n
 *		@ref S_DPOTVG_DeratingLevel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the LDPOC function \n\n
 *		@ref S_DPOTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_FTireAclMax_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_FTireAclMin_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_HighStatAccu_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		@ref S_DPOTVG_LimiterActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver \n\n
 *		@ref S_DPOTVG_LimiterTimeDuration_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_LtcyCompActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for the latency compensation in the TRJPLN \n\n
 *		@ref S_DPOTVG_MaxCrvGrdBuildup_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_MaxCrvGrdRed_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_MaxCrvTrajGuiCtrl_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref S_DPOTVG_MaxTrqScalGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		@ref S_DPOTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		@ref S_DPOTVG_ObstacleAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_ObstacleDistX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_ObstacleDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_ObstacleVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_ObstacleWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_PlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_PredTimeCrv_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_PredTimeHeadAng_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_SensorTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		@ref S_DPOTVG_StrWhStifGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		@ref S_DPOTVG_StrWhStifLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		@ref S_DPOTVG_TrajGuiQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		 \n\n
 *		@ref S_DPOTVG_TrajPlanServQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_TriggerReplan_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		It has to be 1 for TRJPLN to calculate a trajectory \n\n
 *		@ref S_DPOTVG_TrqRampGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		@ref S_DPOTVG_WeightEndTime_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPOTVG_WeightTgtDistY_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRSMI_SysStateRDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the RDP function. \n\n
 *		@ref S_DPRTTG_LeCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_LeCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_LeCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_LeCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_LeCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_LeCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_DeratingLevel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the RDP function \n\n
 *		@ref S_DPRTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_FTireAclMax_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_FTireAclMin_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_HighStatAccu_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		@ref S_DPRTVG_LimiterActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to limit the target curvature in the TRJCTR, in case it points to the opposite direction of the intentional lateral maneuver. \n\n
 *		@ref S_DPRTVG_LimiterTimeDuration_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_LtcyCompActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for the latency compensation in the TRJPLN. \n\n
 *		@ref S_DPRTVG_MaxCrvGrdBuildup_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_MaxCrvGrdRed_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_MaxCrvTrajGuiCtrl_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref S_DPRTVG_MaxTrqScalGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		@ref S_DPRTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		@ref S_DPRTVG_ObstacleAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_ObstacleDistX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_ObstacleDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_ObstacleVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_ObstacleWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_PlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_PredTimeCrv_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_PredTimeHeadAng_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_SensorTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		@ref S_DPRTVG_StrWhStifGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		@ref S_DPRTVG_StrWhStifLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		@ref S_DPRTVG_TrajGuiQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		@ref S_DPRTVG_TrajPlanServQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_TriggerReplan_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		It has to be 1 for TRJPLN to calculate a trajectory. \n\n
 *		@ref S_DPRTVG_TrqRampGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		@ref S_DPRTVG_WeightEndTime_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTVG_WeightTgtDistY_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
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
 *		@ref S_LCRTTG_LeCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_LeCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_LeCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_LeCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_LeCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_LeCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_RiCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_RiCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_RiCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_RiCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_RiCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_TgtTrajCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
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
 *		@ref S_LCRTTG_TgtTrajHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_TgtTrajLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTTG_TgtTrajPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
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
 *		@ref S_LCRTVG_DeratingLevel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the ALCA function \n\n
 *		@ref S_LCRTVG_DistYTolLeTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_DistYTolRiTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_FTireAclMax_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_FTireAclMin_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_HighStatAccu_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		@ref S_LCRTVG_LimiterActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_LimiterTimeDuration_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_LtcyCompActivated_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_MaxCrvGrdBuildup_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_MaxCrvGrdRed_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_MaxCrvTrajGuiCtrl_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref S_LCRTVG_MaxTrqScalGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		@ref S_LCRTVG_MaxTrqScalLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		@ref S_LCRTVG_ObstacleAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_ObstacleDistX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_ObstacleDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_ObstacleVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_ObstacleWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_PlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_PredTimeCrv_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_PredTimeHeadAng_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_SensorTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n\n
 *		@ref S_LCRTVG_StrWhStifGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		@ref S_LCRTVG_StrWhStifLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		@ref S_LCRTVG_TrajGuiQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		@ref S_LCRTVG_TrajPlanServQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_TriggerReplan_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_TrqRampGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		@ref S_LCRTVG_WeightEndTime_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCRTVG_WeightTgtDistY_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_MCTLFC_ControllingFunction_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_FunctionV3Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 7 \n
 *		\@description: \n
 *		Carries which function is allowed to control. \n\n
 *		@ref S_TJASTM_SysStateTJA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TJATTG_LeCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_LeCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_LeCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_LeCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_LeCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_LeCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_RiCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_RiCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_RiCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_RiCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_RiCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TgtTrajCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TgtTrajHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TgtTrajLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TgtTrajPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATTG_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATTG_OUTPUT \n\n
 *		@ref S_TJATVG_DeratingLevel_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		DMC Derating Level of the TJA function \n\n
 *		@ref S_TJATVG_DistYTolLeTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_DistYTolRiTgtArea_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_FTireAclMax_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_FTireAclMin_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_GrdLimitTgtCrvTGC_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_HighStatAccu_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		High Stationary Accuracy required \n\n
 *		@ref S_TJATVG_LimiterActivated_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_LimiterTimeDuration_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_LtcyCompActivated_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_MaxCrvGrdBuildup_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_MaxCrvGrdRed_1pms \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pms_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_MaxCrvTrajGuiCtrl_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_MaxJerkAllowed_mps3 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps3_0_50_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^3 \n
 *		\@min: 0 \n
 *		\@max: 50 \n
 *		\@description: \n
 *		Maximum Jerk Allowed in the trajectory planning \n\n
 *		@ref S_TJATVG_MaxTrqScalGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Maximum Torque Scaling Gradient \n\n
 *		@ref S_TJATVG_MaxTrqScalLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum Torque Scaling Limiter (Torque saturation) \n\n
 *		@ref S_TJATVG_ObstacleAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_ObstacleDistX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_ObstacleDistY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_ObstacleVelX_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_ObstacleWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_PlanningHorizon_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_PredTimeCrv_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_PredTimeHeadAng_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_SensorTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Sensor time stamp in seconds \n
 *		OF: radar time stamp \n
 *		ELSE: camera time stamp \n\n
 *		@ref S_TJATVG_StrWhStifGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Gradient \n\n
 *		@ref S_TJATVG_StrWhStifLimit_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Steering Wheel Stiffness Limiter \n\n
 *		@ref S_TJATVG_TrajGuiQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_TGQ_Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Trajectory Guidance Qualifier Output \n\n
 *		@ref S_TJATVG_TrajPlanServQu_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_TriggerReplan_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_TrqRampGrad_1ps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Torque Ramp Gradient \n\n
 *		@ref S_TJATVG_WeightEndTime_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		@ref S_TJATVG_WeightTgtDistY_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJATVG_OUTPUT \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: CSCLTA Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref CSCLTA_Testcase_Initialization) Initialization of the CSCLTA
 *		-# [Testcase_AllFunctions](@ref CSCLTA_Testcase_AllFunctions) LCF Values
 *		
 *	@traceability
 *		[\@link: CSCLTA Module Requirements]()
 */
extern void CSCLTA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // CSCLTA_H_
