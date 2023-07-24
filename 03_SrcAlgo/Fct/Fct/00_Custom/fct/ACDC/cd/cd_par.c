/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD (Collision Detection)

PACKAGENAME:               cd_par.c

DESCRIPTION:               Parameter File of CD (Collision Detection)

AUTHOR:                    $Author: Rastogi, Abhishek (uib10447) (uib10447) $

CREATION DATE:             $Date: 2019/12/18 13:54:28CET $

VERSION:                   $Revision: 1.22.1.1 $

LEGACY VERSION:            Revision: 1.59.2.2

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup cd_par
@{
*/
/*****************************************************************************
  GLOBAL VARIABLES 
*****************************************************************************/

/*! @brief Table to downgrade the pedestrian hypothesis probability [0,1]*/
SET_MEMSEC_CONST(CD_PED_COLL_DOM_DG_MAX_RATE_VEC)
const CML_t_Vector2D CD_PED_COLL_DOM_DG_MAX_RATE_VEC[CD_NUMBER_OF_DOMINANTDOWNGRADE_MAX_RATE_VALUES] =
{
    {0.f , C_F32_DELTA},
    {0.2f, 1.0f}
}; /* { 0.2f, 1.0f } -> ped is >0.2m away, we downgrad the ped hypothesis for objects approaching in an angle sharper than 45 degree.  */

SET_MEMSEC_CONST(CD_PED_COLL_DOM_DG_MIN_FACTOR_VEC)
const CML_t_Vector2D CD_PED_COLL_DOM_DG_MIN_FACTOR_VEC[CD_NUMBER_OF_DOMINANTDOWNGRADE_MIN_FACTOR_VALUES] =
{
    {0.f , 1.0f},
    {1.0f, 0.0f}
};

/*! @brief Lookup table for the relation between the additional Ego-Vehicle corridor width (inlet part) and the Ego-Vehicle speed*/
SET_MEMSEC_CONST(CD_EGO_ADD_WIDTH_IN_VELO_DEP_M)
const CML_t_Vector2D CD_EGO_ADD_WIDTH_IN_VELO_DEP_M[CD_NUMBER_OF_EGO_ADD_WIDTH_IN_VELO_DEP_VALUES] =
{
  { 8.0f, 0.f },
  {20.0f, 0.45f}
};


/*! @brief Lookup table for the relation between the additional Ego-Vehicle corridor width (outlet part) and the Ego-Vehicle speed*/
SET_MEMSEC_CONST(CD_EGO_ADD_WIDTH_OUT_VELO_DEP_M)
  const CML_t_Vector2D CD_EGO_ADD_WIDTH_OUT_VELO_DEP_M[CD_NUMBER_OF_EGO_ADD_WIDTH_OUT_VELO_DEP_VALUES] =
{
  { 8.0f, 0.0f },
  {20.0f, 1.05f}
};

/*! @brief Lookup table for the relation between the additional Ego-Vehicle corridor width and object velocity to trajectory 
    0: No corridor width reduction 1: Maximum corridor width reduction 
    @attention: This is no longer a lookup table for the reduction factor, the name shall be modified.*/
SET_MEMSEC_CONST(CD_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_M)
  const CML_t_Vector2D CD_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_M[CD_NOF_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_VALUES] =
{
  { 0.3f, 0.f },
  { 0.7f, 1.0f}
};

/*! Table that maps the raw ego velocity to assumed max. x-acceleration for comfort braking */
SET_MEMSEC_CONST(CD_COMFORT_EGO_ACCEL_X)
const CML_t_Vector2D CD_COMFORT_EGO_ACCEL_X[CD_NUMBER_OF_COMFORT_EGO_ACCEL_X_VALUES] =
{
  {10.0f, -5.0f},
  {15.0f, -5.0f}
};

/*! Table that maps the raw ego velocity to assumed max. y-acceleration for comfort steering */
SET_MEMSEC_CONST(CD_COMFORT_EGO_VEL_FACTOR_Y)
const CML_t_Vector2D CD_COMFORT_EGO_VEL_FACTOR_Y[CD_NUMBER_OF_COMFORT_EGO_VEL_FACTOR_Y_VALUES] =
{
  { 0.f , 1.0f},
  {10.0f, 0.9f},
  {15.0f, 0.75f},
  {18.0f, 0.6f},
  {22.0f, 0.5f},
  {40.0f, 0.5f},
  {50.0f, 0.6f}
};

/*! Table that maps the raw ego velocity to assumed max. y-acceleration for emergency steering */
SET_MEMSEC_CONST(CD_EMERGENCY_EGO_ACCEL_Y)
const CML_t_Vector2D CD_EMERGENCY_EGO_ACCEL_Y[CD_NUMBER_OF_EMERGENCY_EGO_ACCEL_Y_VALUES] =
{
  {22.0f, 7.0f},
  {30.0f, 4.0f}
};

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
/*! Table that maps the object distance to assumed velocity reduction during brake jerk */
SET_MEMSEC_CONST(CD_BRAKE_JERK_VEL)
const CML_t_Vector2D CD_BRAKE_JERK_VEL[CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES] =
{
  {  25.0f, -10.0f },
  { 100.0f,  -3.0f }
};

/*!  Table that maps the object distance to assumed minimum duration of brake jerk */
SET_MEMSEC_CONST(CD_BRAKE_JERK_TIME)
const CML_t_Vector2D CD_BRAKE_JERK_TIME[CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES] =
{
  {  25.0f, 1.0f },
  { 100.0f, 1.0f }
};
#endif /* CD_USE_BRAKE_JERK_TTC */

/*! @brief      Longitudinal safety margin for customer calculated anec long value
    @conseq     @incp  anec higher at given long. distance
                @decp  anec lower at given long. distance
    @attention  Activation thresholds on end function are not affected
    @typical    0.5    @unit  m   @min 0.0   @max 10.0   */
SET_MEMSEC_VAR(CD_LONG_SAFETY_DIST_CUST)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_DEF_PARAM(float32, CD_LONG_SAFETY_DIST_CUST, CD_LONG_SAFETY_DIST_CUST_DEFAULT)


SET_MEMSEC_VAR(CD_COMMON_TRACK_WIDTH_FACT)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_DEF_PARAM(float32, CD_COMMON_TRACK_WIDTH_FACT, CD_COMMON_TRACK_WIDTH_FACT_DEFAULT)
/*! @brief Ego trajectory curvature depending track width (x --> curvature, y --> track width) */ 
SET_MEMSEC_CONST(CD_RUN_UP_TTC_TRACK_WIDTH)
const CML_t_Vector2D CD_RUN_UP_TTC_TRACK_WIDTH[CD_RUN_UP_TTC_WIDTH_NO_POINTS] =
{
  { 0.0015f, 2.0f},
  { 0.0035f, 1.7f}
};
/*! @brief Obj distance depending track width (x --> distance, y --> track width) */ 
SET_MEMSEC_CONST(CD_RUN_UP_TTC_TRACK_WIDTH_WIDE)
const CML_t_Vector2D CD_RUN_UP_TTC_TRACK_WIDTH_WIDE[CD_RUN_UP_TTC_WIDTH_FAC_NO_POINTS] =
{
  { 3.0f, 1.0f},
  { 5.0f, 2.0f}
};

#if (CD_USE_NAR_TRAJ_RUN_UP_SMALL_OBJ)
/*! @brief      Minimum required distance for narrowing trajectory width for small objects
   @general    Table with distance threshold over ego velocity
   Input:  Sensor vehicle ego velocity  
   Output: Distance Threshold for narrowing trajectory width */
SET_MEMSEC_CONST(CD_RUNUP_SOBJ_OCC_VEGO_DIST)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_PAR_CONST CML_t_Vector2D CD_RUNUP_SOBJ_OCC_VEGO_DIST[CD_RUNUP_SOBJ_HYP_OCC_VEGO_DIST_NO] =
{
  { 60.0f/3.6f,  25.0f},
  {100.0f/3.6f,  50.0f},
  {200.0f/3.6f, 100.5f}
};

/*! @brief      Transition section for trajectory width reduction
   @general     Defines relative part of min. distance, starting width narrowing*/
SET_MEMSEC_CONST(CD_RUNUP_SOBJ_HYP_OCC_DIST_RED_FACT)
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
FCT_DEF_FIX_PARAM(float32, CD_RUNUP_SOBJ_HYP_OCC_DIST_RED_FACT, 0.8F)

/*! @brief      Trajectory width narrowing
   @general     Reduction factor for trajectory width, dependent on transition section*/
SET_MEMSEC_VAR(CD_RUNUP_SOBJ_HYP_OCC_DIST_RED)
CML_t_Vector2D CD_RUNUP_SOBJ_HYP_OCC_DIST_RED[CD_RUNUP_SOBJ_HYP_OCC_RED_OVER_DIST_NO] =
{
  { 0.f, 1.0f}, /* Those zeros will be set dynamically in hyprunup.c */
  { 0.f, 0.4f}
};

#endif

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)

