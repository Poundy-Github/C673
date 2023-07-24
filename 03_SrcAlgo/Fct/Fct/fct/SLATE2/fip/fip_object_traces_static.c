/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_object_traces_static.c

DESCRIPTION:               Functions for computing and working with static traces

AUTHOR:                    Harsha Umesh Babu (uidj3583)

CREATION DATE:             02.06.2016

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip_object_traces.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) 

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_object_traces_static FIP Static Traces
@ingroup fip_object_traces
@brief          Main file for Processing the Static traces of objects. \n\n

@{

*/
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/* CRITERIA FOR TRACE CREATION */
/*! minimum lifetime cycles of obj. */
#define FIP_MOST_LIFETIME_MIN              (7U) // CONV_CYCLES_TO_LIFETIME(x) -> x
/*! minimum probability of existence */
#define FIP_MOST_PROB_EXIST_MIN            (99)
/*! minimum obstacle probability */
#define FIP_MOST_OBST_PROB_MIN             ((percentage_t)85) 
/*! maximum Y intersection gradient */
#define FIP_MOST_VALID_MAXYISGRAD    (0.03f)
/*! maximum Y intersection delta in mm */
#define FIP_MOST_VALID_YISDELTA      (0.75f)
/*! Angle between Trace segment and X-axis in degree*/
#define FIP_MOST_VALID_ANGLEVAR      (25.0f)
/*!Max Angle between Trace segment and X-axis in degree*/
#define FIP_MOST_VALID_MAXANGLE       (8.5f)
/*!Max variance of trace segment to curve*/
#define FIP_MOST_VALID_MAXVAR2CURVE   (0.5f)

/*! length [m] for trace deletion when trace conditions are not fulfilled */
#define FIP_MOST_DEL_LENGTH                 (25.0f)
/*! smart tracing disable flag: optimizations for straight lines using fewer points */
#define FIP_MOST_DISABLE_SMART_SAMPLING       (SWITCH_ON)

#if (!FIP_MOST_DISABLE_SMART_SAMPLING)
/*! maximum length for straight lines */
#define FIP_MOST_MAX_STRAIGHT_LINE_LENGTH   ( 70.0f)
#endif
/*Minimum value of absolute Y intersection gradient filter*/
#define FIP_MOST_MIN_ABS_YINTERSEC_GRAD_FILTR (0.003f)
/*maximum value of Y intersection delta value*/
#define FIP_MOST_MAX_YINTERSEC_DELTA (0.5f)
/*! length [m] for trace deletion when object is deleted */
#define FIP_MOST_DEAD_DEL_LENGTH          (40.0f)
/*! time   [s] for trace deletion when object is deleted */
#define FIP_MOST_DEAD_DEL_TIME            (5.0f)
/*Min points in trace for updating length */
#define FCT_STATIC_TRACE_TWO_POINTS            (2)

/*! cycles for trace deletion when trace conditions are not fulfilled */
#define FIP_MOST_DEL_QUALITY_HYST_CYCLES   ((sint8)15)
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

/*****************************************************************************
LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
GLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
LOCAL VARIABLES
*****************************************************************************/
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*! list of Moving Object Traces used for local computations */
SET_MEMSEC_VAR(FIP_a_MOSTrace)
static FIP_t_MovingObjStaticTraceData  FIP_a_MOSTrace[FIP_STATIC_TRACE_NO_OF_TRACES];
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

/*****************************************************************************
FUNCTION PROTOTYPES
*****************************************************************************/
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/* Checks for dead traces*/
static void FIP_v_CheckDeadStaticTrace(void);
/* Checking general conditions for traces creation*/
static void FIP_v_CheckGeneralConditionsStatic(void);
/* Checking conditions for traces creation*/
static void FIP_v_CheckStaticTraceConditions(void);
/* trace sampling once trace created*/
static void FIP_v_MOSTSampling(void);
/* Compensating ego vehicle motion */
static void FIP_v_MOSTEgoMotionCompensation(void);
/* Function to analyze the quality for the created traces, those who fulfilled the trace conditions*/
static void FIP_v_MOSTQualityAnalyse(void);
/*start trace deletion when object is deleted, trace is NOT deleted !! */
static void FIP_v_StartObjectStaticTraceDeletion(ObjNumber_t iObj );
/* Create the traces for the object those who fulfilled the trace conditions*/
static void FIP_v_StaticTraceCreation(ObjNumber_t iObj);
/* if the trace conditions for the object not fulfilled, delete the trace*/
static void FIP_v_CheckStaticTraceDeletion(ObjNumber_t iObj);
/* if the trace does not have any object in it(called dead trace), delete that trace */
static void FIP_v_CheckDeadStaticTraceDeletion(TraceID_t iTrace); 
/* to compensate the trace points */
static void FIP_v_MOSTCompensatePoints(TraceID_t iTrc);
/* if the trace is growing more than 25 points, crop the trace */
static void FIP_v_CropStaticTrace(TraceID_t iTrace);
/* to get Y axis intersection for the trace */
static boolean FIP_b_GetStaticTraceYAxisIntersection(TraceID_t iTrace, float32 *pfY , float32 *pfYVar); 
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

/* Initialize the trace parameters,those who fulfilled the trace conditions*/
static void FIP_v_InitMovingObjectStaticTraces ( TraceID_t iTrace );

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    FIP_v_Init_Static_Traces                                                                                 */ /*!

  @brief           Initialize complete moving object traces structure

  @description     Initialize complete moving object traces structure

  @startuml 
  Partition FIP_v_Init_Static_Traces
  Start
	Note right: This function initializes complete moving object traces structure	
	- Depending on the available sources initialize the trace parameters for number of static traces
  Stop
  @enduml

  @return          -


  @glob_out        t_FIP_ObjectList[t_ObjNr] :  FIP object list of object iObj with iObj in [0...EM_N_OBJECTS[
                     u_ReferenceToTrace : Trace ID of Objects [0...FIP_STATIC_TRACE_NO_OF_TRACES[

  @c_switch_part   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!
  
  @pre             - 
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.05.2016
  @changed         04.05.2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
void FIP_v_Init_Static_Traces(void)
{
  TraceID_t iTrace;
  ObjNumber_t iObj = 0;

  /* Initialize the trace parameters for FIP_STATIC_TRACE_NO_OF_TRACES traces*/

  for (iTrace = 0u; iTrace < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* Initialize trace parameters*/
    FIP_v_InitMovingObjectStaticTraces ( iTrace );
  }
  /*Check all Fct objects and assign INVALID ID i.e 255 before starting actual trace computation*/
  for (iObj = 0; iObj < EM_N_OBJECTS ; iObj++)
  {
    pt_FIP_MOT_Output->u_ReferenceToStaticTrace[iObj] = (TraceID_t)FIP_u_TRACE_INVALID_ID;
  }
}
/*************************************************************************************************************************
  Functionname:    FIP_v_InitMovingObjectStaticTraces                                                               */ /*!

  @brief           initialize 1 trace structure 

  @description     initialize 1 trace structure 

  @startuml 
  Partition FIP_v_InitMovingObjectStaticTraces
  Start
  	Note right: This function initializes a single trace structure
  	- Depending on the available sourcesStop initializes a Moving Object Static trace structure
  @enduml

  @return          -

  @param[in]       iTrace : Trace ID [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[

  @glob_in         pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject : Object ID of Trace [0 ... EM_N_OBJECTS[
  
  @glob_out        t_FIP_ObjectList[t_ObjNr] : FIP object list of object iObj with iObj in [0...EM_N_OBJECTS[
                     u_ReferenceToTrace : Trace ID of Object [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
  @glob_out        FIP_a_MOSTrace[iTrace]: Moving Object Traces iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     iBadCycles : Quality Number for hysteresis at trace deletion [0, 15]
                     fLength : length of trace [float] m
                     fYVar[i] : fYVar values of trace [float] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     fTraceWithoutObjTime : time since object has been deleted [float] s
                     YIntersecDelta : distance, trace has moved on the y-axis (used for quality analysis) [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     YIntersecVar : intersection variance of trace with y-axis [0.f ... 1000.f]
                     Quality.PointNotOnStraightLine : sample point is on straight line trace or not [0, 1]
                     Quality.ReachedEgoVeh : bit that indicate ego has reached to traced to trace sample [0, 1]
                     Quality.valid_NoShadowObj : object is shadow or not [0, 1]
                     Quality.valid_YIntersecGrad : y intersection gradient is valid or not [0, 1]
                     Quality.valid_MaxAngleGrad : Maximum angle gradient is valid or not [0, 1]
                     Quality.valid_AngleGradVar : Angle gradient variance is valid or not [0, 1]
                     Quality.valid_MeanVarMOT2Curve : Mean variance of moving object trace to curve is valid or not [0, 1]
                     Quality.valid_YIntersecDelta : Delta of y intersection is valid or not [0, 1]
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] moving object static trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : FCT Object ID [0...EM_N_OBJECTS[
                       uiReferenceToEMObject : EM Object ID [0...100[
                       iNumberOfPoints : Number of sample points in trace for Trace in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fYIntersection : Y intersection of the trace w.r.t X-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
                       Legacy.YPredictedIntersec : Prediced Intersection of trace with y-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       Legacy.YPredictedIntersecVar : Prediced Intersection of trace with y-axis variance [0.f ... 1000.f] m
                       Legacy:ValidForLaneMatrix : Valid for lane matrix [TRUE, FALSE]
                       Legacy.TraceReachEgoVeh  : Traces sample reached to ego vahicle or not [0, 1]
                       fTracePointY[i] : Y-Position of sample point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : X-Position of sample point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointYStdDev[i] : Standard deviation of y-position of sample point i [0... PI/2*RW_FCT_MAX] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  

  @c_switch_part   FCT_CFG_USE_FCT_STATIC_TRACES: Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

@author           david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_InitMovingObjectStaticTraces (TraceID_t iTrace )
{
  uint8 uIndex;
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
  if ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID )
  {
    /* reset object data */
    pt_FIP_MOT_Output->u_ReferenceToStaticTrace[pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject] = (uint8) FIP_u_TRACE_INVALID_ID;
  }
  /* reset trace data */
  /* Rest variables used in FIP trace computation */
  /*!set initial values for the trace structure members*/
  FIP_a_MOSTrace[iTrace].fLength                = 0.0f;
  FIP_a_MOSTrace[iTrace].fTraceWithoutObjTime   = -1.0f;
  FIP_a_MOSTrace[iTrace].iBadCycles             = (sint8)0;
  FIP_a_MOSTrace[iTrace].YIntersecDelta         = 0.0f;
  FIP_a_MOSTrace[iTrace].YIntersecVar           = 0.0f;
  FIP_a_MOSTrace[iTrace].Quality.ReachedEgoVeh           = 0u;
  FIP_a_MOSTrace[iTrace].Quality.PointNotOnStraightLine  = 0u;
  FIP_a_MOSTrace[iTrace].Quality.valid_NoShadowObj            = 0u;
  FIP_a_MOSTrace[iTrace].Quality.valid_YIntersecGrad          = 0u;
  FIP_a_MOSTrace[iTrace].Quality.valid_MaxAngleGrad           = 0u;
  FIP_a_MOSTrace[iTrace].Quality.valid_AngleGradVar           = 0u;
  FIP_a_MOSTrace[iTrace].Quality.valid_MeanVarMOT2Curve       = 0u;
  FIP_a_MOSTrace[iTrace].Quality.valid_YIntersecDelta         = 0u;
  for (uIndex = 0u; uIndex < FIP_STATIC_TRACE_NO_OF_POINTS; uIndex++)
  {
    FIP_a_MOSTrace[iTrace].fYVar[uIndex] = 0.f;
  }
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

  /* Reset variables used in EM/FIP trace computation */
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject = (uint8) FIP_u_TRACE_INVALID_ID;
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToEMObject = (uint8) FIP_u_TRACE_INVALID_ID;
  
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = (sint8)0;

  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fYIntersection = FIPMOT_INVALID_VALUE;
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fYIntersectionGradFilt = 0.0f;
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].Legacy.YPredictedIntersec = FIPMOT_INVALID_VALUE;
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].Legacy.YPredictedIntersecVar = FIPMOT_INVALID_VALUE;
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].Legacy.TraceReachEgoVeh = 1u;
  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].Legacy.ValidForLaneMatrix = FALSE;

  for (uIndex = 0u; uIndex < FIP_STATIC_TRACE_NO_OF_POINTS; uIndex++)
  {
    pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[uIndex] = 0.f;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[uIndex] = 0.f;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointYStdDev[uIndex] = 0.f;
  }
}

