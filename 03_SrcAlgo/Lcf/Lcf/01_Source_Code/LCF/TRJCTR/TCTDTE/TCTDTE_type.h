/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTDTE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTDTE_type.h
//! @brief     (TCTDTE) Module Type Header.

#ifndef TCTDTE_TYPE_H_
#define TCTDTE_TYPE_H_

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

/*! TCTDTE module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTDTE_CrvReqBnkAglComp_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTDTE_CrvReqBnkAglComp_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTDTE_CrvReqDistrbStmTf_1pm; /*!< @description
	*	Curvature request of the disturbance compensator based on the single track model \n\n
	*	\@asap_name: D_TCTDTE_CrvReqDistrbStmTf_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTDTE_CrvReqBnkAglComp_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTDTE_CrvReqBnkAglComp_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTDTE_CrvReqDstrbComp_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTDTE_CrvReqDstrbComp_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_NoUnit_0_65535_1em3_t S_TCTDTE_MccGLaDmcDenS0_nu; /*!< @description
	*	s^0 coefficient of the approximated LaDMC transfer function's denominator \n\n
	*	\@asap_name: S_TCTDTE_MccGLaDmcDenS0_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t S_TCTDTE_MccGLaDmcDenS1_nu; /*!< @description
	*	s^1 coefficient of the approximated LaDMC transfer function's denominator \n\n
	*	\@asap_name: S_TCTDTE_MccGLaDmcDenS1_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t S_TCTDTE_MccGLaDmcDenS2_nu; /*!< @description
	*	s^2 coefficient of the approximated LaDMC transfer function's denominator \n\n
	*	\@asap_name: S_TCTDTE_MccGLaDmcDenS2_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t S_TCTDTE_MccGLaDmcDenS3_nu; /*!< @description
	*	s^3 coefficient of the approximated LaDMC transfer function's denominator \n\n
	*	\@asap_name: S_TCTDTE_MccGLaDmcDenS3_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t S_TCTDTE_MccGLaDmcNumS0_nu; /*!< @description
	*	s^0 coefficient of the approximated LaDMC transfer function's numerator \n\n
	*	\@asap_name: S_TCTDTE_MccGLaDmcNumS0_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_NoUnit_0_65535_1em3_t S_TCTDTE_MccGLaDmcNumS1_nu; /*!< @description
	*	s^1 coefficient of the approximated LaDMC transfer function's numerator \n\n
	*	\@asap_name: S_TCTDTE_MccGLaDmcNumS1_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	f32_deg_m50_50_1em8_t D_TCTDTE_DeltaSetCroWiComp_deg; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTDTE_DeltaSetCroWiComp_deg \n
	*	\@type: value \n
	*	\@unit: ° \n
	*	\@min: -50 \n
	*	\@max: 50
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t D_TCTDTE_DeltaSetCroWiComp_rad; /*!< @description
	*	Control signal /rad used to compensate crosswind \n\n
	*	\@asap_name: D_TCTDTE_DeltaSetCroWiComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TCTDTE_DeltaSetCroWiComp_rad; /*!< @description
	*	Control signal /rad used to compensate crosswind \n\n
	*	\@asap_name: S_TCTDTE_DeltaSetCroWiComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTDTE_DeltaSetBnkAglComp_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTDTE_DeltaSetBnkAglComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTDTE_DeltaSetDstrbStmTf_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTDTE_DeltaSetDstrbStmTf_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t S_TCTDTE_DeltaSetBnkAglComp_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTDTE_DeltaSetBnkAglComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t S_TCTDTE_DeltaSetDstrbComp_rad; /*!< @description
	*	Additional steer angle control signal part needed to compensate disturbances \n\n
	*	\@asap_name: S_TCTDTE_DeltaSetDstrbComp_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
} TCTDTE_VehDbgType; /*!< @description TCTDTE module vehicle debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // TCTDTE_TYPE_H_
