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
//! @file     LCRSIA_type.h
//! @brief     (LCRSIA) Module Type Header.

#ifndef LCRSIA_TYPE_H_
#define LCRSIA_TYPE_H_

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

/*! LCRSIA module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m15_15_1em3_t S_LCRSIA_DlcLeALCA_met; /*!< @description
	*	Distance to cross the left lane marking for the ALCA. \n\n
	*	\@asap_name: S_LCRSIA_DlcLeALCA_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_m_m15_15_1em3_t S_LCRSIA_DlcRiALCA_met; /*!< @description
	*	Distance to cross the right lane marking for the ALCA. \n\n
	*	\@asap_name: S_LCRSIA_DlcRiALCA_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -15 \n
	*	\@max: 15
	*/
	
	f32_mps_m20_20_1em3_t S_LCRSIA_VelLatLeALCA_mps; /*!< @description
	*	Lateral velocity towards the left lane marking for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_VelLatLeALCA_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_LCRSIA_VelLatRiALCA_mps; /*!< @description
	*	Lateral velocity towards the right lane marking for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_VelLatRiALCA_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_60_1em3_t S_LCRSIA_TlcLeALCA_sec; /*!< @description
	*	Time to cross the left lane marking for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_TlcLeALCA_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	f32_s_0_60_1em3_t S_LCRSIA_TlcRiALCA_sec; /*!< @description
	*	Time to cross the right lane marking for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_TlcRiALCA_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	E_HMORQG_BndValidType_t S_LCRSIA_LnBndValidALCA_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_LCRSIA_LnBndValidALCA_nu \n
	*	\@values: E_HMORQG_BndValidType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 3
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSIA_LnBndLeCancelValidALCA_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSIA_LnBndLeCancelValidALCA_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSIA_LnBndLeTrgValidALCA_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSIA_LnBndLeTrgValidALCA_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSIA_LnBndRiCancelValidALCA_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSIA_LnBndRiCancelValidALCA_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_LCRSIA_LnBndRiTrgValidALCA_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_LCRSIA_LnBndRiTrgValidALCA_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_LCRSIA_LnBndLeValidALCA_bool; /*!< @description
	*	Validity of the left lane marking for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_LnBndLeValidALCA_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_LCRSIA_LnBndRiValidALCA_bool; /*!< @description
	*	Validity of the right lane marking for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_LnBndRiValidALCA_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_LCRSIA_SideCondALCALe_btf; /*!< @description
	*	Bitfield with the left side conditions for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_SideCondALCALe_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_LCRSIA_SideCondALCARi_btf; /*!< @description
	*	Bitfield with the right side conditions for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_SideCondALCARi_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_LCRSIA_SpecificALCA_btf; /*!< @description
	*	Bitfield with the specific conditions for the ALCA \n\n
	*	\@asap_name: S_LCRSIA_SpecificALCA_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} LCRSIA_SenDbgType; /*!< @description LCRSIA module sensor debug data structure for MTS measurement. */

/*! LCRSIA module sensor output data structure. */
typedef struct
{
	
	f32_m_0_10_1em3_t S_LCRSIA_LaneWidth_met; /*!< @description
	*	New calculated Lane Width used across ALCA. It takes into account if there is only one lane marking or if the lane width is too big. \n\n
	*	\@asap_name: S_LCRSIA_LaneWidth_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	E_LCF_CurveType_t S_LCRSIA_CurveTypeLe_enum; /*!< @description
	*	Signal that indicates if the left lane marking is part of an inner curve, an outer curve or a straight. \n\n
	*	\@asap_name: S_LCRSIA_CurveTypeLe_enum \n
	*	\@values: E_LCF_CurveType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	E_LCF_CurveType_t S_LCRSIA_CurveTypeRi_enum; /*!< @description
	*	Signal that indicates if the right lane marking is part of an inner curve, an outer curve or a straight. \n\n
	*	\@asap_name: S_LCRSIA_CurveTypeRi_enum \n
	*	\@values: E_LCF_CurveType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 2
	*/
	
	u8_NoUnit_0_1_0_1_t S_LCRSIA_TgtCntrLnEnable_bool; /*!< @description
	*	Signal that enables the target in the center of the lane. Both lane markings and the lane width have to be valid. \n\n
	*	\@asap_name: S_LCRSIA_TgtCntrLnEnable_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} LCRSIA_SenOutType; /*!< @description LCRSIA module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // LCRSIA_TYPE_H_
