/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_sye.c
   Real-Time Workshop code generated for Simulink model vdy_sye.
   Model version                        : 1.3383
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:04:36 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:04:37 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy steering angle yaw rate estimation
   and driver intended curvature estimation
   VERSION:                             : $Revision: 1.5 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_sye.h"
#include "vdy_sye_private.h"

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
 *    '<S13>/make_A_matrix'
 *    '<S51>/make_A_matrix'
 */
void vdy_sye_make_A_matrix(real32_T rtu_CycleTime, rtB_make_A_matrix_vdy_sye
  *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<S13>/make_A_matrix' */
  /* Embedded MATLAB Function 'Q_A_addpation_curve/A/make_A_matrix': '<S18>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S18>:1:5' */
  localB->A[0] = 1.0F;
  localB->A[2] = rtu_CycleTime;
  for (i = 0; i < 2; i++) {
    localB->A[1 + (i << 1)] = (real32_T)i;
  }
}

/*
 * Output and update for atomic system:
 *    '<S2>/Time2Sec'
 *    '<S26>/Time2Sec'
 *    '<S44>/Time2Sec'
 *    '<S9>/Time2Sec'
 */
void vdy_sye_Time2Sec(uint16_T rtu_u, rtB_Time2Sec_vdy_sye *localB)
{
  /* Product: '<S15>/Time2Sec' incorporates:
   *  Constant: '<S15>/Constant'
   */
  localB->Time2Sec = ((real32_T)rtu_u) / 1000.0F;
}

/*
 * Output and update for atomic system:
 *    '<S17>/get_gain_bias'
 *    '<S54>/get_gain_bias'
 */
void vdy_sye_get_gain_bias(const real32_T rtu_q_gain[3],
  rtB_get_gain_bias_vdy_sye *localB)
{
  /* Embedded MATLAB: '<S17>/get_gain_bias' */
  /* Embedded MATLAB Function 'Q_A_addpation_curve/q_gain/get_gain_bias': '<S22>:1' */
  /*  extract parameters */
  /* '<S22>:1:3' */
  localB->gain = rtu_q_gain[0];

  /* '<S22>:1:4' */
  localB->bias = rtu_q_gain[1];

  /* '<S22>:1:5' */
  localB->default_diff = rtu_q_gain[2];
}

/*
 * Output and update for atomic system:
 *    '<S30>/Get_IO_State1'
 *    '<S28>/Get_IO_State2'
 *    '<S45>/Get_IO_State2'
 */
