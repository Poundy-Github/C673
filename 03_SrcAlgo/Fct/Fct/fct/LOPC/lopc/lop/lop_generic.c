/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACT / LOP (Adaptive Cruise Control - Longitudinal Planner)

PACKAGENAME:               lop_dummy.c

DESCRIPTION:               Functions for ... purpose

AUTHOR:                    Borgs Wolfgang (uidj5069)

CREATION DATE:             12.05.2017

VERSION:                   $Revision: 1.18 $

---*/ /*---
CHANGES:                    $Log: lop_generic.c  $
CHANGES:                    Revision 1.18 2018/11/07 14:50:44CET uidj5069 
CHANGES:                    Functions
CHANGES:                    <LOP_v_GEN_SpeedProfileControl()>
CHANGES:                    <LOP_v_GEN_AccelProfileControl()>
CHANGES:                    <LOP_v_TFC_ControlArbitration()>
CHANGES:                    updated
CHANGES:                    Revision 1.17 2018/07/12 17:38:25CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Minor Changes for Integration of Trajectory Follow Controller
CHANGES:                    Naming of Functions updated
CHANGES:                    Revision 1.16 2018/06/13 15:59:22CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Unused Function Parameter <const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP> removed
CHANGES:                    Revision 1.15 2018/06/11 08:11:23CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Remove old "Start Coordination"
CHANGES:                    Revision 1.14 2018/04/09 15:15:35CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <LOP_v_TFC_ControlArbitration()> corrected to remove side effect from Overtake Support
CHANGES:                    Revision 1.13 2018/04/06 16:31:24CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <LOP_v_TFC_AccelProfileControl()> corrected
CHANGES:                    Revision 1.12 2018/04/05 10:52:27CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Function <LOP_v_TFC_SpeedProfileControl()> improved.
CHANGES:                    Function <LOP_v_TFC_ControlArbitration()> updated for Overtake Support Feature
CHANGES:                    Revision 1.11 2017/12/05 15:25:52CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of Function <LOP_v_TFC_SpeedProfileGeneration()>
CHANGES:                    Revision 1.10 2017/12/01 10:52:32CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of Function <LOP_v_TFC_ControlArbitration()>
CHANGES:                    Revision 1.9 2017/11/30 10:46:17CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Various improvements of <TargetFollowControl> <VehicleSpeedControl>
CHANGES:                    Revision 1.8 2017/11/21 10:51:17CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Update of various control functions
CHANGES:                    Revision 1.7 2017/11/13 15:35:12CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    General Improvement of Target Follow Control (GEN 4)
CHANGES:                    Revision 1.6 2017/11/02 15:25:55CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Integration of Info <b_StartTrial> of Target Follow Controller into Vehicle Speed Control State
CHANGES:                    Revision 1.5 2017/10/26 10:15:47CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Additional Input Port <EgoVehicleStatePort> for LOP Target Follow Control
CHANGES:                    Revision 1.4 2017/10/25 10:28:02CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Bugfix - Speed Controller replaced by Accel Controller
CHANGES:                    Revision 1.3 2017/10/24 14:43:10CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Time Constant for Target Control updated to <1.0s>
CHANGES:                    Revision 1.2 2017/10/10 15:29:29CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Target Follow Controller added

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lop.h"
#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP))


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
#define LOP_LONG_ACCEL_GRAD_MAX         (100.0f)

#define LOP_ACC_CONTROL_TIME_CONST        (0.5f)

#define LOP_SPD_CONTROL_TIME_CONST        (0.5f)


/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

void LOP_v_GEN_SpeedProfileControl (const LOP_MotionProfile_t *pt_MP_IN,
                                    const ControlLimitations_t *pt_CL_IN,
                                    const LOPC_IdealVehVeloState_t *pt_IVS_IN,
                                    LOP_ControlOutput_t *pt_CO_OUT)
{
  boolean b_Lim;
  float32 f_A, f_Ap, f_Apgnd, f_Aplim;

  /* Eval auxiliary variables */
  float32 f_App = pt_CL_IN->f_LongAccGradMax - pt_MP_IN->f_LongAccelGrad;
  float32 f_A0p = -f_App * LOP_SPD_CONTROL_TIME_CONST;
  float32 f_V0p =  f_App * CML_Sqr(LOP_SPD_CONTROL_TIME_CONST);
  float32 f_A1p = pt_CL_IN->f_LongDecelMax - pt_MP_IN->f_LongAccel;
  float32 f_V1p = f_V0p + 0.5f * (CML_Sqr(f_A1p)-CML_Sqr(f_A0p)) / f_App;

  float32 f_Apn = pt_CL_IN->f_LongDecGradMax - pt_MP_IN->f_LongAccelGrad;
  float32 f_A0n = -f_Apn * LOP_SPD_CONTROL_TIME_CONST;
  float32 f_V0n =  f_Apn * CML_Sqr(LOP_SPD_CONTROL_TIME_CONST);
  float32 f_A1n = pt_CL_IN->f_LongAccelMax - pt_MP_IN->f_LongAccel;
  float32 f_V1n = f_V0n + 0.5f * (CML_Sqr(f_A1n)-CML_Sqr(f_A0n)) / f_Apn;

  float32 f_Verr = pt_IVS_IN->f_AbsLongVelo - pt_MP_IN->f_LongVelo;

  /* Velocity control in reference coordinate system */
  if (f_Verr > f_V1p)
  {
    f_A = f_A1p;
    f_Ap = 0.0f;
    b_Lim = TRUE;
  }
  else if (f_Verr < f_V1n)
  {
    f_A = f_A1n;
    f_Ap = 0.0f;
    b_Lim = FALSE;
  }
  else if (f_Verr > f_V0p)
  {
    f_A = -CML_f_Sqrt(2.0f * (f_Verr-f_V0p) * f_App + CML_Sqr(f_A0p));
    f_Ap = f_App;
    b_Lim = FALSE;
  }
  else if (f_Verr < f_V0n)
  {
    f_A = -CML_f_Sqrt(2.0f * (f_Verr-f_V0n) * f_Apn + CML_Sqr(f_A0n));
    f_Ap = f_Apn;
    b_Lim = FALSE;
  }
  else
  {
    f_A = -f_Verr / LOP_SPD_CONTROL_TIME_CONST;
    f_Ap = f_Verr / CML_Sqr(LOP_SPD_CONTROL_TIME_CONST);
    b_Lim = FALSE;
  }

  /* Acceleration control in ground system */
  f_Apgnd = (f_A+pt_MP_IN->f_LongAccel - pt_IVS_IN->f_AbsLongAccel) * (2.0f/LOP_SPD_CONTROL_TIME_CONST) + f_Ap+pt_MP_IN->f_LongAccelGrad;

  /* Limit absolute acceleration gradient */
  f_Aplim = CML_f_MinMax(pt_CL_IN->f_LongDecGradMax, pt_CL_IN->f_LongAccGradMax, f_Apgnd);

  /* Output to Param Struct */
  pt_CO_OUT->f_LongVelo = pt_MP_IN->f_LongVelo;
  pt_CO_OUT->f_AccelGrad = f_Aplim;
  pt_CO_OUT->b_Limited = b_Lim;

}

