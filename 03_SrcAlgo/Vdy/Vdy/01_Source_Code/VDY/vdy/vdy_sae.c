/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_sae.c
   Real-Time Workshop code generated for Simulink model vdy_sae.
   Model version                        : 1.3032
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:06:11 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:06:12 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy slip angle estimation
   VERSION:                             : $Revision: 1.6 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_sae.h"
#include "vdy_sae_private.h"

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

/* Model step function */
void vdy_sae_step(BlockIO_vdy_sae *vdy_sae_B, D_Work_vdy_sae *vdy_sae_DWork,
                  VDYInputData_t *vdy_sae_U_VDYInputData, VDYInternalData_t
                  *vdy_sae_U_VDYInternalData_in, VDYInternalData_t
                  *vdy_sae_Y_VDYInternalData_out)
{
  /* local block i/o variables */
  real32_T rtb_xpost[2];
  real32_T rtb_x_pred[2];
  real32_T rtb_veh_velo;
  real32_T rtb_abs_velocity;
  real32_T rtb_Product;
  real32_T rtb_Divide_f;
  real32_T rtb_diff_merge;
  real32_T rtb_P_pred[4];
  real32_T rtb_HPHt_R;
  real32_T rtb_vdy_sfunc_P_pred_Ht_o2[2];
  real32_T rtb_K[2];
  real32_T rtb_P_post[4];
  real32_T rtb_H[2];
  real32_T rtb_P_pred_out[4];
  real32_T rtb_y_m[2];
  real32_T rtb_y_d[4];
  real32_T rtb_A[4];
  real32_T rtb_vdy_sfunc_AP_At_o2[4];
  real32_T rtb_Knu[2];
  real32_T rtb_nu;
  real32_T rtb_KH[4];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_vdy_sfunc_K_nu_o1;
  real32_T rtb_Time2Sec;
  real32_T rtb_yaw_rate_delay_3;
  real32_T rtb_yaw_rate_delay_2;
  real32_T rtb_yaw_rate_delay_1;
  real32_T rtb_bias;
  real32_T rtb_R_out;
  VDYInternalData_t rtb_store_raw_slip_angle;
  real32_T rtb_hx;
  real32_T rtb_TmpSignalConversionAtSFunct[2];
  real32_T rtb_Q[4];
  int32_T i;
  real32_T rtb_TmpSignalConversionAtSFun_0[2];
  real32_T tmp[2];
  int32_T i_0;

  /* Embedded MATLAB: '<S5>/adapt_R_matrix' */
  /* Embedded MATLAB Function 'R/adapt_R_matrix': '<S23>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S23>:1:5' */
  rtb_R_out = vdy_sae_R_p;

  /* Outputs for atomic SubSystem: '<Root>/Time2Sec' */

  /* Product: '<S6>/Time2Sec' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_Time2Sec = ((real32_T)(*vdy_sae_U_VDYInputData).Frame.CycleTime) / 1000.0F;

  /* end of Outputs for SubSystem: '<Root>/Time2Sec' */

  /* Embedded MATLAB: '<S1>/make_A_matrix' */
  /* Embedded MATLAB Function 'A/make_A_matrix': '<S10>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S10>:1:5' */
  rtb_A[0] = 1.0F;
  rtb_A[2] = rtb_Time2Sec;
  for (i = 0; i < 2; i++) {
    rtb_A[1 + (i << 1)] = (real32_T)i;
  }

  /* UnitDelay: '<S2>/x_delay' */
  for (i = 0; i < 2; i++) {
    rtb_xpost[i] = vdy_sae_DWork->x_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A, (real32_T*)
    rtb_xpost, rtb_x_pred, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S2>/hx' */
  /* Embedded MATLAB Function 'KF/hx': '<S16>:1' */
  /*  transformation from state space to measurement space */
  /* '<S16>:1:3' */
  rtb_hx = rtb_x_pred[0];

  /* '<S16>:1:5' */

  /* SignalConversion: '<S22>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Divide'
   *  Product: '<S4>/Product1'
   */
  rtb_TmpSignalConversionAtSFunct[0] = (rtb_Time2Sec * rtb_Time2Sec) / 2.0F;
  rtb_TmpSignalConversionAtSFunct[1] = rtb_Time2Sec;

  /* Embedded MATLAB: '<S4>/makeQ' incorporates:
   *  Constant: '<S4>/sigma_model'
   */
  /* Embedded MATLAB Function 'Q/makeQ': '<S22>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S22>:1:5' */
  for (i = 0; i < 2; i++) {
    rtb_H[i] = (-1.0F * ((real32_T)i)) + 1.0F;
    rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFunct[i] *
      vdy_sae_Q_sigmas_p[(i)];
    tmp[i] = vdy_sae_Q_sigmas_p[(i)] * rtb_TmpSignalConversionAtSFunct[i];
  }

  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_Q[i_0 + (i << 1)] = rtb_TmpSignalConversionAtSFun_0[i_0] * tmp[i];
    }
  }

  /* BusSelector: '<S8>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo = (*vdy_sae_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /* Product: '<S8>/Product1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_nu = (*vdy_sae_U_VDYInputData).Parameter.WheelBase *
    (*vdy_sae_U_VDYInputData).Parameter.AxisLoadDistr;

  /* Sum: '<S8>/Add1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_Time2Sec = (*vdy_sae_U_VDYInputData).Parameter.WheelBase - rtb_nu;

  /* S-Function (ex_sfun_abs): '<S8>/abs_velocity' */
  rtb_abs_velocity = CML_f_Abs( (real32_T)rtb_veh_velo);

  /* Embedded MATLAB: '<S8>/divide_velocity1' */
  /* Embedded MATLAB Function 'make_z_vector/divide_velocity1': '<S25>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (rtb_abs_velocity <= 0.0001F) {
    /* '<S25>:1:5' */
    /* '<S25>:1:6' */
    rtb_Time2Sec = 0.0F;
  } else {
    /* '<S25>:1:8' */
    rtb_Time2Sec /= rtb_abs_velocity;
  }

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/vdy_sae_Cr'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  Product: '<S8>/Divide'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   *  Sum: '<S8>/Add'
   */
  rtb_Product = (rtb_Time2Sec - (((rtb_abs_velocity * rtb_nu) *
    (*vdy_sae_U_VDYInputData).Parameter.VehWeight) / ((*vdy_sae_U_VDYInputData).
    Parameter.WheelBase * vdy_sae_Cr_p))) * (*vdy_sae_U_VDYInternalData_in).
    vdy_ye_out.veh_yaw_rate;

  /* UnitDelay: '<S27>/yaw_rate_delay_3' */
  rtb_yaw_rate_delay_3 = vdy_sae_DWork->yaw_rate_delay_3_DSTATE;

  /* UnitDelay: '<S27>/yaw_rate_delay_2' */
  rtb_yaw_rate_delay_2 = vdy_sae_DWork->yaw_rate_delay_2_DSTATE;

  /* UnitDelay: '<S27>/yaw_rate_delay_1' */
  rtb_yaw_rate_delay_1 = vdy_sae_DWork->yaw_rate_delay_1_DSTATE;

  /* Product: '<S27>/Divide' incorporates:
   *  Constant: '<S27>/filter_length'
   *  Sum: '<S27>/Add'
   *  UnitDelay: '<S27>/yaw_rate_delay_4'
   */
  rtb_Divide_f = (((vdy_sae_DWork->yaw_rate_delay_4_DSTATE +
                    vdy_sae_DWork->yaw_rate_delay_3_DSTATE) +
                   vdy_sae_DWork->yaw_rate_delay_2_DSTATE) +
                  vdy_sae_DWork->yaw_rate_delay_1_DSTATE) * 0.25F;

  /* Embedded MATLAB: '<S9>/get_gain_bias' incorporates:
   *  Constant: '<Root>/vdy_gye_Q_gain'
   */
  /* Embedded MATLAB Function 'q_gain/get_gain_bias': '<S26>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S26>:1:5' */
  rtb_Time2Sec = vdy_sae_Q_gain_p[0];

  /* '<S26>:1:6' */
  rtb_bias = vdy_sae_Q_gain_p[1];

  /* '<S26>:1:7' */

  /* If: '<S28>/If' incorporates:
   *  ActionPort: '<S29>/Action Port'
   *  ActionPort: '<S30>/Action Port'
   *  S-Function (ex_sfun_abs): '<S28>/Abs'
   *  S-Function (ex_sfun_abs): '<S28>/Abs1'
   *  SubSystem: '<S28>/If Action false'
   *  SubSystem: '<S28>/If Action true'
   */
  if ((CML_f_Abs( (real32_T)rtb_Product) >= 1.0E-7F) && (CML_f_Abs( (real32_T)
        rtb_Divide_f) >= 1.0E-7F)) {
    /* Sum: '<S30>/Add' */
    rtb_diff_merge = rtb_Product - rtb_Divide_f;
  } else {
    /* Inport: '<S29>/default_diff' */
    rtb_diff_merge = vdy_sae_Q_gain_p[2];
  }

  /* Sum: '<S9>/Sum2' incorporates:
   *  Product: '<S9>/Product'
   *  S-Function (ex_sfun_abs): '<S9>/Abs'
   */
  rtb_Time2Sec = (CML_f_Abs( (real32_T)rtb_diff_merge) * rtb_Time2Sec) +
    rtb_bias;
  for (i = 0; i < 4; i++) {
    /* UnitDelay: '<S2>/P_delay' */
    rtb_vdy_sfunc_AP_At_o2[i] = vdy_sae_DWork->P_delay_DSTATE[(i)];
    rtb_Q[i] = (rtb_Q[i] * rtb_Time2Sec) + vdy_sae_Q_add_p[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S17>/vdy_s-func_AP' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A, (real32_T*)
    rtb_vdy_sfunc_AP_At_o2, rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S2>/At' */
  /* Embedded MATLAB Function 'KF/At': '<S11>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S11>:1:5' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_y_d[i_0 + (i << 1)] = rtb_A[(i_0 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S17>/vdy_s-func_AP_At' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_y_d, rtb_vdy_sfunc_AP_At_o2, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Sum: '<S2>/APA_Q' */
  for (i = 0; i < 4; i++) {
    rtb_P_pred[i] = rtb_Q[i] + rtb_vdy_sfunc_AP_At_o2[i];
  }

  /* S-Function (MatrixMultiplication): '<S18>/vdy_s-func_HP' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_H, (real32_T*)
    rtb_P_pred, rtb_Knu, (uint8_T)2, (uint8_T)1, (uint8_T)2);

  /* Embedded MATLAB: '<S2>/Ht' */
  /* Embedded MATLAB Function 'KF/Ht': '<S13>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S13>:1:5' */
  for (i = 0; i < 2; i++) {
    rtb_y_m[i] = rtb_H[i];
  }

  /* S-Function (MatrixMultiplication): '<S18>/vdy_s-func_HP_Ht' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_Knu,
    (real32_T*)rtb_y_m, &rtb_nu, (uint8_T)2, (uint8_T)1, (uint8_T)1);

  /* Sum: '<S2>/HPH_R' */
  rtb_HPHt_R = rtb_R_out + rtb_nu;

  /* Embedded MATLAB: '<S12>/Matrix_Inversion_1x1' */
  vdy_matrix_inversion_1x1(rtb_HPHt_R, &vdy_sae_B->sf_Matrix_Inversion_1x1);

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_y_m, rtb_vdy_sfunc_P_pred_Ht_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)1);

  /* If: '<S12>/If' incorporates:
   *  ActionPort: '<S20>/Action Port'
   *  ActionPort: '<S21>/Action Port'
   *  SubSystem: '<S12>/calculate the gain'
   *  SubSystem: '<S12>/set gain to default value'
   */
  if (!vdy_sae_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* S-Function (MatrixMultiplication): '<S20>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)
      rtb_vdy_sfunc_P_pred_Ht_o2, (real32_T*)
      &vdy_sae_B->sf_Matrix_Inversion_1x1.HPHt_R_inv, rtb_K, (uint8_T)1,
      (uint8_T)2, (uint8_T)1);
  } else {
    /* Constant: '<S21>/Constant' */
    for (i = 0; i < 2; i++) {
      rtb_K[i] = vdy_sae_K_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_KH' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)
    rtb_H, rtb_KH, (uint8_T)1, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S2>/1_KH' incorporates:
   *  Constant: '<S2>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH[i] = vdy_sae_I_matrix_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S2>/Reset_P_pred' */
  /* Embedded MATLAB Function 'KF/Reset_P_pred': '<S14>:1' */
  if (vdy_sae_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* '<S14>:1:4' */
    /* '<S14>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = vdy_sae_P_init_p[(i)];
    }
  } else {
    /* '<S14>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out, rtb_P_post, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<Root>/diag_uncertainty' */
  /* Embedded MATLAB Function 'diag_uncertainty': '<S7>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S7>:1:5' */

  /* BusAssignment: '<Root>/slip_angle1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_store_raw_slip_angle = (*vdy_sae_U_VDYInternalData_in);
  rtb_store_raw_slip_angle.vdy_sae_out.est_slip_angle_var = rtb_P_post[0];

  /* Embedded MATLAB: '<S2>/Reset_x_pred' */
  /* Embedded MATLAB Function 'KF/Reset_x_pred': '<S15>:1' */
  if (vdy_sae_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* '<S15>:1:4' */
    /* '<S15>:1:6' */
    rtb_TmpSignalConversionAtSFunct[0] = rtb_xpost[0];
    rtb_TmpSignalConversionAtSFunct[1] = 0.0F;
  } else {
    /* '<S15>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFunct[i] = rtb_x_pred[i];
    }
  }

  /* Sum: '<S2>/z_Hx' */
  rtb_nu = rtb_Product - rtb_hx;

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)
    &rtb_nu, rtb_Knu, (uint8_T)1, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S2>/x_Knu' */
  for (i = 0; i < 2; i++) {
    vdy_sae_DWork->x_delay_DSTATE[(i)] = rtb_TmpSignalConversionAtSFunct[i] +
      rtb_Knu[i];
  }

  /* BusAssignment: '<Root>/slip_angle' */
  rtb_store_raw_slip_angle.vdy_sae_out.est_slip_angle =
    vdy_sae_DWork->x_delay_DSTATE[0];

  /* BusAssignment: '<Root>/store_raw_slip_angle' */
  rtb_store_raw_slip_angle.vdy_sae_out.raw_slip_angle = rtb_Product;

  /* Outport: '<Root>/VDYInternalData_out' */
  (*vdy_sae_Y_VDYInternalData_out) = rtb_store_raw_slip_angle;

  /* Update for UnitDelay: '<S27>/yaw_rate_delay_4' */
  vdy_sae_DWork->yaw_rate_delay_4_DSTATE = rtb_yaw_rate_delay_3;

  /* Update for UnitDelay: '<S27>/yaw_rate_delay_3' */
  vdy_sae_DWork->yaw_rate_delay_3_DSTATE = rtb_yaw_rate_delay_2;

  /* Update for UnitDelay: '<S27>/yaw_rate_delay_2' */
  vdy_sae_DWork->yaw_rate_delay_2_DSTATE = rtb_yaw_rate_delay_1;

  /* Update for UnitDelay: '<S27>/yaw_rate_delay_1' */
  vdy_sae_DWork->yaw_rate_delay_1_DSTATE = vdy_sae_DWork->x_delay_DSTATE[0];

  /* Update for UnitDelay: '<S2>/P_delay' */
  for (i = 0; i < 4; i++) {
    vdy_sae_DWork->P_delay_DSTATE[(i)] = rtb_P_post[i];
  }
}

/* Model initialize function */
void vdy_sae_initialize(boolean_T firstTime, BlockIO_vdy_sae *vdy_sae_B,
  D_Work_vdy_sae *vdy_sae_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_sae_B), 0,
                      sizeof(BlockIO_vdy_sae));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_sae_DWork, 0,
                      sizeof(D_Work_vdy_sae));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S2>/x_delay' */
    for (i = 0; i < 2; i++) {
      vdy_sae_DWork->x_delay_DSTATE[(i)] = vdy_sae_x_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S2>/P_delay' */
    for (i = 0; i < 4; i++) {
      vdy_sae_DWork->P_delay_DSTATE[(i)] = vdy_sae_P_init_p[(i)];
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
