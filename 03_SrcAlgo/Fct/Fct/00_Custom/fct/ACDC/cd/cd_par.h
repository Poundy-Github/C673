/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD (Collision Detection)

PACKAGENAME:               cd_par.h

DESCRIPTION:               Parameters of CD (Collision Detection)

AUTHOR:                    $Author: Rastogi, Abhishek (uib10447) (uib10447) $

CREATION DATE:             $Date: 2019/12/17 10:28:50CET $

VERSION:                   $Revision: 1.42.2.1 $

LEGACY VERSION:            Revision: 1.158.1.8.1.4

**************************************************************************** */
#ifndef CD_PAR_H_INCLUDED
#define CD_PAR_H_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_par.h"
#include "cd_cfg.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup cd_par Parameter
@ingroup cd
@brief        Contains all parameters that are used in CD and their values.\n\n
@description  This module does not contain any functions. It only contains defines as soon as variable initializations.
@{
*/

/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
/*! @brief  number of edges in a rectangle as an unsigned int 4u */
#define CD_NUMBER_OF_EDGES_IN_A_RECTANGLE (4u)

/*! @brief  if we continuously enumerate a chain of edges in a rectangle i.e. with 0, 1, 2 and 3; every edge with index i has an opposite edge on index
    (i+CD_INDEX_OFFSET_OF_AN_OPPOSITE_EDGE_IN_A_RECTANGLE)modCD_NUMBER_OF_EDGES_IN_A_RECTANGLE, it holds CD_INDEX_OFFSET_OF_AN_OPPOSITE_EDGE_IN_A_RECTANGLE = 2u
 */
#define CD_INDEX_OFFSET_OF_AN_OPPOSITE_EDGE_IN_A_RECTANGLE (2u)

/*! @brief  if we continuously enumerate a chain of edges in a rectangle i.e. with 0, 1, 2 and 3; every edge with index i has a previous edge on index
    (i+CD_INDEX_OFFSET_OF_A_PREVIOUS_EDGE_IN_A_RECTANGLE)modCD_NUMBER_OF_EDGES_IN_A_RECTANGLE, it holds CD_INDEX_OFFSET_OF_AN_OPPOSITE_EDGE_IN_A_RECTANGLE = 3u*/
#define CD_INDEX_OFFSET_OF_A_PREVIOUS_EDGE_IN_A_RECTANGLE (3u)

/****************************************************************
 General Calculation Settings
 *****************************************************************/

/*! @brief  Assumed latency of VDY data compared to Object data. 
            @typical 0.000f, @unit  [s] */
#define CD_LATENCY_OBJ_ACQUISITION                  (       0.000f)

/*! @brief  Assumed latency from VDY data to Bus output of FCT. 
            @typical 0.160f, @unit  [s] */
#define CD_LATENCY_FCT2BRAKE                        (       0.120f)
/*! @brief  Assumed latency starting from sensor data aquisition up to the brake system; 
            used to calculate the control values (anec_long; anec_lat; closing velocity ). \n
            @typical @ref CD_LATENCY_FCT2BRAKE + @ref CD_LATENCY_OBJ_ACQUISITION, @unit [s]*/
#define CD_LATENCY_SYSTEM                           (CD_LATENCY_FCT2BRAKE + CD_LATENCY_OBJ_ACQUISITION)

/*! @brief  Model parameter used as an offset time in calculation of anec long to account 
            for the fact that actual brake response curve is not a step function.
            @typical 0.0f, @unit [s]*/
#define CD_BRK_RESPONSE_TIME                        (           0.0f)

/*! @brief  Maximum possible distance. @typical 200.0f, @unit [m]*/
#define CD_DIST_MAX                                 (         200.0f)

/*! @brief  Maximum time value as calculation result. @typical 40.0f, @unit [s] */
#define CD_TIME_MAX                                 (          40.0f)

/*! @brief  Number of CD Hypothesis to be calculated in one cycle.
            @typical \ref MAX_NUM_OF_HYPS */
#define CD_NUMBER_OF_HYPOTHESES            ((uint32) MAX_NUM_OF_HYPS)

/*! @brief      Number of CD Hypothesis types 
                @typical    14u */
#define CD_NUMBER_OF_HYPOTHESES_TYPES               (            14u)

/************************************************************************/
/* Lazy calculation initial and check values                            */
/************************************************************************/

/*! @brief  Initial TTC value. @typical 1000.0f, @unit [s] */
#define CD_TTC_INIT                                 (        1000.0f)

/*! @brief  Initial TTM value. @typical 1000.0f, @unit [s] */
#define CD_TTM_INIT                                 (        1000.0f)

/*! @brief  Initial Necessary longitudinal acceleration to avoid a collision. 
            @typical 1000.0f, @unit [m/s^2] */
#define CD_LONGNECACCEL_INIT                        (        1000.0f)

/*! @brief  Initial Necessary lateral acceleration to avoid a collision.
            @typical 1000.0f, @unit [m/s^2]*/
#define CD_LATNECACCEL_INIT                         (        1000.0f)

/*! @brief  Initial time to brake for comfort and emergency braking.
            @typical 1000.0f, @unit [s]*/
#define CD_TTBDYN_INIT                              (        1000.0f)

/*! @brief  Initial Relative speed at time of collision.
            @typical 1000.0f, @unit [m/s]*/
#define CD_CLOSINGVELOCITY_INIT                     (        1000.0f)

/*! @brief  Initial time to steer for comfort steering.
            @typical 1000.0f, @unit [s]*/
#define CD_TTSPRE_INIT                              (        1000.0f)

/*! @brief  Initial time to steer for emergency steering 
            @typical 1000.0f, @unit [s]*/
#define CD_TTSACUTE_INIT                            (        1000.0f)

/*! @brief  Initial value of all object movement properties.
            @typical 1000.0f, @unit [m]/[m/s]/[m/s^2]*/
#define CD_OBJMOV_PAR_INIT                          (        1000.0f)

/*! @brief  Initial value of the Ego movement properties
            @typical 1000.0f, @unit [m]/[m/s]/[m/s^2]*/
#define CD_EGOMOV_PAR_INIT                          (        1000.0f)

/*! @brief  Initial value of the TTCBrakeJerk.
            @typical 1000.0f, @unit [s]*/
#define CD_TTCBRAKEJERK_INIT                        (        1000.0f)

/*! @brief  Initial value of the fTTCBrakeJerkFactor.
            @typical 1000.0f*/
#define CD_TTCBRAKEJERKFACTOR_INIT                  (        1000.0f)

/*! @brief  Assumed check value of CorridorStopDistance.
            @typical 1000.0f, @unit [m]*/
#define CD_CORRIDORSTOPDIST_INIT                    (        1000.0f)

/*! @brief  Assumed check value of Ego movement properties.
            @typical 999.0f, @unit [m]/[m/s]/[m/s^2]*/
#define CD_EGOMOV_PAR_CHECK                         (         999.0f)

/*! @brief  Assumed check value of object movement properties.
            @typical 999.0f, @unit [m]/[m/s]/[m/s^2]*/
#define CD_OBJMOV_PAR_CHECK                         (         999.0f)

/*! @brief  Assumed check value of TTC.
            @typical 999.0f, @unit [s]*/
#define CD_TTC_CHECK                                (         999.0f)

/*! @brief  Assumed check value of TTM.
            @typical 999.0f, @unit [s]*/
#define CD_TTM_CHECK                                (         999.0f)

/*! @brief  Assumed check value of LongNecAccel.
            @typical 999.0f, @unit [m/s^2]*/
#define CD_LONGNECACCEL_CHECK                       (         999.0f)

/*! @brief  Assumed check value of TTBPre and TTBAcute
            @typical 999.0f, @unit [s]*/
#define CD_TTBDYN_CHECK                             (         999.0f)

/*! @brief  Assumed check value of AnecLat.
            @typical 999.0f, @unit [m/s^2]*/
#define CD_ANECLAT_CHECK                            (         999.0f)

/*! @brief  Assumed check value of ClosingVelocity.
            @typical 999.0f, @unit [m/s]*/
#define CD_CLOSINGVELOCITY_CHECK                    (         999.0f)

/*! @brief  Assumed check value of TTSPre.
            @typical 999.0f, @unit [s]*/
#define CD_TTSPRE_CHECK                             (         999.0f)

/*! @brief  Assumed check value of TTSAcute.
            @typical 999.0f, @unit [s]*/
#define CD_TTSACUTE_CHECK                           (         999.0f)

/*! @brief  Assumed check value of TTCBrakeJerk.
            @typical 999.0f, @unit [s]*/
#define CD_TTCBRAKEJERK_CHECK                        (        999.0f)

/*! @brief  Assumed check value of TTCBrakeJerkFactor.
            @typical 999.0f*/
#define CD_TTCBRAKEJERKFACTOR_CHECK                  (        999.0f)

/*! @brief  Assumed check value of CorridorStopDistance.
            @typical 999.0f, @unit [m]*/
#define CD_CORRIDORSTOPDIST_CHECK                    (        999.0f)

/*! @brief  Minimum lateral velocity to assume that Target does not stay in ego corridor.
            @typical 0.5f, @unit [m/s^2]*/
#define CD_ANECLONG_PASS_LATVEL_THRES               (           0.5f)

/*! @brief  Maximum necessary longitudinal deceleration as calculation result.
            @typical -15.0f, @unit [m/s^2]*/
#define CD_NEC_LONG_DECEL_MAX                       (         -15.0f)

/*! @brief  Virtual Distance to target for still stand braking 
            @typical 0.02f, @unit [m]*/
#define CD_NEC_LONG_VIRTUAL_OBJ_DIST                (          0.20f)

/*! @brief  Maximum necessary lateral deceleration as calculation result
            @typical 15.0f, @unit [m/s^2]*/
#define CD_NEC_LAT_DECEL_MAX                        (          15.0f)


/*! @brief  Longitudinal safety distance.
            @typical 0.5f, @unit [m]*/
#define CD_LONG_SAFETY_DISTANCE                     (           0.6f)

/*! @brief  Longitudinal safety distance for customer output calculated value , CD parameters allow:oem_bmw.
            @typical @ref CDParLongSafetyDistCust_c, @unit [m]*/
#define CD_LONG_SAFETY_DIST_CUST                    CDParLongSafetyDistCust_c

/*! @brief  Longitudinal safety distance for customer output calculated default value.
            @typical 0.5f, @unit [m]*/
#define CD_LONG_SAFETY_DIST_CUST_DEFAULT            (           0.6f)


/*! @brief  Lateral safety distance without overlap of ego and object.
            @typical 0.3f, @unit [m]*/
#define CD_LAT_SAFETY_DISTANCE                      (         0.3f)

/*! @brief  Maximum time to pass to be considered in TTS calculation [s].
            @typical 0.64f, @unit [s]*/
#define CD_TTS_MAX_PASSING_TIME                     (           1.3f)

/*! @brief  Minimum lateral speed of object to consider time to pass in TTS calculation.
            @typical 0.5f, @unit [m/s]*/
#define CD_TTS_MAX_YVEL_FOR_PASSING                 (         0.5f)

/*! @brief  Assumed longitudinal acceleration for emergency braking.
            @typical -9.0f, @unit [m/s^2]*/
#define CD_EMERGENCY_BRAKE_ACCEL                    (        -9.0f)

#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)
/*! @brief  Assumed longitudinal negative acceleration for comfort braking.
            @typical -3.0f, @unit [m/s^2]*/
#define CD_TTM_ACCEL_PRE_NEG                        (        -3.0f)

/*! @brief  Assumed longitudinal positive comfort acceleration
            @typical 1.0f, @unit [m/s^2]*/
#define CD_TTM_ACCEL_PRE_POS                        (         1.0f)

/*! @brief  Assumed longitudinal negative acceleration for emergency braking.
            @typical -9.0f, @unit [m/s^2]*/
#define CD_TTM_ACCEL_ACUTE_NEG                      (        -9.0f)

/*! @brief  Assumed longitudinal positive maximum acceleration.
            @typical 3.0f, @unit [m/s^2]*/
#define CD_TTM_ACCEL_ACUTE_POS                      (         3.0f)

/*! @brief  Minimum Safety Gap around objects for TTM calculation.
            @typical 1.5f, @unit [m]*/
#define CD_TTM_SAFETY_GAP_MIN                       (          1.5f)

/*! @brief  Maximum Safety Gap around objects for TTM calculation.
            @typical 2.0f, @unit [m]*/
#define CD_TTM_SAFETY_GAP_MAX                       (          2.0f)

/*! @brief  Minimum Safety Gap Velocity threshold around objects for TTM calculation.
            @typical 5.0f, @unit [m/s]*/
#define CD_TTM_SAFETY_GAP_VELOCITY_THRSHLD_MIN      (          5.0f)

/*! @brief  Maximum Safety Gap Velocity threshold around objects for TTM calculation
            @typical 10.0f, @unit [m/s]*/
#define CD_TTM_SAFETY_GAP_VELOCITY_THRSHLD_MAX      (         10.0f)

#endif /* CD_USE_TTM_LONG */


/*! @brief  Number of value pairs in the ego x-acceleration table (@ref CD_COMFORT_EGO_ACCEL_X). 
            @typical 2L*/
#define CD_NUMBER_OF_COMFORT_EGO_ACCEL_X_VALUES     (           2L)

/*! @brief  Number of value pairs in ego y-acceleration table (@ref CD_COMFORT_EGO_VEL_FACTOR_Y). 
            @typical 7L*/
#define CD_NUMBER_OF_COMFORT_EGO_VEL_FACTOR_Y_VALUES     (           7L)

/*! @brief Number of value pairs in ego y-acceleration table (@ref CD_EMERGENCY_EGO_ACCEL_Y).*/
#define CD_NUMBER_OF_EMERGENCY_EGO_ACCEL_Y_VALUES   (           2L)


/*parameter for TTS Pre overlap*/

/*! @brief CD lateral velocity limit. @typical 2.0f, @unit [m/s] */
#define CD_V_LAT_PRE_LIMIT    (2.0f)

/*! @brief CD max lateral acceleration. @typical 3.5f, @unit [m/s^2] */
#define CD_A_LAT_PRE_LIMIT    (3.5f)

/*! @brief CD lower acceleration threshold. @typical 1.0f, @unit [m/s^2] */
#define CD_A_LAT_PRE_MIN      (1.0f)

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
/*! @brief  Number of value pairs in velocity reduction and minimum duration for brake jerk table:
            @ref CD_BRAKE_JERK_VEL & @ref CD_BRAKE_JERK_TIME*/
#define CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES     (           2L)

/*! @brief  Maximal acceleration for a brake jerk.Object deceleration must be 
            less than this to activate brake jerk calculations.
            @typical -2.0f, @unit: [m/s^2]*/
#define MAX_BRAKE_JERK_ACCEL                        (        -2.0f)

/*! @brief  Value for minimum brake jerk factor at maximum TTC delta. 
            @typical 0.1f*/
#define BRAKE_JERK_FACTOR_VALUE_MAX_DELTA           (         0.1f)

/*! @brief  Maximum TTC delta for brake jerk factor calculation.
            @typical 1.0f, @range ]0,+...[*/
#define BRAKE_JERK_FACTOR_MAX_TTC_DELTA             (         1.0f)

/*! @brief  Minimum TTC delta for brake jerk factor calculation.
            @typical 0.1f, @unit [s]*/
#define BRAKE_JERK_FACTOR_MIN_TTC_DELTA             (         0.1f)
#endif /* CD_USE_BRAKE_JERK_TTC */

#if (CD_PED_USE_EM_ROAD_ESTIMATION)
/*! @brief  Minimum Road Estimation Tracking Status to consider Road Estimation for Pedestrian on Road.
            @typical 5u*/
#define CD_PED_ROAD_EST_MIN_TRACKSTAT               (           5u)

/*! @brief  Minimal confidence for the Road Estimation to be considered for Pedestrian on Road
            @typical 60.0f, @unit [%]*/
#define CD_PED_ROAD_EST_MIN_CONF                    (         60.f)   /* % */

/*! @brief  Minimum lateral distance to the road border to consider the pedestrian on the road.
            @typical 0.7f, @unit [m]*/
#define CD_PED_ROAD_MIN_DIST_TO_BORDER              (         0.7f)

/*! @brief  Minimum Range of the Road Estimation to consider as valid.
            @typical 30.0f, @unit [m]*/
#define CD_PED_ROAD_MIN_RANGE                       (        30.0f)

#endif /* CD_PED_USE_EM_ROAD_ESTIMATION */

#if CD_USE_HIGH_QUALITY_LIFETIME
/*! @brief      Gradient for object high quality lifetime reduction
    @general    Gradient for reduction of object high quality lifetime in case conditions are not met. Value needs to be negative.
    @conseq     -
    @attention  Must be negative to have an effect. 0 switches off the functionality.
    @typical 0  @unit  -   @min -   @max 0   */
#define CD_HIGH_QUALITY_LIFETIME_GRAD                           (0.0f)

/*! @brief      Maximum allowed value for object high quality lifetime
    @typical 2.0f  @unit  s  */
#define CD_CALCULATION_HIGH_QUALITY_LIFETIME_MAX                (100.0f)

/*! @brief      EBA object quality threshold for stationary objects used to test whether the high quality lifetime is allowed to be increased.
    @typical 97u @unit - */
#define CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_STAT      (97u)

/*! @brief      EBA object quality threshold for moving and stopped objects used to test whether the high quality lifetime is allowed to be increased.
    @typical 97u  @unit - */
#define CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_MOV_STOP  (97u)

/*! @brief      EBA object quality threshold for crossing objects used to test whether the high quality lifetime is allowed to be increased.
    @typical 60u  @unit - */
#define CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_CROSS     (60u)

/*! @brief      Default threshold for the EBA object quality used to test whether the high quality lifetime is allowed to be increased. 
    @attention  This value is defined such that the high lifetime quality is never increased.
    @typical 100u  @unit - */
#define CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_DEFAULT   (200u)

#endif /* CD_USE_HIGH_QUALITY LIFETIME */

/****************************************************************
  Object Width Settings
 *****************************************************************/

/*! @brief      Constant object width variance.
                @typical 0.0121f, @unit [m]*/
#define CD_CONST_OBJ_WIDTH_VAR                      (        0.0121f)

/*! @brief      Constant object Length variance.
                @typical 0.0121f, @unit [m]*/
#define CD_CONST_OBJ_LENGTH_VAR                     (        0.0121f)

/*! @brief  Minimum object classification sureness to determine a secure object width
            on base of the object class. Secure = smaller, as it avoids false detections,
            used in @ref cd_hypcollision). @typical 95u */
#define CD_OBJ_CLASS_MIN_CONF_WIDTH_SEC             (          95u)

/*! @brief  Maximal size of a car. @typical 1.5f, @unit: [m] */
#define CD_CAR_WIDTH_SEC                            (         1.5f)

/*! @brief  Maximal size of a truck. @typical 2.0f, @unit: [m] */
#define CD_TRUCK_WIDTH_SEC                          (         2.0f)

/*! @brief  Maximal size of an unclassified object. @typical 0.1f, @unit: [m] */
#define CD_OBJECT_NO_CLASS_WIDTH_SEC                (         0.1f)

/*! @brief  Minimum object width assumed for object - trajectory overlap calculation.
            @typical 0.1f, @unit: [m] */
#define CD_MIN_OBJECT_WIDTH                         (         0.1f)

/*! @brief  Minimum trajectory width assumed for object - trajectory overlap calculation 
            @typical 0.1f, @unit: [m] */
#define CD_MIN_TRAJECTORY_WIDTH                     (         0.1f)

/*! @brief  Weighting factor for overlap probability now calculation 
            @typical 0.5f*/
#define CD_OVERLAP_WEIGHT_FAC_PROB_NOW              (           0.4f)

/*! @brief  Weighting factor for overlap probability TTC calculation
            @typical 0.333f*/
#define CD_OVERLAP_WEIGHT_FAC_PROB_TTC              (         0.333f)

#if (CD_PED_USE_LIMITED_DIMENSIONS)
/*! @brief  Maximal width of a pedestrian object.
            @typical 1.0f, @unit: [m] */
#define CD_PEDESTRIAN_WIDTH_SEC                     (         1.0f)

/*! @brief  Maximal length of a pedestrian object.
            @typical 1.0f, @unit: [m] */
#define CD_PEDESTRIAN_LENGTH_SEC                    (         1.0f)
#endif

#if (CD_BICYCLE_USE_LIMITED_DIMENSIONS)
/*! @brief  Maximal width of a bicycle object.
            @typical 1.0f, @unit: [m] */
#define CD_BICYCLE_WIDTH_SEC                     (         1.0f)

/*! @brief  Maximal length of a bicycle object.
            @typical 1.0f, @unit: [m] */
#define CD_BICYCLE_LENGTH_SEC                    (         1.0f)
#endif



/****************************************************************
  Common Hypothesis Settings
 *****************************************************************/

/*! @brief  Threshold for object relevance based on TTC.
            @typical 4.0f, @unit: [s]  */
#define CD_COMMON_TTC_THRES                         (         4.0f)

/*! @brief  threshold for object relevance based on TTB.
            @typical 4.0f, @unit: [s]  */
#define CD_COMMON_TTB_THRES                         (         4.0f)

/*! @brief  threshold for object relevance based on necessary longitudinal acceleration.
            @typical -0.2f, @unit: [m/s^2]  */
#define CD_COMMON_ANECLONG_THRES                    (        -0.2f)

/*! @brief  minimum object probability.
            @typical 48u */
#define CD_COMMON_MIN_OBJ_QUALITY                   (          48u)

/*! @brief  minimum object probability.
            @typical 97u */
#define CD_COMMON_MIN_OBJ_QUALITY_POINT             (          97u)

/*! @brief  Minimum hypothesis probability for hypothesis to be considered.
            @typical 0.5f */
#define CD_COMMON_MIN_HYP_PROB                      (         0.5f)

/*! @brief  Minimum hypothesis probability to treat hypothesis as relevant in hypothesis selection.
            @typical 0.5f */
#define CD_COMMON_HYP_PROB_IRREL_THRES              (         0.5f)

/*! @brief  The minimum required confidence to consider the dynamic state stopped as reliable.
            @typical 80u */
#define CD_COMMON_MIN_STOPPED_CONF                  (            50u)

/*! @brief  Parameter to modify ego vehicle driving path width. This can be used to get earlier function reaction. 
            @typical @ref CDComTrackWidthFact_c*/
#define CD_COMMON_TRACK_WIDTH_FACT                  CDComTrackWidthFact_c

/*! @brief  Default value of the parameter used to modify ego vehicle driving path width.
            @typical 1.0f*/
#define CD_COMMON_TRACK_WIDTH_FACT_DEFAULT          (         1.0f)

/*          Minimum X-Distance for camera.
            @typical @ref C_F32_DELTA unit: [m]*/
#define CD_COMMON_MIN_DISTX                         (         1.0f)


/************************************************************************/
/* Long collision hypothesis settings                                   */
/************************************************************************/
/*! @brief  Minimal overlap to increase the time confirmation.
            @typical 0.3f @range [0,1]*/
#define CD_LONG_COLL_TIME_BASED_HYP_PROB_MIN_OVERLAP (          0.2F)
/*! @brief  Maximum what can be added to hypothesis probability by time confirmation.
            @typical 50u @range [0,100]*/
#define CD_LONG_COLL_TIME_BASED_HYP_PROB_MAX_VALUE        50
/*! @brief  Step size by which the probability is increased per cycle if the time confirmation conditions are fulfilled.
            @typical 5 @range [0,100]*/
#define CD_LONG_COLL_TIME_BASED_HYP_PROB_INCR             5
/*! @brief  Step size by which the probability is decreased per cycle if the time confirmation conditions are not fulfilled.
            @typical 15 @range [0,100]*/
#define CD_LONG_COLL_TIME_BASED_HYP_PROB_DECR             15
/*! @brief  Max difference between the trajectory slope and the object orientation angle to apply time stabilization 
            @typical 20.0f @unit [deg]*/
#define CD_LONG_COLL_TIME_BASED_HYP_PROB_MAX_ORIENT_DIFF  20.0F


/****************************************************************
  Follow Hypothesis Settings
 *****************************************************************/
/*! @brief  Min. EBA generic quality 
            @typical (@ref CD_COMMON_MIN_OBJ_QUALITY + 1u) @range [0,100]*/
#define CD_FOLLOW_MIN_EBA_GEN_OBJ_QUAL              ( CD_COMMON_MIN_OBJ_QUALITY + 1u )

/*! @brief  Min. required object quality for a stationary hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_FOLLOW_MIN_EBA_STAT_OBJ_QUAL             (           0u)

/*! @brief  Min. required object quality of a pedestrian for a static hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_FOLLOW_MIN_EBA_PED_OBJ_QUAL              (           0u)

/*! @brief  Maximum distance of an object to open a static hypothesis.
            @typical 40.0f, unit [m]*/
#define CD_FOLLOWING_MAX_DIST                       (        40.0f)

/*! @brief  Relative velocity threshold for the detection of following situation (lower limit).
            @typical -4.0f, @unit [m/s]*/
#define CD_FOLLOWING_MIN_VREL                       (        -4.0f)

/*! @brief  Relative velocity threshold for the detection of following situation (upper limit).
            @typical 0.0f, @unit [m/s]*/
#define CD_FOLLOWING_MAX_VREL                       (         0.0f)

/*! @brief  relative velocity threshold for the detection (keep) of a following situation (upper limit).
            @typical 2.0f, @unit [m/s]*/
#define CD_FOLLOWING_MAX_VREL_KEEP                  (         2.0f)

/*! @brief  Minimum track assignments of an object to the ego track for a static hypothesis.
            @typical (1u << 7u)*/
#define CD_FOLLOWING_MIN_TRACK_ASSIGNED             (     1u << 7u)

/*! @brief Threshold for pre-selection of objects for follow hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_FOLLOW_MIN_OBJ_CLASS_CONF                (           0u)

/****************************************************************
  Run-up Hypothesis Settings
 *****************************************************************/

/*! @brief  Min. required EBA quality of an object to be considered for a Run Up hypothesis.
            @typical (@ref CD_COMMON_MIN_OBJ_QUALITY + 1u)*/
#define CD_RUN_UP_MIN_EBA_GEN_OBJ_QUAL              ( CD_COMMON_MIN_OBJ_QUALITY + 1u )

/*! @brief  Threshold for object relevance based on necessary longitudinal acceleration in runup hypotheses 
            @typical @ref CD_COMMON_ANECLONG_THRES */
#define CD_RUNUP_ANECLONG_THRES                     (        CD_COMMON_ANECLONG_THRES)

/*! @brief  Relative velocity threshold for the runup hypotheses.
            @typical 1.0f, @unit [m/s]
            @general   -1000 disables the functionality in cd_hyprunup of the velocity threshold   */
#define CD_RUNUP_V_REL_X_THRES                       (        -1000.0f)

/*! @brief  Min. EBA quality to consider an object for a stationary hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_RUN_UP_MIN_EBA_STAT_OBJ_QUAL             (           0u)

/*! @brief  Min. EBA quality to consider a pedestrian for a run up hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_RUN_UP_MIN_EBA_PED_OBJ_QUAL              (           0u)

/*! @brief  Maximal distance to course for run-up hypothesis (prefiltering).
            @typical 2.0f, @unit [m]*/
#define CD_RUN_UP_MAX_LAT_DIST                      (         2.0f)

/*! @brief  Track width that is assumed for the run up hypothesis.
            @typical (@ref ACDC_COMMON_EGO_WIDTH * @ref CD_COMMON_TRACK_WIDTH_FACT), @unit [m]*/
#define CD_RUN_UP_TRACK_WIDTH                       ( ACDC_COMMON_EGO_WIDTH * CD_COMMON_TRACK_WIDTH_FACT)

/*! @brief  Maximal prediction time for RUN UP hypothesis.
            @typical 1.5f, @unit [s]*/
#define CD_RUN_UP_MAX_PRED_TIME                     (           1.0f)

/*! @brief  For objects that are slower than this velocity the prediction time is limited based on the absolute velocity.
           @typical 5.0f, @unit [m/s]*/
#define CD_RUN_UP_PRED_TIME_LIMIT_VABS_THRESH       (         5.0f)

/*! @brief  Factor by which the prediction time is reduced for very slow moving objects.
            @typical 0.1f, @range [0,1]*/
#define CD_RUN_UP_PRED_TIME_LOW_VABS_FACT           (         0.1f)

/*! @brief  Minimum required cycles of track assignment of an object to be considered for a Run Up hypothesis.
            @typical (7u << 5u)*/
#define CD_RUN_UP_MIN_TRACK_ASSIGNED                (     7u << 5u)

/*! @brief  Minimum EBA quality for the track assignment of stationary objects.
            @typical 50u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_RUN_UP_MIN_TRACK_STAT_OBJ_QUALITY        (          50u)

/*! @brief  Minimum class confidence to consider an object for a run-up hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_RUN_UP_MIN_OBJ_CLASS_CONF                (           0u)

/* Overlap thresholds now and TTC */

/*! @brief  If the occupancy is below, the Quality Now is 0.
            @typical 0.2f, @attention: Must not be equal to @ref CD_RUN_UP_THRES_OCC_1_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_RUN_UP_THRES_OCC_0_NOW                   (         0.2f)
/*! @brief  If the occupancy is above, the Quality Now is 1.
            @typical 0.4f, @attention: Must not be equal to @ref CD_RUN_UP_THRES_OCC_0_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_RUN_UP_THRES_OCC_1_NOW                   (         0.4f)
/*! @brief  If the occupancy is above, the Quality TTC is 0.
            @typical 0.1f, @attention: Must not be equal to @ref CD_RUN_UP_THRES_OCC_1_TTC. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_RUN_UP_THRES_OCC_0_TTC                   (         0.1f)
/*! @brief  If the occupancy is above, the Quality TTC is 1.
            @typical 0.3f, @attention: Must not be equal to @ref CD_RUN_UP_THRES_OCC_0_TTC. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_RUN_UP_THRES_OCC_1_TTC                   (         0.3f)

/*! @brief  Lower distance threshold for the calculation of the fQualityDistSpeedAccel.
            @typical 50.0f, @unit [m]*/
#define CD_RUN_UP_THRES_DIST_X0                     (        50.0f)
/*! @brief  Quality returned for @ref CD_RUN_UP_THRES_DIST_X0 for the calculation of the fQualityDistSpeedAccel.
            @typical 1.5f*/
#define CD_RUN_UP_THRES_DIST_Y0                     (         1.5f)
/*! @brief  Upper distance threshold for the calculation of the fQualityDistSpeedAccel.
            @typical 130.0f, @unit [m]*/
#define CD_RUN_UP_THRES_DIST_X1                     (       130.0f)
/*! @brief  Quality returned for @ref CD_RUN_UP_THRES_DIST_X1 for the calculation of the fQualityDistSpeedAccel.
            @typical 0.5f*/
#define CD_RUN_UP_THRES_DIST_Y1                     (         0.5f)

/*! @brief  Lower speed threshold for the calculation of the fQualityDistSpeedAccel.
            @typical 30.0f, @unit [m/s]*/
#define CD_RUN_UP_THRES_SPEED_X0                    (        30.0f) /*108km/h*/
/*! @brief  Quality returned for @ref CD_RUN_UP_THRES_SPEED_X0 for the calculation of the fQualityDistSpeedAccel.
            @typical 1.5f*/
#define CD_RUN_UP_THRES_SPEED_Y0                    (         1.5f)
/*! @brief  Upper speed threshold for the calculation of the fQualityDistSpeedAccel.
            @typical 61.0f, @unit [m/s]*/
#define CD_RUN_UP_THRES_SPEED_X1                    (        61.0f) /*220km/h*/
/*! @brief  Quality returned for @ref CD_RUN_UP_THRES_SPEED_X1 for the calculation of the fQualityDistSpeedAccel.
            @typical 0.5f*/
#define CD_RUN_UP_THRES_SPEED_Y1                    (         0.5f)

/*! @brief  Lower acceleration threshold for the calculation of the fQualityDistSpeedAccel.
            @typical -6.0f, @unit [m/s^2]*/
#define CD_RUN_UP_THRES_ACCEL_X0                    (        -6.0f)
/*! @brief  Quality returned for @ref CD_RUN_UP_THRES_ACCEL_X0 for the calculation of the fQualityDistSpeedAccel.
            @typical 2.0f*/
#define CD_RUN_UP_THRES_ACCEL_Y0                    (         2.0f)
/*! @brief  Upper acceleration threshold for the calculation of the fQualityDistSpeedAccel.
            @typical -1.0f, @unit [m/s^2]*/
#define CD_RUN_UP_THRES_ACCEL_X1                    (        -1.0f)
/*! @brief  Quality returned for @ref CD_RUN_UP_THRES_ACCEL_X1 for the calculation of the fQualityDistSpeedAccel.
            @typical 1.0f*/
#define CD_RUN_UP_THRES_ACCEL_Y1                    (         1.0f)

/*! @brief deceleration of object for Run-up Hypothesis  
   (Adapted from -2.0 to -1.7mpss because of NCAP IUBraking)
 */
#define CD_RUN_UP_OBJ_DECEL_BRAKING                 (        -1.7f)

/*! @brief  Maximum distance up to which a run up hypothesis can be set up if the ego vehicle is driving in a narrow curve.
            @typical 20.0f, @unit [m]*/
#define CD_RUN_UP_NCURVE_MAX_DIST                   (        20.0F)
/*! @brief  Maximum TTC up to which a run up hypothesis can be set up if the ego vehicle is driving in a narrow curve.
            @typical 3.0f, @unit: [s]*/
#define CD_RUN_UP_NCURVE_MAX_TTC                    (         3.0F)
/*! @brief  Minimum curvature apart from which a curve is considered as narrow.
            @typical (1.0f / 155.0f)*/
#define CD_RUN_UP_NCURVE_C0_MIN                     (1.0f / 155.0f)
/*! @brief  Maximum DistToTraj an object may have in a narrow curve to be considered for a run up hypothesis.
            @typical 0.5f, @unit [m]*/
#define CD_RUN_UP_NCURVE_DIST2TRAJ2                 (         0.5F)
/*! @brief  Minimum/Maximum orientation an object may have to be considered for a run up hypothesis.
            @typical (DEG2RAD(5.0F)), @unit [rad]*/
#define CD_RUN_UP_NCURVE_ORIENT                     (DEG2RAD(5.0F))

/*--- Pass by small objects inhibition parameters ---*/
#if (CD_USE_NAR_TRAJ_RUN_UP_SMALL_OBJ)
/*! @brief  Minimum required distance for narrowing trajectory width for small objects */
#define CD_RUNUP_SOBJ_HYP_OCC_VEGO_DIST_NO          (           3L)

/*! @brief  Trajectory width narrowing factors */
#define CD_RUNUP_SOBJ_HYP_OCC_RED_OVER_DIST_NO      (           2L)

/*! @brief  Transition section for trajectory width reduction */
#define CD_RUNUP_SOBJ_HYP_OCC_DIST_RED_FACT         CDParRunUpSObjRedDistFact_c 

#endif

/*! Narrow track width depending on ego trajectory curvature/gradient
 * @attention The logic for the calculation of the curvature/gradient is wrong (see CGEB ActionList)
 */
#define CD_RUN_UP_TTC_WIDTH_NO_POINTS               (           2L)

 /*! @brief CD_RUN_UP_TTC_WIDTH_FAC_NO_POINTS */
#define CD_RUN_UP_TTC_WIDTH_FAC_NO_POINTS           (           2L)

  /*! @brief CD_RUN_UP_TTC_WIDTH_FAC_DEF.  */
#define CD_RUN_UP_TTC_WIDTH_FAC_DEF                 (         1.0F)

/* ! @brief      Coefficient for the low pass filter of the Quality TTC.\n
                 1 -> only the new value is considered (Filter Off)\n
                 0 -> only the old value is considered\n
                 @typical 0.5f, @range [0,1]*/
#define CD_RUN_UP_QUALITY_TTC_FILTER_FACTOR         (         1.0f)

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
/*! @brief Hypothesis probability threshold for the inhibition of PreWarn activation */
#define CD_RUN_UP_INH_BRK_JRK_PREWARN_PROB_THRSHLD  (         0.5f)
/*! @brief Hypothesis probability threshold for the inhibition of PreFill activation */
#define CD_RUN_UP_INH_BRK_JRK_PREFILL_PROB_THRSHLD  (         0.5f)
/*! @brief Hypothesis probability threshold for the inhibition of AcuteWarn activation */
#define CD_RUN_UP_INH_BRK_JRK_ACUWARN_PROB_THRSHLD  (         0.5f)
/*! @brief Hypothesis probability threshold for the inhibition of Brake-Level1 activation */
#define CD_RUN_UP_INH_BRK_JRK_BRK_L1_PROB_THRSHLD   (         0.5f)
#endif

/****************************************************************
  Run-up Stationary Hypothesis Settings
 *****************************************************************/
#if (CD_HYP_RUN_UP_STAT_USE_OBJ_CHAIN_DETECTION == SWITCH_ON)
/*! @brief Relevant object has to be further outside the trajectory than the specified parameter to be used for this check */
#define CD_STAT_OBJ_CHAIN_DET_MIN_DIST2TRAJ         (        0.30f)
/*! @brief Initial distance to trajectory gate which is used to find a first object related to the relevant object */
#define CD_STAT_OBJ_CHAIN_DET_INIT_GATE             (        0.75f)
/*! @brief General processing distance to trajectory gate used to find more objects after an initial object has been found */
#define CD_STAT_OBJ_CHAIN_DET_PROC_GATE             (        0.50f)
/*! @brief Minimum probability of existence of a stationary object to be used for the stationary object chain detection 
           @typical 97u @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_STAT_OBJ_CHAIN_DET_MIN_STAT_POE          (          97u)
/*! @brief Minimum number of objects required for setting a relevant object to invalid */
#define CD_STAT_OBJ_CHAIN_DET_MIN_NOF_OBJS          (            4)
/*! @brief Initial value for the invalid counter */
#define CD_STAT_OBJ_CHAIN_DET_INIT_CNT              (            3)
/*! @brief Maximum value for the invalid counter */
#define CD_STAT_OBJ_CHAIN_DET_MAX_CNT               (            8)
/*! @brief Minimum curve radius for the feature to be active, if the ego curve radius is smaller the feature is deactivated (0.01f => 1.f/100.f => 100m curve radius) */
#define CD_STAT_OBJ_CHAIN_MIN_CURVE_RAD             (        0.01f)
/*! @brief Lower velocity threshold for the x gate setting */
#define CD_STAT_OBJ_CHAIN_DET_VEL_MIN_X_GATE        (        10.0f)
/*! @brief Upper velocity threshold for the x gate setting */
#define CD_STAT_OBJ_CHAIN_DET_VEL_MAX_X_GATE        (        30.0f)
/*! @brief Minimum x gate considered for the feature */
#define CD_STAT_OBJ_CHAIN_DET_MIN_X_GATE            (         6.0f)
/*! @brief Maximum x gate considered for the feature */
#define CD_STAT_OBJ_CHAIN_DET_MAX_X_GATE            (        10.0f)
#endif

/****************************************************************
  Pass Hypothesis Settings
 *****************************************************************/
/*! @brief  Min. required EBA quality to be considered for a pass hypothesis
            @typical ( @ref CD_COMMON_MIN_OBJ_QUALITY + 1u ), @range [0,100]*/
#define CD_PASS_MIN_EBA_GEN_OBJ_QUAL                ( CD_COMMON_MIN_OBJ_QUALITY + 1u )
/*! @brief  Min. required EBA quality of a stationary object to be considered for a pass hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_PASS_MIN_EBA_STAT_OBJ_QUAL               (           0u)
/*! @brief  Min. required EBA quality of a pedestrian to be considered for a pass hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_PASS_MIN_EBA_PED_OBJ_QUAL                (           0u)
/*! @brief  Maximal distance to course to be considered for a run-up hypothesis.
            @typical 7.0f, @unit [m]*/
#define CD_PASS_MAX_LAT_DIST                        (         7.0f)
/*! @brief  Track width for the pass hypothesis.
            @typical 9.0f, @unit [m]*/
#define CD_PASS_TRACK_WIDTH                         (         9.0f)
/*! @brief  Track width at TTC for the pass hypothesis.
            @typical 12.0f, @unit [m]*/
#define CD_PASS_TRACK_WIDTH_TTC                     (        12.0f)
/*! @brief  Maximal prediction time for the Pedestrian hypothesis.
            @typical 0.5f, @unit [s]*/
#define CD_PASS_MAX_PRED_TIME                       (         0.5f)
/*! @brief  Minimal necessary deceleration.
            @typical -3.0f, @unit [m/s^2]*/
#define CD_PASS_ANECLONG_THRES                      (        -3.0f)
/*! @brief  Minimal necessary deceleration (keep).
            @typical -2.5f, @unit [m/s^2]*/
#define CD_PASS_ANECLONG_THRES_KEEP                 (        -2.5f)
/*! @brief  Minimum class confidence of an object relevant for the pass hypothesis*/
#define CD_PASS_MIN_OBJ_CLASS_CONF                  (          80u)

/* Overlap thresholds now and TTC */

/*! @brief  If the occupancy is below, the Quality Now is 0.
            @typical 0.0f, @attention: Must not be equal to @ref CD_PASS_THRES_OCC_1_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_PASS_THRES_OCC_0_NOW                     (         0.0f)
/*! @brief  If the occupancy is above, the Quality Now is 1.
            @typical 0.2f, @attention: Must not be equal to @ref CD_PASS_THRES_OCC_0_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_PASS_THRES_OCC_1_NOW                     (         0.2f)
/*! @brief  If the occupancy is below, the Quality TTC is 0.
            @typical 0.0f, @attention: Must not be equal to @ref CD_PASS_THRES_OCC_1_TTC. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_PASS_THRES_OCC_0_TTC                     (         0.0f)
/*! @brief  If the occupancy is above, the Quality TTC is 1.
            @typical 0.2f, @attention: Must not be equal to @ref CD_PASS_THRES_OCC_0_TTC. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_PASS_THRES_OCC_1_TTC                     (         0.2f)

/****************************************************************
  Cut-in Hypothesis Settings
 *****************************************************************/
/*! @brief  Min. EBA generic quality to be considered for a cut in hypothesis.
            @typical ( CD_COMMON_MIN_OBJ_QUALITY + 1u ), range [0,100]*/
#define CD_CUT_IN_MIN_EBA_GEN_OBJ_QUAL              ( CD_COMMON_MIN_OBJ_QUALITY + 1u )
/*! @brief  Min. EBA quality of a stationary object to be considered for a cut in hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_CUT_IN_MIN_EBA_STAT_OBJ_QUAL             (           0u)
/*! @brief  Min. EBA quality of a pedestrian to be considered for a cut in hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_CUT_IN_MIN_EBA_PED_OBJ_QUAL              (           0u)
/*! @brief  Track width for the cut in hypothesis.
            @typical ( @ref ACDC_COMMON_EGO_WIDTH * @ref CD_COMMON_TRACK_WIDTH_FACT ), @unit [m]*/
#define CD_CUT_IN_TRACK_WIDTH                       ( ACDC_COMMON_EGO_WIDTH * CD_COMMON_TRACK_WIDTH_FACT )
/*! @brief  Cut-in Track width for estimated position.
            @typical 6.0f, @unit [m]*/
#define CD_CUT_IN_TRACK_WIDTH_NOW                   (         6.0f)
/*! @brief  Maximal prediction time for the cut in hypothesis.
            @typical 1.0f, @unit [s]*/
#define CD_CUT_IN_MAX_PRED_TIME                     (         1.0f)
/*! @brief  Minimum class confidence of an object to be considered for a CutIn hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_CUT_IN_MIN_OBJ_CLASS_CONF                (          80u)
/*! @brief  Maximum TTC to pass the cut in object filter.
            @typical @ref CD_COMMON_TTC_THRES, @unit [s]*/
#define CD_CUT_IN_TTC_THRES                         ( CD_COMMON_TTC_THRES )
/*! @brief  Maximum TTC to pass the cut in object filter.
            @typical @ref CD_COMMON_TTB_THRES, @unit [s]*/
#define CD_CUT_IN_TTB_THRES                         ( CD_COMMON_TTB_THRES )
/*! @brief  Maximum AnecLong to pass the cut in object filter.
            @typical @ref CD_COMMON_ANECLONG_THRES, @unit [m/s^2]*/
#define CD_CUT_IN_ANECLONG_THRES                    ( CD_COMMON_ANECLONG_THRES )
/*! @brief  Minimum lane association probability of neighbor objects.
            @typical 80u, @range [0,100]*/
#define CD_CUT_IN_NBOR_OBJ_RUN_UP_MIN_LANE_ASSOC_PROB  (       80u) 
/*! @brief  Minimum lane association confidence of neighbor objects.
            @typical 0u, @range [0,100]*/
#define CD_CUT_IN_NBOR_OBJ_RUN_UP_MIN_LANE_ASSOC_CONF  (        0u) 

/* Overlap thresholds now and TTC */

/*! @brief  If the occupancy is below, the Quality Now is 0.
            @typical @ref CD_RUN_UP_THRES_OCC_0_NOW,
            @attention: Must not be equal to @ref CD_CUT_IN_THRES_OCC_1_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_CUT_IN_THRES_OCC_0_NOW                   CD_RUN_UP_THRES_OCC_0_NOW
/*! @brief  If the occupancy is above, the Quality Now is 1.
            @typical @ref CD_RUN_UP_THRES_OCC_1_NOW,
            @attention: Must not be equal to @ref CD_CUT_IN_THRES_OCC_0_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_CUT_IN_THRES_OCC_1_NOW                   CD_RUN_UP_THRES_OCC_1_NOW
/*! @brief  If the occupancy is below, the Quality TTC is 0.
            @typical @ref CD_RUN_UP_THRES_OCC_0_TTC,
            @attention: Must not be equal to @ref CD_CUT_IN_THRES_OCC_1_TTC. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_CUT_IN_THRES_OCC_0_TTC                   CD_RUN_UP_THRES_OCC_0_TTC
/*! @brief  If the occupancy is above, the Quality TTC is 1.
            @typical @ref CD_RUN_UP_THRES_OCC_1_TTC,
            @attention: Must not be equal to @ref CD_CUT_IN_THRES_OCC_0_NOW. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_CUT_IN_THRES_OCC_1_TTC                   CD_RUN_UP_THRES_OCC_1_TTC
/*! @brief  If the curvature is above, the Quality Traj is 0.
            @typical 0.002f,
            @attention: Must not be equal to @ref CD_CUT_IN_THRES_TRAJC0_0. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_CUT_IN_THRES_TRAJC0_0                    (       0.002f)
/*! @brief  If the curvature is above, the Quality Traj is 0.
            @typical 0.001f,
            @attention: Must not be equal to @ref CD_CUT_IN_THRES_TRAJC0_1. This causes a Div-by-0 exception., @range [0,1]*/
#define CD_CUT_IN_THRES_TRAJC0_1                    (       0.001f)

/****************************************************************
  ACC Hypothesis Settings
 *****************************************************************/

/*! @brief  Min. required eba quality to be considered for an acc hypothesis.
            @typical (@ref CD_COMMON_MIN_OBJ_QUALITY + 1u), @range [0,100]*/
#define CD_ACC_MIN_EBA_GEN_OBJ_QUAL                 ( CD_COMMON_MIN_OBJ_QUALITY + 1u )
/*! @brief  Min. required eba quality of a stationary object to be considered for an acc hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_ACC_MIN_EBA_STAT_OBJ_QUAL                (           0u)
/*! @brief  Min. required eba quality of a pedestrian to be considered for an acc hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_ACC_MIN_EBA_PED_OBJ_QUAL                 (           0u)

/*! @brief  Track width specific for the ACC hypothesis.
            @typical ( 2.2f * @ref CD_COMMON_TRACK_WIDTH_FACT ), @unit [m]*/
#define CD_ACC_TRACK_WIDTH                          ( 2.2f * CD_COMMON_TRACK_WIDTH_FACT )
/*! @brief  ACC hypothesis specific distance at which the full track width is assumed.
            @typical @ref CD_DIST_MAX, @unit [m]*/
#define CD_ACC_LENGTH                               CD_DIST_MAX
/*! @brief  ACC hypothesis specific distance up to which a minimum track width is assumed.
            @typical 20.0f, unit [m]*/
#define CD_ACC_TO_RUNUP_LENGTH                      (        20.0f)
/*! @brief  Minimum number of cycles for which an object has to be track assigned for the ACC Hypothesis.
            @typical (1u << 7u)*/
#define CD_ACC_MIN_TRACK_ASSIGNED                   (     1u << 7u)
/*! @brief  Minimum eba quality of an object to be considered for the acc hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_ACC_MIN_OBJ_CLASS_CONF                   (          80u)

/****************************************************************
  Collision / Collision Unavailable Hypothesis Settings
 *****************************************************************/
/*! @brief  Min. EBA quality to be considered for a collision hypothesis.
            @typical ( @ref CD_COMMON_MIN_OBJ_QUALITY + 1u ), @range [0,100] */
#define CD_COLL_MIN_EBA_GEN_OBJ_QUAL                ( CD_COMMON_MIN_OBJ_QUALITY + 1u )
/*! @brief  Min. EBA quality of a stationary object to be considered for a collision hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_COLL_MIN_EBA_STAT_OBJ_QUAL               (           0u)
/*! @brief  Min. EBA quality of a pedestrian to be considered for a collision hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_COLL_MIN_EBA_PED_OBJ_QUAL                (           0u)
/*! @brief  Maximum TTB/TTS to pass the collision object filter.
            @typical 0.5f, @unit [s]*/
#define CD_COLL_TTB_TTS_THRES                       (         0.5f)
/*! @brief  Maximum TTC to pass the collision object filter.
            @typical 1.0f, @unit [s]*/
#define CD_COLL_TTC_THRES                           (         1.0f)
/*! @brief  Size of the ego vehicle collision width used for collision hypothesis.
            @typical ( @ref ACDC_COMMON_EGO_WIDTH * 0.5f ), @unit [m] */
#define CD_COLL_EGO_COLL_WIDTH                      ( ACDC_COMMON_EGO_WIDTH * 0.5f )
/*! @brief  Maximum number of time steps, which are evaluated.
            @typical 50u*/
#define CD_COLL_NUM_SIM_STEPS                       (          50u)
/*! @brief  Default iteration step width
            @typical 0.05*/
#define CD_COLL_TIME_STEP_WIDTH                     (         0.05F)
/*! @brief  Minimum class confidence to be considered for a collision hypothesis.
            @typical 0u, @range [0,100] */
#define CD_COLL_MIN_OBJ_CLASS_CONF                  (          80u)
/*! @brief  Assumed maximum object acceleration.
            @typical 10.0f, @unit [m/s^2]*/
#define CD_COLL_OBJ_MAX_ACCEL_UNAV                  (        10.0f)
/*! @brief  Assumed maximum ego acceleration in longitudinal direction in case of an unavoidable collision.
            @typical 10.0f, @unit [m/s^2]*/
#define CD_COLL_EGO_MAX_ACCEL_X_UNAV                (        10.0f)
/*! @brief  Assumed maximum ego acceleration in lateral direction in case of an unavoidable collision.
            @typical 8.0f, @unit [m/s^2]*/
#define CD_COLL_EGO_MAX_ACCEL_Y_UNAV                (         8.0f)
/*! @brief  Assumed maximum ego acceleration in longitudinal direction in case of a likely collision.
            @typical 10.0f, @unit [m/s^2]*/
#define CD_COLL_EGO_MAX_ACCEL_X_LIKE                (        10.0f)
/*! @brief  Assumed maximum ego acceleration in lateral direction in case of a likely collision.
            @typical 5.0f, @unit [m/s^2]*/
#define CD_COLL_EGO_MAX_ACCEL_Y_LIKE                (         5.0f)
/*! @brief  Maximal prediction time for the collision / collision unavoidable hypothesis.
            @typical 1.5f, @unit [s]*/
#define CD_COLL_MAX_TIME                            (         1.5f)
/*! @brief  Minimum number of cycles for which an object has been track assigned for a collision hypothesis.
            @typical (3u << 6u)*/
#define CD_COLL_MIN_TRACK_ASSIGNED                  (     1u << 7u)

/*! @brief  Minimum Collision Probability to activate the Collision Bit.
            @typical 0.7f, @range [0,1]*/
#define CD_COLL_PROB_THRESHOLD_MEDIUM               (         0.7f)
/*! @brief  Minimum Collision Probability to activate the Collision Unavoidable Bit.
            @typical 0.7f, @range [0,1]*/
#define CD_COLL_PROB_THRESHOLD_MAXIMUM              (         0.7f)

/****************************************************************
  Run-up Stationary Hypothesis Settings
 *****************************************************************/
/*! @brief  Min. EBA quality to be considered for a run Up Hypothesis.  
            @typical ( @ref CD_COMMON_MIN_OBJ_QUALITY + 1u ), @range [0,100]*/
#define CD_RUN_UP_STAT_MIN_EBA_GEN_OBJ_QUAL         ( CD_COMMON_MIN_OBJ_QUALITY + 1u )
/*! @brief  Min. EBA quality of a stationary object to be considered for a run Up Hypothesis.
            @typical ( @ref CD_RUN_UP_MIN_TRACK_STAT_OBJ_QUALITY + 1u ), 
            @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_RUN_UP_STAT_MIN_EBA_STAT_OBJ_QUAL        ( CD_RUN_UP_MIN_TRACK_STAT_OBJ_QUALITY + 1u )
/*! @brief  Min. EBA quality of a pedestrian to be considered for a run Up Hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_RUN_UP_STAT_MIN_EBA_PED_OBJ_QUAL         (           0u)
/*! @brief  Maximum prediction time for the run up stationary hypothesis.
            @typical 1.5f, @unit [s]*/
#define CD_RUN_UP_STAT_MAX_PRED_TIME                (         1.5f)
/*! @brief  +x-direction search area for object matching.
            @typical 5.0f, @unit [m]*/
#define CD_RUN_UP_STAT_GATE_AHEAD                   (         5.0f)
/*! @brief  -x-direction search area for object matching.
            @typical 5.0f, @unit [m]*/
#define CD_RUN_UP_STAT_GATE_BEHIND                  (         5.0f)
/*! @brief  Maximal TTS to be considered for a run up stationary hypothesis.
            @typical 4.0f, @unit [s]*/
#define CD_RUN_UP_STAT_MAX_TTS                      (         4.0f)
/*! @brief  Maximal TTC to be considered for a run up stationary hypothesis.
            @typical 4.0f, @unit [s]*/
#define CD_RUN_UP_STAT_MAX_TTC                      (         4.0f)
/*! @brief  Minimum class confidence to be considered for a run up stationary hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_RUN_UP_STAT_MIN_OBJ_CLASS_CONF           (           0u)

/****************************************************************
  Pedestrian Collision Hypothesis Settings
 *****************************************************************/
/*! @brief  Assumed maximum Pedestrian Speed.
            @typical 2.2f, @unit [m/s]*/
#define CD_PED_COLL_PED_SPEED_MAX                   (         2.2f)
/*! @brief  Min. EBA quality to be considered for a pedestrian hypothesis
            @typical @ref CD_COMMON_MIN_OBJ_QUALITY, @range [0,100]*/
#define CD_PED_COLL_MIN_EBA_GEN_OBJ_QUAL            (           0u)
/*! @brief  Min. EBA quality of a stationary object to be considered for a pedestrian hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_PED_COLL_MIN_EBA_STAT_OBJ_QUAL           (           0u)
/*! @brief  Min. EBA quality of a pedestrian to be considered for a pedestrian hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_PED_COLL_MIN_EBA_PED_OBJ_QUAL            (           0u)
/*! @brief  Min. class confidence to be considered for a pedestrian hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_PED_COLL_MIN_OBJ_CLASS_CONF              (           0u)
/*! @brief  Maximum TTC to be considered for a pedestrian hypothesis.
            @typical 0u, @range [0,100]*/
//#define CD_PED_MAX_TTC_FILTER                       (         4.0f)
#define CD_PED_MAX_TTC_FILTER                       (         2.4f)
/*
  Defines for Corridor Approach
*/
/*! @brief  Width of On Road Zone.
            @typical 3.3f, @unit [m]*/
#define CD_PED_COLL_ON_ROAD_ZONE_WIDTH              (         3.3f)
/*! @brief  Width of PreBrake Zone.
            @typical 2.6f, @unit [m]*/
#define CD_PED_COLL_PREBRAKE_ZONE_WIDTH             (         2.6f)
/*! @brief  Time until Ped reaches Vehicle Path.
            @typical 0.36f, @unit [s]*/
#define CD_PED_TIME_TO_VEHICLE_PATH_S               (        0.36f)
/*! @brief  Additional escape zone offset.
            @typical 0.3f, @unit [m]*/
#define CD_PED_COLL_ESCAPE_ZONE_OFFSET              (         0.3f)
/* 
  Defines for Probability of Speed Calculation in Pedestrian Collision Hypothesis
*/
/*! @brief  Min Velocity to use for fitting. 
            @typical -4.0f, @unit [m/s]*/
#define CD_PED_COLL_PED_VELO_MIN_MPS                (        -4.0f)
/*! @brief  Max Velocity to use for fitting.
            @typical 4.0f, @unit [m/s]*/
#define CD_PED_COLL_PED_VELO_MAX_MPS                (         4.0f)
/*! @brief  Minimal Std Deviation for VelToTraj used in Ped Hypothesis.
            @typical 0.01f, @unit [m/s]*/
#define CD_PED_COLL_PED_MIN_VELO_TO_TRAJ_STD        (         0.01f)

/*! @brief  Values of maximal VelTo/VelOn -rate dependent of the object dist to vehicle path.
            @typical 2L*/
#define CD_NUMBER_OF_DOMINANTDOWNGRADE_MAX_RATE_VALUES     (           2L)

/*! @brief  Values of maximal velo_to/velo_on -rate dependent of the object dist to vehicle path
            @typical 2L*/
#define CD_NUMBER_OF_DOMINANTDOWNGRADE_MIN_FACTOR_VALUES     (           2L)


/*! @brief  Min object velocity to downgrade (use square of value).
            @typical 1.0f*/
#define CD_PED_COLL_DOM_DG_MIN_OBJ_VELO_MPS                   (       1.0f)

/*! @brief  Number of value pairs in ego additional width (on the inlet corridor side) velocity dependent table.
            @typical 2L */
#define CD_NUMBER_OF_EGO_ADD_WIDTH_IN_VELO_DEP_VALUES         (         2L)

/*! @brief  Number of value pairs in ego additional width (on the outlet corridor side) velocity dependent table.
            @typical 2L */
#define CD_NUMBER_OF_EGO_ADD_WIDTH_OUT_VELO_DEP_VALUES        (         2L)

/*! @brief  Number of value pairs in ego width reduction object velocity to trajectory dependent table.
            @typical 2L */
#define CD_NOF_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_VALUES           (         2L)

/*********************************************************
  Bicycle Hypothesis
************************************************/

/*! @brief  Min. EBA generic quality to be considered for a crossing bicycle hypothesis
            @typical 0u, @range [0,100]*/
#define CD_BICYCLE_COLL_MIN_EBA_GEN_OBJ_QUAL            (           0u)
/*! @brief  Min. EBA generic quality of a stationary object to be considered for a crossing bicycle hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_BICYCLE_COLL_MIN_EBA_STAT_OBJ_QUAL           (           0u)
/*! @brief  Min. EBA generic quality of a pedestrian to be considered for a crossing bicycle hypothesis.
            @typical 0u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_BICYCLE_COLL_MIN_EBA_PED_OBJ_QUAL            (           0u)
/*! @brief  Min. Class confidence of an object to be considered for a crossing bicycle hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_BICYCLE_COLL_MIN_OBJ_CLASS_CONF              (           0u)
/*! @brief  Max. TTC to be considered for a crossing bicycle hypothesis.
            @typical 4.0f, @range [0,1]*/
//#define CD_BICYCLE_MAX_TTC_FILTER                       (         4.0f)
#define CD_BICYCLE_MAX_TTC_FILTER                       (         2.4f)

/*! @brief  Max velocity on/to trajectory rate before downgrade.
            @typical 0.6f, @range [0,1]*/
#define CD_BICYCLE_COLL_DOMINANT_DOWNGRADE_MAX_RATE         (0.6f)
/*! @brief  Min Downgrade Factor.
            @typical 0.5f, @range [0,1]*/
#define CD_BICYCLE_COLL_DOMINANT_DOWNGRADE_MIN_FACTOR       (0.5f)
/*! @brief  Min object velocity to downgrade (use square of value).
            @typical 1.0f, @unit [m/s]*/
#define CD_BICYCLE_COLL_DOMINANT_DOWNGRADE_MIN_OBJ_VELO_MPS (1.0f)

/*! @brief  Min Velocity to use for fitting.
            @typical -6.0f, @unit [m/s]*/
#define CD_BICYCLE_COLL_BICYCLE_VELO_MIN_MPS                (        -6.0f)
/*! @brief  Max Velocity to use for fitting.
            @typical 6.0f, @unit [m/s]*/
#define CD_BICYCLE_COLL_BICYCLE_VELO_MAX_MPS                (         6.0f)

/*! @brief  Minimal Std for VelToTraj used in Bicycle Hypothesis.
            @typical 0.01f, @unit [m/s]*/
#define CD_BICYCLE_COLL_BICYCLE_MIN_VELO_TO_TRAJ_STD        (         0.01f)


/****************************************************************
  Crossing Hypothesis Settings
 *****************************************************************/
/*! @brief  Threshold for the Hypothesis probability to set bitHypActive.
            @typical -0.2f, @range [0,1]*/
#define CD_CROSSING_ACTIVE_THRESHOLD                (               0.2f)
/*! @brief  Min. EBA quality to be considered for a crossing hypothesis.
            @typical 42u, @range [0,100] */
#define CD_CROSSING_MIN_EBA_GEN_OBJ_QUAL            (                42u)
/*! @brief  Min. EBA quality of a stationary object to be considered for a crossing hypothesis.
            @typical 101u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_CROSSING_MIN_EBA_STAT_OBJ_QUAL           (               101u)
/*! @brief  Min. EBA quality of a pedestrian to be considered for a crossing hypothesis.
            @typical 101u, @range [0,100] (101 disables pedestrians for this hypothesis)*/
#define CD_CROSSING_MIN_EBA_PED_OBJ_QUAL            (               101u)
/*! @brief  Min. Probability of existence to be considered for a crossing hypothesis.
            @typical 90u, @range [0,100]*/
#define CD_CROSSING_MIN_POE_QUAL                    (                90u)
/*! @brief  Min. Object class confidence to be considered for a crossing hypothesis.
            @typical 0u, @range [0,100]*/
#define CD_CROSSING_MIN_OBJ_CLASS_CONF              (                 0u)
/*! @brief  Min. velocity to be considered for a crossing hypothesis.
            @typical (10.f/@ref CML_f_Kmh2Ms), @unit [m/s]*/
#define CD_CROSSING_MIN_OBJ_VELOCITY                (  10.f/CML_f_Kmh2Ms)
/*! @brief  Maximum object acceleration of object to move out of situation
            @typical 3.0f, @unit: [m/s^2] */
#define CD_CROSSING_MAX_ACCELERATION_OBJECT         (                3.f)
/*! @brief  Maximum value of deceleration of object to move out of situation.
            @typical -9.0f, @unit: [m/s^2] */
#define CD_CROSSING_MAX_DECELERATION_OBJECT         (               -9.f)
/*! @brief  Minimum value of TTM for Interpolation between 0 and 1 (here for 0).
            @typical 1.0f, @unit: [s] */
#define CD_CROSSING_MIN_TTM_INTERP                  (               1.0f)
/*! @brief  Maximum value of TTM for Interpolation between 0 and 1 (here for 1).
            @typical 0.0f, @unit: [s] */
#define CD_CROSSING_MAX_TTM_INTERP                  (               0.0f)
/*! @brief  Min Angle for objects to be considered for hypCrossing.
            @typical (DEG2RAD(27.f)), @unit: [rad] */
#define CD_CROSSING_MIN_ANGLE                       (      DEG2RAD(27.f))
/*! @brief  Min xDistance for objects to be considered for the crossing hypothesis.
            @typical 12.0f, @unit: [m] */
#define CD_CROSSING_MIN_DISTX                       (               12.f)
/*! @brief  Min velocity for objects to be considered for the crossing hypothesis.
            @typical (15.f/@ref CML_f_Kmh2Ms), @unit: [m/s] */
#define CD_CROSSING_MIN_BIKE_VELOCITY               (   15.f/CML_f_Kmh2Ms)
/*! @brief  Number of track assignments of stopped objects to be considered for a crossing hypothesis.
            @typical (7u << 5u) */
#define CD_CROSSING_STOPPED_OBJ_TRACK_ASSIGNED      (           7u << 5u)
/*! @brief  Ego corridor width for environment filter.
            @typical 1.5f, @unit: [m] */
#define CD_CROSSING_FILTER_EGO_CORRIDOR_WIDTH       (               1.5f)
/*! @brief  Object EBA Quality for environment filter.
            @typical 42u, @range: [0,100] */
#define CD_CROSSING_FILTER_OBJECT_OBJ_QUAL          (                42u)
/*! @brief  Probability Of Existence for environment filter.
            @typical 90u, @range: [0,100] */
#define CD_CROSSING_FILTER_OBJECT_POE_QUAL          (                90u)
/*! @brief  Number of needed oncoming confirmations.
            @typical 5u*/
#define CD_CROSSING_NEEDED_ONCOMMING_CONFIRMATIONS  (                 5u)
/*! @brief  Was Crossing Counter Threshold.
            @typical 5u */
#define CD_CROSSING_WASCROSSING_COUNTER_THRESHOLD   (                 5u)
/*! @brief  Number by which the crossing counter is increased every cycle.
            @typical 2u */
#define CD_CROSSING_COUNTER_INCREASE                (                 2u)
/*! @brief  Maximum number of the crossing counter.
            @typical 200u */
#define CD_CROSSING_MAX_COUNTER_INT                 (               200u)
/*! @brief  Maximum TTC to be considered for the crossing hypothesis.
            @typical 2.0f, @unit: [s] */
#define CD_CROSSING_OBJECT_TTC_THRSHLD              (               2.0f)
/*! @brief  Maximum Angle to be considered for the crossing hypothesis.
            @typical DEG2RAD(48.0f), @unit: [rad] */
#define CD_CROSSING_OBJECT_ANGLE_THRSHLD            (     DEG2RAD(48.0f))
/*! @brief  Maximum DistY to be considered for the crossing hypothesis.
            @typical 15.0f, @unit: [m] */
#define CD_CROSSING_OBJECT_DISTY_THRSHLD            (              15.0f)
/*! @brief  Maximum lateral velocity at which an object can be discarded for the crossing hypothesis due to its HypCat.
            @typical 7.0f, @unit: [m/s] */
#define CD_CROSSING_HYP_CAT_VELOCITY_THRESHOLD      (               7.0f)
/*! @brief  Cam Confirmation Threshold for crossing objects.
            @typical 97u, @range: [0,100] */
#define CD_CROSSING_CAM_CONFIRMATION_PROB_THRSHLD   (                97u)
/*! @brief  Ego velocity camera confirmation acceleration Threshold for crossing objects.
            @typical (52.0f/@ref CML_f_Kmh2Ms), @unit [m/s]*/
#define CD_CROSSING_EGO_VEL_CAM_ACCEL_THRSHLD       (  52.f/CML_f_Kmh2Ms)
/*! @brief  Cam Confirmation Acceleration Threshold for crossing objects.
            @typical 1.0f*/
#define CD_CROSSING_CAM_ACCEL_THRSHLD               (               1.0f)

/****************************************************************
  Oncoming Hypothesis Settings
 *****************************************************************/
/*! Min. EBA generic quality */
#define CD_HYP_ONCOMING_MIN_EBA_GEN_OBJ_QUAL          ( CD_COMMON_MIN_OBJ_QUALITY + 1u )
/*! Min. EBA stationary quality */
#define CD_HYP_ONCOMING_MIN_EBA_STAT_OBJ_QUAL         (          0u)
/*! Min. EBA pedestrian quality */
#define CD_HYP_ONCOMING_MIN_EBA_PED_OBJ_QUAL          (        101u)
/*! Threshold for Hypothesis to enter bitHypActive*/
#define CD_HYP_ONCOMING_ACTIVE_THRESHOLD              (        0.1f)
/*! Threshold for pre-selection of objects for crossing hypothesis */
#define CD_HYP_ONCOMING_MIN_OBJ_CLASS_CONF            (         10u)
/*! Number of object filters for track assignment */
#define CD_HYP_ONCOMING_CLASS_FILTERS_NO              (          1u)

/****************************************************************
  Turn into oncoming VRU (CPTA) hypothesis settings
  @attention: name has been decided to be VRU but in fact defines and filters tailored to pedestrians only
 *****************************************************************/
/*! @brief  Min. EBA quality to be considered for a turn into vru hypothesis
            @typical @ref CD_COMMON_MIN_OBJ_QUALITY, @range [0,100]*/
#define CD_TURNINTOVRU_MIN_EBA_GEN_OBJ_QUAL                       (           0u)

/*! @brief  Min. EBA quality of a stationary object to be considered for a turn into vru hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_TURNINTOVRU_MIN_EBA_STAT_OBJ_QUAL                      (           0u)

/*! @brief  Min. EBA quality of a pedestrian to be considered for a turn into vru hypothesis.
            @typical 0u, @range [0,100] */
#define CD_TURNINTOVRU_MIN_EBA_PED_OBJ_QUAL                       (           0u)

/*! @brief  Min. class confidence to be considered for a turn into turn into vru hypothesis.
            @typical 0u, @range [0,100] */
#define CD_TURNINTOVRU_MIN_OBJ_CLASS_CONF                         (           0u)

/*! @brief  Maximum TTC to be considered for a turn into vru hypothesis.
            @typical 4f, @range [0,100] */
#define CD_TURNINTOVRU_MAX_TTC_FILTER                             (         4.0f)

/*! @brief      Minimum required cycles of psc prob. history of an object 
*               to be considered for Turn into oncoming VRU hypothesis.
                @typical (63u << 2u)*/
#define CD_TURNINTOVRU_MIN_COLL_CONFIRM                           (    63u << 2u)
/*! @brief      Cosine of the angle between obj. velocity vector and vector from
 *              object to collision point above which the confidence equals 1.
                @typical     0.86f  (cos(30°))  */
#define CD_TURNINTOVRU_COS_MAX_CONF_ANGL                          (        0.86f)
/*! @brief      Cosine of the angle between obj. velocity vector and vector from
 *              object to collision point below which the confidence equals 0.
                @typical     0.34f  (cos(70°))  */
#define CD_TURNINTOVRU_COS_NO_CONF_ANGL                           (        0.34f)
/*! @brief      Distance of object to collision point below which confidence value
 *              is ignored
 *              @typical    1.0f */
#define CD_TURNINTOVRU_DIST_IGNR_CONF                             (        1.0f)
/*! @brief      Distance of object to collision point above which confidence value
 *              is completely taken into account
 *              @typical    1.5f */
#define CD_TURNINTOVRU_DIST_FULL_CONF                             (        1.5f)
/*! @brief      The minimum allowed object absolute velocity to build a turn into vru hypothesis.
 *              @typical    0.4f */
#define CD_TURNINTOVRU_OBJ_ABS_VEL_MIN                            (        0.40f)
/*! @brief      Number of entries in the parameter lookup table for the ego Turning detection threshold
                @typical    4L */
#define CD_EGO_DRV_CRV_TRN_THRE_NO                                (           4L)

/*! @brief      Number of entries in the parameter lookup table for keep threshold of the ego Turning detection
                @typical    4L */
#define CD_EGO_DRV_CRV_KEEP_TRN_THRE_NO                           (           4L)

/*! @brief      Number of entries in the parameter lookup table for the distance to block the detection of turn on the opposite direction
                @typical    4L */
#define CD_EGO_DRV_CRV_BLK_OPP_DIR_NO                             (           2L)

/*! @brief      The low pass filter factor for the vdy curve used for the turning curve detection
                @typical    0.4f */
#define CD_FILTER_FACTOR_EGO_CRV                                  (         0.4f)

/*! @brief      The maximum ego-vehicle speed for the detection of turning scenario
                @typical    40.0f/3.6f */
#define CD_EGO_DRV_CRV_VEL_MAX                                    (   40.0f/3.6f)

/*! @brief  Minimum hypothesis probability for TurnIntoVRU hypothesis to be considered.
            @typical 0.5f */
#define CD_TURNINTOVRU_MIN_HYP_PROB                               (         0.5f)

/****************************************************************
  Drive into Slow Moving hypothesis settings
 *****************************************************************/
/*! @brief  Min. EBA quality to be considered for a drive into slow moving hypothesis.
            @typical @ref CD_COMMON_MIN_OBJ_QUALITY, @range [0,100]*/
#define CD_DRIVEINTOSLOMO_MIN_EBA_GEN_OBJ_QUAL         ( CD_COMMON_MIN_OBJ_QUALITY + 1u )

/*! @brief  Min. EBA quality of a stationary object to be considered for a drive into slow moving hypothesis.
            @typical 0u, @range [0,100] (101 disables stationary objects for this hypothesis)*/
#define CD_DRIVEINTOSLOMO_MIN_EBA_STAT_OBJ_QUAL        (           0u)

/*! @brief  Min. EBA quality of a pedestrian to be considered for a drive into slow moving hypothesis.
            @typical 0u, @range [0,100] */
#define CD_DRIVEINTOSLOMO_MIN_EBA_PED_OBJ_QUAL         (           0u)

/*! @brief  Min. class confidence to be considered for a drive into slow moving hypothesis.
            @typical 0u, @range [0,100] */
#define CD_DRIVEINTOSLOMO_MIN_OBJ_CLASS_CONF           (           0u)

/*! @brief  Max xDistance for objects to be considered for a drive into slow moving hypothesis.
            @typical 7.0f, @unit: [m] */
#define CD_DRIVEINTOSLOMO_MAX_DISTX                    (         7.0f)

/*! @brief  Maximum Ego Velocity to be considered for a drive into slow moving hypothesis.
            @typical 15.0f/3.6f, @unit [m/s] */
#define CD_DRIVEINTOSLOMO_MAX_V_EGO                    (   15.0f/3.6f)

/*! @brief  Maximum Absolute Object Velocity to be considered for a drive into slow moving hypothesis.
            @typical 5.0f/3.6f, @unit [m/s] */
#define CD_DRIVEINTOSLOMO_MAX_V_ABS                    (    5.0f/3.6f)

/****************************************************************
             Probability of Speed Concept Settings
 *****************************************************************/

/*! @brief  Number of Y-distance values of every object to observe to fit velocities. 
            @typical 5u*/
#define CD_PSC_PROB_OBSERVE_Y_DIST_N                (            5u )
/*! @brief  Number of Steps between min and max velocity to use for fitting. The value is to be odd number.
            @typical 35u, @range [3,+...[*/
#define CD_PSC_PROB_VELO_STEPS_N                    (           35u )
/*! @brief  Maximum velocity considered for the probability of speed concept.
            @typical 100.0f*/
#define CD_PSC_PROB_VELO_MAX                        (        100.0f )
/*! @brief  The velocity gate, range of the velocity distribution.
            @typical 10.0f, @unit [m/s]*/
#define CD_PSC_VEL_GATE                             (         10.0f )
/*! @brief  Velocity range of one velocity step.
            @typical ((@ref CD_PSC_VEL_GATE) / (float32)(@ref CD_PSC_PROB_VELO_STEPS_N -1u)), @unit [m/s]*/
#define CD_PSC_STEP_SIZE_VELOCITY                   ((CD_PSC_VEL_GATE) / (float32)(CD_PSC_PROB_VELO_STEPS_N-1u))

/************************************************************************/
/* Hypothesis relation settings                                         */
/************************************************************************/

/* ACC to RunupStationary Hypothesis */


/*! @brief       Max time after the ACC hypothesis is lost, until the RunupStat hypothesis gets fully functional again 
    @conseq      @incp  May lead to more real world usecase loss which cannot be detected using endurance and usecase test approach
    @typical     10   @unit s     @min 0   @max 100   */
#define CD_HYPREL_ACC2RUNUPSTAT_MAX_SUPPRESS_TIME  (0.01F)

/*! @brief       Max hypothesis probability
    @conseq      @incp  hypothesis may trigger a reaction. Check in HEAD.
    @typical     0.3   @unit Percentage     @min 0   @max 1   */
#define CD_HYPREL_ACC2RUNUPSTAT_SUPPRESS_HYP_PROB  (0.9f)


/****************************************************************
  Common Hypothesis Handler and Object Filter Settings
 *****************************************************************/

/*! @brief Total number of hypothesis handlers */
#define CD_HYP_HANDLERS_NO ( \
            CD_USE_RUN_UP_HYPOTHESIS \
          + CD_USE_CUT_IN_HYPOTHESIS \
          + CD_USE_PASS_HYPOTHESIS \
          + CD_USE_FOLLOW_HYPOTHESIS \
          + CD_USE_COLL_HYPOTHESIS \
          + CD_USE_RUN_UP_STAT_HYPOTHESIS \
          + CD_USE_ACC_HYPOTHESIS \
          + CD_USE_PED_COLL_HYPOTHESIS \
          + CD_USE_CROSSING_HYPOTHESIS \
          + CD_USE_BICYCLE_COLL_HYPOTHESIS \
          + CD_USE_LONG_COLL_HYPOTHESIS\
          + CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS\
          + CD_USE_TURNINTOVRU_HYPOTHESIS \
          + CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS \
          )


