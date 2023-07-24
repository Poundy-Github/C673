/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_geometric_lane_assoc.c

DESCRIPTION:               This is the main file for implementation of geometrical lane association

AUTHOR:                    Grant Davtjan (uidg3349)

CREATION DATE:             

VERSION:                   $Revision: 1.60 $

LEGACY VERSION:            Revision: 2.2
  
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_geometric_lane_assoc LA geometric lane association
@ingroup la_laneassociation
@brief          Check to which lane object is associated to based on the geometrical inlap based information. \n\n

@{

*/
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if (LA_CFG_USE_OBJECT_ORIENTATION_NEAR_OBJECTS)
#define LA_MAX_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT          (10.f)    /*!< Maximum longitudinal distance, before which cut ins have to be treated more carefully */
#define LA_MIN_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT          (1.5f)    /*!< Maximum longitudinal distance, before which cut ins have to be treated more carefully. The value represents 0.33*Car_Length */
#define LA_MIN_TRUCK_SHORTRANGE_CUT_IN_LONG_DISPLACEMENT    (4.f)     /*!< Maximum longitudinal distance, before which cut ins have to be treated more carefully */
#define LA_MAX_SHORTRANGE_CUT_IN_LAT_DISPLACEMENT           (2.0f)    /*!< Maximum lateral distance, before which cut ins have to be treated more carefully */
#define LA_MAX_CURVATURE_CUT_IN_LAT_DISPLACEMENT            (1/150)   /*!< Maximum curvature of the trajectory above which reduced Object distance to trajectory is used for overlap computation */
#endif

#if (LA_HIGH_VEGO_INLANE_TIME)
static const LA_t_FindObjInAreaArgs LA_OTCheckArgsHSDefault_TO = // PRQA S 3218
  /* date: 2015-09-18, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAX_LOWER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAX_UPPER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_LOWER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_UPPER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAV_LOWER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAV_UPPER)
};
static const LA_t_FindObjInAreaArgs LA_OTCheckArgsHSLeft_TO = // PRQA S 3218
  /* date: 2018-02-27, reviewer: Grant Davtjan, reason: static local for saving data across function calls */
{
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAX_LOWER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAX_UPPER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_LOWER_LEFT_TO),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAY_UPPER_LFET_TO),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAV_LOWER),
  (LA_OVERTAKING_OBJ_HIGHSPEED_DELTAV_UPPER)
};
#endif

SET_MEMSEC_CONST(LATimeThreshInLaneFromDist)
static const GDBLFunction_t LATimeThreshInLaneFromDist = {// PRQA S 3218
   /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
  LA_MINTIME_MOVE_OBJ_IN_LANE_MIN,
  LA_MINTIME_MOVE_OBJ_IN_LANE_MAX,
  /*! <ln_offset:+1 PCLINT Error 835: reviewer name: Boll date: 13-03-2012 reason: LA_MINTIME_MOVE_OBJ_IN_LANE_MIN set as zero */
  ( ( LA_MINTIME_MOVE_OBJ_IN_LANE_MAX - LA_MINTIME_MOVE_OBJ_IN_LANE_MIN ) / ( LA_DISTX_MOVE_OBJ_IN_LANE_MAX - LA_DISTX_MOVE_OBJ_IN_LANE_MIN ) ),
  /*! <ln_offset:+1 PCLINT Error 835: reviewer name: Boll date: 13-03-2012 reason: LA_MINTIME_MOVE_OBJ_IN_LANE_MIN set as zero */
  LA_MINTIME_MOVE_OBJ_IN_LANE_MIN - ( (( LA_MINTIME_MOVE_OBJ_IN_LANE_MAX - LA_MINTIME_MOVE_OBJ_IN_LANE_MIN ) / ( LA_DISTX_MOVE_OBJ_IN_LANE_MAX - LA_DISTX_MOVE_OBJ_IN_LANE_MIN ) ) * LA_DISTX_MOVE_OBJ_IN_LANE_MIN)
};

#if (LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX)
/* Pickup threshold increment factors depending on longitudinal relative velocity*/
#define LA_MIN_PICKUP_RED_VALUE  (0.0f)
#define LA_MAX_PICKUP_RED_VALUE	 (0.2f)

/* Minimum and maximum relative velocities in which the the ramp function which increases the PICKUP threshold is defined*/
#define LA_MIN_VREL_X            (0.0f)
#define LA_MAX_VREL_X            (4.0f)

#endif /*END IF LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX*/

#if (LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD)

/* Pickup threshold decrement factors depending on longitudinal relative velocity*/
#define LA_MIN_LAT_RED_VALUE     (0.1f)
#define LA_MAX_LAT_RED_VALUE     (0.5f)

/* Minimum and maximum relative velocities in which the the ramp function which decreases the PICKUP threshold is defined*/
#define LA_MIN_VREL_Y            (0.3f)
#define LA_MAX_VREL_Y            (2.0f)

#endif /* END IF LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD */

SET_MEMSEC_CONST(LAPickUpThreshInLaneFromDist)
/*This ramp function is used to reduce Pick up threshold w.r.t the longitundinal distance to improve long distance approaches and cutins
Defined in the distance range LA_DISTX_PICKUP_REDUCTION_MIN to LA_DISTX_PICKUP_REDUCTION_MAX*/
static const GDBLFunction_t LAPickUpThreshInLaneFromDist = { // PRQA S 3218
   /* date: 2016-08-26, reviewer: Madhusudan Mudhol, reason: static local for saving data across function calls */
  LA_MINFAC_MOVE_OBJ_IN_LANE_MIN_X,  /*Minimum reduction value; this is the factor by which Pickup Threshold gets reduced at the smallest of the distances*/
  LA_MINFAC_MOVE_OBJ_IN_LANE_MAX,    /*Maximum reduction value; this is the factor by which Pickup threshold gets reduced at the largest of the distances*/

  ( ( LA_MINFAC_MOVE_OBJ_IN_LANE_MAX - LA_MINFAC_MOVE_OBJ_IN_LANE_MIN_X ) / ( LA_DISTX_PICKUP_REDUCTION_MAX - LA_DISTX_PICKUP_REDUCTION_MIN ) ), /*Slope of the function*/
  
  LA_MINFAC_MOVE_OBJ_IN_LANE_MIN_X - ( (( LA_MINFAC_MOVE_OBJ_IN_LANE_MAX - LA_MINFAC_MOVE_OBJ_IN_LANE_MIN_X ) / ( LA_DISTX_PICKUP_REDUCTION_MAX - LA_DISTX_PICKUP_REDUCTION_MIN ) ) * (LA_DISTX_PICKUP_REDUCTION_MIN))
  /*Y intercept of the function*/
};

#if (LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX)

SET_MEMSEC_CONST(LAPickUpThreshFromLongVelo)
/*This ramp function is used to increase the Pickup Threshold w.r.t the longitudinal velocity of the object relative to ego, higher the velocity, higher is the PickUp Threshold
Defined in the velocity range LA_MIN_VREL_X and LA_MAX_VREL_X*/
static const GDBLFunction_t LAPickUpThreshFromLongVelo = { // PRQA S 3218
   /* date: 2016-08-26, reviewer: Madhusudan Mudhol, reason: static local for saving data across function calls */
  LA_MIN_PICKUP_RED_VALUE,  /*Minimum increment value*/
  LA_MAX_PICKUP_RED_VALUE,  /*Maximum increment value*/
 
  ((LA_MAX_PICKUP_RED_VALUE - LA_MIN_PICKUP_RED_VALUE) / (LA_MAX_VREL_X - LA_MIN_VREL_X)) , /*Slope of the function*/
  
  LA_MIN_PICKUP_RED_VALUE - ((LA_MAX_PICKUP_RED_VALUE - LA_MIN_PICKUP_RED_VALUE) / (LA_MAX_VREL_X - LA_MIN_VREL_X)) * (LA_MIN_VREL_X) /*Y intercept of the function*/
};

#endif /*END IF LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX*/

#if (LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD)

SET_MEMSEC_CONST(LAPickUpThreshFromLatVelo)
/* This ramp function is used to reduce pick up threshold w.r.t lateral velocity of object relative to ego, higher the relative lateral velocity, lower is the pickup threshold 
defined in the velocity range LA_MAX_VREL_Y and LA_MIN_VREL_Y */
static const GDBLFunction_t LAPickUpThreshFromLatVelo = { // PRQA S 3218
  /* date: 2019-01-01, reviewer: Pavan kumar Kotra, reason: static local for saving data across function calls */
  LA_MIN_LAT_RED_VALUE,  /*Minimum reduction value*/
  LA_MAX_LAT_RED_VALUE,  /*Maximum reduction value*/
 
  ((LA_MAX_LAT_RED_VALUE - LA_MIN_LAT_RED_VALUE) / (LA_MAX_VREL_Y - LA_MIN_VREL_Y)) , /*Slope of the function*/
  
  LA_MIN_LAT_RED_VALUE - (((LA_MAX_LAT_RED_VALUE - LA_MIN_LAT_RED_VALUE) / (LA_MAX_VREL_Y - LA_MIN_VREL_Y)) * (LA_MIN_VREL_Y)) /*Y intercept of the function*/
};

#endif /* END IF LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD */

/*Pickup threshold decrement factor for improving close cut-ins*/
#define LA_CUTIN_REDUCTION_VALUE    (0.65f)

/*Minimum and maximum distances for which close cut-in reduction may be conLAdered*/
#define LA_MIN_DIST_CLOSE_CUTIN    (1.60f)
#define LA_MAX_DIST_CLOSE_CUTIN    (4.5f)

/*Minimum Lateral velocity for which close cutin adjustment is considered*/
#define LA_MIN_LAT_VELO     (0.45f)

/* Distance up to which curvature of the road doesn't generally matter*/
#define LA_SMALL_DIST_CURVE_CHECK   (4.50f)

/*Minimum class confidence required to make class-related parameter reductions*/
#define LA_MIN_CLASS_CONFIDENCE   (95u)

/*Minimum class confidence required for the bicylce class related */
#define LA_MIN_BICYCLE_CLASS_CONFIDENCE (90u)

#if(LA_CFG_CAM_INLANE_THRSHOLD_UPDATE)
/*Minimum camera confirmation and class confidence required to make class-related parameter reductions*/
#define LA_MIN_CAM_CONFIRMATION_CONF   (70u)
#define LA_REDUCED_CLASS_CONFIDENCE   (60u)

/* Distance and speed parameter for reduced pick-up threshold with camera confirmation */
#define LA_MAX_DIST_PICKUP_REDUCTION_CAM (30.0f)
#define LA_MIN_DIST_PICKUP_REDUCTION_CAM (5.0f)
#define LA_MAX_EGO_VEL_CITY (70.f/C_KMH_MS)
#endif

/*Multiplication factor in case of curves*/
#define LA_CURVE_MULTIPLICATION_FACTOR   (200.0f)

#if ((EM_ARS_OBJECT_LIST_INTFVER >= 6u) && (LA_CFG_MICRODOPPLER_PEDESTRIAN_HIGH_INLANE_TIME))
#define LA_MICRODOPPLER_HIGH_INLANE_TIME_THRES     (1.5f)     /*<! Very high in-lane time threshold for objects with microdoppler signature */
#endif

#if(LA_CFG_ADAPT_INLANE_TIME_THRESHOLD_STAT_OBJ_CURVE)
#define LA_EGO_CURVE_THRES     (0.05f)     /*<! Ego curve threshold to calculate Inlane time threshold for stationary objects in curvy scenario */
#define LA_EGO_CURVE_INLANE_TIME_FACTOR (0.5f)
#endif

#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
#define LA_BLOCKED_PATH_TIMER  (9u)     /* Timer to decide blocked path scenario */
#define LA_VRELX_THRESH        (10.f)  /* Longitudinal relative velocity of the object */
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */


/*****************************************************************************
  FUNCTION
*****************************************************************************/
static void         LA_v_SetObjInlapPickupThreshold(const ObjNumber_t iObj);
static void         LA_v_SetObjInlapDropThreshold(const ObjNumber_t iObj);

static fTime_t      LA_f_CalcInlaneTimeStatVehicle(fVelocity_t const fVelocity, const ObjNumber_t iObj);
static fTime_t      LA_f_CalcInlaneTimeStatNonVehicle(fVelocity_t const fVelocity, const ObjNumber_t iObj);
static fDistance_t  LA_f_GetInLaneDistanceThreshold(const ObjNumber_t iObj);

#if (LA_SIT_VREL_INLANE_TIME_INC)
static fTime_t      LA_f_GetSituationVrelInLaneTimeThreshold(const ObjNumber_t iObj, fTime_t fTimeThreshInLane);
#endif

#if (LA_HIGH_VEGO_INLANE_TIME)
static fTime_t      LA_f_GetHighEgoVelInLaneTimeThreshold(const ObjNumber_t iObj, fTime_t fTimeThreshInLane);
#endif

#if (LA_TTC_DEPENDANT_INLANE_TIME)
static fTime_t      LA_f_TTCDependantInLaneTimeThreshold(ObjNumber_t iObj, fTime_t fTimeThreshInLane);
#endif
/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/
// PRQA S 7013 STTLN_EXCEEDED
/* date: 2017-11-24, reviewer: Grant Davtjan, reason: Number of lines exceeded per file, not safety critical */
/*************************************************************************************************************************
  Functionname:    LA_v_GeometricLaneAssoc                                                                     */ /*!

  @brief           Execute geometrical (inlap based) lane association.

  @description     This function is performing the purely geometrical inlap-based lane association for an object.
                   The first step is to compute the inlap value of the object using the bracket positions, the object position
                   and the distance to trajectory of the object. Then, the inlap value is used to set the flags 
                   for the inlane and outlane specific inlap criteria. In the third step, dependent on state of transition
                   (LAInlaneState) some additional signals are reseted in case the inlap criteria is not fulfilled for the 
                   inlane-to-outlane transition case.

                  @startuml
                  Partition LA_v_GeometricLaneAssoc
                  Start
                  :Get bracket position
                  **LA_t_GetBracketPosition**;
                  :Calculate inlap of object and store it in output signal
                  **LA_v_CalculateInlap**;
                  partition SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE{
                    :store overlap for later usage in calculation of cutin potential;
                  }
                  :Calculate and store geometric object pickup and drop thresholds
                  **LA_v_SetObjInlapPickupThreshold**
                  **LA_v_SetObjInlapDropThreshold**;
                  :Check and store geometric in- and out-lane criteria
                  **LA_v_GeometricLaneAssocInLaneCriteria**
                  **LA_v_GeometricLaneAssocOutLaneCriteria**;
                  :State Flow for Geometric Lane association
                  **LA_v_GeometricLaneAssocStateFlow**;
                  Stop
                  @enduml


  @return          void

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjTrajDistWidth : structure used for inlap computation [CPDistanceWidth_t as defined in la_ext.h]
                    ObjTrajDistWidth->fTrajectoryWidth: distance between borders of the corridor [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    ObjTrajDistWidth->fDistance : distance between center of the corridor and the center of the object [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjTrajRelation : structure containing result of inlap computation [LA_t_TrajInlap as defined in la_ext.h]
                    ObjTrajRelation->fInlap : Inlap value of the object [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    ObjTrajRelation->fInlapVar : Variance of Inlap value [full range of data type float32]

  @c_switch_part   SIT_CUTINPOTENTIAL_MULTIOBJECTANALYSE: Configuration switch to enable multi object analyze as one input for the cutin potential
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2018
  @changed         15.03.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
void LA_v_GeometricLaneAssoc(const ObjNumber_t iObj)
{
  LA_t_TrajInlap TrajInlap;
  LA_t_BracketOutput BracketPosition;
  LADistanceWidth_t *pDistWidth = &(pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajDistWidth);
  boolean InLInlapValue;

  /* Get bracket position*/
  BracketPosition = LA_t_GetBracketPosition(iObj);

  /* Calculate inlap of object and store it in output signal */
  LA_v_CalculateInlap(iObj, pDistWidth,BracketPosition.BracketPositionLeft, BracketPosition.BracketPositionRight, &TrajInlap);
  pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajRelation = TrajInlap;

  /* Calculate and store geometric object pickup threshold */
  LA_v_SetObjInlapPickupThreshold(iObj);

  /* Calculate and store geometric object drop threshold */
  LA_v_SetObjInlapDropThreshold(iObj);

  /* Check and store geometric in-lane criteria */
  LA_v_GeometricLaneAssocInLaneCriteria(iObj);

  /* Check and store geometric out-lane criteria */
  LA_v_GeometricLaneAssocOutLaneCriteria(iObj);

  /* State Flow for Geometric Lane association */
  InLInlapValue = (boolean)pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLInlapValue;
  LA_v_GeometricLaneAssocStateFlow(iObj, InLInlapValue);
}

