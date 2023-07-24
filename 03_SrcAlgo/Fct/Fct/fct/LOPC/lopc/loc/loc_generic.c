/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner & Coordinator)

PACKAGENAME:               loc_dummy.c

DESCRIPTION:               Functions for ... purpose

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.04.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---
CHANGES:                    $Log: loc_generic.c  $
CHANGES:                    Revision 1.6 2018/07/12 17:20:48CEST uidj5069 
CHANGES:                    Trajectory Follow Controller implemented
CHANGES:                    Revision 1.5 2018/06/22 13:55:48CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Routing of Standstill Info updated
CHANGES:                    Revision 1.4 2018/06/14 15:04:43CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Standstill Management improved
CHANGES:                    Revision 1.3 2018/06/12 10:52:01CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    New Start Coordination Function added
CHANGES:                    Revision 1.2 2017/10/26 13:49:25CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Output Zero Acceleration while disabled
CHANGES:                    Revision 1.1 2017/10/05 09:05:31CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC_LongitudinalPlannerAndController/04_Engineering/01_Source_Code/LOPC/lopc/loc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "loc.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOC))

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  float32 f_DistErrPosMax;     /* Maximum Positive Distance Control Error */
  float32 f_DistErrNegMax;     /* Maximum Negative Distance Control Error */
  float32 f_VeloErrPosMax;     /* Maximum Positive Velocity Control Error */
  float32 f_VeloErrNegMax;     /* Maximum Negative Velocity Control Error */
}
LOC_ControlErrorLimits_t;

typedef struct
{
  float32 f_KF_Velo;
  float32 f_KP_Velo;
  float32 f_KD_Velo;
  float32 f_TD_Velo;
  float32 f_KF_Accel;
}
LOC_VeloCtrlParam_t;

typedef struct
{
  float32 f_KP_Dist;
  float32 f_KF_Velo;
  float32 f_KP_Velo;
  float32 f_KD_Velo;
  float32 f_TD_Velo;
  float32 f_KF_Accel;
}
LOC_DistCtrlParam_t;

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
#define LOC_LONG_ACCEL_INIT_MAX   (50.0f)

#define LOC_IVEH_LIM_TIM_CONST     (1.0f)   /* Filter time constant for limitation of ideal vehicle distance/velocity */

#define LOC_DIST_ERR_POS_MAX     (100.0f)   /* Maximum Positive Distance Control Error - (Ego Vehicle too far) [m] */
#define LOC_DIST_ERR_NEG_MAX    (-100.0f)   /* Maximum Negative Distance Control Error - (Ego Vehicle too close) [m] */
#define LOC_VELO_ERR_POS_MAX     (100.0f)   /* Maximum Positive Velocity Control Error - (Ego Vehicle too slow) [m/s] */
#define LOC_VELO_ERR_NEG_MAX    (-100.0f)   /* Maximum Negative Velocity Control Error - (Ego Vehicle too fast) [m/s] */

#define LOC_CTRL_PAR_KP_DIST       (0.6f) //(0.1f)   /* Overall weighting factor for proportional Distance error */
#define LOC_CTRL_PAR_KF_VELO       (1.0f)   /* Feedforward weighting factor for Velocity */
#define LOC_CTRL_PAR_KP_VELO       (0.3f)   /* Overall weighting factor for proportional Velocity error */
#define LOC_CTRL_PAR_KD_VELO       (0.1f)   /* Overall weighting factor for derivative Velocity error */
#define LOC_CTRL_PAR_TD_VELO       (1.0f)   /* Filter time constant for derivative Velocity error (0 -> no filtering) */
#define LOC_CTRL_PAR_KF_ACCEL      (1.0f) //(0.9f)   /* Feedforward weighting factor for Acceleration */

#define LOC_TARGET_ACCEL_GRAD_MAX  (2.5f)   /* Maximum Target Control Acceleration Gradient:  2.5 [m/s^3] */
#define LOC_TARGET_DECEL_GRAD_MAX (-2.5f)   /* Maximum Target Control Deceleration Gradient: -2.5 [m/s^3] */



/*****************************************************************************
  VARIABLES 
*****************************************************************************/
SET_MEMSEC_VAR(t_StandstillTime)
times_t t_StandstillTime;

SET_MEMSEC_VAR(t_LOC_IVS)
LOPC_IdealVehicleState_t t_LOC_IVS;

