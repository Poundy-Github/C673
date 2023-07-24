/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PRODUCT FAMILY : MFC431x
  PROJECT        : MFC5J3
  COMPONENT      : LCF
  BUILD          : DPU
  TASK           : Vehicle
  SUB-COMPONENTS : DRVMN,TRJPLN,TRJCTR,LATDMC
  AUTHOR         : Task_AuxCodeGen
  VERSION        : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     LCFVEH_data.h
//! @brief    Lateral Control Functions - Vehicle (LCFVEH) Task Data Header.

#ifndef LCFVEH_DATA_H_
#define LCFVEH_DATA_H_

/*-----------------------------------------------------*
   I N C L U D E S
**-----------------------------------------------------*/

#include "DRVMN/DRVMNVEH_data.h"
#include "TRJPLN/TRJPLNVEH_data.h"
#include "TRJCTR/TRJCTRVEH_data.h"
#include "LATDMC/LATDMCVEH_data.h"
#include "LCFRCV/LCFRCVVEH.h"
#include "LCFSND/LCFSNDVEH.h"
#include "LCFPRM/LCFPRM_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**-----------------------------------------------------*/

/*-----------------------------------------------------*
   S T U B B E D   I N P U T   M A C R O S
**-----------------------------------------------------*/

#ifndef S_ABPLBP_LeCrvQuality_perc
#define S_ABPLBP_LeCrvQuality_perc (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_ABPLBP_LeCrvQuality_perc() S_ABPLBP_LeCrvQuality_perc //!< LCFVEH stubbed input macro getter.
#endif // S_ABPLBP_LeCrvQuality_perc

#ifndef S_ABPLBP_LeLnQuality_perc
#define S_ABPLBP_LeLnQuality_perc (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_ABPLBP_LeLnQuality_perc() S_ABPLBP_LeLnQuality_perc //!< LCFVEH stubbed input macro getter.
#endif // S_ABPLBP_LeLnQuality_perc

#ifndef S_ABPLBP_RiCrvQuality_perc
#define S_ABPLBP_RiCrvQuality_perc (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_ABPLBP_RiCrvQuality_perc() S_ABPLBP_RiCrvQuality_perc //!< LCFVEH stubbed input macro getter.
#endif // S_ABPLBP_RiCrvQuality_perc

#ifndef S_ABPLBP_RiLnQuality_perc
#define S_ABPLBP_RiLnQuality_perc (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_ABPLBP_RiLnQuality_perc() S_ABPLBP_RiLnQuality_perc //!< LCFVEH stubbed input macro getter.
#endif // S_ABPLBP_RiLnQuality_perc

#ifndef S_ABPLBP_UpDownHillDtct_perc
#define S_ABPLBP_UpDownHillDtct_perc (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_ABPLBP_UpDownHillDtct_perc() S_ABPLBP_UpDownHillDtct_perc //!< LCFVEH stubbed input macro getter.
#endif // S_ABPLBP_UpDownHillDtct_perc

#ifndef S_CSCLTA_DistYTolLeTgtArea_met
#define S_CSCLTA_DistYTolLeTgtArea_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_DistYTolLeTgtArea_met() S_CSCLTA_DistYTolLeTgtArea_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_DistYTolLeTgtArea_met

#ifndef S_CSCLTA_DistYTolRiTgtArea_met
#define S_CSCLTA_DistYTolRiTgtArea_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_DistYTolRiTgtArea_met() S_CSCLTA_DistYTolRiTgtArea_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_DistYTolRiTgtArea_met

#ifndef S_CSCLTA_FTireAclMax_mps2
#define S_CSCLTA_FTireAclMax_mps2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_FTireAclMax_mps2() S_CSCLTA_FTireAclMax_mps2 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_FTireAclMax_mps2

#ifndef S_CSCLTA_FTireAclMin_mps2
#define S_CSCLTA_FTireAclMin_mps2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_FTireAclMin_mps2() S_CSCLTA_FTireAclMin_mps2 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_FTireAclMin_mps2

#ifndef S_CSCLTA_GrdLimitTgtCrvTGC_1pms
#define S_CSCLTA_GrdLimitTgtCrvTGC_1pms (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_GrdLimitTgtCrvTGC_1pms() S_CSCLTA_GrdLimitTgtCrvTGC_1pms //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_GrdLimitTgtCrvTGC_1pms

