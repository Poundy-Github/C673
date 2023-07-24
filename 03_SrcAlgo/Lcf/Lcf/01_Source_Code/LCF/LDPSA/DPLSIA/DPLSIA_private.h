/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLSIA_private.h
//! @brief     (DPLSIA) Module Private Header.

#ifndef DPLSIA_PRIVATE_H_
#define DPLSIA_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define LDPSA	//!< LDPSA sub-component input macro switch.
#define DPLSIA	//!< DPLSIA module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DPLSIA.h"
#include "Bitop.h"  //MFC5J3
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_DPLSIA_SenReset		0xF0 //!< DPLSIA module reset runnable identifier.
#define RUNNABLE_ID_DPLSIA_SenProcess	0xF1 //!< DPLSIA module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static DPLSIA_SenDbgType *DPLSIA_SenDbgPtr = NULL; //!< DPLSIA module sensor debug data pointer.
void DPLSIA_SenInitDbgPtr(DPLSIA_SenDbgType *DPLSIA_SenDbgArg) { DPLSIA_SenDbgPtr = DPLSIA_SenDbgPtr == NULL ? DPLSIA_SenDbgArg : DPLSIA_SenDbgPtr; }
const DPLSIA_SenDbgType* DPLSIA_SenGetDbgPtr(void) { return (const DPLSIA_SenDbgType*) DPLSIA_SenDbgPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_DPLSIA_LnBndLeCancelValidLDP_bool
#define	D_DPLSIA_LnBndLeCancelValidLDP_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndLeCancelValidLDP_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndLeCancelValidLDP_bool(val)	(D_DPLSIA_LnBndLeCancelValidLDP_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndLeCancelValidLDW_bool
#define	D_DPLSIA_LnBndLeCancelValidLDW_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndLeCancelValidLDW_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndLeCancelValidLDW_bool(val)	(D_DPLSIA_LnBndLeCancelValidLDW_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndLeTrgValidLDP_bool
#define	D_DPLSIA_LnBndLeTrgValidLDP_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndLeTrgValidLDP_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndLeTrgValidLDP_bool(val)	(D_DPLSIA_LnBndLeTrgValidLDP_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndLeTrgValidLDW_bool
#define	D_DPLSIA_LnBndLeTrgValidLDW_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndLeTrgValidLDW_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndLeTrgValidLDW_bool(val)	(D_DPLSIA_LnBndLeTrgValidLDW_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndRiCancelValidLDP_bool
#define	D_DPLSIA_LnBndRiCancelValidLDP_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndRiCancelValidLDP_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndRiCancelValidLDP_bool(val)	(D_DPLSIA_LnBndRiCancelValidLDP_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndRiCancelValidLDW_bool
#define	D_DPLSIA_LnBndRiCancelValidLDW_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndRiCancelValidLDW_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndRiCancelValidLDW_bool(val)	(D_DPLSIA_LnBndRiCancelValidLDW_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndRiTrgValidLDP_bool
#define	D_DPLSIA_LnBndRiTrgValidLDP_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndRiTrgValidLDP_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndRiTrgValidLDP_bool(val)	(D_DPLSIA_LnBndRiTrgValidLDP_bool = (val)) //!< DPLSIA debug macro setter.

#undef	D_DPLSIA_LnBndRiTrgValidLDW_bool
#define	D_DPLSIA_LnBndRiTrgValidLDW_bool (DPLSIA_SenDbgPtr->D_DPLSIA_LnBndRiTrgValidLDW_bool) //!< DPLSIA debug macro.
#define	SET_D_DPLSIA_LnBndRiTrgValidLDW_bool(val)	(D_DPLSIA_LnBndRiTrgValidLDW_bool = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_CurveTypeLe_enum
#define	S_DPLSIA_CurveTypeLe_enum (DPLSIA_SenDbgPtr->S_DPLSIA_CurveTypeLe_enum) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_CurveTypeLe_enum(val)	(S_DPLSIA_CurveTypeLe_enum = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_CurveTypeRi_enum
#define	S_DPLSIA_CurveTypeRi_enum (DPLSIA_SenDbgPtr->S_DPLSIA_CurveTypeRi_enum) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_CurveTypeRi_enum(val)	(S_DPLSIA_CurveTypeRi_enum = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_DlcLeLDP_met
#define	S_DPLSIA_DlcLeLDP_met (DPLSIA_SenDbgPtr->S_DPLSIA_DlcLeLDP_met) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_DlcLeLDP_met(val)	(S_DPLSIA_DlcLeLDP_met = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_DlcLeLDW_met
#define	S_DPLSIA_DlcLeLDW_met (DPLSIA_SenDbgPtr->S_DPLSIA_DlcLeLDW_met) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_DlcLeLDW_met(val)	(S_DPLSIA_DlcLeLDW_met = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_DlcRiLDP_met
#define	S_DPLSIA_DlcRiLDP_met (DPLSIA_SenDbgPtr->S_DPLSIA_DlcRiLDP_met) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_DlcRiLDP_met(val)	(S_DPLSIA_DlcRiLDP_met = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_DlcRiLDW_met
#define	S_DPLSIA_DlcRiLDW_met (DPLSIA_SenDbgPtr->S_DPLSIA_DlcRiLDW_met) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_DlcRiLDW_met(val)	(S_DPLSIA_DlcRiLDW_met = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LaneWidthLDP_met
#define	S_DPLSIA_LaneWidthLDP_met (DPLSIA_SenDbgPtr->S_DPLSIA_LaneWidthLDP_met) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LaneWidthLDP_met(val)	(S_DPLSIA_LaneWidthLDP_met = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LaneWidthLDW_met
#define	S_DPLSIA_LaneWidthLDW_met (DPLSIA_SenDbgPtr->S_DPLSIA_LaneWidthLDW_met) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LaneWidthLDW_met(val)	(S_DPLSIA_LaneWidthLDW_met = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LnBndLeValidLDP_bool
#define	S_DPLSIA_LnBndLeValidLDP_bool (DPLSIA_SenDbgPtr->S_DPLSIA_LnBndLeValidLDP_bool) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LnBndLeValidLDP_bool(val)	(S_DPLSIA_LnBndLeValidLDP_bool = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LnBndLeValidLDW_bool
#define	S_DPLSIA_LnBndLeValidLDW_bool (DPLSIA_SenDbgPtr->S_DPLSIA_LnBndLeValidLDW_bool) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LnBndLeValidLDW_bool(val)	(S_DPLSIA_LnBndLeValidLDW_bool = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LnBndRiValidLDP_bool
#define	S_DPLSIA_LnBndRiValidLDP_bool (DPLSIA_SenDbgPtr->S_DPLSIA_LnBndRiValidLDP_bool) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LnBndRiValidLDP_bool(val)	(S_DPLSIA_LnBndRiValidLDP_bool = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LnBndRiValidLDW_bool
#define	S_DPLSIA_LnBndRiValidLDW_bool (DPLSIA_SenDbgPtr->S_DPLSIA_LnBndRiValidLDW_bool) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LnBndRiValidLDW_bool(val)	(S_DPLSIA_LnBndRiValidLDW_bool = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LnBndValidLDP_nu
#define	S_DPLSIA_LnBndValidLDP_nu (DPLSIA_SenDbgPtr->S_DPLSIA_LnBndValidLDP_nu) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LnBndValidLDP_nu(val)	(S_DPLSIA_LnBndValidLDP_nu = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_LnBndValidLDW_nu
#define	S_DPLSIA_LnBndValidLDW_nu (DPLSIA_SenDbgPtr->S_DPLSIA_LnBndValidLDW_nu) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_LnBndValidLDW_nu(val)	(S_DPLSIA_LnBndValidLDW_nu = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_SideCondLDPLe_btf
#define	S_DPLSIA_SideCondLDPLe_btf (DPLSIA_SenDbgPtr->S_DPLSIA_SideCondLDPLe_btf) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_SideCondLDPLe_btf(val)	(S_DPLSIA_SideCondLDPLe_btf = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_SideCondLDPRi_btf
#define	S_DPLSIA_SideCondLDPRi_btf (DPLSIA_SenDbgPtr->S_DPLSIA_SideCondLDPRi_btf) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_SideCondLDPRi_btf(val)	(S_DPLSIA_SideCondLDPRi_btf = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_SideCondLDWLe_btf
#define	S_DPLSIA_SideCondLDWLe_btf (DPLSIA_SenDbgPtr->S_DPLSIA_SideCondLDWLe_btf) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_SideCondLDWLe_btf(val)	(S_DPLSIA_SideCondLDWLe_btf = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_SideCondLDWRi_btf
#define	S_DPLSIA_SideCondLDWRi_btf (DPLSIA_SenDbgPtr->S_DPLSIA_SideCondLDWRi_btf) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_SideCondLDWRi_btf(val)	(S_DPLSIA_SideCondLDWRi_btf = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_SpecificLDP_btf
#define	S_DPLSIA_SpecificLDP_btf (DPLSIA_SenDbgPtr->S_DPLSIA_SpecificLDP_btf) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_SpecificLDP_btf(val)	(S_DPLSIA_SpecificLDP_btf = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_SpecificLDW_btf
#define	S_DPLSIA_SpecificLDW_btf (DPLSIA_SenDbgPtr->S_DPLSIA_SpecificLDW_btf) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_SpecificLDW_btf(val)	(S_DPLSIA_SpecificLDW_btf = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_TgtCntrLnEnable_bool
#define	S_DPLSIA_TgtCntrLnEnable_bool (DPLSIA_SenDbgPtr->S_DPLSIA_TgtCntrLnEnable_bool) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_TgtCntrLnEnable_bool(val)	(S_DPLSIA_TgtCntrLnEnable_bool = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_TlcLeLDP_sec
#define	S_DPLSIA_TlcLeLDP_sec (DPLSIA_SenDbgPtr->S_DPLSIA_TlcLeLDP_sec) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_TlcLeLDP_sec(val)	(S_DPLSIA_TlcLeLDP_sec = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_TlcLeLDW_sec
#define	S_DPLSIA_TlcLeLDW_sec (DPLSIA_SenDbgPtr->S_DPLSIA_TlcLeLDW_sec) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_TlcLeLDW_sec(val)	(S_DPLSIA_TlcLeLDW_sec = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_TlcRiLDP_sec
#define	S_DPLSIA_TlcRiLDP_sec (DPLSIA_SenDbgPtr->S_DPLSIA_TlcRiLDP_sec) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_TlcRiLDP_sec(val)	(S_DPLSIA_TlcRiLDP_sec = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_TlcRiLDW_sec
#define	S_DPLSIA_TlcRiLDW_sec (DPLSIA_SenDbgPtr->S_DPLSIA_TlcRiLDW_sec) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_TlcRiLDW_sec(val)	(S_DPLSIA_TlcRiLDW_sec = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_VelLatLeLDP_mps
#define	S_DPLSIA_VelLatLeLDP_mps (DPLSIA_SenDbgPtr->S_DPLSIA_VelLatLeLDP_mps) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_VelLatLeLDP_mps(val)	(S_DPLSIA_VelLatLeLDP_mps = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_VelLatLeLDW_mps
#define	S_DPLSIA_VelLatLeLDW_mps (DPLSIA_SenDbgPtr->S_DPLSIA_VelLatLeLDW_mps) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_VelLatLeLDW_mps(val)	(S_DPLSIA_VelLatLeLDW_mps = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_VelLatRiLDP_mps
#define	S_DPLSIA_VelLatRiLDP_mps (DPLSIA_SenDbgPtr->S_DPLSIA_VelLatRiLDP_mps) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_VelLatRiLDP_mps(val)	(S_DPLSIA_VelLatRiLDP_mps = (val)) //!< DPLSIA debug macro setter.

#undef	S_DPLSIA_VelLatRiLDW_mps
#define	S_DPLSIA_VelLatRiLDW_mps (DPLSIA_SenDbgPtr->S_DPLSIA_VelLatRiLDW_mps) //!< DPLSIA debug macro.
#define	SET_S_DPLSIA_VelLatRiLDW_mps(val)	(S_DPLSIA_VelLatRiLDW_mps = (val)) //!< DPLSIA debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // DPLSIA_PRIVATE_H_
