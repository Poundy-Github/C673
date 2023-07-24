/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 SPM - Sensor Performance Monitoring

PACKAGENAME:               spm_par.h

DESCRIPTION:               SPM specific parameters defines

AUTHOR:                    $Author: Pallo, Istvan (palloi) $

CREATION DATE:             $Date: 2020/06/23 12:50:33CEST $

VERSION:                   $Revision: 1.5 $

  ---*/ /*---
  CHANGES:                $Log: spm_par.h  $
  CHANGES:                Revision 1.5 2020/06/23 12:50:33CEST Pallo, Istvan (palloi) 
  CHANGES:                Update config swithces for SPM Split - SRR
  CHANGES:                Revision 1.4 2018/09/24 14:27:14CEST Pallo, Istvan (palloi) 
  CHANGES:                Add parameters for SRR
  CHANGES:                Revision 1.3 2018/03/20 14:58:08CET Pallo, Istvan (palloi) 
  CHANGES:                New define for input acceptable drops
  CHANGES:                Revision 1.2 2018/02/23 14:50:37CET Pallo, Istvan (palloi) 
  CHANGES:                Add new SPM parameter for time conversion to microseconds
  CHANGES:                Revision 1.1 2017/03/17 13:16:31CET Kober, Manfred (uidv8885) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/00_Projects/ARS510/SPM/project.pj

**************************************************************************** */
#ifndef SPM_PAR_H_INCLUDED
#define SPM_PAR_H_INCLUDED

