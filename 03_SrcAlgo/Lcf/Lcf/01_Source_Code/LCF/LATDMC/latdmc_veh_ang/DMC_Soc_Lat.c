/* $Header: DMC_Soc_Lat.c 1.62 2020/08/20 10:43:53CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc_Lat.c
   C source code generated on           : Wed Aug 19 16:25:20 2020
   Filename of Simulink Model           : DMC_Soc_Lat.mdl/.slx
   Revision of Simulink Model           : 1.4551
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
#include "DMC_Soc_Lat.h"
#include "DMC_Soc_Lat_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: signed_int16_t Lat_min_offset_state, [, ], 1  1,
   PARA: signed_int16_t Lat_min_yaw_rate_offset_state, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_min_kappa_quality, [, ], 1  1,
   PARA: signed_int16_t Sac_activation_override, [, ], 1  1,
   PARA: signed_int16_t Sac_one_by_ts, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode_2, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode_3, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_compensation_mode, [, ], 1  1,
   PARA: unsigned_int16_t Exc_restart_chirp, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_off_flt_initial_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_dmc_status_override_cycles, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_foretime_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_minimum_confidence, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_yaw_debounce_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_yaw_debounce_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_discharge_slope, [, ], 1  1,
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
   PARA: unsigned_int16_t Lat_pitch_max_accuracy, [, ], 1  1,
   PARA: unsigned_int16_t Lat_select_input_source, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_curvature_dot_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_curvature_slope, [, ], 1  1,
   PARA: unsigned_int16_t Ldc_controller_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_controller_mode_1, [, ], 1  1,
   PARA: unsigned_int16_t Sac_controller_mode_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_derating_override, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_activ_source, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fad_enable_multi_ramp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_stiffness_override, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_mode, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_boost_signal_reduction, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_dot_boost_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_state_filter_time_constant, [, ], 1  1,
   PARA: unsigned_int16_t Hec_yaw_rate_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_cmd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_controller_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_off_flt_initial_omega, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_offset_filter_omega, [, ], 1  1,
   PARA: unsigned_int16_t Lat_derating_factor_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_direct_feedthrough_kappa, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_yaw_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_discharge_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_gradient_aes, [, ], 1  1,
   PARA: unsigned_int16_t Lat_max_kappa_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_fast_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_cmd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_ffwd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_psi, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_sign_delta_ys_weighting, [, ], 1  1,
   PARA: unsigned_int16_t Lat_pitch_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_ctrl_delt_dot_flt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_ctrl_parity_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_pt1_control_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_ay_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_memshp_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_yaw_rate_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_yaw_rate_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_filter_fall_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_filter_risng_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_error_filter_falling_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_error_filter_rising_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_filter_falling_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_filter_rising_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Mot_mean_value_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_backlash_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_feedforward_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_3, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_6, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_7, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_max_filter_coeff_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_pt1_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_yr_cmd_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_comp_factor_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_delta_f_latency_comp_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_min_compensation_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_resid_rising_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_residue_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_torque_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_torque_vel_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_trq_req_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_ff_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_ctrl_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_resd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_der_filt_coeff_hf, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_derating_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_der_falling_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_der_rising_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_derating_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_lateral_error_fact_dec, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_lateral_error_fact_inc, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_road_gradient_fact_dec, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_road_gradient_fact_inc, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_dec_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_inc_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Adp_dyc_corr_factor_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_factor_lower_limit, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_factor_upper_limit, [, ], 1  1,
   PARA: unsigned_int16_t Dit_dirac_loop_count, [, ], 1  1,
   PARA: unsigned_int16_t Dit_signal_gen_frequency, [, ], 1  1,
   PARA: unsigned_int16_t Dit_torque_pulse_amplitude, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor_neg, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor_pos, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_ldp_corr_y_sch, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_time_constant_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Hec_r_dot_factor, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_dot_factor_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Hec_r_factor_obf, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_obf_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Lat_ay_arw_k, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_cmd_margin_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_comp_eps_damping, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_comp_eps_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_compensation_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_kd, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_kp, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_pt1_kp, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_detach_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_i_part_margin, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_min_jerk, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_reset_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_torque_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_decreasing_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_max_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_ay_parity_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_sat_margin_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_threshold_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_damp_eps_damping, [, ], 1  1,
   PARA: unsigned_int16_t Lat_damp_eps_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_max_nvm, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_max_nvm_strt, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_variation, [, ], 1  1,
   PARA: unsigned_int16_t Lat_force_trq_shut_off_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_debounce_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_delta_f_cmd_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_lateral_error_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_yaw_rate_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_yrc_residl_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_quadrnt_discharge_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_lateral_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_max_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_counter_preload, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_kappa_gain, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_startup_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_switch_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_lka_startup_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_max_kappa_grad_y_scheduling, [, ], 1  12,
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
   PARA: unsigned_int16_t Lat_pitch_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_r_factor_level_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_control_k_pt1, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_control_kd, [, ], 1  1,
   PARA: unsigned_int16_t Lat_status_first_run_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_stiffness_falling_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_factor_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Lat_support_torque_gain, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_torque_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_preload_enh_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_control_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_err_preload_enh_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_lateral_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_load_comp_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_preload_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lka_max_align_torque, [, ], 1  1,
   PARA: unsigned_int16_t Mot_modulation_duty_cycle, [, ], 1  1,
   PARA: unsigned_int16_t Mot_signal_gen_freq_modulation, [, ], 1  1,
   PARA: unsigned_int16_t Mot_signal_gen_frequency_base, [, ], 1  1,
   PARA: unsigned_int16_t Mot_torque_duty_cycle, [, ], 1  1,
   PARA: unsigned_int16_t Mot_torque_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Prf_t_nom, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_cmd_limit_margin_fact, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_cmd_limit_out_mn_fact, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_bump, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_dys_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_min, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_mode_chg, [, ], 1  1,
   PARA: unsigned_int16_t Sac_anglerate_ctrl_sat_kp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_backlash_omega, [, ], 1  1,
   PARA: unsigned_int16_t Sac_backlash_t_nom, [, ], 1  1,
   PARA: unsigned_int16_t Sac_cmd_feedforward_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_comp_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_delta_cmd_ffwd_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_f_cmd_feedfwd_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_aes, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_barrier, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_fading, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_rampout, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_straight, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grd_aes_cr_y_sc, [, ], 1  11,
   PARA: unsigned_int16_t Sac_delta_f_cmd_initial_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_min_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_counter_steer_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_latency, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_grad_barrier_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_lcf_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_obf_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dyn_corr_factor_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_factor_aes, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_factor_grdscal, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_factor_obf, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_min_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_min_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dynamic_corr_obf_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dynamic_correction_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_eps_no_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Sac_feedfwd_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_feedthr_increment_per_loop, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ffwd_scale_pos_angle_cmd, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_comp_b1_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_comp_omega, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_static_friction_torque, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_torque_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_linear_slope, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_scaling_end, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_scaling_start, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_torque, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_gradient_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_inverse_eg_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_max, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_prediction_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_weighting, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kd, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kd_fading_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kd_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_kmc_loop_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_lin_fading_activation_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_coefficient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_gate_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_max_offset, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_min_offset, [, ], 1  1,
   PARA: unsigned_int16_t Sac_low_grad_max_dys, [, ], 1  1,
   PARA: unsigned_int16_t Sac_maximum_accuracy_request, [, ], 1  1,
   PARA: unsigned_int16_t Sac_maximum_stiffness_request, [, ], 1  1,
   PARA: unsigned_int16_t Sac_min_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_const_barrier, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pid_kd, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pid_kd_damp_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_reduced_kmc_loop_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_ctrl_cmd_fading_y_sched, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kd_fading_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_ki_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sat_dynamic_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_cmd_factor_aes_y_sched, [, ], 1  13,
   PARA: unsigned_int16_t Sat_max_cmd_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Tdf_activation_gain, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_comp_filter_min_residual, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_err_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_error_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_error_sign_slope_2, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_damping_gain, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_delta_f_latency, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_level_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_max_angle, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_max_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_min_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_slope_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_derating_thrs_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_load_comp_end, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_load_comp_start, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_load_comp_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_min_steer_trq_cls_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_out_scale_filt_min_residual, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_request_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_torque_residue, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_st_wheel_unbalance_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_comp_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_comp_thrs_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_ffwd_gain, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_sign_slope_2, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_ldp_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_slp_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Tdf_steer_trq_ff_gain_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_torque_derating_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_reduc_gain_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_torque_request_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_max_init_trq, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_slope_hf_path, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_threshold_dp, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_thrs_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_velocity_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_velocity_derating_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_pos_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a3_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a3_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_gen_cor_fct_neg, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_gen_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_lpf_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_saturation_class_thr, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_loop_gain_corr, [, ], 1  1,
   PARA: unsigned_int16_t Acf_min_sac_enabled_time, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_dec_x_sched, [, ], 1  12,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_inc_x_sched, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a2_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a3_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_x_schedul_aes, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_x_schedul_gen, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_time_constant_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Hec_r_dot_factor_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Hec_r_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Lat_ay_max_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_max_kappa_grad_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_oc_max_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_velocity_dys, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_factor_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Sac_comp_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_delta_cmd_ffwd_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grd_aes_cr_x_sc, [, ], 1  11,
   PARA: unsigned_int16_t Sac_delta_grad_barrier_x_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dynamic_corr_min_x_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Sac_feedfwd_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_friction_comp_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_kd_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_kp_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_yrc_ctrl_cmd_fading_x_sched, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sat_max_cmd_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Tdf_derating_slope_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_derating_thrs_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_load_comp_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_min_steer_trq_cls_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_ldp_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_slp_x_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Tdf_trq_derating_thrs_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_sch_aes_neg, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_sch_gen_neg, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_aes, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_gen, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_nom, [, ], 1  12,
   PARA: unsigned_int16_t Lat_torque_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_error_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_control_error_gain, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max_steer_angle, [, ], 1  1,
   PARA: signed_int16_t Exc_chirp_ay_offset, [, ], 1  1,
   PARA: signed_int16_t Exc_chirp_delta_torque, [, ], 1  1,
   PARA: signed_int16_t Exc_chirp_start_frequency, [, ], 1  1,
   PARA: signed_int16_t Exc_signal_amplitude, [, ], 1  1,
   PARA: signed_int16_t Exc_signal_gen_frequency, [, ], 1  1,
   PARA: signed_int16_t Exc_trq_signal_amplitude, [, ], 1  1,
   PARA: signed_int16_t Exc_trq_signal_gen_frequency, [, ], 1  1,
   PARA: signed_int16_t Lat_delta_f_offset, [, ], 1  1,
   PARA: signed_int16_t Lat_gi_yaw_rate_offset, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay_aes, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay_tja, [, ], 1  1,
   PARA: signed_int16_t Lat_max_output_torque, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max_clm_trq, [, ], 1  1,
   PARA: signed_int16_t Mot_signal_gen_amplitude, [, ], 1  1,
   PARA: signed_int16_t Prf_t_nom_2, [, ], 1  1,
   PARA: signed_int16_t Sac_backlash_angle, [, ], 1  1,
   PARA: signed_int16_t Sac_ffwd_diff_filter_omega, [, ], 1  1,
   PARA: signed_int16_t Sac_friction_comp_torque_cw, [, ], 1  1,
   PARA: signed_int16_t Sac_kd_max_fading_factor, [, ], 1  1,
   PARA: signed_int16_t Sac_kd_obs, [, ], 1  1,
   PARA: signed_int16_t Sac_load_compensation_factor, [, ], 1  1,
   PARA: signed_int16_t Sac_notch_l1, [, ], 1  1,
   PARA: signed_int16_t Sac_notch_l2, [, ], 1  1,
   PARA: signed_int16_t Sac_notch_l3, [, ], 1  1,
   PARA: signed_int16_t Tdf_derating_thrs_eps_i_hold, [, ], 1  1,
   PARA: signed_int16_t Tdf_min_steer_torque_class, [, ], 1  1,
   PARA: signed_int16_t Tdf_min_str_trq_class_handsoff, [, ], 1  1,
   PARA: signed_int16_t Tdf_toque_derating_slope, [, ], 1  1,
   PARA: signed_int16_t Tdf_torque_reduction_gain, [, ], 1  1,
   PARA: signed_int16_t Tdf_torque_reduction_p_gain, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_ki, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_confid_threshold_2, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_confidence_threshold, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_input_filter_coeff, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_lambda, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_offset_increment, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_var_stiffness_init, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_variance_offset_init, [, ], 1  1,
   PARA: signed_int16_t Sac_fad_flt_fallng_lw_dyn_coeff, [, ], 1  1,
   PARA: signed_int16_t Sac_fad_flt_rising_lw_dyn_coeff, [, ], 1  1,
   PARA: signed_int16_t Sac_kp_fading_flt_falling_coeff, [, ], 1  1,
   PARA: signed_int16_t Sac_kp_fading_flt_rising_coeff, [, ], 1  1,
   PARA: signed_int16_t Lat_kappa_discharge_min_error, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_max_kappa, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_max_kappa_dys, [, ], 1  1,
   PARA: signed_int16_t Lco_min_curvature_command, [, ], 1  1,
   PARA: signed_int16_t Lco_min_curvature_dot, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_heading_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_switch_falling_rate_2, [, ], 1  1,
   PARA: unsigned_int16_t Lat_switch_rising_rate_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant_low, [, ], 1  1,
   PARA: unsigned_int16_t Sat_thrs_control_kp, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_inc_per_loop_slow, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_inc_per_loop_turn_on, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_increment_per_loop, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_out_incr_per_loop, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd_phy, [, ], 1  1,
   PARA: signed_int16_t Prf_omega, [, ], 1  1,
   PARA: signed_int16_t Prf_omega_2, [, ], 1  1,
   PARA: unsigned_char_t Acf_no_of_items_in_sample, [, ], 1  1,
   PARA: unsigned_char_t Acf_no_of_segment_selection, [, ], 1  1,
   CALL: DMC_Soc_Lat_step()
   CALL: DMC_Soc_Lat_initialize(0)
   FILE: DMC_Soc_Lat.c
 ***************************************************************************************************
 */
const real32_T DMC_Soc_Lat_R32GND = 0.0F;/* real32_T ground */
const boolean_T DMC_Soc_Lat_BGND = false;/* boolean_T ground */

/* Block signals (auto storage) */
rtB_DMC_Soc_Lat_T DMC_Soc_Lat_B;

/* Block states (auto storage) */
rtDW_DMC_Soc_Lat_T DMC_Soc_Lat_DWork;

/* Previous zero-crossings (trigger) states */
rtZCE_DMC_Soc_Lat_T DMC_Soc_Lat_PrevZCSigState;

/*
 * Initial conditions for atomic system:
 *    '<S206>/S-R_Flip_Flop'
 *    '<S462>/S-R_Flip_Flop'
 */
void DMC_Soc_Lat_SR_Flip_Flop_Init(rtDW_SR_Flip_Flop_DMC_Soc_Lat_T *localDW,
  boolean_T rtp_Q_initial)
{
  /* InitializeConditions for Atomic SubSystem: '<S219>/Atomic Subsystem' */
  /* InitializeConditions for UnitDelay: '<S220>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_Q_initial;

  /* End of InitializeConditions for SubSystem: '<S219>/Atomic Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S206>/S-R_Flip_Flop'
 *    '<S462>/S-R_Flip_Flop'
 */
void DMC_Soc_Lat_SR_Flip_Flop(boolean_T rt_i0ijI, boolean_T rt_pzxuI, boolean_T
  rt_i0ijmI[2], rtDW_SR_Flip_Flop_DMC_Soc_Lat_T *localDW)
{
  boolean_T rtb_;

  /* Outputs for Atomic SubSystem: '<S219>/Atomic Subsystem' */
  /* Switch: '<S220>/Switch' incorporates:
   *  Constant: '<S220>/Constant'
   */
  if ((int32_T)rt_i0ijI) {
    localDW->UnitDelay_DSTATE = (boolean_T)true;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Switch: '<S220>/Switch1' incorporates:
   *  Constant: '<S220>/Constant1'
   */
  if ((int32_T)rt_pzxuI) {
    localDW->UnitDelay_DSTATE = (boolean_T)false;
  }

  /* End of Switch: '<S220>/Switch1' */

  /* Logic: '<S220>/Logical Operator1' */
  rtb_ = (boolean_T)((int32_T)(((int32_T)rt_i0ijI) && ((int32_T)rt_pzxuI)));

  /* Switch: '<S220>/Switch2' incorporates:
   *  Constant: '<S220>/Constant4'
   *  Logic: '<S220>/Logical Operator'
   */
  if ((int32_T)rtb_) {
    rt_i0ijmI[(int8_T)0] = (boolean_T)false;
  } else {
    rt_i0ijmI[(int8_T)0] = (boolean_T)((int32_T)(!localDW->UnitDelay_DSTATE));
  }

  if ((int32_T)rtb_) {
    rt_i0ijmI[(int8_T)1] = (boolean_T)false;
  } else {
    rt_i0ijmI[(int8_T)1] = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S220>/Switch2' */

  /* Update for UnitDelay: '<S220>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rt_i0ijmI[(int8_T)1];

  /* End of Outputs for SubSystem: '<S219>/Atomic Subsystem' */
}

/* Initial conditions for referenced model: 'DMC_Soc_Lat' */
void DMC_Soc_Lat_Init(int16_T *rt_erh2sI)
{
  /* InitializeConditions for UnitDelay: '<Root>/Alg loop1' */
  DMC_Soc_Lat_DWork.Algloop1_DSTATE_mkup = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<Root>/Alg_Loop_Delay12' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S488>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_h20c = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Alg_Loop' */
  DMC_Soc_Lat_DWork.Alg_Loop_DSTATE_gi5b = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S5>/Alg_Loop2' */
  DMC_Soc_Lat_DWork.Alg_Loop2_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S5>/Alg_Loop3' */
  DMC_Soc_Lat_DWork.Alg_Loop3_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jfr0 = 0.0F;

  /* InitializeConditions for ModelReference: '<S5>/LAT_Dmc_Status_Defintion3' */
  DMC_Lat_LAT_Dmc_Status_Defintion_Init(rt_erh2sI,
    &DMC_Soc_Lat_B.LAT_Dmc_Status_Defintion3_o4);

  /* InitializeConditions for ModelReference: '<S17>/LAT_Ldp_States1' */
  DMC_Lat_LAT_Ldp_States_Init(&(DMC_Soc_Lat_DWork.LAT_Ldp_States1_DWORK1.rtdw));

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ee5c = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_oowh = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_i4w1 = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b22d = (boolean_T)false;

  /* InitializeConditions for ModelReference: '<Root>/LAT_Kappa_Filter' */
  DMC_Lat_LAT_Kappa_Filter_Init();

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_jsby = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Alg_Loop1' */
  DMC_Soc_Lat_DWork.Alg_Loop1_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_abtt = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kyvd = 0.0F;

  /* InitializeConditions for UnitDelay: '<S15>/Alg loop1' */
  DMC_Soc_Lat_DWork.Algloop1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop' */
  DMC_Soc_Lat_DWork.Algloop_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop1' */
  DMC_Soc_Lat_DWork.Algloop1_DSTATE_jnar = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop2' */
  DMC_Soc_Lat_DWork.Algloop2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop3' */
  DMC_Soc_Lat_DWork.Algloop3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop4' */
  DMC_Soc_Lat_DWork.Algloop4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop5' */
  DMC_Soc_Lat_DWork.Algloop5_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S17>/Alg loop6' */
  DMC_Soc_Lat_DWork.Algloop6_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay22' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay23' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay23_DSTATE = 0.0F;

  /* InitializeConditions for Atomic SubSystem: '<S35>/Steering_Characteristic_Correction_Factor' */
  /* InitializeConditions for Atomic SubSystem: '<S137>/Error_Side_And_Desired_Driving_Curve_Detection' */
  /* InitializeConditions for Atomic SubSystem: '<S161>/Mean_Calculator' */
  /* InitializeConditions for Atomic SubSystem: '<S182>/Mean_Of_Segment' */
  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq = (boolean_T)false;

  /* InitializeConditions for Delay: '<S185>/Resettable Delay1' */
  DMC_Soc_Lat_DWork.ResettableDelay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S185>/Resettable Delay' */
  DMC_Soc_Lat_DWork.ResettableDelay_DSTATE = 0U;

  /* InitializeConditions for Delay: '<S185>/Resettable Delay2' */
  DMC_Soc_Lat_DWork.ResettableDelay2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S185>/Resettable Delay3' */
  DMC_Soc_Lat_DWork.ResettableDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_buoy = 0.0F;

  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b4na = 0.0F;

  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ieks = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S182>/Mean_Of_Segment' */
  /* End of InitializeConditions for SubSystem: '<S161>/Mean_Calculator' */
  /* End of InitializeConditions for SubSystem: '<S137>/Error_Side_And_Desired_Driving_Curve_Detection' */

  /* InitializeConditions for UnitDelay: '<S163>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_olvg = 0.0F;

  /* InitializeConditions for UnitDelay: '<S137>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)0] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)1] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)2] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)3] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)4] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)5] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)6] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)7] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)8] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)9] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)10] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)11] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)12] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)13] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)14] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)15] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)16] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)17] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)18] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)19] = 1.0F;

  /* InitializeConditions for UnitDelay: '<S137>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)0] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)1] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)2] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)3] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)4] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)5] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)6] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)7] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)8] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)9] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)10] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)11] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)12] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)13] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)14] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)15] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)16] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)17] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)18] = 1.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)19] = 1.0F;

  /* InitializeConditions for UnitDelay: '<S137>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)0] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)1] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)2] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)3] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)4] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)5] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)6] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)7] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)8] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)9] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)10] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)11] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)12] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)13] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)14] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)15] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)16] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)17] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)18] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)19] = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S137>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)0] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)1] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)2] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)3] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)4] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)5] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)6] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)7] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)8] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)9] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)10] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)11] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)12] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)13] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)14] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)15] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)16] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)17] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)18] = (uint16_T)0U;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)19] = (uint16_T)0U;

  /* InitializeConditions for Atomic SubSystem: '<S137>/Read_EEPROM_Correction_Factor' */
  /* InitializeConditions for UnitDelay: '<S165>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj = (boolean_T)false;

  /* End of InitializeConditions for SubSystem: '<S137>/Read_EEPROM_Correction_Factor' */

  /* InitializeConditions for Atomic SubSystem: '<S137>/Possible_Adaptation_Check' */
  /* InitializeConditions for Atomic SubSystem: '<S164>/Wait_so_that_SAC_active_over_certrain_loops' */
  /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_m0jf = (uint16_T)0U;

  /* End of InitializeConditions for SubSystem: '<S164>/Wait_so_that_SAC_active_over_certrain_loops' */
  /* End of InitializeConditions for SubSystem: '<S137>/Possible_Adaptation_Check' */

  /* InitializeConditions for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ctq3 = 0U;

  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_iblc = 0.0F;

  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_c04i = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S137>/Speed_Segment_Identify' */

  /* InitializeConditions for Atomic SubSystem: '<S137>/Correction_Factor_Estimation' */
  /* InitializeConditions for UnitDelay: '<S160>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_luca = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S160>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_juu0 = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S160>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_k51z = (uint16_T)0U;

  /* InitializeConditions for UnitDelay: '<S160>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_apu5 = (uint16_T)0U;

  /* End of InitializeConditions for SubSystem: '<S137>/Correction_Factor_Estimation' */

  /* InitializeConditions for Atomic SubSystem: '<S137>/Save_Correction_Factor_In_Vector' */
  /* InitializeConditions for Atomic SubSystem: '<S166>/Correction_Factor_Gradient_Limitation' */
  /* InitializeConditions for UnitDelay: '<S201>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_c3jk = 0.0F;

  /* End of InitializeConditions for SubSystem: '<S166>/Correction_Factor_Gradient_Limitation' */
  /* End of InitializeConditions for SubSystem: '<S137>/Save_Correction_Factor_In_Vector' */
  /* End of InitializeConditions for SubSystem: '<S35>/Steering_Characteristic_Correction_Factor' */

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S29>/LAT_Loop_Gain_Correction' */
  DMC_Soc_Lat_Loop_Gain_Correction_Init();

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay12' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE_hbpm = 0.0F;

  /* InitializeConditions for ModelReference: '<S35>/DYC_Dynamic_Compensation_Filter' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_Init();

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay alg loop' */
  DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S17>/LAT_Delta_F_Offset_Switch' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_Init();

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d3m1 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay17' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay17_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S35>/SAC_Yaw_Rate_Control' */
  DMC_Lat_SAC_Yaw_Rate_Control_Init();

  /* InitializeConditions for DiscreteIntegrator: '<S489>/Discrete-Time Integrator' */
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState = 0;

  /* InitializeConditions for UnitDelay: '<S490>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_g0mi = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S478>/Discrete-Time Integrator' */
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cs0j = 0.0F;

  /* InitializeConditions for UnitDelay: '<S478>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_f0dp = 0U;

  /* InitializeConditions for UnitDelay: '<S458>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_du4u = (uint16_T)0U;

  /* InitializeConditions for DiscreteIntegrator: '<S462>/Discrete-Time Integrator1' */
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S480>/Discrete-Time Integrator' */
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cipt = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState_lpiz = 0;

  /* InitializeConditions for UnitDelay: '<S477>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24 = 10.0F;

  /* InitializeConditions for UnitDelay: '<S462>/Unit Delay5' */
  DMC_Soc_Lat_DWork.UnitDelay5_DSTATE_jjz1 = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay5' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay5_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S35>/SAC_Damping_Filter' */
  DMC_Soc_Lat_SAC_Damping_Filter_Init();

  /* InitializeConditions for UnitDelay: '<S47>/Alg_Loop' */
  DMC_Soc_Lat_DWork.Alg_Loop_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay3' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay18' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay18_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay4' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay10' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay10_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay alg loop' */
  DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE_kepf = 0.0F;

  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay alg loop1' */
  DMC_Soc_Lat_DWork.UnitDelayalgloop1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S221>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e43m = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay15' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay15_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay16' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay16_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay19' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay19_DSTATE = (boolean_T)false;

  /* InitializeConditions for ModelReference: '<S29>/TDF_Torque_Derating_Function' */
  DMC_Lat_TDF_Torque_Derating_Function_Init();

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay1' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay11' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay11_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay13' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay13_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S215>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dpkx = 0.0F;

  /* InitializeConditions for ModelReference: '<S29>/SAC_Angle_Command_Fading' */
  DMC_Lat_SAC_Angle_Command_Fading_Init();

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay7' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay7_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay2' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S279>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hnnx = 0.0F;

  /* InitializeConditions for UnitDelay: '<S275>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fo0b = 0.0F;

  /* InitializeConditions for UnitDelay: '<S214>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S36>/Alg_loop' */
  DMC_Soc_Lat_DWork.Alg_loop_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S216>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w = 0.0F;

  /* InitializeConditions for UnitDelay: '<S209>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bp0l = 0.0F;

  /* InitializeConditions for UnitDelay: '<S206>/Alg_loop1' */
  DMC_Soc_Lat_DWork.Alg_loop1_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S206>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_foqo = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S210>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_my50 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay9' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay9_DSTATE = 0.0F;

  /* InitializeConditions for Atomic SubSystem: '<S206>/S-R_Flip_Flop' */
  DMC_Soc_Lat_SR_Flip_Flop_Init(&DMC_Soc_Lat_DWork.SR_Flip_Flop, false);

  /* End of InitializeConditions for SubSystem: '<S206>/S-R_Flip_Flop' */

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay8' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay8_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay6' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S207>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mtzq = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S207>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kxew = 0.0F;

  /* InitializeConditions for ModelReference: '<S34>/SAT_Angle_Command_Saturation' */
  DMC_Lat_SAT_Angle_Command_Saturation_Init();

  /* InitializeConditions for UnitDelay: '<S86>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_a5ig = 0.0F;

  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nsgx = 0.0F;

  /* InitializeConditions for UnitDelay: '<S79>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ljte = 0.0F;

  /* InitializeConditions for UnitDelay: '<S78>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_asff = 0.0F;

  /* InitializeConditions for UnitDelay: '<S82>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_kxgv = 0.0F;

  /* InitializeConditions for UnitDelay: '<S107>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u = 0.0F;

  /* InitializeConditions for UnitDelay: '<S106>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp = 0.0F;

  /* InitializeConditions for UnitDelay: '<S108>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay21' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay21_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S29>/SAC_Accuracy_Calculation' */
  DMC_Lat_SAC_Accuracy_Calculation_Init();

  /* InitializeConditions for UnitDelay: '<S120>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j5v2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S121>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ko35 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S497>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S119>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_mdsl = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_i13z = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ckqg = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_jaq2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay4' */
  DMC_Soc_Lat_DWork.UnitDelay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay5' */
  DMC_Soc_Lat_DWork.UnitDelay5_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay6' */
  DMC_Soc_Lat_DWork.UnitDelay6_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay7' */
  DMC_Soc_Lat_DWork.UnitDelay7_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay8' */
  DMC_Soc_Lat_DWork.UnitDelay8_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay9' */
  DMC_Soc_Lat_DWork.UnitDelay9_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay10' */
  DMC_Soc_Lat_DWork.UnitDelay10_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay11' */
  DMC_Soc_Lat_DWork.UnitDelay11_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay12' */
  DMC_Soc_Lat_DWork.UnitDelay12_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay13' */
  DMC_Soc_Lat_DWork.UnitDelay13_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S498>/Unit Delay14' */
  DMC_Soc_Lat_DWork.UnitDelay14_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S496>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_b55e = 0.0F;

  /* InitializeConditions for UnitDelay: '<S118>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d45l = 0.0F;

  /* InitializeConditions for ModelReference: '<S43>/MOT_Modulation_Torque' */
  DMC_Soc_Lat_MOT_Modulation_Torque_Init();

  /* InitializeConditions for UnitDelay: '<S270>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jjfr = 0.0F;

  /* InitializeConditions for UnitDelay: '<S269>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dngv = 0.0F;

  /* InitializeConditions for UnitDelay: '<S263>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pmt4 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S256>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S257>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_hzxr = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay20' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay20_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S43>/SAC_Friction_Compensation' */
  DMC_Lat_SAC_Friction_Compensation_Init();

  /* InitializeConditions for ModelReference: '<S29>/SAC_Steer_Angle_Cmd_Controller' */
  DMC_Soc_Lat_SAC_Steer_Angle_Cmd_Controller_Init();

  /* InitializeConditions for UnitDelay: '<S250>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ddx5 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S250>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei = 0.0F;

  /* InitializeConditions for UnitDelay: '<S284>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pfgp = 0.0F;

  /* InitializeConditions for UnitDelay: '<S290>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws = 0.0F;

  /* InitializeConditions for UnitDelay: '<S285>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgsj = 0.0F;

  /* InitializeConditions for UnitDelay: '<S286>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kpna = 0.0F;

  /* InitializeConditions for UnitDelay: '<S287>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_am0s = 0.0F;

  /* InitializeConditions for UnitDelay: '<S288>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_l240 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S291>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bvsy = 0.0F;

  /* InitializeConditions for UnitDelay: '<S40>/Alg Loop1' */
  DMC_Soc_Lat_DWork.AlgLoop1_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S249>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_erx0 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S248>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_drku = 0.0F;

  /* InitializeConditions for UnitDelay: '<S245>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_djgi = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S245>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_is2t = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S230>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hshs = 0.0F;

  /* InitializeConditions for UnitDelay: '<S309>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_aucg = 0.0F;

  /* InitializeConditions for UnitDelay: '<S296>/Unit Delay (1)' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e1bg = 0.0F;

  /* InitializeConditions for UnitDelay: '<S296>/Unit Delay (2)' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hrg2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S296>/Unit Delay (3)' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ffue = 0.0F;

  /* InitializeConditions for UnitDelay: '<S29>/Alg_Loop_Delay14' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay14_DSTATE = 0.0F;

  /* InitializeConditions for ModelReference: '<S29>/SAC_Proportional_Factor_Derating' */
  DMC_Soc_Lat_SAC_Proportional_Factor_Derating_Init();

  /* InitializeConditions for UnitDelay: '<S206>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_g4ol = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nzhp = 0.0F;

  /* InitializeConditions for UnitDelay: '<S40>/Alg Loop' */
  DMC_Soc_Lat_DWork.AlgLoop_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S243>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgm4 = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S242>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_o534 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S241>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_gnzo = 0.0F;

  /* InitializeConditions for UnitDelay: '<S243>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mxbc = (boolean_T)false;

  /* InitializeConditions for MinMax: '<S224>/MinMax2' incorporates:
   *  InitializeConditions for UnitDelay: '<S224>/Unit Delay1'
   */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q = 0.0;

  /* InitializeConditions for UnitDelay: '<S227>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_mdgq = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S227>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_opjk = 0U;

  /* InitializeConditions for Triggered SubSystem: '<S40>/LAT_Gi_Shift_Register' */
  /* InitializeConditions for UnitDelay: '<S235>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ejt4 = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S226>/Unit Delay9' */
  DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S234>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nc01 = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S239>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_dsnr = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S233>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mg5o = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S236>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nxl5 = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S237>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_cr5d = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S238>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b45s = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S240>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_m43z = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S226>/Unit Delay10' */
  DMC_Soc_Lat_DWork.UnitDelay10_DSTATE_hhgz = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S226>/Unit Delay11' */
  DMC_Soc_Lat_DWork.UnitDelay11_DSTATE_amny = (boolean_T)false;

  /* End of InitializeConditions for SubSystem: '<S40>/LAT_Gi_Shift_Register' */

  /* InitializeConditions for UnitDelay: '<S255>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kho1 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hxjk = 0.0F;

  /* InitializeConditions for UnitDelay: '<S476>/UD'
   *
   * Block description for '<S476>/UD':
   *
   *  Store in Global RAM
   */
  DMC_Soc_Lat_DWork.UD_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S462>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif = 0.0F;

  /* InitializeConditions for UnitDelay: '<S475>/UD'
   *
   * Block description for '<S475>/UD':
   *
   *  Store in Global RAM
   */
  DMC_Soc_Lat_DWork.UD_DSTATE_eihf = 0.0F;

  /* InitializeConditions for Atomic SubSystem: '<S462>/S-R_Flip_Flop' */
  DMC_Soc_Lat_SR_Flip_Flop_Init(&DMC_Soc_Lat_DWork.SR_Flip_Flop_alsc, false);

  /* End of InitializeConditions for SubSystem: '<S462>/S-R_Flip_Flop' */

  /* InitializeConditions for UnitDelay: '<S462>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_d5fw = 0.0F;
}

/* Start for referenced model: 'DMC_Soc_Lat' */
void DMC_Soc_Lat_Start(void)
{
  /* Start for Atomic SubSystem: '<S35>/Steering_Characteristic_Correction_Factor' */
  /* Start for Atomic SubSystem: '<S137>/Error_Side_And_Desired_Driving_Curve_Detection' */
  /* Start for Atomic SubSystem: '<S161>/Mean_Calculator' */
  /* InitializeConditions for Enabled SubSystem: '<S182>/Mean_Of_All_Segments' */
  /* InitializeConditions for Delay: '<S184>/Item_1' */
  DMC_Soc_Lat_DWork.Item_1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S184>/Item_2' */
  DMC_Soc_Lat_DWork.Item_2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S184>/Item_3' */
  DMC_Soc_Lat_DWork.Item_3_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S184>/Item_4' */
  DMC_Soc_Lat_DWork.Item_4_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S184>/Item_5' */
  DMC_Soc_Lat_DWork.Item_5_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S184>/Count' */
  DMC_Soc_Lat_DWork.icLoad = 1U;

  /* End of InitializeConditions for SubSystem: '<S182>/Mean_Of_All_Segments' */
  /* End of Start for SubSystem: '<S161>/Mean_Calculator' */
  /* End of Start for SubSystem: '<S137>/Error_Side_And_Desired_Driving_Curve_Detection' */
  /* End of Start for SubSystem: '<S35>/Steering_Characteristic_Correction_Factor' */
  /* Start for ModelReference: '<S17>/LAT_Delta_F_Offset_Switch' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_Start();
}

/* Output and update for referenced model: 'DMC_Soc_Lat' */
void DMC_Soc_Lat(const int16_T *rt_erh2I, const real32_T *rt_gd42I, const
                 real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const real32_T
                 *rt_ngfdI, const real32_T *rt_f3r3I, const real32_T *rt_kkebI,
                 const int16_T *rt_hny3I, const real32_T *rt_kwugI, const
                 real32_T *rt_kafvI, const real32_T *rt_kaadI, const real32_T
                 *rt_eltpI, const real32_T *rt_cjpeI, const real32_T *rt_ezusI,
                 const real32_T *rt_orb0I, const int16_T *rt_pdp2I, const
                 int16_T *rt_dxdkI, const real32_T *rt_dmmuI, const real32_T
                 *rt_gyqsI, const real32_T *rt_m2jwI, const int16_T *rt_pdncI,
                 const boolean_T *rt_id5lI, const boolean_T *rt_prezI, const
                 real32_T *rt_pehlI, const int16_T *rt_o3aaI, const real32_T
                 *rt_e45jI, const real32_T *rt_mcq4I, const int16_T *rt_jus1I,
                 const real32_T *rt_popsI, const int16_T *rt_m3xfI, const
                 real32_T *rt_p2o1I, const int16_T *rt_i3p3I, const real32_T
                 *rt_ka1pI, const int16_T *rt_hsldI, const boolean_T *rt_bofcI,
                 const uint8_T *rt_ngjpI, const int16_T *rt_gye0I, const uint8_T
                 *rt_gohpI, const int16_T *rt_epsyI, const int16_T *rt_kfmqI,
                 const boolean_T *rt_bn5yI, const real32_T *rt_c4rhI, const
                 boolean_T *rt_p4gfI, const boolean_T *rt_pynyI, const real32_T *
                 rt_enkbI, const real32_T *rt_pxsgI, const real32_T *rt_mkevI,
                 const uint16_T *rt_nkaaI, const boolean_T *rt_fpnbI, const
                 real32_T *rt_dfm1I, const real32_T rt_mwrrI[20], const real32_T
                 rt_h3drI[20], const uint16_T rt_hzz5I[20], const uint16_T
                 rt_h23nI[20], const boolean_T *rt_hs5jI, const real32_T
                 *rt_i3nmI, const boolean_T *rt_h1w1I, const real32_T *rt_igqzI,
                 const uint16_T *rt_dzorI, const int16_T *rt_a5xsI, const
                 real32_T *rt_ido5I, const boolean_T *rt_bx45I, const boolean_T *
                 rt_dptqI, const boolean_T *rt_j53pI, int16_T *rt_erh2sI,
                 int16_T *rt_gd42sI, real32_T *rt_cpaomI, real32_T *rt_e4ho4I,
                 real32_T *rt_ngfdoI, real32_T *rt_f3r3lI, uint8_T *rt_kkeboI,
                 real32_T *rt_hny3uI, uint8_T *rt_kwuguI, uint8_T *rt_kafvzI,
                 uint8_T *rt_kaadaI, uint8_T *rt_eltpnI, real32_T *rt_cjpenI,
                 uint8_T *rt_ezus0I, uint8_T *rt_orb0mI, uint8_T *rt_pdp2qI,
                 real32_T *rt_dxdktI, boolean_T *rt_dmmu3I, boolean_T *rt_gyqsrI,
                 uint16_T *rt_m2jwdI, real32_T *rt_pdncgI, uint16_T rt_id5lvI[20],
                 uint16_T rt_prezcI[20], real32_T *rt_pehleI, real32_T
                 *rt_o3aadI, int16_T *rt_e45jiI, uint16_T *rt_mcq4bI, real32_T
                 *rt_jus11I, real32_T *rt_pops4I, uint8_T *rt_m3xflI)
{
  /* local block i/o variables */
  real32_T rtb_c4yx;
  real32_T rtb_kxln;
  real32_T rtb_e4ku;
  real32_T rtb_euvg;
  real32_T rtb_fgeh;
  real32_T rtb_ojre;
  real32_T rtb_jhwo;
  real32_T rtb_ghy4;
  real32_T rtb_jhzt;
  real32_T rtb_ghz1;
  real32_T rtb_fz0g;
  real32_T rtb_llyj;
  real32_T rtb_ofyg;
  real32_T rtb_hlnm;
  real32_T rtb_n3s4;
  real32_T rtb_d2ky;
  real32_T rtb_mxz2;
  real32_T rtb_d50f;
  real32_T rtb_ll3p;
  real32_T rtb_l1xc;
  real32_T rtb_cep1;
  real32_T rtb_fyle;
  real32_T rtb_hqad;
  real32_T rtb_aayn;
  real32_T rtb_akp0;
  real32_T rtb_macq;
  real32_T rtb_ni1l;
  real32_T rtb_eh0v;
  real32_T rtb_ez30;
  real32_T rtb_gkzz;
  real32_T rtb_hvhi;
  real32_T rtb_ep44;
  real32_T rtb_ncfe;
  real32_T rtb_kzgj;
  real32_T rtb_b5si;
  real32_T rtb_eg0o;
  real32_T rtb_ifco;
  real32_T rtb_exxx;
  real32_T rtb_dmt0;
  real32_T rtb_gfou;
  real32_T rtb_n1zt;
  real32_T rtb_pqrc;
  real32_T rtb_eypw;
  real32_T rtb_hd5l;
  real32_T rtb_hbvj;
  real32_T rtb_pgfp;
  real32_T rtb_oc5b;
  real32_T rtb_gta3;
  real32_T rtb_kzhy;
  real32_T rtb_ozv1;
  real32_T rtb_l1lr;
  real32_T rtb_jnhy;
  real32_T rtb_kgdq;
  real32_T rtb_na3o;
  real32_T rtb_lmkf;
  real32_T rtb_etec;
  real32_T rtb_bi2v;
  real32_T rtb_flnx;
  real32_T rtb_n0ba;
  real32_T rtb_j111;
  real32_T rtb_iuh5;
  real32_T rtb_nhlb;
  real32_T rtb_n3ry;
  real32_T rtb_kggy;
  real32_T rtb_lyau;
  real32_T rtb_gemg;
  real32_T rtb_jeca;
  real32_T rtb_nexq;
  real32_T rtb_ls5n;
  real32_T rtb_a2h2;
  real32_T rtb_jgkv;
  real32_T rtb_pdty;
  real32_T rtb_afoa;
  real32_T rtb_cfdi;
  real32_T rtb_e3dd;
  real32_T rtb_hwhx;
  real32_T rtb_heqw;
  real32_T rtb_l1ll;
  real32_T rtb_gnup;
  real32_T rtb_mw4r;
  real32_T rtb_fadn;
  real32_T rtb_cy3g;
  real32_T rtb_maat;
  real32_T rtb_axf1;
  real32_T rtb_gmy5;
  uint16_T rtb_cec3;
  uint16_T rtb_i4mt;
  uint16_T rtb_oclz;
  int16_T rtb_futb;
  uint8_T rtb_dzi1;
  boolean_T rtb_cjo4;
  boolean_T rtb_b2ee;
  boolean_T rtb_ef4d;
  boolean_T rtb_pkm5;
  boolean_T rtb_h0p5;
  boolean_T rtb_jomt;
  boolean_T rtb_gtaj;
  boolean_T rtb_f3ae;
  boolean_T rtb_eib2;
  boolean_T rtb_lhxj;
  boolean_T rtb_ccsn;
  boolean_T rtb_f4hc;
  boolean_T rtb_hczn;
  boolean_T rtb_owpf;
  boolean_T rtb_m04f;
  boolean_T rtb_icrr;
  boolean_T rtb_j5oy;
  boolean_T rtb_dvgz;
  boolean_T rtb_hdiu;
  boolean_T rtb_bhbp;
  boolean_T rtb_fzlt;
  boolean_T rtb_ovjx;
  real32_T rtb_;
  int16_T rtb_b1op;
  real32_T rtb_e1oo;
  uint32_T rtb_jyuz;
  real32_T rtb_pfif;
  real32_T rtb_l0rv;
  real32_T rtb_h0la;
  real32_T rtb_lscy;
  boolean_T rtb_fckq;
  boolean_T rtb_pyzc;
  boolean_T rtb_azal;
  real32_T rtb_n4jt;
  real32_T rtb_dpeo;
  real32_T rtb_jwxe;
  real32_T rtb_ojsl;
  real32_T rtb_pnn5;
  real32_T rtb_m3dz;
  boolean_T rtb_ji32;
  boolean_T rtb_dm2g;
  boolean_T rtb_m4lj;
  boolean_T rtb_e5xk;
  int32_T rtb_kw01;
  boolean_T rtb_llzw[2];
  boolean_T rtb_ayms;
  boolean_T rtb_desf;
  boolean_T rtb_kiah;
  boolean_T rtb_k1lr;
  boolean_T rtb_cj00;
  boolean_T rtb_nlrq;
  real_T rtb_elan;
  int16_T rtb_knky;
  boolean_T rtb_pcxk;
  int32_T rtb_kzp5;
  boolean_T rtb_fm0p;
  boolean_T rtb_crhi;
  boolean_T rtb_lcw5;
  boolean_T rtb_gwnw;
  boolean_T rtb_amqm;
  boolean_T rtb_gpun;
  real32_T rtb_dtuy;
  real32_T rtb_mdfx;
  real32_T rtb_idqr;
  int32_T rtb_itp5;
  boolean_T rtb_hy3g[2];
  boolean_T rtb_fsbi;
  boolean_T rtb_bcax;
  real32_T rtb_iwln;
  uint8_T rtb_mbmh;
  real32_T rtb_m0pk;
  uint8_T rtb_kgt0;
  real32_T rtb_nsi3;
  real32_T rtb_mkzu;
  real32_T rtb_fit4;
  uint8_T rtb_l15a;
  real32_T rtb_ixul;
  real32_T rtb_bqaz[40];
  uint16_T rtb_bf3w[40];
  boolean_T rtb_ohj2;
  uint8_T rtb_mxcu;
  real_T rtb_ergg;
  real32_T tmp_;
  real32_T tmp_0;
  real32_T tmp_1;
  real32_T tmp_2;
  real32_T tmp_3;
  real32_T tmp_4;
  real32_T tmp_5;
  real32_T tmp_6;
  real32_T tmp_7;
  real32_T tmp_8;
  real32_T tmp_9;
  real32_T tmp_a;
  real32_T tmp_b;
  real32_T tmp_c;
  real32_T tmp_d;
  real32_T tmp_e;
  real32_T tmp_f;
  real32_T tmp_g;
  real32_T tmp_h;
  real32_T tmp_i;
  real32_T tmp_j;
  real32_T tmp_k;
  real32_T tmp_l;
  real32_T tmp_m;
  real32_T tmp_n;
  real32_T tmp_o;
  real32_T tmp_p;
  real32_T tmp_q;
  real32_T tmp_r;
  real32_T tmp_s;
  real32_T tmp_t;
  real32_T tmp_u;
  real32_T tmp_v;
  uint16_T tmp_w;
  uint16_T tmp_x;
  uint16_T tmp_y;
  uint16_T tmp_z;
  uint16_T tmp_10;
  uint16_T tmp_11;
  uint16_T tmp_12;
  uint16_T tmp_13;
  uint16_T tmp_14;
  uint16_T tmp_15;
  uint16_T tmp_16;
  uint16_T tmp_17;
  uint16_T tmp_18;
  uint16_T tmp_19;
  uint16_T tmp_1a;
  uint16_T tmp_1b;
  uint16_T tmp_1c;
  uint16_T tmp_1d;
  uint16_T tmp_1e;
  uint16_T tmp_1f;
  uint16_T tmp_1g;
  uint16_T tmp_1h;
  uint16_T tmp_1i;
  uint16_T tmp_1j;
  uint16_T tmp_1k;
  uint16_T tmp_1l;
  uint16_T tmp_1m;
  uint16_T tmp_1n;
  uint16_T tmp_1o;
  uint16_T tmp_1p;
  uint16_T tmp_1q;
  uint16_T tmp_1r;
  uint16_T tmp_1s;
  uint16_T tmp_1t;
  uint16_T tmp_1u;
  uint16_T tmp_1v;
  uint16_T tmp_1w;
  uint16_T tmp_1x;
  uint16_T tmp_1y;
  uint16_T tmp_1z;

  /* Abs: '<Root>/Abs1' */
  rtb_ = (real32_T)fabs((real_T)(*rt_ezusI));

  /* MinMax: '<S477>/MinMax' incorporates:
   *  UnitDelay: '<Root>/Alg_Loop_Delay12'
   */
  rtb_maat = DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE;

  /* MinMax: '<Root>/MinMax' */
  if (((int16_T)100) <= (*rt_kfmqI)) {
    rtb_kw01 = (int32_T)100;
  } else {
    rtb_kw01 = (int32_T)(*rt_kfmqI);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  MinMax: '<Root>/MinMax'
   */
  *rt_pdp2qI = (uint8_T)rtb_kw01;

  /* S-Function (sfix_bitop): '<S32>/Bitwise Operator' incorporates:
   *  ArithShift: '<S32>/Shift Arithmetic'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Constant5'
   *  DataTypeConversion: '<S32>/Data Type Conversion'
   *  DataTypeConversion: '<S32>/Data Type Conversion1'
   */
  SAC_Controller_Mode_Sig = (((uint32_T)Sac_controller_mode_2) << 16) |
    Sac_controller_mode_1;

  /* MinMax: '<S488>/MinMax1' incorporates:
   *  Constant: '<S458>/Lat_select_input_source1'
   */
  if (6.0F <= ((real32_T)Lat_select_input_source)) {
    rtb_ojsl = 6.0F;
  } else {
    rtb_ojsl = (real32_T)Lat_select_input_source;
  }

  /* MultiPortSwitch: '<S488>/Multiport Switch1' incorporates:
   *  Constant: '<S488>/Constant10'
   *  Constant: '<S488>/Constant12'
   *  Constant: '<S488>/Constant6'
   *  Constant: '<S488>/Constant7'
   *  Constant: '<S488>/Constant8'
   *  Constant: '<S488>/Constant9'
   *  MinMax: '<S488>/MinMax1'
   */
  switch ((int32_T)rtb_ojsl) {
   case 1:
    rtb_e1oo = 0.0F;
    break;

   case 2:
    rtb_e1oo = 100.0F;
    break;

   case 3:
    rtb_e1oo = 1.0F;
    break;

   case 4:
    rtb_e1oo = 0.5F;
    break;

   case 5:
    rtb_e1oo = 0.25F;
    break;

   default:
    rtb_e1oo = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S488>/Multiport Switch1' */

  /* MinMax: '<S488>/MinMax2' incorporates:
   *  UnitDelay: '<S488>/Unit Delay1'
   */
  if (10.0F <= DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_h20c) {
    rtb_dtuy = 10.0F;
  } else {
    rtb_dtuy = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_h20c;
  }

  /* End of MinMax: '<S488>/MinMax2' */

  /* MinMax: '<S488>/MinMax3' incorporates:
   *  Constant: '<S488>/Lat_pre_trigger_time'
   *  Sum: '<S488>/Add4'
   */
  if ((rtb_dtuy - 1.0F) >= 0.0F) {
    rtb_ojsl = rtb_dtuy - 1.0F;
  } else {
    rtb_ojsl = 0.0F;
  }

  /* Product: '<S488>/Product1' incorporates:
   *  MinMax: '<S488>/MinMax3'
   */
  rtb_e1oo *= rtb_ojsl;

  /* Constant: '<S486>/Exc_signal_amplitude' */
  rtb_pfif = ((real32_T)Exc_signal_amplitude) * 0.0009765625F;

  /* MinMax: '<S488>/MinMax4' */
  if (rtb_e1oo <= 1.0F) {
  } else {
    rtb_e1oo = 1.0F;
  }

  /* Product: '<S488>/Product2' incorporates:
   *  MinMax: '<S488>/MinMax4'
   */
  rtb_e1oo *= rtb_pfif;

  /* UnitDelay: '<S5>/Alg_Loop' */
  rtb_bhbp = DMC_Soc_Lat_DWork.Alg_Loop_DSTATE_gi5b;

  /* UnitDelay: '<S5>/Alg_Loop2' */
  rtb_ovjx = DMC_Soc_Lat_DWork.Alg_Loop2_DSTATE;

  /* UnitDelay: '<S5>/Alg_Loop3' */
  rtb_fzlt = DMC_Soc_Lat_DWork.Alg_Loop3_DSTATE;

  /* Switch: '<S491>/Switch5' incorporates:
   *  Constant: '<S491>/Constant5'
   *  Constant: '<S491>/Sac_activation_override'
   *  Constant: '<S495>/Constant'
   *  RelationalOperator: '<S495>/Compare'
   *  Sum: '<S491>/Add'
   */
  if (Sac_activation_override >= ((int16_T)2)) {
    DMC_Soc_Lat_B.Switch5 = (int16_T)(Sac_activation_override - ((int16_T)1));
  } else {
    DMC_Soc_Lat_B.Switch5 = *rt_hny3I;
  }

  /* End of Switch: '<S491>/Switch5' */

  /* RelationalOperator: '<S494>/Compare' incorporates:
   *  Constant: '<S491>/Sac_activation_override'
   *  Constant: '<S494>/Constant'
   */
  rtb_hdiu = (boolean_T)((int32_T)(Sac_activation_override >= ((int16_T)1)));

  /* Switch: '<S491>/Switch' incorporates:
   *  Constant: '<S491>/Constant6'
   */
  if ((int32_T)rtb_hdiu) {
    rtb_b1op = (int16_T)1;
  } else {
    rtb_b1op = *rt_erh2I;
  }

  /* End of Switch: '<S491>/Switch' */

  /* Logic: '<S20>/Logical Operator1' incorporates:
   *  Constant: '<S17>/Dmc_configuration_mode_3'
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   *  Logic: '<S20>/Logical Operator'
   *  Logic: '<S20>/Logical Operator2'
   *  Logic: '<S20>/Logical Operator3'
   *  Logic: '<S20>/Logical Operator4'
   *  Logic: '<S20>/Logical Operator5'
   *  S-Function (sfix_bitop): '<S20>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S20>/Bitwise Operator2'
   *  S-Function (sfix_bitop): '<S20>/Bitwise Operator3'
   */
  rtb_cjo4 = (boolean_T)((int32_T)(((!(*rt_bx45I)) || (!((((int32_T)
    Dmc_configuration_mode_3) & ((int32_T)256)) != ((int32_T)0)))) &&
    ((((((int32_T)Dmc_configuration_mode_3) & ((int32_T)4096)) != ((int32_T)0)) &&
      (DMC_Soc_Lat_B.Switch5 != ((int16_T)0))) || ((((int32_T)((uint16_T)
    rtb_b1op)) & ((int32_T)1)) != ((int32_T)0)))));

  /* Switch: '<S491>/Switch1' incorporates:
   *  Constant: '<S491>/Constant1'
   */
  if ((int32_T)rtb_hdiu) {
    DMC_LAT_DEGRADATION_TEMP = 0;
  } else {
    DMC_LAT_DEGRADATION_TEMP = *rt_pdncI;
  }

  /* End of Switch: '<S491>/Switch1' */

  /* Switch: '<S491>/Switch2' incorporates:
   *  Constant: '<S491>/Constant2'
   */
  if ((int32_T)rtb_hdiu) {
    VEH_Stability_Control_Active_temp = false;
  } else {
    VEH_Stability_Control_Active_temp = *rt_prezI;
  }

  /* End of Switch: '<S491>/Switch2' */

  /* RelationalOperator: '<S493>/Compare' incorporates:
   *  Constant: '<S491>/Sac_activation_override'
   *  Constant: '<S493>/Constant'
   */
  rtb_hdiu = (boolean_T)((int32_T)(Sac_activation_override == ((int16_T)1)));

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if ((int32_T)(*rt_pynyI)) {
    rtb_futb = (int16_T)0;
  } else {
    rtb_futb = (int16_T)((uint32_T)(((uint32_T)(*rt_ngjpI)) * ((uint8_T)100U)));
  }

  /* End of Switch: '<Root>/Switch' */

  /* UnitDelay: '<S9>/Unit Delay1' */
  rtb_h0la = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jfr0;

  /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
   *  Constant: '<S9>/Lat_stiffness_falling_decrement'
   */
  rtb_axf1 = ((real32_T)Lat_stiffness_falling_decrement) * 0.0009765625F;

  /* Switch: '<S9>/Switch3' incorporates:
   *  Product: '<S9>/Product2'
   *  UnitDelay: '<Root>/Alg loop1'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  if ((int32_T)DMC_Soc_Lat_DWork.Algloop1_DSTATE_mkup) {
  } else {
    rtb_h0la = rtb_axf1 * DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jfr0;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* Sum: '<S9>/Add1' incorporates:
   *  Abs: '<S9>/Abs'
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   */
  rtb_l0rv = ((real32_T)fabs((real_T)((real32_T)(((real32_T)rtb_futb) * 0.01F))))
    - rtb_h0la;

  /* Signum: '<S9>/Sign1' */
  if (rtb_l0rv < 0.0F) {
    rtb_axf1 = -1.0F;
  } else if (rtb_l0rv > 0.0F) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = rtb_l0rv;
  }

  /* End of Signum: '<S9>/Sign1' */

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  Abs: '<S9>/Abs1'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  Gain: '<S9>/Sac_ts'
   *  Product: '<S9>/Product'
   */
  rtb_fadn = (real32_T)(*rt_gye0I);
  if (25.0F >= rtb_fadn) {
    rtb_fadn = 25.0F;
  }

  rtb_fadn = ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_fadn) * rtb_axf1;
  rtb_fadn = (real32_T)fabs((real_T)rtb_fadn);

  /* Abs: '<S9>/Abs2' */
  rtb_l0rv = (real32_T)fabs((real_T)rtb_l0rv);

  /* MinMax: '<S9>/MinMax1' */
  if (rtb_fadn <= rtb_l0rv) {
    rtb_l0rv = rtb_fadn;
  }

  /* Sum: '<S9>/Add' incorporates:
   *  MinMax: '<S9>/MinMax1'
   *  Product: '<S9>/Product1'
   */
  rtb_lscy = (rtb_axf1 * rtb_l0rv) + rtb_h0la;

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  Gain: '<S6>/Gain4'
   */
  rtb_fadn = 0.01F * rtb_lscy;

  /* MinMax: '<S6>/MinMax' */
  if (rtb_fadn <= 1.0F) {
  } else {
    /* MinMax: '<S9>/MinMax2' */
    rtb_fadn = 1.0F;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* Switch: '<S491>/Switch4' incorporates:
   *  Constant: '<S491>/Sac_stiffness_override'
   *  Gain: '<S491>/Gain'
   *  MinMax: '<S6>/MinMax2'
   */
  if ((int32_T)rtb_hdiu) {
    rtb_c4yx = 0.01F * ((real32_T)Sac_stiffness_override);
  } else if (rtb_fadn >= 0.0F) {
    /* MinMax: '<S6>/MinMax2' */
    rtb_c4yx = rtb_fadn;
  } else {
    /* MinMax: '<S6>/MinMax2' */
    rtb_c4yx = 0.0F;
  }

  /* End of Switch: '<S491>/Switch4' */

  /* ModelReference: '<S5>/LAT_Dmc_Status_Defintion3' */
  DMC_Lat_LAT_Dmc_Status_Defintion(&rtb_bhbp, &rtb_ovjx, &rtb_fzlt, &rtb_cjo4,
    rt_id5lI, rt_o3aaI, rt_bofcI, &rtb_c4yx, rt_pynyI, rt_erh2sI, rt_gd42sI,
    &rtb_b2ee, &DMC_Soc_Lat_B.LAT_Dmc_Status_Defintion3_o4, rt_ezus0I, rt_orb0mI);

  /* DataTypeConversion: '<S5>/Data Type Conversion6' */
  rtb_ef4d = (boolean_T)((int32_T)(DMC_Soc_Lat_B.LAT_Dmc_Status_Defintion3_o4 !=
                          ((int16_T)0)));

  /* MinMax: '<Root>/Max' */
  if (rtb_ >= 0.01F) {
    VEH_Vehicle_Speed = rtb_;
  } else {
    VEH_Vehicle_Speed = 0.01F;
  }

  /* End of MinMax: '<Root>/Max' */

  /* ModelReference: '<S17>/LAT_Ldp_States1' */
  DMC_Lat_LAT_Ldp_States(rt_jus1I, &rtb_ef4d, (&(LDP_Active)), &rtb_pkm5,
    &rtb_h0p5, &rtb_jomt, &rtb_gtaj, &rtb_cec3,
    &(DMC_Soc_Lat_DWork.LAT_Ldp_States1_DWORK1.rtdw));

  /* UnitDelay: '<S2>/Unit Delay2' */
  rtb_fzlt = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ee5c;

  /* Logic: '<S2>/Logical Operator1' incorporates:
   *  Logic: '<S2>/Logical Operator2'
   */
  rtb_fckq = (boolean_T)((int32_T)(((int32_T)rtb_fzlt) && (!(*rt_pynyI))));

  /* UnitDelay: '<S2>/Unit Delay3' */
  rtb_fzlt = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_oowh;

  /* Logic: '<S2>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S2>/Relational Operator'
   */
  rtb_pyzc = (boolean_T)((int32_T)((((int32_T)(*rt_p4gfI)) || ((int32_T)rtb_fckq))
    || (rtb_ef4d != rtb_fzlt)));

  /* UnitDelay: '<S2>/Unit Delay' */
  rtb_azal = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_i4w1;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtb_fzlt = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b22d;

  /* Logic: '<S2>/Logical Operator' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_fzlt = (boolean_T)((int32_T)((((int32_T)rtb_pyzc) || ((int32_T)
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_i4w1)) || ((int32_T)rtb_fzlt)));

  /* ModelReference: '<Root>/LAT_Kappa_Filter' */
  DMC_Lat_LAT_Kappa_Filter(rt_gd42I, &rtb_ef4d, (&(VEH_Vehicle_Speed)), rt_ngfdI,
                           (&(LDP_Active)), &rtb_fzlt, &rtb_maat, rt_dptqI,
    &rtb_kxln);

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_fadn = DMC_Soc_Lat_DWork.UnitDelay_DSTATE;

  /* Sum: '<S4>/Add' incorporates:
   *  Sum: '<S4>/Add1'
   */
  rtb_e4ku = ((*rt_cpaoI) - rtb_fadn) + rtb_fadn;

  /* ModelReference: '<S5>/LAT_Kinematic_Signals_Arbiter' */
  DMC_Soc_Lat_LAT_Kinematic_Signals_Arbiter((&(SAC_Controller_Mode_Sig)),
    &rtb_e1oo, &DMC_Soc_Lat_ConstP.pooled4, rt_ngfdI, rt_e4hoI, &rtb_kxln,
    &rtb_e4ku, rt_f3r3I, rt_kkebI, rt_e45jI, rt_mcq4I,
    &DMC_Soc_Lat_ConstP.pooled4, &DMC_Soc_Lat_ConstP.pooled4,
    &DMC_Soc_Lat_ConstP.pooled4, &rtb_euvg, &rtb_fgeh, (&(LKC_Kappa_Command_Arb)),
    (&(LKC_Kappa_Dot_Command_Arb)), &rtb_ojre, &rtb_jhwo, &rtb_ghy4);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  LAT_Delta_Ys = rtb_euvg;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  LAT_Delta_Psi = rtb_fgeh;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  LAT_Kappa_Command = LKC_Kappa_Command_Arb;

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  *rt_cpaomI = LKC_Kappa_Dot_Command_Arb;

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  rtb_dzi1 = (uint8_T)(*rt_a5xsI);

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_fadn = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_jsby;

  /* DataTypeConversion: '<S1>/Data Type Conversion14' incorporates:
   *  Constant: '<S1>/Lat_delta_f_dot_filter_coeff'
   */
  rtb_axf1 = ((real32_T)Lat_delta_f_dot_filter_coeff) * 3.05175781E-5F;

  /* Sum: '<S1>/Add' incorporates:
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add1'
   */
  rtb_jhzt = (((*rt_eltpI) - rtb_fadn) * rtb_axf1) + rtb_fadn;

  /* UnitDelay: '<S5>/Alg_Loop1' */
  rtb_f3ae = DMC_Soc_Lat_DWork.Alg_Loop1_DSTATE;

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  LAT_Delta_Ys_dbg = (int16_T)((real32_T)floor(rtb_euvg / 0.001F));

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  rtb_i4mt = (uint16_T)(*rt_gd42sI);

  /* Switch: '<S13>/Switch1' */
  if ((int32_T)rtb_b2ee) {
    /* MinMax: '<S9>/MinMax2' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_fadn = 1.0F;
  } else {
    /* MinMax: '<S9>/MinMax2' incorporates:
     *  Constant: '<S13>/Constant1'
     */
    rtb_fadn = 0.0F;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S13>/Constant2'
   *  Constant: '<S13>/Constant3'
   */
  if (DMC_Soc_Lat_B.Switch5 != ((int16_T)0)) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Gain: '<S13>/Gain2' */
  rtb_e1oo = 2.0F * rtb_axf1;

  /* Switch: '<S13>/Switch3' incorporates:
   *  Constant: '<S13>/Constant4'
   *  Constant: '<S13>/Constant5'
   */
  if (((int32_T)(*rt_orb0mI)) != ((int32_T)0)) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch3' */

  /* Gain: '<S13>/Gain3' */
  rtb_n4jt = 4.0F * rtb_axf1;

  /* Switch: '<S13>/Switch4' incorporates:
   *  Constant: '<S13>/Constant6'
   *  Constant: '<S13>/Constant7'
   */
  if (((int32_T)(*rt_ezus0I)) != ((int32_T)0)) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch4' */

  /* Gain: '<S13>/Gain4' */
  rtb_dpeo = 8.0F * rtb_axf1;

  /* Switch: '<S13>/Switch5' incorporates:
   *  Constant: '<S13>/Constant8'
   *  Constant: '<S13>/Constant9'
   */
  if ((int32_T)rtb_ef4d) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch5' */

  /* Gain: '<S13>/Gain5' */
  rtb_jwxe = 16.0F * rtb_axf1;

  /* Switch: '<S13>/Switch6' incorporates:
   *  Constant: '<S13>/Constant10'
   *  Constant: '<S13>/Constant11'
   */
  if ((*rt_gd42sI) != ((int16_T)0)) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch6' */

  /* Gain: '<S13>/Gain6' */
  rtb_ojsl = 32.0F * rtb_axf1;

  /* Switch: '<S13>/Switch7' incorporates:
   *  Constant: '<S13>/Constant12'
   *  Constant: '<S13>/Constant13'
   */
  if ((int32_T)(*rt_p4gfI)) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch7' */

  /* Gain: '<S13>/Gain7' */
  rtb_pnn5 = 64.0F * rtb_axf1;

  /* Logic: '<S15>/Logical Operator' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  RelationalOperator: '<S15>/Relational Operator'
   *  S-Function (sfix_bitop): '<S15>/Bitwise Operator1'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  rtb_ovjx = (boolean_T)((int32_T)((DMC_Soc_Lat_DWork.UnitDelay_DSTATE_abtt != (*
    rt_dzorI)) && ((((int32_T)Dmc_configuration_mode_2) & ((int32_T)32)) !=
                   ((int32_T)0))));

  /* Switch: '<S13>/Switch8' incorporates:
   *  Constant: '<S13>/Constant14'
   *  Constant: '<S13>/Constant15'
   */
  if ((int32_T)rtb_ovjx) {
    rtb_axf1 = 1.0F;
  } else {
    rtb_axf1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch8' */

  /* Gain: '<S13>/Gain8' */
  rtb_m3dz = 128.0F * rtb_axf1;

  /* UnitDelay: '<S27>/Unit Delay' */
  rtb_axf1 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kyvd;

  /* Sum: '<S27>/Add' incorporates:
   *  Constant: '<S26>/Lat_pitch_filter_coeff'
   *  Product: '<S27>/Product'
   *  Sum: '<S27>/Add1'
   */
  rtb_mdfx = (((*rt_ido5I) - rtb_axf1) * (((real32_T)Lat_pitch_filter_coeff) *
    3.05175781E-5F)) + rtb_axf1;

  /* Sum: '<S26>/Add2' */
  rtb_axf1 = (*rt_ido5I) - rtb_mdfx;

  /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
   *  Abs: '<S26>/Abs1'
   *  Constant: '<S26>/Lat_pitch_threshold'
   */
  rtb_bhbp = (boolean_T)((int32_T)(((real32_T)fabs((real_T)rtb_axf1)) >
    (((real32_T)Lat_pitch_threshold) * 0.0009765625F)));

  /* Logic: '<S25>/Logical Operator4' incorporates:
   *  Constant: '<S25>/Lat_pitch_max_accuracy'
   *  RelationalOperator: '<S25>/Relational Operator1'
   *  UnitDelay: '<S15>/Alg loop1'
   */
  rtb_bhbp = (boolean_T)((int32_T)(((int32_T)rtb_bhbp) &&
    (DMC_Soc_Lat_DWork.Algloop1_DSTATE <= ((real32_T)Lat_pitch_max_accuracy))));

  /* Switch: '<S13>/Switch9' incorporates:
   *  Constant: '<S13>/Constant16'
   *  Constant: '<S13>/Constant17'
   */
  if ((int32_T)rtb_bhbp) {
    rtb_h0la = 1.0F;
  } else {
    rtb_h0la = 0.0F;
  }

  /* End of Switch: '<S13>/Switch9' */

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  Gain: '<S13>/Gain9'
   *  Sum: '<S13>/Add'
   */
  rtb_fadn = (((((((rtb_fadn + rtb_e1oo) + rtb_n4jt) + rtb_dpeo) + rtb_jwxe) +
                rtb_ojsl) + rtb_pnn5) + rtb_m3dz) + (256.0F * rtb_h0la);

  /* DataTypeConversion: '<S5>/Data Type Conversion2' */
  LAT_Gen_Purpose_dbg = (int16_T)((real32_T)floor(rtb_fadn));

  /* DataTypeConversion: '<S5>/Data Type Conversion3' */
  LAT_Delta_Psi_dbg = (int16_T)((real32_T)floor(rtb_fgeh * 1024.0F));

  /* DataTypeConversion: '<S5>/Data Type Conversion5' */
  LAT_Kappa_Command_dbg = (int16_T)((real32_T)floor(LKC_Kappa_Command_Arb /
    2.0E-5F));

  /* Logic: '<S15>/Logical Operator4' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  DataTypeConversion: '<S15>/Data Type Conversion1'
   *  DataTypeConversion: '<S15>/Data Type Conversion4'
   *  Logic: '<S15>/Logical Operator2'
   *  S-Function (sfix_bitop): '<S15>/Bitwise Operator2'
   *  S-Function (sfix_bitop): '<S15>/Bitwise Operator5'
   */
  rtb_ji32 = (boolean_T)((int32_T)(((((int32_T)Dmc_configuration_mode_2) &
    ((int32_T)64)) != ((int32_T)0)) && (((((int32_T)((uint16_T)rtb_b1op)) &
    ((int32_T)2)) != ((int32_T)0)) || ((int32_T)(*rt_p4gfI)))));

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S15>/Constant5'
   *  Constant: '<S15>/Constant6'
   */
  if ((int32_T)rtb_ji32) {
    rtb_futb = (int16_T)1;
  } else {
    rtb_futb = (int16_T)0;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant3'
   *  Constant: '<S15>/Constant4'
   */
  if ((int32_T)rtb_ovjx) {
    rtb_b1op = (int16_T)2;
  } else {
    rtb_b1op = (int16_T)0;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant2'
   */
  if ((int32_T)rtb_bhbp) {
    rtb_knky = (int16_T)4;
  } else {
    rtb_knky = (int16_T)0;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Sum: '<S15>/Add' */
  rtb_futb = (int16_T)((rtb_futb + rtb_b1op) + rtb_knky);

  /* Logic: '<S15>/Logical Operator3' */
  rtb_eib2 = (boolean_T)((int32_T)((((int32_T)rtb_ji32) || ((int32_T)rtb_ovjx)) ||
                          ((int32_T)rtb_bhbp)));

  /* DataTypeConversion: '<S15>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   *  Gain: '<S15>/Gain'
   *  Sum: '<S15>/Add1'
   */
  LAT_Debug6_dbg = (int16_T)(((rtb_eib2 << 13) + (rtb_futb << 14)) >> 3);

  /* DataTypeConversion: '<S26>/Data Type Conversion' */
  LAT_Pitch_Angle_Deviation_dbg = (int16_T)((real32_T)floor(rtb_axf1 * 32768.0F));

  /* UnitDelay: '<S17>/Alg loop' */
  rtb_ghz1 = DMC_Soc_Lat_DWork.Algloop_DSTATE;

  /* UnitDelay: '<S17>/Alg loop1' */
  rtb_lhxj = DMC_Soc_Lat_DWork.Algloop1_DSTATE_jnar;

  /* UnitDelay: '<S17>/Alg loop2' */
  rtb_fz0g = DMC_Soc_Lat_DWork.Algloop2_DSTATE;

  /* UnitDelay: '<S17>/Alg loop3' */
  rtb_llyj = DMC_Soc_Lat_DWork.Algloop3_DSTATE;

  /* UnitDelay: '<S17>/Alg loop4' */
  rtb_ofyg = DMC_Soc_Lat_DWork.Algloop4_DSTATE;

  /* UnitDelay: '<S17>/Alg loop5' */
  rtb_ccsn = DMC_Soc_Lat_DWork.Algloop5_DSTATE;

  /* UnitDelay: '<S17>/Alg loop6' */
  rtb_f4hc = DMC_Soc_Lat_DWork.Algloop6_DSTATE;

  /* DataTypeConversion: '<S17>/Data Type Conversion' */
  LKC_Lane_Status_dbg = (int16_T)rtb_cec3;

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  Gain: '<S17>/Gain1'
   */
  rtb_fadn = (real32_T)(*rt_jus1I);

  /* DataTypeConversion: '<S17>/Data Type Conversion2' */
  *rt_kaadaI = (uint8_T)rtb_fadn;

  /* Logic: '<S17>/Logical Operator3' */
  SAC_Disable = !rtb_ef4d;

  /* UnitDelay: '<S29>/Alg_Loop_Delay23' */
  rtb_idqr = DMC_Soc_Lat_DWork.Alg_Loop_Delay23_DSTATE;

  /* Outputs for Atomic SubSystem: '<S35>/Steering_Characteristic_Correction_Factor' */
  /* Outputs for Atomic SubSystem: '<S137>/Lateral_Error_Validity_Check ' */
  /* RelationalOperator: '<S162>/Relational Operator1' */
  rtb_fsbi = (boolean_T)((int32_T)((*rt_i3p3I) >= ((int16_T)1)));

  /* End of Outputs for SubSystem: '<S137>/Lateral_Error_Validity_Check ' */

  /* Outputs for Atomic SubSystem: '<S137>/Error_Side_And_Desired_Driving_Curve_Detection' */
  /* Outputs for Atomic SubSystem: '<S161>/Mean_Calculator' */
  /* Logic: '<S182>/Logical Operator1' */
  rtb_fckq = (boolean_T)((int32_T)(!rtb_fsbi));

  /* Outputs for Atomic SubSystem: '<S182>/Mean_Of_Segment' */
  /* Logic: '<S185>/Logical Operator' incorporates:
   *  UnitDelay: '<S185>/Unit Delay2'
   */
  rtb_ohj2 = (boolean_T)((int32_T)(((int32_T)
    DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq) || ((int32_T)rtb_fckq)));

  /* Delay: '<S185>/Resettable Delay1' */
  if ((int32_T)rtb_ohj2) {
    DMC_Soc_Lat_DWork.ResettableDelay1_DSTATE = 0.0F;
  }

  /* Switch: '<S185>/Switch1' incorporates:
   *  Constant: '<S185>/Constant2'
   */
  if ((int32_T)rtb_fckq) {
    rtb_jwxe = 0.0F;
  } else {
    rtb_jwxe = *rt_p2o1I;
  }

  /* End of Switch: '<S185>/Switch1' */

  /* Sum: '<S185>/Add1' incorporates:
   *  Delay: '<S185>/Resettable Delay1'
   */
  DMC_Soc_Lat_DWork.ResettableDelay1_DSTATE += rtb_jwxe;

  /* Delay: '<S185>/Resettable Delay' */
  if ((int32_T)rtb_ohj2) {
    DMC_Soc_Lat_DWork.ResettableDelay_DSTATE = 0U;
  }

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S185>/Constant1'
   *  Constant: '<S185>/Constant3'
   */
  if ((int32_T)rtb_fckq) {
    rtb_mxcu = 0U;
  } else {
    rtb_mxcu = 1U;
  }

  /* End of Switch: '<S185>/Switch' */

  /* Sum: '<S185>/Add2' incorporates:
   *  Delay: '<S185>/Resettable Delay'
   */
  DMC_Soc_Lat_DWork.ResettableDelay_DSTATE = (uint8_T)(((uint32_T)
    DMC_Soc_Lat_DWork.ResettableDelay_DSTATE) + ((uint32_T)rtb_mxcu));

  /* Delay: '<S185>/Resettable Delay2' */
  if ((int32_T)rtb_ohj2) {
    DMC_Soc_Lat_DWork.ResettableDelay2_DSTATE = 0.0F;
  }

  /* Sum: '<S185>/Add3' incorporates:
   *  Delay: '<S185>/Resettable Delay2'
   */
  DMC_Soc_Lat_DWork.ResettableDelay2_DSTATE += LKC_Kappa_Command_Arb;

  /* Delay: '<S185>/Resettable Delay3' */
  if ((int32_T)rtb_ohj2) {
    DMC_Soc_Lat_DWork.ResettableDelay3_DSTATE = 0.0F;
  }

  /* Sum: '<S185>/Add4' incorporates:
   *  Delay: '<S185>/Resettable Delay3'
   */
  DMC_Soc_Lat_DWork.ResettableDelay3_DSTATE += VEH_Vehicle_Speed;

  /* MinMax: '<S185>/MinMax' */
  if (((int32_T)DMC_Soc_Lat_DWork.ResettableDelay_DSTATE) >= ((int32_T)1)) {
    rtb_mxcu = DMC_Soc_Lat_DWork.ResettableDelay_DSTATE;
  } else {
    rtb_mxcu = 1U;
  }

  /* End of MinMax: '<S185>/MinMax' */

  /* RelationalOperator: '<S185>/Relational Operator' incorporates:
   *  Constant: '<S185>/Number_of_Items_In_Sample'
   */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq = (boolean_T)((int32_T)
    (DMC_Soc_Lat_DWork.ResettableDelay_DSTATE >= Acf_no_of_items_in_sample));

  /* Switch: '<S185>/Switch2' incorporates:
   *  Product: '<S185>/Divide'
   */
  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_buoy =
      DMC_Soc_Lat_DWork.ResettableDelay1_DSTATE / ((real32_T)rtb_mxcu);
  }

  /* End of Switch: '<S185>/Switch2' */

  /* Switch: '<S185>/Switch3' incorporates:
   *  Product: '<S185>/Divide1'
   *  UnitDelay: '<S185>/Unit Delay1'
   */
  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq) {
    Mean_Kappa_Command = DMC_Soc_Lat_DWork.ResettableDelay2_DSTATE / ((real32_T)
      rtb_mxcu);
  } else {
    Mean_Kappa_Command = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b4na;
  }

  /* End of Switch: '<S185>/Switch3' */

  /* Switch: '<S185>/Switch4' incorporates:
   *  Product: '<S185>/Divide2'
   *  UnitDelay: '<S185>/Unit Delay3'
   */
  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq) {
    Mean_Vehicle_Velocity = DMC_Soc_Lat_DWork.ResettableDelay3_DSTATE /
      ((real32_T)rtb_mxcu);
  } else {
    Mean_Vehicle_Velocity = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ieks;
  }

  /* End of Switch: '<S185>/Switch4' */

  /* Update for UnitDelay: '<S185>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b4na = Mean_Kappa_Command;

  /* Update for UnitDelay: '<S185>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ieks = Mean_Vehicle_Velocity;

  /* End of Outputs for SubSystem: '<S182>/Mean_Of_Segment' */

  /* Outputs for Enabled SubSystem: '<S182>/Mean_Of_All_Segments' incorporates:
   *  EnablePort: '<S184>/Enable'
   */
  /* Logic: '<S182>/Logical Operator2' */
  if (((int32_T)rtb_fckq) || ((int32_T)DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq))
  {
    /* Delay: '<S184>/Item_1' */
    if ((int32_T)rtb_fckq) {
      DMC_Soc_Lat_DWork.Item_1_DSTATE = 0.0F;
    }

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/Constant1'
     */
    if ((int32_T)rtb_fckq) {
      rtb_e1oo = 0.0F;
    } else {
      rtb_e1oo = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_buoy;
    }

    /* End of Switch: '<S184>/Switch' */

    /* Delay: '<S184>/Item_2' */
    if ((int32_T)rtb_fckq) {
      DMC_Soc_Lat_DWork.Item_2_DSTATE = 0.0F;
    }

    rtb_n4jt = DMC_Soc_Lat_DWork.Item_2_DSTATE;

    /* Delay: '<S184>/Item_3' */
    if ((int32_T)rtb_fckq) {
      DMC_Soc_Lat_DWork.Item_3_DSTATE = 0.0F;
    }

    rtb_dpeo = DMC_Soc_Lat_DWork.Item_3_DSTATE;

    /* Delay: '<S184>/Item_4' */
    if ((int32_T)rtb_fckq) {
      DMC_Soc_Lat_DWork.Item_4_DSTATE = 0.0F;
    }

    rtb_jwxe = DMC_Soc_Lat_DWork.Item_4_DSTATE;

    /* Delay: '<S184>/Item_5' */
    if ((int32_T)rtb_fckq) {
      DMC_Soc_Lat_DWork.Item_5_DSTATE = 0.0F;
    }

    /* Delay: '<S184>/Count' incorporates:
     *  Constant: '<S184>/Constant4'
     */
    if ((int32_T)rtb_fckq) {
      DMC_Soc_Lat_DWork.icLoad = 1U;
    }

    if (((int32_T)DMC_Soc_Lat_DWork.icLoad) != ((int32_T)0)) {
      DMC_Soc_Lat_DWork.Count_DSTATE = 1U;
    }

    /* Switch: '<S186>/Switch' incorporates:
     *  Constant: '<S186>/Constant'
     *  Delay: '<S184>/Count'
     *  RelationalOperator: '<S186>/Relational Operator'
     */
    if (((real_T)DMC_Soc_Lat_DWork.Count_DSTATE) <= 0.01) {
      rtb_ergg = 0.01;
    } else {
      rtb_ergg = (real_T)DMC_Soc_Lat_DWork.Count_DSTATE;
    }

    /* End of Switch: '<S186>/Switch' */

    /* Product: '<S184>/Divide' incorporates:
     *  Delay: '<S184>/Item_2'
     *  Delay: '<S184>/Item_3'
     *  Delay: '<S184>/Item_4'
     *  Delay: '<S184>/Item_5'
     *  Sum: '<S184>/Add1'
     */
    CAM_Lateral_Error_Mean = (real32_T)(((((rtb_e1oo +
      DMC_Soc_Lat_DWork.Item_2_DSTATE) + DMC_Soc_Lat_DWork.Item_3_DSTATE) +
      DMC_Soc_Lat_DWork.Item_4_DSTATE) + DMC_Soc_Lat_DWork.Item_5_DSTATE) /
      rtb_ergg);

    /* Sum: '<S184>/Add' incorporates:
     *  Delay: '<S184>/Item_1'
     */
    CAM_Lateral_Error_Delta = CAM_Lateral_Error_Mean -
      DMC_Soc_Lat_DWork.Item_1_DSTATE;

    /* Signum: '<S184>/Sign' */
    if (CAM_Lateral_Error_Mean < 0.0F) {
      rtb_ojsl = -1.0F;
    } else if (CAM_Lateral_Error_Mean > 0.0F) {
      rtb_ojsl = 1.0F;
    } else {
      rtb_ojsl = CAM_Lateral_Error_Mean;
    }

    /* DataTypeConversion: '<S184>/Data Type Conversion' incorporates:
     *  Signum: '<S184>/Sign'
     */
    DMC_Soc_Lat_B.DataTypeConversion = (int8_T)rtb_ojsl;

    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S184>/Constant2'
     *  Delay: '<S184>/Count'
     *  RelationalOperator: '<S184>/Relational Operator1'
     */
    if (((int32_T)DMC_Soc_Lat_DWork.Count_DSTATE) < ((int32_T)5)) {
      /* Update for Delay: '<S184>/Count' incorporates:
       *  Constant: '<S184>/Constant3'
       *  Sum: '<S184>/Sum'
       */
      DMC_Soc_Lat_DWork.Count_DSTATE++;
    }

    /* End of Switch: '<S184>/Switch2' */

    /* Update for Delay: '<S184>/Item_1' */
    DMC_Soc_Lat_DWork.Item_1_DSTATE = CAM_Lateral_Error_Mean;

    /* Update for Delay: '<S184>/Item_2' */
    DMC_Soc_Lat_DWork.Item_2_DSTATE = rtb_e1oo;

    /* Update for Delay: '<S184>/Item_3' */
    DMC_Soc_Lat_DWork.Item_3_DSTATE = rtb_n4jt;

    /* Update for Delay: '<S184>/Item_4' */
    DMC_Soc_Lat_DWork.Item_4_DSTATE = rtb_dpeo;

    /* Update for Delay: '<S184>/Item_5' */
    DMC_Soc_Lat_DWork.Item_5_DSTATE = rtb_jwxe;

    /* Update for Delay: '<S184>/Count' */
    DMC_Soc_Lat_DWork.icLoad = 0U;
  }

  /* End of Logic: '<S182>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S182>/Mean_Of_All_Segments' */
  /* End of Outputs for SubSystem: '<S161>/Mean_Calculator' */

  /* Outputs for Atomic SubSystem: '<S161>/Turn_And_Lateral_Error_Side_Direction' */
  /* RelationalOperator: '<S195>/Compare' incorporates:
   *  Constant: '<S195>/Constant'
   */
  rtb_fckq = (boolean_T)((int32_T)(CAM_Lateral_Error_Mean != 0.0F));

  /* Switch: '<S183>/Switch3' incorporates:
   *  Constant: '<S183>/Default'
   *  Constant: '<S183>/Right_Turn_Right_Error'
   *  Constant: '<S193>/Constant'
   *  Constant: '<S194>/Constant'
   *  Logic: '<S183>/Logical Operator3'
   *  RelationalOperator: '<S193>/Compare'
   *  RelationalOperator: '<S194>/Compare'
   */
  if ((((int32_T)rtb_fckq) && (DMC_Soc_Lat_B.DataTypeConversion == ((int8_T)1)))
      && (Mean_Kappa_Command < 0.0F)) {
    Turn_And_Error_Side = 4U;
  } else {
    Turn_And_Error_Side = 0U;
  }

  /* End of Switch: '<S183>/Switch3' */

  /* Switch: '<S183>/Switch2' incorporates:
   *  Constant: '<S183>/Right_Turn_Left_Error'
   *  Constant: '<S191>/Constant'
   *  Constant: '<S192>/Constant'
   *  Logic: '<S183>/Logical Operator2'
   *  RelationalOperator: '<S191>/Compare'
   *  RelationalOperator: '<S192>/Compare'
   */
  if ((((int32_T)rtb_fckq) && (DMC_Soc_Lat_B.DataTypeConversion == ((int8_T)-1)))
      && (Mean_Kappa_Command < 0.0F)) {
    Turn_And_Error_Side = 3U;
  }

  /* End of Switch: '<S183>/Switch2' */

  /* Switch: '<S183>/Switch1' incorporates:
   *  Constant: '<S183>/Left_Turn_Right_Error'
   *  Constant: '<S189>/Constant'
   *  Constant: '<S190>/Constant'
   *  Logic: '<S183>/Logical Operator1'
   *  RelationalOperator: '<S189>/Compare'
   *  RelationalOperator: '<S190>/Compare'
   */
  if ((((int32_T)rtb_fckq) && (DMC_Soc_Lat_B.DataTypeConversion == ((int8_T)1)))
      && (Mean_Kappa_Command > 0.0F)) {
    Turn_And_Error_Side = 2U;
  }

  /* End of Switch: '<S183>/Switch1' */

  /* Switch: '<S183>/Switch' incorporates:
   *  Constant: '<S183>/Left_Turn_Left_Error'
   *  Constant: '<S187>/Constant'
   *  Constant: '<S188>/Constant'
   *  Logic: '<S183>/Logical Operator'
   *  RelationalOperator: '<S187>/Compare'
   *  RelationalOperator: '<S188>/Compare'
   */
  if ((((int32_T)rtb_fckq) && (DMC_Soc_Lat_B.DataTypeConversion == ((int8_T)-1)))
      && (Mean_Kappa_Command > 0.0F)) {
    Turn_And_Error_Side = 1U;
  }

  /* End of Switch: '<S183>/Switch' */
  /* End of Outputs for SubSystem: '<S161>/Turn_And_Lateral_Error_Side_Direction' */
  /* End of Outputs for SubSystem: '<S137>/Error_Side_And_Desired_Driving_Curve_Detection' */

  /* Outputs for Atomic SubSystem: '<S137>/Algorithm_Parameter' */
  /* Gain: '<S159>/Gain' */
  rtb_pnn5 = 3.6F * VEH_Vehicle_Speed;

  /* Outputs for Atomic SubSystem: '<S159>/Increase_Reduction_Factor_Computation' */
  /* Abs: '<S168>/Abs1' */
  rtb_dpeo = (real32_T)fabs((real_T)(*rt_igqzI));

  /* Sum: '<S168>/Add' incorporates:
   *  Abs: '<S168>/Abs'
   *  Constant: '<S137>/Min_th_lateral_error'
   */
  rtb_e1oo = ((real32_T)fabs((real_T)CAM_Lateral_Error_Mean)) - 0.05F;

  /* MinMax: '<S168>/MinMax' */
  if (rtb_e1oo >= 0.0F) {
  } else {
    rtb_e1oo = 0.0F;
  }

  /* End of MinMax: '<S168>/MinMax' */

  /* Product: '<S168>/Product' incorporates:
   *  Constant: '<S168>/Lateral_Error_Slope_For_Factor_Increase'
   */
  rtb_jwxe = (((real32_T)Acf_slop_lateral_error_fact_inc) * 0.0009765625F) *
    rtb_e1oo;

  /* MinMax: '<S168>/MinMax1' */
  if (rtb_jwxe <= 1.0F) {
  } else {
    rtb_jwxe = 1.0F;
  }

  /* End of MinMax: '<S168>/MinMax1' */

  /* Product: '<S168>/Product4' incorporates:
   *  Constant: '<S168>/Lateral_Error_Slope_For_Factor_Decrease'
   */
  rtb_e1oo *= ((real32_T)Acf_slop_lateral_error_fact_dec) * 0.0009765625F;

  /* MinMax: '<S168>/MinMax2' */
  if (rtb_e1oo <= 1.0F) {
  } else {
    rtb_e1oo = 1.0F;
  }

  /* End of MinMax: '<S168>/MinMax2' */

  /* Sum: '<S168>/Add4' incorporates:
   *  Product: '<S168>/Product6'
   */
  rtb_n4jt = rtb_e1oo;

  /* Lookup_n-D: '<S168>/Factor_Decrease_Scheduling' */
  rtb_e1oo = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_pnn5,
    (&(Adp_dyc_corr_fact_dec_x_sched[0])), (&(Adp_dyc_corr_fact_dec_y_sched[0])),
    11U);

  /* Lookup_n-D: '<S168>/Factor_Incease_Scheduling' */
  rtb_ojsl = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_pnn5,
    (&(Adp_dyc_corr_fact_inc_x_sched[0])), (&(Adp_dyc_corr_fact_inc_y_sched[0])),
    11U);

  /* Sum: '<S168>/Add6' incorporates:
   *  Constant: '<S168>/Constant3'
   *  Constant: '<S168>/Road_Gradient_Slope_For_Factor_Decrease'
   *  Product: '<S168>/Product10'
   */
  rtb_m3dz = 1.0F - (rtb_dpeo * (((real32_T)Acf_slop_road_gradient_fact_dec) *
    0.0009765625F));

  /* MinMax: '<S168>/MinMax5' */
  if (rtb_m3dz >= 0.0F) {
  } else {
    rtb_m3dz = 0.0F;
  }

  /* MinMax: '<S168>/MinMax6' incorporates:
   *  MinMax: '<S168>/MinMax5'
   */
  if (1.0F <= rtb_m3dz) {
    rtb_m3dz = 1.0F;
  }

  /* Product: '<S168>/Product11' incorporates:
   *  MinMax: '<S168>/MinMax5'
   *  MinMax: '<S168>/MinMax6'
   *  Product: '<S168>/Product7'
   */
  Factor_Decrease = rtb_m3dz * (rtb_n4jt * rtb_e1oo);

  /* Sum: '<S168>/Add5' incorporates:
   *  Constant: '<S168>/Constant2'
   *  Constant: '<S168>/Road_Gradient_Slope_For_Factor_Increase'
   *  Product: '<S168>/Product8'
   */
  rtb_m3dz = 1.0F - (rtb_dpeo * (((real32_T)Acf_slop_road_gradient_fact_inc) *
    0.0009765625F));

  /* MinMax: '<S168>/MinMax3' */
  if (rtb_m3dz >= 0.0F) {
  } else {
    rtb_m3dz = 0.0F;
  }

  /* MinMax: '<S168>/MinMax4' incorporates:
   *  MinMax: '<S168>/MinMax3'
   */
  if (1.0F <= rtb_m3dz) {
    rtb_m3dz = 1.0F;
  }

  /* Product: '<S168>/Product9' incorporates:
   *  MinMax: '<S168>/MinMax3'
   *  MinMax: '<S168>/MinMax4'
   *  Product: '<S168>/Product2'
   *  Product: '<S168>/Product3'
   */
  Factor_Increase = (rtb_ojsl * rtb_jwxe) * rtb_m3dz;

  /* End of Outputs for SubSystem: '<S159>/Increase_Reduction_Factor_Computation' */

  /* Outputs for Atomic SubSystem: '<S159>/Maximum_Waiting_Counter_Computation' */
  /* Product: '<S169>/Product4' incorporates:
   *  Abs: '<S169>/Abs'
   *  Constant: '<S169>/Cuvature_Command_Slope_For_Waiting_Counter'
   */
  rtb_e1oo = ((real32_T)fabs((real_T)LKC_Kappa_Command_Arb)) * 120.0F;

  /* MinMax: '<S169>/MinMax' */
  if (rtb_e1oo >= 0.0F) {
  } else {
    rtb_e1oo = 0.0F;
  }

  /* MinMax: '<S169>/MinMax2' incorporates:
   *  MinMax: '<S169>/MinMax'
   */
  if (1.0F <= rtb_e1oo) {
    rtb_e1oo = 1.0F;
  }

  /* End of MinMax: '<S169>/MinMax2' */

  /* Product: '<S169>/Product1' */
  rtb_n4jt = rtb_e1oo;

  /* Product: '<S169>/Product2' incorporates:
   *  Constant: '<S169>/Constant'
   *  Constant: '<S169>/Max_Factor_For_Waiting_Counter'
   *  Sum: '<S169>/Add'
   */
  rtb_dpeo = (1.0F - rtb_e1oo) * 1.2F;

  /* Lookup_n-D: '<S169>/Maximum_Waiting_Counter_Scheduling' */
  rtb_e1oo = look1_iflf_binlc(rtb_pnn5,
    DMC_Soc_Lat_ConstP.Maximum_Waiting_Counter_Scheduling_bp01Data,
    DMC_Soc_Lat_ConstP.Maximum_Waiting_Counter_Scheduling_tableData, 8U);

  /* Product: '<S169>/Product3' incorporates:
   *  Sum: '<S169>/Add1'
   */
  rtb_e1oo *= rtb_n4jt + rtb_dpeo;

  /* DataTypeConversion: '<S169>/Data Type Conversion1' */
  Maximum_Waiting_Counter = (uint16_T)rtb_e1oo;

  /* End of Outputs for SubSystem: '<S159>/Maximum_Waiting_Counter_Computation' */
  /* End of Outputs for SubSystem: '<S137>/Algorithm_Parameter' */

  /* Sum: '<S163>/Add1' incorporates:
   *  Constant: '<S163>/Veh_Lat_Acc_Filter_Coeff'
   *  Product: '<S163>/Product'
   *  Sum: '<S163>/Add'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_olvg += ((*rt_gyqsI) -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_olvg) * 0.95F;

  /* Outputs for Atomic SubSystem: '<S137>/Read_EEPROM_Correction_Factor' */
  /* UnitDelay: '<S165>/Unit Delay' */
  rtb_bcax = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj;

  /* Outputs for Enabled SubSystem: '<S165>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S199>/Enable'
   */
  /* Logic: '<S165>/Logical Operator' incorporates:
   *  Constant: '<S199>/Constant2'
   *  UnitDelay: '<S165>/Unit Delay'
   */
  if (!DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj) {
    DMC_Soc_Lat_B.Constant2 = (boolean_T)true;
  }

  /* End of Logic: '<S165>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S165>/Enabled Subsystem' */

  /* Logic: '<S165>/Logical Operator1' incorporates:
   *  Constant: '<S198>/Constant'
   *  Constant: '<S35>/Dyc_compensation_mode (1)'
   *  Logic: '<S165>/Logical Operator2'
   *  RelationalOperator: '<S198>/Compare'
   *  S-Function (sfix_bitop): '<S165>/Bitwise Operator2'
   */
  rtb_fckq = (boolean_T)((int32_T)(((((int32_T)Dyc_compensation_mode) &
    ((int32_T)4096)) == ((int32_T)4096)) && (!(*rt_hs5jI))));

  /* Switch: '<S165>/Switch' */
  if ((int32_T)rtb_fckq) {
    rtb_e1oo = rt_mwrrI[(int8_T)0];
    rtb_n4jt = rt_mwrrI[(int8_T)1];
    rtb_dpeo = rt_mwrrI[(int8_T)2];
    rtb_jwxe = rt_mwrrI[(int8_T)3];
    rtb_ojsl = rt_mwrrI[(int8_T)4];
    rtb_pnn5 = rt_mwrrI[(int8_T)5];
    rtb_m3dz = rt_mwrrI[(int8_T)6];
    tmp_ = rt_mwrrI[(int8_T)7];
    tmp_0 = rt_mwrrI[(int8_T)8];
    tmp_1 = rt_mwrrI[(int8_T)9];
    tmp_2 = rt_mwrrI[(int8_T)10];
    tmp_3 = rt_mwrrI[(int8_T)11];
    tmp_4 = rt_mwrrI[(int8_T)12];
    tmp_5 = rt_mwrrI[(int8_T)13];
    tmp_6 = rt_mwrrI[(int8_T)14];
    tmp_7 = rt_mwrrI[(int8_T)15];
    tmp_8 = rt_mwrrI[(int8_T)16];
    tmp_9 = rt_mwrrI[(int8_T)17];
    tmp_a = rt_mwrrI[(int8_T)18];
    tmp_b = rt_mwrrI[(int8_T)19];
  } else {
    rtb_e1oo = 1.0F;
    rtb_n4jt = 1.0F;
    rtb_dpeo = 1.0F;
    rtb_jwxe = 1.0F;
    rtb_ojsl = 1.0F;
    rtb_pnn5 = 1.0F;
    rtb_m3dz = 1.0F;
    tmp_ = 1.0F;
    tmp_0 = 1.0F;
    tmp_1 = 1.0F;
    tmp_2 = 1.0F;
    tmp_3 = 1.0F;
    tmp_4 = 1.0F;
    tmp_5 = 1.0F;
    tmp_6 = 1.0F;
    tmp_7 = 1.0F;
    tmp_8 = 1.0F;
    tmp_9 = 1.0F;
    tmp_a = 1.0F;
    tmp_b = 1.0F;
  }

  if ((int32_T)rtb_fckq) {
    tmp_c = rt_h3drI[(int8_T)0];
    tmp_d = rt_h3drI[(int8_T)1];
    tmp_e = rt_h3drI[(int8_T)2];
    tmp_f = rt_h3drI[(int8_T)3];
    tmp_g = rt_h3drI[(int8_T)4];
    tmp_h = rt_h3drI[(int8_T)5];
    tmp_i = rt_h3drI[(int8_T)6];
    tmp_j = rt_h3drI[(int8_T)7];
    tmp_k = rt_h3drI[(int8_T)8];
    tmp_l = rt_h3drI[(int8_T)9];
    tmp_m = rt_h3drI[(int8_T)10];
    tmp_n = rt_h3drI[(int8_T)11];
    tmp_o = rt_h3drI[(int8_T)12];
    tmp_p = rt_h3drI[(int8_T)13];
    tmp_q = rt_h3drI[(int8_T)14];
    tmp_r = rt_h3drI[(int8_T)15];
    tmp_s = rt_h3drI[(int8_T)16];
    tmp_t = rt_h3drI[(int8_T)17];
    tmp_u = rt_h3drI[(int8_T)18];
    tmp_v = rt_h3drI[(int8_T)19];
  } else {
    tmp_c = 1.0F;
    tmp_d = 1.0F;
    tmp_e = 1.0F;
    tmp_f = 1.0F;
    tmp_g = 1.0F;
    tmp_h = 1.0F;
    tmp_i = 1.0F;
    tmp_j = 1.0F;
    tmp_k = 1.0F;
    tmp_l = 1.0F;
    tmp_m = 1.0F;
    tmp_n = 1.0F;
    tmp_o = 1.0F;
    tmp_p = 1.0F;
    tmp_q = 1.0F;
    tmp_r = 1.0F;
    tmp_s = 1.0F;
    tmp_t = 1.0F;
    tmp_u = 1.0F;
    tmp_v = 1.0F;
  }

  /* End of Switch: '<S165>/Switch' */

  /* Switch: '<S165>/Switch1' */
  if ((int32_T)rtb_fckq) {
    tmp_w = rt_hzz5I[(int8_T)0];
    tmp_x = rt_hzz5I[(int8_T)1];
    tmp_y = rt_hzz5I[(int8_T)2];
    tmp_z = rt_hzz5I[(int8_T)3];
    tmp_10 = rt_hzz5I[(int8_T)4];
    tmp_11 = rt_hzz5I[(int8_T)5];
    tmp_12 = rt_hzz5I[(int8_T)6];
    tmp_13 = rt_hzz5I[(int8_T)7];
    tmp_14 = rt_hzz5I[(int8_T)8];
    tmp_15 = rt_hzz5I[(int8_T)9];
    tmp_16 = rt_hzz5I[(int8_T)10];
    tmp_17 = rt_hzz5I[(int8_T)11];
    tmp_18 = rt_hzz5I[(int8_T)12];
    tmp_19 = rt_hzz5I[(int8_T)13];
    tmp_1a = rt_hzz5I[(int8_T)14];
    tmp_1b = rt_hzz5I[(int8_T)15];
    tmp_1c = rt_hzz5I[(int8_T)16];
    tmp_1d = rt_hzz5I[(int8_T)17];
    tmp_1e = rt_hzz5I[(int8_T)18];
    tmp_1f = rt_hzz5I[(int8_T)19];
  } else {
    tmp_w = (uint16_T)0U;
    tmp_x = (uint16_T)0U;
    tmp_y = (uint16_T)0U;
    tmp_z = (uint16_T)0U;
    tmp_10 = (uint16_T)0U;
    tmp_11 = (uint16_T)0U;
    tmp_12 = (uint16_T)0U;
    tmp_13 = (uint16_T)0U;
    tmp_14 = (uint16_T)0U;
    tmp_15 = (uint16_T)0U;
    tmp_16 = (uint16_T)0U;
    tmp_17 = (uint16_T)0U;
    tmp_18 = (uint16_T)0U;
    tmp_19 = (uint16_T)0U;
    tmp_1a = (uint16_T)0U;
    tmp_1b = (uint16_T)0U;
    tmp_1c = (uint16_T)0U;
    tmp_1d = (uint16_T)0U;
    tmp_1e = (uint16_T)0U;
    tmp_1f = (uint16_T)0U;
  }

  if ((int32_T)rtb_fckq) {
    tmp_1g = rt_h23nI[(int8_T)0];
    tmp_1h = rt_h23nI[(int8_T)1];
    tmp_1i = rt_h23nI[(int8_T)2];
    tmp_1j = rt_h23nI[(int8_T)3];
    tmp_1k = rt_h23nI[(int8_T)4];
    tmp_1l = rt_h23nI[(int8_T)5];
    tmp_1m = rt_h23nI[(int8_T)6];
    tmp_1n = rt_h23nI[(int8_T)7];
    tmp_1o = rt_h23nI[(int8_T)8];
    tmp_1p = rt_h23nI[(int8_T)9];
    tmp_1q = rt_h23nI[(int8_T)10];
    tmp_1r = rt_h23nI[(int8_T)11];
    tmp_1s = rt_h23nI[(int8_T)12];
    tmp_1t = rt_h23nI[(int8_T)13];
    tmp_1u = rt_h23nI[(int8_T)14];
    tmp_1v = rt_h23nI[(int8_T)15];
    tmp_1w = rt_h23nI[(int8_T)16];
    tmp_1x = rt_h23nI[(int8_T)17];
    tmp_1y = rt_h23nI[(int8_T)18];
    tmp_1z = rt_h23nI[(int8_T)19];
  } else {
    tmp_1g = (uint16_T)0U;
    tmp_1h = (uint16_T)0U;
    tmp_1i = (uint16_T)0U;
    tmp_1j = (uint16_T)0U;
    tmp_1k = (uint16_T)0U;
    tmp_1l = (uint16_T)0U;
    tmp_1m = (uint16_T)0U;
    tmp_1n = (uint16_T)0U;
    tmp_1o = (uint16_T)0U;
    tmp_1p = (uint16_T)0U;
    tmp_1q = (uint16_T)0U;
    tmp_1r = (uint16_T)0U;
    tmp_1s = (uint16_T)0U;
    tmp_1t = (uint16_T)0U;
    tmp_1u = (uint16_T)0U;
    tmp_1v = (uint16_T)0U;
    tmp_1w = (uint16_T)0U;
    tmp_1x = (uint16_T)0U;
    tmp_1y = (uint16_T)0U;
    tmp_1z = (uint16_T)0U;
  }

  /* End of Switch: '<S165>/Switch1' */

  /* Switch: '<S165>/Switch2' incorporates:
   *  UnitDelay: '<S137>/Unit Delay'
   *  UnitDelay: '<S137>/Unit Delay1'
   *  UnitDelay: '<S165>/Unit Delay'
   */
  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj) {
    rtb_bqaz[(int8_T)0] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)0];
    rtb_bqaz[(int8_T)1] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)1];
    rtb_bqaz[(int8_T)2] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)2];
    rtb_bqaz[(int8_T)3] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)3];
    rtb_bqaz[(int8_T)4] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)4];
    rtb_bqaz[(int8_T)5] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)5];
    rtb_bqaz[(int8_T)6] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)6];
    rtb_bqaz[(int8_T)7] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)7];
    rtb_bqaz[(int8_T)8] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)8];
    rtb_bqaz[(int8_T)9] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)9];
    rtb_bqaz[(int8_T)10] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)10];
    rtb_bqaz[(int8_T)11] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)11];
    rtb_bqaz[(int8_T)12] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)12];
    rtb_bqaz[(int8_T)13] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)13];
    rtb_bqaz[(int8_T)14] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)14];
    rtb_bqaz[(int8_T)15] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)15];
    rtb_bqaz[(int8_T)16] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)16];
    rtb_bqaz[(int8_T)17] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)17];
    rtb_bqaz[(int8_T)18] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)18];
    rtb_bqaz[(int8_T)19] = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)19];
  } else {
    rtb_bqaz[(int8_T)0] = rtb_e1oo;
    rtb_bqaz[(int8_T)1] = rtb_n4jt;
    rtb_bqaz[(int8_T)2] = rtb_dpeo;
    rtb_bqaz[(int8_T)3] = rtb_jwxe;
    rtb_bqaz[(int8_T)4] = rtb_ojsl;
    rtb_bqaz[(int8_T)5] = rtb_pnn5;
    rtb_bqaz[(int8_T)6] = rtb_m3dz;
    rtb_bqaz[(int8_T)7] = tmp_;
    rtb_bqaz[(int8_T)8] = tmp_0;
    rtb_bqaz[(int8_T)9] = tmp_1;
    rtb_bqaz[(int8_T)10] = tmp_2;
    rtb_bqaz[(int8_T)11] = tmp_3;
    rtb_bqaz[(int8_T)12] = tmp_4;
    rtb_bqaz[(int8_T)13] = tmp_5;
    rtb_bqaz[(int8_T)14] = tmp_6;
    rtb_bqaz[(int8_T)15] = tmp_7;
    rtb_bqaz[(int8_T)16] = tmp_8;
    rtb_bqaz[(int8_T)17] = tmp_9;
    rtb_bqaz[(int8_T)18] = tmp_a;
    rtb_bqaz[(int8_T)19] = tmp_b;
  }

  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj) {
    rtb_bqaz[(int8_T)20] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)0];
    rtb_bqaz[(int8_T)21] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)1];
    rtb_bqaz[(int8_T)22] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)2];
    rtb_bqaz[(int8_T)23] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)3];
    rtb_bqaz[(int8_T)24] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)4];
    rtb_bqaz[(int8_T)25] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)5];
    rtb_bqaz[(int8_T)26] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)6];
    rtb_bqaz[(int8_T)27] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)7];
    rtb_bqaz[(int8_T)28] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)8];
    rtb_bqaz[(int8_T)29] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)9];
    rtb_bqaz[(int8_T)30] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)10];
    rtb_bqaz[(int8_T)31] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)11];
    rtb_bqaz[(int8_T)32] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)12];
    rtb_bqaz[(int8_T)33] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)13];
    rtb_bqaz[(int8_T)34] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)14];
    rtb_bqaz[(int8_T)35] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)15];
    rtb_bqaz[(int8_T)36] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)16];
    rtb_bqaz[(int8_T)37] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)17];
    rtb_bqaz[(int8_T)38] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)18];
    rtb_bqaz[(int8_T)39] = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)19];
  } else {
    rtb_bqaz[(int8_T)20] = tmp_c;
    rtb_bqaz[(int8_T)21] = tmp_d;
    rtb_bqaz[(int8_T)22] = tmp_e;
    rtb_bqaz[(int8_T)23] = tmp_f;
    rtb_bqaz[(int8_T)24] = tmp_g;
    rtb_bqaz[(int8_T)25] = tmp_h;
    rtb_bqaz[(int8_T)26] = tmp_i;
    rtb_bqaz[(int8_T)27] = tmp_j;
    rtb_bqaz[(int8_T)28] = tmp_k;
    rtb_bqaz[(int8_T)29] = tmp_l;
    rtb_bqaz[(int8_T)30] = tmp_m;
    rtb_bqaz[(int8_T)31] = tmp_n;
    rtb_bqaz[(int8_T)32] = tmp_o;
    rtb_bqaz[(int8_T)33] = tmp_p;
    rtb_bqaz[(int8_T)34] = tmp_q;
    rtb_bqaz[(int8_T)35] = tmp_r;
    rtb_bqaz[(int8_T)36] = tmp_s;
    rtb_bqaz[(int8_T)37] = tmp_t;
    rtb_bqaz[(int8_T)38] = tmp_u;
    rtb_bqaz[(int8_T)39] = tmp_v;
  }

  /* End of Switch: '<S165>/Switch2' */

  /* Switch: '<S165>/Switch3' incorporates:
   *  UnitDelay: '<S137>/Unit Delay2'
   *  UnitDelay: '<S137>/Unit Delay3'
   *  UnitDelay: '<S165>/Unit Delay'
   */
  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj) {
    rtb_bf3w[(int8_T)0] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)0];
    rtb_bf3w[(int8_T)1] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)1];
    rtb_bf3w[(int8_T)2] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)2];
    rtb_bf3w[(int8_T)3] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)3];
    rtb_bf3w[(int8_T)4] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)4];
    rtb_bf3w[(int8_T)5] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)5];
    rtb_bf3w[(int8_T)6] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)6];
    rtb_bf3w[(int8_T)7] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)7];
    rtb_bf3w[(int8_T)8] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)8];
    rtb_bf3w[(int8_T)9] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)9];
    rtb_bf3w[(int8_T)10] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)10];
    rtb_bf3w[(int8_T)11] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)11];
    rtb_bf3w[(int8_T)12] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)12];
    rtb_bf3w[(int8_T)13] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)13];
    rtb_bf3w[(int8_T)14] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)14];
    rtb_bf3w[(int8_T)15] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)15];
    rtb_bf3w[(int8_T)16] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)16];
    rtb_bf3w[(int8_T)17] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)17];
    rtb_bf3w[(int8_T)18] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)18];
    rtb_bf3w[(int8_T)19] = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)19];
  } else {
    rtb_bf3w[(int8_T)0] = tmp_w;
    rtb_bf3w[(int8_T)1] = tmp_x;
    rtb_bf3w[(int8_T)2] = tmp_y;
    rtb_bf3w[(int8_T)3] = tmp_z;
    rtb_bf3w[(int8_T)4] = tmp_10;
    rtb_bf3w[(int8_T)5] = tmp_11;
    rtb_bf3w[(int8_T)6] = tmp_12;
    rtb_bf3w[(int8_T)7] = tmp_13;
    rtb_bf3w[(int8_T)8] = tmp_14;
    rtb_bf3w[(int8_T)9] = tmp_15;
    rtb_bf3w[(int8_T)10] = tmp_16;
    rtb_bf3w[(int8_T)11] = tmp_17;
    rtb_bf3w[(int8_T)12] = tmp_18;
    rtb_bf3w[(int8_T)13] = tmp_19;
    rtb_bf3w[(int8_T)14] = tmp_1a;
    rtb_bf3w[(int8_T)15] = tmp_1b;
    rtb_bf3w[(int8_T)16] = tmp_1c;
    rtb_bf3w[(int8_T)17] = tmp_1d;
    rtb_bf3w[(int8_T)18] = tmp_1e;
    rtb_bf3w[(int8_T)19] = tmp_1f;
  }

  if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj) {
    rtb_bf3w[(int8_T)20] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)0];
    rtb_bf3w[(int8_T)21] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)1];
    rtb_bf3w[(int8_T)22] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)2];
    rtb_bf3w[(int8_T)23] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)3];
    rtb_bf3w[(int8_T)24] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)4];
    rtb_bf3w[(int8_T)25] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)5];
    rtb_bf3w[(int8_T)26] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)6];
    rtb_bf3w[(int8_T)27] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)7];
    rtb_bf3w[(int8_T)28] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)8];
    rtb_bf3w[(int8_T)29] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)9];
    rtb_bf3w[(int8_T)30] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)10];
    rtb_bf3w[(int8_T)31] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)11];
    rtb_bf3w[(int8_T)32] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)12];
    rtb_bf3w[(int8_T)33] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)13];
    rtb_bf3w[(int8_T)34] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)14];
    rtb_bf3w[(int8_T)35] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)15];
    rtb_bf3w[(int8_T)36] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)16];
    rtb_bf3w[(int8_T)37] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)17];
    rtb_bf3w[(int8_T)38] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)18];
    rtb_bf3w[(int8_T)39] = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)19];
  } else {
    rtb_bf3w[(int8_T)20] = tmp_1g;
    rtb_bf3w[(int8_T)21] = tmp_1h;
    rtb_bf3w[(int8_T)22] = tmp_1i;
    rtb_bf3w[(int8_T)23] = tmp_1j;
    rtb_bf3w[(int8_T)24] = tmp_1k;
    rtb_bf3w[(int8_T)25] = tmp_1l;
    rtb_bf3w[(int8_T)26] = tmp_1m;
    rtb_bf3w[(int8_T)27] = tmp_1n;
    rtb_bf3w[(int8_T)28] = tmp_1o;
    rtb_bf3w[(int8_T)29] = tmp_1p;
    rtb_bf3w[(int8_T)30] = tmp_1q;
    rtb_bf3w[(int8_T)31] = tmp_1r;
    rtb_bf3w[(int8_T)32] = tmp_1s;
    rtb_bf3w[(int8_T)33] = tmp_1t;
    rtb_bf3w[(int8_T)34] = tmp_1u;
    rtb_bf3w[(int8_T)35] = tmp_1v;
    rtb_bf3w[(int8_T)36] = tmp_1w;
    rtb_bf3w[(int8_T)37] = tmp_1x;
    rtb_bf3w[(int8_T)38] = tmp_1y;
    rtb_bf3w[(int8_T)39] = tmp_1z;
  }

  /* End of Switch: '<S165>/Switch3' */

  /* Update for UnitDelay: '<S165>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nhcj = DMC_Soc_Lat_B.Constant2;

  /* End of Outputs for SubSystem: '<S137>/Read_EEPROM_Correction_Factor' */

  /* Outputs for Atomic SubSystem: '<S137>/Possible_Adaptation_Check' */
  /* Abs: '<S164>/Abs2' */
  rtb_e1oo = (real32_T)fabs((real_T)CAM_Lateral_Error_Mean);

  /* Logic: '<S164>/Logical Operator1' */
  rtb_fckq = (boolean_T)((int32_T)(!SAC_Disable));

  /* Outputs for Atomic SubSystem: '<S164>/Wait_so_that_SAC_active_over_certrain_loops' */
  /* Constant: '<S197>/Sac_ts' */
  rtb_m3dz = ((real32_T)Sac_ts) * 3.05175781E-5F;

  /* MinMax: '<S197>/MinMax1' */
  if (rtb_m3dz >= 0.01F) {
  } else {
    rtb_m3dz = 0.01F;
  }

  /* DataTypeConversion: '<S197>/Data Type Conversion1' incorporates:
   *  Constant: '<S197>/Lat_min_offset_state'
   *  MinMax: '<S197>/MinMax1'
   *  Product: '<S197>/Divide'
   */
  tmp_w = (uint16_T)((real32_T)((((real32_T)Acf_min_sac_enabled_time) *
    0.015625F) / rtb_m3dz));

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/Constant1'
   *  Constant: '<S197>/Constant2'
   *  Sum: '<S197>/Add'
   *  UnitDelay: '<S197>/Unit Delay'
   */
  if ((int32_T)rtb_fckq) {
    tmp_x = (uint16_T)(DMC_Soc_Lat_DWork.UnitDelay_DSTATE_m0jf + ((uint16_T)1U));
  } else {
    tmp_x = (uint16_T)0U;
  }

  /* End of Switch: '<S197>/Switch' */

  /* MinMax: '<S197>/MinMax' */
  if (tmp_x <= tmp_w) {
    /* Update for UnitDelay: '<S197>/Unit Delay' */
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_m0jf = tmp_x;
  } else {
    /* Update for UnitDelay: '<S197>/Unit Delay' */
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_m0jf = tmp_w;
  }

  /* End of MinMax: '<S197>/MinMax' */

  /* Logic: '<S164>/Logical Operator' incorporates:
   *  Abs: '<S164>/Abs'
   *  Abs: '<S164>/Abs1'
   *  Abs: '<S164>/Abs3'
   *  Abs: '<S164>/Abs4'
   *  Constant: '<S137>/Min_th_lateral_error'
   *  Constant: '<S164>/Max_Camera_Curvature'
   *  Constant: '<S164>/Max_Driver_Steering_Torque'
   *  Constant: '<S164>/Max_Vehicle_Lateral_Acc'
   *  Constant: '<S164>/Max_Vehicle_Steer_Angle'
   *  Constant: '<S164>/Max_th_lateral_error1'
   *  Constant: '<S164>/Min_Stiffness_Request_Factor'
   *  Constant: '<S164>/Vehicle_Velocity_Lower_Limit'
   *  Constant: '<S164>/Vehicle_Velocity_Upper_Limit'
   *  Logic: '<S164>/Logical Operator3'
   *  Logic: '<S197>/Logical Operator'
   *  RelationalOperator: '<S164>/Relational Operator1'
   *  RelationalOperator: '<S164>/Relational Operator2'
   *  RelationalOperator: '<S164>/Relational Operator3'
   *  RelationalOperator: '<S164>/Relational Operator4'
   *  RelationalOperator: '<S164>/Relational Operator5'
   *  RelationalOperator: '<S164>/Relational Operator6'
   *  RelationalOperator: '<S164>/Relational Operator7'
   *  RelationalOperator: '<S164>/Relational Operator8'
   *  RelationalOperator: '<S164>/Relational Operator9'
   *  RelationalOperator: '<S197>/Relational Operator'
   *  UnitDelay: '<S29>/Alg_Loop_Delay23'
   */
  Factor_Corr_Enable_Flag = (((((((((((((((real32_T)fabs
    (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_olvg)) < 3.5F) && ((tmp_x > tmp_w) &&
    rtb_fckq)) && (((real32_T)fabs(*rt_dmmuI)) < 3.0F)) && (!LDP_Active)) &&
    (((real32_T)fabs(LKC_Kappa_Command_Arb)) < 0.01F)) && (VEH_Vehicle_Speed >=
    2.77777767F)) && (VEH_Vehicle_Speed <= 50.0F)) && rtb_bcax) && (rtb_c4yx >=
    0.7F)) && (rtb_e1oo > 0.05F)) && (rtb_e1oo <= 3.0F)) && (((real32_T)fabs
    (DMC_Soc_Lat_DWork.Alg_Loop_Delay23_DSTATE)) <= 15.0F)) && rtb_fsbi);

  /* End of Outputs for SubSystem: '<S164>/Wait_so_that_SAC_active_over_certrain_loops' */
  /* End of Outputs for SubSystem: '<S137>/Possible_Adaptation_Check' */

  /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
  /* Gain: '<S167>/Gain1' */
  rtb_e1oo = 3.6F * VEH_Vehicle_Speed;

  /* PreLookup: '<S167>/Prelookup1' incorporates:
   *  Constant: '<S167>/20_Mean_Speed_Segments'
   */
  rtb_mxcu = plook_u8ff_linc(rtb_e1oo,
    DMC_Soc_Lat_ConstP.u_Mean_Speed_Segments_Value_pinx, 19U, &rtb_iwln);

  /* PreLookup: '<S167>/Prelookup4' incorporates:
   *  Constant: '<S167>/10_Mean_Speed_Segments'
   */
  rtb_mbmh = plook_u8ff_linc(rtb_e1oo,
    DMC_Soc_Lat_ConstP.u_Mean_Speed_Segments_Value, 9U, &rtb_m0pk);

  /* PreLookup: '<S167>/Prelookup5' incorporates:
   *  Constant: '<S167>/5_Mean_Speed_Segments'
   */
  rtb_kgt0 = plook_u8ff_linc(rtb_e1oo,
    DMC_Soc_Lat_ConstP._Mean_Speed_Segments_Value, 4U, &rtb_nsi3);

  /* MultiPortSwitch: '<S167>/Multiport Switch1' incorporates:
   *  Constant: '<S167>/Constant3'
   */
  switch (Acf_no_of_segment_selection) {
   case 1:
    rtb_kgt0 = rtb_mxcu;
    break;

   case 2:
    rtb_kgt0 = rtb_mbmh;
    break;
  }

  /* End of MultiPortSwitch: '<S167>/Multiport Switch1' */

  /* Gain: '<S167>/Gain' */
  rtb_e1oo = 3.6F * Mean_Vehicle_Velocity;

  /* PreLookup: '<S167>/Prelookup' incorporates:
   *  Constant: '<S167>/20_Speed_Segments'
   */
  rtb_mxcu = plook_u8ff_linc(rtb_e1oo,
    DMC_Soc_Lat_ConstP.u_Speed_Segments_Value_hx55, 20U, &rtb_mkzu);

  /* PreLookup: '<S167>/Prelookup2' incorporates:
   *  Constant: '<S167>/10_Speed_Segments'
   */
  rtb_mbmh = plook_u8ff_linc(rtb_e1oo, DMC_Soc_Lat_ConstP.u_Speed_Segments_Value,
    10U, &rtb_fit4);

  /* PreLookup: '<S167>/Prelookup3' incorporates:
   *  Constant: '<S167>/5_Speed_Segments'
   */
  rtb_l15a = plook_u8ff_linc(rtb_e1oo, DMC_Soc_Lat_ConstP._Speed_Segments_Value,
    5U, &rtb_ixul);

  /* MultiPortSwitch: '<S167>/Multiport Switch' incorporates:
   *  Constant: '<S167>/Constant3'
   */
  switch (Acf_no_of_segment_selection) {
   case 1:
    rtb_l15a = rtb_mxcu;
    break;

   case 2:
    rtb_l15a = rtb_mbmh;
    break;
  }

  /* End of MultiPortSwitch: '<S167>/Multiport Switch' */

  /* MultiPortSwitch: '<S167>/Multiport Switch1' incorporates:
   *  Constant: '<S167>/Constant3'
   */
  switch (Acf_no_of_segment_selection) {
   case 1:
    rtb_nsi3 = rtb_iwln;
    break;

   case 2:
    rtb_nsi3 = rtb_m0pk;
    break;
  }

  /* End of MultiPortSwitch: '<S167>/Multiport Switch1' */

  /* RelationalOperator: '<S167>/Relational Operator' incorporates:
   *  UnitDelay: '<S167>/Unit Delay'
   */
  rtb_fckq = (boolean_T)((int32_T)(rtb_l15a ==
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ctq3));

  /* UnitDelay: '<S167>/Unit Delay1' */
  rtb_ojsl = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_iblc;

  /* UnitDelay: '<S167>/Unit Delay2' */
  rtb_pnn5 = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_c04i;

  /* Update for UnitDelay: '<S167>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ctq3 = rtb_l15a;

  /* Update for UnitDelay: '<S167>/Unit Delay1' incorporates:
   *  MultiPortSwitch: '<S167>/Index Vector'
   */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_iblc = rtb_bqaz[rtb_l15a];

  /* Update for UnitDelay: '<S167>/Unit Delay2' incorporates:
   *  MultiPortSwitch: '<S167>/Index Vector1'
   */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_c04i = rtb_bqaz[((int32_T)rtb_l15a) +
    ((int32_T)20)];

  /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

  /* Outputs for Atomic SubSystem: '<S137>/Correction_Factor_Estimation' */
  /* RelationalOperator: '<S174>/Compare' incorporates:
   *  Constant: '<S174>/Constant'
   *  Constant: '<S35>/Dyc_compensation_mode (1)'
   *  S-Function (sfix_bitop): '<S160>/Bitwise Operator2'
   */
  rtb_mxcu = (uint8_T)((int32_T)((((int32_T)Dyc_compensation_mode) & ((int32_T)
    8192)) == ((int32_T)8192)));

  /* If: '<S160>/If' incorporates:
   *  Constant: '<S160>/Max_Driver_Steering_Torque_Inner_Lane'
   *  Constant: '<S160>/Max_Driver_Steering_Torque_Outer_Lane'
   *  Constant: '<S170>/Constant'
   *  Constant: '<S171>/Constant'
   *  Constant: '<S172>/Constant'
   *  Constant: '<S173>/Constant'
   *  Constant: '<S177>/Constant1'
   *  Constant: '<S177>/Constant5'
   *  Constant: '<S177>/Constant6'
   *  Constant: '<S177>/Constant7'
   *  Constant: '<S178>/Constant5'
   *  Constant: '<S178>/Constant6'
   *  Constant: '<S178>/Constant7'
   *  Constant: '<S179>/Constant5'
   *  Constant: '<S179>/Constant6'
   *  Constant: '<S179>/Constant7'
   *  Constant: '<S180>/Constant5'
   *  Constant: '<S180>/Constant6'
   *  Constant: '<S180>/Constant7'
   *  Constant: '<S181>/Constant5'
   *  Constant: '<S181>/Constant6'
   *  Constant: '<S181>/Constant7'
   *  Inport: '<S177>/Correction_Factor_Left_Last_Loop'
   *  Inport: '<S177>/Correction_Factor_Right_Last_Loop'
   *  Logic: '<S160>/Logical Operator'
   *  Logic: '<S160>/Logical Operator1'
   *  Logic: '<S160>/Logical Operator2'
   *  Logic: '<S160>/Logical Operator3'
   *  MultiPortSwitch: '<S167>/Index Vector'
   *  MultiPortSwitch: '<S167>/Index Vector1'
   *  RelationalOperator: '<S160>/Relational Operator1'
   *  RelationalOperator: '<S160>/Relational Operator2'
   *  RelationalOperator: '<S160>/Relational Operator3'
   *  RelationalOperator: '<S160>/Relational Operator4'
   *  RelationalOperator: '<S170>/Compare'
   *  RelationalOperator: '<S171>/Compare'
   *  RelationalOperator: '<S172>/Compare'
   *  RelationalOperator: '<S173>/Compare'
   *  RelationalOperator: '<S175>/Compare'
   */
  if ((((int32_T)Factor_Corr_Enable_Flag) && (((int32_T)Turn_And_Error_Side) ==
        ((int32_T)1))) && ((*rt_dmmuI) < 2.5F)) {
    /* Outputs for IfAction SubSystem: '<S160>/Left_Turn_Left_Error' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Switch: '<S178>/Switch' incorporates:
     *  Abs: '<S178>/Abs'
     *  Constant: '<S178>/Constant'
     *  Constant: '<S178>/Constant1'
     *  Constant: '<S178>/Constant2'
     *  Constant: '<S178>/Constant3'
     *  Logic: '<S178>/Logical Operator'
     *  RelationalOperator: '<S178>/Relational Operator'
     *  RelationalOperator: '<S178>/Relational Operator1'
     *  UnitDelay: '<S29>/Alg_Loop_Delay22'
     */
    if (((CAM_Lateral_Error_Delta <= 0.0F) && (((real32_T)fabs((real_T)
            DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE)) < 0.04F)) && ((int32_T)
         DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq)) {
      LTLE_Waiting_Counter = 1U;
    } else {
      LTLE_Waiting_Counter = 0U;
    }

    /* End of Switch: '<S178>/Switch' */

    /* Sum: '<S178>/Add' incorporates:
     *  UnitDelay: '<S160>/Unit Delay'
     */
    LTLE_Waiting_Counter = (uint16_T)(((uint32_T)LTLE_Waiting_Counter) +
      DMC_Soc_Lat_DWork.UnitDelay_DSTATE_apu5);

    /* Product: '<S178>/Product' incorporates:
     *  Constant: '<S178>/Last_Segment_Corr_Factor_Take_Over'
     */
    rtb_e1oo = rtb_ojsl * 1.05F;

    /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
    /* Switch: '<S178>/Switch3' incorporates:
     *  Logic: '<S178>/Logical Operator1'
     *  MultiPortSwitch: '<S167>/Index Vector'
     *  RelationalOperator: '<S178>/Relational Operator3'
     */
    if (((int32_T)rtb_fckq) || (rtb_bqaz[rtb_l15a] <= rtb_e1oo)) {
      rtb_e1oo = rtb_bqaz[rtb_l15a];
    }

    /* End of Switch: '<S178>/Switch3' */
    /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

    /* Sum: '<S178>/Add1' */
    rtb_dpeo = rtb_e1oo - Factor_Decrease;

    /* RelationalOperator: '<S178>/Relational Operator2' */
    rtb_fckq = (boolean_T)((int32_T)(LTLE_Waiting_Counter >
      Maximum_Waiting_Counter));

    /* Switch: '<S178>/Switch1' */
    if ((int32_T)rtb_fckq) {
      rtb_n4jt = rtb_dpeo;
    } else {
      rtb_n4jt = rtb_e1oo;
    }

    /* End of Switch: '<S178>/Switch1' */

    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S178>/Constant4'
     *  MinMax: '<S178>/MinMax'
     */
    if ((int32_T)rtb_fckq) {
      LTLE_Waiting_Counter = 0U;
    } else if (LTLE_Waiting_Counter <= Maximum_Waiting_Counter) {
    } else {
      /* MinMax: '<S178>/MinMax' */
      LTLE_Waiting_Counter = Maximum_Waiting_Counter;
    }

    /* End of Switch: '<S178>/Switch2' */

    /* Switch: '<S178>/Switch5' */
    if ((int32_T)rtb_fckq) {
    } else {
      rtb_dpeo = rtb_e1oo;
    }

    /* End of Switch: '<S178>/Switch5' */

    /* Switch: '<S178>/Switch4' incorporates:
     *  MultiPortSwitch: '<S167>/Index Vector1'
     */
    if (((int32_T)rtb_mxcu) > ((int32_T)0)) {
    } else {
      /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
      rtb_dpeo = rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)];

      /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
    }

    /* End of Switch: '<S178>/Switch4' */
    LTRE_Waiting_Counter = 0U;
    RTLE_Waiting_Counter = 0U;
    RTRE_Waiting_Counter = 0U;

    /* End of Outputs for SubSystem: '<S160>/Left_Turn_Left_Error' */
  } else if ((((int32_T)Factor_Corr_Enable_Flag) && (((int32_T)
                Turn_And_Error_Side) == ((int32_T)2))) && ((*rt_dmmuI) > -1.5F))
  {
    /* Outputs for IfAction SubSystem: '<S160>/Left_Turn_Right_Error' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* Switch: '<S179>/Switch' incorporates:
     *  Abs: '<S179>/Abs'
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Constant1'
     *  Constant: '<S179>/Constant2'
     *  Constant: '<S179>/Constant3'
     *  Logic: '<S179>/Logical Operator'
     *  RelationalOperator: '<S179>/Relational Operator'
     *  RelationalOperator: '<S179>/Relational Operator1'
     *  UnitDelay: '<S29>/Alg_Loop_Delay22'
     */
    if (((CAM_Lateral_Error_Delta >= 0.0F) && (((real32_T)fabs((real_T)
            DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE)) < 0.04F)) && ((int32_T)
         DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq)) {
      LTRE_Waiting_Counter = 1U;
    } else {
      LTRE_Waiting_Counter = 0U;
    }

    /* End of Switch: '<S179>/Switch' */

    /* Sum: '<S179>/Add' incorporates:
     *  UnitDelay: '<S160>/Unit Delay1'
     */
    LTRE_Waiting_Counter = (uint16_T)(((uint32_T)LTRE_Waiting_Counter) +
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_k51z);

    /* Product: '<S179>/Product' incorporates:
     *  Constant: '<S179>/Last_Segment_Corr_Factor_Take_Over'
     */
    rtb_e1oo = rtb_ojsl * 0.95F;

    /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
    /* Switch: '<S179>/Switch3' incorporates:
     *  Logic: '<S179>/Logical Operator1'
     *  MultiPortSwitch: '<S167>/Index Vector'
     *  RelationalOperator: '<S179>/Relational Operator3'
     */
    if (((int32_T)rtb_fckq) || (rtb_bqaz[rtb_l15a] >= rtb_e1oo)) {
      rtb_e1oo = rtb_bqaz[rtb_l15a];
    }

    /* End of Switch: '<S179>/Switch3' */
    /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

    /* Sum: '<S179>/Add1' */
    rtb_dpeo = rtb_e1oo + Factor_Increase;

    /* RelationalOperator: '<S179>/Relational Operator2' */
    rtb_fckq = (boolean_T)((int32_T)(LTRE_Waiting_Counter >
      Maximum_Waiting_Counter));

    /* Switch: '<S179>/Switch1' */
    if ((int32_T)rtb_fckq) {
      rtb_n4jt = rtb_dpeo;
    } else {
      rtb_n4jt = rtb_e1oo;
    }

    /* End of Switch: '<S179>/Switch1' */

    /* Switch: '<S179>/Switch2' incorporates:
     *  Constant: '<S179>/Constant4'
     *  MinMax: '<S179>/MinMax'
     */
    if ((int32_T)rtb_fckq) {
      LTRE_Waiting_Counter = 0U;
    } else if (LTRE_Waiting_Counter <= Maximum_Waiting_Counter) {
    } else {
      /* MinMax: '<S179>/MinMax' */
      LTRE_Waiting_Counter = Maximum_Waiting_Counter;
    }

    /* End of Switch: '<S179>/Switch2' */

    /* Switch: '<S179>/Switch5' */
    if ((int32_T)rtb_fckq) {
    } else {
      rtb_dpeo = rtb_e1oo;
    }

    /* End of Switch: '<S179>/Switch5' */

    /* Switch: '<S179>/Switch4' incorporates:
     *  MultiPortSwitch: '<S167>/Index Vector1'
     */
    if (((int32_T)rtb_mxcu) > ((int32_T)0)) {
    } else {
      /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
      rtb_dpeo = rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)];

      /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
    }

    /* End of Switch: '<S179>/Switch4' */
    LTLE_Waiting_Counter = 0U;
    RTLE_Waiting_Counter = 0U;
    RTRE_Waiting_Counter = 0U;

    /* End of Outputs for SubSystem: '<S160>/Left_Turn_Right_Error' */
  } else if ((((int32_T)Factor_Corr_Enable_Flag) && (((int32_T)
                Turn_And_Error_Side) == ((int32_T)3))) && ((*rt_dmmuI) < 1.5F))
  {
    /* Outputs for IfAction SubSystem: '<S160>/Right_Turn_Left_Error' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Switch: '<S180>/Switch' incorporates:
     *  Abs: '<S180>/Abs'
     *  Constant: '<S180>/Constant'
     *  Constant: '<S180>/Constant1'
     *  Constant: '<S180>/Constant2'
     *  Constant: '<S180>/Constant3'
     *  Logic: '<S180>/Logical Operator'
     *  RelationalOperator: '<S180>/Relational Operator'
     *  RelationalOperator: '<S180>/Relational Operator1'
     *  UnitDelay: '<S29>/Alg_Loop_Delay22'
     */
    if (((CAM_Lateral_Error_Delta <= 0.0F) && (((real32_T)fabs((real_T)
            DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE)) < 0.04F)) && ((int32_T)
         DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq)) {
      RTLE_Waiting_Counter = 1U;
    } else {
      RTLE_Waiting_Counter = 0U;
    }

    /* End of Switch: '<S180>/Switch' */

    /* Sum: '<S180>/Add' incorporates:
     *  UnitDelay: '<S160>/Unit Delay2'
     */
    RTLE_Waiting_Counter = (uint16_T)(((uint32_T)RTLE_Waiting_Counter) +
      DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_juu0);

    /* Product: '<S180>/Product' incorporates:
     *  Constant: '<S180>/Last_Segment_Corr_Factor_Take_Over'
     */
    rtb_e1oo = rtb_pnn5 * 0.95F;

    /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
    /* Switch: '<S180>/Switch3' incorporates:
     *  Logic: '<S180>/Logical Operator1'
     *  MultiPortSwitch: '<S167>/Index Vector1'
     *  RelationalOperator: '<S180>/Relational Operator3'
     */
    if (((int32_T)rtb_fckq) || (rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)] >=
         rtb_e1oo)) {
      rtb_e1oo = rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)];
    }

    /* End of Switch: '<S180>/Switch3' */
    /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

    /* Sum: '<S180>/Add1' */
    rtb_n4jt = rtb_e1oo + Factor_Increase;

    /* RelationalOperator: '<S180>/Relational Operator2' */
    rtb_fckq = (boolean_T)((int32_T)(RTLE_Waiting_Counter >
      Maximum_Waiting_Counter));

    /* Switch: '<S180>/Switch1' */
    if ((int32_T)rtb_fckq) {
      rtb_dpeo = rtb_n4jt;
    } else {
      rtb_dpeo = rtb_e1oo;
    }

    /* End of Switch: '<S180>/Switch1' */

    /* Switch: '<S180>/Switch2' incorporates:
     *  Constant: '<S180>/Constant4'
     *  MinMax: '<S180>/MinMax'
     */
    if ((int32_T)rtb_fckq) {
      RTLE_Waiting_Counter = 0U;
    } else if (RTLE_Waiting_Counter <= Maximum_Waiting_Counter) {
    } else {
      /* MinMax: '<S180>/MinMax' */
      RTLE_Waiting_Counter = Maximum_Waiting_Counter;
    }

    /* End of Switch: '<S180>/Switch2' */

    /* Switch: '<S180>/Switch5' */
    if ((int32_T)rtb_fckq) {
    } else {
      rtb_n4jt = rtb_e1oo;
    }

    /* End of Switch: '<S180>/Switch5' */

    /* Switch: '<S180>/Switch4' incorporates:
     *  MultiPortSwitch: '<S167>/Index Vector'
     */
    if (((int32_T)rtb_mxcu) > ((int32_T)0)) {
    } else {
      /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
      rtb_n4jt = rtb_bqaz[rtb_l15a];

      /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
    }

    /* End of Switch: '<S180>/Switch4' */
    LTLE_Waiting_Counter = 0U;
    LTRE_Waiting_Counter = 0U;
    RTRE_Waiting_Counter = 0U;

    /* End of Outputs for SubSystem: '<S160>/Right_Turn_Left_Error' */
  } else if ((((int32_T)Factor_Corr_Enable_Flag) && (((int32_T)
                Turn_And_Error_Side) == ((int32_T)4))) && ((*rt_dmmuI) > -2.5F))
  {
    /* Outputs for IfAction SubSystem: '<S160>/Right_Turn_Right_Error' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    /* Switch: '<S181>/Switch' incorporates:
     *  Abs: '<S181>/Abs'
     *  Constant: '<S181>/Constant'
     *  Constant: '<S181>/Constant1'
     *  Constant: '<S181>/Constant2'
     *  Constant: '<S181>/Constant3'
     *  Logic: '<S181>/Logical Operator'
     *  RelationalOperator: '<S181>/Relational Operator'
     *  RelationalOperator: '<S181>/Relational Operator1'
     *  UnitDelay: '<S29>/Alg_Loop_Delay22'
     */
    if (((CAM_Lateral_Error_Delta >= 0.0F) && (((real32_T)fabs((real_T)
            DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE)) < 0.04F)) && ((int32_T)
         DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_dvmq)) {
      RTRE_Waiting_Counter = 1U;
    } else {
      RTRE_Waiting_Counter = 0U;
    }

    /* End of Switch: '<S181>/Switch' */

    /* Sum: '<S181>/Add' incorporates:
     *  UnitDelay: '<S160>/Unit Delay3'
     */
    RTRE_Waiting_Counter = (uint16_T)(((uint32_T)RTRE_Waiting_Counter) +
      DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_luca);

    /* Product: '<S181>/Product' incorporates:
     *  Constant: '<S181>/Last_Segment_Corr_Factor_Take_Over'
     */
    rtb_e1oo = rtb_pnn5 * 1.05F;

    /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
    /* Switch: '<S181>/Switch3' incorporates:
     *  Logic: '<S181>/Logical Operator1'
     *  MultiPortSwitch: '<S167>/Index Vector1'
     *  RelationalOperator: '<S181>/Relational Operator3'
     */
    if (((int32_T)rtb_fckq) || (rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)] <=
         rtb_e1oo)) {
      rtb_e1oo = rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)];
    }

    /* End of Switch: '<S181>/Switch3' */
    /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

    /* Sum: '<S181>/Add1' */
    rtb_n4jt = rtb_e1oo - Factor_Decrease;

    /* RelationalOperator: '<S181>/Relational Operator2' */
    rtb_fckq = (boolean_T)((int32_T)(RTRE_Waiting_Counter >
      Maximum_Waiting_Counter));

    /* Switch: '<S181>/Switch1' */
    if ((int32_T)rtb_fckq) {
      rtb_dpeo = rtb_n4jt;
    } else {
      rtb_dpeo = rtb_e1oo;
    }

    /* End of Switch: '<S181>/Switch1' */

    /* Switch: '<S181>/Switch2' incorporates:
     *  Constant: '<S181>/Constant4'
     *  MinMax: '<S181>/MinMax'
     */
    if ((int32_T)rtb_fckq) {
      RTRE_Waiting_Counter = 0U;
    } else if (RTRE_Waiting_Counter <= Maximum_Waiting_Counter) {
    } else {
      /* MinMax: '<S181>/MinMax' */
      RTRE_Waiting_Counter = Maximum_Waiting_Counter;
    }

    /* End of Switch: '<S181>/Switch2' */

    /* Switch: '<S181>/Switch5' */
    if ((int32_T)rtb_fckq) {
    } else {
      rtb_n4jt = rtb_e1oo;
    }

    /* End of Switch: '<S181>/Switch5' */

    /* Switch: '<S181>/Switch4' incorporates:
     *  MultiPortSwitch: '<S167>/Index Vector'
     */
    if (((int32_T)rtb_mxcu) > ((int32_T)0)) {
    } else {
      /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
      rtb_n4jt = rtb_bqaz[rtb_l15a];

      /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
    }

    /* End of Switch: '<S181>/Switch4' */
    LTLE_Waiting_Counter = 0U;
    LTRE_Waiting_Counter = 0U;
    RTLE_Waiting_Counter = 0U;

    /* End of Outputs for SubSystem: '<S160>/Right_Turn_Right_Error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S160>/Default' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
    rtb_n4jt = rtb_bqaz[rtb_l15a];
    rtb_dpeo = rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)];

    /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
    LTLE_Waiting_Counter = 0U;
    LTRE_Waiting_Counter = 0U;
    RTLE_Waiting_Counter = 0U;
    RTRE_Waiting_Counter = 0U;

    /* End of Outputs for SubSystem: '<S160>/Default' */
  }

  /* End of If: '<S160>/If' */

  /* Outputs for Atomic SubSystem: '<S160>/Correction_Factor_Saturation' */
  /* MinMax: '<S176>/MinMax' incorporates:
   *  Constant: '<S176>/Min_Correction_Factor'
   */
  rtb_jwxe = ((real32_T)Adp_dyc_corr_factor_lower_limit) * 0.0009765625F;
  if (rtb_n4jt >= rtb_jwxe) {
    rtb_jwxe = rtb_n4jt;
  }

  /* MinMax: '<S176>/MinMax1' incorporates:
   *  Constant: '<S176>/Max_Correction_Factor'
   *  MinMax: '<S176>/MinMax'
   */
  rtb_e1oo = ((real32_T)Adp_dyc_corr_factor_upper_limit) * 0.0009765625F;
  if (rtb_jwxe <= rtb_e1oo) {
    rtb_e1oo = rtb_jwxe;
  }

  /* End of MinMax: '<S176>/MinMax1' */

  /* MinMax: '<S176>/MinMax2' incorporates:
   *  Constant: '<S176>/Min_Correction_Factor'
   */
  rtb_m3dz = ((real32_T)Adp_dyc_corr_factor_lower_limit) * 0.0009765625F;
  if (rtb_m3dz >= rtb_dpeo) {
    rtb_dpeo = rtb_m3dz;
  }

  /* MinMax: '<S176>/MinMax3' incorporates:
   *  Constant: '<S176>/Max_Correction_Factor'
   *  MinMax: '<S176>/MinMax2'
   */
  rtb_m3dz = ((real32_T)Adp_dyc_corr_factor_upper_limit) * 0.0009765625F;
  if (rtb_m3dz <= rtb_dpeo) {
    rtb_dpeo = rtb_m3dz;
  }

  /* End of MinMax: '<S176>/MinMax3' */
  /* End of Outputs for SubSystem: '<S160>/Correction_Factor_Saturation' */

  /* Update for UnitDelay: '<S160>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_luca = RTRE_Waiting_Counter;

  /* Update for UnitDelay: '<S160>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_juu0 = RTLE_Waiting_Counter;

  /* Update for UnitDelay: '<S160>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_k51z = LTRE_Waiting_Counter;

  /* Update for UnitDelay: '<S160>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_apu5 = LTLE_Waiting_Counter;

  /* End of Outputs for SubSystem: '<S137>/Correction_Factor_Estimation' */

  /* Outputs for Atomic SubSystem: '<S137>/Save_Correction_Factor_In_Vector' */
  /* Assignment: '<S166>/Assignment1' */
  ADP_Dyc_Corr_Factor_Left_Vect[0] = rtb_bqaz[0];
  ADP_Dyc_Corr_Factor_Left_Vect[1] = rtb_bqaz[1];
  ADP_Dyc_Corr_Factor_Left_Vect[2] = rtb_bqaz[2];
  ADP_Dyc_Corr_Factor_Left_Vect[3] = rtb_bqaz[3];
  ADP_Dyc_Corr_Factor_Left_Vect[4] = rtb_bqaz[4];
  ADP_Dyc_Corr_Factor_Left_Vect[5] = rtb_bqaz[5];
  ADP_Dyc_Corr_Factor_Left_Vect[6] = rtb_bqaz[6];
  ADP_Dyc_Corr_Factor_Left_Vect[7] = rtb_bqaz[7];
  ADP_Dyc_Corr_Factor_Left_Vect[8] = rtb_bqaz[8];
  ADP_Dyc_Corr_Factor_Left_Vect[9] = rtb_bqaz[9];
  ADP_Dyc_Corr_Factor_Left_Vect[10] = rtb_bqaz[10];
  ADP_Dyc_Corr_Factor_Left_Vect[11] = rtb_bqaz[11];
  ADP_Dyc_Corr_Factor_Left_Vect[12] = rtb_bqaz[12];
  ADP_Dyc_Corr_Factor_Left_Vect[13] = rtb_bqaz[13];
  ADP_Dyc_Corr_Factor_Left_Vect[14] = rtb_bqaz[14];
  ADP_Dyc_Corr_Factor_Left_Vect[15] = rtb_bqaz[15];
  ADP_Dyc_Corr_Factor_Left_Vect[16] = rtb_bqaz[16];
  ADP_Dyc_Corr_Factor_Left_Vect[17] = rtb_bqaz[17];
  ADP_Dyc_Corr_Factor_Left_Vect[18] = rtb_bqaz[18];
  ADP_Dyc_Corr_Factor_Left_Vect[19] = rtb_bqaz[19];
  ADP_Dyc_Corr_Factor_Left_Vect[(rtb_l15a)] = rtb_e1oo;

  /* Assignment: '<S166>/Assignment2' */
  ADP_Dyc_Corr_Factor_Right_Vect[0] = rtb_bqaz[20];
  ADP_Dyc_Corr_Factor_Right_Vect[1] = rtb_bqaz[21];
  ADP_Dyc_Corr_Factor_Right_Vect[2] = rtb_bqaz[22];
  ADP_Dyc_Corr_Factor_Right_Vect[3] = rtb_bqaz[23];
  ADP_Dyc_Corr_Factor_Right_Vect[4] = rtb_bqaz[24];
  ADP_Dyc_Corr_Factor_Right_Vect[5] = rtb_bqaz[25];
  ADP_Dyc_Corr_Factor_Right_Vect[6] = rtb_bqaz[26];
  ADP_Dyc_Corr_Factor_Right_Vect[7] = rtb_bqaz[27];
  ADP_Dyc_Corr_Factor_Right_Vect[8] = rtb_bqaz[28];
  ADP_Dyc_Corr_Factor_Right_Vect[9] = rtb_bqaz[29];
  ADP_Dyc_Corr_Factor_Right_Vect[10] = rtb_bqaz[30];
  ADP_Dyc_Corr_Factor_Right_Vect[11] = rtb_bqaz[31];
  ADP_Dyc_Corr_Factor_Right_Vect[12] = rtb_bqaz[32];
  ADP_Dyc_Corr_Factor_Right_Vect[13] = rtb_bqaz[33];
  ADP_Dyc_Corr_Factor_Right_Vect[14] = rtb_bqaz[34];
  ADP_Dyc_Corr_Factor_Right_Vect[15] = rtb_bqaz[35];
  ADP_Dyc_Corr_Factor_Right_Vect[16] = rtb_bqaz[36];
  ADP_Dyc_Corr_Factor_Right_Vect[17] = rtb_bqaz[37];
  ADP_Dyc_Corr_Factor_Right_Vect[18] = rtb_bqaz[38];
  ADP_Dyc_Corr_Factor_Right_Vect[19] = rtb_bqaz[39];
  ADP_Dyc_Corr_Factor_Right_Vect[(rtb_l15a)] = rtb_dpeo;

  /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
  /* Switch: '<S166>/Switch3' incorporates:
   *  Constant: '<S166>/Increament_Counter'
   *  MultiPortSwitch: '<S167>/Index Vector'
   *  MultiPortSwitch: '<S167>/Index Vector2'
   *  RelationalOperator: '<S166>/Relational Operator'
   *  Sum: '<S166>/Add'
   */
  if (rtb_e1oo != rtb_bqaz[rtb_l15a]) {
    tmp_w = (uint16_T)(((uint16_T)1U) + rtb_bf3w[rtb_l15a]);
  } else {
    tmp_w = rtb_bf3w[rtb_l15a];
  }

  /* End of Switch: '<S166>/Switch3' */
  /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

  /* Assignment: '<S166>/Assignment3' */
  rt_id5lvI[(int8_T)0] = rtb_bf3w[(int8_T)0];
  rt_id5lvI[(int8_T)1] = rtb_bf3w[(int8_T)1];
  rt_id5lvI[(int8_T)2] = rtb_bf3w[(int8_T)2];
  rt_id5lvI[(int8_T)3] = rtb_bf3w[(int8_T)3];
  rt_id5lvI[(int8_T)4] = rtb_bf3w[(int8_T)4];
  rt_id5lvI[(int8_T)5] = rtb_bf3w[(int8_T)5];
  rt_id5lvI[(int8_T)6] = rtb_bf3w[(int8_T)6];
  rt_id5lvI[(int8_T)7] = rtb_bf3w[(int8_T)7];
  rt_id5lvI[(int8_T)8] = rtb_bf3w[(int8_T)8];
  rt_id5lvI[(int8_T)9] = rtb_bf3w[(int8_T)9];
  rt_id5lvI[(int8_T)10] = rtb_bf3w[(int8_T)10];
  rt_id5lvI[(int8_T)11] = rtb_bf3w[(int8_T)11];
  rt_id5lvI[(int8_T)12] = rtb_bf3w[(int8_T)12];
  rt_id5lvI[(int8_T)13] = rtb_bf3w[(int8_T)13];
  rt_id5lvI[(int8_T)14] = rtb_bf3w[(int8_T)14];
  rt_id5lvI[(int8_T)15] = rtb_bf3w[(int8_T)15];
  rt_id5lvI[(int8_T)16] = rtb_bf3w[(int8_T)16];
  rt_id5lvI[(int8_T)17] = rtb_bf3w[(int8_T)17];
  rt_id5lvI[(int8_T)18] = rtb_bf3w[(int8_T)18];
  rt_id5lvI[(int8_T)19] = rtb_bf3w[(int8_T)19];

  /* MinMax: '<S166>/MinMax' */
  if (((int32_T)tmp_w) <= ((int32_T)6500)) {
  } else {
    tmp_w = 6500U;
  }

  /* Assignment: '<S166>/Assignment3' incorporates:
   *  MinMax: '<S166>/MinMax'
   */
  rt_id5lvI[rtb_l15a] = tmp_w;

  /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
  /* Switch: '<S166>/Switch2' incorporates:
   *  Constant: '<S166>/Increament_Counter'
   *  MultiPortSwitch: '<S167>/Index Vector1'
   *  MultiPortSwitch: '<S167>/Index Vector3'
   *  RelationalOperator: '<S166>/Relational Operator1'
   *  Sum: '<S166>/Add1'
   */
  if (rtb_dpeo != rtb_bqaz[((int32_T)rtb_l15a) + ((int32_T)20)]) {
    tmp_w = (uint16_T)(((uint16_T)1U) + rtb_bf3w[((int32_T)rtb_l15a) + ((int32_T)
      20)]);
  } else {
    tmp_w = rtb_bf3w[((int32_T)rtb_l15a) + ((int32_T)20)];
  }

  /* End of Switch: '<S166>/Switch2' */
  /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */

  /* Assignment: '<S166>/Assignment4' */
  rt_prezcI[(int8_T)0] = rtb_bf3w[(int8_T)20];
  rt_prezcI[(int8_T)1] = rtb_bf3w[(int8_T)21];
  rt_prezcI[(int8_T)2] = rtb_bf3w[(int8_T)22];
  rt_prezcI[(int8_T)3] = rtb_bf3w[(int8_T)23];
  rt_prezcI[(int8_T)4] = rtb_bf3w[(int8_T)24];
  rt_prezcI[(int8_T)5] = rtb_bf3w[(int8_T)25];
  rt_prezcI[(int8_T)6] = rtb_bf3w[(int8_T)26];
  rt_prezcI[(int8_T)7] = rtb_bf3w[(int8_T)27];
  rt_prezcI[(int8_T)8] = rtb_bf3w[(int8_T)28];
  rt_prezcI[(int8_T)9] = rtb_bf3w[(int8_T)29];
  rt_prezcI[(int8_T)10] = rtb_bf3w[(int8_T)30];
  rt_prezcI[(int8_T)11] = rtb_bf3w[(int8_T)31];
  rt_prezcI[(int8_T)12] = rtb_bf3w[(int8_T)32];
  rt_prezcI[(int8_T)13] = rtb_bf3w[(int8_T)33];
  rt_prezcI[(int8_T)14] = rtb_bf3w[(int8_T)34];
  rt_prezcI[(int8_T)15] = rtb_bf3w[(int8_T)35];
  rt_prezcI[(int8_T)16] = rtb_bf3w[(int8_T)36];
  rt_prezcI[(int8_T)17] = rtb_bf3w[(int8_T)37];
  rt_prezcI[(int8_T)18] = rtb_bf3w[(int8_T)38];
  rt_prezcI[(int8_T)19] = rtb_bf3w[(int8_T)39];

  /* MinMax: '<S166>/MinMax1' */
  if (((int32_T)6500) <= ((int32_T)tmp_w)) {
    tmp_w = 6500U;
  }

  /* Assignment: '<S166>/Assignment4' incorporates:
   *  MinMax: '<S166>/MinMax1'
   */
  rt_prezcI[rtb_l15a] = tmp_w;

  /* Interpolation_n-D: '<S166>/Interpolation Using Prelookup' incorporates:
   *  DataTypeConversion: '<S167>/Data Type Conversion'
   */
  rtb_jwxe = rtb_nsi3;
  if (rtb_nsi3 < 0.0F) {
    rtb_jwxe = 0.0F;
  } else {
    if (rtb_nsi3 > 1.0F) {
      rtb_jwxe = 1.0F;
    }
  }

  /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
  rtb_kw01 = (int32_T)rtb_kgt0;
  if (rtb_kgt0 > ((uint8_T)18U)) {
    rtb_kw01 = (int32_T)18;
  }

  /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
  ADP_Dyc_Corr_Factor_Ls = intrp1d_fu32fl((uint32_T)rtb_kw01, rtb_jwxe,
    (&(ADP_Dyc_Corr_Factor_Left_Vect[0])));

  /* End of Interpolation_n-D: '<S166>/Interpolation Using Prelookup' */

  /* Interpolation_n-D: '<S166>/Interpolation Using Prelookup1' incorporates:
   *  DataTypeConversion: '<S167>/Data Type Conversion'
   */
  if (rtb_nsi3 < 0.0F) {
    rtb_nsi3 = 0.0F;
  } else {
    if (rtb_nsi3 > 1.0F) {
      rtb_nsi3 = 1.0F;
    }
  }

  /* Outputs for Atomic SubSystem: '<S137>/Speed_Segment_Identify' */
  rtb_kw01 = (int32_T)rtb_kgt0;
  if (rtb_kgt0 > ((uint8_T)18U)) {
    rtb_kw01 = (int32_T)18;
  }

  /* End of Outputs for SubSystem: '<S137>/Speed_Segment_Identify' */
  ADP_Dyc_Corr_Factor_Rs = intrp1d_fu32fl((uint32_T)rtb_kw01, rtb_nsi3,
    (&(ADP_Dyc_Corr_Factor_Right_Vect[0])));

  /* End of Interpolation_n-D: '<S166>/Interpolation Using Prelookup1' */

  /* Switch: '<S166>/Switch1' incorporates:
   *  Constant: '<S200>/Constant'
   *  RelationalOperator: '<S200>/Compare'
   */
  if (LKC_Kappa_Command_Arb > 0.0F) {
    rtb_m3dz = ADP_Dyc_Corr_Factor_Ls;
  } else {
    rtb_m3dz = ADP_Dyc_Corr_Factor_Rs;
  }

  /* End of Switch: '<S166>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S166>/Correction_Factor_Gradient_Limitation' */
  /* Sum: '<S201>/Add' incorporates:
   *  UnitDelay: '<S201>/Unit Delay'
   */
  rtb_e1oo = rtb_m3dz - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_c3jk;

  /* Signum: '<S201>/Sign' */
  if (rtb_e1oo < 0.0F) {
    rtb_ojsl = -1.0F;
  } else if (rtb_e1oo > 0.0F) {
    rtb_ojsl = 1.0F;
  } else {
    rtb_ojsl = rtb_e1oo;
  }

  /* Abs: '<S201>/Abs' */
  rtb_m3dz = (real32_T)fabs((real_T)rtb_e1oo);

  /* Product: '<S201>/Product1' incorporates:
   *  Constant: '<S201>/Adp_dyc_corr_factor_gradient'
   *  Constant: '<S201>/Sac_ts'
   */
  rtb_jwxe = (((real32_T)Adp_dyc_corr_factor_gradient) * 0.0009765625F) *
    (((real32_T)Sac_ts) * 3.05175781E-5F);

  /* MinMax: '<S201>/MinMax' */
  if (rtb_m3dz <= rtb_jwxe) {
    rtb_jwxe = rtb_m3dz;
  }

  /* Sum: '<S201>/Add1' incorporates:
   *  MinMax: '<S201>/MinMax'
   *  Product: '<S201>/Product'
   *  Signum: '<S201>/Sign'
   *  UnitDelay: '<S201>/Unit Delay'
   */
  ADP_Dyc_Corr_Factor = (rtb_ojsl * rtb_jwxe) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_c3jk;

  /* Update for UnitDelay: '<S201>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_c3jk = ADP_Dyc_Corr_Factor;

  /* End of Outputs for SubSystem: '<S166>/Correction_Factor_Gradient_Limitation' */
  /* End of Outputs for SubSystem: '<S137>/Save_Correction_Factor_In_Vector' */

  /* Update for UnitDelay: '<S137>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)0] =
    ADP_Dyc_Corr_Factor_Left_Vect[0];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)1] =
    ADP_Dyc_Corr_Factor_Left_Vect[1];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)2] =
    ADP_Dyc_Corr_Factor_Left_Vect[2];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)3] =
    ADP_Dyc_Corr_Factor_Left_Vect[3];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)4] =
    ADP_Dyc_Corr_Factor_Left_Vect[4];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)5] =
    ADP_Dyc_Corr_Factor_Left_Vect[5];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)6] =
    ADP_Dyc_Corr_Factor_Left_Vect[6];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)7] =
    ADP_Dyc_Corr_Factor_Left_Vect[7];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)8] =
    ADP_Dyc_Corr_Factor_Left_Vect[8];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)9] =
    ADP_Dyc_Corr_Factor_Left_Vect[9];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)10] =
    ADP_Dyc_Corr_Factor_Left_Vect[10];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)11] =
    ADP_Dyc_Corr_Factor_Left_Vect[11];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)12] =
    ADP_Dyc_Corr_Factor_Left_Vect[12];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)13] =
    ADP_Dyc_Corr_Factor_Left_Vect[13];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)14] =
    ADP_Dyc_Corr_Factor_Left_Vect[14];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)15] =
    ADP_Dyc_Corr_Factor_Left_Vect[15];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)16] =
    ADP_Dyc_Corr_Factor_Left_Vect[16];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)17] =
    ADP_Dyc_Corr_Factor_Left_Vect[17];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)18] =
    ADP_Dyc_Corr_Factor_Left_Vect[18];
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[(int8_T)19] =
    ADP_Dyc_Corr_Factor_Left_Vect[19];

  /* Update for UnitDelay: '<S137>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)0] =
    ADP_Dyc_Corr_Factor_Right_Vect[0];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)1] =
    ADP_Dyc_Corr_Factor_Right_Vect[1];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)2] =
    ADP_Dyc_Corr_Factor_Right_Vect[2];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)3] =
    ADP_Dyc_Corr_Factor_Right_Vect[3];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)4] =
    ADP_Dyc_Corr_Factor_Right_Vect[4];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)5] =
    ADP_Dyc_Corr_Factor_Right_Vect[5];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)6] =
    ADP_Dyc_Corr_Factor_Right_Vect[6];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)7] =
    ADP_Dyc_Corr_Factor_Right_Vect[7];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)8] =
    ADP_Dyc_Corr_Factor_Right_Vect[8];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)9] =
    ADP_Dyc_Corr_Factor_Right_Vect[9];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)10] =
    ADP_Dyc_Corr_Factor_Right_Vect[10];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)11] =
    ADP_Dyc_Corr_Factor_Right_Vect[11];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)12] =
    ADP_Dyc_Corr_Factor_Right_Vect[12];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)13] =
    ADP_Dyc_Corr_Factor_Right_Vect[13];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)14] =
    ADP_Dyc_Corr_Factor_Right_Vect[14];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)15] =
    ADP_Dyc_Corr_Factor_Right_Vect[15];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)16] =
    ADP_Dyc_Corr_Factor_Right_Vect[16];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)17] =
    ADP_Dyc_Corr_Factor_Right_Vect[17];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)18] =
    ADP_Dyc_Corr_Factor_Right_Vect[18];
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[(int8_T)19] =
    ADP_Dyc_Corr_Factor_Right_Vect[19];

  /* Update for UnitDelay: '<S137>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)0] = rt_id5lvI[(int8_T)0];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)1] = rt_id5lvI[(int8_T)1];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)2] = rt_id5lvI[(int8_T)2];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)3] = rt_id5lvI[(int8_T)3];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)4] = rt_id5lvI[(int8_T)4];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)5] = rt_id5lvI[(int8_T)5];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)6] = rt_id5lvI[(int8_T)6];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)7] = rt_id5lvI[(int8_T)7];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)8] = rt_id5lvI[(int8_T)8];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)9] = rt_id5lvI[(int8_T)9];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)10] = rt_id5lvI[(int8_T)10];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)11] = rt_id5lvI[(int8_T)11];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)12] = rt_id5lvI[(int8_T)12];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)13] = rt_id5lvI[(int8_T)13];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)14] = rt_id5lvI[(int8_T)14];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)15] = rt_id5lvI[(int8_T)15];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)16] = rt_id5lvI[(int8_T)16];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)17] = rt_id5lvI[(int8_T)17];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)18] = rt_id5lvI[(int8_T)18];
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_cwle[(int8_T)19] = rt_id5lvI[(int8_T)19];

  /* Update for UnitDelay: '<S137>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)0] = rt_prezcI[(int8_T)0];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)1] = rt_prezcI[(int8_T)1];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)2] = rt_prezcI[(int8_T)2];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)3] = rt_prezcI[(int8_T)3];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)4] = rt_prezcI[(int8_T)4];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)5] = rt_prezcI[(int8_T)5];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)6] = rt_prezcI[(int8_T)6];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)7] = rt_prezcI[(int8_T)7];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)8] = rt_prezcI[(int8_T)8];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)9] = rt_prezcI[(int8_T)9];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)10] = rt_prezcI[(int8_T)10];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)11] = rt_prezcI[(int8_T)11];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)12] = rt_prezcI[(int8_T)12];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)13] = rt_prezcI[(int8_T)13];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)14] = rt_prezcI[(int8_T)14];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)15] = rt_prezcI[(int8_T)15];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)16] = rt_prezcI[(int8_T)16];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)17] = rt_prezcI[(int8_T)17];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)18] = rt_prezcI[(int8_T)18];
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_orzm[(int8_T)19] = rt_prezcI[(int8_T)19];

  /* End of Outputs for SubSystem: '<S35>/Steering_Characteristic_Correction_Factor' */

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay'
   */
  rtb_fadn = DMC_Soc_Lat_DWork.Alg_Loop_Delay_DSTATE;

  /* ModelReference: '<S29>/LAT_Loop_Gain_Correction' */
  DMC_Soc_Lat_Loop_Gain_Correction(&rtb_ojre, &rtb_fadn, &rtb_jhwo, rt_dzorI,
                                   (&(LDP_Active)), rt_dptqI, &rtb_hlnm,
    &rtb_n3s4);

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay12'
   */
  rtb_fadn = DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE_hbpm;

  /* ModelReference: '<S35>/DYC_Dynamic_Compensation_Filter' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter((&(ADP_Dyc_Corr_Factor)),
    (&(LKC_Kappa_Command_Arb)), (&(LKC_Kappa_Dot_Command_Arb)), &rtb_hlnm,
    (&(VEH_Vehicle_Speed)), (&(SAC_Controller_Mode_Sig)), rt_dxdkI,
    (&(LDP_Active)), &rtb_fadn, (&(SAC_Disable)), &rtb_fzlt, rt_dptqI, (real32_T*)
    &DMC_Soc_Lat_R32GND, &rtb_d2ky, &rtb_mxz2);

  /* UnitDelay: '<S17>/Unit Delay alg loop' */
  rtb_d50f = DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE;

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  rtb_fadn = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE;

  /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
   *  Constant: '<S19>/Sac_ts'
   */
  rtb_axf1 = ((real32_T)Sac_ts) * 3.05175781E-5F;

  /* MinMax: '<S9>/MinMax2' incorporates:
   *  Sum: '<S19>/Add'
   */
  rtb_fadn += rtb_axf1;

  /* RelationalOperator: '<S19>/Relational Operator4' incorporates:
   *  Constant: '<S19>/Lat_status_first_run_time'
   */
  rtb_hczn = (boolean_T)((int32_T)(rtb_fadn > (((real32_T)
    Lat_status_first_run_time) * 0.0009765625F)));

  /* ModelReference: '<S17>/LAT_Delta_F_Offset_Switch' */
  DMC_Lat_LAT_Delta_F_Offset_Switch((&(SAC_Disable)), rt_kafvI,
    (&(SAC_Controller_Mode_Sig)), rt_pehlI, rt_o3aaI, rt_kaadI, rt_popsI,
    rt_m3xfI, rt_p2o1I, rt_i3p3I, rt_ka1pI, rt_hsldI, (&(DYC_Angle_Per_Kappa)),
                                    (&(VEH_Vehicle_Speed)), &rtb_d50f, rt_pdncI,
    rt_prezI, (&(LKC_Kappa_Command_Arb)), &rtb_euvg, rt_dmmuI, (&(LDP_Active)),
    rt_mkevI, rt_nkaaI, rt_fpnbI, &rtb_hczn, &rtb_fz0g, &rtb_fgeh, &rtb_ofyg,
    rt_m2jwI, &rtb_i4mt, &rtb_ccsn, &rtb_eib2, rt_dzorI, &rtb_f4hc, rt_o3aadI,
    &rtb_ll3p, &rtb_l1xc, &rtb_owpf, &rtb_cep1, rt_m2jwdI, rt_pdncgI);

  /* UnitDelay: '<S7>/Unit Delay' */
  rtb_axf1 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d3m1;

  /* Sum: '<S7>/Add' incorporates:
   *  Constant: '<S7>/Lat_yaw_rate_filter_coeff'
   *  Product: '<S7>/Product'
   *  Sum: '<S7>/Add1'
   */
  rtb_fyle = (((*rt_cjpeI) - rtb_axf1) * (((real32_T)Lat_yaw_rate_filter_coeff) *
    3.05175781E-5F)) + rtb_axf1;

  /* ModelReference: '<S17>/LAT_Yaw_Rate_Offset_Compensation' */
  DMC_Soc_LAT_Yaw_Rate_Offset_Compensation(&rtb_fyle, rt_orb0I, rt_pdp2I,
    &rtb_hqad);

  /* UnitDelay: '<S29>/Alg_Loop_Delay17' */
  rtb_axf1 = DMC_Soc_Lat_DWork.Alg_Loop_Delay17_DSTATE;

  /* ModelReference: '<S35>/SAC_Yaw_Rate_Control' */
  DMC_Lat_SAC_Yaw_Rate_Control((&(SAC_Controller_Mode_Sig)),
    (&(VEH_Vehicle_Speed)), (&(LKC_Kappa_Command_Arb)), &rtb_hqad, &rtb_hlnm,
    &rtb_mxz2, &rtb_n3s4, (&(SAC_Disable)), &rtb_axf1, rt_dzorI, rt_f3r3lI,
    &rtb_aayn);

  /* Logic: '<S458>/Logical Operator' */
  rtb_dm2g = (boolean_T)((int32_T)(!rtb_ef4d));

  /* DiscreteIntegrator: '<S489>/Discrete-Time Integrator' */
  if (((int32_T)rtb_dm2g) ||
      (DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState != ((int8_T)0)))
  {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  rtb_axf1 = DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S489>/Discrete-Time Integrator' */

  /* Relay: '<S489>/Relay' incorporates:
   *  Constant: '<S489>/Constant'
   *  Sum: '<S489>/Add'
   */
  if ((1.0F + rtb_axf1) >= 1.0F) {
    DMC_Soc_Lat_DWork.Relay_Mode = (boolean_T)true;
  } else {
    if ((1.0F + rtb_axf1) <= -1.0F) {
      DMC_Soc_Lat_DWork.Relay_Mode = (boolean_T)false;
    }
  }

  if ((int32_T)DMC_Soc_Lat_DWork.Relay_Mode) {
    rtb_h0la = -1.0F;
  } else {
    rtb_h0la = 1.0F;
  }

  /* End of Relay: '<S489>/Relay' */

  /* Switch: '<S489>/Switch3' incorporates:
   *  Constant: '<S489>/Constant1'
   *  Product: '<S489>/Product2'
   */
  if ((int32_T)rtb_dm2g) {
    rtb_ojsl = 0.0F;
  } else {
    rtb_ojsl = rtb_h0la * rtb_pfif;
  }

  /* End of Switch: '<S489>/Switch3' */

  /* UnitDelay: '<S490>/Unit Delay1' */
  rtb_axf1 = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_g0mi;

  /* Relay: '<S490>/Relay' incorporates:
   *  Constant: '<S490>/Constant'
   *  Sum: '<S490>/Add'
   */
  if ((1.0F + rtb_axf1) >= 1.0F) {
    DMC_Soc_Lat_DWork.Relay_Mode_iryo = (boolean_T)true;
  } else {
    if ((1.0F + rtb_axf1) <= -1.0F) {
      DMC_Soc_Lat_DWork.Relay_Mode_iryo = (boolean_T)false;
    }
  }

  if ((int32_T)DMC_Soc_Lat_DWork.Relay_Mode_iryo) {
    rtb_l0rv = -1.0F;
  } else {
    rtb_l0rv = 1.0F;
  }

  /* End of Relay: '<S490>/Relay' */

  /* Switch: '<S490>/Switch3' incorporates:
   *  Constant: '<S487>/Exc_hec_signal_amplitude'
   *  Constant: '<S490>/Constant1'
   *  Product: '<S490>/Product2'
   */
  if ((int32_T)rtb_dm2g) {
    rtb_e1oo = 0.0F;
  } else {
    rtb_e1oo = rtb_l0rv * 0.1F;
  }

  /* End of Switch: '<S490>/Switch3' */

  /* RelationalOperator: '<S474>/Compare' incorporates:
   *  Constant: '<S458>/Lat_select_input_source1'
   *  Constant: '<S474>/Constant'
   */
  rtb_mbmh = (uint8_T)((int32_T)(((int32_T)Lat_select_input_source) == ((int32_T)
    12)));

  /* DataTypeConversion: '<S462>/Data Type Conversion4' incorporates:
   *  Constant: '<S465>/Constant'
   *  RelationalOperator: '<S465>/Compare'
   *  UnitDelay: '<S458>/Unit Delay'
   */
  rtb_m4lj = (boolean_T)((int32_T)(((int32_T)
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_du4u) < ((int32_T)1)));

  /* DiscreteIntegrator: '<S462>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S465>/Constant'
   *  RelationalOperator: '<S465>/Compare'
   *  UnitDelay: '<S458>/Unit Delay'
   */
  if ((((int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_du4u) < ((int32_T)1)) ||
      (DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_PrevResetState != ((int8_T)0)))
  {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* RelationalOperator: '<S464>/Compare' incorporates:
   *  Constant: '<S464>/Constant'
   *  DiscreteIntegrator: '<S462>/Discrete-Time Integrator1'
   */
  rtb_l15a = (uint8_T)((int32_T)
                       (DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_DSTATE > 0.75F));

  /* Sum: '<S478>/Sum1' incorporates:
   *  UnitDelay: '<S478>/Unit Delay'
   */
  rtb_kw01 = ((int32_T)rtb_l15a) - ((int32_T)
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_f0dp);
  if (rtb_kw01 < ((int32_T)0)) {
    rtb_kw01 = (int32_T)0;
  }

  /* RelationalOperator: '<S482>/Compare' incorporates:
   *  Constant: '<S482>/Constant'
   *  Sum: '<S478>/Sum1'
   */
  rtb_mxcu = (uint8_T)((int32_T)(rtb_kw01 > ((int32_T)0)));

  /* Outputs for Triggered SubSystem: '<S478>/Triggered Subsystem1' incorporates:
   *  TriggerPort: '<S483>/Trigger'
   */
  if ((((int32_T)rtb_mxcu) > ((int32_T)0)) &&
      (DMC_Soc_Lat_PrevZCSigState.TriggeredSubsystem1_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S483>/In1' incorporates:
     *  DiscreteIntegrator: '<S478>/Discrete-Time Integrator'
     */
    DMC_Soc_Lat_B.In1 = DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cs0j;
  }

  DMC_Soc_Lat_PrevZCSigState.TriggeredSubsystem1_Trig_ZCE = (uint8_T)((int32_T)
    ((((int32_T)rtb_mxcu) > ((int32_T)0)) ? ((int32_T)((uint8_T)POS_ZCSIG)) :
     ((int32_T)((uint8_T)ZERO_ZCSIG))));

  /* End of Outputs for SubSystem: '<S478>/Triggered Subsystem1' */

  /* Sum: '<S478>/Add1' incorporates:
   *  DiscreteIntegrator: '<S478>/Discrete-Time Integrator'
   */
  rtb_pfif = DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cs0j -
    DMC_Soc_Lat_B.In1;

  /* RelationalOperator: '<S478>/Relational Operator' incorporates:
   *  Constant: '<S478>/EXC_TargetTime'
   */
  rtb_fzlt = (boolean_T)((int32_T)(rtb_pfif < 20.0F));

  /* MinMax: '<S477>/MinMax' incorporates:
   *  MinMax: '<S478>/MinMax1'
   */
  rtb_maat = (real32_T)rtb_l15a;

  /* Product: '<S478>/Product5' incorporates:
   *  DataTypeConversion: '<S478>/Data Type Conversion1'
   */
  rtb_ = ((real32_T)rtb_fzlt) * rtb_maat;

  /* Saturate: '<S462>/Saturation2' */
  if (rtb_ > 1.0F) {
    rtb_fit4 = 1.0F;
  } else if (rtb_ < 0.0F) {
    rtb_fit4 = 0.0F;
  } else {
    rtb_fit4 = rtb_;
  }

  /* End of Saturate: '<S462>/Saturation2' */

  /* Logic: '<S462>/Logical Operator5' incorporates:
   *  Constant: '<S466>/Constant'
   *  Logic: '<S462>/Logical Operator4'
   *  RelationalOperator: '<S466>/Compare'
   */
  rtb_e5xk = (boolean_T)((int32_T)(!((((int32_T)rtb_mbmh) != ((int32_T)0)) &&
    (rtb_fit4 == 1.0F))));

  /* DiscreteIntegrator: '<S480>/Discrete-Time Integrator' */
  if (((int32_T)rtb_e5xk) ||
      (DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState_lpiz != ((int8_T)
        0))) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cipt = 0.0F;
  }

  /* Relay: '<S480>/Relay' incorporates:
   *  Constant: '<S480>/Constant'
   *  DiscreteIntegrator: '<S480>/Discrete-Time Integrator'
   *  Sum: '<S480>/Add'
   */
  if ((1.0F + DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cipt) >= 1.0F) {
    DMC_Soc_Lat_DWork.Relay_Mode_fpid = (boolean_T)true;
  } else {
    if ((1.0F + DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cipt) <= -1.0F)
    {
      DMC_Soc_Lat_DWork.Relay_Mode_fpid = (boolean_T)false;
    }
  }

  if ((int32_T)DMC_Soc_Lat_DWork.Relay_Mode_fpid) {
    rtb_ = -1.0F;
  } else {
    rtb_ = 1.0F;
  }

  /* End of Relay: '<S480>/Relay' */

  /* Product: '<S480>/Product2' incorporates:
   *  Constant: '<S463>/Exc_trq_signal_amplitude'
   */
  tmp_2 = rtb_ * (((real32_T)Exc_trq_signal_amplitude) * 0.0009765625F);

  /* Switch: '<S480>/Switch3' incorporates:
   *  Constant: '<S480>/Constant1'
   */
  if ((int32_T)rtb_e5xk) {
    tmp_2 = 0.0F;
  }

  /* End of Switch: '<S480>/Switch3' */

  /* Constant: '<S478>/EXC_Start_Freq' */
  rtb_afoa = ((real32_T)Exc_chirp_start_frequency) * 0.0009765625F;

  /* Product: '<S478>/Product4' incorporates:
   *  Constant: '<S478>/EXC_End_Freq'
   *  DataTypeConversion: '<S478>/Data Type Conversion1'
   *  Gain: '<S478>/Gain'
   *  Gain: '<S478>/Gain2'
   *  Gain: '<S478>/Gain3'
   *  Product: '<S478>/Product'
   *  Product: '<S478>/Product1'
   *  Product: '<S478>/Product2'
   *  Sum: '<S478>/Add2'
   *  Sum: '<S478>/Sum'
   *  Trigonometry: '<S478>/Output'
   */
  rtb_jwxe = (rtb_maat * ((real32_T)sin((real_T)((real32_T)(rtb_pfif *
    ((rtb_pfif * (0.5F * ((6.28318548F * (10.0F - rtb_afoa)) / 20.0F))) +
     (6.28318548F * rtb_afoa))))))) * ((real32_T)rtb_fzlt);

  /* Constant: '<S458>/Exc_chirp_delta_torque' */
  rtb_afoa = ((real32_T)Exc_chirp_delta_torque) * 0.0009765625F;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Product: '<S477>/Product3'
   *  UnitDelay: '<S477>/Unit Delay'
   */
  rtb_maat = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24 *
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24;
  if (rtb_maat >= 0.1F) {
  } else {
    rtb_maat = 0.1F;
  }

  /* Product: '<S477>/Product1' incorporates:
   *  Constant: '<S458>/Exc_chirp_ay_offset'
   *  Constant: '<S477>/VEH_Vehicle_Wheel_Base'
   *  Gain: '<S477>/VEH_Vehicle_Selfsteering_Factor'
   *  Gain: '<S481>/Gain'
   *  MinMax: '<S477>/MinMax'
   *  Product: '<S477>/Divide'
   *  Product: '<S477>/Product2'
   *  Sum: '<S477>/Add1'
   *  UnitDelay: '<S477>/Unit Delay'
   */
  rtb_pfif = ((((real32_T)Exc_chirp_ay_offset) * 0.0009765625F) / rtb_maat) *
    (57.2957802F * (2.986F + (0.0037F * (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24
        * DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24))));

  /* MinMax: '<S477>/MinMax1' */
  if (rtb_pfif <= 12.0F) {
  } else {
    rtb_pfif = 12.0F;
  }

  /* End of MinMax: '<S477>/MinMax1' */

  /* Switch: '<S462>/Switch3' incorporates:
   *  Constant: '<S458>/Lat_select_input_source1'
   *  Constant: '<S468>/Constant'
   *  Constant: '<S473>/Constant'
   *  Logic: '<S462>/Logical Operator3'
   *  RelationalOperator: '<S468>/Compare'
   *  RelationalOperator: '<S473>/Compare'
   */
  if ((((int32_T)Lat_select_input_source) == ((int32_T)11)) || (((int32_T)
        Lat_select_input_source) == ((int32_T)12))) {
  } else {
    rtb_afoa = rtb_pfif;
  }

  /* End of Switch: '<S462>/Switch3' */

  /* Switch: '<S462>/Switch1' incorporates:
   *  Product: '<S478>/Product3'
   */
  if (((int32_T)rtb_mbmh) != ((int32_T)0)) {
  } else {
    tmp_2 = rtb_jwxe * rtb_afoa;
  }

  /* End of Switch: '<S462>/Switch1' */

  /* Switch: '<S462>/Switch4' incorporates:
   *  Constant: '<S458>/Lat_select_input_source1'
   *  Constant: '<S462>/Constant5'
   *  Constant: '<S469>/Constant'
   *  Constant: '<S472>/Constant'
   *  Logic: '<S462>/Logical Operator2'
   *  RelationalOperator: '<S469>/Compare'
   *  RelationalOperator: '<S472>/Compare'
   */
  if ((((int32_T)Lat_select_input_source) == ((int32_T)11)) || (((int32_T)
        Lat_select_input_source) == ((int32_T)12))) {
    tmp_2 = 0.0F;
  }

  /* End of Switch: '<S462>/Switch4' */

  /* UnitDelay: '<S462>/Unit Delay5' */
  rtb_fzlt = DMC_Soc_Lat_DWork.UnitDelay5_DSTATE_jjz1;

  /* Switch: '<S462>/Switch' incorporates:
   *  Constant: '<S462>/Constant2'
   */
  if ((int32_T)rtb_fzlt) {
  } else {
    tmp_2 = 0.0F;
  }

  /* End of Switch: '<S462>/Switch' */

  /* Switch: '<S462>/Switch6' incorporates:
   *  Constant: '<S462>/Constant7'
   */
  if ((int32_T)rtb_fzlt) {
  } else {
    rtb_pfif = 0.0F;
  }

  /* End of Switch: '<S462>/Switch6' */

  /* MultiPortSwitch: '<S461>/Multiport Switch' incorporates:
   *  Constant: '<S458>/Lat_select_input_source1'
   *  Constant: '<S461>/Constant4'
   *  Constant: '<S461>/LAT_Const'
   *  Sum: '<S461>/Add'
   */
  switch (Lat_select_input_source) {
   case 1:
    rtb_afoa = *rt_kwugI;
    break;

   case 2:
    rtb_afoa = 0.0F;
    break;

   case 3:
    rtb_afoa = 0.0F;
    break;

   case 4:
    rtb_afoa = 0.0F;
    break;

   case 5:
    rtb_afoa = (*rt_kkebI) + rtb_ojsl;
    break;

   case 6:
    rtb_afoa = rtb_e1oo;
    break;

   case 7:
    rtb_afoa = rtb_ojsl;
    break;

   case 8:
    rtb_afoa = 0.0F;
    break;

   case 9:
    rtb_afoa = 0.0F;
    break;

   case 10:
    /* Saturate: '<S462>/EXC_Limit_Steer_Angle' */
    if (tmp_2 > 20.0F) {
      rtb_afoa = 20.0F;
    } else if (tmp_2 < -20.0F) {
      rtb_afoa = -20.0F;
    } else {
      rtb_afoa = tmp_2;
    }

    /* End of Saturate: '<S462>/EXC_Limit_Steer_Angle' */
    break;

   case 11:
    rtb_afoa = rtb_pfif;
    break;

   case 12:
    rtb_afoa = rtb_pfif;
    break;

   case 13:
    rtb_afoa = 0.0F;
    break;

   default:
    rtb_afoa = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S461>/Multiport Switch' */

  /* Sum: '<S133>/Add2' */
  rtb_jwxe = (*rt_f3r3lI) + rtb_afoa;

  /* S-Function (sfix_bitop): '<S133>/Bitwise Operator3' */
  rtb_kw01 = (int32_T)((uint32_T)(SAC_Controller_Mode_Sig & ((uint32_T)128U)));

  /* UnitDelay: '<S29>/Alg_Loop_Delay5' */
  rtb_afoa = DMC_Soc_Lat_DWork.Alg_Loop_Delay5_DSTATE;

  /* ModelReference: '<S35>/SAC_Damping_Filter' */
  DMC_Soc_Lat_SAC_Damping_Filter(&rtb_afoa, &rtb_n3s4,
    (&(SAC_Controller_Mode_Sig)), (&(VEH_Vehicle_Speed)), rt_dzorI,
    (&(LDP_Active)), rt_dptqI, &rtb_akp0);

  /* Sum: '<S133>/Add1' */
  rtb_macq = ((rtb_n3s4 + DYC_Steer_Angle_Feedforward) + (*rt_f3r3lI)) +
    rtb_akp0;

  /* Switch: '<S133>/Switch4' incorporates:
   *  Constant: '<S138>/Constant'
   *  RelationalOperator: '<S138>/Compare'
   */
  if (((uint32_T)rtb_kw01) == ((uint32_T)128U)) {
    rtb_macq = rtb_jwxe;
  }

  /* End of Switch: '<S133>/Switch4' */

  /* Abs: '<S42>/Abs' */
  rtb_afoa = (real32_T)fabs((real_T)rtb_macq);

  /* Logic: '<S293>/Logical Operator' incorporates:
   *  Constant: '<S301>/Constant'
   *  RelationalOperator: '<S301>/Compare'
   *  UnitDelay: '<S47>/Alg_Loop'
   */
  rtb_fzlt = (boolean_T)((int32_T)(!((boolean_T)((int32_T)
    ((DMC_Soc_Lat_DWork.Alg_Loop_DSTATE > 0.0F) ^ ((int32_T)rtb_pkm5))))));

  /* DataTypeConversion: '<S294>/Data Type Conversion (1)' incorporates:
   *  Constant: '<S294>/Sac_parity_time_const_barrier'
   *
   * Block description for '<S294>/Sac_parity_time_const_barrier':
   *  u: seconds
   */
  rtb_pfif = ((real32_T)Sac_parity_time_const_barrier) * 0.0009765625F;

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S294>/No_Time_Constant'
   *  Logic: '<S294>/And Logical Operator'
   *  Logic: '<S294>/Or Logical Operator'
   *
   * Block description for '<S294>/No_Time_Constant':
   *  u: seconds
   */
  if ((((int32_T)rtb_jomt) && ((int32_T)rtb_fzlt)) || ((int32_T)(*rt_pynyI))) {
    rtb_pfif = 0.0F;
  }

  /* End of Switch: '<S294>/Switch' */

  /* UnitDelay: '<S29>/Alg_Loop_Delay3' */
  rtb_ni1l = DMC_Soc_Lat_DWork.Alg_Loop_Delay3_DSTATE;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay18'
   */
  rtb_maat = DMC_Soc_Lat_DWork.Alg_Loop_Delay18_DSTATE;

  /* UnitDelay: '<S29>/Alg_Loop_Delay4' */
  rtb_pdty = DMC_Soc_Lat_DWork.Alg_Loop_Delay4_DSTATE;

  /* UnitDelay: '<S29>/Alg_Loop_Delay10' */
  rtb_hwhx = DMC_Soc_Lat_DWork.Alg_Loop_Delay10_DSTATE;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  UnitDelay: '<S49>/Unit Delay alg loop'
   */
  rtb_l1ll = DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE_kepf;

  /* UnitDelay: '<S49>/Unit Delay alg loop1' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelayalgloop1_DSTATE;

  /* Sum: '<S49>/Add3' */
  rtb_eh0v = rtb_l1ll - rtb_gmy5;

  /* Constant: '<S491>/Sac_derating_override' */
  rtb_gmy5 = (real32_T)Sac_derating_override;

  /* Switch: '<S491>/Switch8' */
  if ((int32_T)rtb_hdiu) {
  } else {
    rtb_gmy5 = *rt_i3nmI;
  }

  /* End of Switch: '<S491>/Switch8' */

  /* Gain: '<S37>/Gain1' */
  rtb_gmy5 *= 0.01F;

  /* MinMax: '<S221>/MinMax1' */
  if (rtb_gmy5 <= 1.0F) {
    rtb_ojsl = rtb_gmy5;
  } else {
    rtb_ojsl = 1.0F;
  }

  /* End of MinMax: '<S221>/MinMax1' */

  /* UnitDelay: '<S221>/Unit Delay1' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e43m;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Sum: '<S221>/Add2'
   */
  rtb_l1ll = rtb_ojsl - rtb_gmy5;

  /* DataTypeConversion: '<S221>/Data Type Conversion2' incorporates:
   *  Constant: '<S221>/Tdf_derating_level_decrement'
   */
  rtb_cfdi = ((real32_T)Tdf_derating_level_decrement) * 0.0009765625F;

  /* Switch: '<S221>/Switch2' incorporates:
   *  Constant: '<S221>/Constant5'
   *  RelationalOperator: '<S221>/Relational Operator'
   */
  if (rtb_l1ll >= 0.0F) {
  } else {
    /* MinMax: '<S81>/MinMax2' incorporates:
     *  Gain: '<S221>/Gain'
     */
    rtb_l1ll = -rtb_cfdi;
  }

  /* End of Switch: '<S221>/Switch2' */

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Sum: '<S221>/Add3'
   */
  rtb_l1ll += rtb_gmy5;

  /* Switch: '<S221>/Switch1' incorporates:
   *  Constant: '<S221>/Constant3'
   *  MinMax: '<S221>/MinMax'
   */
  if ((int32_T)SAC_Disable) {
    rtb_ez30 = 0.0F;
  } else if (rtb_l1ll >= 0.0F) {
    /* MinMax: '<S221>/MinMax' */
    rtb_ez30 = rtb_l1ll;
  } else {
    /* MinMax: '<S221>/MinMax' */
    rtb_ez30 = 0.0F;
  }

  /* End of Switch: '<S221>/Switch1' */

  /* UnitDelay: '<S29>/Alg_Loop_Delay15' */
  rtb_gkzz = DMC_Soc_Lat_DWork.Alg_Loop_Delay15_DSTATE;

  /* UnitDelay: '<S29>/Alg_Loop_Delay16' */
  rtb_hvhi = DMC_Soc_Lat_DWork.Alg_Loop_Delay16_DSTATE;

  /* UnitDelay: '<S29>/Alg_Loop_Delay19' */
  rtb_hdiu = DMC_Soc_Lat_DWork.Alg_Loop_Delay19_DSTATE;

  /* ModelReference: '<S29>/TDF_Torque_Derating_Function' */
  DMC_Lat_TDF_Torque_Derating_Function((real32_T*)&DMC_Soc_Lat_R32GND, rt_dmmuI,
    rt_c4rhI, (boolean_T*)&DMC_Soc_Lat_BGND, &rtb_maat, (&(SAC_Disable)),
    &DMC_Soc_Lat_ConstP.pooled3, (&(LDP_Active)), &rtb_pdty, &rtb_hwhx,
    &rtb_c4yx, (real32_T*)&DMC_Soc_Lat_R32GND, &rtb_pkm5, (&(VEH_Vehicle_Speed)),
                                       (&(LKC_Kappa_Command_Arb)), rt_o3aadI,
    &rtb_eh0v, rt_dfm1I, rt_h1w1I, &rtb_ez30, &rtb_gkzz, &rtb_hvhi, &rtb_hdiu,
    &rtb_ep44, &rtb_ncfe, &rtb_kzgj, rt_dmmu3I, rt_gyqsrI, &rtb_b5si, &rtb_m04f,
    &rtb_eg0o, &rtb_ifco, rt_dxdktI, &rtb_exxx, &rtb_dmt0, &rtb_gfou, &rtb_n1zt,
    &rtb_pqrc, &rtb_eypw);

  /* UnitDelay: '<S29>/Alg_Loop_Delay1' */
  rtb_cfdi = DMC_Soc_Lat_DWork.Alg_Loop_Delay1_DSTATE;

  /* UnitDelay: '<S29>/Alg_Loop_Delay11' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.Alg_Loop_Delay11_DSTATE;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay13'
   */
  rtb_l1ll = DMC_Soc_Lat_DWork.Alg_Loop_Delay13_DSTATE;

  /* Product: '<S36>/Product8' */
  rtb_hwhx = VEH_Vehicle_Speed * rtb_hqad;

  /* UnitDelay: '<S215>/Unit Delay' */
  rtb_pdty = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dpkx;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Sum: '<S215>/Add1'
   */
  rtb_maat = rtb_hwhx - rtb_pdty;

  /* Sum: '<S215>/Add' incorporates:
   *  Constant: '<S203>/Lat_ay_control_cmd_filter_coeff'
   *  Product: '<S215>/Product'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dpkx = (rtb_maat * (((real32_T)
    Lat_ay_control_cmd_filter_coeff) * 3.05175781E-5F)) + rtb_pdty;

  /* Gain: '<S215>/Sac_one_by_ts' incorporates:
   *  Sum: '<S215>/Add2'
   */
  rtb_m0pk = ((real32_T)Sac_one_by_ts) *
    (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dpkx - rtb_pdty);

  /* Abs: '<S203>/Abs1' */
  rtb_pdty = (real32_T)fabs((real_T)rtb_m0pk);

  /* ModelReference: '<S29>/SAC_Angle_Command_Fading' */
  DMC_Lat_SAC_Angle_Command_Fading(&rtb_macq, (&(SAC_Disable)), rt_o3aadI,
    (&(VEH_Vehicle_Speed)), &rtb_ni1l, (&(LDP_Active)), &rtb_eib2, &rtb_ifco,
    rt_pynyI, rt_pxsgI, &rtb_cfdi, &rtb_gmy5, rt_dptqI, &rtb_futb, &rtb_l1ll,
    &rtb_euvg, &rtb_dzi1, rt_dzorI, &rtb_pdty, &DMC_Soc_Lat_ConstP.pooled65,
    &DMC_Soc_Lat_ConstP.pooled65, &DMC_Soc_Lat_ConstP.pooled15, &rtb_hd5l,
    &rtb_hbvj, &rtb_pgfp, &rtb_oc5b, &rtb_gta3, &rtb_kzhy, &rtb_ozv1, &rtb_l1lr);

  /* Constant: '<S271>/Lat_max_ay_aes'
   *
   * Block description for '<S271>/Lat_max_ay_aes':
   *  u: m/s^2
   */
  rtb_cfdi = ((real32_T)Lat_max_ay_aes) * 0.0009765625F;

  /* Gain: '<S271>/mps2kph' */
  rtb_gmy5 = 3.6F * VEH_Vehicle_Speed;

  /* Lookup_n-D: '<S271>/LAT_Ay_Max_Scheduling'
   *
   * Block description for '<S271>/LAT_Ay_Max_Scheduling':
   *  u: m/s^2
   */
  rtb_gmy5 = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_gmy5,
    (&(Lat_ay_max_x_scheduling[0])), (&(Lat_ay_max_y_scheduling[0])), 11U);

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Constant: '<S271>/Lat_max_ay_tja'
   *
   * Block description for '<S271>/Lat_max_ay_tja':
   *  u: m/s^2
   */
  rtb_l1ll = ((real32_T)Lat_max_ay_tja) * 0.0009765625F;

  /* Switch: '<S271>/Switch (1)' */
  if ((int32_T)LDP_Active) {
  } else {
    rtb_gmy5 = rtb_l1ll;
  }

  /* End of Switch: '<S271>/Switch (1)' */

  /* Switch: '<S271>/Switch (2)' */
  if ((int32_T)(*rt_dptqI)) {
  } else {
    rtb_cfdi = rtb_gmy5;
  }

  /* End of Switch: '<S271>/Switch (2)' */

  /* UnitDelay: '<S29>/Alg_Loop_Delay7' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.Alg_Loop_Delay7_DSTATE;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay2'
   */
  rtb_l1ll = DMC_Soc_Lat_DWork.Alg_Loop_Delay2_DSTATE;

  /* MinMax: '<S207>/MinMax2' */
  if (rtb_gmy5 <= rtb_l1ll) {
  } else {
    rtb_gmy5 = rtb_l1ll;
  }

  /* End of MinMax: '<S207>/MinMax2' */

  /* S-Function (sfix_bitop): '<S204>/Bitwise Operator3' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   */
  tmp_w = (uint16_T)((int32_T)(((int32_T)Dmc_configuration_mode_2) & ((int32_T)2)));

  /* Logic: '<S209>/Logical Operator' */
  rtb_hdiu = SAC_Disable;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Abs: '<S203>/Abs5'
   */
  rtb_maat = (real32_T)fabs((real_T)rtb_hwhx);

  /* Sum: '<S273>/Sub' incorporates:
   *  Abs: '<S273>/Abs'
   *  Constant: '<S273>/Lat_support_torque_threshold'
   *
   * Block description for '<S273>/Lat_support_torque_threshold':
   *  u: Nm
   */
  tmp_3 = ((real32_T)fabs((real_T)(*rt_dmmuI))) - (((real32_T)
    Lat_support_torque_threshold) * 0.0009765625F);

  /* MinMax: '<S273>/Max' */
  if (tmp_3 >= 0.0F) {
  } else {
    tmp_3 = 0.0F;
  }

  /* Signum: '<S273>/Sign (1)' */
  if ((*rt_dmmuI) < 0.0F) {
    rtb_ojsl = -1.0F;
  } else if ((*rt_dmmuI) > 0.0F) {
    rtb_ojsl = 1.0F;
  } else {
    rtb_ojsl = *rt_dmmuI;
  }

  /* Signum: '<S273>/Sign (2)' */
  if (rtb_macq < 0.0F) {
    rtb_e1oo = -1.0F;
  } else if (rtb_macq > 0.0F) {
    rtb_e1oo = 1.0F;
  } else {
    rtb_e1oo = rtb_macq;
  }

  /* Product: '<S273>/Product (2)' incorporates:
   *  MinMax: '<S273>/Max'
   *  Product: '<S273>/Product (1)'
   *  Signum: '<S273>/Sign (1)'
   *  Signum: '<S273>/Sign (2)'
   */
  rtb_iwln = (rtb_ojsl * tmp_3) * rtb_e1oo;

  /* MinMax: '<S278>/Max' */
  if (0.0F >= rtb_iwln) {
    rtb_iwln = 0.0F;
  }

  /* End of MinMax: '<S278>/Max' */

  /* Lookup_n-D: '<S273>/LAT_Support_Torque_Scheduling' incorporates:
   *  Gain: '<S273>/mps2kph'
   *
   * Block description for '<S273>/LAT_Support_Torque_Scheduling':
   *  u: 1
   */
  tmp_3 = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * VEH_Vehicle_Speed,
    (&(Lat_support_factor_x_schedul[0])), (&(Lat_support_factor_y_schedul[0])),
    10U);

  /* Product: '<S278>/Product' incorporates:
   *  Constant: '<S273>/Lat_support_torque_gain'
   *  Product: '<S273>/Product (3)'
   *
   * Block description for '<S273>/Lat_support_torque_gain':
   *  u: 1/Nm
   */
  rtb_iwln *= (((real32_T)Lat_support_torque_gain) * 0.0009765625F) * tmp_3;

  /* MinMax: '<S278>/Min' */
  if (1.0F <= rtb_iwln) {
    rtb_iwln = 1.0F;
  }

  /* End of MinMax: '<S278>/Min' */

  /* Sum: '<S279>/Add' incorporates:
   *  Constant: '<S273>/Lat_support_memshp_filter_coeff'
   *  Product: '<S279>/Product'
   *  Sum: '<S279>/Sub'
   *  UnitDelay: '<S279>/Unit Delay'
   *
   * Block description for '<S273>/Lat_support_memshp_filter_coeff':
   *  u: 1
   */
  rtb_jnhy = ((rtb_iwln - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hnnx) * (((real32_T)
    Lat_support_memshp_filter_coeff) * 3.05175781E-5F)) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hnnx;

  /* Sum: '<S275>/Add' incorporates:
   *  Constant: '<S272>/Lat_support_ay_filter_coeff'
   *  Constant: '<S272>/Lat_support_enhancement_factor'
   *  Product: '<S272>/Product (1)'
   *  Product: '<S272>/Product (2)'
   *  Product: '<S275>/Product'
   *  Sum: '<S275>/Sub'
   *  UnitDelay: '<S275>/Unit Delay'
   *
   * Block description for '<S272>/Lat_support_ay_filter_coeff':
   *  u: 1
   *
   * Block description for '<S272>/Lat_support_enhancement_factor':
   *  u: 1
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fo0b += (((rtb_cfdi * (((real32_T)
    Lat_support_enhancement_factor) * 0.0009765625F)) * rtb_jnhy) -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fo0b) * (((real32_T)
    Lat_support_ay_filter_coeff) * 3.05175781E-5F);

  /* Gain: '<S36>/Lat_ay_cmd_margin_factor' incorporates:
   *  Sum: '<S272>/Add'
   */
  rtb_jwxe = (((real32_T)Lat_ay_cmd_margin_factor) * 0.0009765625F) * (rtb_cfdi
    + DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fo0b);

  /* UnitDelay: '<S36>/Alg_loop' */
  rtb_ovjx = DMC_Soc_Lat_DWork.Alg_loop_DSTATE;

  /* UnitDelay: '<S216>/Unit Delay1' */
  tmp_3 = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w;

  /* Switch: '<S216>/Switch4' incorporates:
   *  RelationalOperator: '<S216>/Relational Operator1'
   *  UnitDelay: '<S214>/Unit Delay2'
   *  UnitDelay: '<S216>/Unit Delay1'
   */
  if (DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 >=
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w) {
    tmp_3 = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2;
  }

  /* End of Switch: '<S216>/Switch4' */

  /* Switch: '<S216>/Switch5' incorporates:
   *  Constant: '<S216>/Constant4'
   *  Logic: '<S214>/Logical Operator1'
   */
  if (!rtb_ovjx) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w = 0.0F;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w = tmp_3;
  }

  /* End of Switch: '<S216>/Switch5' */

  /* RelationalOperator: '<S216>/Relational Operator2' incorporates:
   *  Constant: '<S216>/Lat_ay_decreasing_threshold'
   *  Sum: '<S216>/Add1'
   *  UnitDelay: '<S214>/Unit Delay2'
   */
  rtb_bhbp = (boolean_T)((int32_T)((DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w -
    DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2) >= (((real32_T)
    Lat_ay_decreasing_threshold) * 0.0009765625F)));

  /* Gain: '<S203>/Lat_ay_parity_time_const' */
  tmp_3 = (((real32_T)Lat_ay_parity_time_const) * 0.0009765625F) * rtb_pdty;

  /* Switch: '<S214>/Switch3' incorporates:
   *  Constant: '<S214>/Constant3'
   *  MinMax: '<S214>/MinMax5'
   */
  if (((int32_T)tmp_w) != ((int32_T)0)) {
    tmp_3 = 0.0F;
  } else {
    if (rtb_jwxe <= tmp_3) {
      /* MinMax: '<S214>/MinMax5' */
      tmp_3 = rtb_jwxe;
    }
  }

  /* End of Switch: '<S214>/Switch3' */

  /* Sum: '<S214>/Add2' incorporates:
   *  UnitDelay: '<S214>/Unit Delay2'
   */
  tmp_3 -= DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2;

  /* Switch: '<S214>/Switch1' incorporates:
   *  Constant: '<S214>/Constant1'
   *  Logic: '<S214>/Logical Operator2'
   */
  if (((int32_T)rtb_bhbp) && ((int32_T)rtb_ovjx)) {
    rtb_pnn5 = 0.0F;
  } else {
    rtb_pnn5 = tmp_3;
  }

  /* End of Switch: '<S214>/Switch1' */

  /* RelationalOperator: '<S214>/Relational Operator' incorporates:
   *  Constant: '<S214>/Constant5'
   */
  rtb_ohj2 = (boolean_T)((int32_T)(tmp_3 >= 0.0F));

  /* Abs: '<S214>/Abs' */
  tmp_3 = (real32_T)fabs((real_T)tmp_3);

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Constant: '<S214>/Lat_ay_threshold_decrement'
   *  DataTypeConversion: '<S214>/Data Type Conversion2'
   */
  rtb_cy3g = ((real32_T)Lat_ay_threshold_decrement) * 0.0009765625F;

  /* Switch: '<S214>/Switch2' incorporates:
   *  Gain: '<S214>/Gain'
   *  MinMax: '<S214>/MinMax1'
   */
  if ((int32_T)rtb_ohj2) {
  } else {
    if (tmp_3 <= rtb_cy3g) {
      /* MinMax: '<S214>/MinMax1' */
      rtb_cy3g = tmp_3;
    }

    rtb_pnn5 = -rtb_cy3g;
  }

  /* End of Switch: '<S214>/Switch2' */

  /* Sum: '<S214>/Add3' incorporates:
   *  UnitDelay: '<S214>/Unit Delay2'
   */
  rtb_pnn5 += DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2;

  /* MinMax: '<S214>/MinMax' */
  if (rtb_pnn5 >= 0.0F) {
    DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 = rtb_pnn5;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 = 0.0F;
  }

  /* End of MinMax: '<S214>/MinMax' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Sum: '<S203>/Add2'
   *  Sum: '<S214>/Add4'
   */
  rtb_cy3g = (rtb_jwxe - DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2) - rtb_maat;

  /* Switch: '<S204>/Switch2' incorporates:
   *  Constant: '<S204>/Constant1'
   */
  if (((int32_T)tmp_w) != ((int32_T)0)) {
    rtb_m3dz = 0.0F;
  } else {
    rtb_m3dz = rtb_cy3g;
  }

  /* End of Switch: '<S204>/Switch2' */

  /* UnitDelay: '<S209>/Unit Delay' */
  rtb_pnn5 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bp0l;

  /* Switch: '<S209>/Switch1' incorporates:
   *  Constant: '<S209>/Constant3'
   */
  if ((int32_T)rtb_hdiu) {
    rtb_pnn5 = 0.0F;
  }

  /* End of Switch: '<S209>/Switch1' */

  /* UnitDelay: '<S206>/Alg_loop1' */
  rtb_ovjx = DMC_Soc_Lat_DWork.Alg_loop1_DSTATE;

  /* UnitDelay: '<S206>/Unit Delay1' */
  rtb_bhbp = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_foqo;

  /* Logic: '<S206>/Logical Operator3' incorporates:
   *  Constant: '<S206>/Lat_ay_ctrl_reset_thrs'
   *  RelationalOperator: '<S206>/Relational Operator2'
   *  RelationalOperator: '<S206>/Relational Operator7'
   */
  rtb_ovjx = (boolean_T)((int32_T)(((rtb_maat <= (((real32_T)
    Lat_ay_ctrl_reset_thrs) * 0.0009765625F)) || ((int32_T)rtb_ovjx)) ||
    (rtb_bhbp != SAC_Disable)));

  /* Switch: '<S209>/Switch3' incorporates:
   *  Constant: '<S209>/Lat_ay_ctrl_discharge_coeff'
   *  Product: '<S209>/Product1'
   */
  if ((int32_T)rtb_ovjx) {
    rtb_pnn5 *= 0.9F;
  }

  /* End of Switch: '<S209>/Switch3' */

  /* Product: '<S209>/Product' incorporates:
   *  Constant: '<S209>/Lat_ay_controller_coeff'
   *  Sum: '<S209>/Add1'
   */
  rtb_iwln = (rtb_m3dz - rtb_pnn5) * (((real32_T)Lat_ay_controller_coeff) *
    3.05175781E-5F);

  /* Switch: '<S209>/Switch2' incorporates:
   *  Constant: '<S209>/Constant1'
   */
  if ((int32_T)rtb_hdiu) {
    rtb_iwln = 0.0F;
  }

  /* End of Switch: '<S209>/Switch2' */

  /* Sum: '<S209>/Add' */
  rtb_iwln += rtb_pnn5;

  /* MinMax: '<S209>/MinMax' */
  if (rtb_iwln >= 0.0F) {
  } else {
    rtb_iwln = 0.0F;
  }

  /* End of MinMax: '<S209>/MinMax' */

  /* MinMax: '<S209>/MinMax1' */
  if (rtb_l1ll <= rtb_iwln) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bp0l = rtb_l1ll;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bp0l = rtb_iwln;
  }

  /* End of MinMax: '<S209>/MinMax1' */

  /* S-Function (sfix_bitop): '<S208>/Bitwise Operator1' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   */
  tmp_x = (uint16_T)((int32_T)(((int32_T)Dmc_configuration_mode_2) & ((int32_T)
    16)));

  /* Outputs for Enabled SubSystem: '<S208>/LAT_Sac_Compensation' incorporates:
   *  EnablePort: '<S212>/Enable'
   */
  /* Logic: '<S208>/Logical Operator' incorporates:
   *  Constant: '<S212>/Lat_ay_compensation_time_const'
   */
  if (!(((int32_T)tmp_x) != ((int32_T)0))) {
    rtb_jwxe = ((real32_T)Lat_ay_compensation_time_const) * 0.0009765625F;

    /* MinMax: '<S213>/MinMax' incorporates:
     *  Constant: '<S212>/Lat_ay_compensation_time_const'
     */
    if (rtb_jwxe >= 0.006F) {
    } else {
      rtb_jwxe = 0.006F;
    }

    /* End of MinMax: '<S213>/MinMax' */

    /* Product: '<S213>/Product1' */
    rtb_ojsl = rtb_jwxe * rtb_jwxe;

    /* Sum: '<S213>/Add3' incorporates:
     *  Constant: '<S213>/Constant2'
     *  Constant: '<S213>/Constant3'
     *  Constant: '<S213>/Constant4'
     *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator2'
     *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator3'
     *  Product: '<S213>/Divide1'
     *  Product: '<S213>/Divide2'
     *  Product: '<S213>/Divide3'
     *  Product: '<S213>/Product3'
     *  Product: '<S213>/Product4'
     *  Product: '<S213>/Product5'
     */
    rtb_e1oo = (((1.0F / rtb_ojsl) * rtb_m3dz) - ((1.0F / rtb_ojsl) *
      DMC_Soc_Lat_DWork.DiscreteTimeIntegrator3_DSTATE)) - ((2.0F / rtb_jwxe) *
      DMC_Soc_Lat_DWork.DiscreteTimeIntegrator2_DSTATE);

    /* DotProduct: '<S212>/Dot Product1' incorporates:
     *  Constant: '<S212>/Lat_ay_comp_eps_damping'
     *  Constant: '<S212>/Lat_ay_comp_eps_time_const '
     *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator2'
     *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator3'
     *  Gain: '<S212>/Gain'
     *  Product: '<S212>/Product'
     *  Product: '<S212>/Product1'
     *  SignalConversion: '<S212>/TmpSignal ConversionAtDot Product1Inport1'
     */
    DMC_Soc_Lat_B.DotProduct1 =
      (DMC_Soc_Lat_DWork.DiscreteTimeIntegrator3_DSTATE +
       (DMC_Soc_Lat_DWork.DiscreteTimeIntegrator2_DSTATE * (2.0F * ((((real32_T)
            Lat_ay_comp_eps_damping) * 0.0009765625F) * (((real32_T)
            Lat_ay_comp_eps_time_const) * 0.0009765625F))))) + (rtb_e1oo *
      ((((real32_T)Lat_ay_comp_eps_time_const) * 0.0009765625F) * (((real32_T)
      Lat_ay_comp_eps_time_const) * 0.0009765625F)));

    /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator3' incorporates:
     *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator2'
     */
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator3_DSTATE += 0.01F *
      DMC_Soc_Lat_DWork.DiscreteTimeIntegrator2_DSTATE;

    /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator2' */
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator2_DSTATE += 0.01F * rtb_e1oo;
  }

  /* End of Logic: '<S208>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S208>/LAT_Sac_Compensation' */

  /* Switch: '<S208>/Switch' */
  if (((int32_T)tmp_x) > ((int32_T)0)) {
    rtb_pnn5 = rtb_m3dz;
  } else {
    rtb_pnn5 = DMC_Soc_Lat_B.DotProduct1;
  }

  /* End of Switch: '<S208>/Switch' */

  /* Sum: '<S210>/Add' incorporates:
   *  Constant: '<S202>/Lat_ay_control_kd_filter_coeff'
   *  Product: '<S210>/Product'
   *  Sum: '<S210>/Add1'
   *  UnitDelay: '<S210>/Unit Delay'
   */
  rtb_mkzu = ((rtb_m3dz - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_my50) * 0.1F) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_my50;

  /* Sum: '<S202>/Add3' incorporates:
   *  Gain: '<S202>/Lat_ay_control_kd'
   *  Gain: '<S202>/Lat_ay_control_kp'
   *  Gain: '<S202>/Lat_ay_control_pt1_kp'
   *  Gain: '<S210>/Sac_one_by_ts'
   *  Sum: '<S210>/Add2'
   *  UnitDelay: '<S210>/Unit Delay'
   */
  rtb_pnn5 = (((((real32_T)Lat_ay_control_pt1_kp) * 0.0009765625F) *
               DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bp0l) + ((((real32_T)
    Lat_ay_control_kp) * 0.0009765625F) * rtb_pnn5)) + ((((real32_T)
    Lat_ay_control_kd) * 0.0009765625F) * (((real32_T)Sac_one_by_ts) * (rtb_mkzu
    - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_my50)));

  /* Sum: '<S207>/Add3' incorporates:
   *  Abs: '<S207>/Abs'
   *  Abs: '<S207>/Abs1'
   *  Constant: '<S207>/Lat_ay_ctrl_i_part_margin'
   *  UnitDelay: '<S29>/Alg_Loop_Delay9'
   */
  tmp_3 = (((real32_T)fabs((real_T)rtb_pnn5)) + ((real32_T)fabs((real_T)
             DMC_Soc_Lat_DWork.Alg_Loop_Delay9_DSTATE))) + (((real32_T)
    Lat_ay_ctrl_i_part_margin) * 0.0009765625F);

  /* MinMax: '<S207>/MinMax3' incorporates:
   *  Switch: '<S207>/Switch5'
   */
  if ((((int32_T)tmp_w) != ((int32_T)0)) || (rtb_gmy5 <= tmp_3)) {
  } else {
    rtb_gmy5 = tmp_3;
  }

  /* End of MinMax: '<S207>/MinMax3' */

  /* RelationalOperator: '<S206>/Relational Operator1' incorporates:
   *  Constant: '<S206>/Constant3'
   */
  rtb_ohj2 = (boolean_T)((int32_T)(rtb_cy3g < -0.001F));

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Constant: '<S206>/Lat_ay_ctrl_min_jerk'
   */
  rtb_cy3g = ((real32_T)Lat_ay_ctrl_min_jerk) * 0.0009765625F;

  /* Signum: '<S203>/Sign' */
  if (rtb_m0pk < 0.0F) {
    rtb_m0pk = -1.0F;
  } else {
    if (rtb_m0pk > 0.0F) {
      rtb_m0pk = 1.0F;
    }
  }

  /* Logic: '<S206>/Logical Operator6' incorporates:
   *  Constant: '<S206>/Constant2'
   *  Product: '<S206>/Product'
   *  RelationalOperator: '<S206>/Relational Operator4'
   *  RelationalOperator: '<S206>/Relational Operator6'
   *  Signum: '<S203>/Sign'
   */
  rtb_fckq = (boolean_T)((int32_T)(((rtb_hwhx * rtb_m0pk) > 0.0F) ||
    (DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 < rtb_cy3g)));

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Abs: '<S206>/Abs3'
   */
  rtb_cy3g = (real32_T)fabs((real_T)(*rt_dmmuI));

  /* Outputs for Atomic SubSystem: '<S206>/S-R_Flip_Flop' */

  /* Logic: '<S206>/Logical Operator2' incorporates:
   *  Constant: '<S206>/Lat_ay_ctrl_torque_thrs'
   *  Logic: '<S206>/Logical Operator'
   *  RelationalOperator: '<S206>/Relational Operator3'
   */
  DMC_Soc_Lat_SR_Flip_Flop(rtb_ohj2 && rtb_fckq, (rtb_cy3g > (((real32_T)
    Lat_ay_ctrl_torque_thrs) * 0.0009765625F)) || rtb_ovjx, rtb_llzw,
    &DMC_Soc_Lat_DWork.SR_Flip_Flop);

  /* End of Outputs for SubSystem: '<S206>/S-R_Flip_Flop' */

  /* Logic: '<S207>/Logical Operator3' */
  rtb_hdiu = (boolean_T)((int32_T)(!rtb_llzw[(int8_T)1]));

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay8'
   */
  rtb_cy3g = DMC_Soc_Lat_DWork.Alg_Loop_Delay8_DSTATE;

  /* Switch: '<S207>/Switch2' */
  if ((int32_T)rtb_hdiu) {
    /* MinMax: '<S214>/MinMax1' incorporates:
     *  Constant: '<S207>/Constant1'
     */
    rtb_cy3g = 0.0F;
  } else {
    /* MinMax: '<S214>/MinMax1' incorporates:
     *  Gain: '<S207>/Lat_ay_control_ki'
     *  Gain: '<S36>/Lat_ay_arw_k'
     *  Sum: '<S207>/Add2'
     */
    rtb_cy3g = ((((real32_T)Lat_ay_control_ki) * 0.0009765625F) * rtb_m3dz) -
      ((((real32_T)Lat_ay_arw_k) * 0.0009765625F) * rtb_cy3g);
  }

  /* End of Switch: '<S207>/Switch2' */

  /* Gain: '<S207>/Sac_ts' */
  rtb_e1oo = (((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_cy3g;

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Abs: '<S204>/Abs2'
   *  UnitDelay: '<S29>/Alg_Loop_Delay6'
   */
  rtb_cy3g = DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE;
  rtb_cy3g = (real32_T)fabs((real_T)rtb_cy3g);

  /* Switch: '<S204>/Switch1' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  S-Function (sfix_bitop): '<S204>/Bitwise Operator2'
   */
  if ((((int32_T)Dmc_configuration_mode_2) & ((int32_T)8)) != ((int32_T)0)) {
    /* MinMax: '<S214>/MinMax1' incorporates:
     *  Sum: '<S204>/Add6'
     */
    rtb_cy3g -= rtb_pnn5;
  } else {
    /* MinMax: '<S214>/MinMax1' */
    rtb_cy3g = *rt_o3aadI;
  }

  /* End of Switch: '<S204>/Switch1' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Abs: '<S204>/Abs1'
   */
  rtb_cy3g = (real32_T)fabs((real_T)rtb_cy3g);

  /* UnitDelay: '<S207>/Unit Delay1' */
  rtb_ovjx = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mtzq;

  /* Switch: '<S207>/Switch4' incorporates:
   *  Logic: '<S207>/Logical Operator1'
   *  Logic: '<S207>/Logical Operator2'
   */
  if (((int32_T)rtb_llzw[(int8_T)1]) && (!rtb_ovjx)) {
  } else {
    /* MinMax: '<S214>/MinMax1' incorporates:
     *  Constant: '<S207>/Constant4'
     */
    rtb_cy3g = 0.0F;
  }

  /* End of Switch: '<S207>/Switch4' */

  /* UnitDelay: '<S207>/Unit Delay' */
  rtb_jwxe = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kxew;

  /* Switch: '<S207>/Switch1' incorporates:
   *  Constant: '<S207>/Constant3'
   */
  if ((int32_T)rtb_hdiu) {
    rtb_jwxe = 0.0F;
  }

  /* End of Switch: '<S207>/Switch1' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Sum: '<S207>/Add'
   *  Sum: '<S207>/Add1'
   */
  rtb_cy3g = rtb_e1oo + (rtb_cy3g + rtb_jwxe);

  /* MinMax: '<S207>/MinMax' */
  if (rtb_cy3g >= 0.0F) {
  } else {
    /* MinMax: '<S214>/MinMax1' */
    rtb_cy3g = 0.0F;
  }

  /* End of MinMax: '<S207>/MinMax' */

  /* MinMax: '<S207>/MinMax1' */
  if (rtb_gmy5 <= rtb_cy3g) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kxew = rtb_gmy5;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kxew = rtb_cy3g;
  }

  /* End of MinMax: '<S207>/MinMax1' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Constant: '<S205>/Sat_max_delta_f_cmd_phy'
   *  DataTypeConversion: '<S205>/Data Type Conversion2'
   */
  rtb_cy3g = ((real32_T)Sat_max_delta_f_cmd_phy) * 0.001953125F;

  /* Switch: '<S205>/Switch' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode_2'
   *  Logic: '<S205>/Logical Operator1'
   *  Logic: '<S205>/Logical Operator4'
   *  S-Function (sfix_bitop): '<S205>/Bitwise Operator1'
   */
  if (((int32_T)rtb_llzw[(int8_T)1]) && (!((((int32_T)Dmc_configuration_mode_2)
         & ((int32_T)4)) != ((int32_T)0)))) {
    /* MinMax: '<S214>/MinMax1' incorporates:
     *  Sum: '<S205>/Add1'
     */
    rtb_cy3g = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kxew + rtb_pnn5;
  }

  /* End of Switch: '<S205>/Switch' */

  /* MinMax: '<S205>/MinMax4' */
  if (rtb_cy3g >= 0.0F) {
  } else {
    /* MinMax: '<S214>/MinMax1' */
    rtb_cy3g = 0.0F;
  }

  /* End of MinMax: '<S205>/MinMax4' */

  /* ModelReference: '<S34>/SAT_Angle_Command_Saturation' */
  DMC_Lat_SAT_Angle_Command_Saturation(&rtb_hd5l, (&(VEH_Vehicle_Speed)),
    &rtb_hqad, rt_gyqsI, &rtb_cfdi, &rtb_jomt, rt_dptqI, &rtb_cy3g,
    &DMC_Soc_Lat_ConstP.pooled65, &rtb_mxz2, &rtb_jnhy, rt_ngfdoI, &rtb_kgdq,
    &rtb_na3o, &rtb_lmkf, &rtb_etec, &rtb_oclz, &rtb_bi2v);

  /* Gain: '<S83>/Gain3' */
  rtb_pnn5 = 3.6F * VEH_Vehicle_Speed;

  /* Lookup: '<S83>/PRF_T_Const_Scheduling' */
  rtb_ojsl = rt_Lookup32(DMC_Soc_Lat_ConstP.pooled31, 12, rtb_pnn5,
    DMC_Soc_Lat_ConstP.pooled32);

  /* Lookup: '<S83>/Prf_omega_Scheduling' */
  rtb_e1oo = rt_Lookup32(DMC_Soc_Lat_ConstP.pooled31, 12, rtb_pnn5,
    DMC_Soc_Lat_ConstP.pooled32);

  /* Sum: '<S83>/Add1' incorporates:
   *  UnitDelay: '<S86>/Unit Delay1'
   */
  rtb_jwxe = (*rt_ngfdoI) - DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_a5ig;

  /* Product: '<S83>/Product1' incorporates:
   *  Constant: '<S83>/Prf_omega'
   *  Product: '<S83>/Product5'
   */
  rtb_iwln = (((real32_T)Prf_omega) * 0.001953125F) * (rtb_e1oo * rtb_jwxe);

  /* Product: '<S84>/Product1' incorporates:
   *  Constant: '<S83>/Prf_t_nom'
   *  Constant: '<S84>/Prf_omega_2'
   *  Product: '<S83>/Product2'
   *  Product: '<S83>/Product4'
   *  Sum: '<S83>/Add'
   *  Sum: '<S84>/Add1'
   *  UnitDelay: '<S86>/Unit Delay1'
   *  UnitDelay: '<S87>/Unit Delay1'
   */
  rtb_m0pk = (((real32_T)Prf_omega_2) * 0.001953125F) * ((((((real32_T)Prf_t_nom)
    * 0.0009765625F) * (rtb_ojsl * rtb_iwln)) +
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_a5ig) -
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nsgx);

  /* Switch: '<S74>/Switch4' incorporates:
   *  Constant: '<S84>/Prf_t_nom_2'
   *  Product: '<S84>/Product2'
   *  S-Function (sfix_bitop): '<S74>/Bitwise Operator3'
   *  Sum: '<S84>/Add'
   *  UnitDelay: '<S87>/Unit Delay1'
   */
  if ((SAC_Controller_Mode_Sig & ((uint32_T)16U)) != ((uint32_T)0U)) {
    tmp_3 = *rt_ngfdoI;
  } else {
    tmp_3 = ((((real32_T)Prf_t_nom_2) * 0.0009765625F) * rtb_m0pk) +
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nsgx;
  }

  /* End of Switch: '<S74>/Switch4' */

  /* UnitDelay: '<S79>/Unit Delay' */
  rtb_cfdi = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ljte;

  /* Sum: '<S79>/Add1' */
  rtb_gmy5 = tmp_3 - rtb_cfdi;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Constant: '<S79>/Sac_backlash_filter_coeff'
   *  Product: '<S79>/Product'
   */
  rtb_l1ll = rtb_gmy5 * (((real32_T)Sac_backlash_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S79>/Add' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ljte = rtb_l1ll + rtb_cfdi;

  /* UnitDelay: '<S78>/Unit Delay' */
  rtb_cfdi = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_asff;

  /* Sum: '<S73>/Add1' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ljte - rtb_cfdi;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Constant: '<S73>/Sac_backlash_angle'
   *  DataTypeConversion: '<S73>/Data Type Conversion1'
   */
  rtb_l1ll = ((real32_T)Sac_backlash_angle) * 0.0009765625F;

  /* MinMax: '<S81>/MinMax1' */
  if (rtb_gmy5 <= rtb_l1ll) {
    rtb_hwhx = rtb_gmy5;
  } else {
    rtb_hwhx = rtb_l1ll;
  }

  /* End of MinMax: '<S81>/MinMax1' */

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Gain: '<S81>/Gain'
   */
  rtb_l1ll = -rtb_l1ll;
  if (rtb_hwhx >= rtb_l1ll) {
    rtb_l1ll = rtb_hwhx;
  }

  /* Sum: '<S78>/Add' incorporates:
   *  MinMax: '<S81>/MinMax2'
   *  Sum: '<S73>/Add'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_asff = (rtb_gmy5 - rtb_l1ll) + rtb_cfdi;

  /* UnitDelay: '<S82>/Unit Delay1' */
  rtb_cfdi = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_kxgv;

  /* Sum: '<S80>/Add1' incorporates:
   *  Sum: '<S73>/Add2'
   *  Sum: '<S73>/Add3'
   */
  rtb_gmy5 = ((tmp_3 - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ljte) +
              DMC_Soc_Lat_DWork.UnitDelay_DSTATE_asff) - rtb_cfdi;

  /* MinMax: '<S81>/MinMax2' incorporates:
   *  Constant: '<S80>/Sac_backlash_omega'
   *  Product: '<S80>/Product1'
   */
  rtb_l1ll = (((real32_T)Sac_backlash_omega) * 0.0009765625F) * rtb_gmy5;

  /* Product: '<S80>/Product2' incorporates:
   *  Constant: '<S80>/Sac_backlash_t_nom'
   */
  rtb_gmy5 = (((real32_T)Sac_backlash_t_nom) * 0.0009765625F) * rtb_l1ll;

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Sac_backlash_angle'
   *  Logic: '<S73>/Logical Operator'
   *  Logic: '<S73>/Logical Operator1'
   *  RelationalOperator: '<S77>/Compare'
   *  Sum: '<S80>/Add'
   */
  if ((Sac_backlash_angle > ((int16_T)0)) && (!SAC_Disable)) {
    tmp_3 = rtb_gmy5 + rtb_cfdi;
  }

  /* End of Switch: '<S73>/Switch' */

  /* DataTypeConversion: '<S68>/Data Type Conversion' incorporates:
   *  Constant: '<S68>/Sac_dynamic_corr_factor_aes'
   */
  rtb_gmy5 = ((real32_T)Sac_dynamic_corr_factor_aes) * 0.0009765625F;

  /* Switch: '<S68>/Switch1' incorporates:
   *  Constant: '<S68>/Constant1'
   *  Logic: '<S68>/Logical Operator'
   */
  if (((int32_T)(*rt_dptqI)) || ((int32_T)rtb_jomt)) {
  } else {
    rtb_gmy5 = 0.0F;
  }

  /* End of Switch: '<S68>/Switch1' */

  /* UnitDelay: '<S107>/Unit Delay1' */
  rtb_hwhx = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u;

  /* Sum: '<S107>/Add2' */
  rtb_gmy5 -= rtb_hwhx;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Constant: '<S107>/Sac_dyn_corr_factor_decrement'
   *  DataTypeConversion: '<S107>/Data Type Conversion2'
   */
  rtb_maat = ((real32_T)Sac_dyn_corr_factor_decrement) * 0.0009765625F;

  /* Switch: '<S107>/Switch2' incorporates:
   *  Constant: '<S107>/Constant5'
   *  Gain: '<S107>/Gain'
   *  RelationalOperator: '<S107>/Relational Operator'
   */
  if (rtb_gmy5 >= 0.0F) {
  } else {
    rtb_gmy5 = -rtb_maat;
  }

  /* End of Switch: '<S107>/Switch2' */

  /* Sum: '<S107>/Add3' */
  rtb_gmy5 += rtb_hwhx;

  /* MinMax: '<S107>/MinMax' */
  if (rtb_gmy5 >= 0.0F) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u = rtb_gmy5;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u = 0.0F;
  }

  /* End of MinMax: '<S107>/MinMax' */

  /* DataTypeConversion: '<S106>/Data Type Conversion2' incorporates:
   *  Constant: '<S106>/Sac_dyn_corr_factor_decrement'
   */
  rtb_gmy5 = ((real32_T)Sac_dyn_corr_factor_decrement) * 0.0009765625F;

  /* Gain: '<S68>/Gain3' */
  rtb_hwhx = 3.6F * VEH_Vehicle_Speed;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Lookup_n-D: '<S68>/SAC_Dynamic_Corr_Scheduling'
   */
  rtb_maat = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_hwhx,
    (&(Sac_dynamic_corr_min_x_schedul[0])), (&(Sac_dynamic_corr_min_y_schedul[0])),
    11U);

  /* Product: '<S68>/Product1' incorporates:
   *  Constant: '<S68>/Sac_dynamic_correction_factor'
   */
  tmp_1 = (((real32_T)Sac_dynamic_correction_factor) * 0.0009765625F) * rtb_maat;

  /* MinMax: '<S109>/MinMax1' */
  if ((*rt_pxsgI) <= 0.34F) {
    rtb_ojsl = *rt_pxsgI;
  } else {
    rtb_ojsl = 0.34F;
  }

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Gain: '<S109>/Gain'
   *  MinMax: '<S109>/MinMax1'
   */
  rtb_maat = 3.0F * rtb_ojsl;

  /* Switch: '<S109>/Switch2' incorporates:
   *  Constant: '<S17>/Dmc_configuration_mode_3'
   *  MinMax: '<S109>/MinMax2'
   *  S-Function (sfix_bitop): '<S109>/Bitwise Operator3'
   */
  if ((((int32_T)Dmc_configuration_mode_3) & ((int32_T)16)) != ((int32_T)0)) {
    /* MinMax: '<S477>/MinMax' incorporates:
     *  Constant: '<S109>/Constant3'
     */
    rtb_maat = 1.0F;
  } else {
    if (1.0F <= rtb_maat) {
      /* MinMax: '<S477>/MinMax' incorporates:
       *  MinMax: '<S109>/MinMax2'
       */
      rtb_maat = 1.0F;
    }
  }

  /* End of Switch: '<S109>/Switch2' */

  /* MinMax: '<S113>/MinMax' incorporates:
   *  Constant: '<S68>/Sac_dynamic_corr_factor_grdscal'
   */
  rtb_heqw = ((real32_T)Sac_dynamic_corr_factor_grdscal) * 0.0009765625F;
  if (tmp_1 <= rtb_heqw) {
    rtb_heqw = tmp_1;
  }

  /* Product: '<S113>/Product2' incorporates:
   *  Constant: '<S113>/Constant'
   *  Sum: '<S113>/Add1'
   */
  rtb_jwxe = rtb_heqw * (1.0F - rtb_maat);

  /* MinMax: '<S113>/MinMax' incorporates:
   *  UnitDelay: '<S106>/Unit Delay1'
   */
  rtb_heqw = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Product: '<S113>/Product1'
   *  Sum: '<S106>/Add2'
   *  Sum: '<S113>/Add'
   */
  rtb_maat = ((tmp_1 * rtb_maat) + rtb_jwxe) - rtb_heqw;

  /* MinMax: '<S106>/MinMax1' incorporates:
   *  Constant: '<S106>/Constant5'
   *  RelationalOperator: '<S106>/Relational Operator'
   *  Switch: '<S106>/Switch2'
   */
  if ((rtb_maat >= 0.0F) && (rtb_gmy5 <= rtb_maat)) {
    /* MinMax: '<S477>/MinMax' */
    rtb_maat = rtb_gmy5;
  }

  /* End of MinMax: '<S106>/MinMax1' */

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Sum: '<S106>/Add3'
   */
  rtb_maat += rtb_heqw;

  /* MinMax: '<S106>/MinMax' */
  if (rtb_maat >= 0.0F) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp = rtb_maat;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp = 0.0F;
  }

  /* End of MinMax: '<S106>/MinMax' */

  /* Lookup_n-D: '<S68>/SAC_Dynamic_Corr_Scheduling1' */
  rtb_hwhx = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_hwhx,
    (&(Sac_dynamic_corr_min_x_schedul[0])), (&(Sac_dynamic_corr_obf_y_schedul[0])),
    11U);

  /* MinMax: '<S113>/MinMax' incorporates:
   *  Constant: '<S68>/Sac_dynamic_corr_factor_obf'
   *  Product: '<S68>/Product2'
   */
  rtb_heqw = (((real32_T)Sac_dynamic_corr_factor_obf) * 0.0009765625F) *
    rtb_hwhx;

  /* MinMax: '<S68>/MinMax' */
  if (tmp_1 <= rtb_heqw) {
    rtb_jwxe = tmp_1;
  } else {
    rtb_jwxe = rtb_heqw;
  }

  /* End of MinMax: '<S68>/MinMax' */

  /* Switch: '<S108>/Switch3' incorporates:
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S63>/Compare'
   */
  if (((int32_T)(*rt_dzorI)) == ((int32_T)2)) {
    /* MinMax: '<S113>/MinMax' incorporates:
     *  Constant: '<S108>/Constant2'
     */
    rtb_heqw = 1.0F;
  } else {
    /* MinMax: '<S113>/MinMax' incorporates:
     *  Constant: '<S108>/Constant1'
     */
    rtb_heqw = 0.0F;
  }

  /* End of Switch: '<S108>/Switch3' */

  /* UnitDelay: '<S108>/Unit Delay' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1;

  /* MinMax: '<S113>/MinMax' incorporates:
   *  Sum: '<S108>/Sum'
   */
  rtb_heqw -= rtb_gmy5;

  /* Signum: '<S108>/Sign' */
  if (rtb_heqw < 0.0F) {
    /* MinMax: '<S113>/MinMax' */
    rtb_heqw = -1.0F;
  } else {
    if (rtb_heqw > 0.0F) {
      /* MinMax: '<S113>/MinMax' */
      rtb_heqw = 1.0F;
    }
  }

  /* Sum: '<S108>/IntegSum' incorporates:
   *  Constant: '<S108>/Sac_corr_factor_ramp_increment'
   *  Product: '<S108>/Product'
   *  Signum: '<S108>/Sign'
   */
  rtb_gmy5 += 0.02F * rtb_heqw;

  /* Saturate: '<S108>/Saturation2' */
  if (rtb_gmy5 > 1.0F) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1 = 1.0F;
  } else if (rtb_gmy5 < 0.0F) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1 = 0.0F;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1 = rtb_gmy5;
  }

  /* End of Saturate: '<S108>/Saturation2' */

  /* MinMax: '<S113>/MinMax' incorporates:
   *  UnitDelay: '<S29>/Alg_Loop_Delay21'
   */
  rtb_heqw = DMC_Soc_Lat_DWork.Alg_Loop_Delay21_DSTATE;

  /* ModelReference: '<S29>/SAC_Accuracy_Calculation' */
  DMC_Lat_SAC_Accuracy_Calculation(&rtb_kzgj, (&(VEH_Vehicle_Speed)), rt_popsI,
                                   (&(LDP_Active)), &rtb_euvg, &rtb_heqw,
    rt_bn5yI, (&(LKC_Kappa_Command_Arb)), &rtb_d2ky, &rtb_flnx, &rtb_n0ba,
    &rtb_j111, &rtb_iuh5);

  /* MinMax: '<S113>/MinMax' incorporates:
   *  Constant: '<S68>/Sac_dynamic_corr_min_factor'
   *  MinMax: '<S111>/MinMax'
   */
  rtb_heqw = ((real32_T)Sac_dynamic_corr_min_factor) * 0.0009765625F;

  /* MinMax: '<S111>/MinMax' */
  if (tmp_1 <= rtb_heqw) {
    /* MinMax: '<S113>/MinMax' */
    rtb_heqw = tmp_1;
  }

  /* MinMax: '<S113>/MinMax' incorporates:
   *  Constant: '<S111>/Constant'
   *  Constant: '<S112>/Constant'
   *  Product: '<S111>/Product1'
   *  Product: '<S111>/Product2'
   *  Product: '<S112>/Product1'
   *  Product: '<S112>/Product2'
   *  Sum: '<S111>/Add'
   *  Sum: '<S111>/Add1'
   *  Sum: '<S112>/Add'
   *  Sum: '<S112>/Add1'
   */
  rtb_heqw = (rtb_jwxe * DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1) + (((tmp_1 *
    rtb_n0ba) + (rtb_heqw * (1.0F - rtb_n0ba))) * (1.0F -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1));

  /* MinMax: '<S68>/MinMax2' */
  if (DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp <= rtb_heqw) {
    /* MinMax: '<S113>/MinMax' */
    rtb_heqw = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp;
  }

  /* End of MinMax: '<S68>/MinMax2' */

  /* MinMax: '<S68>/MinMax1' */
  if (DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u >= rtb_heqw) {
    /* MinMax: '<S113>/MinMax' */
    rtb_heqw = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u;
  }

  /* End of MinMax: '<S68>/MinMax1' */

  /* Product: '<S68>/Product5' incorporates:
   *  Constant: '<S68>/Constant5'
   *  Sum: '<S68>/Add2'
   */
  rtb_e1oo = (1.0F - rtb_heqw) * (*rt_o3aadI);

  /* Sum: '<S68>/Add1' incorporates:
   *  Product: '<S68>/Product4'
   */
  tmp_1 = (tmp_3 * rtb_heqw) + rtb_e1oo;

  /* UnitDelay: '<S120>/Unit Delay' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j5v2;

  /* Constant: '<S117>/Lat_ref_ctrl_parity_coeff' */
  rtb_hwhx = ((real32_T)Lat_ref_ctrl_parity_coeff) * 3.05175781E-5F;

  /* Switch: '<S117>/Switch' incorporates:
   *  Constant: '<S117>/Constant'
   */
  if ((int32_T)SAC_Disable) {
    rtb_hwhx = 1.0F;
  }

  /* End of Switch: '<S117>/Switch' */

  /* Sum: '<S120>/Add' incorporates:
   *  Product: '<S120>/Product'
   *  Sum: '<S120>/Add1'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j5v2 = ((tmp_1 - rtb_gmy5) * rtb_hwhx) +
    rtb_gmy5;

  /* UnitDelay: '<S121>/Unit Delay' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ko35;

  /* Sum: '<S121>/Add' incorporates:
   *  Product: '<S121>/Product'
   *  Sum: '<S121>/Add1'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ko35 =
    ((DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j5v2 - rtb_gmy5) * rtb_hwhx) + rtb_gmy5;

  /* Logic: '<S5>/Logical Operator4' */
  rtb_hdiu = (boolean_T)((int32_T)(!rtb_ef4d));

  /* UnitDelay: '<S497>/Unit Delay3' */
  rtb_hwhx = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE;

  /* Switch: '<S497>/Switch' */
  if ((int32_T)rtb_hdiu) {
    rtb_hwhx = *rt_o3aadI;
  }

  /* End of Switch: '<S497>/Switch' */

  /* Switch: '<S116>/Switch1' incorporates:
   *  Constant: '<S17>/Dmc_configuration_mode_3'
   *  S-Function (sfix_bitop): '<S116>/Bitwise Operator1'
   */
  if ((((int32_T)Dmc_configuration_mode_3) & ((int32_T)2048)) != ((int32_T)0)) {
    /* MinMax: '<S477>/MinMax' */
    rtb_maat = rtb_hwhx;
  } else {
    /* MinMax: '<S477>/MinMax' */
    rtb_maat = *rt_o3aadI;
  }

  /* End of Switch: '<S116>/Switch1' */

  /* Sum: '<S116>/Add1' */
  rtb_jwxe = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ko35 - rtb_maat;

  /* MinMax: '<S477>/MinMax' incorporates:
   *  UnitDelay: '<S119>/Unit Delay'
   */
  rtb_maat = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_mdsl;

  /* Sum: '<S119>/Add' incorporates:
   *  Constant: '<S119>/Lat_ref_pt1_control_coeff'
   *  Gain: '<S116>/Lat_ref_control_k_pt1'
   *  Product: '<S119>/Product'
   *  Sum: '<S119>/Add1'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_mdsl = ((((((real32_T)Lat_ref_control_k_pt1)
    * 0.0009765625F) * rtb_jwxe) - rtb_maat) * (((real32_T)
    Lat_ref_pt1_control_coeff) * 3.05175781E-5F)) + rtb_maat;

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/Constant1'
   *  Gain: '<S121>/Sac_one_by_ts'
   *  Sum: '<S121>/Add2'
   */
  if ((int32_T)SAC_Disable) {
    tmp_f = 0.0F;
  } else {
    tmp_f = ((real32_T)Sac_one_by_ts) * (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ko35
      - rtb_gmy5);
  }

  /* End of Switch: '<S117>/Switch1' */

  /* DataTypeConversion: '<S22>/Data Type Conversion1' incorporates:
   *  Constant: '<S22>/Sac_notch_l2'
   */
  rtb_gmy5 = ((real32_T)Sac_notch_l2) * 0.0009765625F;

  /* UnitDelay: '<S498>/Unit Delay' */
  tmp_i = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3;

  /* UnitDelay: '<S498>/Unit Delay1' */
  tmp_j = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_i13z;

  /* UnitDelay: '<S498>/Unit Delay2' */
  tmp_k = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ckqg;

  /* UnitDelay: '<S498>/Unit Delay3' */
  tmp_l = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_jaq2;

  /* UnitDelay: '<S498>/Unit Delay4' */
  tmp_m = DMC_Soc_Lat_DWork.UnitDelay4_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay5' */
  tmp_n = DMC_Soc_Lat_DWork.UnitDelay5_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay6' */
  tmp_o = DMC_Soc_Lat_DWork.UnitDelay6_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay7' */
  tmp_p = DMC_Soc_Lat_DWork.UnitDelay7_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay8' */
  tmp_q = DMC_Soc_Lat_DWork.UnitDelay8_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay9' */
  tmp_r = DMC_Soc_Lat_DWork.UnitDelay9_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay10' */
  tmp_s = DMC_Soc_Lat_DWork.UnitDelay10_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay11' */
  tmp_t = DMC_Soc_Lat_DWork.UnitDelay11_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay12' */
  tmp_u = DMC_Soc_Lat_DWork.UnitDelay12_DSTATE;

  /* UnitDelay: '<S498>/Unit Delay13' */
  tmp_v = DMC_Soc_Lat_DWork.UnitDelay13_DSTATE;

  /* MultiPortSwitch: '<S498>/Multiport Switch' incorporates:
   *  Constant: '<S17>/Dmc_configuration_mode_3'
   *  Constant: '<S498>/Constant'
   *  S-Function (sfix_bitop): '<S22>/Bitwise Operator3'
   *  Sum: '<S498>/Add'
   */
  switch (((int32_T)1) + (((int32_T)Dmc_configuration_mode_3) & ((int32_T)15)))
  {
   case 1:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3;
    break;

   case 2:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3;
    break;

   case 3:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay1'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_i13z;
    break;

   case 4:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay2'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ckqg;
    break;

   case 5:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay3'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_jaq2;
    break;

   case 6:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay4'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay4_DSTATE;
    break;

   case 7:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay5'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay5_DSTATE;
    break;

   case 8:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay6'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay6_DSTATE;
    break;

   case 9:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay7'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay7_DSTATE;
    break;

   case 10:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay8'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay8_DSTATE;
    break;

   case 11:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay9'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay9_DSTATE;
    break;

   case 12:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay10'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay10_DSTATE;
    break;

   case 13:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay11'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay11_DSTATE;
    break;

   case 14:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay12'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay12_DSTATE;
    break;

   case 15:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay13'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay13_DSTATE;
    break;

   default:
    /* MinMax: '<S477>/MinMax' incorporates:
     *  UnitDelay: '<S498>/Unit Delay14'
     */
    rtb_maat = DMC_Soc_Lat_DWork.UnitDelay14_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S498>/Multiport Switch' */

  /* MinMax: '<S477>/MinMax' incorporates:
   *  Sum: '<S22>/Add8'
   *
   * Block requirements for '<S22>/Add8':
   *  1. The Eps Model Error
   */
  rtb_maat = (*rt_o3aadI) - rtb_maat;

  /* Product: '<S22>/Product1' */
  rtb_jwxe = rtb_gmy5 * rtb_maat;

  /* UnitDelay: '<S496>/Unit Delay3' */
  rtb_gmy5 = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_b55e;

  /* Switch: '<S496>/Switch' incorporates:
   *  Constant: '<S496>/Constant'
   */
  if ((int32_T)rtb_hdiu) {
    rtb_gmy5 = 0.0F;
  }

  /* End of Switch: '<S496>/Switch' */

  /* Sum: '<S22>/Add10' */
  tmp_4 = rtb_jwxe + rtb_gmy5;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S17>/Dmc_configuration_mode_3'
   *  S-Function (sfix_bitop): '<S22>/Bitwise Operator1'
   */
  if ((((int32_T)Dmc_configuration_mode_3) & ((int32_T)512)) != ((int32_T)0)) {
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = tmp_4;
  } else {
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = rtb_gmy5;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Sum: '<S118>/Add1' incorporates:
   *  UnitDelay: '<S118>/Unit Delay'
   */
  rtb_e3dd = (*rt_o3aadI) - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d45l;

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Constant: '<S118>/Lat_ref_ctrl_delt_dot_flt_coeff'
   *  Product: '<S118>/Product'
   */
  rtb_gnup = rtb_e3dd * (((real32_T)Lat_ref_ctrl_delt_dot_flt_coeff) *
    3.05175781E-5F);

  /* Sum: '<S118>/Add' incorporates:
   *  UnitDelay: '<S118>/Unit Delay'
   */
  tmp_h = rtb_gnup + DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d45l;

  /* Switch: '<S116>/Switch' incorporates:
   *  Constant: '<S17>/Dmc_configuration_mode_3'
   *  S-Function (sfix_bitop): '<S116>/Bitwise Operator'
   */
  if ((((int32_T)Dmc_configuration_mode_3) & ((int32_T)1024)) != ((int32_T)0)) {
    /* MinMax: '<S282>/MinMax2' */
    rtb_gnup = rtb_mw4r;
  } else {
    /* MinMax: '<S282>/MinMax2' incorporates:
     *  Gain: '<S118>/Sac_one_by_ts'
     *  Sum: '<S118>/Add2'
     *  UnitDelay: '<S118>/Unit Delay'
     */
    rtb_gnup = ((real32_T)Sac_one_by_ts) * (tmp_h -
      DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d45l);
  }

  /* End of Switch: '<S116>/Switch' */

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Gain: '<S116>/Lat_ref_control_kd'
   *  Sum: '<S116>/Add2'
   *  Sum: '<S116>/Add3'
   *  Sum: '<S116>/Add4'
   */
  rtb_gnup = tmp_1 + (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_mdsl + ((((real32_T)
    Lat_ref_control_kd) * 0.0009765625F) * (tmp_f - rtb_gnup)));

  /* Gain: '<S260>/Gain8' */
  rtb_e3dd = 3.6F * VEH_Vehicle_Speed;

  /* Lookup_n-D: '<S260>/SAC_Trq_Angle_Factor_Scheduling' */
  rtb_e3dd = look1_iflf_binlc(rtb_e3dd,
    DMC_Soc_Lat_ConstP.SAC_Trq_Angle_Factor_Scheduling_bp01Data,
    DMC_Soc_Lat_ConstP.SAC_Trq_Angle_Factor_Scheduling_tableData, 10U);

  /* ModelReference: '<S43>/MOT_Modulation_Torque' */
  DMC_Soc_Lat_MOT_Modulation_Torque((&(SAC_Disable)), &DMC_Soc_Lat_B.Switch5,
    &rtb_nhlb);

  /* Constant: '<S264>/Sac_ffwd_scale_pos_angle_cmd' */
  rtb_e1oo = ((real32_T)Sac_ffwd_scale_pos_angle_cmd) * 0.0009765625F;

  /* RelationalOperator: '<S266>/Compare' incorporates:
   *  Constant: '<S266>/Constant'
   */
  rtb_ohj2 = (boolean_T)((int32_T)((*rt_ngfdoI) > 0.0F));

  /* Switch: '<S264>/Switch7' incorporates:
   *  Constant: '<S264>/Constant2'
   */
  if ((int32_T)rtb_ohj2) {
  } else {
    rtb_e1oo = 1.0F;
  }

  /* End of Switch: '<S264>/Switch7' */

  /* Lookup_n-D: '<S264>/SAC_Feedfwd_Factor_Scheduling' incorporates:
   *  Gain: '<S264>/Gain2'
   */
  tmp_f = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * VEH_Vehicle_Speed,
    (&(Sac_feedfwd_factor_x_scheduling[0])), (&(Sac_feedfwd_factor_y_scheduling
    [0])), 12U);

  /* Product: '<S264>/Product4' */
  rtb_e1oo *= tmp_f;

  /* Product: '<S264>/Product' incorporates:
   *  Constant: '<S264>/Constant'
   *  Product: '<S264>/Product1'
   */
  tmp_f = (*rt_ngfdoI) * (rtb_e1oo * (((real32_T)Sac_cmd_feedforward_gain) *
    0.0009765625F));

  /* Sum: '<S269>/Add2' incorporates:
   *  UnitDelay: '<S270>/Unit Delay1'
   */
  tmp_g = tmp_f - DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jjfr;

  /* Sum: '<S269>/Add1' incorporates:
   *  UnitDelay: '<S269>/Unit Delay'
   */
  tmp_f -= DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dngv;

  /* Sum: '<S269>/Add' incorporates:
   *  Constant: '<S269>/Sac_feedforward_filter_coeff'
   *  Product: '<S269>/Product'
   *  UnitDelay: '<S269>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dngv += tmp_f * (((real32_T)
    Sac_feedforward_filter_coeff) * 3.05175781E-5F);

  /* Switch: '<S269>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S269>/Bitwise Operator5'
   */
  if ((SAC_Controller_Mode_Sig & 33554432U) != ((uint32_T)0U)) {
    tmp_ = tmp_g;
  } else {
    tmp_ = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dngv;
  }

  /* End of Switch: '<S269>/Switch4' */

  /* Switch: '<S268>/Switch3' incorporates:
   *  Constant: '<S253>/Lka_max_align_torque'
   *  Constant: '<S268>/Constant1'
   */
  if ((int32_T)rtb_jomt) {
    rtb_dpeo = 0.0F;
  } else {
    rtb_dpeo = ((real32_T)Lka_max_align_torque) * 0.0009765625F;
  }

  /* End of Switch: '<S268>/Switch3' */

  /* DataTypeConversion: '<S253>/Data Type Conversion14' incorporates:
   *  Constant: '<S253>/Lat_max_output_torque'
   */
  tmp_f = ((real32_T)Lat_max_output_torque) * 0.0009765625F;

  /* Switch: '<S268>/Switch1' incorporates:
   *  Gain: '<S268>/Gain2'
   *  Gain: '<S268>/Gain6'
   */
  if ((int32_T)rtb_pkm5) {
    rtb_e1oo = rtb_dpeo;
  } else {
    rtb_e1oo = tmp_f;
  }

  if ((int32_T)rtb_pkm5) {
    rtb_ojsl = -tmp_f;
  } else {
    rtb_ojsl = -rtb_dpeo;
  }

  /* End of Switch: '<S268>/Switch1' */

  /* Switch: '<S268>/Switch2' incorporates:
   *  Gain: '<S268>/Gain1'
   */
  rtb_jwxe = rtb_e1oo;
  if ((int32_T)LDP_Active) {
  } else {
    rtb_jwxe = tmp_f;
  }

  rtb_e1oo = rtb_jwxe;
  rtb_jwxe = rtb_ojsl;
  if ((int32_T)LDP_Active) {
  } else {
    rtb_jwxe = -tmp_f;
  }

  /* End of Switch: '<S268>/Switch2' */

  /* MinMax: '<S267>/MinMax1' */
  if (tmp_ <= rtb_e1oo) {
  } else {
    tmp_ = rtb_e1oo;
  }

  /* End of MinMax: '<S267>/MinMax1' */

  /* Switch: '<S264>/Switch1' incorporates:
   *  Constant: '<S264>/Constant1'
   *  Constant: '<S265>/Constant'
   *  MinMax: '<S267>/MinMax3'
   *  RelationalOperator: '<S265>/Compare'
   *  S-Function (sfix_bitop): '<S264>/Bitwise Operator1'
   */
  if ((SAC_Controller_Mode_Sig & ((uint32_T)7U)) == ((uint32_T)0U)) {
    rtb_jwxe = 0.0F;
  } else {
    if (tmp_ >= rtb_jwxe) {
      /* MinMax: '<S267>/MinMax3' */
      rtb_jwxe = tmp_;
    }
  }

  /* End of Switch: '<S264>/Switch1' */

  /* Sum: '<S263>/Add1' incorporates:
   *  UnitDelay: '<S263>/Unit Delay'
   */
  rtb_jwxe -= DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pmt4;

  /* Abs: '<S263>/Abs2' */
  tmp_ = (real32_T)fabs((real_T)rtb_jwxe);

  /* Gain: '<S263>/Sac_ts' incorporates:
   *  Constant: '<S253>/Lat_torque_gradient'
   */
  if (((int32_T)Sac_ts) > ((int32_T)511)) {
    tmp_w = MAX_uint16_T;
  } else {
    tmp_w = (uint16_T)(Sac_ts << ((int8_T)7));
  }

  rtb_jyuz = ((uint32_T)tmp_w) * ((uint32_T)Lat_torque_gradient);

  /* End of Gain: '<S263>/Sac_ts' */

  /* Sum: '<S263>/Add4' */
  rtb_dpeo = tmp_ - (((real32_T)rtb_jyuz) * 7.4505806E-9F);

  /* MinMax: '<S263>/MinMax4' */
  if (0.0F >= rtb_dpeo) {
    rtb_dpeo = 0.0F;
  }

  /* End of MinMax: '<S263>/MinMax4' */

  /* MinMax: '<S263>/MinMax3' */
  if (0.0F <= rtb_dpeo) {
    rtb_e1oo = 0.0F;
  } else {
    rtb_e1oo = rtb_dpeo;
  }

  /* End of MinMax: '<S263>/MinMax3' */

  /* Signum: '<S263>/Sign1' */
  if (rtb_jwxe < 0.0F) {
    rtb_jwxe = -1.0F;
  } else {
    if (rtb_jwxe > 0.0F) {
      rtb_jwxe = 1.0F;
    }
  }

  /* End of Signum: '<S263>/Sign1' */

  /* Abs: '<S263>/Abs1' incorporates:
   *  Product: '<S263>/Product'
   */
  rtb_dpeo = (real32_T)fabs((real_T)((real32_T)((((real32_T)rtb_jyuz) *
    7.4505806E-9F) * rtb_jwxe)));

  /* MinMax: '<S263>/MinMax1' */
  if (rtb_dpeo <= tmp_) {
    tmp_ = rtb_dpeo;
  }

  /* Sum: '<S263>/Add' incorporates:
   *  MinMax: '<S263>/MinMax1'
   *  Product: '<S263>/Product1'
   *  UnitDelay: '<S263>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pmt4 += rtb_jwxe * tmp_;

  /* Sum: '<S263>/Add2' incorporates:
   *  Product: '<S263>/Product2'
   */
  SAC_Rate_Lim_Feed_Fwd_Torque = (rtb_e1oo * rtb_jwxe) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pmt4;

  /* RelationalOperator: '<S256>/Relational Operator2' incorporates:
   *  Constant: '<S256>/Constant5'
   *  Constant: '<S256>/Dit_dirac_loop_count'
   *  Sum: '<S256>/Add1'
   *  UnitDelay: '<S256>/Unit Delay1'
   */
  rtb_ovjx = (boolean_T)((int32_T)((1.0 + DMC_Soc_Lat_DWork.UnitDelay1_DSTATE) <=
                          (((real_T)Dit_dirac_loop_count) * 0.0009765625)));

  /* Switch: '<S257>/Switch1' incorporates:
   *  Constant: '<S257>/Constant1'
   *  Constant: '<S257>/Constant2'
   *  Constant: '<S257>/Constant3'
   *  RelationalOperator: '<S257>/Relational Operator'
   *  UnitDelay: '<S257>/Unit Delay1'
   */
  if (DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_hzxr < 0.4F) {
    rtb_itp5 = (int32_T)1;
  } else {
    rtb_itp5 = (int32_T)-1;
  }

  /* End of Switch: '<S257>/Switch1' */

  /* Signum: '<S255>/Sign' */
  if (((real32_T)rtb_itp5) < 0.0F) {
    rtb_ojsl = -1.0F;
  } else if (((real32_T)rtb_itp5) > 0.0F) {
    rtb_ojsl = 1.0F;
  } else {
    rtb_ojsl = 0.0F;
  }

  /* UnitDelay: '<S29>/Alg_Loop_Delay20' */
  rtb_n3ry = DMC_Soc_Lat_DWork.Alg_Loop_Delay20_DSTATE;

  /* ModelReference: '<S43>/SAC_Friction_Compensation' */
  DMC_Lat_SAC_Friction_Compensation(rt_ngfdoI, (&(SAC_Controller_Mode_Sig)),
    (&(VEH_Vehicle_Speed)), rt_o3aadI, (&(SAC_Disable)), &rtb_n3ry, &rtb_kggy);

  /* DataTypeConversion: '<S261>/Data Type Conversion' incorporates:
   *  Constant: '<S252>/Sac_friction_comp_scaling_end'
   *  Constant: '<S252>/Sac_friction_comp_scaling_start'
   *  Sum: '<S261>/Subtract1'
   */
  rtb_m3dz = ((real32_T)((uint16_T)(Sac_friction_comp_scaling_end -
    Sac_friction_comp_scaling_start))) * 0.0009765625F;

  /* MinMax: '<S261>/MinMax2' */
  if (rtb_m3dz >= 0.1F) {
  } else {
    rtb_m3dz = 0.1F;
  }

  /* Sum: '<S261>/Subtract' incorporates:
   *  Constant: '<S252>/Sac_friction_comp_scaling_start'
   */
  rtb_e1oo = rtb_c4yx - (((real32_T)Sac_friction_comp_scaling_start) *
    0.0009765625F);

  /* MinMax: '<S261>/MinMax4' */
  if (rtb_e1oo >= 0.0F) {
  } else {
    rtb_e1oo = 0.0F;
  }

  /* Product: '<S261>/Product' incorporates:
   *  Constant: '<S261>/Constant2'
   *  MinMax: '<S261>/MinMax2'
   *  MinMax: '<S261>/MinMax4'
   *  Product: '<S261>/Divide'
   */
  rtb_m3dz = rtb_e1oo * (1.0F / rtb_m3dz);

  /* MinMax: '<S261>/MinMax1' */
  if (rtb_m3dz <= 1.0F) {
  } else {
    rtb_m3dz = 1.0F;
  }

  /* Sum: '<S252>/Add1' incorporates:
   *  Constant: '<S252>/Constant1'
   *  Constant: '<S258>/Dit_torque_pulse_amplitude'
   *  MinMax: '<S261>/MinMax1'
   *  Product: '<S252>/Product'
   *  Product: '<S252>/Product1'
   *  Product: '<S258>/Product'
   *  Product: '<S258>/Product1'
   *  Signum: '<S255>/Sign'
   *  Sum: '<S252>/Add'
   *  Sum: '<S252>/Add2'
   */
  rtb_n4jt = rtb_nhlb + ((((SAC_Rate_Lim_Feed_Fwd_Torque + ((((real32_T)
    Dit_torque_pulse_amplitude) * 0.0009765625F) * (rtb_ovjx ? rtb_ojsl : 0.0F)))
    + rtb_kggy) * rtb_m3dz) * (1.0F - rtb_pqrc));

  /* S-Function (sfix_bitop): '<S252>/Bitwise Operator2' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   */
  tmp_x = (uint16_T)((int32_T)(((int32_T)Dmc_configuration_mode) & ((int32_T)512)));

  /* Switch: '<S252>/Switch2' incorporates:
   *  Constant: '<S252>/Constant5'
   */
  if (((int32_T)tmp_x) != ((int32_T)0)) {
    tmp_ = rtb_n4jt;
  } else {
    tmp_ = 0.0F;
  }

  /* End of Switch: '<S252>/Switch2' */

  /* Product: '<S260>/Product' */
  rtb_e3dd *= tmp_;

  /* ModelReference: '<S29>/SAC_Steer_Angle_Cmd_Controller' */
  DMC_Soc_Lat_SAC_Steer_Angle_Cmd_Controller(&rtb_gnup, &rtb_kgdq,
    (&(VEH_Vehicle_Speed)), rt_o3aadI, &rtb_n0ba, (&(SAC_Controller_Mode_Sig)),
    &rtb_e3dd, &rtb_jhzt, &rtb_jomt, &rtb_mw4r, &rtb_lyau, &rtb_icrr, &rtb_gemg);

  /* Gain: '<S46>/Gain' */
  tmp_ = 0.01F * (*rt_enkbI);

  /* Switch: '<S250>/Switch1' incorporates:
   *  Constant: '<S250>/Constant3'
   *  Logic: '<S250>/Logical Operator'
   *  Logic: '<S250>/Logical Operator1'
   *  RelationalOperator: '<S250>/Relational Operator'
   *  UnitDelay: '<S250>/Unit Delay1'
   */
  if ((rtb_c4yx > DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ddx5) && (!SAC_Disable)) {
    rtb_dpeo = rtb_c4yx;
  } else {
    rtb_dpeo = 0.0F;
  }

  /* End of Switch: '<S250>/Switch1' */

  /* Switch: '<S250>/Switch3' */
  if ((int32_T)SAC_Disable) {
    /* MinMax: '<S282>/MinMax2' incorporates:
     *  Constant: '<S250>/Constant2'
     */
    rtb_gnup = 0.0F;
  } else {
    /* MinMax: '<S282>/MinMax2' incorporates:
     *  Constant: '<S250>/Constant1'
     */
    rtb_gnup = 1.0F;
  }

  /* End of Switch: '<S250>/Switch3' */

  /* UnitDelay: '<S250>/Unit Delay' */
  rtb_e3dd = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei;

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Sum: '<S250>/Sum'
   */
  rtb_gnup -= rtb_e3dd;

  /* Signum: '<S250>/Sign' */
  if (rtb_gnup < 0.0F) {
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = -1.0F;
  } else if (rtb_gnup > 0.0F) {
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = 1.0F;
  } else {
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = rtb_gnup;
  }

  /* End of Signum: '<S250>/Sign' */

  /* Switch: '<S250>/Switch2' */
  if (rtb_gnup >= 0.0F) {
    /* MinMax: '<S282>/MinMax2' incorporates:
     *  Gain: '<S250>/Lat_switch_rising_rate_2'
     */
    rtb_gnup = (((real32_T)Lat_switch_rising_rate_2) * 0.00390625F) * rtb_mw4r;
  } else {
    /* MinMax: '<S282>/MinMax2' incorporates:
     *  Gain: '<S250>/Lat_switch_falling_rate_2'
     */
    rtb_gnup = (((real32_T)Lat_switch_falling_rate_2) * 0.00390625F) * rtb_mw4r;
  }

  /* End of Switch: '<S250>/Switch2' */

  /* Sum: '<S250>/IntegSum' incorporates:
   *  Gain: '<S250>/IntegGain2'
   */
  rtb_e3dd += (((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_gnup;

  /* MinMax: '<S250>/MinMax' */
  if (rtb_dpeo >= rtb_e3dd) {
  } else {
    rtb_dpeo = rtb_e3dd;
  }

  /* End of MinMax: '<S250>/MinMax' */

  /* Saturate: '<S250>/Saturation2' */
  if (rtb_dpeo > 1.0F) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei = 1.0F;
  } else if (rtb_dpeo < 0.0F) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei = 0.0F;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei = rtb_dpeo;
  }

  /* End of Saturate: '<S250>/Saturation2' */

  /* MinMax: '<S250>/MinMax1' */
  if (rtb_c4yx <= DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei) {
    rtb_jeca = rtb_c4yx;
  } else {
    rtb_jeca = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei;
  }

  /* End of MinMax: '<S250>/MinMax1' */

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S46>/Constant1'
   *  S-Function (sfix_bitop): '<S46>/Bitwise Operator2'
   */
  if ((((int32_T)Dmc_configuration_mode) & ((int32_T)1024)) != ((int32_T)0)) {
    rtb_dpeo = rtb_n1zt;
  } else {
    rtb_dpeo = 1.0F;
  }

  /* End of Switch: '<S46>/Switch2' */

  /* MinMax: '<S46>/MinMax' */
  if (rtb_jeca <= rtb_dpeo) {
    rtb_dpeo = rtb_jeca;
  }

  /* End of MinMax: '<S46>/MinMax' */

  /* MinMax: '<S46>/MinMax2' */
  if (tmp_ <= rtb_dpeo) {
  } else {
    tmp_ = rtb_dpeo;
  }

  /* End of MinMax: '<S46>/MinMax2' */

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Sum: '<S284>/Add1'
   *  UnitDelay: '<S284>/Unit Delay'
   */
  rtb_gnup = (*rt_o3aadI) - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pfgp;

  /* Product: '<S284>/Product' incorporates:
   *  Constant: '<S281>/Tdf_delta_f_latency_comp_coeff'
   */
  rtb_e3dd = rtb_gnup * (((real32_T)Tdf_delta_f_latency_comp_coeff) *
    3.05175781E-5F);

  /* Sum: '<S284>/Add' incorporates:
   *  UnitDelay: '<S284>/Unit Delay'
   */
  tmp_e = rtb_e3dd + DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pfgp;

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Constant: '<S281>/Tdf_delta_f_latency'
   *  Gain: '<S284>/Sac_one_by_ts'
   *  Product: '<S281>/Product'
   *  Sum: '<S284>/Add2'
   *  UnitDelay: '<S284>/Unit Delay'
   */
  rtb_gnup = (((real32_T)Sac_one_by_ts) * (tmp_e -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pfgp)) * (((real32_T)Tdf_delta_f_latency)
    * 0.0009765625F);

  /* Sum: '<S281>/Add4' */
  rtb_e1oo = rtb_gnup + (*rt_o3aadI);

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Constant: '<S282>/Constant6'
   *  Sum: '<S282>/Add1'
   */
  rtb_gnup = 1.0F - rtb_kzgj;
  if (rtb_gfou >= rtb_gnup) {
    rtb_gnup = rtb_gfou;
  }

  /* Product: '<S282>/Product4' incorporates:
   *  Constant: '<S282>/Tdf_activation_gain'
   *  MinMax: '<S282>/MinMax2'
   */
  rtb_dpeo = (((real32_T)Tdf_activation_gain) * 0.0009765625F) * rtb_gnup;

  /* MinMax: '<S282>/MinMax4' */
  if (rtb_dpeo <= 1.0F) {
  } else {
    rtb_dpeo = 1.0F;
  }

  /* End of MinMax: '<S282>/MinMax4' */

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Gain: '<S282>/Gain4'
   */
  rtb_gnup = 3.6F * rtb_dmt0;

  /* Lookup_n-D: '<S282>/TDF_Reduction_Gain_Schedul' */
  rtb_e3dd = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_gnup,
    (&(Tdf_trq_derating_thrs_x_schedul[0])), (&(Tdf_torque_reduc_gain_y_schedul
    [0])), 10U);

  /* MultiPortSwitch: '<S283>/Multiport Switch' incorporates:
   *  ArithShift: '<S283>/Shift Arithmetic'
   *  Constant: '<S283>/Constant1'
   *  Constant: '<S29>/Tdf_derating_mode'
   *  S-Function (sfix_bitop): '<S283>/Bitwise Operator2'
   *  Sum: '<S283>/Add'
   */
  switch ((int32_T)((uint32_T)(((uint32_T)1U) + (((uint32_T)((int32_T)(((int32_T)
    Tdf_derating_mode) & ((int32_T)384)))) >> ((int8_T)7))))) {
   case 1:
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = *rt_dfm1I;
    break;

   case 2:
    /* MinMax: '<S282>/MinMax' incorporates:
     *  Gain: '<S283>/Gain'
     */
    rtb_mw4r = -(*rt_dmmuI);
    break;

   case 3:
    /* MinMax: '<S282>/MinMax' */
    rtb_mw4r = *rt_c4rhI;
    break;

   default:
    /* MinMax: '<S282>/MinMax' incorporates:
     *  Constant: '<S283>/Constant3'
     */
    rtb_mw4r = 0.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S283>/Multiport Switch' */

  /* Sum: '<S290>/Add1' incorporates:
   *  UnitDelay: '<S290>/Unit Delay'
   */
  rtb_ojsl = rtb_mw4r - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws;

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Constant: '<S290>/Tdf_steer_trq_ctrl_filter_coeff'
   *  DataTypeConversion: '<S290>/Data Type Conversion2'
   */
  rtb_mw4r = ((real32_T)Tdf_steer_trq_ctrl_filter_coeff) * 3.05175781E-5F;

  /* Sum: '<S290>/Add' incorporates:
   *  Product: '<S290>/Product'
   *  UnitDelay: '<S290>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws += rtb_ojsl * rtb_mw4r;

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Abs: '<S282>/Abs1'
   */
  rtb_mw4r = (real32_T)fabs((real_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws);

  /* Sum: '<S285>/Add1' incorporates:
   *  Abs: '<S282>/Abs2'
   *  Constant: '<S282>/Constant3'
   *  Sum: '<S282>/Add3'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  rtb_jwxe = (1.0F - ((real32_T)fabs((real_T)rtb_exxx))) -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgsj;

  /* Switch: '<S285>/Switch' incorporates:
   *  Constant: '<S285>/Constant'
   *  Constant: '<S285>/Tdf_pac_resid_rising_filt_coeff'
   *  Constant: '<S285>/Tdf_pac_residue_filter_coeff'
   *  RelationalOperator: '<S285>/Relational Operator'
   */
  if (rtb_jwxe > 0.0F) {
    tmp_w = Tdf_pac_resid_rising_filt_coeff;
  } else {
    tmp_w = Tdf_pac_residue_filter_coeff;
  }

  /* End of Switch: '<S285>/Switch' */

  /* Sum: '<S285>/Add2' incorporates:
   *  Product: '<S285>/Product'
   *  UnitDelay: '<S285>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgsj += rtb_jwxe * (((real32_T)tmp_w) *
    3.05175781E-5F);

  /* MinMax: '<S282>/MinMax3' incorporates:
   *  Constant: '<S282>/Constant4'
   *  Sum: '<S282>/Add5'
   */
  if (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgsj <= (1.0F - rtb_gfou)) {
    rtb_ojsl = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgsj;
  } else {
    rtb_ojsl = 1.0F - rtb_gfou;
  }

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Constant: '<S282>/Tdf_pac_torque_residue'
   *  MinMax: '<S282>/MinMax3'
   *  Product: '<S282>/Product'
   *  Sum: '<S282>/Add'
   */
  rtb_mw4r -= (((real32_T)Tdf_pac_torque_residue) * 0.0009765625F) * rtb_ojsl;
  if (0.0F >= rtb_mw4r) {
    rtb_mw4r = 0.0F;
  }

  /* Signum: '<S282>/Sign1' */
  if (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws < 0.0F) {
    rtb_ojsl = -1.0F;
  } else if (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws > 0.0F) {
    rtb_ojsl = 1.0F;
  } else {
    rtb_ojsl = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws;
  }

  /* Product: '<S282>/Product6' incorporates:
   *  Constant: '<S282>/Tdf_torque_reduction_gain'
   *  MinMax: '<S282>/MinMax'
   *  Product: '<S282>/Product1'
   *  Product: '<S282>/Product2'
   *  Product: '<S282>/Product9'
   *  Signum: '<S282>/Sign1'
   */
  rtb_ojsl = (rtb_dpeo * (rtb_e3dd * (rtb_ojsl * rtb_mw4r))) * (((real32_T)
    Tdf_torque_reduction_gain) * 0.0009765625F);

  /* DataTypeConversion: '<S289>/Data Type Conversion' incorporates:
   *  Constant: '<S289>/Tdf_derating_max_angle'
   */
  rtb_jwxe = ((real32_T)Tdf_derating_max_angle) * 0.0009765625F;

  /* MinMax: '<S289>/MinMax1' */
  if (rtb_ojsl <= rtb_jwxe) {
    rtb_jwxe = rtb_ojsl;
  }

  /* Gain: '<S289>/Gain1' incorporates:
   *  Constant: '<S289>/Tdf_derating_max_angle'
   *  DataTypeConversion: '<S289>/Data Type Conversion'
   */
  rtb_pnn5 = -(((real32_T)Tdf_derating_max_angle) * 0.0009765625F);

  /* MinMax: '<S289>/MinMax3' incorporates:
   *  MinMax: '<S289>/MinMax1'
   */
  if (rtb_jwxe >= rtb_pnn5) {
    rtb_pnn5 = rtb_jwxe;
  }

  /* End of MinMax: '<S289>/MinMax3' */

  /* Sum: '<S286>/Add' incorporates:
   *  Constant: '<S286>/Tdf_pac_torque_filter_coeff'
   *  DataTypeConversion: '<S286>/Data Type Conversion'
   *  Product: '<S286>/Product'
   *  Sum: '<S286>/Sub'
   *  UnitDelay: '<S286>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kpna += (rtb_pnn5 -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kpna) * (((real32_T)
    Tdf_pac_torque_filter_coeff) * 3.05175781E-5F);

  /* Product: '<S282>/Product7' incorporates:
   *  Constant: '<S282>/Tdf_damping_gain'
   *  Product: '<S282>/Product5'
   */
  rtb_jwxe = (((real32_T)Tdf_damping_gain) * 0.0009765625F) * (rtb_gemg *
    rtb_gfou);

  /* Sum: '<S287>/Add' incorporates:
   *  Constant: '<S287>/Tdf_pac_torque_vel_filter_coeff'
   *  DataTypeConversion: '<S287>/Data Type Conversion'
   *  Product: '<S287>/Product'
   *  Sum: '<S287>/Sub'
   *  UnitDelay: '<S287>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_am0s += (rtb_jwxe -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_am0s) * (((real32_T)
    Tdf_pac_torque_vel_filter_coeff) * 3.05175781E-5F);

  /* MinMax: '<S282>/MinMax2' incorporates:
   *  Lookup_n-D: '<S282>/TDF_Reduction_Gain_Schedul1'
   */
  rtb_gnup = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_gnup,
    (&(Tdf_trq_derating_thrs_x_schedul[0])), (&(Tdf_steer_trq_ff_gain_y_schedul
    [0])), 10U);

  /* Sum: '<S288>/Add' incorporates:
   *  Constant: '<S282>/Tdf_steer_torque_ffwd_gain'
   *  Constant: '<S288>/Tdf_steer_torque_ff_filter_coeff'
   *  DataTypeConversion: '<S288>/Data Type Conversion'
   *  Product: '<S282>/Product10'
   *  Product: '<S282>/Product11'
   *  Product: '<S282>/Product12'
   *  Product: '<S288>/Product'
   *  Sum: '<S288>/Sub'
   *  UnitDelay: '<S288>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_l240 += ((rtb_gnup * ((rtb_dpeo * rtb_exxx)
    * (((real32_T)Tdf_steer_torque_ffwd_gain) * 0.0009765625F))) -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_l240) * (((real32_T)
    Tdf_steer_torque_ff_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S282>/Add2' incorporates:
   *  Constant: '<S282>/Tdf_torque_reduction_p_gain'
   *  Product: '<S282>/Product8'
   */
  rtb_pnn5 = ((((((real32_T)Tdf_torque_reduction_p_gain) * 0.0009765625F) *
                rtb_pnn5) + DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kpna) +
              DMC_Soc_Lat_DWork.UnitDelay_DSTATE_am0s) -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_l240;

  /* Sum: '<S46>/Add2' incorporates:
   *  Constant: '<S46>/Constant10'
   *  Product: '<S46>/Product1'
   *  Product: '<S46>/Product7'
   *  Sum: '<S46>/Add1'
   *  Sum: '<S46>/Add7'
   */
  tmp_ = ((rtb_lyau * tmp_) + (rtb_e1oo * (1.0F - tmp_))) - rtb_pnn5;

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S48>/Constant'
   *  Logic: '<S48>/Logical Operator'
   *  S-Function (sfix_bitop): '<S48>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S48>/Bitwise Operator1'
   */
  if (((((int32_T)Dmc_configuration_mode) & ((int32_T)2048)) != ((int32_T)0)) &&
      ((((int32_T)Dmc_configuration_mode) & ((int32_T)8)) != ((int32_T)0))) {
    rtb_dpeo = rtb_cep1;
  } else {
    rtb_dpeo = 0.0F;
  }

  /* End of Switch: '<S48>/Switch1' */

  /* Switch: '<S48>/Switch2' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S48>/Constant4'
   *  S-Function (sfix_bitop): '<S48>/Bitwise Operator2'
   *  Sum: '<S48>/Add2'
   */
  if ((((int32_T)Dmc_configuration_mode) & ((int32_T)64)) != ((int32_T)0)) {
    rtb_dpeo += rtb_l1xc;
  } else {
    rtb_dpeo = 0.0F;
  }

  /* End of Switch: '<S48>/Switch2' */

  /* Switch: '<S292>/Switch' */
  if ((int32_T)(*rt_pynyI)) {
    /* MinMax: '<S282>/MinMax2' */
    rtb_gnup = *rt_kafvI;
  } else {
    /* MinMax: '<S282>/MinMax2' incorporates:
     *  Sum: '<S45>/Add1'
     *  Sum: '<S45>/Add2'
     */
    rtb_gnup = tmp_ + rtb_dpeo;
  }

  /* End of Switch: '<S292>/Switch' */

  /* UnitDelay: '<S291>/Unit Delay' */
  rtb_e3dd = DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bvsy;

  /* Sum: '<S291>/Sub (1)' */
  tmp_0 = rtb_gnup - rtb_e3dd;

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Gain: '<S297>/MpsToKph'
   *  Lookup_n-D: '<S297>/SAC_Delta_F_Grad_Barrier_Sched'
   *
   * Block description for '<S297>/SAC_Delta_F_Grad_Barrier_Sched':
   *  u: 1
   */
  rtb_mw4r = 3.6F * VEH_Vehicle_Speed;
  rtb_mw4r = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_mw4r,
    (&(Sac_delta_grad_barrier_x_sched[0])), (&(Sac_delta_grad_barrier_y_sched[0])),
    11U);

  /* Product: '<S297>/Product (1)' incorporates:
   *  Constant: '<S297>/Sac_delta_f_cmd_grad_barrier'
   *
   * Block description for '<S297>/Sac_delta_f_cmd_grad_barrier':
   *  u: deg/s
   */
  tmp_f = (((real32_T)Sac_delta_f_cmd_grad_barrier) * 0.0009765625F) * rtb_mw4r;

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Gain: '<S297>/Rescale'
   *  Product: '<S297>/Product (2)'
   */
  rtb_mw4r = tmp_f * (0.01F * (*rt_pxsgI));

  /* MinMax: '<S310>/SatMax' incorporates:
   *  Constant: '<S297>/Sac_delta_f_cmd_min_grad'
   *
   * Block description for '<S297>/Sac_delta_f_cmd_min_grad':
   *  u: deg/s
   */
  tmp_5 = ((real32_T)Sac_delta_f_cmd_min_grad) * 0.0009765625F;
  if (rtb_mw4r >= tmp_5) {
    tmp_5 = rtb_mw4r;
  }

  /* End of MinMax: '<S310>/SatMax' */

  /* MinMax: '<S310>/SatMin' */
  if (tmp_f <= tmp_5) {
  } else {
    tmp_f = tmp_5;
  }

  /* End of MinMax: '<S310>/SatMin' */

  /* MinMax: '<S297>/Max' incorporates:
   *  Constant: '<S297>/Sac_delta_f_cmd_grad_rampout'
   *
   * Block description for '<S297>/Sac_delta_f_cmd_grad_rampout':
   *  u: deg/s
   */
  tmp_5 = ((real32_T)Sac_delta_f_cmd_grad_rampout) * 0.0009765625F;
  if (tmp_5 >= tmp_f) {
  } else {
    tmp_5 = tmp_f;
  }

  /* End of MinMax: '<S297>/Max' */

  /* Switch: '<S297>/Switch (1)' */
  if ((int32_T)(*rt_pynyI)) {
  } else {
    tmp_5 = tmp_f;
  }

  /* End of Switch: '<S297>/Switch (1)' */

  /* Switch: '<S297>/Switch (2)' */
  if ((int32_T)(*rt_dptqI)) {
    tmp_5 = rtb_kzhy;
  }

  /* End of Switch: '<S297>/Switch (2)' */

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Switch: '<S295>/Switch (2)'
   */
  rtb_mw4r = tmp_5;

  /* Switch: '<S293>/Switch (1)' incorporates:
   *  Constant: '<S293>/No_Gradient'
   *
   * Block description for '<S293>/No_Gradient':
   *  u: deg/s
   */
  if ((int32_T)rtb_fzlt) {
    rtb_ergg = 0.0;
  } else {
    rtb_ergg = (real_T)rtb_mw4r;
  }

  /* End of Switch: '<S293>/Switch (1)' */

  /* Switch: '<S293>/Switch (2)' incorporates:
   *  UnitDelay: '<S47>/Alg_Loop'
   */
  if (DMC_Soc_Lat_DWork.Alg_Loop_DSTATE != 0.0F) {
  } else {
    rtb_ergg = (real_T)rtb_mw4r;
  }

  /* End of Switch: '<S293>/Switch (2)' */

  /* UnitDelay: '<S40>/Alg Loop1' */
  rtb_fzlt = DMC_Soc_Lat_DWork.AlgLoop1_DSTATE;

  /* Sum: '<S249>/Add' incorporates:
   *  Constant: '<S249>/Lat_gi_dot_filter_coeff'
   *  Product: '<S249>/Product'
   *  Sum: '<S249>/Add1'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  tmp_a = ((rtb_aayn - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_erx0) * (((real32_T)
             Lat_gi_yaw_dot_filter_coeff) * 3.05175781E-5F)) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_erx0;

  /* Gain: '<S249>/Sac_one_by_ts' incorporates:
   *  Sum: '<S249>/Add2'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  tmp_5 = ((real32_T)Sac_one_by_ts) * (tmp_a -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_erx0);

  /* Sum: '<S248>/Add' incorporates:
   *  Constant: '<S248>/Lat_gi_yaw_dot_filter_coeff'
   *  Product: '<S248>/Product'
   *  Sum: '<S248>/Add1'
   *  UnitDelay: '<S248>/Unit Delay'
   */
  tmp_b = ((rtb_hqad - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_drku) * (((real32_T)
             Lat_gi_yaw_dot_filter_coeff) * 3.05175781E-5F)) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_drku;

  /* Gain: '<S248>/Sac_one_by_ts' incorporates:
   *  Sum: '<S248>/Add2'
   *  UnitDelay: '<S248>/Unit Delay'
   */
  tmp_c = ((real32_T)Sac_one_by_ts) * (tmp_b -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_drku);

  /* Logic: '<S247>/Logical Operator4' incorporates:
   *  Constant: '<S247>/Constant2'
   *  Constant: '<S247>/Constant3'
   *  RelationalOperator: '<S247>/Relational Operator1'
   *  RelationalOperator: '<S247>/Relational Operator2'
   */
  rtb_ovjx = (boolean_T)((int32_T)((tmp_5 > 0.0F) && (tmp_c < 0.0F)));

  /* Logic: '<S247>/Logical Operator' incorporates:
   *  Constant: '<S247>/Constant11'
   *  Constant: '<S247>/Constant8'
   *  RelationalOperator: '<S247>/Relational Operator4'
   *  RelationalOperator: '<S247>/Relational Operator7'
   */
  rtb_bhbp = (boolean_T)((int32_T)((tmp_5 < 0.0F) && (tmp_c > 0.0F)));

  /* Logic: '<S247>/Logical Operator2' incorporates:
   *  Logic: '<S247>/Logical Operator1'
   */
  rtb_ayms = (boolean_T)((int32_T)(((int32_T)rtb_ovjx) && (!rtb_bhbp)));

  /* Logic: '<S247>/Logical Operator3' incorporates:
   *  Logic: '<S247>/Logical Operator5'
   */
  rtb_desf = (boolean_T)((int32_T)((!rtb_ovjx) && ((int32_T)rtb_bhbp)));

  /* UnitDelay: '<S245>/Unit Delay3' */
  rtb_ovjx = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_djgi;

  /* Logic: '<S245>/Logical Operator3' incorporates:
   *  Logic: '<S245>/Logical Operator1'
   *  Logic: '<S245>/Logical Operator2'
   *  Logic: '<S245>/Logical Operator4'
   *  RelationalOperator: '<S245>/Relational Operator3'
   */
  rtb_ohj2 = (boolean_T)((int32_T)(((!rtb_ayms) && (!rtb_desf)) || (rtb_ovjx !=
    rtb_desf)));

  /* UnitDelay: '<S245>/Unit Delay1' */
  rtb_ovjx = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_is2t;

  /* UnitDelay: '<S230>/Unit Delay2' */
  tmp_f = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hshs;

  /* Switch: '<S230>/Switch2' incorporates:
   *  Constant: '<S230>/Constant5'
   *  Logic: '<S245>/Logical Operator5'
   *  RelationalOperator: '<S245>/Relational Operator4'
   */
  if (((int32_T)rtb_ohj2) || (rtb_ovjx != rtb_ayms)) {
    tmp_f = 0.0F;
  }

  /* End of Switch: '<S230>/Switch2' */

  /* RelationalOperator: '<S246>/Relational Operator2' incorporates:
   *  Constant: '<S246>/Lat_gi_yaw_rate_offset'
   */
  rtb_ovjx = (boolean_T)((int32_T)(0.0F == (((real32_T)Lat_gi_yaw_rate_offset) *
    0.0009765625F)));

  /* Logic: '<S246>/Logical Operator' incorporates:
   *  Constant: '<S246>/Lat_gi_yaw_rate_offset'
   *  RelationalOperator: '<S246>/Relational Operator'
   */
  rtb_bhbp = (boolean_T)((int32_T)(((int32_T)rtb_ovjx) || (rtb_hqad <
    (((real32_T)Lat_gi_yaw_rate_offset) * 0.0009765625F))));

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  Constant: '<S230>/Lat_gi_yaw_debounce_thrs'
   *  DataTypeConversion: '<S230>/Data Type Conversion2'
   *  RelationalOperator: '<S230>/Relational Operator2'
   */
  rtb_ji32 = (boolean_T)((int32_T)((tmp_f >= ((real32_T)Lat_gi_yaw_debounce_thrs))
    && ((int32_T)rtb_bhbp)));

  /* Logic: '<S246>/Logical Operator1' incorporates:
   *  Constant: '<S246>/Lat_gi_yaw_rate_offset'
   *  Gain: '<S246>/Gain'
   *  RelationalOperator: '<S246>/Relational Operator1'
   */
  rtb_ovjx = (boolean_T)((int32_T)((rtb_hqad > (-(((real32_T)
    Lat_gi_yaw_rate_offset) * 0.0009765625F))) || ((int32_T)rtb_ovjx)));

  /* Logic: '<S230>/Logical Operator' incorporates:
   *  Constant: '<S230>/Lat_gi_yaw_debounce_thrs'
   *  DataTypeConversion: '<S230>/Data Type Conversion2'
   *  Gain: '<S230>/Gain'
   *  RelationalOperator: '<S230>/Relational Operator'
   */
  rtb_kiah = (boolean_T)((int32_T)(((int32_T)rtb_ovjx) && (tmp_f <= (-((real32_T)
    Lat_gi_yaw_debounce_thrs)))));

  /* Logic: '<S229>/Logical Operator8' incorporates:
   *  Logic: '<S229>/Logical Operator5'
   *  Logic: '<S229>/Logical Operator6'
   *  Logic: '<S229>/Logical Operator7'
   */
  rtb_k1lr = (boolean_T)((int32_T)((((int32_T)rtb_pkm5) && ((int32_T)rtb_ji32)) ||
                          ((!rtb_pkm5) && ((int32_T)rtb_kiah))));

  /* Logic: '<S232>/Logical Operator9' */
  rtb_cj00 = (boolean_T)((int32_T)(((int32_T)rtb_fzlt) && ((int32_T)rtb_k1lr)));

  /* Logic: '<S232>/Logical Operator5' */
  rtb_nlrq = (boolean_T)((int32_T)(((int32_T)(*rt_j53pI)) && ((int32_T)rtb_cj00)));

  /* Switch: '<S293>/Switch (3)' incorporates:
   *  Logic: '<S293>/Logical Operator1'
   *  Logic: '<S293>/Logical Operator2'
   */
  if ((!rtb_nlrq) && ((int32_T)rtb_jomt)) {
  } else {
    rtb_ergg = (real_T)rtb_mw4r;
  }

  /* End of Switch: '<S293>/Switch (3)' */

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Constant: '<S298>/Constant'
   *  Constant: '<S298>/Constant1'
   *  Sum: '<S298>/Sub'
   *  Sum: '<S298>/Sub1'
   */
  rtb_mw4r = 1.0F - (1.0F - rtb_n1zt);

  /* MinMax: '<S298>/MinMax' incorporates:
   *  Constant: '<S298>/Sac_delta_f_counter_steer_grad'
   *
   * Block description for '<S298>/Sac_delta_f_counter_steer_grad':
   *  u: deg/s
   */
  rtb_elan = ((real_T)Sac_delta_f_counter_steer_grad) * 0.0009765625;
  if (rtb_ergg >= rtb_elan) {
    rtb_elan = rtb_ergg;
  }

  /* Sum: '<S298>/Add' incorporates:
   *  Constant: '<S298>/Constant1'
   *  MinMax: '<S298>/MinMax'
   *  Product: '<S298>/Product (1)'
   *  Product: '<S298>/Product (2)'
   *  Sum: '<S298>/Sub1'
   */
  rtb_ergg = (rtb_ergg * ((real_T)rtb_mw4r)) + (rtb_elan * ((real_T)((real32_T)
    (1.0F - rtb_n1zt))));

  /* Product: '<S294>/Product' incorporates:
   *  DataTypeConversion: '<S298>/Data Type Conversion'
   */
  rtb_pfif *= (real32_T)rtb_ergg;

  /* MinMax: '<S282>/MinMax' incorporates:
   *  Abs: '<S291>/Abs (1)'
   */
  rtb_mw4r = (real32_T)fabs((real_T)tmp_0);

  /* Gain: '<S291>/Sac_ts' incorporates:
   *  DataTypeConversion: '<S298>/Data Type Conversion'
   *
   * Block description for '<S291>/Sac_ts':
   *  u: seconds
   */
  rtb_m3dz = (((real32_T)Sac_ts) * 3.05175781E-5F) * ((real32_T)rtb_ergg);

  /* Sum: '<S291>/Sub (2)' */
  tmp_2 = rtb_mw4r - rtb_m3dz;

  /* MinMax: '<S299>/Maximum' */
  if (0.0F >= tmp_2) {
    tmp_2 = 0.0F;
  }

  /* End of MinMax: '<S299>/Maximum' */

  /* MinMax: '<S299>/Minimum' */
  if (rtb_pfif <= tmp_2) {
  } else {
    rtb_pfif = tmp_2;
  }

  /* End of MinMax: '<S299>/Minimum' */

  /* Signum: '<S291>/Sign' */
  if (tmp_0 < 0.0F) {
    tmp_2 = -1.0F;
  } else if (tmp_0 > 0.0F) {
    tmp_2 = 1.0F;
  } else {
    tmp_2 = tmp_0;
  }

  /* End of Signum: '<S291>/Sign' */

  /* Sum: '<S309>/Add1' incorporates:
   *  UnitDelay: '<S309>/Unit Delay'
   */
  tmp_6 = (*rt_o3aadI) - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_aucg;

  /* Sum: '<S309>/Add' incorporates:
   *  Constant: '<S307>/Tdf_delta_f_latency_comp_coeff'
   *  Product: '<S309>/Product'
   *  UnitDelay: '<S309>/Unit Delay'
   */
  tmp_d = (tmp_6 * (((real32_T)Tdf_delta_f_latency_comp_coeff) * 3.05175781E-5F))
    + DMC_Soc_Lat_DWork.UnitDelay_DSTATE_aucg;

  /* Sum: '<S307>/Add4' incorporates:
   *  Constant: '<S307>/Sac_delta_f_latency'
   *  Gain: '<S309>/Sac_one_by_ts'
   *  Product: '<S307>/Product'
   *  Sum: '<S309>/Add2'
   *  UnitDelay: '<S309>/Unit Delay'
   */
  rtb_e1oo = ((((real32_T)Sac_one_by_ts) * (tmp_d -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_aucg)) * (((real32_T)Sac_delta_f_latency)
    * 0.0009765625F)) + (*rt_o3aadI);

  /* Sum: '<S296>/Add (1)' */
  tmp_7 = rtb_dpeo + rtb_e1oo;

  /* UnitDelay: '<S296>/Unit Delay (1)' */
  tmp_8 = DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e1bg;

  /* UnitDelay: '<S296>/Unit Delay (2)' */
  tmp_9 = DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hrg2;

  /* Product: '<S291>/Product (1)' */
  rtb_m3dz *= tmp_2;

  /* Abs: '<S291>/Abs (2)' */
  rtb_m3dz = (real32_T)fabs((real_T)rtb_m3dz);

  /* Switch: '<S291>/Switch' incorporates:
   *  Gain: '<S296>/Gain'
   *  MinMax: '<S291>/Minimum'
   *  Product: '<S291>/Product (3)'
   *  Sum: '<S291>/Add (1)'
   *  Sum: '<S296>/Add (2)'
   *  UnitDelay: '<S296>/Unit Delay (1)'
   *  UnitDelay: '<S296>/Unit Delay (2)'
   *  UnitDelay: '<S296>/Unit Delay (3)'
   */
  if ((int32_T)SAC_Disable) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bvsy = 0.25F * (((tmp_7 +
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e1bg) +
      DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hrg2) +
      DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ffue);
  } else {
    if (rtb_mw4r <= rtb_m3dz) {
      /* MinMax: '<S291>/Minimum' */
      rtb_m3dz = rtb_mw4r;
    }

    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bvsy = (tmp_2 * rtb_m3dz) + rtb_e3dd;
  }

  /* End of Switch: '<S291>/Switch' */

  /* Sum: '<S291>/Add (2)' incorporates:
   *  Product: '<S291>/Product (2)'
   */
  *rt_jus11I = (rtb_pfif * tmp_2) + DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bvsy;

  /* Sum: '<S291>/Sub (4)' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE = (*rt_jus11I) - rtb_dpeo;

  /* Abs: '<S42>/Abs3' */
  rtb_m3dz = (real32_T)fabs((real_T)(*rt_ngfdoI));

  /* Switch: '<S42>/Switch1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant5'
   */
  if ((int32_T)rtb_icrr) {
    rtb_dpeo = 32.0F;
  } else {
    rtb_dpeo = 0.0F;
  }

  /* End of Switch: '<S42>/Switch1' */

  /* Switch: '<S42>/Switch2' incorporates:
   *  Abs: '<S42>/Abs1'
   *  Constant: '<S42>/Constant6'
   *  Constant: '<S42>/Constant7'
   *  RelationalOperator: '<S42>/Relational Operator'
   */
  if (rtb_afoa > ((real32_T)fabs((real_T)
        DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE))) {
    rtb_e1oo = 64.0F;
  } else {
    rtb_e1oo = 0.0F;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Switch: '<S42>/Switch3' incorporates:
   *  Abs: '<S42>/Abs2'
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S42>/Constant2'
   *  RelationalOperator: '<S42>/Relational Operator1'
   */
  if (((real32_T)fabs((real_T)rtb_macq)) > rtb_m3dz) {
    tmp_6 = 128.0F;
  } else {
    tmp_6 = 0.0F;
  }

  /* End of Switch: '<S42>/Switch3' */

  /* DataTypeConversion: '<S42>/Data Type Conversion3' incorporates:
   *  Sum: '<S42>/Add'
   */
  SAT_Active_Saturation_dbg = (uint16_T)((real32_T)(((((real32_T)rtb_oclz) +
    rtb_dpeo) + rtb_e1oo) + tmp_6));

  /* UnitDelay: '<S29>/Alg_Loop_Delay14' */
  rtb_nexq = DMC_Soc_Lat_DWork.Alg_Loop_Delay14_DSTATE;

  /* ModelReference: '<S29>/SAC_Proportional_Factor_Derating' */
  DMC_Soc_Lat_SAC_Proportional_Factor_Derating(&rtb_macq, &rtb_hd5l, &rtb_ls5n,
    &rtb_a2h2, &rtb_j5oy, &rtb_jgkv);

  /* DataTypeConversion: '<S29>/Data Type Conversion' */
  SAT_Angle_Rate_Residual_dbg = (int16_T)((real32_T)floor(rtb_jgkv / 0.001526F));

  /* DataTypeConversion: '<S29>/Data Type Conversion1' */
  *rt_kwuguI = (uint8_T)rtb_flnx;

  /* DataTypeConversion: '<S29>/Data Type Conversion3' */
  TDF_Torque_Derating_Factor_dbg = (uint16_T)((real32_T)(rtb_n1zt * 1024.0F));

  /* DataTypeConversion: '<S29>/Data Type Conversion7' */
  LAT_Debug5_dbg = (int16_T)((real32_T)floor(rtb_pdty * 1024.0F));

  /* DataTypeConversion: '<S29>/Data Type Conversion9' */
  SAC_Faded_Angle_Command_dbg = (int16_T)((real32_T)floor(rtb_hd5l / 0.001526F));

  /* DataTypeConversion: '<S64>/Data Type Conversion12' */
  SAC_Enhanced_Angle_Cmd_dbg = (int16_T)((real32_T)floor(tmp_1 / 0.001526F));

  /* DataTypeConversion: '<S68>/Data Type Conversion11' */
  SAC_Filtered_Angle_Command_dbg = (int16_T)((real32_T)floor(tmp_3 / 0.001526F));

  /* DataTypeConversion: '<S68>/Data Type Conversion12' */
  SAC_Dyn_Corrected_Angle_Cmd_dbg = (int16_T)((real32_T)floor(tmp_1 / 0.001526F));

  /* DataTypeConversion: '<S68>/Data Type Conversion2' */
  SAC_Dynamic_Correction_Factor_dbg = (uint16_T)((real32_T)(rtb_heqw * 1024.0F));

  /* DataTypeConversion: '<S36>/Data Type Conversion' */
  LAT_Ay_Control_Limit_Bias_dbg = (int16_T)((real32_T)floor(rtb_cy3g / 0.001526F));

  /* DataTypeConversion: '<S203>/Data Type Conversion' */
  LAT_Ay_Dynamic_Threshold_dbg = (uint16_T)((real32_T)
    (DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 * 1024.0F));

  /* RelationalOperator: '<S206>/Relational Operator5' incorporates:
   *  Abs: '<S206>/Abs4'
   *  Constant: '<S206>/Lat_ay_ctrl_detach_thrs'
   *  Sum: '<S206>/Add5'
   */
  rtb_pcxk = (boolean_T)((int32_T)((rtb_cy3g - ((real32_T)fabs((real_T)rtb_hd5l)))
    > (((real32_T)Lat_ay_ctrl_detach_thrs) * 0.0009765625F)));

  /* Sum: '<S221>/Add1' incorporates:
   *  Constant: '<S221>/Constant10'
   *  Product: '<S221>/Product1'
   *  Product: '<S221>/Product7'
   *  Sum: '<S221>/Add7'
   */
  rtb_e1oo = rtb_eypw + (rtb_ez30 * (1.0F - rtb_eypw));

  /* MinMax: '<S221>/MinMax2' */
  if (rtb_ez30 >= rtb_e1oo) {
    rtb_e1oo = rtb_ez30;
  }

  /* DataTypeConversion: '<S37>/Data Type Conversion2' incorporates:
   *  Gain: '<S37>/Gain2'
   *  MinMax: '<S221>/MinMax2'
   */
  *rt_kafvzI = (uint8_T)((real32_T)(100.0F * rtb_e1oo));

  /* Switch: '<S222>/Switch1' incorporates:
   *  Constant: '<S222>/Constant'
   *  Constant: '<S222>/Constant1'
   *  Constant: '<S38>/Constant4'
   *  RelationalOperator: '<S38>/Relational Operator2'
   */
  if (rtb_ozv1 > 0.0F) {
    rtb_e1oo = 1.0F;
  } else {
    rtb_e1oo = 0.0F;
  }

  /* End of Switch: '<S222>/Switch1' */

  /* Switch: '<S222>/Switch2' incorporates:
   *  Constant: '<S222>/Constant2'
   *  Constant: '<S222>/Constant3'
   *  Constant: '<S38>/Constant4'
   *  RelationalOperator: '<S38>/Relational Operator3'
   */
  if (0.0F > rtb_ozv1) {
    tmp_6 = 1.0F;
  } else {
    tmp_6 = 0.0F;
  }

  /* End of Switch: '<S222>/Switch2' */

  /* Gain: '<S222>/Gain2' */
  rtb_kw01 = (((int32_T)tmp_6) << ((int8_T)1));

  /* Switch: '<S222>/Switch3' incorporates:
   *  Constant: '<S222>/Constant4'
   *  Constant: '<S222>/Constant5'
   */
  if ((int32_T)rtb_icrr) {
    tmp_6 = 1.0F;
  } else {
    tmp_6 = 0.0F;
  }

  /* End of Switch: '<S222>/Switch3' */

  /* Gain: '<S222>/Gain3' */
  rtb_kzp5 = (((int32_T)tmp_6) << ((int8_T)2));

  /* Switch: '<S222>/Switch4' incorporates:
   *  Constant: '<S222>/Constant6'
   *  Constant: '<S222>/Constant7'
   *  Constant: '<S38>/Constant10'
   *  RelationalOperator: '<S38>/Relational Operator4'
   */
  if (rtb_gfou > 0.0F) {
    tmp_6 = 1.0F;
  } else {
    tmp_6 = 0.0F;
  }

  /* End of Switch: '<S222>/Switch4' */

  /* Sum: '<S222>/Add' incorporates:
   *  Gain: '<S222>/Gain4'
   */
  *rt_pops4I = ((rtb_e1oo + ((real32_T)rtb_kw01)) + ((real32_T)rtb_kzp5)) +
    (8.0F * tmp_6);

  /* Signum: '<S39>/Sign' */
  if (rtb_eh0v < 0.0F) {
    rtb_dpeo = -1.0F;
  } else if (rtb_eh0v > 0.0F) {
    rtb_dpeo = 1.0F;
  } else {
    rtb_dpeo = rtb_eh0v;
  }

  /* End of Signum: '<S39>/Sign' */

  /* Logic: '<S39>/Logical Operator2' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Constant: '<S39>/Constant2'
   *  RelationalOperator: '<S39>/Relational Operator1'
   *  RelationalOperator: '<S39>/Relational Operator2'
   */
  rtb_fm0p = (boolean_T)((int32_T)((rtb_c4yx <= 0.98F) || (rtb_jeca <= 0.01F)));

  /* Sum: '<S242>/Add' incorporates:
   *  Constant: '<S242>/Lat_gi_dot_filter_coeff'
   *  DataTypeConversion: '<S242>/Data Type Conversion1'
   *  Product: '<S242>/Product'
   *  Sum: '<S242>/Add1'
   *  UnitDelay: '<S242>/Unit Delay'
   */
  tmp_1 = ((rtb_euvg - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_o534) * (((real32_T)
             Lat_gi_dot_filter_coeff) * 3.05175781E-5F)) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_o534;

  /* Gain: '<S242>/Sac_one_by_ts' incorporates:
   *  Sum: '<S242>/Add2'
   *  UnitDelay: '<S242>/Unit Delay'
   */
  rtb_e1oo = ((real32_T)Sac_one_by_ts) * (tmp_1 -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_o534);

  /* Sum: '<S241>/Add' incorporates:
   *  Constant: '<S241>/Lat_gi_dot_filter_coeff'
   *  DataTypeConversion: '<S241>/Data Type Conversion'
   *  Product: '<S241>/Product'
   *  Sum: '<S241>/Add1'
   *  UnitDelay: '<S241>/Unit Delay'
   */
  tmp_2 = ((DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE -
            DMC_Soc_Lat_DWork.UnitDelay_DSTATE_gnzo) * (((real32_T)
             Lat_gi_dot_filter_coeff) * 3.05175781E-5F)) +
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_gnzo;

  /* Gain: '<S241>/Sac_one_by_ts' incorporates:
   *  Sum: '<S241>/Add2'
   *  UnitDelay: '<S241>/Unit Delay'
   */
  tmp_6 = ((real32_T)Sac_one_by_ts) * (tmp_2 -
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_gnzo);

  /* Logic: '<S243>/Logical Operator4' incorporates:
   *  Constant: '<S243>/Constant1'
   *  Constant: '<S243>/Constant2'
   *  Constant: '<S243>/Constant3'
   *  Logic: '<S243>/Logical Operator3'
   *  RelationalOperator: '<S243>/Relational Operator1'
   *  RelationalOperator: '<S243>/Relational Operator2'
   *  RelationalOperator: '<S243>/Relational Operator3'
   */
  rtb_crhi = (boolean_T)((int32_T)((rtb_e1oo < 0.0F) && ((rtb_euvg < 0.0F) &&
    (tmp_6 < 0.0F))));

  /* Logic: '<S243>/Logical Operator1' incorporates:
   *  Constant: '<S243>/Constant10'
   *  Constant: '<S243>/Constant11'
   *  Constant: '<S243>/Constant8'
   *  Logic: '<S243>/Logical Operator'
   *  RelationalOperator: '<S243>/Relational Operator4'
   *  RelationalOperator: '<S243>/Relational Operator6'
   *  RelationalOperator: '<S243>/Relational Operator7'
   */
  rtb_lcw5 = (boolean_T)((int32_T)(((rtb_e1oo > 0.0F) && (rtb_euvg > 0.0F)) &&
    (tmp_6 > 0.0F)));

  /* Logic: '<S243>/Logical Operator5' incorporates:
   *  RelationalOperator: '<S243>/Relational Operator'
   *  RelationalOperator: '<S243>/Relational Operator5'
   *  UnitDelay: '<S243>/Unit Delay'
   *  UnitDelay: '<S243>/Unit Delay1'
   */
  rtb_gwnw = (boolean_T)((int32_T)((DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgm4 !=
    rtb_crhi) || (DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mxbc != rtb_lcw5)));

  /* Abs: '<S228>/Abs1' */
  rtb_e1oo = (real32_T)fabs((real_T)rtb_e1oo);

  /* RelationalOperator: '<S228>/Relational Operator3' incorporates:
   *  Constant: '<S228>/Lat_gi_min_lateral_error_gradient'
   */
  rtb_ohj2 = (boolean_T)((int32_T)(rtb_e1oo > (((real32_T)
    Lat_gi_min_lateral_error_gradient) * 0.0009765625F)));

  /* RelationalOperator: '<S228>/Relational Operator2' incorporates:
   *  Abs: '<S228>/Abs'
   *  Constant: '<S228>/Lat_gi_min_lateral_error'
   */
  rtb_fckq = (boolean_T)((int32_T)(((real32_T)fabs((real_T)rtb_euvg)) >
    (((real32_T)Lat_gi_min_lateral_error) * 0.0009765625F)));

  /* Abs: '<S228>/Abs2' */
  tmp_6 = (real32_T)fabs((real_T)tmp_6);

  /* RelationalOperator: '<S228>/Relational Operator5' incorporates:
   *  Constant: '<S228>/Lat_gi_min_delta_f_cmd_gradient'
   */
  rtb_bcax = (boolean_T)((int32_T)(tmp_6 > (((real32_T)
    Lat_gi_min_delta_f_cmd_gradient) * 0.0009765625F)));

  /* Logic: '<S243>/Logical Operator2' */
  rtb_fsbi = (boolean_T)((int32_T)(((int32_T)rtb_crhi) || ((int32_T)rtb_lcw5)));

  /* ArithShift: '<S224>/Shift Arithmetic' incorporates:
   *  Constant: '<S224>/Lat_gi_foretime_loops'
   */
  rtb_elan = ldexp((real_T)Lat_gi_foretime_loops, -3);

  /* Switch: '<S224>/Switch1' incorporates:
   *  Constant: '<S224>/Constant5'
   *  Constant: '<S224>/Lat_gi_quadrnt_discharge_factor'
   *  Gain: '<S224>/Gain2'
   *  Product: '<S224>/Product'
   */
  if ((int32_T)rtb_fsbi) {
    rtb_ergg = -1.0;
  } else {
    rtb_ergg = -(rtb_elan * (((real_T)Lat_gi_quadrnt_discharge_factor) *
      0.0009765625));
  }

  /* End of Switch: '<S224>/Switch1' */

  /* Switch: '<S224>/Switch2' incorporates:
   *  Constant: '<S224>/Constant3'
   *  Logic: '<S228>/Logical Operator1'
   *  Logic: '<S228>/Logical Operator2'
   *  Logic: '<S228>/Logical Operator4'
   */
  if (((((int32_T)rtb_ohj2) && ((int32_T)rtb_fckq)) && ((int32_T)rtb_bcax)) &&
      ((int32_T)rtb_fsbi)) {
    rtb_ergg = 1.0;
  }

  /* End of Switch: '<S224>/Switch2' */

  /* Switch: '<S224>/Switch3' incorporates:
   *  MinMax: '<S224>/MinMax2'
   *  UnitDelay: '<S224>/Unit Delay1'
   */
  if ((int32_T)rtb_gwnw) {
    /* MinMax: '<S224>/MinMax2' incorporates:
     *  Constant: '<S224>/Constant1'
     */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q = 0.0;
  } else {
    if (0.0 >= DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q) {
      /* MinMax: '<S224>/MinMax2' */
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q = 0.0;
    }

    /* MinMax: '<S224>/MinMax3' incorporates:
     *  MinMax: '<S224>/MinMax2'
     */
    if (rtb_elan <= DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q = rtb_elan;
    }

    /* MinMax: '<S224>/MinMax2' incorporates:
     *  MinMax: '<S224>/MinMax3'
     *  Sum: '<S224>/Add1'
     */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q += rtb_ergg;
  }

  /* End of Switch: '<S224>/Switch3' */

  /* RelationalOperator: '<S224>/Relational Operator1' incorporates:
   *  Constant: '<S224>/Lat_gi_debounce_factor'
   *  Product: '<S224>/Product1'
   */
  rtb_amqm = (boolean_T)((int32_T)(DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q >=
    (rtb_elan * (((real_T)Lat_gi_debounce_factor) * 0.0009765625))));

  /* Logic: '<S227>/Logical Operator2' incorporates:
   *  Logic: '<S227>/Logical Operator'
   *  Logic: '<S227>/Logical Operator3'
   *  RelationalOperator: '<S227>/Relational Operator1'
   *  UnitDelay: '<S227>/Unit Delay1'
   *  UnitDelay: '<S227>/Unit Delay3'
   *  UnitDelay: '<S40>/Alg Loop'
   */
  rtb_gpun = (boolean_T)((int32_T)((((int32_T)DMC_Soc_Lat_DWork.AlgLoop_DSTATE) ||
                           (((int32_T)rtb_amqm) && ((int32_T)
    DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_mdgq))) || (((real_T)
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_opjk) >= rtb_elan)));

  /* Sum: '<S223>/Add' incorporates:
   *  Gain: '<S223>/Gain (1)'
   *  Gain: '<S223>/Gain (10)'
   *  Gain: '<S223>/Gain (11)'
   *  Gain: '<S223>/Gain (12)'
   *  Gain: '<S223>/Gain (13)'
   *  Gain: '<S223>/Gain (14)'
   *  Gain: '<S223>/Gain (15)'
   *  Gain: '<S223>/Gain (2)'
   *  Gain: '<S223>/Gain (3)'
   *  Gain: '<S223>/Gain (4)'
   *  Gain: '<S223>/Gain (5)'
   *  Gain: '<S223>/Gain (6)'
   *  Gain: '<S223>/Gain (7)'
   *  Gain: '<S223>/Gain (8)'
   *  Gain: '<S223>/Gain (9)'
   *  Switch: '<S223>/Switch (1)'
   *  Switch: '<S223>/Switch (2)'
   *  Switch: '<S223>/Switch (3)'
   *  Switch: '<S223>/Switch (4)'
   *  Switch: '<S223>/Switch (5)'
   *  Switch: '<S223>/Switch (6)'
   *  Switch: '<S223>/Switch (7)'
   *  Switch: '<S223>/Switch (8)'
   *  Switch: '<S223>/Switch (9)'
   *  Switch: '<S223>/Switch (9)1'
   *  Switch: '<S223>/Switch (9)2'
   *  Switch: '<S223>/Switch (9)3'
   *  Switch: '<S223>/Switch (9)4'
   *  Switch: '<S223>/Switch (9)5'
   */
  LAT_Gi_Status_dbg = (uint16_T)((((((((((((((((uint32_T)rtb_gpun) + ((uint16_T)
    ((int32_T)(((int32_T)rtb_ohj2) << 1)))) + ((uint16_T)((int32_T)(((int32_T)
    rtb_fckq) << 2)))) + ((uint16_T)((int32_T)(((int32_T)rtb_bcax) << 3)))) +
    ((uint16_T)((int32_T)(((int32_T)rtb_fsbi) << 4)))) + ((uint16_T)((int32_T)
    (((int32_T)rtb_fzlt) << 5)))) + ((uint16_T)((int32_T)(((int32_T)rtb_pkm5) <<
    6)))) + ((uint16_T)((int32_T)(((int32_T)rtb_k1lr) << 7)))) + ((uint16_T)
    ((int32_T)(((int32_T)rtb_kiah) << 8)))) + ((uint16_T)((int32_T)(((int32_T)
    rtb_ji32) << 9)))) + ((uint16_T)((int32_T)(((int32_T)(*rt_j53pI)) << 10))))
    + ((uint16_T)((int32_T)(((int32_T)rtb_ovjx) << 11)))) + ((uint16_T)((int32_T)
                                     (((int32_T)rtb_bhbp) << 12)))) + ((uint16_T)
                                   ((int32_T)(((int32_T)rtb_cj00) << 13)))) +
    (rtb_nlrq << 14));

  /* Outputs for Triggered SubSystem: '<S40>/LAT_Gi_Shift_Register' incorporates:
   *  TriggerPort: '<S226>/Trigger'
   */
  if (((int32_T)rtb_gpun) &&
      (DMC_Soc_Lat_PrevZCSigState.LAT_Gi_Shift_Register_Trig_ZCE != POS_ZCSIG))
  {
    /* Switch: '<S235>/Switch' incorporates:
     *  Constant: '<S235>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nc01 = (boolean_T)false;
    }

    /* End of Switch: '<S235>/Switch' */

    /* Switch: '<S234>/Switch' incorporates:
     *  Constant: '<S234>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_dsnr = (boolean_T)false;
    }

    /* End of Switch: '<S234>/Switch' */

    /* Switch: '<S239>/Switch' incorporates:
     *  Constant: '<S239>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mg5o = (boolean_T)false;
    }

    /* End of Switch: '<S239>/Switch' */

    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S233>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nxl5 = (boolean_T)false;
    }

    /* End of Switch: '<S233>/Switch' */

    /* Switch: '<S236>/Switch' incorporates:
     *  Constant: '<S236>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_cr5d = (boolean_T)false;
    }

    /* End of Switch: '<S236>/Switch' */

    /* Switch: '<S237>/Switch' incorporates:
     *  Constant: '<S237>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b45s = (boolean_T)false;
    }

    /* End of Switch: '<S237>/Switch' */

    /* Switch: '<S238>/Switch' incorporates:
     *  Constant: '<S238>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_m43z = (boolean_T)false;
    }

    /* End of Switch: '<S238>/Switch' */

    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S240>/Constant'
     *  UnitDelay: '<S226>/Unit Delay9'
     */
    if ((int32_T)DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq) {
      rtb_ohj2 = (boolean_T)false;
    } else {
      rtb_ohj2 = rtb_amqm;
    }

    /* End of Switch: '<S240>/Switch' */

    /* RelationalOperator: '<S226>/Relational Operator' incorporates:
     *  Constant: '<S226>/Lat_gi_minimum_confidence'
     *  DataTypeConversion: '<S226>/Data Type Conversion'
     *  DataTypeConversion: '<S226>/Data Type Conversion1'
     *  DataTypeConversion: '<S226>/Data Type Conversion2'
     *  DataTypeConversion: '<S226>/Data Type Conversion3'
     *  DataTypeConversion: '<S226>/Data Type Conversion4'
     *  DataTypeConversion: '<S226>/Data Type Conversion5'
     *  DataTypeConversion: '<S226>/Data Type Conversion6'
     *  DataTypeConversion: '<S226>/Data Type Conversion7'
     *  Sum: '<S226>/Add'
     *  UnitDelay: '<S235>/Unit Delay1'
     */
    DMC_Soc_Lat_B.RelationalOperator = (boolean_T)((int32_T)(((((((((((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ejt4) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nc01)) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_dsnr)) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mg5o)) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nxl5)) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_cr5d)) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b45s)) + ((uint32_T)
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_m43z)) + ((uint32_T)rtb_ohj2)) >=
      ((uint32_T)Lat_gi_minimum_confidence)));

    /* Update for UnitDelay: '<S235>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ejt4 =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nc01;

    /* Update for UnitDelay: '<S226>/Unit Delay9' incorporates:
     *  UnitDelay: '<S226>/Unit Delay10'
     */
    DMC_Soc_Lat_DWork.UnitDelay9_DSTATE_npcq =
      DMC_Soc_Lat_DWork.UnitDelay10_DSTATE_hhgz;

    /* Update for UnitDelay: '<S234>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nc01 =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_dsnr;

    /* Update for UnitDelay: '<S239>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_dsnr =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mg5o;

    /* Update for UnitDelay: '<S233>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mg5o =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nxl5;

    /* Update for UnitDelay: '<S236>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nxl5 =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_cr5d;

    /* Update for UnitDelay: '<S237>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_cr5d =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b45s;

    /* Update for UnitDelay: '<S238>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b45s =
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_m43z;

    /* Update for UnitDelay: '<S240>/Unit Delay1' */
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_m43z = rtb_ohj2;

    /* Update for UnitDelay: '<S226>/Unit Delay10' incorporates:
     *  UnitDelay: '<S226>/Unit Delay11'
     */
    DMC_Soc_Lat_DWork.UnitDelay10_DSTATE_hhgz =
      DMC_Soc_Lat_DWork.UnitDelay11_DSTATE_amny;

    /* Update for UnitDelay: '<S226>/Unit Delay11' incorporates:
     *  Logic: '<S225>/Logical Operator1'
     *  Logic: '<S225>/Logical Operator2'
     *  Logic: '<S225>/Logical Operator3'
     *  Logic: '<S225>/Logical Operator4'
     *  Logic: '<S225>/Logical Operator5'
     *  Logic: '<S225>/Logical Operator6'
     *  Logic: '<S225>/Logical Operator7'
     *  UnitDelay: '<S40>/Alg Loop'
     */
    DMC_Soc_Lat_DWork.UnitDelay11_DSTATE_amny = (boolean_T)((int32_T)(((int32_T)
      DMC_Soc_Lat_DWork.AlgLoop_DSTATE) && ((!rtb_k1lr) && (!((((int32_T)
      rtb_crhi) && ((int32_T)rtb_kiah)) || (((int32_T)rtb_lcw5) && ((int32_T)
      rtb_ji32)))))));
  }

  DMC_Soc_Lat_PrevZCSigState.LAT_Gi_Shift_Register_Trig_ZCE = (uint8_T)((int32_T)
    (rtb_gpun ? ((int32_T)((uint8_T)POS_ZCSIG)) : ((int32_T)((uint8_T)ZERO_ZCSIG))));

  /* End of Outputs for SubSystem: '<S40>/LAT_Gi_Shift_Register' */

  /* Switch: '<S227>/Switch1' incorporates:
   *  Constant: '<S227>/Constant1'
   *  Constant: '<S227>/Constant3'
   *  Sum: '<S227>/Add1'
   *  UnitDelay: '<S227>/Unit Delay1'
   */
  if ((int32_T)rtb_gpun) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_opjk = 0U;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_opjk++;
  }

  /* End of Switch: '<S227>/Switch1' */

  /* Switch: '<S230>/Switch1' incorporates:
   *  Constant: '<S230>/Constant2'
   *  Constant: '<S230>/Constant3'
   */
  if ((int32_T)rtb_desf) {
    rtb_e1oo = -1.0F;
  } else {
    rtb_e1oo = 1.0F;
  }

  /* End of Switch: '<S230>/Switch1' */

  /* Abs: '<S231>/Abs3' */
  tmp_5 = (real32_T)fabs((real_T)tmp_5);

  /* Abs: '<S231>/Abs5' */
  tmp_c = (real32_T)fabs((real_T)tmp_c);

  /* Switch: '<S230>/Switch3' incorporates:
   *  Constant: '<S230>/Constant4'
   *  Constant: '<S230>/Constant7'
   *  Constant: '<S231>/Lat_gi_min_yaw_rate_gradient'
   *  Constant: '<S231>/Lat_gi_min_yrc_residl_gradient'
   *  Logic: '<S231>/Logical Operator3'
   *  RelationalOperator: '<S231>/Relational Operator1'
   *  RelationalOperator: '<S231>/Relational Operator4'
   */
  if ((tmp_5 > (((real32_T)Lat_gi_min_yrc_residl_gradient) * 0.0009765625F)) &&
      (tmp_c > (((real32_T)Lat_gi_min_yaw_rate_gradient) * 0.0009765625F))) {
    tmp_6 = 1.0F;
  } else {
    tmp_6 = -1.0F;
  }

  /* End of Switch: '<S230>/Switch3' */

  /* Product: '<S230>/Product' */
  rtb_kw01 = (int32_T)((real32_T)(rtb_e1oo * tmp_6));

  /* Switch: '<S244>/Switch4' incorporates:
   *  Constant: '<S244>/Constant1'
   *  Constant: '<S244>/Lat_gi_yaw_debounce_loops'
   *  DataTypeConversion: '<S244>/Data Type Conversion'
   */
  if ((int32_T)rtb_ayms) {
    tmp_6 = (real32_T)Lat_gi_yaw_debounce_loops;
  } else {
    tmp_6 = 0.0F;
  }

  /* End of Switch: '<S244>/Switch4' */

  /* MinMax: '<S244>/MinMax' */
  if (tmp_f <= tmp_6) {
  } else {
    tmp_f = tmp_6;
  }

  /* End of MinMax: '<S244>/MinMax' */

  /* Switch: '<S244>/Switch5' incorporates:
   *  Constant: '<S244>/Constant9'
   *  Constant: '<S244>/Lat_gi_yaw_debounce_loops'
   *  DataTypeConversion: '<S244>/Data Type Conversion'
   *  Gain: '<S244>/Gain1'
   */
  if ((int32_T)rtb_ayms) {
    rtb_e1oo = 0.0F;
  } else {
    rtb_e1oo = -((real32_T)Lat_gi_yaw_debounce_loops);
  }

  /* End of Switch: '<S244>/Switch5' */

  /* MinMax: '<S244>/MinMax1' */
  if (tmp_f >= rtb_e1oo) {
  } else {
    tmp_f = rtb_e1oo;
  }

  /* End of MinMax: '<S244>/MinMax1' */

  /* ModelReference: '<S29>/LAT_Stiffness_Definition' */
  DMC_Soc_Lat_LAT_Stiffness_Definition(&rtb_c4yx, &rtb_ifco, &rtb_n0ba,
    rt_kkeboI);

  /* Switch: '<S256>/Switch1' incorporates:
   *  Abs: '<S255>/Abs'
   *  Constant: '<S256>/Constant7'
   *  Constant: '<S259>/Constant'
   *  RelationalOperator: '<S259>/Compare'
   *  Sum: '<S255>/Add'
   *  UnitDelay: '<S255>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)
         (DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kho1 - ((real32_T)rtb_itp5))))) >
      0.0F) {
    rtb_ergg = 0.0;
  } else {
    /* MinMax: '<S256>/MinMax' incorporates:
     *  Constant: '<S256>/Constant5'
     *  Constant: '<S256>/Dit_dirac_loop_count'
     *  Sum: '<S256>/Add1'
     *  UnitDelay: '<S256>/Unit Delay1'
     */
    rtb_ergg = ((real_T)Dit_dirac_loop_count) * 0.0009765625;
    if ((1.0 + DMC_Soc_Lat_DWork.UnitDelay1_DSTATE) <= rtb_ergg) {
      rtb_ergg = 1.0 + DMC_Soc_Lat_DWork.UnitDelay1_DSTATE;
    }

    /* End of MinMax: '<S256>/MinMax' */
  }

  /* End of Switch: '<S256>/Switch1' */

  /* Switch: '<S257>/Switch' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S257>/Constant6'
   *  Constant: '<S257>/Dit_signal_gen_frequency'
   *  Gain: '<S257>/IntegGain2'
   *  Logic: '<S254>/Logical Operator'
   *  Logic: '<S254>/Logical Operator1'
   *  S-Function (sfix_bitop): '<S254>/Bitwise Operator2'
   *  Sum: '<S257>/IntegSum'
   *  UnitDelay: '<S257>/Unit Delay1'
   */
  if (((!((((int32_T)Dmc_configuration_mode) & ((int32_T)16)) != ((int32_T)0))) ||
       ((int32_T)DMC_Soc_Lat_B.MOT_Modulation_Torque_o2)) || ((int32_T)
       SAC_Disable)) {
    rtb_e1oo = 0.0F;
  } else {
    if (((int32_T)Sac_ts) > ((int32_T)511)) {
      /* Gain: '<S257>/IntegGain2' */
      tmp_w = MAX_uint16_T;
    } else {
      /* Gain: '<S257>/IntegGain2' */
      tmp_w = (uint16_T)(Sac_ts << ((int8_T)7));
    }

    rtb_e1oo = (((real32_T)((uint32_T)(((uint32_T)tmp_w) * ((uint32_T)
      Dit_signal_gen_frequency)))) * 2.32830644E-10F) +
      DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_hzxr;
  }

  /* End of Switch: '<S257>/Switch' */

  /* Switch: '<S257>/Switch2' incorporates:
   *  Constant: '<S257>/Constant4'
   *  Constant: '<S257>/Constant5'
   *  RelationalOperator: '<S257>/Relational Operator1'
   */
  if (rtb_e1oo >= 1.0F) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_hzxr = 0.0F;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_hzxr = rtb_e1oo;
  }

  /* End of Switch: '<S257>/Switch2' */

  /* DataTypeConversion: '<S43>/Data Type Conversion4' */
  SAC_Friction_Comp_Torque_Out_dbg = (int16_T)((real32_T)floor(rtb_kggy / 0.001F));

  /* Switch: '<S252>/Switch1' incorporates:
   *  Constant: '<S252>/Constant8'
   */
  if (((int32_T)tmp_x) != ((int32_T)0)) {
    *rt_cjpenI = 0.0F;
  } else {
    *rt_cjpenI = rtb_n4jt;
  }

  /* End of Switch: '<S252>/Switch1' */

  /* Logic: '<S43>/Logical Operator' */
  rtb_dvgz = (boolean_T)((int32_T)(!rtb_owpf));

  /* DataTypeConversion: '<S277>/Data Type Conversion' */
  SAT_Req_Angle_Supp_Control_dbg = (int16_T)((real32_T)floor(rtb_jnhy /
    0.001526F));

  /* Sum: '<S46>/Add4' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE = rtb_lyau - (*rt_o3aadI);

  /* DataTypeConversion: '<S46>/Data Type Conversion' */
  SAC_Derated_Angle_Command_dbg = (int16_T)((real32_T)floor(tmp_ / 0.001526F));

  /* DataTypeConversion: '<S46>/Data Type Conversion1' */
  SAC_Derated_Eps_Torque_dbg = (int16_T)((real32_T)floor(rtb_pnn5 * 1024.0F));

  /* Abs: '<S282>/Abs3' */
  rtb_pnn5 = (real32_T)fabs((real_T)rtb_pnn5);

  /* Abs: '<S282>/Abs4' */
  rtb_jwxe = (real32_T)fabs((real_T)rtb_jwxe);

  /* Abs: '<S282>/Abs5' */
  rtb_ojsl = (real32_T)fabs((real_T)rtb_ojsl);

  /* Logic: '<S282>/Logical Operator3' incorporates:
   *  Constant: '<S282>/Constant11'
   *  Constant: '<S282>/Constant7'
   *  Constant: '<S282>/Constant8'
   *  Logic: '<S282>/Logical Operator'
   *  RelationalOperator: '<S282>/Relational Operator'
   *  RelationalOperator: '<S282>/Relational Operator1'
   *  RelationalOperator: '<S282>/Relational Operator4'
   */
  DMC_Soc_Lat_DWork.Algloop6_DSTATE = (boolean_T)((int32_T)((rtb_pnn5 > 0.05F) ||
    ((rtb_ojsl > 0.015F) || (rtb_jwxe > 0.015F))));

  /* Sum: '<S291>/Sub (3)' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay8_DSTATE = rtb_gnup - (*rt_jus11I);

  /* Switch: '<S49>/Switch' incorporates:
   *  Sum: '<S133>/Add5'
   */
  if ((int32_T)SAC_Disable) {
    rtb_e1oo = *rt_o3aadI;
  } else {
    rtb_e1oo = rtb_n3s4 + DYC_Steer_Angle_Feedforward;
  }

  /* End of Switch: '<S49>/Switch' */

  /* MinMax: '<S313>/Min' */
  if (rtb_e1oo <= rtb_l1lr) {
  } else {
    rtb_e1oo = rtb_l1lr;
  }

  /* End of MinMax: '<S313>/Min' */

  /* MinMax: '<S49>/MinMax' */
  if (DYC_Angle_Per_Kappa >= 0.1F) {
    rtb_ojsl = DYC_Angle_Per_Kappa;
  } else {
    rtb_ojsl = 0.1F;
  }

  /* MinMax: '<S313>/Max' incorporates:
   *  Gain: '<S313>/Gain1'
   */
  if (rtb_e1oo >= (-rtb_l1lr)) {
  } else {
    rtb_e1oo = -rtb_l1lr;
  }

  /* Product: '<S49>/Divide' incorporates:
   *  MinMax: '<S313>/Max'
   *  MinMax: '<S49>/MinMax'
   */
  *rt_pehleI = rtb_e1oo / rtb_ojsl;

  /* DataTypeConversion: '<S49>/Data Type Conversion1' */
  SAC_Control_Error_Eps_dbg = (int16_T)((real32_T)floor(rtb_eh0v / 0.001526F));

  /* DataTypeConversion: '<S49>/Data Type Conversion2' */
  SAC_Angle_Command_Raw_dbg = (int16_T)((real32_T)floor((*rt_jus11I) / 0.001526F));

  /* Product: '<S49>/Product6' */
  *rt_hny3uI = (*rt_jus11I) * (*rt_m2jwI);

  /* Switch: '<S29>/Switch' incorporates:
   *  Abs: '<S29>/Abs'
   *  Constant: '<S29>/Constant6'
   *  Constant: '<S29>/Tdf_derating_thrs_eps_i_hold'
   *  DataTypeConversion: '<S29>/Data Type Conversion4'
   *  Logic: '<S29>/Logical Operator'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S29>/Relational Operator1'
   */
  if (Tdf_derating_thrs_eps_i_hold < ((int16_T)0)) {
    *rt_e45jiI = (int16_T)1;
  } else {
    *rt_e45jiI = (int16_T)((((real32_T)fabs((real_T)(*rt_dmmuI))) > (((real32_T)
      Tdf_derating_thrs_eps_i_hold) * 0.0009765625F)) && ((int32_T)LDP_Active));
  }

  /* End of Switch: '<S29>/Switch' */

  /* Constant: '<S29>/Constant1' */
  *rt_mcq4bI = (uint16_T)0U;

  /* DataTypeConversion: '<S17>/Data Type Conversion3' */
  *rt_eltpnI = (uint8_T)(*rt_bofcI);

  /* Gain: '<S8>/Gain4' incorporates:
   *  UnitDelay: '<S8>/Unit Delay'
   */
  tmp_6 = 0.01F * DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hxjk;

  /* MinMax: '<S8>/MinMax2' */
  if (1.0F <= tmp_6) {
    rtb_m3dz = 1.0F;
  } else {
    rtb_m3dz = tmp_6;
  }

  /* End of MinMax: '<S8>/MinMax2' */

  /* DataTypeConversion: '<S17>/Data Type Conversion4' incorporates:
   *  Gain: '<S17>/Gain2'
   */
  *rt_m3xflI = (uint8_T)((real32_T)(100.0F * rtb_m3dz));

  /* UnitDelay: '<S462>/Unit Delay3' */
  rtb_n4jt = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif;

  /* Sum: '<S475>/Diff' incorporates:
   *  UnitDelay: '<S462>/Unit Delay3'
   *  UnitDelay: '<S475>/UD'
   *
   * Block description for '<S475>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S475>/UD':
   *
   *  Store in Global RAM
   */
  tmp_6 = DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif -
    DMC_Soc_Lat_DWork.UD_DSTATE_eihf;

  /* Saturate: '<S462>/Saturation' */
  if (tmp_6 > 1.0F) {
    tmp_6 = 1.0F;
  } else {
    if (tmp_6 < 0.0F) {
      tmp_6 = 0.0F;
    }
  }

  /* End of Saturate: '<S462>/Saturation' */

  /* DataTypeConversion: '<S462>/Data Type Conversion5' incorporates:
   *  UnitDelay: '<S458>/Unit Delay'
   */
  rtb_kzp5 = (int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_du4u;

  /* Switch: '<S477>/Switch2' incorporates:
   *  UnitDelay: '<S462>/Unit Delay3'
   */
  if (DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif != 0.0F) {
  } else {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24 = VEH_Vehicle_Speed;
  }

  /* End of Switch: '<S477>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S462>/S-R_Flip_Flop' */

  /* DataTypeConversion: '<S462>/Data Type Conversion' incorporates:
   *  Constant: '<S467>/Constant'
   *  RelationalOperator: '<S467>/Compare'
   *  Sum: '<S476>/Diff'
   *  UnitDelay: '<S476>/UD'
   *
   * Block description for '<S476>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S476>/UD':
   *
   *  Store in Global RAM
   */
  DMC_Soc_Lat_SR_Flip_Flop(tmp_6 != 0.0F, (rtb_fit4 -
    DMC_Soc_Lat_DWork.UD_DSTATE) < 0.0F, rtb_hy3g,
    &DMC_Soc_Lat_DWork.SR_Flip_Flop_alsc);

  /* End of Outputs for SubSystem: '<S462>/S-R_Flip_Flop' */

  /* Switch: '<S490>/Switch5' incorporates:
   *  Constant: '<S490>/Constant5'
   *  Gain: '<S490>/Sac_ts'
   *  Product: '<S490>/Product'
   *  Sum: '<S490>/Add1'
   */
  if ((int32_T)rtb_dm2g) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_g0mi = 0.0F;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_g0mi = ((((real32_T)Sac_ts) *
      3.05175781E-5F) * (0.8F * rtb_l0rv)) + rtb_axf1;
  }

  /* End of Switch: '<S490>/Switch5' */

  /* Switch: '<S488>/Switch' incorporates:
   *  Constant: '<S488>/Constant'
   *  Constant: '<S488>/Constant1'
   */
  if ((int32_T)rtb_dm2g) {
    tmp_6 = 0.0F;
  } else {
    tmp_6 = 1.0F;
  }

  /* End of Switch: '<S488>/Switch' */

  /* Switch: '<S488>/Switch1' incorporates:
   *  Constant: '<S488>/Constant3'
   *  Gain: '<S488>/Sac_ts'
   *  Sum: '<S488>/Add3'
   */
  if ((int32_T)rtb_dm2g) {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_h20c = 0.0F;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_h20c = ((((real32_T)Sac_ts) *
      3.05175781E-5F) * tmp_6) + rtb_dtuy;
  }

  /* End of Switch: '<S488>/Switch1' */

  /* Constant: '<S22>/Lat_damp_eps_time_const ' */
  tmp_6 = ((real32_T)Lat_damp_eps_time_const) * 0.0009765625F;

  /* MinMax: '<S22>/MinMax' */
  if (0.125F >= tmp_6) {
    tmp_6 = 0.125F;
  }

  /* End of MinMax: '<S22>/MinMax' */

  /* Sum: '<S22>/Add6' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Lat_damp_eps_damping'
   *  Gain: '<S22>/Gain'
   *  Product: '<S22>/Divide'
   *  Product: '<S22>/Divide1'
   *  Product: '<S22>/Product3'
   *  Product: '<S22>/Product4'
   *  Product: '<S22>/Product5'
   *  Sum: '<S22>/Add7'
   */
  rtb_e1oo = ((1.0F / (tmp_6 * tmp_6)) *
              (DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE - rtb_hwhx)) - (((2.0F *
    (((real32_T)Lat_damp_eps_damping) * 0.0009765625F)) / tmp_6) * rtb_gmy5);

  /* Switch: '<S498>/Switch' incorporates:
   *  Constant: '<S22>/Sac_notch_l1'
   *  DataTypeConversion: '<S22>/Data Type Conversion2'
   *  Product: '<S22>/Product2'
   *  Sum: '<S22>/Add9'
   *
   * Block requirements for '<S22>/Add9':
   *  1. Eps Torque Request
   */
  if ((int32_T)rtb_hdiu) {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3 = *rt_o3aadI;
  } else {
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3 = ((((real32_T)Sac_notch_l1) *
      0.0009765625F) * rtb_maat) + rtb_hwhx;
  }

  /* End of Switch: '<S498>/Switch' */

  /* Constant: '<S546>/Constant' */
  *rt_e4ho4I = 0.0F;

  /* MinMax: '<S8>/MinMax3' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   */
  if (25.0F >= ((real32_T)(*rt_epsyI))) {
    rtb_ojsl = 25.0F;
  } else {
    rtb_ojsl = (real32_T)(*rt_epsyI);
  }

  /* Sum: '<S8>/Add1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  tmp_6 = ((real32_T)(*rt_gohpI)) - DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hxjk;

  /* Signum: '<S8>/Sign1' */
  if (tmp_6 < 0.0F) {
    tmp_c = -1.0F;
  } else if (tmp_6 > 0.0F) {
    tmp_c = 1.0F;
  } else {
    tmp_c = tmp_6;
  }

  /* End of Signum: '<S8>/Sign1' */

  /* Abs: '<S8>/Abs1' incorporates:
   *  Gain: '<S8>/Sac_ts'
   *  MinMax: '<S8>/MinMax3'
   *  Product: '<S8>/Product'
   */
  tmp_5 = (real32_T)fabs((real_T)((real32_T)(((((real32_T)Sac_ts) *
    3.05175781E-5F) * ((real32_T)((int32_T)rtb_ojsl))) * tmp_c)));

  /* Abs: '<S8>/Abs2' */
  tmp_6 = (real32_T)fabs((real_T)tmp_6);

  /* DataTypeConversion: '<S8>/Data Type Conversion4' */
  SAC_Max_Torque_Scale_dbg = (int16_T)((real32_T)floor(rtb_m3dz * 1024.0F));

  /* Update for UnitDelay: '<Root>/Alg loop1' */
  DMC_Soc_Lat_DWork.Algloop1_DSTATE_mkup = rtb_ef4d;

  /* Update for UnitDelay: '<Root>/Alg_Loop_Delay12' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE = *rt_pehleI;

  /* Update for UnitDelay: '<S5>/Alg_Loop' incorporates:
   *  Abs: '<S39>/Abs'
   *  Constant: '<S39>/Constant3'
   *  Constant: '<S39>/Sac_eps_no_control_error'
   *  Logic: '<S39>/Logical Operator1'
   *  Logic: '<S39>/Logical Operator3'
   *  Product: '<S39>/Product'
   *  RelationalOperator: '<S39>/Relational Operator3'
   *  RelationalOperator: '<S39>/Relational Operator4'
   *  UnitDelay: '<S39>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.Alg_Loop_DSTATE_gi5b = (boolean_T)((int32_T)((((rtb_dpeo *
    DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nzhp) <= 0.0F) || (((real32_T)fabs
    ((real_T)rtb_eh0v)) <= (((real32_T)Sac_eps_no_control_error) * 0.0009765625F)))
    && ((int32_T)rtb_fm0p)));

  /* Update for UnitDelay: '<S5>/Alg_Loop2' */
  DMC_Soc_Lat_DWork.Alg_Loop2_DSTATE = *rt_dmmu3I;

  /* Update for UnitDelay: '<S5>/Alg_Loop3' */
  DMC_Soc_Lat_DWork.Alg_Loop3_DSTATE = *rt_gyqsrI;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jfr0 = rtb_lscy;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ee5c = *rt_pynyI;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_oowh = rtb_ef4d;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_i4w1 = rtb_pyzc;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b22d = rtb_azal;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE = rtb_e4ku;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_jsby = rtb_jhzt;

  /* Update for UnitDelay: '<S5>/Alg_Loop1' */
  DMC_Soc_Lat_DWork.Alg_Loop1_DSTATE = LDP_Active;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_abtt = *rt_dzorI;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kyvd = rtb_mdfx;

  /* Update for UnitDelay: '<S15>/Alg loop1' */
  DMC_Soc_Lat_DWork.Algloop1_DSTATE = rtb_iuh5;

  /* Update for UnitDelay: '<S17>/Alg loop' */
  DMC_Soc_Lat_DWork.Algloop_DSTATE = rtb_ifco;

  /* Update for UnitDelay: '<S17>/Alg loop1' */
  DMC_Soc_Lat_DWork.Algloop1_DSTATE_jnar = rtb_llzw[(int8_T)1];

  /* Update for UnitDelay: '<S17>/Alg loop2' */
  DMC_Soc_Lat_DWork.Algloop2_DSTATE = DYC_Steer_Angle_Feedforward;

  /* Update for UnitDelay: '<S17>/Alg loop3' */
  DMC_Soc_Lat_DWork.Algloop3_DSTATE = *rt_ngfdoI;

  /* Update for UnitDelay: '<S17>/Alg loop4' */
  DMC_Soc_Lat_DWork.Algloop4_DSTATE = rtb_kzgj;

  /* Update for UnitDelay: '<S17>/Alg loop5' */
  DMC_Soc_Lat_DWork.Algloop5_DSTATE = *rt_dmmu3I;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay23' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay23_DSTATE = *rt_o3aadI;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay_DSTATE = rtb_a2h2;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay12' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE_hbpm = *rt_pehleI;

  /* Update for UnitDelay: '<S17>/Unit Delay alg loop' */
  DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE = rtb_gemg;

  /* MinMax: '<S19>/MinMax' */
  if (rtb_fadn <= 20.0F) {
    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    DMC_Soc_Lat_DWork.UnitDelay2_DSTATE = rtb_fadn;
  } else {
    /* Update for UnitDelay: '<S19>/Unit Delay2' */
    DMC_Soc_Lat_DWork.UnitDelay2_DSTATE = 20.0F;
  }

  /* End of MinMax: '<S19>/MinMax' */

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d3m1 = rtb_fyle;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay17' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay17_DSTATE = rtb_iuh5;

  /* Update for DiscreteIntegrator: '<S489>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S486>/Exc_signal_gen_frequency'
   *  Gain: '<S489>/Gain'
   *  Product: '<S489>/Product'
   */
  if (!rtb_dm2g) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE += 0.01F * ((4.0F *
      (((real32_T)Exc_signal_gen_frequency) * 0.0009765625F)) * rtb_h0la);
  }

  if ((int32_T)rtb_dm2g) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState = 1;
  } else {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S489>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S478>/Discrete-Time Integrator' */
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cs0j += 0.01F;

  /* Update for UnitDelay: '<S478>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_f0dp = rtb_l15a;

  /* Update for UnitDelay: '<S458>/Unit Delay' incorporates:
   *  Constant: '<S458>/Exc_restart_chirp'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_du4u = Exc_restart_chirp;

  /* Update for DiscreteIntegrator: '<S462>/Discrete-Time Integrator1' incorporates:
   *  UnitDelay: '<S462>/Unit Delay3'
   */
  if (!rtb_m4lj) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_DSTATE += 0.01F *
      DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif;
  }

  if ((int32_T)rtb_m4lj) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_PrevResetState = 1;
  } else {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S462>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S480>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S463>/Exc_trq_signal_gen_frequency'
   *  Gain: '<S480>/Gain'
   *  Product: '<S480>/Product'
   */
  if (!rtb_e5xk) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cipt += 0.01F * ((4.0F *
      (((real32_T)Exc_trq_signal_gen_frequency) * 0.0009765625F)) * rtb_);
  }

  if ((int32_T)rtb_e5xk) {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState_lpiz = 1;
  } else {
    DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_PrevResetState_lpiz = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S480>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S462>/Unit Delay5' */
  DMC_Soc_Lat_DWork.UnitDelay5_DSTATE_jjz1 = rtb_hy3g[(int8_T)1];

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay5' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay5_DSTATE = rtb_ls5n;

  /* Update for UnitDelay: '<S47>/Alg_Loop' */
  DMC_Soc_Lat_DWork.Alg_Loop_DSTATE = tmp_0;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay3' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay3_DSTATE = rtb_gemg;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay18' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay18_DSTATE = rtb_gemg;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay4' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay4_DSTATE =
    DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay10' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay10_DSTATE = *rt_ngfdoI;

  /* Update for UnitDelay: '<S49>/Unit Delay alg loop' */
  DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE_kepf = *rt_jus11I;

  /* Update for UnitDelay: '<S49>/Unit Delay alg loop1' */
  DMC_Soc_Lat_DWork.UnitDelayalgloop1_DSTATE = *rt_kafvI;

  /* Update for UnitDelay: '<S221>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e43m = rtb_ez30;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay15' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay15_DSTATE =
    DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay16' incorporates:
   *  Sum: '<S133>/Add4'
   */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay16_DSTATE = rtb_macq - rtb_idqr;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay19' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay19_DSTATE = DMC_Soc_Lat_DWork.Algloop6_DSTATE;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay1' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay1_DSTATE = rtb_lmkf;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay11' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay11_DSTATE = rtb_kgdq;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay13' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay13_DSTATE = rtb_iuh5;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay7' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay7_DSTATE = rtb_etec;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay2' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay2_DSTATE = rtb_na3o;

  /* Update for UnitDelay: '<S279>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hnnx = rtb_jnhy;

  /* Update for UnitDelay: '<S36>/Alg_loop' */
  DMC_Soc_Lat_DWork.Alg_loop_DSTATE = rtb_llzw[(int8_T)1];

  /* Update for UnitDelay: '<S206>/Alg_loop1' incorporates:
   *  Logic: '<S206>/Logical Operator5'
   *  UnitDelay: '<S206>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.Alg_loop1_DSTATE = (boolean_T)((int32_T)((((int32_T)rtb_pcxk)
    && ((int32_T)DMC_Soc_Lat_DWork.UnitDelay_DSTATE_g4ol)) && ((int32_T)
    rtb_llzw[(int8_T)1])));

  /* Update for UnitDelay: '<S206>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_foqo = SAC_Disable;

  /* Update for UnitDelay: '<S210>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_my50 = rtb_mkzu;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay9' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay9_DSTATE = rtb_lyau;

  /* Update for UnitDelay: '<S207>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mtzq = rtb_llzw[(int8_T)1];

  /* Update for UnitDelay: '<S86>/Unit Delay1' incorporates:
   *  Gain: '<S86>/Sac_ts'
   *  Sum: '<S86>/Add1'
   *  UnitDelay: '<S86>/Unit Delay1'
   */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_a5ig += (((real32_T)Sac_ts) *
    3.05175781E-5F) * rtb_iwln;

  /* Update for UnitDelay: '<S87>/Unit Delay1' incorporates:
   *  Gain: '<S87>/Sac_ts'
   *  Sum: '<S87>/Add1'
   *  UnitDelay: '<S87>/Unit Delay1'
   */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nsgx += (((real32_T)Sac_ts) *
    3.05175781E-5F) * rtb_m0pk;

  /* Update for UnitDelay: '<S82>/Unit Delay1' incorporates:
   *  Gain: '<S82>/Sac_ts'
   *  Sum: '<S82>/Add1'
   */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_kxgv = ((((real32_T)Sac_ts) *
    3.05175781E-5F) * rtb_l1ll) + rtb_cfdi;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay21' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay21_DSTATE =
    DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE;

  /* Update for UnitDelay: '<S497>/Unit Delay3' incorporates:
   *  Gain: '<S497>/Sac_ts1'
   *  Sum: '<S497>/Add2'
   */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE = rtb_hwhx + ((((real32_T)Sac_ts) *
    3.05175781E-5F) * tmp_4);

  /* Update for UnitDelay: '<S498>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_i13z = tmp_i;

  /* Update for UnitDelay: '<S498>/Unit Delay2' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ckqg = tmp_j;

  /* Update for UnitDelay: '<S498>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_jaq2 = tmp_k;

  /* Update for UnitDelay: '<S498>/Unit Delay4' */
  DMC_Soc_Lat_DWork.UnitDelay4_DSTATE = tmp_l;

  /* Update for UnitDelay: '<S498>/Unit Delay5' */
  DMC_Soc_Lat_DWork.UnitDelay5_DSTATE = tmp_m;

  /* Update for UnitDelay: '<S498>/Unit Delay6' */
  DMC_Soc_Lat_DWork.UnitDelay6_DSTATE = tmp_n;

  /* Update for UnitDelay: '<S498>/Unit Delay7' */
  DMC_Soc_Lat_DWork.UnitDelay7_DSTATE = tmp_o;

  /* Update for UnitDelay: '<S498>/Unit Delay8' */
  DMC_Soc_Lat_DWork.UnitDelay8_DSTATE = tmp_p;

  /* Update for UnitDelay: '<S498>/Unit Delay9' */
  DMC_Soc_Lat_DWork.UnitDelay9_DSTATE = tmp_q;

  /* Update for UnitDelay: '<S498>/Unit Delay10' */
  DMC_Soc_Lat_DWork.UnitDelay10_DSTATE = tmp_r;

  /* Update for UnitDelay: '<S498>/Unit Delay11' */
  DMC_Soc_Lat_DWork.UnitDelay11_DSTATE = tmp_s;

  /* Update for UnitDelay: '<S498>/Unit Delay12' */
  DMC_Soc_Lat_DWork.UnitDelay12_DSTATE = tmp_t;

  /* Update for UnitDelay: '<S498>/Unit Delay13' */
  DMC_Soc_Lat_DWork.UnitDelay13_DSTATE = tmp_u;

  /* Update for UnitDelay: '<S498>/Unit Delay14' */
  DMC_Soc_Lat_DWork.UnitDelay14_DSTATE = tmp_v;

  /* Update for UnitDelay: '<S496>/Unit Delay3' incorporates:
   *  Constant: '<S22>/Sac_notch_l3'
   *  DataTypeConversion: '<S22>/Data Type Conversion'
   *  Gain: '<S496>/Sac_ts1'
   *  Product: '<S22>/Product6'
   *  Sum: '<S22>/Add11'
   *  Sum: '<S496>/Add2'
   */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_b55e = rtb_gmy5 + ((((real32_T)Sac_ts) *
    3.05175781E-5F) * (((((real32_T)Sac_notch_l3) * 0.0009765625F) * rtb_maat) +
                       rtb_e1oo));

  /* Update for UnitDelay: '<S118>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d45l = tmp_h;

  /* Update for UnitDelay: '<S270>/Unit Delay1' incorporates:
   *  Constant: '<S269>/Sac_ffwd_diff_filter_omega'
   *  Gain: '<S270>/Sac_ts'
   *  Product: '<S269>/Product1'
   *  Sum: '<S270>/Add1'
   *  UnitDelay: '<S270>/Unit Delay1'
   */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jjfr += (((real32_T)Sac_ts) *
    3.05175781E-5F) * ((((real32_T)Sac_ffwd_diff_filter_omega) * 0.0009765625F) *
                       tmp_g);

  /* Update for UnitDelay: '<S256>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE = rtb_ergg;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay20' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay20_DSTATE =
    DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE;

  /* Update for UnitDelay: '<S250>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ddx5 = rtb_c4yx;

  /* Update for UnitDelay: '<S284>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pfgp = tmp_e;

  /* Update for UnitDelay: '<S40>/Alg Loop1' */
  DMC_Soc_Lat_DWork.AlgLoop1_DSTATE = DMC_Soc_Lat_B.RelationalOperator;

  /* Update for UnitDelay: '<S249>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_erx0 = tmp_a;

  /* Update for UnitDelay: '<S248>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_drku = tmp_b;

  /* Update for UnitDelay: '<S245>/Unit Delay3' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_djgi = rtb_desf;

  /* Update for UnitDelay: '<S245>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_is2t = rtb_ayms;

  /* Update for UnitDelay: '<S230>/Unit Delay2' incorporates:
   *  Sum: '<S230>/Add3'
   */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hshs = ((real32_T)rtb_kw01) + tmp_f;

  /* Update for UnitDelay: '<S309>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_aucg = tmp_d;

  /* Update for UnitDelay: '<S296>/Unit Delay (1)' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e1bg = tmp_7;

  /* Update for UnitDelay: '<S296>/Unit Delay (2)' */
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hrg2 = tmp_8;

  /* Update for UnitDelay: '<S296>/Unit Delay (3)' */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ffue = tmp_9;

  /* Update for UnitDelay: '<S29>/Alg_Loop_Delay14' */
  DMC_Soc_Lat_DWork.Alg_Loop_Delay14_DSTATE =
    DMC_Soc_Lat_DWork.Alg_Loop_Delay8_DSTATE;

  /* Update for UnitDelay: '<S206>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_g4ol = rtb_pcxk;

  /* Update for UnitDelay: '<S39>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nzhp = rtb_dpeo;

  /* Update for UnitDelay: '<S40>/Alg Loop' */
  DMC_Soc_Lat_DWork.AlgLoop_DSTATE = rtb_gwnw;

  /* Update for UnitDelay: '<S243>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgm4 = rtb_crhi;

  /* Update for UnitDelay: '<S242>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_o534 = tmp_1;

  /* Update for UnitDelay: '<S241>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_gnzo = tmp_2;

  /* Update for UnitDelay: '<S243>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_mxbc = rtb_lcw5;

  /* Update for UnitDelay: '<S227>/Unit Delay3' incorporates:
   *  Logic: '<S227>/Logical Operator1'
   */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_mdgq = (boolean_T)((int32_T)(!rtb_amqm));

  /* Update for UnitDelay: '<S255>/Unit Delay' */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kho1 = (real32_T)rtb_itp5;

  /* MinMax: '<S8>/MinMax1' */
  if (tmp_5 <= tmp_6) {
    tmp_6 = tmp_5;
  }

  /* Update for UnitDelay: '<S8>/Unit Delay' incorporates:
   *  MinMax: '<S8>/MinMax1'
   *  Product: '<S8>/Product1'
   *  Sum: '<S8>/Add'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hxjk += tmp_c * tmp_6;

  /* Update for UnitDelay: '<S476>/UD'
   *
   * Block description for '<S476>/UD':
   *
   *  Store in Global RAM
   */
  DMC_Soc_Lat_DWork.UD_DSTATE = rtb_fit4;

  /* Update for UnitDelay: '<S462>/Unit Delay3' incorporates:
   *  UnitDelay: '<S462>/Unit Delay1'
   */
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif =
    DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_d5fw;

  /* Update for UnitDelay: '<S475>/UD'
   *
   * Block description for '<S475>/UD':
   *
   *  Store in Global RAM
   */
  DMC_Soc_Lat_DWork.UD_DSTATE_eihf = rtb_n4jt;

  /* Update for UnitDelay: '<S462>/Unit Delay1' */
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_d5fw = (real32_T)rtb_kzp5;
}

/* Model initialize function */
void DMC_Soc_Lat_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) sde_memset(((void *) &DMC_Soc_Lat_B), 0,
                    sizeof(rtB_DMC_Soc_Lat_T));

  {
    DMC_Soc_Lat_B.In1 = 0.0F;
    DMC_Soc_Lat_B.DotProduct1 = 0.0F;
    DMC_Soc_Lat_B.MOT_Modulation_Torque_o2 = false;
  }

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Soc_Lat_DWork, 0,
                    sizeof(rtDW_DMC_Soc_Lat_T));
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE = 0.0;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jv3q = 0.0;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_h20c = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jfr0 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_jsby = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kyvd = 0.0F;
  DMC_Soc_Lat_DWork.Algloop1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Algloop_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Algloop2_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Algloop3_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Algloop4_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay22_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay23_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay12_DSTATE_hbpm = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d3m1 = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay17_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_g0mi = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cs0j = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator_DSTATE_cipt = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fq24 = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay5_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay3_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay18_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay4_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay10_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelayalgloop_DSTATE_kepf = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelayalgloop1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e43m = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay15_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay16_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay11_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay13_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dpkx = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay7_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay2_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hnnx = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_fo0b = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_jzb2 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_of4w = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bp0l = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_my50 = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay9_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay8_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay6_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kxew = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_a5ig = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_nsgx = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ljte = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_asff = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_kxgv = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b30u = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jijp = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_iji1 = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay21_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j5v2 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_ko35 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_mdsl = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_j1u3 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_i13z = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_ckqg = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_jaq2 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay4_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay5_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay6_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay7_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay8_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay9_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay10_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay11_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay12_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay13_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay14_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_b55e = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_d45l = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_jjfr = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dngv = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pmt4 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_hzxr = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay20_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_ddx5 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kcei = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_pfgp = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_dvws = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_lgsj = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kpna = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_am0s = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_l240 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_bvsy = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_erx0 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_drku = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hshs = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_aucg = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_e1bg = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_hrg2 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ffue = 0.0F;
  DMC_Soc_Lat_DWork.Alg_Loop_Delay14_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_nzhp = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_o534 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_gnzo = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_kho1 = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_hxjk = 0.0F;
  DMC_Soc_Lat_DWork.UD_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_btif = 0.0F;
  DMC_Soc_Lat_DWork.UD_DSTATE_eihf = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_d5fw = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.DiscreteTimeIntegrator2_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_olvg = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[0] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[1] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[2] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[3] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[4] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[5] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[6] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[7] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[8] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[9] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[10] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[11] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[12] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[13] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[14] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[15] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[16] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[17] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[18] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_idnp[19] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[0] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[1] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[2] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[3] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[4] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[5] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[6] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[7] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[8] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[9] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[10] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[11] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[12] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[13] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[14] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[15] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[16] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[17] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[18] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_n2lq[19] = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_iblc = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay2_DSTATE_c04i = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_c3jk = 0.0F;
  DMC_Soc_Lat_DWork.ResettableDelay1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.ResettableDelay2_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.ResettableDelay3_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay_DSTATE_buoy = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay1_DSTATE_b4na = 0.0F;
  DMC_Soc_Lat_DWork.UnitDelay3_DSTATE_ieks = 0.0F;
  DMC_Soc_Lat_DWork.Item_1_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Item_2_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Item_3_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Item_4_DSTATE = 0.0F;
  DMC_Soc_Lat_DWork.Item_5_DSTATE = 0.0F;

  /* Model Initialize fcn for ModelReference Block: '<Root>/LAT_Kappa_Filter' */
  DMC_Lat_LAT_Kappa_Filter_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S5>/LAT_Dmc_Status_Defintion3' */
  DMC_Lat_LAT_Dmc_Status_Defintion_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S5>/LAT_Kinematic_Signals_Arbiter' */
  DMC_Soc_Lat_LAT_Kinematic_Signals_Arbiter_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S17>/LAT_Delta_F_Offset_Switch' */
  DMC_Lat_LAT_Delta_F_Offset_Switch_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S34>/SAT_Angle_Command_Saturation' */
  DMC_Lat_SAT_Angle_Command_Saturation_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S35>/DYC_Dynamic_Compensation_Filter' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S35>/SAC_Damping_Filter' */
  DMC_Soc_Lat_SAC_Damping_Filter_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S35>/SAC_Yaw_Rate_Control' */
  DMC_Lat_SAC_Yaw_Rate_Control_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/LAT_Loop_Gain_Correction' */
  DMC_Soc_Lat_Loop_Gain_Correction_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/LAT_Stiffness_Definition' */
  DMC_Soc_Lat_LAT_Stiffness_Definition_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S43>/MOT_Modulation_Torque' */
  DMC_Soc_Lat_MOT_Modulation_Torque_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S43>/SAC_Friction_Compensation' */
  DMC_Lat_SAC_Friction_Compensation_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/SAC_Accuracy_Calculation' */
  DMC_Lat_SAC_Accuracy_Calculation_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/SAC_Angle_Command_Fading' */
  DMC_Lat_SAC_Angle_Command_Fading_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/SAC_Proportional_Factor_Derating' */
  DMC_Soc_Lat_SAC_Proportional_Factor_Derating_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/SAC_Steer_Angle_Cmd_Controller' */
  DMC_Soc_Lat_SAC_Steer_Angle_Cmd_Controller_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S29>/TDF_Torque_Derating_Function' */
  DMC_Lat_TDF_Torque_Derating_Function_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S17>/LAT_Ldp_States1' */
  DMC_Lat_LAT_Ldp_States_initialize
    (&(DMC_Soc_Lat_DWork.LAT_Ldp_States1_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S17>/LAT_Yaw_Rate_Offset_Compensation' */
  DMC_Soc_LAT_Yaw_Rate_Offset_Compensation_initialize();
  DMC_Soc_Lat_PrevZCSigState.LAT_Gi_Shift_Register_Trig_ZCE = POS_ZCSIG;
  DMC_Soc_Lat_PrevZCSigState.TriggeredSubsystem1_Trig_ZCE = POS_ZCSIG;
}