/*! @brief      Ego path curvature threshold for detecting turn maneuver
   @general    Table with curvature threshold over ego velocity
   Input:  Sensor vehicle ego velocity  
   Output: curvature Threshold for detecting turn maneuver */
SET_MEMSEC_CONST(CD_EGO_DRV_CRV_TRN_THRE)
const CML_t_Vector2D CD_EGO_DRV_CRV_TRN_THRE[CD_EGO_DRV_CRV_TRN_THRE_NO] =
{
  {0.0f         , 0.080f},
  {5.0f/3.6f    , 0.062f},
  {15.0f/3.6f   , 0.043f},
  {20.0f/3.6f   , 0.038f},
};

/*! @brief      Ego path curvature threshold for keeping the detected turn maneuver
   @general    Table with curvature threshold over ego velocity
   Input:  Sensor vehicle ego velocity  
   Output: curvature Threshold for keeping the detected turn maneuver */
SET_MEMSEC_CONST(CD_EGO_DRV_CRV_KEEP_TRN_THRE)
const CML_t_Vector2D CD_EGO_DRV_CRV_KEEP_TRN_THRE[CD_EGO_DRV_CRV_KEEP_TRN_THRE_NO] =
{
  {0.0f         , 0.040f},
  {5.0f/3.6f    , 0.031f},
  {15.0f/3.6f   , 0.021f},
  {20.0f/3.6f   , 0.019f}
};

