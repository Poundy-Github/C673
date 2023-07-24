/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJASTM
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJASTM_data.h
//! @brief     (TJASTM) Module Data Header.

#ifndef TJASTM_DATA_H_
#define TJASTM_DATA_H_

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
 *	TJASTM module sensor get function. Function gets TJASTM sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJASTM_SenDbgPtr</b> Global static pointer to TJASTM sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJASTM_SenDbgType* TJASTM_SenGetDbgPtr(void);

/*!
 *	TJASTM module sensor get function. Function gets TJASTM sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJASTM_SenOutPtr</b> Global static pointer to TJASTM sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJASTM_SenOutType* TJASTM_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJASTM_TJAInvalid_btf
#define D_TJASTM_TJAInvalid_btf (TJASTM_SenGetDbgPtr()->D_TJASTM_TJAInvalid_btf) //!< TJASTM debug macro.
#define GET_D_TJASTM_TJAInvalid_btf() (D_TJASTM_TJAInvalid_btf) //!< TJASTM debug macro getter.
#endif // D_TJASTM_TJAInvalid_btf

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TJASTM_LatCtrlMode_nu
#define S_TJASTM_LatCtrlMode_nu (TJASTM_SenGetOutPtr()->S_TJASTM_LatCtrlMode_nu) //!< TJASTM output macro.
#define GET_S_TJASTM_LatCtrlMode_nu() (S_TJASTM_LatCtrlMode_nu) //!< TJASTM output macro getter.
#endif // S_TJASTM_LatCtrlMode_nu

#ifndef S_TJASTM_SysStateTJA_nu
#define S_TJASTM_SysStateTJA_nu (TJASTM_SenGetOutPtr()->S_TJASTM_SysStateTJA_nu) //!< TJASTM output macro.
#define GET_S_TJASTM_SysStateTJA_nu() (S_TJASTM_SysStateTJA_nu) //!< TJASTM output macro getter.
#endif // S_TJASTM_SysStateTJA_nu

#ifdef __cplusplus
}
#endif

#endif // TJASTM_DATA_H_