#ifndef S_CSCLTA_LatencyCompActivated_nu
#define S_CSCLTA_LatencyCompActivated_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LatencyCompActivated_nu() S_CSCLTA_LatencyCompActivated_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LatencyCompActivated_nu

#ifndef S_CSCLTA_LeCridrBndCrvChng_1pm2
#define S_CSCLTA_LeCridrBndCrvChng_1pm2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LeCridrBndCrvChng_1pm2() S_CSCLTA_LeCridrBndCrvChng_1pm2 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LeCridrBndCrvChng_1pm2

#ifndef S_CSCLTA_LeCridrBndCrv_1pm
#define S_CSCLTA_LeCridrBndCrv_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LeCridrBndCrv_1pm() S_CSCLTA_LeCridrBndCrv_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LeCridrBndCrv_1pm

#ifndef S_CSCLTA_LeCridrBndHeadAng_rad
#define S_CSCLTA_LeCridrBndHeadAng_rad (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LeCridrBndHeadAng_rad() S_CSCLTA_LeCridrBndHeadAng_rad //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LeCridrBndHeadAng_rad

#ifndef S_CSCLTA_LeCridrBndLength_met
#define S_CSCLTA_LeCridrBndLength_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LeCridrBndLength_met() S_CSCLTA_LeCridrBndLength_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LeCridrBndLength_met

#ifndef S_CSCLTA_LeCridrBndPosX0_met
#define S_CSCLTA_LeCridrBndPosX0_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LeCridrBndPosX0_met() S_CSCLTA_LeCridrBndPosX0_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LeCridrBndPosX0_met

#ifndef S_CSCLTA_LeCridrBndPosY0_met
#define S_CSCLTA_LeCridrBndPosY0_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LeCridrBndPosY0_met() S_CSCLTA_LeCridrBndPosY0_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LeCridrBndPosY0_met

#ifndef S_CSCLTA_LimiterActivated_nu
#define S_CSCLTA_LimiterActivated_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LimiterActivated_nu() S_CSCLTA_LimiterActivated_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LimiterActivated_nu

#ifndef S_CSCLTA_LimiterTimeDuration_sec
#define S_CSCLTA_LimiterTimeDuration_sec (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_LimiterTimeDuration_sec() S_CSCLTA_LimiterTimeDuration_sec //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_LimiterTimeDuration_sec

#ifndef S_CSCLTA_MaxCrvGrdBuildup_1pms
#define S_CSCLTA_MaxCrvGrdBuildup_1pms (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_MaxCrvGrdBuildup_1pms() S_CSCLTA_MaxCrvGrdBuildup_1pms //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_MaxCrvGrdBuildup_1pms

#ifndef S_CSCLTA_MaxCrvGrdRed_1pms
#define S_CSCLTA_MaxCrvGrdRed_1pms (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_MaxCrvGrdRed_1pms() S_CSCLTA_MaxCrvGrdRed_1pms //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_MaxCrvGrdRed_1pms

#ifndef S_CSCLTA_MaxCrvTrajGuiCtrl_1pm
#define S_CSCLTA_MaxCrvTrajGuiCtrl_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_MaxCrvTrajGuiCtrl_1pm() S_CSCLTA_MaxCrvTrajGuiCtrl_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_MaxCrvTrajGuiCtrl_1pm

#ifndef S_CSCLTA_MaxJerkAllowed_mps3
#define S_CSCLTA_MaxJerkAllowed_mps3 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_MaxJerkAllowed_mps3() S_CSCLTA_MaxJerkAllowed_mps3 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_MaxJerkAllowed_mps3

#ifndef S_CSCLTA_ObstacleAclX_mps2
#define S_CSCLTA_ObstacleAclX_mps2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_ObstacleAclX_mps2() S_CSCLTA_ObstacleAclX_mps2 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_ObstacleAclX_mps2

#ifndef S_CSCLTA_ObstacleDistX_met
#define S_CSCLTA_ObstacleDistX_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_ObstacleDistX_met() S_CSCLTA_ObstacleDistX_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_ObstacleDistX_met

#ifndef S_CSCLTA_ObstacleDistY_met
#define S_CSCLTA_ObstacleDistY_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_ObstacleDistY_met() S_CSCLTA_ObstacleDistY_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_ObstacleDistY_met

#ifndef S_CSCLTA_ObstacleVelX_mps
#define S_CSCLTA_ObstacleVelX_mps (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_ObstacleVelX_mps() S_CSCLTA_ObstacleVelX_mps //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_ObstacleVelX_mps