/****************************************************************
  Track Assignment Settings
 *****************************************************************/

/*! @brief  Minimum track overlap for track assignment.
            @typical 0.75f, @range [0,1]*/
#define CD_TRKASGN_MIN_TRACK_OVERLAP                (        0.75f)
/*! @brief  Minimum object overlap for track assignment.
            @typical 0.75f, @range [0,1]*/
#define CD_TRKASGN_MIN_OBJECT_OVERLAP               (         0.5f)
/*! @brief  Offset for predicted track overlap, i.e. allowed error.
            @typical -0.25f, @range [-1,1]*/
#define CD_TRKASGN_TRACK_OVERLAP_PRED_OFFSET        (       -0.25f)
/*! @brief  Offset for predicted object overlap, i.e. allowed error.
            @typical -0.35f, @range [-1,1]*/
#define CD_TRKASGN_OBJ_OVERLAP_PRED_OFFSET          (       -0.35f)
/*! @brief  Minimum lateral velocity for avoidance maneuvers.
            @typical 0.9f, @unit [m/s]*/
#define CD_TRKASGN_MIN_LAT_AVOID_SPEED              (         0.9f)
/*! @brief  Maximum object distance for a detection of a avoidance maneuver.
            @typical 20.0f, @unit [m]*/
#define CD_TRKASGN_MAX_AVOID_DIST                   (        20.0f)
/*! @brief  Maximum TTC for a detection of a avoidance maneuver.
            @typical 3.0f, @unit [m]*/
