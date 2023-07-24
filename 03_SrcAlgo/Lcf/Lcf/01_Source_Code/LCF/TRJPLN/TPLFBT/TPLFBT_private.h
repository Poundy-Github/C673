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
//! @file     TPLFBT_private.h
//! @brief     (TPLFBT) Module Private Header.

#ifndef TPLFBT_PRIVATE_H_
#define TPLFBT_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJPLN	//!< TRJPLN sub-component input macro switch.
#define TPLFBT	//!< TPLFBT module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLFBT.h"
#include "Bitop.h"  //MFC5J3
#include "ecmath.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TPLFBT_VehReset		0xF0 //!< TPLFBT module reset runnable identifier.
#define RUNNABLE_ID_TPLFBT_VehProcess	0xF1 //!< TPLFBT module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TPLFBT_VehDbgType *TPLFBT_VehDbgPtr = NULL; //!< TPLFBT module vehicle debug data pointer.
void TPLFBT_VehInitDbgPtr(TPLFBT_VehDbgType *TPLFBT_VehDbgArg) { TPLFBT_VehDbgPtr = TPLFBT_VehDbgPtr == NULL ? TPLFBT_VehDbgArg : TPLFBT_VehDbgPtr; }
const TPLFBT_VehDbgType* TPLFBT_VehGetDbgPtr(void) { return (const TPLFBT_VehDbgType*) TPLFBT_VehDbgPtr; }

