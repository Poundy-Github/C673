/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 SPM - Sensor Performance Monitoring

PACKAGENAME:               spm_par.c

DESCRIPTION:               SPM specific parameters

AUTHOR:                    $Author: Motocu, Alexandru Marian02 (MotocuA02) $

CREATION DATE:             $Date: 2021/01/14 15:17:25CET $

VERSION:                   $Revision: 1.10 $

  ---*/ /*---
  CHANGES:                $Log: spm_par.c  $
  CHANGES:                Revision 1.10 2021/01/14 15:17:25CET Motocu, Alexandru Marian02 (MotocuA02) 
  CHANGES:                Set SPM_ENABLE_SELFTEST to ON
  CHANGES:                Revision 1.9 2020/11/02 16:13:36CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                For ARS projects add config switch when selftest threshold are set
  CHANGES:                Revision 1.8 2020/06/23 12:51:03CEST Pallo, Istvan (palloi) 
  CHANGES:                Update config switches for SPM Split - SRR
  CHANGES:                Revision 1.7 2020/01/07 09:04:09CET Motocu, Alexandru Marian02 (MotocuA02) 
  CHANGES:                Change SPM_INTERFERENC_RANGE_DIST_MAX_c parameter from 140.0 to 60.0 for SRR
  CHANGES:                Revision 1.6 2019/12/04 13:53:47CET Popescu, Dumitru-Cristian (uic23266) (uic23266) 
  CHANGES:                Update Blockage Shutoff Thld (55m) and ShutOn Thld (70m) according to Honda-san CR
  CHANGES:                Revision 1.5 2018/12/03 13:33:59CET Motocu, Alexandru Marian02 (MotocuA02) 
  CHANGES:                Update Blockage thresholds
  CHANGES:                Revision 1.4 2018/09/24 14:26:44CEST Pallo, Istvan (palloi) 
  CHANGES:                Add parameters for SRR
  CHANGES:                Revision 1.3 2018/03/28 09:23:09CEST Pallo, Istvan (palloi) 
  CHANGES:                Correct consideration of interference max range threshold based on sensor type
  CHANGES:                Revision 1.2 2017/07/27 12:22:46CEST Pallo, Istvan (palloi) 
  CHANGES:                Code alignment changes
  CHANGES:                Revision 1.1 2017/03/17 13:16:30CET Kober, Manfred (uidv8885) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/00_Projects/ARS510/SPM/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_par.h"


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*! @CompParamGroup TPSPMParam "TP SPM Parameter" */
/*@StartParamGroup*/

/***********************/
/* Velocity thresholds */
/***********************/
/*! @brief       Minimum speed for blockage state determination 
    @general     s. brief
    @conseq      @incp   availability of system will decrease
                 @decp   will not work properly
    @attention   systems power reduction mode can affect performance of 
                 blockage detection  
    @typical     10kph    @unit  [m/s]   @min 0 @max 30/C_KMH_MS   */

#if(SPM_USE_STOPNGO_BLOCKAGE == SWITCH_ON)
  SET_MEMSEC_CONST(SPM_SPEED_MIN_c )
  FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_c ,   0.5F/C_KMH_MS)
#else
  SET_MEMSEC_CONST(SPM_SPEED_MIN_c )
  FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_c ,   10.0F/C_KMH_MS )
#endif

/*! @brief       Maximum speed for blockage state determination 
    @general     s. brief
    @conseq      @incp   availability of system will increase
                 @decp   availability of system will decrease
    @attention   too high speed will cause sideeffects in range statistic, objects will pass too fast 
    @typical     200kph    @unit  [m/s]   @min 120/C_KMH_MS   @max 250/C_KMH_MS   */

SET_MEMSEC_CONST(SPM_SPEED_MAX_c )
FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MAX_c ,   200.0F/C_KMH_MS )

/***********************/
/* Roadbeam parameters */
/***********************/
/*! @brief       Duration of Roadbeam activity
    @general     s. brief
    @conseq      @incp   chance of finding the street will increase
                 @decp   blockage crtiteria will not be available during activity
    @attention   -
    @typical     30s    @unit  [s]   @min 5   @max 60   */

SET_MEMSEC_CONST(SPM_ROADBEAM_DURATION_c )
FCT_DEF_FIX_PARAM( float32 , SPM_ROADBEAM_DURATION_c ,   30.0F )

/*! @brief       Passed time before Roadbeam will be activated after blockage detection
    @general     s. brief
    @conseq      @incp   chance of available system increases without roadbeam activation
                 @decp   faster activation of roadbeam when system is unavailable
    @attention   can completely replaced by SPM_TMAX_UNTIL_OBJ !!!
    @typical     120s    @unit  [s]   @min 30   @max 240   */

SET_MEMSEC_CONST(SPM_ROADBEAM_DELAY_FOR_REACTIVATION_c )
FCT_DEF_FIX_PARAM( float32 , SPM_ROADBEAM_DELAY_FOR_REACTIVATION_c ,   120.0F )

