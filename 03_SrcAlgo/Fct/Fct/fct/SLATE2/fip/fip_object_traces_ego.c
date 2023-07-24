/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_ego_trace.c

DESCRIPTION:               Functions for creating Ego trace

AUTHOR:                    Patel Chirag (uidr6458)

CREATION DATE:             6/15/2016

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip_object_traces.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/



#if (FIP_CFG_USE_EGO_TRACE)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup fip_ego_trace FIP Ego Traces
@ingroup fip_object_traces
@brief          Main file for Processing the Ego traces of objects. \n\n

@{

*/
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/
/*Min points in trace for updating length */
#define FCT_EGO_TRACE_TWO_POINTS            (2)

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

/*****************************************************************************
FUNCTION PROTOTYPES
*****************************************************************************/
static void FIP_v_EgoTraceSampling(void);
/* Compensating ego vehicle motion */
static void FIP_v_EgoTraceMotionCompensation(void);
/* to compensate the trace points */
static void FIP_v_ETCompensatePoints(void);
/* Compute the resolution/sampling interval of the Ego trace */
static void FIP_v_ComputeEgoSamplingLength(void);

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    FIP_v_Init_Ego_Trace                                                                             */ /*!

  @brief           Intialise the Ego trace structure

  @description     All the members of Ego trace structure are intialised.

  @startuml 
    Partition FIP_v_Init_Ego_Trace
    Start
    	Note right: This function initializes the Ego trace structure	
    	- Initialize the trace parameters of Ego trace
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -

  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Ego module output
                    t_EgoTrace.iNumberOfPoints : Number of sample points in trace [0...FIP_EGO_TRACE_NO_OF_POINTS[
                    t_EgoTrace.fLength : length of trace [float] m
                    t_EgoTrace.fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                    t_EgoTrace.fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[

  @c_switch_part   -
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
void FIP_v_Init_Ego_Trace(void)
{
  uint8 uIndex;

  /* Initialize the trace parameters of Ego trace*/
  /*Intialising Ego trace with one sample of it's current position*/
  pt_FIP_MOT_Output->t_EgoTrace.iNumberOfPoints = (sint8)1; 
  pt_FIP_MOT_Output->t_EgoTrace.fLength = 0.0f;
  pt_FIP_MOT_Output->t_EgoTrace.fSamplingDistance = 0.0f;
  for (uIndex = 0; uIndex < FIP_EGO_TRACE_NO_OF_POINTS; uIndex++)
  {
    pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[uIndex] = 0.0f;
    pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[uIndex] = 0.0f;
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_CalculateEgoTrace                                                                          */ /*!

  @brief           Calculation of Ego trace

  @description     Sampling of new ego trace sample, compensation of Ego motion. freeze Ego trace data

  @startuml 
  Partition FIP_v_CalculateEgoTrace
  Start
	Note right: This function calculates Ego trace	
	- Compute resolution/sampling interval for Ego trace
	- Sampling of trace: adding new sampling points
	- EGO motion compensation and shifting of sample points simultaneously
  Stop
  @enduml

  @return          void

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             Ego trace should be intialised
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
void FIP_v_CalculateEgoTrace(void)
{
  /*! Compute resolution/sampling interval for Ego trace */
  FIP_v_ComputeEgoSamplingLength();

  /*! Sampling of trace: adding new sampling points */
  FIP_v_EgoTraceSampling ();

  /*! EGO motion compensation and shifting of sample points simultaneously */
  FIP_v_EgoTraceMotionCompensation ();

}

/*************************************************************************************************************************
  Functionname:    FIP_v_ComputeEgoSamplingLength                                                                   */ /*!

  @brief           Compute resolution/sampling interval for Ego trace

  @description     Compute resolution/sampling interval for Ego trace. This is intended to dynamic in the sense that
                   it will be a function of the differnet factors. 
                   At the moment however it is hard-coded to 5m.
  
  @startuml 
    Partition FIP_v_ComputeEgoSamplingLength
    Start
  	Note right: This function computes resolution/sampling interval for Ego trace	
  	- Set sampling length for Ego traces
    Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Ego module output
                     t_EgoTrace.fSamplingDistance : Ego trace sampling length [0, full range of float in positive size] m
                   
  @c_switch_part   -
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module
                   
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @todo            Implement this function

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_ComputeEgoSamplingLength(void)
{
  pt_FIP_MOT_Output->t_EgoTrace.fSamplingDistance = FIP_MOST_SAMPLING_LENGTH; /*Constant sampling length of static object traces*/
}

