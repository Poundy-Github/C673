/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPREP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPREP.h
//! @brief     (ABPREP) Module Header.

#ifndef ABPREP_H_
#define ABPREP_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "ABPREP_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	ABPREP module sensor initialization function. Function initializes ABPREP sensor debug data pointer.
 *	
 *	@param
 *		[in] ABPREP_SenDbgArg Pointer to ABPREP sensor debug data.
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
extern void ABPREP_SenInitDbgPtr(ABPREP_SenDbgType *ABPREP_SenDbgArg);

/*!
 *	ABPREP module sensor initialization function. Function initializes ABPREP sensor output data pointer.
 *	
 *	@param
 *		[in] ABPREP_SenOutArg Pointer to ABPREP sensor output data.
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
extern void ABPREP_SenInitOutPtr(ABPREP_SenOutType *ABPREP_SenOutArg);

/*!
 *	ABPREP module sensor reset function.
 *	
 *	@pre
 *		- The ABPREP sensor initialization function(s) must be called once.
 *		- The ABPREP sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [S_ABPREP_LaneStabilization_btf](@ref ABPREP_SenDbgType::S_ABPREP_LaneStabilization_btf) \n
 *		[Debug  Signal] [S_ABPREP_LeReClthCrvChng_1pm2](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthCrvChng_1pm2) \n
 *		[Debug  Signal] [S_ABPREP_LeReClthCrvSIF_1pm](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthCrvSIF_1pm) \n
 *		[Debug  Signal] [S_ABPREP_LeReClthCrv_1pm](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthCrv_1pm) \n
 *		[Debug  Signal] [S_ABPREP_LeReClthHeadingSIF_rad](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthHeadingSIF_rad) \n
 *		[Debug  Signal] [S_ABPREP_LeReClthPosY0SIF_met](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthPosY0SIF_met) \n
 *		[Debug  Signal] [S_ABPREP_LeReHeading_rad](@ref ABPREP_SenDbgType::S_ABPREP_LeReHeading_rad) \n
 *		[Debug  Signal] [S_ABPREP_LeReInvalidQuSIF_btf](@ref ABPREP_SenDbgType::S_ABPREP_LeReInvalidQuSIF_btf) \n
 *		[Debug  Signal] [S_ABPREP_LeReInvalidQu_btf](@ref ABPREP_SenDbgType::S_ABPREP_LeReInvalidQu_btf) \n
 *		[Debug  Signal] [S_ABPREP_LeReKFQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_LeReKFQuality_perc) \n
 *		[Debug  Signal] [S_ABPREP_LeReKFStatus_enum](@ref ABPREP_SenDbgType::S_ABPREP_LeReKFStatus_enum) \n
 *		[Debug  Signal] [S_ABPREP_LeReLatVel_mps](@ref ABPREP_SenDbgType::S_ABPREP_LeReLatVel_mps) \n
 *		[Debug  Signal] [S_ABPREP_LeReLength_met](@ref ABPREP_SenDbgType::S_ABPREP_LeReLength_met) \n
 *		[Debug  Signal] [S_ABPREP_LeRePosY0_met](@ref ABPREP_SenDbgType::S_ABPREP_LeRePosY0_met) \n
 *		[Debug  Signal] [S_ABPREP_LeReQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_LeReQuality_perc) \n
 *		[Debug  Signal] [S_ABPREP_LnBndGradLimActive_btf](@ref ABPREP_SenDbgType::S_ABPREP_LnBndGradLimActive_btf) \n
 *		[Debug  Signal] [S_ABPREP_RiReClthCrvChng_1pm2](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthCrvChng_1pm2) \n
 *		[Debug  Signal] [S_ABPREP_RiReClthCrvSIF_1pm](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthCrvSIF_1pm) \n
 *		[Debug  Signal] [S_ABPREP_RiReClthCrv_1pm](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthCrv_1pm) \n
 *		[Debug  Signal] [S_ABPREP_RiReClthHeadingSIF_rad](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthHeadingSIF_rad) \n
 *		[Debug  Signal] [S_ABPREP_RiReClthPosY0SIF_met](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthPosY0SIF_met) \n
 *		[Debug  Signal] [S_ABPREP_RiReHeading_rad](@ref ABPREP_SenDbgType::S_ABPREP_RiReHeading_rad) \n
 *		[Debug  Signal] [S_ABPREP_RiReInvalidQuSIF_btf](@ref ABPREP_SenDbgType::S_ABPREP_RiReInvalidQuSIF_btf) \n
 *		[Debug  Signal] [S_ABPREP_RiReInvalidQu_btf](@ref ABPREP_SenDbgType::S_ABPREP_RiReInvalidQu_btf) \n
 *		[Debug  Signal] [S_ABPREP_RiReKFQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_RiReKFQuality_perc) \n
 *		[Debug  Signal] [S_ABPREP_RiReKFStatus_enum](@ref ABPREP_SenDbgType::S_ABPREP_RiReKFStatus_enum) \n
 *		[Debug  Signal] [S_ABPREP_RiReLatVel_mps](@ref ABPREP_SenDbgType::S_ABPREP_RiReLatVel_mps) \n
 *		[Debug  Signal] [S_ABPREP_RiReLength_met](@ref ABPREP_SenDbgType::S_ABPREP_RiReLength_met) \n
 *		[Debug  Signal] [S_ABPREP_RiRePosY0_met](@ref ABPREP_SenDbgType::S_ABPREP_RiRePosY0_met) \n
 *		[Debug  Signal] [S_ABPREP_RiReQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_RiReQuality_perc) \n
 *		[Output Signal] [S_ABPREP_LeReClthPosX0_met](@ref ABPREP_SenOutType::S_ABPREP_LeReClthPosX0_met) \n
 *		[Output Signal] [S_ABPREP_RiReClthPosX0_met](@ref ABPREP_SenOutType::S_ABPREP_RiReClthPosX0_met) \n\n
 *		For signal details, see sub-section [Globals](@ref ABPREP_SenProcess_Globals) of the function @ref ABPREP_SenProcess.
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
extern void ABPREP_SenReset(void);

/*!
 *	ABPREP module sensor process function.
 *	
 *	@pre
 *		- The ABPREP sensor initialization function(s) must be called once.
 *		- The ABPREP sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor ABPREP_SenProcess_Globals
 *		[S_ABPREP_LaneStabilization_btf](@ref ABPREP_SenDbgType::S_ABPREP_LaneStabilization_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield determines lane stabilization \n
 *		Bit0: LeReStabilized; \n
 *		Bit1: RiReSTabilized; \n
 *		Bit2: LeReSIFStabilized; \n
 *		Bit3: RiReSIFStabilized; \n\n
 *		[S_ABPREP_LeReClthCrvChng_1pm2](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left road edge clothoid curvature rate \n\n
 *		[S_ABPREP_LeReClthCrvSIF_1pm](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthCrvSIF_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left road edge clothoid curvature (safety interface) \n\n
 *		[S_ABPREP_LeReClthCrv_1pm](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left road edge clothoid curvature \n\n
 *		[S_ABPREP_LeReClthHeadingSIF_rad](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthHeadingSIF_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left road edge clothoid yaw angle (safety interface) \n\n
 *		[S_ABPREP_LeReClthPosY0SIF_met](@ref ABPREP_SenDbgType::S_ABPREP_LeReClthPosY0SIF_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left road edge clothoid lateral distance (safety interface) \n\n
 *		[S_ABPREP_LeReHeading_rad](@ref ABPREP_SenDbgType::S_ABPREP_LeReHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left road edge clothoid yaw angle \n\n
 *		[S_ABPREP_LeReInvalidQuSIF_btf](@ref ABPREP_SenDbgType::S_ABPREP_LeReInvalidQuSIF_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Left road edge clothoid invalid qualifier (safety interface); \n
 *		 \n
 *		Bit 0: Lateral distance jump debounced; \n
 *		Bit 1: Yaw angle jump debounce; \n
 *		Bit 2: Curvature jump debounced; \n
 *		Bit 3: Quality invalid \n
 *		Bit 4: Bridging \n\n
 *		[S_ABPREP_LeReInvalidQu_btf](@ref ABPREP_SenDbgType::S_ABPREP_LeReInvalidQu_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit 0: Road edge availability invalid \n
 *		Bit 1: Existence probability invalid \n
 *		Bit 2: Road edge type invalid \n
 *		Bit 3: Road edge minimum length invalid \n
 *		Bit 4: Lateral distance step debounced \n
 *		Bit 5: Heading step debounced \n
 *		Bit 6: Curvature step debounced \n
 *		Bit 7: Curvature rate step debounced \n
 *		Bit 8: Lateral distance out of range \n
 *		Bit 9:  Yaw angle out of range \n
 *		Bit 10: Curvature out of range \n
 *		Bit 11: Curvature rate out of range \n
 *		Bit 12: Valid length out of range \n
 *		Bit 13: Road Edge bridging \n
 *		Bit 14: Road Kalman Filter not valid \n\n
 *		[S_ABPREP_LeReKFQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_LeReKFQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Leftroad edge kalman filter quality \n\n
 *		[S_ABPREP_LeReKFStatus_enum](@ref ABPREP_SenDbgType::S_ABPREP_LeReKFStatus_enum) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_ABPLBP_KalmanStatusType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Left road edge kalman filter status \n
 *		 \n
 *		0: not valid \n
 *		1: full update \n
 *		2: degraded update \n
 *		3: predict \n
 *		4: init \n
 *		5: reset \n\n
 *		[S_ABPREP_LeReLatVel_mps](@ref ABPREP_SenDbgType::S_ABPREP_LeReLatVel_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Left road edge lateral veloctiy \n\n
 *		[S_ABPREP_LeReLength_met](@ref ABPREP_SenDbgType::S_ABPREP_LeReLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left road edge clothoid length (lookahead distance) \n\n
 *		[S_ABPREP_LeRePosY0_met](@ref ABPREP_SenDbgType::S_ABPREP_LeRePosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left road edge clothoid lateral distance (Y0 position) \n\n
 *		[S_ABPREP_LeReQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_LeReQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Left road edge quality \n\n
 *		[S_ABPREP_LnBndGradLimActive_btf](@ref ABPREP_SenDbgType::S_ABPREP_LnBndGradLimActive_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Gradient limiter active bitfield: \n
 *		 \n
 *		Bit 0: Left lateral position gradient limiter active \n
 *		Bit 1: Left yaw angle gradient limiter active \n
 *		Bit 2: Left curvature gradient limiter active \n
 *		Bit 3: Left curvature rate gradient limiter active \n
 *		Bit 4: Right lateral position gradient limiter active \n
 *		Bit 5: Right heading angle gradient limiter active \n
 *		Bit 6: Right curvature gradient limiter active \n
 *		Bit 7: Right curvature rate gradient limiter active \n\n
 *		[S_ABPREP_RiReClthCrvChng_1pm2](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right road edge clothoid curvature rate \n\n
 *		[S_ABPREP_RiReClthCrvSIF_1pm](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthCrvSIF_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right road edge clothoid curvature (safety interface); \n\n
 *		[S_ABPREP_RiReClthCrv_1pm](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right road edge clothoid curvature \n\n
 *		[S_ABPREP_RiReClthHeadingSIF_rad](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthHeadingSIF_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right road edge clothoid yaw angle (safety interface); \n\n
 *		[S_ABPREP_RiReClthPosY0SIF_met](@ref ABPREP_SenDbgType::S_ABPREP_RiReClthPosY0SIF_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right road edge clothoid lateral distance (safety interface); \n\n
 *		[S_ABPREP_RiReHeading_rad](@ref ABPREP_SenDbgType::S_ABPREP_RiReHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right road edge clothoid yaw angle \n\n
 *		[S_ABPREP_RiReInvalidQuSIF_btf](@ref ABPREP_SenDbgType::S_ABPREP_RiReInvalidQuSIF_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Right road edge clothoid invalid qualifier (safety interface); \n
 *		 \n
 *		Bit 0: Lateral distance jump debounced; \n
 *		Bit 1: Yaw angle jump debounce; \n
 *		Bit 2: Curvature jump debounced; \n
 *		Bit 3: Quality invalid \n
 *		Bit 4: Bridging \n\n
 *		[S_ABPREP_RiReInvalidQu_btf](@ref ABPREP_SenDbgType::S_ABPREP_RiReInvalidQu_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Right invalid road edge qualifier. \n
 *		Bit 0: Road edge availability invalid \n
 *		Bit 1: Existence probability invalid \n
 *		Bit 2: Road edge type invalid \n
 *		Bit 3: Road edge minimum length invalid \n
 *		Bit 4: Lateral distance step debounced \n
 *		Bit 5: Heading step debounced \n
 *		Bit 6: Curvature step debounced \n
 *		Bit 7: Curvature rate step debounced \n
 *		Bit 8: Lateral distance out of range \n
 *		Bit 9:  Yaw angle out of range \n
 *		Bit 10: Curvature out of range \n
 *		Bit 11: Curvature rate out of range \n
 *		Bit 12: Valid length out of range \n
 *		Bit 13: Road Edge bridging \n
 *		Bit 14: Road Kalman Filter not valid \n\n
 *		[S_ABPREP_RiReKFQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_RiReKFQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Right road edge kalman filter quality \n\n
 *		[S_ABPREP_RiReKFStatus_enum](@ref ABPREP_SenDbgType::S_ABPREP_RiReKFStatus_enum) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_ABPLBP_KalmanStatusType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Right road edge kalman filter status \n
 *		 \n
 *		0: not valid \n
 *		1: full update \n
 *		2: degraded update \n
 *		3: predict \n
 *		4: init \n
 *		5: reset \n\n
 *		[S_ABPREP_RiReLatVel_mps](@ref ABPREP_SenDbgType::S_ABPREP_RiReLatVel_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Right road edge lateral veloctiy \n\n
 *		[S_ABPREP_RiReLength_met](@ref ABPREP_SenDbgType::S_ABPREP_RiReLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right road edge clothoid length (lookahead distance) \n\n
 *		[S_ABPREP_RiRePosY0_met](@ref ABPREP_SenDbgType::S_ABPREP_RiRePosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right road edge clothoid lateral distance (Pos Y0) \n\n
 *		[S_ABPREP_RiReQuality_perc](@ref ABPREP_SenDbgType::S_ABPREP_RiReQuality_perc) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Right road edge quality \n\n
 *		[S_ABPREP_LeReClthPosX0_met](@ref ABPREP_SenOutType::S_ABPREP_LeReClthPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left road edge clothoid X0 coordinate \n\n
 *		[S_ABPREP_RiReClthPosX0_met](@ref ABPREP_SenOutType::S_ABPREP_RiReClthPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right road edge clothoid X0 coordinate \n\n
 *		@ref S_ABPLBP_LeLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left lane clothoid change of curvature \n\n
 *		@ref S_ABPLBP_LeLnClthCrvSIF_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left lane clothoid curvature (safety interface) \n\n
 *		@ref S_ABPLBP_LeLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left lane clothoid curvature \n\n
 *		@ref S_ABPLBP_LeLnClthHeadingSIF_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left lane clothoid heading angle (safety interface) \n\n
 *		@ref S_ABPLBP_LeLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left lane clothoid heading angle \n\n
 *		@ref S_ABPLBP_LeLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid length \n\n
 *		@ref S_ABPLBP_LeLnClthPosY0SIF_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (safety interface) \n\n
 *		@ref S_ABPLBP_LeLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (init +10m) \n\n
 *		@ref S_ABPLBP_LeLnInvalidQuSIF_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ABPLBP_LeLnInvalidQu_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ABPLBP_RiLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right lane clothoid curvature change \n\n
 *		@ref S_ABPLBP_RiLnClthCrvSIF_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right lane clothoid curvature (safety interface) \n\n
 *		@ref S_ABPLBP_RiLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right lane clothoid curvature \n\n
 *		@ref S_ABPLBP_RiLnClthHeadingSIF_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right lane clothoid heading angle \n\n
 *		@ref S_ABPLBP_RiLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right lane clothoid heading angle \n\n
 *		@ref S_ABPLBP_RiLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid length \n\n
 *		@ref S_ABPLBP_RiLnClthPosY0SIF_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (safety interface) \n\n
 *		@ref S_ABPLBP_RiLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (init -10m) \n\n
 *		@ref S_ABPLBP_RiLnInvalidQuSIF_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ABPLBP_RiLnInvalidQu_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_LCFRCV_AnyBndAvailable_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Defines whether a lane boundary track is available or not. If the flag is set to 0, the other parameters might either remain constant or change over time. The parameters will not be reset to default values in case that a track gets lost. The parameters must not be used if this value is 0. \n\n
 *		@ref S_LCFRCV_AnyBndCrvRate_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Curvature rate of a lane boundary track w.r.t. the used coordinate system. \n\n
 *		@ref S_LCFRCV_AnyBndCurvature_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature of a lane boundary track w.r.t. the used coordinate system \n\n
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
 *		@ref S_LCFRCV_AnyBndValidLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x10x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Visibility range of a lane boundary track. This value is calculated using the features associated to the track. A lane boundary track can be considered as accurate up to this distance. Evaluating the polynomial at a longitudinal distance larger than this value results in an extrapolation and might lead to inaccurate lateral distances. \n\n
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
 *		@ref P_ABPREP_CrvLimStepDtct_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Curvature limit for the step detection \n\n
 *		@ref P_ABPREP_CrvRateLimStepDtct_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Threshold for step detection in lane marker curvature change \n\n
 *		@ref P_ABPREP_DefaultRoadWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Default road width for virtual road edge building \n\n
 *		@ref P_ABPREP_DistYLimitStepDtct_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lateral postion limit for the step detection \n\n
 *		@ref P_ABPREP_DurValidCrvRateStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Indicates how long a step in the curvature rate is debounced \n\n
 *		@ref P_ABPREP_DurValidCrvStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Indicates how long a step in the curvature is debounced \n\n
 *		@ref P_ABPREP_DurValidDistYStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Indicates how long a step in the lateral postition is stored \n\n
 *		@ref P_ABPREP_DurValidHeadingStep_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Indicates how long a step in the heading angle is debounced \n\n
 *		@ref P_ABPREP_HeadLimStepDtct_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Heading limit for the step detection \n\n
 *		@ref P_ABPREP_KalmanMinQuality_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum kalman filter quality \n\n
 *		@ref P_ABPREP_Lane2ReDistThresh_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Distance threshold between road edge and lanes for road edge stabilization with lane data \n\n
 *		@ref P_ABPREP_LaneKFDecQualDeg_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality decrease for the lane kalman filter after the degraded update step has been applied \n\n
 *		@ref P_ABPREP_LaneKFDecQualPred_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality decrease for the lane kalman filter after only a prediction step has been applied \n\n
 *		@ref P_ABPREP_LaneKFDegrUpdateQu_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality threshold for degraded update in center lane kalman filter \n\n
 *		@ref P_ABPREP_LaneKFDegrUpdate_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use degraded update in center lane kalman filter \n\n
 *		@ref P_ABPREP_LaneKFDegradeWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0p0001_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0.0001 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Weight for degraded update_laneKF \n\n
 *		@ref P_ABPREP_LaneKFDynCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor to control the curvature signal dynamics in lane center kalman filter \n\n
 *		@ref P_ABPREP_LaneKFDynCrvRtFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor to control the curvature signal dynamics in lane center kalman filter \n\n
 *		@ref P_ABPREP_LaneKFDynDistYFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor needed to set the dynamic of the lateral distance within the prediction step; \n
 *		100000.0f High Dynamic, 10000.0f Middle Dynamic, <1000.0f Low Dynamic \n\n
 *		@ref P_ABPREP_LaneKFDynYawFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Factor needed to set the dynamic of the yaw angle within the prediction step \n\n
 *		@ref P_ABPREP_LaneKFErrCoeff1_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_3p4E38_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 3.4E+38 \n
 *		\@description: \n
 *		Geometric model error (kappa2diff) calculation factor 1 - [minimum radius european highway] \n\n
 *		@ref P_ABPREP_LaneKFErrCoeff2_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Geometric model error (kappa2diff) calculation factor 2 - [average ego vehicle velocity highway] \n\n
 *		@ref P_ABPREP_LaneKFIncQual_1ps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_Pers_1_10000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/s \n
 *		\@min: 1 \n
 *		\@max: 10000 \n
 *		\@description: \n
 *		Quality increase for the lane kalman filter after the update step has been applied \n\n
 *		@ref P_ABPREP_LaneKFInitRFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Initialization factor for R_laneKF matrix -> achieve better transient oscillation \n\n
 *		@ref P_ABPREP_LaneKFKGainFac_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Factor needed to set the dynamic of the lateral position within degraded update \n\n
 *		@ref P_ABPREP_LaneKFMnInitQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum measurement quality for the kalman filter initialization \n\n
 *		@ref P_ABPREP_LaneKFMnUpdateQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum measurement quality to apply kalman filter update step. If the measurement quality is below only the prediction step is applied. \n\n
 *		@ref P_ABPREP_LaneKFStdDevCrvRt_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Center lane curvature rate standard deviation \n\n
 *		@ref P_ABPREP_LaneKFStdDevCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.5 \n
 *		\@description: \n
 *		Center lane curvature standard deviation \n\n
 *		@ref P_ABPREP_LaneKFStdDevLatDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Center lane lateral distance standard deviation \n\n
 *		@ref P_ABPREP_LaneKFStdDevYawRt_radps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Center lane yaw rate standard deviation \n\n
 *		@ref P_ABPREP_LaneKFStdDevYaw_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Center lane yaw angle standard deviation \n\n
 *		@ref P_ABPREP_LaneMaxCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum curvature for lane bridging \n\n
 *		@ref P_ABPREP_LatVelPT1TimeConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral velocity PT1 time constant \n\n
 *		@ref P_ABPREP_MaxCrvChngGrad_1psm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms2_0_0p1_1em7_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Gradient for the road edge curvature change \n\n
 *		@ref P_ABPREP_MaxCrvGrad_1pms \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pms_0_5_1em7_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/ms \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Gradient for the road edge curvature \n\n
 *		@ref P_ABPREP_MaxCrvRateRange_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum range check value for curvature rate \n\n
 *		@ref P_ABPREP_MaxCurvatureRange_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum range check value for curvature \n\n
 *		@ref P_ABPREP_MaxDistYGrad_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Gradient for the road edge distance \n\n
 *		@ref P_ABPREP_MaxDistYRange_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum range check value for lateral position \n\n
 *		@ref P_ABPREP_MaxHeadingGrad_radps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_radps_0_1p5_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad/s \n
 *		\@min: 0 \n
 *		\@max: 1.5 \n
 *		\@description: \n
 *		Gradient for the road edge yaw angle \n\n
 *		@ref P_ABPREP_MaxHeadingRange_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximum range check value for yaw angle \n\n
 *		@ref P_ABPREP_MaxLaneBridgingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum road edge bridging time \n\n
 *		@ref P_ABPREP_MaxLatDistStabilize_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum lateral distance for opposite lane stabilization \n\n
 *		@ref P_ABPREP_MaxRangeHyst_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Maximum range check hysteresis factor \n\n
 *		@ref P_ABPREP_MaxValidLengthRange_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum range check value valid length \n\n
 *		@ref P_ABPREP_MinLatDistStabilize_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum lateral distance for opposite lane stabilization \n\n
 *		@ref P_ABPREP_MinRoadEdgeABDQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum road edge quality (ABD input quality threhold \n\n
 *		@ref P_ABPREP_MinRoadEdgeQualLSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lower (LSP) quality hysteresis threshold \n\n
 *		@ref P_ABPREP_MinRoadEdgeQualRSP_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Upper (RSP) quality hysteresis threshold \n\n
 *		@ref P_ABPREP_MinVelForKalmanFilt_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum kalman filter input velocity to avoid internal matrix inversion failures \n\n
 *		@ref P_ABPREP_ReQualCrvMaxTh_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality calculation maximum curvature step threshold \n\n
 *		@ref P_ABPREP_ReQualCrvMinTh_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality calculation minimum curvature step threshold \n\n
 *		@ref P_ABPREP_ReQualCrvRateMaxTh_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality calculation maximum curvature rate step threshold \n\n
 *		@ref P_ABPREP_ReQualCrvRateMinTh_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_0_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Quality calculation minimum curvature rate step threshold \n\n
 *		@ref P_ABPREP_ReQualCrvRateWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation curvature rate penalty weighting factor \n\n
 *		@ref P_ABPREP_ReQualCrvWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation curvature penalty weighting factor \n\n
 *		@ref P_ABPREP_ReQualDistanceMaxTh_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Quality calculation maximum distance step threshold \n\n
 *		@ref P_ABPREP_ReQualDistanceMinTh_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Quality calculation maximum distance step threshold \n\n
 *		@ref P_ABPREP_ReQualDistanceWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation lateral distance penalty weighting factor \n\n
 *		@ref P_ABPREP_ReQualGradLimLD_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Quality calculation gradient limiter lower threshold \n\n
 *		@ref P_ABPREP_ReQualGradLimLU_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation gradient limiter upper threshold \n\n
 *		@ref P_ABPREP_ReQualHeadingMaxTh_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Quality calculation maximum heading step threshold \n\n
 *		@ref P_ABPREP_ReQualHeadingMinTh_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Quality calculation minimum heading step threshold \n\n
 *		@ref P_ABPREP_ReQualHeadingWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation heading penalty weighting factor \n\n
 *		@ref P_ABPREP_ReQualPenFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation penalty factor \n\n
 *		@ref P_ABPREP_ReQualPenGradLimLD_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m10000000_10000000_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -10000000 \n
 *		\@max: 10000000 \n
 *		\@description: \n
 *		Quality calculation penalty gradient limiter lower threshold \n\n
 *		@ref P_ABPREP_ReQualPenGradLimLU_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation penalty gradient limiter lower threshold \n\n
 *		@ref P_ABPREP_ReQualPenHoldFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_100000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100000 \n
 *		\@description: \n
 *		Quality calculation penalty hold factor \n\n
 *		@ref P_ABPREP_ReQualValidLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality calculation lookahead distance threshold \n\n
 *		@ref P_ABPREP_SIFJumpDebounceT_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Safety interface jump debounce time for yaw angle, lateral distance and curvature signals. \n\n
 *		@ref P_ABPREP_SIFLatencyTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Time contant for latency time compensation of lateral displacement \n\n
 *		@ref P_ABPREP_SIFPT1TimeConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p06_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.06 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant for lateral velocity lowpass filter \n\n
 *		@ref P_ABPREP_SIFUseKalmanHead_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use kalman filter safety heading \n\n
 *		@ref P_ABPREP_SIFUseLatVelPT1Flt_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines if PT1 filter for the lateral velocity is active \n\n
 *		@ref P_ABPREP_SIFUseLatencyComp_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates if latency compensation should be used for the lateral displacement \n\n
 *		@ref P_ABPREP_StabilizeWithLanes_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Determines if road edges are stabilized with lane data \n\n
 *		@ref P_ABPREP_UseCBWeatherCond_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use CB (camera blockage) weather condition check \n\n
 *		@ref P_ABPREP_UseGradientLimiter_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: Activate output data gradient limiter \n\n
 *		@ref P_ABPREP_UseLDAlgoCompState_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use LD algo component state check \n\n
 *		@ref P_ABPREP_UseLatVelPT1Filter_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Use lateral velocity kalman filter \n\n
 *		@ref P_ABPREP_UseRoadEdgeKalman_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Activates road edge kalman filter \n\n
 *		@ref P_ABPREP_UseRoadEdgeQuality_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Activates internal calculated quality \n\n
 *		@ref P_ABPREP_ValidCBWeatherCond_btf \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask selects weather condition information for evaluation \n
 *		 \n
 *		GB_HEAVY_RAIN_SNOW    (Bit 1) \n
 *		GB_HEAVY_FOG    (Bit 2) \n
 *		GB_HEAVY_GLARING_SUN    (Bit 3) \n
 *		GB_GLARING    (Bit 4) \n
 *		GB_RAIN    (Bit 5) \n
 *		GB_FOG    (Bit 6) \n\n
 *		@ref P_ABPREP_ValidReTypeBitmask_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Valid Road edge bitmask. \n\n
 *		@ref X_ABPLBP_ThLnClthMinValLen_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_0_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m/s \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		X-axis of the LUT for the minimum valid length of an input lane clothoid (in mps) \n\n
 *		@ref Y_ABPREP_ThReClthMinValLen_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Y-axis of the LUT for the minimum valid length of an input lane clothoid (in met) \n\n
 *		@ref Y_ABPREP_ThReMinValLenHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum road edge valid length hysteresis \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: ABPREP Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref ABPREP_Testcase_Initialization) Initialization of the ABPREP
 *		-# [Testcase_SignalFlow](@ref ABPREP_Testcase_SignalFlow) Test for correct signal flow of the module
 *		-# [Testcase_TypeEnumMapping](@ref ABPREP_Testcase_TypeEnumMapping) ABRPEP_TypeEnumMapping
 *		-# [Testcase_DefaultData](@ref ABPREP_Testcase_DefaultData) Test default data output in case of any kind of invalid road edge data
 *		-# [Testcase_RoadEdgeAvailability](@ref ABPREP_Testcase_RoadEdgeAvailability) Test road edge availability validation
 *		-# [Testcase_RoadEdgeQualityValidation](@ref ABPREP_Testcase_RoadEdgeQualityValidation) Test road edge quality validation
 *		-# [Testcase_RoadEdgeLength](@ref ABPREP_Testcase_RoadEdgeLength) Test road edge valid length validation
 *		-# [Testcase_RoadEdgeType](@ref ABPREP_Testcase_RoadEdgeType) Test road edge type validation
 *		-# [Testcase_RoadEdgeStepDetection](@ref ABPREP_Testcase_RoadEdgeStepDetection) Test road edge step detection validation
 *		-# [Testcase_RoadEdgeSafetyDistYLatCompensation](@ref ABPREP_Testcase_RoadEdgeSafetyDistYLatCompensation) Test road edge lateral position latency compensation (safety interface)
 *		-# [Testcase_RoadEdgeStabilizeWithEgoLaneData](@ref ABPREP_Testcase_RoadEdgeStabilizeWithEgoLaneData) Test road edge stabilization with valid ego lane data
 *		-# [Testcase_RoadEdgeValidOneSided](@ref ABPREP_Testcase_RoadEdgeValidOneSided) Test output data in case of only one side valid road edge
 *		-# [Testcase_RoadEdgeGradientLimiter](@ref ABPREP_Testcase_RoadEdgeGradientLimiter) Test road edge output gradient limitation
 *		-# [Testcase_RoadEdgeRangeChecks](@ref ABPREP_Testcase_RoadEdgeRangeChecks) Test road edge input data range checks
 *		-# [Testcase_RoadEdgeKalmanFilter](@ref ABPREP_Testcase_RoadEdgeKalmanFilter) Road edge kalman filter filter mode testing
 *		-# [Testcase_RoadEdgeKalmanFilterProvidedInterface](@ref ABPREP_Testcase_RoadEdgeKalmanFilterProvidedInterface) Check kalman filter output data if only one lane is valid
 *		-# [Testcase_RoadEdgeKalmanFilterValidity](@ref ABPREP_Testcase_RoadEdgeKalmanFilterValidity) Kalman filter validation
 *		-# [Testcase_CameraBlockageWeatherCondition](@ref ABPREP_Testcase_CameraBlockageWeatherCondition) Check camera blockage weather condition
 *		-# [Testcase_LDAlgoComponentState](@ref ABPREP_Testcase_LDAlgoComponentState) Check lane detection algo component state
 *		-# [Testcase_RoadEdgeQualityCalculation](@ref ABPREP_Testcase_RoadEdgeQualityCalculation) Test road edge quality calculation
 *		-# [Testcase_RoadEdgeBridging](@ref ABPREP_Testcase_RoadEdgeBridging) Check road edge bridging
 *		-# [Testcase_RoadEdgeStabilizeWithLaneDataSIF](@ref ABPREP_Testcase_RoadEdgeStabilizeWithLaneDataSIF) SIF Test road edge stabilization with valid ego lane data
 *		-# [Testcase_RoadEdgeBridgingSIF](@ref ABPREP_Testcase_RoadEdgeBridgingSIF) SIF Check road edge bridging
 *		-# [Testcase_LateralVelocity](@ref ABPREP_Testcase_LateralVelocity) Check lateral velocity calculation
 *		-# [Testcase_Coverage](@ref ABPREP_Testcase_Coverage) Check road edge bridging
 *		
 *	@traceability
 *		[\@link: ABPREP Module Requirements]()
 */
extern void ABPREP_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // ABPREP_H_
