/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                    Umesh Babu Harsha (uidj3583)

CREATION DATE:             28.09.2016

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef FIP_ACCESS_FUNC_H_INCLUDED
#define FIP_ACCESS_FUNC_H_INCLUDED

#include "fip_custom_ext.h"
#include "fip_ext.h"
#include "fip_par.h"
#include "slate_access_func.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip
@{ */

#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
ALGO_INLINE FIP_LM_Output_t const * FIP_pt_LM_GetLaneMatrixData(void);
#endif /* END IF FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING */

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
ALGO_INLINE FIP_ND_Output_t const * FIP_pt_ND_GetNaviData(void);
#endif

ALGO_INLINE FIP_OA_Output_t const * FIP_pt_GetObjAttributes(void);
ALGO_INLINE FIP_RD_Output_t const *FIP_pt_RD_GetRoadData(void);
ALGO_INLINE FIP_RT_Output_t const * FIP_pt_RT_GetRoadType(void);

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
ALGO_INLINE FIP_CC_Output_t const * FIP_pf_CC_GetCCComputation(void);
#endif /* FCT_CFG_CURVATURE_CHANGE_COMPUTATION */

ALGO_INLINE FIP_TO_Output_t const * FIP_pt_TO_GetTrafficOrientation(void);

#if (SLATE_CFG_CAM_LANE_INTERFACE)
ALGO_INLINE FIP_CL_Output_t const *FIP_pt_CL_GetCamLaneData(void);
#endif/* END IF SLATE_CFG_CAM_LANE_INTERFACE */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
#if ((FCT_CFG_USE_FCT_STATIC_TRACES) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES))
ALGO_INLINE FIP_MOT_Output_t const * FIP_pt_GetMOTData(void);
#endif
#if (FCT_CFG_USE_FCT_STATIC_TRACES)
ALGO_INLINE TraceID_t const * FIP_pu_GetStaticTraceID(const ObjNumber_t t_ObjNr);
#endif
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    FIP_pt_LM_GetLaneMatrixData                                                                           */ /*!                                                                 */ /*!

  @brief           Inline function for accessing Lane Matrix Data

  @description     Inline function for accessing Lane Matrix Data

  @return          Reference to lane width 

  @param[in]       void

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING : Config switch for FIP Lane Matrix: Need to be switched on for ACC
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)

  @pre             None
  @post            No changes

  @created         29.09.2016
  @changed         29.09.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE FIP_LM_Output_t const * FIP_pt_LM_GetLaneMatrixData(void)
{
  return &(t_FIP_ALL_Output.t_FIP_LM_Output);
}
#endif /* END IF FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING*/

#if (SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    FIP_pt_CL_GetCamLaneData                                                                           */ /*!

  @brief           Inline function for accessing Camera Lane matrix information

  @description     Inline function for accessing Camera Lane matrix information

  @return          Reference to Camera Lane matrix information

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : FCT support for CAM LANE PROCESSING : Need to be switched on for ACC

  @created         04.11.2016
  @changed         04.11.2016

  @author          Gangadhar Badiger | gangadhar.badiger-EXT@continental-corporation.com | +91 (80) 6679-6055
*************************************************************************************************************************/
ALGO_INLINE FIP_CL_Output_t const *FIP_pt_CL_GetCamLaneData(void)
{
  return &(t_FIP_ALL_Output.t_FIP_CL_Output);
}
#endif /*END IF SLATE_CFG_CAM_LANE_INTERFACE*/

/*************************************************************************************************************************
  Functionname:    FIP_pt_RD_GetRoadData                                                                            */ /*!

  @brief           Inline function for accessing the confidence of Road Data

  @description     Inline function for accessing the confidence of Road Data

  @return          Reference to Road Data structure as output of this component

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 1727277036-
*************************************************************************************************************************/

ALGO_INLINE FIP_RD_Output_t const *FIP_pt_RD_GetRoadData(void)
{
  return &(t_FIP_ALL_Output.t_FIP_RD_Output);
}
#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
/*************************************************************************************************************************
  Functionname:    FIP_pt_ND_GetNaviData                                                                         */ /*!

  @brief           Inline function for accessing the information if NAVI path is plausible

  @description     Inline function for accessing the information if NAVI path is plausible

  @return          t_FIP_ALL_Output.t_FIP_ND_Output.b_NaviPathPlausible : Reference to information if NAVI path is plausible [TRUE, FALSE]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @created         09.11.2016
  @changed         09.11.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE FIP_ND_Output_t const * FIP_pt_ND_GetNaviData(void)
{
  return &(t_FIP_ALL_Output.t_FIP_ND_Output);
}
#endif /* SLATE_CFG_SIMPLE_NAVI_INTERFACE & FCT_CFG_INPUT_PREPROCESSSING */

/*************************************************************************************************************************
  Functionname:    FIP_pt_RT_GetRoadType                                                                           */ /*!

  @brief           Inline function for accessing RoadType and Roadworks information

  @description     Inline function for accessing RoadType and Roadworks information

  @return          Reference to RoadType and Roadworks information

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @created         11.10.2016
  @changed         11.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 1727277036-
*************************************************************************************************************************/
ALGO_INLINE FIP_RT_Output_t const * FIP_pt_RT_GetRoadType(void)
{
  return &(t_FIP_ALL_Output.t_FIP_RT_Output);
}


#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
/*************************************************************************************************************************
  Functionname:    FIP_pf_CC_GetCCComputation                                                 */ /*!

  @brief           Get fused distance to high curvature change

  @description     Get fused distance to high curvature change

  @return          t_FIP_ALL_Output.t_FIP_CC_Output.f_FusedDistToHighCC : Reference to longitudinal distance to high curvature change [0.f ... RW_FCT_MAX]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC
  @c_switch_full   FCT_CFG_CURVATURE_CHANGE_COMPUTATION : FCT support for Curvature Change Computation in FIP

  @pre             -
  @post            -

  @created         24.02.2017
  @changed         24.02.2017

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
ALGO_INLINE FIP_CC_Output_t const * FIP_pf_CC_GetCCComputation(void)
{
  return &(t_FIP_ALL_Output.t_FIP_CC_Output);
}
#endif /* FCT_CFG_CURVATURE_CHANGE_COMPUTATION */

/*************************************************************************************************************************
  Functionname:    FIP_pt_TO_GetTrafficOrientation                                                                  */ /*!

  @brief           Inline function for accessing the traffic orientation

  @description     Inline function for accessing the traffic orientation

  @return          Reference to traffic orientation [full range of SLATE_t_TrafficOrientation as in slate_types.h]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC

  @pre             -
  @post            -

  @created         07.11.2016
  @changed         07.11.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 1727277036-
*************************************************************************************************************************/
ALGO_INLINE FIP_TO_Output_t const * FIP_pt_TO_GetTrafficOrientation(void)
{
  return &(t_FIP_ALL_Output.t_FIP_TO_Output);
}
#endif /* END IF FCT_CFG_INPUT_PREPROCESSSING */

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    FIP_pu_GetStaticTraceID                                                                          */ /*!

  @brief           Inline function for accessing the pointer to static trace ID for moving object

  @description     Inline function for accessing the pointer to static trace ID for moving object

  @return          Reference to pointer to static trace ID for moving object

  @param[in]       t_ObjNr : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT

  @created         21.11.2016
  @changed         21.11.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE TraceID_t const * FIP_pu_GetStaticTraceID(const ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */
  
  return &(t_FIP_ALL_Output.t_FIP_MOT_Output.u_ReferenceToStaticTrace[t_ObjNr]);
}
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

