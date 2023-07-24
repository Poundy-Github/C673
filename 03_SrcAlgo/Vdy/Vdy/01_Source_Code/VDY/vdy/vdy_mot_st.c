/*! \file **********************************************************************
   COMPANY:                               Continental Temic, BC DAS, A.D.C. GmbH
   COMPONENT                            : VDY (Vehicle Dynamics Observer)
   File: vdy_mot_st.c
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
#include "vdy_mot_st.h"
#include "vdy_mot_st_private.h"

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
 * Initial conditions for atomic system:
 *    '<S1>/ALN_Fwd'
 *    '<S1>/ALN_Rws'
 *    '<S1>/ALN_Ss'
 */
void ALN_percenatge_probability_Init(rtDW_ALN_percenatge_probability *localDW)
{
  /* InitializeConditions for UnitDelay: '<S18>/Init2' */
  localDW->Init2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S19>/Init2' */
  localDW->Init2_DSTATE_p = 1U;

  /* InitializeConditions for UnitDelay: '<S19>/FWD_Init' */
  localDW->FWD_Init_DSTATE = 33U;
}

/*
 * Output and update for atomic system:
 *    '<S1>/ALN_Fwd'
 *    '<S1>/ALN_Rws'
 *    '<S1>/ALN_Ss'
 */
