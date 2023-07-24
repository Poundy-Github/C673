/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_pred_lane_assoc.c

DESCRIPTION:               This module inherits all functions for predicted lane association. Here, objects 
                           future position is determined and checked whether it will be in ego lane or not 
                           based on its lateral velocity/displacement

AUTHOR:                    Grant Davtjan

CREATION DATE:             23.05.2018

VERSION:                   $Revision: 1.53 $

LEGACY VERSION:            Revision: 2.1

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
@defgroup la_pred_lane_assoc LA predicted lane association
@ingroup la_laneassociation
@brief         Objects association to diffrent lane is done using predictions based on lateral velocity/displacement of objects. \n\n

@{
*/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/* SET STRUCTIRES FOR PREDICTED LANE ASSOCIATION */

SET_MEMSEC_CONST(t_CutOut_weight)
  static const GDBLFunction_t t_CutOut_weight = // PRQA S 3218
  { 
    /* date: 2015-03-11, reviewer: Steffen Luis, reason: static local for saving data across function calls */
    LA_PRED_POTENTIAL_MIN_OUTPUT,
    LA_PRED_POTENTIAL_MAX_OUTPUT,
    (LA_PRED_POTENTIAL_MAX_OUTPUT-LA_PRED_POTENTIAL_MIN_OUTPUT)/(LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MAX-LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MIN),
    LA_PRED_POTENTIAL_MAX_OUTPUT-((LA_PRED_POTENTIAL_MAX_OUTPUT-LA_PRED_POTENTIAL_MIN_OUTPUT)/(LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MAX-LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MIN)*LA_PRED_CUTOUT_WEIGHT_DIST_TO_TRAJ_MAX)
  };

SET_MEMSEC_CONST(LAPredTimeFromTimeGap)
  static const GDBLFunction_t LAPredTimeFromTimeGap = // PRQA S 3218
  { 
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_TG_DEP_MAX,
    LA_PRED_TIME_TG_DEP_MIN,
    ( ( LA_PRED_TIME_TG_DEP_MIN - LA_PRED_TIME_TG_DEP_MAX ) / ( LA_PRED_TIME_TG_DEP_UPPER - LA_PRED_TIME_TG_DEP_LOW ) ),
    LA_PRED_TIME_TG_DEP_MAX - ( (( LA_PRED_TIME_TG_DEP_MIN - LA_PRED_TIME_TG_DEP_MAX ) / ( LA_PRED_TIME_TG_DEP_UPPER - LA_PRED_TIME_TG_DEP_LOW ) ) * LA_PRED_TIME_TG_DEP_LOW)
  };

SET_MEMSEC_CONST(LAPredTimeFromDistX)
  static const GDBLFunction_t LAPredTimeFromDistX = // PRQA S 3218
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_DISTX_DEP_MAX,
    LA_PRED_TIME_DISTX_DEP_MIN,
    ( ( LA_PRED_TIME_DISTX_DEP_MIN - LA_PRED_TIME_DISTX_DEP_MAX ) / ( LA_PRED_TIME_DISTX_DEP_UPPER - LA_PRED_TIME_DISTX_DEP_LOW ) ),
    LA_PRED_TIME_DISTX_DEP_MAX - ( (( LA_PRED_TIME_DISTX_DEP_MIN - LA_PRED_TIME_DISTX_DEP_MAX ) / ( LA_PRED_TIME_DISTX_DEP_UPPER - LA_PRED_TIME_DISTX_DEP_LOW ) ) * LA_PRED_TIME_DISTX_DEP_LOW)
  };

#if(LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE)
SET_MEMSEC_CONST(LAPredTimeFromDistXClose)
  static const GDBLFunction_t LAPredTimeFromDistXClose = // PRQA S 3218, 3207
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_DISTX_CLOSE_DEP_MAX,
    LA_PRED_TIME_DISTX_CLOSE_DEP_MIN,
    ( ( LA_PRED_TIME_DISTX_CLOSE_DEP_MIN - LA_PRED_TIME_DISTX_CLOSE_DEP_MAX ) / ( LA_PRED_TIME_DISTX_CLOSE_DEP_UPPER - LA_PRED_TIME_DISTX_LOWEGOVEL_LOW ) ),
    LA_PRED_TIME_DISTX_CLOSE_DEP_MAX - ( (( LA_PRED_TIME_DISTX_CLOSE_DEP_MIN - LA_PRED_TIME_DISTX_CLOSE_DEP_MAX ) / ( LA_PRED_TIME_DISTX_CLOSE_DEP_UPPER - LA_PRED_TIME_DISTX_CLOSE_DEP_LOW ) ) * LA_PRED_TIME_DISTX_LOWEGOVEL_LOW)
  };
#endif /*(LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE)*/

SET_MEMSEC_CONST(LAPredTimeFromCurve)
  static const GDBLFunction_t LAPredTimeFromCurve = // PRQA S 3218
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_CURVE_DEP_MAX,
    LA_PRED_TIME_CURVE_DEP_MIN,
    ( ( LA_PRED_TIME_CURVE_DEP_MIN - LA_PRED_TIME_CURVE_DEP_MAX ) / ( LA_PRED_TIME_CURVE_DEP_UPPER - LA_PRED_TIME_CURVE_DEP_LOW ) ),
    LA_PRED_TIME_CURVE_DEP_MAX - ( (( LA_PRED_TIME_CURVE_DEP_MIN - LA_PRED_TIME_CURVE_DEP_MAX ) / ( LA_PRED_TIME_CURVE_DEP_UPPER - LA_PRED_TIME_CURVE_DEP_LOW ) ) * LA_PRED_TIME_CURVE_DEP_LOW)
  };

SET_MEMSEC_CONST(LAPredTimeFromHighEgoVel)
  static const GDBLFunction_t LAPredTimeFromHighEgoVel = // PRQA S 3218
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_EGOVEL_DEP_MAX,
    LA_PRED_TIME_EGOVEL_DEP_MIN,
    ( ( LA_PRED_TIME_EGOVEL_DEP_MIN - LA_PRED_TIME_EGOVEL_DEP_MAX ) / ( LA_PRED_TIME_EGOVEL_DEP_UPPER - LA_PRED_TIME_EGOVEL_DEP_LOW ) ),
    LA_PRED_TIME_EGOVEL_DEP_MAX - ( (( LA_PRED_TIME_EGOVEL_DEP_MIN - LA_PRED_TIME_EGOVEL_DEP_MAX ) / ( LA_PRED_TIME_EGOVEL_DEP_UPPER - LA_PRED_TIME_EGOVEL_DEP_LOW ) ) * LA_PRED_TIME_EGOVEL_DEP_LOW)
  };

#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST))
/* - Parameters for non-camera confirmed objects or the object distance is less than 30m or Object classified as TRUCK by both Radar and Camera - */
SET_MEMSEC_CONST(LAPredTimeFromTimeGapNoCamConf)
  static const GDBLFunction_t LAPredTimeFromTimeGapNoCamConf = // PRQA S 3218
  { 
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_MAX_NO_CAM_CONF,
    LA_PRED_TIME_TG_DEP_MIN,
    ( ( LA_PRED_TIME_TG_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_TG_DEP_UPPER - LA_PRED_TIME_TG_DEP_LOW ) ),
    LA_PRED_TIME_MAX_NO_CAM_CONF - ( (( LA_PRED_TIME_TG_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_TG_DEP_UPPER - LA_PRED_TIME_TG_DEP_LOW ) ) * LA_PRED_TIME_TG_DEP_LOW)
  };

SET_MEMSEC_CONST(LAPredTimeFromDistXNoCamConf)
  static const GDBLFunction_t LAPredTimeFromDistXNoCamConf = // PRQA S 3218
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_MAX_NO_CAM_CONF,
    LA_PRED_TIME_DISTX_DEP_MIN,
    ( ( LA_PRED_TIME_DISTX_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_DISTX_DEP_UPPER - LA_PRED_TIME_DISTX_DEP_LOW ) ),
    LA_PRED_TIME_MAX_NO_CAM_CONF - ( (( LA_PRED_TIME_DISTX_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_DISTX_DEP_UPPER - LA_PRED_TIME_DISTX_DEP_LOW ) ) * LA_PRED_TIME_DISTX_DEP_LOW)
  };

