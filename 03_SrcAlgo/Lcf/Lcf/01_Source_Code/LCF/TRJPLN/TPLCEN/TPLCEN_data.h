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
//! @file     TPLCEN_data.h
//! @brief     (TPLCEN) Module Data Header.

#ifndef TPLCEN_DATA_H_
#define TPLCEN_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH/LCFVEH_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TPLCEN module vehicle get function. Function gets TPLCEN vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLCEN_VehDbgPtr</b> Global static pointer to TPLCEN vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLCEN_VehDbgType* TPLCEN_VehGetDbgPtr(void);

/*!
 *	TPLCEN module vehicle get function. Function gets TPLCEN vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TPLCEN_VehOutPtr</b> Global static pointer to TPLCEN vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TPLCEN_VehOutType* TPLCEN_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLCEN_CorridorJumpDetected_nu
#define D_TPLCEN_CorridorJumpDetected_nu (TPLCEN_VehGetDbgPtr()->D_TPLCEN_CorridorJumpDetected_nu) //!< TPLCEN debug macro.
#define GET_D_TPLCEN_CorridorJumpDetected_nu() (D_TPLCEN_CorridorJumpDetected_nu) //!< TPLCEN debug macro getter.
#endif // D_TPLCEN_CorridorJumpDetected_nu

#ifndef D_TPLCEN_LatDMCReqFinished_nu
#define D_TPLCEN_LatDMCReqFinished_nu (TPLCEN_VehGetDbgPtr()->D_TPLCEN_LatDMCReqFinished_nu) //!< TPLCEN debug macro.
#define GET_D_TPLCEN_LatDMCReqFinished_nu() (D_TPLCEN_LatDMCReqFinished_nu) //!< TPLCEN debug macro getter.
#endif // D_TPLCEN_LatDMCReqFinished_nu

#ifndef D_TPLCEN_TrigLargeDeviation_nu
#define D_TPLCEN_TrigLargeDeviation_nu (TPLCEN_VehGetDbgPtr()->D_TPLCEN_TrigLargeDeviation_nu) //!< TPLCEN debug macro.
#define GET_D_TPLCEN_TrigLargeDeviation_nu() (D_TPLCEN_TrigLargeDeviation_nu) //!< TPLCEN debug macro getter.
#endif // D_TPLCEN_TrigLargeDeviation_nu

#ifndef S_TPLCEN_DelayVehGui_sec
#define S_TPLCEN_DelayVehGui_sec (TPLCEN_VehGetDbgPtr()->S_TPLCEN_DelayVehGui_sec) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_DelayVehGui_sec() (S_TPLCEN_DelayVehGui_sec) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_DelayVehGui_sec

#ifndef S_TPLCEN_EnblSpecPlanStrategy_nu
#define S_TPLCEN_EnblSpecPlanStrategy_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_EnblSpecPlanStrategy_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_EnblSpecPlanStrategy_nu() (S_TPLCEN_EnblSpecPlanStrategy_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_EnblSpecPlanStrategy_nu

#ifndef S_TPLCEN_PredictionTimeCrv_sec
#define S_TPLCEN_PredictionTimeCrv_sec (TPLCEN_VehGetDbgPtr()->S_TPLCEN_PredictionTimeCrv_sec) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_PredictionTimeCrv_sec() (S_TPLCEN_PredictionTimeCrv_sec) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_PredictionTimeCrv_sec

#ifndef S_TPLCEN_PredictionTimeHead_sec
#define S_TPLCEN_PredictionTimeHead_sec (TPLCEN_VehGetDbgPtr()->S_TPLCEN_PredictionTimeHead_sec) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_PredictionTimeHead_sec() (S_TPLCEN_PredictionTimeHead_sec) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_PredictionTimeHead_sec

#ifndef S_TPLCEN_ReplanCurValues_nu
#define S_TPLCEN_ReplanCurValues_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_ReplanCurValues_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_ReplanCurValues_nu() (S_TPLCEN_ReplanCurValues_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_ReplanCurValues_nu

#ifndef S_TPLCEN_ReplanModeArcLength_nu
#define S_TPLCEN_ReplanModeArcLength_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_ReplanModeArcLength_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_ReplanModeArcLength_nu() (S_TPLCEN_ReplanModeArcLength_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_ReplanModeArcLength_nu

#ifndef S_TPLCEN_ReplanTgtValues_nu
#define S_TPLCEN_ReplanTgtValues_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_ReplanTgtValues_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_ReplanTgtValues_nu() (S_TPLCEN_ReplanTgtValues_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_ReplanTgtValues_nu

#ifndef S_TPLCEN_TrajGuiQuChange_nu
#define S_TPLCEN_TrajGuiQuChange_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_TrajGuiQuChange_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_TrajGuiQuChange_nu() (S_TPLCEN_TrajGuiQuChange_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_TrajGuiQuChange_nu

#ifndef S_TPLCEN_TrajPlanEnbl_nu
#define S_TPLCEN_TrajPlanEnbl_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_TrajPlanEnbl_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_TrajPlanEnbl_nu() (S_TPLCEN_TrajPlanEnbl_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_TrajPlanEnbl_nu

#ifndef S_TPLCEN_TrigCustFctActn_nu
#define S_TPLCEN_TrigCustFctActn_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_TrigCustFctActn_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_TrigCustFctActn_nu() (S_TPLCEN_TrigCustFctActn_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_TrigCustFctActn_nu

#ifndef S_TPLCEN_TrigReplanTgtTraj_nu
#define S_TPLCEN_TrigReplanTgtTraj_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_TrigReplanTgtTraj_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_TrigReplanTgtTraj_nu() (S_TPLCEN_TrigReplanTgtTraj_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_TrigReplanTgtTraj_nu

#ifndef S_TPLCEN_TrigTrajReplan_nu
#define S_TPLCEN_TrigTrajReplan_nu (TPLCEN_VehGetDbgPtr()->S_TPLCEN_TrigTrajReplan_nu) //!< TPLCEN debug macro.
#define GET_S_TPLCEN_TrigTrajReplan_nu() (S_TPLCEN_TrigTrajReplan_nu) //!< TPLCEN debug macro getter.
#endif // S_TPLCEN_TrigTrajReplan_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TPLCEN_TrigCustFctChange_nu
#define D_TPLCEN_TrigCustFctChange_nu (TPLCEN_VehGetOutPtr()->D_TPLCEN_TrigCustFctChange_nu) //!< TPLCEN output macro.
#define GET_D_TPLCEN_TrigCustFctChange_nu() (D_TPLCEN_TrigCustFctChange_nu) //!< TPLCEN output macro getter.
#endif // D_TPLCEN_TrigCustFctChange_nu

#ifdef __cplusplus
}
#endif

#endif // TPLCEN_DATA_H_
