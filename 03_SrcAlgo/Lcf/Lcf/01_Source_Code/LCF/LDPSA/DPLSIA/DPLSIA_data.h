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
//! @file     DPLSIA_data.h
//! @brief     (DPLSIA) Module Data Header.

#ifndef DPLSIA_DATA_H_
#define DPLSIA_DATA_H_

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
 *	DPLSIA module sensor get function. Function gets DPLSIA sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLSIA_SenDbgPtr</b> Global static pointer to DPLSIA sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLSIA_SenDbgType* DPLSIA_SenGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DPLSIA_LnBndLeCancelValidLDP_bool
#define D_DPLSIA_LnBndLeCancelValidLDP_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndLeCancelValidLDP_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndLeCancelValidLDP_bool() (D_DPLSIA_LnBndLeCancelValidLDP_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndLeCancelValidLDP_bool

#ifndef D_DPLSIA_LnBndLeCancelValidLDW_bool
#define D_DPLSIA_LnBndLeCancelValidLDW_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndLeCancelValidLDW_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndLeCancelValidLDW_bool() (D_DPLSIA_LnBndLeCancelValidLDW_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndLeCancelValidLDW_bool

#ifndef D_DPLSIA_LnBndLeTrgValidLDP_bool
#define D_DPLSIA_LnBndLeTrgValidLDP_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndLeTrgValidLDP_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndLeTrgValidLDP_bool() (D_DPLSIA_LnBndLeTrgValidLDP_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndLeTrgValidLDP_bool

#ifndef D_DPLSIA_LnBndLeTrgValidLDW_bool
#define D_DPLSIA_LnBndLeTrgValidLDW_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndLeTrgValidLDW_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndLeTrgValidLDW_bool() (D_DPLSIA_LnBndLeTrgValidLDW_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndLeTrgValidLDW_bool

#ifndef D_DPLSIA_LnBndRiCancelValidLDP_bool
#define D_DPLSIA_LnBndRiCancelValidLDP_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndRiCancelValidLDP_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndRiCancelValidLDP_bool() (D_DPLSIA_LnBndRiCancelValidLDP_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndRiCancelValidLDP_bool

#ifndef D_DPLSIA_LnBndRiCancelValidLDW_bool
#define D_DPLSIA_LnBndRiCancelValidLDW_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndRiCancelValidLDW_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndRiCancelValidLDW_bool() (D_DPLSIA_LnBndRiCancelValidLDW_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndRiCancelValidLDW_bool

#ifndef D_DPLSIA_LnBndRiTrgValidLDP_bool
#define D_DPLSIA_LnBndRiTrgValidLDP_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndRiTrgValidLDP_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndRiTrgValidLDP_bool() (D_DPLSIA_LnBndRiTrgValidLDP_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndRiTrgValidLDP_bool

#ifndef D_DPLSIA_LnBndRiTrgValidLDW_bool
#define D_DPLSIA_LnBndRiTrgValidLDW_bool (DPLSIA_SenGetDbgPtr()->D_DPLSIA_LnBndRiTrgValidLDW_bool) //!< DPLSIA debug macro.
#define GET_D_DPLSIA_LnBndRiTrgValidLDW_bool() (D_DPLSIA_LnBndRiTrgValidLDW_bool) //!< DPLSIA debug macro getter.
#endif // D_DPLSIA_LnBndRiTrgValidLDW_bool

#ifndef S_DPLSIA_CurveTypeLe_enum
#define S_DPLSIA_CurveTypeLe_enum (DPLSIA_SenGetDbgPtr()->S_DPLSIA_CurveTypeLe_enum) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_CurveTypeLe_enum() (S_DPLSIA_CurveTypeLe_enum) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_CurveTypeLe_enum

#ifndef S_DPLSIA_CurveTypeRi_enum
#define S_DPLSIA_CurveTypeRi_enum (DPLSIA_SenGetDbgPtr()->S_DPLSIA_CurveTypeRi_enum) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_CurveTypeRi_enum() (S_DPLSIA_CurveTypeRi_enum) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_CurveTypeRi_enum

#ifndef S_DPLSIA_DlcLeLDP_met
#define S_DPLSIA_DlcLeLDP_met (DPLSIA_SenGetDbgPtr()->S_DPLSIA_DlcLeLDP_met) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_DlcLeLDP_met() (S_DPLSIA_DlcLeLDP_met) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_DlcLeLDP_met

