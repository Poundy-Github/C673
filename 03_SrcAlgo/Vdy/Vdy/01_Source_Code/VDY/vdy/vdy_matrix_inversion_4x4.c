/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_matrix_inversion_4x4.c
   Real-Time Workshop code generated for Simulink model vdy_ye.
   Model version                        : 1.2827
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
   VERSION:                             : $Revision: 1.3 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_matrix_inversion_4x4.h"

/* Include model header file for global data */
#include "vdy_ye.h"
#include "vdy_ye_private.h"

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
 * Output and update for atomic system: '<S70>/Matrix_Inversion_4x4'
 * Block description for: '<S70>/Matrix_Inversion_4x4'
 *   Compute an Inverse Matrix for a 4x4 Matrix
 */
void vdy_matrix_inversion_4x4(const real32_T rtu_HPHt[16], const real32_T rtu_R
  [16], rtB_vdy_matrix_inversion_4x4 *localB)
{
  real32_T d;
  real32_T d_0;
  real32_T d_1;
  real32_T d_2;
  real32_T z;

  /* Embedded MATLAB: '<S70>/Matrix_Inversion_4x4' */
  /* Embedded MATLAB Function 'Matrix_Inversion_4x4': '<S77>:1' */
  /* Inversion of 4x4 matrix */
  /* '<S77>:1:4' */
  vdy_memset_s((void *)(&localB->HPHt_R_inv[0]), (int32_T)0.0F, sizeof(real32_T)
               << 4U);

  /*  default value for initialization */
  /* '<S77>:1:5' */
  localB->det_flag = FALSE;

  /* Diagonal elements of R matrix */
  if (rtu_R[0] > 1.0E-10F) {
    /* '<S77>:1:8' */
    d = rtu_R[0];
  } else {
    /* '<S77>:1:9' */
    d = 1.0E-10F;

    /* '<S77>:1:9' */
    localB->det_flag = TRUE;
  }

  /* if R(1,1) value is too low */
  if (rtu_R[5] > 1.0E-10F) {
    /* '<S77>:1:11' */
    d_0 = rtu_R[5];
  } else {
    /* '<S77>:1:12' */
    d_0 = 1.0E-10F;

    /* '<S77>:1:12' */
    localB->det_flag = TRUE;
  }

  /* if R(2,2) value is too low */
  if (rtu_R[10] > 1.0E-10F) {
    /* '<S77>:1:14' */
    d_1 = rtu_R[10];
  } else {
    /* '<S77>:1:15' */
    d_1 = 1.0E-10F;

    /* '<S77>:1:15' */
    localB->det_flag = TRUE;
  }

  /* if R(3,3) value is too low */
  if (rtu_R[15] > 1.0E-10F) {
    /* '<S77>:1:17' */
    d_2 = rtu_R[15];
  } else {
    /* '<S77>:1:18' */
    d_2 = 1.0E-10F;

    /* '<S77>:1:18' */
    localB->det_flag = TRUE;
  }

  /* if R(4,4) value is too low */
  /* '<S77>:1:21' */
  /*  All elements are same in HPHt matrix, so take the first element */
  if (!localB->det_flag) {
    /* '<S77>:1:23' */
    /* '<S77>:1:24' */
    z = 1.0F / (((((rtu_HPHt[0] / d) + 1.0F) + (rtu_HPHt[0] / d_0)) + (rtu_HPHt
      [0] / d_1)) + (rtu_HPHt[0] / d_2));

    /*  Elements of the inverted matrix */
    /* '<S77>:1:27' */
    localB->HPHt_R_inv[0] = (1.0F - ((rtu_HPHt[0] * z) / d)) * (1.0F / d);

    /* '<S77>:1:28' */
    localB->HPHt_R_inv[5] = (1.0F - ((rtu_HPHt[0] * z) / d_0)) * (1.0F / d_0);

    /* '<S77>:1:29' */
    localB->HPHt_R_inv[10] = (1.0F - ((rtu_HPHt[0] * z) / d_1)) * (1.0F / d_1);

    /* '<S77>:1:30' */
    localB->HPHt_R_inv[15] = (1.0F - ((rtu_HPHt[0] * z) / d_2)) * (1.0F / d_2);

    /* '<S77>:1:32' */
    localB->HPHt_R_inv[1] = -((rtu_HPHt[0] * z) / (d * d_0));

    /* '<S77>:1:33' */
    localB->HPHt_R_inv[2] = -((rtu_HPHt[0] * z) / (d * d_1));

    /* '<S77>:1:34' */
    localB->HPHt_R_inv[3] = -((rtu_HPHt[0] * z) / (d * d_2));

    /* '<S77>:1:35' */
    localB->HPHt_R_inv[6] = -((rtu_HPHt[0] * z) / (d_0 * d_1));

    /* '<S77>:1:36' */
    localB->HPHt_R_inv[7] = -((rtu_HPHt[0] * z) / (d_0 * d_2));

    /* '<S77>:1:37' */
    localB->HPHt_R_inv[11] = -((rtu_HPHt[0] * z) / (d_1 * d_2));

    /* '<S77>:1:39' */
    localB->HPHt_R_inv[4] = localB->HPHt_R_inv[1];

    /* '<S77>:1:40' */
    localB->HPHt_R_inv[8] = localB->HPHt_R_inv[2];

    /* '<S77>:1:41' */
    localB->HPHt_R_inv[12] = localB->HPHt_R_inv[3];

    /* '<S77>:1:42' */
    localB->HPHt_R_inv[9] = localB->HPHt_R_inv[6];

    /* '<S77>:1:43' */
    localB->HPHt_R_inv[13] = localB->HPHt_R_inv[7];

    /* '<S77>:1:44' */
    localB->HPHt_R_inv[14] = localB->HPHt_R_inv[11];
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
