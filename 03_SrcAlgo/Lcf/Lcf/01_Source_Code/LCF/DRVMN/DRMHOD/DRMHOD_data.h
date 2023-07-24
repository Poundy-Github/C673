/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMHOD
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DRMHOD_data.h
//! @brief     (DRMHOD) Module Data Header.

#ifndef DRMHOD_DATA_H_
#define DRMHOD_DATA_H_

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
 *	DRMHOD module vehicle get function. Function gets DRMHOD vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DRMHOD_VehDbgPtr</b> Global static pointer to DRMHOD vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DRMHOD_VehDbgType* DRMHOD_VehGetDbgPtr(void);

/*!
 *	DRMHOD module vehicle get function. Function gets DRMHOD vehicle output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DRMHOD_VehOutPtr</b> Global static pointer to DRMHOD vehicle output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DRMHOD_VehOutType* DRMHOD_VehGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DRMHOD_EstHandTor_Nm
#define D_DRMHOD_EstHandTor_Nm (DRMHOD_VehGetDbgPtr()->D_DRMHOD_EstHandTor_Nm) //!< DRMHOD debug macro.
#define GET_D_DRMHOD_EstHandTor_Nm() (D_DRMHOD_EstHandTor_Nm) //!< DRMHOD debug macro getter.
#endif // D_DRMHOD_EstHandTor_Nm

#ifndef S_DRMHOD_HandsOffConfirmed_bool
#define S_DRMHOD_HandsOffConfirmed_bool (DRMHOD_VehGetDbgPtr()->S_DRMHOD_HandsOffConfirmed_bool) //!< DRMHOD debug macro.
#define GET_S_DRMHOD_HandsOffConfirmed_bool() (S_DRMHOD_HandsOffConfirmed_bool) //!< DRMHOD debug macro getter.
#endif // S_DRMHOD_HandsOffConfirmed_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DRMHOD_CorrectedTorque_Nm
#define D_DRMHOD_CorrectedTorque_Nm (DRMHOD_VehGetOutPtr()->D_DRMHOD_CorrectedTorque_Nm) //!< DRMHOD output macro.
#define GET_D_DRMHOD_CorrectedTorque_Nm() (D_DRMHOD_CorrectedTorque_Nm) //!< DRMHOD output macro getter.
#endif // D_DRMHOD_CorrectedTorque_Nm

#ifndef D_DRMHOD_EstHandTorCounter_nu
#define D_DRMHOD_EstHandTorCounter_nu (DRMHOD_VehGetOutPtr()->D_DRMHOD_EstHandTorCounter_nu) //!< DRMHOD output macro.
#define GET_D_DRMHOD_EstHandTorCounter_nu() (D_DRMHOD_EstHandTorCounter_nu) //!< DRMHOD output macro getter.
#endif // D_DRMHOD_EstHandTorCounter_nu

#ifndef D_DRMHOD_EstHandTorState_nu
#define D_DRMHOD_EstHandTorState_nu (DRMHOD_VehGetOutPtr()->D_DRMHOD_EstHandTorState_nu) //!< DRMHOD output macro.
#define GET_D_DRMHOD_EstHandTorState_nu() (D_DRMHOD_EstHandTorState_nu) //!< DRMHOD output macro getter.
#endif // D_DRMHOD_EstHandTorState_nu

#ifndef D_DRMHOD_HdOffDtctStatus_nu
#define D_DRMHOD_HdOffDtctStatus_nu (DRMHOD_VehGetOutPtr()->D_DRMHOD_HdOffDtctStatus_nu) //!< DRMHOD output macro.
#define GET_D_DRMHOD_HdOffDtctStatus_nu() (D_DRMHOD_HdOffDtctStatus_nu) //!< DRMHOD output macro getter.
#endif // D_DRMHOD_HdOffDtctStatus_nu

#ifndef D_DRMHOD_LowPassC
#define D_DRMHOD_LowPassC (DRMHOD_VehGetOutPtr()->D_DRMHOD_LowPassC) //!< DRMHOD output macro.
#define GET_D_DRMHOD_LowPassC() (D_DRMHOD_LowPassC) //!< DRMHOD output macro getter.
#endif // D_DRMHOD_LowPassC

#ifdef __cplusplus
}
#endif

#endif // DRMHOD_DATA_H_
