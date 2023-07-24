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
//! @file     ABPLBP_data.h
//! @brief     (ABPLBP) Module Data Header.

#ifndef ABPLBP_DATA_H_
#define ABPLBP_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "LCFSEN/LCFSEN_type.h"



/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*!
 *	ABPLBP module sensor get function. Function gets ABPLBP sensor debug data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ABPLBP_SenDbgPtr</b> Global static pointer to ABPLBP sensor debug data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ABPLBP_SenDbgType* ABPLBP_SenGetDbgPtr(void);

/*!
 *	ABPLBP module sensor get function. Function gets ABPLBP sensor output data pointer.
 *	
 *	@param
 *		void
 *		
 *	@return
 *		<b>ABPLBP_SenOutPtr</b> Global static pointer to ABPLBP sensor output data. 
 *		
 *	@testmethod
 *		Code Review
 *		
 *	@traceability
 *		Design Decision
 */
extern const ABPLBP_SenOutType* ABPLBP_SenGetOutPtr(void);

/*-----------------------------------------------------*
   D E B U G   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_ABPLBP_ABDTimeStamp_sec
#define S_ABPLBP_ABDTimeStamp_sec (ABPLBP_SenGetDbgPtr()->S_ABPLBP_ABDTimeStamp_sec) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_ABDTimeStamp_sec() (S_ABPLBP_ABDTimeStamp_sec) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_ABDTimeStamp_sec

#ifndef S_ABPLBP_CntrLnClthCrvChng_1pm2
#define S_ABPLBP_CntrLnClthCrvChng_1pm2 (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnClthCrvChng_1pm2) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnClthCrvChng_1pm2() (S_ABPLBP_CntrLnClthCrvChng_1pm2) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnClthCrvChng_1pm2

#ifndef S_ABPLBP_CntrLnClthCrv_1pm
#define S_ABPLBP_CntrLnClthCrv_1pm (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnClthCrv_1pm) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnClthCrv_1pm() (S_ABPLBP_CntrLnClthCrv_1pm) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnClthCrv_1pm

#ifndef S_ABPLBP_CntrLnClthHeading_rad
#define S_ABPLBP_CntrLnClthHeading_rad (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnClthHeading_rad) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnClthHeading_rad() (S_ABPLBP_CntrLnClthHeading_rad) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnClthHeading_rad

#ifndef S_ABPLBP_CntrLnClthLength_met
#define S_ABPLBP_CntrLnClthLength_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnClthLength_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnClthLength_met() (S_ABPLBP_CntrLnClthLength_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnClthLength_met

#ifndef S_ABPLBP_CntrLnClthPosY0_met
#define S_ABPLBP_CntrLnClthPosY0_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnClthPosY0_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnClthPosY0_met() (S_ABPLBP_CntrLnClthPosY0_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnClthPosY0_met

#ifndef S_ABPLBP_CntrLnKalmanQual_perc
#define S_ABPLBP_CntrLnKalmanQual_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnKalmanQual_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnKalmanQual_perc() (S_ABPLBP_CntrLnKalmanQual_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnKalmanQual_perc

#ifndef S_ABPLBP_CntrLnKalmanStatus_nu
#define S_ABPLBP_CntrLnKalmanStatus_nu (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CntrLnKalmanStatus_nu) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CntrLnKalmanStatus_nu() (S_ABPLBP_CntrLnKalmanStatus_nu) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CntrLnKalmanStatus_nu

#ifndef S_ABPLBP_ConstructionSite_bool
#define S_ABPLBP_ConstructionSite_bool (ABPLBP_SenGetDbgPtr()->S_ABPLBP_ConstructionSite_bool) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_ConstructionSite_bool() (S_ABPLBP_ConstructionSite_bool) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_ConstructionSite_bool

#ifndef S_ABPLBP_CoupledLaneWidth_met
#define S_ABPLBP_CoupledLaneWidth_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_CoupledLaneWidth_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_CoupledLaneWidth_met() (S_ABPLBP_CoupledLaneWidth_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_CoupledLaneWidth_met

#ifndef S_ABPLBP_ExitLeft_perc
#define S_ABPLBP_ExitLeft_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_ExitLeft_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_ExitLeft_perc() (S_ABPLBP_ExitLeft_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_ExitLeft_perc

#ifndef S_ABPLBP_ExitRight_perc
#define S_ABPLBP_ExitRight_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_ExitRight_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_ExitRight_perc() (S_ABPLBP_ExitRight_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_ExitRight_perc

#ifndef S_ABPLBP_LaneChangeDetected_bool
#define S_ABPLBP_LaneChangeDetected_bool (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LaneChangeDetected_bool) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LaneChangeDetected_bool() (S_ABPLBP_LaneChangeDetected_bool) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LaneChangeDetected_bool

#ifndef S_ABPLBP_LaneValidQualDMC_nu
#define S_ABPLBP_LaneValidQualDMC_nu (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LaneValidQualDMC_nu) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LaneValidQualDMC_nu() (S_ABPLBP_LaneValidQualDMC_nu) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LaneValidQualDMC_nu

#ifndef S_ABPLBP_LaneValidQualVis_nu
#define S_ABPLBP_LaneValidQualVis_nu (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LaneValidQualVis_nu) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LaneValidQualVis_nu() (S_ABPLBP_LaneValidQualVis_nu) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LaneValidQualVis_nu

#ifndef S_ABPLBP_LaneWidth_met
#define S_ABPLBP_LaneWidth_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LaneWidth_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LaneWidth_met() (S_ABPLBP_LaneWidth_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LaneWidth_met

#ifndef S_ABPLBP_LeCoupLnQual_perc
#define S_ABPLBP_LeCoupLnQual_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeCoupLnQual_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeCoupLnQual_perc() (S_ABPLBP_LeCoupLnQual_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeCoupLnQual_perc

#ifndef S_ABPLBP_LeCrvQuality_perc
#define S_ABPLBP_LeCrvQuality_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeCrvQuality_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeCrvQuality_perc() (S_ABPLBP_LeCrvQuality_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeCrvQuality_perc

#ifndef S_ABPLBP_LeLnClthCrvChng_1pm2
#define S_ABPLBP_LeLnClthCrvChng_1pm2 (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthCrvChng_1pm2) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthCrvChng_1pm2() (S_ABPLBP_LeLnClthCrvChng_1pm2) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthCrvChng_1pm2

#ifndef S_ABPLBP_LeLnClthCrvRtSIF_1pm2
#define S_ABPLBP_LeLnClthCrvRtSIF_1pm2 (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthCrvRtSIF_1pm2) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthCrvRtSIF_1pm2() (S_ABPLBP_LeLnClthCrvRtSIF_1pm2) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthCrvRtSIF_1pm2

#ifndef S_ABPLBP_LeLnClthCrvSIF_1pm
#define S_ABPLBP_LeLnClthCrvSIF_1pm (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthCrvSIF_1pm) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthCrvSIF_1pm() (S_ABPLBP_LeLnClthCrvSIF_1pm) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthCrvSIF_1pm

#ifndef S_ABPLBP_LeLnClthCrv_1pm
#define S_ABPLBP_LeLnClthCrv_1pm (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthCrv_1pm) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthCrv_1pm() (S_ABPLBP_LeLnClthCrv_1pm) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthCrv_1pm

#ifndef S_ABPLBP_LeLnClthHeadingSIF_rad
#define S_ABPLBP_LeLnClthHeadingSIF_rad (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthHeadingSIF_rad) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthHeadingSIF_rad() (S_ABPLBP_LeLnClthHeadingSIF_rad) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthHeadingSIF_rad

#ifndef S_ABPLBP_LeLnClthHeading_rad
#define S_ABPLBP_LeLnClthHeading_rad (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthHeading_rad) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthHeading_rad() (S_ABPLBP_LeLnClthHeading_rad) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthHeading_rad

#ifndef S_ABPLBP_LeLnClthLength_met
#define S_ABPLBP_LeLnClthLength_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthLength_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthLength_met() (S_ABPLBP_LeLnClthLength_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthLength_met

#ifndef S_ABPLBP_LeLnClthPosY0SIF_met
#define S_ABPLBP_LeLnClthPosY0SIF_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthPosY0SIF_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthPosY0SIF_met() (S_ABPLBP_LeLnClthPosY0SIF_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthPosY0SIF_met

#ifndef S_ABPLBP_LeLnClthPosY0_met
#define S_ABPLBP_LeLnClthPosY0_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnClthPosY0_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnClthPosY0_met() (S_ABPLBP_LeLnClthPosY0_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnClthPosY0_met

#ifndef S_ABPLBP_LeLnInvalidQuSIF_btf
#define S_ABPLBP_LeLnInvalidQuSIF_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnInvalidQuSIF_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnInvalidQuSIF_btf() (S_ABPLBP_LeLnInvalidQuSIF_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnInvalidQuSIF_btf

#ifndef S_ABPLBP_LeLnInvalidQu_btf
#define S_ABPLBP_LeLnInvalidQu_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnInvalidQu_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnInvalidQu_btf() (S_ABPLBP_LeLnInvalidQu_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnInvalidQu_btf

#ifndef S_ABPLBP_LeLnLengthSIF_met
#define S_ABPLBP_LeLnLengthSIF_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnLengthSIF_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnLengthSIF_met() (S_ABPLBP_LeLnLengthSIF_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnLengthSIF_met

#ifndef S_ABPLBP_LeLnQualitySIF_perc
#define S_ABPLBP_LeLnQualitySIF_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnQualitySIF_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnQualitySIF_perc() (S_ABPLBP_LeLnQualitySIF_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnQualitySIF_perc

#ifndef S_ABPLBP_LeLnQuality_perc
#define S_ABPLBP_LeLnQuality_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeLnQuality_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeLnQuality_perc() (S_ABPLBP_LeLnQuality_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeLnQuality_perc

#ifndef S_ABPLBP_LeUncoupBrid_bool
#define S_ABPLBP_LeUncoupBrid_bool (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeUncoupBrid_bool) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeUncoupBrid_bool() (S_ABPLBP_LeUncoupBrid_bool) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeUncoupBrid_bool

#ifndef S_ABPLBP_LeUncoupLnQual_perc
#define S_ABPLBP_LeUncoupLnQual_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_LeUncoupLnQual_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_LeUncoupLnQual_perc() (S_ABPLBP_LeUncoupLnQual_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_LeUncoupLnQual_perc

#ifndef S_ABPLBP_OutRangeCheckQuali_btf
#define S_ABPLBP_OutRangeCheckQuali_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_OutRangeCheckQuali_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_OutRangeCheckQuali_btf() (S_ABPLBP_OutRangeCheckQuali_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_OutRangeCheckQuali_btf

#ifndef S_ABPLBP_PitchingDetected_bool
#define S_ABPLBP_PitchingDetected_bool (ABPLBP_SenGetDbgPtr()->S_ABPLBP_PitchingDetected_bool) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_PitchingDetected_bool() (S_ABPLBP_PitchingDetected_bool) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_PitchingDetected_bool

#ifndef S_ABPLBP_PitchingProb_perc
#define S_ABPLBP_PitchingProb_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_PitchingProb_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_PitchingProb_perc() (S_ABPLBP_PitchingProb_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_PitchingProb_perc

#ifndef S_ABPLBP_RangeCheckQualifier_btf
#define S_ABPLBP_RangeCheckQualifier_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RangeCheckQualifier_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RangeCheckQualifier_btf() (S_ABPLBP_RangeCheckQualifier_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RangeCheckQualifier_btf

#ifndef S_ABPLBP_RiCoupLnQual_perc
#define S_ABPLBP_RiCoupLnQual_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiCoupLnQual_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiCoupLnQual_perc() (S_ABPLBP_RiCoupLnQual_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiCoupLnQual_perc

#ifndef S_ABPLBP_RiCrvQuality_perc
#define S_ABPLBP_RiCrvQuality_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiCrvQuality_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiCrvQuality_perc() (S_ABPLBP_RiCrvQuality_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiCrvQuality_perc

#ifndef S_ABPLBP_RiLnClthCrvChng_1pm2
#define S_ABPLBP_RiLnClthCrvChng_1pm2 (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthCrvChng_1pm2) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthCrvChng_1pm2() (S_ABPLBP_RiLnClthCrvChng_1pm2) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthCrvChng_1pm2

#ifndef S_ABPLBP_RiLnClthCrvRtSIF_1pm2
#define S_ABPLBP_RiLnClthCrvRtSIF_1pm2 (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthCrvRtSIF_1pm2) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthCrvRtSIF_1pm2() (S_ABPLBP_RiLnClthCrvRtSIF_1pm2) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthCrvRtSIF_1pm2

#ifndef S_ABPLBP_RiLnClthCrvSIF_1pm
#define S_ABPLBP_RiLnClthCrvSIF_1pm (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthCrvSIF_1pm) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthCrvSIF_1pm() (S_ABPLBP_RiLnClthCrvSIF_1pm) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthCrvSIF_1pm

#ifndef S_ABPLBP_RiLnClthCrv_1pm
#define S_ABPLBP_RiLnClthCrv_1pm (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthCrv_1pm) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthCrv_1pm() (S_ABPLBP_RiLnClthCrv_1pm) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthCrv_1pm

#ifndef S_ABPLBP_RiLnClthHeadingSIF_rad
#define S_ABPLBP_RiLnClthHeadingSIF_rad (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthHeadingSIF_rad) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthHeadingSIF_rad() (S_ABPLBP_RiLnClthHeadingSIF_rad) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthHeadingSIF_rad

#ifndef S_ABPLBP_RiLnClthHeading_rad
#define S_ABPLBP_RiLnClthHeading_rad (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthHeading_rad) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthHeading_rad() (S_ABPLBP_RiLnClthHeading_rad) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthHeading_rad

#ifndef S_ABPLBP_RiLnClthLength_met
#define S_ABPLBP_RiLnClthLength_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthLength_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthLength_met() (S_ABPLBP_RiLnClthLength_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthLength_met

#ifndef S_ABPLBP_RiLnClthPosY0SIF_met
#define S_ABPLBP_RiLnClthPosY0SIF_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthPosY0SIF_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthPosY0SIF_met() (S_ABPLBP_RiLnClthPosY0SIF_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthPosY0SIF_met

#ifndef S_ABPLBP_RiLnClthPosY0_met
#define S_ABPLBP_RiLnClthPosY0_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnClthPosY0_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnClthPosY0_met() (S_ABPLBP_RiLnClthPosY0_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnClthPosY0_met

#ifndef S_ABPLBP_RiLnInvalidQuSIF_btf
#define S_ABPLBP_RiLnInvalidQuSIF_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnInvalidQuSIF_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnInvalidQuSIF_btf() (S_ABPLBP_RiLnInvalidQuSIF_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnInvalidQuSIF_btf

#ifndef S_ABPLBP_RiLnInvalidQu_btf
#define S_ABPLBP_RiLnInvalidQu_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnInvalidQu_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnInvalidQu_btf() (S_ABPLBP_RiLnInvalidQu_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnInvalidQu_btf

#ifndef S_ABPLBP_RiLnLengthSIF_met
#define S_ABPLBP_RiLnLengthSIF_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnLengthSIF_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnLengthSIF_met() (S_ABPLBP_RiLnLengthSIF_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnLengthSIF_met

#ifndef S_ABPLBP_RiLnQualitySIF_perc
#define S_ABPLBP_RiLnQualitySIF_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnQualitySIF_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnQualitySIF_perc() (S_ABPLBP_RiLnQualitySIF_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnQualitySIF_perc

#ifndef S_ABPLBP_RiLnQuality_perc
#define S_ABPLBP_RiLnQuality_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiLnQuality_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiLnQuality_perc() (S_ABPLBP_RiLnQuality_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiLnQuality_perc

#ifndef S_ABPLBP_RiUncoupBrid_bool
#define S_ABPLBP_RiUncoupBrid_bool (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiUncoupBrid_bool) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiUncoupBrid_bool() (S_ABPLBP_RiUncoupBrid_bool) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiUncoupBrid_bool

#ifndef S_ABPLBP_RiUncoupLnQual_perc
#define S_ABPLBP_RiUncoupLnQual_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_RiUncoupLnQual_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_RiUncoupLnQual_perc() (S_ABPLBP_RiUncoupLnQual_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_RiUncoupLnQual_perc

#ifndef S_ABPLBP_StraightPathDtct_nu
#define S_ABPLBP_StraightPathDtct_nu (ABPLBP_SenGetDbgPtr()->S_ABPLBP_StraightPathDtct_nu) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_StraightPathDtct_nu() (S_ABPLBP_StraightPathDtct_nu) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_StraightPathDtct_nu

#ifndef S_ABPLBP_UncoupledLaneBrid_btf
#define S_ABPLBP_UncoupledLaneBrid_btf (ABPLBP_SenGetDbgPtr()->S_ABPLBP_UncoupledLaneBrid_btf) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_UncoupledLaneBrid_btf() (S_ABPLBP_UncoupledLaneBrid_btf) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_UncoupledLaneBrid_btf

#ifndef S_ABPLBP_UncoupledLaneWidth_met
#define S_ABPLBP_UncoupledLaneWidth_met (ABPLBP_SenGetDbgPtr()->S_ABPLBP_UncoupledLaneWidth_met) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_UncoupledLaneWidth_met() (S_ABPLBP_UncoupledLaneWidth_met) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_UncoupledLaneWidth_met

#ifndef S_ABPLBP_UpDownHillDtct_perc
#define S_ABPLBP_UpDownHillDtct_perc (ABPLBP_SenGetDbgPtr()->S_ABPLBP_UpDownHillDtct_perc) //!< ABPLBP debug macro.
#define GET_S_ABPLBP_UpDownHillDtct_perc() (S_ABPLBP_UpDownHillDtct_perc) //!< ABPLBP debug macro getter.
#endif // S_ABPLBP_UpDownHillDtct_perc

/*-----------------------------------------------------*
   O U T P U T   M A C R O   G E T T E R S
**-----------------------------------------------------*/