SET_MEMSEC_VAR(t_LOC_EVC)
ACT_EgoVehicleCommand_t t_LOC_EVC;

SET_MEMSEC_VAR(t_LOC_MotState)
LOC_MotionState_t t_LOC_MotState;

SET_MEMSEC_VAR(t_LOC_CEL)
LOC_ControlErrorLimits_t t_LOC_CEL =
{
  LOC_DIST_ERR_POS_MAX,
  LOC_DIST_ERR_NEG_MAX,
  LOC_VELO_ERR_POS_MAX,
  LOC_VELO_ERR_NEG_MAX
};

SET_MEMSEC_VAR(t_LOC_VCP)
LOC_VeloCtrlParam_t t_LOC_VCP =
{
  LOC_CTRL_PAR_KF_VELO,
  LOC_CTRL_PAR_KP_VELO,
  LOC_CTRL_PAR_KD_VELO,
  LOC_CTRL_PAR_TD_VELO,
  LOC_CTRL_PAR_KF_ACCEL
};

SET_MEMSEC_VAR(t_LOC_DCP)
LOC_DistCtrlParam_t t_LOC_DCP =
{
  LOC_CTRL_PAR_KP_DIST,
  LOC_CTRL_PAR_KF_VELO,
  LOC_CTRL_PAR_KP_VELO,
  LOC_CTRL_PAR_KD_VELO,
  LOC_CTRL_PAR_TD_VELO,
  LOC_CTRL_PAR_KF_ACCEL
};

/*****************************************************************************
  FUNCTION PROTOTYPE
*****************************************************************************/
void LOC_v_IdealVehicleStateUpdate (float32 f_CycleTime,
                                    const LOC_ControlErrorLimits_t *pt_LOC_IN_CEL,
                                    const LOPC_IdealVehicleCommand_t *pt_LOC_IN_IVC,
                                    const LOPC_EgoVehicleState_t *pt_LOC_IN_EVS,
                                    LOPC_IdealVehicleState_t *pt_LOC_IVS);

void LOC_v_EgoVehicleStateControl (float32 f_CycleTime,
                                   const LOPC_IdealVehicleState_t *pt_LOC_IVS,
                                   const LOPC_EgoVehicleState_t *pt_LOC_IN_EVS,
                                   ACT_EgoVehicleCommand_t *pt_LOC_EVC);

void LOC_v_EgoMotionStateControl (float32 f_CycleTime, LOC_MotionState_t *pt_LOC_MS,
                                  const LOPC_EgoVehicleState_t *pt_LOC_IN_EVS,
                                  const ACT_LogicVehicleCommand_t *pt_LOC_IN_LVC,
                                  const ACT_EgoVehicleCommand_t *pt_LOC_EVC,
                                  ACT_EgoVehicleCommand_t *pt_LOC_OUT_EVC,
                                  ACT_LogicVehicleState_t *pt_LOC_OUT_LVS);

float32 LOC_f_EgoVeloFollowControl (float32 f_CycleTime, boolean b_Reset,
                                    const LOPC_IdealVehVeloState_t *pt_LOC_IVVS,
                                    const LOPC_EgoVehicleState_t *pt_LOC_EVS,
                                    const LOC_VeloCtrlParam_t *pt_LOC_VCP);

float32 LOC_f_EgoDistFollowControl (float32 f_CycleTime, boolean b_Reset,
                                    const LOPC_IdealVehDistState_t *pt_LOC_IVDS,
                                    const LOPC_EgoVehicleState_t *pt_LOC_EVS,
                                    const LOC_DistCtrlParam_t *pt_LOC_DCP);

/*****************************************************************************
  FUNCTION IMPLEMENTATION
*****************************************************************************/

