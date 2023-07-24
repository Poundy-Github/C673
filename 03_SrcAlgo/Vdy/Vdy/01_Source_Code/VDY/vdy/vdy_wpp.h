/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_wpp.h
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
#ifndef RTW_HEADER_vdy_wpp_h_
#define RTW_HEADER_vdy_wpp_h_
#ifndef vdy_wpp_COMMON_INCLUDES_
# define vdy_wpp_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_wpp_COMMON_INCLUDES_ */

#include "vdy_wpp_types.h"

/* Child system includes */
#include "vdy_matrix_inversion_2x2.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

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

/* Block signals for system '<Root>/Get_IO_State_WTCKS_FL' */
typedef struct {
  uint8_T IndexVector;                 /* '<S1>/Index Vector' */
} rtB_Get_IO_State_WTCKS_FL_vdy_w;

/* Block signals for system '<Root>/front_left_wheel_speed_fusion' */
typedef struct {
  real32_T y;                          /* '<S36>/velocity' */
  real32_T y_g;                        /* '<S36>/limit_accel' */
  real32_T corrected_wheel_velocity_uncert;/* '<S35>/correct_estimated_ws_uncertainty' */
  rtB_vdy_matrix_inversion_2x2 sf_Matrix_Inversion_2x2;/* '<S64>/Matrix_Inversion_2x2' */
} rtB_wheel_speed_fusion;

/* Block states (auto storage) for system '<Root>/front_left_wheel_speed_fusion' */
typedef struct {
  real32_T FixPtUnitDelay1_DSTATE[2];  /* '<S70>/FixPt Unit Delay1' */
  real32_T th_Delay_DSTATE;            /* '<S79>/1th_Delay' */
  real32_T th_Delay_DSTATE_b;          /* '<S79>/2th_Delay' */
  real32_T th_Delay_DSTATE_f;          /* '<S79>/3th_Delay' */
  real32_T th_Delay_DSTATE_o;          /* '<S79>/4th_Delay' */
  real32_T th_Delay1_DSTATE;           /* '<S79>/1th_Delay1' */
  real32_T th_Delay1_DSTATE_f;         /* '<S79>/2th_Delay1' */
  real32_T th_Delay1_DSTATE_j;         /* '<S79>/3th_Delay1' */
  real32_T puls_speed_delay_DSTATE;    /* '<S37>/puls_speed_delay' */
  real32_T counter_delay_DSTATE;       /* '<S37>/counter_delay' */
  real32_T m_delay_DSTATE;             /* '<S37>/m_delay' */
  real32_T single_puls_velocity_delay_DSTA;/* '<S37>/single_puls_velocity_delay' */
  real32_T T3_DSTATE;                  /* '<S76>/T3' */
  real32_T T2_DSTATE;                  /* '<S76>/T2' */
  real32_T T1_DSTATE;                  /* '<S76>/T1' */
  real32_T T0_DSTATE;                  /* '<S76>/T0' */
  real32_T UnitDelay_DSTATE;           /* '<S58>/Unit Delay' */
  real32_T P_delay_DSTATE[4];          /* '<S56>/P_delay' */
  real32_T FixPtUnitDelay1_DSTATE_e;   /* '<S41>/FixPt Unit Delay1' */
  real32_T last_accel_corr_DSTATE;     /* '<S39>/last_accel_corr' */
  real32_T last_accel_corr_step_DSTATE;/* '<S39>/last_accel_corr_step' */
  real32_T last_accel_corr_max_DSTATE; /* '<S39>/last_accel_corr_max' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S70>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_o;    /* '<S41>/FixPt Unit Delay2' */
  boolean_T init_delay_DSTATE;         /* '<S37>/init_delay' */
} rtDW_wheel_speed_fusion;

