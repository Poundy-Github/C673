/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMW
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSMW.h
//! @brief     (DPRSMW) Module Header.

#ifndef DPRSMW_H_
#define DPRSMW_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "DPRSMW_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DPRSMW module sensor initialization function. Function initializes DPRSMW sensor debug data pointer.
 *	
 *	@param
 *		[in] DPRSMW_SenDbgArg Pointer to DPRSMW sensor debug data.
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
extern void DPRSMW_SenInitDbgPtr(DPRSMW_SenDbgType *DPRSMW_SenDbgArg);

/*!
 *	DPRSMW module sensor initialization function. Function initializes DPRSMW sensor output data pointer.
 *	
 *	@param
 *		[in] DPRSMW_SenOutArg Pointer to DPRSMW sensor output data.
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
extern void DPRSMW_SenInitOutPtr(DPRSMW_SenOutType *DPRSMW_SenOutArg);

/*!
 *	DPRSMW module sensor reset function.
 *	
 *	@pre
 *		- The DPRSMW sensor initialization function(s) must be called once.
 *		- The DPRSMW sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DPRSMW_Cancel_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_Cancel_btf) \n
 *		[Debug  Signal] [D_DPRSMW_DlcLeThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DlcLeThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMW_DlcRiThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DlcRiThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMW_DrcLeThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DrcLeThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMW_DrcRiThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DrcRiThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMW_StrongReady_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_StrongReady_btf) \n
 *		[Debug  Signal] [D_DPRSMW_SysStateRDW_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_SysStateRDW_btf) \n
 *		[Debug  Signal] [D_DPRSMW_TlcLeThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TlcLeThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMW_TlcRiThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TlcRiThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMW_TrcLeThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TrcLeThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMW_TrcRiThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TrcRiThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMW_TriggerLnLe_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnLe_btf) \n
 *		[Debug  Signal] [D_DPRSMW_TriggerLnReLe_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnReLe_btf) \n
 *		[Debug  Signal] [D_DPRSMW_TriggerLnReRi_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnReRi_btf) \n
 *		[Debug  Signal] [D_DPRSMW_TriggerLnRi_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnRi_btf) \n
 *		[Debug  Signal] [D_DPRSMW_TriggerReLe_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerReLe_btf) \n
 *		[Debug  Signal] [D_DPRSMW_TriggerReRi_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerReRi_btf) \n
 *		[Debug  Signal] [D_DPRSMW_WeakReady_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_WeakReady_btf) \n
 *		[Debug  Signal] [S_DPRSMW_DangerousSide_nu](@ref DPRSMW_SenDbgType::S_DPRSMW_DangerousSide_nu) \n
 *		[Debug  Signal] [S_DPRSMW_ReadyToTrigger_bool](@ref DPRSMW_SenDbgType::S_DPRSMW_ReadyToTrigger_bool) \n
 *		[Debug  Signal] [S_DPRSMW_TriggerReason_nu](@ref DPRSMW_SenDbgType::S_DPRSMW_TriggerReason_nu) \n
 *		[Output Signal] [S_DPRSMW_SysStateRDWLe_nu](@ref DPRSMW_SenOutType::S_DPRSMW_SysStateRDWLe_nu) \n
 *		[Output Signal] [S_DPRSMW_SysStateRDWRi_nu](@ref DPRSMW_SenOutType::S_DPRSMW_SysStateRDWRi_nu) \n
 *		[Output Signal] [S_DPRSMW_SysStateRDW_nu](@ref DPRSMW_SenOutType::S_DPRSMW_SysStateRDW_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref DPRSMW_SenProcess_Globals) of the function @ref DPRSMW_SenProcess.
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
extern void DPRSMW_SenReset(void);

/*!
 *	DPRSMW module sensor process function.
 *	
 *	@pre
 *		- The DPRSMW sensor initialization function(s) must be called once.
 *		- The DPRSMW sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPRSMW_SenProcess_Globals
 *		[D_DPRSMW_Cancel_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_Cancel_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDW cancel conditions. \n\n
 *		[D_DPRSMW_DlcLeThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DlcLeThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
 *		[D_DPRSMW_DlcRiThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DlcRiThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
 *		[D_DPRSMW_DrcLeThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DrcLeThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Drc Threshold for the left road edge. \n\n
 *		[D_DPRSMW_DrcRiThreshold_met](@ref DPRSMW_SenDbgType::D_DPRSMW_DrcRiThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Drc Threshold for the right road edge. \n\n
 *		[D_DPRSMW_StrongReady_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_StrongReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDW strong ready conditions. \n\n
 *		[D_DPRSMW_SysStateRDW_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_SysStateRDW_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDW state machine inputs. \n\n
 *		[D_DPRSMW_TlcLeThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TlcLeThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
 *		[D_DPRSMW_TlcRiThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TlcRiThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
 *		[D_DPRSMW_TrcLeThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TrcLeThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Trc Threshold for the left road edge. \n\n
 *		[D_DPRSMW_TrcRiThreshold_sec](@ref DPRSMW_SenDbgType::D_DPRSMW_TrcRiThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Trc Threshold for the right road edge. \n\n
 *		[D_DPRSMW_TriggerLnLe_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane for the left side. \n\n
 *		[D_DPRSMW_TriggerLnReLe_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnReLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane and road for the left side. \n\n
 *		[D_DPRSMW_TriggerLnReRi_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnReRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane and road for the right side. \n\n
 *		[D_DPRSMW_TriggerLnRi_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerLnRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane for the right side. \n\n
 *		[D_DPRSMW_TriggerReLe_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerReLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger road for the left side. \n\n
 *		[D_DPRSMW_TriggerReRi_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_TriggerReRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger road for the right side. \n\n
 *		[D_DPRSMW_WeakReady_btf](@ref DPRSMW_SenDbgType::D_DPRSMW_WeakReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDW weak ready conditions. \n\n
 *		[S_DPRSMW_DangerousSide_nu](@ref DPRSMW_SenDbgType::S_DPRSMW_DangerousSide_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the warning, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		[S_DPRSMW_ReadyToTrigger_bool](@ref DPRSMW_SenDbgType::S_DPRSMW_ReadyToTrigger_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		The signal is true when the RDW strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
 *		[S_DPRSMW_TriggerReason_nu](@ref DPRSMW_SenDbgType::S_DPRSMW_TriggerReason_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Trigger Reason of the RDW function. \n\n
 *		[S_DPRSMW_SysStateRDWLe_nu](@ref DPRSMW_SenOutType::S_DPRSMW_SysStateRDWLe_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		System State for the left side of the RDW function. \n\n
 *		[S_DPRSMW_SysStateRDWRi_nu](@ref DPRSMW_SenOutType::S_DPRSMW_SysStateRDWRi_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		System State for the right side of the RDW function. \n\n
 *		[S_DPRSMW_SysStateRDW_nu](@ref DPRSMW_SenOutType::S_DPRSMW_SysStateRDW_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the RDW function. \n\n
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
 *		@ref S_ABPREP_LeReClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left road edge clothoid curvature \n\n
 *		@ref S_ABPREP_LeReHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left road edge clothoid yaw angle \n\n
 *		@ref S_ABPREP_LeReInvalidQu_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ABPREP_LeRePosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left road edge clothoid lateral distance (Y0 position) \n\n
 *		@ref S_ABPREP_RiReClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right road edge clothoid curvature \n\n
 *		@ref S_ABPREP_RiReHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right road edge clothoid yaw angle \n\n
 *		@ref S_ABPREP_RiReInvalidQu_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ABPREP_RiRePosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right road edge clothoid lateral distance (Pos Y0) \n\n
 *		@ref S_CUSTOM_PrjSpecQu_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield containing all the relevant information of the customer projects. \n\n
 *		@ref S_CUSTOM_RDWDlcLimitLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing limit zone for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDlcLimitRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing limit zone for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDlcTrgLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing threshold for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDlcTrgRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing threshold for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDrcLimitLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left road edge crossing limit zone for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDrcLimitRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right road edge crossing limit zone for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDrcTrgLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left road edge crossing threshold for the RDW. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDWDrcTrgRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right road edge crossing threshold for the RDW. Customer Specific. \n\n
 *		@ref S_DPRSIA_DlcLeRDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the RDW. \n\n
 *		@ref S_DPRSIA_DlcRiRDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the RDW. \n\n
 *		@ref S_DPRSIA_DrcLeRDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left road edge for the RDW. \n\n
 *		@ref S_DPRSIA_DrcRiRDW_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right road edge for the RDW. \n\n
 *		@ref S_DPRSIA_SideCondRDWLe_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the RDW. \n\n
 *		@ref S_DPRSIA_SideCondRDWRi_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the RDW. \n\n
 *		@ref S_DPRSIA_SpecificRDW_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the RDW. \n\n
 *		@ref S_DPRSIA_TlcLeRDW_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the RDW. \n\n
 *		@ref S_DPRSIA_TlcRiRDW_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the RDW. \n\n
 *		@ref S_DPRSIA_TrcLeRDW_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left road edge for the RDW. \n\n
 *		@ref S_DPRSIA_TrcRiRDW_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right road edge for the RDW. \n\n
 *		@ref S_DPRSIA_TriggerReasonLeRDW_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Left side Trigger Reason of the RDW function. \n\n
 *		@ref S_DPRSIA_TriggerReasonRiRDW_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Right side Trigger Reason of the RDW function. \n\n
 *		@ref S_DPRSIA_VelLatLnLeRDW_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the RDW. \n\n
 *		@ref S_DPRSIA_VelLatLnRiRDW_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the RDW. \n\n
 *		@ref S_DPRSIA_VelLatReLeRDW_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left road edge for the RDW. \n\n
 *		@ref S_DPRSIA_VelLatReRiRDW_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right road edge for the RDW. \n\n
 *		@ref S_LCFRCV_ErrorStateRDW_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Error State of the RDW \n\n
 *		@ref S_LCFRCV_RDWMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Sensitivity mode of the RDW. \n\n
 *		@ref S_LCFRCV_RDWSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the RDW. \n\n
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
 *		@ref P_DPRSMI_CurveDetectThreshold_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		If the curvature is above this threshold, a curve is considered, else, a straight line. \n\n
 *		@ref P_DPRSMW_AbortDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to an abort condition. \n\n
 *		@ref P_DPRSMW_AbortDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to abort a warning. \n\n
 *		@ref P_DPRSMW_AbortFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to abort a warning. \n\n
 *		@ref P_DPRSMW_AbortFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf  are used to abort a warning. \n\n
 *		@ref P_DPRSMW_AbortFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to abort a warning. \n\n
 *		@ref P_DPRSMW_AbortFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to abort a warning. \n\n
 *		@ref P_DPRSMW_AbortSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used to abort a warning. \n\n
 *		@ref P_DPRSMW_AbortVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to abort a warning. \n\n
 *		@ref P_DPRSMW_BlockingTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Duration of the blocking time between two RDW warnings. \n\n
 *		@ref P_DPRSMW_CancelDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to a cancel condition. \n\n
 *		@ref P_DPRSMW_CancelDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_CancelFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_CancelFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_CancelFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_CancelFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_CancelSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_CancelVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to cancel a warning. \n\n
 *		@ref P_DPRSMW_DebugDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
 *		@ref P_DPRSMW_DebugSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used for the SysState debug signal. \n\n
 *		@ref P_DPRSMW_DlcLimitMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
 *		@ref P_DPRSMW_DlcLimitMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
 *		@ref P_DPRSMW_DrcLimitMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed value of the DRC to trigger. If DRC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
 *		@ref P_DPRSMW_DrcLimitMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum allowed value of the DRC to trigger. If DRC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
 *		@ref P_DPRSMW_ErrorStateRDWEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPRSMW_ErrorStateRDW_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the Error State Signal. \n\n
 *		@ref P_DPRSMW_FctCustomCancelLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left warning. \n\n
 *		@ref P_DPRSMW_FctCustomCancelRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right warning. \n\n
 *		@ref P_DPRSMW_FctCustomTrgLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left warning. \n\n
 *		@ref P_DPRSMW_FctCustomTrgRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right warning. \n\n
 *		@ref P_DPRSMW_FinishCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions are used in order to finish a warning. \n\n
 *		@ref P_DPRSMW_FinishDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to a finish condition. \n\n
 *		@ref P_DPRSMW_FinishMinDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Finish Condition. The function shall have been at least this time controlling to be able to finish. \n\n
 *		@ref P_DPRSMW_HazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DRC is bigger than this tolerance across the road marking the warning is cancelled. \n\n
 *		@ref P_DPRSMW_HazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMW_HazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMW_LnMrkRdEdgeDistMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between a lane marking and a road edge to trigger. \n\n
 *		@ref P_DPRSMW_LnMrkRdEdgeDistMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimal allowed distance between a lane marking and a road edge to trigger. \n\n
 *		@ref P_DPRSMW_LnOverlapCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximum curvature of a boundary when a road edge and a lane marking overlap. \n\n
 *		@ref P_DPRSMW_LnOverlapEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Trigger enabler when a road edge and a lane marking overlap. \n\n
 *		@ref P_DPRSMW_LnOverlapInnerDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the road edge and the lane marking when the road edge is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
 *		@ref P_DPRSMW_LnOverlapOuterDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the road edge and the lane marking when the lane marking is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
 *		@ref P_DPRSMW_NoHazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DRC is apart from the target a distance bigger than this tolerance in the opposite direction of the dangerous situation the warning is cancelled. \n\n
 *		@ref P_DPRSMW_NoHazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMW_NoHazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMW_OnTargetFinishTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time for which all the finish conditions have to be fulfilled in order to consider a warning finished. \n\n
 *		@ref P_DPRSMW_RDWSwitchEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPRSMW_RDWSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the HMI Switch. \n\n
 *		@ref P_DPRSMW_SafeSitDelayLn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the lane marking safe situation condition. \n\n
 *		@ref P_DPRSMW_SafeSitDelayRe_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the road edge safe situation condition. \n\n
 *		@ref P_DPRSMW_SafeSitOffsetLn_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		To avoid two lateral interventions with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
 *		@ref P_DPRSMW_SafeSitOffsetRe_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		To avoid two lateral interventions with the same dangerous situation, the DRC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
 *		@ref P_DPRSMW_SafeSitStateLn_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		This bitfield determines which conditions are used to reset the flipflop used to avoid two warnings with the same dangerous situation. \n\n
 *		@ref P_DPRSMW_SafeSitStateRe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		This bitfield determines which conditions are used to reset the flipflop used to avoid two warnings with the same dangerous situation. \n\n
 *		@ref P_DPRSMW_SideCondCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used in order to cancel a warning. \n\n
 *		@ref P_DPRSMW_SideCondDebug_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used for the SysState debug signal \n\n
 *		@ref P_DPRSMW_SideCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used in order to trigger a warning. \n\n
 *		@ref P_DPRSMW_StrgRdyDegrDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Degradation time due to an strong ready condition. \n\n
 *		@ref P_DPRSMW_StrgRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPRSMW_StrgRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_StrgRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPRSMW_StrgRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPRSMW_StrgRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPRSMW_StrgRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPRSMW_StrgRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the strong ready conditions (relevant for trigger and cancel). \n\n
 *		@ref P_DPRSMW_SuppressDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_SuppressFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_SuppressFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_SuppressFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_SuppressFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_SuppressSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDW_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_SuppressVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used to suppress a warning. \n\n
 *		@ref P_DPRSMW_TgtTrajPosY0_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Expected end position of the vehicle if the driver reacts to the RDW. \n\n
 *		@ref P_DPRSMW_TlcDistanceMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
 *		@ref P_DPRSMW_TlcValidMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
 *		@ref P_DPRSMW_TrcDistanceMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TRC Criterium is fulfilled. \n\n
 *		@ref P_DPRSMW_TrcValidMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time that the trc criterium shall be fulfilled to be used to trigger. \n\n
 *		@ref P_DPRSMW_TrgIgnoreLnContg_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch to ignore a lane marking when it is there, to trigger like a road edge only. \n\n
 *		@ref P_DPRSMW_TriggerAlwaysOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this switch is on, the trigger conditions (DLC or TLC/DRC or TRC) have to be fulfilled the whole time the trigger is being held, in order to have a trigger. Else, only the trigger holding time is relevant. \n\n
 *		@ref P_DPRSMW_TriggerHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Holding time when the trigger threshold was exceeded. \n\n
 *		@ref P_DPRSMW_WeakRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPRSMW_WeakRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPRSMW_WeakRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_ActiveStCtrl_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPRSMW_WeakRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStError_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPRSMW_WeakRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_SysStNotAvailable_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPRSMW_WeakRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDP_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_DPRSMW_WeakRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_VehStInvalid_btf are used for the weak ready conditions (relevant for trigger). \n\n
 *		@ref P_RDW_DlcLimitCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Limit Switch for the RDW. \n\n
 *		@ref P_RDW_DlcTriggerCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Threshold Switch for the RDW. \n\n
 *		@ref P_RDW_DrcLimitCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DRC Limit Switch for the RDW. \n\n
 *		@ref P_RDW_DrcTriggerCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DRC Threshold Switch for the RDW. \n\n
 *		@ref P_RDW_Existing_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main parameter switch of the RDW. \n\n
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
 *		@ref Y_DPRSMW_CrvICDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		InnerCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvICDrcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		InnerCurve Drc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvICTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		InnerCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvICTrcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		InnerCurve Trc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvOCDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		OuterCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvOCDrcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		OuterCurve Drc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvOCTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		OuterCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_CrvOCTrcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		OuterCurve Trc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMW_LWContrMaxDurLnScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDW for the use cases in which a lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMW_LWContrMaxDurReScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDW for the use cases in which no lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMW_LWHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPRSMW_LWNoHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPRSMW_LWTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Dlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPRSMW_LWTrigDrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane Width Drc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPRSMW_LWTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Tlc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPRSMW_LWTrigTrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane Width Trc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPRSMW_VXContrMaxDurLn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDW for the use cases in which a lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMW_VXContrMaxDurRe_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDW for the use cases in which no lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMW_VXMD1TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPRSMW_VXMD1TrigDrc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD1 Drc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD1TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD1 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD1TrigTrc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to road edge crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPRSMW_VXMD2TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Trigger distance to lane crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPRSMW_VXMD2TrigDrc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD2 Drc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD2TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD2 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD2TrigTrc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to road edge crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPRSMW_VXMD3TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD3 Dlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD3TrigDrc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD3 Drc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD3TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD3 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VXMD3TrigTrc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD3 Trc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMW_VYTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral velocity Dlc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPRSMW_VYTrigDrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral velocity Drc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPRSMW_VYTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral velocity Tlc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPRSMW_VYTrigTrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lateral velocity Trc Scaling Factor - Lateral velocity Dependant \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPRSMW Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPRSMW_Testcase_Initialization) Initialization of the DPRSMW
 *		-# [Testcase_Coded_Function](@ref DPRSMW_Testcase_Coded_Function) RDW Coded
 *		-# [Testcase_Function_Switch](@ref DPRSMW_Testcase_Function_Switch) RDW Switch
 *		-# [Testcase_Weak_Ready](@ref DPRSMW_Testcase_Weak_Ready) Weak Ready Conditions
 *		-# [Testcase_Strong_Ready](@ref DPRSMW_Testcase_Strong_Ready) Strong Ready Conditions
 *		-# [Testcase_TriggerLeft_REO](@ref DPRSMW_Testcase_TriggerLeft_REO) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_RELMO](@ref DPRSMW_Testcase_TriggerLeft_RELMO) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_RELMC](@ref DPRSMW_Testcase_TriggerLeft_RELMC) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_RELMB](@ref DPRSMW_Testcase_TriggerLeft_RELMB) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_Ignore](@ref DPRSMW_Testcase_TriggerLeft_Ignore) Trigger Left Conditions
 *		-# [Testcase_TriggerRight_REO](@ref DPRSMW_Testcase_TriggerRight_REO) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_RELMO](@ref DPRSMW_Testcase_TriggerRight_RELMO) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_RELMC](@ref DPRSMW_Testcase_TriggerRight_RELMC) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_RELMB](@ref DPRSMW_Testcase_TriggerRight_RELMB) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_Ignore](@ref DPRSMW_Testcase_TriggerRight_Ignore) Trigger Right Conditions
 *		-# [Testcase_Suppress](@ref DPRSMW_Testcase_Suppress) Suppress Conditions
 *		-# [Testcase_Finish](@ref DPRSMW_Testcase_Finish) Finish Conditions
 *		-# [Testcase_Cancel](@ref DPRSMW_Testcase_Cancel) Cancel Conditions
 *		-# [Testcase_Abort](@ref DPRSMW_Testcase_Abort) Abort Conditions
 *		-# [Testcase_Degradation](@ref DPRSMW_Testcase_Degradation) Degradation Conditions
 *		-# [Testcase_Function_Error](@ref DPRSMW_Testcase_Function_Error) RDW Error
 *		-# [Testcase_State_Machine](@ref DPRSMW_Testcase_State_Machine) RDW System State
 *		-# [Testcase_Internal_System_State_Left](@ref DPRSMW_Testcase_Internal_System_State_Left) Internal System State - Left Side
 *		-# [Testcase_Internal_System_State_Right](@ref DPRSMW_Testcase_Internal_System_State_Right) Internal System State - Right Side
 *		
 *	@traceability
 *		[\@link: DPRSMW Module Requirements]()
 */
extern void DPRSMW_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPRSMW_H_