#if(LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE)
SET_MEMSEC_CONST(LAPredTimeFromDistXCloseNoCamConf)
  static const GDBLFunction_t LAPredTimeFromDistXCloseNoCamConf = // PRQA S 3218, 3207
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_DISTX_CLOSE_DEP_MAX_NO_CAM_CONF,
    LA_PRED_TIME_DISTX_CLOSE_DEP_MIN_NO_CAM_CONF,
    ( ( LA_PRED_TIME_DISTX_CLOSE_DEP_MIN_NO_CAM_CONF - LA_PRED_TIME_DISTX_CLOSE_DEP_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_DISTX_CLOSE_DEP_UPPER - LA_PRED_TIME_DISTX_CLOSE_DEP_LOW ) ),
    LA_PRED_TIME_DISTX_CLOSE_DEP_MAX_NO_CAM_CONF - ( (( LA_PRED_TIME_DISTX_CLOSE_DEP_MIN_NO_CAM_CONF - LA_PRED_TIME_DISTX_CLOSE_DEP_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_DISTX_CLOSE_DEP_UPPER - LA_PRED_TIME_DISTX_CLOSE_DEP_LOW ) ) * LA_PRED_TIME_DISTX_CLOSE_DEP_LOW)
  };
#endif/*(LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE)*/

SET_MEMSEC_CONST(LAPredTimeFromCurveNoCamConf)
  static const GDBLFunction_t LAPredTimeFromCurveNoCamConf = // PRQA S 3218
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_MAX_NO_CAM_CONF,
    LA_PRED_TIME_CURVE_DEP_MIN,
    ( ( LA_PRED_TIME_CURVE_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_CURVE_DEP_UPPER - LA_PRED_TIME_CURVE_DEP_LOW ) ),
    LA_PRED_TIME_MAX_NO_CAM_CONF - ( (( LA_PRED_TIME_CURVE_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_CURVE_DEP_UPPER - LA_PRED_TIME_CURVE_DEP_LOW ) ) * LA_PRED_TIME_CURVE_DEP_LOW)
  };

SET_MEMSEC_CONST(LAPredTimeFromHighEgoVelNoCamConf)
  static const GDBLFunction_t LAPredTimeFromHighEgoVelNoCamConf = // PRQA S 3218
  {
    /* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
    LA_PRED_TIME_MAX_NO_CAM_CONF,
    LA_PRED_TIME_EGOVEL_DEP_MIN,
    ( ( LA_PRED_TIME_EGOVEL_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_EGOVEL_DEP_UPPER - LA_PRED_TIME_EGOVEL_DEP_LOW ) ),
    LA_PRED_TIME_MAX_NO_CAM_CONF - ( (( LA_PRED_TIME_EGOVEL_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_EGOVEL_DEP_UPPER - LA_PRED_TIME_EGOVEL_DEP_LOW ) ) * LA_PRED_TIME_EGOVEL_DEP_LOW)
  };

SET_MEMSEC_CONST(LAPredTimeFromTTCNoCamConf)
  static const GDBLFunction_t LAPredTimeFromTTCNoCamConf = // PRQA S 3218 
     /* date: 2020-07-17, reviewer:Gireesh , reason: static local for saving data across function calls */
  {
    LA_PRED_TIME_MAX_NO_CAM_CONF,
    LA_PRED_TIME_TTC_DEP_MIN,
    ( ( LA_PRED_TIME_TTC_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_TTC_DEP_UPPER - LA_PRED_TIME_TTC_DEP_LOW ) ),
    LA_PRED_TIME_MAX_NO_CAM_CONF - ( (( LA_PRED_TIME_TTC_DEP_MIN - LA_PRED_TIME_MAX_NO_CAM_CONF ) / ( LA_PRED_TIME_TTC_DEP_UPPER - LA_PRED_TIME_TTC_DEP_LOW) ) * LA_PRED_TIME_TTC_DEP_LOW)
  };

#endif /* ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST)) */

SET_MEMSEC_CONST(LAPredTimeFromTTCCamConf)
  static const GDBLFunction_t LAPredTimeFromTTCCamConf = // PRQA S 3218 
    /* date: 2020-07-17, reviewer:Gireesh , reason: static local for saving data across function calls */
  {
    LA_PRED_TIME_TTC_DEP_MAX,
    LA_PRED_TIME_TTC_DEP_MIN,
    ( ( LA_PRED_TIME_TTC_DEP_MIN - LA_PRED_TIME_TTC_DEP_MAX ) / ( LA_PRED_TIME_TTC_DEP_UPPER - LA_PRED_TIME_TTC_DEP_LOW ) ),
    LA_PRED_TIME_TTC_DEP_MAX - ( (( LA_PRED_TIME_TTC_DEP_MIN - LA_PRED_TIME_TTC_DEP_MAX ) / ( LA_PRED_TIME_TTC_DEP_UPPER - LA_PRED_TIME_TTC_DEP_LOW ) ) * LA_PRED_TIME_TTC_DEP_LOW)
  };


/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION
*****************************************************************************/
static void LA_t_UpdatePredInlaneTimer(ObjNumber_t ObjId, fTime_t t_TimeToInlap, fTime_t t_TimeToInlapThreshold, fTime_t f_InlaneTimeThreshold);
static void LA_t_UpdatePredOutlaneCounter(ObjNumber_t ObjId, fTime_t t_TimeToInlapDrop, fTime_t t_TimeToInlapDropThreshold, uint8 u_CounterThres);/* PRQA S 2200 */
/* Date: 2020-04-02, Reviewer:Gireesh , Reason:This warning is suppressed as Indentation does not have any critical impact the functionality. */

static fTime_t LA_t_GetTimeToInlap(ObjNumber_t ObjId);
static fTime_t LA_t_GetTimeToInlapDrop(ObjNumber_t ObjId);

static boolean LA_b_CheckPredictedInlaneCriteria(ObjNumber_t iObj);
static boolean LA_b_CheckPredictedOutlaneCriteria(ObjNumber_t iObj);
static fTime_t LA_f_GetPredTimeThreshold(const ObjNumber_t iObj);
static void LA_f_CalculateDistanceToInlap(ObjNumber_t ObjId);
static void LA_f_CalculateDistanceToInlapDrop(ObjNumber_t ObjId);

/*PRQA S 2013,2016 EMPTY_ELSE_OR_DEFAULT*/
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Empty else or default, no effect on functionality*/

/****************************************************************************************************************************
  Functionname:    LA_b_CheckPredictedInlaneCriteria                                                                   */ /*!

  @brief           Check criteria for an object for predicted Inlane

  @description     This function is performing Out to In Predicted lane association, by calculating total time to inlap.

                    @startuml
					partition LA_b_CheckPredictedInlaneCriteria {
                    Start
                        : Calculate DistanceToInlap;
                        : Get Predicted low time threshold;
                        : Get the Time To Inlap;
                        : Get the In lane timer Threshold;
                        : Calculate Remaining Inlane Timer;
                        : Calcule total inlane timer;
                        If((Check If Total Time To Inlap is below Minimum Predicted time threshold
                            and Predicted time threshold is greater than zero) then (True)
                            : It is Inlane, Return True;
                        Else (False)
                            : Return False;
                    End
					}
                    @enduml

  @return          b_RetVal : Boolean if the prediction estimates the object to be in ego lane [TRUE, FALSE]

  @param[in]       iObj : Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_PredTimeThreshold: Predicted lower time threshold
  @glob_in         LA_t_GetTimeToInlap(iObj): Returns computed Time to Inlap
  @glob_in         LA_f_GetInLaneTimeThreshold(iObj): Inlane Timer threshold for the iObj
  @glob_in         LA_b_CheckCustomInlaneCriteria(iObj): To consider camera cutin potential

  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlap : To store Total time to Inlap of iObj

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
 
  @traceability    340:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-340-00061542 \n
                   324:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-324-00061542 \n

  @created         17.05.2018
  @changed         17.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static boolean LA_b_CheckPredictedInlaneCriteria(ObjNumber_t iObj)
{
  boolean b_RetVal;
  fTime_t t_TimeToInlap;
  fTime_t f_InlaneTimeThreshold;
  fTime_t t_ILT_remaining;
  fTime_t t_TimeToInlapThreshold;
  boolean  b_CustomInlaneCriteria;

  b_RetVal = FALSE;

  /*!Calculate DistanceToInlap */
  LA_f_CalculateDistanceToInlap(iObj);

  /*!Get Predicted time threshold*/
  t_TimeToInlapThreshold = pt_LAOutput->t_LAObjOutputList[iObj].t_PredTimeThreshold;

  /*!Get Time To Inlap*/
  t_TimeToInlap = LA_t_GetTimeToInlap(iObj);

  /* Limit minimum time to inlap threshold for consistency */
  t_TimeToInlap = MAX_FLOAT(t_TimeToInlap, t_TimeToInlapThreshold);

  /*!Get the In lane timer Threshold*/
  f_InlaneTimeThreshold = LA_f_GetInLaneTimeThreshold(iObj); 
  
  /*!Calculate Remaining Inlane Time*/
  t_ILT_remaining = f_InlaneTimeThreshold - pt_LAOutput->t_LAObjOutputList[iObj].t_PredInlaneTimer;

  /*!Update current Inlane timer*/
  LA_t_UpdatePredInlaneTimer(iObj, t_TimeToInlap, t_TimeToInlapThreshold, f_InlaneTimeThreshold);
  
  /*! Take custom inlane criteria e.g. camera cut-in potential into consideration */
  b_CustomInlaneCriteria = LA_b_CheckCustomInlaneCriteria(iObj);

  if (b_CustomInlaneCriteria == TRUE)
  {
    pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlap = 0.f;
  }
  else
  {
    /*!Calculate total time to Inlap*/
    pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlap = t_TimeToInlap + t_ILT_remaining;
  }

  /*!If Total Time To Inlap is below Minimum threshold then it is Inlane */
  if((pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlap <= t_TimeToInlapThreshold) && (t_TimeToInlapThreshold > 0.f))
  { 
    b_RetVal = TRUE;
  }
  else
  {
    /*! Do Nothing */
  }

  return b_RetVal;
}

