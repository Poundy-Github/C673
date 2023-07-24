/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_dynamic_traces.c

DESCRIPTION:               ACC FIP object dynamic traces processing module

AUTHOR:                    Patel Chirag (uidr6458)

CREATION DATE:             6/1/2016

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip_object_traces.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/


#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_dynamic_traces FIP Dynamic Traces
@ingroup fip_object_traces
@brief          Main file for Processing the dynamic traces of objects. \n\n

@{

*/
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/
/* CRITERIA FOR DYNAMIC TRACE CREATION */
/*! minimum lifetime cycles of obj. */
#define FIPMOT_LIFETIME_MIN              CONV_CYCLES_TO_LIFETIME(7U)
/*! minimum probability of existence */
#define FIPMOT_PROB_EXIST_MIN            (99)
/*! minimum obstacle probability */
#define FIPMOT_OBST_PROB_MIN             ((percentage_t)85) 
/*! maximum Y intersection gradient */
#define FIPMOT_VALID_MAXYISGRAD    (0.03f)
/*! maximum Y intersection delta in mm */
#define FIPMOT_VALID_YISDELTA      (0.75f)
/*! Angle between Dynamic Trace segment and X-axis in degree*/
#define FIPMOT_VALID_ANGLEVAR      (25.0f)
/*!Max Angle between Dynamic Trace segment and X-axis in degree*/
#define FIPMOT_VALID_MAXANGLE       (8.5f)
/*!Max variance of dynamic trace segment to curve*/
#define FIPMOT_VALID_MAXVAR2CURVE   (0.5f)

/*! length [m] for dynamic trace deletion when dynamic trace conditions are not fulfilled */
#define FIPMOT_DEL_LENGTH                 (25.0f)
/*! smart tracing disable flag: optimizations for straight lines using fewer points */
#define FIPMOT_DISABLE_SMART_SAMPLING       (SWITCH_ON)

#if (!FIPMOT_DISABLE_SMART_SAMPLING)
/*! maximum length for straight lines */
#define FIPMOT_MAX_STRAIGHT_LINE_LENGTH   ( 70.0f)
#endif
/*Minimum value of absolute Y intersection gradient filter*/
#define FIPMOT_MIN_ABS_YINTERSEC_GRAD_FILTR (0.003f)
/*maximum value of Y intersection delta value*/
#define FIPMOT_MAX_YINTERSEC_DELTA (0.5f)
/*! length [m] for dynamic trace deletion when object is deleted */
#define FIPMOT_DEAD_DEL_LENGTH          (40.0f)
/*! time   [s] for dynamic trace deletion when object is deleted */
#define FIPMOT_DEAD_DEL_TIME            (5.0f)
/*Min points in dynamic trace for updating length */
#define FCT_TRACE_TWO_POINTS            (2)

/*! cycles for dynamic trace deletion when dynamic trace conditions are not fulfilled */
#define FIPMOT_DEL_QUALITY_HYST_CYCLES   ((sint8)15)

/*! Maximum history samples in trace*/
#define FIPMOT_HISTORY_SAMPLES   (4)

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
/*! list of Moving Object Dynamic Traces */
SET_MEMSEC_VAR(FIP_a_MODTrace)
static FIP_t_MovingObjDynTraceData  FIP_a_MODTrace[FIP_DYN_TRACE_NO_OF_TRACES];

/*****************************************************************************
FUNCTION PROTOTYPES
*****************************************************************************/
/* Checks for dead dynamic traces*/
static void FIP_v_CheckDeadDynTrace(void);
/* Checking general conditions for dynamic trace creation*/
static void FIP_v_CheckGeneralConditionsDyn(void);
/* Checking conditions for dynamic trace creation*/
static void FIP_v_CheckDynTraceConditions(void);
/* dynamic trace sampling once dynamic trace created*/
static void FIP_v_MODTSampling(void);
/* Compensating ego vehicle motion */
static void FIP_v_MODTEgoMotionCompensation(void);
/* Function to analyze the quality for the created dynamic trace, those who fulfilled the dynamic trace conditions*/
static void FIP_v_MODTQualityAnalyse(void);
/*start dynamic trace deletion when object is deleted, dynamic trace is NOT deleted !! */
static void FIP_v_StartObjectDynTraceDeletion(ObjNumber_t iObj);
/* Create the dynamic trace for the object those who fulfilled the dynamic trace conditions*/
static void FIP_v_DynTraceCreation(ObjNumber_t iObj);
/* if the dynamic trace conditions for the object not fulfilled, delete the dynamic trace*/
static void FIP_v_CheckDynTraceDeletion(ObjNumber_t iObj);
/* if the dynamic trace does not have any object in it(called dead dynamic trace), delete that dynamic trace */
static void FIP_v_CheckDeadDynTraceDeletion(TraceID_t iTrace);
/* to compensate the dynamic trace points */
static void FIP_v_MODTCompensatePoints(TraceID_t iTrc);
/* if the dynamic trace is growing more than FIP_DYN_TRACE_NO_OF_POINTS points, crop the dynamic trace */
static void FIP_v_CropDynTrace(TraceID_t iTrace);
/* to get Y axis intersection for the dynamic trace */
static boolean FIP_b_GetDynTraceYAxisIntersection(TraceID_t iTrace, float32 *pfY , float32 *pfYVar);
/* Compute the resolution/sampling interval of the individual traces */
static void FIP_v_ComputeSamplingInterval(void);

/* Initialize the dynamic trace parameters,those who fulfilled the dynamic trace conditions*/
static void FIP_v_InitMovingObjectDynTraces     ( TraceID_t iTrace );

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    FIP_v_Init_Dynamic_Traces                                                                        */ /*!

  @brief           Initialize complete moving object dynamic traces structure

  @description     Initialize complete moving object dynamic traces structure. Initialize dynamic trace parameters and resolution/sampling
                   interval. Check and assign the INVALID ID.
  
  @startuml 
    Partition FIP_v_Init_Dynamic_Traces
    Start
    	Note right: This function initializes complete \n moving object dynamic traces structure	
  	  - Depending on the available sources initialize \n the dynamic trace parameters for all of the traces
    Stop
  @enduml

  @return          -


  @glob_in         -
  @glob_out        t_FIP_ObjectList[iObj] : FIP object list of object iObj with iObj in [0...EM_N_OBJECTS[
                     u_ReferenceToDynTrace : Dynamic Trace ID of Objects [0...FIP_DYN_TRACE_NO_OF_TRACES[

  @c_switch_part   -
  @c_switch_full   Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.06.2016
  @changed         02.06.2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
void FIP_v_Init_Dynamic_Traces(void)
{
  TraceID_t iTrace;
  ObjNumber_t iObj;

  /* Initialize the dynamic trace parameters for FIP_DYN_TRACE_NO_OF_TRACES*/
  for (iTrace = 0u; iTrace < (TraceID_t)FIP_DYN_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* Initialize dynamic trace parameters*/
    FIP_v_InitMovingObjectDynTraces ( iTrace );
  }

  /*Check all Fct objects and assign INVALID ID i.e 255 before starting actual dynamic trace computation*/
  for (iObj = 0; iObj < EM_N_OBJECTS ; iObj++)
  {
    pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] = (TraceID_t)FIP_u_TRACE_INVALID_ID;
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_InitMovingObjectDynTraces                                                                     */ /*!

  @brief           initialize 1 dynamic trace structure 

  @description     initialize 1 dynamic trace structure 

  @startuml 
    Partition FIP_v_InitMovingObjectDynTraces
    Start
    	Note right: This function initializes a dynamic trace structure
    	- Depending on the available source initialize dynamic trace structure
    Stop
  @enduml

  @return          -

  @param[in]       iTrace : Dynamic Trace ID [0...FIP_DYN_TRACE_NO_OF_TRACES[

  @glob_in         FIP_DYN_TRACE_GET_FCT_ID : Object ID of Dynamic Trace [0...FIP_DYN_TRACE_NO_OF_TRACES[
  
  @glob_out        t_FIP_ObjectList[iObj] : FIP object list of object iObj with iObj in iObj with iObj in [0...EM_N_OBJECTS[
                     u_ReferenceToDynTrace : Dynamic Trace ID of Object [0...FIP_DYN_TRACE_NO_OF_TRACES[
  @glob_out        FIP_a_MODTrace[iTrace]: list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                    iBadCycles : Quality Number for hysteresis at dynamic trace deletion [0, 15]
                    fLength : length of dynamic trace [float] m
                    fYVar[0] : fYVar values of dynamic trace [float] m
                    fTraceWithoutObjTime : time since object has been deleted [float] s
                    YIntersecDelta : distance, dynamic trace has moved on the y-axis (used for quality analysis) [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                    YIntersecVar : intersection variance of dynamic trace with y-axis [0.f ... 1000.f]
                    Quality : quality of the trace
                      PointNotOnStraightLine : sample point is on straight line dynamic trace or not [0, 1]
                      ReachedEgoVeh : bit that indicate ego has reached to traced to dynamic trace sample [0, 1]
                      valid_NoShadowObj : object is shadow or not [0, 1]
                      valid_YIntersecGrad : y intersection gradient is valid or not [0, 1]
                      valid_MaxAngleGrad : Maximum angle gradient is valid or not [0, 1]
                      valid_AngleGradVar : Angle gradient variance is valid or not [0, 1]
                      valid_MeanVarMOT2Curve : Mean variance of moving object dynamic trace to curve is valid or not [0, 1]
                      valid_YIntersecDelta : Delta of y intersection is valid or not [0, 1]
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace]: FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         Legacy.YPredictedIntersec : Prediced Intersection of trace with y-axis [float] m
                         fYIntersection : Y value of intersection of trace with X-Axis [fDistance_t as in Rte_Type.h] m
                         Legacy.TraceReachEgoVeh  : Traces sample reached to ego vahicle or not [0, 1]
                         fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
  

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_InitMovingObjectDynTraces (TraceID_t iTrace )
{
  uint8 uIndex;
  /* Defining local variable from reference pointer */
  uint8 uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject;
  if ( uRefToFCTObj < FIP_u_TRACE_VALID_NO_OBJ_ID )
  {
    /* reset object data */
    pt_FIP_MOT_Output->u_ReferenceToDynTrace[uRefToFCTObj] = (uint8) FIP_u_TRACE_INVALID_ID;
  }
  /* reset dynamic trace data */
  /* Rest variables used in FIP dynamic trace computation */
  /*!set initial values for the dynamic trace structure members*/
  FIP_a_MODTrace[iTrace].fLength                = 0.0f;
  FIP_a_MODTrace[iTrace].fTraceWithoutObjTime   = -1.0f;
  FIP_a_MODTrace[iTrace].iBadCycles             = (sint8)0;
  FIP_a_MODTrace[iTrace].YIntersecDelta         = 0.0f;
  FIP_a_MODTrace[iTrace].YIntersecVar           = 0.0f;
  FIP_a_MODTrace[iTrace].Quality.ReachedEgoVeh           = 0u;
  FIP_a_MODTrace[iTrace].Quality.PointNotOnStraightLine  = 0u;
  FIP_a_MODTrace[iTrace].Quality.valid_NoShadowObj            = 0u;
  FIP_a_MODTrace[iTrace].Quality.valid_YIntersecGrad          = 0u;
  FIP_a_MODTrace[iTrace].Quality.valid_MaxAngleGrad           = 0u;
  FIP_a_MODTrace[iTrace].Quality.valid_AngleGradVar           = 0u;
  FIP_a_MODTrace[iTrace].Quality.valid_MeanVarMOT2Curve       = 0u;
  FIP_a_MODTrace[iTrace].Quality.valid_YIntersecDelta         = 0u;
  for (uIndex = 0; uIndex < FIP_DYN_TRACE_NO_OF_POINTS; uIndex++)
  {
    FIP_a_MODTrace[iTrace].fYVar[uIndex] = 0.f;
  }

  /* Rest variables used in FIP dynamic trace computation */
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject       = (uint8) FIP_u_TRACE_INVALID_ID;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToEMObject        = (uint8) FIP_u_TRACE_INVALID_ID;

  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints              = (sint8)0;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fSamplingLength              = 0.0f;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiHistorySampleHead          = FIP_DYN_TRACE_NO_OF_POINTS;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fYIntersection               = FIPMOT_INVALID_VALUE;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fYIntersectionGradFilt       = 0.0f;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].Legacy.YPredictedIntersec    = FIPMOT_INVALID_VALUE;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].Legacy.YPredictedIntersecVar = FIPMOT_INVALID_VALUE;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].Legacy.ValidForLaneMatrix    = FALSE;
  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].Legacy.TraceReachEgoVeh      = 1u;

  for (uIndex = 0; uIndex < FIP_DYN_TRACE_NO_OF_POINTS; uIndex++)
  {
    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[uIndex]       = 0.f;
    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[uIndex]       = 0.f;
    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointYStdDev[uIndex] = 0.f;
  }

}

