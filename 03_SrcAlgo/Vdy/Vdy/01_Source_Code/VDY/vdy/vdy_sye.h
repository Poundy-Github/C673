/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_sye.h
   Real-Time Workshop code generated for Simulink model vdy_sye.
   Model version                        : 1.3383
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:04:36 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:04:37 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy steering angle yaw rate estimation
   and driver intended curvature estimation
   VERSION:                             : $Revision: 1.8 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_sye_h_
#define RTW_HEADER_vdy_sye_h_
#ifndef vdy_sye_COMMON_INCLUDES_
# define vdy_sye_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_sye_COMMON_INCLUDES_ */

#include "vdy_sye_types.h"

/* Child system includes */
#include "vdy_matrix_inversion_1x1.h"
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

/* Block signals for system '<S13>/make_A_matrix' */
typedef struct {
  real32_T A[4];                       /* '<S13>/make_A_matrix' */
} rtB_make_A_matrix_vdy_sye;

/* Block signals for system '<S2>/Time2Sec' */
typedef struct {
  real32_T Time2Sec;                   /* '<S15>/Time2Sec' */
} rtB_Time2Sec_vdy_sye;

/* Block signals for system '<S17>/get_gain_bias' */
typedef struct {
  real32_T default_diff;               /* '<S17>/get_gain_bias' */
  real32_T gain;                       /* '<S17>/get_gain_bias' */
  real32_T bias;                       /* '<S17>/get_gain_bias' */
} rtB_get_gain_bias_vdy_sye;

/* Block signals for system '<S30>/Get_IO_State1' */
typedef struct {
  uint8_T IndexVector;                 /* '<S35>/Index Vector' */
} rtB_Get_IO_State1_vdy_sye;

/* Block signals for system '<S73>/Get_NVM_IO_State' */
typedef struct {
  uint32_T state;                      /* '<S73>/Get_NVM_IO_State' */
} rtB_Get_NVM_IO_State_vdy_sye;

/* Block signals for system '<S11>/At' */
typedef struct {
  real32_T y[4];                       /* '<S11>/At' */
} rtB_At_vdy_sye;

/* Block signals for system '<S11>/Ht' */
typedef struct {
  real32_T y[2];                       /* '<S11>/Ht' */
} rtB_Ht_vdy_sye;

