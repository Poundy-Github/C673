/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_check_occupied_lane.c

DESCRIPTION:               ACC specific detection of lane occupation by more than 1 object (narrow gap)

AUTHOR:                    Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474

CREATION DATE:             14.09.2016

VERSION:                   $Revision: 1.31 $

LEGACY VERSION:            Revision: 2.2.1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_check_occupied_lane Lane occupancy check
@ingroup sit
@brief          This module checks whether our lane is occupied by more than one object.\n\n
@{
*/
// PRQA S 7013 STTLN_EXCEEDED
/* date: 2015-04-28, reviewer: Lonard jaison manohar, reason: Number of lines exceeded per file, not safety critical */
/*****************************************************************************
  MACROS 
*****************************************************************************/
#define LAT_LANECHANGE_TIME                                   (1.4f) /*!< Comfort Lat LANECHANGE time @unit:s */
#define LAT_LANECHANGE_MINSPEED                               (5.0f) /*!< Minimal assumed Lat LANECHANGE speed @unit:m/s*/
#define STATIC_OBJECT_OCCUPATION_RIGHT_ENTRY                  (2u)
#define STATIC_OBJECT_OCCUPATION_LEFT_ENTRY                   (3u)
#define STATIC_OBJECT_OCCUPATION_FREE_ENTRY                   (4u)

#define SIT_VALID_OBJECT_WIDTH_IN_LANE_FOR_ARSOBJ_CLASS_POINT  (0.8f)
#define SIT_OBJECT_WIDTH_IN_LANE_FOR_NON_ARSOBJ_CLASS_POINT    (1.8f)
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
SET_MEMSEC_CONST(CorrSelOffsetYObj2ObjDistX)
static const GDBLFunction_t CorrSelOffsetYObj2ObjDistX = {// PRQA S 3218
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls*/
  SIT_CORRIDOR_SEL_Y_OFFSET_MIN,/* Ausgangswert A1 */
  SIT_CORRIDOR_SEL_Y_OFFSET_MAX,/* Ausgangswert A2 */
  ( SIT_CORRIDOR_SEL_Y_OFFSET_MAX - SIT_CORRIDOR_SEL_Y_OFFSET_MIN ) / ( SIT_CORSELYOFF_Obj2ObjDistX_MAX - SIT_CORSELYOFF_Obj2ObjDistX_MIN ),
  /* Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 */
  SIT_CORRIDOR_SEL_Y_OFFSET_MIN
  -( (( SIT_CORRIDOR_SEL_Y_OFFSET_MAX - SIT_CORRIDOR_SEL_Y_OFFSET_MIN ) / ( SIT_CORSELYOFF_Obj2ObjDistX_MAX - SIT_CORSELYOFF_Obj2ObjDistX_MIN ))
  * SIT_CORSELYOFF_Obj2ObjDistX_MIN )
};

SET_MEMSEC_CONST(CorrSelOffsetYTTCGapWeight)
static const GDBLFunction_t CorrSelOffsetYTTCGapWeight = {// PRQA S 3218
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls*/
  1.0F,/* Ausgangswert A1 */
  0.0F,/* Ausgangswert A2 */
  ( - 1.0F ) / ( SIT_CORSELYOFF_TTCGAP_MAX - SIT_CORSELYOFF_TTCGAP_MIN ),
  /* Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 */
  1.0F
  -( ((  -1.0F ) / ( SIT_CORSELYOFF_TTCGAP_MAX - SIT_CORSELYOFF_TTCGAP_MIN ))
  * SIT_CORSELYOFF_TTCGAP_MIN )
};

SET_MEMSEC_CONST(CorrSelOffsetYTimeGapWeight)
static const GDBLFunction_t CorrSelOffsetYTimeGapWeight = {// PRQA S 3218
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls*/
  SIT_CORSEL_Y_HYST_MIN,/* Ausgangswert A1 */
  SIT_CORSEL_Y_HYST_MAX,/* Ausgangswert A2 */
  (SIT_CORSEL_Y_HYST_MAX - SIT_CORSEL_Y_HYST_MIN ) / ( SIT_CORSEL_Y_HYST_TIMEGAP_MAX - SIT_CORSEL_Y_HYST_TIMEGAP_MIN ),
  /* Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 */
  SIT_CORSEL_Y_HYST_MIN
  -( ((SIT_CORSEL_Y_HYST_MAX - SIT_CORSEL_Y_HYST_MIN ) / ( SIT_CORSEL_Y_HYST_TIMEGAP_MAX - SIT_CORSEL_Y_HYST_TIMEGAP_MIN ))
  * SIT_CORSEL_Y_HYST_TIMEGAP_MIN )
};

SET_MEMSEC_CONST(CorrSelPathwidthPassableMov)
static const GDBLFunction_t CorrSelPathwidthPassableMov = {// PRQA S 3218
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: static local for saving data across function calls*/
  SIT_MIN_PATHWIDTH_PASSABLE_MOV_MIN,/* Ausgangswert A1 */
  SIT_MIN_PATHWIDTH_PASSABLE_MOV_MAX,/* Ausgangswert A2 */
  ( SIT_MIN_PATHWIDTH_PASSABLE_MOV_MAX - SIT_MIN_PATHWIDTH_PASSABLE_MOV_MIN ) / ( SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MAX - SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MIN ),
  /* Achsabschnitt der Anpassungsgerade:   A1 - (A2-A1)/(E2-E1) * E1 */
  SIT_MIN_PATHWIDTH_PASSABLE_MOV_MIN
  -( (( SIT_MIN_PATHWIDTH_PASSABLE_MOV_MAX - SIT_MIN_PATHWIDTH_PASSABLE_MOV_MIN ) / ( SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MAX - SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MIN ))
  * SIT_MIN_PATHWIDTH_PASSABLE_MOV_VOBJ_MIN )
};

/*****************************************************************************
  VARIABLES 
*****************************************************************************/
SET_MEMSEC_VAR(t_SIT_LastCycleOOIObjID)
static  ObjNumber_t t_SIT_LastCycleOOIObjID[OOI_NUMBER_OF_OOI];
/*****************************************************************************
  FUNCTION 
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES DECLARATIONS
*****************************************************************************/

static float32 SIT_f_CalcDriveAroundDist(float32 EgoSpeedXObjSync);
static float32 SIT_f_GetObjectWidthInLane(ObjNumber_t iObject);
static void SIT_v_InitSiPathOccupation (SIT_t_PathOccupationArray SITPathOccupation, float32 HalfLaneWidth);
static void SIT_v_FillStat2StatPathOccupation (SIT_t_PathOccupationArray SITPathOccupation);
static void SIT_v_FillMov2MovPathOccupation(SIT_t_PathOccupationArray SITPathOccupation);
static void SIT_v_CalcOccPathWidth( const SIT_t_PathOccupation SITPathOcc[SIT_PATH_OCC_ENTRIES],
                                SIT_t_PathOccResultArray SiPathhOccResult);
static void SIT_v_InsertObjInPathOcc( SIT_t_PathOccupationArray SITPathOccupation,
                                  uint32* ActualEntry,uint32* NextFree, 
                                  const SIT_t_PathOccInsertObjData * SITPathOccInsertObjDataPtr);
static void SIT_v_InitSiPathOccResult(SIT_t_PathOccResultArray SITPathhOccResult, float32 HalfLaneWidth);
static void SIT_v_CheckForNarrowPath( const SIT_t_PathOccResult SITPathhOccResult[SIT_PATH_OCC_ENTRIES],
                                  ObjNumber_t * const pCloseObjId,
                                  ObjNumber_t * const pFarObjId);
static void SIT_v_ResetBlockedPathDecision(void);
static void SIT_v_UpdateTimerBlockedPathDecision(void);
static void SIT_v_SetBlockedPathAtLaneChange(ObjNumber_t CloseObjId, ObjNumber_t FarObjId);
static void SIT_v_ResetBlockedPathOutputs(ObjNumber_t t_CloseObjID, ObjNumber_t t_FarObjID);

/*************************************************************************************************************************
  Functionname:    SIT_v_InitBlockedPath                                                                                */ /*!

  @brief           Initialization of blocked path relevant variables

  @description     Initialization of blocked path relevant variables when SI is initializied.
                   This module is Empty in this version. Code does not need initialization since no
                   static variables present. Function only present to allow same module signature 
                   towards caller (sit_main.c - prevent branching)

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Marie-Theres Boll| Marie-Theres Boll@continental-corporation.com | 
*************************************************************************************************************************/
void SIT_v_InitBlockedPath(void)
{
  /* Empty in this version. Code does not need initialization since no
  static variables present. Function only present to allow same module
  signature towards caller (sit_main.c - prevent branching) */
}


/*************************************************************************************************************************
  Functionname:    SIT_v_SelectCorridorObjects                                                                          */ /*!

  @brief           Select corridor objects

  @description     Function gets addresses of pointer to relevant object and hidden object passed. If previously run 
                   algorithms did not select these objects, than the pointers pointed to may be NULL (note: *ppNextObject 
                   may be NULL not ppNextObject itself) If blocked corridor detection indicates that vehicle path is blocked,
                   then these pointers are replaced by the objects blocking the path.

                    @startuml
                    Partition SIT_v_SelectCorridorObjects{
                    Start
                    Note right
                    stationary and slow moving objects are inserted here
                    End note
                    : save Object IDs of last cycle decision;
                    : Reset the blocked path decision bits for all objects;
                    If (Actual curve is less than maximum curvature\n for active blocked path selection) then (TRUE)
                    : Insert stationary objects into path occupation list;
                    : Insert moving objects into path occupation list;
                    : Calculate resulting path widths of neighboring objects within path;
                    : Calculate resulting path widths of neighboring objects within path;
                    : Check for blocked stat2atat path ahead;
                    : check for blocked mov2mov path ahead;
                    : overwrite mov2mov narrow path with stat2stat narrowpath if closer;
                    If (Objects blocking path detected) then (TRUE)
                    : Blocked path objects are set again in case of a lane change situation;
                    : Increment blocked path decision timer for both of the output objects;
                    : Minimum time threshold needed for the objects to\n be selected as blocked path close and far objects;
                    If (Blockedpath selection timer is greater than the threshold) then (TRUE)
                    : Set the timer value of the respective objects to a higher value\n to not drop the objects immediately\n if they are not selected as blocked path\n objects in the next cycle;
                    Else (FALSE)
                    Endif
                    Else (FALSE)
                    If (CloseObjId and FarObjId are invalid objects) then (TRUE)
                    : Get Close and FarObjIsDeleted;
                    If (Check to prolong the selection of blocked path objects from previous cycle for more cycles) then (TRUE)
                    : Decrement blocked path objects timer as part of hysteresis;
                    : Close and Far objects are set from the previous cycle's\n blocked path selected close and far object ids respectively;
                    : Blocked path objects are set again in case of a lane change situation;
                    : Set the timer values to the output to be given out to other components;
                    Else (FALSE)
                    : Reset output values when there are no blocked path objects;
                    Endif
                    Else (FALSE)
                    : Reset output values when there are no blocked path objects;
                    Endif
                    Endif
                    Endif
                    End
                    }
                    @enduml

  @return          -

  @param[in,out]   pNextObjId : Pointer to ID of currently selected next object (relevant object). If blocked corridor
                    examination determines a blocked path, the object pointer is replaced by the ID of the object 
                    blocking the path                                                                                            [ObjNumber_t][-1 ... 39]
  @param[in,out]   pHiddenObjId : Pointer to ID of currently selected hidden object (object in path but farther away than 
                       relevant object). If blocked corridor examination determines a blocked path, the object ID is replaced
                       by the ID of the object blocking the path     
                       [-1 ... 39]
  @glob_in         t_SIT_LastCycleOOIObjID : Last cycle object id                                                                    [ObjNumber_t][-1 ... 39]
  @glob_out        pt_SITOutput->t_ObjList[i].u_BlockedPathSelectionTimer : Path selection timer                                 [full range of uint8]
  @glob_out        pSLATE_CustomOutput->CustObjData[*pNextObjId].DTR_ObjData.DTR_Obj_LaneDistTime :                             [Member not found]
  @glob_out        pSLATE_CustomOutput->CustObjData[*pNextObjId].DTR_ObjData.DTR_Obj_Lane_v2 :                                  [Member not found]
  @glob_out        pt_SITOutput->t_BlockedPathCloseObjID : Blockedpath close object number                                       [ObjNumber_t][-1 ... 39]
  @glob_out        pt_SITOutput->t_BlockedPathFarObjID : Blockedpath far object number                                           [ObjNumber_t][-1 ... 39]

  @c_switch_part   FCT_SIMU : Enable FCT Simulation as defined in fct_config.h
  @c_switch_part   FASTSIM  : Enable FASTSIM environment 
  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM : Configuration switch, which adapts the trace brackets based on the ego position in lane as defined in sit_cfg.h
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM : Configuration switch, which adapts the trace brackets in case of no lane change as defined in sit_cfg.h
  @c_switch_part   LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM : Configuration switch, which adapts the trace brackets in case of the blinker feature as defined in sit_cfg.h
  @c_switch_part   LA_CFG_DTR_OBJ_SELECTION : Configuration switch for DTR object selection as defined in sit_cfg.h
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @todo            Remove global input t_SIT_LastCycleOOIObjID when doing outputs of OOI
                   Move function to OOI. Replace access functions for RTE inputs
                   Replace outputs pSLATE_CustomOutput->CustObjData[*pNextObjId].DTR_ObjData.DTR_Obj_LaneDistTime and 
                   pSLATE_CustomOutput->CustObjData[*pNextObjId].DTR_ObjData.DTR_Obj_Lane_v2 in the function
                   Calls to SIMSaveStatOccPathInfo and SIMSaveMovOccPathInfo have to be moved to SIM Frame

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
void SIT_v_SelectCorridorObjects(void)
{
  /* stationary and slow moving objects are inserted here.
     relationships between slow moving, stopped and stationary
     are assumed to be the same since there is nearly no relative
     movement between objects. object longitudinal expansion 
     depends only on own vehicles speed. */
#if (SIT_CFG_FILL_STAT_PATH) 
  SIT_t_PathOccResultArray  SITPathOccResultStat2Stat;
#endif /*SIT_CFG_FILL_STAT_PATH*/
  /* moving objects are inserted here.
  relationships between moving objects depend on relative speed
  between them, but this is neglected. only relative speed 
  towards own vehicle is taken into account.*/

  SIT_t_PathOccResultArray  SITPathOccResultMov2Mov;
  uint8 nr, u_BlockedPathSelectionTime;
  boolean b_CloseObjIsDeleted, b_FarObjIsDeleted;

  ObjNumber_t CloseObjId      = OBJ_INDEX_NO_OBJECT;
  ObjNumber_t FarObjId        = OBJ_INDEX_NO_OBJECT;
  ObjNumber_t StatCloseObjId  = OBJ_INDEX_NO_OBJECT;
  ObjNumber_t StatFarObjId    = OBJ_INDEX_NO_OBJECT;
  
  float32 fObjLongDisp_Mov=0.f,fObjLongDisp_Stat=0.f;
  
  const fCurve_t ActualCurve = *SLATE_pf_GetEgoCurve();
  float32 f_ActualCurve;

  /* save Object IDs of last cycle decision */
  for(nr = 0u; nr < OOI_NUMBER_OF_OOI; nr++)
  {
    t_SIT_LastCycleOOIObjID[nr] = *pt_SITInput->t_OOI.pu_OOIListObjId(nr);
  }

  /* Reset the blocked path decision bits for all objects */
  SIT_v_ResetBlockedPathDecision();
  f_ActualCurve = fABS(ActualCurve);

  if(f_ActualCurve < SIT_MAX_CURVE_FOR_BLOCKED_PATH_SELECTION)
  {
    /* insert stationary objects into path occupation list */
#if (SIT_CFG_FILL_STAT_PATH) 
    SIT_v_FillStat2StatPathOccupation(pt_SITOutput->t_SITPathOccStat2Stat);
#endif /*SIT_CFG_FILL_STAT_PATH*/
    /* insert moving objects into path occupation list */
    SIT_v_FillMov2MovPathOccupation(pt_SITOutput->t_SITPathOccMov2Mov);

    /* calculate resulting path widths of neighboring objects within path */
#if (SIT_CFG_FILL_STAT_PATH) 
    SIT_v_CalcOccPathWidth(pt_SITOutput->t_SITPathOccStat2Stat,SITPathOccResultStat2Stat);
#endif /*SIT_CFG_FILL_STAT_PATH*/
    /* calculate resulting path widths of neighboring objects within path */
    SIT_v_CalcOccPathWidth(pt_SITOutput->t_SITPathOccMov2Mov,SITPathOccResultMov2Mov);

    /* check for blocked stat2atat path ahead */
#if (SIT_CFG_FILL_STAT_PATH) 
    SIT_v_CheckForNarrowPath(SITPathOccResultStat2Stat,&StatCloseObjId, &StatFarObjId);
#endif /*SIT_CFG_FILL_STAT_PATH*/
    /* check for blocked mov2mov path ahead */
    SIT_v_CheckForNarrowPath(SITPathOccResultMov2Mov,&CloseObjId, &FarObjId);

#if defined FCT_SIMU  /* This code shall not be executed in the FASTSIM context */
    pt_SITOutput->CloseObjId = CloseObjId;
    pt_SITOutput->FarObjId = FarObjId;
    pt_SITOutput->StatCloseObjId = StatCloseObjId;
    pt_SITOutput->StatFarObjId = StatFarObjId;
#endif

    if((StatCloseObjId >= 0) && (CloseObjId >= 0))
    {
      fObjLongDisp_Stat=*SLATE_pf_GetObjLongDisp(StatCloseObjId);
      fObjLongDisp_Mov=*SLATE_pf_GetObjLongDisp(CloseObjId);
    }

    /*overwrite mov2mov narrow path with stat2stat narrowpath if closer */
    if(  (CloseObjId < 0) 
      ||(  (StatCloseObjId >= 0)
         &&(fObjLongDisp_Stat < fObjLongDisp_Mov) 
        )
      )
    {
      CloseObjId = StatCloseObjId;
      FarObjId   = StatFarObjId;
    }

    /* Objects blocking path detected ? */
    if ((CloseObjId >=0) && (FarObjId >=0))
    {
      /* Blocked path objects are set again in case of a lane change situation */
      SIT_v_SetBlockedPathAtLaneChange(CloseObjId,FarObjId);

      CloseObjId =   pt_SITOutput->t_BlockedPathCloseObjID;
      FarObjId = pt_SITOutput->t_BlockedPathFarObjID;
      /* Increment blocked path decision timer for both of the output objects */
      pt_SITOutput->t_ObjList[CloseObjId].u_BlockedPathSelectionTimer++;
      pt_SITOutput->t_ObjList[FarObjId].u_BlockedPathSelectionTimer++;  

      /* Minimum time threshold needed for the objects to be selected as blocked path close and far objects */
      u_BlockedPathSelectionTime = SIT_BLOCKED_PATH_DECISION_TIME_THRESHOLD;

      if( (pt_SITOutput->t_ObjList[CloseObjId].u_BlockedPathSelectionTimer > u_BlockedPathSelectionTime) ||
          (pt_SITOutput->t_ObjList[FarObjId].u_BlockedPathSelectionTimer > u_BlockedPathSelectionTime) )
      {
        /* Blockedpath selection timer is greater than the threshold; so set the timer value of the respective
           objects to a higher value to not drop the objects immediately if they are not selected as blocked path 
           objects in the next cycle */
          pt_SITOutput->t_ObjList[CloseObjId].u_BlockedPathSelectionTimer = SIT_BLOCKED_PATH_HYSTERESIS_THRES;
          pt_SITOutput->t_ObjList[FarObjId].u_BlockedPathSelectionTimer = SIT_BLOCKED_PATH_HYSTERESIS_THRES;
      }/* end if blocked path timer ? */
    }
    else /* CloseObjId and FarObjId are invalid objects in this cycle */
    {
      if ( (pt_SITOutput->t_BlockedPathCloseObjID != OBJ_INDEX_NO_OBJECT) && (pt_SITOutput->t_BlockedPathFarObjID != OBJ_INDEX_NO_OBJECT) )
      {
        b_CloseObjIsDeleted = SLATE_b_GetObjIsDeleted(pt_SITOutput->t_BlockedPathCloseObjID);
        b_FarObjIsDeleted = SLATE_b_GetObjIsDeleted(pt_SITOutput->t_BlockedPathFarObjID);
        /* Check to prolong the selection of blocked path objects from previous cycle for more cycles to avoid dropouts */
        if (  (pt_SITOutput->t_ObjList[pt_SITOutput->t_BlockedPathCloseObjID].u_BlockedPathSelectionTimer > SIT_BLOCKED_PATH_DECISION_TIME_THRESHOLD)
          && (pt_SITOutput->t_ObjList[pt_SITOutput->t_BlockedPathFarObjID].u_BlockedPathSelectionTimer > SIT_BLOCKED_PATH_DECISION_TIME_THRESHOLD) 
          && (b_CloseObjIsDeleted == FALSE)
          && (b_FarObjIsDeleted == FALSE) )
        {
          /* Decrement blocked path objects' timer as part of hysteresis */
          pt_SITOutput->t_ObjList[pt_SITOutput->t_BlockedPathCloseObjID].u_BlockedPathSelectionTimer--;
          pt_SITOutput->t_ObjList[pt_SITOutput->t_BlockedPathFarObjID].u_BlockedPathSelectionTimer--;
          t_SITOutput.t_ObjList[pt_SITOutput->t_BlockedPathCloseObjID].t_Bool.SelectedByPathDecision = 1u;
          t_SITOutput.t_ObjList[pt_SITOutput->t_BlockedPathFarObjID].t_Bool.SelectedByPathDecision = 1u;
          /* Close and Far objects are set from the previous cycle's blocked path selected close and far object ids respectively */
          CloseObjId = pt_SITOutput->t_BlockedPathCloseObjID;
          FarObjId = pt_SITOutput->t_BlockedPathFarObjID;

          /* Blocked path objects are set again in case of a lane change situation */
          SIT_v_SetBlockedPathAtLaneChange(CloseObjId,FarObjId);

          /* Set the timer values to the output to be given out to other components */
          pt_SITOutput->t_ObjList[pt_SITOutput->t_BlockedPathCloseObjID].u_BlockedPathSelectionTimer = pt_SITOutput->t_ObjList[CloseObjId].u_BlockedPathSelectionTimer;
          pt_SITOutput->t_ObjList[pt_SITOutput->t_BlockedPathFarObjID].u_BlockedPathSelectionTimer = pt_SITOutput->t_ObjList[FarObjId].u_BlockedPathSelectionTimer;
        }
        else
        {
          /* Reset output values when there are no blocked path objects */
          SIT_v_ResetBlockedPathOutputs(CloseObjId,FarObjId);
        }
      }
      else
      {
        /* Reset output values when there are no blocked path objects */
        SIT_v_ResetBlockedPathOutputs(CloseObjId,FarObjId);
      }
    }
  }
  /* Update blocked path decision timers */
  SIT_v_UpdateTimerBlockedPathDecision();
}//PRQA S 7004
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Not a Safety critical issue*/

