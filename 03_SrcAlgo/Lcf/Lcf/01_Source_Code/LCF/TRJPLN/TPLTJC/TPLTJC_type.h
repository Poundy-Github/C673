/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLTJC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLTJC_type.h
//! @brief     (TPLTJC) Module Type Header.

#ifndef TPLTJC_TYPE_H_
#define TPLTJC_TYPE_H_

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

/*! TPLTJC module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_NoUnit_0_100000_1em3_t D_TPLTJC_OptimalCost_nu; /*!< @description
	*	Cost of the optimal trajectory \n\n
	*	\@asap_name: D_TPLTJC_OptimalCost_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100000
	*/
	
	f32_NoUnit_0_100_1em3_t D_TPLTJC_WeightEndTime_nu; /*!< @description
	*	used weight end time by planning \n\n
	*	\@asap_name: D_TPLTJC_WeightEndTime_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t D_TPLTJC_WeightTgtDistY_nu; /*!< @description
	*	used weight target disty by planning \n\n
	*	\@asap_name: D_TPLTJC_WeightTgtDistY_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_100_1em3_t S_TPLTJC_EndPointTrajectory_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_EndPointTrajectory_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 100
	*/
	
	f32_NoUnit_0_1_1em6_t D_TPLTJC_PassedTrajLenPercent_nu; /*!< @description
	*	percentage of the passed trajectory length \n\n
	*	\@asap_name: D_TPLTJC_PassedTrajLenPercent_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_NoUnit_m10000000_10000000_1em9_t S_TPLTJC_TrajParam_nu[6]; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajParam_nu \n
	*	\@type: curve \n
	*	\@unit: - \n
	*	\@min: -10000000 \n
	*	\@max: 10000000
	*/
	
	f32_m_m100_100_1em3_t S_TPLTJC_TrajDistYFmPrev_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajDistYFmPrev_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_m_m100_100_1em3_t S_TPLTJC_TrajDistY_met; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajDistY_met \n
	*	\@type: value \n
	*	\@unit: m \n
	*	\@min: -100 \n
	*	\@max: 100
	*/
	
	f32_mps2_m20_20_1em3_t D_TPLTJC_MaxAclTraj_mps2; /*!< @description
	*	Max. lateral acceleration of the planned trajectory. \n\n
	*	\@asap_name: D_TPLTJC_MaxAclTraj_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLTJC_TrajDistY2ndDeriv_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajDistY2ndDeriv_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLTJC_YDt2TrjFmKpPrevDT_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_YDt2TrjFmKpPrevDT_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps2_m20_20_1em3_t S_TPLTJC_YDt2TrjFmKpPrev_mps2; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_YDt2TrjFmKpPrev_mps2 \n
	*	\@type: value \n
	*	\@unit: m/s^2 \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps3_m10_10_1em3_t D_TPLTJC_MaxJerkTraj_mps3; /*!< @description
	*	Max jerk of the planned trajectory \n\n
	*	\@asap_name: D_TPLTJC_MaxJerkTraj_mps3 \n
	*	\@type: value \n
	*	\@unit: m/s^3 \n
	*	\@min: -10 \n
	*	\@max: 10
	*/
	
	f32_mps3_m1_1_1em3_t S_TPLTJC_TrajDistY3rdDeriv_mps3; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajDistY3rdDeriv_mps3 \n
	*	\@type: value \n
	*	\@unit: m/s^3 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_mps3_m1_1_1em3_t S_TPLTJC_YDt3TrjFmKpPrevDT_mps3; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_YDt3TrjFmKpPrevDT_mps3 \n
	*	\@type: value \n
	*	\@unit: m/s^3 \n
	*	\@min: -1 \n
	*	\@max: 1
	*/
	
	f32_mps_m20_20_1em3_t S_TPLTJC_TrajDistY1stDeriv_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajDistY1stDeriv_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	f32_mps_m20_20_1em3_t S_TPLTJC_YDtTrjFmHeadPrev_mps; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_YDtTrjFmHeadPrev_mps \n
	*	\@type: value \n
	*	\@unit: m/s \n
	*	\@min: -20 \n
	*	\@max: 20
	*/
	
	u16_NoUnit_0_65535_0_1_t S_TPLTJC_QuStatusTrajPlan_nu; /*!< @description
	*	Bitfield indicates the planner status: 1: NOT OK 0: OK \n
	*	0 bit: min acceleration check \n
	*	1 bit: max acceleration check \n
	*	2 bit: right corridor boundary collision check \n
	*	3 bit: left corridor boundary collision check \n
	*	4 bit: object collision check \n
	*	5 bit: matrix invertible  \n
	*	6 bit: trajectory length \n
	*	7 bit: max jerk check \n
	*	8 bit: physical max curvature \n\n
	*	\@asap_name: S_TPLTJC_QuStatusTrajPlan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLTJC_MaxJerkOK_nu; /*!< @description
	*	Max jerk check result \n\n
	*	\@asap_name: D_TPLTJC_MaxJerkOK_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLTJC_LengthOK_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_LengthOK_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLTJC_MatrixInverseOK_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_MatrixInverseOK_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLTJC_TrajEnd_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLTJC_TrajEnd_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TPLTJC_VehDbgType; /*!< @description TPLTJC module vehicle debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // TPLTJC_TYPE_H_
