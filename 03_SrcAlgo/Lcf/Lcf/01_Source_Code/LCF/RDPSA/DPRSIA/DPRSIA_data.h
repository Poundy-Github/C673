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
//! @file     DPRSIA_data.h
//! @brief     (DPRSIA) Module Data Header.

#ifndef DPRSIA_DATA_H_
#define DPRSIA_DATA_H_

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
 *	DPRSIA module sensor get function. Function gets DPRSIA sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRSIA_SenDbgPtr</b> Global static pointer to DPRSIA sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRSIA_SenDbgType* DPRSIA_SenGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_DPRSIA_LnBndLeCancelValidRDP_bool
#define D_DPRSIA_LnBndLeCancelValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndLeCancelValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndLeCancelValidRDP_bool() (D_DPRSIA_LnBndLeCancelValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndLeCancelValidRDP_bool

#ifndef D_DPRSIA_LnBndLeCancelValidRDW_bool
#define D_DPRSIA_LnBndLeCancelValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndLeCancelValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndLeCancelValidRDW_bool() (D_DPRSIA_LnBndLeCancelValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndLeCancelValidRDW_bool

#ifndef D_DPRSIA_LnBndLeTrgValidRDP_bool
#define D_DPRSIA_LnBndLeTrgValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndLeTrgValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndLeTrgValidRDP_bool() (D_DPRSIA_LnBndLeTrgValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndLeTrgValidRDP_bool

#ifndef D_DPRSIA_LnBndLeTrgValidRDW_bool
#define D_DPRSIA_LnBndLeTrgValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndLeTrgValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndLeTrgValidRDW_bool() (D_DPRSIA_LnBndLeTrgValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndLeTrgValidRDW_bool

#ifndef D_DPRSIA_LnBndRiCancelValidRDP_bool
#define D_DPRSIA_LnBndRiCancelValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndRiCancelValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndRiCancelValidRDP_bool() (D_DPRSIA_LnBndRiCancelValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndRiCancelValidRDP_bool

#ifndef D_DPRSIA_LnBndRiCancelValidRDW_bool
#define D_DPRSIA_LnBndRiCancelValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndRiCancelValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndRiCancelValidRDW_bool() (D_DPRSIA_LnBndRiCancelValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndRiCancelValidRDW_bool

#ifndef D_DPRSIA_LnBndRiTrgValidRDP_bool
#define D_DPRSIA_LnBndRiTrgValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndRiTrgValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndRiTrgValidRDP_bool() (D_DPRSIA_LnBndRiTrgValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndRiTrgValidRDP_bool

#ifndef D_DPRSIA_LnBndRiTrgValidRDW_bool
#define D_DPRSIA_LnBndRiTrgValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_LnBndRiTrgValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_LnBndRiTrgValidRDW_bool() (D_DPRSIA_LnBndRiTrgValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_LnBndRiTrgValidRDW_bool

#ifndef D_DPRSIA_RdBndLeCancelValidRDP_bool
#define D_DPRSIA_RdBndLeCancelValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndLeCancelValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndLeCancelValidRDP_bool() (D_DPRSIA_RdBndLeCancelValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndLeCancelValidRDP_bool

#ifndef D_DPRSIA_RdBndLeCancelValidRDW_bool
#define D_DPRSIA_RdBndLeCancelValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndLeCancelValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndLeCancelValidRDW_bool() (D_DPRSIA_RdBndLeCancelValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndLeCancelValidRDW_bool

#ifndef D_DPRSIA_RdBndLeTrgValidRDP_bool
#define D_DPRSIA_RdBndLeTrgValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndLeTrgValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndLeTrgValidRDP_bool() (D_DPRSIA_RdBndLeTrgValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndLeTrgValidRDP_bool

#ifndef D_DPRSIA_RdBndLeTrgValidRDW_bool
#define D_DPRSIA_RdBndLeTrgValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndLeTrgValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndLeTrgValidRDW_bool() (D_DPRSIA_RdBndLeTrgValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndLeTrgValidRDW_bool

#ifndef D_DPRSIA_RdBndRiCancelValidRDP_bool
#define D_DPRSIA_RdBndRiCancelValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndRiCancelValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndRiCancelValidRDP_bool() (D_DPRSIA_RdBndRiCancelValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndRiCancelValidRDP_bool