void LOC_v_IdealVehicleControl_Process (float32 f_CycleTime, LOC_MotionState_t *pt_LOC_MS,
                                        const LOPC_IdealVehicleCommandPort_t *pt_LOC_IN_IVCP,
                                        const LOPC_LogicVehicleCommandPort_t *pt_LOC_IN_LVCP,
                                        const LOPC_EgoVehicleStatePort_t *pt_LOC_IN_EVSP,
                                        LOPC_IdealVehicleStatePort_t *pt_LOC_OUT_IVSP,
                                        LOPC_LogicVehicleStatePort_t *pt_LOC_OUT_LVSP,
                                        LOPC_EgoVehicleCommandPort_t *pt_LOC_OUT_EVCP)
{
  /* Update Ideal Vehicle State */
  LOC_v_IdealVehicleStateUpdate (f_CycleTime, &t_LOC_CEL, pt_LOC_IN_IVCP->pt_IVC, pt_LOC_IN_EVSP->pt_EVS, &t_LOC_IVS);

  /* Output Ideal Vehicle State */
  *(pt_LOC_OUT_IVSP->pt_IVS) = t_LOC_IVS;

  /* Control Ego Vehicle State */
  LOC_v_EgoVehicleStateControl (f_CycleTime, &t_LOC_IVS, pt_LOC_IN_EVSP->pt_EVS, &t_LOC_EVC);

  /* Assign "b_ArbitDriverMin" to local Ego Control Output */
  t_LOC_EVC.b_ArbitDriverMin = pt_LOC_IN_IVCP->pt_IVC->t_IVVC.b_ArbitDriverMin;

  /* Control Ego Vehicle Motion State */
  LOC_v_EgoMotionStateControl (f_CycleTime, pt_LOC_MS, pt_LOC_IN_EVSP->pt_EVS, pt_LOC_IN_LVCP->pt_LVC, &t_LOC_EVC, pt_LOC_OUT_EVCP->pt_EVC, pt_LOC_OUT_LVSP->pt_LVS);
}

