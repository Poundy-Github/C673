/* $Header: DMC_Lat_TDF_Torque_Derating_Function.c 1.25 2020/08/20 10:43:20CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_TDF_Torque_Derating_Function.c
   C source code generated on           : Mon Aug 17 20:48:13 2020
   Filename of Simulink Model           : DMC_Lat_TDF_Torque_Derating_Function.mdl/.slx
   Revision of Simulink Model           : 1.442
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
#include "DMC_Lat_TDF_Torque_Derating_Function.h"
#include "DMC_Lat_TDF_Torque_Derating_Function_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: unsigned_int16_t Tdf_derating_mode, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_comp_filter_min_residual, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_err_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_error_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_error_sign_slope_2, [, ], 1  1,
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
   PARA: unsigned_int16_t Tdf_st_wheel_unbalance_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_comp_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_comp_thrs_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_sign_slope_2, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_ldp_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_slp_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Tdf_torque_derating_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_request_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_max_init_trq, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_slope_hf_path, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_threshold_dp, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_thrs_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_velocity_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_velocity_derating_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_derating_factor_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_comp_factor_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_min_compensation_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_trq_req_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_resd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_der_filt_coeff_hf, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_derating_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_der_falling_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_der_rising_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_derating_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_saturation_class_thr, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_slope_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_derating_thrs_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_load_comp_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_min_steer_trq_cls_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_ldp_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_slp_x_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Tdf_trq_derating_thrs_x_schedul, [, ], 1  11,
   PARA: signed_int16_t Tdf_min_steer_torque_class, [, ], 1  1,
   PARA: signed_int16_t Tdf_min_str_trq_class_handsoff, [, ], 1  1,
   PARA: signed_int16_t Tdf_toque_derating_slope, [, ], 1  1,
   CALL: DMC_Lat_TDF_Torque_Derating_Function_step()
   CALL: DMC_Lat_TDF_Torque_Derating_Function_initialize(0)
   FILE: DMC_Lat_TDF_Torque_Derating_Function.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_TDF_Torque_Derating_Function_T
  DMC_Lat_TDF_Torque_Derating_Function_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_TDF_Torque_Derating_Function' */