void LOP_v_GEN_AccelProfileControl (const LOP_MotionProfile_t *pt_MP_IN,
                                    const ControlLimitations_t *pt_CL_IN,
                                    const LOPC_IdealVehVeloState_t *pt_IVS_IN,
                                    LOP_ControlOutput_t *pt_CO_OUT)
{
  /* Input from Param Struct */
  float32 f_AccAct = pt_IVS_IN->f_AbsLongAccel;
  float32 f_AccRef = pt_MP_IN->f_LongAccel;
  float32 f_GradRef = pt_MP_IN->f_LongAccelGrad;
  float32 f_AccMin = pt_CL_IN->f_LongDecelMax;
  float32 f_AccMax = pt_CL_IN->f_LongAccelMax;
  float32 f_GradMin = pt_CL_IN->f_LongDecGradMax;
  float32 f_GradMax = pt_CL_IN->f_LongAccGradMax;
  float32 f_Aref, f_Apref, f_AccGrad, f_Aplim;
  boolean b_Lim;

  /* Command Acceleration Limitation */
  if (f_AccRef > f_AccMax)
  {
    f_Aref = f_AccMax;
    f_Apref = 0.0f;
    b_Lim = FALSE;
  }
  else if (f_AccRef < f_AccMin)
  {
    f_Aref = f_AccMin;
    f_Apref = 0.0f;
    b_Lim = TRUE;
  }
  else
  {
    f_Aref  = f_AccRef;
    f_Apref = f_GradRef;
    b_Lim = FALSE;
  }

  /* Acceleration Control */
  f_AccGrad = (f_Aref - f_AccAct) * (2.0f/LOP_ACC_CONTROL_TIME_CONST) + f_Apref;

  /* Limit Acceleration Gradient by User Limits for Output */
  f_Aplim = CML_f_MinMax(f_GradMin, f_GradMax, f_AccGrad);

  /* Output to Param Struct */
  pt_CO_OUT->f_LongVelo = pt_MP_IN->f_LongVelo;
  pt_CO_OUT->f_AccelGrad = f_Aplim;
  pt_CO_OUT->b_Limited = b_Lim;
}


#if (LOP_CFG_VSC_PORT_CNT)

void LOP_v_VehicleSpeedControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                        const LOPC_VehicleSpeedCommandPort_t at_LOP_IN_VSCP[],
                                        LOP_VehicleSpeedOutputPort_t *pt_LOP_LOC_VSOP,
                                        LOPC_VehicleSpeedStatePort_t at_LOP_OUT_VSSP[])
{
  uint8 i;
  boolean b_Active = FALSE;
  boolean b_ArbitDriverMin = FALSE;
  float32 f_LongAccelGradMin = LOP_LONG_ACCEL_GRAD_MAX;

  for (i=0; i<LOP_CFG_VSC_PORT_CNT; i++)
  {
    LOP_v_VehicleSpeedControl (pt_LOP_IN_IVSP, &(at_LOP_IN_VSCP[i]), &pt_LOP_LOC_VSOP->at_LOP_LOC_VSO[i], &(at_LOP_OUT_VSSP[i]));
    if (pt_LOP_LOC_VSOP->at_LOP_LOC_VSO[i].b_Active)
    {
      if (pt_LOP_LOC_VSOP->at_LOP_LOC_VSO[i].f_LongAccelGrad < f_LongAccelGradMin)
      {
        f_LongAccelGradMin = pt_LOP_LOC_VSOP->at_LOP_LOC_VSO[i].f_LongAccelGrad;
        b_ArbitDriverMin = pt_LOP_LOC_VSOP->at_LOP_LOC_VSO[i].b_ArbitDriverMin;
      }
      b_Active = TRUE;
    }
  }

  pt_LOP_LOC_VSOP->f_LongAccelGrad = f_LongAccelGradMin;
  pt_LOP_LOC_VSOP->b_ArbitDriverMin = b_ArbitDriverMin;
  pt_LOP_LOC_VSOP->b_Active = b_Active;
}

void LOP_v_VehicleSpeedControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                const LOPC_VehicleSpeedCommandPort_t *pt_LOP_IN_VSCP,
                                LOP_VehicleSpeedOutput_t *pt_LOP_LOC_VSO,
                                LOPC_VehicleSpeedStatePort_t *pt_LOP_OUT_VSSP)
{
  LOP_MotionProfile_t t_MP_Spd_Const;
  LOP_ControlOutput_t t_CO_Spd_Const;

  if (pt_LOP_IN_VSCP->pt_VSC->b_Enable)
  {
    /* Assign Command Speed to Motion Profile */
    t_MP_Spd_Const.f_LongVelo = pt_LOP_IN_VSCP->pt_VSC->f_EgoLongVeloCmd;
    t_MP_Spd_Const.f_LongAccel = 0.0f;
    t_MP_Spd_Const.f_LongAccelGrad = 0.0f;

    /* Speed Control for Constant Speed "Profile" */
    LOP_v_GEN_SpeedProfileControl (&t_MP_Spd_Const, &pt_LOP_IN_VSCP->pt_VSC->t_CtrLim, &pt_LOP_IN_IVSP->pt_IVS->t_IVVS, &t_CO_Spd_Const);

    /* Vehicle Speed Status Output */
    pt_LOP_OUT_VSSP->pt_VSS->f_LongDecelMax = pt_LOP_IN_VSCP->pt_VSC->t_CtrLim.f_LongDecelMax;
    pt_LOP_OUT_VSSP->pt_VSS->b_Active = TRUE;
    pt_LOP_OUT_VSSP->pt_VSS->b_Limited = t_CO_Spd_Const.b_Limited;

    /* Vehicle Speed Output */
    pt_LOP_LOC_VSO->b_Active = TRUE;
    pt_LOP_LOC_VSO->b_ArbitDriverMin = pt_LOP_IN_VSCP->pt_VSC->b_ArbitDriverMin;
    pt_LOP_LOC_VSO->f_LongAccelGrad = t_CO_Spd_Const.f_AccelGrad;
  }
  else
  {
    /* Vehicle Speed Status Output */
    pt_LOP_OUT_VSSP->pt_VSS->f_LongDecelMax = 0.0f;
    pt_LOP_OUT_VSSP->pt_VSS->b_Active = FALSE;
    pt_LOP_OUT_VSSP->pt_VSS->b_Limited = FALSE;

    /* Vehicle Speed Control Output */
    pt_LOP_LOC_VSO->b_Active = FALSE;
    pt_LOP_LOC_VSO->b_ArbitDriverMin = FALSE;
    pt_LOP_LOC_VSO->f_LongAccelGrad = 0.0f;
  }

}