/*************************************************************************************************************************
  Functionname:    LA_f_CalculateDistanceToInlap                                                                          */ /*!

  @brief           Get Total distance to Inlap for inlane prediction

  @description     This function returns the Total distance from the objects inner edge to the tracebracket
                  @startuml
				  partition LA_f_CalculateDistanceToInlap {
                  Start
                    : Get In lane timer Threshold;
                    : Calculate DistanceToInlap;
                    if(DistanceToInlap is greater than 0) then (yes)
						-Object has not reached the DistanceToInlap
					else
						-Object has passed the DistanceToInlap
					endif
                  End
				  }
                  @enduml

  @return          None.

  @param[in]       ObjId : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       LA_f_GetInLaneTimeThreshold(ObjId); To get the Inlane Timer Threshold

  @glob_out        pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap: Object has not reached the tracebracket
  @glob_out        pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlap: Once the Object has passed the tracebracket
  
  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.08.2018
  @changed         29.08.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_f_CalculateDistanceToInlap(ObjNumber_t ObjId)
{
  fTime_t f_InlaneTimeThreshold;
  const LA_t_TrajInlap *p_Inlap = &(pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRelation);
  float32 f_ObjInlapPickupThresh = pt_LAOutput->t_LAObjOutputList[ObjId].f_ObjInlapPickupThresh;


  /*!Get the In lane timer Threshold*/
  f_InlaneTimeThreshold = LA_f_GetInLaneTimeThreshold(ObjId); 

#if (LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD)
  f_ObjInlapPickupThresh = LA_f_AdaptObjInlapPickupThresholdForCutIn(ObjId, f_ObjInlapPickupThresh);
#endif /* END IF LA_CFG_ADAPT_INLANE_INLAP_PICKUP_THRESHOLD */

  /*!Calculate DistanceToInlap*/
  pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap = f_ObjInlapPickupThresh - LA_f_GetCorrectedInlap(p_Inlap);

  /*! Calculate total distance to Inlap */
  if(pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap > 0.0f)
  {
    /*!Object has not reached the DistanceToInlap */
    pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlap = pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap + (f_InlaneTimeThreshold * LA_TIME_TO_DIST_TRANS_FACTOR);
  }
  else
  {
    /*!Object has passed the DistanceToInlap */
    pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlap = (f_InlaneTimeThreshold - pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.fCorridorRelevantTime) * LA_TIME_TO_DIST_TRANS_FACTOR;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_t_GetTimeToInlap                                                                          */ /*!

  @brief           Get Time to Inlap for inlane prediction

  @description     This function returns the Time to Inlap for a given object by 
                   calculating Distance to inlap and using Lateral velocity of the object.
                  @startuml
                  Partition LA_t_GetTimeToInlap {
                  Start
                   - Get Lateral Velocity
                    If (Object is on right of trajectory) then (True)
                       - Object on right of trajectory will only be considered when they have positive lateral velocity, i.e. towards EGO lane
                    Else (False)
                        -Object on left of trajectory will only be considered when they have negative lateral velocity, i.e. towards EGO lane
                    Endif
                  
                    If(DistanceToInlap is less than or equal to 0) then (True)
                      -Set Time to Inlap as 0
                    else 
                      -Calculate TimeToInlap
                    Endif
                  End
                  }
                  @enduml

  @return          t_TimeToInlap : Calculated Time to Inlap for the object.

  @param[in]       ObjId : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]


  @glob_in         pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth : Distance to trajectory
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelY(i) : Relative velocity of an object i                                  [-330.f ... 330.f] m/s
  @glob_in         &(pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRelation) : To get the Inlap
  @glob_out        None


  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    319:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-319-00061542 \n
                   321:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-321-00061542 \n
                   323:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-323-00061542 \n

  @created         17.05.2018
  @changed         17.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static fTime_t LA_t_GetTimeToInlap(ObjNumber_t ObjId)
{
  float32 f_ObjLatVel; 
  float32 f_Dist2Traj = pt_LAOutput->t_LAObjOutputList[ObjId].TrajDist.TrajDistMeas.Y.f0;
  boolean b_LatVelToTraj = FALSE;
  fTime_t t_TimeToInlap;
  float32 fABS_ObjLatVel;	/* For calculating ABS value */
  
  /*! Get Lateral Velocity */
  f_ObjLatVel = (*pt_LAInput->t_RTE.pf_ObjVrelY(ObjId));

  /*! Object is on right of trajectory */
  if(f_Dist2Traj < 0.f) 
  {
    /*! Object on right of trajectory will only be considered when they have positive lateral velocity, i.e. towards EGO lane */
    if (f_ObjLatVel > 0.f)
    {
      b_LatVelToTraj = TRUE;
    }
  }
  /*! Object is on left of trajectory */
  else
  {
    /*! Object on left of trajectory will only be considered when they have negative lateral velocity, i.e. towards EGO lane */
    if (f_ObjLatVel < 0.f)
    {
      b_LatVelToTraj = TRUE;
    }
  }

  /* Object is inside the trace brackets*/
  if (pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap <= 0.f) 
  {
      /*Set Time to Inlap as 0 */
    t_TimeToInlap = 0.f;
  }
  else
  {
	fABS_ObjLatVel = fABS(f_ObjLatVel);
    if ( (b_LatVelToTraj == TRUE)
      && (fABS_ObjLatVel > C_F32_DELTA) /* check for division by zero*/
       )
    {
        /*!Calculate TimeToInlap*/
        t_TimeToInlap = MIN_FLOAT(LA_PRED_TIME_INIT_HIGH, pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlap/fABS(f_ObjLatVel));
    }
    else
    {
        /*!When object is not cutting in*/
        t_TimeToInlap = LA_PRED_TIME_INIT_HIGH;
    }
  }

   return t_TimeToInlap;
}

