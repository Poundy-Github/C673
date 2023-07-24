/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_ve.h
   Real-Time Workshop code generated for Simulink model vdy_ve.
   Model version                        : 1.1259
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:00:55 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:00:56 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy velocity and acceleration
   estimation, merge the four wheel speeds
   VERSION:                             : $Revision: 1.8 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_ve_h_
#define RTW_HEADER_vdy_ve_h_
#ifndef vdy_ve_COMMON_INCLUDES_
# define vdy_ve_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_ve_COMMON_INCLUDES_ */

#include "vdy_ve_types.h"

/* Child system includes */
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

/* Block signals for system '<S28>/Get_IO_State_ABS' */
typedef struct {
  uint8_T IndexVector;                 /* '<S31>/Index Vector' */
} rtB_Get_IO_State_ABS_vdy_ve;

/* Block signals for system '<S28>/Get_IO_State_WVEL_FL' */
typedef struct {
  uint8_T IndexVector;                 /* '<S32>/Index Vector' */
} rtB_Get_IO_State_WVEL_FL_vdy_ve;

/* Block signals for system '<S39>/whl_vel_std_dev_function' */
typedef struct {
  real32_T flag_vel;                   /* '<S39>/whl_vel_std_dev_function' */
} rtB_whl_vel_std_dev_function_vd;

/* Block signals for system '<S73>/FL_R_step_increment_ve_model' */
typedef struct {
  real32_T sum;                        /* '<S80>/sum' */
} rtB_step_increment_ve_model;

/* Block states (auto storage) for system '<S73>/FL_R_step_increment_ve_model' */
typedef struct {
  real32_T FL_latched_velvar_DSTATE;   /* '<S85>/FL_latched_vel//var' */
} rtDW_step_increment_ve_model;

/* Block states (auto storage) for system '<S15>/check_variance_R_matrix_FL' */
typedef struct {
  real32_T FL_filt_var_DSTATE;         /* '<S90>/FL_filt_var' */
  real32_T FL_init_value_DSTATE;       /* '<S93>/FL_init_value' */
  uint8_T FL_ext_reset_DSTATE;         /* '<S75>/FL_ext_reset' */
  uint8_T FL_init_reset_DSTATE;        /* '<S93>/FL_init_reset' */
} rtDW_check_variance_R_matrix;

