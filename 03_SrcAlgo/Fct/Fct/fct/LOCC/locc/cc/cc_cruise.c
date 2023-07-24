/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Cruise Control)

PACKAGENAME:               cc_cruise.c

DESCRIPTION:               Functions for cruise purpose

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             06.07.2017

VERSION:                   $Revision: 1.11 $

---*/ /*---
CHANGES:                    $Log: cc_cruise.c  $
CHANGES:                    Revision 1.11 2018/06/21 11:22:13CEST uidj5069 
CHANGES:                    Fault Tolerance of CC Behaviour improved
CHANGES:                    Revision 1.10 2018/06/11 14:11:32CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Remove old "Start Coordination"
CHANGES:                    Revision 1.9 2018/04/17 14:02:59CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Deleted input command <b_StartClearance> replaced by constant TRUE temporarily
CHANGES:                    Revision 1.8 2018/04/06 17:45:50CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    SetSpeed Decrementation corrected
CHANGES:                    Revision 1.7 2017/11/20 09:13:29CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Renaming to RTE Port Type Names
CHANGES:                    Revision 1.6 2017/11/02 15:46:48CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Implementation of new StateMachine to improve Stop&Go Behaviour
CHANGES:                    Revision 1.5 2017/10/26 17:02:17CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <CC_v_UpdateStandStill()> added to implement 3s allowed StandStill
CHANGES:                    Revision 1.4 2017/10/26 10:20:25CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <CC_f_CalcDispToRealSpdFact()> improved
CHANGES:                    Revision 1.3 2017/10/23 16:33:56CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Assignment of new <b_Ready> state output for State Machine
CHANGES:                    Revision 1.2 2017/10/10 17:27:37CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Updates acording to changes in struct type

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cc.h"
#if ((FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC))


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void CC_v_UpdateSetSpeed(boolean *pb_SpdStored, setspeed_t *pu_SetSpeedAct, ACT_CC_OP_t t_OpNew, ACT_CC_OP_t t_OpAct, float f_DispSpeed, setspeed_t u_SetSpeedExt, boolean b_Active);
static void CC_v_UpdateEngState(CC_EngageState_t *pt_EngState, ACT_CC_OP_t t_OpNew, ACT_CC_OP_t t_OpAct, boolean b_Limited, boolean b_Override);
static float CC_f_CalcDispToRealSpdFact(const LOCC_EgoVehicleInfo_t *pt_CC_IN_EVI, float *pf_EgoVeloFilt);
static float CC_f_CalcControlSetSpeed(setspeed_t u_SetSpeedAct, float f_DispToRealSpdFact);
static void CC_v_SetCtrlLimits(ControlLimitations_t *pt_CtrLim, CC_EngageState_t *pt_EngState);



void CC_v_CruiseProcess(uint8 u_VSC_ID)
{
#if (ACT_CFG_CC_VSC_PORT_CNT)

  boolean b_ArbitDriverMin;
  float f_DispToRealSpdFact;
  float f_ControlSetSpeed;
  ControlLimitations_t t_CtrLim;

  switch (t_CC_Active_State)
  {
    case CC_AS_PASSIVE:
    default:
      /* Update SetSpeed according to operation type */
      CC_v_UpdateSetSpeed(&b_CC_Speed_Stored, &u_CC_Set_Speed, t_CC_IN_CCCP.pt_CCC->t_Operation, t_CC_Operation_Act, t_CC_IN_EVIP.pt_EVI->f_LongVeloDisplay, t_CC_IN_CCCP.pt_CCC->u_SetSpeedExt, FALSE);

      /* Store current Operation */
      t_CC_Operation_Act = t_CC_IN_CCCP.pt_CCC->t_Operation;

      /* Vehicle Speed Command Output */
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_Enable = FALSE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_ArbitDriverMin = FALSE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->f_EgoLongVeloCmd = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongAccelMax = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongDecelMax = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongAccGradMax = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongDecGradMax = 0.0f;

      /* Cruise Control State Output */
      t_CC_OUT_CCSP.pt_CCS->b_Ready = !t_CC_IN_CCCP.pt_FD->b_NoEngagement;
      t_CC_OUT_CCSP.pt_CCS->b_Active = FALSE;
      t_CC_OUT_CCSP.pt_CCS->b_Override_Accel = FALSE;
      t_CC_OUT_CCSP.pt_CCS->b_Override_Decel = FALSE;
      t_CC_OUT_CCSP.pt_CCS->b_SpeedStored = b_CC_Speed_Stored;
      t_CC_OUT_CCSP.pt_CCS->u_SetSpeed = u_CC_Set_Speed;
      t_CC_OUT_CCSP.pt_CCS->t_Operation = t_CC_Operation_Act;

      break;

    case CC_AS_ACTIVE:
      /* Update SetSpeed according to operation type */
      CC_v_UpdateSetSpeed(&b_CC_Speed_Stored, &u_CC_Set_Speed, t_CC_IN_CCCP.pt_CCC->t_Operation, t_CC_Operation_Act, t_CC_IN_EVIP.pt_EVI->f_LongVeloDisplay, t_CC_IN_CCCP.pt_CCC->u_SetSpeedExt, TRUE);

      /* Calculate Tranformation Factor from Display Speed to Real Speed */
      f_DispToRealSpdFact = CC_f_CalcDispToRealSpdFact(t_CC_IN_EVIP.pt_EVI, &f_CC_EgoVeloFilt);

      /* Calculate Control SetSpeed */
      f_ControlSetSpeed = CC_f_CalcControlSetSpeed(u_CC_Set_Speed, f_DispToRealSpdFact);

      /* Define Control Limits depending on Engagement State */
      CC_v_SetCtrlLimits(&t_CtrLim, &t_CC_Engage_State);

      /* Define Driver Arbitration depending on function type */
      b_ArbitDriverMin = (t_CC_IN_CCCP.pt_CCC->t_Function == ACT_CC_FUN_LIM);

      /* Update Engagement State according to operation type, active control limits and override */
      CC_v_UpdateEngState(&t_CC_Engage_State, t_CC_IN_CCCP.pt_CCC->t_Operation, t_CC_Operation_Act, at_CC_IN_VSSP[u_VSC_ID].pt_VSS->b_Limited, t_CC_IN_EVIP.pt_EVI->b_Override_Accel);

      /* Store current Operation */
      t_CC_Operation_Act = t_CC_IN_CCCP.pt_CCC->t_Operation;

      /* Vehicle Speed Command Output */
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_Enable = TRUE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_ArbitDriverMin = b_ArbitDriverMin;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->f_EgoLongVeloCmd = f_ControlSetSpeed;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim = t_CtrLim;

      /* Cruise Control State Output */
      t_CC_OUT_CCSP.pt_CCS->b_Ready = !t_CC_IN_CCCP.pt_FD->b_Disengagement;
      t_CC_OUT_CCSP.pt_CCS->b_Active = TRUE;
      t_CC_OUT_CCSP.pt_CCS->b_Override_Accel = t_CC_IN_EVIP.pt_EVI->b_Override_Accel;
      t_CC_OUT_CCSP.pt_CCS->b_Override_Decel = t_CC_IN_EVIP.pt_EVI->b_Override_Decel;
      t_CC_OUT_CCSP.pt_CCS->b_SpeedStored = b_CC_Speed_Stored;
      t_CC_OUT_CCSP.pt_CCS->u_SetSpeed = u_CC_Set_Speed;
      t_CC_OUT_CCSP.pt_CCS->t_Operation = t_CC_Operation_Act;

      break;
  }