/*************************************************************************************************************************
  Functionname:    SIT_v_ResetBlockedPathOutputs                                                                                   */ /*!

  @brief           Blocked path objects parameters are reset to default values when there are no blocked path objects

  @description     Blocked path objects parameters are reset to default values when there are no blocked path objects

                    @startuml
                    Partition SIT_v_ResetBlockedPathOutputs{
                    Start
                    : Reset output values when there are no blocked path objects;
                    End
                    }
                    @enduml

  @return          -

  @param[in,out]   CloseObjId : Closer object among the two objects that are blocking the path according to preliminary blocked path 
  calculation                                                                                           [ObjNumber_t][-1 ... 39]
  @param[in,out]   FarObjId : Farther object among the two objects that are blocking the path according to preliminary blocked path 
  calculation                                                                                           [ObjNumber_t][-1 ... 39]

  @glob_out         pt_SITOutput->t_BlockedPathCloseObjID : Blocked path close object id                          [ObjNumber_t][-1 ... 39]
  @glob_out         pt_SITOutput->t_BlockedPathFarObjID : Blocked path far object id                              [ObjNumber_t][-1 ... 39]
  @glob_out         pt_SITOutput->f_DistXFarObjId: Longitudinal distance of the blockedpath far object            [m]
  @glob_out         pt_SITOutput->f_CloseObjDistTraj: Distance to the trajectory of the blockedpath close object  [m]
  @glob_out         pt_SITOutput->f_FarObjDistTraj: Distance to the trajectory of the blockedpath far object      [m]

  @glob_in          -

  @c_switch_part   -

  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.12.2017
  @changed         -

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_ResetBlockedPathOutputs(ObjNumber_t t_CloseObjID, ObjNumber_t t_FarObjID)
{
  /* Reset output values when there are no blocked path objects */
  pt_SITOutput->t_BlockedPathCloseObjID = t_CloseObjID;
  pt_SITOutput->t_BlockedPathFarObjID = t_FarObjID;
  pt_SITOutput->f_DistXFarObjId = 0.f;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_SITOutput->f_DistXCloseObjId = 0.f;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  pt_SITOutput->f_CloseObjDistTraj = 0.f;
  pt_SITOutput->f_FarObjDistTraj = 0.f;
}
/*************************************************************************************************************************
  Functionname:    SIT_v_SetBlockedPathAtLaneChange                                                                                   */ /*!

  @brief           Blocked path objects (CloseObjId) and (FarObjId) are set again based on Lane change situation

  @description     Function sets the Close object and the far object for blocked path considering if there is a lane change 
                    and calculates several parameters of CloseObjId and FarObjId like object distance to trajectory and
                    longitudinal distance of these two objects for further usage in the blocked path decision making.

                     @startuml
                     Partition SIT_v_SetBlockedPathAtLaneChange{
                     Start
                     : Get Actual Speed;
                     If (CloseObjId and FarObjId is Initialised) then (TRUE)
                     If (Lane change to the left) then (TRUE)
                     : set the objects in the direction of the lane change to the CloseObjId;
                     Elseif (Lane change to the right) then (TRUE)
                     : set the objects in the direction of the lane change to the CloseObjId;
                     Else (FALSE)
                     Endif
                     : calculate corridor objects inner edge distance to trajectory;
                     : calculate x-dist depending y-hysteresis between corridor objects;
                     : apply dist-x hysteresis;
                     : Hysteresis is turned OFF when far object becomes\n close and close object becomes far Object;
                     If (FarObjId is Last Cyacle Obj ID) then (TRUE)
                     : calculate relevant object depending hysteresis between corridor objects;
                     : apply rel hysteresis;
                     Elseif (CloseObjId is Last Cyacle Obj ID) then (TRUE)
                     : calculate relevant object depending hysteresis between corridor objects;
                     : apply rel hysteresis;
                     Else (FALSE)
                     : No RelObject Selection Hysteresis;
                     Endif
                     Else (FALSE)
                     Endif
                     : Get Object ID of the Nearer, farther object, Distance to trajectory of the Close and Far Object\n in the Block path pair Longitudinal Displacement of the Far Object;
                     End
                     }
                     @enduml

  @return          -

  @param[in,out]   CloseObjId : Closer object among the two objects that are blocking the path according to preliminary blocked path 
                    calculation                                                                                           [ObjNumber_t][-1 ... 39]
  @param[in,out]   FarObjId : Farther object among the two objects that are blocking the path according to preliminary blocked path 
                    calculation                                                                                           [ObjNumber_t][-1 ... 39]

  @glob_out         pt_SITOutput->f_DistXFarObjId: Longitudinal distance of the blockedpath far object
  @glob_out         pt_SITOutput->f_DistXCloseObjId: Longitudinal distance of the blockedpath Close object
  @glob_out         pt_SITOutput->f_CloseObjDistTraj: Distance to the trajectory of the blockedpath close object
  @glob_out         pt_SITOutput->f_FarObjDistTraj: Distance to the trajectory of the blockedpath far object

  @glob_in          -

  @c_switch_part   -

  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.09.2017
  @changed         -

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SIT_v_SetBlockedPathAtLaneChange(ObjNumber_t CloseObjId, ObjNumber_t FarObjId)
{
  float32 fTTCGap, fTimeGap, fObj2ObjDistX, fCorridorSelectionOffsetY, fRelObjectHysteresisY;
  float32 FarObjDistTraj = 0.f, CloseObjDistTraj = 0.f, fDistXFarObjId = 0.f, fDistXCloseObjId = 0.f;
  float32 f_ObjVrelX_CloseObjId, f_ObjVrelX_FarObjId;
  const fVelocity_t ActualSpeed = *SLATE_pf_GetEgoLongVel();

  if ((CloseObjId >=0) && (FarObjId >=0))
  {
    float32 fFarObjWidth, fCloseObjWidth;
    boolean b_LaneChangeConsideration = FALSE;

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
    const LA_t_ScaleBracketState LC_State = *(LA_pt_ScaleBracketState());  /*!< Get lane change state */
    const float32 f_Dist2TrajFarObj = *(LA_pf_ObjToRefDistMeas(FarObjId));
    const float32 f_Dist2TrajCloseObj = *(LA_pf_ObjToRefDistMeas(CloseObjId));
    /* Set FarObjId and CloseObjId in case of a Lane Change; 
    set the objects in the direction of the lane change to the CloseObjId */
    if (LC_State == SLATE_PRE_LANE_CHANGE_LEFT)
    { 
      if(f_Dist2TrajFarObj > f_Dist2TrajCloseObj)
      {
        const ObjNumber_t ObjTemp = CloseObjId;
        CloseObjId = FarObjId;
        FarObjId = ObjTemp;
      }
      b_LaneChangeConsideration = TRUE;
    }
    else if (LC_State == SLATE_PRE_LANE_CHANGE_RIGHT)// PRQA S 2004 
      /* date: 2015-06-30, reviewer: Gangadhar Badiger, reason: conditions are checking in if and elseif, else is not required*/
    {
      if(f_Dist2TrajFarObj < f_Dist2TrajCloseObj)
      {
        const ObjNumber_t ObjTemp = CloseObjId;
        CloseObjId = FarObjId;
        FarObjId = ObjTemp;
      }
      b_LaneChangeConsideration = TRUE;
    }
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
    LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
    LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
