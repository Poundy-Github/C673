/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_wye.h
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
   VERSION:                             : $Revision: 1.8 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_wye_h_
#define RTW_HEADER_vdy_wye_h_
#ifndef vdy_wye_COMMON_INCLUDES_
# define vdy_wye_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_wye_COMMON_INCLUDES_ */

#include "vdy_wye_types.h"

/* Child system includes */
#include "vdy_matrix_inversion_2x2.h"
#include "vdy_matrix_inversion_3x3.h"

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

/* Block signals for system '<S51>/Get_NVM_IO_State' */
typedef struct {
  uint32_T state;                      /* '<S51>/Get_NVM_IO_State' */
} rtB_Get_NVM_IO_State_vdy_wye;

/* Block signals for system '<S35>/Time2Sec' */
typedef struct {
  real32_T Time2Sec;                   /* '<S59>/Time2Sec' */
} rtB_Time2Sec_vdy_wye;

/* Block signals for system '<S66>/make_A_matrix' */
typedef struct {
  real32_T A[9];                       /* '<S66>/make_A_matrix' */
} rtB_make_A_matrix_vdy_wye;

/* Block signals for system '<S70>/get_bit' */
typedef struct {
  uint16_T y;                          /* '<S70>/get_bit' */
} rtB_get_bit_vdy_wye;

/* Block signals for system '<S11>/Get_IO_State' */
typedef struct {
  uint8_T IndexVector;                 /* '<S103>/Index Vector' */
} rtB_Get_IO_State_vdy_wye;

/* Block signals (auto storage) */
typedef struct {
  rtB_Get_IO_State_vdy_wye Get_IO_State1;/* '<S11>/Get_IO_State1' */
  rtB_Get_IO_State_vdy_wye Get_IO_State;/* '<S11>/Get_IO_State' */
  rtB_Time2Sec_vdy_wye Time2Sec_d;     /* '<S10>/Time2Sec' */
  rtB_get_bit_vdy_wye sf_get_bit_i;    /* '<S84>/get_bit' */
  rtB_Time2Sec_vdy_wye Time2Sec_l;     /* '<S9>/Time2Sec' */
  rtB_make_A_matrix_vdy_wye sf_make_A_matrix_d;/* '<S80>/make_A_matrix' */
  rtB_get_bit_vdy_wye sf_get_bit;      /* '<S70>/get_bit' */
  rtB_Time2Sec_vdy_wye Time2Sec;       /* '<S37>/Time2Sec' */
  rtB_make_A_matrix_vdy_wye sf_make_A_matrix;/* '<S66>/make_A_matrix' */
  rtB_Time2Sec_vdy_wye Time2Sec_n;     /* '<S35>/Time2Sec' */
  rtB_Get_NVM_IO_State_vdy_wye sf_Get_NVM_IO_State_k;/* '<S64>/Get_NVM_IO_State' */
  rtB_Get_NVM_IO_State_vdy_wye sf_Get_NVM_IO_State;/* '<S51>/Get_NVM_IO_State' */
  rtB_vdy_matrix_inversion_2x2 sf_Matrix_Inversion_2x2;/* '<S38>/Matrix_Inversion_2x2' */
  rtB_vdy_matrix_inversion_2x2 sf_Matrix_Inversion_2x2_c;/* '<S25>/Matrix_Inversion_2x2' */
  rtB_vdy_matrix_inversion_3x3 sf_Matrix_Inversion_3x3;/* '<S14>/Matrix_Inversion_3x3' */
} BlockIO_vdy_wye;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T UD_DSTATE;                  /* '<S55>/UD' */
  real32_T UD_DSTATE_a;                /* '<S56>/UD' */
  real32_T last_est_wld_DSTATE;        /* '<S8>/last_est_wld' */
  real32_T x_delay_wld_DSTATE[3];      /* '<S33>/x_delay_wld' */
  real32_T UD_DSTATE_b;                /* '<S76>/UD' */
  real32_T P_delay_wld_DSTATE[9];      /* '<S33>/P_delay_wld' */
  real32_T P_delay_dyn_off_DSTATE[9];  /* '<S2>/P_delay_dyn_off' */
  real32_T x_delay_dyn_off_DSTATE[3];  /* '<S2>/x_delay_dyn_off' */
  real32_T last_dyn_yaw_offset_DSTATE; /* '<S1>/last_dyn_yaw_offset' */
  real32_T dyn_yaw_off_overt_count_DSTATE;/* '<S1>/dyn_yaw_off_overt_count' */
  real32_T whl_yaw_off_control_DSTATE; /* '<S93>/whl_yaw_off_control' */
  real32_T diff_raw_whl_est_whl_yaw_DSTATE;/* '<S10>/diff_raw_whl_est_whl_yaw' */
  real32_T T3_DSTATE;                  /* '<S96>/T3' */
  real32_T T2_DSTATE;                  /* '<S96>/T2' */
  real32_T T1_DSTATE;                  /* '<S96>/T1' */
  real32_T T0_DSTATE;                  /* '<S96>/T0' */
  real32_T last_est_whl_yaw_rate_DSTATE;/* '<S10>/last_est_whl_yaw_rate' */
  real32_T P_delay_whl_yaw_DSTATE[4];  /* '<S3>/P_delay_whl_yaw' */
  real32_T x_delay_whl_yaw_DSTATE[2];  /* '<S3>/x_delay_whl_yaw' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S61>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_d;   /* '<S102>/FixPt Unit Delay1' */
  int8_T last_dyn_yaw_offset_sign_DSTATE;/* '<S1>/last_dyn_yaw_offset_sign' */
  uint8_T init_nvm_wld_delay_DSTATE;   /* '<S33>/init_nvm_wld_delay' */
  uint8_T hold_value_DSTATE;           /* '<S77>/hold_value' */
  uint8_T hold_counter_DSTATE;         /* '<S77>/hold_counter' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S61>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_h;    /* '<S102>/FixPt Unit Delay2' */
  boolean_T trav_dist_reset_DSTATE;    /* '<S35>/trav_dist_reset' */
} D_Work_vdy_wye;

