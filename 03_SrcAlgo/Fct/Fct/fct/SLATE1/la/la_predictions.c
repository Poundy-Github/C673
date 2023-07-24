/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_predictions.c

DESCRIPTION:               This module inherits all calculation for predictions
                           made by LA component e.g. predicted lateral displacement etc.

AUTHOR:                    Fridolin Kolb

CREATION DATE:             -

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */



/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/

/* The functions in this file are not in use and the file can be removed in future */

#if (0)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_predictions LA predictions
@ingroup la
@brief          This module inherits all calculation for predictions
                           made by LA component  \n\n

@{

*/

/*****************************************************************************
  MACROS 
*****************************************************************************/
/* predicted distance for the ARS Object CAR */
#define LA_PRED_DIST_FOR_ARSOBJ_CAR (0.9f)
/* predicted displacement To Course Standard for the ARS Object TRUCK */
#define LA_PRED_DIST_FOR_ARSOBJ_TRUCK (1.25f)
/* predicted distance for the object apart from CAR or Truck*/
#define LA_PRED_DIST_FOR_OBJECT_OTHER_THAN_CAR_OR_TRUCK (0.4f)
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

SET_MEMSEC_CONST(LACutOutPredTime)
static const GDBLFunction_t LACutOutPredTime = {// PRQA S 3218
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls */

  LA_CUT_OUT_PRED_MAX,
  LA_CUT_OUT_PRED_MIN,
  ( ( LA_CUT_OUT_PRED_MIN - LA_CUT_OUT_PRED_MAX ) / ( LA_CUT_OUT_DIST_MAX - LA_CUT_OUT_DIST_MIN ) ),
  LA_CUT_OUT_PRED_MAX - ( (( LA_CUT_OUT_PRED_MIN - LA_CUT_OUT_PRED_MAX ) / ( LA_CUT_OUT_DIST_MAX - LA_CUT_OUT_DIST_MIN ) ) * LA_CUT_OUT_DIST_MIN)
};

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/* Currently not used
static fTime_t LA_t_LimitPredictionBySpeed(fTime_t normal_prediction_time);
*/
/*************************************************************************************************************************
  Functionname:    LA_v_CalcPredDisplToCourseStandard                                                                  */ /*!

  @brief           Calculate predicted displacement to course by standard values defined in la_par.h

  @description     This function calculates the predicted lateral displacement to course
                   with standard parameters which are defined in la_par.h.
                   Those are:
                     - SI_VREL_TO_TRAJ_TRUST_VALUE
                       The relation between variance and average value of Vrel to course
                       to trust in the Vrel value.
                     - SI_VREL_TO_TRAJ_TRUST_RISE_VALUE
                       The relation between variance and average value of Vrel to course
                       to rise the trust to the Vrel value. Below this value, Vrel is taken
                       without any restrictions.

                      @startuml 
                      partition LA_v_CalcPredDisplToCourseStandard {
                      Start
                       -Get actual distance to course and the gradient
                       -The predicted displacement is the actual position plus the product of gradient and prediction time
                       -check for zero crossing
                        if(object is car) then (yes)
                          -calculate an object width of 1.8m and subtract half of it off calculated distance
                        elseif(object is Truck) then (yes)
                           -to do FK originally 1.25, but due to problems with classification, cars and trucks are now the same
                        else
                           -calculate an object width of 0.4 m and subtract half of it off calculated distance
                         endif
                      
                      End
                      }
                      @enduml


  @return          void

  @param[in]       prediction_time : time to calculate the predicted lateral displacement [0 ... 100.f] s
  @param[in]       object_class : Object class                                            [SLATE_t_Obj_CLassification as defined in Rte_Type.h]
  @param[in]       obj_id : Object Number (Object ID)                                     [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in,out]   pred_dist : Pointer to variables of the predicted distance             [LA_t_PredictedDistance as defined in si.h]
                      pdist : The predicted lateral displacement to vehicle course        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pdist_var : Variance of the predicted lateral displacement with calculated prediction time        [0 ... SQRT(PI/2*RW_FCT_MAX)] m
                      pdist_var_fullpred :  Variance of the predicted lateral displacement with maximum prediction time [0 ... SQRT(PI/2*RW_FCT_MAX)] m
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.02.2016
  @changed         26.02.2016

  @author          Fridolin Kolb,  fridolin01.kolb@contiautomotive.com
*************************************************************************************************************************/
void LA_v_CalcPredDisplToCourseStandard(fTime_t prediction_time, SLATE_t_Obj_CLassification object_class, ObjNumber_t obj_id, LA_t_PredictedDistance* pred_dist)
{
  float32 DistanceToTraj;
  float32 DistanceToTrajVar;
  float32 VRelToTraj;
  float32 VRelToTrajVar;
  float32 p_dist_var;
  float32 p_dist_var_fullpred;
  float32 p_dist;
  float32 fVRelToTrajVarFac = LA_VARIANCE_SCALE_FACTOR;

  /* Get actual distance to course and the gradient (Vrel to course) */
   DistanceToTraj = pt_LAOutput->t_LAObjOutputList[obj_id].TrajDist.TrajDistMeas.Y.f0;
   DistanceToTrajVar = pt_LAOutput->t_LAObjOutputList[obj_id].TrajDist.TrajDistFilt.P.f00;

  VRelToTraj = pt_LAOutput->t_LAObjOutputList[obj_id].TrajDist.TrajDistFilt.X.f1;
  VRelToTrajVar = pt_LAOutput->t_LAObjOutputList[obj_id].TrajDist.TrajDistFilt.P.f11;

  /* Calculate displacement now */
  /* The predicted displacement is the actual position plus the product of gradient and prediction time */
  p_dist = DistanceToTraj + (prediction_time * VRelToTraj);
  p_dist_var = DistanceToTrajVar + (SQR(prediction_time)* fVRelToTrajVarFac * VRelToTrajVar);
  p_dist_var_fullpred = DistanceToTrajVar + (SQR(LA_LaneAssPredTime) * fVRelToTrajVarFac * VRelToTrajVar);

  /*zero crossing?*/
  if((p_dist * DistanceToTraj) < 0.f)
  {
    p_dist = 0.f;
  }
  else
  {
    p_dist = fABS(p_dist);
  }

  /* respect object width !!!! */
  if (object_class == SLATE_OBJCLASS_CAR)
  {
    /* object seems to be a car, so calculate an object width of 1.8m and subtract half of it off calculated distance*/
    p_dist -= LA_PRED_DIST_FOR_ARSOBJ_CAR;
  }
  else if (object_class == SLATE_OBJCLASS_TRUCK)
  {
    p_dist-= LA_PRED_DIST_FOR_ARSOBJ_CAR;/* @todo: FK urspruenglich 1.25, wegen Problemen mit Klassifizierung aber PKW und LKW jetzt gleich,
                  wenn Klassifizierung und Objektbreite plausibel, neu bewerten */
  }
  else
  {
    p_dist-= LA_PRED_DIST_FOR_OBJECT_OTHER_THAN_CAR_OR_TRUCK;
  }

  pred_dist->pdist = p_dist;
  pred_dist->pdist_var = p_dist_var;
  pred_dist->pdist_var_fullpred = p_dist_var_fullpred;
}

/*************************************************************************************************************************
  Functionname:    LA_t_LimitPredictionBySpeed                                                                         */ /*!

  @brief           Limit prediction time by ego speed

  @description     This function limits the prediction time for object ego speeds
                   Reason:
                    In city traffic too big prediction times lead to bad predictions
                    because of bigger side movements of objects.
                   
  @return          limited prediction_time : limited prediction time [0.f ... 100.f] s

  @param[in]       normal_prediction_time : time in s to predicted the displacement in normal case [0.f ... 100.f] s

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY [-330.f ... 330.f] m/s 
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.02.2016
  @changed         26.02.2016

  @todo            Currently not used, check and delete the function

  @author          Fridolin Kolb,  fridolin01.kolb@contiautomotive.com
*************************************************************************************************************************/
/*
static fTime_t LA_t_LimitPredictionBySpeed(fTime_t normal_prediction_time)
{

  fTime_t limited_prediction_time;
  fVelocity_t vehicle_speed;

  vehicle_speed = *pt_LAInput->t_RTE.pf_EgoVelObjSync;

  if (vehicle_speed > LA_MAX_VEHICLE_SPEED_LIMIT_PREDICTION)
  {
    limited_prediction_time = normal_prediction_time;
  }
  else
  {
    limited_prediction_time = LA_CutInPotPredTimeLimited;
  }

  return(limited_prediction_time);
}
*/
/*************************************************************************************************************************
  Functionname:    LA_t_LimitPredictionTimeDist                                                                        */ /*!

  @brief           Limit prediction by time distance to predicted object

  @description     This function limits the prediction time for object ego speeds
                   Reason:
                    In city traffic too big prediction times lead to bad predictions
                    because of bigger side movements of objects.
                   @startuml 
                   partition LA_t_LimitPredictionTimeDist {
                   Start
                    -limits the prediction time for object ego speeds greater than C F32 DELTA
                   End
                   }
                   @enduml

  @return          limited prediction_time : limited prediction time    [0.f ... 100.f] s

  @param[in]       obj_id : Object Number (Object ID)                   [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync : Ego velocity provided by VDY  [-330.f ... 330.f] m/s 
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp  (i) : Longitudinal displacement of an object i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.02.2016
  @changed         26.02.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
fTime_t LA_t_LimitPredictionTimeDist(fVelocity_t vehicle_speed, float32 ObjDisp)
{
  fTime_t limited_prediction_time;

  if (fABS(vehicle_speed)> C_F32_DELTA)
  {
    limited_prediction_time = dGDBmathLineareFunktion(&LACutOutPredTime,( ObjDisp / vehicle_speed) );
  }
  else
  {
    limited_prediction_time = 0.0f;
  }

  return(limited_prediction_time);
}


/*************************************************************************************************************************
  Functionname:    LA_v_CalcPredDisplToCutOut                                                                          */ /*!

  @brief           Calculate predicted displacement to course by standard values
                   defined in la_par.h for cut out cases

  @description    This function calculates the predicted lateral displacement to
                   with standard parameters which are defined in la_par.h.

                   @startuml 
                   partition LA_v_CalcPredDisplToCutOut {
                   Start
                     -Get actual distance to course and the gradient
                     -The predicted displacement is the actual position plus the product of gradient and prediction time
                     if(object is car) then (yes)
                       - calculate an object width of 1.8m and subtract half of it off calculated distance
                    -to do FK originally 1.25, but due to problems with classification, cars and trucks are now the same
                     else
                        -calculate an object width of 0.4 m and subtract half of it off calculated distance
                      endif
                   End
                   }
                   @enduml


  @return          void

  @param[in]       prediction_time : time to calculate the predicted lateral displacement [0 ... 100.f] s
  @param[in]       object_class : Object class                                            [SLATE_t_Obj_CLassification as defined in Rte_Type.h]
  @param[in]       obj_id : Object Number (Object ID)                                     [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in,out]   pred_dist : Pointer to variables of the predicted distance             [LA_t_PredictedDistance as defined in si.h]                      
                      pdist : The predicted lateral displacement to vehicle course        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pdist_var : Variance of the predicted lateral displacement with calculated prediction time        [0 ... SQRT(PI/2*RW_FCT_MAX)] m
                      pdist_var_fullpred :  Variance of the predicted lateral displacement with maximum prediction time [0 ... SQRT(PI/2*RW_FCT_MAX)] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.02.2016
  @changed         26.02.2016
  
  @todo            Remove access functions and use local pointers instead.

  @author          Fridolin Kolb,  fridolin01.kolb@contiautomotive.com
*************************************************************************************************************************/
void LA_v_CalcPredDisplToCutOut(fTime_t prediction_time, SLATE_t_Obj_CLassification object_class, ObjNumber_t obj_id, LA_t_PredictedDistance* pred_dist)
{
  float32 DistanceToTraj;
  float32 DistanceToTrajVar;
  float32 VRelToTraj;
  float32 VRelToTrajVar;
  float32 p_dist_var;
  float32 p_dist_var_fullpred;
  float32 p_dist;
  float32 fVRelToTrajVarFac = LA_VARIANCE_SCALE_FACTOR;

  /* Get actual distance to course and the gradient (Vrel to course) */
  DistanceToTraj = *(LA_pf_ObjToRefDistMeas(obj_id));
  DistanceToTrajVar = *(LA_pf_TrajGetObjToRefDistFiltVar(obj_id));

  VRelToTraj = *(LA_pf_TrajGetObjToRefDistGradFilt(obj_id));
  VRelToTrajVar = *(LA_pf_TrajGetObjToRefVarDistGradFilt(obj_id));

  /* Calculate displacement now */
  /* The predicted displacement is the actual position plus the product of gradient and prediction time */
  p_dist = DistanceToTraj + (prediction_time * VRelToTraj);
  p_dist_var = DistanceToTrajVar + (SQR(prediction_time) * fVRelToTrajVarFac * VRelToTrajVar);
  p_dist_var_fullpred = DistanceToTrajVar + (SQR(LA_CUT_OUT_PRED_MAX) * fVRelToTrajVarFac * VRelToTrajVar);


  p_dist = fABS(p_dist);

  /* respect object width !!!! */
  if (object_class == SLATE_OBJCLASS_CAR)
  {
    /* object seems to be a car, so calculate an object width of 1.8m and subtract half of it off calculated distance*/
    p_dist -= LA_PRED_DIST_FOR_ARSOBJ_CAR;
  }
  else if (object_class == SLATE_OBJCLASS_TRUCK)
  {
    p_dist-= LA_PRED_DIST_FOR_ARSOBJ_TRUCK;/* @todo: FK urspruenglich 1.25, wegen Problemen mit Klassifizierung aber PKW und LKW jetzt gleich,
                  wenn Klassifizierung und Objektbreite plausibel, neu bewerten */
  }
  else
  {
    p_dist-= LA_PRED_DIST_FOR_OBJECT_OTHER_THAN_CAR_OR_TRUCK;
  }

  pred_dist->pdist      = p_dist;
  pred_dist->pdist_var  = p_dist_var;
  pred_dist->pdist_var_fullpred = p_dist_var_fullpred;
}
/** @} end defgroup */
#endif /* (0) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

