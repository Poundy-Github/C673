/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRSIA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRSIA_private.h
//! @brief     (LCRSIA) Module Private Header.

#ifndef LCRSIA_PRIVATE_H_
#define LCRSIA_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ALCASA	//!< ALCASA sub-component input macro switch.
#define LCRSIA	//!< LCRSIA module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCRSIA.h"
#include "Bitop.h"  //MFC5J3
#include "f32_calm.h"
#include "f32_math.h"
#include "LCRSIA_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_LCRSIA_SenReset		0xF0 //!< LCRSIA module reset runnable identifier.
#define RUNNABLE_ID_LCRSIA_SenProcess	0xF1 //!< LCRSIA module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static LCRSIA_SenDbgType *LCRSIA_SenDbgPtr = NULL; //!< LCRSIA module sensor debug data pointer.
void LCRSIA_SenInitDbgPtr(LCRSIA_SenDbgType *LCRSIA_SenDbgArg) { LCRSIA_SenDbgPtr = LCRSIA_SenDbgPtr == NULL ? LCRSIA_SenDbgArg : LCRSIA_SenDbgPtr; }
const LCRSIA_SenDbgType* LCRSIA_SenGetDbgPtr(void) { return (const LCRSIA_SenDbgType*) LCRSIA_SenDbgPtr; }