#ifndef D_DPRSIA_RdBndRiCancelValidRDW_bool
#define D_DPRSIA_RdBndRiCancelValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndRiCancelValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndRiCancelValidRDW_bool() (D_DPRSIA_RdBndRiCancelValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndRiCancelValidRDW_bool

#ifndef D_DPRSIA_RdBndRiTrgValidRDP_bool
#define D_DPRSIA_RdBndRiTrgValidRDP_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndRiTrgValidRDP_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndRiTrgValidRDP_bool() (D_DPRSIA_RdBndRiTrgValidRDP_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndRiTrgValidRDP_bool

#ifndef D_DPRSIA_RdBndRiTrgValidRDW_bool
#define D_DPRSIA_RdBndRiTrgValidRDW_bool (DPRSIA_SenGetDbgPtr()->D_DPRSIA_RdBndRiTrgValidRDW_bool) //!< DPRSIA debug macro.
#define GET_D_DPRSIA_RdBndRiTrgValidRDW_bool() (D_DPRSIA_RdBndRiTrgValidRDW_bool) //!< DPRSIA debug macro getter.
#endif // D_DPRSIA_RdBndRiTrgValidRDW_bool

#ifndef S_DPRSIA_DlcLeRDP_met
#define S_DPRSIA_DlcLeRDP_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DlcLeRDP_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DlcLeRDP_met() (S_DPRSIA_DlcLeRDP_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DlcLeRDP_met

#ifndef S_DPRSIA_DlcLeRDW_met
#define S_DPRSIA_DlcLeRDW_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DlcLeRDW_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DlcLeRDW_met() (S_DPRSIA_DlcLeRDW_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DlcLeRDW_met

#ifndef S_DPRSIA_DlcRiRDP_met
#define S_DPRSIA_DlcRiRDP_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DlcRiRDP_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DlcRiRDP_met() (S_DPRSIA_DlcRiRDP_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DlcRiRDP_met

#ifndef S_DPRSIA_DlcRiRDW_met
#define S_DPRSIA_DlcRiRDW_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DlcRiRDW_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DlcRiRDW_met() (S_DPRSIA_DlcRiRDW_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DlcRiRDW_met

#ifndef S_DPRSIA_DrcLeRDP_met
#define S_DPRSIA_DrcLeRDP_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DrcLeRDP_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DrcLeRDP_met() (S_DPRSIA_DrcLeRDP_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DrcLeRDP_met

#ifndef S_DPRSIA_DrcLeRDW_met
#define S_DPRSIA_DrcLeRDW_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DrcLeRDW_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DrcLeRDW_met() (S_DPRSIA_DrcLeRDW_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DrcLeRDW_met

#ifndef S_DPRSIA_DrcRiRDP_met
#define S_DPRSIA_DrcRiRDP_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DrcRiRDP_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DrcRiRDP_met() (S_DPRSIA_DrcRiRDP_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DrcRiRDP_met

#ifndef S_DPRSIA_DrcRiRDW_met
#define S_DPRSIA_DrcRiRDW_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_DrcRiRDW_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_DrcRiRDW_met() (S_DPRSIA_DrcRiRDW_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_DrcRiRDW_met

#ifndef S_DPRSIA_LaneWidthRDP_met
#define S_DPRSIA_LaneWidthRDP_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_LaneWidthRDP_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_LaneWidthRDP_met() (S_DPRSIA_LaneWidthRDP_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_LaneWidthRDP_met

#ifndef S_DPRSIA_LaneWidthRDW_met
#define S_DPRSIA_LaneWidthRDW_met (DPRSIA_SenGetDbgPtr()->S_DPRSIA_LaneWidthRDW_met) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_LaneWidthRDW_met() (S_DPRSIA_LaneWidthRDW_met) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_LaneWidthRDW_met

#ifndef S_DPRSIA_LnBndValidRDP_nu
#define S_DPRSIA_LnBndValidRDP_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_LnBndValidRDP_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_LnBndValidRDP_nu() (S_DPRSIA_LnBndValidRDP_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_LnBndValidRDP_nu

#ifndef S_DPRSIA_LnBndValidRDW_nu
#define S_DPRSIA_LnBndValidRDW_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_LnBndValidRDW_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_LnBndValidRDW_nu() (S_DPRSIA_LnBndValidRDW_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_LnBndValidRDW_nu

