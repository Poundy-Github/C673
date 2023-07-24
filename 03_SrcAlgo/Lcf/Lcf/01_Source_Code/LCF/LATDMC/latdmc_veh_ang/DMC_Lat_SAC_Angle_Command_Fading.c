/* $Header: DMC_Lat_SAC_Angle_Command_Fading.c 1.38 2020/08/20 10:43:07CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_SAC_Angle_Command_Fading.c
   C source code generated on           : Mon Aug 17 20:47:31 2020
   Filename of Simulink Model           : DMC_Lat_SAC_Angle_Command_Fading.mdl/.slx
   Revision of Simulink Model           : 1.2508
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
#include "DMC_Lat_SAC_Angle_Command_Fading.h"
#include "DMC_Lat_SAC_Angle_Command_Fading_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: signed_int16_t Sac_one_by_ts, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fad_enable_multi_ramp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Lat_lka_startup_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_cmd_limit_margin_fact, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_bump, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_dys_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_min, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_mode_chg, [, ], 1  1,
   PARA: unsigned_int16_t Sac_anglerate_ctrl_sat_kp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_aes, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_fading, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_straight, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grd_aes_cr_y_sc, [, ], 1  11,
   PARA: unsigned_int16_t Sac_delta_f_cmd_initial_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_min_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_counter_steer_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_gradient_lcf_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_obf_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_feedthr_increment_per_loop, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_gradient_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_inverse_eg_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_max, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_prediction_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_weighting, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_activation_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_coefficient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_gate_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_max_offset, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_min_offset, [, ], 1  1,
   PARA: unsigned_int16_t Sac_low_grad_max_dys, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant_low, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grd_aes_cr_x_sc, [, ], 1  11,
   PARA: unsigned_int16_t Sac_delta_gradient_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd_phy, [, ], 1  1,
   CALL: DMC_Lat_SAC_Angle_Command_Fading_step()
   CALL: DMC_Lat_SAC_Angle_Command_Fading_initialize(0)
   FILE: DMC_Lat_SAC_Angle_Command_Fading.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_SAC_Angle_Command_Fading_T DMC_Lat_SAC_Angle_Command_Fading_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_SAC_Angle_Command_Fading' */
void DMC_Lat_SAC_Angle_Command_Fading_Init(void)
{
  /* InitializeConditions for Delay: '<S42>/Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay2_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S39>/Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S40>/Delay' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S37>/Delay' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby = 0.0F;

  /* InitializeConditions for UnitDelay: '<S48>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo = 0.0F;

  /* InitializeConditions for Atomic SubSystem: '<S4>/Ref_Steer_Angle_Offset_Exp'
   *
   * Block requirements for '<S4>/Ref_Steer_Angle_Offset_Exp':
   *  1. Exponential offset
   */
  /* InitializeConditions for Delay: '<S34>/Delay' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S4>/Ref_Steer_Angle_Offset_Exp' */

  /* InitializeConditions for Delay: '<S36>/Delay' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd = 0.0F;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for MinMax: '<S14>/MinMax' incorporates:
   *  InitializeConditions for UnitDelay: '<S14>/Unit Delay2'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_jn4g = 0.0F;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay3' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_huhv = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_bsyw = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay5' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_m1ek = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay4' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE_hg2d = (boolean_T)
    false;

  /* InitializeConditions for MinMax: '<S12>/MinMax' incorporates:
   *  InitializeConditions for UnitDelay: '<S9>/Unit Delay2'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = 0.0F;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay5' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE_k0cr = 0.0F;

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk = 0.0F;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_npeh = 0.0F;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay3' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE_dklm = 0.0F;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay4' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_e30m = 0.0F;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_cjrr = 0.0F;

  /* InitializeConditions for Atomic SubSystem: '<S42>/S-R_Flip_Flop' */
  /* InitializeConditions for Atomic SubSystem: '<S45>/Atomic Subsystem' */
  /* InitializeConditions for Switch: '<S46>/Switch2' incorporates:
   *  InitializeConditions for UnitDelay: '<S46>/Unit Delay'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE_l3th = (boolean_T)
    false;

  /* End of InitializeConditions for SubSystem: '<S45>/Atomic Subsystem' */
  /* End of InitializeConditions for SubSystem: '<S42>/S-R_Flip_Flop' */
}