#define CD_TRKASGN_MAX_AVOID_TTC                    (         3.0f)
/*! @brief  Minimum curve radius for rad estimation based track assignment. In case of smaller 
            radii the track assign algorithms uses the ego trajectory for stationary objects.
            @typical 700.0f, @unit [m]*/
#define CD_TRKASGN_MIN_RAD_FOR_ROAD_TRAJ            (       700.0f) 
/*! @brief  Max prediction time for track assignment.
            @typical 1.5f, @unit [s]*/
#define CD_TRKASGN_CURVE_OVRLAP_PRED_TIME           (         1.5f)
/*! @brief  Maximum prediction time for track assignment of stationary objects when driving straight ahead.
             @typical 0.35f, @unit [s]*/
#define CD_TRKASGN_STRAIGHT_OVRLAP_PRED_TIME        ( CD_TRKASGN_CURVE_OVRLAP_PRED_TIME - 1.0f )

/*! @brief CD_TRKASGN_PROB_THRESHOLD */
#define CD_TRKASGN_PROB_THRESHOLD                   (         0.2f)

/*! @brief  Relative Reduction of Corridor to calculate Track Assignment
            @typical 0.3f, @range [0,1]*/
#define CD_TRKASGN_CORRIDOR_REDUCTION_PERC          (         0.3f)