/*************************************************************************************************************************
  Functionname:    LA_v_GeometricLaneAssocInLaneCriteria                                                                     */ /*!

  @brief           Set geometrical (inlap based) inlane criteria flag.

  @description     This function stores the geometrical (inlap based) inlane criteria flag signal. 

                   @startuml
                   partition LA_v_GeometricLaneAssocInLaneCriteria
                   start
                   :Get threshold for time condition for in lane decision of object
                   :adapt the object inlap pickup threshold to avoid cutIns
                   **LA_f_AdaptObjInlapPickupThresholdForCutIn**;
                   :Store inlap pickup threshold in inlap pickup threshold sim
                   :Check the object inlap value for inlane decision of object
                   **LA_b_CheckObjInlapPickupValue**;
                   :store inlane inlap criteria flag;
                   stop
                   @enduml


  @return          void

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       f_ObjInlapPickupThresh : Pickup threshold of the object ... [0.0f   PI/2*RW_FCT_MAX]m

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjTrajRelation : structure containing result of inlap computation [LA_t_TrajInlap as defined in la_ext.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLInlapValue : Outlane inlap flag [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLTimeValue : Inlane timer satisfied [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLDistValue : Inlane Distance satisfied [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2018
  @changed         15.03.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
void LA_v_GeometricLaneAssocInLaneCriteria(const ObjNumber_t iObj)
{
  boolean b_InlapValue = FALSE;
  const LA_t_TrajInlap *p_Inlap = &(pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajRelation);
  float32 f_ObjInlapPickupThresh = pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapPickupThresh;

  f_ObjInlapPickupThresh = LA_f_AdaptObjInlapPickupThresholdForCutIn(iObj, f_ObjInlapPickupThresh);
  /* temporary to be removed later */
#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[iObj].fObjInlapPickupThreshSIM = f_ObjInlapPickupThresh;
#endif 

  b_InlapValue = LA_b_CheckObjInlapPickupValue(p_Inlap, f_ObjInlapPickupThresh);

  /* store inlane inlap criteria flag */
  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLInlapValue = b_InlapValue;
}