/* Block signals (auto storage) */
typedef struct {
  rtB_Ht_vdy_sye sf_Ht_d;              /* '<S12>/Ht' */
  rtB_vdy_matrix_inversion_1x1 sf_Matrix_Inversion_1x1;/* '<S106>/Matrix_Inversion_1x1' */
  rtB_At_vdy_sye sf_At_d;              /* '<S12>/At' */
  rtB_Ht_vdy_sye sf_Ht_k;              /* '<S11>/Ht' */
  rtB_vdy_matrix_inversion_1x1 sf_Matrix_Inversion_1x1_a;/* '<S95>/Matrix_Inversion_1x1' */
  rtB_At_vdy_sye sf_At_dl;             /* '<S11>/At' */
  rtB_Get_NVM_IO_State_vdy_sye sf_Get_NVM_IO_State;/* '<S92>/Get_NVM_IO_State' */
  rtB_vdy_matrix_inversion_2x2 sf_Matrix_Inversion_2x2;/* '<S78>/Matrix_Inversion_2x2' */
  rtB_Time2Sec_vdy_sye Time2Sec_i;     /* '<S9>/Time2Sec' */
  rtB_Get_NVM_IO_State_vdy_sye sf_Get_NVM_IO_State_g;/* '<S73>/Get_NVM_IO_State' */
  rtB_Get_IO_State1_vdy_sye Get_IO_State2_k;/* '<S45>/Get_IO_State2' */
  rtB_get_gain_bias_vdy_sye sf_get_gain_bias;/* '<S54>/get_gain_bias' */
  rtB_Time2Sec_vdy_sye Time2Sec_b;     /* '<S44>/Time2Sec' */
  rtB_make_A_matrix_vdy_sye sf_make_A_matrix_i;/* '<S51>/make_A_matrix' */
  rtB_Get_IO_State1_vdy_sye Get_IO_State2;/* '<S28>/Get_IO_State2' */
  rtB_Time2Sec_vdy_sye Time2Sec;       /* '<S26>/Time2Sec' */
  rtB_Get_IO_State1_vdy_sye Get_IO_State1;/* '<S30>/Get_IO_State1' */
  rtB_get_gain_bias_vdy_sye sf_get_gain_bias_k;/* '<S17>/get_gain_bias' */
  rtB_Time2Sec_vdy_sye Time2Sec_f;     /* '<S2>/Time2Sec' */
  rtB_make_A_matrix_vdy_sye sf_make_A_matrix_d;/* '<S13>/make_A_matrix' */
} BlockIO_vdy_sye;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T x_delay_eg_DSTATE[3];       /* '<S10>/x_delay_eg' */
  real32_T T3_DSTATE;                  /* '<S37>/T3' */
  real32_T T2_DSTATE;                  /* '<S37>/T2' */
  real32_T T1_DSTATE;                  /* '<S37>/T1' */
  real32_T T0_DSTATE;                  /* '<S37>/T0' */
  real32_T T7_DSTATE;                  /* '<S37>/T7' */
  real32_T T6_DSTATE;                  /* '<S37>/T6' */
  real32_T T5_DSTATE;                  /* '<S37>/T5' */
  real32_T T4_DSTATE;                  /* '<S37>/T4' */
  real32_T P_delay_eg_DSTATE[9];       /* '<S10>/P_delay_eg' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S75>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_b;   /* '<S76>/FixPt Unit Delay1' */
  real32_T FixPtUnitDelay1_DSTATE_g;   /* '<S70>/FixPt Unit Delay1' */
  real32_T last_SlfStGradDisc_DSTATE;  /* '<S9>/last_SlfStGradDisc' */
  real32_T x_delay_yaw_DSTATE[2];      /* '<S12>/x_delay_yaw' */
  real32_T T3_DSTATE_c;                /* '<S58>/T3' */
  real32_T T2_DSTATE_f;                /* '<S58>/T2' */
  real32_T T1_DSTATE_k;                /* '<S58>/T1' */
  real32_T T0_DSTATE_f;                /* '<S58>/T0' */
  real32_T P_delay_yaw_DSTATE[4];      /* '<S12>/P_delay_yaw' */
  real32_T last_not_zero_min_DSTATE;   /* '<S43>/last_not_zero_min' */
  real32_T last_steering_angle_DSTATE; /* '<S43>/last_steering_angle' */
  real32_T FixPtUnitDelay1_DSTATE_l;   /* '<S50>/FixPt Unit Delay1' */
  real32_T x_delay_curve_DSTATE[2];    /* '<S11>/x_delay_curve' */
  real32_T T3_DSTATE_f;                /* '<S23>/T3' */
  real32_T T2_DSTATE_e;                /* '<S23>/T2' */
  real32_T T1_DSTATE_h;                /* '<S23>/T1' */
  real32_T T0_DSTATE_l;                /* '<S23>/T0' */
  real32_T P_delay_curve_DSTATE[4];    /* '<S11>/P_delay_curve' */
  uint8_T init_nvm_eg_delay_DSTATE;    /* '<S10>/init_nvm_eg_delay' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S70>/FixPt Unit Delay2' */
  boolean_T trav_dist_reset_DSTATE;    /* '<S9>/trav_dist_reset' */
} D_Work_vdy_sye;

/* Model entry point functions */
extern void vdy_sye_initialize(boolean_T firstTime, BlockIO_vdy_sye *vdy_sye_B,
  D_Work_vdy_sye *vdy_sye_DWork);