#include "spm.h"


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if(FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)
  /******************************************/
  /*! Parameter declaration for application */
  /******************************************/
  
  /* SPM velocity thresholds */
  #define SPM_SPEED_MIN                             SPM_SPEED_MIN_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SPEED_MIN_c)
  #define SPM_SPEED_MAX                             SPM_SPEED_MAX_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SPEED_MAX_c)
  
  /* Roadbeam parameters */
  #define SPM_ROADBEAM_DURATION                     SPM_ROADBEAM_DURATION_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_ROADBEAM_DURATION_c)
  #define SPM_ROADBEAM_DELAY_FOR_REACTIVATION       SPM_ROADBEAM_DELAY_FOR_REACTIVATION_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_ROADBEAM_DELAY_FOR_REACTIVATION_c)
  #define SPM_SELFTEST_ROADBEAM_VISIBILITY          SPM_SELFTEST_ROADBEAM_VISIBILITY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint8,                        SPM_SELFTEST_ROADBEAM_VISIBILITY_c)
  #define SPM_ROADBEAM_VISIBILITY_STRONG_THRESH          SPM_ROADBEAM_VISIBILITY_STRONG_THRESH_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint8,                        SPM_ROADBEAM_VISIBILITY_STRONG_THRESH_c)
  #define SPM_SELFTEST_ROADBEAM_QUALITY             SPM_SELFTEST_ROADBEAM_QUALITY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint8,                        SPM_SELFTEST_ROADBEAM_QUALITY_c)
  #define SPM_ROADBEAM_QUALITY_STRONG_THRESH             SPM_ROADBEAM_QUALITY_STRONG_THRESH_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint8,                        SPM_ROADBEAM_QUALITY_STRONG_THRESH_c)
                                              
  #define SPM_BLOCKAGE_ROADBEAM_VISIBILITY          SPM_BLOCKAGE_ROADBEAM_VISIBILITY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF sint32,                        SPM_BLOCKAGE_ROADBEAM_VISIBILITY_c)
                                              
  #define SPM_BLOCKAGE_ROADBEAM_QUALITY             SPM_BLOCKAGE_ROADBEAM_QUALITY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF sint32,                        SPM_BLOCKAGE_ROADBEAM_QUALITY_c)
  
  /* Selftest parameters */
  #define SPM_TMAX_UNTIL_OBJ                        SPM_TMAX_UNTIL_OBJ_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_TMAX_UNTIL_OBJ_c)
  #define SPM_SPEED_MIN_SELFTEST                    SPM_SPEED_MIN_SELFTEST_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SPEED_MIN_SELFTEST_c)
  #define SPM_SELFTEST_RANGE_MIN                    SPM_SELFTEST_RANGE_MIN_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SELFTEST_RANGE_MIN_c)
  #define SPM_SELFTEST_CONFIDENCE_MIN               SPM_SELFTEST_CONFIDENCE_MIN_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SELFTEST_CONFIDENCE_MIN_c)
  #define SPM_SELFTEST_REACTIVATION_RANGE           SPM_SELFTEST_REACTIVATION_RANGE_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SELFTEST_REACTIVATION_RANGE_c)
  #define SPM_SELFTEST_REACTIVATION_CONF            SPM_SELFTEST_REACTIVATION_CONF_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SELFTEST_REACTIVATION_CONF_c)
  
  /* Interference parameters */
  #define SPM_INTERFERENCE_RANGE_DIST_MIN           SPM_INTERFERENC_RANGE_DIST_MIN_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_INTERFERENC_RANGE_DIST_MIN_c)
  #define SPM_INTERFERENCE_RANGE_DIST_MAX           SPM_INTERFERENC_RANGE_DIST_MAX_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_INTERFERENC_RANGE_DIST_MAX_c)
  #define SPM_INTERFERENC_RANGE_TIME_DIST           SPM_INTERFERENC_RANGE_TIME_DIST_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_INTERFERENC_RANGE_TIME_DIST_c)
  #define SPM_INTERFERENCE_RANGE_HOLD               SPM_INTERFERENCE_RANGE_HOLD_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint32,                        SPM_INTERFERENCE_RANGE_HOLD_c)
  
  /* Common parameters */
  #define SPM_BLOCKAGE_REACTIVATION_DELAY           SPM_BLOCKAGE_REACTIVATION_DELAY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLOCKAGE_REACTIVATION_DELAY_c)
  
  /* Blockage parameters */
  #define SPM_RANGE_HOLD_COUNTER_THLD               SPM_RANGE_HOLD_COUNTER_THLD_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_RANGE_HOLD_COUNTER_THLD_c)
  #define SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR                SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR_c)
  #define SPM_BLOCKAGE_SHUTOFF_RANGE_FAR                SPM_BLOCKAGE_SHUTOFF_RANGE_FAR_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         SPM_BLOCKAGE_SHUTOFF_RANGE_FAR_c)
  #define SPM_STATE_CONF_MIN                        SPM_STATE_CONF_MIN_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_STATE_CONF_MIN_c)
  #define SPM_BLOCKAGE_SHUTON_RANGE_NEAR                   SPM_BLOCKAGE_SHUTON_RANGE_NEAR_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         SPM_BLOCKAGE_SHUTON_RANGE_NEAR_c)
  #define SPM_BLOCKAGE_SHUTON_RANGE_FAR                   SPM_BLOCKAGE_SHUTON_RANGE_FAR_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         SPM_BLOCKAGE_SHUTON_RANGE_FAR_c)
  #define SPM_BLOCKAGE_RANGE_WEIGHT                 SPM_BLOCKAGE_RANGE_WEIGHT_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLOCKAGE_RANGE_WEIGHT_c)
  #define SPM_BLOCKAGE_SHUTOFF_TIME                 SPM_BLOCKAGE_SHUTOFF_TIME_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint32,                        SPM_BLOCKAGE_SHUTOFF_TIME_c)
  #define SPM_BLOCKAGE_SHUTOFF_WAY                  SPM_BLOCKAGE_SHUTOFF_WAY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint32,                        SPM_BLOCKAGE_SHUTOFF_WAY_c)
  #define SPM_BLOCKAGE_TIMEOUT_WEIGHT               SPM_BLOCKAGE_TIMEOUT_WEIGHT_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLOCKAGE_TIMEOUT_WEIGHT_c)
  #define SPM_BLOCKAGE_OBJLOSS_WEIGHT               SPM_BLOCKAGE_OBJLOSS_WEIGHT_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLOCKAGE_OBJLOSS_WEIGHT_c)
  #define SPM_BLK_A_OUTPUT_FILTER_FAST              SPM_BLK_A_OUTPUT_FILTER_FAST_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLK_A_OUTPUT_FILTER_FAST_c)
  #define SPM_BLK_A_OUTPUT_FILTER_SLOW              SPM_BLK_A_OUTPUT_FILTER_SLOW_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLK_A_OUTPUT_FILTER_SLOW_c)
  #define SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB           SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c)
  #define SPM_BLOCKAGE_SRD_REACTIVATION_DELAY       SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c)
  #define SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY          SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                       SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c)
  #define SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP      SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint8,                         SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c)
  #define SPM_ENABLE_BLOCKAGE                       SPM_ENABLE_BLOCKAGE_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF boolean,                       SPM_ENABLE_BLOCKAGE_c)
  #define SPM_ENABLE_SELFTEST                       SPM_ENABLE_SELFTEST_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF boolean,                       SPM_ENABLE_SELFTEST_c)
  #define SPM_OBJLOSS_MINRELOBJ_TIMER               SPM_OBJLOSS_MINRELOBJ_TIMER_c
  FCT_DECL_FIX_PARAM(MEMSEC_REF uint8,                         SPM_OBJLOSS_MINRELOBJ_TIMER_c)
  
  #define SPM_TIMESTAMP_TO_MICROSECONDS                   1000000.0f
  
  #define SPM_INPUT_ACCEPTABLE_DROPS                      1U
