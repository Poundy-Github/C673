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
//! @file     LCRSIA_data.h
//! @brief     (LCRSIA) Module Data Header.

#ifndef LCRSIA_DATA_H_
#define LCRSIA_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"
#include "LCRSIA_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCRSIA module sensor get function. Function gets LCRSIA sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRSIA_SenDbgPtr</b> Global static pointer to LCRSIA sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRSIA_SenDbgType* LCRSIA_SenGetDbgPtr(void);

/*!
 *	LCRSIA module sensor get function. Function gets LCRSIA sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRSIA_SenOutPtr</b> Global static pointer to LCRSIA sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRSIA_SenOutType* LCRSIA_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_LCRSIA_LnBndLeCancelValidALCA_bool
#define D_LCRSIA_LnBndLeCancelValidALCA_bool (LCRSIA_SenGetDbgPtr()->D_LCRSIA_LnBndLeCancelValidALCA_bool) //!< LCRSIA debug macro.
#define GET_D_LCRSIA_LnBndLeCancelValidALCA_bool() (D_LCRSIA_LnBndLeCancelValidALCA_bool) //!< LCRSIA debug macro getter.
#endif // D_LCRSIA_LnBndLeCancelValidALCA_bool

#ifndef D_LCRSIA_LnBndLeTrgValidALCA_bool
#define D_LCRSIA_LnBndLeTrgValidALCA_bool (LCRSIA_SenGetDbgPtr()->D_LCRSIA_LnBndLeTrgValidALCA_bool) //!< LCRSIA debug macro.
#define GET_D_LCRSIA_LnBndLeTrgValidALCA_bool() (D_LCRSIA_LnBndLeTrgValidALCA_bool) //!< LCRSIA debug macro getter.
#endif // D_LCRSIA_LnBndLeTrgValidALCA_bool

#ifndef D_LCRSIA_LnBndRiCancelValidALCA_bool
#define D_LCRSIA_LnBndRiCancelValidALCA_bool (LCRSIA_SenGetDbgPtr()->D_LCRSIA_LnBndRiCancelValidALCA_bool) //!< LCRSIA debug macro.
#define GET_D_LCRSIA_LnBndRiCancelValidALCA_bool() (D_LCRSIA_LnBndRiCancelValidALCA_bool) //!< LCRSIA debug macro getter.
#endif // D_LCRSIA_LnBndRiCancelValidALCA_bool

#ifndef D_LCRSIA_LnBndRiTrgValidALCA_bool
#define D_LCRSIA_LnBndRiTrgValidALCA_bool (LCRSIA_SenGetDbgPtr()->D_LCRSIA_LnBndRiTrgValidALCA_bool) //!< LCRSIA debug macro.
#define GET_D_LCRSIA_LnBndRiTrgValidALCA_bool() (D_LCRSIA_LnBndRiTrgValidALCA_bool) //!< LCRSIA debug macro getter.
#endif // D_LCRSIA_LnBndRiTrgValidALCA_bool

#ifndef S_LCRSIA_DlcLeALCA_met
#define S_LCRSIA_DlcLeALCA_met (LCRSIA_SenGetDbgPtr()->S_LCRSIA_DlcLeALCA_met) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_DlcLeALCA_met() (S_LCRSIA_DlcLeALCA_met) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_DlcLeALCA_met

#ifndef S_LCRSIA_DlcRiALCA_met
#define S_LCRSIA_DlcRiALCA_met (LCRSIA_SenGetDbgPtr()->S_LCRSIA_DlcRiALCA_met) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_DlcRiALCA_met() (S_LCRSIA_DlcRiALCA_met) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_DlcRiALCA_met

#ifndef S_LCRSIA_LnBndLeValidALCA_bool
#define S_LCRSIA_LnBndLeValidALCA_bool (LCRSIA_SenGetDbgPtr()->S_LCRSIA_LnBndLeValidALCA_bool) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_LnBndLeValidALCA_bool() (S_LCRSIA_LnBndLeValidALCA_bool) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_LnBndLeValidALCA_bool

#ifndef S_LCRSIA_LnBndRiValidALCA_bool
#define S_LCRSIA_LnBndRiValidALCA_bool (LCRSIA_SenGetDbgPtr()->S_LCRSIA_LnBndRiValidALCA_bool) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_LnBndRiValidALCA_bool() (S_LCRSIA_LnBndRiValidALCA_bool) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_LnBndRiValidALCA_bool

#ifndef S_LCRSIA_LnBndValidALCA_nu
#define S_LCRSIA_LnBndValidALCA_nu (LCRSIA_SenGetDbgPtr()->S_LCRSIA_LnBndValidALCA_nu) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_LnBndValidALCA_nu() (S_LCRSIA_LnBndValidALCA_nu) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_LnBndValidALCA_nu

#ifndef S_LCRSIA_SideCondALCALe_btf
#define S_LCRSIA_SideCondALCALe_btf (LCRSIA_SenGetDbgPtr()->S_LCRSIA_SideCondALCALe_btf) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_SideCondALCALe_btf() (S_LCRSIA_SideCondALCALe_btf) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_SideCondALCALe_btf

#ifndef S_LCRSIA_SideCondALCARi_btf
#define S_LCRSIA_SideCondALCARi_btf (LCRSIA_SenGetDbgPtr()->S_LCRSIA_SideCondALCARi_btf) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_SideCondALCARi_btf() (S_LCRSIA_SideCondALCARi_btf) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_SideCondALCARi_btf

#ifndef S_LCRSIA_SpecificALCA_btf
#define S_LCRSIA_SpecificALCA_btf (LCRSIA_SenGetDbgPtr()->S_LCRSIA_SpecificALCA_btf) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_SpecificALCA_btf() (S_LCRSIA_SpecificALCA_btf) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_SpecificALCA_btf

#ifndef S_LCRSIA_TlcLeALCA_sec
#define S_LCRSIA_TlcLeALCA_sec (LCRSIA_SenGetDbgPtr()->S_LCRSIA_TlcLeALCA_sec) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_TlcLeALCA_sec() (S_LCRSIA_TlcLeALCA_sec) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_TlcLeALCA_sec

#ifndef S_LCRSIA_TlcRiALCA_sec
#define S_LCRSIA_TlcRiALCA_sec (LCRSIA_SenGetDbgPtr()->S_LCRSIA_TlcRiALCA_sec) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_TlcRiALCA_sec() (S_LCRSIA_TlcRiALCA_sec) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_TlcRiALCA_sec

#ifndef S_LCRSIA_VelLatLeALCA_mps
#define S_LCRSIA_VelLatLeALCA_mps (LCRSIA_SenGetDbgPtr()->S_LCRSIA_VelLatLeALCA_mps) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_VelLatLeALCA_mps() (S_LCRSIA_VelLatLeALCA_mps) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_VelLatLeALCA_mps

#ifndef S_LCRSIA_VelLatRiALCA_mps
#define S_LCRSIA_VelLatRiALCA_mps (LCRSIA_SenGetDbgPtr()->S_LCRSIA_VelLatRiALCA_mps) //!< LCRSIA debug macro.
#define GET_S_LCRSIA_VelLatRiALCA_mps() (S_LCRSIA_VelLatRiALCA_mps) //!< LCRSIA debug macro getter.
#endif // S_LCRSIA_VelLatRiALCA_mps

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_LCRSIA_CurveTypeLe_enum
#define S_LCRSIA_CurveTypeLe_enum (LCRSIA_SenGetOutPtr()->S_LCRSIA_CurveTypeLe_enum) //!< LCRSIA output macro.
#define GET_S_LCRSIA_CurveTypeLe_enum() (S_LCRSIA_CurveTypeLe_enum) //!< LCRSIA output macro getter.
#endif // S_LCRSIA_CurveTypeLe_enum

#ifndef S_LCRSIA_CurveTypeRi_enum
#define S_LCRSIA_CurveTypeRi_enum (LCRSIA_SenGetOutPtr()->S_LCRSIA_CurveTypeRi_enum) //!< LCRSIA output macro.
#define GET_S_LCRSIA_CurveTypeRi_enum() (S_LCRSIA_CurveTypeRi_enum) //!< LCRSIA output macro getter.
#endif // S_LCRSIA_CurveTypeRi_enum

#ifndef S_LCRSIA_LaneWidth_met
#define S_LCRSIA_LaneWidth_met (LCRSIA_SenGetOutPtr()->S_LCRSIA_LaneWidth_met) //!< LCRSIA output macro.
#define GET_S_LCRSIA_LaneWidth_met() (S_LCRSIA_LaneWidth_met) //!< LCRSIA output macro getter.
#endif // S_LCRSIA_LaneWidth_met

#ifndef S_LCRSIA_TgtCntrLnEnable_bool
#define S_LCRSIA_TgtCntrLnEnable_bool (LCRSIA_SenGetOutPtr()->S_LCRSIA_TgtCntrLnEnable_bool) //!< LCRSIA output macro.
#define GET_S_LCRSIA_TgtCntrLnEnable_bool() (S_LCRSIA_TgtCntrLnEnable_bool) //!< LCRSIA output macro getter.
#endif // S_LCRSIA_TgtCntrLnEnable_bool

#ifdef __cplusplus
}
#endif

#endif // LCRSIA_DATA_H_
