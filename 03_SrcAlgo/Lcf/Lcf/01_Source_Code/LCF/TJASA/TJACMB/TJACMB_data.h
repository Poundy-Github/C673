/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJACMB
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.6 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:23:12CEST $
  $Log: TJACMB_data.h  $
  Revision 1.6 2020/04/09 14:23:12CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.5 2019/11/29 09:05:06CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     TJACMB_data.h
//! @brief     (TJACMB) Module Data Header.

#ifndef TJACMB_DATA_H_
#define TJACMB_DATA_H_

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
 *	TJACMB module sensor get function. Function gets TJACMB sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJACMB_SenDbgPtr</b> Global static pointer to TJACMB sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJACMB_SenDbgType* TJACMB_SenGetDbgPtr(void);

/*!
 *	TJACMB module sensor get function. Function gets TJACMB sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJACMB_SenOutPtr</b> Global static pointer to TJACMB sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJACMB_SenOutType* TJACMB_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJACMB_CombinedInvalid_btf
#define D_TJACMB_CombinedInvalid_btf (TJACMB_SenGetDbgPtr()->D_TJACMB_CombinedInvalid_btf) //!< TJACMB debug macro.
#define GET_D_TJACMB_CombinedInvalid_btf() (D_TJACMB_CombinedInvalid_btf) //!< TJACMB debug macro getter.
#endif // D_TJACMB_CombinedInvalid_btf

#ifndef S_TJACMB_Cancel_bool
#define S_TJACMB_Cancel_bool (TJACMB_SenGetDbgPtr()->S_TJACMB_Cancel_bool) //!< TJACMB debug macro.
#define GET_S_TJACMB_Cancel_bool() (S_TJACMB_Cancel_bool) //!< TJACMB debug macro getter.
#endif // S_TJACMB_Cancel_bool

#ifndef S_TJACMB_CombinedCrvChng_1pm2
#define S_TJACMB_CombinedCrvChng_1pm2 (TJACMB_SenGetDbgPtr()->S_TJACMB_CombinedCrvChng_1pm2) //!< TJACMB debug macro.
#define GET_S_TJACMB_CombinedCrvChng_1pm2() (S_TJACMB_CombinedCrvChng_1pm2) //!< TJACMB debug macro getter.
#endif // S_TJACMB_CombinedCrvChng_1pm2

#ifndef S_TJACMB_CombinedCrv_1pm
#define S_TJACMB_CombinedCrv_1pm (TJACMB_SenGetDbgPtr()->S_TJACMB_CombinedCrv_1pm) //!< TJACMB debug macro.
#define GET_S_TJACMB_CombinedCrv_1pm() (S_TJACMB_CombinedCrv_1pm) //!< TJACMB debug macro getter.
#endif // S_TJACMB_CombinedCrv_1pm

#ifndef S_TJACMB_CombinedHeading_rad
#define S_TJACMB_CombinedHeading_rad (TJACMB_SenGetDbgPtr()->S_TJACMB_CombinedHeading_rad) //!< TJACMB debug macro.
#define GET_S_TJACMB_CombinedHeading_rad() (S_TJACMB_CombinedHeading_rad) //!< TJACMB debug macro getter.
#endif // S_TJACMB_CombinedHeading_rad

#ifndef S_TJACMB_CombinedLength_met
#define S_TJACMB_CombinedLength_met (TJACMB_SenGetDbgPtr()->S_TJACMB_CombinedLength_met) //!< TJACMB debug macro.
#define GET_S_TJACMB_CombinedLength_met() (S_TJACMB_CombinedLength_met) //!< TJACMB debug macro getter.
#endif // S_TJACMB_CombinedLength_met

#ifndef S_TJACMB_CombinedPosY0_met
#define S_TJACMB_CombinedPosY0_met (TJACMB_SenGetDbgPtr()->S_TJACMB_CombinedPosY0_met) //!< TJACMB debug macro.
#define GET_S_TJACMB_CombinedPosY0_met() (S_TJACMB_CombinedPosY0_met) //!< TJACMB debug macro getter.
#endif // S_TJACMB_CombinedPosY0_met

#ifndef S_TJACMB_StrongReady_bool
#define S_TJACMB_StrongReady_bool (TJACMB_SenGetDbgPtr()->S_TJACMB_StrongReady_bool) //!< TJACMB debug macro.
#define GET_S_TJACMB_StrongReady_bool() (S_TJACMB_StrongReady_bool) //!< TJACMB debug macro getter.
#endif // S_TJACMB_StrongReady_bool

#ifndef S_TJACMB_WeakReady_bool
#define S_TJACMB_WeakReady_bool (TJACMB_SenGetDbgPtr()->S_TJACMB_WeakReady_bool) //!< TJACMB debug macro.
#define GET_S_TJACMB_WeakReady_bool() (S_TJACMB_WeakReady_bool) //!< TJACMB debug macro getter.
#endif // S_TJACMB_WeakReady_bool

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJACMB_TransitionInvalid_btf
#define D_TJACMB_TransitionInvalid_btf (TJACMB_SenGetOutPtr()->D_TJACMB_TransitionInvalid_btf) //!< TJACMB output macro.
#define GET_D_TJACMB_TransitionInvalid_btf() (D_TJACMB_TransitionInvalid_btf) //!< TJACMB output macro getter.
#endif // D_TJACMB_TransitionInvalid_btf

#ifndef S_TJACMB_CombinedLePosY0_met
#define S_TJACMB_CombinedLePosY0_met (TJACMB_SenGetOutPtr()->S_TJACMB_CombinedLePosY0_met) //!< TJACMB output macro.
#define GET_S_TJACMB_CombinedLePosY0_met() (S_TJACMB_CombinedLePosY0_met) //!< TJACMB output macro getter.
#endif // S_TJACMB_CombinedLePosY0_met

#ifndef S_TJACMB_CombinedMode_nu
#define S_TJACMB_CombinedMode_nu (TJACMB_SenGetOutPtr()->S_TJACMB_CombinedMode_nu) //!< TJACMB output macro.
#define GET_S_TJACMB_CombinedMode_nu() (S_TJACMB_CombinedMode_nu) //!< TJACMB output macro getter.
#endif // S_TJACMB_CombinedMode_nu

#ifndef S_TJACMB_CombinedPosX0_met
#define S_TJACMB_CombinedPosX0_met (TJACMB_SenGetOutPtr()->S_TJACMB_CombinedPosX0_met) //!< TJACMB output macro.
#define GET_S_TJACMB_CombinedPosX0_met() (S_TJACMB_CombinedPosX0_met) //!< TJACMB output macro getter.
#endif // S_TJACMB_CombinedPosX0_met

#ifndef S_TJACMB_CombinedRiPosY0_met
#define S_TJACMB_CombinedRiPosY0_met (TJACMB_SenGetOutPtr()->S_TJACMB_CombinedRiPosY0_met) //!< TJACMB output macro.
#define GET_S_TJACMB_CombinedRiPosY0_met() (S_TJACMB_CombinedRiPosY0_met) //!< TJACMB output macro getter.
#endif // S_TJACMB_CombinedRiPosY0_met

#ifdef __cplusplus
}
#endif

#endif /* TJACMB_DATA_H_*/