/* Block signals (auto storage) */
typedef struct {
  rtB_step_increment_ve_model RR_z_step_increment_ve_model;/* '<S112>/RR_z_step_increment_ve_model' */
  rtB_step_increment_ve_model RL_z_step_increment_ve_model;/* '<S112>/RL_z_step_increment_ve_model' */
  rtB_step_increment_ve_model FR_z_step_increment_ve_model;/* '<S112>/FR_z_step_increment_ve_model' */
  rtB_step_increment_ve_model FL_z_step_increment_ve_model;/* '<S112>/FL_z_step_increment_ve_model' */
  rtB_step_increment_ve_model RR_R_step_increment_ve_model;/* '<S73>/RR_R_step_increment_ve_model' */
  rtB_step_increment_ve_model RL_R_step_increment_ve_model;/* '<S73>/RL_R_step_increment_ve_model' */
  rtB_step_increment_ve_model FR_R_step_increment_ve_model;/* '<S73>/FR_R_step_increment_ve_model' */
  rtB_step_increment_ve_model FL_R_step_increment_ve_model;/* '<S73>/FL_R_step_increment_ve_model' */
  rtB_vdy_matrix_inversion_4x4 sf_Matrix_Inversion_4x4;/* '<S61>/Matrix_Inversion_4x4' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WTCKS_RR;/* '<S13>/Get_IO_State_WTCKS_RR' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WTCKS_RL;/* '<S13>/Get_IO_State_WTCKS_RL' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WTCKS_FR;/* '<S13>/Get_IO_State_WTCKS_FR' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WTCKS_FL;/* '<S13>/Get_IO_State_WTCKS_FL' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_VEHACL_EXT;/* '<S7>/Get_IO_State_VEHACL_EXT' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_ExtAccel;/* '<Root>/Get_IO_State_ExtAccel' */
  rtB_Get_IO_State_ABS_vdy_ve Get_IO_State_ABS_p;/* '<S47>/Get_IO_State_ABS' */
  rtB_Get_IO_State_ABS_vdy_ve Get_IO_State_TCS;/* '<S27>/Get_IO_State_TCS' */
  rtB_whl_vel_std_dev_function_vd sf_whl_accel_function;/* '<S40>/whl_accel_function' */
  rtB_whl_vel_std_dev_function_vd sf_whl_vel_std_dev_function;/* '<S39>/whl_vel_std_dev_function' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WVEL_RR;/* '<S28>/Get_IO_State_WVEL_RR' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WVEL_RL;/* '<S28>/Get_IO_State_WVEL_RL' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WVEL_FR;/* '<S28>/Get_IO_State_WVEL_FR' */
  rtB_Get_IO_State_WVEL_FL_vdy_ve Get_IO_State_WVEL_FL;/* '<S28>/Get_IO_State_WVEL_FL' */
  rtB_Get_IO_State_ABS_vdy_ve Get_IO_State_ABS;/* '<S28>/Get_IO_State_ABS' */
} BlockIO_vdy_ve;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Rate_Limit_Counter_DSTATE;  /* '<S8>/Rate_Limit_Counter' */
  real32_T x_delay_DSTATE[2];          /* '<S68>/x_delay' */
  real32_T TP_filter_Delay_DSTATE;     /* '<S55>/TP_filter_Delay' */
  real32_T last_veh_velocity_DSTATE;   /* '<S12>/last_veh_velocity' */
  real32_T P_delay_DSTATE[4];          /* '<S14>/P_delay' */
  real32_T FL_var_delay_DSTATE;        /* '<S73>/FL_var_delay' */
  real32_T FR_var_delay_DSTATE;        /* '<S73>/FR_var_delay' */
  real32_T RL_var_delay_DSTATE;        /* '<S73>/RL_var_delay' */
  real32_T RR_var_delay_DSTATE;        /* '<S73>/RR_var_delay' */
  real32_T FL_vel_delay_DSTATE;        /* '<S112>/FL_vel_delay' */
  real32_T FR_vel_delay_DSTATE;        /* '<S112>/FR_vel_delay' */
  real32_T RL_vel_delay_DSTATE;        /* '<S112>/RL_vel_delay' */
  real32_T RR_vel_delay_DSTATE;        /* '<S112>/RR_vel_delay' */
  real32_T Vel_out_delay_DSTATE;       /* '<S52>/Vel_out_delay' */
  real32_T last_v_var_DSTATE;          /* '<S17>/last_v_var' */
  real32_T last_a_var_DSTATE;          /* '<S10>/last_a_var' */
  real32_T JerkDetectAccel_DSTATE;     /* '<S21>/JerkDetectAccel' */
  real32_T WeightageDelay_DSTATE;      /* '<S23>/WeightageDelay' */
  real32_T Accel_Counter_DSTATE;       /* '<S40>/Accel_Counter' */
  real32_T EWMA_Left_DSTATE;           /* '<S42>/EWMA_Left' */
  real32_T EWVAR_Left_DSTATE;          /* '<S42>/EWVAR_Left' */
  real32_T EWMA_Right_DSTATE;          /* '<S43>/EWMA_Right' */
  real32_T EWVAR_Right_DSTATE;         /* '<S43>/EWVAR_Right' */
  real32_T SD_Counter_DSTATE;          /* '<S39>/SD_Counter' */
  real32_T Vel_Counter_DSTATE;         /* '<S38>/Vel_Counter' */
  uint8_T x_init_reset_DSTATE;         /* '<S68>/x_init_reset' */
  uint8_T TCS_Var_Flag_Init_DSTATE;    /* '<S82>/TCS_Var_Flag_Init' */
  uint8_T TCS_Var_Flag_DSTATE;         /* '<S82>/TCS_Var_Flag' */
  uint8_T Step_Counter_Var_DSTATE;     /* '<S82>/Step_Counter_Var' */
  uint8_T TCS_Vel_Flag_Init_DSTATE;    /* '<S117>/TCS_Vel_Flag_Init' */
  uint8_T TCS_Vel_Flag_DSTATE;         /* '<S117>/TCS_Vel_Flag' */
  uint8_T Step_Counter_Vel_DSTATE;     /* '<S117>/Step_Counter_Vel' */
  rtDW_step_increment_ve_model RR_z_step_increment_ve_model;/* '<S112>/RR_z_step_increment_ve_model' */
  rtDW_step_increment_ve_model RL_z_step_increment_ve_model;/* '<S112>/RL_z_step_increment_ve_model' */
  rtDW_step_increment_ve_model FR_z_step_increment_ve_model;/* '<S112>/FR_z_step_increment_ve_model' */
  rtDW_step_increment_ve_model FL_z_step_increment_ve_model;/* '<S112>/FL_z_step_increment_ve_model' */
  rtDW_check_variance_R_matrix check_variance_R_matrix_RR;/* '<S15>/check_variance_R_matrix_RR' */
  rtDW_check_variance_R_matrix check_variance_R_matrix_RL;/* '<S15>/check_variance_R_matrix_RL' */
  rtDW_check_variance_R_matrix check_variance_R_matrix_FR;/* '<S15>/check_variance_R_matrix_FR' */
  rtDW_check_variance_R_matrix check_variance_R_matrix_FL;/* '<S15>/check_variance_R_matrix_FL' */
  rtDW_step_increment_ve_model RR_R_step_increment_ve_model;/* '<S73>/RR_R_step_increment_ve_model' */
  rtDW_step_increment_ve_model RL_R_step_increment_ve_model;/* '<S73>/RL_R_step_increment_ve_model' */
  rtDW_step_increment_ve_model FR_R_step_increment_ve_model;/* '<S73>/FR_R_step_increment_ve_model' */
  rtDW_step_increment_ve_model FL_R_step_increment_ve_model;/* '<S73>/FL_R_step_increment_ve_model' */
} D_Work_vdy_ve;

