/* $Header: DMC_Lat_LAT_Dmc_Status_Defintion.c 1.27 2020/08/20 10:42:55CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_LAT_Dmc_Status_Defintion.c
   C source code generated on           : Mon Aug 17 20:46:55 2020
   Filename of Simulink Model           : DMC_Lat_LAT_Dmc_Status_Defintion.mdl/.slx
   Revision of Simulink Model           : 1.2660
 ***************************************************************************************************
   Detailed informations needed to rebuild this code.

   MATLAB Version: 8.4.0.150421 (R2014b)
   MATLAB License Number: 40544997
   Operating System: Microsoft Windows 10 Enterprise Version 10.0 (Build 17763)
   Java Version: Java 1.7.0_11 b21 with Oracle Corporation Java HotSpot(TM) Client VM mixed mode

   MATLAB                                                Version 8.4        (R2014b)
   Simulink                                              Version 8.4        (R2014b)
   Communications System Toolbox                         Version 5.7        (R2014b)
   Computer Vision System Toolbox                        Version 6.1        (R2014b)
   Control System Toolbox                                Version 9.8        (R2014b)
   Curve Fitting Toolbox                                 Version 3.5        (R2014b)
   DSP System Toolbox                                    Version 8.7        (R2014b)
   Data Acquisition Toolbox                              Version 3.6        (R2014b)
   Database Toolbox                                      Version 5.2        (R2014b)
   Embedded Coder                                        Version 6.7        (R2014b)
   Filter Design HDL Coder                               Version 2.9.6      (R2014b)
   Fixed Point Designer                                  Version 4.3        (R2014b)
   Fuzzy Logic Toolbox                                   Version 2.2.20     (R2014b)
   Image Acquisition Toolbox                             Version 4.8        (R2014b)
   Image Processing Toolbox                              Version 9.1        (R2014b)
   Instrument Control Toolbox                            Version 3.6        (R2014b)
   MATLAB Builder NE                                     Version 4.2.2      (R2014b)
   MATLAB Coder                                          Version 2.7        (R2014b)
   MATLAB Compiler                                       Version 5.2        (R2014b)
   MATLAB Report Generator                               Version 4.0        (R2014b)
   Mapping Toolbox                                       Version 4.0.2      (R2014b)
   Model Predictive Control Toolbox                      Version 5.0        (R2014b)
   Model Based Calibration Toolbox                       Version 4.8        (R2014b)
   Neural Network Toolbox                                Version 8.2.1      (R2014b)
   Optimization Toolbox                                  Version 7.1        (R2014b)
   Parallel Computing Toolbox                            Version 6.5        (R2014b)
   Partial Differential Equation Toolbox                 Version 1.5        (R2014b)
   RF Toolbox                                            Version 2.15       (R2014b)
   Robust Control Toolbox                                Version 5.2        (R2014b)
   Signal Processing Toolbox                             Version 6.22       (R2014b)
   SimDriveline                                          Version 2.7        (R2014b)
   SimElectronics                                        Version 2.6        (R2014b)
   SimHydraulics                                         Version 1.15       (R2014b)
   SimMechanics                                          Version 4.5        (R2014b)
   SimPowerSystems                                       Version 6.2        (R2014b)
   SimRF                                                 Version 4.3        (R2014b)
   Simscape                                              Version 3.12       (R2014b)
   Simulink Coder                                        Version 8.7        (R2014b)
   Simulink Control Design                               Version 4.1        (R2014b)
   Simulink Design Optimization                          Version 2.6        (R2014b)
   Simulink Report Generator                             Version 4.0        (R2014b)
   Simulink Verification and Validation                  Version 3.8        (R2014b)
   Spreadsheet Link EX                                   Version 3.2.2      (R2014b)
   Stateflow                                             Version 8.4        (R2014b)
   Statistics Toolbox                                    Version 9.1        (R2014b)
   Symbolic Math Toolbox                                 Version 6.1        (R2014b)
   System Identification Toolbox                         Version 9.1        (R2014b)
   Vehicle Network Toolbox                               Version 2.3        (R2014b)
   Wavelet Toolbox                                       Version 4.14       (R2014b)
 ***************************************************************************************************
 ***************************************************************************************************
 */
