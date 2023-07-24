/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                    Umesh Babu Harsha (uidj3583)

CREATION DATE:             30.09.2016

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef LA_ACCESS_FUNC_H_INCLUDED
#define LA_ACCESS_FUNC_H_INCLUDED

#include "la_custom_ext.h"
#include "la_ext.h"
#include "la_par.h"
#include "slate_access_func.h"

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup la
@{ */
/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
ALGO_INLINE float32 * LA_pf_SeekLaneWidth(void);
ALGO_INLINE float32 * LA_pf_TrackLaneWidth(void);
ALGO_INLINE const float32 * LA_pf_ObjToRefDistMeas(ObjNumber_t iObj);
ALGO_INLINE const float32 * LA_pf_TrajGetObjToRefDistFiltVar(ObjNumber_t iObj);
ALGO_INLINE const float32 * LA_pf_TrajGetObjToRefDistGradFilt(ObjNumber_t iObj);
ALGO_INLINE const float32 * LA_pf_TrajGetObjToRefVarDistGradFilt(ObjNumber_t iObj);
ALGO_INLINE fDistance_t * LA_pt_GetMovingObjPickupRange(void);
ALGO_INLINE fDistance_t * LA_pt_GetMovingObjBasePickUpRange(void);
ALGO_INLINE float32 * LA_pf_GetfRangeFac(void);
ALGO_INLINE const LA_t_BasePreselObjList * LA_pt_GetBasePreselectionState(ObjNumber_t iObj);
ALGO_INLINE LA_t_ObjLaneState * LA_pt_GetLAObjLaneState(ObjNumber_t iObj);
ALGO_INLINE const LAObjOutput_t * LA_pt_GetLAObjOutputList(ObjNumber_t iObj);
#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
ALGO_INLINE const uint8 * LA_pu_GetCameraBasedCutInPotential(ObjNumber_t iObj);
#endif
#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
ALGO_INLINE const uint8 * LA_pu_GetCameraBasedCutOutPotential(ObjNumber_t iObj);
#endif

#ifdef FCT_SIMU
ALGO_INLINE CAL_t_TrajRefPoint * LA_pt_AccessTrajRefPoint(ObjNumber_t iObj);
ALGO_INLINE CAL_t_TrajRefPoint * LA_pt_AccessTrajRefPointLastCycle(ObjNumber_t iObj);
ALGO_INLINE const ObjNumber_t * LA_pt_GetNearBlockedObject(void);
ALGO_INLINE const ObjNumber_t * LA_pt_GetFarBlockedObject(void);
ALGO_INLINE const float32 * LA_pf_GetBlockedPath(void);
ALGO_INLINE const SIT_t_PathOccupation * LA_pt_GetPathOccArray(void);
#endif /* (defined(FCT_SIMU) || defined(FASTSIM)) */

ALGO_INLINE const float32 * LA_pf_GetObjDependantMaxRange(ObjNumber_t t_ObjNr);

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
ALGO_INLINE LA_t_ScaleBracketState * LA_pt_ScaleBracketState(void);
#endif
ALGO_INLINE const eAssociatedLane_t * LA_pt_GetObjFuncLane(ObjNumber_t iObj);
ALGO_INLINE const eAssociatedLane_t * LA_pt_GetObjAssociatedLane(ObjNumber_t iObj);

ALGO_INLINE const fTime_t  * LA_pt_GetPredTimeThreshold(ObjNumber_t t_ObjNr);
ALGO_INLINE const fTime_t  * LA_pt_GetTotalTimeToInlap(ObjNumber_t t_ObjNr);
ALGO_INLINE const fTime_t  * LA_pt_GetTotalTimeToInlapDrop(ObjNumber_t t_ObjNr);
ALGO_INLINE const float32  * LA_pt_GetDistanceToInlap(ObjNumber_t t_ObjNr);
ALGO_INLINE const float32  * LA_pt_GetDistanceToInlapDrop(ObjNumber_t t_ObjNr);
ALGO_INLINE const float32  * LA_pt_GetTotalDistanceToInlap(ObjNumber_t t_ObjNr);
ALGO_INLINE const float32  * LA_pt_GetTotalDistanceToInlapDrop(ObjNumber_t t_ObjNr);
ALGO_INLINE const float32  * LA_pf_GetObjectInlap(ObjNumber_t t_ObjNr);

/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    LA_pf_SeekLaneWidth                                                                              */ /*!

  @brief           Inline function to get flobal seek lane width variable

  @description     Inline function to get flobal seek lane width variable

  @return          &(t_LA_Output.f_LA_SeekLaneWidth) : Reference to global seek lane width variable

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @created         10/28/2016
  @changed         10/28/2016

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE float32 * LA_pf_SeekLaneWidth(void)
{
  return &(t_LA_Output.f_LA_SeekLaneWidth);
}

/*************************************************************************************************************************
  Functionname:    LA_pf_TrackLaneWidth                                                                             */ /*!

  @brief           Inline function to get global track lane width variable
  @description     Inline function to get global track lane width variable

  @return          &(t_LA_Output.f_LA_TrackLaneWidth) : Reference to global track lane width variable

  @param[in]       void : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @created         10/28/2016
  @changed         10/28/2016

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE float32 * LA_pf_TrackLaneWidth(void)
{
  return &(t_LA_Output.f_LA_TrackLaneWidth);
}

#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )

/*************************************************************************************************************************
  Functionname:    LA_pt_ScaleBracketState                                                                          */ /*!

  @brief           Inline function to get the state of trace bracket adaption

  @description     Inline function to get the state of trace bracket adaption

  @return          &(t_LA_Output.f_LA_StateScaleBracket) : (address of ) type LA_t_ScaleBracketState defined in la_ext.h

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM  : Config switch which moves trace brackets in case of ego lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Config switch which moves trace brackets in case of no lane change
  @c_switch_full   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Config switch which moves trace brackets w.r.t. BLINKER FEATURE

  @pre             -
  @post            -

  @created         10/28/2016
  @changed         10/28/2016

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE LA_t_ScaleBracketState * LA_pt_ScaleBracketState(void)
{
  return &(t_LA_Output.f_LA_StateScaleBracket);
}
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM || \
         LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM || \
         LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/


/*************************************************************************************************************************
  Functionname:    LA_pf_ObjToRefDistMeas                                                                           */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const float32 *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/9/2016
  @changed         11/9/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_ObjToRefDistMeas(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].TrajDist.TrajDistMeas.Y.f0);
}