#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)

void LOP_v_DistanceSpeedControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                         const LOPC_DistanceSpeedCommandPort_t at_LOP_IN_DSCP[],
                                         LOP_DistanceSpeedOutputPort_t *pt_LOP_LOC_DSOP,
                                         LOPC_DistanceSpeedStatePort_t at_LOP_OUT_DSSP[])
{
  uint8 i;
  boolean b_Active = FALSE;
  float32 f_LongAccelGradMin = LOP_LONG_ACCEL_GRAD_MAX;

  for (i=0; i<LOP_CFG_DSC_PORT_CNT; i++)
  {
    LOP_v_DistanceSpeedControl (pt_LOP_IN_IVSP, &(at_LOP_IN_DSCP[i]), &pt_LOP_LOC_DSOP->at_LOP_LOC_DSO[i], &(at_LOP_OUT_DSSP[i]));
    if (pt_LOP_LOC_DSOP->at_LOP_LOC_DSO[i].b_Active)
    {
      if (pt_LOP_LOC_DSOP->at_LOP_LOC_DSO[i].f_LongAccelGrad < f_LongAccelGradMin)
      {
        f_LongAccelGradMin = pt_LOP_LOC_DSOP->at_LOP_LOC_DSO[i].f_LongAccelGrad;
      }
      b_Active = TRUE;
    }
  }

  pt_LOP_LOC_DSOP->f_LongAccelGrad = f_LongAccelGradMin;
  pt_LOP_LOC_DSOP->b_Active = b_Active;
}

void LOP_v_DistanceSpeedControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                 const LOPC_DistanceSpeedCommandPort_t *pt_LOP_IN_DSCP,
                                 LOP_DistanceSpeedOutput_t *pt_LOP_LOC_DSO,
                                 LOPC_DistanceSpeedStatePort_t *pt_LOP_OUT_DSSP)
{
  pt_LOP_OUT_DSSP->pt_DSS->b_Active = FALSE;
  pt_LOP_OUT_DSSP->pt_DSS->b_Limited = FALSE;

  pt_LOP_LOC_DSO->b_Active = FALSE;
}

#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)

void LOP_v_DistanceCurveControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                         const LOPC_DistanceCurveCommandPort_t at_LOP_IN_DCCP[],
                                         LOP_DistanceCurveOutputPort_t *pt_LOP_LOC_DCOP,
                                         LOPC_DistanceCurveStatePort_t at_LOP_OUT_DCSP[])
{
  uint8 i;
  boolean b_Active = FALSE;
  float32 f_LongAccelGradMin = LOP_LONG_ACCEL_GRAD_MAX;

  for (i=0; i<LOP_CFG_DCC_PORT_CNT; i++)
  {
    LOP_v_DistanceCurveControl (pt_LOP_IN_IVSP, &(at_LOP_IN_DCCP[i]), &pt_LOP_LOC_DCOP->at_LOP_LOC_DCO[i], &(at_LOP_OUT_DCSP[i]));
    if (pt_LOP_LOC_DCOP->at_LOP_LOC_DCO[i].b_Active)
    {
      if (pt_LOP_LOC_DCOP->at_LOP_LOC_DCO[i].f_LongAccelGrad < f_LongAccelGradMin)
      {
        f_LongAccelGradMin = pt_LOP_LOC_DCOP->at_LOP_LOC_DCO[i].f_LongAccelGrad;
      }
      b_Active = TRUE;
    }
  }

  pt_LOP_LOC_DCOP->f_LongAccelGrad = f_LongAccelGradMin;
  pt_LOP_LOC_DCOP->b_Active = b_Active;
}

void LOP_v_DistanceCurveControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                 const LOPC_DistanceCurveCommandPort_t *pt_LOP_IN_DCCP,
                                 LOP_DistanceCurveOutput_t *pt_LOP_LOC_DCO,
                                 LOPC_DistanceCurveStatePort_t *pt_LOP_OUT_DCSP)
{
  pt_LOP_OUT_DCSP->pt_DCS->b_Active = FALSE;
  pt_LOP_OUT_DCSP->pt_DCS->b_Limited = FALSE;

  pt_LOP_LOC_DCO->b_Active = FALSE;
}

#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)

void LOP_v_TargetFollowControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                        const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP,
                                        const LOPC_TargetFollowCommandPort_t at_LOP_IN_TFCP[],
                                        LOP_TargetFollowOutputPort_t *pt_LOP_LOC_TFOP,
                                        LOPC_TargetFollowStatePort_t at_LOP_OUT_TFSP[])
{
  uint8 i;
  boolean b_Active = FALSE;
  float32 f_LongAccelGradMin = LOP_LONG_ACCEL_GRAD_MAX;

  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    LOP_v_TargetFollowControl (pt_LOP_IN_IVSP, pt_LOP_IN_EVSP, &(at_LOP_IN_TFCP[i]), &pt_LOP_LOC_TFOP->at_LOP_LOC_TFO[i], &(at_LOP_OUT_TFSP[i]));
    if (pt_LOP_LOC_TFOP->at_LOP_LOC_TFO[i].b_Active)
    {
      if (pt_LOP_LOC_TFOP->at_LOP_LOC_TFO[i].f_LongAccelGrad < f_LongAccelGradMin)
      {
        f_LongAccelGradMin = pt_LOP_LOC_TFOP->at_LOP_LOC_TFO[i].f_LongAccelGrad;
      }
      b_Active = TRUE;
    }
  }

  pt_LOP_LOC_TFOP->f_LongAccelGrad = f_LongAccelGradMin;
  pt_LOP_LOC_TFOP->b_Active = b_Active;
}