/*************************************************************************************************************************
  Functionname:    FIP_v_CalculateMovingObjectDynamicTraces                                                                */ /*!

  @brief           main function for determination of moving object dynamic traces

  @description     main function for determination of moving object dynamic traces. It includes ego motion matrix updation, checks condition to select object for dynamic traces, 
                   Sample's object position for dynamic traces, compensate traces as per ego motion, check quality of traces.
  
  @startuml 
    Partition FIP_v_CalculateMovingObjectDynamicTraces
    Start
  	Note right: This is the main function for computing moving object dynamic traces	
  	- Check for dead traces. It should be called before Dynamic Trace \n creation so it freezes FCT object ID to be selected as another trace
  	- Check conditions for creation, deletion and holding of dynamic traces
  	- Compute resolution/sampling interval for individual traces
  	- Sampling of dynamic traces: adding new sampling points
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
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             Traces structure should be initialized
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
void FIP_v_CalculateMovingObjectDynamicTraces (void)
{
  uint8 i = 0;
  bool_t b_ret = 0;

  /*Check for dead traces. It should be called before Dynamic Trace creation so it frees FCT object ID to be selected as another trace*/
  FIP_v_CheckDeadDynTrace();

  /*! Check conditions for creation, deletion and holding of dynamic traces */
  FIP_v_CheckDynTraceConditions ();

  /*! Compute resolution/sampling interval for individual traces */
  FIP_v_ComputeSamplingInterval();
  
  /*! Sampling of dynamic traces: adding new sampling points */
  FIP_v_MODTSampling ();

  /*! EGO motion compensation and shifting of sample points simultaneously */
  FIP_v_MODTEgoMotionCompensation ();

  /*! Quality analysis of dynamic traces */
  FIP_v_MODTQualityAnalyse();

  /*Calculate Y axis intersection of all Traces */
  for(i = 0u; i<FIP_DYN_TRACE_NO_OF_TRACES; i++) 
  {
    b_ret = FIP_b_GetDynTraceYAxisIntersection(i, &t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].Legacy.YPredictedIntersec,&t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].Legacy.YPredictedIntersecVar);
  }

  _PARAM_UNUSED(b_ret);
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CheckDeadDynTrace                                                                             */ /*!

  @brief           Checks if Dynamic Trace is dead Trace

  @description     Checks if object associated with the Dynamic Trace is deleted. If it is deleted then this function will declare Dynamic Trace a dead Trace.

  @startuml 
  Partition FIP_v_CheckDeadDynTrace
  Start
	Note right: This function checks if object associated with the Dynamic Trace is deleted \n If it is deleted then this function will declare dynamic Trace a dead Trace
	- Iterate through all the number of dynamic traces
	If (FCT Object ID of a Trace is less than Vaid Trace ID without Object)
		If (Object ID state is new \n OR \n EM ID of object is different \n from SLATE Object ID) then (True)
  			- Object is not in list \n Declare dynamic trace as dead trace
			Note right: If the object in the dynamic trace is deleted, \n but the dynamic trace is not deleted, then delete the dynamic trace
  		else (False)
		Endif
	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                          uiReferenceToFCTObject : Getting FCT Object ID of a Dynamic Trace [0-EM_N_OBJECTS-1, TRACE_VALID_NO_OBJ_ID]
                          uiReferenceToEMObject : Getting EM Object ID of a Dynamic Trace [0-99, TRACE_VALID_NO_OBJ_ID]
  @glob_in         OBJ_IS_NEW : Indicate the administration state of object [0, 5]
  @glob_in         OBJ_GENERAL[i].uiID : EM object ID of FCT Object ID i [0-99] with i in [0...EM_N_OBJECTS[

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01/06/2016
  @changed         01/06/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_CheckDeadDynTrace(void)
{
  TraceID_t iTrace;
  /* Defining local variable from reference pointer */
  uint8 uRefToFCTObj;

  for (iTrace = 0U; iTrace < (TraceID_t)FIP_DYN_TRACE_NO_OF_TRACES ; iTrace++)
  {
    uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject;
    if ( uRefToFCTObj  < TRACE_VALID_NO_OBJ_ID )  
    {
      if((SLATE_b_GetObjIsNew(uRefToFCTObj)) || (t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToEMObject != OBJ_GENERAL(uRefToFCTObj).uiID)) // SLATE_b_GetObjIsDeleted(uRefToFCTObj)
      {
        /*if the object in the dynamic trace is deleted, but the dynamic trace is not deleted, then delete the dynamic trace*/
        FIP_v_StartObjectDynTraceDeletion ((ObjNumber_t)uRefToFCTObj);
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_ComputeSamplingInterval                                                                          */ /*!

  @brief           Compute resolution/sampling interval for individual traces

  @description     Compute resolution/sampling interval for individual traces. This is intended to dynamic in the sense that
                   it will be a function of the object distance, VREL, type of ROAD and other factors. 
                   At the moment however it is hard-coded to 5m.
  
  @startuml 
    Partition FIP_v_ComputeSamplingInterval
    Start
  	Note right: This function computes resolution/sampling interval for individual traces
  	- Iterate through each number of dynamic traces	
  	- Set Moving Dynamic Trace Sampling length for all Traces
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         fSamplingLength : Sampling length of trace [0 ... 5*RW_FCT_MAX] m
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module
                   
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         5/25/2016
  @changed         5/25/2016

  @todo            Implement this function

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_ComputeSamplingInterval(void)
{
  TraceID_t iTrace;

  for (iTrace = 0u; iTrace < (TraceID_t)FIP_DYN_TRACE_NO_OF_TRACES ; iTrace++)
  {
    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fSamplingLength = FIP_MOST_SAMPLING_LENGTH;
  }

}


/*************************************************************************************************************************
  Functionname:    FIP_v_MODTSampling                                                                                   */ /*!

  @brief           creation/replacing of supporting points of object dynamic trace

  @description     creation/replacing of supporting points of object dynamic trace

  @startuml 
  Partition FIP_v_MODTSampling
  Start
	Note right: This function creates/replaces supporting points of object dynamic trace
	- Iterate through each number of dynamic traces	
	If(Trace has valid object) then (True)
  		- Calculate distance between last point of trace and current position of object
  		If (Distance is greater than square of Sampling length) then (True)
			- SAMPLING distance reached -> add/replace point
  			If(New point is nearer than last trace point) then (True)
  				- Delete dynamic trace
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

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
                         fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         OBJ_LONG_DISPLACEMENT : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  
  @glob_out        FIP_a_MODTrace[iTrace] :  list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     Quality : quality of the trace
                       PointNotOnStraightLine : sample point is on straight line dynamic trace or not [0, 1]
                     fYVar[0] : fYVar values of dynamic trace [float] m
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         fTracePointYStdDev[i] : standard deviation of dynamic trace point i [0... PI/2*RW_FCT_MAX]
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointX[i] : x coordinates of dynamic trace point of point i[-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[

  @c_switch_part   FIPMOT_DISABLE_SMART_SAMPLING : smart tracing disable flag: optimizations for straight lines using fewer points
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

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
static void FIP_v_MODTSampling (void)
{
#if (!FIPMOT_DISABLE_SMART_SAMPLING)
  bool_t    bStraightLine;
#endif
  TraceID_t iTrace;
  float32     fDistanceSqr, f_SamplingInterval;
  uint8 uRefToFCTObj;
  sint8 iNumberOfPoints;

  for (iTrace = 0U; iTrace < (TraceID_t)FIP_DYN_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* Defining local variables for reference pointer */
    iNumberOfPoints= t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints;
    uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject;
    if ( uRefToFCTObj  < TRACE_VALID_NO_OBJ_ID )  
    {
      f_SamplingInterval = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fSamplingLength;
      /* NORMAL tracing with an active object -> sampling */
      fDistanceSqr =  SQR ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0] - (*pt_FIP_RTE_Input->pf_ObjLongDisp(uRefToFCTObj)) )
        + SQR ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[0] - (*pt_FIP_RTE_Input->pf_ObjLatDisp(uRefToFCTObj)) ) ;

      if (fDistanceSqr > SQR(f_SamplingInterval) )
      {
        /* SAMPLING distance reached -> add/replace point */

        /*!@todo only allow traces as function from X (y=f(x)), if extension is needed remove deletion here */
        if ( (iNumberOfPoints  >= 1 )
          &&(*pt_FIP_RTE_Input->pf_ObjLongDisp( uRefToFCTObj )  <=  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[ 0 ]  )
          )
        {
          /*! new point is nearer than last one -> delete dynamic trace */
          FIP_v_InitMovingObjectDynTraces (iTrace);
        }
        else
        {
          /* ADD new supporting point */

          /*! check if new point fit to an straight line */
#if (FIPMOT_DISABLE_SMART_SAMPLING)
          /* points NOT on a STRAIGHT line */
          /* insert mode : for ego motion comp. WITH insertion */
          iNumberOfPoints ++;
          iNumberOfPoints *= ((sint8)-1);
          FIP_a_MODTrace[iTrace].Quality.PointNotOnStraightLine = 1U;
#else
          bStraightLine  = EOMOTCheckStraightLineCondition ( iTrace );
          if  ( bStraightLine  == TRUE )
          {
            /*!@ todo check if dX as approximation for real distance is enough */
            if ( fABS( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[1] - (*pt_FIP_RTE_Input->pf_ObjLongDisp( uRefToFCTObj )) ) <= FIPMOT_MAX_STRAIGHT_LINE_LENGTH )
            {
              /* points on a STRAIGHT line */
              /* replace last point with current position, because all point are on a straight line */
              t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0]    = *pt_FIP_RTE_Input->pf_ObjLongDisp( uRefToFCTObj );
              t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[0]    = *pt_FIP_RTE_Input->pf_ObjLatDisp( uRefToFCTObj );
              FIP_a_MODTrace[iTrace].fYVar[0] = FIP_f_GetObjObservationVariance( (ObjNumber_t) uRefToFCTObj );
              t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointYStdDev[0] = SQRT_(FIP_a_MODTrace[iTrace].fYVar[0]);
            }
            else
            {
              /* straight line too long .... insert new point */
              iNumberOfPoints++; 
              iNumberOfPoints *= ((sint8)-1);
            }
          }
          else
          {
            /* points NOT on a STRAIGHT line */
            /* insert mode : for ego motion comp. WITH insertion */
            iNumberOfPoints ++;
            iNumberOfPoints *= ((sint8)-1);
            FIP_a_MODTrace[iTrace].Quality.PointNotOnStraightLine = 1U;
          }
#endif
        }
      }
      else
      {
        /* do nothing ( just compensate ) */
      }
    }
    else
    {
      /* do nothing (no dynamic trace) */
    }
    /* Saving local value to reference pointer */
    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints = iNumberOfPoints;
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_MODTEgoMotionCompensation                                                                      */ /*!

  @brief           Comensate dynamic traces based on ego motion, crop unnecessary samples, calculate history head

  @description     Comensate dynamic traces based on ego motion, crop unnecessary samples, calculate history head

  @startuml 
  Partition FIP_v_MODTEgoMotionCompensation
  Start
	Note right: This function compensates dynamic traces based on ego motion	
	- Iterate through each number of dynamic traces
	If (Trace has valid object) then (True)
		If (Number of sample points in trace is greater than or equal to 0) then (True)
			- Compensate samples for ego motion
		Else (False)
			If (Number of sample points in trace is greater than number of FIP sample dynamic trace points)
				- Calculate distance between last 2 points
				- Crop length
				- Limit number of sample points in trace to number of FIP sample dynamic trace points (maximum)
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

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                          uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
                          iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
                          fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                          with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                          fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                          fTracePointYStdDev[i] : standard deviation of dynamic trace points [0... PI/2*RW_FCT_MAX]
                          with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                      fLength : length of dynamic trace [float] m
                      fYVar[i] : fYVar values of dynamic trace of point í [float]
                   with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[

  @glob_in         *pt_FIP_RTE_Input->pf_ObjLongDisp : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                    fLength : length of dynamic trace [float] m
                    fYVar[i] : fYVar values of dynamic trace of point i [float]
                   with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointYStdDev[i] : standard deviation of dynamic trace point i [0... PI/2*RW_FCT_MAX] 
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Enable Interface for Traces

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_MODTEgoMotionCompensation  (void)
{
  TraceID_t iTrace;
  float32 fDistance;
  float32 fDeltaX, fDeltaY;
  sint8 iPt;
  uint8 uRefToFCTObj;
  sint8 iNumberOfPoints;

  for (iTrace = 0U; iTrace < (TraceID_t)FIP_DYN_TRACE_NO_OF_TRACES ; iTrace++)
  {
    /* Defining local variables for reference pointer */
    uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject;
    iNumberOfPoints= t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints;
    if ( uRefToFCTObj  < FIP_u_TRACE_VALID_OBJ_ID )  
    {
      /* valid dynamic trace */
      /*! @todo check this position for deletion check */
      /* ego motion compensation */
      if ( iNumberOfPoints >= 0 )
      {
        FIP_v_MODTCompensatePoints( iTrace );
      }
      else
      {
        /* SHIFT mode : save ego motion comp. result in next array element , add new entry */

        /* cNoPts is already increased */
        /* reset mode */
        iNumberOfPoints *= -1;

        /* check for points that will be shifted out */
        if ( iNumberOfPoints > FIP_DYN_TRACE_NO_OF_POINTS )
        {
          /* list is full and will overflow */
          /* calc distance between last 2 points */
          fDeltaX = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[ FIP_DYN_TRACE_NO_OF_POINTS - 1 ] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[ FIP_DYN_TRACE_NO_OF_POINTS - 2 ];
          fDeltaY = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[ FIP_DYN_TRACE_NO_OF_POINTS - 1 ] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[ FIP_DYN_TRACE_NO_OF_POINTS - 2 ];
          fDistance = SQRT_(SQR( fDeltaX ) + SQR( fDeltaY ));
          /* crop length */
          FIP_a_MODTrace[iTrace].fLength = MAX_FLOAT( ( FIP_a_MODTrace[iTrace].fLength - fDistance ) , 0.0f);
          /* limit NoPts to max */
          iNumberOfPoints  = (sint8) FIP_DYN_TRACE_NO_OF_POINTS;
        }
        /* shift points */
        for ( iPt = (iNumberOfPoints - 1)  ; iPt >= 1 ; iPt-- )
        {
          /* shift */
          t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[iPt]   =  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[iPt-1];
          t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[iPt]   =  t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[iPt-1];
          FIP_a_MODTrace[iTrace].fYVar[iPt]=  FIP_a_MODTrace[iTrace].fYVar[iPt-1];
          t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointYStdDev[iPt] = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointYStdDev[iPt-1];
        }
		/* Saving local value to reference pointer */
		t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints = iNumberOfPoints;
        /*compensate points*/
        FIP_v_MODTCompensatePoints( iTrace );
        /* add new point */
        t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0]    = *pt_FIP_RTE_Input->pf_ObjLongDisp( uRefToFCTObj );
        t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0]    = *pt_FIP_RTE_Input->pf_ObjLatDisp( uRefToFCTObj );
        FIP_a_MODTrace[iTrace].fYVar[0] = FIP_f_GetObjObservationVariance( (ObjNumber_t) uRefToFCTObj );
        t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointYStdDev[0] = SQRT_(FIP_a_MODTrace[iTrace].fYVar[0]);
        /* update length */
        if ( iNumberOfPoints >= FCT_TRACE_TWO_POINTS)/*FCT_TRACE_TWO_POINTS*/
        {
          fDeltaX = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[ 1];
          fDeltaY = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[0] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[ 1];
          fDistance = SQRT_( SQR( fDeltaX ) + SQR( fDeltaY ) );

          FIP_a_MODTrace[iTrace].fLength += fDistance; 

        }

      }
      /*Calculate history sample head*/
      iPt = 0;
      while(iPt < iNumberOfPoints)
      {
        if(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[iPt] < 0.0f)
        {
          t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiHistorySampleHead = (uint8)iPt;
          /*To break the loop*/
          iPt = iNumberOfPoints; 
        }
        iPt++;
      }
      /* Saving local value to reference pointer */
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints = iNumberOfPoints;

      /*! delete next to last point of dynamic trace, if it's behind sensor vehicle more than FIPMOT_HISTORY_SAMPLES*/
      FIP_v_CropDynTrace ( iTrace );
    }
    else
    {
      /* no dynamic trace -> do nothing */
    }
  } /* for */
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CropDynTrace                                                                                  */ /*!

  @brief           crop dynamic trace. crop last point, if it's more than FIPMOT_HISTORY_SAMPLES sampling length behind sensor vehicle

  @description     crop dynamic trace. crop last point, if it's more than FIPMOT_HISTORY_SAMPLES sampling length behind sensor vehicle

  @startuml 
  Partition FIP_v_CropDynTrace
  Start
	Note right: This function crops dynamic trace. Crop last point, if it's more than Maximum history samples
	If (Number of sample points in trace \n is greater than Maximum history \n samples in trace + 1) then (True)	
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

  @param[in]       iTrace : Dynamic Trace ID [0...FIP_DYN_TRACE_NO_OF_TRACES[

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                       fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                       with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     fLength : length of dynamic trace [float] m

  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         fTracePointX[i] : x coordinates of dynamic trace point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_out        FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     fLength : length of dynamic trace [float] m

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_CropDynTrace ( TraceID_t  iTrace )
{

  float32 fDeltaX, fDeltaY;
  float32 fDistance;
  sint8  cNoPts;

  cNoPts = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints;

  if (cNoPts >= (FIPMOT_HISTORY_SAMPLES + 1))
  {
    /* when more than FIPMOT_HISTORY_SAMPLES points are behind ego vehicle crop dynamic trace */
    if((cNoPts - (sint8)t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiHistorySampleHead) >  FIPMOT_HISTORY_SAMPLES)
    {
      /* calc distance between last 2 points */
      fDeltaX = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[ cNoPts - 2 ] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[ cNoPts - 1 ];
      fDeltaY = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[ cNoPts - 2 ] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[ cNoPts - 1 ];
      fDistance = SQRT_( SQR( fDeltaX ) + SQR( fDeltaY ) );

      /* reset value */
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[cNoPts -1] = FIPMOT_INVALID_VALUE;
      /* decrease nr. of points */
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints = (sint8)MAX( ( cNoPts - 1 ) , 0);

      FIP_a_MODTrace[iTrace].fLength =      MAX_FLOAT( ( FIP_a_MODTrace[iTrace].fLength - fDistance ) , 0.0f);
    }
  }
  else
  {
    /* < 2 points -> nothing to crop */
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_MODTQualityAnalyse                                                                             */ /*!

  @brief           Calculate dynamic trace quality

  @description     Calculate dynamic trace quality. 
                    - Checks if dynamic trace tail has reached ego-vehicle. 
                    - check, if corresponding object is classified as truck cabin. 
                    - analyse shape of dynamic trace
                    - analyse angle between two segments. 
                    - analyse y-intersection of dynamic trace tail
  
  @startuml 
  Partition FIP_v_MODTQualityAnalyse
  Start
	Note right: This function calculates dynamic trace quality
	- Iterate throught each of the number of dynamic traces	
	If(Trace has valid object) then (True)
  		- Calculate trace has reached to ego vehicle or not
  		If(Object has moved form last cycle position \n AND \n Trace has reached to ego vehicle) then (True)
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
  				- Analyse shape of curve, by fitring a curve (y(x) = 0.5*f_C0 *x^2 + YIntersection) through minimal and maximal point on the trace;
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

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
                         fTracePointY[i] : y coordinates of dynamic trace point i [float]
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fYIntersection : Y value of intersection of trace with X-Axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/s
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS]
  @glob_in         FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     Quality : quality of the trace
                       ReachedEgoVeh : bit that indicate ego has reachd to traced to dynamic trace sample [0, 1]
                       YIntersecDelta : distance, dynamic trace has moved on the y-axis (used for quality analysis) [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         OBJ_IS_SHADOW : checks is object is shadow or not [0, 1]

  @glob_out        FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     Quality : quality of the trace
                       ReachedEgoVeh : bit that indicate ego has reachd to traced to dynamic trace sample [0, 1]
                       YIntersecDelta : distance, dynamic trace has moved on the y-axis (used for quality analysis) [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       YIntersecVar : intersection variance of dynamic trace with y-axis [0.f ... 1000.f]
                       valid_YIntersecGrad : The filtered y axis intersection gradient is valid or not [0, 1]
                       valid_YIntersecDelta : distance, dynamic trace has moved on the y-axis is valid or not [0, 1]
                       valid_AngleGradVar : angle gradiant variance is valid or not [0, 1]
                       valid_MaxAngleGrad : Max angle gradiant is valid or not [0, 1]
                       valid_MeanVarMOT2Curve : Mean variance from dynamic trace to curve is valis or not[0, 1]
                       valid_NoShadowObj : object is shadow or not [0, 1]
  @glob_out        FIP_DYN_TRACE_REACHED_EGO_VEH : bit that indicate ego has reachd to traced to dynamic trace sample [0, 1]
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         fYIntersectionGradFilt : The filtered y axis intersection gradient [float] m/
                         fYIntersection : Y value of intersection of trace with X-Axis [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          nele.hanel@contiautomotive.com
*************************************************************************************************************************/
static void FIP_v_MODTQualityAnalyse(void)
{
  float32 f_tempYIntersection = FIPMOT_INVALID_VALUE, f_tempYIntersectionVar, f_tempGradient;
  float32 a_Angle[FIP_DYN_TRACE_NO_OF_POINTS];             
  float32 a_AngleGradient[FIP_DYN_TRACE_NO_OF_POINTS];     
  float32 f_DrivenDist, f_dX, f_dY;
  float32 f_Slope, f_C0, f_Y0;
  float32 f_temp_AngleGradVar, f_max_AngleGrad;
  float32 f_maxY, f_maxX, f_minX, f_minY, f_maxXmaxX, f_minXminX;
  float32 f_YCurve, f_temp_MeanVarMOT2Curve = 0.0f;
  bool_t b_valid;
  TraceID_t i;
  sint8 j;

  float32 f_AbsYIntersectGradFilt;  /* fABS(FCT_DYN_TRACE_GET_Y_INTERSEC_GRAD_FILT(i)) */
  float32 f_AbsYIntersectDelta;     /* fABS(FIP_a_MODTrace[i].YIntersecDelta)         */

  uint8 uRefToFCTObj;
  sint8 iNumberOfPoints;

  f_DrivenDist = SLATE_f_GetCPCycleTime() * (*pt_FIP_RTE_Input->pf_EgoVelObjSync);

  for(i = 0u; i< ( TraceID_t) FIP_DYN_TRACE_NO_OF_TRACES; i++)
  {
    /* Defining local variables for reference pointer */
    iNumberOfPoints= t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].iNumberOfPoints;
    uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].uiReferenceToFCTObject;
    if(uRefToFCTObj < (uint8)FIP_u_TRACE_INVALID_ID)
    {
      /* ----------------------------------------------------------------------------------- */
      /* check, if dynamic trace tail has reached ego-vehicle */
      /* ----------------------------------------------------------------------------------- */
      /* evaluate quality */
      FIP_a_MODTrace[i].Quality.ReachedEgoVeh = (t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointX[iNumberOfPoints-1]<0.0f)?1u:0u;

      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].Legacy.TraceReachEgoVeh = (boolean)FIP_a_MODTrace[i].Quality.ReachedEgoVeh;

      /* ----------------------------------------------------------------------------------- */
      /* analyse y-intersection of dynamic trace tail */
      /* ----------------------------------------------------------------------------------- */

      if(  (f_DrivenDist > C_F32_DELTA)
        &&(FIP_a_MODTrace[i].Quality.ReachedEgoVeh) )  /* use direct acces to the quality instead of FIP_a_MODTrace[i].Quality.ReachedEgoVeh, remove misara 12.4 */ // PRQA S 4115
      /* date: 2016-05-11, reviewer: Chirag, reason: no side effects */
      {
        b_valid = FIP_b_GetDynTraceYAxisIntersection (i, &f_tempYIntersection , &f_tempYIntersectionVar);
        if( (b_valid == TRUE)
          &&(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersection < FIPMOT_INVALID_VALUE) )
        {
          f_tempGradient = (t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersection - f_tempYIntersection)/f_DrivenDist;
          t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersectionGradFilt = ((0.8f) * t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersectionGradFilt) + ((0.2f) * f_tempGradient); 
          FIP_a_MODTrace[i].YIntersecDelta += (t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersection - f_tempYIntersection);

          f_AbsYIntersectGradFilt = fABS(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersectionGradFilt);
          f_AbsYIntersectDelta    = fABS(FIP_a_MODTrace[i].YIntersecDelta);

          if(  (f_AbsYIntersectGradFilt < FIPMOT_MIN_ABS_YINTERSEC_GRAD_FILTR)
            &&(f_AbsYIntersectDelta    > FIPMOT_MAX_YINTERSEC_DELTA) )
          {
            FIP_a_MODTrace[i].YIntersecDelta = 0.0f;
          }
          /* evaluate quality */
          FIP_a_MODTrace[i].Quality.valid_YIntersecGrad = (fABS(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersectionGradFilt)< FIPMOT_VALID_MAXYISGRAD)?1u:0u;
          FIP_a_MODTrace[i].Quality.valid_YIntersecDelta = (fABS(FIP_a_MODTrace[i].YIntersecDelta)< FIPMOT_VALID_YISDELTA)?1u:0u;
        }
        else
        {
          /* evaluate quality */
          FIP_a_MODTrace[i].Quality.valid_YIntersecGrad = 1u;
          FIP_a_MODTrace[i].Quality.valid_YIntersecDelta = 1u;
        }
        t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fYIntersection = f_tempYIntersection;
        FIP_a_MODTrace[i].YIntersecVar = f_tempYIntersectionVar;
      }
      else
      {
        /* evaluate quality */
        FIP_a_MODTrace[i].Quality.valid_YIntersecGrad = 1u;
        FIP_a_MODTrace[i].Quality.valid_YIntersecDelta = 1u;
      }

      /* ----------------------------------------------------------------------------------- */
      /* analyse angle between two segments */
      /* ----------------------------------------------------------------------------------- */
      f_temp_AngleGradVar = 0.0f; 
      f_max_AngleGrad = 0.0f;
      for(j=1; j<iNumberOfPoints; j++)
      {
        /* calculate angle between segment and x-axis */
        f_dX = ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointX[j] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointX[j-1] );
        f_dY = ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointY[j] - t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointY[j-1] );
        if(fABS(f_dX) > C_F32_DELTA)
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
      if(iNumberOfPoints>FCT_TRACE_TWO_POINTS)
      {
        f_temp_AngleGradVar = f_temp_AngleGradVar/( (float32)(iNumberOfPoints) - (float32)(FCT_TRACE_TWO_POINTS) );
      }   
      else
      {
        f_temp_AngleGradVar = 0.0f;
      }
      /* evaluate quality */
      FIP_a_MODTrace[i].Quality.valid_AngleGradVar = (fABS(f_temp_AngleGradVar)< FIPMOT_VALID_ANGLEVAR)?1u:0u;
      FIP_a_MODTrace[i].Quality.valid_MaxAngleGrad = (fABS(f_max_AngleGrad)< FIPMOT_VALID_MAXANGLE)?1u:0u;



      /* ----------------------------------------------------------------------------------- */
      /* analyse shape of dynamic trace */
      /* ----------------------------------------------------------------------------------- */
      if(iNumberOfPoints > FCT_TRACE_TWO_POINTS)
      {
        /* fit a curve (y(x) = 0.5*f_C0 *x^2 + YIntersection) through minimal and maximal point on the dynamic trace */
        f_maxY = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointY[0];
        f_minY = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointY[iNumberOfPoints-1];
        f_maxX = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointX[0];
        f_minX = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointX[iNumberOfPoints-1];
        f_maxXmaxX = f_maxX*f_maxX;
        f_minXminX = f_minX*f_minX;
        if(fABS(f_maxXmaxX - f_minXminX) > C_F32_DELTA)
        {
          f_C0 = (2.0f * (f_maxY - f_minY)) / ((f_maxXmaxX) - (f_minXminX)); // PRQA S 3121
          /* date: 2016-05-11, reviewer: Chirag, reason: used to double the value */
          f_Y0 = f_maxY - (0.5f * f_C0 * f_maxXmaxX); // PRQA S 3121
          /* date: 2016-05-11, reviewer: Chirag, reason: used to half the value */
          /* calc mean variance of dynamic trace to curve */
          f_temp_MeanVarMOT2Curve = 0.0f;
          for(j=1; j<iNumberOfPoints; j++)
          {
            f_YCurve = (0.5f * f_C0 * SQR(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointX[j])) + f_Y0; // PRQA S 3121
          /* date: 2016-05-11, reviewer: Chirag, reason: used to half the value */
            f_dY = (t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[i].fTracePointY[j] - f_YCurve);
            f_temp_MeanVarMOT2Curve += SQR(f_dY);
          }
          f_temp_MeanVarMOT2Curve /= ((float32)iNumberOfPoints);
          FIP_a_MODTrace[i].Quality.valid_MeanVarMOT2Curve = (fABS(f_temp_MeanVarMOT2Curve)< FIPMOT_VALID_MAXVAR2CURVE)?1u:0u;
        }
        else
        {
          FIP_a_MODTrace[i].Quality.valid_MeanVarMOT2Curve = 1u;
        }
      }
      else
      {
        FIP_a_MODTrace[i].Quality.valid_MeanVarMOT2Curve = 1u;
      }


      /* ----------------------------------------------------------------------------------- */
      /* check, if corresponding object is classified as truck cabin */
      /* ----------------------------------------------------------------------------------- */
      if(  (uRefToFCTObj < TRACE_VALID_NO_OBJ_ID)
        &&(SLATE_b_GetObjIsShadow( uRefToFCTObj ) == TRUE ) )
      {
        FIP_a_MODTrace[i].Quality.valid_NoShadowObj = 0u;
      }
      else
      {
        FIP_a_MODTrace[i].Quality.valid_NoShadowObj = 1u;
      }

    }
    else
    {
      /* make MISRA happy */
    }
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_b_GetDynTraceYAxisIntersection                                                                  */ /*!

  @brief           determine the intersection from dynamic trace or predicted dynamic trace with 
                   Y-axis

  @description     - if the dynamic trace has more than 1 point, 
                     then y-intersection is always the inter-/extrapolated intersection of the last dynamic trace segment
                   - if this segment is nearly parallel to the y-axis, then no valid intersection is given
                   - if the dynamic trace has only one point, 
                   - and object and dynamic trace point are separated by the y-axis, then intersection is interpolated 
                     (except they are parallel to y-axis, in that case no valid intersection is given 
                   - and object and dynamic trace point lie on the same side of the y-axis, then no valid intersection is given 
  
  @startuml 
  Partition FIP_b_GetDynTraceYAxisIntersection
  Start
	Note right: This function determines the intersection from dynamic trace or predicted dynamic trace with Y-axis	
	If(Dynamic Trace has valid object) then (True)
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

  @return          static bool_t : y intersection exists or not.

  @param[in]       iTrace : Dynamic Trace ID [0...FIP_DYN_TRACE_NO_OF_TRACES[
  @param[in,out]   *pfY : y intersection of trace [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   *pfYVar :  y intersection standard deviation [float]

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS][
                         fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         *pt_FIP_RTE_Input->pf_ObjLongDisp : object's longitudinal displacement [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT : object's latitudinal  displacement [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static boolean FIP_b_GetDynTraceYAxisIntersection (TraceID_t iTrace, float32 *pfY , float32 *pfYVar )
{
  sint8                s_Tr;
  FIP_t_MovingObjDynTraceData *p_Trace;
  float32               f_Slope
    ,f_SlopeVar
    ,f_TraceDistXhead
    ,f_TraceDistYhead
    ,f_TraceDistYVarhead
    ,f_TraceDistXtail
    ,f_TraceDistYtail
    ,f_TraceDistYVartail;
  bool_t              b_Valid;
  ObjNumber_t u_iTracedObj;
  /* Defining local variables for reference pointer */
  sint8 iNumberOfPoints = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints;
  uint8 uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject;

  p_Trace = &(FIP_a_MODTrace[iTrace]);
  b_Valid = TRUE;

  /*! @todo add dead traces , here only with object */
  /*if the dynamic trace has only one point in it.. no 'Y' intersection is possible*/
  if (  uRefToFCTObj  <  TRACE_VALID_NO_OBJ_ID )
  {
    u_iTracedObj = (ObjNumber_t)uRefToFCTObj;
    if( iNumberOfPoints == 1 )
    {
      if ( ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0] - (*pt_FIP_RTE_Input->pf_ObjLongDisp( u_iTracedObj )) ) < C_F32_DELTA )
      {
        b_Valid = FALSE;
        *pfY    = FIPMOT_INVALID_VALUE;
        *pfYVar = FIPMOT_INVALID_VALUE;
      }
    }


    /* dynamic trace valid */
    if (b_Valid == TRUE) 
    {
      /* determine Xmax point */
      /* dynamic trace has an object */ 
      f_TraceDistXhead    = *pt_FIP_RTE_Input->pf_ObjLongDisp( u_iTracedObj );
      f_TraceDistYhead    = *pt_FIP_RTE_Input->pf_ObjLatDisp( u_iTracedObj );
      /* To get the object variance over the distance traveled */
      f_TraceDistYVarhead = FIP_f_GetObjObservationVariance( u_iTracedObj );

      /* determine Xmin point */
      f_TraceDistXtail  = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[iNumberOfPoints - 1];
      f_TraceDistYtail  = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[iNumberOfPoints - 1];
      f_TraceDistYVartail  = p_Trace->fYVar[iNumberOfPoints - 1];

      if (f_TraceDistXhead >= 0.0f)
      {
        /*****************************************/
        /* dynamic trace HEAD is IN FRONT OF ego vehicle */
        if (f_TraceDistXtail > 0.0f)
        {
          /*****************************************/
          /* dynamic trace HEAD is IN FRONT OF ego vehicle */
          /* dynamic trace TAIL is IN FRONT OF ego vehicle */
          /*   -> predict/interpolate to Y-axis    */
          s_Tr = (iNumberOfPoints - 1);

          if ( iNumberOfPoints >=  FCT_TRACE_TWO_POINTS )
          {
            if(fABS(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[s_Tr-1] - f_TraceDistXtail)> C_F32_DELTA)
            {
              /*if the dynamic trace has maximum 2 points in it , find the slope 
              SLOPE = Y/X;*/
              f_Slope =  ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[s_Tr-1] - f_TraceDistYtail )
                /( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[s_Tr-1] - f_TraceDistXtail );
              f_SlopeVar = ( p_Trace->fYVar[s_Tr-1] - f_TraceDistYVartail )
                /( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[s_Tr-1] - f_TraceDistXtail );
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
            /* dynamic trace has only one point */
            /* extrapolating an y-intersection is not reasonable */
            b_Valid = FALSE;
            *pfY    = FIPMOT_INVALID_VALUE;
            *pfYVar = FIPMOT_INVALID_VALUE;
          }       
        }
        else
        {
          /*****************************************/
          /* dynamic trace HEAD is IN FRONT OF ego vehicle */
          /* dynamic trace TAIL is BEHIND      ego vehicle */
          /*   -> sample it                        */
          if (iNumberOfPoints == 1)
          {
            if(fABS(f_TraceDistXhead - f_TraceDistXtail)> C_F32_DELTA)
            {
              /* interpolate between obj and the one and only dynamic trace point */
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
              /* obj and one-and-only dynamic trace point are nearly parallel to y-axis */
              /* y-intersection does not exist */
              b_Valid = FALSE;
              *pfY    = FIPMOT_INVALID_VALUE;
              *pfYVar = FIPMOT_INVALID_VALUE;
            }
          }
          else
          {
            /* interpolate between last 2 dynamic trace points */
            s_Tr = (iNumberOfPoints - 1);
            if(fABS(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[s_Tr-1] - f_TraceDistXtail)> C_F32_DELTA)
            {
              f_Slope =  ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[s_Tr-1] - f_TraceDistYtail )
                /( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[s_Tr-1] - f_TraceDistXtail );
              f_SlopeVar = ( p_Trace->fYVar[s_Tr-1] - f_TraceDistYVartail )
                /( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[s_Tr-1] - f_TraceDistXtail );
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
        /* dynamic trace HEAD is BEHIND ego vehicle */
        *pfY    = FIPMOT_INVALID_VALUE;
        *pfYVar = FIPMOT_INVALID_VALUE;
        b_Valid  = FALSE;  
      }
    }
  }
  else
  {
    /* no valid dynamic trace */
    b_Valid = FALSE;
    *pfY    = FIPMOT_INVALID_VALUE;
    *pfYVar = FIPMOT_INVALID_VALUE;
  }
  return b_Valid;
}