/*************************************************************************************************************************
  Functionname:    LA_v_GeometricLaneAssocOutLaneCriteria                                                                     */ /*!

  @brief           Set geometrical (inlap based) outlane criteria flag.

  @description     This function stores the geometrical (inlap based) outlane criteria flag signal.
              
                   @startuml
                   partition LA_v_GeometricLaneAssocOutLaneCriteria
                   start
                   :Check the objects inlap value for inlane decision of object
                   **LA_b_CheckObjInlapDropValue**;
                   :store the result in global outlane inlap value;
                   stop
                   @enduml


  @return          void

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjTrajRelation : structure containing result of inlap computation [LA_t_TrajInlap as defined in la_ext.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapDropThresh : Drop threshold of the object ... [0.0f   PI/2*RW_FCT_MAX]m
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.OutLInlapValue : Outlane inlap flag [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2018
  @changed         15.03.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
void LA_v_GeometricLaneAssocOutLaneCriteria(const ObjNumber_t iObj)
{
  const LA_t_TrajInlap *p_Inlap = &(pt_LAOutput->t_LAObjOutputList[iObj].ObjTrajRelation);
  const float32 f_ObjDropThresh = pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapDropThresh;

  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.OutLInlapValue  = LA_b_CheckObjInlapDropValue(p_Inlap, f_ObjDropThresh);
}

/*************************************************************************************************************************
  Functionname:    LA_v_GeometricLaneAssocStateFlow                                                                     */ /*!

  @brief           Set geometrical (inlap based) inlane criteria flag.

  @description     Dependent on the final lane association from the last cycle (LAInlaneState) some additional signals are reseted 
                   in case the inlap criteria is not fulfilled in the current cycle. The resetting is only necessary for the 
                   outlane-to-inlane transition case.
                   @startuml
                   partition LA_v_GeometricLaneAssocStateFlow
                   start
                     if(LA Inlane State is equal to "Object is not in ego lane") then (yes)
                       if(In lap value is True) then (yes)
                   	  -set LA ACC lane status to "Object is in-lane"
                   	else
                   	partition LA_v_ResetInlaneTimer {
                   	 -call LA_v_ResetInlaneTimer function
                   	}
                   	partition LA_v_ResetInlaneDistance {
                   	 -call LA_v_ResetInlaneDistance function
                   	}
                   	-set InLTimeValue and InLDistValue to false
                   	-set LA ACC lane status to "Object is Out-lane"
                   	endif
                   	-set Inlap In2OutlaneCounter to 0
                     else
                      -do nothing 
                     endif
                   stop
                   @enduml

  @return          void

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLInlapValue : Outlane inlap flag [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLTimeValue : Inlane timer satisfied [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLDistValue : Inlane Distance satisfied [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAActLaneState : State if object i is geometrically inlane [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.Inlap_In2OutlaneCounter : Inlap in-to-outlane counter [0u ... LA_IN2OUTLANE_MAX_TRANSITIONTIME]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2018
  @changed         12.02.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
extern void LA_v_GeometricLaneAssocStateFlow( const ObjNumber_t iObj, const boolean b_InLInlapValue )
{
  /* State Flow for Geometric Lane association */
  switch(pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState)
  {
    case OBJ_STATE_OUTLANE:
      if (b_InLInlapValue == TRUE)
      {
        pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAActLaneState = OBJ_STATE_INLANE;
      }
      else
      {
        LA_v_ResetInlaneTimer(iObj);
        LA_v_ResetInlaneDistance(iObj);
        pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLTimeValue = FALSE;
        pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLDistValue = FALSE;
        pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAActLaneState = OBJ_STATE_OUTLANE;
      }
      pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.Inlap_In2OutlaneCounter = 0u;
      break;

    case OBJ_STATE_INLANE:
      break;

    default:
      break;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_v_SetObjInlapPickupThreshold                                                                  */ /*!

  @brief           Calculate and store threshold for the object inlap value for inlane decision of object

  @description     Calculates and stores the threshold for object inlap value for inlane
                   decision of the specified object
                  @startuml
partition LA_v_SetObjInlapPickupThreshold {
start
  partition SLATE_CFG_NAVI_OBJ_LAT_DIST{
    -Update Navi lane width threshold depending on Road type
  }
  
  -Select thresholds values due to dynamic property:stationary, moving to stationary, oncoming
  if (object is stationary but not moving to stationary or object is oncoming) then (true)
    -set "UseConservativeThresh" to False
	partition FCT_CFG_ROAD_INPUT {
	if(FIP Roadworks detected or EgoYawRateQuality is less than or equal la vdy yawrate qual sensor unlearned) then (yes)
	   -set "UseConservativeThresh" to False
	endif
	}
	
	if(EgoYawRateQuality is less than or equal la vdy yawrate qual sensor unlearned) then (yes)
	   -set "UseConservativeThresh" to True
	endif
	
	if(Object Classification is point) then (yes)
	  -set PickupThresholdObj to object inlane pickup thres stat point
	elseif(UseConservativeThresh is true) then (yes)
	  -set PickupThresholdObj to object inlane pickup thres stat conservative
	else
	   - set PickupThresholdObj to la object inlane pickup Threshold stat
	endif
  partition LA_CFG_ADAPT_PICKUP_THD_CAM_TRAJ_LA {
    if(Object is associated to ego lane based on camera trajectory lane association with good confidence) then (yes)
     -Reduce pickup threshold by a factor
    endif
  }  
	partition LA_CFG_ENABLE_PARKED_DETECTION {
	 if(RoadSideParkedObj is true) then (yes)
	   -set PickupThresholdObj to la obj inlane pickup Threshold parked obj
	  endif
	}
  else
   -Increase object inlap pick-up threshold in case cluster variance of object is high
  endif
  
  if(ObjClassification is truck) then (Yes)
     -set PickupThresholdObj to sum of PickupThresholdObj and la obj inlane adj thres
  elseif(ObjClassification is point or motercycle and uiClassConfidence is greater than or equal to la min class confidence) then (yes)
     -set PickupThresholdObj to difference of PickupThresholdObj and la obj inlane adj thres
  partition LA_CFG_CAM_INLANE_THRSHOLD_UPDATE{
    -Reduce Pick-Up threshold for camera confirmed cars to improve slow cut-ins in city (necessary if no cut-in dynamic available and no lane marker exists)
  }
  else
  endif
  
  partition SLATE_CFG_NAVI_OBJ_LAT_DIST {
  if(Check for Road works, Check for city speeds, Check if Ego is making Lane change, Check Ego Curve incase of Lane Exits Don't Update the threshold) then (yes)
    - do noting
  else
    -If Object is near to Navi Trajectory Decrease PU Threshold
	-If Object is far from Navi Trajectory Increase PU Threshold
  endif
  }
stop
}
@enduml
  @return          void

  @param[in]       iObj : object for which inlap is checked [0   EM_N_OBJECTS-1]

  @glob_in         *SLATE_pt_GetObjDynProperty(iObj)                      : Dynamic property of object with ID iObj                          [type SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(iObj)               : Boolean to know if the object is moving or not                   [TRUE, FALSE]
  @glob_in         ROAD_TYPE2                                      : enum for road type                                               [type eRoadTypeLevel2_t defined in Rte_Type.h]
  @glob_in         pt_LAInput->t_RTE.f_EgoYawRateQuality                        : Yaw rate quality of ego                                          [Quality_t as in Rte_Type.h]
  @glob_in         OBJ_GET_SI(iObj).ObjLaneAccStatus.SIInlaneState : State if object i is inlane or not (confirmed with all criteria) [SILaneState_t as defined in si_ext.h]
  @glob_in         OBJ_GET_SI(iObj).ui_ClusterVarianceLevel        : Difficulty level of object i with high cluster variance          [SI_CLUST_VAR_LEVEL_LOW ... SI_CLUST_VAR_LEVEL_DIFFICULT]
  @glob_in         *SLATE_pt_GetObjClassification(iObj)                        : Classification (into type) of object                             [type SLATE_t_Obj_CLassification defined in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc : Camera trajectory based lane association of an object i    [0      3]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].f_ObjCamTrajLaneAssocProb : Probability of Camera trajectory based lane association of an object i    [0      100u]

  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapPickupThresh : Pickup threshold of the object [0.0f   PI/2*RW_FCT_MAX]m

  @c_switch_part   SLATE_CFG_NAVI_OBJ_LAT_DIST                : Bracket adaptation based on Navi data
  @c_switch_part   FCT_CFG_ROAD_INPUT                         : Road estimation input to FCT
  @c_switch_part   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Configuration switch to enable cluster variance usage for inlane decision
  @c_switch_part   LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA      : Configuration switch to adapt Pickup Threshold based on the Camera Trajectory Based Lane Association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION               : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         15.03.2018

  @author          Christopher Knievel
*************************************************************************************************************************/
static void LA_v_SetObjInlapPickupThreshold( const ObjNumber_t iObj )
{
  float32 f_PickupThresholdObj;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(iObj);
  boolean bObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(iObj);
#if(LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA)
  LA_t_ObjCamTrajLanAssocEnum t_ObjCamLaneAssoc = pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc;
  float32 f_ObjCamTrajLaneAssocProb =  pt_LAOutput->t_LAObjOutputList[iObj].f_ObjCamTrajLaneAssocProb ;
  float32 f_TunnelProb = *pt_LAInput->t_RTE.pf_TunnelProbability;
#endif /* (LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA) */
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
  SIT_LC_t_LaneChangePhaseEnum tLCPhase = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase;
  float32 f_EgoVelObjSync    = *(pt_LAInput->t_RTE.pf_EgoVelObjSync);
  float32 f_ObjLongDisp      = *(pt_LAInput->t_RTE.pf_ObjLongDisp(iObj));
  fCurve_t f_Curve           = *(pt_LAInput->t_CP.pf_CourseCurve);
  float32 f_ABS_Curve        = fABS(f_Curve);
  float32 f_NaviLanewidth;
  FIP_t_FusedRoadType iRoadTypeLevel;

  iRoadTypeLevel = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
  /*Update Navi lane width threshold depending on Road type */
  if(iRoadTypeLevel == FIP_ROAD_TYPE_HIGHWAY)
  {
    f_NaviLanewidth = (LA_STANDARDLANEWIDTHSEEK/2.f);
  }
  else
  {
    f_NaviLanewidth = (LA_CITYLANEWIDTHSEEK/2.f);
  }

#endif /*end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
#endif /*end of(SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)*/

#if(LA_CFG_CAM_INLANE_THRSHOLD_UPDATE)
  percentage_t t_camConfirmationProb = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_CamConfirmationProb;
  float32 fObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
#endif

  /* Select thresholds due to dynamic property */
  if ( ( ( t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
      && (bObjIsMovingToStationary == FALSE)
       )
    || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
     )
  {
    boolean b_UseConservativeThresh = FALSE;
#if (FCT_CFG_ROAD_INPUT)
    /* Check if Road Works Situation or unlearned sensor*/
    if ( ((pt_LAInput->pt_FIPRoadType->t_FIPRoadWorks) == FIP_ROADWORKS_DETECTED)
      || (pt_LAInput->t_RTE.f_EgoYawRateQuality <= LA_VDY_YAWRATE_QUAL_SENSOR_UNLEARNED)
       )
    {
      b_UseConservativeThresh = TRUE;
    }
#else
    if(pt_LAInput->t_RTE.f_EgoYawRateQuality <= LA_VDY_YAWRATE_QUAL_SENSOR_UNLEARNED)
    {
      b_UseConservativeThresh = TRUE;
    }
#endif /* FCT_CFG_ROAD_INPUT */

    if (t_ObjClassification == SLATE_OBJCLASS_POINT)
    {
      f_PickupThresholdObj = LA_OBJ_INLANE_PICKUP_THRES_STAT_POINT;
    }
    else if (b_UseConservativeThresh == TRUE)
    {
      f_PickupThresholdObj = LA_OBJ_INLANE_PICKUP_THRES_STAT_CONSERVATIVE;
    }
    else
    {
      f_PickupThresholdObj = LA_OBJ_INLANE_PICKUP_THRES_STAT;
	  /* Decrease inlap pick-up threshold in case object is associated to ego lane by camera trajectory with good confidence */
#if (LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA)
      if( (t_ObjCamLaneAssoc == LA_OBJ_CAM_LANE_EGO) && (f_ObjCamTrajLaneAssocProb > LA_CAM_TRAJ_LA_PICKUP_PROB) 
          && (f_TunnelProb < LA_TUNNEL_PROB_THRES)
          && ( t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
        )
      {
        f_PickupThresholdObj -= LA_CAM_TRAJ_LA_PICKUP_THRES;
      }
#endif /* (LA_CFG_ADAPT_PICKUP_THRES_CAM_TRAJ_LA) */
    }

#if (LA_CFG_ENABLE_PARKED_DETECTION)
    if(pt_LAOutput->b_RoadSideParkedObj[iObj] == TRUE)
    {
      f_PickupThresholdObj = LA_OBJ_INLANE_PICKUP_THRES_PARKED_OBJ;
    } 
#endif /* end of LA_CFG_ENABLE_PARKED_DETECTION */

  }
  else
  {
#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
    /* Increase object inlap pick-up threshold in case cluster variance of object is high */
    if ( (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState == OBJ_STATE_OUTLANE) 
      && (t_LA_InternalObjectData[iObj].ui_ClusterVarianceLevel > LA_CLUST_VAR_LEVEL_LOW ) )
    {
      f_PickupThresholdObj  = LA_CLUST_VAR_OBJ_OCCU_PICKUP_THRES_DIFFICULT;
    } else
#endif
    {
      f_PickupThresholdObj  = LA_OBJ_INLANE_PICKUP_THRES;
    }
  }
  if (t_ObjClassification == SLATE_OBJCLASS_TRUCK)
  {
    f_PickupThresholdObj  += LA_OBJ_INLANE_ADJ_THRES;
  }
  else if ( (( (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE)
             ||(t_ObjClassification == SLATE_OBJCLASS_POINT)
			 || (t_ObjClassification == SLATE_OBJCLASS_BICYCLE)
             )
            &&((SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence >= LA_MIN_CLASS_CONFIDENCE)
			||
			((t_ObjClassification == SLATE_OBJCLASS_BICYCLE) && (SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence >= LA_MIN_BICYCLE_CLASS_CONFIDENCE) ))
            )
#if(LA_CFG_CAM_INLANE_THRSHOLD_UPDATE)
            /* Use reduced confidence if motorcycle is camera confirmed */
            ||((t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE)
              && (t_camConfirmationProb > (percentage_t)LA_MIN_CAM_CONFIRMATION_CONF)
              && (SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence >= LA_REDUCED_CLASS_CONFIDENCE)
            )
#endif
          )
  {
    f_PickupThresholdObj  -= LA_OBJ_INLANE_ADJ_THRES;
  }
#if(LA_CFG_CAM_INLANE_THRSHOLD_UPDATE)
  /* Reduce Pick-Up threshold for camera confirmed cars to improve slow cut-ins in city (necessary if no cut-in dymanic available and no lane marker exists) */
  else if((t_ObjClassification == SLATE_OBJCLASS_CAR)
           && (EGO_SPEED_X_OBJ_SYNC <= LA_MAX_EGO_VEL_CITY)
           && ((fObjLongDisp <= LA_MAX_DIST_PICKUP_REDUCTION_CAM) && (fObjLongDisp > LA_MIN_DIST_PICKUP_REDUCTION_CAM)) 
           && (t_camConfirmationProb > (percentage_t)LA_MIN_CAM_CONFIRMATION_CONF)
           && (SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence >= LA_REDUCED_CLASS_CONFIDENCE)
           && (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
         )
  {
    f_PickupThresholdObj  -= LA_OBJ_INLANE_ADJ_THRES_CAM;
  }
#endif
  else
  {

  }

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
  /* Check for Road works, Check for city speeds, 
  Check if Ego is making Lane change, Check Ego Curve
  incase of Lane Exits Don't Update the threshold */
  if((pt_LAInput->pt_FIPRoadType->t_FIPRoadWorks == FIP_ROADWORKS_DETECTED) 
      || ( (f_EgoVelObjSync > LA_CITY_MAX_SPEED) || (f_EgoVelObjSync < LA_CITY_MIN_SPEED) )
      || ( tLCPhase != LC_NO_LANECHANGE )
      || ( (f_ObjLongDisp > pt_LAInput->pt_FIPNaviData->f_DistNextLeftExit) || (f_ObjLongDisp > pt_LAInput->pt_FIPNaviData->f_DistNextRightExit) )
      || ( f_ABS_Curve > LA_ALLOWED_EGO_CURVE )
      )
  {
    /* do not update Threshold */
  }
  else
  {
    if(fABS(pt_LAInput->pt_FIPNaviData->t_ObjList[iObj].f_NaviLatDist) < f_NaviLanewidth )
    {
      /* If Object is near to Navi Trajectory Decrease PU Threshold */
      f_PickupThresholdObj *= LA_INLAP_PU_NAVI_NEAR_OBJ;
    }
    else if ((fABS(pt_LAInput->pt_FIPNaviData->t_ObjList[iObj].f_NaviLatDist) > f_NaviLanewidth) &&  (fABS(pt_LAInput->pt_FIPNaviData->t_ObjList[iObj].f_NaviLatDist) < FIP_MAX_DIST_TEN_HIGHWAY_LANES) )
    {
      /* If Object is far from Navi Trajectory Increase PU Threshold */
      f_PickupThresholdObj *= LA_INLAP_PU_NAVI_FAR_OBJ;
    }
    else
    {
      /* Do Nothing */
    }
  }
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
#endif /*end of(SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)*/

  pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapPickupThresh = f_PickupThresholdObj;
  /* Temporary to be removed later */
#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[iObj].fObjInlapPickupThreshSIM = f_PickupThresholdObj;
#endif 
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetCorrectedInlap                                                                           */ /*!

  @brief           Get corrected inlap value

  @description     The inlap value is corrected w.r.t. the standard deviation
                   @startuml
                   partition LA_f_GetCorrectedInlap
                   start
                   :correct inlap value with the standard deviation;
                   stop
                   @enduml
  @return          f_RetInlap : correct inlap value [0   PI/2*RW_FCT_MAX]m

  @param[in]       p_Inlap : Inlap information [Pointer to structure CPTrajInlap_t defined in cp_ext.h]
                    p_Inlap->fInlapVar  : Inlap variance                        [0   PI/2*RW_FCT_MAX]
                    p_Inlap->fInlap     : Inlap value                           [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         8/25/2016

  @author          Christopher Knievel
*************************************************************************************************************************/
float32 LA_f_GetCorrectedInlap(const LA_t_TrajInlap * p_Inlap )
{
  float32 f_RetInlap;
  const float32 f_ObjInlapStd = SQRT_(p_Inlap->fInlapVar);

  /* Use the probability that the object is within the ego lane to compute
     a scaling factor. That means that more uncertain we are that the object
     is actually within the ego lane, the harder it is for the object to get
     into and vice versa.*/
     f_RetInlap = p_Inlap->fInlap - LA_INLAP_CORR_STD_DEV_WEIGHT_FACTOR * f_ObjInlapStd;

  return f_RetInlap;
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjInlapPickupValue                                                                    */ /*!

  @brief           Check the object inlap value for inlane decision of object

  @description     Check the object inlap value for inlane decision of object

                   @startuml
                   partition LA_b_CheckObjInlapPickupValue
                   start
                   :initialize return value;
                   :Correct inlap value
                   **LA_f_GetCorrectedInlap**;
                   if (inlap is greater than inlap pickup threshold) then (true)
                   :set the return value to TRUE;
                   endif
                   stop
                   @enduml


  @return          Boolean if object is in-lane based on object inlap (pick-up) [TRUE, FALSE]

  @param[in]       p_Inlap : Inlap information [Pointer to structure CPTrajInlap_t defined in cp_ext.h]
  @param[in]       f_ObjInlapPickupThresh : Pickup threshold of the object [0.0f   PI/2*RW_FCT_MAX]m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (iObj)             : Longitudinal distance of the object        [-5*RW_FCT_MAX   5*RW_FCT_MAX]m
  @glob_in         *SLATE_pt_GetObjClassification(iObj)                : Classification (into type) of object       [type SLATE_t_Obj_CLassification defined in Rte_Type.h]
  @glob_in         SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence  : Confidence of object class                 [0u   90u]
  @glob_in         *SLATE_pt_GetObjDynProperty(iObj)              : Dynamic property of the object             [type SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
  @glob_in         OBJ_GET_FUNC_LANE(iObj)                 : Functional lane the object is assigned to  [type eAssociatedLane_t defined in Rte_Type.h]
  @glob_in         OBJ_LAT_VREL(iObj)                      : Lateral velocity of the object             [-330f   330f]m/s

  @glob_out        -

  @c_switch_part   None
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         15.03.2018

  @author          Christopher Knievel
*************************************************************************************************************************/
extern boolean LA_b_CheckObjInlapPickupValue( const LA_t_TrajInlap * p_Inlap, const float32 f_ObjInlapPickupThresh)
{
  boolean b_result = FALSE;
  const float32 f_Inlap = LA_f_GetCorrectedInlap(p_Inlap);

  if(f_Inlap > f_ObjInlapPickupThresh)
  {
    b_result = TRUE;
  }
  return( b_result );
}

/*************************************************************************************************************************
  Functionname:         LA_f_AdaptObjInlapPickupThresholdForCutIn                                                  */ /*!

  @brief                Adaption of the inlap pickup threshold to improve car and motorcycle cutins

  @description          Reduction of the inlap pickup threshold to improve car and motorcycle cutins falling in the range 
                        [SI_MIN_DIST_CLOSE_CUTIN, SI_MAX_DIST_CLOSE_CUTIN]. 
                        @startuml
                        partition LA_f_AdaptObjInlapPickupThresholdForCutIn{
                        start
                            if (longitudinal distance is within rangeand classification is car or motorcycle and class confidence is greater than threshold and object is not stationary and object is on left or right lane and lateral velocity is above threshold) then (true)
                              :reduce inlap pickup threshold for object;
                            else if (object is not stationary and not stopped) then (true)
                              :reduce inlap pickup threshold for object;
                              if(object is real) then (yes)
                                 if(relObjLongDisp is greater than Pickup threshold of Inlap minimum) then (yes)
                        		    -set EgoLaneFree to true
                        		  endif
                              else
                                 -set EgoLaneFree to true
                              endif
                                
                              if(ego velocity is greater than Pickup threshold of Inlap minimum and object velocity is greater than LA GEO REL X VEL MIN and ego lane is free) then (true)
                                 if (ObjLatVel is greater than equal to  LA MIN VREL Y and ObjFuncLane is equal to ASSOC LANE RIGHT or ObjLatVel is less than -1.0f*LA MIN VREL Y
                                     and ObjFuncLane is equal to associated lane left) then (yes)
                                 -set ObjInlapThresh to minimum of ObjInlapPickupThresh and mathLineareFunktion
                                 endif
                              endif
                               
                            else (false)
                             -set ObjInlapThresh to ObjInlapPickupThresh
                            endif
                        end
                        }
                        @enduml


  @return               f_ObjInlapThresh : Pickup threshold of the object [0.0f   PI/2*RW_FCT_MAX]m

  @param[in]            iObj : Objet ID of the object for which inlap pickup value is to be determined [0   EM_N_OBJECTS-1]
  @param[in]            f_ObjInlapPickupThresh : Pickup threshold of the object [0.0f   PI/2*RW_FCT_MAX]m

  @glob_in              pt_LAOutput->t_LAObjOutputList[iObj].ObjFuncLane : Functional lane the object is assigned to  [type eAssociatedLane_t defined in Rte_Type.h]
  @glob_in              *pt_LAInput->t_RTE.pf_ObjVrelY(iObj) : Lateral velocity of the object             [-330f   330f]m/s
  @glob_in              *pt_LAInput->t_RTE.pf_ObjLongDisp  (iObj)             : Longitudinal distance of the object        [-5*RW_FCT_MAX   5*RW_FCT_MAX]m
  @glob_in              *SLATE_pt_GetObjClassification(iObj) : Classification (into type) of object       [type SLATE_t_Obj_CLassification defined in Rte_Type.h]
  @glob_in              SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence
  @glob_in              *SLATE_pt_GetObjDynProperty(iObj) : Dynamic property of the object             [type SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
  @glob_in              *pt_LAInput->t_RTE.pf_ObjVrelX(iObj) : Object relative longitudinal velocity
  @glob_out             -

  @c_switch_part        -
  @c_switch_full        FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @pre                  -
  @post                 -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @created         		15.03.2018
  @changed         		15.03.2018

  @author               Yvonne Strigel | Yvonne.Strigel@continental-corporation.com | +49 (8382) 9699-696
*************************************************************************************************************************/
extern float32 LA_f_AdaptObjInlapPickupThresholdForCutIn( ObjNumber_t iObj, float32 f_ObjInlapPickupThresh )
{
  float32 f_ObjInlapThresh;
  eAssociatedLane_t t_ObjFuncLane = pt_LAOutput->t_LAObjOutputList[iObj].ObjFuncLane;
  float32 f_ObjLatVel = *pt_LAInput->t_RTE.pf_ObjVrelY(iObj);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(iObj);
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(iObj);
  float32 fObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);

 #if (LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD)
  float32 f_EgoVelObjSync = *(pt_LAInput->t_RTE.pf_EgoVelObjSync);
  float32 f_ObjVelX       = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj);
  float32 f_ABS_ObjLatVel, f_mathLineareFunktion;
  ObjNumber_t relobj = SLATE_i_GetRelObjIndex();
  boolean b_EgoLaneFree = FALSE;
 #endif /* END IF LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD */

    /*Logic implemented to improve car and motorcycle cutins falling in the range [SI_MIN_DIST_CLOSE_CUTIN, SI_MAX_DIST_CLOSE_CUTIN]
      by reducing the pickup threshold; the objects have to be in the adjacent lanes and moving, to be considered here.
      Class confidence is considered to prevent misclassified drop-ins*/
  if ( (fObjLongDisp <= LA_MAX_DIST_CLOSE_CUTIN)
    && (fObjLongDisp>=LA_MIN_DIST_CLOSE_CUTIN)
    && ( ( (t_ObjClassification == SLATE_OBJCLASS_CAR) 
        || (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE)
         )
      && (SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence >= LA_MIN_CLASS_CONFIDENCE)
       )
    && ((t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY) 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
     && (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */ 
       )
    && ( ( (t_ObjFuncLane == ASSOC_LANE_RIGHT)
        && (f_ObjLatVel >= LA_MIN_LAT_VELO)
         )
      || ( (t_ObjFuncLane == ASSOC_LANE_LEFT)
        && (f_ObjLatVel <= -1.0*LA_MIN_LAT_VELO)
         )
       )
     )
  {
    f_ObjInlapThresh = f_ObjInlapPickupThresh - LA_CUTIN_REDUCTION_VALUE;
  }
  else if ((t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
        && (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */ 
          )
  {
    f_ObjInlapThresh = f_ObjInlapPickupThresh - dGDBmathLineareFunktion(&LAPickUpThreshInLaneFromDist, *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj));

#if (LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD)
    if (relobj != OBJ_INDEX_NO_OBJECT)
    {
       float32 f_relObjLongDisp = (*pt_LAInput->t_RTE.pf_ObjLongDisp(relobj));
       if (f_relObjLongDisp > LA_GEO_REL_X_MIN)
       {
          b_EgoLaneFree = TRUE;
       }
    }
    else
    {
      b_EgoLaneFree = TRUE;
    }

    if ((f_EgoVelObjSync > LA_GEO_EGO_VEL_MIN) && (f_ObjVelX > LA_GEO_REL_X_VEL_MIN) && (b_EgoLaneFree == TRUE))
    {
      if (((f_ObjLatVel >= LA_MIN_VREL_Y) && (t_ObjFuncLane == ASSOC_LANE_RIGHT))
          || ((f_ObjLatVel <= -1.0f *LA_MIN_VREL_Y) && (t_ObjFuncLane == ASSOC_LANE_LEFT)))
      {
		/* PRQA S 2200 3 *//* Date: 2020-04-02, Reviewer:Gireesh , Reason:This warning is suppressed as Indentation does not have any critical impact the functionality. */  
		f_ABS_ObjLatVel = fABS(f_ObjLatVel);
		f_mathLineareFunktion = dGDBmathLineareFunktion(&LAPickUpThreshFromLatVelo, f_ABS_ObjLatVel);
        f_ObjInlapThresh = MIN(f_ObjInlapThresh, (f_ObjInlapPickupThresh - f_mathLineareFunktion));
      }    
    }
#endif /* END IF LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD */
  }
  else
  {
    f_ObjInlapThresh = f_ObjInlapPickupThresh;
  }
#if (LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX)
  f_ObjInlapThresh = f_ObjInlapThresh + dGDBmathLineareFunktion(&LAPickUpThreshFromLongVelo, *pt_LAInput->t_RTE.pf_ObjVrelX(iObj));
#endif /*END IF LA_CFG_INLANE_INLAP_PICKUP_THRESHOLD_VRELX*/

  return f_ObjInlapThresh;
}

/*************************************************************************************************************************
  Functionname:    LA_v_SetObjInlapDropThreshold                                                                    */ /*!

  @brief           Calculate and store threshold for the object inlap value for inlane decision of object

  @description     Calculate and store object inlap drop threshold

                   @startuml
                   partition LA_v_SetObjInlapDropThreshold
                   start
                   :Select threshold values due to dynamic property:
                   stationary, moving to stationary, oncoming;
                   if (object is stationary but not moving to stationary or object is oncoming) then (true)
                     :set inlap drop threshold to value for stationary objects;
                   else (false)
                     partition LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION {
                     :Increase object inlap drop threshold in case cluster variance of object is high;
                     }
                     :otherwise adapt threshold dependent on corridor relevant time of the object;
                   endif
                   :reduce the threshold for objects of class truck;
                   :increase the threshold for objects of class 
                   motorcycle, point, pedestrian and bicycle;
                   :set output variable for inlap drop threshold of the object;
                   
                     partition LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD {
                       -Increase object inlap drop threshold based on OOI-0 & OOI-1 kinematics
                   	if(object is relevant) then (yes)
                   	    -increase Object Inlap Drop threshold values
                   		if(OOI-0 is moving at faster speed than OOI-1 in longitudinal direction and Dynamic property of OOI-0 is not Stationary and not stopped
                   		   Classification of OOI-0 must not be Truck and Minimum distance between Ego and OOI-0 must be greater than LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_EGO
                   		   Minimum distance between OOI-0 and OOI-1 must be greater than LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_HIDOOI and 
                   		   Absolute speed of OOI-1 in longitudinal direction must be greater than LA_MIN_ABS_VEL_OF_HID_OOI_IN_X) then (yes)
                   		     -Increase Object Inlap Drop threshold if all the above conditions are satisfied
                   	    endif
                   		
                   	endif
                     }
                   stop
                   @endum


  @return          void 

  @param[in]       iObj : Objet for which inlap are checked [0   EM_N_OBJECTS-1]

  @glob_in         *SLATE_pt_GetObjDynProperty(iObj)                               : Dynamic property of the object                                   [type SLATE_t_Obj_DynamicProperty defined in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(iObj)                        : Boolean to know if the object is moving or not                   [TRUE, FALSE]
  @glob_in         OBJ_GET_SI(iObj).ObjLaneAccStatus.SIInlaneState          : State if object i is inlane or not (confirmed with all criteria) [SILaneState_t as defined in si_ext.h]
  @glob_in         OBJ_GET_SI(iObj).ui_ClusterVarianceLevel                 : Difficulty level of object i with high cluster variance          [SI_CLUST_VAR_LEVEL_LOW ... SI_CLUST_VAR_LEVEL_DIFFICULT]
  @glob_in         OBJ_GET_SI(iObj).ObjLaneAccStatus.fCorridorRelevantTime  : Time the relevant object has been seen inlane                    [full range of data type float > 0.f]
  @glob_in         *SLATE_pt_GetObjClassification(iObj)                                 : Classification (into type) of object                             [type SLATE_t_Obj_CLassification defined in Rte_Type.h]
  @glob_in          SLATE_b_GetObjIsRelevant(iObj) : whether the object is OOI-0 or not
  @glob_in         *SLATE_pf_GetEgoLongVel(iObj) :  Ego velocity provided by VDY                [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjVrelX(iObj) : Relative velocity of object iObj in Longitudinal direction                    [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjVrelY(iObj) : Relative velocity of object iObj in Lateral direction                    [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapDropThresh : object inlap drop threshold  [0.0f   PI/2*RW_FCT_MAX]m

  @c_switch_part   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Configuration switch to enable cluster variance usage for inlane decision
  @c_switch_part   FCT_SIMU : Compiler switch used for simulation purpose
  @c_switch_part   LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD  : Configuration switch which enables the adaptation of object Inlap drop threshold based on OOI-0 and OOI-1 kinematics
  @c_switch_part   LA_CFG_TRAJ_DYNAMISM_DETECTION : Configuration switch which enables the adaptation of object Inlap drop threshold based on Trajectory Dynamism calculations
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         15.03.2018

  @author          Fridolin Kolb,  fridolin01.kolb@contiautomotive.com
*************************************************************************************************************************/
static void LA_v_SetObjInlapDropThreshold( const ObjNumber_t iObj )
{
  float32 f_DropThresholdObj;
  float32 f_ABS_EgoCurve;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *SLATE_pt_GetObjDynProperty(iObj);
  boolean bObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(iObj);

#if (LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD)
  /* Absolute speed of OOI-1 in longitudinal direction */
  float32 f_VabsXSpd;
  /* Absolute speed of OOI-0 in longitudinal direction */
  float32 f_VabsXSpdooi;
  /* Longitudinal displacement to the object (OOI-1) from Ego */
  float32 f_hidooilongdisp;
  /* FCT ID of OOI-1 */
  ObjNumber_t relobj; 
  boolean b_ObjisRelevant = SLATE_b_GetObjIsRelevant(iObj);
  /* Longitudinal displacement to the object (OOI-0) from Ego */
  float32 f_ooilongdisp =  *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
#endif /* END IF LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD */

  /* Select thresholds due to dynamic property */
  if ((  ( t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
        &&(bObjIsMovingToStationary == FALSE)
      )
      || (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_ONCOMING)
     )
  {
    f_DropThresholdObj  =  LA_OBJ_INLANE_DROP_THRES_STAT;
  }
  else
  {
#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
    /* Increase object inlap drop threshold in case cluster variance of object is high */
    if ( (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState == OBJ_STATE_OUTLANE) 
      && (t_LA_InternalObjectData[iObj].ui_ClusterVarianceLevel > LA_CLUST_VAR_LEVEL_LOW ) )
    {
      f_DropThresholdObj  = LA_CLUST_VAR_OBJ_OCCU_DROP_THRES_DIFFICULT;
    } else
#endif
      if ( pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime < LA_MAX_REL_TIMER_DROP_OCC_THRES )
      {
        f_DropThresholdObj = ((LA_OBJ_INLANE_DROP_THRES - LA_SUM_NONSTAT_DROP_OCC_THRES) * pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime) 
          + LA_SUM_NONSTAT_DROP_OCC_THRES;
        f_DropThresholdObj = MIN_FLOAT(LA_OBJ_INLANE_DROP_THRES, f_DropThresholdObj);
      }
      else
      {
        f_DropThresholdObj  = LA_OBJ_INLANE_DROP_THRES;
      }
  }
  if (t_ObjClassification == SLATE_OBJCLASS_TRUCK)
  {
    f_DropThresholdObj  += LA_OBJ_DROP_ADJ_THRES; 
  }
  else if((t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE) || (t_ObjClassification == SLATE_OBJCLASS_POINT) 
       || (t_ObjClassification == SLATE_OBJCLASS_PEDESTRIAN) || (t_ObjClassification == SLATE_OBJCLASS_BICYCLE))
  {
    f_DropThresholdObj  -= LA_OBJ_DROP_ADJ_THRES;
  }
  else
  {
    /* QAC error fix */
  }

  f_ABS_EgoCurve = fABS(*pt_LAInput->t_RTE.pf_EgoCurve);
  if (f_ABS_EgoCurve >= LA_INLANE_CURVE_MIN)
  {
    f_DropThresholdObj = (LA_OUTLANE_INLAP_MUL_FACT) * (f_DropThresholdObj);
  }

#if (LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD)

  /* Increase object inlap drop threshold based on OOI-0 & OOI-1 kinematics */
  relobj = *pt_LAInput->t_OOI.pu_OOIListObjId((uint8)OBJ_HIDDEN_NEXT_OOI);
  
  /* Increase Object Inlap Drop threshold values if the below conditions are satisfied */
  if((b_ObjisRelevant != FALSE) && (relobj != OBJ_INDEX_NO_OBJECT))
  {
    f_hidooilongdisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(relobj);
    f_VabsXSpdooi = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj) + *SLATE_pf_GetEgoLongVel();
    f_VabsXSpd = *pt_LAInput->t_RTE.pf_ObjVrelX(relobj) + *SLATE_pf_GetEgoLongVel();

    /* OOI-0 must be moving at faster speed than OOI-1 in longitudinal direction */
   if(((f_VabsXSpdooi - f_VabsXSpd) > LA_MIN_DIFF_OF_ABS_VEL_IN_X) && 
     /* Dynamic property of OOI-0 must not be Stationary */
     ( (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY) 
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
   &&  (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STOPPED) 
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
     ) &&  
     /* Classification of OOI-0 must not be Truck */
     (t_ObjClassification != SLATE_OBJCLASS_TRUCK) && 
     /* Minimum distance between Ego and OOI-0 must be greater than LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_EGO */
     (f_ooilongdisp > LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_EGO) && 
     /* Minimum distance between OOI-0 and OOI-1 must be greater than LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_HIDOOI */
     ((f_hidooilongdisp - f_ooilongdisp) > LA_MIN_DIFF_OF_LONG_DISP_BTWN_OOI_HIDOOI) && 
     /* Absolute speed of OOI-1 in longitudinal direction must be greater than LA_MIN_ABS_VEL_OF_HID_OOI_IN_X */
     (f_VabsXSpd > LA_MIN_ABS_VEL_OF_HID_OOI_IN_X)) 
   {
    /* Increase Object Inlap Drop threshold if all the above conditions are satisfied */
    f_DropThresholdObj = (LA_ADAPT_OUTLANE_INLAP_MUL_FACT) * (f_DropThresholdObj) ;
   }
  }
#endif /* END IF (LA_CFG_ADAPT_OUTLANE_INLAP_DROP_THRESHOLD) */

#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
  f_DropThresholdObj = LA_v_AdaptObjInlapDropThresholdTrajDynamism(iObj, f_DropThresholdObj);
#endif /* LA_CFG_TRAJ_DYNAMISM_DETECTION */

  pt_LAOutput->t_LAObjOutputList[iObj].f_ObjInlapDropThresh = f_DropThresholdObj;
  /* Temporary to be removed later */
#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[iObj].fObjInlapDropThreshSIM = f_DropThresholdObj;
#endif 
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckObjInlapDropValue                                                                      */ /*!

  @brief           Check the objects inlap value for inlane decision of object

  @description     Check the objects inlap value for inlane decision of object
                   @startuml
                   partition LA_b_CheckObjInlapDropValue
                   start
                   :Initialize return value to FALSE;
                   if (Inlap is less than ObjectInlapDropThresh) then (true)
                     :set the return value to TRUE;
                   else (false)
                     if (Inlap is less than or equal to object occupancy drop border for insecure inlap values) then (true)
                       :set the return value to TRUE;
                     endif
                   endif
                   stop
                   @enduml
  @return          b_result : Boolean, returns TRUE if the object's inlap value is less than the Drop threshold [TRUE, FALSE]

  @param[in]       f_ObjectInlapDropThresh : Drop threshold of the object ... [0.0f   PI/2*RW_FCT_MAX]m
  @param[in]       p_Inlap : Inlap information [Pointer to the structure CPTrajInlap_t defined in cp_ext.h]
                    p_Inlap->fInlap    : Inlap value  [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]m
                    p_Inlap->fInlapVar : Inlap variance  [0   PI/2*RW_FCT_MAX]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SIMU: Compiler switch used for simulation purpose
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION: FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         15.03.2018

  @author          Fridolin Kolb,  fridolin01.kolb@contiautomotive.com
*************************************************************************************************************************/
extern boolean LA_b_CheckObjInlapDropValue( const LA_t_TrajInlap* p_Inlap, float32 f_ObjectInlapDropThresh )
{
  boolean b_result = FALSE;

  if(p_Inlap->fInlap < f_ObjectInlapDropThresh)
  {
    if(p_Inlap->fInlapVar < LA_OBJ_INLANE_DROP_MAX_INLAP_VAR)
    {
      b_result = TRUE;
    }
    else
    {
      if(p_Inlap->fInlap <= LA_OBJ_INLANE_DROP_INSECURE_INLAP)
      {
        b_result = TRUE;
      }
    }
  }
  return( b_result );
}

#if (LA_SIT_VREL_INLANE_TIME_INC)
/*************************************************************************************************************************
  Functionname:    LA_f_GetSituationVrelInLaneTimeThreshold                                                            */ /*!

  @brief           Increase inlane timer threshold as a function of curve
                   radius and relative velocity.

  @description     Increase inlane timer threshold as a function of curve radius and relative velocity. Increase the timer
                   timer threshold for objects which are further away, have a similar velocity and/or are partly occluded.
                   Additionally, the threshold is increased in narrow curves in order to prevent drop-ins.
                   If we approach another object with high velocity, the threshold is maintained at a low level to
                   allow an early pickup and thus, an ACC-controlled approach.
                   @startuml
                   partition LA_f_GetSituationVrelInLaneTimeThreshold
                   start
                     -Increase inlane timer threshold as a function of curve radius and relative velocity.
                     -Increase the  timer threshold for objects which are further away, have a similar velocity and/or are partly occluded
                     -the threshold is increased in narrow curves in order to prevent drop-ins
                     If (approach another object with high velocity)then (yes)
                       -the threshold is maintained at a low level to allow an early pickup and thus, an ACC-controlled approach.
                     endif
                   stop
                   @enduml

  @return          fTimeThreshInLane : The object in-lane time threshold [0 ... 100.0f] s

  @param[in]       iObj : Object Number (Object ID)                                     [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThreshInLane : Time threshold for object iObj                   [0 ... 100.0f] s

  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(iObj) : Relative velocity of object iObj             [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY                  [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision : Object i was selected by blocked path [TRUE, FALSE]
  @glob_in         *pt_LAInput->t_SIT.pu_BlockedPathSelectionTimer(iObj) : Timer to decide the blocked path scenario  [0 ... 18]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane or not (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurve : Ego curve provided by VDY                      [-1 ... +1] m^-1
  @glob_in         *SLATE_pt_GetObjClassification(i) : object class [EM_t_GenObjClassification as in Rte_Type.h]

  @glob_out        -

  @c_switch_part   LA_SIT_VREL_INLANE_TIME_INC : Configuration switch to enable situative increase of inlane timer as a
                                                 function of relative velocity, curvature, and distance
  @c_switch_part   LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME : Configuration switch which enables the adaptation of Inlane Time Threshold using blocked path timer
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static fTime_t LA_f_GetSituationVrelInLaneTimeThreshold(const ObjNumber_t iObj, fTime_t fTimeThreshInLane)
{
  float32 f_VrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj);
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(iObj);
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
  uint8 u_BlockedPathSelectionTimer = *pt_LAInput->t_SIT.pu_BlockedPathSelectionTimer(iObj);
  boolean b_SelectedByPathDecision = pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision;
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */

    if (    (f_VrelX > LA_SIT_VREL_INLANE_TIME_INC_MIN_VREL)
         && (f_ObjLongDisp > LA_SIT_VREL_INLANE_TIME_INC_MIN_EGO_DISTX)
         && (f_EgoVelObjSync > LA_SIT_VREL_INLANE_TIME_INC_MIN_EGO_VEL)
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
         && (((u_BlockedPathSelectionTimer < LA_BLOCKED_PATH_TIMER) && (f_VrelX > -(LA_VRELX_THRESH))) || ((b_SelectedByPathDecision == FALSE) && (f_VrelX <= -(LA_VRELX_THRESH))))
#else
		  && (pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision == FALSE)
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
         && (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState != OBJ_STATE_INLANE))
    {
      float32 f_absEgoCurve = fABS(*pt_LAInput->t_RTE.pf_EgoCurve);
      if(f_absEgoCurve > LA_SIT_VREL_INLANE_TIME_INC_MAX_CURVE)
      {
        if(t_ObjClassification == SLATE_OBJCLASS_TRUCK)
        {
          fTimeThreshInLane = MAX_FLOAT(fTimeThreshInLane+LA_SIT_VREL_INLANE_TIME_INC_MAX_INCR, LA_SIT_VREL_INLANE_TIME_INC_MAX_TIME_TRUCKS);
        }
        else
        {
          fTimeThreshInLane = MAX_FLOAT(fTimeThreshInLane+LA_SIT_VREL_INLANE_TIME_INC_MED_INCR, LA_MINTIME_MOVE_OBJ_IN_LANE_MAX);
        }
      }
      else
      {
        if(fTimeThreshInLane < LA_MINTIME_MOVE_OBJ_IN_LANE_MAX)
        {
          if(f_VrelX > LA_SIT_VREL_INLANE_TIME_INC_MAX_VREL)
          {
            fTimeThreshInLane = MAX_FLOAT(fTimeThreshInLane+LA_SIT_VREL_INLANE_TIME_INC_MED_INCR, LA_MINTIME_MOVE_OBJ_IN_LANE_MAX);
          }
          else
          {
            fTimeThreshInLane = MAX_FLOAT(fTimeThreshInLane+LA_SIT_VREL_INLANE_TIME_INC_MIN_INCR,LA_SIT_VREL_INLANE_TIME_INC_MAX_TIME_STRAIGHT_CAR);
          }
        }
      }
    }
    else
    {
      /* nothing to do here */
    }

  return fTimeThreshInLane;
}
#endif

#if (LA_HIGH_VEGO_INLANE_TIME)
/*************************************************************************************************************************
  Functionname:    LA_f_GetHighEgoVelInLaneTimeThreshold                                                               */ /*!

  @brief           Get situation specific time threshold for
                   in-lane decision of objects for high ego velocities

  @description     For high ego velocities an increase of in-lane time is useful
                   to avoid drop-ins. The in-lane time is increased
                   dependent on object class, curvature and occlusion. Increase
                   of in-lane time is done only in case object is not overtaking.
                   This feature is useful for german autobahn and above 140 kp/h.
                   @startuml
                    partition LA_f_GetHighEgoVelInLaneTimeThreshold 
                    start
                      If(traffic orientation is unknown) then (yes)
                         -use the default threshold
                      endif
                      
                      -Check velocity and distance thresholds for object suppression at high velocities
                      -Check lane matrix and road border specific conditions
                      if(CheckSurroundings is true) then (yes)
                         if(TrafficOrientation is on left) then (yes)
                    	    partition LA_v_FindObjInArea{
                    	    -Loop over all objects to check if truck is overtaking on the right lane
                    		}
                    	  else
                    	    partition LA_v_FindObjInArea{
                    	    -Loop over all objects to check if truck is overtaking on the left lane
                    		}
                    	  endif	
                    		
                    	  if( possible overtaken object has been found) then (yes)
                    	     - No possibly overtaken object has been found
                    	  endif
                      endif
                      
                      if(ObjIsOvertaking is true) then (yes)
                        if(object quality is less than or equal to 76) then (yes)
                    	  -Highest in-lane time in case cluster variance of object is high
                    	endif
                    	if(ObjClassification is Truck or EgoCurveRaw is greater than LA HIGH VEGO INLANE TIME STRONG CURV) then (yes)
                    	  -Very high in-lane time for trucks or in strong curves
                    	endif
                    	
                    	if(eObjectOcclusion is equal to em  object Occlusion full) then (yes)
                    	  -High in-lane time for fully occluded objects
                    	endif
                    	
                    	if(ObjClassification is CAR) then (yes)
                    	  -Increased in-lane time for cars
                        Endif
                      endif
                    stop
                    @enduml

  @return          fTimeThreshInLane : The increased or unmodified in-lane time threshold

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThreshInLane : Time threshold object has to be seen inlane [0 ... 100.f] s

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync :  Ego velocity provided by VDY                [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of object i                    [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjArelX(i) :  Relative longitudinal acceleration of object i  [-100.0f ... 100.0f] m/s^2
  @glob_in         pt_LAInput->t_FIPRoad.fDistLeft : : Lateral ego distance to left road border   [0.f ... 30.f] m
  @glob_in         SLATE_u_GetAccQuality(i) : ACC quality of object i which includes cluster variance information [0 ... 100]
  @glob_in         *SLATE_pt_GetObjClassification(i) : object class [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         pt_LAInput->t_RTE.pf_EgoCurveRaw : Unfiltered curve provided by VDY                    [-1 ... +1] m^(-1)
  @glob_in         SLATE_p_GetEMGenObjAttributes(i)->eObjectOcclusion : Occlusion of object i [EM_t_GenObjOclusionState as in Rte_Type.h]
  @glob_in         pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight : Lateral ego distance to right road border   [0.f ... 30.f] m
  @glob_in         pt_LAInput->t_FIPTO.pt_FIPTrafficOrientation: FIP Fused Traffic Orientation Value [Full Range of datatype eTrafficOrientation_t as defined in Rte_Type.h] 

  @glob_out        -
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Config switch to enable use of cluster variance in lane association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component
  

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @todo            Inputs from FIP Road (pt_LAInput->t_FIPRoad) are available only if switch FCT_CFG_INPUT_PREPROCESSSING is 
                   on, which is not considered here. Switch for FCT_CFG_ROAD_INPUT to also be adapted.

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static fTime_t LA_f_GetHighEgoVelInLaneTimeThreshold(const ObjNumber_t iObj, fTime_t fTimeThreshInLane)
{
  boolean b_ObjIsOvertaking = TRUE;
  boolean b_HighEgoVelCrit = FALSE;
  boolean b_CheckSurroundings = FALSE;
  SLATE_t_TrafficOrientation t_TrafficOrientation = pt_LAInput->pt_FIPTO->t_FIPTrafficOrientation;
  ObjNumber_t a_OvertakenObjID[LA_FIND_MOV_OBJ_IN_AREA_NUM_MAX]; /* Array of objects possibly overtaken by iObj */
  const sint32 s_NumberLanesLeft = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneLeft);
  const sint32 s_NumberLanesRight = (pt_LAInput->pt_FIPLaneMatrix->s_NumOfLaneRight);
  float32 f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  float32 f_VrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj);
  float32 f_ArelX = *pt_LAInput->t_RTE.pf_ObjArelX(iObj);
  float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(iObj);
  float32 fABS_EgoCurveRaw;		/* For calculating ABS value */

  /* Check high velocity condition. If traffic orientation is unknown, use the default threshold */
  if ( ((f_EgoVelObjSync > LA_HIGH_VEGO_INLANE_TIME_VEGO_MIN) && (t_TrafficOrientation != SLATE_TRAFFIC_ORIENTATION_UNKNOWN))
    || ((f_EgoVelObjSync > LA_HIGH_VEGO_INLANE_TIME_VEGO_MIN_UNKNOWN_TO) && (t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_UNKNOWN))
    )
  {
    b_HighEgoVelCrit = TRUE;
  }

  /* Check velocity and distance thresholds for object suppression at high velocities */
  if ( (b_HighEgoVelCrit == TRUE)
    && ((f_EgoVelObjSync + f_VrelX) > LA_HIGH_VEGO_INLANE_TIME_VOBJ_MIN)
    && (f_ObjLongDisp > LA_HIGH_VEGO_INLANE_TIME_XDIST_MIN)
    && (f_VrelX < LA_HIGH_VEGO_INLANE_TIME_VREL_MAX)
    && (f_ArelX > LA_HIGH_DIST_OBJ_SUPPRESS_AREL_MIN)
    )
  {
  /* Check lane matrix and road border specific conditions. */
    if ( (t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT)
      && (s_NumberLanesLeft != (sint8)0)
      && ( (s_NumberLanesRight == (sint8)0)
#if (FCT_CFG_ROAD_INPUT)
        || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight)  > -LA_HIGH_VEGO_OBJ_SUPPRESS_BORDER_DIST_NEAR)
        || ((s_NumberLanesRight == (sint8)-1) && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft) > LA_HIGH_VEGO_OBJ_SUPPRESS_BORDER_DIST_FAR))
#endif /* FCT_CFG_ROAD_INPUT */
        )
      )
    {
      /* Ego has to be most likely on right lane. */
      b_CheckSurroundings = TRUE;
    }
    else if ( (t_TrafficOrientation != SLATE_TRAFFIC_ORIENTATION_LEFT)
      && (s_NumberLanesRight != (sint8)0)
      && ( (s_NumberLanesLeft == (sint8)0)
#if (FCT_CFG_ROAD_INPUT)
        || ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistLeft)  < LA_HIGH_VEGO_OBJ_SUPPRESS_BORDER_DIST_NEAR)
        || ((s_NumberLanesLeft == (sint8)-1) && ((pt_LAInput->pt_FIPRoad->t_FIPRoadFusedBorder.fDistRight) < - LA_HIGH_VEGO_OBJ_SUPPRESS_BORDER_DIST_FAR))
#endif /* FCT_CFG_ROAD_INPUT */
        )
      )
    {
      /* Ego has to be most likely on left lane. */
      b_CheckSurroundings = TRUE;
    }
    else
    {
      b_CheckSurroundings = FALSE;
    }
  }

  /* Check for overtaking surroundings objects */
  if (b_CheckSurroundings == TRUE)
  {
    if (t_TrafficOrientation == SLATE_TRAFFIC_ORIENTATION_LEFT)
    {
      /* Loop over all objects to check if truck is overtaking on the right lane*/
#if (LA_CFG_AVOID_SPILT_OBJ)
      LA_v_FindObjInArea(a_OvertakenObjID, iObj, &LA_OTCheckArgsHSLeft_TO, FALSE);
#else
      LA_v_FindObjInArea(a_OvertakenObjID, iObj, &LA_OTCheckArgsHSLeft_TO);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
    }
    else 
    {
      /* Loop over all objects to check if truck is overtaking on the left lane*/
#if (LA_CFG_AVOID_SPILT_OBJ)
      LA_v_FindObjInArea(a_OvertakenObjID, iObj, &LA_OTCheckArgsHSDefault_TO, FALSE);
#else
      LA_v_FindObjInArea(a_OvertakenObjID, iObj, &LA_OTCheckArgsHSDefault_TO);
#endif /*LA_CFG_AVOID_SPILT_OBJ*/
    }
     /* Check if possible overtaken object has been found */
    if (a_OvertakenObjID[0] == (ObjNumber_t)-1)
    {
      /* No possibly overtaken object has been found */
      b_ObjIsOvertaking = FALSE;
    }
  }

  /* If object is most likely not overtaking, increase situation in-lane-timer to avoid drop-ins. */
  /* The InLane Timer threshold is set based on different scenarios below; The sequence of the check does not matter
     as we always take the maximum value */
  if (b_ObjIsOvertaking != TRUE)
  {
#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
    if ( (SLATE_u_GetAccQuality(iObj) <= FUN_PRESEL_ACC_LOW_CLUST_VAR_OBJ_QUAL) )
    {
      /* Highest in-lane time in case cluster variance of object is high */
      fTimeThreshInLane = MAX_FLOAT(LA_CLUST_VAR_HIGH_VEGO_INLANE_TIME, fTimeThreshInLane);
    }
#endif
	fABS_EgoCurveRaw = fABS(*pt_LAInput->t_RTE.pf_EgoCurveRaw);
    if ( (t_ObjClassification == SLATE_OBJCLASS_TRUCK)
      || (fABS_EgoCurveRaw > LA_HIGH_VEGO_INLANE_TIME_STRONG_CURVE) )
    {
      /* Very high in-lane time for trucks or in strong curves */
      fTimeThreshInLane = MAX_FLOAT(LA_HIGH_VEGO_INLANE_TIME_TRUCK, fTimeThreshInLane);
    }

    if (SLATE_p_GetEMGenObjAttributes(iObj)->eObjectOcclusion == EM_GEN_OBJECT_OCCL_FULL)
    {
      /* High in-lane time for fully occluded objects */
      fTimeThreshInLane = MAX_FLOAT(LA_HIGH_VEGO_INLANE_TIME_OCCLUDED, fTimeThreshInLane);
    }

    if (t_ObjClassification == SLATE_OBJCLASS_CAR)
    {
      /* Increased in-lane time for cars */
      fTimeThreshInLane = MAX_FLOAT(LA_HIGH_VEGO_INLANE_TIME_CAR , fTimeThreshInLane);
    }
  }

  return fTimeThreshInLane;
}
#endif

