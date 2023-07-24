/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_wpp.c
   Real-Time Workshop code generated for Simulink model vdy_wpp.
   Model version                        : 1.2936
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:00:00 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:00:01 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy wheel pre processing,
   estimate and merge the four wheel
   velocities with the wheel puls tick's
   VERSION:                             : $Revision: 1.5 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_wpp.h"
#include "vdy_wpp_private.h"

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
 *    '<Root>/Get_IO_State_WTCKS_FL'
 *    '<Root>/Get_IO_State_WTCKS_FR'
 *    '<Root>/Get_IO_State_WTCKS_RL'
 *    '<Root>/Get_IO_State_WTCKS_RR'
 *    '<Root>/Get_IO_State_WVEL_FL'
 *    '<Root>/Get_IO_State_WVEL_FR'
 *    '<Root>/Get_IO_State_WVEL_RL'
 *    '<Root>/Get_IO_State_WVEL_RR'
 */
void vdy_wpp_Get_IO_State_WTCKS_FL(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State_WTCKS_FL_vdy_w *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S1>/Index Vector' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/*
 * Initial conditions for atomic system:
 *    '<Root>/front_left_wheel_speed_fusion'
 *    '<Root>/front_right_wheel_speed_fusion'
 *    '<Root>/rear_left_wheel_speed_fusion'
 *    '<Root>/rear_right_wheel_speed_fusion'
 */
void wheel_speed_fusion_Init(rtDW_wheel_speed_fusion *localDW)
{
  int32_T i;

  /* InitializeConditions for UnitDelay: '<S70>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S37>/init_delay' */
  localDW->init_delay_DSTATE = TRUE;

  /* InitializeConditions for UnitDelay: '<S56>/P_delay' */
  for (i = 0; i < 4; i++) {
    localDW->P_delay_DSTATE[(i)] = vdy_wpp_P_init_p[(i)];
  }

  /* InitializeConditions for UnitDelay: '<S41>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE_o = 15U;
}

/*
 * Output and update for atomic system:
 *    '<Root>/front_left_wheel_speed_fusion'
 *    '<Root>/front_right_wheel_speed_fusion'
 *    '<Root>/rear_left_wheel_speed_fusion'
 *    '<Root>/rear_right_wheel_speed_fusion'
 */
void wheel_speed_fusion(real32_T rtu_wheel_velocity, real32_T rtu_CycleTime,
  real32_T rtu_whl_Circumference, uint8_T rtu_number_wheel_pulse, uint8_T
  rtu_wheel_velocity_valid, uint8_T rtu_use_pulse, real32_T
  rtu_aqua_slip_correction, uint8_T rtu_diff_wheel_pulse, rtB_wheel_speed_fusion
  *localB, rtDW_wheel_speed_fusion *localDW)
{
  /* local block i/o variables */
  real32_T rtb_vdy_sfunc_x_pred_o2[2];
  real32_T rtb_Divide;
  real32_T rtb_puls_speed_delay;
  real32_T rtb_Divide_l;
  real32_T rtb_Add_e;
  real32_T rtb_P_pred[4];
  real32_T rtb_HPH_R[4];
  real32_T rtb_P_predHt[4];
  real32_T rtb_K[4];
  real32_T rtb_x_post[2];
  real32_T rtb_vdy_sfunc_P_post_o2[4];
  real32_T rtb_diff;
  real32_T rtb_add_diff;
  real32_T rtb_V_pred;
  real32_T rtb_H[4];
  real32_T rtb_P_pred_out[4];
  real32_T rtb_exponent;
  real32_T rtb_A[4];
  real32_T rtb_exponent_d;
  real32_T rtb_exponent_h;
  real32_T rtb_wheel_acceleration;
  real32_T rtb_Knu[2];
  real32_T rtb_Ht[4];
  real32_T rtb_nu[2];
  real32_T rtb_vdy_sfunc_HP_Ht_o2[4];
  real32_T rtb_KH[4];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_vdy_sfunc_P_post_o1;
  real32_T wheel_puls_velocity_out;
  real32_T counter_out;
  real32_T m_out;
  real32_T rtb_Init;
  real32_T rtb_th_Delay;
  real32_T rtb_th_Delay_g;
  real32_T rtb_th_Delay_c;
  real32_T rtb_th_Delay1;
  real32_T rtb_th_Delay1_b;
  real32_T rtb_th_Delay1_h;
  uint8_T rtb_y_n;
  real32_T rtb_Product1_k;
  real32_T rtb_T2;
  real32_T rtb_T1;
  real32_T rtb_T0;
  real32_T rtb_Product_n[2];
  real32_T rtb_hx[2];
  real32_T rtb_last_accel_corr;
  real32_T rtb_single_puls_velocity_out;
  real32_T rtb_accel_corrected_out;
  real32_T rtb_TmpSignalConversionAtSFun_a[2];
  int32_T i;
  real32_T rtb_TmpSignalConversionAtSFun_0[2];
  real32_T rtb_Product_n_0[2];
  int32_T i_0;

  /* Embedded MATLAB: '<S51>/make_A_matrix' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/A/make_A_matrix': '<S60>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S60>:1:5' */
  rtb_A[0] = 1.0F;
  rtb_A[2] = rtu_CycleTime;
  for (i = 0; i < 2; i++) {
    rtb_A[1 + (i << 1)] = (real32_T)i;
  }

  /* UnitDelay: '<S70>/FixPt Unit Delay2' */
  rtb_vdy_sfunc_P_post_o1 = localDW->FixPtUnitDelay2_DSTATE;

  /* UnitDelay: '<S70>/FixPt Unit Delay1' */
  for (i = 0; i < 2; i++) {
    rtb_nu[i] = localDW->FixPtUnitDelay1_DSTATE[(i)];
  }

  /* Switch: '<S70>/Init' incorporates:
   *  Constant: '<S56>/x_init_a'
   */
  if (rtb_vdy_sfunc_P_post_o1 != 0) {
    rtb_nu[0] = rtu_wheel_velocity;
    rtb_nu[1] = vdy_wpp_x_init_p;
  }

  /* S-Function (MatrixMultiplication): '<S56>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_nu, rtb_vdy_sfunc_x_pred_o2, (uint8_T)2, (uint8_T)2, (uint8_T)
    1);

  /* Embedded MATLAB: '<S56>/hx' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/kalman_filter/hx': '<S67>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S67>:1:6' */
  for (i = 0; i < 4; i++) {
    rtb_H[i] = vdy_wpp_H_p[(i)];
  }

  /* '<S67>:1:8' */
  for (i = 0; i < 2; i++) {
    rtb_hx[i] = 0.0F;
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_hx[i] = (vdy_wpp_H_p[(i_0 << 1) + i] * rtb_vdy_sfunc_x_pred_o2[i_0]) +
        rtb_hx[i];
    }
  }

  /* Product: '<S52>/Divide' incorporates:
   *  Constant: '<S52>/Constant'
   *  Product: '<S52>/Product1'
   */
  rtb_Divide = (rtu_CycleTime * rtu_CycleTime) / 2.0F;

  /* UnitDelay: '<S79>/1th_Delay' */
  rtb_Init = localDW->th_Delay_DSTATE;

  /* UnitDelay: '<S79>/2th_Delay' */
  rtb_th_Delay = localDW->th_Delay_DSTATE_b;

  /* UnitDelay: '<S79>/3th_Delay' */
  rtb_th_Delay_g = localDW->th_Delay_DSTATE_f;

  /* UnitDelay: '<S79>/4th_Delay' */
  rtb_th_Delay_c = localDW->th_Delay_DSTATE_o;

  /* UnitDelay: '<S79>/1th_Delay1' */
  rtb_th_Delay1 = localDW->th_Delay1_DSTATE;

  /* UnitDelay: '<S79>/2th_Delay1' */
  rtb_th_Delay1_b = localDW->th_Delay1_DSTATE_f;

  /* UnitDelay: '<S79>/3th_Delay1' */
  rtb_th_Delay1_h = localDW->th_Delay1_DSTATE_j;

  /* Embedded MATLAB: '<S37>/init_wheel_pulse' incorporates:
   *  UnitDelay: '<S37>/init_delay'
   */
  /* Embedded MATLAB Function 'wheel pulses to speed/init_wheel_pulse': '<S78>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (((int32_T)localDW->init_delay_DSTATE) == 1) {
    /* '<S78>:1:4' */
    /* '<S78>:1:5' */
    /* '<S78>:1:6' */
    rtb_y_n = 0U;
  } else {
    /* '<S78>:1:8' */
    /* '<S78>:1:9' */
    rtb_y_n = rtu_diff_wheel_pulse;
  }

  /* Product: '<S80>/Product1' */
  rtb_Product1_k = rtu_CycleTime * ((real32_T)rtu_number_wheel_pulse);

  /* Embedded MATLAB: '<S80>/divide' incorporates:
   *  Product: '<S80>/Product'
   */
  /* Embedded MATLAB Function 'puls to speed/divide': '<S82>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if ((rtb_Product1_k >= 0.0001F) || (rtb_Product1_k <= -0.0001F)) {
    /* '<S82>:1:5' */
    /* '<S82>:1:6' */
    rtb_Product1_k = (((real32_T)rtb_y_n) * rtu_whl_Circumference) /
      rtb_Product1_k;
  } else {
    /* '<S82>:1:8' */
    rtb_Product1_k = 0.0F;
  }

  /* UnitDelay: '<S37>/puls_speed_delay' */
  rtb_puls_speed_delay = localDW->puls_speed_delay_DSTATE;

  /* Embedded MATLAB: '<S37>/puls_velocity_pre_processing' incorporates:
   *  S-Function (ex_sfun_abs): '<S37>/S-Function'
   *  UnitDelay: '<S37>/counter_delay'
   *  UnitDelay: '<S37>/m_delay'
   *  UnitDelay: '<S37>/single_puls_velocity_delay'
   */
  /* Embedded MATLAB Function 'wheel pulses to speed/puls_velocity_pre_processing': '<S81>:1' */
  /*  This block calculates the wheel pulse velocity out of the pulses */
  if (rtu_number_wheel_pulse == 0) {
    /* '<S81>:1:3' */
    /*  increase the counter if no pulse is detected */
    /* '<S81>:1:5' */
    counter_out = localDW->counter_delay_DSTATE + 1.0F;

    /*  if no pulse is detected for some cycles, set all to zero */
    if (counter_out > vdy_wpp_puls_velocity_para_p[0]) {
      /* '<S81>:1:7' */
      /* '<S81>:1:8' */
      wheel_puls_velocity_out = 0.0F;

      /* '<S81>:1:9' */
      rtb_single_puls_velocity_out = 0.0F;

      /* '<S81>:1:10' */
      m_out = 0.0F;
    } else {
      /*  The calculated gradient between the last two wheel pulse dirac velocities  */
      /*  is used to increase or drop down the output puls velocity */
      /* '<S81>:1:14' */
      wheel_puls_velocity_out = rtb_puls_speed_delay + localDW->m_delay_DSTATE;

      /*  check if the wheel pulse speed is below zero */
      if (wheel_puls_velocity_out < 0.0F) {
        /* '<S81>:1:16' */
        /* '<S81>:1:17' */
        wheel_puls_velocity_out = 0.0F;
      }

      /*  save the wheel velocity of the last pulse dirac */
      /* '<S81>:1:20' */
      rtb_single_puls_velocity_out = localDW->single_puls_velocity_delay_DSTA;

      /* '<S81>:1:21' */
      m_out = localDW->m_delay_DSTATE;
    }
  } else {
    /*  if the first pulse is detected after a long time */
    if (CML_f_Abs( (real32_T)rtb_puls_speed_delay) <= 0.0001F) {
      /* '<S81>:1:25' */
      /*  with only one pulse it is not possible to calculate a suitable pulse velocity */
      /*  but if one pulse is detected the vehicle is moving so the velocity is increased  */
      /*  by a constant gradient  */
      /* '<S81>:1:29' */
      m_out = vdy_wpp_puls_velocity_para_p[1] / vdy_wpp_puls_velocity_para_p[2];

      /* '<S81>:1:30' */
      wheel_puls_velocity_out = rtb_puls_speed_delay + m_out;

      /* '<S81>:1:31' */
      rtb_single_puls_velocity_out = 0.0F;

      /*  reset the counter */
      /* '<S81>:1:33' */
      counter_out = 1.0F;
    } else {
      /*  pulse velocity gradient = act pulse velocity - last_pulse velocity / cycles between pulses */
      /* '<S81>:1:36' */
      m_out = (((rtb_Product1_k / localDW->counter_delay_DSTATE) -
                localDW->single_puls_velocity_delay_DSTA) /
               localDW->counter_delay_DSTATE) / vdy_wpp_puls_velocity_para_p[3];

      /*  only one pulse is detected, the puls velocity for this first pulse can not be calculated so the single pulse velocity is zero    */
      if ((localDW->single_puls_velocity_delay_DSTA <= 0.0001F) &&
          (localDW->single_puls_velocity_delay_DSTA >= -0.0001F)) {
        /* '<S81>:1:38' */
        /* '<S81>:1:39' */
        wheel_puls_velocity_out = rtb_puls_speed_delay + m_out;
      } else {
        /* '<S81>:1:41' */
        wheel_puls_velocity_out = rtb_Product1_k / localDW->counter_delay_DSTATE;
      }

      /*  the single pulse velocity is the constant veloctiy between the */
      /*  last and the current pulse */
      /* '<S81>:1:45' */
      rtb_single_puls_velocity_out = rtb_Product1_k /
        localDW->counter_delay_DSTATE;

      /*  reset the counter */
      /* '<S81>:1:47' */
      counter_out = 1.0F;
    }
  }

  /* Product: '<S79>/Divide' incorporates:
   *  Constant: '<S79>/Constant'
   *  Sum: '<S79>/Add'
   */
  rtb_Init = (((((((rtb_Init + rtb_th_Delay) + rtb_th_Delay_g) + rtb_th_Delay_c)
                 + rtb_th_Delay1) + rtb_th_Delay1_b) + rtb_th_Delay1_h) +
              wheel_puls_velocity_out) * 0.125F;

  /* UnitDelay: '<S76>/T2' */
  rtb_T2 = localDW->T2_DSTATE;

  /* UnitDelay: '<S76>/T1' */
  rtb_T1 = localDW->T1_DSTATE;

  /* UnitDelay: '<S76>/T0' */
  rtb_T0 = localDW->T0_DSTATE;

  /* Product: '<S76>/Divide' incorporates:
   *  Constant: '<S76>/filter_length'
   *  Sum: '<S76>/Add'
   *  UnitDelay: '<S76>/T3'
   */
  rtb_Divide_l = (((localDW->T3_DSTATE + localDW->T2_DSTATE) +
                   localDW->T1_DSTATE) + localDW->T0_DSTATE) * 0.25F;

  /* Sum: '<S58>/Add' */
  rtb_Add_e = rtu_wheel_velocity - rtb_Divide_l;

  /* Embedded MATLAB: '<S58>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S36>/vdy_wpp_Q_gain'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  /* Embedded MATLAB Function 'puls wheel speed fusion/q_gain/Embedded MATLAB Function': '<S74>:1' */
  /* '<S74>:1:3' */
  rtb_add_diff = vdy_wpp_Q_gain_p[6] - rtb_Init;

  /*  predict the wheel velocity by the estimated wheel acceleration */
  /* '<S74>:1:6' */
  rtb_V_pred = (vdy_wpp_Q_gain_p[2] * localDW->UnitDelay_DSTATE) + rtb_Divide_l;

  /* Embedded MATLAB: '<S58>/q_gain_delta' incorporates:
   *  S-Function (ex_sfun_abs): '<S58>/abs_V_pred'
   *  S-Function (ex_sfun_abs): '<S58>/abs_last_est_wheel_velocity_in'
   *  S-Function (ex_sfun_abs): '<S58>/add_abs'
   *  S-Function (ex_sfun_abs): '<S58>/diff_abs'
   *  Sum: '<S58>/Add'
   */
  /* Embedded MATLAB Function 'puls wheel speed fusion/q_gain/q_gain_delta': '<S77>:1' */
  /*  the difference between the mean filtered last velocity and the actual wheel velocity */
  /* '<S77>:1:3' */
  rtb_diff = rtu_wheel_velocity - rtb_Divide_l;

  /*  if the predicted velocity is below zero raise the model Variance */
  /*  to protect velocity below zero */
  if (rtb_V_pred < 0.0F) {
    /* '<S77>:1:7' */
    /* '<S77>:1:8' */
    rtb_diff = (CML_f_Abs( (real32_T)rtb_V_pred) * vdy_wpp_Q_gain_p[3]) +
      CML_f_Abs( (real32_T)rtb_Add_e);
    if (CML_f_Abs( (real32_T)rtb_Divide_l) < vdy_wpp_Q_gain_p[4]) {
      /* '<S77>:1:9' */
      /* '<S77>:1:10' */
      rtb_diff = vdy_wpp_Q_gain_p[5];
    }
  } else {
    /*  if no zero under-run is detected but the wheel velocity is in the low speed range */
    if ((rtb_Init <= vdy_wpp_Q_gain_p[6]) && ((rtb_Init >= 0.0001F) || (rtb_Init
          <= -0.0001F))) {
      /* '<S77>:1:14' */
      /*  the diff gain control factor is raised with to zero */
      /* '<S77>:1:16' */
      /* '<S77>:1:17' */
      rtb_diff = vdy_wpp_Q_gain_p[7] + CML_f_Abs( (real32_T)rtb_add_diff);
    }

    /*  if wheel velocity in is below 0.6 and wheel puls velocity is zero (no pulse available) */
    if (((rtu_wheel_velocity <= vdy_wpp_Q_gain_p[6]) && (rtb_Init <= 0.0001F)) &&
        (rtb_Init >= -0.0001F)) {
      /* '<S77>:1:21' */
      /*  set diff value to const value */
      /* '<S77>:1:23' */
      rtb_diff = 2.0F;
    }
  }

  /* Embedded MATLAB: '<S58>/get_gain_bias' incorporates:
   *  Constant: '<S36>/vdy_wpp_Q_gain'
   */
  /* Embedded MATLAB Function 'puls wheel speed fusion/q_gain/get_gain_bias': '<S75>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S75>:1:5' */
  /* '<S75>:1:6' */

  /* Sum: '<S58>/Sum2' incorporates:
   *  Product: '<S58>/Product'
   *  S-Function (ex_sfun_abs): '<S58>/Diff_abs'
   */
  rtb_Product1_k = (CML_f_Abs( (real32_T)rtb_diff) * vdy_wpp_Q_gain_p[0]) +
    vdy_wpp_Q_gain_p[1];

  /* Product: '<S52>/Product' incorporates:
   *  Constant: '<S52>/sigma_model'
   */
  for (i = 0; i < 2; i++) {
    rtb_Product_n[i] = vdy_wpp_Q_sigmas_p[(i)] * rtb_Product1_k;
  }

  /* SignalConversion: '<S61>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_TmpSignalConversionAtSFun_a[0] = rtb_Divide;
  rtb_TmpSignalConversionAtSFun_a[1] = rtu_CycleTime;

  /* Embedded MATLAB: '<S52>/makeQ' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/Q/makeQ': '<S61>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S61>:1:5' */

  /* UnitDelay: '<S56>/P_delay' */
  for (i = 0; i < 4; i++) {
    rtb_vdy_sfunc_HP_Ht_o2[i] = localDW->P_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S68>/vdy_s-func_AP' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_vdy_sfunc_HP_Ht_o2, rtb_Ht, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Math: '<S56>/At' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_vdy_sfunc_HP_Ht_o2[i_0 + (i << 1)] = rtb_A[(i_0 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S68>/vdy_s-func_AP_At' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_Ht,
    (real32_T*)rtb_vdy_sfunc_HP_Ht_o2, rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Sum: '<S56>/APA_Q' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFun_a[i] *
      rtb_Product_n[i];
    rtb_Product_n_0[i] = rtb_Product_n[i] * rtb_TmpSignalConversionAtSFun_a[i];
  }

  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_P_pred[i_0 + (i << 1)] = rtb_KH[(i << 1) + i_0] +
        (rtb_TmpSignalConversionAtSFun_0[i_0] * rtb_Product_n_0[i]);
    }
  }

  /* S-Function (MatrixMultiplication): '<S69>/vdy_s-func_HP' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_H,
    (real32_T*)rtb_P_pred, rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Math: '<S56>/Ht' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_Ht[i_0 + (i << 1)] = rtb_H[(i_0 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S69>/vdy_s-func_HP_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_Ht, rtb_vdy_sfunc_HP_Ht_o2, (uint8_T)2, (uint8_T)2, (uint8_T)
    2);

  /* Embedded MATLAB: '<S53>/calc_exponent' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/calc_wheel_velocity_R_variance/calc_exponent': '<S63>:1' */
  /*  if wheel velocity is high variance is low variance */
  /*  R22 = 40*exp(wheel_velocity_in * -10) + 0.002 */
  /*  check exponent is in single floating point range */
  /* '<S63>:1:6' */
  rtb_exponent = rtu_wheel_velocity * vdy_wpp_R_p[1];
  if (rtb_exponent < -80.0F) {
    /* '<S63>:1:7' */
    /* '<S63>:1:8' */
    rtb_exponent = -80.0F;
  }

  if (rtb_exponent > 80.0F) {
    /* '<S63>:1:10' */
    /* '<S63>:1:11' */
    rtb_exponent = 80.0F;
  }

  /* Embedded MATLAB: '<S53>/calc_R' incorporates:
   *  S-Function (ex_sfun_exp): '<S53>/S-Function'
   */
  /* Embedded MATLAB Function 'puls wheel speed fusion/calc_wheel_velocity_R_variance/calc_R': '<S62>:1' */
  /*  R22 = 40*exp(wheel_velocity_in * -10) + 0.002 */
  /* '<S62>:1:4' */
  rtb_Product1_k = (GDBexp( (real32_T)rtb_exponent) * vdy_wpp_R_p[2]) +
    vdy_wpp_R_p[3];

  /* Embedded MATLAB: '<S36>/if_else_use_wheel_pulse' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/if_else_use_wheel_pulse': '<S55>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (((uint32_T)rtu_use_pulse) == ((uint32_T)VDY_IO_STATE_VALID)) {
    /* '<S55>:1:5' */
    /* '<S55>:1:6' */
    rtb_HPH_R[0] = vdy_wpp_R_p[0];
    rtb_HPH_R[2] = 0.0F;
    rtb_HPH_R[1] = 0.0F;
    rtb_HPH_R[3] = rtb_Product1_k;

    /* '<S55>:1:7' */
    rtb_Product_n[0] = rtb_Init;
    rtb_Product_n[1] = rtu_wheel_velocity;
  } else {
    /* '<S55>:1:9' */
    rtb_HPH_R[0] = vdy_wpp_R_p[0];
    rtb_HPH_R[2] = 0.0F;
    rtb_HPH_R[1] = 0.0F;
    rtb_HPH_R[3] = rtb_Product1_k;

    /* '<S55>:1:10' */
    rtb_Product_n[0] = 0.0F;
    rtb_Product_n[1] = rtu_wheel_velocity;
  }

  /* Sum: '<S56>/HPH_R' */
  for (i = 0; i < 4; i++) {
    rtb_HPH_R[i] = rtb_vdy_sfunc_HP_Ht_o2[i] + rtb_HPH_R[i];
  }

  /* Embedded MATLAB: '<S64>/Matrix_Inversion_2x2' */
  vdy_matrix_inversion_2x2(rtb_HPH_R, &localB->sf_Matrix_Inversion_2x2);

  /* Embedded MATLAB: '<S56>/Reset_x_pred' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/kalman_filter/Reset_x_pred': '<S66>:1' */
  if (localB->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S66>:1:4' */
    /* '<S66>:1:6' */
    rtb_TmpSignalConversionAtSFun_a[0] = rtu_wheel_velocity;
    rtb_TmpSignalConversionAtSFun_a[1] = 0.0F;
  } else {
    /* '<S66>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_TmpSignalConversionAtSFun_a[i] = rtb_vdy_sfunc_x_pred_o2[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S56>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_Ht, rtb_P_predHt, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* If: '<S64>/If' incorporates:
   *  ActionPort: '<S72>/Action Port'
   *  ActionPort: '<S73>/Action Port'
   *  SubSystem: '<S64>/calculate the gain'
   *  SubSystem: '<S64>/set gain to default value'
   */
  if (!localB->sf_Matrix_Inversion_2x2.det_flag) {
    /* S-Function (MatrixMultiplication): '<S72>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_predHt,
      (real32_T*)localB->sf_Matrix_Inversion_2x2.HPHt_R_inv, rtb_K, (uint8_T)2,
      (uint8_T)2, (uint8_T)2);
  } else {
    /* Constant: '<S73>/default_K_gain' */
    for (i = 0; i < 4; i++) {
      rtb_K[i] = vdy_wpp_K_default_p[(i)];
    }
  }

  /* Sum: '<S56>/z_Hx' */
  for (i = 0; i < 2; i++) {
    rtb_nu[i] = rtb_Product_n[i] - rtb_hx[i];
  }

  /* S-Function (MatrixMultiplication): '<S56>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_nu, rtb_Knu, (uint8_T)2, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S56>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_x_post[i] = rtb_TmpSignalConversionAtSFun_a[i] + rtb_Knu[i];
  }

  /* Embedded MATLAB: '<S36>/velocity' incorporates:
   *  S-Function (ex_sfun_abs): '<S36>/diff_abs'
   */
  /* Embedded MATLAB Function 'puls wheel speed fusion/velocity': '<S59>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if (CML_f_Abs( (real32_T)rtb_x_post[0]) < 0.02F) {
    /* '<S59>:1:4' */
    /* '<S59>:1:5' */
    localB->y = 0.0F;
  } else {
    /* '<S59>:1:7' */
    localB->y = rtb_x_post[0];
  }

  /* UnitDelay: '<S41>/FixPt Unit Delay2' */
  rtb_vdy_sfunc_P_post_o1 = localDW->FixPtUnitDelay2_DSTATE_o;

  /* UnitDelay: '<S41>/FixPt Unit Delay1' */
  rtb_Init = localDW->FixPtUnitDelay1_DSTATE_e;

  /* Switch: '<S41>/Init' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Logic: '<S41>/Logical Operator'
   *  Logic: '<S41>/Logical Operator1'
   *  Logic: '<S41>/Logical Operator2'
   *  RelationalOperator: '<S42>/Compare'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S46>/Compare'
   */
  if ((((rtu_wheel_velocity_valid == 3) || (rtu_wheel_velocity_valid == 4)) ||
       (rtu_wheel_velocity_valid == 0)) && ((rtb_vdy_sfunc_P_post_o1 == 15) ||
       (rtb_vdy_sfunc_P_post_o1 == 1))) {
    rtb_Init = localB->y;
  }

  /* Embedded MATLAB: '<S38>/divide' incorporates:
   *  Sum: '<S38>/Add'
   */
  /* Embedded MATLAB Function 'front left wheel speed fusion/acceleration_correction/calc_abs_accel/divide': '<S40>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if ((rtu_CycleTime >= 0.0001F) || (rtu_CycleTime <= -0.0001F)) {
    /* '<S40>:1:5' */
    /* '<S40>:1:6' */
    rtb_wheel_acceleration = (localB->y - rtb_Init) / rtu_CycleTime;
  } else {
    /* '<S40>:1:8' */
    rtb_wheel_acceleration = 0.0F;
  }

  /* UnitDelay: '<S39>/last_accel_corr' */
  rtb_last_accel_corr = localDW->last_accel_corr_DSTATE;

  /* Embedded MATLAB: '<S39>/calc_exponent' incorporates:
   *  UnitDelay: '<S39>/last_accel_corr_step'
   */
  /* Embedded MATLAB Function 'front left wheel speed fusion/acceleration_correction/peak_filter_abs_acceleration/calc_exponent': '<S48>:1' */
  /* '<S48>:1:3' */
  rtb_Product1_k = localDW->last_accel_corr_step_DSTATE;

  /* '<S48>:1:4' */
  rtb_exponent_h = 0.0F;
  if (localDW->last_accel_corr_step_DSTATE < 100.0F) {
    /* '<S48>:1:5' */
    /* '<S48>:1:6' */
    rtb_exponent_h = localDW->last_accel_corr_step_DSTATE /
      vdy_wpp_accel_correct_p;
  }

  /* Embedded MATLAB: '<S39>/accel_peak_filter' incorporates:
   *  S-Function (ex_sfun_abs): '<S38>/abs_accel'
   *  S-Function (ex_sfun_exp): '<S39>/S-Function'
   *  UnitDelay: '<S39>/last_accel_corr_max'
   */
  /* Embedded MATLAB Function 'front left wheel speed fusion/acceleration_correction/peak_filter_abs_acceleration/accel_peak_filter': '<S47>:1' */
  /*  filters the abs wheel acceleration */
  /*  all acceleration peaks are positive, in case of zero crossing of the acceleration in the abs signal is there is a valley */
  /*  to reduce these waves a peak filter is used */
  if (CML_f_Abs( (real32_T)rtb_wheel_acceleration) >
      localDW->last_accel_corr_max_DSTATE) {
    /* '<S47>:1:11' */
    /*  a new higher peak is detected */
    /* '<S47>:1:13' */
    rtb_last_accel_corr = CML_f_Abs( (real32_T)rtb_wheel_acceleration);

    /* '<S47>:1:14' */
    rtb_Init = 1.0F;

    /* '<S47>:1:15' */
    rtb_accel_corrected_out = CML_f_Abs( (real32_T)rtb_wheel_acceleration);
  } else {
    /*  slow down the correction factor from the peak, by an exp funktion */
    /*  after slow doen 100 cycles the correction factor should be zero because of exp overflow */
    if (rtb_Product1_k < 100.0F) {
      /* '<S47>:1:19' */
      /* '<S47>:1:20' */
      rtb_accel_corrected_out = rtb_last_accel_corr * GDBexp( (real32_T)
        rtb_exponent_h);

      /* '<S47>:1:21' */
      /* '<S47>:1:22' */
      rtb_Init = rtb_Product1_k + 1.0F;
    } else {
      /* '<S47>:1:24' */
      rtb_accel_corrected_out = 0.0F;

      /* '<S47>:1:25' */
      /* '<S47>:1:26' */
      rtb_Init = 101.0F;
    }
  }

  /* Embedded MATLAB: '<S35>/calc_exponent' */
  /* Embedded MATLAB Function 'correct wheel uncertainty/calc_exponent': '<S49>:1' */
  /* '<S49>:1:3' */
  rtb_exponent_d = 0.0F;

  /*  check for exp overflow */
  if ((localB->y / vdy_wpp_P_correct_p[2]) < 100.0F) {
    /* '<S49>:1:5' */
    /* '<S49>:1:6' */
    rtb_exponent_d = localB->y / vdy_wpp_P_correct_p[2];
  }

  /* S-Function (MatrixMultiplication): '<S56>/vdy_s-func_KH' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_H, rtb_KH, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S56>/1_KH' incorporates:
   *  Constant: '<S56>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH[i] = vdy_wpp_I_matrix_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S56>/Reset_P_pred' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/kalman_filter/Reset_P_pred': '<S65>:1' */
  if (localB->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S65>:1:4' */
    /* '<S65>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = vdy_wpp_P_init_p[(i)];
    }
  } else {
    /* '<S65>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S56>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out, rtb_vdy_sfunc_P_post_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Embedded MATLAB: '<S36>/diag_P' */
  /* Embedded MATLAB Function 'puls wheel speed fusion/diag_P': '<S54>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S54>:1:5' */

  /* Embedded MATLAB: '<S35>/correct_estimated_ws_uncertainty' incorporates:
   *  S-Function (ex_sfun_exp): '<S35>/S-Function'
   */
  /* Embedded MATLAB Function 'correct wheel uncertainty/correct_estimated_ws_uncertainty': '<S50>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  if the wheel velocity is available and valid */
  if (((uint32_T)rtu_wheel_velocity_valid) == ((uint32_T)VDY_IO_STATE_VALID)) {
    /* '<S50>:1:6' */
    /*  if the vehicle is near stand still  */
    if (rtu_wheel_velocity <= 0.001F) {
      /* '<S50>:1:8' */
      if (((uint32_T)rtu_use_pulse) != ((uint32_T)VDY_IO_STATE_VALID)) {
        /* '<S50>:1:9' */
        /*  if wheel velocity is low and no wheel pulse are available */
        /* '<S50>:1:11' */
        localB->corrected_wheel_velocity_uncert = rtb_vdy_sfunc_P_post_o2[0] +
          vdy_wpp_P_correct_p[0];
      } else {
        /*  if pulse are available */
        /* '<S50>:1:14' */
        rtb_Product1_k = 0.0F;

        /*  check for exp overflow */
        if ((localB->y / vdy_wpp_P_correct_p[2]) < 100.0F) {
          /* '<S50>:1:16' */
          /* '<S50>:1:17' */
          rtb_Product1_k = GDBexp( (real32_T)rtb_exponent_d);
        }

        /* '<S50>:1:19' */
        rtb_Product1_k *= vdy_wpp_P_correct_p[1];

        /*  the exp value is raised at low speed */
        /* '<S50>:1:21' */
        /*  the corrected wheel veloctiy variance consitsts of the estimated wheel variance the wheel acceleration factor in case of abs */
        /*  and the exp value */
        /* '<S50>:1:24' */
        /* '<S50>:1:25' */
        localB->corrected_wheel_velocity_uncert = ((rtb_accel_corrected_out *
          rtb_accel_corrected_out) + rtb_vdy_sfunc_P_post_o2[0]) +
          (rtb_Product1_k * rtb_Product1_k);
      }
    } else {
      /*  if no pulse are used but velocity is below a specified value */
      if ((((uint32_T)rtu_use_pulse) != ((uint32_T)VDY_IO_STATE_VALID)) &&
          (rtu_wheel_velocity <= vdy_wpp_P_correct_p[3])) {
        /* '<S50>:1:29' */
        /* '<S50>:1:30' */
        /*  add constant value to wheel velocity variance (vdy_wpp_P_correct_p(5)) the velocity is really not known */
        /* '<S50>:1:32' */
        localB->corrected_wheel_velocity_uncert = (rtb_vdy_sfunc_P_post_o2[0] +
          vdy_wpp_P_correct_p[4]) - (((rtb_vdy_sfunc_P_post_o2[0] +
          vdy_wpp_P_correct_p[4]) - (((rtb_accel_corrected_out *
          rtb_accel_corrected_out) + rtb_vdy_sfunc_P_post_o2[0]) +
          rtu_aqua_slip_correction)) * rtu_wheel_velocity);
      } else {
        /*  best case pulse are available  */
        /* '<S50>:1:35' */
        /*  the corrected variance consists out of the estimated variance the wheel acceleration correction (ABS) */
        /*  and the aquaplaning and slip correction factor */
        /* '<S50>:1:38' */
        localB->corrected_wheel_velocity_uncert = ((rtb_accel_corrected_out *
          rtb_accel_corrected_out) + rtb_vdy_sfunc_P_post_o2[0]) +
          rtu_aqua_slip_correction;
      }
    }

    /*  limit variance to avoid getting very huge numbers in later ve calculations */
    if (localB->corrected_wheel_velocity_uncert > vdy_wpp_P_correct_p[5]) {
      /* '<S50>:1:42' */
      /* '<S50>:1:43' */
      localB->corrected_wheel_velocity_uncert = vdy_wpp_P_correct_p[5];
    }
  } else {
    /*  no wheel velocity is available, set variance to a default value */
    /* '<S50>:1:47' */
    localB->corrected_wheel_velocity_uncert = vdy_wpp_P_correct_p[5];
  }

  /* Embedded MATLAB: '<S36>/limit_accel' incorporates:
   *  S-Function (ex_sfun_abs): '<S36>/diff_abs1'
   */
  /* Embedded MATLAB Function 'puls wheel speed fusion/limit_accel': '<S57>:1' */
  /* if accel is below 0.001 set to zero */
  if (CML_f_Abs( (real32_T)rtb_x_post[1]) < 0.001F) {
    /* '<S57>:1:3' */
    /* '<S57>:1:4' */
    localB->y_g = 0.0F;
  } else {
    /* '<S57>:1:6' */
    localB->y_g = rtb_x_post[1];
  }

  /* Update for UnitDelay: '<S70>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S70>/FixPt Constant'
   */
  localDW->FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S70>/FixPt Unit Delay1' */
  for (i = 0; i < 2; i++) {
    localDW->FixPtUnitDelay1_DSTATE[(i)] = rtb_x_post[i];
  }

  /* Update for UnitDelay: '<S79>/1th_Delay' */
  localDW->th_Delay_DSTATE = rtb_th_Delay;

  /* Update for UnitDelay: '<S79>/2th_Delay' */
  localDW->th_Delay_DSTATE_b = rtb_th_Delay_g;

  /* Update for UnitDelay: '<S79>/3th_Delay' */
  localDW->th_Delay_DSTATE_f = rtb_th_Delay_c;

  /* Update for UnitDelay: '<S79>/4th_Delay' */
  localDW->th_Delay_DSTATE_o = rtb_th_Delay1;

  /* Update for UnitDelay: '<S79>/1th_Delay1' */
  localDW->th_Delay1_DSTATE = rtb_th_Delay1_b;

  /* Update for UnitDelay: '<S79>/2th_Delay1' */
  localDW->th_Delay1_DSTATE_f = rtb_th_Delay1_h;

  /* Update for UnitDelay: '<S79>/3th_Delay1' */
  localDW->th_Delay1_DSTATE_j = wheel_puls_velocity_out;

  /* Update for UnitDelay: '<S37>/init_delay' */
  localDW->init_delay_DSTATE = FALSE;

  /* Update for UnitDelay: '<S37>/puls_speed_delay' */
  localDW->puls_speed_delay_DSTATE = wheel_puls_velocity_out;

  /* Update for UnitDelay: '<S37>/counter_delay' */
  localDW->counter_delay_DSTATE = counter_out;

  /* Update for UnitDelay: '<S37>/m_delay' */
  localDW->m_delay_DSTATE = m_out;

  /* Update for UnitDelay: '<S37>/single_puls_velocity_delay' */
  localDW->single_puls_velocity_delay_DSTA = rtb_single_puls_velocity_out;

  /* Update for UnitDelay: '<S76>/T3' */
  localDW->T3_DSTATE = rtb_T2;

  /* Update for UnitDelay: '<S76>/T2' */
  localDW->T2_DSTATE = rtb_T1;

  /* Update for UnitDelay: '<S76>/T1' */
  localDW->T1_DSTATE = rtb_T0;

  /* Update for UnitDelay: '<S76>/T0' */
  localDW->T0_DSTATE = localB->y;

  /* Update for UnitDelay: '<S58>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->y_g;

  /* Update for UnitDelay: '<S56>/P_delay' */
  for (i = 0; i < 4; i++) {
    localDW->P_delay_DSTATE[(i)] = rtb_vdy_sfunc_P_post_o2[i];
  }

  /* Update for UnitDelay: '<S41>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE_o = rtu_wheel_velocity_valid;

  /* Update for UnitDelay: '<S41>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_e = localB->y;

  /* Update for UnitDelay: '<S39>/last_accel_corr' */
  localDW->last_accel_corr_DSTATE = rtb_accel_corrected_out;

  /* Update for UnitDelay: '<S39>/last_accel_corr_step' */
  localDW->last_accel_corr_step_DSTATE = rtb_Init;

  /* Update for UnitDelay: '<S39>/last_accel_corr_max' */
  localDW->last_accel_corr_max_DSTATE = rtb_last_accel_corr;
}