/*************************************************************************************************************************
  Functionname:    FIP_v_MODTCompensatePoints                                                                           */ /*!

  @brief           compensate trace points as per matrix for ego motion 

  @description     compensate trace points as per matrix for ego motion 

  @startuml 
  Partition FIP_v_MODTCompensatePoints
  Start
	  Note right: This function compensates dynamic trace points as per matrix for ego motion	
	- Update the ego motion matrices
	- Iterate through each number of sample points in trace
	- Compensate the sample points according the ego motion
  Stop
  @enduml

  @return          static void

  @param[in]       iTrc : Dynamic Trace ID

  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         FIPTrMat2DCOFFwdTgtSync : 2D Transformation matrix coefficient forward target sync [GDBTrafoMatrix2D_t as in cml_mapping.h]
  @glob_in         FIPTrMat2DCOFForJitTgtSync : 2D Transformation matrix coefficient jitter target sync [GDBTrafoMatrix2D_t as in cml_mapping.h]
  @glob_out        FIP_a_MODTrace[iTrace] : 
                     fYVar[0] : fYVar values of dynamic trace [float] m
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         fTracePointYStdDev[i] : standard deviation of dynamic trace point i [0... PI/2*RW_FCT_MAX] 
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             Dynamic Trace has to be valid
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_MODTCompensatePoints( TraceID_t iTrc )
{
  float32 f_YJitter;
  const GDBTrafoMatrix2D_t * p_Mat = FIPGetTrafoMatrix2DCOFFwdTgtSync();
  const GDBTrafoMatrix2D_t * p_MatJitter = FIPGetTrafoMatrix2DCOFForJitTgtSync();
  sint8 s_Pt;

  /*update the ego motion matrices*/
  for (s_Pt = (sint8)0 ; s_Pt < MIN( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].iNumberOfPoints, (sint8)FIP_DYN_TRACE_NO_OF_POINTS ); s_Pt++)
  {
    /* compensate */
    f_YJitter = GDBmathTrafoYPos2D( p_MatJitter , t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].fTracePointX[s_Pt], t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].fTracePointY[s_Pt] );
    GDBmathTrafoPos2D( p_Mat,&(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].fTracePointX[s_Pt]), &(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].fTracePointY[s_Pt]) );

    FIP_a_MODTrace[iTrc].fYVar[s_Pt] += SQR(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].fTracePointY[s_Pt]-f_YJitter);

    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrc].fTracePointYStdDev[s_Pt] = SQRT_(FIP_a_MODTrace[iTrc].fYVar[s_Pt]);
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CheckDynTraceConditions                                                                       */ /*!

  @brief           check condition for dynamic traces to select for sampling

  @description     check condition for dynamic traces to select for sampling

  @startuml 
    Partition FIP_v_CheckDynTraceConditions
    Start
  	Note right: This function checks condition for dynamic traces to select for sampling
  	- Iterate through each of the EM Objects	
  	If (Object is moving or stopped \n and \n object is Not deleted \n and \n Life cycle of object is over or equal minimum lifecycle \n and \n Probability of existance of object is over or equal to minimum probability existance) then (True)
  		If(Object is already selected for trace) then (True)
  			- Create a new dynamic trace for that object
  	  	Else (False)
  			- Object already in dynamic trace list and dynamic trace conditions fulfilled
  		  	- Decrement bad cycle count for that trace
  	  	Endif
    	Else (False)
  	  	If (Object is being traced) then (True)
  	  		- Increment bad cycle count for that traces
  	  		- Delete dynamic trace parameters for the object
  	  	Else (False)
  	  	Endif
    	Endif
    - Check if trace should be declared dead trace
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         *SLATE_pt_GetObjDynProperty : Dynamic property of object [SLATE_t_Obj_DynamicProperty as in Rte_Type.h]
  @glob_in         OBJ_ARS_MOTIONATTRIBUTES(iObj).uiStoppedConfidence : confidence that indicate object is stoped from moving [ucConfidence_t as in Rte_Type.h]
  @glob_in         OBJ_MAINTENANCE_STATE : Object state like new, deleted, measured, predicted, inactive[EM_t_GenObjMaintenanceState as in Rte_Type.h]
  @glob_in         OBJ_PROBABILITY_OF_EXIST : object's probability of existance [0...100] %
  @glob_in         t_FIP_ObjectList[i] : object list of object i with i in [0...EM_N_OBJECTS[
                     u_ReferenceToDynTrace : Dynamic Trace ID of Object [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                          uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
  @glob_out        FIP_a_MODTrace[ ].iBadCycles : Quality Number for hysteresis at dynamic trace deletion [0, 15]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Enable Interface for Traces

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_CheckDynTraceConditions  (void)
{
  ObjNumber_t iObj;
  TraceID_t iTrace;
  boolean bTraceConditions;

  /* OBJECT CONDITIONS */
  for (iObj = 0; iObj < EM_N_OBJECTS; iObj++)
  {
    bTraceConditions = FALSE;
    /*! The conditions for creating dynamic traces for the object as follows
     1.The Object should be in moving or in stationary state
     2.The object was moving and now stopped and if stopped confidence is above 80
     3.probability of existence of the object is greater than or equal to 99.5% */
    if ( (*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_MOVING) || 
#if (FCT_CFG_SENSOR_TYPE_RADAR)
         ((*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_STATIONARY)   &&  (SLATE_b_GetObjIsMovingToStationary(iObj)))
#else /* !FCT_CFG_SENSOR_TYPE_RADAR */
         (SLATE_b_GetObjIsMovingToStationary(iObj))
#endif /* !FCT_CFG_SENSOR_TYPE_RADAR */
       )
    {
      if(!(OBJ_MAINTENANCE_STATE(iObj) == EM_GEN_OBJECT_MT_STATE_DELETED))
      {
        if(( SLATE_u_GetObjLifeCycles(iObj)   >=  FIPMOT_LIFETIME_MIN   ) )
        {
          if(( OBJ_PROBABILITY_OF_EXIST(iObj)    >=  FIPMOT_PROB_EXIST_MIN   )   )
          {
            bTraceConditions = TRUE; /* if ALL conditions are not fulfilled, bTraceConditions stays FALSE */
          } /* ( OBJ_PROBABILITY_OF_EXIST(iObj)    >=  FIPMOT_PROB_EXIST_MIN   ) */
        } /* IF ( SLATE_u_GetObjLifeCycles(iObj)   >=  FIPMOT_LIFETIME_MIN   )  */
      } /* IF !(OBJ_MAINTENANCE_STATE(iObj) == EM_GEN_OBJECT_MT_STATE_DELETED) */
    } /* IF (*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_MOVING) || ((*SLATE_pt_GetObjDynProperty(iObj) == SLATE_OBJECT_PROPERTY_STATIONARY)   &&  (SLATE_b_GetObjIsMovingToStationary(iObj))) */

    /* Trace creation/deletion */
    if (bTraceConditions == TRUE)
    {
      /* For current object, all trace conditions are fulfilled */
      if( pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]     >=  FIP_u_TRACE_VALID_OBJ_ID     )
      {
        /* object not in dynamic trace list and dynamic trace conditions fulfilled (FIP_a_MODTrace)                        */
        /* dynamic trace creation :                                                                         */
        /*  - check for free element in dynamic trace list - if none ->        do nothing  !!!!             */
        /*                                                   -> @todo: priorisation (not impl. yet) */
        /*! create a new dynamic trace */
        FIP_v_DynTraceCreation ( iObj );
      }
      else
      {
        /* object already in dynamic trace list and dynamic trace conditions fulfilled (FIP_a_MODTrace) */
        (FIP_a_MODTrace[ pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] ].iBadCycles)--;
        FIP_a_MODTrace[ pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] ].iBadCycles = MAX(  FIP_a_MODTrace[ pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] ].iBadCycles
          , (sint8)0 );
      } /* END IF bTraceConditions == TRUE */
    }
    else 
    {
      /* For current obj trace conditions NOT fulfilled */
      if ( pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]               <  FIP_u_TRACE_VALID_OBJ_ID     )
      {
        /* object is in dynamic trace list and dynamic trace conditions NOT fulfilled (FIP_a_MODTrace)                    */
        /*! check for dynamic trace deletion                                                               */
        FIP_a_MODTrace[ pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] ].iBadCycles++;

        FIP_a_MODTrace[ pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] ].iBadCycles = MIN(  FIP_a_MODTrace[ pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] ].iBadCycles
          , FIPMOT_DEL_QUALITY_HYST_CYCLES  );
        /*Delete dynamic trace for the object, that is not fulfilled the dynamic trace condition */
        FIP_v_CheckDynTraceDeletion ( iObj );

      } /* END IF ( pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]     <  FIP_u_TRACE_VALID_OBJ_ID     ) */
    } /* END IF (bTraceConditions == TRUE) */
  } /* END Obj Loop */

  /* check for dead traces (dynamic traces without objects) */
  for(iTrace = 0U ; iTrace < (TraceID_t) FIP_DYN_TRACE_NO_OF_TRACES ; iTrace++)
  {
    if ( t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject == TRACE_VALID_NO_OBJ_ID )
    {
      /*! dynamic trace without an object */
      FIP_v_CheckDeadDynTraceDeletion ( iTrace );
    }
  } /* END Trace Loop */
}