/*! @brief       Minimum road visibility for successful roadbeam test during selftest
    @general     s. brief
    @conseq      @incp   chance for successful roadbeam test decreases
                 @decp   chance for successful roadbeam test increases
    @attention   road visibility must not be too low, blockage may be present
    @typical     70%    @unit  [%]   @min 50   @max 100   */

SET_MEMSEC_CONST(SPM_SELFTEST_ROADBEAM_VISIBILITY_c )
FCT_DEF_FIX_PARAM( uint8 , SPM_SELFTEST_ROADBEAM_VISIBILITY_c ,   60U )

/*! @brief       Minimum road visibility for successful roadbeam  strong test during selftest and blockage 
    @general     s. brief
    @conseq      @incp   chance for successful roadbeam test decreases
                 @decp   chance for successful roadbeam test increases
    @attention   road visibility must not be too low, blockage may be present
    @typical     80%    @unit  [%]   @min 50   @max 100   */

SET_MEMSEC_CONST(SPM_ROADBEAM_VISIBILITY_STRONG_THRESH_c )
FCT_DEF_FIX_PARAM( uint8 , SPM_ROADBEAM_VISIBILITY_STRONG_THRESH_c,   80U )


/*! @brief       Minimum road quality for successful roadbeam test during selftest
    @general     s. brief
    @conseq      @incp   chance for successful roadbeam test decreases
                 @decp   chance for successful roadbeam test increases
    @attention   road quality must not be too low, result may be a wrong visibility
    @typical     95%    @unit  [%]   @min 70   @max 100   */

SET_MEMSEC_CONST(SPM_SELFTEST_ROADBEAM_QUALITY_c )
FCT_DEF_FIX_PARAM( uint8 , SPM_SELFTEST_ROADBEAM_QUALITY_c ,   30U )

/*! @brief       Minimum road quality for successful roadbeam  strong test during selftest and blockage
    @general     s. brief
    @conseq      @incp   chance for successful roadbeam test decreases
                 @decp   chance for successful roadbeam test increases
    @attention   road quality must not be too low, result may be a wrong visibility
    @typical     95%    @unit  [%]   @min 70   @max 100   */

SET_MEMSEC_CONST(SPM_ROADBEAM_QUALITY_STRONG_THRESH_c )
FCT_DEF_FIX_PARAM( uint8 , SPM_ROADBEAM_QUALITY_STRONG_THRESH_c ,   40U )

/*! @brief       Minimum road visibility for successful roadbeam test during FULL_DAMP
    @general     s. brief
    @conseq      @incp   chance for successful roadbeam test decreases
                 @decp   chance for successful roadbeam test increases
    @attention   road visibility must not be too low, blockage may be present
    @typical     85%    @unit  [%]   @min 50   @max 100   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_ROADBEAM_VISIBILITY_c )
FCT_DEF_FIX_PARAM( sint32 , SPM_BLOCKAGE_ROADBEAM_VISIBILITY_c ,   70L )

/*! @brief       Minimum road quality for successful roadbeam test during FULL_DAMP
    @general     s. brief
    @conseq      @incp   chance for successful roadbeam test decreases
                 @decp   chance for successful roadbeam test increases
    @attention   road quality must not be too low, result may be a wrong visibility
    @typical     100%    @unit  [%]   @min 70   @max 100   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_ROADBEAM_QUALITY_c )
FCT_DEF_FIX_PARAM( sint32 , SPM_BLOCKAGE_ROADBEAM_QUALITY_c ,   100L )

/***********************/
/* Selftest parameters */
/***********************/
/*! @brief       complete selftest cycle with statistical analysis and roadbeam test
    @general     s. brief
    @conseq      @incp   faster change between statistical analysis and roadbeam
                 @decp   slower change between statistical analysis and roadbeam
    @attention   -
    @typical     120s    @unit  [s]   @min 30   @max 240   */

#if(SPM_USE_ONEMIN_SELFTEST_TIME_THLD == SWITCH_OFF)
  #if(SPM_USE_DIFF_SELFTEST_TIME_THRES == SWITCH_OFF)
    SET_MEMSEC_CONST(SPM_TMAX_UNTIL_OBJ_c )
    FCT_DEF_FIX_PARAM( float32 , SPM_TMAX_UNTIL_OBJ_c ,  120.0F)
  #else
    SET_MEMSEC_CONST(SPM_TMAX_UNTIL_OBJ_c )
    FCT_DEF_FIX_PARAM( float32 , SPM_TMAX_UNTIL_OBJ_c ,  45.0F)
  #endif
#else
SET_MEMSEC_CONST(SPM_TMAX_UNTIL_OBJ_c )
FCT_DEF_FIX_PARAM( float32 , SPM_TMAX_UNTIL_OBJ_c ,  60.0F)
#endif

/*! @brief       Minimum speed for activation of selftest
    @general     s. brief
    @conseq      @incp   selftest will start later
                 @decp   selftest will start earlier
    @attention   systems power reduction mode can affect the results of the selftest 
    @typical     10kph    @unit  [kph]   @min 0   @max 30   */