#if(CD_BLK_DIST_TURN_OPST_DIR)
/*! @brief      The distance, in which the detection of turn scenario in the opposite direction is blocked,
                to avoid the detection of lane change orientation correction phase as turning.
   @general    Table with distance threshold over ego velocity
   Input:  Sensor vehicle ego velocity  
   Output: Distance of the prevention of turn detection in the oposite direction */
SET_MEMSEC_CONST(CD_EGO_DRV_CRV_BLK_OPP_DIR)
const CML_t_Vector2D CD_EGO_DRV_CRV_BLK_OPP_DIR[CD_EGO_DRV_CRV_BLK_OPP_DIR_NO] =
{
  {0.0f          , 0.0f},
  {35.0f/3.6f    , 0.0f}
};
#endif
#endif
/****************************************************************
  Fusion sensor confirmation settings
 *****************************************************************/
#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && ( CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE == SWITCH_ON )

/*! @brief        Array with mappings between the uiSensorConfirmation structure in the EM Fusion object list
                  and the eSensorSource bitfield in the CD hypothesis and the corresponding confirmation thresholds.*/
const CDFusionSenConf_t CDFusionSenConf[EM_N_FUSION_SENSORS] = 
{
  { 
    EM_FUSION_SEN_IDX_CAM,  /*!<eFusionSenIdx    Sensor index in the fusion object list */
    EM_GEN_OBJECT_MS_CAM,   /*!<eSensorSource    Bit in the sensor source interface matching the fusion sensor*/
    70u,                    /*!<uSenConfThresOn  Sensor specific confirmation threshold to set SensorSource Bit. */
    70u                     /*!<uSenConfThresOff Sensor specific confirmation threshold to delete SensorSource Bit. */
  }
}; 

#endif