/* Block signals (auto storage) */
typedef struct {
  rtB_wheel_speed_fusion rear_right_wheel_speed_fusion;/* '<Root>/rear_right_wheel_speed_fusion' */
  rtB_wheel_speed_fusion rear_left_wheel_speed_fusion;/* '<Root>/rear_left_wheel_speed_fusion' */
  rtB_wheel_speed_fusion front_right_wheel_speed_fusion;/* '<Root>/front_right_wheel_speed_fusion' */
  rtB_wheel_speed_fusion front_left_wheel_speed_fusion;/* '<Root>/front_left_wheel_speed_fusion' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WVEL_RR;/* '<Root>/Get_IO_State_WVEL_RR' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WVEL_RL;/* '<Root>/Get_IO_State_WVEL_RL' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WVEL_FR;/* '<Root>/Get_IO_State_WVEL_FR' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WVEL_FL;/* '<Root>/Get_IO_State_WVEL_FL' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WTCKS_RR;/* '<Root>/Get_IO_State_WTCKS_RR' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WTCKS_RL;/* '<Root>/Get_IO_State_WTCKS_RL' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WTCKS_FR;/* '<Root>/Get_IO_State_WTCKS_FR' */
  rtB_Get_IO_State_WTCKS_FL_vdy_w Get_IO_State_WTCKS_FL;/* '<Root>/Get_IO_State_WTCKS_FL' */
} BlockIO_vdy_wpp;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T FL_aqua_slip_state_delay_DSTATE;/* '<S29>/FL_aqua_slip_state_delay' */
  real32_T FR_aqua_slip_state_delay_DSTATE;/* '<S30>/FR_aqua_slip_state_delay' */
  real32_T RL_aqua_slip_state_delay_DSTATE;/* '<S31>/RL_aqua_slip_state_delay' */
  real32_T RR_aqua_slip_state_delay_DSTATE;/* '<S32>/RR_aqua_slip_state_delay' */
  rtDW_wheel_speed_fusion rear_right_wheel_speed_fusion;/* '<Root>/rear_right_wheel_speed_fusion' */
  rtDW_wheel_speed_fusion rear_left_wheel_speed_fusion;/* '<Root>/rear_left_wheel_speed_fusion' */
  rtDW_wheel_speed_fusion front_right_wheel_speed_fusion;/* '<Root>/front_right_wheel_speed_fusion' */
  rtDW_wheel_speed_fusion front_left_wheel_speed_fusion;/* '<Root>/front_left_wheel_speed_fusion' */
} D_Work_vdy_wpp;

/* Model entry point functions */
extern void vdy_wpp_initialize(boolean_T firstTime, BlockIO_vdy_wpp *vdy_wpp_B,
  D_Work_vdy_wpp *vdy_wpp_DWork);