#endif /*FCT_CFG_ACC_LANE_ASSOCIATION*/
      
      /*Defining local variable from reference pointer*/
      fDistXCloseObjId = *SLATE_pf_GetObjLongDisp(CloseObjId);
      fDistXFarObjId = *SLATE_pf_GetObjLongDisp(FarObjId);
      
      /* Use Hysteresis in case of no lane change */
      if (b_LaneChangeConsideration == FALSE)// PRQA S 3358,3355
      /* date: 2015-10-01, reviewer: Gangadhar Badiger, reason:b_LaneChangeConsideration is always FALSE since TRUE part is diabled by conditional MACRO*/
    {
      fFarObjWidth = SIT_f_GetObjectWidthInLane(FarObjId);
      fCloseObjWidth = SIT_f_GetObjectWidthInLane(CloseObjId);

      /*calculate corridor objects inner edge distance to trajectory*/
      FarObjDistTraj    = *(LA_pf_ObjToRefDistMeas(FarObjId));

      FarObjDistTraj    = fABS(FarObjDistTraj) - (0.5f * fFarObjWidth);
      FarObjDistTraj    = MAX_FLOAT(0.0f, FarObjDistTraj);

      CloseObjDistTraj  = *(LA_pf_ObjToRefDistMeas(CloseObjId));
      CloseObjDistTraj  = fABS(CloseObjDistTraj) - (0.5f * fCloseObjWidth);
      CloseObjDistTraj  = MAX_FLOAT(0.0f,CloseObjDistTraj);

      /*calculate x-dist depending y-hysteresis between corridor objects */
	  f_ObjVrelX_CloseObjId = *SLATE_pf_GetObjVrelX(CloseObjId);/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
	  f_ObjVrelX_FarObjId   = *SLATE_pf_GetObjVrelX(FarObjId);/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
      fTTCGap = MIN_FLOAT( -fDistXCloseObjId/MIN_FLOAT(f_ObjVrelX_CloseObjId,-1.0f)
		,-fDistXFarObjId/MIN_FLOAT(f_ObjVrelX_FarObjId,-1.0f) );

      fObj2ObjDistX = fDistXFarObjId - fDistXCloseObjId;

      fCorridorSelectionOffsetY =   dGDBmathLineareFunktion(&CorrSelOffsetYObj2ObjDistX , fObj2ObjDistX);
      fCorridorSelectionOffsetY *=  dGDBmathLineareFunktion(&CorrSelOffsetYTTCGapWeight , fTTCGap);

      /*apply dist-x hysteresis*/
      FarObjDistTraj   += fCorridorSelectionOffsetY;
      CloseObjDistTraj -= fCorridorSelectionOffsetY;

	  // Hysteresis is turned OFF when far object becomes close and close object becomes far Object
	  if( ( pt_SITOutput->t_BlockedPathCloseObjID != FarObjId) && (pt_SITOutput->t_BlockedPathFarObjID != CloseObjId) )/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact on the functionality. */
	  {

		  if(FarObjId == t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI])
		  {
			fTimeGap = fDistXFarObjId/MAX_FLOAT(ActualSpeed,0.1f);
			/* calculate relevant object depending hysteresis between corridor objects*/
			fRelObjectHysteresisY = dGDBmathLineareFunktion(&CorrSelOffsetYTimeGapWeight , fTimeGap);
			/*apply rel hysteresis*/
			FarObjDistTraj-=fRelObjectHysteresisY;
			CloseObjDistTraj+=fRelObjectHysteresisY;
		  }
		  else if(CloseObjId == t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI])
		  {
			fTimeGap = fDistXCloseObjId/MAX_FLOAT(ActualSpeed,0.1f);
			/* calculate relevant object depending hysteresis between corridor objects*/
			fRelObjectHysteresisY = dGDBmathLineareFunktion(&CorrSelOffsetYTimeGapWeight , fTimeGap);
			/*apply rel hysteresis*/
			FarObjDistTraj+=fRelObjectHysteresisY;
			CloseObjDistTraj-=fRelObjectHysteresisY;
		  }
		  else
		  {
			/*No RelObject Selection Hysteresis*/
		  }
	  }

    }
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
#if ( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
  LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )
    else
    {// PRQA S 3201
      /* date: 2015-10-01, reviewer: Gangadhar Badiger, reason: control will reach else part only when b_LaneChangeConsideration is TRUE, currently TRUE Part is disabled by MACRO*/
      /* In case of an lane change don't appy any hysteresis, 
      manipulate the distance to the acc trajectory in order 
      to select the object on the next lane */
      fCloseObjWidth = SIT_f_GetObjectWidthInLane(CloseObjId);

      CloseObjDistTraj  = *(LA_pf_ObjToRefDistMeas(CloseObjId));
      CloseObjDistTraj  = fABS(CloseObjDistTraj) - (0.5f * fCloseObjWidth);
      CloseObjDistTraj  = MAX_FLOAT(0.0f,CloseObjDistTraj);

      FarObjDistTraj = CloseObjDistTraj + 1.f;
    }
