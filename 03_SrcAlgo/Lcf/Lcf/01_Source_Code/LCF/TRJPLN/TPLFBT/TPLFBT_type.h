/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLFBT
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLFBT_type.h
//! @brief     (TPLFBT) Module Type Header.

#ifndef TPLFBT_TYPE_H_
#define TPLFBT_TYPE_H_

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

/*! TPLFBT module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_1pm_m0p15_0p15_1em8_t D_TPLFBT_DeltaTargetCrv_1pm; /*!< @description
	*	Difference between planned trajectory curvature and target corridor curvature \n\n
	*	\@asap_name: D_TPLFBT_DeltaTargetCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.15 \n
	*	\@max: 0.15
	*/
	
	f32_1pm_m0p1_0p1_1em3_t S_TPLFBT_TrajTgtCrv_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_TrajTgtCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m1_1_1em3_t S_TPLFBT_TrajTgtCrvPrev_1pm; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_TrajTgtCrvPrev_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_m_m100_100_1em3_t S_TPLFBT_CtrlErrDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_CtrlErrDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t S_TPLFBT_CurDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_CurDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t S_TPLFBT_TrajDistYPrev_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_TrajDistYPrev_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t S_TPLFBT_TrajDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_TrajDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m10_10_1em3_t D_TPLFBT_DeltaTargetPosY0_met; /*!< @description
	*	difference between planned trajectory lateral distance and target corridor lateral distance \n\n
	*	\@asap_name: D_TPLFBT_DeltaTargetPosY0_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_rad_m6_6_1em3_t D_TPLFBT_DeltaTargetHeading_rad; /*!< @description
	*	Difference between planned trajectory heading and target corridor heading \n\n
	*	\@asap_name: D_TPLFBT_DeltaTargetHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TPLFBT_CtrlErrHeadAglPrev_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_CtrlErrHeadAglPrev_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TPLFBT_CtrlErrHeadingAngle_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_CtrlErrHeadingAngle_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TPLFBT_CurHeading_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_CurHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TPLFBT_TrajHeadInclPrev_rad; /*!< @description
	*	 \n\n
	*	\@asap_name: S_TPLFBT_TrajHeadInclPrev_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TPLFBT_TrajHeadingPrev_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_TrajHeadingPrev_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	f32_rad_m6_6_1em3_t S_TPLFBT_TrajHeading_rad; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLFBT_TrajHeading_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -6 \n
	*	\@max: 6
	*/
	
	u16_NoUnit_0_65535_0_1_t D_TPLFBT_QuStatusTrajPlan_nu; /*!< @description
	*	Notes for D_TPLTJC_QuStatusTrajPlan_nu: \n
	*	Bitfield indicates the status of trajectory planner: 1 Not OK, 0 OK \n
	*	0 bit: min acceleration check  \n
	*	1 bit: max acceleration check  \n
	*	2 bit: right corridor boundary collision check  \n
	*	3 bit: left corridor boundary collision check  \n
	*	4 bit: object collision check  \n
	*	5 bit: matrix invertible   \n
	*	6 bit: trajectory length  \n
	*	7 bit: max jerk check  \n
	*	8 bit: lane cross check  \n
	*	9 bit: target lateral distance  \n
	*	10 bit: vehicle lateral distance  \n
	*	11 bit: right corridor transformation  \n
	*	12 bit: target corridor transformation  \n
	*	13 bit: left corridor transformation  \n
	*	14 bit: input target corridor heading \n\n
	*	\@asap_name: D_TPLFBT_QuStatusTrajPlan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u16_NoUnit_0_65535_0_1_t S_TPLFBT_QuStatusTrajPlan_nu; /*!< @description
	*	Notes for S_TPLTJC_QuStatusTrajPlan_nu: \n
	*	Bitfield indicates the status of trajectory planner: 1 Not OK, 0 OK \n
	*	0 bit: min acceleration check  \n
	*	1 bit: max acceleration check  \n
	*	2 bit: right corridor boundary collision check  \n
	*	3 bit: left corridor boundary collision check  \n
	*	4 bit: object collision check  \n
	*	5 bit: matrix invertible   \n
	*	6 bit: trajectory length  \n
	*	7 bit: max jerk check  \n
	*	8 bit: lane cross check  \n
	*	9 bit: target lateral distance  \n
	*	10 bit: vehicle lateral distance  \n
	*	11 bit: right corridor transformation  \n
	*	12 bit: target corridor transformation  \n
	*	13 bit: left corridor transformation  \n
	*	14 bit: input target corridor heading \n\n
	*	\@asap_name: S_TPLFBT_QuStatusTrajPlan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	E_LCF_TGQ_Type_t S_TPLFBT_TrajGuiQualifier_nu; /*!< @description
	*	Trajectory Guidance Qualifier send by TPLFBT \n\n
	*	\@asap_name: S_TPLFBT_TrajGuiQualifier_nu \n
	*	\@values: E_LCF_TGQ_Type \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 5
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLFBT_GradLimitActive_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TPLFBT_GradLimitActive_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLFBT_PlausiCheckStatus_nu; /*!< @description
	*	Indicates if the target disty is plausible. \n\n
	*	\@asap_name: D_TPLFBT_PlausiCheckStatus_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLFBT_TargetSwitch_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TPLFBT_TargetSwitch_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLFBT_UseTargetCorridor_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TPLFBT_UseTargetCorridor_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TPLFBT_VehDbgType; /*!< @description TPLFBT module vehicle debug data structure for MTS measurement. */

