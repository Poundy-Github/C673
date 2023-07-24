/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOH
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4.1.2 $
  $Author: Craciun, Mihaela (uidl9730) (uidl9730) $
  $Date: 2020/04/09 14:20:44CEST $
  $Log: ODPFOH_data.h  $
  Revision 1.4.1.2 2020/04/09 14:20:44CEST Craciun, Mihaela (uidl9730) (uidl9730) 
  integrate new updates
  Revision 1.4.1.1 2019/11/29 09:02:24CET Nastasa, Elena (uidt4846) 
  Update LCF code for new auxCodeGen 4.1
**===========================================================*/
//! @file     ODPFOH_data.h
//! @brief     (ODPFOH) Module Data Header.

#ifndef ODPFOH_DATA_H_
#define ODPFOH_DATA_H_

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
 *	ODPFOH module sensor get function. Function gets ODPFOH sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ODPFOH_SenDbgPtr</b> Global static pointer to ODPFOH sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ODPFOH_SenDbgType* ODPFOH_SenGetDbgPtr(void);

/*!
 *	ODPFOH module sensor get function. Function gets ODPFOH sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ODPFOH_SenOutPtr</b> Global static pointer to ODPFOH sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ODPFOH_SenOutType* ODPFOH_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_ODPFOH_AddNewSample_bool
#define D_ODPFOH_AddNewSample_bool (ODPFOH_SenGetDbgPtr()->D_ODPFOH_AddNewSample_bool) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_AddNewSample_bool() (D_ODPFOH_AddNewSample_bool) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_AddNewSample_bool

#ifndef D_ODPFOH_LastStoredPntAge_sec
#define D_ODPFOH_LastStoredPntAge_sec (ODPFOH_SenGetDbgPtr()->D_ODPFOH_LastStoredPntAge_sec) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_LastStoredPntAge_sec() (D_ODPFOH_LastStoredPntAge_sec) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_LastStoredPntAge_sec

#ifndef D_ODPFOH_LastStoredPntX_met
#define D_ODPFOH_LastStoredPntX_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_LastStoredPntX_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_LastStoredPntX_met() (D_ODPFOH_LastStoredPntX_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_LastStoredPntX_met

#ifndef D_ODPFOH_LastStoredPntY_met
#define D_ODPFOH_LastStoredPntY_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_LastStoredPntY_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_LastStoredPntY_met() (D_ODPFOH_LastStoredPntY_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_LastStoredPntY_met

#ifndef D_ODPFOH_MaxGapEgoToHist_met
#define D_ODPFOH_MaxGapEgoToHist_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_MaxGapEgoToHist_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_MaxGapEgoToHist_met() (D_ODPFOH_MaxGapEgoToHist_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_MaxGapEgoToHist_met

#ifndef D_ODPFOH_MeanDevToTraj_1st_met
#define D_ODPFOH_MeanDevToTraj_1st_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_MeanDevToTraj_1st_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_MeanDevToTraj_1st_met() (D_ODPFOH_MeanDevToTraj_1st_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_MeanDevToTraj_1st_met

#ifndef D_ODPFOH_MeanDevToTraj_3rd_met
#define D_ODPFOH_MeanDevToTraj_3rd_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_MeanDevToTraj_3rd_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_MeanDevToTraj_3rd_met() (D_ODPFOH_MeanDevToTraj_3rd_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_MeanDevToTraj_3rd_met

#ifndef D_ODPFOH_MinHistLength_met
#define D_ODPFOH_MinHistLength_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_MinHistLength_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_MinHistLength_met() (D_ODPFOH_MinHistLength_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_MinHistLength_met

#ifndef D_ODPFOH_MinHistStartPosX_met
#define D_ODPFOH_MinHistStartPosX_met (ODPFOH_SenGetDbgPtr()->D_ODPFOH_MinHistStartPosX_met) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_MinHistStartPosX_met() (D_ODPFOH_MinHistStartPosX_met) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_MinHistStartPosX_met

#ifndef D_ODPFOH_NumValidSamples_nu
#define D_ODPFOH_NumValidSamples_nu (ODPFOH_SenGetDbgPtr()->D_ODPFOH_NumValidSamples_nu) //!< ODPFOH debug macro.
#define GET_D_ODPFOH_NumValidSamples_nu() (D_ODPFOH_NumValidSamples_nu) //!< ODPFOH debug macro getter.
#endif // D_ODPFOH_NumValidSamples_nu

#ifndef S_ODPFOH_AccObjTraceCrv_1pm
#define S_ODPFOH_AccObjTraceCrv_1pm (ODPFOH_SenGetDbgPtr()->S_ODPFOH_AccObjTraceCrv_1pm) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_AccObjTraceCrv_1pm() (S_ODPFOH_AccObjTraceCrv_1pm) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_AccObjTraceCrv_1pm

#ifndef S_ODPFOH_ObjTraceCrvQual_perc
#define S_ODPFOH_ObjTraceCrvQual_perc (ODPFOH_SenGetDbgPtr()->S_ODPFOH_ObjTraceCrvQual_perc) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_ObjTraceCrvQual_perc() (S_ODPFOH_ObjTraceCrvQual_perc) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_ObjTraceCrvQual_perc

#ifndef S_ODPFOH_ObjTraceQual_perc
#define S_ODPFOH_ObjTraceQual_perc (ODPFOH_SenGetDbgPtr()->S_ODPFOH_ObjTraceQual_perc) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_ObjTraceQual_perc() (S_ODPFOH_ObjTraceQual_perc) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_ObjTraceQual_perc

#ifndef S_ODPFOH_ObjTraceStraight_perc
#define S_ODPFOH_ObjTraceStraight_perc (ODPFOH_SenGetDbgPtr()->S_ODPFOH_ObjTraceStraight_perc) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_ObjTraceStraight_perc() (S_ODPFOH_ObjTraceStraight_perc) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_ObjTraceStraight_perc

#ifndef S_ODPFOH_TgtObjClothoidInv_btf
#define S_ODPFOH_TgtObjClothoidInv_btf (ODPFOH_SenGetDbgPtr()->S_ODPFOH_TgtObjClothoidInv_btf) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_TgtObjClothoidInv_btf() (S_ODPFOH_TgtObjClothoidInv_btf) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_TgtObjClothoidInv_btf

#ifndef S_ODPFOH_TgtObjCrv_1pm
#define S_ODPFOH_TgtObjCrv_1pm (ODPFOH_SenGetDbgPtr()->S_ODPFOH_TgtObjCrv_1pm) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_TgtObjCrv_1pm() (S_ODPFOH_TgtObjCrv_1pm) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_TgtObjCrv_1pm

#ifndef S_ODPFOH_TgtObjHeadAng_rad
#define S_ODPFOH_TgtObjHeadAng_rad (ODPFOH_SenGetDbgPtr()->S_ODPFOH_TgtObjHeadAng_rad) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_TgtObjHeadAng_rad() (S_ODPFOH_TgtObjHeadAng_rad) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_TgtObjHeadAng_rad

#ifndef S_ODPFOH_TgtObjLength_met
#define S_ODPFOH_TgtObjLength_met (ODPFOH_SenGetDbgPtr()->S_ODPFOH_TgtObjLength_met) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_TgtObjLength_met() (S_ODPFOH_TgtObjLength_met) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_TgtObjLength_met

#ifndef S_ODPFOH_TgtObjPosX0_met
#define S_ODPFOH_TgtObjPosX0_met (ODPFOH_SenGetDbgPtr()->S_ODPFOH_TgtObjPosX0_met) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_TgtObjPosX0_met() (S_ODPFOH_TgtObjPosX0_met) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_TgtObjPosX0_met

#ifndef S_ODPFOH_TgtObjPosY0_met
#define S_ODPFOH_TgtObjPosY0_met (ODPFOH_SenGetDbgPtr()->S_ODPFOH_TgtObjPosY0_met) //!< ODPFOH debug macro.
#define GET_S_ODPFOH_TgtObjPosY0_met() (S_ODPFOH_TgtObjPosY0_met) //!< ODPFOH debug macro getter.
#endif // S_ODPFOH_TgtObjPosY0_met

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef D_ODPFOH_FirstStoredPntAge_sec
#define D_ODPFOH_FirstStoredPntAge_sec (ODPFOH_SenGetOutPtr()->D_ODPFOH_FirstStoredPntAge_sec) //!< ODPFOH output macro.
#define GET_D_ODPFOH_FirstStoredPntAge_sec() (D_ODPFOH_FirstStoredPntAge_sec) //!< ODPFOH output macro getter.
#endif // D_ODPFOH_FirstStoredPntAge_sec

#ifndef D_ODPFOH_FirstStoredPntX_met
#define D_ODPFOH_FirstStoredPntX_met (ODPFOH_SenGetOutPtr()->D_ODPFOH_FirstStoredPntX_met) //!< ODPFOH output macro.
#define GET_D_ODPFOH_FirstStoredPntX_met() (D_ODPFOH_FirstStoredPntX_met) //!< ODPFOH output macro getter.
#endif // D_ODPFOH_FirstStoredPntX_met

#ifndef D_ODPFOH_MeanStoredPntAge_sec
#define D_ODPFOH_MeanStoredPntAge_sec (ODPFOH_SenGetOutPtr()->D_ODPFOH_MeanStoredPntAge_sec) //!< ODPFOH output macro.
#define GET_D_ODPFOH_MeanStoredPntAge_sec() (D_ODPFOH_MeanStoredPntAge_sec) //!< ODPFOH output macro getter.
#endif // D_ODPFOH_MeanStoredPntAge_sec

#ifndef S_ODPFOH_TgtObjCrvChng_1pm2
#define S_ODPFOH_TgtObjCrvChng_1pm2 (ODPFOH_SenGetOutPtr()->S_ODPFOH_TgtObjCrvChng_1pm2) //!< ODPFOH output macro.
#define GET_S_ODPFOH_TgtObjCrvChng_1pm2() (S_ODPFOH_TgtObjCrvChng_1pm2) //!< ODPFOH output macro getter.
#endif // S_ODPFOH_TgtObjCrvChng_1pm2

#ifdef __cplusplus
}
#endif

#endif /* ODPFOH_DATA_H_*/
