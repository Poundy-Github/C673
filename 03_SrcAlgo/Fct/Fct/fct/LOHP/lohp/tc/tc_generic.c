/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc_generic.c

DESCRIPTION:               Functions for ... purpose

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.04.2017

VERSION:                   $Revision: 1.13 $

---*/ /*---
CHANGES:                    $Log: tc_generic.c  $
CHANGES:                    Revision 1.13 2018/11/06 16:21:55CET uidj5069 
CHANGES:                    Implementation of "Target Follower System" for reference distance generation
CHANGES:                    Revision 1.12 2018/07/12 17:04:58CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Calibration Concept revised
CHANGES:                    Revision 1.11 2018/06/13 16:45:41CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Bugfix in Function <TC_b_IsRelevantObject()>
CHANGES:                    Revision 1.10 2018/04/17 14:12:46CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <TC_b_IsRelevantObject()> added for better object filtering
CHANGES:                    Revision 1.9 2018/04/05 11:07:46CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Overtake Support Feature implemented
CHANGES:                    Revision 1.8 2018/03/15 11:44:20CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Target Control Module extended for Multi Object Control
CHANGES:                    Revision 1.7 2017/11/30 10:28:06CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Synchronization of "AfterEngagement" and "AfterOverride" Condition Termination
CHANGES:                    Revision 1.6 2017/11/21 10:39:43CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Revision 1.5 2017/11/20 12:55:15CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Renaming to RTE Port Type Names
CHANGES:                    Revision 1.4 2017/10/23 16:34:41CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Assignment of new <b_Ready> state output for State Machine
CHANGES:                    Revision 1.3 2017/10/17 13:59:14CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Target Control Functionality
CHANGES:                    Revision 1.2 2017/10/10 13:58:31CEST Mistry, Niraj (uidq5738) 
CHANGES:                    Switch added
CHANGES:                    Revision 1.1 2017/10/05 09:47:42CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/01_Source_Code/LOHP/lohp/tc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "tc.h"
#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef enum
{
  TC_OOI_NEXT_LONG,
  TC_OOI_HIDDEN_LONG,
  TC_OOI_NEXT_LEFT,
  TC_OOI_NEXT_RIGHT,
  TC_OOI_HIDDEN_LEFT,
  TC_OOI_HIDDEN_RIGHT
}
TC_OOI_Object_t;

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/
static boolean TC_b_IsRelevantObject(const AccOOIGenAttributes_t *pt_AccOOIAttributes);
static void TC_v_UpdateTargetFollower(float32 f_VeloTar, float32 f_DistGap, float32 f_TimeGap, float32 f_CycleTime, TC_RefTargetFollower_t *pt_TargetFollower);

static void TC_v_SetCtrlLimits(TC_EngageState_t t_EngState, TC_OOI_Object_t t_OOI, percentage_t u_CutInOutProb, LOHP_OT_DIR_t t_OT_Dir, ControlLimitations_t *pt_CtrLim);
static void TC_v_SetTargetPrefs(const AccOOIGenKinematics_t *pt_OOI_Kin, TC_OOI_Object_t t_OOI, ObjNumber_t s_ObjID, percentage_t u_CutOutProb, percentage_t u_HeadwaySetting, LOHP_OT_DIR_t t_OT_Dir, TargetPreferences_t *pt_TarPref);
static uint8 TC_u_SetTargetVehicle(const AccOOIGenKinematics_t *pt_OOI_Kin, const LOHP_EgoVehicleInfo_t *pt_EVI, const TC_RefTargetFollower_t *pt_RTF, TargetVehicle_t *pt_TarVeh);
static void TC_v_UpdateEngState(const TargetFollowCommand_t *pt_TFC, const TargetFollowState_t *pt_TFS, boolean b_Override, TC_EngageState_t *pt_EngState);


void TC_v_Generic_Process(void)
{
#if (FCT_CFG_HP_TFC_PORT_CNT)

  ControlLimitations_t t_CtrLim, t_CtrLim_Def = {0};
  TargetPreferences_t t_TarPref, t_TarPref_Def = {0};
  TargetVehicle_t t_TarVeh, t_TarVeh_Def = {0};
  uint8 u_TargetSpeed, u_HeadwaySetting, u_CutInOutProb, i;
  ObjNumber_t s_ObjectID;
  LOHP_OT_DIR_t t_OT_Dir;

  switch (t_TC_Active_State)
  {
    case TC_AS_PASSIVE:
    default:
      /* Target Control State Output */
      t_TC_OUT_TCSP.pt_TCS->b_Ready = t_TC_IN_TVIP.pt_TVI->b_Valid && !t_TC_IN_TCCP.pt_FD->b_NoEngagement;
      t_TC_OUT_TCSP.pt_TCS->b_Active = FALSE;
      t_TC_OUT_TCSP.pt_TCS->b_TargetDetected = FALSE;
      t_TC_OUT_TCSP.pt_TCS->b_ControlAlert = FALSE;
      t_TC_OUT_TCSP.pt_TCS->u_DistanceRequested = 0u;
      t_TC_OUT_TCSP.pt_TCS->u_DistanceTarget = 0u;
      t_TC_OUT_TCSP.pt_TCS->u_SpeedTarget = 0u;

      /* Target Follow Command Output */
      for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[i].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[i].f_Distance = 0.0f;
        at_TC_Target_Follower[i].f_Velocity = 0.0f;
        at_TC_Target_Follower[i].f_Acceleration = 0.0f;

        at_TC_OUT_TFCP[i].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[i].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[i].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[i].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }

      break;

    case TC_AS_ACTIVE:
      /* Assign Headway Setting from HMI */
      u_HeadwaySetting = t_TC_IN_TCCP.pt_TCC->u_HeadwaySetting;

      /* Assign Overtake Direction for (Multi Object Control and Overtake Support) only */
