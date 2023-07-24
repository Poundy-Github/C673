/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

PACKAGENAME:               cp_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                    Umesh Babu Harsha (uidj3583)

CREATION DATE:             30.09.2016

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef CP_ACCESS_FUNC_H_INCLUDED
#define CP_ACCESS_FUNC_H_INCLUDED

#include "cp_custom_ext.h"
#include "cp_ext.h"
#include "slate_access_func.h"
#include "cp_par.h"

#if (FCT_CFG_COURSE_PREDICTION)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp
@{ */

/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
ALGO_INLINE CP_t_TrajectoryData * CP_pt_GetTrajectoryData(void);
ALGO_INLINE CP_t_TrajectoryState  * CP_pt_GetTrajectoryState(void);
ALGO_INLINE CP_t_GDBTrajectoryData const * CP_pt_GetTrajectoryCurrent(void);

ALGO_INLINE fCurve_t const * CP_f_GetCourseCurve(void);
ALGO_INLINE fGradient_t const * CP_f_GetCourseCurveGradient(void);
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
ALGO_INLINE CAL_t_TracePolyL2 const * CP_pt_GetTracePoly(TraceID_t iTr);
#endif
#if defined FCT_SIMU
ALGO_INLINE CP_t_CourseData *CP_pt_GetCourseData(void);
#endif
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
ALGO_INLINE CPTraceLaneChangeInfo_t const * CP_pt_GetTraceLaneChangeInfo(const TraceID_t iTr);
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
ALGO_INLINE CP_t_TraceTrajectory * CP_pt_GetACCTraceTrajectory(void);
#endif
/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    CP_pt_GetTrajectoryData                                                                          */ /*!

  @brief           Returns Trajectory Data, accessed by SIM for SIM init

  @description     Returns Trajectory Data, used in simulation as well for resetting the variable

  @return          CP_t_TrajectoryData : trajectory data

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         11/9/2016
  @changed         11/9/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
ALGO_INLINE CP_t_TrajectoryData * CP_pt_GetTrajectoryData(void)
{
  return &(t_CP_Output.CP_TrajectoryData);
}

/*************************************************************************************************************************
  Functionname:    CP_pt_GetTrajectoryState                                                                          */ /*!

  @brief           Returns Trajectory state, accessed by SIM for SIM init

  @description     Returns Trajectory state, used in simulation as well for resetting the variable

  @return          CP_t_TrajectoryState : Trajectory state

  @param[in]       - 
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         11/9/2016
  @changed         11/9/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
ALGO_INLINE CP_t_TrajectoryState  * CP_pt_GetTrajectoryState(void)
{
  return &(t_CP_Output.CP_TrajectoryData.State);
}

/*************************************************************************************************************************
  Functionname:    CP_pt_GetTrajectoryCurrent                                                                          */ /*!

  @brief           Returns Current Trajectory 

  @description     Returns Current Trajectory 

  @return          CP_pt_GetTrajectoryCurrent : Current Trajectory

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         11/9/2016
  @changed         11/9/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
ALGO_INLINE CP_t_GDBTrajectoryData const * CP_pt_GetTrajectoryCurrent(void)
{
  return &(t_CP_Output.CP_TrajectoryData.Current);
}

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_pt_GetACCTraceTrajectory                                                                          */ /*!

  @brief           Returns ACC Trace Trajectory 

  @description     Returns ACC Trace Trajectory 

  @return          CP_t_TraceTrajectory : Final ACC Trace Trajectory

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   - FCT_CFG_OBJECT_TRACE_PREPROCESSSING
  @c_switch_full   -

  @pre             -
  @post            -

  @created         11/9/2016
  @changed         11/9/2016

  @author          Sangeetha Ramesh | sangeetha.ramesh@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE CP_t_TraceTrajectory * CP_pt_GetACCTraceTrajectory(void)
{
  return &(t_CP_Output.TraceTrajectory);
}
#endif /* (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

/*************************************************************************************************************************
  Functionname:    CP_f_GetCourseCurve                                                                          */ /*!

  @brief           Returns last cycle course curve

  @description     Returns last cycle course curve

  @return          t_CP_Output.CP_CourseData.fCurve : Reference to  last cycle course curve  

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         11/11/2016
  @changed         11/11/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
ALGO_INLINE fCurve_t const * CP_f_GetCourseCurve(void)
{
  return &(t_CP_Output.CP_CourseData.fCurve);
}

/*************************************************************************************************************************
  Functionname:    CP_f_GetCourseCurveGradient                                                                          */ /*!

  @brief           Returns last cycle course curve gradient

  @description     Returns last cycle course curve gradient

  @return          t_CP_Output.CP_CourseData.fCurveGradient : Reference to last cycle course curve gradient

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         11/11/2016
  @changed         11/11/2016

  @author          Chirag Patel | chirag.patel-ext@continental-corporation.com | +91 (80) 6679-6464
*************************************************************************************************************************/
ALGO_INLINE fGradient_t const * CP_f_GetCourseCurveGradient(void)
{
  return &(t_CP_Output.CP_CourseData.fCurveGradient);
}

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    CP_f_GetTracePoly                                                                                */ /*!

  @brief           Inline function for accessing the pointer to tracepolynomial of trace

  @description     Inline function for accessing the pointer to tracepolynomial of trace

  @return          t_CP_Output.CP_TracePoly[iTr] : Reference to pointer to tracepolynomial of trace

  @param[in]       iTr : Trace Id Number     [TraceID_t type as defined in Rte_Type.h] [0......10]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING

  @created         13.12.2016
  @changed         13.12.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE CAL_t_TracePolyL2 const * CP_pt_GetTracePoly(TraceID_t iTr)
{
  return &(t_CP_Output.CP_TracePoly[iTr]);
}
#endif

#if defined FCT_SIMU
/*************************************************************************************************************************
  Functionname:    CP_pt_GetCourseData                                                                             */ /*!

  @brief           Inline function for CP Course Data Information that is accessed by SIM

  @description     Inline function for CP Course Data Information that is accessed by SIM

  @return          Reference to CP_CourseData

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch to enable SIM Framewrok

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE CP_t_CourseData *CP_pt_GetCourseData(void)
{
  return &(t_CP_Output.CP_CourseData);
}
#endif /*FCT_SIMU*/

#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
/*************************************************************************************************************************
  Functionname:    CP_pt_GetTraceLaneChangeInfo                                                                             */ /*!

  @brief           Inline function for accessing the pointer to CP Trace Lane Change Info

  @description     Inline function for accessing the pointer to CP Trace Lane Change Info

  @return          Reference to CPTraceLaneChangeInfo_t

  @param[in]       iTr : Trace Id Number     [TraceID_t type as defined in Rte_Type.h] [0......10]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_PARALLEL_LANE_CHANGE  : Configuration switch for enabling Parallel lane change detection

  @pre             -
  @post            -

  @created         12/5/2018
  @changed         12/5/2018

  @author          Rahul Raj | Rahul.Raj@continental-corporation.com | +91 (80) 6679-7305
*************************************************************************************************************************/
ALGO_INLINE CPTraceLaneChangeInfo_t const * CP_pt_GetTraceLaneChangeInfo(const TraceID_t iTr)
{
  /* Perform range check before accessing an object */
  SLATE_ASSERT((iTr >= 0) && (iTr < FIP_STATIC_TRACE_NO_OF_TRACES));

  return &(t_CP_Output.CP_TrajectoryData.t_TraceLaneChangeInfo[iTr]);
}
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
#endif
///@}
#endif /* END IF CP_ACCESS_FUNC_H_INCLUDED */
