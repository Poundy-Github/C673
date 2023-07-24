/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_aye.c
   Real-Time Workshop code generated for Simulink model vdy_aye.
   Model version                        : 1.2418
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:03:15 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:03:15 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy ay yaw rate estimation,
   use lateral acceleration signal and
   offset compensated yaw rate to calculate
   the ay yaw rate
   VERSION:                             : $Revision: 1.6 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_aye.h"
#include "vdy_aye_private.h"

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
void vdy_aye_step(BlockIO_vdy_aye *vdy_aye_B, D_Work_vdy_aye *vdy_aye_DWork,
                  VDYInputData_t *vdy_aye_U_VDYInputData, VDYInternalData_t
                  *vdy_aye_U_VDYInternalData_in, VDYInternalData_t
                  *vdy_aye_Y_vdy_aye_out)
{
  /* local block i/o variables */
  real32_T rtb_x_pred[4];
  real32_T rtb_gier_yaw_rate_g;
  real32_T rtb_Sum;
  real32_T rtb_P_pred[16];
  real32_T rtb_HPHt_R[4];
  real32_T rtb_P_predHt[8];
  real32_T rtb_K[8];
  real32_T rtb_P_post[16];
  real32_T rtb_x_post[4];
  real32_T rtb_diff;
  real32_T rtb_y_b;
  real32_T rtb_H[8];
  real32_T rtb_x_out[4];
  real32_T rtb_P_pred_out[16];
  real32_T rtb_vdy_sfunc_HP_o2[8];
  real32_T rtb_Ht[8];
  real32_T rtb_vdy_sfunc_HP_Ht_o2[4];
  real32_T rtb_nu[2];
  real32_T rtb_At[16];
  real32_T rtb_Knu[4];
  real32_T rtb_vdy_sfunc_AP_At_o2[16];
  real32_T rtb_KH[16];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_vdy_sfunc_K_nu_o1;
  real32_T rtb_Time2Sec;
  real32_T rtb_xpost[4];
  VDYInternalData_t rtb_ay_yaw_rate;
  real32_T rtb_z_out[2];
  real32_T rtb_hx[2];
  uint8_T rtb_R_onoff;
  uint8_T rtb_BankRoadDelay1;
  real32_T rtb_Sum_m[16];
  real32_T rtb_R_out[4];
  int32_T i;
  real32_T tmp[16];
  int32_T i_0;
  static int8_T tmp_0[4] = { 0, 1, 0, 0 };

  /* Embedded MATLAB: '<S10>/gnerate_z_vector' incorporates:
   *  Constant: '<S26>/Constant1'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  MultiPortSwitch: '<S26>/Index Vector'
   */
  /* Embedded MATLAB Function 'make_z_vektor/gnerate_z_vector': '<S27>:1' */
  /*  check if the velocity is above 3.0 m/s */
  if ((*vdy_aye_U_VDYInternalData_in).vdy_ve_out.veh_velo >= 3.0F) {
    /* '<S27>:1:3' */
    /*  check if the lateral acceleration signal is valid */
    if (((uint32_T)(*vdy_aye_U_VDYInputData).Signals.State[(((uint32_T)
           VDY_SIN_POS_LATA))]) == ((uint32_T)VDY_IO_STATE_VALID)) {
      /* '<S27>:1:5' */
      /*  if the lat offset state is above 1 */
      if ((*vdy_aye_U_VDYInternalData_in).vdy_offsets_in.vdy_ay_offset.state > 1)
      {
        /* '<S27>:1:7' */
        /* '<S27>:1:8' */
        rtb_R_onoff = 1U;

        /* '<S27>:1:9' */
        rtb_z_out[0] = (*vdy_aye_U_VDYInputData).Signals.LatAccel -
          (*vdy_aye_U_VDYInternalData_in).vdy_offsets_in.vdy_ay_offset.offset;
        rtb_z_out[1] = (*vdy_aye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate;
      } else {
        /* '<S27>:1:11' */
        rtb_R_onoff = 2U;

        /* '<S27>:1:12' */
        rtb_z_out[0] = (*vdy_aye_U_VDYInputData).Signals.LatAccel;
        rtb_z_out[1] = (*vdy_aye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate;
      }
    } else {
      /* '<S27>:1:15' */
      rtb_R_onoff = 0U;

      /* '<S27>:1:16' */
      for (i = 0; i < 2; i++) {
        rtb_z_out[i] = 0.0F;
      }
    }
  } else {
    /* '<S27>:1:19' */
    rtb_R_onoff = 0U;

    /* '<S27>:1:20' */
    for (i = 0; i < 2; i++) {
      rtb_z_out[i] = 0.0F;
    }
  }

  /* Embedded MATLAB: '<S6>/adapt_R_matrix' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  for (i = 0; i < 4; i++) {
    rtb_R_out[i] = vdy_aye_R_p[(i)];
  }

  /* Embedded MATLAB Function 'R/adapt_R_matrix': '<S25>:1' */
  /*  if the lateral acceleration signal is valid */
  if (rtb_R_onoff >= 1) {
    /* '<S25>:1:3' */
    /* '<S25>:1:4' */
    rtb_R_out[3] = (*vdy_aye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate_var;

    /* '<S25>:1:5' */
  } else {
    /* '<S25>:1:7' */
    rtb_R_out[0] = vdy_aye_R_ay_invalid_p;

    /* '<S25>:1:8' */
    rtb_R_out[3] = (*vdy_aye_U_VDYInternalData_in).vdy_gye_out.gier_yaw_rate_var;

    /* '<S25>:1:9' */
  }

  /* SignalConversion: '<S1>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_At[0] = 1.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[1] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector ConcatenateIn3' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[2] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector ConcatenateIn4' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[3] = 0.0F;

  /* Outputs for atomic SubSystem: '<Root>/Time2Sec' */

  /* Product: '<S7>/Time2Sec' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_Time2Sec = ((real32_T)(*vdy_aye_U_VDYInputData).Frame.CycleTime) / 1000.0F;

  /* end of Outputs for SubSystem: '<Root>/Time2Sec' */

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate1In1' */
  rtb_At[4] = rtb_Time2Sec;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_At[5] = 1.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[6] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate1In4' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[7] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate2In1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[8] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[9] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_At[10] = 1.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate2In4' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[11] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate3In1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[12] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate3In2' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[13] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate3In3' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  rtb_At[14] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate3In4' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_At[15] = 1.0F;

  /* Embedded MATLAB: '<S3>/check_track_bent_range' */
  /* Embedded MATLAB Function 'EKF/check_track_bent_range': '<S16>:1' */
  /*  check if the track bent is in valid range */
  /* '<S16>:1:3' */
  for (i = 0; i < 4; i++) {
    /* UnitDelay: '<S3>/x_delay' */
    rtb_xpost[i] = vdy_aye_DWork->x_delay_DSTATE[(i)];
    rtb_x_out[i] = vdy_aye_DWork->x_delay_DSTATE[(i)];
  }

  /*  if  */
  if (vdy_aye_DWork->x_delay_DSTATE[2] < -0.5F) {
    /* '<S16>:1:6' */
    /* '<S16>:1:7' */
    rtb_x_out[2] = -0.5F;
  }

  /*  if  */
  if (vdy_aye_DWork->x_delay_DSTATE[2] > 0.5F) {
    /* '<S16>:1:11' */
    /* '<S16>:1:12' */
    rtb_x_out[2] = 0.5F;
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_At,
    (real32_T*)rtb_x_out, rtb_x_pred, (uint8_T)4, (uint8_T)4, (uint8_T)1);

  /* Embedded MATLAB: '<S17>/x(3)' */
  /* Embedded MATLAB Function 'EKF/hx/x(3)': '<S24>:1' */
  /* '<S24>:1:2' */
  rtb_y_b = rtb_x_pred[2];

  /* Embedded MATLAB: '<S17>/hx' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_cos32): '<S17>/cos'
   *  S-Function (ex_sfun_sin32): '<S17>/sin'
   */
  /* Embedded MATLAB Function 'EKF/hx/hx': '<S23>:1' */
  /*  non linear transformation function from state space to measurement space */
  /* '<S23>:1:3' */
  rtb_hx[0] = (((*vdy_aye_U_VDYInternalData_in).vdy_ve_out.veh_velo *
                rtb_x_pred[1]) - (GDB_sin32( (real32_T)rtb_y_b) * 9.81F)) -
    rtb_x_pred[3];
  rtb_hx[1] = rtb_x_pred[1];

  /*  linearized by the Jacobi matrix */
  /* '<S23>:1:7' */
  rtb_H[0] = 0.0F;
  rtb_H[2] = (*vdy_aye_U_VDYInternalData_in).vdy_ve_out.veh_velo;
  rtb_H[4] = (-GDB_cos32( (real32_T)rtb_y_b)) * 9.81F;
  rtb_H[6] = 1.0F;
  for (i = 0; i < 4; i++) {
    rtb_H[1 + (i << 1)] = (real32_T)tmp_0[i];
  }

  /* Product: '<S5>/Product2' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/sigma_model'
   *  Product: '<S5>/Divide'
   *  Product: '<S5>/Product1'
   */
  rtb_Knu[0] = ((rtb_Time2Sec * rtb_Time2Sec) * 0.5F) * vdy_aye_Q_sigmas_p[0];
  rtb_Knu[1] = rtb_Time2Sec * vdy_aye_Q_sigmas_p[1];
  rtb_Knu[2] = 0.0F;
  rtb_Knu[3] = 0.0F;

  /* S-Function (MatrixMultiplication): '<S5>/vdy_s-func_Q' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_Knu,
    (real32_T*)rtb_Knu, rtb_vdy_sfunc_AP_At_o2, (uint8_T)1, (uint8_T)4, (uint8_T)
    4);

  /* BusSelector: '<Root>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_gier_yaw_rate_g = (*vdy_aye_U_VDYInternalData_in).
    vdy_gye_out.gier_yaw_rate;

  /* Sum: '<S29>/Sum' incorporates:
   *  Gain: '<S29>/Gain'
   *  Sum: '<S29>/Diff'
   *  UnitDelay: '<S11>/delay'
   *  UnitDelay: '<S29>/UD'
   */
  rtb_Sum = ((vdy_aye_DWork->UD_DSTATE - vdy_aye_DWork->delay_DSTATE) * 0.7F) +
    vdy_aye_DWork->delay_DSTATE;

  /* Embedded MATLAB: '<S11>/q_gain_delta' incorporates:
   *  BusSelector: '<Root>/Bus Selector1'
   *  Constant: '<S11>/Constant3'
   *  Inport: '<Root>/VDYInternalData_in'
   *  S-Function (ex_sfun_abs): '<S11>/tp_filter_est_yaw_rate_abs'
   *  S-Function (ex_sfun_abs): '<S11>/yaw_rate_in_abs'
   */
  /* Embedded MATLAB Function 'q_gain/q_gain_delta': '<S28>:1' */
  /*  Note: In order to eliminate QAC Level-4 warnings, the if-condition below is rewritten with multiple if-elseif expressions. */
  /*  calculate the difference between the mean filtered last yaw rate and  */
  /*  the actual yaw rate */
  if (CML_f_Abs( (real32_T)rtb_gier_yaw_rate_g) >= 1.0E-7F) {
    /* '<S28>:1:6' */
    if (CML_f_Abs( (real32_T)rtb_Sum) >= 1.0E-7F) {
      /* '<S28>:1:7' */
      /* '<S28>:1:8' */
      rtb_diff = rtb_gier_yaw_rate_g - rtb_Sum;
    } else {
      /* '<S28>:1:10' */
      rtb_diff = 0.2F;
    }
  } else {
    /* '<S28>:1:13' */
    rtb_diff = 0.2F;
  }

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<Root>/vdy_aye_Q_gain'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  MultiPortSwitch: '<S11>/bias_value'
   *  MultiPortSwitch: '<S11>/gain_factor'
   *  Product: '<S11>/Product1'
   *  S-Function (ex_sfun_abs): '<S11>/diff_abs'
   */
  rtb_Time2Sec = (CML_f_Abs( (real32_T)rtb_diff) * vdy_aye_Q_gain_p[0]) +
    vdy_aye_Q_gain_p[1];
  for (i = 0; i < 16; i++) {
    /* Sum: '<S5>/Sum' incorporates:
     *  Constant: '<S5>/additional'
     *  Product: '<S5>/Product'
     */
    rtb_Sum_m[i] = (rtb_vdy_sfunc_AP_At_o2[i] * rtb_Time2Sec) + vdy_aye_Q_add_p
      [(i)];

    /* UnitDelay: '<S3>/P_delay' */
    rtb_vdy_sfunc_AP_At_o2[i] = vdy_aye_DWork->P_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S18>/vdy_s-func_AP' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_At,
    (real32_T*)rtb_vdy_sfunc_AP_At_o2, rtb_KH, (uint8_T)4, (uint8_T)4, (uint8_T)
    4);

  /* Math: '<S3>/At' */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      tmp[i_0 + (i << 2)] = rtb_At[(i_0 << 2) + i];
    }
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_At[i_0 + (i << 2)] = tmp[(i << 2) + i_0];
    }
  }

  /* S-Function (MatrixMultiplication): '<S18>/vdy_s-func_AP_At' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_At, rtb_vdy_sfunc_AP_At_o2, (uint8_T)4, (uint8_T)4, (uint8_T)
    4);

  /* Sum: '<S3>/APA_Q' */
  for (i = 0; i < 16; i++) {
    rtb_P_pred[i] = rtb_Sum_m[i] + rtb_vdy_sfunc_AP_At_o2[i];
  }

  /* S-Function (MatrixMultiplication): '<S19>/vdy_s-func_HP' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_H, (real32_T*)
    rtb_P_pred, rtb_vdy_sfunc_HP_o2, (uint8_T)4, (uint8_T)2, (uint8_T)4);

  /* Math: '<S3>/Ht' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_Ht[i_0 + (i << 2)] = rtb_H[(i_0 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S19>/vdy_s-func_HP_Ht' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_HP_o2, (real32_T*)rtb_Ht, rtb_vdy_sfunc_HP_Ht_o2, (uint8_T)4,
    (uint8_T)2, (uint8_T)2);

  /* Sum: '<S3>/HPH_R' */
  for (i = 0; i < 4; i++) {
    rtb_HPHt_R[i] = rtb_R_out[i] + rtb_vdy_sfunc_HP_Ht_o2[i];
  }

  /* Embedded MATLAB: '<S13>/Matrix_Inversion_2x2' */
  vdy_matrix_inversion_2x2(rtb_HPHt_R, &vdy_aye_B->sf_Matrix_Inversion_2x2);

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_Ht, rtb_P_predHt, (uint8_T)4, (uint8_T)4, (uint8_T)2);

  /* If: '<S13>/If' incorporates:
   *  ActionPort: '<S21>/Action Port'
   *  ActionPort: '<S22>/Action Port'
   *  SubSystem: '<S13>/calculate the gain'
   *  SubSystem: '<S13>/set gain to default value'
   */
  if (!vdy_aye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* S-Function (MatrixMultiplication): '<S21>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_predHt,
      (real32_T*)vdy_aye_B->sf_Matrix_Inversion_2x2.HPHt_R_inv, rtb_K, (uint8_T)
      2, (uint8_T)4, (uint8_T)2);
  } else {
    /* Constant: '<S22>/Constant' */
    for (i = 0; i < 8; i++) {
      rtb_K[i] = vdy_aye_K_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_KH' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)
    rtb_H, rtb_KH, (uint8_T)2, (uint8_T)4, (uint8_T)4);

  /* Sum: '<S3>/1_KH' incorporates:
   *  Constant: '<S3>/eye'
   */
  for (i = 0; i < 16; i++) {
    rtb_KH[i] = vdy_aye_I_matrix_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S3>/Reset_P_pred' */
  /* Embedded MATLAB Function 'EKF/Reset_P_pred': '<S14>:1' */
  if (vdy_aye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S14>:1:4' */
    /* '<S14>:1:5' */
    for (i = 0; i < 16; i++) {
      rtb_P_pred_out[i] = vdy_aye_P_init_p[(i)];
    }
  } else {
    /* '<S14>:1:7' */
    vdy_memcpy_s((void *)(&rtb_P_pred_out[0]), (void *)(&rtb_P_pred[0]), sizeof
                 (real32_T) << 4U);
  }

  /* S-Function (MatrixMultiplication): '<S3>/S-Function3' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out, rtb_P_post, (uint8_T)4, (uint8_T)4, (uint8_T)4);

  /* Embedded MATLAB: '<Root>/correct_variance' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'correct_variance': '<S8>:1' */
  /*  the output variance for this module is raised at low speed */
  /*  if the input values are not valid set a high constant */
  /*  if the velocity is in a low speed range eg. between 1 and 10 m/s */
  /*  the variance is linear increasing to the bottom limit with the velocity */
  /*  below this bottom limit the variance is constant */
  /*  if the velocity if above the upper limit nothing is done */
  if (rtb_R_onoff >= 1) {
    /* '<S8>:1:8' */
    if (((*vdy_aye_U_VDYInternalData_in).vdy_ve_out.veh_velo <
         vdy_aye_P_correct_p[1]) && ((*vdy_aye_U_VDYInternalData_in).
         vdy_ve_out.veh_velo > vdy_aye_P_correct_p[0])) {
      /* '<S8>:1:9' */
      /* '<S8>:1:10' */
      rtb_Time2Sec = ((*vdy_aye_U_VDYInternalData_in).vdy_ve_out.veh_velo -
                      vdy_aye_P_correct_p[0]) * vdy_aye_P_correct_p[2];
      for (i = 0; i < 4; i++) {
        rtb_R_out[i] = rtb_P_post[5 * i] + (vdy_aye_P_correct_p[3] -
          rtb_Time2Sec);
      }
    } else if ((*vdy_aye_U_VDYInternalData_in).vdy_ve_out.veh_velo <=
               vdy_aye_P_correct_p[0]) {
      /* '<S8>:1:11' */
      /* '<S8>:1:12' */
      for (i = 0; i < 4; i++) {
        rtb_R_out[i] = rtb_P_post[5 * i] + vdy_aye_P_correct_p[3];
      }
    } else {
      /*  if the ay offset is not valid */
      if (rtb_R_onoff == 2) {
        /* '<S8>:1:15' */
        /* '<S8>:1:16' */
        for (i = 0; i < 4; i++) {
          rtb_R_out[i] = rtb_P_post[5 * i] * 1.2F;
        }
      } else {
        /* '<S8>:1:18' */
        for (i = 0; i < 4; i++) {
          rtb_R_out[i] = rtb_P_post[5 * i];
        }
      }
    }
  } else {
    /* '<S8>:1:22' */
    for (i = 0; i < 4; i++) {
      rtb_R_out[i] = vdy_aye_P_correct_p[3];
    }
  }

  /* BusAssignment: '<Root>/Bus Assignment1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_ay_yaw_rate = (*vdy_aye_U_VDYInternalData_in);
  rtb_ay_yaw_rate.vdy_aye_out.ay_yaw_rate_var = rtb_R_out[1];

  /* BusAssignment: '<Root>/Bus Assignment3' */
  rtb_ay_yaw_rate.vdy_aye_out.track_bent_var = rtb_R_out[2];

  /* Embedded MATLAB: '<S3>/Reset_x_pred' */
  /* Embedded MATLAB Function 'EKF/Reset_x_pred': '<S15>:1' */
  if (vdy_aye_B->sf_Matrix_Inversion_2x2.det_flag) {
    /* '<S15>:1:4' */
    /* '<S15>:1:6' */
    rtb_R_out[0] = 0.0F;
    rtb_R_out[1] = rtb_xpost[1];
    rtb_R_out[2] = rtb_xpost[2];
    rtb_R_out[3] = 0.0F;
  } else {
    /* '<S15>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_R_out[i] = rtb_x_pred[i];
    }
  }

  /* Sum: '<S3>/z_Hx' */
  for (i = 0; i < 2; i++) {
    rtb_nu[i] = rtb_z_out[i] - rtb_hx[i];
  }

  /* S-Function (MatrixMultiplication): '<S3>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)
    rtb_nu, rtb_Knu, (uint8_T)2, (uint8_T)4, (uint8_T)1);

  /* Sum: '<S3>/x_Knu' */
  for (i = 0; i < 4; i++) {
    rtb_x_post[i] = rtb_R_out[i] + rtb_Knu[i];
  }

  /* Embedded MATLAB: '<Root>/correct_yaw_rate' */
  /* Embedded MATLAB Function 'correct_yaw_rate': '<S9>:1' */
  /*  the output yaw rate is set to 0 */
  /*  if the input values are not valid */
  if (rtb_R_onoff >= 1) {
    /* '<S9>:1:4' */
    /* '<S9>:1:5' */
    rtb_Time2Sec = rtb_x_post[1];
  } else {
    /* '<S9>:1:7' */
    rtb_Time2Sec = 0.0F;
  }

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_ay_yaw_rate.vdy_aye_out.ay_yaw_rate = rtb_Time2Sec;
  rtb_ay_yaw_rate.vdy_aye_out.r_On_Off_control = rtb_R_onoff;

  /* Outputs for atomic SubSystem: '<Root>/BankRoadDetection' */

  /* UnitDelay: '<S2>/BankRoadDelay' */
  rtb_R_onoff = vdy_aye_DWork->BankRoadDelay_DSTATE;

  /* UnitDelay: '<S2>/BankRoadDelay1' */
  rtb_BankRoadDelay1 = vdy_aye_DWork->BankRoadDelay1_DSTATE;

  /* Embedded MATLAB: '<S2>/EnableBRD' incorporates:
   *  S-Function (ex_sfun_abs): '<S2>/Bent_abs'
   */
  /* Embedded MATLAB Function 'BankRoadDetection/EnableBRD': '<S12>:1' */
  /* % If Bent > |0.035|(2 degree) for 20 vdy cycles. */
  if (CML_f_Abs( (real32_T)rtb_x_post[2]) >= 0.035F) {
    /* '<S12>:1:5' */
    /* '<S12>:1:6' */
    i = (int32_T)(((uint32_T)rtb_R_onoff) + 1U);
    if (((uint32_T)i) > 255U) {
      i = 255;
    }

    vdy_aye_DWork->BankRoadDelay_DSTATE = (uint8_T)i;
  } else {
    /* '<S12>:1:8' */
    vdy_aye_DWork->BankRoadDelay_DSTATE = rtb_R_onoff;
  }

  if (vdy_aye_DWork->BankRoadDelay_DSTATE == rtb_R_onoff) {
    /* '<S12>:1:11' */
    /* '<S12>:1:12' */
    i = (int32_T)(((uint32_T)rtb_BankRoadDelay1) + 1U);
    if (((uint32_T)i) > 255U) {
      i = 255;
    }

    vdy_aye_DWork->BankRoadDelay1_DSTATE = (uint8_T)i;
    if (vdy_aye_DWork->BankRoadDelay1_DSTATE > 5) {
      /* '<S12>:1:13' */
      /* '<S12>:1:14' */
      vdy_aye_DWork->BankRoadDelay1_DSTATE = 0U;

      /* '<S12>:1:15' */
      vdy_aye_DWork->BankRoadDelay_DSTATE = 0U;
    }
  } else {
    /* '<S12>:1:18' */
    vdy_aye_DWork->BankRoadDelay1_DSTATE = 0U;
  }

  if (vdy_aye_DWork->BankRoadDelay_DSTATE >= 20) {
    /* '<S12>:1:21' */
    /* '<S12>:1:22' */
    vdy_aye_DWork->BankRoadDelay_DSTATE = 20U;

    /* '<S12>:1:23' */
    rtb_R_onoff = 1U;
  } else {
    /* '<S12>:1:25' */
    rtb_R_onoff = 0U;
  }

  /* end of Outputs for SubSystem: '<Root>/BankRoadDetection' */

  /* BusAssignment: '<Root>/ay_yaw_rate' */
  rtb_ay_yaw_rate.vdy_aye_out.track_bent = rtb_x_post[2];
  rtb_ay_yaw_rate.vdy_aye_out.BankRoad = rtb_R_onoff;

  /* Outport: '<Root>/vdy_aye_out' */
  (*vdy_aye_Y_vdy_aye_out) = rtb_ay_yaw_rate;

  /* Update for UnitDelay: '<S3>/x_delay' */
  for (i = 0; i < 4; i++) {
    vdy_aye_DWork->x_delay_DSTATE[(i)] = rtb_x_post[i];
  }

  /* Update for UnitDelay: '<S29>/UD' */
  vdy_aye_DWork->UD_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S11>/delay' */
  vdy_aye_DWork->delay_DSTATE = rtb_x_post[1];

  /* Update for UnitDelay: '<S3>/P_delay' */
  vdy_memcpy_s((void *)(&vdy_aye_DWork->P_delay_DSTATE[0]), (void *)
               (&rtb_P_post[0]), sizeof(real32_T) << 4U);
}

/* Model initialize function */
void vdy_aye_initialize(boolean_T firstTime, BlockIO_vdy_aye *vdy_aye_B,
  D_Work_vdy_aye *vdy_aye_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_aye_B), 0,
                      sizeof(BlockIO_vdy_aye));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_aye_DWork, 0,
                      sizeof(D_Work_vdy_aye));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S3>/x_delay' */
    for (i = 0; i < 4; i++) {
      vdy_aye_DWork->x_delay_DSTATE[(i)] = vdy_aye_x_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S3>/P_delay' */
    for (i = 0; i < 16; i++) {
      vdy_aye_DWork->P_delay_DSTATE[(i)] = vdy_aye_P_init_p[(i)];
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
