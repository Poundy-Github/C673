/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTEST
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTEST_type.h
//! @brief     (TCTEST) Module Type Header.

#ifndef TCTEST_TYPE_H_
#define TCTEST_TYPE_H_

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

/*! TCTEST module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTEST_InPlObsCurvature_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_InPlObsCurvature_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t D_TCTEST_KObsKappa_1pm; /*!< @description
	*	Estimated curvature, debug signal in front of the enable / freeze blocks \n\n
	*	\@asap_name: D_TCTEST_KObsKappa_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p15_0p15_1em8_t S_TCTEST_KObsKappa_1pm; /*!< @description
	*	Estimated Curvature \n\n
	*	\@asap_name: S_TCTEST_KObsKappa_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_N_m100000_100000_1em8_t D_TCTEST_CrObsCrosswindRaw_New; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_CrObsCrosswindRaw_New \n
	*	\@type: value \n
	*	\@unit: N \n
	*	\@min: -100000 \n
	*	\@max: 100000
	*/
	
	f32_N_m100000_100000_1em8_t S_TCTEST_CrObsCrosswind_New; /*!< @description
	*	Estimated Crosswind / Newton \n\n
	*	\@asap_name: S_TCTEST_CrObsCrosswind_New \n
	*	\@type: value \n
	*	\@unit: N \n
	*	\@min: -100000 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccA11_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccA11_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccA12_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccA12_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccA21_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccA21_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccA22_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccA22_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccB11_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccB11_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccB21_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccB21_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccH11Cw_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccH11Cw_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TCTEST_MccH21Cw_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_MccH21Cw_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_Perc_0_100_1em3_t D_TCTEST_HdrMean_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_HdrMean_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_Perc_0_100_1em3_t D_TCTEST_HdrMul_perc; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_HdrMul_perc \n
	*	\@type: value \n
	*	\@unit: % \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_m_m10_10_1em3_t D_TCTEST_InPlObsDeltaY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_InPlObsDeltaY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t D_TCTEST_PlObsDeltaY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_PlObsDeltaY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_m_m10_10_1em3_t S_TCTEST_PlObsDeltaY_met; /*!< @description
	*	Estimated DeltaY of PlantObserver \n\n
	*	\@asap_name: S_TCTEST_PlObsDeltaY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t D_TCTEST_SteerAngleLaDMC_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_SteerAngleLaDMC_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t D_TCTEST_SteerAngleVDY_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_SteerAngleVDY_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m0p78539816_0p78539816_1em8_t S_TCTEST_CurSteerAngle_rad; /*!< @description
	*	Current steer angle of the front wheels \n\n
	*	\@asap_name: S_TCTEST_CurSteerAngle_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.78539816 \n
	*	\@max: 0.78539816
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTEST_PlObsDeltaTheta_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_PlObsDeltaTheta_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t D_TCTEST_SObsBeta_rad; /*!< @description
	*	Estimated Side Slip Angle of Side Slip Angle observer without saturations \n\n
	*	\@asap_name: D_TCTEST_SObsBeta_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t S_TCTEST_PlObsDeltaTheta_rad; /*!< @description
	*	Estimated DeltaTheta of PlantObserver \n\n
	*	\@asap_name: S_TCTEST_PlObsDeltaTheta_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_rad_m6p28_6p28_1em4_t S_TCTEST_SObsBeta_rad; /*!< @description
	*	Estimated Side Slip Angle of SideSlip Angle Observer \n\n
	*	\@asap_name: S_TCTEST_SObsBeta_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6.28 \n
	*	\@max: 6.28
	*/
	
	f32_radps_m1p5708_1p5708_1em3_t D_TCTEST_SObsPsiDot_rps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_SObsPsiDot_rps \n
	*	\@type: value \n
	*	\@unit: rad/s \n
	*	\@min: -1.5708 \n
	*	\@max: 1.5708
	*/
	
	u32_NoUnit_0_4294967295_0_1_t S_TCTEST_QualifierService_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TCTEST_QualifierService_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 4294967295
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTEST_HdrMean_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_HdrMean_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TCTEST_HdrMul_bool; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TCTEST_HdrMul_bool \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TCTEST_VehDbgType; /*!< @description TCTEST module vehicle debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // TCTEST_TYPE_H_
