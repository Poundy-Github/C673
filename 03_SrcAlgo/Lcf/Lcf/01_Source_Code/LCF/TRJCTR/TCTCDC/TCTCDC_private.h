/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCDC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTCDC_private.h
//! @brief     (TCTCDC) Module Private Header.

#ifndef TCTCDC_PRIVATE_H_
#define TCTCDC_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJCTR	//!< TRJCTR sub-component input macro switch.
#define TCTCDC	//!< TCTCDC module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTCDC.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TCTCDC_VehReset		0xF0 //!< TCTCDC module reset runnable identifier.
#define RUNNABLE_ID_TCTCDC_VehProcess	0xF1 //!< TCTCDC module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TCTCDC_VehDbgType *TCTCDC_VehDbgPtr = NULL; //!< TCTCDC module vehicle debug data pointer.
void TCTCDC_VehInitDbgPtr(TCTCDC_VehDbgType *TCTCDC_VehDbgArg) { TCTCDC_VehDbgPtr = TCTCDC_VehDbgPtr == NULL ? TCTCDC_VehDbgArg : TCTCDC_VehDbgPtr; }
const TCTCDC_VehDbgType* TCTCDC_VehGetDbgPtr(void) { return (const TCTCDC_VehDbgType*) TCTCDC_VehDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTCDC_DeltaThetaEsti_rad
#define	D_TCTCDC_DeltaThetaEsti_rad (TCTCDC_VehDbgPtr->D_TCTCDC_DeltaThetaEsti_rad) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_DeltaThetaEsti_rad(val)	(D_TCTCDC_DeltaThetaEsti_rad = (val)) //!< TCTCDC debug macro setter.

#undef	D_TCTCDC_DeltaThetaPT1_rad
#define	D_TCTCDC_DeltaThetaPT1_rad (TCTCDC_VehDbgPtr->D_TCTCDC_DeltaThetaPT1_rad) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_DeltaThetaPT1_rad(val)	(D_TCTCDC_DeltaThetaPT1_rad = (val)) //!< TCTCDC debug macro setter.

#undef	D_TCTCDC_DeltaThetaRaw_rad
#define	D_TCTCDC_DeltaThetaRaw_rad (TCTCDC_VehDbgPtr->D_TCTCDC_DeltaThetaRaw_rad) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_DeltaThetaRaw_rad(val)	(D_TCTCDC_DeltaThetaRaw_rad = (val)) //!< TCTCDC debug macro setter.

#undef	D_TCTCDC_DeltaYPT1_met
#define	D_TCTCDC_DeltaYPT1_met (TCTCDC_VehDbgPtr->D_TCTCDC_DeltaYPT1_met) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_DeltaYPT1_met(val)	(D_TCTCDC_DeltaYPT1_met = (val)) //!< TCTCDC debug macro setter.

#undef	D_TCTCDC_DeltaYRaw_met
#define	D_TCTCDC_DeltaYRaw_met (TCTCDC_VehDbgPtr->D_TCTCDC_DeltaYRaw_met) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_DeltaYRaw_met(val)	(D_TCTCDC_DeltaYRaw_met = (val)) //!< TCTCDC debug macro setter.

#undef	D_TCTCDC_QualifierService_nu
#define	D_TCTCDC_QualifierService_nu (TCTCDC_VehDbgPtr->D_TCTCDC_QualifierService_nu) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_QualifierService_nu(val)	(D_TCTCDC_QualifierService_nu = (val)) //!< TCTCDC debug macro setter.

#undef	D_TCTCDC_WatchdogStatus_nu
#define	D_TCTCDC_WatchdogStatus_nu (TCTCDC_VehDbgPtr->D_TCTCDC_WatchdogStatus_nu) //!< TCTCDC debug macro.
#define	SET_D_TCTCDC_WatchdogStatus_nu(val)	(D_TCTCDC_WatchdogStatus_nu = (val)) //!< TCTCDC debug macro setter.

#undef	S_TCTCDC_CtrlErrDistY_met
#define	S_TCTCDC_CtrlErrDistY_met (TCTCDC_VehDbgPtr->S_TCTCDC_CtrlErrDistY_met) //!< TCTCDC debug macro.
#define	SET_S_TCTCDC_CtrlErrDistY_met(val)	(S_TCTCDC_CtrlErrDistY_met = (val)) //!< TCTCDC debug macro setter.

#undef	S_TCTCDC_CtrlErrHeadAglPrev_rad
#define	S_TCTCDC_CtrlErrHeadAglPrev_rad (TCTCDC_VehDbgPtr->S_TCTCDC_CtrlErrHeadAglPrev_rad) //!< TCTCDC debug macro.
#define	SET_S_TCTCDC_CtrlErrHeadAglPrev_rad(val)	(S_TCTCDC_CtrlErrHeadAglPrev_rad = (val)) //!< TCTCDC debug macro setter.

#undef	S_TCTCDC_CtrlErrHeadAgl_rad
#define	S_TCTCDC_CtrlErrHeadAgl_rad (TCTCDC_VehDbgPtr->S_TCTCDC_CtrlErrHeadAgl_rad) //!< TCTCDC debug macro.
#define	SET_S_TCTCDC_CtrlErrHeadAgl_rad(val)	(S_TCTCDC_CtrlErrHeadAgl_rad = (val)) //!< TCTCDC debug macro setter.

#undef	S_TCTCDC_QualifierService_nu
#define	S_TCTCDC_QualifierService_nu (TCTCDC_VehDbgPtr->S_TCTCDC_QualifierService_nu) //!< TCTCDC debug macro.
#define	SET_S_TCTCDC_QualifierService_nu(val)	(S_TCTCDC_QualifierService_nu = (val)) //!< TCTCDC debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTCDC_PRIVATE_H_