/*************************************************************************************************************************
  Functionname:    LA_pf_TrajGetObjToRefDistFiltVar                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const float32 *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/10/2016
  @changed         11/10/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_TrajGetObjToRefDistFiltVar(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].TrajDist.TrajDistFilt.P.f00);
}

/*************************************************************************************************************************
  Functionname:    LA_pf_ObjDistOnTraj                                                                              */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const float32 *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/10/2016
  @changed         11/10/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_ObjDistOnTraj(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].TrajDist.ObjDistOnTraj);
}

/*************************************************************************************************************************
  Functionname:    LA_pf_TrajGetObjToRefDistGradFilt                                                                */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const float32 *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/10/2016
  @changed         11/10/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_TrajGetObjToRefDistGradFilt(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].TrajDist.TrajDistFilt.X.f1);
}

/*************************************************************************************************************************
  Functionname:    LA_pf_TrajGetObjToRefVarDistGradFilt                                                             */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const float32 *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/10/2016
  @changed         11/10/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_TrajGetObjToRefVarDistGradFilt(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].TrajDist.TrajDistFilt.P.f11);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetMovingObjPickupRange                                                                    */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE fDistance_t *

  @param[in]       void : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/11/2016
  @changed         11/11/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE fDistance_t * LA_pt_GetMovingObjPickupRange(void)
{
  return &(t_LA_Output.f_LAMovingObjPickUpRange);
}


/*************************************************************************************************************************
  Functionname:    LA_pt_GetMovingObjBasePickUpRange                                                                */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE fDistance_t *

  @param[in]       void : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/11/2016
  @changed         11/11/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE fDistance_t * LA_pt_GetMovingObjBasePickUpRange(void)
{
  return &(t_LA_Output.f_LAMovingObjBasePickUpRange);
}