void vdy_sye_Get_IO_State1(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State1_vdy_sye *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S35>/Index Vector' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/*
 * Output and update for atomic system:
 *    '<S73>/Get_NVM_IO_State'
 *    '<S92>/Get_NVM_IO_State'
 */
void vdy_sye_Get_NVM_IO_State(uint32_T rtu_pos, uint32_T rtu_state_in, uint32_T
  rtu_VDYIOBitMask, rtB_Get_NVM_IO_State_vdy_sye *localB)
{
  int32_T x;
  uint32_T tmp;

  /* Embedded MATLAB: '<S73>/Get_NVM_IO_State' */
  /* Embedded MATLAB Function 'extract_understeer_grad/Get_SlfStGrad_IO_State/GetIOState/Get_NVM_IO_State': '<S74>:1' */
  /*  position in state array */
  /* '<S74>:1:4' */
  tmp = rtu_pos;
  if (rtu_pos > 2147483647U) {
    tmp = 2147483647U;
  }

  x = (int32_T)tmp;

  /* '<S74>:1:5' */
  /*  get state info */
  /* '<S74>:1:8' */
  localB->state = (rtu_state_in >> (x - ((x >> 5) << 5))) & rtu_VDYIOBitMask;
}

/*
 * Output and update for atomic system:
 *    '<S11>/At'
 *    '<S12>/At'
 */
void vdy_sye_At(const real32_T rtu_u[4], rtB_At_vdy_sye *localB)
{
  int32_T i;
  int32_T i_0;

  /* Embedded MATLAB: '<S11>/At' */
  /* Embedded MATLAB Function 'swa_curve_EKF/At': '<S94>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S94>:1:5' */
  for (i_0 = 0; i_0 < 2; i_0++) {
    for (i = 0; i < 2; i++) {
      localB->y[i + (i_0 << 1)] = rtu_u[(i << 1) + i_0];
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S11>/Ht'
 *    '<S12>/Ht'
 */
void vdy_sye_Ht(const real32_T rtu_u[2], rtB_Ht_vdy_sye *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<S11>/Ht' */
  /* Embedded MATLAB Function 'swa_curve_EKF/Ht': '<S96>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S96>:1:5' */
  for (i = 0; i < 2; i++) {
    localB->y[(i)] = rtu_u[(i)];
  }
}

/* Model step function */
void vdy_sye_step(BlockIO_vdy_sye *vdy_sye_B, D_Work_vdy_sye *vdy_sye_DWork,
                  VDYInputData_t *vdy_sye_U_VDYInputData, VDYInternalData_t
                  *vdy_sye_U_VDYInternalData_in, VDYNvData_t
                  *vdy_sye_U_VDYNVData_in, uint16_T vdy_sye_U_vdy_ctrl_op_mode,
                  VDYInternalData_t *vdy_sye_Y_VDYInternalData_out, VDYNvData_t *
                  vdy_sye_Y_VDYNVData_out)
{
  /* local block i/o variables */
  real32_T rtb_veh_velo;
  real32_T rtb_x_pred[3];
  real32_T rtb_veh_lat_accel;
  real32_T rtb_Add;
  real32_T rtb_P_pred[9];
  real32_T rtb_HPHt_R[4];
  real32_T rtb_P_predHt[6];
  real32_T rtb_K[6];
  real32_T rtb_P_post[9];
  real32_T rtb_veh_velo_kq;
  real32_T rtb_xpost_a[2];
  real32_T rtb_vdy_sfunc_x_pred_o2[2];
  real32_T rtb_gier_yaw_rate_l;
  real32_T rtb_Divide_h;
  real32_T rtb_P_pred_a[4];
  real32_T rtb_HPHt_R_l;
  real32_T rtb_vdy_sfunc_P_pred_Ht_o2[2];
  real32_T rtb_K_l[2];
  real32_T rtb_vdy_sfunc_P_post_o2[4];
  real32_T rtb_Add_g;
  real32_T rtb_xpost_m[2];
  real32_T rtb_vdy_sfunc_x_pred_o2_b[2];
  real32_T rtb_veh_velo_h;
  real32_T rtb_Divide_ln;
  real32_T rtb_P_pred_d[4];
  real32_T rtb_HPHt_R_n;
  real32_T rtb_vdy_sfunc_P_pred_Ht_o2_n[2];
  real32_T rtb_K_e[2];
  real32_T rtb_P_post_d[4];
  real32_T rtb_H[2];
  real32_T rtb_P_pred_out[4];
  real32_T rtb_H_p[2];
  real32_T rtb_P_pred_out_n[4];
  real32_T rtb_H_a[6];
  real32_T rtb_P_pred_out_d[9];
  real32_T rtb_y[3];
  real32_T rtb_y_f[6];
  real32_T rtb_y_e[9];
  real32_T rtb_diff;
  real32_T rtb_A[9];
  real32_T rtb_diff_c;
  real32_T rtb_quot;
  real32_T rtb_vdy_sfunc_HP_o2[6];
  real32_T rtb_vdy_sfunc_K_nu_o2[3];
  real32_T rtb_nu;
  real32_T rtb_vdy_sfunc_AP_At_o2[9];
  real32_T rtb_KH[9];
  real32_T rtb_vdy_sfunc_AP_o2[4];
  real32_T rtb_Knu[2];
  real32_T rtb_Add3;
  real32_T rtb_KH_c[4];
  uint32_T rtb_State;
  uint32_T rtb_State_p;
  uint16_T rtb_CycleTime;
  uint16_T rtb_CycleTime_b;
  uint16_T rtb_CycleTime_e;
  uint16_T rtb_CycleTime_k;
  uint8_T rtb_State_c[32];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_SFunction5_o1;
  uint8_T rtb_vdy_sfunc_K_gain_o1_b;
  uint8_T rtb_DataTypeConversion1;
  uint8_T rtb_DataTypeConversion;
  uint32_T c;
  real32_T rtb_rat[2];
  real32_T rtb_xpost[3];
  real32_T rtb_Divide;
  real32_T rtb_T2;
  real32_T rtb_T1;
  real32_T rtb_T0;
  real32_T rtb_T7;
  real32_T rtb_T6;
  real32_T rtb_T5;
  real32_T rtb_T4;
  real32_T rtb_z_out_a[2];
  real32_T rtb_hx_g[2];
  real32_T rtb_x_pred_out_f[3];
  int32_T rtb_DataTypeConversion2;
  int32_T rtb_DataTypeConversion3;
  real32_T rtb_T2_e;
  real32_T rtb_T1_p;
  real32_T rtb_T0_a;
  real32_T rtb_R_out_l;
  real32_T rtb_x_pred_out[2];
  real32_T rtb_z_out_c;
  real32_T rtb_T0_k;
  real32_T rtb_Q_gain_i;
  real32_T rtb_addVariance;
  real32_T rtb_hx_d;
  real32_T rtb_y_h[3];
  real32_T rtb_Reset;
  real32_T rtb_Reset_m;
  real32_T rtb_SlfStGradDisc_out;
  real32_T rtb_y_o;
  uint8_T rtb_R_onoff;
  real32_T rtb_SlfStGradMax_out;
  real32_T rtb_SlfStGradMin_out;
  real32_T rtb_SlfStGradNVM_out;
  real32_T rtb_sigma_EG;
  real32_T rtb_add_trav_dist;
  boolean_T rtb_y_c;
  real32_T rtb_Reset_l;
  uint8_T rtb_init_out;
  boolean_T rtb_trav_dist_reset_f;
  boolean_T rtb_R_onoff_n;
  real32_T rtb_init_SSG;
  uint8_T rtb_init;
  uint16_T rtb_y_a;
  uint32_T rtb_state;
  real32_T rtb_Q_h[9];
  real32_T rtb_R_out[4];
  int32_T i;
  real32_T rtb_rat_0[2];
  real32_T rtb_rat_1[4];
  real32_T rtb_z_out_a_0[2];
  static int8_T tmp[3] = { 0, 1, 0 };

  static int8_T tmp_0[3] = { 0, 0, 1 };

  /* BusSelector: '<Root>/Bus Selector5' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 32; i++) {
    rtb_State_c[i] = (*vdy_sye_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<S28>/Get_IO_State2' */
  vdy_sye_Get_IO_State1(rtb_State_c, &vdy_sye_B->Get_IO_State2, ((uint32_T)
    VDY_SIN_POS_SWA));

  /* end of Outputs for SubSystem: '<S28>/Get_IO_State2' */

  /* Embedded MATLAB: '<S28>/make_z_vector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'build_EG_Q_R_A_z/make_z_vektor/make_z_vector': '<S42>:1' */
  /*  if the steering wheel angle is availabel use the */
  /*  offst compensated steering wheel angle  */
  /*  otherwise set to zero */
  if (((uint32_T)vdy_sye_B->Get_IO_State2.IndexVector) == ((uint32_T)
       VDY_IO_STATE_VALID)) {
    /* '<S42>:1:5' */
    /* '<S42>:1:6' */
    rtb_R_onoff_n = TRUE;

    /* '<S42>:1:7' */
    rtb_z_out_a[0] = (*vdy_sye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate;
    rtb_z_out_a[1] = (*vdy_sye_U_VDYInputData).Signals.StWheelAngle -
      (*vdy_sye_U_VDYInternalData_in).vdy_offsets_in.vdy_swa_offset.offset;
  } else {
    /* '<S42>:1:9' */
    rtb_R_onoff_n = FALSE;

    /* '<S42>:1:10' */
    rtb_z_out_a[0] = (*vdy_sye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate;
    rtb_z_out_a[1] = 0.0F;
  }

  /* Embedded MATLAB: '<S27>/adapt_R_matrix' */
  /* Embedded MATLAB Function 'build_EG_Q_R_A_z/make_R/adapt_R_matrix': '<S40>:1' */
  /*  if the steering wheel angle is invalid */
  /* R_out = single([0.01^2 0.0;... */
  /*                 0.0 0.018^2]); */
  /* '<S40>:1:5' */
  for (i = 0; i < 4; i++) {
    rtb_R_out[i] = vdy_sye_R_SSG_p[(i)];
  }

  if (((int32_T)rtb_R_onoff_n) == 0) {
    /* '<S40>:1:6' */
    /* '<S40>:1:7' */
    rtb_R_out[3] = 100.0F;
  }

  /* BusSelector: '<S10>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 2; i++) {
    rtb_rat[i] = (*vdy_sye_U_VDYInputData).Parameter.SteeringRatio.swa.rat[(i)];
  }

  /* BusSelector: '<S10>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo = (*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /* BusSelector: '<S26>/Bus Selector3' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_CycleTime = (*vdy_sye_U_VDYInputData).Frame.CycleTime;

  /* Outputs for atomic SubSystem: '<S26>/Time2Sec' */
  vdy_sye_Time2Sec(rtb_CycleTime, &vdy_sye_B->Time2Sec);

  /* end of Outputs for SubSystem: '<S26>/Time2Sec' */

  /* Embedded MATLAB: '<S29>/make_A_matrix' */
  /* Embedded MATLAB Function 'build_EG_Q_R_A_z/Q_A_adapation_curve/A/make_A_matrix': '<S34>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S34>:1:5' */
  rtb_A[0] = 1.0F;
  rtb_A[3] = vdy_sye_B->Time2Sec.Time2Sec;
  rtb_A[6] = 0.0F;
  for (i = 0; i < 3; i++) {
    rtb_A[1 + (3 * i)] = (real32_T)tmp[i];
  }

  for (i = 0; i < 3; i++) {
    rtb_A[2 + (3 * i)] = (real32_T)tmp_0[i];
  }

  /* UnitDelay: '<S10>/x_delay_eg' */
  for (i = 0; i < 3; i++) {
    rtb_xpost[i] = vdy_sye_DWork->x_delay_eg_DSTATE[(i)];
  }

  /* BusSelector: '<S10>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYNVData_in'
   */
  rtb_State = (*vdy_sye_U_VDYNVData_in).Read.State;

  /* Embedded MATLAB: '<S92>/Get_NVM_IO_State' */
  vdy_sye_Get_NVM_IO_State(((uint32_T)VDY_NVM_POS_SSG), rtb_State, 3U,
    &vdy_sye_B->sf_Get_NVM_IO_State);

  /* Embedded MATLAB: '<S10>/check_init_state' incorporates:
   *  Inport: '<Root>/VDYNVData_in'
   *  UnitDelay: '<S10>/init_nvm_eg_delay'
   */
  /* Embedded MATLAB Function 'swa_EG_EKF/check_init_state': '<S85>:1' */
  /*  check if NVMSSG is valid and first init is true */
  if ((vdy_sye_B->sf_Get_NVM_IO_State.state == ((uint32_T)VDY_IO_STATE_VALID)) &&
      (vdy_sye_DWork->init_nvm_eg_delay_DSTATE == 0)) {
    /* '<S85>:1:3' */
    /* '<S85>:1:4' */
    rtb_init_SSG = (*vdy_sye_U_VDYNVData_in).Read.SlfstGrad.SlfStGrad;

    /* '<S85>:1:5' */
    rtb_init = 1U;

    /* '<S85>:1:6' */
    rtb_init_out = 1U;
  } else {
    /* '<S85>:1:8' */
    rtb_init_SSG = 0.005F;

    /* '<S85>:1:9' */
    rtb_init = 0U;

    /* '<S85>:1:10' */
    rtb_init_out = vdy_sye_DWork->init_nvm_eg_delay_DSTATE;
  }

  /* Embedded MATLAB: '<S10>/Range check of the SSG' */
  /* Embedded MATLAB Function 'swa_EG_EKF/Range check of the SSG': '<S81>:1' */
  /*  check for understeer range violences */
  /* '<S81>:1:3' */
  for (i = 0; i < 3; i++) {
    rtb_y[i] = rtb_xpost[i];
  }

  /*  if understeer gradient is below 0.1  */
  if (rtb_xpost[2] < 0.00175F) {
    /* '<S81>:1:5' */
    /* '<S81>:1:6' */
    rtb_y[2] = 0.00175F;
  }

  /*  if understeer gradient is over 0.45 */
  if (rtb_xpost[2] > 0.00785F) {
    /* '<S81>:1:9' */
    /* '<S81>:1:10' */
    rtb_y[2] = 0.00785F;
  }

  /*  init self steering gradient if init is true */
  if (rtb_init == 1) {
    /* '<S81>:1:14' */
    /* '<S81>:1:15' */
    rtb_y[2] = rtb_init_SSG;
  }

  /* S-Function (MatrixMultiplication): '<S10>/vdy_s-func_x_pred' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_y, rtb_x_pred, (uint8_T)3, (uint8_T)3, (uint8_T)1);

  /* Embedded MATLAB: '<S10>/hx' incorporates:
   *  BusSelector: '<S10>/Bus Selector1'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S10>/veh_velo_abs'
   */
  rtb_init_SSG = rtb_veh_velo;

  /* Embedded MATLAB Function 'swa_EG_EKF/hx': '<S86>:1' */
  /*  calculate transformation from state space to measurement space */
  if (CML_f_Abs( (real32_T)rtb_veh_velo) <= 0.0001F) {
    /* '<S86>:1:4' */
    /* '<S86>:1:5' */
    rtb_init_SSG = 0.0001F;
  }

  /* '<S86>:1:8' */
  /*  non linear equation  */
  /* '<S86>:1:10' */
  rtb_hx_g[0] = rtb_x_pred[1];
  rtb_hx_g[1] = ((((rtb_init_SSG * rtb_init_SSG) * rtb_x_pred[2]) +
                  (*vdy_sye_U_VDYInputData).Parameter.WheelBase) * (rtb_rat[1] *
    rtb_x_pred[1])) / rtb_init_SSG;

  /*  linearised transformation matrix H */
  /* '<S86>:1:13' */
  for (i = 0; i < 3; i++) {
    rtb_H_a[i << 1] = (real32_T)tmp[i];
  }

  rtb_H_a[1] = 0.0F;
  rtb_H_a[3] = (rtb_rat[1] * (*vdy_sye_U_VDYInputData).Parameter.WheelBase) /
    rtb_init_SSG;
  rtb_H_a[5] = (rtb_rat[1] * (*vdy_sye_U_VDYInternalData_in).
                vdy_gye_out.gier_yaw_rate) * rtb_init_SSG;

  /* Product: '<S31>/Divide' incorporates:
   *  Constant: '<S31>/Constant'
   *  Product: '<S31>/Product1'
   */
  rtb_Divide = (vdy_sye_B->Time2Sec.Time2Sec * vdy_sye_B->Time2Sec.Time2Sec) *
    0.5F;

  /* UnitDelay: '<S37>/T3' */
  rtb_init_SSG = vdy_sye_DWork->T3_DSTATE;

  /* UnitDelay: '<S37>/T2' */
  rtb_T2 = vdy_sye_DWork->T2_DSTATE;

  /* UnitDelay: '<S37>/T1' */
  rtb_T1 = vdy_sye_DWork->T1_DSTATE;

  /* UnitDelay: '<S37>/T0' */
  rtb_T0 = vdy_sye_DWork->T0_DSTATE;

  /* UnitDelay: '<S37>/T7' */
  rtb_T7 = vdy_sye_DWork->T7_DSTATE;

  /* UnitDelay: '<S37>/T6' */
  rtb_T6 = vdy_sye_DWork->T6_DSTATE;

  /* UnitDelay: '<S37>/T5' */
  rtb_T5 = vdy_sye_DWork->T5_DSTATE;

  /* UnitDelay: '<S37>/T4' */
  rtb_T4 = vdy_sye_DWork->T4_DSTATE;

  /* Outputs for atomic SubSystem: '<S30>/Get_IO_State1' */
  vdy_sye_Get_IO_State1(rtb_State_c, &vdy_sye_B->Get_IO_State1, ((uint32_T)
    VDY_SIN_POS_LATA));

  /* end of Outputs for SubSystem: '<S30>/Get_IO_State1' */

  /* BusSelector: '<S26>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_lat_accel = (*vdy_sye_U_VDYInternalData_in).vdy_ye_out.veh_lat_accel;

  /* Sum: '<S26>/Add' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_Add = (*vdy_sye_U_VDYInputData).Signals.StWheelAngle -
    (*vdy_sye_U_VDYInternalData_in).vdy_offsets_in.vdy_swa_offset.offset;

  /* Embedded MATLAB: '<S33>/get_bit' incorporates:
   *  Constant: '<S33>/bitmask'
   *  Inport: '<Root>/VDYInputData'
   *  S-Function (sfix_bitop): '<S33>/Bitwise Operator'
   */
  /* Embedded MATLAB Function 'get_bit/get_bit': '<S39>:1' */
  /*  get state of a specified bit */
  if (((*vdy_sye_U_VDYInputData).Frame.CaliMode & ((uint16_T)VDY_CAL_SWA_GRAD)) ==
      ((uint16_T)VDY_CAL_SWA_GRAD)) {
    /* '<S39>:1:3' */
    /* '<S39>:1:4' */
    rtb_y_a = 1U;
  } else {
    /* '<S39>:1:6' */
    rtb_y_a = 0U;
  }

  /* Embedded MATLAB: '<S30>/controll_ssg_noice' incorporates:
   *  BusSelector: '<S26>/Bus Selector2'
   *  BusSelector: '<S26>/Bus Selector3'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S30>/lateral_accel_abs'
   *  S-Function (ex_sfun_abs): '<S30>/stw_angle_abs'
   *  Sum: '<S26>/Add'
   */
  /* Embedded MATLAB Function 'build_EG_Q_R_A_z/Q_A_adapation_curve/Build_EG_State/controll_ssg_noice': '<S36>:1' */
  /*  this function calculates the model noise parameter EG velocity for the EG understeer */
  /*  gradient, if the driving situation is suitable for EG learning */
  /*  the EG velocity is tuned up otherwise the EG velocity is very small */
  /*  if on of the imput signal used for driving situation detection */
  /*  is not abailable the velocty is small */
  /* if ((velocity < single(5.0)) || (velocity > single(24.0)) || (lat_accel_state ~= VDY_IO_STATE_VALID)) */
  /*  if ((velocity < vdy_sye_Q_SSG_range_p(7)) || (velocity > vdy_sye_Q_SSG_range_p(8)) || (lat_accel_state ~= VDY_IO_STATE_VALID)) */
  /*  %    sigma_EG = single(0.0000000000001); % 1 exp -8 */
  /*      sigma_EG = vdy_sye_Q_SSG_range_p(6); */
  /*      r = single(0.0); */
  /*      vmax = single(0.0); */
  /*      vq = single(0.0); */
  /*      vmin = single(0.0); */
  /*      EGDyn = single(0.0); */
  /*  else */
  /*      VelocityQ = velocity*velocity; */
  /*      vq = VelocityQ; */
  /*      LatAccelRadius = VelocityQ / lateral_accel; */
  /*      r = LatAccelRadius; */
  /*  %    MaxVeloQ = LatAccelRadius * single(4.0); */
  /*      MaxVeloQ = LatAccelRadius * vdy_sye_Q_SSG_range_p(4); */
  /*      vmax = MaxVeloQ; */
  /*  %    MinVeloQ = LatAccelRadius * single(0.5); */
  /*      MinVeloQ = LatAccelRadius * vdy_sye_Q_SSG_range_p(3); */
  /*      vmin = MinVeloQ; */
  /*  %    if ((LatAccelRadius >= 25) && (LatAccelRadius <= 500) && (VelocityQ <= MaxVeloQ) && (VelocityQ >= MinVeloQ)) */
  /*      if ((LatAccelRadius >=  vdy_sye_Q_SSG_range_p(1)) && (LatAccelRadius <=  vdy_sye_Q_SSG_range_p(2)) && (VelocityQ <= MaxVeloQ) && (VelocityQ >= MinVeloQ)) */
  /*  %         sigma_EG = single(0.000000001); */
  /*          sigma_EG = vdy_sye_Q_SSG_range_p(5); */
  /*          EGDyn = single(1.0); */
  /*      else */
  /*  %         sigma_EG = single(0.0000000000001); % 1 exp -8 */
  /*          sigma_EG = vdy_sye_Q_SSG_range_p(6); */
  /*          EGDyn = single(0.0); */
  /*      end; */
  /*   */
  /*  end */
  /*  if the steering wheel angle is below a specified value */
  /*  and the lateral acceleration is in a specified range then the EG learning is possible */
  if ((((CML_f_Abs( (real32_T)rtb_Add) < vdy_sye_Q_SSG_range_p[0]) && (CML_f_Abs
         ( (real32_T)rtb_veh_lat_accel) >= vdy_sye_Q_SSG_range_p[1])) &&
       (CML_f_Abs( (real32_T)rtb_veh_lat_accel) <= vdy_sye_Q_SSG_range_p[2])) &&
      ((*vdy_sye_U_VDYInternalData_in).vdy_offsets_in.vdy_swa_offset.state >= 2))
  {
    /* '<S36>:1:44' */
    /* '<S36>:1:45' */
    rtb_sigma_EG = vdy_sye_Q_SSG_range_p[3];

    /* '<S36>:1:46' */
    /* '<S36>:1:47' */
    /* '<S36>:1:48' */
    /* '<S36>:1:49' */
    /* '<S36>:1:50' */
    rtb_init = 0U;
  } else {
    /* '<S36>:1:52' */
    rtb_sigma_EG = vdy_sye_Q_SSG_range_p[4];

    /* '<S36>:1:53' */
    /* '<S36>:1:54' */
    /* '<S36>:1:55' */
    /* '<S36>:1:56' */
    /* '<S36>:1:57' */
    rtb_init = 1U;
  }

  if (rtb_y_a == 1) {
    /* '<S36>:1:60' */
    /* '<S36>:1:61' */
    rtb_init = 1U;
  }

  /* Product: '<S37>/Divide' incorporates:
   *  Constant: '<S37>/filter_length'
   *  Sum: '<S37>/Add'
   */
  rtb_init_SSG = ((((((((rtb_init_SSG + rtb_T2) + rtb_T1) + rtb_T0) + rtb_T7) +
                     rtb_T6) + rtb_T5) + rtb_T4) + rtb_sigma_EG) * 0.11111F;

  /* SignalConversion: '<S38>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_rat[0] = rtb_Divide;
  rtb_rat[1] = vdy_sye_B->Time2Sec.Time2Sec;

  /* Embedded MATLAB: '<S31>/makeQ' incorporates:
   *  Constant: '<S31>/sigma_model'
   */
  /* Embedded MATLAB Function 'build_EG_Q_R_A_z/Q_A_adapation_curve/Q/makeQ': '<S38>:1' */
  /*  calculate the model covariance matrix Q */
  /* '<S38>:1:3' */
  /* '<S38>:1:4' */
  for (i = 0; i < 2; i++) {
    rtb_rat_0[i] = rtb_rat[i] * vdy_sye_Q_SSG_sigmas_p[(i)];
    rtb_z_out_a_0[i] = vdy_sye_Q_SSG_sigmas_p[(i)] * rtb_rat[i];
  }

  for (i = 0; i < 2; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 2;
         rtb_DataTypeConversion2++) {
      rtb_rat_1[rtb_DataTypeConversion2 + (i << 1)] =
        rtb_rat_0[rtb_DataTypeConversion2] * rtb_z_out_a_0[i];
    }
  }

  for (i = 0; i < 2; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 2;
         rtb_DataTypeConversion2++) {
      rtb_Q_h[rtb_DataTypeConversion2 + (3 * i)] = rtb_rat_1[(i << 1) +
        rtb_DataTypeConversion2];
    }
  }

  for (i = 0; i < 2; i++) {
    rtb_Q_h[i + 6] = 0.0F;
  }

  rtb_Q_h[2] = 0.0F;
  rtb_Q_h[5] = 0.0F;
  rtb_Q_h[8] = ((vdy_sye_B->Time2Sec.Time2Sec * vdy_sye_B->Time2Sec.Time2Sec) *
                rtb_init_SSG) * rtb_init_SSG;

  /* UnitDelay: '<S10>/P_delay_eg' */
  for (i = 0; i < 9; i++) {
    rtb_vdy_sfunc_AP_At_o2[i] = vdy_sye_DWork->P_delay_eg_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S87>/vdy_s-func_AP' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_vdy_sfunc_AP_At_o2, rtb_KH, (uint8_T)3, (uint8_T)3, (uint8_T)
    3);

  /* Embedded MATLAB: '<S10>/At' */
  /* Embedded MATLAB Function 'swa_EG_EKF/At': '<S77>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S77>:1:5' */
  for (i = 0; i < 3; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 3;
         rtb_DataTypeConversion2++) {
      rtb_y_e[rtb_DataTypeConversion2 + (3 * i)] = rtb_A[(3 *
        rtb_DataTypeConversion2) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S87>/vdy_s-func_AP_At' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_y_e, rtb_vdy_sfunc_AP_At_o2, (uint8_T)3, (uint8_T)3, (uint8_T)
    3);

  /* Sum: '<S10>/APA_Q' */
  for (i = 0; i < 9; i++) {
    rtb_P_pred[i] = rtb_Q_h[i] + rtb_vdy_sfunc_AP_At_o2[i];
  }

  /* S-Function (MatrixMultiplication): '<S88>/vdy_s-func_HP' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_H_a,
    (real32_T*)rtb_P_pred, rtb_vdy_sfunc_HP_o2, (uint8_T)3, (uint8_T)2, (uint8_T)
    3);

  /* Embedded MATLAB: '<S10>/Ht' */
  /* Embedded MATLAB Function 'swa_EG_EKF/Ht': '<S80>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S80>:1:5' */
  for (i = 0; i < 2; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 3;
         rtb_DataTypeConversion2++) {
      rtb_y_f[rtb_DataTypeConversion2 + (3 * i)] = rtb_H_a
        [(rtb_DataTypeConversion2 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S88>/vdy_s-func_HP_Ht' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_HP_o2, (real32_T*)rtb_y_f, rtb_vdy_sfunc_AP_o2, (uint8_T)3,
    (uint8_T)2, (uint8_T)2);

  /* Sum: '<S10>/HPH_R' */
  for (i = 0; i < 4; i++) {
    rtb_HPHt_R[i] = rtb_R_out[i] + rtb_vdy_sfunc_AP_o2[i];
  }

  /* Embedded MATLAB: '<S78>/Matrix_Inversion_2x2' */
  vdy_matrix_inversion_2x2(rtb_HPHt_R, &vdy_sye_B->sf_Matrix_Inversion_2x2);

  /* S-Function (MatrixMultiplication): '<S10>/vdy_s-func_P_pred_Ht' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_y_f, rtb_P_predHt, (uint8_T)3, (uint8_T)3, (uint8_T)2);

  /* If: '<S78>/If' incorporates:
   *  ActionPort: '<S90>/Action Port'
   *  ActionPort: '<S91>/Action Port'
   *  SubSystem: '<S78>/calculate the gain'
   *  SubSystem: '<S78>/set gain to default value'
   */
  if (!vdy_sye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* S-Function (MatrixMultiplication): '<S90>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1_b = vdy_matrix_multiplication( (real32_T*)
      rtb_P_predHt, (real32_T*)vdy_sye_B->sf_Matrix_Inversion_2x2.HPHt_R_inv,
      rtb_K, (uint8_T)2, (uint8_T)3, (uint8_T)2);
  } else {
    /* Constant: '<S91>/Constant' */
    for (i = 0; i < 6; i++) {
      rtb_K[i] = vdy_sye_K_SSG_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S10>/vdy_s-func_KH' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_H_a, rtb_KH, (uint8_T)2, (uint8_T)3, (uint8_T)3);

  /* Sum: '<S10>/1_KH' incorporates:
   *  Constant: '<S10>/eye'
   */
  for (i = 0; i < 9; i++) {
    rtb_KH[i] = vdy_sye_I_SSG_matrix_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S10>/Reset_P_pred' */
  /* Embedded MATLAB Function 'swa_EG_EKF/Reset_P_pred': '<S82>:1' */
  if (vdy_sye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S82>:1:4' */
    /* '<S82>:1:6' */
    for (i = 0; i < 9; i++) {
      rtb_P_pred_out_d[i] = vdy_sye_P_SSG_init_p[(i)];
    }
  } else {
    /* '<S82>:1:10' */
    for (i = 0; i < 9; i++) {
      rtb_P_pred_out_d[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S10>/vdy_s-func_P_post' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out_d, rtb_P_post, (uint8_T)3, (uint8_T)3, (uint8_T)3);

  /* Embedded MATLAB: '<S9>/diag_EG' */
  /* Embedded MATLAB Function 'extract_understeer_grad/diag_EG': '<S68>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S68>:1:4' */
  for (i = 0; i < 3; i++) {
    rtb_y_h[i] = rtb_P_post[i << 2];
  }

  /* Embedded MATLAB: '<S9>/get_init_control_mode' incorporates:
   *  Inport: '<Root>/vdy_ctrl_op_mode'
   */
  /* Embedded MATLAB Function 'extract_understeer_grad/get_init_control_mode': '<S69>:1' */
  /*  if the vdy_ctrl mode is init in Radar or Op Mode is Reset in Camera, */
  /*  set the output too true. In RTE of MFC and RADAR */
  /*  BASE_OM_RESET	        (1) */
  /*  VDY_CTRL_STATE_INIT	(1) */
  if (vdy_sye_U_vdy_ctrl_op_mode == ((uint16_T)VDY_CTRL_STATE_INIT)) {
    /* '<S69>:1:6' */
    /* '<S69>:1:7' */
    rtb_R_onoff_n = TRUE;
  } else {
    /* '<S69>:1:9' */
    rtb_R_onoff_n = FALSE;
  }

  /* Embedded MATLAB: '<S10>/Reset_x_pred' */
  /* Embedded MATLAB Function 'swa_EG_EKF/Reset_x_pred': '<S83>:1' */
  if (vdy_sye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S83>:1:4' */
    /* '<S83>:1:6' */
    rtb_x_pred_out_f[0] = 0.0F;
    rtb_x_pred_out_f[1] = 0.0F;
    rtb_x_pred_out_f[2] = rtb_xpost[2];
  } else {
    /* '<S83>:1:10' */
    for (i = 0; i < 3; i++) {
      rtb_x_pred_out_f[i] = rtb_x_pred[i];
    }
  }

  /* Sum: '<S10>/z_Hx' */
  for (i = 0; i < 2; i++) {
    rtb_Knu[i] = rtb_z_out_a[i] - rtb_hx_g[i];
  }

  /* S-Function (MatrixMultiplication): '<S10>/vdy_s-func_K_nu' */
  rtb_DataTypeConversion1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_Knu, rtb_vdy_sfunc_K_nu_o2, (uint8_T)2, (uint8_T)3, (uint8_T)
    1);

  /* Embedded MATLAB: '<S10>/check_eg' incorporates:
   *  Sum: '<S10>/x_Knu'
   */
  /* Embedded MATLAB Function 'swa_EG_EKF/check_eg': '<S84>:1' */
  /*  If EG_Control is 1, so no EG should be leard. */
  /*  and the EG state in the filter is not updated */
  /* '<S84>:1:5' */
  for (i = 0; i < 3; i++) {
    rtb_xpost[i] = rtb_x_pred_out_f[i] + rtb_vdy_sfunc_K_nu_o2[i];
  }

  /*  if 0 don't update eg */
  if (rtb_init == 1) {
    /* '<S84>:1:7' */
    /* '<S84>:1:8' */
    rtb_xpost[2] = rtb_x_pred_out_f[2];
  }

  /* Switch: '<S75>/Reset' incorporates:
   *  Constant: '<S75>/Initial Condition'
   *  MinMax: '<S64>/MinMax'
   *  UnitDelay: '<S75>/FixPt Unit Delay1'
   */
  if (rtb_R_onoff_n) {
    rtb_Reset = 0.0F;
  } else {
    rtb_Reset = (rtb_xpost[2] >= vdy_sye_DWork->FixPtUnitDelay1_DSTATE) ?
      rtb_xpost[2] : vdy_sye_DWork->FixPtUnitDelay1_DSTATE;
  }

  /* Switch: '<S76>/Reset' incorporates:
   *  Constant: '<S76>/Initial Condition'
   *  MinMax: '<S65>/MinMax'
   *  UnitDelay: '<S76>/FixPt Unit Delay1'
   */
  if (rtb_R_onoff_n) {
    rtb_Reset_m = 0.008F;
  } else {
    rtb_Reset_m = (rtb_xpost[2] <= vdy_sye_DWork->FixPtUnitDelay1_DSTATE_b) ?
      rtb_xpost[2] : vdy_sye_DWork->FixPtUnitDelay1_DSTATE_b;
  }

  /* BusSelector: '<S9>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYNVData_in'
   */
  rtb_State_p = (*vdy_sye_U_VDYNVData_in).Read.State;
  rtb_DataTypeConversion1 = (*vdy_sye_U_VDYNVData_in).
    Read.SlfstGrad.SlfStGradMax;
  rtb_DataTypeConversion = (*vdy_sye_U_VDYNVData_in).Read.SlfstGrad.SlfStGradMin;

  /* Embedded MATLAB: '<S73>/Get_NVM_IO_State' */
  vdy_sye_Get_NVM_IO_State(((uint32_T)VDY_NVM_POS_SSG), rtb_State_p, 3U,
    &vdy_sye_B->sf_Get_NVM_IO_State_g);

  /* DataTypeConversion: '<S9>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = rtb_DataTypeConversion1;

  /* DataTypeConversion: '<S9>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = rtb_DataTypeConversion;

  /* BusSelector: '<S9>/Bus Selector3' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_CycleTime_b = (*vdy_sye_U_VDYInputData).Frame.CycleTime;

  /* Outputs for atomic SubSystem: '<S9>/Time2Sec' */
  vdy_sye_Time2Sec(rtb_CycleTime_b, &vdy_sye_B->Time2Sec_i);

  /* end of Outputs for SubSystem: '<S9>/Time2Sec' */

  /* UnitDelay: '<S9>/trav_dist_reset' */
  rtb_R_onoff_n = vdy_sye_DWork->trav_dist_reset_DSTATE;

  /* Switch: '<S70>/Init' incorporates:
   *  Constant: '<S70>/Initial Condition'
   *  Logic: '<S70>/FixPt Logical Operator'
   *  UnitDelay: '<S70>/FixPt Unit Delay1'
   *  UnitDelay: '<S70>/FixPt Unit Delay2'
   */
  if (vdy_sye_DWork->trav_dist_reset_DSTATE ||
      (vdy_sye_DWork->FixPtUnitDelay2_DSTATE != 0)) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = vdy_sye_DWork->FixPtUnitDelay1_DSTATE_g;
  }

  /* Sum: '<S9>/add_trav_dist' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  Product: '<S9>/inc_dist'
   */
  rtb_add_trav_dist = (vdy_sye_B->Time2Sec_i.Time2Sec *
                       (*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo) +
    rtb_Add3;

  /* Embedded MATLAB: '<S9>/check_with_read_values' incorporates:
   *  Inport: '<Root>/VDYNVData_in'
   *  UnitDelay: '<S9>/last_SlfStGradDisc'
   */
  /* Embedded MATLAB Function 'extract_understeer_grad/check_with_read_values': '<S67>:1' */
  /*  extract min max values */
  /* '<S67>:1:3' */
  rtb_Divide = ((real32_T)rtb_DataTypeConversion3) / 25000.0F;

  /* '<S67>:1:4' */
  rtb_init_SSG = ((real32_T)rtb_DataTypeConversion2) / 25000.0F;

  /*  if the actual min value is below the read nvm value use the actual */
  /* '<S67>:1:7' */
  if (rtb_Reset_m < rtb_Divide) {
    /* '<S67>:1:8' */
    /* '<S67>:1:9' */
    rtb_Divide = rtb_Reset_m;
  }

  /*  if the actual max value is above the read nvm value use the actual */
  /* '<S67>:1:14' */
  if (rtb_Reset > rtb_init_SSG) {
    /* '<S67>:1:15' */
    /* '<S67>:1:16' */
    rtb_init_SSG = rtb_Reset;
  }

  /*  calc new min max values */
  /* '<S67>:1:21' */
  /* '<S67>:1:22' */
  /* '<S67>:1:24' */
  rtb_trav_dist_reset_f = FALSE;

  /*  if self steering gradiend is read form the NVM check with actual calculated values */
  if (vdy_sye_B->sf_Get_NVM_IO_State_g.state == ((uint32_T)VDY_IO_STATE_VALID))
  {
    /* '<S67>:1:26' */
    /*  if the difference of the self steering gradien between the last saved NVM SSG and the actual estimated SSG is above 0.1 deg  */
    /*  and the traveled distances is above 30000.0m (30km) */
    if ((((rtb_xpost[2] - (*vdy_sye_U_VDYNVData_in).Read.SlfstGrad.SlfStGrad) >=
          0.00017453F) || ((rtb_xpost[2] - (*vdy_sye_U_VDYNVData_in).
                            Read.SlfstGrad.SlfStGrad) <= -0.00017453F)) &&
        (rtb_add_trav_dist > 30000.0F)) {
      /* '<S67>:1:29' */
      /* '<S67>:1:30' */
      rtb_SlfStGradNVM_out = rtb_xpost[2];

      /* '<S67>:1:31' */
      rtb_SlfStGradMax_out = rtb_init_SSG * 25000.0F;

      /* '<S67>:1:32' */
      rtb_SlfStGradMin_out = rtb_Divide * 25000.0F;

      /* '<S67>:1:33' */
      rtb_trav_dist_reset_f = TRUE;

      /* '<S67>:1:34' */
      rtb_state = ((uint32_T)VDY_IO_STATE_VALID);
    } else {
      /* '<S67>:1:36' */
      rtb_SlfStGradNVM_out = (*vdy_sye_U_VDYNVData_in).Read.SlfstGrad.SlfStGrad;

      /* '<S67>:1:37' */
      rtb_SlfStGradMax_out = (real32_T)rtb_DataTypeConversion2;

      /* '<S67>:1:38' */
      rtb_SlfStGradMin_out = (real32_T)rtb_DataTypeConversion3;

      /* '<S67>:1:39' */
      rtb_state = ((uint32_T)VDY_IO_STATE_INVALID);
    }
  } else {
    /* '<S67>:1:42' */
    rtb_SlfStGradNVM_out = (*vdy_sye_U_VDYNVData_in).Read.SlfstGrad.SlfStGrad;

    /* '<S67>:1:43' */
    rtb_SlfStGradMax_out = (real32_T)rtb_DataTypeConversion2;

    /* '<S67>:1:44' */
    rtb_SlfStGradMin_out = (real32_T)rtb_DataTypeConversion3;

    /* '<S67>:1:45' */
    rtb_state = ((uint32_T)VDY_IO_STATE_INVALID);
  }

  /*  discret ext self steer grad output */
  if (((rtb_xpost[2] - vdy_sye_DWork->last_SlfStGradDisc_DSTATE) >= 0.00017453F)
      || ((rtb_xpost[2] - vdy_sye_DWork->last_SlfStGradDisc_DSTATE) <=
          -0.00017453F)) {
    /* '<S67>:1:49' */
    /* '<S67>:1:50' */
    rtb_SlfStGradDisc_out = rtb_xpost[2];
  } else {
    /* '<S67>:1:52' */
    rtb_SlfStGradDisc_out = vdy_sye_DWork->last_SlfStGradDisc_DSTATE;
  }

  /* BusSelector: '<Root>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo_kq = (*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /* Outputs for atomic SubSystem: '<S45>/Get_IO_State2' */
  vdy_sye_Get_IO_State1(rtb_State_c, &vdy_sye_B->Get_IO_State2_k, ((uint32_T)
    VDY_SIN_POS_SWA));

  /* end of Outputs for SubSystem: '<S45>/Get_IO_State2' */

  /* Embedded MATLAB: '<S45>/make_z_vector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'build_Q_R_A_z/make_z_vektor/make_z_vector': '<S61>:1' */
  /*  if the steering wheel angle is available, use the */
  /*  offset compensated steering wheel angle, */
  /*  otherwise set to zero */
  if (((((uint32_T)vdy_sye_B->Get_IO_State2_k.IndexVector) == ((uint32_T)
         VDY_IO_STATE_INVALID)) || (((uint32_T)
         vdy_sye_B->Get_IO_State2_k.IndexVector) == ((uint32_T)
         VDY_IO_STATE_NOTAVAIL))) || (((uint32_T)
        vdy_sye_B->Get_IO_State2_k.IndexVector) == ((uint32_T)VDY_IO_STATE_INIT)))
  {
    /* '<S61>:1:5' */
    /* '<S61>:1:6' */
    rtb_R_onoff = 0U;

    /* '<S61>:1:7' */
    rtb_z_out_c = 0.0F;
  } else if ((*vdy_sye_U_VDYInternalData_in).vdy_offsets_in.vdy_swa_offset.state
             > 1) {
    /* '<S61>:1:9' */
    /* '<S61>:1:10' */
    rtb_R_onoff = 1U;

    /* '<S61>:1:11' */
    rtb_z_out_c = (*vdy_sye_U_VDYInputData).Signals.StWheelAngle -
      (*vdy_sye_U_VDYInternalData_in).vdy_offsets_in.vdy_swa_offset.offset;
  } else {
    /* '<S61>:1:13' */
    rtb_R_onoff = 2U;

    /* '<S61>:1:14' */
    rtb_z_out_c = (*vdy_sye_U_VDYInputData).Signals.StWheelAngle;
  }

  /* Embedded MATLAB: '<S3>/adapt_R_matrix' */
  /* Embedded MATLAB Function 'R/adapt_R_matrix': '<S25>:1' */
  /*  if the steering wheel angle is invalid */
  /* '<S25>:1:3' */
  rtb_R_out_l = vdy_sye_R_p[0];
  if (rtb_R_onoff == 0) {
    /* '<S25>:1:4' */
    /* '<S25>:1:5' */
    rtb_R_out_l = vdy_sye_R_p[1];
  }

  /* BusSelector: '<S44>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_CycleTime_e = (*vdy_sye_U_VDYInputData).Frame.CycleTime;

  /* Outputs for atomic SubSystem: '<S44>/Time2Sec' */
  vdy_sye_Time2Sec(rtb_CycleTime_e, &vdy_sye_B->Time2Sec_b);

  /* end of Outputs for SubSystem: '<S44>/Time2Sec' */

  /* Embedded MATLAB: '<S51>/make_A_matrix' */
  vdy_sye_make_A_matrix(vdy_sye_B->Time2Sec_b.Time2Sec,
                        &vdy_sye_B->sf_make_A_matrix_i);

  /* UnitDelay: '<S12>/x_delay_yaw' */
  for (i = 0; i < 2; i++) {
    rtb_xpost_a[i] = vdy_sye_DWork->x_delay_yaw_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S12>/vdy_s-func_x_pred' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)
    vdy_sye_B->sf_make_A_matrix_i.A, (real32_T*)rtb_xpost_a,
    rtb_vdy_sfunc_x_pred_o2, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S12>/hx1' */
  /* Embedded MATLAB Function 'swa_yaw_EKF/hx1': '<S110>:1' */
  /*  calculate the transformation from the state space to the measurement space */
  /* '<S110>:1:3' */
  /* '<S110>:1:4' */
  rtb_Divide = 0.0F;
  rtb_DataTypeConversion2 = 1;
  rtb_DataTypeConversion3 = 1;

  /* SignalConversion: '<S56>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S52>/Constant'
   *  Product: '<S52>/Divide'
   *  Product: '<S52>/Product1'
   */
  rtb_rat[0] = (vdy_sye_B->Time2Sec_b.Time2Sec * vdy_sye_B->Time2Sec_b.Time2Sec)
    / 2.0F;
  rtb_rat[1] = vdy_sye_B->Time2Sec_b.Time2Sec;

  /* Embedded MATLAB: '<S52>/makeQ' incorporates:
   *  Constant: '<S52>/sigma_model'
   */
  /* Embedded MATLAB Function 'build_Q_R_A_z/Q_A_adaptation_yaw/Q/makeQ': '<S56>:1' */
  /*  calculate the model covariance matrix Q */
  /* '<S56>:1:3' */
  for (i = 0; i < 2; i++) {
    rtb_H[i] = (real32_T)i;
    rtb_Divide += ((real32_T)((int8_T)(rtb_DataTypeConversion2 - 1))) *
      rtb_vdy_sfunc_x_pred_o2[rtb_DataTypeConversion3 - 1];
    rtb_DataTypeConversion2++;
    rtb_DataTypeConversion3++;
    rtb_rat_0[i] = rtb_rat[i] * vdy_sye_Q_sigmas_p[(i)];
    rtb_z_out_a_0[i] = vdy_sye_Q_sigmas_p[(i)] * rtb_rat[i];
  }

  for (i = 0; i < 2; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 2;
         rtb_DataTypeConversion2++) {
      rtb_R_out[rtb_DataTypeConversion2 + (i << 1)] =
        rtb_rat_0[rtb_DataTypeConversion2] * rtb_z_out_a_0[i];
    }
  }

  /* BusSelector: '<S44>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_gier_yaw_rate_l = (*vdy_sye_U_VDYInternalData_in).
    vdy_gye_out.gier_yaw_rate;

  /* UnitDelay: '<S58>/T2' */
  rtb_T2_e = vdy_sye_DWork->T2_DSTATE_f;

  /* UnitDelay: '<S58>/T1' */
  rtb_T1_p = vdy_sye_DWork->T1_DSTATE_k;

  /* UnitDelay: '<S58>/T0' */
  rtb_T0_a = vdy_sye_DWork->T0_DSTATE_f;

  /* Product: '<S58>/Divide' incorporates:
   *  Constant: '<S58>/filter_length'
   *  Sum: '<S58>/Add'
   *  UnitDelay: '<S58>/T3'
   */
  rtb_Divide_h = (((vdy_sye_DWork->T3_DSTATE_c + vdy_sye_DWork->T2_DSTATE_f) +
                   vdy_sye_DWork->T1_DSTATE_k) + vdy_sye_DWork->T0_DSTATE_f) *
    0.25F;

  /* Embedded MATLAB: '<S54>/get_gain_bias' */
  vdy_sye_get_gain_bias((&(vdy_sye_Q_gain_p[0])), &vdy_sye_B->sf_get_gain_bias);

  /* Embedded MATLAB: '<S54>/q_gain_delta' incorporates:
   *  BusSelector: '<S44>/Bus Selector1'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S54>/mean_filt_yaw_rate_abs'
   *  S-Function (ex_sfun_abs): '<S54>/yaw_rate_in_abs'
   */
  /* Embedded MATLAB Function 'build_Q_R_A_z/Q_A_adaptation_yaw/q_gain/q_gain_delta': '<S59>:1' */
  /*  Note: In order to eliminate QAC Level-4 warnings, the if-condition below is rewritten with multiple if-elseif expressions. */
  /*  calculate the difference between the mean filtered last yaw rate and  */
  /*  the actual yaw rate */
  if (CML_f_Abs( (real32_T)rtb_gier_yaw_rate_l) >= 1.0E-7F) {
    /* '<S59>:1:6' */
    if (CML_f_Abs( (real32_T)rtb_Divide_h) >= 1.0E-7F) {
      /* '<S59>:1:7' */
      /* '<S59>:1:8' */
      rtb_diff = rtb_gier_yaw_rate_l - rtb_Divide_h;
    } else {
      /* '<S59>:1:10' */
      rtb_diff = vdy_sye_B->sf_get_gain_bias.default_diff;
    }
  } else {
    /* '<S59>:1:13' */
    rtb_diff = vdy_sye_B->sf_get_gain_bias.default_diff;
  }

  /* Sum: '<S54>/Sum2' incorporates:
   *  Product: '<S54>/Product'
   *  S-Function (ex_sfun_abs): '<S54>/Diff_abs'
   */
  rtb_init_SSG = (CML_f_Abs( (real32_T)rtb_diff) *
                  vdy_sye_B->sf_get_gain_bias.gain) +
    vdy_sye_B->sf_get_gain_bias.bias;
  for (i = 0; i < 4; i++) {
    /* UnitDelay: '<S12>/P_delay_yaw' */
    rtb_vdy_sfunc_AP_o2[i] = vdy_sye_DWork->P_delay_yaw_DSTATE[(i)];
    rtb_R_out[i] = (rtb_R_out[i] * rtb_init_SSG) + vdy_sye_Q_add_p[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S112>/vdy_s-func_AP' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)
    vdy_sye_B->sf_make_A_matrix_i.A, (real32_T*)rtb_vdy_sfunc_AP_o2, rtb_KH_c,
    (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S12>/At' */
  vdy_sye_At(vdy_sye_B->sf_make_A_matrix_i.A, &vdy_sye_B->sf_At_d);

  /* S-Function (MatrixMultiplication): '<S112>/vdy_s-func_AP_At' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_KH_c,
    (real32_T*)vdy_sye_B->sf_At_d.y, rtb_vdy_sfunc_AP_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Sum: '<S12>/APA_Q' */
  for (i = 0; i < 4; i++) {
    rtb_P_pred_a[i] = rtb_R_out[i] + rtb_vdy_sfunc_AP_o2[i];
  }

  /* S-Function (MatrixMultiplication): '<S113>/vdy_s-func_HP' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_H,
    (real32_T*)rtb_P_pred_a, rtb_Knu, (uint8_T)2, (uint8_T)1, (uint8_T)2);

  /* Embedded MATLAB: '<S12>/Ht' */
  vdy_sye_Ht(rtb_H, &vdy_sye_B->sf_Ht_d);

  /* S-Function (MatrixMultiplication): '<S113>/vdy_s-func_HP_Ht' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_Knu,
    (real32_T*)vdy_sye_B->sf_Ht_d.y, &rtb_Add3, (uint8_T)2, (uint8_T)1, (uint8_T)
    1);

  /* Sum: '<S12>/HPH_R' */
  rtb_HPHt_R_l = rtb_R_out_l + rtb_Add3;

  /* Embedded MATLAB: '<S106>/Matrix_Inversion_1x1' */
  vdy_matrix_inversion_1x1(rtb_HPHt_R_l, &vdy_sye_B->sf_Matrix_Inversion_1x1);

  /* S-Function (MatrixMultiplication): '<S12>/vdy_s-func_P_pred_Ht' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_P_pred_a,
    (real32_T*)vdy_sye_B->sf_Ht_d.y, rtb_vdy_sfunc_P_pred_Ht_o2, (uint8_T)2,
    (uint8_T)2, (uint8_T)1);

  /* If: '<S106>/If' incorporates:
   *  ActionPort: '<S115>/Action Port'
   *  ActionPort: '<S116>/Action Port'
   *  SubSystem: '<S106>/calculate the gain'
   *  SubSystem: '<S106>/set gain to default value'
   */
  if (!vdy_sye_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* S-Function (MatrixMultiplication): '<S115>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)
      rtb_vdy_sfunc_P_pred_Ht_o2, (real32_T*)
      &vdy_sye_B->sf_Matrix_Inversion_1x1.HPHt_R_inv, rtb_K_l, (uint8_T)1,
      (uint8_T)2, (uint8_T)1);
  } else {
    /* Constant: '<S116>/Constant' */
    for (i = 0; i < 2; i++) {
      rtb_K_l[i] = vdy_sye_K_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S12>/vdy_s-func_KH' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_K_l,
    (real32_T*)rtb_H, rtb_KH_c, (uint8_T)1, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S12>/1_KH' incorporates:
   *  Constant: '<S12>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH_c[i] = vdy_sye_I_matrix_p[(i)] - rtb_KH_c[i];
  }

  /* Embedded MATLAB: '<S12>/Reset_P_pred' */
  /* Embedded MATLAB Function 'swa_yaw_EKF/Reset_P_pred': '<S108>:1' */
  if (vdy_sye_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* '<S108>:1:4' */
    /* '<S108>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = vdy_sye_P_init_p[(i)];
    }
  } else {
    /* '<S108>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = rtb_P_pred_a[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S12>/vdy_s-func_P_post' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_KH_c,
    (real32_T*)rtb_P_pred_out, rtb_vdy_sfunc_P_post_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Embedded MATLAB: '<Root>/diag_yaw_variance' */
  /* Embedded MATLAB Function 'diag_yaw_variance': '<S8>:1' */
  /*  tune output variances */
  if (rtb_R_onoff >= 1) {
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    for (i = 0; i < 2; i++) {
      rtb_hx_g[i] = rtb_vdy_sfunc_P_post_o2[3 * i];
    }

    /*  if no swa offset is available add 20 perc to all variances */
    if (rtb_R_onoff == 2) {
      /* '<S8>:1:6' */
      /* '<S8>:1:7' */
      for (i = 0; i < 2; i++) {
        rtb_hx_g[i] = rtb_vdy_sfunc_P_post_o2[3 * i] * 1.2F;
      }
    }

    if (rtb_veh_velo_kq <= vdy_sye_P_correct_p[1]) {
      /* '<S8>:1:10' */
      /* '<S8>:1:11' */
      for (i = 0; i < 2; i++) {
        rtb_hx_g[i] = (((rtb_hx_g[i] - vdy_sye_P_correct_p[2]) /
                        vdy_sye_P_correct_p[1]) * rtb_veh_velo_kq) +
          vdy_sye_P_correct_p[2];
      }
    }

    /* '<S8>:1:13' */
    for (i = 0; i < 2; i++) {
      rtb_hx_g[i] = rtb_hx_g[i] + vdy_sye_P_correct_p[3];
    }
  } else {
    /*  if input values are not valid set output variance to high value */
    /* '<S8>:1:16' */
    for (i = 0; i < 2; i++) {
      rtb_hx_g[i] = vdy_sye_P_correct_p[0];
    }
  }

  /* Embedded MATLAB: '<S12>/Reset_x_pred' */
  /* Embedded MATLAB Function 'swa_yaw_EKF/Reset_x_pred': '<S109>:1' */
  if (vdy_sye_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* '<S109>:1:4' */
    /* '<S109>:1:6' */
    rtb_x_pred_out[0] = 0.0F;
    rtb_x_pred_out[1] = rtb_xpost_a[1];
  } else {
    /* '<S109>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_x_pred_out[i] = rtb_vdy_sfunc_x_pred_o2[i];
    }
  }

  /* BusSelector: '<S12>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 2; i++) {
    rtb_rat[i] = (*vdy_sye_U_VDYInputData).Parameter.SteeringRatio.swa.rat[(i)];
  }

  /* Embedded MATLAB: '<S12>/make_z' incorporates:
   *  BusSelector: '<Root>/Bus Selector1'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S12>/veh_velo_abs'
   */
  /* Embedded MATLAB Function 'swa_yaw_EKF/make_z': '<S111>:1' */
  /*  calculate the swa yaw rate with the parameters and the offset comp swa */
  /*  if the learned understeer gradient should be used */
  if (((uint32_T)VDY_USE_LEARNED_UNDERSTEER_GRAD) == 1U) {
    /* '<S111>:1:6' */
    /*  if the vehicle velocity is not zero */
    if (CML_f_Abs( (real32_T)rtb_veh_velo_kq) >= 0.0001F) {
      /* '<S111>:1:8' */
      /* '<S111>:1:9' */
      /*  the meas input swa yaw rate */
      /* '<S111>:1:11' */
      rtb_init_SSG = (((rtb_veh_velo_kq * rtb_veh_velo_kq) *
                       rtb_SlfStGradDisc_out) + (*vdy_sye_U_VDYInputData).
                      Parameter.WheelBase) * rtb_rat[1];
      if ((rtb_init_SSG <= 0.0001F) && (rtb_init_SSG >= -0.0001F)) {
        /* '<S111>:1:12' */
        /* '<S111>:1:13' */
        rtb_init_SSG = 0.0F;
      } else {
        /* '<S111>:1:15' */
        rtb_init_SSG = (rtb_z_out_c * rtb_veh_velo_kq) / rtb_init_SSG;
      }
    } else {
      /* '<S111>:1:18' */
      rtb_init_SSG = 0.0F;
    }
  } else {
    /*  if the understeer gradient from the parameter input struct should be used */
    /*  if the vehicle velocity is not zero */
    if (CML_f_Abs( (real32_T)rtb_veh_velo_kq) >= 0.0001F) {
      /* '<S111>:1:23' */
      /* '<S111>:1:24' */
      /*  the meas input swa yaw rate */
      /* '<S111>:1:26' */
      rtb_init_SSG = (((rtb_veh_velo_kq * rtb_veh_velo_kq) *
                       (*vdy_sye_U_VDYInputData).Parameter.SelfSteerGrad) +
                      (*vdy_sye_U_VDYInputData).Parameter.WheelBase) * rtb_rat[1];
      if ((rtb_init_SSG <= 0.0001F) && (rtb_init_SSG >= -0.0001F)) {
        /* '<S111>:1:27' */
        /* '<S111>:1:28' */
        rtb_init_SSG = 0.0F;
      } else {
        /* '<S111>:1:30' */
        rtb_init_SSG = (rtb_z_out_c * rtb_veh_velo_kq) / rtb_init_SSG;
      }
    } else {
      /* '<S111>:1:33' */
      rtb_init_SSG = 0.0F;
    }
  }

  /* Sum: '<S12>/z_Hx' */
  rtb_Add3 = rtb_init_SSG - rtb_Divide;

  /* S-Function (MatrixMultiplication): '<S12>/vdy_s-func_K_nu' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_K_l,
    (real32_T*)&rtb_Add3, rtb_Knu, (uint8_T)1, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S12>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_x_pred_out[i] = rtb_x_pred_out[i] + rtb_Knu[i];
  }

  /* Embedded MATLAB: '<Root>/correct_yaw_rate' */
  /* Embedded MATLAB Function 'correct_yaw_rate': '<S6>:1' */
  /*  correct output yaw rate */
  if (rtb_R_onoff >= 1) {
    /* '<S6>:1:3' */
    /* '<S6>:1:4' */
    rtb_y_o = rtb_x_pred_out[1];
  } else {
    /* '<S6>:1:6' */
    rtb_y_o = 0.0F;
  }

  /* Embedded MATLAB: '<S43>/get_init_control_mode' incorporates:
   *  Inport: '<Root>/vdy_ctrl_op_mode'
   */
  /* Embedded MATLAB Function 'build_Q_R_A_z/CaculateAddVar/get_init_control_mode': '<S49>:1' */
  /*  if the vdy_ctrl mode is init set the output too true */
  if (vdy_sye_U_vdy_ctrl_op_mode == ((uint16_T)VDY_CTRL_STATE_INIT)) {
    /* '<S49>:1:3' */
    /* '<S49>:1:4' */
    rtb_y_c = TRUE;
  } else {
    /* '<S49>:1:6' */
    rtb_y_c = FALSE;
  }

  /* UnitDelay: '<S43>/last_not_zero_min' */
  rtb_init_SSG = vdy_sye_DWork->last_not_zero_min_DSTATE;

  /* Sum: '<S43>/Add' incorporates:
   *  UnitDelay: '<S43>/last_steering_angle'
   */
  rtb_Add_g = rtb_z_out_c - vdy_sye_DWork->last_steering_angle_DSTATE;

  /* Embedded MATLAB: '<S43>/check_for_zero_values' incorporates:
   *  S-Function (ex_sfun_abs): '<S43>/diff_abs'
   *  Sum: '<S43>/Add'
   *  UnitDelay: '<S43>/last_steering_angle'
   */
  /* Embedded MATLAB Function 'build_Q_R_A_z/CaculateAddVar/check_for_zero_values': '<S48>:1' */
  /*  check if the input DiffAbs steering wheel angle is not zero */
  /*  if it is zero use the last min Value as output */
  if (!(CML_f_Abs( (real32_T)rtb_Add_g) <= 0.0001F)) {
    /* '<S48>:1:7' */
    rtb_init_SSG = CML_f_Abs( (real32_T)rtb_Add_g);
  } else {
    /* '<S48>:1:4' */
    /* '<S48>:1:5' */
  }

  /* Switch: '<S50>/Reset' incorporates:
   *  Constant: '<S50>/Initial Condition'
   *  MinMax: '<S47>/MinMax'
   *  UnitDelay: '<S50>/FixPt Unit Delay1'
   */
  if (rtb_y_c) {
    rtb_Reset_l = 10.0F;
  } else {
    rtb_Reset_l = (rtb_init_SSG <= vdy_sye_DWork->FixPtUnitDelay1_DSTATE_l) ?
      rtb_init_SSG : vdy_sye_DWork->FixPtUnitDelay1_DSTATE_l;
  }

  /* Embedded MATLAB: '<S43>/AddVariance' incorporates:
   *  BusSelector: '<S43>/Bus Selector'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'build_Q_R_A_z/CaculateAddVar/AddVariance': '<S46>:1' */
  /*  calculate the steering wheel curve for the resolution of the swa sensor */
  /*  if the learned understeer gradient should be used */
  if (((uint32_T)VDY_USE_LEARNED_UNDERSTEER_GRAD) == 1U) {
    /* '<S46>:1:4' */
    /* '<S46>:1:5' */
    /*  Estimation of the variance to 3*SteeringAngleResolution */
    /* '<S46>:1:7' */
    rtb_init_SSG = ((((*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo *
                      (*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo) *
                     rtb_SlfStGradDisc_out) + (*vdy_sye_U_VDYInputData).
                    Parameter.WheelBase) * (*vdy_sye_U_VDYInputData).
      Parameter.SteeringRatio.swa.rat[1];
    if ((rtb_init_SSG >= 0.0001F) || (rtb_init_SSG <= -0.0001F)) {
      /* '<S46>:1:8' */
      /* '<S46>:1:9' */
      rtb_addVariance = (rtb_Reset_l / rtb_init_SSG) * 3.0F;
    } else {
      /* '<S46>:1:11' */
      rtb_addVariance = 0.002F;
    }
  } else {
    /*  if the understeer gradient from the parameter input struct should be used */
    /* '<S46>:1:15' */
    /*  Estimation of the variance to 3*SteeringAngleResolution */
    /* '<S46>:1:17' */
    rtb_init_SSG = ((((*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo *
                      (*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo) *
                     (*vdy_sye_U_VDYInputData).Parameter.SelfSteerGrad) +
                    (*vdy_sye_U_VDYInputData).Parameter.WheelBase) *
      (*vdy_sye_U_VDYInputData).Parameter.SteeringRatio.swa.rat[1];
    if ((rtb_init_SSG >= 0.0001F) || (rtb_init_SSG <= -0.0001F)) {
      /* '<S46>:1:18' */
      /* '<S46>:1:19' */
      rtb_addVariance = (rtb_Reset_l / rtb_init_SSG) * 3.0F;
    } else {
      /* '<S46>:1:21' */
      rtb_addVariance = 0.002F;
    }
  }

  /* '<S46>:1:24' */
  rtb_addVariance *= rtb_addVariance;

  /* BusSelector: '<S11>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 2; i++) {
    rtb_rat[i] = (*vdy_sye_U_VDYInputData).Parameter.SteeringRatio.swa.rat[(i)];
  }

  /* BusSelector: '<S2>/Bus Selector3' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_CycleTime_k = (*vdy_sye_U_VDYInputData).Frame.CycleTime;

  /* Outputs for atomic SubSystem: '<S2>/Time2Sec' */
  vdy_sye_Time2Sec(rtb_CycleTime_k, &vdy_sye_B->Time2Sec_f);

  /* end of Outputs for SubSystem: '<S2>/Time2Sec' */

  /* Embedded MATLAB: '<S13>/make_A_matrix' */
  vdy_sye_make_A_matrix(vdy_sye_B->Time2Sec_f.Time2Sec,
                        &vdy_sye_B->sf_make_A_matrix_d);

  /* UnitDelay: '<S11>/x_delay_curve' */
  for (i = 0; i < 2; i++) {
    rtb_xpost_m[i] = vdy_sye_DWork->x_delay_curve_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S11>/vdy_s-func_x_pred' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)
    vdy_sye_B->sf_make_A_matrix_d.A, (real32_T*)rtb_xpost_m,
    rtb_vdy_sfunc_x_pred_o2_b, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S11>/hx' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  /* Embedded MATLAB Function 'swa_curve_EKF/hx': '<S99>:1' */
  /*  calculate transformation from state space to measurement space */
  /*  if the learned understeer gradient should be used */
  if (((uint32_T)VDY_USE_LEARNED_UNDERSTEER_GRAD) == 1U) {
    /* '<S99>:1:4' */
    /* '<S99>:1:5' */
    rtb_init_SSG = rtb_veh_velo_kq * rtb_veh_velo_kq;

    /*  non linear equation */
    /* '<S99>:1:7' */
    rtb_hx_d = ((rtb_SlfStGradDisc_out * rtb_init_SSG) +
                (*vdy_sye_U_VDYInputData).Parameter.WheelBase) * (rtb_rat[1] *
      rtb_vdy_sfunc_x_pred_o2_b[0]);

    /*  linearised transformation matrix H */
    /* '<S99>:1:9' */
    rtb_H_p[0] = ((rtb_SlfStGradDisc_out * rtb_init_SSG) +
                  (*vdy_sye_U_VDYInputData).Parameter.WheelBase) * rtb_rat[1];
    rtb_H_p[1] = 0.0F;
  } else {
    /*  if the understeer gradient from the parameter input struct should be used */
    /* '<S99>:1:12' */
    rtb_init_SSG = rtb_veh_velo_kq * rtb_veh_velo_kq;

    /*  non linear equation */
    /* '<S99>:1:14' */
    rtb_hx_d = (((*vdy_sye_U_VDYInputData).Parameter.SelfSteerGrad *
                 rtb_init_SSG) + (*vdy_sye_U_VDYInputData).Parameter.WheelBase) *
      (rtb_rat[1] * rtb_vdy_sfunc_x_pred_o2_b[0]);

    /*  linearised transformation matrix H */
    /* '<S99>:1:16' */
    rtb_H_p[0] = (((*vdy_sye_U_VDYInputData).Parameter.SelfSteerGrad *
                   rtb_init_SSG) + (*vdy_sye_U_VDYInputData).Parameter.WheelBase)
      * rtb_rat[1];
    rtb_H_p[1] = 0.0F;
  }

  /* BusSelector: '<S2>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo_h = (*vdy_sye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /* Embedded MATLAB: '<S19>/sigma_velocity_gain_controll' incorporates:
   *  Constant: '<S19>/sigma_model'
   *  Constant: '<S19>/sigma_velo_gain'
   */
  /* Embedded MATLAB Function 'Q_A_addpation_curve/Q/gain_sigmas_over_velocity/sigma_velocity_gain_controll': '<S21>:1' */
  /*  if gain controll over velocity is selected */
  if (vdy_sye_Q_di_sigmas_velo_gain_p[0] == 1.0F) {
    /* '<S21>:1:3' */
    /*     if velocity is  below the max gain controled velocity */
    if (rtb_veh_velo_h <= vdy_sye_Q_di_sigmas_velo_gain_p[3]) {
      /* '<S21>:1:5' */
      /*  calculate the new sigmas controled by the velocity */
      /* '<S21>:1:7' */
      /* '<S21>:1:8' */
      rtb_init_SSG = ((((vdy_sye_Q_di_sigmas_velo_gain_p[1] -
                         vdy_sye_Q_di_sigmas_velo_gain_p[2]) /
                        (vdy_sye_Q_di_sigmas_velo_gain_p[3] *
                         vdy_sye_Q_di_sigmas_velo_gain_p[3])) * (rtb_veh_velo_h
        - vdy_sye_Q_di_sigmas_velo_gain_p[3])) * (rtb_veh_velo_h -
        vdy_sye_Q_di_sigmas_velo_gain_p[3])) + vdy_sye_Q_di_sigmas_velo_gain_p[2];

      /* '<S21>:1:9' */
      rtb_rat[0] = rtb_init_SSG;
      rtb_rat[1] = rtb_init_SSG;
    } else {
      /*  constant sigma if above the threshold velocity */
      /* '<S21>:1:12' */
      rtb_rat[0] = vdy_sye_Q_di_sigmas_velo_gain_p[2];
      rtb_rat[1] = vdy_sye_Q_di_sigmas_velo_gain_p[2];
    }
  } else {
    /*  not velocity gain controlled */
    /* '<S21>:1:16' */
    for (i = 0; i < 2; i++) {
      rtb_rat[i] = vdy_sye_Q_di_sigmas_p[(i)];
    }
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S14>/Constant'
   *  Product: '<S14>/Divide'
   *  Product: '<S14>/Product1'
   */
  rtb_z_out_a[0] = (vdy_sye_B->Time2Sec_f.Time2Sec *
                    vdy_sye_B->Time2Sec_f.Time2Sec) / 2.0F;
  rtb_z_out_a[1] = vdy_sye_B->Time2Sec_f.Time2Sec;

  /* Embedded MATLAB: '<S14>/makeQ' */
  /* Embedded MATLAB Function 'Q_A_addpation_curve/Q/makeQ': '<S20>:1' */
  /*  calculate the model covariance matrix Q */
  /* '<S20>:1:3' */

  /* Embedded MATLAB: '<S2>/divide' incorporates:
   *  BusSelector: '<S2>/Bus Selector2'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S2>/Veh_velo_abs'
   */
  /* Embedded MATLAB Function 'Q_A_addpation_curve/divide': '<S16>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (CML_f_Abs( (real32_T)rtb_veh_velo_h) >= 0.0001F) {
    /* '<S16>:1:5' */
    /* '<S16>:1:6' */
    rtb_quot = (*vdy_sye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate /
      rtb_veh_velo_h;
  } else {
    /* '<S16>:1:8' */
    rtb_quot = 0.0F;
  }

  /* UnitDelay: '<S23>/T2' */
  rtb_init_SSG = vdy_sye_DWork->T2_DSTATE_e;

  /* UnitDelay: '<S23>/T1' */
  rtb_Divide = vdy_sye_DWork->T1_DSTATE_h;

  /* UnitDelay: '<S23>/T0' */
  rtb_T0_k = vdy_sye_DWork->T0_DSTATE_l;

  /* Product: '<S23>/Divide' incorporates:
   *  Constant: '<S23>/filter_length'
   *  Sum: '<S23>/Add'
   *  UnitDelay: '<S23>/T3'
   */
  rtb_Divide_ln = (((vdy_sye_DWork->T3_DSTATE_f + vdy_sye_DWork->T2_DSTATE_e) +
                    vdy_sye_DWork->T1_DSTATE_h) + vdy_sye_DWork->T0_DSTATE_l) *
    0.25F;

  /* Embedded MATLAB: '<S17>/get_gain_bias' */
  vdy_sye_get_gain_bias((&(vdy_sye_Q_di_gain_p[0])),
                        &vdy_sye_B->sf_get_gain_bias_k);

  /* Embedded MATLAB: '<S17>/q_gain_delta' incorporates:
   *  S-Function (ex_sfun_abs): '<S17>/mean_filt_yaw_rate_abs'
   *  S-Function (ex_sfun_abs): '<S17>/yaw_rate_in_abs'
   */
  /* Embedded MATLAB Function 'Q_A_addpation_curve/q_gain/q_gain_delta': '<S24>:1' */
  /*  Note: In order to eliminate QAC Level-4 warnings, the if-condition below is rewritten with multiple if-elseif expressions. */
  /*  calculate the difference between the mean filtered last yaw rate and  */
  /*  the actual yaw rate */
  if (CML_f_Abs( (real32_T)rtb_quot) >= 1.0E-7F) {
    /* '<S24>:1:6' */
    if (CML_f_Abs( (real32_T)rtb_Divide_ln) >= 1.0E-7F) {
      /* '<S24>:1:7' */
      /* '<S24>:1:8' */
      rtb_diff_c = rtb_quot - rtb_Divide_ln;
    } else {
      /* '<S24>:1:10' */
      rtb_diff_c = vdy_sye_B->sf_get_gain_bias_k.default_diff;
    }
  } else {
    /* '<S24>:1:13' */
    rtb_diff_c = vdy_sye_B->sf_get_gain_bias_k.default_diff;
  }

  /* Sum: '<S17>/Sum2' incorporates:
   *  Product: '<S17>/Product'
   *  S-Function (ex_sfun_abs): '<S17>/Diff_abs'
   */
  rtb_Q_gain_i = (CML_f_Abs( (real32_T)rtb_diff_c) *
                  vdy_sye_B->sf_get_gain_bias_k.gain) +
    vdy_sye_B->sf_get_gain_bias_k.bias;

  /* Sum: '<S14>/Sum' incorporates:
   *  Constant: '<S14>/additional'
   *  Product: '<S14>/Product'
   */
  for (i = 0; i < 2; i++) {
    rtb_z_out_a_0[i] = rtb_z_out_a[i] * rtb_rat[i];
    rtb_rat_0[i] = rtb_rat[i] * rtb_z_out_a[i];
  }

  for (i = 0; i < 2; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 2;
         rtb_DataTypeConversion2++) {
      rtb_rat_1[rtb_DataTypeConversion2 + (i << 1)] =
        rtb_z_out_a_0[rtb_DataTypeConversion2] * rtb_rat_0[i];
    }
  }

  for (i = 0; i < 2; i++) {
    for (rtb_DataTypeConversion2 = 0; rtb_DataTypeConversion2 < 2;
         rtb_DataTypeConversion2++) {
      rtb_R_out[rtb_DataTypeConversion2 + (i << 1)] = (rtb_rat_1[(i << 1) +
        rtb_DataTypeConversion2] * rtb_Q_gain_i) + vdy_sye_Q_di_add_p[(i << 1) +
        rtb_DataTypeConversion2];
    }
  }

  /* UnitDelay: '<S11>/P_delay_curve' */
  for (i = 0; i < 4; i++) {
    rtb_KH_c[i] = vdy_sye_DWork->P_delay_curve_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S100>/vdy_s-func_AP' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)
    vdy_sye_B->sf_make_A_matrix_d.A, (real32_T*)rtb_KH_c, rtb_vdy_sfunc_AP_o2,
    (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S11>/At' */
  vdy_sye_At(vdy_sye_B->sf_make_A_matrix_d.A, &vdy_sye_B->sf_At_dl);

  /* S-Function (MatrixMultiplication): '<S100>/vdy_s-func_AP_At' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_AP_o2, (real32_T*)vdy_sye_B->sf_At_dl.y, rtb_KH_c, (uint8_T)2,
    (uint8_T)2, (uint8_T)2);

  /* Sum: '<S11>/APA_Q' */
  for (i = 0; i < 4; i++) {
    rtb_P_pred_d[i] = rtb_R_out[i] + rtb_KH_c[i];
  }

  /* S-Function (MatrixMultiplication): '<S101>/vdy_s-func_HP' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_H_p,
    (real32_T*)rtb_P_pred_d, rtb_Knu, (uint8_T)2, (uint8_T)1, (uint8_T)2);

  /* Embedded MATLAB: '<S11>/Ht' */
  vdy_sye_Ht(rtb_H_p, &vdy_sye_B->sf_Ht_k);

  /* S-Function (MatrixMultiplication): '<S101>/vdy_s-func_HPHt' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_Knu,
    (real32_T*)vdy_sye_B->sf_Ht_k.y, &rtb_Add3, (uint8_T)2, (uint8_T)1, (uint8_T)
    1);

  /* Sum: '<S11>/HPH_R' */
  rtb_HPHt_R_n = rtb_R_out_l + rtb_Add3;

  /* Embedded MATLAB: '<S95>/Matrix_Inversion_1x1' */
  vdy_matrix_inversion_1x1(rtb_HPHt_R_n, &vdy_sye_B->sf_Matrix_Inversion_1x1_a);

  /* S-Function (MatrixMultiplication): '<S11>/vdy_s-func_P_pred_Ht' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_P_pred_d,
    (real32_T*)vdy_sye_B->sf_Ht_k.y, rtb_vdy_sfunc_P_pred_Ht_o2_n, (uint8_T)2,
    (uint8_T)2, (uint8_T)1);

  /* If: '<S95>/If' incorporates:
   *  ActionPort: '<S103>/Action Port'
   *  ActionPort: '<S104>/Action Port'
   *  SubSystem: '<S95>/calculate the gain'
   *  SubSystem: '<S95>/set gain to default value'
   */
  if (!vdy_sye_B->sf_Matrix_Inversion_1x1_a.det_flag) {
    /* S-Function (MatrixMultiplication): '<S103>/S-Function5' */
    rtb_SFunction5_o1 = vdy_matrix_multiplication( (real32_T*)
      rtb_vdy_sfunc_P_pred_Ht_o2_n, (real32_T*)
      &vdy_sye_B->sf_Matrix_Inversion_1x1_a.HPHt_R_inv, rtb_K_e, (uint8_T)1,
      (uint8_T)2, (uint8_T)1);
  } else {
    /* Constant: '<S104>/Constant' */
    for (i = 0; i < 2; i++) {
      rtb_K_e[i] = vdy_sye_K_di_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S11>/vdy_s-func_KH' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_K_e,
    (real32_T*)rtb_H_p, rtb_KH_c, (uint8_T)1, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S11>/1_KH' incorporates:
   *  Constant: '<S11>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH_c[i] = vdy_sye_I_di_matrix_p[(i)] - rtb_KH_c[i];
  }

  /* Embedded MATLAB: '<S11>/Reset_P_pred' */
  /* Embedded MATLAB Function 'swa_curve_EKF/Reset_P_pred': '<S97>:1' */
  if (vdy_sye_B->sf_Matrix_Inversion_1x1_a.det_flag) {
    /* '<S97>:1:4' */
    /* '<S97>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out_n[i] = vdy_sye_P_di_init_p[(i)];
    }
  } else {
    /* '<S97>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out_n[i] = rtb_P_pred_d[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S11>/vdy_s-func_P_post' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_KH_c,
    (real32_T*)rtb_P_pred_out_n, rtb_P_post_d, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Embedded MATLAB: '<Root>/diag_curve_variance' */
  /* Embedded MATLAB Function 'diag_curve_variance': '<S7>:1' */
  /*  tune output variances */
  if (rtb_R_onoff >= 1) {
    /* '<S7>:1:3' */
    /* '<S7>:1:4' */
    for (i = 0; i < 2; i++) {
      rtb_rat[i] = rtb_P_post_d[3 * i];
    }

    /*  if swa offset is not available add 20 perc to all variances */
    if (rtb_R_onoff == 2) {
      /* '<S7>:1:6' */
      /* '<S7>:1:7' */
      for (i = 0; i < 2; i++) {
        rtb_rat[i] = rtb_P_post_d[3 * i] * 1.2F;
      }
    }
  } else {
    /*  if input values are not valid set output variance to high value */
    /* '<S7>:1:11' */
    for (i = 0; i < 2; i++) {
      rtb_rat[i] = vdy_sye_P_correct_p[0];
    }
  }

  /* Sum: '<Root>/Add3' */
  rtb_Add3 = rtb_addVariance + rtb_rat[0];

  /* Embedded MATLAB: '<S11>/Reset_x_pred' */
  /* Embedded MATLAB Function 'swa_curve_EKF/Reset_x_pred': '<S98>:1' */
  if (vdy_sye_B->sf_Matrix_Inversion_1x1_a.det_flag) {
    /* '<S98>:1:4' */
    /* '<S98>:1:6' */
    for (i = 0; i < 2; i++) {
      rtb_z_out_a[i] = rtb_xpost_m[i];
    }
  } else {
    /* '<S98>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_z_out_a[i] = rtb_vdy_sfunc_x_pred_o2_b[i];
    }
  }

  /* Sum: '<S11>/z_Hx' */
  rtb_nu = rtb_z_out_c - rtb_hx_d;

  /* S-Function (MatrixMultiplication): '<S11>/vdy_s-func_K_nu' */
  rtb_DataTypeConversion = vdy_matrix_multiplication( (real32_T*)rtb_K_e,
    (real32_T*)&rtb_nu, rtb_Knu, (uint8_T)1, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S11>/x_Knu' */
  for (i = 0; i < 2; i++) {
    vdy_sye_DWork->x_delay_curve_DSTATE[(i)] = rtb_z_out_a[i] + rtb_Knu[i];
  }

  /* BusAssignment: '<Root>/Bus Assignment3' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  (*vdy_sye_Y_VDYInternalData_out) = (*vdy_sye_U_VDYInternalData_in);
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_understeer_grad_var =
    rtb_y_h[2];
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_understeer_grad_max =
    rtb_Reset;
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_understeer_grad_min =
    rtb_Reset_m;
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_understeer_grad = rtb_xpost[2];
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_understeer_grad_disc =
    rtb_SlfStGradDisc_out;
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_understeer_control = rtb_init;
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_yaw_rate_var = rtb_hx_g[1];
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_yaw_rate = rtb_y_o;
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_curve_var = rtb_Add3;
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_curve_grad_var = rtb_rat[1];
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_curve =
    vdy_sye_DWork->x_delay_curve_DSTATE[0];
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.stw_curve_grad =
    vdy_sye_DWork->x_delay_curve_DSTATE[1];
  (*vdy_sye_Y_VDYInternalData_out).vdy_sye_out.r_On_Off_control = rtb_R_onoff;

  /* Embedded MATLAB: '<S71>/Get_IO_State' incorporates:
   *  Constant: '<S62>/VDY_SIN_POS'
   *  Constant: '<S71>/VDY_IO_STATE_BITMASK'
   */
  /* Embedded MATLAB Function 'extract_understeer_grad/Get_IO_State3/GetIOState/Get_IO_State': '<S72>:1' */
  /*  set the value at pos in the state array */
  /* '<S72>:1:4' */
  c = ((uint32_T)VDY_NVM_POS_SSG);
  if (((uint32_T)VDY_NVM_POS_SSG) > 2147483647U) {
    c = 2147483647U;
  }

  rtb_DataTypeConversion2 = (int32_T)c;
  rtb_DataTypeConversion3 = rtb_DataTypeConversion2 - ((rtb_DataTypeConversion2 >>
    5) << 5);

  /* '<S72>:1:5' */
  /* '<S72>:1:6' */
  c = 0U;
  if (rtb_DataTypeConversion3 < 0) {
    rtb_DataTypeConversion2 = -rtb_DataTypeConversion3;
    if (rtb_DataTypeConversion2 > 255) {
      rtb_DataTypeConversion2 = 255;
    }

    rtb_init = (uint8_T)rtb_DataTypeConversion2;
    if (rtb_init < 32) {
      c = (3U >> ((uint32_T)rtb_init));
    }
  } else {
    rtb_DataTypeConversion2 = rtb_DataTypeConversion3;
    if (rtb_DataTypeConversion3 <= 0) {
      rtb_DataTypeConversion2 = 0;
    } else {
      if (rtb_DataTypeConversion3 > 255) {
        rtb_DataTypeConversion2 = 255;
      }
    }

    rtb_init = (uint8_T)rtb_DataTypeConversion2;
    if (rtb_init < 32) {
      c = (3U << ((uint32_T)rtb_init));
    }
  }

  /* '<S72>:1:7' */
  /* '<S72>:1:8' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  rtb_DataTypeConversion = (uint8_T)rtb_SlfStGradMax_out;

  /* DataTypeConversion: '<S9>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (uint8_T)rtb_SlfStGradMin_out;

  /* BusAssignment: '<S9>/Bus Assignment' incorporates:
   *  Inport: '<Root>/VDYNVData_in'
   */
  (*vdy_sye_Y_VDYNVData_out) = (*vdy_sye_U_VDYNVData_in);
  (*vdy_sye_Y_VDYNVData_out).Write.State = ((c ^ MAX_uint32_T)
    & (*vdy_sye_U_VDYNVData_in).Write.State) | (rtb_state <<
    rtb_DataTypeConversion3);
  (*vdy_sye_Y_VDYNVData_out).Write.SlfstGrad.SlfStGrad = rtb_SlfStGradNVM_out;
  (*vdy_sye_Y_VDYNVData_out).Write.SlfstGrad.SlfStGradMax =
    rtb_DataTypeConversion;
  (*vdy_sye_Y_VDYNVData_out).Write.SlfstGrad.SlfStGradMin =
    rtb_DataTypeConversion1;

  /* Switch: '<S70>/Reset' incorporates:
   *  Constant: '<S70>/Initial Condition'
   *  Update for UnitDelay: '<S70>/FixPt Unit Delay1'
   */
  if (rtb_R_onoff_n) {
    vdy_sye_DWork->FixPtUnitDelay1_DSTATE_g = 0.0F;
  } else {
    vdy_sye_DWork->FixPtUnitDelay1_DSTATE_g = rtb_add_trav_dist;
  }

  /* Update for UnitDelay: '<S10>/x_delay_eg' */
  for (i = 0; i < 3; i++) {
    vdy_sye_DWork->x_delay_eg_DSTATE[(i)] = rtb_xpost[i];
  }

  /* Update for UnitDelay: '<S10>/init_nvm_eg_delay' */
  vdy_sye_DWork->init_nvm_eg_delay_DSTATE = rtb_init_out;

  /* Update for UnitDelay: '<S37>/T3' */
  vdy_sye_DWork->T3_DSTATE = rtb_T2;

  /* Update for UnitDelay: '<S37>/T2' */
  vdy_sye_DWork->T2_DSTATE = rtb_T1;

  /* Update for UnitDelay: '<S37>/T1' */
  vdy_sye_DWork->T1_DSTATE = rtb_T0;

  /* Update for UnitDelay: '<S37>/T0' */
  vdy_sye_DWork->T0_DSTATE = rtb_T7;

  /* Update for UnitDelay: '<S37>/T7' */
  vdy_sye_DWork->T7_DSTATE = rtb_T6;

  /* Update for UnitDelay: '<S37>/T6' */
  vdy_sye_DWork->T6_DSTATE = rtb_T5;

  /* Update for UnitDelay: '<S37>/T5' */
  vdy_sye_DWork->T5_DSTATE = rtb_T4;

  /* Update for UnitDelay: '<S37>/T4' */
  vdy_sye_DWork->T4_DSTATE = rtb_sigma_EG;

  /* Update for UnitDelay: '<S10>/P_delay_eg' */
  for (i = 0; i < 9; i++) {
    vdy_sye_DWork->P_delay_eg_DSTATE[(i)] = rtb_P_post[i];
  }

  /* Update for UnitDelay: '<S75>/FixPt Unit Delay1' */
  vdy_sye_DWork->FixPtUnitDelay1_DSTATE = rtb_Reset;

  /* Update for UnitDelay: '<S76>/FixPt Unit Delay1' */
  vdy_sye_DWork->FixPtUnitDelay1_DSTATE_b = rtb_Reset_m;

  /* Update for UnitDelay: '<S9>/trav_dist_reset' */
  vdy_sye_DWork->trav_dist_reset_DSTATE = rtb_trav_dist_reset_f;

  /* Update for UnitDelay: '<S70>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S70>/FixPt Constant'
   */
  vdy_sye_DWork->FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S9>/last_SlfStGradDisc' */
  vdy_sye_DWork->last_SlfStGradDisc_DSTATE = rtb_SlfStGradDisc_out;

  /* Update for UnitDelay: '<S12>/x_delay_yaw' */
  for (i = 0; i < 2; i++) {
    vdy_sye_DWork->x_delay_yaw_DSTATE[(i)] = rtb_x_pred_out[i];
  }

  /* Update for UnitDelay: '<S58>/T3' */
  vdy_sye_DWork->T3_DSTATE_c = rtb_T2_e;

  /* Update for UnitDelay: '<S58>/T2' */
  vdy_sye_DWork->T2_DSTATE_f = rtb_T1_p;

  /* Update for UnitDelay: '<S58>/T1' */
  vdy_sye_DWork->T1_DSTATE_k = rtb_T0_a;

  /* Update for UnitDelay: '<S58>/T0' */
  vdy_sye_DWork->T0_DSTATE_f = rtb_x_pred_out[1];

  /* Update for UnitDelay: '<S43>/last_not_zero_min' */
  vdy_sye_DWork->last_not_zero_min_DSTATE = rtb_Reset_l;

  /* Update for UnitDelay: '<S43>/last_steering_angle' */
  vdy_sye_DWork->last_steering_angle_DSTATE = rtb_z_out_c;

  /* Update for UnitDelay: '<S50>/FixPt Unit Delay1' */
  vdy_sye_DWork->FixPtUnitDelay1_DSTATE_l = rtb_Reset_l;

  /* Update for UnitDelay: '<S23>/T3' */
  vdy_sye_DWork->T3_DSTATE_f = rtb_init_SSG;

  /* Update for UnitDelay: '<S23>/T2' */
  vdy_sye_DWork->T2_DSTATE_e = rtb_Divide;

  /* Update for UnitDelay: '<S23>/T1' */
  vdy_sye_DWork->T1_DSTATE_h = rtb_T0_k;

  /* Update for UnitDelay: '<S23>/T0' */
  vdy_sye_DWork->T0_DSTATE_l = vdy_sye_DWork->x_delay_curve_DSTATE[0];
  for (i = 0; i < 4; i++) {
    /* Update for UnitDelay: '<S12>/P_delay_yaw' */
    vdy_sye_DWork->P_delay_yaw_DSTATE[(i)] = rtb_vdy_sfunc_P_post_o2[i];

    /* Update for UnitDelay: '<S11>/P_delay_curve' */
    vdy_sye_DWork->P_delay_curve_DSTATE[(i)] = rtb_P_post_d[i];
  }
}

/* Model initialize function */
void vdy_sye_initialize(boolean_T firstTime, BlockIO_vdy_sye *vdy_sye_B,
  D_Work_vdy_sye *vdy_sye_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_sye_B), 0,
                      sizeof(BlockIO_vdy_sye));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_sye_DWork, 0,
                      sizeof(D_Work_vdy_sye));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S10>/x_delay_eg' */
    for (i = 0; i < 3; i++) {
      vdy_sye_DWork->x_delay_eg_DSTATE[(i)] = vdy_sye_x_SSG_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S10>/P_delay_eg' */
    for (i = 0; i < 9; i++) {
      vdy_sye_DWork->P_delay_eg_DSTATE[(i)] = vdy_sye_P_SSG_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S76>/FixPt Unit Delay1' */
    vdy_sye_DWork->FixPtUnitDelay1_DSTATE_b = 0.008F;

    /* InitializeConditions for UnitDelay: '<S70>/FixPt Unit Delay2' */
    vdy_sye_DWork->FixPtUnitDelay2_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S12>/x_delay_yaw' */
    for (i = 0; i < 2; i++) {
      vdy_sye_DWork->x_delay_yaw_DSTATE[(i)] = vdy_sye_x_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S12>/P_delay_yaw' */
    for (i = 0; i < 4; i++) {
      vdy_sye_DWork->P_delay_yaw_DSTATE[(i)] = vdy_sye_P_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S43>/last_not_zero_min' */
    vdy_sye_DWork->last_not_zero_min_DSTATE = 10.0F;

    /* InitializeConditions for UnitDelay: '<S50>/FixPt Unit Delay1' */
    vdy_sye_DWork->FixPtUnitDelay1_DSTATE_l = 10.0F;

    /* InitializeConditions for UnitDelay: '<S11>/x_delay_curve' */
    for (i = 0; i < 2; i++) {
      vdy_sye_DWork->x_delay_curve_DSTATE[(i)] = vdy_sye_x_di_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S11>/P_delay_curve' */
    for (i = 0; i < 4; i++) {
      vdy_sye_DWork->P_delay_curve_DSTATE[(i)] = vdy_sye_P_di_init_p[(i)];
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
