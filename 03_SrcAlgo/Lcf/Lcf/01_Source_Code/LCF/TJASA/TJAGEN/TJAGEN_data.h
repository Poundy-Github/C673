/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAGEN
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJAGEN_data.h
//! @brief     (TJAGEN) Module Data Header.

#ifndef TJAGEN_DATA_H_
#define TJAGEN_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	TJAGEN module sensor get function. Function gets TJAGEN sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJAGEN_SenDbgPtr</b> Global static pointer to TJAGEN sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJAGEN_SenDbgType* TJAGEN_SenGetDbgPtr(void);

/*!
 *	TJAGEN module sensor get function. Function gets TJAGEN sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJAGEN_SenOutPtr</b> Global static pointer to TJAGEN sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJAGEN_SenOutType* TJAGEN_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJAGEN_CancelStatus_btf
#define D_TJAGEN_CancelStatus_btf (TJAGEN_SenGetDbgPtr()->D_TJAGEN_CancelStatus_btf) //!< TJAGEN debug macro.
#define GET_D_TJAGEN_CancelStatus_btf() (D_TJAGEN_CancelStatus_btf) //!< TJAGEN debug macro getter.
#endif // D_TJAGEN_CancelStatus_btf

#ifndef D_TJAGEN_StrongReadyInvalid_btf
#define D_TJAGEN_StrongReadyInvalid_btf (TJAGEN_SenGetDbgPtr()->D_TJAGEN_StrongReadyInvalid_btf) //!< TJAGEN debug macro.
#define GET_D_TJAGEN_StrongReadyInvalid_btf() (D_TJAGEN_StrongReadyInvalid_btf) //!< TJAGEN debug macro getter.
#endif // D_TJAGEN_StrongReadyInvalid_btf

#ifndef D_TJAGEN_WeakReadyInvalid_btf
#define D_TJAGEN_WeakReadyInvalid_btf (TJAGEN_SenGetDbgPtr()->D_TJAGEN_WeakReadyInvalid_btf) //!< TJAGEN debug macro.
#define GET_D_TJAGEN_WeakReadyInvalid_btf() (D_TJAGEN_WeakReadyInvalid_btf) //!< TJAGEN debug macro getter.
#endif // D_TJAGEN_WeakReadyInvalid_btf

#ifndef S_TJAGEN_Abort_bool
#define S_TJAGEN_Abort_bool (TJAGEN_SenGetDbgPtr()->S_TJAGEN_Abort_bool) //!< TJAGEN debug macro.
#define GET_S_TJAGEN_Abort_bool() (S_TJAGEN_Abort_bool) //!< TJAGEN debug macro getter.
#endif // S_TJAGEN_Abort_bool

#ifndef S_TJAGEN_LKAOnlySwitch_bool
#define S_TJAGEN_LKAOnlySwitch_bool (TJAGEN_SenGetDbgPtr()->S_TJAGEN_LKAOnlySwitch_bool) //!< TJAGEN debug macro.
#define GET_S_TJAGEN_LKAOnlySwitch_bool() (S_TJAGEN_LKAOnlySwitch_bool) //!< TJAGEN debug macro getter.
#endif // S_TJAGEN_LKAOnlySwitch_bool

#ifndef S_TJAGEN_StrongReady_bool
#define S_TJAGEN_StrongReady_bool (TJAGEN_SenGetDbgPtr()->S_TJAGEN_StrongReady_bool) //!< TJAGEN debug macro.
#define GET_S_TJAGEN_StrongReady_bool() (S_TJAGEN_StrongReady_bool) //!< TJAGEN debug macro getter.
#endif // S_TJAGEN_StrongReady_bool

#ifndef S_TJAGEN_WeakReady_bool
#define S_TJAGEN_WeakReady_bool (TJAGEN_SenGetDbgPtr()->S_TJAGEN_WeakReady_bool) //!< TJAGEN debug macro.
#define GET_S_TJAGEN_WeakReady_bool() (S_TJAGEN_WeakReady_bool) //!< TJAGEN debug macro getter.
#endif // S_TJAGEN_WeakReady_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TJAGEN_Cancel_nu
#define S_TJAGEN_Cancel_nu (TJAGEN_SenGetOutPtr()->S_TJAGEN_Cancel_nu) //!< TJAGEN output macro.
#define GET_S_TJAGEN_Cancel_nu() (S_TJAGEN_Cancel_nu) //!< TJAGEN output macro getter.
#endif // S_TJAGEN_Cancel_nu

#ifndef S_TJAGEN_Clearance_bool
#define S_TJAGEN_Clearance_bool (TJAGEN_SenGetOutPtr()->S_TJAGEN_Clearance_bool) //!< TJAGEN output macro.
#define GET_S_TJAGEN_Clearance_bool() (S_TJAGEN_Clearance_bool) //!< TJAGEN output macro getter.
#endif // S_TJAGEN_Clearance_bool

#ifndef S_TJAGEN_CodeFunction_bool
#define S_TJAGEN_CodeFunction_bool (TJAGEN_SenGetOutPtr()->S_TJAGEN_CodeFunction_bool) //!< TJAGEN output macro.
#define GET_S_TJAGEN_CodeFunction_bool() (S_TJAGEN_CodeFunction_bool) //!< TJAGEN output macro getter.
#endif // S_TJAGEN_CodeFunction_bool

#ifndef S_TJAGEN_Degradation_bool
#define S_TJAGEN_Degradation_bool (TJAGEN_SenGetOutPtr()->S_TJAGEN_Degradation_bool) //!< TJAGEN output macro.
#define GET_S_TJAGEN_Degradation_bool() (S_TJAGEN_Degradation_bool) //!< TJAGEN output macro getter.
#endif // S_TJAGEN_Degradation_bool

#ifndef S_TJAGEN_Error_bool
#define S_TJAGEN_Error_bool (TJAGEN_SenGetOutPtr()->S_TJAGEN_Error_bool) //!< TJAGEN output macro.
#define GET_S_TJAGEN_Error_bool() (S_TJAGEN_Error_bool) //!< TJAGEN output macro getter.
#endif // S_TJAGEN_Error_bool

#ifndef S_TJAGEN_FunctionSwitch_bool
#define S_TJAGEN_FunctionSwitch_bool (TJAGEN_SenGetOutPtr()->S_TJAGEN_FunctionSwitch_bool) //!< TJAGEN output macro.
#define GET_S_TJAGEN_FunctionSwitch_bool() (S_TJAGEN_FunctionSwitch_bool) //!< TJAGEN output macro getter.
#endif // S_TJAGEN_FunctionSwitch_bool

#ifdef __cplusplus
}
#endif

#endif // TJAGEN_DATA_H_