#if (LA_TTC_DEPENDANT_INLANE_TIME)
/*************************************************************************************************************************
  Functionname:    LA_f_TTCDependantInLaneTimeThreshold                                                                */ /*!

  @brief           Get threshold for time condition for in lane decision of objects

  @description     Return required time for object to be classified as in-lane
                   dependent on longitudinal displacement and relative velocity.
                   Increase the in-lane-time as a factor of LA_TTC_DEPENDANT_INLANE_TIME_FACTOR.
                   @startuml
                   partition LA_f_TTCDependantInLaneTimeThreshold
                   start
                     -Return required time for object to be classified as in-lane dependent on longitudinal displacement and relative velocity.
                     -Increase the in-lane-time as a factor of dependant inlane time factor.
                   stop
                   @enduml

  @return          fTimeThresInLaneLocal : The object in-lane time threshold [0 ... 100.0f] s

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThreshInLane : The object in-lane time threshold [0 ... 100.0f] s

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY                                [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i                [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(i) : Relative velocity of an object i                                [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision : Object i was selected by blocked path  [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane or not (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
static fTime_t LA_f_TTCDependantInLaneTimeThreshold(ObjNumber_t iObj, fTime_t fTimeThreshInLane)
{
  float32 fTimeThreshInLaneLocal;

  if ( (*pt_LAInput->t_RTE.pf_EgoVelObjSync > LA_TTC_DEPENDANT_INLANE_TIME_VEGO_MIN )
    && (*pt_LAInput->t_RTE.pf_EgoVelObjSync < LA_TTC_DEPENDANT_INLANE_TIME_VEGO_MAX )
    && (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) > LA_TTC_DEPENDANT_INLANE_TIME_XDIST_MIN )
    && (*pt_LAInput->t_RTE.pf_ObjVrelX(iObj) > LA_TTC_DEPENDANT_INLANE_TIME_VREL_MIN)
    && (pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision == FALSE)
    && (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState != OBJ_STATE_INLANE)
     )
  {
    if (*pt_LAInput->t_RTE.pf_ObjVrelX(iObj) < LA_TTC_DEPENDANT_INLANE_TIME_VREL_MAX)
    {
      fTimeThreshInLaneLocal = MIN_FLOAT(LA_TTC_DEPENDANT_INLANE_TIME_MAX, LA_TTC_DEPENDANT_INLANE_TIME_FACTOR * -(*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) / *pt_LAInput->t_RTE.pf_ObjVrelX(iObj)) );
    }
    else
    {
      fTimeThreshInLaneLocal = LA_TTC_DEPENDANT_INLANE_TIME_MAX;
    }

    fTimeThreshInLane = MAX_FLOAT(fTimeThreshInLaneLocal , fTimeThreshInLane);
  }

  return fTimeThreshInLane;
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_f_CalcInlaneTimeStatVehicle                                                                      */ /*!

  @brief           Calculate the inlane time threshold for a stationary vehicle object

  @description     Determine the inlane time for a given stationary vehicle-like object
                   based on the ego vehicle longitudinal velocity. A higher inlane time requires
                   that the object is stable within the ego lane. Thus, mirror-objects are likely
                   to be suppressed, however, approaches may be late.
                   @startuml
                    partition LA_f_CalcInlaneTimeStatVehicle
                    start
                      if(Longitudinal velocity is less than la statveh inlane nospeed) then (yes)
                        -set TimeThreshold to la statveh inlane time nospeed
                      elseif(Longitudinal velocity is less than la statveh inlane parkspeed)then (yes)
                        -set TimeThreshold to la statveh inlane time parkspeed
                      elseif(Longitudinal velocity is less than la statveh inlane lowspeed)then (yes)
                        -set TimeThreshold to la statveh inlane distmin divided by Velocity
                      elseif(Longitudinal velocity is less than or equal to la statveh inlane highspeed)then (yes)
                        -set TimeThreshold to fRequiredDistanceInLane divided by velocity
                      else
                        -set TimeThreshold to la statveh inlane distmax divided by velocity
                      endif
                      
                      partition LA_CFG_DTR_OBJ_SELECTION {
                        if(fVelocity is  greater than la statveh inlane nospeed and less than la statveh inlane lowspeed and ObjLongDisp is less than la statveh inlane distx lowspeed and DTR class is car or truck or pedestrian) then (yes)
                    	  -set TimeThreshold to la statveh inlane distmin divided by la statveh inlane lowspeed
                    	endif
                      }
                    stop
                    @enduml

  @return          Time threshold for a vehicle object [0.f ... 100.f] s

  @param[in]       fVelocity : Longitudinal velocity  [-330.f ... 330.f] m/s
  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pSLATE_EmCustObjList->CustObjects[i].DTR_Obj_Class : DTR specific object class for object i [DTR_Obj_Class_t as defined in Rte_Type.h]
  @glob_in         OBJ_DYNAMIC_SUB_PROPERTY(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc : Camera trajectory based lane association of an object i    [0      3]

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : DTR object selection
  @c_switch_part   LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA : Configuration switch to reduce In-Lane Time and In-Lane Distance threshold depending on Camera Trajectory based LA

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             _
  @post            _

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.02.2016
  @changed         11.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static fTime_t LA_f_CalcInlaneTimeStatVehicle( fVelocity_t const fVelocity, const ObjNumber_t iObj )
{
  fTime_t fTimeThreshold;
  fDistance_t fRequiredDistanceInLane;
  MotState_t t_EGOMotionState = SLATE_t_GetEGOMotionState();
  VDYIoStateTypes_t uEgoMotionState = SLATE_u_EgoMotionState();
#if (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA)
  LA_t_ObjCamTrajLanAssocEnum t_CamTrajLaneAssoc = pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc;
#endif /* (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA) */

