/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_aye.h
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
   VERSION:                             : $Revision: 1.9 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_aye_h_
#define RTW_HEADER_vdy_aye_h_
#ifndef vdy_aye_COMMON_INCLUDES_
# define vdy_aye_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#endif                                 /* vdy_aye_COMMON_INCLUDES_ */

#include "vdy_aye_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  rtB_vdy_matrix_inversion_2x2 sf_Matrix_Inversion_2x2;/* '<S13>/Matrix_Inversion_2x2' */
} BlockIO_vdy_aye;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T x_delay_DSTATE[4];          /* '<S3>/x_delay' */
  real32_T UD_DSTATE;                  /* '<S29>/UD' */
  real32_T delay_DSTATE;               /* '<S11>/delay' */
  real32_T P_delay_DSTATE[16];         /* '<S3>/P_delay' */
  uint8_T BankRoadDelay_DSTATE;        /* '<S2>/BankRoadDelay' */
  uint8_T BankRoadDelay1_DSTATE;       /* '<S2>/BankRoadDelay1' */
} D_Work_vdy_aye;

/* Model entry point functions */
extern void vdy_aye_initialize(boolean_T firstTime, BlockIO_vdy_aye *vdy_aye_B,
  D_Work_vdy_aye *vdy_aye_DWork);
extern void vdy_aye_step(BlockIO_vdy_aye *vdy_aye_B, D_Work_vdy_aye
  *vdy_aye_DWork, VDYInputData_t *vdy_aye_U_VDYInputData, VDYInternalData_t
  *vdy_aye_U_VDYInternalData_in, VDYInternalData_t *vdy_aye_Y_vdy_aye_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T vdy_aye_I_matrix_p[16];
extern const real32_T vdy_aye_K_default_p[8];
extern const real32_T vdy_aye_P_correct_p[4];
extern const real32_T vdy_aye_P_init_p[16];
extern const real32_T vdy_aye_Q_add_p[16];
extern const real32_T vdy_aye_Q_gain_p[2];
extern const real32_T vdy_aye_Q_sigmas_p[4];
extern const real32_T vdy_aye_R_ay_invalid_p;
extern const real32_T vdy_aye_R_p[4];
extern const real32_T vdy_aye_x_init_p[4];

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
 * '<Root>' : vdy_aye
 * '<S1>'   : vdy_aye/A
 * '<S2>'   : vdy_aye/BankRoadDetection
 * '<S3>'   : vdy_aye/EKF
 * '<S4>'   : vdy_aye/Model Info
 * '<S5>'   : vdy_aye/Q
 * '<S6>'   : vdy_aye/R
 * '<S7>'   : vdy_aye/Time2Sec
 * '<S8>'   : vdy_aye/correct_variance
 * '<S9>'   : vdy_aye/correct_yaw_rate
 * '<S10>'  : vdy_aye/make_z_vektor
 * '<S11>'  : vdy_aye/q_gain
 * '<S12>'  : vdy_aye/BankRoadDetection/EnableBRD
 * '<S13>'  : vdy_aye/EKF/Calculate Kalman gain PHt_(HPHt_R)
 * '<S14>'  : vdy_aye/EKF/Reset_P_pred
 * '<S15>'  : vdy_aye/EKF/Reset_x_pred
 * '<S16>'  : vdy_aye/EKF/check_track_bent_range
 * '<S17>'  : vdy_aye/EKF/hx
 * '<S18>'  : vdy_aye/EKF/vdy_s-func_APAt
 * '<S19>'  : vdy_aye/EKF/vdy_s-func_HPHt
 * '<S20>'  : vdy_aye/EKF/Calculate Kalman gain PHt_(HPHt_R)/Matrix_Inversion_2x2
 * '<S21>'  : vdy_aye/EKF/Calculate Kalman gain PHt_(HPHt_R)/calculate the gain
 * '<S22>'  : vdy_aye/EKF/Calculate Kalman gain PHt_(HPHt_R)/set gain to default value
 * '<S23>'  : vdy_aye/EKF/hx/hx
 * '<S24>'  : vdy_aye/EKF/hx/x(3)
 * '<S25>'  : vdy_aye/R/adapt_R_matrix
 * '<S26>'  : vdy_aye/make_z_vektor/Get_IO_State2
 * '<S27>'  : vdy_aye/make_z_vektor/gnerate_z_vector
 * '<S28>'  : vdy_aye/q_gain/q_gain_delta
 * '<S29>'  : vdy_aye/q_gain/tp_filter
 */
#endif                                 /* RTW_HEADER_vdy_aye_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
