/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : LDPSA
  MODULE        : DPLTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     DPLTTG_data.h
//! @brief     (DPLTTG) Module Data Header.

#ifndef DPLTTG_DATA_H_
#define DPLTTG_DATA_H_

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
 *	DPLTTG module sensor get function. Function gets DPLTTG sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLTTG_SenDbgPtr</b> Global static pointer to DPLTTG sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLTTG_SenDbgType* DPLTTG_SenGetDbgPtr(void);

/*!
 *	DPLTTG module sensor get function. Function gets DPLTTG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>DPLTTG_SenOutPtr</b> Global static pointer to DPLTTG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const DPLTTG_SenOutType* DPLTTG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPLTTG_LeTgtTrajPosY0_met
#define S_DPLTTG_LeTgtTrajPosY0_met (DPLTTG_SenGetDbgPtr()->S_DPLTTG_LeTgtTrajPosY0_met) //!< DPLTTG debug macro.
#define GET_S_DPLTTG_LeTgtTrajPosY0_met() (S_DPLTTG_LeTgtTrajPosY0_met) //!< DPLTTG debug macro getter.
#endif // S_DPLTTG_LeTgtTrajPosY0_met

#ifndef S_DPLTTG_RiTgtTrajPosY0_met
#define S_DPLTTG_RiTgtTrajPosY0_met (DPLTTG_SenGetDbgPtr()->S_DPLTTG_RiTgtTrajPosY0_met) //!< DPLTTG debug macro.
#define GET_S_DPLTTG_RiTgtTrajPosY0_met() (S_DPLTTG_RiTgtTrajPosY0_met) //!< DPLTTG debug macro getter.
#endif // S_DPLTTG_RiTgtTrajPosY0_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_DPLTTG_LeCridrBndCrvChng_1pm2
#define S_DPLTTG_LeCridrBndCrvChng_1pm2 (DPLTTG_SenGetOutPtr()->S_DPLTTG_LeCridrBndCrvChng_1pm2) //!< DPLTTG output macro.
#define GET_S_DPLTTG_LeCridrBndCrvChng_1pm2() (S_DPLTTG_LeCridrBndCrvChng_1pm2) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_LeCridrBndCrvChng_1pm2

#ifndef S_DPLTTG_LeCridrBndCrv_1pm
#define S_DPLTTG_LeCridrBndCrv_1pm (DPLTTG_SenGetOutPtr()->S_DPLTTG_LeCridrBndCrv_1pm) //!< DPLTTG output macro.
#define GET_S_DPLTTG_LeCridrBndCrv_1pm() (S_DPLTTG_LeCridrBndCrv_1pm) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_LeCridrBndCrv_1pm

#ifndef S_DPLTTG_LeCridrBndHeadAng_rad
#define S_DPLTTG_LeCridrBndHeadAng_rad (DPLTTG_SenGetOutPtr()->S_DPLTTG_LeCridrBndHeadAng_rad) //!< DPLTTG output macro.
#define GET_S_DPLTTG_LeCridrBndHeadAng_rad() (S_DPLTTG_LeCridrBndHeadAng_rad) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_LeCridrBndHeadAng_rad

#ifndef S_DPLTTG_LeCridrBndLength_met
#define S_DPLTTG_LeCridrBndLength_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_LeCridrBndLength_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_LeCridrBndLength_met() (S_DPLTTG_LeCridrBndLength_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_LeCridrBndLength_met

#ifndef S_DPLTTG_LeCridrBndPosX0_met
#define S_DPLTTG_LeCridrBndPosX0_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_LeCridrBndPosX0_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_LeCridrBndPosX0_met() (S_DPLTTG_LeCridrBndPosX0_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_LeCridrBndPosX0_met

#ifndef S_DPLTTG_LeCridrBndPosY0_met
#define S_DPLTTG_LeCridrBndPosY0_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_LeCridrBndPosY0_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_LeCridrBndPosY0_met() (S_DPLTTG_LeCridrBndPosY0_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_LeCridrBndPosY0_met

#ifndef S_DPLTTG_RiCridrBndCrvChng_1pm2
#define S_DPLTTG_RiCridrBndCrvChng_1pm2 (DPLTTG_SenGetOutPtr()->S_DPLTTG_RiCridrBndCrvChng_1pm2) //!< DPLTTG output macro.
#define GET_S_DPLTTG_RiCridrBndCrvChng_1pm2() (S_DPLTTG_RiCridrBndCrvChng_1pm2) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_RiCridrBndCrvChng_1pm2

#ifndef S_DPLTTG_RiCridrBndCrv_1pm
#define S_DPLTTG_RiCridrBndCrv_1pm (DPLTTG_SenGetOutPtr()->S_DPLTTG_RiCridrBndCrv_1pm) //!< DPLTTG output macro.
#define GET_S_DPLTTG_RiCridrBndCrv_1pm() (S_DPLTTG_RiCridrBndCrv_1pm) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_RiCridrBndCrv_1pm

#ifndef S_DPLTTG_RiCridrBndHeadAng_rad
#define S_DPLTTG_RiCridrBndHeadAng_rad (DPLTTG_SenGetOutPtr()->S_DPLTTG_RiCridrBndHeadAng_rad) //!< DPLTTG output macro.
#define GET_S_DPLTTG_RiCridrBndHeadAng_rad() (S_DPLTTG_RiCridrBndHeadAng_rad) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_RiCridrBndHeadAng_rad

#ifndef S_DPLTTG_RiCridrBndLength_met
#define S_DPLTTG_RiCridrBndLength_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_RiCridrBndLength_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_RiCridrBndLength_met() (S_DPLTTG_RiCridrBndLength_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_RiCridrBndLength_met

#ifndef S_DPLTTG_RiCridrBndPosX0_met
#define S_DPLTTG_RiCridrBndPosX0_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_RiCridrBndPosX0_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_RiCridrBndPosX0_met() (S_DPLTTG_RiCridrBndPosX0_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_RiCridrBndPosX0_met

#ifndef S_DPLTTG_RiCridrBndPosY0_met
#define S_DPLTTG_RiCridrBndPosY0_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_RiCridrBndPosY0_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_RiCridrBndPosY0_met() (S_DPLTTG_RiCridrBndPosY0_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_RiCridrBndPosY0_met

#ifndef S_DPLTTG_TgtTrajCrvChng_1pm2
#define S_DPLTTG_TgtTrajCrvChng_1pm2 (DPLTTG_SenGetOutPtr()->S_DPLTTG_TgtTrajCrvChng_1pm2) //!< DPLTTG output macro.
#define GET_S_DPLTTG_TgtTrajCrvChng_1pm2() (S_DPLTTG_TgtTrajCrvChng_1pm2) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_TgtTrajCrvChng_1pm2

#ifndef S_DPLTTG_TgtTrajCrv_1pm
#define S_DPLTTG_TgtTrajCrv_1pm (DPLTTG_SenGetOutPtr()->S_DPLTTG_TgtTrajCrv_1pm) //!< DPLTTG output macro.
#define GET_S_DPLTTG_TgtTrajCrv_1pm() (S_DPLTTG_TgtTrajCrv_1pm) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_TgtTrajCrv_1pm

#ifndef S_DPLTTG_TgtTrajHeadAng_rad
#define S_DPLTTG_TgtTrajHeadAng_rad (DPLTTG_SenGetOutPtr()->S_DPLTTG_TgtTrajHeadAng_rad) //!< DPLTTG output macro.
#define GET_S_DPLTTG_TgtTrajHeadAng_rad() (S_DPLTTG_TgtTrajHeadAng_rad) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_TgtTrajHeadAng_rad

#ifndef S_DPLTTG_TgtTrajLength_met
#define S_DPLTTG_TgtTrajLength_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_TgtTrajLength_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_TgtTrajLength_met() (S_DPLTTG_TgtTrajLength_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_TgtTrajLength_met

#ifndef S_DPLTTG_TgtTrajPosX0_met
#define S_DPLTTG_TgtTrajPosX0_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_TgtTrajPosX0_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_TgtTrajPosX0_met() (S_DPLTTG_TgtTrajPosX0_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_TgtTrajPosX0_met

#ifndef S_DPLTTG_TgtTrajPosY0_met
#define S_DPLTTG_TgtTrajPosY0_met (DPLTTG_SenGetOutPtr()->S_DPLTTG_TgtTrajPosY0_met) //!< DPLTTG output macro.
#define GET_S_DPLTTG_TgtTrajPosY0_met() (S_DPLTTG_TgtTrajPosY0_met) //!< DPLTTG output macro getter.
#endif // S_DPLTTG_TgtTrajPosY0_met

#ifdef __cplusplus
}
#endif

#endif // DPLTTG_DATA_H_