void LOP_v_TargetFollowControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP,
                                const LOPC_TargetFollowCommandPort_t *pt_LOP_IN_TFCP,
                                LOP_TargetFollowOutput_t *pt_LOP_LOC_TFO,
                                LOPC_TargetFollowStatePort_t *pt_LOP_OUT_TFSP)
{
  TargetVehicle_t t_TV_State_Error;
  LOP_MotionProfile_t t_MP_Trg_Spd_Prf_Base;
  LOP_MotionProfile_t t_MP_Trg_Spd_Prf_Intr;
  LOP_MotionProfile_t t_MP_Trg_Spd_Max_Intr;
  LOP_MotionProfile_t t_MP_Trg_Acc_Prf;
  LOP_MotionProfile_t t_MP_Trg_Acc_Max;
  LOP_MotionProfile_t t_MP_Gnd_Spd_Prf_Base;
  LOP_MotionProfile_t t_MP_Gnd_Spd_Prf_Intr;
  LOP_MotionProfile_t t_MP_Gnd_Spd_Max_Intr;
  LOP_MotionProfile_t t_MP_Gnd_Acc_Prf;
  LOP_MotionProfile_t t_MP_Gnd_Acc_Max;
  LOP_ControlOutput_t t_CO_Spd_Prf_Base;
  LOP_ControlOutput_t t_CO_Spd_Prf_Intr;
  LOP_ControlOutput_t t_CO_Spd_Max_Intr;
  LOP_ControlOutput_t t_CO_Acc_Prf;
  LOP_ControlOutput_t t_CO_Acc_Max;
  LOP_ControlOutput_t t_CO_Arbitration;
  float32 af_RelLongDistErr[2];
  float32 af_RelLongMaxDec[2];

  if (pt_LOP_IN_TFCP->pt_TFC->b_Enable)
  {
    /* Generate Maximum Deceleration Profile */
    float32 f_ErrorDist = pt_LOP_IN_TFCP->pt_TFC->t_TarPref.af_RelLongDistErr[pt_LOP_IN_TFCP->pt_TFC->t_TarPref.u_RelLongDistErrZeroIndex-1];
    float32 f_PrefAccel = pt_LOP_IN_TFCP->pt_TFC->t_TarPref.af_RelLongPrefAcc[pt_LOP_IN_TFCP->pt_TFC->t_TarPref.u_RelLongDistErrZeroIndex-1];
    float32 f_MaxDecel = -3.5f - (pt_LOP_IN_EVSP->pt_EVS->f_LongAcceleration + pt_LOP_IN_TFCP->pt_TFC->t_TarVeh.f_RelLongAccel);
    af_RelLongDistErr[0] = f_ErrorDist / f_PrefAccel * f_MaxDecel;
    af_RelLongDistErr[1] = 0.0f;
    af_RelLongMaxDec[0] = f_MaxDecel;
    af_RelLongMaxDec[1] = 0.0f;

    /* Relative to Target Error Transformation of Motion */
    LOP_v_TFC_RelativeToTargetTransformation (&pt_LOP_IN_IVSP->pt_IVS->t_IVDS, pt_LOP_IN_EVSP->pt_EVS, pt_LOP_IN_TFCP->pt_TFC, &t_TV_State_Error);


    /* Generate Preferred Speed Profile without intrusion */
    LOP_v_TFC_SpeedProfileGeneration (&t_TV_State_Error,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.af_RelLongDistErr,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.af_RelLongPrefAcc,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.u_RelLongDistErrorDynSize,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.u_RelLongDistErrZeroIndex,
                                      0.0f,
                                      &t_MP_Trg_Spd_Prf_Base);

    /* Generate Preferred Speed Profile with intrusion */
    LOP_v_TFC_SpeedProfileGeneration (&t_TV_State_Error,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.af_RelLongDistErr,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.af_RelLongPrefAcc,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.u_RelLongDistErrorDynSize,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.u_RelLongDistErrZeroIndex,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.f_RelLongDistIntrusion,
                                      &t_MP_Trg_Spd_Prf_Intr);

    /* Generate Maximum Speed Profile with intrusion */
    LOP_v_TFC_SpeedProfileGeneration (&t_TV_State_Error, af_RelLongDistErr, af_RelLongMaxDec, 2, 1,
                                      pt_LOP_IN_TFCP->pt_TFC->t_TarPref.f_RelLongDistIntrusion,
                                      &t_MP_Trg_Spd_Max_Intr);

    /* Generate Preferred Accel Profile */
    LOP_v_TFC_AccelProfileGeneration (&pt_LOP_IN_TFCP->pt_TFC->t_TarPref, &t_TV_State_Error, &t_MP_Trg_Acc_Prf);

    /* Interpolate Maximum Accel Profile between Preferred and Maximum Speed Profile */
    LOP_v_TFC_AccelProfileInterpolation (&t_TV_State_Error, &t_MP_Trg_Spd_Prf_Intr, &t_MP_Trg_Spd_Max_Intr, &t_MP_Trg_Acc_Max);


    /* Target to Ground Transformation of Preferred Speed Profile without intrusion */
    LOP_v_TFC_TargetToGroundTransformation (&pt_LOP_IN_TFCP->pt_TFC->t_TarVeh, &t_MP_Trg_Spd_Prf_Base, pt_LOP_IN_EVSP->pt_EVS, &t_MP_Gnd_Spd_Prf_Base);

    /* Target to Ground Transformation of Preferred Speed Profile with intrusion */
    LOP_v_TFC_TargetToGroundTransformation (&pt_LOP_IN_TFCP->pt_TFC->t_TarVeh, &t_MP_Trg_Spd_Prf_Intr, pt_LOP_IN_EVSP->pt_EVS, &t_MP_Gnd_Spd_Prf_Intr);

    /* Target to Ground Transformation of Maximum Speed Profile with intrusion */
    LOP_v_TFC_TargetToGroundTransformation (&pt_LOP_IN_TFCP->pt_TFC->t_TarVeh, &t_MP_Trg_Spd_Max_Intr, pt_LOP_IN_EVSP->pt_EVS, &t_MP_Gnd_Spd_Max_Intr);

    /* Target to Ground Transformation of Preferred Accel Profile */
    LOP_v_TFC_TargetToGroundTransformation (&pt_LOP_IN_TFCP->pt_TFC->t_TarVeh, &t_MP_Trg_Acc_Prf, pt_LOP_IN_EVSP->pt_EVS, &t_MP_Gnd_Acc_Prf);

    /* Target to Ground Transformation of Maximum Accel Profile */
    LOP_v_TFC_TargetToGroundTransformation (&pt_LOP_IN_TFCP->pt_TFC->t_TarVeh, &t_MP_Trg_Acc_Max, pt_LOP_IN_EVSP->pt_EVS, &t_MP_Gnd_Acc_Max);


    /* Speed Control for Preferred Speed Profile without intrusion */
    LOP_v_GEN_SpeedProfileControl (&t_MP_Gnd_Spd_Prf_Base, &pt_LOP_IN_TFCP->pt_TFC->t_CtrLimit, &pt_LOP_IN_IVSP->pt_IVS->t_IVDS.t_IVVS, &t_CO_Spd_Prf_Base);

    /* Speed Control for Preferred Speed Profile with intrusion */
    LOP_v_GEN_SpeedProfileControl (&t_MP_Gnd_Spd_Prf_Intr, &pt_LOP_IN_TFCP->pt_TFC->t_CtrLimit, &pt_LOP_IN_IVSP->pt_IVS->t_IVDS.t_IVVS, &t_CO_Spd_Prf_Intr);

    /* Speed Control for Maximum Speed Profile with intrusion */
    LOP_v_GEN_SpeedProfileControl (&t_MP_Gnd_Spd_Max_Intr, &pt_LOP_IN_TFCP->pt_TFC->t_CtrLimit, &pt_LOP_IN_IVSP->pt_IVS->t_IVDS.t_IVVS, &t_CO_Spd_Max_Intr);

    /* Accel Control for Preferred Accel Profile */
    LOP_v_GEN_AccelProfileControl (&t_MP_Gnd_Acc_Prf, &pt_LOP_IN_TFCP->pt_TFC->t_CtrLimit, &pt_LOP_IN_IVSP->pt_IVS->t_IVDS.t_IVVS, &t_CO_Acc_Prf);

    /* Accel Control for Maximum Accel Profile */
    LOP_v_GEN_AccelProfileControl (&t_MP_Gnd_Acc_Max, &pt_LOP_IN_TFCP->pt_TFC->t_CtrLimit, &pt_LOP_IN_IVSP->pt_IVS->t_IVDS.t_IVVS, &t_CO_Acc_Max);


    /* Arbitration of Accel Gradients of all Controllers */
    LOP_v_TFC_ControlArbitration (&t_TV_State_Error,
                                  pt_LOP_IN_TFCP->pt_TFC,
                                  &pt_LOP_IN_IVSP->pt_IVS->t_IVDS,
                                  &t_CO_Spd_Prf_Base,
                                  &t_CO_Spd_Prf_Intr,
                                  &t_CO_Spd_Max_Intr,
                                  &t_CO_Acc_Prf,
                                  &t_CO_Acc_Max,
                                  &t_CO_Arbitration);

    /* Output Control Values */
    pt_LOP_LOC_TFO->b_Active = TRUE;
    pt_LOP_LOC_TFO->f_LongAccelGrad = t_CO_Arbitration.f_AccelGrad;

    /* Output State Values */
    pt_LOP_OUT_TFSP->pt_TFS->f_LongDecelMax = pt_LOP_IN_TFCP->pt_TFC->t_CtrLimit.f_LongDecelMax;
    pt_LOP_OUT_TFSP->pt_TFS->b_Active = TRUE;
    pt_LOP_OUT_TFSP->pt_TFS->b_Limited = t_CO_Arbitration.b_Limited;
    pt_LOP_OUT_TFSP->pt_TFS->b_ControlAlert = FALSE;
  }
  else
  {
    /* Output Control Values */
    pt_LOP_LOC_TFO->b_Active = FALSE;
    pt_LOP_LOC_TFO->f_LongAccelGrad = 0.0f;

    /* Output State Values */
    pt_LOP_OUT_TFSP->pt_TFS->f_LongDecelMax = 0.0f;
    pt_LOP_OUT_TFSP->pt_TFS->b_Active = FALSE;
    pt_LOP_OUT_TFSP->pt_TFS->b_Limited = FALSE;
    pt_LOP_OUT_TFSP->pt_TFS->b_ControlAlert = FALSE;
  }
  
}

