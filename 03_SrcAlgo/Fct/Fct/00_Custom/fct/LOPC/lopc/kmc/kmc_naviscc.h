/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_naviscc.h

DESCRIPTION:               File containing NSCC custom functions for KMC in LOPC

AUTHOR:                    Thomas Mielke (uidq4510)

CREATION DATE:             05.12.2017

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.4

**************************************************************************** */
#ifndef _FCT_LONG_NAVISCC_H_
#define _FCT_LONG_NAVISCC_H_

#if KMC_CFG_HI_NAVI_FEATURE


#define p_Offset_Invalid 8191u
#define p_PROSHORT_Distance_Invalid 1023u
#define p_CyclicCounter_Invalid 4u
#define p_PROLONG_ProfileType_Invalid 0u
#define p_PROSHORT_ProfileType_Invalid 0u
#define p_PROSHORT_Value_Invalid 1023u
#define p_PROLONG_Value_Invalid 0xFFFFFFFF
#define p_NDP_CurLanes_Invalid 7u

#define NSCC_C_CURVE_ARRAY_SIZE 200u
#define NSCC_C_CURVE_ARRAY_SIZE_REDUCED 100u
#define NSCC_C_CURVE_ARRAY_SIZE_MEAS 40u
#define NSCC_C_CURVE_ARRAY_SIZE_MEAS_REDUCED 10u

typedef sint16 NSCC_CurveInfoListDist_array_t[NSCC_C_CURVE_ARRAY_SIZE];
typedef sint16 NSCC_CurveInfoListDistMEAS_array_t[NSCC_C_CURVE_ARRAY_SIZE_MEAS];
typedef sint16 NSCC_CurveInfoListR_array_t[NSCC_C_CURVE_ARRAY_SIZE];
typedef sint16 NSCC_CurveInfoListRMEAS_array_t[NSCC_C_CURVE_ARRAY_SIZE_MEAS];
typedef sint16 NSCC_CurveInfoListDistRed_array_t[NSCC_C_CURVE_ARRAY_SIZE_REDUCED];
typedef sint16 NSCC_CurveInfoListDistRedMEAS_array_t[NSCC_C_CURVE_ARRAY_SIZE_MEAS_REDUCED];
typedef sint16 NSCC_CurveInfoListRRed_array_t[NSCC_C_CURVE_ARRAY_SIZE_REDUCED];
typedef sint16 NSCC_CurveInfoListRRedMEAS_array_t[NSCC_C_CURVE_ARRAY_SIZE_MEAS_REDUCED];

typedef enum osc_mode_t {
  osc_off,
  osc_on,
  osc_standby,
  osc_control
} osc_mode_t;

typedef struct nscc_inputs_t {
  boolean OSC_USM_Status;
  nscc_roadclass_t NSCC_CurRoadClass;
  nscc_linkclass_t NSCC_CurLinkClass;
  OSC_SpotCamInfoList_Dist_array_t OSC_SpotCamInfoList_Dist;
  OSC_SpotCamInfoList_Type_array_t OSC_SpotCamInfoList_Type;
  OSC_SpotCamInfoList_array_t OSC_SpotCamInfoList_Spd;
  uint8 OSC_SpotCamInfoValidSize;
  NSCC_SegInfoList_Dist_array_t NSCC_SegInfoList_Dist;
  NSCC_SegInfoList_RC_array_t NSCC_SegInfoList_RoadClass;
  NSCC_SegInfoList_LC_array_t NSCC_SegInfoList_LinkClass;
  uint8 NSCC_SegInfoValidSize;
  boolean NSCC_DataReady;
  boolean NSCC_Inhibit;
  boolean NSCC_RouteInvalid;
  boolean NSCC_PosMsgUpdate;
  float32 DrivingDistFor1Cycle;
  float32 DrivingDistForPosMsgUpdate;
  float32 VehSpdCluCal;
  boolean NSCC_Buffer_Reset;
  boolean SOSC_DataReady;
  boolean OSC_SectCam_Valid;
  uint8 OSC_SectCam_Spd;
  float32 OSC_SectCam_AvgSpd;
  /* NaviSCC-C */
  boolean NSCC_Curve_USM_In;
  uint8 NDP_CurveInfoValidSize;
  uint8 NDP_CurveInfoValidSizeReal;
  uint8 NDP_CurveInfoValidSizeEndReal;
  NSCC_CurveInfoListDist_array_t NDP_CurveInfoListDist;
  NSCC_CurveInfoListDistRed_array_t NDP_CurveInfoListDistReal;
  NSCC_CurveInfoListDistRed_array_t NDP_CurveInfoListDistEndReal;
  NSCC_CurveInfoListR_array_t NDP_CurveInfoListR;
  NSCC_CurveInfoListRRed_array_t NDP_CurveInfoListRred;
  boolean PROLONG_Update; 
  uint16 PROLONG_Offset;
  uint8 PROLONG_CyclicCounter;
  uint8 PROLONG_ProfileType; 
  uint32 PROLONG_Value;
  uint16 PROSHORT_Offset;
  uint16 PROSHORT_Distance;
  uint16 PROSHORT_Value0;
  uint8 PROSHORT_CyclicCounter;
  uint8 PROSHORT_ProfileType;
  float32 DistBySysDelay;
  boolean NDP_BufferResetNSCC_C;
  uint8 CurSafeSpd;
  osc_mode_t NSCC_C_Mode;
  osc_mode_t NSCC_Z_Mode;
  boolean NSCC_C_SwCond;
  boolean NSCC_Z_SwCond;
  uint8 NDP_CurLanes;
} nscc_inputs_t;