#ifndef S_DPRSIA_RdBndValidRDP_nu
#define S_DPRSIA_RdBndValidRDP_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_RdBndValidRDP_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_RdBndValidRDP_nu() (S_DPRSIA_RdBndValidRDP_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_RdBndValidRDP_nu

#ifndef S_DPRSIA_RdBndValidRDW_nu
#define S_DPRSIA_RdBndValidRDW_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_RdBndValidRDW_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_RdBndValidRDW_nu() (S_DPRSIA_RdBndValidRDW_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_RdBndValidRDW_nu

#ifndef S_DPRSIA_SideCondRDPLe_btf
#define S_DPRSIA_SideCondRDPLe_btf (DPRSIA_SenGetDbgPtr()->S_DPRSIA_SideCondRDPLe_btf) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_SideCondRDPLe_btf() (S_DPRSIA_SideCondRDPLe_btf) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_SideCondRDPLe_btf

#ifndef S_DPRSIA_SideCondRDPRi_btf
#define S_DPRSIA_SideCondRDPRi_btf (DPRSIA_SenGetDbgPtr()->S_DPRSIA_SideCondRDPRi_btf) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_SideCondRDPRi_btf() (S_DPRSIA_SideCondRDPRi_btf) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_SideCondRDPRi_btf

#ifndef S_DPRSIA_SideCondRDWLe_btf
#define S_DPRSIA_SideCondRDWLe_btf (DPRSIA_SenGetDbgPtr()->S_DPRSIA_SideCondRDWLe_btf) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_SideCondRDWLe_btf() (S_DPRSIA_SideCondRDWLe_btf) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_SideCondRDWLe_btf

#ifndef S_DPRSIA_SideCondRDWRi_btf
#define S_DPRSIA_SideCondRDWRi_btf (DPRSIA_SenGetDbgPtr()->S_DPRSIA_SideCondRDWRi_btf) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_SideCondRDWRi_btf() (S_DPRSIA_SideCondRDWRi_btf) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_SideCondRDWRi_btf

#ifndef S_DPRSIA_SpecificRDP_btf
#define S_DPRSIA_SpecificRDP_btf (DPRSIA_SenGetDbgPtr()->S_DPRSIA_SpecificRDP_btf) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_SpecificRDP_btf() (S_DPRSIA_SpecificRDP_btf) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_SpecificRDP_btf

#ifndef S_DPRSIA_SpecificRDW_btf
#define S_DPRSIA_SpecificRDW_btf (DPRSIA_SenGetDbgPtr()->S_DPRSIA_SpecificRDW_btf) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_SpecificRDW_btf() (S_DPRSIA_SpecificRDW_btf) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_SpecificRDW_btf

#ifndef S_DPRSIA_TgtCntrLnEnable_bool
#define S_DPRSIA_TgtCntrLnEnable_bool (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TgtCntrLnEnable_bool) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TgtCntrLnEnable_bool() (S_DPRSIA_TgtCntrLnEnable_bool) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TgtCntrLnEnable_bool

#ifndef S_DPRSIA_TlcLeRDP_sec
#define S_DPRSIA_TlcLeRDP_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TlcLeRDP_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TlcLeRDP_sec() (S_DPRSIA_TlcLeRDP_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TlcLeRDP_sec

#ifndef S_DPRSIA_TlcLeRDW_sec
#define S_DPRSIA_TlcLeRDW_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TlcLeRDW_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TlcLeRDW_sec() (S_DPRSIA_TlcLeRDW_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TlcLeRDW_sec

#ifndef S_DPRSIA_TlcRiRDP_sec
#define S_DPRSIA_TlcRiRDP_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TlcRiRDP_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TlcRiRDP_sec() (S_DPRSIA_TlcRiRDP_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TlcRiRDP_sec

#ifndef S_DPRSIA_TlcRiRDW_sec
#define S_DPRSIA_TlcRiRDW_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TlcRiRDW_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TlcRiRDW_sec() (S_DPRSIA_TlcRiRDW_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TlcRiRDW_sec

#ifndef S_DPRSIA_TrcLeRDP_sec
#define S_DPRSIA_TrcLeRDP_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TrcLeRDP_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TrcLeRDP_sec() (S_DPRSIA_TrcLeRDP_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TrcLeRDP_sec

#ifndef S_DPRSIA_TrcLeRDW_sec
#define S_DPRSIA_TrcLeRDW_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TrcLeRDW_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TrcLeRDW_sec() (S_DPRSIA_TrcLeRDW_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TrcLeRDW_sec