void LOP_v_TFC_RelativeToTargetTransformation (const LOPC_IdealVehDistState_t *pt_IVDS_IN,
                                               const LOPC_EgoVehicleState_t *pt_EVS_IN,
                                               const TargetFollowCommand_t *pt_TFC_IN,
                                               TargetVehicle_t *pt_TE_OUT)
{
  pt_TE_OUT->f_RelLongAccel = pt_IVDS_IN->t_IVVS.f_AbsLongAccel - (pt_TFC_IN->t_TarVeh.f_RelLongAccel + pt_EVS_IN->f_LongAcceleration);
  pt_TE_OUT->f_RelLongVelo  = pt_IVDS_IN->t_IVVS.f_AbsLongVelo  - (pt_TFC_IN->t_TarVeh.f_RelLongVelo  + pt_EVS_IN->f_LongVelocity);
  pt_TE_OUT->f_RelLongDist  = pt_IVDS_IN->f_RelLongDist         -  pt_TFC_IN->t_TarVeh.f_RelLongDist;
}

void LOP_v_TFC_SpeedProfileGeneration (const TargetVehicle_t *pt_TE_IN,
                                       const float32 *pf_RelLongDistErr,
                                       const float32 *pf_RelLongRefAcc,
                                       uint8 u_RelLongDynSize,
                                       uint8 u_RelLongZeroIndex,
                                       float32 f_RelLongIntrusion,
                                       LOP_MotionProfile_t *pt_MP_OUT)
{
  float32 S[FCT_CFG_TP_ACC_CRV_SIZE+1];
  float32 A[FCT_CFG_TP_ACC_CRV_SIZE+1];
  float32 Sint = f_RelLongIntrusion;
  float32 s_act = pt_TE_IN->f_RelLongDist;
  float32 v_act = pt_TE_IN->f_RelLongVelo;
  float32 a_act = pt_TE_IN->f_RelLongAccel;
  float32 DS, DA, V2, aps, aps_root;
  float32 a_pro, a_ref, ap_ref;
  float32 v_ref, v_ref_lim, v_act_lim;

  uint8 Size = CML_Min(FCT_CFG_TP_ACC_CRV_SIZE, u_RelLongDynSize);
  uint8 i0 = u_RelLongZeroIndex;
  uint8 i;

  /* Copy distance error and reference acceleration to local arrays S and A */
  for (i=0; i<Size; i++)
  {
    S[i] = pf_RelLongDistErr[i];
    A[i] = pf_RelLongRefAcc[i];
  }

  /* Preprocess S and A array depending on intrusion */
  if (Sint > 0.0f)
  {
    DS = S[i0] - S[i0-1];
    DA = A[i0] - A[i0-1];

    if (Sint < DS/2)
    {
      Size = i0+2;
      for (i=0; i<i0; i++)
      {
        S[i] += 2*Sint;
      }
      A[i0]  -= 2*Sint*DA/DS;
      S[i0+1] = S[i0] + Sint;
      A[i0+1] = A[i0];

      i = i0+1;
    }
    else
    {
      Size = i0+1;
      for (i=0; i<i0; i++)
      {
        S[i] += Sint + DS/2;
      }
      S[i0] += Sint;
      A[i0]  = A[i0-1];

      i = i0;
    }
  }
  else
  {
    i = i0;
  }

  /* Generate speed profile according to S and A array */
  V2 = 0.0f;

  if (s_act > S[i])
  {
    while (i<Size-1 && S[i+1]<s_act)
    {
      V2 -= (A[i+1]+A[i])*(S[i+1]-S[i]);
      i++;
    }

    if (i<Size-1)
    {
      if (S[i+1]>S[i])
      {
        aps = (A[i+1]-A[i]) / (S[i+1]-S[i]);
        a_pro = A[i] + (s_act-S[i])*aps;
      }
      else
      {
        aps = 0.0f;
        a_pro = A[i+1];
      }
    }
    else
    {
      aps = 0.0f;
      a_pro = A[i];
    }

    if (a_pro >= 0.0f)
    {
      V2 -= (a_pro+A[i])*(s_act-S[i]);
    }
  }
  else
  {
    while (i>0 && S[i-1]>s_act)
    {
      V2 -= (A[i]+A[i-1])*(S[i]-S[i-1]);
      i--;
    }
        
    if (i>0)
    {
      if (S[i]>S[i-1])
      {
        aps = (A[i]-A[i-1]) / (S[i]-S[i-1]);
        a_pro = A[i] + (s_act-S[i])*aps;
      }
      else
      {
        aps = 0.0f;
        a_pro = A[i-1];
      }
    }
    else
    {
      aps = 0.0f;
      a_pro = A[i];
    }

    if (a_pro <= 0.0f)
    {
      V2 -= (a_pro+A[i])*(S[i]-s_act);
    }
  }

  /* Eval Reference and Limited Reference Velocity */
  if (V2 < 0.0f)
  {
    v_ref = -CML_f_Sqrt(-V2);
    v_ref_lim = CML_Min(v_ref, -0.1f);
  }
  else
  {
    v_ref = CML_f_Sqrt(V2);
    v_ref_lim = CML_Max(v_ref, 0.1f);
  }

  /* Eval Limited Actual Velocity */
  if (v_act < 0.0f)
  {
    v_act_lim = CML_Min(v_act, -0.1f);
  }
  else
  {
    v_act_lim = CML_Max(v_act, 0.1f);
  }

  if (aps < 0.0f)
  {
    aps_root = -CML_f_Sqrt(-aps);
  }
  else
  {
    aps_root = CML_f_Sqrt(aps);
  }

  /* Eval Accel and Accel Gradient References */
  if ((Sint==0.0f) && (i==i0))
  {
    a_ref  = -aps_root*v_act;
    ap_ref = -aps_root*a_act;
  }
  else
  {
    a_ref  = a_pro*v_act_lim/v_ref_lim;
    ap_ref = ((aps*CML_Sqr(v_act_lim)+a_pro*a_act)*v_ref - a_pro*v_act_lim*a_ref)/CML_Sqr(v_ref_lim);
  }

  /* Copy reference values to output struct */
  pt_MP_OUT->f_LongVelo = v_ref;
  pt_MP_OUT->f_LongAccel = a_ref;
  pt_MP_OUT->f_LongAccelGrad = ap_ref;
}

