/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJACMB
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.1.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:23:14CEST $
  $Log: TJACMB.h  $
  Revision 1.1.1.2 2020/04/09 14:23:14CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.1.1.1 2019/11/29 09:05:07CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJACMB.h
//! @brief     (TJACMB) Module Header.

#ifndef TJACMB_H_
#define TJACMB_H_

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
 *	TJACMB module sensor initialization function. Function initializes TJACMB sensor debug data pointer.
 *	
 *	@param
 *		[in] TJACMB_SenDbgArg Pointer to TJACMB sensor debug data.
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
extern void TJACMB_SenInitDbgPtr(TJACMB_SenDbgType *TJACMB_SenDbgArg);

/*!
 *	TJACMB module sensor initialization function. Function initializes TJACMB sensor output data pointer.
 *	
 *	@param
 *		[in] TJACMB_SenOutArg Pointer to TJACMB sensor output data.
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
extern void TJACMB_SenInitOutPtr(TJACMB_SenOutType *TJACMB_SenOutArg);

/*!
 *	TJACMB module sensor reset function.
 *	
 *	@pre
 *		- The TJACMB sensor initialization function(s) must be called once.
 *		- The TJACMB sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TJACMB_CombinedInvalid_btf](@ref TJACMB_SenDbgType::D_TJACMB_CombinedInvalid_btf) \n
 *		[Debug  Signal] [S_TJACMB_Cancel_bool](@ref TJACMB_SenDbgType::S_TJACMB_Cancel_bool) \n
 *		[Debug  Signal] [S_TJACMB_CombinedCrvChng_1pm2](@ref TJACMB_SenDbgType::S_TJACMB_CombinedCrvChng_1pm2) \n
 *		[Debug  Signal] [S_TJACMB_CombinedCrv_1pm](@ref TJACMB_SenDbgType::S_TJACMB_CombinedCrv_1pm) \n
 *		[Debug  Signal] [S_TJACMB_CombinedHeading_rad](@ref TJACMB_SenDbgType::S_TJACMB_CombinedHeading_rad) \n
 *		[Debug  Signal] [S_TJACMB_CombinedLength_met](@ref TJACMB_SenDbgType::S_TJACMB_CombinedLength_met) \n
 *		[Debug  Signal] [S_TJACMB_CombinedPosY0_met](@ref TJACMB_SenDbgType::S_TJACMB_CombinedPosY0_met) \n
 *		[Debug  Signal] [S_TJACMB_StrongReady_bool](@ref TJACMB_SenDbgType::S_TJACMB_StrongReady_bool) \n
 *		[Debug  Signal] [S_TJACMB_WeakReady_bool](@ref TJACMB_SenDbgType::S_TJACMB_WeakReady_bool) \n
 *		[Output Signal] [D_TJACMB_TransitionInvalid_btf](@ref TJACMB_SenOutType::D_TJACMB_TransitionInvalid_btf) \n
 *		[Output Signal] [S_TJACMB_CombinedLePosY0_met](@ref TJACMB_SenOutType::S_TJACMB_CombinedLePosY0_met) \n
 *		[Output Signal] [S_TJACMB_CombinedMode_nu](@ref TJACMB_SenOutType::S_TJACMB_CombinedMode_nu) \n
 *		[Output Signal] [S_TJACMB_CombinedPosX0_met](@ref TJACMB_SenOutType::S_TJACMB_CombinedPosX0_met) \n
 *		[Output Signal] [S_TJACMB_CombinedRiPosY0_met](@ref TJACMB_SenOutType::S_TJACMB_CombinedRiPosY0_met) \n\n
 *		For signal details, see sub-section [Globals](@ref TJACMB_SenProcess_Globals) of the function @ref TJACMB_SenProcess.
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
extern void TJACMB_SenReset(void);

/*!
 *	TJACMB module sensor process function.
 *	
 *	@pre
 *		- The TJACMB sensor initialization function(s) must be called once.
 *		- The TJACMB sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJACMB_SenProcess_Globals
 *		[D_TJACMB_CombinedInvalid_btf](@ref TJACMB_SenDbgType::D_TJACMB_CombinedInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJACMB Debug Signal \n\n
 *		[S_TJACMB_Cancel_bool](@ref TJACMB_SenDbgType::S_TJACMB_Cancel_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if at least one cancel condition for combined mode is fulfilled. \n\n
 *		[S_TJACMB_CombinedCrvChng_1pm2](@ref TJACMB_SenDbgType::S_TJACMB_CombinedCrvChng_1pm2) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Combined Curvature Change \n\n
 *		[S_TJACMB_CombinedCrv_1pm](@ref TJACMB_SenDbgType::S_TJACMB_CombinedCrv_1pm) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Combined Curvature \n\n
 *		[S_TJACMB_CombinedHeading_rad](@ref TJACMB_SenDbgType::S_TJACMB_CombinedHeading_rad) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Combined Heading Angle \n\n
 *		[S_TJACMB_CombinedLength_met](@ref TJACMB_SenDbgType::S_TJACMB_CombinedLength_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Combined Trajectory Length \n\n
 *		[S_TJACMB_CombinedPosY0_met](@ref TJACMB_SenDbgType::S_TJACMB_CombinedPosY0_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Combined PosY0 \n\n
 *		[S_TJACMB_StrongReady_bool](@ref TJACMB_SenDbgType::S_TJACMB_StrongReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if all strong ready conditions for combined mode are fulfilled. \n\n
 *		[S_TJACMB_WeakReady_bool](@ref TJACMB_SenDbgType::S_TJACMB_WeakReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if all weak ready conditions for combined mode are fulfilled. \n\n
 *		[D_TJACMB_TransitionInvalid_btf](@ref TJACMB_SenOutType::D_TJACMB_TransitionInvalid_btf) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJACMB Debug: Internal transition \n\n
 *		[S_TJACMB_CombinedLePosY0_met](@ref TJACMB_SenOutType::S_TJACMB_CombinedLePosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Combined Left PosY0 \n\n
 *		[S_TJACMB_CombinedMode_nu](@ref TJACMB_SenOutType::S_TJACMB_CombinedMode_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_TJACMB_CombModeType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Combined mode state \n\n
 *		[S_TJACMB_CombinedPosX0_met](@ref TJACMB_SenOutType::S_TJACMB_CombinedPosX0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Combined PosX0 \n\n
 *		[S_TJACMB_CombinedRiPosY0_met](@ref TJACMB_SenOutType::S_TJACMB_CombinedRiPosY0_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Combined Right PosY0 \n\n
 *		@ref S_ABPLBP_CntrLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Lane center clothoid curvature change \n\n
 *		@ref S_ABPLBP_CntrLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Lane center clothoid curvature \n\n
 *		@ref S_ABPLBP_CntrLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Lane center clothoid heading angle \n\n
 *		@ref S_ABPLBP_CntrLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lane center clothoid length \n\n
 *		@ref S_ABPLBP_CntrLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Lane center clothoid X0-Position \n\n
 *		@ref S_ABPLBP_CntrLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lane center clothoid Y0 position \n\n
 *		@ref S_ABPLBP_ConstructionSite_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE: Construction site detected; \n
 *		FALSE: No construction site detected \n\n
 *		@ref S_ABPLBP_LeLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (init +10m) \n\n
 *		@ref S_ABPLBP_RiLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (init -10m) \n\n
 *		@ref S_ABPLBP_StraightPathDtct_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Confidence for straight detection - value from 0 to 100 \n\n
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
 *		@ref S_LCFRCV_VDy_VehVelocity_kph \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Tachometer Vehicle Speed in kilometers/hour \n\n
 *		@ref S_LCFRCV_VehCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Vehicle curvature \n\n
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
 *		@ref S_ODPFOH_ObjTraceStraight_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Probability of a straight object trace trajectory (dominant 1st order History Polyfit) \n\n
 *		@ref S_ODPFOH_TgtObjCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Target object curvature change \n\n
 *		@ref S_ODPFOH_TgtObjCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Target object curvature \n\n
 *		@ref S_ODPFOH_TgtObjHeadAng_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Target object heading angle \n\n
 *		@ref S_ODPFOH_TgtObjLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Target object trajectory length \n\n
 *		@ref S_ODPFOH_TgtObjPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Target object position X0 \n\n
 *		@ref S_ODPFOH_TgtObjPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Target object position Y0 \n\n
 *		@ref S_ODPFOP_AccObjPosX_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Longitudinal (parallel to ego-vehicle x-axis) distance to object kinematic point. \n\n
 *		@ref S_ODPFOP_AccObjPosY_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Lateral (parallel to ego-vehicle y-axis) distance to object kinematic point. Positive to the left. \n\n
 *		@ref S_TJAGEN_LKAOnlySwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable LKA only \n\n
 *		@ref S_TJALKA_Cancel_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for lane centering are fulfilled. \n\n
 *		@ref S_TJALKA_CombinedLaneSR_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if lane are considered SR valid for combined mode \n\n
 *		@ref S_TJALKA_CombinedLaneWR_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if lane are considered WR valid for combined mode \n\n
 *		@ref S_TJALKA_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for lane centering are fulfilled. \n\n
 *		@ref S_TJALKA_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for lane centering are fulfilled. \n\n
 *		@ref S_TJAOBF_AccObjValid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if ACC object is valid for object following mode. \n\n
 *		@ref S_TJAOBF_Cancel_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for object following are fulfilled. \n\n
 *		@ref S_TJAOBF_CombObjectCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Object curvature based on ACC object measurement position and lateral offset / heading angle of ABPR center lane \n\n
 *		@ref S_TJAOBF_ObjInLaneValid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if target object validated to be driving within the ego lane \n\n
 *		@ref S_TJAOBF_ObjectCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Object curvature based on ACC object measurement position \n\n
 *		@ref S_TJAOBF_StrongReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for object following are fulfilled. \n\n
 *		@ref S_TJAOBF_WeakReady_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for object following are fulfilled. \n\n
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_TJASTM_SysStateTJA_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref P_LCF_AlmostZero_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_1Em20_1Em05_1em9_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 1E-20 \n
 *		\@max: 1E-05 \n
 *		\@description: \n
 *		Constant Macro near 0.0f which is used for the Division-by-Zero protection \n\n
 *		@ref P_TJACMB_AccObjPosXStdDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		Standard deviation of Acc object measurement PosX \n\n
 *		@ref P_TJACMB_AccObjPosYStdDev_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Standard deviation of Acc object measurement PosY \n\n
 *		@ref P_TJACMB_AccObjTransitionTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Transition time for lane to object transition \n\n
 *		@ref P_TJACMB_CMB_Enabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable combined mode \n\n
 *		@ref P_TJACMB_CombinedCrvEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of combined curvature during lane based combined mode \n\n
 *		@ref P_TJACMB_CombinedCrvObjWeight_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Object weight for combined curvature \n\n
 *		@ref P_TJACMB_ConstSiteCheckOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable construction site check for combined mode \n\n
 *		@ref P_TJACMB_CurvatureMaxOF_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum curvature allowed during object-based combined mode \n\n
 *		@ref P_TJACMB_IndVelLimitsEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if individual combined mode velocities shall be enabled (P_TJACMB_VelXMax_kph, P_TJACMB_VelXMin_kph) \n\n
 *		@ref P_TJACMB_InjectLaneError_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJACMB error injection for lane validity \n\n
 *		@ref P_TJACMB_KalmanMinValidTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum Kalman Filter running time to allow Lane2Obj transition \n\n
 *		@ref P_TJACMB_LaneCheckEnabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable object-in-lane check for object-based combined mode \n\n
 *		@ref P_TJACMB_LaneInvalidTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Invalidation time for lane error injection \n\n
 *		@ref P_TJACMB_LnCurveDtctEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of lane curvature detection as activation condition for object-based combined mode \n\n
 *		@ref P_TJACMB_LnCurveMaxPercHyst_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Hysteresis for maximum probability of ABPR straight estimation below which a curve scenario is considered \n\n
 *		@ref P_TJACMB_LnCurveMaxPerc_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum probability of ABPR straight estimation below which a curve scenario is considered \n\n
 *		@ref P_TJACMB_MaxTimeObjCntrl_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum allowed control time for object-based combined mode \n\n
 *		@ref P_TJACMB_MaxTimeObjCtrlOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable control time limitation of object-based combined mode \n\n
 *		@ref P_TJACMB_MinDurObjLnValidWR_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum duration of valid object-in-lane check as WR condition for object-based combined mode \n\n
 *		@ref P_TJACMB_MinLnLengthHystLC_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		Minimum lane length for lane based combined mode (hysteresis) \n\n
 *		@ref P_TJACMB_MinLnLengthLC_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		Minimum lane length for lane based combined mode \n\n
 *		@ref P_TJACMB_MinObjStraightProb_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum OF straight probability to set higher priority on pure object following mode \n\n
 *		@ref P_TJACMB_MinObjStraightProb_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time of minimum OF straight probability to set higher priority on pure object following mode \n\n
 *		@ref P_TJACMB_OF_Debug_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable debug mode (force object-based combined mode) \n\n
 *		@ref P_TJACMB_OF_Enabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable object based combined mode \n\n
 *		@ref P_TJACMB_ObjHystPosXOF_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_40_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 40 \n
 *		\@description: \n
 *		Hysteresis for long. distance check of ACC target object to allow object based combined mode \n\n
 *		@ref P_TJACMB_ObjMaxPosXOF_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum long. distance to ACC target object to allow object based combined mode \n\n
 *		@ref P_TJACMB_ObjMinPosXOF_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum long. distance to ACC target object to allow object based combined mode \n\n
 *		@ref P_TJACMB_PassivModeMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Combined mode blocking time after switch to combined mode passive state \n\n
 *		@ref P_TJACMB_SetLaneCondInvalid_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to set lane conditions invalid \n\n
 *		@ref P_TJACMB_TransitionHandleOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable transition handling for transition lane to objects \n\n
 *		@ref P_TJACMB_UseInterCmbCrvCalc_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable internal calculation of object (combined) curvature \n\n
 *		@ref P_TJACMB_VelXMaxOF_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum ego vehicle velocity to allow object based combined mode \n\n
 *		@ref P_TJACMB_VelXMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum allowed ego vehicle velocity for combined mode \n\n
 *		@ref P_TJACMB_VelXMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum required ego vehicle velocity for combined mode \n\n
 *		@ref P_TJALKA_VelXHyst_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Longitudinal velocity hysteresis \n\n
 *		@ref P_TJALKA_VelXMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum longitudinal velocity allowed for lane centering mode \n\n
 *		@ref P_TJALKA_VelXMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Minimum longitudinal velocity required for lane centering mode \n\n
 *		@ref P_TJAOBF_VelXMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum longitudinal velocity allowed for object following mode \n\n
 *		@ref P_TJAOBF_VelXMinOF_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum ego vehicle velocity to allow object based combined mode \n\n
 *		@ref P_TJAOBF_VelXMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Minimum longitudinal velocity required for object following mode \n\n
 *		@ref P_TJATTG_CrvChngDecay_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Curvature change decay factor for object following \n\n
 *		@ref P_TJATTG_LnMeasCrvChngVar_1pm4 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Measurement uncertainty of lane curvature \n\n
 *		@ref P_TJATTG_LnMeasCrvVar_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Measurement uncertainty of lane curvature \n\n
 *		@ref P_TJATTG_LnMeasHeadVar_rad2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Measurement uncertainty of lane heading \n\n
 *		@ref P_TJATTG_LnMeasPosYVar_m2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Measurement uncertainty of lateral lane position \n\n
 *		@ref P_TJATTG_ModelCrvChngVar_1pm4 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Model uncertainty with respect to curvature change \n\n
 *		@ref P_TJATTG_ModelCrvVar_1pm2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm2_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Model uncertainty with respect to curvature \n\n
 *		@ref P_TJATTG_ModelPosYVar_m2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Model uncertainty with respect to lateral position \n\n
 *		@ref P_TJATTG_ModelYawVar_rad2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Model uncertainty with respect to heading angle \n\n
 *		@ref P_TJATTG_ObjMeasPosXVar_m2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Measurement uncertainty of lateral object position \n\n
 *		@ref P_TJATTG_ObjMeasPosYVar_m2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Measurement uncertainty of longitudinal object position \n\n
 *		@ref P_TJATTG_PredVelXVar_m2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Velocity variance for prediction \n\n
 *		@ref P_TJATTG_PredYawRtVar_r2ps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m0p1_0p1_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Kalman Filter Parameter: \n
 *		Yaw rate variance for prediction \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJACMB Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJACMB_SEN/TJACMB/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJACMB_Testcase_Initialization) Initialization of the TJACMB module
 *		-# [Testcase_OldCombinedMode](@ref TJACMB_Testcase_OldCombinedMode) Strong ready check
 *		-# [Testcase_PassiveState](@ref TJACMB_Testcase_PassiveState) Check condition flags
 *		-# [Testcase_SR_WR_Cancel_Flags](@ref TJACMB_Testcase_SR_WR_Cancel_Flags) Set passive state
 *		-# [Testcase_Combined_StrongReady](@ref TJACMB_Testcase_Combined_StrongReady) Check generic strong ready conditions for object combined mode
 *		-# [Testcase_Combined_WeakReady](@ref TJACMB_Testcase_Combined_WeakReady) Check generic weak ready conditions for object combined mode
 *		-# [Testcase_Combined_Cancel](@ref TJACMB_Testcase_Combined_Cancel) Check generic cancel conditions
 *		-# [Testcase_LaneCMB_WeakReady](@ref TJACMB_Testcase_LaneCMB_WeakReady) Lane Combined Mode: Weak Ready Condition Checks
 *		-# [Testcase_LaneCMB_Cancel](@ref TJACMB_Testcase_LaneCMB_Cancel) Lane Combined Mode: Cancel Condition Checks
 *		-# [Testcase_ObjCMB_WeakReady](@ref TJACMB_Testcase_ObjCMB_WeakReady) Check object combined mode
 *		-# [Testcase_ObjCMB_LaneReset](@ref TJACMB_Testcase_ObjCMB_LaneReset) Check object combined mode
 *		-# [Testcase_ObjCMB_Cancel](@ref TJACMB_Testcase_ObjCMB_Cancel) Check object combined mode
 *		-# [Testcase_ObjCMB_Cancel_MaxTime](@ref TJACMB_Testcase_ObjCMB_Cancel_MaxTime) Check maximum time limitation of object combined mode
 *		-# [Testcase_CombinedCrvCalculation](@ref TJACMB_Testcase_CombinedCrvCalculation) Check combined curvature calculation
 *		-# [Testcase_DebugMode](@ref TJACMB_Testcase_DebugMode) Debug mode for object-based combined mode
 *		-# [Testcase_KalmanInvalid](@ref TJACMB_Testcase_KalmanInvalid) Set Kalman tuning parameter to zero and check if invalidty detected
 *		
 *	@traceability
 *		[\@link: TJACMB Module Requirements]()
 */
extern void TJACMB_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* TJACMB_H_*/