#ifndef S_CSCLTA_ObstacleWidth_met
#define S_CSCLTA_ObstacleWidth_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_ObstacleWidth_met() S_CSCLTA_ObstacleWidth_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_ObstacleWidth_met

#ifndef S_CSCLTA_PlanningHorizon_sec
#define S_CSCLTA_PlanningHorizon_sec (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_PlanningHorizon_sec() S_CSCLTA_PlanningHorizon_sec //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_PlanningHorizon_sec

#ifndef S_CSCLTA_PredTimeHeadAng_sec
#define S_CSCLTA_PredTimeHeadAng_sec (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_PredTimeHeadAng_sec() S_CSCLTA_PredTimeHeadAng_sec //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_PredTimeHeadAng_sec

#ifndef S_CSCLTA_PredictionTimeCrv_sec
#define S_CSCLTA_PredictionTimeCrv_sec (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_PredictionTimeCrv_sec() S_CSCLTA_PredictionTimeCrv_sec //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_PredictionTimeCrv_sec

#ifndef S_CSCLTA_RiCridrBndCrvChng_1pm2
#define S_CSCLTA_RiCridrBndCrvChng_1pm2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_RiCridrBndCrvChng_1pm2() S_CSCLTA_RiCridrBndCrvChng_1pm2 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_RiCridrBndCrvChng_1pm2

#ifndef S_CSCLTA_RiCridrBndCrv_1pm
#define S_CSCLTA_RiCridrBndCrv_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_RiCridrBndCrv_1pm() S_CSCLTA_RiCridrBndCrv_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_RiCridrBndCrv_1pm

#ifndef S_CSCLTA_RiCridrBndHeadAng_rad
#define S_CSCLTA_RiCridrBndHeadAng_rad (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_RiCridrBndHeadAng_rad() S_CSCLTA_RiCridrBndHeadAng_rad //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_RiCridrBndHeadAng_rad

#ifndef S_CSCLTA_RiCridrBndLength_met
#define S_CSCLTA_RiCridrBndLength_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_RiCridrBndLength_met() S_CSCLTA_RiCridrBndLength_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_RiCridrBndLength_met

#ifndef S_CSCLTA_RiCridrBndPosX0_met
#define S_CSCLTA_RiCridrBndPosX0_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_RiCridrBndPosX0_met() S_CSCLTA_RiCridrBndPosX0_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_RiCridrBndPosX0_met

#ifndef S_CSCLTA_RiCridrBndPosY0_met
#define S_CSCLTA_RiCridrBndPosY0_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_RiCridrBndPosY0_met() S_CSCLTA_RiCridrBndPosY0_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_RiCridrBndPosY0_met

#ifndef S_CSCLTA_SensorTStamp_sec
#define S_CSCLTA_SensorTStamp_sec (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_SensorTStamp_sec() S_CSCLTA_SensorTStamp_sec //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_SensorTStamp_sec

#ifndef S_CSCLTA_SysStateLCF_enum
#define S_CSCLTA_SysStateLCF_enum (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_SysStateLCF_enum() S_CSCLTA_SysStateLCF_enum //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_SysStateLCF_enum

#ifndef S_CSCLTA_TgtTrajCrvChng_1pm2
#define S_CSCLTA_TgtTrajCrvChng_1pm2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TgtTrajCrvChng_1pm2() S_CSCLTA_TgtTrajCrvChng_1pm2 //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TgtTrajCrvChng_1pm2

#ifndef S_CSCLTA_TgtTrajCrv_1pm
#define S_CSCLTA_TgtTrajCrv_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TgtTrajCrv_1pm() S_CSCLTA_TgtTrajCrv_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TgtTrajCrv_1pm

#ifndef S_CSCLTA_TgtTrajHeadAng_rad
#define S_CSCLTA_TgtTrajHeadAng_rad (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TgtTrajHeadAng_rad() S_CSCLTA_TgtTrajHeadAng_rad //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TgtTrajHeadAng_rad

#ifndef S_CSCLTA_TgtTrajLength_met
#define S_CSCLTA_TgtTrajLength_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TgtTrajLength_met() S_CSCLTA_TgtTrajLength_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TgtTrajLength_met