void LOP_v_TFC_AccelProfileGeneration (const TargetPreferences_t *pt_TP_IN,
                                       const TargetVehicle_t *pt_TE_IN,
                                       LOP_MotionProfile_t *pt_MP_OUT)
{
  float32 S[FCT_CFG_TP_ACC_CRV_SIZE];
  float32 A[FCT_CFG_TP_ACC_CRV_SIZE];
  float32 v = pt_TE_IN->f_RelLongVelo;
  float32 s = pt_TE_IN->f_RelLongDist;
  float32 a1, v1, s1, ds, v2, dv2, aps, Apref, Aref;

  uint8 Size = CML_Min(FCT_CFG_TP_ACC_CRV_SIZE, pt_TP_IN->u_RelLongDistErrorDynSize);
  uint8 i0 = pt_TP_IN->u_RelLongDistErrZeroIndex;
  uint8 i;

  /* Copy distance error and preferred acceleration to local arrays S and A */
  for (i=0; i<Size; i++)
  {
    S[i] = pt_TP_IN->af_RelLongDistErr[i];
    A[i] = pt_TP_IN->af_RelLongPrefAcc[i];
  }

  i = i0;
  v2 = CML_f_Abs(v)*v;

  if (v2 >= 0.0f)
  {
    a1 =  A[i0-1];
    v1 = (A[i0]+A[i0-1])*(S[i0-1]-S[i0]);
    s1 = -S[i0-1]/2;
        
    if (s>0.0f && v<v1)
    {            
      if (s >= s1 + v2/(2*a1))
      {
        aps = 0;
        Aref = a1;
        ds = -v2/(2*a1);
      }
      else
      {
        aps = 0;
        Aref = a1 * (s + CML_f_Sqrt(CML_Max((CML_Sqr(s)-2*v2*s1/a1), 0.0f))) / (2*s1);
        ds = -v2/(2*Aref);
      }
    }
    else
    {
      while (i>0 && v2>=0)
      {
        dv2 = (A[i]+A[i-1])*(S[i]-S[i-1]);
        v2 += dv2;
        i--;
      }

      if (i>0)
      {
        i++;
        if (S[i]>S[i-1])
        {
          aps = (A[i]-A[i-1]) / (S[i]-S[i-1]);
          if (aps==0)
          {
            ds = v2 / (A[i-1]+A[i]);
          }
          else
          {
            ds = (-2*A[i-1] - CML_f_Sqrt(CML_Max((4*CML_Sqr(A[i-1])+4*aps*v2), 0.0f))) / (2*aps);
          }
          Aref = A[i-1] + ds*aps;
          ds += S[i-1];
        }
        else
        {
          aps = 0;
          Aref = A[i-1];
          ds = S[i-1];
        }
      }
      else
      {
        aps = 0;
        Aref = A[i];
        ds = S[i];
      }
    }

  }
  else
  {
    while (i<Size-1 && v2<0.0f)
    {
      dv2 = (A[i+1]+A[i])*(S[i+1]-S[i]);
      v2 = v2 + dv2;
      i++;
    }

    if (i<Size-1)
    {
      i--;
      if (S[i+1]>S[i])
      {
        aps = (A[i+1]-A[i]) / (S[i+1]-S[i]);
        if (aps==0)
        {
          ds = v2 / (A[i]+A[i+1]);
        }
        else
        {
          ds = (-2*A[i] - CML_f_Sqrt(CML_Max((4*CML_Sqr(A[i])+4*aps*v2), 0.0f))) / (2*aps);
        }
        Aref = A[i] + ds*aps;
        ds += S[i];
      }
      else
      {
        aps = 0;
        Aref = A[i+1];
        ds = S[i+1];
      }
    }
    else
    {
      aps = 0;
      Aref = A[i];
      ds = S[i];
    }
  }

  /* Eval Accel Gradient Reference */
  Apref = aps*v;

  /* Copy reference values to output struct */
  pt_MP_OUT->f_LongVelo = v;
  pt_MP_OUT->f_LongAccel = Aref;
  pt_MP_OUT->f_LongAccelGrad = Apref;
}