#if(SPM_USE_STOPNGO_SELFTEST == SWITCH_ON)
  #if(SPM_USE_SELFTEST_STANDSTILL == SWITCH_ON)
    SET_MEMSEC_CONST(SPM_SPEED_MIN_SELFTEST_c )
    FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_SELFTEST_c ,   (0.0F) )
  #else 
    SET_MEMSEC_CONST(SPM_SPEED_MIN_SELFTEST_c )
    FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_SELFTEST_c ,   (0.5F/C_KMH_MS) )
  #endif
#else
  SET_MEMSEC_CONST(SPM_SPEED_MIN_SELFTEST_c )
  FCT_DEF_FIX_PARAM( float32, SPM_SPEED_MIN_SELFTEST_c , (10.0F/C_KMH_MS) )
#endif

/*! @brief       Minimum range for successful selftest
    @general     s. brief
    @conseq      @incp   availability of the system will decrease
                 @decp   availability of the system will increase
    @attention   -
    @typical     100m    @unit  [m]   @min 50   @max 150   */

SET_MEMSEC_CONST(SPM_SELFTEST_RANGE_MIN_c )
FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_RANGE_MIN_c ,   100.0F )

/*! @brief       Minimum range confidence for successful selftest
    @general     s. brief
    @conseq      @incp   availability of the system will decrease
                 @decp   availability of the system will increase
    @attention   -
    @typical     0.05    @unit  -   @min 0.01   @max 0.5   */

SET_MEMSEC_CONST(SPM_SELFTEST_CONFIDENCE_MIN_c )
FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_CONFIDENCE_MIN_c ,   0.05F )

/*! @brief       Minimum range for reactivation after failed selftest
    @general     s. brief
    @conseq      @incp   availability of the system will decrease
                 @decp   availability of the system will increase
    @attention   -
    @typical     140m    @unit  [m]   @min 100   @max 160   */

SET_MEMSEC_CONST(SPM_SELFTEST_REACTIVATION_RANGE_c )
FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_REACTIVATION_RANGE_c ,   140.0F )

/*! @brief       Minimum range confidence for reactivation after failed selftest
    @general     s. brief
    @conseq      @incp   availability of the system will decrease
                 @decp   availability of the system will increase
    @attention   -
    @typical     0.4    @unit  -   @min 0.1   @max 0.8   */

SET_MEMSEC_CONST(SPM_SELFTEST_REACTIVATION_CONF_c )
FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_REACTIVATION_CONF_c ,   0.4F )

/***************************/
/* Interference parameters */
/***************************/
/*! @brief       ?
    @general     s. brief
    @conseq      @incp   ?
                 @decp   ?
    @attention   ?
    @typical     15m    @unit  [m]   @min tbd   @max tbd   */

SET_MEMSEC_CONST(SPM_INTERFERENC_RANGE_DIST_MIN_c )
FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_DIST_MIN_c ,   15.0F )

/*! @brief       ?
    @general     s. brief
    @conseq      @incp   ?
                 @decp   ?
    @attention   ?
    @typical     140m    @unit  [m]   @min tbd   @max tbd   */
#if(SYS_NUM_OF_SCANS > 1U)
SET_MEMSEC_CONST(SPM_INTERFERENC_RANGE_DIST_MAX_c )
FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_DIST_MAX_c ,   140.0F )
#else
SET_MEMSEC_CONST(SPM_INTERFERENC_RANGE_DIST_MAX_c )
FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_DIST_MAX_c ,   80.0F )
#endif

/*! @brief       Interference range time, Used in generating the interference range threshold.
    @general     s. brief
    @conseq      @incp   -
                 @decp   -
    @attention   -
    @typical     3.6    @unit  [s]   @min tbd   @max tbd   */

SET_MEMSEC_CONST(SPM_INTERFERENC_RANGE_TIME_DIST_c )
FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_TIME_DIST_c ,   3.6F )

/*! @brief       Interference range hold count.
    @general     s. brief
    @conseq      @incp   -
                 @decp   -
    @attention   ?
    @typical     100    @unit  -   @min tbd   @max tbd   */

SET_MEMSEC_CONST(SPM_INTERFERENCE_RANGE_HOLD_c )
FCT_DEF_FIX_PARAM( uint32 , SPM_INTERFERENCE_RANGE_HOLD_c ,   100u )

/*********************/
/* Common parameters */
/*********************/
/*! @brief       Time the system remains in full damping before checking the situation again
    @general     s. brief
    @conseq      @incp   time the system remains in full damp mode increases
                 @decp   time the system remains in full damp mode decreases
    @attention   value must not be 0!
    @typical     120s    @unit  [s]   @min 0.001   @max 300   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_REACTIVATION_DELAY_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_REACTIVATION_DELAY_c ,   120.0F )

/************************/
/* Blockage parameters  */
/************************/
/*! @brief       If range drops below deactivation threshold this time delays blockage
    @general     s. brief
    @conseq      @incp   blockage is reported later
                 @decp   blockage is reported earlier
    @attention   -
    @typical     0    @unit  [s]   @min 0   @max 600   */

