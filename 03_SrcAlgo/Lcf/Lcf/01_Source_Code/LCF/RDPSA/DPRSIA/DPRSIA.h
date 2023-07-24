/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSIA.h
//! @brief     (DPRSIA) Module Header.

#ifndef DPRSIA_H_
#define DPRSIA_H_

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
 *	DPRSIA module sensor initialization function. Function initializes DPRSIA sensor debug data pointer.
 *	
 *	@param
 *		[in] DPRSIA_SenDbgArg Pointer to DPRSIA sensor debug data.
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
extern void DPRSIA_SenInitDbgPtr(DPRSIA_SenDbgType *DPRSIA_SenDbgArg);

/*!
 *	DPRSIA module sensor reset function.
 *	
 *	@pre
 *		- The DPRSIA sensor initialization function(s) must be called once.
 *		- The DPRSIA sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DPRSIA_LnBndLeCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeCancelValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndLeCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeCancelValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndLeTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeTrgValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndLeTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeTrgValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndRiCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiCancelValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndRiCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiCancelValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndRiTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiTrgValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_LnBndRiTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiTrgValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndLeCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeCancelValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndLeCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeCancelValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndLeTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeTrgValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndLeTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeTrgValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndRiCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiCancelValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndRiCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiCancelValidRDW_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndRiTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiTrgValidRDP_bool) \n
 *		[Debug  Signal] [D_DPRSIA_RdBndRiTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiTrgValidRDW_bool) \n
 *		[Debug  Signal] [S_DPRSIA_DlcLeRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcLeRDP_met) \n
 *		[Debug  Signal] [S_DPRSIA_DlcLeRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcLeRDW_met) \n
 *		[Debug  Signal] [S_DPRSIA_DlcRiRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcRiRDP_met) \n
 *		[Debug  Signal] [S_DPRSIA_DlcRiRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcRiRDW_met) \n
 *		[Debug  Signal] [S_DPRSIA_DrcLeRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcLeRDP_met) \n
 *		[Debug  Signal] [S_DPRSIA_DrcLeRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcLeRDW_met) \n
 *		[Debug  Signal] [S_DPRSIA_DrcRiRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcRiRDP_met) \n
 *		[Debug  Signal] [S_DPRSIA_DrcRiRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcRiRDW_met) \n
 *		[Debug  Signal] [S_DPRSIA_LaneWidthRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_LaneWidthRDP_met) \n
 *		[Debug  Signal] [S_DPRSIA_LaneWidthRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_LaneWidthRDW_met) \n
 *		[Debug  Signal] [S_DPRSIA_LnBndValidRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_LnBndValidRDP_nu) \n
 *		[Debug  Signal] [S_DPRSIA_LnBndValidRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_LnBndValidRDW_nu) \n
 *		[Debug  Signal] [S_DPRSIA_RdBndValidRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_RdBndValidRDP_nu) \n
 *		[Debug  Signal] [S_DPRSIA_RdBndValidRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_RdBndValidRDW_nu) \n
 *		[Debug  Signal] [S_DPRSIA_SideCondRDPLe_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDPLe_btf) \n
 *		[Debug  Signal] [S_DPRSIA_SideCondRDPRi_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDPRi_btf) \n
 *		[Debug  Signal] [S_DPRSIA_SideCondRDWLe_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDWLe_btf) \n
 *		[Debug  Signal] [S_DPRSIA_SideCondRDWRi_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDWRi_btf) \n
 *		[Debug  Signal] [S_DPRSIA_SpecificRDP_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SpecificRDP_btf) \n
 *		[Debug  Signal] [S_DPRSIA_SpecificRDW_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SpecificRDW_btf) \n
 *		[Debug  Signal] [S_DPRSIA_TgtCntrLnEnable_bool](@ref DPRSIA_SenDbgType::S_DPRSIA_TgtCntrLnEnable_bool) \n
 *		[Debug  Signal] [S_DPRSIA_TlcLeRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcLeRDP_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TlcLeRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcLeRDW_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TlcRiRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcRiRDP_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TlcRiRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcRiRDW_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TrcLeRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcLeRDP_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TrcLeRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcLeRDW_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TrcRiRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcRiRDP_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TrcRiRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcRiRDW_sec) \n
 *		[Debug  Signal] [S_DPRSIA_TriggerReasonLeRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonLeRDP_nu) \n
 *		[Debug  Signal] [S_DPRSIA_TriggerReasonLeRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonLeRDW_nu) \n
 *		[Debug  Signal] [S_DPRSIA_TriggerReasonRiRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonRiRDP_nu) \n
 *		[Debug  Signal] [S_DPRSIA_TriggerReasonRiRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonRiRDW_nu) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatLnLeRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnLeRDP_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatLnLeRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnLeRDW_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatLnRiRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnRiRDP_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatLnRiRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnRiRDW_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatReLeRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReLeRDP_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatReLeRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReLeRDW_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatReRiRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReRiRDP_mps) \n
 *		[Debug  Signal] [S_DPRSIA_VelLatReRiRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReRiRDW_mps) \n\n
 *		For signal details, see sub-section [Globals](@ref DPRSIA_SenProcess_Globals) of the function @ref DPRSIA_SenProcess.
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
extern void DPRSIA_SenReset(void);

/*!
 *	DPRSIA module sensor process function.
 *	
 *	@pre
 *		- The DPRSIA sensor initialization function(s) must be called once.
 *		- The DPRSIA sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPRSIA_SenProcess_Globals
 *		[D_DPRSIA_LnBndLeCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeCancelValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the RDP in order to cancel. \n\n
 *		[D_DPRSIA_LnBndLeCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeCancelValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the RDW in order to cancel. \n\n
 *		[D_DPRSIA_LnBndLeTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeTrgValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the RDP in order to trigger. \n\n
 *		[D_DPRSIA_LnBndLeTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndLeTrgValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the RDW in order to trigger. \n\n
 *		[D_DPRSIA_LnBndRiCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiCancelValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the RDP in order to cancel. \n\n
 *		[D_DPRSIA_LnBndRiCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiCancelValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the RDW in order to cancel. \n\n
 *		[D_DPRSIA_LnBndRiTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiTrgValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the RDP in order to trigger. \n\n
 *		[D_DPRSIA_LnBndRiTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_LnBndRiTrgValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the RDW in order to trigger. \n\n
 *		[D_DPRSIA_RdBndLeCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeCancelValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left road edge for the RDP in order to cancel. \n\n
 *		[D_DPRSIA_RdBndLeCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeCancelValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left road edge for the RDW in order to cancel. \n\n
 *		[D_DPRSIA_RdBndLeTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeTrgValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left road edge for the RDP in order to trigger. \n\n
 *		[D_DPRSIA_RdBndLeTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndLeTrgValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left road edge for the RDW in order to trigger. \n\n
 *		[D_DPRSIA_RdBndRiCancelValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiCancelValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right road edge for the RDP in order to cancel. \n\n
 *		[D_DPRSIA_RdBndRiCancelValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiCancelValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right road edge for the RDW in order to cancel. \n\n
 *		[D_DPRSIA_RdBndRiTrgValidRDP_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiTrgValidRDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right road edge for the RDP in order to trigger. \n\n
 *		[D_DPRSIA_RdBndRiTrgValidRDW_bool](@ref DPRSIA_SenDbgType::D_DPRSIA_RdBndRiTrgValidRDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right road edge for the RDW in order to trigger. \n\n
 *		[S_DPRSIA_DlcLeRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcLeRDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the RDP. \n\n
 *		[S_DPRSIA_DlcLeRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcLeRDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the RDW. \n\n
 *		[S_DPRSIA_DlcRiRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcRiRDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the RDP. \n\n
 *		[S_DPRSIA_DlcRiRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DlcRiRDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the RDW. \n\n
 *		[S_DPRSIA_DrcLeRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcLeRDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left road edge for the RDP. \n\n
 *		[S_DPRSIA_DrcLeRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcLeRDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left road edge for the RDW. \n\n
 *		[S_DPRSIA_DrcRiRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcRiRDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right road edge for the RDP. \n\n
 *		[S_DPRSIA_DrcRiRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_DrcRiRDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right road edge for the RDW. \n\n
 *		[S_DPRSIA_LaneWidthRDP_met](@ref DPRSIA_SenDbgType::S_DPRSIA_LaneWidthRDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across RDP. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		[S_DPRSIA_LaneWidthRDW_met](@ref DPRSIA_SenDbgType::S_DPRSIA_LaneWidthRDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across RDW. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		[S_DPRSIA_LnBndValidRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_LnBndValidRDP_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Validity of both lane markings for the RDP function. \n\n
 *		[S_DPRSIA_LnBndValidRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_LnBndValidRDW_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Validity of both lane markings for the RDW function. \n\n
 *		[S_DPRSIA_RdBndValidRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_RdBndValidRDP_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Validity of both road edges for the RDP function. \n\n
 *		[S_DPRSIA_RdBndValidRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_RdBndValidRDW_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Validity of both road edges for the RDW function. \n\n
 *		[S_DPRSIA_SideCondRDPLe_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDPLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the RDP. \n\n
 *		[S_DPRSIA_SideCondRDPRi_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDPRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the RDP. \n\n
 *		[S_DPRSIA_SideCondRDWLe_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDWLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the RDW. \n\n
 *		[S_DPRSIA_SideCondRDWRi_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SideCondRDWRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the RDW. \n\n
 *		[S_DPRSIA_SpecificRDP_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SpecificRDP_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the RDP. \n\n
 *		[S_DPRSIA_SpecificRDW_btf](@ref DPRSIA_SenDbgType::S_DPRSIA_SpecificRDW_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the RDW. \n\n
 *		[S_DPRSIA_TgtCntrLnEnable_bool](@ref DPRSIA_SenDbgType::S_DPRSIA_TgtCntrLnEnable_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
 *		[S_DPRSIA_TlcLeRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcLeRDP_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the RDP. \n\n
 *		[S_DPRSIA_TlcLeRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcLeRDW_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the RDW. \n\n
 *		[S_DPRSIA_TlcRiRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcRiRDP_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the RDP. \n\n
 *		[S_DPRSIA_TlcRiRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TlcRiRDW_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the RDW. \n\n
 *		[S_DPRSIA_TrcLeRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcLeRDP_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left road edge for the RDP. \n\n
 *		[S_DPRSIA_TrcLeRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcLeRDW_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left road edge for the RDW. \n\n
 *		[S_DPRSIA_TrcRiRDP_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcRiRDP_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right road edge for the RDP. \n\n
 *		[S_DPRSIA_TrcRiRDW_sec](@ref DPRSIA_SenDbgType::S_DPRSIA_TrcRiRDW_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right road edge for the RDW. \n\n
 *		[S_DPRSIA_TriggerReasonLeRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonLeRDP_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Left side Trigger Reason of the RDP function. \n\n
 *		[S_DPRSIA_TriggerReasonLeRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonLeRDW_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Left side Trigger Reason of the RDW function. \n\n
 *		[S_DPRSIA_TriggerReasonRiRDP_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonRiRDP_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Right side Trigger Reason of the RDP function. \n\n
 *		[S_DPRSIA_TriggerReasonRiRDW_nu](@ref DPRSIA_SenDbgType::S_DPRSIA_TriggerReasonRiRDW_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_DPRSMI_TrgReasType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 4 \n
 *		\@description: \n
 *		Right side Trigger Reason of the RDW function. \n\n
 *		[S_DPRSIA_VelLatLnLeRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnLeRDP_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the RDP. \n\n
 *		[S_DPRSIA_VelLatLnLeRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnLeRDW_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the RDW. \n\n
 *		[S_DPRSIA_VelLatLnRiRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnRiRDP_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the RDP. \n\n
 *		[S_DPRSIA_VelLatLnRiRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatLnRiRDW_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the RDW. \n\n
 *		[S_DPRSIA_VelLatReLeRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReLeRDP_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left road edge for the RDP. \n\n
 *		[S_DPRSIA_VelLatReLeRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReLeRDW_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left road edge for the RDW. \n\n
 *		[S_DPRSIA_VelLatReRiRDP_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReRiRDP_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right road edge for the RDP. \n\n
 *		[S_DPRSIA_VelLatReRiRDW_mps](@ref DPRSIA_SenDbgType::S_DPRSIA_VelLatReRiRDW_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right road edge for the RDW. \n\n
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
 *		@ref S_ABPLBP_ExitLeft_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Exit flag for left side \n\n
 *		@ref S_ABPLBP_ExitRight_perc \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Exit flag for right side \n\n
 *		@ref S_ABPLBP_LaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Lane width \n\n
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
 *		@ref S_ABPLBP_UncoupledLaneWidth_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Raw lane width of ABD interface uncoupled lane data \n\n
 *		@ref S_ABPREP_LeReClthCrvSIF_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left road edge clothoid curvature (safety interface) \n\n
 *		@ref S_ABPREP_LeReClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Left road edge clothoid curvature \n\n
 *		@ref S_ABPREP_LeReClthHeadingSIF_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left road edge clothoid yaw angle (safety interface) \n\n
 *		@ref S_ABPREP_LeReClthPosY0SIF_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Left road edge clothoid lateral distance (safety interface) \n\n
 *		@ref S_ABPREP_LeReHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Left road edge clothoid yaw angle \n\n
 *		@ref S_ABPREP_LeReInvalidQuSIF_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_ABPREP_RiReClthCrvSIF_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right road edge clothoid curvature (safety interface); \n\n
 *		@ref S_ABPREP_RiReClthCrv_1pm \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Right road edge clothoid curvature \n\n
 *		@ref S_ABPREP_RiReClthHeadingSIF_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right road edge clothoid yaw angle (safety interface); \n\n
 *		@ref S_ABPREP_RiReClthPosY0SIF_met \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Right road edge clothoid lateral distance (safety interface); \n\n
 *		@ref S_ABPREP_RiReHeading_rad \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_rad_m0p7854_0p7854_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.7854 \n
 *		\@max: 0.7854 \n
 *		\@description: \n
 *		Right road edge clothoid yaw angle \n\n
 *		@ref S_ABPREP_RiReInvalidQuSIF_btf \n
 *		\@kind: Input Signal \n
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
 *		@ref S_DPRSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_DPRSMW_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the warning, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_LCFRCV_RDPSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the RDP \n\n
 *		@ref S_LCFRCV_RDWSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the RDW. \n\n
 *		@ref S_LCFRCV_SteerWAngleRate_degps \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Steering Wheel Angle Rate from CAN Bus \n\n
 *		@ref S_LCFRCV_SteerWAngle_deg \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Steering Wheel Angle from CAN Bus \n\n
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
 *		@ref S_LCFRCV_TurnSignalState_enum \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_VDPDRV_TurnSignalType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Turn Indicator signal state \n\n
 *		@ref S_LCFRCV_VDy_VehVelocity_kph \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Tachometer Vehicle Speed in kilometers/hour \n\n
 *		@ref S_LCFRCV_VehAclX_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Vehicle longitudinal acceleration \n\n
 *		@ref S_LCFRCV_VehAclY_mps2 \n
 *		\@kind: Input Signal \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Vehicle lateral acceleration \n\n
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
 *		@ref P_DPRSIA_AclXHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the longitudinal acceleration for the RDP. \n\n
 *		@ref P_DPRSIA_AclXMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the longitudinal acceleration for the RDP. \n\n
 *		@ref P_DPRSIA_AclXMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum allowed value of the longitudinal acceleration for the RDP. \n\n
 *		@ref P_DPRSIA_AclYHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the lateral acceleration for the RDP. \n\n
 *		@ref P_DPRSIA_AclYMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the lateral acceleration for the RDP. \n\n
 *		@ref P_DPRSIA_ConstrSiteLnTurnOff_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Construction Site turn off delay for the lane marking validity. \n\n
 *		@ref P_DPRSIA_ConstrSiteLnTurnOn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Construction Site turn on delay for the lane marking validity. \n\n
 *		@ref P_DPRSIA_ConstrSiteLn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Construction Site Enable Switch for lane markings \n\n
 *		@ref P_DPRSIA_ConstrSiteReTurnOff_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Construction Site turn off delay for the road edge validity. \n\n
 *		@ref P_DPRSIA_ConstrSiteReTurnOn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Construction Site turn on delay for the road edge validity. \n\n
 *		@ref P_DPRSIA_ConstrSiteRe_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Construction Site Enable Switch for road edges \n\n
 *		@ref P_DPRSIA_ExitRampProb_perc \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_Perc_0_100_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: % \n
 *		\@min: 0 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		Minimum threshold (in percentage) that determines if an exit ramp was detected. \n\n
 *		@ref P_DPRSIA_ExitRampTurnOff_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn off time for the exit ramp. \n\n
 *		@ref P_DPRSIA_ExitRampTurnOn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on time for the exit ramp. \n\n
 *		@ref P_DPRSIA_LaneBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the LaneBitfield are needed to triger the RDP function. Used with S_ABPLBP_LeLnInvalidQu_btf/S_ABPLBP_RiLnInvalidQu_btf. \n\n
 *		@ref P_DPRSIA_LaneBridgedBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which bits of the LaneBitfield mean lane markling bridged. \n\n
 *		@ref P_DPRSIA_LaneCancelBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the LaneBitfield are needed to cancel the function. \n\n
 *		@ref P_DPRSIA_LaneSafetyBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the LaneSafetyBitfield can cancel the function. \n\n
 *		@ref P_DPRSIA_LaneWidthHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Hysteresis of the lane width validation for the RDP. \n\n
 *		@ref P_DPRSIA_LaneWidthMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum allowed value of the lane width validation for the RDP. \n\n
 *		@ref P_DPRSIA_LaneWidthMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum allowed value of the lane width validation for the RDP. \n\n
 *		@ref P_DPRSIA_LaneWidthSIFOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If the switch is on, the Coupled/Uncoupled Lane Width will be taking into account and checked to trigger or cancel an intervention. If not, it will be ignored. \n\n
 *		@ref P_DPRSIA_LaneWidthSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Lane width validation switch for the RDP. \n\n
 *		@ref P_DPRSIA_LaneWidthWideLnDef_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width Default value. Used if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref P_DPRSIA_LaneWidthWideLn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		New Lane Width too big logic switch. If on, lanes too wide will be considerd valid and a default lane width will be used. \n\n
 *		@ref P_DPRSIA_LnBndTurnOnTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the lane marking validity flags. \n\n
 *		@ref P_DPRSIA_LnHeadAngThresHyst_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Hysteresis of the heading angle to the lane marking validation. \n\n
 *		@ref P_DPRSIA_LnHeadAngThresMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximal value of the heading angle to the lane marking validation. \n\n
 *		@ref P_DPRSIA_LnHeadAngThresMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Minimal value of the heading angle to the lane marking validation. \n\n
 *		@ref P_DPRSIA_LnRdWidthHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Hysteresis of the lane/road width validation for the RDP. \n\n
 *		@ref P_DPRSIA_LnRdWidthMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum allowed value of the lane/road width validation for the RDP. \n\n
 *		@ref P_DPRSIA_LnRdWidthMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum allowed value of the lane/road width validation for the RDP. \n\n
 *		@ref P_DPRSIA_RDPSpecificDebTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Vector containing the turn off debounce times of the RDP Specific Qualifier. \n\n
 *		@ref P_DPRSIA_RdBndTurnOnTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the road edge validity flags. \n\n
 *		@ref P_DPRSIA_ReHeadAngThresHyst_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Hysteresis of the heading angle to the road edge validation. \n\n
 *		@ref P_DPRSIA_ReHeadAngThresMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximal value of the heading angle to the road edge validation. \n\n
 *		@ref P_DPRSIA_ReHeadAngThresMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Minimal value of the heading angle to the road edge validation. \n\n
 *		@ref P_DPRSIA_RoadBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that indicates which properties of the RoadBitfield are needed to trigger the function. \n\n
 *		@ref P_DPRSIA_RoadBridgedBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which bits of the RoadBitfield mean road edge bridged. \n\n
 *		@ref P_DPRSIA_RoadCancelBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the RoadBitfield can cancel the function. \n\n
 *		@ref P_DPRSIA_RoadSafetyBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the RoadSafetyBitfield can cancel the function. \n\n
 *		@ref P_DPRSIA_RoadWidthHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Hysteresis of the road width validation for the RDP. \n\n
 *		@ref P_DPRSIA_RoadWidthMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum allowed value of the road width validation for the RDP. \n\n
 *		@ref P_DPRSIA_RoadWidthMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum allowed value of the road width validation for the RDP. \n\n
 *		@ref P_DPRSIA_RoadWidthSwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Road width validation switch for the RDP. \n\n
 *		@ref P_DPRSIA_SafetyIfaceLnOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the data from the safety lane markings will be used to trigger the function. Else, the control interface data will be used. \n\n
 *		@ref P_DPRSIA_SafetyIfaceReOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the data from the safety road edges will be used to trigger the function. Else, the control interface data will be used. \n\n
 *		@ref P_DPRSIA_StrWhlAngSpeedHyst_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Hysteresis of the steering wheel angle rate validation for the RDP. \n\n
 *		@ref P_DPRSIA_StrWhlAngSpeedMax_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum allowed value of the steering wheel angle rate validation for the RDP. \n\n
 *		@ref P_DPRSIA_StrWhlAngleHyst_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Hysteresis of the steering wheel angle validation for the RDP. \n\n
 *		@ref P_DPRSIA_StrWhlAngleMax_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Maximum allowed value of the steering wheel angle validation for the RDP. \n\n
 *		@ref P_DPRSIA_TlcHeadAngThres_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		For the Tlc Criterium to be fulfilled, the heading angle between the lane marking and the vehicle has to be under a certain threshold. \n\n
 *		@ref P_DPRSIA_TrcHeadAngThres_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		For the Trc Criterium to be fulfilled, the heading angle between the road edge and the vehicle has to be under a certain threshold. \n\n
 *		@ref P_DPRSIA_TriggerCondEnable_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield that decides with constellation of lane markings and road edges is valid. \n\n
 *		@ref P_DPRSIA_TurnSignHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Holding time of the turn signals. \n\n
 *		@ref P_DPRSIA_TurnSignReset_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the turn signal holding time is reseted when the driver switches on the turn light in the other direction. \n\n
 *		@ref P_DPRSIA_UncoupledLWEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If the switch in on, the uncoupled model lane width will be used. Else, the coupled model lane width. \n\n
 *		@ref P_DPRSIA_VelLatThresHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the lateral velocity for the RDP. \n\n
 *		@ref P_DPRSIA_VelLatThresMax_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the lateral  velocity for the RDP. \n\n
 *		@ref P_DPRSIA_VelLatThresMin_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum allowed value of the lateral velocity for the RDP. \n\n
 *		@ref P_DPRSIA_VelVehDispHyst_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Hysteresis of the displayed longitudinal velocity for the RDP. \n\n
 *		@ref P_DPRSIA_VelVehDispMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum allowed value of the displayed longitudinal velocity for the RDP. \n\n
 *		@ref P_DPRSIA_VelVehDispMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum allowed value of the displayed longitudinal velocity for the RDP. \n\n
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
 *		@ref P_VEH_Width_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
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
 *		@ref X_LCF_VelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPRSIA_CrvVehCrvTurnOn_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x6x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the vehicle curvature activation condition. \n\n
 *		@ref Y_DPRSIA_VXLnCrvThresHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the lane marking curvature validation. \n\n
 *		@ref Y_DPRSIA_VXLnCrvThresMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximal value of the lane marking curvature validation. \n\n
 *		@ref Y_DPRSIA_VXReCrvThresHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the road edge curvature validation. \n\n
 *		@ref Y_DPRSIA_VXReCrvThresMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximal value of the road edge curvature validation. \n\n
 *		@ref Y_DPRSIA_VXVehCrvThresHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the vehicle curvature validation. \n\n
 *		@ref Y_DPRSIA_VXVehCrvThresMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximal value of the vehicle curvature validation. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPRSIA Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPRSIA_Testcase_Initialization) Initialization of the DPRSIA
 *		-# [Testcase_Lane_Marking_Validation_RDP_Left](@ref DPRSIA_Testcase_Lane_Marking_Validation_RDP_Left) Lane_Marking_Validation_RDP_Left
 *		-# [Testcase_Lane_Marking_Validation_RDP_Right](@ref DPRSIA_Testcase_Lane_Marking_Validation_RDP_Right) Lane_Marking_Validation_RDP_Right
 *		-# [Testcase_Lane_Marking_Validation_RDW_Left](@ref DPRSIA_Testcase_Lane_Marking_Validation_RDW_Left) Lane_Marking_Validation_RDW_Left
 *		-# [Testcase_Lane_Marking_Validation_RDW_Right](@ref DPRSIA_Testcase_Lane_Marking_Validation_RDW_Right) Lane_Marking_Validation_RDW_Right
 *		-# [Testcase_Road_Edge_Validation_RDP_Left](@ref DPRSIA_Testcase_Road_Edge_Validation_RDP_Left) Road_Edge_Validation_RDP_Left
 *		-# [Testcase_Road_Edge_Validation_RDP_Right](@ref DPRSIA_Testcase_Road_Edge_Validation_RDP_Right) Road_Edge_Validation_RDP_Right
 *		-# [Testcase_Road_Edge_Validation_RDW_Left](@ref DPRSIA_Testcase_Road_Edge_Validation_RDW_Left) Road_Edge_Validation_RDW_Left
 *		-# [Testcase_Road_Edge_Validation_RDW_Right](@ref DPRSIA_Testcase_Road_Edge_Validation_RDW_Right) Road_Edge_Validation_RDW_Right
 *		-# [Testcase_Trigger_Reason_RDP](@ref DPRSIA_Testcase_Trigger_Reason_RDP) Testcase_Trigger_Reason
 *		-# [Testcase_Trigger_Reason_RDW](@ref DPRSIA_Testcase_Trigger_Reason_RDW) Testcase_Trigger_Reason
 *		-# [Testcase_Dlc_Tlc_RDP](@ref DPRSIA_Testcase_Dlc_Tlc_RDP) Testcase_Dlc_Tlc
 *		-# [Testcase_Drc_Trc_RDP](@ref DPRSIA_Testcase_Drc_Trc_RDP) Testcase_Drc_Trc
 *		-# [Testcase_Dlc_Tlc_RDW](@ref DPRSIA_Testcase_Dlc_Tlc_RDW) Testcase_Dlc_Tlc
 *		-# [Testcase_Drc_Trc_RDW](@ref DPRSIA_Testcase_Drc_Trc_RDW) Testcase_Drc_Trc
 *		-# [Testcase_Specific_RDP_RDW](@ref DPRSIA_Testcase_Specific_RDP_RDW) Specific Qualifier RDP_RDW
 *		-# [Testcase_Side_Conditions_RDP](@ref DPRSIA_Testcase_Side_Conditions_RDP) Testcase_Side_Conditions
 *		-# [Testcase_Side_Conditions_RDW](@ref DPRSIA_Testcase_Side_Conditions_RDW) Testcase_Side_Conditions
 *		
 *	@traceability
 *		[\@link: DPRSIA Module Requirements]()
 */
extern void DPRSIA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPRSIA_H_