void LOP_v_TFC_AccelProfileInterpolation (const TargetVehicle_t *pt_TE_IN,
                                          const LOP_MotionProfile_t *pt_MP_SPD_MIN_IN,
                                          const LOP_MotionProfile_t *pt_MP_SPD_MAX_IN,
                                          LOP_MotionProfile_t *pt_MP_ACC_OUT)
{
  float32 f_V_ACT = pt_TE_IN->f_RelLongVelo;
  float32 f_V_MIN = pt_MP_SPD_MIN_IN->f_LongVelo;
  float32 f_V_MAX = pt_MP_SPD_MAX_IN->f_LongVelo;
  float32 f_A_MIN = pt_MP_SPD_MIN_IN->f_LongAccel;
  float32 f_A_MAX = pt_MP_SPD_MAX_IN->f_LongAccel;
  float32 f_Ap_MIN = pt_MP_SPD_MIN_IN->f_LongAccelGrad;
  float32 f_Ap_MAX = pt_MP_SPD_MAX_IN->f_LongAccelGrad;

  pt_MP_ACC_OUT->f_LongVelo = f_V_ACT;

  if (f_V_MAX > f_V_MIN)
  {
    if (f_V_ACT <= f_V_MIN)
    {
      pt_MP_ACC_OUT->f_LongAccel = f_A_MIN;
      pt_MP_ACC_OUT->f_LongAccelGrad = f_Ap_MIN;
    }
    else if(f_V_ACT >= f_V_MAX)
    {
      pt_MP_ACC_OUT->f_LongAccel = f_A_MAX;
      pt_MP_ACC_OUT->f_LongAccelGrad = f_Ap_MAX;
    }
    else
    {
      pt_MP_ACC_OUT->f_LongAccel     = f_A_MIN  + (f_V_ACT - f_V_MIN) / (f_V_MAX - f_V_MIN) * (f_A_MAX  - f_A_MIN);
      pt_MP_ACC_OUT->f_LongAccelGrad = f_Ap_MIN + (f_V_ACT - f_V_MIN) / (f_V_MAX - f_V_MIN) * (f_Ap_MAX - f_Ap_MIN);
    }
  }
  else
  {
    pt_MP_ACC_OUT->f_LongAccel = f_A_MAX;
    pt_MP_ACC_OUT->f_LongAccelGrad = f_Ap_MAX;
  }

  pt_MP_ACC_OUT->f_LongVelo = f_V_ACT;
}

void LOP_v_TFC_TargetToGroundTransformation (const TargetVehicle_t *pt_TV_IN,
                                             const LOP_MotionProfile_t *pt_MP_IN,
                                             const LOPC_EgoVehicleState_t *pt_EVS_IN,
                                             LOP_MotionProfile_t *pt_MP_OUT)
{
  pt_MP_OUT->f_LongVelo      = pt_MP_IN->f_LongVelo  + (pt_EVS_IN->f_LongVelocity     + pt_TV_IN->f_RelLongVelo);
  pt_MP_OUT->f_LongAccel     = pt_MP_IN->f_LongAccel + (pt_EVS_IN->f_LongAcceleration + pt_TV_IN->f_RelLongAccel);
  pt_MP_OUT->f_LongAccelGrad = pt_MP_IN->f_LongAccelGrad;

  if (pt_MP_OUT->f_LongVelo <= 0.0f)
  {
    pt_MP_OUT->f_LongVelo = 0.0f;
    pt_MP_OUT->f_LongAccel = 0.0f;
    pt_MP_OUT->f_LongAccelGrad = 0.0f;
  }
}

