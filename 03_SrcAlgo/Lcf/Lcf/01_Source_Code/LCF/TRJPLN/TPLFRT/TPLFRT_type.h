/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFRT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLFRT_type.h
//! @brief     (TPLFRT) Module Type Header.

#ifndef TPLFRT_TYPE_H_
#define TPLFRT_TYPE_H_

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

/*! TPLFRT module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_NoUnit_m100_100_1em3_t S_TPLFRT_TgtPoints_nu[15]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TgtPoints_nu \n
	*	\@type: curve \n
	*	\@unit: - \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_0_10_1em3_t S_TPLFRT_CurDistYPreview_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_CurDistYPreview_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_TPLFRT_CurDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_CurDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_TPLFRT_TgtDistY_met[15]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TgtDistY_met \n
	*	\@type: curve \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_m_0_10_1em3_t S_TPLFRT_TrajDistYPrev_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TrajDistYPrev_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLFRT_CurDistY2ndDeriv_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_CurDistY2ndDeriv_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLFRT_DistY2ndToDevHead_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_DistY2ndToDevHead_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLFRT_TgtDistY2ndDeriv_mps2[15]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TgtDistY2ndDeriv_mps2 \n
	*	\@type: curve \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLFRT_TrajAclRefCurve_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TrajAclRefCurve_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLFRT_TrajDistY2ndToPrev_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TrajDistY2ndToPrev_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLFRT_CurDistY1stDeriv_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_CurDistY1stDeriv_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLFRT_CurDistY1stToPrev_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_CurDistY1stToPrev_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLFRT_DistY1stToDevHead_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_DistY1stToDevHead_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLFRT_TgtDistY1stDeriv_mps[15]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TgtDistY1stDeriv_mps \n
	*	\@type: curve \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLFRT_TrajDistY1stToPrev_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TrajDistY1stToPrev_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLFRT_TrajVelRefCurve_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TrajVelRefCurve_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_s_0_300_1em3_t S_TPLFRT_PlanHorizonVisRange_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_PlanHorizonVisRange_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_300_1em3_t S_TPLFRT_PreviewTimeHeading_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_PreviewTimeHeading_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 300
	*/
	
	f32_s_0_60_1em3_t S_TPLFRT_TrajPlanningHorizon_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_TrajPlanningHorizon_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	u8_NoUnit_0_255_0_1_t S_TPLFRT_NumPointsCridrLeft_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_NumPointsCridrLeft_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_TPLFRT_NumTgtPoints_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_NumTgtPoints_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TPLFRT_VehDbgType; /*!< @description TPLFRT module vehicle debug data structure for MTS measurement. */

/*! TPLFRT module vehicle output data structure. */
typedef struct
{
	
	f32_m_0_10_1em3_t S_TPLFRT_LeftDistY_met[100]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFRT_LeftDistY_met \n
	*	\@type: curve \n
	*	\@unit: m \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
} TPLFRT_VehOutType; /*!< @description TPLFRT module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TPLFRT_TYPE_H_
