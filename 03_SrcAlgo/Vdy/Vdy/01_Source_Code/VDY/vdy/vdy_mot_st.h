/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_mot_st.h
   Real-Time Workshop code generated for Simulink model vdy_mot_st.
   Model version                        : 1.4942
   Real-Time Workshop file version      : 7.6.2  (R2010bSP2)  02-Mar-2012
   Real-Time Workshop file generated on : Mon Nov 11 16:06:53 2019
   TLC version                          : 7.6 (Jul 13 2010)
   C source code generated on           : Mon Nov 11 16:06:54 2019
   AUTOR                                : spruckj
   DESCRIPTION                          : vdy motion state estimation, use
   a bayes net to compute a motion state
   and quality for this state
   VERSION:                             : $Revision: 1.9 $
 **************************************************************************** */
/* date: 2019-06-19, reviewer: Ramachandra Chinnaswamy-EXT (uids4735), reason: "Legacy code of ARS4xx, alreay reviewed and working fine without any critical issue" */
/* PRQA S 0314, 0380, 1850, 1860, 1862, 1863, 2211, 2741, 2742, 2880, 2982, 2983, 2991, 2992, 2995, 2996, 3119, 3120, 3212, 3227, 3344, 3449, 3451, 3469, 3673, 3678, 3715, 4115, 4304, 4305, 4393, 4394, 4395, 4404, 4440, 4443, 4491, 4499, 4533, 4534, 1505, 1531, 1532, 1533, 1534, 4116, 4558, 4436  EOF */
#ifndef RTW_HEADER_vdy_mot_st_h_
#define RTW_HEADER_vdy_mot_st_h_
#ifndef vdy_mot_st_COMMON_INCLUDES_
# define vdy_mot_st_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "algo_glob.h"
#include "cml_ext.h"
#include "vdy_glob.h"
#endif                                 /* vdy_mot_st_COMMON_INCLUDES_ */

#include "vdy_mot_st_types.h"

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

/* Block signals for system '<S1>/ALN_Fwd' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S12>/Data Type Conversion' */
} rtB_ALN_percenatge_probability;

/* Block states (auto storage) for system '<S1>/ALN_Fwd' */
typedef struct {
  real32_T FWD_Init1_DSTATE;           /* '<S12>/FWD_Init1' */
  uint8_T Init2_DSTATE;                /* '<S18>/Init2' */
  uint8_T ALN_e_Direction_Prev_DSTATE; /* '<S18>/ALN_e_Direction_Prev' */
  uint8_T Init2_DSTATE_p;              /* '<S19>/Init2' */
  uint8_T FWD_Init_DSTATE;             /* '<S19>/FWD_Init' */
} rtDW_ALN_percenatge_probability;

/* Block signals for system '<S1>/Get_IO_State2' */
typedef struct {
  uint8_T IndexVector;                 /* '<S17>/Index Vector' */
} rtB_Get_IO_State2_vdy_mot_st;

/* Block signals for system '<S48>/prob_calc_brake_trq' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S52>/Data Type Conversion' */
} rtB_prob_calc_brake_trq;

/* Block signals for system '<S64>/fwd_down_counter_veh_velo_mot_st' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S66>/Data Type Conversion' */
} rtB_down_counter_veh_velo_mot_s;

/* Block signals for system '<S64>/fwd_up_counter_veh_velo_mot_st' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S67>/Data Type Conversion' */
} rtB_up_counter_veh_velo_mot_st;

/* Block signals for system '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
typedef struct {
  percentage_t fwd_percentage;         /* '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
  percentage_t ss_percentage;          /* '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
  percentage_t rws_percentage;         /* '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
} rtB_whl_motion_percentage;

/* Block signals for system '<S94>/prob_counter_calc_whl_puls_perc' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S99>/Data Type Conversion' */
} rtB_down_counter_prob_calc;

/* Block signals for system '<S10>/whl_puls_fl_percentage' */
typedef struct {
  vdy_mot_states_t whl_puls_fl_percentage;/* '<S90>/Bus Creator' */
  rtB_down_counter_prob_calc prob_counter_calc_whl_puls_pe_j;/* '<S96>/prob_counter_calc_whl_puls_perc' */
  rtB_down_counter_prob_calc prob_counter_calc_whl_puls_pe_b;/* '<S95>/prob_counter_calc_whl_puls_perc' */
  rtB_down_counter_prob_calc prob_counter_calc_whl_puls_perc;/* '<S94>/prob_counter_calc_whl_puls_perc' */
} rtB_Whl_pulse_perecentage;