extern void vdy_sye_step(BlockIO_vdy_sye *vdy_sye_B, D_Work_vdy_sye
  *vdy_sye_DWork, VDYInputData_t *vdy_sye_U_VDYInputData, VDYInternalData_t
  *vdy_sye_U_VDYInternalData_in, VDYNvData_t *vdy_sye_U_VDYNVData_in, uint16_T
  vdy_sye_U_vdy_ctrl_op_mode, VDYInternalData_t *vdy_sye_Y_VDYInternalData_out,
  VDYNvData_t *vdy_sye_Y_VDYNVData_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_sye_I_SSG_matrix_p[9];
extern const real32_T vdy_sye_I_di_matrix_p[4];
extern const real32_T vdy_sye_I_matrix_p[4];
extern const real32_T vdy_sye_K_SSG_default_p[6];
extern const real32_T vdy_sye_K_default_p[2];
extern const real32_T vdy_sye_K_di_default_p[2];
extern const real32_T vdy_sye_P_SSG_init_p[9];
extern const real32_T vdy_sye_P_correct_p[4];
extern const real32_T vdy_sye_P_di_init_p[4];
extern const real32_T vdy_sye_P_init_p[4];
extern const real32_T vdy_sye_Q_SSG_range_p[5];
extern const real32_T vdy_sye_Q_SSG_sigmas_p[2];
extern const real32_T vdy_sye_Q_add_p[4];
extern const real32_T vdy_sye_Q_di_add_p[4];
extern const real32_T vdy_sye_Q_di_gain_p[3];
extern const real32_T vdy_sye_Q_di_sigmas_p[2];
extern const real32_T vdy_sye_Q_di_sigmas_velo_gain_p[4];
extern const real32_T vdy_sye_Q_gain_p[3];
extern const real32_T vdy_sye_Q_sigmas_p[2];
extern const real32_T vdy_sye_R_SSG_p[4];
extern const real32_T vdy_sye_R_p[2];
extern const real32_T vdy_sye_x_SSG_init_p[3];
extern const real32_T vdy_sye_x_di_init_p[2];
extern const real32_T vdy_sye_x_init_p[2];

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
 * '<Root>' : vdy_sye
 * '<S1>'   : vdy_sye/Model Info1
 * '<S2>'   : vdy_sye/Q_A_addpation_curve
 * '<S3>'   : vdy_sye/R
 * '<S4>'   : vdy_sye/build_EG_Q_R_A_z
 * '<S5>'   : vdy_sye/build_Q_R_A_z
 * '<S6>'   : vdy_sye/correct_yaw_rate
 * '<S7>'   : vdy_sye/diag_curve_variance
 * '<S8>'   : vdy_sye/diag_yaw_variance
 * '<S9>'   : vdy_sye/extract_understeer_grad
 * '<S10>'  : vdy_sye/swa_EG_EKF
 * '<S11>'  : vdy_sye/swa_curve_EKF
 * '<S12>'  : vdy_sye/swa_yaw_EKF
 * '<S13>'  : vdy_sye/Q_A_addpation_curve/A
 * '<S14>'  : vdy_sye/Q_A_addpation_curve/Q
 * '<S15>'  : vdy_sye/Q_A_addpation_curve/Time2Sec
 * '<S16>'  : vdy_sye/Q_A_addpation_curve/divide
 * '<S17>'  : vdy_sye/Q_A_addpation_curve/q_gain
 * '<S18>'  : vdy_sye/Q_A_addpation_curve/A/make_A_matrix
 * '<S19>'  : vdy_sye/Q_A_addpation_curve/Q/gain_sigmas_over_velocity
 * '<S20>'  : vdy_sye/Q_A_addpation_curve/Q/makeQ
 * '<S21>'  : vdy_sye/Q_A_addpation_curve/Q/gain_sigmas_over_velocity/sigma_velocity_gain_controll
 * '<S22>'  : vdy_sye/Q_A_addpation_curve/q_gain/get_gain_bias
 * '<S23>'  : vdy_sye/Q_A_addpation_curve/q_gain/mean_filt_yaw_rate
 * '<S24>'  : vdy_sye/Q_A_addpation_curve/q_gain/q_gain_delta
 * '<S25>'  : vdy_sye/R/adapt_R_matrix
 * '<S26>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve
 * '<S27>'  : vdy_sye/build_EG_Q_R_A_z/make_R
 * '<S28>'  : vdy_sye/build_EG_Q_R_A_z/make_z_vektor
 * '<S29>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/A
 * '<S30>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Build_EG_State
 * '<S31>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Q
 * '<S32>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Time2Sec
 * '<S33>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/get_bit
 * '<S34>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/A/make_A_matrix
 * '<S35>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Build_EG_State/Get_IO_State1
 * '<S36>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Build_EG_State/controll_ssg_noice
 * '<S37>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Build_EG_State/mean_filt_yaw_rate
 * '<S38>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/Q/makeQ
 * '<S39>'  : vdy_sye/build_EG_Q_R_A_z/Q_A_adapation_curve/get_bit/get_bit
 * '<S40>'  : vdy_sye/build_EG_Q_R_A_z/make_R/adapt_R_matrix
 * '<S41>'  : vdy_sye/build_EG_Q_R_A_z/make_z_vektor/Get_IO_State2
 * '<S42>'  : vdy_sye/build_EG_Q_R_A_z/make_z_vektor/make_z_vector
 * '<S43>'  : vdy_sye/build_Q_R_A_z/CaculateAddVar
 * '<S44>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw
 * '<S45>'  : vdy_sye/build_Q_R_A_z/make_z_vektor
 * '<S46>'  : vdy_sye/build_Q_R_A_z/CaculateAddVar/AddVariance
 * '<S47>'  : vdy_sye/build_Q_R_A_z/CaculateAddVar/MinMax Running Resettable
 * '<S48>'  : vdy_sye/build_Q_R_A_z/CaculateAddVar/check_for_zero_values
 * '<S49>'  : vdy_sye/build_Q_R_A_z/CaculateAddVar/get_init_control_mode
 * '<S50>'  : vdy_sye/build_Q_R_A_z/CaculateAddVar/MinMax Running Resettable/Unit Delay With Preview Resettable
 * '<S51>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/A
 * '<S52>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/Q
 * '<S53>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/Time2Sec
 * '<S54>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/q_gain
 * '<S55>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/A/make_A_matrix
 * '<S56>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/Q/makeQ
 * '<S57>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/q_gain/get_gain_bias
 * '<S58>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/q_gain/mean_filt_yaw_rate
 * '<S59>'  : vdy_sye/build_Q_R_A_z/Q_A_adaptation_yaw/q_gain/q_gain_delta
 * '<S60>'  : vdy_sye/build_Q_R_A_z/make_z_vektor/Get_IO_State2
 * '<S61>'  : vdy_sye/build_Q_R_A_z/make_z_vektor/make_z_vector
 * '<S62>'  : vdy_sye/extract_understeer_grad/Get_IO_State3
 * '<S63>'  : vdy_sye/extract_understeer_grad/Get_SlfStGrad_IO_State
 * '<S64>'  : vdy_sye/extract_understeer_grad/Max_EG
 * '<S65>'  : vdy_sye/extract_understeer_grad/Min_EG
 * '<S66>'  : vdy_sye/extract_understeer_grad/Time2Sec
 * '<S67>'  : vdy_sye/extract_understeer_grad/check_with_read_values
 * '<S68>'  : vdy_sye/extract_understeer_grad/diag_EG
 * '<S69>'  : vdy_sye/extract_understeer_grad/get_init_control_mode
 * '<S70>'  : vdy_sye/extract_understeer_grad/last_trav_dist
 * '<S71>'  : vdy_sye/extract_understeer_grad/Get_IO_State3/GetIOState
 * '<S72>'  : vdy_sye/extract_understeer_grad/Get_IO_State3/GetIOState/Get_IO_State
 * '<S73>'  : vdy_sye/extract_understeer_grad/Get_SlfStGrad_IO_State/GetIOState
 * '<S74>'  : vdy_sye/extract_understeer_grad/Get_SlfStGrad_IO_State/GetIOState/Get_NVM_IO_State
 * '<S75>'  : vdy_sye/extract_understeer_grad/Max_EG/Unit Delay With Preview Resettable
 * '<S76>'  : vdy_sye/extract_understeer_grad/Min_EG/Unit Delay With Preview Resettable
 * '<S77>'  : vdy_sye/swa_EG_EKF/At
 * '<S78>'  : vdy_sye/swa_EG_EKF/Calculate Kalman gain PHt_(HPHt_R)
 * '<S79>'  : vdy_sye/swa_EG_EKF/Get_SlfStGrad_IO_State
 * '<S80>'  : vdy_sye/swa_EG_EKF/Ht
 * '<S81>'  : vdy_sye/swa_EG_EKF/Range check of the SSG
 * '<S82>'  : vdy_sye/swa_EG_EKF/Reset_P_pred
 * '<S83>'  : vdy_sye/swa_EG_EKF/Reset_x_pred
 * '<S84>'  : vdy_sye/swa_EG_EKF/check_eg
 * '<S85>'  : vdy_sye/swa_EG_EKF/check_init_state
 * '<S86>'  : vdy_sye/swa_EG_EKF/hx
 * '<S87>'  : vdy_sye/swa_EG_EKF/vdy_s-func_APAt
 * '<S88>'  : vdy_sye/swa_EG_EKF/vdy_s-func_HPHt
 * '<S89>'  : vdy_sye/swa_EG_EKF/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S90>'  : vdy_sye/swa_EG_EKF/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S91>'  : vdy_sye/swa_EG_EKF/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S92>'  : vdy_sye/swa_EG_EKF/Get_SlfStGrad_IO_State/GetIOState
 * '<S93>'  : vdy_sye/swa_EG_EKF/Get_SlfStGrad_IO_State/GetIOState/Get_NVM_IO_State
 * '<S94>'  : vdy_sye/swa_curve_EKF/At
 * '<S95>'  : vdy_sye/swa_curve_EKF/Calculate Kalman gain PHt_(HPHt_R)1
 * '<S96>'  : vdy_sye/swa_curve_EKF/Ht
 * '<S97>'  : vdy_sye/swa_curve_EKF/Reset_P_pred
 * '<S98>'  : vdy_sye/swa_curve_EKF/Reset_x_pred
 * '<S99>'  : vdy_sye/swa_curve_EKF/hx
 * '<S100>' : vdy_sye/swa_curve_EKF/vdy_s-func_APAt
 * '<S101>' : vdy_sye/swa_curve_EKF/vdy_s-func_HPHt
 * '<S102>' : vdy_sye/swa_curve_EKF/Calculate Kalman gain PHt_(HPHt_R)1/Matrix_Inversion_1x1
 * '<S103>' : vdy_sye/swa_curve_EKF/Calculate Kalman gain PHt_(HPHt_R)1/calculate the gain
 * '<S104>' : vdy_sye/swa_curve_EKF/Calculate Kalman gain PHt_(HPHt_R)1/set gain to default value
 * '<S105>' : vdy_sye/swa_yaw_EKF/At
 * '<S106>' : vdy_sye/swa_yaw_EKF/Calculate Kalman gain PHt_(HPHt_R)
 * '<S107>' : vdy_sye/swa_yaw_EKF/Ht
 * '<S108>' : vdy_sye/swa_yaw_EKF/Reset_P_pred
 * '<S109>' : vdy_sye/swa_yaw_EKF/Reset_x_pred
 * '<S110>' : vdy_sye/swa_yaw_EKF/hx1
 * '<S111>' : vdy_sye/swa_yaw_EKF/make_z
 * '<S112>' : vdy_sye/swa_yaw_EKF/vdy_s-func_APAt
 * '<S113>' : vdy_sye/swa_yaw_EKF/vdy_s-func_HPHt
 * '<S114>' : vdy_sye/swa_yaw_EKF/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_1x1
 * '<S115>' : vdy_sye/swa_yaw_EKF/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S116>' : vdy_sye/swa_yaw_EKF/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 */
#endif                                 /* RTW_HEADER_vdy_sye_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
