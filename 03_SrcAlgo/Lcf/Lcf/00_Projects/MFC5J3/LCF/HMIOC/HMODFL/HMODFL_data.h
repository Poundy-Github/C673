/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : HMIOC
  MODULE        : HMODFL
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     HMODFL_data.h
//! @brief     (HMODFL) Module Data Header.

#ifndef HMODFL_DATA_H_
#define HMODFL_DATA_H_

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
 *	HMODFL module sensor get function. Function gets HMODFL sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>HMODFL_SenOutPtr</b> Global static pointer to HMODFL sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const HMODFL_SenOutType* HMODFL_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_HMODFL_AvailableFunction_btf
#define S_HMODFL_AvailableFunction_btf (HMODFL_SenGetOutPtr()->S_HMODFL_AvailableFunction_btf) //!< HMODFL output macro.
#define GET_S_HMODFL_AvailableFunction_btf() (S_HMODFL_AvailableFunction_btf) //!< HMODFL output macro getter.
#endif // S_HMODFL_AvailableFunction_btf

#ifndef S_HMODFL_LKAInforStatus_nu
#define S_HMODFL_LKAInforStatus_nu (HMODFL_SenGetOutPtr()->S_HMODFL_LKAInforStatus_nu) //!< HMODFL output macro.
#define GET_S_HMODFL_LKAInforStatus_nu() (S_HMODFL_LKAInforStatus_nu) //!< HMODFL output macro getter.
#endif // S_HMODFL_LKAInforStatus_nu

#ifndef S_HMODFL_LKAStatusChange_nu
#define S_HMODFL_LKAStatusChange_nu (HMODFL_SenGetOutPtr()->S_HMODFL_LKAStatusChange_nu) //!< HMODFL output macro.
#define GET_S_HMODFL_LKAStatusChange_nu() (S_HMODFL_LKAStatusChange_nu) //!< HMODFL output macro getter.
#endif // S_HMODFL_LKAStatusChange_nu

#ifdef __cplusplus
}
#endif

#endif // HMODFL_DATA_H_
