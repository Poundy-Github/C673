/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_gye.h
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
#ifndef RTW_HEADER_vdy_gye_h_
#define RTW_HEADER_vdy_gye_h_
#ifndef vdy_gye_COMMON_INCLUDES_
# define vdy_gye_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_gye_COMMON_INCLUDES_ */

#include "vdy_gye_types.h"

/* Child system includes */
#include "vdy_matrix_inversion_1x1.h"

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

/* Block signals for system '<S10>/Get_IO_State1' */
typedef struct {
  uint8_T IndexVector;                 /* '<S33>/Index Vector' */
} rtB_Get_IO_State1_vdy_gye;

/* Block signals (auto storage) */
typedef struct {
  real32_T Divide;                     /* '<S7>/Divide' */
  rtB_Get_IO_State1_vdy_gye Get_IO_State2;/* '<S10>/Get_IO_State2' */
  rtB_Get_IO_State1_vdy_gye Get_IO_State1;/* '<S10>/Get_IO_State1' */
  rtB_vdy_matrix_inversion_1x1 sf_Matrix_Inversion_1x1;/* '<S11>/Matrix_Inversion_1x1' */
} BlockIO_vdy_gye;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T delay_DSTATE;               /* '<S7>/delay' */
  real32_T UD_DSTATE;                  /* '<S24>/UD' */
  real32_T WeightedMovingAverage_TapDelayU[7];/* '<S7>/Weighted Moving Average' */
  real32_T UnitDelay_DSTATE;           /* '<S28>/Unit Delay' */
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S32>/FixPt Unit Delay1' */
  real32_T UD_DSTATE_h;                /* '<S25>/UD' */
  real32_T hold_value_DSTATE;          /* '<S26>/hold_value' */
  real32_T P_delay_DSTATE[4];          /* '<S2>/P_delay' */
  real32_T x_delay_DSTATE[2];          /* '<S2>/x_delay' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S32>/FixPt Unit Delay2' */
  uint8_T hold_counter_DSTATE;         /* '<S26>/hold_counter' */
} D_Work_vdy_gye;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: mgainval
   * Referenced by: '<S7>/Weighted Moving Average'
   */
  real32_T WeightedMovingAverage[8];
} ConstParam_vdy_gye;

/* Constant parameters (auto storage) */
extern const ConstParam_vdy_gye vdy_gye_ConstP;

/* Model entry point functions */
extern void vdy_gye_initialize(boolean_T firstTime, BlockIO_vdy_gye *vdy_gye_B,
  D_Work_vdy_gye *vdy_gye_DWork);
extern void vdy_gye_step(BlockIO_vdy_gye *vdy_gye_B, D_Work_vdy_gye
  *vdy_gye_DWork, VDYInputData_t *vdy_gye_U_VDYInputData, VDYInternalData_t
  *vdy_gye_U_VDYInternalData_in, VDYInternalData_t
  *vdy_gye_Y_VDYInternalData_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_gye_H_p[2];
extern const real32_T vdy_gye_I_matrix_p[4];
extern const real32_T vdy_gye_K_default_p[2];
extern const real32_T vdy_gye_P_correct_p[2];
extern const real32_T vdy_gye_P_init_p[4];
extern const real32_T vdy_gye_Q_gain_p;
extern const real32_T vdy_gye_R_p[6];
extern const real32_T vdy_gye_x_init_p[2];

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
 * '<Root>' : vdy_gye
 * '<S1>'   : vdy_gye/A
 * '<S2>'   : vdy_gye/KF
 * '<S3>'   : vdy_gye/Model Info
 * '<S4>'   : vdy_gye/Q
 * '<S5>'   : vdy_gye/R
 * '<S6>'   : vdy_gye/Time2Sec
 * '<S7>'   : vdy_gye/calculate_Q_gain
 * '<S8>'   : vdy_gye/correct_output
 * '<S9>'   : vdy_gye/diag_uncertainty
 * '<S10>'  : vdy_gye/make_z_vektor
 * '<S11>'  : vdy_gye/KF/Calculate Kalman gain
 * '<S12>'  : vdy_gye/KF/Reset_P_pred
 * '<S13>'  : vdy_gye/KF/Reset_x_pred
 * '<S14>'  : vdy_gye/KF/vdy_s-func_APAt
 * '<S15>'  : vdy_gye/KF/vdy_s-func_HPHt
 * '<S16>'  : vdy_gye/KF/Calculate Kalman gain/Matrix_Inversion_1x1
 * '<S17>'  : vdy_gye/KF/Calculate Kalman gain/calculate the gain
 * '<S18>'  : vdy_gye/KF/Calculate Kalman gain/set gain to default value
 * '<S19>'  : vdy_gye/Q/make_Q
 * '<S20>'  : vdy_gye/Q/make_Q/make_Q_matrix
 * '<S21>'  : vdy_gye/R/If Action false
 * '<S22>'  : vdy_gye/R/If Action true
 * '<S23>'  : vdy_gye/R/If Action true/calc_resolution_var
 * '<S24>'  : vdy_gye/calculate_Q_gain/Difference
 * '<S25>'  : vdy_gye/calculate_Q_gain/Transfer Fcn First Order
 * '<S26>'  : vdy_gye/calculate_Q_gain/hold_last_5_values
 * '<S27>'  : vdy_gye/calculate_Q_gain/threshold_gain
 * '<S28>'  : vdy_gye/calculate_Q_gain/tp_filter_peaks
 * '<S29>'  : vdy_gye/calculate_Q_gain/hold_last_5_values/hold_last_5_values
 * '<S30>'  : vdy_gye/calculate_Q_gain/tp_filter_peaks/check_reset_condition
 * '<S31>'  : vdy_gye/calculate_Q_gain/tp_filter_peaks/tp_filter
 * '<S32>'  : vdy_gye/calculate_Q_gain/tp_filter_peaks/tp_filter/Unit Delay Resettable External IC
 * '<S33>'  : vdy_gye/make_z_vektor/Get_IO_State1
 * '<S34>'  : vdy_gye/make_z_vektor/Get_IO_State2
 * '<S35>'  : vdy_gye/make_z_vektor/R_yaw_valid
 */
#endif                                 /* RTW_HEADER_vdy_gye_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
