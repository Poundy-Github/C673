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
//! @file     TCTEST_data.h
//! @brief     (TCTEST) Module Data Header.

#ifndef TCTEST_DATA_H_
#define TCTEST_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFVEH/LCFVEH_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TCTEST module vehicle get function. Function gets TCTEST vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTEST_VehDbgPtr</b> Global static pointer to TCTEST vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTEST_VehDbgType* TCTEST_VehGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTEST_CrObsCrosswindRaw_New
#define D_TCTEST_CrObsCrosswindRaw_New (TCTEST_VehGetDbgPtr()->D_TCTEST_CrObsCrosswindRaw_New) //!< TCTEST debug macro.
#define GET_D_TCTEST_CrObsCrosswindRaw_New() (D_TCTEST_CrObsCrosswindRaw_New) //!< TCTEST debug macro getter.
#endif // D_TCTEST_CrObsCrosswindRaw_New

#ifndef D_TCTEST_HdrMean_bool
#define D_TCTEST_HdrMean_bool (TCTEST_VehGetDbgPtr()->D_TCTEST_HdrMean_bool) //!< TCTEST debug macro.
#define GET_D_TCTEST_HdrMean_bool() (D_TCTEST_HdrMean_bool) //!< TCTEST debug macro getter.
#endif // D_TCTEST_HdrMean_bool

#ifndef D_TCTEST_HdrMean_perc
#define D_TCTEST_HdrMean_perc (TCTEST_VehGetDbgPtr()->D_TCTEST_HdrMean_perc) //!< TCTEST debug macro.
#define GET_D_TCTEST_HdrMean_perc() (D_TCTEST_HdrMean_perc) //!< TCTEST debug macro getter.
#endif // D_TCTEST_HdrMean_perc

#ifndef D_TCTEST_HdrMul_bool
#define D_TCTEST_HdrMul_bool (TCTEST_VehGetDbgPtr()->D_TCTEST_HdrMul_bool) //!< TCTEST debug macro.
#define GET_D_TCTEST_HdrMul_bool() (D_TCTEST_HdrMul_bool) //!< TCTEST debug macro getter.
#endif // D_TCTEST_HdrMul_bool

#ifndef D_TCTEST_HdrMul_perc
#define D_TCTEST_HdrMul_perc (TCTEST_VehGetDbgPtr()->D_TCTEST_HdrMul_perc) //!< TCTEST debug macro.
#define GET_D_TCTEST_HdrMul_perc() (D_TCTEST_HdrMul_perc) //!< TCTEST debug macro getter.
#endif // D_TCTEST_HdrMul_perc

#ifndef D_TCTEST_InPlObsCurvature_1pm
#define D_TCTEST_InPlObsCurvature_1pm (TCTEST_VehGetDbgPtr()->D_TCTEST_InPlObsCurvature_1pm) //!< TCTEST debug macro.
#define GET_D_TCTEST_InPlObsCurvature_1pm() (D_TCTEST_InPlObsCurvature_1pm) //!< TCTEST debug macro getter.
#endif // D_TCTEST_InPlObsCurvature_1pm

#ifndef D_TCTEST_InPlObsDeltaY_met
#define D_TCTEST_InPlObsDeltaY_met (TCTEST_VehGetDbgPtr()->D_TCTEST_InPlObsDeltaY_met) //!< TCTEST debug macro.
#define GET_D_TCTEST_InPlObsDeltaY_met() (D_TCTEST_InPlObsDeltaY_met) //!< TCTEST debug macro getter.
#endif // D_TCTEST_InPlObsDeltaY_met

#ifndef D_TCTEST_KObsKappa_1pm
#define D_TCTEST_KObsKappa_1pm (TCTEST_VehGetDbgPtr()->D_TCTEST_KObsKappa_1pm) //!< TCTEST debug macro.
#define GET_D_TCTEST_KObsKappa_1pm() (D_TCTEST_KObsKappa_1pm) //!< TCTEST debug macro getter.
#endif // D_TCTEST_KObsKappa_1pm