/* Block states (auto storage) for system '<S10>/whl_puls_fl_percentage' */
typedef struct {
  uint8_T cnt_ramp_DSTATE;             /* '<S90>/cnt_ramp' */
  uint8_T cnt_delay_DSTATE;            /* '<S90>/cnt_delay' */
} rtDW_Whl_pulse_perecentage;

/* Block signals (auto storage) */
typedef struct {
  rtB_Whl_pulse_perecentage whl_puls_rr_percentage;/* '<S10>/whl_puls_rr_percentage' */
  rtB_Whl_pulse_perecentage whl_puls_rl_percentage;/* '<S10>/whl_puls_rl_percentage' */
  rtB_Whl_pulse_perecentage whl_puls_fr_percentage;/* '<S10>/whl_puls_fr_percentage' */
  rtB_Whl_pulse_perecentage whl_puls_fl_percentage;/* '<S10>/whl_puls_fl_percentage' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State8;/* '<S10>/Get_IO_State8' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State3;/* '<S10>/Get_IO_State3' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2;/* '<S10>/Get_IO_State2' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State1;/* '<S10>/Get_IO_State1' */
  rtB_whl_motion_percentage sf_whl_rr_motion_percentageComp;/* '<S9>/whl_rr_motion_percentage                          Compute probabilities associated with rear right wheel direction' */
  rtB_whl_motion_percentage sf_whl_rl_motion_percentageComp;/* '<S9>/whl_rl_motion_percentage                          Compute probabilities associated with rear left wheel direction' */
  rtB_whl_motion_percentage sf_whl_fr_motion_percentageComp;/* '<S9>/whl_fr_motion_percentage                          Compute probabilities associated with front right wheel direction' */
  rtB_whl_motion_percentage sf_whl_fl_motion_percentageComp;/* '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State4;/* '<S9>/Get_IO_State4' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State3_e;/* '<S9>/Get_IO_State3' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_f;/* '<S9>/Get_IO_State2' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State1_i;/* '<S9>/Get_IO_State1' */
  rtB_up_counter_veh_velo_mot_st ss_up_counter_veh_velo_mot_st;/* '<S64>/ss_up_counter_veh_velo_mot_st' */
  rtB_down_counter_veh_velo_mot_s ss_down_counter_veh_velo_mot_st;/* '<S64>/ss_down_counter_veh_velo_mot_st' */
  rtB_up_counter_veh_velo_mot_st rws_up_counter_veh_velo_mot_st;/* '<S64>/rws_up_counter_veh_velo_mot_st' */
  rtB_down_counter_veh_velo_mot_s rws_down_counter_veh_velo_mot_s;/* '<S64>/rws_down_counter_veh_velo_mot_st' */
  rtB_up_counter_veh_velo_mot_st fwd_up_counter_veh_velo_mot_st;/* '<S64>/fwd_up_counter_veh_velo_mot_st' */
  rtB_down_counter_veh_velo_mot_s fwd_down_counter_veh_velo_mot_s;/* '<S64>/fwd_down_counter_veh_velo_mot_st' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_e;/* '<S7>/Get_IO_State2' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_d0;/* '<S6>/Get_IO_State2' */
  rtB_prob_calc_brake_trq prob_calc_brake_trq_d;/* '<S50>/prob_calc_brake_trq' */
  rtB_prob_calc_brake_trq prob_calc_brake_trq_m;/* '<S49>/prob_calc_brake_trq' */
  rtB_prob_calc_brake_trq prob_calc_brake_trq_o;/* '<S48>/prob_calc_brake_trq' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_d;/* '<S5>/Get_IO_State2' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State8_b;/* '<S30>/Get_IO_State8' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State3_eg;/* '<S30>/Get_IO_State3' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_m1;/* '<S30>/Get_IO_State2' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State1_k;/* '<S30>/Get_IO_State1' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State4_b;/* '<S26>/Get_IO_State4' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State3_b;/* '<S26>/Get_IO_State3' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_es;/* '<S26>/Get_IO_State2' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State1_d;/* '<S26>/Get_IO_State1' */
  rtB_Get_IO_State2_vdy_mot_st Get_IO_State2_m;/* '<S1>/Get_IO_State2' */
  rtB_ALN_percenatge_probability ALN_Ss;/* '<S1>/ALN_Ss' */
  rtB_ALN_percenatge_probability ALN_Rws;/* '<S1>/ALN_Rws' */
  rtB_ALN_percenatge_probability ALN_Fwd;/* '<S1>/ALN_Fwd' */
} BlockIO_vdy_mot_st;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T UD_DSTATE;                  /* '<S135>/UD' */
  real32_T UD_DSTATE_k;                /* '<S134>/UD' */
  real32_T T3_DSTATE;                  /* '<S136>/T3' */
  real32_T T2_DSTATE;                  /* '<S136>/T2' */
  real32_T T1_DSTATE;                  /* '<S136>/T1' */
  real32_T T0_DSTATE;                  /* '<S136>/T0' */
  real32_T T4_DSTATE;                  /* '<S136>/T4' */
  real32_T T5_DSTATE;                  /* '<S136>/T5' */
  real32_T T6_DSTATE;                  /* '<S136>/T6' */
  int8_T mot_count_delay_DSTATE;       /* '<S1>/mot_count_delay' */
  uint8_T cnt_delay_down_DSTATE;       /* '<S8>/cnt_delay_down' */
  uint8_T cnt_delay_up_DSTATE;         /* '<S8>/cnt_delay_up' */
  percentage_t lastrvs_DSTATE;         /* '<S6>/last rvs' */
  percentage_t lastss_DSTATE;          /* '<S6>/last ss' */
  percentage_t lastfwd_DSTATE;         /* '<S6>/last fwd' */
  uint8_T FWD_Init7_DSTATE;            /* '<S1>/FWD_Init7' */
  uint8_T SS_Init6_DSTATE;             /* '<S1>/SS_Init6' */
  uint8_T RWS_Init5_DSTATE;            /* '<S1>/RWS_Init5' */
  uint8_T FWD_Init1_DSTATE;            /* '<S1>/FWD_Init1' */
  uint8_T FWD_Init3_DSTATE;            /* '<S1>/FWD_Init3' */
  uint8_T FWD_Init4_DSTATE;            /* '<S1>/FWD_Init4' */
  rtDW_Whl_pulse_perecentage whl_puls_rr_percentage;/* '<S10>/whl_puls_rr_percentage' */
  rtDW_Whl_pulse_perecentage whl_puls_rl_percentage;/* '<S10>/whl_puls_rl_percentage' */
  rtDW_Whl_pulse_perecentage whl_puls_fr_percentage;/* '<S10>/whl_puls_fr_percentage' */
  rtDW_Whl_pulse_perecentage whl_puls_fl_percentage;/* '<S10>/whl_puls_fl_percentage' */
  rtDW_ALN_percenatge_probability ALN_Ss;/* '<S1>/ALN_Ss' */
  rtDW_ALN_percenatge_probability ALN_Rws;/* '<S1>/ALN_Rws' */
  rtDW_ALN_percenatge_probability ALN_Fwd;/* '<S1>/ALN_Fwd' */
} D_Work_vdy_mot_st;