typedef enum acc_mode_t{
  acc_mode_off,
  acc_mode_engaged,
  acc_mode_override,
  acc_mode_shutoff
} acc_mode_t;

typedef enum nscc_req_accel_mode_t {
  nscc_req_accel_mode_no_act,
  nscc_req_accel_mode_nscc_c,
  nscc_req_accel_mode_nscc_z,
  nscc_req_accel_mode_drvovr
} nscc_req_accel_mode_t;

typedef enum osc_req_accel_mode_t {
  osc_no_req_accel,
  osc_mosc_req_accel,
  osc_fosc_req_accel,
  osc_sosc_req_accel
} osc_req_accel_mode_t;

typedef struct nscc_measfreeze_data_t {
  osc_mode_t OSC_Mode_MEAS;
  sint16 OSC_TargetDist_MEAS;
  sint16 OSC_TargetSpd_MEAS;
  sint16 OSC_NearestSpotCam_Spd_MEAS;
  sint16 OSC_NearestSpotCam_Dist_MEAS;
  sint16 OSC_CurLmtSpd_MEAS;
  float32 OSC_TargetDistComp_MEAS;
  float32 SOSC_TargetSpd_MEAS;
  float32 SOSC_AvgSpd_MEAS;
  float32 SOSC_TargetSpdAvg_MEAS;
  float32 OSC_ReqAccel_PCtrl_MEAS;
  float32 OSC_ReqAccel_SCtrl_MEAS;
  boolean OSC_CtrlStrategyChgToPFlag_MEAS;
  float32 OSC_SpdEr_MEAS;
  float32 OSC_SpdGain_MEAS;
  float32 MOSC_SpdEr_MEAS;
  float32 MOSC_SpdGain_MEAS;
  float32 SOSC_SpdEr_MEAS;
  float32 SOSC_SpdGain_MEAS;
  boolean SOSC_Valid_MEAS;
  osc_req_accel_mode_t OSC_ReqAccelMode_MEAS;
  float32 OSC_ReqAccel_MEAS;
  /* NaviSCC-C */
  NSCC_CurveInfoListDistMEAS_array_t NDP_CurveInfoListDist_MEAS;
  NSCC_CurveInfoListRMEAS_array_t NDP_CurveInfoListR_MEAS;
  NSCC_CurveInfoListDistRedMEAS_array_t NDP_CurveInfoListDistReal_MEAS;
  NSCC_CurveInfoListDistRedMEAS_array_t NDP_CurveInfoListDistEndReal_MEAS;
  NSCC_CurveInfoListRRedMEAS_array_t NDP_CurveInfoListRred_MEAS;
  osc_mode_t NSCC_C_Mode_MEAS;
  float32 CurDesiredAy_MEAS;
  float32 NSCC_C_TargetDistComp_MEAS;
  float32 NSCC_C_ReqAccel_MEAS;
  float32 NSCC_C_ReqAccelLmt_MEAS;
  sint16 NSCC_C_DistOfInterestMax_MEAS;
  sint16 NSCC_C_DistOfInterestMaxOld_MEAS;
  sint16 NSCC_C_TargetR_MEAS;
  sint16 NSCC_C_TargetDist_MEAS;
  sint16 NSCC_C_TargetSpd_MEAS;
  sint16 CurRadius_MEAS;
  uint8 CurSafeSpd_MEAS;
  uint8 NDP_CurveInfoValidSize_MEAS;
  uint8 NDP_CurveInfoValidSizeReal_MEAS;
  uint8 NDP_CurveInfoValidSizeEndReal_MEAS;
  uint8 NSCC_C_TargetType_MEAS;
  boolean MainLinkCurve_flag_MEAS;
  boolean NSCC_C_SwCond_MEAS;
  boolean NSCC_C_RoadClassCond_MEAS;
  boolean NSCC_C_LinkClassCond_MEAS;
  boolean NSCC_C_SetSpdChg_MEAS;
} nscc_measfreeze_data_t;

void NSCC_EXEC(nscc_inputs_t * NSCCIn, acc_mode_t ACCMode, setspeed_t cc_setspeed, boolean CCOnlyActive, LongCtrlOutput_t * pLongCtrlCmd);

#endif

#endif /* KMC_CFG_HI_NAVI_FEATURE */