/*************************************************************************************************************************
  Functionname:    LA_pt_GetfRangeFac                                                                               */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE fDistance_t *

  @param[in]       void : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/11/2016
  @changed         11/11/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE float32 * LA_pf_GetfRangeFac(void)
{
  return &(t_LA_Output.fRangeFac);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetBasePreselectionState                                                                   */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const LA_t_BasePreselObjList *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/14/2016
  @changed         11/14/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const LA_t_BasePreselObjList * LA_pt_GetBasePreselectionState(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.LABasePreselObjList[iObj]);
}

#if (FCT_CFG_CAMERA_CUTIN_POTENTIAL)
/*************************************************************************************************************************
  Functionname:    LA_pu_GetCameraBasedCutInPotential                                                                */ /*!

  @brief           Return camera LA cut in potential for object

  @description     Return camera LA cut in potential for object

  @return          ALGO_INLINE const uint8 * : cut in potential for object [0 .. 100 %]

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         25.04.2017
  @changed         -


  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 69 67869 6110
*************************************************************************************************************************/
ALGO_INLINE const uint8 * LA_pu_GetCameraBasedCutInPotential(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(t_LA_Output.t_LAObjOutputList[iObj].u_CameraCutInPotential );
}
#endif

#if (FCT_CFG_CAMERA_CUTOUT_POTENTIAL)
/*************************************************************************************************************************
  Functionname:    LA_pu_GetCameraBasedCutOutPotential                                                                */ /*!

  @brief           Return camera LA cut out potential for object

  @description     Return camera LA cut out potential for object

  @return          ALGO_INLINE const uint8 * : cut out potential for object [0 .. 100 %]

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         25.04.2017
  @changed         -


  @author          Piotr Pelechaty | piotr.pelechaty@conti-engineering.com | +49 69 67869 6110
*************************************************************************************************************************/
ALGO_INLINE const uint8 * LA_pu_GetCameraBasedCutOutPotential(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));

  return &(t_LA_Output.t_LAObjOutputList[iObj].u_CameraCutOutPotential );
}
#endif
/*************************************************************************************************************************
  Functionname:    LA_pt_GetObjetList                                                                               */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE const void *

  @param[in]       iObj : 

  @glob_in         None ? : Global input used in this function
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None ? : Compiler switch used only within this function
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @created         11/15/2016
  @changed         11/15/2016

  @todo            Remove this entire line if not needed

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE LA_t_ObjLaneState * LA_pt_GetLAObjLaneState(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].ObjLaneAccStatus);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetLAObjOutputList                                                                         */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE LAObjOutput_t *

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 

  @created         11/18/2016
  @changed         11/18/2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE const LAObjOutput_t * LA_pt_GetLAObjOutputList(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj]);
}

#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    LA_ptAccessTrajRefPoint                                                                          */ /*!

  @brief           Access function for Trajectory Reference Point in current cycle

  @description     Access function for Getting and setting trajectory reference point in current cycle

  @return          Reference to trajectory reference point in current cycle

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes

  @created         28.11.2016
  @changed         28.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE CAL_t_TrajRefPoint * LA_pt_AccessTrajRefPoint(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].ObjTrajRefPoint);
}
#endif

