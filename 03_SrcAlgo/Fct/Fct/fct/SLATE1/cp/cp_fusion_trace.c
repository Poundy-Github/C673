/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_fusion_trace.c

DESCRIPTION:               Fusion of object trace info into ACC trajectory

AUTHOR:                    Matthias Thomi, Gregor Powarzynski

CREATION DATE:             07.05.2012

VERSION:                   $Revision: 1.38 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_COURSE_PREDICTION)
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup cp_fusion_trace Trace fusion
@ingroup cp_trajectory
@brief         Responsible for computation of object trace data based trajectory. \n\n

@description   The following functionalities are provided by this module:
               - Check if Trace is parallel to Circle with Radius 1/C0.
               - Check if Trace is parallel to Clothoid with Radius 1/C0.
               - Check if trace fusion is possible from situation point of view.
               - Evaluate Quality and Paralellism of all available Traces.
               - Calculate trace samples based on trace trajectory.
               - Evaluate trace trajectory for fusion.
               - Calculate trace trajectory given all trace samples.
               - Calculation of the orthogonal distance of the trajectory hypothesis to the trace samples. 
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
#define CP_MIN_TRACE_LENGTH         20.f
#define CP_MAX_TRACE_MSE            5.0f
#define CP_MAX_TRACE_DIST_HIGH_VAR  130.f


#define CP_MAX_DEVIATION_SAMPLE_TO_HYPO (0.6f)

#define CP_RADIUS_MIN            (20.0f)
#define CP_LAT_ACCEL_MIN_RADIUS  (3.0f)
#define CP_EXTRAPOLATION_THRES   (40.f)

/* Number of parallel tested hypotheses */
#define CP_PSO_NUM_HYPOTHESIS (3u)

/* PSO internal variables */
#define CP_TRACE_PSO_XI       (0.7298f)
#define CP_TRACE_PSO_C1       (2.8f)
#define CP_TRACE_PSO_C2       (1.3f)
#define CP_TRACE_PSO_INIT_FIT (1000.f)
#define CP_TRACE_PSO_CHANGE_RADIUS (500.f)

/* Maximum number of PSO iterations.
  This has an huge effect on complexity, do not use values
  larger than 10 */
#define CP_TRACE_PSO_ITER_MAX (10u)

#define CP_TRACE_RADIUS_MAX            (99999.f)
#define CP_TRACE_CURVATURE_MIN         (1e-5f)

#if (CP_CFG_DISCARD_TRACE_WITH_HIGH_DEVIATION)
/* Thresholds for discard traces above certain deviation w.r.t to ACC trajectory */
#define CP_TRACE_TO_RADIUS_DEVIATION             (1.5f)
#endif /* (CP_CFG_DISCARD_TRACE_WITH_HIGH_DEVIATION) */

/*! @brief  Input parameters to the function for calculation of the orthogonal distance of the trajectory hypothesis to the trace samples. */
#if(FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#define CP_CAL_GLOBAL_BEST_FIT  (1u)
#define CP_CAL_LOCAL_BEST_FIT   (0u) 
#endif

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

static void CP_v_SetValidityOfTraceForFusion(TraceID_t iTrace, uint8 ui_TraceQualityFlag);
static float32 CP_f_CalculateAvgDevTrace(float32 fRadius, boolean b_IndividualTrace);
static boolean CP_b_FusionTraceIsFusionSituation( 
#if (CP_CFG_USE_TRACE_FUSION_LOWER_VEL)
                                                 const CP_t_TraceTrajectory * pTraceTrajectory,
#endif /*CP_CFG_USE_TRACE_FUSION_LOWER_VEL*/
                                                 CP_t_TrajectoryState *pTrajState );
#if (FCT_CFG_ROAD_INPUT)
static CP_t_Trace2CurveParallelism CP_t_FusionTraceCalcTraceClothoidParallelism(uint8 iTr , float32 fC0 , float32 fC1 , const GDBTrafoMatrix2D_t * MOT2CIR);
#endif /* (FCT_CFG_ROAD_INPUT) */
#if (CP_CFG_USE_ACTUAL_TRACE_LENGTH)
static float32 CP_t_CalculateTraceLength(const FIP_MovObjStaticTrace_t * pTrace);
#endif /* (CP_CFG_USE_ACTUAL_TRACE_LENGTH) */

/*************************************************************************************************************************
  Functionname:    CP_t_FusionTraceCalcTraceCircleParallelism                                                               */ /*!

  @brief           Check if Trace is parallel to Circle with Radius 1/C0

  @description     Calc distance mean and standard deviation of distances of trajectory to cicle. For given trace ( using trace id),
                   mean and std deviation of distances from trajectory to cicle is calculated.Big standard deviation means trace is 
                   not parallel to circle

                   @startuml
                   Start
                   Partition CP_t_FusionTraceCalcTraceCircleParallelism() {
                    If(
                       (The reference FCT Object Id with given trace id is Valid) AND
                       (No of points for the given trace > Minimum Trace points)) then (True)
                             Repeat
                                : Calcutalte distance mean and standard deviation
                                  of distances of trajectory to cicle;
                             Repeat while (for all the points of the given trace)
                             : Calulate Variance;
                             If( Variance is greater than zero ) Then (True)
                                : Calculate standard deviation as sqaure root of Variance;
                             Else (False)
                                : Set standard deviation to Zero;
                             Endif
                    Else (False)
                             : Distance mean and standard deviation of distances of trajectory to cicle
                               is set to Invalid;
                    Endif
                    :return the Structure which contains distance and standard deviation of object trace to vdy or road curve ;
                   }
                   End
                   @enduml

  @return          ret : Structure which contains distance and standard deviation of object trace to vdy or road curve 
                      fDistMean : mean distance                    [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                      fDistStdDev : standard deviation of distance [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                      returns DEFAULT on invalid Traces and 
                      if FCT_CFG_OBJECT_TRACE_PREPROCESSSING(iTr) > CP_PARALLELISM_MIN_LENGTH_TRACE


  @param[in]       iTr : Trace ID as defined in Rte_type.h ObjectTraces_t is an array of size 10  [0...10]
  @param[in]       MOT2CIR : Pointer to structure of type CML_t_TrafoMatrix2D defined in cml_mat.h
                             Transformation Matrix to Circle Coordinate System (with Rotation)
  @param[out]      -

  @glob_in         pt_CPOutput->CP_CourseData.fCurve : Curvature (= 1 / Radius)                                                          [-1 … +1] m^-1
  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->uiReferenceToFCTObject : The reference FCT Object Id with given trace id    [0 ... EM_N_OBJECTS-1] 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointX[iS] : The X coordinate of given trace ID                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointY[iS] : The Y coordinate of given trace ID                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/14/2016
  @changed         2/14/2016

  @author          Norman Apel | Norman.Apel@continental-corporation.com | 
*************************************************************************************************************************/
CP_t_Trace2CurveParallelism CP_t_FusionTraceCalcTraceCircleParallelism(uint8 iTr, const GDBTrafoMatrix2D_t * MOT2CIR)
{
  float32 fC0 = pt_CPOutput->CP_CourseData.fCurve;
  CP_t_Trace2CurveParallelism ret;
  CAL_t_TrajRefPoint TrajRefPoint;
  sint8 iS;
  /* Defining local variable to reference pointer in function */
  sint8 i_NumberOfPoints= pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].iNumberOfPoints;

  ret.fDistMean    = 0.0f;
  ret.fDistStdDev  = 0.0f;

  if (
    (pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].uiReferenceToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID) &&
       (i_NumberOfPoints > CP_PARALLELISM_MIN_LENGTH_TRACE)
       )
  {
    float32 fVarianceVal;
    const float32 InvNoPts = (1.f / (float32)i_NumberOfPoints);
    for (iS = 0; iS < i_NumberOfPoints ; iS ++ )
    {
      float32 fX = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointX[iS];
      float32 fY = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointY[iS];
      GDBmathTrafoPos2D( MOT2CIR ,&fX, &fY ); 
      TrajRefPoint = CAL_t_CalculateDistancePoint2Circle(fX, fY, fC0);
      ret.fDistMean   += TrajRefPoint.fDistToTraj;
      ret.fDistStdDev += SQR(TrajRefPoint.fDistToTraj);
    }
    ret.fDistMean  *= InvNoPts;

    fVarianceVal = (ret.fDistStdDev * InvNoPts) - SQR(ret.fDistMean);
    if( fVarianceVal > 0.f )
    {
      ret.fDistStdDev =  SQRT_(fVarianceVal);
    }
    else
    {
      ret.fDistStdDev = 0.f;
    }
  }
  else
  {
    ret.fDistMean    = CP_TRAJ_INVALID_VALUE; /*EOMOT_VALID_OBJ_ID*/
    ret.fDistStdDev  = CP_TRAJ_INVALID_VALUE;
  }
  return ret;
}

