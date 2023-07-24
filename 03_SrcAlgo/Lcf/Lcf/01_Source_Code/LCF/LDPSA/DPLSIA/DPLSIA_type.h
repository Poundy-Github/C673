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
//! @file     DPLSIA_type.h
//! @brief     (DPLSIA) Module Type Header.

#ifndef DPLSIA_TYPE_H_
#define DPLSIA_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! DPLSIA module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_0_10_1em3_t S_DPLSIA_LaneWidthLDP_met; /*!< @description
	*	New calculated Lane Width used across LDP. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: S_DPLSIA_LaneWidthLDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_DPLSIA_LaneWidthLDW_met; /*!< @description
	*	New calculated Lane Width used across LDW. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: S_DPLSIA_LaneWidthLDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_m15_15_1em3_t S_DPLSIA_DlcLeLDP_met; /*!< @description
	*	Distance to cross the left lane marking for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_DlcLeLDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPLSIA_DlcLeLDW_met; /*!< @description
	*	Distance to cross the left lane marking for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_DlcLeLDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPLSIA_DlcRiLDP_met; /*!< @description
	*	Distance to cross the right lane marking for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_DlcRiLDP_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_DPLSIA_DlcRiLDW_met; /*!< @description
	*	Distance to cross the right lane marking for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_DlcRiLDW_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_mps_m20_20_1em3_t S_DPLSIA_VelLatLeLDP_mps; /*!< @description
	*	Lateral velocity towards the left lane marking for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_VelLatLeLDP_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPLSIA_VelLatLeLDW_mps; /*!< @description
	*	Lateral velocity towards the left lane marking for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_VelLatLeLDW_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPLSIA_VelLatRiLDP_mps; /*!< @description
	*	Lateral velocity towards the right lane marking for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_VelLatRiLDP_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_DPLSIA_VelLatRiLDW_mps; /*!< @description
	*	Lateral velocity towards the right lane marking for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_VelLatRiLDW_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t S_DPLSIA_TlcLeLDP_sec; /*!< @description
	*	Time to cross the left lane marking for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_TlcLeLDP_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPLSIA_TlcLeLDW_sec; /*!< @description
	*	Time to cross the left lane marking for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_TlcLeLDW_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPLSIA_TlcRiLDP_sec; /*!< @description
	*	Time to cross the right lane marking for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_TlcRiLDP_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_DPLSIA_TlcRiLDW_sec; /*!< @description
	*	Time to cross the right lane marking for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_TlcRiLDW_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_HMORQG_BndValidType_t S_DPLSIA_LnBndValidLDP_nu; /*!< @description
	*	 \n\n
	*	\@asap_name: S_DPLSIA_LnBndValidLDP_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	E_HMORQG_BndValidType_t S_DPLSIA_LnBndValidLDW_nu; /*!< @description
	*	Validity of the lane markings for the LDW function. \n\n
	*	\@asap_name: S_DPLSIA_LnBndValidLDW_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	E_LCF_CurveType_t S_DPLSIA_CurveTypeLe_enum; /*!< @description
	*	Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
	*	\@asap_name: S_DPLSIA_CurveTypeLe_enum \n
	*	\@values: E_LCF_CurveType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	E_LCF_CurveType_t S_DPLSIA_CurveTypeRi_enum; /*!< @description
	*	Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
	*	\@asap_name: S_DPLSIA_CurveTypeRi_enum \n
	*	\@values: E_LCF_CurveType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndLeCancelValidLDP_bool; /*!< @description
	*	Validity of the left lane marking for the LDP in order to cancel. \n\n
	*	\@asap_name: D_DPLSIA_LnBndLeCancelValidLDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndLeCancelValidLDW_bool; /*!< @description
	*	Validity of the left lane marking for the LDW in order to cancel. \n\n
	*	\@asap_name: D_DPLSIA_LnBndLeCancelValidLDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndLeTrgValidLDP_bool; /*!< @description
	*	Validity of the left lane marking for the LDP in order to trigger. \n\n
	*	\@asap_name: D_DPLSIA_LnBndLeTrgValidLDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndLeTrgValidLDW_bool; /*!< @description
	*	Validity of the left lane marking for the LDW in order to trigger. \n\n
	*	\@asap_name: D_DPLSIA_LnBndLeTrgValidLDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndRiCancelValidLDP_bool; /*!< @description
	*	Validity of the right lane marking for the LDP in order to cancel. \n\n
	*	\@asap_name: D_DPLSIA_LnBndRiCancelValidLDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndRiCancelValidLDW_bool; /*!< @description
	*	Validity of the right lane marking for the LDW in order to cancel. \n\n
	*	\@asap_name: D_DPLSIA_LnBndRiCancelValidLDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndRiTrgValidLDP_bool; /*!< @description
	*	Validity of the right lane marking for the LDP in order to trigger. \n\n
	*	\@asap_name: D_DPLSIA_LnBndRiTrgValidLDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_DPLSIA_LnBndRiTrgValidLDW_bool; /*!< @description
	*	Validity of the right lane marking for the LDW in order to trigger. \n\n
	*	\@asap_name: D_DPLSIA_LnBndRiTrgValidLDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSIA_LnBndLeValidLDP_bool; /*!< @description
	*	Validity of the left lane marking for the LDP and LDW functions. \n\n
	*	\@asap_name: S_DPLSIA_LnBndLeValidLDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSIA_LnBndLeValidLDW_bool; /*!< @description
	*	Validity of the left lane marking for the LDW function. \n\n
	*	\@asap_name: S_DPLSIA_LnBndLeValidLDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSIA_LnBndRiValidLDP_bool; /*!< @description
	*	Validity of the right lane marking for the LDP and LDW functions. \n\n
	*	\@asap_name: S_DPLSIA_LnBndRiValidLDP_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSIA_LnBndRiValidLDW_bool; /*!< @description
	*	Validity of the right lane marking for the LDW function. \n\n
	*	\@asap_name: S_DPLSIA_LnBndRiValidLDW_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_DPLSIA_TgtCntrLnEnable_bool; /*!< @description
	*	Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
	*	\@asap_name: S_DPLSIA_TgtCntrLnEnable_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLSIA_SideCondLDPLe_btf; /*!< @description
	*	Bitfield with the left side conditions for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_SideCondLDPLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLSIA_SideCondLDPRi_btf; /*!< @description
	*	Bitfield with the right side conditions for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_SideCondLDPRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLSIA_SideCondLDWLe_btf; /*!< @description
	*	Bitfield with the left side conditions for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_SideCondLDWLe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLSIA_SideCondLDWRi_btf; /*!< @description
	*	Bitfield with the right side conditions for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_SideCondLDWRi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLSIA_SpecificLDP_btf; /*!< @description
	*	Bitfield with the specific conditions for the LDP. \n\n
	*	\@asap_name: S_DPLSIA_SpecificLDP_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_DPLSIA_SpecificLDW_btf; /*!< @description
	*	Bitfield with the specific conditions for the LDW. \n\n
	*	\@asap_name: S_DPLSIA_SpecificLDW_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} DPLSIA_SenDbgType; /*!< @description DPLSIA module sensor debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // DPLSIA_TYPE_H_
