/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJALKA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJALKA.h
//! @brief     (TJALKA) Module Header.

#ifndef TJALKA_H_
#define TJALKA_H_

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
 *	TJALKA module sensor initialization function. Function initializes TJALKA sensor debug data pointer.
 *	
 *	@param
 *		[in] TJALKA_SenDbgArg Pointer to TJALKA sensor debug data.
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
extern void TJALKA_SenInitDbgPtr(TJALKA_SenDbgType *TJALKA_SenDbgArg);

/*!
 *	TJALKA module sensor initialization function. Function initializes TJALKA sensor output data pointer.
 *	
 *	@param
 *		[in] TJALKA_SenOutArg Pointer to TJALKA sensor output data.
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
extern void TJALKA_SenInitOutPtr(TJALKA_SenOutType *TJALKA_SenOutArg);

/*!
 *	TJALKA module sensor reset function.
 *	
 *	@pre
 *		- The TJALKA sensor initialization function(s) must be called once.
 *		- The TJALKA sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TJALKA_LaneCenterInvalid_btf](@ref TJALKA_SenDbgType::D_TJALKA_LaneCenterInvalid_btf) \n
 *		[Debug  Signal] [S_TJALKA_Cancel_bool](@ref TJALKA_SenDbgType::S_TJALKA_Cancel_bool) \n
 *		[Debug  Signal] [S_TJALKA_LanePredictValid_bool](@ref TJALKA_SenDbgType::S_TJALKA_LanePredictValid_bool) \n
 *		[Debug  Signal] [S_TJALKA_LnBndValid_nu](@ref TJALKA_SenDbgType::S_TJALKA_LnBndValid_nu) \n
 *		[Debug  Signal] [S_TJALKA_StrongReady_bool](@ref TJALKA_SenDbgType::S_TJALKA_StrongReady_bool) \n
 *		[Debug  Signal] [S_TJALKA_WeakReady_bool](@ref TJALKA_SenDbgType::S_TJALKA_WeakReady_bool) \n
 *		[Output Signal] [D_TJALKA_LaneInvalid_btf](@ref TJALKA_SenOutType::D_TJALKA_LaneInvalid_btf) \n
 *		[Output Signal] [S_TJALKA_CombinedLaneSR_bool](@ref TJALKA_SenOutType::S_TJALKA_CombinedLaneSR_bool) \n
 *		[Output Signal] [S_TJALKA_CombinedLaneWR_bool](@ref TJALKA_SenOutType::S_TJALKA_CombinedLaneWR_bool) \n\n
 *		For signal details, see sub-section [Globals](@ref TJALKA_SenProcess_Globals) of the function @ref TJALKA_SenProcess.
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
extern void TJALKA_SenReset(void);

/*!
 *	TJALKA module sensor process function.
 *	
 *	@pre
 *		- The TJALKA sensor initialization function(s) must be called once.
 *		- The TJALKA sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJALKA_SenProcess_Globals
 *		[D_TJALKA_LaneCenterInvalid_btf](@ref TJALKA_SenDbgType::D_TJALKA_LaneCenterInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJALKA_DEBUG Bitfield \n
 *		 \n
 *		0: SR: EgoLanesInvalid \n
 *		1: SR: VelLimitExceed \n
 *		2: SR: DistToLnBoundInvalid \n
 *		3: SR: LaneWidthInvalid \n
 *		4: SR: CurvaturRadiusInvalid \n
 *		5: SR: TurnIndicatorEngaged \n
 *		6: SR: ConstSiteDetected \n
 *		7: SR: LC_Disabled \n
 *		8: SR: CustomSRInvalid \n
 *		9: SR: ObjFollowOnlyMode \n
 *		10: WR: CustomWRInvalid \n
 *		11: WR: LaneNotInCaptRange \n
 *		12: WR: BlockingTimeOn \n
 *		13: C: CustomCancel \n
 *		14: C: CancelCondFulfilled \n
 *		15: Reserved \n\n
 *		[S_TJALKA_Cancel_bool](@ref TJALKA_SenDbgType::S_TJALKA_Cancel_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for lane centering are fulfilled. \n\n
 *		[S_TJALKA_LanePredictValid_bool](@ref TJALKA_SenDbgType::S_TJALKA_LanePredictValid_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates TRUE if both-sided lane prediction shall be enabled \n\n
 *		[S_TJALKA_LnBndValid_nu](@ref TJALKA_SenDbgType::S_TJALKA_LnBndValid_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		TJA lane valid qualifier \n
 *		 \n
 *		0: Both lanes invalid \n
 *		1: Left lane valid \n
 *		2: Right lane valid \n
 *		3: Both lanes valid \n\n
 *		[S_TJALKA_StrongReady_bool](@ref TJALKA_SenDbgType::S_TJALKA_StrongReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for lane centering are fulfilled. \n\n
 *		[S_TJALKA_WeakReady_bool](@ref TJALKA_SenDbgType::S_TJALKA_WeakReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJALKA_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for lane centering are fulfilled. \n\n
 *		[D_TJALKA_LaneInvalid_btf](@ref TJALKA_SenOutType::D_TJALKA_LaneInvalid_btf) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Lane Invalid Debug Bitfield \n\n
 *		[S_TJALKA_CombinedLaneSR_bool](@ref TJALKA_SenOutType::S_TJALKA_CombinedLaneSR_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if lane are considered SR valid for combined mode \n\n
 *		[S_TJALKA_CombinedLaneWR_bool](@ref TJALKA_SenOutType::S_TJALKA_CombinedLaneWR_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if lane are considered WR valid for combined mode \n\n
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
 *		@ref S_ABPLBP_CoupledLaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Raw lane width of ABD interface coupled lane data \n\n
 *		@ref S_ABPLBP_LaneChangeDetected_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Flag that indicates a detected lane change \n\n
 *		@ref S_ABPLBP_LaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane width \n\n
 *		@ref S_ABPLBP_LeLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (init +10m) \n\n
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
 *		@ref S_ABPLBP_LeLnQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the left ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		@ref S_ABPLBP_LeUncoupBrid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		left lane uncoupled lane bridging possible \n\n
 *		@ref S_ABPLBP_RiLnClthLength_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid length \n\n
 *		@ref S_ABPLBP_RiLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (init -10m) \n\n
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
 *		@ref S_ABPLBP_RiLnQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the right ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		@ref S_ABPLBP_RiUncoupBrid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Right lane uncouplded bridging possible \n\n
 *		@ref S_ABPLBP_UncoupledLaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Raw lane width of ABD interface uncoupled lane data \n\n
 *		@ref S_CUSTOM_PrjSpecQu_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield containing all the relevant information of the customer projects. \n\n
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
 *		@ref S_LCFRCV_TurnSignalLeverHold_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if turn signal lever is in hold position \n\n
 *		@ref S_LCFRCV_VDy_VehVelocity_kph \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Tachometer Vehicle Speed in kilometers/hour \n\n
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
 *		@ref S_TJAOBS_CancelLC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if critical situation is observed, which required cancelation of lane centering mode \n\n
 *		@ref S_TJASLC_TakeOverValid_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if SALC maneuver state is valid for lane centering mode to take over. \n\n
 *		@ref S_TJASTM_LatCtrlMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_TJASTM_LatCtrlMdV4Type_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 8 \n
 *		\@description: \n
 *		TJASTM_OUTPUT \n\n
 *		@ref S_VDPDRV_DrvStInvalid_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: AccelPedalRateInvalid \n
 *		1: DriverNotBuckledUp \n
 *		2: TurnSignalHarzard \n
 *		3: TurnSignalLeftOrRight \n
 *		4: DrvInattentivenessDetected \n
 *		5: ManualTorqueOverride \n
 *		6: Reserved (0 by default) \n
 *		7: Reserved (0 by default) \n\n
 *		@ref P_TJACMB_LnQualGradMaxExit_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Maximum lane quality drop (in one cycle) to consider exit scenario \n\n
 *		@ref P_TJACMB_LnQualMinContrast_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum lane quality below which low contrast scenario is considered \n\n
 *		@ref P_TJACMB_LnQualMinCurve_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum lane quality below which curve scenario is considered (if both lanes below this threshold for more than P_TJACMB_LnQualMinOnTmCurve_sec seconds) \n\n
 *		@ref P_TJACMB_LnQualMinExit_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum lane quality below which exit scenario is considered \n\n
 *		@ref P_TJACMB_LnQualMinHystWR_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum required lane quality hysteresis for lane based combined mode activation \n\n
 *		@ref P_TJACMB_LnQualMinOnTmCurve_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time of lane quality below P_TJACMB_LnQualMinCurve_perc to consider curvature scenario \n\n
 *		@ref P_TJACMB_LnQualMinOnTmWR_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time of lane quality above P_TJACMB_LnQualMinWR_perc for lane based combined mode activation \n\n
 *		@ref P_TJACMB_LnQualMinWR_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum required lane quality for lane based combined mode activation \n\n
 *		@ref P_TJACMB_LnQualShutOffQulOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of lane quality checks for trigger of combined mode transition from lanes to object \n\n
 *		@ref P_TJAGEN_QuTrajPlanMinLnQual_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum required lane quality for function re-activation after specific blocking time for TrajPlanCancelQualifier \n\n
 *		@ref P_TJALKA_BlockTimeTJA_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJA Blocking time \n\n
 *		@ref P_TJALKA_BothSideBrdgEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if both-sided bridging/prediction is enabled \n\n
 *		@ref P_TJALKA_ConstSiteCheckOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable construction site check \n\n
 *		@ref P_TJALKA_DistVeh2LnBndHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Minimum distance to lane boundary hysteresis \n\n
 *		@ref P_TJALKA_DistVeh2LnBndMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Minimum distance to lane boundary \n\n
 *		@ref P_TJALKA_DrvStInvalidSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask to check if turn signal left/right is engaged \n\n
 *		@ref P_TJALKA_InjectLaneError_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Setting to TRUE will inject single error, which invalidates lanes for P_TJALKA_LaneInvalidTime_sec seconds \n\n
 *		@ref P_TJALKA_LC_Enabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if lane centering mode is enabled. \n\n
 *		@ref P_TJALKA_LaneInvalidTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Lane invalidation time for lane error injection \n\n
 *		@ref P_TJALKA_LaneQualityHyst_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum lane quality hysteresis \n\n
 *		@ref P_TJALKA_LaneQualityMin_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum lane quality \n\n
 *		@ref P_TJALKA_LaneValid_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for lane validity check (left/right) \n\n
 *		@ref P_TJALKA_LaneVirtOrBridged_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check if lanes are bridged or virtual \n\n
 *		@ref P_TJALKA_LaneWidthHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Hysteresis for lane width check \n\n
 *		@ref P_TJALKA_LaneWidthMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed lane width for lane centering \n\n
 *		@ref P_TJALKA_LaneWidthMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum required lane width for lane centering \n\n
 *		@ref P_TJALKA_LnPredMinValidTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum required time of valid lanes and active controlling in LC or CMB mode for allowing both-sided lane prediction \n\n
 *		@ref P_TJALKA_LnPredictionCrvMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximum allowed lane curvature for lane prediction activation \n\n
 *		@ref P_TJALKA_LnPredictionTimeMax_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum allowed lane prediction duration \n\n
 *		@ref P_TJALKA_LnPredictionTimeMin_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Minimum prediction time for rampout prediction (prediction of lanes while outputs torque output is set to zero) \n\n
 *		@ref P_TJALKA_LnQualTurnOffTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn off delay time for lane quality check \n\n
 *		@ref P_TJALKA_LnQualTurnOnTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for lane quality check \n\n
 *		@ref P_TJALKA_MaxHeadAngActnTJA_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximum allowed ego vehicle heading angle for activation of TJA \n\n
 *		@ref P_TJALKA_MaxLnWdthUseCoup_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of coupled lane width for maximum lane width check \n\n
 *		@ref P_TJALKA_MinLnWdthUseUncoup_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable use of uncoupled lane width for minimum lane width check \n\n
 *		@ref P_TJALKA_PrjSpecQuC_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific cancel conditions for lane centering \n\n
 *		@ref P_TJALKA_PrjSpecQuSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific SR conditions for lane centering \n\n
 *		@ref P_TJALKA_PrjSpecQuWR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific WR conditions for lane centering \n\n
 *		@ref P_TJALKA_RadiusHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_200_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 200 \n
 *		\@description: \n
 *		Curvature radius hysteresis \n\n
 *		@ref P_TJALKA_RadiusMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		Minimum curvature radius for lane centering controlling \n\n
 *		@ref P_TJALKA_RampoutPredictOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable rampout prediction (lane prediction while LatDMC output is set to zero) \n\n
 *		@ref P_TJALKA_TransLnChecksOff_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TRUE if lane quality checks shall be disabled during SALC --> LC transition \n\n
 *		@ref P_TJALKA_ValidLengthMinHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_200_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 200 \n
 *		\@description: \n
 *		Minimum required valid length (hysteresis) \n\n
 *		@ref P_TJALKA_ValidLengthMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_200_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 200 \n
 *		\@description: \n
 *		Minimum required valid length \n\n
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
 *		@ref P_TJASLC_SALC_Enabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable semi-automatic lane change functionality \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJALKA Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJALKA_SEN/TJALKA/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJALKA_Testcase_Initialization) Initialization of the TJALKA module
 *		-# [Testcase_S_TJALKA_LnBndValid_nu](@ref TJALKA_Testcase_S_TJALKA_LnBndValid_nu) FCT_CMP_TJASA_1941, FCT_CMP_TJASA_1942, FCT_CMP_TJASA_1943, FCT_CMP_TJASA_1944: Lane validity check
 *		-# [Testcase_S_TJALKA_Cancel_bool](@ref TJALKA_Testcase_S_TJALKA_Cancel_bool) FCT_CMP_TJASA_1691: Cancel condition check check
 *		-# [Testcase_StrongReady_InvalidLanes](@ref TJALKA_Testcase_StrongReady_InvalidLanes) FCT_CMP_TJASA_1935: Lane validity check
 *		-# [Testcase_StrongReady_InvalidLaneWidth](@ref TJALKA_Testcase_StrongReady_InvalidLaneWidth) FCT_CMP_TJASA_1935: Lane width check
 *		-# [Testcase_StrongReady_InvalidVelocity](@ref TJALKA_Testcase_StrongReady_InvalidVelocity) FCT_CMP_TJASA_1935: Velocity check
 *		-# [Testcase_StrongReady_InvalidCurvature](@ref TJALKA_Testcase_StrongReady_InvalidCurvature) FCT_CMP_TJASA_1935: Curvature check
 *		-# [Testcase_StrongReady_InvalidLength](@ref TJALKA_Testcase_StrongReady_InvalidLength) FCT_CMP_TJASA_1935: Lane length check
 *		-# [Testcase_StrongReady_InvalidDist2Boundary](@ref TJALKA_Testcase_StrongReady_InvalidDist2Boundary) FCT_CMP_TJASA_1935: Distance to boundary check
 *		-# [Testcase_StrongReady_LaneCenteringDisabled](@ref TJALKA_Testcase_StrongReady_LaneCenteringDisabled) FCT_CMP_TJASA_1935: Velocity check
 *		-# [Testcase_StrongReady_TurnSignalEngaged](@ref TJALKA_Testcase_StrongReady_TurnSignalEngaged) FCT_CMP_TJASA_1935: Turn signal check
 *		-# [Testcase_StrongReady_ConstructionSite](@ref TJALKA_Testcase_StrongReady_ConstructionSite) FCT_CMP_TJASA_1935: Construction site check
 *		-# [Testcase_WeakReady_LaneChangeDetected](@ref TJALKA_Testcase_WeakReady_LaneChangeDetected) FCT_CMP_TJASA_1690: Lane change check
 *		-# [Testcase_WeakReady_LaneInCaptureRange](@ref TJALKA_Testcase_WeakReady_LaneInCaptureRange) FCT_CMP_TJASA_1690: Lane in capture range check
 *		-# [Testcase_WeakReady_Cancel](@ref TJALKA_Testcase_WeakReady_Cancel) FCT_CMP_TJASA_1690: Lane center mode cancel blocking time
 *		-# [Testcase_CancelConditions](@ref TJALKA_Testcase_CancelConditions) FCT_CMP_TJASA_1691: Cancel Condition
 *		-# [Testcase_CustomSpecificQualifier](@ref TJALKA_Testcase_CustomSpecificQualifier) Custom specific qualifier
 *		-# [Testcase_LanePrediction](@ref TJALKA_Testcase_LanePrediction) Test case for S_TJALKA_LanePredictValid_bool
 *		-# [Testcase_S_TJALKA_CombinedLaneSR_bool](@ref TJALKA_Testcase_S_TJALKA_CombinedLaneSR_bool) Test case for S_TJALKA_CombinedLaneSR_bool
 *		-# [Testcase_S_TJALKA_CombinedLaneWR_bool](@ref TJALKA_Testcase_S_TJALKA_CombinedLaneWR_bool) Test case for S_TJALKA_CombinedLaneSR_bool
 *		
 *	@traceability
 *		[\@link: TJALKA Module Requirements]()
 */
extern void TJALKA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // TJALKA_H_
