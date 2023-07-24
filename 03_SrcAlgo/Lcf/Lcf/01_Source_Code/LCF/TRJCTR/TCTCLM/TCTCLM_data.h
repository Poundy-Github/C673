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
//! @file     TCTCLM_data.h
//! @brief     (TCTCLM) Module Data Header.

#ifndef TCTCLM_DATA_H_
#define TCTCLM_DATA_H_

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
 *	TCTCLM module vehicle get function. Function gets TCTCLM vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTCLM_VehDbgPtr</b> Global static pointer to TCTCLM vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTCLM_VehDbgType* TCTCLM_VehGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTCLM_FlagTimerLastCall_nu
#define D_TCTCLM_FlagTimerLastCall_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_FlagTimerLastCall_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_FlagTimerLastCall_nu() (D_TCTCLM_FlagTimerLastCall_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_FlagTimerLastCall_nu

#ifndef D_TCTCLM_FrozenVehCrv_1pm
#define D_TCTCLM_FrozenVehCrv_1pm (TCTCLM_VehGetDbgPtr()->D_TCTCLM_FrozenVehCrv_1pm) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_FrozenVehCrv_1pm() (D_TCTCLM_FrozenVehCrv_1pm) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_FrozenVehCrv_1pm

#ifndef D_TCTCLM_LimiterWthtErrCntr_nu
#define D_TCTCLM_LimiterWthtErrCntr_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_LimiterWthtErrCntr_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_LimiterWthtErrCntr_nu() (D_TCTCLM_LimiterWthtErrCntr_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_LimiterWthtErrCntr_nu

#ifndef D_TCTCLM_PlausiChkLowLimit_1pm
#define D_TCTCLM_PlausiChkLowLimit_1pm (TCTCLM_VehGetDbgPtr()->D_TCTCLM_PlausiChkLowLimit_1pm) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_PlausiChkLowLimit_1pm() (D_TCTCLM_PlausiChkLowLimit_1pm) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_PlausiChkLowLimit_1pm

#ifndef D_TCTCLM_PlausiChkUpLimit_1pm
#define D_TCTCLM_PlausiChkUpLimit_1pm (TCTCLM_VehGetDbgPtr()->D_TCTCLM_PlausiChkUpLimit_1pm) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_PlausiChkUpLimit_1pm() (D_TCTCLM_PlausiChkUpLimit_1pm) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_PlausiChkUpLimit_1pm

#ifndef D_TCTCLM_PlausibCheckActive_nu
#define D_TCTCLM_PlausibCheckActive_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_PlausibCheckActive_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_PlausibCheckActive_nu() (D_TCTCLM_PlausibCheckActive_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_PlausibCheckActive_nu

#ifndef D_TCTCLM_PlausibCheckPrecond_nu
#define D_TCTCLM_PlausibCheckPrecond_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_PlausibCheckPrecond_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_PlausibCheckPrecond_nu() (D_TCTCLM_PlausibCheckPrecond_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_PlausibCheckPrecond_nu

#ifndef D_TCTCLM_QuServErrMemReset_nu
#define D_TCTCLM_QuServErrMemReset_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_QuServErrMemReset_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_QuServErrMemReset_nu() (D_TCTCLM_QuServErrMemReset_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_QuServErrMemReset_nu

#ifndef D_TCTCLM_QuServErrMemSet_nu
#define D_TCTCLM_QuServErrMemSet_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_QuServErrMemSet_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_QuServErrMemSet_nu() (D_TCTCLM_QuServErrMemSet_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_QuServErrMemSet_nu

#ifndef D_TCTCLM_QualifierService_nu
#define D_TCTCLM_QualifierService_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_QualifierService_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_QualifierService_nu() (D_TCTCLM_QualifierService_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_QualifierService_nu

#ifndef D_TCTCLM_SumCtrlSignal_1pm
#define D_TCTCLM_SumCtrlSignal_1pm (TCTCLM_VehGetDbgPtr()->D_TCTCLM_SumCtrlSignal_1pm) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_SumCtrlSignal_1pm() (D_TCTCLM_SumCtrlSignal_1pm) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_SumCtrlSignal_1pm

