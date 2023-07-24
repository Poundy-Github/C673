/* $Header: DMC_Lat_SAC_Accuracy_Calculation.c 1.24 2020/08/20 10:43:04CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_SAC_Accuracy_Calculation.c
   C source code generated on           : Mon Aug 17 20:47:22 2020
   Filename of Simulink Model           : DMC_Lat_SAC_Accuracy_Calculation.mdl/.slx
   Revision of Simulink Model           : 1.2
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
#include "DMC_Lat_SAC_Accuracy_Calculation.h"
#include "DMC_Lat_SAC_Accuracy_Calculation_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: unsigned_int16_t Lco_min_curvature_dot_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_curvature_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_filter_fall_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_filter_risng_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_error_filter_falling_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_error_filter_rising_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_filter_falling_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_filter_rising_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_preload_enh_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_control_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_err_preload_enh_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_lateral_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_load_comp_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_preload_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_comp_factor_y_scheduling, [, ], 1  13,
   PARA: signed_int16_t Lco_min_curvature_command, [, ], 1  1,
   PARA: signed_int16_t Lco_min_curvature_dot, [, ], 1  1,
   PARA: signed_int16_t Sac_load_compensation_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_comp_factor_x_scheduling, [, ], 1  13,
   CALL: DMC_Lat_SAC_Accuracy_Calculation_step()
   CALL: DMC_Lat_SAC_Accuracy_Calculation_initialize(0)
   FILE: DMC_Lat_SAC_Accuracy_Calculation.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_SAC_Accuracy_Calculation_T DMC_Lat_SAC_Accuracy_Calculation_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_SAC_Accuracy_Calculation' */
void DMC_Lat_SAC_Accuracy_Calculation_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_ghok = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_nrkb = 0.0F;
}