/*
 ***************************************************************************************************
   List of disabled QA-C warnings ignored for automatic generated code.
 ***************************************************************************************************
   Warning  272: Value of integer expression is apparently not representable in the signed result type.
   Warning  295:  Result of << on value of signed expression is apparently implementation defined.
   Warning  502:  A right shift on signed data may be an arithmetic or a logical shift.
   Warning 0272: Value of integer expression is apparently not representable in the signed result type.
   Warning 0297: Value of signed expression is apparently not representable.
   Warning 0841: Use of #undef is not recommended in some programming standards.
   Warning 2204: Min_Brace case is not aligned to match its controlling switch statement.
   Warning 2209: Min_Brace This brace style is not consistent with exdented style.
   Warning 2215: Indentation is not consistent with configured depth.
   Warning 3112: Redundancy - This statement has no side-effect - it can be removed.
   Warning 3201: This statement is unreachable.
   Warning 3344: Testing a value should be made explicit: Avoid using control expression with implicit comparisions against 0
   Warning 3355: The result of this logical operation is always 'true'.
   Warning 3356: The value of this control expression is always 'true'.
   Warning 3358: The result of this logical operation is always 'true'.
   Warning 3359: The value of this control expression is always 'false'.
   Warning 3391: Extra parenthesis recommended.
   Warning 3398: Extra parenthesis recommended.
   Warning 3415: The right hand operand of '&&' or '||' has side effects.
   Warning 3757: Implicit conversion: unsigned short to short.
   Warning 4131: Left shift operation on signed operand
   Warning 3334: This declaration of ... hides a more global declaration.
   Warning  499: Right operand of shift operator is greater than or equal to the width of the underlying type.
   Warning 3203: The variable '%s' is set but never used.
   Warning 2002: No 'default' case found in this 'switch' statement.
   Warning  380: Number of macro definitions exceeds 4095 - program does not conform strictly to ISO:C99.
   Warning 4116: Operand of logical ! operator is not an 'effectively Boolean' expression.
   Warning 4115: Operand of logical && or || operator is not an 'effectively Boolean' expression.
   Warning  602: The identifier '%s' is reserved for use by the library
   Warning  310: Casting to different object pointer type.
   Warning 2203: This closing brace is not aligned appropriately with the matching opening brace.
   Warning 3673: The object addressed by the pointer parameter '%s' is not modified and so the pointer could be of type 'pointer to const'.
   Warning  311: Dangerous pointer cast results in loss of const qualification.
   Warning  606: Object '%s' is declared using typedefs which are different to those in a previous declaration.
   Warning 3451: The global identifier '%s' has been declared in more than one file.
   Warning 4104: Left hand operand of arithmetic or bitwise operator is a 'Boolean' expression.
   Warning 4105: Right hand operand of arithmetic or bitwise operator is a 'Boolean' expression.
   Warning 4130: Bitwise operations on signed data will give implementation defined results.
   Warning 2200: Indentation of this line is to the left of the line above.
   Warning 5013: Use of basic type 'char'.
   Further informations can be found in your simulink project. Refer to:
   ".\docs\coding_guidelines\AGC_MISRA_COMPLIANCE.rtf in your simulink project"
 ***************************************************************************************************
 */
/* Justification 272: AutoCode. */
/* Justification 295: AutoCode. */
/* Justification 502: AutoCode. */
/* Justification 0272: AutoCode. */
/* Justification 0297: AutoCode. */
/* Justification 0841: AutoCode. */
/* Justification 2204: AutoCode. */
/* Justification 2209: AutoCode. */
/* Justification 2215: AutoCode. */
/* Justification 3112: AutoCode. */
/* Justification 3201: AutoCode. */
/* Justification 3344: AutoCode. */
/* Justification 3355: AutoCode. */
/* Justification 3356: AutoCode. */
/* Justification 3358: AutoCode. */
/* Justification 3359: AutoCode. */
/* Justification 3391: AutoCode. */
/* Justification 3398: AutoCode. */
/* Justification 3415: AutoCode. */
/* Justification 3757: AutoCode. */
/* Justification 4131: AutoCode. */
/* Justification 2201: AutoCode. */
/* Justification 3334: AutoCode. */
/* Justification  499: AutoCode. */
/* Justification 3203: AutoCode. Autocoder optimisation of unused pathes does not remove code in variant coded blocks */
/* Justification 2002: AutoCode. Autocoder optimises empty default cases in switches */
/* Justification  380: AutoCode. */
/* Justification 4115: AutoCode. */
/* Justification 4116: AutoCode. */
/* Justification  602: AutoCode. */
/* Justification  310: AutoCode. */
/* Justification 2203: AutoCode. Brackets Alignment */
/* Justification 3673: AutoCode. */
/* Justification  311: AutoCode. */
/* Justification  606: AutoCode. */
/* Justification 3451: AutoCode. */
/* Justification 4104: AutoCode. Equal to 4105, but different operator only */
/* Justification 4105: AutoCode. */
/* Justification 4130: AutoCode. */
/* Justification 2200: AutoCode. Brackets Alignment */
/* Justification 5013: AutoCode. Variant coding of systems */
/* Justification 3447: AutoCode. '%s' has external linkage but this declaration is not in a header file. */
/* Justification 3408: AutoCode (TCS3). Avoids external linkage warning which incorrectly occurs at file global variables (call QA-Systems?) */
/* Justification 2203: AutoCode. This closing brace is not aligned appropriately with the matching opening brace. */
/* Justification 3210: AutoCode. The global identifier '%s' is declared but is not used. */
/* PRQA S 502, 4131, 295, 3757, 3344, 3112, 2204, 2209, 2215, 3356, 3359, 3201, 3391, 3355, 3358, 272, 3415, 3390, 3398, 297, 272, 841, 2201, 3334, 499, 3203, 2002, 380, 4115, 4116, 602, 310, 2203, 3673, 311, 606, 3451, 4104, 4105, 4130, 2200, 5013, 3447, 2203, 3210 EOF */
/* --- Includes --- */
#include "DMC_Lat_LAT_Dmc_Status_Defintion.h"
#include "DMC_Lat_LAT_Dmc_Status_Defintion_private.h"