#endif

}


static void CC_v_UpdateSetSpeed(boolean *pb_SpdStored, setspeed_t *pu_SetSpeedAct, ACT_CC_OP_t t_OpNew, ACT_CC_OP_t t_OpAct, float f_DispSpeed, setspeed_t u_SetSpeedExt, boolean b_Active)
{
  /* If Operation is unchanged */
  if (t_OpNew == t_OpAct)
  {
    /* Do nothing */
    return;
  }

  switch (t_OpNew)
  {
  case ACT_CC_OP_NOP:
  default:
    if (b_Active && !*pb_SpdStored)
    {
      *pb_SpdStored = TRUE;
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (setspeed_t)f_DispSpeed);
    }
    break;

  case ACT_CC_OP_SPEED_SET_ACT:
    *pb_SpdStored = TRUE;
    *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (setspeed_t)f_DispSpeed);
    break;

  case ACT_CC_OP_SPEED_SET_EXT:
    *pb_SpdStored = TRUE;
    *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, u_SetSpeedExt);
    break;

  case ACT_CC_OP_SPEED_CLEAR:
    if (!b_Active)
    {
      *pb_SpdStored = FALSE;
      *pu_SetSpeedAct = 0u;
    }
    break;

  case ACT_CC_OP_SPEED_INC_1:
    if (*pb_SpdStored)
    {
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (*pu_SetSpeedAct / CC_INC_SPEED_1) * CC_INC_SPEED_1 + CC_INC_SPEED_1);
    }
    else if (b_Active)
    {
      *pb_SpdStored = TRUE;
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (setspeed_t)f_DispSpeed);
    }
    break;

  case ACT_CC_OP_SPEED_INC_2:
    if (*pb_SpdStored)
    {
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (*pu_SetSpeedAct / CC_INC_SPEED_2) * CC_INC_SPEED_2 + CC_INC_SPEED_2);
    }
    else if (b_Active)
    {
      *pb_SpdStored = TRUE;
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (setspeed_t)f_DispSpeed);
    }
    break;

  case ACT_CC_OP_SPEED_DEC_1:
    if (*pb_SpdStored)
    {
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, ((*pu_SetSpeedAct-1) / CC_DEC_SPEED_1) * CC_DEC_SPEED_1);
    }
    else if (b_Active)
    {
      *pb_SpdStored = TRUE;
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (setspeed_t)f_DispSpeed);
    }
    break;

  case ACT_CC_OP_SPEED_DEC_2:
    if (*pb_SpdStored)
    {
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, ((*pu_SetSpeedAct-1) / CC_DEC_SPEED_2) * CC_DEC_SPEED_2);
    }
    else if (b_Active)
    {
      *pb_SpdStored = TRUE;
      *pu_SetSpeedAct = CML_MinMax(CC_SET_SPEED_MIN, CC_SET_SPEED_MAX, (setspeed_t)f_DispSpeed);
    }
    break;
  }
}


