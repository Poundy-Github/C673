/* $Header: DMC_Lat_SAT_Angle_Command_Saturation.c 1.28 2020/08/20 10:43:16CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_SAT_Angle_Command_Saturation.c
   C source code generated on           : Mon Aug 17 20:48:02 2020
   Filename of Simulink Model           : DMC_Lat_SAT_Angle_Command_Saturation.mdl/.slx
   Revision of Simulink Model           : 1.187
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
#include "DMC_Lat_SAT_Angle_Command_Saturation.h"
#include "DMC_Lat_SAT_Angle_Command_Saturation_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: unsigned_int16_t Lat_ay_sat_margin_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sat_dynamic_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_cmd_factor_aes_y_sched, [, ], 1  13,
   PARA: unsigned_int16_t Sat_max_cmd_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Lat_support_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_cmd_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd_phy, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay, [, ], 1  1,
   PARA: unsigned_int16_t Sat_thrs_control_kp, [, ], 1  1,
   CALL: DMC_Lat_SAT_Angle_Command_Saturation_step()
   CALL: DMC_Lat_SAT_Angle_Command_Saturation_initialize(0)
   FILE: DMC_Lat_SAT_Angle_Command_Saturation.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_SAT_Angle_Command_Saturation_T
  DMC_Lat_SAT_Angle_Command_Saturation_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_SAT_Angle_Command_Saturation' */
void DMC_Lat_SAT_Angle_Command_Saturation_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_jqbs = 0.0F;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hrg2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_ioqj = 0.0F;

  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hn0u = 0.0F;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_mqg2 = 0.0F;
}

