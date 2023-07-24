/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_matrix_inversion_3x3.c
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
   VERSION:                             : $Revision: 1.3 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#include "vdy_matrix_inversion_3x3.h"

/* Include model header file for global data */
#include "vdy_wye.h"
#include "vdy_wye_private.h"

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
 * Output and update for atomic system: '<S14>/Matrix_Inversion_3x3'
 * Block description for: '<S14>/Matrix_Inversion_3x3'
 *   Compute an Inverse Matrix for a 3x3 Matrix
 */
void vdy_matrix_inversion_3x3(const real32_T rtu_HPHt_R[9],
  rtB_vdy_matrix_inversion_3x3 *localB)
{
  real32_T A;
  real32_T B;
  real32_T C;
  real32_T determinant;
  int32_T i;

  /* Embedded MATLAB: '<S14>/Matrix_Inversion_3x3' */
  /* Embedded MATLAB Function 'Matrix_Inversion_3x3': '<S22>:1' */
  /* Inversion of 3x3 matrix */
  /* '<S22>:1:4' */
  for (i = 0; i < 9; i++) {
    localB->HPHt_R_inv[(i)] = 0.0F;
  }

  /*  default value for initialization */
  /* '<S22>:1:5' */
  localB->det_flag = FALSE;

  /*  Cofactors of the matrix */
  /* '<S22>:1:8' */
  A = (rtu_HPHt_R[4] * rtu_HPHt_R[8]) - (rtu_HPHt_R[7] * rtu_HPHt_R[5]);

  /* '<S22>:1:9' */
  B = -((rtu_HPHt_R[1] * rtu_HPHt_R[8]) - (rtu_HPHt_R[7] * rtu_HPHt_R[2]));

  /* '<S22>:1:10' */
  C = (rtu_HPHt_R[1] * rtu_HPHt_R[5]) - (rtu_HPHt_R[4] * rtu_HPHt_R[2]);

  /* '<S22>:1:11' */
  /* '<S22>:1:12' */
  /* '<S22>:1:13' */
  /* '<S22>:1:14' */
  /* '<S22>:1:15' */
  /* '<S22>:1:16' */
  /* '<S22>:1:18' */
  determinant = ((rtu_HPHt_R[0] * A) + (rtu_HPHt_R[3] * B)) + (rtu_HPHt_R[6] * C);

  /*  determinant */
  if (determinant < 1.0E-16F) {
    /* '<S22>:1:19' */
    determinant = 1.0E-16F;

    /* '<S22>:1:19' */
    localB->det_flag = TRUE;
  }

  /* if determinant value is too low */
  if (!localB->det_flag) {
    /* '<S22>:1:21' */
    /*  Elements of the inverted matrix */
    /* '<S22>:1:23' */
    localB->HPHt_R_inv[0] = A / determinant;

    /* '<S22>:1:24' */
    localB->HPHt_R_inv[3] = (-((rtu_HPHt_R[3] * rtu_HPHt_R[8]) - (rtu_HPHt_R[6] *
      rtu_HPHt_R[5]))) / determinant;

    /* '<S22>:1:25' */
    localB->HPHt_R_inv[6] = ((rtu_HPHt_R[3] * rtu_HPHt_R[7]) - (rtu_HPHt_R[6] *
      rtu_HPHt_R[4])) / determinant;

    /* '<S22>:1:26' */
    localB->HPHt_R_inv[1] = B / determinant;

    /* '<S22>:1:27' */
    localB->HPHt_R_inv[4] = ((rtu_HPHt_R[0] * rtu_HPHt_R[8]) - (rtu_HPHt_R[6] *
      rtu_HPHt_R[2])) / determinant;

    /* '<S22>:1:28' */
    localB->HPHt_R_inv[7] = (-((rtu_HPHt_R[0] * rtu_HPHt_R[7]) - (rtu_HPHt_R[6] *
      rtu_HPHt_R[1]))) / determinant;

    /* '<S22>:1:29' */
    localB->HPHt_R_inv[2] = C / determinant;

    /* '<S22>:1:30' */
    localB->HPHt_R_inv[5] = (-((rtu_HPHt_R[0] * rtu_HPHt_R[5]) - (rtu_HPHt_R[3] *
      rtu_HPHt_R[2]))) / determinant;

    /* '<S22>:1:31' */
    localB->HPHt_R_inv[8] = ((rtu_HPHt_R[0] * rtu_HPHt_R[4]) - (rtu_HPHt_R[3] *
      rtu_HPHt_R[1])) / determinant;
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
