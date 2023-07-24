/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLCEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLCEN_type.h
//! @brief     (TPLCEN) Module Type Header.

#ifndef TPLCEN_TYPE_H_
#define TPLCEN_TYPE_H_

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

/*! TPLCEN module vehicle debug data structure for MTS measurement. */
typedef struct
{
	
	f32_s_0_1_1em3_t S_TPLCEN_PredictionTimeCrv_sec; /*!< @description
	*	Prediction time of the curvature, saterated, ramped up \n\n
	*	\@asap_name: S_TPLCEN_PredictionTimeCrv_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_0_1_1em3_t S_TPLCEN_PredictionTimeHead_sec; /*!< @description
	*	Prediction time of the heading, saturated, ramped up \n\n
	*	\@asap_name: S_TPLCEN_PredictionTimeHead_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	f32_s_0_60_1em3_t S_TPLCEN_DelayVehGui_sec; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_DelayVehGui_sec \n
	*	\@type: value \n
	*	\@unit: s \n
	*	\@min: 0 \n
	*	\@max: 60
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLCEN_CorridorJumpDetected_nu; /*!< @description
	*	Boolean indicates if there is jump in corridor info. \n\n
	*	\@asap_name: D_TPLCEN_CorridorJumpDetected_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLCEN_LatDMCReqFinished_nu; /*!< @description
	*	Indicates if DMC and EPS handshake is finished \n\n
	*	\@asap_name: D_TPLCEN_LatDMCReqFinished_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t D_TPLCEN_TrigLargeDeviation_nu; /*!< @description
	*	Trigger indicates if the deviation is too large \n\n
	*	\@asap_name: D_TPLCEN_TrigLargeDeviation_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_EnblSpecPlanStrategy_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_EnblSpecPlanStrategy_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_ReplanCurValues_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_ReplanCurValues_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_ReplanModeArcLength_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_ReplanModeArcLength_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_ReplanTgtValues_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_ReplanTgtValues_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_TrajGuiQuChange_nu; /*!< @description
	*	Signal indicates the trajectory guidance qualifier change \n\n
	*	\@asap_name: S_TPLCEN_TrajGuiQuChange_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_TrajPlanEnbl_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_TrajPlanEnbl_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_TrigCustFctActn_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_TrigCustFctActn_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_TrigReplanTgtTraj_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_TrigReplanTgtTraj_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_1_0_1_t S_TPLCEN_TrigTrajReplan_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: S_TPLCEN_TrigTrajReplan_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TPLCEN_VehDbgType; /*!< @description TPLCEN module vehicle debug data structure for MTS measurement. */

/*! TPLCEN module vehicle output data structure. */
typedef struct
{
	
	u8_NoUnit_0_1_0_1_t D_TPLCEN_TrigCustFctChange_nu; /*!< @description
	*	UNDEFINED \n\n
	*	\@asap_name: D_TPLCEN_TrigCustFctChange_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
} TPLCEN_VehOutType; /*!< @description TPLCEN module vehicle output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TPLCEN_TYPE_H_
