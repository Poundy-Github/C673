/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_sae.h
   Real-Time Workshop code generated for Simulink model vdy_sae.
   Model version                        : 1.3032
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:06:11 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:06:12 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy slip angle estimation
   VERSION:                             : $Revision: 1.5 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_sae_h_
#define RTW_HEADER_vdy_sae_h_
#ifndef vdy_sae_COMMON_INCLUDES_
# define vdy_sae_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_sae_COMMON_INCLUDES_ */

#include "vdy_sae_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  rtB_vdy_matrix_inversion_1x1 sf_Matrix_Inversion_1x1;/* '<S12>/Matrix_Inversion_1x1' */
} BlockIO_vdy_sae;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T x_delay_DSTATE[2];          /* '<S2>/x_delay' */
  real32_T yaw_rate_delay_4_DSTATE;    /* '<S27>/yaw_rate_delay_4' */
  real32_T yaw_rate_delay_3_DSTATE;    /* '<S27>/yaw_rate_delay_3' */
  real32_T yaw_rate_delay_2_DSTATE;    /* '<S27>/yaw_rate_delay_2' */
  real32_T yaw_rate_delay_1_DSTATE;    /* '<S27>/yaw_rate_delay_1' */
  real32_T P_delay_DSTATE[4];          /* '<S2>/P_delay' */
} D_Work_vdy_sae;

/* Model entry point functions */
extern void vdy_sae_initialize(boolean_T firstTime, BlockIO_vdy_sae *vdy_sae_B,
  D_Work_vdy_sae *vdy_sae_DWork);
extern void vdy_sae_step(BlockIO_vdy_sae *vdy_sae_B, D_Work_vdy_sae
  *vdy_sae_DWork, VDYInputData_t *vdy_sae_U_VDYInputData, VDYInternalData_t
  *vdy_sae_U_VDYInternalData_in, VDYInternalData_t
  *vdy_sae_Y_VDYInternalData_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_sae_Cr_p;
extern const real32_T vdy_sae_I_matrix_p[4];
extern const real32_T vdy_sae_K_default_p[2];
extern const real32_T vdy_sae_P_init_p[4];
extern const real32_T vdy_sae_Q_add_p[4];
extern const real32_T vdy_sae_Q_gain_p[3];
extern const real32_T vdy_sae_Q_sigmas_p[2];
extern const real32_T vdy_sae_R_p;
extern const real32_T vdy_sae_x_init_p[2];

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
 * '<Root>' : vdy_sae
 * '<S1>'   : vdy_sae/A
 * '<S2>'   : vdy_sae/KF
 * '<S3>'   : vdy_sae/Model Info
 * '<S4>'   : vdy_sae/Q
 * '<S5>'   : vdy_sae/R
 * '<S6>'   : vdy_sae/Time2Sec
 * '<S7>'   : vdy_sae/diag_uncertainty
 * '<S8>'   : vdy_sae/make_z_vector
 * '<S9>'   : vdy_sae/q_gain
 * '<S10>'  : vdy_sae/A/make_A_matrix
 * '<S11>'  : vdy_sae/KF/At
 * '<S12>'  : vdy_sae/KF/Calculate Kalman gain PHt_(HPHt_R)
 * '<S13>'  : vdy_sae/KF/Ht
 * '<S14>'  : vdy_sae/KF/Reset_P_pred
 * '<S15>'  : vdy_sae/KF/Reset_x_pred
 * '<S16>'  : vdy_sae/KF/hx
 * '<S17>'  : vdy_sae/KF/vdy_s-func_APAt
 * '<S18>'  : vdy_sae/KF/vdy_s-func_HPHt
 * '<S19>'  : vdy_sae/KF/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_1x1
 * '<S20>'  : vdy_sae/KF/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S21>'  : vdy_sae/KF/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S22>'  : vdy_sae/Q/makeQ
 * '<S23>'  : vdy_sae/R/adapt_R_matrix
 * '<S24>'  : vdy_sae/make_z_vector/Model Info
 * '<S25>'  : vdy_sae/make_z_vector/divide_velocity1
 * '<S26>'  : vdy_sae/q_gain/get_gain_bias
 * '<S27>'  : vdy_sae/q_gain/mean_filt_yaw_rate
 * '<S28>'  : vdy_sae/q_gain/q_gain_delta
 * '<S29>'  : vdy_sae/q_gain/q_gain_delta/If Action false
 * '<S30>'  : vdy_sae/q_gain/q_gain_delta/If Action true
 */
#endif                                 /* RTW_HEADER_vdy_sae_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
