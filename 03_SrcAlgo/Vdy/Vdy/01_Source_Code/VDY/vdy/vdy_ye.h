/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_ye.h
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
   VERSION:                             : $Revision: 1.8 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_ye_h_
#define RTW_HEADER_vdy_ye_h_
#ifndef vdy_ye_COMMON_INCLUDES_
# define vdy_ye_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_ye_COMMON_INCLUDES_ */

#include "vdy_ye_types.h"

/* Child system includes */
#include "vdy_matrix_inversion_2x2.h"
#include "vdy_matrix_inversion_4x4.h"

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

/* Block signals for system '<Root>/Get_IO_State1' */
typedef struct {
  uint8_T IndexVector;                 /* '<S1>/Index Vector' */
} rtB_Get_IO_State1_vdy_ye;

/* Block signals for system '<S3>/diag_variance' */
typedef struct {
  real32_T y[4];                       /* '<S3>/diag_variance' */
} rtB_diag_variance_vdy_ye;

/* Block signals for system '<S7>/At' */
typedef struct {
  real32_T y[4];                       /* '<S7>/At' */
} rtB_At_vdy_ye;

/* Block signals for system '<Root>/diag_curve_variance' */
typedef struct {
  real32_T y[2];                       /* '<Root>/diag_curve_variance' */
} rtB_diag_curve_variance_vdy_ye;

/* Block signals for system '<S38>/make_A_matrix' */
typedef struct {
  real32_T A[4];                       /* '<S38>/make_A_matrix' */
} rtB_make_A_matrix_vdy_ye;

/* Block signals (auto storage) */
typedef struct {
  real32_T Divide;                     /* '<S40>/Divide' */
  rtB_diag_variance_vdy_ye sf_diag_R_i;/* '<S16>/diag_R' */
  rtB_Get_IO_State1_vdy_ye Get_IO_State1;/* '<S16>/Get_IO_State1' */
  rtB_vdy_matrix_inversion_4x4 sf_Matrix_Inversion_4x4;/* '<S70>/Matrix_Inversion_4x4' */
  rtB_At_vdy_ye sf_At;                 /* '<S15>/At' */
  rtB_make_A_matrix_vdy_ye sf_make_A_matrix;/* '<S53>/make_A_matrix' */
  rtB_make_A_matrix_vdy_ye sf_make_A_matrix_l;/* '<S38>/make_A_matrix' */
  rtB_diag_curve_variance_vdy_ye sf_diag_yaw_variance;/* '<Root>/diag_yaw_variance' */
  rtB_diag_curve_variance_vdy_ye sf_diag_curve_variance;/* '<Root>/diag_curve_variance' */
  rtB_At_vdy_ye sf_Ht_k;               /* '<S7>/Ht' */
  rtB_vdy_matrix_inversion_2x2 sf_Matrix_Inversion_2x2;/* '<S27>/Matrix_Inversion_2x2' */
  rtB_At_vdy_ye sf_At_i;               /* '<S7>/At' */
  rtB_diag_variance_vdy_ye sf_diag_variance;/* '<S3>/diag_variance' */
  rtB_Get_IO_State1_vdy_ye Get_IO_State1_o;/* '<Root>/Get_IO_State1' */
} BlockIO_vdy_ye;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T UD_DSTATE;                  /* '<S17>/UD' */
  real32_T x_delay_DSTATE[2];          /* '<S15>/x_delay' */
  real32_T UnitDelay_DSTATE;           /* '<S56>/Unit Delay' */
  real32_T T3_DSTATE;                  /* '<S60>/T3' */
  real32_T T2_DSTATE;                  /* '<S60>/T2' */
  real32_T T1_DSTATE;                  /* '<S60>/T1' */
  real32_T T0_DSTATE;                  /* '<S60>/T0' */
  real32_T P_delay_DSTATE[4];          /* '<S15>/P_delay' */
  real32_T UD_DSTATE_m;                /* '<S18>/UD' */
  real32_T UD_DSTATE_h;                /* '<S20>/UD' */
  real32_T UD_DSTATE_j;                /* '<S19>/UD' */
  real32_T UD_DSTATE_hz;               /* '<S66>/UD' */
  real32_T x_delay_DSTATE_k[2];        /* '<S7>/x_delay' */
  real32_T delay_DSTATE;               /* '<S40>/delay' */
  real32_T ramp_factor_DSTATE;         /* '<S12>/ramp_factor' */
  real32_T last_yaw_rate_curve_DSTATE; /* '<S12>/last_yaw_rate_curve' */
  real32_T UD_DSTATE_i;                /* '<S45>/UD' */
  real32_T WeightedMovingAverage_TapDelayU[7];/* '<S40>/Weighted Moving Average' */
  real32_T UnitDelay_DSTATE_j;         /* '<S48>/Unit Delay' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S52>/FixPt Unit Delay1' */
  real32_T hold_value_DSTATE;          /* '<S46>/hold_value' */
  real32_T P_delay_DSTATE_l[4];        /* '<S7>/P_delay' */
  uint8_T hold_counter_DSTATE;         /* '<S12>/hold_counter' */
  uint8_T ramp_counter_DSTATE;         /* '<S12>/ramp_counter' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S52>/FixPt Unit Delay2' */
  uint8_T hold_counter_DSTATE_e;       /* '<S46>/hold_counter' */
} D_Work_vdy_ye;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: mgainval
   * Referenced by: '<S40>/Weighted Moving Average'
   */
  real32_T WeightedMovingAverage[8];
} ConstParam_vdy_ye;