/*************************************************************************************************************************
  Functionname:    LA_t_UpdatePredInlaneTimer                                                                          */ /*!

  @brief           Determines current inlane timer.

  @description     Determines current inlane timer based on the Inlane time Threshold.

                  @startuml 
                  Partition LA_t_UpdatePredInlaneTimer {
                  Start
                       If (TimeToInlap is less than or equal to TimeToInlapThreshold) then (True)
                         -Start the timer
                          If (Check if the Predicted inlane current timer is more than the inlane timer threshold) then  (True)
                             -reset the timer to the inlane timer threshold
                          Endif
                       Else (False)
                         -Object is outlane.
                       Endif
                  End
                  }
                  @enduml


  @return          None

  @param[in]       ObjId : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
                   t_TimeToInlap: The amount of time to reach the pick up distance.
                   t_TimeToInlapThreshold: Predicted lower time threshold.
                   f_InlaneTimeThreshold: Inlane timer threshold.


  @glob_in         None
  @glob_out        pt_LAOutput->t_LAObjOutputList[ObjId].t_PredInlaneTimer: Updated current inlane timer


  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    325:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-325-00061542 \n

  @created         17.05.2018
  @changed         17.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_t_UpdatePredInlaneTimer(ObjNumber_t ObjId, fTime_t t_TimeToInlap, fTime_t t_TimeToInlapThreshold, fTime_t f_InlaneTimeThreshold)
{
  /*!Check if inLap time is below the inlane timer threshold*/
  if(t_TimeToInlap <= t_TimeToInlapThreshold)
  {
      /*! Start the timer*/
      pt_LAOutput->t_LAObjOutputList[ObjId].t_PredInlaneTimer += SLATE_f_GetSITCycleTime();

      /*!If the Predicted inlane current timer is more than the inlane timer threshold then reset the timer to the inlane timer threshold */
      if(pt_LAOutput->t_LAObjOutputList[ObjId].t_PredInlaneTimer > f_InlaneTimeThreshold)
      {
          pt_LAOutput->t_LAObjOutputList[ObjId].t_PredInlaneTimer = f_InlaneTimeThreshold;
      }
  }
  else
  {
      /*!Object is outlane*/
      pt_LAOutput->t_LAObjOutputList[ObjId].t_PredInlaneTimer = 0.f;
  }

}


/*************************************************************************************************************************
  Functionname:    LA_b_CheckPredictedOutlaneCriteria                                                                   */ /*!

  @brief           Check criteria for an object for predicted Outlane

  @description     This function is performing In to Out Predicted lane association, by calculating total time to Inlap Drop.

                   @startuml
                   partition LA_b_CheckPredictedOutlaneCriteria {
                   Start
                       : Calculate DistanceToInlapDrop;
                       : Get Predicted low time threshold;
                       : Get the Time To Inlap Drop;
                       : Limit minimum time to inlap-drop threshold for consistency;
                       : Get the outlane counter threshold;
                       : Outlane counter threshold based on situation;
                       : Update current Outlane counter;
                       : Take custom outlane criteria;
                   If(Custom Outlane Criteria is true) then (yes)
                       :Set Total Time To InlapDrop to 0;
                   else
                       : Calculate Remaining Outlane Time;
                       : Calculate total time to Inlap Drop;
                       If(Total Time To Inlap Drop is below Minimum Predicted time threshold and Predicted time threshold is greater than zero) then (true)
                           :Object is Outlane;
                       Endif
                   endif
                   End
                   }
                   @enduml

  @return          b_RetVal : Boolean if the prediction estimates the object to be in ego lane [TRUE, FALSE]

  @param[in]       iObj :  Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[iObj].t_PredTimeThreshold : To get the Lower pricted timer threshold
  @glob_out        pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlapDrop : To store Total time to Inlap drop of iObj

  @traceability    341:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-341-00061542 \n
                   334:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-334-00061542 \n

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.05.2018
  @changed         23.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static boolean LA_b_CheckPredictedOutlaneCriteria(ObjNumber_t iObj)
{
  boolean b_RetVal;
  fTime_t t_TimeToInlapDrop;
  fTime_t t_TimeToInlapDropThreshold;
  uint8 u_CounterThres;
  boolean b_CustomOutlaneCriteria;
  fTime_t t_OLT_remaining;

  b_RetVal = FALSE;

  /*!Calculate DistanceToInlapDrop */
  LA_f_CalculateDistanceToInlapDrop(iObj);

  /*!Get Predicted low time threshold*/
  t_TimeToInlapDropThreshold = pt_LAOutput->t_LAObjOutputList[iObj].t_PredTimeThreshold;

  /*!Get the Time To Inlap Drop*/
  t_TimeToInlapDrop = LA_t_GetTimeToInlapDrop(iObj);

  /*!Limit minimum time to inlap-drop threshold for consistency */
  t_TimeToInlapDrop = MAX_FLOAT(t_TimeToInlapDrop, t_TimeToInlapDropThreshold);

  /*!Get the outlane counter threshold*/
#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
  u_CounterThres = 0u; 
  /*Outlane counter threshold based on situation */
  u_CounterThres = LA_u_GetObjOutlaneCounterThreshold(iObj,u_CounterThres);
#else
  u_CounterThres = LA_OUTLANE_CYCLE_MIN;
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */
  /*!Update current outlane counter */
  LA_t_UpdatePredOutlaneCounter(iObj, t_TimeToInlapDrop, t_TimeToInlapDropThreshold, u_CounterThres);

  /*!Take custom outlane criteria e.g. camera cut-out potential into consideration */
  b_CustomOutlaneCriteria = LA_b_CheckCustomOutlaneCriteria(iObj);

  if (b_CustomOutlaneCriteria == TRUE)
  {
    pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlapDrop = 0.f;
    b_RetVal = TRUE;
  }
  else
  {
    /*!Calculate Remaining Outlane Time*/
    t_OLT_remaining = ((float32)u_CounterThres - (float32)pt_LAOutput->t_LAObjOutputList[iObj].u_PredOutlaneCounter) * SLATE_f_GetSITCycleTime();

    /*!Calculate total time to Inlap Drop*/
    pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlapDrop = t_TimeToInlapDrop + t_OLT_remaining;

    /*!If Total Time To Inlap Drop is below Minimum threshold then it is Outlane */
    if((pt_LAOutput->t_LAObjOutputList[iObj].t_TotalTimeToInlapDrop <= t_TimeToInlapDropThreshold) && (t_TimeToInlapDropThreshold > 0.f))
    { 
      b_RetVal = TRUE;
    }
  }

  return b_RetVal;
}


/*************************************************************************************************************************
  Functionname:    LA_f_CalculateDistanceToInlapDrop                                                                          */ /*!

  @brief           Get Total distance to Inlap for inlane prediction

  @description     This function returns the Total distance from the objects inner edge to the tracebracket
                   @startuml
                   partition LA_f_CalculateDistanceToInlapDrop {
                   Start
                     : Get outlane counter threshold;
                   If(Inlap Variance is less than  Max. Inlap variance for normal object occupancy drop border) then (Yes)
                        : Calculate Distance To Inlap Drop as difference of Inlap Variance and Object Inlap Drop Threshold;
                   Else 
                      : Calculate Distance To Inlap Drop as difference of Inlap Variance and minimum of object occupancy drop border for insecure inlap and Object Inlap Drop Threshold;
                   Endif
                   
                   If(Distance To Inlap Drop is greater than 0) then (yes)
                        : Object has not reached the DistanceToInlapDrop;
                   Else
                        : Object has passed the DistanceToInlapDrop;
                   Endif
                   
                   End
                   }
                   @enduml

  @return          None.

  @param[in]       ObjId : Object Number (Object ID) [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_out        pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop: Object has not reached the tracebracket
  @glob_out        pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlapDrop: Once the Object has passed the tracebracket calculate the total distance based on the counter.
  
  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         29.08.2018
  @changed         29.08.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_f_CalculateDistanceToInlapDrop(ObjNumber_t ObjId)
{
  uint8 u_CounterThres;
  const LA_t_TrajInlap *p_Inlap = &(pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRelation);
  
#if(LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD)
  /*Outlane counter threshold based on situation */
  u_CounterThres = 0u; 
  u_CounterThres = LA_u_GetObjOutlaneCounterThreshold(ObjId,u_CounterThres);