/*! TPLFBT module vehicle output data structure. */
typedef struct
{
	
	f32_1pm_m0p1_0p1_1em3_t D_TPLFBT_TgtCorridorCrv_1pm; /*!< @description
	*	Target corridor curvature \n\n
	*	\@asap_name: D_TPLFBT_TgtCorridorCrv_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pm_m0p1_0p1_1em3_t D_TPLFBT_TgtTrjCrvPrvwDT_1pm; /*!< @description
	*	curvature of the target trajectory under consideration of preview and dead time \n\n
	*	\@asap_name: D_TPLFBT_TgtTrjCrvPrvwDT_1pm \n
	*	\@type: value \n
	*	\@unit: 1/m \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_m0p1_0p1_1em8_t D_TPLFBT_TgtCorridorCrvGrd_1pms; /*!< @description
	*	curvature gradient of the target corridor \n\n
	*	\@asap_name: D_TPLFBT_TgtCorridorCrvGrd_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_m0p1_0p1_1em8_t D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms; /*!< @description
	*	curvature gradient of the target trajectory under consideration of preview and dead time \n\n
	*	\@asap_name: D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -0.1 \n
	*	\@max: 0.1
	*/
	
	f32_1pms_m1_1_1em3_t D_TPLFBT_TrajTgtCrvGrdPrev_1pms; /*!< @description
	*	Target trajectory curvature gradient \n\n
	*	\@asap_name: D_TPLFBT_TrajTgtCrvGrdPrev_1pms \n
	*	\@type: value \n
	*	\@unit: 1/ms \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_rad_m0p7854_0p7854_1em3_t D_TPLFBT_TrajHeadingPrvw_rad; /*!< @description
	*	trajectory heading inclusive preview time \n\n
	*	\@asap_name: D_TPLFBT_TrajHeadingPrvw_rad \n
	*	\@type: value \n
	*	\@unit: rad \n
	*	\@min: -0.7854 \n
	*	\@max: 0.7854
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLFBT_TrajPlanInvalid_nu; /*!< @description
	*	1: trajectory planner is invalid \n
	*	0: trajectory planner is valid \n\n
	*	\@asap_name: D_TPLFBT_TrajPlanInvalid_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TPLFBT_VehOutType; /*!< @description TPLFBT module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TPLFBT_TYPE_H_
