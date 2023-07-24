/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : MDCTR
  MODULE        : MCTLFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     MCTLFC_data.h
//! @brief     (MCTLFC) Module Data Header.

#ifndef MCTLFC_DATA_H_
#define MCTLFC_DATA_H_

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
 *	MCTLFC module sensor get function. Function gets MCTLFC sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>MCTLFC_SenOutPtr</b> Global static pointer to MCTLFC sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const MCTLFC_SenOutType* MCTLFC_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_MCTLFC_ControllingFunction_nu
#define S_MCTLFC_ControllingFunction_nu (MCTLFC_SenGetOutPtr()->S_MCTLFC_ControllingFunction_nu) //!< MCTLFC output macro.
#define GET_S_MCTLFC_ControllingFunction_nu() (S_MCTLFC_ControllingFunction_nu) //!< MCTLFC output macro getter.
#endif // S_MCTLFC_ControllingFunction_nu

#ifdef __cplusplus
}
#endif

#endif // MCTLFC_DATA_H_
