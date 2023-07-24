/* $Header: DMC_Lat_LAT_Delta_F_Offset_Switch.c 1.41 2020/08/20 10:42:52CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_LAT_Delta_F_Offset_Switch.c
   C source code generated on           : Mon Aug 17 20:46:37 2020
   Filename of Simulink Model           : DMC_Lat_LAT_Delta_F_Offset_Switch.mdl/.slx
   Revision of Simulink Model           : 1.491
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
#include "DMC_Lat_LAT_Delta_F_Offset_Switch.h"
#include "DMC_Lat_LAT_Delta_F_Offset_Switch_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: signed_int16_t Lat_oc_min_kappa_quality, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode_2, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_off_flt_initial_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_const_trq_cnt_max_limit, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_const_trq_cnt_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_const_trq_pos_increment, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_dys_pre_filter_length, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_min_head_err_qual, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_min_latency, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_offset_state, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_minimum_latency, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_minimum_latency_shrt, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_controller_mode, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_downsample, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_min_state_nvm, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_weighting_power, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max_steer_angle, [, ], 1  1,
   PARA: signed_int16_t Lat_delta_f_offset, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max_clm_trq, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_max_nvm, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_max_nvm_strt, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_variation, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_calib_cnt_grad, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_delta_f_offset, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_delta_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_implaus_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_learning_rate, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_f_dot, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_offset, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_offset_kappa, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_lateral_accel, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_offset_rate, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_max_angle, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_max_angle_speed, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_max_holding_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_min_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_min_veh_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_offset_init, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_offset_saturation, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_reset, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_stiffness_init, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_small_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_tolerated_delta_ys, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_off_flt_initial_omega, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_offset_filter_omega, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_fast_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_cmd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_ffwd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_psi, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_sign_delta_ys_weighting, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_ki, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_confid_threshold_2, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_confidence_threshold, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_input_filter_coeff, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_lambda, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_offset_increment, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_var_stiffness_init, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_variance_offset_init, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_max_kappa, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_max_kappa_dys, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_velocity_dys, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_heading_error, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_inc_per_loop_slow, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_inc_per_loop_turn_on, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_increment_per_loop, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_out_incr_per_loop, [, ], 1  1,
   CALL: DMC_Lat_LAT_Delta_F_Offset_Switch_step()
   CALL: DMC_Lat_LAT_Delta_F_Offset_Switch_initialize(0)
   FILE: DMC_Lat_LAT_Delta_F_Offset_Switch.c
 ***************************************************************************************************
 */

/* Block signals (auto storage) */
rtB_DMC_Lat_LAT_Delta_F_Offset_Switch_T DMC_Lat_LAT_Delta_F_Offset_Switch_B;

/* Block states (auto storage) */
rtDW_DMC_Lat_LAT_Delta_F_Offset_Switch_T DMC_Lat_LAT_Delta_F_Offset_Switch_DWork;

/* Previous zero-crossings (trigger) states */
rtZCE_DMC_Lat_LAT_Delta_F_Offset_Switch_T
  DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState;