/* ************************************************************************* */
/*   Hypothesis Handlers                                                     */
/* ************************************************************************* */

#if (CD_USE_RUN_UP_HYPOTHESIS)

/* Handler for 'Run-up' Hypothesis */
SET_MEMSEC_CONST(CD_RUN_UP_HANDLER)
SET_MEMSEC_CONST(sClassList_Runup)
SET_MEMSEC_CONST(sClassFilter_RunUp)

/*!@brief List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_Runup[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/*!@brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_RunUp = 
{
  sClassList_Runup,
  sizeof(sClassList_Runup)/sizeof(CDHypFilterClass_t), 
  CD_RUN_UP_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the RunUp hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_RUN_UP_HANDLER =
{
  &CDHypoRunUpMain,
  NULL,
  &sClassFilter_RunUp, /* NULL switches of the class handling. All objects will pass the filter */
  ( ((uint32)1u << (uint32)CDHypothesisType_RunUp) | ((uint32)1u << (uint32)CDHypothesisType_RunUpBraking) ),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_COMOV,
  CD_RUN_UP_MIN_EBA_GEN_OBJ_QUAL,
  CD_RUN_UP_MIN_EBA_STAT_OBJ_QUAL,
  CD_RUN_UP_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_RUNUP,
};
#endif /* CD_USE_RUN_UP_HYPOTHESIS */

#if (CD_USE_CUT_IN_HYPOTHESIS)
/* Handler 'Cut-In' Hypothesis */
SET_MEMSEC_CONST(CD_CUT_HANDLER)
SET_MEMSEC_CONST(sClassList_Cutin)
SET_MEMSEC_CONST(sClassFilter_Cutin)

/*! List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_Cutin[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/* Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_Cutin = 
{
  sClassList_Cutin,
  sizeof(sClassList_Cutin)/sizeof(CDHypFilterClass_t), 
  CD_CUT_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the CutIn hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_CUT_IN_HANDLER =
{
  &CDHypoCutInMain,
  NULL,
  &sClassFilter_Cutin, /* NULL switches of the class handling. All objects will pass the filter */
  (uint32)(1u << (uint32)CDHypothesisType_CutIn),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_COMOV,
  CD_CUT_IN_MIN_EBA_GEN_OBJ_QUAL,
  CD_CUT_IN_MIN_EBA_STAT_OBJ_QUAL,
  CD_CUT_IN_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_CUTIN,
};
#endif /* CD_USE_CUT_IN_HYPOTHESIS */

#if (CD_USE_PASS_HYPOTHESIS)
/* Handler 'Pass' Hypothesis */

SET_MEMSEC_CONST(CD_PASS_HANDLER)
SET_MEMSEC_CONST(sClassList_Pass)
SET_MEMSEC_CONST(sClassFilter_Pass)

/*! @brief List of all classes which shall be accepted for this hypothesis type. 
      - @attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_Pass[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/*! @brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_Pass = 
{
  sClassList_Pass,
  sizeof(sClassList_Pass)/sizeof(CDHypFilterClass_t), 
  CD_PASS_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the Pass hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_PASS_HANDLER =
{
  &CDHypoPassMain,
  NULL,
  &sClassFilter_Pass, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_Pass),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_COMOV,
  CD_PASS_MIN_EBA_GEN_OBJ_QUAL,
  CD_PASS_MIN_EBA_STAT_OBJ_QUAL,
  CD_PASS_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_PASS
};
#endif /* CD_USE_PASS_HYPOTHESIS */

#if (CD_USE_FOLLOW_HYPOTHESIS)
/* Handler 'Follow' Hypothesis */

SET_MEMSEC_CONST(CD_FOLLOW_HANDLER)
SET_MEMSEC_CONST(sClassList_Follow)
SET_MEMSEC_CONST(sClassFilter_Follow)

