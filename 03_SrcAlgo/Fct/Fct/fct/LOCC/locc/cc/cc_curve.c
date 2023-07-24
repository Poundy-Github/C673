/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Cruise Control)

PACKAGENAME:               cc_curve.c

DESCRIPTION:               Functions for curve purpose

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             11.07.2017

VERSION:                   $Revision: 1.2 $

---*/ /*---
CHANGES:                    $Log: cc_curve.c  $
CHANGES:                    Revision 1.2 2017/10/10 17:27:52CEST uidj5069 
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
#define CC_CURVATURE_MIN        0.00002F


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/


void CC_v_CurveProcess(uint8 u_VSC_ID)
{
#if (ACT_CFG_CC_VSC_PORT_CNT)

  float f_CurveRadius;
  float f_LatAccel;
  float f_CurveSpeed;

  switch (t_CC_Active_State)
  {
    case CC_AS_ACTIVE:
      /* Calculate Curve Radius from Driver Intended Curvature */
      f_CurveRadius = 1.0F / CML_Max(CML_f_Abs(t_CC_IN_EVIP.pt_EVI->f_DriverIntendCurve), CC_CURVATURE_MIN);

      /* Calculate Lateral Acceleration by Linear Map Interpolation */
      f_LatAccel = cal_calculate_param_value_1D (af_cc_curve_accel_lat_bkp, af_cc_curve_accel_lat_val, CC_CURVE_ACCEL_LAT_CNT, f_CurveRadius);

      /* Calculate Reference Speed from Curve Radius and Lateral Acceleration */
      f_CurveSpeed = CML_f_Sqrt(f_LatAccel * f_CurveRadius);

      /* Vehicle Speed Command Output */
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_Enable = TRUE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_ArbitDriverMin = FALSE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->f_EgoLongVeloCmd = f_CurveSpeed;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongAccelMax = f_cc_curve_accel_max;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongDecelMax = f_cc_curve_decel_max;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongAccGradMax = f_cc_curve_accel_grad_max;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongDecGradMax = f_cc_curve_decel_grad_max;

      break;

    case CC_AS_PASSIVE:
    default:
      /* Vehicle Speed Command Output */
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_Enable = FALSE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->b_ArbitDriverMin = FALSE;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->f_EgoLongVeloCmd = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongAccelMax = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongDecelMax = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongAccGradMax = 0.0f;
      at_CC_OUT_VSCP[u_VSC_ID].pt_VSC->t_CtrLim.f_LongDecGradMax = 0.0f;

      break;
  }
#endif

}


#endif /* FCT_CFG_LOCC_COMPONENT && LOCC_CFG_CC*/