void LOC_v_IdealVehicleStateUpdate (float32 f_CycleTime,
                                    const LOC_ControlErrorLimits_t *pt_LOC_IN_CEL,
                                    const LOPC_IdealVehicleCommand_t *pt_LOC_IN_IVC,
                                    const LOPC_EgoVehicleState_t *pt_LOC_IN_EVS,
                                    LOPC_IdealVehicleState_t *pt_LOC_IVS)
{
  float32 f_AccMin, f_AccMax;

  /* Update of ideal vehicle velocity model */
  if (pt_LOC_IN_EVS->b_Valid)
  {
    if (pt_LOC_IVS->t_IVVS.b_Valid)
    {
      /* Update of ideal vehicle velocity model by planner command */
      if (pt_LOC_IN_IVC->t_IVVC.b_Enable)
      {
        /* Integration of accel gradient over cycle time to acceleration */
        pt_LOC_IVS->t_IVVS.f_AbsLongAccel += (pt_LOC_IN_IVC->t_IVVC.f_LongAccelGrad * f_CycleTime);

        /* Evaluate minimum acceleration for ideal vehicle model corresponding to negative velocity control error limit */
        f_AccMin = (pt_LOC_IN_EVS->f_LongVelocity + pt_LOC_IN_CEL->f_VeloErrNegMax - pt_LOC_IVS->t_IVVS.f_AbsLongVelo) / LOC_IVEH_LIM_TIM_CONST
                  + pt_LOC_IN_EVS->f_LongAcceleration;

        /* Evaluate maximum acceleration for ideal vehicle model corresponding to positive velocity control error limit */
        f_AccMax = (pt_LOC_IN_EVS->f_LongVelocity + pt_LOC_IN_CEL->f_VeloErrPosMax - pt_LOC_IVS->t_IVVS.f_AbsLongVelo) / LOC_IVEH_LIM_TIM_CONST
                  + pt_LOC_IN_EVS->f_LongAcceleration;

        /* Limit acceleration for ideal vehicle model by min/max limits */
        pt_LOC_IVS->t_IVVS.f_AbsLongAccel = CML_f_MinMax (f_AccMin, f_AccMax, pt_LOC_IVS->t_IVVS.f_AbsLongAccel);

        /* Integration of acceleration over cycle time to velocity */
        pt_LOC_IVS->t_IVVS.f_AbsLongVelo += (pt_LOC_IVS->t_IVVS.f_AbsLongAccel * f_CycleTime);

        pt_LOC_IVS->t_IVVS.b_Reset = FALSE;
      }
      else
      {
        /* initialize ideal model by ego vehicle state */
        pt_LOC_IVS->t_IVVS.f_AbsLongAccel = pt_LOC_IN_EVS->f_LongAcceleration;
        pt_LOC_IVS->t_IVVS.f_AbsLongVelo = pt_LOC_IN_EVS->f_LongVelocity;
        pt_LOC_IVS->t_IVVS.b_Reset = TRUE;
      }
    }
    else
    {
      /* initialize ideal model by ego vehicle state */
      pt_LOC_IVS->t_IVVS.f_AbsLongAccel = pt_LOC_IN_EVS->f_LongAcceleration;
      pt_LOC_IVS->t_IVVS.f_AbsLongVelo = pt_LOC_IN_EVS->f_LongVelocity;
      pt_LOC_IVS->t_IVVS.b_Valid = TRUE;
      pt_LOC_IVS->t_IVVS.b_Reset = TRUE;
    }
  }
  else
  {
    /* set ideal model to default state */
    pt_LOC_IVS->t_IVVS.f_AbsLongAccel = 0.0f;
    pt_LOC_IVS->t_IVVS.f_AbsLongVelo = 0.0f;
    pt_LOC_IVS->t_IVVS.b_Valid = FALSE;
    pt_LOC_IVS->t_IVVS.b_Reset = FALSE;
  }

  /* Update of ideal vehicle distance model */
  if (pt_LOC_IN_EVS->b_Valid)
  {
    if (pt_LOC_IVS->t_IVDS.t_IVVS.b_Valid)
    {
      /* Update of ideal distance model by planner command */
      if (pt_LOC_IN_IVC->t_IVDC.b_Enable)
      {
        /* Integration of acceleration gradient to acceleration over cycle time */
        pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel += (pt_LOC_IN_IVC->t_IVDC.f_LongAccelGrad * f_CycleTime);

        /* Evaluate minimum acceleration for ideal vehicle model corresponding to negative distance control error limit */
        f_AccMin = (pt_LOC_IN_CEL->f_DistErrNegMax - pt_LOC_IVS->t_IVDS.f_RelLongDist)        / CML_Sqr(LOC_IVEH_LIM_TIM_CONST)
                 + (pt_LOC_IN_EVS->f_LongVelocity  - pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo) * (2.0f / LOC_IVEH_LIM_TIM_CONST)
                 +  pt_LOC_IN_EVS->f_LongAcceleration;

        /* Evaluate maximum acceleration for ideal vehicle model corresponding to positive distance control error limit */
        f_AccMax = (pt_LOC_IN_CEL->f_DistErrPosMax - pt_LOC_IVS->t_IVDS.f_RelLongDist)        / CML_Sqr(LOC_IVEH_LIM_TIM_CONST)
                 + (pt_LOC_IN_EVS->f_LongVelocity  - pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo) * (2.0f / LOC_IVEH_LIM_TIM_CONST)
                 +  pt_LOC_IN_EVS->f_LongAcceleration;

        /* Limit acceleration for ideal vehicle model by min/max limits */
        pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel = CML_f_MinMax (f_AccMin, f_AccMax, pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel);

        /* Integration of acceleration to velocity over cycle time */
        pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo += (pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel * f_CycleTime);

        /* Integration of velocity difference to distance control error */
        pt_LOC_IVS->t_IVDS.f_RelLongDist += ((pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo-pt_LOC_IN_EVS->f_LongVelocity) * f_CycleTime);

        pt_LOC_IVS->t_IVDS.t_IVVS.b_Reset = FALSE;
      }
      else
      {
        /* initialize ideal model with ego vehicle state */
        pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel = pt_LOC_IN_EVS->f_LongAcceleration;
        pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo = pt_LOC_IN_EVS->f_LongVelocity;
        pt_LOC_IVS->t_IVDS.t_IVVS.b_Reset = TRUE;
        pt_LOC_IVS->t_IVDS.f_RelLongDist = 0.0f;
      }
    }
    else
    {
      /* initialize ideal model with ego vehicle state */
      pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel = pt_LOC_IN_EVS->f_LongAcceleration;
      pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo = pt_LOC_IN_EVS->f_LongVelocity;
      pt_LOC_IVS->t_IVDS.t_IVVS.b_Valid = TRUE;
      pt_LOC_IVS->t_IVDS.t_IVVS.b_Reset = TRUE;
      pt_LOC_IVS->t_IVDS.f_RelLongDist = 0.0f;
    }
  }
  else
  {
    /* set ideal model to default state */
    pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongAccel = 0.0f;
    pt_LOC_IVS->t_IVDS.t_IVVS.f_AbsLongVelo = 0.0f;
    pt_LOC_IVS->t_IVDS.t_IVVS.b_Valid = FALSE;
    pt_LOC_IVS->t_IVDS.t_IVVS.b_Reset = FALSE;
    pt_LOC_IVS->t_IVDS.f_RelLongDist = 0.0f;
  }
}