#if (FCT_CFG_ROAD_INPUT)
/*************************************************************************************************************************
  Functionname:    CP_t_FusionTraceCalcTraceClothoidParallelism                                                               */ /*!

  @brief           Check if Trace is parallel to Clothoid with Radius 1/C0

  @description     Calc distance mean and standard deviation of distances of trajectory to polynomial appoximation of clothoid. 
                   For given trace ( using trace id),mean and std deviation of distances from trajectory to clothoid is calculated.
                   Big standard deviation means trace is not parallel to clothoid.

                   Polynomial Approximation of clothoid is given by following equation
                   Y_Curve =  1/2 * C0 + X_Curve^2 + 1/6 * C1 * X_Curve^3

                   @startuml
                   Start
                   Partition CP_t_FusionTraceCalcTraceClothoidParallelism() {
                   If(
                       (The reference FCT Object Id is valid) AND
                       (No of points for the given trace > Minimum Trace points)) then (True)
                             Repeat
                                : Calcutalte distance mean and standard deviation
                                  of distances of trajectory to cicle;
                             Repeat while (for all the points of the given trace)
                             : Calulate Variance;
                             If( Variance is greater than zero ) Then (True)
                                : Calculate standard deviation as sqaure root of Variance;
                             Else (False)
                                : Set standard deviation to Zero;
                             Endif
                    Else (False)
                             : Distance mean and standard deviation of distances of trajectory to cicle
                               is set to Invalid;
                    Endif
                    :return the Structure which contains distance and standard deviation of object trace to vdy or road curve;
                   }
                   End
                   @enduml

  @return          ret : Structure which contains distance and standard deviation of object trace to vdy or road curve 
                      fDistMean : mean distance                    [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                      fDistStdDev : standard deviation of distance [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                      returns DEFAULT on invalid Traces and 
                      if FCT_CFG_OBJECT_TRACE_PREPROCESSSING(iTr) > CP_PARALLELISM_MIN_LENGTH_TRACE


  @param[in]       iTr : Trace ID as defined in Rte_type.h ObjectTraces_t is an array of size 10  [0...10]
  @param[in]       fC0 : C0 parameter of polynomial                                               [-1 ... +1] m^-1
  @param[in]       fC1 : C1 parameter of polynomial                                               [-1 ... +1] m^-2
  @param[in]       MOT2CIR : Pointer to structure of type CML_t_TrafoMatrix2D defined in cml_mat.h
                             Transformation Matrix to Circle Coordinate System (with Rotation)
  @param[out]      -

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... CAL_MAX_NB_TRAJ_SAMPLES]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->uiReferenceToFCTObject : The reference FCT Object Id with given trace id    [0 ... EM_N_OBJECTS-1] 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointX[iS] : The X coordinate of given trace ID                       [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTr)->fTracePointY[iS] : The Y coordinate of given trace ID                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/14/2016
  @changed         2/14/2016

  @author          Norman Apel | Norman.Apel@continental-corporation.com | 
*************************************************************************************************************************/
static CP_t_Trace2CurveParallelism CP_t_FusionTraceCalcTraceClothoidParallelism(uint8 iTr , float32 fC0 , float32 fC1 , const GDBTrafoMatrix2D_t * MOT2CIR)
{
  /* Defining local variable to reference pointer in function */
  sint8 i_NumberOfPoints= pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].iNumberOfPoints;

  CP_t_Trace2CurveParallelism ret;
  CAL_t_TrajRefPoint TrajRefPoint;
  sint8 iS;
  
  ret.fDistMean    = 0.0f;
  ret.fDistStdDev  = 0.0f;

  if ( 
    (pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].uiReferenceToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID) &&
    (i_NumberOfPoints > CP_PARALLELISM_MIN_LENGTH_TRACE)
      )
  {
    float32 fVarianceVal;
    const float32 InvNoPts = (1.f / (float32)i_NumberOfPoints);
    for (iS = 0; iS < i_NumberOfPoints ; iS ++ )
    {
      float32 fX = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointX[iS];
      float32 fY = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointY[iS];
      GDBmathTrafoPos2D( MOT2CIR ,&fX, &fY ); 
      TrajRefPoint = CAL_t_CalculateDistancePoint2Clothoid(fX, fY, fC0, fC1);
      ret.fDistMean   += TrajRefPoint.fDistToTraj;
      ret.fDistStdDev += SQR(TrajRefPoint.fDistToTraj);
    }
    ret.fDistMean  *= InvNoPts;

    fVarianceVal = (ret.fDistStdDev * InvNoPts) - SQR(ret.fDistMean);
    if( fVarianceVal > 0.f )
    {
      ret.fDistStdDev = SQRT_(fVarianceVal);
    }
    else
    {
      ret.fDistStdDev = 0.f;
    }
  }  
  else
  {
    ret.fDistMean    = CP_TRAJ_INVALID_VALUE; /*EOMOT_VALID_OBJ_ID*/
    ret.fDistStdDev  = CP_TRAJ_INVALID_VALUE;
  }  
  return ret;
}

#endif /* END IF (FCT_CFG_ROAD_INPUT) */

/*************************************************************************************************************************
  Functionname:    CP_b_FusionTraceIsFusionSituation                                                               */ /*!

  @brief           Check if trace fusion is possible from situation point of view

  @description     Situation is assessed based on ego speed and presence of tunnel, it is established whether trace fusion is possible or not

                   @startuml
                   Start
                   Partition CP_b_FusionTraceIsFusionSituation() {
                    :Calculate minimum and maximum required Ego Speed;
                    If (Ego Longitudinal velocity is lesser than minimum required Ego Speed) Then (True)
                      :Set Bit indicating that ego speed is sufficient for Traces fusion to FALSE;
                    Else (Flase)
                      :Set Bit indicating that ego speed is sufficient for Traces fusion to TRUE;
                    EndIf
                    If ((Bit indicating that ego speed is sufficient for Traces fusion is TRUE) AND
                        (Tunnel Probability is lesser than 0.5f)) Then (True)
                      : Set the flag indicating trace fusion is possible from situation point of view to TRUE;
                    Else (Flase)
                      : Set the flag indicating trace fusion is possible from situation point of view to FALSE;
                    EndIf
                    :return the flag indicating trace fusion is possible from situation point of view or not;
                   }
                   End
                   @enduml

  @return          bRet : Boolean, TRUE if trace fusion is possible from situation point of view, FALSE otherwise   [TRUE,FALSE]

  @param[in,out]   pTrajState : Pointer to ACC trajectory State
                      FusionTraceHystEgoSpeed : Bit indicating that ego speed is sufficient for Traces fusion       [TRUE,FALSE]

  @glob_in         pt_CPInput->t_RTE.pf_EgoLongVel : ego speed [-330.f ... 330.f] m/s
  @glob_in         TUNNEL_PROBABILITY : Tunnel Probability     [0 ... 1]
  @glob_out        -

  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING       : FCT signal performance monitoring as defined in fct_config.h
  @c_switch_part   CP_CFG_ENABLE_TRACE_FUSION_IN_TUNNEL : Configuration switch to enable trace fusion in tunnels as defined in cp_cfg.h
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING  : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION            : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    154:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-154-00061542 \n
                   155:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-155-00061542 \n
  
  @created         2/14/2016
  @changed         2/14/2016

  @author          Norman Apel | Norman.Apel@continental-corporation.com | 
*************************************************************************************************************************/
static boolean CP_b_FusionTraceIsFusionSituation( 
#if (CP_CFG_USE_TRACE_FUSION_LOWER_VEL)
                                                 const CP_t_TraceTrajectory * pTraceTrajectory,
#endif /*CP_CFG_USE_TRACE_FUSION_LOWER_VEL*/
                                                 CP_t_TrajectoryState *pTrajState )
{
  boolean bRet = FALSE;
  float32 f_EgoSpeedMin;
  float32 f_EgoSpeedMax;

#if (CP_CFG_USE_TRACE_FUSION_LOWER_VEL)
   if(pTraceTrajectory->fWeight < 0.4f )
   {
       f_EgoSpeedMin = (CP_FUSIONTRACESPEEDTHRESHCITY - CP_FUSIONTRACESPEEDHYSTOFFSETCITY);
       f_EgoSpeedMax = CP_FUSIONTRACESPEEDTHRESHCITY;
   }
   else
   {
      f_EgoSpeedMin = (CP_FUSIONTRACESPEEDTHRESH - CP_FUSIONTRACESPEEDHYSTOFFSET);
      f_EgoSpeedMax = CP_FUSIONTRACESPEEDTHRESH;
   }
#else
      f_EgoSpeedMin = (CP_FUSIONTRACESPEEDTHRESH - CP_FUSIONTRACESPEEDHYSTOFFSET);
      f_EgoSpeedMax = CP_FUSIONTRACESPEEDTHRESH;
#endif /*CP_CFG_USE_TRACE_FUSION_LOWER_VEL*/

  if(pTrajState->FusionTraceHystEgoSpeed)
  {
    if(*pt_CPInput->t_RTE.pf_EgoLongVel < f_EgoSpeedMin) 
    {
      pTrajState->FusionTraceHystEgoSpeed = FALSE;
    }
  }
  else
  {
    if(*pt_CPInput->t_RTE.pf_EgoLongVel > f_EgoSpeedMax)
    {
      pTrajState->FusionTraceHystEgoSpeed = TRUE;
    }
  }

  /* if speed is over 60(-Hyst) and there is no Tunnel --> TRUE */  
  if (   (pTrajState->FusionTraceHystEgoSpeed) 
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) && (!CP_CFG_ENABLE_TRACE_FUSION_IN_TUNNEL))
    && (*pt_CPInput->t_RTE.pf_TunnelProbability < 0.5f)