#ifndef S_CSCLTA_TgtTrajPosX0_met
#define S_CSCLTA_TgtTrajPosX0_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TgtTrajPosX0_met() S_CSCLTA_TgtTrajPosX0_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TgtTrajPosX0_met

#ifndef S_CSCLTA_TgtTrajPosY0_met
#define S_CSCLTA_TgtTrajPosY0_met (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TgtTrajPosY0_met() S_CSCLTA_TgtTrajPosY0_met //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TgtTrajPosY0_met

#ifndef S_CSCLTA_TrajGuiQualifier_nu
#define S_CSCLTA_TrajGuiQualifier_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TrajGuiQualifier_nu() S_CSCLTA_TrajGuiQualifier_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TrajGuiQualifier_nu

#ifndef S_CSCLTA_TrajPlanServQu_nu
#define S_CSCLTA_TrajPlanServQu_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TrajPlanServQu_nu() S_CSCLTA_TrajPlanServQu_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TrajPlanServQu_nu

#ifndef S_CSCLTA_TriggerReplan_nu
#define S_CSCLTA_TriggerReplan_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_TriggerReplan_nu() S_CSCLTA_TriggerReplan_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_TriggerReplan_nu

#ifndef S_CSCLTA_WeightEndTime_nu
#define S_CSCLTA_WeightEndTime_nu (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_WeightEndTime_nu() S_CSCLTA_WeightEndTime_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_WeightEndTime_nu

#ifndef S_CSCLTA_WeightTgtDistY_nu
#define S_CSCLTA_WeightTgtDistY_nu (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_CSCLTA_WeightTgtDistY_nu() S_CSCLTA_WeightTgtDistY_nu //!< LCFVEH stubbed input macro getter.
#endif // S_CSCLTA_WeightTgtDistY_nu

#ifndef S_HMIOC_AvailableFunction_btf
#define S_HMIOC_AvailableFunction_btf (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_HMIOC_AvailableFunction_btf() S_HMIOC_AvailableFunction_btf //!< LCFVEH stubbed input macro getter.
#endif // S_HMIOC_AvailableFunction_btf

#ifndef S_LCFRCV_ActFctLevel_nu
#define S_LCFRCV_ActFctLevel_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_ActFctLevel_nu() S_LCFRCV_ActFctLevel_nu //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_ActFctLevel_nu

#ifndef S_LCFRCV_ActToi_nu
#define S_LCFRCV_ActToi_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_ActToi_nu() S_LCFRCV_ActToi_nu //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_ActToi_nu

#ifndef S_LCFRCV_EPS_ManualTrqActualVal_Nm
#define S_LCFRCV_EPS_ManualTrqActualVal_Nm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm() S_LCFRCV_EPS_ManualTrqActualVal_Nm //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_EPS_ManualTrqActualVal_Nm

#ifndef S_LCFRCV_HandsOffConfirmedExt_bool
#define S_LCFRCV_HandsOffConfirmedExt_bool (0u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_HandsOffConfirmedExt_bool() S_LCFRCV_HandsOffConfirmedExt_bool //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_HandsOffConfirmedExt_bool

#ifndef S_LCFRCV_KappaSumCommand_1pm
#define S_LCFRCV_KappaSumCommand_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_KappaSumCommand_1pm() S_LCFRCV_KappaSumCommand_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_KappaSumCommand_1pm

#ifndef S_LCFRCV_LaneStatusLaKMC_st
#define S_LCFRCV_LaneStatusLaKMC_st (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_LaneStatusLaKMC_st() S_LCFRCV_LaneStatusLaKMC_st //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_LaneStatusLaKMC_st

#ifndef S_LCFRCV_OffCompStWheelAngle_rad
#define S_LCFRCV_OffCompStWheelAngle_rad (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_OffCompStWheelAngle_rad() S_LCFRCV_OffCompStWheelAngle_rad //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_OffCompStWheelAngle_rad

#ifndef S_LCFRCV_RoadBankAngle_rad
#define S_LCFRCV_RoadBankAngle_rad (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_RoadBankAngle_rad() S_LCFRCV_RoadBankAngle_rad //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_RoadBankAngle_rad

#ifndef S_LCFRCV_SenToVehTStamp_us
#define S_LCFRCV_SenToVehTStamp_us (0x00000000u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_SenToVehTStamp_us() S_LCFRCV_SenToVehTStamp_us //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_SenToVehTStamp_us

