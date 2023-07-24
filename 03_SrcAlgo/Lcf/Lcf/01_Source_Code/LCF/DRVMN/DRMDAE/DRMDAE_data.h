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
//! @file     DRMDAE_data.h
//! @brief     (DRMDAE) Module Data Header.

#ifndef DRMDAE_DATA_H_
#define DRMDAE_DATA_H_

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
 *	DRMDAE module vehicle get function. Function gets DRMDAE vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DRMDAE_VehDbgPtr</b> Global static pointer to DRMDAE vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DRMDAE_VehDbgType* DRMDAE_VehGetDbgPtr(void);

/*!
 *	DRMDAE module vehicle get function. Function gets DRMDAE vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DRMDAE_VehOutPtr</b> Global static pointer to DRMDAE vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DRMDAE_VehOutType* DRMDAE_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DRMDAE_AbuseWarning_bool
#define S_DRMDAE_AbuseWarning_bool (DRMDAE_VehGetDbgPtr()->S_DRMDAE_AbuseWarning_bool) //!< DRMDAE debug macro.
#define GET_S_DRMDAE_AbuseWarning_bool() (S_DRMDAE_AbuseWarning_bool) //!< DRMDAE debug macro getter.
#endif // S_DRMDAE_AbuseWarning_bool

#ifndef S_DRMDAE_SysWarning_nu
#define S_DRMDAE_SysWarning_nu (DRMDAE_VehGetDbgPtr()->S_DRMDAE_SysWarning_nu) //!< DRMDAE debug macro.
#define GET_S_DRMDAE_SysWarning_nu() (S_DRMDAE_SysWarning_nu) //!< DRMDAE debug macro getter.
#endif // S_DRMDAE_SysWarning_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DRMDAE_AbuseWarnDuration_sec
#define D_DRMDAE_AbuseWarnDuration_sec (DRMDAE_VehGetOutPtr()->D_DRMDAE_AbuseWarnDuration_sec) //!< DRMDAE output macro.
#define GET_D_DRMDAE_AbuseWarnDuration_sec() (D_DRMDAE_AbuseWarnDuration_sec) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_AbuseWarnDuration_sec

#ifndef D_DRMDAE_ActToi_nu
#define D_DRMDAE_ActToi_nu (DRMDAE_VehGetOutPtr()->D_DRMDAE_ActToi_nu) //!< DRMDAE output macro.
#define GET_D_DRMDAE_ActToi_nu() (D_DRMDAE_ActToi_nu) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_ActToi_nu

#ifndef D_DRMDAE_CriticalEventsNo_nu
#define D_DRMDAE_CriticalEventsNo_nu (DRMDAE_VehGetOutPtr()->D_DRMDAE_CriticalEventsNo_nu) //!< DRMDAE output macro.
#define GET_D_DRMDAE_CriticalEventsNo_nu() (D_DRMDAE_CriticalEventsNo_nu) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_CriticalEventsNo_nu

#ifndef D_DRMDAE_ElapsedTime_sec
#define D_DRMDAE_ElapsedTime_sec (DRMDAE_VehGetOutPtr()->D_DRMDAE_ElapsedTime_sec) //!< DRMDAE output macro.
#define GET_D_DRMDAE_ElapsedTime_sec() (D_DRMDAE_ElapsedTime_sec) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_ElapsedTime_sec

#ifndef D_DRMDAE_HoffTrigger_nu
#define D_DRMDAE_HoffTrigger_nu (DRMDAE_VehGetOutPtr()->D_DRMDAE_HoffTrigger_nu) //!< DRMDAE output macro.
#define GET_D_DRMDAE_HoffTrigger_nu() (D_DRMDAE_HoffTrigger_nu) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_HoffTrigger_nu

#ifndef D_DRMDAE_ResetWarnCnt_nu
#define D_DRMDAE_ResetWarnCnt_nu (DRMDAE_VehGetOutPtr()->D_DRMDAE_ResetWarnCnt_nu) //!< DRMDAE output macro.
#define GET_D_DRMDAE_ResetWarnCnt_nu() (D_DRMDAE_ResetWarnCnt_nu) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_ResetWarnCnt_nu

#ifndef D_DRMDAE_SpeedOk_bool
#define D_DRMDAE_SpeedOk_bool (DRMDAE_VehGetOutPtr()->D_DRMDAE_SpeedOk_bool) //!< DRMDAE output macro.
#define GET_D_DRMDAE_SpeedOk_bool() (D_DRMDAE_SpeedOk_bool) //!< DRMDAE output macro getter.
#endif // D_DRMDAE_SpeedOk_bool

#ifndef S_DRMDAE_DrvAttentionConf_perc
#define S_DRMDAE_DrvAttentionConf_perc (DRMDAE_VehGetOutPtr()->S_DRMDAE_DrvAttentionConf_perc) //!< DRMDAE output macro.
#define GET_S_DRMDAE_DrvAttentionConf_perc() (S_DRMDAE_DrvAttentionConf_perc) //!< DRMDAE output macro getter.
#endif // S_DRMDAE_DrvAttentionConf_perc

#ifndef S_DRMDAE_DrvAttention_perc
#define S_DRMDAE_DrvAttention_perc (DRMDAE_VehGetOutPtr()->S_DRMDAE_DrvAttention_perc) //!< DRMDAE output macro.
#define GET_S_DRMDAE_DrvAttention_perc() (S_DRMDAE_DrvAttention_perc) //!< DRMDAE output macro getter.
#endif // S_DRMDAE_DrvAttention_perc

#ifdef __cplusplus
}
#endif

#endif // DRMDAE_DATA_H_