/*!@brief List of all classes which shall be accepted for the static hypothesis.
    - @attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_Follow[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/*!@brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_Follow = 
{
  sClassList_Follow,
  sizeof(sClassList_Follow)/sizeof(CDHypFilterClass_t), 
  CD_FOLLOW_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the follow hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_FOLLOW_HANDLER =
{
  &CDHypoStaticMain,
  NULL,
  &sClassFilter_Follow, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_Static),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_COMOV,
  CD_FOLLOW_MIN_EBA_GEN_OBJ_QUAL,
  CD_FOLLOW_MIN_EBA_STAT_OBJ_QUAL,
  CD_FOLLOW_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_STATIC
};
#endif /* CD_USE_FOLLOW_HYPOTHESIS */

#if (CD_USE_COLL_HYPOTHESIS)

SET_MEMSEC_CONST(CD_COLL_HANDLER)
SET_MEMSEC_CONST(sClassList_Collision)
SET_MEMSEC_CONST(sClassFilter_Collision)

/*!@brief List of all classes which shall be accepted for the collision hypothesis. 
    - @attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_Collision[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/*!@brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_Collision = 
{
  sClassList_Collision,
  sizeof(sClassList_Collision)/sizeof(CDHypFilterClass_t), 
  CD_COLL_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the collision hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_COLL_HANDLER =
{
  &CDHypoCollisionMain,
  NULL,
  &sClassFilter_Collision, /* NULL switches of the class handling. All objects will pass the filter */
  ( ((uint32)1u << (uint32)CDHypothesisType_Collision) | ((uint32)1u << (uint32)CDHypothesisType_CollisionUnavoidable) ),
  (EM_t_GenEbaHypCat)(FPS_EBA_HYP_CAT_COMOV | FPS_EBA_HYP_CAT_XING | FPS_EBA_HYP_CAT_ONC | FPS_EBA_HYP_CAT_STAT),
  CD_COLL_MIN_EBA_GEN_OBJ_QUAL,
  CD_COLL_MIN_EBA_STAT_OBJ_QUAL,
  CD_COLL_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_COLLISION
};
#endif /* CD_USE_COLL_HYPOTHESIS */

#if (CD_USE_RUN_UP_STAT_HYPOTHESIS)
/* Handler 'Run-up Stationary' Hypothesis */

SET_MEMSEC_CONST(CD_RUN_UP_STAT_HANDLER)
SET_MEMSEC_CONST(sClassList_RunupStat)
SET_MEMSEC_CONST(sClassFilter_RunupStat)

/*! List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_RunupStat[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR,
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/* Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_RunupStat = 
{
  sClassList_RunupStat,
  sizeof(sClassList_RunupStat)/sizeof(CDHypFilterClass_t), 
  CD_RUN_UP_STAT_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the collision hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_RUN_UP_STAT_HANDLER =
{
  &CDHypoRunUpStationaryMain,
  &CDHypoRunUpStationaryPost,
  &sClassFilter_RunupStat, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_RunUpStationary),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_STAT,
  CD_RUN_UP_STAT_MIN_EBA_GEN_OBJ_QUAL,
  CD_RUN_UP_STAT_MIN_EBA_STAT_OBJ_QUAL,
  CD_RUN_UP_STAT_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_RUNUP_STAT
};
#endif /* CD_USE_RUN_UP_STAT_HYPOTHESIS */

#if (CD_USE_ACC_HYPOTHESIS)
/*! Handler 'ACC' Hypothesis */
SET_MEMSEC_CONST(CD_ACC_HANDLER)
SET_MEMSEC_CONST(sClassList_ACC)
SET_MEMSEC_CONST(sClassFilter_ACC)

/*! @brief List of all classes which shall be accepted for the ACC hypothesis. 
    - @attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_ACC[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/* Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_ACC = 
{
  sClassList_ACC,
  sizeof(sClassList_ACC)/sizeof(CDHypFilterClass_t), 
  CD_ACC_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the acc hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_ACC_HANDLER =
{
  &CDHypoAccMain,
  NULL,
  &sClassFilter_ACC, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_ACC),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_COMOV,
  CD_ACC_MIN_EBA_GEN_OBJ_QUAL,
  CD_ACC_MIN_EBA_STAT_OBJ_QUAL,
  CD_ACC_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_ACC
};
#endif /* CD_USE_ACC_HYPOTHESIS */


