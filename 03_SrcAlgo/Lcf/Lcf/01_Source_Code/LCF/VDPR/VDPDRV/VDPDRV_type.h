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
//! @file     VDPDRV_type.h
//! @brief     (VDPDRV) Module Type Header.

#ifndef VDPDRV_TYPE_H_
#define VDPDRV_TYPE_H_

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

/*! VDPDRV module sensor debug data structure for MTS measurement. */
typedef struct
{
	
	u16_NoUnit_0_65535_0_1_t S_VDPDRV_VehStInvalid_btf; /*!< @description
	*	VDPDRV_OUTPUT \n
	*	 \n
	*	0: DoorOpen \n
	*	1: VehicleNotReadyToStart \n
	*	2: TrailerPresent \n
	*	3: InvalidGearEngaged \n
	*	4: VehDoesMovesBckwd \n
	*	5: OversteerDetected \n
	*	6: UndersteerDetected \n
	*	7: RollerBenchDetected \n
	*	8: SteeringStopDetected \n
	*	9: Reserved (0 by default) \n
	*	10: Reserved (0 by default) \n
	*	11: Reserved (0 by default) \n
	*	12: Reserved (0 by default) \n
	*	13: Reserved (0 by default) \n
	*	14: Reserved (0 by default) \n
	*	15: Reserved (0 by default) \n\n
	*	\@asap_name: S_VDPDRV_VehStInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 65535
	*/
	
	u8_NoUnit_0_255_0_1_t S_VDPDRV_ActiveStCtrl_btf; /*!< @description
	*	VDPDRV_OUTPUT \n
	*	 \n
	*	0: ActiveCtrlABS \n
	*	1: ActiveCtrlACC \n
	*	2: ActiveCtrlESC \n
	*	3: ActiveCtrlTCS \n
	*	4: ActiveCtrlVSM \n
	*	5: Reserved \n
	*	6: Reserved \n
	*	7: Reserved \n\n
	*	\@asap_name: S_VDPDRV_ActiveStCtrl_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_VDPDRV_DrvStInvalid_btf; /*!< @description
	*	VDPDRV_OUTPUT \n
	*	 \n
	*	0: AccelPedalRateInvalid \n
	*	1: DriverNotBuckledUp \n
	*	2: TurnSignalHarzard \n
	*	3: TurnSignalLeftOrRight \n
	*	4: DrvInattentivenessDetected \n
	*	5: ManualTorqueOverride \n
	*	6: Reserved (0 by default) \n
	*	7: Reserved (0 by default) \n\n
	*	\@asap_name: S_VDPDRV_DrvStInvalid_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_VDPDRV_SysStError_btf; /*!< @description
	*	VDPDRV_OUTPUT \n
	*	 \n
	*	0: SystemErrorABS \n
	*	1: SystemErrorACC \n
	*	2: SystemErrorESC \n
	*	3: SystemErrorTCS \n
	*	4: SystemErrorVSM \n
	*	5: SystemErrorVDY \n
	*	6: SystemErrorLatDMC \n
	*	7: Reserved \n\n
	*	\@asap_name: S_VDPDRV_SysStError_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
	u8_NoUnit_0_255_0_1_t S_VDPDRV_SysStNotAvailable_btf; /*!< @description
	*	VDPDRV_OUTPUT \n
	*	 \n
	*	0: SystemNotAvailableABS \n
	*	1: SystemNotAvailableACC \n
	*	2: SystemNotAvailableESC \n
	*	3: SystemNotAvailableTCS \n
	*	4: SystemNotAvailableVSM \n
	*	5: Reserved \n
	*	6: Reserved \n
	*	7: Reserved \n\n
	*	\@asap_name: S_VDPDRV_SysStNotAvailable_btf \n
	*	\@type: value \n
	*	\@unit: - \n
	*	\@min: 0 \n
	*	\@max: 255
	*/
	
} VDPDRV_SenDbgType; /*!< @description VDPDRV module sensor debug data structure for MTS measurement. */

#ifdef __cplusplus
}
#endif

#endif // VDPDRV_TYPE_H_
