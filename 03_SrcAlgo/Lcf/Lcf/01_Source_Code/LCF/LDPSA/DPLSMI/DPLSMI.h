/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSMI.h
//! @brief     (DPLSMI) Module Header.

#ifndef DPLSMI_H_
#define DPLSMI_H_

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
 *	DPLSMI module sensor initialization function. Function initializes DPLSMI sensor debug data pointer.
 *	
 *	@param
 *		[in] DPLSMI_SenDbgArg Pointer to DPLSMI sensor debug data.
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
extern void DPLSMI_SenInitDbgPtr(DPLSMI_SenDbgType *DPLSMI_SenDbgArg);

/*!
 *	DPLSMI module sensor initialization function. Function initializes DPLSMI sensor output data pointer.
 *	
 *	@param
 *		[in] DPLSMI_SenOutArg Pointer to DPLSMI sensor output data.
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
extern void DPLSMI_SenInitOutPtr(DPLSMI_SenOutType *DPLSMI_SenOutArg);

/*!
 *	DPLSMI module sensor reset function.
 *	
 *	@pre
 *		- The DPLSMI sensor initialization function(s) must be called once.
 *		- The DPLSMI sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DPLSMI_Cancel_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_Cancel_btf) \n
 *		[Debug  Signal] [D_DPLSMI_DlcLeThreshold_met](@ref DPLSMI_SenDbgType::D_DPLSMI_DlcLeThreshold_met) \n
 *		[Debug  Signal] [D_DPLSMI_DlcRiThreshold_met](@ref DPLSMI_SenDbgType::D_DPLSMI_DlcRiThreshold_met) \n
 *		[Debug  Signal] [D_DPLSMI_StrongReady_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_StrongReady_btf) \n
 *		[Debug  Signal] [D_DPLSMI_SysStateLDP_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_SysStateLDP_btf) \n
 *		[Debug  Signal] [D_DPLSMI_TlcLeThreshold_sec](@ref DPLSMI_SenDbgType::D_DPLSMI_TlcLeThreshold_sec) \n
 *		[Debug  Signal] [D_DPLSMI_TlcRiThreshold_sec](@ref DPLSMI_SenDbgType::D_DPLSMI_TlcRiThreshold_sec) \n
 *		[Debug  Signal] [D_DPLSMI_TriggerLe_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_TriggerLe_btf) \n
 *		[Debug  Signal] [D_DPLSMI_TriggerRi_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_TriggerRi_btf) \n
 *		[Debug  Signal] [D_DPLSMI_WeakReady_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_WeakReady_btf) \n
 *		[Debug  Signal] [S_DPLSMI_DangerousSide_nu](@ref DPLSMI_SenDbgType::S_DPLSMI_DangerousSide_nu) \n
 *		[Debug  Signal] [S_DPLSMI_FunctionAborted_bool](@ref DPLSMI_SenDbgType::S_DPLSMI_FunctionAborted_bool) \n
 *		[Debug  Signal] [S_DPLSMI_ReadyToTrigger_bool](@ref DPLSMI_SenDbgType::S_DPLSMI_ReadyToTrigger_bool) \n
 *		[Output Signal] [S_DPLSMI_SysStateLDPLe_nu](@ref DPLSMI_SenOutType::S_DPLSMI_SysStateLDPLe_nu) \n
 *		[Output Signal] [S_DPLSMI_SysStateLDPRi_nu](@ref DPLSMI_SenOutType::S_DPLSMI_SysStateLDPRi_nu) \n
 *		[Output Signal] [S_DPLSMI_SysStateLDP_nu](@ref DPLSMI_SenOutType::S_DPLSMI_SysStateLDP_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref DPLSMI_SenProcess_Globals) of the function @ref DPLSMI_SenProcess.
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
extern void DPLSMI_SenReset(void);

/*!
 *	DPLSMI module sensor process function.
 *	
 *	@pre
 *		- The DPLSMI sensor initialization function(s) must be called once.
 *		- The DPLSMI sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPLSMI_SenProcess_Globals
 *		[D_DPLSMI_Cancel_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_Cancel_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDP cancel conditions. \n\n
 *		[D_DPLSMI_DlcLeThreshold_met](@ref DPLSMI_SenDbgType::D_DPLSMI_DlcLeThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
 *		[D_DPLSMI_DlcRiThreshold_met](@ref DPLSMI_SenDbgType::D_DPLSMI_DlcRiThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
 *		[D_DPLSMI_StrongReady_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_StrongReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDP strong ready conditions. \n\n
 *		[D_DPLSMI_SysStateLDP_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_SysStateLDP_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDP state machine inputs. \n\n
 *		[D_DPLSMI_TlcLeThreshold_sec](@ref DPLSMI_SenDbgType::D_DPLSMI_TlcLeThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
 *		[D_DPLSMI_TlcRiThreshold_sec](@ref DPLSMI_SenDbgType::D_DPLSMI_TlcRiThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
 *		[D_DPLSMI_TriggerLe_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_TriggerLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger condition for left side. \n\n
 *		[D_DPLSMI_TriggerRi_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_TriggerRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger condition for right side. \n\n
 *		[D_DPLSMI_WeakReady_btf](@ref DPLSMI_SenDbgType::D_DPLSMI_WeakReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDP weak ready conditions. \n\n
 *		[S_DPLSMI_DangerousSide_nu](@ref DPLSMI_SenDbgType::S_DPLSMI_DangerousSide_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		[S_DPLSMI_FunctionAborted_bool](@ref DPLSMI_SenDbgType::S_DPLSMI_FunctionAborted_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		The signal is 1 for the whole rampout duration if the rampout was caused by an abort condition. \n\n
 *		[S_DPLSMI_ReadyToTrigger_bool](@ref DPLSMI_SenDbgType::S_DPLSMI_ReadyToTrigger_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		The signal is true when the LDP strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
 *		[S_DPLSMI_SysStateLDPLe_nu](@ref DPLSMI_SenOutType::S_DPLSMI_SysStateLDPLe_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		System State for the left side of the LDP function. \n\n
 *		[S_DPLSMI_SysStateLDPRi_nu](@ref DPLSMI_SenOutType::S_DPLSMI_SysStateLDPRi_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		System State for the right side of the LDP function. \n\n
 *		[S_DPLSMI_SysStateLDP_nu](@ref DPLSMI_SenOutType::S_DPLSMI_SysStateLDP_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the LDP function. \n\n
 *		@ref S_ABPLBP_LaneChangeDetected_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Flag that indicates a detected lane change \n\n
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
 *		@ref S_ABPLBP_LeLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left lane clothoid heading angle \n\n
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
 *		@ref S_ABPLBP_RiLnClthHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right lane clothoid heading angle \n\n
 *		@ref S_CUSTOM_LDPDlcLimitLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing limit zone for the LDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_LDPDlcLimitRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing limit zone for the LDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_LDPDlcTrgLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing threshold for the LDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_LDPDlcTrgRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing threshold for the LDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_PrjSpecQu_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield containing all the relevant information of the customer projects. \n\n
 *		@ref S_DPLSIA_CurveTypeLe_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_DPLSIA_CurveTypeRi_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		@ref S_DPLSIA_DlcLeLDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the LDP. \n\n
 *		@ref S_DPLSIA_DlcRiLDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the LDP. \n\n
 *		@ref S_DPLSIA_LaneWidthLDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across LDP. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref S_DPLSIA_LnBndLeValidLDP_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDP and LDW functions. \n\n
 *		@ref S_DPLSIA_LnBndRiValidLDP_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDP and LDW functions. \n\n
 *		@ref S_DPLSIA_SideCondLDPLe_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the LDP. \n\n
 *		@ref S_DPLSIA_SideCondLDPRi_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the LDP. \n\n
 *		@ref S_DPLSIA_SpecificLDP_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the LDP. \n\n
 *		@ref S_DPLSIA_TlcLeLDP_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the LDP. \n\n
 *		@ref S_DPLSIA_TlcRiLDP_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the LDP. \n\n
 *		@ref S_DPLSIA_VelLatLeLDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the LDP. \n\n
 *		@ref S_DPLSIA_VelLatRiLDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the LDP. \n\n
 *		@ref S_DPLTTG_LeTgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lateral distance to the target when a dangerous situation on the left side takes place. \n\n
 *		@ref S_DPLTTG_RiTgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Lateral distance to the target when a dangerous situation on the right side takes place. \n\n
 *		@ref S_LCFRCV_ErrorStateLDP_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Error State of the LDP function. \n\n
 *		@ref S_LCFRCV_LDPMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Sensitivity mode of the LDP. \n\n
 *		@ref S_LCFRCV_LDPSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the LDP \n\n
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
 *		@ref S_LCFRCV_SysStOffLatDMC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if DMC_LAT_STATUS = 0 (LCF_LADMC_OFF) \n\n
 *		@ref S_LCFRCV_SysStOnLatDMC_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Indicates TRUE if DMC_LAT_STATUS = 1, 2 or 3 (LCF_LADMC_ON) \n\n
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
 *		@ref S_TCTCLM_QuServTrajCtr_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Trajectory controller qualifier. Includes relevant information for the Situation Assessment components. \n\n
 *		@ref S_TPLFBT_QuStatusTrajPlan_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Notes for S_TPLTJC_QuStatusTrajPlan_nu: \n
 *		Bitfield indicates the status of trajectory planner: 1 Not OK, 0 OK \n
 *		0 bit: min acceleration check  \n
 *		1 bit: max acceleration check  \n
 *		2 bit: right corridor boundary collision check  \n
 *		3 bit: left corridor boundary collision check  \n
 *		4 bit: object collision check  \n
 *		5 bit: matrix invertible   \n
 *		6 bit: trajectory length  \n
 *		7 bit: max jerk check  \n
 *		8 bit: lane cross check  \n
 *		9 bit: target lateral distance  \n
 *		10 bit: vehicle lateral distance  \n
 *		11 bit: right corridor transformation  \n
 *		12 bit: target corridor transformation  \n
 *		13 bit: left corridor transformation  \n
 *		14 bit: input target corridor heading \n\n
 *		@ref S_VDPDRV_ActiveStCtrl_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: ActiveCtrlABS \n
 *		1: ActiveCtrlACC \n
 *		2: ActiveCtrlESC \n
 *		3: ActiveCtrlTCS \n
 *		4: ActiveCtrlVSM \n
 *		5: Reserved \n
 *		6: Reserved \n
 *		7: Reserved \n\n
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
 *		@ref S_VDPDRV_SysStError_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: SystemErrorABS \n
 *		1: SystemErrorACC \n
 *		2: SystemErrorESC \n
 *		3: SystemErrorTCS \n
 *		4: SystemErrorVSM \n
 *		5: SystemErrorVDY \n
 *		6: SystemErrorLatDMC \n
 *		7: Reserved \n\n
 *		@ref S_VDPDRV_SysStNotAvailable_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: SystemNotAvailableABS \n
 *		1: SystemNotAvailableACC \n
 *		2: SystemNotAvailableESC \n
 *		3: SystemNotAvailableTCS \n
 *		4: SystemNotAvailableVSM \n
 *		5: Reserved \n
 *		6: Reserved \n
 *		7: Reserved \n\n
 *		@ref S_VDPDRV_VehStInvalid_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		VDPDRV_OUTPUT \n
 *		 \n
 *		0: DoorOpen \n
 *		1: VehicleNotReadyToStart \n
 *		2: TrailerPresent \n
 *		3: InvalidGearEngaged \n
 *		4: VehDoesMovesBckwd \n
 *		5: OversteerDetected \n
 *		6: UndersteerDetected \n
 *		7: RollerBenchDetected \n
 *		8: SteeringStopDetected \n
 *		9: Reserved (0 by default) \n
 *		10: Reserved (0 by default) \n
 *		11: Reserved (0 by default) \n
 *		12: Reserved (0 by default) \n
 *		13: Reserved (0 by default) \n
 *		14: Reserved (0 by default) \n
 *		15: Reserved (0 by default) \n\n
 *		@ref P_DPLSIA_SafetyIfaceLDPOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the data from the safety interface will be used to trigger the LDP. Else, the control interface data will be used. \n\n
 *		@ref P_DPLSMI_AbortDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_AbortFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_AbortFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf  are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_AbortFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_AbortFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_AbortSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_AbortVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to abort a lateral intervention. \n\n
 *		@ref P_DPLSMI_BlockingTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Duration of the blocking time between two LDP lateral interventions. \n\n
 *		@ref P_DPLSMI_CancelDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_CancelFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_CancelFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_CancelFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_CancelFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_CancelSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_CancelVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_DebugDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
 *		@ref P_DPLSMI_DebugSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used for the SysState debug signal. \n\n
 *		@ref P_DPLSMI_DegrTimeOut_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time out parameter for the degradation watch dog timer. \n\n
 *		@ref P_DPLSMI_DlcLimitMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
 *		@ref P_DPLSMI_DlcLimitMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
 *		@ref P_DPLSMI_ErrorStateLDPEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPLSMI_ErrorStateLDP_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the Error State Signal. \n\n
 *		@ref P_DPLSMI_FctCustomBSMLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM left lateral intervention. \n\n
 *		@ref P_DPLSMI_FctCustomBSMRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM right lateral intervention. \n\n
 *		@ref P_DPLSMI_FctCustomCancelLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left lateral intervention. \n\n
 *		@ref P_DPLSMI_FctCustomCancelRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right lateral intervention. \n\n
 *		@ref P_DPLSMI_FctCustomTrgLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left lateral intervention. \n\n
 *		@ref P_DPLSMI_FctCustomTrgRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right lateral intervention. \n\n
 *		@ref P_DPLSMI_FinishCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions are used in order to finish a lateral intervention. \n\n
 *		@ref P_DPLSMI_HazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DLC is bigger than this tolerance across the lane marking the intervention is cancelled. \n\n
 *		@ref P_DPLSMI_HazardFinishDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPLSMI_HazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPLSMI_HazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPLSMI_LDPSwitchEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPLSMI_LDPSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the HMI Switch. \n\n
 *		@ref P_DPLSMI_LatDMCClearEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Enabler of the SysStateDMC as clearance condition \n\n
 *		@ref P_DPLSMI_NoHazardCancelDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DLC is apart from the lane marking a distance bigger than this tolerance in the opposite direction of the dangerous situation the intervention is cancelled. \n\n
 *		@ref P_DPLSMI_NoHazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DLC is apart from the target a distance bigger than this tolerance in the opposite direction of the dangerous situation the intervention is cancelled. \n\n
 *		@ref P_DPLSMI_NoHazardFinishDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. \n\n
 *		@ref P_DPLSMI_NoHazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading angle has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the oppposite directon of the dangerous situation. \n\n
 *		@ref P_DPLSMI_NoHazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the oppposite directon of the dangerous situation. \n\n
 *		@ref P_DPLSMI_OnTargetFinishTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time for which all the finish conditions have to be fulfilled in order to consider an intervention finished. \n\n
 *		@ref P_DPLSMI_QuTrajCtrCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to cancel an LDP intevention. \n\n
 *		@ref P_DPLSMI_QuTrajCtrClearance_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to give the clearance to an LDP intevention. \n\n
 *		@ref P_DPLSMI_QuTrajPlanCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to cancel an LDP intevention. \n\n
 *		@ref P_DPLSMI_QuTrajPlanClearance_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to give the clearance to an an LDP intevention. \n\n
 *		@ref P_DPLSMI_RequestTimeOut_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal time that the LDP can be in state REQUEST. \n\n
 *		@ref P_DPLSMI_SafeSituationDelay_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the safe situation condition. \n\n
 *		@ref P_DPLSMI_SafeSituationOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		To avoid two lateral interventions with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
 *		@ref P_DPLSMI_SafeSituationState_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
 *		@ref P_DPLSMI_SideCondCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDPLe_btf/S_DPLSIA_SideCondLDPRi_btf are used in order to cancel a lateral intervention. \n\n
 *		@ref P_DPLSMI_SideCondDebug_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDPLe_btf/S_DPLSIA_SideCondLDPRi_btf are used for the SysState debug signal \n\n
 *		@ref P_DPLSMI_SideCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDPLe_btf/S_DPLSIA_SideCondLDPRi_btf are used in order to trigger a lateral intervention. \n\n
 *		@ref P_DPLSMI_StrgRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_StrgRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_StrgRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_StrgRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_StrgRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_StrgRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_StrgRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMI_SuppressDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_SuppressFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_SuppressFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_SuppressFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_SuppressFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_SuppressSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_SuppressVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to suppress a lateral intervention. \n\n
 *		@ref P_DPLSMI_TlcDistanceMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
 *		@ref P_DPLSMI_TlcValidMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time that the TLC criterium shall be fulfilled to be used to trigger. \n\n
 *		@ref P_DPLSMI_TriggerCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions are used in order to trigger a lateral intervention. \n\n
 *		@ref P_DPLSMI_TriggerHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Holding time when the trigger threshold was exceeded. \n\n
 *		@ref P_DPLSMI_WeakRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMI_WeakRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_FunctionCustom_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMI_WeakRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMI_WeakRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the weakready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMI_WeakRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMI_WeakRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDP_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMI_WeakRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_LDP_DlcLimitCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Limit Switch for the LDP. \n\n
 *		@ref P_LDP_DlcTriggerCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Threshold Switch for the LDP. \n\n
 *		@ref P_LDP_Existing_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
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
 *		@ref X_LCF_LaneWidth_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		 \n\n
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
 *		@ref Y_DPLSMI_CrvICDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		InnerCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMI_CrvICTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		InnerCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMI_CrvOCDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		OuterCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMI_CrvOCTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		OuterCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMI_LWContrMaxDurScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the LDP. \n\n
 *		@ref Y_DPLSMI_LWHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPLSMI_LWNoHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPLSMI_LWTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Dlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPLSMI_LWTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Tlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPLSMI_VXContrMaxDur_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the LDP. \n\n
 *		@ref Y_DPLSMI_VXMD1TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPLSMI_VXMD1TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to lane crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPLSMI_VXMD2TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPLSMI_VXMD2TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to lane crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPLSMI_VXMD3TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 3. SpeedX dependant. \n\n
 *		@ref Y_DPLSMI_VXMD3TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to lane crossing. Mode 3. SpeedX dependant. \n\n
 *		@ref Y_DPLSMI_VYTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Dlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPLSMI_VYTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Dlc Scaling Factor - Lane Width Dependant \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPLSMI Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPLSMI_Testcase_Initialization) Initialization of the DPLSMI
 *		-# [Testcase_Coded_Function](@ref DPLSMI_Testcase_Coded_Function) LDP Coded
 *		-# [Testcase_Function_Switch](@ref DPLSMI_Testcase_Function_Switch) LDP Switch
 *		-# [Testcase_Weak_Ready](@ref DPLSMI_Testcase_Weak_Ready) Weak Ready Conditions
 *		-# [Testcase_Strong_Ready](@ref DPLSMI_Testcase_Strong_Ready) Strong Ready Conditions
 *		-# [Testcase_TriggerLeft](@ref DPLSMI_Testcase_TriggerLeft) Trigger Left Conditions
 *		-# [Testcase_TriggerRight](@ref DPLSMI_Testcase_TriggerRight) Trigger Right Conditions
 *		-# [Testcase_TriggerBSM](@ref DPLSMI_Testcase_TriggerBSM) Trigger BSM Conditions
 *		-# [Testcase_Suppress](@ref DPLSMI_Testcase_Suppress) Suppress Conditions
 *		-# [Testcase_Finish](@ref DPLSMI_Testcase_Finish) Finish Conditions
 *		-# [Testcase_Cancel](@ref DPLSMI_Testcase_Cancel) Cancel Conditions
 *		-# [Testcase_Abort](@ref DPLSMI_Testcase_Abort) Abort Conditions
 *		-# [Testcase_Degradation](@ref DPLSMI_Testcase_Degradation) Degradation Conditions
 *		-# [Testcase_Clearance](@ref DPLSMI_Testcase_Clearance) Suppress Conditions
 *		-# [Testcase_Function_Error](@ref DPLSMI_Testcase_Function_Error) LDP Error
 *		-# [Testcase_State_Machine](@ref DPLSMI_Testcase_State_Machine) LDP System State
 *		-# [Testcase_Internal_System_State_Left](@ref DPLSMI_Testcase_Internal_System_State_Left) Internal System State - Left Side
 *		-# [Testcase_Internal_System_State_Right](@ref DPLSMI_Testcase_Internal_System_State_Right) Internal System State - Right Side
 *		
 *	@traceability
 *		[\@link: DPLSMI Module Requirements]()
 */
extern void DPLSMI_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPLSMI_H_