#if (!LA_CFG_DTR_OBJ_SELECTION)
  _PARAM_UNUSED(iObj);
#endif

  if( (fVelocity < LA_STATVEH_INLANE_NOSPEED)
    ||((t_EGOMotionState ==  VDY_LONG_MOT_STATE_STDST) && (IS_SIGNAL_STATUS_OK(uEgoMotionState))) )
  {
    fTimeThreshold = LA_STATVEH_INLANE_TIME_NOSPEED;
  }
  else if(fVelocity < LA_STATVEH_INLANE_PARKSPEED)
  {
    fTimeThreshold = LA_STATVEH_INLANE_TIME_PARKSPEED;
  }
#if (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA)
  else if ((fVelocity < LA_CFG_ADAPT_IN_LANE_TIME_CAM_TRAJ_LA_EGOSPEED) &&
           (t_CamTrajLaneAssoc == LA_OBJ_CAM_LANE_EGO))
  {
    fTimeThreshold = LA_STATVEH_INLANE_DISTMIN / fVelocity;
  }
#endif /* (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA) */
  else if(fVelocity < LA_STATVEH_INLANE_LOWSPEED)
  {
    fTimeThreshold = LA_STATVEH_INLANE_DISTMIN / fVelocity;
  }
  else if(fVelocity <= LA_STATVEH_INLANE_HIGHSPEED)
  {
    fRequiredDistanceInLane = MUL_ADD_FLOAT(LA_STATVEH_INLANE_DISTSLOPE,fVelocity,LA_STATVEH_INLANE_DISTOFFSET);
    fTimeThreshold = fRequiredDistanceInLane / fVelocity;
  }
  else
  {
    fTimeThreshold = LA_STATVEH_INLANE_DISTMAX / fVelocity;
  }

