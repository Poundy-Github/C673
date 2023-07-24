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
//! @file     TCTCDC_data.h
//! @brief     (TCTCDC) Module Data Header.

#ifndef TCTCDC_DATA_H_
#define TCTCDC_DATA_H_

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
 *	TCTCDC module vehicle get function. Function gets TCTCDC vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTCDC_VehDbgPtr</b> Global static pointer to TCTCDC vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTCDC_VehDbgType* TCTCDC_VehGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTCDC_DeltaThetaEsti_rad
#define D_TCTCDC_DeltaThetaEsti_rad (TCTCDC_VehGetDbgPtr()->D_TCTCDC_DeltaThetaEsti_rad) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_DeltaThetaEsti_rad() (D_TCTCDC_DeltaThetaEsti_rad) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_DeltaThetaEsti_rad

#ifndef D_TCTCDC_DeltaThetaPT1_rad
#define D_TCTCDC_DeltaThetaPT1_rad (TCTCDC_VehGetDbgPtr()->D_TCTCDC_DeltaThetaPT1_rad) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_DeltaThetaPT1_rad() (D_TCTCDC_DeltaThetaPT1_rad) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_DeltaThetaPT1_rad

#ifndef D_TCTCDC_DeltaThetaRaw_rad
#define D_TCTCDC_DeltaThetaRaw_rad (TCTCDC_VehGetDbgPtr()->D_TCTCDC_DeltaThetaRaw_rad) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_DeltaThetaRaw_rad() (D_TCTCDC_DeltaThetaRaw_rad) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_DeltaThetaRaw_rad

#ifndef D_TCTCDC_DeltaYPT1_met
#define D_TCTCDC_DeltaYPT1_met (TCTCDC_VehGetDbgPtr()->D_TCTCDC_DeltaYPT1_met) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_DeltaYPT1_met() (D_TCTCDC_DeltaYPT1_met) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_DeltaYPT1_met

#ifndef D_TCTCDC_DeltaYRaw_met
#define D_TCTCDC_DeltaYRaw_met (TCTCDC_VehGetDbgPtr()->D_TCTCDC_DeltaYRaw_met) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_DeltaYRaw_met() (D_TCTCDC_DeltaYRaw_met) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_DeltaYRaw_met

#ifndef D_TCTCDC_QualifierService_nu
#define D_TCTCDC_QualifierService_nu (TCTCDC_VehGetDbgPtr()->D_TCTCDC_QualifierService_nu) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_QualifierService_nu() (D_TCTCDC_QualifierService_nu) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_QualifierService_nu

#ifndef D_TCTCDC_WatchdogStatus_nu
#define D_TCTCDC_WatchdogStatus_nu (TCTCDC_VehGetDbgPtr()->D_TCTCDC_WatchdogStatus_nu) //!< TCTCDC debug macro.
#define GET_D_TCTCDC_WatchdogStatus_nu() (D_TCTCDC_WatchdogStatus_nu) //!< TCTCDC debug macro getter.
#endif // D_TCTCDC_WatchdogStatus_nu

#ifndef S_TCTCDC_CtrlErrDistY_met
#define S_TCTCDC_CtrlErrDistY_met (TCTCDC_VehGetDbgPtr()->S_TCTCDC_CtrlErrDistY_met) //!< TCTCDC debug macro.
#define GET_S_TCTCDC_CtrlErrDistY_met() (S_TCTCDC_CtrlErrDistY_met) //!< TCTCDC debug macro getter.
#endif // S_TCTCDC_CtrlErrDistY_met

#ifndef S_TCTCDC_CtrlErrHeadAglPrev_rad
#define S_TCTCDC_CtrlErrHeadAglPrev_rad (TCTCDC_VehGetDbgPtr()->S_TCTCDC_CtrlErrHeadAglPrev_rad) //!< TCTCDC debug macro.
#define GET_S_TCTCDC_CtrlErrHeadAglPrev_rad() (S_TCTCDC_CtrlErrHeadAglPrev_rad) //!< TCTCDC debug macro getter.
#endif // S_TCTCDC_CtrlErrHeadAglPrev_rad

#ifndef S_TCTCDC_CtrlErrHeadAgl_rad
#define S_TCTCDC_CtrlErrHeadAgl_rad (TCTCDC_VehGetDbgPtr()->S_TCTCDC_CtrlErrHeadAgl_rad) //!< TCTCDC debug macro.
#define GET_S_TCTCDC_CtrlErrHeadAgl_rad() (S_TCTCDC_CtrlErrHeadAgl_rad) //!< TCTCDC debug macro getter.
#endif // S_TCTCDC_CtrlErrHeadAgl_rad

#ifndef S_TCTCDC_QualifierService_nu
#define S_TCTCDC_QualifierService_nu (TCTCDC_VehGetDbgPtr()->S_TCTCDC_QualifierService_nu) //!< TCTCDC debug macro.
#define GET_S_TCTCDC_QualifierService_nu() (S_TCTCDC_QualifierService_nu) //!< TCTCDC debug macro getter.
#endif // S_TCTCDC_QualifierService_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTCDC_DATA_H_