/*************************************************************************************************************************
  Functionname:    FIP_v_DynTraceCreation                                                                              */ /*!

  @brief           creation of new moving object dynamic trace

  @description     creation of new moving object dynamic trace after selected for traces.

  @startuml 
  Partition FIP_v_DynTraceCreation
  Start
	Note right: This function creates new moving object dynamic trace after selected for traces	
	- Iterate through each of the number of dynamic traces
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
  @glob_out        t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                       uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
                       fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                       with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
                       fTracePointY[i] : y coordinates of dynamic trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                       with i in [0...FIP_DYN_TRACE_NO_OF_POINTS
                       iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
                       fTracePointYStdDev[] : standard deviation of dynamic trace points [unsigned short]
                       u_ReferenceToDynTrace: Dynamic Trace ID of Object [0...FIP_DYN_TRACE_NO_OF_TRACES[
  @glob_out        FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                    fYVar[0] : fYVar values of dynamic trace [float] m
                    iBadCycles : Quality Number for hysteresis at dynamic trace deletion [0, 15]


  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             Object must be selected for dynamic trace creation
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_DynTraceCreation ( ObjNumber_t iObj )
{
  TraceID_t  iTrace; 
  /* Defining local variables for reference pointer */
  uint8 uRefToFCTObj;
  iTrace  = 0U;

  while ( iTrace < (TraceID_t) FIP_DYN_TRACE_NO_OF_TRACES )
  {
    uRefToFCTObj = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject;
    /*! @todo: priorisation needed */
    if( uRefToFCTObj  > FIP_u_TRACE_VALID_OBJ_ID )
    {
      /* insert dynamic trace with current object data */
      uRefToFCTObj                                =  (uint8)iObj;
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToEMObject        =  OBJ_GENERAL(iObj).uiID;
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[0]              =  *pt_FIP_RTE_Input->pf_ObjLongDisp(iObj);
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointY[0]              =  *pt_FIP_RTE_Input->pf_ObjLatDisp(iObj);
      FIP_a_MODTrace[iTrace].fYVar[0]                                                             =  FIP_f_GetObjObservationVariance( (ObjNumber_t) uRefToFCTObj );
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointYStdDev[0]        =  SQRT_(FIP_a_MODTrace[iTrace].fYVar[0]);
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints              =  ((sint8)1);
      FIP_a_MODTrace[iTrace].iBadCycles                                                           =  ((sint8)0);

      pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]   =  (uint8)iTrace;

      /* saving local variable into reference pointer */
      t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].uiReferenceToFCTObject = uRefToFCTObj;

      /* to leave loop */
      iTrace   = (TraceID_t) FIP_DYN_TRACE_NO_OF_TRACES;

      /*! @todo: variance should be implemented */
    }
    iTrace++;
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CheckDynTraceDeletion                                                                         */ /*!

  @brief           conditions for deletion of moving object dynamic trace when object conditions for tracing are not fulfilled any more

  @description     conditions for deletion of moving object dynamic trace when object conditions for tracing are not fulfilled any more

  @startuml 
    Partition FIP_v_CheckDynTraceDeletion
    Start
  	Note right: This function checks conditions for deletion \n of moving object dynamic trace when object conditions \n for tracing are not fulfilled any more	
  	If (Trace has samples) then (True)
    		If(Length of trace is less than length required for trace deletion¬ \n AND \n Last sample is infront of ego vehicle \n OR \n Bad cycle count is over threshold for trace deletion) then (True)
    			- Delete the dynamic trace by initializing the trace structure
    		Else(False)
    		Endif
   	Else(False)
  		- Delete the dynamic trace by initializing the trace structure
    	Endif 
    Stop
  @enduml

  @return          static void

  @param[in]       iObj : Object ID [0...EM_N_OBJECTS[

  @glob_in         t_FIP_ObjectList[iObj] : object list of object i with i in [0...EM_N_OBJECTS[
                      u_ReferenceToDynTrace : Dynamic Trace ID of Object [0...EM_N_OBJECTS[
  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
                         fTracePointX[i] : x coordinates of dynamic trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                         with i in [0...FIP_DYN_TRACE_NO_OF_POINTS[
  @glob_in         FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     iBadCycles : Quality Number for hysteresis at dynamic trace deletion [0, 15]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_CheckDynTraceDeletion ( ObjNumber_t iObj )
{
  sint8 s_NbofPoints = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[(sint32)(pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj])].iNumberOfPoints;
  TraceID_t u_DelTrace = pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj];
  if( s_NbofPoints > 0 )
  {
    if (((FIP_a_MODTrace[ (sint32)(pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]) ].fLength < FIPMOT_DEL_LENGTH)
      &&(t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[(sint32)(pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj])].fTracePointX[s_NbofPoints-1] > 0.0f))
        ||(FIP_a_MODTrace[ (sint32)(pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]) ].iBadCycles == FIPMOT_DEL_QUALITY_HYST_CYCLES))
    {
      /*! @todo -> EOMOT_DEL_TIME */

      FIP_v_InitMovingObjectDynTraces ( u_DelTrace );
    }          
  }
  else
  {
    /* this should never be the case, but anyways... */ 
    FIP_v_InitMovingObjectDynTraces ( u_DelTrace );
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_StartObjectDynTraceDeletion                                                                      */ /*!

  @brief           start dynamic trace deletion when object is deleted, dynamic trace is NOT deleted !!

  @description     start dynamic trace deletion when object is deleted, dynamic trace is NOT deleted !!

  @startuml 
  Partition FIP_v_StartObjectDynTraceDeletion
  Start
	Note right: This function starts trace deletion when object is deleted, dynamic trace is NOT deleted	
	If(Dynamic Trace has valid object ID) then (True)
  		- Declare dynamic trace a dead trace
  		- Start tracking time, without object
  	Else (False)
  	Endif 
  Stop
  @enduml

  @return          void

  @param[in]       iObj : Object ID [0...EM_N_OBJECTS[

  @glob_in         t_FIP_ObjectList[iObj] : object list of object i with i in [0...EM_N_OBJECTS[
                     u_ReferenceToDynTrace : Dynamic Trace ID of Object [0...EM_N_OBJECTS[
  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     uiReferenceToFCTObject : Object ID of Dynamic Trace [0...EM_N_OBJECTS[
  @glob_out        FIP_a_MODTrace[iTrace] . list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     fTraceWithoutObjTime : time since object has been deleted [float] s

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             Object should be selected for dynamic trace
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_StartObjectDynTraceDeletion (ObjNumber_t iObj )
{
  uint8 u_MODTID;
  /* object is deleted -> start dynamic trace holding and deletion */
  /*!@todo : TRACE_VALID_NO_OBJ_ID can be removed here ... just for safety */
  if(  (pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] < FIP_u_TRACE_VALID_OBJ_ID   )
    &&(pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj] < TRACE_VALID_NO_OBJ_ID)
    )
  {
    u_MODTID = pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj];
    /* start time without obj. measurement */
    t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[u_MODTID].uiReferenceToFCTObject = FIP_u_TRACE_VALID_NO_OBJ_ID;
    FIP_a_MODTrace[u_MODTID].fTraceWithoutObjTime = 0.0f;
    pt_FIP_MOT_Output->u_ReferenceToDynTrace[iObj]        = (TraceID_t) FIP_u_TRACE_INVALID_ID;
  }
  else
  {
    /* no dynamic trace of this obj -> do nothing */
  }
}