#endif
     )
  {
    bRet = TRUE;
  }  
  else
  {
    bRet = FALSE;
  }  
  return bRet;
}

/*************************************************************************************************************************
  Functionname:    CP_v_FusionTracesEvalTraces                                                                         */ /*!

  @brief           Evaluate Traces

  @description     Evaluate Quality and Paralellism of all available Traces

                   @startuml
                   Start
                   Partition CP_v_FusionTracesEvalTraces() {
                     Repeat
                      If((object is not shadow) AND
                         ((object has high quality) OR (low longitudinal distance)) AND
                         (Object Existance Probability is greater than Minimum Threshold) AND
                         (Trace has minimal Length) OR (Trace reached ego vehicle)) Then (True)
                           :Set Trace Quality validity flag to 1;
                      Else (False)
                           :Set Trace Quality validity flag to 0;
                      EndIf
                     :Calculate distance mean and standard deviation of object trace to vdy curve i.e.,
                      Trace and Vdy parallelism;
                     :Set the Trace and Ego validity flag to TRUE, if distance mean of object trace to
                      vdy is within the left and right threshold;
                     If((Trace Quality validity flag is greater than one) AND (Trace and Ego validity
                     flag is TRUE)) Then (True)
                       :Set the bit indicating Trace and Vdy Parallelism;
                     Else
                     EndIf
                     :Calculate distance mean and standard deviation of object trace to road curve i.e.,
                      Trace and road parallelism;
                     :Set the Trace and road validity flag to TRUE, if distance mean of object trace to
                      road is within the left and right threshold;
                     If((Trace Quality validity flag is greater than one) AND (Trace and road
                         validity flag is TRUE)) Then (True)
                       :Set the bit indicating Trace and road Parallelism;
                     Else
                     EndIf
                     :Evaluate each trace if it is suitable for computation of a trace trajectory and
                       store result;
                     Repeat while (for all the 10 traces)
                     :copy trace quality for visualization;
                   }
                   End
                   @enduml

  @return          -

  @param[in,out]   pTrace_Params : Trace Parameters
                      Trace_QualityValid[i] : Array to store if the given trace is valid or not [Full range of data type uint8]
                      Trace_EGOPara[i] : Structure which contains distance and standard deviation of object trace to vdy or road curve 
                         fDistMean : mean distance                                              [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                         fDistStdDev : standard deviation of distance                           [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                      Trace_REPara[i] : Structure which contains distance and standard deviation of object trace to vdy or road curve 
                         fDistMean : mean distance                                              [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
                         fDistStdDev : standard deviation of distance                           [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pf_FCTBumperToCoG : distance from Bumper to Center of Gravity                                                   [Full range of float32  >= 0.F] 
                      t_RTE.pf_SensorYPos : Lateral position of sensor mounting                                                             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      pt_FIPRoad->t_FIPRoadEstimation.fYawAngle : Yaw angle                                                                                       [-PI ... +PI] rad
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->uiReferenceToFCTObject : The reference FCT Object Id with given trace id    [0 ... EM_N_OBJECTS-1]
                      t_RTE.pb_ObjIsShadow(iObj) : Boolean indicating if object is shadow                                                   [TRUE, FALSE]
                      t_RTE.pu_AccObjQuality(iObj) : Get pre-selection quality of given FCT object                                          [Full range of unsigned char]
                      t_RTE.pu_ObjExistProbability(iObj) : Object probability of existence                                                  [0 ... 100] as mentioned in algo_glob.h v1.53
                      t_RTE.pf_ObjLongDisp(iObj) : Get longitudnal displacement of given FCT object                                         [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->Legacy.TraceReachEgoVeh : Boolean variable, Trace reached ego vehicle       [TRUE, FALSE]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... 24] 
                      pt_FIPRoad->t_FIPRoadEstimation.fC0 : C0 parameter of polynomial                                                                            [-1 ... +1] m^1
                      pt_FIPRoad->t_FIPRoadEstimation.fC1 : C1 parameter of polynomial                                                                            [-1 ... +1] m^2
                      pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatus : Road tracking status                                                                     [0 ... 7]
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].QualityValid  : Array to store if the given trace is valid or not        [Full range of data type uint8]
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].EgoValid : Array of Boolean variable if the given trace is within carriageway.Used for circle parallelism    [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].RoadValid : Array of Boolean variable if the given trace is within carriageway.Used for clothoid parallelism [TRUE, FALSE]
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].EgoPara.fDistMean : mean distance                        [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].EgoPara.fDistStdDev : standard deviation                 [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].RoadPara.fDistMean : mean distance                       [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)
  @glob_out        CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].RoadPara.fDistStdDev : standard deviation                [Full range of float32  >= 0.F] Default value CP_TRAJ_INVALID_VALUE (999f)

  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT as defined in fct_config.h
  @c_switch_part   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix as defined in fct_config.h
  @c_switch_part   FCT_SIMU : Enable FCT Simulation as defined in fct_config.h
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    252:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-252-00061542 \n
                   253:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-253-00061542 \n
                   254:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-254-00061542 \n
                   256:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-256-00061542 \n


  @created         -
  @changed         2/27/2016


  @author          Matthias Thomi, Gregor Powarzynski | Matthias.Thomi@continental-corporation.com,Gregor.Powarzynski@continental-corporation.com  | 
*************************************************************************************************************************/
void CP_v_FusionTracesEvalTraces(CP_t_InputSourceParams           * pTrace_Params)
{
  uint8                       iTrace;
  boolean                     Trace_EgoValid[FIP_STATIC_TRACE_NO_OF_TRACES];
#if (FCT_CFG_ROAD_INPUT)
  boolean                     Trace_RoadValid[FIP_STATIC_TRACE_NO_OF_TRACES];
#endif /* END IF (FCT_CFG_ROAD_INPUT) */
  uint8 u_RefToFCTObject;
  boolean b_ObjIsShadow = FALSE, TraceReachEgoVeh = FALSE;
  const uint8 *pu_ObjExistProbability = NULL;
  const float32 *pf_ObjLongDisp = NULL;
  sint8 iNumberOfPoints = 0;
  uint8 u_AccObjQuality;
  
  /*trace transformation to center of gravity without slipangle*/
  GDBTrafoMatrix2D_t          MOT2EGO = GDBGetTrafoMatrixByDisplacement( *pt_CPInput->t_RTE.pf_FCTBumperToCoG, *pt_CPInput->t_RTE.pf_SensorYPos ); // PRQA S 1031 
  /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Allowed in later versions of ISO C99*/
#if (FCT_CFG_ROAD_INPUT)
  /*trace transformation to road aligned coordinate system*/
  GDBTrafoMatrix2D_t          MOT2RE  = GDBGetTrafoMatrixByAngle(-1.0f * (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fYawAngle));// PRQA S 1031 
  /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Allowed in later versions of ISO C99*/
 /* Maximum two lanes normal width considered for VDY and ROAD parallelism check */
  const float32               fLeftThreshold = 2.0f * STRASSENBREITE;
  const float32               fRightThreshold = 2.0f * STRASSENBREITE * -1.0F;

#else
  const float32               fLeftThreshold =  STRASSENBREITE;
  const float32               fRightThreshold = STRASSENBREITE * -1.0F;
#endif

  /*assess Traces */
  for (iTrace=0u;iTrace<FIP_STATIC_TRACE_NO_OF_TRACES;iTrace++)
  {
    /* Defining local variable to reference pointer in function */
    u_RefToFCTObject= pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
#ifdef FCT_SIMU
    pt_CPOutput->CP_TrajectoryData.t_TraceLaneChangeInfo[iTrace].iObjNr   = (ObjNumber_t)u_RefToFCTObject;
#endif
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

    if(u_RefToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID) /*Object alive*/
    {
      b_ObjIsShadow = pt_CPInput->t_RTE.pb_ObjIsShadow((sint8)u_RefToFCTObject);
      u_AccObjQuality = pt_CPInput->t_RTE.pu_AccObjQuality((sint8)u_RefToFCTObject);
      pu_ObjExistProbability = pt_CPInput->t_RTE.pu_ObjExistProbability((sint8)u_RefToFCTObject);
      pf_ObjLongDisp = pt_CPInput->t_RTE.pf_ObjLongDisp((sint8)u_RefToFCTObject);
      TraceReachEgoVeh = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].Legacy.TraceReachEgoVeh;
      iNumberOfPoints = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTrace].iNumberOfPoints;
      pTrace_Params->Trace_QualityValid[iTrace] = ( (!b_ObjIsShadow)
      /* Reject traces of objects with high cluster variance and large longitudinal distance */
      && ((u_AccObjQuality > CP_MIN_ACC_QUALITY) || (*pf_ObjLongDisp < CP_MAX_TRACE_DIST_HIGH_VAR))
      && (*pu_ObjExistProbability > CP_MIN_PEX_FOR_VALID_TRACE)
      && ( (iNumberOfPoints  > CP_PARALLELISM_MIN_LENGTH_TRACE) /*minimal Length of Trace*/
      || (TraceReachEgoVeh)
      )
      )?CP_TRACE_QUAL_MASK_TRACE_VALID:0u;
    } 
    else
    { 
      /* Trace Object dead */
      pTrace_Params->Trace_QualityValid[iTrace] = 0u;
    }


    pTrace_Params->Trace_EGOPara[iTrace]      = CP_t_FusionTraceCalcTraceCircleParallelism( iTrace, &MOT2EGO );
    Trace_EgoValid[iTrace]     =( (pTrace_Params->Trace_EGOPara[iTrace].fDistMean < fLeftThreshold) && /*within carriageway */
      (pTrace_Params->Trace_EGOPara[iTrace].fDistMean > fRightThreshold) /*within carriageway */
      )?TRUE:FALSE;
    if((pTrace_Params->Trace_QualityValid[iTrace] > 0u) && (Trace_EgoValid[iTrace]))
    {
      SET_BIT(pTrace_Params->Trace_QualityValid[iTrace],CP_TRACE_QUAL_MASK_EGO_PARALLEL); /* PRQA S 1861 */ /* Date:2/25/2020, Reviewer: Gireesh, Reason: :The operands of this relational operator are of different essential type categories; one is 'essentially signed' and the other is 'essentially unsigned'. Both essential types are of lower rank than type int but the comparison will be performed in type int because of integral promotion*/
    }