#endif /*( LA_CFG_ADAPT_TRACEBRACKETS_LC_BASED_ON_POS_INLANE_CAM && \
    LA_CFG_ADAPT_TRACEBRACKETS_NOLC_BASED_ON_POS_INLANE_CAM && \
    LA_CFG_ADAPT_TRACEBRACKETS_BLINKER_FEATURE_BASED_ON_POS_INLANE_CAM )*/
#endif /*FCT_CFG_ACC_LANE_ASSOCIATION*/
  }
  pt_SITOutput->t_BlockedPathCloseObjID = CloseObjId;
  pt_SITOutput->t_BlockedPathFarObjID = FarObjId;
  pt_SITOutput->f_DistXFarObjId = fDistXFarObjId;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  pt_SITOutput->f_DistXCloseObjId = fDistXCloseObjId;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  pt_SITOutput->f_CloseObjDistTraj = CloseObjDistTraj;
  pt_SITOutput->f_FarObjDistTraj = FarObjDistTraj;
}
/*************************************************************************************************************************
  Functionname:    SIT_v_FillStat2StatPathOccupation                                                                    */ /*!

  @brief           This function fills static object occupation list

  @description     This function fills the path occupation array of structures with the information from all the static objects

                   @startuml
                   Partition SIT_v_FillStat2StatPathOccupation{
                   Start
                   : Get right, left, first free entries;
                   : Set path width for all objects;
                   : Initialize path occupation list;
                   : Search sorted  object list for objects touching track;
                   : Crossing objects are excluded from corridor selection list;
                   If (Object type STATIONARY OR MOVING &&\n Vehicle Speed less than STAT Speed) then (TRUE)
                   : Set object data structure for path occupation list entry;
                   Else (FALSE)
                   Endif
                   If (Measured distance to trajectory right side) then (TRUE)
                   : Insert to right path of list;
                   : Recalculate distance to trajectory using absolute value and respecting object width;
                   Elseif (Measured distance to trajectory left side) then (TRUE)
                   : Insert to left path of list;
                   : Recalculate distance to trajectory using absolute value and respecting object width;
                   Else (FALSE)
                   Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       SITPathOccupation : The filled occupation array of datatype SIT_t_PathOccupation as defined in si_ext.h

  @glob_in         t_LA_Output.LABasePreselObjList[i] : Array of variable to store pre-selection decision for objects        [TRUE, FALSE]
                                                        array size [0u ... EM_N_OBJECTS-1]
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : number of objects [0 ... EM_N_OBJECTS] with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @todo            Remove direct usage of access functions

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_FillStat2StatPathOccupation (SIT_t_PathOccupationArray SITPathOccupation)
{
  ObjNumber_t i, j;
  uint32  ActualR = STATIC_OBJECT_OCCUPATION_RIGHT_ENTRY; /* staring point for right entries is number 2 */ 
  uint32  ActualL = STATIC_OBJECT_OCCUPATION_LEFT_ENTRY; /* staring point for left entries is number 3 */
  uint32  NextFree = STATIC_OBJECT_OCCUPATION_FREE_ENTRY;/* so first free entry is number 4 */
  const fVelocity_t TempVehicleSpeed = *SLATE_pf_GetEgoLongVel(); /* Note: Direct access to function given because function called in OOI*/
  float32 GetObjVrelX;
  SLATE_t_Obj_DynamicProperty ObjDynProperty;
  fVelocity_t VehicleSpeed;
  ObjNumber_t t_NumOfObjectsUsed;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SLATE_t_Obj_DynamicSubProperty ObjDynSubProperty;
