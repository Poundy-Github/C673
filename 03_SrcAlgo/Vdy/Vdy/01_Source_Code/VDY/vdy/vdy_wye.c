/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_wye.c
   Real-Time Workshop code generated for Simulink model vdy_wye.
   Model version                        : 1.3060
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:02:11 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:02:12 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy wheel yaw rate estimation,
   estimates the wheel  yaw rate
   and the offset of the gyro sensor yaw rate.
   Therefore the four wheel speeds and the
   gyro yaw rate are used
   VERSION:                             : $Revision: 1.5 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_wye.h"
#include "vdy_wye_private.h"

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
 *    '<S51>/Get_NVM_IO_State'
 *    '<S64>/Get_NVM_IO_State'
 */
void vdy_wye_Get_NVM_IO_State(uint32_T rtu_pos, uint32_T rtu_state_in, uint32_T
  rtu_VDYIOBitMask, rtB_Get_NVM_IO_State_vdy_wye *localB)
{
  int32_T x;
  uint32_T tmp;

  /* Embedded MATLAB: '<S51>/Get_NVM_IO_State' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/Get_WhlLoad_IO_State/GetIOState/Get_NVM_IO_State': '<S52>:1' */
  /*  position in state array */
  /* '<S52>:1:4' */
  tmp = rtu_pos;
  if (rtu_pos > 2147483647U) {
    tmp = 2147483647U;
  }

  x = (int32_T)tmp;

  /* '<S52>:1:5' */
  /*  get state info */
  /* '<S52>:1:8' */
  localB->state = (rtu_state_in >> (x - ((x >> 5) << 5))) & rtu_VDYIOBitMask;
}

/*
 * Output and update for atomic system:
 *    '<S35>/Time2Sec'
 *    '<S37>/Time2Sec'
 *    '<S9>/Time2Sec'
 *    '<S10>/Time2Sec'
 */
void vdy_wye_Time2Sec(uint16_T rtu_u, rtB_Time2Sec_vdy_wye *localB)
{
  /* Product: '<S59>/Time2Sec' incorporates:
   *  Constant: '<S59>/Constant'
   */
  localB->Time2Sec = ((real32_T)rtu_u) / 1000.0F;
}

/*
 * Output and update for atomic system:
 *    '<S66>/make_A_matrix'
 *    '<S80>/make_A_matrix'
 */
void vdy_wye_make_A_matrix(real32_T rtu_CycleTime, rtB_make_A_matrix_vdy_wye
  *localB)
{
  int32_T i;
  static int8_T tmp[3] = { 0, 1, 0 };

  static int8_T tmp_0[3] = { 0, 0, 1 };

  /* Embedded MATLAB: '<S66>/make_A_matrix' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/make_A_Q_R1/A/make_A_matrix': '<S73>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S73>:1:5' */
  localB->A[0] = 1.0F;
  localB->A[3] = rtu_CycleTime;
  localB->A[6] = 0.0F;
  for (i = 0; i < 3; i++) {
    localB->A[1 + (3 * i)] = (real32_T)tmp[i];
  }

  for (i = 0; i < 3; i++) {
    localB->A[2 + (3 * i)] = (real32_T)tmp_0[i];
  }
}

/*
 * Output and update for atomic system:
 *    '<S70>/get_bit'
 *    '<S84>/get_bit'
 */
void vdy_wye_get_bit(uint16_T rtu_value_in, uint16_T rtu_bitmask,
                     rtB_get_bit_vdy_wye *localB)
{
  /* Embedded MATLAB: '<S70>/get_bit' */
  /* Embedded MATLAB Function 'get_bit/get_bit': '<S79>:1' */
  /*  get state of a specified bit */
  if (rtu_value_in == rtu_bitmask) {
    /* '<S79>:1:3' */
    /* '<S79>:1:4' */
    localB->y = 1U;
  } else {
    /* '<S79>:1:6' */
    localB->y = 0U;
  }
}

/*
 * Output and update for atomic system:
 *    '<S11>/Get_IO_State'
 *    '<S11>/Get_IO_State1'
 */