#if (FCT_CFG_ROAD_INPUT)
    pTrace_Params->Trace_REPara[iTrace]       = CP_t_FusionTraceCalcTraceClothoidParallelism( iTrace, (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC0), (pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.fC1), &MOT2RE );
    Trace_RoadValid[iTrace]    =(    (pTrace_Params->Trace_REPara[iTrace].fDistMean < fLeftThreshold) /*within carriageway */
      && (pTrace_Params->Trace_REPara[iTrace].fDistMean > fRightThreshold) /*within carriageway */
      && ((pt_CPInput->pt_FIPRoad->t_FIPRoadEstimation.uiTrackingStatus) >= CP_PARALLELISM_MIN_RE_TRACKING_STAT) /*RE available*/
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__) ") : TODO: Remove RE-Conf-Thresh because this is consideresd in situation criterion")//PRQA S 3116
      /* date: 2015-04-28, reviewer: Gangadhar Badiger, reason: Non QAC related but required.*/
#endif
      /*(MAX(fConfidenceLeft,fConfidenceRight) > PARALLELISM_MIN_RE_CONF)*/ /*RE available*/
      )?TRUE:FALSE;
    if((pTrace_Params->Trace_QualityValid[iTrace] > 0u) && (Trace_RoadValid[iTrace]))
    {
      SET_BIT(pTrace_Params->Trace_QualityValid[iTrace],CP_TRACE_QUAL_MASK_ROAD_PARALLEL); /* PRQA S 1861 */ 
	  /* Date:2/25/2020, Reviewer: Gireesh, Reason: :The operands of this relational operator are of different essential type categories; one is 'essentially signed' and the other is 'essentially unsigned'. Both essential types are of lower rank than type int but the comparison will be performed in type int because of integral promotion*/
    }
#endif

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
    CP_v_DetermineObjectLaneChange(iTrace, &MOT2EGO);
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */

    /* Evaluate each trace if it is suitable for computation of a trace trajectory and store result */
    CP_v_SetValidityOfTraceForFusion(iTrace, pTrace_Params->Trace_QualityValid[iTrace]);
  }
#ifdef FCT_SIMU
    /*copy trace quality for visualization*/
    for (iTrace=0;iTrace<FIP_STATIC_TRACE_NO_OF_TRACES;iTrace++)
    {
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].QualityValid          = pTrace_Params->Trace_QualityValid[iTrace];
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].EgoValid              = Trace_EgoValid[iTrace];
#if (FCT_CFG_ROAD_INPUT)
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].RoadValid             = Trace_RoadValid[iTrace];
#endif /* END IF (FCT_CFG_ROAD_INPUT) */
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].EgoPara.fDistMean     = pTrace_Params->Trace_EGOPara[iTrace].fDistMean;
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].EgoPara.fDistStdDev   = pTrace_Params->Trace_EGOPara[iTrace].fDistStdDev;
#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT))
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].RoadPara.fDistMean    = pTrace_Params->Trace_REPara[iTrace].fDistMean;
      CP_TrajFusionDebugInfo.TraceFusionDebug[iTrace].RoadPara.fDistStdDev  = pTrace_Params->Trace_REPara[iTrace].fDistStdDev;
#endif /* END IF ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (FCT_CFG_ROAD_INPUT)) */
    }
#endif
}

/*************************************************************************************************************************
  Functionname:    CP_v_CalculateTraceSamples                                                                          */ /*!

  @brief           Calculate trace samples based on trace trajectory

  @description     Initialize position samples.
                   Approximate clothoid based on polynomial and sample it.
                   Transform trace samples with respect to sensor cordinate system and limit no
                   of samples to maximum CAL_MAX_NB_TRAJ_SAMPLES as defined in cp_ext.h

                   @startuml
                    Start
                     Partition CP_v_CalculateTraceSamples() {
                        : Initialize trace samples;
                        : Get trace estimation in correct format;
                        : Sample the trace trajectory;
                        if(the max longitudinal distance of the traces is over the threshold) Then (True)
                          : extrapolate till the maximum distance;
                        Else(False)
                           : no extrapolation;
                        endif
                     }
                    End
                   @enduml

  @return          -

  @param[in]       pTraceTrajectory : Trace trajectory, pointer to structure of type CP_t_TraceTrajectory as defined in cp_ext.h
                      fMaxDist : Maximum distance of the object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @param[in,out]   pTRACE_PosSamples : Trace samples based on trace trajectory, pointer to structure of type SLATE_t_PosSamples as defined in slate_types.h
                      nb_samples : Number of trace samples      [0 ... CAL_MAX_NB_TRAJ_SAMPLES]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    152:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-152-00061542 \n
  
  @created         2/12/2016
  @changed         2/12/2016

  @author          Christopher Knievel | Christopher.Knievel@continental-corporation.com | 
*************************************************************************************************************************/
void CP_v_CalculateTraceSamples(const CP_t_TraceTrajectory * pTraceTrajectory, SLATE_t_PosSamples * pTRACE_PosSamples)
{
  CP_t_CourseData TraceCourseData;
  float32 fMaxDistTrace = 0.0f;

  /* Initialize trace samples */
  CP_v_InitPosSamples(pTRACE_PosSamples);

  /* Get trace estimation in correct format */
  TraceCourseData = CP_t_GetTraceEstimationAsCourseData(pTraceTrajectory);
  
  /* Sample the trace trajectory */
  CP_v_SamplePosClothApprox(&TraceCourseData, CPClothApproxType_PolynomialOnly, CP_SAMPLEDIST_MAX, pTRACE_PosSamples, CP_XDIST_FIRST_SAMPLE_ZERO_OFFSET);

  CP_v_MoveSamplesFromCoGToSensor(pTRACE_PosSamples);

  /* If the max distance of the traces is over the threshold -> extrapolate to the maximum distance / if not -> no extrapolation*/
  if(pTraceTrajectory->fMaxDist < CP_EXTRAPOLATION_THRES)
  {
    fMaxDistTrace = pTraceTrajectory->fMaxDist;
  }
  else
  {
    fMaxDistTrace = 200.f;
  }

  CP_v_LimitSamplesXDist(fMaxDistTrace,pTRACE_PosSamples);

  /* Increase the number of samples to a minimum length of MIN_FUSION_TRACE_POS_SAMPLES 
     if the samples were reasonable good so far. */
  /* if(pTraceTrajectory->fMeanSquaredError < 0.1f) 
  {
  pTRACE_PosSamples->nb_samples = MAX(pTRACE_PosSamples->nb_samples,10);
  }*/
  pTRACE_PosSamples->nb_samples = MIN(pTRACE_PosSamples->nb_samples,CAL_MAX_NB_TRAJ_SAMPLES);
}


