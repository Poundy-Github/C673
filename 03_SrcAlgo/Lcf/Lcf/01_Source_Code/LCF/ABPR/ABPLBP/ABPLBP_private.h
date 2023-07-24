/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ABPR
  MODULE        : ABPLBP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     ABPLBP_private.h
//! @brief     (ABPLBP) Module Private Header.

#ifndef ABPLBP_PRIVATE_H_
#define ABPLBP_PRIVATE_H_

/*-----------------------------------------------------*
   I N P U T   M A C R O   S W I T C H E S
**-----------------------------------------------------*/

#define ABPR	//!< ABPR sub-component input macro switch.
#define ABPLBP	//!< ABPLBP module input macro switch.

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "ABPLBP.h"
#include "Bitop.h"  //MFC5J3
#include "ecmath.h"
#include "f32_calm.h"
#include "f32_math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   R U N N A B L E   M A C R O   I D E N T I F I E R S
**-----------------------------------------------------*/

#define RUNNABLE_ID_ABPLBP_SenReset		0xF0 //!< ABPLBP module reset runnable identifier.
#define RUNNABLE_ID_ABPLBP_SenProcess	0xF1 //!< ABPLBP module process runnable identifier.

/*-----------------------------------------------------*
   D A T A / F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

static ABPLBP_SenDbgType *ABPLBP_SenDbgPtr = NULL; //!< ABPLBP module sensor debug data pointer.
void ABPLBP_SenInitDbgPtr(ABPLBP_SenDbgType *ABPLBP_SenDbgArg) { ABPLBP_SenDbgPtr = ABPLBP_SenDbgPtr == NULL ? ABPLBP_SenDbgArg : ABPLBP_SenDbgPtr; }
const ABPLBP_SenDbgType* ABPLBP_SenGetDbgPtr(void) { return (const ABPLBP_SenDbgType*) ABPLBP_SenDbgPtr; }

static ABPLBP_SenOutType *ABPLBP_SenOutPtr = NULL; //!< ABPLBP module sensor output data pointer.
void ABPLBP_SenInitOutPtr(ABPLBP_SenOutType *ABPLBP_SenOutArg) { ABPLBP_SenOutPtr = ABPLBP_SenOutPtr == NULL ? ABPLBP_SenOutArg : ABPLBP_SenOutPtr; }
const ABPLBP_SenOutType* ABPLBP_SenGetOutPtr(void) { return (const ABPLBP_SenOutType*) ABPLBP_SenOutPtr; }

/*-----------------------------------------------------*
   D E B U G   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_ABPLBP_ABDTimeStamp_sec
#define	S_ABPLBP_ABDTimeStamp_sec (ABPLBP_SenDbgPtr->S_ABPLBP_ABDTimeStamp_sec) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_ABDTimeStamp_sec(val)	(S_ABPLBP_ABDTimeStamp_sec = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnClthCrvChng_1pm2
#define	S_ABPLBP_CntrLnClthCrvChng_1pm2 (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnClthCrvChng_1pm2) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnClthCrvChng_1pm2(val)	(S_ABPLBP_CntrLnClthCrvChng_1pm2 = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnClthCrv_1pm
#define	S_ABPLBP_CntrLnClthCrv_1pm (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnClthCrv_1pm) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnClthCrv_1pm(val)	(S_ABPLBP_CntrLnClthCrv_1pm = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnClthHeading_rad
#define	S_ABPLBP_CntrLnClthHeading_rad (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnClthHeading_rad) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnClthHeading_rad(val)	(S_ABPLBP_CntrLnClthHeading_rad = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnClthLength_met
#define	S_ABPLBP_CntrLnClthLength_met (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnClthLength_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnClthLength_met(val)	(S_ABPLBP_CntrLnClthLength_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnClthPosY0_met
#define	S_ABPLBP_CntrLnClthPosY0_met (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnClthPosY0_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnClthPosY0_met(val)	(S_ABPLBP_CntrLnClthPosY0_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnKalmanQual_perc
#define	S_ABPLBP_CntrLnKalmanQual_perc (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnKalmanQual_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnKalmanQual_perc(val)	(S_ABPLBP_CntrLnKalmanQual_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CntrLnKalmanStatus_nu
#define	S_ABPLBP_CntrLnKalmanStatus_nu (ABPLBP_SenDbgPtr->S_ABPLBP_CntrLnKalmanStatus_nu) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnKalmanStatus_nu(val)	(S_ABPLBP_CntrLnKalmanStatus_nu = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_ConstructionSite_bool
#define	S_ABPLBP_ConstructionSite_bool (ABPLBP_SenDbgPtr->S_ABPLBP_ConstructionSite_bool) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_ConstructionSite_bool(val)	(S_ABPLBP_ConstructionSite_bool = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_CoupledLaneWidth_met
#define	S_ABPLBP_CoupledLaneWidth_met (ABPLBP_SenDbgPtr->S_ABPLBP_CoupledLaneWidth_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CoupledLaneWidth_met(val)	(S_ABPLBP_CoupledLaneWidth_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_ExitLeft_perc
#define	S_ABPLBP_ExitLeft_perc (ABPLBP_SenDbgPtr->S_ABPLBP_ExitLeft_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_ExitLeft_perc(val)	(S_ABPLBP_ExitLeft_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_ExitRight_perc
#define	S_ABPLBP_ExitRight_perc (ABPLBP_SenDbgPtr->S_ABPLBP_ExitRight_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_ExitRight_perc(val)	(S_ABPLBP_ExitRight_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LaneChangeDetected_bool
#define	S_ABPLBP_LaneChangeDetected_bool (ABPLBP_SenDbgPtr->S_ABPLBP_LaneChangeDetected_bool) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LaneChangeDetected_bool(val)	(S_ABPLBP_LaneChangeDetected_bool = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LaneValidQualDMC_nu
#define	S_ABPLBP_LaneValidQualDMC_nu (ABPLBP_SenDbgPtr->S_ABPLBP_LaneValidQualDMC_nu) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LaneValidQualDMC_nu(val)	(S_ABPLBP_LaneValidQualDMC_nu = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LaneValidQualVis_nu
#define	S_ABPLBP_LaneValidQualVis_nu (ABPLBP_SenDbgPtr->S_ABPLBP_LaneValidQualVis_nu) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LaneValidQualVis_nu(val)	(S_ABPLBP_LaneValidQualVis_nu = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LaneWidth_met
#define	S_ABPLBP_LaneWidth_met (ABPLBP_SenDbgPtr->S_ABPLBP_LaneWidth_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LaneWidth_met(val)	(S_ABPLBP_LaneWidth_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeCoupLnQual_perc
#define	S_ABPLBP_LeCoupLnQual_perc (ABPLBP_SenDbgPtr->S_ABPLBP_LeCoupLnQual_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeCoupLnQual_perc(val)	(S_ABPLBP_LeCoupLnQual_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeCrvQuality_perc
#define	S_ABPLBP_LeCrvQuality_perc (ABPLBP_SenDbgPtr->S_ABPLBP_LeCrvQuality_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeCrvQuality_perc(val)	(S_ABPLBP_LeCrvQuality_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthCrvChng_1pm2
#define	S_ABPLBP_LeLnClthCrvChng_1pm2 (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthCrvChng_1pm2) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthCrvChng_1pm2(val)	(S_ABPLBP_LeLnClthCrvChng_1pm2 = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthCrvRtSIF_1pm2
#define	S_ABPLBP_LeLnClthCrvRtSIF_1pm2 (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthCrvRtSIF_1pm2) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthCrvRtSIF_1pm2(val)	(S_ABPLBP_LeLnClthCrvRtSIF_1pm2 = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthCrvSIF_1pm
#define	S_ABPLBP_LeLnClthCrvSIF_1pm (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthCrvSIF_1pm) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthCrvSIF_1pm(val)	(S_ABPLBP_LeLnClthCrvSIF_1pm = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthCrv_1pm
#define	S_ABPLBP_LeLnClthCrv_1pm (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthCrv_1pm) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthCrv_1pm(val)	(S_ABPLBP_LeLnClthCrv_1pm = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthHeadingSIF_rad
#define	S_ABPLBP_LeLnClthHeadingSIF_rad (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthHeadingSIF_rad) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthHeadingSIF_rad(val)	(S_ABPLBP_LeLnClthHeadingSIF_rad = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthHeading_rad
#define	S_ABPLBP_LeLnClthHeading_rad (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthHeading_rad) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthHeading_rad(val)	(S_ABPLBP_LeLnClthHeading_rad = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthLength_met
#define	S_ABPLBP_LeLnClthLength_met (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthLength_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthLength_met(val)	(S_ABPLBP_LeLnClthLength_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthPosY0SIF_met
#define	S_ABPLBP_LeLnClthPosY0SIF_met (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthPosY0SIF_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthPosY0SIF_met(val)	(S_ABPLBP_LeLnClthPosY0SIF_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthPosY0_met
#define	S_ABPLBP_LeLnClthPosY0_met (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnClthPosY0_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthPosY0_met(val)	(S_ABPLBP_LeLnClthPosY0_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnInvalidQuSIF_btf
#define	S_ABPLBP_LeLnInvalidQuSIF_btf (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnInvalidQuSIF_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnInvalidQuSIF_btf(val)	(S_ABPLBP_LeLnInvalidQuSIF_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnInvalidQu_btf
#define	S_ABPLBP_LeLnInvalidQu_btf (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnInvalidQu_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnInvalidQu_btf(val)	(S_ABPLBP_LeLnInvalidQu_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnLengthSIF_met
#define	S_ABPLBP_LeLnLengthSIF_met (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnLengthSIF_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnLengthSIF_met(val)	(S_ABPLBP_LeLnLengthSIF_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnQualitySIF_perc
#define	S_ABPLBP_LeLnQualitySIF_perc (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnQualitySIF_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnQualitySIF_perc(val)	(S_ABPLBP_LeLnQualitySIF_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnQuality_perc
#define	S_ABPLBP_LeLnQuality_perc (ABPLBP_SenDbgPtr->S_ABPLBP_LeLnQuality_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnQuality_perc(val)	(S_ABPLBP_LeLnQuality_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeUncoupBrid_bool
#define	S_ABPLBP_LeUncoupBrid_bool (ABPLBP_SenDbgPtr->S_ABPLBP_LeUncoupBrid_bool) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeUncoupBrid_bool(val)	(S_ABPLBP_LeUncoupBrid_bool = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeUncoupLnQual_perc
#define	S_ABPLBP_LeUncoupLnQual_perc (ABPLBP_SenDbgPtr->S_ABPLBP_LeUncoupLnQual_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeUncoupLnQual_perc(val)	(S_ABPLBP_LeUncoupLnQual_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_OutRangeCheckQuali_btf
#define	S_ABPLBP_OutRangeCheckQuali_btf (ABPLBP_SenDbgPtr->S_ABPLBP_OutRangeCheckQuali_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_OutRangeCheckQuali_btf(val)	(S_ABPLBP_OutRangeCheckQuali_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_PitchingDetected_bool
#define	S_ABPLBP_PitchingDetected_bool (ABPLBP_SenDbgPtr->S_ABPLBP_PitchingDetected_bool) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_PitchingDetected_bool(val)	(S_ABPLBP_PitchingDetected_bool = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_PitchingProb_perc
#define	S_ABPLBP_PitchingProb_perc (ABPLBP_SenDbgPtr->S_ABPLBP_PitchingProb_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_PitchingProb_perc(val)	(S_ABPLBP_PitchingProb_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RangeCheckQualifier_btf
#define	S_ABPLBP_RangeCheckQualifier_btf (ABPLBP_SenDbgPtr->S_ABPLBP_RangeCheckQualifier_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RangeCheckQualifier_btf(val)	(S_ABPLBP_RangeCheckQualifier_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiCoupLnQual_perc
#define	S_ABPLBP_RiCoupLnQual_perc (ABPLBP_SenDbgPtr->S_ABPLBP_RiCoupLnQual_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiCoupLnQual_perc(val)	(S_ABPLBP_RiCoupLnQual_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiCrvQuality_perc
#define	S_ABPLBP_RiCrvQuality_perc (ABPLBP_SenDbgPtr->S_ABPLBP_RiCrvQuality_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiCrvQuality_perc(val)	(S_ABPLBP_RiCrvQuality_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthCrvChng_1pm2
#define	S_ABPLBP_RiLnClthCrvChng_1pm2 (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthCrvChng_1pm2) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthCrvChng_1pm2(val)	(S_ABPLBP_RiLnClthCrvChng_1pm2 = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthCrvRtSIF_1pm2
#define	S_ABPLBP_RiLnClthCrvRtSIF_1pm2 (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthCrvRtSIF_1pm2) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthCrvRtSIF_1pm2(val)	(S_ABPLBP_RiLnClthCrvRtSIF_1pm2 = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthCrvSIF_1pm
#define	S_ABPLBP_RiLnClthCrvSIF_1pm (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthCrvSIF_1pm) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthCrvSIF_1pm(val)	(S_ABPLBP_RiLnClthCrvSIF_1pm = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthCrv_1pm
#define	S_ABPLBP_RiLnClthCrv_1pm (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthCrv_1pm) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthCrv_1pm(val)	(S_ABPLBP_RiLnClthCrv_1pm = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthHeadingSIF_rad
#define	S_ABPLBP_RiLnClthHeadingSIF_rad (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthHeadingSIF_rad) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthHeadingSIF_rad(val)	(S_ABPLBP_RiLnClthHeadingSIF_rad = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthHeading_rad
#define	S_ABPLBP_RiLnClthHeading_rad (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthHeading_rad) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthHeading_rad(val)	(S_ABPLBP_RiLnClthHeading_rad = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthLength_met
#define	S_ABPLBP_RiLnClthLength_met (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthLength_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthLength_met(val)	(S_ABPLBP_RiLnClthLength_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthPosY0SIF_met
#define	S_ABPLBP_RiLnClthPosY0SIF_met (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthPosY0SIF_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthPosY0SIF_met(val)	(S_ABPLBP_RiLnClthPosY0SIF_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthPosY0_met
#define	S_ABPLBP_RiLnClthPosY0_met (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnClthPosY0_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthPosY0_met(val)	(S_ABPLBP_RiLnClthPosY0_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnInvalidQuSIF_btf
#define	S_ABPLBP_RiLnInvalidQuSIF_btf (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnInvalidQuSIF_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnInvalidQuSIF_btf(val)	(S_ABPLBP_RiLnInvalidQuSIF_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnInvalidQu_btf
#define	S_ABPLBP_RiLnInvalidQu_btf (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnInvalidQu_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnInvalidQu_btf(val)	(S_ABPLBP_RiLnInvalidQu_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnLengthSIF_met
#define	S_ABPLBP_RiLnLengthSIF_met (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnLengthSIF_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnLengthSIF_met(val)	(S_ABPLBP_RiLnLengthSIF_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnQualitySIF_perc
#define	S_ABPLBP_RiLnQualitySIF_perc (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnQualitySIF_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnQualitySIF_perc(val)	(S_ABPLBP_RiLnQualitySIF_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnQuality_perc
#define	S_ABPLBP_RiLnQuality_perc (ABPLBP_SenDbgPtr->S_ABPLBP_RiLnQuality_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnQuality_perc(val)	(S_ABPLBP_RiLnQuality_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiUncoupBrid_bool
#define	S_ABPLBP_RiUncoupBrid_bool (ABPLBP_SenDbgPtr->S_ABPLBP_RiUncoupBrid_bool) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiUncoupBrid_bool(val)	(S_ABPLBP_RiUncoupBrid_bool = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiUncoupLnQual_perc
#define	S_ABPLBP_RiUncoupLnQual_perc (ABPLBP_SenDbgPtr->S_ABPLBP_RiUncoupLnQual_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiUncoupLnQual_perc(val)	(S_ABPLBP_RiUncoupLnQual_perc = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_StraightPathDtct_nu
#define	S_ABPLBP_StraightPathDtct_nu (ABPLBP_SenDbgPtr->S_ABPLBP_StraightPathDtct_nu) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_StraightPathDtct_nu(val)	(S_ABPLBP_StraightPathDtct_nu = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_UncoupledLaneBrid_btf
#define	S_ABPLBP_UncoupledLaneBrid_btf (ABPLBP_SenDbgPtr->S_ABPLBP_UncoupledLaneBrid_btf) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_UncoupledLaneBrid_btf(val)	(S_ABPLBP_UncoupledLaneBrid_btf = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_UncoupledLaneWidth_met
#define	S_ABPLBP_UncoupledLaneWidth_met (ABPLBP_SenDbgPtr->S_ABPLBP_UncoupledLaneWidth_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_UncoupledLaneWidth_met(val)	(S_ABPLBP_UncoupledLaneWidth_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_UpDownHillDtct_perc
#define	S_ABPLBP_UpDownHillDtct_perc (ABPLBP_SenDbgPtr->S_ABPLBP_UpDownHillDtct_perc) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_UpDownHillDtct_perc(val)	(S_ABPLBP_UpDownHillDtct_perc = (val)) //!< ABPLBP debug macro setter.

/*-----------------------------------------------------*
   O U T P U T   M A C R O   S E T T E R S
**-----------------------------------------------------*/