#else
  /*!Get the outlane counter threshold*/
  u_CounterThres = LA_OUTLANE_CYCLE_MIN;
#endif /* (LA_CFG_ADAPT_OUTLANE_COUNTER_THRESHOLD) */

  /* The two different cases are needed for alignment with geometrical lane association (compare with the functions LA_b_CheckObjInlapDropValue) */
  if(p_Inlap->fInlapVar < LA_OBJ_INLANE_DROP_MAX_INLAP_VAR)
  {
    /*!Calculate DistanceToInlapDrop*/
    pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop = p_Inlap->fInlap - pt_LAOutput->t_LAObjOutputList[ObjId].f_ObjInlapDropThresh;
  }
  else
  {
    /*!Calculate DistanceToInlapDrop*/
    pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop = p_Inlap->fInlap - MIN_FLOAT(LA_OBJ_INLANE_DROP_INSECURE_INLAP, pt_LAOutput->t_LAObjOutputList[ObjId].f_ObjInlapDropThresh);
  }
  
  /*! Calculate total distance to InlapDrop */
  if(pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop > 0.0f)
  {
    /*!Object has not reached the DistanceToInlapDrop */
    pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlapDrop = pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop + (((float32)u_CounterThres*SLATE_f_GetSITCycleTime()) * LA_TIME_TO_DIST_TRANS_FACTOR);
  }
  else
  {
    /*!Object has passed the DistanceToInlapDrop */
    pt_LAOutput->t_LAObjOutputList[ObjId].f_TotalDistanceToInlapDrop = (((float32)u_CounterThres - (float32)pt_LAOutput->t_LAObjOutputList[ObjId].ObjLaneAccStatus.Inlap_In2OutlaneCounter) * SLATE_f_GetSITCycleTime()) * LA_TIME_TO_DIST_TRANS_FACTOR;
  }
}

/*************************************************************************************************************************
  Functionname:    LA_t_GetTimeToInlapDrop                                                                   */ /*!

  @brief           Get Time To Inlap Drop for in-to outlane objects.

  @description     This function returns the Time to Inlap Drop for a given object by 
                   calculating Distance to inlap drop and using Lateral velocity of the object.

                   @startuml
                   partition LA_t_GetTimeToInlapDrop {
                   Start
                        :Get Lateral Velocity;
                        If (Check if Object is on right of trajectory) then (True)
                            : Object on right of trajectory will only be considered when they have negative lateral velocity;
                        Else (False)
                            :Object on left of trajectory will only be considered when they have positive lateral velocity;
                        Endif
                        :Calculate DistanceToInlapDrop;
                        If(Check if Object is outlane) then (True)
                          :Set Time to Inlap  Drop as 0;
                        else 
                          :Calculate TimeToInlapDrop;
                        Endif
                   End
                   }
                   @enduml


  @return          t_TimeToInlapDrop: Returns the time to inlap drop

  @param[in]       iObj :  Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajDistWidth : Distance to trajectory
  @glob_in         pt_LAInput->t_RTE.pf_ObjVrelY(i) : Relative velocity of an object i                                  [-330.f ... 330.f] m/s
  @glob_in         &(pt_LAOutput->t_LAObjOutputList[ObjId].ObjTrajRelation) : To get the Inlap
  @glob_in         pt_LAOutput->t_LAObjOutputList[ObjId].f_ObjInlapDropThresh : Drop threshold for the particular object

  @glob_out        None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
 
  @traceability    320:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-320-00061542 \n
                   330:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-330-00061542 \n
                   333:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-333-00061542 \n

  @created         23.05.2018
  @changed         23.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static fTime_t LA_t_GetTimeToInlapDrop(ObjNumber_t ObjId)
{
  float32 f_ObjLatVel; 
  float32 f_Dist2Traj = pt_LAOutput->t_LAObjOutputList[ObjId].TrajDist.TrajDistMeas.Y.f0;
  boolean b_LatVelToTraj = FALSE;
  fTime_t t_TimeToInlapDrop;
  float32 fABS_ObjLatVel;	/* For calculating ABS value */

  /*! Get Lateral Velocity */
  f_ObjLatVel = (*pt_LAInput->t_RTE.pf_ObjVrelY(ObjId));

  /*! Object is on right of trajectory */
  if(f_Dist2Traj < 0.f) 
  {
    /*! Object on right of trajectory will only be considered when they have negative lateral velocity */
    if (f_ObjLatVel < 0.f)
    {
      b_LatVelToTraj = TRUE;
    }
  }
  /*! Object is on left of trajectory */
  else
  {
    /*! Object on left of trajectory will only be considered when they have positive lateral velocity */
    if (f_ObjLatVel > 0.f)
    {
      b_LatVelToTraj = TRUE;
    }
  }

  /*! Object is already Outlane */
  if ( (pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop <= 0.f)
    && (b_LatVelToTraj == TRUE)
    )
  {
    t_TimeToInlapDrop = 0.f;
  }
  else
  {     /* check for division by zero*/
    fABS_ObjLatVel = fABS(f_ObjLatVel);
    if ( (b_LatVelToTraj == TRUE)
      && (fABS_ObjLatVel > C_F32_DELTA) 
       )
    {
        /*!Calculate TimeToInlapDrop*/
        t_TimeToInlapDrop = MIN_FLOAT(LA_PRED_TIME_INIT_HIGH, pt_LAOutput->t_LAObjOutputList[ObjId].f_DistanceToInlapDrop/fABS(f_ObjLatVel));
    }
    else
    {
        /*!When object is not making cutout*/
        t_TimeToInlapDrop = LA_PRED_TIME_INIT_HIGH;
    }
  }

  return t_TimeToInlapDrop;
}


/*************************************************************************************************************************
  Functionname:    LA_t_UpdatePredOutlaneCounter                                                                   */ /*!

  @brief           Determine current outlane counter.

  @description     Determine current outlane counter based on drop threshold.

                   @startuml
                   partition LA_t_UpdatePredOutlaneCounter {
                   Start
                       If ( InLap Drop time is below than Drop threshold) then (True)
                         -Start the timer
                          If (Check if the Predicted Outlane current timer is more than the Outlane timer threshold) then  (True)
                             -reset the timer to the Outlane timer threshold
                          Endif
                       Else (False)
                         -Object is Inlane.
                       Endif
                   End
                   }
                   @enduml
  @return          None

  @param[in]       iObj :  Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_out        pt_LAOutput->t_LAObjOutputList[ObjId].u_PredOutlaneCounter: Current oulane counter

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    335:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-335-00061542 \n

  @created         23.05.2018
  @changed         23.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
static void LA_t_UpdatePredOutlaneCounter(ObjNumber_t ObjId, fTime_t t_TimeToInlapDrop, fTime_t t_TimeToInlapDropThreshold, uint8 u_CounterThres)
{
  /*!Check if Time to Inlap Drop is below the Drop threshold*/
  if(t_TimeToInlapDrop <= t_TimeToInlapDropThreshold)
  {
      /*! Start the counter*/
      pt_LAOutput->t_LAObjOutputList[ObjId].u_PredOutlaneCounter += 1;

      /*!If the Predicted current Outlane counter is more than the Outlane counter threshold then reset the Outlane counter to the Outlane counter threshold */
      if(pt_LAOutput->t_LAObjOutputList[ObjId].u_PredOutlaneCounter > u_CounterThres)
      {
          pt_LAOutput->t_LAObjOutputList[ObjId].u_PredOutlaneCounter = u_CounterThres;
      }
  }
  else
  {
      /*!Object is inlane*/
      pt_LAOutput->t_LAObjOutputList[ObjId].u_PredOutlaneCounter = 0u;
  }

}