#if (TC_CFG_MULTI_OBJECT_CONTROL_FEATURE)
#if (TC_CFG_OVERTAKE_SUPPORT_FEATURE)
        t_OT_Dir = t_TC_IN_TVIP.pt_TVI->OvertakeDirection;
#else
        t_OT_Dir = LOHP_OT_NONE;
#endif
#else
        t_OT_Dir = LOHP_OT_NONE;
#endif

      /* If Target OOI-0 detected */
      if (TC_b_IsRelevantObject(&t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Attributes))
      {
        /* Assign CutOut Probability from OOI-0 Object for Multi Object Control only */
#if (TC_CFG_MULTI_OBJECT_CONTROL_FEATURE)
        u_CutInOutProb = t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Attributes.uiCutInOutProbability;
#else
        u_CutInOutProb = 0u;
#endif

        /* Assign Object ID from OOI-0 Object */
        s_ObjectID = t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Attributes.uiObjectID;

        /* Define Control Limits depending on Engagement State */
        TC_v_SetCtrlLimits(t_TC_Engage_State, TC_OOI_NEXT_LONG, 0u, t_OT_Dir, &t_CtrLim);

        /* Define Target Preferences depending on OOI-0 Target */
        TC_v_SetTargetPrefs(&t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Kinematic, TC_OOI_NEXT_LONG, s_ObjectID, u_CutInOutProb, u_HeadwaySetting, t_OT_Dir, &t_TarPref);

        /* Assign Target Vehicle Kinematics from OOI-0 Target */
        u_TargetSpeed = TC_u_SetTargetVehicle(&t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Kinematic, t_TC_IN_EVIP.pt_EVI, &at_TC_Target_Follower[TC_OOI_NEXT_LONG], &t_TarVeh);

        /* Target Control State Output */
        t_TC_OUT_TCSP.pt_TCS->b_Ready = t_TC_IN_TVIP.pt_TVI->b_Valid && !t_TC_IN_TCCP.pt_FD->b_Disengagement;
        t_TC_OUT_TCSP.pt_TCS->b_Active = TRUE;
        t_TC_OUT_TCSP.pt_TCS->b_TargetDetected = TRUE;
        t_TC_OUT_TCSP.pt_TCS->b_ControlAlert = at_TC_IN_TFSP[0].pt_TFS->b_Active && at_TC_IN_TFSP[0].pt_TFS->b_ControlAlert;
        t_TC_OUT_TCSP.pt_TCS->u_DistanceRequested = (uint8)t_TarPref.f_RelLongDistReference;
        t_TC_OUT_TCSP.pt_TCS->u_DistanceTarget = (uint8)t_TarVeh.f_RelLongDist;
        t_TC_OUT_TCSP.pt_TCS->u_SpeedTarget = u_TargetSpeed;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[0].pt_TFC->b_Enable = TRUE;
        at_TC_OUT_TFCP[0].pt_TFC->t_CtrLimit = t_CtrLim;
        at_TC_OUT_TFCP[0].pt_TFC->t_TarPref = t_TarPref;
        at_TC_OUT_TFCP[0].pt_TFC->t_TarVeh = t_TarVeh;
      }
      else
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[0].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[0].f_Distance = 0.0f;
        at_TC_Target_Follower[0].f_Velocity = 0.0f;
        at_TC_Target_Follower[0].f_Acceleration = 0.0f;

        /* Target Control State Output */
        t_TC_OUT_TCSP.pt_TCS->b_Ready = t_TC_IN_TVIP.pt_TVI->b_Valid && !t_TC_IN_TCCP.pt_FD->b_Disengagement;
        t_TC_OUT_TCSP.pt_TCS->b_Active = TRUE;
        t_TC_OUT_TCSP.pt_TCS->b_TargetDetected = FALSE;
        t_TC_OUT_TCSP.pt_TCS->b_ControlAlert = FALSE;
        t_TC_OUT_TCSP.pt_TCS->u_DistanceRequested = 0u;
        t_TC_OUT_TCSP.pt_TCS->u_DistanceTarget = 0u;
        t_TC_OUT_TCSP.pt_TCS->u_SpeedTarget = 0u;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[0].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[0].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[0].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[0].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }

#if (TC_CFG_MULTI_OBJECT_CONTROL_FEATURE)

#if (FCT_CFG_HP_TFC_PORT_CNT > 1)
      /* If Target OOI-1 detected */
      if (TC_b_IsRelevantObject(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLong.Attributes))
      {
        /* Assign Object ID from OOI-1 Object */
        s_ObjectID = t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLong.Attributes.uiObjectID;

        /* Assign CutOut Probability from OOI-0 !!! Object */
        u_CutInOutProb = t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Attributes.uiCutInOutProbability;

        /* Define Control Limits depending on Engagement State and CutOut Probability of OOI-0 !!! Object */
        TC_v_SetCtrlLimits(t_TC_Engage_State, TC_OOI_HIDDEN_LONG, u_CutInOutProb, t_OT_Dir, &t_CtrLim);

        /* Define Target Preferences depending on OOI-1 Target */
        TC_v_SetTargetPrefs(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLong.Kinematic, TC_OOI_HIDDEN_LONG, s_ObjectID, 0u, u_HeadwaySetting, t_OT_Dir, &t_TarPref);

        /* Assign Target Vehicle Kinematics from OOI-1 Target */
        TC_u_SetTargetVehicle(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLong.Kinematic, t_TC_IN_EVIP.pt_EVI, &at_TC_Target_Follower[TC_OOI_HIDDEN_LONG], &t_TarVeh);

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[1].pt_TFC->b_Enable = TRUE;
        at_TC_OUT_TFCP[1].pt_TFC->t_CtrLimit = t_CtrLim;
        at_TC_OUT_TFCP[1].pt_TFC->t_TarPref = t_TarPref;
        at_TC_OUT_TFCP[1].pt_TFC->t_TarVeh = t_TarVeh;
      }
      else
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[1].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[1].f_Distance = 0.0f;
        at_TC_Target_Follower[1].f_Velocity = 0.0f;
        at_TC_Target_Follower[1].f_Acceleration = 0.0f;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[1].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[1].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[1].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[1].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT > 2)
      /* If Target OOI-2 detected */
      if (TC_b_IsRelevantObject(&t_TC_IN_TVIP.pt_TVI->AccOOINextLeft.Attributes))
      {
        /* Assign Object ID from OOI-2 Object */
        s_ObjectID = t_TC_IN_TVIP.pt_TVI->AccOOINextLeft.Attributes.uiObjectID;

        /* Assign CutIn Probability from OOI-2 Object */
        u_CutInOutProb = t_TC_IN_TVIP.pt_TVI->AccOOINextLeft.Attributes.uiCutInOutProbability;

        /* Define Control Limits depending on Engagement State and CutOut Probability of OOI-2 Object */
        TC_v_SetCtrlLimits(t_TC_Engage_State, TC_OOI_NEXT_LEFT, u_CutInOutProb, t_OT_Dir, &t_CtrLim);

        /* Define Target Preferences depending on OOI-2 Target */
        TC_v_SetTargetPrefs(&t_TC_IN_TVIP.pt_TVI->AccOOINextLeft.Kinematic, TC_OOI_NEXT_LEFT, s_ObjectID, 0u, u_HeadwaySetting, t_OT_Dir, &t_TarPref);

        /* Assign Target Vehicle Kinematics from OOI-2 Target */
        TC_u_SetTargetVehicle(&t_TC_IN_TVIP.pt_TVI->AccOOINextLeft.Kinematic, t_TC_IN_EVIP.pt_EVI, &at_TC_Target_Follower[TC_OOI_NEXT_LEFT], &t_TarVeh);

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[2].pt_TFC->b_Enable = TRUE;
        at_TC_OUT_TFCP[2].pt_TFC->t_CtrLimit = t_CtrLim;
        at_TC_OUT_TFCP[2].pt_TFC->t_TarPref = t_TarPref;
        at_TC_OUT_TFCP[2].pt_TFC->t_TarVeh = t_TarVeh;
      }
      else
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[2].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[2].f_Distance = 0.0f;
        at_TC_Target_Follower[2].f_Velocity = 0.0f;
        at_TC_Target_Follower[2].f_Acceleration = 0.0f;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[2].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[2].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[2].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[2].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT > 3)
      /* If Target OOI-3 detected */
      if (TC_b_IsRelevantObject(&t_TC_IN_TVIP.pt_TVI->AccOOINextRight.Attributes))
      {
        /* Assign Object ID from OOI-3 Object */
        s_ObjectID = t_TC_IN_TVIP.pt_TVI->AccOOINextRight.Attributes.uiObjectID;

        /* Assign CutIn Probability from OOI-3 Object */
        u_CutInOutProb = t_TC_IN_TVIP.pt_TVI->AccOOINextRight.Attributes.uiCutInOutProbability;

        /* Define Control Limits depending on Engagement State and CutOut Probability of OOI-3 Object */
        TC_v_SetCtrlLimits(t_TC_Engage_State, TC_OOI_NEXT_RIGHT, u_CutInOutProb, t_OT_Dir, &t_CtrLim);

        /* Define Target Preferences depending on OOI-3 Target */
        TC_v_SetTargetPrefs(&t_TC_IN_TVIP.pt_TVI->AccOOINextRight.Kinematic, TC_OOI_NEXT_RIGHT, s_ObjectID, 0u, u_HeadwaySetting, t_OT_Dir, &t_TarPref);

        /* Assign Target Vehicle Kinematics from OOI-3 Target */
        TC_u_SetTargetVehicle(&t_TC_IN_TVIP.pt_TVI->AccOOINextRight.Kinematic, t_TC_IN_EVIP.pt_EVI, &at_TC_Target_Follower[TC_OOI_NEXT_RIGHT], &t_TarVeh);

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[3].pt_TFC->b_Enable = TRUE;
        at_TC_OUT_TFCP[3].pt_TFC->t_CtrLimit = t_CtrLim;
        at_TC_OUT_TFCP[3].pt_TFC->t_TarPref = t_TarPref;
        at_TC_OUT_TFCP[3].pt_TFC->t_TarVeh = t_TarVeh;
      }
      else
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[3].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[3].f_Distance = 0.0f;
        at_TC_Target_Follower[3].f_Velocity = 0.0f;
        at_TC_Target_Follower[3].f_Acceleration = 0.0f;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[3].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[3].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[3].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[3].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT > 4)
      /* If Target OOI-4 detected */
      if (TC_b_IsRelevantObject(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLeft.Attributes))
      {
        /* Assign Object ID from OOI-4 Object */
        s_ObjectID = t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLeft.Attributes.uiObjectID;

        /* Assign CutIn Probability from OOI-4 Object */
        u_CutInOutProb = t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLeft.Attributes.uiCutInOutProbability;

        /* Define Control Limits depending on Engagement State and CutOut Probability of OOI-4 Object */
        TC_v_SetCtrlLimits(t_TC_Engage_State, TC_OOI_HIDDEN_LEFT, u_CutInOutProb, t_OT_Dir, &t_CtrLim);

        /* Define Target Preferences depending on OOI-4 Target */
        TC_v_SetTargetPrefs(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLeft.Kinematic, TC_OOI_HIDDEN_LEFT, s_ObjectID, 0u, u_HeadwaySetting, t_OT_Dir, &t_TarPref);

        /* Assign Target Vehicle Kinematics from OOI-4 Target */
        TC_u_SetTargetVehicle(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextLeft.Kinematic, t_TC_IN_EVIP.pt_EVI, &at_TC_Target_Follower[TC_OOI_HIDDEN_LEFT], &t_TarVeh);

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[4].pt_TFC->b_Enable = TRUE;
        at_TC_OUT_TFCP[4].pt_TFC->t_CtrLimit = t_CtrLim;
        at_TC_OUT_TFCP[4].pt_TFC->t_TarPref = t_TarPref;
        at_TC_OUT_TFCP[4].pt_TFC->t_TarVeh = t_TarVeh;
      }
      else
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[4].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[4].f_Distance = 0.0f;
        at_TC_Target_Follower[4].f_Velocity = 0.0f;
        at_TC_Target_Follower[4].f_Acceleration = 0.0f;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[4].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[4].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[4].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[4].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT > 5)
      /* If Target OOI-5 detected */
      if (TC_b_IsRelevantObject(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextRight.Attributes))
      {
        /* Assign Object ID from OOI-5 Object */
        s_ObjectID = t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextRight.Attributes.uiObjectID;

        /* Assign CutIn Probability from OOI-5 Object */
        u_CutInOutProb = t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextRight.Attributes.uiCutInOutProbability;

        /* Define Control Limits depending on Engagement State and CutOut Probability of OOI-5 Object */
        TC_v_SetCtrlLimits(t_TC_Engage_State, TC_OOI_HIDDEN_RIGHT, u_CutInOutProb, t_OT_Dir, &t_CtrLim);

        /* Define Target Preferences depending on OOI-5 Target */
        TC_v_SetTargetPrefs(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextRight.Kinematic, TC_OOI_HIDDEN_RIGHT, s_ObjectID, 0u, u_HeadwaySetting, t_OT_Dir, &t_TarPref);

        /* Assign Target Vehicle Kinematics from OOI-5 Target */
        TC_u_SetTargetVehicle(&t_TC_IN_TVIP.pt_TVI->AccOOIHiddenNextRight.Kinematic, t_TC_IN_EVIP.pt_EVI, &at_TC_Target_Follower[TC_OOI_HIDDEN_RIGHT], &t_TarVeh);

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[5].pt_TFC->b_Enable = TRUE;
        at_TC_OUT_TFCP[5].pt_TFC->t_CtrLimit = t_CtrLim;
        at_TC_OUT_TFCP[5].pt_TFC->t_TarPref = t_TarPref;
        at_TC_OUT_TFCP[5].pt_TFC->t_TarVeh = t_TarVeh;
      }
      else
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[5].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[5].f_Distance = 0.0f;
        at_TC_Target_Follower[5].f_Velocity = 0.0f;
        at_TC_Target_Follower[5].f_Acceleration = 0.0f;

        /* Target Follow Command Output */
        at_TC_OUT_TFCP[5].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[5].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[5].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[5].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }
