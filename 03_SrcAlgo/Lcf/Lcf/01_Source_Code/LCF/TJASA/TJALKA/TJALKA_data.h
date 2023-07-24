/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJALKA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJALKA_data.h
//! @brief     (TJALKA) Module Data Header.

#ifndef TJALKA_DATA_H_
#define TJALKA_DATA_H_

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
 *	TJALKA module sensor get function. Function gets TJALKA sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJALKA_SenDbgPtr</b> Global static pointer to TJALKA sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJALKA_SenDbgType* TJALKA_SenGetDbgPtr(void);

/*!
 *	TJALKA module sensor get function. Function gets TJALKA sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJALKA_SenOutPtr</b> Global static pointer to TJALKA sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJALKA_SenOutType* TJALKA_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJALKA_LaneCenterInvalid_btf
#define D_TJALKA_LaneCenterInvalid_btf (TJALKA_SenGetDbgPtr()->D_TJALKA_LaneCenterInvalid_btf) //!< TJALKA debug macro.
#define GET_D_TJALKA_LaneCenterInvalid_btf() (D_TJALKA_LaneCenterInvalid_btf) //!< TJALKA debug macro getter.
#endif // D_TJALKA_LaneCenterInvalid_btf

#ifndef S_TJALKA_Cancel_bool
#define S_TJALKA_Cancel_bool (TJALKA_SenGetDbgPtr()->S_TJALKA_Cancel_bool) //!< TJALKA debug macro.
#define GET_S_TJALKA_Cancel_bool() (S_TJALKA_Cancel_bool) //!< TJALKA debug macro getter.
#endif // S_TJALKA_Cancel_bool

#ifndef S_TJALKA_LanePredictValid_bool
#define S_TJALKA_LanePredictValid_bool (TJALKA_SenGetDbgPtr()->S_TJALKA_LanePredictValid_bool) //!< TJALKA debug macro.
#define GET_S_TJALKA_LanePredictValid_bool() (S_TJALKA_LanePredictValid_bool) //!< TJALKA debug macro getter.
#endif // S_TJALKA_LanePredictValid_bool

#ifndef S_TJALKA_LnBndValid_nu
#define S_TJALKA_LnBndValid_nu (TJALKA_SenGetDbgPtr()->S_TJALKA_LnBndValid_nu) //!< TJALKA debug macro.
#define GET_S_TJALKA_LnBndValid_nu() (S_TJALKA_LnBndValid_nu) //!< TJALKA debug macro getter.
#endif // S_TJALKA_LnBndValid_nu

#ifndef S_TJALKA_StrongReady_bool
#define S_TJALKA_StrongReady_bool (TJALKA_SenGetDbgPtr()->S_TJALKA_StrongReady_bool) //!< TJALKA debug macro.
#define GET_S_TJALKA_StrongReady_bool() (S_TJALKA_StrongReady_bool) //!< TJALKA debug macro getter.
#endif // S_TJALKA_StrongReady_bool

#ifndef S_TJALKA_WeakReady_bool
#define S_TJALKA_WeakReady_bool (TJALKA_SenGetDbgPtr()->S_TJALKA_WeakReady_bool) //!< TJALKA debug macro.
#define GET_S_TJALKA_WeakReady_bool() (S_TJALKA_WeakReady_bool) //!< TJALKA debug macro getter.
#endif // S_TJALKA_WeakReady_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJALKA_LaneInvalid_btf
#define D_TJALKA_LaneInvalid_btf (TJALKA_SenGetOutPtr()->D_TJALKA_LaneInvalid_btf) //!< TJALKA output macro.
#define GET_D_TJALKA_LaneInvalid_btf() (D_TJALKA_LaneInvalid_btf) //!< TJALKA output macro getter.
#endif // D_TJALKA_LaneInvalid_btf

#ifndef S_TJALKA_CombinedLaneSR_bool
#define S_TJALKA_CombinedLaneSR_bool (TJALKA_SenGetOutPtr()->S_TJALKA_CombinedLaneSR_bool) //!< TJALKA output macro.
#define GET_S_TJALKA_CombinedLaneSR_bool() (S_TJALKA_CombinedLaneSR_bool) //!< TJALKA output macro getter.
#endif // S_TJALKA_CombinedLaneSR_bool

#ifndef S_TJALKA_CombinedLaneWR_bool
#define S_TJALKA_CombinedLaneWR_bool (TJALKA_SenGetOutPtr()->S_TJALKA_CombinedLaneWR_bool) //!< TJALKA output macro.
#define GET_S_TJALKA_CombinedLaneWR_bool() (S_TJALKA_CombinedLaneWR_bool) //!< TJALKA output macro getter.
#endif // S_TJALKA_CombinedLaneWR_bool

#ifdef __cplusplus
}
#endif

#endif // TJALKA_DATA_H_