/*************************************************************************************************************************
  Functionname:    LA_f_GetPredTimeThreshold                                                                       */ /*!

  @brief           Get the prediction time for predicted lane association

  @description     Get the prediction time for predicted lane association. This is the main and only tuning parameter for 
                   predicted lane association.

                   @startuml
                   partition LA_f_GetPredTimeThreshold{
                   Start
                      -Get object details from camera data 
                   
                   If(object is not camera confirmed) then (yes)
                   -prediction time shall be lower as in a radar-only system
                   Endif
                   
                   If(object distance is less than 30m OR object is classified as TRUCK by Radar AND Camera) then (yes)
                   -prediction time shall be lower
                   Endif
                   
                   If(Object relative longitudinal velocity is less than LA PREDICTED OBJECT LONGITUDINAL RELATIVE VELOCITY X MINIMUM  OR
                   Ego velocity is less than LA PREDICTED EGO VELOCITY MINIMUM OR
                   Object longitudinal displacement is less than  LA PREDICTED OBJECT DISTX MINIMUM  OR
                   Relative velocity is greater than LA PREDICTED OBJECT RELATIVE VELOCITY Y MAX ABS OR
                   Probability of Tunnel is greater than LA TUNNEL PROBABILITY THRESHOLD OR
                   (Lateral displacenet of the object is greater than LA PREDICTED CLOSE OBJECT DISTANCE X ABS AND
                   Object longitudinal displacement is less than LA PREDICTED CLOSE OBJECT DISTX)) then (Yes)
                   -Predicted Inlane is turned off
                   Elseif(Predicted Inlane time is low)then (yes)
                   -calculate Predicted Inlane time base on time gap, Object longitudinal displacement and absolute ego curve 
                      If(Ego velocity is greater than LA PREDICTED TIME EGO VELOCITY LOW)then (yes)
                      -set predicted time to minimum of current predicted time and ego velocity
                      Endif
                   
                      If(Ego object velocity is less than LA PREDICTED EGO VELOCITY MINIMUM and Object longitudinal displacement is less than LA PREDICTED CLOSE OBJECT DISTX MAXIMUM and 
                   absolute ego curve is less than LA PREDICTED TIME LOWCURVE MAXIMUM and greate than LA PREDICTED TIME LOWCURVE MINIMUM) then (yes)
                      -set predicted time to minimum of current predicted time and Object longitudinal displacement
                      endif

                      If(there are no relevant object)
                      - Limit prediction time to avoid drop-ins in free-drive mode
                      endif
                   
                   else
                    - Inlane lower time threshold is Predicted based on Time gap, longitudinal displacement, Ego curve, and Ego velocity
                      If(Ego velocity is greater than LA PREDICTED TIME EGO VELOCITY LOW)then (yes)
                      -set predicted time to minimum of current predicted time and ego velocity
                      Endif
                   
                      If(Ego object velocity is less than LA PREDICTED EGO VELOCITY MINIMUM and Object longitudinal displacement is less than LA PREDICTED CLOSE OBJECT DISTX MAXIMUM and 
                   absolute ego curve is less than LA PREDICTED TIME LOWCURVE MAXIMUM and greate than LA PREDICTED TIME LOWCURVE MINIMUM) then (yes)
                      -set predicted time to minimum of current predicted time and Object longitudinal displacement
                      Endif
                       
                      If(there are no relevant object)
                      - Limit prediction time to avoid drop-ins in free-drive mode
                      endif
                   endif
                   
                   if(Turnlight indicator confidence is above a threshold
                       annd if there is lateral movement in the correct direction) then (Yes)
                       if(object turn light indicator and lateral velocity is towards right)then (yes)
                       -set predicted time to LA PREDICTED TIME TURN INDICATOR 
                       elseif(object turn light indicator and lateral velocity is towards left) then (yes)
                       -set predicted time to LA PREDICTED TIME TURN INDICATOR 
                       Else
                       -Do nothing
                       Endif
                   Endif
                   
                   if(ego vehicle is moving) then (Yes)
                       if( distance to object is between 10m and 100m and
                       (ego turn light indicator and lateral velocity is towards right) or 
                       (ego turn light indicator and lateral velocity is towards left)) then (yes)
                       -set predicted time to LA_PRED_TIME_EGOTURNIND 
                       Else
                       -Do nothing
                       Endif
                   Endif

                   If (there is movement away from trajectory it could be a Cut-out case or the end of an Cut-in case) then (yes)
                       - use a bounded linear function, to smoothly separate this two cases and prevent the Cut-out case from toggling
                   endif
                   
                   End
                   }
                   @enduml

  @return          f_PredTime : prediction time for predicted lane association

  @param[in]       iObjNr : object ID for which predicted lane association is done [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         *(pt_LAInput->t_RTE.pf_EgoVelObjSync) : To get the Ego velocity
  @glob_in         *(pt_LAInput->t_RTE.pf_ObjLongDisp(iObj)) : Object longitudinal displacement
  @glob_in         (*(pt_LAInput->t_RTE.pf_ObjVrelY(iObj))) : Relative lateral velocity
  @glob_in         (*(pt_LAInput->t_RTE.pf_ObjLatDisp(iObj))): Lateral displacenet of the object
  @glob_in         (*(pt_LAInput->t_RTE.pf_EgoCurve)): Ego curvature
  @glob_in         pt_LAInput->pt_FIPOA.pt_CamConfirmationProb(iObj): Prob if the cam object exists
  @glob_in         pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_TurnLightsStateConf: Prob if the target turnind is set
  @glob_in         pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.eTurnLightsState: Target turnind state
  @glob_in         *pt_LAInput->t_RTE.pt_TurnIndicator : Ego turn indicator
  @glob_in         pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType: Road type information
  @glob_in         *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj): Dynamic property of the object

  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         5/18/2018
  @changed         5/18/2018

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
static fTime_t LA_f_GetPredTimeThreshold(const ObjNumber_t iObj)
{
  fTime_t f_PredTime;
  fTime_t f_TimeGap;
  float32 f_ObjVrelYAbs;
  float32 f_ObjLatDispAbs;
  float32 f_EgoCurveAbs;
  float32 f_EgoVelObjSync;
  float32 f_ObjLongDisp;
  float32 f_ObjVrelY = *pt_LAInput->t_RTE.pf_ObjVrelY(iObj);
  float32 f_DistToTraj = pt_LAOutput->t_LAObjOutputList[iObj].TrajDist.TrajDistMeas.Y.f0;
  ObjNumber_t iRelObjIndex;  
  float32 fObjVrelX = *(pt_LAInput->t_RTE.pf_ObjVrelX(iObj));
  SLATE_t_Obj_CLassification t_ObjClass = *pt_LAInput->t_RTE.pt_ObjClassification(iObj);
  float32 f_ObjVrelxAbs      = fABS(fObjVrelX);
  float32 f_Timetocollision;
#if (LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD)
  float32 f_ObjVerlYStd      = SLATE_f_GetObjVrelYStd(iObj);
  float32 f_ObjDistYStd      = SLATE_f_GetObjDistYStd(iObj);
  float32 f_PredTimeVerlYStd = 0.0f;
  float32 f_PredTimeDistYStd = 0.0f;
#endif /* LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD */

#if (SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE)
  FIP_t_CamTurnLightsState TurnLightsState = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.eTurnLightsState;
  percentage_t TurnLightsStateConf = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_TurnLightsStateConf;
  SLATE_t_Obj_DynamicProperty t_ObjDynProperty = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj);
#endif /* SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE */
#if ((SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) && (LA_CFG_EGO_TURNIND_BASED_PICKUP))
  eTurnIndicator_t EgoTurnIndicator = *pt_LAInput->t_RTE.pt_TurnIndicator;
  FIP_t_FusedRoadType t_FusedRoadType = pt_LAInput->pt_FIPRoadType->t_FIPFusedRoadType;
  SLATE_t_Obj_DynamicProperty ObjDynProperty = *pt_LAInput->t_RTE.pt_ObjDynamicProperty(iObj);
  float32 f_ObjLatDisp = *pt_LAInput->t_RTE.pf_ObjLatDisp(iObj);