#endif

#else /* (TC_CFG_MULTI_OBJECT_CONTROL_FEATURE) */

      /* Multi Object Control switched off - Ports [1..MAX] disabled */
      for (i=1; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
      {
        /* Deactivate Target Follower State */
        at_TC_Target_Follower[i].s_ObjectID = OBJ_INDEX_NO_OBJECT;
        at_TC_Target_Follower[i].f_Distance = 0.0f;
        at_TC_Target_Follower[i].f_Velocity = 0.0f;
        at_TC_Target_Follower[i].f_Acceleration = 0.0f;

        at_TC_OUT_TFCP[i].pt_TFC->b_Enable = FALSE;
        at_TC_OUT_TFCP[i].pt_TFC->t_CtrLimit = t_CtrLim_Def;
        at_TC_OUT_TFCP[i].pt_TFC->t_TarPref = t_TarPref_Def;
        at_TC_OUT_TFCP[i].pt_TFC->t_TarVeh = t_TarVeh_Def;
      }

#endif /* (TC_CFG_MULTI_OBJECT_CONTROL_FEATURE) */

      /* Update Engagement State according to active control limits and override */
      TC_v_UpdateEngState(at_TC_OUT_TFCP[0].pt_TFC, at_TC_IN_TFSP[0].pt_TFS, t_TC_IN_EVIP.pt_EVI->b_Override_Accel, &t_TC_Engage_State);

      break;
  }