#endif

  
  SIT_t_PathOccInsertObjData  SITPathOccInsertObjData;

  /* set path width for all objects */
  SITPathOccInsertObjData.HalbeSpurbreite = SIT_HALF_LANEOCCUPATION_WIDTH;

  /* initialize path occupation list */
  SIT_v_InitSiPathOccupation(SITPathOccupation,SITPathOccInsertObjData.HalbeSpurbreite);

  /* search sorted  object list for objects touching track */
  t_NumOfObjectsUsed = SLATE_t_GetNumOfObjectsUsed();
  for(j = 0; j < t_NumOfObjectsUsed; j++)
  {
    i = *SLATE_pu_GetDistXSortedObj(j);
    /* do not use empty objects or not preselected objects or objects of different dynamic property */
    /* slow moving objects are handled as stationary objects; definition of slow moving is constant
       SIT_CORR_SEL_MOVING_AS_STAT_SPEED */
    /* crossing objects are excluded from corridor selection list */
     GetObjVrelX=*SLATE_pf_GetObjVrelX(i);
     ObjDynProperty=*SLATE_pt_GetObjDynProperty(i);
     VehicleSpeed=TempVehicleSpeed + GetObjVrelX;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
     ObjDynSubProperty=*SLATE_pt_GetObjDynSubProperty(i);
#endif /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
    if(( ((ObjDynProperty == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
       || (ObjDynProperty == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
         )
         ||( (ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)
          &&((VehicleSpeed) < SIT_CORR_SEL_MOVING_AS_STAT_SPEED)))
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      &&(t_LA_Output.LABasePreselObjList[i] == TRUE)
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      &&(ObjDynSubProperty!= SLATE_OBJECT_SUBPROP_CROSSING)
#endif /* END IF (FCT_USE_EM_ARS_TECH_OBJECT_LIST) */
      )
    {
      const float32 fObjHalfWidth = 0.5f * SIT_f_GetObjectWidthInLane(i);
      const float32 fObjLength    = (pt_SITInput->pt_FIPOA->t_ObjList[i].fObjectLength);
      /* set object data structure for path occupation list entry */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      SITPathOccInsertObjData.DistTrajToObjEdge = *(LA_pf_ObjToRefDistMeas(i));
#endif
      SITPathOccInsertObjData.ObjID = i;
      SITPathOccInsertObjData.CalculatedObjLength = SIT_f_CalcDriveAroundDist(TempVehicleSpeed)
                                                 + fObjLength
                                                 + FCT_WHEELBASE_DEFAULT;
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      SITPathOccInsertObjData.ObjDistOnTraj = *(LA_pf_ObjDistOnTraj(i));
#endif

      /* left side or right side ? */
      if(SITPathOccInsertObjData.DistTrajToObjEdge < 0.f)
      {
        /* right side, so insert to right path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        SITPathOccInsertObjData.DistTrajToObjEdge = fABS(SITPathOccInsertObjData.DistTrajToObjEdge) - fObjHalfWidth;
        SIT_v_InsertObjInPathOcc(SITPathOccupation,&ActualR,&NextFree,&SITPathOccInsertObjData);
      }
      else
      {
        /* left side, so insert to left path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        SITPathOccInsertObjData.DistTrajToObjEdge = fABS(SITPathOccInsertObjData.DistTrajToObjEdge) - fObjHalfWidth;
        SIT_v_InsertObjInPathOcc(SITPathOccupation,&ActualL,&NextFree,&SITPathOccInsertObjData);
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_FillMov2MovPathOccupation                                                                      */ /*!

  @brief           This function handles call of entry function for occupied path list

  @description     This function calculates the moving to moving object occupied path

                   @startuml
                   Partition SIT_v_FillMov2MovPathOccupation{
                   Start
                   : Get right, left, first free entries;
                   : Set path width for all objects;
                   : Initialize path occupation list;
                   : Search sorted object list for objects touching track;
                   : Crossing objects are excluded from corridor selection list;
                   If (Object type MOVING &&\n object dynamic sub property is not crossing) then (TRUE)
                   : Set object data structure for path occupation list entry;
                   Else (FALSE)
                   Endif
                   If (Measured distance to trajectory right side) then (TRUE)
                   : Insert to right path of list;
                   : Recalculate distance to trajectory using absolute value and respecting object width;
                   Elseif (Measured distance to trajectory left side) then (TRUE)
                   : Insert to left path of list;
                   : Recalculate distance to trajectory using absolute value and respecting object width;
                   Else (FALSE)
                   Endif
                   End
                   }
                   @enduml

  @return          -

  @param[in]       SITPathOccupation : The array of moving to moving object occupation information of type SIT_t_PathOccupation defined in si_ext.h
  @param[out]      -

  @glob_in         t_LA_Output.LABasePreselObjList[i] : Array of variable to store pre-selection decision for objects             [TRUE, FALSE]
  @glob_in         SLATE_t_GetNumOfObjectsUsed() : number of objects [0 ... EM_N_OBJECTS] with EM_N_OBJECTS as in Rte_SWCEmAdapt_Type.h                    
  @glob_out        -

  @c_switch_part   FCT_CFG_ACC_LANE_ASSOCIATION : FCT support for ACC LA (Lane Association) sub-component
  @c_switch_full   FCT_CFG_ACC_SITUATION        :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @todo            Remove direct usage of access functions

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_FillMov2MovPathOccupation (SIT_t_PathOccupationArray SITPathOccupation)
{
  ObjNumber_t i,j;
  uint32  ActualR = STATIC_OBJECT_OCCUPATION_RIGHT_ENTRY; /* staring point for right entries is number 2 */ 
  uint32  ActualL = STATIC_OBJECT_OCCUPATION_LEFT_ENTRY; /* staring point for left entries is number 3 */
  uint32  NextFree = STATIC_OBJECT_OCCUPATION_FREE_ENTRY;/* so first free entry is number 4 */
  SLATE_t_Obj_DynamicProperty ObjDynProperty;
  ObjNumber_t t_NumOfObjectsUsed;
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SLATE_t_Obj_DynamicSubProperty ObjDynSubProperty;
#endif

  SIT_t_PathOccInsertObjData  SITPathOccInsertObjData;

  /* set path width for all objects */
  SITPathOccInsertObjData.HalbeSpurbreite = SIT_HALF_LANEOCCUPATION_WIDTH;

  /* initialize path occupation list */
  SIT_v_InitSiPathOccupation(SITPathOccupation,SITPathOccInsertObjData.HalbeSpurbreite);

  /* search sorted  object list for objects touching track */
  t_NumOfObjectsUsed = SLATE_t_GetNumOfObjectsUsed();
  for(j = 0; j < t_NumOfObjectsUsed; j++)
  {
    i = *SLATE_pu_GetDistXSortedObj(j);
    /* do not use empty objects or not preselected objects or objects of different dynamic property */
    /* crossing objects are excluded from corridor selection list */
    ObjDynProperty=*SLATE_pt_GetObjDynProperty(i);
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    ObjDynSubProperty=*SLATE_pt_GetObjDynSubProperty(i);
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
    if( (ObjDynProperty == SLATE_OBJECT_PROPERTY_MOVING)      
#if (FCT_CFG_ACC_LANE_ASSOCIATION)   
      &&(t_LA_Output.LABasePreselObjList[i] == TRUE)
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      &&(ObjDynSubProperty != SLATE_OBJECT_SUBPROP_CROSSING)
#endif /* END IF FCT_USE_EM_ARS_TECH_OBJECT_LIST */
      )
    {
      const float32 fObjHalfWidth = 0.5f * SIT_f_GetObjectWidthInLane(i);
      const float32 fObjLength = (pt_SITInput->pt_FIPOA->t_ObjList[i].fObjectLength);

      /* set object data structure for path occupation list entry */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      SITPathOccInsertObjData.DistTrajToObjEdge = *(LA_pf_ObjToRefDistMeas(i));
#endif
      SITPathOccInsertObjData.ObjID = i;
      SITPathOccInsertObjData.CalculatedObjLength = SIT_f_CalcDriveAroundDist(-*SLATE_pf_GetObjVrelX(i)) 
                                                 + fObjLength
                                                 + FCT_WHEELBASE_DEFAULT;
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
      SITPathOccInsertObjData.ObjDistOnTraj = *(LA_pf_ObjDistOnTraj(i));
#endif

      /* left side or right side ? */
      if(SITPathOccInsertObjData.DistTrajToObjEdge < 0.f)
      {
        /* right side, so insert to right path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        SITPathOccInsertObjData.DistTrajToObjEdge = fABS(SITPathOccInsertObjData.DistTrajToObjEdge) - fObjHalfWidth;
        SIT_v_InsertObjInPathOcc(SITPathOccupation,&ActualR,&NextFree,&SITPathOccInsertObjData);
      }
      else
      {
        /* left side, so insert to left path of list */
        /* recalculate distance to trajectory using absolute value and respecting object width */
        SITPathOccInsertObjData.DistTrajToObjEdge = fABS(SITPathOccInsertObjData.DistTrajToObjEdge) - fObjHalfWidth;
        SIT_v_InsertObjInPathOcc(SITPathOccupation,&ActualL,&NextFree,&SITPathOccInsertObjData);
      }
    }
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitSiPathOccupation                                                                           */ /*!

  @brief           Initialization of occupied path list

  @description     Initialize the passed SITPathOccupation array for later filling with path occupation information 
                   (for calculating narrow vehicle path)

                    @startuml
                    Partition SIT_v_InitSiPathOccupation{
                    Start
                    : Initialize entire list like Longitudnal distance from Ego to Object\n, Width of trace bracket, object ID;
                    : Set starting points;
                    End
                    }
                    @enduml

  @return          -

  @param[in/out]   SITPathOccupation : The filled occupation array of datatype SIT_t_PathOccupation as defined in si_ext.h
                      LengthTrajEgoFrontToObj : Longitudnal distance from Ego to Object           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      DistTrajToObjEdge : Width of trace bracket                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      objID : object ID                                                           [-1...39]
                      next : Pointer of type SITPathOccupationStruct
                      prev : Pointer of type SITPathOccupationStruct
  @param[in]       HalfLaneWidth : Half of assumed lane width                                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_InitSiPathOccupation (SIT_t_PathOccupationArray SITPathOccupation, float32 HalfLaneWidth)
{
  uint8 i;
  /* SITPathOccupation entries 0 and 1 are starting points of the list.
  SITPathOccupation[0] is starting point for right side with Distance to Trajectory of
  half trackwidth.
  SITPathOccupation[1] is starting point for left side with Distance to Trajectory of
  half trackwidth.
  This is to find the first entry of narrow track and to keep information of trackwidth within the list. */
  
  /*initialize entire list */
  for(i=0u; i<(uint8)SIT_PATH_OCC_ENTRIES;i++)
  {
    SITPathOccupation[i].LengthTrajEgoFrontToObj = 0.0f;
    SITPathOccupation[i].DistTrajToObjEdge = HalfLaneWidth;
    SITPathOccupation[i].ObjID = OBJ_INDEX_NO_OBJECT;
    SITPathOccupation[i].prev = NULL;
    SITPathOccupation[i].next = NULL;
  }
  /* set starting points */
  SITPathOccupation[0].next = &SITPathOccupation[2];
  SITPathOccupation[1].next = &SITPathOccupation[3];

  SITPathOccupation[2].prev = &SITPathOccupation[0];
  SITPathOccupation[3].prev = &SITPathOccupation[1];

  SITPathOccupation[2].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT; 
  SITPathOccupation[3].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT;


}


/*************************************************************************************************************************
  Functionname:    SIT_v_InsertObjInPathOcc                                                                             */ /*!

  @brief           Insert object into path occupation structure

  @description     Insert occupation information into array of occupation structures

                    @startuml
                    Partition SIT_v_InsertObjInPathOcc{
                    Start
                    If (last entry at this side nearer than new entry?) then (TRUE)
                    : Insert first point of object;
                    : Prepare second point of object;
                    : Insert second point of object;
                    : Prepare next edge entry;
                    Else (FALSE)
                    : first look for distance to insert new edge;
                    : now look for path width of new entry;
                    If (new edge is farer away than this entry insert new edge) then (TRUE)
                    : Get Ego Trajectory, Distance, Obj ID;
                    If (new entry is last in list) then (TRUE)
                    : Insert second point of object (object length);
                    : Prepare next edge entry;
                    Else (FALSE)
                    : New entry was not last in list, so look for\n position to insert second edge of entry;
                    If (point is nearer but narrower than actual entry) then (TRUE)
                    : next entry in list;
                    : next free space increased;
                    Else (FALSE)
                    If (entry is nearer and wider than new entry) then (TRUE)
                    : This point once was endpoint of an object, narrower than actual;
                    : next entry in list;
                    Else (FALSE)
                    : A point wider than actual entry so delete it from list;
                    Endif
                    Endif
                    Endif
                    Else (FALSE)
                    If (new entry is nearer than found wider edge) then (TRUE)
                    : second edge of object is even nearer than found wider edge\n so even do not save that point;
                    Elseif (Next is NULL) then (TRUE)
                    : Refill Distance of Trajectory of new previous with\n actual Distance of Trajectory of object;
                    : The found entry was last in list so directly\n insert second point after that entry;
                    Else (FALSE)
                    : new entry was not last in list, so look\n for position to insert second edge of entry;
                    If (this point is nearer but narrower than actual entry) then (TRUE)
                    : next entry in list;
                    Else (FALSE)
                    If (this entry is nearer and wider than new entry) then (TRUE)
                    : next entry in list;
                    Else (FALSE)
                    : seems to be a point wider than actual entry so delete it from list;
                    Endif
                    Endif
                    Endif
                    Endif
                    Endif
                    End
                    }
                    @enduml

  @return          -

  @param[in]       SITPathOccupation : The filled occupation array of datatype SIT_t_PathOccupation as defined in si_ext.h
                      LengthTrajEgoFrontToObj : Longitudnal distance from Ego to Object                        [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      PathWidth : Width of trace bracket                                                       [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      ObjID : object ID                                                                        [-1...39]
                      next : Pointer of type SITPathOccupationStruct
                      prev : Pointer of type SITPathOccupationStruct
  @param[in,out]   ActualEntry : Last filled entry in SITPathOccupation                                        [0...39]
  @param[in,out]   NextFree : Index of next free entry in SITPathOccupation                                    [0...39]
  @param[in]       SITPathOccInsertObjDataPtr : Pointer to occupation object data to insert
                      ObjID : Object ID                                                                        [-1...39]
                      HalbeSpurbreite : Half lane width                                                        [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      CalculatedObjLength : Calculated object lenght                                           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      DistTrajToObjEdge : Distance of trajectory to object edge                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      ObjDistOnTraj : Distance from EGO center of gravity to trajectory object reference point [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_InsertObjInPathOcc(SIT_t_PathOccupationArray SITPathOccupation,
                                 uint32* ActualEntry, uint32* NextFree, 
                                 const SIT_t_PathOccInsertObjData * SITPathOccInsertObjDataPtr)
{
SIT_t_PathOccupation* List_insert_ptr = NULL;
SIT_t_PathOccupation* last_deleted = NULL;
  
   /* last entry at this side nearer than new entry ? */
  if(SITPathOccupation[*ActualEntry].LengthTrajEgoFrontToObj < SITPathOccInsertObjDataPtr->ObjDistOnTraj)
  {
    /* this is the simple case: add new edge at the end of the list */
    /* insert first point of object */
    SITPathOccupation[*ActualEntry].next                  = &SITPathOccupation[*NextFree];
    SITPathOccupation[*NextFree].prev                     = &SITPathOccupation[*ActualEntry];
    SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj  = SITPathOccInsertObjDataPtr->ObjDistOnTraj;
    SITPathOccupation[*NextFree].DistTrajToObjEdge        = SITPathOccInsertObjDataPtr->DistTrajToObjEdge;
    SITPathOccupation[*NextFree].ObjID                    = SITPathOccInsertObjDataPtr->ObjID;
    
    /* prepare second point entry */
    *ActualEntry = *NextFree;
    (*NextFree)++;

    /* insert second point of object (object length)*/
    SITPathOccupation[*ActualEntry].next            = &SITPathOccupation[*NextFree];
    SITPathOccupation[*NextFree].prev           = &SITPathOccupation[*ActualEntry];
    SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                    + SITPathOccInsertObjDataPtr->CalculatedObjLength;
    SITPathOccupation[*NextFree].DistTrajToObjEdge         = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
    SITPathOccupation[*NextFree].ObjID              = OBJ_INDEX_NO_OBJECT;
    SITPathOccupation[*NextFree].next           = NULL;

    /* prepare next edge entry */
    *ActualEntry = *NextFree;
    (*NextFree)++;
  }/* end simple case */
  else
  {
    /* now it gets complex: the new entry must be inserted between the previous found entries*/
    /* first look for distance to insert new edge */
    List_insert_ptr = &SITPathOccupation[*ActualEntry];
    while((List_insert_ptr->LengthTrajEgoFrontToObj > SITPathOccInsertObjDataPtr->ObjDistOnTraj)
        &&(List_insert_ptr->prev != NULL))
    {
      List_insert_ptr = List_insert_ptr->prev;
    }
    
    /* ListInsertPtr now stands at list entry nearer than new edge */
    /* now look for path width of new entry */
    while((List_insert_ptr->DistTrajToObjEdge < SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
        &&(List_insert_ptr->next != NULL))
    {
      List_insert_ptr = List_insert_ptr->next;
    }

    /* ListInsertPtr now stands at list entry wider than new edge */
    /* if new edge is farer away than this entry insert new edge as follower of ListInsertPtr*/
    if(SITPathOccInsertObjDataPtr->ObjDistOnTraj > List_insert_ptr->LengthTrajEgoFrontToObj)
    {
      SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj    = SITPathOccInsertObjDataPtr->ObjDistOnTraj;
      SITPathOccupation[*NextFree].DistTrajToObjEdge  = SITPathOccInsertObjDataPtr->DistTrajToObjEdge;
      SITPathOccupation[*NextFree].ObjID              = SITPathOccInsertObjDataPtr->ObjID;
      SITPathOccupation[*NextFree].prev               = List_insert_ptr;
      SITPathOccupation[*NextFree].next               = List_insert_ptr->next;
      List_insert_ptr->next                         = &SITPathOccupation[*NextFree];
                      
      if(SITPathOccupation[*NextFree].next == NULL)
      {
        /* new entry is last in list, so directly insert second point */
        *ActualEntry = *NextFree;
        (*NextFree)++;
        /* insert second point of object (object length)*/
        SITPathOccupation[*ActualEntry].next            = &SITPathOccupation[*NextFree];
        SITPathOccupation[*NextFree].prev       = &SITPathOccupation[*ActualEntry];
        SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                        + SITPathOccInsertObjDataPtr->CalculatedObjLength;
        SITPathOccupation[*NextFree].DistTrajToObjEdge         = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
        SITPathOccupation[*NextFree].ObjID              = SITPathOccInsertObjDataPtr->ObjID;
        SITPathOccupation[*NextFree].next           = NULL;

        /* prepare next edge entry */
        *ActualEntry = *NextFree;
        (*NextFree)++;
      }
      else
      {
        /* new entry was not last in list, so look for position to insert second edge of entry */
        SITPathOccupation[*NextFree].next->prev = &SITPathOccupation[*NextFree];
        List_insert_ptr = SITPathOccupation[*NextFree].next;
        
        while((List_insert_ptr != NULL))
        {
          if (List_insert_ptr->LengthTrajEgoFrontToObj < (SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                        + SITPathOccInsertObjDataPtr->CalculatedObjLength ) )
          {
            if(List_insert_ptr->DistTrajToObjEdge <= SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
            {
              /* this point is nearer but narrower than actual entry, so keep it */

              /* next entry in list */
              List_insert_ptr = List_insert_ptr->next;
              
              /* do not forget to increment Pointer to next free space in SITPathOccupation */
              if(List_insert_ptr == NULL)
              {
                (*NextFree)++;
              }
            }
            else
            {
              /* this entry is nearer and wider than new entry */
              if(List_insert_ptr->prev->DistTrajToObjEdge < SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
              {
                /*This point once was endpoint of an object, narrower than actual, so keep it and
                just give it new ObjID and DistTrajToObjEdge data */
                List_insert_ptr->ObjID = SITPathOccInsertObjDataPtr->ObjID;
                List_insert_ptr->DistTrajToObjEdge = SITPathOccInsertObjDataPtr->DistTrajToObjEdge;
                
                /* next entry in list */
                List_insert_ptr = List_insert_ptr->next;

                /* do not forget to increment Pointer to next free space in SITPathOccupation */
                if(List_insert_ptr == NULL)
                {//PRQA S 715
                  /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason:Need to change control structure if rule agrred upon*/
                  (*NextFree)++;
                }
              }
              else
              {
                /* seems to be a point wider than actual entry so delete it from list (open chain)*/
                if(List_insert_ptr->next != NULL)
                {//PRQA S 715
                  /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Need to change control structure if rule agreed upon*/
                  SITPathOccupation[*NextFree].next = List_insert_ptr->next;
                  List_insert_ptr->next->prev     = &SITPathOccupation[*NextFree];
                  
                  last_deleted = List_insert_ptr;
                  
                  /* next entry in list */
                  List_insert_ptr = List_insert_ptr->next;
                }
                else
                {//PRQA S 715
                /* date: 2015-06-12, reviewer: Gangadhar Badiger,reason: Need to change control structure if rule agrred upon*/
                  (*NextFree)++;
                  /* insert second point of object (object length)*/
                  SITPathOccupation[*ActualEntry].prev->next            = &SITPathOccupation[*NextFree];
                  SITPathOccupation[*NextFree].prev                     = SITPathOccupation[*ActualEntry].prev;
                  SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj  = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                        + SITPathOccInsertObjDataPtr->CalculatedObjLength;
                  SITPathOccupation[*NextFree].DistTrajToObjEdge        = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
                  SITPathOccupation[*NextFree].ObjID                    = OBJ_INDEX_NO_OBJECT;
                  SITPathOccupation[*NextFree].next                     = NULL;

                  /* next entry in list */
                  List_insert_ptr = NULL;

                  /* prepare next edge entry */
                  *ActualEntry = *NextFree;
                  (*NextFree)++;
                }
              }
            }
          }
          else
          {
            if(List_insert_ptr->prev->DistTrajToObjEdge < SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
            {
              /* do not insert entry, because t is wider than already saved point */
              /* break condition for while loop */
              List_insert_ptr = NULL;
              (*NextFree)++;
            }
            else
            {
              /*found insertion point for new entry */
              (*NextFree)++;
              /* insert second point of object (object length)*/
              List_insert_ptr->prev->next                         = &SITPathOccupation[*NextFree];
              SITPathOccupation[*NextFree].prev                     = List_insert_ptr->prev;
              SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj  = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                    + SITPathOccInsertObjDataPtr->CalculatedObjLength;
              if(last_deleted != NULL)
              {
                SITPathOccupation[*NextFree].DistTrajToObjEdge      = last_deleted->DistTrajToObjEdge;
                SITPathOccupation[*NextFree].ObjID                  = last_deleted->ObjID ;
              }
              else
              {
                SITPathOccupation[*NextFree].DistTrajToObjEdge      = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
                SITPathOccupation[*NextFree].ObjID                  = OBJ_INDEX_NO_OBJECT;
              }
              SITPathOccupation[*NextFree].next                     = List_insert_ptr;
              List_insert_ptr->prev                               = &SITPathOccupation[*NextFree];

              /* break condition for while loop */
              List_insert_ptr = NULL;

              /* prepare next edge entry */
              (*NextFree)++;
            }
          }
        }
      }
    }
    else
    {
      /* new entry is nearer than found wider edge --> do not save first point of object !!*/
      /* ListInsertPtr still stands at list entry wider than new edge */
      if(List_insert_ptr->LengthTrajEgoFrontToObj > ( SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                    + SITPathOccInsertObjDataPtr->CalculatedObjLength) )
      {
        /* second edge of object is even nearer than found wider edge so even do not save that point */
      }
      else if(List_insert_ptr->next == NULL)
      {
        /* refill DistTrajToObjEdge of new previous with actual DistTrajToObjEdge */
        List_insert_ptr->DistTrajToObjEdge = SITPathOccInsertObjDataPtr->DistTrajToObjEdge;
        
        /* the found entry was last in list so directly insert second point after that entry*/
        List_insert_ptr->next                               = &SITPathOccupation[*NextFree];
        SITPathOccupation[*NextFree].prev                     = List_insert_ptr;
        SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj  = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                              + SITPathOccInsertObjDataPtr->CalculatedObjLength;
        SITPathOccupation[*NextFree].DistTrajToObjEdge        = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
        SITPathOccupation[*NextFree].ObjID                    = SITPathOccInsertObjDataPtr->ObjID;
        SITPathOccupation[*NextFree].next                     = NULL;

        /* prepare next edge entry */
        *ActualEntry = *NextFree;
        (*NextFree)++;
      }
      else
      {
        /* new entry was not last in list, so look for position to insert second edge of entry */
        List_insert_ptr = List_insert_ptr->next;
        
        while((List_insert_ptr != NULL))
        {
          if (List_insert_ptr->LengthTrajEgoFrontToObj < (SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                        + SITPathOccInsertObjDataPtr->CalculatedObjLength ) )
          {
            if(List_insert_ptr->DistTrajToObjEdge <= SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
            {
              /* this point is nearer but narrower than actual entry, so keep it */

              /* next entry in list */
              List_insert_ptr = List_insert_ptr->next;
            }
            else
            {
              /* this entry is nearer and wider than new entry */
              if(List_insert_ptr->prev->DistTrajToObjEdge < SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
              {
                /*This point once was endpoint of an object, narrower than actual, so keep it and
                just give it new ObjID and DistTrajToObjEdge data */
                List_insert_ptr->ObjID = SITPathOccInsertObjDataPtr->ObjID;
                List_insert_ptr->DistTrajToObjEdge = SITPathOccInsertObjDataPtr->DistTrajToObjEdge;
                
                /* next entry in list */
                List_insert_ptr = List_insert_ptr->next;
              }
              else
              {
                /* seems to be a point wider than actual entry so delete it from list (open chain)*/
                if(List_insert_ptr->next != NULL)//PRQA S 715
                  /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Need to change control structure if rule agrred upon*/
                {
                  List_insert_ptr->next->prev     = List_insert_ptr->prev;
                  List_insert_ptr->prev->next     = List_insert_ptr->next;
                                              
                  last_deleted = List_insert_ptr;
                  /* next entry in list */
                  List_insert_ptr = List_insert_ptr->next;
                }
                else
                {
                  /* insert second point of object (object length)*/
                  SITPathOccupation[*ActualEntry].prev->next                = &SITPathOccupation[*NextFree];
                  SITPathOccupation[*NextFree].prev                     = SITPathOccupation[*ActualEntry].prev;
                  SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj  = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                        + SITPathOccInsertObjDataPtr->CalculatedObjLength;
                  SITPathOccupation[*NextFree].DistTrajToObjEdge        = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
                  SITPathOccupation[*NextFree].ObjID                    = OBJ_INDEX_NO_OBJECT;
                  SITPathOccupation[*NextFree].next                     = NULL;

                  /* next entry in list */
                  List_insert_ptr = NULL;

                  /* prepare next edge entry */
                  *ActualEntry = *NextFree;
                  (*NextFree)++;
                }
              }
            }
          }
          else
          {
            if(List_insert_ptr->prev->DistTrajToObjEdge < SITPathOccInsertObjDataPtr->DistTrajToObjEdge)
            {
              /* do not insert entry, because t is wider than already saved point */
              /* break condition for while loop */
              List_insert_ptr = NULL;
            }
            else
            {
              /* insert second point of object (object length)*/
              List_insert_ptr->prev->next                          = &SITPathOccupation[*NextFree];
              SITPathOccupation[*NextFree].prev                     = List_insert_ptr->prev;
              SITPathOccupation[*NextFree].LengthTrajEgoFrontToObj  = SITPathOccInsertObjDataPtr->ObjDistOnTraj 
                                                                    + SITPathOccInsertObjDataPtr->CalculatedObjLength;
              if(last_deleted != NULL)
              {
                SITPathOccupation[*NextFree].DistTrajToObjEdge      = last_deleted->DistTrajToObjEdge;
                SITPathOccupation[*NextFree].ObjID                  = last_deleted->ObjID ;
              }
              else
              {
                SITPathOccupation[*NextFree].DistTrajToObjEdge      = SITPathOccInsertObjDataPtr->HalbeSpurbreite;
                SITPathOccupation[*NextFree].ObjID                  = OBJ_INDEX_NO_OBJECT;
              }
              SITPathOccupation[*NextFree].next                     = List_insert_ptr;
              List_insert_ptr->prev                               = &SITPathOccupation[*NextFree];

              /* break condition for while loop */
              List_insert_ptr = NULL;

              /* prepare next edge entry */
              (*NextFree)++;
            }
          }
        }
      }
    }
  }/* end of complex case */

}//PRQA S 7004
/* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Not a Safety critical issue*/

/*************************************************************************************************************************
  Functionname:    SIT_f_CalcDriveAroundDist                                                                            */ /*!

  @brief           Calculate Distance That Ego Vehicle Travels while Changing lane (sy = 2m)

  @description     Calculate Distance That Ego Vehicle Travels while Changing lane (sy = 2m)

                    @startuml
                    Partition SIT_f_CalcDriveAroundDist{
                    Start
                    : Return Distance That Ego Vehicle Travels while Changing lane (sy = 2m);
                    End
                    }
                    @enduml

  @return          static float32 : Return Drive Around distance                                       [Full range of float32 >= 0] m

  @param[in]       EgoSpeedXObjSync : Ego vehicles speed                                               [-330.f ... 330.f] m/s 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Norman Apel | Norman Apel@continental-corporation.com | 
*************************************************************************************************************************/
static float32 SIT_f_CalcDriveAroundDist(float32 EgoSpeedXObjSync)
{
  return MAX_FLOAT(EgoSpeedXObjSync,LAT_LANECHANGE_MINSPEED) * LAT_LANECHANGE_TIME;
}

/*************************************************************************************************************************
  Functionname:    SIT_v_CalcOccPathWidth                                                                               */ /*!

  @brief           Calculate resulting path widths out of path occupation array

  @description     Calculate the available width of the vehicle path between the obstacles (objects) in the way

                    @startuml
                    Partition SIT_v_CalcOccPathWidth{
                    Start
                    : Result structure initialization path widths;
                    : Calculate path width at actual entry point;
                    : save object IDs of participating objects;
                    : save distance from sensor of actual entry point;
                    : prepare next entry;
                    If (next closest entry point on any side?) then (TRUE)
                    If (next closest entry point is on right or left side?) then (TRUE)
                    : next entry is left;
                    Elseif (entry?) then (TRUE)
                    : next entry is right;
                    Else (FALSE)
                    : if entry points on both sides are of equal distance, set both;
                    Endif
                    Elseif (entry points on right) then (TRUE)
                    : no more entries on left side, so set right entry as next;
                    Elseif (entry points on left) then (TRUE)
                    : no more entries on right side, so set left entry as next;
                    Else (FALSE)
                    : no more entries on both sides, set both;
                    Endif
                    End
                    }
                    @enduml

  @return          -

  @param[in]       SITPathOcc : Array of SIT_t_PathOccupation entries which describe vehicle path obstacles on right and left side (chained)
  @param[in]       SiPathhOccResult : Array which describes how narrow vehicle path is at given distances

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_CalcOccPathWidth(const SIT_t_PathOccupation SITPathOcc[SIT_PATH_OCC_ENTRIES],
                               SIT_t_PathOccResultArray SiPathhOccResult)
{
  const SIT_t_PathOccupation* ActualR = &SITPathOcc[0]; /* right start point is entry 0 */
  const SIT_t_PathOccupation* ActualL = &SITPathOcc[1]; /* left start point is entry 1 */
  SIT_t_PathOccResult*  NextResult = &SiPathhOccResult[0]; /* result structure start point is 0 */

  /* initialize result structure */
  SIT_v_InitSiPathOccResult(SiPathhOccResult,ActualR->DistTrajToObjEdge);

  /* as long as there are entries on any side */
  while((ActualR != NULL)&&(ActualL != NULL))
  {
    /* Calculate path width at actual entry point */
    NextResult->PathWidth = ActualR->DistTrajToObjEdge + ActualL->DistTrajToObjEdge;
    /* save object IDs of participating objects */
    NextResult->ObjIDR = ActualR->ObjID;
    NextResult->ObjIDL = ActualL->ObjID;
    /* save distance from sensor of actual entry point */
    NextResult->LengthTrajEgoFrontToObj = MAX_FLOAT(ActualR->LengthTrajEgoFrontToObj,ActualL->LengthTrajEgoFrontToObj);
    
    /*prepare next entry*/
    NextResult++;//PRQA S 489
  /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
    if((ActualR->next!=NULL) && (ActualL->next!= NULL))
    {
      /* Look if next closest entry point is on right or left side */
      if(ActualR->next->LengthTrajEgoFrontToObj > ActualL->next->LengthTrajEgoFrontToObj)
      {
        /* next entry is left */
        ActualL = ActualL->next;
      }
      else if(ActualR->next->LengthTrajEgoFrontToObj < ActualL->next->LengthTrajEgoFrontToObj)
      {
        /* next entry is right */
        ActualR = ActualR->next;
      }
      else
      {
        /* if entry points on both sides are of equal distance, set both of them */
        ActualL = ActualL->next;
        ActualR = ActualR->next;
      }
    }
    else if(ActualR->next!=NULL)
    {
      /* no more entries on left side, so set right entry as next */
      ActualR = ActualR->next;
    }
    else if(ActualL->next!=NULL)
    {
      /* no more entries on right side, so set left entry as next */
      ActualL = ActualL->next;
    }
    else
    {
      /* no more entries on both sides, set both to break while loop */
      ActualL = ActualL->next;
      ActualR = ActualR->next;
    }
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_InitSiPathOccResult                                                                            */ /*!

  @brief           Initialize result structure for calculating path widths

  @description     Initialize the path occupation result array of structs

                    @startuml
                    Partition SIT_v_InitSiPathOccResult{
                    Start
                    : Get Longitudnal distance from Ego to Object, Width of trace bracket, object ID;
                    End
                    }
                    @enduml

  @return          -

  @param[out]      SITPathhOccResult : Array which describe path width between an object and an obstacle which form a corridor 
                      LengthTrajEgoFrontToObj : Longitudnal distance from Ego to Object [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      PathWidth : Width of trace bracket                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      ObjIDL : object ID                                                [-1...39]
                      ObjIDR : object ID                                                [-1...39]
  @param[in]       HalfLaneWidth : half lane width                                      [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @author          Fridolin Kolb| fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_InitSiPathOccResult(SIT_t_PathOccResultArray SITPathhOccResult, float32 HalfLaneWidth)
{
  uint8 i;
  const float32 LaneWidth = 2.f * HalfLaneWidth;

  for(i=0u; i<(uint8)SIT_PATH_OCC_ENTRIES;i++)
  {
    SITPathhOccResult[i].LengthTrajEgoFrontToObj = SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT;
    SITPathhOccResult[i].PathWidth               = LaneWidth;
    SITPathhOccResult[i].ObjIDL                  = OBJ_INDEX_NO_OBJECT;
    SITPathhOccResult[i].ObjIDR                  = OBJ_INDEX_NO_OBJECT;
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_CheckForNarrowPath                                                                             */ /*!

  @brief           Look for narrow path and return nearest object causing this narrow path

  @description     Look for narrow path and return nearest object causing this narrow path 
                   or the left object if ego is in left most lane and the right object when ego is in right most lane.

                    @startuml
                    Partition SIT_v_CheckForNarrowPath{
                    Start
                    : Get Ego Speed;
                    : calculate passable corridor width depending on speed of corridor objects;
                    : check for closer object of both and report it as narrow object;
                    End
                    }
                    @enduml

  @return          -

  @param[in]       SITPathhOccResult : Array which describes how narrow vehicle path is at given distances
                      LengthTrajEgoFrontToObj : Longitudnal distance from Ego to Object                                             [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                      PathWidth : Width of trace bracket                                                                            [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                      ObjIDL : object ID                                                                                            [-1...39]
                      ObjIDR : object ID                                                                                            [-1...39]
  @param[in,out]   pCloseObjId : Pointer to the closer object blocking the path                                                     [-1 ... 39]
  @param[out]      pFarObjId : Pointer to the farther object blocking the path                                                      [-1 ... 39]

  @glob_in         pt_SITInput->t_RTE.pf_EgoLongVel : Ego Speed                                                                     [-330.f ... 330.f] m/s
  @glob_in         pt_SITInput->t_RTE.pf_ObjLongDisp : Macro to get longitudinal distance of given object                           [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
  @glob_in         pt_SITInput->t_RTE.pf_ObjVrelX : Longidudinal relative velocity for the given object                             [-330.f ... 330.f] m/s 
  @glob_in         pt_SITInput->t_RTE.pt_ObjDynProperty : Macro to obtain dynamic object property. This signal indicates whether
                                                          the object is moving, stationary or oncoming, based on comparison of the
                                                          l ongitudinal relative velocity with the host vehicle velocity,
                                                          defined in algo_glob.h                                                    [0...7]
  @glob_in         pt_SITInput->t_FIPOA.pb_ObjIsMovingToStationary : Macro which provides the information if the object is 
                                                 moving to stationary                                                               [TRUE, FALSE]
  @glob_in         t_SIT_LastCycleOOIObjID : Last cycle object id                                                                   [-1 ... 39]
  @glob_out        t_SITOutput.t_ObjList[NextResult->ObjIDR].t_Bool.SelectedByPathDecision : Selected By Path Decision              [TRUE,FALSE]


  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016
  
  @todo            Need to replace direct output variable access with local pointer. Currently put on hold since blocked path restructuring is pending.
                   Also replace global input t_SIT_LastCycleOOIObjID when doing outputs of OOI

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_CheckForNarrowPath(const SIT_t_PathOccResult SITPathhOccResult[SIT_PATH_OCC_ENTRIES],
                                 ObjNumber_t * const pCloseObjId,
                                 ObjNumber_t * const pFarObjId)
{
  SLATE_t_Obj_DynamicProperty ObjDynProp_ObjIDL, ObjDynProp_ObjIDR;
  boolean b_ObjIDL_IsMovingToStationary, b_ObjIDR_IsMovingToStationary;
  const fVelocity_t fEgoSpeed = *SLATE_pf_GetEgoLongVel();
  const SIT_t_PathOccResult* NextResult = &SITPathhOccResult[0];
  float32 fSpeedSlowObj, fDistXObjIDR, fDistXObjIDL, f_ObjIDRLongDisp, f_ObjIDLRLongDisp;
  float32 fPathwidthPassableMov;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  const sint8 i_NumOfLaneLeft      = pt_SITInput->pt_FIPLM->s_NumOfLaneLeft;   /* Get number of left lanes */
  const sint8 i_NumOfLaneRight     = pt_SITInput->pt_FIPLM->s_NumOfLaneRight;  /* Get number of right lanes */
  sint8 s_CamNumLaneLeft = pt_SITInput->pt_FIPLM->s_CamNumLaneLeft;
  sint8 s_CamNumLaneRight = pt_SITInput->pt_FIPLM->s_CamNumLaneRight;
  SIT_LC_t_LaneChangePhaseEnum tLCPhase = pt_SITOutput->t_LaneChangePhase.t_LCPhase;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  *pCloseObjId = OBJ_INDEX_NO_OBJECT;

  /* SITPathhOccResult is sorted by distance to sensor, so first detected blocked path is closest */
  while((NextResult->LengthTrajEgoFrontToObj < SIT_PATH_OCCUPATION_LENGTH_TRAJEGO_FRONT_TO_OBJECT)
        &&(*pCloseObjId < 0))
  {
    if( (NextResult->ObjIDL != OBJ_INDEX_NO_OBJECT)
      &&(NextResult->ObjIDR != OBJ_INDEX_NO_OBJECT))
    {
      /*Defining local variables from reference pointer*/
      ObjDynProp_ObjIDL = *SLATE_pt_GetObjDynProperty(NextResult->ObjIDL);
      ObjDynProp_ObjIDR = *SLATE_pt_GetObjDynProperty(NextResult->ObjIDR);
      b_ObjIDL_IsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(NextResult->ObjIDL);
      b_ObjIDR_IsMovingToStationary = SLATE_b_GetObjIsMovingToStationary(NextResult->ObjIDR);

      /*calculate passable corridor width depending on speed of corridor objects*/
      fSpeedSlowObj = fEgoSpeed + MIN_FLOAT( *SLATE_pf_GetObjVrelX(NextResult->ObjIDL)/* PRQA S 3455 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as it does not have any critical impact on the functionality. */
                                      ,*SLATE_pf_GetObjVrelX(NextResult->ObjIDR) );
      fPathwidthPassableMov = dGDBmathLineareFunktion(&CorrSelPathwidthPassableMov , fSpeedSlowObj);

      fDistXObjIDR = *SLATE_pf_GetObjLongDisp(NextResult->ObjIDR);
      fDistXObjIDL = *SLATE_pf_GetObjLongDisp(NextResult->ObjIDL);

      /*Scale down passable corridor if one object is very close to the ego-vehicle, so that the lateral position may be unstable*/
      if( (fDistXObjIDR < SIT_MAX_PATHWIDTH_PASSABLE_SCALE_DIST) 
        || (fDistXObjIDL < SIT_MAX_PATHWIDTH_PASSABLE_SCALE_DIST) )
      {
        fPathwidthPassableMov*=SIT_MIN_PATHWIDTH_PASSABLE_SCALE_FACTOR;
      }

      /* path is build up by two objects */
      if( /* check for moving - moving constellation --> Moving pathwidth is used */
          (  (  (ObjDynProp_ObjIDL == SLATE_OBJECT_PROPERTY_MOVING)
              ||(b_ObjIDL_IsMovingToStationary))
          &&( (ObjDynProp_ObjIDR == SLATE_OBJECT_PROPERTY_MOVING)
              ||(b_ObjIDR_IsMovingToStationary))
          &&(NextResult->PathWidth < fPathwidthPassableMov))
          /* check for moving - moving constellation with former relevance --> moving hysteresis pathwidth is used */
        ||( (( (ObjDynProp_ObjIDL == SLATE_OBJECT_PROPERTY_MOVING)
              ||(b_ObjIDL_IsMovingToStationary))
          &&( (ObjDynProp_ObjIDR == SLATE_OBJECT_PROPERTY_MOVING)
              ||(b_ObjIDR_IsMovingToStationary)))
          &&( (NextResult->ObjIDR == t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI])
            ||(NextResult->ObjIDL == t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI]))
          &&(NextResult->PathWidth < (fPathwidthPassableMov + SIT_MIN_PATHWIDTH_PASSABLE_MOV_HYST_ADD)))
        /* minimum one of the objects is stationary use stationary pathwidths */
        /* with former relevance....*/
        ||(( ((ObjDynProp_ObjIDL == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
           || (ObjDynProp_ObjIDL == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
             )
          || ( (ObjDynProp_ObjIDR == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
            || (ObjDynProp_ObjIDR == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
            ))
          &&(((NextResult->ObjIDR == t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI])
            ||(NextResult->ObjIDL == t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI])
            )
          &&(NextResult->PathWidth < SIT_MIN_PATHWIDTH_PASSABLE_STAT_HYST))
          )
        /* ...or without former relevance */
        ||(( ((ObjDynProp_ObjIDL == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
           || (ObjDynProp_ObjIDL == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
             )
          || ((ObjDynProp_ObjIDR == SLATE_OBJECT_PROPERTY_STATIONARY)
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
           || (ObjDynProp_ObjIDR == SLATE_OBJECT_PROPERTY_STOPPED)
#endif /* FCT_CFG_SENSOR_TYPE_CAMERA */
          ))
          &&(NextResult->PathWidth < SIT_MIN_PATHWIDTH_PASSABLE_STAT)))
      {
        /* found path width is to small */
        t_SITOutput.t_ObjList[NextResult->ObjIDR].t_Bool.SelectedByPathDecision = 1u;
        t_SITOutput.t_ObjList[NextResult->ObjIDL].t_Bool.SelectedByPathDecision = 1u;

#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)        
        if((i_NumOfLaneLeft == 0) && (s_CamNumLaneLeft == 0) && (t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI]!=NextResult->ObjIDR) && (tLCPhase == LC_NO_LANECHANGE))
        {
		  /* Ego is in left most Lane */
          *pCloseObjId  = NextResult->ObjIDL;
          *pFarObjId    = NextResult->ObjIDR;
          pt_SITOutput->t_LaneChangePhase.b_EgoLaneStatus = TRUE; /* Indicates Ego is in Left most lane */
        }
        else if((i_NumOfLaneRight == 0) && (s_CamNumLaneRight == 0) && (t_SIT_LastCycleOOIObjID[OBJ_NEXT_OOI]!=NextResult->ObjIDL) && (tLCPhase == LC_NO_LANECHANGE))
        {
		  /* Ego is in right most Lane */
          *pCloseObjId  = NextResult->ObjIDR;
          *pFarObjId    = NextResult->ObjIDL;
          pt_SITOutput->t_LaneChangePhase.b_EgoLaneStatus = TRUE; /* Indicates Ego is in Right most lane */
        }
        else
        {
          /* check for closer object of both and report it as narrow object*/
          f_ObjIDRLongDisp = *SLATE_pf_GetObjLongDisp(NextResult->ObjIDR);
          f_ObjIDLRLongDisp = *SLATE_pf_GetObjLongDisp(NextResult->ObjIDL);
          
		  if(f_ObjIDRLongDisp < f_ObjIDLRLongDisp)
          {
            *pCloseObjId  = NextResult->ObjIDR;
            *pFarObjId    = NextResult->ObjIDL;
          }
          else
          {
            *pCloseObjId  = NextResult->ObjIDL;
            *pFarObjId    = NextResult->ObjIDR;
          }
        }
#else
        /* check for closer object of both and report it as narrow object*/
        f_ObjIDRLongDisp = *SLATE_pf_GetObjLongDisp(NextResult->ObjIDR);
        f_ObjIDLRLongDisp = *SLATE_pf_GetObjLongDisp(NextResult->ObjIDL);
        if(f_ObjIDRLongDisp < f_ObjIDLRLongDisp)
        {
          *pCloseObjId  = NextResult->ObjIDR;
          *pFarObjId    = NextResult->ObjIDL;
        }
        else
        {
          *pCloseObjId  = NextResult->ObjIDL;
          *pFarObjId    = NextResult->ObjIDR;
        }
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
      }
    }
    NextResult++;//PRQA S 489
  /* date: 2015-06-12, reviewer: Gangadhar Badiger, reason: Application wide deviation to rule agreed upon*/
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_ResetBlockedPathDecision                                                                       */ /*!

  @brief           Reset blocked path decision bit

  @description     Reset blocked path decision bit (t_SITOutput.t_ObjList.t_Bool.SelectedByPathDecision)
                   for all objects, to be able to see which objects are selected
                   in this cycle

                   @startuml
                   Partition SIT_v_ResetBlockedPathDecision{
                   Start
                   : Reset selection bit for blocked path decision;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        t_SITOutput.t_ObjList[i].t_Bool.SelectedByPathDecision : Object was selected by blocked path of type ubit32_t            [0,1]
                      with i in [0u ... EM_N_OBJECTS-1]                                                       
  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016
  
  @todo            Need to replace direct output variable access with local pointer. Currently put on hold since blocked path restructuring is pending.

  @author          Fridolin Kolb | fridolin.1.kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_ResetBlockedPathDecision(void)
{
  ObjNumber_t i;

  for(i = 0; i< EM_N_OBJECTS; i++)
  {
    /* Reset selection bit for blocked path decision */
    t_SITOutput.t_ObjList[i].t_Bool.SelectedByPathDecision = 0u;
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_v_UpdateTimerBlockedPathDecision                                                                 */ /*!

  @brief           Update path selection timer if not selected by blocked path

  @description     Update blocked path decision timer for objects not selected in current cycle

                   @startuml
                   Partition SIT_v_UpdateTimerBlockedPathDecision{
                   Start
                   : Check if given object selected by blocked path decision in this cycle.\n If not, then decrease the path selection timer;
                   End
                   }
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         t_SITOutput.t_ObjList[i].t_Bool.SelectedByPathDecision : Object was selected by blocked path                  [0,1]
  @glob_in         t_SITOutput.t_ObjList[i].u_BlockedPathSelectionTimer : Path selection timer                                   [Full range of uint8]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             Each object's t_SIT_ObjectList.t_Bool.SelectedByPathDecision bit was set
                   if selected in current cycle to be blocking path. Otherwise
                   bit shall be cleared.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016
  
  @todo            Need to replace direct output variable access with local pointer. Currently put on hold since blocked path restructuring is pending.

  @author          Fridolin Kolb | Fridolin.1.Kolb@continental-corporation.com | 
*************************************************************************************************************************/
static void SIT_v_UpdateTimerBlockedPathDecision(void)
{
  ObjNumber_t i;

  for(i = 0; i< EM_N_OBJECTS; i++)
  {
    /* Check if given object selected by blocked path decision in this
    cycle. If not, then decrease the path selection timer */
    if(pt_SITOutput->t_ObjList[i].t_Bool.SelectedByPathDecision == 0u)
    {
      /* Object not selected by blocked path decision in this cycle, update
      timer */
      if(pt_SITOutput->t_ObjList[i].u_BlockedPathSelectionTimer > 1u)
      {
        pt_SITOutput->t_ObjList[i].u_BlockedPathSelectionTimer -= 1u;
      }
      else
      {
        pt_SITOutput->t_ObjList[i].u_BlockedPathSelectionTimer = 0u;
      }
    }
  }
}


/*************************************************************************************************************************
  Functionname:    SIT_f_GetObjectWidthInLane                                                                           */ /*!

  @brief           Get width of object

  @description     Get width of object to use in blocked path calculations

                    @startuml
                    Partition SIT_f_GetObjectWidthInLane{
                    Start
                    If (Object Class is SLATE_OBJCLASS_POINT) then (TRUE)
                    : Return object width;
                    Else (FALSE)
                    : Return object width;
                    Endif
                    End
                    }
                    @enduml

  @return          fObjectWidth: return object width depending on its classification
                                                    [SIT_VALID_OBJECT_WIDTH_IN_LANE_FOR_ARSOBJ_CLASS_POINT, SIT_OBJECT_WIDTH_IN_LANE_FOR_NON_ARSOBJ_CLASS_POINT] as defined in this file.

  @param[in]       iObject : object number          [0u ... EM_N_OBJECTS-1]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/7/2016

  @todo            Remove direct usage of access functions

  @author          Fridolin Kolb / Norman Apel | Fridolin.1.Kolb / Norman Apel@continental-corporation.com | 
*************************************************************************************************************************/
static float32 SIT_f_GetObjectWidthInLane(ObjNumber_t iObject)
{
  float32 fObjectWidth;
  SLATE_t_Obj_CLassification t_ObjClassification = *SLATE_pt_GetObjClassification(iObject);

  if (t_ObjClassification == SLATE_OBJCLASS_POINT)
  {
    fObjectWidth = SIT_VALID_OBJECT_WIDTH_IN_LANE_FOR_ARSOBJ_CLASS_POINT;
  }
  else
  {
    fObjectWidth = SIT_OBJECT_WIDTH_IN_LANE_FOR_NON_ARSOBJ_CLASS_POINT;
  }
  return fObjectWidth;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
///@}
#endif /* (FCT_CFG_ACC_SITUATION) */ 

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
// PRQA L:STTLN_EXCEEDED
