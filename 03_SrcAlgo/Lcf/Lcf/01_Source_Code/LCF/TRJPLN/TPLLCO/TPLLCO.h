/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLLCO
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLLCO.h
//! @brief     (TPLLCO) Module Header.

#ifndef TPLLCO_H_
#define TPLLCO_H_

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
 *	TPLLCO module vehicle initialization function. Function initializes TPLLCO vehicle debug data pointer.
 *	
 *	@param
 *		[in] TPLLCO_VehDbgArg Pointer to TPLLCO vehicle debug data.
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
extern void TPLLCO_VehInitDbgPtr(TPLLCO_VehDbgType *TPLLCO_VehDbgArg);

/*!
 *	TPLLCO module vehicle initialization function. Function initializes TPLLCO vehicle output data pointer.
 *	
 *	@param
 *		[in] TPLLCO_VehOutArg Pointer to TPLLCO vehicle output data.
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
extern void TPLLCO_VehInitOutPtr(TPLLCO_VehOutType *TPLLCO_VehOutArg);

/*!
 *	TPLLCO module vehicle reset function.
 *	
 *	@pre
 *		- The TPLLCO vehicle initialization function(s) must be called once.
 *		- The TPLLCO vehicle debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TPLLCO_CCCDeviation_met](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCDeviation_met) \n
 *		[Debug  Signal] [D_TPLLCO_CCCInvalid_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCInvalid_nu) \n
 *		[Debug  Signal] [D_TPLLCO_CCCLength_met](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCLength_met) \n
 *		[Debug  Signal] [D_TPLLCO_CCCPassedPerc_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCPassedPerc_nu) \n
 *		[Debug  Signal] [D_TPLLCO_CCCReset_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCReset_nu) \n
 *		[Debug  Signal] [D_TPLLCO_CCCTestPointDistX_met](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCTestPointDistX_met) \n
 *		[Debug  Signal] [D_TPLLCO_CCCWarning_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCWarning_nu) \n
 *		[Debug  Signal] [D_TPLLCO_DeltaProjPosX_met](@ref TPLLCO_VehDbgType::D_TPLLCO_DeltaProjPosX_met) \n
 *		[Debug  Signal] [D_TPLLCO_DeltaProjPosY_met](@ref TPLLCO_VehDbgType::D_TPLLCO_DeltaProjPosY_met) \n
 *		[Debug  Signal] [D_TPLLCO_EgoDistYPre_met](@ref TPLLCO_VehDbgType::D_TPLLCO_EgoDistYPre_met) \n
 *		[Debug  Signal] [D_TPLLCO_EgoHeadingPre_rad](@ref TPLLCO_VehDbgType::D_TPLLCO_EgoHeadingPre_rad) \n
 *		[Debug  Signal] [D_TPLLCO_LeCridrTransDev_met](@ref TPLLCO_VehDbgType::D_TPLLCO_LeCridrTransDev_met) \n
 *		[Debug  Signal] [D_TPLLCO_PlausiCheckStatus_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_PlausiCheckStatus_nu) \n
 *		[Debug  Signal] [D_TPLLCO_RiCridrTransDev_met](@ref TPLLCO_VehDbgType::D_TPLLCO_RiCridrTransDev_met) \n
 *		[Debug  Signal] [D_TPLLCO_RightOri_rad](@ref TPLLCO_VehDbgType::D_TPLLCO_RightOri_rad) \n
 *		[Debug  Signal] [D_TPLLCO_TgtCridrTransDev_met](@ref TPLLCO_VehDbgType::D_TPLLCO_TgtCridrTransDev_met) \n
 *		[Debug  Signal] [S_TPLLCO_DevDistY_met](@ref TPLLCO_VehDbgType::S_TPLLCO_DevDistY_met) \n
 *		[Debug  Signal] [S_TPLLCO_DevHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_DevHeading_rad) \n
 *		[Debug  Signal] [S_TPLLCO_LeftCorridorCrv_1pm](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorCrv_1pm) \n
 *		[Debug  Signal] [S_TPLLCO_LeftCorridorHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorHeading_rad) \n
 *		[Debug  Signal] [S_TPLLCO_LeftCorridorLength_met](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorLength_met) \n
 *		[Debug  Signal] [S_TPLLCO_LeftCorridorPosX0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorPosX0_met) \n
 *		[Debug  Signal] [S_TPLLCO_LeftCorridorPosY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorPosY0_met) \n
 *		[Debug  Signal] [S_TPLLCO_LeftCridrChngOfCrv_1pm2](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCridrChngOfCrv_1pm2) \n
 *		[Debug  Signal] [S_TPLLCO_MeasDeltaT_sec](@ref TPLLCO_VehDbgType::S_TPLLCO_MeasDeltaT_sec) \n
 *		[Debug  Signal] [S_TPLLCO_PlausiCheckStatus_nu](@ref TPLLCO_VehDbgType::S_TPLLCO_PlausiCheckStatus_nu) \n
 *		[Debug  Signal] [S_TPLLCO_ReplanDevDistY_met](@ref TPLLCO_VehDbgType::S_TPLLCO_ReplanDevDistY_met) \n
 *		[Debug  Signal] [S_TPLLCO_ReplanDevHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_ReplanDevHeading_rad) \n
 *		[Debug  Signal] [S_TPLLCO_RiCridrChngOfCrv_1pm2](@ref TPLLCO_VehDbgType::S_TPLLCO_RiCridrChngOfCrv_1pm2) \n
 *		[Debug  Signal] [S_TPLLCO_RightCorridorCrv_1pm](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorCrv_1pm) \n
 *		[Debug  Signal] [S_TPLLCO_RightCorridorLength_met](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorLength_met) \n
 *		[Debug  Signal] [S_TPLLCO_RightCorridorPosX0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorPosX0_met) \n
 *		[Debug  Signal] [S_TPLLCO_RightCorridorPosY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorPosY0_met) \n
 *		[Debug  Signal] [S_TPLLCO_RightCridrHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCridrHeading_rad) \n
 *		[Debug  Signal] [S_TPLLCO_TargetCorridorCrv_1pm](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCorridorCrv_1pm) \n
 *		[Debug  Signal] [S_TPLLCO_TargetCorridorPosX0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCorridorPosX0_met) \n
 *		[Debug  Signal] [S_TPLLCO_TargetCorridorPosY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCorridorPosY0_met) \n
 *		[Debug  Signal] [S_TPLLCO_TargetCridrHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCridrHeading_rad) \n
 *		[Debug  Signal] [S_TPLLCO_TargetCridrLength_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCridrLength_met) \n
 *		[Debug  Signal] [S_TPLLCO_TargetPathCrv_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetPathCrv_rad) \n
 *		[Debug  Signal] [S_TPLLCO_TargetPathHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetPathHeading_rad) \n
 *		[Debug  Signal] [S_TPLLCO_TargetPathY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetPathY0_met) \n
 *		[Debug  Signal] [S_TPLLCO_TgtCridrChngOfCrv_1pm2](@ref TPLLCO_VehDbgType::S_TPLLCO_TgtCridrChngOfCrv_1pm2) \n
 *		[Debug  Signal] [S_TPLLCO_TriggerReplan_nu](@ref TPLLCO_VehDbgType::S_TPLLCO_TriggerReplan_nu) \n
 *		[Output Signal] [D_TPLLCO_CCCEgoDistX_met](@ref TPLLCO_VehOutType::D_TPLLCO_CCCEgoDistX_met) \n
 *		[Output Signal] [D_TPLLCO_CCCEgoDistY_met](@ref TPLLCO_VehOutType::D_TPLLCO_CCCEgoDistY_met) \n
 *		[Output Signal] [D_TPLLCO_CCCEgoYawangle_rad](@ref TPLLCO_VehOutType::D_TPLLCO_CCCEgoYawangle_rad) \n\n
 *		For signal details, see sub-section [Globals](@ref TPLLCO_VehProcess_Globals) of the function @ref TPLLCO_VehProcess.
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
extern void TPLLCO_VehReset(void);

/*!
 *	TPLLCO module vehicle process function.
 *	
 *	@pre
 *		- The TPLLCO vehicle initialization function(s) must be called once.
 *		- The TPLLCO vehicle debug/output data pointer(s) should not be NULL.
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
 *		@anchor TPLLCO_VehProcess_Globals
 *		[D_TPLLCO_CCCDeviation_met](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCDeviation_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Lateral deviation of CCC (course consistency check) \n\n
 *		[D_TPLLCO_CCCInvalid_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCInvalid_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CCC failed \n\n
 *		[D_TPLLCO_CCCLength_met](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_100_1em5_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Length of the reference \n\n
 *		[D_TPLLCO_CCCPassedPerc_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCPassedPerc_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Testpoint DistX / Length of the reference \n\n
 *		[D_TPLLCO_CCCReset_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCReset_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		reference reset \n\n
 *		[D_TPLLCO_CCCTestPointDistX_met](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCTestPointDistX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		DistX of the test point \n\n
 *		[D_TPLLCO_CCCWarning_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_CCCWarning_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CCC Deviation over the threshold detected \n\n
 *		[D_TPLLCO_DeltaProjPosX_met](@ref TPLLCO_VehDbgType::D_TPLLCO_DeltaProjPosX_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Projection on x axle of the foot of the perpendicular from reference point (e.g. front axle middle) to the right corridor boundary in the vehicle coordinate system. \n\n
 *		[D_TPLLCO_DeltaProjPosY_met](@ref TPLLCO_VehDbgType::D_TPLLCO_DeltaProjPosY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Projection on y axle of the foot of the perpendicular from reference point (e.g. front axle middle) to the right corridor boundary in the vehicle coordinate system. \n\n
 *		[D_TPLLCO_EgoDistYPre_met](@ref TPLLCO_VehDbgType::D_TPLLCO_EgoDistYPre_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		ego disty prediction based on ego curvature and preview distance \n\n
 *		[D_TPLLCO_EgoHeadingPre_rad](@ref TPLLCO_VehDbgType::D_TPLLCO_EgoHeadingPre_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		ego heading prediction based on ego curvature and preview distance \n\n
 *		[D_TPLLCO_LeCridrTransDev_met](@ref TPLLCO_VehDbgType::D_TPLLCO_LeCridrTransDev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x4x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Deviation of the lateral position between the orginal and transformed left corridor boundary. \n\n
 *		[D_TPLLCO_PlausiCheckStatus_nu](@ref TPLLCO_VehDbgType::D_TPLLCO_PlausiCheckStatus_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield indicates the detailed information of the plausibility check in TPLLCO 1: NOT OK 0: OK \n
 *		Bit 0: vehicle's lateral position \n
 *		Bit 1: right corridor disty \n
 *		Bit 2: right corridor heading \n
 *		Bit 3: right corridor curvature \n
 *		Bit 4: left corridor disty \n
 *		Bit 5: left corridor heading \n
 *		Bit 6: left corridor curvature \n\n
 *		[D_TPLLCO_RiCridrTransDev_met](@ref TPLLCO_VehDbgType::D_TPLLCO_RiCridrTransDev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x4x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Deviation of the lateral position between the orginal and transformed right corridor boundary \n\n
 *		[D_TPLLCO_RightOri_rad](@ref TPLLCO_VehDbgType::D_TPLLCO_RightOri_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Orientation of the right corridor at the foot of the perpendicular \n\n
 *		[D_TPLLCO_TgtCridrTransDev_met](@ref TPLLCO_VehDbgType::D_TPLLCO_TgtCridrTransDev_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x4x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Deviation of the lateral position between the orginal and transformed target corridor \n\n
 *		[S_TPLLCO_DevDistY_met](@ref TPLLCO_VehDbgType::S_TPLLCO_DevDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		vehicle ego lateral distance in right corridor coordinate system \n\n
 *		[S_TPLLCO_DevHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_DevHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		vehicle heading angle in right corridor coordinate system \n\n
 *		[S_TPLLCO_LeftCorridorCrv_1pm](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		left corridor curvature in right corridor coordinate system \n\n
 *		[S_TPLLCO_LeftCorridorHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		left corridor heading angle in right corridor cooridnate system \n\n
 *		[S_TPLLCO_LeftCorridorLength_met](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		left corridor valid length in right corridor coordinate system \n\n
 *		[S_TPLLCO_LeftCorridorPosX0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		left corridor longitudinal start position in right corridor coordinate system \n\n
 *		[S_TPLLCO_LeftCorridorPosY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCorridorPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		left corridor lateral position in right corridor coordinate system \n\n
 *		[S_TPLLCO_LeftCridrChngOfCrv_1pm2](@ref TPLLCO_VehDbgType::S_TPLLCO_LeftCridrChngOfCrv_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		left corridor curvature change in right corridor cooridinate system \n\n
 *		[S_TPLLCO_MeasDeltaT_sec](@ref TPLLCO_VehDbgType::S_TPLLCO_MeasDeltaT_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Delta between LD and VDY time stamps \n\n
 *		[S_TPLLCO_PlausiCheckStatus_nu](@ref TPLLCO_VehDbgType::S_TPLLCO_PlausiCheckStatus_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield indicates the information of the plausibility check in TPLLCO 1: NOT OK 0: OK \n
 *		Bit 0: vehicle's lateral position \n
 *		Bit 1: right corridor transformation \n
 *		Bit 2: left corridor transformation \n\n
 *		[S_TPLLCO_ReplanDevDistY_met](@ref TPLLCO_VehDbgType::S_TPLLCO_ReplanDevDistY_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		deviation in lateral position by replanning \n\n
 *		[S_TPLLCO_ReplanDevHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_ReplanDevHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		heading angle deviation by replanning \n\n
 *		[S_TPLLCO_RiCridrChngOfCrv_1pm2](@ref TPLLCO_VehDbgType::S_TPLLCO_RiCridrChngOfCrv_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		right corridor curvature change in right corridor cooridnate system \n\n
 *		[S_TPLLCO_RightCorridorCrv_1pm](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		right corridor curvature in right corridor cooridnate system \n\n
 *		[S_TPLLCO_RightCorridorLength_met](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		right corridor valid length in right corridor cooridnate system \n\n
 *		[S_TPLLCO_RightCorridorPosX0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		right corridor longitudinal start position in right corridor coordinate system \n\n
 *		[S_TPLLCO_RightCorridorPosY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCorridorPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		right corridor lateral position in right corridor coordinate system \n\n
 *		[S_TPLLCO_RightCridrHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_RightCridrHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		right corridor heading angle in right corridor coordinate system \n\n
 *		[S_TPLLCO_TargetCorridorCrv_1pm](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCorridorCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		target corridor curvature in right corridor coordinate system \n\n
 *		[S_TPLLCO_TargetCorridorPosX0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCorridorPosX0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		target corridor longitudinal start position in right corridor coordinate system \n\n
 *		[S_TPLLCO_TargetCorridorPosY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCorridorPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		target corridor lateral position in right corridor coordinate system \n\n
 *		[S_TPLLCO_TargetCridrHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCridrHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		target corridor heading angle in right corridor coordinate system \n\n
 *		[S_TPLLCO_TargetCridrLength_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetCridrLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		target corridor valid length in right corridor coordinate system \n\n
 *		[S_TPLLCO_TargetPathCrv_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetPathCrv_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		curvature of the target path (target corridor with X0 = 0) \n\n
 *		[S_TPLLCO_TargetPathHeading_rad](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetPathHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		heading angle of the target path (target corridor with X0 = 0) \n\n
 *		[S_TPLLCO_TargetPathY0_met](@ref TPLLCO_VehDbgType::S_TPLLCO_TargetPathY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		lateral position of the target path (target corridor with X0 = 0) \n\n
 *		[S_TPLLCO_TgtCridrChngOfCrv_1pm2](@ref TPLLCO_VehDbgType::S_TPLLCO_TgtCridrChngOfCrv_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		target corridor curvature change in right corridor coordinate system \n\n
 *		[S_TPLLCO_TriggerReplan_nu](@ref TPLLCO_VehDbgType::S_TPLLCO_TriggerReplan_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		trigger for replanning \n\n
 *		[D_TPLLCO_CCCEgoDistX_met](@ref TPLLCO_VehOutType::D_TPLLCO_CCCEgoDistX_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		ego dist X from CCC \n\n
 *		[D_TPLLCO_CCCEgoDistY_met](@ref TPLLCO_VehOutType::D_TPLLCO_CCCEgoDistY_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m10_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -10 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		ego dist Y from CCC \n\n
 *		[D_TPLLCO_CCCEgoYawangle_rad](@ref TPLLCO_VehOutType::D_TPLLCO_CCCEgoYawangle_rad) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Ego Yaw angle from CCC \n\n
 *		@ref S_ABPLBP_LeCrvQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the curvature information based on standard deviations and the lookahead distance \n\n
 *		@ref S_ABPLBP_LeLnQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the left ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		@ref S_ABPLBP_RiCrvQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the curvature information based on standard deviations and the lookahead distance \n\n
 *		@ref S_ABPLBP_RiLnQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the right ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		@ref S_CSCLTA_LatencyCompActivated_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LeCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LeCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LeCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LeCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LeCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_LeCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_RiCridrBndCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_RiCridrBndCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_RiCridrBndHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_RiCridrBndLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_RiCridrBndPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_RiCridrBndPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_SensorTStamp_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_4295_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 4295 \n
 *		\@description: \n
 *		Timestamp of the corridor information signals \n\n
 *		@ref S_CSCLTA_SysStateLCF_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TgtTrajCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TgtTrajCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TgtTrajHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TgtTrajLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_150_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 150 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TgtTrajPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		CSCLTA_OUTPUT \n\n
 *		@ref S_CSCLTA_TgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
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
 *		@ref S_LCFRCV_SenToVehTStamp_us \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u32_us_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: us \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		Time stamp of the signals from sen part \n\n
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
 *		@ref S_LCFRCV_VehSync4LCO_us \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u32_us_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: us \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		Timestamp of VDY signals for latency compensation \n\n
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
 *		@ref P_TPLLCO_CCCAllowOverwrite_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Allow to overwrite the corridors when CCC check failed \n\n
 *		@ref P_TPLLCO_CCCEnableInCurve_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		enable CCC check in the curve all the time \n\n
 *		@ref P_TPLLCO_CCCEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enable CCC (course consistency check) \n\n
 *		@ref P_TPLLCO_CCCMaxCurvature_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		threshold for curve for CCC check \n\n
 *		@ref P_TPLLCO_CCCMinCrvQuality_Perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Min Crv Quality for reset \n\n
 *		@ref P_TPLLCO_CCCMinLnQuality_Perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Min. Lane Quality for reset \n\n
 *		@ref P_TPLLCO_CCCMinQuCycle_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		min. cycle of high quality for reset \n\n
 *		@ref P_TPLLCO_CCCMinTestDistX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_100_1em5_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Min. DistX of the test point \n\n
 *		@ref P_TPLLCO_CCCMinValidLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_100_1em5_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Min. valid length for bridging by failed CCC, afterwards it will be reported to SA through bitfield. \n\n
 *		@ref P_TPLLCO_CCCResetMaxDistX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_100_1em5_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Reset when DistX over the Max. \n\n
 *		@ref P_TPLLCO_CCCResetMaxPerc_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Reset when the DistX of the test point is over the max perc. of the frozen length \n\n
 *		@ref P_TPLLCO_CCCTestDisXPerc_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		DistX of the test point = TestDistXPerc * ValidLength \n\n
 *		@ref P_TPLLCO_CCCThresholdMaxDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Threshold of the max. allowed deviation by CCC \n\n
 *		@ref P_TPLLCO_CCCValidMaxPerc_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Max. Perc. of the frozen length of the test point by valid check \n\n
 *		@ref P_TPLLCO_CalculationbyRampout_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Allow the calculation of the current ego position when the function ramps out \n\n
 *		@ref P_TPLLCO_CalculationbyRequest_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_CoordTrafoMinLength_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_CrvCheckTolerance_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Tolerance of the deviation caused by the curvature term by coordinate transformation. \n\n
 *		@ref P_TPLLCO_DistYCheckTolerance_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Tolerance of the deviation caused by the disty term by coordinate transformation. \n\n
 *		@ref P_TPLLCO_NumIter_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_1_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_OdoMaxTime_us \n
 *		\@kind: Parameter \n
 *		\@type: @ref u32_us_0_4294967295_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: us \n
 *		\@min: 0 \n
 *		\@max: 4294967295 \n
 *		\@description: \n
 *		max timestamp of vdy data \n\n
 *		@ref P_TPLLCO_PreviewDistXEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_ReplanDevEnable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		enable the deviation calculation for replan \n\n
 *		@ref P_TPLLCO_SupressDoubleTrigRpl_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_TimeDiffSwitch_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_TimeDiff_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_m60_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: -60 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_UseEgoPredict_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		consider ego motion by calculating current disty under OBF mode \n\n
 *		@ref P_TPLLCO_UseOdoReplan_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_TPLLCO_UseSensorTStamp_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		switch between sensor time stamp and sentoveh time stamp for calculation trigger \n\n
 *		@ref P_TPLLCO_VehCrvPT1Enable_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		enable low pass filter by using ego vehicle curvature \n\n
 *		@ref P_TPLLCO_VehCrvPT1TimeConst_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0p025_10_1em4_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0.025 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Time constant of the low pass filter on vehicle curvature \n\n
 *		@ref X_TPLLCO_CorridorCurvature_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		 \n\n
 *		@ref X_TPLLCO_TestPointPosX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m100_100_1em3_t \n
 *		\@size: 1x4x1 \n
 *		\@unit: m \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		x axle with test point longitudinal position \n\n
 *		@ref X_TPLLCO_VehVelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_100_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TPLLCO_AllowedDevPosY_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_1_1em3_t \n
 *		\@size: 1x4x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		y axle with allowed deviation in lateral direction for coordinate transformation \n\n
 *		@ref Y_TPLLCO_PreviewDistXOBF_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		preview distance in longitudinal direction for OBF mode \n\n
 *		@ref Y_TPLLCO_PreviewDistX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_TPLLCO_TgtCridrHeadTolCrv_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_1_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Target corridor heading tolerance regarding to the curvature \n\n
 *		@ref Y_TPLLCO_TgtCridrHeadTolVelX_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_0_1_1em6_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: rad \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Target corridor heading tolerance regarding to longitudinal velocity \n\n
 *		@ref Y_TPLLCO_VehCrvFactor_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_2_1em3_t \n
 *		\@size: 1x13x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		factor on vehicle curvature \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TPLLCO Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TPLLCO_Testcase_Initialization) Initialization of the TPLLCO
 *		-# [Testcase_TGQ_REQ_FFC](@ref TPLLCO_Testcase_TGQ_REQ_FFC) 
 *		-# [Testcase_S_TPLLCO_TriggerReplan_nu](@ref TPLLCO_Testcase_S_TPLLCO_TriggerReplan_nu) DOORS ID FCT_CMP_TRJPLN_284
 *		-# [Testcase_forcoverage](@ref TPLLCO_Testcase_forcoverage) 
 *		-# [Testcase_S_TPLLCO_MeasDeltaT_sec](@ref TPLLCO_Testcase_S_TPLLCO_MeasDeltaT_sec) S_TPLLCO_MeasDeltaT_sec
 *		-# [Testcase_CoordinateTransformation](@ref TPLLCO_Testcase_CoordinateTransformation) DOORS ID FCT_CMP_TRJPLN_257
 *		-# [Testcase_S_TPLLCO_DevDistY_met](@ref TPLLCO_Testcase_S_TPLLCO_DevDistY_met) DOORS ID FCT_CMP_TRJPLN_253
 *		-# [Testcase_S_TPLLCO_DevHeading_rad](@ref TPLLCO_Testcase_S_TPLLCO_DevHeading_rad) DOORS ID FCT_CMP_TRJPLN_258
 *		-# [Testcase_ReplanDev](@ref TPLLCO_Testcase_ReplanDev) S_TPLLCO_ReplanDevDistY_met, S_TPLLCO_ReplanDevHeading_rad
 *		-# [Testcase_PlausiCheck](@ref TPLLCO_Testcase_PlausiCheck) DOORS ID FCT_CMP_TRJPLN_294, FCT_CMP_TRJPLN_295, FCT_CMP_TRJPLN_297, FCT_CMP_TRJPLN_296, FCT_CMP_TRJPLN_298
 *		-# [Testcase_CCC_Check](@ref TPLLCO_Testcase_CCC_Check) DOORS ID FCT_CMP_TRJPLN_294, FCT_CMP_TRJPLN_295, FCT_CMP_TRJPLN_297, FCT_CMP_TRJPLN_296, FCT_CMP_TRJPLN_298
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		-# [Testcase_S_TPLLCO_TrajPlanEnbl_nu](@ref TPLLCO_Testcase_S_TPLLCO_TrajPlanEnbl_nu) S_TPLLCO_TrajPlanEnbl_nu, S_TPLLCO_EnblSpecPlanStrategy_nu
 *		
 *	@traceability
 *		[\@link: TPLLCO Module Requirements]()
 */
extern void TPLLCO_VehProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TPLLCO_H_