/*************************************************************************************************************************
  Functionname:    FIP_v_CheckDeadDynTraceDeletion                                                                */ /*!  

  @brief           conditions for deletion of 'dead' moving object dynamic trace (without an object)

  @description     conditions for deletion of 'dead' moving object dynamic trace (without an object)

  @startuml 
  Partition FIP_v_CheckDeadDynTraceDeletion
  Start
	Note right: This function checks conditions for deletion of 'dead' moving object dynamic trace (without an object)	
	If(Length of trace is below length for trace deletion \n OR \n Trace has been dead trace for time for trace deletion \n OR \n Last sample is infront of ego vehicle \n AND \n Trace is below Maximum number of sample trace points in each dynamic trace) then (True)
  		- Delete the dynamic trace
  	Else (False)
		- Kepp dynamic trace without object
  		- Increment time of being dead trace by cycle time
  	Endif
  Stop
  @enduml

  @return         -

  @param[in]       iTrace : Dynamic Trace ID [0...FIP_DYN_TRACE_NO_OF_TRACES[

  @glob_in         FIP_a_MODTrace[iTrace] : list of Moving Object Dynamic Traces of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                     fLength : length of dynamic trace [float] m
                     fTraceWithoutObjTime : time since object has been deleted [float] s
  @glob_in         FIP_DYN_TRACE_GET_X : x coordinates of dynamic trace point [float] m
  @glob_in         t_FIP_ALL_Output : FIP ALL output structure
                     t_FIP_MOT_Output : FIP moving object trace output structure
                       t_MovObjDynamicTrace[iTrace] : FIP moving object dynamic trace of trace iTrace with iTrace in [0...FIP_DYN_TRACE_NO_OF_TRACES[
                         iNumberOfPoints : Number of sample points in dynamic trace [0...FIP_DYN_TRACE_NO_OF_POINTS[
  
  @glob_out        FIP_a_MODTrace[iTrace].fTraceWithoutObjTime : time since object has been deleted [float] s

  @c_switch_part   -
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @pre             -
  @post            - 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         01/06/2016

  @author          Chirag Patel | Chirag.Patel-ext@continental-corporation.com
*************************************************************************************************************************/
static void FIP_v_CheckDeadDynTraceDeletion ( TraceID_t iTrace )
{
    /* Defining local variables for reference pointer */
  sint8 iNumberOfPoints = t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].iNumberOfPoints;
  /* delete the dynamic trace in one of the following cases:  */
  /* dynamic trace is short                                   */
  /* object corresponding to dynamic trace was deleted long time ago */
  /* dynamic trace tail hasn't reached ego vehicle yet (execpt if dynamic trace has maximal length) */
  if (  ( FIP_a_MODTrace[ iTrace ].fLength              < FIPMOT_DEAD_DEL_LENGTH )
    ||( FIP_a_MODTrace[ iTrace ].fTraceWithoutObjTime > FIPMOT_DEAD_DEL_TIME   )
    ||(  (t_FIP_ALL_Output.t_FIP_MOT_Output.t_MovObjDynamicTrace[iTrace].fTracePointX[iNumberOfPoints-1] > 0.0f)
    &&(iNumberOfPoints < FIP_DYN_TRACE_NO_OF_POINTS) ) )
  {
    /*! delete dynamic trace */
    FIP_v_InitMovingObjectDynTraces ( iTrace );
  }
  else
  {
    /*! keep dynamic trace without object */
    FIP_a_MODTrace[ iTrace ].fTraceWithoutObjTime += (float32)SLATE_f_GetCPCycleTime();
  }
}
///@}
#endif /*FCT_CFG_USE_FCT_DYNAMIC_TRACES*/

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
