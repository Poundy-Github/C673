/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTEST
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TCTEST_private.h
//! @brief     (TCTEST) Module Private Header.

#ifndef TCTEST_PRIVATE_H_
#define TCTEST_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define TRJCTR	//!< TRJCTR sub-component input macro switch.
#define TCTEST	//!< TCTEST module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "TCTEST.h"
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

#define RUNNABLE_ID_TCTEST_VehReset		0xF0 //!< TCTEST module reset runnable identifier.
#define RUNNABLE_ID_TCTEST_VehProcess	0xF1 //!< TCTEST module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static TCTEST_VehDbgType *TCTEST_VehDbgPtr = NULL; //!< TCTEST module vehicle debug data pointer.
void TCTEST_VehInitDbgPtr(TCTEST_VehDbgType *TCTEST_VehDbgArg) { TCTEST_VehDbgPtr = TCTEST_VehDbgPtr == NULL ? TCTEST_VehDbgArg : TCTEST_VehDbgPtr; }
const TCTEST_VehDbgType* TCTEST_VehGetDbgPtr(void) { return (const TCTEST_VehDbgType*) TCTEST_VehDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_TCTEST_CrObsCrosswindRaw_New
#define	D_TCTEST_CrObsCrosswindRaw_New (TCTEST_VehDbgPtr->D_TCTEST_CrObsCrosswindRaw_New) //!< TCTEST debug macro.
#define	SET_D_TCTEST_CrObsCrosswindRaw_New(val)	(D_TCTEST_CrObsCrosswindRaw_New = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_HdrMean_bool
#define	D_TCTEST_HdrMean_bool (TCTEST_VehDbgPtr->D_TCTEST_HdrMean_bool) //!< TCTEST debug macro.
#define	SET_D_TCTEST_HdrMean_bool(val)	(D_TCTEST_HdrMean_bool = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_HdrMean_perc
#define	D_TCTEST_HdrMean_perc (TCTEST_VehDbgPtr->D_TCTEST_HdrMean_perc) //!< TCTEST debug macro.
#define	SET_D_TCTEST_HdrMean_perc(val)	(D_TCTEST_HdrMean_perc = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_HdrMul_bool
#define	D_TCTEST_HdrMul_bool (TCTEST_VehDbgPtr->D_TCTEST_HdrMul_bool) //!< TCTEST debug macro.
#define	SET_D_TCTEST_HdrMul_bool(val)	(D_TCTEST_HdrMul_bool = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_HdrMul_perc
#define	D_TCTEST_HdrMul_perc (TCTEST_VehDbgPtr->D_TCTEST_HdrMul_perc) //!< TCTEST debug macro.
#define	SET_D_TCTEST_HdrMul_perc(val)	(D_TCTEST_HdrMul_perc = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_InPlObsCurvature_1pm
#define	D_TCTEST_InPlObsCurvature_1pm (TCTEST_VehDbgPtr->D_TCTEST_InPlObsCurvature_1pm) //!< TCTEST debug macro.
#define	SET_D_TCTEST_InPlObsCurvature_1pm(val)	(D_TCTEST_InPlObsCurvature_1pm = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_InPlObsDeltaY_met
#define	D_TCTEST_InPlObsDeltaY_met (TCTEST_VehDbgPtr->D_TCTEST_InPlObsDeltaY_met) //!< TCTEST debug macro.
#define	SET_D_TCTEST_InPlObsDeltaY_met(val)	(D_TCTEST_InPlObsDeltaY_met = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_KObsKappa_1pm
#define	D_TCTEST_KObsKappa_1pm (TCTEST_VehDbgPtr->D_TCTEST_KObsKappa_1pm) //!< TCTEST debug macro.
#define	SET_D_TCTEST_KObsKappa_1pm(val)	(D_TCTEST_KObsKappa_1pm = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_PlObsDeltaTheta_rad
#define	D_TCTEST_PlObsDeltaTheta_rad (TCTEST_VehDbgPtr->D_TCTEST_PlObsDeltaTheta_rad) //!< TCTEST debug macro.
#define	SET_D_TCTEST_PlObsDeltaTheta_rad(val)	(D_TCTEST_PlObsDeltaTheta_rad = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_PlObsDeltaY_met
#define	D_TCTEST_PlObsDeltaY_met (TCTEST_VehDbgPtr->D_TCTEST_PlObsDeltaY_met) //!< TCTEST debug macro.
#define	SET_D_TCTEST_PlObsDeltaY_met(val)	(D_TCTEST_PlObsDeltaY_met = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_SObsBeta_rad
#define	D_TCTEST_SObsBeta_rad (TCTEST_VehDbgPtr->D_TCTEST_SObsBeta_rad) //!< TCTEST debug macro.
#define	SET_D_TCTEST_SObsBeta_rad(val)	(D_TCTEST_SObsBeta_rad = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_SObsPsiDot_rps
#define	D_TCTEST_SObsPsiDot_rps (TCTEST_VehDbgPtr->D_TCTEST_SObsPsiDot_rps) //!< TCTEST debug macro.
#define	SET_D_TCTEST_SObsPsiDot_rps(val)	(D_TCTEST_SObsPsiDot_rps = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_SteerAngleLaDMC_rad
#define	D_TCTEST_SteerAngleLaDMC_rad (TCTEST_VehDbgPtr->D_TCTEST_SteerAngleLaDMC_rad) //!< TCTEST debug macro.
#define	SET_D_TCTEST_SteerAngleLaDMC_rad(val)	(D_TCTEST_SteerAngleLaDMC_rad = (val)) //!< TCTEST debug macro setter.

#undef	D_TCTEST_SteerAngleVDY_rad
#define	D_TCTEST_SteerAngleVDY_rad (TCTEST_VehDbgPtr->D_TCTEST_SteerAngleVDY_rad) //!< TCTEST debug macro.
#define	SET_D_TCTEST_SteerAngleVDY_rad(val)	(D_TCTEST_SteerAngleVDY_rad = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_CrObsCrosswind_New
#define	S_TCTEST_CrObsCrosswind_New (TCTEST_VehDbgPtr->S_TCTEST_CrObsCrosswind_New) //!< TCTEST debug macro.
#define	SET_S_TCTEST_CrObsCrosswind_New(val)	(S_TCTEST_CrObsCrosswind_New = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_CurSteerAngle_rad
#define	S_TCTEST_CurSteerAngle_rad (TCTEST_VehDbgPtr->S_TCTEST_CurSteerAngle_rad) //!< TCTEST debug macro.
#define	SET_S_TCTEST_CurSteerAngle_rad(val)	(S_TCTEST_CurSteerAngle_rad = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_KObsKappa_1pm
#define	S_TCTEST_KObsKappa_1pm (TCTEST_VehDbgPtr->S_TCTEST_KObsKappa_1pm) //!< TCTEST debug macro.
#define	SET_S_TCTEST_KObsKappa_1pm(val)	(S_TCTEST_KObsKappa_1pm = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccA11_nu
#define	S_TCTEST_MccA11_nu (TCTEST_VehDbgPtr->S_TCTEST_MccA11_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccA11_nu(val)	(S_TCTEST_MccA11_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccA12_nu
#define	S_TCTEST_MccA12_nu (TCTEST_VehDbgPtr->S_TCTEST_MccA12_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccA12_nu(val)	(S_TCTEST_MccA12_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccA21_nu
#define	S_TCTEST_MccA21_nu (TCTEST_VehDbgPtr->S_TCTEST_MccA21_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccA21_nu(val)	(S_TCTEST_MccA21_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccA22_nu
#define	S_TCTEST_MccA22_nu (TCTEST_VehDbgPtr->S_TCTEST_MccA22_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccA22_nu(val)	(S_TCTEST_MccA22_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccB11_nu
#define	S_TCTEST_MccB11_nu (TCTEST_VehDbgPtr->S_TCTEST_MccB11_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccB11_nu(val)	(S_TCTEST_MccB11_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccB21_nu
#define	S_TCTEST_MccB21_nu (TCTEST_VehDbgPtr->S_TCTEST_MccB21_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccB21_nu(val)	(S_TCTEST_MccB21_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccH11Cw_nu
#define	S_TCTEST_MccH11Cw_nu (TCTEST_VehDbgPtr->S_TCTEST_MccH11Cw_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccH11Cw_nu(val)	(S_TCTEST_MccH11Cw_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_MccH21Cw_nu
#define	S_TCTEST_MccH21Cw_nu (TCTEST_VehDbgPtr->S_TCTEST_MccH21Cw_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_MccH21Cw_nu(val)	(S_TCTEST_MccH21Cw_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_PlObsDeltaTheta_rad
#define	S_TCTEST_PlObsDeltaTheta_rad (TCTEST_VehDbgPtr->S_TCTEST_PlObsDeltaTheta_rad) //!< TCTEST debug macro.
#define	SET_S_TCTEST_PlObsDeltaTheta_rad(val)	(S_TCTEST_PlObsDeltaTheta_rad = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_PlObsDeltaY_met
#define	S_TCTEST_PlObsDeltaY_met (TCTEST_VehDbgPtr->S_TCTEST_PlObsDeltaY_met) //!< TCTEST debug macro.
#define	SET_S_TCTEST_PlObsDeltaY_met(val)	(S_TCTEST_PlObsDeltaY_met = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_QualifierService_nu
#define	S_TCTEST_QualifierService_nu (TCTEST_VehDbgPtr->S_TCTEST_QualifierService_nu) //!< TCTEST debug macro.
#define	SET_S_TCTEST_QualifierService_nu(val)	(S_TCTEST_QualifierService_nu = (val)) //!< TCTEST debug macro setter.

#undef	S_TCTEST_SObsBeta_rad
#define	S_TCTEST_SObsBeta_rad (TCTEST_VehDbgPtr->S_TCTEST_SObsBeta_rad) //!< TCTEST debug macro.
#define	SET_S_TCTEST_SObsBeta_rad(val)	(S_TCTEST_SObsBeta_rad = (val)) //!< TCTEST debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTEST_PRIVATE_H_