void LOP_v_TFC_ControlArbitration (const TargetVehicle_t *pt_TE_IN,
                                   const TargetFollowCommand_t *pt_TFC_IN,
                                   const LOPC_IdealVehDistState_t *pt_IVDS_IN,
                                   const LOP_ControlOutput_t *pt_CO_SPC_Prf_Base,
                                   const LOP_ControlOutput_t *pt_CO_SPC_Prf_Intr,
                                   const LOP_ControlOutput_t *pt_CO_SPC_Max_Intr,
                                   const LOP_ControlOutput_t *pt_CO_APC_Prf,
                                   const LOP_ControlOutput_t *pt_CO_APC_Max,
                                   LOP_ControlOutput_t *pt_CO_OUT)
{
  LOP_ControlOutput_t t_CO_TMP;
  float32 SpdError = pt_TE_IN->f_RelLongVelo;
  float32 DistError = pt_TE_IN->f_RelLongDist;
  float32 DistIntrMax = pt_TFC_IN->t_TarPref.f_RelLongDistIntrusion;
  float32 DistIntrMin = CML_Min(1.0f, DistIntrMax);
  boolean ActiveIntrusionCtrl = pt_TFC_IN->t_TarPref.b_ActiveIntrusionCtrl;

  /* if intrusion distance shall be utilized for active acceleration */
  if (ActiveIntrusionCtrl)
  {
    /* if distance error is below max intrusion distance and speed error above zero or distance error is below min intrusion distance */
    if ((DistError < DistIntrMax) && (SpdError > 0.0f) || (DistError < DistIntrMin))
    {
      /* use maximum intrusion speed control profile */
      t_CO_TMP.f_AccelGrad = pt_CO_SPC_Max_Intr->f_AccelGrad;
      t_CO_TMP.f_LongVelo = pt_CO_SPC_Max_Intr->f_LongVelo;
      t_CO_TMP.b_Limited = pt_CO_SPC_Max_Intr->b_Limited;
    }
    else
    {
      /* use preferred base speed control profile */
      t_CO_TMP.f_AccelGrad = pt_CO_SPC_Prf_Base->f_AccelGrad;
      t_CO_TMP.f_LongVelo = pt_CO_SPC_Prf_Base->f_LongVelo;
      t_CO_TMP.b_Limited = pt_CO_SPC_Prf_Base->b_Limited;
    }
  }
  /* no active intrusion control - normal mode */
  else
  {
    /* if distance error is below intrusion distance and speed error above zero */
    if ((DistError < DistIntrMax) && (SpdError > 0.0f))
    {
      /* if velocity of ideal vehicle is below preferred base speed control profile */
      if (pt_IVDS_IN->t_IVVS.f_AbsLongVelo < pt_CO_SPC_Prf_Base->f_LongVelo)
      {
        /* use preferred base speed control profile */
        t_CO_TMP.f_AccelGrad = pt_CO_SPC_Prf_Base->f_AccelGrad;
        t_CO_TMP.f_LongVelo = pt_CO_SPC_Prf_Base->f_LongVelo;
        t_CO_TMP.b_Limited = pt_CO_SPC_Prf_Base->b_Limited;
      }
      /* else if velocity of ideal vehicle is below preferred intrusion speed control profile */
      else if (pt_IVDS_IN->t_IVVS.f_AbsLongVelo < pt_CO_SPC_Prf_Intr->f_LongVelo)
      {
        /* use preferred acceleration profile */
        t_CO_TMP.f_AccelGrad = pt_CO_APC_Prf->f_AccelGrad;
        t_CO_TMP.f_LongVelo = pt_CO_APC_Prf->f_LongVelo;
        t_CO_TMP.b_Limited = pt_CO_APC_Prf->b_Limited;
      }
      /* else if velocity of ideal vehicle is below maximum intrusion speed control profile */
      else if (pt_IVDS_IN->t_IVVS.f_AbsLongVelo < pt_CO_SPC_Max_Intr->f_LongVelo)
      {
        /* use maximum deceleration profile */
        t_CO_TMP.f_AccelGrad = pt_CO_APC_Max->f_AccelGrad;
        t_CO_TMP.f_LongVelo = pt_CO_APC_Max->f_LongVelo;
        t_CO_TMP.b_Limited = pt_CO_APC_Max->b_Limited;
      }
      /* else */
      else
      {
        /* use maximum intrusion speed control profile */
        t_CO_TMP.f_AccelGrad = pt_CO_SPC_Max_Intr->f_AccelGrad;
        t_CO_TMP.f_LongVelo = pt_CO_SPC_Max_Intr->f_LongVelo;
        t_CO_TMP.b_Limited = pt_CO_SPC_Max_Intr->b_Limited;
      }
    }
    else
    {
      /* use preferred base speed control profile */
      t_CO_TMP.f_AccelGrad = pt_CO_SPC_Prf_Base->f_AccelGrad;
      t_CO_TMP.f_LongVelo = pt_CO_SPC_Prf_Base->f_LongVelo;
      t_CO_TMP.b_Limited = pt_CO_SPC_Prf_Base->b_Limited;
    }
  }

  /* Output */
  pt_CO_OUT->f_AccelGrad = t_CO_TMP.f_AccelGrad;
  pt_CO_OUT->f_LongVelo = t_CO_TMP.f_LongVelo;
  pt_CO_OUT->b_Limited = t_CO_TMP.b_Limited;
}

#endif

void LOP_v_ControlArbitration_Process (
#if (LOP_CFG_VSC_PORT_CNT)
                                       const LOP_VehicleSpeedOutputPort_t *pt_LOP_LOC_VSOP,
#endif
#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
                                       const LOP_DistanceSpeedOutputPort_t *pt_LOP_LOC_DSOP,
#endif
#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
                                       const LOP_DistanceCurveOutputPort_t *pt_LOP_LOC_DCOP,
#endif
#if (FCT_CFG_HP_TFC_PORT_CNT)
                                       const LOP_TargetFollowOutputPort_t *pt_LOP_LOC_TFOP,
#endif
                                       LOPC_IdealVehicleCommandPort_t *pt_LOP_OUT_IVCP)
{
  boolean b_VeloActive = FALSE;
  boolean b_DistActive = FALSE;
  boolean b_ArbitDriverMin = FALSE;
  float32 f_LongAccelGradVelo = LOP_LONG_ACCEL_GRAD_MAX;
  float32 f_LongAccelGradDist = LOP_LONG_ACCEL_GRAD_MAX;

  /* Arbitration for vehicle speed controller */
#if (LOP_CFG_VSC_PORT_CNT)
  if (pt_LOP_LOC_VSOP->b_Active)
  {
    if (pt_LOP_LOC_VSOP->f_LongAccelGrad < f_LongAccelGradVelo)
    {
      f_LongAccelGradVelo = pt_LOP_LOC_VSOP->f_LongAccelGrad;
      b_ArbitDriverMin = pt_LOP_LOC_VSOP->b_ArbitDriverMin;
    }
    b_VeloActive = TRUE;
  }
#endif

  /* Arbitration for distance speed controller */
#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  if (pt_LOP_LOC_DSOP->b_Active)
  {
    if (pt_LOP_LOC_DSOP->f_LongAccelGrad < f_LongAccelGradDist)
    {
      f_LongAccelGradDist = pt_LOP_LOC_DSOP->f_LongAccelGrad;
    }
    b_DistActive = TRUE;
  }
#endif

  /* Arbitration for distance curve controller */
#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  if (pt_LOP_LOC_DCOP->b_Active)
  {
    if (pt_LOP_LOC_DCOP->f_LongAccelGrad < f_LongAccelGradDist)
    {
      f_LongAccelGradDist = pt_LOP_LOC_DCOP->f_LongAccelGrad;
    }
    b_DistActive = TRUE;
  }
#endif

  /* Arbitration for target follow controller */
#if (FCT_CFG_HP_TFC_PORT_CNT)
  if (pt_LOP_LOC_TFOP->b_Active)
  {
    if (pt_LOP_LOC_TFOP->f_LongAccelGrad < f_LongAccelGradDist)
    {
      f_LongAccelGradDist = pt_LOP_LOC_TFOP->f_LongAccelGrad;
    }
    b_DistActive = TRUE;
  }
#endif

  /* Output to ideal vehicle velocity model */
  pt_LOP_OUT_IVCP->pt_IVC->t_IVVC.f_LongAccelGrad = f_LongAccelGradVelo;
  pt_LOP_OUT_IVCP->pt_IVC->t_IVVC.b_ArbitDriverMin = b_ArbitDriverMin;
  pt_LOP_OUT_IVCP->pt_IVC->t_IVVC.b_Enable = b_VeloActive;

  /* Output to ideal vehicle distance model */
  pt_LOP_OUT_IVCP->pt_IVC->t_IVDC.f_LongAccelGrad = f_LongAccelGradDist;
  pt_LOP_OUT_IVCP->pt_IVC->t_IVDC.b_Enable = b_DistActive;
}

#endif /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP) */
