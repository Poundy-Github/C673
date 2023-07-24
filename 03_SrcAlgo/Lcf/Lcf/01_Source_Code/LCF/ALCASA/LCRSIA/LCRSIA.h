/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRSIA.h
//! @brief     (LCRSIA) Module Header.

#ifndef LCRSIA_H_
#define LCRSIA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_data.h"
#include "LCRSIA_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCRSIA module sensor initialization function. Function initializes LCRSIA sensor debug data pointer.
 *	
 *	@param
 *		[in] LCRSIA_SenDbgArg Pointer to LCRSIA sensor debug data.
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
extern void LCRSIA_SenInitDbgPtr(LCRSIA_SenDbgType *LCRSIA_SenDbgArg);

/*!
 *	LCRSIA module sensor initialization function. Function initializes LCRSIA sensor output data pointer.
 *	
 *	@param
 *		[in] LCRSIA_SenOutArg Pointer to LCRSIA sensor output data.
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
extern void LCRSIA_SenInitOutPtr(LCRSIA_SenOutType *LCRSIA_SenOutArg);

/*!
 *	LCRSIA module sensor reset function.
 *	
 *	@pre
 *		- The LCRSIA sensor initialization function(s) must be called once.
 *		- The LCRSIA sensor debug/output data pointer(s) should not be NULL.
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
 *		[Debug  Signal] [D_LCRSIA_LnBndLeCancelValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndLeCancelValidALCA_bool) \n
 *		[Debug  Signal] [D_LCRSIA_LnBndLeTrgValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndLeTrgValidALCA_bool) \n
 *		[Debug  Signal] [D_LCRSIA_LnBndRiCancelValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndRiCancelValidALCA_bool) \n
 *		[Debug  Signal] [D_LCRSIA_LnBndRiTrgValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndRiTrgValidALCA_bool) \n
 *		[Debug  Signal] [S_LCRSIA_DlcLeALCA_met](@ref LCRSIA_SenDbgType::S_LCRSIA_DlcLeALCA_met) \n
 *		[Debug  Signal] [S_LCRSIA_DlcRiALCA_met](@ref LCRSIA_SenDbgType::S_LCRSIA_DlcRiALCA_met) \n
 *		[Debug  Signal] [S_LCRSIA_LnBndLeValidALCA_bool](@ref LCRSIA_SenDbgType::S_LCRSIA_LnBndLeValidALCA_bool) \n
 *		[Debug  Signal] [S_LCRSIA_LnBndRiValidALCA_bool](@ref LCRSIA_SenDbgType::S_LCRSIA_LnBndRiValidALCA_bool) \n
 *		[Debug  Signal] [S_LCRSIA_LnBndValidALCA_nu](@ref LCRSIA_SenDbgType::S_LCRSIA_LnBndValidALCA_nu) \n
 *		[Debug  Signal] [S_LCRSIA_SideCondALCALe_btf](@ref LCRSIA_SenDbgType::S_LCRSIA_SideCondALCALe_btf) \n
 *		[Debug  Signal] [S_LCRSIA_SideCondALCARi_btf](@ref LCRSIA_SenDbgType::S_LCRSIA_SideCondALCARi_btf) \n
 *		[Debug  Signal] [S_LCRSIA_SpecificALCA_btf](@ref LCRSIA_SenDbgType::S_LCRSIA_SpecificALCA_btf) \n
 *		[Debug  Signal] [S_LCRSIA_TlcLeALCA_sec](@ref LCRSIA_SenDbgType::S_LCRSIA_TlcLeALCA_sec) \n
 *		[Debug  Signal] [S_LCRSIA_TlcRiALCA_sec](@ref LCRSIA_SenDbgType::S_LCRSIA_TlcRiALCA_sec) \n
 *		[Debug  Signal] [S_LCRSIA_VelLatLeALCA_mps](@ref LCRSIA_SenDbgType::S_LCRSIA_VelLatLeALCA_mps) \n
 *		[Debug  Signal] [S_LCRSIA_VelLatRiALCA_mps](@ref LCRSIA_SenDbgType::S_LCRSIA_VelLatRiALCA_mps) \n
 *		[Output Signal] [S_LCRSIA_CurveTypeLe_enum](@ref LCRSIA_SenOutType::S_LCRSIA_CurveTypeLe_enum) \n
 *		[Output Signal] [S_LCRSIA_CurveTypeRi_enum](@ref LCRSIA_SenOutType::S_LCRSIA_CurveTypeRi_enum) \n
 *		[Output Signal] [S_LCRSIA_LaneWidth_met](@ref LCRSIA_SenOutType::S_LCRSIA_LaneWidth_met) \n
 *		[Output Signal] [S_LCRSIA_TgtCntrLnEnable_bool](@ref LCRSIA_SenOutType::S_LCRSIA_TgtCntrLnEnable_bool) \n\n
 *		For signal details, see sub-section [Globals](@ref LCRSIA_SenProcess_Globals) of the function @ref LCRSIA_SenProcess.
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
extern void LCRSIA_SenReset(void);

/*!
 *	LCRSIA module sensor process function.
 *	
 *	@pre
 *		- The LCRSIA sensor initialization function(s) must be called once.
 *		- The LCRSIA sensor debug/output data pointer(s) should not be NULL.
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
 *		@anchor LCRSIA_SenProcess_Globals
 *		[D_LCRSIA_LnBndLeCancelValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndLeCancelValidALCA_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_LCRSIA_LnBndLeTrgValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndLeTrgValidALCA_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_LCRSIA_LnBndRiCancelValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndRiCancelValidALCA_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[D_LCRSIA_LnBndRiTrgValidALCA_bool](@ref LCRSIA_SenDbgType::D_LCRSIA_LnBndRiTrgValidALCA_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRSIA_DlcLeALCA_met](@ref LCRSIA_SenDbgType::S_LCRSIA_DlcLeALCA_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the left lane marking for the ALCA. \n\n
 *		[S_LCRSIA_DlcRiALCA_met](@ref LCRSIA_SenDbgType::S_LCRSIA_DlcRiALCA_met) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_m_m15_15_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: -15 \n
 *		\@max: 15 \n
 *		\@description: \n
 *		Distance to cross the right lane marking for the ALCA. \n\n
 *		[S_LCRSIA_LnBndLeValidALCA_bool](@ref LCRSIA_SenDbgType::S_LCRSIA_LnBndLeValidALCA_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the left lane marking for the ALCA \n\n
 *		[S_LCRSIA_LnBndRiValidALCA_bool](@ref LCRSIA_SenDbgType::S_LCRSIA_LnBndRiValidALCA_bool) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Validity of the right lane marking for the ALCA \n\n
 *		[S_LCRSIA_LnBndValidALCA_nu](@ref LCRSIA_SenDbgType::S_LCRSIA_LnBndValidALCA_nu) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref E_HMORQG_BndValidType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 3 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		[S_LCRSIA_SideCondALCALe_btf](@ref LCRSIA_SenDbgType::S_LCRSIA_SideCondALCALe_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the left side conditions for the ALCA \n\n
 *		[S_LCRSIA_SideCondALCARi_btf](@ref LCRSIA_SenDbgType::S_LCRSIA_SideCondALCARi_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the right side conditions for the ALCA \n\n
 *		[S_LCRSIA_SpecificALCA_btf](@ref LCRSIA_SenDbgType::S_LCRSIA_SpecificALCA_btf) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		Bitfield with the specific conditions for the ALCA \n\n
 *		[S_LCRSIA_TlcLeALCA_sec](@ref LCRSIA_SenDbgType::S_LCRSIA_TlcLeALCA_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the left lane marking for the ALCA \n\n
 *		[S_LCRSIA_TlcRiALCA_sec](@ref LCRSIA_SenDbgType::S_LCRSIA_TlcRiALCA_sec) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Time to cross the right lane marking for the ALCA \n\n
 *		[S_LCRSIA_VelLatLeALCA_mps](@ref LCRSIA_SenDbgType::S_LCRSIA_VelLatLeALCA_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the left lane marking for the ALCA \n\n
 *		[S_LCRSIA_VelLatRiALCA_mps](@ref LCRSIA_SenDbgType::S_LCRSIA_VelLatRiALCA_mps) \n
 *		\@kind: Debug Signal \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		Lateral velocity towards the right lane marking for the ALCA \n\n
 *		[S_LCRSIA_CurveTypeLe_enum](@ref LCRSIA_SenOutType::S_LCRSIA_CurveTypeLe_enum) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		[S_LCRSIA_CurveTypeRi_enum](@ref LCRSIA_SenOutType::S_LCRSIA_CurveTypeRi_enum) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref E_LCF_CurveType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
 *		[S_LCRSIA_LaneWidth_met](@ref LCRSIA_SenOutType::S_LCRSIA_LaneWidth_met) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width used across ALCA. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
 *		[S_LCRSIA_TgtCntrLnEnable_bool](@ref LCRSIA_SenOutType::S_LCRSIA_TgtCntrLnEnable_bool) \n
 *		\@kind: Output Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
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
 *		@ref S_LCFRCV_ALCASwitch_bool \n
 *		\@kind: Input Signal \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Main switch of the LDP \n\n
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
 *		@ref S_LCRSMI_DangerousSide_nu \n
 *		\@kind: Input Signal \n
 *		\@type: @ref E_LCF_DangerousSideType_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 2 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_AclXHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_AclXMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_AclXMin_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_AclYHyst_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_AclYMax_mps2 \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps2_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s^2 \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_ConstrSite_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		Construction Site Enable Switch for ALCA \n\n
 *		@ref P_LCRSIA_CurveDetectThreshold_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p1_0p1_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.1 \n
 *		\@max: 0.1 \n
 *		\@description: \n
 *		Parameter used to determine the curve. \n\n
 *		@ref P_LCRSIA_HeadAngThresALCAHyst_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_HeadAngThresALCAMax_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_HeadAngThresALCAMin_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneCancelBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u16_NoUnit_0_65535_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 65535 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneSafetyBitmask_btm \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_255_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 255 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneWidthALCAHyst_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneWidthALCAMax_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneWidthALCAMin_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_LaneWidthSIFOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		If the switch is on, the Coupled/Uncoupled Lane Width will be taking into account and checked to trigger or cancel an intervention. If not, it will be ignored. \n\n
 *		@ref P_LCRSIA_LaneWidthWideLnDef_met \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_m_0_10_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m \n
 *		\@min: 0 \n
 *		\@max: 10 \n
 *		\@description: \n
 *		New calculated Lane Width Default value. Used if there is only one lane marking or if the lane width is too big. \n\n
 *		@ref P_LCRSIA_LaneWidthWideLn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		New Lane Width too big logic switch. If on, lanes too wide will be considerd valid and a default lane width will be used. \n\n
 *		@ref P_LCRSIA_LnBndTurnOnTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Turn on delay time for the lane marking validity flags. \n\n
 *		@ref P_LCRSIA_SafetyIfaceALCAOn_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_SpecificDebTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		Vector containing the turn off debounce times of the ALCA Specific Qualifier. \n\n
 *		@ref P_LCRSIA_StrWhlAngSpeedALCAHyst_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_StrWhlAngSpeedALCAMax_degps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_degps_m360_360_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: °/s \n
 *		\@min: -360 \n
 *		\@max: 360 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_StrWhlAngleALCAHyst_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_StrWhlAngleALCAMax_deg \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_deg_m720_720_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: ° \n
 *		\@min: -720 \n
 *		\@max: 720 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_TlcHeadAngThres_rad \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_rad_m0p78539816_0p78539816_1em8_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: rad \n
 *		\@min: -0.78539816 \n
 *		\@max: 0.78539816 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_TurnSignHoldingTime_sec \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_s_0_60_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: s \n
 *		\@min: 0 \n
 *		\@max: 60 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_TurnSignReset_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_UncoupledLWEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_VelDispALCAHyst_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_VelDispALCAMax_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_VelDispALCAMin_kph \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_kph_0_300_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: km/h \n
 *		\@min: 0 \n
 *		\@max: 300 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_VelLatThresALCAHyst_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_VelLatThresALCAMax_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSIA_VelLatThresALCAMin_mps \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_mps_m20_20_1em3_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: m/s \n
 *		\@min: -20 \n
 *		\@max: 20 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSMI_ALCASwitchEnable_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
 *		@ref P_LCRSMI_ALCASwitch_bool \n
 *		\@kind: Parameter \n
 *		\@type: @ref u8_NoUnit_0_1_0_1_t \n
 *		\@size: 1x1x1 \n
 *		\@unit: - \n
 *		\@min: 0 \n
 *		\@max: 1 \n
 *		\@description: \n
 *		UNDEFINED \n\n
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
 *		@ref Y_LCRSIA_VXCrvThresALCAHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the lane marking curvature validation. Speed Dependant. \n\n
 *		@ref Y_LCRSIA_VXCrvThresALCAMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximal value of the lane marking curvature validation for the ALCA. \n\n
 *		@ref Y_LCRSIA_VXVehCrvThresHyst_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Hysteresis of the vehicle curvature validation for the ALCA. \n\n
 *		@ref Y_LCRSIA_VXVehCrvThresMax_1pm \n
 *		\@kind: Parameter \n
 *		\@type: @ref f32_1pm_m0p15_0p15_1em8_t \n
 *		\@size: 1x8x1 \n
 *		\@unit: 1/m \n
 *		\@min: -0.15 \n
 *		\@max: 0.15 \n
 *		\@description: \n
 *		Maximum value of the vehicle curvature validation for the ALCA. \n\n
 *		
 *	@InOutCorrelation
 *		[\@link: LCRSIA Module Software Detailed Design]()
 *		
 *	@callsequence
 *		
 *	@testmethod
 *		
 *	@traceability
 *		[\@link: LCRSIA Module Requirements]()
 */
extern void LCRSIA_SenProcess(void);

#ifdef __cplusplus
}
#endif

#endif // LCRSIA_H_