#endif /* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT && LA_CFG_EGO_TURNIND_BASED_PICKUP */
#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  percentage_t t_camConfirmationProb = pt_LAInput->pt_FIPOA->t_ObjList[iObj].t_CamObjectData.t_CamConfirmationProb;
#endif /* FCT_CFG_CAMERA_OBJECT_DETECTION */
#if (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST)
  EM_t_GenObjClassification t_CamObjClass = pt_LAInput->t_RTE.p_EMCustObj(iObj)->CamObjectData.e_CamClass;
#endif /* (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST) */
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST))
  boolean b_UseLowPredTime = FALSE;
#endif /* ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST)) */

  f_EgoVelObjSync    = *(pt_LAInput->t_RTE.pf_EgoVelObjSync);
  f_ObjLongDisp      = *(pt_LAInput->t_RTE.pf_ObjLongDisp(iObj));
  f_ObjVrelYAbs      = fABS(f_ObjVrelY);
  f_ObjLatDispAbs    = fABS(*(pt_LAInput->t_RTE.pf_ObjLatDisp(iObj)));
  f_EgoCurveAbs      = fABS(*(pt_LAInput->t_RTE.pf_EgoCurve));

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
  /* In case object is not camera confirmed prediction time shall be lower as in a radar-only system */
  if (t_camConfirmationProb < LA_PAR_CAM_CONF_MIN)
  {
    b_UseLowPredTime = TRUE;
  }
#endif /* (FCT_CFG_CAMERA_OBJECT_DETECTION) */

#if (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST)
  /* In case object distance is less than 30m OR object is classified as TRUCK by Radar AND Camera then prediction time shall be lower */
  if ( (f_ObjLongDisp < LA_LOW_PRED_CLOSE_OBJ_DIST) ||
       ((t_ObjClass == SLATE_OBJCLASS_TRUCK) && (t_CamObjClass == SLATE_OBJCLASS_TRUCK)) )
  {
    b_UseLowPredTime = TRUE;
  }
#endif /* (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST) */

  /*!Predicted Inlane is turned off for these scenarios otherwise it is calculated  */
  
  if ( (fObjVrelX < LA_PRED_OBJ_LONG_VREL_MIN)
#if (LA_PRED_EGO_VEL_MIN_DISABLE)
    || (f_EgoVelObjSync < LA_PRED_EGO_VEL_MIN)
#endif
    || (f_ObjLongDisp < LA_PRED_OBJ_DISTX_MIN)
    || (f_ObjVrelYAbs > LA_PRED_OBJ_VRELY_MAX_ABS)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    || (*(pt_LAInput->t_RTE.pf_TunnelProbability) > LA_TUNNEL_PROB_THRES)
#endif
    || ( (f_ObjLatDispAbs > LA_PRED_CLOSE_OBJ_DISTY_ABS)
      && (f_ObjLongDisp < LA_PRED_CLOSE_OBJ_DISTX)
       )
     )
  {
    f_PredTime = 0.0f;
  }  
#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST))
  /* In case object is not camera confirmed or the object distance is less than 30m or Object classified as TRUCK by both Radar and Camera
     prediction time shall be lower */
  else if (b_UseLowPredTime == TRUE)
  {
    ObjNumber_t i_RelObjIndex;
    f_EgoVelObjSync = MAX_FLOAT(CML_f_Delta, f_EgoVelObjSync);
	
	f_ObjVrelxAbs = MAX_FLOAT(CML_f_Delta, f_ObjVrelxAbs);

    f_TimeGap = (f_ObjLongDisp)/(f_EgoVelObjSync);

    f_PredTime = dGDBmathLineareFunktion( &LAPredTimeFromTimeGapNoCamConf, f_TimeGap);

    f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromDistXNoCamConf, f_ObjLongDisp ) );

    f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromCurveNoCamConf, f_EgoCurveAbs) );

    if (f_EgoVelObjSync > LA_PRED_TIME_EGOVEL_DEP_LOW)
    {
      f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromHighEgoVelNoCamConf, f_EgoVelObjSync) );
    }

#if (LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE)
    if (    (f_EgoVelObjSync < LA_PRED_EGO_VEL_MIN) && (f_ObjLongDisp < LA_PRED_CLOSE_OBJ_DISTX_MAX)  
        &&  ((f_EgoCurveAbs < LA_PRED_TIME_LOWCURVE_MAX) && (f_EgoCurveAbs > LA_PRED_TIME_LOWCURVE_MIN)))
    {
      f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromDistXCloseNoCamConf, f_ObjLongDisp ) );
    }
#endif
    f_Timetocollision = (f_ObjLongDisp)/(f_ObjVrelxAbs);
    
	if((t_ObjClass != SLATE_OBJCLASS_TRUCK) && (f_PredTime > 0.f) && (f_ObjLatDispAbs < LA_PRED_CLOSE_OBJ_DISTY_ABS))
	{
	  f_PredTime = MAX_FLOAT(f_PredTime,dGDBmathLineareFunktion( &LAPredTimeFromTTCNoCamConf, f_Timetocollision));
    }
    
	i_RelObjIndex = SLATE_i_GetRelObjIndex();
    
	if ((i_RelObjIndex == OBJ_INDEX_NO_OBJECT))
    {
      /* In free-drive mode limit prediction time to avoid drop-ins */
      f_PredTime = MIN_FLOAT(f_PredTime, LA_PRED_TIME_FREEDRIVE_NO_CAM_CONF);
    }
  }
#endif /* ((FCT_CFG_CAMERA_OBJECT_DETECTION) || (LA_CFG_LOWER_PRED_TIME_FOR_CLOSER_DIST)) */
  /*! Inlane lower time threshold is Predicted based on Time gap, longitudinal displacement, Ego curve, and Ego velocity*/
  else
  {
    f_EgoVelObjSync = MAX_FLOAT(CML_f_Delta, f_EgoVelObjSync);

	f_ObjVrelxAbs = MAX_FLOAT(CML_f_Delta, f_ObjVrelxAbs);

    f_TimeGap = (f_ObjLongDisp)/(f_EgoVelObjSync);

    f_PredTime = dGDBmathLineareFunktion( &LAPredTimeFromTimeGap, f_TimeGap);

    f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromDistX, f_ObjLongDisp ) );

    f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromCurve, f_EgoCurveAbs) );

    if (f_EgoVelObjSync > LA_PRED_TIME_EGOVEL_DEP_LOW)
    {
      f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromHighEgoVel, f_EgoVelObjSync) );
    }

#if (LA_PRED_EGO_VEL_AND_OBJ_DISTX_ENABLE)
    if (    (f_EgoVelObjSync < LA_PRED_EGO_VEL_MIN) && (f_ObjLongDisp < LA_PRED_CLOSE_OBJ_DISTX_MAX)  
        &&  ((f_EgoCurveAbs < LA_PRED_TIME_LOWCURVE_MAX) && (f_EgoCurveAbs > LA_PRED_TIME_LOWCURVE_MIN)))
    {
      f_PredTime = MIN_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromDistXClose, f_ObjLongDisp ) );
    }
#endif
    f_Timetocollision = (f_ObjLongDisp)/(f_ObjVrelxAbs);	
	
	if((t_ObjClass != SLATE_OBJCLASS_TRUCK) && (f_PredTime > 0.f) && (f_ObjLatDispAbs < LA_PRED_CLOSE_OBJ_DISTY_ABS))
    {
	  f_PredTime = MAX_FLOAT(f_PredTime, dGDBmathLineareFunktion( &LAPredTimeFromTTCCamConf, f_Timetocollision));
    }
	
    iRelObjIndex = SLATE_i_GetRelObjIndex();
    
	if ((iRelObjIndex == OBJ_INDEX_NO_OBJECT))
    {
      /* In free-drive mode limit prediction time to avoid drop-ins */
      f_PredTime = MIN_FLOAT(f_PredTime, LA_PRED_TIME_FREEDRIVE);
    }
  }