/* Named constants for Chart: '<Root>/LAT_Dmc_Flow_Control' */
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_Active_Request ((uint8_T)1U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Active ((uint8_T)1U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Inactive ((uint8_T)2U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_active ((uint8_T)1U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_inactive ((uint8_T)2U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Ramping_down_Activity ((uint8_T)1U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_No_Request ((uint8_T)2U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_Use_LAT_Enable_Lateral_Control ((uint8_T)2U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_Was_Not_Zero ((uint8_T)1U)
#define DMC_Lat_LAT_Dmc_Status_Defintion_IN_Was_Zero ((uint8_T)2U)

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: signed_int16_t Lat_min_offset_state, [, ], 1  1,
   PARA: unsigned_int16_t Lat_dmc_status_override_cycles, [, ], 1  1,
   PARA: unsigned_int16_t Lat_force_trq_shut_off_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   CALL: DMC_Lat_LAT_Dmc_Status_Defintion_step()
   CALL: DMC_Lat_LAT_Dmc_Status_Defintion_initialize(0)
   FILE: DMC_Lat_LAT_Dmc_Status_Defintion.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_LAT_Dmc_Status_Defintion_T DMC_Lat_LAT_Dmc_Status_Defintion_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_LAT_Dmc_Status_Defintion' */
void DMC_Lat_LAT_Dmc_Status_Defintion_Init(int16_T *rt_erh2sI, int16_T
  *rt_e4ho4I)
{
  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk = 0.0F;

  /* InitializeConditions for Chart: '<Root>/LAT_Dmc_Flow_Control' */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Eps_Open_Interface_Request
    = 0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Open_Interface_Request =
    DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_Half_Torque_Overlay_Active_Filt
    = 0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt =
    DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Enable_Lateral_Control =
    0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control =
    DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Eps_Torque_Request_Zero_Filt
    = 0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Torque_Request_Zero_Filt =
    DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LKC_Activation_Status = 0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LKC_Activation_Status =
    DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_Last_loop_values = 0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_c1_DMC_Lat_LAT_Dmc_Status_Defintion
    = 0U;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status = (boolean_T)
    false;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.open_interface_request_ll = (boolean_T)
    false;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lat_eps_torque_request_zero_filt =
    (boolean_T)false;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.torque_request_zero_ll = (boolean_T)
    false;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt =
    (boolean_T)false;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter = 0.0;
  *rt_e4ho4I = (int16_T)0;
  *rt_erh2sI = (int16_T)0;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay (2)' */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay (1)' */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay1_DSTATE = (boolean_T)false;

  /* InitializeConditions for MinMax: '<S9>/MinMax' incorporates:
   *  InitializeConditions for UnitDelay: '<S9>/Unit Delay'
   */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_a2lj = (uint16_T)0U;
}

/* Output and update for referenced model: 'DMC_Lat_LAT_Dmc_Status_Defintion' */
void DMC_Lat_LAT_Dmc_Status_Defintion(const boolean_T *rt_erh2I, const boolean_T
  *rt_gd42I, const boolean_T *rt_cpaoI, const boolean_T *rt_e4hoI, const
  boolean_T *rt_ngfdI, const int16_T *rt_f3r3I, const boolean_T *rt_kkebI, const
  real32_T *rt_hny3I, const boolean_T *rt_kwugI, int16_T *rt_erh2sI, int16_T
  *rt_gd42sI, boolean_T *rt_cpaomI, int16_T *rt_e4ho4I, uint8_T *rt_ngfdoI,
  uint8_T *rt_f3r3lI)
{
  boolean_T rtb_;
  real32_T rtb_lws3;
  boolean_T rtb_ccex;
  boolean_T rtb_hbia;
  boolean_T rtb_jjv2;
  boolean_T rtb_fuq4;
  boolean_T rtb_f3bw;
  int16_T rtb_izkn;
  real32_T rtb_odxu;

  /* Logic: '<S12>/Logical Operator' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Inport: '<Root>/DMC_LAT_DEGRADATION_TEMP'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   */
  rtb_ = (boolean_T)((int32_T)((DMC_LAT_DEGRADATION_TEMP == ((int16_T)1)) ||
    (DMC_LAT_DEGRADATION_TEMP == ((int16_T)2))));

  /* Switch: '<S6>/Switch (1)' incorporates:
   *  Constant: '<S6>/Constant (1)'
   *  Constant: '<S6>/Constant (2)'
   *  Inport: '<Root>/VEH_Stability_Control_Active'
   */
  if ((int32_T)VEH_Stability_Control_Active_temp) {
    rtb_lws3 = 1.0F;
  } else {
    rtb_lws3 = 0.0F;
  }

  /* End of Switch: '<S6>/Switch (1)' */

  /* Switch: '<S6>/Switch (2)' incorporates:
   *  Constant: '<S6>/Constant (3)'
   *  Inport: '<Root>/VEH_Stability_Control_Active'
   *  Sum: '<S6>/Add'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if ((int32_T)VEH_Stability_Control_Active_temp) {
    rtb_lws3 += DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE;
  } else {
    rtb_lws3 = 0.0F;
  }

  /* End of Switch: '<S6>/Switch (2)' */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Veh_stab_ctr_act_debounce_loops'
   *
   * Block description for '<S6>/Veh_stab_ctr_act_debounce_loops':
   *  u: 1
   */
  rtb_ccex = (boolean_T)((int32_T)(rtb_lws3 >= 6.0F));

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Constant: '<S13>/Lat_min_offset_state'
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/DMC_LAT_DEGRADATION_TEMP'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S16>/Compare'
   *
   * Block description for '<S13>/Lat_min_offset_state':
   *  u: 1
   */
  rtb_hbia = (boolean_T)((int32_T)((((DMC_LAT_DEGRADATION_TEMP == ((int16_T)3)) ||
                            ((int32_T)rtb_ccex)) || ((int32_T)(*rt_kkebI))) ||
                          ((*rt_f3r3I) < Lat_min_offset_state)));

  /* Logic: '<S5>/Logical Operator'
   *
   * Block requirements for '<S5>/Logical Operator':
   *  1. Shut Off Request
   */
  rtb_jjv2 = (boolean_T)((int32_T)(((int32_T)rtb_) || ((int32_T)rtb_hbia)));

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant (1)'
   *  Constant: '<S3>/Lat_request_zero_debounce_loops (1)'
   *
   * Block description for '<S3>/Lat_request_zero_debounce_loops (1)':
   *  u: 1
   */
  if ((int32_T)(*rt_erh2I)) {
    rtb_odxu = 7.0F;
  } else {
    rtb_odxu = -1.0F;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Add' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk += rtb_odxu;

  /* RelationalOperator: '<S3>/Relational Operator' incorporates:
   *  Constant: '<S3>/Constant (3)'
   */
  rtb_fuq4 = (boolean_T)((int32_T)
    (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk >= 0.0F));

  /* Chart: '<Root>/LAT_Dmc_Flow_Control' */
  /* Gateway: LAT_Dmc_Flow_Control */
  /* During: LAT_Dmc_Flow_Control */
  if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_c1_DMC_Lat_LAT_Dmc_Status_Defintion
      == ((uint8_T)0U)) {
    /* Entry: LAT_Dmc_Flow_Control */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_c1_DMC_Lat_LAT_Dmc_Status_Defintion
      = 1U;

    /* Entry Internal: LAT_Dmc_Flow_Control */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Eps_Torque_Request_Zero_Filt
      = 1U;

    /* Entry Internal 'LAT_Eps_Torque_Request_Zero_Filt': '<S1>:45' */
    /* Transition: '<S1>:74' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Torque_Request_Zero_Filt =
      DMC_Lat_LAT_Dmc_Status_Defintion_IN_Was_Zero;

    /* Entry 'Was_Zero': '<S1>:41' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lat_eps_torque_request_zero_filt =
      (boolean_T)true;
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LKC_Activation_Status = 1U;

    /* Entry Internal 'LKC_Activation_Status': '<S1>:30' */
    /* Transition: '<S1>:32' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LKC_Activation_Status =
      DMC_Lat_LAT_Dmc_Status_Defintion_IN_Use_LAT_Enable_Lateral_Control;

    /* Entry 'Use_LAT_Enable_Lateral_Control': '<S1>:34' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status = *rt_e4hoI;
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Eps_Open_Interface_Request
      = 1U;

    /* Entry 'LAT_Eps_Open_Interface_Request': '<S1>:7' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt =
      (boolean_T)false;

    /* Entry Internal 'LAT_Eps_Open_Interface_Request': '<S1>:7' */
    if ((((int32_T)rtb_jjv2) == ((int32_T)0)) && ((int32_T)
         DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status)) {
      /* Transition: '<S1>:68' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Open_Interface_Request =
        DMC_Lat_LAT_Dmc_Status_Defintion_IN_Active_Request;

      /* Entry 'Active_Request': '<S1>:9' */
      *rt_erh2sI = (int16_T)1;

      /* Entry Internal 'Active_Request': '<S1>:9' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_Half_Torque_Overlay_Active_Filt
        = 1U;

      /* Entry 'Half_Torque_Overlay_Active_Filt': '<S1>:57' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter = 0.0;

      /* Entry Internal 'Half_Torque_Overlay_Active_Filt': '<S1>:57' */
      /* Transition: '<S1>:72' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt =
        DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Active;

      /* Entry 'Filter_Active': '<S1>:54' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt =
        (boolean_T)true;
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter++;
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Enable_Lateral_Control
        = 1U;

      /* Entry Internal 'LAT_Enable_Lateral_Control': '<S1>:69' */
      /* Transition: '<S1>:73' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control =
        DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_active;

      /* Entry 'LAT_Enable_Lateral_Control_active': '<S1>:11' */
      *rt_e4ho4I = (int16_T)1;
    } else {
      /* Transition: '<S1>:12' */
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Open_Interface_Request =
        DMC_Lat_LAT_Dmc_Status_Defintion_IN_No_Request;

      /* Entry 'No_Request': '<S1>:8' */
      *rt_e4ho4I = (int16_T)0;
      *rt_erh2sI = (int16_T)0;
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt =
        *rt_ngfdI;
    }

    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_Last_loop_values = 1U;

    /* Entry 'Last_loop_values': '<S1>:28' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.open_interface_request_ll =
      (boolean_T)((int32_T)((*rt_erh2sI) != ((int16_T)0)));
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.torque_request_zero_ll = rtb_fuq4;
  } else {
    /* During 'LAT_Eps_Torque_Request_Zero_Filt': '<S1>:45' */
    if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Torque_Request_Zero_Filt
        == DMC_Lat_LAT_Dmc_Status_Defintion_IN_Was_Not_Zero) {
      /* During 'Was_Not_Zero': '<S1>:43' */
      if ((((int32_T)
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.torque_request_zero_ll) ==
           ((int32_T)1)) && (((int32_T)rtb_fuq4) == ((int32_T)1))) {
        /* Transition: '<S1>:39' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Torque_Request_Zero_Filt
          = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Was_Zero;

        /* Entry 'Was_Zero': '<S1>:41' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lat_eps_torque_request_zero_filt =
          (boolean_T)true;
      }
    } else {
      /* During 'Was_Zero': '<S1>:41' */
      if (((int32_T)rtb_fuq4) == ((int32_T)0)) {
        /* Transition: '<S1>:38' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Torque_Request_Zero_Filt
          = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Was_Not_Zero;

        /* Entry 'Was_Not_Zero': '<S1>:43' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lat_eps_torque_request_zero_filt =
          (boolean_T)false;
      }
    }

    /* During 'LKC_Activation_Status': '<S1>:30' */
    if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LKC_Activation_Status ==
        DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Ramping_down_Activity) {
      /* During 'LAT_Ramping_down_Activity': '<S1>:33' */
      if (((int32_T)
           DMC_Lat_LAT_Dmc_Status_Defintion_DWork.open_interface_request_ll) ==
          ((int32_T)0)) {
        /* Transition: '<S1>:71' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LKC_Activation_Status =
          DMC_Lat_LAT_Dmc_Status_Defintion_IN_Use_LAT_Enable_Lateral_Control;

        /* Entry 'Use_LAT_Enable_Lateral_Control': '<S1>:34' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status = *rt_e4hoI;
      }
    } else {
      /* During 'Use_LAT_Enable_Lateral_Control': '<S1>:34' */
      if (((int32_T)rtb_jjv2) && ((int32_T)
           DMC_Lat_LAT_Dmc_Status_Defintion_DWork.open_interface_request_ll)) {
        /* Transition: '<S1>:29' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LKC_Activation_Status =
          DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Ramping_down_Activity;

        /* Entry 'LAT_Ramping_down_Activity': '<S1>:33' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status =
          (boolean_T)false;
      } else {
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status = *rt_e4hoI;
      }
    }

    /* During 'LAT_Eps_Open_Interface_Request': '<S1>:7' */
    if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Open_Interface_Request
        == DMC_Lat_LAT_Dmc_Status_Defintion_IN_Active_Request) {
      /* During 'Active_Request': '<S1>:9' */
      if (((int32_T)
           DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lat_eps_torque_request_zero_filt)
          && (((int32_T)rtb_jjv2) || (((int32_T)
             DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status) ==
            ((int32_T)0)))) {
        /* Transition: '<S1>:25' */
        /* Exit Internal 'Active_Request': '<S1>:9' */
        /* Exit Internal 'LAT_Enable_Lateral_Control': '<S1>:69' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control =
          DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Enable_Lateral_Control
          = 0U;

        /* Exit Internal 'Half_Torque_Overlay_Active_Filt': '<S1>:57' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt
          = DMC_Lat_LAT_Dmc_Status_Defintion_IN_NO_ACTIVE_CHILD;
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_Half_Torque_Overlay_Active_Filt
          = 0U;
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Open_Interface_Request
          = DMC_Lat_LAT_Dmc_Status_Defintion_IN_No_Request;

        /* Entry 'No_Request': '<S1>:8' */
        *rt_e4ho4I = (int16_T)0;
        *rt_erh2sI = (int16_T)0;
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt =
          *rt_ngfdI;
      } else {
        /* During 'Half_Torque_Overlay_Active_Filt': '<S1>:57' */
        if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt
            == DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Active) {
          /* During 'Filter_Active': '<S1>:54' */
          if (((int32_T)rtb_jjv2) ||
              (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter >=
               (((real_T)Lat_dmc_status_override_cycles) - 1.0))) {
            /* Transition: '<S1>:59' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter++;
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt
              = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Inactive;

            /* Entry 'Filter_Inactive': '<S1>:55' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt
              = *rt_ngfdI;
          } else {
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter++;
          }
        } else {
          /* During 'Filter_Inactive': '<S1>:55' */
          if ((((int32_T)rtb_jjv2) == ((int32_T)0)) &&
              (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter < ((real_T)
                Lat_dmc_status_override_cycles))) {
            /* Transition: '<S1>:63' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt
              = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Active;

            /* Entry 'Filter_Active': '<S1>:54' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt
              = (boolean_T)true;
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter++;
          } else if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter <=
                     25.0) {
            /* Transition: '<S1>:66' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter++;
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt
              = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Inactive;

            /* Entry 'Filter_Inactive': '<S1>:55' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt
              = *rt_ngfdI;
          } else {
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt
              = *rt_ngfdI;
          }
        }

        /* During 'LAT_Enable_Lateral_Control': '<S1>:69' */
        if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control
            ==
            DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_active)
        {
          /* During 'LAT_Enable_Lateral_Control_active': '<S1>:11' */
          if (!((((int32_T)
                  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt)
                 && ((int32_T)
                     DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status))
                && (((int32_T)rtb_jjv2) == ((int32_T)0)))) {
            /* Transition: '<S1>:14' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control
              =
              DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_inactive;

            /* Entry 'LAT_Enable_Lateral_Control_inactive': '<S1>:10' */
            *rt_e4ho4I = (int16_T)0;
          }
        } else {
          /* During 'LAT_Enable_Lateral_Control_inactive': '<S1>:10' */
          if ((((int32_T)
                DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt)
               && ((int32_T)
                   DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status))
              && (((int32_T)rtb_jjv2) == ((int32_T)0))) {
            /* Transition: '<S1>:15' */
            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control
              =
              DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_active;

            /* Entry 'LAT_Enable_Lateral_Control_active': '<S1>:11' */
            *rt_e4ho4I = (int16_T)1;
          }
        }
      }
    } else {
      /* During 'No_Request': '<S1>:8' */
      if ((((int32_T)rtb_jjv2) == ((int32_T)0)) && ((int32_T)
           DMC_Lat_LAT_Dmc_Status_Defintion_DWork.lkc_activation_status)) {
        /* Transition: '<S1>:19' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Eps_Open_Interface_Request
          = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Active_Request;

        /* Entry 'Active_Request': '<S1>:9' */
        *rt_erh2sI = (int16_T)1;

        /* Entry Internal 'Active_Request': '<S1>:9' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_Half_Torque_Overlay_Active_Filt
          = 1U;

        /* Entry 'Half_Torque_Overlay_Active_Filt': '<S1>:57' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter = 0.0;

        /* Entry Internal 'Half_Torque_Overlay_Active_Filt': '<S1>:57' */
        /* Transition: '<S1>:72' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_Half_Torque_Overlay_Active_Filt
          = DMC_Lat_LAT_Dmc_Status_Defintion_IN_Filter_Active;

        /* Entry 'Filter_Active': '<S1>:54' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.half_torque_overlay_active_filt =
          (boolean_T)true;
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter++;
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_active_LAT_Enable_Lateral_Control
          = 1U;

        /* Entry Internal 'LAT_Enable_Lateral_Control': '<S1>:69' */
        /* Transition: '<S1>:73' */
        DMC_Lat_LAT_Dmc_Status_Defintion_DWork.is_LAT_Enable_Lateral_Control =
          DMC_Lat_LAT_Dmc_Status_Defintion_IN_LAT_Enable_Lateral_Control_active;

        /* Entry 'LAT_Enable_Lateral_Control_active': '<S1>:11' */
        *rt_e4ho4I = (int16_T)1;
      }
    }

    /* During 'Last_loop_values': '<S1>:28' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.open_interface_request_ll =
      (boolean_T)((int32_T)((*rt_erh2sI) != ((int16_T)0)));
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.torque_request_zero_ll = rtb_fuq4;
  }

  /* End of Chart: '<Root>/LAT_Dmc_Flow_Control' */

  /* DataTypeConversion: '<Root>/Data Type Conversion (1)' */
  *rt_f3r3lI = (uint8_T)(*rt_erh2sI);

  /* DataTypeConversion: '<Root>/Data Type Conversion (2)' */
  rtb_f3bw = (boolean_T)((int32_T)((*rt_erh2sI) != ((int16_T)0)));

  /* Switch: '<S2>/Switch (1)' incorporates:
   *  Constant: '<S2>/Status On'
   *  Constant: '<S2>/Support'
   *
   * Block requirements for '<S2>/Switch (1)':
   *  1. DMC Support Status
   *  2. DMC On Status
   */
  if ((int32_T)(*rt_cpaoI)) {
    rtb_izkn = (int16_T)2;
  } else {
    rtb_izkn = (int16_T)1;
  }

  /* End of Switch: '<S2>/Switch (1)' */

  /* Switch: '<S2>/Switch (2)' incorporates:
   *  Constant: '<S2>/Counter'
   *
   * Block requirements for '<S2>/Switch (2)':
   *  1. DMC Counter Status
   */
  if ((int32_T)(*rt_gd42I)) {
    rtb_izkn = (int16_T)3;
  }

  /* End of Switch: '<S2>/Switch (2)' */

  /* Switch: '<S2>/Switch (3)' incorporates:
   *  Constant: '<S2>/Status Off (1)'
   *  Constant: '<S7>/Constant'
   *  Logic: '<S2>/And Logical Operator (1)'
   *  Logic: '<S2>/And Logical Operator (2)'
   *  Logic: '<S2>/Nand Logical Operator (1)'
   *  Logic: '<S2>/Not Logical Operator (1)'
   *  Logic: '<S2>/Or Logical Operator'
   *  RelationalOperator: '<S7>/Compare'
   *
   * Block requirements for '<S2>/Switch (3)':
   *  1. DMC Off Status
   */
  if ((((int32_T)(*rt_ngfdI)) && ((int32_T)(*rt_e4hoI))) && ((!(((int32_T)
          rtb_fuq4) && ((*rt_hny3I) < 0.98F))) || (!(*rt_kwugI)))) {
  } else {
    rtb_izkn = (int16_T)0;
  }

  /* End of Switch: '<S2>/Switch (3)' */

  /* RelationalOperator: '<S8>/Relational Operator (1)' incorporates:
   *  Constant: '<S8>/Status Off (2)'
   */
  rtb_fuq4 = (boolean_T)((int32_T)(((int16_T)0) == rtb_izkn));

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant (1)'
   *  Constant: '<S8>/Lat_request_zero_debounce_loops'
   *  Logic: '<S8>/And Logical Operator'
   *  Logic: '<S8>/Not Logical Operator'
   *  UnitDelay: '<S8>/Unit Delay (1)'
   *
   * Block description for '<S8>/Lat_request_zero_debounce_loops':
   *  u: 1
   */
  if ((!DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay1_DSTATE) && ((int32_T)
       rtb_fuq4)) {
    rtb_odxu = 7.0F;
  } else {
    rtb_odxu = -1.0F;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Sum: '<S8>/Add' incorporates:
   *  UnitDelay: '<S8>/Unit Delay (2)'
   */
  rtb_odxu += DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay2_DSTATE;

  /* RelationalOperator: '<S8>/Relational Operator (2)' incorporates:
   *  Constant: '<S8>/Constant (3)'
   */
  rtb_jjv2 = (boolean_T)((int32_T)(rtb_odxu < 0.0F));

  /* MinMax: '<S8>/Min' */
  if (7.0F <= rtb_odxu) {
    rtb_odxu = 7.0F;
  }

  /* End of MinMax: '<S8>/Min' */

  /* MinMax: '<S8>/Max' */
  if (rtb_odxu >= 0.0F) {
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay2_DSTATE = rtb_odxu;
  } else {
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay2_DSTATE = 0.0F;
  }

  /* End of MinMax: '<S8>/Max' */

  /* Switch: '<S2>/Switch (4)' incorporates:
   *  Constant: '<S2>/Status Wait for EPS handshake'
   *  Logic: '<S2>/Nand Logical Operator (2)'
   *  Logic: '<S2>/Not Logical Operator (2)'
   *
   * Block requirements for '<S2>/Switch (4)':
   *  1. DMC EPS Handshake Waiting Status
   */
  if (!(((int32_T)rtb_f3bw) && (!(*rt_ngfdI)))) {
  } else {
    rtb_izkn = (int16_T)6;
  }

  /* End of Switch: '<S2>/Switch (4)' */

  /* Switch: '<S2>/Switch (5)' incorporates:
   *  Constant: '<S2>/Status Temporary Disabled'
   *  Logic: '<S2>/And Logical Operator (3)'
   *
   * Block requirements for '<S2>/Switch (5)':
   *  1. DMC Temporary Disabled Status
   */
  if (((int32_T)rtb_jjv2) && ((int32_T)rtb_hbia)) {
    rtb_izkn = (int16_T)5;
  }

  /* End of Switch: '<S2>/Switch (5)' */

  /* Switch: '<S2>/Switch (6)' incorporates:
   *  Constant: '<S2>/Status Permanently Disabled'
   *  Logic: '<S2>/And Logical Operator (4)'
   *
   * Block requirements for '<S2>/Switch (6)':
   *  1. DMC Permanently Disabled Status
   */
  if (((int32_T)rtb_jjv2) && ((int32_T)rtb_)) {
    *rt_gd42sI = (int16_T)4;
  } else {
    *rt_gd42sI = rtb_izkn;
  }

  /* End of Switch: '<S2>/Switch (6)' */

  /* MinMax: '<S3>/Min' */
  if (7.0F <= DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk) {
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk = 7.0F;
  }

  /* End of MinMax: '<S3>/Min' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Inport: '<Root>/DMC_LAT_DEGRADATION_TEMP'
   *  Logic: '<S9>/Logical Operator'
   *  RelationalOperator: '<S11>/Compare'
   */
  if (((DMC_LAT_DEGRADATION_TEMP != ((int16_T)0)) || ((int32_T)rtb_ccex)) ||
      ((int32_T)(*rt_kkebI))) {
    /* MinMax: '<S9>/MinMax' incorporates:
     *  Constant: '<S9>/Constant (2)'
     *  Sum: '<S9>/Add'
     *  UnitDelay: '<S9>/Unit Delay'
     */
    if (((int32_T)1000) <= ((int32_T)
                            DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_a2lj))
    {
      DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_a2lj = 1000U;
    }

    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_a2lj++;
  } else {
    /* MinMax: '<S9>/MinMax' incorporates:
     *  Constant: '<S9>/Constant (1)'
     */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_a2lj = (uint16_T)0U;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Constant: '<S10>/Sac_ts'
   *
   * Block description for '<S10>/Sac_ts':
   *  u: s
   */
  rtb_odxu = ((real32_T)Sac_ts) * 3.05175781E-5F;

  /* MinMax: '<S10>/MinMax' */
  if (rtb_odxu >= 0.01F) {
  } else {
    rtb_odxu = 0.01F;
  }

  /* RelationalOperator: '<S10>/Relational Operator' incorporates:
   *  Constant: '<S10>/Lat_force_trq_shut_off_time'
   *  MinMax: '<S10>/MinMax'
   *  Product: '<S10>/Divide'
   *
   * Block description for '<S10>/Lat_force_trq_shut_off_time':
   *  u: s
   */
  *rt_cpaomI = (boolean_T)((int32_T)(((real32_T)
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_a2lj) > ((((real32_T)
    Lat_force_trq_shut_off_time) * 0.0009765625F) / rtb_odxu)));

  /* Constant: '<Root>/Constant' */
  *rt_ngfdoI = 1U;

  /* MinMax: '<S6>/MinMax' */
  if (rtb_lws3 <= 6.0F) {
    /* Update for UnitDelay: '<S6>/Unit Delay' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE = rtb_lws3;
  } else {
    /* Update for UnitDelay: '<S6>/Unit Delay' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE = 6.0F;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* MinMax: '<S3>/Max' */
  if (DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk >= 0.0F) {
  } else {
    /* Update for UnitDelay: '<S3>/Unit Delay' */
    DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk = 0.0F;
  }

  /* End of MinMax: '<S3>/Max' */

  /* Update for UnitDelay: '<S8>/Unit Delay (1)' */
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay1_DSTATE = rtb_fuq4;
}

/* Model initialize function */
void DMC_Lat_LAT_Dmc_Status_Defintion_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Lat_LAT_Dmc_Status_Defintion_DWork, 0,
                    sizeof(rtDW_DMC_Lat_LAT_Dmc_Status_Defintion_T));
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.active_counter = 0.0;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay_DSTATE_hxtk = 0.0F;
  DMC_Lat_LAT_Dmc_Status_Defintion_DWork.UnitDelay2_DSTATE = 0.0F;
}