SET_MEMSEC_CONST(SPM_RANGE_HOLD_COUNTER_THLD_c )
FCT_DEF_FIX_PARAM(float32, SPM_RANGE_HOLD_COUNTER_THLD_c ,   0.0F)

/*! @brief       Minimum confidence needed to change blockage state
    @general     s. brief
    @conseq      @incp   blockage is reported with lower uncertainty
                 @decp   blockage is reported with higher uncertainty
    @attention   -
    @typical     0.4    @unit  -   @min 0.2   @max 0.6   */

SET_MEMSEC_CONST(SPM_STATE_CONF_MIN_c )
FCT_DEF_FIX_PARAM(float32, SPM_STATE_CONF_MIN_c ,    0.4F)

/*! @brief       Range at which the algo reports blockage
    @general     s. brief
    @conseq      @incp   availability of the system increases
                 @decp   availability of the system decreases
    @attention   -
    @typical     71.25m    @unit  [m]   @min 60   @max 100   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTOFF_RANGE_FAR_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SHUTOFF_RANGE_FAR_c ,   180.0F)
/*! @brief       Range at which the algo reports blockage
    @general     s. brief
    @conseq      @incp   availability of the system increases
                 @decp   availability of the system decreases
    @attention   -
    @typical     71.25m    @unit  [m]   @min 60   @max 100   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR_c ,   80.0F)

/*! @brief       Range at which the corresponding blockage probability is 0%
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     140m    @unit  [m]   @min 120   @max 180   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTON_RANGE_FAR_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SHUTON_RANGE_FAR_c ,   250.0F )
/*! @brief       Range at which the corresponding blockage probability is 0%
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     140m    @unit  [m]   @min 120   @max 180   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTON_RANGE_NEAR_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SHUTON_RANGE_NEAR_c ,   130.0F )

/*! @brief       Influence of range criterion for blockage probability 
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     1    @unit  -   @min 0   @max 1   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_RANGE_WEIGHT_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_RANGE_WEIGHT_c ,   1.0F )

/*! @brief       Passed time without valid object at which the algo reports blockage
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     60s    @unit  [s]   @min 30   @max 120   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTOFF_TIME_c )
FCT_DEF_FIX_PARAM( uint32 , SPM_BLOCKAGE_SHUTOFF_TIME_c ,   60UL )

/*! @brief       Driven distance without valid object at which the algo reports blockage
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     2000m    @unit  [m]   @min 1000   @max 5000   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTOFF_WAY_c )
FCT_DEF_FIX_PARAM( uint32 , SPM_BLOCKAGE_SHUTOFF_WAY_c ,   2000UL )

/*! @brief       Influence of timeout criterion for blockage probability 
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     1    @unit  -   @min 0   @max 1   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_TIMEOUT_WEIGHT_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_TIMEOUT_WEIGHT_c ,   1.0F )

/*! @brief       Influence of object loss criterion for blockage probability 
    @general     s. brief
    @conseq      @incp   availability of the system decreases
                 @decp   availability of the system increases
    @attention   -
    @typical     1    @unit  -   @min 0   @max 1   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_OBJLOSS_WEIGHT_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_OBJLOSS_WEIGHT_c ,   1.0F )

/*! @brief       Alpha value for fast output filtering
    @general     s. brief
    @conseq      @incp   dynamic of the filter increases
                 @decp   dynamic of the filter decreases
    @attention   -
    @typical     0.114469    @unit  -   @min 0   @max tbd   */

SET_MEMSEC_CONST(SPM_BLK_A_OUTPUT_FILTER_FAST_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLK_A_OUTPUT_FILTER_FAST_c ,   0.114469F )

/*! @brief       Alpha value for slow output filtering
    @general     s. brief
    @conseq      @incp   dynamic of the filter increases
                 @decp   dynamic of the filter decreases
    @attention   -
    @typical     0.002    @unit  -   @min 0   @max tbd   */

SET_MEMSEC_CONST(SPM_BLK_A_OUTPUT_FILTER_SLOW_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLK_A_OUTPUT_FILTER_SLOW_c ,   0.002F )

/*! @brief       Blockage probability at which full damping is reported
    @general     s. brief
    @conseq      @incp   availability of the system increases
                 @decp   availability of the system decreases
    @attention   -
    @typical     80    @unit  %   @min 60   @max 99   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c ,   0.8F )

/*! @brief       Time the system remains deactivated after SRR damping transition from FULL/RDC_DAMP to
                 NO_DAMP for this period of time
    @general     s. brief
    @conseq      @incp   system remains longer in deactivated after SRR damping
                 @decp   system remains shorter in deactivated after SRR damping
    @attention   -
    @typical     0    @unit  [s]   @min 0   @max 240   */

SET_MEMSEC_CONST(SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c )
FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c ,   120.0F )