#ifdef FCT_SIMU
/*************************************************************************************************************************
  Functionname:    LA_pt_AccessTrajRefPointLastCycle                                                                  */ /*!

  @brief           Access function for Trajectory Reference Point in last cycle

  @description     Access function for Getting and setting trajectory reference point in last cycle

  @return          Reference to trajectory reference point in last cycle

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            No changes

  @created         28.11.2016
  @changed         28.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
ALGO_INLINE CAL_t_TrajRefPoint * LA_pt_AccessTrajRefPointLastCycle(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].ObjTrajRefPointLastCycle);
}
#endif

/*************************************************************************************************************************
  Functionname:    LA_pt_GetObjAssociatedLane                                                                       */ /*!

  @brief           Inline access function for reference to associated lane for object

  @description     Inline access function for reference to associated lane for object

  @return          Reference to associated lane for object

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS)

  @c_switch_part   None
  @c_switch_full   None

  @created         15.12.2016
  @changed         15.12.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE const eAssociatedLane_t * LA_pt_GetObjAssociatedLane(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].ObjAssociatedLane);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetObjFuncLane                                                                             */ /*!

  @brief           Inline access function for reference to associated function lane for object

  @description     Inline access function for reference to associated function lane for object

  @return          Reference to associated function lane for object

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS)

  @c_switch_part   None
  @c_switch_full   None

  @created         15.12.2016
  @changed         15.12.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE const eAssociatedLane_t * LA_pt_GetObjFuncLane(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_LA_Output.t_LAObjOutputList[iObj].ObjFuncLane);
}

#if (defined(FCT_SIMU) || defined(FASTSIM))
/*************************************************************************************************************************
  Functionname:    LA_pf_GetRangeFac                                                                                */ /*!

  @brief           Get a pointer to range reduction factor to be initialized by the SIM Framework

  @description     Get a pointer to range reduction factor to be initialized by the SIM Framework

  @return          reference to the range factor initialized in SIM

  @param[in]       void 

  @glob_in         None
  @glob_out        None

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch for Simulation Framework
  @c_switch_full   FASTSIM   : Switch for Fastsim simulation

  @pre             -
  @post            Range reduction factor will be set to zero

  @created         5/14/2017
  @changed         5/14/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE float32 * LA_pf_GetRangeFac(void)
{
  return &(t_LA_Output.fRangeFac);
}
#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    *LA_pt_GetNearBlockedObject                                                                      */ /*!

  @brief           Inline function to access nearer of the objects in the blocked path; used by SIM

  @description     Inline function to access nearer of the objects in the blocked path; used by SIM

  @return          Reference to ID of the nearer object in the blocked path

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch for Simulation Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE const ObjNumber_t *LA_pt_GetNearBlockedObject(void)
{
  return &(t_LA_Output.s_BlockedNearObj);
}
#endif /*END IF(LA_CFG_BLOCKED_OBSTACLE_EXTENSION)*/

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_pt_GetFarBlockedObject                                                                        */ /*!

  @brief           Inline function to access farther of the objects in the blocked path; used by SIM

  @description     Inline function to access farther of the objects in the blocked path; used by SIM

  @return          Reference to ID of the farther object in the blocked path

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch for Simulation Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE const ObjNumber_t * LA_pt_GetFarBlockedObject(void)
{
  return &(t_LA_Output.s_BlockedFartherObj);
}
#endif /*END IF(LA_CFG_BLOCKED_OBSTACLE_EXTENSION) */

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_pf_GetBlockedPath                                                                             */ /*!

  @brief           Inline function to get the width of the blocked path; used by SIM
  @description     Inline function to get the width of the blocked path; used by SIM

  @return          reference to the blocked path width

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch for Simulation Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_GetBlockedPath(void)
{
  return &(t_LA_Output.f_BlockedPathWidth);
}
#endif /*END IF(LA_CFG_BLOCKED_OBSTACLE_EXTENSION) */

#if (LA_CFG_BLOCKED_OBSTACLE_EXTENSION)
/*************************************************************************************************************************
  Functionname:    LA_pt_GetPathOccArray                                                                            */ /*!

  @brief           Inline function to access the occupancy list of objects and obstacles; used by SIM

  @description     Inline function to access the occupancy list of objects and obstacles; used by SIM

  @return          reference to the occupancy array

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch for Simulation Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017


  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE const SIT_t_PathOccupation * LA_pt_GetPathOccArray(void)
{
  return &(t_LA_Output.a_PathOccObj2Obstacle[0]);
}
#endif /*END IF(LA_CFG_BLOCKED_OBSTACLE_EXTENSION) */
#endif /*(defined(FCT_SIMU) || defined(FASTSIM))*/

