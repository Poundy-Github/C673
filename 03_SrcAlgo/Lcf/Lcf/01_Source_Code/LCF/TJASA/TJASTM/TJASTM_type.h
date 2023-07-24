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
//! @file     TJASTM_type.h
//! @brief     (TJASTM) Module Type Header.

#ifndef TJASTM_TYPE_H_
#define TJASTM_TYPE_H_

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

/*! TJASTM module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	u16_NoUnit_0_65535_0_1_t D_TJASTM_TJAInvalid_btf; /*!< @description
	*	TJASTM_DEBUG \n
	*	 \n
	*	0: TJA: StrongReadyInvalid \n
	*	1: TJA: WeakReadyInvalid \n
	*	2: LC: StrongReadyInvalid \n
	*	3: LC: WeakReadyInvalid \n
	*	4: OF: StrongReadyInvalid \n
	*	5: OF: WeakReadyInvalid \n
	*	6: SLC: StrongReadyInvalid \n
	*	7: SLC: WeakReadyInvalid \n
	*	8: TJA: CancelCondFulfilled \n
	*	9: TJA: FunctionSwitchInvalid \n
	*	10: TJA: RampoutComplete \n
	*	11: TJA: NoClearance \n
	*	12: TJA: FunctionNotCoded \n
	*	13: TJA: ErrorState \n
	*	14-15: Reserved (0 by default) \n\n
	*	\@asap_name: D_TJASTM_TJAInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
} TJASTM_SenDbgType; /*!< @description TJASTM module sensor debug data structure for MTS measurement. */

/*! TJASTM module sensor output data structure. */
typedef struct
{
	
	E_LCF_SysStateType_t S_TJASTM_SysStateTJA_nu; /*!< @description
	*	TJASTM_OUTPUT \n\n
	*	\@asap_name: S_TJASTM_SysStateTJA_nu \n
	*	\@values: E_LCF_SysStateType \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 6
	*/
	
	E_TJASTM_LatCtrlMdV4Type_t S_TJASTM_LatCtrlMode_nu; /*!< @description
	*	TJASTM_OUTPUT \n\n
	*	\@asap_name: S_TJASTM_LatCtrlMode_nu \n
	*	\@values: E_TJASTM_LatCtrlMdV4Type \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 8
	*/
	
} TJASTM_SenOutType; /*!< @description TJASTM module sensor output data structure. */

#ifdef __cplusplus
}
#endif

#endif // TJASTM_TYPE_H_
