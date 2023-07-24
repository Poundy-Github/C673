/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : MFC5J3CN15
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
//! @file     HMODFL_type.h
//! @brief     (HMODFL) Module Type Header.

#ifndef HMODFL_TYPE_H_
#define HMODFL_TYPE_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCF_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   S T R U C T U R E S
**-----------------------------------------------------*/

/*! HMODFL module sensor output data structure. */
typedef struct
{
	
	u8_NoUnit_0_10_0_1_t S_HMODFL_LKAInforStatus_nu; /*!< @description
	*	LKA status: \n
	*	0 -> Not present / Disable \n
	*	1 -> Passive \n
	*	2 -> Request / Controlling / Rampout \n
	*	4 -> Fault \n\n
	*	\@asap_name: S_HMODFL_LKAInforStatus_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 10
	*/
	
	u8_NoUnit_0_1_0_1_t S_HMODFL_LKAStatusChange_nu; /*!< @description
	*	Indicate if the LKA status changes from 0 to 1 or from 1 to 2. \n\n
	*	\@asap_name: S_HMODFL_LKAStatusChange_nu \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 1
	*/
	
	u8_NoUnit_0_255_0_1_t S_HMODFL_AvailableFunction_btf; /*!< @description
	*	Bit0: TJA(LKA); \n\n
	*	\@asap_name: S_HMODFL_AvailableFunction_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} HMODFL_SenOutType; /*!< @description HMODFL module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // HMODFL_TYPE_H_