/* Model entry point functions */
extern void vdy_mot_st_initialize(boolean_T firstTime, BlockIO_vdy_mot_st
  *vdy_mot_st_B, D_Work_vdy_mot_st *vdy_mot_st_DWork);
extern void vdy_mot_st_step(BlockIO_vdy_mot_st *vdy_mot_st_B, D_Work_vdy_mot_st *
  vdy_mot_st_DWork, VDYInputData_t *vdy_mot_st_U_VDYInputData, VDYInternalData_t
  *vdy_mot_st_U_VDYInternalData_in, uint8_T vdy_mot_st_U_e_Direction, real32_T
  vdy_mot_st_U_RawVelo, vdy_bayes_mot_states_t *vdy_mot_st_Y_vdy_mot_st_out);

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const percentage_t vdy_ALN_to_perc_p[15];
extern const percentage_t vdy_brake_torque_to_perc_p[18];
extern const percentage_t vdy_cpt_pre_break_torque_p[4];
extern const percentage_t vdy_cpt_pre_gear_parking_p[16];
extern const percentage_t vdy_cpt_pulse_velo_dir_p[4];
extern const percentage_t vdy_cpt_pulse_velo_p[4];
extern const percentage_t vdy_cpt_whl_pulse_p[16];
extern const percentage_t vdy_gear_shift_to_perc_p[18];
extern const percentage_t vdy_parking_break_to_perc_p[9];
extern const percentage_t vdy_veh_velocity_to_perc_p[15];
extern const percentage_t vdy_whl_direction_to_perc_p[18];
extern const percentage_t vdy_whl_puls_to_perc_p[15];
extern const percentage_t vdy_yaw_rate_to_perc_p[9];

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
 * '<Root>' : vdy_mot_st
 * '<S1>'   : vdy_mot_st/ALN_direction
 * '<S2>'   : vdy_mot_st/Model Info
 * '<S3>'   : vdy_mot_st/WhlVel
 * '<S4>'   : vdy_mot_st/bayes_net
 * '<S5>'   : vdy_mot_st/brake_torque
 * '<S6>'   : vdy_mot_st/gear_shift
 * '<S7>'   : vdy_mot_st/parking_brake
 * '<S8>'   : vdy_mot_st/veh_velo
 * '<S9>'   : vdy_mot_st/whl_direction
 * '<S10>'  : vdy_mot_st/whl_pulse
 * '<S11>'  : vdy_mot_st/yaw_rate
 * '<S12>'  : vdy_mot_st/ALN_direction/ALN_Fwd
 * '<S13>'  : vdy_mot_st/ALN_direction/ALN_Rws
 * '<S14>'  : vdy_mot_st/ALN_direction/ALN_Ss
 * '<S15>'  : vdy_mot_st/ALN_direction/ALN_direction_percentage
 * '<S16>'  : vdy_mot_st/ALN_direction/ALN_direction_percentage1
 * '<S17>'  : vdy_mot_st/ALN_direction/Get_IO_State2
 * '<S18>'  : vdy_mot_st/ALN_direction/ALN_Fwd/Subsystem
 * '<S19>'  : vdy_mot_st/ALN_direction/ALN_Fwd/Subsystem1
 * '<S20>'  : vdy_mot_st/ALN_direction/ALN_Rws/Subsystem
 * '<S21>'  : vdy_mot_st/ALN_direction/ALN_Rws/Subsystem1
 * '<S22>'  : vdy_mot_st/ALN_direction/ALN_Ss/Subsystem
 * '<S23>'  : vdy_mot_st/ALN_direction/ALN_Ss/Subsystem1
 * '<S24>'  : vdy_mot_st/bayes_net/bayes_break_torqu
 * '<S25>'  : vdy_mot_st/bayes_net/bayes_gear_parking_break
 * '<S26>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo
 * '<S27>'  : vdy_mot_st/bayes_net/bayes_puls_velo_dir
 * '<S28>'  : vdy_mot_st/bayes_net/bayes_whl_direction
 * '<S29>'  : vdy_mot_st/bayes_net/bayes_whl_pulse
 * '<S30>'  : vdy_mot_st/bayes_net/check_whl_ALN
 * '<S31>'  : vdy_mot_st/bayes_net/state_decider
 * '<S32>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo/Get_IO_State1
 * '<S33>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo/Get_IO_State2
 * '<S34>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo/Get_IO_State3
 * '<S35>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo/Get_IO_State4
 * '<S36>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo/Wheel Tick Consider
 * '<S37>'  : vdy_mot_st/bayes_net/bayes_puls_veh_velo/any_whl_valid
 * '<S38>'  : vdy_mot_st/bayes_net/check_whl_ALN/ALN_dir
 * '<S39>'  : vdy_mot_st/bayes_net/check_whl_ALN/Get_IO_State1
 * '<S40>'  : vdy_mot_st/bayes_net/check_whl_ALN/Get_IO_State2
 * '<S41>'  : vdy_mot_st/bayes_net/check_whl_ALN/Get_IO_State3
 * '<S42>'  : vdy_mot_st/bayes_net/check_whl_ALN/Get_IO_State8
 * '<S43>'  : vdy_mot_st/bayes_net/check_whl_ALN/whl_dir
 * '<S44>'  : vdy_mot_st/bayes_net/state_decider/state_decider
 * '<S45>'  : vdy_mot_st/brake_torque/Get_IO_State2
 * '<S46>'  : vdy_mot_st/brake_torque/brake_torque_percentage
 * '<S47>'  : vdy_mot_st/brake_torque/brake_torque_percentage/brake_torque_percentage_fcn
 * '<S48>'  : vdy_mot_st/brake_torque/brake_torque_percentage/fwd_brake_torque_to_percentage
 * '<S49>'  : vdy_mot_st/brake_torque/brake_torque_percentage/rws_brake_torque_to_percentage
 * '<S50>'  : vdy_mot_st/brake_torque/brake_torque_percentage/ss_brake_torque_to_percentage
 * '<S51>'  : vdy_mot_st/brake_torque/brake_torque_percentage/fwd_brake_torque_to_percentage/get_percentage
 * '<S52>'  : vdy_mot_st/brake_torque/brake_torque_percentage/fwd_brake_torque_to_percentage/prob_calc_brake_trq
 * '<S53>'  : vdy_mot_st/brake_torque/brake_torque_percentage/rws_brake_torque_to_percentage/get_percentage
 * '<S54>'  : vdy_mot_st/brake_torque/brake_torque_percentage/rws_brake_torque_to_percentage/prob_calc_brake_trq
 * '<S55>'  : vdy_mot_st/brake_torque/brake_torque_percentage/ss_brake_torque_to_percentage/get_percentage
 * '<S56>'  : vdy_mot_st/brake_torque/brake_torque_percentage/ss_brake_torque_to_percentage/prob_calc_brake_trq
 * '<S57>'  : vdy_mot_st/gear_shift/Get_IO_State2
 * '<S58>'  : vdy_mot_st/gear_shift/gear_shift_percentage
 * '<S59>'  : vdy_mot_st/parking_brake/Get_IO_State2
 * '<S60>'  : vdy_mot_st/parking_brake/parking_break_percentage
 * '<S61>'  : vdy_mot_st/veh_velo/get_percentage_fwd
 * '<S62>'  : vdy_mot_st/veh_velo/get_percentage_rws
 * '<S63>'  : vdy_mot_st/veh_velo/get_percentage_ss
 * '<S64>'  : vdy_mot_st/veh_velo/prob_calc_counter
 * '<S65>'  : vdy_mot_st/veh_velo/veh_velocity_percentage
 * '<S66>'  : vdy_mot_st/veh_velo/prob_calc_counter/fwd_down_counter_veh_velo_mot_st
 * '<S67>'  : vdy_mot_st/veh_velo/prob_calc_counter/fwd_up_counter_veh_velo_mot_st
 * '<S68>'  : vdy_mot_st/veh_velo/prob_calc_counter/rws_down_counter_veh_velo_mot_st
 * '<S69>'  : vdy_mot_st/veh_velo/prob_calc_counter/rws_up_counter_veh_velo_mot_st
 * '<S70>'  : vdy_mot_st/veh_velo/prob_calc_counter/ss_down_counter_veh_velo_mot_st
 * '<S71>'  : vdy_mot_st/veh_velo/prob_calc_counter/ss_up_counter_veh_velo_mot_st
 * '<S72>'  : vdy_mot_st/veh_velo/prob_calc_counter/fwd_down_counter_veh_velo_mot_st/Increment Real World
 * '<S73>'  : vdy_mot_st/veh_velo/prob_calc_counter/fwd_up_counter_veh_velo_mot_st/Increment Real World
 * '<S74>'  : vdy_mot_st/veh_velo/prob_calc_counter/rws_down_counter_veh_velo_mot_st/Increment Real World
 * '<S75>'  : vdy_mot_st/veh_velo/prob_calc_counter/rws_up_counter_veh_velo_mot_st/Increment Real World
 * '<S76>'  : vdy_mot_st/veh_velo/prob_calc_counter/ss_down_counter_veh_velo_mot_st/Increment Real World
 * '<S77>'  : vdy_mot_st/veh_velo/prob_calc_counter/ss_up_counter_veh_velo_mot_st/Increment Real World
 * '<S78>'  : vdy_mot_st/whl_direction/Get_IO_State1
 * '<S79>'  : vdy_mot_st/whl_direction/Get_IO_State2
 * '<S80>'  : vdy_mot_st/whl_direction/Get_IO_State3
 * '<S81>'  : vdy_mot_st/whl_direction/Get_IO_State4
 * '<S82>'  : vdy_mot_st/whl_direction/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction
 * '<S83>'  : vdy_mot_st/whl_direction/whl_fr_motion_percentage                          Compute probabilities associated with front right wheel direction
 * '<S84>'  : vdy_mot_st/whl_direction/whl_rl_motion_percentage                          Compute probabilities associated with rear left wheel direction
 * '<S85>'  : vdy_mot_st/whl_direction/whl_rr_motion_percentage                          Compute probabilities associated with rear right wheel direction
 * '<S86>'  : vdy_mot_st/whl_pulse/Get_IO_State1
 * '<S87>'  : vdy_mot_st/whl_pulse/Get_IO_State2
 * '<S88>'  : vdy_mot_st/whl_pulse/Get_IO_State3
 * '<S89>'  : vdy_mot_st/whl_pulse/Get_IO_State8
 * '<S90>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage
 * '<S91>'  : vdy_mot_st/whl_pulse/whl_puls_fr_percentage
 * '<S92>'  : vdy_mot_st/whl_pulse/whl_puls_rl_percentage
 * '<S93>'  : vdy_mot_st/whl_pulse/whl_puls_rr_percentage
 * '<S94>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/fwd_down_prob
 * '<S95>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/rws_down_prob
 * '<S96>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/ss_down_prob
 * '<S97>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/whl_puls_fl_percentage
 * '<S98>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/fwd_down_prob/get_percentage
 * '<S99>'  : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/fwd_down_prob/prob_counter_calc_whl_puls_perc
 * '<S100>' : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/rws_down_prob/get_percentage
 * '<S101>' : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/rws_down_prob/prob_counter_calc_whl_puls_perc
 * '<S102>' : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/ss_down_prob/get_percentage
 * '<S103>' : vdy_mot_st/whl_pulse/whl_puls_fl_percentage/ss_down_prob/prob_counter_calc_whl_puls_perc
 * '<S104>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/fwd_down_prob
 * '<S105>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/rws_down_prob
 * '<S106>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/ss_down_prob
 * '<S107>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/whl_puls_fl_percentage
 * '<S108>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/fwd_down_prob/get_percentage
 * '<S109>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/fwd_down_prob/prob_counter_calc_whl_puls_perc
 * '<S110>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/rws_down_prob/get_percentage
 * '<S111>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/rws_down_prob/prob_counter_calc_whl_puls_perc
 * '<S112>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/ss_down_prob/get_percentage
 * '<S113>' : vdy_mot_st/whl_pulse/whl_puls_fr_percentage/ss_down_prob/prob_counter_calc_whl_puls_perc
 * '<S114>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/fwd_down_prob
 * '<S115>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/rws_down_prob
 * '<S116>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/ss_down_prob
 * '<S117>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/whl_puls_fl_percentage
 * '<S118>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/fwd_down_prob/get_percentage
 * '<S119>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/fwd_down_prob/prob_counter_calc_whl_puls_perc
 * '<S120>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/rws_down_prob/get_percentage
 * '<S121>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/rws_down_prob/prob_counter_calc_whl_puls_perc
 * '<S122>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/ss_down_prob/get_percentage
 * '<S123>' : vdy_mot_st/whl_pulse/whl_puls_rl_percentage/ss_down_prob/prob_counter_calc_whl_puls_perc
 * '<S124>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/fwd_down_prob
 * '<S125>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/rws_down_prob
 * '<S126>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/ss_down_prob
 * '<S127>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/whl_puls_fl_percentage
 * '<S128>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/fwd_down_prob/get_percentage
 * '<S129>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/fwd_down_prob/prob_counter_calc_whl_puls_perc
 * '<S130>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/rws_down_prob/get_percentage
 * '<S131>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/rws_down_prob/prob_counter_calc_whl_puls_perc
 * '<S132>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/ss_down_prob/get_percentage
 * '<S133>' : vdy_mot_st/whl_pulse/whl_puls_rr_percentage/ss_down_prob/prob_counter_calc_whl_puls_perc
 * '<S134>' : vdy_mot_st/yaw_rate/Difference
 * '<S135>' : vdy_mot_st/yaw_rate/Transfer Fcn First Order
 * '<S136>' : vdy_mot_st/yaw_rate/eight_stage_mean_filter
 * '<S137>' : vdy_mot_st/yaw_rate/threshold_yaw_rate
 * '<S138>' : vdy_mot_st/yaw_rate/yaw_rate_percentage
 */
#endif                                 /* RTW_HEADER_vdy_mot_st_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