#ifndef S_ABPLBP_CntrLnClthPosX0_met
#define S_ABPLBP_CntrLnClthPosX0_met (ABPLBP_SenGetOutPtr()->S_ABPLBP_CntrLnClthPosX0_met) //!< ABPLBP output macro.
#define GET_S_ABPLBP_CntrLnClthPosX0_met() (S_ABPLBP_CntrLnClthPosX0_met) //!< ABPLBP output macro getter.
#endif // S_ABPLBP_CntrLnClthPosX0_met

#ifndef S_ABPLBP_LeLnClthPosX0_met
#define S_ABPLBP_LeLnClthPosX0_met (ABPLBP_SenGetOutPtr()->S_ABPLBP_LeLnClthPosX0_met) //!< ABPLBP output macro.
#define GET_S_ABPLBP_LeLnClthPosX0_met() (S_ABPLBP_LeLnClthPosX0_met) //!< ABPLBP output macro getter.
#endif // S_ABPLBP_LeLnClthPosX0_met

#ifndef S_ABPLBP_LeftLaneType_enum
#define S_ABPLBP_LeftLaneType_enum (ABPLBP_SenGetOutPtr()->S_ABPLBP_LeftLaneType_enum) //!< ABPLBP output macro.
#define GET_S_ABPLBP_LeftLaneType_enum() (S_ABPLBP_LeftLaneType_enum) //!< ABPLBP output macro getter.
#endif // S_ABPLBP_LeftLaneType_enum

#ifndef S_ABPLBP_RiLnClthPosX0_met
#define S_ABPLBP_RiLnClthPosX0_met (ABPLBP_SenGetOutPtr()->S_ABPLBP_RiLnClthPosX0_met) //!< ABPLBP output macro.
#define GET_S_ABPLBP_RiLnClthPosX0_met() (S_ABPLBP_RiLnClthPosX0_met) //!< ABPLBP output macro getter.
#endif // S_ABPLBP_RiLnClthPosX0_met

#ifndef S_ABPLBP_RightLaneType_enum
#define S_ABPLBP_RightLaneType_enum (ABPLBP_SenGetOutPtr()->S_ABPLBP_RightLaneType_enum) //!< ABPLBP output macro.
#define GET_S_ABPLBP_RightLaneType_enum() (S_ABPLBP_RightLaneType_enum) //!< ABPLBP output macro getter.
#endif // S_ABPLBP_RightLaneType_enum

#endif // ABPLBP_DATA_H_