#ifndef D_TCTEST_PlObsDeltaTheta_rad
#define D_TCTEST_PlObsDeltaTheta_rad (TCTEST_VehGetDbgPtr()->D_TCTEST_PlObsDeltaTheta_rad) //!< TCTEST debug macro.
#define GET_D_TCTEST_PlObsDeltaTheta_rad() (D_TCTEST_PlObsDeltaTheta_rad) //!< TCTEST debug macro getter.
#endif // D_TCTEST_PlObsDeltaTheta_rad

#ifndef D_TCTEST_PlObsDeltaY_met
#define D_TCTEST_PlObsDeltaY_met (TCTEST_VehGetDbgPtr()->D_TCTEST_PlObsDeltaY_met) //!< TCTEST debug macro.
#define GET_D_TCTEST_PlObsDeltaY_met() (D_TCTEST_PlObsDeltaY_met) //!< TCTEST debug macro getter.
#endif // D_TCTEST_PlObsDeltaY_met

#ifndef D_TCTEST_SObsBeta_rad
#define D_TCTEST_SObsBeta_rad (TCTEST_VehGetDbgPtr()->D_TCTEST_SObsBeta_rad) //!< TCTEST debug macro.
#define GET_D_TCTEST_SObsBeta_rad() (D_TCTEST_SObsBeta_rad) //!< TCTEST debug macro getter.
#endif // D_TCTEST_SObsBeta_rad

#ifndef D_TCTEST_SObsPsiDot_rps
#define D_TCTEST_SObsPsiDot_rps (TCTEST_VehGetDbgPtr()->D_TCTEST_SObsPsiDot_rps) //!< TCTEST debug macro.
#define GET_D_TCTEST_SObsPsiDot_rps() (D_TCTEST_SObsPsiDot_rps) //!< TCTEST debug macro getter.
#endif // D_TCTEST_SObsPsiDot_rps

#ifndef D_TCTEST_SteerAngleLaDMC_rad
#define D_TCTEST_SteerAngleLaDMC_rad (TCTEST_VehGetDbgPtr()->D_TCTEST_SteerAngleLaDMC_rad) //!< TCTEST debug macro.
#define GET_D_TCTEST_SteerAngleLaDMC_rad() (D_TCTEST_SteerAngleLaDMC_rad) //!< TCTEST debug macro getter.
#endif // D_TCTEST_SteerAngleLaDMC_rad

#ifndef D_TCTEST_SteerAngleVDY_rad
#define D_TCTEST_SteerAngleVDY_rad (TCTEST_VehGetDbgPtr()->D_TCTEST_SteerAngleVDY_rad) //!< TCTEST debug macro.
#define GET_D_TCTEST_SteerAngleVDY_rad() (D_TCTEST_SteerAngleVDY_rad) //!< TCTEST debug macro getter.
#endif // D_TCTEST_SteerAngleVDY_rad

#ifndef S_TCTEST_CrObsCrosswind_New
#define S_TCTEST_CrObsCrosswind_New (TCTEST_VehGetDbgPtr()->S_TCTEST_CrObsCrosswind_New) //!< TCTEST debug macro.
#define GET_S_TCTEST_CrObsCrosswind_New() (S_TCTEST_CrObsCrosswind_New) //!< TCTEST debug macro getter.
#endif // S_TCTEST_CrObsCrosswind_New

#ifndef S_TCTEST_CurSteerAngle_rad
#define S_TCTEST_CurSteerAngle_rad (TCTEST_VehGetDbgPtr()->S_TCTEST_CurSteerAngle_rad) //!< TCTEST debug macro.
#define GET_S_TCTEST_CurSteerAngle_rad() (S_TCTEST_CurSteerAngle_rad) //!< TCTEST debug macro getter.
#endif // S_TCTEST_CurSteerAngle_rad