#else /* (FCT_CFG_HP_TFC_PORT_CNT) */

  /* Target Control State Output */
  t_TC_OUT_TCSP.pt_TCS->b_Ready = FALSE;
  t_TC_OUT_TCSP.pt_TCS->b_Active = FALSE;
  t_TC_OUT_TCSP.pt_TCS->b_TargetDetected = FALSE;
  t_TC_OUT_TCSP.pt_TCS->b_ControlAlert = FALSE;
  t_TC_OUT_TCSP.pt_TCS->u_DistanceRequested = 0u;
  t_TC_OUT_TCSP.pt_TCS->u_DistanceTarget = 0u;
  t_TC_OUT_TCSP.pt_TCS->u_SpeedTarget = 0u;

#endif /* (FCT_CFG_HP_TFC_PORT_CNT) */
}


static boolean TC_b_IsRelevantObject(const AccOOIGenAttributes_t *pt_AccOOIAttributes)
{
  boolean b_Result;

  if (pt_AccOOIAttributes->uiObjectID != OBJ_INDEX_NO_OBJECT)
  {
    switch (pt_AccOOIAttributes->eDynamicProperty)
    {
    case EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY:
    case EM_GEN_OBJECT_DYN_PROPERTY_STOPPED:
    case EM_GEN_OBJECT_DYN_PROPERTY_MOVING:
      b_Result = TRUE;
      break;

    case EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING:
    case EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT:
    case EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT:
    case EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN:
    default:
      b_Result = FALSE;
      break;
    }
  }
  else
  {
    b_Result = FALSE;
  }

  return b_Result;
}


static void TC_v_UpdateTargetFollower(float32 f_VeloTar, float32 f_DistGap, float32 f_TimeGap, float32 f_CycleTime, TC_RefTargetFollower_t *pt_TargetFollower)
{
  float32 f_VeloNew, f_VeloMean;

  /* Eval Target Follower Acceleration */
  pt_TargetFollower->f_Acceleration = 4.0f * (pt_TargetFollower->f_Distance-f_DistGap) / CML_Sqr(f_TimeGap);

  /* Update Target Follower Velocity and Distance */
  f_VeloNew  =  pt_TargetFollower->f_Velocity + pt_TargetFollower->f_Acceleration * f_CycleTime;
  f_VeloMean = (pt_TargetFollower->f_Velocity + f_VeloNew) * 0.5f;
  pt_TargetFollower->f_Velocity = f_VeloNew;
  pt_TargetFollower->f_Distance += (f_VeloTar-f_VeloMean) * f_CycleTime;
}


