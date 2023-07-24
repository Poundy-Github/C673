/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJPLN
  MODULE        : TPLLCO
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TPLLCO_private.h
//! @brief     (TPLLCO) Module Private Header.

#ifndef TPLLCO_PRIVATE_H_
#define TPLLCO_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJPLN	//!< TRJPLN sub-component input macro switch.
#define TPLLCO	//!< TPLLCO module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TPLLCO.h"
#include "Bitop.h" //MFC5J3
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

#define RUNNABLE_ID_TPLLCO_VehReset		0xF0 //!< TPLLCO module reset runnable identifier.
#define RUNNABLE_ID_TPLLCO_VehProcess	0xF1 //!< TPLLCO module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TPLLCO_VehDbgType *TPLLCO_VehDbgPtr = NULL; //!< TPLLCO module vehicle debug data pointer.
void TPLLCO_VehInitDbgPtr(TPLLCO_VehDbgType *TPLLCO_VehDbgArg) { TPLLCO_VehDbgPtr = TPLLCO_VehDbgPtr == NULL ? TPLLCO_VehDbgArg : TPLLCO_VehDbgPtr; }
const TPLLCO_VehDbgType* TPLLCO_VehGetDbgPtr(void) { return (const TPLLCO_VehDbgType*) TPLLCO_VehDbgPtr; }