#undef	S_ABPLBP_CntrLnClthPosX0_met
#define	S_ABPLBP_CntrLnClthPosX0_met (ABPLBP_SenOutPtr->S_ABPLBP_CntrLnClthPosX0_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_CntrLnClthPosX0_met(val)	(S_ABPLBP_CntrLnClthPosX0_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeLnClthPosX0_met
#define	S_ABPLBP_LeLnClthPosX0_met (ABPLBP_SenOutPtr->S_ABPLBP_LeLnClthPosX0_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeLnClthPosX0_met(val)	(S_ABPLBP_LeLnClthPosX0_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_LeftLaneType_enum
#define	S_ABPLBP_LeftLaneType_enum (ABPLBP_SenOutPtr->S_ABPLBP_LeftLaneType_enum) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_LeftLaneType_enum(val)	(S_ABPLBP_LeftLaneType_enum = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RiLnClthPosX0_met
#define	S_ABPLBP_RiLnClthPosX0_met (ABPLBP_SenOutPtr->S_ABPLBP_RiLnClthPosX0_met) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RiLnClthPosX0_met(val)	(S_ABPLBP_RiLnClthPosX0_met = (val)) //!< ABPLBP debug macro setter.

#undef	S_ABPLBP_RightLaneType_enum
#define	S_ABPLBP_RightLaneType_enum (ABPLBP_SenOutPtr->S_ABPLBP_RightLaneType_enum) //!< ABPLBP debug macro.
#define	SET_S_ABPLBP_RightLaneType_enum(val)	(S_ABPLBP_RightLaneType_enum = (val)) //!< ABPLBP debug macro setter.

#ifdef __cplusplus
}
#endif

#endif // ABPLBP_PRIVATE_H_