/*************************************************************************************************************************
  Functionname:    CP_v_FusionEvalTraceSamples                                                                          */ /*!

  @brief           Evaluate trace trajectory for fusion

  @description     Check the plausibility of given trace trajectory by checking its maximum distance and mean squared error.
                   Given the state of trace trajectory, check if trace fusion is possible from situation point of view
                   Update the trajectory data based on result of above two conditions
                   If the above two conditions are true
                      Set the state as fusion, set moving object fusion range to max distance and mean squared error
                   Else
                      Initialize trace trajectory and Remember for the next cycle, that trace fusion was inactive

                   @startuml
                    Start
                     Partition CP_v_FusionEvalTraceSamples() {
                        : Check the plausibility of given trace trajectory by checking its maximum
                          distance and mean squared error;
                        : Given the state of trace trajectory, check if trace fusion is possible from
                          situation point of view;
                        : Update the trajectory data based on result of above two conditions;
                        if(the above two conditions are true) Then (True)
                          : Set the state as fusion, set moving object fusion range to max distance and
                            mean squared error;
                        Else(False)
                           : Initialize trace trajectory and Remember for the next cycle, that trace
                             fusion was inactive;
                        endif
                     }
                    End
                   @enduml

  @return          -

  @param[in]       pTraceTrajectory : Pointer to Trace trajectory of type CP_t_TraceTrajectory as defined in cp_ext.h
                      fMaxDist : maximum distance of the object             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fMeanSquaredError : mean squared error of trace       [0 ... CP_MAX_TRACE_MSE] as defined in cp_fusion_trace.c
                      fWeight : Deviation of trace trajectory from samples  [0 ... 100.f]
  @param[in]       pTRACE_PosSamples : Trace samples based on trace trajectory, pointer to structure of type SLATE_t_PosSamples as defined in slate_types.h
  @param[out]      -

  @glob_in         pt_CPOutput->CP_TrajectoryData.State : Trajectory State
  @glob_out        pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData.State.FusionTraces : Bit indicating that Traces are used for trajectory fusion             [TRUE,FALSE]
                      CP_TrajectoryData.State.EgoCourseOnly : Bit indicating that only ego course used for trajectory (fusion off) [TRUE,FALSE]
                      CP_TrajectoryData.fMovObjFusRange : Moving object Fusion Range                                               [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      CP_TrajectoryData.fMSETrace : Mean Squared Error of Trace                                                    [0...CP_MAX_TRACE_MSE]
                      CP_TrajectoryData.bTraceFusionActiveLastCycle : Whether trace fusion is active or not                        [TRUE,FALSE]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    258:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-258-00061542 \n
                   282:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-282-00061542 \n
  
  @created         2/12/2016
  @changed         2/12/2016

  @author          Christopher Knievel | Christopher.Knievel@continental-corporation.com | 
*************************************************************************************************************************/
void CP_v_FusionEvalTraceSamples(const CP_t_TraceTrajectory * pTraceTrajectory)
{
  boolean bIsGoodTraceTrajectory, bFusTraceSituationCriterion;

  
  if(   (pTraceTrajectory->fMaxDist > CP_MIN_TRACE_LENGTH) 
     && (pTraceTrajectory->fMeanSquaredError < CP_MAX_TRACE_MSE))
  {
    bIsGoodTraceTrajectory = TRUE;
  }
  else
  {
    bIsGoodTraceTrajectory = FALSE;
  }
  
  bFusTraceSituationCriterion = CP_b_FusionTraceIsFusionSituation(
#if(CP_CFG_USE_TRACE_FUSION_LOWER_VEL)
                                                                  pTraceTrajectory,
#endif
                                                                  &pt_CPOutput->CP_TrajectoryData.State ); 

  if(   (bIsGoodTraceTrajectory      != FALSE)
     && (bFusTraceSituationCriterion != FALSE)
     && (pTraceTrajectory->fWeight < CP_MAX_DEVIATION_SAMPLE_TO_HYPO))
  {
    pt_CPOutput->CP_TrajectoryData.State.FusionTraces   = TRUE;
    pt_CPOutput->CP_TrajectoryData.State.EgoCourseOnly  = FALSE;

    /* Set moving objects fusion */
    pt_CPOutput->CP_TrajectoryData.fMovObjFusRange = pTraceTrajectory->fMaxDist;

    /* Set MSE of trace trajectory */
    pt_CPOutput->CP_TrajectoryData.fMSETrace = pTraceTrajectory->fMeanSquaredError;

    /* Remember for the next cycle, that trace fusion was active */
    pt_CPOutput->CP_TrajectoryData.bTraceFusionActiveLastCycle = TRUE;

  }
  else
  {
    /* Remember for the next cycle, that trace fusion was inactive */
    pt_CPOutput->CP_TrajectoryData.bTraceFusionActiveLastCycle = FALSE;
  }
}



#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)