/* Output and update for referenced model: 'DMC_Lat_SAC_Angle_Command_Fading' */
void DMC_Lat_SAC_Angle_Command_Fading(const real32_T *rt_erh2I, const boolean_T *
  rt_gd42I, const real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const real32_T
  *rt_ngfdI, const boolean_T *rt_hny3I, const boolean_T *rt_kwugI, const
  real32_T *rt_kafvI, const boolean_T *rt_kaadI, const real32_T *rt_eltpI, const
  real32_T *rt_cjpeI, const real32_T *rt_ezusI, const boolean_T *rt_orb0I, const
  int16_T *rt_pdp2I, const real32_T *rt_dxdkI, const real32_T *rt_dmmuI, const
  uint8_T *rt_gyqsI, const uint16_T *rt_m2jwI, const real32_T *rt_pdncI, const
  boolean_T *rt_id5lI, const boolean_T *rt_prezI, const real32_T *rt_pehlI,
  real32_T *rt_erh2sI, real32_T *rt_gd42sI, real32_T *rt_cpaomI, real32_T
  *rt_e4ho4I, real32_T *rt_ngfdoI, real32_T *rt_f3r3lI, real32_T *rt_kkeboI,
  real32_T *rt_hny3uI)
{
  real32_T rtb_;
  real32_T rtb_d1ql;
  boolean_T rtb_fwgx;
  boolean_T rtb_djrh;
  real32_T rtb_nlrw;
  real32_T rtb_dqe5;
  real32_T rtb_nwur;
  real32_T rtb_dt1r;
  real32_T rtb_md04;
  real32_T rtb_ctya;
  boolean_T rtb_j03o;
  boolean_T rtb_ek4f;
  real32_T rtb_cwrb;
  real32_T rtb_jqin;
  real32_T rtb_fnqf;
  real32_T rtb_nb2y;
  real32_T rtb_b15m;
  real32_T rtb_aioq;
  real32_T rtb_ow2b;
  boolean_T rtb_aaff;
  uint16_T tmp_;

  /* Sum: '<S41>/Add2' */
  rtb_ = (*rt_erh2I) - (*rt_cpaoI);

  /* MinMax: '<S41>/MinMax1' incorporates:
   *  Constant: '<S41>/Sac_lin_fading_max_offset'
   */
  rtb_nwur = ((real32_T)Sac_lin_fading_max_offset) * 0.0009765625F;

  /* Signum: '<S44>/Sign1' */
  if (rtb_ < 0.0F) {
    rtb_jqin = -1.0F;
  } else if (rtb_ > 0.0F) {
    rtb_jqin = 1.0F;
  } else {
    rtb_jqin = rtb_;
  }

  /* Sum: '<S44>/Add' incorporates:
   *  Abs: '<S44>/Abs1'
   *  Constant: '<S44>/Sac_lin_fading_min_offset'
   */
  rtb_nb2y = ((real32_T)fabs((real_T)rtb_)) - (((real32_T)
    Sac_lin_fading_min_offset) * 0.0009765625F);

  /* MinMax: '<S44>/MinMax' */
  if (0.0F >= rtb_nb2y) {
    rtb_nb2y = 0.0F;
  }

  /* Product: '<S44>/Product1' incorporates:
   *  MinMax: '<S44>/MinMax'
   *  Signum: '<S44>/Sign1'
   */
  rtb_d1ql = rtb_jqin * rtb_nb2y;

  /* MinMax: '<S41>/MinMax1' */
  if (rtb_nwur <= rtb_d1ql) {
    rtb_d1ql = rtb_nwur;
  }

  /* Gain: '<S41>/Gain' incorporates:
   *  Constant: '<S41>/Sac_lin_fading_max_offset'
   */
  rtb_nwur = -(((real32_T)Sac_lin_fading_max_offset) * 0.0009765625F);

  /* MinMax: '<S41>/MinMax2' */
  if (rtb_nwur >= rtb_d1ql) {
    rtb_d1ql = rtb_nwur;
  }

  /* End of MinMax: '<S41>/MinMax2' */

  /* MinMax: '<S47>/MinMax' incorporates:
   *  UnitDelay: '<S47>/Unit Delay1'
   */
  if (10.0F <= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE = 10.0F;
  }

  /* End of MinMax: '<S47>/MinMax' */

  /* Logic: '<S43>/Logical Operator1' */
  rtb_fwgx = (boolean_T)((int32_T)(!(*rt_gd42I)));

  /* Switch: '<S39>/Switch3' incorporates:
   *  Constant: '<S39>/Constant2'
   */
  if ((int32_T)(*rt_gd42I)) {
    rtb_ow2b = 0.0F;
  } else {
    rtb_ow2b = rtb_;
  }

  /* End of Switch: '<S39>/Switch3' */

  /* Switch: '<S42>/Switch1' incorporates:
   *  Abs: '<S39>/Abs1'
   *  Constant: '<S35>/Sac_lin_fad_enable_multi_ramp'
   *  Constant: '<S39>/Sac_lin_fading_activation_thrs'
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Sac_lin_fading_gate_time'
   *  Delay: '<S39>/Delay1'
   *  Delay: '<S42>/Delay2'
   *  Logic: '<S43>/Logical Operator'
   *  Logic: '<S43>/Logical Operator4'
   *  RelationalOperator: '<S39>/Relational Operator1'
   *  RelationalOperator: '<S43>/Relational Operator2'
   *  Sum: '<S39>/Add4'
   */
  if ((int32_T)DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay2_DSTATE) {
    rtb_aaff = (boolean_T)false;
  } else {
    rtb_aaff = (boolean_T)((int32_T)
      ((((DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE < (((real32_T)
      Sac_lin_fading_gate_time) * 0.0009765625F)) || (((int32_T)
      Sac_lin_fad_enable_multi_ramp) != ((int32_T)0))) && ((int32_T)rtb_fwgx)) &&
       (((real32_T)fabs((real_T)((real32_T)(rtb_ow2b -
      DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay1_DSTATE)))) > (((real32_T)
      Sac_lin_fading_activation_thrs) * 0.0009765625F))));
  }

  /* End of Switch: '<S42>/Switch1' */

  /* Switch: '<S40>/Switch2' incorporates:
   *  Delay: '<S40>/Delay'
   *  MinMax: '<S40>/MinMax'
   *  Product: '<S40>/Product'
   *  Signum: '<S40>/Sign1'
   *  Sum: '<S40>/Add1'
   */
  if ((int32_T)rtb_aaff) {
  } else {
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE < 0.0F) {
      /* Signum: '<S40>/Sign1' */
      rtb_jqin = -1.0F;
    } else if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE > 0.0F) {
      /* Signum: '<S40>/Sign1' */
      rtb_jqin = 1.0F;
    } else {
      /* Signum: '<S40>/Sign1' incorporates:
       *  Delay: '<S40>/Delay'
       */
      rtb_jqin = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE;
    }

    /* Abs: '<S40>/Abs' incorporates:
     *  Delay: '<S40>/Delay'
     *  Signum: '<S40>/Sign1'
     */
    rtb_nwur = (real32_T)fabs((real_T)
      DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE);

    /* MinMax: '<S40>/MinMax' incorporates:
     *  Constant: '<S40>/Sac_lin_fading_coefficient'
     */
    rtb_nb2y = ((real32_T)Sac_lin_fading_coefficient) * 0.0009765625F;
    if (rtb_nwur <= rtb_nb2y) {
      rtb_nb2y = rtb_nwur;
    }

    rtb_d1ql = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE - (rtb_jqin *
      rtb_nb2y);
  }

  /* End of Switch: '<S40>/Switch2' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  if ((int32_T)(*rt_gd42I)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE = 0.0F;
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE = rtb_d1ql;
  }

  /* End of Switch: '<S40>/Switch1' */

  /* MinMax: '<S48>/MinMax' incorporates:
   *  UnitDelay: '<S48>/Unit Delay1'
   */
  if (10.0F <= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo = 10.0F;
  }

  /* End of MinMax: '<S48>/MinMax' */

  /* Switch: '<S37>/Switch2' incorporates:
   *  Delay: '<S37>/Delay'
   *  MinMax: '<S37>/MinMax'
   *  Product: '<S37>/Product'
   *  Signum: '<S37>/Sign1'
   *  Sum: '<S37>/Add1'
   *  Sum: '<S37>/Add2'
   */
  if ((int32_T)(*rt_gd42I)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby = (*rt_erh2I) -
      (*rt_cpaoI);
  } else {
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby < 0.0F) {
      /* Signum: '<S37>/Sign1' */
      rtb_jqin = -1.0F;
    } else if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby > 0.0F)
    {
      /* Signum: '<S37>/Sign1' */
      rtb_jqin = 1.0F;
    } else {
      /* Signum: '<S37>/Sign1' incorporates:
       *  Delay: '<S37>/Delay'
       */
      rtb_jqin = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby;
    }

    /* Abs: '<S37>/Abs' incorporates:
     *  Delay: '<S37>/Delay'
     *  Signum: '<S37>/Sign1'
     */
    rtb_nwur = (real32_T)fabs((real_T)
      DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby);

    /* MinMax: '<S37>/MinMax1' incorporates:
     *  Constant: '<S37>/Sac_lin_fading_coefficient'
     *  Sum: '<S37>/Add3'
     */
    if (0.2F >= (0.2F +
                 DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo))
    {
      rtb_nb2y = 0.2F;
    } else {
      rtb_nb2y = 0.2F +
        DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo;
    }

    /* End of MinMax: '<S37>/MinMax1' */

    /* MinMax: '<S37>/MinMax' */
    if (rtb_nwur <= rtb_nb2y) {
      rtb_nb2y = rtb_nwur;
    }

    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby -= rtb_jqin *
      rtb_nb2y;
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S4>/Ref_Steer_Angle_Offset_Exp'
   *
   * Block requirements for '<S4>/Ref_Steer_Angle_Offset_Exp':
   *  1. Exponential offset
   */
  /* Switch: '<S34>/Switch2' incorporates:
   *  Delay: '<S34>/Delay'
   *  Gain: '<S34>/Exp_Fading_Coefficient'
   *  Sum: '<S34>/Add2'
   */
  if ((int32_T)(*rt_gd42I)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf = (*rt_erh2I) -
      (*rt_cpaoI);
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf *= 0.9F;
  }

  /* End of Switch: '<S34>/Switch2' */
  /* End of Outputs for SubSystem: '<S4>/Ref_Steer_Angle_Offset_Exp' */

  /* Abs: '<S36>/Abs' incorporates:
   *  Delay: '<S36>/Delay'
   */
  rtb_d1ql = (real32_T)fabs((real_T)
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd);

  /* Signum: '<S36>/Sign1' incorporates:
   *  Delay: '<S36>/Delay'
   */
  if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd < 0.0F) {
    rtb_jqin = -1.0F;
  } else if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd > 0.0F) {
    rtb_jqin = 1.0F;
  } else {
    rtb_jqin = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd;
  }

  /* MinMax: '<S36>/MinMax' */
  if (rtb_d1ql <= 0.2F) {
  } else {
    rtb_d1ql = 0.2F;
  }

  /* Sum: '<S36>/Add1' incorporates:
   *  Delay: '<S36>/Delay'
   *  MinMax: '<S36>/MinMax'
   *  Product: '<S36>/Product'
   *  Signum: '<S36>/Sign1'
   */
  rtb_d1ql = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd -
    (rtb_jqin * rtb_d1ql);

  /* Gain: '<S36>/Exp_Fading_Coefficient' incorporates:
   *  Delay: '<S36>/Delay'
   */
  rtb_nlrw = 0.94F * DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd;

  /* Switch: '<S36>/Switch1' incorporates:
   *  Abs: '<S36>/Abs2'
   *  Abs: '<S36>/Abs3'
   *  RelationalOperator: '<S36>/Relational Operator'
   */
  if (((real32_T)fabs((real_T)rtb_d1ql)) > ((real32_T)fabs((real_T)rtb_nlrw))) {
  } else {
    rtb_d1ql = rtb_nlrw;
  }

  /* End of Switch: '<S36>/Switch1' */

  /* Switch: '<S36>/Switch2' incorporates:
   *  Sum: '<S36>/Add2'
   */
  if ((int32_T)(*rt_gd42I)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd = (*rt_erh2I) -
      (*rt_cpaoI);
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd = rtb_d1ql;
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<Root>/Sac_angle_fading_mode'
   *  Constant: '<S4>/Constant'
   */
  tmp_ = (uint16_T)(Sac_angle_fading_mode + ((uint16_T)1U));

  /* Saturate: '<S4>/Saturation' */
  if (((int32_T)tmp_) > ((int32_T)5)) {
    tmp_ = (uint16_T)5U;
  } else {
    if (((int32_T)tmp_) < ((int32_T)1)) {
      tmp_ = (uint16_T)1U;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *
   * Block requirements for '<S4>/Multiport Switch':
   *  1. Offset Selection
   */
  switch (tmp_) {
   case 1:
    rtb_dqe5 = 0.0F;
    break;

   case 2:
    rtb_dqe5 = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE;
    break;

   case 3:
    /* Saturate: '<S37>/Saturation' */
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby > 20.0F) {
      rtb_dqe5 = 20.0F;
    } else if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby < -20.0F)
    {
      rtb_dqe5 = -20.0F;
    } else {
      rtb_dqe5 = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby;
    }

    /* End of Saturate: '<S37>/Saturation' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S4>/Ref_Steer_Angle_Offset_Exp'
     *
     * Block requirements for '<S4>/Ref_Steer_Angle_Offset_Exp':
     *  1. Exponential offset
     */
    /* Saturate: '<S34>/Saturation' */
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf > 20.0F) {
      rtb_dqe5 = 20.0F;
    } else if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf < -20.0F)
    {
      rtb_dqe5 = -20.0F;
    } else {
      rtb_dqe5 = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf;
    }

    /* End of Saturate: '<S34>/Saturation' */
    /* End of Outputs for SubSystem: '<S4>/Ref_Steer_Angle_Offset_Exp' */
    break;

   default:
    /* Saturate: '<S36>/Saturation' */
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd > 20.0F) {
      rtb_dqe5 = 20.0F;
    } else if (DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd < -20.0F)
    {
      rtb_dqe5 = -20.0F;
    } else {
      rtb_dqe5 = DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd;
    }

    /* End of Saturate: '<S36>/Saturation' */
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* Sum: '<Root>/Add' */
  rtb_nlrw = (*rt_erh2I) - rtb_dqe5;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  SAC_Arb_Angle_Cmd_Raw_dbg = (int16_T)((real32_T)floor(rtb_nlrw / 0.001526F));

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  SAC_Fading_Offset_dbg = (int16_T)((real32_T)floor(rtb_dqe5 * 1024.0F));

  /* Gain: '<S13>/Gain9' */
  rtb_dqe5 = 3.6F * (*rt_e4hoI);

  /* Lookup_n-D: '<S24>/Sac_jerk_gradient_Scheduling' */
  rtb_d1ql = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_dqe5,
    (&(Sac_delta_gradient_x_scheduling[0])), (&(Sac_jerk_gradient_y_scheduling[0])),
    11U);

  /* Lookup_n-D: '<S24>/Sac_jerk_inverse_eg_Scheduling' */
  rtb_dt1r = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_dqe5,
    (&(Sac_delta_gradient_x_scheduling[0])),
    (&(Sac_jerk_inverse_eg_y_scheduling[0])), 11U);

  /* Product: '<S24>/Product1' incorporates:
   *  Constant: '<S24>/Sac_jerk_prediction_time'
   *  Gain: '<S24>/Sac_one_by_ts'
   *  Product: '<S24>/Product'
   *  Sum: '<S24>/Sum5'
   *  Sum: '<S24>/Sum6'
   *  UnitDelay: '<S24>/Unit Delay2'
   */
  rtb_dt1r *= (*rt_ngfdI) + ((((real32_T)Sac_one_by_ts) * ((*rt_ngfdI) -
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE)) * (((real32_T)
    Sac_jerk_prediction_time) * 0.0009765625F));

  /* Abs: '<S24>/Abs' */
  rtb_dt1r = (real32_T)fabs((real_T)rtb_dt1r);

  /* Abs: '<S24>/Abs1' incorporates:
   *  Gain: '<S24>/Sac_jerk_weighting'
   */
  rtb_nwur = (real32_T)fabs((real_T)((real32_T)((((real32_T)Sac_jerk_weighting) *
    0.0009765625F) * (*rt_pdncI))));

  /* MinMax: '<S24>/MinMax' */
  if (rtb_nwur >= rtb_dt1r) {
    rtb_dt1r = rtb_nwur;
  }

  /* Sum: '<S5>/Add1' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_ = rtb_nlrw - DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE;

  /* Signum: '<S14>/Sign1' */
  if (rtb_ < 0.0F) {
    rtb_ctya = -1.0F;
  } else if (rtb_ > 0.0F) {
    rtb_ctya = 1.0F;
  } else {
    rtb_ctya = rtb_;
  }

  /* End of Signum: '<S14>/Sign1' */

  /* Switch: '<S14>/Switch1' incorporates:
   *  Abs: '<S14>/Abs2'
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Lat_lka_filter_init_time'
   *  Constant: '<S14>/Lat_lka_startup_time'
   *  Constant: '<S14>/Sac_angle_rate_limiter_residual'
   *  Logic: '<S14>/Logical Operator'
   *  Logic: '<S14>/Logical Operator1'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  RelationalOperator: '<S14>/Relational Operator1'
   *  RelationalOperator: '<S14>/Relational Operator2'
   *  UnitDelay: '<S14>/Unit Delay1'
   *  UnitDelay: '<S14>/Unit Delay3'
   */
  if ((0.1F > DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE) ||
      (!((rtb_ctya !=
          DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_huhv) ||
         (((real32_T)fabs((real_T)rtb_)) < 0.05F)))) {
    rtb_md04 = 0.0F;
  } else {
    rtb_md04 = ((real32_T)Lat_lka_startup_time) * 0.0009765625F;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Switch: '<S14>/Switch6' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Sum: '<S14>/Add2'
   *  UnitDelay: '<S14>/Unit Delay2'
   */
  if ((int32_T)(*rt_gd42I)) {
    rtb_md04 = 0.0F;
  } else {
    rtb_md04 += DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_jn4g;
  }

  /* End of Switch: '<S14>/Switch6' */

  /* Switch: '<S14>/Switch7' incorporates:
   *  Constant: '<S14>/Constant6'
   *  Constant: '<S14>/Constant7'
   */
  if ((int32_T)(*rt_gd42I)) {
    rtb_nwur = 0.0F;
  } else {
    rtb_nwur = 1.0F;
  }

  /* End of Switch: '<S14>/Switch7' */

  /* Sum: '<S14>/Add' incorporates:
   *  Gain: '<S14>/Gain'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE = rtb_md04 +
    ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_nwur);

  /* Logic: '<S14>/Logical Operator8' incorporates:
   *  Constant: '<S14>/Lat_lka_startup_time'
   *  Logic: '<S14>/Logical Operator2'
   *  RelationalOperator: '<S14>/Relational Operator4'
   */
  rtb_djrh = (boolean_T)((int32_T)
    ((DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE < (((real32_T)
    Lat_lka_startup_time) * 0.0009765625F)) && (!(*rt_gd42I))));

  /* Lookup_n-D: '<S13>/SAC_Delta_F_Gradient_Obf_Sched' */
  rtb_md04 = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_dqe5,
    (&(Sac_delta_gradient_x_scheduling[0])), (&(Sac_delta_gradient_obf_y_sched[0])),
    11U);

  /* Lookup_n-D: '<S13>/SAC_Delta_F_Gradient_Lcf_Sched' */
  rtb_nwur = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_dqe5,
    (&(Sac_delta_gradient_x_scheduling[0])), (&(Sac_delta_gradient_lcf_y_sched[0])),
    11U);

  /* Switch: '<S13>/Switch3' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S22>/Compare'
   */
  if (((int32_T)(*rt_m2jwI)) == ((int32_T)2)) {
  } else {
    rtb_md04 = rtb_nwur;
  }

  /* End of Switch: '<S13>/Switch3' */

  /* Lookup_n-D: '<S13>/SAC_Delta_F_Gradient_Scheduling' */
  rtb_nwur = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_dqe5,
    (&(Sac_delta_gradient_x_scheduling[0])), (&(Sac_delta_gradient_y_scheduling
    [0])), 11U);

  /* Switch: '<S13>/Switch1' incorporates:
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  if ((int32_T)DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_bsyw) {
  } else {
    rtb_md04 = rtb_nwur;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<S13>/Sac_delta_f_cmd_gradient'
   */
  *rt_e4ho4I = (((real32_T)Sac_delta_f_cmd_gradient) * 0.0009765625F) * rtb_md04;

  /* MinMax: '<S13>/MinMax2' incorporates:
   *  Constant: '<S13>/Sac_delta_f_cmd_grad_fading'
   */
  rtb_nwur = ((real32_T)Sac_delta_f_cmd_grad_fading) * 0.0009765625F;
  rtb_md04 = *rt_e4ho4I;
  if (rtb_nwur <= rtb_md04) {
    rtb_md04 = rtb_nwur;
  }

  /* End of MinMax: '<S13>/MinMax2' */

  /* UnitDelay: '<S9>/Unit Delay5' */
  rtb_nwur = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE;

  /* Logic: '<S9>/Logical Operator1' incorporates:
   *  Logic: '<S9>/Logical Operator2'
   *  Logic: '<S9>/Logical Operator6'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  rtb_ek4f = (boolean_T)((int32_T)(((!(*rt_kaadI)) && ((int32_T)
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_m1ek)) || ((int32_T)
                           (*rt_kwugI))));

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Sac_angle_fading_time'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator'
   */
  if (((int16_T)((*rt_pdp2I) & ((int16_T)1))) != ((int16_T)0)) {
    rtb_nb2y = ((real32_T)Sac_angle_fading_time) * 0.0009765625F;
  } else {
    rtb_nb2y = 0.0F;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Sac_angle_fading_time_mode_chg'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator1'
   */
  if (((int16_T)((*rt_pdp2I) & ((int16_T)2))) != ((int16_T)0)) {
    rtb_b15m = ((real32_T)Sac_angle_fading_time_mode_chg) * 0.0009765625F;
  } else {
    rtb_b15m = 0.0F;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* Switch: '<S9>/Switch4' incorporates:
   *  Constant: '<S9>/Constant5'
   *  Constant: '<S9>/Sac_angle_fading_time_bump'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator2'
   */
  if (((int16_T)((*rt_pdp2I) & ((int16_T)4))) != ((int16_T)0)) {
    rtb_aioq = ((real32_T)Sac_angle_fading_time_bump) * 0.0009765625F;
  } else {
    rtb_aioq = 0.0F;
  }

  /* End of Switch: '<S9>/Switch4' */

  /* Switch: '<S9>/Switch5' incorporates:
   *  Constant: '<S9>/Constant6'
   *  Constant: '<S9>/Sac_angle_fading_time_dys_grad'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator3'
   */
  if (((int16_T)((*rt_pdp2I) & ((int16_T)8))) != ((int16_T)0)) {
    rtb_fnqf = ((real32_T)Sac_angle_fading_time_dys_grad) * 0.0009765625F;
  } else {
    rtb_fnqf = 0.0F;
  }

  /* End of Switch: '<S9>/Switch5' */

  /* MinMax: '<S9>/MinMax' incorporates:
   *  Constant: '<S9>/Sac_angle_fading_time_min'
   *  UnitDelay: '<S9>/Unit Delay2'
   */
  if (rtb_nb2y >= rtb_b15m) {
    rtb_b15m = rtb_nb2y;
  }

  if (rtb_b15m >= rtb_aioq) {
    rtb_aioq = rtb_b15m;
  }

  if (rtb_aioq >= rtb_fnqf) {
    rtb_fnqf = rtb_aioq;
  }

  rtb_nb2y = ((real32_T)Sac_angle_fading_time_min) * 0.0009765625F;
  if (rtb_fnqf >= rtb_nb2y) {
    rtb_nb2y = rtb_fnqf;
  }

  if (rtb_nb2y >= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g)
  {
    /* MinMax: '<S12>/MinMax' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = rtb_nb2y;
  }

  /* End of MinMax: '<S9>/MinMax' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Logic: '<S9>/Logical Operator3'
   *  Logic: '<S9>/Logical Operator4'
   *  UnitDelay: '<S9>/Unit Delay4'
   */
  if (!(((int32_T)rtb_ek4f) &&
        (!DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE_hg2d))) {
  } else {
    rtb_nwur = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Sum: '<S9>/Add1' incorporates:
   *  Gain: '<S9>/Gain1'
   */
  rtb_cwrb = rtb_nwur - (((real32_T)Sac_ts) * 3.05175781E-5F);

  /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  rtb_j03o = (boolean_T)((int32_T)(rtb_cwrb > 0.0F));

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Gain: '<S23>/Gain1'
   *  Product: '<S23>/Product1'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = (0.01F *
    (*rt_pehlI)) * (*rt_e4ho4I);

  /* Product: '<S23>/Product7' incorporates:
   *  Gain: '<S23>/Gain'
   */
  rtb_jqin = (*rt_e4ho4I) * (0.01F * (*rt_eltpI));

  /* MinMax: '<S23>/MinMax4' incorporates:
   *  Constant: '<S23>/Sac_delta_f_cmd_min_grad'
   */
  rtb_fnqf = ((real32_T)Sac_delta_f_cmd_min_grad) * 0.0009765625F;
  if (rtb_jqin >= rtb_fnqf) {
    rtb_fnqf = rtb_jqin;
  }

  /* End of MinMax: '<S23>/MinMax4' */

  /* MinMax: '<S23>/MinMax5' */
  rtb_nwur = *rt_e4ho4I;
  if (rtb_nwur <= rtb_fnqf) {
    rtb_fnqf = rtb_nwur;
  }

  /* Switch: '<S23>/Switch7' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S27>/Constant'
   *  Logic: '<S23>/Logical Operator1'
   *  Logic: '<S23>/Logical Operator2'
   *  Logic: '<S23>/Logical Operator3'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S27>/Compare'
   */
  if (((rtb_ > 0.0F) && ((int32_T)(*rt_prezI))) || ((rtb_ < 0.0F) && ((int32_T)(*
         rt_id5lI)))) {
    /* MinMax: '<S23>/MinMax1' incorporates:
     *  MinMax: '<S23>/MinMax5'
     */
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g <=
        rtb_fnqf) {
    } else {
      /* MinMax: '<S12>/MinMax' */
      DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = rtb_fnqf;
    }

    /* End of MinMax: '<S23>/MinMax1' */
  } else {
    /* MinMax: '<S12>/MinMax' incorporates:
     *  MinMax: '<S23>/MinMax5'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = rtb_fnqf;
  }

  /* End of Switch: '<S23>/Switch7' */

  /* Switch: '<S23>/Switch8' incorporates:
   *  Logic: '<S23>/Logical Operator'
   */
  if (((int32_T)(*rt_id5lI)) || ((int32_T)(*rt_prezI))) {
  } else {
    /* MinMax: '<S12>/MinMax' incorporates:
     *  MinMax: '<S23>/MinMax5'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = rtb_fnqf;
  }

  /* End of Switch: '<S23>/Switch8' */

  /* UnitDelay: '<S15>/Unit Delay5' */
  rtb_fnqf = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE_k0cr;

  /* Switch: '<S15>/Switch3' incorporates:
   *  Constant: '<S15>/Constant5'
   *  Constant: '<S15>/Sac_low_grad_inhibt_time_driver'
   *  RelationalOperator: '<S15>/Relational Operator'
   */
  if ((*rt_kafvI) > 0.98F) {
  } else {
    rtb_fnqf = 2.5F;
  }

  /* End of Switch: '<S15>/Switch3' */

  /* Sum: '<S15>/Add1' incorporates:
   *  Gain: '<S15>/Gain1'
   */
  rtb_fnqf -= ((real32_T)Sac_ts) * 3.05175781E-5F;

  /* Switch: '<S15>/Switch4' incorporates:
   *  Constant: '<S15>/Constant10'
   *  Constant: '<S15>/Constant6'
   *  Constant: '<S15>/Constant9'
   *  RelationalOperator: '<S15>/Relational Operator1'
   */
  if (rtb_fnqf > 0.0F) {
    rtb_aioq = 0.0F;
  } else {
    rtb_aioq = 1.0F;
  }

  /* End of Switch: '<S15>/Switch4' */

  /* Sum: '<S15>/Add2' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  rtb_b15m = 100.0F - (*rt_dxdkI);

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  rtb_nb2y = (real32_T)(*rt_gyqsI);

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Constant: '<S15>/Constant3'
   *  S-Function (sfix_bitop): '<S15>/Bitwise Operator1'
   */
  if ((((int32_T)Dmc_configuration_mode_2) & ((int32_T)256)) != ((int32_T)0)) {
  } else {
    rtb_nb2y = 0.0F;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* MinMax: '<S15>/MinMax1' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Sum: '<S15>/Add2'
   */
  if ((100.0F - (*rt_dxdkI)) >= rtb_nb2y) {
  } else {
    rtb_b15m = rtb_nb2y;
  }

  /* End of MinMax: '<S15>/MinMax1' */

  /* Product: '<S15>/Product' incorporates:
   *  Gain: '<S15>/Gain'
   */
  rtb_nwur = rtb_aioq * (0.01F * rtb_b15m);

  /* Switch: '<S15>/Switch5' incorporates:
   *  Abs: '<S15>/Abs'
   *  Constant: '<S15>/Constant11'
   *  Constant: '<S15>/Constant12'
   *  Constant: '<S15>/Constant8'
   *  Constant: '<S15>/Sac_low_grad_max_dys'
   *  Logic: '<S15>/Logical Operator2'
   *  RelationalOperator: '<S15>/Relational Operator2'
   *  RelationalOperator: '<S15>/Relational Operator3'
   */
  if ((rtb_b15m > 98.0F) && (((real32_T)fabs((real_T)(*rt_dmmuI))) > (((real32_T)
         Sac_low_grad_max_dys) * 0.0009765625F))) {
    rtb_aioq = 2.0F;
  } else {
    rtb_aioq = 0.0F;
  }

  /* End of Switch: '<S15>/Switch5' */

  /* Sum: '<S33>/Add2' incorporates:
   *  UnitDelay: '<S33>/Unit Delay1'
   */
  rtb_aioq -= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk;

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S33>/Constant5'
   *  RelationalOperator: '<S33>/Relational Operator'
   */
  if (rtb_aioq >= 0.0F) {
  } else {
    rtb_aioq = -0.01F;
  }

  /* End of Switch: '<S33>/Switch2' */

  /* Sum: '<S33>/Add3' incorporates:
   *  UnitDelay: '<S33>/Unit Delay1'
   */
  rtb_aioq += DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk;

  /* MinMax: '<S33>/MinMax' */
  if (rtb_aioq >= 0.0F) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk = rtb_aioq;
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk = 0.0F;
  }

  /* End of MinMax: '<S33>/MinMax' */

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Constant: '<S15>/Constant13'
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S32>/Constant'
   *  Logic: '<S15>/Logical Operator1'
   *  MinMax: '<S33>/MinMax1'
   *  Product: '<S15>/Product1'
   *  RelationalOperator: '<S32>/Compare'
   *  S-Function (sfix_bitop): '<S15>/Bitwise Operator2'
   *  Sum: '<S15>/Add4'
   */
  if ((((int32_T)(*rt_m2jwI)) != ((int32_T)2)) && ((((int32_T)
         Dmc_configuration_mode_2) & ((int32_T)128)) != ((int32_T)0))) {
    /* MinMax: '<S33>/MinMax1' */
    if (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk <= 1.0F) {
      rtb_jqin = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk;
    } else {
      rtb_jqin = 1.0F;
    }

    rtb_aioq = rtb_nwur * (1.0F - rtb_jqin);
  } else {
    rtb_aioq = 0.0F;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* MinMax: '<S25>/MinMax3' incorporates:
   *  Constant: '<S25>/Sac_delta_f_cmd_grad_straight'
   */
  rtb_nb2y = ((real32_T)Sac_delta_f_cmd_grad_straight) * 0.0009765625F;
  if (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g <= rtb_nb2y)
  {
    rtb_nb2y = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Constant: '<S25>/Constant1'
   *  MinMax: '<S25>/MinMax3'
   *  Product: '<S25>/Product3'
   *  Product: '<S25>/Product4'
   *  Sum: '<S25>/Add1'
   *  Sum: '<S25>/Add2'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = (rtb_nb2y *
    rtb_aioq) + (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g *
                 (1.0F - rtb_aioq));

  /* Switch: '<S13>/Switch4' */
  if ((int32_T)rtb_j03o) {
  } else {
    rtb_md04 = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* End of Switch: '<S13>/Switch4' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S13>/Sac_delta_f_cmd_initial_grad'
   */
  if ((int32_T)rtb_djrh) {
    rtb_md04 = ((real32_T)Sac_delta_f_cmd_initial_grad) * 0.0009765625F;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* MinMax: '<S13>/MinMax1' */
  if (rtb_md04 <= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g)
  {
  } else {
    rtb_md04 = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* End of MinMax: '<S13>/MinMax1' */

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/Sac_jerk_max'
   *  MinMax: '<S24>/MinMax'
   *  RelationalOperator: '<S24>/Relational Operator1'
   */
  if (rtb_dt1r >= (((real32_T)Sac_jerk_max) * 0.0009765625F)) {
  } else {
    rtb_d1ql = rtb_md04;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* MinMax: '<S13>/MinMax7' */
  if (rtb_d1ql <= rtb_md04) {
  } else {
    rtb_d1ql = rtb_md04;
  }

  /* End of MinMax: '<S13>/MinMax7' */

  /* Lookup_n-D: '<S13>/Sac_delta_f_cmd_grd_aes_cor_sc' */
  rtb_dqe5 = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_dqe5,
    (&(Sac_delta_f_cmd_grd_aes_cr_x_sc[0])), (&(Sac_delta_f_cmd_grd_aes_cr_y_sc
    [0])), 10U);

  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<S13>/Sac_delta_f_cmd_grad_aes'
   */
  *rt_f3r3lI = (((real32_T)Sac_delta_f_cmd_grad_aes) * 0.0009765625F) * rtb_dqe5;

  /* Switch: '<S13>/Switch' incorporates:
   *  Logic: '<S13>/Logical Operator'
   */
  if (((int32_T)(*rt_orb0I)) || ((int32_T)(*rt_hny3I))) {
    /* MinMax: '<S12>/MinMax' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = *rt_f3r3lI;
  } else {
    /* MinMax: '<S12>/MinMax' incorporates:
     *  Constant: '<S13>/Constant'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = 0.0F;
  }

  /* End of Switch: '<S13>/Switch' */

  /* MinMax: '<S13>/MinMax6' */
  if (rtb_d1ql >= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g)
  {
  } else {
    rtb_d1ql = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* End of MinMax: '<S13>/MinMax6' */

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Constant: '<S12>/Constant10'
   *  Constant: '<S12>/Sac_delta_f_counter_steer_grad'
   *  DataTypeConversion: '<S12>/Data Type Conversion1'
   *  Product: '<S12>/Product4'
   *  Product: '<S12>/Product7'
   *  Sum: '<S12>/Add6'
   *  Sum: '<S12>/Add7'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = ((real32_T)
    Sac_delta_f_counter_steer_grad) * 0.0009765625F;
  if (rtb_d1ql >= DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g)
  {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = rtb_d1ql;
  }

  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = (rtb_d1ql *
    (*rt_kafvI)) +
    (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g * (1.0F -
      (*rt_kafvI)));

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  *rt_cpaomI = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  SAC_Delta_F_Cmd_Grad_Param_dbg = (int16_T)((real32_T)floor
    (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g * 1024.0F));

  /* UnitDelay: '<S20>/Unit Delay2' */
  rtb_dqe5 = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_npeh;

  /* UnitDelay: '<S20>/Unit Delay3' */
  rtb_d1ql = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE_dklm;

  /* Signum: '<S5>/Sign1' */
  if (rtb_ < 0.0F) {
    rtb_jqin = -1.0F;
  } else if (rtb_ > 0.0F) {
    rtb_jqin = 1.0F;
  } else {
    rtb_jqin = rtb_;
  }

  /* End of Signum: '<S5>/Sign1' */

  /* Gain: '<S5>/Sac_ts' */
  rtb_aioq = (((real32_T)Sac_ts) * 3.05175781E-5F) *
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;

  /* Abs: '<S5>/Abs1' incorporates:
   *  Product: '<S5>/Product'
   */
  rtb_b15m = (real32_T)fabs((real_T)((real32_T)(rtb_aioq * rtb_jqin)));

  /* Abs: '<S5>/Abs2' */
  rtb_ = (real32_T)fabs((real_T)rtb_);

  /* MinMax: '<S5>/MinMax1' */
  if (rtb_b15m <= rtb_) {
  } else {
    rtb_b15m = rtb_;
  }

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Gain: '<S6>/Sac_anglerate_ctrl_sat_kp'
   *  MinMax: '<S5>/MinMax1'
   *  Product: '<S5>/Product1'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add3'
   *  Sum: '<S6>/Add6'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = ((rtb_jqin *
    rtb_b15m) + (0.0F - ((((real32_T)Sac_anglerate_ctrl_sat_kp) * 0.0009765625F)
    * (*rt_cjpeI)))) + DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE;

  /* Switch: '<S5>/Switch3' incorporates:
   *  Gain: '<S20>/Gain'
   *  Sum: '<S20>/Add5'
   *  UnitDelay: '<S20>/Unit Delay2'
   *  UnitDelay: '<S20>/Unit Delay3'
   *  UnitDelay: '<S20>/Unit Delay4'
   */
  if ((int32_T)(*rt_gd42I)) {
    rtb_b15m = 0.25F * ((((*rt_cpaoI) +
                          DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_npeh)
                         + DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE_dklm)
                        + DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE);
  } else {
    rtb_b15m = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* End of Switch: '<S5>/Switch3' */

  /* Switch: '<S17>/Switch2' incorporates:
   *  Constant: '<S17>/Sat_max_delta_f_cmd_phy'
   *  DataTypeConversion: '<S17>/Data Type Conversion5'
   *  Gain: '<S17>/Sac_angle_cmd_limit_margin_fact'
   */
  if ((int32_T)(*rt_orb0I)) {
    *rt_hny3uI = ((real32_T)Sat_max_delta_f_cmd_phy) * 0.001953125F;
  } else {
    *rt_hny3uI = (((real32_T)Sac_angle_cmd_limit_margin_fact) * 0.0009765625F) *
      (*rt_ezusI);
  }

  /* End of Switch: '<S17>/Switch2' */

  /* MinMax: '<S18>/Min' */
  rtb_nwur = *rt_hny3uI;
  if (rtb_b15m <= rtb_nwur) {
    rtb_nwur = rtb_b15m;
  }

  /* Gain: '<S18>/Gain1' */
  rtb_nb2y = -(*rt_hny3uI);

  /* MinMax: '<S18>/Max' incorporates:
   *  MinMax: '<S18>/Min'
   */
  if (rtb_nwur >= rtb_nb2y) {
  } else {
    rtb_nwur = rtb_nb2y;
  }

  /* End of MinMax: '<S18>/Max' */

  /* Sum: '<S5>/Add5' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_dt1r = rtb_nwur - DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE;

  /* Logic: '<S16>/Logical Operator4' incorporates:
   *  Logic: '<S16>/Logical Operator2'
   *  Logic: '<S16>/Logical Operator3'
   *  Logic: '<S16>/Logical Operator5'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  UnitDelay: '<S16>/Unit Delay2'
   */
  rtb_j03o = (boolean_T)((int32_T)(((*rt_eltpI) <
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_e30m) || (((int32_T)
    rtb_djrh) || (((int32_T)(*rt_gd42I)) || ((int32_T)rtb_j03o)))));

  /* Constant: '<S16>/Sac_feedthr_increment_per_loop' */
  rtb_nb2y = ((real32_T)Sac_feedthr_increment_per_loop) * 0.0009765625F;

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  if ((int32_T)rtb_j03o) {
    rtb_nb2y = 0.0F;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Add3'
   *  UnitDelay: '<S16>/Unit Delay1'
   */
  if ((int32_T)rtb_j03o) {
    rtb_nb2y = 0.0F;
  } else {
    rtb_nb2y += DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_cjrr;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* MinMax: '<S16>/MinMax2' */
  if (1.0F <= rtb_nb2y) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_cjrr = 1.0F;
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_cjrr = rtb_nb2y;
  }

  /* End of MinMax: '<S16>/MinMax2' */

  /* Switch: '<S16>/Switch3' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Logic: '<S16>/Logical Operator'
   *  Logic: '<S16>/Logical Operator1'
   *  Logic: '<S16>/Logical Operator6'
   */
  if ((!(*rt_gd42I)) && (((int32_T)(*rt_orb0I)) || ((int32_T)(*rt_hny3I)))) {
    *rt_ngfdoI = 1.0F;
  } else {
    *rt_ngfdoI = DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_cjrr;
  }

  /* End of Switch: '<S16>/Switch3' */

  /* Constant: '<S10>/Sac_parity_time_constant_ldp' */
  rtb_md04 = ((real32_T)Sac_parity_time_constant_ldp) * 0.00390625F;

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Sac_parity_time_constant'
   *  Logic: '<S10>/Logical Operator'
   */
  if (((int32_T)(*rt_hny3I)) || ((int32_T)(*rt_orb0I))) {
  } else {
    rtb_md04 = ((real32_T)Sac_parity_time_constant) * 0.00390625F;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Sac_parity_time_constant_low'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  if ((*rt_eltpI) < 33.0F) {
    *rt_gd42sI = ((real32_T)Sac_parity_time_constant_low) * 0.00390625F;
  } else {
    *rt_gd42sI = rtb_md04;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Product: '<S5>/Product3' */
  rtb_nb2y = *rt_gd42sI;

  /* Sum: '<S5>/Add4' */
  rtb_ -= rtb_aioq;

  /* MinMax: '<S5>/MinMax4' */
  if (0.0F >= rtb_) {
    rtb_ = 0.0F;
  }

  /* End of MinMax: '<S5>/MinMax4' */

  /* MinMax: '<S5>/MinMax3' */
  if (rtb_nb2y <= rtb_) {
    rtb_ = rtb_nb2y;
  }

  /* Product: '<S5>/Product5' incorporates:
   *  MinMax: '<S5>/MinMax3'
   *  Product: '<S5>/Product2'
   */
  rtb_jqin = (*rt_ngfdoI) * (rtb_ * rtb_jqin);

  /* Sum: '<S5>/Add2' */
  rtb_aioq = rtb_jqin + rtb_nwur;

  /* Sum: '<S5>/Add6' */
  *rt_kkeboI = rtb_nlrw - rtb_aioq;

  /* DataTypeConversion: '<S5>/Data Type Conversion2' */
  LAT_Debug1_dbg = (int16_T)((real32_T)floor(rtb_jqin * 1024.0F));

  /* DataTypeConversion: '<S5>/Data Type Conversion3' */
  LAT_Debug2_dbg = (int16_T)((real32_T)floor(rtb_nwur * 1024.0F));

  /* DataTypeConversion: '<S5>/Data Type Conversion4' */
  LAT_Debug4_dbg = (int16_T)((real32_T)floor
    (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g * 1024.0F));

  /* Logic: '<S42>/Logical Operator2' incorporates:
   *  Constant: '<S35>/Sac_lin_fad_enable_multi_ramp'
   *  Delay: '<S42>/Delay2'
   *  Logic: '<S42>/Logical Operator3'
   */
  rtb_j03o = (boolean_T)((int32_T)(((int32_T)(*rt_gd42I)) || ((((int32_T)
    Sac_lin_fad_enable_multi_ramp) != ((int32_T)0)) && ((int32_T)
    DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay2_DSTATE))));

  /* Outputs for Atomic SubSystem: '<S42>/S-R_Flip_Flop' */
  /* Outputs for Atomic SubSystem: '<S45>/Atomic Subsystem' */
  /* Switch: '<S46>/Switch' */
  if ((int32_T)rtb_aaff) {
    /* Switch: '<S46>/Switch2' incorporates:
     *  Constant: '<S46>/Constant'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE_l3th = (boolean_T)
      true;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Switch: '<S46>/Switch1' */
  if ((int32_T)rtb_j03o) {
    /* Switch: '<S46>/Switch2' incorporates:
     *  Constant: '<S46>/Constant1'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE_l3th = (boolean_T)
      false;
  }

  /* End of Switch: '<S46>/Switch1' */

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S46>/Constant4'
   *  Logic: '<S46>/Logical Operator1'
   */
  if (((int32_T)rtb_aaff) && ((int32_T)rtb_j03o)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE_l3th = (boolean_T)
      false;
  }

  /* End of Outputs for SubSystem: '<S45>/Atomic Subsystem' */
  /* End of Outputs for SubSystem: '<S42>/S-R_Flip_Flop' */

  /* Switch: '<S43>/Switch3' */
  if ((int32_T)rtb_fwgx) {
    /* MinMax: '<S12>/MinMax' incorporates:
     *  Constant: '<S43>/Constant1'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = 1.0F;
  } else {
    /* MinMax: '<S12>/MinMax' incorporates:
     *  Constant: '<S43>/Constant2'
     */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = 0.0F;
  }

  /* End of Switch: '<S43>/Switch3' */

  /* Switch: '<S47>/Switch5' incorporates:
   *  Constant: '<S47>/Constant5'
   *  Gain: '<S47>/Sac_ts'
   *  Sum: '<S47>/Add1'
   */
  if ((int32_T)(*rt_gd42I)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE = 0.0F;
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE += (((real32_T)
      Sac_ts) * 3.05175781E-5F) *
      DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g;
  }

  /* End of Switch: '<S47>/Switch5' */

  /* Switch: '<S48>/Switch5' incorporates:
   *  Constant: '<S37>/SAC_Progr_Fading_Coefficient'
   *  Constant: '<S48>/Constant5'
   *  Gain: '<S48>/Sac_ts'
   *  Logic: '<S37>/Logical Operator'
   *  Sum: '<S48>/Add1'
   */
  if (!(*rt_gd42I)) {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo = 0.0F;
  } else {
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo += (((real32_T)
      Sac_ts) * 3.05175781E-5F) * 0.05F;
  }

  /* End of Switch: '<S48>/Switch5' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Sac_angle_fading_mode'
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   */
  if (((int32_T)Sac_angle_fading_mode) == ((int32_T)128)) {
    *rt_erh2sI = *rt_erh2I;
  } else {
    *rt_erh2sI = rtb_aioq;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for Delay: '<S42>/Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay2_DSTATE =
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE_l3th;

  /* Update for Delay: '<S39>/Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay1_DSTATE = rtb_ow2b;

  /* Update for UnitDelay: '<S24>/Unit Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE = *rt_ngfdI;

  /* MinMax: '<S14>/MinMax' incorporates:
   *  Constant: '<S14>/Lat_lka_startup_time'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_jn4g = ((real32_T)
    Lat_lka_startup_time) * 0.0009765625F;
  if (DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE <=
      DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_jn4g) {
    /* Update for UnitDelay: '<S14>/Unit Delay2' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_jn4g =
      DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE;
  }

  /* End of MinMax: '<S14>/MinMax' */

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE = rtb_nwur;

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_huhv = rtb_ctya;

  /* Update for UnitDelay: '<S5>/Unit Delay1' incorporates:
   *  Abs: '<S5>/Abs'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Logic: '<S5>/Logical Operator'
   *  Logic: '<S5>/Logical Operator1'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_bsyw = (boolean_T)
    ((int32_T)((((real32_T)fabs((real_T)rtb_dt1r)) > 0.001F) && ((int32_T)
       ((boolean_T)((int32_T)((rtb_dt1r > 0.0F) ^ (rtb_aioq < 0.0F)))))));

  /* MinMax: '<S9>/MinMax1' */
  if (rtb_cwrb >= 0.0F) {
    /* Update for UnitDelay: '<S9>/Unit Delay5' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE = rtb_cwrb;
  } else {
    /* Update for UnitDelay: '<S9>/Unit Delay5' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE = 0.0F;
  }

  /* End of MinMax: '<S9>/MinMax1' */

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_m1ek = *rt_kaadI;

  /* Update for UnitDelay: '<S9>/Unit Delay4' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE_hg2d = rtb_ek4f;

  /* Update for MinMax: '<S12>/MinMax' incorporates:
   *  Update for UnitDelay: '<S9>/Unit Delay2'
   */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = rtb_cwrb;

  /* MinMax: '<S15>/MinMax2' */
  if (rtb_fnqf >= 0.0F) {
    /* Update for UnitDelay: '<S15>/Unit Delay5' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE_k0cr = rtb_fnqf;
  } else {
    /* Update for UnitDelay: '<S15>/Unit Delay5' */
    DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE_k0cr = 0.0F;
  }

  /* End of MinMax: '<S15>/MinMax2' */

  /* Update for UnitDelay: '<S20>/Unit Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_npeh = *rt_cpaoI;

  /* Update for UnitDelay: '<S20>/Unit Delay3' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE_dklm = rtb_dqe5;

  /* Update for UnitDelay: '<S20>/Unit Delay4' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE = rtb_d1ql;

  /* Update for UnitDelay: '<S16>/Unit Delay2' */
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_e30m = *rt_eltpI;
}

/* Model initialize function */
void DMC_Lat_SAC_Angle_Command_Fading_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Lat_SAC_Angle_Command_Fading_DWork, 0,
                    sizeof(rtDW_DMC_Lat_SAC_Angle_Command_Fading_T));
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay1_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_mlby = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_okxo = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_gxyd = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_jn4g = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_huhv = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_pr3g = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay5_DSTATE_k0cr = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_kujk = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_npeh = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay3_DSTATE_dklm = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay4_DSTATE = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay2_DSTATE_e30m = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.UnitDelay1_DSTATE_cjrr = 0.0F;
  DMC_Lat_SAC_Angle_Command_Fading_DWork.Delay_DSTATE_b5gf = 0.0F;
}