#if (CD_USE_PED_COLL_HYPOTHESIS)
SET_MEMSEC_CONST(CD_PED_COLL_HANDLER)
SET_MEMSEC_CONST(sClassList_PedColl)
SET_MEMSEC_CONST(sClassFilter_PedColl)

/*! @brief List of all classes which shall be accepted for the pedestrian hypothesis. 
    - @attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_PedColl[] = 
{ 
  FPS_EBA_CLASS_PEDESTRIAN,
};

/*! @brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_PedColl = 
{
  sClassList_PedColl,
  sizeof(sClassList_PedColl)/sizeof(CDHypFilterClass_t), 
  CD_PED_COLL_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the pedestrian hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_PED_COLL_HANDLER =
{
  &CDHypoPedCollMain,
  NULL,
  &sClassFilter_PedColl, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_PedCollision),
  (EM_t_GenEbaHypCat)(FPS_EBA_HYP_CAT_XING | FPS_EBA_HYP_CAT_STAT),
  CD_PED_COLL_MIN_EBA_GEN_OBJ_QUAL,
  CD_PED_COLL_MIN_EBA_STAT_OBJ_QUAL,
  CD_PED_COLL_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_PEDCOLL
};

#endif /* CD_USE_PED_COLL_HYPOTHESIS */

#if (CD_USE_BICYCLE_COLL_HYPOTHESIS)
SET_MEMSEC_CONST(CD_BICYCLE_COLL_HANDLER)
SET_MEMSEC_CONST(sClassList_BicycleColl)
SET_MEMSEC_CONST(sClassFilter_BicycleColl)

/*! List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_BicycleColl[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
};

/*! @brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_BicycleColl = 
{
  sClassList_BicycleColl,
  sizeof(sClassList_BicycleColl)/sizeof(CDHypFilterClass_t), 
  CD_BICYCLE_COLL_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the bicycle hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_BICYCLE_COLL_HANDLER =
{
  &CDHypoCycleCollMain,
  NULL,
  &sClassFilter_BicycleColl, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_CyclColl),
  (EM_t_GenEbaHypCat)(FPS_EBA_HYP_CAT_XING | FPS_EBA_HYP_CAT_STAT),
  CD_BICYCLE_COLL_MIN_EBA_GEN_OBJ_QUAL,
  CD_BICYCLE_COLL_MIN_EBA_STAT_OBJ_QUAL,
  CD_BICYCLE_COLL_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_BICYCLECOLL
};

#endif /* CD_USE_CYCLE_COLL_HYPOTHESIS */

#if (CD_USE_CROSSING_HYPOTHESIS)
SET_MEMSEC_CONST(CD_CROSSING_HANDLER)
SET_MEMSEC_CONST(sClassList_Crossing)
SET_MEMSEC_CONST(sClassFilter_Crossing)

/*!@brief List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_Crossing[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
  FPS_EBA_CLASS_TRUCK,
  FPS_EBA_CLASS_CAR, 
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/*!@brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_Crossing = 
{
  sClassList_Crossing,
  sizeof(sClassList_Crossing)/sizeof(CDHypFilterClass_t), 
  CD_CROSSING_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the crossing hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_CROSSING_HANDLER =
{
  &CDHypoCrossingMain,
  NULL,
  &sClassFilter_Crossing, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_Crossing),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_XING,
  CD_CROSSING_MIN_EBA_GEN_OBJ_QUAL,
  CD_CROSSING_MIN_EBA_STAT_OBJ_QUAL,
  CD_CROSSING_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_CROSSING
};

#endif /* CD_USE_CROSSING_HYPOTHESIS */

#if (CD_USE_LONG_COLL_HYPOTHESIS)
SET_MEMSEC_CONST(CD_LONG_COLL_HANDLER)
SET_MEMSEC_CONST(sClassList_LongColl)
SET_MEMSEC_CONST(sClassFilter_LongColl)