#if (LA_CFG_DTR_OBJ_SELECTION)
  if ( (fVelocity > LA_STATVEH_INLANE_NOSPEED)
    && (fVelocity < LA_STATVEH_INLANE_LOWSPEED)
    && (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) < LA_STATVEH_INLANE_DISTX_LOWSPEED)
    && ((pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class == DTR_CLASS_CAR) || (pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class == DTR_CLASS_TRUCK) || (pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class == DTR_CLASS_POINT))
    && (pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class != DTR_CLASS_PEDESTRIAN_HIGH)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    && (OBJ_DYNAMIC_SUB_PROPERTY(iObj) != SLATE_OBJECT_SUBPROP_CROSSING)
#endif
    )
  {
    fTimeThreshold = (LA_STATVEH_INLANE_DISTMIN / LA_STATVEH_INLANE_LOWSPEED);
  }
#endif

  return fTimeThreshold;
}

/*************************************************************************************************************************
  Functionname:    LA_f_CalcInlaneTimeStatNonVehicle                                                                   */ /*!

  @brief           Calculate the inlane time threshold for a stationary non-vehicle object

  @description     Determine the inlane time for a given stationary non-vehicle-like object
                   based on the ego vehicle longitudinal velocity. A higher inlane time requires
                   that the object is stable within the ego lane. Thus, mirror-objects are likely
                   to be suppressed, however, approaches may be late.
                   @startuml
                   partition LA_f_CalcInlaneTimeStatNonVehicle
                   start
                     if(Longitudinal velocity is less than la statveh inlane nospeed) then (yes)
                       -set TimeThreshold to la statveh inlane time nospeed
                     elseif(Longitudinal velocity is less than la statveh inlane parkspeed)then (yes)
                       -set TimeThreshold to la statveh inlane time parkspeed
                     elseif(Longitudinal velocity is less than la statveh inlane lowspeed)then (yes)
                       -set TimeThreshold to la statveh inlane distmin divided by Velocity
                     elseif(Longitudinal velocity is less than or equal to la statveh inlane highspeed)then (yes)
                       -set TimeThreshold to fRequiredDistanceInLane divided by velocity
                     else
                       -set TimeThreshold to la statveh inlane distmax divided by velocity
                     endif
                     
                     partition LA_CFG_DTR_OBJ_SELECTION {
                       if(fVelocity is  greater than la statveh inlane nospeed and less than la statveh inlane lowspeed and ObjLongDisp is less than la statveh inlane distx lowspeed and DTR class is car or truck or pedestrian) then (yes)
                   	  -set TimeThreshold to la statveh inlane distmin divided by la statveh inlane lowspeed
                   	endif
                     }
                   stop
                   @enduml

  @return          Time threshold for a non-vehicle object [0.f ... 100.f] s

  @param[in]       fVelocity : Longitudinal velocity [-330.f ... 330.f] m/s
  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pSLATE_EmCustObjList->CustObjects[i].DTR_Obj_Class : DTR specific object class for object i [DTR_Obj_Class_t as defined in Rte_Type.h]
  @glob_in         OBJ_DYNAMIC_SUB_PROPERTY(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]

  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION :  DTR object selection

  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.02.2016
  @changed         11.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static fTime_t LA_f_CalcInlaneTimeStatNonVehicle( fVelocity_t const fVelocity, const ObjNumber_t iObj )
{
  fTime_t fTimeThreshold;
  fDistance_t fRequiredDistanceInLane;
  MotState_t t_EGOMotionState = SLATE_t_GetEGOMotionState();
  VDYIoStateTypes_t uEgoMotionState = SLATE_u_EgoMotionState();

#if (!LA_CFG_DTR_OBJ_SELECTION)
  _PARAM_UNUSED(iObj);
#endif

  if( (fVelocity < LA_STATOBJ_INLANE_NOSPEED)
    ||((t_EGOMotionState ==  VDY_LONG_MOT_STATE_STDST) && (IS_SIGNAL_STATUS_OK(uEgoMotionState))) )
  {
    fTimeThreshold = LA_STATOBJ_INLANE_TIME_NOSPEED;
  }
  else if(fVelocity < LA_STATOBJ_INLANE_PARKSPEED)
  {
    fTimeThreshold = LA_STATOBJ_INLANE_TIME_PARKSPEED;
  }
  else if(fVelocity < LA_STATOBJ_INLANE_LOWSPEED)
  {
    fTimeThreshold = LA_STATOBJ_INLANE_DISTMIN / fVelocity;
  }
  else if(fVelocity <= LA_STATOBJ_INLANE_HIGHSPEED)
  {
    fRequiredDistanceInLane = MUL_ADD_FLOAT(LA_STATOBJ_INLANE_DISTSLOPE,fVelocity,LA_STATOBJ_INLANE_DISTOFFSET);
    fTimeThreshold = fRequiredDistanceInLane / fVelocity;
  }
  else
  {
    fTimeThreshold = LA_STATOBJ_INLANE_DISTMAX / fVelocity;
  }

#if (LA_CFG_DTR_OBJ_SELECTION)
  if ( (fVelocity > LA_STATOBJ_INLANE_NOSPEED)
    && (fVelocity < LA_STATOBJ_INLANE_LOWSPEED)
    && (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj) < LA_STATVEH_INLANE_DISTX_LOWSPEED)
    && ((pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class == DTR_CLASS_CAR) || (pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class == DTR_CLASS_TRUCK) || (pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class == DTR_CLASS_POINT))
    && (pSLATE_EmCustObjList->CustObjects[iObj].DTR_Obj_Class != DTR_CLASS_PEDESTRIAN_HIGH)
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    && (OBJ_DYNAMIC_SUB_PROPERTY(iObj) != SLATE_OBJECT_SUBPROP_CROSSING)
#endif
    )
  {
    fTimeThreshold = (LA_STATOBJ_INLANE_DISTMIN / LA_STATOBJ_INLANE_LOWSPEED);
  }
#endif

  return ( fTimeThreshold );
}

/*************************************************************************************************************************
  Functionname:    LA_v_ResetInlaneTimer                                                                               */ /*!

  @brief           Reset the Inlane Timer if timing conditions not fulfilled

  @description     Update (reset) object's SI.ObjLaneAccStatus.fCorridorRelevantTime
                   field for hysteresis
                   @startuml
                   partition LA_v_ResetInlaneTimer
                   start
                     -Reset the Inlane Timer if timing conditions not fulfilled
                   stop
                   @enduml

  @return          -

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [full range of data type float > 0.f]
  @glob_out        -

  @c_switch_part   FCT_SIMU: Compiler switch used for simulation purpose
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
void LA_v_ResetInlaneTimer(const ObjNumber_t iObj)
{
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj));
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);

  if ( (t_ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
    && (b_ObjIsMovingToStationary == FALSE)
     )
  {
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime = pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime -
      (LA_SCALE_RESET_INLANE_TIMER_STAT * SLATE_f_GetSITCycleTime());
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime = MAX_FLOAT(pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime, 0.f);
  }
  else
  {
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime = 0.f;
  }

#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[iObj].fInLaneTimeThres = 0.f;
#endif
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetInLaneDistanceThreshold                                                                     */ /*!

  @brief           Get threshold for time condition for in lane decision of objects

  @description     Return distance threshold for given object

                   @startuml
                   partition LA_f_GetInLaneDistanceThreshold
                   start
                     if(object is not stationary and Object Is Moving To Stationary) then (yes)
                       - only use the time in lane for moving and stopped objects -> deactivate the distance in lane 
                     else
                       If(object us car or truck or motercycle) then (yes)
                        if(fveigen is less than la statveh inlane parkspeed) then (yes)
                        -set fdistthreshinlane to maximum of la statveh inlane distmin and product of fveigen and la statveh inlane time parkspeed
                      elseif(fveigen is less than la statveh inlane lowspeed)  then (yes)
                         -set fdistthreshinlane to la statveh inlane distmin
                      elseif(fveigen is less than or equal to la statveh inlane highspeed) then (yes)
                         -set fdistthreshinlane to sum of la inlane dist maxvalue and c f32 delta
                      else
                         -set fdistthreshinlane to la statveh inlane distmax
                      endif
                    else
                        if(fveigen is less than la statobj inlane parkspeed) then (yes)
                        -set fdistthreshinlane to maximum of la statobj inlane distmin and product of fveigen and la statobj inlane time parkspeed
                      elseif(fveigen is less than la statobj inlane lowspeed)  then (yes)
                         -set fdistthreshinlane to la statobj inlane distmin
                      elseif(fveigen is less than or equal to la statobj inlane highspeed) then (yes)
                         -set fdistthreshinlane to sum of la inlane dist maxvalue and c f32 delta
                      else
                         -set fdistthreshinlane to la statobj inlane distmax
                      endif
                    
                    endif
                     endif
                   stop
                   @enduml

  @return          fDistance_t : Distance threshold for the given object [0 ... 5*RW_FCT_MAX] m

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY            [-330.f ... 330.f] m/s
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving [TRUE, FALSE]
  @glob_in         *SLATE_pt_GetObjClassification(i) : object class [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].b_SetInLaneTimeCurve : Indication of In-Lane timer for 
                                                                               Stationry Objects on Curve [TRUE or FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc : Camera trajectory based lane association of an object i    [0      3]
  @glob_out        -

  @c_switch_part   LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT            : Update Inlane Timer value for Stationary Objects on Curve
  @c_switch_part   LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA : Configuration switch to reduce In-Lane Time and In-Lane Distance threshold depending on Camera Trajectory based LA
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION                   : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static fDistance_t LA_f_GetInLaneDistanceThreshold(const ObjNumber_t iObj)
{
  fDistance_t fDistThreshInLane;
  fVelocity_t fVeigen = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj));
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);
  SLATE_t_Obj_CLassification t_ObjClassification = (*pt_LAInput->t_RTE.pt_ObjClassification(iObj));
#if (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA)
  LA_t_ObjCamTrajLanAssocEnum t_CamTrajLaneAssoc = pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc;
#endif /* (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA) */

  fVeigen = fABS(fVeigen);

  if ( (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
    || (b_ObjIsMovingToStationary == TRUE)
     )
  {
    /* only use the time in lane for moving and stopped objects -> deactivate the distance in lane */
    fDistThreshInLane = (LA_INLANE_DIST_MAXVALUE+C_F32_DELTA);
  }
  else /* Stationary Objects or vehicles */
  {
    if(  (t_ObjClassification == SLATE_OBJCLASS_CAR      )
      || (t_ObjClassification == SLATE_OBJCLASS_TRUCK    )
      || (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE)
      )
    {
      if(fVeigen < LA_STATVEH_INLANE_PARKSPEED)
      {
        fDistThreshInLane = MAX_FLOAT( LA_STATVEH_INLANE_DISTMIN , (fVeigen*LA_STATVEH_INLANE_TIME_PARKSPEED) );
      }
#if (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA)
      else if ((fVeigen < LA_CFG_ADAPT_IN_LANE_DIST_CAM_TRAJ_LA_EGOSPEED) &&
               (t_CamTrajLaneAssoc == LA_OBJ_CAM_LANE_EGO))
      {
        fDistThreshInLane = LA_STATVEH_INLANE_DISTMIN;
      }
#endif /* (LA_CFG_ADAPT_IN_LANE_TIME_AND_DIST_CAM_TRAJ_LA) */
      else if(   (fVeigen < LA_STATVEH_INLANE_LOWSPEED)
#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)
              && (pt_LAOutput->t_LAObjOutputList[iObj].b_SetInLaneTimeCurve == FALSE)
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */
              )
      {
        fDistThreshInLane = LA_STATVEH_INLANE_DISTMIN;
      }
      else if(fVeigen <= LA_STATVEH_INLANE_HIGHSPEED)
      {
        /* only use the time in lane -> deactivate the distance in lane */
        fDistThreshInLane = (LA_INLANE_DIST_MAXVALUE+C_F32_DELTA);
      }
      else
      {
        fDistThreshInLane = LA_STATVEH_INLANE_DISTMAX;
      }
    }
    else
    {
      if(fVeigen < LA_STATOBJ_INLANE_PARKSPEED)
      {
        fDistThreshInLane = MAX_FLOAT( LA_STATOBJ_INLANE_DISTMIN , (fVeigen*LA_STATOBJ_INLANE_TIME_PARKSPEED) );
      }
      else if(fVeigen < LA_STATOBJ_INLANE_LOWSPEED)
      {
        fDistThreshInLane = LA_STATOBJ_INLANE_DISTMIN;
      }
      else if(fVeigen <= LA_STATOBJ_INLANE_HIGHSPEED)
      {
        /* only use the time in lane -> deactivate the distance in lane */
        fDistThreshInLane = (LA_INLANE_DIST_MAXVALUE+C_F32_DELTA);
      }
      else
      {
        fDistThreshInLane = LA_STATOBJ_INLANE_DISTMAX;
      }
    }
  }

  return(fDistThreshInLane);
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckInlaneDistance                                                                            */ /*!

  @brief           Check distance condition for in lane decision of objects

  @description     Update given object's SI.ObjLaneAccStatus.fCorridorRelevantDist
                   to get the ego driven distance during which object was in
                   ego lane
                   @startuml
                   partition LA_b_CheckInlaneDistance
                   start
                     - Update given object's SI.ObjLaneAccStatus.fCorridorRelevantDist to get the ego driven distance during which object was in ego lane
                   stop
                   @enduml

  @return          bInlaneDist : true when the distance threshold is met [TRUE, FALSE]

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoAccObjSync : Longitudinal acceleration of ego vehicle [-330.f ... 330.f] m/s
  @glob_in         SLATE_f_GetSITCycleTime() : Period of cycle time                            [0.f ... 1.f] s
  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync :  Ego velocity provided by VDY            [-330.f ... 330.f] m/s

  @glob_out         pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantDist : Distance of relevant object [0 ... 5*RW_FCT_MAX] m

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         11.02.2016
  @changed         11.02.2016

  @author          philippe.dintzer@contiautomotive.com
*************************************************************************************************************************/
extern boolean LA_b_CheckInlaneDistance(const ObjNumber_t iObj)
{
  boolean  bInlaneDist;
  const fAccel_t        fEgoAcceleration  = *pt_LAInput->t_RTE.pf_EgoAccObjSync;
  const fTime_t         fLastCycleTime    = SLATE_f_GetSITCycleTime();
  const fDistance_t     fDistThresh       = LA_f_GetInLaneDistanceThreshold(iObj);

  pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantDist += ( (*pt_LAInput->t_RTE.pf_EgoVelObjSync * fLastCycleTime) + (0.5f * fEgoAcceleration * fLastCycleTime * fLastCycleTime));

  pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantDist = MIN_FLOAT(LA_INLANE_DIST_MAXVALUE , pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantDist);

  if (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantDist > fDistThresh)
  {
    bInlaneDist = TRUE;
  }
  else
  {
    bInlaneDist = FALSE;
  }
  return bInlaneDist;
}

/*************************************************************************************************************************
  Functionname:    LA_v_ResetInlaneDistance                                                                            */ /*!

  @brief           Reset the Inlane Distance

  @description     Reset the Inlane Distance
                   @startuml
                   partition LA_v_ResetInlaneDistance
                   start
                     if( the time in lane is 0) then (yes)
                      -delete the distance in lane
                      endif
                   stop
                   @enduml

  @return          -

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [full range of data type float > 0.f]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         22.02.2016

  @author          Philippe Dintzer | philippe.dintzer@contiautomotive.com
*************************************************************************************************************************/
void LA_v_ResetInlaneDistance(const ObjNumber_t iObj)
{
  /* Only delete the distance in lane when the time in lane is 0 */
  if(pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime < C_F32_DELTA)
  {
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantDist = 0.0f;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetInLaneTimeThreshold                                                                         */ /*!

  @brief           Get threshold for time condition for in lane decision of objects

  @description     Return required time for object to be classified as (geometric) in-lane
                   prior to setting the final in-lane flag (i.e., being selected
                   for the 6 object interface)

                   @startuml
                   partition LA_f_GetInLaneTimeThreshold
                   start
                   if (object is not stationary or object is moving to stationary) then (true)
                     :TODO;
                     partition LA_HIGH_VEGO_INLANE_TIME {
                       :adapt time threshold for in-lane decision of objects for high ego velocities
                       **LA_f_GetHighEgoVelInLaneTimeThreshold**;
                     }
                     partition LA_SIT_VREL_INLANE_TIME_INC {
                       :Increase inlane timer threshold dependent on curve
                       radius and relative velocity
                       **LA_f_GetSituationVrelInLaneTimeThreshold**;
                     }
                     partition LA_TTC_DEPENDANT_INLANE_TIME {
                       :adapt threshold for time condition for in lane decision of objects
                       **LA_f_TTCDependantInLaneTimeThreshold**;
                     }
                     partition (EM_ARS_OBJECT_LIST_INTFVER_>=_6u_&&_LA_CFG_MICRODOPPLER_PEDESTRIAN_HIGH_INLANE_TIME) {
                      :Increase in-lane time for objects with micro doppler signature;
                     }
                     partition (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION) {
                       :Increase object inlane time threshold in case cluster variance of object 
                       is high and the situation is difficult;
                     }
                     partition FCT_CFG_CURVATURE_CHANGE_COMPUTATION {
                       :Check distance to high curvature change (curve entry/exit) criteria
                       **LA_b_CheckObjDistToCCCriteria**;
                       :Increase object in-lane-time threshold in case object is above the distance 
                       where a high curvature change is defined and not selected by path decision and 
                       object is not state inlane;
                     }
                     partition LA_CFG_NARROW_HIGHWAY_CRITERIA {
                       :Check narrow highway criteria
                       **LA_b_CheckNarrowHighwayCriteria**;
                       :Increase object in-lane-time threshold in case the narrow highway criteria is false;
                     }
                     partition FCT_CFG_ROAD_INPUT {
                      :Increase time threshold for roadworks;
                     }
                     partition SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION {
                       partition FCT_CFG_ROAD_INPUT {
                         :Check if objects are occluded. Use different parameters for the highway and the city.
                          Consider occlusion only if the object can become the OOI-0 based in the longitudinal distance
                          in order to reduce the influence on the OOI-1;
                         :Increase the in lane timer threshold in case of a occlusion
                         (threshold is higher on the highway compared to the city);
                       }
                     }
                   else (false)
                     :Calculate the inlane time threshold for a stationary vehicle object;
                   if (object is of class car, truck or motorcycle) then (true)
                     :**LA_f_CalcInlaneTimeStatVehicle**;
                   else (false)
                     :**LA_f_CalcInlaneTimeStatNonVehicle**;
                   endif
                   endif
                   partition LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA {
                     : Increase in-lane time for objects assigned to left or right lane based on Camera Trajectory Based Lane Association;
                   }
                   partition SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN {
                     :For Pedestrian Detection overwrite the required time in Lane;
                   }
                   partition EM_ARS_OBJECT_LIST_INTFVER_>=_6u_&&_LA_CFG_MICRODOPPLER_PEDESTRIAN_HIGH_INLANE_TIME {
                     :Increase in-lane time for objects with micro doppler signature;
                   }
                     :Increase the Time in Lane as long as the sensor is unlearned;
                     :Store the inlane time threshold;
                     :Return the inlane time threshold;
                   stop
                   @enduml

  @return          fTime_t : The object in-lane time threshold [0 ... 100.0f] s

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY                                  [-330.f ... 330.f] m/s
  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i                            [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving   [TRUE, FALSE]
  @glob_in         t_LA_InternalObjectData[i].ui_ClusterVarianceLevel : Difficulty level of object i with high cluster variance
                                                                                                        [LA_CLUST_VAR_LEVEL_LOW ... LA_CLUST_VAR_LEVEL_DIFFICULT]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FusedRoadType : Reference to FIP road type                [full range of FIP_t_FusedRoadType as in fip_ext.h]
  @glob_in         pt_LAInput->pt_FIPRoadType->t_RoadWorks : Reference to FIP road works type              [full range of FIP_t_RoadWorks as in fip_ext.h]
  @glob_in         SLATE_p_GetEMGenObjAttributes(i)->eObjectOcclusion : Occlusion of object i                           [EM_t_GenObjOclusionState as in Rte_Type.h]
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(iObj)->OccludedByTrace : Determine if object i is occluded based on a trace analysis [TRUE, FALSE]
  @glob_in         SLATE_f_GetObjectLength(i) : Length of object i                                            [0 ... 100.0f] m
  @glob_in         *SLATE_pt_GetObjClassification(i) : object class                                                 [EM_t_GenObjClassification as in Rte_Type.h]
  @glob_in         OBJ_KINEMATIC(i).fDistX : Longitudinal displacement of an object i                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_LAInput->t_RTE.f_EgoYawRateQuality : Quality of yaw rate provided by VDY                       [Quality_t as in Rte_Type.h]
  @glob_in         *pt_LAInput->t_SIT.pu_BlockedPathSelectionTimer(iObj) : Timer to decide the blocked path scenario  [0 ... 18]
  @glob_in         pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision : Object i was selected by blocked path [TRUE, FALSE]
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelX(iObj) : Relative velocity of object iObj                             [-330.f ... 330.f] m/s
  @glob_in         pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr : object number of relevant object                        [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS[ and EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_in         pt_LAInput->t_CP.pf_CourseCurve : Ego course curvature                                             [1/m]
  @glob_in         pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase : Ego Lane Change Phase 
  @glob_in         pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb : Ego Lane change probability                 
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc : Camera trajectory based lane association of an object i    [0      3]                   

  @glob_out        -

  @c_switch_part   FCT_SIMU: Compiler switch used for simulation purpose
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_part   SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION :  Configuration switch to enable occlusion calculation usage for inlane decision
  @c_switch_part   LA_HIGH_VEGO_INLANE_TIME : Configuration switch to enable suppression of objects at high velocities when ego is on the left lane
  @c_switch_part   LA_SIT_VREL_INLANE_TIME_INC : Configuration switch to enable situative increase of inlane timer as a
                          function of relative velocity, curvature, and distance
  @c_switch_part   LA_TTC_DEPENDANT_INLANE_TIME : Configuration switch to enable increase of inlane timer as a
                          function of approximate time-to-collision (distance divided by relative velocity)
  @c_switch_part   LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION : Configuration switch to enable cluster variance usage for inlane decision
  @c_switch_part   SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN :  Configuration switch enabling low speed pedestrian selection support
  @c_switch_part   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP
  @c_switch_part   LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME : Configuration switch which enables the adaptation of Inlane Time Threshold using blocked path timer
  @c_switch_part   LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA : Configuration switch to increase In-Lane Time Threshold based on the Camera Trajectory Based Lane Association
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22.02.2016
  @changed         15.03.2018

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
fTime_t LA_f_GetInLaneTimeThreshold(const ObjNumber_t iObj)
{
  fTime_t fTimeThreshInLane;
  fVelocity_t f_EgoSpeed;

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
  boolean b_DistToHighCCCriteria; /* Flag for distance to high curvature change criteria */ 
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
  boolean b_NarrowHighwayCriteria; /* Flag for narrow highway criteria */
#endif

  ObjNumber_t t_RelObjNr;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj));
  SLATE_t_Obj_CLassification t_ObjClassification = (*pt_LAInput->t_RTE.pt_ObjClassification(iObj));
  const float32 f_ObjLongDisp = (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj));
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
  float32 f_VrelX = *pt_LAInput->t_RTE.pf_ObjVrelX(iObj); 
  uint8 u_BlockedPathSelectionTimer = *pt_LAInput->t_SIT.pu_BlockedPathSelectionTimer(iObj);
  boolean b_SelectedByPathDecision = pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision;
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);
  float32 f_RelObjLongDisp, f_RelObjLength, f_EgoVelObjSync;
  boolean b_ObjOccludedByTrace;
