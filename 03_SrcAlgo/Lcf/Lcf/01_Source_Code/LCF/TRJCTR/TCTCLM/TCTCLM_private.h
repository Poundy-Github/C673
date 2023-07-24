/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCLM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTCLM_private.h
//! @brief     (TCTCLM) Module Private Header.

#ifndef TCTCLM_PRIVATE_H_
#define TCTCLM_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJCTR	//!< TRJCTR sub-component input macro switch.
#define TCTCLM	//!< TCTCLM module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTCLM.h"
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

#define RUNNABLE_ID_TCTCLM_VehReset		0xF0 //!< TCTCLM module reset runnable identifier.
#define RUNNABLE_ID_TCTCLM_VehProcess	0xF1 //!< TCTCLM module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TCTCLM_VehDbgType *TCTCLM_VehDbgPtr = NULL; //!< TCTCLM module vehicle debug data pointer.
void TCTCLM_VehInitDbgPtr(TCTCLM_VehDbgType *TCTCLM_VehDbgArg) { TCTCLM_VehDbgPtr = TCTCLM_VehDbgPtr == NULL ? TCTCLM_VehDbgArg : TCTCLM_VehDbgPtr; }
const TCTCLM_VehDbgType* TCTCLM_VehGetDbgPtr(void) { return (const TCTCLM_VehDbgType*) TCTCLM_VehDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTCLM_FlagTimerLastCall_nu
#define	D_TCTCLM_FlagTimerLastCall_nu (TCTCLM_VehDbgPtr->D_TCTCLM_FlagTimerLastCall_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_FlagTimerLastCall_nu(val)	(D_TCTCLM_FlagTimerLastCall_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_FrozenVehCrv_1pm
#define	D_TCTCLM_FrozenVehCrv_1pm (TCTCLM_VehDbgPtr->D_TCTCLM_FrozenVehCrv_1pm) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_FrozenVehCrv_1pm(val)	(D_TCTCLM_FrozenVehCrv_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_LimiterWthtErrCntr_nu
#define	D_TCTCLM_LimiterWthtErrCntr_nu (TCTCLM_VehDbgPtr->D_TCTCLM_LimiterWthtErrCntr_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_LimiterWthtErrCntr_nu(val)	(D_TCTCLM_LimiterWthtErrCntr_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_PlausiChkLowLimit_1pm
#define	D_TCTCLM_PlausiChkLowLimit_1pm (TCTCLM_VehDbgPtr->D_TCTCLM_PlausiChkLowLimit_1pm) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_PlausiChkLowLimit_1pm(val)	(D_TCTCLM_PlausiChkLowLimit_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_PlausiChkUpLimit_1pm
#define	D_TCTCLM_PlausiChkUpLimit_1pm (TCTCLM_VehDbgPtr->D_TCTCLM_PlausiChkUpLimit_1pm) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_PlausiChkUpLimit_1pm(val)	(D_TCTCLM_PlausiChkUpLimit_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_PlausibCheckActive_nu
#define	D_TCTCLM_PlausibCheckActive_nu (TCTCLM_VehDbgPtr->D_TCTCLM_PlausibCheckActive_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_PlausibCheckActive_nu(val)	(D_TCTCLM_PlausibCheckActive_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_PlausibCheckPrecond_nu
#define	D_TCTCLM_PlausibCheckPrecond_nu (TCTCLM_VehDbgPtr->D_TCTCLM_PlausibCheckPrecond_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_PlausibCheckPrecond_nu(val)	(D_TCTCLM_PlausibCheckPrecond_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_QuServErrMemReset_nu
#define	D_TCTCLM_QuServErrMemReset_nu (TCTCLM_VehDbgPtr->D_TCTCLM_QuServErrMemReset_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_QuServErrMemReset_nu(val)	(D_TCTCLM_QuServErrMemReset_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_QuServErrMemSet_nu
#define	D_TCTCLM_QuServErrMemSet_nu (TCTCLM_VehDbgPtr->D_TCTCLM_QuServErrMemSet_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_QuServErrMemSet_nu(val)	(D_TCTCLM_QuServErrMemSet_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_QualifierService_nu
#define	D_TCTCLM_QualifierService_nu (TCTCLM_VehDbgPtr->D_TCTCLM_QualifierService_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_QualifierService_nu(val)	(D_TCTCLM_QualifierService_nu = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_SumCtrlSignal_1pm
#define	D_TCTCLM_SumCtrlSignal_1pm (TCTCLM_VehDbgPtr->D_TCTCLM_SumCtrlSignal_1pm) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_SumCtrlSignal_1pm(val)	(D_TCTCLM_SumCtrlSignal_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_TimerValue_sec
#define	D_TCTCLM_TimerValue_sec (TCTCLM_VehDbgPtr->D_TCTCLM_TimerValue_sec) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_TimerValue_sec(val)	(D_TCTCLM_TimerValue_sec = (val)) //!< TCTCLM debug macro setter.

#undef	D_TCTCLM_UnplsblDrctnOfRqst_nu
#define	D_TCTCLM_UnplsblDrctnOfRqst_nu (TCTCLM_VehDbgPtr->D_TCTCLM_UnplsblDrctnOfRqst_nu) //!< TCTCLM debug macro.
#define	SET_D_TCTCLM_UnplsblDrctnOfRqst_nu(val)	(D_TCTCLM_UnplsblDrctnOfRqst_nu = (val)) //!< TCTCLM debug macro setter.

#undef	S_TCTCLM_DeltaFCmd_deg
#define	S_TCTCLM_DeltaFCmd_deg (TCTCLM_VehDbgPtr->S_TCTCLM_DeltaFCmd_deg) //!< TCTCLM debug macro.
#define	SET_S_TCTCLM_DeltaFCmd_deg(val)	(S_TCTCLM_DeltaFCmd_deg = (val)) //!< TCTCLM debug macro setter.

#undef	S_TCTCLM_FbcDc_1pm
#define	S_TCTCLM_FbcDc_1pm (TCTCLM_VehDbgPtr->S_TCTCLM_FbcDc_1pm) //!< TCTCLM debug macro.
#define	SET_S_TCTCLM_FbcDc_1pm(val)	(S_TCTCLM_FbcDc_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	S_TCTCLM_Ffc_1pm
#define	S_TCTCLM_Ffc_1pm (TCTCLM_VehDbgPtr->S_TCTCLM_Ffc_1pm) //!< TCTCLM debug macro.
#define	SET_S_TCTCLM_Ffc_1pm(val)	(S_TCTCLM_Ffc_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	S_TCTCLM_LimiterWarning_nu
#define	S_TCTCLM_LimiterWarning_nu (TCTCLM_VehDbgPtr->S_TCTCLM_LimiterWarning_nu) //!< TCTCLM debug macro.
#define	SET_S_TCTCLM_LimiterWarning_nu(val)	(S_TCTCLM_LimiterWarning_nu = (val)) //!< TCTCLM debug macro setter.

#undef	S_TCTCLM_Limiter_TgtCrv_1pm
#define	S_TCTCLM_Limiter_TgtCrv_1pm (TCTCLM_VehDbgPtr->S_TCTCLM_Limiter_TgtCrv_1pm) //!< TCTCLM debug macro.
#define	SET_S_TCTCLM_Limiter_TgtCrv_1pm(val)	(S_TCTCLM_Limiter_TgtCrv_1pm = (val)) //!< TCTCLM debug macro setter.

#undef	S_TCTCLM_QuServTrajCtr_nu
#define	S_TCTCLM_QuServTrajCtr_nu (TCTCLM_VehDbgPtr->S_TCTCLM_QuServTrajCtr_nu) //!< TCTCLM debug macro.
#define	SET_S_TCTCLM_QuServTrajCtr_nu(val)	(S_TCTCLM_QuServTrajCtr_nu = (val)) //!< TCTCLM debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTCLM_PRIVATE_H_
