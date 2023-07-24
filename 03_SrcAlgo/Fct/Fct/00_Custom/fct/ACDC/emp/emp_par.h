/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP (Environment Prediction Model)

PACKAGENAME:               emp_par.h

DESCRIPTION:               EMP parameters

AUTHOR:                    $Author: uid41765 $

CREATION DATE:             $Date: 2018/07/24 13:24:19CEST $

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.22

**************************************************************************** */
#ifndef EMP_PAR_H_INCLUDED
#define EMP_PAR_H_INCLUDED

#include "acdc_par.h"
#include "emp_cfg.h"

#if (ACDC_CFG_EMP)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup emp_par Parameter
@ingroup emp
@brief    Contains all Parameters that are used in the EMP subcomponent.\n\n
@{
*/
/*****************************************************************************
  MACROS 
*****************************************************************************/
/*! @brief        Default X-Variance for the coefficient \f$C_0\f$ of the 
                  polynome \f$C_2\cdot x^2 + C_1\cdot x + C_0\f$

    - @typical    0.0
    - @unit       div
       */
#define EMP_DEFAULT_EGO_VAR_X_C0                      (0.0f)

/*! @brief        Default X-Variance for the coefficient \f$C_1\f$ of the 
                  polynome \f$C_2\cdot x^2 + C_1\cdot x + C_0\f$

    - @typical    0.05
    - @unit       div
       */
#define EMP_DEFAULT_EGO_VAR_X_C1                      (0.05f)

/*! @brief        Default X-Variance for the coefficient \f$C_2\f$ of the 
                  polynome \f$C_2\cdot x^2 + C_1\cdot x + C_0\f$

    - @typical    0.0
    - @unit       div
       */
#define EMP_DEFAULT_EGO_VAR_X_C2                      (0.0f)

/*! @brief        Default Y-Variance for the coefficient \f$C_0\f$ of the 
                  polynome \f$C_2\cdot x^2 + C_1\cdot x + C_0\f$

    - @typical    0.0
    - @unit       div
       */
#define EMP_DEFAULT_EGO_VAR_Y_C0                      (0.0f)

/*! @brief        Default Y-Variance for the coefficient \f$C_1\f$ of the 
                  polynome \f$C_2\cdot x^2 + C_1\cdot x + C_0\f$

    - @typical    0.1
    - @unit       div
       */
#define EMP_DEFAULT_EGO_VAR_Y_C1                      (0.1f)

/*! @brief        Default Y-Variance for the coefficient \f$C_2\f$ of the 
                  polynome \f$C_2\cdot x^2 + C_1\cdot x + C_0\f$

    - @typical    0.0
    - @unit       div
       */
#define EMP_DEFAULT_EGO_VAR_Y_C2                      (0.0f)

/*! @brief        EMP maximum YAW rate for ABS

    - @typical    0.6
    - @unit       [rad/s]
       */
#define EMP_YAW_RATE_ABS_MAX                          (0.6f)

/*! @brief        EMP minimum EGO prediction time

    - @typical    1.0
    - @unit       [s]
       */
#define EMP_PREDICTION_TIME_EGO_MIN                   (1.0f)

/*! @brief        EMP maximum EGO prediction time

    - @typical    8.0
    - @unit       [s]
       */
#define EMP_PREDICTION_TIME_EGO_MAX                   (1000.0f)

/*! @brief        EMP prediction Objects default time

    - @typical    2.0
    - @unit       [s]
       */
#define EMP_PREDICTION_OBJECTS_DEFAULT                (2.0f)

/*! @brief        EMP maximum angle degree

    - @typical    90.0
    - @range      ?
    - @unit       [degree]
       */
#define EMP_MAX_ANGLE_DEGREE                         (90.0f)

/*! @brief        EMP Object distance corridor, velocity to trajectory

    - @typical    5.0
    - @range      [0,+...[
    - @unit       [m]
       */
#define EMP_OBJ_DIST_CORR_VEL2TRAJ                    (5.0f)

/*! @brief        EMP no. of corridor prediction steps.

    - @typical    15
    - @range      [0,+...[
    - @unit       [ ]
       */
#define EMP_CORRIDOR_PREDICTION_STEPS                   (15)

/*! @brief        EMP longitudinal acceleration of ego vehicle at a comfort braking maneuver.

    - @typical    -3.0
    - @range      ]-...,0]
    - @unit       [m/s^2]
       */
#define EMP_EGO_LONG_ACCEL_COMFORT_BRAKING           (-3.0f)

/*! @brief        EMP longitudinal acceleration of ego vehicle at a full braking maneuver.

    - @typical    -10.0
    - @range      ]-...,0]
    - @unit       [m/s^2]
       */
#define EMP_EGO_LONG_ACCEL_FULL_BRAKING             (-10.0f)

/*! @brief        EMP longitudinal acceleration of ego vehicle at a medium braking maneuver.

    - @typical    -5.0
    - @range      ]-...,0]
    - @unit       [m/s^2]
       */
#define EMP_EGO_LONG_ACCEL_AVOIDANCE_MEDIUM_BRAKING  (-5.0f)

/*! @brief        EMP lateral acceleration at a medium braking maneuver.

    - @typical    2.0
    - @range      [0,+...[
    - @unit       [m/s^2]
       */
#define EMP_EGO_LAT_ACCEL_AVOIDANCE_MEDIUM_BRAKING    (2.0f)

/*! @brief        EMP longitudinal acceleration at a maximum braking maneuver

    - @typical    -7.0
    - @range      ]-...,0]
    - @unit       [m/s^2]
       */
#define EMP_EGO_LONG_ACCEL_AVOIDANCE_MAX_BRAKING     (-7.0f)

/*! @brief        EMP lat acceleration avoidance maximum braking

    - @typical    4.0
    - @range      [0,+...[
    - @unit       [m/s^2]
       */
#define EMP_EGO_LAT_ACCEL_AVOIDANCE_MAX_BRAKING       (4.0f)

/*! @brief        EMP avoidance prediction time

    - @typical    0.5
    - @range      [0,+...[
    - @unit       [s]
       */
#define EMP_AVOIDANCE_PREDICTION_TIME                 (0.5f)

/*! @brief        EMP object brake jerk time

    - @typical    1.0
    - @range      [0,+...[
    - @unit       [s]
       */
#define EMP_OBJ_BRAKE_JERK_TIME                       (1.0f)

/*! @brief        EMP object velocity decrease at a medium brake jerk

    - @typical    (30.0 / 3.6)
    - @range      [0,+...[
    - @unit       [m/s]
       */
#define EMP_OBJ_BRAKE_JERK_MEDIUM                     (30.0f / 3.6f)


/*! @brief        EMP object velocity decrease at a intense brake jerk

    - @typical    (50.0 / 3.6)
    - @range      [0,+...[
    - @unit       [m/s]
       */
#define EMP_OBJ_BRAKE_JERK_INTENSE                    (50.0f / 3.6f)

/*! @brief        EMP object acceleration for a brake maneuver with comfort brake acceleration.

    - @typical    -3.0
    - @range      ]-...,0]
    - @unit       [m/s^2]
       */
#define EMP_OBJ_BRAKE_DECEL_COMFORT                   (-3.0f)

/*! @brief        EMP object acceleration for a full braking maneuver

    - @typical    -10.0
    - @range      ]-...,0]
    - @unit       [m/s^2]
       */
#define EMP_OBJ_BRAKE_DECEL_FULL                     (-10.0f)

/* EMPLEGACY */
#define EMPLEG_OBJ_CLASS_MIN_CONF_WIDTH_SEC           (        95u)


#define EMPLEG_OBJECT_CLASS_CAR	                      (1u)
#define EMPLEG_OBJECT_CLASS_TRUCK	                    (2u)

#define EMPLEG_CAR_WIDTH_SEC                          (       1.5f)
#define EMPLEG_TRUCK_WIDTH_SEC                        (       2.0f)
#define EMPLEG_OBJECT_NO_CLASS_WIDTH_SEC              (       0.1f)

#define EMPLEG_COLL_MAX_TIME                          (       1.5f)
#define EMPLEG_COLL_NUM_SIM_STEPS                     (        50u)
#define EMPLEG_COLL_EGO_MAX_ACCEL_X_LIKE              (      10.0f)
#define EMPLEG_COLL_EGO_MAX_ACCEL_Y_LIKE              (       5.0f)
#define EMPLEG_COLL_EGO_COLL_WIDTH                    (       0.9f)
#define EMPLEG_COLL_OBJ_MAX_ACCEL_UNAV                (      10.0f)
#define EMPLEG_COLL_EGO_MAX_ACCEL_X_UNAV              (      10.0f)
#define EMPLEG_COLL_EGO_MAX_ACCEL_Y_UNAV              (       8.0f)

#define EMPLEG_OBJECT_PROPERTY_STATIONARY             (1)

#define EMPLEG_TRKASGN_MIN_RAD_FOR_ROAD_TRAJ          (     700.0f) 
#define EMPLEG_TRKASGN_CURVE_OVRLAP_PRED_TIME         (       1.5f)

#define EMPLEG_RUN_UP_TRACK_WIDTH                     (       1.8f)

#define EMPLEG_GEN_OBJECT_MT_STATE_DELETED	          (0)
#define EMPLEG_GEN_OBJECT_MT_STATE_MERGE_DELETED	    (4)

#define EMPLEG_COMMON_MIN_OBJ_QUALITY                 (        48u)

#define EMPLEG_TRKASGN_MIN_TRACK_OVERLAP              (      0.75f)
#define EMPLEG_TRKASGN_TRACK_OVERLAP_PRED_OFFSET      (     -0.25f)
#define EMPLEG_TRKASGN_OBJ_OVERLAP_PRED_OFFSET        (     -0.35f)
#define EMPLEG_TRKASGN_STRAIGHT_OVRLAP_PRED_TIME      (      1.15f)
#define EMPLEG_TRKASGN_MAX_AVOID_DIST                 (      20.0f)
#define EMPLEG_TRKASGN_MAX_AVOID_TTC                  (       3.0f)
#define EMPLEG_TRKASGN_MIN_LAT_AVOID_SPEED            (       0.9f)

#define EMPLEG_ACC_LENGTH                             (     200.0f)
#define EMPLEG_ACC_TRACK_WIDTH                        (       2.2f)
#define EMPLEG_ACC_TO_RUNUP_LENGTH                    (      20.0f)

/*! Pedestrian Collision Zone Width */
#define EMPLEG_PED_COLL_PROB_ZONE                     (       2.8f)

///@}
#endif /*ACDC_CFG_EMP*/
#endif /* EMP_PAR_H_INCLUDED */

