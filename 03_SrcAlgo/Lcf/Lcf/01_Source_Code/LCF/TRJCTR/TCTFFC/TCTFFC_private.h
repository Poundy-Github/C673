/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTFFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTFFC_private.h
//! @brief     (TCTFFC) Module Private Header.

#ifndef TCTFFC_PRIVATE_H_
#define TCTFFC_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJCTR	//!< TRJCTR sub-component input macro switch.
#define TCTFFC	//!< TCTFFC module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTFFC.h"
#include "Bitop.h"  //MFC5J3
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TCTFFC_VehReset		0xF0 //!< TCTFFC module reset runnable identifier.
#define RUNNABLE_ID_TCTFFC_VehProcess	0xF1 //!< TCTFFC module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TCTFFC_VehDbgType *TCTFFC_VehDbgPtr = NULL; //!< TCTFFC module vehicle debug data pointer.
void TCTFFC_VehInitDbgPtr(TCTFFC_VehDbgType *TCTFFC_VehDbgArg) { TCTFFC_VehDbgPtr = TCTFFC_VehDbgPtr == NULL ? TCTFFC_VehDbgArg : TCTFFC_VehDbgPtr; }
const TCTFFC_VehDbgType* TCTFFC_VehGetDbgPtr(void) { return (const TCTFFC_VehDbgType*) TCTFFC_VehDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTFFC_DiffMeasEstKappa_1pm
#define	D_TCTFFC_DiffMeasEstKappa_1pm (TCTFFC_VehDbgPtr->D_TCTFFC_DiffMeasEstKappa_1pm) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_DiffMeasEstKappa_1pm(val)	(D_TCTFFC_DiffMeasEstKappa_1pm = (val)) //!< TCTFFC debug macro setter.

#undef	D_TCTFFC_DynFfcDecel_1pm
#define	D_TCTFFC_DynFfcDecel_1pm (TCTFFC_VehDbgPtr->D_TCTFFC_DynFfcDecel_1pm) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_DynFfcDecel_1pm(val)	(D_TCTFFC_DynFfcDecel_1pm = (val)) //!< TCTFFC debug macro setter.

#undef	D_TCTFFC_DynFfcGeneral_1pm
#define	D_TCTFFC_DynFfcGeneral_1pm (TCTFFC_VehDbgPtr->D_TCTFFC_DynFfcGeneral_1pm) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_DynFfcGeneral_1pm(val)	(D_TCTFFC_DynFfcGeneral_1pm = (val)) //!< TCTFFC debug macro setter.

#undef	D_TCTFFC_DynFfcUpDwnHill_1pm
#define	D_TCTFFC_DynFfcUpDwnHill_1pm (TCTFFC_VehDbgPtr->D_TCTFFC_DynFfcUpDwnHill_1pm) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_DynFfcUpDwnHill_1pm(val)	(D_TCTFFC_DynFfcUpDwnHill_1pm = (val)) //!< TCTFFC debug macro setter.

#undef	D_TCTFFC_DynFfc_1pm
#define	D_TCTFFC_DynFfc_1pm (TCTFFC_VehDbgPtr->D_TCTFFC_DynFfc_1pm) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_DynFfc_1pm(val)	(D_TCTFFC_DynFfc_1pm = (val)) //!< TCTFFC debug macro setter.

#undef	D_TCTFFC_DynGainPrecFulfilled_nu
#define	D_TCTFFC_DynGainPrecFulfilled_nu (TCTFFC_VehDbgPtr->D_TCTFFC_DynGainPrecFulfilled_nu) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_DynGainPrecFulfilled_nu(val)	(D_TCTFFC_DynGainPrecFulfilled_nu = (val)) //!< TCTFFC debug macro setter.

#undef	D_TCTFFC_TrajTgtCrvFilt_1pm
#define	D_TCTFFC_TrajTgtCrvFilt_1pm (TCTFFC_VehDbgPtr->D_TCTFFC_TrajTgtCrvFilt_1pm) //!< TCTFFC debug macro.
#define	SET_D_TCTFFC_TrajTgtCrvFilt_1pm(val)	(D_TCTFFC_TrajTgtCrvFilt_1pm = (val)) //!< TCTFFC debug macro setter.

#undef	S_TCTFFC_Crv_1pm
#define	S_TCTFFC_Crv_1pm (TCTFFC_VehDbgPtr->S_TCTFFC_Crv_1pm) //!< TCTFFC debug macro.
#define	SET_S_TCTFFC_Crv_1pm(val)	(S_TCTFFC_Crv_1pm = (val)) //!< TCTFFC debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTFFC_PRIVATE_H_