#ifndef S_DPLSIA_DlcLeLDW_met
#define S_DPLSIA_DlcLeLDW_met (DPLSIA_SenGetDbgPtr()->S_DPLSIA_DlcLeLDW_met) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_DlcLeLDW_met() (S_DPLSIA_DlcLeLDW_met) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_DlcLeLDW_met

#ifndef S_DPLSIA_DlcRiLDP_met
#define S_DPLSIA_DlcRiLDP_met (DPLSIA_SenGetDbgPtr()->S_DPLSIA_DlcRiLDP_met) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_DlcRiLDP_met() (S_DPLSIA_DlcRiLDP_met) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_DlcRiLDP_met

#ifndef S_DPLSIA_DlcRiLDW_met
#define S_DPLSIA_DlcRiLDW_met (DPLSIA_SenGetDbgPtr()->S_DPLSIA_DlcRiLDW_met) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_DlcRiLDW_met() (S_DPLSIA_DlcRiLDW_met) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_DlcRiLDW_met

#ifndef S_DPLSIA_LaneWidthLDP_met
#define S_DPLSIA_LaneWidthLDP_met (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LaneWidthLDP_met) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LaneWidthLDP_met() (S_DPLSIA_LaneWidthLDP_met) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LaneWidthLDP_met

#ifndef S_DPLSIA_LaneWidthLDW_met
#define S_DPLSIA_LaneWidthLDW_met (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LaneWidthLDW_met) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LaneWidthLDW_met() (S_DPLSIA_LaneWidthLDW_met) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LaneWidthLDW_met

#ifndef S_DPLSIA_LnBndLeValidLDP_bool
#define S_DPLSIA_LnBndLeValidLDP_bool (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LnBndLeValidLDP_bool) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LnBndLeValidLDP_bool() (S_DPLSIA_LnBndLeValidLDP_bool) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LnBndLeValidLDP_bool

#ifndef S_DPLSIA_LnBndLeValidLDW_bool
#define S_DPLSIA_LnBndLeValidLDW_bool (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LnBndLeValidLDW_bool) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LnBndLeValidLDW_bool() (S_DPLSIA_LnBndLeValidLDW_bool) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LnBndLeValidLDW_bool

#ifndef S_DPLSIA_LnBndRiValidLDP_bool
#define S_DPLSIA_LnBndRiValidLDP_bool (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LnBndRiValidLDP_bool) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LnBndRiValidLDP_bool() (S_DPLSIA_LnBndRiValidLDP_bool) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LnBndRiValidLDP_bool

#ifndef S_DPLSIA_LnBndRiValidLDW_bool
#define S_DPLSIA_LnBndRiValidLDW_bool (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LnBndRiValidLDW_bool) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LnBndRiValidLDW_bool() (S_DPLSIA_LnBndRiValidLDW_bool) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LnBndRiValidLDW_bool

#ifndef S_DPLSIA_LnBndValidLDP_nu
#define S_DPLSIA_LnBndValidLDP_nu (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LnBndValidLDP_nu) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LnBndValidLDP_nu() (S_DPLSIA_LnBndValidLDP_nu) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LnBndValidLDP_nu

#ifndef S_DPLSIA_LnBndValidLDW_nu
#define S_DPLSIA_LnBndValidLDW_nu (DPLSIA_SenGetDbgPtr()->S_DPLSIA_LnBndValidLDW_nu) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_LnBndValidLDW_nu() (S_DPLSIA_LnBndValidLDW_nu) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_LnBndValidLDW_nu

#ifndef S_DPLSIA_SideCondLDPLe_btf
#define S_DPLSIA_SideCondLDPLe_btf (DPLSIA_SenGetDbgPtr()->S_DPLSIA_SideCondLDPLe_btf) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_SideCondLDPLe_btf() (S_DPLSIA_SideCondLDPLe_btf) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_SideCondLDPLe_btf

#ifndef S_DPLSIA_SideCondLDPRi_btf
#define S_DPLSIA_SideCondLDPRi_btf (DPLSIA_SenGetDbgPtr()->S_DPLSIA_SideCondLDPRi_btf) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_SideCondLDPRi_btf() (S_DPLSIA_SideCondLDPRi_btf) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_SideCondLDPRi_btf

#ifndef S_DPLSIA_SideCondLDWLe_btf
#define S_DPLSIA_SideCondLDWLe_btf (DPLSIA_SenGetDbgPtr()->S_DPLSIA_SideCondLDWLe_btf) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_SideCondLDWLe_btf() (S_DPLSIA_SideCondLDWLe_btf) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_SideCondLDWLe_btf