/*!@brief List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_LongColl[] = 
{ 
  FPS_EBA_CLASS_CYCLIST,
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_MOTORBIKE,
};

/*!@brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_LongColl = 
{
  sClassList_LongColl,
  sizeof(sClassList_LongColl)/sizeof(CDHypFilterClass_t), 
  CD_RUN_UP_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the longitudinal collision hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_LONG_COLL_HANDLER =
{
  &CDHypoLongMain,
  NULL,
  &sClassFilter_LongColl, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_RunupCoMoving),
  (EM_t_GenEbaHypCat)FPS_EBA_HYP_CAT_COMOV,
  CD_RUN_UP_MIN_EBA_GEN_OBJ_QUAL,
  CD_RUN_UP_MIN_EBA_STAT_OBJ_QUAL,
  CD_RUN_UP_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_RUNUPLONG
};
#endif /* CD_USE_LONG_COLL_HYPOTHESIS */

#if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
SET_MEMSEC_CONST(CD_ONCOMING_HANDLER)
SET_MEMSEC_CONST(sClassList_DriveIntoOncoming)
SET_MEMSEC_CONST(sClassFilter_DriveIntoOncoming)

/*! @brief List of all object classes which shall be accepted for the drive into oncoming  hypothesis.*/
static const CDHypFilterClass_t sClassList_DriveIntoOncoming[] = 
{ 
  FPS_EBA_CLASS_CAR,
#if(CD_HYP_ONCOMING_USE_TRUCK_OBJECT == SWITCH_ON)
  FPS_EBA_CLASS_TRUCK,
#endif /*CD_HYP_ONCOMING_USE_TRUCK_OBJECT*/
  FPS_EBA_CLASS_MOTORBIKE
};

/*! @brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_DriveIntoOncoming = 
{
  sClassList_DriveIntoOncoming,
  sizeof(sClassList_DriveIntoOncoming)/sizeof(CDHypFilterClass_t), 
  0u /* required class confidence currently set to 0% */
};
static const CDHypoHandler_t CD_ONCOMING_HANDLER =
{
  &CD_v_HypoOncomingMain,
  NULL,
  &sClassFilter_DriveIntoOncoming,
  ((uint32)1u << (uint32)CDHypothesisType_DriveIntoOncoming),
  (EM_t_GenEbaHypCat)(FPS_EBA_HYP_CAT_ONC),
  CD_HYP_ONCOMING_MIN_EBA_GEN_OBJ_QUAL,
  CD_HYP_ONCOMING_MIN_EBA_STAT_OBJ_QUAL,
  CD_HYP_ONCOMING_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_ONCOMING
};
#endif /* CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS */

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
SET_MEMSEC_CONST(CD_TURNINTOVRU_HANDLER)
SET_MEMSEC_CONST(sClassList_TurnIntoVRU)
SET_MEMSEC_CONST(sClassFilter_TurnIntoVRU)

/*! @brief List of all hypothesis classes which shall be accepted for the turn into oncoming pedestrian hypothesis. 
    - @attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_TurnIntoVRU[] = 
{ 
  FPS_EBA_CLASS_PEDESTRIAN,
};

/*! @brief Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_TurnIntoVRU = 
{
  sClassList_TurnIntoVRU,
  sizeof(sClassList_TurnIntoVRU)/sizeof(CDHypFilterClass_t), 
  CD_TURNINTOVRU_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the turn into oncoming pedestrian (CPTA) hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_TURNINTOVRU_HANDLER =
{
  &CDHypTurnIntoVRUMain,
  NULL,
  &sClassFilter_TurnIntoVRU, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_TurnIntoVRU),
  (EM_t_GenEbaHypCat)(FPS_EBA_HYP_CAT_XING | FPS_EBA_HYP_CAT_STAT | FPS_EBA_HYP_CAT_ONC),
  CD_TURNINTOVRU_MIN_EBA_GEN_OBJ_QUAL,
  CD_TURNINTOVRU_MIN_EBA_STAT_OBJ_QUAL,
  CD_TURNINTOVRU_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_TURNINTOVRU
};
#endif /* CD_USE_TURNINTOVRU_HYPOTHESIS */

#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)
/* Handler 'drive into slow moving' Hypothesis */

SET_MEMSEC_CONST(CD_DRIVEINTOSLOMO_HANDLER)
SET_MEMSEC_CONST(sClassList_DriveIntoSloMo)
SET_MEMSEC_CONST(sClassFilter_DriveIntoSloMo)

