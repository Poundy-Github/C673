/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTDTE
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTDTE_private.h
//! @brief     (TCTDTE) Module Private Header.

#ifndef TCTDTE_PRIVATE_H_
#define TCTDTE_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJCTR	//!< TRJCTR sub-component input macro switch.
#define TCTDTE	//!< TCTDTE module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTDTE.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_TCTDTE_VehReset		0xF0 //!< TCTDTE module reset runnable identifier.
#define RUNNABLE_ID_TCTDTE_VehProcess	0xF1 //!< TCTDTE module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TCTDTE_VehDbgType *TCTDTE_VehDbgPtr = NULL; //!< TCTDTE module vehicle debug data pointer.
void TCTDTE_VehInitDbgPtr(TCTDTE_VehDbgType *TCTDTE_VehDbgArg) { TCTDTE_VehDbgPtr = TCTDTE_VehDbgPtr == NULL ? TCTDTE_VehDbgArg : TCTDTE_VehDbgPtr; }
const TCTDTE_VehDbgType* TCTDTE_VehGetDbgPtr(void) { return (const TCTDTE_VehDbgType*) TCTDTE_VehDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTDTE_CrvReqBnkAglComp_1pm
#define	D_TCTDTE_CrvReqBnkAglComp_1pm (TCTDTE_VehDbgPtr->D_TCTDTE_CrvReqBnkAglComp_1pm) //!< TCTDTE debug macro.
#define	SET_D_TCTDTE_CrvReqBnkAglComp_1pm(val)	(D_TCTDTE_CrvReqBnkAglComp_1pm = (val)) //!< TCTDTE debug macro setter.

#undef	D_TCTDTE_CrvReqDistrbStmTf_1pm
#define	D_TCTDTE_CrvReqDistrbStmTf_1pm (TCTDTE_VehDbgPtr->D_TCTDTE_CrvReqDistrbStmTf_1pm) //!< TCTDTE debug macro.
#define	SET_D_TCTDTE_CrvReqDistrbStmTf_1pm(val)	(D_TCTDTE_CrvReqDistrbStmTf_1pm = (val)) //!< TCTDTE debug macro setter.

#undef	D_TCTDTE_DeltaSetBnkAglComp_rad
#define	D_TCTDTE_DeltaSetBnkAglComp_rad (TCTDTE_VehDbgPtr->D_TCTDTE_DeltaSetBnkAglComp_rad) //!< TCTDTE debug macro.
#define	SET_D_TCTDTE_DeltaSetBnkAglComp_rad(val)	(D_TCTDTE_DeltaSetBnkAglComp_rad = (val)) //!< TCTDTE debug macro setter.

#undef	D_TCTDTE_DeltaSetCroWiComp_deg
#define	D_TCTDTE_DeltaSetCroWiComp_deg (TCTDTE_VehDbgPtr->D_TCTDTE_DeltaSetCroWiComp_deg) //!< TCTDTE debug macro.
#define	SET_D_TCTDTE_DeltaSetCroWiComp_deg(val)	(D_TCTDTE_DeltaSetCroWiComp_deg = (val)) //!< TCTDTE debug macro setter.

#undef	D_TCTDTE_DeltaSetCroWiComp_rad
#define	D_TCTDTE_DeltaSetCroWiComp_rad (TCTDTE_VehDbgPtr->D_TCTDTE_DeltaSetCroWiComp_rad) //!< TCTDTE debug macro.
#define	SET_D_TCTDTE_DeltaSetCroWiComp_rad(val)	(D_TCTDTE_DeltaSetCroWiComp_rad = (val)) //!< TCTDTE debug macro setter.

#undef	D_TCTDTE_DeltaSetDstrbStmTf_rad
#define	D_TCTDTE_DeltaSetDstrbStmTf_rad (TCTDTE_VehDbgPtr->D_TCTDTE_DeltaSetDstrbStmTf_rad) //!< TCTDTE debug macro.
#define	SET_D_TCTDTE_DeltaSetDstrbStmTf_rad(val)	(D_TCTDTE_DeltaSetDstrbStmTf_rad = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_CrvReqBnkAglComp_1pm
#define	S_TCTDTE_CrvReqBnkAglComp_1pm (TCTDTE_VehDbgPtr->S_TCTDTE_CrvReqBnkAglComp_1pm) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_CrvReqBnkAglComp_1pm(val)	(S_TCTDTE_CrvReqBnkAglComp_1pm = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_CrvReqDstrbComp_1pm
#define	S_TCTDTE_CrvReqDstrbComp_1pm (TCTDTE_VehDbgPtr->S_TCTDTE_CrvReqDstrbComp_1pm) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_CrvReqDstrbComp_1pm(val)	(S_TCTDTE_CrvReqDstrbComp_1pm = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_DeltaSetBnkAglComp_rad
#define	S_TCTDTE_DeltaSetBnkAglComp_rad (TCTDTE_VehDbgPtr->S_TCTDTE_DeltaSetBnkAglComp_rad) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_DeltaSetBnkAglComp_rad(val)	(S_TCTDTE_DeltaSetBnkAglComp_rad = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_DeltaSetCroWiComp_rad
#define	S_TCTDTE_DeltaSetCroWiComp_rad (TCTDTE_VehDbgPtr->S_TCTDTE_DeltaSetCroWiComp_rad) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_DeltaSetCroWiComp_rad(val)	(S_TCTDTE_DeltaSetCroWiComp_rad = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_DeltaSetDstrbComp_rad
#define	S_TCTDTE_DeltaSetDstrbComp_rad (TCTDTE_VehDbgPtr->S_TCTDTE_DeltaSetDstrbComp_rad) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_DeltaSetDstrbComp_rad(val)	(S_TCTDTE_DeltaSetDstrbComp_rad = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_MccGLaDmcDenS0_nu
#define	S_TCTDTE_MccGLaDmcDenS0_nu (TCTDTE_VehDbgPtr->S_TCTDTE_MccGLaDmcDenS0_nu) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_MccGLaDmcDenS0_nu(val)	(S_TCTDTE_MccGLaDmcDenS0_nu = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_MccGLaDmcDenS1_nu
#define	S_TCTDTE_MccGLaDmcDenS1_nu (TCTDTE_VehDbgPtr->S_TCTDTE_MccGLaDmcDenS1_nu) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_MccGLaDmcDenS1_nu(val)	(S_TCTDTE_MccGLaDmcDenS1_nu = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_MccGLaDmcDenS2_nu
#define	S_TCTDTE_MccGLaDmcDenS2_nu (TCTDTE_VehDbgPtr->S_TCTDTE_MccGLaDmcDenS2_nu) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_MccGLaDmcDenS2_nu(val)	(S_TCTDTE_MccGLaDmcDenS2_nu = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_MccGLaDmcDenS3_nu
#define	S_TCTDTE_MccGLaDmcDenS3_nu (TCTDTE_VehDbgPtr->S_TCTDTE_MccGLaDmcDenS3_nu) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_MccGLaDmcDenS3_nu(val)	(S_TCTDTE_MccGLaDmcDenS3_nu = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_MccGLaDmcNumS0_nu
#define	S_TCTDTE_MccGLaDmcNumS0_nu (TCTDTE_VehDbgPtr->S_TCTDTE_MccGLaDmcNumS0_nu) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_MccGLaDmcNumS0_nu(val)	(S_TCTDTE_MccGLaDmcNumS0_nu = (val)) //!< TCTDTE debug macro setter.

#undef	S_TCTDTE_MccGLaDmcNumS1_nu
#define	S_TCTDTE_MccGLaDmcNumS1_nu (TCTDTE_VehDbgPtr->S_TCTDTE_MccGLaDmcNumS1_nu) //!< TCTDTE debug macro.
#define	SET_S_TCTDTE_MccGLaDmcNumS1_nu(val)	(S_TCTDTE_MccGLaDmcNumS1_nu = (val)) //!< TCTDTE debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTDTE_PRIVATE_H_
