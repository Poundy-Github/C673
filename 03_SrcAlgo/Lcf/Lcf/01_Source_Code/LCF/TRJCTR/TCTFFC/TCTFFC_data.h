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
//! @file     TCTFFC_data.h
//! @brief     (TCTFFC) Module Data Header.

#ifndef TCTFFC_DATA_H_
#define TCTFFC_DATA_H_

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
 *	TCTFFC module vehicle get function. Function gets TCTFFC vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTFFC_VehDbgPtr</b> Global static pointer to TCTFFC vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTFFC_VehDbgType* TCTFFC_VehGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTFFC_DiffMeasEstKappa_1pm
#define D_TCTFFC_DiffMeasEstKappa_1pm (TCTFFC_VehGetDbgPtr()->D_TCTFFC_DiffMeasEstKappa_1pm) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_DiffMeasEstKappa_1pm() (D_TCTFFC_DiffMeasEstKappa_1pm) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_DiffMeasEstKappa_1pm

#ifndef D_TCTFFC_DynFfcDecel_1pm
#define D_TCTFFC_DynFfcDecel_1pm (TCTFFC_VehGetDbgPtr()->D_TCTFFC_DynFfcDecel_1pm) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_DynFfcDecel_1pm() (D_TCTFFC_DynFfcDecel_1pm) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_DynFfcDecel_1pm

#ifndef D_TCTFFC_DynFfcGeneral_1pm
#define D_TCTFFC_DynFfcGeneral_1pm (TCTFFC_VehGetDbgPtr()->D_TCTFFC_DynFfcGeneral_1pm) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_DynFfcGeneral_1pm() (D_TCTFFC_DynFfcGeneral_1pm) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_DynFfcGeneral_1pm

#ifndef D_TCTFFC_DynFfcUpDwnHill_1pm
#define D_TCTFFC_DynFfcUpDwnHill_1pm (TCTFFC_VehGetDbgPtr()->D_TCTFFC_DynFfcUpDwnHill_1pm) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_DynFfcUpDwnHill_1pm() (D_TCTFFC_DynFfcUpDwnHill_1pm) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_DynFfcUpDwnHill_1pm

#ifndef D_TCTFFC_DynFfc_1pm
#define D_TCTFFC_DynFfc_1pm (TCTFFC_VehGetDbgPtr()->D_TCTFFC_DynFfc_1pm) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_DynFfc_1pm() (D_TCTFFC_DynFfc_1pm) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_DynFfc_1pm

#ifndef D_TCTFFC_DynGainPrecFulfilled_nu
#define D_TCTFFC_DynGainPrecFulfilled_nu (TCTFFC_VehGetDbgPtr()->D_TCTFFC_DynGainPrecFulfilled_nu) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_DynGainPrecFulfilled_nu() (D_TCTFFC_DynGainPrecFulfilled_nu) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_DynGainPrecFulfilled_nu

#ifndef D_TCTFFC_TrajTgtCrvFilt_1pm
#define D_TCTFFC_TrajTgtCrvFilt_1pm (TCTFFC_VehGetDbgPtr()->D_TCTFFC_TrajTgtCrvFilt_1pm) //!< TCTFFC debug macro.
#define GET_D_TCTFFC_TrajTgtCrvFilt_1pm() (D_TCTFFC_TrajTgtCrvFilt_1pm) //!< TCTFFC debug macro getter.
#endif // D_TCTFFC_TrajTgtCrvFilt_1pm

#ifndef S_TCTFFC_Crv_1pm
#define S_TCTFFC_Crv_1pm (TCTFFC_VehGetDbgPtr()->S_TCTFFC_Crv_1pm) //!< TCTFFC debug macro.
#define GET_S_TCTFFC_Crv_1pm() (S_TCTFFC_Crv_1pm) //!< TCTFFC debug macro getter.
#endif // S_TCTFFC_Crv_1pm

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTFFC_DATA_H_