/*! @brief  Maximum object width during the calculation of the track assignment.
            @typical 2.0f, @unit [m]*/
#define CD_MAX_OBJ_WIDTH_STAT                       (           1.8f)


/****************************************************************
  PSC Collision Probability History Settings
 *****************************************************************/
/*! @brief  The Threshold of PSC collision probability for setting the PSC collision probability history bit 
*           for the current cycle.
            @typical CD_TURNINTOVRU_MIN_HYP_PROB-0.15f, @range [0,1]*/
#define CD_THRSHLD_PSC_COL_PROB_HIST               ( CD_TURNINTOVRU_MIN_HYP_PROB - 0.15f )

/*! @brief  Maximum TTC to be considered for a the update of the PSC collision probability history bit 
*           for the current cycle.
            @typical 4f, @unit: [s]*/
#define CD_MAX_TTC_PSC_COL_PROB_HIST               (                                4.0f )

/*! @brief  Maximum Ego velocity to be considered for a the update of the PSC collision probability history bit 
*           for the current cycle.
            @typical 14.0f, @unit: [m/s]*/
#define CD_MAX_VEL_EGO_PSC_COL_PROB_HIST           (                               14.0f )

/*! @brief  Maximum Object velocity to be considered for a the update of the PSC collision probability history bit 
*           for the current cycle.
            @typical 10.0f, @unit: [m/s]*/
