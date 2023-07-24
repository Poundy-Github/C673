/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_mot_st_private.h
   Real-Time Workshop code generated for Simulink model vdy_mot_st.
   Model version                        : 1.4934
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:06:53 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:06:54 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy motion state estimation, use
   a bayes net to compute a motion state
   and quality for this state
   VERSION:                             : $Revision: 1.11 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_mot_st_private_h_
#define RTW_HEADER_vdy_mot_st_private_h_
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
#ifndef CFG_VDY_MFC
#error The variable for the parameter "CFG_VDY_MFC" is not defined
#else
#if (CFG_VDY_MFC < 0UL) || (CFG_VDY_MFC > 4294967295UL)
#error The value of the variable for the parameter "CFG_VDY_MFC" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef CFG_VDY_USE_EX_LONG_VELO
#error The variable for the parameter "CFG_VDY_USE_EX_LONG_VELO" is not defined
#else
#if (CFG_VDY_USE_EX_LONG_VELO < 0UL) || (CFG_VDY_USE_EX_LONG_VELO > 4294967295UL)
#error The value of the variable for the parameter "CFG_VDY_USE_EX_LONG_VELO" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_IO_STATE_DECREASED
#error The variable for the parameter "VDY_IO_STATE_DECREASED" is not defined
#else
#if (VDY_IO_STATE_DECREASED < 0UL) || (VDY_IO_STATE_DECREASED > 4294967295UL)
#error The value of the variable for the parameter "VDY_IO_STATE_DECREASED" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_IO_STATE_VALID
#error The variable for the parameter "VDY_IO_STATE_VALID" is not defined
#else
#if (VDY_IO_STATE_VALID < 0UL) || (VDY_IO_STATE_VALID > 4294967295UL)
#error The value of the variable for the parameter "VDY_IO_STATE_VALID" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_BRAKE
#error The variable for the parameter "VDY_SIN_POS_BRAKE" is not defined
#else
#if (VDY_SIN_POS_BRAKE < 0UL) || (VDY_SIN_POS_BRAKE > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_BRAKE" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_GEAR
#error The variable for the parameter "VDY_SIN_POS_GEAR" is not defined
#else
#if (VDY_SIN_POS_GEAR < 0UL) || (VDY_SIN_POS_GEAR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_GEAR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_PBRK
#error The variable for the parameter "VDY_SIN_POS_PBRK" is not defined
#else
#if (VDY_SIN_POS_PBRK < 0UL) || (VDY_SIN_POS_PBRK > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_PBRK" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WDIR_FL
#error The variable for the parameter "VDY_SIN_POS_WDIR_FL" is not defined
#else
#if (VDY_SIN_POS_WDIR_FL < 0UL) || (VDY_SIN_POS_WDIR_FL > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WDIR_FL" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WDIR_FR
#error The variable for the parameter "VDY_SIN_POS_WDIR_FR" is not defined
#else
#if (VDY_SIN_POS_WDIR_FR < 0UL) || (VDY_SIN_POS_WDIR_FR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WDIR_FR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WDIR_RL
#error The variable for the parameter "VDY_SIN_POS_WDIR_RL" is not defined
#else
#if (VDY_SIN_POS_WDIR_RL < 0UL) || (VDY_SIN_POS_WDIR_RL > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WDIR_RL" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WDIR_RR
#error The variable for the parameter "VDY_SIN_POS_WDIR_RR" is not defined
#else
#if (VDY_SIN_POS_WDIR_RR < 0UL) || (VDY_SIN_POS_WDIR_RR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WDIR_RR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WTCKS_FL
#error The variable for the parameter "VDY_SIN_POS_WTCKS_FL" is not defined
#else
#if (VDY_SIN_POS_WTCKS_FL < 0UL) || (VDY_SIN_POS_WTCKS_FL > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WTCKS_FL" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WTCKS_FR
#error The variable for the parameter "VDY_SIN_POS_WTCKS_FR" is not defined
#else
#if (VDY_SIN_POS_WTCKS_FR < 0UL) || (VDY_SIN_POS_WTCKS_FR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WTCKS_FR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WTCKS_RL
#error The variable for the parameter "VDY_SIN_POS_WTCKS_RL" is not defined
#else
#if (VDY_SIN_POS_WTCKS_RL < 0UL) || (VDY_SIN_POS_WTCKS_RL > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WTCKS_RL" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WTCKS_RR
#error The variable for the parameter "VDY_SIN_POS_WTCKS_RR" is not defined
#else
#if (VDY_SIN_POS_WTCKS_RR < 0UL) || (VDY_SIN_POS_WTCKS_RR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WTCKS_RR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WVEL_FL
#error The variable for the parameter "VDY_SIN_POS_WVEL_FL" is not defined
#else
#if (VDY_SIN_POS_WVEL_FL < 0UL) || (VDY_SIN_POS_WVEL_FL > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WVEL_FL" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WVEL_FR
#error The variable for the parameter "VDY_SIN_POS_WVEL_FR" is not defined
#else
#if (VDY_SIN_POS_WVEL_FR < 0UL) || (VDY_SIN_POS_WVEL_FR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WVEL_FR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WVEL_RL
#error The variable for the parameter "VDY_SIN_POS_WVEL_RL" is not defined
#else
#if (VDY_SIN_POS_WVEL_RL < 0UL) || (VDY_SIN_POS_WVEL_RL > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WVEL_RL" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_SIN_POS_WVEL_RR
#error The variable for the parameter "VDY_SIN_POS_WVEL_RR" is not defined
#else
#if (VDY_SIN_POS_WVEL_RR < 0UL) || (VDY_SIN_POS_WVEL_RR > 4294967295UL)
#error The value of the variable for the parameter "VDY_SIN_POS_WVEL_RR" is outside of the range 0UL to 4294967295UL
#endif
#endif