/*! List of all classes which shall be accepted for this hypothesis type. Attention: Use the same type as used for CDHyoClassFilter_t here. */
static const CDHypFilterClass_t sClassList_DriveIntoSloMo[] = 
{ 
  FPS_EBA_CLASS_PEDESTRIAN,
  FPS_EBA_CLASS_CAR,
#ifdef FPS_EBA_CLASS_VEHICLE
  FPS_EBA_CLASS_VEHICLE,
#endif
};

/* Structure which includes all information needed for the generic class handling */
static const CDHypoHandlerClassFilter_t sClassFilter_DriveIntoSloMo = 
{
  sClassList_DriveIntoSloMo,
  sizeof(sClassList_DriveIntoSloMo)/sizeof(CDHypFilterClass_t), 
  CD_DRIVEINTOSLOMO_MIN_OBJ_CLASS_CONF
};

/*!@brief Handler of the drive into slow moving hypothesis containing filter criteria and main hypothesis function.*/
static const CDHypoHandler_t CD_DRIVEINTOSLOMO_HANDLER =
{
  &CDHypDriveIntoSloMoMain,
  NULL,
  &sClassFilter_DriveIntoSloMo, /* NULL switches of the class handling. All objects will pass the filter */
  ((uint32)1u << (uint32)CDHypothesisType_DriveIntoSloMo),
  (EM_t_GenEbaHypCat)(FPS_EBA_HYP_CAT_COMOV | FPS_EBA_HYP_CAT_ONC | FPS_EBA_HYP_CAT_STAT),
  CD_DRIVEINTOSLOMO_MIN_EBA_GEN_OBJ_QUAL,
  CD_DRIVEINTOSLOMO_MIN_EBA_STAT_OBJ_QUAL,
  CD_DRIVEINTOSLOMO_MIN_EBA_PED_OBJ_QUAL,
  ACDC_RTA_CD_HYP_DRIVEINTOSLOMO
};
#endif /* CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS */

#if (CD_HYP_HANDLERS_NO > 0u)
/*PRQA S 3493 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
SET_MEMSEC_CONST(CD_HYP_HANDLERS)
const CDHypoHandler_t * const CD_HYP_HANDLERS[ CD_HYP_HANDLERS_NO ] = 
{
#if(CD_USE_RUN_UP_HYPOTHESIS)
  &CD_RUN_UP_HANDLER,
#endif
#if(CD_USE_CUT_IN_HYPOTHESIS)
  &CD_CUT_IN_HANDLER,
#endif
#if (CD_USE_PASS_HYPOTHESIS)
  &CD_PASS_HANDLER,
#endif
#if(CD_USE_FOLLOW_HYPOTHESIS)
  &CD_FOLLOW_HANDLER,
#endif
#if (CD_USE_COLL_HYPOTHESIS)
  &CD_COLL_HANDLER,
#endif
#if(CD_USE_RUN_UP_STAT_HYPOTHESIS)
  &CD_RUN_UP_STAT_HANDLER,
#endif
#if (CD_USE_ACC_HYPOTHESIS)
  &CD_ACC_HANDLER,
#endif
#if(CD_USE_PED_COLL_HYPOTHESIS)
  &CD_PED_COLL_HANDLER,
#endif
#if (CD_USE_CROSSING_HYPOTHESIS)
  &CD_CROSSING_HANDLER,
#endif
#if (CD_USE_BICYCLE_COLL_HYPOTHESIS)
  &CD_BICYCLE_COLL_HANDLER,
#endif
#if (CD_USE_LONG_COLL_HYPOTHESIS)
  &CD_LONG_COLL_HANDLER,
#endif
#if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)
  &CD_ONCOMING_HANDLER,
#endif
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
  &CD_TURNINTOVRU_HANDLER,
#endif
#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)
  &CD_DRIVEINTOSLOMO_HANDLER
#endif
};
#else
SET_MEMSEC_CONST(CD_HYP_HANDLERS)
const CDHypoHandler_t * const CD_HYP_HANDLERS = NULL;
#endif

///@}
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

