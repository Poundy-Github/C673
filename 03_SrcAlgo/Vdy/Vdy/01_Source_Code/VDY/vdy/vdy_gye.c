/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_gye.c
   Real-Time Workshop code generated for Simulink model vdy_gye.
   Model version                        : 1.2404
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:02:45 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:02:46 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy gier yaw rate estimation,
   estimates the offset compensated
   gier yaw rate
   VERSION:                             : $Revision: 1.5 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_gye.h"
#include "vdy_gye_private.h"

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
 *    '<S10>/Get_IO_State1'
 *    '<S10>/Get_IO_State2'
 */
void vdy_gye_Get_IO_State1(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State1_vdy_gye *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S33>/Index Vector' incorporates:
   *  Constant: '<S33>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/* Model step function */
void vdy_gye_step(BlockIO_vdy_gye *vdy_gye_B, D_Work_vdy_gye *vdy_gye_DWork,
                  VDYInputData_t *vdy_gye_U_VDYInputData, VDYInternalData_t
                  *vdy_gye_U_VDYInternalData_in, VDYInternalData_t
                  *vdy_gye_Y_VDYInternalData_out)
{
  /* local block i/o variables */
  real32_T rtb_Add1;
  real32_T rtb_add_abs;
  real32_T rtb_P_pred[4];
  real32_T rtb_HPHt_R;
  real32_T rtb_vdy_sfunc_P_pred_Ht_o2[2];
  real32_T rtb_K[2];
  real32_T rtb_P_post[4];
  real32_T rtb_xpost[2];
  real32_T rtb_x_pred[2];
  real32_T rtb_P_pred_out[4];
  real32_T rtb_MatrixConcatenate[4];
  real32_T rtb_vdy_sfunc_AP_o2[4];
  real32_T rtb_vdy_sfunc_H_P_pred_o2[2];
  real32_T rtb_WeightedMovingAverage_abs;
  real32_T rtb_At[4];
  real32_T rtb_Knu[2];
  real32_T rtb_KH[4];
  real32_T rtb_nu;
  uint8_T rtb_State[32];
  uint8_T rtb_vdy_sfunc_K_gain_o1;
  uint8_T rtb_vdy_sfunc_K_nu_o1;
  boolean_T rtb_R_onoff;
  real32_T rtb_delay;
  real32_T rtb_Time2Sec;
  uint8_T rtb_Reset;
  real32_T rtb_gain;
  uint8_T rtb_Value_in_uint;
  real32_T rtb_Merge;
  VDYInternalData_t rtb_BusAssignment;
  real32_T rtb_y[2];
  real32_T rtb_off_comp_yaw_rate;
  real32_T rtb_init_value;
  real32_T rtb_Sum;
  real32_T rtb_Sum_j;
  int32_T i;
  real32_T rtb_Time2Sec_0[4];
  int32_T i_0;

  /* BusSelector: '<S10>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 32; i++) {
    rtb_State[i] = (*vdy_gye_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<S10>/Get_IO_State1' */
  vdy_gye_Get_IO_State1(rtb_State, &vdy_gye_B->Get_IO_State1, ((uint32_T)
    VDY_SIN_POS_YWR));

  /* end of Outputs for SubSystem: '<S10>/Get_IO_State1' */

  /* Outputs for atomic SubSystem: '<S10>/Get_IO_State2' */
  vdy_gye_Get_IO_State1(rtb_State, &vdy_gye_B->Get_IO_State2, ((uint32_T)
    VDY_SIN_POS_YWRINT));

  /* end of Outputs for SubSystem: '<S10>/Get_IO_State2' */

  /* Sum: '<S10>/Sum' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_off_comp_yaw_rate = (*vdy_gye_U_VDYInputData).Signals.YawRate -
    (*vdy_gye_U_VDYInternalData_in).vdy_wye_out.gier_yaw_rate_offset;

  /* Embedded MATLAB: '<S10>/R_yaw_valid' incorporates:
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  Sum: '<S10>/Sum1'
   */
  /* Embedded MATLAB Function 'make_z_vektor/R_yaw_valid': '<S35>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /*  check the internal yaw rate processing switch */
  if (((uint32_T)CFG_VDY_INT_GYRO) == 0U) {
    /* '<S35>:1:6' */
    if (((((uint32_T)vdy_gye_B->Get_IO_State1.IndexVector) == ((uint32_T)
           VDY_IO_STATE_VALID)) || (((uint32_T)
           vdy_gye_B->Get_IO_State1.IndexVector) == ((uint32_T)
           VDY_IO_STATE_DECREASED))) || (((uint32_T)
          vdy_gye_B->Get_IO_State1.IndexVector) == ((uint32_T)
          VDY_IO_STATE_SUBSTITUE))) {
      /* '<S35>:1:7' */
      /*  use the external yaw rate signal */
      /* '<S35>:1:9' */
      rtb_R_onoff = TRUE;

      /* '<S35>:1:10' */
    } else {
      /* '<S35>:1:12' */
      rtb_R_onoff = FALSE;

      /* '<S35>:1:13' */
      rtb_off_comp_yaw_rate = 0.0F;
    }
  } else {
    /*  if internal yaw rate sensor processing is switched on, */
    /*  but the external yaw rate is valid use the external yaw rate signal. */
    if (((uint32_T)vdy_gye_B->Get_IO_State1.IndexVector) == ((uint32_T)
         VDY_IO_STATE_VALID)) {
      /* '<S35>:1:18' */
      /*  use the external yaw rate signal */
      /* '<S35>:1:20' */
      rtb_R_onoff = TRUE;

      /* '<S35>:1:21' */
    } else if (((uint32_T)vdy_gye_B->Get_IO_State2.IndexVector) == ((uint32_T)
                VDY_IO_STATE_VALID)) {
      /* '<S35>:1:23' */
      /*  use the internal yaw rate signal */
      /* '<S35>:1:25' */
      rtb_R_onoff = TRUE;

      /* '<S35>:1:26' */
      rtb_off_comp_yaw_rate = (*vdy_gye_U_VDYInputData).Signals.YawRateInt -
        (*vdy_gye_U_VDYInternalData_in).vdy_wye_out.gier_yaw_rate_offset;
    } else {
      /* '<S35>:1:28' */
      rtb_R_onoff = FALSE;

      /* '<S35>:1:29' */
      rtb_off_comp_yaw_rate = 0.0F;
    }
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  rtb_vdy_sfunc_K_nu_o1 = rtb_R_onoff;

  /* If: '<S5>/If' incorporates:
   *  ActionPort: '<S21>/Action Port'
   *  ActionPort: '<S22>/Action Port'
   *  SubSystem: '<S5>/If Action false'
   *  SubSystem: '<S5>/If Action true'
   */
  if (rtb_vdy_sfunc_K_nu_o1 > 0) {
    /* Embedded MATLAB: '<S22>/calc_resolution_var' */
    /* Embedded MATLAB Function 'R/If Action true/calc_resolution_var': '<S23>:1' */
    /*  the input R variance */
    /* '<S23>:1:3' */
    rtb_Merge = vdy_gye_R_p[0];
  } else {
    /* MultiPortSwitch: '<S21>/second_element' incorporates:
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/vdy_gye_P_correct_p'
     */
    rtb_Merge = vdy_gye_R_p[1];
  }

  /* Outputs for atomic SubSystem: '<Root>/Time2Sec' */

  /* Product: '<S6>/Time2Sec' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_Time2Sec = ((real32_T)(*vdy_gye_U_VDYInputData).Frame.CycleTime) / 1000.0F;

  /* end of Outputs for SubSystem: '<Root>/Time2Sec' */

  /* Embedded MATLAB: '<S19>/make_Q_matrix' */
  /* Embedded MATLAB Function 'Q/make_Q/make_Q_matrix': '<S20>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S20>:1:5' */
  /* '<S20>:1:6' */

  /* UnitDelay: '<S7>/delay' */
  rtb_delay = vdy_gye_DWork->delay_DSTATE;

  /* Product: '<S7>/Divide' incorporates:
   *  Sum: '<S24>/Diff'
   *  UnitDelay: '<S24>/UD'
   */
  vdy_gye_B->Divide = (rtb_off_comp_yaw_rate - vdy_gye_DWork->UD_DSTATE) /
    rtb_Time2Sec;

  /* Weighted Moving Average Block: '<S7>/Weighted Moving Average'
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
    rtb_WeightedMovingAverage_abs = vdy_gye_B->Divide * 0.125F;

    {
      int_T i1;
      real32_T *dw_TapDelayU = &vdy_gye_DWork->WeightedMovingAverage_TapDelayU[1];
      for (i1=0; i1 < 7; i1++) {
        yTemp1 = dw_TapDelayU[((i1)-1)] *
          vdy_gye_ConstP.WeightedMovingAverage[i1+1];
        rtb_WeightedMovingAverage_abs = rtb_WeightedMovingAverage_abs + yTemp1;
      }
    }
  }

  /* Sum: '<S7>/Add1' */
  rtb_Add1 = rtb_delay - rtb_WeightedMovingAverage_abs;

  /* S-Function (ex_sfun_abs): '<S7>/add_abs' */
  rtb_add_abs = CML_f_Abs( (real32_T)rtb_Add1);

  /* Embedded MATLAB: '<S28>/check_reset_condition' incorporates:
   *  UnitDelay: '<S28>/Unit Delay'
   */
  /* Embedded MATLAB Function 'calculate_Q_gain/tp_filter_peaks/check_reset_condition': '<S30>:1' */
  if (rtb_add_abs > vdy_gye_DWork->UnitDelay_DSTATE) {
    /* '<S30>:1:3' */
    /* '<S30>:1:4' */
    rtb_Reset = 1U;

    /* '<S30>:1:5' */
    rtb_init_value = rtb_add_abs;
  } else {
    /* '<S30>:1:7' */
    rtb_Reset = 0U;

    /* '<S30>:1:8' */
    rtb_init_value = 0.0F;
  }

  /* Switch: '<S32>/Init' incorporates:
   *  Logic: '<S32>/FixPt Logical Operator'
   *  UnitDelay: '<S32>/FixPt Unit Delay1'
   *  UnitDelay: '<S32>/FixPt Unit Delay2'
   */
  if ((rtb_Reset != 0) || (vdy_gye_DWork->FixPtUnitDelay2_DSTATE != 0)) {
    rtb_nu = rtb_init_value;
  } else {
    rtb_nu = vdy_gye_DWork->FixPtUnitDelay1_DSTATE;
  }

  /* Sum: '<S31>/Sum' incorporates:
   *  Gain: '<S31>/Gain'
   *  Sum: '<S31>/Diff'
   */
  rtb_Sum = ((rtb_nu - rtb_add_abs) * 0.95F) + rtb_add_abs;

  /* UnitDelay: '<S25>/UD' */
  rtb_delay = vdy_gye_DWork->UD_DSTATE_h;

  /* S-Function (ex_sfun_abs): '<S7>/Weighted Moving Average_abs' */
  rtb_WeightedMovingAverage_abs = CML_f_Abs( (real32_T)
    rtb_WeightedMovingAverage_abs);

  /* Sum: '<S25>/Sum' incorporates:
   *  Gain: '<S25>/Gain'
   *  Sum: '<S25>/Diff'
   */
  rtb_Sum_j = ((rtb_delay - rtb_WeightedMovingAverage_abs) * 0.95F) +
    rtb_WeightedMovingAverage_abs;

  /* Embedded MATLAB: '<S7>/threshold_gain' */
  /* Embedded MATLAB Function 'calculate_Q_gain/threshold_gain': '<S27>:1' */
  if (rtb_Sum > 0.05F) {
    /* '<S27>:1:3' */
    if (rtb_Sum_j > 0.03F) {
      /* '<S27>:1:4' */
      /* '<S27>:1:5' */
      rtb_gain = rtb_Sum * vdy_gye_Q_gain_p;
    } else if (rtb_Sum_j > 0.02F) {
      /* '<S27>:1:6' */
      /* '<S27>:1:7' */
      rtb_gain = (rtb_Sum * vdy_gye_Q_gain_p) * 0.5F;
    } else if (rtb_Sum_j > 0.01F) {
      /* '<S27>:1:8' */
      /* '<S27>:1:9' */
      rtb_gain = (rtb_Sum * vdy_gye_Q_gain_p) * 0.1F;
    } else {
      /* '<S27>:1:11' */
      rtb_gain = 1.0F;
    }
  } else {
    /* '<S27>:1:14' */
    rtb_gain = 1.0F;

    /* 0.000125 */
  }

  /* DataTypeConversion: '<S26>/Value_in_uint' */
  rtb_Value_in_uint = (uint8_T)rtb_gain;

  /* Embedded MATLAB: '<S26>/hold_last_5_values' incorporates:
   *  DataTypeConversion: '<S26>/Last_value_uint'
   *  UnitDelay: '<S26>/hold_counter'
   *  UnitDelay: '<S26>/hold_value'
   */
  /* Embedded MATLAB Function 'calculate_Q_gain/hold_last_5_values/hold_last_5_values': '<S29>:1' */
  /*  Hold value 5 cycle if input value is one */
  /*  Added Value_in_uint and Last_value_uint to remove QAC Level 4 warnings */
  if ((((rtb_Value_in_uint == 1) && (((uint8_T)vdy_gye_DWork->hold_value_DSTATE)
         != 1)) && (vdy_gye_DWork->hold_counter_DSTATE == 0)) ||
      ((vdy_gye_DWork->hold_counter_DSTATE > 0) &&
       (vdy_gye_DWork->hold_counter_DSTATE <= 5))) {
    /* '<S29>:1:5' */
    if ((vdy_gye_DWork->hold_counter_DSTATE >= 1) && (rtb_Value_in_uint != 1)) {
      /* '<S29>:1:6' */
      /* '<S29>:1:7' */
      /* '<S29>:1:8' */
      rtb_Value_in_uint = 0U;
    } else {
      /* '<S29>:1:10' */
      rtb_gain = vdy_gye_DWork->hold_value_DSTATE;

      /* '<S29>:1:11' */
      rtb_Value_in_uint = (uint8_T)(vdy_gye_DWork->hold_counter_DSTATE + 1);
    }
  } else {
    /* '<S29>:1:14' */
    /* '<S29>:1:15' */
    rtb_Value_in_uint = 0U;
  }

  /* Constant: '<S1>/Constant' */
  rtb_MatrixConcatenate[0] = 1.0F;

  /* Constant: '<S1>/Constant1' */
  rtb_MatrixConcatenate[1] = 0.0F;

  /* SignalConversion: '<S1>/ConcatBufferAtVector Concatenate1In1' */
  rtb_MatrixConcatenate[2] = rtb_Time2Sec;

  /* Constant: '<S1>/Constant2' */
  rtb_MatrixConcatenate[3] = 1.0F;

  /* UnitDelay: '<S2>/P_delay' */
  for (i = 0; i < 4; i++) {
    rtb_At[i] = vdy_gye_DWork->P_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_AP' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_MatrixConcatenate, (real32_T*)rtb_At, rtb_vdy_sfunc_AP_o2, (uint8_T)2,
    (uint8_T)2, (uint8_T)2);

  /* Math: '<S2>/At' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_At[i_0 + (i << 1)] = rtb_MatrixConcatenate[(i_0 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_AP_At' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_AP_o2, (real32_T*)rtb_At, rtb_KH, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Sum: '<S2>/APA_Q' incorporates:
   *  Product: '<S4>/Product'
   */
  rtb_Time2Sec_0[0] = ((rtb_Time2Sec * rtb_Time2Sec) * rtb_Time2Sec) / 3.0F;
  rtb_Time2Sec_0[2] = (rtb_Time2Sec * rtb_Time2Sec) / 2.0F;
  rtb_Time2Sec_0[1] = (rtb_Time2Sec * rtb_Time2Sec) / 2.0F;
  rtb_Time2Sec_0[3] = rtb_Time2Sec;
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_P_pred[i_0 + (i << 1)] = ((rtb_Time2Sec_0[(i << 1) + i_0] * 0.0025F) *
        rtb_gain) + rtb_KH[(i << 1) + i_0];
    }
  }

  /* S-Function (MatrixMultiplication): '<S15>/vdy_s-func_H_P_pred' incorporates:
   *  Constant: '<S2>/H_const'
   */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)(&(vdy_gye_H_p[0])),
    (real32_T*)rtb_P_pred, rtb_vdy_sfunc_H_P_pred_o2, (uint8_T)2, (uint8_T)1,
    (uint8_T)2);

  /* Math: '<S2>/Ht' incorporates:
   *  Constant: '<S2>/H_const'
   */
  for (i = 0; i < 2; i++) {
    rtb_Knu[i] = vdy_gye_H_p[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S15>/vdy_s-func_HP_Ht' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_H_P_pred_o2, (real32_T*)rtb_Knu, &rtb_nu, (uint8_T)2, (uint8_T)
    1, (uint8_T)1);

  /* Sum: '<S2>/HPH_R' */
  rtb_HPHt_R = rtb_Merge + rtb_nu;

  /* Embedded MATLAB: '<S11>/Matrix_Inversion_1x1' */
  vdy_matrix_inversion_1x1(rtb_HPHt_R, &vdy_gye_B->sf_Matrix_Inversion_1x1);

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_Knu, rtb_vdy_sfunc_P_pred_Ht_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)1);

  /* If: '<S11>/If' incorporates:
   *  ActionPort: '<S17>/Action Port'
   *  ActionPort: '<S18>/Action Port'
   *  SubSystem: '<S11>/calculate the gain'
   *  SubSystem: '<S11>/set gain to default value'
   */
  if (!vdy_gye_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* S-Function (MatrixMultiplication): '<S17>/vdy_s-func_K_gain' */
    rtb_vdy_sfunc_K_gain_o1 = vdy_matrix_multiplication( (real32_T*)
      rtb_vdy_sfunc_P_pred_Ht_o2, (real32_T*)
      &vdy_gye_B->sf_Matrix_Inversion_1x1.HPHt_R_inv, rtb_K, (uint8_T)1,
      (uint8_T)2, (uint8_T)1);
  } else {
    /* Constant: '<S18>/Constant' */
    for (i = 0; i < 2; i++) {
      rtb_K[i] = vdy_gye_K_default_p[(i)];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_KH' incorporates:
   *  Constant: '<S2>/H_const'
   */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)
    (&(vdy_gye_H_p[0])), rtb_KH, (uint8_T)1, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S2>/1_KH' incorporates:
   *  Constant: '<S2>/H_const1'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH[i] = vdy_gye_I_matrix_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S2>/Reset_P_pred' */
  /* Embedded MATLAB Function 'KF/Reset_P_pred': '<S12>:1' */
  if (vdy_gye_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* '<S12>:1:4' */
    /* '<S12>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = vdy_gye_P_init_p[(i)];
    }
  } else {
    /* '<S12>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out, rtb_P_post, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<Root>/diag_uncertainty' */
  /* Embedded MATLAB Function 'diag_uncertainty': '<S9>:1' */
  /*  correct the ouput variance if the input values are not valid */
  if (((int32_T)rtb_R_onoff) == 1) {
    /* '<S9>:1:3' */
    /* '<S9>:1:4' */
    for (i = 0; i < 2; i++) {
      rtb_y[i] = rtb_P_post[3 * i] + vdy_gye_P_correct_p[1];
    }
  } else {
    /* '<S9>:1:6' */
    for (i = 0; i < 2; i++) {
      rtb_y[i] = vdy_gye_P_correct_p[0];
    }
  }

  /* BusAssignment: '<Root>/gier_yaw_rate' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_BusAssignment = (*vdy_gye_U_VDYInternalData_in);
  rtb_BusAssignment.vdy_gye_out.gier_yaw_rate_var = rtb_y[0];

  /* UnitDelay: '<S2>/x_delay' */
  for (i = 0; i < 2; i++) {
    rtb_xpost[i] = vdy_gye_DWork->x_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_MatrixConcatenate, (real32_T*)rtb_xpost, rtb_x_pred, (uint8_T)2,
    (uint8_T)2, (uint8_T)1);

  /* Embedded MATLAB: '<S2>/Reset_x_pred' */
  /* Embedded MATLAB Function 'KF/Reset_x_pred': '<S13>:1' */
  if (vdy_gye_B->sf_Matrix_Inversion_1x1.det_flag) {
    /* '<S13>:1:4' */
    /* '<S13>:1:6' */
    rtb_y[0] = rtb_xpost[0];
    rtb_y[1] = 0.0F;
  } else {
    /* '<S13>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_y[i] = rtb_x_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_Hx' incorporates:
   *  Constant: '<S2>/H_const'
   */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)(&(vdy_gye_H_p[0])),
    (real32_T*)rtb_x_pred, &rtb_nu, (uint8_T)2, (uint8_T)1, (uint8_T)1);

  /* Sum: '<S2>/z_Hx' */
  rtb_nu = rtb_off_comp_yaw_rate - rtb_nu;

  /* S-Function (MatrixMultiplication): '<S2>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_K_nu_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K, (real32_T*)
    &rtb_nu, rtb_Knu, (uint8_T)1, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S2>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_y[i] = rtb_y[i] + rtb_Knu[i];
  }

  /* Embedded MATLAB: '<Root>/correct_output' */
  /* Embedded MATLAB Function 'correct_output': '<S8>:1' */
  /*  correct the ouput if the input values are not valid */
  if (((int32_T)rtb_R_onoff) == 1) {
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    rtb_delay = rtb_y[0];
  } else {
    /* '<S8>:1:6' */
    rtb_delay = 0.0F;
  }

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.vdy_gye_out.gier_yaw_rate = rtb_delay;
  rtb_BusAssignment.vdy_gye_out.r_On_Off_control = rtb_R_onoff;

  /* Outport: '<Root>/VDYInternalData_out' */
  (*vdy_gye_Y_VDYInternalData_out) = rtb_BusAssignment;

  /* Switch: '<S32>/Reset' */
  if (rtb_Reset == 0) {
    rtb_init_value = rtb_Sum;
  }

  /* Update for UnitDelay: '<S7>/delay' */
  vdy_gye_DWork->delay_DSTATE = rtb_y[1];

  /* Update for UnitDelay: '<S24>/UD' */
  vdy_gye_DWork->UD_DSTATE = rtb_off_comp_yaw_rate;

  /* Weighted Moving Average Block: '<S7>/Weighted Moving Average'
   */
  {
    int32_T iObj;

    /*
     * shift all the discrete states on time delay
     *  being careful not to overwrite a value before it
     *  has been moved.
     */
    for (iObj = (6); iObj > 0; iObj-- ) {
      vdy_gye_DWork->WeightedMovingAverage_TapDelayU[iObj] =
        vdy_gye_DWork->WeightedMovingAverage_TapDelayU[iObj-1];
    }

    /*
     * the top state is the current input
     */
    vdy_gye_DWork->WeightedMovingAverage_TapDelayU[0] = vdy_gye_B->Divide;
  }

  /* Update for UnitDelay: '<S28>/Unit Delay' */
  vdy_gye_DWork->UnitDelay_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S32>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S32>/FixPt Constant'
   */
  vdy_gye_DWork->FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S32>/FixPt Unit Delay1' */
  vdy_gye_DWork->FixPtUnitDelay1_DSTATE = rtb_init_value;

  /* Update for UnitDelay: '<S25>/UD' */
  vdy_gye_DWork->UD_DSTATE_h = rtb_Sum_j;

  /* Update for UnitDelay: '<S26>/hold_value' */
  vdy_gye_DWork->hold_value_DSTATE = rtb_gain;

  /* Update for UnitDelay: '<S26>/hold_counter' */
  vdy_gye_DWork->hold_counter_DSTATE = rtb_Value_in_uint;

  /* Update for UnitDelay: '<S2>/P_delay' */
  for (i = 0; i < 4; i++) {
    vdy_gye_DWork->P_delay_DSTATE[(i)] = rtb_P_post[i];
  }

  /* Update for UnitDelay: '<S2>/x_delay' */
  for (i = 0; i < 2; i++) {
    vdy_gye_DWork->x_delay_DSTATE[(i)] = rtb_y[i];
  }
}

/* Model initialize function */
void vdy_gye_initialize(boolean_T firstTime, BlockIO_vdy_gye *vdy_gye_B,
  D_Work_vdy_gye *vdy_gye_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_gye_B), 0,
                      sizeof(BlockIO_vdy_gye));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_gye_DWork, 0,
                      sizeof(D_Work_vdy_gye));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S32>/FixPt Unit Delay2' */
    vdy_gye_DWork->FixPtUnitDelay2_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S26>/hold_value' */
    vdy_gye_DWork->hold_value_DSTATE = 1.0F;

    /* InitializeConditions for UnitDelay: '<S2>/P_delay' */
    for (i = 0; i < 4; i++) {
      vdy_gye_DWork->P_delay_DSTATE[(i)] = vdy_gye_P_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S2>/x_delay' */
    for (i = 0; i < 2; i++) {
      vdy_gye_DWork->x_delay_DSTATE[(i)] = vdy_gye_x_init_p[(i)];
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