static void CC_v_UpdateEngState(CC_EngageState_t *pt_EngState,ACT_CC_OP_t t_OpNew, ACT_CC_OP_t t_OpAct, boolean b_Limited, boolean b_Override)
{
  /* Engagement State Update depending on <t_OpAct> and <t_OpNew> */
  if ((t_OpNew != t_OpAct) && (t_OpNew != ACT_CC_OP_NOP))
  {
    *pt_EngState = CC_ES_STANDARD;
  }

  /* Engagement State Update depending on <b_Limited> and <b_Override> */
  switch (*pt_EngState)
  {
  case CC_ES_STANDARD:
    if (b_Override)
    {
      *pt_EngState = CC_ES_DURING_OVERRIDE;
    }
    break;

  case CC_ES_AFTER_ENGAGEMENT:
    if (b_Override)
    {
      *pt_EngState = CC_ES_DURING_OVERRIDE;
    }
    else if(!b_Limited)
    {
      *pt_EngState = CC_ES_STANDARD;
    }
    break;

  case CC_ES_DURING_OVERRIDE:
    if (!b_Override)
    {
      *pt_EngState = CC_ES_AFTER_OVERRIDE;
    }
    break;

  case CC_ES_AFTER_OVERRIDE:
    if(!b_Limited)
    {
      *pt_EngState = CC_ES_STANDARD;
    }
    break;

  default:
    *pt_EngState = CC_ES_STANDARD;
    break;
  }

}


static float CC_f_CalcDispToRealSpdFact(const LOCC_EgoVehicleInfo_t *pt_CC_IN_EVI, float *pf_EgoVeloFilt)
{
  float f_Factor;

  *pf_EgoVeloFilt = CML_f_LowPassFilter(pt_CC_IN_EVI->f_LongVeloReal, *pf_EgoVeloFilt, f_cc_cruise_ego_speed_filt_const);

  if (pt_CC_IN_EVI->f_LongVeloDisplay > 10.0f)
  {
    f_Factor = *pf_EgoVeloFilt / pt_CC_IN_EVI->f_LongVeloDisplay;
  }
  else
  {
    f_Factor = (1.0f/CML_f_Kmh2Ms);
  }

  return f_Factor;
}


static float CC_f_CalcControlSetSpeed (setspeed_t u_SetSpeedAct, float f_DispToRealSpdFact)
{
  return ((float)u_SetSpeedAct + 0.5f) * f_DispToRealSpdFact;
}


static void CC_v_SetCtrlLimits(ControlLimitations_t *pt_CtrLim, CC_EngageState_t *pt_EngState)
{
  /* Set Engagement State conditional Limits */
  switch (*pt_EngState)
  {
  case CC_ES_STANDARD:
  default:
    pt_CtrLim->f_LongDecelMax = f_cc_cruise_decel_max;
    break;

  case CC_ES_AFTER_ENGAGEMENT:
    pt_CtrLim->f_LongDecelMax = f_cc_cruise_decel_max_after_engagement;
    break;

  case CC_ES_DURING_OVERRIDE:
    pt_CtrLim->f_LongDecelMax = f_cc_cruise_decel_max_during_override;
    break;

  case CC_ES_AFTER_OVERRIDE:
    pt_CtrLim->f_LongDecelMax = f_cc_cruise_decel_max_after_override;
    break;
  }

  /* Set Unconditional Limits */
  pt_CtrLim->f_LongAccelMax = f_cc_cruise_accel_max;
  pt_CtrLim->f_LongAccGradMax = f_cc_cruise_accel_grad_max;
  pt_CtrLim->f_LongDecGradMax = f_cc_cruise_decel_grad_max;

}


#endif /* FCT_CFG_LOCC_COMPONENT && LOCC_CFG_CC*/
