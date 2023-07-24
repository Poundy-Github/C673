/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_sye_para.c
   Real-Time Workshop code generated for Simulink model vdy_sye.
   Model version                        : 1.3383
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:04:36 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:04:37 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy steering angle yaw rate estimation
   and driver intended curvature estimation
   VERSION:                             : $Revision: 1.6 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "rtwtypes.h"
#include "vdy_sye_types.h"

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

/* Const memory section */
/* Definition for custom storage class: Const */
const real32_T vdy_sye_I_SSG_matrix_p[9] = { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
  0.0F, 0.0F, 1.0F } ;

const real32_T vdy_sye_I_di_matrix_p[4] = { 1.0F, 0.0F, 0.0F, 1.0F } ;

const real32_T vdy_sye_I_matrix_p[4] = { 1.0F, 0.0F, 0.0F, 1.0F } ;

const real32_T vdy_sye_K_SSG_default_p[6] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;

const real32_T vdy_sye_K_default_p[2] = { 0.0F, 0.0F } ;

const real32_T vdy_sye_K_di_default_p[2] = { 0.0F, 0.0F } ;

const real32_T vdy_sye_P_SSG_init_p[9] = { 0.0001F, 0.0F, 0.0F, 0.0F, 0.001F,
  0.0F, 0.0F, 0.0F, 1.0E-10F } ;

const real32_T vdy_sye_P_correct_p[4] = { 100.0F, 0.5F, 5.0E-7F, 0.0002F } ;

const real32_T vdy_sye_P_di_init_p[4] = { 1.0F, 0.0F, 0.0F, 1.0F } ;

const real32_T vdy_sye_P_init_p[4] = { 1.0F, 0.0F, 0.0F, 1.0F } ;

const real32_T vdy_sye_Q_SSG_range_p[5] = { 0.35F, 0.5F, 3.5F, 1.0E-7F, 1.0E-11F
} ;

const real32_T vdy_sye_Q_SSG_sigmas_p[2] = { 0.05F, 0.05F } ;

const real32_T vdy_sye_Q_add_p[4] = { 0.0F, 0.0F, 0.0F, 0.0F } ;

const real32_T vdy_sye_Q_di_add_p[4] = { 0.0F, 0.0F, 0.0F, 0.0F } ;

const real32_T vdy_sye_Q_di_gain_p[3] = { 1000.0F, 1.0F, 0.2F } ;

const real32_T vdy_sye_Q_di_sigmas_p[2] = { 0.1F, 0.1F } ;

const real32_T vdy_sye_Q_di_sigmas_velo_gain_p[4] = { 1.0F, 0.3F, 0.01F, 13.0F }
;

const real32_T vdy_sye_Q_gain_p[3] = { 120.0F, 1.0F, 0.001F } ;

const real32_T vdy_sye_Q_sigmas_p[2] = { 0.15F, 0.15F } ;

const real32_T vdy_sye_R_SSG_p[4] = { 0.0001F, 0.0F, 0.0F, 0.000324F } ;

const real32_T vdy_sye_R_p[2] = { 0.000225F, 250000.0F } ;

const real32_T vdy_sye_x_SSG_init_p[3] = { 0.01F, 0.01F, 0.007F } ;

const real32_T vdy_sye_x_di_init_p[2] = { 0.0001F, 0.0001F } ;

const real32_T vdy_sye_x_init_p[2] = { 0.0001F, 0.0001F } ;

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
