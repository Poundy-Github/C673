/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_ye.c
   Real-Time Workshop code generated for Simulink model vdy_ye.
   Model version                        : 1.2834
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:05:40 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:05:41 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy yaw rate estimation
   for the vehicle, merges the
   four yaw rates to the vehicle
   yaw rate and merge this yaw
   rate with the driver intended
   curvature to a vehicle curve
   VERSION:                             : $Revision: 1.5 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_ye.h"
#include "vdy_ye_private.h"

/* <file MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 10.1: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 10.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 10.3: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 10.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 10.5: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 12.1: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 12.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 12.5: reviewer name: Jochen Spruck date: 23-11-2010 reason: autocode module */
/* <file MISRA Rule 12.6: reviewer name: Jochen Spruck date: 23-11-2010 reason: autocode module */
/* <file MISRA Rule 12.7: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 12.13: reviewer name: Jochen Spruck date: 23-11-2010 reason: autocode module */
/* <file MISRA Rule 13.3: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 13.7: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 14.1: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 16.7: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 16.10: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 17.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 17.3: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file MISRA Rule 17.4: reviewer name: Jochen Spruck date: 23-11-2010 reason: autocode module */
/* <file PCLINT Error 662: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 731: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 766: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 774: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 835: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 843: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 845: reviewer name: Jochen Spruck date: 11-11-2010 reason: autocode module */
/* <file PCLINT Error 912: reviewer name: Jochen Spruck date: 23-11-2010 reason: autocode module */
/* <file PCLINT Error 971: reviewer name: Jochen Spruck date: 23-11-2010 reason: autocode module */
/* QAC Fixes */
/* <file MISRA Rule 1.1: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 614 EOF */
/* <file MISRA Rule 8.1: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 3335 EOF */
/* <file MISRA Rule 8.8: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Parameters are stored in a separate file for readability and clarity" */
/* PRQA S 3408 EOF */
/* <file MISRA Rule 10.1: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Both unsigned long and unsigned int are of same size i.e. 4 bytes, so no loss of information is possible" */
/* PRQA S 3794 EOF */
/* <file MISRA Rule 11.5: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 311 EOF */
/* <file MISRA Rule 12.4: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 3415 EOF */
/* <file MISRA Rule 12.5: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 3398 EOF */
/* <file MISRA Rule 12.7: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 502,4131 EOF */
/* <file MISRA Rule 13.3: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 3341 EOF */
/* <file MISRA Rule 13.7: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 3355,3356,3358,3359 EOF */
/* <file MISRA Rule 14.1: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Statement is dependent on value of Configuration switch" */
/* PRQA S 3201,3325 EOF */
/* <file MISRA Rule 14.2: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 3112 EOF */
/* <file MISRA Rule 16.10: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Memset and memcpy are being used to create a null matrix." */
/* PRQA S 3200 EOF */
/* <file MISRA Rule 17.4: reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, alreay reviewed and working fine without any critical issue" */
/* PRQA S 488,489,491 EOF */
/* <file MISRA Rule 'HIS metrics check: cyclomatic complexity': reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, reducing complexity adds risk and effort." */
/* PRQA S 7004 EOF */
/* <file MISRA Rule 'metrics check: executable lines of code per file': reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, reducing lines of code changes component structure." */
/* PRQA S 7013 EOF */
/* <file MISRA Rule 'metrics check: executable lines of code per function': reviewer name: Anuj Berwal date: 10-03-2017 reason: "Legacy code of ARS301, reducing lines of code changes component structure." */
/* PRQA S 7012 EOF */

/*
 * Output and update for atomic system:
 *    '<Root>/Get_IO_State1'
 *    '<S16>/Get_IO_State1'
 */
