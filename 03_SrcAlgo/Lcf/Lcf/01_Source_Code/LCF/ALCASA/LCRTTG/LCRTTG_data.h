/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ALCASA
  MODULE        : LCRTTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCRTTG_data.h
//! @brief     (LCRTTG) Module Data Header.

#ifndef LCRTTG_DATA_H_
#define LCRTTG_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"
#include "LCRTTG_type.h"  //MFC5J3

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	LCRTTG module sensor get function. Function gets LCRTTG sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>LCRTTG_SenDbgPtr</b> Global static pointer to LCRTTG sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const LCRTTG_SenDbgType* LCRTTG_SenGetDbgPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_LCRTTG_LeCridrBndCrvChng_1pm2
#define S_LCRTTG_LeCridrBndCrvChng_1pm2 (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeCridrBndCrvChng_1pm2) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeCridrBndCrvChng_1pm2() (S_LCRTTG_LeCridrBndCrvChng_1pm2) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeCridrBndCrvChng_1pm2

#ifndef S_LCRTTG_LeCridrBndCrv_1pm
#define S_LCRTTG_LeCridrBndCrv_1pm (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeCridrBndCrv_1pm) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeCridrBndCrv_1pm() (S_LCRTTG_LeCridrBndCrv_1pm) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeCridrBndCrv_1pm

#ifndef S_LCRTTG_LeCridrBndHeadAng_rad
#define S_LCRTTG_LeCridrBndHeadAng_rad (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeCridrBndHeadAng_rad) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeCridrBndHeadAng_rad() (S_LCRTTG_LeCridrBndHeadAng_rad) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeCridrBndHeadAng_rad

#ifndef S_LCRTTG_LeCridrBndLength_met
#define S_LCRTTG_LeCridrBndLength_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeCridrBndLength_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeCridrBndLength_met() (S_LCRTTG_LeCridrBndLength_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeCridrBndLength_met

#ifndef S_LCRTTG_LeCridrBndPosX0_met
#define S_LCRTTG_LeCridrBndPosX0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeCridrBndPosX0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeCridrBndPosX0_met() (S_LCRTTG_LeCridrBndPosX0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeCridrBndPosX0_met

#ifndef S_LCRTTG_LeCridrBndPosY0_met
#define S_LCRTTG_LeCridrBndPosY0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeCridrBndPosY0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeCridrBndPosY0_met() (S_LCRTTG_LeCridrBndPosY0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeCridrBndPosY0_met

#ifndef S_LCRTTG_LeTgtTrajPosY0_met
#define S_LCRTTG_LeTgtTrajPosY0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_LeTgtTrajPosY0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_LeTgtTrajPosY0_met() (S_LCRTTG_LeTgtTrajPosY0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_LeTgtTrajPosY0_met

#ifndef S_LCRTTG_RiCridrBndCrvChng_1pm2
#define S_LCRTTG_RiCridrBndCrvChng_1pm2 (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiCridrBndCrvChng_1pm2) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiCridrBndCrvChng_1pm2() (S_LCRTTG_RiCridrBndCrvChng_1pm2) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiCridrBndCrvChng_1pm2

#ifndef S_LCRTTG_RiCridrBndCrv_1pm
#define S_LCRTTG_RiCridrBndCrv_1pm (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiCridrBndCrv_1pm) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiCridrBndCrv_1pm() (S_LCRTTG_RiCridrBndCrv_1pm) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiCridrBndCrv_1pm

#ifndef S_LCRTTG_RiCridrBndHeadAng_rad
#define S_LCRTTG_RiCridrBndHeadAng_rad (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiCridrBndHeadAng_rad) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiCridrBndHeadAng_rad() (S_LCRTTG_RiCridrBndHeadAng_rad) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiCridrBndHeadAng_rad

#ifndef S_LCRTTG_RiCridrBndLength_met
#define S_LCRTTG_RiCridrBndLength_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiCridrBndLength_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiCridrBndLength_met() (S_LCRTTG_RiCridrBndLength_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiCridrBndLength_met

#ifndef S_LCRTTG_RiCridrBndPosX0_met
#define S_LCRTTG_RiCridrBndPosX0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiCridrBndPosX0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiCridrBndPosX0_met() (S_LCRTTG_RiCridrBndPosX0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiCridrBndPosX0_met

#ifndef S_LCRTTG_RiCridrBndPosY0_met
#define S_LCRTTG_RiCridrBndPosY0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiCridrBndPosY0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiCridrBndPosY0_met() (S_LCRTTG_RiCridrBndPosY0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiCridrBndPosY0_met

#ifndef S_LCRTTG_RiTgtTrajPosY0_met
#define S_LCRTTG_RiTgtTrajPosY0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_RiTgtTrajPosY0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_RiTgtTrajPosY0_met() (S_LCRTTG_RiTgtTrajPosY0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_RiTgtTrajPosY0_met

#ifndef S_LCRTTG_TgtTrajCrvChng_1pm2
#define S_LCRTTG_TgtTrajCrvChng_1pm2 (LCRTTG_SenGetDbgPtr()->S_LCRTTG_TgtTrajCrvChng_1pm2) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_TgtTrajCrvChng_1pm2() (S_LCRTTG_TgtTrajCrvChng_1pm2) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_TgtTrajCrvChng_1pm2

#ifndef S_LCRTTG_TgtTrajCrv_1pm
#define S_LCRTTG_TgtTrajCrv_1pm (LCRTTG_SenGetDbgPtr()->S_LCRTTG_TgtTrajCrv_1pm) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_TgtTrajCrv_1pm() (S_LCRTTG_TgtTrajCrv_1pm) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_TgtTrajCrv_1pm

#ifndef S_LCRTTG_TgtTrajHeadAng_rad
#define S_LCRTTG_TgtTrajHeadAng_rad (LCRTTG_SenGetDbgPtr()->S_LCRTTG_TgtTrajHeadAng_rad) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_TgtTrajHeadAng_rad() (S_LCRTTG_TgtTrajHeadAng_rad) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_TgtTrajHeadAng_rad

#ifndef S_LCRTTG_TgtTrajLength_met
#define S_LCRTTG_TgtTrajLength_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_TgtTrajLength_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_TgtTrajLength_met() (S_LCRTTG_TgtTrajLength_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_TgtTrajLength_met

#ifndef S_LCRTTG_TgtTrajPosX0_met
#define S_LCRTTG_TgtTrajPosX0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_TgtTrajPosX0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_TgtTrajPosX0_met() (S_LCRTTG_TgtTrajPosX0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_TgtTrajPosX0_met

#ifndef S_LCRTTG_TgtTrajPosY0_met
#define S_LCRTTG_TgtTrajPosY0_met (LCRTTG_SenGetDbgPtr()->S_LCRTTG_TgtTrajPosY0_met) //!< LCRTTG debug macro.
#define GET_S_LCRTTG_TgtTrajPosY0_met() (S_LCRTTG_TgtTrajPosY0_met) //!< LCRTTG debug macro getter.
#endif // S_LCRTTG_TgtTrajPosY0_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // LCRTTG_DATA_H_
