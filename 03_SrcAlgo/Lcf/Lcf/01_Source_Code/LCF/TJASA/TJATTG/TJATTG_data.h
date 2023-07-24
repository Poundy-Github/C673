/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJATTG
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     TJATTG_data.h
//! @brief     (TJATTG) Module Data Header.

#ifndef TJATTG_DATA_H_
#define TJATTG_DATA_H_

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
 *	TJATTG module sensor get function. Function gets TJATTG sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJATTG_SenDbgPtr</b> Global static pointer to TJATTG sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJATTG_SenDbgType* TJATTG_SenGetDbgPtr(void);

/*!
 *	TJATTG module sensor get function. Function gets TJATTG sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>TJATTG_SenOutPtr</b> Global static pointer to TJATTG sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const TJATTG_SenOutType* TJATTG_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_TJATTG_TgtCorridorInvalid_btf
#define D_TJATTG_TgtCorridorInvalid_btf (TJATTG_SenGetDbgPtr()->D_TJATTG_TgtCorridorInvalid_btf) //!< TJATTG debug macro.
#define GET_D_TJATTG_TgtCorridorInvalid_btf() (D_TJATTG_TgtCorridorInvalid_btf) //!< TJATTG debug macro getter.
#endif // D_TJATTG_TgtCorridorInvalid_btf

#ifndef S_TJATTG_TgtTrajCrvChng_1pm2
#define S_TJATTG_TgtTrajCrvChng_1pm2 (TJATTG_SenGetDbgPtr()->S_TJATTG_TgtTrajCrvChng_1pm2) //!< TJATTG debug macro.
#define GET_S_TJATTG_TgtTrajCrvChng_1pm2() (S_TJATTG_TgtTrajCrvChng_1pm2) //!< TJATTG debug macro getter.
#endif // S_TJATTG_TgtTrajCrvChng_1pm2

#ifndef S_TJATTG_TgtTrajCrv_1pm
#define S_TJATTG_TgtTrajCrv_1pm (TJATTG_SenGetDbgPtr()->S_TJATTG_TgtTrajCrv_1pm) //!< TJATTG debug macro.
#define GET_S_TJATTG_TgtTrajCrv_1pm() (S_TJATTG_TgtTrajCrv_1pm) //!< TJATTG debug macro getter.
#endif // S_TJATTG_TgtTrajCrv_1pm

#ifndef S_TJATTG_TgtTrajHeadAng_rad
#define S_TJATTG_TgtTrajHeadAng_rad (TJATTG_SenGetDbgPtr()->S_TJATTG_TgtTrajHeadAng_rad) //!< TJATTG debug macro.
#define GET_S_TJATTG_TgtTrajHeadAng_rad() (S_TJATTG_TgtTrajHeadAng_rad) //!< TJATTG debug macro getter.
#endif // S_TJATTG_TgtTrajHeadAng_rad

#ifndef S_TJATTG_TgtTrajLength_met
#define S_TJATTG_TgtTrajLength_met (TJATTG_SenGetDbgPtr()->S_TJATTG_TgtTrajLength_met) //!< TJATTG debug macro.
#define GET_S_TJATTG_TgtTrajLength_met() (S_TJATTG_TgtTrajLength_met) //!< TJATTG debug macro getter.
#endif // S_TJATTG_TgtTrajLength_met

#ifndef S_TJATTG_TgtTrajPosX0_met
#define S_TJATTG_TgtTrajPosX0_met (TJATTG_SenGetDbgPtr()->S_TJATTG_TgtTrajPosX0_met) //!< TJATTG debug macro.
#define GET_S_TJATTG_TgtTrajPosX0_met() (S_TJATTG_TgtTrajPosX0_met) //!< TJATTG debug macro getter.
#endif // S_TJATTG_TgtTrajPosX0_met

#ifndef S_TJATTG_TgtTrajPosY0_met
#define S_TJATTG_TgtTrajPosY0_met (TJATTG_SenGetDbgPtr()->S_TJATTG_TgtTrajPosY0_met) //!< TJATTG debug macro.
#define GET_S_TJATTG_TgtTrajPosY0_met() (S_TJATTG_TgtTrajPosY0_met) //!< TJATTG debug macro getter.
#endif // S_TJATTG_TgtTrajPosY0_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_TJATTG_LeCridrBndCrvChng_1pm2
#define S_TJATTG_LeCridrBndCrvChng_1pm2 (TJATTG_SenGetOutPtr()->S_TJATTG_LeCridrBndCrvChng_1pm2) //!< TJATTG output macro.
#define GET_S_TJATTG_LeCridrBndCrvChng_1pm2() (S_TJATTG_LeCridrBndCrvChng_1pm2) //!< TJATTG output macro getter.
#endif // S_TJATTG_LeCridrBndCrvChng_1pm2

#ifndef S_TJATTG_LeCridrBndCrv_1pm
#define S_TJATTG_LeCridrBndCrv_1pm (TJATTG_SenGetOutPtr()->S_TJATTG_LeCridrBndCrv_1pm) //!< TJATTG output macro.
#define GET_S_TJATTG_LeCridrBndCrv_1pm() (S_TJATTG_LeCridrBndCrv_1pm) //!< TJATTG output macro getter.
#endif // S_TJATTG_LeCridrBndCrv_1pm

#ifndef S_TJATTG_LeCridrBndHeadAng_rad
#define S_TJATTG_LeCridrBndHeadAng_rad (TJATTG_SenGetOutPtr()->S_TJATTG_LeCridrBndHeadAng_rad) //!< TJATTG output macro.
#define GET_S_TJATTG_LeCridrBndHeadAng_rad() (S_TJATTG_LeCridrBndHeadAng_rad) //!< TJATTG output macro getter.
#endif // S_TJATTG_LeCridrBndHeadAng_rad

#ifndef S_TJATTG_LeCridrBndLength_met
#define S_TJATTG_LeCridrBndLength_met (TJATTG_SenGetOutPtr()->S_TJATTG_LeCridrBndLength_met) //!< TJATTG output macro.
#define GET_S_TJATTG_LeCridrBndLength_met() (S_TJATTG_LeCridrBndLength_met) //!< TJATTG output macro getter.
#endif // S_TJATTG_LeCridrBndLength_met

#ifndef S_TJATTG_LeCridrBndPosX0_met
#define S_TJATTG_LeCridrBndPosX0_met (TJATTG_SenGetOutPtr()->S_TJATTG_LeCridrBndPosX0_met) //!< TJATTG output macro.
#define GET_S_TJATTG_LeCridrBndPosX0_met() (S_TJATTG_LeCridrBndPosX0_met) //!< TJATTG output macro getter.
#endif // S_TJATTG_LeCridrBndPosX0_met

#ifndef S_TJATTG_LeCridrBndPosY0_met
#define S_TJATTG_LeCridrBndPosY0_met (TJATTG_SenGetOutPtr()->S_TJATTG_LeCridrBndPosY0_met) //!< TJATTG output macro.
#define GET_S_TJATTG_LeCridrBndPosY0_met() (S_TJATTG_LeCridrBndPosY0_met) //!< TJATTG output macro getter.
#endif // S_TJATTG_LeCridrBndPosY0_met

#ifndef S_TJATTG_PredictionEnable_bool
#define S_TJATTG_PredictionEnable_bool (TJATTG_SenGetOutPtr()->S_TJATTG_PredictionEnable_bool) //!< TJATTG output macro.
#define GET_S_TJATTG_PredictionEnable_bool() (S_TJATTG_PredictionEnable_bool) //!< TJATTG output macro getter.
#endif // S_TJATTG_PredictionEnable_bool

#ifndef S_TJATTG_RiCridrBndCrvChng_1pm2
#define S_TJATTG_RiCridrBndCrvChng_1pm2 (TJATTG_SenGetOutPtr()->S_TJATTG_RiCridrBndCrvChng_1pm2) //!< TJATTG output macro.
#define GET_S_TJATTG_RiCridrBndCrvChng_1pm2() (S_TJATTG_RiCridrBndCrvChng_1pm2) //!< TJATTG output macro getter.
#endif // S_TJATTG_RiCridrBndCrvChng_1pm2

#ifndef S_TJATTG_RiCridrBndCrv_1pm
#define S_TJATTG_RiCridrBndCrv_1pm (TJATTG_SenGetOutPtr()->S_TJATTG_RiCridrBndCrv_1pm) //!< TJATTG output macro.
#define GET_S_TJATTG_RiCridrBndCrv_1pm() (S_TJATTG_RiCridrBndCrv_1pm) //!< TJATTG output macro getter.
#endif // S_TJATTG_RiCridrBndCrv_1pm

#ifndef S_TJATTG_RiCridrBndHeadAng_rad
#define S_TJATTG_RiCridrBndHeadAng_rad (TJATTG_SenGetOutPtr()->S_TJATTG_RiCridrBndHeadAng_rad) //!< TJATTG output macro.
#define GET_S_TJATTG_RiCridrBndHeadAng_rad() (S_TJATTG_RiCridrBndHeadAng_rad) //!< TJATTG output macro getter.
#endif // S_TJATTG_RiCridrBndHeadAng_rad

#ifndef S_TJATTG_RiCridrBndLength_met
#define S_TJATTG_RiCridrBndLength_met (TJATTG_SenGetOutPtr()->S_TJATTG_RiCridrBndLength_met) //!< TJATTG output macro.
#define GET_S_TJATTG_RiCridrBndLength_met() (S_TJATTG_RiCridrBndLength_met) //!< TJATTG output macro getter.
#endif // S_TJATTG_RiCridrBndLength_met

#ifndef S_TJATTG_RiCridrBndPosX0_met
#define S_TJATTG_RiCridrBndPosX0_met (TJATTG_SenGetOutPtr()->S_TJATTG_RiCridrBndPosX0_met) //!< TJATTG output macro.
#define GET_S_TJATTG_RiCridrBndPosX0_met() (S_TJATTG_RiCridrBndPosX0_met) //!< TJATTG output macro getter.
#endif // S_TJATTG_RiCridrBndPosX0_met

#ifndef S_TJATTG_RiCridrBndPosY0_met
#define S_TJATTG_RiCridrBndPosY0_met (TJATTG_SenGetOutPtr()->S_TJATTG_RiCridrBndPosY0_met) //!< TJATTG output macro.
#define GET_S_TJATTG_RiCridrBndPosY0_met() (S_TJATTG_RiCridrBndPosY0_met) //!< TJATTG output macro getter.
#endif // S_TJATTG_RiCridrBndPosY0_met

#ifndef S_TJATTG_TransTriggerReplan_bool
#define S_TJATTG_TransTriggerReplan_bool (TJATTG_SenGetOutPtr()->S_TJATTG_TransTriggerReplan_bool) //!< TJATTG output macro.
#define GET_S_TJATTG_TransTriggerReplan_bool() (S_TJATTG_TransTriggerReplan_bool) //!< TJATTG output macro getter.
#endif // S_TJATTG_TransTriggerReplan_bool

#ifdef __cplusplus
}
#endif

#endif // TJATTG_DATA_H_