/* Model entry point functions */
extern void vdy_wye_initialize(boolean_T firstTime, BlockIO_vdy_wye *vdy_wye_B,
  D_Work_vdy_wye *vdy_wye_DWork);
extern void vdy_wye_step(BlockIO_vdy_wye *vdy_wye_B, D_Work_vdy_wye
  *vdy_wye_DWork, VDYInputData_t *vdy_wye_U_VDYInputData, VDYInternalData_t
  *vdy_wye_U_VDYInternalData_in, VDYNvData_t *vdy_wye_U_VDYNvData_in,
  VDYInternalData_t *vdy_wye_Y_VDYInternalData_out, VDYNvData_t
  *vdy_wye_Y_VDYNVData_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_wye_H_p[9];
extern const real32_T vdy_wye_H_yaw_p[4];
extern const real32_T vdy_wye_I_matrix_p[9];
extern const real32_T vdy_wye_I_matrix_wld_p[9];
extern const real32_T vdy_wye_I_matrix_yaw_p[4];
extern const real32_T vdy_wye_K_default_p[9];
extern const real32_T vdy_wye_K_wld_default_p[6];
extern const real32_T vdy_wye_K_yaw_default_p[4];
extern const real32_T vdy_wye_P_correct_p[4];
extern const real32_T vdy_wye_P_init_p[9];
extern const real32_T vdy_wye_P_init_wld_p[9];
extern const real32_T vdy_wye_Q_gain_p[3];
extern const real32_T vdy_wye_Q_gain_wld_p[3];
extern const real32_T vdy_wye_Q_sigmas_dyn_off_p[5];
extern const real32_T vdy_wye_Q_sigmas_dyn_off_wld_p;
extern const real32_T vdy_wye_Q_sigmas_p[3];
extern const real32_T vdy_wye_Q_sigmas_wld_p[3];
extern const real32_T vdy_wye_R_control_p;
extern const real32_T vdy_wye_R_p[9];
extern const real32_T vdy_wye_R_wld_p[4];
extern const real32_T vdy_wye_x_init_p[3];
extern const real32_T vdy_wye_x_init_wld_p[3];
extern const real32_T vdy_wye_yaw_P_correct_p[5];
extern const real32_T vdy_wye_yaw_P_init_p[4];
extern const real32_T vdy_wye_yaw_Q_gain_p[3];
extern const real32_T vdy_wye_yaw_Q_sigmas_p[2];
extern const real32_T vdy_wye_yaw_R_p[4];
extern const real32_T vdy_wye_yaw_offset_const_p[2];
extern const real32_T vdy_wye_yaw_x_init_p[2];

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
 * '<Root>' : vdy_wye
 * '<S1>'   : vdy_wye/Check_yaw_offset
 * '<S2>'   : vdy_wye/KF
 * '<S3>'   : vdy_wye/KF_whl_yaw
 * '<S4>'   : vdy_wye/Model Info
 * '<S5>'   : vdy_wye/correct_variance
 * '<S6>'   : vdy_wye/correct_variance1
 * '<S7>'   : vdy_wye/correct_yaw_rate
 * '<S8>'   : vdy_wye/estimate_wheel_load_dep_front
 * '<S9>'   : vdy_wye/make_A_Q_R
 * '<S10>'  : vdy_wye/make_whl_yaw_A_Q_R
 * '<S11>'  : vdy_wye/make_z_vektor
 * '<S12>'  : vdy_wye/Check_yaw_offset/check_yaw_offset
 * '<S13>'  : vdy_wye/Check_yaw_offset/init_x_yaw
 * '<S14>'  : vdy_wye/KF/Calculate Kalman gain PHt_(HPHt_R)
 * '<S15>'  : vdy_wye/KF/Reset_P_pred
 * '<S16>'  : vdy_wye/KF/Reset_x_pred
 * '<S17>'  : vdy_wye/KF/check_yaw_offset
 * '<S18>'  : vdy_wye/KF/init_P_yaw
 * '<S19>'  : vdy_wye/KF/init_x_yaw
 * '<S20>'  : vdy_wye/KF/vdy_s-func_APAt
 * '<S21>'  : vdy_wye/KF/vdy_s-func_HPHt
 * '<S22>'  : vdy_wye/KF/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_3x3
 * '<S23>'  : vdy_wye/KF/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S24>'  : vdy_wye/KF/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S25>'  : vdy_wye/KF_whl_yaw/Calculate Kalman gain PHt_(HPHt_R)
 * '<S26>'  : vdy_wye/KF_whl_yaw/Reset_P_pred
 * '<S27>'  : vdy_wye/KF_whl_yaw/Reset_x_pred
 * '<S28>'  : vdy_wye/KF_whl_yaw/vdy_s-func_APAt
 * '<S29>'  : vdy_wye/KF_whl_yaw/vdy_s-func_HPHt
 * '<S30>'  : vdy_wye/KF_whl_yaw/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S31>'  : vdy_wye/KF_whl_yaw/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S32>'  : vdy_wye/KF_whl_yaw/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S33>'  : vdy_wye/estimate_wheel_load_dep_front/EKF
 * '<S34>'  : vdy_wye/estimate_wheel_load_dep_front/calc_yaw_front_rear
 * '<S35>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save
 * '<S36>'  : vdy_wye/estimate_wheel_load_dep_front/diff_front_rear
 * '<S37>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1
 * '<S38>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Calculate Kalman gain PHt_(HPHt_R)
 * '<S39>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Get_WhlLoad_IO_State
 * '<S40>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Reset_P_pred
 * '<S41>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Reset_x_pred
 * '<S42>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/check_init_state
 * '<S43>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/hx
 * '<S44>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/init_x_yaw
 * '<S45>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/init_x_yaw1
 * '<S46>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/vdy_s-func_APAt
 * '<S47>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/vdy_s-func_HPHt
 * '<S48>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S49>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S50>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S51>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Get_WhlLoad_IO_State/GetIOState
 * '<S52>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/Get_WhlLoad_IO_State/GetIOState/Get_NVM_IO_State
 * '<S53>'  : vdy_wye/estimate_wheel_load_dep_front/EKF/hx/hx_func
 * '<S54>'  : vdy_wye/estimate_wheel_load_dep_front/calc_yaw_front_rear/calc_fr_re_yaw
 * '<S55>'  : vdy_wye/estimate_wheel_load_dep_front/calc_yaw_front_rear/filter_front_axle_diff
 * '<S56>'  : vdy_wye/estimate_wheel_load_dep_front/calc_yaw_front_rear/filter_rear_axle_diff
 * '<S57>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_IO_State3
 * '<S58>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_WhlLoad_IO_State
 * '<S59>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Time2Sec
 * '<S60>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/check_with_read_values
 * '<S61>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/last_trav_dist
 * '<S62>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_IO_State3/GetIOState
 * '<S63>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_IO_State3/GetIOState/Get_IO_State
 * '<S64>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_WhlLoad_IO_State/GetIOState
 * '<S65>'  : vdy_wye/estimate_wheel_load_dep_front/check_wld_for_nv_save/Get_WhlLoad_IO_State/GetIOState/Get_NVM_IO_State
 * '<S66>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/A
 * '<S67>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/Q
 * '<S68>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/R
 * '<S69>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/Time2Sec
 * '<S70>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/get_bit1
 * '<S71>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/get_gain_bias
 * '<S72>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/q_gain_delta
 * '<S73>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/A/make_A_matrix
 * '<S74>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/Q/makeQ
 * '<S75>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/R/adapt_R_matrix
 * '<S76>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/R/filter_rear_whl_diff
 * '<S77>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/R/hold_last_10_values
 * '<S78>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/R/hold_last_10_values/hold_last_10_values
 * '<S79>'  : vdy_wye/estimate_wheel_load_dep_front/make_A_Q_R1/get_bit1/get_bit
 * '<S80>'  : vdy_wye/make_A_Q_R/A
 * '<S81>'  : vdy_wye/make_A_Q_R/Q
 * '<S82>'  : vdy_wye/make_A_Q_R/R
 * '<S83>'  : vdy_wye/make_A_Q_R/Time2Sec
 * '<S84>'  : vdy_wye/make_A_Q_R/get_bit1
 * '<S85>'  : vdy_wye/make_A_Q_R/get_gain_bias
 * '<S86>'  : vdy_wye/make_A_Q_R/q_gain_delta
 * '<S87>'  : vdy_wye/make_A_Q_R/A/make_A_matrix
 * '<S88>'  : vdy_wye/make_A_Q_R/Q/makeQ
 * '<S89>'  : vdy_wye/make_A_Q_R/R/adapt_R_matrix
 * '<S90>'  : vdy_wye/make_A_Q_R/get_bit1/get_bit
 * '<S91>'  : vdy_wye/make_whl_yaw_A_Q_R/A
 * '<S92>'  : vdy_wye/make_whl_yaw_A_Q_R/Q
 * '<S93>'  : vdy_wye/make_whl_yaw_A_Q_R/R
 * '<S94>'  : vdy_wye/make_whl_yaw_A_Q_R/Time2Sec
 * '<S95>'  : vdy_wye/make_whl_yaw_A_Q_R/get_gain_bias
 * '<S96>'  : vdy_wye/make_whl_yaw_A_Q_R/mean_filt_yaw_rate
 * '<S97>'  : vdy_wye/make_whl_yaw_A_Q_R/q_gain_delta
 * '<S98>'  : vdy_wye/make_whl_yaw_A_Q_R/A/make_A_matrix
 * '<S99>'  : vdy_wye/make_whl_yaw_A_Q_R/Q/makeQ
 * '<S100>' : vdy_wye/make_whl_yaw_A_Q_R/R/adapt_R_matrix
 * '<S101>' : vdy_wye/make_whl_yaw_A_Q_R/R/filter_whl_yaw_off_control
 * '<S102>' : vdy_wye/make_whl_yaw_A_Q_R/R/filter_whl_yaw_off_control/reset_init_filter
 * '<S103>' : vdy_wye/make_z_vektor/Get_IO_State
 * '<S104>' : vdy_wye/make_z_vektor/Get_IO_State1
 * '<S105>' : vdy_wye/make_z_vektor/R_yaw_valid
 * '<S106>' : vdy_wye/make_z_vektor/divide_front_whl
 * '<S107>' : vdy_wye/make_z_vektor/divide_rear_whl
 */
#endif                                 /* RTW_HEADER_vdy_wye_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