#define CD_MAX_VEL_OBJ_PSC_COL_PROB_HIST           (                               10.0f )

/*! @brief  The minimum object velocity to trajectory to consider the object as stationary, 
*           which corresponds to the maximum distance to trajectory @ref CD_DMAX_STAT_OBJ_PSC_COL_PROB_HIST.
            @typical 0.0f, @unit: [m/s]*/
#define CD_VEL_STAT_OBJ_PSC_COL_PROB_HIST          (                               0.0f  )

/*! @brief  The maximum distance to trajectory for stationary object, above which the PSC collision probability history
*           is not evaluated for this cycle.
            @typical 2.0f, @unit: [m]*/
#define CD_DMAX_STAT_OBJ_PSC_COL_PROB_HIST         (                               2.0f  )

/*! @brief  The maximum assumed object(VRU) velocity to trajectory which corresponds to the maximum distance to trajectory 
*           @ref CD_DMAX_MAX_VEL_PSC_COL_PROB_HIST.
            @typical 6.0f, @unit: [m/s]*/
#define CD_MAX_VEL_VRU_PSC_COL_PROB_HIST           (                               6.0f  )

/*! @brief  The maximum distance to trajectory for object with the maximum assumed VRU velocity to trajectory @ref CD_MAX_VEL_VRU_PSC_COL_PROB_HIST, 
*           above which the PSC collision probability history is not evaluated for this cycle.
            @typical 26.0f, @unit: [m]*/