/* Model entry point functions */
extern void vdy_ve_initialize(boolean_T firstTime, BlockIO_vdy_ve *vdy_ve_B,
  D_Work_vdy_ve *vdy_ve_DWork);
extern void vdy_ve_step(BlockIO_vdy_ve *vdy_ve_B, D_Work_vdy_ve *vdy_ve_DWork,
  VDYInputData_t *vdy_ve_U_VDYInputData, VDYInternalData_t
  *vdy_ve_U_VDYInternalData_in, Brake_t *vdy_ve_U_brake_input, VDYInternalData_t
  *vdy_ve_Y_VDYInternalData_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_ve_H_p[8];
extern const real32_T vdy_ve_I_matrix_p[4];
extern const real32_T vdy_ve_K_default_p[8];
extern const real32_T vdy_ve_P_init_p[4];
extern const real32_T vdy_ve_Q_gain_p[3];
extern const real32_T vdy_ve_Q_sigmas_p[2];
extern const real32_T vdy_ve_a_v_zero_p[9];
extern const real32_T vdy_ve_x_init_p;

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
 * '<Root>' : vdy_ve
 * '<S1>'   : vdy_ve/A
 * '<S2>'   : vdy_ve/AccelFuse
 * '<S3>'   : vdy_ve/Calculate_TCS
 * '<S4>'   : vdy_ve/Check_ABS
 * '<S5>'   : vdy_ve/Get_IO_State_ExtAccel
 * '<S6>'   : vdy_ve/Model Info
 * '<S7>'   : vdy_ve/Q
 * '<S8>'   : vdy_ve/Rate Limiter
 * '<S9>'   : vdy_ve/Time2Sec
 * '<S10>'  : vdy_ve/a_var_correct
 * '<S11>'  : vdy_ve/calc_Q_gain
 * '<S12>'  : vdy_ve/calc_diff_q_gain
 * '<S13>'  : vdy_ve/check_for_pulse
 * '<S14>'  : vdy_ve/four_wheel_speed_fusion1
 * '<S15>'  : vdy_ve/make_R_matrix
 * '<S16>'  : vdy_ve/make_z_vektor
 * '<S17>'  : vdy_ve/v_var_correct
 * '<S18>'  : vdy_ve/zero_correcction_a
 * '<S19>'  : vdy_ve/zero_correction_v
 * '<S20>'  : vdy_ve/A/make_A_matrix
 * '<S21>'  : vdy_ve/AccelFuse/Jerk_Detection
 * '<S22>'  : vdy_ve/AccelFuse/Mixer
 * '<S23>'  : vdy_ve/AccelFuse/Weightage
 * '<S24>'  : vdy_ve/AccelFuse/Jerk_Detection/JerkDetect
 * '<S25>'  : vdy_ve/AccelFuse/Weightage/Wightage
 * '<S26>'  : vdy_ve/Calculate_TCS/Else_condition
 * '<S27>'  : vdy_ve/Calculate_TCS/If_TCS_detected
 * '<S28>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Check_ABS_is_valid&zero
 * '<S29>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction
 * '<S30>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Get_IO_State_TCS
 * '<S31>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Check_ABS_is_valid&zero/Get_IO_State_ABS
 * '<S32>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Check_ABS_is_valid&zero/Get_IO_State_WVEL_FL
 * '<S33>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Check_ABS_is_valid&zero/Get_IO_State_WVEL_FR
 * '<S34>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Check_ABS_is_valid&zero/Get_IO_State_WVEL_RL
 * '<S35>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Check_ABS_is_valid&zero/Get_IO_State_WVEL_RR
 * '<S36>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/Else_condition
 * '<S37>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/If_TCS_detected
 * '<S38>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel
 * '<S39>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel_std_dev
 * '<S40>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/calc_flag_accel
 * '<S41>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel/whl_vel_diff_function
 * '<S42>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel_std_dev/Left
 * '<S43>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel_std_dev/Right
 * '<S44>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/cal_flag_vel_std_dev/whl_vel_std_dev_function
 * '<S45>'  : vdy_ve/Calculate_TCS/If_TCS_detected/Compute_traction/calc_flag_accel/whl_accel_function
 * '<S46>'  : vdy_ve/Check_ABS/Else_condition
 * '<S47>'  : vdy_ve/Check_ABS/If_ABS_detected
 * '<S48>'  : vdy_ve/Check_ABS/If_ABS_detected/Get_IO_State_ABS
 * '<S49>'  : vdy_ve/Q/Get_IO_State_VEHACL_EXT
 * '<S50>'  : vdy_ve/Q/Increase_Q2
 * '<S51>'  : vdy_ve/Q/makeQ
 * '<S52>'  : vdy_ve/Rate Limiter/Rate Limiter Dynamic
 * '<S53>'  : vdy_ve/Rate Limiter/Rate Limiter Dynamic/Saturation Dynamic
 * '<S54>'  : vdy_ve/a_var_correct/a_var_correct
 * '<S55>'  : vdy_ve/calc_diff_q_gain/Transfer Fcn First Order
 * '<S56>'  : vdy_ve/calc_diff_q_gain/gain_ramp
 * '<S57>'  : vdy_ve/check_for_pulse/Get_IO_State_WTCKS_FL
 * '<S58>'  : vdy_ve/check_for_pulse/Get_IO_State_WTCKS_FR
 * '<S59>'  : vdy_ve/check_for_pulse/Get_IO_State_WTCKS_RL
 * '<S60>'  : vdy_ve/check_for_pulse/Get_IO_State_WTCKS_RR
 * '<S61>'  : vdy_ve/four_wheel_speed_fusion1/Calculate Kalman gain PHt_(HPHt_R)
 * '<S62>'  : vdy_ve/four_wheel_speed_fusion1/Reset_P_pred
 * '<S63>'  : vdy_ve/four_wheel_speed_fusion1/Reset_x_pred
 * '<S64>'  : vdy_ve/four_wheel_speed_fusion1/diag
 * '<S65>'  : vdy_ve/four_wheel_speed_fusion1/hx
 * '<S66>'  : vdy_ve/four_wheel_speed_fusion1/vdy_s-func_APAt
 * '<S67>'  : vdy_ve/four_wheel_speed_fusion1/vdy_s_func_HPHt
 * '<S68>'  : vdy_ve/four_wheel_speed_fusion1/x_delay
 * '<S69>'  : vdy_ve/four_wheel_speed_fusion1/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_4x4
 * '<S70>'  : vdy_ve/four_wheel_speed_fusion1/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S71>'  : vdy_ve/four_wheel_speed_fusion1/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S72>'  : vdy_ve/make_R_matrix/Merge_wheel_variances
 * '<S73>'  : vdy_ve/make_R_matrix/R_step_increment
 * '<S74>'  : vdy_ve/make_R_matrix/Select_min_or_max_wheel_speed
 * '<S75>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FL
 * '<S76>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FR
 * '<S77>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_RL
 * '<S78>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_RR
 * '<S79>'  : vdy_ve/make_R_matrix/diag
 * '<S80>'  : vdy_ve/make_R_matrix/R_step_increment/FL_R_step_increment_ve_model
 * '<S81>'  : vdy_ve/make_R_matrix/R_step_increment/FR_R_step_increment_ve_model
 * '<S82>'  : vdy_ve/make_R_matrix/R_step_increment/Init_TCS_ABS_flag_delay
 * '<S83>'  : vdy_ve/make_R_matrix/R_step_increment/RL_R_step_increment_ve_model
 * '<S84>'  : vdy_ve/make_R_matrix/R_step_increment/RR_R_step_increment_ve_model
 * '<S85>'  : vdy_ve/make_R_matrix/R_step_increment/FL_R_step_increment_ve_model/whl_vel//var_calc
 * '<S86>'  : vdy_ve/make_R_matrix/R_step_increment/FR_R_step_increment_ve_model/whl_vel//var_calc
 * '<S87>'  : vdy_ve/make_R_matrix/R_step_increment/RL_R_step_increment_ve_model/whl_vel//var_calc
 * '<S88>'  : vdy_ve/make_R_matrix/R_step_increment/RR_R_step_increment_ve_model/whl_vel//var_calc
 * '<S89>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FL/check_threshold_fl
 * '<S90>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FL/tp_filter_peaks_fl
 * '<S91>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FL/tp_filter_peaks_fl/check_reset_condition_fl
 * '<S92>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FL/tp_filter_peaks_fl/tp_filter_fl
 * '<S93>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FL/tp_filter_peaks_fl/tp_filter_fl/Unit Delay Resettable External IC
 * '<S94>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FR/check_threshold_fl
 * '<S95>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FR/tp_filter_peaks_fl
 * '<S96>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FR/tp_filter_peaks_fl/check_reset_condition_fl
 * '<S97>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FR/tp_filter_peaks_fl/tp_filter_fl
 * '<S98>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_FR/tp_filter_peaks_fl/tp_filter_fl/Unit Delay Resettable External IC
 * '<S99>'  : vdy_ve/make_R_matrix/check_variance_R_matrix_RL/check_threshold_fl
 * '<S100>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RL/tp_filter_peaks_fl
 * '<S101>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RL/tp_filter_peaks_fl/check_reset_condition_fl
 * '<S102>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RL/tp_filter_peaks_fl/tp_filter_fl
 * '<S103>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RL/tp_filter_peaks_fl/tp_filter_fl/Unit Delay Resettable External IC
 * '<S104>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RR/check_threshold_fl
 * '<S105>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RR/tp_filter_peaks_fl
 * '<S106>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RR/tp_filter_peaks_fl/check_reset_condition_fl
 * '<S107>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RR/tp_filter_peaks_fl/tp_filter_fl
 * '<S108>' : vdy_ve/make_R_matrix/check_variance_R_matrix_RR/tp_filter_peaks_fl/tp_filter_fl/Unit Delay Resettable External IC
 * '<S109>' : vdy_ve/make_z_vektor/Compute_min_or_max_wheel_speed
 * '<S110>' : vdy_ve/make_z_vektor/Merge_wheel_speeds
 * '<S111>' : vdy_ve/make_z_vektor/Select_min_or_max_wheel_speed
 * '<S112>' : vdy_ve/make_z_vektor/z_step_increment
 * '<S113>' : vdy_ve/make_z_vektor/z_step_increment/FL_z_step_increment_ve_model
 * '<S114>' : vdy_ve/make_z_vektor/z_step_increment/FR_z_step_increment_ve_model
 * '<S115>' : vdy_ve/make_z_vektor/z_step_increment/RL_z_step_increment_ve_model
 * '<S116>' : vdy_ve/make_z_vektor/z_step_increment/RR_z_step_increment_ve_model
 * '<S117>' : vdy_ve/make_z_vektor/z_step_increment/init_TCS_flag_delay
 * '<S118>' : vdy_ve/make_z_vektor/z_step_increment/FL_z_step_increment_ve_model/whl_vel//var_calc
 * '<S119>' : vdy_ve/make_z_vektor/z_step_increment/FR_z_step_increment_ve_model/whl_vel//var_calc
 * '<S120>' : vdy_ve/make_z_vektor/z_step_increment/RL_z_step_increment_ve_model/whl_vel//var_calc
 * '<S121>' : vdy_ve/make_z_vektor/z_step_increment/RR_z_step_increment_ve_model/whl_vel//var_calc
 * '<S122>' : vdy_ve/v_var_correct/v_var_correct
 */
#endif                                 /* RTW_HEADER_vdy_ve_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