void DMC_Lat_TDF_Torque_Derating_Function_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S88>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S54>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_g1pc = 0.0F;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_gc34 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lcum = 0.0F;

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ppxw = 0.0F;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kyf0 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay1' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay1_DSTATE = (boolean_T)
    false;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql = 0.0F;

  /* InitializeConditions for MinMax: '<S70>/MinMax1' incorporates:
   *  InitializeConditions for UnitDelay: '<S1>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = 0.0F;

  /* InitializeConditions for UnitDelay: '<S67>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_f5gl = 0.0F;

  /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kgpf = 0.0F;

  /* InitializeConditions for UnitDelay: '<S65>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mubn = 0.0F;

  /* InitializeConditions for MinMax: '<S26>/MinMax1' incorporates:
   *  InitializeConditions for UnitDelay: '<S23>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q = 0.0F;

  /* InitializeConditions for UnitDelay: '<S80>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay'
   *
   * Block requirements for '<S22>/Unit Delay':
   *  1. Driver Override Factor
   *  2. Raw saturation derating factor
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hcxb = 0.0F;

  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ee10 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lkk5 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ciud = 0.0F;

  /* InitializeConditions for UnitDelay: '<S72>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_axa2 = 0.0F;

  /* InitializeConditions for MinMax: '<S86>/MinMax1' incorporates:
   *  InitializeConditions for UnitDelay: '<S84>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon = 0.0F;
}

/* Output and update for referenced model: 'DMC_Lat_TDF_Torque_Derating_Function' */
void DMC_Lat_TDF_Torque_Derating_Function(const real32_T *rt_erh2I, const
  real32_T *rt_gd42I, const real32_T *rt_cpaoI, const boolean_T *rt_e4hoI, const
  real32_T *rt_ngfdI, const boolean_T *rt_f3r3I, const real32_T *rt_kkebI, const
  boolean_T *rt_hny3I, const real32_T *rt_kwugI, const real32_T *rt_kafvI, const
  real32_T *rt_kaadI, const real32_T *rt_eltpI, const boolean_T *rt_cjpeI, const
  real32_T *rt_ezusI, const real32_T *rt_orb0I, const real32_T *rt_pdp2I, const
  real32_T *rt_dxdkI, const real32_T *rt_dmmuI, const boolean_T *rt_gyqsI, const
  real32_T *rt_m2jwI, const real32_T *rt_pdncI, const real32_T *rt_id5lI, const
  boolean_T *rt_prezI, real32_T *rt_erh2sI, real32_T *rt_gd42sI, real32_T
  *rt_cpaomI, boolean_T *rt_e4ho4I, boolean_T *rt_ngfdoI, real32_T *rt_f3r3lI,
  boolean_T *rt_kkeboI, real32_T *rt_hny3uI, real32_T *rt_kwuguI, real32_T
  *rt_kafvzI, real32_T *rt_kaadaI, real32_T *rt_eltpnI, real32_T *rt_cjpenI,
  real32_T *rt_ezus0I, real32_T *rt_orb0mI, real32_T *rt_pdp2qI)
{
  real32_T rtb_;
  real32_T rtb_orrf;
  real32_T rtb_ohrg;
  real32_T rtb_hvx3;
  real32_T rtb_g1gy;
  real32_T rtb_a1pd;
  real32_T rtb_fp5n;
  real32_T rtb_ilj4;
  boolean_T rtb_dx31;
  real32_T rtb_jb5x;
  real32_T rtb_deiy;
  real32_T rtb_nust;
  real32_T rtb_nbyh;
  boolean_T rtb_o35p;
  real32_T rtb_no2t;
  real32_T rtb_oihn;
  real32_T rtb_nmj5;
  int32_T rtb_lf5i;
  real32_T rtb_kiv2;
  real32_T rtb_cage;
  real32_T rtb_ag34;
  int16_T rtb_htvd;
  uint16_T rtb_nltx;
  real32_T tmp_;

  /* MinMax: '<S89>/MinMax' */
  if (5.0F <= (*rt_pdp2I)) {
    rtb_jb5x = 5.0F;
  } else {
    rtb_jb5x = *rt_pdp2I;
  }

  /* End of MinMax: '<S89>/MinMax' */

  /* MinMax: '<S89>/MinMax1' */
  if (-5.0F >= rtb_jb5x) {
    rtb_jb5x = -5.0F;
  }

  /* Sum: '<S88>/Add2' incorporates:
   *  Constant: '<S88>/Tdf_steer_trq_filter_coeff'
   *  Gain: '<S21>/Tdf_st_wheel_unbalance_factor'
   *  MinMax: '<S89>/MinMax1'
   *  Product: '<S88>/Product'
   *  Sum: '<S21>/Add'
   *  Sum: '<S88>/Add1'
   *  UnitDelay: '<S88>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE += ((((((real32_T)
    Tdf_st_wheel_unbalance_factor) * 0.0009765625F) * rtb_jb5x) + (*rt_gd42I)) -
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE) * (((real32_T)
    Tdf_steer_trq_filter_coeff) * 3.05175781E-5F);

  /* Abs: '<S21>/Abs' */
  rtb_ = (real32_T)fabs((real_T)
                        DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE);

  /* Lookup_n-D: '<S51>/TDF_Trq_Derating_Init_Corr' incorporates:
   *  Gain: '<S51>/Gain'
   */
  rtb_lf5i = look1_iflfIs32_binlc(3.6F * (*rt_ezusI),
    DMC_Lat_TDF_Torque_Derating_Function_ConstP.TDF_Trq_Derating_Init_Corr_bp01Data,
    DMC_Lat_TDF_Torque_Derating_Function_ConstP.TDF_Trq_Derating_Init_Corr_tableData,
    10U);

  /* MinMax: '<S51>/MinMax' incorporates:
   *  Constant: '<S51>/Tdf_trq_derating_max_init_trq'
   *  UnitDelay: '<S54>/Unit Delay'
   */
  rtb_nmj5 = ((real32_T)Tdf_trq_derating_max_init_trq) * 0.0009765625F;
  if (rtb_nmj5 <=
      DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_g1pc) {
  } else {
    rtb_nmj5 = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_g1pc;
  }

  /* End of MinMax: '<S51>/MinMax' */

  /* Sum: '<S51>/Add' */
  rtb_deiy = ((real32_T)rtb_lf5i) + rtb_nmj5;

  /* Abs: '<S63>/Abs' */
  rtb_jb5x = (real32_T)fabs((real_T)(*rt_orb0I));

  /* MinMax: '<S63>/MinMax' */
  if (0.004F <= rtb_jb5x) {
    rtb_jb5x = 0.004F;
  }

  /* Lookup_n-D: '<S63>/TDF_Derating_Curv_Thrs_Schedul' incorporates:
   *  MinMax: '<S63>/MinMax'
   */
  rtb_orrf = look1_iflf_binlc(rtb_jb5x,
    DMC_Lat_TDF_Torque_Derating_Function_ConstP.TDF_Derating_Curv_Thrs_Schedul_bp01Data,
    DMC_Lat_TDF_Torque_Derating_Function_ConstP.TDF_Derating_Curv_Thrs_Schedul_tableData,
    4U);

  /* Lookup_n-D: '<S63>/TDF_Derating_Thrs_Scheduling' incorporates:
   *  Gain: '<S63>/Gain'
   */
  rtb_ohrg = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_derating_thrs_x_scheduling[0])), (&(Tdf_derating_thrs_y_scheduling[0])),
    10U);

  /* Product: '<S63>/Product' */
  rtb_hvx3 = rtb_orrf * rtb_ohrg;

  /* Lookup_n-D: '<S15>/TDF_Trq_Derating_Thrs_Schedul' incorporates:
   *  Gain: '<S15>/Gain4'
   */
  rtb_ohrg = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_trq_derating_thrs_x_schedul[0])), (&(Tdf_trq_derating_thrs_y_schedul
    [0])), 10U);

  /* Product: '<S15>/Product' incorporates:
   *  Constant: '<S15>/Tdf_torque_derating_threshold'
   */
  rtb_orrf = rtb_ohrg * (((real32_T)Tdf_torque_derating_threshold) *
    0.0009765625F);

  /* MinMax: '<S15>/MinMax1' incorporates:
   *  Constant: '<S15>/Tdf_trq_derating_threshold_dp'
   */
  rtb_ohrg = ((real32_T)Tdf_trq_derating_threshold_dp) * 0.0009765625F;
  if (rtb_orrf >= rtb_ohrg) {
    rtb_ohrg = rtb_orrf;
  }

  /* End of MinMax: '<S15>/MinMax1' */

  /* MinMax: '<S9>/MinMax' incorporates:
   *  Constant: '<S9>/Tdf_min_steer_torque_class'
   *  Constant: '<S9>/Tdf_min_str_trq_class_handsoff'
   */
  if (Tdf_min_str_trq_class_handsoff >= Tdf_min_steer_torque_class) {
    rtb_htvd = Tdf_min_str_trq_class_handsoff;
  } else {
    rtb_htvd = Tdf_min_steer_torque_class;
  }

  /* End of MinMax: '<S9>/MinMax' */

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S9>/Tdf_min_steer_torque_class'
   */
  if ((int32_T)(*rt_gyqsI)) {
  } else {
    rtb_htvd = Tdf_min_steer_torque_class;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<Root>/Tdf_derating_mode'
   *  Constant: '<S9>/Tdf_min_steer_torque_class'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator'
   */
  if ((((int32_T)Tdf_derating_mode) & ((int32_T)32)) != ((int32_T)0)) {
  } else {
    rtb_htvd = Tdf_min_steer_torque_class;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Lookup_n-D: '<S9>/TDF_Min_Steer_Torque_Class_Sched' incorporates:
   *  Gain: '<S9>/Gain4'
   */
  rtb_a1pd = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_min_steer_trq_cls_x_schedul[0])), (&(Tdf_min_steer_trq_cls_y_schedul
    [0])), 10U);

  /* Product: '<S9>/Product2' */
  rtb_fp5n = (((real32_T)rtb_htvd) * 0.0009765625F) * rtb_a1pd;

  /* Lookup_n-D: '<S9>/TDF_Steer_Torque_Comp_Ldp_Sched' incorporates:
   *  Gain: '<S9>/Gain5'
   */
  rtb_a1pd = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_steer_trq_cmp_ldp_x_schedul[0])), (&(Tdf_steer_trq_cmp_ldp_y_schedul
    [0])), 10U);

  /* Product: '<S9>/Product8' incorporates:
   *  Constant: '<S9>/Tdf_steer_torque_comp_thrs_ldp'
   */
  rtb_jb5x = (((real32_T)Tdf_steer_torque_comp_thrs_ldp) * 0.0009765625F) *
    rtb_a1pd;

  /* MinMax: '<S27>/MinMax' */
  if (rtb_fp5n >= rtb_jb5x) {
    rtb_jb5x = rtb_fp5n;
  }

  /* Sum: '<S27>/Add5' incorporates:
   *  Constant: '<S27>/Constant10'
   *  MinMax: '<S27>/MinMax'
   *  Product: '<S27>/Product1'
   *  Product: '<S27>/Product2'
   *  Sum: '<S27>/Add6'
   */
  rtb_ilj4 = (rtb_jb5x * (*rt_m2jwI)) + (rtb_fp5n * (1.0F - (*rt_m2jwI)));

  /* Sum: '<S36>/Add' incorporates:
   *  Abs: '<S36>/Abs'
   */
  rtb_g1gy = ((real32_T)fabs((real_T)
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE)) - rtb_ilj4;

  /* Signum: '<S36>/Sign' */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE < 0.0F) {
    tmp_ = -1.0F;
  } else if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE > 0.0F)
  {
    tmp_ = 1.0F;
  } else {
    tmp_ = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE;
  }

  /* MinMax: '<S36>/MinMax' */
  if (0.0F >= rtb_g1gy) {
    rtb_g1gy = 0.0F;
  }

  /* Product: '<S36>/Product' incorporates:
   *  MinMax: '<S36>/MinMax'
   *  Signum: '<S36>/Sign'
   */
  rtb_fp5n = tmp_ * rtb_g1gy;

  /* Gain: '<S36>/Tdf_steer_torque_sign_slope' */
  rtb_a1pd = (((real32_T)Tdf_steer_torque_sign_slope) * 0.0009765625F) *
    rtb_fp5n;

  /* MinMax: '<S45>/MinMax1' */
  if (rtb_a1pd <= 1.0F) {
  } else {
    rtb_a1pd = 1.0F;
  }

  /* End of MinMax: '<S45>/MinMax1' */

  /* MinMax: '<S45>/MinMax2'
   *
   * Block requirements for '<S45>/MinMax2':
   *  1. Vehicle steer torque factor
   */
  if (rtb_a1pd >= -1.0F) {
  } else {
    rtb_a1pd = -1.0F;
  }

  *rt_orb0mI = rtb_a1pd;

  /* End of MinMax: '<S45>/MinMax2' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant2'
   *
   * Block requirements for '<S29>/Switch':
   *  1. LDP Lane Mode Selection
   */
  if ((int32_T)(*rt_cjpeI)) {
    rtb_a1pd = -1.0F;
  } else {
    rtb_a1pd = 1.0F;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Product: '<S9>/Product1' */
  rtb_a1pd *= *rt_orb0mI;

  /* MinMax: '<S9>/MinMax2' */
  if (rtb_a1pd >= 0.0F) {
  } else {
    rtb_a1pd = 0.0F;
  }

  /* End of MinMax: '<S9>/MinMax2' */

  /* Sum: '<S52>/Add' incorporates:
   *  Constant: '<S52>/Constant'
   *  Product: '<S52>/Product1'
   *  Product: '<S52>/Product2'
   *  Sum: '<S52>/Add1'
   */
  rtb_a1pd = (rtb_ohrg * rtb_a1pd) + (rtb_ohrg * (1.0F - rtb_a1pd));

  /* MinMax: '<S50>/MinMax' */
  if (rtb_orrf >= rtb_a1pd) {
    rtb_a1pd = rtb_orrf;
  }

  /* Product: '<S60>/Product3' incorporates:
   *  Constant: '<S50>/Constant10'
   *  MinMax: '<S50>/MinMax'
   *  Product: '<S50>/Product1'
   *  Product: '<S50>/Product2'
   *  Sum: '<S50>/Add5'
   *  Sum: '<S50>/Add6'
   */
  rtb_a1pd = rtb_hvx3 * ((rtb_a1pd * (*rt_m2jwI)) + (rtb_orrf * (1.0F -
    (*rt_m2jwI))));

  /* MinMax: '<S53>/MinMax1' */
  if (rtb_deiy >= rtb_a1pd) {
    rtb_a1pd = rtb_deiy;
  }

  /* Sum: '<S53>/Add' incorporates:
   *  MinMax: '<S53>/MinMax1'
   */
  rtb_a1pd = rtb_ - rtb_a1pd;

  /* MinMax: '<S53>/MinMax2' */
  if (rtb_a1pd >= 0.0F) {
  } else {
    rtb_a1pd = 0.0F;
  }

  /* End of MinMax: '<S53>/MinMax2' */

  /* Sum: '<S61>/Add2' incorporates:
   *  Constant: '<S61>/Tdf_steer_trq_resd_filter_coeff'
   *  Product: '<S61>/Product'
   *  Sum: '<S61>/Add1'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_gc34 += (rtb_a1pd
    - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_gc34) *
    (((real32_T)Tdf_steer_trq_resd_filter_coeff) * 3.05175781E-5F);

  /* Lookup_n-D: '<S59>/TDF_Derating_Slope_Scheduling' incorporates:
   *  Gain: '<S59>/Gain'
   */
  rtb_a1pd = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_derating_slope_x_scheduling[0])), (&(Tdf_derating_slope_y_scheduling
    [0])), 10U);

  /* Signum: '<S21>/Sign' */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE < 0.0F) {
    tmp_ = -1.0F;
  } else if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE > 0.0F)
  {
    tmp_ = 1.0F;
  } else {
    tmp_ = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE;
  }

  /* Product: '<S55>/Product2' incorporates:
   *  Constant: '<S59>/Tdf_toque_derating_slope'
   *  Product: '<S55>/Product'
   *  Product: '<S59>/Product3'
   *  Signum: '<S21>/Sign'
   */
  rtb_a1pd = (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_gc34 *
              (rtb_a1pd * (((real32_T)Tdf_toque_derating_slope) * 0.0009765625F)))
    * tmp_;

  /* MinMax: '<S55>/MinMax2' */
  if (0.0F >= rtb_a1pd) {
    rtb_jb5x = 0.0F;
  } else {
    rtb_jb5x = rtb_a1pd;
  }

  /* End of MinMax: '<S55>/MinMax2' */

  /* Sum: '<S39>/Add2' incorporates:
   *  Constant: '<S39>/Tdf_pac_trq_req_filter_coeff'
   *  Product: '<S39>/Product'
   *  Sum: '<S39>/Add1'
   *  UnitDelay: '<S39>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lcum +=
    ((*rt_dmmuI) -
     DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lcum) *
    (((real32_T)Tdf_pac_trq_req_filter_coeff) * 3.05175781E-5F);

  /* Gain: '<S32>/Tdf_pac_request_sign_slope' */
  rtb_g1gy = (((real32_T)Tdf_pac_request_sign_slope) * 0.0009765625F) *
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lcum;

  /* MinMax: '<S40>/MinMax1' */
  if (rtb_g1gy <= 1.0F) {
  } else {
    rtb_g1gy = 1.0F;
  }

  /* End of MinMax: '<S40>/MinMax1' */

  /* MinMax: '<S40>/MinMax2'
   *
   * Block requirements for '<S40>/MinMax2':
   *  1. Torque request factor
   */
  if (rtb_g1gy >= -1.0F) {
  } else {
    rtb_g1gy = -1.0F;
  }

  /* End of MinMax: '<S40>/MinMax2' */

  /* Logic: '<S55>/Logical Operator1' incorporates:
   *  Abs: '<S55>/Abs'
   *  Constant: '<S55>/Constant10'
   *  Constant: '<S55>/Constant13'
   *  Constant: '<S55>/Tdf_pac_request_sign_slope'
   *  Logic: '<S55>/Logical Operator'
   *  Logic: '<S55>/Logical Operator2'
   *  RelationalOperator: '<S55>/Relational Operator'
   *  RelationalOperator: '<S55>/Relational Operator1'
   */
  rtb_dx31 = (boolean_T)((int32_T)(((((real32_T)fabs((real_T)rtb_g1gy)) > 0.9F) &&
                           ((((real32_T)Tdf_pac_request_sign_slope) *
    0.0009765625F) > 0.1F)) && (!(*rt_prezI))));

  /* Switch: '<S55>/Switch1' incorporates:
   *  Constant: '<S55>/Constant12'
   *  Gain: '<S55>/Gain1'
   */
  if ((int32_T)rtb_dx31) {
    rtb_ohrg = -rtb_g1gy;
  } else {
    rtb_ohrg = 1.0F;
  }

  /* End of Switch: '<S55>/Switch1' */

  /* MinMax: '<S55>/MinMax3' */
  if (0.0F >= rtb_ohrg) {
    rtb_hvx3 = 0.0F;
  } else {
    rtb_hvx3 = rtb_ohrg;
  }

  /* End of MinMax: '<S55>/MinMax3' */

  /* Sum: '<S33>/Add' incorporates:
   *  ArithShift: '<S33>/Shift Arithmetic'
   *  Constant: '<Root>/Tdf_derating_mode'
   *  Constant: '<S33>/Constant1'
   *  S-Function (sfix_bitop): '<S33>/Bitwise Operator2'
   */
  rtb_ohrg = 1.0F + ((real32_T)((int32_T)((uint32_T)(((uint32_T)((int32_T)
    (((int32_T)Tdf_derating_mode) & ((int32_T)28)))) >> ((int8_T)2)))));

  /* MinMax: '<S33>/MinMax' */
  if (rtb_ohrg <= 6.0F) {
  } else {
    rtb_ohrg = 6.0F;
  }

  /* MultiPortSwitch: '<S33>/Multiport Switch' incorporates:
   *  Gain: '<S33>/Gain'
   *  MinMax: '<S33>/MinMax'
   */
  switch ((int32_T)rtb_ohrg) {
   case 1:
    rtb_ohrg = *rt_cpaoI;
    break;

   case 2:
    rtb_ohrg = *rt_dmmuI;
    break;

   case 3:
    rtb_ohrg = -DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE;
    break;

   case 4:
    rtb_ohrg = *rt_dxdkI;
    break;

   case 5:
    rtb_ohrg = *rt_pdncI;
    break;

   default:
    rtb_ohrg = *rt_id5lI;
    break;
  }

  /* End of MultiPortSwitch: '<S33>/Multiport Switch' */

  /* Product: '<S31>/Product' incorporates:
   *  Constant: '<S31>/Tdf_control_error_sign_slope'
   */
  rtb_orrf = rtb_ohrg * (((real32_T)Tdf_control_error_sign_slope) *
    0.0009765625F);

  /* MinMax: '<S38>/MinMax1' */
  if (rtb_orrf <= 1.0F) {
  } else {
    rtb_orrf = 1.0F;
  }

  /* End of MinMax: '<S38>/MinMax1' */

  /* MinMax: '<S38>/MinMax2'
   *
   * Block requirements for '<S38>/MinMax2':
   *  1. Torque request factor
   */
  if (rtb_orrf >= -1.0F) {
  } else {
    rtb_orrf = -1.0F;
  }

  /* End of MinMax: '<S38>/MinMax2' */

  /* Gain: '<S55>/Gain2' */
  rtb_a1pd = -rtb_a1pd;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/Constant11'
   */
  if ((int32_T)rtb_dx31) {
  } else {
    rtb_g1gy = 1.0F;
  }

  /* End of Switch: '<S55>/Switch' */

  /* MinMax: '<S55>/MinMax4' incorporates:
   *  Gain: '<S55>/Gain'
   */
  if (0.0F >= (-rtb_orrf)) {
    tmp_ = 0.0F;
  } else {
    tmp_ = -rtb_orrf;
  }

  /* MinMax: '<S55>/MinMax6' */
  if (0.0F >= rtb_orrf) {
    rtb_deiy = 0.0F;
  } else {
    rtb_deiy = rtb_orrf;
  }

  /* MinMax: '<S55>/MinMax5' */
  if (0.0F >= rtb_a1pd) {
    rtb_a1pd = 0.0F;
  }

  /* MinMax: '<S55>/MinMax7' */
  if (0.0F >= rtb_g1gy) {
    rtb_g1gy = 0.0F;
  }

  /* Sum: '<S55>/Add' incorporates:
   *  Constant: '<S55>/Constant1'
   *  MinMax: '<S55>/MinMax4'
   *  MinMax: '<S55>/MinMax5'
   *  MinMax: '<S55>/MinMax6'
   *  MinMax: '<S55>/MinMax7'
   *  Product: '<S55>/Product1'
   *  Product: '<S55>/Product3'
   *  Product: '<S55>/Product4'
   *  Product: '<S55>/Product5'
   *  Sum: '<S55>/Add1'
   */
  rtb_a1pd = 1.0F - (((rtb_jb5x * rtb_hvx3) * tmp_) + ((rtb_a1pd * rtb_g1gy) *
    rtb_deiy));

  /* MinMax: '<S55>/MinMax' */
  if (rtb_a1pd >= 0.0F) {
  } else {
    rtb_a1pd = 0.0F;
  }

  /* End of MinMax: '<S55>/MinMax' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  MinMax: '<S55>/MinMax1'
   */
  rtb_a1pd--;

  /* Constant: '<S6>/Tdf_derating_max_factor' */
  rtb_g1gy = ((real32_T)Tdf_derating_max_factor) * 0.0009765625F;

  /* Sum: '<S57>/Add' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/Tdf_trq_derating_slope_hf_path'
   *  Product: '<S57>/Product'
   */
  rtb_deiy = 1.0F -
    (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_gc34 *
     (((real32_T)Tdf_trq_derating_slope_hf_path) * 0.0009765625F));

  /* MinMax: '<S57>/MinMax' */
  if (rtb_deiy >= 0.0F) {
  } else {
    rtb_deiy = 0.0F;
  }

  /* End of MinMax: '<S57>/MinMax' */

  /* Sum: '<S41>/Add2' incorporates:
   *  Constant: '<S41>/Tdf_trq_filter_coeff'
   *  Product: '<S41>/Product'
   *  Sum: '<S41>/Add1'
   *  UnitDelay: '<S41>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ppxw += (rtb_ohrg
    - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ppxw) *
    (((real32_T)Tdf_trq_filter_coeff) * 3.05175781E-5F);

  /* Gain: '<S34>/Tdf_torque_request_sign_slope' */
  rtb_nbyh = (((real32_T)Tdf_torque_request_sign_slope) * 0.0009765625F) *
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ppxw;

  /* MinMax: '<S42>/MinMax1' */
  if (rtb_nbyh <= 1.0F) {
  } else {
    rtb_nbyh = 1.0F;
  }

  /* End of MinMax: '<S42>/MinMax1' */

  /* MinMax: '<S42>/MinMax2'
   *
   * Block requirements for '<S42>/MinMax2':
   *  1. Torque request factor
   */
  if (rtb_nbyh >= -1.0F) {
  } else {
    rtb_nbyh = -1.0F;
  }

  /* End of MinMax: '<S42>/MinMax2' */

  /* Product: '<S9>/Product3' */
  rtb_nust = rtb_nbyh * (*rt_orb0mI);

  /* RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  *rt_e4ho4I = (boolean_T)((int32_T)(rtb_nust <= -0.5F));

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if ((int32_T)(*rt_e4ho4I)) {
  } else {
    rtb_deiy = 1.0F;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_deiy--;

  /* RelationalOperator: '<S13>/Relational Operator' incorporates:
   *  Constant: '<S13>/Tdf_trq_min_derating_inc'
   *  Sum: '<S13>/Add'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  rtb_o35p = (boolean_T)((int32_T)(((*rt_m2jwI) -
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kyf0) >= 0.1F));

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  rtb_dx31 = (boolean_T)((int32_T)(((int32_T)rtb_o35p) || ((int32_T)
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay1_DSTATE)));

  /* Switch: '<S2>/Switch' */
  if ((int32_T)rtb_dx31) {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql = rtb_deiy;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Sum: '<S2>/Add2' */
  rtb_deiy -= DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql;

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S2>/Tdf_torque_der_filt_coeff_hf'
   *  Product: '<S2>/Product'
   */
  rtb_kiv2 = (rtb_deiy * (((real32_T)Tdf_torque_der_filt_coeff_hf) *
    3.05175781E-5F)) +
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql;

  /* Switch: '<S1>/Switch1' */
  if ((int32_T)rtb_dx31) {
    /* MinMax: '<S70>/MinMax1' */
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = rtb_a1pd;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Sum: '<S1>/Add2' */
  rtb_a1pd -= DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Constant: '<S1>/Tdf_torque_derating_filt_coeff'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql = ((real32_T)
    Tdf_torque_derating_filt_coeff) * 3.05175781E-5F;

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Tdf_out_scale_filt_min_residual'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  Gain: '<S1>/Gain'
   *  RelationalOperator: '<S1>/Relational Operator'
   */
  if (rtb_a1pd <= (-(((real32_T)Tdf_out_scale_filt_min_residual) * 0.0009765625F)))
  {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql = 1.0F;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Sum: '<S1>/Add3' incorporates:
   *  Product: '<S1>/Product'
   */
  rtb_cage = (rtb_a1pd *
              DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql)
    + DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut;

  /* Sum: '<S67>/Add' incorporates:
   *  UnitDelay: '<S67>/Unit Delay'
   *
   * Block requirements for '<S67>/Add':
   *  1. Saturated Angle Command Error
   *  2. Linear Velocity Derating Factor
   */
  rtb_a1pd = (*rt_kafvI) -
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_f5gl;

  /* MinMax: '<S70>/MinMax1' incorporates:
   *  Abs: '<S66>/Abs1'
   *  Abs: '<S66>/Abs2'
   *  Constant: '<S66>/Tdf_control_error_threshold'
   *  Gain: '<S70>/Tdf_control_err_derating_slope'
   *  Sum: '<S66>/Add'
   *  Sum: '<S66>/Add1'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = (((real32_T)
    fabs((real_T)(*rt_kwugI))) - ((real32_T)fabs((real_T)rtb_a1pd))) - 1.0F;
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut >= 0.0F)
  {
  } else {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = 0.0F;
  }

  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut *= ((real32_T)
    Tdf_control_err_derating_slope) * 0.0009765625F;

  /* MinMax: '<S70>/MinMax2' */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut <= 1.0F)
  {
  } else {
    /* MinMax: '<S70>/MinMax1' */
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = 1.0F;
  }

  /* End of MinMax: '<S70>/MinMax2' */

  /* Sum: '<S69>/Add1' incorporates:
   *  UnitDelay: '<S69>/Unit Delay'
   */
  rtb_deiy = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut -
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kgpf;

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Constant'
   *  Constant: '<S69>/Tdf_vel_der_falling_filt_coeff'
   *  Constant: '<S69>/Tdf_vel_der_rising_filt_coeff'
   *  RelationalOperator: '<S69>/Relational Operator'
   */
  if (rtb_deiy > 0.0F) {
    rtb_nltx = Tdf_vel_der_rising_filt_coeff;
  } else {
    rtb_nltx = Tdf_vel_der_falling_filt_coeff;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Sum: '<S69>/Add2' incorporates:
   *  Product: '<S69>/Product'
   *  UnitDelay: '<S69>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kgpf += rtb_deiy *
    (((real32_T)rtb_nltx) * 3.05175781E-5F);

  /* Sum: '<S68>/Add1' incorporates:
   *  Abs: '<S68>/Abs'
   *  Constant: '<S68>/Tdf_velocity_derating_threshold'
   */
  rtb_deiy = ((real32_T)fabs((real_T)(*rt_ngfdI))) - (((real32_T)
    Tdf_velocity_derating_threshold) * 0.0009765625F);

  /* MinMax: '<S68>/MinMax1' */
  if (rtb_deiy >= 0.0F) {
  } else {
    rtb_deiy = 0.0F;
  }

  /* MinMax: '<S70>/MinMax1' incorporates:
   *  Gain: '<S68>/Tdf_velocity_derating_slope'
   *  MinMax: '<S68>/MinMax1'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = (((real32_T)
    Tdf_velocity_derating_slope) * 0.0009765625F) * rtb_deiy;

  /* MinMax: '<S68>/MinMax3'
   *
   * Block requirements for '<S68>/MinMax3':
   *  1. Velocity Factor
   */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut <= 1.0F)
  {
  } else {
    /* MinMax: '<S70>/MinMax1' */
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = 1.0F;
  }

  /* End of MinMax: '<S68>/MinMax3' */

  /* MinMax: '<S16>/MinMax' incorporates:
   *  Constant: '<S66>/Constant'
   *  Constant: '<S68>/Constant2'
   *  Sum: '<S66>/Add2'
   *  Sum: '<S68>/Add2'
   *
   * Block requirements for '<S66>/Add2':
   *  1. Saturation derating factor
   *  2. Control Error Factor
   */
  if ((1.0F - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kgpf) >=
      (1.0F - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut))
  {
    tmp_ = 1.0F -
      DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kgpf;
  } else {
    tmp_ = 1.0F -
      DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut;
  }

  /* Sum: '<S65>/Add2' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S65>/Tdf_vel_derating_filt_coeff'
   *  MinMax: '<S16>/MinMax'
   *  Product: '<S65>/Product'
   *  Sum: '<S16>/Add1'
   *  Sum: '<S65>/Add1'
   *  UnitDelay: '<S65>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mubn += ((tmp_ -
    1.0F) - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mubn) *
    (((real32_T)Tdf_vel_derating_filt_coeff) * 3.05175781E-5F);

  /* Product: '<S6>/Product3' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S2>/Constant3'
   *  Product: '<S6>/Product1'
   *  Sum: '<S16>/Add2'
   *  Sum: '<S1>/Add4'
   *  Sum: '<S2>/Add4'
   *
   * Block requirements for '<S6>/Product3':
   *  1. Composite Derating factor
   *  2. Composite Derating Factor
   *  3. Composite Derating Factor
   */
  *rt_kafvzI = ((rtb_kiv2 + 1.0F) * (rtb_cage + 1.0F)) *
    (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mubn + 1.0F);

  /* Product: '<S6>/Product2' incorporates:
   *  UnitDelay: '<S23>/Unit Delay'
   *
   * Block requirements for '<S6>/Product2':
   *  1. Composite Derating factor
   *  2. Composite Derating Factor
   *  3. Composite Derating Factor
   */
  rtb_no2t = (*rt_kafvzI) *
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q;

  /* Constant: '<S6>/Tdf_derating_min_factor' */
  rtb_deiy = ((real32_T)Tdf_derating_min_factor) * 0.0009765625F;

  /* MinMax: '<S6>/MinMax' */
  if (rtb_no2t >= rtb_deiy) {
  } else {
    rtb_no2t = rtb_deiy;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* MinMax: '<S6>/MinMax1' */
  if (rtb_g1gy <= rtb_no2t) {
    rtb_hvx3 = rtb_g1gy;
  } else {
    rtb_hvx3 = rtb_no2t;
  }

  /* End of MinMax: '<S6>/MinMax1' */

  /* Saturate: '<S80>/Saturation' incorporates:
   *  UnitDelay: '<S80>/Unit Delay'
   */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse > 1.0F) {
    rtb_no2t = 1.0F;
  } else if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse <
             0.0F) {
    rtb_no2t = 0.0F;
  } else {
    rtb_no2t = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse;
  }

  /* End of Saturate: '<S80>/Saturation' */

  /* MinMax: '<S78>/MinMax1' */
  if (0.8F <= rtb_no2t) {
    rtb_g1gy = 0.8F;
  } else {
    rtb_g1gy = rtb_no2t;
  }

  /* End of MinMax: '<S78>/MinMax1' */

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<Root>/Tdf_derating_mode'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S87>/Constant'
   *  RelationalOperator: '<S87>/Compare'
   *  S-Function (sfix_bitop): '<S79>/Bitwise Operator'
   */
  if ((((int32_T)Tdf_derating_mode) & ((int32_T)1)) == ((int32_T)1)) {
    /* MinMax: '<S78>/MinMax2' */
    if (rtb_g1gy >= 0.0F) {
    } else {
      rtb_g1gy = 0.0F;
    }

    /* End of MinMax: '<S78>/MinMax2' */
  } else {
    rtb_g1gy = 0.0F;
  }

  /* End of Switch: '<S79>/Switch' */

  /* Sum: '<S19>/Add' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_g1gy = 1.0F - rtb_g1gy;

  /* Product: '<Root>/Product' */
  *rt_kwuguI = rtb_hvx3 * rtb_g1gy;

  /* Gain: '<Root>/Gain' */
  *rt_ezus0I = *rt_kwuguI;

  /* MinMax: '<S14>/MinMax1' incorporates:
   *  Constant: '<S14>/TDF_Sac_Integ_Derating_Thresh'
   *  Sum: '<S14>/Add1'
   */
  if ((rtb_ - 5.5F) >= 0.0F) {
    tmp_ = rtb_ - 5.5F;
  } else {
    tmp_ = 0.0F;
  }

  /* MinMax: '<S9>/MinMax1' */
  if (rtb_nust <= 0.0F) {
    rtb_deiy = rtb_nust;
  } else {
    rtb_deiy = 0.0F;
  }

  /* Sum: '<S14>/Add2' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Gain: '<S14>/TDF_Sac_Integ_Derating_Slope'
   *  Gain: '<S9>/Gain3'
   *  MinMax: '<S14>/MinMax1'
   *  MinMax: '<S9>/MinMax1'
   *  Product: '<S14>/Product'
   */
  rtb_deiy = 1.0F - (0.2F * (tmp_ * (-rtb_deiy)));

  /* MinMax: '<S14>/MinMax2' */
  if (rtb_deiy >= 0.0F) {
    rtb_hvx3 = rtb_deiy;
  } else {
    rtb_hvx3 = 0.0F;
  }

  /* End of MinMax: '<S14>/MinMax2' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if ((int32_T)(*rt_hny3I)) {
    rtb_deiy = *rt_kkebI;
  } else {
    rtb_deiy = 1.0F;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Product: '<S3>/Product1' incorporates:
   *  Product: '<S3>/Product'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  *rt_erh2sI = rtb_deiy *
    ((DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q *
      rtb_hvx3) * rtb_g1gy);

  /* Sum: '<S22>/Add2' incorporates:
   *  Constant: '<S22>/LAT_Sat_Forgetting_Factor'
   *  UnitDelay: '<S22>/Unit Delay'
   *
   * Block requirements for '<S22>/Unit Delay':
   *  1. Driver Override Factor
   *  2. Raw saturation derating factor
   */
  rtb_oihn = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hcxb -
    0.002F;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/LAT_Sat_Class_Weighting'
   *  Constant: '<S22>/LAT_Sat_Forgetting_Factor'
   *  Sum: '<S22>/Add1'
   *  Sum: '<S22>/Add2'
   *  UnitDelay: '<S22>/Unit Delay'
   *
   * Block requirements for '<S22>/Unit Delay':
   *  1. Driver Override Factor
   *  2. Raw saturation derating factor
   */
  if ((int32_T)(*rt_e4hoI)) {
    rtb_oihn = 0.25F +
      (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hcxb - 0.002F);
  }

  /* End of Switch: '<S22>/Switch' */

  /* MinMax: '<S24>/MinMax1' */
  if (rtb_oihn <= 1.0F) {
  } else {
    rtb_oihn = 1.0F;
  }

  /* End of MinMax: '<S24>/MinMax1' */

  /* MinMax: '<S24>/MinMax2' */
  if (0.0F >= rtb_oihn) {
    rtb_ag34 = 0.0F;
  } else {
    rtb_ag34 = rtb_oihn;
  }

  /* End of MinMax: '<S24>/MinMax2' */

  /* Sum: '<S23>/Add1' incorporates:
   *  Constant: '<S23>/Lat_saturation_class_thr'
   *  UnitDelay: '<S22>/Unit Delay'
   *
   * Block requirements for '<S22>/Unit Delay':
   *  1. Driver Override Factor
   *  2. Raw saturation derating factor
   */
  rtb_oihn = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hcxb -
    (((real32_T)Lat_saturation_class_thr) * 0.000244140625F);

  /* MinMax: '<S23>/MinMax' */
  if (0.0F >= rtb_oihn) {
    rtb_oihn = 0.0F;
  }

  /* End of MinMax: '<S23>/MinMax' */

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/Lat_derating_factor_filt_coeff'
   *  Gain: '<S23>/Gain'
   *  Product: '<S25>/Product'
   *  Sum: '<S25>/Add1'
   *  UnitDelay: '<S25>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ee10 += ((2.0F *
    rtb_oihn) - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ee10)
    * (((real32_T)Lat_derating_factor_filt_coeff) * 3.05175781E-5F);

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  *rt_kkeboI = (boolean_T)((int32_T)((*rt_kwuguI) < 0.99F));

  /* Lookup_n-D: '<S75>/TDF_Load_Comp_Scheduling' incorporates:
   *  Gain: '<S75>/Gain'
   */
  rtb_oihn = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_load_comp_x_scheduling[0])), (&(Tdf_load_comp_y_scheduling[0])), 10U);

  /* Sum: '<S74>/Subtract1' incorporates:
   *  Constant: '<S74>/Tdf_load_comp_start'
   */
  rtb_hvx3 = (*rt_kaadI) - (((real32_T)Tdf_load_comp_start) * 0.0009765625F);

  /* MinMax: '<S74>/MinMax1' */
  if (rtb_hvx3 >= 0.0F) {
  } else {
    rtb_hvx3 = 0.0F;
  }

  /* DataTypeConversion: '<S74>/Data Type Conversion' incorporates:
   *  Constant: '<S74>/Tdf_load_comp_end'
   *  Constant: '<S74>/Tdf_load_comp_start'
   *  Sum: '<S74>/Subtract2'
   */
  rtb_jb5x = ((real32_T)((uint16_T)(Tdf_load_comp_end - Tdf_load_comp_start))) *
    0.0009765625F;

  /* MinMax: '<S74>/MinMax2' */
  if (rtb_jb5x >= 0.1F) {
  } else {
    rtb_jb5x = 0.1F;
  }

  /* Product: '<S74>/Product' incorporates:
   *  Constant: '<S74>/Constant2'
   *  MinMax: '<S74>/MinMax1'
   *  MinMax: '<S74>/MinMax2'
   *  Product: '<S74>/Divide'
   */
  rtb_hvx3 *= 1.0F / rtb_jb5x;

  /* MinMax: '<S74>/MinMax' */
  if (rtb_hvx3 <= 1.0F) {
  } else {
    rtb_hvx3 = 1.0F;
  }

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S75>/Constant'
   *  Constant: '<S75>/Tdf_min_compensation_factor'
   *  MinMax: '<S74>/MinMax'
   *  Product: '<S75>/Product'
   *  Product: '<S75>/Product1'
   *  Sum: '<S75>/Add'
   *  Sum: '<S75>/Add1'
   *  UnitDelay: '<S23>/Unit Delay'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  *rt_cpaomI = (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q
                * ((((rtb_hvx3 * (((real32_T)Tdf_min_compensation_factor) *
    3.05175781E-5F)) * rtb_oihn) *
                    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lkk5)
                   + (1.0F -
                      DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lkk5)))
    * rtb_g1gy;

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  TDF_Sac_Dos_Limit_Scale_dbg = (uint16_T)((real32_T)((*rt_cpaomI) * 1024.0F));

  /* Lookup_n-D: '<S35>/TDF_Steer_Trq_Comp_Slope_Sched' incorporates:
   *  Gain: '<S35>/Gain'
   */
  rtb_oihn = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ezusI),
    (&(Tdf_steer_trq_cmp_slp_x_schedul[0])), (&(Tdf_steer_trq_cmp_slp_y_schedul
    [0])), 11U);

  /* Sum: '<S35>/Add' incorporates:
   *  Abs: '<S35>/Abs'
   */
  rtb_deiy = ((real32_T)fabs((real_T)
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE)) - rtb_ilj4;

  /* Signum: '<S35>/Sign' */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE < 0.0F) {
    tmp_ = -1.0F;
  } else if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE > 0.0F)
  {
    tmp_ = 1.0F;
  } else {
    tmp_ = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE;
  }

  /* MinMax: '<S35>/MinMax' */
  if (0.0F >= rtb_deiy) {
    rtb_deiy = 0.0F;
  }

  /* Product: '<S35>/Product3' incorporates:
   *  Constant: '<S35>/Tdf_steer_torque_comp_slope'
   *  MinMax: '<S35>/MinMax'
   *  Product: '<S35>/Product1'
   *  Product: '<S35>/Product2'
   *  Signum: '<S35>/Sign'
   */
  rtb_oihn *= (tmp_ * rtb_deiy) * (((real32_T)Tdf_steer_torque_comp_slope) *
    0.0009765625F);

  /* MinMax: '<S44>/MinMax1' */
  if (rtb_oihn <= 1.0F) {
  } else {
    rtb_oihn = 1.0F;
  }

  /* End of MinMax: '<S44>/MinMax1' */

  /* MinMax: '<S44>/MinMax2'
   *
   * Block requirements for '<S44>/MinMax2':
   *  1. Vehicle Steer Torque Compensation Factor
   */
  if (rtb_oihn >= -1.0F) {
  } else {
    rtb_oihn = -1.0F;
  }

  /* Product: '<S9>/Product5' incorporates:
   *  MinMax: '<S44>/MinMax2'
   *
   * Block requirements for '<S44>/MinMax2':
   *  1. Vehicle Steer Torque Compensation Factor
   */
  rtb_nbyh *= rtb_oihn;

  /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
   *  Constant: '<S9>/Constant2'
   */
  *rt_ngfdoI = (boolean_T)((int32_T)(rtb_nust >= 0.5F));

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S30>/Tdf_control_error_sign_slope_2'
   */
  rtb_oihn = rtb_ohrg * (((real32_T)Tdf_control_error_sign_slope_2) *
    0.0009765625F);

  /* MinMax: '<S37>/MinMax1' */
  if (rtb_oihn <= 1.0F) {
  } else {
    rtb_oihn = 1.0F;
  }

  /* End of MinMax: '<S37>/MinMax1' */

  /* MinMax: '<S37>/MinMax2'
   *
   * Block requirements for '<S37>/MinMax2':
   *  1. Torque request factor
   */
  if (rtb_oihn >= -1.0F) {
  } else {
    rtb_oihn = -1.0F;
  }

  *rt_eltpnI = rtb_oihn;

  /* End of MinMax: '<S37>/MinMax2' */

  /* Gain: '<S36>/Tdf_steer_torque_sign_slope_2' */
  rtb_fp5n *= ((real32_T)Tdf_steer_torque_sign_slope_2) * 0.0009765625F;

  /* MinMax: '<S46>/MinMax1' */
  if (rtb_fp5n <= 1.0F) {
  } else {
    rtb_fp5n = 1.0F;
  }

  /* End of MinMax: '<S46>/MinMax1' */

  /* MinMax: '<S46>/MinMax2'
   *
   * Block requirements for '<S46>/MinMax2':
   *  1. Vehicle steer torque factor
   */
  if (rtb_fp5n >= -1.0F) {
  } else {
    rtb_fp5n = -1.0F;
  }

  *rt_kaadaI = rtb_fp5n;

  /* End of MinMax: '<S46>/MinMax2' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  SAC_Trq_Derating_Factor_dbg = (uint16_T)((real32_T)((*rt_kwuguI) * 1024.0F));

  /* Product: '<S10>/Product' */
  rtb_jb5x = (*rt_cpaoI) * (*rt_kwuguI);

  /* Sum: '<S47>/Add2' incorporates:
   *  Constant: '<S47>/LAT_Eps_Torque_Filter_Coeff'
   *  Product: '<S47>/Product'
   *  Sum: '<S47>/Add1'
   *  UnitDelay: '<S47>/Unit Delay'
   */
  *rt_f3r3lI = ((rtb_jb5x -
                 DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ciud)
                * 0.999F) +
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ciud;

  /* Product: '<S11>/Product' */
  *rt_hny3uI = (*rt_kwuguI) * (*rt_eltpI);

  /* DataTypeConversion: '<S51>/Data Type Conversion' */
  TDF_Steer_Torque_Sample_dbg = (int16_T)((real32_T)floor(rtb_nmj5 / 0.001F));

  /* Switch: '<S54>/Switch2' */
  if ((int32_T)(*rt_e4ho4I)) {
  } else {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_g1pc = rtb_;
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Gain: '<S67>/Tdf_sac_pritaty_omega' */
  rtb_a1pd *= 7.0F;

  /* MinMax: '<S71>/MinMax1' */
  if (rtb_a1pd <= 2.0F) {
  } else {
    rtb_a1pd = 2.0F;
  }

  /* End of MinMax: '<S71>/MinMax1' */

  /* MinMax: '<S70>/MinMax1' incorporates:
   *  Sum: '<S72>/Add1'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut -=
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_axa2;

  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S72>/Tdf_vel_der_falling_filt_coeff'
   *  Constant: '<S72>/Tdf_vel_der_rising_filt_coeff'
   *  RelationalOperator: '<S72>/Relational Operator'
   */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut > 0.0F) {
    rtb_nltx = Tdf_vel_der_rising_filt_coeff;
  } else {
    rtb_nltx = Tdf_vel_der_falling_filt_coeff;
  }

  /* End of Switch: '<S72>/Switch' */

  /* Sum: '<S72>/Add2' incorporates:
   *  Product: '<S72>/Product'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  *rt_cjpenI = (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut
                * (((real32_T)rtb_nltx) * 3.05175781E-5F)) +
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_axa2;

  /* MinMax: '<S9>/MinMax3' */
  if (rtb_nbyh <= 0.0F) {
  } else {
    rtb_nbyh = 0.0F;
  }

  /* Sum: '<S73>/Add1' incorporates:
   *  Gain: '<S9>/Gain2'
   *  MinMax: '<S9>/MinMax3'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  rtb_oihn = (-rtb_nbyh) -
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lkk5;

  /* DataTypeConversion: '<S73>/Data Type Conversion2' incorporates:
   *  Constant: '<S73>/Tdf_comp_factor_filter_coeff'
   */
  rtb_deiy = ((real32_T)Tdf_comp_factor_filter_coeff) * 3.05175781E-5F;

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Constant'
   *  Constant: '<S73>/Tdf_comp_filter_min_residual'
   *  DataTypeConversion: '<S73>/Data Type Conversion1'
   *  RelationalOperator: '<S73>/Relational Operator'
   */
  if (rtb_oihn >= (((real32_T)Tdf_comp_filter_min_residual) * 0.0009765625F)) {
    rtb_deiy = 1.0F;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Product: '<S73>/Product' */
  rtb_jb5x = rtb_oihn * rtb_deiy;

  /* Abs: '<S18>/Abs' */
  rtb_hvx3 = (real32_T)fabs((real_T)(*rt_orb0mI));

  /* Product: '<S18>/Product2' incorporates:
   *  Constant: '<S18>/Constant'
   *  Product: '<S18>/Product1'
   *  Sum: '<S18>/Add'
   */
  *rt_gd42sI = (1.0F - rtb_hvx3) * (rtb_g1gy * (*rt_erh2I));

  /* MinMax: '<S86>/MinMax1' incorporates:
   *  UnitDelay: '<S84>/Unit Delay'
   */
  if (0.3F <= DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon)
  {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon = 0.3F;
  }

  /* End of MinMax: '<S86>/MinMax1' */

  /* MinMax: '<S86>/MinMax2' */
  if (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon >= 0.0F)
  {
    rtb_hvx3 = DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon;
  } else {
    rtb_hvx3 = 0.0F;
  }

  /* End of MinMax: '<S86>/MinMax2' */

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S81>/Constant1'
   *  Constant: '<S81>/Constant2'
   *  Constant: '<S86>/TDF_Derating_Switch_Min_Time'
   *  RelationalOperator: '<S84>/Relational Operator'
   */
  if (rtb_hvx3 >= 0.3F) {
    rtb_oihn = 1.0F;
  } else {
    rtb_oihn = 0.0F;
  }

  /* End of Switch: '<S81>/Switch' */

  /* Sum: '<S80>/Sum' */
  rtb_oihn -= rtb_no2t;

  /* Signum: '<S83>/Sign' */
  if (rtb_oihn < 0.0F) {
    rtb_deiy = -1.0F;
  } else if (rtb_oihn > 0.0F) {
    rtb_deiy = 1.0F;
  } else {
    rtb_deiy = rtb_oihn;
  }

  /* End of Signum: '<S83>/Sign' */

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S82>/Constant'
   *  Gain: '<S83>/Gain'
   *  Sum: '<S80>/IntegSum'
   */
  if ((int32_T)(*rt_f3r3I)) {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse = 0.0F;
  } else {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse =
      ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_deiy) + rtb_no2t;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Switch: '<S85>/Switch1' incorporates:
   *  Constant: '<S85>/Constant1'
   *  Constant: '<S85>/Constant2'
   *  Constant: '<S85>/TDF_Derating_Switch_Thresh1'
   *  RelationalOperator: '<S85>/RelOp2'
   */
  if (rtb_ > 3.0F) {
    rtb_oihn = 1.0F;
  } else {
    rtb_oihn = -1.0F;
  }

  /* End of Switch: '<S85>/Switch1' */

  /* Switch: '<S85>/Switch2' incorporates:
   *  Constant: '<S85>/Constant1'
   *  Constant: '<S85>/TDF_Derating_Switch_Thresh2'
   *  RelationalOperator: '<S85>/RelOp1'
   *  Sum: '<S85>/Add2'
   *
   * Block requirements for '<S85>/Switch2':
   *  1. State Derating
   */
  if (rtb_ > 5.0F) {
    rtb_oihn = (rtb_ - 5.0F) + 1.0F;
  }

  /* End of Switch: '<S85>/Switch2' */

  /* Product: '<S20>/Product2' */
  rtb_orrf *= *rt_orb0mI;

  /* MinMax: '<S20>/MinMax8' */
  if (rtb_orrf >= 0.0F) {
  } else {
    rtb_orrf = 0.0F;
  }

  *rt_pdp2qI = rtb_orrf;

  /* End of MinMax: '<S20>/MinMax8' */

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  VEH_Steer_Torque_Comp_dbg = (int16_T)((real32_T)floor
    (DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE * 1024.0F));

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kyf0 = *rt_m2jwI;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay1_DSTATE = rtb_o35p;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql = rtb_kiv2;

  /* Update for MinMax: '<S70>/MinMax1' incorporates:
   *  Update for UnitDelay: '<S1>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = rtb_cage;

  /* MinMax: '<S71>/MinMax2' */
  if (rtb_a1pd >= -2.0F) {
  } else {
    rtb_a1pd = -2.0F;
  }

  /* Update for UnitDelay: '<S67>/Unit Delay' incorporates:
   *  Gain: '<S67>/Gain'
   *  MinMax: '<S71>/MinMax2'
   *  Sum: '<S67>/Sum'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_f5gl +=
    (((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_a1pd;

  /* MinMax: '<S26>/MinMax1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Sum: '<S23>/Add2'
   */
  if ((1.0F - DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ee10) <=
      1.0F) {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q = 1.0F -
      DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ee10;
  } else {
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q = 1.0F;
  }

  /* MinMax: '<S26>/MinMax2' */
  if (0.0F >= DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q)
  {
    /* MinMax: '<S26>/MinMax1' incorporates:
     *  Update for UnitDelay: '<S23>/Unit Delay'
     */
    DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q = 0.0F;
  }

  /* End of MinMax: '<S26>/MinMax2' */

  /* Update for UnitDelay: '<S22>/Unit Delay'
   *
   * Block requirements for '<S22>/Unit Delay':
   *  1. Driver Override Factor
   *  2. Raw saturation derating factor
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hcxb = rtb_ag34;

  /* Update for UnitDelay: '<S73>/Unit Delay' incorporates:
   *  Sum: '<S73>/Add'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lkk5 += rtb_jb5x;

  /* Update for UnitDelay: '<S47>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ciud = *rt_f3r3lI;

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_axa2 = *rt_cjpenI;

  /* Update for MinMax: '<S86>/MinMax1' incorporates:
   *  Gain: '<S84>/Gain'
   *  Sum: '<S84>/Add'
   *  Update for UnitDelay: '<S84>/Unit Delay'
   */
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon =
    ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_oihn) + rtb_hvx3;
}

/* Model initialize function */
void DMC_Lat_TDF_Torque_Derating_Function_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Lat_TDF_Torque_Derating_Function_DWork, 0,
                    sizeof(rtDW_DMC_Lat_TDF_Torque_Derating_Function_T));
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_g1pc = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_gc34 = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lcum = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ppxw = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kyf0 = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hvql = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_izut = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_f5gl = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_kgpf = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mubn = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_pl4q = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mnse = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_hcxb = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ee10 = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_lkk5 = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_ciud = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_axa2 = 0.0F;
  DMC_Lat_TDF_Torque_Derating_Function_DWork.UnitDelay_DSTATE_mkon = 0.0F;
}