extern void vdy_wpp_step(BlockIO_vdy_wpp *vdy_wpp_B, D_Work_vdy_wpp
  *vdy_wpp_DWork, VDYInputData_t *vdy_wpp_U_VDYInputData, VDYInternalData_t
  *vdy_wpp_U_VDYInternalData, VDYInternalData_t *vdy_wpp_Y_VDYInternalData_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_wpp_H_p[4];
extern const real32_T vdy_wpp_I_matrix_p[4];
extern const real32_T vdy_wpp_K_default_p[4];
extern const real32_T vdy_wpp_P_correct_p[6];
extern const real32_T vdy_wpp_P_init_p[4];
extern const real32_T vdy_wpp_Q_gain_p[8];
extern const real32_T vdy_wpp_Q_sigmas_p[2];
extern const real32_T vdy_wpp_R_p[4];
extern const real32_T vdy_wpp_accel_correct_p;
extern const real32_T vdy_wpp_aqua_slip_correct_p[2];
extern const real32_T vdy_wpp_puls_velocity_para_p[4];
extern const real32_T vdy_wpp_x_init_p;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : vdy_wpp
 * '<S1>'   : vdy_wpp/Get_IO_State_WTCKS_FL
 * '<S2>'   : vdy_wpp/Get_IO_State_WTCKS_FR
 * '<S3>'   : vdy_wpp/Get_IO_State_WTCKS_RL
 * '<S4>'   : vdy_wpp/Get_IO_State_WTCKS_RR
 * '<S5>'   : vdy_wpp/Get_IO_State_WVEL_FL
 * '<S6>'   : vdy_wpp/Get_IO_State_WVEL_FR
 * '<S7>'   : vdy_wpp/Get_IO_State_WVEL_RL
 * '<S8>'   : vdy_wpp/Get_IO_State_WVEL_RR
 * '<S9>'   : vdy_wpp/Model Info
 * '<S10>'  : vdy_wpp/Time2Sec
 * '<S11>'  : vdy_wpp/aqua_slip_correction
 * '<S12>'  : vdy_wpp/aqua_slip_state_output
 * '<S13>'  : vdy_wpp/front_left_wheel_speed_fusion
 * '<S14>'  : vdy_wpp/front_right_wheel_speed_fusion
 * '<S15>'  : vdy_wpp/rear_left_wheel_speed_fusion
 * '<S16>'  : vdy_wpp/rear_right_wheel_speed_fusion
 * '<S17>'  : vdy_wpp/aqua_slip_correction/four_wheel_mean
 * '<S18>'  : vdy_wpp/aqua_slip_correction/left_right_correction_fusion
 * '<S19>'  : vdy_wpp/aqua_slip_correction/left_side_aqua_slip_correction
 * '<S20>'  : vdy_wpp/aqua_slip_correction/right_side_aqua_slip_correction
 * '<S21>'  : vdy_wpp/aqua_slip_correction/left_side_aqua_slip_correction/calc_factor
 * '<S22>'  : vdy_wpp/aqua_slip_correction/left_side_aqua_slip_correction/left_side_aqua_slip_correction
 * '<S23>'  : vdy_wpp/aqua_slip_correction/left_side_aqua_slip_correction/calc_factor/left_side_aqua_slip_correction1
 * '<S24>'  : vdy_wpp/aqua_slip_correction/left_side_aqua_slip_correction/calc_factor/left_side_aqua_slip_correction2
 * '<S25>'  : vdy_wpp/aqua_slip_correction/right_side_aqua_slip_correction/calc_factor
 * '<S26>'  : vdy_wpp/aqua_slip_correction/right_side_aqua_slip_correction/right_side_aqua_slip_crrection_org
 * '<S27>'  : vdy_wpp/aqua_slip_correction/right_side_aqua_slip_correction/calc_factor/right_side_aqua_slip_correction_exp
 * '<S28>'  : vdy_wpp/aqua_slip_correction/right_side_aqua_slip_correction/calc_factor/right_side_aqua_slip_correction_factors
 * '<S29>'  : vdy_wpp/aqua_slip_state_output/Transfer Fcn First Order
 * '<S30>'  : vdy_wpp/aqua_slip_state_output/Transfer Fcn First Order1
 * '<S31>'  : vdy_wpp/aqua_slip_state_output/Transfer Fcn First Order2
 * '<S32>'  : vdy_wpp/aqua_slip_state_output/Transfer Fcn First Order3
 * '<S33>'  : vdy_wpp/aqua_slip_state_output/threshold_aqua_slip_state
 * '<S34>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction
 * '<S35>'  : vdy_wpp/front_left_wheel_speed_fusion/correct_wheel_uncertainty
 * '<S36>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion
 * '<S37>'  : vdy_wpp/front_left_wheel_speed_fusion/wheel_pulses_to_speed
 * '<S38>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel
 * '<S39>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration
 * '<S40>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/divide
 * '<S41>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay
 * '<S42>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant
 * '<S43>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant1
 * '<S44>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant2
 * '<S45>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant3
 * '<S46>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant4
 * '<S47>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/accel_peak_filter
 * '<S48>'  : vdy_wpp/front_left_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/calc_exponent
 * '<S49>'  : vdy_wpp/front_left_wheel_speed_fusion/correct_wheel_uncertainty/calc_exponent
 * '<S50>'  : vdy_wpp/front_left_wheel_speed_fusion/correct_wheel_uncertainty/correct_estimated_ws_uncertainty
 * '<S51>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/A
 * '<S52>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/Q
 * '<S53>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance
 * '<S54>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/diag_P
 * '<S55>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/if_else_use_wheel_pulse
 * '<S56>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter
 * '<S57>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/limit_accel
 * '<S58>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain
 * '<S59>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/velocity
 * '<S60>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/A/make_A_matrix
 * '<S61>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/Q/makeQ
 * '<S62>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_R
 * '<S63>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_exponent
 * '<S64>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)
 * '<S65>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_P_pred
 * '<S66>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_x_pred
 * '<S67>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/hx
 * '<S68>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_APAt
 * '<S69>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_HPHt
 * '<S70>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/x_delay
 * '<S71>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S72>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S73>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S74>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/Embedded MATLAB Function
 * '<S75>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/get_gain_bias
 * '<S76>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/mean_filt_velocity
 * '<S77>'  : vdy_wpp/front_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/q_gain_delta
 * '<S78>'  : vdy_wpp/front_left_wheel_speed_fusion/wheel_pulses_to_speed/init_wheel_pulse
 * '<S79>'  : vdy_wpp/front_left_wheel_speed_fusion/wheel_pulses_to_speed/mean_filter
 * '<S80>'  : vdy_wpp/front_left_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity
 * '<S81>'  : vdy_wpp/front_left_wheel_speed_fusion/wheel_pulses_to_speed/puls_velocity_pre_processing
 * '<S82>'  : vdy_wpp/front_left_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity/divide
 * '<S83>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction
 * '<S84>'  : vdy_wpp/front_right_wheel_speed_fusion/correct_wheel_uncertainty
 * '<S85>'  : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion
 * '<S86>'  : vdy_wpp/front_right_wheel_speed_fusion/wheel_pulses_to_speed
 * '<S87>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel
 * '<S88>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration
 * '<S89>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/divide
 * '<S90>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay
 * '<S91>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant
 * '<S92>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant1
 * '<S93>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant2
 * '<S94>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant3
 * '<S95>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant4
 * '<S96>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/accel_peak_filter
 * '<S97>'  : vdy_wpp/front_right_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/calc_exponent
 * '<S98>'  : vdy_wpp/front_right_wheel_speed_fusion/correct_wheel_uncertainty/calc_exponent
 * '<S99>'  : vdy_wpp/front_right_wheel_speed_fusion/correct_wheel_uncertainty/correct_estimated_ws_uncertainty
 * '<S100>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/A
 * '<S101>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/Q
 * '<S102>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance
 * '<S103>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/diag_P
 * '<S104>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/if_else_use_wheel_pulse
 * '<S105>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter
 * '<S106>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/limit_accel
 * '<S107>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain
 * '<S108>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/velocity
 * '<S109>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/A/make_A_matrix
 * '<S110>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/Q/makeQ
 * '<S111>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_R
 * '<S112>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_exponent
 * '<S113>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)
 * '<S114>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_P_pred
 * '<S115>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_x_pred
 * '<S116>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/hx
 * '<S117>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_APAt
 * '<S118>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_HPHt
 * '<S119>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/x_delay
 * '<S120>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S121>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S122>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S123>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/Embedded MATLAB Function
 * '<S124>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/get_gain_bias
 * '<S125>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/mean_filt_velocity
 * '<S126>' : vdy_wpp/front_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/q_gain_delta
 * '<S127>' : vdy_wpp/front_right_wheel_speed_fusion/wheel_pulses_to_speed/init_wheel_pulse
 * '<S128>' : vdy_wpp/front_right_wheel_speed_fusion/wheel_pulses_to_speed/mean_filter
 * '<S129>' : vdy_wpp/front_right_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity
 * '<S130>' : vdy_wpp/front_right_wheel_speed_fusion/wheel_pulses_to_speed/puls_velocity_pre_processing
 * '<S131>' : vdy_wpp/front_right_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity/divide
 * '<S132>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction
 * '<S133>' : vdy_wpp/rear_left_wheel_speed_fusion/correct_wheel_uncertainty
 * '<S134>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion
 * '<S135>' : vdy_wpp/rear_left_wheel_speed_fusion/wheel_pulses_to_speed
 * '<S136>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel
 * '<S137>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration
 * '<S138>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/divide
 * '<S139>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay
 * '<S140>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant
 * '<S141>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant1
 * '<S142>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant2
 * '<S143>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant3
 * '<S144>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant4
 * '<S145>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/accel_peak_filter
 * '<S146>' : vdy_wpp/rear_left_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/calc_exponent
 * '<S147>' : vdy_wpp/rear_left_wheel_speed_fusion/correct_wheel_uncertainty/calc_exponent
 * '<S148>' : vdy_wpp/rear_left_wheel_speed_fusion/correct_wheel_uncertainty/correct_estimated_ws_uncertainty
 * '<S149>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/A
 * '<S150>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/Q
 * '<S151>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance
 * '<S152>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/diag_P
 * '<S153>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/if_else_use_wheel_pulse
 * '<S154>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter
 * '<S155>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/limit_accel
 * '<S156>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain
 * '<S157>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/velocity
 * '<S158>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/A/make_A_matrix
 * '<S159>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/Q/makeQ
 * '<S160>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_R
 * '<S161>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_exponent
 * '<S162>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)
 * '<S163>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_P_pred
 * '<S164>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_x_pred
 * '<S165>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/hx
 * '<S166>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_APAt
 * '<S167>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_HPHt
 * '<S168>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/x_delay
 * '<S169>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S170>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S171>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S172>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/Embedded MATLAB Function
 * '<S173>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/get_gain_bias
 * '<S174>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/mean_filt_velocity
 * '<S175>' : vdy_wpp/rear_left_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/q_gain_delta
 * '<S176>' : vdy_wpp/rear_left_wheel_speed_fusion/wheel_pulses_to_speed/init_wheel_pulse
 * '<S177>' : vdy_wpp/rear_left_wheel_speed_fusion/wheel_pulses_to_speed/mean_filter
 * '<S178>' : vdy_wpp/rear_left_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity
 * '<S179>' : vdy_wpp/rear_left_wheel_speed_fusion/wheel_pulses_to_speed/puls_velocity_pre_processing
 * '<S180>' : vdy_wpp/rear_left_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity/divide
 * '<S181>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction
 * '<S182>' : vdy_wpp/rear_right_wheel_speed_fusion/correct_wheel_uncertainty
 * '<S183>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion
 * '<S184>' : vdy_wpp/rear_right_wheel_speed_fusion/wheel_pulses_to_speed
 * '<S185>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel
 * '<S186>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration
 * '<S187>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/divide
 * '<S188>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay
 * '<S189>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant
 * '<S190>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant1
 * '<S191>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant2
 * '<S192>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant3
 * '<S193>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/calc_abs_accel/x_delay/Compare To Constant4
 * '<S194>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/accel_peak_filter
 * '<S195>' : vdy_wpp/rear_right_wheel_speed_fusion/acceleration_correction/peak_filter_abs_acceleration/calc_exponent
 * '<S196>' : vdy_wpp/rear_right_wheel_speed_fusion/correct_wheel_uncertainty/calc_exponent
 * '<S197>' : vdy_wpp/rear_right_wheel_speed_fusion/correct_wheel_uncertainty/correct_estimated_ws_uncertainty
 * '<S198>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/A
 * '<S199>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/Q
 * '<S200>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance
 * '<S201>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/diag_P
 * '<S202>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/if_else_use_wheel_pulse
 * '<S203>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter
 * '<S204>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/limit_accel
 * '<S205>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain
 * '<S206>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/velocity
 * '<S207>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/A/make_A_matrix
 * '<S208>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/Q/makeQ
 * '<S209>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_R
 * '<S210>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/calc_wheel_velocity_R_variance/calc_exponent
 * '<S211>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)
 * '<S212>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_P_pred
 * '<S213>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Reset_x_pred
 * '<S214>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/hx
 * '<S215>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_APAt
 * '<S216>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/vdy_s-func_HPHt
 * '<S217>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/x_delay
 * '<S218>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S219>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S220>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/kalman_filter/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S221>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/Embedded MATLAB Function
 * '<S222>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/get_gain_bias
 * '<S223>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/mean_filt_velocity
 * '<S224>' : vdy_wpp/rear_right_wheel_speed_fusion/puls_wheel_velocity_fusion/q_gain/q_gain_delta
 * '<S225>' : vdy_wpp/rear_right_wheel_speed_fusion/wheel_pulses_to_speed/init_wheel_pulse
 * '<S226>' : vdy_wpp/rear_right_wheel_speed_fusion/wheel_pulses_to_speed/mean_filter
 * '<S227>' : vdy_wpp/rear_right_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity
 * '<S228>' : vdy_wpp/rear_right_wheel_speed_fusion/wheel_pulses_to_speed/puls_velocity_pre_processing
 * '<S229>' : vdy_wpp/rear_right_wheel_speed_fusion/wheel_pulses_to_speed/puls_to_velocity/divide
 */
#endif                                 /* RTW_HEADER_vdy_wpp_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
