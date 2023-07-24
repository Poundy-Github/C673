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
//! @file     TPLCEN_private.h
//! @brief     (TPLCEN) Module Private Header.

#ifndef TPLCEN_PRIVATE_H_
#define TPLCEN_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJPLN	//!< TRJPLN sub-component input macro switch.
#define TPLCEN	//!< TPLCEN module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLCEN.h"
#include "Bitop.h"  //MFC5J3
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TPLCEN_VehReset		0xF0 //!< TPLCEN module reset runnable identifier.
#define RUNNABLE_ID_TPLCEN_VehProcess	0xF1 //!< TPLCEN module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TPLCEN_VehDbgType *TPLCEN_VehDbgPtr = NULL; //!< TPLCEN module vehicle debug data pointer.
void TPLCEN_VehInitDbgPtr(TPLCEN_VehDbgType *TPLCEN_VehDbgArg) { TPLCEN_VehDbgPtr = TPLCEN_VehDbgPtr == NULL ? TPLCEN_VehDbgArg : TPLCEN_VehDbgPtr; }
const TPLCEN_VehDbgType* TPLCEN_VehGetDbgPtr(void) { return (const TPLCEN_VehDbgType*) TPLCEN_VehDbgPtr; }

static TPLCEN_VehOutType *TPLCEN_VehOutPtr = NULL; //!< TPLCEN module vehicle output data pointer.
void TPLCEN_VehInitOutPtr(TPLCEN_VehOutType *TPLCEN_VehOutArg) { TPLCEN_VehOutPtr = TPLCEN_VehOutPtr == NULL ? TPLCEN_VehOutArg : TPLCEN_VehOutPtr; }
const TPLCEN_VehOutType* TPLCEN_VehGetOutPtr(void) { return (const TPLCEN_VehOutType*) TPLCEN_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLCEN_CorridorJumpDetected_nu
#define	D_TPLCEN_CorridorJumpDetected_nu (TPLCEN_VehDbgPtr->D_TPLCEN_CorridorJumpDetected_nu) //!< TPLCEN debug macro.
#define	SET_D_TPLCEN_CorridorJumpDetected_nu(val)	(D_TPLCEN_CorridorJumpDetected_nu = (val)) //!< TPLCEN debug macro setter.

#undef	D_TPLCEN_LatDMCReqFinished_nu
#define	D_TPLCEN_LatDMCReqFinished_nu (TPLCEN_VehDbgPtr->D_TPLCEN_LatDMCReqFinished_nu) //!< TPLCEN debug macro.
#define	SET_D_TPLCEN_LatDMCReqFinished_nu(val)	(D_TPLCEN_LatDMCReqFinished_nu = (val)) //!< TPLCEN debug macro setter.

#undef	D_TPLCEN_TrigLargeDeviation_nu
#define	D_TPLCEN_TrigLargeDeviation_nu (TPLCEN_VehDbgPtr->D_TPLCEN_TrigLargeDeviation_nu) //!< TPLCEN debug macro.
#define	SET_D_TPLCEN_TrigLargeDeviation_nu(val)	(D_TPLCEN_TrigLargeDeviation_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_DelayVehGui_sec
#define	S_TPLCEN_DelayVehGui_sec (TPLCEN_VehDbgPtr->S_TPLCEN_DelayVehGui_sec) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_DelayVehGui_sec(val)	(S_TPLCEN_DelayVehGui_sec = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_EnblSpecPlanStrategy_nu
#define	S_TPLCEN_EnblSpecPlanStrategy_nu (TPLCEN_VehDbgPtr->S_TPLCEN_EnblSpecPlanStrategy_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_EnblSpecPlanStrategy_nu(val)	(S_TPLCEN_EnblSpecPlanStrategy_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_PredictionTimeCrv_sec
#define	S_TPLCEN_PredictionTimeCrv_sec (TPLCEN_VehDbgPtr->S_TPLCEN_PredictionTimeCrv_sec) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_PredictionTimeCrv_sec(val)	(S_TPLCEN_PredictionTimeCrv_sec = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_PredictionTimeHead_sec
#define	S_TPLCEN_PredictionTimeHead_sec (TPLCEN_VehDbgPtr->S_TPLCEN_PredictionTimeHead_sec) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_PredictionTimeHead_sec(val)	(S_TPLCEN_PredictionTimeHead_sec = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_ReplanCurValues_nu
#define	S_TPLCEN_ReplanCurValues_nu (TPLCEN_VehDbgPtr->S_TPLCEN_ReplanCurValues_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_ReplanCurValues_nu(val)	(S_TPLCEN_ReplanCurValues_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_ReplanModeArcLength_nu
#define	S_TPLCEN_ReplanModeArcLength_nu (TPLCEN_VehDbgPtr->S_TPLCEN_ReplanModeArcLength_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_ReplanModeArcLength_nu(val)	(S_TPLCEN_ReplanModeArcLength_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_ReplanTgtValues_nu
#define	S_TPLCEN_ReplanTgtValues_nu (TPLCEN_VehDbgPtr->S_TPLCEN_ReplanTgtValues_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_ReplanTgtValues_nu(val)	(S_TPLCEN_ReplanTgtValues_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_TrajGuiQuChange_nu
#define	S_TPLCEN_TrajGuiQuChange_nu (TPLCEN_VehDbgPtr->S_TPLCEN_TrajGuiQuChange_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_TrajGuiQuChange_nu(val)	(S_TPLCEN_TrajGuiQuChange_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_TrajPlanEnbl_nu
#define	S_TPLCEN_TrajPlanEnbl_nu (TPLCEN_VehDbgPtr->S_TPLCEN_TrajPlanEnbl_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_TrajPlanEnbl_nu(val)	(S_TPLCEN_TrajPlanEnbl_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_TrigCustFctActn_nu
#define	S_TPLCEN_TrigCustFctActn_nu (TPLCEN_VehDbgPtr->S_TPLCEN_TrigCustFctActn_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_TrigCustFctActn_nu(val)	(S_TPLCEN_TrigCustFctActn_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_TrigReplanTgtTraj_nu
#define	S_TPLCEN_TrigReplanTgtTraj_nu (TPLCEN_VehDbgPtr->S_TPLCEN_TrigReplanTgtTraj_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_TrigReplanTgtTraj_nu(val)	(S_TPLCEN_TrigReplanTgtTraj_nu = (val)) //!< TPLCEN debug macro setter.

#undef	S_TPLCEN_TrigTrajReplan_nu
#define	S_TPLCEN_TrigTrajReplan_nu (TPLCEN_VehDbgPtr->S_TPLCEN_TrigTrajReplan_nu) //!< TPLCEN debug macro.
#define	SET_S_TPLCEN_TrigTrajReplan_nu(val)	(S_TPLCEN_TrigTrajReplan_nu = (val)) //!< TPLCEN debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLCEN_TrigCustFctChange_nu
#define	D_TPLCEN_TrigCustFctChange_nu (TPLCEN_VehOutPtr->D_TPLCEN_TrigCustFctChange_nu) //!< TPLCEN debug macro.
#define	SET_D_TPLCEN_TrigCustFctChange_nu(val)	(D_TPLCEN_TrigCustFctChange_nu = (val)) //!< TPLCEN debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TPLCEN_PRIVATE_H_