#define CD_DMAX_MAX_VEL_PSC_COL_PROB_HIST          (                               26.0f )

/****************************************************************
  Object Merge Settings (cd_wrapper.c)
 *****************************************************************/

/*! @brief  If delete/keep lifetime percentage is above this threshold, a Critical time after merge is calculated.
            @typical 0.3f, @range: [0,1]*/
#define CD_OBJ_MERGE_CRIT_TIME_THRES_PERC           (         0.3f)
/*! @brief  Min. lifetime of objects to consider merge to be critical.
            @typical 1.33f, @unit: [s]*/
#define CD_OBJ_MERGE_CRIT_MERGE_MIN_OBJ_LFT         (        1.33f)
/*! @brief  Lateral distance to define critical obj. merge time lower boundary.
            @typical 1.0f, @unit: [m]*/
#define CD_OBJ_MERGE_CRIT_TIME_THRES_DISTY_0        (         1.0f)
/*! @brief  Critical merge time lower boundary.
            @typical 0.0f, @unit: [s]*/
#define CD_OBJ_MERGE_CRIT_TIME_THRES_TIME_0         (         0.0f)
/*! @brief  Lateral distance to define critical obj. merge time upper boundary.
            @typical 3.0f, @unit: [m]*/
#define CD_OBJ_MERGE_CRIT_TIME_THRES_DISTY_1        (         3.0f)
/*! @brief  Critical merge time upper boundary.
            @typical 30.0f, @unit: [s]*/
