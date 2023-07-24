/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPLBP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPLBP.h
//! @brief     (ABPLBP) Module Header.

#ifndef ABPLBP_H_
#define ABPLBP_H_

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
 *	ABPLBP module sensor initialization function. Function initializes ABPLBP sensor debug data pointer.
 *	
 *	@param
 *		[in] ABPLBP_SenDbgArg Pointer to ABPLBP sensor debug data.
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
extern void ABPLBP_SenInitDbgPtr(ABPLBP_SenDbgType *ABPLBP_SenDbgArg);

/*!
 *	ABPLBP module sensor initialization function. Function initializes ABPLBP sensor output data pointer.
 *	
 *	@param
 *		[in] ABPLBP_SenOutArg Pointer to ABPLBP sensor output data.
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
extern void ABPLBP_SenInitOutPtr(ABPLBP_SenOutType *ABPLBP_SenOutArg);

/*!
 *	ABPLBP module sensor reset function.
 *	
 *	@pre
 *		- The ABPLBP sensor initialization function(s) must be called once.
 *		- The ABPLBP sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_ABPLBP_ABDTimeStamp_sec](@ref ABPLBP_SenDbgType::S_ABPLBP_ABDTimeStamp_sec) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnClthCrvChng_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthCrvChng_1pm2) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnClthCrv_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthCrv_1pm) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnClthHeading_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthHeading_rad) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnClthLength_met](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthLength_met) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnClthPosY0_met](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthPosY0_met) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnKalmanQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnKalmanQual_perc) \n
 *		[Debug  Signal] [S_ABPLBP_CntrLnKalmanStatus_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnKalmanStatus_nu) \n
 *		[Debug  Signal] [S_ABPLBP_ConstructionSite_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_ConstructionSite_bool) \n
 *		[Debug  Signal] [S_ABPLBP_CoupledLaneWidth_met](@ref ABPLBP_SenDbgType::S_ABPLBP_CoupledLaneWidth_met) \n
 *		[Debug  Signal] [S_ABPLBP_ExitLeft_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_ExitLeft_perc) \n
 *		[Debug  Signal] [S_ABPLBP_ExitRight_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_ExitRight_perc) \n
 *		[Debug  Signal] [S_ABPLBP_LaneChangeDetected_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneChangeDetected_bool) \n
 *		[Debug  Signal] [S_ABPLBP_LaneValidQualDMC_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneValidQualDMC_nu) \n
 *		[Debug  Signal] [S_ABPLBP_LaneValidQualVis_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneValidQualVis_nu) \n
 *		[Debug  Signal] [S_ABPLBP_LaneWidth_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneWidth_met) \n
 *		[Debug  Signal] [S_ABPLBP_LeCoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeCoupLnQual_perc) \n
 *		[Debug  Signal] [S_ABPLBP_LeCrvQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeCrvQuality_perc) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthCrvChng_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrvChng_1pm2) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthCrvRtSIF_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrvRtSIF_1pm2) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthCrvSIF_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrvSIF_1pm) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthCrv_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrv_1pm) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthHeadingSIF_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthHeadingSIF_rad) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthHeading_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthHeading_rad) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthLength_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthLength_met) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthPosY0SIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthPosY0SIF_met) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnClthPosY0_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthPosY0_met) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnInvalidQuSIF_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnInvalidQuSIF_btf) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnInvalidQu_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnInvalidQu_btf) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnLengthSIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnLengthSIF_met) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnQualitySIF_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnQualitySIF_perc) \n
 *		[Debug  Signal] [S_ABPLBP_LeLnQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnQuality_perc) \n
 *		[Debug  Signal] [S_ABPLBP_LeUncoupBrid_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_LeUncoupBrid_bool) \n
 *		[Debug  Signal] [S_ABPLBP_LeUncoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeUncoupLnQual_perc) \n
 *		[Debug  Signal] [S_ABPLBP_OutRangeCheckQuali_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_OutRangeCheckQuali_btf) \n
 *		[Debug  Signal] [S_ABPLBP_PitchingDetected_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_PitchingDetected_bool) \n
 *		[Debug  Signal] [S_ABPLBP_PitchingProb_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_PitchingProb_perc) \n
 *		[Debug  Signal] [S_ABPLBP_RangeCheckQualifier_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_RangeCheckQualifier_btf) \n
 *		[Debug  Signal] [S_ABPLBP_RiCoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiCoupLnQual_perc) \n
 *		[Debug  Signal] [S_ABPLBP_RiCrvQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiCrvQuality_perc) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthCrvChng_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrvChng_1pm2) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthCrvRtSIF_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrvRtSIF_1pm2) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthCrvSIF_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrvSIF_1pm) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthCrv_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrv_1pm) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthHeadingSIF_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthHeadingSIF_rad) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthHeading_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthHeading_rad) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthLength_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthLength_met) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthPosY0SIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthPosY0SIF_met) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnClthPosY0_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthPosY0_met) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnInvalidQuSIF_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnInvalidQuSIF_btf) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnInvalidQu_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnInvalidQu_btf) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnLengthSIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnLengthSIF_met) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnQualitySIF_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnQualitySIF_perc) \n
 *		[Debug  Signal] [S_ABPLBP_RiLnQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnQuality_perc) \n
 *		[Debug  Signal] [S_ABPLBP_RiUncoupBrid_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_RiUncoupBrid_bool) \n
 *		[Debug  Signal] [S_ABPLBP_RiUncoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiUncoupLnQual_perc) \n
 *		[Debug  Signal] [S_ABPLBP_StraightPathDtct_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_StraightPathDtct_nu) \n
 *		[Debug  Signal] [S_ABPLBP_UncoupledLaneBrid_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_UncoupledLaneBrid_btf) \n
 *		[Debug  Signal] [S_ABPLBP_UncoupledLaneWidth_met](@ref ABPLBP_SenDbgType::S_ABPLBP_UncoupledLaneWidth_met) \n
 *		[Debug  Signal] [S_ABPLBP_UpDownHillDtct_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_UpDownHillDtct_perc) \n
 *		[Output Signal] [S_ABPLBP_CntrLnClthPosX0_met](@ref ABPLBP_SenOutType::S_ABPLBP_CntrLnClthPosX0_met) \n
 *		[Output Signal] [S_ABPLBP_LeLnClthPosX0_met](@ref ABPLBP_SenOutType::S_ABPLBP_LeLnClthPosX0_met) \n
 *		[Output Signal] [S_ABPLBP_LeftLaneType_enum](@ref ABPLBP_SenOutType::S_ABPLBP_LeftLaneType_enum) \n
 *		[Output Signal] [S_ABPLBP_RiLnClthPosX0_met](@ref ABPLBP_SenOutType::S_ABPLBP_RiLnClthPosX0_met) \n
 *		[Output Signal] [S_ABPLBP_RightLaneType_enum](@ref ABPLBP_SenOutType::S_ABPLBP_RightLaneType_enum) \n\n
 *		For signal details, see sub-section [Globals](@ref ABPLBP_SenProcess_Globals) of the function @ref ABPLBP_SenProcess.
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
extern void ABPLBP_SenReset(void);

/*!
 *	ABPLBP module sensor process function.
 *	
 *	@pre
 *		- The ABPLBP sensor initialization function(s) must be called once.
 *		- The ABPLBP sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor ABPLBP_SenProcess_Globals
 *		[S_ABPLBP_ABDTimeStamp_sec](@ref ABPLBP_SenDbgType::S_ABPLBP_ABDTimeStamp_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		ABD data timestamp in seconds \n\n
 *		[S_ABPLBP_CntrLnClthCrvChng_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Lane center clothoid curvature change \n\n
 *		[S_ABPLBP_CntrLnClthCrv_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Lane center clothoid curvature \n\n
 *		[S_ABPLBP_CntrLnClthHeading_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Lane center clothoid heading angle \n\n
 *		[S_ABPLBP_CntrLnClthLength_met](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lane center clothoid length \n\n
 *		[S_ABPLBP_CntrLnClthPosY0_met](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnClthPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lane center clothoid Y0 position \n\n
 *		[S_ABPLBP_CntrLnKalmanQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnKalmanQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Center lane kalman quality \n\n
 *		[S_ABPLBP_CntrLnKalmanStatus_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_CntrLnKalmanStatus_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_ABPLBP_KalmanStatusType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Center lane kalman filter status \n
 *		0: not valid \n
 *		1: full update \n
 *		2: degraded update \n
 *		3: predict \n
 *		4: init \n
 *		5: reset \n\n
 *		[S_ABPLBP_ConstructionSite_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_ConstructionSite_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: Construction site detected; \n
 *		FALSE: No construction site detected \n\n
 *		[S_ABPLBP_CoupledLaneWidth_met](@ref ABPLBP_SenDbgType::S_ABPLBP_CoupledLaneWidth_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Raw lane width of ABD interface coupled lane data \n\n
 *		[S_ABPLBP_ExitLeft_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_ExitLeft_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Exit flag for left side \n\n
 *		[S_ABPLBP_ExitRight_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_ExitRight_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Exit flag for right side \n\n
 *		[S_ABPLBP_LaneChangeDetected_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneChangeDetected_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Flag that indicates a detected lane change \n\n
 *		[S_ABPLBP_LaneValidQualDMC_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneValidQualDMC_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Lane valid qualifier for Lat DMC: \n
 *		0 - no ego lanes \n
 *		1 - one sided ego lane detection \n
 *		2 - both sided ego lane detection \n\n
 *		[S_ABPLBP_LaneValidQualVis_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneValidQualVis_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Qualifier for the visualization: \n
 *		0- no lanes detected \n
 *		1 - left lane detected \n
 *		2 - right lane detected \n
 *		3 - left lane bridged \n
 *		4 - right lane bridged \n
 *		5  - both lanes detected \n
 *		6 - left lane LD virtual \n
 *		7 - right lane LD virtual \n\n
 *		[S_ABPLBP_LaneWidth_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LaneWidth_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane width \n\n
 *		[S_ABPLBP_LeCoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeCoupLnQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Left coupled lane quality \n\n
 *		[S_ABPLBP_LeCrvQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeCrvQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the curvature information based on standard deviations and the lookahead distance \n\n
 *		[S_ABPLBP_LeLnClthCrvChng_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left lane clothoid change of curvature \n\n
 *		[S_ABPLBP_LeLnClthCrvRtSIF_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrvRtSIF_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left lane clothoid change of curvature (SIF) \n\n
 *		[S_ABPLBP_LeLnClthCrvSIF_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrvSIF_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left lane clothoid curvature (safety interface) \n\n
 *		[S_ABPLBP_LeLnClthCrv_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left lane clothoid curvature \n\n
 *		[S_ABPLBP_LeLnClthHeadingSIF_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthHeadingSIF_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left lane clothoid heading angle (safety interface) \n\n
 *		[S_ABPLBP_LeLnClthHeading_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left lane clothoid heading angle \n\n
 *		[S_ABPLBP_LeLnClthLength_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid length \n\n
 *		[S_ABPLBP_LeLnClthPosY0SIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthPosY0SIF_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (safety interface) \n\n
 *		[S_ABPLBP_LeLnClthPosY0_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnClthPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (init +10m) \n\n
 *		[S_ABPLBP_LeLnInvalidQuSIF_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnInvalidQuSIF_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Left lane invalid qualifier for the safety interface \n
 *		Bit0: Jump in lateral distance stored \n
 *		Bit1: Jump in heading stored \n
 *		Bit2: Jump in curvature stored \n
 *		Bit3: Quality invalid (LD virtual lane) \n\n
 *		[S_ABPLBP_LeLnInvalidQu_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnInvalidQu_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit 0: Not available \n
 *		Bit 1: Lateral distance step \n
 *		Bit 2: Lenght invalid \n
 *		Bit 3: Lateral distance step (output data) \n
 *		Bit 4: Heading step (output data) \n
 *		Bit 5: Curvature step (output data) \n
 *		Bit 6: Curvature rate step (output data) \n
 *		Bit 7: Kalman filter status not valid \n
 *		Bit 8: Input data out of range \n
 *		Bit 9: Output data out of range \n
 *		Bit10:Lane type invalid \n
 *		Bit11:Lane color invalid \n
 *		Bit12:Lane quality invalid \n
 *		Bit13:Lane bridged \n
 *		Bit14:LD virtual lane \n
 *		Bit15:- \n\n
 *		[S_ABPLBP_LeLnLengthSIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnLengthSIF_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid length (SIF) \n\n
 *		[S_ABPLBP_LeLnQualitySIF_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnQualitySIF_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Left lane safety interface quality (SIF) \n\n
 *		[S_ABPLBP_LeLnQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeLnQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the left ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		[S_ABPLBP_LeUncoupBrid_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_LeUncoupBrid_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		left lane uncoupled lane bridging possible \n\n
 *		[S_ABPLBP_LeUncoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_LeUncoupLnQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Left uncoupled lane quality \n\n
 *		[S_ABPLBP_OutRangeCheckQuali_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_OutRangeCheckQuali_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit 0: Left lateral position out of range \n
 *		Bit 1: Right lateral position out of range \n
 *		Bit 2: Center lateral position out of range \n
 *		Bit 3: Left heading out of range \n
 *		Bit 4: Right heading out of range \n
 *		Bit 5: Center heading out of range \n
 *		Bit 6: Left curvature out of range \n
 *		Bit 7: Right curvature out of range \n
 *		Bit 8: Center curvature out of range \n
 *		Bit 9: Left curvature rate out of range \n
 *		Bit 10: Right curvature rate out of range \n
 *		Bit 11: Center curvature rate out of range \n\n
 *		[S_ABPLBP_PitchingDetected_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_PitchingDetected_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines if pitching situation has been detected \n\n
 *		[S_ABPLBP_PitchingProb_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_PitchingProb_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Pitching detection probability \n\n
 *		[S_ABPLBP_RangeCheckQualifier_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_RangeCheckQualifier_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Input range check qualifier bitfield: \n
 *		 \n
 *		Bit 0: Left lateral position out of range \n
 *		Bit 1: Left lateral position out of range \n
 *		Bit 2: Right lateral position out of range \n
 *		Bit 3: Left yaw angle out of range \n
 *		Bit 4: Right yaw angle out of range \n
 *		Bit 5: Left curvature out of range \n
 *		Bit 6: Right curvature out of range \n
 *		Bit 7: Left curvature rate out of range \n
 *		Bit 8: Rightcurvature rate out of range \n\n
 *		[S_ABPLBP_RiCoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiCoupLnQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Right coupled lane quality \n\n
 *		[S_ABPLBP_RiCrvQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiCrvQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the curvature information based on standard deviations and the lookahead distance \n\n
 *		[S_ABPLBP_RiLnClthCrvChng_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right lane clothoid curvature change \n\n
 *		[S_ABPLBP_RiLnClthCrvRtSIF_1pm2](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrvRtSIF_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right lane clothoid curvature change (SIF) \n\n
 *		[S_ABPLBP_RiLnClthCrvSIF_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrvSIF_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right lane clothoid curvature (safety interface) \n\n
 *		[S_ABPLBP_RiLnClthCrv_1pm](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right lane clothoid curvature \n\n
 *		[S_ABPLBP_RiLnClthHeadingSIF_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthHeadingSIF_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right lane clothoid heading angle \n\n
 *		[S_ABPLBP_RiLnClthHeading_rad](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right lane clothoid heading angle \n\n
 *		[S_ABPLBP_RiLnClthLength_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid length \n\n
 *		[S_ABPLBP_RiLnClthPosY0SIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthPosY0SIF_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (safety interface) \n\n
 *		[S_ABPLBP_RiLnClthPosY0_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnClthPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (init -10m) \n\n
 *		[S_ABPLBP_RiLnInvalidQuSIF_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnInvalidQuSIF_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Right lane invalid qualifier for the safety interface \n
 *		Bit0: Jump in lateral distance stored \n
 *		Bit1: Jump in heading stored \n
 *		Bit2: Jump in curvature stored \n
 *		Bit3: Quality invalid (LD virtual) \n\n
 *		[S_ABPLBP_RiLnInvalidQu_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnInvalidQu_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit 0: Not available \n
 *		Bit 1: Lateral distance step \n
 *		Bit 2: Lenght invalid \n
 *		Bit 3: Lateral distance step (output data) \n
 *		Bit 4: Heading step (output data) \n
 *		Bit 5: Curvature step (output data) \n
 *		Bit 6: Curvature rate step (output data) \n
 *		Bit 7: Kalman filter status not valid \n
 *		Bit 8: Input data out of range \n
 *		Bit 9: Output data out of range \n
 *		Bit10:Lane type invalid \n
 *		Bit11:Lane color invalid \n
 *		Bit12:Lane quality invalid \n
 *		Bit13:Lane bridged \n
 *		Bit14:LD virtual lane \n
 *		Bit15:- \n\n
 *		[S_ABPLBP_RiLnLengthSIF_met](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnLengthSIF_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid length (SIF) \n\n
 *		[S_ABPLBP_RiLnQualitySIF_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnQualitySIF_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Right lane safety interface quality (SIF) \n\n
 *		[S_ABPLBP_RiLnQuality_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiLnQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the right ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		[S_ABPLBP_RiUncoupBrid_bool](@ref ABPLBP_SenDbgType::S_ABPLBP_RiUncoupBrid_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Right lane uncouplded bridging possible \n\n
 *		[S_ABPLBP_RiUncoupLnQual_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_RiUncoupLnQual_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Right uncoupled lane quality \n\n
 *		[S_ABPLBP_StraightPathDtct_nu](@ref ABPLBP_SenDbgType::S_ABPLBP_StraightPathDtct_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Confidence for straight detection - value from 0 to 100 \n\n
 *		[S_ABPLBP_UncoupledLaneBrid_btf](@ref ABPLBP_SenDbgType::S_ABPLBP_UncoupledLaneBrid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Uncoupled lane bridging bitfield  \n
 *		Bit 0: Left uncoupled lane step \n
 *		Bit 1: Right uncoupled lane step \n
 *		Bit 2: Left exit \n
 *		Bit 3: Right exit  \n
 *		Bit 4: Left curvature dev \n
 *		Bit 5: Right curvature dev \n
 *		Bit 6: Left heading dev \n
 *		Bit 7: Right heading dev \n\n
 *		[S_ABPLBP_UncoupledLaneWidth_met](@ref ABPLBP_SenDbgType::S_ABPLBP_UncoupledLaneWidth_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Raw lane width of ABD interface uncoupled lane data \n\n
 *		[S_ABPLBP_UpDownHillDtct_perc](@ref ABPLBP_SenDbgType::S_ABPLBP_UpDownHillDtct_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Indicates downhill / uphill scenario detection confidence \n\n
 *		[S_ABPLBP_CntrLnClthPosX0_met](@ref ABPLBP_SenOutType::S_ABPLBP_CntrLnClthPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lane center clothoid X0-Position \n\n
 *		[S_ABPLBP_LeLnClthPosX0_met](@ref ABPLBP_SenOutType::S_ABPLBP_LeLnClthPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid X0 position \n\n
 *		[S_ABPLBP_LeftLaneType_enum](@ref ABPLBP_SenOutType::S_ABPLBP_LeftLaneType_enum) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		NO_LINE= 0 \n
 *		PAINTED_CONTINUOUS = 1 \n
 *		PAINTED_DASHED = 2 \n
 *		PAINTED_DECORATIVE = 3 \n
 *		DOTTED_CONTINUOUS = 4 \n
 *		DOTTED_DASHED = 5  \n
 *		ELEVATED_CONTINUOUS=6 \n
 *		ELEVATED_DISCRETE = 7 \n
 *		CURBSTONE =8 \n
 *		ROADEDGE =9 \n
 *		UNKNOWN = 10 \n\n
 *		[S_ABPLBP_RiLnClthPosX0_met](@ref ABPLBP_SenOutType::S_ABPLBP_RiLnClthPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid X0 position \n\n
 *		[S_ABPLBP_RightLaneType_enum](@ref ABPLBP_SenOutType::S_ABPLBP_RightLaneType_enum) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		NO_LINE= 0 \n
 *		PAINTED_CONTINUOUS = 1 \n
 *		PAINTED_DASHED = 2 \n
 *		PAINTED_DECORATIVE = 3 \n
 *		DOTTED_CONTINUOUS = 4 \n
 *		DOTTED_DASHED = 5  \n
 *		ELEVATED_CONTINUOUS=6 \n
 *		ELEVATED_DISCRETE = 7 \n
 *		CURBSTONE =8 \n
 *		ROADEDGE =9 \n
 *		UNKNOWN = 10 \n\n
 *		@ref S_LCFRCV_ABDFusionConfLeft_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Any boundary detection road model fusion confidence of left coupled lane \n\n
 *		@ref S_LCFRCV_ABDFusionConfRight_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Any boundary detection road model fusion confidence of right coupled lane \n\n
 *		@ref S_LCFRCV_ABDOverpassDtct_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Any boundary detection overpass detection (contrast change) \n\n
 *		@ref S_LCFRCV_ABDSineWaveDtct_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Flag from ABD interface that indicates sine wave road condition \n\n
 *		@ref S_LCFRCV_ABDVertAvailable_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		-2.0f means “not available because virtual TLB present”; \n
 *		-1.0f means “height profile not available because not both sides available”; \n
 *		0.0f means “both sides there, but profile not available” (too few or no feature pairs); \n
 *		1.0f means “height profile available” \n\n
 *		@ref S_LCFRCV_ABDVertCurvatureRt_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		ABD height profile estimation; \n
 *		Coefficient to third-order monomial \n\n
 *		@ref S_LCFRCV_ABDVertCurvature_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		ABD height profile estimation; \n
 *		Coefficient to second-order monomial \n\n
 *		@ref S_LCFRCV_ABDVertSlopeChange_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_NoUnit_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		0.0f means “no significant slope change detected”; \n
 *		1.0f means “significant slope change detected during the last 8 frames” \n
 *		2.0f means “significant slope change detected in the current frame” \n\n
 *		@ref S_LCFRCV_ABDVertValidLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		lookahead distance (longitudinal coordinate of furthest feature pair) OR, if significant slope change detected during last 8 frames, the motion compensated distance where the vertical profile deviates “too strongly” from the flat world assumption \n\n
 *		@ref S_LCFRCV_AnyBndAvailable_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Defines whether a lane boundary track is available or not. If the flag is set to 0, the other parameters might either remain constant or change over time. The parameters will not be reset to default values in case that a track gets lost. The parameters must not be used if this value is 0. \n\n
 *		@ref S_LCFRCV_AnyBndColor_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_ABPR_LaneMarkersColorType_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Defines the color of a lane boundary track. Remark: Green is a legacy value that will not be filled. Red will be mapped to yellow. \n
 *		ABD_MC_UNCLASSIFIED = 0  \n
 *		ABD_MC_WHITE = 1 \n
 *		ABD_MC_YELLOW = 2 \n
 *		ABD_MC_RED = 3 \n
 *		ABD_MC_BLUE = 4 \n
 *		ABD_MC_GREEN = 5 \n\n
 *		@ref S_LCFRCV_AnyBndCrvRateStd_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_0_1_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Standard deviation of the curvature rate. \n\n
 *		@ref S_LCFRCV_AnyBndCrvRate_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Curvature rate of a lane boundary track w.r.t. the used coordinate system. \n\n
 *		@ref S_LCFRCV_AnyBndCurvatureStd_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_0_0p5_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.5 \n
 *		\@description: \n
 *		Standard deviation of the curvature. \n\n
 *		@ref S_LCFRCV_AnyBndCurvature_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature of a lane boundary track w.r.t. the used coordinate system \n\n
 *		@ref S_LCFRCV_AnyBndDistanceStd_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Standard deviation of the lateral distance of lane marker tracks. \n\n
 *		@ref S_LCFRCV_AnyBndDistance_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Defines the lateral distance of a lane boundary track w.r.t. the used coordinate system in meters. The distance given is the value of the polynomial evaluated at X = 0.0 m. \n\n
 *		@ref S_LCFRCV_AnyBndLeftIndex_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref s8_NoUnit_m1_10_0_1_t \n
 *		\@size: 1x3x1 \n
 *		\@unit: - \n
 *		\@min: -1 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Index for left-hand any boundaries: \n
 *		[0] - left ego lane; \n
 *		[1] - left adjacent lane; \n
 *		[2]- left road edge \n\n
 *		@ref S_LCFRCV_AnyBndMarkerType_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_ABPR_AbdLnMarkersType2_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Decribes the type of a lane marker (e.g. continuous, dashed, road edge,…). \n
 *		ABD_MT_NO_LINE= 0 \n
 *		ABD_MT_PAINTED_CONTINUOUS = 1 \n
 *		ABD_MT_PAINTED_DASHED = 2 \n
 *		ABD_MT_PAINTED_DECORATIVE = 3 \n
 *		ABD_MT_DOTTED_CONTINUOUS = 4 \n
 *		ABD_MT_DOTTED_DASHED = 5  \n
 *		ABD_MT_ELEVATED_CONTINUOUS=6 \n
 *		ABD_MT_ELEVATED_DISCRETE = 7 \n
 *		ABD_MT_CURBSTONE =8 \n
 *		ABD_MT_ROADEDGE =9 \n
 *		ABD_MT_UNKNOWN = 100 \n\n
 *		@ref S_LCFRCV_AnyBndQuality_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		default value:          00 \n
 *		Range Quality  X:  1Y - 9Y	=> will be mapped from local map. e.g. local map 34 -> 3Y; local map 78 -> 7Y ... \n
 *		Range Weight  Y : X2 - X9	=> the higher the better \n
 *		virtual line:                01 \n\n
 *		@ref S_LCFRCV_AnyBndRightIndex_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref s8_NoUnit_m1_10_0_1_t \n
 *		\@size: 1x3x1 \n
 *		\@unit: - \n
 *		\@min: -1 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Index for left boundaries: \n
 *		[0] - left ego lane; \n
 *		[1] - left adjacent lane; \n
 *		[2]- left road edge \n\n
 *		@ref S_LCFRCV_AnyBndRoadWorks_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		ABD road works bitfield: \n
 *		 \n
 *		Bit0: CS_MULTIPLE_MARKER; \n
 *		Bit1: CS_LEFT_BARRIER; \n
 *		Bit2: CS_RIGHT_BARRIER; \n
 *		Bit3: CS_CROSSING_MARKER; \n
 *		Bit4: CS_INHIBIT_SINGLE_LINE; \n
 *		Bit5: CS_MARKER_COLOR_CHANGE; \n
 *		Bit6: CS_HOLD \n\n
 *		@ref S_LCFRCV_AnyBndValidLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Visibility range of a lane boundary track. This value is calculated using the features associated to the track. A lane boundary track can be considered as accurate up to this distance. Evaluating the polynomial at a longitudinal distance larger than this value results in an extrapolation and might lead to inaccurate lateral distances. \n\n
 *		@ref S_LCFRCV_AnyBndYawAngleStd_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_0_1_1em6_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Standard deviation of the yaw angle of lane marker tracks. \n\n
 *		@ref S_LCFRCV_AnyBndYawAngle_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Defines the yaw angle of a lane boundary track w.r.t. the used coordinate system in radians \n\n
 *		@ref S_LCFRCV_CBWeatherCond_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Camera blockage (CB) weather condition enum; \n
 *		GB_HEAVY_RAIN_SNOW    (2) \n
 *		GB_HEAVY_FOG    (4) \n
 *		GB_HEAVY_GLARING_SUN    (8) \n
 *		GB_GLARING    (16) \n
 *		GB_RAIN    (32) \n
 *		GB_FOG    (64) \n\n
 *		@ref S_LCFRCV_LDCompState_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_ABPR_AlgoCompStateV2_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		Lane detection component state enumeration \n\n
 *		@ref S_LCFRCV_LaneBoundariesTstamp_us \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u32_us_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: us \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		Camera data timestamp \n\n
 *		@ref S_LCFRCV_LaneChange_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_ABPR_LaneChangeType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Defines whether a lane change has been detected or not. In case that a lane change has been detected, the direction of the lane change (left to right or right to left) is given. \n
 *		ABD_LC_UNKNOWN = 0 \n
 *		ABD_LC_LEFT = 1 \n
 *		ABD_LC_RIGHT = 2 \n
 *		ABD_LC_UNCHANGED = 3 \n\n
 *		@ref S_LCFRCV_LaneEventDistance_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_200_1em3_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 200 \n
 *		\@description: \n
 *		Describes the distance to a lane event in meters. \n\n
 *		@ref S_LCFRCV_LaneEventQuality_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Describes the quality of a detected lane event. \n\n
 *		@ref S_LCFRCV_LaneEventType_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_ABPR_LaneEventType_t \n
 *		\@size: 1x2x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		Describes the event (e.g. construction site, pedestrian crossing, exit,…) present on one or both sides of the ego lane boundary. \n
 *		ABD_LE_IDLE = 0 \n
 *		ABD_LE_FORK_EXIT = 1 \n
 *		ABD_LE_FORK_ENTRY = 2 \n
 *		ABD_LE_FORK_UNKNOWN_OPEN = 3 \n
 *		ABD_LE_FORK_UNKNOWN_CLOSE = 4 \n
 *		ABD_LE_CONSTRUCTION_START = 5 \n
 *		ABD_LE_CONSTRUCTION_STOP = 6 \n
 *		ABD_LE_PEDX_START = 7 \n
 *		ABD_LE_PEDX_STOP = 8 \n\n
 *		@ref S_LCFRCV_SysCycleTimeSen_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0p001_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Cycle time for LCF_SEN components (60ms): \n
 *		minimum possible cycle time:1ms \n
 *		maximum possible cycle time:100ms \n\n
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
 *		@ref S_LCFRCV_VehYawRateStd_radps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_radps_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Ego vehicle yaw rate standard deviation \n\n
 *		@ref S_LCFRCV_VehYawRate_rps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_radps_m1_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: -1 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Ego Vehicle yaw rate (VDY); \n
 *		TODO:Check signal range and choose the corresponding datatype range \n\n
 *		@ref P_ABPLBP_ABDSineWaveHoldOffT_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		ABD sine wave road indicator hold off time \n\n
 *		@ref P_ABPLBP_CSABDBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask determines the ABD CS information usage: \n
 *		 \n
 *		Bit 0: CS_MULTIPLE_MARKER; \n
 *		Bit 1: CS_LEFT_BARRIER; \n
 *		Bit 2: CS_RIGHT_BARRIER; \n
 *		Bit 3: CS_CROSSING_MARKER; \n
 *		Bit 4: CS_INHIBIT_SINGLE_LINE; \n
 *		Bit 5: CS_MARKER_COLOR_CHANGE; \n
 *		Bit 6: CS_HOLD \n\n
 *		@ref P_ABPLBP_CorridorHoldAfterLost_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		the parameter restrains Lateral position and curvature changing when lane available detection from LD is turn off \n\n
 *		@ref P_ABPLBP_CrvDiffForBridging_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature difference from corresponding lane to previous center lane to inhibit bridging \n\n
 *		@ref P_ABPLBP_CrvDiffForPitchProb_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		TBD \n\n
 *		@ref P_ABPLBP_CrvDiffRatioForPitch_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0p0001_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0.0001 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		curvature threshold for pitching detection \n\n
 *		@ref P_ABPLBP_CrvEstimEndPoint_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_200_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 200 \n
 *		\@description: \n
 *		Define end point for 2nd order polynomial curvature estimation. \n\n
 *		@ref P_ABPLBP_CrvEstimPT1Curve_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		PT1 time constant for curvature signal filtering while driving in a curve \n\n
 *		@ref P_ABPLBP_CrvEstimPT1Straight_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		PT1 time constant for curvature signal filtering while driving straight \n\n
 *		@ref P_ABPLBP_CrvEstimStartPoint_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Define start point for 2nd order polynomial curvature estimation. \n\n
 *		@ref P_ABPLBP_CrvFiltEnd_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Final curvature value for maximum PT1 curvature filter time constant \n\n
 *		@ref P_ABPLBP_CrvFiltMinCalcDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Minimum distance between TLB (TrackerLaneBoundary) valid length and the desired start point for the curvature estimation. \n\n
 *		@ref P_ABPLBP_CrvFiltStart_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Start curvature value for maximum PT1 curvature filter time constant \n\n
 *		@ref P_ABPLBP_CrvKFDecQualDeg_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality decrease for the curvature kalman filter after the degraded update step has been applied \n\n
 *		@ref P_ABPLBP_CrvKFDecQualPred_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality decrease for the lane kalman filter after only a prediction step has been applied \n\n
 *		@ref P_ABPLBP_CrvKFDefCurve_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Defines the threshold for a curve (different filtering is applied in kalman filter) \n\n
 *		@ref P_ABPLBP_CrvKFDegradeWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0p0001_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0.0001 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Weight for degraded update_laneKF \n\n
 *		@ref P_ABPLBP_CrvKFErrCoeff1_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_3p4E38_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 3.4E+38 \n
 *		\@description: \n
 *		Geometric model error (kappa2diff) calculation factor 1 - [minimum radius european highway] \n\n
 *		@ref P_ABPLBP_CrvKFErrCoeff2_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Geometric model error (kappa2diff) calculation factor 2 - [average ego vehicle velocity highway] \n\n
 *		@ref P_ABPLBP_CrvKFIncQual_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality increase for the lane kalman filter after the update step has been applied \n\n
 *		@ref P_ABPLBP_CrvKFInitRFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Initialization factor for R_laneKF matrix -> achieve better transient oscillation \n\n
 *		@ref P_ABPLBP_CrvKFMnInitQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum measurement quality for the kalman filter initialization \n\n
 *		@ref P_ABPLBP_CrvKFMnUpdateQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum measurement quality to apply kalman filter update step. If the measurement quality is below only the prediction step is applied. \n\n
 *		@ref P_ABPLBP_CrvKFQ11FacStr_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Q11 matrix factor for straight road \n\n
 *		@ref P_ABPLBP_CrvKFQ11Fac_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Q11 matrix factor for curved road \n\n
 *		@ref P_ABPLBP_CrvKFStdDevCrvRt_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Center lane curvature rate standard deviation \n\n
 *		@ref P_ABPLBP_CrvKFStdDevCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Center lane curvature standard deviation \n\n
 *		@ref P_ABPLBP_CrvLimStepDtct_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Threshold for step detection in lane marker curvature \n\n
 *		@ref P_ABPLBP_CrvRateLimStepDtct_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Threshold for step detection in lane marker curvature change \n\n
 *		@ref P_ABPLBP_CurvatureGrad_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature gradient \n\n
 *		@ref P_ABPLBP_CurvatureRateGrad_1pm2s \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms2_0_0p1_1em7_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature rate gradient \n\n
 *		@ref P_ABPLBP_DebounceTCrvRtStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time for curvature rate step detection \n\n
 *		@ref P_ABPLBP_DebounceTCrvStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time for curvature step detection \n\n
 *		@ref P_ABPLBP_DebounceTDistYStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time for lateral distance step detection \n\n
 *		@ref P_ABPLBP_DebounceTYawAngStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time for yaw angle step detection \n\n
 *		@ref P_ABPLBP_DefaultLaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Default Lane Width \n\n
 *		@ref P_ABPLBP_DistYLimitStepDtctPitch_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Threshold for step detection in lane marker positions during pitching detection \n\n
 *		@ref P_ABPLBP_DistYLimitStepDtct_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Threshold for step detection in lane marker positions \n\n
 *		@ref P_ABPLBP_DurValidDistY_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debounce time after lateral distance step detection \n\n
 *		@ref P_ABPLBP_DurValidNewCorr_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		The time it takes to consider a new corridor valid \n\n
 *		@ref P_ABPLBP_ExitCrvThresh_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane exit detetction curvature deviation threshold to inhibit detection above this curvature \n\n
 *		@ref P_ABPLBP_ExitHeadingThresh_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Exit detection heading angle threshold \n\n
 *		@ref P_ABPLBP_ExitNCycleTrig_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Edge rising trigger enable regarding exit ramp detection by lane width difference \n\n
 *		@ref P_ABPLBP_FadingFactorDiffCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Fading factor between left and right lane in tight curve situation. Fading will be applied dependent on the internal lane quality \n\n
 *		@ref P_ABPLBP_FadingFactorDiffPit_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Fading factor between left and right lane during pitching detected. Fading will be applied dependent on the internal lane quality \n\n
 *		@ref P_ABPLBP_FadingFactorDiff_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Fading factor between left and right lane. Fading will be applied dependent on the internal lane quality \n\n
 *		@ref P_ABPLBP_FadingFactorOneSideCrv_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Fading factor for dynamic coupled/uncoupled lane weighting in tight curve situation. \n\n
 *		@ref P_ABPLBP_FadingFactorOneSide_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Fading factor for dynamic coupled/uncoupled lane weighting \n\n
 *		@ref P_ABPLBP_HeadLimStepDtct_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Threshold for step detection in heading angle \n\n
 *		@ref P_ABPLBP_InvalLeftLane_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for setting the left lane boundary invalid \n\n
 *		@ref P_ABPLBP_InvalRightLane_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for setting the right lane invalid \n\n
 *		@ref P_ABPLBP_JumpDebounceTimeSIF_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Debounce time for jumps of curvature, heading angle or lateral distance (safety interface) \n\n
 *		@ref P_ABPLBP_LDSlopeHoldOffT_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Hold off delay time for LD slope detection information \n\n
 *		@ref P_ABPLBP_LDVirtCycleTurnOn_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Cycle turn on time \n\n
 *		@ref P_ABPLBP_LDVirtDefaultQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Default internal quality for LD virtual line \n\n
 *		@ref P_ABPLBP_LDVirtualDelayCycle_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Determines the cycles for the samle turn on delay for the LD virtual information. \n\n
 *		@ref P_ABPLBP_LDVirtualTForBrid_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Defines the maximum time a LD virtual line is used for bridging \n\n
 *		@ref P_ABPLBP_LaneKFDecQualDeg_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality decrease for the lane kalman filter after the degraded update step has been applied \n\n
 *		@ref P_ABPLBP_LaneKFDecQualPred_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality decrease for the lane kalman filter after only a prediction step has been applied \n\n
 *		@ref P_ABPLBP_LaneKFDegrUpdateQu_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality threshold for degraded update in center lane kalman filter \n\n
 *		@ref P_ABPLBP_LaneKFDegrUpdate_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use degraded update in center lane kalman filter \n\n
 *		@ref P_ABPLBP_LaneKFDegradeWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0p0001_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0.0001 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Weight for degraded update_laneKF \n\n
 *		@ref P_ABPLBP_LaneKFDynCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor to control the curvature signal dynamics in lane center kalman filter \n\n
 *		@ref P_ABPLBP_LaneKFDynCrvRtFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor to control the curvature signal dynamics in lane center kalman filter \n\n
 *		@ref P_ABPLBP_LaneKFDynDistYFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor needed to set the dynamic of the lateral distance within the prediction step; \n
 *		100000.0f High Dynamic, 10000.0f Middle Dynamic, <1000.0f Low Dynamic \n\n
 *		@ref P_ABPLBP_LaneKFDynYawFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor needed to set the dynamic of the yaw angle within the prediction step \n\n
 *		@ref P_ABPLBP_LaneKFErrCoeff1_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_3p4E38_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 3.4E+38 \n
 *		\@description: \n
 *		Geometric model error (kappa2diff) calculation factor 1 - [minimum radius european highway] \n\n
 *		@ref P_ABPLBP_LaneKFErrCoeff2_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Geometric model error (kappa2diff) calculation factor 2 - [average ego vehicle velocity highway] \n\n
 *		@ref P_ABPLBP_LaneKFIncQual_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality increase for the lane kalman filter after the update step has been applied \n\n
 *		@ref P_ABPLBP_LaneKFInitRFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Initialization factor for R_laneKF matrix -> achieve better transient oscillation \n\n
 *		@ref P_ABPLBP_LaneKFKGainFac_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Factor needed to set the dynamic of the lateral position within degraded update \n\n
 *		@ref P_ABPLBP_LaneKFMnInitQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum measurement quality for the kalman filter initialization \n\n
 *		@ref P_ABPLBP_LaneKFMnUpdateQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum measurement quality to apply kalman filter update step. If the measurement quality is below only the prediction step is applied. \n\n
 *		@ref P_ABPLBP_LaneKFQualForBrid_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum center lane kalman filter to enable lane bridging \n\n
 *		@ref P_ABPLBP_LaneKFStdDevCrvRt_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Center lane curvature rate standard deviation \n\n
 *		@ref P_ABPLBP_LaneKFStdDevCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.5 \n
 *		\@description: \n
 *		Center lane curvature standard deviation \n\n
 *		@ref P_ABPLBP_LaneKFStdDevLatDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Center lane lateral distance standard deviation \n\n
 *		@ref P_ABPLBP_LaneKFStdDevYawRt_radps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Center lane yaw rate standard deviation \n\n
 *		@ref P_ABPLBP_LaneKFStdDevYaw_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Center lane yaw angle standard deviation \n\n
 *		@ref P_ABPLBP_LaneKFYawRtStdDev_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE:Use VDY yaw rate standard deviation.  \n
 *		FALSE:Use constant standard deviation \n\n
 *		@ref P_ABPLBP_LaneQualCrvLim_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		tight curvature check for lane quality \n\n
 *		@ref P_ABPLBP_LaneQualityLSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lane quality LSP (lower hysteresis \n\n
 *		@ref P_ABPLBP_LaneQualityRSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lane quality LSP (upper hysteresis) \n\n
 *		@ref P_ABPLBP_LaneWidthDiffCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		curvature-dependent lane width difference threshold for Exit detection \n\n
 *		@ref P_ABPLBP_LaneWidthDiffThresh_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane width difference threshold for exit detection \n\n
 *		@ref P_ABPLBP_LaneWidthGrad_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Gradient limit for lane width before PT1 filter \n\n
 *		@ref P_ABPLBP_LatDistDevCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		a factor for lateral deviation in tight curve situation \n\n
 *		@ref P_ABPLBP_LatDistDevCrvLSP_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Lateral distance deviation observer curvature threshold (LSP - lower hysteresis) \n\n
 *		@ref P_ABPLBP_LatDistDevCrvRSP_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Lateral distance deviation observer curvature threshold (LSP - lower hysteresis) \n\n
 *		@ref P_ABPLBP_LatDistDevThreshStr_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral deviation threshold for estimated and measured lateral position on straight \n\n
 *		@ref P_ABPLBP_LatDistDevThresh_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Lateral deviation threshold for estimated and measured lateral position \n\n
 *		@ref P_ABPLBP_LatDistGrad_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Lateral distance gradient \n\n
 *		@ref P_ABPLBP_LatencyTimeSIF_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Latency time for lateral distance latency compensation \n\n
 *		@ref P_ABPLBP_LnQualGrad_percps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		 \n\n
 *		@ref P_ABPLBP_MaxCrvRateRange_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum range check value for curvature rate \n\n
 *		@ref P_ABPLBP_MaxCurvatureRange_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum range check value for curvature \n\n
 *		@ref P_ABPLBP_MaxDistYRange_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum range check value for lateral position \n\n
 *		@ref P_ABPLBP_MaxHeadingRange_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximum range check value for yaw angle \n\n
 *		@ref P_ABPLBP_MaxLaneWidthHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane widht hysteresis for maximum lane width \n\n
 *		@ref P_ABPLBP_MaxLaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum valid lane width for LCF \n\n
 *		@ref P_ABPLBP_MaxRangeHyst_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Maximum range check hysteresis factor \n\n
 *		@ref P_ABPLBP_MaxValidLengthRange_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum range check value valid length \n\n
 *		@ref P_ABPLBP_MinKalmanQuality_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum kalman filter quality \n\n
 *		@ref P_ABPLBP_MinLaneWidthHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Hysteresis for minimum lane width \n\n
 *		@ref P_ABPLBP_MinLaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum valid lane width for LCF \n\n
 *		@ref P_ABPLBP_MinUncoupBridTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum uncoupled lane bridging time \n\n
 *		@ref P_ABPLBP_MinVelForKalmanFilt_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum kalman filter input velocity to avoid internal matrix inversion failures \n\n
 *		@ref P_ABPLBP_MinVelUpDownDtct_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum velocity for UpDownhill detection \n\n
 *		@ref P_ABPLBP_MotCompCrvGrad_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature gradient limiter after motion compensation \n\n
 *		@ref P_ABPLBP_MotCompCrvRtGrad_1pms2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms2_0_0p1_1em7_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature gradient limiter after motion compensation \n\n
 *		@ref P_ABPLBP_MotCompCrvThresh_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Motion compensation curvature threshold \n\n
 *		@ref P_ABPLBP_MotCompDYGradLim_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Delta lateral distance gradient limit threshold \n\n
 *		@ref P_ABPLBP_MotCompDYawGradLim_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Delta yaw gradient limit threshold \n\n
 *		@ref P_ABPLBP_MotCompDeltaQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Motion compensation delta quality threshold \n\n
 *		@ref P_ABPLBP_MotCompLatDistGrad_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Motion compensation lateral distance gradient \n\n
 *		@ref P_ABPLBP_MotCompMinPrevQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Motion compensation minimum previous lane quality threshold \n\n
 *		@ref P_ABPLBP_MotCompMinValLenPF_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Motion compensation minimum valid length of polyfit (reset condition) \n\n
 *		@ref P_ABPLBP_MotCompMinValLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Minimum valid length for motion compensation \n\n
 *		@ref P_ABPLBP_MotCompPolyMinLen_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Motion compensation minimum polyfit input valid length for sFunction enable switch \n\n
 *		@ref P_ABPLBP_MotCompQualReset_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Motion compensation reset quality \n\n
 *		@ref P_ABPLBP_MotCompYawGrad_radps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Motion compensation yaw angle gradient \n\n
 *		@ref P_ABPLBP_MotionCompDfltQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Default internal quality for motion compensation \n\n
 *		@ref P_ABPLBP_MxBridgDistOneSided_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Maximum allowed bridging distance \n\n
 *		@ref P_ABPLBP_MxBridgTimeOneSided_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Time span in which lane bridging is allowed. \n\n
 *		@ref P_ABPLBP_OverpassDfltQualT_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Overpass (dark-light transition) hold off delay time \n\n
 *		@ref P_ABPLBP_OverpassDfltQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Default quality in case of an detected dark-light transition (overpass issue) \n\n
 *		@ref P_ABPLBP_PT1LaneWidthTConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		PT1 filter time constant for lane width \n\n
 *		@ref P_ABPLBP_PT1LaneWidthTInit_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p001_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Init value for PT1 time constant of lane width lowpass filter \n\n
 *		@ref P_ABPLBP_PT1LaneWidthTLD_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_m1000_0_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: -1000 \n
 *		\@max: 0 \n
 *		\@description: \n
 *		PT1 lane width time constant init gradient limitation (lower gradient) \n\n
 *		@ref P_ABPLBP_PT1LaneWidthTLU_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		PT1 lane width time constant init gradient limitation (upper gradient) \n\n
 *		@ref P_ABPLBP_PT1TimeConstSIF_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Latency compensation lateral velocity PT1 filter time constant (safety interface) \n\n
 *		@ref P_ABPLBP_PitchProbDec_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		number of decreasing pitching probability by 1cycle \n\n
 *		@ref P_ABPLBP_PitchProbGain_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		gain for increasing probability \n\n
 *		@ref P_ABPLBP_PitchProbLSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		pitching probability hysteresis (LSP) \n\n
 *		@ref P_ABPLBP_PitchProbRSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		pitching probability hysteresis (RSP) \n\n
 *		@ref P_ABPLBP_QualCrvPenFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Factor to increase curvature penalty range in tight curves \n\n
 *		@ref P_ABPLBP_QualCrvPenWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality penalty weight for curvature \n\n
 *		@ref P_ABPLBP_QualCrvRtPenMax_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality maximum penalty curvature rate \n\n
 *		@ref P_ABPLBP_QualCrvRtPenMin_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality minimum penalty curvature rate \n\n
 *		@ref P_ABPLBP_QualCrvRtPenWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality penalty weight for curvature rate \n\n
 *		@ref P_ABPLBP_QualCurvaturePenMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality penalty curvature max value \n\n
 *		@ref P_ABPLBP_QualCurvaturePenMin_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality penalty curvature min value \n\n
 *		@ref P_ABPLBP_QualFadingFac_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Lane quality fading factor between lookahead distance and standard deviation term \n\n
 *		@ref P_ABPLBP_QualGradLimLD_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Quality gradient limit (lower) \n\n
 *		@ref P_ABPLBP_QualGradLimLU_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality gradient limit (upper) \n\n
 *		@ref P_ABPLBP_QualHeadingPenMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Quality heading max penalty value \n\n
 *		@ref P_ABPLBP_QualHeadingPenMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Quality heading min penalty value \n\n
 *		@ref P_ABPLBP_QualLatDistPenMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Quality lateral distance max penalty value \n\n
 *		@ref P_ABPLBP_QualLatDistPenMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Quality lateral distance min penalty value \n\n
 *		@ref P_ABPLBP_QualLatDistPenWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality penalty weight for lateral distance \n\n
 *		@ref P_ABPLBP_QualPenFactorPitch_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality penalty factor during pitching detection \n\n
 *		@ref P_ABPLBP_QualPenFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality penalty factor \n\n
 *		@ref P_ABPLBP_QualPenGradLimLD_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Quality penalty gradient limiter (lower) \n\n
 *		@ref P_ABPLBP_QualPenGradLimLU_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality penalty gradient limiter (upper) \n\n
 *		@ref P_ABPLBP_QualPenHoldFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality penalty hold factor \n\n
 *		@ref P_ABPLBP_QualValidLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Quality valid length \n\n
 *		@ref P_ABPLBP_QualYawPenWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality penalty weight for yaw angle \n\n
 *		@ref P_ABPLBP_SIFQualityLSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Safety interface quality hysteresis threshold (lower value) \n\n
 *		@ref P_ABPLBP_SIFQualityRSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Safety interface quality hysteresis threshold (upper value) \n\n
 *		@ref P_ABPLBP_StrDtctCrvDiffDef_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Default straight detection value if lane bridging is active, the center lane curvature is below a threshold and the difference of both uncoupled lanes to the center lane curvature is above a threshold \n\n
 *		@ref P_ABPLBP_StrDtctCrvLSP_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Straight detection curvature hysteresis (LSP) \n\n
 *		@ref P_ABPLBP_StrDtctCrvMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum allowed center lane curvature to trigger curvature difference check \n\n
 *		@ref P_ABPLBP_StrDtctCrvRSP_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Straight detection curvature hysteresis (RSP) \n\n
 *		@ref P_ABPLBP_StrDtctLengthRatio_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Straight detection length ratio \n\n
 *		@ref P_ABPLBP_StrDtctMinQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Straight detection minimum required quality \n\n
 *		@ref P_ABPLBP_StrDtctPreview_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Straight detection preview \n\n
 *		@ref P_ABPLBP_StraightDiffThresh_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Threshold for difference for the straight path estimation \n\n
 *		@ref P_ABPLBP_StraightScaleFct_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Scaling factor for curvature in case of a successful straight detection \n\n
 *		@ref P_ABPLBP_TolRangeDistY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Tolerance for lane width after step in lateral position \n\n
 *		@ref P_ABPLBP_TolRangeNewCorr_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		The corridor is considered new if the width changes more than this value \n\n
 *		@ref P_ABPLBP_TriggerDistDevThres_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Lateral distance deviation threshold for uncoupled lane briding \n\n
 *		@ref P_ABPLBP_UncoupDevReset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Uncoupled lane to coupled lane deviation for reset uncoupled lane bridging \n\n
 *		@ref P_ABPLBP_UncoupLnBridCrvLSP_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane bridging curvature reset LSP (lower hysteresis) value \n\n
 *		@ref P_ABPLBP_UncoupLnBridCrvRSP_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane bridging curvature reset RSP (upper hysteresis) value \n\n
 *		@ref P_ABPLBP_UncoupLnGradLimLD_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_m1000_0_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: -1000 \n
 *		\@max: 0 \n
 *		\@description: \n
 *		Uncoupled lane stept detection gradient limiter (lower value) \n\n
 *		@ref P_ABPLBP_UncoupLnGradLimLU_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_0_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 0 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Uncoupled lane stept detection gradient limiter (upper value) \n\n
 *		@ref P_ABPLBP_UncoupLnQualLSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Uncoupled lane quality hysteresis (LSP) \n\n
 *		@ref P_ABPLBP_UncoupLnQualRSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Uncoupled lane quality hysteresis (RSP) \n\n
 *		@ref P_ABPLBP_UncoupLnStepCRtMax_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane step detection curvature rate max \n\n
 *		@ref P_ABPLBP_UncoupLnStepCRtMin_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane step detection curvature rate min \n\n
 *		@ref P_ABPLBP_UncoupLnStepCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		the factor for curvature-dependent step detection \n\n
 *		@ref P_ABPLBP_UncoupLnStepCrvMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane step detection curvature max \n\n
 *		@ref P_ABPLBP_UncoupLnStepCrvMin_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Uncoupled lane step detection curvature min \n\n
 *		@ref P_ABPLBP_UncoupLnStepMaxVal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum uncoupled lane step detection threshold \n\n
 *		@ref P_ABPLBP_UncoupLnStepPosYMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Uncoupled lane step detection lateral position max \n\n
 *		@ref P_ABPLBP_UncoupLnStepPosYMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Uncoupled lane step detection lateral position min \n\n
 *		@ref P_ABPLBP_UncoupLnStepYawMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Uncoupled lane step detection heading max \n\n
 *		@ref P_ABPLBP_UncoupLnStepYawMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Uncoupled lane step detection heading min \n\n
 *		@ref P_ABPLBP_UpDownDeactivatSIF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Deactivate SIF if up downhill scenario has been detected \n\n
 *		@ref P_ABPLBP_UpDownHillLSP_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lower hysteresis threshold for up/downhill detetion evaluation \n\n
 *		@ref P_ABPLBP_UpDownHillPT1TConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p001_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.001 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Up/Downhill detection PT1 time constant \n\n
 *		@ref P_ABPLBP_UpDownHillRSP_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Upper hysteresis threshold for up/downhill detetion evaluation \n\n
 *		@ref P_ABPLBP_UpDownHillShutOffLSP_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lower threshold for up/downhill detection (hysteresis LSP) \n\n
 *		@ref P_ABPLBP_UpDownHillShutOffRSP_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Upper threshold for up/downhill detection (hysteresis RSP) \n\n
 *		@ref P_ABPLBP_UseABDOverpassFlag_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use ABD dark-light transition flag (overpass issue) \n\n
 *		@ref P_ABPLBP_UseABDSineWave_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines usage of ABD interface sine wave road detection flag \n\n
 *		@ref P_ABPLBP_UseABDSlope_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines usage of ABD interface significant slope detection flag \n\n
 *		@ref P_ABPLBP_UseCBWeatherCond_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use CB weather condition information \n\n
 *		@ref P_ABPLBP_UseCrvEstRecal_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use re-calcuration for curve estimation after Kalman filter \n\n
 *		@ref P_ABPLBP_UseCrvEstSat_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		 \n\n
 *		@ref P_ABPLBP_UseCrvEstimation_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use second order polynomial fit curvature \n\n
 *		@ref P_ABPLBP_UseCrvKalman_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Activate curvature kalman filter \n\n
 *		@ref P_ABPLBP_UseGradientLimiter_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use gradient limitation \n\n
 *		@ref P_ABPLBP_UseLDAlgoCompState_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Decidesto use LD algo component state information \n\n
 *		@ref P_ABPLBP_UseLaneDynWeight_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use dynamic lane weighting of coupled/uncoupled lane \n\n
 *		@ref P_ABPLBP_UseLaneWidthGrad_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		use gradient limit logic for lane width before PT1 filter or don't use \n\n
 *		@ref P_ABPLBP_UseLatencyCompSIF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: Activates latency compensation implemented in the safety interface \n\n
 *		@ref P_ABPLBP_UseMaxValidLength_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use maximum lookahead distance of both lanes in case \n\n
 *		@ref P_ABPLBP_UseMotionComp_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use lane motion compensation \n\n
 *		@ref P_ABPLBP_UsePT1FilterSIF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: Activate lateral velocity PT1 filter for the latency compensation \n\n
 *		@ref P_ABPLBP_UsePitchingDtct_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Activate pitching detection observer \n\n
 *		@ref P_ABPLBP_UseStraightEstim_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use straight estimation based on feature point data \n\n
 *		@ref P_ABPLBP_UseSuppressBridged_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		suppress the judgement of invalid condition during another side is bridged \n\n
 *		@ref P_ABPLBP_UseUncoupABDQual_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use uncoupled lane quality from ABD interface in SIF \n\n
 *		@ref P_ABPLBP_UseUncoupLanesSIF_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use uncoupled raw lane data for safety interface (SIF) instead of ABPLBP fused lane data \n\n
 *		@ref P_ABPLBP_UseUncoupStepDtct_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines uncoupled lane step detection usage \n\n
 *		@ref P_ABPLBP_ValidCBWeatherCond_btf \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask selects weather condition information for evaluation \n
 *		 \n
 *		GB_HEAVY_RAIN_SNOW    (Bit 1) \n
 *		GB_HEAVY_FOG    (Bit 2) \n
 *		GB_HEAVY_GLARING_SUN    (Bit 3) \n
 *		GB_GLARING    (Bit 4) \n
 *		GB_RAIN    (Bit 5) \n
 *		GB_FOG    (Bit 6) \n\n
 *		@ref P_ABPLBP_ValidColorBitmask_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Defines valid lane marker colors: \n
 *		 \n
 *		ABD_MC_UNCLASSIFIED = 0  \n
 *		ABD_MC_WHITE = 1 \n
 *		ABD_MC_YELLOW = 2 \n
 *		ABD_MC_RED = 3 \n
 *		ABD_MC_BLUE = 4 \n
 *		ABD_MC_GREEN = 5 \n\n
 *		@ref P_ABPLBP_ValidLnTypeBitmask_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for valid lane marker type. \n\n
 *		@ref P_ABPLBP_YawAngleGrad_radps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Yaw angle gradient \n\n
 *		@ref X_ABPLBP_ThLnClthMinValLen_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		X-axis of the LUT for the minimum valid length of an input lane clothoid (in mps) \n\n
 *		@ref Y_ABPLBP_ThLnClthMinValLen_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Y-axis of the LUT for the minimum valid length of an input lane clothoid (in met) \n\n
 *		@ref Y_ABPLBP_ThMinValLenHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		Y-axis of the LUT for the minimum valid length of an input lane clothoid (hysteresis) \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: ABPLBP Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref ABPLBP_Testcase_Initialization) Initialization of the ABPLBP
 *		-# [Testcase_SignalFlow](@ref ABPLBP_Testcase_SignalFlow) Test for the correct signal flow in the module
 *		-# [Testcase_LaneChange](@ref ABPLBP_Testcase_LaneChange) Lane change detection test
 *		-# [Testcase_EgoLaneAvailability](@ref ABPLBP_Testcase_EgoLaneAvailability) Test ego lane availability validation
 *		-# [Testcase_EgoLaneType](@ref ABPLBP_Testcase_EgoLaneType) Test ego lane type validation
 *		-# [Testcase_EgoLaneColor](@ref ABPLBP_Testcase_EgoLaneColor) Test ego lane color validation
 *		-# [Testcase_EgoLaneStepDetection](@ref ABPLBP_Testcase_EgoLaneStepDetection) Test ego lane (+safety interface) step detection
 *		-# [Testcase_EgoLaneLength](@ref ABPLBP_Testcase_EgoLaneLength) Test ego lane valid length validation
 *		-# [Testcase_VirtualLine](@ref ABPLBP_Testcase_VirtualLine) Test virtual line concept
 *		-# [Testcase_LaneWidth](@ref ABPLBP_Testcase_LaneWidth) Lane width calculation test
 *		-# [Testcase_LaneWidthPT1Filter](@ref ABPLBP_Testcase_LaneWidthPT1Filter) Lane width PT1 filter test
 *		-# [Testcase_SafetyIfaceLateralDistLatencyCompensation](@ref ABPLBP_Testcase_SafetyIfaceLateralDistLatencyCompensation) Lateral distance latency compensation test (safety interface)
 *		-# [Testcase_CheckMapping](@ref ABPLBP_Testcase_CheckMapping) Check default mapping
 *		-# [Testcase_LaneKalmanFilter](@ref ABPLBP_Testcase_LaneKalmanFilter) Kalman filter mode testing
 *		-# [Testcase_EgoLaneTypeMapping](@ref ABPLBP_Testcase_EgoLaneTypeMapping) Internal mapping of the ego lane type
 *		-# [Testcase_ABDTimestamp](@ref ABPLBP_Testcase_ABDTimestamp) Conversion of the timestamp from usec to sec
 *		-# [Testcase_ConstructionSite](@ref ABPLBP_Testcase_ConstructionSite) Construction site detection
 *		-# [Testcase_LaneKalmanFilterValidity](@ref ABPLBP_Testcase_LaneKalmanFilterValidity) Kalman filter validation
 *		-# [Testcase_CrvQuality](@ref ABPLBP_Testcase_CrvQuality) Curvature quality computation
 *		-# [Testcase_LDVirtualLineQuality](@ref ABPLBP_Testcase_LDVirtualLineQuality) LD virtual line check in safety and comfort interface
 *		-# [Testcase_CurvatureEstimation](@ref ABPLBP_Testcase_CurvatureEstimation) Estimation of lane curvature
 *		-# [Testcase_LatDMCQualifier](@ref ABPLBP_Testcase_LatDMCQualifier) Qualifier for the lateral DMC
 *		-# [Testcase_MTSVisuQualifier](@ref ABPLBP_Testcase_MTSVisuQualifier) Qualifier for the MTS visualization
 *		-# [Testcase_LaneKalmanFilterProvidedInterface](@ref ABPLBP_Testcase_LaneKalmanFilterProvidedInterface) Check kalman filter output data if only one lane is valid
 *		-# [Testcase_SafetyIFaceHeadingAndCrv](@ref ABPLBP_Testcase_SafetyIFaceHeadingAndCrv) Test safety interface heading and curvature
 *		-# [Testcase_InputDataRangeChecks](@ref ABPLBP_Testcase_InputDataRangeChecks) Range check for input clothoid data
 *		-# [Testcase_OutputDataRangeChecks](@ref ABPLBP_Testcase_OutputDataRangeChecks) Range check for output clothoid data
 *		-# [Testcase_LateralDistanceStepDetection](@ref ABPLBP_Testcase_LateralDistanceStepDetection) Test lateral distance step detection
 *		-# [Testcase_CameraBlockageWeatherCondition](@ref ABPLBP_Testcase_CameraBlockageWeatherCondition) Check camera blockage weather condition
 *		-# [Testcase_LDAlgoComponentState](@ref ABPLBP_Testcase_LDAlgoComponentState) Check lane detection algo component state
 *		-# [Testcase_LaneQualityCalculation](@ref ABPLBP_Testcase_LaneQualityCalculation) Test lane quality calculation
 *		-# [Testcase_LaneMotionCompensation](@ref ABPLBP_Testcase_LaneMotionCompensation) Test lane data motion compensation
 *		-# [Testcase_PolyfitLCF](@ref ABPLBP_Testcase_PolyfitLCF) Polyfit s-function
 *		-# [Testcase_CrvKalmanFilter](@ref ABPLBP_Testcase_CrvKalmanFilter) Curvature kalman filter mode testing
 *		-# [Testcase_SlopeChangeDetection](@ref ABPLBP_Testcase_SlopeChangeDetection) Slope change detection
 *		-# [Testcase_PitchingDetection](@ref ABPLBP_Testcase_PitchingDetection) Pitching detection
 *		-# [Testcase_StraightDetection](@ref ABPLBP_Testcase_StraightDetection) Ego lane straight detection
 *		-# [Testcase_UncoupledLaneStepDetection](@ref ABPLBP_Testcase_UncoupledLaneStepDetection) Uncoupled lane step detection
 *		-# [Testcase_UncoupledLaneExitDetection](@ref ABPLBP_Testcase_UncoupledLaneExitDetection) Uncoupled lane Exit detection
 *		-# [Testcase_OverpassDetection](@ref ABPLBP_Testcase_OverpassDetection) Overpass detection
 *		-# [Testcase_newFeatures](@ref ABPLBP_Testcase_newFeatures) TBD test for new features
 *		
 *	@traceability
 *		[\@link: ABPLBP Module Requirements]()
 */
extern void ABPLBP_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // ABPLBP_H_
