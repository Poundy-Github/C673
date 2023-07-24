/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                    Umesh Babu Harsha (uidj3583)

CREATION DATE:             30.09.2016

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 2.2

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef SIT_ACCESS_FUNC_H_INCLUDED
#define SIT_ACCESS_FUNC_H_INCLUDED

/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/
#include "sit_custom_ext.h"
#include "sit_ext.h"
#include "sit_par.h"
#include "slate_access_func.h"
/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit
@{ */

ALGO_INLINE SIT_OutputBool_t const * SIT_pu_GetBool(const ObjNumber_t t_ObjNr);
/*lane change information getters , prob, state , phase*/
ALGO_INLINE SIT_LC_t_LaneChangePhaseInfo const * SIT_pt_GetLaneChangePhase(void);
ALGO_INLINE sint16 const * SIT_pt_GetLaneChangeInfo(void);
ALGO_INLINE uint8 * SIT_pu_GetCutInProbability(const ObjNumber_t iObj);
ALGO_INLINE uint8 * SIT_pu_GetCutOutProbability(const ObjNumber_t iObj);
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
ALGO_INLINE SITLCStateCamLaneMarkerCrossed_t const * SIT_pt_CamLaneMarkerCrossed(void);
#endif /* END IF FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
ALGO_INLINE SITLaneChangeCamPreMove_t const * SIT_pt_LaneChangeCamPreMoveState(void);
#endif /* END IF FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */
#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
ALGO_INLINE float32 const * SIT_pf_GetCrossingDistTrace(const ObjNumber_t ObjID);
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */
#if (SIT_CFG_OBJECT_SCORING)
ALGO_INLINE eAssociatedLane_t const * SIT_pt_GetScoringAssocLane(const ObjNumber_t iObjNr);
#endif /* END IF SIT_CFG_OBJECT_SCORING */
#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))

ALGO_INLINE boolean const * SIT_pb_GetFrontObstSigVal(void);
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */
ALGO_INLINE const SITObjOutput_t * SIT_pt_GetSITObjOutputList(ObjNumber_t iObj);
ALGO_INLINE uint8 const * SIT_pu_BlockedPathSelectionTimer(const ObjNumber_t iObj);
ALGO_INLINE ObjNumber_t const * SIT_pt_GetBlockedPathCloseObjID(void);
ALGO_INLINE ObjNumber_t const * SIT_pt_GetBlockedPathFarObjID(void);
ALGO_INLINE float32 const * SIT_pf_GetCloseObjDistTraj(void);
ALGO_INLINE float32 const * SIT_pf_GetFarObjDistTraj(void);
ALGO_INLINE float32 const * SIT_pf_GetDistXFarObjId(void);
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
ALGO_INLINE float32 const * SIT_pf_GetDistXCloseObjId(void);
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
#if defined FCT_SIMU && !defined FASTSIM
ALGO_INLINE ObjNumber_t const * SIT_pt_GetStatObjNear(void);
ALGO_INLINE ObjNumber_t const * SIT_pt_GetStatObjFar(void);
ALGO_INLINE ObjNumber_t const * SIT_pt_GetMovingObjFar(void);
ALGO_INLINE ObjNumber_t const * SIT_pt_GetMovingObjFar(void);
ALGO_INLINE SIT_t_PathOccupation const * SIT_pt_GetStat2StatOccPath(void);
ALGO_INLINE const SIT_t_PathOccupation  * SIT_pt_GetMov2MovOccPath(void);
#endif
/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    SIT_pu_GetBool                                                                      */ /*!

  @brief           Inline function for accessing the bit field covering the SIT object attributes booleans

  @description     Inline function for accessing the bit field covering the SIT object attributes booleans

  @return          t_SITOutput->t_ObjList[i].t_Bool : Reference to bit field for object t_ObjNr [0u, 1u] 
                                                      with i in [0 ... EM_N_OBJECTS-1]

  @param[in]       t_ObjNr : object number [0 ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             
  @post            

  @created         11.10.2016
  @changed         11.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
ALGO_INLINE SIT_OutputBool_t const * SIT_pu_GetBool(const ObjNumber_t t_ObjNr)
{
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS));

  return &(t_SITOutput.t_ObjList[t_ObjNr].t_Bool);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetLaneChangePhase                                                                     */ /*!

  @brief           Inline function for accessing the lane change phase signals

  @description     Inline function for accessing the lane change phase signals

  @return          t_SITOutput.t_LaneChangePhase : Reference to SIT Lane change phase info

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         02.11.2016
  @changed         02.11.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE SIT_LC_t_LaneChangePhaseInfo const * SIT_pt_GetLaneChangePhase(void)
{
  return &(t_SITOutput.t_LaneChangePhase);
}

/*************************************************************************************************************************
  Functionname:    SIT_ps_GetLaneChangeProbability                                                                     */ /*!

  @brief           Inline function for accessing the Lane change probability

  @description     Inline function for accessing the Lane change probability

  @return          t_SITOutput.s_LCProbability : Reference to SIT Lane change probability                              [-100 100]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         19.10.2016
  @changed         19.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE sint16 const * SIT_pt_GetLaneChangeInfo(void)
{
  return &(t_SITOutput.s_LCProb);
}

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    SIT_pt_CamLaneMarkerCrossed                                                                     */ /*!

  @brief           Inline function for accessing Camera lane marker crossing state

  @description     Inline function for accessing Camera lane marker crossing state

  @return          t_SITOutput.t_CamLaneMarkerCrossed : Reference to SIT Camera lane marker crossing state 
                      [full range of datatype SITLCStateCamLaneMarkerCrossed_t as in sit_ext.h]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for SIT: Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Config switch for SIT: Need to be switched on for ACC

  @pre             - 
  @post            -

  @created         12.10.2016
  @changed         12.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE SITLCStateCamLaneMarkerCrossed_t const * SIT_pt_CamLaneMarkerCrossed(void)
{
  return &(t_SITOutput.t_CamLaneMarkerCrossed);
}
#endif /* END IF FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */

#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
/*************************************************************************************************************************
  Functionname:    SIT_pt_LaneChangeCamPreMoveState                                                                     */ /*!

  @brief           Inline function for accessing the state if the ego vehicle moves to the new lane in the first stage of the lane change, 
                      i.e. before entering the new lane

  @description     Inline function for accessing the state if the ego vehicle moves to the new lane in the first stage of the lane change, 
                      i.e. before entering the new lane

  @return          t_SITOutput.t_LaneChangeCamPreMoveState : Reference to SIT Get state if the ego vehicle 
                      moves to the new lane in the first stage of the lane change [full range of datatype 
                      SITLaneChangeCamPreMove_t as in sit_ext.h]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_FIP_LANE_MATRIX_FUSION : Config switch for SIT: Need to be switched on for ACC
  @c_switch_full   SLATE_CFG_CAM_LANE_INTERFACE : Config switch for SIT: Need to be switched on for ACC

  @pre             -
  @post            -

  @created         13.10.2016
  @changed         13.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE SITLaneChangeCamPreMove_t const * SIT_pt_LaneChangeCamPreMoveState(void)
{
  return &(t_SITOutput.t_LaneChangeCamPreMoveState);
}
#endif /* END IF FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE */ 

#if (FCT_CFG_OBJECT_TRACE_PREPROCESSSING)
/*************************************************************************************************************************
  Functionname:    SIT_pf_GetCrossingDistTrace                                                                     */ /*!

  @brief           Inline function for accessing the longitudinal crossing point of the trajectory 
                    and the corresponding trace trajectory

  @description     Inline function for accessing the longitudinal crossing point of the trajectory 
                    and the corresponding trace trajectory

  @return          t_SITOutput.t_ObjList[ObjID].f_DistCrossing : Reference to SIT Longitudinal distance of the crossing point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @param[in]       ObjID : FCT Object number [0 ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_OBJECT_TRACE_PREPROCESSSING :  Use traces of moving objects for fusion as defined in fct_config.h

  @pre             -
  @post            -

  @created         19.10.2016
  @changed         19.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SIT_pf_GetCrossingDistTrace(const ObjNumber_t ObjID)
{
  return &(t_SITOutput.t_ObjList[ObjID].f_CrossingDistTrace);
}
#endif /* END IF FCT_CFG_OBJECT_TRACE_PREPROCESSSING */

#if (SIT_CFG_OBJECT_SCORING)
/*************************************************************************************************************************
  Functionname:    SIT_pt_GetScoringAssocLane                                                                     */ /*!

  @brief           Inline function for accessing the lane assigned to an object by this module

  @description     Inline function for accessing the lane assigned to an object by this module

  @return          t_SITOutput.t_ObjList[ObjID].t_GetScoringAssocLane : Reference to [enum type eAssociatedLane_t, defined in Rte_Type.h]

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SIT_CFG_OBJECT_SCORING : Configuration switch to enable object scoring module

  @pre             -
  @post            -

  @created         20.10.2016
  @changed         20.10.2016

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE eAssociatedLane_t const * SIT_pt_GetScoringAssocLane(const ObjNumber_t iObjNr)
{
  return &(t_SITOutput.t_ObjList[iObjNr].t_SIT_O2O_Analysis.t_ObjScoreLane);
}
#endif /* END IF SIT_CFG_OBJECT_SCORING */


/*************************************************************************************************************************
  Functionname:    SIT_pu_GetCutInProbability                                                                     */ /*!

  @brief           Inline function for accessing the CUT-IN potential of the object

  @description     Inline function for accessing the CUT-IN potential of the object

  @return          Reference to t_SITOutput.t_ObjList[iObj].u_ObjCutInPotential : Cut in potential of object iObj   [0u ... 100u]

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         12/12/2016
  @changed         12/12/2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE uint8 * SIT_pu_GetCutInProbability(const ObjNumber_t iObj)
{
  return  &(t_SITOutput.t_ObjList[iObj].u_ObjCutInPotential);
}

/*************************************************************************************************************************
  Functionname:    SIT_pu_GetCutOutProbability                                                                    */ /*!

  @brief           Inline function for accessing the CUT-IN potential of the object

  @description     Inline function for accessing the CUT-IN potential of the object

  @return          Reference to t_SITOutput.t_ObjList[iObj].u_ObjCutOutPotential : cut out potential of object iObj  [0u ... 100u]

  @param[in]       iObj : FCT Object number [0 ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   - 

  @pre             -
  @post            -

  @created         12/12/2016
  @changed         12/12/2016

  @author          Chintan Raval | chintan.raval-ext@continental-corporation.com | +91 (80) 6679-6480
*************************************************************************************************************************/
ALGO_INLINE uint8 * SIT_pu_GetCutOutProbability(const ObjNumber_t iObj)
{
  return &(t_SITOutput.t_ObjList[iObj].u_ObjCutOutPotential);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetSITObjOutputList                                                                         */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE SITObjOutput_t *

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
ALGO_INLINE const SITObjOutput_t * SIT_pt_GetSITObjOutputList(ObjNumber_t iObj)
{
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2017-01-08, reviewer:Chintan Raval, reason: Used/will be used to check array index is wtihin the bound */

  return &(t_SITOutput.t_ObjList[iObj]);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetBlockedPathFarObjID                                                                    */ /*!

  @brief           Inline function for accessing the blocked path object ID

  @description     Inline function for accessing the blocked path object ID

  @return          Reference to t_SITOutput.t_BlockedPathFarObjID

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         12/12/2016
  @changed         12/12/2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SIT_pt_GetBlockedPathFarObjID(void)
{
  return &(t_SITOutput.t_BlockedPathFarObjID);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetBlockedPathCloseObjID                                                                    */ /*!

  @brief           Inline function for accessing the blocked path object ID

  @description     Inline function for accessing the blocked path object ID

  @return          Reference to t_SITOutput.t_BlockedPathCloseObjID

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         12/12/2016
  @changed         12/12/2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SIT_pt_GetBlockedPathCloseObjID(void)
{
  return &(t_SITOutput.t_BlockedPathCloseObjID);
}

/*************************************************************************************************************************
  Functionname:    SIT_pf_BlockedPathSelectionTimer                                                                    */ /*!

  @brief           Inline function for accessing the blocked path decision timer

  @description     Inline function for accessing the blocked path decision timer

  @return          Reference to t_SITOutput.t_ObjList[iObj].u_BlockedPathSelectionTimer

  @param[in]       t_ObjNr : FCT Object number [0 ... EM_N_OBJECTS)

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         12/12/2016
  @changed         12/12/2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE uint8 const * SIT_pu_BlockedPathSelectionTimer(const ObjNumber_t iObj)
{
  /* Suppress "Msg(3:3112) This statement has no side-effect - it can be removed"  */ /*PRQA S 3112 1*/
  SLATE_ASSERT((iObj >= 0) && (iObj < EM_N_OBJECTS));
  return &(t_SITOutput.t_ObjList[iObj].u_BlockedPathSelectionTimer);
}

/*************************************************************************************************************************
  Functionname:    SIT_pf_GetDistXFarObjId                                                                    */ /*!

  @brief           Inline function for accessing the blocked path object ID

  @description     Inline function for accessing the blocked path object ID

  @return          Reference to t_SITOutput.f_DistXFarObjId

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         12/12/2016
  @changed         12/12/2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SIT_pf_GetDistXFarObjId(void)
{
  return &(t_SITOutput.f_DistXFarObjId);
}

#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
/*************************************************************************************************************************
  Functionname:    SIT_pf_GetDistXCloseObjId                                                                    */ /*!

  @brief           Inline function for accessing the Longitudinal distance of close object in blocked path 

  @description     Inline function for accessing the Longitudinal distance of close object in blocked path 

  @return          Reference to t_SITOutput.f_DistXCloseObjId

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         05/27/2020
  @changed         05/27/2020

  @author          Madhusudhanan Dhanikachalam | madhusudhanan.dhanikachalam@continental-corporation.com
*************************************************************************************************************************/
ALGO_INLINE float32 const * SIT_pf_GetDistXCloseObjId(void)
{
  return &(t_SITOutput.f_DistXCloseObjId);
}
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */

/*************************************************************************************************************************
  Functionname:    SIT_pf_GetFarObjDistTraj                                                                    */ /*!

  @brief           Inline function for accessing the blocked path object ID

  @description     Inline function for accessing the blocked path object ID

  @return          Reference to t_SITOutput.f_FarObjDistTraj

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         12/12/2016
  @changed         12/12/2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SIT_pf_GetFarObjDistTraj(void)
{
  return &(t_SITOutput.f_FarObjDistTraj);
}

/*************************************************************************************************************************
  Functionname:    SIT_pf_GetCloseObjDistTraj                                                                    */ /*!

  @brief           Inline function for accessing the blocked path object ID

  @description     Inline function for accessing the blocked path object ID

  @return          Reference to t_SITOutput.f_CloseObjDistTraj

  @param[in]       -

  @glob_in         None 
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes

  @created         12/12/2016
  @changed         12/12/2016

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
ALGO_INLINE float32 const * SIT_pf_GetCloseObjDistTraj(void)
{
  return &(t_SITOutput.f_CloseObjDistTraj);
}

#if ((SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD))


/*************************************************************************************************************************
  Functionname:         SIT_pt_GetFrontObstSigVal                                                                    */ /*!

  @brief                Inline Function for accessing the value of the boolean signal bfrontobstacledetected

  @description          Inline Function for accessing the value of the boolean signal bfrontobstacledetected

  @return               Reference to t_SITOutput.t_SIT_FrontObstacleDetection.b_FrontObstDetcd

  @param[in]            -

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        SLATE_CFG_TCI_BASE             : config Switch for enabling SLATE support for TCI Module  
  @c_switch_part        SLATE_CFG_TCI_FRONT_OBST_DETCD : config Switch for enabling SLATE support for TCI Module - Front Obstacle Detected functionality
  @c_switch_full        None
                  

  @pre                  None 
  @post                 None

  @InOutCorrelation     None

  @author               Pavan Kotra | pavan.kotra@continental-corporation.com | +91 (80) 6679-6000
*************************************************************************************************************************/
ALGO_INLINE boolean const * SIT_pb_GetFrontObstSigVal(void)
{
  return &(t_SITOutput.t_SIT_FrontObstacleDetection.b_FrontObstDetcd);
}
#endif /* END IF (SLATE_CFG_TCI_BASE) && (SLATE_CFG_TCI_FRONT_OBST_DETCD) */


#if defined FCT_SIMU && !defined FASTSIM 
/*************************************************************************************************************************
  Functionname:    SIT_pt_GetStatObjNear                                                                            */ /*!

  @brief           Inline function to access nearer object in stat2stat blocked path; used in SIM

  @description     Inline function to access nearer object in stat2stat blocked path; used in SIM

  @return          reference to nearer object in stat2stat blocked path

  @param[in]       void 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Switch for sim framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017


  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SIT_pt_GetStatObjNear(void)
{
  return &(t_SITOutput.StatCloseObjId);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetStatObjFar                                                                             */ /*!

  @brief           Inline function to access farther object in stat2stat blocked path; used in SIM

  @description     Inline function to access farther object in stat2stat blocked path; used in SIM

  @return          reference to farther object in stat2stat blocked path

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Switch for sim framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SIT_pt_GetStatObjFar(void)
{
  return &(t_SITOutput.StatFarObjId);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetMovingObjNear                                                                          */ /*!

  @brief           Inline function to access nearer object in movt2mov blocked path; used in SIM

  @description     Inline function to access nearer object in movt2mov blocked path; used in SIM

  @return          reference to the nearer object in mov2mov blocked path

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Switch for sim framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SIT_pt_GetMovingObjNear(void)
{
  return &(t_SITOutput.CloseObjId);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetMovingObjFar                                                                           */ /*!

  @brief           Inline function to access farther object in movt2mov blocked path; used in SIM

  @description     Inline function to access farther object in movt2mov blocked path; used in SIM

  @return          reference to the farther object in mov2mov blocked path

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : Switch for sim framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * SIT_pt_GetMovingObjFar(void)
{
  return &(t_SITOutput.FarObjId);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetStat2StatOccPath                                                                       */ /*!

  @brief           Inline function to access stat2stat blocked path array; used in SIM

  @description     Inline function to access stat2stat blocked path array; used in SIM

  @return          reference to stat2stat blocked path array

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : switch for SIM Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017


  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE SIT_t_PathOccupation const * SIT_pt_GetStat2StatOccPath(void)
{
  return &(t_SITOutput.t_SITPathOccStat2Stat[0]);
}

/*************************************************************************************************************************
  Functionname:    SIT_pt_GetMov2MovOccPath                                                                         */ /*!

  @brief           Inline function to access mov2mov blocked path array; used in SIM

  @description     Inline function to access mov2mov blocked path array; used in SIM

  @return          reference to mov2mov blocked path array

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : switch for SIM Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE const SIT_t_PathOccupation  * SIT_pt_GetMov2MovOccPath(void)
{
  return &(t_SITOutput.t_SITPathOccMov2Mov[0]);
}

#if (SIT_CFG_TRAFFIC_DENSITY)
/*************************************************************************************************************************
  Functionname:    SIT_pt_GetHistObjArray                                                                           */ /*!

  @brief           Inline function to access object History; used by SIM

  @description     Inline function to access object History; used by SIM

  @return          reference to the structure SITOutput_t

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_SIMU : switch for SIM Framework

  @pre             -
  @post            -

  @created         5/23/2017
  @changed         5/23/2017

  @author          Madhusudan Mudhol | madhusudan.mudhol@continental-corporation.com | +91 (8066796169) -
*************************************************************************************************************************/
ALGO_INLINE SIT_ObjHistData_t * SIT_pt_GetHistObjArray(void)
{
  return (t_SITOutput.a_SITHistData);
}
#endif /* #if (SIT_CFG_TRAFFIC_DENSITY) */
#endif /* END IF FCT_SIMU && !defined FASTSIM */
///@}
#endif /* END IF SIT_ACCESS_FUNC_H_INCLUDED */
