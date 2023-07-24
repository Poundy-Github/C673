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
//! @file     TPLFRT_private.h
//! @brief     (TPLFRT) Module Private Header.

#ifndef TPLFRT_PRIVATE_H_
#define TPLFRT_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJPLN	//!< TRJPLN sub-component input macro switch.
#define TPLFRT	//!< TPLFRT module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLFRT.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TPLFRT_VehReset		0xF0 //!< TPLFRT module reset runnable identifier.
#define RUNNABLE_ID_TPLFRT_VehProcess	0xF1 //!< TPLFRT module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TPLFRT_VehDbgType *TPLFRT_VehDbgPtr = NULL; //!< TPLFRT module vehicle debug data pointer.
void TPLFRT_VehInitDbgPtr(TPLFRT_VehDbgType *TPLFRT_VehDbgArg) { TPLFRT_VehDbgPtr = TPLFRT_VehDbgPtr == NULL ? TPLFRT_VehDbgArg : TPLFRT_VehDbgPtr; }
const TPLFRT_VehDbgType* TPLFRT_VehGetDbgPtr(void) { return (const TPLFRT_VehDbgType*) TPLFRT_VehDbgPtr; }

static TPLFRT_VehOutType *TPLFRT_VehOutPtr = NULL; //!< TPLFRT module vehicle output data pointer.
void TPLFRT_VehInitOutPtr(TPLFRT_VehOutType *TPLFRT_VehOutArg) { TPLFRT_VehOutPtr = TPLFRT_VehOutPtr == NULL ? TPLFRT_VehOutArg : TPLFRT_VehOutPtr; }
const TPLFRT_VehOutType* TPLFRT_VehGetOutPtr(void) { return (const TPLFRT_VehOutType*) TPLFRT_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TPLFRT_CurDistY1stDeriv_mps
#define	S_TPLFRT_CurDistY1stDeriv_mps (TPLFRT_VehDbgPtr->S_TPLFRT_CurDistY1stDeriv_mps) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_CurDistY1stDeriv_mps(val)	(S_TPLFRT_CurDistY1stDeriv_mps = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_CurDistY1stToPrev_mps
#define	S_TPLFRT_CurDistY1stToPrev_mps (TPLFRT_VehDbgPtr->S_TPLFRT_CurDistY1stToPrev_mps) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_CurDistY1stToPrev_mps(val)	(S_TPLFRT_CurDistY1stToPrev_mps = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_CurDistY2ndDeriv_mps2
#define	S_TPLFRT_CurDistY2ndDeriv_mps2 (TPLFRT_VehDbgPtr->S_TPLFRT_CurDistY2ndDeriv_mps2) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_CurDistY2ndDeriv_mps2(val)	(S_TPLFRT_CurDistY2ndDeriv_mps2 = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_CurDistYPreview_met
#define	S_TPLFRT_CurDistYPreview_met (TPLFRT_VehDbgPtr->S_TPLFRT_CurDistYPreview_met) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_CurDistYPreview_met(val)	(S_TPLFRT_CurDistYPreview_met = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_CurDistY_met
#define	S_TPLFRT_CurDistY_met (TPLFRT_VehDbgPtr->S_TPLFRT_CurDistY_met) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_CurDistY_met(val)	(S_TPLFRT_CurDistY_met = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_DistY1stToDevHead_mps
#define	S_TPLFRT_DistY1stToDevHead_mps (TPLFRT_VehDbgPtr->S_TPLFRT_DistY1stToDevHead_mps) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_DistY1stToDevHead_mps(val)	(S_TPLFRT_DistY1stToDevHead_mps = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_DistY2ndToDevHead_mps2
#define	S_TPLFRT_DistY2ndToDevHead_mps2 (TPLFRT_VehDbgPtr->S_TPLFRT_DistY2ndToDevHead_mps2) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_DistY2ndToDevHead_mps2(val)	(S_TPLFRT_DistY2ndToDevHead_mps2 = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_NumPointsCridrLeft_nu
#define	S_TPLFRT_NumPointsCridrLeft_nu (TPLFRT_VehDbgPtr->S_TPLFRT_NumPointsCridrLeft_nu) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_NumPointsCridrLeft_nu(val)	(S_TPLFRT_NumPointsCridrLeft_nu = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_NumTgtPoints_nu
#define	S_TPLFRT_NumTgtPoints_nu (TPLFRT_VehDbgPtr->S_TPLFRT_NumTgtPoints_nu) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_NumTgtPoints_nu(val)	(S_TPLFRT_NumTgtPoints_nu = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_PlanHorizonVisRange_sec
#define	S_TPLFRT_PlanHorizonVisRange_sec (TPLFRT_VehDbgPtr->S_TPLFRT_PlanHorizonVisRange_sec) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_PlanHorizonVisRange_sec(val)	(S_TPLFRT_PlanHorizonVisRange_sec = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_PreviewTimeHeading_sec
#define	S_TPLFRT_PreviewTimeHeading_sec (TPLFRT_VehDbgPtr->S_TPLFRT_PreviewTimeHeading_sec) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_PreviewTimeHeading_sec(val)	(S_TPLFRT_PreviewTimeHeading_sec = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TrajAclRefCurve_mps2
#define	S_TPLFRT_TrajAclRefCurve_mps2 (TPLFRT_VehDbgPtr->S_TPLFRT_TrajAclRefCurve_mps2) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_TrajAclRefCurve_mps2(val)	(S_TPLFRT_TrajAclRefCurve_mps2 = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TrajDistY1stToPrev_mps
#define	S_TPLFRT_TrajDistY1stToPrev_mps (TPLFRT_VehDbgPtr->S_TPLFRT_TrajDistY1stToPrev_mps) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_TrajDistY1stToPrev_mps(val)	(S_TPLFRT_TrajDistY1stToPrev_mps = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TrajDistY2ndToPrev_mps2
#define	S_TPLFRT_TrajDistY2ndToPrev_mps2 (TPLFRT_VehDbgPtr->S_TPLFRT_TrajDistY2ndToPrev_mps2) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_TrajDistY2ndToPrev_mps2(val)	(S_TPLFRT_TrajDistY2ndToPrev_mps2 = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TrajDistYPrev_met
#define	S_TPLFRT_TrajDistYPrev_met (TPLFRT_VehDbgPtr->S_TPLFRT_TrajDistYPrev_met) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_TrajDistYPrev_met(val)	(S_TPLFRT_TrajDistYPrev_met = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TrajPlanningHorizon_sec
#define	S_TPLFRT_TrajPlanningHorizon_sec (TPLFRT_VehDbgPtr->S_TPLFRT_TrajPlanningHorizon_sec) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_TrajPlanningHorizon_sec(val)	(S_TPLFRT_TrajPlanningHorizon_sec = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TrajVelRefCurve_mps
#define	S_TPLFRT_TrajVelRefCurve_mps (TPLFRT_VehDbgPtr->S_TPLFRT_TrajVelRefCurve_mps) //!< TPLFRT debug macro.
#define	SET_S_TPLFRT_TrajVelRefCurve_mps(val)	(S_TPLFRT_TrajVelRefCurve_mps = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TgtDistY1stDeriv_mps
#define	S_TPLFRT_TgtDistY1stDeriv_mps(i) (TPLFRT_VehDbgPtr->S_TPLFRT_TgtDistY1stDeriv_mps[(i)]) //!< TPLFRT debug macro.
#define SET_S_TPLFRT_TgtDistY1stDeriv_mps(i, val)	(S_TPLFRT_TgtDistY1stDeriv_mps(i) = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TgtDistY2ndDeriv_mps2
#define	S_TPLFRT_TgtDistY2ndDeriv_mps2(i) (TPLFRT_VehDbgPtr->S_TPLFRT_TgtDistY2ndDeriv_mps2[(i)]) //!< TPLFRT debug macro.
#define SET_S_TPLFRT_TgtDistY2ndDeriv_mps2(i, val)	(S_TPLFRT_TgtDistY2ndDeriv_mps2(i) = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TgtDistY_met
#define	S_TPLFRT_TgtDistY_met(i) (TPLFRT_VehDbgPtr->S_TPLFRT_TgtDistY_met[(i)]) //!< TPLFRT debug macro.
#define SET_S_TPLFRT_TgtDistY_met(i, val)	(S_TPLFRT_TgtDistY_met(i) = (val)) //!< TPLFRT debug macro setter.

#undef	S_TPLFRT_TgtPoints_nu
#define	S_TPLFRT_TgtPoints_nu(i) (TPLFRT_VehDbgPtr->S_TPLFRT_TgtPoints_nu[(i)]) //!< TPLFRT debug macro.
#define SET_S_TPLFRT_TgtPoints_nu(i, val)	(S_TPLFRT_TgtPoints_nu(i) = (val)) //!< TPLFRT debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_TPLFRT_LeftDistY_met
#define	S_TPLFRT_LeftDistY_met(i) (TPLFRT_VehOutPtr->S_TPLFRT_LeftDistY_met[(i)]) //!< TPLFRT debug macro.
#define SET_S_TPLFRT_LeftDistY_met(i, val)	(S_TPLFRT_LeftDistY_met(i) = (val)) //!< TPLFRT debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TPLFRT_PRIVATE_H_