static void TC_v_SetCtrlLimits(TC_EngageState_t t_EngState, TC_OOI_Object_t t_OOI, percentage_t u_CutInOutProb, LOHP_OT_DIR_t t_OT_Dir, ControlLimitations_t *pt_CtrLim)
{
  float32 f_DecelMaxEngageState, f_DecelMaxCutInOut;
  float32 f_CutInOutProb = (float32)u_CutInOutProb / 100.0f;

  /* Set Engagement State conditional Limits */
  switch (t_EngState)
  {
  case TC_ES_STANDARD:
  default:
    f_DecelMaxEngageState = f_tc_target_decel_max;
    break;

  case TC_ES_AFTER_ENGAGEMENT:
    f_DecelMaxEngageState = f_tc_target_decel_max_after_engagement;
    break;

  case TC_ES_DURING_OVERRIDE:
    f_DecelMaxEngageState = f_tc_target_decel_max_during_override;
    break;

  case TC_ES_AFTER_OVERRIDE:
    f_DecelMaxEngageState = f_tc_target_decel_max_after_override;
    break;
  }

  /* Set OOI Type conditional Limits */
  switch (t_OOI)
  {
  case TC_OOI_NEXT_LONG:
  default:
    f_DecelMaxCutInOut = f_tc_target_decel_max;
    break;

  case TC_OOI_HIDDEN_LONG:
    /* CutOut Probability belongs to corresponding OOI_NEXT_LONG Object */
    f_DecelMaxCutInOut = cal_calculate_param_value_1D (af_tc_cutinout_prob_bkp, af_tc_cutout_tar_decel_max, TC_CUTINOUT_PROB_CNT, f_CutInOutProb);
    break;

  case TC_OOI_NEXT_LEFT:
    if (t_OT_Dir == LOHP_OT_LEFT)
    {
      f_DecelMaxCutInOut = f_tc_target_decel_max;
    }
    else
    {
      f_DecelMaxCutInOut = cal_calculate_param_value_1D (af_tc_cutinout_prob_bkp, af_tc_cutin_tar_decel_max, TC_CUTINOUT_PROB_CNT, f_CutInOutProb);
    }
    break;

  case TC_OOI_NEXT_RIGHT:
    if (t_OT_Dir == LOHP_OT_RIGHT)
    {
      f_DecelMaxCutInOut = f_tc_target_decel_max;
    }
    else
    {
      f_DecelMaxCutInOut = cal_calculate_param_value_1D (af_tc_cutinout_prob_bkp, af_tc_cutin_tar_decel_max, TC_CUTINOUT_PROB_CNT, f_CutInOutProb);
    }
    break;

  case TC_OOI_HIDDEN_LEFT:
  case TC_OOI_HIDDEN_RIGHT:
    f_DecelMaxCutInOut = cal_calculate_param_value_1D (af_tc_cutinout_prob_bkp, af_tc_cutin_tar_decel_max, TC_CUTINOUT_PROB_CNT, f_CutInOutProb);
    break;
  }

  /* Set Minimum of Deceleration Limits */
  pt_CtrLim->f_LongDecelMax = CML_Max(f_DecelMaxEngageState, f_DecelMaxCutInOut);

  /* Set Unconditional Limits */
  pt_CtrLim->f_LongAccelMax   = f_tc_target_accel_max;
  pt_CtrLim->f_LongAccGradMax = f_tc_target_accel_grad_max;
  pt_CtrLim->f_LongDecGradMax = f_tc_target_decel_grad_max;
}