#ifndef S_LCFRCV_SteerAngleLatDMC_deg
#define S_LCFRCV_SteerAngleLatDMC_deg (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_SteerAngleLatDMC_deg() S_LCFRCV_SteerAngleLatDMC_deg //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_SteerAngleLatDMC_deg

#ifndef S_LCFRCV_SteerWAngleRate_degps
#define S_LCFRCV_SteerWAngleRate_degps (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_SteerWAngleRate_degps() S_LCFRCV_SteerWAngleRate_degps //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_SteerWAngleRate_degps

#ifndef S_LCFRCV_SysCycleTimeVeh_sec
#define S_LCFRCV_SysCycleTimeVeh_sec (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_SysCycleTimeVeh_sec() S_LCFRCV_SysCycleTimeVeh_sec //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_SysCycleTimeVeh_sec

#ifndef S_LCFRCV_SysStOffLatDMC_bool
#define S_LCFRCV_SysStOffLatDMC_bool (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_SysStOffLatDMC_bool() S_LCFRCV_SysStOffLatDMC_bool //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_SysStOffLatDMC_bool

#ifndef S_LCFRCV_SysStReqLatDMC_bool
#define S_LCFRCV_SysStReqLatDMC_bool (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_SysStReqLatDMC_bool() S_LCFRCV_SysStReqLatDMC_bool //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_SysStReqLatDMC_bool

#ifndef S_LCFRCV_VehAclX_mps2
#define S_LCFRCV_VehAclX_mps2 (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_VehAclX_mps2() S_LCFRCV_VehAclX_mps2 //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_VehAclX_mps2

#ifndef S_LCFRCV_VehCrv_1pm
#define S_LCFRCV_VehCrv_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_VehCrv_1pm() S_LCFRCV_VehCrv_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_VehCrv_1pm

#ifndef S_LCFRCV_VehOdoState_nu
#define S_LCFRCV_VehOdoState_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_VehOdoState_nu() S_LCFRCV_VehOdoState_nu //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_VehOdoState_nu

#ifndef S_LCFRCV_VehSync4LCO_us
#define S_LCFRCV_VehSync4LCO_us (0x00000000u) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_VehSync4LCO_us() S_LCFRCV_VehSync4LCO_us //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_VehSync4LCO_us

#ifndef S_LCFRCV_VehVelX_mps
#define S_LCFRCV_VehVelX_mps (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_VehVelX_mps() S_LCFRCV_VehVelX_mps //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_VehVelX_mps

#ifndef S_LCFRCV_VehYawRate_rps
#define S_LCFRCV_VehYawRate_rps (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_LCFRCV_VehYawRate_rps() S_LCFRCV_VehYawRate_rps //!< LCFVEH stubbed input macro getter.
#endif // S_LCFRCV_VehYawRate_rps

#ifndef S_MCTLFC_ControllingFunction_nu
#define S_MCTLFC_ControllingFunction_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_MCTLFC_ControllingFunction_nu() S_MCTLFC_ControllingFunction_nu //!< LCFVEH stubbed input macro getter.
#endif // S_MCTLFC_ControllingFunction_nu

#ifndef S_TCTDEV_CrvTestSignal_1pm
#define S_TCTDEV_CrvTestSignal_1pm (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_TCTDEV_CrvTestSignal_1pm() S_TCTDEV_CrvTestSignal_1pm //!< LCFVEH stubbed input macro getter.
#endif // S_TCTDEV_CrvTestSignal_1pm

#ifndef S_TCTDEV_DeltaFCmdTestSignal_deg
#define S_TCTDEV_DeltaFCmdTestSignal_deg (0.f) //!< LCFVEH stubbed input macro.
#define GET_S_TCTDEV_DeltaFCmdTestSignal_deg() S_TCTDEV_DeltaFCmdTestSignal_deg //!< LCFVEH stubbed input macro getter.
#endif // S_TCTDEV_DeltaFCmdTestSignal_deg

#ifndef S_TJASTM_LatCtrlMode_nu
#define S_TJASTM_LatCtrlMode_nu (0x00u) //!< LCFVEH stubbed input macro.
#define GET_S_TJASTM_LatCtrlMode_nu() S_TJASTM_LatCtrlMode_nu //!< LCFVEH stubbed input macro getter.
#endif // S_TJASTM_LatCtrlMode_nu

#ifdef __cplusplus
}
#endif

#endif /* LCFVEH_DATA_H_ */
