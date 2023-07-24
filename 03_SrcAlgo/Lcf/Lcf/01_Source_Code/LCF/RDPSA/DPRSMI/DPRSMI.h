/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSMI
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSMI.h
//! @brief     (DPRSMI) Module Header.

#ifndef DPRSMI_H_
#define DPRSMI_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "DPRSMI_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	DPRSMI module sensor initialization function. Function initializes DPRSMI sensor debug data pointer.
 *	
 *	@param
 *		[in] DPRSMI_SenDbgArg Pointer to DPRSMI sensor debug data.
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
extern void DPRSMI_SenInitDbgPtr(DPRSMI_SenDbgType *DPRSMI_SenDbgArg);

/*!
 *	DPRSMI module sensor initialization function. Function initializes DPRSMI sensor output data pointer.
 *	
 *	@param
 *		[in] DPRSMI_SenOutArg Pointer to DPRSMI sensor output data.
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
extern void DPRSMI_SenInitOutPtr(DPRSMI_SenOutType *DPRSMI_SenOutArg);

/*!
 *	DPRSMI module sensor reset function.
 *	
 *	@pre
 *		- The DPRSMI sensor initialization function(s) must be called once.
 *		- The DPRSMI sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DPRSMI_Cancel_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_Cancel_btf) \n
 *		[Debug  Signal] [D_DPRSMI_DlcLeThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DlcLeThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMI_DlcRiThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DlcRiThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMI_DrcLeThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DrcLeThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMI_DrcRiThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DrcRiThreshold_met) \n
 *		[Debug  Signal] [D_DPRSMI_StrongReady_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_StrongReady_btf) \n
 *		[Debug  Signal] [D_DPRSMI_SysStateRDP_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_SysStateRDP_btf) \n
 *		[Debug  Signal] [D_DPRSMI_TlcLeThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TlcLeThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMI_TlcRiThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TlcRiThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMI_TrcLeThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TrcLeThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMI_TrcRiThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TrcRiThreshold_sec) \n
 *		[Debug  Signal] [D_DPRSMI_TriggerLnLe_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnLe_btf) \n
 *		[Debug  Signal] [D_DPRSMI_TriggerLnReLe_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnReLe_btf) \n
 *		[Debug  Signal] [D_DPRSMI_TriggerLnReRi_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnReRi_btf) \n
 *		[Debug  Signal] [D_DPRSMI_TriggerLnRi_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnRi_btf) \n
 *		[Debug  Signal] [D_DPRSMI_TriggerReLe_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerReLe_btf) \n
 *		[Debug  Signal] [D_DPRSMI_TriggerReRi_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerReRi_btf) \n
 *		[Debug  Signal] [D_DPRSMI_WeakReady_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_WeakReady_btf) \n
 *		[Debug  Signal] [S_DPRSMI_DangerousSide_nu](@ref DPRSMI_SenDbgType::S_DPRSMI_DangerousSide_nu) \n
 *		[Debug  Signal] [S_DPRSMI_FunctionAborted_bool](@ref DPRSMI_SenDbgType::S_DPRSMI_FunctionAborted_bool) \n
 *		[Debug  Signal] [S_DPRSMI_ReadyToTrigger_bool](@ref DPRSMI_SenDbgType::S_DPRSMI_ReadyToTrigger_bool) \n
 *		[Debug  Signal] [S_DPRSMI_TriggerReason_nu](@ref DPRSMI_SenDbgType::S_DPRSMI_TriggerReason_nu) \n
 *		[Output Signal] [S_DPRSMI_SysStateRDPLe_nu](@ref DPRSMI_SenOutType::S_DPRSMI_SysStateRDPLe_nu) \n
 *		[Output Signal] [S_DPRSMI_SysStateRDPRi_nu](@ref DPRSMI_SenOutType::S_DPRSMI_SysStateRDPRi_nu) \n
 *		[Output Signal] [S_DPRSMI_SysStateRDP_nu](@ref DPRSMI_SenOutType::S_DPRSMI_SysStateRDP_nu) \n\n
 *		For signal details, see sub-section [Globals](@ref DPRSMI_SenProcess_Globals) of the function @ref DPRSMI_SenProcess.
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
extern void DPRSMI_SenReset(void);

/*!
 *	DPRSMI module sensor process function.
 *	
 *	@pre
 *		- The DPRSMI sensor initialization function(s) must be called once.
 *		- The DPRSMI sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPRSMI_SenProcess_Globals
 *		[D_DPRSMI_Cancel_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_Cancel_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDP cancel conditions. \n\n
 *		[D_DPRSMI_DlcLeThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DlcLeThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the left lane marking. \n\n
 *		[D_DPRSMI_DlcRiThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DlcRiThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Dlc Threshold for the right lane marking. \n\n
 *		[D_DPRSMI_DrcLeThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DrcLeThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Drc Threshold for the left road edge. \n\n
 *		[D_DPRSMI_DrcRiThreshold_met](@ref DPRSMI_SenDbgType::D_DPRSMI_DrcRiThreshold_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Debug Signal. Current Drc Threshold for the right road edge. \n\n
 *		[D_DPRSMI_StrongReady_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_StrongReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDP strong ready conditions. \n\n
 *		[D_DPRSMI_SysStateRDP_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_SysStateRDP_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDP state machine inputs. \n\n
 *		[D_DPRSMI_TlcLeThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TlcLeThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the left lane marking. \n\n
 *		[D_DPRSMI_TlcRiThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TlcRiThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Tlc Threshold for the right lane marking. \n\n
 *		[D_DPRSMI_TrcLeThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TrcLeThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Trc Threshold for the left road edge. \n\n
 *		[D_DPRSMI_TrcRiThreshold_sec](@ref DPRSMI_SenDbgType::D_DPRSMI_TrcRiThreshold_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Debug Signal. Current Trc Threshold for the right road edge. \n\n
 *		[D_DPRSMI_TriggerLnLe_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane on the left side. \n\n
 *		[D_DPRSMI_TriggerLnReLe_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnReLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane and road on the left side. \n\n
 *		[D_DPRSMI_TriggerLnReRi_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnReRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane and road on the right side. \n\n
 *		[D_DPRSMI_TriggerLnRi_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerLnRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger lane on the right side. \n\n
 *		[D_DPRSMI_TriggerReLe_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerReLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger road on the left side. \n\n
 *		[D_DPRSMI_TriggerReRi_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_TriggerReRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield for Trigger road on the right side. \n\n
 *		[D_DPRSMI_WeakReady_btf](@ref DPRSMI_SenDbgType::D_DPRSMI_WeakReady_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the RDP weak ready conditions. \n\n
 *		[S_DPRSMI_DangerousSide_nu](@ref DPRSMI_SenDbgType::S_DPRSMI_DangerousSide_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		[S_DPRSMI_FunctionAborted_bool](@ref DPRSMI_SenDbgType::S_DPRSMI_FunctionAborted_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		RDP aborted a lateral intervention. \n\n
 *		[S_DPRSMI_ReadyToTrigger_bool](@ref DPRSMI_SenDbgType::S_DPRSMI_ReadyToTrigger_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		The signal is true when the RDP strong ready and weak ready conditions (trigger not included) are fulfilled. \n\n
 *		[S_DPRSMI_TriggerReason_nu](@ref DPRSMI_SenDbgType::S_DPRSMI_TriggerReason_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Trigger Reason of the RDP function. \n\n
 *		[S_DPRSMI_SysStateRDPLe_nu](@ref DPRSMI_SenOutType::S_DPRSMI_SysStateRDPLe_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		System State for the left side of the RDP function. \n\n
 *		[S_DPRSMI_SysStateRDPRi_nu](@ref DPRSMI_SenOutType::S_DPRSMI_SysStateRDPRi_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateDirectionType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		System State for the right side of the RDP function. \n\n
 *		[S_DPRSMI_SysStateRDP_nu](@ref DPRSMI_SenOutType::S_DPRSMI_SysStateRDP_nu) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_SysStateType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 6 \n
 *		\@description: \n
 *		System State of the RDP function. \n\n
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
 *		@ref S_CUSTOM_RDPDlcLimitLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing limit zone for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDlcLimitRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing limit zone for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDlcTrgLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left lane marking crossing threshold for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDlcTrgRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right lane marking crossing threshold for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDrcLimitLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left road edge crossing limit zone for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDrcLimitRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right road edge crossing limit zone for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDrcTrgLe_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the left road edge crossing threshold for the RDP. Customer Specific. \n\n
 *		@ref S_CUSTOM_RDPDrcTrgRi_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to the right road edge crossing threshold for the RDP. Customer Specific. \n\n
 *		@ref S_DPRSIA_DlcLeRDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_DlcRiRDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_DrcLeRDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left road edge for the RDP. \n\n
 *		@ref S_DPRSIA_DrcRiRDP_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right road edge for the RDP. \n\n
 *		@ref S_DPRSIA_SideCondRDPLe_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the RDP. \n\n
 *		@ref S_DPRSIA_SideCondRDPRi_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the RDP. \n\n
 *		@ref S_DPRSIA_SpecificRDP_btf \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the RDP. \n\n
 *		@ref S_DPRSIA_TlcLeRDP_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_TlcRiRDP_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_TrcLeRDP_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left road edge for the RDP. \n\n
 *		@ref S_DPRSIA_TrcRiRDP_sec \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right road edge for the RDP. \n\n
 *		@ref S_DPRSIA_TriggerReasonLeRDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Left side Trigger Reason of the RDP function. \n\n
 *		@ref S_DPRSIA_TriggerReasonRiRDP_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Right side Trigger Reason of the RDP function. \n\n
 *		@ref S_DPRSIA_VelLatLnLeRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_VelLatLnRiRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the RDP. \n\n
 *		@ref S_DPRSIA_VelLatReLeRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left road edge for the RDP. \n\n
 *		@ref S_DPRSIA_VelLatReRiRDP_mps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right road edge for the RDP. \n\n
 *		@ref S_DPRTTG_LeTgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_DPRTTG_RiTgtTrajPosY0_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref S_LCFRCV_ErrorStateRDP_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Error State of the RDP function. \n\n
 *		@ref S_LCFRCV_RDPMode_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Sensitivity mode of the RDP. \n\n
 *		@ref S_LCFRCV_RDPSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the RDP \n\n
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
 *		@ref P_DPRSMI_AbortDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_AbortFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_AbortFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_AbortFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_AbortFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_AbortSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_AbortVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_BlockingTimeDuration_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CancelVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_CurveDetectThreshold_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		If the curvature is above this threshold, a curve is considered, else, a straight line. \n\n
 *		@ref P_DPRSMI_DebugDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_VDPDRV_DrvStInvalid_btf are used for the SysState Debug Signal. \n\n
 *		@ref P_DPRSMI_DebugSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_DPRSIA_SpecificRDP_btf are used for the SysState debug signal. \n\n
 *		@ref P_DPRSMI_DegrTimeOut_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time out parameter for the degradation watch dog timer. \n\n
 *		@ref P_DPRSMI_DlcLimitMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed value of the DLC to trigger. If DLC is bigger than this value, even if the DLC is smaller than the threshold, the function shall not trigger. \n\n
 *		@ref P_DPRSMI_DlcLimitMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum allowed value of the DLC to trigger. If DLC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
 *		@ref P_DPRSMI_DrcLimitMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximum allowed value of the DRC to trigger. If DRC is bigger than this value, even if the DRC is smaller than the threshold, the function shall not trigger. \n\n
 *		@ref P_DPRSMI_DrcLimitMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum allowed value of the DRC to trigger. If DRC is smaller than this value and the function did not trigger, it shall not trigger anymore. \n\n
 *		@ref P_DPRSMI_ErrorStateRDPEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the Error State signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPRSMI_ErrorStateRDP_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the Error State Signal. \n\n
 *		@ref P_DPRSMI_FctCustomCancelLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a left lateral intervention. \n\n
 *		@ref P_DPRSMI_FctCustomCancelRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to cancel a right lateral intervention. \n\n
 *		@ref P_DPRSMI_FctCustomTrgLe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a left lateral intervention. \n\n
 *		@ref P_DPRSMI_FctCustomTrgRi_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of S_CUSTOM_PrjSpecQu_btf are used to trigger a right lateral intervention. \n\n
 *		@ref P_DPRSMI_FinishCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_HazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_HazardFinishDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMI_HazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMI_HazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMI_LatDMCClearEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Switch for the LatDMC clearance condition. \n\n
 *		@ref P_DPRSMI_LnMrkRdEdgeDistMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between a lane marking and a road edge to trigger. \n\n
 *		@ref P_DPRSMI_LnMrkRdEdgeDistMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimal allowed distance between a lane marking and a road edge to trigger. \n\n
 *		@ref P_DPRSMI_LnOverlapCrv_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximum curvature of a boundary when a road edge and a lane marking overlap. \n\n
 *		@ref P_DPRSMI_LnOverlapEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Trigger enabler when a road edge and a lane marking overlap. \n\n
 *		@ref P_DPRSMI_LnOverlapInnerDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the road edge and the lane marking when the road edge is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
 *		@ref P_DPRSMI_LnOverlapOuterDist_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Maximal allowed distance between the road edge and the lane marking when the lane marking is detected closer to the vehicle. This would constitute a lane marking road edge overlap. \n\n
 *		@ref P_DPRSMI_NoHazardCancelDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		When DLC/DRC is apart from the lane marking a distance bigger than this tolerance in the opposite direction of the dangerous situation the intervention is cancelled. \n\n
 *		@ref P_DPRSMI_NoHazardCancelTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_NoHazardFinishDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the apart from the lane marking within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. \n\n
 *		@ref P_DPRSMI_NoHazardFinishHeadAng_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Finish condition. The heading has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMI_NoHazardFinishVelLat_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Finish condition. The lateral velocity has to be smaller than this threshold to consider an intervention successful. This is the tolerance in the directon of the dangerous situation. \n\n
 *		@ref P_DPRSMI_OnTargetFinishTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_QuTrajCtrCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to cancel an RDP intevention. \n\n
 *		@ref P_DPRSMI_QuTrajCtrClearance_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TCTCLM_QuServTrajCtr_nu are used to give the clearance to an RDP intevention. \n\n
 *		@ref P_DPRSMI_QuTrajPlanCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to cancel an RDP intevention. \n\n
 *		@ref P_DPRSMI_QuTrajPlanClearance_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask used to determine which bits of S_TPLFBT_QuStatusTrajPlan_nu are used to give the clearance to an an RDP intevention. \n\n
 *		@ref P_DPRSMI_RDPSwitchEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that switches between the HMI input signal or a parameter that simulates its behaviour. \n\n
 *		@ref P_DPRSMI_RDPSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Parameter that simulates the behaviour of the HMI Switch. \n\n
 *		@ref P_DPRSMI_RequestTimeOut_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal allowed time for the RDP to be in state REQUEST \n\n
 *		@ref P_DPRSMI_SafeSitDelayLn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the lane marking safe situation condition. \n\n
 *		@ref P_DPRSMI_SafeSitDelayRe_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the road edge safe situation condition. \n\n
 *		@ref P_DPRSMI_SafeSitOffsetLn_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		To avoid two lateral interventions with the same dangerous situation, the DLC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
 *		@ref P_DPRSMI_SafeSitOffsetRe_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		To avoid two lateral interventions with the same dangerous situation, the DRC of the vehicle has to be in a safe situation bigger than the trigger line plus this offset. \n\n
 *		@ref P_DPRSMI_SafeSitStateLn_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
 *		@ref P_DPRSMI_SafeSitStateRe_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		This bitfield determines which conditions are used to reset the flipflop used to avoid two lateral interventions with the same dangerous situation. \n\n
 *		@ref P_DPRSMI_SideCondCancel_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SideCondDebug_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that controls which conditions of the  S_DPRSIA_SideCondRDPLe_btf/S_DPRSIA_SideCondRDPRi_btf are used for the SysState debug signal. \n\n
 *		@ref P_DPRSMI_SideCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_StrgRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressSpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_SuppressVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_TlcDistanceMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TLC Criterium is fulfilled. \n\n
 *		@ref P_DPRSMI_TlcValidMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time that the tlc criterium shall be fulfilled to be used to trigger. \n\n
 *		@ref P_DPRSMI_TrcDistanceMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Minimum distance from the side of the vehicle to the lane marking in which the function can trigger if the TRC Criterium is fulfilled. \n\n
 *		@ref P_DPRSMI_TrcValidMinTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Minimum time that the trc criterium shall be fulfilled to be used to trigger. \n\n
 *		@ref P_DPRSMI_TrgIgnoreLnContg_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_TriggerHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdyDrvSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdyFctCustom_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdyFctStCtr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdyFctStErr_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdyFctStNotAv_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdySpecific_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPRSMI_WeakRdyVehSt_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_RDP_DlcLimitCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Limit Switch for the RDP. \n\n
 *		@ref P_RDP_DlcTriggerCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DLC Threshold Switch for the RDP. \n\n
 *		@ref P_RDP_DrcLimitCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DRC Limit Switch for the RDP. \n\n
 *		@ref P_RDP_DrcTriggerCustom_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Customer Specific DRC Threshold Switch for the RDP. \n\n
 *		@ref P_RDP_Existing_nu \n
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
 *		@ref Y_DPRSMI_CrvICDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		InnerCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvICDrcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		InnerCurve Drc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvICTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		InnerCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvICTrcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		InnerCurve Trc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvOCDlcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		OuterCurve Dlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvOCDrcOffset_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		OuterCurve Drc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvOCTlcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		OuterCurve Tlc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_CrvOCTrcOffset_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		OuterCurve Trc Offset - Curvature Dependant \n\n
 *		@ref Y_DPRSMI_LWContrMaxDurLnScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDP for the use cases in which a lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMI_LWContrMaxDurReScal_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_0_10_1em6_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximal lateral intervention duration scaling factor (Lane Width Dependant) allowed for the RDP for the use cases in which no lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMI_LWHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPRSMI_LWNoHazardFinishTol_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Finish condition. The end position of the vehicle must be the target within a tolerance. This is the tolerance in the opposite directon of the dangerous situation. Look Up Table Lane width dependant. \n\n
 *		@ref Y_DPRSMI_LWTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPRSMI_LWTrigDrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lane Width Drc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPRSMI_LWTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPRSMI_LWTrigTrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lane Width Trc Scaling Factor - Lane Width Dependant \n\n
 *		@ref Y_DPRSMI_VXContrMaxDurLn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDP for the use cases in which a lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMI_VXContrMaxDurRe_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Maximal lateral intervention duration (Ego-velocity Dependant) allowed for the RDP for the use cases in which no lane marking is present next to the road edge. \n\n
 *		@ref Y_DPRSMI_VXMD1TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPRSMI_VXMD1TrigDrc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD1 Drc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD1TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD1 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD1TrigTrc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to road edge crossing. Mode 1. SpeedX dependant. \n\n
 *		@ref Y_DPRSMI_VXMD2TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPRSMI_VXMD2TrigDrc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD2 Drc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD2TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD2 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD2TrigTrc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Trigger time to road edge crossing. Mode 2. SpeedX dependant. \n\n
 *		@ref Y_DPRSMI_VXMD3TrigDlc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD3 Dlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD3TrigDrc_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		MD3 Drc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD3TrigTlc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD3 Tlc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VXMD3TrigTrc_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		MD3 Trc Trigger Threshold - Ego-velocity Dependant \n\n
 *		@ref Y_DPRSMI_VYTrigDlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lateral velocity Dlc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPRSMI_VYTrigDrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lateral velocity Drc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPRSMI_VYTrigTlcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lateral velocity Tlc Scaling Factor - Lateral velocity Dependant \n\n
 *		@ref Y_DPRSMI_VYTrigTrcScalFact_nu \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_NoUnit_m100_100_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: - \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Lateral velocity Trc Scaling Factor - Lateral velocity Dependant \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPRSMI Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPRSMI_Testcase_Initialization) Initialization of the DPRSMI
 *		-# [Testcase_Coded_Function](@ref DPRSMI_Testcase_Coded_Function) RDP Coded
 *		-# [Testcase_Function_Switch](@ref DPRSMI_Testcase_Function_Switch) RDP Switch
 *		-# [Testcase_Weak_Ready](@ref DPRSMI_Testcase_Weak_Ready) Weak Ready Conditions
 *		-# [Testcase_Strong_Ready](@ref DPRSMI_Testcase_Strong_Ready) Strong Ready Conditions
 *		-# [Testcase_TriggerLeft_REO](@ref DPRSMI_Testcase_TriggerLeft_REO) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_RELMO](@ref DPRSMI_Testcase_TriggerLeft_RELMO) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_RELMC](@ref DPRSMI_Testcase_TriggerLeft_RELMC) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_RELMB](@ref DPRSMI_Testcase_TriggerLeft_RELMB) Trigger Left Conditions
 *		-# [Testcase_TriggerLeft_Ignore](@ref DPRSMI_Testcase_TriggerLeft_Ignore) Trigger Left Conditions
 *		-# [Testcase_TriggerRight_REO](@ref DPRSMI_Testcase_TriggerRight_REO) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_RELMO](@ref DPRSMI_Testcase_TriggerRight_RELMO) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_RELMC](@ref DPRSMI_Testcase_TriggerRight_RELMC) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_RELMB](@ref DPRSMI_Testcase_TriggerRight_RELMB) Trigger Right Conditions
 *		-# [Testcase_TriggerRight_Ignore](@ref DPRSMI_Testcase_TriggerRight_Ignore) Trigger Right Conditions
 *		-# [Testcase_Suppress](@ref DPRSMI_Testcase_Suppress) Suppress Conditions
 *		-# [Testcase_Finish](@ref DPRSMI_Testcase_Finish) Finish Conditions
 *		-# [Testcase_Cancel](@ref DPRSMI_Testcase_Cancel) Cancel Conditions
 *		-# [Testcase_Abort](@ref DPRSMI_Testcase_Abort) Abort Conditions
 *		-# [Testcase_Degradation](@ref DPRSMI_Testcase_Degradation) Degradation Conditions
 *		-# [Testcase_Clearance](@ref DPRSMI_Testcase_Clearance) Suppress Conditions
 *		-# [Testcase_Function_Error](@ref DPRSMI_Testcase_Function_Error) RDP Error
 *		-# [Testcase_State_Machine](@ref DPRSMI_Testcase_State_Machine) RDP System State
 *		-# [Testcase_Internal_System_State_Left](@ref DPRSMI_Testcase_Internal_System_State_Left) Internal System State - Left Side
 *		-# [Testcase_Internal_System_State_Right](@ref DPRSMI_Testcase_Internal_System_State_Right) Internal System State - Right Side
 *		
 *	@traceability
 *		[\@link: DPRSMI Module Requirements]()
 */
extern void DPRSMI_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPRSMI_H_