#define CD_OBJ_MERGE_CRIT_TIME_THRES_TIME_1         (        30.0f)



/****************************************************************
  EPF - Evasion Possibility Front Settings
 *****************************************************************/
/*! @brief  Maximum Distance (m) for evasion Corridor in case of no Obstacle.
            @typical 5.0f, @unit: [m]*/
#define CD_EPF_MAX_LAT_CORR_WIDTH                   (         5.0f)
/*! @brief  Minimum Obstacle Probability of Existence to be considered by EPF.
            @typical 50u, @range: [0,100]*/
#define CD_EPF_OBSTACLE_MIN_POE                     (          50u)
/*! @brief  Maximum Distance (m) for evasion Corridor in case of no Obstacle.
            @typical 3.0f, @unit: [m]*/
#define CD_EPF_MAX_LAT_PRED_OFFSET                  (         3.0f)
/*! @brief  Maximum TTC (TimeToCollision) the relevant Object is allowed to have to calculate the evasion Corridors.
            @typical 4.0f, @unit: [s]*/
#define CD_EPF_MAX_TTC                              (         4.0f)

/*
  Specific defines for Camera EPF
*/

/*! @brief  Safety Distance for Target and normal Traffic Objects.
            @typical 0.5f, @unit: [m]*/
#define CD_EPF_SAFETY_DIST                          (         0.5f) 
/*! @brief  Safety Distance for weak Traffic Objects like Pedestrians.
            @typical 1.0f, @unit: [m]*/