#ifndef S_DPLSIA_SideCondLDWRi_btf
#define S_DPLSIA_SideCondLDWRi_btf (DPLSIA_SenGetDbgPtr()->S_DPLSIA_SideCondLDWRi_btf) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_SideCondLDWRi_btf() (S_DPLSIA_SideCondLDWRi_btf) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_SideCondLDWRi_btf

#ifndef S_DPLSIA_SpecificLDP_btf
#define S_DPLSIA_SpecificLDP_btf (DPLSIA_SenGetDbgPtr()->S_DPLSIA_SpecificLDP_btf) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_SpecificLDP_btf() (S_DPLSIA_SpecificLDP_btf) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_SpecificLDP_btf

#ifndef S_DPLSIA_SpecificLDW_btf
#define S_DPLSIA_SpecificLDW_btf (DPLSIA_SenGetDbgPtr()->S_DPLSIA_SpecificLDW_btf) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_SpecificLDW_btf() (S_DPLSIA_SpecificLDW_btf) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_SpecificLDW_btf

#ifndef S_DPLSIA_TgtCntrLnEnable_bool
#define S_DPLSIA_TgtCntrLnEnable_bool (DPLSIA_SenGetDbgPtr()->S_DPLSIA_TgtCntrLnEnable_bool) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_TgtCntrLnEnable_bool() (S_DPLSIA_TgtCntrLnEnable_bool) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_TgtCntrLnEnable_bool

#ifndef S_DPLSIA_TlcLeLDP_sec
#define S_DPLSIA_TlcLeLDP_sec (DPLSIA_SenGetDbgPtr()->S_DPLSIA_TlcLeLDP_sec) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_TlcLeLDP_sec() (S_DPLSIA_TlcLeLDP_sec) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_TlcLeLDP_sec

#ifndef S_DPLSIA_TlcLeLDW_sec
#define S_DPLSIA_TlcLeLDW_sec (DPLSIA_SenGetDbgPtr()->S_DPLSIA_TlcLeLDW_sec) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_TlcLeLDW_sec() (S_DPLSIA_TlcLeLDW_sec) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_TlcLeLDW_sec

#ifndef S_DPLSIA_TlcRiLDP_sec
#define S_DPLSIA_TlcRiLDP_sec (DPLSIA_SenGetDbgPtr()->S_DPLSIA_TlcRiLDP_sec) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_TlcRiLDP_sec() (S_DPLSIA_TlcRiLDP_sec) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_TlcRiLDP_sec

#ifndef S_DPLSIA_TlcRiLDW_sec
#define S_DPLSIA_TlcRiLDW_sec (DPLSIA_SenGetDbgPtr()->S_DPLSIA_TlcRiLDW_sec) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_TlcRiLDW_sec() (S_DPLSIA_TlcRiLDW_sec) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_TlcRiLDW_sec

#ifndef S_DPLSIA_VelLatLeLDP_mps
#define S_DPLSIA_VelLatLeLDP_mps (DPLSIA_SenGetDbgPtr()->S_DPLSIA_VelLatLeLDP_mps) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_VelLatLeLDP_mps() (S_DPLSIA_VelLatLeLDP_mps) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_VelLatLeLDP_mps

#ifndef S_DPLSIA_VelLatLeLDW_mps
#define S_DPLSIA_VelLatLeLDW_mps (DPLSIA_SenGetDbgPtr()->S_DPLSIA_VelLatLeLDW_mps) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_VelLatLeLDW_mps() (S_DPLSIA_VelLatLeLDW_mps) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_VelLatLeLDW_mps

#ifndef S_DPLSIA_VelLatRiLDP_mps
#define S_DPLSIA_VelLatRiLDP_mps (DPLSIA_SenGetDbgPtr()->S_DPLSIA_VelLatRiLDP_mps) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_VelLatRiLDP_mps() (S_DPLSIA_VelLatRiLDP_mps) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_VelLatRiLDP_mps

#ifndef S_DPLSIA_VelLatRiLDW_mps
#define S_DPLSIA_VelLatRiLDW_mps (DPLSIA_SenGetDbgPtr()->S_DPLSIA_VelLatRiLDW_mps) //!< DPLSIA debug macro.
#define GET_S_DPLSIA_VelLatRiLDW_mps() (S_DPLSIA_VelLatRiLDW_mps) //!< DPLSIA debug macro getter.
#endif // S_DPLSIA_VelLatRiLDW_mps

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // DPLSIA_DATA_H_