static void TC_v_SetTargetPrefs(const AccOOIGenKinematics_t *pt_OOI_Kin, TC_OOI_Object_t t_OOI, ObjNumber_t s_ObjID, percentage_t u_CutOutProb, percentage_t u_HeadwaySetting, LOHP_OT_DIR_t t_OT_Dir, TargetPreferences_t *pt_TarPref)
{
  float32 f_RefDistMin, f_RefDistMax, f_RefDistance;
  float32 f_RefTimeMin, f_RefTimeMax, f_RefTimeGap;
  float32 f_IntDistMin, f_IntDistMax, f_IntDistance;
  float32 f_IntTimeMin, f_IntTimeMax, f_IntTimeGap;
  float32 f_VeloTable, f_Distance, f_Intrusion;
  float32 f_DistAlertAbs, f_DistAlertRel, f_TimeGap, f_DistBlendFac;
  float32 f_CutOutProb = (float32)u_CutOutProb / 100.0f;
  float32 af_PrefAccel[TC_TARGET_SPEED_LONG_CNT];
  float32 af_DistError[TC_TARGET_SPEED_LONG_CNT];
  boolean b_ActIntCtrl;
  uint8 i, j;

  /* Use Target Velocity for interpolation if Object ID has changed */
  if (s_ObjID != at_TC_Target_Follower[t_OOI].s_ObjectID)
  {
    f_VeloTable = pt_OOI_Kin->fVabsX;
  }
  /* Use Target Follower State Velocity for interpolation else */
  else
  {
    f_VeloTable = at_TC_Target_Follower[t_OOI].f_Velocity;
  }

  /* Eval Reference Distance for Headway Min */
  f_RefDistMin = cal_calculate_param_value_1D(af_tc_target_speed_long_bkp, af_tc_tar_dist_long_ref_min, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Reference Distance for Headway Max */
  f_RefDistMax = cal_calculate_param_value_1D(af_tc_target_speed_long_bkp, af_tc_tar_dist_long_ref_max, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Final Reference Distance depending on Headway Setting */
  f_RefDistance = f_RefDistMin + (f_RefDistMax-f_RefDistMin)*(float32)u_HeadwaySetting/100.0f;

  /* Eval Reference Time Gap for Headway Min */
  f_RefTimeMin = cal_calculate_param_gradient_1D(af_tc_target_speed_long_bkp, af_tc_tar_dist_long_ref_min, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Reference Time Gap for Headway Max */
  f_RefTimeMax = cal_calculate_param_gradient_1D(af_tc_target_speed_long_bkp, af_tc_tar_dist_long_ref_max, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Final Reference Time Gap depending on Headway Setting */
  f_RefTimeGap = f_RefTimeMin + (f_RefTimeMax-f_RefTimeMin)*(float32)u_HeadwaySetting/100.0f;


  /* Eval Intrusion Distance for Headway Min */
  f_IntDistMin = cal_calculate_param_value_1D(af_tc_target_speed_long_bkp, af_tc_int_dist_long_rel_min, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Intrusion Distance for Headway Max */
  f_IntDistMax = cal_calculate_param_value_1D(af_tc_target_speed_long_bkp, af_tc_int_dist_long_rel_max, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Final Intrusion Distance depending on Headway Setting */
  f_IntDistance = f_IntDistMin + (f_IntDistMax-f_IntDistMin)*(float32)u_HeadwaySetting/100.0f;

  /* Eval Intrusion Time Gap for Headway Min */
  f_IntTimeMin = cal_calculate_param_gradient_1D(af_tc_target_speed_long_bkp, af_tc_int_dist_long_rel_min, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Intrusion Time Gap for Headway Max */
  f_IntTimeMax = cal_calculate_param_gradient_1D(af_tc_target_speed_long_bkp, af_tc_int_dist_long_rel_max, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);

  /* Eval Final Time Gap Distance depending on Headway Setting */
  f_IntTimeGap = f_IntTimeMin + (f_IntTimeMax-f_IntTimeMin)*(float32)u_HeadwaySetting/100.0f;
  

  /* Eval CutOut Target Distance Blending Factor */
  f_DistBlendFac = cal_calculate_param_value_1D(af_tc_cutinout_prob_bkp, af_tc_cutout_tar_dist_blend_fac, TC_CUTINOUT_PROB_CNT, f_CutOutProb);
  
  /* Assign Reference and Intrusion Distance depending on OOI Nr. */
  switch (t_OOI)
  {
  case TC_OOI_NEXT_LONG:
  default:
    f_TimeGap = f_RefTimeGap - f_IntTimeGap * f_DistBlendFac;
    f_Distance = f_RefDistance - f_IntDistance * f_DistBlendFac;
    f_Intrusion = f_IntDistance - f_IntDistance * f_DistBlendFac;
    b_ActIntCtrl = (t_OT_Dir != LOHP_OT_NONE);

    /* Eval Alert Distance absolut for OOI 0 only */
    f_DistAlertAbs = cal_calculate_param_value_1D(af_tc_target_speed_long_bkp, af_tc_tar_dist_long_alert, TC_TARGET_SPEED_LONG_CNT, f_VeloTable);
    break;

  case TC_OOI_HIDDEN_LONG:
  case TC_OOI_NEXT_LEFT:
  case TC_OOI_NEXT_RIGHT:
  case TC_OOI_HIDDEN_LEFT:
  case TC_OOI_HIDDEN_RIGHT:
    f_TimeGap = f_RefTimeGap;
    f_Distance = f_RefDistance;
    f_Intrusion = f_IntDistance;
    b_ActIntCtrl = FALSE;

    /* Alert Distance Default for OOI 1-5 */
    f_DistAlertAbs = 0.0f;
    break;
  }

  /* Initialize Target Follower State for new Target */
  if (s_ObjID != at_TC_Target_Follower[t_OOI].s_ObjectID)
  {
    at_TC_Target_Follower[t_OOI].f_Distance = f_Distance;
    at_TC_Target_Follower[t_OOI].f_Velocity = f_VeloTable;
    at_TC_Target_Follower[t_OOI].f_Acceleration = 0.0f;
    at_TC_Target_Follower[t_OOI].s_ObjectID = s_ObjID;
  }
  /* Update Target Follower State for existing Target */
  else
  {
    TC_v_UpdateTargetFollower(pt_OOI_Kin->fVabsX, f_Distance, f_TimeGap, f_TC_CycleTime, &at_TC_Target_Follower[t_OOI]);
  }
  
  if (t_OOI == TC_OOI_NEXT_LONG)
  {
    /* Eval Relative Alert Distance for OOI 0 only */
    f_DistAlertRel = at_TC_Target_Follower[t_OOI].f_Distance - f_DistAlertAbs;
  }
  else
  {
    /* Set Relative Alert Default Distance for OOI 1-5 */
    f_DistAlertRel = -1.0f;
  }
    

  /* Assign Results to Output Struct */
  pt_TarPref->f_RelLongDistReference = at_TC_Target_Follower[t_OOI].f_Distance;
  pt_TarPref->f_RelLongDistIntrusion = f_Intrusion;
  pt_TarPref->f_RelLongDistAlert     = f_DistAlertRel;
  pt_TarPref->b_ActiveIntrusionCtrl  = b_ActIntCtrl;

  /* Evaluate Target Distance Error Axis */
  for (i=0; i<TC_TAR_DIST_LONG_ERR_CNT; i++)
  {
    if (i == TC_TAR_DIST_LONG_ERR_CNT-2)
    {
      pt_TarPref->af_RelLongDistErr[i] = 0.0f;
    }
    else
    {
      for (j=0; j<TC_TARGET_SPEED_LONG_CNT; j++)
      {
        af_DistError[j] = af_tc_tar_dist_long_err[j][i];
      }
      pt_TarPref->af_RelLongDistErr[i] = cal_calculate_param_value_1D (af_tc_target_speed_long_bkp, af_DistError, TC_TARGET_SPEED_LONG_CNT, pt_OOI_Kin->fVabsX);
    }
  }

  /* Evaluate Preferred Acceleration Curve */
  for (i=0; i<TC_TAR_DIST_LONG_ERR_CNT; i++)
  {
    if (i == TC_TAR_DIST_LONG_ERR_CNT-2)
    {
      pt_TarPref->af_RelLongPrefAcc[i] = 0.0f;
    }
    else
    {
      for (j=0; j<TC_TARGET_SPEED_LONG_CNT; j++)
      {
        af_PrefAccel[j] = af_tc_accel_long_pref[j][i] * f_tc_accel_long_pref_fac;
      }
      pt_TarPref->af_RelLongPrefAcc[i] = cal_calculate_param_value_1D (af_tc_target_speed_long_bkp, af_PrefAccel, TC_TARGET_SPEED_LONG_CNT, pt_OOI_Kin->fVabsX);
    }
  }

  /* Assign corresponding Vector Description */
  pt_TarPref->u_RelLongDistErrorDynSize = TC_TAR_DIST_LONG_ERR_CNT;
  pt_TarPref->u_RelLongDistErrZeroIndex = TC_TAR_DIST_LONG_ERR_CNT-2;
}


static uint8 TC_u_SetTargetVehicle(const AccOOIGenKinematics_t *pt_OOI_Kin, const LOHP_EgoVehicleInfo_t *pt_EVI, const TC_RefTargetFollower_t *pt_RTF, TargetVehicle_t *pt_TarVeh)
{
  pt_TarVeh->f_RelLongDist = pt_OOI_Kin->fDistX - pt_RTF->f_Distance;
  pt_TarVeh->f_RelLongVelo = pt_RTF->f_Velocity - pt_EVI->f_LongVeloReal;
  pt_TarVeh->f_RelLongAccel = pt_RTF->f_Acceleration - pt_EVI->f_LongAcceleration;

  return (uint8)CML_Round(pt_OOI_Kin->fVabsX * CML_f_Kmh2Ms);
}


static void TC_v_UpdateEngState(const TargetFollowCommand_t *pt_TFC, const TargetFollowState_t *pt_TFS, boolean b_Override, TC_EngageState_t *pt_EngState)
{
  /* Engagement State Update depending on <b_Limited> and <b_Override> */
  switch (*pt_EngState)
  {
  case TC_ES_STANDARD:
    if (b_Override)
    {
      *pt_EngState = TC_ES_DURING_OVERRIDE;
    }
    break;

  case TC_ES_AFTER_ENGAGEMENT:
    if (b_Override)
    {
      *pt_EngState = TC_ES_DURING_OVERRIDE;
    }
    else if(!pt_TFC->b_Enable || pt_TFS->b_Active && !pt_TFS->b_Limited && (pt_TFS->f_LongDecelMax == pt_TFC->t_CtrLimit.f_LongDecelMax))
    {
      *pt_EngState = TC_ES_STANDARD;
    }
    break;

  case TC_ES_DURING_OVERRIDE:
    if (!b_Override)
    {
      *pt_EngState = TC_ES_AFTER_OVERRIDE;
    }
    break;

  case TC_ES_AFTER_OVERRIDE:
    if(!pt_TFC->b_Enable || pt_TFS->b_Active && !pt_TFS->b_Limited && (pt_TFS->f_LongDecelMax == pt_TFC->t_CtrLimit.f_LongDecelMax))
    {
      *pt_EngState = TC_ES_STANDARD;
    }
    break;

  default:
    *pt_EngState = TC_ES_STANDARD;
    break;
  }
}


#endif /* (FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC) */