static TPLFBT_VehOutType *TPLFBT_VehOutPtr = NULL; //!< TPLFBT module vehicle output data pointer.
void TPLFBT_VehInitOutPtr(TPLFBT_VehOutType *TPLFBT_VehOutArg) { TPLFBT_VehOutPtr = TPLFBT_VehOutPtr == NULL ? TPLFBT_VehOutArg : TPLFBT_VehOutPtr; }
const TPLFBT_VehOutType* TPLFBT_VehGetOutPtr(void) { return (const TPLFBT_VehOutType*) TPLFBT_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLFBT_DeltaTargetCrv_1pm
#define	D_TPLFBT_DeltaTargetCrv_1pm (TPLFBT_VehDbgPtr->D_TPLFBT_DeltaTargetCrv_1pm) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_DeltaTargetCrv_1pm(val)	(D_TPLFBT_DeltaTargetCrv_1pm = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_DeltaTargetHeading_rad
#define	D_TPLFBT_DeltaTargetHeading_rad (TPLFBT_VehDbgPtr->D_TPLFBT_DeltaTargetHeading_rad) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_DeltaTargetHeading_rad(val)	(D_TPLFBT_DeltaTargetHeading_rad = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_DeltaTargetPosY0_met
#define	D_TPLFBT_DeltaTargetPosY0_met (TPLFBT_VehDbgPtr->D_TPLFBT_DeltaTargetPosY0_met) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_DeltaTargetPosY0_met(val)	(D_TPLFBT_DeltaTargetPosY0_met = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_GradLimitActive_nu
#define	D_TPLFBT_GradLimitActive_nu (TPLFBT_VehDbgPtr->D_TPLFBT_GradLimitActive_nu) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_GradLimitActive_nu(val)	(D_TPLFBT_GradLimitActive_nu = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_PlausiCheckStatus_nu
#define	D_TPLFBT_PlausiCheckStatus_nu (TPLFBT_VehDbgPtr->D_TPLFBT_PlausiCheckStatus_nu) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_PlausiCheckStatus_nu(val)	(D_TPLFBT_PlausiCheckStatus_nu = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_QuStatusTrajPlan_nu
#define	D_TPLFBT_QuStatusTrajPlan_nu (TPLFBT_VehDbgPtr->D_TPLFBT_QuStatusTrajPlan_nu) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_QuStatusTrajPlan_nu(val)	(D_TPLFBT_QuStatusTrajPlan_nu = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TargetSwitch_nu
#define	D_TPLFBT_TargetSwitch_nu (TPLFBT_VehDbgPtr->D_TPLFBT_TargetSwitch_nu) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TargetSwitch_nu(val)	(D_TPLFBT_TargetSwitch_nu = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_UseTargetCorridor_nu
#define	D_TPLFBT_UseTargetCorridor_nu (TPLFBT_VehDbgPtr->D_TPLFBT_UseTargetCorridor_nu) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_UseTargetCorridor_nu(val)	(D_TPLFBT_UseTargetCorridor_nu = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_CtrlErrDistY_met
#define	S_TPLFBT_CtrlErrDistY_met (TPLFBT_VehDbgPtr->S_TPLFBT_CtrlErrDistY_met) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_CtrlErrDistY_met(val)	(S_TPLFBT_CtrlErrDistY_met = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_CtrlErrHeadAglPrev_rad
#define	S_TPLFBT_CtrlErrHeadAglPrev_rad (TPLFBT_VehDbgPtr->S_TPLFBT_CtrlErrHeadAglPrev_rad) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_CtrlErrHeadAglPrev_rad(val)	(S_TPLFBT_CtrlErrHeadAglPrev_rad = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_CtrlErrHeadingAngle_rad
#define	S_TPLFBT_CtrlErrHeadingAngle_rad (TPLFBT_VehDbgPtr->S_TPLFBT_CtrlErrHeadingAngle_rad) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_CtrlErrHeadingAngle_rad(val)	(S_TPLFBT_CtrlErrHeadingAngle_rad = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_CurDistY_met
#define	S_TPLFBT_CurDistY_met (TPLFBT_VehDbgPtr->S_TPLFBT_CurDistY_met) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_CurDistY_met(val)	(S_TPLFBT_CurDistY_met = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_CurHeading_rad
#define	S_TPLFBT_CurHeading_rad (TPLFBT_VehDbgPtr->S_TPLFBT_CurHeading_rad) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_CurHeading_rad(val)	(S_TPLFBT_CurHeading_rad = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_QuStatusTrajPlan_nu
#define	S_TPLFBT_QuStatusTrajPlan_nu (TPLFBT_VehDbgPtr->S_TPLFBT_QuStatusTrajPlan_nu) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_QuStatusTrajPlan_nu(val)	(S_TPLFBT_QuStatusTrajPlan_nu = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajDistYPrev_met
#define	S_TPLFBT_TrajDistYPrev_met (TPLFBT_VehDbgPtr->S_TPLFBT_TrajDistYPrev_met) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajDistYPrev_met(val)	(S_TPLFBT_TrajDistYPrev_met = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajDistY_met
#define	S_TPLFBT_TrajDistY_met (TPLFBT_VehDbgPtr->S_TPLFBT_TrajDistY_met) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajDistY_met(val)	(S_TPLFBT_TrajDistY_met = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajGuiQualifier_nu
#define	S_TPLFBT_TrajGuiQualifier_nu (TPLFBT_VehDbgPtr->S_TPLFBT_TrajGuiQualifier_nu) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajGuiQualifier_nu(val)	(S_TPLFBT_TrajGuiQualifier_nu = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajHeadInclPrev_rad
#define	S_TPLFBT_TrajHeadInclPrev_rad (TPLFBT_VehDbgPtr->S_TPLFBT_TrajHeadInclPrev_rad) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajHeadInclPrev_rad(val)	(S_TPLFBT_TrajHeadInclPrev_rad = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajHeadingPrev_rad
#define	S_TPLFBT_TrajHeadingPrev_rad (TPLFBT_VehDbgPtr->S_TPLFBT_TrajHeadingPrev_rad) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajHeadingPrev_rad(val)	(S_TPLFBT_TrajHeadingPrev_rad = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajHeading_rad
#define	S_TPLFBT_TrajHeading_rad (TPLFBT_VehDbgPtr->S_TPLFBT_TrajHeading_rad) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajHeading_rad(val)	(S_TPLFBT_TrajHeading_rad = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajTgtCrvPrev_1pm
#define	S_TPLFBT_TrajTgtCrvPrev_1pm (TPLFBT_VehDbgPtr->S_TPLFBT_TrajTgtCrvPrev_1pm) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajTgtCrvPrev_1pm(val)	(S_TPLFBT_TrajTgtCrvPrev_1pm = (val)) //!< TPLFBT debug macro setter.

#undef	S_TPLFBT_TrajTgtCrv_1pm
#define	S_TPLFBT_TrajTgtCrv_1pm (TPLFBT_VehDbgPtr->S_TPLFBT_TrajTgtCrv_1pm) //!< TPLFBT debug macro.
#define	SET_S_TPLFBT_TrajTgtCrv_1pm(val)	(S_TPLFBT_TrajTgtCrv_1pm = (val)) //!< TPLFBT debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLFBT_TgtCorridorCrvGrd_1pms
#define	D_TPLFBT_TgtCorridorCrvGrd_1pms (TPLFBT_VehOutPtr->D_TPLFBT_TgtCorridorCrvGrd_1pms) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TgtCorridorCrvGrd_1pms(val)	(D_TPLFBT_TgtCorridorCrvGrd_1pms = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TgtCorridorCrv_1pm
#define	D_TPLFBT_TgtCorridorCrv_1pm (TPLFBT_VehOutPtr->D_TPLFBT_TgtCorridorCrv_1pm) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TgtCorridorCrv_1pm(val)	(D_TPLFBT_TgtCorridorCrv_1pm = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms
#define	D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms (TPLFBT_VehOutPtr->D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms(val)	(D_TPLFBT_TgtTrjCrvGrdPrvwDT_1pms = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TgtTrjCrvPrvwDT_1pm
#define	D_TPLFBT_TgtTrjCrvPrvwDT_1pm (TPLFBT_VehOutPtr->D_TPLFBT_TgtTrjCrvPrvwDT_1pm) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TgtTrjCrvPrvwDT_1pm(val)	(D_TPLFBT_TgtTrjCrvPrvwDT_1pm = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TrajHeadingPrvw_rad
#define	D_TPLFBT_TrajHeadingPrvw_rad (TPLFBT_VehOutPtr->D_TPLFBT_TrajHeadingPrvw_rad) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TrajHeadingPrvw_rad(val)	(D_TPLFBT_TrajHeadingPrvw_rad = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TrajPlanInvalid_nu
#define	D_TPLFBT_TrajPlanInvalid_nu (TPLFBT_VehOutPtr->D_TPLFBT_TrajPlanInvalid_nu) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TrajPlanInvalid_nu(val)	(D_TPLFBT_TrajPlanInvalid_nu = (val)) //!< TPLFBT debug macro setter.

#undef	D_TPLFBT_TrajTgtCrvGrdPrev_1pms
#define	D_TPLFBT_TrajTgtCrvGrdPrev_1pms (TPLFBT_VehOutPtr->D_TPLFBT_TrajTgtCrvGrdPrev_1pms) //!< TPLFBT debug macro.
#define	SET_D_TPLFBT_TrajTgtCrvGrdPrev_1pms(val)	(D_TPLFBT_TrajTgtCrvGrdPrev_1pms = (val)) //!< TPLFBT debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TPLFBT_PRIVATE_H_
