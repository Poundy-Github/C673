/* $Header: DMC_Lat_SAC_Yaw_Rate_Control.c 1.24 2020/08/20 10:43:13CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_SAC_Yaw_Rate_Control.c
   C source code generated on           : Mon Aug 17 20:47:53 2020
   Filename of Simulink Model           : DMC_Lat_SAC_Yaw_Rate_Control.mdl/.slx
   Revision of Simulink Model           : 1.2356
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
#include "DMC_Lat_SAC_Yaw_Rate_Control.h"
#include "DMC_Lat_SAC_Yaw_Rate_Control_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: signed_int16_t Sac_one_by_ts, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_loop_gain_corr, [, ], 1  1,
   PARA: unsigned_int16_t Lat_yaw_rate_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_pt1_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_yr_cmd_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_dot_factor, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_dot_factor_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Hec_r_factor_obf, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_obf_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Lat_r_factor_level_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_ctrl_cmd_fading_y_sched, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kd_fading_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_ki_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_gain, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_dot_factor_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Hec_r_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_ctrl_cmd_fading_x_sched, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_y_scheduling, [, ], 1  11,
   CALL: DMC_Lat_SAC_Yaw_Rate_Control_step()
   CALL: DMC_Lat_SAC_Yaw_Rate_Control_initialize(0)
   FILE: DMC_Lat_SAC_Yaw_Rate_Control.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_SAC_Yaw_Rate_Control_T DMC_Lat_SAC_Yaw_Rate_Control_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_SAC_Yaw_Rate_Control' */