void vdy_ye_Get_IO_State1(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State1_vdy_ye *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S1>/Index Vector' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/*
 * Output and update for atomic system:
 *    '<S3>/diag_variance'
 *    '<S16>/diag_R'
 */
void vdy_ye_diag_variance(const real32_T rtu_u[16], rtB_diag_variance_vdy_ye
  *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<S3>/diag_variance' */
  /* Embedded MATLAB Function 'R/diag_variance': '<S23>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S23>:1:5' */
  for (i = 0; i < 4; i++) {
    localB->y[(i)] = rtu_u[(5 * i)];
  }
}

/*
 * Output and update for atomic system:
 *    '<S7>/At'
 *    '<S7>/Ht'
 *    '<S15>/At'
 */
void vdy_ye_At(const real32_T rtu_u[4], rtB_At_vdy_ye *localB)
{
  int32_T i;
  int32_T i_0;

  /* Embedded MATLAB: '<S7>/At' */
  /* Embedded MATLAB Function 'curve_KF/At': '<S26>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S26>:1:5' */
  for (i_0 = 0; i_0 < 2; i_0++) {
    for (i = 0; i < 2; i++) {
      localB->y[i + (i_0 << 1)] = rtu_u[(i << 1) + i_0];
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<Root>/diag_curve_variance'
 *    '<Root>/diag_yaw_variance'
 */
void vdy_ye_diag_curve_variance(const real32_T rtu_u[4],
  rtB_diag_curve_variance_vdy_ye *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<Root>/diag_curve_variance' */
  /* Embedded MATLAB Function 'diag_curve_variance': '<S8>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S8>:1:5' */
  for (i = 0; i < 2; i++) {
    localB->y[(i)] = rtu_u[(3 * i)];
  }
}

/*
 * Output and update for atomic system:
 *    '<S38>/make_A_matrix'
 *    '<S53>/make_A_matrix'
 */
void vdy_ye_make_A_matrix(real32_T rtu_CycleTime, rtB_make_A_matrix_vdy_ye
  *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<S38>/make_A_matrix' */
  /* Embedded MATLAB Function 'make_A_Q_curve/A/make_A_matrix': '<S41>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S41>:1:5' */
  localB->A[0] = 1.0F;
  localB->A[2] = rtu_CycleTime;
  for (i = 0; i < 2; i++) {
    localB->A[1 + (i << 1)] = (real32_T)i;
  }
}

/* Model step function */
void vdy_ye_step(BlockIO_vdy_ye *vdy_ye_B, D_Work_vdy_ye *vdy_ye_DWork,
                 VDYInputData_t *vdy_ye_U_VDYInputData, VDYInternalData_t
                 *vdy_ye_U_VDYInternalData_in, VDYInternalData_t
                 *vdy_ye_Y_VDYInternalData_out, real32_T vdy_ye_Y_K_yaw[8],
                 uint8_T *vdy_ye_Y_K_yaw_fault, real32_T vdy_ye_Y_K_curve[4],
                 uint8_T *vdy_ye_Y_K_curve_fault)
{
  /* local block i/o variables */
  real32_T rtb_xpost[2];
  real32_T rtb_x_pred[2];
  real32_T rtb_Divide_f;
  real32_T rtb_P_pred[4];
  real32_T rtb_vdy_sfunc_HP_Ht_o2[16];
  real32_T rtb_HPHt_R[16];
  real32_T rtb_Reshape4[16];
  real32_T rtb_P_predHt[8];
  real32_T rtb_K[8];
  real32_T rtb_P_post[4];
  real32_T rtb_veh_velo_e;
  real32_T rtb_xpost_e[2];
  real32_T rtb_x_pred_k[2];
  real32_T rtb_Add1;
  real32_T rtb_add_abs;
  real32_T rtb_P_pred_d[4];
  real32_T rtb_HPHt_R_n[4];
  real32_T rtb_P_predHt_n[4];
  real32_T rtb_K_m[4];
  real32_T rtb_KH[4];
  real32_T rtb_P_post_h[4];
  real32_T rtb_Add_d;
  real32_T rtb_H[8];
  real32_T rtb_P_pred_out[4];
  real32_T rtb_y[8];
  real32_T rtb_diff_m;
  real32_T rtb_y_l;
  real32_T rtb_H_g[4];
  real32_T rtb_P_pred_out_p[4];
  real32_T rtb_Time2Sec;
  real32_T rtb_R_out_k[16];
  real32_T rtb_nu[4];
  real32_T rtb_vdy_sfunc_HP_o2[8];
  real32_T rtb_vdy_sfunc_K_nu_o2[2];
  real32_T rtb_nu_p[2];
  real32_T rtb_Product1_j;
  real32_T rtb_vdy_sfunc_HP_Ht_o2_b[4];
  real32_T rtb_KH_b[4];
  uint8_T rtb_State[32];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_vdy_sfunc_K_gain_o1_f;
  uint8_T rtb_Knu;
  real32_T R_out[16];
  real32_T ramp_fact_out;
  real32_T rtb_Yk1;
  real32_T rtb_Product[4];
  real32_T rtb_UnitDelay;
  real32_T rtb_T2;
  real32_T rtb_T1;
  real32_T rtb_T0;
  real32_T rtb_diff;
  real32_T rtb_gain;
  real32_T rtb_bias;
  real32_T rtb_gier_yaw_rate_var;
  real32_T rtb_x_pred_out[2];
  real32_T rtb_make_z_vector[2];
  real32_T rtb_Divide_m;
  real32_T rtb_z_yaw_rate_curve;
  uint8_T rtb_Reset;
  uint8_T rtb_Value_in_uint;
  real32_T rtb_hx_g[2];
  VDYInternalData_t rtb_BusAssignment;
  real32_T rtb_wye_usage;
  real32_T rtb_aye_usage;
  real32_T rtb_sye_usage;
  real32_T rtb_yaw_rate_out;
  uint8_T rtb_K_yaw_fault;
  uint8_T rtb_K_curve_fault;
  real32_T rtb_TmpSignalConversionAtSFun_l[2];
  real32_T rtb_Sum_l;
  real32_T rtb_Sum_lq;
  real32_T rtb_Sum_n;
  real32_T rtb_Sum_d;
  real32_T rtb_Sum_di;
  real32_T rtb_TmpSignalConversionAtSFun_f[2];
  uint8_T rtb_hold_counter_out;
  uint8_T rtb_ramp_counter_out;
  real32_T rtb_Q[4];
  real32_T rtb_R_out_j[16];
  int32_T i;
  real32_T tmp[4];
  real32_T tmp_0[4];
  real32_T rtb_TmpSignalConversionAtSFun_0[2];
  real32_T rtb_TmpSignalConversionAtSFun_1[2];
  int32_T i_0;
  static int8_T tmp_1[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };

  static int8_T tmp_2[4] = { 1, 1, 0, 0 };

  static int8_T tmp_3[4] = { 1, 0, 0, 1 };

  /* UnitDelay: '<S17>/UD' */
  rtb_Yk1 = vdy_ye_DWork->UD_DSTATE;

  /* BusSelector: '<Root>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 32; i++) {
    rtb_State[i] = (*vdy_ye_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<Root>/Time2Sec' */

  /* Product: '<S4>/Time2Sec' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_Time2Sec = ((real32_T)(*vdy_ye_U_VDYInputData).Frame.CycleTime) / 1000.0F;

  /* end of Outputs for SubSystem: '<Root>/Time2Sec' */

  /* Embedded MATLAB: '<S53>/make_A_matrix' */
  vdy_ye_make_A_matrix(rtb_Time2Sec, &vdy_ye_B->sf_make_A_matrix);

  /* UnitDelay: '<S15>/x_delay' */
  for (i = 0; i < 2; i++) {
    rtb_xpost[i] = vdy_ye_DWork->x_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S15>/vdy_s-func_x_pred' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)vdy_ye_B->sf_make_A_matrix.A,
                                      (real32_T*)rtb_xpost, rtb_x_pred, (uint8_T)
    2, (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S15>/hx' */
  /* Embedded MATLAB Function 'yaw_KF/hx': '<S74>:1' */
  /*  transformation from state space to measurement space  */
  /* '<S74>:1:3' */
  for (i = 0; i < 8; i++) {
    rtb_H[i] = (real32_T)tmp_1[i];
  }

  /* '<S74>:1:8' */

  /* Embedded MATLAB: '<S13>/build_z_vector' */
  /* Embedded MATLAB Function 'make_z_vektor/build_z_vector': '<S68>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S68>:1:5' */

  /* Sum: '<S15>/z_Hx' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  tmp[0] = (*vdy_ye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate;
  tmp[1] = (*vdy_ye_U_VDYInternalData_in).vdy_wye_out.whl_yaw_rate;
  tmp[2] = (*vdy_ye_U_VDYInternalData_in).vdy_aye_out.ay_yaw_rate;
  tmp[3] = (*vdy_ye_U_VDYInternalData_in).vdy_sye_out.stw_yaw_rate;
  for (i = 0; i < 4; i++) {
    tmp_0[i] = 0.0F;
    for (i_0 = 0; i_0 < 2; i_0++) {
      tmp_0[i] = (((real32_T)tmp_1[(i_0 << 2) + i]) * rtb_x_pred[i_0]) + tmp_0[i];
    }

    rtb_nu[i] = tmp[i] - tmp_0[i];

    /* Product: '<S3>/Product' */
    rtb_Product[i] = rtb_nu[i] * rtb_nu[i];
  }

  /* SignalConversion: '<S58>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S54>/Constant'
   *  Product: '<S54>/Divide'
   *  Product: '<S54>/Product1'
   */
  rtb_TmpSignalConversionAtSFun_l[0] = (rtb_Time2Sec * rtb_Time2Sec) * 0.5F;
  rtb_TmpSignalConversionAtSFun_l[1] = rtb_Time2Sec;

  /* Embedded MATLAB: '<S54>/makeQ' incorporates:
   *  Constant: '<S54>/sigma_model'
   */
  /* Embedded MATLAB Function 'make_A_Q_yaw/Q/makeQ': '<S58>:1' */
  /*  calculate the model covariance matrix Q */
  /* '<S58>:1:3' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFun_l[i] *
      vdy_ye_Q_sigmas_p[(i)];
    rtb_make_z_vector[i] = vdy_ye_Q_sigmas_p[(i)] *
      rtb_TmpSignalConversionAtSFun_l[i];
  }

  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_Q[i_0 + (i << 1)] = rtb_TmpSignalConversionAtSFun_0[i_0] *
        rtb_make_z_vector[i];
    }
  }

  /* UnitDelay: '<S56>/Unit Delay' */
  rtb_UnitDelay = vdy_ye_DWork->UnitDelay_DSTATE;

  /* Embedded MATLAB: '<S11>/mean' incorporates:
   *  BusSelector: '<S11>/Bus Selector'
   *  Inport: '<Root>/VDYInternalData_in'
   *  SignalConversion: '<S55>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* Embedded MATLAB Function 'make_A_Q_yaw/mean': '<S55>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  Validate the individual yaw rate using the r_On_Off flags and decide the */
  /*  counter for calculating the mean. */
  /* '<S55>:1:8' */
  i = 0;
  if ((*vdy_ye_U_VDYInternalData_in).vdy_aye_out.r_On_Off_control != 0) {
    /* '<S55>:1:10' */
    /* '<S55>:1:11' */
    i = 1;
  }

  if ((*vdy_ye_U_VDYInternalData_in).vdy_gye_out.r_On_Off_control) {
    /* '<S55>:1:13' */
    /* '<S55>:1:14' */
    i++;
  }

  if ((*vdy_ye_U_VDYInternalData_in).vdy_wye_out.r_On_Off_control != 1) {
    /* '<S55>:1:16' */
    /* '<S55>:1:17' */
    i++;
  }

  if ((*vdy_ye_U_VDYInternalData_in).vdy_sye_out.r_On_Off_control != 0) {
    /* '<S55>:1:19' */
    /* '<S55>:1:20' */
    i++;
  }

  if (i == 0) {
    /* '<S55>:1:23' */
    /* '<S55>:1:24' */
    i = 1;
  }

  /* '<S55>:1:27' */
  rtb_y_l = ((((*vdy_ye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate +
               (*vdy_ye_U_VDYInternalData_in).vdy_wye_out.whl_yaw_rate) +
              (*vdy_ye_U_VDYInternalData_in).vdy_aye_out.ay_yaw_rate) +
             (*vdy_ye_U_VDYInternalData_in).vdy_sye_out.stw_yaw_rate) /
    ((real32_T)i);

  /* UnitDelay: '<S60>/T2' */
  rtb_T2 = vdy_ye_DWork->T2_DSTATE;

  /* UnitDelay: '<S60>/T1' */
  rtb_T1 = vdy_ye_DWork->T1_DSTATE;

  /* UnitDelay: '<S60>/T0' */
  rtb_T0 = vdy_ye_DWork->T0_DSTATE;

  /* Product: '<S60>/Divide' incorporates:
   *  Constant: '<S60>/filter_length'
   *  Sum: '<S60>/Add'
   *  UnitDelay: '<S60>/T3'
   */
  rtb_Divide_f = (((vdy_ye_DWork->T3_DSTATE + vdy_ye_DWork->T2_DSTATE) +
                   vdy_ye_DWork->T1_DSTATE) + vdy_ye_DWork->T0_DSTATE) * 0.25F;

  /* Embedded MATLAB: '<S56>/get_gain_bias' incorporates:
   *  Constant: '<S11>/vdy_ye_Q_gain'
   */
  /* Embedded MATLAB Function 'make_A_Q_yaw/q_gain/get_gain_bias': '<S59>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S59>:1:5' */
  rtb_gain = vdy_ye_Q_gain_p[0];

  /* '<S59>:1:6' */
  rtb_bias = vdy_ye_Q_gain_p[1];

  /* '<S59>:1:7' */

  /* Embedded MATLAB: '<S56>/q_gain_delta' incorporates:
   *  S-Function (ex_sfun_abs): '<S56>/mean_filter_yaw_rate_abs'
   *  S-Function (ex_sfun_abs): '<S56>/yaw_rate_abs'
   */
  /* Embedded MATLAB Function 'make_A_Q_yaw/q_gain/q_gain_delta': '<S61>:1' */
  /*  Note: In order to eliminate QAC Level-4 warnings, the if-condition below is rewritten with multiple if-elseif expressions. */
  /*  calculate the difference between the mean filtered last yaw rate and  */
  /*  the actual yaw rate */
  if (CML_f_Abs( (real32_T)rtb_y_l) >= 1.0E-7F) {
    /* '<S61>:1:6' */
    if (CML_f_Abs( (real32_T)rtb_Divide_f) >= 1.0E-7F) {
      /* '<S61>:1:7' */
      /* '<S61>:1:8' */
      rtb_diff_m = rtb_y_l - rtb_Divide_f;
    } else {
      /* '<S61>:1:10' */
      rtb_diff_m = vdy_ye_Q_gain_p[2];
    }
  } else {
    /* '<S61>:1:13' */
    rtb_diff_m = vdy_ye_Q_gain_p[2];
  }

  /* Embedded MATLAB: '<S56>/threshold_diff' incorporates:
   *  S-Function (ex_sfun_abs): '<S56>/diff_abs'
   */
  /* Embedded MATLAB Function 'make_A_Q_yaw/q_gain/threshold_diff': '<S62>:1' */
  /*  check if abs diff is above threshold and limit it to last valid value */
  /* '<S62>:1:3' */
  rtb_diff = CML_f_Abs( (real32_T)rtb_diff_m);
  if (CML_f_Abs( (real32_T)rtb_diff_m) > vdy_ye_Q_gain_p[3]) {
    /* '<S62>:1:4' */
    /* '<S62>:1:5' */
    rtb_diff = rtb_UnitDelay;
  }

  /* Sum: '<S56>/Sum2' incorporates:
   *  Product: '<S56>/Product'
   */
  rtb_UnitDelay = (rtb_diff * rtb_gain) + rtb_bias;
  for (i = 0; i < 4; i++) {
    /* UnitDelay: '<S15>/P_delay' */
    rtb_vdy_sfunc_HP_Ht_o2_b[i] = vdy_ye_DWork->P_delay_DSTATE[(i)];
    rtb_Q[i] = (rtb_Q[i] * rtb_UnitDelay) + vdy_ye_Q_add_p[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S75>/vdy_s-func_AP' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)vdy_ye_B->sf_make_A_matrix.A,
                                      (real32_T*)rtb_vdy_sfunc_HP_Ht_o2_b,
    rtb_KH_b, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S15>/At' */
  vdy_ye_At(vdy_ye_B->sf_make_A_matrix.A, &vdy_ye_B->sf_At);

  /* S-Function (MatrixMultiplication): '<S75>/vdy_s-func_AP_At' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_KH_b, (real32_T*)
    vdy_ye_B->sf_At.y, rtb_vdy_sfunc_HP_Ht_o2_b, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Sum: '<S15>/APA_Q' */
  for (i = 0; i < 4; i++) {
    rtb_P_pred[i] = rtb_Q[i] + rtb_vdy_sfunc_HP_Ht_o2_b[i];
  }

  /* S-Function (MatrixMultiplication): '<S76>/vdy_s-func_HP' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_H, (real32_T*)rtb_P_pred,
    rtb_vdy_sfunc_HP_o2, (uint8_T)2, (uint8_T)4, (uint8_T)2);

  /* Embedded MATLAB: '<S15>/Ht' */
  /* Embedded MATLAB Function 'yaw_KF/Ht': '<S71>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S71>:1:5' */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_y[i_0 + (i << 1)] = rtb_H[(i_0 << 2) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S76>/vdy_s-func_HP_Ht' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_vdy_sfunc_HP_o2, (real32_T*)
    rtb_y, rtb_vdy_sfunc_HP_Ht_o2, (uint8_T)2, (uint8_T)4, (uint8_T)4);

  /* BusSelector: '<S3>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_gier_yaw_rate_var = (*vdy_ye_U_VDYInternalData_in).
    vdy_gye_out.gier_yaw_rate_var;
  rtb_UnitDelay = (*vdy_ye_U_VDYInternalData_in).vdy_wye_out.whl_yaw_rate_var;
  rtb_gain = (*vdy_ye_U_VDYInternalData_in).vdy_aye_out.ay_yaw_rate_var;
  rtb_bias = (*vdy_ye_U_VDYInternalData_in).vdy_sye_out.stw_yaw_rate_var;

  /* SignalConversion: '<S22>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_Q[0] = (*vdy_ye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate_var;
  rtb_Q[1] = (*vdy_ye_U_VDYInternalData_in).vdy_wye_out.whl_yaw_rate_var;
  rtb_Q[2] = (*vdy_ye_U_VDYInternalData_in).vdy_aye_out.ay_yaw_rate_var;
  rtb_Q[3] = (*vdy_ye_U_VDYInternalData_in).vdy_sye_out.stw_yaw_rate_var;

  /* Embedded MATLAB: '<S3>/diag_R' */
  /* Embedded MATLAB Function 'R/diag_R': '<S22>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S22>:1:5' */
  vdy_memset_s((void *)(&rtb_R_out_j[0]), (int32_T)0.0F, sizeof(real32_T) << 4U);
  for (i = 0; i < 4; i++) {
    rtb_R_out_j[i + (i << 2)] = rtb_Q[i];
  }

  /* Sum: '<S3>/HPHt_R' */
  for (i = 0; i < 16; i++) {
    rtb_HPHt_R[i] = rtb_vdy_sfunc_HP_Ht_o2[i] + rtb_R_out_j[i];
  }

  /* Embedded MATLAB: '<S3>/diag_variance' */
  vdy_ye_diag_variance(rtb_HPHt_R, &vdy_ye_B->sf_diag_variance);

  /* Product: '<S3>/PHt_(HPHt_R)1' */
  for (i = 0; i < 4; i++) {
    rtb_Product[i] = rtb_Product[i] / vdy_ye_B->sf_diag_variance.y[(i)];
  }

  /* Embedded MATLAB: '<S3>/meas_matrix_adj1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'R/meas_matrix_adj1': '<S24>:1' */
  /*  check the four mahalanobis distances for threshold */
  /*  and raise then linear with this distance the measument covariance matrix */
  /* '<S24>:1:4' */
  vdy_memcpy_s((void *)(&R_out[0]), (void *)(&rtb_R_out_j[0]), sizeof(real32_T) <<
               4U);

  /*  only if the velocity is above a threshold  */
  if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo >=
      vdy_ye_mahala_para_p[0]) {
    /* '<S24>:1:6' */
    /*  adjustment of the gier yaw rate */
    if (rtb_Product[0] > vdy_ye_mahala_para_p[1]) {
      /* '<S24>:1:8' */
      /* '<S24>:1:9' */
      R_out[0] = (rtb_Product[0] * vdy_ye_mahala_para_p[5]) + rtb_R_out_j[0];

      /* (nu_2(1)/dist_threshold)-HPHt_in(1,1); */
    }

    /*  adjustment of the wheel speed sensors yaw rate */
    if (rtb_Product[1] > vdy_ye_mahala_para_p[2]) {
      /* '<S24>:1:12' */
      /* '<S24>:1:13' */
      R_out[5] = (rtb_Product[1] * vdy_ye_mahala_para_p[6]) + R_out[5];

      /* (nu_2(2)/dist_threshold)-HPHt_in(2,2); */
    }

    /*  adjustment of the lateral acceleration sensor yaw rate */
    if (rtb_Product[2] > vdy_ye_mahala_para_p[3]) {
      /* '<S24>:1:16' */
      /* '<S24>:1:17' */
      R_out[10] = (rtb_Product[2] * vdy_ye_mahala_para_p[7]) + R_out[10];

      /* (nu_2(3)/dist_threshold)-HPHt_in(3,3); */
    }

    /*  adjustment of the steering wheel angle yaw rate */
    if (rtb_Product[3] > vdy_ye_mahala_para_p[4]) {
      /* '<S24>:1:20' */
      /* '<S24>:1:21' */
      R_out[15] = (rtb_Product[3] * vdy_ye_mahala_para_p[8]) + R_out[15];

      /* (nu_2(4)/dist_threshold)-HPHt_in(4,4); */
    }
  }

  /* '<S24>:1:24' */
  /* '<S24>:1:25' */
  /* '<S24>:1:26' */
  /* '<S24>:1:27' */

  /* Sum: '<S17>/Sum' incorporates:
   *  Gain: '<S17>/Gain'
   *  Sum: '<S17>/Diff'
   */
  rtb_Sum_l = ((rtb_Yk1 - R_out[0]) * 0.96F) + R_out[0];

  /* Sum: '<S18>/Sum' incorporates:
   *  Gain: '<S18>/Gain'
   *  Sum: '<S18>/Diff'
   *  UnitDelay: '<S18>/UD'
   */
  rtb_Sum_lq = ((vdy_ye_DWork->UD_DSTATE_m - R_out[5]) * 0.96F) + R_out[5];

  /* Sum: '<S20>/Sum' incorporates:
   *  Gain: '<S20>/Gain'
   *  Sum: '<S20>/Diff'
   *  UnitDelay: '<S20>/UD'
   */
  rtb_Sum_n = ((vdy_ye_DWork->UD_DSTATE_h - R_out[10]) * 0.96F) + R_out[10];

  /* Sum: '<S19>/Sum' incorporates:
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Diff'
   *  UnitDelay: '<S19>/UD'
   */
  rtb_Sum_d = ((vdy_ye_DWork->UD_DSTATE_j - R_out[15]) * 0.96F) + R_out[15];

  /* SignalConversion: '<S21>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_Q[0] = rtb_Sum_l;
  rtb_Q[1] = rtb_Sum_lq;
  rtb_Q[2] = rtb_Sum_n;
  rtb_Q[3] = rtb_Sum_d;

  /* Embedded MATLAB: '<S3>/change_new_R_values' */
  /* Embedded MATLAB Function 'R/change_new_R_values': '<S21>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S21>:1:5' */
  vdy_memcpy_s((void *)(&rtb_R_out_k[0]), (void *)(&rtb_R_out_j[0]), sizeof
               (real32_T) << 4U);

  /* '<S21>:1:6' */
  rtb_R_out_k[0] = rtb_Q[0];

  /* '<S21>:1:7' */
  rtb_R_out_k[5] = rtb_Q[1];

  /* '<S21>:1:8' */
  rtb_R_out_k[10] = rtb_Q[2];

  /* '<S21>:1:9' */
  rtb_R_out_k[15] = rtb_Q[3];

  /* Embedded MATLAB: '<S16>/diag_R' */
  vdy_ye_diag_variance(rtb_R_out_k, &vdy_ye_B->sf_diag_R_i);

  /* SignalConversion: '<S82>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_Q[0] = rtb_gier_yaw_rate_var;
  rtb_Q[1] = rtb_UnitDelay;
  rtb_Q[2] = rtb_gain;
  rtb_Q[3] = rtb_bias;

  /* Embedded MATLAB: '<S16>/mean_var' */
  /* Embedded MATLAB Function 'yaw_rate_usage/mean_var': '<S82>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S82>:1:5' */
  rtb_UnitDelay = (((rtb_Q[0] + rtb_Q[1]) + rtb_Q[2]) + rtb_Q[3]) * 0.25F;

  /* Outputs for atomic SubSystem: '<S16>/Get_IO_State1' */
  vdy_ye_Get_IO_State1(rtb_State, &vdy_ye_B->Get_IO_State1, ((uint32_T)
    VDY_SIN_POS_YWR));

  /* end of Outputs for SubSystem: '<S16>/Get_IO_State1' */

  /* Embedded MATLAB: '<S16>/norm_usage' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  SignalConversion: '<S83>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* Embedded MATLAB Function 'yaw_rate_usage/norm_usage': '<S83>:1' */
  /*  norm the new by the mahalanobis distance controlled measurement variances  */
  /*  to the mean input variance */
  /*  If vehicle velocity is less then 5m/s then use fused Yaw  */
  if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo < 5.0F) {
    /* '<S83>:1:6' */
    /* sum = single(R_new(1)+R_new(2)+R_new(3)+R_new(4)); */
    /* '<S83>:1:9' */
    rtb_gier_yaw_rate_var = vdy_ye_B->sf_diag_R_i.y[0] / rtb_UnitDelay;

    /* '<S83>:1:10' */
    rtb_wye_usage = vdy_ye_B->sf_diag_R_i.y[1] / rtb_UnitDelay;

    /* '<S83>:1:11' */
    rtb_aye_usage = vdy_ye_B->sf_diag_R_i.y[2] / rtb_UnitDelay;

    /* '<S83>:1:12' */
    rtb_sye_usage = vdy_ye_B->sf_diag_R_i.y[3] / rtb_UnitDelay;
  } else {
    /*  if gye is valid ,make it as VDY yaw rate. */
    if ((((uint32_T)vdy_ye_B->Get_IO_State1.IndexVector) == ((uint32_T)
          VDY_IO_STATE_VALID)) || (((uint32_T)
          vdy_ye_B->Get_IO_State1.IndexVector) == ((uint32_T)
          VDY_IO_STATE_DECREASED))) {
      /* '<S83>:1:16' */
      /* '<S83>:1:17' */
      /* '<S83>:1:18' */
      rtb_wye_usage = 10000.0F;

      /* '<S83>:1:19' */
      rtb_aye_usage = 10000.0F;

      /* '<S83>:1:20' */
      rtb_sye_usage = 10000.0F;
    } else {
      /* sum = single(R_new(1)+R_new(2)+R_new(3)+R_new(4)); */
      /* '<S83>:1:23' */
      rtb_gier_yaw_rate_var = vdy_ye_B->sf_diag_R_i.y[0] / rtb_UnitDelay;

      /* '<S83>:1:24' */
      rtb_wye_usage = vdy_ye_B->sf_diag_R_i.y[1] / rtb_UnitDelay;

      /* '<S83>:1:25' */
      rtb_aye_usage = vdy_ye_B->sf_diag_R_i.y[2] / rtb_UnitDelay;

      /* '<S83>:1:26' */
      rtb_sye_usage = vdy_ye_B->sf_diag_R_i.y[3] / rtb_UnitDelay;
    }
  }

  /* Reshape: '<S15>/Reshape4' */
  vdy_memcpy_s((void *)(&rtb_Reshape4[0]), (void *)(&rtb_R_out_k[0]), sizeof
               (real32_T) << 4U);

  /* Embedded MATLAB: '<S70>/Matrix_Inversion_4x4' */
  vdy_matrix_inversion_4x4(rtb_vdy_sfunc_HP_Ht_o2, rtb_Reshape4,
    &vdy_ye_B->sf_Matrix_Inversion_4x4);

  /* S-Function (MatrixMultiplication): '<S15>/S-Function4' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_P_pred, (real32_T*)rtb_y,
    rtb_P_predHt, (uint8_T)2, (uint8_T)2, (uint8_T)4);

  /* If: '<S70>/If' incorporates:
   *  ActionPort: '<S78>/Action Port'
   *  ActionPort: '<S79>/Action Port'
   *  SubSystem: '<S70>/calculate the gain'
   *  SubSystem: '<S70>/set gain to default value'
   */
  if (!vdy_ye_B->sf_Matrix_Inversion_4x4.det_flag) {
    /* S-Function (MatrixMultiplication): '<S78>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_predHt,
      (real32_T*)vdy_ye_B->sf_Matrix_Inversion_4x4.HPHt_R_inv, rtb_K, (uint8_T)4,
      (uint8_T)2, (uint8_T)4);

    /* Constant: '<S78>/K_normal' */
    rtb_K_yaw_fault = 0U;
  } else {
    /* Constant: '<S79>/Constant' */
    for (i = 0; i < 8; i++) {
      rtb_K[i] = vdy_ye_K_yaw_default_p[(i)];
    }

    /* Constant: '<S79>/K_disturbed' */
    rtb_K_yaw_fault = 1U;
  }

  /* S-Function (MatrixMultiplication): '<S15>/vdy_s-func_KH' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)rtb_H,
    rtb_KH_b, (uint8_T)4, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S15>/1_KH' incorporates:
   *  Constant: '<S15>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH_b[i] = vdy_ye_I_matrix_yaw_p[(i)] - rtb_KH_b[i];
  }

  /* Embedded MATLAB: '<S15>/Reset_P_pred' */
  /* Embedded MATLAB Function 'yaw_KF/Reset_P_pred': '<S72>:1' */
  if (vdy_ye_B->sf_Matrix_Inversion_4x4.det_flag) {
    /* '<S72>:1:4' */
    /* '<S72>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = vdy_ye_P_init_p[(i)];
    }
  } else {
    /* '<S72>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S15>/vdy_s-func_P_post' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_KH_b, (real32_T*)
    rtb_P_pred_out, rtb_P_post, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<Root>/diag_yaw_variance' */
  vdy_ye_diag_curve_variance(rtb_P_post, &vdy_ye_B->sf_diag_yaw_variance);

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State1' */
  vdy_ye_Get_IO_State1(rtb_State, &vdy_ye_B->Get_IO_State1_o, ((uint32_T)
    VDY_SIN_POS_YWR));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State1' */

  /* BusSelector: '<Root>/Bus Selector3' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo_e = (*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /* Embedded MATLAB: '<S15>/Reset_x_pred' */
  /* Embedded MATLAB Function 'yaw_KF/Reset_x_pred': '<S73>:1' */
  if (vdy_ye_B->sf_Matrix_Inversion_4x4.det_flag) {
    /* '<S73>:1:4' */
    /* '<S73>:1:6' */
    rtb_x_pred_out[0] = 0.0F;
    rtb_x_pred_out[1] = rtb_xpost[1];
  } else {
    /* '<S73>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_x_pred_out[i] = rtb_x_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S15>/vdy_s-func_K_nu' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)rtb_nu,
    rtb_nu_p, (uint8_T)4, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S15>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_x_pred_out[i] = rtb_x_pred_out[i] + rtb_nu_p[i];
  }

  /* Embedded MATLAB: '<Root>/vdy_yaw_select' incorporates:
   *  BusSelector: '<Root>/Bus Selector3'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<Root>/abs_velocity'
   */
  /* Embedded MATLAB Function 'vdy_yaw_select': '<S14>:1' */
  /*  If vehicle velocity is less then 5m/s then use fused Yaw  */
  if (CML_f_Abs( (real32_T)rtb_veh_velo_e) < 5.0F) {
    /* '<S14>:1:3' */
    /* '<S14>:1:4' */
    rtb_yaw_rate_out = rtb_x_pred_out[1];
  } else {
    /*  if gye is valid ,make it as VDY yaw rate. */
    if ((((uint32_T)vdy_ye_B->Get_IO_State1_o.IndexVector) == ((uint32_T)
          VDY_IO_STATE_VALID)) || (((uint32_T)
          vdy_ye_B->Get_IO_State1_o.IndexVector) == ((uint32_T)
          VDY_IO_STATE_DECREASED))) {
      /* '<S14>:1:7' */
      /* '<S14>:1:8' */
      rtb_yaw_rate_out = (*vdy_ye_U_VDYInternalData_in).
        vdy_gye_out.gier_yaw_rate;
    } else {
      /* '<S14>:1:10' */
      rtb_yaw_rate_out = rtb_x_pred_out[1];
    }
  }

  /* BusSelector: '<S12>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_make_z_vector[1] = (*vdy_ye_U_VDYInternalData_in).vdy_sye_out.stw_curve;

  /* Embedded MATLAB: '<S63>/Divide' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S12>/veh_yaw_rate_var_abs'
   *  S-Function (ex_sfun_sqrt): '<S12>/sqrt_s_function'
   */
  /* Embedded MATLAB Function 'make_crv_z_vektor_R/Divide/Divide': '<S67>:1' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo <= 1.0F) {
    /* '<S67>:1:5' */
    /* '<S67>:1:6' */
    rtb_UnitDelay = GDBsqrt_75( (real32_T)CML_f_Abs( (real32_T)
      vdy_ye_B->sf_diag_yaw_variance.y[1]));
  } else {
    /* '<S67>:1:8' */
    rtb_UnitDelay = GDBsqrt_75( (real32_T)CML_f_Abs( (real32_T)
      vdy_ye_B->sf_diag_yaw_variance.y[1])) / (*vdy_ye_U_VDYInternalData_in).
      vdy_ve_out.veh_velo;
  }

  /* Product: '<S12>/sqr' */
  rtb_UnitDelay *= rtb_UnitDelay;

  /* Sum: '<S66>/Sum' incorporates:
   *  Gain: '<S66>/Gain'
   *  Sum: '<S66>/Diff'
   *  UnitDelay: '<S66>/UD'
   */
  rtb_Sum_di = ((vdy_ye_DWork->UD_DSTATE_hz - rtb_UnitDelay) * 0.96F) +
    rtb_UnitDelay;

  /* Embedded MATLAB: '<S12>/make_R' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_crv_z_vektor_R/make_R': '<S65>:1' */
  /*  calculate the measurement covariance matrix out of the input variances if the velocity is above a threshold */
  /*  or raise up the yaw rate curve and drop down the driver intended curvatures variances */
  /*  z = [yaw_rate_curve, di_curve] */
  /* '<S65>:1:5' */
  for (i = 0; i < 4; i++) {
    rtb_Q[i] = 0.0F;
  }

  /* '<S65>:1:8' */
  rtb_gain = vdy_ye_R_curve_p[0] - vdy_ye_R_curve_p[2];

  /* '<S65>:1:9' */
  rtb_bias = ((vdy_ye_R_curve_p[1] - 1.0F) * rtb_Sum_di) / (rtb_gain * rtb_gain);

  /*  merge yaw rate if steering input is available or the vehicle speed is small */
  if (((*vdy_ye_U_VDYInternalData_in).vdy_sye_out.stw_curve_var < 99.0F) ||
      ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo < 0.5F)) {
    /* '<S65>:1:12' */
    /*  steering input available, merge curvature */
    if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo < vdy_ye_R_curve_p[2])
    {
      /* '<S65>:1:14' */
      /*  below a specifed velocity only the Driver intended curve should be used (ackerman curvature) */
      /* '<S65>:1:16' */
      rtb_Q[0] = ((rtb_bias * rtb_gain) * rtb_gain) + rtb_Sum_di;

      /* '<S65>:1:17' */
      rtb_Q[3] = rtb_Sum_di;
    } else if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo <
               vdy_ye_R_curve_p[0]) {
      /* '<S65>:1:18' */
      /*  below a specifed velocity overload the variance by an parabolic function from the yaw rate curve  */
      /*  to the driver indended curvature, so at standstill the ackerman curvature is available   */
      /* '<S65>:1:21' */
      rtb_UnitDelay = ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
                       vdy_ye_R_curve_p[2]) - rtb_gain;

      /* '<S65>:1:22' */
      rtb_Q[0] = ((rtb_UnitDelay * rtb_UnitDelay) * rtb_bias) + rtb_Sum_di;

      /* '<S65>:1:23' */
      rtb_UnitDelay = (*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
        vdy_ye_R_curve_p[2];

      /* '<S65>:1:24' */
      rtb_Q[3] = ((rtb_UnitDelay * rtb_UnitDelay) * rtb_bias) + rtb_Sum_di;
    } else {
      /*  otherwise use the yaw rate curve as meas input the driver intended curvature is not used  */
      /*  so the measurement variance of the di curve is high */
      /* '<S65>:1:28' */
      rtb_Q[0] = rtb_UnitDelay;
      rtb_Q[2] = 0.0F;
      rtb_Q[1] = 0.0F;
      rtb_Q[3] = ((rtb_bias * rtb_gain) * rtb_gain) + rtb_Sum_di;
    }
  } else {
    /*  no steering input, use only yaw rate for curvature */
    /* '<S65>:1:32' */
    rtb_Q[0] = rtb_UnitDelay;
    rtb_Q[2] = 0.0F;
    rtb_Q[1] = 0.0F;
    rtb_Q[3] = ((rtb_bias * rtb_gain) * rtb_gain) + rtb_Sum_di;
  }

  /* Embedded MATLAB: '<S38>/make_A_matrix' */
  vdy_ye_make_A_matrix(rtb_Time2Sec, &vdy_ye_B->sf_make_A_matrix_l);

  /* UnitDelay: '<S7>/x_delay' */
  for (i = 0; i < 2; i++) {
    rtb_xpost_e[i] = vdy_ye_DWork->x_delay_DSTATE_k[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S7>/vdy_s-func_x_pred' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)vdy_ye_B->sf_make_A_matrix_l.A,
                                      (real32_T*)rtb_xpost_e, rtb_x_pred_k,
    (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S7>/hx' */
  /* Embedded MATLAB Function 'curve_KF/hx': '<S32>:1' */
  /*  transformation from the state space to the measurement space  */
  /* '<S32>:1:3' */
  for (i = 0; i < 4; i++) {
    rtb_H_g[i] = (real32_T)tmp_2[i];
  }

  /* '<S32>:1:5' */
  for (i = 0; i < 2; i++) {
    rtb_hx_g[i] = 0.0F;
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_hx_g[i] = (((real32_T)tmp_2[(i_0 << 1) + i]) * rtb_x_pred_k[i_0]) +
        rtb_hx_g[i];
    }
  }

  /* Product: '<S39>/Divide' incorporates:
   *  Constant: '<S39>/Constant'
   *  Product: '<S39>/Product1'
   */
  rtb_Divide_m = (rtb_Time2Sec * rtb_Time2Sec) * 0.5F;

  /* Embedded MATLAB: '<S42>/sigma_velocity_gain_controll' incorporates:
   *  Constant: '<S42>/sigma_model'
   *  Constant: '<S42>/sigma_velo_gain'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_A_Q_curve/Q/gain_sigmas_over_velocity/sigma_velocity_gain_controll': '<S44>:1' */
  /*  if gain controll over velocity is selected */
  if (vdy_ye_Q_sigmas_velo_gain_p[0] == 1.0F) {
    /* '<S44>:1:3' */
    /*     if velocity is  below the max gain controled velocity */
    if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo <=
        vdy_ye_Q_sigmas_velo_gain_p[3]) {
      /* '<S44>:1:5' */
      /*  calculate the new sigmas controled by the velocity */
      /* '<S44>:1:7' */
      /* '<S44>:1:8' */
      rtb_UnitDelay = ((((vdy_ye_Q_sigmas_velo_gain_p[1] -
                          vdy_ye_Q_sigmas_velo_gain_p[2]) /
                         (vdy_ye_Q_sigmas_velo_gain_p[3] *
                          vdy_ye_Q_sigmas_velo_gain_p[3])) *
                        ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
                         vdy_ye_Q_sigmas_velo_gain_p[3])) *
                       ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
                        vdy_ye_Q_sigmas_velo_gain_p[3])) +
        vdy_ye_Q_sigmas_velo_gain_p[2];

      /* '<S44>:1:9' */
      rtb_TmpSignalConversionAtSFun_l[0] = rtb_UnitDelay;
      rtb_TmpSignalConversionAtSFun_l[1] = rtb_UnitDelay;
    } else {
      /*  constant sigma if above the threshold velocity */
      /* '<S44>:1:12' */
      rtb_TmpSignalConversionAtSFun_l[0] = vdy_ye_Q_sigmas_velo_gain_p[2];
      rtb_TmpSignalConversionAtSFun_l[1] = vdy_ye_Q_sigmas_velo_gain_p[2];
    }
  } else {
    /*  not velocity gain controlled */
    /* '<S44>:1:16' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_l[i] = vdy_ye_Q_sigmas_curve_p[(i)];
    }
  }

  /* UnitDelay: '<S40>/delay' */
  rtb_UnitDelay = vdy_ye_DWork->delay_DSTATE;

  /* Embedded MATLAB: '<S12>/divide_yaw_rate' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S12>/hold_counter'
   *  UnitDelay: '<S12>/last_yaw_rate_curve'
   *  UnitDelay: '<S12>/ramp_counter'
   *  UnitDelay: '<S12>/ramp_factor'
   */
  /* Embedded MATLAB Function 'make_crv_z_vektor_R/divide_yaw_rate': '<S64>:1' */
  /*  calculate the yaw rate curve out of the yaw rate and the vehicle velocity */
  /*  velocity is zero and below use the last yaw rate curve as measurement input */
  if ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo <= 0.015F) {
    /* '<S64>:1:4' */
    /* '<S64>:1:5' */
    rtb_hold_counter_out = vdy_ye_DWork->hold_counter_DSTATE;

    /* '<S64>:1:6' */
    rtb_ramp_counter_out = vdy_ye_DWork->ramp_counter_DSTATE;

    /* '<S64>:1:7' */
    ramp_fact_out = vdy_ye_DWork->ramp_factor_DSTATE;

    /*  calculate the ramp factor only once  */
    if ((vdy_ye_DWork->hold_counter_DSTATE == 0) &&
        (vdy_ye_DWork->ramp_counter_DSTATE == 0)) {
      /* '<S64>:1:9' */
      /* '<S64>:1:10' */
      ramp_fact_out = vdy_ye_DWork->last_yaw_rate_curve_DSTATE / ((real32_T)
        vdy_ye_yaw_curve_ramp_para_p[1]);
    }

    /*  hold the last yaw rate curve a specified time */
    if (vdy_ye_DWork->hold_counter_DSTATE < vdy_ye_yaw_curve_ramp_para_p[0]) {
      /* '<S64>:1:13' */
      /* '<S64>:1:14' */
      rtb_hold_counter_out = (uint8_T)(vdy_ye_DWork->hold_counter_DSTATE + 1);

      /* '<S64>:1:15' */
      rtb_z_yaw_rate_curve = vdy_ye_DWork->last_yaw_rate_curve_DSTATE;
    } else if ((vdy_ye_DWork->ramp_counter_DSTATE <
                vdy_ye_yaw_curve_ramp_para_p[1]) &&
               (vdy_ye_DWork->hold_counter_DSTATE ==
                vdy_ye_yaw_curve_ramp_para_p[0])) {
      /* '<S64>:1:16' */
      /*  afterwards ramp out the yaw rate curve         */
      /* '<S64>:1:18' */
      rtb_ramp_counter_out = (uint8_T)(vdy_ye_DWork->ramp_counter_DSTATE + 1);

      /* '<S64>:1:19' */
      rtb_z_yaw_rate_curve = vdy_ye_DWork->last_yaw_rate_curve_DSTATE -
        ramp_fact_out;
    } else {
      /*  if yaw rate is  ramped out set all to zero */
      /* '<S64>:1:22' */
      rtb_ramp_counter_out = vdy_ye_yaw_curve_ramp_para_p[1];

      /* '<S64>:1:23' */
      rtb_z_yaw_rate_curve = 0.0F;
    }
  } else {
    /* '<S64>:1:27' */
    rtb_hold_counter_out = 0U;

    /* '<S64>:1:28' */
    rtb_ramp_counter_out = 0U;

    /* '<S64>:1:29' */
    ramp_fact_out = 0.0F;

    /* '<S64>:1:30' */
    rtb_z_yaw_rate_curve = rtb_yaw_rate_out / (*vdy_ye_U_VDYInternalData_in).
      vdy_ve_out.veh_velo;
  }

  /* SignalConversion: '<S12>/ConcatBufferAtmake_z_vectorIn1' */
  rtb_make_z_vector[0] = rtb_z_yaw_rate_curve;

  /* Product: '<S40>/Divide' incorporates:
   *  Sum: '<S45>/Diff'
   *  UnitDelay: '<S45>/UD'
   */
  vdy_ye_B->Divide = (rtb_make_z_vector[1] - vdy_ye_DWork->UD_DSTATE_i) /
    rtb_Time2Sec;

  /* Weighted Moving Average Block: '<S40>/Weighted Moving Average'
   *
   *  Finite Impulse Response Filter
   *
   * Input0  Data Type:  Floating Point real32_T
   * Output0 Data Type:  Floating Point real32_T
   *
   * Parameter: Gain
   *   Data Type:  Floating Point real32_T
   *
   */
  {
    real32_T yTemp1;
    rtb_Product1_j = vdy_ye_B->Divide * 0.125F;

    {
      int_T i1;
      real32_T *dw_TapDelayU = &vdy_ye_DWork->WeightedMovingAverage_TapDelayU[1];
      for (i1=0; i1 < 7; i1++) {
        yTemp1 = dw_TapDelayU[((i1)-1)] * vdy_ye_ConstP.WeightedMovingAverage[i1
          +1];
        rtb_Product1_j = rtb_Product1_j + yTemp1;
      }
    }
  }

  /* Sum: '<S40>/Add1' */
  rtb_Add1 = rtb_UnitDelay - rtb_Product1_j;

  /* S-Function (ex_sfun_abs): '<S40>/add_abs' */
  rtb_add_abs = CML_f_Abs( (real32_T)rtb_Add1);

  /* Embedded MATLAB: '<S48>/check_reset_condition' incorporates:
   *  UnitDelay: '<S48>/Unit Delay'
   */
  /* Embedded MATLAB Function 'make_A_Q_curve/calculate_Q_gain/tp_filter_peaks1/check_reset_condition': '<S50>:1' */
  if (rtb_add_abs > vdy_ye_DWork->UnitDelay_DSTATE_j) {
    /* '<S50>:1:3' */
    /* '<S50>:1:4' */
    rtb_Reset = 1U;

    /* '<S50>:1:5' */
    rtb_gain = rtb_add_abs;
  } else {
    /* '<S50>:1:7' */
    rtb_Reset = 0U;

    /* '<S50>:1:8' */
    rtb_gain = 0.0F;
  }

  /* Switch: '<S52>/Init' incorporates:
   *  Logic: '<S52>/FixPt Logical Operator'
   *  UnitDelay: '<S52>/FixPt Unit Delay1'
   *  UnitDelay: '<S52>/FixPt Unit Delay2'
   */
  if ((rtb_Reset != 0) || (vdy_ye_DWork->FixPtUnitDelay2_DSTATE != 0)) {
    rtb_Product1_j = rtb_gain;
  } else {
    rtb_Product1_j = vdy_ye_DWork->FixPtUnitDelay1_DSTATE;
  }

  /* Sum: '<S51>/Sum' incorporates:
   *  Gain: '<S51>/Gain'
   *  Sum: '<S51>/Diff'
   */
  rtb_bias = ((rtb_Product1_j - rtb_add_abs) * 0.95F) + rtb_add_abs;

  /* Embedded MATLAB: '<S40>/threshold_gain' */
  /* Embedded MATLAB Function 'make_A_Q_curve/calculate_Q_gain/threshold_gain': '<S47>:1' */
  if (rtb_bias > 0.002F) {
    /* '<S47>:1:3' */
    /* '<S47>:1:4' */
    rtb_Yk1 = rtb_bias * vdy_ye_Q_curve_gain_p;
  } else {
    /* '<S47>:1:6' */
    rtb_Yk1 = 1.0F;

    /* 0.001 */
  }

  /* DataTypeConversion: '<S46>/Value_in_uint' */
  rtb_Value_in_uint = (uint8_T)rtb_Yk1;

  /* Embedded MATLAB: '<S46>/hold_last_5_values' incorporates:
   *  DataTypeConversion: '<S46>/Last_value_uint'
   *  UnitDelay: '<S46>/hold_counter'
   *  UnitDelay: '<S46>/hold_value'
   */
  /* Embedded MATLAB Function 'make_A_Q_curve/calculate_Q_gain/hold_last_5_values/hold_last_5_values': '<S49>:1' */
  /*  Hold value 5 cycle if input value is one */
  /*  Added Value_in_uint and Last_value_uint to remove QAC Level 4 warnings */
  if ((((rtb_Value_in_uint == 1) && (((uint8_T)vdy_ye_DWork->hold_value_DSTATE)
         != 1)) && (vdy_ye_DWork->hold_counter_DSTATE_e == 0)) ||
      ((vdy_ye_DWork->hold_counter_DSTATE_e > 0) &&
       (vdy_ye_DWork->hold_counter_DSTATE_e <= 5))) {
    /* '<S49>:1:5' */
    if ((vdy_ye_DWork->hold_counter_DSTATE_e >= 1) && (rtb_Value_in_uint != 1))
    {
      /* '<S49>:1:6' */
      /* '<S49>:1:7' */
      /* '<S49>:1:8' */
      rtb_Value_in_uint = 0U;
    } else {
      /* '<S49>:1:10' */
      rtb_Yk1 = vdy_ye_DWork->hold_value_DSTATE;

      /* '<S49>:1:11' */
      rtb_Value_in_uint = (uint8_T)(vdy_ye_DWork->hold_counter_DSTATE_e + 1);
    }
  } else {
    /* '<S49>:1:14' */
    /* '<S49>:1:15' */
    rtb_Value_in_uint = 0U;
  }

  /* Product: '<S39>/Product' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_l[i] = rtb_TmpSignalConversionAtSFun_l[i] *
      rtb_Yk1;
  }

  /* SignalConversion: '<S43>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_TmpSignalConversionAtSFun_f[0] = rtb_Divide_m;
  rtb_TmpSignalConversionAtSFun_f[1] = rtb_Time2Sec;

  /* Embedded MATLAB: '<S39>/makeQ' */
  /* Embedded MATLAB Function 'make_A_Q_curve/Q/makeQ': '<S43>:1' */
  /*  calculate the model covariance matrix Q */
  /* '<S43>:1:3' */

  /* UnitDelay: '<S7>/P_delay' */
  for (i = 0; i < 4; i++) {
    rtb_KH_b[i] = vdy_ye_DWork->P_delay_DSTATE_l[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_AP' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)vdy_ye_B->sf_make_A_matrix_l.A,
                                      (real32_T*)rtb_KH_b,
    rtb_vdy_sfunc_HP_Ht_o2_b, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S7>/At' */
  vdy_ye_At(vdy_ye_B->sf_make_A_matrix_l.A, &vdy_ye_B->sf_At_i);

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_AP_At' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_vdy_sfunc_HP_Ht_o2_b,
    (real32_T*)vdy_ye_B->sf_At_i.y, rtb_KH_b, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S7>/APA_Q' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_1[i] = rtb_TmpSignalConversionAtSFun_f[i] *
      rtb_TmpSignalConversionAtSFun_l[i];
    rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFun_l[i] *
      rtb_TmpSignalConversionAtSFun_f[i];
  }

  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_P_pred_d[i_0 + (i << 1)] = rtb_KH_b[(i << 1) + i_0] +
        (rtb_TmpSignalConversionAtSFun_1[i_0] *
         rtb_TmpSignalConversionAtSFun_0[i]);
    }
  }

  /* S-Function (MatrixMultiplication): '<S34>/vdy_s-func_HP' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_H_g, (real32_T*)
    rtb_P_pred_d, rtb_KH_b, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S7>/Ht' */
  vdy_ye_At(rtb_H_g, &vdy_ye_B->sf_Ht_k);

  /* S-Function (MatrixMultiplication): '<S34>/vdy_s-func_HP_Ht' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_KH_b, (real32_T*)
    vdy_ye_B->sf_Ht_k.y, rtb_vdy_sfunc_HP_Ht_o2_b, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Sum: '<S7>/HPH_R' */
  for (i = 0; i < 4; i++) {
    rtb_HPHt_R_n[i] = rtb_Q[i] + rtb_vdy_sfunc_HP_Ht_o2_b[i];
  }

  /* Embedded MATLAB: '<S27>/Matrix_Inversion_2x2' */
  vdy_matrix_inversion_2x2(rtb_HPHt_R_n, &vdy_ye_B->sf_Matrix_Inversion_2x2);

  /* S-Function (MatrixMultiplication): '<S7>/vdy_s-func_P_Ht' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_P_pred_d, (real32_T*)
    vdy_ye_B->sf_Ht_k.y, rtb_P_predHt_n, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* If: '<S27>/If' incorporates:
   *  ActionPort: '<S36>/Action Port'
   *  ActionPort: '<S37>/Action Port'
   *  SubSystem: '<S27>/calculate the gain'
   *  SubSystem: '<S27>/set gain to default value'
   */
  if (!vdy_ye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* S-Function (MatrixMultiplication): '<S36>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1_f = vdy_matrix_multiplication( (real32_T*)
      rtb_P_predHt_n, (real32_T*)vdy_ye_B->sf_Matrix_Inversion_2x2.HPHt_R_inv,
      rtb_K_m, (uint8_T)2, (uint8_T)2, (uint8_T)2);

    /* Constant: '<S36>/K_normal' */
    rtb_K_curve_fault = 0U;
  } else {
    /* Constant: '<S37>/Constant' */
    for (i = 0; i < 4; i++) {
      rtb_K_m[i] = vdy_ye_K_curve_default_p[(i)];
    }

    /* Constant: '<S37>/K_disturbed' */
    rtb_K_curve_fault = 1U;
  }

  /* S-Function (MatrixMultiplication): '<S7>/vdy_s-func_KH' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_K_m, (real32_T*)rtb_H_g,
    rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S7>/eye' */
  /* Embedded MATLAB Function 'curve_KF/eye': '<S31>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S31>:1:5' */

  /* Sum: '<S7>/1_KH' */
  for (i = 0; i < 4; i++) {
    rtb_KH_b[i] = ((real32_T)tmp_3[i]) - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S7>/Reset_P_pred' */
  /* Embedded MATLAB Function 'curve_KF/Reset_P_pred': '<S29>:1' */
  if (vdy_ye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S29>:1:4' */
    /* '<S29>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out_p[i] = vdy_ye_P_curve_init_p[(i)];
    }
  } else {
    /* '<S29>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out_p[i] = rtb_P_pred_d[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S7>/vdy_s-func_P_post' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_KH_b, (real32_T*)
    rtb_P_pred_out_p, rtb_P_post_h, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<Root>/diag_curve_variance' */
  vdy_ye_diag_curve_variance(rtb_P_post_h, &vdy_ye_B->sf_diag_curve_variance);

  /* Embedded MATLAB: '<S7>/Reset_x_pred' */
  /* Embedded MATLAB Function 'curve_KF/Reset_x_pred': '<S30>:1' */
  if (vdy_ye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S30>:1:4' */
    /* '<S30>:1:6' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_l[i] = rtb_xpost_e[i];
    }
  } else {
    /* '<S30>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_l[i] = rtb_x_pred_k[i];
    }
  }

  /* Sum: '<S7>/z_Hx' */
  for (i = 0; i < 2; i++) {
    rtb_nu_p[i] = rtb_make_z_vector[i] - rtb_hx_g[i];
  }

  /* S-Function (MatrixMultiplication): '<S7>/vdy_s-func_K_nu' */
  rtb_Knu = vdy_matrix_multiplication( (real32_T*)rtb_K_m, (real32_T*)rtb_nu_p,
    rtb_vdy_sfunc_K_nu_o2, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S7>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_l[i] = rtb_TmpSignalConversionAtSFun_l[i] +
      rtb_vdy_sfunc_K_nu_o2[i];
  }

  /* Product: '<S6>/Product1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  Product: '<S6>/Product'
   */
  rtb_Product1_j = ((*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo *
                    (*vdy_ye_U_VDYInternalData_in).vdy_ve_out.veh_velo) *
    rtb_TmpSignalConversionAtSFun_l[0];

  /* BusAssignment: '<Root>/usage_bus_ass1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_BusAssignment = (*vdy_ye_U_VDYInternalData_in);
  rtb_BusAssignment.vdy_ye_out.veh_gye_rate_usage = rtb_gier_yaw_rate_var;
  rtb_BusAssignment.vdy_ye_out.veh_wye_rate_usage = rtb_wye_usage;
  rtb_BusAssignment.vdy_ye_out.veh_aye_rate_usage = rtb_aye_usage;
  rtb_BusAssignment.vdy_ye_out.veh_sye_rate_usage = rtb_sye_usage;
  rtb_BusAssignment.vdy_ye_out.veh_yaw_rate_var =
    vdy_ye_B->sf_diag_yaw_variance.y[1];
  rtb_BusAssignment.vdy_ye_out.veh_yaw_rate = rtb_yaw_rate_out;
  rtb_BusAssignment.vdy_ye_out.veh_merge_curve_var =
    vdy_ye_B->sf_diag_curve_variance.y[0];
  rtb_BusAssignment.vdy_ye_out.veh_merge_curve_grad_var =
    vdy_ye_B->sf_diag_curve_variance.y[1];
  rtb_BusAssignment.vdy_ye_out.veh_lat_accel = rtb_Product1_j;
  rtb_BusAssignment.vdy_ye_out.veh_merge_curve =
    rtb_TmpSignalConversionAtSFun_l[0];
  rtb_BusAssignment.vdy_ye_out.veh_merge_curve_grad =
    rtb_TmpSignalConversionAtSFun_l[1];
  rtb_BusAssignment.vdy_ye_out.veh_yaw_angle = rtb_x_pred_out[0];

  /* Sum: '<S5>/Add' incorporates:
   *  BusSelector: '<S5>/Bus Selector'
   */
  rtb_Add_d = rtb_BusAssignment.vdy_offsets_in.vdy_yaw_offset.offset -
    rtb_BusAssignment.vdy_wye_out.gier_yaw_rate_offset;

  /* Embedded MATLAB: '<S5>/check_stat_and_quality' incorporates:
   *  BusSelector: '<S5>/Bus Selector'
   *  S-Function (ex_sfun_abs): '<S5>/abs_stand_still_gier_yaw_rate_offset'
   *  Sum: '<S5>/Add'
   */
  /* Embedded MATLAB Function 'TuneYawRateVar/check_stat_and_quality': '<S25>:1' */
  /*  if external yaw rate sensor is used */
  /* '<S25>:1:3' */
  rtb_UnitDelay = rtb_BusAssignment.vdy_ye_out.veh_yaw_rate_var;
  if (rtb_BusAssignment.vdy_offsets_in.vdy_yaw_offset.quality == 1.5F) {
    /* '<S25>:1:4' */
    /* '<S25>:1:5' */
    rtb_UnitDelay = (CML_f_Abs( (real32_T)rtb_Add_d) * vdy_yaw_rate_var_tune_p)
      + rtb_BusAssignment.vdy_ye_out.veh_yaw_rate_var;
  }

  /* BusAssignment: '<S5>/Bus Assignment' incorporates:
   *  BusSelector: '<S5>/Bus Selector'
   */
  rtb_BusAssignment.vdy_ye_out.veh_yaw_rate_var_org =
    rtb_BusAssignment.vdy_ye_out.veh_yaw_rate_var;
  rtb_BusAssignment.vdy_ye_out.veh_yaw_rate_var = rtb_UnitDelay;

  /* Outport: '<Root>/VDYInternalData_out' */
  (*vdy_ye_Y_VDYInternalData_out) = rtb_BusAssignment;

  /* Outport: '<Root>/K_yaw' */
  for (i = 0; i < 8; i++) {
    vdy_ye_Y_K_yaw[(i)] = rtb_K[i];
  }

  /* Outport: '<Root>/K_yaw_fault' */
  (*vdy_ye_Y_K_yaw_fault) = rtb_K_yaw_fault;

  /* Outport: '<Root>/K_curve' */
  for (i = 0; i < 4; i++) {
    vdy_ye_Y_K_curve[(i)] = rtb_K_m[i];
  }

  /* Outport: '<Root>/K_curve_fault' */
  (*vdy_ye_Y_K_curve_fault) = rtb_K_curve_fault;

  /* Switch: '<S52>/Reset' */
  if (rtb_Reset == 0) {
    rtb_gain = rtb_bias;
  }

  /* Update for UnitDelay: '<S17>/UD' */
  vdy_ye_DWork->UD_DSTATE = rtb_Sum_l;

  /* Update for UnitDelay: '<S15>/x_delay' */
  for (i = 0; i < 2; i++) {
    vdy_ye_DWork->x_delay_DSTATE[(i)] = rtb_x_pred_out[i];
  }

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  vdy_ye_DWork->UnitDelay_DSTATE = rtb_diff;

  /* Update for UnitDelay: '<S60>/T3' */
  vdy_ye_DWork->T3_DSTATE = rtb_T2;

  /* Update for UnitDelay: '<S60>/T2' */
  vdy_ye_DWork->T2_DSTATE = rtb_T1;

  /* Update for UnitDelay: '<S60>/T1' */
  vdy_ye_DWork->T1_DSTATE = rtb_T0;

  /* Update for UnitDelay: '<S60>/T0' */
  vdy_ye_DWork->T0_DSTATE = rtb_x_pred_out[1];

  /* Update for UnitDelay: '<S15>/P_delay' */
  for (i = 0; i < 4; i++) {
    vdy_ye_DWork->P_delay_DSTATE[(i)] = rtb_P_post[i];
  }

  /* Update for UnitDelay: '<S18>/UD' */
  vdy_ye_DWork->UD_DSTATE_m = rtb_Sum_lq;

  /* Update for UnitDelay: '<S20>/UD' */
  vdy_ye_DWork->UD_DSTATE_h = rtb_Sum_n;

  /* Update for UnitDelay: '<S19>/UD' */
  vdy_ye_DWork->UD_DSTATE_j = rtb_Sum_d;

  /* Update for UnitDelay: '<S66>/UD' */
  vdy_ye_DWork->UD_DSTATE_hz = rtb_Sum_di;

  /* Update for UnitDelay: '<S7>/x_delay' */
  for (i = 0; i < 2; i++) {
    vdy_ye_DWork->x_delay_DSTATE_k[(i)] = rtb_TmpSignalConversionAtSFun_l[i];
  }

  /* Update for UnitDelay: '<S40>/delay' */
  vdy_ye_DWork->delay_DSTATE = rtb_TmpSignalConversionAtSFun_l[1];

  /* Update for UnitDelay: '<S12>/hold_counter' */
  vdy_ye_DWork->hold_counter_DSTATE = rtb_hold_counter_out;

  /* Update for UnitDelay: '<S12>/ramp_counter' */
  vdy_ye_DWork->ramp_counter_DSTATE = rtb_ramp_counter_out;

  /* Update for UnitDelay: '<S12>/ramp_factor' */
  vdy_ye_DWork->ramp_factor_DSTATE = ramp_fact_out;

  /* Update for UnitDelay: '<S12>/last_yaw_rate_curve' */
  vdy_ye_DWork->last_yaw_rate_curve_DSTATE = rtb_z_yaw_rate_curve;

  /* Update for UnitDelay: '<S45>/UD' */
  vdy_ye_DWork->UD_DSTATE_i = rtb_make_z_vector[1];

  /* Weighted Moving Average Block: '<S40>/Weighted Moving Average'
   */
  {
    int32_T iObj;

    /*
     * shift all the discrete states on time delay
     *  being careful not to overwrite a value before it
     *  has been moved.
     */
    for (iObj = (6); iObj > 0; iObj-- ) {
      vdy_ye_DWork->WeightedMovingAverage_TapDelayU[iObj] =
        vdy_ye_DWork->WeightedMovingAverage_TapDelayU[iObj-1];
    }

    /*
     * the top state is the current input
     */
    vdy_ye_DWork->WeightedMovingAverage_TapDelayU[0] = vdy_ye_B->Divide;
  }

  /* Update for UnitDelay: '<S48>/Unit Delay' */
  vdy_ye_DWork->UnitDelay_DSTATE_j = rtb_bias;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S52>/FixPt Constant'
   */
  vdy_ye_DWork->FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S52>/FixPt Unit Delay1' */
  vdy_ye_DWork->FixPtUnitDelay1_DSTATE = rtb_gain;

  /* Update for UnitDelay: '<S46>/hold_value' */
  vdy_ye_DWork->hold_value_DSTATE = rtb_Yk1;

  /* Update for UnitDelay: '<S46>/hold_counter' */
  vdy_ye_DWork->hold_counter_DSTATE_e = rtb_Value_in_uint;

  /* Update for UnitDelay: '<S7>/P_delay' */
  for (i = 0; i < 4; i++) {
    vdy_ye_DWork->P_delay_DSTATE_l[(i)] = rtb_P_post_h[i];
  }
}

/* Model initialize function */
void vdy_ye_initialize(boolean_T firstTime, BlockIO_vdy_ye *vdy_ye_B,
  D_Work_vdy_ye *vdy_ye_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_ye_B), 0,
                      sizeof(BlockIO_vdy_ye));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_ye_DWork, 0,
                      sizeof(D_Work_vdy_ye));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S17>/UD' */
    vdy_ye_DWork->UD_DSTATE = 2.5E-7F;

    /* InitializeConditions for UnitDelay: '<S15>/x_delay' */
    for (i = 0; i < 2; i++) {
      vdy_ye_DWork->x_delay_DSTATE[(i)] = vdy_ye_x_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S15>/P_delay' */
    for (i = 0; i < 4; i++) {
      vdy_ye_DWork->P_delay_DSTATE[(i)] = vdy_ye_P_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S18>/UD' */
    vdy_ye_DWork->UD_DSTATE_m = 2.5E-7F;

    /* InitializeConditions for UnitDelay: '<S20>/UD' */
    vdy_ye_DWork->UD_DSTATE_h = 2.5E-7F;

    /* InitializeConditions for UnitDelay: '<S19>/UD' */
    vdy_ye_DWork->UD_DSTATE_j = 2.5E-7F;

    /* InitializeConditions for UnitDelay: '<S7>/x_delay' */
    for (i = 0; i < 2; i++) {
      vdy_ye_DWork->x_delay_DSTATE_k[(i)] = vdy_ye_x_curve_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay2' */
    vdy_ye_DWork->FixPtUnitDelay2_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S46>/hold_value' */
    vdy_ye_DWork->hold_value_DSTATE = 1.0F;

    /* InitializeConditions for UnitDelay: '<S7>/P_delay' */
    for (i = 0; i < 4; i++) {
      vdy_ye_DWork->P_delay_DSTATE_l[(i)] = vdy_ye_P_curve_init_p[(i)];
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