/*! @brief       Time the system looks for a new relevant object after loss of current rel. obj
                 and avoids enterung full damp mode although fusion already reports full blockage
                 (only relevant if switch SPM_FULL_DAMP_WITH_NO_REL_OBJ is on)
    @general     s. brief
    @conseq      @incp   entering full damp mode is delayed
                 @decp   full damp mode is entered faster after rel. obj. loss 
    @attention   -
    @typical     0    @unit  [s]   @min 0   @max 5   */

SET_MEMSEC_CONST(SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c )
FCT_DEF_FIX_PARAM( float32 , SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c ,   2.0F )


/*! @brief       Number of allowed object losses of the relevant object until full blockage
                 is reported, only disappearences are counted here, not re-appearences
    @general     s. brief
    @conseq      @incp   availability of the system increases
                 @decp   availability of the system decreases
    @attention   -
    @typical     5    @unit  -   @min 3   @max 10   */

SET_MEMSEC_CONST(SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c )
FCT_DEF_FIX_PARAM(uint8 , SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c ,   3u )


/*! @brief       Activation Switch for blockage, computation is always active but damping state is not determined
                 and "no damp" is reported always if switch is off
    @general     s. brief
    @conseq      @SWITCH_ON    blockage algorithm reports current blockage state
                 @SWITCH_OFF   blockage algorithm reports always "NO_DAMP"
    @attention   -
    @typical     SWITCH_ON    @unit  -   @min SWITCH_OFF   @max SWITCH_ON   */

SET_MEMSEC_CONST(SPM_ENABLE_BLOCKAGE_c )
FCT_DEF_FIX_PARAM(boolean , SPM_ENABLE_BLOCKAGE_c ,  (boolean)SWITCH_ON )

/*! @brief       Activation Switch for selftest, computation is always active but selftest state is not determined
                 and "no damp" is reported always if switch is off
    @general     s. brief
    @conseq      @SWITCH_ON    selftest algorithm reports current selftest state
                 @SWITCH_OFF   selftest algorithm reports always "selftest passed"
    @attention   -
    @typical     SWITCH_ON    @unit  -   @min SWITCH_OFF   @max SWITCH_ON   */

SET_MEMSEC_CONST(SPM_ENABLE_SELFTEST_c )
FCT_DEF_FIX_PARAM(boolean , SPM_ENABLE_SELFTEST_c ,   (boolean)SWITCH_ON)

/*! @brief       An object has to be relevant for at least this duration to be considered 
                 for ObjectLoss
    @general     s. brief
    @conseq      @incp  Object has to be relevant longer to be detected by ObjectLoss
                 @decp  Object has to be relevant shorter to be detected by ObjectLoss
    @attention   -
    @typical     3    @unit  [s]   @min 0   @max 10   */