#if (FCT_CFG_USE_FCT_DYNAMIC_TRACES)
/*************************************************************************************************************************
  Functionname:    FIP_pu_GetDynamicTraceID                                                                         */ /*!

  @brief           Inline function for accessing the pointer to dynamic traces for moving object

  @description     Inline function for accessing the pointer to dynamic traces for moving object

  @return          Reference to pointer to dynamic traces for moving object

  @param[in]       t_ObjNr : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_USE_FCT_DYNAMIC_TRACES : Switch for enabling or disabling FCT Computed Dynamic Traces in FIP module

  @created         21.11.2016
  @changed         21.11.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE TraceID_t const * FIP_pu_GetDynamicTraceID(const ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));

  return &(t_FIP_ALL_Output.t_FIP_MOT_Output.u_ReferenceToDynTrace[t_ObjNr]);
}
#endif /* END IF (FCT_CFG_USE_FCT_DYNAMIC_TRACES) */

#if ((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) || (FCT_CFG_USE_FCT_DYNAMIC_TRACES) || (FIP_CFG_USE_EGO_TRACE) || (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES))
/*************************************************************************************************************************
  Functionname:    FIP_pt_GetMOTData                                                                          */ /*!

  @brief           Inline function for accessing the pointer to static trace ID for moving object

  @description     Inline function for accessing the pointer to static trace ID for moving object

  @return          Reference to pointer to static trace ID for moving object

  @param[in]       t_ObjNr : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FIP_ACCESS_FUNC_H_INCLUDED : Configuration switch for access to FIP inline functions
  @c_switch_full   FCT_CFG_USE_FCT_STATIC_TRACES : Switch for Enabling or disabling FCT Computed Traces in FIP module, ATTENTION this is mutually exclusive with SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING : FCT support for Object Trace Preprocessing (FIP) and using Traces in FCT

  @created         21.11.2016
  @changed         21.11.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE FIP_MOT_Output_t const * FIP_pt_GetMOTData(void)
{
  return &(t_FIP_ALL_Output.t_FIP_MOT_Output);
}
#endif /* END IF (FCT_CFG_OBJECT_TRACE_PREPROCESSSING) */

#if (FCT_CFG_INPUT_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    FIP_pt_GetObjAttributes                                                                    */ /*!

  @brief           Inline function for getting Camera based object width 

  @description     Inline function for getting Camera based object width 

  @return          t_FIP_ALL_Output.t_FIP_OA_Output : Reference to object attributes

  @param[in]       t_ObjNr : object number [0 ... EM_N_OBJECTS]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_full   FCT_CFG_CAMERA_CUTIN_POTENTIAL :Camera based cut-in probability for ooi lane association or,
  @c_switch_full   FCT_CFG_CAMERA_CUTOUT_POTENTIAL : Camera based cut-out probability for ooi lane association

  @pre             -
  @post            -

  @created         25.04.2017
  @changed         -

  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 69 67869 6110
*************************************************************************************************************************/
ALGO_INLINE FIP_OA_Output_t const * FIP_pt_GetObjAttributes(void)
{
  return &(t_FIP_ALL_Output.t_FIP_OA_Output);
}
#endif

///@}
#endif /* END IF FIP_ACCESS_FUNC_H_INCLUDED */