#if (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA)
  LA_t_ObjCamTrajLanAssocEnum t_CamTrajLaneAssoc = LA_OBJ_CAM_LANE_UNDEFINED;
  float32 f_AbsCurve = fABS(*pt_LAInput->t_CP.pf_CourseCurve);
  SIT_LC_t_LaneChangePhaseEnum t_LCPhase = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->t_LCPhase;
  uint8 u_LCPhaseProb = pt_LAInput->t_SIT.pt_GetLaneChangeInfo->u_LCPhaseProb;
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA) */

#if (FCT_CFG_ROAD_INPUT)
  FIP_t_RoadWorks t_RoadWorks;

#if (SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_t_FusedRoadType t_FusedRoadType = (pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType);
#else
  const FIP_t_FusedRoadType t_FusedRoadType = FIP_ROAD_TYPE_UNKNOWN;
#endif /* FCT_CFG_INPUT_PREPROCESSSING */
  boolean b_UseOcclusion;
#endif
#endif /* FCT_CFG_ROAD_INPUT */

  f_EgoSpeed = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
  f_EgoSpeed = fABS(f_EgoSpeed);
  t_RelObjNr = pt_LAInput->t_OOI.pt_OOIRelObj->ObjectNr;

#if (FCT_CFG_ROAD_INPUT) && (FCT_CFG_INPUT_PREPROCESSSING)
  t_RoadWorks = (pt_LAInput->pt_FIPRoadType->t_FIPRoadWorks);
#elif (FCT_CFG_ROAD_INPUT)
  t_RoadWorks = FIP_NOINFO_ROADWORKS;
#endif