#ifndef S_TCTEST_KObsKappa_1pm
#define S_TCTEST_KObsKappa_1pm (TCTEST_VehGetDbgPtr()->S_TCTEST_KObsKappa_1pm) //!< TCTEST debug macro.
#define GET_S_TCTEST_KObsKappa_1pm() (S_TCTEST_KObsKappa_1pm) //!< TCTEST debug macro getter.
#endif // S_TCTEST_KObsKappa_1pm

#ifndef S_TCTEST_MccA11_nu
#define S_TCTEST_MccA11_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccA11_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccA11_nu() (S_TCTEST_MccA11_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccA11_nu

#ifndef S_TCTEST_MccA12_nu
#define S_TCTEST_MccA12_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccA12_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccA12_nu() (S_TCTEST_MccA12_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccA12_nu

#ifndef S_TCTEST_MccA21_nu
#define S_TCTEST_MccA21_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccA21_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccA21_nu() (S_TCTEST_MccA21_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccA21_nu

#ifndef S_TCTEST_MccA22_nu
#define S_TCTEST_MccA22_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccA22_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccA22_nu() (S_TCTEST_MccA22_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccA22_nu

#ifndef S_TCTEST_MccB11_nu
#define S_TCTEST_MccB11_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccB11_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccB11_nu() (S_TCTEST_MccB11_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccB11_nu

#ifndef S_TCTEST_MccB21_nu
#define S_TCTEST_MccB21_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccB21_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccB21_nu() (S_TCTEST_MccB21_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccB21_nu

#ifndef S_TCTEST_MccH11Cw_nu
#define S_TCTEST_MccH11Cw_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccH11Cw_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccH11Cw_nu() (S_TCTEST_MccH11Cw_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccH11Cw_nu

#ifndef S_TCTEST_MccH21Cw_nu
#define S_TCTEST_MccH21Cw_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_MccH21Cw_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_MccH21Cw_nu() (S_TCTEST_MccH21Cw_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_MccH21Cw_nu

#ifndef S_TCTEST_PlObsDeltaTheta_rad
#define S_TCTEST_PlObsDeltaTheta_rad (TCTEST_VehGetDbgPtr()->S_TCTEST_PlObsDeltaTheta_rad) //!< TCTEST debug macro.
#define GET_S_TCTEST_PlObsDeltaTheta_rad() (S_TCTEST_PlObsDeltaTheta_rad) //!< TCTEST debug macro getter.
#endif // S_TCTEST_PlObsDeltaTheta_rad

#ifndef S_TCTEST_PlObsDeltaY_met
#define S_TCTEST_PlObsDeltaY_met (TCTEST_VehGetDbgPtr()->S_TCTEST_PlObsDeltaY_met) //!< TCTEST debug macro.
#define GET_S_TCTEST_PlObsDeltaY_met() (S_TCTEST_PlObsDeltaY_met) //!< TCTEST debug macro getter.
#endif // S_TCTEST_PlObsDeltaY_met

#ifndef S_TCTEST_QualifierService_nu
#define S_TCTEST_QualifierService_nu (TCTEST_VehGetDbgPtr()->S_TCTEST_QualifierService_nu) //!< TCTEST debug macro.
#define GET_S_TCTEST_QualifierService_nu() (S_TCTEST_QualifierService_nu) //!< TCTEST debug macro getter.
#endif // S_TCTEST_QualifierService_nu

#ifndef S_TCTEST_SObsBeta_rad
#define S_TCTEST_SObsBeta_rad (TCTEST_VehGetDbgPtr()->S_TCTEST_SObsBeta_rad) //!< TCTEST debug macro.
#define GET_S_TCTEST_SObsBeta_rad() (S_TCTEST_SObsBeta_rad) //!< TCTEST debug macro getter.
#endif // S_TCTEST_SObsBeta_rad

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTEST_DATA_H_