static LCRSIA_SenOutType *LCRSIA_SenOutPtr = NULL; //!< LCRSIA module sensor output data pointer.
void LCRSIA_SenInitOutPtr(LCRSIA_SenOutType *LCRSIA_SenOutArg) { LCRSIA_SenOutPtr = LCRSIA_SenOutPtr == NULL ? LCRSIA_SenOutArg : LCRSIA_SenOutPtr; }
const LCRSIA_SenOutType* LCRSIA_SenGetOutPtr(void) { return (const LCRSIA_SenOutType*) LCRSIA_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	D_LCRSIA_LnBndLeCancelValidALCA_bool
#define	D_LCRSIA_LnBndLeCancelValidALCA_bool (LCRSIA_SenDbgPtr->D_LCRSIA_LnBndLeCancelValidALCA_bool) //!< LCRSIA debug macro.
#define	SET_D_LCRSIA_LnBndLeCancelValidALCA_bool(val)	(D_LCRSIA_LnBndLeCancelValidALCA_bool = (val)) //!< LCRSIA debug macro setter.

#undef	D_LCRSIA_LnBndLeTrgValidALCA_bool
#define	D_LCRSIA_LnBndLeTrgValidALCA_bool (LCRSIA_SenDbgPtr->D_LCRSIA_LnBndLeTrgValidALCA_bool) //!< LCRSIA debug macro.
#define	SET_D_LCRSIA_LnBndLeTrgValidALCA_bool(val)	(D_LCRSIA_LnBndLeTrgValidALCA_bool = (val)) //!< LCRSIA debug macro setter.

#undef	D_LCRSIA_LnBndRiCancelValidALCA_bool
#define	D_LCRSIA_LnBndRiCancelValidALCA_bool (LCRSIA_SenDbgPtr->D_LCRSIA_LnBndRiCancelValidALCA_bool) //!< LCRSIA debug macro.
#define	SET_D_LCRSIA_LnBndRiCancelValidALCA_bool(val)	(D_LCRSIA_LnBndRiCancelValidALCA_bool = (val)) //!< LCRSIA debug macro setter.

#undef	D_LCRSIA_LnBndRiTrgValidALCA_bool
#define	D_LCRSIA_LnBndRiTrgValidALCA_bool (LCRSIA_SenDbgPtr->D_LCRSIA_LnBndRiTrgValidALCA_bool) //!< LCRSIA debug macro.
#define	SET_D_LCRSIA_LnBndRiTrgValidALCA_bool(val)	(D_LCRSIA_LnBndRiTrgValidALCA_bool = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_DlcLeALCA_met
#define	S_LCRSIA_DlcLeALCA_met (LCRSIA_SenDbgPtr->S_LCRSIA_DlcLeALCA_met) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_DlcLeALCA_met(val)	(S_LCRSIA_DlcLeALCA_met = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_DlcRiALCA_met
#define	S_LCRSIA_DlcRiALCA_met (LCRSIA_SenDbgPtr->S_LCRSIA_DlcRiALCA_met) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_DlcRiALCA_met(val)	(S_LCRSIA_DlcRiALCA_met = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_LnBndLeValidALCA_bool
#define	S_LCRSIA_LnBndLeValidALCA_bool (LCRSIA_SenDbgPtr->S_LCRSIA_LnBndLeValidALCA_bool) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_LnBndLeValidALCA_bool(val)	(S_LCRSIA_LnBndLeValidALCA_bool = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_LnBndRiValidALCA_bool
#define	S_LCRSIA_LnBndRiValidALCA_bool (LCRSIA_SenDbgPtr->S_LCRSIA_LnBndRiValidALCA_bool) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_LnBndRiValidALCA_bool(val)	(S_LCRSIA_LnBndRiValidALCA_bool = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_LnBndValidALCA_nu
#define	S_LCRSIA_LnBndValidALCA_nu (LCRSIA_SenDbgPtr->S_LCRSIA_LnBndValidALCA_nu) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_LnBndValidALCA_nu(val)	(S_LCRSIA_LnBndValidALCA_nu = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_SideCondALCALe_btf
#define	S_LCRSIA_SideCondALCALe_btf (LCRSIA_SenDbgPtr->S_LCRSIA_SideCondALCALe_btf) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_SideCondALCALe_btf(val)	(S_LCRSIA_SideCondALCALe_btf = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_SideCondALCARi_btf
#define	S_LCRSIA_SideCondALCARi_btf (LCRSIA_SenDbgPtr->S_LCRSIA_SideCondALCARi_btf) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_SideCondALCARi_btf(val)	(S_LCRSIA_SideCondALCARi_btf = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_SpecificALCA_btf
#define	S_LCRSIA_SpecificALCA_btf (LCRSIA_SenDbgPtr->S_LCRSIA_SpecificALCA_btf) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_SpecificALCA_btf(val)	(S_LCRSIA_SpecificALCA_btf = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_TlcLeALCA_sec
#define	S_LCRSIA_TlcLeALCA_sec (LCRSIA_SenDbgPtr->S_LCRSIA_TlcLeALCA_sec) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_TlcLeALCA_sec(val)	(S_LCRSIA_TlcLeALCA_sec = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_TlcRiALCA_sec
#define	S_LCRSIA_TlcRiALCA_sec (LCRSIA_SenDbgPtr->S_LCRSIA_TlcRiALCA_sec) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_TlcRiALCA_sec(val)	(S_LCRSIA_TlcRiALCA_sec = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_VelLatLeALCA_mps
#define	S_LCRSIA_VelLatLeALCA_mps (LCRSIA_SenDbgPtr->S_LCRSIA_VelLatLeALCA_mps) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_VelLatLeALCA_mps(val)	(S_LCRSIA_VelLatLeALCA_mps = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_VelLatRiALCA_mps
#define	S_LCRSIA_VelLatRiALCA_mps (LCRSIA_SenDbgPtr->S_LCRSIA_VelLatRiALCA_mps) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_VelLatRiALCA_mps(val)	(S_LCRSIA_VelLatRiALCA_mps = (val)) //!< LCRSIA debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_LCRSIA_CurveTypeLe_enum
#define	S_LCRSIA_CurveTypeLe_enum (LCRSIA_SenOutPtr->S_LCRSIA_CurveTypeLe_enum) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_CurveTypeLe_enum(val)	(S_LCRSIA_CurveTypeLe_enum = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_CurveTypeRi_enum
#define	S_LCRSIA_CurveTypeRi_enum (LCRSIA_SenOutPtr->S_LCRSIA_CurveTypeRi_enum) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_CurveTypeRi_enum(val)	(S_LCRSIA_CurveTypeRi_enum = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_LaneWidth_met
#define	S_LCRSIA_LaneWidth_met (LCRSIA_SenOutPtr->S_LCRSIA_LaneWidth_met) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_LaneWidth_met(val)	(S_LCRSIA_LaneWidth_met = (val)) //!< LCRSIA debug macro setter.

#undef	S_LCRSIA_TgtCntrLnEnable_bool
#define	S_LCRSIA_TgtCntrLnEnable_bool (LCRSIA_SenOutPtr->S_LCRSIA_TgtCntrLnEnable_bool) //!< LCRSIA debug macro.
#define	SET_S_LCRSIA_TgtCntrLnEnable_bool(val)	(S_LCRSIA_TgtCntrLnEnable_bool = (val)) //!< LCRSIA debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // LCRSIA_PRIVATE_H_
