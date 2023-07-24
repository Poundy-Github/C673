/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : VDPR
  MODULE        : VDPDRV
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     VDPDRV_data.h
//! @brief     (VDPDRV) Module Data Header.

#ifndef VDPDRV_DATA_H_
#define VDPDRV_DATA_H_

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
 *	VDPDRV module sensor get function. Function gets VDPDRV sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>VDPDRV_SenDbgPtr</b> Global static pointer to VDPDRV sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const VDPDRV_SenDbgType* VDPDRV_SenGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_VDPDRV_ActiveStCtrl_btf
#define S_VDPDRV_ActiveStCtrl_btf (VDPDRV_SenGetDbgPtr()->S_VDPDRV_ActiveStCtrl_btf) //!< VDPDRV debug macro.
#define GET_S_VDPDRV_ActiveStCtrl_btf() (S_VDPDRV_ActiveStCtrl_btf) //!< VDPDRV debug macro getter.
#endif // S_VDPDRV_ActiveStCtrl_btf

#ifndef S_VDPDRV_DrvStInvalid_btf
#define S_VDPDRV_DrvStInvalid_btf (VDPDRV_SenGetDbgPtr()->S_VDPDRV_DrvStInvalid_btf) //!< VDPDRV debug macro.
#define GET_S_VDPDRV_DrvStInvalid_btf() (S_VDPDRV_DrvStInvalid_btf) //!< VDPDRV debug macro getter.
#endif // S_VDPDRV_DrvStInvalid_btf

#ifndef S_VDPDRV_SysStError_btf
#define S_VDPDRV_SysStError_btf (VDPDRV_SenGetDbgPtr()->S_VDPDRV_SysStError_btf) //!< VDPDRV debug macro.
#define GET_S_VDPDRV_SysStError_btf() (S_VDPDRV_SysStError_btf) //!< VDPDRV debug macro getter.
#endif // S_VDPDRV_SysStError_btf

#ifndef S_VDPDRV_SysStNotAvailable_btf
#define S_VDPDRV_SysStNotAvailable_btf (VDPDRV_SenGetDbgPtr()->S_VDPDRV_SysStNotAvailable_btf) //!< VDPDRV debug macro.
#define GET_S_VDPDRV_SysStNotAvailable_btf() (S_VDPDRV_SysStNotAvailable_btf) //!< VDPDRV debug macro getter.
#endif // S_VDPDRV_SysStNotAvailable_btf

#ifndef S_VDPDRV_VehStInvalid_btf
#define S_VDPDRV_VehStInvalid_btf (VDPDRV_SenGetDbgPtr()->S_VDPDRV_VehStInvalid_btf) //!< VDPDRV debug macro.
#define GET_S_VDPDRV_VehStInvalid_btf() (S_VDPDRV_VehStInvalid_btf) //!< VDPDRV debug macro getter.
#endif // S_VDPDRV_VehStInvalid_btf

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // VDPDRV_DATA_H_
