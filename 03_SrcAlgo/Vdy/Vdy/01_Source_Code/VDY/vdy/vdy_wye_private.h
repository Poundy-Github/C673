/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_wye_private.h
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
   VERSION:                             : $Revision: 1.7 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_wye_private_h_
#define RTW_HEADER_vdy_wye_private_h_
#include "rtwtypes.h"

/* Includes for objects with custom storage classes. */
#include "vdy_ext.h"

/*
 * Generate compile time checks that imported macros for parameters
 * with storage class "Const" are defined
 */

/*
 * Generate compile time checks that imported macros for parameters
 * with storage class "VDY_Defines" are defined
 */
#ifndef CFG_VDY_INT_GYRO
#error The variable for the parameter "CFG_VDY_INT_GYRO" is not defined
#else
#if (CFG_VDY_INT_GYRO < 0UL) || (CFG_VDY_INT_GYRO > 4294967295UL)
#error The value of the variable for the parameter "CFG_VDY_INT_GYRO" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_IO_STATE_INVALID
#error The variable for the parameter "VDY_IO_STATE_INVALID" is not defined
#else
#if (VDY_IO_STATE_INVALID < 0UL) || (VDY_IO_STATE_INVALID > 4294967295UL)
#error The value of the variable for the parameter "VDY_IO_STATE_INVALID" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_IO_STATE_VALID
#error The variable for the parameter "VDY_IO_STATE_VALID" is not defined
#else
#if (VDY_IO_STATE_VALID < 0UL) || (VDY_IO_STATE_VALID > 4294967295UL)
#error The value of the variable for the parameter "VDY_IO_STATE_VALID" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_NVM_POS_WLD
#error The variable for the parameter "VDY_NVM_POS_WLD" is not defined
#else
#if (VDY_NVM_POS_WLD < 0UL) || (VDY_NVM_POS_WLD > 4294967295UL)
#error The value of the variable for the parameter "VDY_NVM_POS_WLD" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_YWR
#error The variable for the parameter "VDY_SIN_POS_YWR" is not defined
#else
#if (VDY_SIN_POS_YWR < 0UL) || (VDY_SIN_POS_YWR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_YWR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_YWRINT
#error The variable for the parameter "VDY_SIN_POS_YWRINT" is not defined
#else
#if (VDY_SIN_POS_YWRINT < 0UL) || (VDY_SIN_POS_YWRINT > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_YWRINT" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_USE_EST_WLD_DEP
#error The variable for the parameter "VDY_USE_EST_WLD_DEP" is not defined
#else
#if (VDY_USE_EST_WLD_DEP < 0UL) || (VDY_USE_EST_WLD_DEP > 4294967295UL)
#error The value of the variable for the parameter "VDY_USE_EST_WLD_DEP" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_CAL_WHS_LOAD
#error The variable for the parameter "VDY_CAL_WHS_LOAD" is not defined
#else
#if (VDY_CAL_WHS_LOAD < 0) || (VDY_CAL_WHS_LOAD > 65535)
#error The value of the variable for the parameter "VDY_CAL_WHS_LOAD" is outside of the range 0 to 65535
#endif
#endif

#ifndef VDY_CAL_YWR_OFFS_DYN
#error The variable for the parameter "VDY_CAL_YWR_OFFS_DYN" is not defined
#else
#if (VDY_CAL_YWR_OFFS_DYN < 0) || (VDY_CAL_YWR_OFFS_DYN > 65535)
#error The value of the variable for the parameter "VDY_CAL_YWR_OFFS_DYN" is outside of the range 0 to 65535
#endif
#endif

#define CALL_EVENT                     (-1)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

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
extern void vdy_wye_Get_NVM_IO_State(uint32_T rtu_pos, uint32_T rtu_state_in,
  uint32_T rtu_VDYIOBitMask, rtB_Get_NVM_IO_State_vdy_wye *localB);
extern void vdy_wye_Time2Sec(uint16_T rtu_u, rtB_Time2Sec_vdy_wye *localB);
extern void vdy_wye_make_A_matrix(real32_T rtu_CycleTime,
  rtB_make_A_matrix_vdy_wye *localB);
extern void vdy_wye_get_bit(uint16_T rtu_value_in, uint16_T rtu_bitmask,
  rtB_get_bit_vdy_wye *localB);
extern void vdy_wye_Get_IO_State(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State_vdy_wye *localB, uint32_T rtp_Filter);

#endif                                 /* RTW_HEADER_vdy_wye_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