static TPLLCO_VehOutType *TPLLCO_VehOutPtr = NULL; //!< TPLLCO module vehicle output data pointer.
void TPLLCO_VehInitOutPtr(TPLLCO_VehOutType *TPLLCO_VehOutArg) { TPLLCO_VehOutPtr = TPLLCO_VehOutPtr == NULL ? TPLLCO_VehOutArg : TPLLCO_VehOutPtr; }
const TPLLCO_VehOutType* TPLLCO_VehGetOutPtr(void) { return (const TPLLCO_VehOutType*) TPLLCO_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLLCO_CCCDeviation_met
#define	D_TPLLCO_CCCDeviation_met (TPLLCO_VehDbgPtr->D_TPLLCO_CCCDeviation_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCDeviation_met(val)	(D_TPLLCO_CCCDeviation_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCInvalid_nu
#define	D_TPLLCO_CCCInvalid_nu (TPLLCO_VehDbgPtr->D_TPLLCO_CCCInvalid_nu) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCInvalid_nu(val)	(D_TPLLCO_CCCInvalid_nu = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCLength_met
#define	D_TPLLCO_CCCLength_met (TPLLCO_VehDbgPtr->D_TPLLCO_CCCLength_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCLength_met(val)	(D_TPLLCO_CCCLength_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCPassedPerc_nu
#define	D_TPLLCO_CCCPassedPerc_nu (TPLLCO_VehDbgPtr->D_TPLLCO_CCCPassedPerc_nu) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCPassedPerc_nu(val)	(D_TPLLCO_CCCPassedPerc_nu = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCReset_nu
#define	D_TPLLCO_CCCReset_nu (TPLLCO_VehDbgPtr->D_TPLLCO_CCCReset_nu) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCReset_nu(val)	(D_TPLLCO_CCCReset_nu = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCTestPointDistX_met
#define	D_TPLLCO_CCCTestPointDistX_met (TPLLCO_VehDbgPtr->D_TPLLCO_CCCTestPointDistX_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCTestPointDistX_met(val)	(D_TPLLCO_CCCTestPointDistX_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCWarning_nu
#define	D_TPLLCO_CCCWarning_nu (TPLLCO_VehDbgPtr->D_TPLLCO_CCCWarning_nu) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCWarning_nu(val)	(D_TPLLCO_CCCWarning_nu = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_DeltaProjPosX_met
#define	D_TPLLCO_DeltaProjPosX_met (TPLLCO_VehDbgPtr->D_TPLLCO_DeltaProjPosX_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_DeltaProjPosX_met(val)	(D_TPLLCO_DeltaProjPosX_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_DeltaProjPosY_met
#define	D_TPLLCO_DeltaProjPosY_met (TPLLCO_VehDbgPtr->D_TPLLCO_DeltaProjPosY_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_DeltaProjPosY_met(val)	(D_TPLLCO_DeltaProjPosY_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_EgoDistYPre_met
#define	D_TPLLCO_EgoDistYPre_met (TPLLCO_VehDbgPtr->D_TPLLCO_EgoDistYPre_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_EgoDistYPre_met(val)	(D_TPLLCO_EgoDistYPre_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_EgoHeadingPre_rad
#define	D_TPLLCO_EgoHeadingPre_rad (TPLLCO_VehDbgPtr->D_TPLLCO_EgoHeadingPre_rad) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_EgoHeadingPre_rad(val)	(D_TPLLCO_EgoHeadingPre_rad = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_PlausiCheckStatus_nu
#define	D_TPLLCO_PlausiCheckStatus_nu (TPLLCO_VehDbgPtr->D_TPLLCO_PlausiCheckStatus_nu) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_PlausiCheckStatus_nu(val)	(D_TPLLCO_PlausiCheckStatus_nu = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_RightOri_rad
#define	D_TPLLCO_RightOri_rad (TPLLCO_VehDbgPtr->D_TPLLCO_RightOri_rad) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_RightOri_rad(val)	(D_TPLLCO_RightOri_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_DevDistY_met
#define	S_TPLLCO_DevDistY_met (TPLLCO_VehDbgPtr->S_TPLLCO_DevDistY_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_DevDistY_met(val)	(S_TPLLCO_DevDistY_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_DevHeading_rad
#define	S_TPLLCO_DevHeading_rad (TPLLCO_VehDbgPtr->S_TPLLCO_DevHeading_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_DevHeading_rad(val)	(S_TPLLCO_DevHeading_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_LeftCorridorCrv_1pm
#define	S_TPLLCO_LeftCorridorCrv_1pm (TPLLCO_VehDbgPtr->S_TPLLCO_LeftCorridorCrv_1pm) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_LeftCorridorCrv_1pm(val)	(S_TPLLCO_LeftCorridorCrv_1pm = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_LeftCorridorHeading_rad
#define	S_TPLLCO_LeftCorridorHeading_rad (TPLLCO_VehDbgPtr->S_TPLLCO_LeftCorridorHeading_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_LeftCorridorHeading_rad(val)	(S_TPLLCO_LeftCorridorHeading_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_LeftCorridorLength_met
#define	S_TPLLCO_LeftCorridorLength_met (TPLLCO_VehDbgPtr->S_TPLLCO_LeftCorridorLength_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_LeftCorridorLength_met(val)	(S_TPLLCO_LeftCorridorLength_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_LeftCorridorPosX0_met
#define	S_TPLLCO_LeftCorridorPosX0_met (TPLLCO_VehDbgPtr->S_TPLLCO_LeftCorridorPosX0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_LeftCorridorPosX0_met(val)	(S_TPLLCO_LeftCorridorPosX0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_LeftCorridorPosY0_met
#define	S_TPLLCO_LeftCorridorPosY0_met (TPLLCO_VehDbgPtr->S_TPLLCO_LeftCorridorPosY0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_LeftCorridorPosY0_met(val)	(S_TPLLCO_LeftCorridorPosY0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_LeftCridrChngOfCrv_1pm2
#define	S_TPLLCO_LeftCridrChngOfCrv_1pm2 (TPLLCO_VehDbgPtr->S_TPLLCO_LeftCridrChngOfCrv_1pm2) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_LeftCridrChngOfCrv_1pm2(val)	(S_TPLLCO_LeftCridrChngOfCrv_1pm2 = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_MeasDeltaT_sec
#define	S_TPLLCO_MeasDeltaT_sec (TPLLCO_VehDbgPtr->S_TPLLCO_MeasDeltaT_sec) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_MeasDeltaT_sec(val)	(S_TPLLCO_MeasDeltaT_sec = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_PlausiCheckStatus_nu
#define	S_TPLLCO_PlausiCheckStatus_nu (TPLLCO_VehDbgPtr->S_TPLLCO_PlausiCheckStatus_nu) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_PlausiCheckStatus_nu(val)	(S_TPLLCO_PlausiCheckStatus_nu = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_ReplanDevDistY_met
#define	S_TPLLCO_ReplanDevDistY_met (TPLLCO_VehDbgPtr->S_TPLLCO_ReplanDevDistY_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_ReplanDevDistY_met(val)	(S_TPLLCO_ReplanDevDistY_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_ReplanDevHeading_rad
#define	S_TPLLCO_ReplanDevHeading_rad (TPLLCO_VehDbgPtr->S_TPLLCO_ReplanDevHeading_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_ReplanDevHeading_rad(val)	(S_TPLLCO_ReplanDevHeading_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_RiCridrChngOfCrv_1pm2
#define	S_TPLLCO_RiCridrChngOfCrv_1pm2 (TPLLCO_VehDbgPtr->S_TPLLCO_RiCridrChngOfCrv_1pm2) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_RiCridrChngOfCrv_1pm2(val)	(S_TPLLCO_RiCridrChngOfCrv_1pm2 = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_RightCorridorCrv_1pm
#define	S_TPLLCO_RightCorridorCrv_1pm (TPLLCO_VehDbgPtr->S_TPLLCO_RightCorridorCrv_1pm) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_RightCorridorCrv_1pm(val)	(S_TPLLCO_RightCorridorCrv_1pm = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_RightCorridorLength_met
#define	S_TPLLCO_RightCorridorLength_met (TPLLCO_VehDbgPtr->S_TPLLCO_RightCorridorLength_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_RightCorridorLength_met(val)	(S_TPLLCO_RightCorridorLength_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_RightCorridorPosX0_met
#define	S_TPLLCO_RightCorridorPosX0_met (TPLLCO_VehDbgPtr->S_TPLLCO_RightCorridorPosX0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_RightCorridorPosX0_met(val)	(S_TPLLCO_RightCorridorPosX0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_RightCorridorPosY0_met
#define	S_TPLLCO_RightCorridorPosY0_met (TPLLCO_VehDbgPtr->S_TPLLCO_RightCorridorPosY0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_RightCorridorPosY0_met(val)	(S_TPLLCO_RightCorridorPosY0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_RightCridrHeading_rad
#define	S_TPLLCO_RightCridrHeading_rad (TPLLCO_VehDbgPtr->S_TPLLCO_RightCridrHeading_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_RightCridrHeading_rad(val)	(S_TPLLCO_RightCridrHeading_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetCorridorCrv_1pm
#define	S_TPLLCO_TargetCorridorCrv_1pm (TPLLCO_VehDbgPtr->S_TPLLCO_TargetCorridorCrv_1pm) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetCorridorCrv_1pm(val)	(S_TPLLCO_TargetCorridorCrv_1pm = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetCorridorPosX0_met
#define	S_TPLLCO_TargetCorridorPosX0_met (TPLLCO_VehDbgPtr->S_TPLLCO_TargetCorridorPosX0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetCorridorPosX0_met(val)	(S_TPLLCO_TargetCorridorPosX0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetCorridorPosY0_met
#define	S_TPLLCO_TargetCorridorPosY0_met (TPLLCO_VehDbgPtr->S_TPLLCO_TargetCorridorPosY0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetCorridorPosY0_met(val)	(S_TPLLCO_TargetCorridorPosY0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetCridrHeading_rad
#define	S_TPLLCO_TargetCridrHeading_rad (TPLLCO_VehDbgPtr->S_TPLLCO_TargetCridrHeading_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetCridrHeading_rad(val)	(S_TPLLCO_TargetCridrHeading_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetCridrLength_met
#define	S_TPLLCO_TargetCridrLength_met (TPLLCO_VehDbgPtr->S_TPLLCO_TargetCridrLength_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetCridrLength_met(val)	(S_TPLLCO_TargetCridrLength_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetPathCrv_rad
#define	S_TPLLCO_TargetPathCrv_rad (TPLLCO_VehDbgPtr->S_TPLLCO_TargetPathCrv_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetPathCrv_rad(val)	(S_TPLLCO_TargetPathCrv_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetPathHeading_rad
#define	S_TPLLCO_TargetPathHeading_rad (TPLLCO_VehDbgPtr->S_TPLLCO_TargetPathHeading_rad) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetPathHeading_rad(val)	(S_TPLLCO_TargetPathHeading_rad = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TargetPathY0_met
#define	S_TPLLCO_TargetPathY0_met (TPLLCO_VehDbgPtr->S_TPLLCO_TargetPathY0_met) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TargetPathY0_met(val)	(S_TPLLCO_TargetPathY0_met = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TgtCridrChngOfCrv_1pm2
#define	S_TPLLCO_TgtCridrChngOfCrv_1pm2 (TPLLCO_VehDbgPtr->S_TPLLCO_TgtCridrChngOfCrv_1pm2) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TgtCridrChngOfCrv_1pm2(val)	(S_TPLLCO_TgtCridrChngOfCrv_1pm2 = (val)) //!< TPLLCO debug macro setter.

#undef	S_TPLLCO_TriggerReplan_nu
#define	S_TPLLCO_TriggerReplan_nu (TPLLCO_VehDbgPtr->S_TPLLCO_TriggerReplan_nu) //!< TPLLCO debug macro.
#define	SET_S_TPLLCO_TriggerReplan_nu(val)	(S_TPLLCO_TriggerReplan_nu = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_LeCridrTransDev_met
#define	D_TPLLCO_LeCridrTransDev_met(i) (TPLLCO_VehDbgPtr->D_TPLLCO_LeCridrTransDev_met[(i)]) //!< TPLLCO debug macro.
#define SET_D_TPLLCO_LeCridrTransDev_met(i, val)	(D_TPLLCO_LeCridrTransDev_met(i) = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_RiCridrTransDev_met
#define	D_TPLLCO_RiCridrTransDev_met(i) (TPLLCO_VehDbgPtr->D_TPLLCO_RiCridrTransDev_met[(i)]) //!< TPLLCO debug macro.
#define SET_D_TPLLCO_RiCridrTransDev_met(i, val)	(D_TPLLCO_RiCridrTransDev_met(i) = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_TgtCridrTransDev_met
#define	D_TPLLCO_TgtCridrTransDev_met(i) (TPLLCO_VehDbgPtr->D_TPLLCO_TgtCridrTransDev_met[(i)]) //!< TPLLCO debug macro.
#define SET_D_TPLLCO_TgtCridrTransDev_met(i, val)	(D_TPLLCO_TgtCridrTransDev_met(i) = (val)) //!< TPLLCO debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TPLLCO_CCCEgoDistX_met
#define	D_TPLLCO_CCCEgoDistX_met (TPLLCO_VehOutPtr->D_TPLLCO_CCCEgoDistX_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCEgoDistX_met(val)	(D_TPLLCO_CCCEgoDistX_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCEgoDistY_met
#define	D_TPLLCO_CCCEgoDistY_met (TPLLCO_VehOutPtr->D_TPLLCO_CCCEgoDistY_met) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCEgoDistY_met(val)	(D_TPLLCO_CCCEgoDistY_met = (val)) //!< TPLLCO debug macro setter.

#undef	D_TPLLCO_CCCEgoYawangle_rad
#define	D_TPLLCO_CCCEgoYawangle_rad (TPLLCO_VehOutPtr->D_TPLLCO_CCCEgoYawangle_rad) //!< TPLLCO debug macro.
#define	SET_D_TPLLCO_CCCEgoYawangle_rad(val)	(D_TPLLCO_CCCEgoYawangle_rad = (val)) //!< TPLLCO debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // TPLLCO_PRIVATE_H_