void ALN_percenatge_probability(uint8_T rtu_ALN_e_Direction, uint8_T
  rtu_Previous_Probability, uint8_T rtu_Presentproability,
  rtB_ALN_percenatge_probability *localB, rtDW_ALN_percenatge_probability
  *localDW)
{
  boolean_T rtb_RelationalOperator;
  real32_T tmp;

  /* Switch: '<S18>/Switch' incorporates:
   *  UnitDelay: '<S18>/ALN_e_Direction_Prev'
   *  UnitDelay: '<S18>/Init2'
   */
  if (localDW->Init2_DSTATE != 0) {
    localDW->ALN_e_Direction_Prev_DSTATE = rtu_ALN_e_Direction;
  }

  /* RelationalOperator: '<S12>/Relational Operator' */
  rtb_RelationalOperator = (localDW->ALN_e_Direction_Prev_DSTATE !=
    rtu_ALN_e_Direction);

  /* Switch: '<S12>/Switch1' */
  if (rtb_RelationalOperator) {
    localDW->FWD_Init_DSTATE = rtu_Previous_Probability;
  } else {
    /* Switch: '<S19>/Switch' incorporates:
     *  UnitDelay: '<S19>/FWD_Init'
     *  UnitDelay: '<S19>/Init2'
     */
    if (localDW->Init2_DSTATE_p != 0) {
      localDW->FWD_Init_DSTATE = rtu_Presentproability;
    }
  }

  /* Switch: '<S12>/Switch2' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant2'
   *  Sum: '<S12>/fwd_p1'
   *  UnitDelay: '<S12>/FWD_Init1'
   */
  if (rtb_RelationalOperator) {
    localDW->FWD_Init1_DSTATE = 0.0F;
  } else {
    localDW->FWD_Init1_DSTATE = 1.0F + localDW->FWD_Init1_DSTATE;
  }

  /* Switch: '<S12>/Switch3' incorporates:
   *  Constant: '<S12>/Constant3'
   *  RelationalOperator: '<S12>/Relational Operator1'
   */
  if (localDW->FWD_Init1_DSTATE > 15.0F) {
    localDW->FWD_Init1_DSTATE = 15.0F;
  }

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S12>/Constant'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/fwd_p'
   */
  tmp = ((((real32_T)(rtu_Presentproability - localDW->FWD_Init_DSTATE)) / 15.0F)
         * localDW->FWD_Init1_DSTATE) + ((real32_T)localDW->FWD_Init_DSTATE);
  if (tmp < 256.0F) {
    if (tmp >= 0.0F) {
      localB->DataTypeConversion = (uint8_T)tmp;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    localB->DataTypeConversion = MAX_uint8_T;
  }

  /* Update for UnitDelay: '<S18>/Init2' incorporates:
   *  Constant: '<S18>/Constant'
   */
  localDW->Init2_DSTATE = 0U;

  /* Update for UnitDelay: '<S18>/ALN_e_Direction_Prev' */
  localDW->ALN_e_Direction_Prev_DSTATE = rtu_ALN_e_Direction;

  /* Update for UnitDelay: '<S19>/Init2' incorporates:
   *  Constant: '<S19>/Constant'
   */
  localDW->Init2_DSTATE_p = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Get_IO_State2'
 *    '<S26>/Get_IO_State1'
 *    '<S26>/Get_IO_State2'
 *    '<S26>/Get_IO_State3'
 *    '<S26>/Get_IO_State4'
 *    '<S30>/Get_IO_State1'
 *    '<S30>/Get_IO_State2'
 *    '<S30>/Get_IO_State3'
 *    '<S30>/Get_IO_State8'
 *    '<S5>/Get_IO_State2'
 * ...
 */
void vdy_mot_st_Get_IO_State2(const uint8_T rtu_state_in[32],
  rtB_Get_IO_State2_vdy_mot_st *localB, uint32_T rtp_Filter)
{
  /* MultiPortSwitch: '<S17>/Index Vector' incorporates:
   *  Constant: '<S17>/Constant1'
   */
  localB->IndexVector = rtu_state_in[(rtp_Filter)];
}

/*
 * Output and update for action system:
 *    '<S30>/whl_dir'
 *    '<S30>/ALN_dir'
 */
void vdy_mot_st_whl_dir(const vdy_mot_states_t *rtu_0, vdy_mot_states_t
  *rty_Out1)
{
  /* Inport: '<S43>/In1' */
  (*rty_Out1) = (*rtu_0);
}

/*
 * Output and update for atomic system:
 *    '<S48>/prob_calc_brake_trq'
 *    '<S49>/prob_calc_brake_trq'
 *    '<S50>/prob_calc_brake_trq'
 */
void prob_calc_brake_trq(percentage_t rtu_y2, percentage_t rtu_y1, percentage_t
  rtu_x2, percentage_t rtu_x1, uint16_T rtu_brake_torque,
  rtB_prob_calc_brake_trq *localB)
{
  real32_T tmp;

  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  Gain: '<S52>/Gain'
   *  Product: '<S52>/Divide'
   *  Product: '<S52>/Divide1'
   *  Sum: '<S52>/Add'
   *  Sum: '<S52>/Add1'
   *  Sum: '<S52>/fwd_p'
   */
  tmp = (((real32_T)rtu_brake_torque) / (((real32_T)((((int32_T)(250U *
    ((uint32_T)rtu_y2))) << 2) - rtu_y1)) / ((real32_T)(rtu_x2 - rtu_x1)))) +
    ((real32_T)rtu_x1);
  if (tmp < 256.0F) {
    if (tmp >= 0.0F) {
      localB->DataTypeConversion = (uint8_T)tmp;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    localB->DataTypeConversion = MAX_uint8_T;
  }
}

/*
 * Output and update for atomic system:
 *    '<S64>/fwd_down_counter_veh_velo_mot_st'
 *    '<S64>/rws_down_counter_veh_velo_mot_st'
 *    '<S64>/ss_down_counter_veh_velo_mot_st'
 */
void down_counter_veh_velo_mot_st(percentage_t rtu_y2, percentage_t rtu_y1,
  uint8_T rtu_counter_down, percentage_t rtu_dT, rtB_down_counter_veh_velo_mot_s
  *localB)
{
  real32_T tmp;

  /* DataTypeConversion: '<S66>/Data Type Conversion' incorporates:
   *  Constant: '<S72>/FixPt Constant'
   *  Product: '<S66>/Divide'
   *  Product: '<S66>/Mult'
   *  Sum: '<S66>/Add'
   *  Sum: '<S66>/fwd_p'
   *  Sum: '<S72>/FixPt Sum1'
   */
  tmp = ((real32_T)rtu_y2) - ((((real32_T)(rtu_y2 - rtu_y1)) / ((real32_T)rtu_dT))
    * ((real32_T)((uint8_T)(((uint32_T)rtu_counter_down) + 1U))));
  if (tmp < 256.0F) {
    if (tmp >= 0.0F) {
      localB->DataTypeConversion = (uint8_T)tmp;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    localB->DataTypeConversion = MAX_uint8_T;
  }
}

/*
 * Output and update for atomic system:
 *    '<S64>/fwd_up_counter_veh_velo_mot_st'
 *    '<S64>/rws_up_counter_veh_velo_mot_st'
 *    '<S64>/ss_up_counter_veh_velo_mot_st'
 */
void up_counter_veh_velo_mot_st(percentage_t rtu_y2, percentage_t rtu_y1,
  uint8_T rtu_counter_up, percentage_t rtu_dT, rtB_up_counter_veh_velo_mot_st
  *localB)
{
  real32_T tmp;

  /* DataTypeConversion: '<S67>/Data Type Conversion' incorporates:
   *  Constant: '<S73>/FixPt Constant'
   *  Product: '<S67>/Divide'
   *  Product: '<S67>/Mult'
   *  Sum: '<S67>/Add'
   *  Sum: '<S67>/fwd_p'
   *  Sum: '<S73>/FixPt Sum1'
   */
  tmp = ((((real32_T)(rtu_y2 - rtu_y1)) / ((real32_T)rtu_dT)) * ((real32_T)
          ((uint8_T)(((uint32_T)rtu_counter_up) + 1U)))) + ((real32_T)rtu_y1);
  if (tmp < 256.0F) {
    if (tmp >= 0.0F) {
      localB->DataTypeConversion = (uint8_T)tmp;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    localB->DataTypeConversion = MAX_uint8_T;
  }
}

/*
 * Output and update for atomic system:
 *    '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction'
 *    '<S9>/whl_fr_motion_percentage                          Compute probabilities associated with front right wheel direction'
 *    '<S9>/whl_rl_motion_percentage                          Compute probabilities associated with rear left wheel direction'
 *    '<S9>/whl_rr_motion_percentage                          Compute probabilities associated with rear right wheel direction'
 */
void whl_motion_percentage(uint8_T rtu_whl_direction, uint8_T
  rtu_whl_direction_valid, const percentage_t rtu_whl_direction_percentage[18],
  real32_T rtu_veh_velo, real32_T rtu_veh_velocity_var, const percentage_t
  rtu_vdy_yaw_rate_to_perc[9], rtB_whl_motion_percentage *localB)
{
  /* Embedded MATLAB: '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
  /* Embedded MATLAB Function 'whl_motion_percentage                          Compute probabilities associated with front left wheel direction': '<S82>:1' */
  /*  compute the wheel direction quality */
  if (((uint32_T)rtu_whl_direction_valid) == ((uint32_T)VDY_IO_STATE_VALID)) {
    /* '<S82>:1:3' */
    /* '<S82>:1:4' */
    switch (rtu_whl_direction) {
     case 0U:
      /* unknown */
      /* '<S82>:1:6' */
      localB->fwd_percentage = rtu_whl_direction_percentage[2];

      /* '<S82>:1:7' */
      localB->ss_percentage = rtu_whl_direction_percentage[8];

      /* '<S82>:1:8' */
      localB->rws_percentage = rtu_whl_direction_percentage[14];
      break;

     case 1U:
      /* fwd     */
      /* '<S82>:1:10' */
      localB->fwd_percentage = rtu_whl_direction_percentage[0];

      /* '<S82>:1:11' */
      localB->ss_percentage = rtu_whl_direction_percentage[6];

      /* '<S82>:1:12' */
      localB->rws_percentage = rtu_whl_direction_percentage[12];
      break;

     case 2U:
      /* rws */
      /* '<S82>:1:14' */
      localB->fwd_percentage = rtu_whl_direction_percentage[1];

      /* '<S82>:1:15' */
      localB->ss_percentage = rtu_whl_direction_percentage[7];

      /* '<S82>:1:16' */
      localB->rws_percentage = rtu_whl_direction_percentage[13];
      break;

     default:
      /*  invalid */
      /* '<S82>:1:18' */
      localB->fwd_percentage = rtu_whl_direction_percentage[3];

      /* '<S82>:1:19' */
      localB->ss_percentage = rtu_whl_direction_percentage[9];

      /* '<S82>:1:20' */
      localB->rws_percentage = rtu_whl_direction_percentage[15];
      break;
    }
  } else {
    /*  invalid */
    /* '<S82>:1:23' */
    localB->fwd_percentage = rtu_whl_direction_percentage[3];

    /* '<S82>:1:24' */
    localB->ss_percentage = rtu_whl_direction_percentage[9];

    /* '<S82>:1:25' */
    localB->rws_percentage = rtu_whl_direction_percentage[15];
  }

  if (((rtu_veh_velocity_var <= 2500.0F) && (rtu_veh_velo < (((real32_T)
          rtu_vdy_yaw_rate_to_perc[5]) / 100.0F))) && (((uint32_T)
        rtu_whl_direction_valid) == ((uint32_T)VDY_IO_STATE_VALID))) {
    /* '<S82>:1:28' */
    /* '<S82>:1:30' */
    localB->fwd_percentage = rtu_whl_direction_percentage[4];

    /* '<S82>:1:31' */
    localB->ss_percentage = rtu_whl_direction_percentage[10];

    /* '<S82>:1:32' */
    localB->rws_percentage = rtu_whl_direction_percentage[16];
  }
}

/*
 * Output and update for atomic system:
 *    '<S94>/prob_counter_calc_whl_puls_perc'
 *    '<S95>/prob_counter_calc_whl_puls_perc'
 *    '<S96>/prob_counter_calc_whl_puls_perc'
 *    '<S104>/prob_counter_calc_whl_puls_perc'
 *    '<S105>/prob_counter_calc_whl_puls_perc'
 *    '<S106>/prob_counter_calc_whl_puls_perc'
 *    '<S114>/prob_counter_calc_whl_puls_perc'
 *    '<S115>/prob_counter_calc_whl_puls_perc'
 *    '<S116>/prob_counter_calc_whl_puls_perc'
 *    '<S124>/prob_counter_calc_whl_puls_perc'
 * ...
 */
void down_counter_prob_calc(percentage_t rtu_y2, percentage_t rtu_y1,
  percentage_t rtu_dT, uint8_T rtu_counter, rtB_down_counter_prob_calc *localB)
{
  real32_T tmp;

  /* DataTypeConversion: '<S99>/Data Type Conversion' incorporates:
   *  Product: '<S99>/Divide'
   *  Product: '<S99>/Mult'
   *  Sum: '<S99>/Add'
   *  Sum: '<S99>/fwd_p'
   */
  tmp = ((((real32_T)(rtu_y2 - rtu_y1)) / ((real32_T)rtu_dT)) * ((real32_T)
          rtu_counter)) + ((real32_T)rtu_y1);
  if (tmp < 256.0F) {
    if (tmp >= 0.0F) {
      localB->DataTypeConversion = (uint8_T)tmp;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    localB->DataTypeConversion = MAX_uint8_T;
  }
}

/*
 * Output and update for atomic system:
 *    '<S10>/whl_puls_fl_percentage'
 *    '<S10>/whl_puls_fr_percentage'
 *    '<S10>/whl_puls_rl_percentage'
 *    '<S10>/whl_puls_rr_percentage'
 */
void Whl_pulse_perecentage(const percentage_t rtu_whl_puls_percentage[15],
  uint8_T rtu_diff_whl_puls, uint8_T rtu_whl_puls_valid,
  rtB_Whl_pulse_perecentage *localB, rtDW_Whl_pulse_perecentage *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_cnt_ramp;
  percentage_t rtb_y1_j;
  percentage_t rtb_y2_e;
  percentage_t rtb_dT_p;
  percentage_t rtb_y1_jt;
  percentage_t rtb_y2_c;
  percentage_t rtb_dT_d;
  percentage_t rtb_y1_m;
  percentage_t rtb_y2_cs;
  percentage_t rtb_dT_n;
  uint8_T rtb_fwd_percentage_o;
  uint8_T rtb_ss_percentage_oc;
  uint8_T rtb_rws_percentage_n;
  int32_T tmp;

  /* UnitDelay: '<S90>/cnt_ramp' */
  rtb_cnt_ramp = localDW->cnt_ramp_DSTATE;

  /* Embedded MATLAB: '<S94>/get_percentage' */
  /* Embedded MATLAB Function 'whl_puls_percentage/fwd_down_prob/get_percentage': '<S98>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S98>:1:5' */
  rtb_y1_m = rtu_whl_puls_percentage[0];

  /* '<S98>:1:6' */
  rtb_y2_cs = rtu_whl_puls_percentage[1];

  /* '<S98>:1:7' */
  rtb_dT_n = rtu_whl_puls_percentage[2];

  /* Outputs for atomic SubSystem: '<S94>/prob_counter_calc_whl_puls_perc' */
  down_counter_prob_calc(rtb_y2_cs, rtb_y1_m, rtb_dT_n, rtb_cnt_ramp,
    &localB->prob_counter_calc_whl_puls_perc);

  /* end of Outputs for SubSystem: '<S94>/prob_counter_calc_whl_puls_perc' */

  /* Embedded MATLAB: '<S96>/get_percentage' */
  /* Embedded MATLAB Function 'whl_puls_percentage/ss_down_prob/get_percentage': '<S102>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S102>:1:5' */
  rtb_y1_j = rtu_whl_puls_percentage[5];

  /* '<S102>:1:6' */
  rtb_y2_e = rtu_whl_puls_percentage[6];

  /* '<S102>:1:7' */
  rtb_dT_p = rtu_whl_puls_percentage[7];

  /* Outputs for atomic SubSystem: '<S96>/prob_counter_calc_whl_puls_perc' */
  down_counter_prob_calc(rtb_y2_e, rtb_y1_j, rtb_dT_p, rtb_cnt_ramp,
    &localB->prob_counter_calc_whl_puls_pe_j);

  /* end of Outputs for SubSystem: '<S96>/prob_counter_calc_whl_puls_perc' */

  /* Embedded MATLAB: '<S95>/get_percentage' */
  /* Embedded MATLAB Function 'whl_puls_percentage/rws_down_prob/get_percentage': '<S100>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S100>:1:5' */
  rtb_y1_jt = rtu_whl_puls_percentage[10];

  /* '<S100>:1:6' */
  rtb_y2_c = rtu_whl_puls_percentage[11];

  /* '<S100>:1:7' */
  rtb_dT_d = rtu_whl_puls_percentage[12];

  /* Outputs for atomic SubSystem: '<S95>/prob_counter_calc_whl_puls_perc' */
  down_counter_prob_calc(rtb_y2_c, rtb_y1_jt, rtb_dT_d, rtb_cnt_ramp,
    &localB->prob_counter_calc_whl_puls_pe_b);

  /* end of Outputs for SubSystem: '<S95>/prob_counter_calc_whl_puls_perc' */

  /* Embedded MATLAB: '<S90>/whl_puls_fl_percentage' incorporates:
   *  UnitDelay: '<S90>/cnt_delay'
   */
  /* Embedded MATLAB Function 'whl_puls_percentage/whl_puls_fl_percentage': '<S97>:1' */
  /*  calculate the wheel puls quality */
  if (((uint32_T)rtu_whl_puls_valid) == ((uint32_T)VDY_IO_STATE_VALID)) {
    /* '<S97>:1:3' */
    if (rtu_diff_whl_puls != 0) {
      /* '<S97>:1:4' */
      /* '<S97>:1:5' */
      localDW->cnt_ramp_DSTATE = 0U;

      /* '<S97>:1:6' */
      localDW->cnt_delay_DSTATE = 0U;

      /* '<S97>:1:7' */
      rtb_fwd_percentage_o = rtu_whl_puls_percentage[0];

      /* '<S97>:1:8' */
      rtb_ss_percentage_oc = rtu_whl_puls_percentage[5];

      /* '<S97>:1:9' */
      rtb_rws_percentage_n = rtu_whl_puls_percentage[10];
    } else if (localDW->cnt_delay_DSTATE == rtu_whl_puls_percentage[3]) {
      /* '<S97>:1:11' */
      /* '<S97>:1:12' */
      tmp = (int32_T)(((uint32_T)rtb_cnt_ramp) + 1U);
      if (((uint32_T)tmp) > 255U) {
        tmp = 255;
      }

      localDW->cnt_ramp_DSTATE = (uint8_T)tmp;

      /* '<S97>:1:13' */
      if (localDW->cnt_ramp_DSTATE <= rtu_whl_puls_percentage[2]) {
        /* '<S97>:1:14' */
        /* '<S97>:1:15' */
        rtb_fwd_percentage_o =
          localB->prob_counter_calc_whl_puls_perc.DataTypeConversion;

        /* '<S97>:1:16' */
        rtb_ss_percentage_oc =
          localB->prob_counter_calc_whl_puls_pe_j.DataTypeConversion;

        /* '<S97>:1:17' */
        rtb_rws_percentage_n =
          localB->prob_counter_calc_whl_puls_pe_b.DataTypeConversion;
      } else {
        /* '<S97>:1:19' */
        tmp = (int32_T)(((uint32_T)rtu_whl_puls_percentage[2]) + 1U);
        if (((uint32_T)tmp) > 255U) {
          tmp = 255;
        }

        localDW->cnt_ramp_DSTATE = (uint8_T)tmp;

        /* '<S97>:1:20' */
        rtb_fwd_percentage_o = rtu_whl_puls_percentage[1];

        /* '<S97>:1:21' */
        rtb_ss_percentage_oc = rtu_whl_puls_percentage[6];

        /* '<S97>:1:22' */
        rtb_rws_percentage_n = rtu_whl_puls_percentage[11];
      }
    } else {
      /* '<S97>:1:25' */
      localDW->cnt_ramp_DSTATE = 0U;

      /* '<S97>:1:26' */
      tmp = (int32_T)(((uint32_T)localDW->cnt_delay_DSTATE) + 1U);
      if (((uint32_T)tmp) > 255U) {
        tmp = 255;
      }

      localDW->cnt_delay_DSTATE = (uint8_T)tmp;

      /* '<S97>:1:27' */
      rtb_fwd_percentage_o = rtu_whl_puls_percentage[0];

      /* '<S97>:1:28' */
      rtb_ss_percentage_oc = rtu_whl_puls_percentage[5];

      /* '<S97>:1:29' */
      rtb_rws_percentage_n = rtu_whl_puls_percentage[10];
    }
  } else {
    /* '<S97>:1:33' */
    localDW->cnt_ramp_DSTATE = 0U;

    /* '<S97>:1:34' */
    localDW->cnt_delay_DSTATE = 0U;

    /* '<S97>:1:35' */
    rtb_fwd_percentage_o = rtu_whl_puls_percentage[4];

    /* '<S97>:1:36' */
    rtb_ss_percentage_oc = rtu_whl_puls_percentage[9];

    /* '<S97>:1:37' */
    rtb_rws_percentage_n = rtu_whl_puls_percentage[4];
  }

  /* BusCreator: '<S90>/Bus Creator' */
  localB->whl_puls_fl_percentage.fwd = rtb_fwd_percentage_o;
  localB->whl_puls_fl_percentage.ss = rtb_ss_percentage_oc;
  localB->whl_puls_fl_percentage.rvs = rtb_rws_percentage_n;
}

/* Model step function */
void vdy_mot_st_step(BlockIO_vdy_mot_st *vdy_mot_st_B, D_Work_vdy_mot_st
                     *vdy_mot_st_DWork, VDYInputData_t
                     *vdy_mot_st_U_VDYInputData, VDYInternalData_t
                     *vdy_mot_st_U_VDYInternalData_in, uint8_T
                     vdy_mot_st_U_e_Direction, real32_T vdy_mot_st_U_RawVelo,
                     vdy_bayes_mot_states_t *vdy_mot_st_Y_vdy_mot_st_out)
{
  /* local block i/o variables */
  vdy_mot_states_t rtb_BusCreator_e;
  vdy_mot_states_t rtb_BusCreator_c;
  vdy_mot_states_t rtb_Merge;
  real32_T rtb_veh_velo_var;
  real32_T rtb_Switch;
  real32_T rtb_Diff;
  real32_T rtb_Divide;
  uint16_T rtb_BrakeActLevel;
  uint8_T rtb_WhlTicksDevFrLeft;
  uint8_T rtb_WhlTicksDevFrRight;
  uint8_T rtb_WhlTicksDevReLeft;
  uint8_T rtb_WhlTicksDevReRight;
  uint8_T rtb_State[32];
  uint8_T rtb_cnt_delay_down;
  uint8_T rtb_cnt_delay_up;
  uint8_T rtb_WhlDirFrLeft;
  uint8_T rtb_WhlDirFrRight;
  uint8_T rtb_WhlDirReLeft;
  uint8_T rtb_WhlDirReRight;
  uint8_T rtb_FWD_Init1;
  uint8_T rtb_FWD_Init3;
  uint8_T rtb_FWD_Init4;
  percentage_t rtb_fwd;
  percentage_t rtb_fwd_n;
  percentage_t rtb_fwd_o;
  percentage_t rtb_fwd_d;
  percentage_t rtb_ss;
  percentage_t rtb_ss_p;
  percentage_t rtb_ss_g;
  percentage_t rtb_ss_c;
  percentage_t rtb_rvs;
  percentage_t rtb_rvs_o;
  percentage_t rtb_rvs_g;
  percentage_t rtb_rvs_f;
  percentage_t rtb_fwd_j;
  percentage_t rtb_ss_h;
  percentage_t rtb_rvs_e;
  percentage_t rtb_fwd_f;
  percentage_t rtb_fwd_b;
  percentage_t rtb_fwd_l;
  percentage_t rtb_fwd_e;
  percentage_t rtb_ss_g0;
  percentage_t rtb_ss_i;
  percentage_t rtb_ss_l;
  percentage_t rtb_ss_o;
  percentage_t rtb_rvs_m;
  percentage_t rtb_rvs_oo;
  percentage_t rtb_rvs_a;
  percentage_t rtb_rvs_jo;
  percentage_t rtb_fwd_o3;
  percentage_t rtb_fwd_m;
  percentage_t rtb_ss_gr;
  percentage_t rtb_ss_gp;
  percentage_t rtb_rvs_ay;
  percentage_t rtb_rvs_ge;
  percentage_t rtb_fwd_ct;
  percentage_t rtb_fwd_ot;
  percentage_t rtb_ss_d1;
  percentage_t rtb_ss_f;
  percentage_t rtb_rvs_ei;
  percentage_t rtb_rvs_n0;
  percentage_t rtb_fwd_k;
  percentage_t rtb_fwd_f2;
  percentage_t rtb_fwd_kj;
  percentage_t rtb_fwd_lv;
  percentage_t rtb_ss_fb;
  percentage_t rtb_ss_lh;
  percentage_t rtb_ss_j;
  percentage_t rtb_ss_m;
  percentage_t rtb_rvs_h;
  percentage_t rtb_rvs_ep;
  percentage_t rtb_rvs_jy;
  percentage_t rtb_rvs_ca;
  percentage_t rtb_y1;
  percentage_t rtb_y2;
  percentage_t rtb_dT;
  percentage_t rtb_y1_c;
  percentage_t rtb_y2_f;
  percentage_t rtb_dT_i;
  percentage_t rtb_y1_f;
  percentage_t rtb_y2_d;
  percentage_t rtb_dT_l;
  percentage_t rtb_y2_h;
  percentage_t rtb_y1_fp;
  percentage_t rtb_x2;
  percentage_t rtb_x1;
  percentage_t rtb_y2_b;
  percentage_t rtb_y1_k;
  percentage_t rtb_x2_g;
  percentage_t rtb_x1_m;
  percentage_t rtb_y2_g;
  percentage_t rtb_y1_l;
  percentage_t rtb_x2_f;
  percentage_t rtb_x1_m2;
  percentage_t rtb_fwd_percentage_j;
  percentage_t rtb_ss_percentage_h;
  percentage_t rtb_rws_percentage_p;
  uint8_T rtb_fwd_percentage_e;
  uint8_T rtb_ss_percentage_j;
  uint8_T rtb_rws_percentage_c;
  percentage_t cnt_out_down;
  percentage_t cnt_out_up;
  int8_T mot_counter;
  percentage_t rtb_BusCreator4_front_left_fwd;
  percentage_t rtb_BusCreator4_front_left_ss;
  percentage_t rtb_BusCreator4_front_left_rvs;
  percentage_t rtb_BusCreator4_front_right_fwd;
  percentage_t rtb_BusCreator4_front_right_ss;
  percentage_t rtb_BusCreator4_front_right_rvs;
  percentage_t rtb_BusCreator4_rear_left_fwd;
  percentage_t rtb_BusCreator4_rear_left_ss;
  percentage_t rtb_BusCreator4_rear_left_rvs;
  percentage_t rtb_BusCreator4_rear_right_fwd;
  percentage_t rtb_BusCreator4_rear_right_ss;
  percentage_t rtb_BusCreator4_rear_right_rvs;
  percentage_t rtb_BusCreator_g_fwd;
  percentage_t rtb_BusCreator_g_ss;
  percentage_t rtb_BusCreator_g_rvs;
  uint8_T rtb_fwd_percentage_a;
  uint8_T rtb_ss_percentage_o;
  uint8_T rtb_rws_percentage_e;
  percentage_t rtb_front_left_fwd;
  percentage_t rtb_front_left_ss;
  percentage_t rtb_front_left_rvs;
  percentage_t rtb_front_right_fwd;
  percentage_t rtb_front_right_ss;
  percentage_t rtb_front_right_rvs;
  percentage_t rtb_rear_left_fwd;
  percentage_t rtb_rear_left_ss;
  percentage_t rtb_rear_left_rvs;
  percentage_t rtb_BusCreator4_d_rear_right_fw;
  percentage_t rtb_BusCreator4_d_rear_right_ss;
  percentage_t rtb_BusCreator4_d_rear_right_rv;
  uint8_T rtb_fwd_percentage_g;
  uint8_T rtb_ss_percentage_l;
  uint8_T rtb_rws_percentage_ic;
  percentage_t rtb_fwd_percentage_n;
  percentage_t rtb_ss_percentage_g;
  percentage_t rtb_rws_percentage_i;
  uint8_T rtb_fwd_percentage_f;
  uint8_T rtb_ss_percentage_m;
  uint8_T rtb_rws_percentage_k;
  real32_T rtb_Yk1;
  uint8_T rtb_DataTypeConversion;
  real32_T rtb_T2;
  real32_T rtb_T1;
  real32_T rtb_T0;
  real32_T rtb_T4;
  real32_T rtb_T5;
  real32_T rtb_T6;
  percentage_t rtb_ss_percentage;
  percentage_t rtb_rws_percentage;
  uint8_T rtb_fwd_percentage_fn;
  uint8_T rtb_ss_percentage_c;
  uint8_T rtb_rws_percentage_ek;
  percentage_t rtb_mot_st_bayes_in_ALN_dir_sta;
  percentage_t rtb_mot_st_bayes_in_ALN_dir_s_0;
  percentage_t rtb_mot_st_bayes_in_ALN_dir_s_1;
  percentage_t rtb_BusCreator_m_fwd;
  percentage_t rtb_BusCreator_m_ss;
  percentage_t rtb_BusCreator_m_rvs;
  boolean_T rtb_any_whl_valid;
  percentage_t rtb_BusCreator_p_fwd;
  percentage_t rtb_BusCreator_p_ss;
  percentage_t rtb_BusCreator_p_rvs;
  percentage_t rtb_mot_st_bayes_out_stage_3_fw;
  percentage_t rtb_mot_st_bayes_out_stage_3_ss;
  percentage_t rtb_mot_st_bayes_out_stage_3_rv;
  percentage_t rtb_mot_st_bayes_out_stage_5_fw;
  percentage_t rtb_mot_st_bayes_out_stage_5_rv;
  int32_T i;

  /* BusSelector: '<S10>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_WhlTicksDevFrLeft = (*vdy_mot_st_U_VDYInputData).Signals.WhlTicksDevFrLeft;
  rtb_WhlTicksDevFrRight = (*vdy_mot_st_U_VDYInputData).
    Signals.WhlTicksDevFrRight;
  rtb_WhlTicksDevReLeft = (*vdy_mot_st_U_VDYInputData).Signals.WhlTicksDevReLeft;
  rtb_WhlTicksDevReRight = (*vdy_mot_st_U_VDYInputData).
    Signals.WhlTicksDevReRight;

  /* BusSelector: '<Root>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  for (i = 0; i < 32; i++) {
    rtb_State[i] = (*vdy_mot_st_U_VDYInputData).Signals.State[(i)];
  }

  /* Outputs for atomic SubSystem: '<S10>/Get_IO_State1' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State1, ((uint32_T)
    VDY_SIN_POS_WTCKS_FL));

  /* end of Outputs for SubSystem: '<S10>/Get_IO_State1' */

  /* Outputs for atomic SubSystem: '<S10>/whl_puls_fl_percentage' */
  Whl_pulse_perecentage((&(vdy_whl_puls_to_perc_p[0])), rtb_WhlTicksDevFrLeft,
                        vdy_mot_st_B->Get_IO_State1.IndexVector,
                        &vdy_mot_st_B->whl_puls_fl_percentage,
                        &vdy_mot_st_DWork->whl_puls_fl_percentage);

  /* end of Outputs for SubSystem: '<S10>/whl_puls_fl_percentage' */

  /* Outputs for atomic SubSystem: '<S10>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2, ((uint32_T)
    VDY_SIN_POS_WTCKS_FR));

  /* end of Outputs for SubSystem: '<S10>/Get_IO_State2' */

  /* Outputs for atomic SubSystem: '<S10>/whl_puls_fr_percentage' */
  Whl_pulse_perecentage((&(vdy_whl_puls_to_perc_p[0])), rtb_WhlTicksDevFrRight,
                        vdy_mot_st_B->Get_IO_State2.IndexVector,
                        &vdy_mot_st_B->whl_puls_fr_percentage,
                        &vdy_mot_st_DWork->whl_puls_fr_percentage);

  /* end of Outputs for SubSystem: '<S10>/whl_puls_fr_percentage' */

  /* Outputs for atomic SubSystem: '<S10>/Get_IO_State3' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State3, ((uint32_T)
    VDY_SIN_POS_WTCKS_RL));

  /* end of Outputs for SubSystem: '<S10>/Get_IO_State3' */

  /* Outputs for atomic SubSystem: '<S10>/whl_puls_rl_percentage' */
  Whl_pulse_perecentage((&(vdy_whl_puls_to_perc_p[0])), rtb_WhlTicksDevReLeft,
                        vdy_mot_st_B->Get_IO_State3.IndexVector,
                        &vdy_mot_st_B->whl_puls_rl_percentage,
                        &vdy_mot_st_DWork->whl_puls_rl_percentage);

  /* end of Outputs for SubSystem: '<S10>/whl_puls_rl_percentage' */

  /* Outputs for atomic SubSystem: '<S10>/Get_IO_State8' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State8, ((uint32_T)
    VDY_SIN_POS_WTCKS_RR));

  /* end of Outputs for SubSystem: '<S10>/Get_IO_State8' */

  /* Outputs for atomic SubSystem: '<S10>/whl_puls_rr_percentage' */
  Whl_pulse_perecentage((&(vdy_whl_puls_to_perc_p[0])), rtb_WhlTicksDevReRight,
                        vdy_mot_st_B->Get_IO_State8.IndexVector,
                        &vdy_mot_st_B->whl_puls_rr_percentage,
                        &vdy_mot_st_DWork->whl_puls_rr_percentage);

  /* end of Outputs for SubSystem: '<S10>/whl_puls_rr_percentage' */

  /* BusCreator: '<S10>/Bus Creator4' */
  rtb_BusCreator4_front_left_fwd =
    vdy_mot_st_B->whl_puls_fl_percentage.whl_puls_fl_percentage.fwd;
  rtb_BusCreator4_front_left_ss =
    vdy_mot_st_B->whl_puls_fl_percentage.whl_puls_fl_percentage.ss;
  rtb_BusCreator4_front_left_rvs =
    vdy_mot_st_B->whl_puls_fl_percentage.whl_puls_fl_percentage.rvs;
  rtb_BusCreator4_front_right_fwd =
    vdy_mot_st_B->whl_puls_fr_percentage.whl_puls_fl_percentage.fwd;
  rtb_BusCreator4_front_right_ss =
    vdy_mot_st_B->whl_puls_fr_percentage.whl_puls_fl_percentage.ss;
  rtb_BusCreator4_front_right_rvs =
    vdy_mot_st_B->whl_puls_fr_percentage.whl_puls_fl_percentage.rvs;
  rtb_BusCreator4_rear_left_fwd =
    vdy_mot_st_B->whl_puls_rl_percentage.whl_puls_fl_percentage.fwd;
  rtb_BusCreator4_rear_left_ss =
    vdy_mot_st_B->whl_puls_rl_percentage.whl_puls_fl_percentage.ss;
  rtb_BusCreator4_rear_left_rvs =
    vdy_mot_st_B->whl_puls_rl_percentage.whl_puls_fl_percentage.rvs;
  rtb_BusCreator4_rear_right_fwd =
    vdy_mot_st_B->whl_puls_rr_percentage.whl_puls_fl_percentage.fwd;
  rtb_BusCreator4_rear_right_ss =
    vdy_mot_st_B->whl_puls_rr_percentage.whl_puls_fl_percentage.ss;
  rtb_BusCreator4_rear_right_rvs =
    vdy_mot_st_B->whl_puls_rr_percentage.whl_puls_fl_percentage.rvs;

  /* BusSelector: '<Root>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   */
  rtb_veh_velo_var = (*vdy_mot_st_U_VDYInternalData_in).vdy_ve_out.veh_velo_var;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/ExtVel'
   *  Inport: '<Root>/RawVelo'
   *  Inport: '<Root>/VDYInputData'
   */
  if (((uint32_T)CFG_VDY_USE_EX_LONG_VELO) != 0U) {
    rtb_Switch = (*vdy_mot_st_U_VDYInputData).Signals.VehVelocityExt;
  } else {
    rtb_Switch = vdy_mot_st_U_RawVelo;
  }

  /* UnitDelay: '<S8>/cnt_delay_down' */
  rtb_cnt_delay_down = vdy_mot_st_DWork->cnt_delay_down_DSTATE;

  /* Embedded MATLAB: '<S8>/get_percentage_fwd' incorporates:
   *  Constant: '<S8>/vdy_veh_velocity_to_perc'
   */
  /* Embedded MATLAB Function 'veh_velo/get_percentage_fwd': '<S61>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S61>:1:5' */
  rtb_y1_f = vdy_veh_velocity_to_perc_p[0];

  /* '<S61>:1:6' */
  rtb_y2_d = vdy_veh_velocity_to_perc_p[1];

  /* '<S61>:1:7' */
  rtb_dT_l = vdy_veh_velocity_to_perc_p[3];

  /* Outputs for atomic SubSystem: '<S64>/fwd_down_counter_veh_velo_mot_st' */
  down_counter_veh_velo_mot_st(rtb_y2_d, rtb_y1_f, rtb_cnt_delay_down, rtb_dT_l,
    &vdy_mot_st_B->fwd_down_counter_veh_velo_mot_s);

  /* end of Outputs for SubSystem: '<S64>/fwd_down_counter_veh_velo_mot_st' */

  /* Embedded MATLAB: '<S8>/get_percentage_ss' incorporates:
   *  Constant: '<S8>/vdy_veh_velocity_to_perc'
   */
  /* Embedded MATLAB Function 'veh_velo/get_percentage_ss': '<S63>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S63>:1:5' */
  rtb_y1 = vdy_veh_velocity_to_perc_p[5];

  /* '<S63>:1:6' */
  rtb_y2 = vdy_veh_velocity_to_perc_p[6];

  /* '<S63>:1:7' */
  rtb_dT = vdy_veh_velocity_to_perc_p[8];

  /* Outputs for atomic SubSystem: '<S64>/ss_down_counter_veh_velo_mot_st' */
  down_counter_veh_velo_mot_st(rtb_y2, rtb_y1, rtb_cnt_delay_down, rtb_dT,
    &vdy_mot_st_B->ss_down_counter_veh_velo_mot_st);

  /* end of Outputs for SubSystem: '<S64>/ss_down_counter_veh_velo_mot_st' */

  /* Embedded MATLAB: '<S8>/get_percentage_rws' incorporates:
   *  Constant: '<S8>/vdy_veh_velocity_to_perc'
   */
  /* Embedded MATLAB Function 'veh_velo/get_percentage_rws': '<S62>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S62>:1:5' */
  rtb_y1_c = vdy_veh_velocity_to_perc_p[10];

  /* '<S62>:1:6' */
  rtb_y2_f = vdy_veh_velocity_to_perc_p[11];

  /* '<S62>:1:7' */
  rtb_dT_i = vdy_veh_velocity_to_perc_p[13];

  /* Outputs for atomic SubSystem: '<S64>/rws_down_counter_veh_velo_mot_st' */
  down_counter_veh_velo_mot_st(rtb_y2_f, rtb_y1_c, rtb_cnt_delay_down, rtb_dT_i,
    &vdy_mot_st_B->rws_down_counter_veh_velo_mot_s);

  /* end of Outputs for SubSystem: '<S64>/rws_down_counter_veh_velo_mot_st' */

  /* UnitDelay: '<S8>/cnt_delay_up' */
  rtb_cnt_delay_up = vdy_mot_st_DWork->cnt_delay_up_DSTATE;

  /* Outputs for atomic SubSystem: '<S64>/fwd_up_counter_veh_velo_mot_st' */
  up_counter_veh_velo_mot_st(rtb_y2_d, rtb_y1_f, rtb_cnt_delay_up, rtb_dT_l,
    &vdy_mot_st_B->fwd_up_counter_veh_velo_mot_st);

  /* end of Outputs for SubSystem: '<S64>/fwd_up_counter_veh_velo_mot_st' */

  /* Outputs for atomic SubSystem: '<S64>/ss_up_counter_veh_velo_mot_st' */
  up_counter_veh_velo_mot_st(rtb_y2, rtb_y1, rtb_cnt_delay_up, rtb_dT,
    &vdy_mot_st_B->ss_up_counter_veh_velo_mot_st);

  /* end of Outputs for SubSystem: '<S64>/ss_up_counter_veh_velo_mot_st' */

  /* Outputs for atomic SubSystem: '<S64>/rws_up_counter_veh_velo_mot_st' */
  up_counter_veh_velo_mot_st(rtb_y2_f, rtb_y1_c, rtb_cnt_delay_up, rtb_dT_i,
    &vdy_mot_st_B->rws_up_counter_veh_velo_mot_st);

  /* end of Outputs for SubSystem: '<S64>/rws_up_counter_veh_velo_mot_st' */

  /* Embedded MATLAB: '<S8>/veh_velocity_percentage' incorporates:
   *  Constant: '<S8>/vdy_veh_velocity_to_perc'
   *  Constant: '<S8>/vdy_yaw_rate_to_perc'
   */
  /* Embedded MATLAB Function 'veh_velo/veh_velocity_percentage': '<S65>:1' */
  /*  calculate the vehicle velocity motion state quality */
  if (rtb_veh_velo_var <= 2500.0F) {
    /* '<S65>:1:3' */
    if (rtb_Switch >= (((real32_T)vdy_yaw_rate_to_perc_p[5]) / 100.0F)) {
      /* '<S65>:1:4' */
      /* '<S65>:1:5' */
      cnt_out_up = 0U;

      /* '<S65>:1:7' */
      i = (int32_T)(((uint32_T)rtb_cnt_delay_down) + 1U);
      if (((uint32_T)i) > 255U) {
        i = 255;
      }

      cnt_out_down = (percentage_t)i;
      if (cnt_out_down <= vdy_veh_velocity_to_perc_p[3]) {
        /* '<S65>:1:8' */
        /* '<S65>:1:9' */
        rtb_fwd_percentage_a =
          vdy_mot_st_B->fwd_down_counter_veh_velo_mot_s.DataTypeConversion;

        /* '<S65>:1:10' */
        rtb_ss_percentage_o =
          vdy_mot_st_B->ss_down_counter_veh_velo_mot_st.DataTypeConversion;

        /* '<S65>:1:11' */
        rtb_rws_percentage_e =
          vdy_mot_st_B->rws_down_counter_veh_velo_mot_s.DataTypeConversion;
      } else {
        /* '<S65>:1:13' */
        i = (int32_T)(((uint32_T)vdy_veh_velocity_to_perc_p[3]) + 1U);
        if (((uint32_T)i) > 255U) {
          i = 255;
        }

        cnt_out_down = (percentage_t)i;

        /* '<S65>:1:14' */
        rtb_fwd_percentage_a = vdy_veh_velocity_to_perc_p[0];

        /* '<S65>:1:15' */
        rtb_ss_percentage_o = vdy_veh_velocity_to_perc_p[5];

        /* '<S65>:1:16' */
        rtb_rws_percentage_e = vdy_veh_velocity_to_perc_p[10];
      }
    } else {
      /* '<S65>:1:19' */
      cnt_out_down = 0U;

      /* '<S65>:1:21' */
      i = (int32_T)(((uint32_T)rtb_cnt_delay_up) + 1U);
      if (((uint32_T)i) > 255U) {
        i = 255;
      }

      cnt_out_up = (percentage_t)i;
      if (cnt_out_up <= vdy_veh_velocity_to_perc_p[3]) {
        /* '<S65>:1:22' */
        /* '<S65>:1:23' */
        rtb_fwd_percentage_a =
          vdy_mot_st_B->fwd_up_counter_veh_velo_mot_st.DataTypeConversion;

        /* '<S65>:1:24' */
        rtb_ss_percentage_o =
          vdy_mot_st_B->ss_up_counter_veh_velo_mot_st.DataTypeConversion;

        /* '<S65>:1:25' */
        rtb_rws_percentage_e =
          vdy_mot_st_B->rws_up_counter_veh_velo_mot_st.DataTypeConversion;
      } else {
        /* '<S65>:1:27' */
        i = (int32_T)(((uint32_T)vdy_veh_velocity_to_perc_p[3]) + 2U);
        if (((uint32_T)i) > 255U) {
          i = 255;
        }

        cnt_out_up = (percentage_t)i;

        /* '<S65>:1:28' */
        rtb_fwd_percentage_a = vdy_veh_velocity_to_perc_p[1];

        /* '<S65>:1:29' */
        rtb_ss_percentage_o = vdy_veh_velocity_to_perc_p[6];

        /* '<S65>:1:30' */
        rtb_rws_percentage_e = vdy_veh_velocity_to_perc_p[11];
      }
    }
  } else {
    /* '<S65>:1:34' */
    cnt_out_down = 0U;

    /* '<S65>:1:35' */
    cnt_out_up = 0U;

    /* '<S65>:1:36' */
    rtb_fwd_percentage_a = vdy_veh_velocity_to_perc_p[4];

    /* '<S65>:1:37' */
    rtb_ss_percentage_o = vdy_veh_velocity_to_perc_p[9];

    /* '<S65>:1:38' */
    rtb_rws_percentage_e = vdy_veh_velocity_to_perc_p[14];
  }

  /* BusSelector: '<S9>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_WhlDirFrLeft = (*vdy_mot_st_U_VDYInputData).Signals.WhlDirFrLeft;

  /* Outputs for atomic SubSystem: '<S9>/Get_IO_State1' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State1_i, ((uint32_T)
    VDY_SIN_POS_WDIR_FL));

  /* end of Outputs for SubSystem: '<S9>/Get_IO_State1' */

  /* Embedded MATLAB: '<S9>/whl_fl_motion_percentage                          Compute probabilities associated with front left wheel direction' */
  whl_motion_percentage(rtb_WhlDirFrLeft,
                        vdy_mot_st_B->Get_IO_State1_i.IndexVector,
                        (&(vdy_whl_direction_to_perc_p[0])), rtb_Switch,
                        rtb_veh_velo_var, (&(vdy_yaw_rate_to_perc_p[0])),
                        &vdy_mot_st_B->sf_whl_fl_motion_percentageComp);

  /* BusCreator: '<S9>/Bus Creator' */
  rtb_front_left_fwd =
    vdy_mot_st_B->sf_whl_fl_motion_percentageComp.fwd_percentage;
  rtb_front_left_ss =
    vdy_mot_st_B->sf_whl_fl_motion_percentageComp.ss_percentage;
  rtb_front_left_rvs =
    vdy_mot_st_B->sf_whl_fl_motion_percentageComp.rws_percentage;

  /* BusSelector: '<S9>/Bus Selector1' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_WhlDirFrRight = (*vdy_mot_st_U_VDYInputData).Signals.WhlDirFrRight;

  /* Outputs for atomic SubSystem: '<S9>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_f, ((uint32_T)
    VDY_SIN_POS_WDIR_FR));

  /* end of Outputs for SubSystem: '<S9>/Get_IO_State2' */

  /* Embedded MATLAB: '<S9>/whl_fr_motion_percentage                          Compute probabilities associated with front right wheel direction' */
  whl_motion_percentage(rtb_WhlDirFrRight,
                        vdy_mot_st_B->Get_IO_State2_f.IndexVector,
                        (&(vdy_whl_direction_to_perc_p[0])), rtb_Switch,
                        rtb_veh_velo_var, (&(vdy_yaw_rate_to_perc_p[0])),
                        &vdy_mot_st_B->sf_whl_fr_motion_percentageComp);

  /* BusCreator: '<S9>/Bus Creator1' */
  rtb_front_right_fwd =
    vdy_mot_st_B->sf_whl_fr_motion_percentageComp.fwd_percentage;
  rtb_front_right_ss =
    vdy_mot_st_B->sf_whl_fr_motion_percentageComp.ss_percentage;
  rtb_front_right_rvs =
    vdy_mot_st_B->sf_whl_fr_motion_percentageComp.rws_percentage;

  /* BusSelector: '<S9>/Bus Selector2' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_WhlDirReLeft = (*vdy_mot_st_U_VDYInputData).Signals.WhlDirReLeft;

  /* Outputs for atomic SubSystem: '<S9>/Get_IO_State3' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State3_e, ((uint32_T)
    VDY_SIN_POS_WDIR_RL));

  /* end of Outputs for SubSystem: '<S9>/Get_IO_State3' */

  /* Embedded MATLAB: '<S9>/whl_rl_motion_percentage                          Compute probabilities associated with rear left wheel direction' */
  whl_motion_percentage(rtb_WhlDirReLeft,
                        vdy_mot_st_B->Get_IO_State3_e.IndexVector,
                        (&(vdy_whl_direction_to_perc_p[0])), rtb_Switch,
                        rtb_veh_velo_var, (&(vdy_yaw_rate_to_perc_p[0])),
                        &vdy_mot_st_B->sf_whl_rl_motion_percentageComp);

  /* BusCreator: '<S9>/Bus Creator2' */
  rtb_rear_left_fwd =
    vdy_mot_st_B->sf_whl_rl_motion_percentageComp.fwd_percentage;
  rtb_rear_left_ss = vdy_mot_st_B->sf_whl_rl_motion_percentageComp.ss_percentage;
  rtb_rear_left_rvs =
    vdy_mot_st_B->sf_whl_rl_motion_percentageComp.rws_percentage;

  /* BusSelector: '<S9>/Bus Selector3' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_WhlDirReRight = (*vdy_mot_st_U_VDYInputData).Signals.WhlDirReRight;

  /* Outputs for atomic SubSystem: '<S9>/Get_IO_State4' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State4, ((uint32_T)
    VDY_SIN_POS_WDIR_RR));

  /* end of Outputs for SubSystem: '<S9>/Get_IO_State4' */

  /* Embedded MATLAB: '<S9>/whl_rr_motion_percentage                          Compute probabilities associated with rear right wheel direction' */
  whl_motion_percentage(rtb_WhlDirReRight,
                        vdy_mot_st_B->Get_IO_State4.IndexVector,
                        (&(vdy_whl_direction_to_perc_p[0])), rtb_Switch,
                        rtb_veh_velo_var, (&(vdy_yaw_rate_to_perc_p[0])),
                        &vdy_mot_st_B->sf_whl_rr_motion_percentageComp);

  /* BusCreator: '<S9>/Bus Creator4' incorporates:
   *  BusCreator: '<S9>/Bus Creator3'
   */
  rtb_BusCreator4_d_rear_right_fw =
    vdy_mot_st_B->sf_whl_rr_motion_percentageComp.fwd_percentage;
  rtb_BusCreator4_d_rear_right_ss =
    vdy_mot_st_B->sf_whl_rr_motion_percentageComp.ss_percentage;
  rtb_BusCreator4_d_rear_right_rv =
    vdy_mot_st_B->sf_whl_rr_motion_percentageComp.rws_percentage;

  /* Outputs for atomic SubSystem: '<S5>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_d, ((uint32_T)
    VDY_SIN_POS_BRAKE));

  /* end of Outputs for SubSystem: '<S5>/Get_IO_State2' */

  /* BusSelector: '<S5>/Bus Selector' incorporates:
   *  Inport: '<Root>/VDYInputData'
   */
  rtb_BrakeActLevel = (*vdy_mot_st_U_VDYInputData).Signals.BrakeActLevel;

  /* Embedded MATLAB: '<S48>/get_percentage' incorporates:
   *  Constant: '<S5>/vdy_brake_torque_to_perc'
   */
  /* Embedded MATLAB Function 'brake_torque/brake_torque_percentage/fwd_brake_torque_to_percentage/get_percentage': '<S51>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S51>:1:5' */
  rtb_x1_m2 = vdy_brake_torque_to_perc_p[1];

  /* '<S51>:1:6' */
  rtb_x2_f = vdy_brake_torque_to_perc_p[2];

  /* '<S51>:1:7' */
  rtb_y1_l = vdy_brake_torque_to_perc_p[3];

  /* '<S51>:1:8' */
  rtb_y2_g = vdy_brake_torque_to_perc_p[4];

  /* Outputs for atomic SubSystem: '<S48>/prob_calc_brake_trq' */
  prob_calc_brake_trq(rtb_y2_g, rtb_y1_l, rtb_x2_f, rtb_x1_m2, rtb_BrakeActLevel,
                      &vdy_mot_st_B->prob_calc_brake_trq_o);

  /* end of Outputs for SubSystem: '<S48>/prob_calc_brake_trq' */

  /* Embedded MATLAB: '<S50>/get_percentage' incorporates:
   *  Constant: '<S5>/vdy_brake_torque_to_perc'
   */
  /* Embedded MATLAB Function 'brake_torque/brake_torque_percentage/ss_brake_torque_to_percentage/get_percentage': '<S55>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S55>:1:5' */
  rtb_x1 = vdy_brake_torque_to_perc_p[7];

  /* '<S55>:1:6' */
  rtb_x2 = vdy_brake_torque_to_perc_p[8];

  /* '<S55>:1:7' */
  rtb_y1_fp = vdy_brake_torque_to_perc_p[9];

  /* '<S55>:1:8' */
  rtb_y2_h = vdy_brake_torque_to_perc_p[10];

  /* Outputs for atomic SubSystem: '<S50>/prob_calc_brake_trq' */
  prob_calc_brake_trq(rtb_y2_h, rtb_y1_fp, rtb_x2, rtb_x1, rtb_BrakeActLevel,
                      &vdy_mot_st_B->prob_calc_brake_trq_d);

  /* end of Outputs for SubSystem: '<S50>/prob_calc_brake_trq' */

  /* Embedded MATLAB: '<S49>/get_percentage' incorporates:
   *  Constant: '<S5>/vdy_brake_torque_to_perc'
   */
  /* Embedded MATLAB Function 'brake_torque/brake_torque_percentage/rws_brake_torque_to_percentage/get_percentage': '<S53>:1' */
  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  /* '<S53>:1:5' */
  rtb_x1_m = vdy_brake_torque_to_perc_p[13];

  /* '<S53>:1:6' */
  rtb_x2_g = vdy_brake_torque_to_perc_p[14];

  /* '<S53>:1:7' */
  rtb_y1_k = vdy_brake_torque_to_perc_p[15];

  /* '<S53>:1:8' */
  rtb_y2_b = vdy_brake_torque_to_perc_p[16];

  /* Outputs for atomic SubSystem: '<S49>/prob_calc_brake_trq' */
  prob_calc_brake_trq(rtb_y2_b, rtb_y1_k, rtb_x2_g, rtb_x1_m, rtb_BrakeActLevel,
                      &vdy_mot_st_B->prob_calc_brake_trq_m);

  /* end of Outputs for SubSystem: '<S49>/prob_calc_brake_trq' */

  /* Embedded MATLAB: '<S46>/brake_torque_percentage_fcn' incorporates:
   *  Constant: '<S5>/vdy_brake_torque_to_perc'
   */
  /* Embedded MATLAB Function 'brake_torque/brake_torque_percentage/brake_torque_percentage_fcn': '<S47>:1' */
  /*  compute the brake torque motion state quality */
  if (((uint32_T)vdy_mot_st_B->Get_IO_State2_d.IndexVector) == ((uint32_T)
       VDY_IO_STATE_VALID)) {
    /* '<S47>:1:3' */
    if (rtb_BrakeActLevel == 0) {
      /* '<S47>:1:4' */
      /* '<S47>:1:5' */
      rtb_fwd_percentage_g = vdy_brake_torque_to_perc_p[0];

      /* '<S47>:1:6' */
      rtb_ss_percentage_l = vdy_brake_torque_to_perc_p[6];

      /* '<S47>:1:7' */
      rtb_rws_percentage_ic = vdy_brake_torque_to_perc_p[12];
    } else if (rtb_BrakeActLevel <= vdy_brake_torque_to_perc_p[3]) {
      /* '<S47>:1:8' */
      /* '<S47>:1:9' */
      rtb_fwd_percentage_g = vdy_brake_torque_to_perc_p[1];

      /* '<S47>:1:10' */
      rtb_ss_percentage_l = vdy_brake_torque_to_perc_p[7];

      /* '<S47>:1:11' */
      rtb_rws_percentage_ic = vdy_brake_torque_to_perc_p[13];
    } else {
      /* '<S47>:1:13' */
      rtb_fwd_percentage_g =
        vdy_mot_st_B->prob_calc_brake_trq_o.DataTypeConversion;

      /* '<S47>:1:14' */
      rtb_ss_percentage_l =
        vdy_mot_st_B->prob_calc_brake_trq_d.DataTypeConversion;

      /* '<S47>:1:15' */
      rtb_rws_percentage_ic =
        vdy_mot_st_B->prob_calc_brake_trq_m.DataTypeConversion;
    }
  } else {
    /* '<S47>:1:18' */
    rtb_fwd_percentage_g = vdy_brake_torque_to_perc_p[5];

    /* '<S47>:1:19' */
    rtb_ss_percentage_l = vdy_brake_torque_to_perc_p[11];

    /* '<S47>:1:20' */
    rtb_rws_percentage_ic = vdy_brake_torque_to_perc_p[17];
  }

  /* Outputs for atomic SubSystem: '<S6>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_d0,
    ((uint32_T)VDY_SIN_POS_GEAR));

  /* end of Outputs for SubSystem: '<S6>/Get_IO_State2' */

  /* Embedded MATLAB: '<S6>/gear_shift_percentage' incorporates:
   *  Constant: '<S6>/Velocity_threshold'
   *  Constant: '<S6>/vdy_gear_shift_to_perc'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S6>/last fwd'
   *  UnitDelay: '<S6>/last rvs'
   *  UnitDelay: '<S6>/last ss'
   */
  /* Embedded MATLAB Function 'gear_shift/gear_shift_percentage': '<S58>:1' */
  /*  compute the gear shift position motion state quality */
  if (((uint32_T)vdy_mot_st_B->Get_IO_State2_d0.IndexVector) == ((uint32_T)
       VDY_IO_STATE_VALID)) {
    /* '<S58>:1:3' */
    /* '<S58>:1:4' */
    switch ((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos) {
     case 0U:
      /*  N */
      if (rtb_Switch >= (((real32_T)vdy_yaw_rate_to_perc_p[5]) / 100.0F)) {
        /* '<S58>:1:6' */
        if ((vdy_mot_st_DWork->lastfwd_DSTATE > vdy_mot_st_DWork->lastss_DSTATE)
            || (vdy_mot_st_DWork->lastrvs_DSTATE >
                vdy_mot_st_DWork->lastss_DSTATE)) {
          /* '<S58>:1:7' */
          /* Hold Last Value */
          /* '<S58>:1:9' */
          rtb_fwd_percentage_n = vdy_mot_st_DWork->lastfwd_DSTATE;

          /* '<S58>:1:10' */
          rtb_ss_percentage_g = vdy_mot_st_DWork->lastss_DSTATE;

          /* '<S58>:1:11' */
          rtb_rws_percentage_i = vdy_mot_st_DWork->lastrvs_DSTATE;
        } else {
          /* '<S58>:1:13' */
          rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[5];

          /* '<S58>:1:14' */
          rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[11];

          /* '<S58>:1:15' */
          rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[17];
        }
      } else {
        /* '<S58>:1:18' */
        rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[1];

        /* '<S58>:1:19' */
        rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[7];

        /* '<S58>:1:20' */
        rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[13];
      }
      break;

     case 1U:
      /*  P       */
      /* '<S58>:1:23' */
      rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[0];

      /* '<S58>:1:24' */
      rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[6];

      /* '<S58>:1:25' */
      rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[12];
      break;

     case 2U:
      /*  D */
      /* '<S58>:1:27' */
      rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[3];

      /* '<S58>:1:28' */
      rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[9];

      /* '<S58>:1:29' */
      rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[15];
      break;

     case 3U:
      /*  R */
      /* '<S58>:1:31' */
      rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[2];

      /* '<S58>:1:32' */
      rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[8];

      /* '<S58>:1:33' */
      rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[14];
      break;

     default:
      /* '<S58>:1:35' */
      rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[4];

      /* '<S58>:1:36' */
      rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[10];

      /* '<S58>:1:37' */
      rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[16];
      break;
    }
  } else {
    /* '<S58>:1:40' */
    rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[4];

    /* '<S58>:1:41' */
    rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[10];

    /* '<S58>:1:42' */
    rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[16];
  }

  /*  if velocity is less than 0.1 m/s , standstill percentage can be given . */
  if (((*vdy_mot_st_U_VDYInternalData_in).vdy_ve_out.veh_velo_var <= 2500.0F) &&
      (rtb_Switch < (((real32_T)vdy_yaw_rate_to_perc_p[5]) / 100.0F))) {
    /* '<S58>:1:46' */
    /* '<S58>:1:47' */
    rtb_fwd_percentage_n = vdy_gear_shift_to_perc_p[0];

    /* '<S58>:1:48' */
    rtb_ss_percentage_g = vdy_gear_shift_to_perc_p[6];

    /* '<S58>:1:49' */
    rtb_rws_percentage_i = vdy_gear_shift_to_perc_p[12];
  }

  /* Outputs for atomic SubSystem: '<S7>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_e, ((uint32_T)
    VDY_SIN_POS_PBRK));

  /* end of Outputs for SubSystem: '<S7>/Get_IO_State2' */

  /* Embedded MATLAB: '<S7>/parking_break_percentage' incorporates:
   *  Constant: '<S7>/vdy_parking_break_to_perc'
   *  Inport: '<Root>/VDYInputData'
   */
  /* Embedded MATLAB Function 'parking_brake/parking_break_percentage': '<S60>:1' */
  /*  compute the parking brake state motion state quality */
  if (((uint32_T)vdy_mot_st_B->Get_IO_State2_e.IndexVector) == ((uint32_T)
       VDY_IO_STATE_VALID)) {
    /* '<S60>:1:3' */
    /* '<S60>:1:4' */
    switch ((*vdy_mot_st_U_VDYInputData).Signals.ParkBrakeState) {
     case 0U:
      /*  brake is off */
      /* '<S60>:1:6' */
      rtb_fwd_percentage_f = vdy_parking_break_to_perc_p[0];

      /* '<S60>:1:7' */
      rtb_ss_percentage_m = vdy_parking_break_to_perc_p[3];

      /* '<S60>:1:8' */
      rtb_rws_percentage_k = vdy_parking_break_to_perc_p[6];
      break;

     case 1U:
      /*  brake is on      */
      /* '<S60>:1:10' */
      rtb_fwd_percentage_f = vdy_parking_break_to_perc_p[1];

      /* '<S60>:1:11' */
      rtb_ss_percentage_m = vdy_parking_break_to_perc_p[4];

      /* '<S60>:1:12' */
      rtb_rws_percentage_k = vdy_parking_break_to_perc_p[7];
      break;

     default:
      /* '<S60>:1:14' */
      rtb_fwd_percentage_f = vdy_parking_break_to_perc_p[2];

      /* '<S60>:1:15' */
      rtb_ss_percentage_m = vdy_parking_break_to_perc_p[5];

      /* '<S60>:1:16' */
      rtb_rws_percentage_k = vdy_parking_break_to_perc_p[8];
      break;
    }
  } else {
    /* '<S60>:1:19' */
    rtb_fwd_percentage_f = vdy_parking_break_to_perc_p[2];

    /* '<S60>:1:20' */
    rtb_ss_percentage_m = vdy_parking_break_to_perc_p[5];

    /* '<S60>:1:21' */
    rtb_rws_percentage_k = vdy_parking_break_to_perc_p[8];
  }

  /* UnitDelay: '<S135>/UD' */
  rtb_Yk1 = vdy_mot_st_DWork->UD_DSTATE;

  /* Sum: '<S134>/Diff' incorporates:
   *  Inport: '<Root>/VDYInternalData_in'
   *  UnitDelay: '<S134>/UD'
   */
  rtb_Diff = (*vdy_mot_st_U_VDYInternalData_in).vdy_ye_out.veh_yaw_rate -
    vdy_mot_st_DWork->UD_DSTATE_k;

  /* Embedded MATLAB: '<S11>/threshold_yaw_rate' incorporates:
   *  S-Function (ex_sfun_abs): '<S11>/abs_velocity'
   *  Sum: '<S134>/Diff'
   *  UnitDelay: '<S134>/UD'
   */
  /* Embedded MATLAB Function 'yaw_rate/threshold_yaw_rate': '<S137>:1' */
  /*  if the abs diff yaw rate is below the threshold output is zero */
  /* '<S137>:1:3' */
  i = 1;
  if (CML_f_Abs( (real32_T)rtb_Diff) <= (((real32_T)vdy_yaw_rate_to_perc_p[0]) *
       1.0E-7F)) {
    /* '<S137>:1:4' */
    /* '<S137>:1:5' */
    i = 0;
  }

  /* Sum: '<S135>/Sum' incorporates:
   *  Gain: '<S135>/Gain'
   *  Sum: '<S135>/Diff'
   */
  rtb_Yk1 = ((rtb_Yk1 - ((real32_T)i)) * 0.935F) + ((real32_T)i);

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S11>/fw_rvs_const'
   *  Product: '<S11>/mult_fw_rvs'
   */
  rtb_DataTypeConversion = (uint8_T)(rtb_Yk1 * 50.0F);

  /* UnitDelay: '<S136>/T2' */
  rtb_T2 = vdy_mot_st_DWork->T2_DSTATE;

  /* UnitDelay: '<S136>/T1' */
  rtb_T1 = vdy_mot_st_DWork->T1_DSTATE;

  /* UnitDelay: '<S136>/T0' */
  rtb_T0 = vdy_mot_st_DWork->T0_DSTATE;

  /* UnitDelay: '<S136>/T4' */
  rtb_T4 = vdy_mot_st_DWork->T4_DSTATE;

  /* UnitDelay: '<S136>/T5' */
  rtb_T5 = vdy_mot_st_DWork->T5_DSTATE;

  /* UnitDelay: '<S136>/T6' */
  rtb_T6 = vdy_mot_st_DWork->T6_DSTATE;

  /* Product: '<S136>/Divide' incorporates:
   *  Constant: '<S136>/filter_length'
   *  Inport: '<Root>/VDYInternalData_in'
   *  Sum: '<S136>/Add'
   *  UnitDelay: '<S136>/T3'
   */
  rtb_Divide = (((((((vdy_mot_st_DWork->T3_DSTATE + vdy_mot_st_DWork->T2_DSTATE)
                     + vdy_mot_st_DWork->T1_DSTATE) +
                    vdy_mot_st_DWork->T0_DSTATE) + vdy_mot_st_DWork->T4_DSTATE)
                  + vdy_mot_st_DWork->T5_DSTATE) + vdy_mot_st_DWork->T6_DSTATE)
                + (*vdy_mot_st_U_VDYInternalData_in).vdy_ye_out.veh_yaw_rate_var)
    * 0.125F;

  /* Embedded MATLAB: '<S11>/yaw_rate_percentage' incorporates:
   *  Constant: '<S11>/Velocity_threshold'
   *  Constant: '<S11>/one_const'
   *  Constant: '<S11>/ss_const'
   *  Constant: '<S136>/filter_length'
   *  DataTypeConversion: '<S11>/Data Type Conversion1'
   *  Product: '<S11>/mult_ss'
   *  Product: '<S136>/Divide'
   *  S-Function (ex_sfun_abs): '<S11>/abs_yaw_var'
   *  Sum: '<S11>/Add'
   *  Sum: '<S136>/Add'
   *  UnitDelay: '<S136>/T3'
   */
  /* Embedded MATLAB Function 'yaw_rate/yaw_rate_percentage': '<S138>:1' */
  /*  compute the yaw rate motion state quality */
  if ((CML_f_Abs( (real32_T)rtb_Divide) >= 1.0E-10F) && (rtb_Switch <
       (((real32_T)vdy_yaw_rate_to_perc_p[5]) / 100.0F))) {
    /* '<S138>:1:3' */
    /* '<S138>:1:4' */
    /* '<S138>:1:5' */
    rtb_ss_percentage = (uint8_T)((1.0F - rtb_Yk1) * 100.0F);

    /* '<S138>:1:6' */
    rtb_rws_percentage = rtb_DataTypeConversion;
  } else {
    /* '<S138>:1:8' */
    rtb_DataTypeConversion = vdy_yaw_rate_to_perc_p[1];

    /* '<S138>:1:9' */
    rtb_ss_percentage = vdy_yaw_rate_to_perc_p[4];

    /* '<S138>:1:10' */
    rtb_rws_percentage = vdy_yaw_rate_to_perc_p[7];
  }

  /* Outputs for atomic SubSystem: '<S1>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_m, ((uint32_T)
    VDY_SIN_POS_GEAR));

  /* end of Outputs for SubSystem: '<S1>/Get_IO_State2' */

  /* Embedded MATLAB: '<S1>/ALN_direction_percentage1' incorporates:
   *  Constant: '<S1>/Velocity_threshold'
   *  Constant: '<S1>/vdy_ALN_to_perc_p'
   *  Inport: '<Root>/VDYInputData'
   *  Inport: '<Root>/e_Direction'
   *  UnitDelay: '<S1>/FWD_Init7'
   *  UnitDelay: '<S1>/RWS_Init5'
   *  UnitDelay: '<S1>/SS_Init6'
   *  UnitDelay: '<S1>/mot_count_delay'
   */
  mot_counter = vdy_mot_st_DWork->mot_count_delay_DSTATE;

  /* Embedded MATLAB Function 'ALN_direction/ALN_direction_percentage1': '<S16>:1' */
  /*  compute the direction quality with */
  /*  To go to reverse state, vehicle has to come down to velo (0.0)m/s. */
  /*  max_counter(100) is a limit for fwd/rws condition. */
  /*  mot_counter counts fwd/rws cycles & is incremented/decremented */
  /*  respectively based on ALN direction & veh Velo. It is reset to zero once */
  /*  the ALN state is unknown/invalid/sdst. VDY mot state is updated according */
  /*  At velo < 0.1m/s & velo > 20kmph, ALN data is not considered. */
  /*  NOTE : Consider velocity variance in future issues as it is removed in      */
  /*  to mot_counter & veh Velo. */
  /*  current implementation. */
  /*  ALN is providing */
  /* '<S16>:1:15' */
  rtb_fwd_percentage_e = vdy_ALN_to_perc_p[2];

  /*  the value is 33 percentage    % Unknown */
  /* '<S16>:1:16' */
  rtb_ss_percentage_j = vdy_ALN_to_perc_p[7];

  /*  the value is 34 percentage */
  /* '<S16>:1:17' */
  rtb_rws_percentage_c = vdy_ALN_to_perc_p[12];

  /*  the value is 33 percentage */
  /* '<S16>:1:19' */
  if ((rtb_Switch >= 0.0F) && (rtb_Switch < (((real32_T)vdy_yaw_rate_to_perc_p[5])
        / 100.0F))) {
    /* '<S16>:1:21' */
    /*  at this condition, vehicle is considered standstill because of negligible velocity. */
    /* '<S16>:1:22' */
    mot_counter = 0;

    /*  sdst */
    /* '<S16>:1:23' */
    rtb_fwd_percentage_e = vdy_ALN_to_perc_p[4];

    /*  the value is 2 percentage */
    /* '<S16>:1:24' */
    rtb_ss_percentage_j = vdy_ALN_to_perc_p[9];

    /*  the value is 98 percentage */
    /* '<S16>:1:25' */
    rtb_rws_percentage_c = vdy_ALN_to_perc_p[14];

    /*  the value is 2 percentage */
  } else if ((rtb_Switch >= (((real32_T)vdy_yaw_rate_to_perc_p[5]) / 100.0F)) &&
             (rtb_Switch < 5.55555534F)) {
    /* '<S16>:1:26' */
    if (vdy_mot_st_U_e_Direction == 1) {
      /* '<S16>:1:27' */
      /*  fwd */
      if (vdy_mot_st_DWork->mot_count_delay_DSTATE < 100) {
        /* '<S16>:1:28' */
        /* '<S16>:1:29' */
        mot_counter = (int8_T)(vdy_mot_st_DWork->mot_count_delay_DSTATE + 1);
      } else {
        /* '<S16>:1:31' */
        mot_counter = 100;

        /*  continue to maintain 100 value */
      }
    } else {
      if (vdy_mot_st_U_e_Direction == 2) {
        /* '<S16>:1:33' */
        /*  rws */
        if (vdy_mot_st_DWork->mot_count_delay_DSTATE > -100) {
          /* '<S16>:1:34' */
          /* '<S16>:1:35' */
          mot_counter = (int8_T)(vdy_mot_st_DWork->mot_count_delay_DSTATE - 1);
        } else {
          /* '<S16>:1:37' */
          mot_counter = -100;

          /*  continue to maintain -100 value */
        }
      }
    }

    if ((((uint32_T)vdy_mot_st_B->Get_IO_State2_m.IndexVector) == ((uint32_T)
          VDY_IO_STATE_VALID)) && ((((*vdy_mot_st_U_VDYInputData).
           Signals.ActGearPos == 2) && (mot_counter < -4)) ||
         (((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 3) && (mot_counter
           > 4)))) {
      /* '<S16>:1:41' */
      if ((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 2) {
        /* '<S16>:1:42' */
        /* FWD */
        /* '<S16>:1:43' */
        mot_counter = 15;
      }

      if ((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 3) {
        /* '<S16>:1:46' */
        /* REV */
        /* '<S16>:1:47' */
        mot_counter = -15;
      }
    }

    if (mot_counter > 4) {
      /* '<S16>:1:51' */
      /*  fwd */
      /* '<S16>:1:52' */
      rtb_fwd_percentage_e = vdy_ALN_to_perc_p[0];

      /* '<S16>:1:53' */
      rtb_ss_percentage_j = vdy_ALN_to_perc_p[5];

      /* '<S16>:1:54' */
      rtb_rws_percentage_c = vdy_ALN_to_perc_p[10];
    } else {
      if (mot_counter < -4) {
        /* '<S16>:1:55' */
        /*  rws */
        /* '<S16>:1:56' */
        rtb_fwd_percentage_e = vdy_ALN_to_perc_p[1];

        /* '<S16>:1:57' */
        rtb_ss_percentage_j = vdy_ALN_to_perc_p[6];

        /* '<S16>:1:58' */
        rtb_rws_percentage_c = vdy_ALN_to_perc_p[11];
      }
    }
  } else {
    /*  velo > 20kmph and Gear info is valid ,also ALN and Gear info is */
    /*  contradicting ,then give priority to Gear Info also freeze the */
    /*  counter to +5 for FWD motion and -5 for RWS motion. */
    /*  else start considering prev values. And keep the counter at the same value - no reseting. */
    if (((((uint32_T)vdy_mot_st_B->Get_IO_State2_m.IndexVector) == ((uint32_T)
           VDY_IO_STATE_VALID)) && (vdy_mot_st_U_e_Direction == 0)) &&
        ((((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 2) &&
          (vdy_mot_st_DWork->mot_count_delay_DSTATE < -4)) ||
         (((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 3) &&
          (vdy_mot_st_DWork->mot_count_delay_DSTATE > 4)))) {
      /* '<S16>:1:67' */
      if ((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 2) {
        /* '<S16>:1:68' */
        /* FWD */
        /* '<S16>:1:69' */
        mot_counter = 15;

        /* '<S16>:1:70' */
        rtb_fwd_percentage_e = vdy_ALN_to_perc_p[0];

        /* '<S16>:1:71' */
        rtb_ss_percentage_j = vdy_ALN_to_perc_p[5];

        /* '<S16>:1:72' */
        rtb_rws_percentage_c = vdy_ALN_to_perc_p[10];
      }

      if ((*vdy_mot_st_U_VDYInputData).Signals.ActGearPos == 3) {
        /* '<S16>:1:75' */
        /* REV */
        /* '<S16>:1:76' */
        mot_counter = -15;

        /* '<S16>:1:77' */
        rtb_fwd_percentage_e = vdy_ALN_to_perc_p[1];

        /* '<S16>:1:78' */
        rtb_ss_percentage_j = vdy_ALN_to_perc_p[6];

        /* '<S16>:1:79' */
        rtb_rws_percentage_c = vdy_ALN_to_perc_p[11];
      }
    } else {
      /* '<S16>:1:82' */
      rtb_fwd_percentage_e = vdy_mot_st_DWork->FWD_Init7_DSTATE;

      /* '<S16>:1:83' */
      rtb_ss_percentage_j = vdy_mot_st_DWork->SS_Init6_DSTATE;

      /* '<S16>:1:84' */
      rtb_rws_percentage_c = vdy_mot_st_DWork->RWS_Init5_DSTATE;
    }
  }

  /* '<S16>:1:88' */
  if ((rtb_Switch >= 5.55555534F) && ((rtb_ss_percentage_j >
        rtb_fwd_percentage_e) || (rtb_ss_percentage_j > rtb_rws_percentage_c)))
  {
    /* '<S16>:1:90' */
    /*  Dont consider Aln if velocity is greater than 20km/hr and Aln is */
    /*  showing standstill */
    /* '<S16>:1:93' */
    rtb_fwd_percentage_e = vdy_ALN_to_perc_p[2];

    /*  the value is 33 percentage */
    /* '<S16>:1:94' */
    rtb_ss_percentage_j = vdy_ALN_to_perc_p[7];

    /*  the value is 34 percentage */
    /* '<S16>:1:95' */
    rtb_rws_percentage_c = vdy_ALN_to_perc_p[12];

    /*  the value is 33 percentage */
  }

  /* UnitDelay: '<S1>/FWD_Init1' */
  rtb_FWD_Init1 = vdy_mot_st_DWork->FWD_Init1_DSTATE;

  /* Outputs for atomic SubSystem: '<S1>/ALN_Fwd' */
  ALN_percenatge_probability(vdy_mot_st_U_e_Direction, rtb_FWD_Init1,
    rtb_fwd_percentage_e, &vdy_mot_st_B->ALN_Fwd, &vdy_mot_st_DWork->ALN_Fwd);

  /* end of Outputs for SubSystem: '<S1>/ALN_Fwd' */

  /* UnitDelay: '<S1>/FWD_Init3' */
  rtb_FWD_Init3 = vdy_mot_st_DWork->FWD_Init3_DSTATE;

  /* Outputs for atomic SubSystem: '<S1>/ALN_Ss' */
  ALN_percenatge_probability(vdy_mot_st_U_e_Direction, rtb_FWD_Init3,
    rtb_ss_percentage_j, &vdy_mot_st_B->ALN_Ss, &vdy_mot_st_DWork->ALN_Ss);

  /* end of Outputs for SubSystem: '<S1>/ALN_Ss' */

  /* UnitDelay: '<S1>/FWD_Init4' */
  rtb_FWD_Init4 = vdy_mot_st_DWork->FWD_Init4_DSTATE;

  /* Outputs for atomic SubSystem: '<S1>/ALN_Rws' */
  ALN_percenatge_probability(vdy_mot_st_U_e_Direction, rtb_FWD_Init4,
    rtb_rws_percentage_c, &vdy_mot_st_B->ALN_Rws, &vdy_mot_st_DWork->ALN_Rws);

  /* end of Outputs for SubSystem: '<S1>/ALN_Rws' */

  /* Embedded MATLAB: '<S1>/ALN_direction_percentage' incorporates:
   *  Constant: '<S1>/vdy_ALN_to_perc_p1'
   */
  /* Embedded MATLAB Function 'ALN_direction/ALN_direction_percentage': '<S15>:1' */
  /*  compute the direction quality with  */
  /*  custom switch */
  if (((uint32_T)CFG_VDY_MFC) != 1U) {
    /* '<S15>:1:4' */
    /* '<S15>:1:5' */
    rtb_fwd_percentage_fn = vdy_mot_st_B->ALN_Fwd.DataTypeConversion;

    /*  ALN FWD percentage                */
    /* '<S15>:1:6' */
    rtb_ss_percentage_c = vdy_mot_st_B->ALN_Ss.DataTypeConversion;

    /*  ALN SS percentage */
    /* '<S15>:1:7' */
    rtb_rws_percentage_ek = vdy_mot_st_B->ALN_Rws.DataTypeConversion;

    /*  ALN REV percentage */
  } else {
    /* '<S15>:1:9' */
    rtb_fwd_percentage_fn = vdy_ALN_to_perc_p[3];

    /*  the value is 0 percentage                */
    /* '<S15>:1:10' */
    rtb_ss_percentage_c = vdy_ALN_to_perc_p[8];

    /*  the value is 0 percentage */
    /* '<S15>:1:11' */
    rtb_rws_percentage_ek = vdy_ALN_to_perc_p[13];

    /*  the value is 0 percentage */
  }

  /* BusCreator: '<S1>/Bus Creator' */
  rtb_BusCreator_e.fwd = rtb_fwd_percentage_fn;
  rtb_BusCreator_e.ss = rtb_ss_percentage_c;
  rtb_BusCreator_e.rvs = rtb_rws_percentage_ek;

  /* BusCreator: '<Root>/Bus Creator' */
  rtb_mot_st_bayes_in_ALN_dir_sta = rtb_BusCreator_e.fwd;
  rtb_mot_st_bayes_in_ALN_dir_s_0 = rtb_BusCreator_e.ss;
  rtb_mot_st_bayes_in_ALN_dir_s_1 = rtb_BusCreator_e.rvs;

  /* BusSelector: '<S29>/Bus Selector1' */
  rtb_fwd = rtb_BusCreator4_front_left_fwd;
  rtb_fwd_n = rtb_BusCreator4_front_right_fwd;
  rtb_fwd_o = rtb_BusCreator4_rear_left_fwd;
  rtb_fwd_d = rtb_BusCreator4_rear_right_fwd;

  /* BusSelector: '<S29>/Bus Selector' */
  rtb_ss = rtb_BusCreator4_front_left_ss;
  rtb_ss_p = rtb_BusCreator4_front_right_ss;
  rtb_ss_g = rtb_BusCreator4_rear_left_ss;
  rtb_ss_c = rtb_BusCreator4_rear_right_ss;

  /* BusSelector: '<S29>/Bus Selector2' */
  rtb_rvs = rtb_BusCreator4_front_left_rvs;
  rtb_rvs_o = rtb_BusCreator4_front_right_rvs;
  rtb_rvs_g = rtb_BusCreator4_rear_left_rvs;
  rtb_rvs_f = rtb_BusCreator4_rear_right_rvs;

  /* BusCreator: '<S29>/Bus Creator' incorporates:
   *  BusSelector: '<S29>/Bus Selector'
   *  BusSelector: '<S29>/Bus Selector1'
   *  BusSelector: '<S29>/Bus Selector2'
   *  Constant: '<S29>/vdy_cpt_whl_pulse'
   *  S-Function (ex_sfun_bayes4): '<S29>/fwd_puls_bayes'
   *  S-Function (ex_sfun_bayes4): '<S29>/rws_puls_bayes'
   *  S-Function (ex_sfun_bayes4): '<S29>/ss_puls_bayes'
   */
  rtb_BusCreator_m_fwd = ((uint8_T)CML_Bayes4( (uint8_T)rtb_fwd, (uint8_T)
    rtb_fwd_n, (uint8_T)rtb_fwd_o, (uint8_T)rtb_fwd_d, (uint8_T*)
    (&(vdy_cpt_whl_pulse_p[0]))));
  rtb_BusCreator_m_ss = ((uint8_T)CML_Bayes4( (uint8_T)rtb_ss, (uint8_T)rtb_ss_p,
                          (uint8_T)rtb_ss_g, (uint8_T)rtb_ss_c, (uint8_T*)
    (&(vdy_cpt_whl_pulse_p[0]))));
  rtb_BusCreator_m_rvs = ((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs, (uint8_T)
    rtb_rvs_o, (uint8_T)rtb_rvs_g, (uint8_T)rtb_rvs_f, (uint8_T*)
    (&(vdy_cpt_whl_pulse_p[0]))));

  /* Outputs for atomic SubSystem: '<S26>/Get_IO_State4' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State4_b, ((uint32_T)
    VDY_SIN_POS_WVEL_FL));

  /* end of Outputs for SubSystem: '<S26>/Get_IO_State4' */

  /* Outputs for atomic SubSystem: '<S26>/Get_IO_State1' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State1_d, ((uint32_T)
    VDY_SIN_POS_WVEL_FR));

  /* end of Outputs for SubSystem: '<S26>/Get_IO_State1' */

  /* Outputs for atomic SubSystem: '<S26>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_es,
    ((uint32_T)VDY_SIN_POS_WVEL_RL));

  /* end of Outputs for SubSystem: '<S26>/Get_IO_State2' */

  /* Outputs for atomic SubSystem: '<S26>/Get_IO_State3' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State3_b, ((uint32_T)
    VDY_SIN_POS_WVEL_RR));

  /* end of Outputs for SubSystem: '<S26>/Get_IO_State3' */

  /* Embedded MATLAB: '<S26>/any_whl_valid' */
  /* Embedded MATLAB Function 'bayes_net/bayes_puls_veh_velo/any_whl_valid': '<S37>:1' */
  /* #if any wheel speed is valid,dont use wheel tick info */
  if ((((((((((uint32_T)vdy_mot_st_B->Get_IO_State4_b.IndexVector) == ((uint32_T)
              VDY_IO_STATE_VALID)) || (((uint32_T)
              vdy_mot_st_B->Get_IO_State4_b.IndexVector) == ((uint32_T)
              VDY_IO_STATE_DECREASED))) || (((uint32_T)
             vdy_mot_st_B->Get_IO_State1_d.IndexVector) == ((uint32_T)
             VDY_IO_STATE_VALID))) || (((uint32_T)
            vdy_mot_st_B->Get_IO_State1_d.IndexVector) == ((uint32_T)
            VDY_IO_STATE_DECREASED))) || (((uint32_T)
           vdy_mot_st_B->Get_IO_State2_es.IndexVector) == ((uint32_T)
           VDY_IO_STATE_VALID))) || (((uint32_T)
          vdy_mot_st_B->Get_IO_State2_es.IndexVector) == ((uint32_T)
          VDY_IO_STATE_DECREASED))) || (((uint32_T)
         vdy_mot_st_B->Get_IO_State3_b.IndexVector) == ((uint32_T)
         VDY_IO_STATE_VALID))) || (((uint32_T)
        vdy_mot_st_B->Get_IO_State3_b.IndexVector) == ((uint32_T)
        VDY_IO_STATE_DECREASED))) {
    /* '<S37>:1:3' */
    /* '<S37>:1:4' */
    /* '<S37>:1:5' */
    /* '<S37>:1:6' */
    /* '<S37>:1:7' */
    rtb_any_whl_valid = TRUE;
  } else {
    /* '<S37>:1:9' */
    rtb_any_whl_valid = FALSE;
  }

  /* Embedded MATLAB: '<S26>/Wheel Tick Consider' incorporates:
   *  Constant: '<S26>/vdy_whl_puls_perc'
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   */
  /* Embedded MATLAB Function 'bayes_net/bayes_puls_veh_velo/Wheel Tick Consider': '<S36>:1' */
  /*  Don't use the wheel pulses in motion state estimation if any of wheel */
  /*  speed is available.But wheel pulses probabilty is used in yaw rate standstill offset learning in Ywr.c. */
  if (rtb_any_whl_valid) {
    /* '<S36>:1:7' */
    rtb_fwd_percentage_j = vdy_whl_puls_to_perc_p[4];

    /* '<S36>:1:8' */
    rtb_ss_percentage_h = vdy_whl_puls_to_perc_p[9];

    /* '<S36>:1:9' */
    rtb_rws_percentage_p = vdy_whl_puls_to_perc_p[4];
  } else {
    /* '<S36>:1:11' */
    rtb_fwd_percentage_j = rtb_BusCreator_m_fwd;

    /* '<S36>:1:12' */
    rtb_ss_percentage_h = rtb_BusCreator_m_ss;

    /* '<S36>:1:13' */
    rtb_rws_percentage_p = rtb_BusCreator_m_rvs;
  }

  /* BusSelector: '<S26>/Bus Selector4' incorporates:
   *  BusCreator: '<S8>/Bus Creator'
   */
  rtb_fwd_j = rtb_fwd_percentage_a;

  /* BusSelector: '<S26>/Bus Selector3' incorporates:
   *  BusCreator: '<S8>/Bus Creator'
   */
  rtb_ss_h = rtb_ss_percentage_o;

  /* BusSelector: '<S26>/Bus Selector5' incorporates:
   *  BusCreator: '<S8>/Bus Creator'
   */
  rtb_rvs_e = rtb_rws_percentage_e;

  /* BusCreator: '<S26>/Bus Creator' incorporates:
   *  BusSelector: '<S26>/Bus Selector3'
   *  BusSelector: '<S26>/Bus Selector4'
   *  BusSelector: '<S26>/Bus Selector5'
   *  Constant: '<S26>/vdy_cpt_puls_velo'
   *  S-Function (ex_sfun_bayes2): '<S26>/fwd_direction_bayes'
   *  S-Function (ex_sfun_bayes2): '<S26>/rws_direction_bayes'
   *  S-Function (ex_sfun_bayes2): '<S26>/ss_direction_bayes'
   */
  rtb_BusCreator_g_fwd = ((uint8_T)CML_Bayes2( (percentage_t)
    rtb_fwd_percentage_j, (percentage_t)rtb_fwd_j, (percentage_t*)
    (&(vdy_cpt_pulse_velo_p[0]))));
  rtb_BusCreator_g_ss = ((uint8_T)CML_Bayes2( (percentage_t)rtb_ss_percentage_h,
                          (percentage_t)rtb_ss_h, (percentage_t*)
    (&(vdy_cpt_pulse_velo_p[0]))));
  rtb_BusCreator_g_rvs = ((uint8_T)CML_Bayes2( (percentage_t)
    rtb_rws_percentage_p, (percentage_t)rtb_rvs_e, (percentage_t*)
    (&(vdy_cpt_pulse_velo_p[0]))));

  /* BusSelector: '<S28>/Bus Selector1' */
  rtb_fwd_f = rtb_front_left_fwd;
  rtb_fwd_b = rtb_front_right_fwd;
  rtb_fwd_l = rtb_rear_left_fwd;
  rtb_fwd_e = rtb_BusCreator4_d_rear_right_fw;

  /* BusSelector: '<S28>/Bus Selector' */
  rtb_ss_g0 = rtb_front_left_ss;
  rtb_ss_i = rtb_front_right_ss;
  rtb_ss_l = rtb_rear_left_ss;
  rtb_ss_o = rtb_BusCreator4_d_rear_right_ss;

  /* BusSelector: '<S28>/Bus Selector2' */
  rtb_rvs_m = rtb_front_left_rvs;
  rtb_rvs_oo = rtb_front_right_rvs;
  rtb_rvs_a = rtb_rear_left_rvs;
  rtb_rvs_jo = rtb_BusCreator4_d_rear_right_rv;

  /* BusCreator: '<S28>/Bus Creator' incorporates:
   *  BusSelector: '<S28>/Bus Selector'
   *  BusSelector: '<S28>/Bus Selector1'
   *  BusSelector: '<S28>/Bus Selector2'
   *  Constant: '<S28>/vdy_cpt_whl_pulse'
   *  S-Function (ex_sfun_bayes4): '<S28>/fwd_direction_bayes'
   *  S-Function (ex_sfun_bayes4): '<S28>/rws_direction_bayes'
   *  S-Function (ex_sfun_bayes4): '<S28>/ss_direction_bayes'
   */
  rtb_BusCreator_c.fwd = ((uint8_T)CML_Bayes4( (uint8_T)rtb_fwd_f, (uint8_T)
    rtb_fwd_b, (uint8_T)rtb_fwd_l, (uint8_T)rtb_fwd_e, (uint8_T*)
    (&(vdy_cpt_whl_pulse_p[0]))));
  rtb_BusCreator_c.ss = ((uint8_T)CML_Bayes4( (uint8_T)rtb_ss_g0, (uint8_T)
    rtb_ss_i, (uint8_T)rtb_ss_l, (uint8_T)rtb_ss_o, (uint8_T*)
    (&(vdy_cpt_whl_pulse_p[0]))));
  rtb_BusCreator_c.rvs = ((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs_m, (uint8_T)
    rtb_rvs_oo, (uint8_T)rtb_rvs_a, (uint8_T)rtb_rvs_jo, (uint8_T*)
    (&(vdy_cpt_whl_pulse_p[0]))));

  /* Outputs for atomic SubSystem: '<S30>/Get_IO_State8' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State8_b, ((uint32_T)
    VDY_SIN_POS_WDIR_FL));

  /* end of Outputs for SubSystem: '<S30>/Get_IO_State8' */

  /* Outputs for atomic SubSystem: '<S30>/Get_IO_State1' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State1_k, ((uint32_T)
    VDY_SIN_POS_WDIR_FR));

  /* end of Outputs for SubSystem: '<S30>/Get_IO_State1' */

  /* Outputs for atomic SubSystem: '<S30>/Get_IO_State2' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State2_m1,
    ((uint32_T)VDY_SIN_POS_WDIR_RL));

  /* end of Outputs for SubSystem: '<S30>/Get_IO_State2' */

  /* Outputs for atomic SubSystem: '<S30>/Get_IO_State3' */
  vdy_mot_st_Get_IO_State2(rtb_State, &vdy_mot_st_B->Get_IO_State3_eg,
    ((uint32_T)VDY_SIN_POS_WDIR_RR));

  /* end of Outputs for SubSystem: '<S30>/Get_IO_State3' */

  /* If: '<S30>/If' incorporates:
   *  ActionPort: '<S38>/Action Port'
   *  ActionPort: '<S43>/Action Port'
   *  Logic: '<S30>/whl_dir_valid'
   *  SubSystem: '<S30>/ALN_dir'
   *  SubSystem: '<S30>/whl_dir'
   */
  if (!((((vdy_mot_st_B->Get_IO_State8_b.IndexVector != 0) &&
          (vdy_mot_st_B->Get_IO_State1_k.IndexVector != 0)) &&
         (vdy_mot_st_B->Get_IO_State2_m1.IndexVector != 0)) &&
        (vdy_mot_st_B->Get_IO_State3_eg.IndexVector != 0))) {
    vdy_mot_st_whl_dir(&rtb_BusCreator_c, &rtb_Merge);
  } else {
    vdy_mot_st_whl_dir(&rtb_BusCreator_e, &rtb_Merge);
  }

  /* BusSelector: '<S27>/Bus Selector1' */
  rtb_fwd_o3 = rtb_BusCreator_g_fwd;

  /* BusSelector: '<S27>/Bus Selector4' */
  rtb_fwd_m = rtb_Merge.fwd;

  /* BusSelector: '<S27>/Bus Selector' */
  rtb_ss_gr = rtb_BusCreator_g_ss;

  /* BusSelector: '<S27>/Bus Selector3' */
  rtb_ss_gp = rtb_Merge.ss;

  /* BusSelector: '<S27>/Bus Selector2' */
  rtb_rvs_ay = rtb_BusCreator_g_rvs;

  /* BusSelector: '<S27>/Bus Selector5' */
  rtb_rvs_ge = rtb_Merge.rvs;

  /* BusCreator: '<S27>/Bus Creator' incorporates:
   *  BusSelector: '<S27>/Bus Selector'
   *  BusSelector: '<S27>/Bus Selector1'
   *  BusSelector: '<S27>/Bus Selector2'
   *  BusSelector: '<S27>/Bus Selector3'
   *  BusSelector: '<S27>/Bus Selector4'
   *  BusSelector: '<S27>/Bus Selector5'
   *  Constant: '<S27>/vdy_cpt_puls_velo_dir'
   *  S-Function (ex_sfun_bayes2): '<S27>/fwd_bayes'
   *  S-Function (ex_sfun_bayes2): '<S27>/rws_bayes'
   *  S-Function (ex_sfun_bayes2): '<S27>/ss_bayes'
   */
  rtb_BusCreator_p_fwd = ((uint8_T)CML_Bayes2( (percentage_t)rtb_fwd_o3,
    (percentage_t)rtb_fwd_m, (percentage_t*)(&(vdy_cpt_pulse_velo_dir_p[0]))));
  rtb_BusCreator_p_ss = ((uint8_T)CML_Bayes2( (percentage_t)rtb_ss_gr,
    (percentage_t)rtb_ss_gp, (percentage_t*)(&(vdy_cpt_pulse_velo_dir_p[0]))));
  rtb_BusCreator_p_rvs = ((uint8_T)CML_Bayes2( (percentage_t)rtb_rvs_ay,
    (percentage_t)rtb_rvs_ge, (percentage_t*)(&(vdy_cpt_pulse_velo_dir_p[0]))));

  /* BusSelector: '<S24>/Bus Selector1' incorporates:
   *  BusSelector: '<S27>/Bus Selector1'
   *  BusSelector: '<S27>/Bus Selector4'
   *  Constant: '<S27>/vdy_cpt_puls_velo_dir'
   *  S-Function (ex_sfun_bayes2): '<S27>/fwd_bayes'
   */
  rtb_fwd_ct = ((uint8_T)CML_Bayes2( (percentage_t)rtb_fwd_o3, (percentage_t)
    rtb_fwd_m, (percentage_t*)(&(vdy_cpt_pulse_velo_dir_p[0]))));

  /* BusSelector: '<S24>/Bus Selector4' incorporates:
   *  BusCreator: '<S46>/Bus Creator'
   */
  rtb_fwd_ot = rtb_fwd_percentage_g;

  /* BusSelector: '<S24>/Bus Selector' */
  rtb_ss_d1 = rtb_BusCreator_p_ss;

  /* BusSelector: '<S24>/Bus Selector3' incorporates:
   *  BusCreator: '<S46>/Bus Creator'
   */
  rtb_ss_f = rtb_ss_percentage_l;

  /* BusSelector: '<S24>/Bus Selector2' */
  rtb_rvs_ei = rtb_BusCreator_p_rvs;

  /* BusSelector: '<S24>/Bus Selector5' incorporates:
   *  BusCreator: '<S46>/Bus Creator'
   */
  rtb_rvs_n0 = rtb_rws_percentage_ic;

  /* BusCreator: '<S24>/Bus Creator' incorporates:
   *  BusSelector: '<S24>/Bus Selector'
   *  BusSelector: '<S24>/Bus Selector2'
   *  BusSelector: '<S24>/Bus Selector3'
   *  BusSelector: '<S24>/Bus Selector5'
   *  Constant: '<S24>/vdy_cpt_pre_beak_torque'
   *  S-Function (ex_sfun_bayes2): '<S24>/rws_bayes'
   *  S-Function (ex_sfun_bayes2): '<S24>/ss_bayes'
   */
  rtb_fwd_percentage_fn = ((uint8_T)CML_Bayes2( (percentage_t)rtb_ss_d1,
    (percentage_t)rtb_ss_f, (percentage_t*)(&(vdy_cpt_pre_break_torque_p[0]))));
  rtb_ss_percentage_c = ((uint8_T)CML_Bayes2( (percentage_t)rtb_rvs_ei,
    (percentage_t)rtb_rvs_n0, (percentage_t*)(&(vdy_cpt_pre_break_torque_p[0]))));

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  BusSelector: '<S24>/Bus Selector'
   *  BusSelector: '<S24>/Bus Selector1'
   *  BusSelector: '<S24>/Bus Selector2'
   *  BusSelector: '<S24>/Bus Selector3'
   *  BusSelector: '<S24>/Bus Selector4'
   *  BusSelector: '<S24>/Bus Selector5'
   *  Constant: '<S24>/vdy_cpt_pre_beak_torque'
   *  S-Function (ex_sfun_bayes2): '<S24>/fwd_bayes'
   *  S-Function (ex_sfun_bayes2): '<S24>/rws_bayes'
   *  S-Function (ex_sfun_bayes2): '<S24>/ss_bayes'
   */
  rtb_mot_st_bayes_out_stage_3_fw = rtb_Merge.fwd;
  rtb_mot_st_bayes_out_stage_3_ss = rtb_Merge.ss;
  rtb_mot_st_bayes_out_stage_3_rv = rtb_Merge.rvs;
  rtb_mot_st_bayes_out_stage_5_fw = ((uint8_T)CML_Bayes2( (percentage_t)
    rtb_fwd_ct, (percentage_t)rtb_fwd_ot, (percentage_t*)
    (&(vdy_cpt_pre_break_torque_p[0]))));
  rtb_rws_percentage_ek = ((uint8_T)CML_Bayes2( (percentage_t)rtb_ss_d1,
    (percentage_t)rtb_ss_f, (percentage_t*)(&(vdy_cpt_pre_break_torque_p[0]))));
  rtb_mot_st_bayes_out_stage_5_rv = ((uint8_T)CML_Bayes2( (percentage_t)
    rtb_rvs_ei, (percentage_t)rtb_rvs_n0, (percentage_t*)
    (&(vdy_cpt_pre_break_torque_p[0]))));

  /* BusSelector: '<S25>/Bus Selector1' incorporates:
   *  BusSelector: '<S24>/Bus Selector1'
   *  BusSelector: '<S24>/Bus Selector4'
   *  Constant: '<S24>/vdy_cpt_pre_beak_torque'
   *  S-Function (ex_sfun_bayes2): '<S24>/fwd_bayes'
   */
  rtb_fwd_k = ((uint8_T)CML_Bayes2( (percentage_t)rtb_fwd_ct, (percentage_t)
    rtb_fwd_ot, (percentage_t*)(&(vdy_cpt_pre_break_torque_p[0]))));

  /* BusSelector: '<S25>/Bus Selector4' incorporates:
   *  BusCreator: '<S6>/Bus Creator'
   */
  rtb_fwd_f2 = rtb_fwd_percentage_n;

  /* BusSelector: '<S25>/Bus Selector8' incorporates:
   *  BusCreator: '<S7>/Bus Creator'
   */
  rtb_fwd_kj = rtb_fwd_percentage_f;

  /* BusSelector: '<S25>/Bus Selector9' incorporates:
   *  BusCreator: '<S11>/Bus Creator'
   */
  rtb_fwd_lv = rtb_DataTypeConversion;

  /* BusSelector: '<S25>/Bus Selector' */
  rtb_ss_fb = rtb_fwd_percentage_fn;

  /* BusSelector: '<S25>/Bus Selector3' incorporates:
   *  BusCreator: '<S6>/Bus Creator'
   */
  rtb_ss_lh = rtb_ss_percentage_g;

  /* BusSelector: '<S25>/Bus Selector7' incorporates:
   *  BusCreator: '<S7>/Bus Creator'
   */
  rtb_ss_j = rtb_ss_percentage_m;

  /* BusSelector: '<S25>/Bus Selector10' incorporates:
   *  BusCreator: '<S11>/Bus Creator'
   */
  rtb_ss_m = rtb_ss_percentage;

  /* BusSelector: '<S25>/Bus Selector2' */
  rtb_rvs_h = rtb_ss_percentage_c;

  /* BusSelector: '<S25>/Bus Selector5' incorporates:
   *  BusCreator: '<S6>/Bus Creator'
   */
  rtb_rvs_ep = rtb_rws_percentage_i;

  /* BusSelector: '<S25>/Bus Selector6' incorporates:
   *  BusCreator: '<S7>/Bus Creator'
   */
  rtb_rvs_jy = rtb_rws_percentage_k;

  /* BusSelector: '<S25>/Bus Selector11' incorporates:
   *  BusCreator: '<S11>/Bus Creator'
   */
  rtb_rvs_ca = rtb_rws_percentage;

  /* Embedded MATLAB: '<S31>/state_decider' incorporates:
   *  BusCreator: '<S25>/Bus Creator'
   *  BusSelector: '<S25>/Bus Selector'
   *  BusSelector: '<S25>/Bus Selector1'
   *  BusSelector: '<S25>/Bus Selector10'
   *  BusSelector: '<S25>/Bus Selector11'
   *  BusSelector: '<S25>/Bus Selector2'
   *  BusSelector: '<S25>/Bus Selector3'
   *  BusSelector: '<S25>/Bus Selector4'
   *  BusSelector: '<S25>/Bus Selector5'
   *  BusSelector: '<S25>/Bus Selector6'
   *  BusSelector: '<S25>/Bus Selector7'
   *  BusSelector: '<S25>/Bus Selector8'
   *  BusSelector: '<S25>/Bus Selector9'
   *  Constant: '<S25>/vdy_cpt_pre_gear_parking'
   *  S-Function (ex_sfun_bayes4): '<S25>/fwd_bayes'
   *  S-Function (ex_sfun_bayes4): '<S25>/rws_bayes'
   *  S-Function (ex_sfun_bayes4): '<S25>/ss_bayes'
   */
  /* Embedded MATLAB Function 'bayes_net/state_decider/state_decider': '<S44>:1' */
  /*  decide if the vehicle motion state moving(forward or reverse), forward, reverse or stand still */
  if ((((uint8_T)CML_Bayes4( (uint8_T)rtb_fwd_k, (uint8_T)rtb_fwd_f2, (uint8_T)
         rtb_fwd_kj, (uint8_T)rtb_fwd_lv, (uint8_T*)
         (&(vdy_cpt_pre_gear_parking_p[0])))) >= ((uint8_T)CML_Bayes4( (uint8_T)
         rtb_ss_fb, (uint8_T)rtb_ss_lh, (uint8_T)rtb_ss_j, (uint8_T)rtb_ss_m,
         (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0]))))) && (((uint8_T)
        CML_Bayes4( (uint8_T)rtb_fwd_k, (uint8_T)rtb_fwd_f2, (uint8_T)rtb_fwd_kj,
                   (uint8_T)rtb_fwd_lv, (uint8_T*)(&(vdy_cpt_pre_gear_parking_p
           [0])))) > ((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs_h, (uint8_T)
         rtb_rvs_ep, (uint8_T)rtb_rvs_jy, (uint8_T)rtb_rvs_ca, (uint8_T*)
         (&(vdy_cpt_pre_gear_parking_p[0])))))) {
    /* '<S44>:1:3' */
    /*  if the quality for forward is geater or equal to stand still and reverse is less then forward */
    /*  the motion state is forward */
    /* '<S44>:1:6' */
    rtb_fwd_percentage_fn = ((uint8_T)VDY_LONG_MOT_STATE_MOVE_FWD);

    /* uint8(1); */
    /* '<S44>:1:7' */
    rtb_ss_percentage_c = ((uint8_T)CML_Bayes4( (uint8_T)rtb_fwd_k, (uint8_T)
      rtb_fwd_f2, (uint8_T)rtb_fwd_kj, (uint8_T)rtb_fwd_lv, (uint8_T*)
      (&(vdy_cpt_pre_gear_parking_p[0]))));
  } else if ((((uint8_T)CML_Bayes4( (uint8_T)rtb_ss_fb, (uint8_T)rtb_ss_lh,
                (uint8_T)rtb_ss_j, (uint8_T)rtb_ss_m, (uint8_T*)
                (&(vdy_cpt_pre_gear_parking_p[0])))) > ((uint8_T)CML_Bayes4
               ( (uint8_T)rtb_fwd_k, (uint8_T)rtb_fwd_f2, (uint8_T)rtb_fwd_kj,
                (uint8_T)rtb_fwd_lv, (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0])))))
             && (((uint8_T)CML_Bayes4( (uint8_T)rtb_ss_fb, (uint8_T)rtb_ss_lh,
                (uint8_T)rtb_ss_j, (uint8_T)rtb_ss_m, (uint8_T*)
                (&(vdy_cpt_pre_gear_parking_p[0])))) > ((uint8_T)CML_Bayes4
               ( (uint8_T)rtb_rvs_h, (uint8_T)rtb_rvs_ep, (uint8_T)rtb_rvs_jy,
                (uint8_T)rtb_rvs_ca, (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0]))))))
  {
    /* '<S44>:1:8' */
    /*  elseif the quality for stand still is greater as forward and reverse */
    /*  the motion state is stand still */
    /* '<S44>:1:11' */
    rtb_fwd_percentage_fn = ((uint8_T)VDY_LONG_MOT_STATE_STDST);

    /*  uint8(0); */
    /* '<S44>:1:12' */
    rtb_ss_percentage_c = ((uint8_T)CML_Bayes4( (uint8_T)rtb_ss_fb, (uint8_T)
      rtb_ss_lh, (uint8_T)rtb_ss_j, (uint8_T)rtb_ss_m, (uint8_T*)
      (&(vdy_cpt_pre_gear_parking_p[0]))));
  } else if ((((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs_h, (uint8_T)rtb_rvs_ep,
                (uint8_T)rtb_rvs_jy, (uint8_T)rtb_rvs_ca, (uint8_T*)
                (&(vdy_cpt_pre_gear_parking_p[0])))) > ((uint8_T)CML_Bayes4
               ( (uint8_T)rtb_fwd_k, (uint8_T)rtb_fwd_f2, (uint8_T)rtb_fwd_kj,
                (uint8_T)rtb_fwd_lv, (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0])))))
             && (((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs_h, (uint8_T)rtb_rvs_ep,
                (uint8_T)rtb_rvs_jy, (uint8_T)rtb_rvs_ca, (uint8_T*)
                (&(vdy_cpt_pre_gear_parking_p[0])))) >= ((uint8_T)CML_Bayes4
               ( (uint8_T)rtb_ss_fb, (uint8_T)rtb_ss_lh, (uint8_T)rtb_ss_j,
                (uint8_T)rtb_ss_m, (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0]))))))
  {
    /* '<S44>:1:13' */
    /*  elseif the quality for reverse is greater or equal to stand still and forward is less then reverse */
    /*  the motion state is reverse */
    /* '<S44>:1:16' */
    rtb_fwd_percentage_fn = ((uint8_T)VDY_LONG_MOT_STATE_MOVE_RWD);

    /* uint8(-1); */
    /* '<S44>:1:17' */
    rtb_ss_percentage_c = ((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs_h, (uint8_T)
      rtb_rvs_ep, (uint8_T)rtb_rvs_jy, (uint8_T)rtb_rvs_ca, (uint8_T*)
      (&(vdy_cpt_pre_gear_parking_p[0]))));
  } else if (((uint8_T)CML_Bayes4( (uint8_T)rtb_rvs_h, (uint8_T)rtb_rvs_ep,
               (uint8_T)rtb_rvs_jy, (uint8_T)rtb_rvs_ca, (uint8_T*)
               (&(vdy_cpt_pre_gear_parking_p[0])))) == ((uint8_T)CML_Bayes4
              ( (uint8_T)rtb_fwd_k, (uint8_T)rtb_fwd_f2, (uint8_T)rtb_fwd_kj,
               (uint8_T)rtb_fwd_lv, (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0])))))
  {
    /* '<S44>:1:18' */
    /*  elseif the quality of reverse is equal to forward */
    /*  the motion state is moving */
    /* '<S44>:1:21' */
    rtb_fwd_percentage_fn = ((uint8_T)VDY_LONG_MOT_STATE_MOVE);

    /* uint8(0.5); */
    /* '<S44>:1:22' */
    rtb_ss_percentage_c = ((uint8_T)CML_Bayes4( (uint8_T)rtb_fwd_k, (uint8_T)
      rtb_fwd_f2, (uint8_T)rtb_fwd_kj, (uint8_T)rtb_fwd_lv, (uint8_T*)
      (&(vdy_cpt_pre_gear_parking_p[0]))));
  } else {
    /* '<S44>:1:24' */
    rtb_fwd_percentage_fn = ((uint8_T)VDY_LONG_MOT_STATE_MOVE);

    /* '<S44>:1:25' */
    rtb_ss_percentage_c = 0U;
  }

  /* Outport: '<Root>/vdy_mot_st_out' incorporates:
   *  BusCreator: '<Root>/Bus Creator1'
   *  BusCreator: '<S11>/Bus Creator'
   *  BusCreator: '<S25>/Bus Creator'
   *  BusCreator: '<S31>/Bus Creator'
   *  BusCreator: '<S46>/Bus Creator'
   *  BusCreator: '<S6>/Bus Creator'
   *  BusCreator: '<S7>/Bus Creator'
   *  BusCreator: '<S8>/Bus Creator'
   *  BusSelector: '<S25>/Bus Selector'
   *  BusSelector: '<S25>/Bus Selector1'
   *  BusSelector: '<S25>/Bus Selector10'
   *  BusSelector: '<S25>/Bus Selector11'
   *  BusSelector: '<S25>/Bus Selector2'
   *  BusSelector: '<S25>/Bus Selector3'
   *  BusSelector: '<S25>/Bus Selector4'
   *  BusSelector: '<S25>/Bus Selector5'
   *  BusSelector: '<S25>/Bus Selector6'
   *  BusSelector: '<S25>/Bus Selector7'
   *  BusSelector: '<S25>/Bus Selector8'
   *  BusSelector: '<S25>/Bus Selector9'
   *  Constant: '<S25>/vdy_cpt_pre_gear_parking'
   *  S-Function (ex_sfun_bayes4): '<S25>/fwd_bayes'
   *  S-Function (ex_sfun_bayes4): '<S25>/rws_bayes'
   *  S-Function (ex_sfun_bayes4): '<S25>/ss_bayes'
   */
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.front_left.fwd =
    rtb_BusCreator4_front_left_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.front_left.ss =
    rtb_BusCreator4_front_left_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.front_left.rvs =
    rtb_BusCreator4_front_left_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.front_right.fwd
    = rtb_BusCreator4_front_right_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.front_right.ss =
    rtb_BusCreator4_front_right_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.front_right.rvs
    = rtb_BusCreator4_front_right_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.rear_left.fwd =
    rtb_BusCreator4_rear_left_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.rear_left.ss =
    rtb_BusCreator4_rear_left_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.rear_left.rvs =
    rtb_BusCreator4_rear_left_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.rear_right.fwd =
    rtb_BusCreator4_rear_right_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.rear_right.ss =
    rtb_BusCreator4_rear_right_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_puls_states.rear_right.rvs =
    rtb_BusCreator4_rear_right_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.veh_velocity_state.fwd =
    rtb_fwd_percentage_a;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.veh_velocity_state.ss =
    rtb_ss_percentage_o;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.veh_velocity_state.rvs =
    rtb_rws_percentage_e;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.front_left.fwd =
    rtb_front_left_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.front_left.ss =
    rtb_front_left_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.front_left.rvs =
    rtb_front_left_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.front_right.fwd =
    rtb_front_right_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.front_right.ss =
    rtb_front_right_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.front_right.rvs =
    rtb_front_right_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.rear_left.fwd =
    rtb_rear_left_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.rear_left.ss =
    rtb_rear_left_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.rear_left.rvs =
    rtb_rear_left_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.rear_right.fwd =
    rtb_BusCreator4_d_rear_right_fw;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.rear_right.ss =
    rtb_BusCreator4_d_rear_right_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.whl_dir_states.rear_right.rvs =
    rtb_BusCreator4_d_rear_right_rv;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.brake_torque_state.fwd =
    rtb_fwd_percentage_g;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.brake_torque_state.ss =
    rtb_ss_percentage_l;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.brake_torque_state.rvs =
    rtb_rws_percentage_ic;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.gear_shift_state.fwd =
    rtb_fwd_percentage_n;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.gear_shift_state.ss =
    rtb_ss_percentage_g;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.gear_shift_state.rvs =
    rtb_rws_percentage_i;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.park_brake_state.fwd =
    rtb_fwd_percentage_f;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.park_brake_state.ss =
    rtb_ss_percentage_m;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.park_brake_state.rvs =
    rtb_rws_percentage_k;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.yaw_rate_state.fwd =
    rtb_DataTypeConversion;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.yaw_rate_state.ss =
    rtb_ss_percentage;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.yaw_rate_state.rvs =
    rtb_rws_percentage;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.ALN_dir_states.fwd =
    rtb_mot_st_bayes_in_ALN_dir_sta;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.ALN_dir_states.ss =
    rtb_mot_st_bayes_in_ALN_dir_s_0;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_in.ALN_dir_states.rvs =
    rtb_mot_st_bayes_in_ALN_dir_s_1;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_1.fwd =
    rtb_BusCreator_m_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_1.ss =
    rtb_BusCreator_m_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_1.rvs =
    rtb_BusCreator_m_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_2.fwd =
    rtb_BusCreator_g_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_2.ss =
    rtb_BusCreator_g_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_2.rvs =
    rtb_BusCreator_g_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_3.fwd =
    rtb_mot_st_bayes_out_stage_3_fw;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_3.ss =
    rtb_mot_st_bayes_out_stage_3_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_3.rvs =
    rtb_mot_st_bayes_out_stage_3_rv;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_4.fwd =
    rtb_BusCreator_p_fwd;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_4.ss =
    rtb_BusCreator_p_ss;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_4.rvs =
    rtb_BusCreator_p_rvs;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_5.fwd =
    rtb_mot_st_bayes_out_stage_5_fw;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_5.ss =
    rtb_rws_percentage_ek;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_bayes_out.stage_5.rvs =
    rtb_mot_st_bayes_out_stage_5_rv;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_out.fwd = ((uint8_T)CML_Bayes4( (uint8_T)
    rtb_fwd_k, (uint8_T)rtb_fwd_f2, (uint8_T)rtb_fwd_kj, (uint8_T)rtb_fwd_lv,
    (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0]))));
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_out.ss = ((uint8_T)CML_Bayes4( (uint8_T)
    rtb_ss_fb, (uint8_T)rtb_ss_lh, (uint8_T)rtb_ss_j, (uint8_T)rtb_ss_m,
    (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0]))));
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_out.rvs = ((uint8_T)CML_Bayes4( (uint8_T)
    rtb_rvs_h, (uint8_T)rtb_rvs_ep, (uint8_T)rtb_rvs_jy, (uint8_T)rtb_rvs_ca,
    (uint8_T*)(&(vdy_cpt_pre_gear_parking_p[0]))));
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_out.mot_state = rtb_fwd_percentage_fn;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_out.mot_quality = rtb_ss_percentage_c;
  (*vdy_mot_st_Y_vdy_mot_st_out).mot_st_out.mot_counter = mot_counter;

  /* Update for UnitDelay: '<S8>/cnt_delay_down' */
  vdy_mot_st_DWork->cnt_delay_down_DSTATE = cnt_out_down;

  /* Update for UnitDelay: '<S8>/cnt_delay_up' */
  vdy_mot_st_DWork->cnt_delay_up_DSTATE = cnt_out_up;

  /* Update for UnitDelay: '<S6>/last rvs' */
  vdy_mot_st_DWork->lastrvs_DSTATE = rtb_rws_percentage_i;

  /* Update for UnitDelay: '<S6>/last ss' */
  vdy_mot_st_DWork->lastss_DSTATE = rtb_ss_percentage_g;

  /* Update for UnitDelay: '<S6>/last fwd' */
  vdy_mot_st_DWork->lastfwd_DSTATE = rtb_fwd_percentage_n;

  /* Update for UnitDelay: '<S135>/UD' */
  vdy_mot_st_DWork->UD_DSTATE = rtb_Yk1;

  /* Update for UnitDelay: '<S134>/UD' incorporates:
   *  Update for Inport: '<Root>/VDYInternalData_in'
   */
  vdy_mot_st_DWork->UD_DSTATE_k = (*vdy_mot_st_U_VDYInternalData_in).
    vdy_ye_out.veh_yaw_rate;

  /* Update for UnitDelay: '<S136>/T3' */
  vdy_mot_st_DWork->T3_DSTATE = rtb_T2;

  /* Update for UnitDelay: '<S136>/T2' */
  vdy_mot_st_DWork->T2_DSTATE = rtb_T1;

  /* Update for UnitDelay: '<S136>/T1' */
  vdy_mot_st_DWork->T1_DSTATE = rtb_T0;

  /* Update for UnitDelay: '<S136>/T0' */
  vdy_mot_st_DWork->T0_DSTATE = rtb_T4;

  /* Update for UnitDelay: '<S136>/T4' */
  vdy_mot_st_DWork->T4_DSTATE = rtb_T5;

  /* Update for UnitDelay: '<S136>/T5' */
  vdy_mot_st_DWork->T5_DSTATE = rtb_T6;

  /* Update for UnitDelay: '<S136>/T6' incorporates:
   *  Update for Inport: '<Root>/VDYInternalData_in'
   */
  vdy_mot_st_DWork->T6_DSTATE = (*vdy_mot_st_U_VDYInternalData_in).
    vdy_ye_out.veh_yaw_rate_var;

  /* Update for UnitDelay: '<S1>/FWD_Init7' */
  vdy_mot_st_DWork->FWD_Init7_DSTATE = rtb_fwd_percentage_e;

  /* Update for UnitDelay: '<S1>/SS_Init6' */
  vdy_mot_st_DWork->SS_Init6_DSTATE = rtb_ss_percentage_j;

  /* Update for UnitDelay: '<S1>/RWS_Init5' */
  vdy_mot_st_DWork->RWS_Init5_DSTATE = rtb_rws_percentage_c;

  /* Update for UnitDelay: '<S1>/mot_count_delay' */
  vdy_mot_st_DWork->mot_count_delay_DSTATE = mot_counter;

  /* Update for UnitDelay: '<S1>/FWD_Init1' */
  vdy_mot_st_DWork->FWD_Init1_DSTATE = vdy_mot_st_B->ALN_Fwd.DataTypeConversion;

  /* Update for UnitDelay: '<S1>/FWD_Init3' */
  vdy_mot_st_DWork->FWD_Init3_DSTATE = vdy_mot_st_B->ALN_Ss.DataTypeConversion;

  /* Update for UnitDelay: '<S1>/FWD_Init4' */
  vdy_mot_st_DWork->FWD_Init4_DSTATE = vdy_mot_st_B->ALN_Rws.DataTypeConversion;
}