/*************************************************************************************************************************
  Functionname:    CP_v_CalculateCombinedTraceTrajectory                                                               */ /*!

  @brief           Calculate trace trajectory given all trace samples

  @description     Using all trace samples calculate trace trajectory after checking samples validity for fusion.
                   The trajectory is calculated testing various radius-hypotheses. With a given radius, a metric
                   measuring the deviation of the trajectory to the given samples, is calculated and optimized. 
                   The radius with the minimum deviation is chosen.

                   Previously, an exhaustive search to find the optimum radius has been performed which had a 
                   significant impact on the runtime-performance. In order to improve runtime-efficiency as well
                   as memory consumption, a heuristic search algorithm has been implemented, namely particle swarm
                   optimization (PSO). To reduce runtime, i.e. have only a few iterations, good initial radius-hypotheses
                   have to be used.
                   A disadvantage to PSO is that the convergence to the global optimum is not guaranteed (as opposed to the
                   exhaustive search strategy). Hence, it is of importance to stop using the trace trajectory for the
                   ACC trajectory fusion once the deviation between the trajectory fit and the given samples is too large,
                   i.e. pTraceTrajectory->fWeight gets too large.
                   For details of the algorithm, refer to Kennedy, J.; Eberhart, R. (1995). "Particle Swarm Optimization". 
                   Proceedings of IEEE International Conference on Neural Networks. pp. 1942–1948. doi:10.1109/ICNN.1995.488968
                   Optimization is done for the radius not for the curvature, as the optimization metric is better conditioned.

                   If all the three hypothesis are pointing in same direction, then one of the 3 hypothesis is made opposite.
                   Thus the final ACC Trajectory computation should improve during S-Curve where the Curve direction changes from one direction to another.
                   Switch is added to enable this.
				   
				   For traces below 40m we consider actual trace length by calculating distance between the each sample points of the trace
                   and adding them all up and for traces above we are considering the current X position (longitudinal displacement)
                   (enabled using the switch CP_CFG_USE_ACTUAL_TRACE_LENGTH, this will help in preventing drop outs during curve)

                   @startuml
                    Start
                     Partition CP_v_CalculateCombinedTraceTrajectory() {
                       : Init all PSO related variables;
                       : Calculate the min radius for the trace trajectory. The minimum radius is
                         calculated for a given ego-velocity and an assumed maximum lateral acceleration
                         of 3 m/s^2. For more narrow curve radii the lateral acceleration would be beyond
                         ACC specs, thus we can ignore them;
                       : Calculate First hypothesis based on minimum radius based on lateral acceleration;
                       : Calculate Second hypothesis based on VDY trajectory;
                       : Calculate Third hypothesis based on ACC trajectory;
                       : Initialize local best hypotheses with the given hypotheses;
                       : calculate global best radius;
                       : calculate fitness value for global best radius hypothesis;
                       Repeat
                         :Calculate the maximum distance from valid trace;
                         :Calculate the number of valid traces;
                       Repeat while (for all the traces)
                       If (The number of valid traces is greater than zero)then (TRUE)
                        Repeat
                         :Calculate the local best value for the given hypothesis;
                         : if the local best hypothesis is better compared to the global best hypothesis,
                           Then replace global best with local best hypothesis;
                        Repeat while (Number of parallel tested hypotheses)
                        Repeat
                           Repeat
                             :Calculate velocity of each particle and update the radius of hypothesis;
                             :Calculate fitness for the updated hypothesis;
                             : In case the current hypothesis is better than any other hypothesis of this
                               particle, we replace the local best hypothesis;
                             : In case the current hypothesis is better than any other hypothesis of the
                               overall swarm, we replace the global best hypothesis;
                           Repeat while (For Number of PSO iterations)
                        Repeat while (For Number of PSO iterations)
                        : set the weight for the trace trajectory;
                       Else
                       EndIf
                     }
                    End
                   @enduml

  @return          -

  @param[in,out]   pTraceTrajectory : Pointer to Trace trajectory of type CP_t_TraceTrajectory as defined in cp_ext.h
                      fcurve : curve of the trajectory                                          [-1 ... 1]m^-1
                      fMaxDist : maximum distance of the object                                 [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      fMeanSquaredError : mean squared error of trace                           [0 ... CP_MAX_TRACE_MSE] as defined in cp_fusion_trace.c   
                      fWeight : Deviation of trajectory to given samples                        [0 ... 10.f]

  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_RTE.pf_EgoLongVel : Ego speed                                                                                        [-330.f ... 330.f] m/s
                      t_RTE.pf_ObjLongDisp(iObj) : Get longitudnal displacement of given FCT object                                          [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->uiReferenceToFCTObject : No of points for the given trace  as defined in cp_ext.h [0 ... 24]
  @glob_in         pt_CPOutput : Pointer to CP output structure
                      CP_TrajectoryData.LastCycle.fTrajC0 : Trajectory Curvature                                                             [-1 … +1] m^-1
                      CP_CourseData.fCurve : curve of the trajectory                                                                         [-1 ... 1]m^-1
                      CP_TrajectoryData.bTraceFusionActiveLastCycle : Whether trace fusion is active or not                                  [TRUE,FALSE]
  @glob_in         CP_TraceAdd[iTr].bUseTraceForFusion : BooleanFlag to indicate whether the trace is used within the trajectory fusion      [TRUE,FALSE]
  @glob_out        CP_TrajFusionDebugInfo.CombinedTraceTrajectory : Combined Trace trajectory
  @glob_out        CP_TrajFusionDebugInfo.fMSETrace : mean squared error of trace                                                            [0 ... CP_MAX_TRACE_MSE] as defined in cp_fusion_trace.c

  @c_switch_part   FCT_SIMU : Enable FCT simulation as defined in fct_config.h
  @c_switch_part   CP_CFG_USE_ACTUAL_TRACE_LENGTH      : Configuration switch to enable Actual Trace length consideration based on Object Long Displacement
  @c_switch_part   CP_CFG_TRACE_FUSION_OPPO_HYPOTHESIS : Switch for using Opposite Trace Hypothesis if all the three hypothesis are pointing in same direction
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  
  @traceability    259:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-259-00061542 \n
  
  @created         -
  @changed         4/28/2016

  @author          Bjoern Hackel| Bjoern.Hackel@continental-corporation.com | 
                   Christopher Knievel | Christopher.Knievel@continental-corporation.com | +49 (8382) 9699-399                 
*************************************************************************************************************************/
void CP_v_CalculateCombinedTraceTrajectory(CP_t_TraceTrajectory * pTraceTrajectory)
{
#if (CP_CFG_TRACE_TRAJ_LOWPASS_FILTER)
  /*low-pass filter variables*/
  const  float32 fAlpha      = 0.3f;
#endif
  float32 fTraceCurve = pTraceTrajectory->fCurve;
  /*trace trajectory variables*/
  uint32  iTr, iIter;
  uint32  uNumUsedTraces = 0u;
  
  float32 fRadiusMin,f_aDist;
  float32 fMaxDistTrace = 0.f;
  float32 f_XPos = 0.f;
  float32 f_ObjDisp = 0.f;
  
  /* local variables required for PSO hypothesis testing */
  float32 f_radius_hyp[CP_PSO_NUM_HYPOTHESIS];
  float32 f_local_best_rad[CP_PSO_NUM_HYPOTHESIS];
  float32 f_local_best_fit[CP_PSO_NUM_HYPOTHESIS];
  float32 f_vel_hyp[CP_PSO_NUM_HYPOTHESIS];

  float32 f_global_best_rad;
  float32 f_global_best_fit;
  
  float32 f_ABS_TraceCurve;		/* For calculating ABS value */
  float32 f_Abs_TrajC0;		/* For calculating ABS value */
  float32 f_Abs_globalbestrad;		/* For calculating ABS value */
  float32 f_ABS_Curve = fABS(pt_CPOutput->CP_CourseData.fCurve);		/* For calculating ABS value */
  
  /* Init all PSO related variables */
  /* Calculate the min radius for the trace trajectory. The minimum radius is calculated
     for a given ego-velocity and an assumed maximum lateral acceleration of 3 m/s^2. 
     For more narrow curve radii the lateral acceleration would be beyond ACC specs, thus we
     can ignore them. */
  fRadiusMin = MAX_FLOAT(SQR(*pt_CPInput->t_RTE.pf_EgoLongVel)/CP_LAT_ACCEL_MIN_RADIUS, CP_RADIUS_MIN);

  /* First hypothesis based on minimum radius based on lateral acceleration */
  f_radius_hyp[0u] = (float32)CML_f_Sign(pt_CPOutput->CP_TrajectoryData.LastCycle.fTrajC0) * fRadiusMin;
  
  /* Second hypothesis based on VDY trajectory */
  if(f_ABS_Curve > CP_TRACE_CURVATURE_MIN)
  {
    f_radius_hyp[1u] = (1.f/pt_CPOutput->CP_CourseData.fCurve);
  }
  else
  {
    f_radius_hyp[1u] = CP_TRACE_RADIUS_MAX;
  }
    
  /* Third hypothesis based on ACC trajectory */
  f_Abs_TrajC0 = fABS(pt_CPOutput->CP_TrajectoryData.LastCycle.fTrajC0);
  if(f_Abs_TrajC0 > CP_TRACE_CURVATURE_MIN)
  {
    f_radius_hyp[2u] = (1.f/pt_CPOutput->CP_TrajectoryData.LastCycle.fTrajC0);
  }
  else
  {
    f_radius_hyp[2u] = CP_TRACE_RADIUS_MAX;
  }

#if (CP_CFG_TRACE_FUSION_OPPO_HYPOTHESIS)
  if(  ((f_radius_hyp[0u] > 0.f) && (f_radius_hyp[1u] > 0.f) && (f_radius_hyp[2u] > 0.f))
    || ((f_radius_hyp[0u] < 0.f) && (f_radius_hyp[1u] < 0.f) && (f_radius_hyp[2u] < 0.f))  )
  {
    f_radius_hyp[2u] = -f_radius_hyp[2u];
  }
#endif
  
  /* Initialize local best hypotheses with the given hypotheses */
  for (iTr = 0u; iTr<CP_PSO_NUM_HYPOTHESIS; iTr++)
  {
    f_local_best_rad[iTr] = f_radius_hyp[iTr];
    f_local_best_fit[iTr] = CP_TRACE_PSO_INIT_FIT;
    f_vel_hyp[iTr] = 10.f;
  }

  f_ABS_TraceCurve = fABS(fTraceCurve);
  /* Use as a global best starting position, radius of previously calculated trace trajectory  */  
  if(   (pt_CPOutput->CP_TrajectoryData.bTraceFusionActiveLastCycle != FALSE)
     && (f_ABS_TraceCurve > CP_TRACE_CURVATURE_MIN))
  {
      f_global_best_rad = 1.f/fTraceCurve;    
  }
  else if(f_Abs_TrajC0 > CP_TRACE_CURVATURE_MIN)
  {
    f_global_best_rad = 1.f/pt_CPOutput->CP_TrajectoryData.LastCycle.fTrajC0;
  }
  else
  {
    f_global_best_rad = CP_TRACE_RADIUS_MAX;
  }
   /* calculate fitness value for global best radius hypothesis */
  f_global_best_fit = CP_f_CalculateAvgDevTrace(f_global_best_rad, CP_CAL_GLOBAL_BEST_FIT);

  /*go through all traces*/
  for (iTr=0u; iTr<TRACE_NO_OF_TRACES; iTr++)
  {
    if(CP_TraceAdd[iTr].bUseTraceForFusion != FALSE)
    {
      /* Get the current X-position of the object */
      f_ObjDisp = *pt_CPInput->t_RTE.pf_ObjLongDisp((sint8)(pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[(TraceID_t)iTr].uiReferenceToFCTObject));

#if (CP_CFG_USE_ACTUAL_TRACE_LENGTH)
      if (f_ObjDisp < CP_EXTRAPOLATION_THRES)
      {
        /* save the max distance from valid trace from actual trace length*/
        f_XPos  = CP_t_CalculateTraceLength(&(pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr]));
      }
      else
#endif /* (CP_CFG_USE_ACTUAL_TRACE_LENGTH) */
      {
        /* save the max distance from valid trace from current X-position*/
        f_XPos = f_ObjDisp;
      }

      if(f_XPos > fMaxDistTrace)
      {
        fMaxDistTrace = f_XPos;
      }

      uNumUsedTraces++;
    }
  }

  if(uNumUsedTraces > 0u)
  {
    /* find best initial hypothesis */
    for (iTr = 0u; iTr < CP_PSO_NUM_HYPOTHESIS; iTr++)
    {
      f_local_best_fit[iTr] = CP_f_CalculateAvgDevTrace(f_radius_hyp[iTr], CP_CAL_LOCAL_BEST_FIT);

      /* if the local best hypothesis is better compared to the global best hypothesis, then 
         replace global best with local best hypothesis */
      if(f_local_best_fit[iTr] < f_global_best_fit)
      {
        f_global_best_fit = f_local_best_fit[iTr];
        f_global_best_rad = f_radius_hyp[iTr];
      }

      f_radius_hyp[iTr] += (-1.f*CML_f_Mod((float32)iTr+1.f,2.f)) * CP_TRACE_PSO_CHANGE_RADIUS;
    }
    
    for (iIter = 0u; iIter < CP_TRACE_PSO_ITER_MAX; iIter++)
    {
      for(iTr=0u; iTr < CP_PSO_NUM_HYPOTHESIS; iTr++)
      {
        /* Compared to conventional PSO no random numbers are used. Although this is not optimum, the good initial hypothesis
           can compensate the disadvantage */
        /* For details, refer to van den Bergh, F. (2001). An Analysis of Particle Swarm Optimizers (PhD thesis). University of Pretoria, 
           Faculty of Natural and Agricultural Science. */
        f_vel_hyp[iTr] = CP_TRACE_PSO_XI * (f_vel_hyp[iTr] + (CP_TRACE_PSO_C1 * (f_local_best_rad[iTr] - f_radius_hyp[iTr])) +
                                                             (CP_TRACE_PSO_C2 * (f_global_best_rad - f_radius_hyp[iTr])));
        f_radius_hyp[iTr] += f_vel_hyp[iTr];

        f_aDist = CP_f_CalculateAvgDevTrace(f_radius_hyp[iTr], CP_CAL_LOCAL_BEST_FIT);
        /* In case the current hypothesis is better than any other hypothesis of this particle, we replace
           the local best hypothesis */
        if(f_aDist < f_local_best_fit[iTr])
        {
          f_local_best_fit[iTr] = f_aDist;
          f_local_best_rad[iTr] = f_radius_hyp[iTr];
        }

        /* In case the current hypothesis is better than any other hypothesis of the overall swarm, we replace
           the global best hypothesis */
        if(f_aDist < f_global_best_fit)
        {
          f_global_best_fit = f_aDist;
          f_global_best_rad = f_radius_hyp[iTr];
        }

      }
    }
    f_Abs_globalbestrad = fABS(f_global_best_rad);
    if(f_Abs_globalbestrad > CML_f_Delta)
    {
      pTraceTrajectory->fCurve = (1.f/f_global_best_rad);
    }
    else
    {
      pTraceTrajectory->fCurve = 0.f;
    } 

    /*set the weight for the trace trajectory*/
    pTraceTrajectory->fMeanSquaredError     = 1.f;
    pTraceTrajectory->fWeight               = f_global_best_fit;
    pTraceTrajectory->fMaxDist              = fMaxDistTrace;
  }
  else
  {
    pTraceTrajectory->fCurve                = 0.f;
    pTraceTrajectory->fMaxDist              = 0.f;
    pTraceTrajectory->fMeanSquaredError     = CP_TRAJ_INVALID_VALUE;
    pTraceTrajectory->fWeight               = f_global_best_fit;
  }