/* Output and update for referenced model: 'DMC_Lat_SAT_Angle_Command_Saturation' */
void DMC_Lat_SAT_Angle_Command_Saturation(const real32_T *rt_erh2I, const
  real32_T *rt_gd42I, const real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const
  real32_T *rt_ngfdI, const boolean_T *rt_f3r3I, const boolean_T *rt_kkebI,
  const real32_T *rt_hny3I, const boolean_T *rt_kwugI, const real32_T *rt_kafvI,
  const real32_T *rt_kaadI, real32_T *rt_erh2sI, real32_T *rt_gd42sI, real32_T
  *rt_cpaomI, real32_T *rt_e4ho4I, real32_T *rt_ngfdoI, uint16_T *rt_f3r3lI,
  real32_T *rt_kkeboI)
{
  real32_T rtb_;
  real32_T rtb_akep;
  real32_T rtb_d4wl;
  real32_T rtb_jcwc;
  real32_T rtb_cna3;
  real32_T rtb_js43;
  real32_T rtb_iae5;
  uint16_T rtb_nlv2;
  uint16_T rtb_k1qu;
  boolean_T rtb_awej;
  uint16_T rtb_j3vk;
  uint16_T rtb_j0co;
  uint16_T rtb_poxv;
  real32_T tmp_;

  /* Inport: '<Root>/SAC_Faded_Angle_Command'
   *
   * Block description for '<Root>/SAC_Faded_Angle_Command':
   *  u: degrees
   */
  *rt_erh2sI = *rt_erh2I;

  /* Gain: '<S4>/MpsToKph' */
  rtb_ = 3.6F * (*rt_gd42I);

  /* Lookup_n-D: '<S4>/Sat_max_cmd_factor_aes_sched'
   *
   * Block description for '<S4>/Sat_max_cmd_factor_aes_sched':
   *  u: degrees
   */
  rtb_d4wl = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_,
    (&(Sat_max_cmd_factor_x_scheduling[0])), (&(Sat_max_cmd_factor_aes_y_sched[0])),
    12U);

  /* Lookup_n-D: '<S4>/Sat_max_cmd_factor_scheduling'
   *
   * Block description for '<S4>/Sat_max_cmd_factor_scheduling':
   *  u: degrees
   */
  rtb_ = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_,
    (&(Sat_max_cmd_factor_x_scheduling[0])), (&(Sat_max_cmd_factor_y_scheduling
    [0])), 12U);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Sat_max_delta_f_cmd'
   *  Product: '<S4>/Product'
   *
   * Block description for '<S4>/Sat_max_delta_f_cmd':
   *  u: degrees
   */
  if ((int32_T)(*rt_kkebI)) {
  } else {
    rtb_d4wl = rtb_ * (((real32_T)Sat_max_delta_f_cmd) * 0.001953125F);
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S14>/Add' incorporates:
   *  Constant: '<S11>/Lat_support_enhancement_factor'
   *  Constant: '<S11>/Lat_support_filter_coeff'
   *  Product: '<S11>/Product5'
   *  Product: '<S11>/Product6'
   *  Product: '<S14>/Product'
   *  Sum: '<S14>/Add1'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE += (((rtb_d4wl *
    (((real32_T)Lat_support_enhancement_factor) * 0.0009765625F)) * (*rt_kaadI))
    - DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE) * (((real32_T)
    Lat_support_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S11>/Add3' */
  rtb_d4wl += DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE;

  /* Product: '<S6>/Product (1)' */
  rtb_jcwc = (*rt_gd42I) * (*rt_gd42I);

  /* MinMax: '<S6>/MinMax' */
  if (rtb_jcwc >= 0.1F) {
    tmp_ = rtb_jcwc;
  } else {
    tmp_ = 0.1F;
  }

  /* Product: '<S6>/Product (4)' incorporates:
   *  Constant: '<S6>/Lat_ay_sat_margin_factor'
   *  Constant: '<S6>/Lat_max_ay'
   *  Constant: '<S6>/VEH_Vehicle_Selfsteering_Factor'
   *  Constant: '<S6>/VEH_Vehicle_Wheel_Base'
   *  Gain: '<S21>/Gain'
   *  MinMax: '<S6>/MinMax'
   *  Product: '<S6>/Divide'
   *  Product: '<S6>/Product (2)'
   *  Product: '<S6>/Product (3)'
   *  Sum: '<S6>/Add'
   *
   * Block description for '<S6>/Lat_ay_sat_margin_factor':
   *  u: 1
   *
   * Block description for '<S6>/Lat_max_ay':
   *  u: m/s^2
   *
   * Block description for '<S6>/VEH_Vehicle_Selfsteering_Factor':
   *  u: kg*rad/N
   *
   * Block description for '<S6>/VEH_Vehicle_Wheel_Base':
   *  u: rad*m
   */
  rtb_jcwc = (((((real32_T)Lat_max_ay) * 0.0009765625F) * (((real32_T)
    Lat_ay_sat_margin_factor) * 0.0009765625F)) / tmp_) * (57.2957802F *
    ((rtb_jcwc * 0.0021F) + 2.712F));

  /* Sum: '<S15>/Add' incorporates:
   *  Constant: '<S12>/Lat_support_enhancement_factor'
   *  Constant: '<S12>/Lat_support_filter_coeff'
   *  Product: '<S12>/Product5'
   *  Product: '<S12>/Product6'
   *  Product: '<S15>/Product'
   *  Sum: '<S15>/Add1'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_jqbs +=
    (((rtb_jcwc * (((real32_T)Lat_support_enhancement_factor) * 0.0009765625F)) *
      (*rt_kaadI)) -
     DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_jqbs) *
    (((real32_T)Lat_support_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S12>/Add3' */
  *rt_cpaomI = rtb_jcwc +
    DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_jqbs;

  /* MinMax: '<S3>/MinMax' */
  if ((*rt_gd42I) >= 0.1F) {
    rtb_cna3 = *rt_gd42I;
  } else {
    rtb_cna3 = 0.1F;
  }

  /* End of MinMax: '<S3>/MinMax' */

  /* Product: '<S3>/Product4' */
  rtb_cna3 *= rtb_cna3;

  /* MinMax: '<S3>/MinMax4' */
  if (rtb_cna3 >= 0.1F) {
  } else {
    rtb_cna3 = 0.1F;
  }

  /* Product: '<S3>/Product3' incorporates:
   *  Gain: '<S3>/Lat_ay_sat_margin_factor'
   *  MinMax: '<S3>/MinMax4'
   *  Product: '<S3>/Divide1'
   */
  rtb_cna3 = (*rt_kafvI) * (((((real32_T)Lat_ay_sat_margin_factor) *
    0.0009765625F) * (*rt_ngfdI)) / rtb_cna3);

  /* Sum: '<S16>/Add' incorporates:
   *  Constant: '<S13>/Lat_support_enhancement_factor'
   *  Constant: '<S13>/Lat_support_filter_coeff'
   *  Product: '<S13>/Product5'
   *  Product: '<S13>/Product6'
   *  Product: '<S16>/Product'
   *  Sum: '<S16>/Add1'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hrg2 +=
    (((rtb_cna3 * (((real32_T)Lat_support_enhancement_factor) * 0.0009765625F)) *
      (*rt_kaadI)) -
     DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hrg2) *
    (((real32_T)Lat_support_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S13>/Add3' */
  rtb_cna3 += DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hrg2;

  /* Constant: '<S30>/Sat_max_delta_f_cmd_phy'
   *
   * Block description for '<S30>/Sat_max_delta_f_cmd_phy':
   *  u: degrees
   */
  rtb_akep = ((real32_T)Sat_max_delta_f_cmd_phy) * 0.001953125F;

  /* MinMax: '<S30>/MinMax (1)' */
  rtb_ = *rt_cpaomI;
  if (rtb_ <= rtb_cna3) {
  } else {
    rtb_ = rtb_cna3;
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Logic: '<S30>/Logical Operator'
   *  MinMax: '<S30>/MinMax (1)'
   */
  if (((int32_T)(*rt_kwugI)) || ((int32_T)(*rt_f3r3I))) {
  } else {
    rtb_akep = rtb_;
  }

  /* End of Switch: '<S30>/Switch' */

  /* MinMax: '<S30>/MinMax (3)' */
  if (rtb_akep <= (*rt_hny3I)) {
    tmp_ = rtb_akep;
  } else {
    tmp_ = *rt_hny3I;
  }

  *rt_kkeboI = tmp_;

  /* End of MinMax: '<S30>/MinMax (3)' */

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Sat_dynamic_enhancement_factor'
   *
   * Block description for '<S5>/Sat_dynamic_enhancement_factor':
   *  u: 1
   */
  rtb_ = (*rt_kkeboI) * (((real32_T)Sat_dynamic_enhancement_factor) *
    0.0009765625F);

  /* Sum: '<S5>/Sub' incorporates:
   *  Sum: '<S9>/Add'
   *  UnitDelay: '<S25>/Unit Delay'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  rtb_ -= DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_ioqj +
    DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hn0u;

  /* Constant: '<S5>/Sat_max_delta_f_cmd_phy'
   *
   * Block description for '<S5>/Sat_max_delta_f_cmd_phy':
   *  u: degrees
   */
  rtb_js43 = ((real32_T)Sat_max_delta_f_cmd_phy) * 0.001953125F;

  /* MinMax: '<S5>/MinMax' */
  if (rtb_js43 <= rtb_) {
  } else {
    rtb_js43 = rtb_;
  }

  /* End of MinMax: '<S5>/MinMax' */

  /* MinMax: '<S2>/MinMax (1)' */
  rtb_ = *rt_erh2sI;
  if (rtb_ <= rtb_js43) {
  } else {
    rtb_ = rtb_js43;
  }

  /* MinMax: '<S2>/MinMax (2)' incorporates:
   *  Gain: '<S2>/Gain'
   *  MinMax: '<S2>/MinMax (1)'
   */
  if (rtb_ >= (-rtb_js43)) {
  } else {
    rtb_ = -rtb_js43;
  }

  /* End of MinMax: '<S2>/MinMax (2)' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  SAT_Req_Dyn_Steer_Angle_Max_dbg = (int16_T)((real32_T)floor(rtb_js43 /
    0.001526F));

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  SAT_Req_Steer_Angle_Max_Ay_dbg = (int16_T)((real32_T)floor(rtb_jcwc /
    0.001526F));

  /* Gain: '<S7>/MpsToKph' */
  rtb_iae5 = 3.6F * (*rt_gd42I);

  /* Lookup_n-D: '<S7>/SAT_Max_Angle_Scheduling' */
  rtb_js43 = look1_iflf_binlx(rtb_iae5,
    DMC_Lat_SAT_Angle_Command_Saturation_ConstP.SAT_Max_Angle_Scheduling_bp01Data,
    DMC_Lat_SAT_Angle_Command_Saturation_ConstP.SAT_Max_Angle_Scheduling_tableData,
    3U);

  /* MinMax: '<S7>/MinMax (1)' */
  if ((*rt_gd42I) >= 1.38888884F) {
    tmp_ = *rt_gd42I;
  } else {
    tmp_ = 1.38888884F;
  }

  /* Sum: '<S7>/Add (2)' incorporates:
   *  Abs: '<S7>/Abs'
   *  Constant: '<S7>/VEH_Vehicle_Selfsteering_Factor'
   *  Constant: '<S7>/VEH_Vehicle_Wheel_Base'
   *  Gain: '<S23>/Gain'
   *  MinMax: '<S7>/MinMax (1)'
   *  Product: '<S7>/Divide'
   *  Product: '<S7>/Product (1)'
   *  Sum: '<S7>/Add (1)'
   *
   * Block description for '<S7>/VEH_Vehicle_Selfsteering_Factor':
   *  u: kg*rad/N
   *
   * Block description for '<S7>/VEH_Vehicle_Wheel_Base':
   *  u: rad*m
   */
  rtb_js43 += 57.2957802F * ((real32_T)fabs((real_T)((real32_T)((((*rt_cpaoI) *
    2.712F) / tmp_) + ((*rt_e4hoI) * 0.0021F)))));

  /* Lookup_n-D: '<S7>/Sat_max_angle_low_bound_sched'
   *
   * Block description for '<S7>/Sat_max_angle_low_bound_sched':
   *  u: 1
   */
  rtb_iae5 = look1_iflf_binlx(rtb_iae5,
    DMC_Lat_SAT_Angle_Command_Saturation_ConstP.Sat_max_angle_low_bound_sched_bp01Data,
    DMC_Lat_SAT_Angle_Command_Saturation_ConstP.Sat_max_angle_low_bound_sched_tableData,
    2U);

  /* MinMax: '<S7>/MinMax (2)' */
  if (rtb_js43 >= rtb_iae5) {
    rtb_iae5 = rtb_js43;
  }

  /* Sum: '<S8>/Sub' */
  *rt_e4ho4I = (*rt_erh2sI) - rtb_;

  /* Sum: '<S26>/Add' incorporates:
   *  Constant: '<S26>/SAT_Controller_Coeff'
   *  Product: '<S26>/Product'
   *  Sum: '<S26>/Sub'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_mqg2 += (rtb_ -
    DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_mqg2) * 0.02F;

  /* Constant: '<S29>/Sat_max_delta_f_cmd_phy'
   *
   * Block description for '<S29>/Sat_max_delta_f_cmd_phy':
   *  u: degrees
   */
  rtb_jcwc = ((real32_T)Sat_max_delta_f_cmd_phy) * 0.001953125F;

  /* Switch: '<S29>/Switch' incorporates:
   *  Logic: '<S29>/Logical Operator'
   */
  if (((int32_T)(*rt_f3r3I)) || ((int32_T)(*rt_kwugI))) {
  } else {
    rtb_jcwc = rtb_d4wl;
  }

  /* End of Switch: '<S29>/Switch' */

  /* MinMax: '<S29>/MinMax' */
  rtb_ = *rt_kkeboI;
  if (rtb_ <= rtb_jcwc) {
    rtb_jcwc = rtb_;
  }

  *rt_gd42sI = rtb_jcwc;

  /* End of MinMax: '<S29>/MinMax' */

  /* Sum: '<S9>/Sub' incorporates:
   *  Abs: '<S9>/Abs'
   */
  rtb_ = ((real32_T)fabs((real_T)
           DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_mqg2)) -
    (*rt_gd42sI);

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Sat_thrs_control_kp'
   *
   * Block description for '<S9>/Sat_thrs_control_kp':
   *  u: 1
   */
  rtb_js43 = (((real32_T)Sat_thrs_control_kp) * 0.00390625F) * rtb_;

  /* Abs: '<S28>/Abs' */
  rtb_ = (real32_T)fabs((real_T)(*rt_erh2sI));

  /* Switch: '<S28>/Switch (1)' incorporates:
   *  Constant: '<S28>/ResetBit'
   *  Constant: '<S28>/SetBit'
   *  RelationalOperator: '<S28>/Relational Operator (1)'
   */
  if (rtb_ >= rtb_d4wl) {
    rtb_nlv2 = (uint16_T)1U;
  } else {
    rtb_nlv2 = (uint16_T)0U;
  }

  /* End of Switch: '<S28>/Switch (1)' */

  /* Gain: '<S28>/Gain (1)' */
  rtb_k1qu = rtb_nlv2;

  /* RelationalOperator: '<S28>/Relational Operator (2)' */
  rtb_awej = (boolean_T)((int32_T)(rtb_ >= (*rt_cpaomI)));

  /* Switch: '<S28>/Switch (2)' incorporates:
   *  Constant: '<S28>/ResetBit'
   *  Constant: '<S28>/SetBit'
   */
  if ((int32_T)rtb_awej) {
    rtb_nlv2 = (uint16_T)1U;
  } else {
    rtb_nlv2 = (uint16_T)0U;
  }

  /* End of Switch: '<S28>/Switch (2)' */

  /* Gain: '<S28>/Gain (2)' */
  rtb_j3vk = (uint16_T)(rtb_nlv2 << ((int8_T)1));

  /* Switch: '<S28>/Switch (3)' incorporates:
   *  Constant: '<S28>/ResetBit'
   *  Constant: '<S28>/SetBit'
   *  Constant: '<S7>/Lat_ay_sat_margin_factor'
   *  MinMax: '<S7>/MinMax (2)'
   *  Product: '<S7>/Product (2)'
   *  RelationalOperator: '<S28>/Relational Operator (3)'
   *
   * Block description for '<S7>/Lat_ay_sat_margin_factor':
   *  u: 1
   */
  if (rtb_ >= ((((real32_T)Lat_ay_sat_margin_factor) * 0.0009765625F) * rtb_iae5))
  {
    rtb_nlv2 = (uint16_T)1U;
  } else {
    rtb_nlv2 = (uint16_T)0U;
  }

  /* End of Switch: '<S28>/Switch (3)' */

  /* Gain: '<S28>/Gain (3)' */
  rtb_j0co = (uint16_T)(rtb_nlv2 << ((int8_T)2));

  /* Switch: '<S28>/Switch (4)' incorporates:
   *  Constant: '<S28>/ResetBit'
   *  Constant: '<S28>/SetBit'
   *  RelationalOperator: '<S28>/Relational Operator (4)'
   */
  if (rtb_ >= rtb_cna3) {
    rtb_nlv2 = (uint16_T)1U;
  } else {
    rtb_nlv2 = (uint16_T)0U;
  }

  /* End of Switch: '<S28>/Switch (4)' */

  /* Gain: '<S28>/Gain (4)' */
  rtb_poxv = (uint16_T)(rtb_nlv2 << ((int8_T)3));

  /* Switch: '<S28>/Switch (5)' incorporates:
   *  Constant: '<S28>/ResetBit'
   *  Constant: '<S28>/SetBit'
   *  RelationalOperator: '<S28>/Relational Operator (5)'
   */
  if (rtb_ >= (*rt_hny3I)) {
    rtb_nlv2 = (uint16_T)1U;
  } else {
    rtb_nlv2 = (uint16_T)0U;
  }

  /* End of Switch: '<S28>/Switch (5)' */

  /* Sum: '<S28>/Add' incorporates:
   *  Gain: '<S28>/Gain (5)'
   */
  *rt_f3r3lI = (uint16_T)((((((uint32_T)rtb_k1qu) + ((uint32_T)rtb_j3vk)) +
    ((uint32_T)rtb_j0co)) + ((uint32_T)rtb_poxv)) + ((uint32_T)((int32_T)
    (((int32_T)rtb_nlv2) << ((int8_T)4)))));

  /* DataTypeConversion: '<S29>/Data Type Conversion' */
  SAT_Req_Steer_Angle_Max_dbg = (int16_T)((real32_T)floor((*rt_gd42sI) /
    0.001526F));

  /* MinMax: '<S30>/MinMax (2)' */
  if (rtb_d4wl <= rtb_akep) {
    rtb_akep = rtb_d4wl;
  }

  *rt_ngfdoI = rtb_akep;

  /* End of MinMax: '<S30>/MinMax (2)' */

  /* MinMax: '<S9>/MinMax' */
  if (0.0F >= rtb_js43) {
    /* Update for UnitDelay: '<S9>/Unit Delay' */
    DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_ioqj = 0.0F;
  } else {
    /* Update for UnitDelay: '<S9>/Unit Delay' */
    DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_ioqj = rtb_js43;
  }

  /* End of MinMax: '<S9>/MinMax' */

  /* Update for UnitDelay: '<S25>/Unit Delay' incorporates:
   *  Gain: '<S25>/Sac_ts'
   *  Sum: '<S25>/Add'
   *  UnitDelay: '<S25>/Unit Delay'
   *
   * Block description for '<S25>/Sac_ts':
   *  u: seconds
   */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hn0u +=
    (((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_js43;
}

/* Model initialize function */
void DMC_Lat_SAT_Angle_Command_Saturation_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_jqbs = 0.0F;
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hrg2 = 0.0F;
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_ioqj = 0.0F;
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_hn0u = 0.0F;
  DMC_Lat_SAT_Angle_Command_Saturation_DWork.UnitDelay_DSTATE_mqg2 = 0.0F;
}