/* Model step function */
void vdy_wpp_step(BlockIO_vdy_wpp *vdy_wpp_B, D_Work_vdy_wpp *vdy_wpp_DWork,
                  VDYInputData_t *vdy_wpp_U_VDYInputData, VDYInternalData_t
                  *vdy_wpp_U_VDYInternalData, VDYInternalData_t
                  *vdy_wpp_Y_VDYInternalData_out)
{
  /* local block i/o variables */
  real32_T rtb_WhlCircumference;
  real32_T rtb_WhlVelFrLeft;
  real32_T rtb_WhlVelFrRight;
  real32_T rtb_WhlVelReLeft;
  real32_T rtb_WhlVelReRight;
  real32_T rtb_slip_aqua_correct_front_rig;
  real32_T rtb_slip_aqua_correct_rear_righ;
  real32_T rtb_front_to_rear_right;
  real32_T rtb_factor;
  real32_T rtb_rear_to_front_right;
  real32_T rtb_slip_aqua_correct_front_lef;
  real32_T rtb_slip_aqua_correct_rear_left;
  real32_T rtb_front_to_rear_left_c;
  real32_T rtb_factor_h;
  real32_T rtb_rear_to_front_left_p;
  real32_T rtb_corrected_front_left_value;
  real32_T rtb_corrected_front_right_value;
  real32_T rtb_corrected_rear_left_value;
  real32_T rtb_corrected_rear_right_value;
  real32_T rtb_Time2Sec;
  uint8_T rtb_WhlTicksDevFrLeft;
  uint8_T rtb_WhlTicksDevFrRight;
  uint8_T rtb_WhlTicksDevReLeft;
  uint8_T rtb_WhlTicksDevReRight;
  uint8_T rtb_WhlTcksPerRev;
  uint8_T rtb_State[32];
  real32_T mean_velocity_left;
  boolean_T LeftReference;
  uint8_T rtb_aqua_slip_state_FL_out;
  uint8_T rtb_aqua_slip_state_FR_out;
  uint8_T rtb_aqua_slip_state_RL_out;
  uint8_T rtb_aqua_slip_state_RR_out;
  real32_T rtb_y;
  real32_T rtb_rear_to_front_left;
  int32_T rtb_slip_aqua_correct_rear_le_e;
  int32_T rtb_slip_aqua_correct_front_r_g;
  int32_T rtb_slip_aqua_correct_rear_ri_o;
  int32_T i;

  /* BusSelector: '<Root>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_WhlTicksDevFrLeft = (*vdy_wpp_U_VDYInputData).Signals.WhlTicksDevFrLeft;
  rtb_WhlTicksDevFrRight = (*vdy_wpp_U_VDYInputData).Signals.WhlTicksDevFrRight;
  rtb_WhlTicksDevReLeft = (*vdy_wpp_U_VDYInputData).Signals.WhlTicksDevReLeft;
  rtb_WhlTicksDevReRight = (*vdy_wpp_U_VDYInputData).Signals.WhlTicksDevReRight;
  rtb_WhlTcksPerRev = (*vdy_wpp_U_VDYInputData).Parameter.WhlTcksPerRev;
  rtb_WhlCircumference = (*vdy_wpp_U_VDYInputData).Parameter.WhlCircumference;
  rtb_WhlVelFrLeft = (*vdy_wpp_U_VDYInputData).Signals.WhlVelFrLeft;
  rtb_WhlVelFrRight = (*vdy_wpp_U_VDYInputData).Signals.WhlVelFrRight;
  rtb_WhlVelReLeft = (*vdy_wpp_U_VDYInputData).Signals.WhlVelReLeft;
  rtb_WhlVelReRight = (*vdy_wpp_U_VDYInputData).Signals.WhlVelReRight;
  for (i = 0; i < 32; i++) {
    rtb_State[i] = (*vdy_wpp_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<Root>/Time2Sec' */

  /* Product: '<S10>/Time2Sec' incorporates:
   *  Constant: '<S10>/Constant'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_Time2Sec = ((real32_T)(*vdy_wpp_U_VDYInputData).Frame.CycleTime) / 1000.0F;

  /* end of Outputs for SubSystem: '<Root>/Time2Sec' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WVEL_FL' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WVEL_FL,
    ((uint32_T)VDY_SIN_POS_WVEL_FL));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WVEL_FL' */

  /* Embedded MATLAB: '<S11>/four_wheel_mean' incorporates:
   *  SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* Embedded MATLAB Function 'aqua slip correction/four_wheel_mean': '<S17>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S17>:1:5' */
  rtb_y = (((rtb_WhlVelFrLeft + rtb_WhlVelReLeft) + rtb_WhlVelFrRight) +
           rtb_WhlVelReRight) * 0.25F;

  /* Embedded MATLAB: '<S21>/left_side_aqua_slip_correction1' */
  mean_velocity_left = rtb_WhlVelFrLeft;
  rtb_rear_to_front_left = rtb_WhlVelReLeft;

  /* Embedded MATLAB Function 'aqua slip correction/left_side_aqua_slip_correction/calc_factor/left_side_aqua_slip_correction1': '<S23>:1' */
  /*  check for diff zero */
  if (rtb_WhlVelReLeft < 0.0001F) {
    /* '<S23>:1:6' */
    /* '<S23>:1:7' */
    rtb_rear_to_front_left = 0.0001F;
  }

  if (rtb_WhlVelFrLeft < 0.0001F) {
    /* '<S23>:1:9' */
    /* '<S23>:1:10' */
    mean_velocity_left = 0.0001F;
  }

  /*  check if exponent is (fl/rl) in range of float */
  /* '<S23>:1:14' */
  rtb_front_to_rear_left_c = (mean_velocity_left / rtb_rear_to_front_left) /
    vdy_wpp_aqua_slip_correct_p[0];
  if (rtb_front_to_rear_left_c > 80.0F) {
    /* '<S23>:1:15' */
    /* '<S23>:1:16' */
    rtb_front_to_rear_left_c = 80.0F;
  }

  /*  check if exponent is (rl/fl) in range of float */
  /* '<S23>:1:20' */
  rtb_rear_to_front_left_p = (rtb_rear_to_front_left / mean_velocity_left) /
    vdy_wpp_aqua_slip_correct_p[0];
  if (rtb_rear_to_front_left_p > 80.0F) {
    /* '<S23>:1:21' */
    /* '<S23>:1:22' */
    rtb_rear_to_front_left_p = 80.0F;
  }

  /* '<S23>:1:24' */
  rtb_factor_h = 0.98F / vdy_wpp_aqua_slip_correct_p[0];

  /* Embedded MATLAB: '<S21>/left_side_aqua_slip_correction2' incorporates:
   *  S-Function (ex_sfun_exp): '<S21>/S-Function'
   *  S-Function (ex_sfun_exp): '<S21>/S-Function1'
   *  S-Function (ex_sfun_exp): '<S21>/S-Function2'
   */
  /* Embedded MATLAB Function 'aqua slip correction/left_side_aqua_slip_correction/calc_factor/left_side_aqua_slip_correction2': '<S24>:1' */
  /* '<S24>:1:4' */
  rtb_slip_aqua_correct_rear_left = GDBexp( (real32_T)rtb_front_to_rear_left_c)
    - GDBexp( (real32_T)rtb_factor_h);

  /* '<S24>:1:5' */
  rtb_rear_to_front_left = GDBexp( (real32_T)rtb_rear_to_front_left_p) - GDBexp(
    (real32_T)rtb_factor_h);

  /* Embedded MATLAB: '<S19>/left_side_aqua_slip_correction' */
  /* Embedded MATLAB Function 'aqua slip correction/left_side_aqua_slip_correction/left_side_aqua_slip_correction': '<S22>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S22>:1:8' */
  mean_velocity_left = (rtb_WhlVelFrLeft + rtb_WhlVelReLeft) / 2.0F;

  /*  the trend to the front or the rear wheel speed */
  /*  left side  */
  /*  LeftReference true = front, false = rear */
  /*  Vm four wheel mean velocity */
  /*  Vl left wheel mean velocity */
  /*  R velocity rear */
  /*  F velocity front */
  /* '<S22>:1:16' */
  LeftReference = TRUE;

  /*  check the 8 cases */
  if (rtb_y < mean_velocity_left) {
    /* '<S22>:1:18' */
    if (rtb_WhlVelFrLeft > mean_velocity_left) {
      /* '<S22>:1:19' */
      /*  use the rear axle as reference */
      /*  Vm | R* | Vl | F */
      if (rtb_WhlVelReLeft > rtb_y) {
        /* '<S22>:1:22' */
        /* '<S22>:1:23' */
        LeftReference = FALSE;
      }

      /*  use the rear axle as reference */
      /*   R* | Vm | Vl | F */
      if (rtb_WhlVelReLeft < rtb_y) {
        /* '<S22>:1:27' */
        /* '<S22>:1:28' */
        LeftReference = FALSE;
      }
    }

    if (rtb_WhlVelReLeft > mean_velocity_left) {
      /* '<S22>:1:32' */
      /*  use the front axle as reference */
      /*   F* | Vm | Vl | R */
      if (rtb_WhlVelFrLeft < rtb_y) {
        /* '<S22>:1:35' */
        /* '<S22>:1:36' */
        LeftReference = TRUE;
      }

      /*  use the front axle as reference */
      /*  Vm | F* | Vl | R */
      if (rtb_WhlVelFrLeft > rtb_y) {
        /* '<S22>:1:40' */
        /* '<S22>:1:41' */
        LeftReference = TRUE;
      }
    }
  } else {
    if ((rtb_WhlVelFrLeft > mean_velocity_left) && (rtb_WhlVelFrLeft > rtb_y)) {
      /* '<S22>:1:45' */
      /*  use the front axis as reference */
      /*  R | Vl | F* | Vm */
      /*  use the front axle as reference */
      /*   R | Vl | Vm | F* */
      /* '<S22>:1:53' */
      /* '<S22>:1:54' */
      LeftReference = TRUE;
    }

    if (rtb_WhlVelReLeft > mean_velocity_left) {
      /* '<S22>:1:58' */
      /*  use the rear axle as reference */
      /*   F | Vl | Vm | R* */
      if (rtb_WhlVelReLeft > rtb_y) {
        /* '<S22>:1:61' */
        /* '<S22>:1:62' */
        LeftReference = FALSE;
      }

      /*  use the rear axle as reference */
      /*  F | Vl | R* | Vm */
      if (rtb_WhlVelReLeft < rtb_y) {
        /* '<S22>:1:66' */
        /* '<S22>:1:67' */
        LeftReference = FALSE;
      }
    }
  }

  /*  if LeftReference == false then use the rear axle as reference */
  if (((int32_T)LeftReference) == 0) {
    /* '<S22>:1:74' */
    /*  Left front wheel slips */
    if ((rtb_WhlVelReLeft - rtb_WhlVelFrLeft) <= 0.0F) {
      /* '<S22>:1:76' */
      /* '<S22>:1:77' */
      rtb_slip_aqua_correct_front_lef = rtb_slip_aqua_correct_rear_left;

      /* '<S22>:1:78' */
      i = 2;

      /* '<S22>:1:80' */
      rtb_slip_aqua_correct_rear_left = rtb_rear_to_front_left;

      /* '<S22>:1:81' */
      rtb_slip_aqua_correct_rear_le_e = 1;
    } else {
      /*  left front wheel aqua */
      /* '<S22>:1:83' */
      rtb_slip_aqua_correct_front_lef = rtb_rear_to_front_left;

      /* '<S22>:1:84' */
      i = 0;

      /* '<S22>:1:86' */
      /* '<S22>:1:87' */
      rtb_slip_aqua_correct_rear_le_e = 1;
    }
  } else {
    /*  use the front axle as reference */
    /*  Left rear wheel slips */
    if ((rtb_WhlVelFrLeft - rtb_WhlVelReLeft) <= 0.0F) {
      /* '<S22>:1:91' */
      /* '<S22>:1:92' */
      rtb_slip_aqua_correct_front_lef = rtb_slip_aqua_correct_rear_left;

      /* '<S22>:1:93' */
      i = 1;

      /* '<S22>:1:95' */
      rtb_slip_aqua_correct_rear_left = rtb_rear_to_front_left;

      /* '<S22>:1:96' */
      rtb_slip_aqua_correct_rear_le_e = 2;
    } else {
      /*  left rear wheel aqua */
      /* '<S22>:1:98' */
      rtb_slip_aqua_correct_front_lef = rtb_rear_to_front_left;

      /* '<S22>:1:99' */
      i = 1;

      /* '<S22>:1:101' */
      /* '<S22>:1:102' */
      rtb_slip_aqua_correct_rear_le_e = 0;
    }
  }

  /* Embedded MATLAB: '<S25>/right_side_aqua_slip_correction_factors' */
  mean_velocity_left = rtb_WhlVelFrRight;
  rtb_rear_to_front_left = rtb_WhlVelReRight;

  /* Embedded MATLAB Function 'aqua slip correction/right_side_aqua_slip_correction/calc_factor/right_side_aqua_slip_correction_factors': '<S28>:1' */
  /*  check for diff zero */
  if (rtb_WhlVelReRight < 0.0001F) {
    /* '<S28>:1:6' */
    /* '<S28>:1:7' */
    rtb_rear_to_front_left = 0.0001F;
  }

  if (rtb_WhlVelFrRight < 0.0001F) {
    /* '<S28>:1:9' */
    /* '<S28>:1:10' */
    mean_velocity_left = 0.0001F;
  }

  /*  check if exponent is (fr/rr) in range of float */
  /* '<S28>:1:14' */
  rtb_front_to_rear_right = (mean_velocity_left / rtb_rear_to_front_left) /
    vdy_wpp_aqua_slip_correct_p[0];
  if (rtb_front_to_rear_right > 80.0F) {
    /* '<S28>:1:15' */
    /* '<S28>:1:16' */
    rtb_front_to_rear_right = 80.0F;
  }

  /*  check if exponent is (rr/fr) in range of float */
  /* '<S28>:1:20' */
  rtb_rear_to_front_right = (rtb_rear_to_front_left / mean_velocity_left) /
    vdy_wpp_aqua_slip_correct_p[0];
  if (rtb_rear_to_front_right > 80.0F) {
    /* '<S28>:1:21' */
    /* '<S28>:1:22' */
    rtb_rear_to_front_right = 80.0F;
  }

  /* '<S28>:1:24' */
  rtb_factor = 0.98F / vdy_wpp_aqua_slip_correct_p[1];

  /* Embedded MATLAB: '<S25>/right_side_aqua_slip_correction_exp' incorporates:
   *  S-Function (ex_sfun_exp): '<S25>/S-Function'
   *  S-Function (ex_sfun_exp): '<S25>/S-Function1'
   *  S-Function (ex_sfun_exp): '<S25>/S-Function2'
   */
  /* Embedded MATLAB Function 'aqua slip correction/right_side_aqua_slip_correction/calc_factor/right_side_aqua_slip_correction_exp': '<S27>:1' */
  /* '<S27>:1:4' */
  rtb_slip_aqua_correct_rear_righ = GDBexp( (real32_T)rtb_front_to_rear_right) -
    GDBexp( (real32_T)rtb_factor);

  /* '<S27>:1:5' */
  mean_velocity_left = GDBexp( (real32_T)rtb_rear_to_front_right) - GDBexp
    ( (real32_T)rtb_factor);

  /* Embedded MATLAB: '<S20>/right_side_aqua_slip_crrection_org' */
  /* Embedded MATLAB Function 'aqua slip correction/right_side_aqua_slip_correction/right_side_aqua_slip_crrection_org': '<S26>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S26>:1:8' */
  rtb_rear_to_front_left = (rtb_WhlVelFrRight + rtb_WhlVelReRight) / 2.0F;

  /*  the trend to the front or the rear wheel speed */
  /*  right side  */
  /*  RightReference true = front, false = rear */
  /*  Vm four wheel mean velocity */
  /*  Vr right wheel mean velocity */
  /*  R velocity rear */
  /*  F velocity front */
  /* '<S26>:1:16' */
  LeftReference = TRUE;

  /*  check the 8 cases */
  if (rtb_y < rtb_rear_to_front_left) {
    /* '<S26>:1:18' */
    if (rtb_WhlVelFrRight > rtb_rear_to_front_left) {
      /* '<S26>:1:19' */
      /*  use the rear axle as reference */
      /*  Vm | *R | Vl | F */
      if (rtb_WhlVelReRight > rtb_y) {
        /* '<S26>:1:22' */
        /* '<S26>:1:23' */
        LeftReference = FALSE;
      }

      /*  use the rear axle as reference */
      /*   R* | Vm | Vl | F */
      if (rtb_WhlVelReRight < rtb_y) {
        /* '<S26>:1:27' */
        /* '<S26>:1:28' */
        LeftReference = FALSE;
      }
    }

    if (rtb_WhlVelReRight > rtb_rear_to_front_left) {
      /* '<S26>:1:32' */
      /*  use the front axle as reference */
      /*   F* | Vm | Vl | R */
      if (rtb_WhlVelFrRight < rtb_y) {
        /* '<S26>:1:35' */
        /* '<S26>:1:36' */
        LeftReference = TRUE;
      }

      /*  use the front axle as referenece */
      /*  Vm | F* | Vl | R */
      if (rtb_WhlVelFrRight > rtb_y) {
        /* '<S26>:1:40' */
        /* '<S26>:1:41' */
        LeftReference = TRUE;
      }
    }
  } else {
    if ((rtb_WhlVelFrRight > rtb_rear_to_front_left) && (rtb_WhlVelFrRight >
         rtb_y)) {
      /* '<S26>:1:45' */
      /*  use the front axle as reference */
      /*  R | Vl | F* | Vm */
      /*  use the front axle as reference */
      /*   R | Vl | Vm | F* */
      /* '<S26>:1:53' */
      /* '<S26>:1:54' */
      LeftReference = TRUE;
    }

    if (rtb_WhlVelReRight > rtb_rear_to_front_left) {
      /* '<S26>:1:58' */
      /*  use the rear axle as referenece */
      /*   F | Vl | Vm | R* */
      if (rtb_WhlVelReRight > rtb_y) {
        /* '<S26>:1:61' */
        /* '<S26>:1:62' */
        LeftReference = FALSE;
      }

      /*  use the rear axle as referenece */
      /*  F | Vl | R* | Vm */
      if (rtb_WhlVelReRight < rtb_y) {
        /* '<S26>:1:66' */
        /* '<S26>:1:67' */
        LeftReference = FALSE;
      }
    }
  }

  /*  if RightReference == false then use the rear axle as reference */
  if (((int32_T)LeftReference) == 0) {
    /* '<S26>:1:74' */
    /*  Right front wheel slips */
    if ((rtb_WhlVelReRight - rtb_WhlVelFrRight) <= 0.0F) {
      /* '<S26>:1:76' */
      /* '<S26>:1:77' */
      rtb_slip_aqua_correct_front_rig = rtb_slip_aqua_correct_rear_righ;

      /* '<S26>:1:78' */
      rtb_slip_aqua_correct_front_r_g = 2;

      /* '<S26>:1:80' */
      rtb_slip_aqua_correct_rear_righ = mean_velocity_left;

      /* '<S26>:1:81' */
      rtb_slip_aqua_correct_rear_ri_o = 1;
    } else {
      /*  right front wheel aqua */
      /* '<S26>:1:83' */
      rtb_slip_aqua_correct_front_rig = mean_velocity_left;

      /* '<S26>:1:84' */
      rtb_slip_aqua_correct_front_r_g = 0;

      /* '<S26>:1:86' */
      /* '<S26>:1:87' */
      rtb_slip_aqua_correct_rear_ri_o = 1;
    }
  } else {
    /*  use the front axle as reference */
    /*  Right rear wheel slips */
    if ((rtb_WhlVelFrRight - rtb_WhlVelReRight) <= 0.0F) {
      /* '<S26>:1:91' */
      /* '<S26>:1:92' */
      rtb_slip_aqua_correct_front_rig = rtb_slip_aqua_correct_rear_righ;

      /* '<S26>:1:93' */
      rtb_slip_aqua_correct_front_r_g = 1;

      /* '<S26>:1:95' */
      rtb_slip_aqua_correct_rear_righ = mean_velocity_left;

      /* '<S26>:1:96' */
      rtb_slip_aqua_correct_rear_ri_o = 2;
    } else {
      /*  right rear wheel aqua */
      /* '<S26>:1:98' */
      rtb_slip_aqua_correct_front_rig = mean_velocity_left;

      /* '<S26>:1:99' */
      rtb_slip_aqua_correct_front_r_g = 1;

      /* '<S26>:1:101' */
      /* '<S26>:1:102' */
      rtb_slip_aqua_correct_rear_ri_o = 0;
    }
  }

  /* Embedded MATLAB: '<S11>/left_right_correction_fusion' incorporates:
   *  S-Function (ex_sfun_abs): '<S11>/abs_corrected_front_left_value_in'
   *  S-Function (ex_sfun_abs): '<S11>/abs_corrected_front_right_value_in'
   *  S-Function (ex_sfun_abs): '<S11>/abs_corrected_rear_left_value_in'
   *  S-Function (ex_sfun_abs): '<S11>/abs_corrected_rear_right_value_in'
   */
  /* Embedded MATLAB Function 'aqua slip correction/left_right_correction_fusion': '<S18>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  if ((((rtb_WhlVelFrLeft < 0.01F) || (rtb_WhlVelFrRight < 0.01F)) ||
       (rtb_WhlVelReLeft < 0.01F)) || (rtb_WhlVelReRight < 0.01F)) {
    /* '<S18>:1:22' */
    /* '<S18>:1:23' */
    rtb_corrected_front_left_value = 0.0F;

    /* '<S18>:1:24' */
    i = 1;

    /* '<S18>:1:25' */
    rtb_corrected_front_right_value = 0.0F;

    /* '<S18>:1:26' */
    rtb_slip_aqua_correct_front_r_g = 1;

    /* '<S18>:1:27' */
    rtb_corrected_rear_left_value = 0.0F;

    /* '<S18>:1:28' */
    rtb_slip_aqua_correct_rear_le_e = 1;

    /* '<S18>:1:29' */
    rtb_corrected_rear_right_value = 0.0F;

    /* '<S18>:1:30' */
    rtb_slip_aqua_correct_rear_ri_o = 1;
  } else {
    /* '<S18>:1:32' */
    rtb_corrected_front_left_value = CML_f_Abs( (real32_T)
      rtb_slip_aqua_correct_front_lef);

    /* '<S18>:1:33' */
    /* '<S18>:1:34' */
    rtb_corrected_front_right_value = CML_f_Abs( (real32_T)
      rtb_slip_aqua_correct_front_rig);

    /* '<S18>:1:35' */
    /* '<S18>:1:36' */
    rtb_corrected_rear_left_value = CML_f_Abs( (real32_T)
      rtb_slip_aqua_correct_rear_left);

    /* '<S18>:1:37' */
    /* '<S18>:1:38' */
    rtb_corrected_rear_right_value = CML_f_Abs( (real32_T)
      rtb_slip_aqua_correct_rear_righ);

    /* '<S18>:1:39' */
  }

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WTCKS_FL' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WTCKS_FL,
    ((uint32_T)VDY_SIN_POS_WTCKS_FL));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WTCKS_FL' */

  /* Outputs for atomic SubSystem: '<Root>/front_left_wheel_speed_fusion' */
  wheel_speed_fusion(rtb_WhlVelFrLeft, rtb_Time2Sec, rtb_WhlCircumference,
                     rtb_WhlTcksPerRev,
                     vdy_wpp_B->Get_IO_State_WVEL_FL.IndexVector,
                     vdy_wpp_B->Get_IO_State_WTCKS_FL.IndexVector,
                     rtb_corrected_front_left_value, rtb_WhlTicksDevFrLeft,
                     &vdy_wpp_B->front_left_wheel_speed_fusion,
                     &vdy_wpp_DWork->front_left_wheel_speed_fusion);

  /* end of Outputs for SubSystem: '<Root>/front_left_wheel_speed_fusion' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WVEL_FR' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WVEL_FR,
    ((uint32_T)VDY_SIN_POS_WVEL_FR));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WVEL_FR' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WTCKS_FR' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WTCKS_FR,
    ((uint32_T)VDY_SIN_POS_WTCKS_FR));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WTCKS_FR' */

  /* Outputs for atomic SubSystem: '<Root>/front_right_wheel_speed_fusion' */
  wheel_speed_fusion(rtb_WhlVelFrRight, rtb_Time2Sec, rtb_WhlCircumference,
                     rtb_WhlTcksPerRev,
                     vdy_wpp_B->Get_IO_State_WVEL_FR.IndexVector,
                     vdy_wpp_B->Get_IO_State_WTCKS_FR.IndexVector,
                     rtb_corrected_front_right_value, rtb_WhlTicksDevFrRight,
                     &vdy_wpp_B->front_right_wheel_speed_fusion,
                     &vdy_wpp_DWork->front_right_wheel_speed_fusion);

  /* end of Outputs for SubSystem: '<Root>/front_right_wheel_speed_fusion' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WVEL_RL' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WVEL_RL,
    ((uint32_T)VDY_SIN_POS_WVEL_RL));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WVEL_RL' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WTCKS_RL' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WTCKS_RL,
    ((uint32_T)VDY_SIN_POS_WTCKS_RL));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WTCKS_RL' */

  /* Outputs for atomic SubSystem: '<Root>/rear_left_wheel_speed_fusion' */
  wheel_speed_fusion(rtb_WhlVelReLeft, rtb_Time2Sec, rtb_WhlCircumference,
                     rtb_WhlTcksPerRev,
                     vdy_wpp_B->Get_IO_State_WVEL_RL.IndexVector,
                     vdy_wpp_B->Get_IO_State_WTCKS_RL.IndexVector,
                     rtb_corrected_rear_left_value, rtb_WhlTicksDevReLeft,
                     &vdy_wpp_B->rear_left_wheel_speed_fusion,
                     &vdy_wpp_DWork->rear_left_wheel_speed_fusion);

  /* end of Outputs for SubSystem: '<Root>/rear_left_wheel_speed_fusion' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WVEL_RR' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WVEL_RR,
    ((uint32_T)VDY_SIN_POS_WVEL_RR));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WVEL_RR' */

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_WTCKS_RR' */
  vdy_wpp_Get_IO_State_WTCKS_FL(rtb_State, &vdy_wpp_B->Get_IO_State_WTCKS_RR,
    ((uint32_T)VDY_SIN_POS_WTCKS_RR));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_WTCKS_RR' */

  /* Outputs for atomic SubSystem: '<Root>/rear_right_wheel_speed_fusion' */
  wheel_speed_fusion(rtb_WhlVelReRight, rtb_Time2Sec, rtb_WhlCircumference,
                     rtb_WhlTcksPerRev,
                     vdy_wpp_B->Get_IO_State_WVEL_RR.IndexVector,
                     vdy_wpp_B->Get_IO_State_WTCKS_RR.IndexVector,
                     rtb_corrected_rear_right_value, rtb_WhlTicksDevReRight,
                     &vdy_wpp_B->rear_right_wheel_speed_fusion,
                     &vdy_wpp_DWork->rear_right_wheel_speed_fusion);

  /* end of Outputs for SubSystem: '<Root>/rear_right_wheel_speed_fusion' */

  /* Sum: '<S29>/Sum' incorporates:
   *  Gain: '<S29>/Gain'
   *  Sum: '<S29>/Diff'
   *  UnitDelay: '<S29>/FL_aqua_slip_state_delay'
   */
  vdy_wpp_DWork->FL_aqua_slip_state_delay_DSTATE =
    ((vdy_wpp_DWork->FL_aqua_slip_state_delay_DSTATE - ((real32_T)i)) * 0.8F) +
    ((real32_T)i);

  /* Sum: '<S30>/Sum' incorporates:
   *  Gain: '<S30>/Gain'
   *  Sum: '<S30>/Diff'
   *  UnitDelay: '<S30>/FR_aqua_slip_state_delay'
   */
  vdy_wpp_DWork->FR_aqua_slip_state_delay_DSTATE =
    ((vdy_wpp_DWork->FR_aqua_slip_state_delay_DSTATE - ((real32_T)
       rtb_slip_aqua_correct_front_r_g)) * 0.8F) + ((real32_T)
    rtb_slip_aqua_correct_front_r_g);

  /* Sum: '<S31>/Sum' incorporates:
   *  Gain: '<S31>/Gain'
   *  Sum: '<S31>/Diff'
   *  UnitDelay: '<S31>/RL_aqua_slip_state_delay'
   */
  vdy_wpp_DWork->RL_aqua_slip_state_delay_DSTATE =
    ((vdy_wpp_DWork->RL_aqua_slip_state_delay_DSTATE - ((real32_T)
       rtb_slip_aqua_correct_rear_le_e)) * 0.8F) + ((real32_T)
    rtb_slip_aqua_correct_rear_le_e);

  /* Sum: '<S32>/Sum' incorporates:
   *  Gain: '<S32>/Gain'
   *  Sum: '<S32>/Diff'
   *  UnitDelay: '<S32>/RR_aqua_slip_state_delay'
   */
  vdy_wpp_DWork->RR_aqua_slip_state_delay_DSTATE =
    ((vdy_wpp_DWork->RR_aqua_slip_state_delay_DSTATE - ((real32_T)
       rtb_slip_aqua_correct_rear_ri_o)) * 0.8F) + ((real32_T)
    rtb_slip_aqua_correct_rear_ri_o);

  /* Embedded MATLAB: '<S12>/threshold_aqua_slip_state' */
  /* Embedded MATLAB Function 'aqua_slip_state_output/threshold_aqua_slip_state': '<S33>:1' */
  /*  if the filtered aqua slip state is above 95% set the output to this state */
  /* '<S33>:1:3' */
  /* '<S33>:1:4' */
  if (vdy_wpp_DWork->FL_aqua_slip_state_delay_DSTATE > 1.95F) {
    /* '<S33>:1:8' */
    /* '<S33>:1:9' */
    rtb_aqua_slip_state_FL_out = 2U;
  } else if (vdy_wpp_DWork->FL_aqua_slip_state_delay_DSTATE < 0.05F) {
    /* '<S33>:1:10' */
    /* '<S33>:1:11' */
    rtb_aqua_slip_state_FL_out = 0U;
  } else {
    /* '<S33>:1:13' */
    rtb_aqua_slip_state_FL_out = 1U;
  }

  if (vdy_wpp_DWork->FR_aqua_slip_state_delay_DSTATE > 1.95F) {
    /* '<S33>:1:16' */
    /* '<S33>:1:17' */
    rtb_aqua_slip_state_FR_out = 2U;
  } else if (vdy_wpp_DWork->FR_aqua_slip_state_delay_DSTATE < 0.05F) {
    /* '<S33>:1:18' */
    /* '<S33>:1:19' */
    rtb_aqua_slip_state_FR_out = 0U;
  } else {
    /* '<S33>:1:21' */
    rtb_aqua_slip_state_FR_out = 1U;
  }

  if (vdy_wpp_DWork->RL_aqua_slip_state_delay_DSTATE > 1.95F) {
    /* '<S33>:1:24' */
    /* '<S33>:1:25' */
    rtb_aqua_slip_state_RL_out = 2U;
  } else if (vdy_wpp_DWork->RL_aqua_slip_state_delay_DSTATE < 0.05F) {
    /* '<S33>:1:26' */
    /* '<S33>:1:27' */
    rtb_aqua_slip_state_RL_out = 0U;
  } else {
    /* '<S33>:1:29' */
    rtb_aqua_slip_state_RL_out = 1U;
  }

  if (vdy_wpp_DWork->RR_aqua_slip_state_delay_DSTATE > 1.95F) {
    /* '<S33>:1:32' */
    /* '<S33>:1:33' */
    rtb_aqua_slip_state_RR_out = 2U;
  } else if (vdy_wpp_DWork->RR_aqua_slip_state_delay_DSTATE < 0.05F) {
    /* '<S33>:1:34' */
    /* '<S33>:1:35' */
    rtb_aqua_slip_state_RR_out = 0U;
  } else {
    /* '<S33>:1:37' */
    rtb_aqua_slip_state_RR_out = 1U;
  }

  /* BusAssignment: '<Root>/BusAssign' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  (*vdy_wpp_Y_VDYInternalData_out) = (*vdy_wpp_U_VDYInternalData);
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_front_left =
    vdy_wpp_B->front_left_wheel_speed_fusion.y;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_front_left_var =
    vdy_wpp_B->front_left_wheel_speed_fusion.corrected_wheel_velocity_uncert;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_accel_front_left =
    vdy_wpp_B->front_left_wheel_speed_fusion.y_g;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_front_right =
    vdy_wpp_B->front_right_wheel_speed_fusion.y;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_front_right_var =
    vdy_wpp_B->front_right_wheel_speed_fusion.corrected_wheel_velocity_uncert;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_accel_front_right =
    vdy_wpp_B->front_right_wheel_speed_fusion.y_g;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_rear_left =
    vdy_wpp_B->rear_left_wheel_speed_fusion.y;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_rear_left_var =
    vdy_wpp_B->rear_left_wheel_speed_fusion.corrected_wheel_velocity_uncert;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_accel_rear_left =
    vdy_wpp_B->rear_left_wheel_speed_fusion.y_g;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_rear_right =
    vdy_wpp_B->rear_right_wheel_speed_fusion.y;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_velo_rear_right_var =
    vdy_wpp_B->rear_right_wheel_speed_fusion.corrected_wheel_velocity_uncert;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.wheel_accel_rear_right =
    vdy_wpp_B->rear_right_wheel_speed_fusion.y_g;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.aqua_slip_state_front_left =
    rtb_aqua_slip_state_FL_out;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.aqua_slip_state_front_right =
    rtb_aqua_slip_state_FR_out;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.aqua_slip_state_rear_left =
    rtb_aqua_slip_state_RL_out;
  (*vdy_wpp_Y_VDYInternalData_out).vdy_wpp_out.aqua_slip_state_rear_right =
    rtb_aqua_slip_state_RR_out;
}

/* Model initialize function */
void vdy_wpp_initialize(boolean_T firstTime, BlockIO_vdy_wpp *vdy_wpp_B,
  D_Work_vdy_wpp *vdy_wpp_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_wpp_B), 0,
                      sizeof(BlockIO_vdy_wpp));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_wpp_DWork, 0,
                      sizeof(D_Work_vdy_wpp));

  /* InitializeConditions for atomic SubSystem: '<Root>/front_left_wheel_speed_fusion' */
  wheel_speed_fusion_Init(&vdy_wpp_DWork->front_left_wheel_speed_fusion);

  /* end of InitializeConditions for SubSystem: '<Root>/front_left_wheel_speed_fusion' */

  /* InitializeConditions for atomic SubSystem: '<Root>/front_right_wheel_speed_fusion' */
  wheel_speed_fusion_Init(&vdy_wpp_DWork->front_right_wheel_speed_fusion);

  /* end of InitializeConditions for SubSystem: '<Root>/front_right_wheel_speed_fusion' */

  /* InitializeConditions for atomic SubSystem: '<Root>/rear_left_wheel_speed_fusion' */
  wheel_speed_fusion_Init(&vdy_wpp_DWork->rear_left_wheel_speed_fusion);

  /* end of InitializeConditions for SubSystem: '<Root>/rear_left_wheel_speed_fusion' */

  /* InitializeConditions for atomic SubSystem: '<Root>/rear_right_wheel_speed_fusion' */
  wheel_speed_fusion_Init(&vdy_wpp_DWork->rear_right_wheel_speed_fusion);

  /* end of InitializeConditions for SubSystem: '<Root>/rear_right_wheel_speed_fusion' */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