#if (CP_CFG_TRACE_TRAJ_LOWPASS_FILTER)
  /* Apply low-pass filter for trace trajectory */
  if(pt_CPOutput->CP_TrajectoryData.bTraceFusionActiveLastCycle != FALSE)
  {
    pTraceTrajectory->fCurve = ((1.0f - fAlpha) * fTraceCurve) + (fAlpha * pTraceTrajectory->fCurve);
  }
#endif
}// PRQA S 7004
/* date: 2015-12-16, reviewer: Christopher Knievel, reason: Not safety critical */
#endif



/*************************************************************************************************************************
  Functionname:    CP_f_CalculateAvgDevTrace                                                                           */ /*!

  @brief           Calculation of the orthogonal distance of the trajectory hypothesis to the trace samples.

  @description     Calculation of the orthogonal distance of the trajectory hypothesis to the trace samples. On the basis
                   of the given radius, a trace trajectory is generated with a circular equation (instead of clothoid). The
                   orthogonal distance of the trace trajectory is then computed to each trace sample. The radius
                   hypothesis with the best fit generates the smallest deviation.
                   With the current implementation, only a trace trajectory with a minimum fit of CP_MAX_DEVIATION_SAMPLE_TO_HYPO
                   is used for the fusion with the ACC trajectory.

                   @startuml
                    Start
                     Partition CP_f_CalculateAvgDevTrace() {
                       : Check for the number of Traces used for fusion;
                       : if the traces used are more than 5 in number then maximum 2 traces can be
                         decarded which are crossing the deviation threshold with respect to ACC
                         trajectory;
                       Repeat
                         If(Trace is used for fusion) Then (True)
                            Repeat
                              : calculate the orthogonal distance between trajectory and sample point;
                              If (first trace sample) then (True)
                                : save current orthogonal distance to calculate deviation with next
                                  Sample;
                              Else
                              : Calculate the orthogonal distance deviation between current and previous
                                sample;
                              EndIf
                            Repeat while (for all point of a given traces)
                            If(configuration switch to discard traces which have high deviation w.r.t ACC
                               trajectory is ON) Then (True)
                                If((Individual Trace is True) AND (Number of Used Traces is greater than 1)) Then (True)
                                   : calculate the average of the distance deviation;
                                Else (False)
                                   : Set the average of the distance deviation to 0.0;
                                EndIf
                                : if the average deviation distance threshold is crossed for a
                                  particular trace then it eliminated for the calculation of global best
                                  fit;
                                : calculate the average of the distance deviation;
                            EndIf
                         EndIf
                       Repeat while (for all the traces)
                       :return Deviation of the trajectory based on the radius hypotheses to the given trace samples;
                     }
                    End
                   @enduml

  @return          f_Curve2TraceDev : Deviation of the trajectory based on the radius hypotheses to the given trace samples                 [0 ... 1000]

  @param[in]       fRadius : Radius hypothesis used for the calculation of the optimization metric                                          [-99999.f ... 99999.f]m
  @param[in]       b_IndividualTrace : individual trace is a boolean use to decide whether to calculate average of distance deviation considering all traces at once or by taking the traces individually.
  @param[out]      -   
  
  @glob_in         CP_TraceAdd[iTr].bUseTraceForFusion : BooleanFlag to indicate whether the trace is used within the trajectory fusion     [TRUE,FALSE]


  @glob_in         pt_CPInput : Pointer to CP input structure
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->uiReferenceToFCTObject : The reference FCT Object Id with given trace id         [0 ... EM_N_OBJECTS-1s]
                      t_FIPMOT.pt_FIPMovObjStaticTrace(iTrace)->iNumberOfPoints : No of points for the given trace  as defined in cp_ext.h  [0 ... 24]
                      t_RTE.pf_ObjLongDisp(i) : Longitudinal distance of given object i                                                     [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      t_RTE.pf_ObjLatDisp(i) : Lateral distance of object i                                                                 [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointX[iS] : The X coordinate of given trace ID                            [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                      t_FIPMOT.pt_FIPMovObjStaticTrace(i)->fTracePointY[iS] : The Y coordinate of given trace ID                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m      
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         26.04.2016
  @changed         26.04.2016

  @author          Christopher Knievel | christopher.knievel@continental-corporation.com | +49 (8382) 9699-399
*************************************************************************************************************************/
static float32 CP_f_CalculateAvgDevTrace(float32 fRadius, boolean b_IndividualTrace)
{
  uint8 iTr;
  sint8 iSamplesAll = 0;
  sint16  iS;
  uint8 u_RefToFCTObject;
  float32 f_aDist=0.f, f_aDistPrev=0.f ;
  float32 f_Curve2TraceDev = 0.f;
  float32 f_xPos, f_yPos, f_SqrtxPosyPos;

#if (CP_CFG_DISCARD_TRACE_WITH_HIGH_DEVIATION)
  uint8 u_NumberOfDiscardedTraces = 1u, uNumUsedTraces = 0u;
  float32 f_Curve2TraceDevPrev = 0.f;
  float32 f_Curve2TraceDevTemp = 0.f;

  /*go through all traces*/
  if(b_IndividualTrace)
  {
    for (iTr=0u; iTr<TRACE_NO_OF_TRACES; iTr++)
    {
      if(CP_TraceAdd[iTr].bUseTraceForFusion != FALSE)
      {
        uNumUsedTraces++;
      }
    }
    /* if the traces used are more than 5 in number then maximum 2 traces can be decarded which are crossing the deviation threshold with respect to ACC trajectory */
    if(uNumUsedTraces > 5u)
    {
      u_NumberOfDiscardedTraces = 2u;
    }
    else
    {
      /* Dummy else loop for fixing QAC */
    }
  }
#else
  _PARAM_UNUSED(b_IndividualTrace);
#endif
  
  for (iTr=0u; iTr<FIP_STATIC_TRACE_NO_OF_TRACES; iTr++)
  {
    /* Defining local variable to reference pointer in function */
                  u_RefToFCTObject= pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].uiReferenceToFCTObject;

    if (CP_TraceAdd[iTr].bUseTraceForFusion!=FALSE)
    {
                    for (iS = -1; iS < pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].iNumberOfPoints; iS ++)
      {
        if(iS == -1)/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        {
          /*take the object position as first trace sample*/
          f_xPos  = *pt_CPInput->t_RTE.pf_ObjLongDisp((sint8)u_RefToFCTObject); 
          f_yPos  = *pt_CPInput->t_RTE.pf_ObjLatDisp((sint8)u_RefToFCTObject);
        }
        else/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        {
          /*copy the trace samples into the sample structure*/
          f_xPos  = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointX[iS];
          f_yPos  = pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].fTracePointY[iS];
        }

        /*calculate the orthogonal distance between trajectory and sample point*/
        f_SqrtxPosyPos = SQRT(SQR(f_xPos)+SQR(fRadius-f_yPos));/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        if(f_SqrtxPosyPos > CML_f_AlmostZero)/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        {
          f_aDist = fRadius-((float32)CML_f_Sign(fRadius)*(SQRT(SQR(f_xPos)+SQR(fRadius-f_yPos))));
        }
        else/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        {
          f_aDist = 0.f;
        }
        

        if(iS == -1)/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        {
          /* save current orthogonal distance to calculate deviation with next sample */
          f_aDistPrev = f_aDist;
        }
        else/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
        {
          /* Calculate the orthogonal distance deviation between current and previous sample */
          f_Curve2TraceDev += fABS(f_aDist - f_aDistPrev);
          /* Save current sample as previous sample for the next iteration */
          f_aDistPrev = f_aDist;

          iSamplesAll++;
        }
      }