#endif
#else
  /* SPM velocity thresholds */
#define SPM_SPEED_MIN                             SPM_SPEED_MIN_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SPEED_MIN_c)

#define SPM_SPEED_MAX                             SPM_SPEED_MAX_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SPEED_MAX_c)

#define SPM_SPEED_MIN_OBJ_LOSS                    SPM_SPEED_MIN_OBJ_LOSS_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SPEED_MIN_OBJ_LOSS_c)

/* Selftest parameters */
#define SPM_TMAX_UNTIL_OBJ                        SPM_TMAX_UNTIL_OBJ_c
FCT_DECL_FIX_PARAM(float32,                        SPM_TMAX_UNTIL_OBJ_c)

#define SPM_SPEED_MIN_SELFTEST                    SPM_SPEED_MIN_SELFTEST_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SPEED_MIN_SELFTEST_c)

#define SPM_SELFTEST_RANGE_MIN                    SPM_SELFTEST_RANGE_MIN_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SELFTEST_RANGE_MIN_c)

#define SPM_SELFTEST_CONFIDENCE_MIN               SPM_SELFTEST_CONFIDENCE_MIN_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SELFTEST_CONFIDENCE_MIN_c)

#define SPM_SELFTEST_REACTIVATION_RANGE           SPM_SELFTEST_REACTIVATION_RANGE_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SELFTEST_REACTIVATION_RANGE_c)

#define SPM_SELFTEST_REACTIVATION_CONF            SPM_SELFTEST_REACTIVATION_CONF_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SELFTEST_REACTIVATION_CONF_c)

/* Interference parameters */
#define SPM_INTERFERENCE_RANGE_DIST_MIN           SPM_INTERFERENC_RANGE_DIST_MIN_c
FCT_DECL_FIX_PARAM(float32,                        SPM_INTERFERENC_RANGE_DIST_MIN_c)

#define SPM_INTERFERENCE_RANGE_DIST_MAX           SPM_INTERFERENC_RANGE_DIST_MAX_c
FCT_DECL_FIX_PARAM(float32,                        SPM_INTERFERENC_RANGE_DIST_MAX_c)