/* Output and update for referenced model: 'DMC_Lat_SAC_Accuracy_Calculation' */
void DMC_Lat_SAC_Accuracy_Calculation(const real32_T *rt_erh2I, const real32_T
  *rt_gd42I, const real32_T *rt_cpaoI, const boolean_T *rt_e4hoI, const real32_T
  *rt_ngfdI, const real32_T *rt_f3r3I, const boolean_T *rt_kkebI, const real32_T
  *rt_hny3I, const real32_T *rt_kwugI, real32_T *rt_erh2sI, real32_T *rt_gd42sI,
  real32_T *rt_cpaomI, real32_T *rt_e4ho4I)
{
  real32_T rtb_;
  real32_T rtb_gedj;
  real32_T rtb_gjqx;
  real32_T rtb_kln3;
  real32_T rtb_m2kd;
  real32_T rtb_fsun;
  real32_T rtb_dxut;

  /* Sum: '<S10>/Add' incorporates:
   *  Abs: '<S10>/Abs'
   *  Constant: '<S10>/Lco_min_curvature_command'
   */
  rtb_gjqx = ((real32_T)fabs((real_T)(*rt_cpaoI))) - (((real32_T)
    Lco_min_curvature_command) * 2.0E-5F);

  /* Sum: '<S10>/Add1' incorporates:
   *  Abs: '<S10>/Abs1'
   *  Constant: '<S10>/Lco_min_curvature_command'
   */
  rtb_gedj = ((real32_T)fabs((real_T)(*rt_hny3I))) - (((real32_T)
    Lco_min_curvature_command) * 2.0E-5F);

  /* MinMax: '<S10>/MinMax1' */
  if (rtb_gjqx >= rtb_gedj) {
  } else {
    rtb_gjqx = rtb_gedj;
  }

  /* End of MinMax: '<S10>/MinMax1' */

  /* MinMax: '<S10>/MinMax3' */
  if (0.0F >= rtb_gjqx) {
    rtb_gjqx = 0.0F;
  }

  /* Gain: '<S10>/Lco_min_curvature_slope' incorporates:
   *  MinMax: '<S10>/MinMax3'
   */
  rtb_gedj = ((real32_T)Lco_min_curvature_slope) * rtb_gjqx;

  /* MinMax: '<S10>/MinMax2'
   *
   * Block requirements for '<S10>/MinMax2':
   *  1. Minimum Curvature Command
   */
  if (rtb_gedj <= 1.0F) {
  } else {
    rtb_gedj = 1.0F;
  }

  /* End of MinMax: '<S10>/MinMax2' */

  /* Sum: '<S11>/Add1' incorporates:
   *  Gain: '<S9>/Lco_preload_enhancement_factor'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  rtb_gjqx = ((((real32_T)Lco_preload_enhancement_factor) * 0.0009765625F) *
              rtb_gedj) -
    DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE;

  /* Constant: '<S11>/Lco_filter_rising_coeff' */
  rtb_ = ((real32_T)Lco_filter_rising_coeff) * 3.05175781E-5F;

  /* Switch: '<S11>/Switch5' incorporates:
   *  Constant: '<S11>/Lco_filter_falling_coeff '
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   */
  if (rtb_gjqx >= 0.0F) {
  } else {
    rtb_ = ((real32_T)Lco_filter_falling_coeff) * 3.05175781E-5F;
  }

  /* End of Switch: '<S11>/Switch5' */

  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE += rtb_gjqx * rtb_;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Logic: '<S8>/LogOp1'
   *
   * Block requirements for '<S8>/Switch':
   *  1. Fading Signal Selection
   */
  if (!(*rt_e4hoI)) {
    rtb_kln3 = DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE;
  } else {
    rtb_kln3 = 1.0F;
  }

  /* End of Switch: '<S8>/Switch' */

  /* MinMax: '<S8>/MinMax' */
  if (1.0F <= rtb_kln3) {
    rtb_kln3 = 1.0F;
  }

  /* End of MinMax: '<S8>/MinMax' */

  /* Sum: '<S15>/Add' incorporates:
   *  Abs: '<S15>/Abs'
   *  Constant: '<S15>/Lco_min_curvature_dot'
   */
  rtb_ = ((real32_T)fabs((real_T)(*rt_kwugI))) - (((real32_T)
    Lco_min_curvature_dot) * 2.0E-5F);

  /* MinMax: '<S15>/MinMax1' */
  if (0.0F >= rtb_) {
    rtb_ = 0.0F;
  }

  /* Gain: '<S15>/Lco_min_curvature_dot_slope' incorporates:
   *  MinMax: '<S15>/MinMax1'
   */
  rtb_gedj = ((real32_T)Lco_min_curvature_dot_slope) * rtb_;

  /* MinMax: '<S15>/MinMax2'
   *
   * Block requirements for '<S15>/MinMax2':
   *  1. Minimum Lateral Error
   */
  if (rtb_gedj <= 1.0F) {
  } else {
    rtb_gedj = 1.0F;
  }

  /* End of MinMax: '<S15>/MinMax2' */

  /* Sum: '<S16>/Add1' incorporates:
   *  Gain: '<S14>/Lco_curv_dot_preload_enh_factor'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  rtb_gjqx = ((((real32_T)Lco_curv_dot_preload_enh_factor) * 0.0009765625F) *
              rtb_gedj) -
    DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_ghok;

  /* Constant: '<S16>/Lco_curv_dot_filter_risng_coeff' */
  rtb_ = ((real32_T)Lco_curv_dot_filter_risng_coeff) * 3.05175781E-5F;

  /* Switch: '<S16>/Switch5' incorporates:
   *  Constant: '<S16>/Lco_curv_dot_filter_fall_coeff '
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   */
  if (rtb_gjqx >= 0.0F) {
  } else {
    rtb_ = ((real32_T)Lco_curv_dot_filter_fall_coeff) * 3.05175781E-5F;
  }

  /* End of Switch: '<S16>/Switch5' */

  /* Sum: '<S16>/Add' incorporates:
   *  Product: '<S16>/Product'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_ghok += rtb_gjqx *
    rtb_;

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *
   * Block requirements for '<S13>/Switch':
   *  1. Fading Signal Error Selection
   */
  if ((int32_T)(*rt_e4hoI)) {
    rtb_m2kd = 1.0F;
  } else {
    rtb_m2kd = DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_ghok;
  }

  /* End of Switch: '<S13>/Switch' */

  /* MinMax: '<S13>/MinMax1' */
  if (1.0F <= rtb_m2kd) {
    rtb_m2kd = 1.0F;
  }

  /* End of MinMax: '<S13>/MinMax1' */

  /* Lookup_n-D: '<S6>/SAC_Load_Comp_Factor_Scheduling' incorporates:
   *  Gain: '<S6>/Gain'
   */
  rtb_gedj = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_gd42I),
    (&(Sac_comp_factor_x_scheduling[0])), (&(Sac_comp_factor_y_scheduling[0])),
    12U);

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S6>/Sac_load_compensation_factor'
   */
  rtb_gjqx = (((real32_T)Sac_load_compensation_factor) * 0.0009765625F) *
    rtb_gedj;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  *rt_cpaomI = rtb_gjqx;

  /* MinMax: '<S5>/MinMax1' */
  if (0.0F >= (*rt_erh2I)) {
    rtb_gedj = 0.0F;
  } else {
    rtb_gedj = *rt_erh2I;
  }

  /* End of MinMax: '<S5>/MinMax1' */

  /* MinMax: '<S5>/MinMax2' */
  if (1.0F <= rtb_gedj) {
    rtb_dxut = 1.0F;
  } else {
    rtb_dxut = rtb_gedj;
  }

  /* End of MinMax: '<S5>/MinMax2' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   */
  if ((int32_T)(*rt_kkebI)) {
    rtb_gedj = 1.0F;
  } else {
    rtb_gedj = 0.0F;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Sum: '<S21>/Add' incorporates:
   *  Abs: '<S21>/Abs'
   *  Constant: '<S21>/Lco_min_lateral_error'
   */
  rtb_ = ((real32_T)fabs((real_T)(*rt_ngfdI))) - (((real32_T)
    Lco_min_lateral_error) * 0.0009765625F);

  /* MinMax: '<S21>/MinMax1' */
  if (0.0F >= rtb_) {
    rtb_ = 0.0F;
  }

  /* Gain: '<S21>/Lco_min_lateral_error_slope' incorporates:
   *  MinMax: '<S21>/MinMax1'
   */
  rtb_fsun = (((real32_T)Lco_min_lateral_error_slope) * 0.0009765625F) * rtb_;

  /* MinMax: '<S21>/MinMax2'
   *
   * Block requirements for '<S21>/MinMax2':
   *  1. Minimum Lateral Error
   */
  if (rtb_fsun <= 1.0F) {
  } else {
    rtb_fsun = 1.0F;
  }

  /* End of MinMax: '<S21>/MinMax2' */

  /* Sum: '<S19>/Add' incorporates:
   *  Abs: '<S19>/Abs2'
   *  Constant: '<S19>/Lco_min_control_error'
   *  DataTypeConversion: '<S19>/Data Type Conversion2'
   */
  rtb_ = ((real32_T)fabs((real_T)(*rt_f3r3I))) - (((real32_T)
    Lco_min_control_error) * 0.0009765625F);

  /* MinMax: '<S19>/MinMax1' */
  if (0.0F >= rtb_) {
    rtb_ = 0.0F;
  }

  /* Gain: '<S19>/Lco_min_control_error_slope' incorporates:
   *  MinMax: '<S19>/MinMax1'
   */
  rtb_ *= ((real32_T)Lco_min_control_error_slope) * 0.0009765625F;

  /* MinMax: '<S19>/MinMax2'
   *
   * Block requirements for '<S19>/MinMax2':
   *  1. Minimum Control Error
   */
  if (rtb_ <= 1.0F) {
  } else {
    rtb_ = 1.0F;
  }

  /* Sum: '<S22>/Add1' incorporates:
   *  Gain: '<S20>/Lco_min_err_preload_enh_factor'
   *  MinMax: '<S19>/MinMax2'
   *  Product: '<S20>/Product'
   *  UnitDelay: '<S22>/Unit Delay'
   *
   * Block requirements for '<S19>/MinMax2':
   *  1. Minimum Control Error
   */
  rtb_ = ((((real32_T)Lco_min_err_preload_enh_factor) * 0.0009765625F) *
          (rtb_fsun * rtb_)) -
    DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_nrkb;

  /* Constant: '<S22>/Lco_error_filter_rising_coeff' */
  rtb_fsun = ((real32_T)Lco_error_filter_rising_coeff) * 3.05175781E-5F;

  /* Switch: '<S22>/Switch5' incorporates:
   *  Constant: '<S22>/Lco_error_filter_falling_coeff '
   *  Constant: '<S23>/Constant'
   *  RelationalOperator: '<S23>/Compare'
   */
  if (rtb_ >= 0.0F) {
  } else {
    rtb_fsun = ((real32_T)Lco_error_filter_falling_coeff) * 3.05175781E-5F;
  }

  /* End of Switch: '<S22>/Switch5' */

  /* Sum: '<S22>/Add' incorporates:
   *  Product: '<S22>/Product'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_nrkb += rtb_ *
    rtb_fsun;

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant'
   *
   * Block requirements for '<S18>/Switch':
   *  1. Fading Signal Error Selection
   */
  if ((int32_T)(*rt_e4hoI)) {
    rtb_ = 1.0F;
  } else {
    rtb_ = DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_nrkb;
  }

  /* End of Switch: '<S18>/Switch' */

  /* MinMax: '<S18>/MinMax1' */
  if (1.0F <= rtb_) {
    rtb_ = 1.0F;
  }

  /* End of MinMax: '<S18>/MinMax1' */

  /* MinMax: '<S3>/MinMax' */
  if (rtb_kln3 >= rtb_) {
    rtb_fsun = rtb_kln3;
  } else {
    rtb_fsun = rtb_;
  }

  /* End of MinMax: '<S3>/MinMax' */

  /* MinMax: '<S3>/MinMax2' */
  if (rtb_fsun >= rtb_m2kd) {
  } else {
    rtb_fsun = rtb_m2kd;
  }

  /* End of MinMax: '<S3>/MinMax2' */

  /* MinMax: '<S3>/MinMax1' */
  if (rtb_gedj >= rtb_fsun) {
  } else {
    rtb_gedj = rtb_fsun;
  }

  /* End of MinMax: '<S3>/MinMax1' */

  /* MinMax: '<S4>/MinMax' incorporates:
   *  Constant: '<S4>/Lco_min_load_comp_factor'
   */
  rtb_fsun = ((real32_T)Lco_min_load_comp_factor) * 0.0009765625F;
  if (rtb_gjqx <= rtb_fsun) {
    rtb_fsun = rtb_gjqx;
  }

  /* End of MinMax: '<S4>/MinMax' */

  /* Product: '<Root>/Product1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product2'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Add1'
   */
  *rt_gd42sI = rtb_dxut * ((rtb_gjqx * rtb_gedj) + (rtb_fsun * (1.0F - rtb_gedj)));

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  SAC_Accuracy_Request_dbg = (int16_T)((real32_T)floor((*rt_gd42sI) * 1024.0F));

  /* Gain: '<Root>/Gain' */
  *rt_erh2sI = 100.0F * (*rt_gd42sI);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  SAC_Load_Cmp_Fct_Curv_Chg_dbg = (uint16_T)((real32_T)(rtb_m2kd * 1024.0F));

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  SAC_Load_Comp_Factor_Straight_dbg = (uint16_T)((real32_T)(rtb_kln3 * 1024.0F));

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  SAC_Load_Comp_Factor_Varia_dbg = (uint16_T)((real32_T)(rtb_ * 1024.0F));

  /* Gain: '<S3>/Gain' */
  *rt_e4ho4I = 100.0F * rtb_kln3;
}

/* Model initialize function */
void DMC_Lat_SAC_Accuracy_Calculation_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_ghok = 0.0F;
  DMC_Lat_SAC_Accuracy_Calculation_DWork.UnitDelay_DSTATE_nrkb = 0.0F;
}