/*************************************************************************************************************************
  Functionname:    FIP_v_EgoTraceSampling                                                                           */ /*!

  @brief           Check of new sample point generation for Ego trace

  @description     Check of new sample point generation for Ego trace

  @startuml 
  Partition FIP_v_EgoTraceSampling
  Start
	Note right: This function checks new sample point generation for Ego trace	
	- Get sampling distance
  	- Calculate distance between last point of trace and current position of ego
  	If (Distance is over square of sampling distance) then (True)
		- SAMPLING distance reached. Add/replace point
	Else (False)
  	Endif
  Stop
  @enduml

  @return          -

  @param[in]       -
  
  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Ego module output
                     t_EgoTrace.fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
  @glob_out        pt_FIP_MOT_Output :  Reference to Object Traces Ego module output
                     t_EgoTrace.iNumberOfPoints : number of points in trace [0, FIP_EGO_TRACE_NO_OF_POINTS[
  
  @c_switch_part   -
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             Ego Trace should be intialised
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_EgoTraceSampling (void)
{
  float32 fDistanceSqr;
  float32 f_SamplingInterval;

  /*Get sampling length*/
  f_SamplingInterval = pt_FIP_MOT_Output->t_EgoTrace.fSamplingDistance;

  /* Calculate distance from last sample point */
  fDistanceSqr = SQR(pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[0]) + SQR(pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[0]);

  if (fDistanceSqr > SQR(f_SamplingInterval))
  {
    /* SAMPLING distance reached -> add/replace point */
    pt_FIP_MOT_Output->t_EgoTrace.iNumberOfPoints++;      
    /*Negative value of trace point indicate to insert new point during compensation*/
    pt_FIP_MOT_Output->t_EgoTrace.iNumberOfPoints *= ((sint8)-1); 
  }
}
/*************************************************************************************************************************
  Functionname:    FIP_v_EgoTraceMotionCompensation                                                                 */ /*!

  @brief           Compensate trace based on ego motion

  @description     Compensate trace based on ego motion, add new sampling point is needed

  @startuml 
    Partition FIP_v_EgoTraceMotionCompensation
    Start
  	Note right: This function compensates trace based on \n ego motion and adds new sampling point if needed
  	If (number of sample points on trace is equal to or greater than 0) then (True)
  		- Compensate trace points as per matrix of ego motion
  	Else	(False)
  		If (Number of sample points in trace is greater than number of FIP sample trace points)
  			- Calculate distance between last 2 points
  			- Crop length
  			- Limit number of sample points in trace to number of FIP sample trace points (maximum)
  			- Shift all the points to left
  			- Compensate the points for ego motion
  			- Update length for points
  		Else (False)
  		Endif
  		- Resaving local changed variable to FIP number of sample points 
  		- Delete next to last point of trace, if it's behind sensor vehicle
  	Endif
    Stop
  @enduml

  @return          -

  @param[in]       -

    @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Ego module output
                     t_EgoTrace.iNumberOfPoints : number of points in trace [0, FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fLength : length of trace in meters [0, full range of float positive side]
  @glob_out        pt_FIP_MOT_Output´: Reference to Object Traces Ego module output
                     t_EgoTrace.iNumberOfPoints : number of points in trace [0, FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fLength : length of trace in meters [0, full range of float positive side]
                     t_EgoTrace.fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
  
  @c_switch_part   
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             Ego Trace should be intialised
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_EgoTraceMotionCompensation(void)
{
  /* defining local variable from reference pointer */
  float32 f_TraceLength = pt_FIP_MOT_Output->t_EgoTrace.fLength;
  sint8 i_NumberOfPoints = pt_FIP_MOT_Output->t_EgoTrace.iNumberOfPoints;

  float32 fDistance;
  float32 fDeltaX, fDeltaY;
  sint8 iPt;

  /* ego motion compensation */
  if ( i_NumberOfPoints >= 0 )
  {
    FIP_v_ETCompensatePoints();
  }
  else
  {
    /* SHIFT mode : save ego motion comp. result in next array element , add new entry */

    /* cNoPts is already increased */
    /* reset mode */
    i_NumberOfPoints *= -1;

    /* check for points that will be shifted out */
    if ( i_NumberOfPoints > (sint8)FIP_EGO_TRACE_NO_OF_POINTS )
    {
      /* list is full and will overflow */
      /* calc distance between last 2 points */
      fDeltaX = pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[ FIP_EGO_TRACE_NO_OF_POINTS - 1 ] - pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[ FIP_EGO_TRACE_NO_OF_POINTS - 2 ];
      fDeltaY = pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[ FIP_EGO_TRACE_NO_OF_POINTS - 1 ] - pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[ FIP_EGO_TRACE_NO_OF_POINTS - 2 ];
      fDistance = SQRT_(SQR( fDeltaX ) + SQR( fDeltaY ));
      /* crop length */
      f_TraceLength = MAX_FLOAT( ( f_TraceLength - fDistance ) , 0.0f);
      /* limit NoPts to max */
      i_NumberOfPoints  = (sint8) FIP_EGO_TRACE_NO_OF_POINTS;
    }
    /* shift points */
    for ( iPt = (i_NumberOfPoints - 1)  ; iPt >= 1 ; iPt-- )
    {
      /* shift */
      pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[iPt]   =  pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[iPt-1];
      pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[iPt]   =  pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[iPt-1];
    }
    /*compensate points*/
    FIP_v_ETCompensatePoints();
    /* add new point */
    pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[0] = 0.0f;
    pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[0] = 0.0f;

    /* update length */
    if ( i_NumberOfPoints >= FCT_EGO_TRACE_TWO_POINTS)
    {
      fDeltaX = pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[0] - pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[1];
      fDeltaY = pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[0] - pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[1];
      fDistance = SQRT_( SQR( fDeltaX ) + SQR( fDeltaY ) );

      f_TraceLength += fDistance; 
    }
    /* Saving local value to reference pointer */
    pt_FIP_MOT_Output->t_EgoTrace.fLength = f_TraceLength;
    pt_FIP_MOT_Output->t_EgoTrace.iNumberOfPoints = i_NumberOfPoints;
  }
}

