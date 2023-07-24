/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : RDPSA
  MODULE        : DPRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPRTTG_data.h
//! @brief     (DPRTTG) Module Data Header.

#ifndef DPRTTG_DATA_H_
#define DPRTTG_DATA_H_

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
 *	DPRTTG module sensor get function. Function gets DPRTTG sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRTTG_SenDbgPtr</b> Global static pointer to DPRTTG sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRTTG_SenDbgType* DPRTTG_SenGetDbgPtr(void);

/*!
 *	DPRTTG module sensor get function. Function gets DPRTTG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPRTTG_SenOutPtr</b> Global static pointer to DPRTTG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPRTTG_SenOutType* DPRTTG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPRTTG_LeTgtTrajPosY0_met
#define S_DPRTTG_LeTgtTrajPosY0_met (DPRTTG_SenGetDbgPtr()->S_DPRTTG_LeTgtTrajPosY0_met) //!< DPRTTG debug macro.
#define GET_S_DPRTTG_LeTgtTrajPosY0_met() (S_DPRTTG_LeTgtTrajPosY0_met) //!< DPRTTG debug macro getter.
#endif // S_DPRTTG_LeTgtTrajPosY0_met

#ifndef S_DPRTTG_RiTgtTrajPosY0_met
#define S_DPRTTG_RiTgtTrajPosY0_met (DPRTTG_SenGetDbgPtr()->S_DPRTTG_RiTgtTrajPosY0_met) //!< DPRTTG debug macro.
#define GET_S_DPRTTG_RiTgtTrajPosY0_met() (S_DPRTTG_RiTgtTrajPosY0_met) //!< DPRTTG debug macro getter.
#endif // S_DPRTTG_RiTgtTrajPosY0_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPRTTG_LeCridrBndCrvChng_1pm2
#define S_DPRTTG_LeCridrBndCrvChng_1pm2 (DPRTTG_SenGetOutPtr()->S_DPRTTG_LeCridrBndCrvChng_1pm2) //!< DPRTTG output macro.
#define GET_S_DPRTTG_LeCridrBndCrvChng_1pm2() (S_DPRTTG_LeCridrBndCrvChng_1pm2) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_LeCridrBndCrvChng_1pm2

#ifndef S_DPRTTG_LeCridrBndCrv_1pm
#define S_DPRTTG_LeCridrBndCrv_1pm (DPRTTG_SenGetOutPtr()->S_DPRTTG_LeCridrBndCrv_1pm) //!< DPRTTG output macro.
#define GET_S_DPRTTG_LeCridrBndCrv_1pm() (S_DPRTTG_LeCridrBndCrv_1pm) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_LeCridrBndCrv_1pm

#ifndef S_DPRTTG_LeCridrBndHeadAng_rad
#define S_DPRTTG_LeCridrBndHeadAng_rad (DPRTTG_SenGetOutPtr()->S_DPRTTG_LeCridrBndHeadAng_rad) //!< DPRTTG output macro.
#define GET_S_DPRTTG_LeCridrBndHeadAng_rad() (S_DPRTTG_LeCridrBndHeadAng_rad) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_LeCridrBndHeadAng_rad

#ifndef S_DPRTTG_LeCridrBndLength_met
#define S_DPRTTG_LeCridrBndLength_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_LeCridrBndLength_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_LeCridrBndLength_met() (S_DPRTTG_LeCridrBndLength_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_LeCridrBndLength_met

#ifndef S_DPRTTG_LeCridrBndPosX0_met
#define S_DPRTTG_LeCridrBndPosX0_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_LeCridrBndPosX0_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_LeCridrBndPosX0_met() (S_DPRTTG_LeCridrBndPosX0_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_LeCridrBndPosX0_met

#ifndef S_DPRTTG_LeCridrBndPosY0_met
#define S_DPRTTG_LeCridrBndPosY0_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_LeCridrBndPosY0_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_LeCridrBndPosY0_met() (S_DPRTTG_LeCridrBndPosY0_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_LeCridrBndPosY0_met

#ifndef S_DPRTTG_RiCridrBndCrvChng_1pm2
#define S_DPRTTG_RiCridrBndCrvChng_1pm2 (DPRTTG_SenGetOutPtr()->S_DPRTTG_RiCridrBndCrvChng_1pm2) //!< DPRTTG output macro.
#define GET_S_DPRTTG_RiCridrBndCrvChng_1pm2() (S_DPRTTG_RiCridrBndCrvChng_1pm2) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_RiCridrBndCrvChng_1pm2

#ifndef S_DPRTTG_RiCridrBndCrv_1pm
#define S_DPRTTG_RiCridrBndCrv_1pm (DPRTTG_SenGetOutPtr()->S_DPRTTG_RiCridrBndCrv_1pm) //!< DPRTTG output macro.
#define GET_S_DPRTTG_RiCridrBndCrv_1pm() (S_DPRTTG_RiCridrBndCrv_1pm) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_RiCridrBndCrv_1pm

#ifndef S_DPRTTG_RiCridrBndHeadAng_rad
#define S_DPRTTG_RiCridrBndHeadAng_rad (DPRTTG_SenGetOutPtr()->S_DPRTTG_RiCridrBndHeadAng_rad) //!< DPRTTG output macro.
#define GET_S_DPRTTG_RiCridrBndHeadAng_rad() (S_DPRTTG_RiCridrBndHeadAng_rad) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_RiCridrBndHeadAng_rad

#ifndef S_DPRTTG_RiCridrBndLength_met
#define S_DPRTTG_RiCridrBndLength_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_RiCridrBndLength_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_RiCridrBndLength_met() (S_DPRTTG_RiCridrBndLength_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_RiCridrBndLength_met

#ifndef S_DPRTTG_RiCridrBndPosX0_met
#define S_DPRTTG_RiCridrBndPosX0_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_RiCridrBndPosX0_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_RiCridrBndPosX0_met() (S_DPRTTG_RiCridrBndPosX0_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_RiCridrBndPosX0_met

#ifndef S_DPRTTG_RiCridrBndPosY0_met
#define S_DPRTTG_RiCridrBndPosY0_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_RiCridrBndPosY0_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_RiCridrBndPosY0_met() (S_DPRTTG_RiCridrBndPosY0_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_RiCridrBndPosY0_met

#ifndef S_DPRTTG_TgtTrajCrvChng_1pm2
#define S_DPRTTG_TgtTrajCrvChng_1pm2 (DPRTTG_SenGetOutPtr()->S_DPRTTG_TgtTrajCrvChng_1pm2) //!< DPRTTG output macro.
#define GET_S_DPRTTG_TgtTrajCrvChng_1pm2() (S_DPRTTG_TgtTrajCrvChng_1pm2) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_TgtTrajCrvChng_1pm2

#ifndef S_DPRTTG_TgtTrajCrv_1pm
#define S_DPRTTG_TgtTrajCrv_1pm (DPRTTG_SenGetOutPtr()->S_DPRTTG_TgtTrajCrv_1pm) //!< DPRTTG output macro.
#define GET_S_DPRTTG_TgtTrajCrv_1pm() (S_DPRTTG_TgtTrajCrv_1pm) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_TgtTrajCrv_1pm

#ifndef S_DPRTTG_TgtTrajHeadAng_rad
#define S_DPRTTG_TgtTrajHeadAng_rad (DPRTTG_SenGetOutPtr()->S_DPRTTG_TgtTrajHeadAng_rad) //!< DPRTTG output macro.
#define GET_S_DPRTTG_TgtTrajHeadAng_rad() (S_DPRTTG_TgtTrajHeadAng_rad) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_TgtTrajHeadAng_rad

#ifndef S_DPRTTG_TgtTrajLength_met
#define S_DPRTTG_TgtTrajLength_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_TgtTrajLength_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_TgtTrajLength_met() (S_DPRTTG_TgtTrajLength_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_TgtTrajLength_met

#ifndef S_DPRTTG_TgtTrajPosX0_met
#define S_DPRTTG_TgtTrajPosX0_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_TgtTrajPosX0_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_TgtTrajPosX0_met() (S_DPRTTG_TgtTrajPosX0_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_TgtTrajPosX0_met

#ifndef S_DPRTTG_TgtTrajPosY0_met
#define S_DPRTTG_TgtTrajPosY0_met (DPRTTG_SenGetOutPtr()->S_DPRTTG_TgtTrajPosY0_met) //!< DPRTTG output macro.
#define GET_S_DPRTTG_TgtTrajPosY0_met() (S_DPRTTG_TgtTrajPosY0_met) //!< DPRTTG output macro getter.
#endif // S_DPRTTG_TgtTrajPosY0_met

#ifdef __cplusplus
}
#endif

#endif // DPRTTG_DATA_H_