#if (SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE)
  /*This part will make usage of the Target Turnlight indicator.
    The Turnlight indicator is only valid, if the confidence is above a threshold
    and if there is lateral movement in the correct direction
  */
  if (  ( TurnLightsStateConf > (percentage_t)LA_TURNIND_CONF_MIN )
      &&( t_ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING )
     )
  {
    /* object turn light indicator and lateral velocity to the right */
    if ( (TurnLightsState == FIP_CAM_TURN_LIGHT_RIGHT) 
      && (f_ObjVrelY < -LA_TURNIND_VRELY_THRES)
      )
    {
        f_PredTime = LA_PRED_TIME_TURNIND;
    }
    /* object turn light indicator and lateral velocity to the left */
    else if ( (TurnLightsState == FIP_CAM_TURN_LIGHT_LEFT) 
           && (f_ObjVrelY > LA_TURNIND_VRELY_THRES)
            )
    {
        f_PredTime = LA_PRED_TIME_TURNIND;
    }
    else {}
  }
#endif /* SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE */

#if ((SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) && (LA_CFG_EGO_TURNIND_BASED_PICKUP))
  /*This part will make usage of the ego Turn indicator */
  /* Object is moving and object class is not Point object */
  /* Road type is highway or country road */
  /* Lateral distance to object is within the threshold LA_EGOTURNIND_MAX_DISTY */
  /* Longitudinal distance to object is between LA_EGO_TURNIND_MIN_DISTX and LA_EGO_TURNIND_MAX_DISTX */
  if (  (ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING) 
      &&(t_ObjClass != SLATE_OBJCLASS_POINT)
      &&(  (t_FusedRoadType == FIP_ROAD_TYPE_COUNTRY)
         ||(t_FusedRoadType == FIP_ROAD_TYPE_HIGHWAY)
        )
      && ((f_ObjLatDisp < LA_EGOTURNIND_MAX_DISTY) && (f_ObjLatDisp > -LA_EGOTURNIND_MAX_DISTY))
      && ((f_ObjLongDisp > LA_EGO_TURNIND_MIN_DISTX) && (f_ObjLongDisp < LA_EGO_TURNIND_MAX_DISTX))
     )
  {
    /* left ego turn light indicator and lateral velocity to the left */
    /* right ego turn light indicator and lateral velocity to the right */
    if ( (  (EgoTurnIndicator == eTurnIndicator_Left) 
          &&(f_ObjVrelY < -LA_EGOTURNIND_VRELY_THRES))
       ||(  (EgoTurnIndicator == eTurnIndicator_Right) 
          &&(f_ObjVrelY > LA_EGOTURNIND_VRELY_THRES))
       )
    {
      f_PredTime = LA_PRED_TIME_EGOTURNIND;
    }
    else 
    {
      /* Do nothing */
    }
  }
#endif /* SIT_CFG_LC_USE_TURN_INDICATOR_INPUT && LA_CFG_EGO_TURNIND_BASED_PICKUP*/

#if (LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD)
  if (   (f_PredTime > 0.0f)
      && (f_EgoCurveAbs < LA_PRED_TIME_EMINPUTSTD_CURVE_MIN)
      && (t_ObjClass != SLATE_OBJCLASS_TRUCK)
      && (f_ObjLongDisp > LA_PRED_MIN_RELX_POS)
    )
  {
    if(   (f_ObjDistYStd < LA_PRED_DISTYSTD_MIN)
       && (f_ObjVerlYStd < LA_PRED_VRELYSTD_MIN)
      )
    {
      f_PredTime += LA_PRED_TIME_MAX_EXT_LAT_STD;
    }
    else if (   ((f_ObjDistYStd < LA_PRED_DISTYSTD_MIN) && (f_ObjVerlYStd < LA_PRED_VRELYSTD_MAX)) 
             || ((f_ObjDistYStd < LA_PRED_DISTYSTD_MAX) && (f_ObjVerlYStd < LA_PRED_VRELYSTD_MIN))
            )
    {
      f_PredTimeDistYStd = MINMAX_FLOAT(0.0f, LA_PRED_TIME_MAX_EXT_LAT_STD, (LA_PRED_DISTYSTD_MAX - f_ObjDistYStd));
      f_PredTimeVerlYStd = MINMAX_FLOAT(0.0f, LA_PRED_TIME_MAX_EXT_LAT_STD, (LA_PRED_VRELYSTD_MAX - f_ObjVerlYStd));
      f_PredTime += MIN_FLOAT(f_PredTimeDistYStd,f_PredTimeVerlYStd);
    }
  }
#endif /* LA_CFG_USE_EXTENDED_PRED_TIME_BASED_ON_LAT_STD */

  /* If there is movement away from trajectory it could be a Cut-out case or the end of an Cut-in case. 
     We use a bounded linear function, to smoothly separate this two cases and prevent the Cut-out case from
     toggling.
     The weight can be 0...1. */

  if (  ((f_DistToTraj > 0.f) && (f_ObjVrelY > 0.f))
      ||((f_DistToTraj < 0.f) && (f_ObjVrelY < 0.f))
     )
  {
    /*! Calculate cutOut potential */
    f_PredTime = f_PredTime * dGDBmathLineareFunktion(&t_CutOut_weight, CML_f_Abs(f_DistToTraj));
  }

  return f_PredTime;
}

/*************************************************************************************************************************
  Functionname:    LA_b_CheckPredLaneAssoc                                                                          */ /*!

  @brief           Perform the predicted lane association

  @description     Set the predicted lane association flags dependent on the in-lane state

                   @startuml
                   partition LA_b_CheckPredLaneAssoc {
                   Start
                   : Get the predicted time threshold;
                   : Get the Predicted Inlane Criteria time threshold;
                      if(In-lane state is outlane?) then (True)
                         :Do nothing;
                      Else(False)       
                         :Set the predicted out-lane criteria for the object;
                      Endif
                   End
                   }
                   @enduml


  @return          void

  @param[in]       iObjNr : object ID for which predicted lane association is done [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAOutput->t_LAObjOutputList[i].ObjLaneAccStatus.LAInlaneState : State if object i is inlane (confirmed with all criteria) [LA_t_LaneState as defined in fct_sen_feedback.h]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.OutLCustomValue : Outlane custom flag (predicted outlane) [TRUE, FALSE]
  @glob_out        pt_LAOutput->t_LAObjOutputList[i].t_Bool.InLCustomValue : Inlane custom flag (predicted outlane) [TRUE, FALSE]

  @c_switch_part   None
  @c_switch_full   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/20/2017
  @changed         5/29/2018

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
void LA_v_PredLaneAssoc(const ObjNumber_t iObj)
{
  /*!Get the predicted time threshold */
  pt_LAOutput->t_LAObjOutputList[iObj].t_PredTimeThreshold = LA_f_GetPredTimeThreshold(iObj);

  pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.InLCustomValue = LA_b_CheckPredictedInlaneCriteria(iObj);

  /* State Flow for Predicted Lane association */
  switch(pt_LAOutput->t_LAObjOutputList[iObj].ObjLaneAccStatus.LAInlaneState)
  {
    case OBJ_STATE_OUTLANE:
    break;

    case OBJ_STATE_INLANE:
      #if (LA_CFG_NO_RADAR_PREDICTED_OUTLANE)
       pt_LAOutput->t_LAObjOutputList[iObj].t_PredTimeThreshold = 0.0f;
      #endif
      pt_LAOutput->t_LAObjOutputList[iObj].t_Bool.OutLCustomValue = LA_b_CheckPredictedOutlaneCriteria(iObj);
    break;

    default:
    break;
  }
}
/* PRQA L:EMPTY_ELSE_OR_DEFAULT */
/** @} end defgroup */
#endif /* (FCT_CFG_ACC_LANE_ASSOCIATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