/* Initial conditions for referenced model: 'DMC_Lat_LAT_Delta_F_Offset_Switch' */
void DMC_Lat_LAT_Delta_F_Offset_Switch_Init(void)
{
  /* InitializeConditions for UnitDelay: '<Root>/Alg loop' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Algloop_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hqil = (boolean_T)
    false;

  /* InitializeConditions for Atomic SubSystem: '<Root>/LAT_VDY_Steering_Angle_Offset_Monitoring1' */
  /* InitializeConditions for Atomic SubSystem: '<S14>/Lateral_Error_Mean_Filter' */
  /* InitializeConditions for Atomic SubSystem: '<S247>/Mean_Of_Segment' */
  /* InitializeConditions for UnitDelay: '<S251>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_egfs = (boolean_T)
    false;

  /* InitializeConditions for Delay: '<S251>/Resettable Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S251>/Resettable Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE = 0U;

  /* InitializeConditions for Delay: '<S251>/Resettable Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S251>/Resettable Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay3_DSTATE = (boolean_T)
    false;

  /* End of InitializeConditions for SubSystem: '<S247>/Mean_Of_Segment' */
  /* End of InitializeConditions for SubSystem: '<S14>/Lateral_Error_Mean_Filter' */

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_edix = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed = 0.0F;

  /* End of InitializeConditions for SubSystem: '<Root>/LAT_VDY_Steering_Angle_Offset_Monitoring1' */

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_ade5 = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S86>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_ovny = 0.0F;

  /* InitializeConditions for Triggered SubSystem: '<S10>/LAT_Oc_Rls' */
  /* InitializeConditions for UnitDelay: '<S140>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h = 0.0F;

  /* InitializeConditions for UnitDelay: '<S132>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_nzoi = 0.0F;

  /* InitializeConditions for UnitDelay: '<S126>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ew4c = 0.0F;

  /* InitializeConditions for UnitDelay: '<S121>/P_0' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)0] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)1] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)2] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)3] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S121>/Theta_0' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)0] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)1] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S139>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_fins = 0.0F;

  /* InitializeConditions for UnitDelay: '<S118>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hxh1 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S132>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_bedr = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S10>/LAT_Oc_Rls' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/LAT_Oc_I_Part_Reset1' */
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jbdz = (uint16_T)0U;

  /* InitializeConditions for Atomic SubSystem: '<S9>/Detect_DMC_Settlement' */
  /* InitializeConditions for UnitDelay: '<S80>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l1fh = 0U;

  /* End of InitializeConditions for SubSystem: '<S9>/Detect_DMC_Settlement' */
  /* End of InitializeConditions for SubSystem: '<Root>/LAT_Oc_I_Part_Reset1' */

  /* InitializeConditions for UnitDelay: '<S20>/Latching_VDY_Offset' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Latching_VDY_Offset_DSTATE = 0.0F;

  /* InitializeConditions for Saturate: '<S87>/Saturation' incorporates:
   *  InitializeConditions for UnitDelay: '<S27>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for MinMax: '<S34>/MinMax2' incorporates:
   *  InitializeConditions for UnitDelay: '<S28>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = 0.0F;

  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay5' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb = 0.0F;

  /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kb3q = 0.0F;

  /* InitializeConditions for UnitDelay: '<S67>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_hb45 = 0.0F;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_cct5 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S66>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = 0.0F;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay5' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_lape = 0.0F;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_dm2g = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S43>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_odq4 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_lv1m = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_afzy = 0.0F;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jlpv = 0.0F;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl = 0.0F;

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l4u2 = 0.0F;

  /* InitializeConditions for Triggered SubSystem: '<S8>/LAT_Oc_Delta_Ys_Maf' */
  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hnso = 0.0F;

  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_oylu = 0.0F;

  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hwvo = 0.0F;

  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay4' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S8>/LAT_Oc_Delta_Ys_Maf' */

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_ggbc = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_anr4 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_kcdv = 0.0F;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay5' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_p3z4 = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay4' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE_m4ak = (boolean_T)
    false;

  /* InitializeConditions for MinMax: '<S245>/Min' incorporates:
   *  InitializeConditions for UnitDelay: '<S245>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_k3jm = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S243>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq = 0.0F;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_lqx1 = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ouus = 0.0F;
}

/* Start for referenced model: 'DMC_Lat_LAT_Delta_F_Offset_Switch' */
void DMC_Lat_LAT_Delta_F_Offset_Switch_Start(void)
{
  /* Start for Atomic SubSystem: '<Root>/LAT_VDY_Steering_Angle_Offset_Monitoring1' */
  /* Start for Atomic SubSystem: '<S14>/Lateral_Error_Mean_Filter' */
  /* InitializeConditions for Enabled SubSystem: '<S247>/Mean_Of_All_Segments' */
  /* InitializeConditions for Delay: '<S250>/Item_1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_3_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_4' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_4_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_5' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_5_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_6' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_6_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_7' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_7_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_8' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_8_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Item_9' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_9_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S250>/Count' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.icLoad = 1U;

  /* End of InitializeConditions for SubSystem: '<S247>/Mean_Of_All_Segments' */
  /* End of Start for SubSystem: '<S14>/Lateral_Error_Mean_Filter' */
  /* End of Start for SubSystem: '<Root>/LAT_VDY_Steering_Angle_Offset_Monitoring1' */
}

/* Output and update for referenced model: 'DMC_Lat_LAT_Delta_F_Offset_Switch' */
void DMC_Lat_LAT_Delta_F_Offset_Switch(const boolean_T *rt_erh2I, const real32_T
  *rt_gd42I, const uint32_T *rt_cpaoI, const real32_T *rt_e4hoI, const int16_T
  *rt_ngfdI, const real32_T *rt_f3r3I, const real32_T *rt_kkebI, const int16_T
  *rt_hny3I, const real32_T *rt_kwugI, const int16_T *rt_kafvI, const real32_T
  *rt_kaadI, const int16_T *rt_eltpI, const real32_T *rt_cjpeI, const real32_T
  *rt_ezusI, const real32_T *rt_orb0I, const int16_T *rt_pdp2I, const boolean_T *
  rt_dxdkI, const real32_T *rt_dmmuI, const real32_T *rt_gyqsI, const real32_T
  *rt_m2jwI, const boolean_T *rt_pdncI, const real32_T *rt_id5lI, const uint16_T
  *rt_prezI, const boolean_T *rt_pehlI, const boolean_T *rt_o3aaI, const
  real32_T *rt_e45jI, const real32_T *rt_mcq4I, const real32_T *rt_jus1I, const
  real32_T *rt_popsI, const uint16_T *rt_m3xfI, const boolean_T *rt_p2o1I, const
  boolean_T *rt_i3p3I, const uint16_T *rt_ka1pI, const boolean_T *rt_hsldI,
  real32_T *rt_erh2sI, real32_T *rt_gd42sI, real32_T *rt_cpaomI, boolean_T
  *rt_e4ho4I, real32_T *rt_ngfdoI, uint16_T *rt_f3r3lI, real32_T *rt_kkeboI)
{
  boolean_T rtb_;
  real32_T rtb_k10u;
  boolean_T rtb_l4st;
  real32_T rtb_c0ms;
  real32_T rtb_flap;
  boolean_T rtb_gi5c;
  real32_T rtb_ljyp;
  real32_T rtb_nyue;
  real32_T rtb_cxqu;
  boolean_T rtb_fd04;
  boolean_T rtb_gkjv;
  real_T rtb_nlel;
  real_T rtb_ozkw;
  boolean_T rtb_jmzk;
  boolean_T rtb_dohp;
  boolean_T rtb_j344;
  boolean_T rtb_fc3o;
  boolean_T rtb_eczq;
  boolean_T rtb_fxjo;
  boolean_T rtb_met5;
  boolean_T rtb_f51a;
  boolean_T rtb_lwwu;
  boolean_T rtb_ckb4;
  boolean_T rtb_dhrr;
  boolean_T rtb_gcmg;
  boolean_T rtb_la0n;
  boolean_T rtb_anu3;
  boolean_T rtb_m1bl;
  real_T rtb_gp1m;
  boolean_T rtb_lo1a;
  boolean_T rtb_m1aa;
  int32_T rtb_eryf;
  int32_T rtb_ihwv;
  int32_T rtb_clet;
  int32_T rtb_edjj;
  int32_T rtb_mosm;
  int32_T rtb_girm;
  int32_T rtb_j0jq;
  int32_T rtb_nnov;
  int32_T rtb_njxy;
  int32_T rtb_mubn;
  int32_T rtb_bwxv;
  int32_T rtb_gisu;
  int32_T rtb_lrdu;
  uint16_T rtb_cv5n;
  uint16_T rtb_k4uc;
  boolean_T rtb_odcj;
  real32_T rtb_ilfo;
  real32_T rtb_bwu1;
  boolean_T rtb_n5rr;
  boolean_T rtb_ffgm;
  real32_T rtb_gvqf;
  real32_T rtb_au0t;
  boolean_T rtb_egra;
  boolean_T rtb_ayh2;
  uint8_T rtb_p4gi;
  real32_T rtb_gpno;
  int32_T rtb_g0pg;
  real32_T rtb_ltjz;
  real32_T rtb_jcpi;
  real32_T rtb_nrby;
  real32_T rtb_o53h;
  real32_T rtb_jrck;
  real32_T rtb_hsjc;
  real32_T rtb_kacn;
  real32_T rtb_lowb;
  real32_T rtb_cph1;
  int16_T rtb_ajkb;
  real32_T tmp_;

  /* Logic: '<S20>/Logical Operator1' incorporates:
   *  Logic: '<S20>/Logical Operator2'
   *  UnitDelay: '<S20>/Unit Delay3'
   */
  rtb_ = (boolean_T)((int32_T)(((int32_T)(*rt_o3aaI)) &&
    (!DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hqil)));

  /* Switch: '<S20>/Switch5' incorporates:
   *  Constant: '<S20>/Constant3'
   *  Constant: '<S20>/Constant6'
   */
  if ((int32_T)rtb_) {
    rtb_c0ms = 3.0F;
  } else {
    rtb_c0ms = 0.0F;
  }

  /* End of Switch: '<S20>/Switch5' */

  /* Outputs for Atomic SubSystem: '<Root>/LAT_VDY_Steering_Angle_Offset_Monitoring1' */
  /* RelationalOperator: '<S14>/Relational Operator1' */
  rtb_odcj = (boolean_T)((int32_T)((*rt_kafvI) >= ((int16_T)1)));

  /* Outputs for Atomic SubSystem: '<S14>/Lateral_Error_Mean_Filter' */
  /* Logic: '<S247>/Logical Operator1' */
  rtb_egra = (boolean_T)((int32_T)(!rtb_odcj));

  /* Outputs for Atomic SubSystem: '<S247>/Mean_Of_Segment' */
  /* Logic: '<S251>/Logical Operator' incorporates:
   *  UnitDelay: '<S251>/Unit Delay2'
   */
  rtb_ayh2 = (boolean_T)((int32_T)(((int32_T)
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_egfs) || ((int32_T)
    rtb_egra)));

  /* Delay: '<S251>/Resettable Delay1' */
  if ((int32_T)rtb_ayh2) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay1_DSTATE = 0.0F;
  }

  /* Switch: '<S251>/Switch1' incorporates:
   *  Constant: '<S251>/Constant2'
   */
  if ((int32_T)rtb_egra) {
    rtb_gpno = 0.0F;
  } else {
    rtb_gpno = *rt_kwugI;
  }

  /* End of Switch: '<S251>/Switch1' */

  /* Sum: '<S251>/Add1' incorporates:
   *  Delay: '<S251>/Resettable Delay1'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay1_DSTATE += rtb_gpno;

  /* Delay: '<S251>/Resettable Delay' */
  if ((int32_T)rtb_ayh2) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE = 0U;
  }

  /* Switch: '<S251>/Switch' incorporates:
   *  Constant: '<S251>/Constant1'
   *  Constant: '<S251>/Constant3'
   */
  if ((int32_T)rtb_egra) {
    rtb_p4gi = 0U;
  } else {
    rtb_p4gi = 1U;
  }

  /* End of Switch: '<S251>/Switch' */

  /* Sum: '<S251>/Add2' incorporates:
   *  Delay: '<S251>/Resettable Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE = (uint8_T)
    (((uint32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE)
     + ((uint32_T)rtb_p4gi));

  /* MinMax: '<S251>/MinMax' */
  if (((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE) >=
      ((int32_T)1)) {
    rtb_p4gi = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE;
  } else {
    rtb_p4gi = 1U;
  }

  /* End of MinMax: '<S251>/MinMax' */

  /* RelationalOperator: '<S251>/Relational Operator' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_egfs = (boolean_T)
    ((int32_T)(((int32_T)
                DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay_DSTATE) >=
               ((int32_T)100)));

  /* Delay: '<S251>/Resettable Delay2' */
  if ((int32_T)rtb_egra) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay2_DSTATE = 0.0F;
  }

  /* End of Delay: '<S251>/Resettable Delay2' */

  /* Delay: '<S251>/Resettable Delay3' */
  if ((int32_T)rtb_egra) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay3_DSTATE = (boolean_T)
      false;
  }

  /* End of Delay: '<S251>/Resettable Delay3' */

  /* Switch: '<S251>/Switch2' incorporates:
   *  Product: '<S251>/Divide'
   */
  if ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_egfs) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay2_DSTATE =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay1_DSTATE /
      ((real32_T)rtb_p4gi);
  }

  /* End of Switch: '<S251>/Switch2' */

  /* Switch: '<S251>/Switch3' incorporates:
   *  Constant: '<S251>/Constant'
   */
  if ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_egfs) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay3_DSTATE = (boolean_T)
      true;
  }

  /* End of Switch: '<S251>/Switch3' */
  /* End of Outputs for SubSystem: '<S247>/Mean_Of_Segment' */

  /* Outputs for Enabled SubSystem: '<S247>/Mean_Of_All_Segments' incorporates:
   *  EnablePort: '<S250>/Enable'
   */
  /* Logic: '<S247>/Logical Operator2' */
  if (((int32_T)rtb_egra) || ((int32_T)
       DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_egfs)) {
    /* Switch: '<S250>/Switch' incorporates:
     *  Constant: '<S250>/Constant1'
     */
    if ((int32_T)rtb_egra) {
      rtb_ltjz = 0.0F;
    } else {
      rtb_ltjz = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay2_DSTATE;
    }

    /* End of Switch: '<S250>/Switch' */

    /* Delay: '<S250>/Item_1' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_1_DSTATE = 0.0F;
    }

    rtb_jcpi = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_1_DSTATE;

    /* Delay: '<S250>/Item_2' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_2_DSTATE = 0.0F;
    }

    rtb_nrby = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_2_DSTATE;

    /* Delay: '<S250>/Item_3' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_3_DSTATE = 0.0F;
    }

    rtb_o53h = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_3_DSTATE;

    /* Delay: '<S250>/Item_4' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_4_DSTATE = 0.0F;
    }

    rtb_jrck = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_4_DSTATE;

    /* Delay: '<S250>/Item_5' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_5_DSTATE = 0.0F;
    }

    rtb_hsjc = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_5_DSTATE;

    /* Delay: '<S250>/Item_6' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_6_DSTATE = 0.0F;
    }

    rtb_kacn = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_6_DSTATE;

    /* Delay: '<S250>/Item_7' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_7_DSTATE = 0.0F;
    }

    rtb_lowb = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_7_DSTATE;

    /* Delay: '<S250>/Item_8' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_8_DSTATE = 0.0F;
    }

    rtb_cph1 = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_8_DSTATE;

    /* Delay: '<S250>/Item_9' */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_9_DSTATE = 0.0F;
    }

    /* Delay: '<S250>/Count' incorporates:
     *  Constant: '<S250>/Constant4'
     */
    if ((int32_T)rtb_egra) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.icLoad = 1U;
    }

    if (((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.icLoad) != ((int32_T)0))
    {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Count_DSTATE = 1U;
    }

    /* Switch: '<S253>/Switch1' incorporates:
     *  Constant: '<S253>/Constant2'
     *  Constant: '<S253>/Constant3'
     *  Delay: '<S250>/Count'
     *  RelationalOperator: '<S253>/Relational Operator1'
     */
    if (((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Count_DSTATE) >
        ((int32_T)0)) {
      rtb_g0pg = (int32_T)1;
    } else {
      rtb_g0pg = (int32_T)-1;
    }

    /* End of Switch: '<S253>/Switch1' */

    /* Product: '<S252>/Product5' */
    rtb_gpno = (real32_T)(((real_T)rtb_g0pg) * 0.0099999997764825821);

    /* Switch: '<S252>/Switch' incorporates:
     *  Constant: '<S252>/Constant'
     *  Delay: '<S250>/Count'
     *  RelationalOperator: '<S252>/Relational Operator'
     */
    if (((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Count_DSTATE) <= 0.01)
    {
    } else {
      rtb_gpno = (real32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Count_DSTATE;
    }

    /* End of Switch: '<S252>/Switch' */

    /* Product: '<S250>/Divide' incorporates:
     *  Delay: '<S250>/Item_1'
     *  Delay: '<S250>/Item_2'
     *  Delay: '<S250>/Item_3'
     *  Delay: '<S250>/Item_4'
     *  Delay: '<S250>/Item_5'
     *  Delay: '<S250>/Item_6'
     *  Delay: '<S250>/Item_7'
     *  Delay: '<S250>/Item_8'
     *  Delay: '<S250>/Item_9'
     *  Sum: '<S250>/Add1'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide = (((((((((rtb_ltjz +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_1_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_2_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_3_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_4_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_5_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_6_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_7_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_8_DSTATE) +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_9_DSTATE) / rtb_gpno;

    /* Switch: '<S250>/Switch2' incorporates:
     *  Constant: '<S250>/Constant2'
     *  Delay: '<S250>/Count'
     *  RelationalOperator: '<S250>/Relational Operator1'
     */
    if (((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Count_DSTATE) <
        ((int32_T)10)) {
      /* Update for Delay: '<S250>/Count' incorporates:
       *  Constant: '<S250>/Constant3'
       *  Sum: '<S250>/Sum'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Count_DSTATE++;
    }

    /* End of Switch: '<S250>/Switch2' */

    /* Update for Delay: '<S250>/Item_1' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_1_DSTATE = rtb_ltjz;

    /* Update for Delay: '<S250>/Item_2' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_2_DSTATE = rtb_jcpi;

    /* Update for Delay: '<S250>/Item_3' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_3_DSTATE = rtb_nrby;

    /* Update for Delay: '<S250>/Item_4' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_4_DSTATE = rtb_o53h;

    /* Update for Delay: '<S250>/Item_5' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_5_DSTATE = rtb_jrck;

    /* Update for Delay: '<S250>/Item_6' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_6_DSTATE = rtb_hsjc;

    /* Update for Delay: '<S250>/Item_7' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_7_DSTATE = rtb_kacn;

    /* Update for Delay: '<S250>/Item_8' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_8_DSTATE = rtb_lowb;

    /* Update for Delay: '<S250>/Item_9' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_9_DSTATE = rtb_cph1;

    /* Update for Delay: '<S250>/Count' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.icLoad = 0U;
  }

  /* End of Logic: '<S247>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S247>/Mean_Of_All_Segments' */
  /* End of Outputs for SubSystem: '<S14>/Lateral_Error_Mean_Filter' */

  /* If: '<S14>/If' incorporates:
   *  Constant: '<S248>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Constant: '<S249>/Constant3'
   *  Constant: '<S249>/NoOffsetChangeInfo'
   *  Logic: '<S14>/Logical Operator'
   *  RelationalOperator: '<S14>/Relational Operator'
   */
  if (((*rt_ngfdI) >= ((int16_T)1)) && ((int32_T)rtb_odcj)) {
    /* Outputs for IfAction SubSystem: '<S14>/Offset_Storage_And_Monitoring' incorporates:
     *  ActionPort: '<S248>/Action Port'
     */
    rtb_ayh2 = (boolean_T)true;

    /* Switch: '<S248>/Switch' incorporates:
     *  Constant: '<S248>/Constant'
     *  UnitDelay: '<S14>/Unit Delay1'
     */
    if ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_edix)
    {
    } else {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed = *rt_e4hoI;
    }

    /* End of Switch: '<S248>/Switch' */

    /* Sum: '<S248>/Add' */
    rtb_k10u = (*rt_e4hoI) -
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed;

    /* Sum: '<S248>/Add1' */
    rtb_ltjz = (*rt_e4hoI) -
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed;

    /* Switch: '<S248>/Switch1' incorporates:
     *  RelationalOperator: '<S248>/Relational Operator'
     */
    if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed !=
        (*rt_e4hoI)) {
      /* Update for UnitDelay: '<S14>/Unit Delay2' */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed = *rt_e4hoI;
    }

    /* End of Switch: '<S248>/Switch1' */

    /* Switch: '<S248>/Switch8' incorporates:
     *  Constant: '<S248>/NoOffsetChange'
     *  Constant: '<S248>/OffsetChangeInWrongDirection'
     *  Constant: '<S260>/Constant'
     *  Constant: '<S261>/Constant'
     *  Constant: '<S262>/Constant'
     *  Constant: '<S263>/Constant'
     *  Logic: '<S248>/Logical Operator5'
     *  Logic: '<S248>/Logical Operator6'
     *  Logic: '<S248>/Logical Operator7'
     *  RelationalOperator: '<S260>/Compare'
     *  RelationalOperator: '<S261>/Compare'
     *  RelationalOperator: '<S262>/Compare'
     *  RelationalOperator: '<S263>/Compare'
     */
    if (((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide >= 0.0F) && (rtb_ltjz <
          0.0F)) || ((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide <= 0.0F) &&
                     (rtb_ltjz > 0.0F))) {
      rtb_p4gi = 3U;
    } else {
      rtb_p4gi = 1U;
    }

    /* End of Switch: '<S248>/Switch8' */

    /* Switch: '<S248>/Switch7' incorporates:
     *  Constant: '<S248>/OffsetChangeInCorrectDirection'
     *  Constant: '<S256>/Constant'
     *  Constant: '<S257>/Constant'
     *  Constant: '<S258>/Constant'
     *  Constant: '<S259>/Constant'
     *  Logic: '<S248>/Logical Operator'
     *  Logic: '<S248>/Logical Operator3'
     *  Logic: '<S248>/Logical Operator4'
     *  RelationalOperator: '<S256>/Compare'
     *  RelationalOperator: '<S257>/Compare'
     *  RelationalOperator: '<S258>/Compare'
     *  RelationalOperator: '<S259>/Compare'
     */
    if (((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide > 0.0F) && (rtb_ltjz > 0.0F))
        || ((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide < 0.0F) && (rtb_ltjz <
          0.0F))) {
      rtb_p4gi = 2U;
    }

    /* End of Switch: '<S248>/Switch7' */

    /* Switch: '<S248>/Switch6' incorporates:
     *  Constant: '<S248>/Inti'
     *  Logic: '<S248>/Logical Operator1'
     *  Logic: '<S248>/Logical Operator8'
     *  Logic: '<S248>/Logical Operator9'
     *  UnitDelay: '<S14>/Unit Delay1'
     */
    if ((!DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_edix) ||
        (!DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay3_DSTATE)) {
      rtb_p4gi = 0U;
    }

    /* End of Switch: '<S248>/Switch6' */
    /* End of Outputs for SubSystem: '<S14>/Offset_Storage_And_Monitoring' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/Reset_Arrays' incorporates:
     *  ActionPort: '<S249>/Action Port'
     */
    rtb_ayh2 = (boolean_T)false;

    /* Update for UnitDelay: '<S14>/Unit Delay2' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Constant: '<S249>/Constant2'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed = 0.0F;
    rtb_p4gi = 0U;
    rtb_k10u = 0.0F;

    /* End of Outputs for SubSystem: '<S14>/Reset_Arrays' */
  }

  /* End of If: '<S14>/If' */

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_edix = rtb_ayh2;

  /* End of Outputs for SubSystem: '<Root>/LAT_VDY_Steering_Angle_Offset_Monitoring1' */

  /* Switch: '<S20>/Switch4' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Constant: '<S20>/Constant10'
   *  Constant: '<S20>/Constant9'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Logic: '<S20>/Logical Operator6'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S46>/Compare'
   *  S-Function (sfix_bitop): '<S20>/Bitwise Operator1'
   */
  if (((rtb_k10u != 0.0F) && ((((int32_T)Dmc_configuration_mode_2) & ((int32_T)
          1024)) != ((int32_T)0))) && (!rtb_)) {
    rtb_ljyp = 6.0F;
  } else {
    rtb_ljyp = 0.0F;
  }

  /* End of Switch: '<S20>/Switch4' */

  /* MinMax: '<S20>/MinMax' */
  if (rtb_c0ms >= rtb_ljyp) {
  } else {
    rtb_c0ms = rtb_ljyp;
  }

  /* End of MinMax: '<S20>/MinMax' */

  /* MinMax: '<S20>/MinMax1' */
  if (rtb_c0ms >= 1.0F) {
    tmp_ = rtb_c0ms;
  } else {
    tmp_ = 1.0F;
  }

  /* Logic: '<S70>/Logical Operator' incorporates:
   *  Constant: '<S70>/Lat_oc_min_offset_state'
   *  Constant: '<S71>/Constant'
   *  RelationalOperator: '<S70>/Relational Operator'
   *  RelationalOperator: '<S71>/Compare'
   *  S-Function (sfix_bitop): '<S70>/Bitwise Operator'
   */
  rtb_l4st = (boolean_T)((int32_T)((((*rt_cpaoI) & 4194304U) != ((uint32_T)0U)) &&
                          (((int32_T)(*rt_ngfdI)) >= ((int32_T)
    Lat_oc_min_offset_state))));

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S20>/Constant'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  S-Function (sfix_bitop): '<S20>/Bitwise Operator'
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  if ((rtb_l4st !=
       DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_ade5) ||
      (((*rt_cpaoI) & 1073741824U) != ((uint32_T)0U))) {
    rtb_nyue = 0.0F;
  } else {
    rtb_nyue = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S20>/Switch2' */

  /* RelationalOperator: '<S47>/Relational Operator' incorporates:
   *  Constant: '<S47>/Lat_delta_f_off_standstill_thrs'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  rtb_ = (boolean_T)((int32_T)
                     (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE >
                      1.0F));

  /* Constant: '<S47>/Lat_delta_f_offset_variation' */
  rtb_nrby = ((real32_T)Lat_delta_f_offset_variation) * 0.0009765625F;

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S47>/Constant4'
   */
  if ((int32_T)rtb_) {
    rtb_nrby = 0.0F;
  }

  /* End of Switch: '<S47>/Switch2' */

  /* Sum: '<S50>/Add' incorporates:
   *  Abs: '<S50>/Abs1'
   */
  rtb_c0ms = ((real32_T)fabs((real_T)(*rt_id5lI))) - rtb_nrby;

  /* MinMax: '<S50>/MinMax' */
  if (0.0F >= rtb_c0ms) {
    rtb_c0ms = 0.0F;
  }

  /* Signum: '<S50>/Sign1' */
  if ((*rt_id5lI) < 0.0F) {
    rtb_ltjz = -1.0F;
  } else if ((*rt_id5lI) > 0.0F) {
    rtb_ltjz = 1.0F;
  } else {
    rtb_ltjz = *rt_id5lI;
  }

  /* Product: '<S50>/Product1' incorporates:
   *  MinMax: '<S50>/MinMax'
   *  Signum: '<S50>/Sign1'
   */
  rtb_nrby = rtb_ltjz * rtb_c0ms;

  /* Constant: '<S47>/Lat_delta_f_offset_max_nvm' */
  rtb_c0ms = ((real32_T)Lat_delta_f_offset_max_nvm) * 0.0009765625F;

  /* Switch: '<S47>/Switch3' incorporates:
   *  Constant: '<S47>/Lat_delta_f_offset_max_nvm_strt'
   */
  if ((int32_T)rtb_) {
  } else {
    rtb_c0ms = ((real32_T)Lat_delta_f_offset_max_nvm_strt) * 0.0009765625F;
  }

  /* End of Switch: '<S47>/Switch3' */

  /* MinMax: '<S51>/MinMax1' */
  if (rtb_nrby <= rtb_c0ms) {
  } else {
    rtb_nrby = rtb_c0ms;
  }

  /* End of MinMax: '<S51>/MinMax1' */

  /* Gain: '<S51>/Gain' */
  rtb_c0ms = -rtb_c0ms;

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Constant: '<S47>/Constant3'
   *  Logic: '<S47>/Logical Operator2'
   *  Logic: '<S47>/Logical Operator3'
   *  MinMax: '<S51>/MinMax2'
   *  S-Function (sfix_bitop): '<S47>/Bitwise Operator'
   */
  if ((!((((int32_T)Dmc_configuration_mode_2) & ((int32_T)1)) != ((int32_T)0))) ||
      ((int32_T)(*rt_pehlI))) {
    rtb_cxqu = 0.0F;
  } else if (rtb_nrby >= rtb_c0ms) {
    /* MinMax: '<S51>/MinMax2' */
    rtb_cxqu = rtb_nrby;
  } else {
    /* MinMax: '<S51>/MinMax2' */
    rtb_cxqu = rtb_c0ms;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S10>/Lat_oc_delta_f_offset'
   *  Sum: '<S10>/Add'
   */
  rtb_flap = (*rt_popsI) * ((*rt_gd42I) + (((real32_T)Lat_oc_delta_f_offset) *
    0.0009765625F));

  /* RelationalOperator: '<S86>/Relational Operator' incorporates:
   *  Constant: '<S86>/Constant'
   *  Constant: '<S86>/LAT_Oc_Rls_Downsample'
   *  Sum: '<S86>/Add'
   *  UnitDelay: '<S86>/Unit Delay2'
   */
  rtb_ = (boolean_T)((int32_T)((1.0F +
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_ovny) >=
    ((real32_T)Lat_oc_rls_downsample)));

  /* Logic: '<S86>/Logical Operator1' incorporates:
   *  Constant: '<S86>/Constant1'
   *  Constant: '<S86>/Lat_oc_rls_controller_mode'
   *  Logic: '<S86>/Logical Operator2'
   *  S-Function (sfix_bitop): '<S86>/Bitwise Operator'
   */
  rtb_gi5c = (boolean_T)((int32_T)(((int32_T)rtb_) && (!((((int32_T)
    Lat_oc_rls_controller_mode) & ((int32_T)16)) != ((int32_T)0)))));

  /* Outputs for Triggered SubSystem: '<S10>/LAT_Oc_Rls' incorporates:
   *  TriggerPort: '<S83>/Trigger'
   */
  if (((int32_T)rtb_gi5c) &&
      (DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState.LAT_Oc_Rls_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataTypeConversion: '<S116>/Data Type Conversion1' incorporates:
     *  Constant: '<S116>/Lat_oc_rls_lambda '
     */
    rtb_ltjz = ((real32_T)Lat_oc_rls_lambda) * 3.05175781E-5F;

    /* RelationalOperator: '<S117>/Relational Operator' incorporates:
     *  Abs: '<S117>/Abs1'
     *  Constant: '<S117>/Lat_oc_rls_min_veh_velocity'
     *  DataTypeConversion: '<S117>/Data Type Conversion1'
     */
    rtb_ayh2 = (boolean_T)((int32_T)(((real32_T)fabs((real_T)(*rt_ezusI))) >
      (((real32_T)Lat_oc_rls_min_veh_velocity) * 0.0009765625F)));

    /* Sum: '<S140>/Add' incorporates:
     *  Constant: '<S118>/Lat_oc_rls_input_filter_coeff'
     *  DataTypeConversion: '<S118>/Data Type Conversion4'
     *  Product: '<S140>/Product'
     *  Sum: '<S140>/Add1'
     *  UnitDelay: '<S140>/Unit Delay'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h += ((*rt_m2jwI)
      - DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h) *
      (((real32_T)Lat_oc_rls_input_filter_coeff) * 3.05175781E-5F);

    /* RelationalOperator: '<S117>/Relational Operator3' incorporates:
     *  Constant: '<S117>/Lat_oc_rls_max_angle_speed'
     *  DataTypeConversion: '<S117>/Data Type Conversion6'
     *  UnitDelay: '<S132>/Unit Delay2'
     */
    rtb_odcj = (boolean_T)((int32_T)
      (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_nzoi <
       (((real32_T)Lat_oc_rls_max_angle_speed) * 0.0009765625F)));

    /* RelationalOperator: '<S117>/Relational Operator4' incorporates:
     *  Abs: '<S117>/Abs4'
     *  Constant: '<S117>/Lat_oc_rls_max_angle'
     *  DataTypeConversion: '<S117>/Data Type Conversion7'
     */
    rtb_egra = (boolean_T)((int32_T)(((real32_T)fabs((real_T)rtb_flap)) <
      (((real32_T)Lat_oc_rls_max_angle) * 0.0009765625F)));

    /* Logic: '<S117>/Logical Operator2' incorporates:
     *  RelationalOperator: '<S117>/Relational Operator5'
     *  RelationalOperator: '<S117>/Relational Operator6'
     */
    rtb_n5rr = (boolean_T)((int32_T)((((int32_T)(*rt_m3xfI)) != ((int32_T)1)) &&
                            (((int32_T)(*rt_m3xfI)) != ((int32_T)2))));

    /* Logic: '<S117>/Logical Operator1' incorporates:
     *  Abs: '<S117>/Abs2'
     *  Constant: '<S117>/Constant'
     *  Constant: '<S117>/Lat_oc_rls_controller_mode'
     *  Constant: '<S117>/Lat_oc_rls_min_driver_torque '
     *  DataTypeConversion: '<S117>/Data Type Conversion3'
     *  RelationalOperator: '<S117>/Relational Operator1'
     *  S-Function (sfix_bitop): '<S117>/Bitwise Operator'
     */
    rtb_ffgm = (boolean_T)((int32_T)(((((((int32_T)rtb_ayh2) && (((real32_T)fabs
                                  ((real_T)
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h)) >
      (((real32_T)Lat_oc_rls_min_driver_torque) * 0.0009765625F))) && ((int32_T)
      rtb_odcj)) && ((int32_T)rtb_egra)) && ((int32_T)rtb_n5rr)) && ((((int32_T)
      Lat_oc_rls_controller_mode) & ((int32_T)2)) != ((int32_T)0))));

    /* Logic: '<S117>/Logical Operator' incorporates:
     *  Constant: '<S117>/Constant3'
     *  Constant: '<S117>/Lat_oc_rls_controller_mode'
     *  S-Function (sfix_bitop): '<S117>/Bitwise Operator1'
     */
    rtb_ayh2 = (boolean_T)((int32_T)((((((int32_T)rtb_odcj) && ((int32_T)
      rtb_egra)) && ((int32_T)rtb_n5rr)) && ((int32_T)rtb_ayh2)) && ((((int32_T)
      Lat_oc_rls_controller_mode) & ((int32_T)4)) != ((int32_T)0))));

    /* Switch: '<S127>/Switch7' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Logic: '<S127>/Logical Operator1'
     */
    if (((int32_T)rtb_ffgm) && ((int32_T)rtb_ayh2)) {
    } else {
      rtb_ltjz = 1.0F;
    }

    /* End of Switch: '<S127>/Switch7' */

    /* Switch: '<S128>/Switch1' incorporates:
     *  RelationalOperator: '<S128>/Relational Operator1'
     */
    if (rtb_ltjz > 0.0F) {
      rtb_ilfo = 1.0F;
    } else {
      rtb_ilfo = -1.0F;
    }

    /* End of Switch: '<S128>/Switch1' */

    /* Switch: '<S122>/Switch' incorporates:
     *  Abs: '<S122>/Abs'
     *  Constant: '<S122>/Constant1'
     *  Product: '<S122>/Product5'
     *  RelationalOperator: '<S122>/Relational Operator'
     */
    if (((real32_T)fabs((real_T)rtb_ltjz)) <= 0.01F) {
      rtb_bwu1 = rtb_ilfo * 0.01F;
    } else {
      rtb_bwu1 = rtb_ltjz;
    }

    /* End of Switch: '<S122>/Switch' */

    /* DataTypeConversion: '<S121>/Data Type Conversion4' incorporates:
     *  Constant: '<S121>/Lat_oc_rls_stiffness_init '
     */
    rtb_ilfo = ((real32_T)Lat_oc_rls_stiffness_init) * 0.0009765625F;

    /* Switch: '<S129>/Switch1' incorporates:
     *  RelationalOperator: '<S129>/Relational Operator1'
     */
    if (rtb_ilfo > 0.0F) {
      rtb_jcpi = 1.0F;
    } else {
      rtb_jcpi = -1.0F;
    }

    /* End of Switch: '<S129>/Switch1' */

    /* Switch: '<S123>/Switch' incorporates:
     *  Abs: '<S123>/Abs'
     *  Constant: '<S123>/Constant1'
     *  Product: '<S123>/Product5'
     *  RelationalOperator: '<S123>/Relational Operator'
     */
    if (rtb_ilfo <= 0.01F) {
      rtb_ilfo = rtb_jcpi * 0.01F;
    }

    /* End of Switch: '<S123>/Switch' */

    /* Switch: '<S127>/Switch1' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if ((int32_T)rtb_ffgm) {
      rtb_jcpi = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h;
    } else {
      rtb_jcpi = 0.0F;
    }

    /* End of Switch: '<S127>/Switch1' */

    /* Switch: '<S127>/Switch2' incorporates:
     *  Constant: '<S116>/Offset'
     *  Constant: '<S127>/Constant'
     */
    if ((int32_T)rtb_ayh2) {
      rtb_cph1 = -1.0F;
    } else {
      rtb_cph1 = 0.0F;
    }

    /* End of Switch: '<S127>/Switch2' */

    /* SignalConversion: '<S121>/TmpSignal ConversionAtProductInport2' */
    rtb_jrck = rtb_jcpi;
    rtb_gvqf = rtb_cph1;

    /* Logic: '<S126>/Logical Operator' incorporates:
     *  Constant: '<S126>/Lat_oc_rls_reset'
     *  DataTypeConversion: '<S126>/Data Type Conversion6'
     *  Logic: '<S126>/Logical Operator1'
     *  UnitDelay: '<S126>/Unit Delay'
     */
    rtb_n5rr = (boolean_T)((int32_T)
      ((!(DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ew4c != 0.0F))
       && (((int32_T)Lat_oc_rls_reset) != ((int32_T)0))));

    /* DataTypeConversion: '<S121>/Data Type Conversion2' incorporates:
     *  Constant: '<S121>/Lat_oc_rls_var_stiffness_init'
     */
    rtb_au0t = ((real32_T)Lat_oc_rls_var_stiffness_init) * 3.05175781E-5F;

    /* Switch: '<S121>/Switch1' incorporates:
     *  UnitDelay: '<S121>/P_0'
     */
    if ((int32_T)rtb_n5rr) {
    } else {
      rtb_au0t = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)0];
    }

    rtb_o53h = rtb_au0t;
    rtb_au0t = 0.0F;
    if ((int32_T)rtb_n5rr) {
    } else {
      rtb_au0t = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)1];
    }

    rtb_kacn = rtb_au0t;
    rtb_au0t = 0.0F;
    if ((int32_T)rtb_n5rr) {
    } else {
      rtb_au0t = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)2];
    }

    rtb_hsjc = rtb_au0t;

    /* DataTypeConversion: '<S121>/Data Type Conversion3' incorporates:
     *  Constant: '<S121>/Lat_oc_rls_variance_offset_init'
     */
    rtb_au0t = ((real32_T)Lat_oc_rls_variance_offset_init) * 3.05175781E-5F;

    /* Switch: '<S121>/Switch1' incorporates:
     *  UnitDelay: '<S121>/P_0'
     */
    if ((int32_T)rtb_n5rr) {
    } else {
      rtb_au0t = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)3];
    }

    /* Switch: '<S127>/Switch4' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if ((int32_T)rtb_ffgm) {
      rtb_jcpi = rtb_o53h;
    } else {
      rtb_jcpi = 0.0F;
    }

    /* End of Switch: '<S127>/Switch4' */

    /* Logic: '<S127>/Logical Operator' */
    rtb_ffgm = (boolean_T)((int32_T)(((int32_T)rtb_ffgm) && ((int32_T)rtb_ayh2)));

    /* Switch: '<S127>/Switch3' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if ((int32_T)rtb_ffgm) {
      rtb_cph1 = rtb_kacn;
    } else {
      rtb_cph1 = 0.0F;
    }

    /* End of Switch: '<S127>/Switch3' */

    /* Switch: '<S127>/Switch5' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if ((int32_T)rtb_ffgm) {
      rtb_c0ms = rtb_hsjc;
    } else {
      rtb_c0ms = 0.0F;
    }

    /* End of Switch: '<S127>/Switch5' */

    /* Switch: '<S127>/Switch6' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if ((int32_T)rtb_ayh2) {
      rtb_gpno = rtb_au0t;
    } else {
      rtb_gpno = 0.0F;
    }

    /* End of Switch: '<S127>/Switch6' */

    /* SignalConversion: '<S121>/TmpSignal ConversionAtProductInport1' */
    rtb_lowb = rtb_jcpi;
    rtb_ljyp = rtb_gpno;

    /* Product: '<S121>/Product' incorporates:
     *  SignalConversion: '<S121>/TmpSignal ConversionAtProductInport1'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] +=
      rtb_jcpi * rtb_jrck;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] +=
      rtb_c0ms * rtb_gvqf;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] +=
      rtb_cph1 * rtb_jrck;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] +=
      rtb_gpno * rtb_gvqf;

    /* Sum: '<S121>/Sum' incorporates:
     *  Product: '<S121>/Product1'
     */
    rtb_gpno = ((rtb_jrck *
                 DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)
                 0]) + (rtb_gvqf *
                        DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3
                        [(int8_T)1])) + rtb_ltjz;

    /* Switch: '<S131>/Switch1' incorporates:
     *  RelationalOperator: '<S131>/Relational Operator1'
     */
    if (rtb_gpno > 0.0F) {
      rtb_jcpi = 1.0F;
    } else {
      rtb_jcpi = -1.0F;
    }

    /* End of Switch: '<S131>/Switch1' */

    /* Switch: '<S125>/Switch' incorporates:
     *  Abs: '<S125>/Abs'
     *  Constant: '<S125>/Constant1'
     *  Product: '<S125>/Product5'
     *  RelationalOperator: '<S125>/Relational Operator'
     */
    if (((real32_T)fabs((real_T)rtb_gpno)) <= 0.01F) {
      rtb_gpno = rtb_jcpi * 0.01F;
    }

    /* End of Switch: '<S125>/Switch' */

    /* Product: '<S121>/Divide' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] /=
      rtb_gpno;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] /=
      rtb_gpno;

    /* Product: '<S121>/Product2' incorporates:
     *  Product: '<S121>/Product3'
     */
    rtb_gpno = DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0]
      * rtb_jrck;
    rtb_ltjz = DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0]
      * rtb_gvqf;
    rtb_jrck *= DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)
      1];
    rtb_nrby = DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1]
      * rtb_gvqf;

    /* Product: '<S121>/Divide1' incorporates:
     *  Product: '<S121>/Product3'
     *  SignalConversion: '<S121>/TmpSignal ConversionAtProductInport1'
     *  Sum: '<S121>/Sum1'
     */
    rtb_o53h = (rtb_o53h - ((rtb_gpno * rtb_lowb) + (rtb_ltjz * rtb_cph1))) /
      rtb_bwu1;
    rtb_jcpi = (rtb_hsjc - ((rtb_gpno * rtb_c0ms) + (rtb_ltjz * rtb_ljyp))) /
      rtb_bwu1;
    rtb_ltjz = (rtb_kacn - ((rtb_jrck * rtb_lowb) + (rtb_nrby * rtb_cph1))) /
      rtb_bwu1;
    rtb_gpno = (rtb_au0t - ((rtb_jrck * rtb_c0ms) + (rtb_nrby * rtb_ljyp))) /
      rtb_bwu1;

    /* Product: '<S121>/Divide2' incorporates:
     *  Math: '<S121>/Math Function'
     *  Sum: '<S121>/Sum4'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)0] = (rtb_o53h +
      rtb_o53h) / 2.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)1] = (rtb_ltjz +
      rtb_jcpi) / 2.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)2] = (rtb_jcpi +
      rtb_ltjz) / 2.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)3] = (rtb_gpno +
      rtb_gpno) / 2.0F;

    /* Product: '<S121>/Divide3' incorporates:
     *  Constant: '<S121>/Constant1'
     */
    rtb_ilfo = 1.0F / rtb_ilfo;

    /* Switch: '<S121>/Switch' incorporates:
     *  Constant: '<S121>/Lat_oc_rls_offset_init'
     *  DataTypeConversion: '<S121>/Data Type Conversion5'
     */
    if ((int32_T)rtb_n5rr) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)0] =
        rtb_ilfo;
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)1] =
        ((real32_T)Lat_oc_rls_offset_init) * 0.0009765625F;
    }

    /* End of Switch: '<S121>/Switch' */

    /* Sum: '<S139>/Add' incorporates:
     *  Constant: '<S118>/Lat_oc_rls_input_filter_coeff'
     *  DataTypeConversion: '<S118>/Data Type Conversion4'
     *  Product: '<S10>/Product'
     *  Product: '<S139>/Product'
     *  Sum: '<S118>/Add'
     *  Sum: '<S139>/Add1'
     *  UnitDelay: '<S139>/Unit Delay'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_fins +=
      ((((*rt_f3r3I) * (*rt_popsI)) - rtb_flap) -
       DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_fins) *
      (((real32_T)Lat_oc_rls_input_filter_coeff) * 3.05175781E-5F);

    /* Sum: '<S121>/Sum2' incorporates:
     *  Product: '<S121>/Product4'
     *  Reshape: '<S121>/Reshape1'
     */
    rtb_gpno = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_fins -
      ((DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h *
        DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)0]) +
       (-DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)1]));

    /* Sum: '<S121>/Sum3' incorporates:
     *  Product: '<S121>/Product5'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] =
      (DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] *
       rtb_gpno) + DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE
      [(int8_T)0];
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] =
      (DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] *
       rtb_gpno) + DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE
      [(int8_T)1];

    /* Constant: '<S118>/LAT_Oc_Rls_Downsample' */
    rtb_gpno = (real32_T)Lat_oc_rls_downsample;

    /* Switch: '<S142>/Switch1' incorporates:
     *  Constant: '<S118>/LAT_Oc_Rls_Downsample'
     *  Constant: '<S142>/Constant2'
     *  Constant: '<S142>/Constant3'
     *  Constant: '<S142>/Constant4'
     *  RelationalOperator: '<S142>/Relational Operator1'
     */
    if (((real32_T)Lat_oc_rls_downsample) > 0.0F) {
      rtb_c0ms = 1.0F;
    } else {
      rtb_c0ms = -1.0F;
    }

    /* End of Switch: '<S142>/Switch1' */

    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S118>/LAT_Oc_Rls_Downsample'
     *  Constant: '<S137>/Constant'
     *  Constant: '<S137>/Constant1'
     *  Product: '<S137>/Product5'
     *  RelationalOperator: '<S137>/Relational Operator'
     */
    if (((real32_T)Lat_oc_rls_downsample) <= 0.01F) {
      rtb_gpno = rtb_c0ms * 0.01F;
    }

    /* End of Switch: '<S137>/Switch' */

    /* Product: '<S118>/Divide' incorporates:
     *  Sum: '<S118>/Add1'
     *  UnitDelay: '<S118>/Unit Delay1'
     */
    rtb_gpno = ((DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hxh1
                 - rtb_flap) / rtb_gpno) / 0.01F;

    /* Abs: '<S117>/Abs3' */
    rtb_gpno = (real32_T)fabs((real_T)rtb_gpno);

    /* Constant: '<S132>/LAT_Oc_Rls_Downsample' */
    rtb_c0ms = (real32_T)Lat_oc_rls_downsample;

    /* Switch: '<S135>/Switch1' incorporates:
     *  Constant: '<S132>/LAT_Oc_Rls_Downsample'
     *  Constant: '<S135>/Constant2'
     *  Constant: '<S135>/Constant3'
     *  Constant: '<S135>/Constant4'
     *  RelationalOperator: '<S135>/Relational Operator1'
     */
    if (((real32_T)Lat_oc_rls_downsample) > 0.0F) {
      rtb_cph1 = 1.0F;
    } else {
      rtb_cph1 = -1.0F;
    }

    /* End of Switch: '<S135>/Switch1' */

    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S132>/LAT_Oc_Rls_Downsample'
     *  Constant: '<S133>/Constant'
     *  Constant: '<S133>/Constant1'
     *  Product: '<S133>/Product5'
     *  RelationalOperator: '<S133>/Relational Operator'
     */
    if (((real32_T)Lat_oc_rls_downsample) <= 0.01F) {
      rtb_c0ms = rtb_cph1 * 0.01F;
    }

    /* End of Switch: '<S133>/Switch' */

    /* RelationalOperator: '<S132>/Relational Operator' incorporates:
     *  Constant: '<S132>/Constant2'
     *  Sum: '<S132>/Sum2'
     *  UnitDelay: '<S132>/Unit Delay2'
     */
    rtb_ayh2 = (boolean_T)((int32_T)((rtb_gpno -
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_nzoi) >= 0.0F));

    /* RelationalOperator: '<S132>/Relational Operator1' incorporates:
     *  Constant: '<S132>/Lat_oc_rls_max_holding_time'
     *  DataTypeConversion: '<S132>/Data Type Conversion6'
     *  Product: '<S132>/Divide'
     *  UnitDelay: '<S132>/Unit Delay1'
     */
    rtb_ffgm = (boolean_T)((int32_T)
      (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_bedr >=
       (((((real32_T)Lat_oc_rls_max_holding_time) * 0.0009765625F) / rtb_c0ms) /
        0.01F)));

    /* Switch: '<S132>/Switch' incorporates:
     *  Logic: '<S132>/Logical Operator2'
     */
    if (((int32_T)rtb_ayh2) || ((int32_T)rtb_ffgm)) {
      /* Update for UnitDelay: '<S132>/Unit Delay2' */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_nzoi = rtb_gpno;
    }

    /* End of Switch: '<S132>/Switch' */

    /* Switch: '<S132>/Switch1' incorporates:
     *  Logic: '<S132>/Logical Operator1'
     */
    if (((int32_T)rtb_ayh2) || ((int32_T)rtb_ffgm)) {
      /* Update for UnitDelay: '<S132>/Unit Delay1' incorporates:
       *  Constant: '<S132>/Constant1'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_bedr = 0.0F;
    } else {
      /* Update for UnitDelay: '<S132>/Unit Delay1' incorporates:
       *  Constant: '<S132>/Constant'
       *  Sum: '<S132>/Sum'
       *  UnitDelay: '<S132>/Unit Delay1'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_bedr++;
    }

    /* End of Switch: '<S132>/Switch1' */

    /* Switch: '<S145>/Switch1' incorporates:
     *  RelationalOperator: '<S145>/Relational Operator1'
     */
    if (DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0] >
        0.0F) {
      rtb_c0ms = 1.0F;
    } else {
      rtb_c0ms = -1.0F;
    }

    /* End of Switch: '<S145>/Switch1' */

    /* Switch: '<S144>/Switch' incorporates:
     *  Abs: '<S144>/Abs'
     *  Constant: '<S144>/Constant1'
     *  Product: '<S144>/Product5'
     *  RelationalOperator: '<S144>/Relational Operator'
     */
    if (((real32_T)fabs((real_T)
                        DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3
                        [(int8_T)0])) <= 0.01F) {
      rtb_gpno = rtb_c0ms * 0.01F;
    } else {
      rtb_gpno = DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)
        0];
    }

    /* End of Switch: '<S144>/Switch' */

    /* DataTypeConversion: '<S119>/Data Type Conversion1' */
    LAT_Oc_Rls_Delta_L_Offset_Raw_dbg = (int16_T)((real32_T)floor
      (DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[1] / 0.001526F));

    /* Product: '<S119>/Divide' */
    rtb_gpno = 1.0F / rtb_gpno;

    /* DataTypeConversion: '<S119>/Data Type Conversion4' */
    LAT_Oc_Rls_stiffness_dbg = (int16_T)((real32_T)floor(rtb_gpno / 0.001526F));

    /* DataTypeConversion: '<S119>/Data Type Conversion5' */
    LAT_Oc_Rls_variance_stiffnes_dbg = (uint16_T)((real32_T)
      (DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[0] * 32768.0F));

    /* DataTypeConversion: '<S119>/Data Type Conversion6' */
    LAT_Oc_Rls_cov_stiffnes_offs_dbg = (uint16_T)((real32_T)
      (DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[1] * 32768.0F));

    /* DataTypeConversion: '<S119>/Data Type Conversion7' */
    LAT_Oc_Rls_variance_offset_dbg = (uint16_T)((real32_T)
      (DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[3] * 32768.0F));

    /* Update for UnitDelay: '<S126>/Unit Delay' incorporates:
     *  Constant: '<S126>/Lat_oc_rls_reset'
     *  DataTypeConversion: '<S126>/Data Type Conversion6'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ew4c = ((real32_T)
      Lat_oc_rls_reset) * 0.0009765625F;

    /* Update for UnitDelay: '<S121>/P_0' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)0] =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)0];
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)1] =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)1];
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)2] =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)2];
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[(int8_T)3] =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)3];

    /* Update for UnitDelay: '<S121>/Theta_0' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)0] =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)0];
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[(int8_T)1] =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1];

    /* Update for UnitDelay: '<S118>/Unit Delay1' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hxh1 = rtb_flap;
  }

  DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState.LAT_Oc_Rls_Trig_ZCE =
    (uint8_T)((int32_T)(rtb_gi5c ? ((int32_T)((uint8_T)POS_ZCSIG)) : ((int32_T)
                ((uint8_T)ZERO_ZCSIG))));

  /* End of Outputs for SubSystem: '<S10>/LAT_Oc_Rls' */

  /* Switch: '<S82>/Switch' incorporates:
   *  Abs: '<S82>/Abs'
   *  Constant: '<S82>/Constant'
   *  RelationalOperator: '<S82>/Relational Operator'
   */
  if (((real32_T)fabs((real_T)(*rt_popsI))) <= 0.01F) {
    rtb_nrby = 0.01F;
  } else {
    rtb_nrby = *rt_popsI;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Product: '<S10>/Divide1' */
  rtb_c0ms = DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] /
    rtb_nrby;

  /* Outputs for Atomic SubSystem: '<Root>/LAT_Oc_I_Part_Reset1' */
  /* Lookup_n-D: '<S9>/Steer_Angle_offset//Delta_ys' incorporates:
   *  Gain: '<S9>/Gain'
   */
  rtb_gvqf = look1_iflf_binlc(3.6F * (*rt_ezusI),
    DMC_Lat_LAT_Delta_F_Offset_Switch_ConstP.Steer_Angle_offsetDelta_ys_bp01Data,
    DMC_Lat_LAT_Delta_F_Offset_Switch_ConstP.Steer_Angle_offsetDelta_ys_tableData,
    8U);

  /* Product: '<S9>/Product1' */
  rtb_gvqf *= DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide;

  /* Outputs for Atomic SubSystem: '<S9>/Detect_DMC_Settlement' */
  /* Abs: '<S80>/Abs' */
  rtb_gpno = (real32_T)fabs((real_T)(*rt_gyqsI));

  /* Switch: '<S80>/Switch' incorporates:
   *  Constant: '<S80>/Dmc_Settled'
   *  Constant: '<S80>/Dmc_settled_det_threshold'
   *  Constant: '<S80>/Dmc_unsettled_det_threshold'
   *  Constant: '<S81>/Constant'
   *  Logic: '<S80>/Logical Operator'
   *  Logic: '<S80>/Logical Operator1'
   *  RelationalOperator: '<S80>/Relational Operator'
   *  RelationalOperator: '<S80>/Relational Operator2'
   *  RelationalOperator: '<S81>/Compare'
   *  UnitDelay: '<S80>/Unit Delay'
   */
  if ((rtb_gpno < 0.1F) || ((rtb_gpno <= 0.2F) && (((int32_T)
         DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l1fh) ==
        ((int32_T)0)))) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l1fh = 1U;
  }

  /* End of Switch: '<S80>/Switch' */

  /* Switch: '<S80>/Switch1' incorporates:
   *  Constant: '<S80>/Dmc_Unsettled'
   *  Constant: '<S80>/Dmc_unsettled_det_threshold'
   *  RelationalOperator: '<S80>/Relational Operator1'
   */
  if (rtb_gpno > 0.2F) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l1fh = 2U;
  }

  /* End of Switch: '<S80>/Switch1' */
  /* End of Outputs for SubSystem: '<S9>/Detect_DMC_Settlement' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   *  Sum: '<S9>/Add'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  if ((int32_T)(*rt_erh2I)) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jbdz++;
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jbdz = (uint16_T)0U;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Outputs for Atomic SubSystem: '<S9>/Detect_DMC_Settlement' */
  /* Logic: '<S9>/Logical Operator' incorporates:
   *  Constant: '<S80>/Dmc_Unsettled'
   *  Constant: '<S9>/OffsetChangeInCorrectDirection'
   *  RelationalOperator: '<S80>/Relational Operator3'
   *  RelationalOperator: '<S9>/Relational Operator1'
   *  RelationalOperator: '<S9>/Relational Operator2'
   */
  rtb_ayh2 = (boolean_T)((int32_T)(((((int32_T)
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jbdz) < ((int32_T)
    500)) && (((int32_T)rtb_p4gi) == ((int32_T)2))) && (((int32_T)2) ==
    ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l1fh))));

  /* End of Outputs for SubSystem: '<S9>/Detect_DMC_Settlement' */

  /* Logic: '<S9>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S9>/OffsetChangeInCorrectDirection1'
   *  Constant: '<S9>/OffsetChangeInWrongDirection'
   *  Logic: '<S9>/Logical Operator1'
   *  RelationalOperator: '<S78>/Compare'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S9>/Relational Operator3'
   *  RelationalOperator: '<S9>/Relational Operator4'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator1'
   */
  rtb_odcj = (boolean_T)((int32_T)((((((int32_T)rtb_p4gi) == ((int32_T)2)) ||
                            (((int32_T)rtb_p4gi) == ((int32_T)3))) &&
    (((*rt_cpaoI) & 4194304U) != ((uint32_T)0U))) && ((((int32_T)
    Dmc_configuration_mode_2) & ((int32_T)1024)) != ((int32_T)0))));

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S77>/Constant'
   *  RelationalOperator: '<S77>/Compare'
   *  RelationalOperator: '<S9>/Relational Operator5'
   *  RelationalOperator: '<S9>/Relational Operator6'
   */
  if (rtb_gvqf >= 0.0F) {
    rtb_egra = (boolean_T)((int32_T)((*rt_e4hoI) > rtb_gvqf));
  } else {
    rtb_egra = (boolean_T)((int32_T)((*rt_e4hoI) < rtb_gvqf));
  }

  /* End of Switch: '<S9>/Switch3' */

  /* Switch: '<S9>/Switch4' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Sum: '<S9>/Add1'
   */
  if ((int32_T)rtb_egra) {
    rtb_jrck = (*rt_e4hoI) - rtb_gvqf;
  } else {
    rtb_jrck = 0.0F;
  }

  if ((int32_T)rtb_egra) {
  } else {
    rtb_gvqf = *rt_e4hoI;
  }

  /* End of Switch: '<S9>/Switch4' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Product: '<S9>/Product'
   */
  rtb_kacn = rtb_jrck;
  if ((int32_T)rtb_ayh2) {
  } else {
    rtb_kacn = rtb_k10u;
  }

  rtb_jrck = rtb_kacn;
  rtb_kacn = rtb_gvqf;
  if ((int32_T)rtb_ayh2) {
  } else {
    rtb_kacn = *rt_e4hoI;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if ((int32_T)rtb_odcj) {
  } else {
    rtb_jrck = 0.0F;
  }

  if ((int32_T)rtb_odcj) {
  } else {
    rtb_kacn = *rt_e4hoI;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* MinMax: '<S9>/MinMax' */
  if (((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jbdz) <=
      ((int32_T)500)) {
  } else {
    /* Update for UnitDelay: '<S9>/Unit Delay' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jbdz = 500U;
  }

  /* End of MinMax: '<S9>/MinMax' */
  /* End of Outputs for SubSystem: '<Root>/LAT_Oc_I_Part_Reset1' */

  /* UnitDelay: '<S20>/Latching_VDY_Offset' */
  rtb_ljyp = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Latching_VDY_Offset_DSTATE;

  /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Gain: '<S20>/Gain1'
   *  MinMax: '<S20>/MinMax1'
   *  Sum: '<S20>/Add'
   *  Sum: '<S20>/Add4'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  switch ((int32_T)tmp_) {
   case 1:
    rtb_ljyp = rtb_nyue;
    break;

   case 2:
    rtb_ljyp = 0.0F;
    break;

   case 3:
    rtb_ljyp = rtb_cxqu;
    break;

   case 4:
    rtb_ljyp = -rtb_c0ms;
    break;

   case 5:
    rtb_ljyp = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE -
      rtb_c0ms;
    break;

   case 6:
    rtb_ljyp = rtb_nyue - rtb_jrck;
    break;
  }

  /* End of MultiPortSwitch: '<S20>/Multiport Switch' */

  /* MinMax: '<S27>/MinMax' incorporates:
   *  Constant: '<S27>/Lat_oc_minimum_latency'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  if (((real32_T)Lat_oc_minimum_latency) <=
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE) {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = (real32_T)
      Lat_oc_minimum_latency;
  }

  /* End of MinMax: '<S27>/MinMax' */

  /* MinMax: '<S28>/MinMax' incorporates:
   *  Constant: '<S28>/Lat_oc_minimum_latency_shrt'
   *  UnitDelay: '<S28>/Unit Delay'
   */
  if (((real32_T)Lat_oc_minimum_latency_shrt) <=
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp) {
    /* MinMax: '<S34>/MinMax2' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = (real32_T)
      Lat_oc_minimum_latency_shrt;
  }

  /* End of MinMax: '<S28>/MinMax' */

  /* Logic: '<S17>/Logical Operator11' incorporates:
   *  Abs: '<S24>/Abs'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S24>/Lat_oc_max_delta_psi'
   *  Product: '<S17>/Product'
   *  RelationalOperator: '<S17>/Relational Operator1'
   *  RelationalOperator: '<S24>/Relational Operator'
   */
  rtb_egra = (boolean_T)((int32_T)((((*rt_m2jwI) * (*rt_gyqsI)) < 0.0F) ||
    (((real_T)((real32_T)fabs((real_T)(*rt_mcq4I)))) > (((real_T)
    Lat_oc_max_delta_psi) * 3.0517578125E-5))));

  /* Logic: '<S17>/Logical Operator12' incorporates:
   *  Constant: '<S17>/Constant2'
   *  RelationalOperator: '<S17>/Relational Operator4'
   */
  rtb_gi5c = (boolean_T)((int32_T)(((int32_T)(*rt_p2o1I)) || ((*rt_jus1I) <
    0.95F)));

  /* Logic: '<S17>/Logical Operator5' */
  rtb_n5rr = (boolean_T)((int32_T)(((int32_T)rtb_egra) && ((int32_T)rtb_gi5c)));

  /* Constant: '<S25>/Lat_oc_const_trq_cnt_max_limit' */
  rtb_nlel = (real_T)Lat_oc_const_trq_cnt_max_limit;

  /* MinMax: '<S25>/MinMax' incorporates:
   *  Constant: '<S25>/Lat_oc_const_trq_cnt_max_limit'
   *  UnitDelay: '<S25>/Unit Delay5'
   */
  if (((real_T)Lat_oc_const_trq_cnt_max_limit) <=
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE) {
  } else {
    rtb_nlel = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE;
  }

  /* End of MinMax: '<S25>/MinMax' */

  /* MinMax: '<S25>/MinMax1' */
  if (rtb_nlel >= 0.0) {
    rtb_ozkw = rtb_nlel;
  } else {
    rtb_ozkw = 0.0;
  }

  /* End of MinMax: '<S25>/MinMax1' */

  /* Logic: '<S17>/Logical Operator8' incorporates:
   *  Constant: '<S25>/Lat_oc_const_trq_cnt_threshold'
   *  Logic: '<S17>/Logical Operator9'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  rtb_ffgm = (boolean_T)((int32_T)((!rtb_gi5c) && (rtb_ozkw > ((real_T)
    Lat_oc_const_trq_cnt_threshold))));

  /* Logic: '<S31>/Not Operator' incorporates:
   *  Constant: '<S27>/Lat_oc_minimum_latency'
   *  Constant: '<S28>/Lat_oc_minimum_latency_shrt'
   *  Logic: '<S31>/Or Operator'
   *  RelationalOperator: '<S27>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator'
   */
  rtb_gkjv = (boolean_T)((int32_T)(!((((((real32_T)Lat_oc_minimum_latency) !=
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE) || (((real32_T)
    Lat_oc_minimum_latency_shrt) !=
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp)) || ((int32_T)
    rtb_n5rr)) || ((int32_T)rtb_ffgm))));

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S20>/Lat_oc_max_delta_offset'
   *  Constant: '<S20>/Lat_oc_max_delta_offset_kappa'
   */
  if ((int32_T)rtb_gkjv) {
    rtb_cv5n = Lat_oc_max_delta_offset;
  } else {
    rtb_cv5n = Lat_oc_max_delta_offset_kappa;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* DataTypeConversion: '<S20>/Data Type Conversion' */
  rtb_c0ms = ((real32_T)rtb_cv5n) * 0.0009765625F;

  /* MinMax: '<S49>/MinMax1' */
  if (rtb_ljyp <= rtb_c0ms) {
  } else {
    rtb_ljyp = rtb_c0ms;
  }

  /* End of MinMax: '<S49>/MinMax1' */

  /* Gain: '<S20>/Gain' */
  rtb_c0ms = -rtb_c0ms;

  /* MinMax: '<S49>/MinMax2' */
  if (rtb_ljyp >= rtb_c0ms) {
  } else {
    rtb_ljyp = rtb_c0ms;
  }

  /* End of MinMax: '<S49>/MinMax2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  LAT_Filtered_Delta_F_Offset_dbg = (int16_T)((real32_T)floor(rtb_ljyp /
    0.001526F));

  /* RelationalOperator: '<S64>/Relational Operator' incorporates:
   *  Abs: '<S64>/Abs'
   *  Constant: '<S64>/Lat_oc_min_velocity'
   *  Gain: '<S64>/Gain'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  rtb_fd04 = (boolean_T)((int32_T)(((real_T)((real32_T)fabs((real_T)((real32_T)
    (3.6F * DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE))))) >
    (((real_T)Lat_oc_min_velocity) * 0.015625)));

  /* RelationalOperator: '<S61>/Relational Operator' incorporates:
   *  Abs: '<S61>/Abs'
   *  Constant: '<S61>/Lat_oc_max_velocity'
   *  Gain: '<S61>/Gain'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  rtb_jmzk = (boolean_T)((int32_T)(((real_T)((real32_T)fabs((real_T)((real32_T)
    (3.6F * DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE))))) <
    (((real_T)Lat_oc_max_velocity) * 0.015625)));

  /* Sum: '<S68>/Add' incorporates:
   *  Constant: '<S68>/Lat_oc_kappa_cmd_filter_coeff'
   *  Product: '<S68>/Product'
   *  Sum: '<S68>/Sub'
   *  UnitDelay: '<S68>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kb3q +=
    (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb -
     DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kb3q) *
    (((real32_T)Lat_oc_kappa_cmd_filter_coeff) * 3.05175781E-5F);

  /* RelationalOperator: '<S60>/Relational Operator' incorporates:
   *  Abs: '<S60>/Abs'
   *  Constant: '<S60>/Lat_oc_max_lateral_accel'
   *  Product: '<S60>/Product1'
   *  Product: '<S60>/Product2'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  rtb_dohp = (boolean_T)((int32_T)(((real_T)((real32_T)
    ((DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE *
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE) * ((real32_T)
    fabs((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kb3q)))))
    < (((real_T)Lat_oc_max_lateral_accel) * 0.0009765625)));

  /* Sum: '<S67>/Add' incorporates:
   *  Constant: '<S67>/Lat_oc_kappa_cmd_filter_coeff'
   *  Product: '<S67>/Product'
   *  Sum: '<S67>/Sub'
   *  UnitDelay: '<S67>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  *rt_gd42sI = ((DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb -
                 DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_hb45) *
                (((real32_T)Lat_oc_kappa_cmd_filter_coeff) * 3.05175781E-5F)) +
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_hb45;

  /* Abs: '<S56>/Abs' */
  rtb_lowb = (real32_T)fabs((real_T)(*rt_gd42sI));

  /* RelationalOperator: '<S56>/Relational Operator' incorporates:
   *  Constant: '<S56>/Lat_oc_max_kappa'
   */
  rtb_j344 = (boolean_T)((int32_T)(((real_T)rtb_lowb) < (((real_T)
    Lat_oc_max_kappa) * 2.0E-5)));

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  if ((int32_T)(*rt_erh2I)) {
    rtb_lowb = 0.0F;
  } else {
    rtb_lowb = 1.0F;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Abs: '<S17>/Absolute' */
  rtb_jrck = (real32_T)fabs((real_T)(*rt_m2jwI));

  /* Logic: '<S17>/Logical Operator3' incorporates:
   *  Constant: '<S17>/Lat_oc_max_driver_torque'
   *  RelationalOperator: '<S17>/Relational Operator'
   */
  rtb_fc3o = (boolean_T)((int32_T)(!(((real_T)rtb_jrck) < (((real_T)
    Lat_oc_max_driver_torque) * 0.0009765625))));

  /* Logic: '<S17>/Logical Operator4' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Logic: '<S17>/Logical Operator1'
   *  Logic: '<S17>/Logical Operator2'
   *  S-Function (sfix_bitop): '<S17>/Bitwise Operator'
   */
  rtb_eczq = (boolean_T)((int32_T)(((!(rtb_lowb != 0.0F)) || ((((int32_T)
    Dmc_configuration_mode) & ((int32_T)128)) != ((int32_T)0))) || ((int32_T)
    rtb_fc3o)));

  /* RelationalOperator: '<S57>/Relational Operator' incorporates:
   *  Abs: '<S57>/Abs'
   *  Constant: '<S57>/Lat_oc_max_delta_f_dot'
   *  UnitDelay: '<Root>/Unit Delay2'
   */
  rtb_fxjo = (boolean_T)((int32_T)(((real_T)((real32_T)fabs((real_T)
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_cct5))) <
    (((real_T)Lat_oc_max_delta_f_dot) * 0.0009765625)));

  /* RelationalOperator: '<S63>/Relational Operator' incorporates:
   *  Constant: '<S63>/Lat_oc_min_kappa_quality'
   */
  rtb_met5 = (boolean_T)((int32_T)((*rt_hny3I) >= Lat_oc_min_kappa_quality));

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  rtb_f51a = (boolean_T)((int32_T)((*rt_pdp2I) == ((int16_T)0)));

  /* Logic: '<S22>/Not Operator 1' */
  rtb_lwwu = (boolean_T)((int32_T)(!(*rt_dxdkI)));

  /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
   *  Constant: '<S65>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   */
  rtb_ajkb = (int16_T)(((int16_T)((((int32_T)(*rt_ka1pI)) != ((int32_T)2)) *
    ((int32_T)195U))) << ((int8_T)8));

  /* RelationalOperator: '<S62>/Relational Operator' incorporates:
   *  Constant: '<S62>/Lat_oc_kappa_min_head_err_qual'
   */
  rtb_ckb4 = (boolean_T)((int32_T)(((int32_T)(*rt_eltpI)) >= ((int32_T)
    Lat_oc_kappa_min_head_err_qual)));

  /* RelationalOperator: '<S59>/Relational Operator' incorporates:
   *  Abs: '<S59>/Abs'
   *  Constant: '<S59>/Lat_oc_kappa_max_heading_error'
   *  Gain: '<S59>/Gain'
   */
  rtb_dhrr = (boolean_T)((int32_T)(((real32_T)fabs((real_T)((real32_T)(57.3F * (*
    rt_kaadI))))) < (((real32_T)Lat_oc_kappa_max_heading_error) * 0.00390625F)));

  /* MinMax: '<S66>/MinMax' incorporates:
   *  Constant: '<S55>/Lat_oc_kappa_min_latency'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  if (((real32_T)Lat_oc_kappa_min_latency) <=
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = (real32_T)
      Lat_oc_kappa_min_latency;
  }

  /* End of MinMax: '<S66>/MinMax' */

  /* RelationalOperator: '<S66>/Relational Operator2' incorporates:
   *  Constant: '<S55>/Lat_oc_kappa_min_latency'
   */
  rtb_gcmg = (boolean_T)((int32_T)(((real32_T)Lat_oc_kappa_min_latency) <=
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu));

  /* RelationalOperator: '<S58>/Relational Operator' incorporates:
   *  Abs: '<S58>/Abs'
   *  Constant: '<S58>/Lat_oc_kappa_max_driver_torque'
   */
  rtb_la0n = (boolean_T)((int32_T)(((real_T)((real32_T)fabs((real_T)(*rt_m2jwI))))
    < (((real_T)Lat_oc_kappa_max_driver_torque) * 0.0009765625)));

  /* Logic: '<S22>/Not Operator 2' */
  rtb_anu3 = (boolean_T)((int32_T)(!(*rt_pdncI)));

  /* Logic: '<S22>/Logical Operator' */
  rtb_m1bl = (boolean_T)((int32_T)((((((((((((((((int32_T)rtb_fd04) && ((int32_T)
    rtb_jmzk)) && ((int32_T)rtb_dohp)) && ((int32_T)rtb_j344)) && ((int32_T)
    rtb_eczq)) && ((int32_T)rtb_fxjo)) && ((int32_T)rtb_met5)) && ((int32_T)
    rtb_f51a)) && ((int32_T)rtb_lwwu)) && (rtb_ajkb != ((int16_T)0))) &&
    ((int32_T)rtb_ckb4)) && ((int32_T)rtb_dhrr)) && ((int32_T)rtb_gcmg)) &&
    ((int32_T)rtb_la0n)) && ((int32_T)rtb_anu3)));

  /* Switch: '<S16>/Switch5' incorporates:
   *  Constant: '<S16>/Constant7'
   *  Constant: '<S16>/Lat_oc_calib_cnt_grad'
   *  Gain: '<S16>/Sac_ts'
   *  Logic: '<S16>/Logical Operator'
   */
  if (((int32_T)rtb_gkjv) || ((int32_T)rtb_m1bl)) {
    rtb_ltjz = (((real32_T)Sac_ts) * 3.05175781E-5F) * (((real32_T)
      Lat_oc_calib_cnt_grad) * 0.0009765625F);
  } else {
    rtb_ltjz = 0.0F;
  }

  /* End of Switch: '<S16>/Switch5' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  rtb_o53h = (real32_T)(*rt_prezI);

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S23>/Constant3'
   */
  if ((int32_T)(*rt_pehlI)) {
    rtb_o53h = 0.0F;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Switch: '<S23>/Switch3' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Logic: '<S23>/Logical Operator'
   *  Logic: '<S23>/Logical Operator1'
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  if (((int32_T)(*rt_o3aaI)) &&
      (!DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_dm2g)) {
  } else {
    rtb_o53h = 0.0F;
  }

  /* End of Switch: '<S23>/Switch3' */

  /* Sum: '<S16>/Add5' incorporates:
   *  UnitDelay: '<S16>/Unit Delay5'
   */
  rtb_hsjc = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_lape +
    rtb_o53h;

  /* MinMax: '<S16>/MinMax' */
  if (65000.0F <= rtb_hsjc) {
    rtb_hsjc = 65000.0F;
  }

  /* End of MinMax: '<S16>/MinMax' */

  /* Sum: '<S16>/Add4' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_lape = rtb_ltjz +
    rtb_hsjc;

  /* DataTypeConversion: '<S16>/Data Type Conversion3' */
  *rt_f3r3lI = (uint16_T)rtb_hsjc;

  /* Constant: '<S25>/Lat_oc_const_trq_pos_increment' */
  rtb_nlel = (real_T)Lat_oc_const_trq_pos_increment;

  /* Switch: '<S25>/Switch5' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S17>/Lat_oc_small_driver_torque'
   *  Constant: '<S25>/Constant2'
   *  Logic: '<S17>/Logical Operator10'
   *  Logic: '<S17>/Logical Operator6'
   *  Logic: '<S17>/Logical Operator7'
   *  RelationalOperator: '<S17>/Relational Operator2'
   *  S-Function (sfix_bitop): '<S17>/Bitwise Operator1'
   */
  if (((int32_T)rtb_egra) && ((!((((int32_T)Dmc_configuration_mode) & ((int32_T)
           64)) != ((int32_T)0))) && (((real_T)rtb_jrck) > (((real_T)
          Lat_oc_small_driver_torque) * 0.0009765625)))) {
  } else {
    rtb_nlel = -1.0;
  }

  /* End of Switch: '<S25>/Switch5' */

  /* Switch: '<S26>/Switch1' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S26>/Constant1'
   *  S-Function (sfix_bitop): '<S26>/Bitwise Operator1'
   */
  if ((((int32_T)Dmc_configuration_mode) & 32768) != ((int32_T)0)) {
    rtb_o53h = 0.0F;
  } else {
    rtb_o53h = *rt_e45jI;
  }

  /* End of Switch: '<S26>/Switch1' */

  /* Sum: '<S26>/Add' incorporates:
   *  UnitDelay: '<Root>/Alg loop'
   */
  rtb_jrck = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Algloop_DSTATE - rtb_o53h;

  /* Switch: '<S32>/Switch2' incorporates:
   *  Constant: '<S32>/Constant'
   */
  if ((int32_T)rtb_gkjv) {
    rtb_o53h = *rt_gyqsI;
  } else {
    rtb_o53h = 0.0F;
  }

  /* End of Switch: '<S32>/Switch2' */

  /* Abs: '<S35>/Abs1' */
  rtb_hsjc = (real32_T)fabs((real_T)rtb_o53h);

  /* RelationalOperator: '<S35>/Relational Operator' incorporates:
   *  Constant: '<S33>/Lat_oc_tolerated_delta_ys'
   */
  rtb_ayh2 = (boolean_T)((int32_T)(rtb_hsjc > (((real32_T)
    Lat_oc_tolerated_delta_ys) * 0.0009765625F)));

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Logic: '<S26>/Logical Operator'
   */
  if ((((int32_T)rtb_gkjv) && ((int32_T)rtb_gi5c)) && ((int32_T)rtb_ayh2)) {
  } else {
    rtb_jrck = 0.0F;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S18>/Lat_oc_delta_ki'
   */
  rtb_ltjz = (((real32_T)Lat_oc_delta_ki) * 0.0009765625F) * rtb_jrck;

  /* RelationalOperator: '<S41>/Relational Operator' incorporates:
   *  Abs: '<S41>/Abs'
   *  Constant: '<S41>/Lat_oc_min_velocity_dys'
   *  Gain: '<S41>/Gain'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  *rt_e4ho4I = (boolean_T)((int32_T)(((real_T)((real32_T)fabs((real_T)((real32_T)
                                (3.6F *
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE))))) < (((real_T)
    Lat_oc_min_velocity_dys) * 0.015625)));

  /* Abs: '<S40>/Abs' */
  rtb_jrck = (real32_T)fabs((real_T)(*rt_gd42sI));

  /* Constant: '<S40>/Lat_oc_max_kappa_dys' */
  rtb_gp1m = ((real_T)Lat_oc_max_kappa_dys) * 2.0E-5;

  /* Sum: '<S43>/Add' incorporates:
   *  Constant: '<S43>/Lat_oc_kappa_ffwd_filter_coeff'
   *  Product: '<S43>/Product'
   *  Sum: '<S43>/Sub'
   *  UnitDelay: '<S43>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_odq4 +=
    (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb -
     DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_odq4) *
    (((real32_T)Lat_oc_kappa_ffwd_filter_coeff) * 3.05175781E-5F);

  /* Logic: '<S40>/Logical Operator' incorporates:
   *  Abs: '<S40>/Abs1'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  RelationalOperator: '<S40>/Relational Operator1'
   */
  rtb_egra = (boolean_T)((int32_T)((((real_T)rtb_jrck) > rtb_gp1m) || (rtb_gp1m <
                           ((real_T)((real32_T)fabs((real_T)
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_odq4))))));

  /* Logic: '<S30>/Not Operator' */
  rtb_odcj = (boolean_T)((int32_T)(!(rtb_lowb != 0.0F)));

  /* RelationalOperator: '<S38>/Relational Operator' incorporates:
   *  Abs: '<S38>/Abs'
   *  Constant: '<S38>/Lat_oc_implaus_lateral_error'
   */
  rtb_lo1a = (boolean_T)((int32_T)(((real_T)((real32_T)fabs((real_T)(*rt_gyqsI))))
    > (((real_T)Lat_oc_implaus_lateral_error) * 0.0009765625)));

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S42>/Constant'
   *  Logic: '<S30>/Or Operator'
   *  RelationalOperator: '<S42>/Compare'
   *  S-Function (sfix_bitop): '<S30>/Bitwise Operator'
   *  Sum: '<S27>/Add'
   */
  if (((((((((((int32_T)Dmc_configuration_mode) & ((int32_T)128)) != ((int32_T)0))
            || ((int32_T)(*rt_e4ho4I))) || ((int32_T)rtb_egra)) || ((int32_T)
           rtb_odcj)) || ((int32_T)rtb_lo1a)) || ((int32_T)(*rt_pdncI))) ||
       ((int32_T)(*rt_i3p3I))) || (((int32_T)(*rt_ka1pI)) == ((int32_T)2))) {
    rtb_c0ms = 0.0F;
  } else {
    rtb_c0ms = 1.0F + DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant2'
   *  Logic: '<S28>/Logical Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  Sum: '<S28>/Add'
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  if (((int32_T)rtb_fc3o) || ((*rt_p2o1I) !=
       DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_lv1m)) {
    rtb_au0t = 0.0F;
  } else {
    rtb_au0t = 1.0F +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Abs: '<S32>/Abs' */
  rtb_jrck = (real32_T)fabs((real_T)(*rt_gyqsI));

  /* Logic: '<S32>/Logical Operator' */
  rtb_m1aa = (boolean_T)((int32_T)(((int32_T)rtb_gkjv) && ((int32_T)rtb_gi5c)));

  /* Logic: '<S32>/Logical Operator1' incorporates:
   *  Constant: '<S32>/Lat_oc_max_lateral_error'
   *  Logic: '<S32>/Logical Operator2'
   *  RelationalOperator: '<S32>/Relational Operator'
   */
  rtb_ayh2 = (boolean_T)((int32_T)((rtb_jrck > (((real32_T)
    Lat_oc_max_lateral_error) * 0.0009765625F)) || (((int32_T)rtb_ayh2) &&
    ((int32_T)rtb_m1aa))));

  /* Switch: '<S32>/Switch3' incorporates:
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Lat_oc_ki'
   *  Constant: '<S32>/Lat_oc_min_lateral_error'
   *  Logic: '<S32>/Logical Operator3'
   *  RelationalOperator: '<S32>/Relational Operator1'
   */
  if (((int32_T)rtb_m1aa) && (rtb_jrck < (((real32_T)Lat_oc_min_lateral_error) *
        0.0009765625F))) {
    rtb_jrck = 0.0F;
  } else {
    rtb_jrck = ((real32_T)Lat_oc_ki) * 3.05175781E-5F;
  }

  /* End of Switch: '<S32>/Switch3' */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Lat_oc_fast_ki'
   */
  if ((int32_T)rtb_ayh2) {
    rtb_jrck = ((real32_T)Lat_oc_fast_ki) * 3.05175781E-5F;
  }

  /* End of Switch: '<S32>/Switch' */

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Constant: '<S32>/Lat_oc_max_lateral_error1'
   *  DataTypeConversion: '<S32>/Data Type Conversion3'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = ((real32_T)
    Lat_oc_max_lateral_error) * 0.0009765625F;

  /* MinMax: '<S34>/MinMax' */
  if (rtb_o53h <= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp)
  {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = rtb_o53h;
  } else {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  }

  /* End of MinMax: '<S34>/MinMax' */

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Gain: '<S34>/Gain2'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp =
    -DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE >=
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE;
  }

  /* Product: '<S32>/Product' incorporates:
   *  MinMax: '<S34>/MinMax2'
   */
  rtb_jcpi = rtb_jrck *
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S33>/Lat_oc_tolerated_delta_ys'
   */
  rtb_jrck = rtb_hsjc - (((real32_T)Lat_oc_tolerated_delta_ys) * 0.0009765625F);

  /* MinMax: '<S35>/MinMax' */
  if (0.0F >= rtb_jrck) {
    rtb_jrck = 0.0F;
  }

  /* Signum: '<S35>/Sign1' */
  if (rtb_o53h < 0.0F) {
    tmp_ = -1.0F;
  } else if (rtb_o53h > 0.0F) {
    tmp_ = 1.0F;
  } else {
    tmp_ = rtb_o53h;
  }

  /* Product: '<S35>/Product1' incorporates:
   *  MinMax: '<S35>/MinMax'
   *  Signum: '<S35>/Sign1'
   */
  rtb_hsjc = tmp_ * rtb_jrck;

  /* RelationalOperator: '<S36>/Relational Operator1' incorporates:
   *  Constant: '<S36>/Constant2'
   */
  rtb_ayh2 = (boolean_T)((int32_T)(rtb_hsjc > 0.001F));

  /* Switch: '<S36>/Switch4' incorporates:
   *  Constant: '<S36>/Constant4'
   *  Constant: '<S36>/Constant5'
   *  Constant: '<S36>/Constant6'
   *  RelationalOperator: '<S36>/Relational Operator2'
   */
  if (rtb_hsjc < -0.001F) {
    rtb_hsjc = -1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S36>/Switch4' */

  /* Switch: '<S36>/Switch3' incorporates:
   *  Constant: '<S36>/Constant3'
   */
  if ((int32_T)rtb_ayh2) {
    rtb_hsjc = 1.0F;
  }

  /* End of Switch: '<S36>/Switch3' */

  /* Switch: '<S32>/Switch1' incorporates:
   *  Constant: '<S32>/Constant1'
   *  Gain: '<S32>/Lat_oc_sign_delta_ys_weighting'
   */
  if ((int32_T)rtb_m1aa) {
    rtb_hsjc *= ((real32_T)Lat_oc_sign_delta_ys_weighting) * 3.05175781E-5F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Sum: '<S32>/Add' */
  rtb_gpno = rtb_jcpi + rtb_hsjc;

  /* Sum: '<S32>/Add1' */
  rtb_hsjc += rtb_o53h;

  /* DataTypeConversion: '<S32>/Data Type Conversion' */
  LAT_Oc_Integrator_Input_Raw_dbg = (int16_T)((real32_T)floor(rtb_hsjc / 0.001F));

  /* Switch: '<S37>/Switch1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)(*rt_e4ho4I)) {
    rtb_o53h = 1.0F;
  } else {
    rtb_o53h = 0.0F;
  }

  /* End of Switch: '<S37>/Switch1' */

  /* Switch: '<S37>/Switch2' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)rtb_egra) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Gain: '<S37>/Gain2' */
  rtb_g0pg = (((int32_T)rtb_hsjc) << ((int8_T)1));

  /* Switch: '<S37>/Switch3' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)rtb_odcj) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch3' */

  /* Gain: '<S37>/Gain3' */
  rtb_eryf = (((int32_T)rtb_hsjc) << ((int8_T)2));

  /* Switch: '<S37>/Switch4' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)rtb_lo1a) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch4' */

  /* Gain: '<S37>/Gain4' */
  rtb_ihwv = (((int32_T)rtb_hsjc) << ((int8_T)3));

  /* Switch: '<S37>/Switch5' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)rtb_fc3o) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch5' */

  /* Gain: '<S37>/Gain5' */
  rtb_clet = (((int32_T)rtb_hsjc) << ((int8_T)4));

  /* Switch: '<S37>/Switch6' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)rtb_n5rr) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch6' */

  /* Gain: '<S37>/Gain6' */
  rtb_edjj = (((int32_T)rtb_hsjc) << ((int8_T)5));

  /* Switch: '<S37>/Switch7' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)rtb_ffgm) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch7' */

  /* Gain: '<S37>/Gain7' */
  rtb_mosm = (((int32_T)rtb_hsjc) << ((int8_T)6));

  /* Switch: '<S37>/Switch8' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)(*rt_pdncI)) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch8' */

  /* Gain: '<S37>/Gain8' */
  rtb_girm = (((int32_T)rtb_hsjc) << ((int8_T)7));

  /* Switch: '<S37>/Switch9' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  if ((int32_T)(*rt_hsldI)) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S37>/Switch9' */

  /* Sum: '<S37>/Add' incorporates:
   *  Gain: '<S37>/Gain9'
   */
  rtb_o53h = ((real32_T)((int32_T)(((((((((int32_T)rtb_o53h) + rtb_g0pg) +
    rtb_eryf) + rtb_ihwv) + rtb_clet) + rtb_edjj) + rtb_mosm) + rtb_girm))) +
    (256.0F * rtb_hsjc);

  /* DataTypeConversion: '<S30>/Data Type Conversion' */
  LAT_Oc_Dys_Status_dbg = (int16_T)rtb_o53h;

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Product: '<S21>/Product1'
   *  Sum: '<S21>/Sub1'
   *  Sum: '<S21>/Sub2'
   *  UnitDelay: '<Root>/Unit Delay1'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S7>/Unit Delay'
   *
   * Block requirements for '<S21>/Switch1':
   *  1. Curvature Integrator Input Selection
   */
  if ((int32_T)rtb_m1bl) {
    rtb_o53h = (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_afzy -
                (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb *
                 DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE)) -
      rtb_ljyp;
  } else {
    rtb_o53h = 0.0F;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Constant: '<S21>/Lat_delta_off_flt_initial_omega' */
  rtb_hsjc = ((real32_T)Lat_delta_off_flt_initial_omega) * 3.05175781E-5F;

  /* Switch: '<S21>/Switch2' */
  if ((int32_T)rtb_m1bl) {
    /* MinMax: '<S34>/MinMax2' incorporates:
     *  Constant: '<S21>/Constant2'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = 1.0F;
  } else {
    /* MinMax: '<S34>/MinMax2' incorporates:
     *  Constant: '<S21>/Constant3'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = 0.0F;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Sum: '<S21>/Add2'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp +=
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jlpv;

  /* MinMax: '<S21>/MinMax' incorporates:
   *  Constant: '<S21>/Lat_delta_off_flt_initial_loops'
   */
  if (((real32_T)Lat_delta_off_flt_initial_loops) <=
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jlpv = (real32_T)
      Lat_delta_off_flt_initial_loops;
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jlpv =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  }

  /* End of MinMax: '<S21>/MinMax' */

  /* Switch: '<S21>/Switch3' incorporates:
   *  Constant: '<S21>/Lat_delta_off_flt_initial_loops'
   *  Constant: '<S21>/Lat_delta_offset_filter_omega'
   *  RelationalOperator: '<S21>/Relational Operator'
   *
   * Block requirements for '<S21>/Switch3':
   *  1. Filter Frequency Selection
   */
  if (((real32_T)Lat_delta_off_flt_initial_loops) >
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jlpv) {
  } else {
    rtb_hsjc = ((real32_T)Lat_delta_offset_filter_omega) * 3.05175781E-5F;
  }

  /* End of Switch: '<S21>/Switch3' */

  /* Product: '<S21>/Product2' */
  rtb_hsjc *= rtb_o53h;

  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  Constant: '<S52>/Lat_oc_kappa_max_learning_rate'
   */
  rtb_jrck = ((real32_T)Lat_oc_kappa_max_learning_rate) * 0.0009765625F;

  /* MinMax: '<S52>/MinMax1' */
  if (rtb_hsjc <= rtb_jrck) {
  } else {
    rtb_hsjc = rtb_jrck;
  }

  /* End of MinMax: '<S52>/MinMax1' */

  /* Gain: '<S52>/Gain1' */
  rtb_jrck = -rtb_jrck;

  /* MinMax: '<S52>/MinMax3' */
  if (rtb_hsjc >= rtb_jrck) {
    rtb_jrck = rtb_hsjc;
  }

  /* Sum: '<S20>/Add1' incorporates:
   *  MinMax: '<S52>/MinMax3'
   */
  rtb_ltjz += rtb_gpno + rtb_jrck;

  /* DataTypeConversion: '<S48>/Data Type Conversion' incorporates:
   *  Constant: '<S48>/Lat_oc_max_offset_rate'
   */
  rtb_hsjc = ((real32_T)Lat_oc_max_offset_rate) * 0.0009765625F;

  /* MinMax: '<S48>/MinMax1' */
  if (rtb_ltjz <= rtb_hsjc) {
  } else {
    rtb_ltjz = rtb_hsjc;
  }

  /* End of MinMax: '<S48>/MinMax1' */

  /* Gain: '<S48>/Gain1' */
  rtb_hsjc = -rtb_hsjc;

  /* MinMax: '<S48>/MinMax3' */
  if (rtb_ltjz >= rtb_hsjc) {
    tmp_ = rtb_ltjz;
  } else {
    tmp_ = rtb_hsjc;
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  LAT_Oc_Integrator_Input_Kappa_dbg = (int16_T)((real32_T)floor(rtb_o53h /
    0.001526F));

  /* Switch: '<S54>/Switch1' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_fd04) {
    rtb_o53h = 1.0F;
  } else {
    rtb_o53h = 0.0F;
  }

  /* End of Switch: '<S54>/Switch1' */

  /* Switch: '<S54>/Switch2' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_jmzk) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Gain: '<S54>/Gain2' */
  rtb_g0pg = (((int32_T)rtb_hsjc) << ((int8_T)1));

  /* Switch: '<S54>/Switch3' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_dohp) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch3' */

  /* Gain: '<S54>/Gain3' */
  rtb_eryf = (((int32_T)rtb_hsjc) << ((int8_T)2));

  /* Switch: '<S54>/Switch4' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_j344) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch4' */

  /* Gain: '<S54>/Gain4' */
  rtb_ihwv = (((int32_T)rtb_hsjc) << ((int8_T)3));

  /* Switch: '<S54>/Switch5' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_eczq) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch5' */

  /* Gain: '<S54>/Gain5' */
  rtb_clet = (((int32_T)rtb_hsjc) << ((int8_T)4));

  /* Switch: '<S54>/Switch6' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_fxjo) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch6' */

  /* Gain: '<S54>/Gain6' */
  rtb_edjj = (((int32_T)rtb_hsjc) << ((int8_T)5));

  /* Switch: '<S54>/Switch7' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_met5) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch7' */

  /* Gain: '<S54>/Gain7' */
  rtb_mosm = (((int32_T)rtb_hsjc) << ((int8_T)6));

  /* Switch: '<S54>/Switch8' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_f51a) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch8' */

  /* Gain: '<S54>/Gain8' */
  rtb_girm = (((int32_T)rtb_hsjc) << ((int8_T)7));

  /* Switch: '<S54>/Switch9' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_lwwu) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch9' */

  /* Gain: '<S54>/Gain9' */
  rtb_j0jq = (((int32_T)rtb_hsjc) << ((int8_T)8));

  /* Switch: '<S54>/Switch10' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if (rtb_ajkb != ((int16_T)0)) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch10' */

  /* Gain: '<S54>/Gain10' */
  rtb_nnov = (((int32_T)rtb_hsjc) << ((int8_T)9));

  /* Switch: '<S54>/Switch11' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_ckb4) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch11' */

  /* Gain: '<S54>/Gain11' */
  rtb_njxy = (((int32_T)rtb_hsjc) << ((int8_T)10));

  /* Switch: '<S54>/Switch12' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_dhrr) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch12' */

  /* Gain: '<S54>/Gain12' */
  rtb_mubn = (((int32_T)rtb_hsjc) << ((int8_T)11));

  /* Switch: '<S54>/Switch13' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_gcmg) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch13' */

  /* Gain: '<S54>/Gain13' */
  rtb_bwxv = (((int32_T)rtb_hsjc) << ((int8_T)12));

  /* Switch: '<S54>/Switch15' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_la0n) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch15' */

  /* Gain: '<S54>/Gain14' */
  rtb_gisu = (((int32_T)rtb_hsjc) << ((int8_T)13));

  /* Switch: '<S54>/Switch14' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_anu3) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch14' */

  /* Gain: '<S54>/Gain15' */
  rtb_lrdu = (((int32_T)rtb_hsjc) << ((int8_T)14));

  /* Switch: '<S54>/Switch16' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   */
  if ((int32_T)rtb_m1bl) {
    rtb_hsjc = 1.0F;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S54>/Switch16' */

  /* Sum: '<S54>/Add' incorporates:
   *  Gain: '<S54>/Gain16'
   */
  rtb_o53h = ((real32_T)((int32_T)((((((((((((((((int32_T)rtb_o53h) + rtb_g0pg)
    + rtb_eryf) + rtb_ihwv) + rtb_clet) + rtb_edjj) + rtb_mosm) + rtb_girm) +
    rtb_j0jq) + rtb_nnov) + rtb_njxy) + rtb_mubn) + rtb_bwxv) + rtb_gisu) +
    rtb_lrdu))) + (32768.0F * rtb_hsjc);

  /* DataTypeConversion: '<S22>/Data Type Conversion3' */
  LAT_Oc_Kappa_Status_dbg = (int16_T)rtb_o53h;

  /* Switch: '<S66>/Switch' incorporates:
   *  Abs: '<S55>/Abs'
   *  Constant: '<S55>/Lat_oc_kappa_max_heading_error'
   *  Constant: '<S55>/Lat_oc_kappa_min_head_err_qual'
   *  Constant: '<S66>/Constant1'
   *  Constant: '<S66>/Constant2'
   *  Gain: '<S55>/Gain'
   *  Logic: '<S55>/Logical Operator'
   *  RelationalOperator: '<S55>/Relational Operator1'
   *  RelationalOperator: '<S55>/Relational Operator2'
   *  Sum: '<S66>/Add'
   */
  if ((((real32_T)fabs((real_T)((real32_T)(57.3F * (*rt_kaadI))))) < (((real32_T)
         Lat_oc_kappa_max_heading_error) * 0.00390625F)) && (((int32_T)
        (*rt_eltpI)) >= ((int32_T)Lat_oc_kappa_min_head_err_qual))) {
    rtb_cph1 = 1.0F +
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;
  } else {
    rtb_cph1 = 0.0F;
  }

  /* End of Switch: '<S66>/Switch' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise Operator' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   */
  rtb_cv5n = (uint16_T)((int32_T)(((int32_T)Dmc_configuration_mode) & ((int32_T)
    8)));

  /* Switch: '<S3>/Switch' incorporates:
   *  Sum: '<S3>/Add'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  if (((int32_T)rtb_cv5n) != ((int32_T)0)) {
    rtb_hsjc = rtb_ljyp;
  } else {
    rtb_hsjc = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl +
      rtb_ljyp;
  }

  /* End of Switch: '<S3>/Switch' */

  /* UnitDelay: '<S84>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu =
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l4u2;

  /* S-Function (sfix_bitop): '<S84>/Bitwise Operator' incorporates:
   *  Constant: '<S84>/Constant1'
   *  Constant: '<S84>/Lat_oc_rls_controller_mode'
   */
  rtb_k4uc = (uint16_T)((int32_T)(((int32_T)Lat_oc_rls_controller_mode) &
    ((int32_T)1)));

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S84>/Constant'
   */
  if (((int32_T)rtb_k4uc) != ((int32_T)0)) {
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = 0.0F;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Sum: '<S3>/Add1' incorporates:
   *  Product: '<S10>/Divide'
   */
  rtb_nrby = rtb_hsjc +
    (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu / rtb_nrby);

  /* Switch: '<S4>/Switch5' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Constant: '<S69>/Constant'
   *  RelationalOperator: '<S69>/Compare'
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator'
   */
  if ((((int32_T)Dmc_configuration_mode_2) & ((int32_T)1024)) != ((int32_T)0)) {
    *rt_ngfdoI = rtb_kacn;
  } else {
    *rt_ngfdoI = *rt_e4hoI;
  }

  /* End of Switch: '<S4>/Switch5' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if ((int32_T)rtb_l4st) {
    rtb_hsjc = *rt_ngfdoI;
  } else {
    rtb_hsjc = 0.0F;
  }

  /* End of Switch: '<S4>/Switch' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S12>/Unit Delay'
   */
  Lat_rate_limited_offset_dbg = (int16_T)((real32_T)floor
    (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl / 0.001526F));

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  if (((int32_T)rtb_cv5n) != ((int32_T)0)) {
    rtb_jrck = 0.0F;
  } else {
    rtb_jrck = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S5>/Sub' */
  rtb_kacn = (*rt_gd42I) - rtb_jrck;

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  CAM_Kappa_Cmd_dbg = (int16_T)((real32_T)floor((*rt_kkebI) / 2.0E-5F));

  /* Switch: '<S7>/Switch' */
  if (rtb_lowb != 0.0F) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb = *rt_dmmuI;
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb = *rt_kkebI;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Outputs for Enabled SubSystem: '<S8>/Subsystem' incorporates:
   *  EnablePort: '<S74>/Enable'
   */
  /* Logic: '<S29>/Logical Operator' incorporates:
   *  Logic: '<S29>/Logical Operator1'
   */
  if (((int32_T)rtb_gkjv) && (!rtb_gi5c)) {
    /* Switch: '<S76>/Switch' incorporates:
     *  Constant: '<S74>/Lat_oc_dys_pre_filter_length'
     *  Constant: '<S76>/Constant'
     *  RelationalOperator: '<S76>/Relational Operator'
     */
    if (((real32_T)Lat_oc_dys_pre_filter_length) <= 0.01F) {
      rtb_gpno = 0.01F;
    } else {
      rtb_gpno = (real32_T)Lat_oc_dys_pre_filter_length;
    }

    /* End of Switch: '<S76>/Switch' */

    /* Product: '<S74>/Divide' incorporates:
     *  UnitDelay: '<S74>/Unit Delay'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide_p0as = (1.0F / rtb_gpno) *
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_g2n0;

    /* RelationalOperator: '<S74>/Relational Operator' incorporates:
     *  Constant: '<S74>/Lat_oc_dys_pre_filter_length'
     *  UnitDelay: '<S74>/Unit Delay1'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.RelationalOperator = (boolean_T)
      ((int32_T)(DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_jmfr >
                 ((real32_T)Lat_oc_dys_pre_filter_length)));

    /* Switch: '<S74>/Switch' */
    if ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_B.RelationalOperator) {
      /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
       *  Constant: '<S74>/Constant'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_g2n0 = 0.0F;
    } else {
      /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
       *  Sum: '<S74>/Add'
       *  UnitDelay: '<S74>/Unit Delay'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_g2n0 += *rt_gyqsI;
    }

    /* End of Switch: '<S74>/Switch' */

    /* Switch: '<S74>/Switch1' */
    if ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_B.RelationalOperator) {
      /* Update for UnitDelay: '<S74>/Unit Delay1' incorporates:
       *  Constant: '<S74>/Constant3'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_jmfr = 0.0F;
    } else {
      /* Update for UnitDelay: '<S74>/Unit Delay1' incorporates:
       *  Constant: '<S74>/Constant1'
       *  Sum: '<S74>/Add1'
       *  UnitDelay: '<S74>/Unit Delay1'
       */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_jmfr++;
    }

    /* End of Switch: '<S74>/Switch1' */
  }

  /* End of Logic: '<S29>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S8>/Subsystem' */

  /* Outputs for Triggered SubSystem: '<S8>/LAT_Oc_Delta_Ys_Maf' incorporates:
   *  TriggerPort: '<S73>/Trigger'
   */
  /* Logic: '<S8>/Logical Operator' */
  if (((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_B.RelationalOperator) &&
      (DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState.LAT_Oc_Delta_Ys_Maf_Trig_ZCE
       != POS_ZCSIG)) {
    /* UnitDelay: '<S75>/Unit Delay1' */
    rtb_gpno = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hnso;

    /* UnitDelay: '<S75>/Unit Delay2' */
    rtb_ltjz = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_oylu;

    /* UnitDelay: '<S75>/Unit Delay3' */
    rtb_jcpi = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hwvo;

    /* Gain: '<S75>/Lat_oc_delta_ys_maf_coeff' incorporates:
     *  Sum: '<S75>/Add1'
     *  UnitDelay: '<S75>/Unit Delay1'
     *  UnitDelay: '<S75>/Unit Delay2'
     *  UnitDelay: '<S75>/Unit Delay3'
     *  UnitDelay: '<S75>/Unit Delay4'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Lat_oc_delta_ys_maf_coeff = 0.2F *
      ((((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide_p0as +
          DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hnso) +
         DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_oylu) +
        DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hwvo) +
       DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE);

    /* Update for UnitDelay: '<S75>/Unit Delay1' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hnso =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide_p0as;

    /* Update for UnitDelay: '<S75>/Unit Delay2' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_oylu = rtb_gpno;

    /* Update for UnitDelay: '<S75>/Unit Delay3' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hwvo = rtb_ltjz;

    /* Update for UnitDelay: '<S75>/Unit Delay4' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE = rtb_jcpi;
  }

  DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState.LAT_Oc_Delta_Ys_Maf_Trig_ZCE =
    (uint8_T)((int32_T)(DMC_Lat_LAT_Delta_F_Offset_Switch_B.RelationalOperator ?
                        ((int32_T)((uint8_T)POS_ZCSIG)) : ((int32_T)((uint8_T)
    ZERO_ZCSIG))));

  /* End of Logic: '<S8>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S8>/LAT_Oc_Delta_Ys_Maf' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  LAT_Oc_Delta_Ys_Filtered_dbg = (int16_T)((real32_T)floor
    (DMC_Lat_LAT_Delta_F_Offset_Switch_B.Lat_oc_delta_ys_maf_coeff / 0.001F));

  /* Logic: '<S87>/Logical Operator1' incorporates:
   *  Constant: '<S87>/Constant3'
   *  Constant: '<S87>/Lat_oc_rls_confidence_threshold'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator1'
   */
  rtb_m1aa = (boolean_T)((int32_T)((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape
                           [(int8_T)3] != 0.0F) &&
    (DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)3] <= (((real32_T)
    Lat_oc_rls_confidence_threshold) * 3.05175781E-5F))));

  /* Logic: '<S87>/Logical Operator3' incorporates:
   *  Constant: '<S87>/Lat_oc_rls_reset'
   *  Logic: '<S87>/Logical Operator4'
   *  UnitDelay: '<S87>/Unit Delay3'
   */
  rtb_odcj = (boolean_T)((int32_T)((!(((int32_T)
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_ggbc) != ((int32_T)
    0))) && (((int32_T)Lat_oc_rls_reset) != ((int32_T)0))));

  /* Logic: '<S87>/Logical Operator2' incorporates:
   *  Constant: '<S87>/Constant4'
   *  Constant: '<S87>/Lat_oc_rls_confid_threshold_2'
   *  RelationalOperator: '<S87>/Relational Operator2'
   *  RelationalOperator: '<S87>/Relational Operator3'
   */
  rtb_ayh2 = (boolean_T)((int32_T)((DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape
                           [(int8_T)3] != 0.0F) &&
    (DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)3] <= (((real32_T)
    Lat_oc_rls_confid_threshold_2) * 3.05175781E-5F))));

  /* Switch: '<S10>/Switch1' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion1'
   *  DataTypeConversion: '<S10>/Data Type Conversion4'
   *  Sum: '<S10>/Sum'
   */
  if (((int32_T)rtb_k4uc) != ((int32_T)0)) {
    rtb_k4uc = (uint16_T)((((uint32_T)rtb_m1aa) + ((uint32_T)rtb_ayh2)) +
                          ((uint32_T)2U));
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Switch: '<S10>/Switch' incorporates:
   *  DataTypeConversion: '<S87>/Data Type Conversion6'
   */
  if (((real32_T)rtb_odcj) != 0.0F) {
    rtb_k4uc = (uint16_T)1U;
  }

  /* End of Switch: '<S10>/Switch' */

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  LAT_Oc_Rls_Status_dbg = (int16_T)rtb_k4uc;

  /* DataTypeConversion: '<S10>/Data Type Conversion6' */
  LAT_Oc_Rls_Delta_L_Offst_Lim_dbg = (int16_T)((real32_T)floor
    (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu / 0.001526F));

  /* DataTypeConversion: '<S85>/Data Type Conversion' incorporates:
   *  Constant: '<S85>/Lat_oc_rls_offset_saturation'
   */
  rtb_lowb = ((real32_T)Lat_oc_rls_offset_saturation) * 0.0009765625F;

  /* Gain: '<S85>/Gain' */
  rtb_jrck = -rtb_lowb;

  /* Logic: '<S87>/Logical Operator' incorporates:
   *  UnitDelay: '<S87>/Unit Delay1'
   */
  rtb_lo1a = (boolean_T)((int32_T)
    ((DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_kcdv != 0.0F) ||
     ((int32_T)rtb_ayh2)));

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Constant: '<S239>/Lat_oc_rls_variance_offset_init'
   *  DataTypeConversion: '<S239>/Data Type Conversion1'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = ((real32_T)
    Lat_oc_rls_variance_offset_init) * 3.05175781E-5F;

  /* Sum: '<S239>/Sum1' */
  rtb_ltjz = DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[(int8_T)3] -
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Constant: '<S239>/Lat_oc_rls_confidence_threshold'
   *  DataTypeConversion: '<S239>/Data Type Conversion2'
   *  Sum: '<S239>/Sum3'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp -= ((real32_T)
    Lat_oc_rls_confidence_threshold) * 3.05175781E-5F;

  /* Switch: '<S241>/Switch1' incorporates:
   *  Constant: '<S241>/Constant2'
   *  Constant: '<S241>/Constant3'
   *  Constant: '<S241>/Constant4'
   *  RelationalOperator: '<S241>/Relational Operator1'
   */
  if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp > 0.0F) {
    rtb_gp1m = 1.0;
  } else {
    rtb_gp1m = -1.0;
  }

  /* End of Switch: '<S241>/Switch1' */

  /* Saturate: '<S87>/Saturation' incorporates:
   *  Product: '<S240>/Product5'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = (real32_T)(rtb_gp1m
    * 9.9999997473787516E-5);

  /* Switch: '<S240>/Switch' incorporates:
   *  Abs: '<S240>/Abs'
   *  Constant: '<S240>/Constant'
   *  RelationalOperator: '<S240>/Relational Operator'
   */
  if (((real_T)((real32_T)fabs((real_T)
         DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp))) <=
      0.0001) {
  } else {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  }

  /* End of Switch: '<S240>/Switch' */

  /* Saturate: '<S87>/Saturation' incorporates:
   *  Product: '<S239>/Divide'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = rtb_ltjz /
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE;

  /* Math: '<S239>/Math Function' incorporates:
   *  Constant: '<S239>/Lat_oc_rls_weighting_power'
   *  DataTypeConversion: '<S239>/Data Type Conversion5'
   */
  if ((DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE < 0.0F) &&
      (((real32_T)Lat_oc_rls_weighting_power) > ((real32_T)
        Lat_oc_rls_weighting_power))) {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = -((real32_T)pow
      ((real_T)((real32_T)
                (-DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE)),
       (real_T)Lat_oc_rls_weighting_power));
  } else {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = (real32_T)pow
      ((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE, (real_T)
       Lat_oc_rls_weighting_power);
  }

  /* End of Math: '<S239>/Math Function' */

  /* Saturate: '<S87>/Saturation' incorporates:
   *  Abs: '<S239>/Abs'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = (real32_T)fabs
    ((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE);

  /* Switch: '<S239>/Switch' incorporates:
   *  Constant: '<S239>/Constant1'
   *  Constant: '<S239>/Lat_oc_rls_controller_mode'
   *  S-Function (sfix_bitop): '<S239>/Bitwise Operator'
   */
  if ((((int32_T)Lat_oc_rls_controller_mode) & ((int32_T)32)) > ((int32_T)0)) {
  } else {
    /* Saturate: '<S87>/Saturation' incorporates:
     *  Constant: '<S239>/Constant'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = 0.0F;
  }

  /* End of Switch: '<S239>/Switch' */

  /* Switch: '<S87>/Switch' incorporates:
   *  Saturate: '<S87>/Saturation'
   */
  if ((int32_T)rtb_m1aa) {
    /* MinMax: '<S34>/MinMax2' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1];
  } else {
    if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE > 1.0F) {
      /* Saturate: '<S87>/Saturation' */
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = 1.0F;
    }

    /* MinMax: '<S34>/MinMax2' incorporates:
     *  Product: '<S87>/Product'
     *  Saturate: '<S87>/Saturation'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp =
      DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[(int8_T)1] *
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S87>/Switch' */

  /* Switch: '<S87>/Switch2' */
  if ((int32_T)rtb_lo1a) {
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_anr4 =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  }

  /* End of Switch: '<S87>/Switch2' */

  /* MinMax: '<S85>/MinMax' */
  if (rtb_lowb <= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_anr4)
  {
  } else {
    rtb_lowb = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_anr4;
  }

  /* End of MinMax: '<S85>/MinMax' */

  /* MinMax: '<S85>/MinMax1' */
  if (rtb_jrck >= rtb_lowb) {
    rtb_lowb = rtb_jrck;
  }

  /* Sum: '<S84>/Add1' incorporates:
   *  MinMax: '<S85>/MinMax1'
   */
  rtb_lowb -= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;

  /* Signum: '<S84>/Sign1' */
  if (rtb_lowb < 0.0F) {
    rtb_jrck = -1.0F;
  } else if (rtb_lowb > 0.0F) {
    rtb_jrck = 1.0F;
  } else {
    rtb_jrck = rtb_lowb;
  }

  /* End of Signum: '<S84>/Sign1' */

  /* Abs: '<S84>/Abs1' incorporates:
   *  Constant: '<S84>/Lat_oc_rls_offset_increment'
   *  Product: '<S84>/Product'
   */
  rtb_ltjz = (real32_T)fabs((real_T)((real32_T)((((real32_T)
    Lat_oc_rls_offset_increment) * 3.05175781E-5F) * rtb_jrck)));

  /* Abs: '<S84>/Abs2' */
  rtb_lowb = (real32_T)fabs((real_T)rtb_lowb);

  /* MinMax: '<S84>/MinMax1' */
  if (rtb_ltjz <= rtb_lowb) {
    rtb_lowb = rtb_ltjz;
  }

  /* Sum: '<S84>/Add' incorporates:
   *  MinMax: '<S84>/MinMax1'
   *  Product: '<S84>/Product1'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l4u2 = (rtb_jrck *
    rtb_lowb) + DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S86>/Constant'
   *  Constant: '<S86>/Constant2'
   *  Sum: '<S86>/Add'
   *  UnitDelay: '<S86>/Unit Delay2'
   */
  if ((int32_T)rtb_) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_ovny = 0.0F;
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_ovny++;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Switch: '<S87>/Switch4' incorporates:
   *  Constant: '<S87>/Constant6'
   *  UnitDelay: '<S87>/Unit Delay5'
   */
  if ((int32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_p3z4) {
    rtb_g0pg = (int32_T)0;
  } else {
    rtb_g0pg = (int32_T)rtb_lo1a;
  }

  /* End of Switch: '<S87>/Switch4' */

  /* Constant: '<S242>/Lat_offset_inc_per_loop_turn_on' */
  rtb_lowb = ((real32_T)Lat_offset_inc_per_loop_turn_on) * 1.52587891E-5F;

  /* MinMax: '<S245>/Min' incorporates:
   *  UnitDelay: '<S245>/Unit Delay'
   */
  if (((int32_T)1000) <= ((int32_T)
                          DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_k3jm))
  {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_k3jm = 1000U;
  }

  /* Logic: '<S245>/Not Operator' */
  rtb_m1aa = (boolean_T)((int32_T)(!(*rt_erh2I)));

  /* Switch: '<S245>/Switch'
   *
   * Block requirements for '<S245>/Switch':
   *  1. Active Flag Counter
   */
  if ((int32_T)rtb_m1aa) {
    /* MinMax: '<S245>/Min' incorporates:
     *  Constant: '<S245>/Constant2'
     *  Sum: '<S245>/Add'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_k3jm++;
  } else {
    /* MinMax: '<S245>/Min' incorporates:
     *  Constant: '<S245>/Constant1'
     */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_k3jm = (uint16_T)0U;
  }

  /* End of Switch: '<S245>/Switch' */

  /* Constant: '<S245>/Sac_ts' */
  rtb_jrck = ((real32_T)Sac_ts) * 3.05175781E-5F;

  /* MinMax: '<S245>/Max' */
  if (rtb_jrck >= 0.01F) {
  } else {
    rtb_jrck = 0.01F;
  }

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Lat_offset_inc_per_loop_slow'
   *  Constant: '<S245>/Duration [s]'
   *  Logic: '<S245>/And Operator'
   *  MinMax: '<S245>/Max'
   *  Product: '<S245>/Divide'
   *  RelationalOperator: '<S245>/Relational Operator'
   */
  if ((((real32_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_k3jm)
       < (1.0F / rtb_jrck)) && ((int32_T)rtb_m1aa)) {
  } else {
    rtb_lowb = ((real32_T)Lat_offset_inc_per_loop_slow) * 1.52587891E-5F;
  }

  /* End of Switch: '<S242>/Switch' */

  /* Constant: '<S246>/LAT_Offset_Max' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = ((real32_T)
    Lat_offset_max) * 0.0009765625F;

  /* Gain: '<S246>/Gain' */
  rtb_jrck = -DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Constant: '<S1>/LAT_Delta_F_Offset_Param'
   *  Sum: '<S1>/Sub1'
   *  Sum: '<S1>/Sub2'
   *  Sum: '<S244>/Sub'
   *  UnitDelay: '<S243>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = ((*rt_gd42I) -
    ((*rt_f3r3I) - (((real32_T)Lat_delta_f_offset) * 0.0009765625F))) -
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq;

  /* Signum: '<S244>/Sign' */
  if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp < 0.0F) {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = -1.0F;
  } else if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp >
             0.0F) {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = 1.0F;
  } else {
    /* Saturate: '<S87>/Saturation' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE =
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp;
  }

  /* End of Signum: '<S244>/Sign' */

  /* Product: '<S244>/Product1' */
  rtb_lowb *= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE;

  /* Abs: '<S244>/Abs2' */
  rtb_lowb = (real32_T)fabs((real_T)rtb_lowb);

  /* MinMax: '<S34>/MinMax2' incorporates:
   *  Abs: '<S244>/Abs1'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = (real32_T)fabs
    ((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp);

  /* MinMax: '<S244>/Min' */
  if (rtb_lowb <= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp)
  {
    /* MinMax: '<S34>/MinMax2' */
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = rtb_lowb;
  }

  /* Sum: '<S244>/Add' incorporates:
   *  MinMax: '<S244>/Min'
   *  Product: '<S244>/Product2'
   *  UnitDelay: '<S243>/Unit Delay'
   */
  rtb_lowb = (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE *
              DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp) +
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq;

  /* MinMax: '<S246>/Min' */
  if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu <= rtb_lowb)
  {
  } else {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = rtb_lowb;
  }

  /* End of MinMax: '<S246>/Min' */

  /* Switch: '<S243>/Switch' incorporates:
   *  Abs: '<S243>/Abs1'
   *  Abs: '<S243>/Abs2'
   *  Constant: '<S243>/Lat_offset_max_clm_trq1'
   *  Constant: '<S243>/Lat_offset_max_steer_angle'
   *  Logic: '<S243>/Logical Operator'
   *  RelationalOperator: '<S243>/Relational Operator1'
   *  RelationalOperator: '<S243>/Relational Operator2'
   */
  if ((((real32_T)fabs((real_T)(*rt_f3r3I))) <= (((real32_T)
         Lat_offset_max_steer_angle) * 0.001526F)) && (((real32_T)fabs((real_T)(*
          rt_m2jwI))) <= (((real32_T)Lat_offset_max_clm_trq) * 0.0009765625F)))
  {
    /* MinMax: '<S246>/Max' */
    if (rtb_jrck >=
        DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu) {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq = rtb_jrck;
    } else {
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq =
        DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;
    }

    /* End of MinMax: '<S246>/Max' */
  }

  /* End of Switch: '<S243>/Switch' */

  /* Constant: '<S12>/Lat_offset_increment_per_loop' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = ((real32_T)
    Lat_offset_increment_per_loop) * 1.52587891E-5F;

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Lat_max_plausible_angle_change'
   *  Logic: '<S12>/Logical Operator'
   *  Logic: '<S12>/Logical Operator1'
   *  Logic: '<S12>/Logical Operator2'
   *  Logic: '<S12>/Logical Operator3'
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  if ((!(*rt_o3aaI)) ||
      ((!DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_lqx1) &&
       ((int32_T)rtb_l4st))) {
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = 10.0F;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Sum: '<S12>/Add1' incorporates:
   *  UnitDelay: '<S12>/Unit Delay'
   */
  rtb_hsjc -= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl;

  /* Signum: '<S12>/Sign1' */
  if (rtb_hsjc < 0.0F) {
    rtb_lowb = -1.0F;
  } else if (rtb_hsjc > 0.0F) {
    rtb_lowb = 1.0F;
  } else {
    rtb_lowb = rtb_hsjc;
  }

  /* End of Signum: '<S12>/Sign1' */

  /* Product: '<S12>/Product' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu *= rtb_lowb;

  /* Abs: '<S12>/Abs1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = (real32_T)fabs
    ((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu);

  /* Abs: '<S12>/Abs2' */
  rtb_hsjc = (real32_T)fabs((real_T)rtb_hsjc);

  /* MinMax: '<S12>/MinMax1' */
  if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu <= rtb_hsjc)
  {
    rtb_hsjc = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;
  }

  /* Sum: '<S12>/Add' incorporates:
   *  MinMax: '<S12>/MinMax1'
   *  Product: '<S12>/Product1'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl += rtb_lowb *
    rtb_hsjc;

  /* Constant: '<S13>/Lat_offset_out_incr_per_loop' */
  rtb_o53h = ((real32_T)Lat_offset_out_incr_per_loop) * 1.52587891E-5F;

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Lat_max_plausible_angle_change'
   *  Logic: '<S13>/Logical Operator3'
   */
  if (!(*rt_o3aaI)) {
    rtb_o53h = 10.0F;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Sum: '<S13>/Add1' incorporates:
   *  UnitDelay: '<S13>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = rtb_nrby -
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ouus;

  /* Signum: '<S13>/Sign1' */
  if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu < 0.0F) {
    rtb_lowb = -1.0F;
  } else if (DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu >
             0.0F) {
    rtb_lowb = 1.0F;
  } else {
    rtb_lowb = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;
  }

  /* End of Signum: '<S13>/Sign1' */

  /* Product: '<S13>/Product' */
  rtb_o53h *= rtb_lowb;

  /* Abs: '<S13>/Abs1' */
  rtb_o53h = (real32_T)fabs((real_T)rtb_o53h);

  /* Abs: '<S13>/Abs2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = (real32_T)fabs
    ((real_T)DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu);

  /* MinMax: '<S13>/MinMax1' */
  if (rtb_o53h <= DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu)
  {
    rtb_ltjz = rtb_o53h;
  } else {
    rtb_ltjz = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu;
  }

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if ((int32_T)(*rt_pehlI)) {
    rtb_o53h = 0.0F;
  } else {
    rtb_o53h = *rt_id5lI;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Lat_oc_rls_min_state_nvm'
   *  RelationalOperator: '<Root>/Relational Operator'
   */
  if (rtb_k4uc < Lat_oc_rls_min_state_nvm) {
    *rt_kkeboI = rtb_o53h;
  } else {
    *rt_kkeboI = rtb_ljyp;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S15>/Add' incorporates:
   *  Constant: '<S15>/LAT_Delta_F_Offset'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  *rt_cpaomI = DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ouus +
    (((real32_T)Lat_delta_f_offset) * 0.0009765625F);

  /* Sum: '<S15>/Sub2' */
  rtb_gpno = (*rt_gd42I) - (*rt_cpaomI);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S264>/Constant'
   *  RelationalOperator: '<S264>/Compare'
   *  S-Function (sfix_bitop): '<S15>/Bitwise Operator'
   *  Sum: '<S15>/Sub1'
   */
  if (((*rt_cpaoI) & 536870912U) != ((uint32_T)0U)) {
    *rt_erh2sI = (*rt_gd42I) -
      DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq;
  } else {
    *rt_erh2sI = rtb_gpno;
  }

  /* End of Switch: '<S15>/Switch' */

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  VEH_Delta_F_Oc_dbg = (int16_T)((real32_T)floor((*rt_erh2sI) / 0.001526F));

  /* Update for UnitDelay: '<Root>/Alg loop' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Algloop_DSTATE = *rt_erh2sI;

  /* Update for UnitDelay: '<S20>/Unit Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hqil = *rt_o3aaI;

  /* Update for UnitDelay: '<S20>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_ade5 = rtb_l4st;

  /* Update for UnitDelay: '<S20>/Unit Delay2' incorporates:
   *  Gain: '<S20>/Sac_ts'
   *  MinMax: '<S48>/MinMax3'
   *  Sum: '<S20>/Add2'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE = ((((real32_T)
    Sac_ts) * 3.05175781E-5F) * tmp_) + rtb_ljyp;

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE = *rt_ezusI;

  /* Update for UnitDelay: '<S20>/Latching_VDY_Offset' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Latching_VDY_Offset_DSTATE =
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_afzy;

  /* Update for Saturate: '<S87>/Saturation' incorporates:
   *  Update for UnitDelay: '<S27>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = rtb_c0ms;

  /* Update for MinMax: '<S34>/MinMax2' incorporates:
   *  Update for UnitDelay: '<S28>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = rtb_au0t;

  /* Update for UnitDelay: '<S25>/Unit Delay5' incorporates:
   *  Sum: '<S25>/Add4'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE = rtb_nlel +
    rtb_ozkw;

  /* Update for UnitDelay: '<S67>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_hb45 = *rt_gd42sI;

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_cct5 = *rt_orb0I;

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = rtb_cph1;

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_dm2g = *rt_o3aaI;

  /* Update for UnitDelay: '<S28>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_lv1m = *rt_p2o1I;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_afzy = rtb_kacn;

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE = *rt_cjpeI;

  /* Update for UnitDelay: '<S87>/Unit Delay3' incorporates:
   *  Constant: '<S87>/Lat_oc_rls_reset'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_ggbc =
    Lat_oc_rls_reset;

  /* Update for UnitDelay: '<S87>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_kcdv = (real32_T)
    rtb_g0pg;

  /* Update for UnitDelay: '<S87>/Unit Delay5' incorporates:
   *  UnitDelay: '<S87>/Unit Delay4'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_p3z4 =
    DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE_m4ak;

  /* Update for UnitDelay: '<S87>/Unit Delay4' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE_m4ak = rtb_odcj;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_lqx1 = rtb_l4st;

  /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
   *  MinMax: '<S13>/MinMax1'
   *  Product: '<S13>/Product1'
   *  Sum: '<S13>/Add'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ouus += rtb_lowb *
    rtb_ltjz;
}

/* Model initialize function */
void DMC_Lat_LAT_Delta_F_Offset_Switch_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) sde_memset(((void *) &DMC_Lat_LAT_Delta_F_Offset_Switch_B), 0,
                    sizeof(rtB_DMC_Lat_LAT_Delta_F_Offset_Switch_T));

  {
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[0] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.DataTypeConversion3[1] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[0] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[1] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[2] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Reshape[3] = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Divide_p0as = 0.0F;
    DMC_Lat_LAT_Delta_F_Offset_Switch_B.Lat_oc_delta_ys_maf_coeff = 0.0F;
  }

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Lat_LAT_Delta_F_Offset_Switch_DWork, 0,
                    sizeof(rtDW_DMC_Lat_LAT_Delta_F_Offset_Switch_T));
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE = 0.0;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Algloop_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_ovny = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Latching_VDY_Offset_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_dzwp = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_pftb = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kb3q = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_hb45 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_cct5 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_h0fu = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay5_DSTATE_lape = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_odq4 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_afzy = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_jlpv = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_aozl = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_l4u2 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_anr4 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_kcdv = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_kmeq = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ouus = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_g2ed = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay1_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.ResettableDelay2_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_1_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_2_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_3_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_4_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_5_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_6_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_7_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_8_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Item_9_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_gd3h = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_nzoi = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_ew4c = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[0] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[1] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[2] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.P_0_DSTATE[3] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[0] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.Theta_0_DSTATE[1] = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_fins = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hxh1 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_bedr = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay_DSTATE_g2n0 = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_jmfr = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay1_DSTATE_hnso = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay2_DSTATE_oylu = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay3_DSTATE_hwvo = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_DWork.UnitDelay4_DSTATE = 0.0F;
  DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState.LAT_Oc_Delta_Ys_Maf_Trig_ZCE =
    POS_ZCSIG;
  DMC_Lat_LAT_Delta_F_Offset_Switch_PrevZCSigState.LAT_Oc_Rls_Trig_ZCE =
    POS_ZCSIG;
}