#if (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA)
  /* Consider the Camera Trajectory Based Lane Association only if
     the object is below 80m, Ego Speed below 80KPH, Road Type City,
     No lane change scenario and Ego lane change probability below 20 and
     for curve above 250m */ 
  if (   (f_ObjLongDisp < LA_CFG_INLANE_TIME_CAM_TRAJ_LA_OBJ_DISTX) 
      && (f_EgoSpeed < LA_CFG_INLANE_TIME_CAM_TRAJ_LA_EGO_SPEED) 
      && (t_FusedRoadType == FIP_ROAD_TYPE_CITY) 
      && (t_LCPhase == LC_NO_LANECHANGE) 
      && (u_LCPhaseProb <= LA_CFG_INLANE_TIME_CAM_TRAJ_LA_LC_PROB) 
      && (f_AbsCurve < LA_CFG_INLANE_TIME_CAM_TRAJ_LA_ACC_CURVE)
     )
  {
    t_CamTrajLaneAssoc = pt_LAOutput->t_LAObjOutputList[iObj].t_ObjCamTrajLaneAssoc;
  }
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA) */

  if((t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
    || (b_ObjIsMovingToStationary == TRUE))
  {
    fTimeThreshInLane = dGDBmathLineareFunktion( &LATimeThreshInLaneFromDist, f_ObjLongDisp);

#if (LA_HIGH_VEGO_INLANE_TIME)
    fTimeThreshInLane = LA_f_GetHighEgoVelInLaneTimeThreshold(iObj, fTimeThreshInLane);
#endif
#if (LA_SIT_VREL_INLANE_TIME_INC)
    fTimeThreshInLane = LA_f_GetSituationVrelInLaneTimeThreshold(iObj, fTimeThreshInLane);
#endif
#if (LA_TTC_DEPENDANT_INLANE_TIME)
    fTimeThreshInLane = LA_f_TTCDependantInLaneTimeThreshold(iObj, fTimeThreshInLane);
#endif

#if (LA_USE_CLUSTER_VARIANCE_IN_LANEASSOCIATION)
    if (( t_LA_InternalObjectData[iObj].ui_ClusterVarianceLevel == LA_CLUST_VAR_LEVEL_DIFFICULT)
#if(LA_CFG_ADAPT_INLANE_TIME_FOR_OBSTACLES)
      || (t_LA_InternalObjectData[iObj].ui_ClusterVarianceLevelforobstacles == LA_CLUST_VAR_LEVEL_DIFFICULT )
#endif
      )
    {
      /* Increase object inlane time threshold in case cluster variance of object is high and the situation is difficult */
      fTimeThreshInLane  = MAX_FLOAT(LA_CLUST_VAR_INLANE_TIME_THRES, fTimeThreshInLane);
    }
#endif

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
    /* Check distance to high curvature change (curve entry/exit) criteria */
    b_DistToHighCCCriteria = LA_b_CheckObjDistToCCCriteria(iObj);

    if ( (b_DistToHighCCCriteria == FALSE)
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
      && (((u_BlockedPathSelectionTimer < LA_BLOCKED_PATH_TIMER) && (f_VrelX > -(LA_VRELX_THRESH))) || ((b_SelectedByPathDecision == FALSE) && (f_VrelX <= -(LA_VRELX_THRESH))))
#else
      && (pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision == FALSE)
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
      && (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState != OBJ_STATE_INLANE)
       )
    {
      /* Increase object in-lane-time threshold in case object is above the distance where a high curvature change is defined */
      fTimeThreshInLane  = MAX_FLOAT( LA_CURVE_CHANGE_CRIT_INLANE_TIME, fTimeThreshInLane);
    }
#endif

#if (LA_CFG_NARROW_HIGHWAY_CRITERIA)
    /* Check  criteria */
    b_NarrowHighwayCriteria = LA_b_CheckNarrowHighwayCriteria(iObj);

    if ( (b_NarrowHighwayCriteria == FALSE)
#if (LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME)
      && (((u_BlockedPathSelectionTimer < LA_BLOCKED_PATH_TIMER) && (f_VrelX > -(LA_VRELX_THRESH))) || ((b_SelectedByPathDecision == FALSE) && (f_VrelX <= -(LA_VRELX_THRESH))))
#else
      && (pt_LAInput->t_SIT.pt_ObjBool(iObj)->SelectedByPathDecision == FALSE)
#endif /* LA_CFG_ADAPT_BLOCKED_PATH_TIMER_BASED_INLANE_TIME */
      && (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState != OBJ_STATE_INLANE)
      )
    {
      /* Increase object in-lane-time threshold in case the narrow highway criteria is false */
      fTimeThreshInLane  = MAX_FLOAT(LA_NARROW_HIGHWAY_CRIT_INLANE_TIME, fTimeThreshInLane);
    }
#endif

#if (FCT_CFG_ROAD_INPUT)
    /* Higher time threshold for roadworks only available if road estimation avail */
    if (t_RoadWorks == FIP_ROADWORKS_DETECTED)
    {
      fTimeThreshInLane = MAX_FLOAT(LA_PAR_ROADWORKS_INLANE_TIME_FACTOR * LA_MINTIME_MOVE_OBJ_IN_LANE_MAX, fTimeThreshInLane);
    }
#endif /* FCT_CFG_ROAD_INPUT */

#if (LA_CFG_ADAPT_INLANE_FAR_TRUCK)
  /*Increase the Inlane Time Threshold for Trucks which are longitudinally at higher distance */
   fTimeThreshInLane = LA_v_AdaptObjInLaneTimeThresholdFarTrucks(iObj, fTimeThreshInLane);
#endif /*(LA_CFG_ADAPT_INLANE_FAR_TRUCK)*/

#if(SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON)
#if (FCT_CFG_ROAD_INPUT)
    b_UseOcclusion = False;
    /*! Check if objects are occluded. Use different parameters for the highway and the city.
        Consider occlusion only if the object can become the OOI-0 based in the longitudinal distance
          in order to reduce the influence on the OOI-1). */  
    f_RelObjLongDisp = (t_RelObjNr > OBJ_INDEX_NO_OBJECT)? *pt_LAInput->t_RTE.pf_ObjLongDisp(t_RelObjNr):0.f;
    b_ObjOccludedByTrace = pt_LAInput->t_SIT.pt_ObjBool(iObj)->OccludedByTrace;
    f_RelObjLength = (t_RelObjNr > OBJ_INDEX_NO_OBJECT)? (pt_LAInput->pt_FIPOA->t_ObjList[t_RelObjNr].fObjectLength):0.f;
    f_EgoVelObjSync = *pt_LAInput->t_RTE.pf_EgoVelObjSync;
    if(t_FusedRoadType == FIP_ROAD_TYPE_HIGHWAY)
    {
      if ( ( ( (SLATE_p_GetEMGenObjAttributes(iObj)->eObjectOcclusion >= EM_GEN_OBJECT_OCCL_PARTLY) 
            && (f_ObjLongDisp < LA_OCCLUSION_MAX_DIST)
             ) 
          || (b_ObjOccludedByTrace == (ubit8_t)1u)
           ) 
        && ( (t_RelObjNr == OBJ_INDEX_NO_OBJECT)
          || ((f_RelObjLongDisp + f_RelObjLength) > (f_ObjLongDisp))
           )
         )
      {
        b_UseOcclusion = True;
      }
    }
    else if ( ( ( (SLATE_p_GetEMGenObjAttributes(iObj)->eObjectOcclusion >= EM_GEN_OBJECT_OCCL_PARTLY) 
               && (f_ObjLongDisp < LA_OCCLUSION_MAX_DIST)
                ) 
             || (b_ObjOccludedByTrace == (ubit8_t)1u)
              ) 
           && (f_ObjLongDisp > LA_OCCLUSION_MIN_DIST_NO_HIGHWAY)
           && (f_EgoVelObjSync > LA_OCCLUSION_MIN_VEL_NO_HIGHWAY)
           && ( (t_RelObjNr == OBJ_INDEX_NO_OBJECT)
             || ((f_RelObjLongDisp + f_RelObjLength) > (f_ObjLongDisp))
              )
            )
    {
      b_UseOcclusion = True;
    }
    else
    {
         /* Dummy 'else' condition for QA-C error.*/
    }

    /*! Increase the in lane timer threshold in case of a occlusion
          (threshold is higher on the highway compared to the city). */
    if((b_UseOcclusion == True) && (t_FusedRoadType == FIP_ROAD_TYPE_HIGHWAY))
    {
      fTimeThreshInLane = MAX_FLOAT(LA_PAR_OCC_HIGHWAY_INLANE_TIME_FAC * LA_MINTIME_MOVE_OBJ_IN_LANE_MAX,fTimeThreshInLane);
    }
    else if((b_UseOcclusion == True) && (t_FusedRoadType != FIP_ROAD_TYPE_HIGHWAY))
    {
      fTimeThreshInLane = MAX_FLOAT(LA_PAR_OCC_NO_HIGHWAY_INLANE_TIME_FAC * LA_MINTIME_MOVE_OBJ_IN_LANE_MAX,fTimeThreshInLane);
    }
    else
    {
         /* Dummy 'else' condition for QA-C error.*/
    }
#else
    _PARAM_UNUSED(b_ObjOccludedByTrace);
    _PARAM_UNUSED(f_RelObjLongDisp);
    _PARAM_UNUSED(f_RelObjLength);
    _PARAM_UNUSED(f_EgoVelObjSync);
#endif /* FCT_CFG_ROAD_INPUT */
#endif  /* (SIT_USE_OBJ_OCCLUSION_LANEASSOCIATION == SWITCH_ON) */
  }
  else /* Stationary Objects or vehicles */
  {
    if(  (t_ObjClassification == SLATE_OBJCLASS_CAR      )
      || (t_ObjClassification == SLATE_OBJCLASS_TRUCK    )
      || (t_ObjClassification == SLATE_OBJCLASS_MOTORCYCLE)
      )
    {
      fTimeThreshInLane = LA_f_CalcInlaneTimeStatVehicle(f_EgoSpeed, iObj );
    }
    else
    {
      fTimeThreshInLane = LA_f_CalcInlaneTimeStatNonVehicle(f_EgoSpeed, iObj );
    }
#if (LA_CFG_ADAPT_INLANE_TIME_THRESHOLD_STAT_OBJ_CURVE)
    if(fABS(*pt_LAInput->t_RTE.pf_EgoCurve) > LA_EGO_CURVE_THRES)
	{
        fTimeThreshInLane = MAX_FLOAT((fTimeThreshInLane + LA_EGO_CURVE_INLANE_TIME_FACTOR), fTimeThreshInLane);
	}
#endif

#if (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT)
    /* Increase the InLane Time threshold for Stationary Objects on Curve */
    fTimeThreshInLane = LA_f_GetInLaneTimeCurveStatThreshold(iObj, fTimeThreshInLane);
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CURVE_STAT) */

#if (LA_CFG_TRAJ_DYNAMISM_DETECTION)
    fTimeThreshInLane = LA_v_AdaptObjInLaneTimeThresholdTrajDynamism(iObj, fTimeThreshInLane);
#endif /* LA_CFG_TRAJ_DYNAMISM_DETECTION */
  }

#if (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA)
  /* If the Camera Trajectory Based Lane Association says it is not in Ego Lane then Increase the In-lane Time threshold */
  if ((t_CamTrajLaneAssoc == LA_OBJ_CAM_LANE_LEFT) || (t_CamTrajLaneAssoc == LA_OBJ_CAM_LANE_RIGHT))
  {
    fTimeThreshInLane = MAX_FLOAT(LA_CFG_INLANE_TIME_CAM_TRAJ_LA_THRESHOLD, fTimeThreshInLane);
  }
#endif /* (LA_CFG_ADAPT_INLANE_TIME_CAM_TRAJ_LA) */

    /* for Pedestrian Detection overwrite the required time in Lane */
#if SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN
  if( (f_ObjLongDisp <= LA_MAX_DIST_STAT_PED_SELECTION)
    &&(f_EgoSpeed <= LA_MAX_SPEED_STAT_PED_SELECTION) )
  {
    fTimeThreshInLane = LA_MINTIME_STAT_PED_IN_LANE;
  }
 #endif

#if ((EM_ARS_OBJECT_LIST_INTFVER >= 6u) && (LA_CFG_MICRODOPPLER_PEDESTRIAN_HIGH_INLANE_TIME))
  if (OBJ_ARS_SENSORSPECIFIC(iObj).bPedMicroDoppler == TRUE)
  {
    /* Increased in-lane time for objects with micro doppler signature */
    fTimeThreshInLane = MAX_FLOAT(LA_MICRODOPPLER_HIGH_INLANE_TIME_THRES, fTimeThreshInLane);
  }
#endif

    /* Increase the Time in Lane as long as the sensor is unlearned */
  if(  (pt_LAInput->t_RTE.f_EgoYawRateQuality <= LA_VDY_YAWRATE_QUAL_SENSOR_UNLEARNED)
      &&(f_ObjLongDisp > LA_SAFE_DIST_UNLEARNED)
    )
  {
    fTimeThreshInLane = fTimeThreshInLane * LA_UNLEARNED_SENSOR_INLANE_TIME_RISE_FACTOR;
  }

#ifdef FCT_SIMU
  pt_LAOutput->t_LAObjOutputList[iObj].fInLaneTimeThres = fTimeThreshInLane;
#endif

  return(fTimeThreshInLane);
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckInlaneTimer                                                                               */ /*!

  @brief           Check time condition for in lane decision of objects

  @description     Check time condition for in lane decision of objects

                  @startuml
                  partition LA_b_CheckInlaneTimer
                  start
                  :Initialize the return value to FALSE;
                  if (corridor relevant time for the object > given time threshold) then (true)
                    :Set the return value to TRUE;
                  else (false)
                  endif
                  :Return the inline timer check value;
                  stop
                  @enduml


  @return          TRUE if object has satisfied in-lane time criteria [TRUE, FALSE]

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThres : Time threshold the inlane timer is checked against [full range of fTime_t as in Rte_type.h]

  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [full range of data type float > 0.f]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2016
  @changed         15.03.2018

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
extern boolean LA_b_CheckInlaneTimer( const ObjNumber_t iObj, const fTime_t fTimeThres )
{
  boolean result = FALSE;

  if (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime > fTimeThres)
  {
    result = TRUE;
  }
  else
  {
    
  }

  return( result );
}

/*************************************************************************************************************************
  Functionname:    LA_v_UpdateInlaneTimer                                                                               */ /*!

  @brief           Update timer for in lane decision of objects

  @description     Update timer for in lane decision of objects

                  @startuml
                  partition LA_b_UpdateInlaneTimer
                  start
                  if (corridor relevant time for the object > given time threshold) then (true)
                    if (object is not stationary or object is stationary to moving) then (true)
                      :set the corridor relevant time for the object to maximum value for stationary objects;
                    endif 
                  else (false)
                    :Increase the corridor relevant time by **SLATE_f_GetSITCycleTime**;
                  endif
                  stop
                  @enduml


  @return          none

  @param[in]       iObj : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fTimeThres : Time threshold the inlane timer is checked against [full range of fTime_t as in Rte_type.h]

  @glob_in         *SLATE_pt_GetObjDynProperty(i) : Dynamic property of an object i [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsMovingToStationary(i) : Boolean if an stationary object i was seen moving [TRUE, FALSE]
  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [full range of data type float > 0.f]
  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime : Time the relevant object has been seen inlane [full range of data type float > 0.f]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION  : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         12.02.2016
  @changed         15.03.2018

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
extern void LA_v_UpdateInlaneTimer( const ObjNumber_t iObj, const fTime_t fTimeThres )
{
  boolean b_ObjIsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(iObj);
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = (*pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj));

  if (pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime > fTimeThres)
  {
    if ( (t_ObjDynProperty != SLATE_OBJECT_PROPERTY_STATIONARY)
      || (b_ObjIsMovingToStationary == TRUE)
      )
    {
      pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime = LA_MAX_CORR_REL_TIME_NONSTAT;
    }
  }
  else
  {
    pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.fCorridorRelevantTime += SLATE_f_GetSITCycleTime();
  }
}
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup */
#endif /* FCT_CFG_ACC_LANE_ASSOCIATION */

// PRQA L:STTLN_EXCEEDED
