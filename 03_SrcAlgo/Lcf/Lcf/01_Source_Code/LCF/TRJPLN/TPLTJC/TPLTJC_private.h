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
//! @file     TPLTJC_private.h
//! @brief     (TPLTJC) Module Private Header.

#ifndef TPLTJC_PRIVATE_H_
#define TPLTJC_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJPLN	//!< TRJPLN sub-component input macro switch.
#define TPLTJC	//!< TPLTJC module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLTJC.h"
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

#define RUNNABLE_ID_TPLTJC_VehReset		0xF0 //!< TPLTJC module reset runnable identifier.
#define RUNNABLE_ID_TPLTJC_VehProcess	0xF1 //!< TPLTJC module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TPLTJC_VehDbgType *TPLTJC_VehDbgPtr = NULL; //!< TPLTJC module vehicle debug data pointer.
void TPLTJC_VehInitDbgPtr(TPLTJC_VehDbgType *TPLTJC_VehDbgArg) { TPLTJC_VehDbgPtr = TPLTJC_VehDbgPtr == NULL ? TPLTJC_VehDbgArg : TPLTJC_VehDbgPtr; }
const TPLTJC_VehDbgType* TPLTJC_VehGetDbgPtr(void) { return (const TPLTJC_VehDbgType*) TPLTJC_VehDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLTJC_MaxAclTraj_mps2
#define	D_TPLTJC_MaxAclTraj_mps2 (TPLTJC_VehDbgPtr->D_TPLTJC_MaxAclTraj_mps2) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_MaxAclTraj_mps2(val)	(D_TPLTJC_MaxAclTraj_mps2 = (val)) //!< TPLTJC debug macro setter.

#undef	D_TPLTJC_MaxJerkOK_nu
#define	D_TPLTJC_MaxJerkOK_nu (TPLTJC_VehDbgPtr->D_TPLTJC_MaxJerkOK_nu) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_MaxJerkOK_nu(val)	(D_TPLTJC_MaxJerkOK_nu = (val)) //!< TPLTJC debug macro setter.

#undef	D_TPLTJC_MaxJerkTraj_mps3
#define	D_TPLTJC_MaxJerkTraj_mps3 (TPLTJC_VehDbgPtr->D_TPLTJC_MaxJerkTraj_mps3) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_MaxJerkTraj_mps3(val)	(D_TPLTJC_MaxJerkTraj_mps3 = (val)) //!< TPLTJC debug macro setter.

#undef	D_TPLTJC_OptimalCost_nu
#define	D_TPLTJC_OptimalCost_nu (TPLTJC_VehDbgPtr->D_TPLTJC_OptimalCost_nu) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_OptimalCost_nu(val)	(D_TPLTJC_OptimalCost_nu = (val)) //!< TPLTJC debug macro setter.

#undef	D_TPLTJC_PassedTrajLenPercent_nu
#define	D_TPLTJC_PassedTrajLenPercent_nu (TPLTJC_VehDbgPtr->D_TPLTJC_PassedTrajLenPercent_nu) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_PassedTrajLenPercent_nu(val)	(D_TPLTJC_PassedTrajLenPercent_nu = (val)) //!< TPLTJC debug macro setter.

#undef	D_TPLTJC_WeightEndTime_nu
#define	D_TPLTJC_WeightEndTime_nu (TPLTJC_VehDbgPtr->D_TPLTJC_WeightEndTime_nu) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_WeightEndTime_nu(val)	(D_TPLTJC_WeightEndTime_nu = (val)) //!< TPLTJC debug macro setter.

#undef	D_TPLTJC_WeightTgtDistY_nu
#define	D_TPLTJC_WeightTgtDistY_nu (TPLTJC_VehDbgPtr->D_TPLTJC_WeightTgtDistY_nu) //!< TPLTJC debug macro.
#define	SET_D_TPLTJC_WeightTgtDistY_nu(val)	(D_TPLTJC_WeightTgtDistY_nu = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_EndPointTrajectory_nu
#define	S_TPLTJC_EndPointTrajectory_nu (TPLTJC_VehDbgPtr->S_TPLTJC_EndPointTrajectory_nu) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_EndPointTrajectory_nu(val)	(S_TPLTJC_EndPointTrajectory_nu = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_LengthOK_nu
#define	S_TPLTJC_LengthOK_nu (TPLTJC_VehDbgPtr->S_TPLTJC_LengthOK_nu) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_LengthOK_nu(val)	(S_TPLTJC_LengthOK_nu = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_MatrixInverseOK_nu
#define	S_TPLTJC_MatrixInverseOK_nu (TPLTJC_VehDbgPtr->S_TPLTJC_MatrixInverseOK_nu) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_MatrixInverseOK_nu(val)	(S_TPLTJC_MatrixInverseOK_nu = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_QuStatusTrajPlan_nu
#define	S_TPLTJC_QuStatusTrajPlan_nu (TPLTJC_VehDbgPtr->S_TPLTJC_QuStatusTrajPlan_nu) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_QuStatusTrajPlan_nu(val)	(S_TPLTJC_QuStatusTrajPlan_nu = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajDistY1stDeriv_mps
#define	S_TPLTJC_TrajDistY1stDeriv_mps (TPLTJC_VehDbgPtr->S_TPLTJC_TrajDistY1stDeriv_mps) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_TrajDistY1stDeriv_mps(val)	(S_TPLTJC_TrajDistY1stDeriv_mps = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajDistY2ndDeriv_mps2
#define	S_TPLTJC_TrajDistY2ndDeriv_mps2 (TPLTJC_VehDbgPtr->S_TPLTJC_TrajDistY2ndDeriv_mps2) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_TrajDistY2ndDeriv_mps2(val)	(S_TPLTJC_TrajDistY2ndDeriv_mps2 = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajDistY3rdDeriv_mps3
#define	S_TPLTJC_TrajDistY3rdDeriv_mps3 (TPLTJC_VehDbgPtr->S_TPLTJC_TrajDistY3rdDeriv_mps3) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_TrajDistY3rdDeriv_mps3(val)	(S_TPLTJC_TrajDistY3rdDeriv_mps3 = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajDistYFmPrev_met
#define	S_TPLTJC_TrajDistYFmPrev_met (TPLTJC_VehDbgPtr->S_TPLTJC_TrajDistYFmPrev_met) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_TrajDistYFmPrev_met(val)	(S_TPLTJC_TrajDistYFmPrev_met = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajDistY_met
#define	S_TPLTJC_TrajDistY_met (TPLTJC_VehDbgPtr->S_TPLTJC_TrajDistY_met) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_TrajDistY_met(val)	(S_TPLTJC_TrajDistY_met = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajEnd_nu
#define	S_TPLTJC_TrajEnd_nu (TPLTJC_VehDbgPtr->S_TPLTJC_TrajEnd_nu) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_TrajEnd_nu(val)	(S_TPLTJC_TrajEnd_nu = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_YDt2TrjFmKpPrevDT_mps2
#define	S_TPLTJC_YDt2TrjFmKpPrevDT_mps2 (TPLTJC_VehDbgPtr->S_TPLTJC_YDt2TrjFmKpPrevDT_mps2) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_YDt2TrjFmKpPrevDT_mps2(val)	(S_TPLTJC_YDt2TrjFmKpPrevDT_mps2 = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_YDt2TrjFmKpPrev_mps2
#define	S_TPLTJC_YDt2TrjFmKpPrev_mps2 (TPLTJC_VehDbgPtr->S_TPLTJC_YDt2TrjFmKpPrev_mps2) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_YDt2TrjFmKpPrev_mps2(val)	(S_TPLTJC_YDt2TrjFmKpPrev_mps2 = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_YDt3TrjFmKpPrevDT_mps3
#define	S_TPLTJC_YDt3TrjFmKpPrevDT_mps3 (TPLTJC_VehDbgPtr->S_TPLTJC_YDt3TrjFmKpPrevDT_mps3) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_YDt3TrjFmKpPrevDT_mps3(val)	(S_TPLTJC_YDt3TrjFmKpPrevDT_mps3 = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_YDtTrjFmHeadPrev_mps
#define	S_TPLTJC_YDtTrjFmHeadPrev_mps (TPLTJC_VehDbgPtr->S_TPLTJC_YDtTrjFmHeadPrev_mps) //!< TPLTJC debug macro.
#define	SET_S_TPLTJC_YDtTrjFmHeadPrev_mps(val)	(S_TPLTJC_YDtTrjFmHeadPrev_mps = (val)) //!< TPLTJC debug macro setter.

#undef	S_TPLTJC_TrajParam_nu
#define	S_TPLTJC_TrajParam_nu(i) (TPLTJC_VehDbgPtr->S_TPLTJC_TrajParam_nu[(i)]) //!< TPLTJC debug macro.
#define SET_S_TPLTJC_TrajParam_nu(i, val)	(S_TPLTJC_TrajParam_nu(i) = (val)) //!< TPLTJC debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TPLTJC_PRIVATE_H_