#if (CP_CFG_DISCARD_TRACE_WITH_HIGH_DEVIATION)
      if((b_IndividualTrace) && (uNumUsedTraces > 1u))
      {
        if(pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].iNumberOfPoints > 0)
        {
          /*calculate the average of the distance deviation*/
          f_Curve2TraceDevTemp = (f_Curve2TraceDev - f_Curve2TraceDevPrev) / (float32)pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].iNumberOfPoints;
        }
        else
        {
          f_Curve2TraceDevTemp = 0.0f;
        }
        /* if the average deviation distance thereshold is crossed for a particular trace then it eliminated for the calculation of global best fit*/
        if ((fABS(f_Curve2TraceDevTemp) > CP_TRACE_TO_RADIUS_DEVIATION) && (u_NumberOfDiscardedTraces > 0u))
        {
          f_Curve2TraceDev = f_Curve2TraceDevPrev;
          iSamplesAll -= pt_CPInput->pt_FIPMOT->t_MovObjStaticTrace[iTr].iNumberOfPoints;
          CP_TraceAdd[iTr].bUseTraceForFusion = FALSE;
          u_NumberOfDiscardedTraces -= 1u;
        }
        else
        {
          /* Dummy else loop for fixing QAC */
        }
        /* Store the previous orthogonal distance */
        f_Curve2TraceDevPrev = f_Curve2TraceDev;
      }          
      else
      {
        /* Dummy else loop for fixing QAC */
      }
#endif
    }
  }
  if(iSamplesAll > 0)
  {
    /*calculate the average of the distance deviation*/
    f_Curve2TraceDev = f_Curve2TraceDev / (float32)iSamplesAll;
  }

  return f_Curve2TraceDev;
}

/*************************************************************************************************************************
  Functionname:    CP_v_SetValidityOfTraceForFusion                                                                  */ /*!

  @brief           Evaluate each trace if it is suitable for trace trajectory

  @description     Evaluate the suitability of trace by checking if it's object number is positive and no of trace points 
                   which we have already seen is positive, quality flag is set and its lateral acceleration is plausible.

                   @startuml
                    Start
                     Partition CP_v_SetValidityOfTraceForFusion() {
                      If(object is valid AND quality flag is valid AND
                         lateral acceleration is plausible) Then (True)
                          : trace is suitable for fusion;
                      Else
                          : trace is not suitable for fusion;
                      EndIf
                     }
                    End
                   @enduml

  @return          -

  @param[in]       iTrace : TraceID  as defined in Rte_SWCEmAdapt_Type.h        [0 ... MAX_NUM_TRACES]
  @param[in]       ui_TraceQualityFlag : Qualifier for each trace               [Full Range of data type uint8]

  @glob_in         CP_TraceAdd : Structure of type CP_t_TraceAddData used to store trace additional data as defined in cp.h
                      iObjNr : Object number of the trace (Object ID)                                                        [0 ... EM_N_OBJECTS-1] 
                      ApproxPoly.fC2 : Coefficient of second-order term                                                      [-1f...+1f]
                      bUseTraceForFusion : BooleanFlag to indicate whether the trace is used within the trajectory fusion    [TRUE,FALSE]
  @glob_in         pt_CPInput->t_RTE.pf_EgoLongVel : Ego speed                                                               [-330.f ... 330.f] m/s 


  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         2/12/2016
  @changed         2/12/2016

  @todo            Remove this entire line if not needed

  @author          Christopher Knievel | Christopher.Knievel@continental-corporation.com | 
*************************************************************************************************************************/
static void CP_v_SetValidityOfTraceForFusion(TraceID_t iTrace, uint8 ui_TraceQualityFlag)
{
  boolean b_UseTraceForFusion = FALSE;

  if ( (CP_TraceAdd[iTrace].iObjNr != -1) &&
       (ui_TraceQualityFlag > 1u) && 
       ( (2.0f * CP_TraceAdd[iTrace].ApproxPoly.fC2 * SQR(*pt_CPInput->t_RTE.pf_EgoLongVel)) < CP_TRACE_MAX_PLAUSIBLE_LAT_ACCEL ) ) /* check if we can follow the trace with ay */
  {
    b_UseTraceForFusion = TRUE;
  }

    CP_TraceAdd[iTrace].bUseTraceForFusion =  b_UseTraceForFusion;
}

#if (CP_CFG_USE_ACTUAL_TRACE_LENGTH)
/*************************************************************************************************************************
  Functionname:    CP_t_CalculateTraceLength                                                                           */ /*!

  @brief           Calculate trace length

  @description     Calculates the length of trace including it's object head (if available) 
                    based on the distance between the each sample points of the trace

                   @startuml
                    Start
                     Partition CP_t_CalculateTraceLength() {
                       : Initialize Trace length to zero;
                       If(Number Of Points is greater than 0) Then (True)
                         : Determine which head of trace to use;
                         If(Traced object is available) Then (True)
                           : use it as first point;
                         Else
                           : use trace points only;
                         EndIf
                         : Calculate length of trace based on the distance between the each sample points
                           of the trace;
                       EndIf
                       : return length of trace;
                     }
                    End
                   @enduml

  @return          fLength : Length of the trace [0.f ... 5*RW_FCT_MAX] m 

  @param[in]       pTrace : Pointer to the trace
                      fTracePointX[i] : X-Position of trace point i   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m  with i in [0u ... FIP_STATIC_TRACE_NO_OF_POINTS]
                      fTracePointY[i] : Y-Position of trace point i   [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]m  i in [0u ... FIP_STATIC_TRACE_NO_OF_POINTS]
                      uiReferenceToFCTObject : FCT ID of trace object [0u ... EM_N_OBJECTS-1]
                      iNumberOfPoints : Number of sample point        [0u ... FIP_STATIC_TRACE_NO_OF_POINTS]

  @glob_in         *pt_CPInput->t_RTE.pf_ObjLongDisp(i) : Longitudinal displacement of an object i  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m 
                    with i in [0u ... EM_N_OBJECTS-1]
  @glob_in         *pt_CPInput->t_RTE.pf_ObjLatDisp(i) : Lateral displacement of an object i        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m 
                    with i in [0u ... EM_N_OBJECTS-1]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   CP_CFG_USE_ACTUAL_TRACE_LENGTH      : Configuration switch to enable Actual Trace length consideration based on Object Long Displacement
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : Configuration switch for using Traces in FCT, irrespective of where they are computed
  @c_switch_full   FCT_CFG_COURSE_PREDICTION           : FCT support for CP sub-component as defined in fct_config.h


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.04.2016
  @changed         21.01.2020 (Rahul Raj)

  @author          Gergely Ungvary
*************************************************************************************************************************/
static float32 CP_t_CalculateTraceLength(const FIP_MovObjStaticTrace_t * pTrace)
{
  float32 fLength;

  /* Initialize returned length to zero */
  fLength = 0.f;

  /* At minimum we always need at least two points */
  if (pTrace->iNumberOfPoints > (sint8)0)
  {
    sint8 iRemainPts;
    float32 fPrevX, fPrevY;
    const float32 * pfSamplesX, *pfSamplesY;

    /* Determine which head of trace to use */
    if (pTrace->uiReferenceToFCTObject < (uint8)EM_N_OBJECTS)
    {
      /* Traced object available, use it as first point */
      pfSamplesX = pTrace->fTracePointX;
      pfSamplesY = pTrace->fTracePointY;
      fPrevX = *pt_CPInput->t_RTE.pf_ObjLongDisp((sint8)pTrace->uiReferenceToFCTObject);
      fPrevY = *pt_CPInput->t_RTE.pf_ObjLatDisp((sint8)pTrace->uiReferenceToFCTObject);
      iRemainPts = pTrace->iNumberOfPoints;
    }
    else
    {
      /* Traced object not available, use trace points only */
      pfSamplesX = pTrace->fTracePointX;
      pfSamplesY = pTrace->fTracePointY;
      fPrevX = *pfSamplesX;
      pfSamplesX++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      fPrevY = *pfSamplesY;
      pfSamplesY++;// PRQA S 0489
     /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      iRemainPts = (pTrace->iNumberOfPoints-1);
    }

    /* While we have entries left to fill, keep going */
    while (iRemainPts > (sint8)0)
    {
      const float32 fDeltaX = (*pfSamplesX - fPrevX);
      const float32 fDeltaY = (*pfSamplesY - fPrevY);
      fLength += SQRT_(SQR(fDeltaX) + SQR(fDeltaY));
      /* Advance X and Y pointers */
      fPrevX = *pfSamplesX;
      pfSamplesX++;// PRQA S 0489
    /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      fPrevY = *pfSamplesY;
      pfSamplesY++;// PRQA S 0489
    /* date: 2015-04-27, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
      /* Decrease remaining number of points */
      iRemainPts--;
    }
  }
  return fLength;
}
#endif /* (CP_CFG_USE_ACTUAL_TRACE_LENGTH) */
/** @} end defgroup */
#endif /* FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
#endif /* FCT_CFG_COURSE_PREDICTION */