/*************************************************************************************************************************
  Functionname:    FIP_v_ETCompensatePoints                                                                         */ /*!

  @brief           compensate trace points as per matrix of ego motion

  @description     compensate trace points as per matrix of ego motion

  @startuml 
  Partition FIP_v_ETCompensatePoints
  Start
	Note right: This function compensates trace points as per matrix of ego motion	
	- Iterate through each of the number of sample points in each trace
	- update ego motion matrices
  Stop
  @enduml

  @return          -

  @param[in]       -

  @glob_in         pt_FIP_MOT_Output : Reference to Object Traces Ego module output
                     t_EgoTrace.iNumberOfPoints : number of points in trace [0, FIP_EGO_TRACE_NO_OF_POINTS]
                     t_EgoTrace.fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
  @glob_out        pt_FIP_MOT_Output : Reference to Object Traces Ego module output
                     t_EgoTrace.fTracePointX[i] : x coordinates of trace point i [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
                     t_EgoTrace.fTracePointY[i] : y coordinates of trace point i [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m with i in [0...FIP_EGO_TRACE_NO_OF_POINTS[
  
  @c_switch_part   -
  @c_switch_full   FIP_CFG_USE_EGO_TRACE : Switch for enabling or disabling FCT Computed Ego Trace in FIP module

  @pre             Ego Trace should be intialised
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         6/16/2016
  @changed         6/16/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
static void FIP_v_ETCompensatePoints(void)
{
  const GDBTrafoMatrix2D_t * p_Mat = FIPGetTrafoMatrix2DCOFFwdTgtSync();
  sint8 s_Pt;

  /*update the ego motion matrices*/
  for(s_Pt = (sint8)0 ; s_Pt < MIN(pt_FIP_MOT_Output->t_EgoTrace.iNumberOfPoints, (sint8)FIP_EGO_TRACE_NO_OF_POINTS); s_Pt++)
  {
    /* compensate */
    GDBmathTrafoPos2D(p_Mat,&(pt_FIP_MOT_Output->t_EgoTrace.fTracePointX[s_Pt]), &(pt_FIP_MOT_Output->t_EgoTrace.fTracePointY[s_Pt]));
  }
}

///@}
#endif /* END IF (FIP_CFG_USE_EGO_TRACE) */