/* Constant parameters (auto storage) */
extern const ConstParam_vdy_ye vdy_ye_ConstP;

/* Model entry point functions */
extern void vdy_ye_initialize(boolean_T firstTime, BlockIO_vdy_ye *vdy_ye_B,
  D_Work_vdy_ye *vdy_ye_DWork);
extern void vdy_ye_step(BlockIO_vdy_ye *vdy_ye_B, D_Work_vdy_ye *vdy_ye_DWork,
  VDYInputData_t *vdy_ye_U_VDYInputData, VDYInternalData_t
  *vdy_ye_U_VDYInternalData_in, VDYInternalData_t *vdy_ye_Y_VDYInternalData_out,
  real32_T vdy_ye_Y_K_yaw[8], uint8_T *vdy_ye_Y_K_yaw_fault, real32_T
  vdy_ye_Y_K_curve[4], uint8_T *vdy_ye_Y_K_curve_fault);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_yaw_rate_var_tune_p;
extern const real32_T vdy_ye_I_matrix_yaw_p[4];
extern const real32_T vdy_ye_K_curve_default_p[4];
extern const real32_T vdy_ye_K_yaw_default_p[8];
extern const real32_T vdy_ye_P_curve_init_p[4];
extern const real32_T vdy_ye_P_init_p[4];
extern const real32_T vdy_ye_Q_add_p[4];
extern const real32_T vdy_ye_Q_curve_gain_p;
extern const real32_T vdy_ye_Q_gain_p[4];
extern const real32_T vdy_ye_Q_sigmas_curve_p[2];
extern const real32_T vdy_ye_Q_sigmas_p[2];
extern const real32_T vdy_ye_Q_sigmas_velo_gain_p[4];
extern const real32_T vdy_ye_R_curve_p[3];
extern const real32_T vdy_ye_mahala_para_p[9];
extern const real32_T vdy_ye_x_curve_init_p[2];
extern const real32_T vdy_ye_x_init_p[2];
extern const uint8_T vdy_ye_yaw_curve_ramp_para_p[2];

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
 * '<Root>' : vdy_ye
 * '<S1>'   : vdy_ye/Get_IO_State1
 * '<S2>'   : vdy_ye/Model Info
 * '<S3>'   : vdy_ye/R
 * '<S4>'   : vdy_ye/Time2Sec
 * '<S5>'   : vdy_ye/TuneYawRateVar
 * '<S6>'   : vdy_ye/calc_lat_accel´
 * '<S7>'   : vdy_ye/curve_KF
 * '<S8>'   : vdy_ye/diag_curve_variance
 * '<S9>'   : vdy_ye/diag_yaw_variance
 * '<S10>'  : vdy_ye/make_A_Q_curve
 * '<S11>'  : vdy_ye/make_A_Q_yaw
 * '<S12>'  : vdy_ye/make_crv_z_vektor_R
 * '<S13>'  : vdy_ye/make_z_vektor
 * '<S14>'  : vdy_ye/vdy_yaw_select
 * '<S15>'  : vdy_ye/yaw_KF
 * '<S16>'  : vdy_ye/yaw_rate_usage
 * '<S17>'  : vdy_ye/R/Transfer Fcn First Order
 * '<S18>'  : vdy_ye/R/Transfer Fcn First Order1
 * '<S19>'  : vdy_ye/R/Transfer Fcn First Order2
 * '<S20>'  : vdy_ye/R/Transfer Fcn First Order3
 * '<S21>'  : vdy_ye/R/change_new_R_values
 * '<S22>'  : vdy_ye/R/diag_R
 * '<S23>'  : vdy_ye/R/diag_variance
 * '<S24>'  : vdy_ye/R/meas_matrix_adj1
 * '<S25>'  : vdy_ye/TuneYawRateVar/check_stat_and_quality
 * '<S26>'  : vdy_ye/curve_KF/At
 * '<S27>'  : vdy_ye/curve_KF/Calculate Kalman gain
 * '<S28>'  : vdy_ye/curve_KF/Ht
 * '<S29>'  : vdy_ye/curve_KF/Reset_P_pred
 * '<S30>'  : vdy_ye/curve_KF/Reset_x_pred
 * '<S31>'  : vdy_ye/curve_KF/eye
 * '<S32>'  : vdy_ye/curve_KF/hx
 * '<S33>'  : vdy_ye/curve_KF/vdy_s-func_APAt
 * '<S34>'  : vdy_ye/curve_KF/vdy_s-func_HPHt
 * '<S35>'  : vdy_ye/curve_KF/Calculate Kalman gain/Matrix_Inversion_2x2
 * '<S36>'  : vdy_ye/curve_KF/Calculate Kalman gain/calculate the gain
 * '<S37>'  : vdy_ye/curve_KF/Calculate Kalman gain/set gain to default value
 * '<S38>'  : vdy_ye/make_A_Q_curve/A
 * '<S39>'  : vdy_ye/make_A_Q_curve/Q
 * '<S40>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain
 * '<S41>'  : vdy_ye/make_A_Q_curve/A/make_A_matrix
 * '<S42>'  : vdy_ye/make_A_Q_curve/Q/gain_sigmas_over_velocity
 * '<S43>'  : vdy_ye/make_A_Q_curve/Q/makeQ
 * '<S44>'  : vdy_ye/make_A_Q_curve/Q/gain_sigmas_over_velocity/sigma_velocity_gain_controll
 * '<S45>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/Difference
 * '<S46>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/hold_last_5_values
 * '<S47>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/threshold_gain
 * '<S48>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/tp_filter_peaks1
 * '<S49>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/hold_last_5_values/hold_last_5_values
 * '<S50>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/tp_filter_peaks1/check_reset_condition
 * '<S51>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/tp_filter_peaks1/tp_filter
 * '<S52>'  : vdy_ye/make_A_Q_curve/calculate_Q_gain/tp_filter_peaks1/tp_filter/Unit Delay Resettable External IC
 * '<S53>'  : vdy_ye/make_A_Q_yaw/A
 * '<S54>'  : vdy_ye/make_A_Q_yaw/Q
 * '<S55>'  : vdy_ye/make_A_Q_yaw/mean
 * '<S56>'  : vdy_ye/make_A_Q_yaw/q_gain
 * '<S57>'  : vdy_ye/make_A_Q_yaw/A/make_A_matrix
 * '<S58>'  : vdy_ye/make_A_Q_yaw/Q/makeQ
 * '<S59>'  : vdy_ye/make_A_Q_yaw/q_gain/get_gain_bias
 * '<S60>'  : vdy_ye/make_A_Q_yaw/q_gain/mean_filter_yaw_rate
 * '<S61>'  : vdy_ye/make_A_Q_yaw/q_gain/q_gain_delta
 * '<S62>'  : vdy_ye/make_A_Q_yaw/q_gain/threshold_diff
 * '<S63>'  : vdy_ye/make_crv_z_vektor_R/Divide
 * '<S64>'  : vdy_ye/make_crv_z_vektor_R/divide_yaw_rate
 * '<S65>'  : vdy_ye/make_crv_z_vektor_R/make_R
 * '<S66>'  : vdy_ye/make_crv_z_vektor_R/yaw_rate_var_filter
 * '<S67>'  : vdy_ye/make_crv_z_vektor_R/Divide/Divide
 * '<S68>'  : vdy_ye/make_z_vektor/build_z_vector
 * '<S69>'  : vdy_ye/yaw_KF/At
 * '<S70>'  : vdy_ye/yaw_KF/Calculate Kalman gain
 * '<S71>'  : vdy_ye/yaw_KF/Ht
 * '<S72>'  : vdy_ye/yaw_KF/Reset_P_pred
 * '<S73>'  : vdy_ye/yaw_KF/Reset_x_pred
 * '<S74>'  : vdy_ye/yaw_KF/hx
 * '<S75>'  : vdy_ye/yaw_KF/vdy_s-func_APAt
 * '<S76>'  : vdy_ye/yaw_KF/vdy_s-func_HPHt
 * '<S77>'  : vdy_ye/yaw_KF/Calculate Kalman gain/Matrix_Inversion_4x4
 * '<S78>'  : vdy_ye/yaw_KF/Calculate Kalman gain/calculate the gain
 * '<S79>'  : vdy_ye/yaw_KF/Calculate Kalman gain/set gain to default value
 * '<S80>'  : vdy_ye/yaw_rate_usage/Get_IO_State1
 * '<S81>'  : vdy_ye/yaw_rate_usage/diag_R
 * '<S82>'  : vdy_ye/yaw_rate_usage/mean_var
 * '<S83>'  : vdy_ye/yaw_rate_usage/norm_usage
 */
#endif                                 /* RTW_HEADER_vdy_ye_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