#define SPM_INTERFERENC_RANGE_TIME_DIST           SPM_INTERFERENC_RANGE_TIME_DIST_c
FCT_DECL_FIX_PARAM(float32,                        SPM_INTERFERENC_RANGE_TIME_DIST_c)

#define SPM_INTERFERENCE_RANGE_HOLD               SPM_INTERFERENCE_RANGE_HOLD_c
FCT_DECL_FIX_PARAM(uint32,                         SPM_INTERFERENCE_RANGE_HOLD_c)

/* Common parameters */
#define SPM_VELOCITY_ACC_MAX_VARIANCE             SPM_VELOCITY_ACC_MAX_VARIANCE_c
FCT_DECL_FIX_PARAM(float32,                        SPM_VELOCITY_ACC_MAX_VARIANCE_c)

#define SPM_YAWRATE_ACC_MAX_VARIANCE              SPM_YAWRATE_ACC_MAX_VARIANCE_c
FCT_DECL_FIX_PARAM(float32,                        SPM_YAWRATE_ACC_MAX_VARIANCE_c)

#define SPM_YAWRATE_ACC_MIN_VELOCITY              SPM_YAWRATE_ACC_MIN_VELOCITY_c
FCT_DECL_FIX_PARAM(float32,                        SPM_YAWRATE_ACC_MIN_VELOCITY_c)

#define SPM_LATERAL_POS_ADD_SPEED_FAILURE         SPM_LATERAL_POS_ADD_SPEED_FAILURE_c
FCT_DECL_FIX_PARAM(float32,                        SPM_LATERAL_POS_ADD_SPEED_FAILURE_c)

#define SPM_BLOCKAGE_REACTIVATION_DELAY           SPM_BLOCKAGE_REACTIVATION_DELAY_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BLOCKAGE_REACTIVATION_DELAY_c)

/* Blockage parameters */
#define SPM_BSD_RANGE_HOLD_COUNTER_THLD           SPM_BSD_RANGE_HOLD_COUNTER_THLD_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BSD_RANGE_HOLD_COUNTER_THLD_c)

#define SPM_LCA_RANGE_HOLD_COUNTER_THLD           SPM_LCA_RANGE_HOLD_COUNTER_THLD_c
FCT_DECL_FIX_PARAM(float32,                        SPM_LCA_RANGE_HOLD_COUNTER_THLD_c)

#define SPM_BLOCKAGE_SHUTOFF_BSD_RANGE            SPM_BLOCKAGE_SHUTOFF_BSD_RANGE_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_BLOCKAGE_SHUTOFF_BSD_RANGE_c)

#define SPM_BLOCKAGE_SHUTOFF_LCA_RANGE            SPM_BLOCKAGE_SHUTOFF_LCA_RANGE_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_BLOCKAGE_SHUTOFF_LCA_RANGE_c)

#define SPM_BLOCKAGE_INC_BSD_RANGE            SPM_BLOCKAGE_INC_BSD_RANGE_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_BLOCKAGE_INC_BSD_RANGE_c)

#define SPM_BLOCKAGE_INC_LCA_RANGE            SPM_BLOCKAGE_INC_LCA_RANGE_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_BLOCKAGE_INC_LCA_RANGE_c)

#define SPM_STATE_CONF_MIN                        SPM_STATE_CONF_MIN_c
FCT_DECL_FIX_PARAM(float32,                        SPM_STATE_CONF_MIN_c)

#define SPM_RANGE_CONF_INC_BLOCKANGE_MIN          SPM_RANGE_CONF_INC_BLOCKANGE_MIN_c
FCT_DECL_FIX_PARAM(float32,                        SPM_RANGE_CONF_INC_BLOCKANGE_MIN_c)

#define SPM_BLOCKAGE_FULL_BSD_RANGE               SPM_BLOCKAGE_FULL_BSD_RANGE_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_BLOCKAGE_FULL_BSD_RANGE_c)