#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_PreProcessEMTraces                                                                         */ /*!

  @brief           Pre process traces data which is received from EM through RTE ports

  @description     There are many ways of computing and using traces in FCT, this function is specific to the case when traces
                   are computed in EM and received in FCT. Before using the traces, preprocessing is usually carried out. 
                   Currently only data is copied to local structures but no actual preprocessing is done!
  
  @startuml 
  Partition FIP_v_PreProcessEMTraces
  Start
	Note right: This function pre-processes traces data which is received from EM through RTE ports	
	- Initialize the trace parameters for number of static traces
	- Copy all relevant data related to traces computed in EM \n to FCT local variables by iterating through each number \n of static traces and each number of sample trace points \n for each trace
	- Update Static trace ID for each of the object from EM Object ID
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pSLATE_MovObjTraces.ObjectTrace[iTrace]: moving object traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fTracePointX[i] : X-Position of sample point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     fTracePointY[i] : Y-Position of sample point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     fTracePointYStdDev[i] : Standard deviation of y-position of sample point i [0... PI/2*RW_FCT_MAX] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     fYIntersection : Y intersection of the trace w.r.t X-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
                     iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     uiReferenceToObject : reference to corresponding object in object list [0...100[
                     uiReferenceToFCTObject : FCT Object ID of Trace [0...EM_N_OBJECTS[
                     Legacy.TraceReachEgoVeh : Traces sample reached to ego vahicle or not [0, 1]
                     Legacy.ValidForLaneMatrix : Valid for lane matrix [TRUE, FALSE]
                     Legacy.YPredictedIntersec : Prediced Intersection of trace with y-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     Legacy.YPredictedIntersecVar : Prediced Intersection of trace with y-axis variance [float]
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fTracePointX[i] : X-Position of sample point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[ 
                     fTracePointY[i] : Y-Position of sample point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     fTracePointYStdDev[i] : Standard deviation of y-position of sample point i [0... PI/2*RW_FCT_MAX] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     fYIntersection : Y intersection of the trace w.r.t X-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
                     iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                     uiReferenceToObject : reference to corresponding object in object list [0...100[
                     uiReferenceToFCTObject : FCT Object ID of Trace [0...EM_N_OBJECTS[
                     Legacy.TraceReachEgoVeh : Traces sample reached to ego vahicle or not [0, 1]
                     Legacy.ValidForLaneMatrix : Valid for lane matrix [TRUE, FALSE]
                     Legacy.YPredictedIntersec : Prediced Intersection of trace with y-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                     Legacy.YPredictedIntersecVar : Prediced Intersection of trace with y-axis variance [float]
  
  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!
  @c_switch_full   SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         07.05.2016
  @changed         07.05.2016

  @todo            Check compilation and execution for all configurations of trace usage

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
void FIP_v_PreProcessEMTraces(void)
{
  uint8 u_TraceIndex, u_TracePoints;
  ObjNumber_t t_Obj;
  /* Copy all relevant data related to traces computed in EM to FCT local variables */
  for (u_TraceIndex = 0u; u_TraceIndex < FIP_STATIC_TRACE_NO_OF_TRACES; u_TraceIndex++)
  {
    for (u_TracePoints = 0u; u_TracePoints < FIP_STATIC_TRACE_NO_OF_POINTS; u_TracePoints++)
    {
      pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].fTracePointX[u_TracePoints]           = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].fTracePointX[u_TracePoints];
      pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].fTracePointY[u_TracePoints]           = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].fTracePointY[u_TracePoints];
      pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].fTracePointYStdDev[u_TracePoints]     = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].fTracePointYStdDev[u_TracePoints];
    }
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].fYIntersection         = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].fYIntersection;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].fYIntersectionGradFilt = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].fYIntersectionGradFilt;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].iNumberOfPoints        = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].iNumberOfPoints;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].uiReferenceToEMObject  = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].uiReferenceToObject;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].uiReferenceToFCTObject = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].uiReferenceToFCTObject;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].Legacy.TraceReachEgoVeh      = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].Legacy.TraceReachEgoVeh;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].Legacy.ValidForLaneMatrix    = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].Legacy.ValidForLaneMatrix;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].Legacy.YPredictedIntersec    = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].Legacy.YPredictedIntersec;
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_TraceIndex].Legacy.YPredictedIntersecVar = pSLATE_MovObjTraces->ObjectTrace[u_TraceIndex].Legacy.YPredictedIntersecVar;
  }

  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    pt_FIP_MOT_Output->u_ReferenceToStaticTrace[t_Obj] = OBJ_TRACE_ID(t_Obj);
  }

}
#endif /* END IF (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIPMOTCalculateMovingObjectTraces                                                                */ /*!

  @brief           main function for determination of moving object traces

  @description     main function for determination of moving object traces. It includes ego motion matrix updation, checks condition to select object for traces, 
                   Sample's object position for traces, compensate traces as per ego motion, check quality of traces.
  
  @startuml 
  Partition FIPMOTCalculateMovingObjectTraces
  Start
	Note right: This is the main function for determination of moving object traces	
	- Check for dead traces. It should be called before Trace \n creation so it frees FCT object ID to be selected as another trace
	- Check general conditions (vehicle dynamic) for calculating traces
	- Check conditions for creation, deletion and holding of traces
	- Sampling of traces: adding new sampling points
	- EGO motion compensation and shifting of sample points simultaneously
	- Quality analysis of traces
	- Calculate Y axis intersection of all Traces
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             Traces structure should be initialized
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
void FIP_v_CalculateMovingObjectStaticTraces (void)
{
  uint8 i = 0u;
  boolean b_ret = 0u;

  /*Check for dead traces. It should be called before Trace creation so it frees FCT object ID to be selected as another trace*/
  FIP_v_CheckDeadStaticTrace();

  /*! check general conditions (vehicle dynamic) for calculating traces */
  /*currently no functionality is implemented, could be implemented in future*/
  FIP_v_CheckGeneralConditionsStatic ();

  /*! Check conditions for creation, deletion and holding of traces */
  FIP_v_CheckStaticTraceConditions ();

/*! Sampling of traces: adding new sampling points */
  FIP_v_MOSTSampling ();

  /*! EGO motion compensation and shifting of sample points simultaneously */
  FIP_v_MOSTEgoMotionCompensation ();

  /*! Quality analysis of traces */
  FIP_v_MOSTQualityAnalyse();

  /*Calculate Y axis intersection of all Traces */
  for(i = 0u; i<FIP_STATIC_TRACE_NO_OF_TRACES; i++) 
  {
    b_ret = FIP_b_GetStaticTraceYAxisIntersection(i, &pt_FIP_MOT_Output->t_MovObjStaticTrace[i].Legacy.YPredictedIntersec,&pt_FIP_MOT_Output->t_MovObjStaticTrace[i].Legacy.YPredictedIntersecVar);
  }

  _PARAM_UNUSED(b_ret);
}
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckDeadStaticTrace                                                                       */ /*!

  @brief           Checks if Trace is dead Trace

  @description     Checks if object associated with the Trace is deleted. If it is deleted then this function will declare Trace a dead Trace.

  @startuml 
  Partition FIP_v_CheckDeadStaticTrace
  Start
	Note right: This function checks if object associated with the Trace is deleted \n If it is deleted then this function will declare Trace a dead Trace
	- Iterate through all the number of static traces
	If (FCT Object ID of a Trace is less than Vaid Trace ID without Object)
		If (Object ID state is new \n OR \n EM ID of object is different \n from SLATE Object ID) then (True)
  			- Object is Not in list \n Declare trace as dead trace
			Note right: If the object in the trace is deleted, \n but the trace is not deleted, then delete the trace
  		else (False)
		Endif
	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Getting FCT Object ID of a Trace [0-EM_N_OBJECTS-1, TRACE_VALID_NO_OBJ_ID]
                       uiReferenceToEMObject : Getting EM Object ID of a Trace [0-99, 249, 250]
  @glob_in         SLATE_b_GetObjIsNew : Indicate the administration state of object [TRUE, FALSE]

  @glob_in         OBJ_GENERAL().uiID : EM object ID [0-99]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         4/7/2016
  @changed         4/7/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_CheckDeadStaticTrace(void)
{
  TraceID_t iTrace;
  boolean b_ObjIsNew;
  
  for (iTrace = 0U; iTrace < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* local variable to reference pointer in function */
    uint8 uiRefToFCTObj = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;
    if ( uiRefToFCTObj  < FIP_u_TRACE_VALID_NO_OBJ_ID )  
    {
      b_ObjIsNew = SLATE_b_GetObjIsNew((ObjNumber_t)uiRefToFCTObj);
      if((b_ObjIsNew) || (pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToEMObject != SLATE_p_GetEMGenObjGeneral((ObjNumber_t)uiRefToFCTObj)->uiID)) // SLATE_b_GetObjIsDeleted(uiRefToFCTObj)
      {
        /*if the object in the trace is deleted, but the trace is not deleted, then delete the trace*/
        FIP_v_StartObjectStaticTraceDeletion ((ObjNumber_t)uiRefToFCTObj);
      }
    }
  }
}
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_MOSTSampling                                                                               */ /*!

  @brief           creation/replacing of supporting points of object trace

  @description     creation/replacing of supporting points of object trace

  @startuml 
  Partition FIP_v_MOSTSampling
  Start
	Note right: This function creates/replaces supporting points of object trace
	- Iterate through each number of static traces	
	If(Trace has valid object) then (True)
  		- Calculate distance between last point of trace and current position of object
  		If (Distance is greater than square of Sampling length) then (True)
			- SAMPLING distance reached -> add/replace point
  			If(New point is nearer than last trace point) then (True)
  				- Delete the trace
  			Else (False)
				If (Smart tracing disable flag switch is enabled) then (True)
  					- Points NOT on a STRAIGHT line
					- Set Point Not On Straight Line to TRUE
				Else (False)
					If (Straight Line is TRUE) then (True)
						If (Points on Straight line is less \n than maximum straight line length) then (True)
							- Replace last point with current position, \n because all point are on a straight line
						Else (False)
							- Straight line too long, insert new point
						Endif
					Else (False)
						- Points NOT on a STRAIGHT line
						- Set Point Not On Straight Line to TRUE
					Endif
				Endif
			Endif
  		Else (False)
  		Endif
  	Else (False)
  	Endif 
		- Global variable is updated
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         OBJ_LONG_DISPLACEMENT : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         pt_FIP_MOT_Output :  Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace]  moving object stactic traces structure of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace [0...EM_N_OBJECTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  
  @glob_out        FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                      Quality.PointNotOnStraightLine : sample point is on straight line trace or not [0, 1]
                      fYVar[0] : fYVar values of trace [float]
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       fTracePointYStdDev[i] : standard deviation of trace point i [0... PI/2*RW_FCT_MAX] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[

  @c_switch_part   FIP_MOST_DISABLE_SMART_SAMPLING : smart tracing disable flag: optimizations for straight lines using fewer points
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_MOSTSampling (void)
{
#if (!FIP_MOST_DISABLE_SMART_SAMPLING)
  bool_t    bStraightLine;
#endif
  TraceID_t iTrace;
  float32     fDistanceSqr;
  uint8 uiRefToFCTObj;
  float32 fTracePointX_0;
  sint8 i_NumberOfPoints;
  float32 fRefToTraceObj;

  for (iTrace = 0U; iTrace < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* local variables to reference pointer in function */
    uiRefToFCTObj = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;
    fTracePointX_0 = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[0];
    i_NumberOfPoints = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints;
    if ( uiRefToFCTObj  < FIP_u_TRACE_VALID_NO_OBJ_ID )
    {
      /* NORMAL tracing with an active object -> sampling */
      fDistanceSqr =  SQR ( fTracePointX_0 - (*pt_FIP_RTE_Input->pf_ObjLongDisp( (ObjNumber_t)uiRefToFCTObj ))  ) 
        + SQR ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[0] - (*pt_FIP_RTE_Input->pf_ObjLatDisp((ObjNumber_t)uiRefToFCTObj ))  ) ;

      if (fDistanceSqr > SQR( FIP_MOST_SAMPLING_LENGTH  ) )
      {
        /* SAMPLING distance reached -> add/replace point */
        fRefToTraceObj = *pt_FIP_RTE_Input->pf_ObjLongDisp( (ObjNumber_t)uiRefToFCTObj );
        /*!@todo only allow traces as function from X (y=f(x)), if extension is needed remove deletion here */
        if (   (i_NumberOfPoints   >= 1       )
          &&(fRefToTraceObj <= fTracePointX_0 )
          )
        {
          /*! new point is nearer than last one -> delete trace */
          FIP_v_InitMovingObjectStaticTraces (iTrace);
        }
        else
        {
          /* ADD new supporting point */

          /*! check if new point fit to an straight line */
#if (FIP_MOST_DISABLE_SMART_SAMPLING)
          /* points NOT on a STRAIGHT line */
          /* insert mode : for ego motion comp. WITH insertion */
          i_NumberOfPoints ++;
          i_NumberOfPoints *= ((sint8)-1);
          FIP_a_MOSTrace[iTrace].Quality.PointNotOnStraightLine = 1U;
#else
          bStraightLine  = EOMOTCheckStraightLineCondition ( iTrace );
          if  ( bStraightLine  == TRUE )
          {
            /*!@ todo check if dX as approximation for real distance is enough */
            if ( fABS( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[1] - (*pt_FIP_RTE_Input->pf_ObjLongDisp( uiRefToFCTObj )) ) <= FIP_MOST_MAX_STRAIGHT_LINE_LENGTH )
            {
              /* points on a STRAIGHT line */
              /* replace last point with current position, because all point are on a straight line */
              pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[0]    = *pt_FIP_RTE_Input->pf_ObjLongDisp( uiRefToFCTObj);
              pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[0]    = *pt_FIP_RTE_Input->pf_ObjLatDisp( uiRefToFCTObj );
              FIP_a_MOSTrace[iTrace].fYVar[0] = FIP_f_GetObjObservationVariance( (ObjNumber_t) uiRefToFCTObj );
              pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointYStdDev[0] = SQRT_(FIP_a_MOSTrace[iTrace].fYVar[0]);
            }
            else
            {
              /* straight line too long .... insert new point */
              i_NumberOfPoints++;      
              i_NumberOfPoints*= ((sint8)-1);
              pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = i_NumberOfPoints;
            }
          }
          else
          {
            /* points NOT on a STRAIGHT line */
            /* insert mode : for ego motion comp. WITH insertion */
            i_NumberOfPoints ++;      
            i_NumberOfPoints *= ((sint8)-1);
            pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = i_NumberOfPoints;
            FIP_a_MOSTrace[iTrace].Quality.PointNotOnStraightLine = 1U;
          }
#endif
          /* FIP_a_MOSTrace[iTrace].fLength     += SQRT( fDistanceSqr ); */
        }
      }
      else
      {
        /* do nothing ( just compensate ) */
      }
    }
    else
    {
      /* do nothing (no trace) */
    }
    /* global variable is updated */
    pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = i_NumberOfPoints;
  }
}
#endif /* (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_MOSTEgoMotionCompensation                                                                  */ /*!

  @brief           Compensate traces based on ego motion

  @description     Detailed Design

  @startuml 
  Partition FIP_v_MOSTEgoMotionCompensation
  Start
	Note right: This function compensates traces based on ego motion	
	- Iterate through each number of static traces
	If (Trace has valid object) then (True)
		If (Number of sample points in trace is greater than or equal to 0) then (True)
			- Compensate samples for ego motion
		Else (False)
			If (Number of sample points in trace is greater than number of FIP sample trace points)
				- Calculate distance between last 2 points
				- Crop length
				- Limit number of sample points in trace to number of FIP sample trace points (maximum)
				- Shift all the points to left
				- Compensate the points for ego motion
				- Update length for points
			Else (False)
			Endif
		Endif
		- Resaving local changed variable to FIP number of sample points 
		- Delete next to last point of trace, if it's behind sensor vehicle
	Else (False)
	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_MOT_Output . Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace [0...EM_N_OBJECTS[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_in         FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                               fLength : length of trace [float] m
                               fYVar[i] : fYVar values of trace [float] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_in         pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[]_STD_DEV : standard deviation of trace points [unsigned short]
  @glob_in         OBJ_LONG_DISPLACEMENT : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        FIP_a_MOSTrace[iTrace] Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fLength : length of trace [float] m
                     fYVar[i] : fYVar values of trace [float] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                    t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                      fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                      fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                      fTracePointYStdDev[i]: standard deviation of trace point i [0... PI/2*RW_FCT_MAX] with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[


  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

@author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_MOSTEgoMotionCompensation  (void)
{
  TraceID_t iTrace;
  float32 fDistance;
  float32 fDeltaX, fDeltaY;
  sint8 iPt;
  uint8 uiRefToFCTObj;
  sint8 i_NumberOfPoints;

  for (iTrace = 0U; iTrace < (TraceID_t)FIP_STATIC_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* local variables to reference pointer in function */
    uiRefToFCTObj = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;
    i_NumberOfPoints = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints;
    if ( uiRefToFCTObj < FIP_u_TRACE_VALID_OBJ_ID )  
    {
      /* valid trace */
      /*! @todo check this position for deletion check */
      /* ego motion compensation */
      if ( i_NumberOfPoints >= 0 )
      {
        FIP_v_MOSTCompensatePoints( iTrace );
      }
      else
      {
        /* SHIFT mode : save ego motion comp. result in next array element , add new entry */

        /* cNoPts is already increased */
        /* reset mode */
        i_NumberOfPoints *= -1;

        /* check for points that will be shifted out */
        if ( i_NumberOfPoints > FIP_STATIC_TRACE_NO_OF_POINTS )
        {
          /* list is full and will overflow */
          /* calc distance between last 2 points */
          fDeltaX = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[ FIP_STATIC_TRACE_NO_OF_POINTS - 1 ] - pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[ FIP_STATIC_TRACE_NO_OF_POINTS - 2 ];
          fDeltaY = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[ FIP_STATIC_TRACE_NO_OF_POINTS - 1 ] - pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[ FIP_STATIC_TRACE_NO_OF_POINTS - 2 ];
          fDistance = SQRT_(SQR( fDeltaX ) + SQR( fDeltaY ));
          /* crop length */
          FIP_a_MOSTrace[iTrace].fLength = MAX_FLOAT( ( FIP_a_MOSTrace[iTrace].fLength - fDistance ) , 0.0f);
          /* limit NoPts to max */
          i_NumberOfPoints  = (sint8) FIP_STATIC_TRACE_NO_OF_POINTS;
        }
        /* shift points */
        for ( iPt = (i_NumberOfPoints - 1)  ; iPt >= 1 ; iPt-- )
        {
          /* shift */
          pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[iPt]   =  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[iPt-1];
          pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[iPt]   =  pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[iPt-1];
          FIP_a_MOSTrace[iTrace].fYVar[iPt]=  FIP_a_MOSTrace[iTrace].fYVar[iPt-1];
          pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointYStdDev[iPt] = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointYStdDev[iPt-1];
        }
		/* save number of trace points before FIP_v_MOSTCompensatePoints() is called */
		pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = i_NumberOfPoints;/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact  on the functionality. */

        /*compensate points*/
        FIP_v_MOSTCompensatePoints( iTrace );
        /* add new point */
        pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[0]    = *pt_FIP_RTE_Input->pf_ObjLongDisp( (ObjNumber_t)uiRefToFCTObj );
        pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[0]    = *pt_FIP_RTE_Input->pf_ObjLatDisp( (ObjNumber_t)uiRefToFCTObj );
        FIP_a_MOSTrace[iTrace].fYVar[0] = FIP_f_GetObjObservationVariance( (ObjNumber_t) uiRefToFCTObj );
        pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointYStdDev[0] = SQRT_(FIP_a_MOSTrace[iTrace].fYVar[0]);
        /* update length */
        if ( i_NumberOfPoints >= FCT_STATIC_TRACE_TWO_POINTS)/*FCT_STATIC_TRACE_TWO_POINTS*/
        {
          fDeltaX = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[0] - pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[ 1];
          fDeltaY = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[0] - pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[ 1];
          fDistance = SQRT_( SQR( fDeltaX ) + SQR( fDeltaY ) );
          FIP_a_MOSTrace[iTrace].fLength += fDistance; 
        }
      }
      /* Resaving local changed variable to reference */
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = i_NumberOfPoints;
      /*! delete next to last point of trace, if it's behind sensor vehicle */
      FIP_v_CropStaticTrace ( iTrace );
    }
    else
    {
      /* no trace -> do nothing */
    }

  } /* for */
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_CropStaticTrace                                                                            */ /*!

  @brief           crop trace. crop last point, if it's more than 1 sampling length behind sensor vehicle

  @description     crop trace. crop last point, if it's more than 1 sampling length behind sensor vehicle

  @startuml 
  Partition FIP_v_CropStaticTrace
  Start
	Note right: This function crops trace. Crop last point, if it's more than 1 sampling length behind sensor vehicle
	If (Number of sample points in trace is greater than 2) then (True)	
		If(next to last point is behind ego vehicle) then (True)
			- Calculate distance between last 2 points
  			- Drop old sample
			- Decrease number of sample points
  			- Adjust length of trace appropriately
 		Else(False)
			- nothing to crop
  		Endif
  	Else(False)
  	Endif 
  Stop	
  @enduml

  @return          -

  @param[in]       iTrace : Trace ID [0...FIP_STATIC_TRACE_NO_OF_TRACES[

  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_in         FIP_a_MOSTrace[iTrace]: Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                      fLength : length of trace [float] m

  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       fTracePointX[i] : x coordinates of trace point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_out        FIP_a_MOSTrace[iTrace]: Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                      fLength : length of trace [float] m

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_CropStaticTrace ( TraceID_t  iTrace )
{

  float32 fDeltaX, fDeltaY;
  float32 fDistance;
  sint8  cNoPts;

  cNoPts = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints;

  if (cNoPts >=FCT_STATIC_TRACE_TWO_POINTS)
  {
    /* when next to last point is behind ego vehicle crop trace */
    if( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[ cNoPts - 2  ] < 0.0f )
    {
      /* calc distance between last 2 points */
      fDeltaX = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[ cNoPts - 2 ] - pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[ cNoPts - 1 ];
      fDeltaY = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[ cNoPts - 2 ] - pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[ cNoPts - 1 ];
      fDistance = SQRT_( SQR( fDeltaX ) + SQR( fDeltaY ) );

      /* reset value */
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[cNoPts -1] = FIPMOT_INVALID_VALUE;
      /* decrease nr. of points */
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints = (sint8)MAX( ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints  - 1         ) , 0);

      FIP_a_MOSTrace[iTrace].fLength =      MAX_FLOAT( ( FIP_a_MOSTrace[iTrace].fLength - fDistance ) , 0.0f);
    }
  }
  else
  {
    /* < 2 points -> nothing to crop */
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_MOSTQualityAnalyse                                                                         */ /*!

  @brief           Calculate trace quality

  @description     Calculate trace quality. 
                    - Checks if trace tail has reached ego-vehicle. 
                    - check, if corresponding object is classified as truck cabin. 
                    - analyze shape of trace
                    - analyze angle between two segments. 
                    - analyze y-intersection of trace tail
  
  @startuml 
  Partition FIP_v_MOSTQualityAnalyse
  Start
	Note right: This function calculates trace quality
	- Iterate throught each of the number of static traces	
	If(Trace has valid object) then (True)
  		- Calculate trace has reached to ego vehicle or not
  		If(Object has moved form last cycle position \n and \n Trace has reached to ego vehicle) then (True)
  			- Calculate Y axis intersection of the trace
  			If(Y axis intersection of the trace is valid) then (True)
  				- Calculate gradient filter of Y axis intersection
  				- Calculate distance, trace has moved on the y-axis
				If (Absolute gradient filter of Y axis intersection is less than minimum threshold \n AND \n absolute Y axis intersection delta is greater than maximum delta) then (True)
					- Set Y axis intersection delat to 0
				Else (False)
				Endif
				- Calculate filtered y axis intersection gradient is valid or not
				- Calculate distance, trace has moved on the y-axis is valid or not
			Else (False)
				- Calculate filtered y axis intersection gradient is valid or not
				- Calculate distance, trace has moved on the y-axis is valid or not
			Endif
			
			- Iterate throught each number of sample points in trace
			- Calculate angle and slope between trace segment and x-axis for all the samples 
  			- Compare angle of 2 segments and find highest angle
  			- Calculate variance of angle gradient
  			- Validate both maximum angle and variance of angle gradient with it’s maximum value
			If (Number of sample points in trace is greater than 2) then (True)
				- Calculate variance of angle gradient
			Else (False)
				- Set variance of angle gradient to 0
			Endif

			- Calculate variance of angle gradient is valid or not
			- Calculate maximum angle gradient is valid or not
			
			If (Number of sample points in trace is greater than 2) then (True)
  				- Analyse shape of curve, by fitring a curve through minimal and maximal point on the trace;
  				- Calculate Mean of variance of disance of trace point to curve
  				- Validate Mean of variance of disance of trace point to curve to maximum value
  				- Check object is shadow or not;
  			Else(False) 
  			Endif
		Else (False)
		Endif
	Else (False)
	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace [0...EM_N_OBJECTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
  @glob_in         FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       Quality.ReachedEgoVeh : bit that indicate ego has reached to traced to trace sample [0, 1]
                       YIntersecDelta : distance, trace has moved on the y-axis (used for quality analysis) [float]
  @glob_in         OBJ_IS_SHADOW : checks if object is shadow or not [0, 1]
 
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[i] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       Legacy.TraceReachEgoVeh : bit that indicate ego has reached to traced to trace sample [0, 1]
                       fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
                       fYIntersection : Y intersection of the trace w.r.t X-axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       YIntersecDelta : distance, trace has moved on the y-axis (used for quality analysis) [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       YIntersecVar : intersection variance of trace with y-axis [0.f ... 1000.f]
                       Quality.ReachedEgoVeh : bit that indicate ego has reached to traced to trace sample [0, 1]
                       Quality.valid_YIntersecGrad : The filtered y axis intersection gradient is valid or not [0, 1]
                       Quality.valid_YIntersecDelta : distance, trace has moved on the y-axis is valid or not [0, 1] 
                       Quality.valid_AngleGradVar : angle gradient variance is valid or not [0, 1]
                       Quality.valid_MaxAngleGrad : Max angle gradient is valid or not [0, 1]
                       Quality.valid_MeanVarMOT2Curve : Mean variance from trace to curve is valid or not[0, 1]
                       Quality.valid_NoShadowObj : object is shadow or not [0, 1]
  
  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @todo            -

  @author          nele.hanel@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_MOSTQualityAnalyse(void)
{
  float32 f_tempYIntersection = FIPMOT_INVALID_VALUE, f_tempYIntersectionVar, f_tempGradient;
  float32 a_Angle[FIP_STATIC_TRACE_NO_OF_POINTS];             
  float32 a_AngleGradient[FIP_STATIC_TRACE_NO_OF_POINTS];     
  float32 f_DrivenDist, f_dX, f_dY;
  float32 f_Slope, f_C0, f_Y0;
  float32 f_temp_AngleGradVar, f_max_AngleGrad;
  float32 f_maxY, f_maxX, f_minX, f_minY, f_maxXmaxX, f_minXminX;
  boolean b_valid, bIsObjectShadow;
  TraceID_t i;
  sint8 j;
  uint8 uiRefToFCTObj;
  sint8 i_NumberOfPoints;
  float32 f_YIntersectionGradFilt,f_YIntersection;
  float32 f_YCurve, f_temp_MeanVarMOT2Curve = 0.0f;

  float32 f_AbsYIntersectDelta;     /* fABS(FIP_a_MOSTrace[i].YIntersecDelta)         */
  float32 f_Abs_YIntersectionGradFilt, f_Abs_YIntersecDelta, f_Abs_dX, f_Abs_temp_AngleGradVar, f_Abs_max_AngleGrad;
  float32 f_Abs_DiffmaxXmaxXminXminX, f_ABS_temp_MeanVarMOT2Curve, f_AbsYIntersectionGradFilt;

  f_DrivenDist = SLATE_f_GetCPCycleTime() * (*pt_FIP_RTE_Input->pf_EgoVelObjSync);

  for(i = 0u; i< ( TraceID_t) FIP_STATIC_TRACE_NO_OF_TRACES; i++)
  {    /* local variables to reference pointer in function */
    uiRefToFCTObj = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].uiReferenceToFCTObject;
    i_NumberOfPoints = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].iNumberOfPoints;
    f_YIntersectionGradFilt= pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fYIntersectionGradFilt;
    f_YIntersection = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fYIntersection;

    if(uiRefToFCTObj < (uint8)FIP_u_TRACE_INVALID_ID)
    {
      /* ----------------------------------------------------------------------------------- */
      /* check, if trace tail has reached ego-vehicle */
      /* ----------------------------------------------------------------------------------- */
      /* evaluate quality */
      FIP_a_MOSTrace[i].Quality.ReachedEgoVeh = (pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointX[i_NumberOfPoints-1]<0.0f)?1u:0u;

      pt_FIP_MOT_Output->t_MovObjStaticTrace[i].Legacy.TraceReachEgoVeh = (boolean)FIP_a_MOSTrace[i].Quality.ReachedEgoVeh;

      /* ----------------------------------------------------------------------------------- */
      /* analyse y-intersection of trace tail */
      /* ----------------------------------------------------------------------------------- */

      if(  (f_DrivenDist > C_F32_DELTA)
        &&(FIP_a_MOSTrace[i].Quality.ReachedEgoVeh) )  /* use direct access to the quality instead of FIP_STATIC_TRACE_GET_QUALITY(i).ReachedEgoVeh, remove misara 12.4 */ // PRQA S 4115
      /* date: 2016-05-11, reviewer: Chirag, reason: no side effects */
      {
        b_valid = FIP_b_GetStaticTraceYAxisIntersection (i, &f_tempYIntersection , &f_tempYIntersectionVar);
        if( (b_valid == TRUE)
          &&(f_YIntersection < FIPMOT_INVALID_VALUE) )
        {
          f_tempGradient = (f_YIntersection - f_tempYIntersection)/f_DrivenDist;
          f_YIntersectionGradFilt = ((0.8f) * f_YIntersectionGradFilt) + ((0.2f) * f_tempGradient); 
          FIP_a_MOSTrace[i].YIntersecDelta += (f_YIntersection - f_tempYIntersection);

          f_AbsYIntersectDelta    = fABS(FIP_a_MOSTrace[i].YIntersecDelta);

          f_AbsYIntersectionGradFilt = fABS(f_YIntersectionGradFilt);
          if(  (f_AbsYIntersectionGradFilt < FIP_MOST_MIN_ABS_YINTERSEC_GRAD_FILTR)
            &&(f_AbsYIntersectDelta    > FIP_MOST_MAX_YINTERSEC_DELTA) )
          {
            FIP_a_MOSTrace[i].YIntersecDelta = 0.0f;
          }
          /* evaluate quality */
          f_Abs_YIntersectionGradFilt = fABS(f_YIntersectionGradFilt);
          FIP_a_MOSTrace[i].Quality.valid_YIntersecGrad = (f_Abs_YIntersectionGradFilt< FIP_MOST_VALID_MAXYISGRAD)?1u:0u;
          f_Abs_YIntersecDelta = fABS(FIP_a_MOSTrace[i].YIntersecDelta);
          FIP_a_MOSTrace[i].Quality.valid_YIntersecDelta = (f_Abs_YIntersecDelta< FIP_MOST_VALID_YISDELTA)?1u:0u;
        }
        else
        {
          /* evaluate quality */
          FIP_a_MOSTrace[i].Quality.valid_YIntersecGrad = 1u;
          FIP_a_MOSTrace[i].Quality.valid_YIntersecDelta = 1u;
        }
        pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fYIntersection = f_tempYIntersection;
        FIP_a_MOSTrace[i].YIntersecVar = f_tempYIntersectionVar;
      }
      else
      {
        /* evaluate quality */
        FIP_a_MOSTrace[i].Quality.valid_YIntersecGrad = 1u;
        FIP_a_MOSTrace[i].Quality.valid_YIntersecDelta = 1u;
      }

      /* ----------------------------------------------------------------------------------- */
      /* analyse angle between two segments */
      /* ----------------------------------------------------------------------------------- */
      f_temp_AngleGradVar = 0.0f; 
      f_max_AngleGrad = 0.0f;
      for(j=1; j<i_NumberOfPoints; j++)
      {
        /* calculate angle between segment and x-axis */
        f_dX = ( pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointX[j] - pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointX[j-1] );
        f_dY = ( pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointY[j] - pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointY[j-1] );
	    f_Abs_dX = fABS(f_dX);
        if(f_Abs_dX > C_F32_DELTA)
        {
          f_Slope = f_dY / f_dX; // PRQA S 584
          /* date: 2016-05-11, reviewer: Chirag, reason: f_dx will be graeter than 0.001  */
          a_Angle[j] = RAD2DEG(ATAN_(f_Slope));
        }
        else
        {
          a_Angle[j] = 90.0f;
        } 
        /* compare angles of two following segments */
        if(j>1)
        {                 
          a_AngleGradient[j] = a_Angle[j] - a_Angle[j-1];
          f_temp_AngleGradVar += SQR(a_AngleGradient[j]);
          f_max_AngleGrad = MAX_FLOAT(f_max_AngleGrad, fABS(a_AngleGradient[j]));
        }
      }
      if(i_NumberOfPoints>FCT_STATIC_TRACE_TWO_POINTS)
      {
        f_temp_AngleGradVar = f_temp_AngleGradVar/( (float32)(i_NumberOfPoints) - (float32)(FCT_STATIC_TRACE_TWO_POINTS) );
      }   
      else
      {
        f_temp_AngleGradVar = 0.0f;
      }
      /* evaluate quality */
      f_Abs_temp_AngleGradVar = fABS(f_temp_AngleGradVar);
      FIP_a_MOSTrace[i].Quality.valid_AngleGradVar = (f_Abs_temp_AngleGradVar< FIP_MOST_VALID_ANGLEVAR)?1u:0u;
      f_Abs_max_AngleGrad = fABS(f_max_AngleGrad);
      FIP_a_MOSTrace[i].Quality.valid_MaxAngleGrad = (f_Abs_max_AngleGrad< FIP_MOST_VALID_MAXANGLE)?1u:0u;



      /* ----------------------------------------------------------------------------------- */
      /* analyse shape of trace */
      /* ----------------------------------------------------------------------------------- */
      if(i_NumberOfPoints > FCT_STATIC_TRACE_TWO_POINTS)
      {
        /* fit a curve (y(x) = 0.5*f_C0 *x^2 + YIntersection) through minimal and maximal point on the trace */
        f_maxY = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointY[0];
        f_minY = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointY[i_NumberOfPoints-1];
        f_maxX = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointX[0];
        f_minX = pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointX[i_NumberOfPoints-1];
        f_maxXmaxX = f_maxX*f_maxX;
        f_minXminX = f_minX*f_minX;
        f_Abs_DiffmaxXmaxXminXminX = fABS(f_maxXmaxX - f_minXminX);
        if(f_Abs_DiffmaxXmaxXminXminX > C_F32_DELTA)
        {
          f_C0 = (2.0f * (f_maxY - f_minY)) / ((f_maxXmaxX) - (f_minXminX)); // PRQA S 3121
          /* date: 2016-05-11, reviewer: Chirag, reason: used to double the value */
          f_Y0 = f_maxY - (0.5f * f_C0 * f_maxXmaxX); // PRQA S 3121
          /* date: 2016-05-11, reviewer: Chirag, reason: used to half the value */
          /* calc mean variance of trace to curve */
          f_temp_MeanVarMOT2Curve = 0.0f;
          for(j=1; j<i_NumberOfPoints; j++)
          {
            f_YCurve = (0.5f * f_C0 * SQR(pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointX[j])) + f_Y0; // PRQA S 3121
          /* date: 2016-05-11, reviewer: Chirag, reason: used to half the value */
            f_dY = (pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fTracePointY[j] - f_YCurve);
            f_temp_MeanVarMOT2Curve += SQR(f_dY);
          }
          f_temp_MeanVarMOT2Curve /= ((float32)i_NumberOfPoints);
          f_ABS_temp_MeanVarMOT2Curve = fABS(f_temp_MeanVarMOT2Curve);
          FIP_a_MOSTrace[i].Quality.valid_MeanVarMOT2Curve = (f_ABS_temp_MeanVarMOT2Curve< FIP_MOST_VALID_MAXVAR2CURVE)?1u:0u;
        }
        else
        {
          FIP_a_MOSTrace[i].Quality.valid_MeanVarMOT2Curve = 1u;
        }
      }
      else
      {
        FIP_a_MOSTrace[i].Quality.valid_MeanVarMOT2Curve = 1u;
      }
	  if(uiRefToFCTObj < (uint8)EM_N_OBJECTS)
	  {
		  bIsObjectShadow = SLATE_b_GetObjIsShadow( (ObjNumber_t)uiRefToFCTObj);
      /* ----------------------------------------------------------------------------------- */
      /* check, if corresponding object is classified as truck cabin */
      /* ----------------------------------------------------------------------------------- */
		  if( bIsObjectShadow == TRUE)
		  {
			  FIP_a_MOSTrace[i].Quality.valid_NoShadowObj = 0u;
		  }
		  else
		  {
			  FIP_a_MOSTrace[i].Quality.valid_NoShadowObj = 1u;

		  }
	  }
	  else
	  {
		  FIP_a_MOSTrace[i].Quality.valid_NoShadowObj = 1u;
	  }
    }
    else
    {
      /* make MISRA happy */
    }
    /* Resaving local changed variable to reference */
    pt_FIP_MOT_Output->t_MovObjStaticTrace[i].fYIntersectionGradFilt = f_YIntersectionGradFilt;
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_b_GetStaticTraceYAxisIntersection                                                            */ /*!

  @brief           determine the intersection from trace or predicted trace with 
                   Y-axis

  @description     - if the trace has more than 1 point, 
                     then y-intersection is always the inter-/extrapolated intersection of the last trace segment
                   - if this segment is nearly parallel to the y-axis, then no valid intersection is given
                   - if the trace has only one point, 
                   - and object and trace point are separated by the y-axis, then intersection is interpolated 
                     (except they are parallel to y-axis, in that case no valid intersection is given 
                   - and object and trace point lie on the same side of the y-axis, then no valid intersection is given 
  
  @startuml 
  Partition FIP_b_GetStaticTraceYAxisIntersection
  Start
	Note right: This function determines the intersection from trace or predicted trace with Y-axis	
	If(Trace has valid object) then (True)
 		If(Trace has only one sample and Distance beetween last sample and current position is very small) then (True)
			- Set y intersection as INVALID
  		Else (False)
  			- Take current position as head point and last trace sample as tail point. Calculate the slope
  			- Using the slope calculate Y intersection point and Variance of Y intersection
  		Endif
  	Else (False)
  	Endif
  Stop
  @enduml

  @return           y intersection exists or not [TRUE; FAULSE]

  @param[in]       iTrace : Trace ID [0...FIP_STATIC_TRACE_NO_OF_TRACES[
  @param[in,out]   *pfY : y intersection of trace [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   *pfYVar :  y intersection standard deviation [float]

  @glob_in         OBJ_LONG_DISPLACEMENT : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX][float] m
  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                    t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace [0...EM_N_OBJECTS[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static boolean FIP_b_GetStaticTraceYAxisIntersection (TraceID_t iTrace, float32 *pfY , float32 *pfYVar )
{
  sint8                s_Tr;
  float32               f_Slope
    ,f_SlopeVar
    ,f_TraceDistXhead
    ,f_TraceDistYhead
    ,f_TraceDistYVarhead
    ,f_TraceDistXtail
    ,f_TraceDistYtail
    ,f_TraceDistYVartail
    ,f_TracePointX;
  boolean              b_Valid;
  ObjNumber_t u_iTracedObj;
  sint8 i_NumberOfPoints;
  float32 f_TracedObjLongDisp, f_AbsDiff_PointXDistXtail, f_AbsDif_DistXheadDistXtail, f_Abs_DiffPointXDistXtail;

  b_Valid = TRUE;
  
  /* local variable to reference pointer in function */
  i_NumberOfPoints= pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints;

  /*! @todo add dead traces , her only with object */
  /*if the trace has only one point in it.. no 'Y' intersection is possible*/
  if ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject < FIP_u_TRACE_VALID_NO_OBJ_ID )
  {
    u_iTracedObj = (ObjNumber_t)pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject;
    if( i_NumberOfPoints == (sint8)1 )
    {
      f_TracedObjLongDisp = *pt_FIP_RTE_Input->pf_ObjLongDisp( u_iTracedObj );
      if ( ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[0] - (f_TracedObjLongDisp) ) < C_F32_DELTA )
      {
        b_Valid = FALSE;
        *pfY    = FIPMOT_INVALID_VALUE;
        *pfYVar = FIPMOT_INVALID_VALUE;
      }
    }


    /* trace valid */
    if (b_Valid == TRUE) 
    {
      /* determine Xmax point */
      /* trace has an object */ 
      f_TraceDistXhead    = *pt_FIP_RTE_Input->pf_ObjLongDisp( u_iTracedObj );
      f_TraceDistYhead    = *pt_FIP_RTE_Input->pf_ObjLatDisp( u_iTracedObj );
      /* To get the object variance over the distance traveled */
      f_TraceDistYVarhead = FIP_f_GetObjObservationVariance( u_iTracedObj );

      /* determine Xmin point */
      f_TraceDistXtail  = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[i_NumberOfPoints - 1];
      f_TraceDistYtail  = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[i_NumberOfPoints - 1];
      f_TraceDistYVartail  = FIP_a_MOSTrace[iTrace].fYVar[i_NumberOfPoints - 1];

      if (f_TraceDistXhead >= 0.0f)
      {
        /*****************************************/
        /* trace HEAD is IN FRONT OF ego vehicle */
        if (f_TraceDistXtail > 0.0f)
        {
          /*****************************************/
          /* trace HEAD is IN FRONT OF ego vehicle */
          /* trace TAIL is IN FRONT OF ego vehicle */
          /*   -> predict/interpolate to Y-axis    */
          s_Tr = (sint8)(i_NumberOfPoints - 1);
          /* local variables to reference pointer in function for second last element in array */
          f_TracePointX= pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[s_Tr-1];//PRQA S 3689
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: manually verified, it will not exceed number of trace points*/

          if ( i_NumberOfPoints >=  FCT_STATIC_TRACE_TWO_POINTS )
          {
            f_AbsDiff_PointXDistXtail = fABS(f_TracePointX - f_TraceDistXtail);
            if(f_AbsDiff_PointXDistXtail> C_F32_DELTA)
            {
              /*if the trace has maximum 2 points in it , find the slope 
              SLOPE = Y/X;*/
              f_Slope =  ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[s_Tr-1] - f_TraceDistYtail )//PRQA S 3689
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: manually verified, it will not exceed number of trace points*/
                /( f_TracePointX - f_TraceDistXtail );
              f_SlopeVar = ( FIP_a_MOSTrace[iTrace].fYVar[s_Tr-1] - f_TraceDistYVartail )//PRQA S 3689
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: manually verified, it will not exceed number of trace points*/
                /( f_TracePointX - f_TraceDistXtail );
              /* y(x=0)       =           dx         *  slope + y0              */
              *pfY         = (-( f_TraceDistXtail ) * f_Slope)    + f_TraceDistYtail;
              *pfYVar      = (-( f_TraceDistXtail ) * f_SlopeVar) + f_TraceDistYVartail;
              b_Valid = TRUE;
            }
            else
            {
              /* last segment is nearly parallel to y-axis */
              /* y-intersection does not exist */
              b_Valid = FALSE;
              *pfY    = FIPMOT_INVALID_VALUE;
              *pfYVar = FIPMOT_INVALID_VALUE;
            }
          } 
          else
          {
            /* trace has only one point */
            /* extrapolating an y-intersection is not reasonable */
            b_Valid = FALSE;
            *pfY    = FIPMOT_INVALID_VALUE;
            *pfYVar = FIPMOT_INVALID_VALUE;
          }       
        }
        else
        {
          /*****************************************/
          /* trace HEAD is IN FRONT OF ego vehicle */
          /* trace TAIL is BEHIND      ego vehicle */
          /*   -> sample it                        */
          if (i_NumberOfPoints == (sint8)1)
          {
            f_AbsDif_DistXheadDistXtail = fABS(f_TraceDistXhead - f_TraceDistXtail);
            if(f_AbsDif_DistXheadDistXtail> C_F32_DELTA)
            {
              /* interpolate between obj and the one and only trace point */
              f_Slope =  ( f_TraceDistYhead - f_TraceDistYtail )
                /( f_TraceDistXhead - f_TraceDistXtail ); 
              f_SlopeVar = ( f_TraceDistYVarhead - f_TraceDistYVartail )
                /( f_TraceDistXhead - f_TraceDistXtail );
              /* y(x=0)       =           f_dX       *  slope + f_Y0              */
              *pfY         =   (-(f_TraceDistXtail)  * f_Slope) +  f_TraceDistYtail;
              *pfYVar      =   (-(f_TraceDistXtail)  * f_SlopeVar) + f_TraceDistYVartail;
              b_Valid = TRUE;
            }
            else
            {
              /* obj and one-and-only trace point are nearly parallel to y-axis */
              /* y-intersection does not exist */
              b_Valid = FALSE;
              *pfY    = FIPMOT_INVALID_VALUE;
              *pfYVar = FIPMOT_INVALID_VALUE;
            }
          }
          else
          {
            /* interpolate between last 2 trace points */
            s_Tr = (sint8)(i_NumberOfPoints - 1);
            /* local variables to reference pointer in function for second last element in array */
            f_TracePointX= pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[s_Tr-1];
            f_Abs_DiffPointXDistXtail = fABS(f_TracePointX - f_TraceDistXtail);
            if(f_Abs_DiffPointXDistXtail> C_F32_DELTA)
            {
              f_Slope =  ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[s_Tr-1] - f_TraceDistYtail )
                /( f_TracePointX - f_TraceDistXtail );
              f_SlopeVar = ( FIP_a_MOSTrace[iTrace].fYVar[s_Tr-1] - f_TraceDistYVartail )
                /( f_TracePointX - f_TraceDistXtail );
              /* y(x=0)       =           f_dX       *  slope + f_Y0              */
              *pfY         =   (-(f_TraceDistXtail)  * f_Slope) +  f_TraceDistYtail;
              *pfYVar      =   (-(f_TraceDistXtail)  * f_SlopeVar) + f_TraceDistYVartail;
              b_Valid = TRUE;
            }
            else
            {
              /* last segment is nearly parallel to y-axis */
              /* y-intersection does not exist */
              b_Valid = FALSE;
              *pfY    = FIPMOT_INVALID_VALUE;
              *pfYVar = FIPMOT_INVALID_VALUE;
            }
          }

        }
      }
      else
      {
        /************************************/
        /* trace HEAD is BEHIND ego vehicle */
        *pfY    = FIPMOT_INVALID_VALUE;
        *pfYVar = FIPMOT_INVALID_VALUE;
        b_Valid  = FALSE;  
      }
    }
  }
  else
  {
    /* no valid trace */
    b_Valid = FALSE;
    *pfY    = FIPMOT_INVALID_VALUE;
    *pfYVar = FIPMOT_INVALID_VALUE;
  }
  return b_Valid;
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_MOSTCompensatePoints                                                                       */ /*!

  @brief           compensate matrix for ego motion 

  @description     compensate matrix for ego motion 

  @startuml 
  Partition FIP_v_MOSTCompensatePoints
  Start
	Note right: This function compensates matrix for ego motion	
	- Update the ego motion matrices
	- Iterate through each number of sample points in trace
	- Compensate the sample points according the ego motion
  Stop
  @enduml

  @return          -

  @param[in]       iTrc : Trace ID [0...FIP_STATIC_TRACE_NO_OF_TRACES[

  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_in         FIPTrMat2DCOFFwdTgtSync : 2D Transformation matrix coefficient forward target sync [GDBTrafoMatrix2D_t as in cml_mapping.h]
  @glob_in         FIPTrMat2DCOFForJitTgtSync : 2D Transformation matrix coefficient jitter target sync [GDBTrafoMatrix2D_t as in cml_mapping.h]
  
  @glob_out        FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                    fYVar[i] : fYVar values of trace [float] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       fTracePointYStdDev : standard deviation of trace points [0... PI/2*RW_FCT_MAX]

  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             Trace has to be valid
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         12/17/2015

  @author          norman.apel@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_MOSTCompensatePoints( TraceID_t iTrc )
{
  float32 f_YJitter, f_TracePointY;
  const GDBTrafoMatrix2D_t * p_Mat = FIPGetTrafoMatrix2DCOFFwdTgtSync();
  const GDBTrafoMatrix2D_t * p_MatJitter = FIPGetTrafoMatrix2DCOFForJitTgtSync();
  sint8 s_Pt;


  /*update the ego motion matrices*/
  for (s_Pt = (sint8)0 ; s_Pt < MIN( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrc].iNumberOfPoints, (sint8)FIP_STATIC_TRACE_NO_OF_POINTS ); s_Pt++)
  {
    /* local variable to reference pointer in function */
    f_TracePointY = pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrc].fTracePointY[s_Pt];

    /* compensate */
    f_YJitter = GDBmathTrafoYPos2D( p_MatJitter , pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrc].fTracePointX[s_Pt], f_TracePointY );
    GDBmathTrafoPos2D( p_Mat,&(pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrc].fTracePointX[s_Pt]), &(f_TracePointY) );

    FIP_a_MOSTrace[iTrc].fYVar[s_Pt] += SQR(f_TracePointY-f_YJitter);

    pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrc].fTracePointYStdDev[s_Pt] = SQRT_(FIP_a_MOSTrace[iTrc].fYVar[s_Pt]);

    /* Resaving local changed variable to reference */
    pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrc].fTracePointY[s_Pt] = f_TracePointY;
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckGeneralConditionsStatic                                                               */ /*!

  @brief           check vehicle dynamic for trace calculation

  @description     check vehicle dynamic for trace calculation

  @startuml 
  Partition FIP_v_CheckGeneralConditionsStatic
  Start
  	Note right: This function checks vehicle dynamic for trace calculation	
  	- <color: GREEN > GENERAL CONDITIONS </color>
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -
                   
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!
                   
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_CheckGeneralConditionsStatic  (void)
{
  /* GENERAL CONDITIONS */
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckStaticTraceConditions                                                                 */ /*!

  @brief           check condition for traces to select for sampling

  @description     check condition for traces to select for sampling

  @startuml 
  Partition FIP_v_CheckStaticTraceConditions
  Start
	Note right: This function checks condition for traces to select for sampling
	- Iterate through each of the EM Objects	
	If (Object is moving or been stationary from moving \n and \n object is Not deleted \n and \n Life cycle of object is over or equal minimum lifecycle \n and \n Probability of existance of object is over or equal to minimum probability existance) then (True)
		If(Object is already selected for trace) then (True)
			- Create trace for that object
	  	Else (False)
			- Object already in trace list and trace conditions fulfilled
		  	- Decrement bad cycle count for that trace
	  	Endif
  	Else (False)
	  	If (Object is being traced) then (True)
	  		- Increment bad cycle count for that traces
	  		- Check if trace should be deleted
	  	Else (False)
	  	Endif
  	Endif
  - Check if trace should be declared dead trace
  Stop
  @enduml

  @return          -

  @param[in]       -
  @glob_in         *SLATE_pt_GetObjDynProperty : Dynamic property of object [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         OBJ_ARS_MOTIONATTRIBUTES(iObj).uiStoppedConfidence : confidence that indicate object is stopped from moving [ucConfidence_t as in Rte_Type.h]
  @glob_in         OBJ_MAINTENANCE_STATE : Object state like new, deleted, measured, predicted, inactive[EM_t_GenObjMaintenanceState as in Rte_Type.h]
  @glob_in         OBJ_PROBABILITY_OF_EXIST : object's probability of existence [0, 100]
  @glob_in         OBJ_GET_STATIC_TRACE_ID : Trace ID of Object [0, 10[
  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace [0...EM_N_OBJECTS[
  @glob_out        FIP_a_MOSTrace[iTrace].: Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     iBadCycles : Quality Number for hysteresis at trace deletion [0, 15]

  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING . FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/17/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_CheckStaticTraceConditions  (void)
{
  ObjNumber_t iObj;
  TraceID_t iTrace;
  boolean bTraceConditions, b_ObjIsMovingToStat;
  TraceID_t uStatTraceID;
  SLATE_t_Obj_DynamicProperty t_ObjDynamicProperty;
  AlgoCycleCounter_t u_ObjLifeCycles;

  /* OBJECT CONDITIONS */
  for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
  {
    t_ObjDynamicProperty = *SLATE_pt_GetObjDynProperty(iObj);
    /* defining local variable from reference pointer */
    uStatTraceID = (FIP_pt_GetMOTData()->u_ReferenceToStaticTrace[iObj]);
    bTraceConditions = FALSE;
    /*! The conditions for creating traces for the object as follows
     1.The Object should be in moving or in stationary state
     2.The object was moving and now stopped and if stopped confidence is above 80
     3.probability of existence of the object is greater than or equal to 99.5% */

    b_ObjIsMovingToStat = SLATE_b_GetObjIsMovingToStationary(iObj);
    if (  (t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_MOVING) || 
#if (FCT_CFG_SENSOR_TYPE_RADAR)
         ((t_ObjDynamicProperty == SLATE_OBJECT_PROPERTY_STATIONARY)   &&  (b_ObjIsMovingToStat))
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
         (b_ObjIsMovingToStat)
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
       )
    {
      if(!(SLATE_p_GetEMGenObjGeneral(iObj)->eMaintenanceState == EM_GEN_OBJECT_MT_STATE_DELETED))
      {
        u_ObjLifeCycles = SLATE_u_GetObjLifeCycles(iObj);
        if (( u_ObjLifeCycles   >=  FIP_MOST_LIFETIME_MIN   ) )
        {
          if (( SLATE_p_GetEMGenObjQualifiers(iObj)->uiProbabilityOfExistence >=  FIP_MOST_PROB_EXIST_MIN )   )
          {
            bTraceConditions = TRUE; /* if ALL conditions are not fulfilled, bTraceConditions stays FALSE */
          } /* ( OBJ_PROBABILITY_OF_EXIST(iObj)    >=  FIP_MOST_PROB_EXIST_MIN   ) */
        } /* IF ( SLATE_u_GetObjLifeCycles(iObj)   >=  FIP_MOST_LIFETIME_MIN   )  */
      } /* IF !(OBJ_MAINTENANCE_STATE(iObj) == EM_GEN_OBJECT_MT_STATE_DELETED) */
    } /* IF (*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_MOVING) || ((*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_STATIONARY)   &&  (SLATE_b_GetObjIsMovingToStationary(iObj))) */

    /* Trace creation/deletion */
    if (bTraceConditions == TRUE)
    {
      /* For current object, all trace conditions are fulfilled */
        if ( uStatTraceID  >=  FIP_u_TRACE_VALID_OBJ_ID     )
        {
          /* object not in trace list and trace conditions fulfilled (FIP_a_MOSTrace)                        */
          /* trace creation :                                                                         */
          /*  - check for free element in trace list - if none ->        do nothing  !!!!             */
          /*                                                   -> @todo: priorisation (not impl. yet) */
          /*! create a new trace */
          FIP_v_StaticTraceCreation ( iObj );
        }
        else
        {
          /* object already in trace list and trace conditions fulfilled (FIP_a_MOSTrace) */
          (FIP_a_MOSTrace[ uStatTraceID ].iBadCycles)--;
          FIP_a_MOSTrace[ uStatTraceID ].iBadCycles = MAX(  FIP_a_MOSTrace[uStatTraceID].iBadCycles
            , (sint8)0 );
        } /* END IF bTraceConditions == TRUE */
    }
    else
    {
      if ( uStatTraceID        <  FIP_u_TRACE_VALID_OBJ_ID     )
      {
        /* object is in trace list and trace conditions NOT fulfilled (FIP_a_MOSTrace)                    */
        /*! check for trace deletion                                                               */
        FIP_a_MOSTrace[ uStatTraceID ].iBadCycles++;

        FIP_a_MOSTrace[ uStatTraceID ].iBadCycles = MIN(  FIP_a_MOSTrace[ uStatTraceID ].iBadCycles
          , FIP_MOST_DEL_QUALITY_HYST_CYCLES  );
        /*Delete trace for the object, that is not fulfilled the trace condition */
        FIP_v_CheckStaticTraceDeletion ( iObj );

      }
    }
  } /* obj loop */

  /* check for dead traces (traces without objects) */
  for(iTrace = 0U ; iTrace < (TraceID_t) FIP_STATIC_TRACE_NO_OF_TRACES ; iTrace++)
  {
    if ( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject == FIP_u_TRACE_VALID_NO_OBJ_ID )
    {
      /*! trace without an object */
      FIP_v_CheckDeadStaticTraceDeletion ( iTrace );
    }
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_StaticTraceCreation                                                                        */ /*!

  @brief           creation of new moving object trace

  @description     creation of new moving object trace after selected for traces.

  @startuml 
  Partition FIP_v_StaticTraceCreation
  Start
	Note right: This function creates new moving object trace after selected for traces	
	- Iterate through each of the number of static traces
	If (Object ID of trace is greater then Trace ID occupied with object) then (True)
		- Insert trace with current object data
	Else (False)
	Endif
  Stop
  @enduml

  @return          -

  @param[in]       iObj : object ID [0...EM_N_OBJECTS[

  @glob_in         OBJ_LONG_DISPLACEMENT : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace[0...EM_N_OBJECTS[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
 
  @glob_out        FIP_a_MOSTrace[iTrace]: Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fYVar[0] : fYVar values of trace (m) [float]
                     iBadCycles : Quality Number for hysteresis at trace deletion [0, 15]
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fTracePointYStdDev : standard deviation of trace points [0... PI/2*RW_FCT_MAX]
  @glob_out        t_FIP_ObjectList[t_ObjNr] : FIP object list of object iObj with iObj in [0...EM_N_OBJECTS[
                     u_ReferenceToTrace : Trace ID of Object [0...FIP_STATIC_TRACE_NO_OF_TRACES[

  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             Object must be selected for trace creation
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_StaticTraceCreation ( ObjNumber_t iObj )
{
  TraceID_t  iTrace; 

  iTrace  = 0U;

  while ( iTrace < (TraceID_t) FIP_STATIC_TRACE_NO_OF_TRACES )
  {
    /*! @todo: prioritization needed */
    if( pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject  > FIP_u_TRACE_VALID_OBJ_ID )
    {
      /* insert trace with current object data */
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject            =  (uint8)iObj;
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToEMObject             =  SLATE_p_GetEMGenObjGeneral(iObj)->uiID;
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[0]              =  *pt_FIP_RTE_Input->pf_ObjLongDisp(iObj);
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointY[0]              =  *pt_FIP_RTE_Input->pf_ObjLatDisp(iObj);
      FIP_a_MOSTrace[iTrace].fYVar[0]  =  FIP_f_GetObjObservationVariance( (ObjNumber_t) pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].uiReferenceToFCTObject );
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointYStdDev[0]      =  SQRT_(FIP_a_MOSTrace[iTrace].fYVar[0]);
      pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints      =  ((sint8)1);
      FIP_a_MOSTrace[iTrace].iBadCycles              =  ((sint8)0);

       pt_FIP_MOT_Output->u_ReferenceToStaticTrace[iObj] =  (uint8)iTrace;

      /* to leave loop */
      iTrace   = (TraceID_t) FIP_STATIC_TRACE_NO_OF_TRACES;

      /*! @todo: variance should be implemented */
    }
    iTrace++;
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckStaticTraceDeletion                                                                   */ /*!

  @brief           conditions for deletion of moving object trace when object conditions for tracing are not fulfilled any more

  @description     conditions for deletion of moving object trace when object conditions for tracing are not fulfilled any more

  @startuml 
  Partition FIP_v_CheckStaticTraceDeletion
  Start
	Note right: This function checks conditions for deletion \n of moving object trace when object conditions \n for tracing are not fulfilled any more	
	If(Trace has samples) then (True)
  		If(Length of trace is less than length for trace deletion¬ \n AND \n Last sample is infront of ego vehicle \n OR \n Bad cycle count is over cycles for trace deletion) then (True)
  			- Delete the trace by initializing the trace structure
  		Else(False)
  		Endif
 	Else(False)
		- Delete the trace by initializing the trace structure
  	Endif 
  Stop
  @enduml

  @return          -

  @param[in]       object ID [0...EM_N_OBJECTS[

  @glob_in         *(FIP_pu_GetStaticTraceID(iObj)) : Trace ID of Object [0...EM_N_OBJECTS[
  @glob_in         FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     iBadCycles : Quality Number for hysteresis at trace deletion [0, 15]
  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

  @author          david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_CheckStaticTraceDeletion ( ObjNumber_t iObj )
{
  /* defining local variable from reference pointer */
  TraceID_t  u_DelTrace =  (FIP_pt_GetMOTData()->u_ReferenceToStaticTrace[iObj]);
  sint8 s_NbofPoints = pt_FIP_MOT_Output->t_MovObjStaticTrace[(sint32)u_DelTrace].iNumberOfPoints;

  if( s_NbofPoints > 0 )
  {
    if (  (  ( FIP_a_MOSTrace[ (sint32)(u_DelTrace) ].fLength     <  FIP_MOST_DEL_LENGTH              )
      && ( pt_FIP_MOT_Output->t_MovObjStaticTrace[(sint32)(u_DelTrace)].fTracePointX[s_NbofPoints-1] > 0.0f                     ) )
      || ( FIP_a_MOSTrace[ (sint32)(u_DelTrace) ].iBadCycles  == FIP_MOST_DEL_QUALITY_HYST_CYCLES ) )
    {
      /*! @todo -> EOMOT_DEL_TIME */

      FIP_v_InitMovingObjectStaticTraces ( u_DelTrace );
    }          
  }
  else
  {
    /* this should never be the case, but anyways... */ 
    FIP_v_InitMovingObjectStaticTraces ( u_DelTrace );
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_StartObjectStaticTraceDeletion                                                             */ /*!

  @brief           start trace deletion when object is deleted, trace is NOT deleted !!

  @description     start trace deletion when object is deleted, trace is NOT deleted !!

  @startuml 
  Partition FIP_v_StartObjectStaticTraceDeletion
  Start
	Note right: This function starts trace deletion when object is deleted, trace is NOT deleted	
	If(Trace has valid object ID) then (True)
  		- Declare trace a dead trace
  		- Start tracking time, without object
  	Else (False)
  	Endif 
  Stop
  @enduml

  @return          -

  @param[in]       iObj : Object ID [0...EM_N_OBJECTS[

  @glob_in         *(FIP_pu_GetStaticTraceID(iObj)) : Trace ID of Object [0...EM_N_OBJECTS[
  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : moving object stactic traces structure of trace iTrace with iTrace in [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Trace [0...EM_N_OBJECTS[
  @glob_out        FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fTraceWithoutObjTime : time since object has been deleted [float] s
 
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             Object should be selected for trace
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

@author           david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_StartObjectStaticTraceDeletion (ObjNumber_t iObj )
{
  /* defining local variables from reference pointer */
  uint8 u_MOTID = (FIP_pt_GetMOTData()->u_ReferenceToStaticTrace[iObj]); /* static trace ID for given FCT object */

  /* object is deleted -> start trace holding and deletion */
  /*!@todo : TRACE_VALID_NO_OBJ_ID can be removed here ... just for safety */
  if(  (u_MOTID < FIP_u_TRACE_VALID_OBJ_ID   )
    &&(u_MOTID < FIP_u_TRACE_VALID_NO_OBJ_ID)
    )
  {
    /* start time without obj. measurement */
    pt_FIP_MOT_Output->t_MovObjStaticTrace[u_MOTID].uiReferenceToFCTObject  = FIP_u_TRACE_VALID_NO_OBJ_ID;
    FIP_a_MOSTrace[u_MOTID].fTraceWithoutObjTime                            = 0.0f;
    pt_FIP_MOT_Output->u_ReferenceToStaticTrace[iObj]                       = (TraceID_t) FIP_u_TRACE_INVALID_ID;

  }
  else
  {
    /* no trace of this obj -> do nothing */
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */

#if (FCT_CFG_USE_FCT_STATIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_v_CheckDeadStaticTraceDeletion                                                             */ /*!  

  @brief           conditions for deletion of 'dead' moving object trace (without an object)

  @description     conditions for deletion of 'dead' moving object trace (without an object)

  @startuml 
  Partition FIP_v_CheckDeadStaticTraceDeletion
  Start
	Note right: This function checks conditions for deletion of 'dead' moving object trace (without an object)	
	If(Length of trace is below length for trace deletion \n OR \n Trace has been dead trace for time for trace deletion \n OR \n Last sample is infront of ego vehicle \n AND \n Trace is below Maximum number of sample trace points in each trace) then (True)
  		- Delete the trace
  	Else (False)
		- Kepp trace without object
  		- Increment time of being dead trace by cycle time
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       iTrace : Trace ID [0...FIP_STATIC_TRACE_NO_OF_TRACES[
  
  @glob_in         FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                     fLength : length of trace [float] m
                     fTraceWithoutObjTime : time since object has been deleted [float] s
  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Static module output
                     t_MovObjStaticTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                       iNumberOfPoints : Number of sample points in trace [0...FIP_STATIC_TRACE_NO_OF_POINTS[
                       fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_STATIC_TRACE_NO_OF_POINTS[
  
  
  @glob_out        FIP_a_MOSTrace[iTrace] : Moving Object Traces of trace iTrace with iTrace [0 ... FIP_STATIC_TRACE_NO_OF_TRACES[
                    fTraceWithoutObjTime : time since object has been deleted [float] s

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES 
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT, irrespective of where they are computed!

  @pre             -
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/18/2015

@author           david.kubera@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_CheckDeadStaticTraceDeletion ( TraceID_t iTrace )
{
  /* delete the trace in one of the following cases:  */
  /* trace is short                                   */
  /* object corresponding to trace was deleted long time ago */
  /* trace tail hasn't reached ego vehicle yet (except if trace has maximal length) */
  if (  ( FIP_a_MOSTrace[ iTrace ].fLength              < FIP_MOST_DEAD_DEL_LENGTH )
    ||( FIP_a_MOSTrace[ iTrace ].fTraceWithoutObjTime > FIP_MOST_DEAD_DEL_TIME   )
    ||(  (pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].fTracePointX[pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints-1] > 0.0f)
    &&(pt_FIP_MOT_Output->t_MovObjStaticTrace[iTrace].iNumberOfPoints < FIP_STATIC_TRACE_NO_OF_POINTS) ) )
  {
    /*! delete trace */
    FIP_v_InitMovingObjectStaticTraces ( iTrace );
  }
  else
  {
    /*! keep trace without object */
    FIP_a_MOSTrace[ iTrace ].fTraceWithoutObjTime += (float32)SLATE_f_GetCPCycleTime();
  }
}
#endif /* END IF (FCT_CFG_USE_FCT_STATIC_TRACES) */
///@}
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */
