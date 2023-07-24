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
//! @file     TCTDTE_data.h
//! @brief     (TCTDTE) Module Data Header.

#ifndef TCTDTE_DATA_H_
#define TCTDTE_DATA_H_

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
 *	TCTDTE module vehicle get function. Function gets TCTDTE vehicle debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TCTDTE_VehDbgPtr</b> Global static pointer to TCTDTE vehicle debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TCTDTE_VehDbgType* TCTDTE_VehGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TCTDTE_CrvReqBnkAglComp_1pm
#define D_TCTDTE_CrvReqBnkAglComp_1pm (TCTDTE_VehGetDbgPtr()->D_TCTDTE_CrvReqBnkAglComp_1pm) //!< TCTDTE debug macro.
#define GET_D_TCTDTE_CrvReqBnkAglComp_1pm() (D_TCTDTE_CrvReqBnkAglComp_1pm) //!< TCTDTE debug macro getter.
#endif // D_TCTDTE_CrvReqBnkAglComp_1pm

#ifndef D_TCTDTE_CrvReqDistrbStmTf_1pm
#define D_TCTDTE_CrvReqDistrbStmTf_1pm (TCTDTE_VehGetDbgPtr()->D_TCTDTE_CrvReqDistrbStmTf_1pm) //!< TCTDTE debug macro.
#define GET_D_TCTDTE_CrvReqDistrbStmTf_1pm() (D_TCTDTE_CrvReqDistrbStmTf_1pm) //!< TCTDTE debug macro getter.
#endif // D_TCTDTE_CrvReqDistrbStmTf_1pm

#ifndef D_TCTDTE_DeltaSetBnkAglComp_rad
#define D_TCTDTE_DeltaSetBnkAglComp_rad (TCTDTE_VehGetDbgPtr()->D_TCTDTE_DeltaSetBnkAglComp_rad) //!< TCTDTE debug macro.
#define GET_D_TCTDTE_DeltaSetBnkAglComp_rad() (D_TCTDTE_DeltaSetBnkAglComp_rad) //!< TCTDTE debug macro getter.
#endif // D_TCTDTE_DeltaSetBnkAglComp_rad

#ifndef D_TCTDTE_DeltaSetCroWiComp_deg
#define D_TCTDTE_DeltaSetCroWiComp_deg (TCTDTE_VehGetDbgPtr()->D_TCTDTE_DeltaSetCroWiComp_deg) //!< TCTDTE debug macro.
#define GET_D_TCTDTE_DeltaSetCroWiComp_deg() (D_TCTDTE_DeltaSetCroWiComp_deg) //!< TCTDTE debug macro getter.
#endif // D_TCTDTE_DeltaSetCroWiComp_deg

#ifndef D_TCTDTE_DeltaSetCroWiComp_rad
#define D_TCTDTE_DeltaSetCroWiComp_rad (TCTDTE_VehGetDbgPtr()->D_TCTDTE_DeltaSetCroWiComp_rad) //!< TCTDTE debug macro.
#define GET_D_TCTDTE_DeltaSetCroWiComp_rad() (D_TCTDTE_DeltaSetCroWiComp_rad) //!< TCTDTE debug macro getter.
#endif // D_TCTDTE_DeltaSetCroWiComp_rad

#ifndef D_TCTDTE_DeltaSetDstrbStmTf_rad
#define D_TCTDTE_DeltaSetDstrbStmTf_rad (TCTDTE_VehGetDbgPtr()->D_TCTDTE_DeltaSetDstrbStmTf_rad) //!< TCTDTE debug macro.
#define GET_D_TCTDTE_DeltaSetDstrbStmTf_rad() (D_TCTDTE_DeltaSetDstrbStmTf_rad) //!< TCTDTE debug macro getter.
#endif // D_TCTDTE_DeltaSetDstrbStmTf_rad

#ifndef S_TCTDTE_CrvReqBnkAglComp_1pm
#define S_TCTDTE_CrvReqBnkAglComp_1pm (TCTDTE_VehGetDbgPtr()->S_TCTDTE_CrvReqBnkAglComp_1pm) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_CrvReqBnkAglComp_1pm() (S_TCTDTE_CrvReqBnkAglComp_1pm) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_CrvReqBnkAglComp_1pm