void DMC_Lat_SAC_Yaw_Rate_Control_Init(void)
{
  /* InitializeConditions for Sum: '<S15>/Add3' incorporates:
   *  InitializeConditions for UnitDelay: '<S15>/Unit Delay1'
   */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S18>/2nd_Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.nd_Delay_DSTATE = (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_bomv = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_o3wq = 0.0F;

  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_csnm = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_nt0t = 0.0F;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_eh21 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S18>/1st_Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.st_Delay_DSTATE = (boolean_T)false;
}

/* Output and update for referenced model: 'DMC_Lat_SAC_Yaw_Rate_Control' */
void DMC_Lat_SAC_Yaw_Rate_Control(const uint32_T *rt_erh2I, const real32_T
  *rt_gd42I, const real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const real32_T *
  rt_ngfdI, const real32_T *rt_f3r3I, const real32_T *rt_kkebI, const boolean_T *
  rt_hny3I, const real32_T *rt_kwugI, const uint16_T *rt_kafvI, real32_T
  *rt_erh2sI, real32_T *rt_gd42sI)
{
  real32_T rtb_;
  real32_T rtb_oqv5;
  real32_T rtb_g1pn;
  real32_T rtb_fbf0;
  real32_T rtb_ns15;
  real32_T rtb_otlv;

  /* Lookup_n-D: '<S6>/SAC_Yrc_Ctrl_Cmd_Fading_Sched' incorporates:
   *  Gain: '<S6>/MpsToKph'
   *
   * Block description for '<S6>/SAC_Yrc_Ctrl_Cmd_Fading_Sched':
   *  u: 1
   */
  rtb_ = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_gd42I),
    (&(Sac_yrc_ctrl_cmd_fading_x_sched[0])), (&(Sac_yrc_ctrl_cmd_fading_y_sched
    [0])), 10U);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<Root>/Dmc_configuration_mode'
   *  Constant: '<S6>/Constant'
   *  MinMax: '<S20>/MinMax'
   *  Product: '<S6>/Divide'
   *  Product: '<S6>/Product'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator'
   *  Sum: '<S6>/Add (1)'
   *
   * Block requirements for '<S6>/Switch':
   *  1. Enable active yaw rate control
   */
  if ((((int32_T)Dmc_configuration_mode) & ((int32_T)256)) != ((int32_T)0)) {
    /* MinMax: '<S20>/MinMax' */
    if ((*rt_f3r3I) >= 0.1F) {
      rtb_g1pn = *rt_f3r3I;
    } else {
      rtb_g1pn = 0.1F;
    }

    rtb_ *= ((*rt_kkebI) / rtb_g1pn) + (*rt_ngfdI);
  } else {
    rtb_ = 0.0F;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S6>/Add (2)' */
  rtb_ += *rt_cpaoI;

  /* Product: '<S2>/Product' */
  rtb_oqv5 = (*rt_gd42I) * rtb_;

  /* Sum: '<S2>/Sub' */
  *rt_gd42sI = rtb_oqv5 - (*rt_e4hoI);

  /* Gain: '<S4>/MpsToKph' */
  rtb_g1pn = 3.6F * (*rt_gd42I);

  /* Lookup_n-D: '<S4>/Hec_r_factor_obf_Scheduling' */
  rtb_fbf0 = look1_ifbu16n6lftu16n10DfIf_binlcs(rtb_g1pn, (&(Hec_r_x_scheduling
    [0])), (&(Hec_r_obf_y_scheduling[0])), 10U);

  /* Gain: '<S4>/Hec_r_factor_obf' */
  rtb_ns15 = (((real32_T)Hec_r_factor_obf) * 0.0009765625F) * rtb_fbf0;

  /* Sum: '<S15>/Add2' incorporates:
   *  Constant: '<S14>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  RelationalOperator: '<S14>/Compare'
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  rtb_fbf0 = ((real32_T)((int32_T)(((int32_T)(*rt_kafvI)) == ((int32_T)2)))) -
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE;

  /* Signum: '<S15>/Sign' */
  if (rtb_fbf0 < 0.0F) {
    rtb_fbf0 = -1.0F;
  } else {
    if (rtb_fbf0 > 0.0F) {
      rtb_fbf0 = 1.0F;
    }
  }

  /* End of Signum: '<S15>/Sign' */

  /* Sum: '<S15>/Add3' incorporates:
   *  Constant: '<S15>/Lat_r_factor_level_decrement'
   *  Product: '<S15>/Product'
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE += rtb_fbf0 * (((real32_T)
    Lat_r_factor_level_decrement) * 0.0009765625F);

  /* MinMax: '<S15>/MinMax' */
  if (DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE >= 0.0F) {
  } else {
    /* Sum: '<S15>/Add3' */
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE = 0.0F;
  }

  /* End of MinMax: '<S15>/MinMax' */

  /* MinMax: '<S15>/MinMax1' */
  if (1.0F <= DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE) {
    /* Sum: '<S15>/Add3' */
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE = 1.0F;
  }

  /* End of MinMax: '<S15>/MinMax1' */

  /* Lookup_n-D: '<S4>/SAC_Yrc_Kp_Scheduling'
   *
   * Block description for '<S4>/SAC_Yrc_Kp_Scheduling':
   *  u: 1
   */
  rtb_g1pn = look1_ifbu16n6lftu16n9DfIf_binlcs(rtb_g1pn,
    (&(Sac_yrc_kp_x_scheduling[0])), (&(Sac_yrc_kp_y_scheduling[0])), 10U);

  /* Product: '<S4>/Product (2)' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S4>/Sac_yrc_kp_gain'
   *  Product: '<S16>/Product1'
   *  Product: '<S16>/Product2'
   *  Product: '<S4>/Product (1)'
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Add1'
   *
   * Block description for '<S4>/Sac_yrc_kp_gain':
   *  u: deg*(s/rad)
   */
  rtb_ns15 = (*rt_gd42sI) * ((rtb_ns15 *
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE) + ((rtb_g1pn *
    (((real32_T)Sac_yrc_kp_gain) * 0.0009765625F)) * (1.0F -
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE)));

  /* Lookup_n-D: '<S5>/SAC_Yrc_Kp_Pt1_Scheduling' incorporates:
   *  Gain: '<S5>/MpsToKph'
   *
   * Block description for '<S5>/SAC_Yrc_Kp_Pt1_Scheduling':
   *  u: 1
   */
  rtb_g1pn = look1_ifbu16n6lftu16n9DfIf_binlcs(3.6F * (*rt_gd42I),
    (&(Sac_yrc_kp_pt1_x_scheduling[0])), (&(Sac_yrc_kp_pt1_y_scheduling[0])),
    10U);

  /* Product: '<S5>/Product (2)' incorporates:
   *  Constant: '<S5>/Sac_yrc_kp_pt1_gain'
   *  Product: '<S5>/Product (1)'
   *
   * Block description for '<S5>/Sac_yrc_kp_pt1_gain':
   *  u: deg*(s/rad)
   */
  rtb_g1pn = (*rt_gd42sI) * (rtb_g1pn * (((real32_T)Sac_yrc_kp_pt1_gain) *
    0.0009765625F));

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Sac_yrc_pt1_filter_coeff'
   *  UnitDelay: '<S18>/2nd_Delay'
   *
   * Block description for '<S18>/Sac_yrc_pt1_filter_coeff':
   *  u: 1
   *
   * Block requirements for '<S18>/Switch':
   *  1. Enable active yaw rate control
   */
  if ((int32_T)DMC_Lat_SAC_Yaw_Rate_Control_DWork.nd_Delay_DSTATE) {
    rtb_otlv = 1.0F;
  } else {
    rtb_otlv = ((real32_T)Sac_yrc_pt1_filter_coeff) * 3.05175781E-5F;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Sum: '<S18>/Add' incorporates:
   *  Product: '<S18>/Product'
   *  Sum: '<S18>/Sub'
   *  UnitDelay: '<S18>/Unit Delay'
   */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE += (rtb_g1pn -
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE) * rtb_otlv;

  /* Gain: '<S3>/Sac_yrc_ki_gain'
   *
   * Block description for '<S3>/Sac_yrc_ki_gain':
   *  u: deg/rad
   */
  rtb_g1pn = (((real32_T)Sac_yrc_ki_gain) * 0.0009765625F) * (*rt_gd42sI);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Gain: '<S7>/Gain'
   *  S-Function (sfix_bitop): '<S7>/Bitwise Operator'
   *  Sum: '<S7>/Add'
   */
  if (((*rt_erh2I) & ((uint32_T)512U)) != ((uint32_T)0U)) {
    rtb_otlv = 1.0F - (0.01F * (*rt_kwugI));
  } else {
    rtb_otlv = 1.0F;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/SAC_Yrc_Integrator_Limit'
   *  Product: '<S3>/Product'
   *
   * Block requirements for '<S3>/Switch':
   *  1. Enable active yaw rate control
   *
   * Block requirements for '<S3>/SAC_Yrc_Integrator_Limit':
   *  1. Limitation of controller I part
   */
  if ((int32_T)(*rt_hny3I)) {
    rtb_fbf0 = 0.0F;
  } else {
    rtb_fbf0 = 2.0F * rtb_otlv;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Add' incorporates:
   *  Gain: '<S3>/Sac_ts'
   *  UnitDelay: '<S3>/Unit Delay'
   *
   * Block description for '<S3>/Sac_ts':
   *  u: seconds
   */
  rtb_g1pn = ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_g1pn) +
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_bomv;

  /* MinMax: '<S3>/UpperLimit' */
  if (rtb_g1pn <= rtb_fbf0) {
  } else {
    rtb_g1pn = rtb_fbf0;
  }

  /* End of MinMax: '<S3>/UpperLimit' */

  /* Gain: '<S3>/Gain' */
  rtb_fbf0 = -rtb_fbf0;

  /* MinMax: '<S3>/LowerLimit' */
  if (rtb_g1pn >= rtb_fbf0) {
    rtb_fbf0 = rtb_g1pn;
  }

  /* End of MinMax: '<S3>/LowerLimit' */

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/Sac_yrc_yr_cmd_dot_filter_coeff'
   *  DataTypeConversion: '<S25>/Data Type Conversion'
   *  Gain: '<S9>/Gain'
   *  Product: '<S25>/Product'
   *  Sum: '<S25>/Add1'
   *  Sum: '<S9>/Add10'
   *  UnitDelay: '<S25>/Unit Delay'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_csnm += ((((real32_T)
    Sac_one_by_ts) * (rtb_oqv5 -
                      DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_o3wq))
    - DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_csnm) * (((real32_T)
    Sac_yrc_yr_cmd_dot_filter_coeff) * 3.05175781E-5F);

  /* Lookup_n-D: '<S23>/Hec_r_dot_factor_Scheduling' incorporates:
   *  Gain: '<S23>/Gain4'
   */
  rtb_g1pn = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_gd42I),
    (&(Hec_r_dot_factor_x_scheduling[0])), (&(Hec_r_dot_factor_y_scheduling[0])),
    10U);

  /* Gain: '<S23>/Hec_r_dot_factor' */
  rtb_g1pn *= ((real32_T)Hec_r_dot_factor) * 0.0009765625F;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S9>/Sac_yrc_kd_fading_factor'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Gain: '<S1>/Sac_yrc_loop_gain_corr'
   *  Product: '<S1>/Product'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  RelationalOperator: '<S10>/Compare'
   *  S-Function (sfix_bitop): '<S1>/Bitwise Operator'
   *  Sum: '<S1>/Add'
   *
   * Block description for '<S1>/Sac_yrc_loop_gain_corr':
   *  u: 1
   *
   * Block requirements for '<S1>/Add':
   *  1. Enable active yaw rate control
   */
  if (((*rt_erh2I) & ((uint32_T)2048U)) == ((uint32_T)2048U)) {
    rtb_otlv = 0.0F;
  } else {
    rtb_otlv *= (((real32_T)Sac_yrc_loop_gain_corr) * 0.000244140625F) *
      (((rtb_ns15 + DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE) +
        rtb_fbf0) + ((DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_csnm *
                      rtb_g1pn) * (((real32_T)Sac_yrc_kd_fading_factor) *
         0.0009765625F)));
  }

  /* End of Switch: '<S1>/Switch' */

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S24>/Lat_yaw_rate_dot_filter_coeff'
   *  Gain: '<S22>/Gain'
   *  Product: '<S24>/Product'
   *  Sum: '<S22>/Add10'
   *  Sum: '<S24>/Add1'
   *  UnitDelay: '<S22>/Unit Delay'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_eh21 += ((((real32_T)
    Sac_one_by_ts) * ((*rt_e4hoI) -
                      DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_nt0t))
    - DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_eh21) * (((real32_T)
    Lat_yaw_rate_dot_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S1>/Add1' incorporates:
   *  Product: '<S8>/Product12'
   *
   * Block requirements for '<S1>/Add1':
   *  1. Enable active yaw rate control
   */
  *rt_erh2sI = rtb_otlv -
    (DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_eh21 * rtb_g1pn);

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  SAC_Yrc_Angle_Command_dbg = (int16_T)((real32_T)floor((*rt_erh2sI) / 0.001526F));

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  SAC_Yrc_Residual_dbg = (int16_T)((real32_T)floor((*rt_gd42sI) / 0.001526F));

  /* DataTypeConversion: '<S6>/Data Type Conversion (2)' */
  LAT_Debug3_dbg = (int16_T)((real32_T)floor(rtb_ * 1024.0F));

  /* Update for UnitDelay: '<S18>/2nd_Delay' incorporates:
   *  UnitDelay: '<S18>/1st_Delay'
   */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.nd_Delay_DSTATE =
    DMC_Lat_SAC_Yaw_Rate_Control_DWork.st_Delay_DSTATE;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_bomv = rtb_fbf0;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_o3wq = rtb_oqv5;

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_nt0t = *rt_e4hoI;

  /* Update for UnitDelay: '<S18>/1st_Delay' */
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.st_Delay_DSTATE = *rt_hny3I;
}

/* Model initialize function */
void DMC_Lat_SAC_Yaw_Rate_Control_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Lat_SAC_Yaw_Rate_Control_DWork, 0,
                    sizeof(rtDW_DMC_Lat_SAC_Yaw_Rate_Control_T));
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay1_DSTATE = 0.0F;
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_bomv = 0.0F;
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_o3wq = 0.0F;
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_csnm = 0.0F;
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_nt0t = 0.0F;
  DMC_Lat_SAC_Yaw_Rate_Control_DWork.UnitDelay_DSTATE_eh21 = 0.0F;
}
