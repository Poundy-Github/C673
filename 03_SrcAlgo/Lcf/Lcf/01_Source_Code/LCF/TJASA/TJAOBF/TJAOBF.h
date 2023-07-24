/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAOBF
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:24:00CEST $
  $Log: TJAOBF.h  $
  Revision 1.4.1.2 2020/04/09 14:24:00CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:05:11CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJAOBF.h
//! @brief     (TJAOBF) Module Header.

#ifndef TJAOBF_H_
#define TJAOBF_H_

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
 *	TJAOBF module sensor initialization function. Function initializes TJAOBF sensor debug data pointer.
 *	
 *	@param
 *		[in] TJAOBF_SenDbgArg Pointer to TJAOBF sensor debug data.
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
extern void TJAOBF_SenInitDbgPtr(TJAOBF_SenDbgType *TJAOBF_SenDbgArg);

/*!
 *	TJAOBF module sensor initialization function. Function initializes TJAOBF sensor output data pointer.
 *	
 *	@param
 *		[in] TJAOBF_SenOutArg Pointer to TJAOBF sensor output data.
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
extern void TJAOBF_SenInitOutPtr(TJAOBF_SenOutType *TJAOBF_SenOutArg);

/*!
 *	TJAOBF module sensor reset function.
 *	
 *	@pre
 *		- The TJAOBF sensor initialization function(s) must be called once.
 *		- The TJAOBF sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_TJAOBF_ObjFollowInvalid_btf](@ref TJAOBF_SenDbgType::D_TJAOBF_ObjFollowInvalid_btf) \n
 *		[Debug  Signal] [D_TJAOBF_ObjInLaneInvalid_btf](@ref TJAOBF_SenDbgType::D_TJAOBF_ObjInLaneInvalid_btf) \n
 *		[Debug  Signal] [D_TJAOBF_TgtObjDataInvalid_btf](@ref TJAOBF_SenDbgType::D_TJAOBF_TgtObjDataInvalid_btf) \n
 *		[Debug  Signal] [S_TJAOBF_Cancel_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_Cancel_bool) \n
 *		[Debug  Signal] [S_TJAOBF_ObjInLaneValid_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_ObjInLaneValid_bool) \n
 *		[Debug  Signal] [S_TJAOBF_StrongReady_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_StrongReady_bool) \n
 *		[Debug  Signal] [S_TJAOBF_TgtObjDataValid_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_TgtObjDataValid_bool) \n
 *		[Debug  Signal] [S_TJAOBF_WeakReady_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_WeakReady_bool) \n
 *		[Output Signal] [S_TJAOBF_AccObjValid_bool](@ref TJAOBF_SenOutType::S_TJAOBF_AccObjValid_bool) \n
 *		[Output Signal] [S_TJAOBF_CombObjectCrv_1pm](@ref TJAOBF_SenOutType::S_TJAOBF_CombObjectCrv_1pm) \n
 *		[Output Signal] [S_TJAOBF_ObjectCrv_1pm](@ref TJAOBF_SenOutType::S_TJAOBF_ObjectCrv_1pm) \n\n
 *		For signal details, see sub-section [Globals](@ref TJAOBF_SenProcess_Globals) of the function @ref TJAOBF_SenProcess.
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
extern void TJAOBF_SenReset(void);

/*!
 *	TJAOBF module sensor process function.
 *	
 *	@pre
 *		- The TJAOBF sensor initialization function(s) must be called once.
 *		- The TJAOBF sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor TJAOBF_SenProcess_Globals
 *		[D_TJAOBF_ObjFollowInvalid_btf](@ref TJAOBF_SenDbgType::D_TJAOBF_ObjFollowInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJAOBF_DEBUG: ObjFollowInvalid_btf \n
 *		 \n
 *		0: LaneCheckDisabled \n
 *		1: AccObjectInvalid \n
 *		2: NoLeftLaneDetected \n
 *		3: LeLaneLengthInvalid \n
 *		4: NoRightLaneDetected \n
 *		5: RiLaneLengthInvalid \n
 *		6: ObjNotInEgoLane \n
 *		7: Dist2LeBndInvalid \n
 *		8: Dist2RiBndInvalid \n
 *		9-15: Reserved (0 by default) \n\n
 *		[D_TJAOBF_ObjInLaneInvalid_btf](@ref TJAOBF_SenDbgType::D_TJAOBF_ObjInLaneInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		TJAOBF_DEBUG: ObjectInLaneCheck__Bitfield \n
 *		 \n
 *		0: LaneCheckDisabled \n
 *		1: AccObjectInvalid \n
 *		2: NoLeftLaneDetected \n
 *		3: LeLaneLengthInvalid \n
 *		4: NoRightLaneDetected \n
 *		5: RiLaneLengthInvalid \n
 *		6: ObjNotInEgoLane \n
 *		7: Dist2LeBndInvalid \n
 *		8: Dist2RiBndInvalid \n
 *		9-15: Reserved (0 by default) \n\n
 *		[D_TJAOBF_TgtObjDataInvalid_btf](@ref TJAOBF_SenDbgType::D_TJAOBF_TgtObjDataInvalid_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		TJAOBF_DEBUG: TgtObjDataInvalid_btf \n\n
 *		[S_TJAOBF_Cancel_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_Cancel_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if cancel condition for object following are fulfilled. \n\n
 *		[S_TJAOBF_ObjInLaneValid_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_ObjInLaneValid_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if target object validated to be driving within the ego lane \n\n
 *		[S_TJAOBF_StrongReady_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_StrongReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if strong ready condition for object following are fulfilled. \n\n
 *		[S_TJAOBF_TgtObjDataValid_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_TgtObjDataValid_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if target object data is valid for controlling in OF or CMB mode \n\n
 *		[S_TJAOBF_WeakReady_bool](@ref TJAOBF_SenDbgType::S_TJAOBF_WeakReady_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		TJAOBF_OUTPUT \n
 *		 \n
 *		Indicates true if weak ready condition for object following are fulfilled. \n\n
 *		[S_TJAOBF_AccObjValid_bool](@ref TJAOBF_SenOutType::S_TJAOBF_AccObjValid_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE, if ACC object is valid for object following mode. \n\n
 *		[S_TJAOBF_CombObjectCrv_1pm](@ref TJAOBF_SenOutType::S_TJAOBF_CombObjectCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Object curvature based on ACC object measurement position and lateral offset / heading angle of ABPR center lane \n\n
 *		[S_TJAOBF_ObjectCrv_1pm](@ref TJAOBF_SenOutType::S_TJAOBF_ObjectCrv_1pm) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Object curvature based on ACC object measurement position \n\n
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
 *		@ref S_ABPLBP_LeLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Left lane clothoid change of curvature \n\n
 *		@ref S_ABPLBP_LeLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left lane clothoid curvature \n\n
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
 *		@ref S_ABPLBP_LeLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Left lane clothoid X0 position \n\n
 *		@ref S_ABPLBP_LeLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left lane clothoid Y0 position (init +10m) \n\n
 *		@ref S_ABPLBP_LeLnQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the left ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
 *		@ref S_ABPLBP_RiLnClthCrvChng_1pm2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm2_m0p001_0p001_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m^2 \n
 *		\@min: -0.001 \n
 *		\@max: 0.001 \n
 *		\@description: \n
 *		Right lane clothoid curvature change \n\n
 *		@ref S_ABPLBP_RiLnClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right lane clothoid curvature \n\n
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
 *		@ref S_ABPLBP_RiLnClthPosX0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m300_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -300 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Right lane clothoid X0 position \n\n
 *		@ref S_ABPLBP_RiLnClthPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right lane clothoid Y0 position (init -10m) \n\n
 *		@ref S_ABPLBP_RiLnQuality_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Quality of the right ego lane information based on standard deviations, paralell model, iQuality (input from ABD) and the lookahead distance \n\n
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
 *		@ref S_ODPFOH_TgtObjClothoidInv_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		ODPFOH Invalid Bitfield: \n
 *		0: AccObjInvalidAsNewSample \n
 *		1: AccObjPosFreeze \n
 *		2: ObjValidTransitionOngoing \n
 *		3: CutInTransitionOngoing \n
 *		4: CutOutTransitionOngoing \n
 *		5: FreezeStopTransOngoing \n
 *		6: TrajNotUpdated \n
 *		7: TrajInvalid \n
 *		8: HistoryModeInactive (Polyfit) \n
 *		9: LowSpeedModeInactive \n
 *		10: LowSpeedModeTransitionOngoing \n
 *		11: TrajInvTransitionOngoing \n
 *		12: HistoryDisabled \n
 *		13: HistroyReset \n\n
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
 *		@ref S_ODPFOH_TgtObjPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m30_30_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -30 \n
 *		\@max: 30 \n
 *		\@description: \n
 *		Target object position Y0 \n\n
 *		@ref S_ODPFOP_AccObjInvBitfield_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Invalid Bitfield Description: \n
 *		Bit 0: ACC Object Detected \n
 *		Bit 1: Object Quality \n
 *		Bit 2: Object Measurement state \n
 *		Bit 3: PosY \n
 *		Bit 4: PosX \n
 *		Bit 5: Object Width \n
 *		Bit 6: Object longitudinal velocity \n
 *		Bit 7: Object lateral velocity \n
 *		Bit 8: Object longitudinal acceleration \n
 *		Bit 9: Object type \n
 *		Bit 10: Object Fusion state \n
 *		Bit 11: Object ID switch \n
 *		Bit 12: unused \n
 *		Bit 13: unused \n
 *		Bit 14: unused \n
 *		Bit 15: unused \n\n
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
 *		@ref S_TJALKA_LnBndValid_nu \n
 *		\@kind: Input Signal \n
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
 *		@ref P_TJACMB_LnQualMinHystWR_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum required lane quality hysteresis for lane based combined mode activation \n\n
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
 *		@ref P_TJALKA_BlockTimeTJA_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		TJA Blocking time \n\n
 *		@ref P_TJALKA_VelXHyst_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Longitudinal velocity hysteresis \n\n
 *		@ref P_TJAOBF_AccObjChange_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check if the ID of the target object has changed. \n\n
 *		@ref P_TJAOBF_AccObjLanesInvalid_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit mask to check ACC object validity for object in target lane evalution (ignoring lateral position validity) \n\n
 *		@ref P_TJAOBF_AccObjectInvalid_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit mask to check ACC object validity \n\n
 *		@ref P_TJAOBF_CheckAccObjValidty_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable check of Acc object validity within TJAOBF as SR condition for pure object following \n\n
 *		@ref P_TJAOBF_ConstSiteCheckOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable construction site check for OF SR condition \n\n
 *		@ref P_TJAOBF_CutinObValidFreezTm_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Freeze time of Acc object validity status after object cut-in \n\n
 *		@ref P_TJAOBF_DefaultLaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Assumption of default lane width for object-in-lane check for maximum distance to lane boundary \n\n
 *		@ref P_TJAOBF_DrvStInvalidSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask for turn signal SR condition check \n\n
 *		@ref P_TJAOBF_LaneCheckEnabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable object in lane evaluation \n\n
 *		@ref P_TJAOBF_MaxDiffLnLen2ObjPosX_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum longitudinal difference between detected lane length and acc object position x for object  in lane evaluation \n\n
 *		@ref P_TJAOBF_MaxDurObjBrdg_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximum allowed duration of object bridging mode at high velocities \n\n
 *		@ref P_TJAOBF_MinDurAccObjValid_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum duration of ACC object validity for activation of object following and combined mode \n\n
 *		@ref P_TJAOBF_MinDurLCforOB_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum duration of Lane Centering availability to allow object bridging at high velocities \n\n
 *		@ref P_TJAOBF_MinDurObjLnValidWR_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum duration of object in lane validity as WR condition \n\n
 *		@ref P_TJAOBF_OF_Enabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable object following mode \n\n
 *		@ref P_TJAOBF_ObjBrdgEnabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable object briding at speeds greated than P_TJAOBF_VelXMax_kph \n\n
 *		@ref P_TJAOBF_ObjLnCheckMinVelX_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum longitudinal velocity to allow object-in-lane assessment \n\n
 *		@ref P_TJAOBF_PrjSpecQuC_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific cancel conditions for object following \n\n
 *		@ref P_TJAOBF_PrjSpecQuSR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific SR conditions for object following \n\n
 *		@ref P_TJAOBF_PrjSpecQuWR_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask to check project specific WR conditions for object following \n\n
 *		@ref P_TJAOBF_TgtClthCrvMaxHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_0_0p1_1em6_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: 0 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Maximum allowed target object clothoid curvature for OF mode activation (hysteresis) \n\n
 *		@ref P_TJAOBF_TgtClthHeadMaxHyst_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Maximum allowed target object clothoid heading angle for OF mode activation \n\n
 *		@ref P_TJAOBF_TgtClthInvalid_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bit mask to check validity of ACC object clothoid generation \n\n
 *		@ref P_TJAOBF_TgtClthLengthMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum required object trajectory length \n\n
 *		@ref P_TJAOBF_TgtClthMinValidTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum validity time of target clothoid features for OF mode activation \n\n
 *		@ref P_TJAOBF_TgtClthPosYMaxHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed target object clothoid pos Y0 for OF mode activation (hysteresis) \n\n
 *		@ref P_TJAOBF_TgtClthWRInvalid_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask for target object clothoid weak ready check \n\n
 *		@ref P_TJAOBF_TgtVehDist2LnBndHst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Target vehicle minimum distance to lane boundary hysteresis \n
 *		 \n
 *		(Distance defined as vehicle center to lane boundary) \n\n
 *		@ref P_TJAOBF_TgtVehDist2LnBndMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_5_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 5 \n
 *		\@description: \n
 *		Target vehicle minimum distance to lane boundary hysteresis \n
 *		 \n
 *		(Distance defined as vehicle center to lane boundary) \n\n
 *		@ref P_TJAOBF_VelXMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum longitudinal velocity allowed for object following mode \n\n
 *		@ref P_TJAOBF_VelXMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_m72_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: -72 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Minimum longitudinal velocity required for object following mode \n\n
 *		@ref P_TJASLC_SALC_Enabled_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to enable semi-automatic lane change functionality \n\n
 *		@ref X_TJAOBF_VehVelX_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		TJAOBF VehVelX x-axis for lookup tables \n\n
 *		@ref Y_TJAOBF_TgtClthCrvMaxWR_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p02_0p02_1em9_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.02 \n
 *		\@max: 0.02 \n
 *		\@description: \n
 *		Maximum allowed target object clothoid curvature for OF mode activation (WR condition) \n\n
 *		@ref Y_TJAOBF_TgtClthHeadMaxWR_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Maximum allowed target object clothoid heading angle for OF mode activation (WR condition) \n\n
 *		@ref Y_TJAOBF_TgtClthPosYMaxWR_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed target object clothoid lateral position Y0 for OF mode activation (WR condition) \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: TJAOBF Module Software Detailed Design](http://ims-adas:7001/si/viewproject?projectName=%23/ADAS/SW%23Components/LCF_LateralControlFunctions%23forceJump%3D%23d%3DMFC431x_Family_Trunk%2303_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJAOBF_SEN/TJAOBF/d)
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref TJAOBF_Testcase_Initialization) Initialization of the TJAOBF module
 *		-# [Testcase_StrongReady_Velocity](@ref TJAOBF_Testcase_StrongReady_Velocity) Velocity invalid
 *		-# [Testcase_StrongReady_ObjectBridging](@ref TJAOBF_Testcase_StrongReady_ObjectBridging) Object bridging invalid
 *		-# [Testcase_StrongReady_TurnSignal](@ref TJAOBF_Testcase_StrongReady_TurnSignal) Turn signal check
 *		-# [Testcase_StrongReady_FunctionSwitch](@ref TJAOBF_Testcase_StrongReady_FunctionSwitch) LKA only enabled
 *		-# [Testcase_StrongReady_ConstructionSite](@ref TJAOBF_Testcase_StrongReady_ConstructionSite) Set construction site detected
 *		-# [Testcase_StrongReady_TgtClothoidInvalid](@ref TJAOBF_Testcase_StrongReady_TgtClothoidInvalid) Set ODPFOH target clothoid invalid
 *		-# [Testcase_StrongReady_TgtClothLengthInvalid](@ref TJAOBF_Testcase_StrongReady_TgtClothLengthInvalid) Set ODPFOH target clothoid length invalid
 *		-# [Testcase_StrongWeakReady_TgtClthPosYInvalid](@ref TJAOBF_Testcase_StrongWeakReady_TgtClthPosYInvalid) Test case for WR conds - Invalid target clothoid lateral position
 *		-# [Testcase_StrongWeakReady_TgtClthHeadInvalid](@ref TJAOBF_Testcase_StrongWeakReady_TgtClthHeadInvalid) Test case for WR conds - Invalid target clothoid heading
 *		-# [Testcase_StrongWeakReady_TgtClthCrvInvalid](@ref TJAOBF_Testcase_StrongWeakReady_TgtClthCrvInvalid) Test case for WR conds - Invalid target clothoid curvature
 *		-# [Testcase_WeakReady_CustomSpecConds](@ref TJAOBF_Testcase_WeakReady_CustomSpecConds) Test case for weak ready custom specific conditions
 *		-# [Testcase_WeakReady_BlockingTime](@ref TJAOBF_Testcase_WeakReady_BlockingTime) Test case for weak ready blocking time
 *		-# [Testcase_S_TJAOBF_Cancel_bool](@ref TJAOBF_Testcase_S_TJAOBF_Cancel_bool) Cancel conditions check
 *		-# [Testcase_CustomSpecificQualifier](@ref TJAOBF_Testcase_CustomSpecificQualifier) Custom specific qualifier
 *		-# [Testcase_S_TJAOBF_AccObjValid_bool](@ref TJAOBF_Testcase_S_TJAOBF_AccObjValid_bool) Validity check of ACC object without lanes
 *		-# [Testcase_AccObjectChange](@ref TJAOBF_Testcase_AccObjectChange) Validity check during ACC object change
 *		-# [Testcase_S_TJAOBF_ObjInLaneValid_bool](@ref TJAOBF_Testcase_S_TJAOBF_ObjInLaneValid_bool) Check if target object distance to both lanes is valid
 *		-# [Testcase_LaneCheck_MinDist2LeftBndValid](@ref TJAOBF_Testcase_LaneCheck_MinDist2LeftBndValid) Check if target object distance to left lane is valid
 *		-# [Testcase_LaneCheck_MinDist2RightBndValid](@ref TJAOBF_Testcase_LaneCheck_MinDist2RightBndValid) Check if target object distance to right lane is valid
 *		-# [Testcase_LaneCheck_EgoLaneValid](@ref TJAOBF_Testcase_LaneCheck_EgoLaneValid) Check if target object drives within ego lane
 *		-# [Testcase_LaneCheck_LaneCrvInvalid](@ref TJAOBF_Testcase_LaneCheck_LaneCrvInvalid) Disable object-lane-check if lane crv invalid
 *		
 *	@traceability
 *		[\@link: TJAOBF Module Requirements]()
 */
extern void TJAOBF_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif /* TJAOBF_H_*/
