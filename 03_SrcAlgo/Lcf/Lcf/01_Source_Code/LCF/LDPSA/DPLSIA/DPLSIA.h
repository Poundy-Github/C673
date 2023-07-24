/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSIA.h
//! @brief     (DPLSIA) Module Header.

#ifndef DPLSIA_H_
#define DPLSIA_H_

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
 *	DPLSIA module sensor initialization function. Function initializes DPLSIA sensor debug data pointer.
 *	
 *	@param
 *		[in] DPLSIA_SenDbgArg Pointer to DPLSIA sensor debug data.
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
extern void DPLSIA_SenInitDbgPtr(DPLSIA_SenDbgType *DPLSIA_SenDbgArg);

/*!
 *	DPLSIA module sensor reset function.
 *	
 *	@pre
 *		- The DPLSIA sensor initialization function(s) must be called once.
 *		- The DPLSIA sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_DPLSIA_LnBndLeCancelValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeCancelValidLDP_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndLeCancelValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeCancelValidLDW_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndLeTrgValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeTrgValidLDP_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndLeTrgValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeTrgValidLDW_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndRiCancelValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiCancelValidLDP_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndRiCancelValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiCancelValidLDW_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndRiTrgValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiTrgValidLDP_bool) \n
 *		[Debug  Signal] [D_DPLSIA_LnBndRiTrgValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiTrgValidLDW_bool) \n
 *		[Debug  Signal] [S_DPLSIA_CurveTypeLe_enum](@ref DPLSIA_SenDbgType::S_DPLSIA_CurveTypeLe_enum) \n
 *		[Debug  Signal] [S_DPLSIA_CurveTypeRi_enum](@ref DPLSIA_SenDbgType::S_DPLSIA_CurveTypeRi_enum) \n
 *		[Debug  Signal] [S_DPLSIA_DlcLeLDP_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcLeLDP_met) \n
 *		[Debug  Signal] [S_DPLSIA_DlcLeLDW_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcLeLDW_met) \n
 *		[Debug  Signal] [S_DPLSIA_DlcRiLDP_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcRiLDP_met) \n
 *		[Debug  Signal] [S_DPLSIA_DlcRiLDW_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcRiLDW_met) \n
 *		[Debug  Signal] [S_DPLSIA_LaneWidthLDP_met](@ref DPLSIA_SenDbgType::S_DPLSIA_LaneWidthLDP_met) \n
 *		[Debug  Signal] [S_DPLSIA_LaneWidthLDW_met](@ref DPLSIA_SenDbgType::S_DPLSIA_LaneWidthLDW_met) \n
 *		[Debug  Signal] [S_DPLSIA_LnBndLeValidLDP_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndLeValidLDP_bool) \n
 *		[Debug  Signal] [S_DPLSIA_LnBndLeValidLDW_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndLeValidLDW_bool) \n
 *		[Debug  Signal] [S_DPLSIA_LnBndRiValidLDP_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndRiValidLDP_bool) \n
 *		[Debug  Signal] [S_DPLSIA_LnBndRiValidLDW_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndRiValidLDW_bool) \n
 *		[Debug  Signal] [S_DPLSIA_LnBndValidLDP_nu](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndValidLDP_nu) \n
 *		[Debug  Signal] [S_DPLSIA_LnBndValidLDW_nu](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndValidLDW_nu) \n
 *		[Debug  Signal] [S_DPLSIA_SideCondLDPLe_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDPLe_btf) \n
 *		[Debug  Signal] [S_DPLSIA_SideCondLDPRi_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDPRi_btf) \n
 *		[Debug  Signal] [S_DPLSIA_SideCondLDWLe_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDWLe_btf) \n
 *		[Debug  Signal] [S_DPLSIA_SideCondLDWRi_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDWRi_btf) \n
 *		[Debug  Signal] [S_DPLSIA_SpecificLDP_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SpecificLDP_btf) \n
 *		[Debug  Signal] [S_DPLSIA_SpecificLDW_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SpecificLDW_btf) \n
 *		[Debug  Signal] [S_DPLSIA_TgtCntrLnEnable_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_TgtCntrLnEnable_bool) \n
 *		[Debug  Signal] [S_DPLSIA_TlcLeLDP_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcLeLDP_sec) \n
 *		[Debug  Signal] [S_DPLSIA_TlcLeLDW_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcLeLDW_sec) \n
 *		[Debug  Signal] [S_DPLSIA_TlcRiLDP_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcRiLDP_sec) \n
 *		[Debug  Signal] [S_DPLSIA_TlcRiLDW_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcRiLDW_sec) \n
 *		[Debug  Signal] [S_DPLSIA_VelLatLeLDP_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatLeLDP_mps) \n
 *		[Debug  Signal] [S_DPLSIA_VelLatLeLDW_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatLeLDW_mps) \n
 *		[Debug  Signal] [S_DPLSIA_VelLatRiLDP_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatRiLDP_mps) \n
 *		[Debug  Signal] [S_DPLSIA_VelLatRiLDW_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatRiLDW_mps) \n\n
 *		For signal details, see sub-section [Globals](@ref DPLSIA_SenProcess_Globals) of the function @ref DPLSIA_SenProcess.
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
extern void DPLSIA_SenReset(void);

/*!
 *	DPLSIA module sensor process function.
 *	
 *	@pre
 *		- The DPLSIA sensor initialization function(s) must be called once.
 *		- The DPLSIA sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor DPLSIA_SenProcess_Globals
 *		[D_DPLSIA_LnBndLeCancelValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeCancelValidLDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDP in order to cancel. \n\n
 *		[D_DPLSIA_LnBndLeCancelValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeCancelValidLDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDW in order to cancel. \n\n
 *		[D_DPLSIA_LnBndLeTrgValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeTrgValidLDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDP in order to trigger. \n\n
 *		[D_DPLSIA_LnBndLeTrgValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndLeTrgValidLDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDW in order to trigger. \n\n
 *		[D_DPLSIA_LnBndRiCancelValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiCancelValidLDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDP in order to cancel. \n\n
 *		[D_DPLSIA_LnBndRiCancelValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiCancelValidLDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDW in order to cancel. \n\n
 *		[D_DPLSIA_LnBndRiTrgValidLDP_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiTrgValidLDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDP in order to trigger. \n\n
 *		[D_DPLSIA_LnBndRiTrgValidLDW_bool](@ref DPLSIA_SenDbgType::D_DPLSIA_LnBndRiTrgValidLDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDW in order to trigger. \n\n
 *		[S_DPLSIA_CurveTypeLe_enum](@ref DPLSIA_SenDbgType::S_DPLSIA_CurveTypeLe_enum) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		[S_DPLSIA_CurveTypeRi_enum](@ref DPLSIA_SenDbgType::S_DPLSIA_CurveTypeRi_enum) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		[S_DPLSIA_DlcLeLDP_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcLeLDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the LDP. \n\n
 *		[S_DPLSIA_DlcLeLDW_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcLeLDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the LDW. \n\n
 *		[S_DPLSIA_DlcRiLDP_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcRiLDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the LDP. \n\n
 *		[S_DPLSIA_DlcRiLDW_met](@ref DPLSIA_SenDbgType::S_DPLSIA_DlcRiLDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the LDW. \n\n
 *		[S_DPLSIA_LaneWidthLDP_met](@ref DPLSIA_SenDbgType::S_DPLSIA_LaneWidthLDP_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across LDP. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		[S_DPLSIA_LaneWidthLDW_met](@ref DPLSIA_SenDbgType::S_DPLSIA_LaneWidthLDW_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across LDW. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		[S_DPLSIA_LnBndLeValidLDP_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndLeValidLDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDP and LDW functions. \n\n
 *		[S_DPLSIA_LnBndLeValidLDW_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndLeValidLDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the LDW function. \n\n
 *		[S_DPLSIA_LnBndRiValidLDP_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndRiValidLDP_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDP and LDW functions. \n\n
 *		[S_DPLSIA_LnBndRiValidLDW_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndRiValidLDW_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the LDW function. \n\n
 *		[S_DPLSIA_LnBndValidLDP_nu](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndValidLDP_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		 \n\n
 *		[S_DPLSIA_LnBndValidLDW_nu](@ref DPLSIA_SenDbgType::S_DPLSIA_LnBndValidLDW_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		Validity of the lane markings for the LDW function. \n\n
 *		[S_DPLSIA_SideCondLDPLe_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDPLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the LDP. \n\n
 *		[S_DPLSIA_SideCondLDPRi_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDPRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the LDP. \n\n
 *		[S_DPLSIA_SideCondLDWLe_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDWLe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the LDW. \n\n
 *		[S_DPLSIA_SideCondLDWRi_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SideCondLDWRi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the LDW. \n\n
 *		[S_DPLSIA_SpecificLDP_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SpecificLDP_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the LDP. \n\n
 *		[S_DPLSIA_SpecificLDW_btf](@ref DPLSIA_SenDbgType::S_DPLSIA_SpecificLDW_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the LDW. \n\n
 *		[S_DPLSIA_TgtCntrLnEnable_bool](@ref DPLSIA_SenDbgType::S_DPLSIA_TgtCntrLnEnable_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
 *		[S_DPLSIA_TlcLeLDP_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcLeLDP_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the LDP. \n\n
 *		[S_DPLSIA_TlcLeLDW_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcLeLDW_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the LDW. \n\n
 *		[S_DPLSIA_TlcRiLDP_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcRiLDP_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the LDP. \n\n
 *		[S_DPLSIA_TlcRiLDW_sec](@ref DPLSIA_SenDbgType::S_DPLSIA_TlcRiLDW_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the LDW. \n\n
 *		[S_DPLSIA_VelLatLeLDP_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatLeLDP_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the LDP. \n\n
 *		[S_DPLSIA_VelLatLeLDW_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatLeLDW_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the LDW. \n\n
 *		[S_DPLSIA_VelLatRiLDP_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatRiLDP_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the LDP. \n\n
 *		[S_DPLSIA_VelLatRiLDW_mps](@ref DPLSIA_SenDbgType::S_DPLSIA_VelLatRiLDW_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the LDW. \n\n
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
 *		@ref S_DPLSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the lateral intervention, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_DPLSMW_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Carries the information of the side of the warning, 1 for trigger to the left and 2 for trigger to the right. \n\n
 *		@ref S_LCFRCV_LDPSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the LDP \n\n
 *		@ref S_LCFRCV_LDWSwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
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
 *		@ref P_DPLSIA_AclXHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the longitudinal acceleration for the LDP. \n\n
 *		@ref P_DPLSIA_AclXLDWHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the longitudinal acceleration for the LDW. \n\n
 *		@ref P_DPLSIA_AclXLDWMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the longitudinal acceleration for the LDW. \n\n
 *		@ref P_DPLSIA_AclXLDWMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum allowed value of the longitudinal acceleration for the LDW. \n\n
 *		@ref P_DPLSIA_AclXMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the longitudinal acceleration for the LDP. \n\n
 *		@ref P_DPLSIA_AclXMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum allowed value of the longitudinal acceleration for the LDP. \n\n
 *		@ref P_DPLSIA_AclYHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the lateral acceleration for the LDP. \n\n
 *		@ref P_DPLSIA_AclYLDWHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the lateral acceleration for the LDW. \n\n
 *		@ref P_DPLSIA_AclYLDWMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the lateral acceleration for the LDW. \n\n
 *		@ref P_DPLSIA_AclYMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the lateral acceleration for the LDP. \n\n
 *		@ref P_DPLSIA_ConstrSiteLDP_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Construction Site Enable Switch for LDP \n\n
 *		@ref P_DPLSIA_ConstrSiteLDW_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Construction Site Enable Switch for LDW \n\n
 *		@ref P_DPLSIA_CurveDetectThreshold_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		If the curvature is above this threshold, a curve is considered, else, a straight line. \n\n
 *		@ref P_DPLSIA_HeadAngThresLDPHyst_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Hysteresis of the heading angle to the lane marking validation for LDP \n\n
 *		@ref P_DPLSIA_HeadAngThresLDPMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximal value of the heading angle to the lane marking validation for LDP \n\n
 *		@ref P_DPLSIA_HeadAngThresLDPMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Minimal value of the heading angle to the lane marking validation for LDP \n\n
 *		@ref P_DPLSIA_HeadAngThresLDWHyst_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Hysteresis of the heading angle to the lane marking validation for the LDW. \n\n
 *		@ref P_DPLSIA_HeadAngThresLDWMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Maximal value of the heading angle to the lane marking validation for the LDW. \n\n
 *		@ref P_DPLSIA_HeadAngThresLDWMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		Minimal value of the heading angle to the lane marking validation for the LDW. \n\n
 *		@ref P_DPLSIA_LDPSpecificDebTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Vector containing the turn off debounce times of the LDP Specific Qualifier. \n\n
 *		@ref P_DPLSIA_LaneBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_DPLSIA_LaneBridgedBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which bits of the LaneBitfield mean lane markling bridged. \n\n
 *		@ref P_DPLSIA_LaneCancelBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the LaneBitfield are needed to cancel the function. \n\n
 *		@ref P_DPLSIA_LaneSafetyBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitmask that carries the information of which properties of the LaneSafety Bitfield are needed to trigger the function. \n\n
 *		@ref P_DPLSIA_LaneWidthLDPHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Hysteresis of the lane width validation for the LDP. \n\n
 *		@ref P_DPLSIA_LaneWidthLDPMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum allowed value of the lane width validation for the LDP. \n\n
 *		@ref P_DPLSIA_LaneWidthLDPMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum allowed value of the lane width validation for the LDP. \n\n
 *		@ref P_DPLSIA_LaneWidthLDWHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Hysteresis of the lane width validation for the LDW. \n\n
 *		@ref P_DPLSIA_LaneWidthLDWMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Maximum allowed value of the lane width validation for the LDW. \n\n
 *		@ref P_DPLSIA_LaneWidthLDWMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		Minimum allowed value of the lane width validation for the LDW. \n\n
 *		@ref P_DPLSIA_LaneWidthSIFOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If the switch is on, the Coupled/Uncoupled Lane Width will be taking into account and checked to trigger or cancel an intervention. If not, it will be ignored. \n\n
 *		@ref P_DPLSIA_LaneWidthWideLnDef_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width Default value. Used if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref P_DPLSIA_LaneWidthWideLn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		New Lane Width too big logic switch. If on, lanes too wide will be considerd valid and a default lane width will be used. \n\n
 *		@ref P_DPLSIA_LnBndTurnOnTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the lane marking validity flags. \n\n
 *		@ref P_DPLSIA_SafetyIfaceLDPOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the data from the safety interface will be used to trigger the LDP. Else, the control interface data will be used. \n\n
 *		@ref P_DPLSIA_SafetyIfaceLDWOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the data from the safety interface will be used to trigger the LDW. Else, the control interface data will be used. \n\n
 *		@ref P_DPLSIA_StrWhlAngSpLDPHys_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Hysteresis of the steering wheel angle rate validation for the LDP. \n\n
 *		@ref P_DPLSIA_StrWhlAngSpLDPMax_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum allowed value of the steering wheel angle rate validation for the LDP. \n\n
 *		@ref P_DPLSIA_StrWhlAngSpLDWHys_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Hysteresis of the steering wheel angle rate validation for the LDW. \n\n
 *		@ref P_DPLSIA_StrWhlAngSpLDWMax_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		Maximum allowed value of the steering wheel angle rate validation for the LDW. \n\n
 *		@ref P_DPLSIA_StrWhlAngleLDPHyst_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Hysteresis of the steering wheel angle validation for the LDP. \n\n
 *		@ref P_DPLSIA_StrWhlAngleLDPMax_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Maximum allowed value of the steering wheel angle validation for the LDP. \n\n
 *		@ref P_DPLSIA_StrWhlAngleLDWHyst_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Hysteresis of the steering wheel angle validation for the LDW. \n\n
 *		@ref P_DPLSIA_StrWhlAngleLDWMax_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		Maximum allowed value of the steering wheel angle validation for the LDW. \n\n
 *		@ref P_DPLSIA_TlcHeadAngThres_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		For the Tlc Criterium to be fulfilled, the heading angle between the lane marking and the vehicle has to be under a certain threshold. (The vehicle shall be oriented towards the lane marking). \n\n
 *		@ref P_DPLSIA_TurnSignHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Holding time of the turn indicator signals. \n\n
 *		@ref P_DPLSIA_TurnSignReset_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If this parameter is enabled, the turn signal holding time is reseted when the driver switches on the turn light in the other direction. \n\n
 *		@ref P_DPLSIA_UncoupledLWEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If the switch in on, the uncoupled model lane width will be used. Else, the coupled model lane width. \n\n
 *		@ref P_DPLSIA_VelDispLDPHyst_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Hysteresis of the displayed longitudinal velocity for the LDP. \n\n
 *		@ref P_DPLSIA_VelDispLDPMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum allowed value of the displayed longitudinal velocity for the LDP. \n\n
 *		@ref P_DPLSIA_VelDispLDPMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum allowed value of the displayed longitudinal velocity for the LDP. \n\n
 *		@ref P_DPLSIA_VelDispLDWHyst_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Hysteresis of the displayed longitudinal velocity for the LDW. \n\n
 *		@ref P_DPLSIA_VelDispLDWMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Maximum allowed value of the displayed longitudinal velocity for the LDW. \n\n
 *		@ref P_DPLSIA_VelDispLDWMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		Minimum allowed value of the displayed longitudinal velocity for the LDW. \n\n
 *		@ref P_DPLSIA_VelLatThresLDPHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the displayed longitudinal velocity for the LDP \n\n
 *		@ref P_DPLSIA_VelLatThresLDPMax_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the displayed longitudinal velocity for the LDP \n\n
 *		@ref P_DPLSIA_VelLatThresLDPMin_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum allowed value of the displayed longitudinal velocity for the LDP \n\n
 *		@ref P_DPLSIA_VelLatThresLDWHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Hysteresis of the displayed longitudinal velocity for the LDW \n\n
 *		@ref P_DPLSIA_VelLatThresLDWMax_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Maximum allowed value of the displayed longitudinal velocity for the LDW \n\n
 *		@ref P_DPLSIA_VelLatThresLDWMin_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Minimum allowed value of the displayed longitudinal velocity for the LDW \n\n
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
 *		@ref P_VEH_Width_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_m1000_1000_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -1000 \n
 *		\@max: 1000 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref X_LCF_VelX_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m100_100_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: m/s \n
 *		\@min: -100 \n
 *		\@max: 100 \n
 *		\@description: \n
 *		 \n\n
 *		@ref Y_DPLSIA_VXCrvThresLDPHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the lane marking curvature validation. Speed Dependant. \n\n
 *		@ref Y_DPLSIA_VXCrvThresLDPMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximal value of the lane marking curvature validation for the LDP. \n\n
 *		@ref Y_DPLSIA_VXCrvThresLDWHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the lane marking curvature validation for the LDW. \n\n
 *		@ref Y_DPLSIA_VXCrvThresLDWMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximal value of the lane marking curvature validation for the LDW. \n\n
 *		@ref Y_DPLSIA_VXVehCrvThresHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the vehicle curvature validation for the LDP. \n\n
 *		@ref Y_DPLSIA_VXVehCrvThresLDWHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximum value of the vehicle curvature validation for the LDW. \n\n
 *		@ref Y_DPLSIA_VXVehCrvThresLDWMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the vehicle curvature validation for the LDW. \n\n
 *		@ref Y_DPLSIA_VXVehCrvThresMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximum value of the vehicle curvature validation for the LDP. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: DPLSIA Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		-# [Testcase_Initialization](@ref DPLSIA_Testcase_Initialization) Initialization of the DPLSIA
 *		-# [Testcase_Lane_Marking_Validation_LDP_Left](@ref DPLSIA_Testcase_Lane_Marking_Validation_LDP_Left) Lane_Marking_Validation_LDP
 *		-# [Testcase_Lane_Marking_Validation_LDP_Right](@ref DPLSIA_Testcase_Lane_Marking_Validation_LDP_Right) Lane_Marking_Validation_LDP
 *		-# [Testcase_Dlc_Tlc_LDP](@ref DPLSIA_Testcase_Dlc_Tlc_LDP) Testcase Dlc Tlc VLat LDP
 *		-# [Testcase_Specific_LDP](@ref DPLSIA_Testcase_Specific_LDP) Specific Qualifier LDP
 *		-# [Testcase_Side_Conditions_LDP](@ref DPLSIA_Testcase_Side_Conditions_LDP) Testcase Side Conditions LDP
 *		-# [Testcase_Lane_Marking_Validation_LDW_Left](@ref DPLSIA_Testcase_Lane_Marking_Validation_LDW_Left) Lane_Marking_Validation_LDW
 *		-# [Testcase_Lane_Marking_Validation_LDW_Right](@ref DPLSIA_Testcase_Lane_Marking_Validation_LDW_Right) Lane_Marking_Validation_LDP
 *		-# [Testcase_Dlc_Tlc_LDW](@ref DPLSIA_Testcase_Dlc_Tlc_LDW) Testcase Dlc Tlc VLat LDW
 *		-# [Testcase_Specific_LDW](@ref DPLSIA_Testcase_Specific_LDW) Specific Qualifier LDW
 *		-# [Testcase_Side_Conditions_LDW](@ref DPLSIA_Testcase_Side_Conditions_LDW) Testcase Side Conditions LDW
 *		-# [Testcase_Curve_Type](@ref DPLSIA_Testcase_Curve_Type) Testcase Curve Type
 *		
 *	@traceability
 *		[\@link: DPLSIA Module Requirements]()
 */
extern void DPLSIA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // DPLSIA_H_