void LOC_v_EgoVehicleStateControl (float32 f_CycleTime,
                                   const LOPC_IdealVehicleState_t *pt_LOC_IVS,
                                   const LOPC_EgoVehicleState_t *pt_LOC_IN_EVS,
                                   ACT_EgoVehicleCommand_t *pt_LOC_EVC)
{
  boolean b_EnableVelo, b_EnableDist, b_Enable = FALSE;
  float32 f_LongAccelVelo, f_LongAccelDist, f_LongAccel = LOC_LONG_ACCEL_INIT_MAX;

  /* Ego Vehicle Velocity Control */
  if (pt_LOC_IVS->t_IVVS.b_Valid && !pt_LOC_IVS->t_IVVS.b_Reset)
  {
    f_LongAccelVelo = LOC_f_EgoVeloFollowControl (f_CycleTime, FALSE, &pt_LOC_IVS->t_IVVS, pt_LOC_IN_EVS, &t_LOC_VCP);
    b_EnableVelo = TRUE;
  }
  else
  {
    f_LongAccelVelo = LOC_f_EgoVeloFollowControl (f_CycleTime, TRUE, &pt_LOC_IVS->t_IVVS, pt_LOC_IN_EVS, &t_LOC_VCP);
    b_EnableVelo = FALSE;
  }

  /* Ego Vehicle Distance Control */
  if (pt_LOC_IVS->t_IVDS.t_IVVS.b_Valid && !pt_LOC_IVS->t_IVDS.t_IVVS.b_Reset)
  {
    f_LongAccelDist = LOC_f_EgoDistFollowControl (f_CycleTime, FALSE, &pt_LOC_IVS->t_IVDS, pt_LOC_IN_EVS, &t_LOC_DCP);
    b_EnableDist = TRUE;
  }
  else
  {
    f_LongAccelDist = LOC_f_EgoDistFollowControl (f_CycleTime, TRUE, &pt_LOC_IVS->t_IVDS, pt_LOC_IN_EVS, &t_LOC_DCP);
    b_EnableDist = FALSE;
  }

  /* Control Output Arbitration */
  if (b_EnableVelo)
  {
    f_LongAccel = f_LongAccelVelo;
    b_Enable = TRUE;
  }

  if (b_EnableDist)
  {
    f_LongAccel = CML_Min(f_LongAccel, f_LongAccelDist);
    b_Enable = TRUE;
  }

  /* Output ego vehicle command */
  pt_LOC_EVC->f_LongAcceleration = f_LongAccel;
  pt_LOC_EVC->b_Enabled = b_Enable;
}