#define SPM_BLOCKAGE_FULL_LCA_RANGE               SPM_BLOCKAGE_FULL_LCA_RANGE_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_BLOCKAGE_FULL_LCA_RANGE_c)

#define SPM_BLOCKAGE_RANGE_WEIGHT                 SPM_BLOCKAGE_RANGE_WEIGHT_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BLOCKAGE_RANGE_WEIGHT_c)

#define SPM_BLOCKAGE_SHUTOFF_TIME                 SPM_BLOCKAGE_SHUTOFF_TIME_c
FCT_DECL_FIX_PARAM(uint32,                         SPM_BLOCKAGE_SHUTOFF_TIME_c)

#define SPM_BLOCKAGE_SHUTOFF_WAY                  SPM_BLOCKAGE_SHUTOFF_WAY_c
FCT_DECL_FIX_PARAM(uint32,                         SPM_BLOCKAGE_SHUTOFF_WAY_c)

#define SPM_BLOCKAGE_TIMEOUT_WEIGHT               SPM_BLOCKAGE_TIMEOUT_WEIGHT_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BLOCKAGE_TIMEOUT_WEIGHT_c)

#define SPM_BLOCKAGE_OBJLOSS_WEIGHT               SPM_BLOCKAGE_OBJLOSS_WEIGHT_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BLOCKAGE_OBJLOSS_WEIGHT_c)

#define SPM_BLK_A_OUTPUT_FILTER_FAST               SPM_BLK_A_OUTPUT_FILTER_FAST_c
FCT_DECL_FIX_PARAM(float32,                         SPM_BLK_A_OUTPUT_FILTER_FAST_c)

#define SPM_BLK_A_OUTPUT_FILTER_SLOW               SPM_BLK_A_OUTPUT_FILTER_SLOW_c
FCT_DECL_FIX_PARAM(float32,                         SPM_BLK_A_OUTPUT_FILTER_SLOW_c)

#define SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB           SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c)

#define SPM_BLOCKAGE_SRD_REACTIVATION_DELAY       SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c
FCT_DECL_FIX_PARAM(float32,                        SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c)

#define SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY          SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c
FCT_DECL_FIX_PARAM(float32,                        SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c)

#define SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP      SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c)

#define SPM_ENABLE_BLOCKAGE                       SPM_ENABLE_BLOCKAGE_c
FCT_DECL_FIX_PARAM(boolean,                        SPM_ENABLE_BLOCKAGE_c)

#define SPM_ENABLE_SELFTEST                       SPM_ENABLE_SELFTEST_c
FCT_DECL_FIX_PARAM(boolean,                        SPM_ENABLE_SELFTEST_c)

#define DEBOUNCETIME                              DEBOUNCETIME_c
FCT_DECL_FIX_PARAM(float32,                        DEBOUNCETIME_c)

#define SPM_ACTIVATION_THRESHOLD_AZIMUTH          SPM_ACTIVATION_THRESHOLD_AZIMUTH_c
FCT_DECL_FIX_PARAM(float32,                        SPM_ACTIVATION_THRESHOLD_AZIMUTH_c)

#define SPM_DEACTIVATION_THRESHOLD_AZIMUTH        SPM_DEACTIVATION_THRESHOLD_AZIMUTH_c
FCT_DECL_FIX_PARAM(float32,                        SPM_DEACTIVATION_THRESHOLD_AZIMUTH_c)

#define UNKNOWN_MISALIGNMENT_NOT_SAFE             UNKNOWN_MISALIGNMENT_NOT_SAFE_c
FCT_DECL_FIX_PARAM(boolean,                        UNKNOWN_MISALIGNMENT_NOT_SAFE_c)

#define SPM_OBJLOSS_MINRELOBJ_TIMER               SPM_OBJLOSS_MINRELOBJ_TIMER_c
FCT_DECL_FIX_PARAM(uint8,                          SPM_OBJLOSS_MINRELOBJ_TIMER_c)
#endif


#endif /* SPM_PAR_H_INCLUDED */
