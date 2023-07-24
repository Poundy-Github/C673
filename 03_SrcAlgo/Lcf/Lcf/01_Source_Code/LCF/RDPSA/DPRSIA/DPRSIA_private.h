/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRSIA_private.h
//! @brief     (DPRSIA) Module Private Header.

#ifndef DPRSIA_PRIVATE_H_
#define DPRSIA_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define RDPSA	//!< RDPSA sub-component input macro switch.
#define DPRSIA	//!< DPRSIA module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPRSIA.h"
#include "Bitop.h"  //MFC5J3
#include "f32_calm.h"
#include "f32_math.h"
#include "DPRSIA_type.h" //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DPRSIA_SenReset		0xF0 //!< DPRSIA module reset runnable identifier.
#define RUNNABLE_ID_DPRSIA_SenProcess	0xF1 //!< DPRSIA module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPRSIA_SenDbgType *DPRSIA_SenDbgPtr = NULL; //!< DPRSIA module sensor debug data pointer.
void DPRSIA_SenInitDbgPtr(DPRSIA_SenDbgType *DPRSIA_SenDbgArg) { DPRSIA_SenDbgPtr = DPRSIA_SenDbgPtr == NULL ? DPRSIA_SenDbgArg : DPRSIA_SenDbgPtr; }
const DPRSIA_SenDbgType* DPRSIA_SenGetDbgPtr(void) { return (const DPRSIA_SenDbgType*) DPRSIA_SenDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DPRSIA_LnBndLeCancelValidRDP_bool
#define	D_DPRSIA_LnBndLeCancelValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndLeCancelValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndLeCancelValidRDP_bool(val)	(D_DPRSIA_LnBndLeCancelValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndLeCancelValidRDW_bool
#define	D_DPRSIA_LnBndLeCancelValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndLeCancelValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndLeCancelValidRDW_bool(val)	(D_DPRSIA_LnBndLeCancelValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndLeTrgValidRDP_bool
#define	D_DPRSIA_LnBndLeTrgValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndLeTrgValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndLeTrgValidRDP_bool(val)	(D_DPRSIA_LnBndLeTrgValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndLeTrgValidRDW_bool
#define	D_DPRSIA_LnBndLeTrgValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndLeTrgValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndLeTrgValidRDW_bool(val)	(D_DPRSIA_LnBndLeTrgValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndRiCancelValidRDP_bool
#define	D_DPRSIA_LnBndRiCancelValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndRiCancelValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndRiCancelValidRDP_bool(val)	(D_DPRSIA_LnBndRiCancelValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndRiCancelValidRDW_bool
#define	D_DPRSIA_LnBndRiCancelValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndRiCancelValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndRiCancelValidRDW_bool(val)	(D_DPRSIA_LnBndRiCancelValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndRiTrgValidRDP_bool
#define	D_DPRSIA_LnBndRiTrgValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndRiTrgValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndRiTrgValidRDP_bool(val)	(D_DPRSIA_LnBndRiTrgValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_LnBndRiTrgValidRDW_bool
#define	D_DPRSIA_LnBndRiTrgValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_LnBndRiTrgValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_LnBndRiTrgValidRDW_bool(val)	(D_DPRSIA_LnBndRiTrgValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndLeCancelValidRDP_bool
#define	D_DPRSIA_RdBndLeCancelValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndLeCancelValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndLeCancelValidRDP_bool(val)	(D_DPRSIA_RdBndLeCancelValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndLeCancelValidRDW_bool
#define	D_DPRSIA_RdBndLeCancelValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndLeCancelValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndLeCancelValidRDW_bool(val)	(D_DPRSIA_RdBndLeCancelValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndLeTrgValidRDP_bool
#define	D_DPRSIA_RdBndLeTrgValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndLeTrgValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndLeTrgValidRDP_bool(val)	(D_DPRSIA_RdBndLeTrgValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndLeTrgValidRDW_bool
#define	D_DPRSIA_RdBndLeTrgValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndLeTrgValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndLeTrgValidRDW_bool(val)	(D_DPRSIA_RdBndLeTrgValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndRiCancelValidRDP_bool
#define	D_DPRSIA_RdBndRiCancelValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndRiCancelValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndRiCancelValidRDP_bool(val)	(D_DPRSIA_RdBndRiCancelValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndRiCancelValidRDW_bool
#define	D_DPRSIA_RdBndRiCancelValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndRiCancelValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndRiCancelValidRDW_bool(val)	(D_DPRSIA_RdBndRiCancelValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndRiTrgValidRDP_bool
#define	D_DPRSIA_RdBndRiTrgValidRDP_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndRiTrgValidRDP_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndRiTrgValidRDP_bool(val)	(D_DPRSIA_RdBndRiTrgValidRDP_bool = (val)) //!< DPRSIA debug macro setter.

#undef	D_DPRSIA_RdBndRiTrgValidRDW_bool
#define	D_DPRSIA_RdBndRiTrgValidRDW_bool (DPRSIA_SenDbgPtr->D_DPRSIA_RdBndRiTrgValidRDW_bool) //!< DPRSIA debug macro.
#define	SET_D_DPRSIA_RdBndRiTrgValidRDW_bool(val)	(D_DPRSIA_RdBndRiTrgValidRDW_bool = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DlcLeRDP_met
#define	S_DPRSIA_DlcLeRDP_met (DPRSIA_SenDbgPtr->S_DPRSIA_DlcLeRDP_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DlcLeRDP_met(val)	(S_DPRSIA_DlcLeRDP_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DlcLeRDW_met
#define	S_DPRSIA_DlcLeRDW_met (DPRSIA_SenDbgPtr->S_DPRSIA_DlcLeRDW_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DlcLeRDW_met(val)	(S_DPRSIA_DlcLeRDW_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DlcRiRDP_met
#define	S_DPRSIA_DlcRiRDP_met (DPRSIA_SenDbgPtr->S_DPRSIA_DlcRiRDP_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DlcRiRDP_met(val)	(S_DPRSIA_DlcRiRDP_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DlcRiRDW_met
#define	S_DPRSIA_DlcRiRDW_met (DPRSIA_SenDbgPtr->S_DPRSIA_DlcRiRDW_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DlcRiRDW_met(val)	(S_DPRSIA_DlcRiRDW_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DrcLeRDP_met
#define	S_DPRSIA_DrcLeRDP_met (DPRSIA_SenDbgPtr->S_DPRSIA_DrcLeRDP_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DrcLeRDP_met(val)	(S_DPRSIA_DrcLeRDP_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DrcLeRDW_met
#define	S_DPRSIA_DrcLeRDW_met (DPRSIA_SenDbgPtr->S_DPRSIA_DrcLeRDW_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DrcLeRDW_met(val)	(S_DPRSIA_DrcLeRDW_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DrcRiRDP_met
#define	S_DPRSIA_DrcRiRDP_met (DPRSIA_SenDbgPtr->S_DPRSIA_DrcRiRDP_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DrcRiRDP_met(val)	(S_DPRSIA_DrcRiRDP_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_DrcRiRDW_met
#define	S_DPRSIA_DrcRiRDW_met (DPRSIA_SenDbgPtr->S_DPRSIA_DrcRiRDW_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_DrcRiRDW_met(val)	(S_DPRSIA_DrcRiRDW_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_LaneWidthRDP_met
#define	S_DPRSIA_LaneWidthRDP_met (DPRSIA_SenDbgPtr->S_DPRSIA_LaneWidthRDP_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_LaneWidthRDP_met(val)	(S_DPRSIA_LaneWidthRDP_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_LaneWidthRDW_met
#define	S_DPRSIA_LaneWidthRDW_met (DPRSIA_SenDbgPtr->S_DPRSIA_LaneWidthRDW_met) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_LaneWidthRDW_met(val)	(S_DPRSIA_LaneWidthRDW_met = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_LnBndValidRDP_nu
#define	S_DPRSIA_LnBndValidRDP_nu (DPRSIA_SenDbgPtr->S_DPRSIA_LnBndValidRDP_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_LnBndValidRDP_nu(val)	(S_DPRSIA_LnBndValidRDP_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_LnBndValidRDW_nu
#define	S_DPRSIA_LnBndValidRDW_nu (DPRSIA_SenDbgPtr->S_DPRSIA_LnBndValidRDW_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_LnBndValidRDW_nu(val)	(S_DPRSIA_LnBndValidRDW_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_RdBndValidRDP_nu
#define	S_DPRSIA_RdBndValidRDP_nu (DPRSIA_SenDbgPtr->S_DPRSIA_RdBndValidRDP_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_RdBndValidRDP_nu(val)	(S_DPRSIA_RdBndValidRDP_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_RdBndValidRDW_nu
#define	S_DPRSIA_RdBndValidRDW_nu (DPRSIA_SenDbgPtr->S_DPRSIA_RdBndValidRDW_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_RdBndValidRDW_nu(val)	(S_DPRSIA_RdBndValidRDW_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_SideCondRDPLe_btf
#define	S_DPRSIA_SideCondRDPLe_btf (DPRSIA_SenDbgPtr->S_DPRSIA_SideCondRDPLe_btf) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_SideCondRDPLe_btf(val)	(S_DPRSIA_SideCondRDPLe_btf = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_SideCondRDPRi_btf
#define	S_DPRSIA_SideCondRDPRi_btf (DPRSIA_SenDbgPtr->S_DPRSIA_SideCondRDPRi_btf) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_SideCondRDPRi_btf(val)	(S_DPRSIA_SideCondRDPRi_btf = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_SideCondRDWLe_btf
#define	S_DPRSIA_SideCondRDWLe_btf (DPRSIA_SenDbgPtr->S_DPRSIA_SideCondRDWLe_btf) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_SideCondRDWLe_btf(val)	(S_DPRSIA_SideCondRDWLe_btf = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_SideCondRDWRi_btf
#define	S_DPRSIA_SideCondRDWRi_btf (DPRSIA_SenDbgPtr->S_DPRSIA_SideCondRDWRi_btf) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_SideCondRDWRi_btf(val)	(S_DPRSIA_SideCondRDWRi_btf = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_SpecificRDP_btf
#define	S_DPRSIA_SpecificRDP_btf (DPRSIA_SenDbgPtr->S_DPRSIA_SpecificRDP_btf) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_SpecificRDP_btf(val)	(S_DPRSIA_SpecificRDP_btf = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_SpecificRDW_btf
#define	S_DPRSIA_SpecificRDW_btf (DPRSIA_SenDbgPtr->S_DPRSIA_SpecificRDW_btf) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_SpecificRDW_btf(val)	(S_DPRSIA_SpecificRDW_btf = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TgtCntrLnEnable_bool
#define	S_DPRSIA_TgtCntrLnEnable_bool (DPRSIA_SenDbgPtr->S_DPRSIA_TgtCntrLnEnable_bool) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TgtCntrLnEnable_bool(val)	(S_DPRSIA_TgtCntrLnEnable_bool = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TlcLeRDP_sec
#define	S_DPRSIA_TlcLeRDP_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TlcLeRDP_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TlcLeRDP_sec(val)	(S_DPRSIA_TlcLeRDP_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TlcLeRDW_sec
#define	S_DPRSIA_TlcLeRDW_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TlcLeRDW_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TlcLeRDW_sec(val)	(S_DPRSIA_TlcLeRDW_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TlcRiRDP_sec
#define	S_DPRSIA_TlcRiRDP_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TlcRiRDP_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TlcRiRDP_sec(val)	(S_DPRSIA_TlcRiRDP_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TlcRiRDW_sec
#define	S_DPRSIA_TlcRiRDW_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TlcRiRDW_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TlcRiRDW_sec(val)	(S_DPRSIA_TlcRiRDW_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TrcLeRDP_sec
#define	S_DPRSIA_TrcLeRDP_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TrcLeRDP_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TrcLeRDP_sec(val)	(S_DPRSIA_TrcLeRDP_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TrcLeRDW_sec
#define	S_DPRSIA_TrcLeRDW_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TrcLeRDW_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TrcLeRDW_sec(val)	(S_DPRSIA_TrcLeRDW_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TrcRiRDP_sec
#define	S_DPRSIA_TrcRiRDP_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TrcRiRDP_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TrcRiRDP_sec(val)	(S_DPRSIA_TrcRiRDP_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TrcRiRDW_sec
#define	S_DPRSIA_TrcRiRDW_sec (DPRSIA_SenDbgPtr->S_DPRSIA_TrcRiRDW_sec) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TrcRiRDW_sec(val)	(S_DPRSIA_TrcRiRDW_sec = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TriggerReasonLeRDP_nu
#define	S_DPRSIA_TriggerReasonLeRDP_nu (DPRSIA_SenDbgPtr->S_DPRSIA_TriggerReasonLeRDP_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TriggerReasonLeRDP_nu(val)	(S_DPRSIA_TriggerReasonLeRDP_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TriggerReasonLeRDW_nu
#define	S_DPRSIA_TriggerReasonLeRDW_nu (DPRSIA_SenDbgPtr->S_DPRSIA_TriggerReasonLeRDW_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TriggerReasonLeRDW_nu(val)	(S_DPRSIA_TriggerReasonLeRDW_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TriggerReasonRiRDP_nu
#define	S_DPRSIA_TriggerReasonRiRDP_nu (DPRSIA_SenDbgPtr->S_DPRSIA_TriggerReasonRiRDP_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TriggerReasonRiRDP_nu(val)	(S_DPRSIA_TriggerReasonRiRDP_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_TriggerReasonRiRDW_nu
#define	S_DPRSIA_TriggerReasonRiRDW_nu (DPRSIA_SenDbgPtr->S_DPRSIA_TriggerReasonRiRDW_nu) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_TriggerReasonRiRDW_nu(val)	(S_DPRSIA_TriggerReasonRiRDW_nu = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatLnLeRDP_mps
#define	S_DPRSIA_VelLatLnLeRDP_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatLnLeRDP_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatLnLeRDP_mps(val)	(S_DPRSIA_VelLatLnLeRDP_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatLnLeRDW_mps
#define	S_DPRSIA_VelLatLnLeRDW_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatLnLeRDW_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatLnLeRDW_mps(val)	(S_DPRSIA_VelLatLnLeRDW_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatLnRiRDP_mps
#define	S_DPRSIA_VelLatLnRiRDP_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatLnRiRDP_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatLnRiRDP_mps(val)	(S_DPRSIA_VelLatLnRiRDP_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatLnRiRDW_mps
#define	S_DPRSIA_VelLatLnRiRDW_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatLnRiRDW_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatLnRiRDW_mps(val)	(S_DPRSIA_VelLatLnRiRDW_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatReLeRDP_mps
#define	S_DPRSIA_VelLatReLeRDP_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatReLeRDP_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatReLeRDP_mps(val)	(S_DPRSIA_VelLatReLeRDP_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatReLeRDW_mps
#define	S_DPRSIA_VelLatReLeRDW_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatReLeRDW_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatReLeRDW_mps(val)	(S_DPRSIA_VelLatReLeRDW_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatReRiRDP_mps
#define	S_DPRSIA_VelLatReRiRDP_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatReRiRDP_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatReRiRDP_mps(val)	(S_DPRSIA_VelLatReRiRDP_mps = (val)) //!< DPRSIA debug macro setter.

#undef	S_DPRSIA_VelLatReRiRDW_mps
#define	S_DPRSIA_VelLatReRiRDW_mps (DPRSIA_SenDbgPtr->S_DPRSIA_VelLatReRiRDW_mps) //!< DPRSIA debug macro.
#define	SET_S_DPRSIA_VelLatReRiRDW_mps(val)	(S_DPRSIA_VelLatReRiRDW_mps = (val)) //!< DPRSIA debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // DPRSIA_PRIVATE_H_