void LOC_v_EgoMotionStateControl (float32 f_CycleTime, LOC_MotionState_t *pt_LOC_MS,
                                  const LOPC_EgoVehicleState_t *pt_LOC_IN_EVS,
                                  const ACT_LogicVehicleCommand_t *pt_LOC_IN_LVC,
                                  const ACT_EgoVehicleCommand_t *pt_LOC_EVC,
                                  ACT_EgoVehicleCommand_t *pt_LOC_OUT_EVC,
                                  ACT_LogicVehicleState_t *pt_LOC_OUT_LVS)
{
  times_t t_CycleTime  = (times_t)(f_CycleTime*Time_s);
  boolean b_Standstill =  pt_LOC_IN_EVS->b_Standstill;
  boolean b_StopReq    = (pt_LOC_IN_EVS->f_LongVelocity < 0.3f) && (pt_LOC_EVC->f_LongAcceleration < -0.01f);
  boolean b_StartReq   = (pt_LOC_EVC->f_LongAcceleration > 0.3f);
  boolean b_StartConf  =  pt_LOC_IN_LVC->b_StartConfirmation;

  /* If Control is enabled */
  if (pt_LOC_EVC->b_Enabled)
  {
    switch (*pt_LOC_MS)
    {
    case LOC_MS_MOVE:
    default:
      if (b_Standstill)
      {
        *pt_LOC_MS = LOC_MS_STAND;
      }
      else if (b_StopReq)
      {
        *pt_LOC_MS = LOC_MS_STOP;
      }

      /* Reset Standstill Time */
      t_StandstillTime = (times_t)0u;
      break;

    case LOC_MS_STOP:
      if (b_Standstill)
      {
        *pt_LOC_MS = LOC_MS_STAND;
      }

      /* Reset Standstill Time */
      t_StandstillTime = (times_t)0u;
      break;

    case LOC_MS_STAND:
      if (!b_Standstill)
      {
        *pt_LOC_MS = LOC_MS_MOVE;
      }
      else if (b_StartReq)
      {
        *pt_LOC_MS = LOC_MS_START;
      }
      else if (t_StandstillTime > LOC_TIME_HOLD_DETECT_MAX)
      {
        *pt_LOC_MS = LOC_MS_HOLD;
      }

      /* Increment Standstill Time */
      if (t_StandstillTime <= CML_u_UNSIGNED_16BIT_QUANT_SIZE - t_CycleTime)
      {
        t_StandstillTime += t_CycleTime;
      }
      else
      {
        t_StandstillTime = CML_u_UNSIGNED_16BIT_QUANT_SIZE;
      }
      break;

    case LOC_MS_HOLD:
      if (!b_Standstill)
      {
        *pt_LOC_MS = LOC_MS_MOVE;
      }
      else if (b_StartReq && b_StartConf)
      {
        *pt_LOC_MS = LOC_MS_START;
      }

      /* Increment Standstill Time */
      if (t_StandstillTime <= CML_u_UNSIGNED_16BIT_QUANT_SIZE - t_CycleTime)
      {
        t_StandstillTime += t_CycleTime;
      }
      else
      {
        t_StandstillTime = CML_u_UNSIGNED_16BIT_QUANT_SIZE;
      }
      break;

    case LOC_MS_START:
      if (!b_Standstill)
      {
        *pt_LOC_MS = LOC_MS_MOVE;
      }

      /* Increment Standstill Time */
      if (t_StandstillTime <= CML_u_UNSIGNED_16BIT_QUANT_SIZE - t_CycleTime)
      {
        t_StandstillTime += t_CycleTime;
      }
      else
      {
        t_StandstillTime = CML_u_UNSIGNED_16BIT_QUANT_SIZE;
      }
      break;
    }

    /* Output ego vehicle standstill request */
    pt_LOC_OUT_EVC->b_Standstill = (*pt_LOC_MS == LOC_MS_STOP)
                                || (*pt_LOC_MS == LOC_MS_STAND)
                                || (*pt_LOC_MS == LOC_MS_HOLD);
  }
  else
  {
    /* Standstill leads to immediate HOLD else MOVE */
    *pt_LOC_MS = b_Standstill ? LOC_MS_HOLD : LOC_MS_MOVE;

    /* Output ego vehicle standstill request */
    pt_LOC_OUT_EVC->b_Standstill = FALSE;
  }

  if (pt_LOC_OUT_EVC->b_Standstill)
  /* Output ramped standstill deceleration */
  {
    /* Define Reference Standstill Deceleration */
    float32 f_LongAccelRef = CML_Min(pt_LOC_EVC->f_LongAcceleration, -0.3f);

    /* Ramp to Reference Acceleration */
    if (pt_LOC_OUT_EVC->f_LongAcceleration < f_LongAccelRef)
    {
      pt_LOC_OUT_EVC->f_LongAcceleration = CML_Min(pt_LOC_OUT_EVC->f_LongAcceleration + (LOC_TARGET_ACCEL_GRAD_MAX*f_CycleTime), f_LongAccelRef);
    }
    else if (pt_LOC_EVC->f_LongAcceleration > f_LongAccelRef)
    {
      pt_LOC_OUT_EVC->f_LongAcceleration = CML_Max(pt_LOC_OUT_EVC->f_LongAcceleration + (LOC_TARGET_DECEL_GRAD_MAX*f_CycleTime), f_LongAccelRef);
    }
  }
  else
  /* Output controller acceleration */
  {
    pt_LOC_OUT_EVC->f_LongAcceleration = pt_LOC_EVC->f_LongAcceleration;
  }

  /* Output Ego Vehicle Command */
  pt_LOC_OUT_EVC->b_Enabled = pt_LOC_EVC->b_Enabled;
  pt_LOC_OUT_EVC->b_ArbitDriverMin = pt_LOC_EVC->b_ArbitDriverMin;

  /* Output Logic Vehicle State */
  pt_LOC_OUT_LVS->b_StartRequest = b_StartReq;
  pt_LOC_OUT_LVS->b_StandStill = (*pt_LOC_MS == LOC_MS_STAND) || (*pt_LOC_MS == LOC_MS_HOLD);
  pt_LOC_OUT_LVS->b_HoldState  = (*pt_LOC_MS == LOC_MS_HOLD);
}