#ifndef S_TCTDTE_CrvReqDstrbComp_1pm
#define S_TCTDTE_CrvReqDstrbComp_1pm (TCTDTE_VehGetDbgPtr()->S_TCTDTE_CrvReqDstrbComp_1pm) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_CrvReqDstrbComp_1pm() (S_TCTDTE_CrvReqDstrbComp_1pm) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_CrvReqDstrbComp_1pm

#ifndef S_TCTDTE_DeltaSetBnkAglComp_rad
#define S_TCTDTE_DeltaSetBnkAglComp_rad (TCTDTE_VehGetDbgPtr()->S_TCTDTE_DeltaSetBnkAglComp_rad) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_DeltaSetBnkAglComp_rad() (S_TCTDTE_DeltaSetBnkAglComp_rad) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_DeltaSetBnkAglComp_rad

#ifndef S_TCTDTE_DeltaSetCroWiComp_rad
#define S_TCTDTE_DeltaSetCroWiComp_rad (TCTDTE_VehGetDbgPtr()->S_TCTDTE_DeltaSetCroWiComp_rad) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_DeltaSetCroWiComp_rad() (S_TCTDTE_DeltaSetCroWiComp_rad) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_DeltaSetCroWiComp_rad

#ifndef S_TCTDTE_DeltaSetDstrbComp_rad
#define S_TCTDTE_DeltaSetDstrbComp_rad (TCTDTE_VehGetDbgPtr()->S_TCTDTE_DeltaSetDstrbComp_rad) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_DeltaSetDstrbComp_rad() (S_TCTDTE_DeltaSetDstrbComp_rad) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_DeltaSetDstrbComp_rad

#ifndef S_TCTDTE_MccGLaDmcDenS0_nu
#define S_TCTDTE_MccGLaDmcDenS0_nu (TCTDTE_VehGetDbgPtr()->S_TCTDTE_MccGLaDmcDenS0_nu) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_MccGLaDmcDenS0_nu() (S_TCTDTE_MccGLaDmcDenS0_nu) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_MccGLaDmcDenS0_nu

#ifndef S_TCTDTE_MccGLaDmcDenS1_nu
#define S_TCTDTE_MccGLaDmcDenS1_nu (TCTDTE_VehGetDbgPtr()->S_TCTDTE_MccGLaDmcDenS1_nu) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_MccGLaDmcDenS1_nu() (S_TCTDTE_MccGLaDmcDenS1_nu) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_MccGLaDmcDenS1_nu

#ifndef S_TCTDTE_MccGLaDmcDenS2_nu
#define S_TCTDTE_MccGLaDmcDenS2_nu (TCTDTE_VehGetDbgPtr()->S_TCTDTE_MccGLaDmcDenS2_nu) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_MccGLaDmcDenS2_nu() (S_TCTDTE_MccGLaDmcDenS2_nu) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_MccGLaDmcDenS2_nu

#ifndef S_TCTDTE_MccGLaDmcDenS3_nu
#define S_TCTDTE_MccGLaDmcDenS3_nu (TCTDTE_VehGetDbgPtr()->S_TCTDTE_MccGLaDmcDenS3_nu) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_MccGLaDmcDenS3_nu() (S_TCTDTE_MccGLaDmcDenS3_nu) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_MccGLaDmcDenS3_nu

#ifndef S_TCTDTE_MccGLaDmcNumS0_nu
#define S_TCTDTE_MccGLaDmcNumS0_nu (TCTDTE_VehGetDbgPtr()->S_TCTDTE_MccGLaDmcNumS0_nu) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_MccGLaDmcNumS0_nu() (S_TCTDTE_MccGLaDmcNumS0_nu) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_MccGLaDmcNumS0_nu

#ifndef S_TCTDTE_MccGLaDmcNumS1_nu
#define S_TCTDTE_MccGLaDmcNumS1_nu (TCTDTE_VehGetDbgPtr()->S_TCTDTE_MccGLaDmcNumS1_nu) //!< TCTDTE debug macro.
#define GET_S_TCTDTE_MccGLaDmcNumS1_nu() (S_TCTDTE_MccGLaDmcNumS1_nu) //!< TCTDTE debug macro getter.
#endif // S_TCTDTE_MccGLaDmcNumS1_nu

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // TCTDTE_DATA_H_
