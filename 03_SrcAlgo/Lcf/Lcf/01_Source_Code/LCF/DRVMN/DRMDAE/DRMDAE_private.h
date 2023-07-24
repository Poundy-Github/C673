/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMDAE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMDAE_private.h
//! @brief     (DRMDAE) Module Private Header.

#ifndef DRMDAE_PRIVATE_H_
#define DRMDAE_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define DRVMN	//!< DRVMN sub-component input macro switch.
#define DRMDAE	//!< DRMDAE module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRMDAE.h"
#include "Bitop.h"  //MFC5J3
#include "ecmath.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DRMDAE_VehReset		0xF0 //!< DRMDAE module reset runnable identifier.
#define RUNNABLE_ID_DRMDAE_VehProcess	0xF1 //!< DRMDAE module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DRMDAE_VehDbgType *DRMDAE_VehDbgPtr = NULL; //!< DRMDAE module vehicle debug data pointer.
void DRMDAE_VehInitDbgPtr(DRMDAE_VehDbgType *DRMDAE_VehDbgArg) { DRMDAE_VehDbgPtr = DRMDAE_VehDbgPtr == NULL ? DRMDAE_VehDbgArg : DRMDAE_VehDbgPtr; }
const DRMDAE_VehDbgType* DRMDAE_VehGetDbgPtr(void) { return (const DRMDAE_VehDbgType*) DRMDAE_VehDbgPtr; }

static DRMDAE_VehOutType *DRMDAE_VehOutPtr = NULL; //!< DRMDAE module vehicle output data pointer.
void DRMDAE_VehInitOutPtr(DRMDAE_VehOutType *DRMDAE_VehOutArg) { DRMDAE_VehOutPtr = DRMDAE_VehOutPtr == NULL ? DRMDAE_VehOutArg : DRMDAE_VehOutPtr; }
const DRMDAE_VehOutType* DRMDAE_VehGetOutPtr(void) { return (const DRMDAE_VehOutType*) DRMDAE_VehOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_DRMDAE_AbuseWarning_bool
#define	S_DRMDAE_AbuseWarning_bool (DRMDAE_VehDbgPtr->S_DRMDAE_AbuseWarning_bool) //!< DRMDAE debug macro.
#define	SET_S_DRMDAE_AbuseWarning_bool(val)	(S_DRMDAE_AbuseWarning_bool = (val)) //!< DRMDAE debug macro setter.

#undef	S_DRMDAE_SysWarning_nu
#define	S_DRMDAE_SysWarning_nu (DRMDAE_VehDbgPtr->S_DRMDAE_SysWarning_nu) //!< DRMDAE debug macro.
#define	SET_S_DRMDAE_SysWarning_nu(val)	(S_DRMDAE_SysWarning_nu = (val)) //!< DRMDAE debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DRMDAE_AbuseWarnDuration_sec
#define	D_DRMDAE_AbuseWarnDuration_sec (DRMDAE_VehOutPtr->D_DRMDAE_AbuseWarnDuration_sec) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_AbuseWarnDuration_sec(val)	(D_DRMDAE_AbuseWarnDuration_sec = (val)) //!< DRMDAE debug macro setter.

#undef	D_DRMDAE_ActToi_nu
#define	D_DRMDAE_ActToi_nu (DRMDAE_VehOutPtr->D_DRMDAE_ActToi_nu) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_ActToi_nu(val)	(D_DRMDAE_ActToi_nu = (val)) //!< DRMDAE debug macro setter.

#undef	D_DRMDAE_CriticalEventsNo_nu
#define	D_DRMDAE_CriticalEventsNo_nu (DRMDAE_VehOutPtr->D_DRMDAE_CriticalEventsNo_nu) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_CriticalEventsNo_nu(val)	(D_DRMDAE_CriticalEventsNo_nu = (val)) //!< DRMDAE debug macro setter.

#undef	D_DRMDAE_ElapsedTime_sec
#define	D_DRMDAE_ElapsedTime_sec (DRMDAE_VehOutPtr->D_DRMDAE_ElapsedTime_sec) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_ElapsedTime_sec(val)	(D_DRMDAE_ElapsedTime_sec = (val)) //!< DRMDAE debug macro setter.

#undef	D_DRMDAE_HoffTrigger_nu
#define	D_DRMDAE_HoffTrigger_nu (DRMDAE_VehOutPtr->D_DRMDAE_HoffTrigger_nu) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_HoffTrigger_nu(val)	(D_DRMDAE_HoffTrigger_nu = (val)) //!< DRMDAE debug macro setter.

#undef	D_DRMDAE_ResetWarnCnt_nu
#define	D_DRMDAE_ResetWarnCnt_nu (DRMDAE_VehOutPtr->D_DRMDAE_ResetWarnCnt_nu) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_ResetWarnCnt_nu(val)	(D_DRMDAE_ResetWarnCnt_nu = (val)) //!< DRMDAE debug macro setter.

#undef	D_DRMDAE_SpeedOk_bool
#define	D_DRMDAE_SpeedOk_bool (DRMDAE_VehOutPtr->D_DRMDAE_SpeedOk_bool) //!< DRMDAE debug macro.
#define	SET_D_DRMDAE_SpeedOk_bool(val)	(D_DRMDAE_SpeedOk_bool = (val)) //!< DRMDAE debug macro setter.

#undef	S_DRMDAE_DrvAttentionConf_perc
#define	S_DRMDAE_DrvAttentionConf_perc (DRMDAE_VehOutPtr->S_DRMDAE_DrvAttentionConf_perc) //!< DRMDAE debug macro.
#define	SET_S_DRMDAE_DrvAttentionConf_perc(val)	(S_DRMDAE_DrvAttentionConf_perc = (val)) //!< DRMDAE debug macro setter.

#undef	S_DRMDAE_DrvAttention_perc
#define	S_DRMDAE_DrvAttention_perc (DRMDAE_VehOutPtr->S_DRMDAE_DrvAttention_perc) //!< DRMDAE debug macro.
#define	SET_S_DRMDAE_DrvAttention_perc(val)	(S_DRMDAE_DrvAttention_perc = (val)) //!< DRMDAE debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // DRMDAE_PRIVATE_H_
