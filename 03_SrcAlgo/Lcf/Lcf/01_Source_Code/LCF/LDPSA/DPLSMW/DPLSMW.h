/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSMW.h
//! @brief     (DPLSMW) Module Header.

#ifndef DPLSMW_H_
#define DPLSMW_H_

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
 *	DPLSMW module sensor initialization function. Function initializes DPLSMW sensor debug data pointer.
 *	
 *	@param
 *		[in] DPLSMW_SenDbgArg Pointer to DPLSMW sensor debug data.
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
extern void DPLSMW_SenInitDbgPtr(DPLSMW_SenDbgType *DPLSMW_SenDbgArg);

/*!
 *	DPLSMW module sensor initialization function. Function initializes DPLSMW sensor output data pointer.
 *	
 *	@param
 *		[in] DPLSMW_SenOutArg Pointer to DPLSMW sensor output data.
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
extern void DPLSMW_SenInitOutPtr(DPLSMW_SenOutType *DPLSMW_SenOutArg);

/*!
 *	DPLSMW module sensor reset function.
 *	
 *	@pre
 *		- The DPLSMW sensor initialization function(s) must be called once.
 *		- The DPLSMW sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DPLSMW_Cancel_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_Cancel_btf) \n
 *		[Debug  Signal] [D_DPLSMW_DlcLeThreshold_met](@ref DPLSMW_SenDbgType::D_DPLSMW_DlcLeThreshold_met) \n
 *		[Debug  Signal] [D_DPLSMW_DlcRiThreshold_met](@ref DPLSMW_SenDbgType::D_DPLSMW_DlcRiThreshold_met) \n
 *		[Debug  Signal] [D_DPLSMW_StrongReady_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_StrongReady_btf) \n
 *		[Debug  Signal] [D_DPLSMW_SysStateLDW_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_SysStateLDW_btf) \n
 *		[Debug  Signal] [D_DPLSMW_TlcLeThreshold_sec](@ref DPLSMW_SenDbgType::D_DPLSMW_TlcLeThreshold_sec) \n
 *		[Debug  Signal] [D_DPLSMW_TlcRiThreshold_sec](@ref DPLSMW_SenDbgType::D_DPLSMW_TlcRiThreshold_sec) \n
 *		[Debug  Signal] [D_DPLSMW_TriggerLe_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_TriggerLe_btf) \n
 *		[Debug  Signal] [D_DPLSMW_TriggerRi_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_TriggerRi_btf) \n
 *		[Debug  Signal] [D_DPLSMW_WeakReady_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_WeakReady_btf) \n
 *		[Debug  Signal] [S_DPLSMW_DangerousSide_nu](@ref DPLSMW_SenDbgType::S_DPLSMW_DangerousSide_nu) \n
 *		[Debug  Signal] [S_DPLSMW_ReadyToTrigger_bool](@ref DPLSMW_SenDbgType::S_DPLSMW_ReadyToTrigger_bool) \n
 *		[Output Signal] [S_DPLSMW_SysStateLDWLe_nu](@ref DPLSMW_SenOutType::S_DPLSMW_SysStateLDWLe_nu) \n
 *		[Output Signal] [S_DPLSMW_SysStateLDWRi_nu](@ref DPLSMW_SenOutType::S_DPLSMW_SysStateLDWRi_nu) \n
 *		[Output Signal] [S_DPLSMW_SysStateLDW_nu](@ref DPLSMW_SenOutType::S_DPLSMW_SysStateLDW_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref DPLSMW_SenProcess_Globals) of the function @ref DPLSMW_SenProcess.
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
extern void DPLSMW_SenReset(void);

/*!
 *	DPLSMW module sensor process function.
 *	
 *	@pre
 *		- The DPLSMW sensor initialization function(s) must be called once.
 *		- The DPLSMW sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPLSMW_SenProcess_Globals
 *		[D_DPLSMW_Cancel_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_Cancel_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDW cancel conditions. \n\n
 *		[D_DPLSMW_DlcLeThreshold_met](@ref DPLSMW_SenDbgType::D_DPLSMW_DlcLeThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
 *		[D_DPLSMW_DlcRiThreshold_met](@ref DPLSMW_SenDbgType::D_DPLSMW_DlcRiThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
 *		[D_DPLSMW_StrongReady_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_StrongReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDW strong ready conditions. \n\n
 *		[D_DPLSMW_SysStateLDW_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_SysStateLDW_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDW state machine inputs. \n\n
 *		[D_DPLSMW_TlcLeThreshold_sec](@ref DPLSMW_SenDbgType::D_DPLSMW_TlcLeThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
 *		[D_DPLSMW_TlcRiThreshold_sec](@ref DPLSMW_SenDbgType::D_DPLSMW_TlcRiThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
 *		[D_DPLSMW_TriggerLe_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_TriggerLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger on the left side. \n\n
 *		[D_DPLSMW_TriggerRi_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_TriggerRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger on the right side. \n\n
 *		[D_DPLSMW_WeakReady_btf](@ref DPLSMW_SenDbgType::D_DPLSMW_WeakReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the LDW weak ready conditions. \n\n
 *		[S_DPLSMW_DangerousSide_nu](@ref DPLSMW_SenDbgType::S_DPLSMW_DangerousSide_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the warning, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		[S_DPLSMW_ReadyToTrigger_bool](@ref DPLSMW_SenDbgType::S_DPLSMW_ReadyToTrigger_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		The signal is true when the LDW strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
 *		[S_DPLSMW_SysStateLDWLe_nu](@ref DPLSMW_SenOutType::S_DPLSMW_SysStateLDWLe_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		LDW System State. Left side. \n\n
 *		[S_DPLSMW_SysStateLDWRi_nu](@ref DPLSMW_SenOutType::S_DPLSMW_SysStateLDWRi_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		LDW System State. Right side. \n\n
 *		[S_DPLSMW_SysStateLDW_nu](@ref DPLSMW_SenOutType::S_DPLSMW_SysStateLDW_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the LDW function. \n\n
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
 *		@ref S_CUSTOM_LDWDlcLimitLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing limit zone for the LDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_LDWDlcLimitRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing limit zone for the LDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_LDWDlcTrgLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing threshold for the LDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_LDWDlcTrgRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing threshold for the LDW. Customer Specific. \n\n
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
 *		@ref S_DPLSIA_DlcLeLDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the LDW. \n\n
 *		@ref S_DPLSIA_DlcRiLDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the LDW. \n\n
 *		@ref S_DPLSIA_LaneWidthLDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across LDW. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref S_DPLSIA_LnBndLeValidLDW_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDW function. \n\n
 *		@ref S_DPLSIA_LnBndRiValidLDW_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDW function. \n\n
 *		@ref S_DPLSIA_SideCondLDWLe_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the LDW. \n\n
 *		@ref S_DPLSIA_SideCondLDWRi_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the LDW. \n\n
 *		@ref S_DPLSIA_SpecificLDW_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the LDW. \n\n
 *		@ref S_DPLSIA_TlcLeLDW_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the LDW. \n\n
 *		@ref S_DPLSIA_TlcRiLDW_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the LDW. \n\n
 *		@ref S_DPLSIA_VelLatLeLDW_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the LDW. \n\n
 *		@ref S_DPLSIA_VelLatRiLDW_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the LDW. \n\n
 *		@ref S_LCFRCV_ErrorStateLDW_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Error State of the LDW function. \n\n
 *		@ref S_LCFRCV_LDWMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_LDWSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
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
 *		@ref P_DPLSIA_SafetyIfaceLDWOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the data from the safety interface will be used to trigger the LDW. Else, the control interface data will be used. \n\n
 *		@ref P_DPLSMW_AbortDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to an abort condition. \n\n
 *		@ref P_DPLSMW_AbortDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to abort a warning. \n\n
 *		@ref P_DPLSMW_AbortFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to abort a warning. \n\n
 *		@ref P_DPLSMW_AbortFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf  are used to abort a warning. \n\n
 *		@ref P_DPLSMW_AbortFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to abort a warning. \n\n
 *		@ref P_DPLSMW_AbortFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to abort a warning. \n\n
 *		@ref P_DPLSMW_AbortSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used to abort a warning. \n\n
 *		@ref P_DPLSMW_AbortVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to abort a warning. \n\n
 *		@ref P_DPLSMW_BlockingTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Duration of the blocking time between two LDW warnings. \n\n
 *		@ref P_DPLSMW_CancelDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to a cancel condition. \n\n
 *		@ref P_DPLSMW_CancelDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_CancelFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_CancelFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_CancelFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_CancelFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_CancelSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_CancelVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to cancel a warning. \n\n
 *		@ref P_DPLSMW_DebugDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
 *		@ref P_DPLSMW_DebugSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used for the SysState debug signal. \n\n
 *		@ref P_DPLSMW_DlcLimitMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
 *		@ref P_DPLSMW_DlcLimitMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
 *		@ref P_DPLSMW_ErrorStateLDWEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPLSMW_ErrorStateLDW_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the Error State Signal. \n\n
 *		@ref P_DPLSMW_FctCustomBSMLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM left warning. \n\n
 *		@ref P_DPLSMW_FctCustomBSMRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a BSM right warning. \n\n
 *		@ref P_DPLSMW_FctCustomCancelLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left warning. \n\n
 *		@ref P_DPLSMW_FctCustomCancelRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right warning. \n\n
 *		@ref P_DPLSMW_FctCustomTrgLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left warning. \n\n
 *		@ref P_DPLSMW_FctCustomTrgRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right warning. \n\n
 *		@ref P_DPLSMW_FinishCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions are used in order to finish a warning. \n\n
 *		@ref P_DPLSMW_FinishDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to a finish condition. \n\n
 *		@ref P_DPLSMW_FinishMinDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Finish Condition. The function shall have been at least this time controlling to be able to finish. \n\n
 *		@ref P_DPLSMW_HazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DLC is bigger than this tolerance across the lane marking the warning is cancelled. \n\n
 *		@ref P_DPLSMW_HazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPLSMW_HazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPLSMW_LDWSwitchEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPLSMW_LDWSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the HMI Switch. \n\n
 *		@ref P_DPLSMW_NoHazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DLC is apart from the target a distance bigger than this tolerance in the opposite direction of the dangerous situation the warning is cancelled. \n\n
 *		@ref P_DPLSMW_NoHazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the opposite directon of the dangerous situation. \n\n
 *		@ref P_DPLSMW_NoHazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the opposite directon of the dangerous situation. \n\n
 *		@ref P_DPLSMW_OnTargetFinishTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time for which all the finish conditions have to be fulfilled in order to consider a warning finished. \n\n
 *		@ref P_DPLSMW_SafeSituationDelay_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the safe situation condition. \n\n
 *		@ref P_DPLSMW_SafeSituationOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		To avoid two warnings with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
 *		@ref P_DPLSMW_SafeSituationState_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		This bitfield determines which conditions are used to reset the flipflop used to avoid two warnings with the same dangerous situation. \n\n
 *		@ref P_DPLSMW_SideCondCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDWLe_btf/S_DPLSIA_SideCondLDWRi_btf are used in order to cancel a warning. \n\n
 *		@ref P_DPLSMW_SideCondDebug_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDWLe_btf/S_DPLSIA_SideCondLDWRi_btf are used for the SysState debug signal. \n\n
 *		@ref P_DPLSMW_SideCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPLSIA_SideCondLDWLe_btf/S_DPLSIA_SideCondLDWRi_btf are used in order to trigger a warning. \n\n
 *		@ref P_DPLSMW_StrgRdyDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to an strong ready condition. \n\n
 *		@ref P_DPLSMW_StrgRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMW_StrgRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_StrgRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMW_StrgRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMW_StrgRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMW_StrgRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMW_StrgRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPLSMW_SuppressDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_SuppressFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_SuppressFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_SuppressFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_SuppressFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_SuppressSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_SuppressVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to suppress a warning. \n\n
 *		@ref P_DPLSMW_TgtTrajPosY0_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Expected end position of the vehicle if the driver reacts to the LDW. \n\n
 *		@ref P_DPLSMW_TlcDistanceMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
 *		@ref P_DPLSMW_TlcValidMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
 *		@ref P_DPLSMW_TriggerAlwaysOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this switch is on, the trigger conditions (DLC or TLC) have to be fulfilled the whole time the trigger is being held, in order to have a trigger. Else, only the trigger holding time is relevant. \n\n
 *		@ref P_DPLSMW_TriggerCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions are used in order to trigger a warning. \n\n
 *		@ref P_DPLSMW_TriggerHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Holding time when the trigger threshold was exceeded. \n\n
 *		@ref P_DPLSMW_WeakRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMW_WeakRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMW_WeakRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMW_WeakRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMW_WeakRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMW_WeakRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPLSIA_SpecificLDW_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPLSMW_WeakRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_LDW_DlcLimitCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Limit Switch for the LDW. \n\n
 *		@ref P_LDW_DlcTriggerCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Threshold Switch for the LDW. \n\n
 *		@ref P_LDW_Existing_nu \n
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
 *		@ref Y_DPLSMW_CrvICDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		InnerCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMW_CrvICTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		InnerCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMW_CrvOCDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		OuterCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMW_CrvOCTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		OuterCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPLSMW_LWContrMaxDurScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the LDW. \n\n
 *		@ref Y_DPLSMW_LWHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPLSMW_LWNoHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPLSMW_LWTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Dlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPLSMW_LWTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Tlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPLSMW_VXContrMaxDur_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the LDW. \n\n
 *		@ref Y_DPLSMW_VXMD1TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPLSMW_VXMD1TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to lane crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPLSMW_VXMD2TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPLSMW_VXMD2TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to lane crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPLSMW_VXMD3TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 3. SpeedX dependant. \n\n
 *		@ref Y_DPLSMW_VXMD3TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to lane crossing. Mode 3. SpeedX dependant. \n\n
 *		@ref Y_DPLSMW_VYTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Dlc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPLSMW_VYTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Tlc Scaling Factor - Lateral velocity Dependant \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPLSMW Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPLSMW_Testcase_Initialization) Initialization of the DPLSMW
 *		-# [Testcase_Coded_Function](@ref DPLSMW_Testcase_Coded_Function) LDW Coded
 *		-# [Testcase_Function_Switch](@ref DPLSMW_Testcase_Function_Switch) LDW Switch
 *		-# [Testcase_Weak_Ready](@ref DPLSMW_Testcase_Weak_Ready) Weak Ready Conditions
 *		-# [Testcase_Strong_Ready](@ref DPLSMW_Testcase_Strong_Ready) Strong Ready Conditions
 *		-# [Testcase_TriggerLeft](@ref DPLSMW_Testcase_TriggerLeft) Trigger Left Conditions
 *		-# [Testcase_TriggerRight](@ref DPLSMW_Testcase_TriggerRight) Trigger Right Conditions
 *		-# [Testcase_TriggerBSM](@ref DPLSMW_Testcase_TriggerBSM) Trigger BSM Conditions
 *		-# [Testcase_Suppress](@ref DPLSMW_Testcase_Suppress) Suppress Conditions
 *		-# [Testcase_Finish](@ref DPLSMW_Testcase_Finish) Finish Conditions
 *		-# [Testcase_Cancel](@ref DPLSMW_Testcase_Cancel) Cancel Conditions
 *		-# [Testcase_Abort](@ref DPLSMW_Testcase_Abort) Abort Conditions
 *		-# [Testcase_Degradation](@ref DPLSMW_Testcase_Degradation) Degradation Conditions
 *		-# [Testcase_Function_Error](@ref DPLSMW_Testcase_Function_Error) LDW Error
 *		-# [Testcase_State_Machine](@ref DPLSMW_Testcase_State_Machine) LDW System State
 *		-# [Testcase_Internal_System_State_Left](@ref DPLSMW_Testcase_Internal_System_State_Left) Internal System State - Left Side
 *		-# [Testcase_Internal_System_State_Right](@ref DPLSMW_Testcase_Internal_System_State_Right) Internal System State - Right Side
 *		
 *	@traceability
 *		[\@link: DPLSMW Module Requirements]()
 */
extern void DPLSMW_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPLSMW_H_