#ifndef VDY_LONG_MOT_STATE_MOVE
#error The variable for the parameter "VDY_LONG_MOT_STATE_MOVE" is not defined
#else
#if (VDY_LONG_MOT_STATE_MOVE < 0) || (VDY_LONG_MOT_STATE_MOVE > 255)
#error The value of the variable for the parameter "VDY_LONG_MOT_STATE_MOVE" is outside of the range 0 to 255
#endif
#endif

#ifndef VDY_LONG_MOT_STATE_MOVE_FWD
#error The variable for the parameter "VDY_LONG_MOT_STATE_MOVE_FWD" is not defined
#else
#if (VDY_LONG_MOT_STATE_MOVE_FWD < 0) || (VDY_LONG_MOT_STATE_MOVE_FWD > 255)
#error The value of the variable for the parameter "VDY_LONG_MOT_STATE_MOVE_FWD" is outside of the range 0 to 255
#endif
#endif

#ifndef VDY_LONG_MOT_STATE_MOVE_RWD
#error The variable for the parameter "VDY_LONG_MOT_STATE_MOVE_RWD" is not defined
#else
#if (VDY_LONG_MOT_STATE_MOVE_RWD < 0) || (VDY_LONG_MOT_STATE_MOVE_RWD > 255)
#error The value of the variable for the parameter "VDY_LONG_MOT_STATE_MOVE_RWD" is outside of the range 0 to 255
#endif
#endif

#ifndef VDY_LONG_MOT_STATE_STDST
#error The variable for the parameter "VDY_LONG_MOT_STATE_STDST" is not defined
#else
#if (VDY_LONG_MOT_STATE_STDST < 0) || (VDY_LONG_MOT_STATE_STDST > 255)
#error The value of the variable for the parameter "VDY_LONG_MOT_STATE_STDST" is outside of the range 0 to 255
#endif
#endif

#define CALL_EVENT                     (-1)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

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
extern void ALN_percenatge_probability_Init(rtDW_ALN_percenatge_probability
  *localDW);
extern void ALN_percenatge_probability(uint8_T rtu_ALN_e_Direction, uint8_T
  rtu_Previous_Probability, uint8_T rtu_Presentproability,
  rtB_ALN_percenatge_probability *localB, rtDW_ALN_percenatge_probability
  *localDW);
extern void vdy_mot_st_Get_IO_State2(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State2_vdy_mot_st *localB, uint32_T rtp_Filter);
extern void vdy_mot_st_whl_dir(const vdy_mot_states_t *rtu_0, vdy_mot_states_t
  *rty_Out1);
extern void prob_calc_brake_trq(percentage_t rtu_y2, percentage_t rtu_y1,
  percentage_t rtu_x2, percentage_t rtu_x1, uint16_T rtu_brake_torque,
  rtB_prob_calc_brake_trq *localB);
extern void down_counter_veh_velo_mot_st(percentage_t rtu_y2, percentage_t
  rtu_y1, uint8_T rtu_counter_down, percentage_t rtu_dT,
  rtB_down_counter_veh_velo_mot_s *localB);
extern void up_counter_veh_velo_mot_st(percentage_t rtu_y2, percentage_t rtu_y1,
  uint8_T rtu_counter_up, percentage_t rtu_dT, rtB_up_counter_veh_velo_mot_st
  *localB);
extern void whl_motion_percentage(uint8_T rtu_whl_direction, uint8_T
  rtu_whl_direction_valid, const percentage_t rtu_whl_direction_percentage[18],
  real32_T rtu_veh_velo, real32_T rtu_veh_velocity_var, const percentage_t
  rtu_vdy_yaw_rate_to_perc[9], rtB_whl_motion_percentage *localB);
extern void down_counter_prob_calc(percentage_t rtu_y2, percentage_t rtu_y1,
  percentage_t rtu_dT, uint8_T rtu_counter, rtB_down_counter_prob_calc *localB);
extern void Whl_pulse_perecentage(const percentage_t rtu_whl_puls_percentage[15],
  uint8_T rtu_diff_whl_puls, uint8_T rtu_whl_puls_valid,
  rtB_Whl_pulse_perecentage *localB, rtDW_Whl_pulse_perecentage *localDW);

#endif                                 /* RTW_HEADER_vdy_mot_st_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