SET_MEMSEC_CONST(SPM_OBJLOSS_MINRELOBJ_TIMER_c )
FCT_DEF_FIX_PARAM(uint8 , SPM_OBJLOSS_MINRELOBJ_TIMER_c ,   5u )
#endif
#else
  /***********************/
  /* Velocity thresholds */
  /***********************/
  /*! @brief       Minimum speed for blockage state determination 
      @general     s. brief
      @conseq      @incp   availability of system will decrease
                   @decp   will not work properly
      @attention   systems power reduction mode can affect performance of 
                   blockage detection  
      @typical     10kph    @unit  [m/s]   @min 0 @max 30/C_KMH_MS   */
  #if(SPM_USE_STOPNGO_BLOCKAGE == SWITCH_ON)
   FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_c ,  (0.5F*C_MS_KMH) )
  #else
   FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_c ,  (10.0F*C_MS_KMH) )
  #endif
  
  /*! @brief       Maximum speed for blockage state determination 
      @general     s. brief
      @conseq      @incp   availability of system will increase
                   @decp   availability of system will decrease
      @attention   too high speed will cause sideeffects in range statistic, objects will pass too fast 
      @typical     200kph    @unit  [m/s]   @min 120/C_KMH_MS   @max 250/C_KMH_MS   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MAX_c ,  (200.0F*C_MS_KMH) )
  
  /*! @brief       Minimum speed for use Object loss observeration 
      @general     s. brief
      @conseq      @incp   availability of system will decrease
                   @decp   will not work properly
      @attention   systems power reduction mode can affect performance of 
                   blockage detection  
      @typical     10kph    @unit  [m/s]   @min 0 @max 30/C_KMH_MS   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_OBJ_LOSS_c ,  (30.0F*C_MS_KMH) )
  
  /***********************/
  /* Selftest parameters */
  /***********************/
  /*! @brief       complete selftest cycle with statistical analysis and roadbeam test
      @general     s. brief
      @conseq      @incp   faster change between statistical analysis and roadbeam
                   @decp   slower change between statistical analysis and roadbeam
      @attention   -
      @typical     120s    @unit  [s]   @min 30   @max 240   */
  #if(SPM_SELFTEST_ROADBEAM_TEST_ACTIVE == SWITCH_ON)
   FCT_DEF_FIX_PARAM( float32 , SPM_TMAX_UNTIL_OBJ_c ,   60.0F)
  #else
   FCT_DEF_FIX_PARAM( float32 , SPM_TMAX_UNTIL_OBJ_c ,  120.0F)
  #endif
  
  /*! @brief       Minimum speed for activation of selftest
      @general     s. brief
      @conseq      @incp   selftest will start later
                   @decp   selftest will start earlier
      @attention   systems power reduction mode can affect the results of the selftest 
      @typical     10kph    @unit  [kph]   @min 0   @max 30   */
  #if(SPM_USE_STOPNGO_SELFTEST == SWITCH_ON)
   FCT_DEF_FIX_PARAM( float32 , SPM_SPEED_MIN_SELFTEST_c ,   (0.5F*C_MS_KMH) )
  #else
   FCT_DEF_FIX_PARAM( float32, SPM_SPEED_MIN_SELFTEST_c , (10.0F*C_MS_KMH) )
  #endif
  
  /*! @brief       Minimum range for successful selftest
      @general     s. brief
      @conseq      @incp   availability of the system will decrease
                   @decp   availability of the system will increase
      @attention   -
      @typical     100m    @unit  [m]   @min 50   @max 150   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_RANGE_MIN_c ,   50.0F )
  
  /*! @brief       Minimum range confidence for successful selftest
      @general     s. brief
      @conseq      @incp   availability of the system will decrease
                   @decp   availability of the system will increase
      @attention   -
      @typical     0.05    @unit  -   @min 0.01   @max 0.5   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_CONFIDENCE_MIN_c ,   0.05F )
  
  /*! @brief       Minimum range for reactivation after failed selftest
      @general     s. brief
      @conseq      @incp   availability of the system will decrease
                   @decp   availability of the system will increase
      @attention   -
      @typical     140m    @unit  [m]   @min 100   @max 160   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_REACTIVATION_RANGE_c ,   70.0F )
  
  /*! @brief       Minimum range confidence for reactivation after failed selftest
      @general     s. brief
      @conseq      @incp   availability of the system will decrease
                   @decp   availability of the system will increase
      @attention   -
      @typical     0.4    @unit  -   @min 0.1   @max 0.8   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SELFTEST_REACTIVATION_CONF_c ,   0.4F )
  
  /***************************/
  /* Interference parameters */
  /***************************/
  /*! @brief       ?
      @general     s. brief
      @conseq      @incp   ?
                   @decp   ?
      @attention   ?
      @typical     15m    @unit  [m]   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_DIST_MIN_c ,   15.0F )
  
  /*! @brief       ?
      @general     s. brief
      @conseq      @incp   ?
                   @decp   ?
      @attention   ?
      @typical     60m    @unit  [m]   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_DIST_MAX_c ,   60.0F )
  
  /*! @brief       ?
      @general     s. brief
      @conseq      @incp   ?
                   @decp   ?
      @attention   ?
      @typical     3.6    @unit  ?   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_INTERFERENC_RANGE_TIME_DIST_c ,   3.6F )
  
  /*! @brief       ?
      @general     s. brief
      @conseq      @incp   ?
                   @decp   ?
      @attention   ?
      @typical     100    @unit  -   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( uint32 , SPM_INTERFERENCE_RANGE_HOLD_c ,   100u )
  
  /*********************/
  /* Common parameters */
  /*********************/
  /*! @brief       Threshold of variance of current velocity for ACC availability
      @general     s. brief
      @conseq      @incp   ACC availability will decrease
                   @decp   ACC availability will increase
      @attention   ?
      @typical     30(m/s)^2    @unit  [(m/s)^2]   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_VELOCITY_ACC_MAX_VARIANCE_c ,   30.0F )
  
  /*! @brief       Threshold of variance of current yawrate for ACC availability
      @general     s. brief
      @conseq      @incp   ACC availability will decrease
                   @decp   ACC availability will increase
      @attention   ?
      @typical     0.025rad^2    @unit  [rad^2]   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_YAWRATE_ACC_MAX_VARIANCE_c ,   0.025F )
  
  /*! @brief       Minimum velocity for yawrate variance consideration
      @general     s. brief
      @conseq      @incp   ACC availability will decrease
                   @decp   ACC availability will increase
      @attention   ?
      @typical     1m/s    @unit  [m/s]   @min tbd   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_YAWRATE_ACC_MIN_VELOCITY_c ,   1.0F )
  
  /*! @brief       Max allowed position failure depending on Speedfailure
      @general     s. brief
      @conseq      @incp   EBA availability will decrease
                   @decp   EBA availability will increase
      @attention   ?
      @typical     2m    @unit  [m]   @min 0   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_LATERAL_POS_ADD_SPEED_FAILURE_c ,   1.0F )
  
  /*! @brief       Time the system remains in full damping before checking the situation again
      @general     s. brief
      @conseq      @incp   time the system remains in full damp mode increases
                   @decp   time the system remains in full damp mode decreases
      @attention   value must not be 0!
      @typical     120s    @unit  [s]   @min 0.001   @max 300   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_REACTIVATION_DELAY_c ,   120.0F )
  
  /************************/
  /* Blockage parameters  */
  /************************/
  /*! @brief       If BSD range drops below deactivation threshold this time delays blockage
      @general     s. brief
      @conseq      @incp   blockage is reported later
                   @decp   blockage is reported earlier
      @attention   -
      @typical     0    @unit  [s]   @min 0   @max 600   */
   FCT_DEF_FIX_PARAM(float32, SPM_BSD_RANGE_HOLD_COUNTER_THLD_c ,   120.0F)
  
  /*! @brief       If LCA range drops below deactivation threshold this time delays blockage
      @general     s. brief
      @conseq      @incp   blockage is reported later
                   @decp   blockage is reported earlier
      @attention   -
      @typical     0    @unit  [s]   @min 0   @max 600   */
   FCT_DEF_FIX_PARAM(float32, SPM_LCA_RANGE_HOLD_COUNTER_THLD_c ,   120.0F)
  
  /*! @brief       Minimum confidence needed to change blockage state
      @general     s. brief
      @conseq      @incp   blockage is reported with lower uncertainty
                   @decp   blockage is reported with higher uncertainty
      @attention   -
      @typical     0.4    @unit  -   @min 0.2   @max 0.6   */
   FCT_DEF_FIX_PARAM(float32, SPM_STATE_CONF_MIN_c ,    0.4F)
  
  /*! @brief       Minimum confidence needed to change blockage state fro, NO Damp to increase Damp
      @general     s. brief
      @conseq      @incp   blockage is reported with lower uncertainty
                   @decp   blockage is reported with higher uncertainty
      @attention   -
      @typical     0.4    @unit  -   @min 0.2   @max 0.6   */
   FCT_DEF_FIX_PARAM(float32, SPM_RANGE_CONF_INC_BLOCKANGE_MIN_c ,    0.3F)
  
  /*! @brief       Range at which the algo reports Sensor Damping for BSD
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     71.25m    @unit  [m]   @min 60   @max 100   */
   FCT_DEF_FIX_PARAM( uint8 , SPM_BLOCKAGE_SHUTOFF_BSD_RANGE_c ,   22U )
  
  /*! @brief       Range at which the algo reports Sensor damping for LCA
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     71.25m    @unit  [m]   @min 60   @max 100   */
   FCT_DEF_FIX_PARAM( uint8 , SPM_BLOCKAGE_SHUTOFF_LCA_RANGE_c ,   55U )
  
  /*! @brief       Range at which the corresponding INC BSD blockage 
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     140m    @unit  [m]   @min 120   @max 180   */
   FCT_DEF_FIX_PARAM( uint8 , SPM_BLOCKAGE_INC_BSD_RANGE_c ,   35U )
  
  /*! @brief       Range at which the corresponding INC LCA blockage 
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     140m    @unit  [m]   @min 120   @max 180   */
   FCT_DEF_FIX_PARAM( uint8 , SPM_BLOCKAGE_INC_LCA_RANGE_c ,   65U )
  
  /*! @brief       Range at which the corresponding BSD blockage probability is 0%
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     140m    @unit  [m]   @min 120   @max 180   */
   FCT_DEF_FIX_PARAM( uint8 , SPM_BLOCKAGE_FULL_BSD_RANGE_c ,   40U )
  
  /*! @brief       Range at which the corresponding LCA blockage probability is 0%
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     140m    @unit  [m]   @min 120   @max 180   */
   FCT_DEF_FIX_PARAM( uint8 , SPM_BLOCKAGE_FULL_LCA_RANGE_c ,   70U )
  
  /*! @brief       Influence of range criterion for blockage probability 
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     1    @unit  -   @min 0   @max 1   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_RANGE_WEIGHT_c ,   1.0F )
  
  /*! @brief       Passed time without valid object at which the algo reports blockage
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     60s    @unit  [s]   @min 30   @max 120   */
   FCT_DEF_FIX_PARAM( uint32 , SPM_BLOCKAGE_SHUTOFF_TIME_c ,   180u )
  
  /*! @brief       Driven distance without valid object at which the algo reports blockage
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     2000m    @unit  [m]   @min 1000   @max 5000   */
   FCT_DEF_FIX_PARAM(uint32 , SPM_BLOCKAGE_SHUTOFF_WAY_c ,   3000u )
  
  /*! @brief       Influence of timeout criterion for blockage probability 
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     1    @unit  -   @min 0   @max 1   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_TIMEOUT_WEIGHT_c ,   1.0F )
  
  /*! @brief       Influence of object loss criterion for blockage probability 
      @general     s. brief
      @conseq      @incp   availability of the system decreases
                   @decp   availability of the system increases
      @attention   -
      @typical     1    @unit  -   @min 0   @max 1   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_OBJLOSS_WEIGHT_c ,   1.0F )
  
  /*! @brief       Alpha value for fast output filtering
      @general     s. brief
      @conseq      @incp   dynamic of the filter increases
                   @decp   dynamic of the filter decreases
      @attention   -
      @typical     0.114469    @unit  -   @min 0   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLK_A_OUTPUT_FILTER_FAST_c ,   0.114469F )
  
  /*! @brief       Alpha value for slow output filtering
      @general     s. brief
      @conseq      @incp   dynamic of the filter increases
                   @decp   dynamic of the filter decreases
      @attention   -
      @typical     0.002    @unit  -   @min 0   @max tbd   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLK_A_OUTPUT_FILTER_SLOW_c ,   0.002F )
  
  /*! @brief       Blockage probability at which full damping is reported
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     80    @unit  %   @min 60   @max 99   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB_c ,   0.8F )
  
  /*! @brief       Time the system remains deactivated after SRR damping transition from FULL/RDC_DAMP to
                   NO_DAMP for this period of time
      @general     s. brief
      @conseq      @incp   system remains longer in deactivated after SRR damping
                   @decp   system remains shorter in deactivated after SRR damping
      @attention   -
      @typical     0    @unit  [s]   @min 0   @max 240   */
   FCT_DEF_FIX_PARAM( float32 , SPM_BLOCKAGE_SRD_REACTIVATION_DELAY_c ,   120.0F )
  
  
  /*! @brief       Time the system looks for a new relevant object after loss of current rel. obj
                   and avoids enterung full damp mode although fusion already reports full blockage
                   (only relevant if switch SPM_FULL_DAMP_WITH_NO_REL_OBJ is on)
      @general     s. brief
      @conseq      @incp   entering full damp mode is delayed
                   @decp   full damp mode is entered faster after rel. obj. loss 
      @attention   -
      @typical     0    @unit  [s]   @min 0   @max 5   */
   FCT_DEF_FIX_PARAM( float32 , SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY_c ,   2.0F )
  
  
  /*! @brief       Number of allowed object losses of the relevant object until full blockage
                   is reported, only disappearences are counted here, not re-appearences
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     5    @unit  -   @min 3   @max 10   */
   FCT_DEF_FIX_PARAM(uint8 , SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP_c ,   0u )
  
  
  /*! @brief       Activation Switch for blockage, computation is always active but damping state is not determined
                   and "no damp" is reported always if switch is off
      @general     s. brief
      @conseq      @SWITCH_ON    blockage algorithm reports current blockage state
                   @SWITCH_OFF   blockage algorithm reports always "NO_DAMP"
      @attention   -
      @typical     SWITCH_ON    @unit  -   @min SWITCH_OFF   @max SWITCH_ON   */
   FCT_DEF_FIX_PARAM(boolean , SPM_ENABLE_BLOCKAGE_c ,  ((boolean)SWITCH_ON) )
  
  /*! @brief       Activation Switch for selftest, computation is always active but selftest state is not determined
                   and "no damp" is reported always if switch is off
      @general     s. brief
      @conseq      @SWITCH_ON    selftest algorithm reports current selftest state
                   @SWITCH_OFF   selftest algorithm reports always "selftest passed"
      @attention   -
      @typical     SWITCH_ON    @unit  -   @min SWITCH_OFF   @max SWITCH_ON   */
   FCT_DEF_FIX_PARAM(boolean , SPM_ENABLE_SELFTEST_c ,   ((boolean)SWITCH_ON) )
  
  /*! @brief       Debounce Time to leave the stable state
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     20    @unit  s   @min 1   @max tbd   */
   FCT_DEF_FIX_PARAM(float32 , DEBOUNCETIME_c ,   20.f )
  
  /*! @brief       Value for Function Activation
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     0.9    @unit  °   @min    @max    */
   FCT_DEF_FIX_PARAM(float32 , SPM_ACTIVATION_THRESHOLD_AZIMUTH_c ,   2.7f )
  
  /*! @brief       Value for Function Deactivation
                   Value should be greater than value for activation!
      @general     s. brief
      @conseq      @incp   availability of the system increases
                   @decp   availability of the system decreases
      @attention   -
      @typical     0.3    @unit  °   @min    @max    */
   FCT_DEF_FIX_PARAM(float32 , SPM_DEACTIVATION_THRESHOLD_AZIMUTH_c ,   3.f )
  
  /*! @brief       at standstill after ignition on no alignment info is available. 
                   Use switch for deaktivation of CMS/ContiGuard function in these situation 
      @general     s. brief
      @conseq      @SWITCH_ON    no ContiGuard/CMS function
                   @SWITCH_OFF   ContiGuard/CMS function available at unknown misalignment
      @attention   -
      @typical     SWITCH_ON    @unit  -   @min    @max    */
   FCT_DEF_FIX_PARAM(boolean , UNKNOWN_MISALIGNMENT_NOT_SAFE_c ,   ((boolean)SWITCH_OFF) )
  
  /*! @brief       An object has to be relevant for at least this duration to be considered 
                   for ObjectLoss
      @general     s. brief
      @conseq      @incp  Object has to be relevant longer to be detected by ObjectLoss
                   @decp  Object has to be relevant shorter to be detected by ObjectLoss
      @attention   -
      @typical     3    @unit  [s]   @min 0   @max 10   */
   FCT_DEF_FIX_PARAM(uint8 , SPM_OBJLOSS_MINRELOBJ_TIMER_c ,   1u )
#endif

