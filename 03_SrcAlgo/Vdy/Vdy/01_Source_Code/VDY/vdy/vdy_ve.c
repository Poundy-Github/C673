/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_ve.c
   Real-Time Workshop code generated for Simulink model vdy_ve.
   Model version                        : 1.1259
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:00:55 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:00:56 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy velocity and acceleration
   estimation, merge the four wheel speeds
   VERSION:                             : $Revision: 1.7 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_ve.h"
#include "vdy_ve_private.h"

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
 *    '<S28>/Get_IO_State_ABS'
 *    '<S27>/Get_IO_State_TCS'
 *    '<S47>/Get_IO_State_ABS'
 */
void vdy_ve_Get_IO_State_ABS(const uint8_T rtu_state_in[2],
  rtB_Get_IO_State_ABS_vdy_ve *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S31>/Index Vector' incorporates:
   *  Constant: '<S31>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/*
 * Output and update for atomic system:
 *    '<S28>/Get_IO_State_WVEL_FL'
 *    '<S28>/Get_IO_State_WVEL_FR'
 *    '<S28>/Get_IO_State_WVEL_RL'
 *    '<S28>/Get_IO_State_WVEL_RR'
 *    '<Root>/Get_IO_State_ExtAccel'
 *    '<S7>/Get_IO_State_VEHACL_EXT'
 *    '<S13>/Get_IO_State_WTCKS_FL'
 *    '<S13>/Get_IO_State_WTCKS_FR'
 *    '<S13>/Get_IO_State_WTCKS_RL'
 *    '<S13>/Get_IO_State_WTCKS_RR'
 */
void vdy_ve_Get_IO_State_WVEL_FL(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State_WVEL_FL_vdy_ve *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S32>/Index Vector' incorporates:
   *  Constant: '<S32>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/*
 * Output and update for atomic system:
 *    '<S39>/whl_vel_std_dev_function'
 *    '<S40>/whl_accel_function'
 */
void vdy_ve_whl_vel_std_dev_function(real32_T rtu_x, real32_T rtu_flagv,
  rtB_whl_vel_std_dev_function_vd *localB)
{
  /* Embedded MATLAB: '<S39>/whl_vel_std_dev_function' */
  /* Embedded MATLAB Function 'Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel_std_dev/whl_vel_std_dev_function': '<S44>:1' */
  if (rtu_x >= 1.0F) {
    /* '<S44>:1:4' */
    localB->flag_vel = rtu_flagv + 1.0F;
  } else {
    /* '<S44>:1:5' */
    localB->flag_vel = rtu_flagv - 0.5F;
  }

  if (localB->flag_vel < 0.0F) {
    /* '<S44>:1:7' */
    localB->flag_vel = 0.0F;
  }

  if (localB->flag_vel >= 100.0F) {
    /* '<S44>:1:8' */
    localB->flag_vel = 100.0F;
  }
}

/*
 * Output and update for atomic system:
 *    '<S73>/FL_R_step_increment_ve_model'
 *    '<S73>/FR_R_step_increment_ve_model'
 *    '<S73>/RL_R_step_increment_ve_model'
 *    '<S73>/RR_R_step_increment_ve_model'
 *    '<S112>/FL_z_step_increment_ve_model'
 *    '<S112>/FR_z_step_increment_ve_model'
 *    '<S112>/RL_z_step_increment_ve_model'
 *    '<S112>/RR_z_step_increment_ve_model'
 */
void step_increment_ve_model(real32_T rtu_Previous_whl_velovar, boolean_T
  rtu_TCS_ABS_flag_check, real32_T rtu_Present_whl_velvar, uint8_T
  rtu_Step_veloVar_in, uint8_T rtu_Init_delay_in, rtB_step_increment_ve_model
  *localB, rtDW_step_increment_ve_model *localDW)
{
  /* Switch: '<S80>/Switch' */
  if (rtu_TCS_ABS_flag_check) {
    localDW->FL_latched_velvar_DSTATE = rtu_Previous_whl_velovar;
  } else {
    /* Switch: '<S85>/Switch' incorporates:
     *  UnitDelay: '<S85>/FL_latched_vel//var'
     */
    if (rtu_Init_delay_in != 0) {
      localDW->FL_latched_velvar_DSTATE = rtu_Present_whl_velvar;
    }
  }

  /* Sum: '<S80>/sum' incorporates:
   *  Constant: '<S80>/Constant'
   *  Product: '<S80>/Divide'
   *  Product: '<S80>/Divide1'
   *  Sum: '<S80>/Sum'
   */
  localB->sum = (((rtu_Present_whl_velvar - localDW->FL_latched_velvar_DSTATE) /
                  20.0F) * ((real32_T)rtu_Step_veloVar_in)) +
    localDW->FL_latched_velvar_DSTATE;
}

/*
 * Initial conditions for atomic system:
 *    '<S15>/check_variance_R_matrix_FL'
 *    '<S15>/check_variance_R_matrix_FR'
 *    '<S15>/check_variance_R_matrix_RL'
 *    '<S15>/check_variance_R_matrix_RR'
 */
void check_variance_R_matrix_Init(rtDW_check_variance_R_matrix *localDW)
{
  /* InitializeConditions for UnitDelay: '<S93>/FL_init_reset' */
  localDW->FL_init_reset_DSTATE = 1U;
}

/*
 * Output and update for atomic system:
 *    '<S15>/check_variance_R_matrix_FL'
 *    '<S15>/check_variance_R_matrix_FR'
 *    '<S15>/check_variance_R_matrix_RL'
 *    '<S15>/check_variance_R_matrix_RR'
 */
void check_variance_R_matrix(real32_T rtu_var_in, real32_T *rty_var_out,
  rtDW_check_variance_R_matrix *localDW)
{
  uint8_T rtb_Reset;
  real32_T rtb_init_value;

  /* Embedded MATLAB: '<S90>/check_reset_condition_fl' incorporates:
   *  UnitDelay: '<S75>/FL_ext_reset'
   *  UnitDelay: '<S90>/FL_filt_var'
   */
  /* Embedded MATLAB Function 'check_variance_R_matrix/tp_filter_peaks_fl/check_reset_condition_fl': '<S91>:1' */
  if ((rtu_var_in > localDW->FL_filt_var_DSTATE) ||
      (localDW->FL_ext_reset_DSTATE == 1)) {
    /* '<S91>:1:3' */
    /* '<S91>:1:4' */
    rtb_Reset = 1U;

    /* '<S91>:1:5' */
    rtb_init_value = rtu_var_in;
  } else {
    /* '<S91>:1:7' */
    rtb_Reset = 0U;

    /* '<S91>:1:8' */
    rtb_init_value = 0.0F;
  }

  /* Switch: '<S93>/Init' incorporates:
   *  Logic: '<S93>/FixPt Logical Operator'
   *  UnitDelay: '<S93>/FL_init_reset'
   */
  if ((rtb_Reset != 0) || (localDW->FL_init_reset_DSTATE != 0)) {
    localDW->FL_init_value_DSTATE = rtb_init_value;
  }

  /* Sum: '<S92>/Sum' incorporates:
   *  Gain: '<S92>/Gain'
   *  Sum: '<S92>/Diff'
   */
  localDW->FL_filt_var_DSTATE = ((localDW->FL_init_value_DSTATE - rtu_var_in) *
    0.8F) + rtu_var_in;

  /* Embedded MATLAB: '<S75>/check_threshold_fl' incorporates:
   *  Update for UnitDelay: '<S75>/FL_ext_reset'
   */
  /* Embedded MATLAB Function 'check_variance_R_matrix/check_threshold_fl': '<S89>:1' */
  /*  If raw variance is below secified Value use the filtered var  */
  if (rtu_var_in <= 250.0F) {
    /* '<S89>:1:3' */
    /* '<S89>:1:4' */
    (*rty_var_out) = localDW->FL_filt_var_DSTATE;

    /* '<S89>:1:5' */
    localDW->FL_ext_reset_DSTATE = 0U;
  } else {
    /* '<S89>:1:7' */
    (*rty_var_out) = rtu_var_in;

    /* '<S89>:1:8' */
    localDW->FL_ext_reset_DSTATE = 1U;
  }

  /* Switch: '<S93>/Reset' incorporates:
   *  Update for UnitDelay: '<S93>/FL_init_value'
   */
  if (rtb_Reset != 0) {
    localDW->FL_init_value_DSTATE = rtb_init_value;
  } else {
    localDW->FL_init_value_DSTATE = localDW->FL_filt_var_DSTATE;
  }

  /* Update for UnitDelay: '<S93>/FL_init_reset' incorporates:
   *  Constant: '<S93>/FixPt Constant'
   */
  localDW->FL_init_reset_DSTATE = 0U;
}

/* Model step function */
void vdy_ve_step(BlockIO_vdy_ve *vdy_ve_B, D_Work_vdy_ve *vdy_ve_DWork,
                 VDYInputData_t *vdy_ve_U_VDYInputData, VDYInternalData_t
                 *vdy_ve_U_VDYInternalData_in, Brake_t *vdy_ve_U_brake_input,
                 VDYInternalData_t *vdy_ve_Y_VDYInternalData_out)
{
  /* local block i/o variables */
  real32_T rtb_x_pred[2];
  real32_T rtb_VehLongAccelExt_h;
  real32_T rtb_Add_c;
  real32_T rtb_P_pred[4];
  real32_T rtb_vdy_sfunc_P_pred_H_Ht_o2[16];
  real32_T rtb_create_var_vector[4];
  real32_T rtb_FL_var_delay;
  real32_T rtb_FR_var_delay;
  real32_T rtb_RL_var_delay;
  real32_T rtb_RR_var_delay;
  real32_T rtb_P_predHt[8];
  real32_T rtb_K[8];
  real32_T rtb_create_vector[4];
  real32_T rtb_FL_vel_delay;
  real32_T rtb_FR_vel_delay;
  real32_T rtb_RL_vel_delay;
  real32_T rtb_RR_vel_delay;
  real32_T rtb_P_post[4];
  real32_T rtb_Add_j;
  real32_T rtb_y[16];
  real32_T rtb_Whl_vel_var_FL_out;
  real32_T rtb_Whl_vel_var_FR_out;
  real32_T rtb_Whl_vel_var_RL_out;
  real32_T rtb_Whl_vel_var_RR_out;
  real32_T rtb_H[8];
  real32_T rtb_P_pred_out[4];
  real32_T rtb_DataTypeConversion1;
  real32_T rtb_Accel_Counter;
  real32_T rtb_DataTypeConversion;
  real32_T rtb_SD_Counter;
  real32_T rtb_Sum_b;
  real32_T rtb_Sum1;
  real32_T rtb_A[4];
  real32_T rtb_vdy_sfunc_A_P_post_o2[4];
  real32_T rtb_vdy_sfunc_P_pred_H_o2[8];
  real32_T rtb_Ht[8];
  real32_T rtb_nu[4];
  real32_T rtb_At[4];
  real32_T rtb_vdy_sfunc_K_nu_o2[2];
  real32_T rtb_KH[4];
  uint8_T rtb_State[32];
  uint8_T rtb_State_h[32];
  uint8_T rtb_State_n[32];
  uint8_T rtb_TCS_Var_Flag_Init;
  uint8_T rtb_Switch1;
  uint8_T rtb_TCS_Vel_Flag_Init;
  uint8_T rtb_Switch1_o;
  uint8_T rtb_State_p[2];
  uint8_T rtb_State_f[2];
  uint8_T rtb_State_j[2];
  uint8_T rtb_State_i[32];
  uint8_T rtb_vdy_sfunc_K_o1;
  uint8_T rtb_vdy_sfunc_P_post_o1;
  boolean_T rtb_TCS_transient_flag;
  boolean_T rtb_TCS_transient_flag_d;
  VDYInternalData_t rtb_VdyAccel;
  uint8_T rtb_TCS;
  real32_T rtb_Sum;
  real32_T rtb_Product[2];
  uint8_T rtb_DataTypeConversion_a;
  int32_T rtb_whl_index;
  real32_T rtb_hx[4];
  real32_T rtb_v_out;
  real32_T rtb_DeadZone_FL;
  real32_T rtb_DeadZone_FR;
  real32_T rtb_EWMA_Right;
  real32_T rtb_EWVAR_Right;
  boolean_T rtb_ORLogicalOperator;
  uint8_T rtb_DataTypeConversion_e;
  boolean_T rtb_u;
  boolean_T rtb_ABS_input;
  boolean_T rtb_ABS_state_valid_f;
  boolean_T rtb_WVEL_FL_valid;
  boolean_T rtb_WVEL_FR_valid;
  boolean_T rtb_WVEL_RL_valid;
  real32_T rtb_EWMA_Sum_i;
  uint8_T rtb_DataTypeConversion1_b;
  real32_T rtb_Add;
  real32_T rtb_TmpSignalConversionAtSFun_o[2];
  real32_T rtb_R_out[4];
  int32_T i;
  real32_T rtb_TmpSignalConversionAtSFun_0[2];
  real32_T rtb_Product_0[2];
  int32_T i_0;

  /* If: '<S3>/If' incorporates:
   *  ActionPort: '<S26>/Action Port'
   *  ActionPort: '<S27>/Action Port'
   *  Constant: '<S3>/Constant'
   *  SubSystem: '<S3>/Else_condition'
   *  SubSystem: '<S3>/If_TCS_detected'
   */
  if (((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) {
    /* DeadZone: '<S40>/Dead Zone_FL' incorporates:
     *  BusSelector: '<S40>/Bus Selector5'
     *  Inport: '<Root>/VDYInternalData_in'
     */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_front_left >=
        0.5F) {
      rtb_DeadZone_FL = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_front_left - 0.5F;
    } else if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_front_left
               > -0.5F) {
      rtb_DeadZone_FL = 0.0F;
    } else {
      rtb_DeadZone_FL = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_front_left - -0.5F;
    }

    /* DeadZone: '<S40>/Dead Zone_FR' incorporates:
     *  BusSelector: '<S40>/Bus Selector5'
     *  Inport: '<Root>/VDYInternalData_in'
     */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_front_right >=
        0.5F) {
      rtb_DeadZone_FR = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_front_right - 0.5F;
    } else if ((*vdy_ve_U_VDYInternalData_in).
               vdy_wpp_out.wheel_accel_front_right > -0.5F) {
      rtb_DeadZone_FR = 0.0F;
    } else {
      rtb_DeadZone_FR = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_front_right - -0.5F;
    }

    /* DeadZone: '<S40>/Dead Zone_RL' incorporates:
     *  BusSelector: '<S40>/Bus Selector5'
     *  Inport: '<Root>/VDYInternalData_in'
     */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_rear_left >= 0.5F)
    {
      rtb_EWMA_Right = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_rear_left - 0.5F;
    } else if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_rear_left >
               -0.5F) {
      rtb_EWMA_Right = 0.0F;
    } else {
      rtb_EWMA_Right = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_rear_left - -0.5F;
    }

    /* DeadZone: '<S40>/Dead Zone_RR' incorporates:
     *  BusSelector: '<S40>/Bus Selector5'
     *  Inport: '<Root>/VDYInternalData_in'
     */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_rear_right >=
        0.5F) {
      rtb_EWVAR_Right = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_rear_right - 0.5F;
    } else if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_accel_rear_right
               > -0.5F) {
      rtb_EWVAR_Right = 0.0F;
    } else {
      rtb_EWVAR_Right = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_accel_rear_right - -0.5F;
    }

    /* Logic: '<S40>/OR Logical Operator' incorporates:
     *  Constant: '<S40>/Constant'
     *  RelationalOperator: '<S40>/Relational Operator'
     *  RelationalOperator: '<S40>/Relational Operator1'
     *  RelationalOperator: '<S40>/Relational Operator2'
     *  RelationalOperator: '<S40>/Relational Operator3'
     */
    rtb_ORLogicalOperator = ((((rtb_DeadZone_FL > 0.01F) || (rtb_DeadZone_FR >
      0.01F)) || (rtb_EWMA_Right > 0.01F)) || (rtb_EWVAR_Right > 0.01F));

    /* BusSelector: '<S27>/Bus Selector4' incorporates:
     *  Inport: '<Root>/brake_input'
     */
    for (i = 0; i < 2; i++) {
      rtb_State_f[i] = (*vdy_ve_U_brake_input).State[(i)];
    }

    /* Outputs for atomic SubSystem: '<S27>/Get_IO_State_TCS' */
    vdy_ve_Get_IO_State_ABS(rtb_State_f, &vdy_ve_B->Get_IO_State_TCS, ((uint32_T)
      VEH_SIG_BRAKE_TSC));

    /* end of Outputs for SubSystem: '<S27>/Get_IO_State_TCS' */

    /* Switch: '<S27>/Ext_TCS' incorporates:
     *  Constant: '<S27>/Constant'
     *  Inport: '<Root>/brake_input'
     */
    if (vdy_ve_B->Get_IO_State_TCS.IndexVector != 0) {
      rtb_DataTypeConversion_e = 0U;
    } else {
      rtb_DataTypeConversion_e = (*vdy_ve_U_brake_input).TCSCtrl;
    }

    /* Logic: '<S27>/                      ' */
    rtb_u = ((rtb_ORLogicalOperator) && (rtb_DataTypeConversion_e != 0));

    /* BusSelector: '<S28>/Bus Selector1' incorporates:
     *  Inport: '<Root>/brake_input'
     */
    for (i = 0; i < 2; i++) {
      rtb_State_j[i] = (*vdy_ve_U_brake_input).State[(i)];
    }

    /* RelationalOperator: '<S28>/ABS_input' incorporates:
     *  Constant: '<S28>/Constant'
     *  Inport: '<Root>/brake_input'
     */
    rtb_ABS_input = ((*vdy_ve_U_brake_input).ABSCtrl == 0);

    /* Outputs for atomic SubSystem: '<S28>/Get_IO_State_ABS' */
    vdy_ve_Get_IO_State_ABS(rtb_State_j, &vdy_ve_B->Get_IO_State_ABS, ((uint32_T)
      VEH_SIG_BRAKE_ABS));

    /* end of Outputs for SubSystem: '<S28>/Get_IO_State_ABS' */

    /* RelationalOperator: '<S28>/ABS_state_valid' incorporates:
     *  Constant: '<S28>/Constant'
     */
    rtb_ABS_state_valid_f = (vdy_ve_B->Get_IO_State_ABS.IndexVector == 0);

    /* BusSelector: '<S28>/Bus Selector3' incorporates:
     *  Inport: '<Root>/VDYInputData'
     */
    for (i = 0; i < 32; i++) {
      rtb_State_i[i] = (*vdy_ve_U_VDYInputData).Signals.State[(i)];
    }

    /* Outputs for atomic SubSystem: '<S28>/Get_IO_State_WVEL_FL' */
    vdy_ve_Get_IO_State_WVEL_FL(rtb_State_i, &vdy_ve_B->Get_IO_State_WVEL_FL,
      ((uint32_T)VDY_SIN_POS_WVEL_FL));

    /* end of Outputs for SubSystem: '<S28>/Get_IO_State_WVEL_FL' */

    /* RelationalOperator: '<S28>/WVEL_FL_valid' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    rtb_WVEL_FL_valid = (vdy_ve_B->Get_IO_State_WVEL_FL.IndexVector == 0);

    /* Outputs for atomic SubSystem: '<S28>/Get_IO_State_WVEL_FR' */
    vdy_ve_Get_IO_State_WVEL_FL(rtb_State_i, &vdy_ve_B->Get_IO_State_WVEL_FR,
      ((uint32_T)VDY_SIN_POS_WVEL_FR));

    /* end of Outputs for SubSystem: '<S28>/Get_IO_State_WVEL_FR' */

    /* RelationalOperator: '<S28>/WVEL_FR_valid' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    rtb_WVEL_FR_valid = (vdy_ve_B->Get_IO_State_WVEL_FR.IndexVector == 0);

    /* Outputs for atomic SubSystem: '<S28>/Get_IO_State_WVEL_RL' */
    vdy_ve_Get_IO_State_WVEL_FL(rtb_State_i, &vdy_ve_B->Get_IO_State_WVEL_RL,
      ((uint32_T)VDY_SIN_POS_WVEL_RL));

    /* end of Outputs for SubSystem: '<S28>/Get_IO_State_WVEL_RL' */

    /* RelationalOperator: '<S28>/WVEL_RL_valid' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    rtb_WVEL_RL_valid = (vdy_ve_B->Get_IO_State_WVEL_RL.IndexVector == 0);

    /* Outputs for atomic SubSystem: '<S28>/Get_IO_State_WVEL_RR' */
    vdy_ve_Get_IO_State_WVEL_FL(rtb_State_i, &vdy_ve_B->Get_IO_State_WVEL_RR,
      ((uint32_T)VDY_SIN_POS_WVEL_RR));

    /* end of Outputs for SubSystem: '<S28>/Get_IO_State_WVEL_RR' */

    /* Logic: '<S28>/AND Logical Operator' incorporates:
     *  Constant: '<S28>/Constant1'
     *  RelationalOperator: '<S28>/WVEL_RR_valid'
     */
    rtb_WVEL_FL_valid = ((((rtb_WVEL_FL_valid) && (rtb_WVEL_FR_valid)) &&
                          (rtb_WVEL_RL_valid)) &&
                         (vdy_ve_B->Get_IO_State_WVEL_RR.IndexVector == 0));

    /* DataTypeConversion: '<S40>/Data Type Conversion1' */
    rtb_DataTypeConversion1 = (real32_T)rtb_ORLogicalOperator;

    /* UnitDelay: '<S40>/Accel_Counter' */
    rtb_Accel_Counter = vdy_ve_DWork->Accel_Counter_DSTATE;

    /* Embedded MATLAB: '<S40>/whl_accel_function' */
    vdy_ve_whl_vel_std_dev_function(rtb_DataTypeConversion1, rtb_Accel_Counter,
      &vdy_ve_B->sf_whl_accel_function);

    /* DataTypeConversion: '<S40>/Data Type Conversion' */
    rtb_DataTypeConversion_e = (uint8_T)vdy_ve_B->sf_whl_accel_function.flag_vel;

    /* Sum: '<S39>/Sum' incorporates:
     *  Inport: '<Root>/VDYInternalData_in'
     */
    rtb_EWVAR_Right = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_left - (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_left;

    /* Sum: '<S42>/EWMA_Sum' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant1'
     *  Product: '<S42>/Product'
     *  Product: '<S42>/Product1'
     *  UnitDelay: '<S42>/EWMA_Left'
     */
    rtb_DeadZone_FR = (rtb_EWVAR_Right * 0.2F) + (0.8F *
      vdy_ve_DWork->EWMA_Left_DSTATE);

    /* Sum: '<S42>/Sum1' */
    rtb_EWVAR_Right -= rtb_DeadZone_FR;

    /* Sum: '<S42>/stnd_dev_left_wheels' incorporates:
     *  Constant: '<S42>/Constant2'
     *  Constant: '<S42>/Constant3'
     *  Product: '<S42>/Product2'
     *  Product: '<S42>/Product3'
     *  UnitDelay: '<S42>/EWVAR_Left'
     */
    rtb_EWMA_Right = ((rtb_EWVAR_Right * rtb_EWVAR_Right) * 0.2F) + (0.8F *
      vdy_ve_DWork->EWVAR_Left_DSTATE);

    /* Sum: '<S39>/Sum1' incorporates:
     *  Inport: '<Root>/VDYInternalData_in'
     */
    rtb_EWVAR_Right = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_right - (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_right;

    /* Sum: '<S43>/EWMA_Sum' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     *  Product: '<S43>/Product'
     *  Product: '<S43>/Product1'
     *  UnitDelay: '<S43>/EWMA_Right'
     */
    rtb_EWMA_Sum_i = (rtb_EWVAR_Right * 0.2F) + (0.8F *
      vdy_ve_DWork->EWMA_Right_DSTATE);

    /* Sum: '<S43>/Sum1' */
    rtb_EWVAR_Right -= rtb_EWMA_Sum_i;

    /* Sum: '<S43>/stnd_dev_right_wheels' incorporates:
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Product: '<S43>/Product2'
     *  Product: '<S43>/Product3'
     *  UnitDelay: '<S43>/EWVAR_Right'
     */
    rtb_DeadZone_FL = ((rtb_EWVAR_Right * rtb_EWVAR_Right) * 0.2F) + (0.8F *
      vdy_ve_DWork->EWVAR_Right_DSTATE);

    /* DataTypeConversion: '<S39>/Data Type Conversion' incorporates:
     *  Constant: '<S39>/Constant'
     *  Logic: '<S39>/OR Logical Operator'
     *  RelationalOperator: '<S39>/Relational Operator'
     *  RelationalOperator: '<S39>/Relational Operator1'
     */
    rtb_DataTypeConversion = (real32_T)((rtb_EWMA_Right > 0.1F) ||
      (rtb_DeadZone_FL > 0.1F));

    /* UnitDelay: '<S39>/SD_Counter' */
    rtb_SD_Counter = vdy_ve_DWork->SD_Counter_DSTATE;

    /* Embedded MATLAB: '<S39>/whl_vel_std_dev_function' */
    vdy_ve_whl_vel_std_dev_function(rtb_DataTypeConversion, rtb_SD_Counter,
      &vdy_ve_B->sf_whl_vel_std_dev_function);

    /* DataTypeConversion: '<S39>/Data Type Conversion1' */
    rtb_DataTypeConversion1_b = (uint8_T)
      vdy_ve_B->sf_whl_vel_std_dev_function.flag_vel;

    /* Sum: '<S38>/Sum' incorporates:
     *  Inport: '<Root>/VDYInputData'
     */
    rtb_Sum_b = (*vdy_ve_U_VDYInputData).Signals.WhlVelFrLeft -
      (*vdy_ve_U_VDYInputData).Signals.WhlVelReLeft;

    /* Sum: '<S38>/Sum1' incorporates:
     *  Inport: '<Root>/VDYInputData'
     */
    rtb_Sum1 = (*vdy_ve_U_VDYInputData).Signals.WhlVelFrRight -
      (*vdy_ve_U_VDYInputData).Signals.WhlVelReRight;

    /* Embedded MATLAB: '<S38>/whl_vel_diff_function' incorporates:
     *  BusSelector: '<S29>/Bus Selector2'
     *  Constant: '<S38>/Constant'
     *  Inport: '<Root>/VDYInputData'
     *  Product: '<S38>/whl_vel_diff'
     *  S-Function (ex_sfun_abs): '<S38>/abs_left_diff'
     *  S-Function (ex_sfun_abs): '<S38>/abs_right_diff'
     *  Sum: '<S38>/Sum'
     *  Sum: '<S38>/Sum1'
     *  Sum: '<S38>/Sum2'
     *  UnitDelay: '<S38>/Vel_Counter'
     */
    /* Embedded MATLAB Function 'Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel/whl_vel_diff_function': '<S41>:1' */
    if (((CML_f_Abs( (real32_T)rtb_Sum_b) + CML_f_Abs( (real32_T)rtb_Sum1)) /
         2.0F) >= 1.0F) {
      /* '<S41>:1:4' */
      vdy_ve_DWork->Vel_Counter_DSTATE = vdy_ve_DWork->Vel_Counter_DSTATE + 1.0F;
    } else {
      /* '<S41>:1:5' */
      vdy_ve_DWork->Vel_Counter_DSTATE = vdy_ve_DWork->Vel_Counter_DSTATE - 0.5F;
    }

    if (vdy_ve_DWork->Vel_Counter_DSTATE < 0.0F) {
      /* '<S41>:1:7' */
      vdy_ve_DWork->Vel_Counter_DSTATE = 0.0F;
    }

    if (vdy_ve_DWork->Vel_Counter_DSTATE >= 100.0F) {
      /* '<S41>:1:8' */
      vdy_ve_DWork->Vel_Counter_DSTATE = 100.0F;
    }

    /* If: '<S29>/If' incorporates:
     *  ActionPort: '<S36>/Action Port'
     *  ActionPort: '<S37>/Action Port'
     *  DataTypeConversion: '<S38>/Data Type Conversion'
     *  SubSystem: '<S29>/Else_condition'
     *  SubSystem: '<S29>/If_TCS_detected'
     */
    if (((rtb_DataTypeConversion_e >= 5) && (rtb_DataTypeConversion1_b >= 5)) &&
        (((uint8_T)vdy_ve_DWork->Vel_Counter_DSTATE) >= 5)) {
      /* Constant: '<S37>/Constant' */
      rtb_DataTypeConversion_e = 1U;
    } else {
      /* Constant: '<S36>/Constant' */
      rtb_DataTypeConversion_e = 0U;
    }

    /* Switch: '<S27>/Switch_validity_check' incorporates:
     *  Constant: '<S27>/Constant1'
     *  DataTypeConversion: '<S27>/Data Type Conversion'
     *  Logic: '<S27>/Traction_Detection'
     *  Logic: '<S28>/AND Logical Operator1'
     *  Logic: '<S28>/AND Logical Operator2'
     */
    if (((rtb_ABS_input) && (rtb_ABS_state_valid_f)) && (rtb_WVEL_FL_valid)) {
      rtb_TCS = ((rtb_DataTypeConversion_e != 0) || (rtb_u));
    } else {
      rtb_TCS = 0U;
    }

    /* Update for UnitDelay: '<S40>/Accel_Counter' */
    vdy_ve_DWork->Accel_Counter_DSTATE =
      vdy_ve_B->sf_whl_accel_function.flag_vel;

    /* Update for UnitDelay: '<S42>/EWMA_Left' */
    vdy_ve_DWork->EWMA_Left_DSTATE = rtb_DeadZone_FR;

    /* Update for UnitDelay: '<S42>/EWVAR_Left' */
    vdy_ve_DWork->EWVAR_Left_DSTATE = rtb_EWMA_Right;

    /* Update for UnitDelay: '<S43>/EWMA_Right' */
    vdy_ve_DWork->EWMA_Right_DSTATE = rtb_EWMA_Sum_i;

    /* Update for UnitDelay: '<S43>/EWVAR_Right' */
    vdy_ve_DWork->EWVAR_Right_DSTATE = rtb_DeadZone_FL;

    /* Update for UnitDelay: '<S39>/SD_Counter' */
    vdy_ve_DWork->SD_Counter_DSTATE =
      vdy_ve_B->sf_whl_vel_std_dev_function.flag_vel;
  } else {
    /* Constant: '<S26>/Constant' */
    rtb_TCS = 0U;
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_VdyAccel = (*vdy_ve_U_VDYInternalData_in);
  rtb_VdyAccel.vdy_ve_out.traction = rtb_TCS;

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S8>/CycleCnt'
   *  UnitDelay: '<S8>/Rate_Limit_Counter'
   */
  rtb_Add = vdy_ve_DWork->Rate_Limit_Counter_DSTATE + 1.0F;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   */
  if (rtb_Add >= 5.0F) {
    rtb_EWVAR_Right = 15.0F;
  } else {
    rtb_EWVAR_Right = 100000.0F;
  }

  /* Product: '<S52>/delta rise limit' */
  rtb_EWVAR_Right *= 0.02F;

  /* If: '<S4>/If' incorporates:
   *  ActionPort: '<S46>/Action Port'
   *  ActionPort: '<S47>/Action Port'
   *  Constant: '<S4>/Constant1'
   *  SubSystem: '<S4>/Else_condition'
   *  SubSystem: '<S4>/If_ABS_detected'
   */
  if (((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) {
    /* BusSelector: '<S47>/Bus Selector4' incorporates:
     *  Inport: '<Root>/brake_input'
     */
    for (i = 0; i < 2; i++) {
      rtb_State_p[i] = (*vdy_ve_U_brake_input).State[(i)];
    }

    /* Outputs for atomic SubSystem: '<S47>/Get_IO_State_ABS' */
    vdy_ve_Get_IO_State_ABS(rtb_State_p, &vdy_ve_B->Get_IO_State_ABS_p,
      ((uint32_T)VEH_SIG_BRAKE_ABS));

    /* end of Outputs for SubSystem: '<S47>/Get_IO_State_ABS' */

    /* Switch: '<S47>/Switch_check_ABS' incorporates:
     *  Constant: '<S47>/Constant'
     *  Inport: '<Root>/brake_input'
     */
    if (vdy_ve_B->Get_IO_State_ABS_p.IndexVector != 0) {
      rtb_DataTypeConversion_e = 0U;
    } else {
      rtb_DataTypeConversion_e = (*vdy_ve_U_brake_input).ABSCtrl;
    }
  } else {
    /* Constant: '<S46>/Constant' */
    rtb_DataTypeConversion_e = 0U;
  }

  /* Embedded MATLAB: '<S16>/Compute_min_or_max_wheel_speed' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_z_vektor/Compute_min_or_max_wheel_speed': '<S109>:1' */
  /*  Calculate maximum or minimum wheel speed during ABS or Traction event */
  /*  Detect max wheel speed during ABS */
  if ((((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) && (rtb_DataTypeConversion_e == 1))
  {
    /* '<S109>:1:6' */
    /*  Compare Front Left and Front Right wheel speed, and select the faster wheel speed */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_left >=
        (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right) {
      /* '<S109>:1:8' */
      i = 1;
    } else {
      /* '<S109>:1:9' */
      i = 2;
    }

    /*  Compare Rear Left and Rear Right wheel speed, and select the faster wheel speed */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left >
        (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right) {
      /* '<S109>:1:12' */
      rtb_whl_index = 3;
    } else {
      /* '<S109>:1:13' */
      rtb_whl_index = 4;
    }

    if (i == 1) {
      /* '<S109>:1:15' */
      if (rtb_whl_index == 3) {
        /* '<S109>:1:16' */
        /* Front Left wheel speed is maximum */
        if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_left > (*
             vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left) {
          /* '<S109>:1:18' */
          rtb_whl_index = 1;

          /* Rear Left wheel speed is maximum */
        } else {
          /* '<S109>:1:20' */
          rtb_whl_index = 3;
        }
      } else {
        /* Front Left wheel speed is maximum */
        if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_left > (*
             vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right) {
          /* '<S109>:1:24' */
          rtb_whl_index = 1;

          /* Rear Right wheel speed is maximum */
        } else {
          /* '<S109>:1:26' */
          rtb_whl_index = 4;
        }
      }
    } else if (rtb_whl_index == 3) {
      /* '<S109>:1:30' */
      /* Front Right wheel speed is maximum */
      if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right >
          (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left) {
        /* '<S109>:1:32' */
        rtb_whl_index = 2;

        /* Rear Left wheel speed is maximum */
      } else {
        /* '<S109>:1:34' */
        rtb_whl_index = 3;
      }
    } else {
      /* Front Right wheel speed is maximum */
      if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right >
          (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right) {
        /* '<S109>:1:38' */
        rtb_whl_index = 2;

        /* Rear Right wheel speed is maximum */
      } else {
        /* '<S109>:1:40' */
        rtb_whl_index = 4;
      }
    }

    /*  Detect min wheel speed during Traction     */
  } else if ((((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) && (rtb_TCS == 1)) {
    /* '<S109>:1:46' */
    /*  Compare Front Left and Front Right wheel speed, and select the slower wheel speed */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_left <=
        (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right) {
      /* '<S109>:1:48' */
      i = 1;
    } else {
      /* '<S109>:1:49' */
      i = 2;
    }

    /*  Compare Rear Left and Rear Right wheel speed, and select the slower wheel speed */
    if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left <
        (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right) {
      /* '<S109>:1:52' */
      rtb_whl_index = 3;
    } else {
      /* '<S109>:1:53' */
      rtb_whl_index = 4;
    }

    if (i == 1) {
      /* '<S109>:1:55' */
      if (rtb_whl_index == 3) {
        /* '<S109>:1:56' */
        /* Front Left wheel speed is minimum */
        if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_left < (*
             vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left) {
          /* '<S109>:1:58' */
          rtb_whl_index = 1;

          /* Rear Left wheel speed is minimum */
        } else {
          /* '<S109>:1:60' */
          rtb_whl_index = 3;
        }
      } else {
        /* Front Left wheel speed is minimum */
        if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_left < (*
             vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right) {
          /* '<S109>:1:64' */
          rtb_whl_index = 1;

          /* Rear Right wheel speed is minimum */
        } else {
          /* '<S109>:1:66' */
          rtb_whl_index = 4;
        }
      }
    } else if (rtb_whl_index == 3) {
      /* '<S109>:1:70' */
      /* Front Right wheel speed is minimum */
      if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right <
          (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_left) {
        /* '<S109>:1:72' */
        rtb_whl_index = 2;

        /* Rear Left wheel speed is minimum */
      } else {
        /* '<S109>:1:74' */
        rtb_whl_index = 3;
      }
    } else {
      /* Front Right wheel speed is minimum */
      if ((*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_front_right <
          (*vdy_ve_U_VDYInternalData_in).vdy_wpp_out.wheel_velo_rear_right) {
        /* '<S109>:1:78' */
        rtb_whl_index = 2;

        /* Rear Right wheel speed is minimum */
      } else {
        /* '<S109>:1:80' */
        rtb_whl_index = 4;
      }
    }

    /* Default case     */
  } else {
    /* '<S109>:1:87' */
    rtb_whl_index = 1;
  }

  /*  Compute mean wheel speed */
  /* '<S109>:1:91' */
  rtb_DeadZone_FL = ((((*vdy_ve_U_VDYInternalData_in).
                       vdy_wpp_out.wheel_velo_front_left +
                       (*vdy_ve_U_VDYInternalData_in).
                       vdy_wpp_out.wheel_velo_front_right) +
                      (*vdy_ve_U_VDYInternalData_in).
                      vdy_wpp_out.wheel_velo_rear_left) +
                     (*vdy_ve_U_VDYInternalData_in).
                     vdy_wpp_out.wheel_velo_rear_right) * 0.25F;

  /* BusSelector: '<Root>/Bus Selector5' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 32; i++) {
    rtb_State[i] = (*vdy_ve_U_VDYInputData).Signals.State[(i)];
    rtb_State_h[i] = (*vdy_ve_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<Root>/Time2Sec' */

  /* Product: '<S9>/Time2Sec' incorporates:
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_DeadZone_FR = ((real32_T)(*vdy_ve_U_VDYInputData).Frame.CycleTime) /
    1000.0F;

  /* end of Outputs for SubSystem: '<Root>/Time2Sec' */

  /* Embedded MATLAB: '<S1>/make_A_matrix' */
  /* Embedded MATLAB Function 'A/make_A_matrix': '<S20>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S20>:1:5' */
  rtb_A[0] = 1.0F;
  rtb_A[2] = rtb_DeadZone_FR;
  for (i = 0; i < 2; i++) {
    rtb_A[1 + (i << 1)] = (real32_T)i;
  }

  /* UnitDelay: '<S68>/x_init_reset' */
  rtb_vdy_sfunc_P_post_o1 = vdy_ve_DWork->x_init_reset_DSTATE;

  /* UnitDelay: '<S68>/x_delay' */
  for (i = 0; i < 2; i++) {
    rtb_vdy_sfunc_K_nu_o2[i] = vdy_ve_DWork->x_delay_DSTATE[(i)];
  }

  /* Switch: '<S68>/Init' incorporates:
   *  Constant: '<S14>/x_init_a'
   */
  if (rtb_vdy_sfunc_P_post_o1 != 0) {
    rtb_vdy_sfunc_K_nu_o2[0] = rtb_DeadZone_FL;
    rtb_vdy_sfunc_K_nu_o2[1] = vdy_ve_x_init_p;
  }

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_x_pred' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_vdy_sfunc_K_nu_o2, rtb_x_pred, (uint8_T)2, (uint8_T)2,
    (uint8_T)1);

  /* Embedded MATLAB: '<S14>/hx' */
  /* Embedded MATLAB Function 'four_wheel_speed_fusion1/hx': '<S65>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S65>:1:6' */
  for (i = 0; i < 8; i++) {
    rtb_H[i] = vdy_ve_H_p[(i)];
  }

  /* '<S65>:1:8' */
  for (i = 0; i < 4; i++) {
    rtb_hx[i] = 0.0F;
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_hx[i] = (vdy_ve_H_p[(i_0 << 2) + i] * rtb_x_pred[i_0]) + rtb_hx[i];
    }
  }

  /* BusSelector: '<S7>/Bus Selector5' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_VehLongAccelExt_h = (*vdy_ve_U_VDYInputData).Signals.VehLongAccelExt;
  for (i = 0; i < 32; i++) {
    rtb_State_n[i] = (*vdy_ve_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<S7>/Get_IO_State_VEHACL_EXT' */
  vdy_ve_Get_IO_State_WVEL_FL(rtb_State_n, &vdy_ve_B->Get_IO_State_VEHACL_EXT,
                              ((uint32_T)VDY_SIN_POS_VEHACL_EXT));

  /* end of Outputs for SubSystem: '<S7>/Get_IO_State_VEHACL_EXT' */

  /* Sum: '<S55>/Sum' incorporates:
   *  Gain: '<S55>/Gain'
   *  Sum: '<S55>/Diff'
   *  UnitDelay: '<S12>/last_veh_velocity'
   *  UnitDelay: '<S55>/TP_filter_Delay'
   */
  rtb_Sum = ((vdy_ve_DWork->TP_filter_Delay_DSTATE -
              vdy_ve_DWork->last_veh_velocity_DSTATE) * 0.7F) +
    vdy_ve_DWork->last_veh_velocity_DSTATE;

  /* Sum: '<S12>/Add' */
  rtb_Add_c = rtb_DeadZone_FL - rtb_Sum;

  /* Embedded MATLAB: '<S12>/gain_ramp' incorporates:
   *  S-Function (ex_sfun_abs): '<S12>/Abs'
   *  Sum: '<S12>/Add'
   */
  /* Embedded MATLAB Function 'calc_diff_q_gain/gain_ramp': '<S56>:1' */
  /*  zero crossing detection */
  /*  if the veh velocity is below zero set it to specified value */
  /* '<S56>:1:4' */
  rtb_EWMA_Right = (vdy_ve_Q_gain_p[2] * CML_f_Abs( (real32_T)rtb_Add_c)) + 1.0F;

  /* Outputs for atomic SubSystem: '<S13>/Get_IO_State_WTCKS_FL' */
  vdy_ve_Get_IO_State_WVEL_FL(rtb_State, &vdy_ve_B->Get_IO_State_WTCKS_FL,
    ((uint32_T)VDY_SIN_POS_WTCKS_FL));

  /* end of Outputs for SubSystem: '<S13>/Get_IO_State_WTCKS_FL' */

  /* Outputs for atomic SubSystem: '<S13>/Get_IO_State_WTCKS_FR' */
  vdy_ve_Get_IO_State_WVEL_FL(rtb_State, &vdy_ve_B->Get_IO_State_WTCKS_FR,
    ((uint32_T)VDY_SIN_POS_WTCKS_FR));

  /* end of Outputs for SubSystem: '<S13>/Get_IO_State_WTCKS_FR' */

  /* Outputs for atomic SubSystem: '<S13>/Get_IO_State_WTCKS_RL' */
  vdy_ve_Get_IO_State_WVEL_FL(rtb_State, &vdy_ve_B->Get_IO_State_WTCKS_RL,
    ((uint32_T)VDY_SIN_POS_WTCKS_RL));

  /* end of Outputs for SubSystem: '<S13>/Get_IO_State_WTCKS_RL' */

  /* Outputs for atomic SubSystem: '<S13>/Get_IO_State_WTCKS_RR' */
  vdy_ve_Get_IO_State_WVEL_FL(rtb_State, &vdy_ve_B->Get_IO_State_WTCKS_RR,
    ((uint32_T)VDY_SIN_POS_WTCKS_RR));

  /* end of Outputs for SubSystem: '<S13>/Get_IO_State_WTCKS_RR' */

  /* Embedded MATLAB: '<Root>/calc_Q_gain' incorporates:
   *  Logic: '<S13>/Logical Operator'
   */
  /* Embedded MATLAB Function 'calc_Q_gain': '<S11>:1' */
  /* '<S11>:1:2' */
  rtb_EWMA_Sum_i = rtb_EWMA_Right;

  /*  if the mean velocity is below a specified value 0.4 */
  /*  the model variance gain is raised */
  if (rtb_DeadZone_FL <= vdy_ve_Q_gain_p[0]) {
    /* '<S11>:1:6' */
    /* '<S11>:1:7' */
    rtb_EWMA_Sum_i = (vdy_ve_Q_gain_p[0] - rtb_DeadZone_FL) * vdy_ve_Q_gain_p[1];
  }

  /*  if no wheel puls counters are available */
  if ((((uint32_T)((((vdy_ve_B->Get_IO_State_WTCKS_FL.IndexVector != 0) &&
                     (vdy_ve_B->Get_IO_State_WTCKS_FR.IndexVector != 0)) &&
                    (vdy_ve_B->Get_IO_State_WTCKS_RL.IndexVector != 0)) &&
                   (vdy_ve_B->Get_IO_State_WTCKS_RR.IndexVector != 0))) !=
       ((uint32_T)VDY_IO_STATE_VALID)) && (rtb_DeadZone_FL <= 0.7F)) {
    /* '<S11>:1:11' */
    /*  from v=0 ->g=14 to v=0.7 ->g=0 add diff_q_gain */
    /* '<S11>:1:13' */
    rtb_EWMA_Sum_i = (14.0F - (rtb_DeadZone_FL * 20.0F)) + rtb_EWMA_Right;
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/sigma_model'
   */
  for (i = 0; i < 2; i++) {
    rtb_Product[i] = vdy_ve_Q_sigmas_p[(i)] * rtb_EWMA_Sum_i;
  }

  /* Embedded MATLAB: '<S7>/Increase_Q2' incorporates:
   *  BusSelector: '<S7>/Bus Selector5'
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/VDYInputData'
   *  Product: '<S7>/Product3'
   *  S-Function (ex_sfun_abs): '<S7>/abs_accel_ext'
   */
  /* Embedded MATLAB Function 'Q/Increase_Q2': '<S50>:1' */
  /* % Increase of Q for Dynamic Accelaration */
  if ((CML_f_Abs( (real32_T)rtb_VehLongAccelExt_h) > 0.5F) && (((uint32_T)
        vdy_ve_B->Get_IO_State_VEHACL_EXT.IndexVector) == ((uint32_T)
        VDY_IO_STATE_VALID))) {
    /* '<S50>:1:3' */
    /* '<S50>:1:5' */
    for (i = 0; i < 2; i++) {
      rtb_Product[i] = 35.0F * rtb_Product[i];
    }
  } else {
    /* '<S50>:1:9' */
  }

  /* SignalConversion: '<S51>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Product: '<S7>/Divide'
   *  Product: '<S7>/Product1'
   */
  rtb_TmpSignalConversionAtSFun_o[0] = (rtb_DeadZone_FR * rtb_DeadZone_FR) *
    0.5F;
  rtb_TmpSignalConversionAtSFun_o[1] = rtb_DeadZone_FR;

  /* Embedded MATLAB: '<S7>/makeQ' */
  /* Embedded MATLAB Function 'Q/makeQ': '<S51>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S51>:1:5' */

  /* UnitDelay: '<S14>/P_delay' */
  for (i = 0; i < 4; i++) {
    rtb_At[i] = vdy_ve_DWork->P_delay_DSTATE[(i)];
  }

  /* S-Function (MatrixMultiplication): '<S66>/vdy_s-func_A_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_A,
    (real32_T*)rtb_At, rtb_vdy_sfunc_A_P_post_o2, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Math: '<S14>/At' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_At[i_0 + (i << 1)] = rtb_A[(i_0 << 1) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S66>/vdy_s-func_A_P_post_At' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_A_P_post_o2, (real32_T*)rtb_At, rtb_KH, (uint8_T)2, (uint8_T)2,
    (uint8_T)2);

  /* Sum: '<S14>/APA_Q' */
  for (i = 0; i < 2; i++) {
    rtb_TmpSignalConversionAtSFun_0[i] = rtb_TmpSignalConversionAtSFun_o[i] *
      rtb_Product[i];
    rtb_Product_0[i] = rtb_Product[i] * rtb_TmpSignalConversionAtSFun_o[i];
  }

  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_P_pred[i_0 + (i << 1)] = rtb_KH[(i << 1) + i_0] +
        (rtb_TmpSignalConversionAtSFun_0[i_0] * rtb_Product_0[i]);
    }
  }

  /* S-Function (MatrixMultiplication): '<S67>/vdy_s-func_P_pred_H' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_H,
    (real32_T*)rtb_P_pred, rtb_vdy_sfunc_P_pred_H_o2, (uint8_T)2, (uint8_T)4,
    (uint8_T)2);

  /* Math: '<S14>/Ht' */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_Ht[i_0 + (i << 1)] = rtb_H[(i_0 << 2) + i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S67>/vdy_s-func_P_pred_H_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)
    rtb_vdy_sfunc_P_pred_H_o2, (real32_T*)rtb_Ht, rtb_vdy_sfunc_P_pred_H_Ht_o2,
    (uint8_T)2, (uint8_T)4, (uint8_T)4);

  /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
   *  Logic: '<S15>/Logical Operator1'
   */
  rtb_DataTypeConversion_a = ((rtb_DataTypeConversion_e != 0) || (rtb_TCS != 0));

  /* UnitDelay: '<S82>/TCS_Var_Flag_Init' */
  rtb_TCS_Var_Flag_Init = vdy_ve_DWork->TCS_Var_Flag_Init_DSTATE;

  /* Switch: '<S82>/Switch' incorporates:
   *  UnitDelay: '<S82>/TCS_Var_Flag'
   */
  if (rtb_TCS_Var_Flag_Init != 0) {
    rtb_vdy_sfunc_P_post_o1 = rtb_DataTypeConversion_a;
  } else {
    rtb_vdy_sfunc_P_post_o1 = vdy_ve_DWork->TCS_Var_Flag_DSTATE;
  }

  /* RelationalOperator: '<S82>/TCS_transient_flag' */
  rtb_TCS_transient_flag = (rtb_DataTypeConversion_a != rtb_vdy_sfunc_P_post_o1);

  /* Switch: '<S82>/Switch2' incorporates:
   *  Constant: '<S82>/Constant1'
   *  Constant: '<S82>/Constant2'
   *  Sum: '<S82>/Sum'
   *  UnitDelay: '<S82>/Step_Counter_Var'
   */
  if (rtb_TCS_transient_flag) {
    rtb_vdy_sfunc_P_post_o1 = 0U;
  } else {
    rtb_vdy_sfunc_P_post_o1 = (uint8_T)(1U + ((uint32_T)
      vdy_ve_DWork->Step_Counter_Var_DSTATE));
  }

  /* Switch: '<S82>/Switch1' incorporates:
   *  Constant: '<S82>/Constant3'
   *  RelationalOperator: '<S82>/Relational Operator1'
   */
  if (rtb_vdy_sfunc_P_post_o1 > 20) {
    rtb_Switch1 = 20U;
  } else {
    rtb_Switch1 = rtb_vdy_sfunc_P_post_o1;
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  rtb_DataTypeConversion1_b = (uint8_T)rtb_whl_index;

  /* Embedded MATLAB: '<S15>/Select_min_or_max_wheel_speed' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_R_matrix/Select_min_or_max_wheel_speed': '<S74>:1' */
  /*  If either of Traction or ABS flag is Active */
  if ((((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) && (rtb_DataTypeConversion_a == 1))
  {
    /* '<S74>:1:4' */
    /*  If Front Left Wheel velocity is selected, set all 4 wheel speeds as Front Left wheel speed */
    if (rtb_DataTypeConversion1_b == 1) {
      /* '<S74>:1:7' */
      /* '<S74>:1:8' */
      rtb_Whl_vel_var_FL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left_var;

      /* '<S74>:1:9' */
      rtb_Whl_vel_var_FR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left_var;

      /* '<S74>:1:10' */
      rtb_Whl_vel_var_RL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left_var;

      /* '<S74>:1:11' */
      rtb_Whl_vel_var_RR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left_var;

      /*  If Front Right Wheel velocity is selected, set all 4 wheel speeds as Front Right wheel speed */
    } else if (rtb_DataTypeConversion1_b == 2) {
      /* '<S74>:1:14' */
      /* '<S74>:1:15' */
      rtb_Whl_vel_var_FL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right_var;

      /* '<S74>:1:16' */
      rtb_Whl_vel_var_FR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right_var;

      /* '<S74>:1:17' */
      rtb_Whl_vel_var_RL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right_var;

      /* '<S74>:1:18' */
      rtb_Whl_vel_var_RR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right_var;

      /*  If Rear Left Wheel velocity is selected, set all 4 wheel speeds as Rear Left wheel speed */
    } else if (rtb_DataTypeConversion1_b == 3) {
      /* '<S74>:1:21' */
      /* '<S74>:1:22' */
      rtb_Whl_vel_var_FL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left_var;

      /* '<S74>:1:23' */
      rtb_Whl_vel_var_FR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left_var;

      /* '<S74>:1:24' */
      rtb_Whl_vel_var_RL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left_var;

      /* '<S74>:1:25' */
      rtb_Whl_vel_var_RR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left_var;

      /*  If Rear Right velocity is selected, set all 4 wheel speeds as Rear Right wheel speed */
    } else {
      /* '<S74>:1:29' */
      rtb_Whl_vel_var_FL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right_var;

      /* '<S74>:1:30' */
      rtb_Whl_vel_var_FR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right_var;

      /* '<S74>:1:31' */
      rtb_Whl_vel_var_RL_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right_var;

      /* '<S74>:1:32' */
      rtb_Whl_vel_var_RR_out = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right_var;
    }

    /*  Normal driving (Both Traction and ABS are Inactive) */
  } else {
    /* '<S74>:1:37' */
    rtb_Whl_vel_var_FL_out = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_left_var;

    /* '<S74>:1:38' */
    rtb_Whl_vel_var_FR_out = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_right_var;

    /* '<S74>:1:39' */
    rtb_Whl_vel_var_RL_out = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_left_var;

    /* '<S74>:1:40' */
    rtb_Whl_vel_var_RR_out = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_right_var;
  }

  /* Outputs for atomic SubSystem: '<S15>/check_variance_R_matrix_FL' */
  check_variance_R_matrix(rtb_Whl_vel_var_FL_out, &rtb_create_var_vector[0],
    &vdy_ve_DWork->check_variance_R_matrix_FL);

  /* end of Outputs for SubSystem: '<S15>/check_variance_R_matrix_FL' */

  /* Outputs for atomic SubSystem: '<S15>/check_variance_R_matrix_FR' */
  check_variance_R_matrix(rtb_Whl_vel_var_FR_out, &rtb_create_var_vector[1],
    &vdy_ve_DWork->check_variance_R_matrix_FR);

  /* end of Outputs for SubSystem: '<S15>/check_variance_R_matrix_FR' */

  /* Outputs for atomic SubSystem: '<S15>/check_variance_R_matrix_RL' */
  check_variance_R_matrix(rtb_Whl_vel_var_RL_out, &rtb_create_var_vector[2],
    &vdy_ve_DWork->check_variance_R_matrix_RL);

  /* end of Outputs for SubSystem: '<S15>/check_variance_R_matrix_RL' */

  /* Outputs for atomic SubSystem: '<S15>/check_variance_R_matrix_RR' */
  check_variance_R_matrix(rtb_Whl_vel_var_RR_out, &rtb_create_var_vector[3],
    &vdy_ve_DWork->check_variance_R_matrix_RR);

  /* end of Outputs for SubSystem: '<S15>/check_variance_R_matrix_RR' */

  /* UnitDelay: '<S73>/FL_var_delay' */
  rtb_FL_var_delay = vdy_ve_DWork->FL_var_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S73>/FL_R_step_increment_ve_model' */
  step_increment_ve_model(rtb_FL_var_delay, rtb_TCS_transient_flag,
    rtb_create_var_vector[0], rtb_Switch1, rtb_TCS_Var_Flag_Init,
    &vdy_ve_B->FL_R_step_increment_ve_model,
    &vdy_ve_DWork->FL_R_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S73>/FL_R_step_increment_ve_model' */

  /* UnitDelay: '<S73>/FR_var_delay' */
  rtb_FR_var_delay = vdy_ve_DWork->FR_var_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S73>/FR_R_step_increment_ve_model' */
  step_increment_ve_model(rtb_FR_var_delay, rtb_TCS_transient_flag,
    rtb_create_var_vector[1], rtb_Switch1, rtb_TCS_Var_Flag_Init,
    &vdy_ve_B->FR_R_step_increment_ve_model,
    &vdy_ve_DWork->FR_R_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S73>/FR_R_step_increment_ve_model' */

  /* UnitDelay: '<S73>/RL_var_delay' */
  rtb_RL_var_delay = vdy_ve_DWork->RL_var_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S73>/RL_R_step_increment_ve_model' */
  step_increment_ve_model(rtb_RL_var_delay, rtb_TCS_transient_flag,
    rtb_create_var_vector[2], rtb_Switch1, rtb_TCS_Var_Flag_Init,
    &vdy_ve_B->RL_R_step_increment_ve_model,
    &vdy_ve_DWork->RL_R_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S73>/RL_R_step_increment_ve_model' */

  /* UnitDelay: '<S73>/RR_var_delay' */
  rtb_RR_var_delay = vdy_ve_DWork->RR_var_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S73>/RR_R_step_increment_ve_model' */
  step_increment_ve_model(rtb_RR_var_delay, rtb_TCS_transient_flag,
    rtb_create_var_vector[3], rtb_Switch1, rtb_TCS_Var_Flag_Init,
    &vdy_ve_B->RR_R_step_increment_ve_model,
    &vdy_ve_DWork->RR_R_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S73>/RR_R_step_increment_ve_model' */

  /* Embedded MATLAB: '<S15>/Merge_wheel_variances' incorporates:
   *  SignalConversion: '<S72>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* Embedded MATLAB Function 'make_R_matrix/Merge_wheel_variances': '<S72>:1' */
  /*  If either of Traction or ABS flag is Active */
  if (((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) {
    /* '<S72>:1:4' */
    /* '<S72>:1:5' */
    rtb_R_out[0] = vdy_ve_B->FL_R_step_increment_ve_model.sum;
    rtb_R_out[1] = vdy_ve_B->FR_R_step_increment_ve_model.sum;
    rtb_R_out[2] = vdy_ve_B->RL_R_step_increment_ve_model.sum;
    rtb_R_out[3] = vdy_ve_B->RR_R_step_increment_ve_model.sum;

    /*  Normal driving (Both Traction and ABS are Inactive) */
  } else {
    /* '<S72>:1:8' */
    for (i = 0; i < 4; i++) {
      rtb_R_out[i] = rtb_create_var_vector[i];
    }
  }

  /* Embedded MATLAB: '<S15>/diag' */
  /* Embedded MATLAB Function 'make_R_matrix/diag': '<S79>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S79>:1:5' */
  vdy_memset_s((void *)(&rtb_y[0]), (int32_T)0.0F, sizeof(real32_T) << 4U);
  for (rtb_whl_index = 0; rtb_whl_index < 4; rtb_whl_index++) {
    rtb_y[rtb_whl_index + (rtb_whl_index << 2)] = rtb_R_out[rtb_whl_index];
  }

  /* Embedded MATLAB: '<S61>/Matrix_Inversion_4x4' */
  vdy_matrix_inversion_4x4(rtb_vdy_sfunc_P_pred_H_Ht_o2, rtb_y,
    &vdy_ve_B->sf_Matrix_Inversion_4x4);

  /* Embedded MATLAB: '<S14>/Reset_x_pred' */
  /* Embedded MATLAB Function 'four_wheel_speed_fusion1/Reset_x_pred': '<S63>:1' */
  if (vdy_ve_B->sf_Matrix_Inversion_4x4.det_flag) {
    /* '<S63>:1:4' */
    /* '<S63>:1:6' */
    rtb_Product[0] = rtb_DeadZone_FL;
    rtb_Product[1] = 0.0F;
  } else {
    /* '<S63>:1:10' */
    for (i = 0; i < 2; i++) {
      rtb_Product[i] = rtb_x_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_P_pred_Ht' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_pred,
    (real32_T*)rtb_Ht, rtb_P_predHt, (uint8_T)2, (uint8_T)2, (uint8_T)4);

  /* If: '<S61>/If' incorporates:
   *  ActionPort: '<S70>/Action Port'
   *  ActionPort: '<S71>/Action Port'
   *  SubSystem: '<S61>/calculate the gain'
   *  SubSystem: '<S61>/set gain to default value'
   */
  if (!vdy_ve_B->sf_Matrix_Inversion_4x4.det_flag) {
    /* S-Function (MatrixMultiplication): '<S70>/vdy_s-func_K' */
    rtb_vdy_sfunc_K_o1 = vdy_matrix_multiplication( (real32_T*)rtb_P_predHt,
      (real32_T*)vdy_ve_B->sf_Matrix_Inversion_4x4.HPHt_R_inv, rtb_K, (uint8_T)4,
      (uint8_T)2, (uint8_T)4);
  } else {
    /* Constant: '<S71>/Constant' */
    for (i = 0; i < 8; i++) {
      rtb_K[i] = vdy_ve_K_default_p[(i)];
    }
  }

  /* UnitDelay: '<S117>/TCS_Vel_Flag_Init' */
  rtb_TCS_Vel_Flag_Init = vdy_ve_DWork->TCS_Vel_Flag_Init_DSTATE;

  /* Switch: '<S117>/Switch' incorporates:
   *  UnitDelay: '<S117>/TCS_Vel_Flag'
   */
  if (rtb_TCS_Vel_Flag_Init != 0) {
    rtb_vdy_sfunc_P_post_o1 = rtb_TCS;
  } else {
    rtb_vdy_sfunc_P_post_o1 = vdy_ve_DWork->TCS_Vel_Flag_DSTATE;
  }

  /* RelationalOperator: '<S117>/TCS_transient_flag' */
  rtb_TCS_transient_flag_d = (rtb_TCS != rtb_vdy_sfunc_P_post_o1);

  /* Switch: '<S117>/Switch2' incorporates:
   *  Constant: '<S117>/Constant1'
   *  Constant: '<S117>/Constant2'
   *  Sum: '<S117>/Sum'
   *  UnitDelay: '<S117>/Step_Counter_Vel'
   */
  if (rtb_TCS_transient_flag_d) {
    rtb_vdy_sfunc_P_post_o1 = 1U;
  } else {
    rtb_vdy_sfunc_P_post_o1 = (uint8_T)(1U + ((uint32_T)
      vdy_ve_DWork->Step_Counter_Vel_DSTATE));
  }

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/Constant3'
   *  RelationalOperator: '<S117>/Relational Operator1'
   */
  if (rtb_vdy_sfunc_P_post_o1 > 20) {
    rtb_Switch1_o = 20U;
  } else {
    rtb_Switch1_o = rtb_vdy_sfunc_P_post_o1;
  }

  /* Embedded MATLAB: '<S16>/Select_min_or_max_wheel_speed' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  /* Embedded MATLAB Function 'make_z_vektor/Select_min_or_max_wheel_speed': '<S111>:1' */
  /*  If Traction flag is Active */
  if ((((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) && (rtb_TCS == 1)) {
    /* '<S111>:1:4' */
    /*  If Front Left Wheel velocity is minimum, set all 4 wheel speeds as Front Left wheel speed */
    if (rtb_DataTypeConversion1_b == 1) {
      /* '<S111>:1:7' */
      /* '<S111>:1:8' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /* '<S111>:1:9' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /* '<S111>:1:10' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /* '<S111>:1:11' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /*  If Front Right Wheel velocity is minimum, set all 4 wheel speeds as Front Right wheel speed */
    } else if (rtb_DataTypeConversion1_b == 2) {
      /* '<S111>:1:14' */
      /* '<S111>:1:15' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /* '<S111>:1:16' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /* '<S111>:1:17' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /* '<S111>:1:18' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /*  If Rear Left Wheel velocity is minimum, set all 4 wheel speeds as Rear Left wheel speed */
    } else if (rtb_DataTypeConversion1_b == 3) {
      /* '<S111>:1:21' */
      /* '<S111>:1:22' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /* '<S111>:1:23' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /* '<S111>:1:24' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /* '<S111>:1:25' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /*  If Rear Right Wheel velocity is minimum, set all 4 wheel speeds as Rear Right wheel speed */
    } else {
      /* '<S111>:1:29' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;

      /* '<S111>:1:30' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;

      /* '<S111>:1:31' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;

      /* '<S111>:1:32' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;
    }

    /*  If ABS flag is Active     */
  } else if ((((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) &&
             (rtb_DataTypeConversion_e == 1)) {
    /* '<S111>:1:36' */
    /*  If Front Left Wheel velocity is maximum, set all 4 wheel speeds as Front Left wheel speed */
    if (rtb_DataTypeConversion1_b == 1) {
      /* '<S111>:1:39' */
      /* '<S111>:1:40' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /* '<S111>:1:41' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /* '<S111>:1:42' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /* '<S111>:1:43' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_left;

      /*  If Front Right Wheel velocity is maximum, set all 4 wheel speeds as Front Right wheel speed */
    } else if (rtb_DataTypeConversion1_b == 2) {
      /* '<S111>:1:46' */
      /* '<S111>:1:47' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /* '<S111>:1:48' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /* '<S111>:1:49' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /* '<S111>:1:50' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_front_right;

      /*  If Rear Left Wheel velocity is maximum, set all 4 wheel speeds as Rear Left wheel speed */
    } else if (rtb_DataTypeConversion1_b == 3) {
      /* '<S111>:1:53' */
      /* '<S111>:1:54' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /* '<S111>:1:55' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /* '<S111>:1:56' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /* '<S111>:1:57' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_left;

      /*  If Rear Right Wheel velocity is maximum, set all 4 wheel speeds as Rear Right wheel speed */
    } else {
      /* '<S111>:1:61' */
      rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;

      /* '<S111>:1:62' */
      rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;

      /* '<S111>:1:63' */
      rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;

      /* '<S111>:1:64' */
      rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
        vdy_wpp_out.wheel_velo_rear_right;
    }

    /*  Normal driving (Both Traction and ABS are Inactive) */
  } else {
    /* '<S111>:1:69' */
    rtb_create_vector[0] = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_left;

    /* '<S111>:1:70' */
    rtb_create_vector[1] = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_front_right;

    /* '<S111>:1:71' */
    rtb_create_vector[2] = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_left;

    /* '<S111>:1:72' */
    rtb_create_vector[3] = (*vdy_ve_U_VDYInternalData_in).
      vdy_wpp_out.wheel_velo_rear_right;
  }

  /* UnitDelay: '<S112>/FL_vel_delay' */
  rtb_FL_vel_delay = vdy_ve_DWork->FL_vel_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S112>/FL_z_step_increment_ve_model' */
  step_increment_ve_model(rtb_FL_vel_delay, rtb_TCS_transient_flag_d,
    rtb_create_vector[0], rtb_Switch1_o, rtb_TCS_Vel_Flag_Init,
    &vdy_ve_B->FL_z_step_increment_ve_model,
    &vdy_ve_DWork->FL_z_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S112>/FL_z_step_increment_ve_model' */

  /* UnitDelay: '<S112>/FR_vel_delay' */
  rtb_FR_vel_delay = vdy_ve_DWork->FR_vel_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S112>/FR_z_step_increment_ve_model' */
  step_increment_ve_model(rtb_FR_vel_delay, rtb_TCS_transient_flag_d,
    rtb_create_vector[1], rtb_Switch1_o, rtb_TCS_Vel_Flag_Init,
    &vdy_ve_B->FR_z_step_increment_ve_model,
    &vdy_ve_DWork->FR_z_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S112>/FR_z_step_increment_ve_model' */

  /* UnitDelay: '<S112>/RL_vel_delay' */
  rtb_RL_vel_delay = vdy_ve_DWork->RL_vel_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S112>/RL_z_step_increment_ve_model' */
  step_increment_ve_model(rtb_RL_vel_delay, rtb_TCS_transient_flag_d,
    rtb_create_vector[2], rtb_Switch1_o, rtb_TCS_Vel_Flag_Init,
    &vdy_ve_B->RL_z_step_increment_ve_model,
    &vdy_ve_DWork->RL_z_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S112>/RL_z_step_increment_ve_model' */

  /* UnitDelay: '<S112>/RR_vel_delay' */
  rtb_RR_vel_delay = vdy_ve_DWork->RR_vel_delay_DSTATE;

  /* Outputs for atomic SubSystem: '<S112>/RR_z_step_increment_ve_model' */
  step_increment_ve_model(rtb_RR_vel_delay, rtb_TCS_transient_flag_d,
    rtb_create_vector[3], rtb_Switch1_o, rtb_TCS_Vel_Flag_Init,
    &vdy_ve_B->RR_z_step_increment_ve_model,
    &vdy_ve_DWork->RR_z_step_increment_ve_model);

  /* end of Outputs for SubSystem: '<S112>/RR_z_step_increment_ve_model' */

  /* Embedded MATLAB: '<S16>/Merge_wheel_speeds' incorporates:
   *  SignalConversion: '<S110>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* Embedded MATLAB Function 'make_z_vektor/Merge_wheel_speeds': '<S110>:1' */
  /*  If Traction flag is Active */
  if (((uint32_T)CFG_VDY_INT_TCS_ABS) == 1U) {
    /* '<S110>:1:4' */
    /* '<S110>:1:5' */
    rtb_nu[0] = vdy_ve_B->FL_z_step_increment_ve_model.sum;
    rtb_nu[1] = vdy_ve_B->FR_z_step_increment_ve_model.sum;
    rtb_nu[2] = vdy_ve_B->RL_z_step_increment_ve_model.sum;
    rtb_nu[3] = vdy_ve_B->RR_z_step_increment_ve_model.sum;

    /*  Normal driving (Traction is Inactive) */
  } else {
    /* '<S110>:1:8' */
    for (i = 0; i < 4; i++) {
      rtb_nu[i] = rtb_create_vector[i];
    }
  }

  /* Sum: '<S14>/z_Hx' */
  for (i = 0; i < 4; i++) {
    rtb_nu[i] = rtb_nu[i] - rtb_hx[i];
  }

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_K_nu' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_nu, rtb_vdy_sfunc_K_nu_o2, (uint8_T)4, (uint8_T)2, (uint8_T)1);

  /* Sum: '<S14>/x_Knu' */
  for (i = 0; i < 2; i++) {
    rtb_Product[i] = rtb_Product[i] + rtb_vdy_sfunc_K_nu_o2[i];
  }

  /* Embedded MATLAB: '<Root>/zero_correction_v' */
  /* Embedded MATLAB Function 'zero_correction_v': '<S19>:1' */
  /*  zero crossing detection */
  /*  if the veh velocity is below zero set is to specified value */
  if (((rtb_Product[0] <= vdy_ve_a_v_zero_p[0]) || (rtb_Product[0] <
        vdy_ve_a_v_zero_p[3])) || (rtb_DeadZone_FL < vdy_ve_a_v_zero_p[3])) {
    /* '<S19>:1:4' */
    /* '<S19>:1:5' */
    rtb_v_out = vdy_ve_a_v_zero_p[6];
  } else {
    /* '<S19>:1:7' */
    rtb_v_out = rtb_Product[0];
  }

  /* Sum: '<S52>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S52>/Vel_out_delay'
   */
  rtb_DeadZone_FR = rtb_v_out - vdy_ve_DWork->Vel_out_delay_DSTATE;

  /* Switch: '<S53>/Switch2' incorporates:
   *  RelationalOperator: '<S53>/LowerRelop1'
   */
  if (!(rtb_DeadZone_FR > rtb_EWVAR_Right)) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant2'
     */
    if (rtb_Add >= 5.0F) {
      rtb_DeadZone_FL = -15.0F;
    } else {
      rtb_DeadZone_FL = -100000.0F;
    }

    /* Product: '<S52>/delta fall limit' */
    rtb_DeadZone_FL *= 0.02F;

    /* Switch: '<S53>/Switch' incorporates:
     *  RelationalOperator: '<S53>/UpperRelop'
     */
    if (rtb_DeadZone_FR < rtb_DeadZone_FL) {
      rtb_DeadZone_FR = rtb_DeadZone_FL;
    }

    rtb_EWVAR_Right = rtb_DeadZone_FR;
  }

  /* Sum: '<S52>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S52>/Vel_out_delay'
   */
  rtb_DeadZone_FL = rtb_EWVAR_Right + vdy_ve_DWork->Vel_out_delay_DSTATE;

  /* BusAssignment: '<Root>/Bus Assignment1' */
  rtb_VdyAccel.vdy_ve_out.veh_velo = rtb_DeadZone_FL;

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_K_H' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_K,
    (real32_T*)rtb_H, rtb_KH, (uint8_T)4, (uint8_T)2, (uint8_T)2);

  /* Sum: '<S14>/1_KH' incorporates:
   *  Constant: '<S14>/eye'
   */
  for (i = 0; i < 4; i++) {
    rtb_KH[i] = vdy_ve_I_matrix_p[(i)] - rtb_KH[i];
  }

  /* Embedded MATLAB: '<S14>/Reset_P_pred' */
  /* Embedded MATLAB Function 'four_wheel_speed_fusion1/Reset_P_pred': '<S62>:1' */
  if (vdy_ve_B->sf_Matrix_Inversion_4x4.det_flag) {
    /* '<S62>:1:4' */
    /* '<S62>:1:6' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = vdy_ve_P_init_p[(i)];
    }
  } else {
    /* '<S62>:1:10' */
    for (i = 0; i < 4; i++) {
      rtb_P_pred_out[i] = rtb_P_pred[i];
    }
  }

  /* S-Function (MatrixMultiplication): '<S14>/vdy_s-func_P_post' */
  rtb_vdy_sfunc_P_post_o1 = vdy_matrix_multiplication( (real32_T*)rtb_KH,
    (real32_T*)rtb_P_pred_out, rtb_P_post, (uint8_T)2, (uint8_T)2, (uint8_T)2);

  /* Embedded MATLAB: '<S14>/diag' */
  /* Embedded MATLAB Function 'four_wheel_speed_fusion1/diag': '<S64>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S64>:1:5' */

  /* Embedded MATLAB: '<S17>/v_var_correct' incorporates:
   *  UnitDelay: '<S17>/last_v_var'
   */
  /* Embedded MATLAB Function 'v_var_correct/v_var_correct': '<S122>:1' */
  /* check if varianc is negative */
  if (rtb_P_post[0] <= 0.0F) {
    /* '<S122>:1:3' */
    /* '<S122>:1:4' */
    rtb_DeadZone_FR = vdy_ve_DWork->last_v_var_DSTATE;
  } else {
    /*  if the veh velocity is blow the specified value set the velocity variance to a fix value */
    if ((rtb_v_out <= vdy_ve_a_v_zero_p[2]) && (rtb_P_post[0] >=
         vdy_ve_a_v_zero_p[5])) {
      /* '<S122>:1:7' */
      /* '<S122>:1:8' */
      rtb_DeadZone_FR = vdy_ve_a_v_zero_p[5];
    } else {
      /* '<S122>:1:10' */
      rtb_DeadZone_FR = rtb_P_post[0];
    }
  }

  /* BusAssignment: '<Root>/Bus Assignment3' */
  rtb_VdyAccel.vdy_ve_out.veh_velo_var = rtb_DeadZone_FR;

  /* Embedded MATLAB: '<S10>/a_var_correct' incorporates:
   *  UnitDelay: '<S10>/last_a_var'
   */
  /* Embedded MATLAB Function 'a_var_correct/a_var_correct': '<S54>:1' */
  /* check if varianc is negative */
  if (rtb_P_post[3] <= 0.0F) {
    /* '<S54>:1:3' */
    /* '<S54>:1:4' */
    rtb_EWMA_Right = vdy_ve_DWork->last_a_var_DSTATE;
  } else {
    /*  if the veh velocity is blow the specified value set the velocity variance to a fix value */
    if (rtb_v_out <= vdy_ve_a_v_zero_p[2]) {
      /* '<S54>:1:7' */
      /* '<S54>:1:8' */
      rtb_EWMA_Right = vdy_ve_a_v_zero_p[8];
    } else {
      /* '<S54>:1:10' */
      rtb_EWMA_Right = rtb_P_post[3];
    }
  }

  /* BusAssignment: '<Root>/veh_velo' */
  rtb_VdyAccel.vdy_ve_out.veh_accel_var = rtb_EWMA_Right;

  /* Embedded MATLAB: '<Root>/zero_correcction_a' */
  /* Embedded MATLAB Function 'zero_correcction_a': '<S18>:1' */
  /*  Note: In order to eliminate QAC Level-4 warnings, the if-condition below is rearranged */
  /*  zero crossing detection */
  /*  if the veh acceleration is below zero set is to specified value */
  if ((rtb_v_out <= vdy_ve_a_v_zero_p[1]) && ((rtb_Product[1] <
        vdy_ve_a_v_zero_p[4]) || (rtb_Product[1] > (-vdy_ve_a_v_zero_p[4])))) {
    /* '<S18>:1:6' */
    /* '<S18>:1:7' */
    rtb_EWMA_Sum_i = vdy_ve_a_v_zero_p[7];
  } else {
    /* '<S18>:1:9' */
    rtb_EWMA_Sum_i = rtb_Product[1];
  }

  /* Sum: '<S21>/Add' incorporates:
   *  UnitDelay: '<S21>/JerkDetectAccel'
   */
  rtb_Add_j = rtb_EWMA_Sum_i - vdy_ve_DWork->JerkDetectAccel_DSTATE;

  /* RelationalOperator: '<S2>/Relational Operator' incorporates:
   *  Constant: '<S2>/P_v_min [m//s]'
   */
  rtb_WVEL_FL_valid = (rtb_DeadZone_FL >= 0.833333F);

  /* Embedded MATLAB: '<S21>/JerkDetect' incorporates:
   *  Constant: '<S2>/P_Jerk_Height_Extreme'
   *  Constant: '<S2>/P_Jerk_Height_Normal'
   *  Constant: '<S2>/P_Max_DAccel'
   */
  /* Embedded MATLAB Function 'AccelFuse/Jerk_Detection/JerkDetect': '<S24>:1' */
  /* # If "-4 > AccelDeltaBraking <= -0.4" and "VdyAccel > -9.8m/s2"  */
  /* # Jerk = 1 */
  /* # If "AccelDeltaBraking <= -4" */
  /* # Jerk = 2 */
  /* # If and "VdyAccel > -9.8m/s2"  */
  /* # Jerk = 3 */
  /* # else  */
  /* # Jerk = 0 */
  if ((((rtb_Add_j <= -0.4F) && (rtb_WVEL_FL_valid)) && (rtb_Add_j > -4.0F)) &&
      (rtb_EWMA_Sum_i >= -9.8F)) {
    /* '<S24>:1:11' */
    /* '<S24>:1:12' */
    rtb_DataTypeConversion_e = 1U;
  } else if ((rtb_Add_j <= -4.0F) && (rtb_WVEL_FL_valid)) {
    /* '<S24>:1:13' */
    /* '<S24>:1:14' */
    rtb_DataTypeConversion_e = 2U;
  } else if ((rtb_EWMA_Sum_i < -9.8F) && (rtb_WVEL_FL_valid)) {
    /* '<S24>:1:15' */
    /* '<S24>:1:16' */
    rtb_DataTypeConversion_e = 3U;
  } else {
    /* '<S24>:1:18' */
    rtb_DataTypeConversion_e = 0U;
  }

  /* Embedded MATLAB: '<S23>/Wightage' incorporates:
   *  Constant: '<S2>/P_Ramp_Step_G'
   *  Constant: '<S2>/P_Ramp_Step_Normal'
   *  S-Function (ex_sfun_abs): '<S23>/abs_Accel_Delta'
   *  UnitDelay: '<S23>/WeightageDelay'
   */
  /* Embedded MATLAB Function 'AccelFuse/Weightage/Wightage': '<S25>:1' */
  /* #1 => Increase weightage by 0.07 */
  /* #2 => Increase weightage by 10 % of accel delta */
  /* #3 => Increase weightage by 0.1 */
  /* #else => Reduce weightage by 0.07 */
  if (rtb_DataTypeConversion_e == 1) {
    /* '<S25>:1:7' */
    /* '<S25>:1:8' */
    rtb_EWVAR_Right = vdy_ve_DWork->WeightageDelay_DSTATE + 0.07F;
    if (rtb_EWVAR_Right >= 1.0F) {
      /* '<S25>:1:9' */
      /* '<S25>:1:10' */
      rtb_EWVAR_Right = 1.0F;
    }
  } else if (rtb_DataTypeConversion_e == 2) {
    /* '<S25>:1:12' */
    /* '<S25>:1:13' */
    rtb_EWVAR_Right = (CML_f_Abs( (real32_T)rtb_Add_j) * 0.1F) +
      vdy_ve_DWork->WeightageDelay_DSTATE;
    if (rtb_EWVAR_Right >= 1.0F) {
      /* '<S25>:1:14' */
      /* '<S25>:1:15' */
      rtb_EWVAR_Right = 1.0F;
    }
  } else if (rtb_DataTypeConversion_e == 3) {
    /* '<S25>:1:17' */
    /* '<S25>:1:18' */
    rtb_EWVAR_Right = vdy_ve_DWork->WeightageDelay_DSTATE + 0.1F;
    if (rtb_EWVAR_Right >= 1.0F) {
      /* '<S25>:1:19' */
      /* '<S25>:1:20' */
      rtb_EWVAR_Right = 1.0F;
    }
  } else {
    /* '<S25>:1:23' */
    rtb_EWVAR_Right = vdy_ve_DWork->WeightageDelay_DSTATE - 0.07F;
    if (rtb_EWVAR_Right <= 0.0F) {
      /* '<S25>:1:24' */
      /* '<S25>:1:25' */
      rtb_EWVAR_Right = 0.0F;
    }
  }

  /* Outputs for atomic SubSystem: '<Root>/Get_IO_State_ExtAccel' */
  vdy_ve_Get_IO_State_WVEL_FL(rtb_State_h, &vdy_ve_B->Get_IO_State_ExtAccel,
    ((uint32_T)VDY_SIN_POS_VEHACL_EXT));

  /* end of Outputs for SubSystem: '<Root>/Get_IO_State_ExtAccel' */

  /* Switch: '<Root>/Switch' incorporates:
   *  BusAssignment: '<Root>/VdyAccel'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S22>/Constant'
   *  Inport: '<Root>/VDYInputData'
   *  Logic: '<Root>/AND Logical Operator1'
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  RelationalOperator: '<Root>/ABS_state_valid'
   *  Sum: '<S22>/Add'
   *  Sum: '<S22>/Sub'
   */
  if ((((uint32_T)CFG_VDY_FUSE_ACCEL) != 0U) &&
      (vdy_ve_B->Get_IO_State_ExtAccel.IndexVector == 0)) {
    rtb_VdyAccel.vdy_ve_out.veh_accel = ((1.0F - rtb_EWVAR_Right) *
      rtb_EWMA_Sum_i) + ((*vdy_ve_U_VDYInputData).Signals.VehLongAccelExt *
                         rtb_EWVAR_Right);
  } else {
    rtb_VdyAccel.vdy_ve_out.veh_accel = rtb_EWMA_Sum_i;
  }

  /* Outport: '<Root>/VDYInternalData_out' */
  (*vdy_ve_Y_VDYInternalData_out) = rtb_VdyAccel;

  /* Update for UnitDelay: '<S8>/Rate_Limit_Counter' */
  vdy_ve_DWork->Rate_Limit_Counter_DSTATE = rtb_Add;

  /* Update for UnitDelay: '<S68>/x_init_reset' incorporates:
   *  Constant: '<S68>/FixPt Constant'
   */
  vdy_ve_DWork->x_init_reset_DSTATE = 0U;

  /* Update for UnitDelay: '<S68>/x_delay' */
  for (i = 0; i < 2; i++) {
    vdy_ve_DWork->x_delay_DSTATE[(i)] = rtb_Product[i];
  }

  /* Update for UnitDelay: '<S55>/TP_filter_Delay' */
  vdy_ve_DWork->TP_filter_Delay_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S12>/last_veh_velocity' */
  vdy_ve_DWork->last_veh_velocity_DSTATE = rtb_v_out;

  /* Update for UnitDelay: '<S14>/P_delay' */
  for (i = 0; i < 4; i++) {
    vdy_ve_DWork->P_delay_DSTATE[(i)] = rtb_P_post[i];
  }

  /* Update for UnitDelay: '<S82>/TCS_Var_Flag_Init' incorporates:
   *  Constant: '<S82>/Constant'
   */
  vdy_ve_DWork->TCS_Var_Flag_Init_DSTATE = 0U;

  /* Update for UnitDelay: '<S82>/TCS_Var_Flag' */
  vdy_ve_DWork->TCS_Var_Flag_DSTATE = rtb_DataTypeConversion_a;

  /* Update for UnitDelay: '<S82>/Step_Counter_Var' */
  vdy_ve_DWork->Step_Counter_Var_DSTATE = rtb_Switch1;

  /* Update for UnitDelay: '<S73>/FL_var_delay' */
  vdy_ve_DWork->FL_var_delay_DSTATE = vdy_ve_B->FL_R_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S73>/FR_var_delay' */
  vdy_ve_DWork->FR_var_delay_DSTATE = vdy_ve_B->FR_R_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S73>/RL_var_delay' */
  vdy_ve_DWork->RL_var_delay_DSTATE = vdy_ve_B->RL_R_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S73>/RR_var_delay' */
  vdy_ve_DWork->RR_var_delay_DSTATE = vdy_ve_B->RR_R_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S117>/TCS_Vel_Flag_Init' incorporates:
   *  Constant: '<S117>/Constant'
   */
  vdy_ve_DWork->TCS_Vel_Flag_Init_DSTATE = 0U;

  /* Update for UnitDelay: '<S117>/TCS_Vel_Flag' */
  vdy_ve_DWork->TCS_Vel_Flag_DSTATE = rtb_TCS;

  /* Update for UnitDelay: '<S117>/Step_Counter_Vel' */
  vdy_ve_DWork->Step_Counter_Vel_DSTATE = rtb_Switch1_o;

  /* Update for UnitDelay: '<S112>/FL_vel_delay' */
  vdy_ve_DWork->FL_vel_delay_DSTATE = vdy_ve_B->FL_z_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S112>/FR_vel_delay' */
  vdy_ve_DWork->FR_vel_delay_DSTATE = vdy_ve_B->FR_z_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S112>/RL_vel_delay' */
  vdy_ve_DWork->RL_vel_delay_DSTATE = vdy_ve_B->RL_z_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S112>/RR_vel_delay' */
  vdy_ve_DWork->RR_vel_delay_DSTATE = vdy_ve_B->RR_z_step_increment_ve_model.sum;

  /* Update for UnitDelay: '<S52>/Vel_out_delay' */
  vdy_ve_DWork->Vel_out_delay_DSTATE = rtb_DeadZone_FL;

  /* Update for UnitDelay: '<S17>/last_v_var' */
  vdy_ve_DWork->last_v_var_DSTATE = rtb_DeadZone_FR;

  /* Update for UnitDelay: '<S10>/last_a_var' */
  vdy_ve_DWork->last_a_var_DSTATE = rtb_EWMA_Right;

  /* Update for UnitDelay: '<S21>/JerkDetectAccel' */
  vdy_ve_DWork->JerkDetectAccel_DSTATE = rtb_EWMA_Sum_i;

  /* Update for UnitDelay: '<S23>/WeightageDelay' */
  vdy_ve_DWork->WeightageDelay_DSTATE = rtb_EWVAR_Right;
}

/* Model initialize function */
void vdy_ve_initialize(boolean_T firstTime, BlockIO_vdy_ve *vdy_ve_B,
  D_Work_vdy_ve *vdy_ve_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_ve_B), 0,
                      sizeof(BlockIO_vdy_ve));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_ve_DWork, 0,
                      sizeof(D_Work_vdy_ve));

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S68>/x_init_reset' */
    vdy_ve_DWork->x_init_reset_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S14>/P_delay' */
    for (i = 0; i < 4; i++) {
      vdy_ve_DWork->P_delay_DSTATE[(i)] = vdy_ve_P_init_p[(i)];
    }

    /* InitializeConditions for UnitDelay: '<S82>/TCS_Var_Flag_Init' */
    vdy_ve_DWork->TCS_Var_Flag_Init_DSTATE = 1U;

    /* InitializeConditions for atomic SubSystem: '<S15>/check_variance_R_matrix_FL' */
    check_variance_R_matrix_Init(&vdy_ve_DWork->check_variance_R_matrix_FL);

    /* end of InitializeConditions for SubSystem: '<S15>/check_variance_R_matrix_FL' */

    /* InitializeConditions for atomic SubSystem: '<S15>/check_variance_R_matrix_FR' */
    check_variance_R_matrix_Init(&vdy_ve_DWork->check_variance_R_matrix_FR);

    /* end of InitializeConditions for SubSystem: '<S15>/check_variance_R_matrix_FR' */

    /* InitializeConditions for atomic SubSystem: '<S15>/check_variance_R_matrix_RL' */
    check_variance_R_matrix_Init(&vdy_ve_DWork->check_variance_R_matrix_RL);

    /* end of InitializeConditions for SubSystem: '<S15>/check_variance_R_matrix_RL' */

    /* InitializeConditions for atomic SubSystem: '<S15>/check_variance_R_matrix_RR' */
    check_variance_R_matrix_Init(&vdy_ve_DWork->check_variance_R_matrix_RR);

    /* end of InitializeConditions for SubSystem: '<S15>/check_variance_R_matrix_RR' */

    /* InitializeConditions for UnitDelay: '<S117>/TCS_Vel_Flag_Init' */
    vdy_ve_DWork->TCS_Vel_Flag_Init_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S17>/last_v_var' */
    vdy_ve_DWork->last_v_var_DSTATE = 1.0F;

    /* InitializeConditions for UnitDelay: '<S10>/last_a_var' */
    vdy_ve_DWork->last_a_var_DSTATE = 1.0F;
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