void vdy_wye_Get_IO_State(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State_vdy_wye *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S103>/Index Vector' incorporates:
   *  Constant: '<S103>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/* Model step function */
void vdy_wye_step(BlockIO_vdy_wye *vdy_wye_B, D_Work_vdy_wye *vdy_wye_DWork,
                  VDYInputData_t *vdy_wye_U_VDYInputData, VDYInternalData_t
                  *vdy_wye_U_VDYInternalData_in, VDYNvData_t
                  *vdy_wye_U_VDYNvData_in, VDYInternalData_t
                  *vdy_wye_Y_VDYInternalData_out, VDYNvData_t
                  *vdy_wye_Y_VDYNVData_out)
{
  /* local block i/o variables */
  real32_T rtb_Sub;
  real32_T rtb_sub_abs;
  real32_T rtb_x_pred[3];
  real32_T rtb_veh_velo_j;
  real32_T rtb_veh_lat_accel;
  real32_T rtb_P_pred[9];
  real32_T rtb_HPHt_R[4];
  real32_T rtb_P_predHt[6];
  real32_T rtb_K[6];
  real32_T rtb_veh_velo_h;
  real32_T rtb_veh_lat_accel_h;
  real32_T rtb_veh_accel;
  real32_T rtb_P_pred_n[9];
  real32_T rtb_HPHt_R_o[9];
  real32_T rtb_P_predHt_n[9];
  real32_T rtb_K_d[9];
  real32_T rtb_P_post_p[9];
  real32_T rtb_x_pred_g[3];
  real32_T rtb_Divide_c;
  real32_T rtb_last_est_whl_yaw_rate;
  real32_T rtb_P_pred_nb[4];
  real32_T rtb_HPHt_R_m[4];
  real32_T rtb_P_predHt_g[4];
  real32_T rtb_K_n[4];
  real32_T rtb_P_post_d[4];
  real32_T rtb_x_post_bq[2];
  real32_T rtb_x_pred_p[2];
  real32_T rtb_P_post_k[9];
  real32_T rtb_diff;
  real32_T rtb_A[4];
  real32_T rtb_diff_n;
  real32_T rtb_diff_g;
  real32_T rtb_x_post_h[3];
  real32_T rtb_H[6];
  real32_T rtb_P_pred_out[9];
  real32_T rtb_P_pred_out_b[4];
  real32_T rtb_x_post_f[3];
  real32_T rtb_P_post_e[9];
  real32_T rtb_P_pred_out_p[9];
  real32_T rtb_vdy_sfunc_H_P_o2[6];
  real32_T rtb_Ht[6];
  real32_T rtb_Knu[3];
  real32_T rtb_Knu_p[2];
  real32_T rtb_Ht_a[4];
  real32_T rtb_Ht_c[9];
  real32_T rtb_nu[2];
  real32_T rtb_nu_h[3];
  real32_T rtb_vdy_sfunc_HPHt_o2[9];
  real32_T rtb_vdy_sfunc_HP_Ht_o2[4];
  real32_T rtb_KH[4];
  real32_T rtb_KH_g[9];
  uint32_T rtb_State;
  uint32_T rtb_State_n;
  uint16_T rtb_CycleTime;
  uint16_T rtb_BitwiseOperator;
  uint16_T rtb_BitwiseOperator_c;
  uint8_T rtb_State_f[32];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_vdy_sfunc_K_gain_o1_b;
  uint8_T rtb_vdy_sfunc_K_gain_o1_o;
  uint8_T rtb_vdy_sfunc_P_post_o1;
  real32_T frfilt;
  real32_T refilt;
  real32_T kf_quad;
  real32_T vx_quad;
  real32_T WldFactFront;
  real32_T sigma_model_gain[2];
  int32_T bitpos;
  uint32_T c;
  real32_T rtb_Yk1;
  real32_T rtb_frfiltWithWldEst;
  real32_T rtb_refiltWithWldEst;
  real32_T rtb_x_post[3];
  real32_T rtb_hx[2];
  real32_T rtb_x_pred_out[3];
  real32_T rtb_x_pred_out_f[3];
  real32_T rtb_x_out[3];
  uint8_T rtb_wye_yaw_off_control;
  uint8_T rtb_Reset;
  int32_T rtb_TP_yaw_off_control_out;
  real32_T rtb_frWithWldEst_wye;
  real32_T rtb_reWithWldEst_wye;
  real32_T rtb_Sum;
  real32_T rtb_Sum_p;
  real32_T rtb_Sum_c;
  real32_T rtb_TmpSignalConversionAtSFun_c[2];
  int32_T rtb_TP_init;
  uint8_T rtb_init_out;
  uint8_T rtb_counter_out;
  int8_T rtb_sign_out;
  boolean_T rtb_R_onoff_front;
  boolean_T rtb_R_onoff_rear;
  boolean_T rtb_R_yaw_valid;
  uint8_T rtb_init;
  uint8_T rtb_Rroff;
  boolean_T rtb_R_onoff;
  uint32_T rtb_state;
  real32_T rtb_Q_g[9];
  real32_T rtb_R_out_p[4];
  real32_T rtb_Q_m[9];
  int32_T i;
  real32_T rtb_TmpSignalConversionAtSFun_0[2];
  real32_T sigma_model_gain_0[2];
  real32_T rtb_TmpSignalConversionAtSFun_1[4];
  real32_T rtb_VectorConcatenate_idx;
  real32_T rtb_VectorConcatenate_idx_0;
  real32_T rtb_VectorConcatenate_idx_1;
  static int8_T tmp[3] = { 0, 1, 0 };

  /* UnitDelay: '<S55>/UD' */
  rtb_Yk1 = vdy_wye_DWork->UD_DSTATE;

  /* Embedded MATLAB: '<S11>/divide_front_whl' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_z_vektor/divide_front_whl': '<S106>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (((*vdy_wye_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right >=
       3.0F) && ((*vdy_wye_U_VDYInternalData_in).
                 vdy_wpp_out.wheel_velo_front_left >= 3.0F)) {
    /* '<S106>:1:5' */
    /* '<S106>:1:6' */
    rtb_VectorConcatenate_idx = (*vdy_wye_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_left / (*vdy_wye_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_right;

    /* '<S106>:1:7' */
    rtb_R_onoff_front = TRUE;
  } else {
    /* '<S106>:1:9' */
    rtb_VectorConcatenate_idx = 1.0F;

    /* '<S106>:1:10' */
    rtb_R_onoff_front = FALSE;
  }

  /* Embedded MATLAB: '<S11>/divide_rear_whl' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_z_vektor/divide_rear_whl': '<S107>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (((*vdy_wye_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right >= 3.0F)
      && ((*vdy_wye_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left >=
          3.0F)) {
    /* '<S107>:1:5' */
    /* '<S107>:1:6' */
    rtb_VectorConcatenate_idx_0 = (*vdy_wye_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_left / (*vdy_wye_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_right;

    /* '<S107>:1:7' */
    rtb_R_onoff_rear = TRUE;
  } else {
    /* '<S107>:1:9' */
    rtb_VectorConcatenate_idx_0 = 1.0F;

    /* '<S107>:1:10' */
    rtb_R_onoff_rear = FALSE;
  }

  /* BusSelector: '<S11>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 32; i++) {
    rtb_State_f[i] = (*vdy_wye_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<S11>/Get_IO_State' */
  vdy_wye_Get_IO_State(rtb_State_f, &vdy_wye_B->Get_IO_State, ((uint32_T)
    VDY_SIN_POS_YWR));

  /* end of Outputs for SubSystem: '<S11>/Get_IO_State' */

  /* Outputs for atomic SubSystem: '<S11>/Get_IO_State1' */
  vdy_wye_Get_IO_State(rtb_State_f, &vdy_wye_B->Get_IO_State1, ((uint32_T)
    VDY_SIN_POS_YWRINT));

  /* end of Outputs for SubSystem: '<S11>/Get_IO_State1' */

  /* Embedded MATLAB: '<S11>/R_yaw_valid' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  /* Embedded MATLAB Function 'make_z_vektor/R_yaw_valid': '<S105>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (((uint32_T)CFG_VDY_INT_GYRO) == 0U) {
    /* '<S105>:1:5' */
    if (vdy_wye_B->Get_IO_State.IndexVector == 0) {
      /* '<S105>:1:6' */
      /* '<S105>:1:7' */
      rtb_R_yaw_valid = TRUE;

      /* '<S105>:1:8' */
      rtb_VectorConcatenate_idx_1 = (*vdy_wye_U_VDYInputData).Signals.YawRate;
    } else {
      /* '<S105>:1:10' */
      rtb_R_yaw_valid = FALSE;

      /* '<S105>:1:11' */
      rtb_VectorConcatenate_idx_1 = 0.0F;
    }
  } else if (vdy_wye_B->Get_IO_State1.IndexVector == 0) {
    /* '<S105>:1:14' */
    /* '<S105>:1:15' */
    rtb_R_yaw_valid = TRUE;

    /* '<S105>:1:16' */
    rtb_VectorConcatenate_idx_1 = (*vdy_wye_U_VDYInputData).Signals.YawRateInt;
  } else {
    /* '<S105>:1:18' */
    rtb_R_yaw_valid = FALSE;

    /* '<S105>:1:19' */
    rtb_VectorConcatenate_idx_1 = 0.0F;
  }

  /* Sum: '<S55>/Sum' incorporates:
   *  Gain: '<S55>/Gain'
   *  Sum: '<S55>/Diff'
   */
  rtb_Sum = ((rtb_Yk1 - rtb_VectorConcatenate_idx) * 0.98F) +
    rtb_VectorConcatenate_idx;

  /* Sum: '<S56>/Sum' incorporates:
   *  Gain: '<S56>/Gain'
   *  Sum: '<S56>/Diff'
   *  UnitDelay: '<S56>/UD'
   */
  rtb_Sum_p = ((vdy_wye_DWork->UD_DSTATE_a - rtb_VectorConcatenate_idx_0) *
               0.98F) + rtb_VectorConcatenate_idx_0;

  /* Embedded MATLAB: '<S34>/calc_fr_re_yaw' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S8>/last_est_wld'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/calc_yaw_front_rear/calc_fr_re_yaw': '<S54>:1' */
  /*  use this equations if no wheel load dependancty should be used */
  /*  Qf = */
  /* ->   1/(yaw*s+vx)*(-(yaw*s+vx)*(yaw*s-vx))^(1/2)*Kf */
  /*     -1/(yaw*s+vx)*(-(yaw*s+vx)*(yaw*s-vx))^(1/2)*Kf */
  /*    */
  /*  Qr = */
  /*  -Kr*(yaw*s-2*vx)/(yaw*s+2*vx) */
  /*    */
  /*  H = */
  /*  ->[ 0, -vx*Kf*s/(yaw*s+vx)/(-yaw^2*s^2+vx^2)^(1/2),  1/(yaw*s+vx)*(-yaw^2*s^2+vx^2)^(1/2),  0,  0] */
  /*  [ 0,  vx*Kf*s/(yaw*s+vx)/(-yaw^2*s^2+vx^2)^(1/2), -1/(yaw*s+vx)*(-yaw^2*s^2+vx^2)^(1/2),  0,  0] */
  /*  [ 0,                   -4*s*Kr*vx/(yaw*s+2*vx)^2,  0, -(yaw*s-2*vx)/(yaw*s+2*vx),  0] */
  /*  [ 0,                                           1,  0,                          0, -1] */
  /*  use this equations if the estimated wheel load dependancty for the front axis should be used */
  /*  WldFactFront = 1+1/1000000*est_wld_dep*CntrOfGravHeight*VehWeight*AxisLoadDist*vx^2/TW_F^2 */
  /*  WldFactRear = single(1.0) */
  /*  use this equations if the parameter wheel load dependancty for both axis should be used */
  /*  WldFactFront = 1+1/1000000*WhlLoadDepFrontAxle*CntrOfGravHeight*VehWeight*AxisLoadDist*vx^2/TW_F^2 */
  /*  WldFactRear = 1+1/1000000*WhlLoadDepRearAxle*CntrOfGravHeight*VehWeight*(1-AxisLoadDist)*vx^2/TW_R^2 */
  /*  front = -(Qf^2-k_front^2)/(Qf^2+k_front^2)*vx/TW_F/WldFactFront */
  /*  rear = -2*(Qr-k_rear)/(Qr+k_rear)*vx/TW_R/WldFactRear */
  /*    */
  /*  Qf = -> 1/(yaw*TW_F*WldFactFront+vx)*(-(yaw*TW_F*WldFactFront+vx)*(yaw*TW_F*WldFactFront-vx))^(1/2)*k_front */
  /*       -1/(yaw*TW_F*WldFactFront+vx)*(-(yaw*TW_F*WldFactFront+vx)*(yaw*TW_F*WldFactFront-vx))^(1/2)*k_front */
  /*   */
  /*  Qr = -k_rear*(yaw*s*WldFactRear-2*vx)/(yaw*s*WldFactRear+2*vx) */
  /*    */
  /*  h = 1/(yaw*TW_F*WldFactFront+vx)*(-(yaw*TW_F*WldFactFront+vx)*(yaw*TW_F*WldFactFront-vx))^(1/2)*k_front */
  /*                                                -k_rear*(yaw*s*WldFactRear-2*vx)/(yaw*s*WldFactRear+2*vx) */
  /*                                                                                               yaw+yawoff */
  /*    */
  /*  H1 =[ 0, -vx*k_front*TW_F*WldFactFront/(yaw*TW_F*WldFactFront+vx)/(-yaw^2*TW_F^2*WldFactFront^2+vx^2)^(1/2), 0] */
  /*      [ 0,                                              -4*s*WldFactRear*k_rear*vx/(yaw*s*WldFactRear+2*vx)^2, 0] */
  /*      [ 0,                                                                                                  1, 1] */
  /*  fr1 = -((qf^2 - 1) / (qf^2 + 1))*(1/twf)*vx; */
  /*   */
  /*  re = -((qr - 1) / (qr + 1))*(2/twr)*vx; */
  /*  fr1 = -((qf^2 - 1) / (qf^2 + 1))*(1/twf)*vx; */
  /*   */
  /*  re = -((qr - 0.9995) / (qr + 0.9995))*(2/twr)*vx; */
  /*   */
  /* fWld = 2.675; */
  /* rWld = 1.0;%1.725; */
  /* fr = -((qf^2 - kf^2) / (qf^2 + kf^2))*(1/twf)*vx; */
  /* re = -((qr - kr) / (qr + kr))*(2/twr)*vx; */
  /* '<S54>:1:61' */
  rtb_Yk1 = rtb_Sum * rtb_Sum;

  /* '<S54>:1:62' */
  rtb_VectorConcatenate_idx *= rtb_VectorConcatenate_idx;

  /* '<S54>:1:64' */
  kf_quad = (*vdy_wye_U_VDYInternalData_in).
    vdy_offsets_in.vdy_whs_offset.offset_ratio_front *
    (*vdy_wye_U_VDYInternalData_in).
    vdy_offsets_in.vdy_whs_offset.offset_ratio_front;

  /* '<S54>:1:65' */
  vx_quad = (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo *
    (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /*  calculate the wheel load dep factor for the different configurations */
  /* '<S54>:1:68' */
  switch (((uint32_T)VDY_USE_EST_WLD_DEP)) {
   case 0U:
    /*  no wheel load dep is used */
    /* '<S54>:1:70' */
    WldFactFront = 1.0F;

    /* '<S54>:1:72' */
    vx_quad = 1.0F;
    break;

   case 1U:
    /*  use the estimated wheel load dep for front axis */
    /*  calc wld factor front      */
    /* '<S54>:1:75' */
    WldFactFront = (((((vdy_wye_DWork->last_est_wld_DSTATE *
                        (*vdy_wye_U_VDYInputData).Parameter.CntrOfGravHeight) *
                       (*vdy_wye_U_VDYInputData).Parameter.VehWeight) *
                      (*vdy_wye_U_VDYInputData).Parameter.AxisLoadDistr) *
                     vx_quad) / (((*vdy_wye_U_VDYInputData).
      Parameter.TrackWidthFront * (*vdy_wye_U_VDYInputData).
      Parameter.TrackWidthFront) * 1.0E+6F)) + 1.0F;

    /* '<S54>:1:77' */
    vx_quad = 1.0F;
    break;

   case 2U:
    /*  use the wheel load parameter only for front axis */
    /*  calc wld factor front */
    /* '<S54>:1:80' */
    WldFactFront = ((((((*vdy_wye_U_VDYInputData).Parameter.WhlLoadDepFrontAxle *
                        (*vdy_wye_U_VDYInputData).Parameter.CntrOfGravHeight) *
                       (*vdy_wye_U_VDYInputData).Parameter.VehWeight) *
                      (*vdy_wye_U_VDYInputData).Parameter.AxisLoadDistr) *
                     vx_quad) / (((*vdy_wye_U_VDYInputData).
      Parameter.TrackWidthFront * (*vdy_wye_U_VDYInputData).
      Parameter.TrackWidthFront) * 1.0E+6F)) + 1.0F;

    /* '<S54>:1:82' */
    vx_quad = 1.0F;
    break;

   case 3U:
    /*  Use the wheel load parameter for front and rear axis */
    /*  calc wld factor front         */
    /* '<S54>:1:86' */
    WldFactFront = ((((((*vdy_wye_U_VDYInputData).Parameter.WhlLoadDepFrontAxle *
                        (*vdy_wye_U_VDYInputData).Parameter.CntrOfGravHeight) *
                       (*vdy_wye_U_VDYInputData).Parameter.VehWeight) *
                      (*vdy_wye_U_VDYInputData).Parameter.AxisLoadDistr) *
                     vx_quad) / (((*vdy_wye_U_VDYInputData).
      Parameter.TrackWidthFront * (*vdy_wye_U_VDYInputData).
      Parameter.TrackWidthFront) * 1.0E+6F)) + 1.0F;

    /*  calc wld factor rear         */
    /* '<S54>:1:89' */
    vx_quad = ((((((*vdy_wye_U_VDYInputData).Parameter.WhlLoadDepRearAxle *
                   (*vdy_wye_U_VDYInputData).Parameter.CntrOfGravHeight) *
                  (*vdy_wye_U_VDYInputData).Parameter.VehWeight) * (1.0F -
      (*vdy_wye_U_VDYInputData).Parameter.AxisLoadDistr)) * vx_quad) /
               (((*vdy_wye_U_VDYInputData).Parameter.TrackWidthRear *
                 (*vdy_wye_U_VDYInputData).Parameter.TrackWidthRear) * 1.0E+6F))
      + 1.0F;
    break;

   default:
    /*  no wheel load dep is used */
    /* '<S54>:1:91' */
    WldFactFront = 1.0F;

    /* '<S54>:1:92' */
    vx_quad = 1.0F;
    break;
  }

  /*  calculate the filtered wheel yaw rate for the front and rear axis */
  /* '<S54>:1:97' */
  frfilt = ((-((rtb_Yk1 - kf_quad) / (rtb_Yk1 + kf_quad))) * (1.0F /
             (*vdy_wye_U_VDYInputData).Parameter.TrackWidthFront)) *
    (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /*  calculate the filtered wheel yaw rate for the front and rear axis for wheel yaw rate estimation */
  /* '<S54>:1:100' */
  /*  front filtered yaw rate with wheel load dep */
  if ((WldFactFront >= 1.0E-7F) || (WldFactFront <= -1.0E-7F)) {
    /* '<S54>:1:103' */
    /* '<S54>:1:104' */
    rtb_frfiltWithWldEst = frfilt / WldFactFront;

    /* '<S54>:1:105' */
    rtb_frWithWldEst_wye = (((-((rtb_VectorConcatenate_idx - kf_quad) /
      (rtb_VectorConcatenate_idx + kf_quad))) * (1.0F / (*vdy_wye_U_VDYInputData)
      .Parameter.TrackWidthFront)) * (*vdy_wye_U_VDYInternalData_in).
      vdy_ve_out.veh_velo) / WldFactFront;
  } else {
    /* '<S54>:1:107' */
    rtb_frfiltWithWldEst = 1.4F;

    /*  max ca. 80 grad / s  */
    /* '<S54>:1:108' */
    rtb_frWithWldEst_wye = 1.4F;

    /*  max ca. 80 grad / s  */
  }

  /*  rear filtered yaw rate */
  /* '<S54>:1:112' */
  refilt = ((-((rtb_Sum_p - (*vdy_wye_U_VDYInternalData_in).
                vdy_offsets_in.vdy_whs_offset.offset_ratio_rear) / (rtb_Sum_p +
               (*vdy_wye_U_VDYInternalData_in).
    vdy_offsets_in.vdy_whs_offset.offset_ratio_rear))) * (2.0F /
             (*vdy_wye_U_VDYInputData).Parameter.TrackWidthRear)) *
    (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /*  rear filtered yaw rate for wheel yaw rate estimation */
  /* '<S54>:1:115' */
  /*  rear filtered yaw rate with wheel load dep */
  if ((vx_quad >= 1.0E-7F) || (vx_quad <= -1.0E-7F)) {
    /* '<S54>:1:118' */
    /* '<S54>:1:119' */
    rtb_refiltWithWldEst = refilt / vx_quad;

    /* '<S54>:1:120' */
    rtb_reWithWldEst_wye = (((-((rtb_VectorConcatenate_idx_0 -
      (*vdy_wye_U_VDYInternalData_in).
      vdy_offsets_in.vdy_whs_offset.offset_ratio_rear) /
      (rtb_VectorConcatenate_idx_0 + (*vdy_wye_U_VDYInternalData_in).
       vdy_offsets_in.vdy_whs_offset.offset_ratio_rear))) * (2.0F /
      (*vdy_wye_U_VDYInputData).Parameter.TrackWidthRear)) *
      (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo) / vx_quad;
  } else {
    /* '<S54>:1:122' */
    rtb_refiltWithWldEst = 1.4F;

    /*  max ca. 80 grad / s  */
    /* '<S54>:1:123' */
    rtb_reWithWldEst_wye = 1.4F;

    /*  max ca. 80 grad / s  */
  }

  /*  mean front rear yaw rate  */
  /* '<S54>:1:127' */
  /* frWld = -((qf^2 - kf^2) / (qf^2 + kf^2))*(1/twf)*vx/(1 + fWld * COG * (Weight*AxlDist/1000.0) * vx.^2 / (1000*twf^2)) ; */
  /* reWld = -((qr - kr) / (qr + kr))*(2/twr)*vx/(1 + rWld * COG * (Weight*(1-AxlDist)/1000.0) * vx.^2 / (1000*twr^2)); */
  /* frWldcal = -((qf^2 - kf^2) / (qf^2 + kf^2))*(1/twf)*vx/(1 + wld * COG * (Weight*AxlDist/1000.0) * vx.^2 / (1000*twf^2)) ; */

  /* Sum: '<S36>/Sub' */
  rtb_Sub = rtb_frfiltWithWldEst - rtb_refiltWithWldEst;

  /* S-Function (ex_sfun_abs): '<S36>/sub_abs' */
  rtb_sub_abs = CML_f_Abs( (real32_T)rtb_Sub);

  /* BusSelector: '<Root>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_CycleTime = (*vdy_wye_U_VDYInputData).Frame.CycleTime;

  /* Outputs for atomic SubSystem: '<S37>/Time2Sec' */
  vdy_wye_Time2Sec(rtb_CycleTime, &vdy_wye_B->Time2Sec);

  /* end of Outputs for SubSystem: '<S37>/Time2Sec' */

  /* Embedded MATLAB: '<S66>/make_A_matrix' */
  vdy_wye_make_A_matrix(vdy_wye_B->Time2Sec.Time2Sec,
                        &vdy_wye_B->sf_make_A_matrix);

  /* UnitDelay: '<S33>/x_delay_wld' */
  for (i = 0; i < 3; i++) {
    rtb_x_post[i] = vdy_wye_DWork->x_delay_wld_DSTATE[(i)];
  }

  /* BusSelector: '<S33>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYNvData_in'
   */
  rtb_State = (*vdy_wye_U_VDYNvData_in).Read.State;

  /* Embedded MATLAB: '<S51>/Get_NVM_IO_State' */
  vdy_wye_Get_NVM_IO_State(((uint32_T)VDY_NVM_POS_WLD), rtb_State, 3U,
    &vdy_wye_B->sf_Get_NVM_IO_State);

  /* Embedded MATLAB: '<S33>/check_init_state' incorporates:
   *  Inport: '<Root>/VDYNvData_in'
   *  UnitDelay: '<S33>/init_nvm_wld_delay'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/check_init_state': '<S42>:1' */
  /*  check if NVMSSG is valid and first init is true */
  if ((vdy_wye_B->sf_Get_NVM_IO_State.state == ((uint32_T)VDY_IO_STATE_VALID)) &&
      (vdy_wye_DWork->init_nvm_wld_delay_DSTATE == 0)) {
    /* '<S42>:1:3' */
    /* '<S42>:1:4' */
    rtb_Yk1 = (*vdy_wye_U_VDYNvData_in).Read.Wld.Wld_front;

    /* '<S42>:1:5' */
    rtb_init = 1U;

    /* '<S42>:1:6' */
    rtb_init_out = 1U;
  } else {
    /* '<S42>:1:8' */
    rtb_Yk1 = 1.5F;

    /* '<S42>:1:9' */
    rtb_init = 0U;

    /* '<S42>:1:10' */
    rtb_init_out = vdy_wye_DWork->init_nvm_wld_delay_DSTATE;
  }

  /* Embedded MATLAB: '<S33>/init_x_yaw' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/init_x_yaw': '<S44>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S44>:1:5' */
  for (i = 0; i < 3; i++) {
    rtb_x_post_h[i] = rtb_x_post[i];
  }

  /*  if  */
  if (rtb_x_post[2] < 0.5F) {
    /* '<S44>:1:8' */
    /* '<S44>:1:9' */
    rtb_x_post_h[2] = 0.5F;
  }

  /*  if  */
  if (rtb_x_post[2] > 3.0F) {
    /* '<S44>:1:13' */
    /* '<S44>:1:14' */
    rtb_x_post_h[2] = 3.0F;
  }

  /*  init wheel load dependency if init is true */
  if (rtb_init == 1) {
    /* '<S44>:1:18' */
    /* '<S44>:1:19' */
    rtb_x_post_h[2] = rtb_Yk1;
  }

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    vdy_wye_B->sf_make_A_matrix.A, (real32_T*)rtb_x_post_h, rtb_x_pred, (uint8_T)
    3, (uint8_T)3, (uint8_T)1);

  /* Sum: '<S11>/Add' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  WldFactFront = (*vdy_wye_U_VDYInternalData_in).
    vdy_wpp_out.wheel_velo_front_left_var + (*vdy_wye_U_VDYInternalData_in).
    vdy_wpp_out.wheel_velo_front_right_var;

  /* Sum: '<S11>/Add1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_VectorConcatenate_idx_0 = (*vdy_wye_U_VDYInternalData_in).
    vdy_wpp_out.wheel_velo_rear_left_var + (*vdy_wye_U_VDYInternalData_in).
    vdy_wpp_out.wheel_velo_rear_right_var;

  /* Sum: '<S76>/Sum' incorporates:
   *  Gain: '<S76>/Gain'
   *  Sum: '<S76>/Diff'
   *  UnitDelay: '<S76>/UD'
   */
  rtb_Sum_c = ((vdy_wye_DWork->UD_DSTATE_b - rtb_VectorConcatenate_idx_0) *
               0.998F) + rtb_VectorConcatenate_idx_0;

  /* Embedded MATLAB: '<S68>/adapt_R_matrix' incorporates:
   *  Constant: '<S68>/R'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/make_A_Q_R1/R/adapt_R_matrix': '<S75>:1' */
  /*  build the R matrix */
  /* '<S75>:1:3' */
  for (i = 0; i < 4; i++) {
    rtb_R_out_p[i] = vdy_wye_R_wld_p[(i)];
  }

  if ((((int32_T)rtb_R_onoff_front) == 0) || (((int32_T)rtb_R_onoff_rear) == 0))
  {
    /* '<S75>:1:4' */
    /* '<S75>:1:5' */
    for (i = 0; i < 4; i++) {
      rtb_R_out_p[i] = vdy_wye_R_wld_p[(i)] * 10000.0F;
    }
  }

  if ((rtb_VectorConcatenate_idx_0 > (rtb_Sum_c * 1.05F)) ||
      (((*vdy_wye_U_VDYInternalData_in).
        vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev >= 1.0F) &&
       ((*vdy_wye_U_VDYInternalData_in).
        vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev >= 1.0F))) {
    /* '<S75>:1:10' */
    /* '<S75>:1:11' */
    rtb_Rroff = 1U;
  } else {
    /* '<S75>:1:13' */
    rtb_Rroff = 0U;

    /*  if sum variance of ratio front is above */
    if (WldFactFront > vdy_wye_R_control_p) {
      /* '<S75>:1:15' */
      /* '<S75>:1:16' */
      rtb_R_out_p[0] = rtb_R_out_p[0] * 100000.0F;

      /* '<S75>:1:17' */
      rtb_Rroff = 1U;
    }

    /*  if sum variance of ratio rear is above */
    if (rtb_VectorConcatenate_idx_0 > vdy_wye_R_control_p) {
      /* '<S75>:1:21' */
      /* '<S75>:1:22' */
      rtb_R_out_p[3] = rtb_R_out_p[3] * 100000.0F;

      /* '<S75>:1:23' */
      rtb_Rroff = 1U;
    }

    /*  if yaw rate difference front rear is above specified value turn off the estimation */
    if (rtb_sub_abs > vdy_wye_Q_sigmas_dyn_off_p[4]) {
      /* '<S75>:1:27' */
      /* '<S75>:1:28' */
      rtb_Rroff = 1U;
    }
  }

  /* Embedded MATLAB: '<S43>/hx_func' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/hx/hx_func': '<S53>:1' */
  /*  Transformation from state space to measurement space */
  /*  Wheel Load dep filter */
  /* '<S53>:1:4' */
  /* '<S53>:1:5' */
  /*  yawFmeas = -(Qf2^2-Kf2^2)/(Qf2^2+Kf2^2)*vx/s */
  /*  yawRmeas = -2*(Qr-Kr)/(Qr+Kr)*vx/s */
  /*   */
  /*  yawXFmeas = yaw*(1+1/1000000*K*h*m*vx^2/s^2) */
  /*    */
  /*  z = -(Qf2^2-Kf2^2)/(Qf2^2+Kf2^2)*vx/s */
  /*             -2*(Qr-Kr)/(Qr+Kr)*vx/s */
  /*    */
  /*  h =  yaw*(1+1/1000000*K*h*m*vx^2/s^2) */
  /*                                yaw */
  /*    */
  /*  H1 =[ 0, 1/1000000*(1000000*s^2+K*h*m*vx^2)/s^2, 1/1000000*yaw*h*m*vx^2/s^2] */
  /*      [ 0,                                      1,                          0] */
  /*     */
  /* '<S53>:1:23' */
  rtb_Yk1 = (*vdy_wye_U_VDYInputData).Parameter.VehWeight *
    (*vdy_wye_U_VDYInputData).Parameter.AxisLoadDistr;

  /* '<S53>:1:24' */
  vx_quad = (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo *
    (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo;

  /* '<S53>:1:25' */
  rtb_VectorConcatenate_idx = (*vdy_wye_U_VDYInputData).
    Parameter.TrackWidthFront * (*vdy_wye_U_VDYInputData).
    Parameter.TrackWidthFront;

  /* '<S53>:1:26' */
  rtb_hx[0] = ((((((1.0E-6F * rtb_x_pred[2]) * (*vdy_wye_U_VDYInputData).
                   Parameter.CntrOfGravHeight) * rtb_Yk1) * vx_quad) /
                rtb_VectorConcatenate_idx) + 1.0F) * rtb_x_pred[1];
  rtb_hx[1] = rtb_x_pred[1];

  /* '<S53>:1:29' */
  rtb_H[0] = 0.0F;
  rtb_H[2] = (((((rtb_x_pred[2] * (*vdy_wye_U_VDYInputData).
                  Parameter.CntrOfGravHeight) * rtb_Yk1) * vx_quad) + (1.0E+6F *
    rtb_VectorConcatenate_idx)) * 1.0E-6F) / rtb_VectorConcatenate_idx;
  rtb_H[4] = ((((1.0E-6F * rtb_x_pred[1]) * (*vdy_wye_U_VDYInputData).
                Parameter.CntrOfGravHeight) * rtb_Yk1) * vx_quad) /
    rtb_VectorConcatenate_idx;
  for (i = 0; i < 3; i++) {
    rtb_H[1 + (i << 1)] = (real32_T)tmp[i];
  }

  /* Product: '<S67>/Divide' incorporates:
   *  Constant: '<S67>/Constant'
   *  Product: '<S67>/Product1'
   */
  kf_quad = (vdy_wye_B->Time2Sec.Time2Sec * vdy_wye_B->Time2Sec.Time2Sec) * 0.5F;

  /* Embedded MATLAB: '<S37>/get_gain_bias' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/make_A_Q_R1/get_gain_bias': '<S71>:1' */
  /*  extract the gain control parameters */
  /* '<S71>:1:3' */
  rtb_Yk1 = vdy_wye_Q_gain_wld_p[0];

  /* '<S71>:1:4' */
  rtb_VectorConcatenate_idx = vdy_wye_Q_gain_wld_p[1];

  /* '<S71>:1:5' */

  /* Embedded MATLAB: '<S37>/q_gain_delta' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/make_A_Q_R1/q_gain_delta': '<S72>:1' */
  /*  this feature is deactivated the diff is always  */
  /* '<S72>:1:3' */
  rtb_diff_g = vdy_wye_Q_gain_wld_p[2];

  /* single(0.0000001);   */

  /* Sum: '<S37>/Sum1' incorporates:
   *  Product: '<S37>/Product'
   *  S-Function (ex_sfun_abs): '<S37>/diff_abs'
   */
  rtb_Yk1 = (CML_f_Abs( (real32_T)rtb_diff_g) * rtb_Yk1) +
    rtb_VectorConcatenate_idx;

  /* BusSelector: '<S67>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo_j = (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo;
  rtb_veh_lat_accel = (*vdy_wye_U_VDYInternalData_in).vdy_ye_out.veh_lat_accel;

  /* S-Function (sfix_bitop): '<S70>/Bitwise Operator' incorporates:
   *  Constant: '<S70>/bitmask'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_BitwiseOperator = (uint16_T)((*vdy_wye_U_VDYInputData).Frame.CaliMode &
    ((uint16_T)VDY_CAL_WHS_LOAD));

  /* Embedded MATLAB: '<S70>/get_bit' */
  vdy_wye_get_bit(rtb_BitwiseOperator, ((uint16_T)VDY_CAL_WHS_LOAD),
                  &vdy_wye_B->sf_get_bit);

  /* Embedded MATLAB: '<S77>/hold_last_10_values' incorporates:
   *  UnitDelay: '<S77>/hold_counter'
   *  UnitDelay: '<S77>/hold_value'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/make_A_Q_R1/R/hold_last_10_values/hold_last_10_values': '<S78>:1' */
  /*  Hold value 10 cycle if input value is zero */
  if (vdy_wye_B->sf_get_bit.y == 1) {
    /* '<S78>:1:4' */
    /* '<S78>:1:5' */
    rtb_Rroff = 1U;

    /* '<S78>:1:6' */
    rtb_counter_out = 0U;
  } else if ((rtb_Rroff != 0) || (vdy_wye_DWork->hold_counter_DSTATE > 10)) {
    /* '<S78>:1:8' */
    /* '<S78>:1:9' */
    /* '<S78>:1:10' */
    rtb_counter_out = 0U;
  } else {
    /* '<S78>:1:12' */
    rtb_Rroff = vdy_wye_DWork->hold_value_DSTATE;

    /* '<S78>:1:13' */
    rtb_counter_out = (uint8_T)(vdy_wye_DWork->hold_counter_DSTATE + 1);
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_TmpSignalConversionAtSFun_c[0] = kf_quad;
  rtb_TmpSignalConversionAtSFun_c[1] = vdy_wye_B->Time2Sec.Time2Sec;

  /* Embedded MATLAB: '<S67>/makeQ' incorporates:
   *  Constant: '<S67>/sigma_model'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/make_A_Q_R1/Q/makeQ': '<S74>:1' */
  /*  calculates the model noise matrix Q */
  /*  and the noise for the drift */
  /* '<S74>:1:4' */
  sigma_model_gain[0] = vdy_wye_Q_sigmas_wld_p[0] * rtb_Yk1;
  sigma_model_gain[1] = vdy_wye_Q_sigmas_wld_p[1] * rtb_Yk1;

  /*  if the velocity is over a specified value und the lat_accel too use the normal sigma value for the offset */
  /*  otherwise make the model offset drift noise very small so that it does nothing */
  /*  if ((veh_velocity >= vdy_wye_Q_sigmas_dyn_wld_p(1)) && (veh_lat_accel <= vdy_wye_Q_sigmas_dyn_wld_p(2) )) */
  /*  Q1 = (G.*sigma_model_gain)*(sigma_model_gain.*G)'; */
  /*  Q = [Q1 [0; 0]; 0 0 sigma_model(3)*sigma_model(3)*CycleTime*CycleTime]; */
  /*  else */
  /*  Q1 = (G.*sigma_model_gain)*(sigma_model_gain.*G)'; */
  /*  Q = [Q1 [0; 0]; 0 0 vdy_wye_Q_sigmas_dyn_off_p(3)*vdy_wye_Q_sigmas_dyn_off_p(3)*CycleTime*CycleTime]; */
  /*  end; */
  if (rtb_Rroff == 0) {
    /* '<S74>:1:14' */
    /* '<S74>:1:15' */
    /* '<S74>:1:16' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFun_c[i] *
        sigma_model_gain[i];
      sigma_model_gain_0[i] = sigma_model_gain[i] *
        rtb_TmpSignalConversionAtSFun_c[i];
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_TmpSignalConversionAtSFun_1[bitpos + (i << 1)] =
          rtb_TmpSignalConversionAtSFun_0[bitpos] * sigma_model_gain_0[i];
      }
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_Q_g[bitpos + (3 * i)] = rtb_TmpSignalConversionAtSFun_1[(i << 1) +
          bitpos];
      }
    }

    for (i = 0; i < 2; i++) {
      rtb_Q_g[i + 6] = 0.0F;
    }

    rtb_Q_g[2] = 0.0F;
    rtb_Q_g[5] = 0.0F;
    rtb_Q_g[8] = ((vdy_wye_Q_sigmas_wld_p[2] * vdy_wye_Q_sigmas_wld_p[2]) *
                  vdy_wye_B->Time2Sec.Time2Sec) * vdy_wye_B->Time2Sec.Time2Sec;
  } else {
    /* '<S74>:1:18' */
    /* '<S74>:1:19' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFun_c[i] *
        sigma_model_gain[i];
      sigma_model_gain_0[i] = sigma_model_gain[i] *
        rtb_TmpSignalConversionAtSFun_c[i];
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_TmpSignalConversionAtSFun_1[bitpos + (i << 1)] =
          rtb_TmpSignalConversionAtSFun_0[bitpos] * sigma_model_gain_0[i];
      }
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_Q_g[bitpos + (3 * i)] = rtb_TmpSignalConversionAtSFun_1[(i << 1) +
          bitpos];
      }
    }

    for (i = 0; i < 2; i++) {
      rtb_Q_g[i + 6] = 0.0F;
    }

    rtb_Q_g[2] = 0.0F;
    rtb_Q_g[5] = 0.0F;
    rtb_Q_g[8] = ((vdy_wye_Q_sigmas_dyn_off_wld_p *
                   vdy_wye_Q_sigmas_dyn_off_wld_p) *
                  vdy_wye_B->Time2Sec.Time2Sec) * vdy_wye_B->Time2Sec.Time2Sec;
  }

  /* UnitDelay: '<S33>/P_delay_wld' */
  for (i = 0; i < 9; i++) {
    rtb_vdy_sfunc_HPHt_o2[i] = vdy_wye_DWork->P_delay_wld_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S46>/vdy_s-func_A_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    vdy_wye_B->sf_make_A_matrix.A, (real32_T*)rtb_vdy_sfunc_HPHt_o2, rtb_Ht_c,
    (uint8_T)3, (uint8_T)3, (uint8_T)3);

  /* Math: '<S33>/At' */
  for (i = 0; i < 3; i++) {
    for (bitpos = 0; bitpos < 3; bitpos++) {
      rtb_vdy_sfunc_HPHt_o2[bitpos + (3 * i)] = vdy_wye_B->sf_make_A_matrix.A[(3
        * bitpos) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S46>/vdy_s-func_A_P_At' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_Ht_c,
    (real32_T*)rtb_vdy_sfunc_HPHt_o2, rtb_KH_g, (uint8_T)3, (uint8_T)3, (uint8_T)
    3);

  /* Sum: '<S33>/APA_Q' */
  for (i = 0; i < 9; i++) {
    rtb_P_pred[i] = rtb_Q_g[i] + rtb_KH_g[i];
  }

  /* S-Function (MatrixMultiplication): '<S47>/vdy_s-func_H_P' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_H,
    (real32_T*)rtb_P_pred, rtb_vdy_sfunc_H_P_o2, (uint8_T)3, (uint8_T)2,
    (uint8_T)3);

  /* Math: '<S33>/Ht' */
  for (i = 0; i < 2; i++) {
    for (bitpos = 0; bitpos < 3; bitpos++) {
      rtb_Ht[bitpos + (3 * i)] = rtb_H[(bitpos << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S47>/vdy_s-func_H_P_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_H_P_o2, (real32_T*)rtb_Ht, rtb_vdy_sfunc_HP_Ht_o2, (uint8_T)3,
    (uint8_T)2, (uint8_T)2);

  /* Sum: '<S33>/HPH_R' */
  for (i = 0; i < 4; i++) {
    rtb_HPHt_R[i] = rtb_R_out_p[i] + rtb_vdy_sfunc_HP_Ht_o2[i];
  }

  /* Embedded MATLAB: '<S38>/Matrix_Inversion_2x2' */
  vdy_matrix_inversion_2x2(rtb_HPHt_R, &vdy_wye_B->sf_Matrix_Inversion_2x2);

  /* Embedded MATLAB: '<S33>/Reset_x_pred' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/Reset_x_pred': '<S41>:1' */
  if (vdy_wye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S41>:1:4' */
    /* '<S41>:1:6' */
    rtb_x_pred_out[0] = 0.0F;
    rtb_x_pred_out[1] = 0.0F;
    rtb_x_pred_out[2] = rtb_x_post[2];
  } else {
    /* '<S41>:1:10' */
    for (i = 0; i < 3; i++) {
      rtb_x_pred_out[i] = rtb_x_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_Ht, rtb_P_predHt, (uint8_T)3, (uint8_T)3, (uint8_T)2);

  /* If: '<S38>/If' incorporates:
   *  ActionPort: '<S49>/Action Port'
   *  ActionPort: '<S50>/Action Port'
   *  SubSystem: '<S38>/calculate the gain'
   *  SubSystem: '<S38>/set gain to default value'
   */
  if (!vdy_wye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* S-Function (MatrixMultiplication): '<S49>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_predHt,
      (real32_T*)vdy_wye_B->sf_Matrix_Inversion_2x2.HPHt_R_inv, rtb_K, (uint8_T)
      2, (uint8_T)3, (uint8_T)2);
  } else {
    /* Constant: '<S50>/Constant' */
    for (i = 0; i < 6; i++) {
      rtb_K[i] = vdy_wye_K_wld_default_p[(i)];
    }
  }

  /* Sum: '<S33>/z_Hx' */
  rtb_nu[0] = frfilt - rtb_hx[0];
  rtb_nu[1] = refilt - rtb_hx[1];

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_nu, rtb_nu_h, (uint8_T)2, (uint8_T)3, (uint8_T)1);

  /* Embedded MATLAB: '<S33>/init_x_yaw1' incorporates:
   *  Sum: '<S33>/x_Knu'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/init_x_yaw1': '<S45>:1' */
  /*  If Wld_Control is 1, so no wld should be leard. */
  /*  and the wld state in the filter is not updated */
  /* '<S45>:1:5' */
  for (i = 0; i < 3; i++) {
    rtb_x_out[i] = rtb_x_pred_out[i] + rtb_nu_h[i];
  }

  /*  if 1 don't update wld */
  if (rtb_Rroff == 1) {
    /* '<S45>:1:7' */
    /* '<S45>:1:8' */
    rtb_x_out[2] = rtb_x_pred_out[2];
  }

  /* Embedded MATLAB: '<S82>/adapt_R_matrix' incorporates:
   *  Constant: '<S82>/R'
   */
  /* Embedded MATLAB Function 'make_A_Q_R/R/adapt_R_matrix': '<S89>:1' */
  /*  build the R matrix */
  /* '<S89>:1:3' */
  for (i = 0; i < 9; i++) {
    rtb_Q_g[i] = vdy_wye_R_p[(i)];
  }

  /* '<S89>:1:4' */
  rtb_R_onoff = TRUE;
  if (((((int32_T)rtb_R_onoff_front) == 0) || (((int32_T)rtb_R_onoff_rear) == 0))
      || (((int32_T)rtb_R_yaw_valid) == 0)) {
    /* '<S89>:1:5' */
    /* '<S89>:1:6' */
    for (i = 0; i < 9; i++) {
      rtb_Q_g[i] = vdy_wye_R_p[(i)] * 10000.0F;
    }

    /* '<S89>:1:7' */
    rtb_R_onoff = FALSE;
  }

  /*  if sum variance of ratio front is above  */
  if (WldFactFront > vdy_wye_R_control_p) {
    /* '<S89>:1:11' */
    /* '<S89>:1:12' */
    rtb_Q_g[0] = rtb_Q_g[0] * 100000.0F;
  }

  /*  if sum variance of ratio rear is above  */
  if (rtb_VectorConcatenate_idx_0 > vdy_wye_R_control_p) {
    /* '<S89>:1:16' */
    /* '<S89>:1:17' */
    rtb_Q_g[4] = rtb_Q_g[4] * 100000.0F;
  }

  /*  if (R_onoff_front == true) */
  /*      R_out(1,1) = R_in(1,1)*R_quot_front;     */
  /*  else */
  /*      R_out(1,1) = R_in(1,1) * 10000; */
  /*  end; */
  /*   */
  /*  if (R_onoff_rear == true) */
  /*      R_out(2,2) = R_in(2,2)*R_quot_rear;     */
  /*  else */
  /*      R_out(2,2) = R_in(2,2) * 10000; */
  /*  end; */
  /*   */
  /*  if (R_yaw_valid == false) */
  /*      R_out(3,3) = R_in(3,3) * 10000; */
  /*  end; */

  /* Outputs for atomic SubSystem: '<S9>/Time2Sec' */
  vdy_wye_Time2Sec(rtb_CycleTime, &vdy_wye_B->Time2Sec_l);

  /* end of Outputs for SubSystem: '<S9>/Time2Sec' */

  /* Product: '<S81>/Divide' incorporates:
   *  Constant: '<S81>/Constant'
   *  Product: '<S81>/Product1'
   */
  kf_quad = (vdy_wye_B->Time2Sec_l.Time2Sec * vdy_wye_B->Time2Sec_l.Time2Sec) *
    0.5F;

  /* Embedded MATLAB: '<S9>/get_gain_bias' */
  /* Embedded MATLAB Function 'make_A_Q_R/get_gain_bias': '<S85>:1' */
  /*  extract the gain control parameters */
  /* '<S85>:1:3' */
  rtb_Yk1 = vdy_wye_Q_gain_p[0];

  /* '<S85>:1:4' */
  rtb_VectorConcatenate_idx = vdy_wye_Q_gain_p[1];

  /* '<S85>:1:5' */

  /* Embedded MATLAB: '<S9>/q_gain_delta' */
  /* Embedded MATLAB Function 'make_A_Q_R/q_gain_delta': '<S86>:1' */
  /*  this feature is deactivated the diff is always  */
  /* '<S86>:1:3' */
  rtb_diff_n = vdy_wye_Q_gain_p[2];

  /* single(0.0000001);   */

  /* Sum: '<S9>/Sum1' incorporates:
   *  Product: '<S9>/Product'
   *  S-Function (ex_sfun_abs): '<S9>/abs_V_pred'
   */
  rtb_Yk1 = (CML_f_Abs( (real32_T)rtb_diff_n) * rtb_Yk1) +
    rtb_VectorConcatenate_idx;

  /* BusSelector: '<S81>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo_h = (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo;
  rtb_veh_lat_accel_h = (*vdy_wye_U_VDYInternalData_in).vdy_ye_out.veh_lat_accel;
  rtb_veh_accel = (*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_accel;

  /* S-Function (sfix_bitop): '<S84>/Bitwise Operator' incorporates:
   *  Constant: '<S84>/bitmask'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_BitwiseOperator_c = (uint16_T)((*vdy_wye_U_VDYInputData).Frame.CaliMode &
                                     ((uint16_T)VDY_CAL_YWR_OFFS_DYN));

  /* Embedded MATLAB: '<S84>/get_bit' */
  vdy_wye_get_bit(rtb_BitwiseOperator_c, ((uint16_T)VDY_CAL_YWR_OFFS_DYN),
                  &vdy_wye_B->sf_get_bit_i);

  /* SignalConversion: '<S88>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_hx[0] = kf_quad;
  rtb_hx[1] = vdy_wye_B->Time2Sec_l.Time2Sec;

  /* Embedded MATLAB: '<S81>/makeQ' incorporates:
   *  BusSelector: '<S81>/Bus Selector'
   *  Constant: '<S81>/sigma_model'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S81>/lat_accel_abs'
   *  S-Function (ex_sfun_abs): '<S81>/veh_accel_abs'
   *  S-Function (ex_sfun_abs): '<S81>/veh_velo_abs'
   */
  /* Embedded MATLAB Function 'make_A_Q_R/Q/makeQ': '<S88>:1' */
  /*  calculates the model noise matrix Q */
  /*  and the noise for the drift */
  /* '<S88>:1:4' */
  sigma_model_gain[0] = vdy_wye_Q_sigmas_p[0] * rtb_Yk1;
  sigma_model_gain[1] = vdy_wye_Q_sigmas_p[1] * rtb_Yk1;

  /*  if the velocity is over a specified value und the lat_accel too use the normal sigma value for the offset */
  /*  otherwise make the model offset drift noise very small so that it does nothing */
  if ((((CML_f_Abs( (real32_T)rtb_veh_velo_h) >= vdy_wye_Q_sigmas_dyn_off_p[0]) &&
        (CML_f_Abs( (real32_T)rtb_veh_lat_accel_h) <=
         vdy_wye_Q_sigmas_dyn_off_p[1])) && (CML_f_Abs( (real32_T)rtb_veh_accel)
        <= vdy_wye_Q_sigmas_dyn_off_p[3])) && (rtb_sub_abs <=
       vdy_wye_Q_sigmas_dyn_off_p[4])) {
    /* '<S88>:1:7' */
    /* '<S88>:1:8' */
    /* '<S88>:1:9' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_0[i] = rtb_hx[i] * sigma_model_gain[i];
      sigma_model_gain_0[i] = sigma_model_gain[i] * rtb_hx[i];
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_R_out_p[bitpos + (i << 1)] = rtb_TmpSignalConversionAtSFun_0[bitpos]
          * sigma_model_gain_0[i];
      }
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_Q_m[bitpos + (3 * i)] = rtb_R_out_p[(i << 1) + bitpos];
      }
    }

    for (i = 0; i < 2; i++) {
      rtb_Q_m[i + 6] = 0.0F;
    }

    rtb_Q_m[2] = 0.0F;
    rtb_Q_m[5] = 0.0F;
    rtb_Q_m[8] = ((vdy_wye_Q_sigmas_p[2] * vdy_wye_Q_sigmas_p[2]) *
                  vdy_wye_B->Time2Sec_l.Time2Sec) *
      vdy_wye_B->Time2Sec_l.Time2Sec;

    /* '<S88>:1:10' */
    rtb_init = 0U;
  } else {
    /* '<S88>:1:12' */
    /* '<S88>:1:13' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_0[i] = rtb_hx[i] * sigma_model_gain[i];
      sigma_model_gain_0[i] = sigma_model_gain[i] * rtb_hx[i];
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_R_out_p[bitpos + (i << 1)] = rtb_TmpSignalConversionAtSFun_0[bitpos]
          * sigma_model_gain_0[i];
      }
    }

    for (i = 0; i < 2; i++) {
      for (bitpos = 0; bitpos < 2; bitpos++) {
        rtb_Q_m[bitpos + (3 * i)] = rtb_R_out_p[(i << 1) + bitpos];
      }
    }

    for (i = 0; i < 2; i++) {
      rtb_Q_m[i + 6] = 0.0F;
    }

    rtb_Q_m[2] = 0.0F;
    rtb_Q_m[5] = 0.0F;
    rtb_Q_m[8] = ((vdy_wye_Q_sigmas_dyn_off_p[2] * vdy_wye_Q_sigmas_dyn_off_p[2])
                  * vdy_wye_B->Time2Sec_l.Time2Sec) *
      vdy_wye_B->Time2Sec_l.Time2Sec;

    /* '<S88>:1:14' */
    rtb_init = 1U;
  }

  /*  if the deviation of the front or rear axis offset is above 1.0 do not use the */
  if (((*vdy_wye_U_VDYInternalData_in).
       vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev >= 1.0F) ||
      ((*vdy_wye_U_VDYInternalData_in).
       vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev >= 1.0F)) {
    /* '<S88>:1:18' */
    /* '<S88>:1:19' */
    rtb_init = 1U;
  }

  /*  if the ywr off dyn calibration is on, switch off dyn yaw rate offset estimation */
  if (vdy_wye_B->sf_get_bit_i.y == 1) {
    /* '<S88>:1:23' */
    /* '<S88>:1:24' */
    rtb_init = 1U;
  }

  /* Embedded MATLAB: '<S80>/make_A_matrix' */
  vdy_wye_make_A_matrix(vdy_wye_B->Time2Sec_l.Time2Sec,
                        &vdy_wye_B->sf_make_A_matrix_d);

  /* Embedded MATLAB: '<S2>/init_P_yaw' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S2>/P_delay_dyn_off'
   */
  /* Embedded MATLAB Function 'KF/init_P_yaw': '<S18>:1' */
  /*  Init P matrix with external yaw rate offset variance */
  /* '<S18>:1:4' */
  for (i = 0; i < 9; i++) {
    rtb_P_post_e[i] = vdy_wye_DWork->P_delay_dyn_off_DSTATE[(i)];
  }

  if ((((*vdy_wye_U_VDYInternalData_in).vdy_offsets_in.vdy_yaw_offset.state == 1)
       || ((*vdy_wye_U_VDYInternalData_in).vdy_offsets_in.vdy_yaw_offset.state ==
           2)) || ((*vdy_wye_U_VDYInternalData_in).
                   vdy_offsets_in.vdy_yaw_offset.state == 3)) {
    /* '<S18>:1:5' */
    /* '<S18>:1:6' */
    rtb_P_post_e[8] = (*vdy_wye_U_VDYInternalData_in).
      vdy_offsets_in.vdy_yaw_offset.var;
  }

  /* S-Function (MatrixMultiplication): '<S20>/vdy_s-func_AP' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    vdy_wye_B->sf_make_A_matrix_d.A, (real32_T*)rtb_P_post_e, rtb_KH_g, (uint8_T)
    3, (uint8_T)3, (uint8_T)3);

  /* Math: '<S2>/At' */
  for (i = 0; i < 3; i++) {
    for (bitpos = 0; bitpos < 3; bitpos++) {
      rtb_Ht_c[bitpos + (3 * i)] = vdy_wye_B->sf_make_A_matrix_d.A[(3 * bitpos)
        + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S20>/vdy_s-func_A_P_At' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH_g,
    (real32_T*)rtb_Ht_c, rtb_vdy_sfunc_HPHt_o2, (uint8_T)3, (uint8_T)3, (uint8_T)
    3);

  /* Sum: '<S2>/APA_Q' */
  for (i = 0; i < 9; i++) {
    rtb_P_pred_n[i] = rtb_Q_m[i] + rtb_vdy_sfunc_HPHt_o2[i];
  }

  /* S-Function (MatrixMultiplication): '<S21>/vdy_s-func_H_P' incorporates:
   *  Constant: '<S2>/H_const'
   */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    (&(vdy_wye_H_p[0])), (real32_T*)rtb_P_pred_n, rtb_KH_g, (uint8_T)3, (uint8_T)
    3, (uint8_T)3);

  /* Math: '<S2>/Ht' incorporates:
   *  Constant: '<S2>/H_const'
   */
  for (i = 0; i < 3; i++) {
    for (bitpos = 0; bitpos < 3; bitpos++) {
      rtb_Ht_c[bitpos + (3 * i)] = vdy_wye_H_p[(3 * bitpos) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S21>/vdy_s-func_HPHt' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH_g,
    (real32_T*)rtb_Ht_c, rtb_vdy_sfunc_HPHt_o2, (uint8_T)3, (uint8_T)3, (uint8_T)
    3);

  /* Sum: '<S2>/HPH_R' */
  for (i = 0; i < 9; i++) {
    rtb_HPHt_R_o[i] = rtb_Q_g[i] + rtb_vdy_sfunc_HPHt_o2[i];
  }

  /* Embedded MATLAB: '<S14>/Matrix_Inversion_3x3' */
  vdy_matrix_inversion_3x3(rtb_HPHt_R_o, &vdy_wye_B->sf_Matrix_Inversion_3x3);

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred_n,
    (real32_T*)rtb_Ht_c, rtb_P_predHt_n, (uint8_T)3, (uint8_T)3, (uint8_T)3);

  /* If: '<S14>/If' incorporates:
   *  ActionPort: '<S23>/Action Port'
   *  ActionPort: '<S24>/Action Port'
   *  SubSystem: '<S14>/calculate the gain'
   *  SubSystem: '<S14>/set gain to default value'
   */
  if (!vdy_wye_B->sf_Matrix_Inversion_3x3.det_flag) {
    /* S-Function (MatrixMultiplication): '<S23>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1_o = vdy_matrix_multiplication( (real32_T*)
      rtb_P_predHt_n, (real32_T*)vdy_wye_B->sf_Matrix_Inversion_3x3.HPHt_R_inv,
      rtb_K_d, (uint8_T)3, (uint8_T)3, (uint8_T)3);
  } else {
    /* Constant: '<S24>/default_K_gain' */
    for (i = 0; i < 9; i++) {
      rtb_K_d[i] = vdy_wye_K_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_KH' incorporates:
   *  Constant: '<S2>/H_const'
   */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K_d,
    (real32_T*)(&(vdy_wye_H_p[0])), rtb_KH_g, (uint8_T)3, (uint8_T)3, (uint8_T)3);

  /* Sum: '<S2>/1_KH' incorporates:
   *  Constant: '<S2>/eye'
   */
  for (i = 0; i < 9; i++) {
    rtb_KH_g[i] = vdy_wye_I_matrix_p[(i)] - rtb_KH_g[i];
  }

  /* Embedded MATLAB: '<S2>/Reset_P_pred' */
  /* Embedded MATLAB Function 'KF/Reset_P_pred': '<S15>:1' */
  if (vdy_wye_B->sf_Matrix_Inversion_3x3.det_flag) {
    /* '<S15>:1:4' */
    /* '<S15>:1:6' */
    for (i = 0; i < 9; i++) {
      rtb_P_pred_out_p[i] = vdy_wye_P_init_p[(i)];
    }
  } else {
    /* '<S15>:1:10' */
    for (i = 0; i < 9; i++) {
      rtb_P_pred_out_p[i] = rtb_P_pred_n[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH_g,
    (real32_T*)rtb_P_pred_out_p, rtb_P_post_p, (uint8_T)3, (uint8_T)3, (uint8_T)
    3);

  /* Embedded MATLAB: '<Root>/correct_variance' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'correct_variance': '<S5>:1' */
  /*  the output variance for this module is rasied at low speed */
  /*  if input values are not valid set output variance to high value */
  /*  if the velocity is in a low speed range eg. between 1 and 10 m/s  */
  /*  the variance is linear increasing to the bottom limit with the velocity */
  /*  below this botom limit the variance is constant */
  /*  if the velocity if above the upper limit nothing is done */
  if (((int32_T)rtb_R_onoff) == 1) {
    /* '<S5>:1:8' */
    if (((*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo >
         vdy_wye_P_correct_p[0]) && ((*vdy_wye_U_VDYInternalData_in).
         vdy_ve_out.veh_velo < vdy_wye_P_correct_p[1])) {
      /* '<S5>:1:9' */
      /* '<S5>:1:10' */
      rtb_Yk1 = ((*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
                 vdy_wye_P_correct_p[0]) * vdy_wye_P_correct_p[2];
      for (i = 0; i < 3; i++) {
        rtb_x_pred_out[i] = (rtb_P_post_p[i << 2] + (vdy_wye_P_correct_p[3] -
          rtb_Yk1)) + 6.0E-5F;
      }
    } else if ((*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo <=
               vdy_wye_P_correct_p[0]) {
      /* '<S5>:1:11' */
      /* '<S5>:1:12' */
      for (i = 0; i < 3; i++) {
        rtb_x_pred_out[i] = (rtb_P_post_p[i << 2] + vdy_wye_P_correct_p[3]) +
          6.0E-5F;
      }
    } else {
      /* '<S5>:1:14' */
      for (i = 0; i < 3; i++) {
        rtb_x_pred_out[i] = rtb_P_post_p[i << 2] + 6.0E-5F;
      }
    }
  } else {
    /* '<S5>:1:17' */
    for (i = 0; i < 3; i++) {
      rtb_x_pred_out[i] = vdy_wye_P_correct_p[3];
    }
  }

  /* Embedded MATLAB: '<S2>/init_x_yaw' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'KF/init_x_yaw': '<S19>:1' */
  /*  Init x state with external yaw rate offset variance */
  /*  and limit estimated yaw rate offset */
  /* '<S19>:1:5' */
  for (i = 0; i < 3; i++) {
    /* UnitDelay: '<S2>/x_delay_dyn_off' */
    rtb_x_post[i] = vdy_wye_DWork->x_delay_dyn_off_DSTATE[(i)];
    rtb_x_post_f[i] = vdy_wye_DWork->x_delay_dyn_off_DSTATE[(i)];
  }

  /*  if  */
  if (vdy_wye_DWork->x_delay_dyn_off_DSTATE[2] < -0.04F) {
    /* '<S19>:1:8' */
    /* '<S19>:1:9' */
    rtb_x_post_f[2] = -0.04F;
  }

  /*  if  */
  if (vdy_wye_DWork->x_delay_dyn_off_DSTATE[2] > 0.05F) {
    /* '<S19>:1:12' */
    /* '<S19>:1:13' */
    rtb_x_post_f[2] = 0.05F;
  }

  if ((((*vdy_wye_U_VDYInternalData_in).vdy_offsets_in.vdy_yaw_offset.state == 1)
       || ((*vdy_wye_U_VDYInternalData_in).vdy_offsets_in.vdy_yaw_offset.state ==
           2)) || ((*vdy_wye_U_VDYInternalData_in).
                   vdy_offsets_in.vdy_yaw_offset.state == 3)) {
    /* '<S19>:1:16' */
    /* '<S19>:1:17' */
    rtb_x_post_f[2] = (*vdy_wye_U_VDYInternalData_in).
      vdy_offsets_in.vdy_yaw_offset.offset;
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    vdy_wye_B->sf_make_A_matrix_d.A, (real32_T*)rtb_x_post_f, rtb_x_pred_g,
    (uint8_T)3, (uint8_T)3, (uint8_T)1);

  /* Embedded MATLAB: '<S2>/Reset_x_pred' */
  /* Embedded MATLAB Function 'KF/Reset_x_pred': '<S16>:1' */
  if (vdy_wye_B->sf_Matrix_Inversion_3x3.det_flag) {
    /* '<S16>:1:4' */
    /* '<S16>:1:6' */
    rtb_x_pred_out_f[0] = 0.0F;
    rtb_x_pred_out_f[1] = 0.0F;
    rtb_x_pred_out_f[2] = rtb_x_post[2];
  } else {
    /* '<S16>:1:10' */
    for (i = 0; i < 3; i++) {
      rtb_x_pred_out_f[i] = rtb_x_pred_g[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_Hx' incorporates:
   *  Constant: '<S2>/H_const'
   */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    (&(vdy_wye_H_p[0])), (real32_T*)rtb_x_pred_g, rtb_nu_h, (uint8_T)3, (uint8_T)
    3, (uint8_T)1);

  /* Sum: '<S2>/z_Hx' */
  rtb_x_post[0] = rtb_frfiltWithWldEst;
  rtb_x_post[1] = rtb_refiltWithWldEst;
  rtb_x_post[2] = rtb_VectorConcatenate_idx_1;
  for (i = 0; i < 3; i++) {
    rtb_nu_h[i] = rtb_x_post[i] - rtb_nu_h[i];
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K_d,
    (real32_T*)rtb_nu_h, rtb_Knu, (uint8_T)3, (uint8_T)3, (uint8_T)1);

  /* Embedded MATLAB: '<S2>/check_yaw_offset' incorporates:
   *  Sum: '<S2>/x_Knu'
   */
  /* Embedded MATLAB Function 'KF/check_yaw_offset': '<S17>:1' */
  /*  If EG_Control is 1, so no EG should be leard. */
  /*  and the EG state in the filter is not updated */
  /* '<S17>:1:5' */
  for (i = 0; i < 3; i++) {
    rtb_x_post[i] = rtb_x_pred_out_f[i] + rtb_Knu[i];
  }

  /*  if 0 don't update eg */
  if (rtb_init == 1) {
    /* '<S17>:1:7' */
    /* '<S17>:1:8' */
    rtb_x_post[2] = rtb_x_pred_out_f[2];
  }

  /* Embedded MATLAB: '<S1>/init_x_yaw' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S1>/last_dyn_yaw_offset'
   */
  /* Embedded MATLAB Function 'Check_yaw_offset/init_x_yaw': '<S13>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S13>:1:5' */
  rtb_VectorConcatenate_idx_1 = vdy_wye_DWork->last_dyn_yaw_offset_DSTATE;
  if ((((*vdy_wye_U_VDYInternalData_in).vdy_offsets_in.vdy_yaw_offset.state == 1)
       || ((*vdy_wye_U_VDYInternalData_in).vdy_offsets_in.vdy_yaw_offset.state ==
           2)) || ((*vdy_wye_U_VDYInternalData_in).
                   vdy_offsets_in.vdy_yaw_offset.state == 3)) {
    /* '<S13>:1:8' */
    /* '<S13>:1:9' */
    rtb_VectorConcatenate_idx_1 = (*vdy_wye_U_VDYInternalData_in).
      vdy_offsets_in.vdy_yaw_offset.offset;
  }

  /* Embedded MATLAB: '<S1>/check_yaw_offset' incorporates:
   *  UnitDelay: '<S1>/dyn_yaw_off_overt_count'
   *  UnitDelay: '<S1>/last_dyn_yaw_offset_sign'
   */
  /* Embedded MATLAB Function 'Check_yaw_offset/check_yaw_offset': '<S12>:1' */
  /*  check if the yaw rate offset is above or below a resolution threshold */
  /*  if yes start a counter and count a specified time */
  /*  after this time use the next yaw rate offset resolution step. */
  /* '<S12>:1:5' */
  /* '<S12>:1:7' */
  rtb_Yk1 = rtb_x_post[2] - rtb_VectorConcatenate_idx_1;

  /* '<S12>:1:8' */
  rtb_sign_out = vdy_wye_DWork->last_dyn_yaw_offset_sign_DSTATE;
  if ((rtb_Yk1 > vdy_wye_yaw_offset_const_p[0]) || (rtb_Yk1 <
       (-vdy_wye_yaw_offset_const_p[0]))) {
    /* '<S12>:1:10' */
    if (vdy_wye_DWork->dyn_yaw_off_overt_count_DSTATE <= 0.0001F) {
      /* '<S12>:1:11' */
      if (rtb_Yk1 > 0.0F) {
        /* '<S12>:1:12' */
        /* '<S12>:1:13' */
        rtb_sign_out = 1;
      } else {
        if (rtb_Yk1 < 0.0F) {
          /* '<S12>:1:14' */
          /* '<S12>:1:15' */
          rtb_sign_out = -1;
        }
      }
    }

    /* '<S12>:1:18' */
    vx_quad = vdy_wye_DWork->dyn_yaw_off_overt_count_DSTATE + 1.0F;
  } else {
    /* '<S12>:1:20' */
    vx_quad = 0.0F;
  }

  /* '<S12>:1:23' */
  if (((vx_quad * ((real32_T)rtb_CycleTime)) / 1000.0F) >
      vdy_wye_yaw_offset_const_p[1]) {
    /* '<S12>:1:25' */
    if (vdy_wye_DWork->last_dyn_yaw_offset_sign_DSTATE == 1) {
      /* '<S12>:1:26' */
      /* '<S12>:1:27' */
      rtb_VectorConcatenate_idx_1 += vdy_wye_yaw_offset_const_p[0];
    } else if (vdy_wye_DWork->last_dyn_yaw_offset_sign_DSTATE == -1) {
      /* '<S12>:1:28' */
      /* '<S12>:1:29' */
      rtb_VectorConcatenate_idx_1 -= vdy_wye_yaw_offset_const_p[0];
    } else {
      /* '<S12>:1:31' */
    }
  }

  /* Embedded MATLAB: '<S93>/adapt_R_matrix' incorporates:
   *  Constant: '<S93>/R'
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S93>/whl_yaw_off_control'
   */
  /* Embedded MATLAB Function 'make_whl_yaw_A_Q_R/R/adapt_R_matrix': '<S100>:1' */
  /*  build the R matrix */
  /* '<S100>:1:3' */
  for (i = 0; i < 4; i++) {
    rtb_R_out_p[i] = vdy_wye_yaw_R_p[(i)];
  }

  /* '<S100>:1:4' */
  rtb_R_onoff = TRUE;
  if ((((int32_T)rtb_R_onoff_front) == 0) || (((int32_T)rtb_R_onoff_rear) == 0))
  {
    /* '<S100>:1:6' */
    /* '<S100>:1:7' */
    for (i = 0; i < 4; i++) {
      rtb_R_out_p[i] = vdy_wye_yaw_R_p[(i)] * 10000.0F;
    }

    /* '<S100>:1:8' */
    rtb_R_onoff = FALSE;
  }

  /*  if sum variance of ratio front is above  */
  if (WldFactFront > vdy_wye_R_control_p) {
    /* '<S100>:1:12' */
    /* '<S100>:1:13' */
    rtb_R_out_p[0] = rtb_R_out_p[0] * 100000.0F;
  }

  /*  if sum variance of ratio rear is above  */
  if (rtb_VectorConcatenate_idx_0 > vdy_wye_R_control_p) {
    /* '<S100>:1:17' */
    /* '<S100>:1:18' */
    rtb_R_out_p[3] = rtb_R_out_p[3] * 100000.0F;
  }

  /*  if both sum variance of ratio front is above  */
  if ((WldFactFront > vdy_wye_R_control_p) && (rtb_VectorConcatenate_idx_0 >
       vdy_wye_R_control_p)) {
    /* '<S100>:1:22' */
    /* '<S100>:1:23' */
    for (i = 0; i < 4; i++) {
      rtb_R_out_p[i] = vdy_wye_yaw_R_p[(i)] * 10000.0F;
    }

    /* '<S100>:1:24' */
    rtb_R_onoff = FALSE;
  }

  /* '<S100>:1:28' */
  rtb_TP_yaw_off_control_out = 0;

  /* '<S100>:1:29' */
  rtb_Reset = 0U;

  /* '<S100>:1:30' */
  rtb_TP_init = 0;

  /*  if the deviation of the front or rear axis offset is above 1.0 do not use the */
  /*  wheel yaw rate */
  if ((((*vdy_wye_U_VDYInternalData_in).
        vdy_offsets_in.vdy_whs_offset.offset_ratio_front_dev >= 1.0F) ||
       ((*vdy_wye_U_VDYInternalData_in).
        vdy_offsets_in.vdy_whs_offset.offset_ratio_rear_dev >= 1.0F)) ||
      (((int32_T)rtb_R_onoff) == 0)) {
    /* '<S100>:1:34' */
    /* '<S100>:1:36' */
    rtb_TP_yaw_off_control_out = 1;

    /* '<S100>:1:37' */
    rtb_Reset = 1U;

    /* '<S100>:1:38' */
    rtb_TP_init = 1;
  }

  /*  if the TP filtered yaw off control is below 20 % Use the wheel yaw rate */
  if (vdy_wye_DWork->whl_yaw_off_control_DSTATE < 0.2F) {
    /* '<S100>:1:42' */
    /* '<S100>:1:43' */
    rtb_wye_yaw_off_control = 0U;
  } else {
    /* '<S100>:1:45' */
    rtb_wye_yaw_off_control = 1U;
  }

  /* Outputs for atomic SubSystem: '<S10>/Time2Sec' */
  vdy_wye_Time2Sec(rtb_CycleTime, &vdy_wye_B->Time2Sec_d);

  /* end of Outputs for SubSystem: '<S10>/Time2Sec' */

  /* Product: '<S92>/Divide' incorporates:
   *  Constant: '<S92>/Constant'
   *  Product: '<S92>/Product1'
   */
  rtb_VectorConcatenate_idx = (vdy_wye_B->Time2Sec_d.Time2Sec *
    vdy_wye_B->Time2Sec_d.Time2Sec) * 0.5F;

  /* UnitDelay: '<S10>/diff_raw_whl_est_whl_yaw' */
  rtb_Yk1 = vdy_wye_DWork->diff_raw_whl_est_whl_yaw_DSTATE;

  /* UnitDelay: '<S96>/T2' */
  kf_quad = vdy_wye_DWork->T2_DSTATE;

  /* UnitDelay: '<S96>/T1' */
  WldFactFront = vdy_wye_DWork->T1_DSTATE;

  /* UnitDelay: '<S96>/T0' */
  rtb_VectorConcatenate_idx_0 = vdy_wye_DWork->T0_DSTATE;

  /* Product: '<S96>/Divide' incorporates:
   *  Constant: '<S96>/filter_length'
   *  Sum: '<S96>/Add'
   *  UnitDelay: '<S96>/T3'
   */
  rtb_Divide_c = (((vdy_wye_DWork->T3_DSTATE + vdy_wye_DWork->T2_DSTATE) +
                   vdy_wye_DWork->T1_DSTATE) + vdy_wye_DWork->T0_DSTATE) * 0.25F;

  /* UnitDelay: '<S10>/last_est_whl_yaw_rate' */
  rtb_last_est_whl_yaw_rate = vdy_wye_DWork->last_est_whl_yaw_rate_DSTATE;

  /* Embedded MATLAB: '<S10>/q_gain_delta' incorporates:
   *  S-Function (ex_sfun_abs): '<S10>/abs_yaw_rate'
   *  S-Function (ex_sfun_abs): '<S10>/last_est_whl_yaw_rate_abs'
   *  UnitDelay: '<S10>/last_est_whl_yaw_rate'
   */
  /* Embedded MATLAB Function 'make_whl_yaw_A_Q_R/q_gain_delta': '<S97>:1' */
  /*  Note: In order to eliminate QAC Level-4 warnings, the if-condition below is rewritten with multiple if-elseif expressions. */
  /*  calculate the diff between estimated and real value */
  if (CML_f_Abs( (real32_T)rtb_Divide_c) >= 1.0E-7F) {
    /* '<S97>:1:5' */
    if (CML_f_Abs( (real32_T)rtb_last_est_whl_yaw_rate) >= 1.0E-7F) {
      /* '<S97>:1:6' */
      /* '<S97>:1:7' */
      rtb_diff = rtb_Divide_c - rtb_last_est_whl_yaw_rate;
    } else {
      /* '<S97>:1:9' */
      rtb_diff = rtb_Yk1;
    }
  } else {
    /* '<S97>:1:12' */
    rtb_diff = rtb_Yk1;
  }

  /* Embedded MATLAB: '<S10>/get_gain_bias' */
  /* Embedded MATLAB Function 'make_whl_yaw_A_Q_R/get_gain_bias': '<S95>:1' */
  /*  extract the gain control parameters */
  /* '<S95>:1:3' */
  /* '<S95>:1:4' */

  /* Sum: '<S10>/Sum1' incorporates:
   *  Product: '<S10>/Product'
   *  S-Function (ex_sfun_abs): '<S10>/diff_abs'
   */
  rtb_Yk1 = (CML_f_Abs( (real32_T)rtb_diff) * vdy_wye_yaw_Q_gain_p[0]) +
    vdy_wye_yaw_Q_gain_p[1];

  /* SignalConversion: '<S99>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_hx[0] = rtb_VectorConcatenate_idx;
  rtb_hx[1] = vdy_wye_B->Time2Sec_d.Time2Sec;

  /* Embedded MATLAB: '<S92>/makeQ' incorporates:
   *  Constant: '<S92>/sigma_model'
   */
  /* Embedded MATLAB Function 'make_whl_yaw_A_Q_R/Q/makeQ': '<S99>:1' */
  /*  calculates the model noise matrix Q */
  /*  and the noise for the drift */
  /* '<S99>:1:4' */
  sigma_model_gain[0] = vdy_wye_yaw_Q_sigmas_p[0] * rtb_Yk1;
  sigma_model_gain[1] = vdy_wye_yaw_Q_sigmas_p[1] * rtb_Yk1;

  /* '<S99>:1:5' */

  /* Embedded MATLAB: '<S91>/make_A_matrix' */
  /* Embedded MATLAB Function 'make_whl_yaw_A_Q_R/A/make_A_matrix': '<S98>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S98>:1:5' */
  rtb_A[0] = 1.0F;
  rtb_A[2] = vdy_wye_B->Time2Sec_d.Time2Sec;
  for (i = 0; i < 2; i++) {
    rtb_A[1 + (i << 1)] = (real32_T)i;
  }

  /* UnitDelay: '<S3>/P_delay_whl_yaw' */
  for (i = 0; i < 4; i++) {
    rtb_vdy_sfunc_HP_Ht_o2[i] = vdy_wye_DWork->P_delay_whl_yaw_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S28>/vdy_s-func_AP' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_vdy_sfunc_HP_Ht_o2, rtb_Ht_a, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Math: '<S3>/At' */
  for (i = 0; i < 2; i++) {
    for (bitpos = 0; bitpos < 2; bitpos++) {
      rtb_vdy_sfunc_HP_Ht_o2[bitpos + (i << 1)] = rtb_A[(bitpos << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S28>/vdy_s-func_A_P_At' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_Ht_a,
    (real32_T*)rtb_vdy_sfunc_HP_Ht_o2, rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Sum: '<S3>/APA_Q' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_0[i] = rtb_hx[i] * sigma_model_gain[i];
    sigma_model_gain_0[i] = sigma_model_gain[i] * rtb_hx[i];
  }

  for (i = 0; i < 2; i++) {
    for (bitpos = 0; bitpos < 2; bitpos++) {
      rtb_P_pred_nb[bitpos + (i << 1)] = rtb_KH[(i << 1) + bitpos] +
        (rtb_TmpSignalConversionAtSFun_0[bitpos] * sigma_model_gain_0[i]);
    }
  }

  /* S-Function (MatrixMultiplication): '<S29>/vdy_s-func_HP' incorporates:
   *  Constant: '<S3>/H_const'
   */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    (&(vdy_wye_H_yaw_p[0])), (real32_T*)rtb_P_pred_nb, rtb_KH, (uint8_T)2,
    (uint8_T)2, (uint8_T)2);

  /* Math: '<S3>/Ht' incorporates:
   *  Constant: '<S3>/H_const'
   */
  for (i = 0; i < 2; i++) {
    for (bitpos = 0; bitpos < 2; bitpos++) {
      rtb_Ht_a[bitpos + (i << 1)] = vdy_wye_H_yaw_p[(bitpos << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S29>/vdy_s-func_HP_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_Ht_a, rtb_vdy_sfunc_HP_Ht_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Sum: '<S3>/HPH_R' */
  for (i = 0; i < 4; i++) {
    rtb_HPHt_R_m[i] = rtb_R_out_p[i] + rtb_vdy_sfunc_HP_Ht_o2[i];
  }

  /* Embedded MATLAB: '<S25>/Matrix_Inversion_2x2' */
  vdy_matrix_inversion_2x2(rtb_HPHt_R_m, &vdy_wye_B->sf_Matrix_Inversion_2x2_c);

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred_nb,
    (real32_T*)rtb_Ht_a, rtb_P_predHt_g, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* If: '<S25>/If' incorporates:
   *  ActionPort: '<S31>/Action Port'
   *  ActionPort: '<S32>/Action Port'
   *  SubSystem: '<S25>/calculate the gain'
   *  SubSystem: '<S25>/set gain to default value'
   */
  if (!vdy_wye_B->sf_Matrix_Inversion_2x2_c.det_flag) {
    /* S-Function (MatrixMultiplication): '<S31>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1_b = vdy_matrix_multiplication( (real32_T*)
      rtb_P_predHt_g, (real32_T*)vdy_wye_B->sf_Matrix_Inversion_2x2_c.HPHt_R_inv,
      rtb_K_n, (uint8_T)2, (uint8_T)2, (uint8_T)2);
  } else {
    /* Constant: '<S32>/Constant' */
    for (i = 0; i < 4; i++) {
      rtb_K_n[i] = vdy_wye_K_yaw_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_KH' incorporates:
   *  Constant: '<S3>/H_const'
   */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K_n,
    (real32_T*)(&(vdy_wye_H_yaw_p[0])), rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Sum: '<S3>/1_KH' incorporates:
   *  Constant: '<S3>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH[i] = vdy_wye_I_matrix_yaw_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S3>/Reset_P_pred' */
  /* Embedded MATLAB Function 'KF_whl_yaw/Reset_P_pred': '<S26>:1' */
  if (vdy_wye_B->sf_Matrix_Inversion_2x2_c.det_flag) {
    /* '<S26>:1:4' */
    /* '<S26>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out_b[i] = vdy_wye_yaw_P_init_p[(i)];
    }
  } else {
    /* '<S26>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out_b[i] = rtb_P_pred_nb[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out_b, rtb_P_post_d, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Embedded MATLAB: '<Root>/correct_variance1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'correct_variance1': '<S6>:1' */
  /*  the output variance for this module is raised at low speed */
  /*  if input values are not valid set output variance to high value */
  /*  if the velocity is in a low speed range eg. between 1 and 10 m/s  */
  /*  the variance is linear increasing to the bottom limit with the velocity */
  /*  below this bottom limit the variance is constant */
  /*  if the velocity if above the upper limit nothing is done */
  if (rtb_wye_yaw_off_control == 0) {
    /* '<S6>:1:8' */
    if (((*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo >
         vdy_wye_yaw_P_correct_p[0]) && ((*vdy_wye_U_VDYInternalData_in).
         vdy_ve_out.veh_velo < vdy_wye_yaw_P_correct_p[1])) {
      /* '<S6>:1:9' */
      /* '<S6>:1:10' */
      rtb_Yk1 = ((*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
                 vdy_wye_yaw_P_correct_p[0]) * vdy_wye_yaw_P_correct_p[2];
      for (i = 0; i < 2; i++) {
        rtb_hx[i] = (rtb_P_post_d[3 * i] + (vdy_wye_yaw_P_correct_p[3] - rtb_Yk1))
          + vdy_wye_yaw_P_correct_p[4];
      }
    } else if ((*vdy_wye_U_VDYInternalData_in).vdy_ve_out.veh_velo <=
               vdy_wye_yaw_P_correct_p[0]) {
      /* '<S6>:1:11' */
      /* '<S6>:1:12' */
      for (i = 0; i < 2; i++) {
        rtb_hx[i] = (rtb_P_post_d[3 * i] + vdy_wye_yaw_P_correct_p[3]) +
          vdy_wye_yaw_P_correct_p[4];
      }
    } else {
      /* '<S6>:1:14' */
      for (i = 0; i < 2; i++) {
        rtb_hx[i] = rtb_P_post_d[3 * i] + vdy_wye_yaw_P_correct_p[4];
      }
    }
  } else {
    /* '<S6>:1:17' */
    for (i = 0; i < 2; i++) {
      rtb_hx[i] = vdy_wye_yaw_P_correct_p[3];
    }
  }

  /* UnitDelay: '<S3>/x_delay_whl_yaw' */
  for (i = 0; i < 2; i++) {
    rtb_x_post_bq[i] = vdy_wye_DWork->x_delay_whl_yaw_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_x_post_bq, rtb_x_pred_p, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S3>/Reset_x_pred' */
  /* Embedded MATLAB Function 'KF_whl_yaw/Reset_x_pred': '<S27>:1' */
  if (vdy_wye_B->sf_Matrix_Inversion_2x2_c.det_flag) {
    /* '<S27>:1:4' */
    /* '<S27>:1:6' */
    rtb_TmpSignalConversionAtSFun_c[0] = rtb_x_post_bq[0];
    rtb_TmpSignalConversionAtSFun_c[1] = 0.0F;
  } else {
    /* '<S27>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_c[i] = rtb_x_pred_p[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_Hx' incorporates:
   *  Constant: '<S3>/H_const'
   */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    (&(vdy_wye_H_yaw_p[0])), (real32_T*)rtb_x_pred_p, rtb_nu, (uint8_T)2,
    (uint8_T)2, (uint8_T)1);

  /* Sum: '<S3>/z_Hx' */
  rtb_TmpSignalConversionAtSFun_0[0] = rtb_frWithWldEst_wye;
  rtb_TmpSignalConversionAtSFun_0[1] = rtb_reWithWldEst_wye;
  for (i = 0; i < 2; i++) {
    rtb_nu[i] = rtb_TmpSignalConversionAtSFun_0[i] - rtb_nu[i];
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K_n,
    (real32_T*)rtb_nu, rtb_Knu_p, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S3>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_c[i] = rtb_TmpSignalConversionAtSFun_c[i] +
      rtb_Knu_p[i];
  }

  /* Embedded MATLAB: '<Root>/correct_yaw_rate' */
  /* Embedded MATLAB Function 'correct_yaw_rate': '<S7>:1' */
  /*  if input values are not valid set output yaw rate to 0 */
  if (rtb_wye_yaw_off_control == 0) {
    /* '<S7>:1:3' */
    /* '<S7>:1:4' */
    rtb_Yk1 = rtb_TmpSignalConversionAtSFun_c[0];
  } else {
    /* '<S7>:1:6' */
    rtb_Yk1 = 0.0F;
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  (*vdy_wye_Y_VDYInternalData_out) = (*vdy_wye_U_VDYInternalData_in);
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.front_whl_yaw_rate_filt_wld =
    rtb_frfiltWithWldEst;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.diff_whl_yaw_front_rear =
    rtb_sub_abs;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.rear_whl_yaw_rate_filt_wld =
    rtb_refiltWithWldEst;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.front_whl_yaw_rate_filt = frfilt;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.rear_whl_yaw_rate_filt = refilt;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.est_whl_load_dep_front =
    rtb_x_out[2];
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.wld_control = rtb_Rroff;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.gier_yaw_rate_offset_var =
    rtb_x_pred_out[2];
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.dyn_yaw_off_control = rtb_init;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.raw_est_yaw_offset = rtb_x_post[2];
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.gier_yaw_rate_offset =
    rtb_VectorConcatenate_idx_1;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.whl_yaw_rate_var = rtb_hx[0];
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.whl_yaw_rate = rtb_Yk1;
  (*vdy_wye_Y_VDYInternalData_out).vdy_wye_out.r_On_Off_control =
    rtb_wye_yaw_off_control;

  /* BusSelector: '<S35>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYNvData_in'
   */
  rtb_State_n = (*vdy_wye_U_VDYNvData_in).Read.State;

  /* Embedded MATLAB: '<S64>/Get_NVM_IO_State' */
  vdy_wye_Get_NVM_IO_State(((uint32_T)VDY_NVM_POS_WLD), rtb_State_n, 3U,
    &vdy_wye_B->sf_Get_NVM_IO_State_k);

  /* Outputs for atomic SubSystem: '<S35>/Time2Sec' */
  vdy_wye_Time2Sec(rtb_CycleTime, &vdy_wye_B->Time2Sec_n);

  /* end of Outputs for SubSystem: '<S35>/Time2Sec' */

  /* UnitDelay: '<S35>/trav_dist_reset' */
  rtb_R_onoff = vdy_wye_DWork->trav_dist_reset_DSTATE;

  /* Switch: '<S61>/Init' incorporates:
   *  Constant: '<S61>/Initial Condition'
   *  Logic: '<S61>/FixPt Logical Operator'
   *  UnitDelay: '<S61>/FixPt Unit Delay1'
   *  UnitDelay: '<S61>/FixPt Unit Delay2'
   */
  if (vdy_wye_DWork->trav_dist_reset_DSTATE ||
      (vdy_wye_DWork->FixPtUnitDelay2_DSTATE != 0)) {
    rtb_Yk1 = 0.0F;
  } else {
    rtb_Yk1 = vdy_wye_DWork->FixPtUnitDelay1_DSTATE;
  }

  /* Sum: '<S35>/add_trav_dist' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  Product: '<S35>/inc_dist'
   */
  rtb_Yk1 += vdy_wye_B->Time2Sec_n.Time2Sec * (*vdy_wye_U_VDYInternalData_in).
    vdy_ve_out.veh_velo;

  /* Embedded MATLAB: '<S35>/check_with_read_values' incorporates:
   *  Inport: '<Root>/VDYNvData_in'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/check_wld_for_nv_save/check_with_read_values': '<S60>:1' */
  /* '<S60>:1:2' */
  rtb_R_yaw_valid = FALSE;

  /*  if wheel load dependency is read from the NVM, check with currently calculated values */
  if (vdy_wye_B->sf_Get_NVM_IO_State_k.state == ((uint32_T)VDY_IO_STATE_VALID))
  {
    /* '<S60>:1:4' */
    /*  if the difference of the wheel load dependancy between the last saved NVM WLD and the currently estimated WLD is above 0.05   */
    /*  and the traveled distance is above 30000.0 m (30 km), store the new value */
    if ((((rtb_x_out[2] - (*vdy_wye_U_VDYNvData_in).Read.Wld.Wld_front) >= 0.05F)
         || ((rtb_x_out[2] - (*vdy_wye_U_VDYNvData_in).Read.Wld.Wld_front) <=
             -0.05F)) && (rtb_Yk1 > 30000.0F)) {
      /* '<S60>:1:7' */
      /* '<S60>:1:8' */
      rtb_VectorConcatenate_idx = rtb_x_out[2];

      /* '<S60>:1:9' */
      rtb_R_yaw_valid = TRUE;

      /* '<S60>:1:10' */
      rtb_state = ((uint32_T)VDY_IO_STATE_VALID);
    } else {
      /* '<S60>:1:12' */
      rtb_VectorConcatenate_idx = (*vdy_wye_U_VDYNvData_in).Read.Wld.Wld_front;

      /* '<S60>:1:13' */
      rtb_state = ((uint32_T)VDY_IO_STATE_INVALID);
    }
  } else {
    /* '<S60>:1:16' */
    rtb_VectorConcatenate_idx = (*vdy_wye_U_VDYNvData_in).Read.Wld.Wld_front;

    /* '<S60>:1:17' */
    rtb_state = ((uint32_T)VDY_IO_STATE_INVALID);
  }

  /* Embedded MATLAB: '<S62>/Get_IO_State' incorporates:
   *  Constant: '<S57>/VDY_SIN_POS'
   *  Constant: '<S62>/VDY_IO_STATE_BITMASK'
   */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_IO_State3/GetIOState/Get_IO_State': '<S63>:1' */
  /*  set the value at pos in the state array */
  /* '<S63>:1:4' */
  c = ((uint32_T)VDY_NVM_POS_WLD);
  if (((uint32_T)VDY_NVM_POS_WLD) > 2147483647U) {
    c = 2147483647U;
  }

  i = (int32_T)c;
  bitpos = i - ((i >> 5) << 5);

  /* '<S63>:1:5' */
  /* '<S63>:1:6' */
  c = 0U;
  if (bitpos < 0) {
    i = -bitpos;
    if (i > 255) {
      i = 255;
    }

    rtb_init = (uint8_T)i;
    if (rtb_init < 32) {
      c = (3U >> ((uint32_T)rtb_init));
    }
  } else {
    i = bitpos;
    if (bitpos <= 0) {
      i = 0;
    } else {
      if (bitpos > 255) {
        i = 255;
      }
    }

    rtb_init = (uint8_T)i;
    if (rtb_init < 32) {
      c = (3U << ((uint32_T)rtb_init));
    }
  }

  /* '<S63>:1:7' */
  /* '<S63>:1:8' */

  /* BusAssignment: '<S35>/Bus Assignment1' incorporates:
   *  Inport: '<Root>/VDYNvData_in'
   */
  (*vdy_wye_Y_VDYNVData_out) = (*vdy_wye_U_VDYNvData_in);
  (*vdy_wye_Y_VDYNVData_out).Write.State = ((c ^ MAX_uint32_T)
    & (*vdy_wye_U_VDYNvData_in).Write.State) | (rtb_state << bitpos);
  (*vdy_wye_Y_VDYNVData_out).Write.Wld.Wld_front = rtb_VectorConcatenate_idx;

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_KH' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_H, rtb_KH_g, (uint8_T)2, (uint8_T)3, (uint8_T)3);

  /* Sum: '<S33>/1_KH' incorporates:
   *  Constant: '<S33>/eye'
   */
  for (i = 0; i < 9; i++) {
    rtb_KH_g[i] = vdy_wye_I_matrix_wld_p[(i)] - rtb_KH_g[i];
  }

  /* Embedded MATLAB: '<S33>/Reset_P_pred' */
  /* Embedded MATLAB Function 'estimate_wheel_load_dep_front/EKF/Reset_P_pred': '<S40>:1' */
  if (vdy_wye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S40>:1:4' */
    /* '<S40>:1:6' */
    for (i = 0; i < 9; i++) {
      rtb_P_pred_out[i] = vdy_wye_P_init_wld_p[(i)];
    }
  } else {
    /* '<S40>:1:10' */
    for (i = 0; i < 9; i++) {
      rtb_P_pred_out[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S33>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH_g,
    (real32_T*)rtb_P_pred_out, rtb_P_post_k, (uint8_T)3, (uint8_T)3, (uint8_T)3);

  /* Switch: '<S61>/Reset' incorporates:
   *  Constant: '<S61>/Initial Condition'
   *  Update for UnitDelay: '<S61>/FixPt Unit Delay1'
   */
  if (rtb_R_onoff) {
    vdy_wye_DWork->FixPtUnitDelay1_DSTATE = 0.0F;
  } else {
    vdy_wye_DWork->FixPtUnitDelay1_DSTATE = rtb_Yk1;
  }

  /* Switch: '<S102>/Init' incorporates:
   *  Logic: '<S102>/FixPt Logical Operator'
   *  UnitDelay: '<S102>/FixPt Unit Delay1'
   *  UnitDelay: '<S102>/FixPt Unit Delay2'
   */
  if ((rtb_Reset != 0) || (vdy_wye_DWork->FixPtUnitDelay2_DSTATE_h != 0)) {
    rtb_Yk1 = (real32_T)rtb_TP_init;
  } else {
    rtb_Yk1 = vdy_wye_DWork->FixPtUnitDelay1_DSTATE_d;
  }

  /* Sum: '<S101>/Sum' incorporates:
   *  Gain: '<S101>/Gain'
   *  Sum: '<S101>/Diff'
   */
  vdy_wye_DWork->whl_yaw_off_control_DSTATE = ((rtb_Yk1 - ((real32_T)
    rtb_TP_yaw_off_control_out)) * 0.6F) + ((real32_T)rtb_TP_yaw_off_control_out);

  /* Switch: '<S102>/Reset' incorporates:
   *  Update for UnitDelay: '<S102>/FixPt Unit Delay1'
   */
  if (rtb_Reset != 0) {
    vdy_wye_DWork->FixPtUnitDelay1_DSTATE_d = (real32_T)rtb_TP_init;
  } else {
    vdy_wye_DWork->FixPtUnitDelay1_DSTATE_d =
      vdy_wye_DWork->whl_yaw_off_control_DSTATE;
  }

  /* Update for UnitDelay: '<S55>/UD' */
  vdy_wye_DWork->UD_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S56>/UD' */
  vdy_wye_DWork->UD_DSTATE_a = rtb_Sum_p;

  /* Update for UnitDelay: '<S8>/last_est_wld' */
  vdy_wye_DWork->last_est_wld_DSTATE = rtb_x_out[2];

  /* Update for UnitDelay: '<S33>/x_delay_wld' */
  for (i = 0; i < 3; i++) {
    vdy_wye_DWork->x_delay_wld_DSTATE[(i)] = rtb_x_out[i];
  }

  /* Update for UnitDelay: '<S33>/init_nvm_wld_delay' */
  vdy_wye_DWork->init_nvm_wld_delay_DSTATE = rtb_init_out;

  /* Update for UnitDelay: '<S76>/UD' */
  vdy_wye_DWork->UD_DSTATE_b = rtb_Sum_c;

  /* Update for UnitDelay: '<S77>/hold_value' */
  vdy_wye_DWork->hold_value_DSTATE = rtb_Rroff;

  /* Update for UnitDelay: '<S77>/hold_counter' */
  vdy_wye_DWork->hold_counter_DSTATE = rtb_counter_out;
  for (i = 0; i < 9; i++) {
    /* Update for UnitDelay: '<S33>/P_delay_wld' */
    vdy_wye_DWork->P_delay_wld_DSTATE[(i)] = rtb_P_post_k[i];

    /* Update for UnitDelay: '<S2>/P_delay_dyn_off' */
    vdy_wye_DWork->P_delay_dyn_off_DSTATE[(i)] = rtb_P_post_p[i];
  }

  /* Update for UnitDelay: '<S2>/x_delay_dyn_off' */
  for (i = 0; i < 3; i++) {
    vdy_wye_DWork->x_delay_dyn_off_DSTATE[(i)] = rtb_x_post[i];
  }

  /* Update for UnitDelay: '<S1>/last_dyn_yaw_offset' */
  vdy_wye_DWork->last_dyn_yaw_offset_DSTATE = rtb_VectorConcatenate_idx_1;

  /* Update for UnitDelay: '<S1>/dyn_yaw_off_overt_count' */
  vdy_wye_DWork->dyn_yaw_off_overt_count_DSTATE = vx_quad;

  /* Update for UnitDelay: '<S1>/last_dyn_yaw_offset_sign' */
  vdy_wye_DWork->last_dyn_yaw_offset_sign_DSTATE = rtb_sign_out;

  /* Update for UnitDelay: '<S10>/diff_raw_whl_est_whl_yaw' */
  vdy_wye_DWork->diff_raw_whl_est_whl_yaw_DSTATE = rtb_diff;

  /* Update for UnitDelay: '<S96>/T3' */
  vdy_wye_DWork->T3_DSTATE = kf_quad;

  /* Update for UnitDelay: '<S96>/T2' */
  vdy_wye_DWork->T2_DSTATE = WldFactFront;

  /* Update for UnitDelay: '<S96>/T1' */
  vdy_wye_DWork->T1_DSTATE = rtb_VectorConcatenate_idx_0;

  /* Update for UnitDelay: '<S96>/T0' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S10>/Product1'
   *  Sum: '<S10>/Add'
   */
  vdy_wye_DWork->T0_DSTATE = (rtb_frWithWldEst_wye + rtb_reWithWldEst_wye) *
    0.5F;

  /* Update for UnitDelay: '<S10>/last_est_whl_yaw_rate' */
  vdy_wye_DWork->last_est_whl_yaw_rate_DSTATE = rtb_TmpSignalConversionAtSFun_c
    [0];

  /* Update for UnitDelay: '<S3>/P_delay_whl_yaw' */
  for (i = 0; i < 4; i++) {
    vdy_wye_DWork->P_delay_whl_yaw_DSTATE[(i)] = rtb_P_post_d[i];
  }

  /* Update for UnitDelay: '<S3>/x_delay_whl_yaw' */
  for (i = 0; i < 2; i++) {
    vdy_wye_DWork->x_delay_whl_yaw_DSTATE[(i)] =
      rtb_TmpSignalConversionAtSFun_c[i];
  }

  /* Update for UnitDelay: '<S35>/trav_dist_reset' */
  vdy_wye_DWork->trav_dist_reset_DSTATE = rtb_R_yaw_valid;

  /* Update for UnitDelay: '<S61>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S61>/FixPt Constant'
   */
  vdy_wye_DWork->FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S102>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S102>/FixPt Constant'
   */
  vdy_wye_DWork->FixPtUnitDelay2_DSTATE_h = 0U;
}

/* Model initialize function */
void vdy_wye_initialize(boolean_T firstTime, BlockIO_vdy_wye *vdy_wye_B,
  D_Work_vdy_wye *vdy_wye_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_wye_B), 0,
                      sizeof(BlockIO_vdy_wye));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_wye_DWork, 0,
                      sizeof(D_Work_vdy_wye));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S55>/UD' */
    vdy_wye_DWork->UD_DSTATE = 1.0F;

    /* InitializeConditions for UnitDelay: '<S56>/UD' */
    vdy_wye_DWork->UD_DSTATE_a = 1.0F;

    /* InitializeConditions for UnitDelay: '<S8>/last_est_wld' */
    vdy_wye_DWork->last_est_wld_DSTATE = 1.5F;

    /* InitializeConditions for UnitDelay: '<S33>/x_delay_wld' */
    for (i = 0; i < 3; i++) {
      vdy_wye_DWork->x_delay_wld_DSTATE[(i)] = vdy_wye_x_init_wld_p[(i)];
    }

    for (i = 0; i < 9; i++) {
      /* InitializeConditions for UnitDelay: '<S33>/P_delay_wld' */
      vdy_wye_DWork->P_delay_wld_DSTATE[(i)] = vdy_wye_P_init_wld_p[(i)];

      /* InitializeConditions for UnitDelay: '<S2>/P_delay_dyn_off' */
      vdy_wye_DWork->P_delay_dyn_off_DSTATE[(i)] = vdy_wye_P_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S2>/x_delay_dyn_off' */
    for (i = 0; i < 3; i++) {
      vdy_wye_DWork->x_delay_dyn_off_DSTATE[(i)] = vdy_wye_x_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S3>/P_delay_whl_yaw' */
    for (i = 0; i < 4; i++) {
      vdy_wye_DWork->P_delay_whl_yaw_DSTATE[(i)] = vdy_wye_yaw_P_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S3>/x_delay_whl_yaw' */
    for (i = 0; i < 2; i++) {
      vdy_wye_DWork->x_delay_whl_yaw_DSTATE[(i)] = vdy_wye_yaw_x_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S61>/FixPt Unit Delay2' */
    vdy_wye_DWork->FixPtUnitDelay2_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S102>/FixPt Unit Delay2' */
    vdy_wye_DWork->FixPtUnitDelay2_DSTATE_h = 1U;
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