/* Model initialize function */
void vdy_mot_st_initialize(boolean_T firstTime, BlockIO_vdy_mot_st *vdy_mot_st_B,
  D_Work_vdy_mot_st *vdy_mot_st_DWork)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) vdy_memset_s(((void *) vdy_mot_st_B), 0,
                      sizeof(BlockIO_vdy_mot_st));

  /* states (dwork) */
  (void) vdy_memset_s((void *)vdy_mot_st_DWork, 0,
                      sizeof(D_Work_vdy_mot_st));

  /* InitializeConditions for UnitDelay: '<S1>/FWD_Init7' */
  vdy_mot_st_DWork->FWD_Init7_DSTATE = 33U;

  /* InitializeConditions for UnitDelay: '<S1>/SS_Init6' */
  vdy_mot_st_DWork->SS_Init6_DSTATE = 33U;

  /* InitializeConditions for UnitDelay: '<S1>/RWS_Init5' */
  vdy_mot_st_DWork->RWS_Init5_DSTATE = 33U;

  /* InitializeConditions for UnitDelay: '<S1>/FWD_Init1' */
  vdy_mot_st_DWork->FWD_Init1_DSTATE = 33U;

  /* InitializeConditions for atomic SubSystem: '<S1>/ALN_Fwd' */
  ALN_percenatge_probability_Init(&vdy_mot_st_DWork->ALN_Fwd);

  /* end of InitializeConditions for SubSystem: '<S1>/ALN_Fwd' */

  /* InitializeConditions for UnitDelay: '<S1>/FWD_Init3' */
  vdy_mot_st_DWork->FWD_Init3_DSTATE = 33U;

  /* InitializeConditions for atomic SubSystem: '<S1>/ALN_Ss' */
  ALN_percenatge_probability_Init(&vdy_mot_st_DWork->ALN_Ss);

  /* end of InitializeConditions for SubSystem: '<S1>/ALN_Ss' */

  /* InitializeConditions for UnitDelay: '<S1>/FWD_Init4' */
  vdy_mot_st_DWork->FWD_Init4_DSTATE = 33U;

  /* InitializeConditions for atomic SubSystem: '<S1>/ALN_Rws' */
  ALN_percenatge_probability_Init(&vdy_mot_st_DWork->ALN_Rws);

  /* end of InitializeConditions for SubSystem: '<S1>/ALN_Rws' */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