#ifndef D_TCTCLM_TimerValue_sec
#define D_TCTCLM_TimerValue_sec (TCTCLM_VehGetDbgPtr()->D_TCTCLM_TimerValue_sec) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_TimerValue_sec() (D_TCTCLM_TimerValue_sec) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_TimerValue_sec

#ifndef D_TCTCLM_UnplsblDrctnOfRqst_nu
#define D_TCTCLM_UnplsblDrctnOfRqst_nu (TCTCLM_VehGetDbgPtr()->D_TCTCLM_UnplsblDrctnOfRqst_nu) //!< TCTCLM debug macro.
#define GET_D_TCTCLM_UnplsblDrctnOfRqst_nu() (D_TCTCLM_UnplsblDrctnOfRqst_nu) //!< TCTCLM debug macro getter.
#endif // D_TCTCLM_UnplsblDrctnOfRqst_nu

#ifndef S_TCTCLM_DeltaFCmd_deg
#define S_TCTCLM_DeltaFCmd_deg (TCTCLM_VehGetDbgPtr()->S_TCTCLM_DeltaFCmd_deg) //!< TCTCLM debug macro.
#define GET_S_TCTCLM_DeltaFCmd_deg() (S_TCTCLM_DeltaFCmd_deg) //!< TCTCLM debug macro getter.
#endif // S_TCTCLM_DeltaFCmd_deg

#ifndef S_TCTCLM_FbcDc_1pm
#define S_TCTCLM_FbcDc_1pm (TCTCLM_VehGetDbgPtr()->S_TCTCLM_FbcDc_1pm) //!< TCTCLM debug macro.
#define GET_S_TCTCLM_FbcDc_1pm() (S_TCTCLM_FbcDc_1pm) //!< TCTCLM debug macro getter.
#endif // S_TCTCLM_FbcDc_1pm

#ifndef S_TCTCLM_Ffc_1pm
#define S_TCTCLM_Ffc_1pm (TCTCLM_VehGetDbgPtr()->S_TCTCLM_Ffc_1pm) //!< TCTCLM debug macro.
#define GET_S_TCTCLM_Ffc_1pm() (S_TCTCLM_Ffc_1pm) //!< TCTCLM debug macro getter.
#endif // S_TCTCLM_Ffc_1pm

#ifndef S_TCTCLM_LimiterWarning_nu
#define S_TCTCLM_LimiterWarning_nu (TCTCLM_VehGetDbgPtr()->S_TCTCLM_LimiterWarning_nu) //!< TCTCLM debug macro.
#define GET_S_TCTCLM_LimiterWarning_nu() (S_TCTCLM_LimiterWarning_nu) //!< TCTCLM debug macro getter.
#endif // S_TCTCLM_LimiterWarning_nu

#ifndef S_TCTCLM_Limiter_TgtCrv_1pm
#define S_TCTCLM_Limiter_TgtCrv_1pm (TCTCLM_VehGetDbgPtr()->S_TCTCLM_Limiter_TgtCrv_1pm) //!< TCTCLM debug macro.
#define GET_S_TCTCLM_Limiter_TgtCrv_1pm() (S_TCTCLM_Limiter_TgtCrv_1pm) //!< TCTCLM debug macro getter.
#endif // S_TCTCLM_Limiter_TgtCrv_1pm

#ifndef S_TCTCLM_QuServTrajCtr_nu
#define S_TCTCLM_QuServTrajCtr_nu (TCTCLM_VehGetDbgPtr()->S_TCTCLM_QuServTrajCtr_nu) //!< TCTCLM debug macro.
#define GET_S_TCTCLM_QuServTrajCtr_nu() (S_TCTCLM_QuServTrajCtr_nu) //!< TCTCLM debug macro getter.
#endif // S_TCTCLM_QuServTrajCtr_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTCLM_DATA_H_