#ifndef S_DPRSIA_TrcRiRDP_sec
#define S_DPRSIA_TrcRiRDP_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TrcRiRDP_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TrcRiRDP_sec() (S_DPRSIA_TrcRiRDP_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TrcRiRDP_sec

#ifndef S_DPRSIA_TrcRiRDW_sec
#define S_DPRSIA_TrcRiRDW_sec (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TrcRiRDW_sec) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TrcRiRDW_sec() (S_DPRSIA_TrcRiRDW_sec) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TrcRiRDW_sec

#ifndef S_DPRSIA_TriggerReasonLeRDP_nu
#define S_DPRSIA_TriggerReasonLeRDP_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TriggerReasonLeRDP_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TriggerReasonLeRDP_nu() (S_DPRSIA_TriggerReasonLeRDP_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TriggerReasonLeRDP_nu

#ifndef S_DPRSIA_TriggerReasonLeRDW_nu
#define S_DPRSIA_TriggerReasonLeRDW_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TriggerReasonLeRDW_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TriggerReasonLeRDW_nu() (S_DPRSIA_TriggerReasonLeRDW_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TriggerReasonLeRDW_nu

#ifndef S_DPRSIA_TriggerReasonRiRDP_nu
#define S_DPRSIA_TriggerReasonRiRDP_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TriggerReasonRiRDP_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TriggerReasonRiRDP_nu() (S_DPRSIA_TriggerReasonRiRDP_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TriggerReasonRiRDP_nu

#ifndef S_DPRSIA_TriggerReasonRiRDW_nu
#define S_DPRSIA_TriggerReasonRiRDW_nu (DPRSIA_SenGetDbgPtr()->S_DPRSIA_TriggerReasonRiRDW_nu) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_TriggerReasonRiRDW_nu() (S_DPRSIA_TriggerReasonRiRDW_nu) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_TriggerReasonRiRDW_nu

#ifndef S_DPRSIA_VelLatLnLeRDP_mps
#define S_DPRSIA_VelLatLnLeRDP_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatLnLeRDP_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatLnLeRDP_mps() (S_DPRSIA_VelLatLnLeRDP_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatLnLeRDP_mps

#ifndef S_DPRSIA_VelLatLnLeRDW_mps
#define S_DPRSIA_VelLatLnLeRDW_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatLnLeRDW_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatLnLeRDW_mps() (S_DPRSIA_VelLatLnLeRDW_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatLnLeRDW_mps

#ifndef S_DPRSIA_VelLatLnRiRDP_mps
#define S_DPRSIA_VelLatLnRiRDP_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatLnRiRDP_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatLnRiRDP_mps() (S_DPRSIA_VelLatLnRiRDP_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatLnRiRDP_mps

#ifndef S_DPRSIA_VelLatLnRiRDW_mps
#define S_DPRSIA_VelLatLnRiRDW_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatLnRiRDW_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatLnRiRDW_mps() (S_DPRSIA_VelLatLnRiRDW_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatLnRiRDW_mps

#ifndef S_DPRSIA_VelLatReLeRDP_mps
#define S_DPRSIA_VelLatReLeRDP_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatReLeRDP_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatReLeRDP_mps() (S_DPRSIA_VelLatReLeRDP_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatReLeRDP_mps

#ifndef S_DPRSIA_VelLatReLeRDW_mps
#define S_DPRSIA_VelLatReLeRDW_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatReLeRDW_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatReLeRDW_mps() (S_DPRSIA_VelLatReLeRDW_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatReLeRDW_mps

#ifndef S_DPRSIA_VelLatReRiRDP_mps
#define S_DPRSIA_VelLatReRiRDP_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatReRiRDP_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatReRiRDP_mps() (S_DPRSIA_VelLatReRiRDP_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatReRiRDP_mps

#ifndef S_DPRSIA_VelLatReRiRDW_mps
#define S_DPRSIA_VelLatReRiRDW_mps (DPRSIA_SenGetDbgPtr()->S_DPRSIA_VelLatReRiRDW_mps) //!< DPRSIA debug macro.
#define GET_S_DPRSIA_VelLatReRiRDW_mps() (S_DPRSIA_VelLatReRiRDW_mps) //!< DPRSIA debug macro getter.
#endif // S_DPRSIA_VelLatReRiRDW_mps

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // DPRSIA_DATA_H_