#define CD_EPF_SAFETY_DIST_EXT                      (         1.0f) 
/*! @brief  Distance in front of Target that has to be free of Obstacles.
            @typical 10.0f, @unit: [m]*/
#define CD_EPF_LONG_SAFETY_DIST                     (        10.0f) 
/*! @brief  ANecLong at which the probability of a free corridor is multiplied by 0.
            @typical -8.0f, @unit: [m/s^2]*/
#define CD_EPF_CRITICAL_ANECLONG                    (        -8.0f) 
/*! @brief  Maximum Distance for Objects in front of the Target to penetrate the Inside of the evasion Corridor.
            @typical 0.4f, @unit: [m]*/
#define CD_EPF_MAX_INSIDE_REDUCTION                 (         0.4f) 

/*
  Specific defines for Radar EPF
*/

/*!@brief Safety Distance for Target.
          @typical 0.5f, @unit: [m]*/
#define CD_EPF_TARGET_SAFETY_DIST                   (         0.5f)
/*!@brief Lateral safety Extension of Ego evasion Corridor.
          @typical 1.8f, @unit: [m]*/
#define CD_EPF_EGO_CORRIDOR_SAFETY_EXTENSION        (         1.8f)
/*!@brief Safety Distance for Target and normal Traffic Objects.
          @typical 0.5f, @unit: [m]*/
#define CD_EPF_OBJ_SAFETY_DIST                      (         0.2f) 
/*!@brief Safety Distance for weak Traffic Objects like Pedestrians.
          @typical 1.0f, @unit: [m]*/
#define CD_EPF_VULNERABLE_OBJ_SAFETY_DIST           (         0.2f)  
/*!@brief Minimum Obstacle Probability of Existence of Point Objects to be considered by EPF.
          @typical 90u, @range: [0,100]*/
#define CD_EPF_POINT_OBSTACLE_MIN_POE               (          90u)
/*!@brief Longitudinal Distance Factor for total length of Area behind Target.
          @typical 3.0f*/
#define CD_EPF_MAX_LONG_DIST_FACTOR                 (         3.0f)
/*!@brief Maximum Distance for Objects in front of the Target to penetrate the Inside of the evasion Corridor.
          @typical 0.6f, @unit: [m]*/
#define CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET     (         0.6f)
/*!@brief Overlap Distance in front of ego vehicle of the center safety zones.
          @typical 0.2f, @unit: [m]*/
#define CD_EPF_CENTER_ZONE_OVERLAP                  (         0.2f)
/*!@brief Overlap Distance in front of ego vehicle of the center safety zones.
          @typical 2.0f, @unit: [m]*/
#define CD_EPF_OBJ_WIDTH_LIMIT                      (         2.0f)
/*!@brief ANecLong at which the probability of a free corridor is multiplied by 0.
          @typical -1.0f, @unit: [m/s^2]*/
#define CD_EPF_OBJECT_ANECLONG_THRES                (        -1.0f)
/*!@brief Minimum Ego Velocity to calculate evasion possibility.
          @typical 4.0f, @unit: [m/s]*/
#define CD_EPF_MIN_V_EGO                            (         4.0f)
/*!@brief Maximum Ego Velocity to calculate evasion possibility.
          @typical 44.5f, @unit: [m/s]*/
#define CD_EPF_MAX_V_EGO                            (        44.5f)
/*!@brief Maximum Longitudinal Distance to Target to calculate evasion possibility.
          @typical 240.0f, @unit: [m]*/
#define CD_EPF_MAX_LONG_DIST_TO_TARGET              (       240.0f)
/*!@brief Maximum absolute Yaw Rate at which DistToTraj Calculation is favored.
          @typical 0.02f, @unit: [rad/s]*/
#define CD_EPF_DIST_TO_TRAJ_YAW_RATE                (        0.02f)

/*!@brief TTB Threshold at which corridors are frozen.
          @typical 0.0f, @unit: [s]*/
#define CD_EPF_CORRIDOR_FREEZE_TTB_THRES            (         0.0f)
/*!@brief TTS Threshold at which corridors are frozen.
          @typical 0.0f, @unit: [s]*/
#define CD_EPF_CORRIDOR_FREEZE_TTS_THRES            (         0.0f)

/****************************************************************
  Measurement Settings
 *****************************************************************/

#ifndef FCT_MEAS_ID_CGEB_CD_DATA
/*! @brief FCT_MEAS_ID_CGEB_CD_DATA */
#define FCT_MEAS_ID_CGEB_CD_DATA                    (0x2022A000u)
#endif /* FCT_MEAS_ID_CGEB_CD_DATA */

#ifndef FCT_MEAS_ID_CGEB_CD_HYPOTHESES
/*! @brief FCT_MEAS_ID_CGEB_CD_HYPOTHESES */
#define FCT_MEAS_ID_CGEB_CD_HYPOTHESES              (FCT_MEAS_ID_CGEB_CD_DATA + 0x0u)
#endif

#ifndef FCT_MEAS_ID_CGEB_CD_INT_OBJ_DATA
/*! @brief FCT_MEAS_ID_CGEB_CD_INT_OBJ_DATA */
#define FCT_MEAS_ID_CGEB_CD_INT_OBJ_DATA            (0x202CA980)
#endif /* FCT_MEAS_ID_CGEB_CD_INT_OBJ_DATA */

#ifndef FCT_MEAS_ID_CGEB_CD_WRAP_DATA
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_DATA */
#define FCT_MEAS_ID_CGEB_CD_WRAP_DATA               (0x20250000u)
#endif /* FCT_MEAS_ID_CGEB_CD_WRAP_DATA */

/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_STATE */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_STATE           (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x0u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_KIN_OBJ */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_KIN_OBJ     (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x100u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_ATTR_OBJ*/
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_ATTR_OBJ    (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x200u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_DIM_OBJ */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_DIM_OBJ     (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x300u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_QUAL_OBJ */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_QUAL_OBJ        (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x400u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_ADD_QUAL_OBJ */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_ADD_QUAL_OBJ    (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x500u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_EGO_TRAJ */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_EGO_TRAJ    (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x600u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_ROAD_TRAJ */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_ROAD_TRAJ   (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x900u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_INT         (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0xE00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_DYN_RAW */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_DYN_RAW     (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1000u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_DYN_SYNC */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_DYN_SYNC    (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1100u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_TRAJ_RAW */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_TRAJ_RAW    (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1200u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_ROAD_TRAJ_RAW */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_ROAD_TRAJ_RAW   (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1300u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_ROAD_TRAJ_RAW */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_TRAJ_SYNC   (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1400u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_DYN_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_EGO_DYN_INT     (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1500u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_INP_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_INP_INT         (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1600u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_ADJ_SAFE_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_ADJ_SAFE_INT    (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1700u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_PAR_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_PAR_INT         (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1800u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_EXT_FUN */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_EXT_FUN         (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1900u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_MATH_FUN */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_MATH_FUN        (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1A00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_REL_HYP_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_REL_HYP_INT     (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1B00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_DATA */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_DATA        (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1C00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_PAR */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_PAR         (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1C50u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_RAW */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_RAW         (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1C90u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_FILT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_CRV_FILT        (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1CD0u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_LANE */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_OBJ_LANE        (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x1E00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_COLL_MODEL_INT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_COLL_MODEL_INT  (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x7B00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_STATE */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_INT_STATE       (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x7C00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_OUT_DATA */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_OUT_DATA        (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x7D00u)
/*! @brief FCT_MEAS_ID_CGEB_CD_WRAP_CD_REL_OBJ_OUT */
#define FCT_MEAS_ID_CGEB_CD_WRAP_CD_REL_OBJ_OUT     (FCT_MEAS_ID_CGEB_CD_WRAP_DATA + 0x7D10u)

///@}

#endif /*(ACDC_CFG_CD)*/

#endif /* CD_PAR_H_INCLUDED */