/*************************************************************************************************************************
  Functionname:    LA_pf_GetObjDependentMaxRange                                                                    */ /*!

  @brief           Inline function to access object dependent max selection distance; used by SIM

  @description     Inline function to access object dependent max selection distance; used by SIM

  @return          reference to the object dependent max selection distance

  @param[in]       t_ObjNr : ID of the object for which selection distance is to be sent [0   EM_N_OBJECTS[

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU  : Switch for Simulation Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017


  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_GetObjDependantMaxRange(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].ObjDependantMaxRange);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetPredTimeThreshold                                                                    */ /*!

  @brief           Inline function to access object dependent prediction time threshold

  @description     Inline function to access object dependent prediction time threshold

  @return          reference to the object dependent prediction time threshold

  @param[in]       t_ObjNr : ID of the object for which prediction time threshold is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         7/19/2018
  @changed         7/19/2018


  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
ALGO_INLINE const fTime_t * LA_pt_GetPredTimeThreshold(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].t_PredTimeThreshold);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetTotalTimeToInlap                                                                    */ /*!

  @brief           Inline function to access object dependent predicted total time to inlap

  @description     Inline function to access object dependent predicted total time to inlap

  @return          reference to the object dependent predicted total time to inlap

  @param[in]       t_ObjNr : ID of the object for which total time to inlap is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         7/19/2018
  @changed         7/19/2018


  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
ALGO_INLINE const fTime_t * LA_pt_GetTotalTimeToInlap(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].t_TotalTimeToInlap);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetTotalTimeToInlapDrop                                                                    */ /*!

  @brief           Inline function to access object dependent predicted total time to inlap drop

  @description     Inline function to access object dependent predicted total time to inlap drop

  @return          reference to the object dependent predicted total time to inlap drop

  @param[in]       t_ObjNr : ID of the object for which total time to inlap drop is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         7/19/2018
  @changed         7/19/2018


  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
ALGO_INLINE const fTime_t * LA_pt_GetTotalTimeToInlapDrop(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].t_TotalTimeToInlapDrop);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetDistanceToInlap                                                                    */ /*!

  @brief           Inline function to access object dependent Distance to inlap

  @description     Inline function to access object dependent Distance to inlap

  @return          reference to the object dependent  Distance to inlap

  @param[in]       t_ObjNr : ID of the object for which Distance to inlap is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         10.08.2018
  @changed         10.08.2018


  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pt_GetDistanceToInlap(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].f_DistanceToInlap);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetDistanceToInlapDrop                                                                    */ /*!

  @brief           Inline function to access object dependent Distance to inlapDrop

  @description     Inline function to access object dependent Distance to inlapDrop

  @return          reference to the object dependent  Distance to inlapDrop

  @param[in]       t_ObjNr : ID of the object for which Distance to inlapDrop is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         10.08.2018
  @changed         10.08.2018


  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pt_GetDistanceToInlapDrop(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].f_DistanceToInlapDrop);
}

/*************************************************************************************************************************
  Functionname:    LA_pt_GetTotalDistanceToInlap                                                                    */ /*!

  @brief           Inline function to access object dependent Total Distance to inlap

  @description     Inline function to access object dependent Total Distance to inlap

  @return          reference to the object dependent Total Distance to inlap

  @param[in]       t_ObjNr : ID of the object for which Total Distance to inlap is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         10.08.2018
  @changed         10.08.2018


  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pt_GetTotalDistanceToInlap(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].f_TotalDistanceToInlap);
}
/*************************************************************************************************************************
  Functionname:    LA_pt_GetTotalDistanceToInlapDrop                                                                    */ /*!

  @brief           Inline function to access object dependent Total Distance to inlapDrop

  @description     Inline function to access object dependent Total Distance to inlapDrop

  @return          reference to the object dependent Total Distance to inlapDrop

  @param[in]       t_ObjNr : ID of the object for which Total Distance to inlapDrop is to be sent [0   EM_N_OBJECTS[

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   None

  @pre             None
  @post            None

  @created         10.08.2018
  @changed         10.08.2018


  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pt_GetTotalDistanceToInlapDrop(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].f_TotalDistanceToInlapDrop);
}

/*************************************************************************************************************************
  Functionname:    LA_pf_GetObjectInlap                                                                    */ /*!

  @brief           Inline function to access object's Inlap

  @description     Inline function to access object's Inlap

  @return          reference to the object's Inlap

  @param[in]       t_ObjNr : ID of the object for which Inlap is to be sent [0   EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         26.11.2020
  @changed         26.11.2020


  @author          Rahul Raj | Rahul.Raj@continental-corporation.com | 
*************************************************************************************************************************/
ALGO_INLINE const float32 * LA_pf_GetObjectInlap(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));
  return &(t_LA_Output.t_LAObjOutputList[t_ObjNr].ObjTrajRelation.fInlap);
}
#endif /* END IF FCT_CFG_ACC_LANE_ASSOCIATION */
#endif /* END IF LA_ACCESS_FUNC_H_INCLUDED */