float32 LOC_f_EgoVeloFollowControl (float32 f_CycleTime, boolean b_Reset,
                                    const LOPC_IdealVehVeloState_t *pt_LOC_IVVS,
                                    const LOPC_EgoVehicleState_t *pt_LOC_EVS,
                                    const LOC_VeloCtrlParam_t *pt_LOC_VCP)
{
  static float32 sf_DeltaV_LP;
  float32 f_DeltaV, f_DeltaV_DT, f_AccelCmd;
  
  /* Evaluate Input for Velocity Control */
  f_DeltaV = pt_LOC_IVVS->f_AbsLongVelo * pt_LOC_VCP->f_KF_Velo - pt_LOC_EVS->f_LongVelocity;

  /* LowPass Filter for DeltaV */
  if (b_Reset)
  {
    /* Init LowPass for DeltaV */
    sf_DeltaV_LP = f_DeltaV;
  }
  else
  {
    /* Process LowPass for DeltaV */
    sf_DeltaV_LP = CML_f_LowPassFilter (f_DeltaV, sf_DeltaV_LP, pt_LOC_VCP->f_TD_Velo/f_CycleTime);
  }

  /* Differentiation of DeltaV */
  f_DeltaV_DT = (f_DeltaV - sf_DeltaV_LP) / pt_LOC_VCP->f_TD_Velo;

  /* Velocity PD Control with Feedforward Acceleration */
  f_AccelCmd = pt_LOC_IVVS->f_AbsLongAccel * pt_LOC_VCP->f_KF_Accel
             + f_DeltaV                    * pt_LOC_VCP->f_KP_Velo
             + f_DeltaV_DT                 * pt_LOC_VCP->f_KD_Velo;

  return f_AccelCmd;
}

float32 LOC_f_EgoDistFollowControl (float32 f_CycleTime, boolean b_Reset,
                                    const LOPC_IdealVehDistState_t *pt_LOC_IVDS,
                                    const LOPC_EgoVehicleState_t *pt_LOC_EVS,
                                    const LOC_DistCtrlParam_t *pt_LOC_DCP)
{
  static float32 sf_DeltaV_LP;
  float32 f_DeltaV, f_DeltaV_DT, f_AccelCmd;
  
  /* Distance P Control with Feedforward Velocity */
  f_DeltaV = pt_LOC_IVDS->t_IVVS.f_AbsLongVelo * pt_LOC_DCP->f_KF_Velo
           + pt_LOC_IVDS->f_RelLongDist        * pt_LOC_DCP->f_KP_Dist
           - pt_LOC_EVS->f_LongVelocity;

  /* LowPass Filter for DeltaV */
  if (b_Reset)
  {
    /* Init LowPass for DeltaV */
    sf_DeltaV_LP = f_DeltaV;
  }
  else
  {
    /* Process LowPass for DeltaV */
    sf_DeltaV_LP = CML_f_LowPassFilter (f_DeltaV, sf_DeltaV_LP, pt_LOC_DCP->f_TD_Velo/f_CycleTime);
  }

  /* Differentiation of DeltaV */
  f_DeltaV_DT = (f_DeltaV - sf_DeltaV_LP) / pt_LOC_DCP->f_TD_Velo;

  /* Velocity PD Control with Feedforward Acceleration */
  f_AccelCmd = pt_LOC_IVDS->t_IVVS.f_AbsLongAccel * pt_LOC_DCP->f_KF_Accel
             + f_DeltaV                           * pt_LOC_DCP->f_KP_Velo
             + f_DeltaV_DT                        * pt_LOC_DCP->f_KD_Velo;

  return f_AccelCmd;
}

#endif /* FCT_CFG_LOPC_COMPONENT && LOPC_CFG_LOC */
