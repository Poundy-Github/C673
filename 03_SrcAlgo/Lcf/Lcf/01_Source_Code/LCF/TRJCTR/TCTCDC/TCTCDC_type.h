/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCDC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTCDC_type.h
//! @brief     (TCTCDC) Module Type Header.

#ifndef TCTCDC_TYPE_H_
#define TCTCDC_TYPE_H_

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

/*! TCTCDC module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_m_m100_100_1em3_t S_TCTCDC_CtrlErrDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTCDC_CtrlErrDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m10_10_1em3_t D_TCTCDC_DeltaYPT1_met; /*!< @description
	*	Lateral Deviation, PT1 filtered \n\n
	*	\@asap_name: D_TCTCDC_DeltaYPT1_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t D_TCTCDC_DeltaYRaw_met; /*!< @description
	*	Lateral Deviation \n\n
	*	\@asap_name: D_TCTCDC_DeltaYRaw_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m6_6_1em3_t S_TCTCDC_CtrlErrHeadAglPrev_rad; /*!< @description
	*	 \n\n
	*	\@asap_name: S_TCTCDC_CtrlErrHeadAglPrev_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TCTCDC_CtrlErrHeadAgl_rad; /*!< @description
	*	 \n\n
	*	\@asap_name: S_TCTCDC_CtrlErrHeadAgl_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTCDC_DeltaThetaEsti_rad; /*!< @description
	*	Course Angle Deviation calculated by means of "HAF estimator" \n\n
	*	\@asap_name: D_TCTCDC_DeltaThetaEsti_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTCDC_DeltaThetaPT1_rad; /*!< @description
	*	PT1 filtered Course Angle Deviation \n\n
	*	\@asap_name: D_TCTCDC_DeltaThetaPT1_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTCDC_DeltaThetaRaw_rad; /*!< @description
	*	Course Angle Deviation \n\n
	*	\@asap_name: D_TCTCDC_DeltaThetaRaw_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTCDC_WatchdogStatus_nu; /*!< @description
	*	0: Watchdog inactive \n
	*	1: Watchdog active \n\n
	*	\@asap_name: D_TCTCDC_WatchdogStatus_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t D_TCTCDC_QualifierService_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTCDC_QualifierService_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_TCTCDC_QualifierService_nu; /*!< @description
	*	Qualifier signal of TCTCDC: \n
	*	xxxx xxx1: Too high deviation in the control error regarding the Y-Coordinate \n
	*	xxxx xx1x: Too high deviation in the control error regarding the Course Angle \n
	*	xxxx x1xx: Too high deviation in the control error regarding the Course Angle with Preview \n\n
	*	\@asap_name: S_TCTCDC_QualifierService_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} TCTCDC_VehDbgType; /*!< @description TCTCDC module vehicle debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // TCTCDC_TYPE_H_
