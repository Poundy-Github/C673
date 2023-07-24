/* $Header: DMC_Lat_DYC_Dynamic_Compensation_Filter.c 1.30 2020/08/20 10:42:48CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_DYC_Dynamic_Compensation_Filter.c
   C source code generated on           : Mon Aug 17 20:46:23 2020
   Filename of Simulink Model           : DMC_Lat_DYC_Dynamic_Compensation_Filter.mdl/.slx
   Revision of Simulink Model           : 1.3032
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
#include "DMC_Lat_DYC_Dynamic_Compensation_Filter.h"
#include "DMC_Lat_DYC_Dynamic_Compensation_Filter_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: unsigned_int16_t Dyc_compensation_mode, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_boost_signal_reduction, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_dot_boost_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_state_filter_time_constant, [, ], 1  1,
   PARA: unsigned_int16_t Hec_yaw_rate_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor_neg, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor_pos, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_ldp_corr_y_sch, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_time_constant_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_ldp_counter_preload, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_kappa_gain, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_switch_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_pos_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a3_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a3_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_gen_cor_fct_neg, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_gen_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_lpf_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a3_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_x_schedul_aes, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_x_schedul_gen, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_time_constant_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_sch_aes_neg, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_sch_gen_neg, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_aes, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_gen, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_nom, [, ], 1  12,
   CALL: DMC_Lat_DYC_Dynamic_Compensation_Filter_step()
   CALL: DMC_Lat_DYC_Dynamic_Compensation_Filter_initialize(0)
   FILE: DMC_Lat_DYC_Dynamic_Compensation_Filter.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_DYC_Dynamic_Compensation_Filter_T
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_DYC_Dynamic_Compensation_Filter' */
void DMC_Lat_DYC_Dynamic_Compensation_Filter_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay (2)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay (2)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_oxw2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay (3)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm = 0.0F;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S35>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_f1n2 =
    (boolean_T)false;

  /* InitializeConditions for UnitDelay: '<S35>/Unit Delay (2)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt = 0.0F;

  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE_dnmf = 0.0F;

  /* InitializeConditions for UnitDelay: '<S68>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_iuzq = 0.0F;

  /* InitializeConditions for UnitDelay: '<S68>/Unit Delay (2)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_jmdn = 0.0F;
}

/* Output and update for referenced model: 'DMC_Lat_DYC_Dynamic_Compensation_Filter' */
void DMC_Lat_DYC_Dynamic_Compensation_Filter(const real32_T *rt_erh2I, const
  real32_T *rt_gd42I, const real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const
  real32_T *rt_ngfdI, const uint32_T *rt_f3r3I, const int16_T *rt_kkebI, const
  boolean_T *rt_hny3I, const real32_T *rt_kwugI, const boolean_T *rt_kafvI,
  const boolean_T *rt_kaadI, const boolean_T *rt_eltpI, const real32_T *rt_cjpeI,
  real32_T *rt_erh2sI, real32_T *rt_gd42sI)
{
  boolean_T rtb_;
  real32_T rtb_a3js;
  real32_T rtb_byzy;
  real32_T rtb_crzr;
  real32_T rtb_f2qz;
  real32_T rtb_o3hm;
  uint8_T rtb_ppfk;
  real32_T rtb_otrw;
  real32_T rtb_plyj;
  real32_T rtb_lmkm;
  boolean_T rtb_jzya;
  real32_T rtb_o1qe;
  real32_T rtb_ndp3;
  real32_T rtb_ejpd;
  real32_T rtb_absf;
  uint16_T rtb_a2gd;
  real32_T tmp_;

  /* Switch: '<S2>/Switch' */
  if ((int32_T)(*rt_kafvI)) {
    rtb_f2qz = *rt_kwugI;
  } else {
    rtb_f2qz = *rt_gd42I;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Logic: '<S4>/Logical Operator' */
  rtb_ = (boolean_T)((int32_T)(((int32_T)(*rt_kaadI)) || ((int32_T)(*rt_kafvI))));

  /* Lookup_n-D: '<S5>/Dyc_time_constant_scheduling' incorporates:
   *  Gain: '<S5>/MpsToKph'
   *
   * Block description for '<S5>/Dyc_time_constant_scheduling':
   *  u: 1
   */
  rtb_a3js = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ngfdI),
    (&(Dyc_time_constant_x_scheduling[0])), (&(Dyc_time_constant_y_scheduling[0])),
    11U);

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Dyc_state_filter_time_constant'
   *
   * Block description for '<S5>/Dyc_state_filter_time_constant':
   *  u: seconds
   */
  rtb_byzy = rtb_a3js * (((real32_T)Dyc_state_filter_time_constant) *
    3.05175781E-5F);

  /* MinMax: '<S4>/Max' */
  if (rtb_byzy >= 0.006F) {
    rtb_a3js = rtb_byzy;
  } else {
    rtb_a3js = 0.006F;
  }

  /* End of MinMax: '<S4>/Max' */

  /* Product: '<S4>/Product' */
  rtb_crzr = rtb_a3js * rtb_a3js;

  /* Switch: '<S4>/Switch (1)' incorporates:
   *  Constant: '<S4>/Constant (1)'
   *  Constant: '<S4>/Constant (2)'
   *  Constant: '<S4>/Constant (3)'
   *  Constant: '<S4>/Constant (4)'
   *  Product: '<S4>/Divide (1)'
   *  Product: '<S4>/Divide (2)'
   *  Product: '<S4>/Divide (3)'
   *  Product: '<S4>/Product (1)'
   *  Product: '<S4>/Product (2)'
   *  Product: '<S4>/Product (3)'
   *  Sum: '<S4>/Sub'
   *  UnitDelay: '<S4>/Unit Delay (1)'
   *  UnitDelay: '<S4>/Unit Delay (2)'
   */
  if ((int32_T)rtb_) {
    rtb_o3hm = 0.0F;
  } else {
    rtb_o3hm = (((1.0F / rtb_crzr) * rtb_f2qz) - ((1.0F / rtb_crzr) *
      DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE)) - ((2.0F
      / rtb_a3js) *
      DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE);
  }

  /* End of Switch: '<S4>/Switch (1)' */

  /* Switch: '<S4>/Switch (2)' incorporates:
   *  Constant: '<S4>/Constant (5)'
   *  Gain: '<S4>/Sac_ts (1)'
   *  Sum: '<S4>/Add (1)'
   *  UnitDelay: '<S4>/Unit Delay (1)'
   *
   * Block description for '<S4>/Sac_ts (1)':
   *  u: seconds
   */
  if ((int32_T)rtb_) {
    rtb_ndp3 = 0.0F;
  } else {
    rtb_ndp3 = ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_o3hm) +
      DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S4>/Switch (2)' */

  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S25>/Constant'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator (1)'
   */
  rtb_ppfk = (uint8_T)((int32_T)((((int32_T)Dyc_compensation_mode) & ((int32_T)
    32)) == ((int32_T)32)));

  /* Sum: '<S6>/Add (3)' incorporates:
   *  Gain: '<S6>/Sac_ts (3)'
   *  UnitDelay: '<S6>/Unit Delay (2)'
   *  UnitDelay: '<S6>/Unit Delay (3)'
   */
  rtb_ejpd = ((((real32_T)Sac_ts) * 3.05175781E-5F) *
              DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_oxw2)
    + DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay3_DSTATE;

  /* MinMax: '<S6>/MinMax' */
  if (rtb_byzy >= 0.02F) {
  } else {
    rtb_byzy = 0.02F;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* Product: '<S6>/Product (1)' */
  rtb_otrw = rtb_byzy * rtb_byzy;

  /* Product: '<S6>/Product (2)' */
  rtb_plyj = rtb_otrw * rtb_byzy;

  /* Sum: '<S6>/Sub' incorporates:
   *  Constant: '<S6>/Constant (1)'
   *  Constant: '<S6>/Constant (2)'
   *  Constant: '<S6>/Constant (3)'
   *  Constant: '<S6>/Constant (4)'
   *  Product: '<S6>/Divide (1)'
   *  Product: '<S6>/Divide (2)'
   *  Product: '<S6>/Divide (3)'
   *  Product: '<S6>/Divide (4)'
   *  Product: '<S6>/Product (3)'
   *  Product: '<S6>/Product (4)'
   *  Product: '<S6>/Product (5)'
   *  Product: '<S6>/Product (6)'
   *  UnitDelay: '<S6>/Unit Delay (1)'
   *  UnitDelay: '<S6>/Unit Delay (2)'
   *  UnitDelay: '<S6>/Unit Delay (3)'
   */
  rtb_plyj = ((((1.0F / rtb_plyj) * rtb_f2qz) - ((1.0F / rtb_plyj) *
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay3_DSTATE)) - ((3.0F /
    rtb_otrw) *
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_oxw2)) -
    ((3.0F / rtb_byzy) *
     DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm);

  /* Switch: '<S3>/Switch (1)' incorporates:
   *  UnitDelay: '<S6>/Unit Delay (1)'
   *  UnitDelay: '<S6>/Unit Delay (2)'
   */
  if (((int32_T)rtb_ppfk) != ((int32_T)0)) {
    rtb_crzr = rtb_f2qz;
  } else {
    rtb_crzr = rtb_ejpd;
  }

  if (((int32_T)rtb_ppfk) != ((int32_T)0)) {
    tmp_ = rtb_ndp3;
  } else {
    tmp_ = DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_oxw2;
  }

  if (((int32_T)rtb_ppfk) != ((int32_T)0)) {
  } else {
    rtb_o3hm =
      DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm;
  }

  /* End of Switch: '<S3>/Switch (1)' */

  /* Switch: '<S3>/Switch (2)' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator (3)'
   */
  rtb_jzya = (boolean_T)((int32_T)((((int32_T)Dyc_compensation_mode) & ((int32_T)
    4)) == ((int32_T)4)));

  /* Switch: '<S3>/Switch (3)' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S3>/Constant (3)'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S26>/Compare'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator (2)'
   *
   * Block requirements for '<S3>/Switch (3)':
   *  1. Dynamic Compensation Enabling
   */
  if (((((int32_T)Dyc_compensation_mode) & ((int32_T)2048)) == ((int32_T)2048)) &&
      ((int32_T)(*rt_hny3I))) {
    rtb_jzya = (boolean_T)false;
  }

  /* End of Switch: '<S3>/Switch (3)' */

  /* Switch: '<S3>/Switch (4)' */
  rtb_absf = rtb_crzr;
  if ((int32_T)rtb_jzya) {
  } else {
    rtb_absf = rtb_f2qz;
  }

  rtb_crzr = rtb_absf;
  rtb_absf = tmp_;
  if ((int32_T)rtb_jzya) {
  } else {
    rtb_absf = *rt_cpaoI;
  }

  tmp_ = rtb_absf;
  rtb_absf = rtb_o3hm;
  if ((int32_T)rtb_jzya) {
  } else {
    rtb_absf = 0.0F;
  }

  /* End of Switch: '<S3>/Switch (4)' */

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S12>/Dyc_kappa_dot_filter_coeff'
   *  Product: '<S12>/Product'
   *  Sum: '<S12>/Sub'
   *  UnitDelay: '<S12>/Unit Delay'
   *
   * Block description for '<S12>/Dyc_kappa_dot_filter_coeff':
   *  u: 1
   */
  *rt_erh2sI = ((tmp_ -
                 DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE)
                * (((real32_T)Dyc_kappa_dot_filter_coeff) * 3.05175781E-5F)) +
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE;

  /* Abs: '<S8>/Abs' */
  rtb_otrw = (real32_T)fabs((real_T)(*rt_erh2sI));

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Dyc_kappa_dot_boost_thrs'
   *
   * Block description for '<S8>/Dyc_kappa_dot_boost_thrs':
   *  u: 1/(m*s)
   */
  rtb_jzya = (boolean_T)((int32_T)(rtb_otrw > (((real32_T)
    Dyc_kappa_dot_boost_thrs) * 3.05175781E-5F)));

  /* Switch: '<S8>/Switch (2)' incorporates:
   *  Constant: '<S8>/Constant (2)'
   *
   * Block requirements for '<S8>/Switch (2)':
   *  1. Enable dynamic compensation
   */
  if ((int32_T)rtb_jzya) {
  } else {
    rtb_otrw = 0.0F;
  }

  /* End of Switch: '<S8>/Switch (2)' */

  /* Gain: '<S8>/DYC_Boost_Scaling'
   *
   * Block description for '<S8>/DYC_Boost_Scaling':
   *  u: 1
   */
  DYC_Boost_Request = 3000.0F * rtb_otrw;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Dyc_kappa_a2_boost_factor'
   *
   * Block description for '<S8>/Dyc_kappa_a2_boost_factor':
   *  u: 1
   */
  rtb_otrw = (*rt_erh2sI) * (((real32_T)Dyc_kappa_a2_boost_factor) *
    0.0009765625F);

  /* Switch: '<S8>/Switch (1)' incorporates:
   *  Constant: '<S8>/Constant (1)'
   *
   * Block requirements for '<S8>/Switch (1)':
   *  1. Enable dynamic compensation
   */
  if ((int32_T)rtb_jzya) {
  } else {
    rtb_otrw = 0.0F;
  }

  /* End of Switch: '<S8>/Switch (1)' */

  /* Signum: '<S13>/Sign' */
  if (rtb_otrw < 0.0F) {
    rtb_a3js = -1.0F;
  } else if (rtb_otrw > 0.0F) {
    rtb_a3js = 1.0F;
  } else {
    rtb_a3js = rtb_otrw;
  }

  /* End of Signum: '<S13>/Sign' */

  /* Abs: '<S13>/Abs' */
  rtb_otrw = (real32_T)fabs((real_T)rtb_otrw);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Dyc_boost_signal_reduction'
   *
   * Block description for '<S13>/Dyc_boost_signal_reduction':
   *  u: 1/(m*s)
   */
  rtb_lmkm = rtb_otrw - (((real32_T)Dyc_boost_signal_reduction) * 3.05175781E-5F);

  /* MinMax: '<S13>/MinMax' */
  if (0.0F >= rtb_lmkm) {
    rtb_lmkm = 0.0F;
  }

  /* Product: '<S13>/Product' incorporates:
   *  MinMax: '<S13>/MinMax'
   */
  rtb_otrw = rtb_a3js * rtb_lmkm;

  /* DataTypeConversion: '<S8>/Data Type Conversion (1)' */
  DYC_Boost_Filter_Out_dbg = (int16_T)((real32_T)floor(rtb_otrw / 0.001526F));

  /* DataTypeConversion: '<S8>/Data Type Conversion (2)' */
  DYC_Boost_Request_dbg = (int16_T)((real32_T)floor(DYC_Boost_Request * 1024.0F));

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S18>/Compare'
   *  S-Function (sfix_bitop): '<S10>/Bitwise Operator (1)'
   */
  rtb_jzya = (boolean_T)((int32_T)(((((int32_T)Dyc_compensation_mode) &
    ((int32_T)1024)) == ((int32_T)1024)) && ((int32_T)(*rt_hny3I))));

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S19>/Constant'
   *  S-Function (sfix_bitop): '<S10>/Bitwise Operator (2)'
   */
  rtb_ppfk = (uint8_T)((int32_T)((((int32_T)Dyc_compensation_mode) & ((int32_T)8))
    == ((int32_T)8)));

  /* Switch: '<S11>/Switch (2)' incorporates:
   *  Constant: '<S11>/Constant (1)'
   *  Constant: '<S11>/Dyc_kappa_a2_boost_factor_pos'
   *
   * Block description for '<S11>/Dyc_kappa_a2_boost_factor_pos':
   *  u: 1
   */
  if ((int32_T)(*rt_hny3I)) {
    rtb_lmkm = ((real32_T)Dyc_kappa_a2_boost_factor_pos) * 0.0009765625F;
  } else {
    rtb_lmkm = 1.0F;
  }

  /* End of Switch: '<S11>/Switch (2)' */

  /* Gain: '<S11>/MpsToKph' */
  rtb_o3hm = 3.6F * (*rt_ngfdI);

  /* Lookup_n-D: '<S11>/DYC_Kappa_A2_Scheduling_Sc'
   *
   * Block description for '<S11>/DYC_Kappa_A2_Scheduling_Sc':
   *  u: 1
   */
  rtb_byzy = look1_iflf_binlc(rtb_o3hm,
    DMC_Lat_DYC_Dynamic_Compensation_Filter_ConstP.pooled6,
    DMC_Lat_DYC_Dynamic_Compensation_Filter_ConstP.DYC_Kappa_A2_Scheduling_Sc_tableData,
    11U);

  /* Lookup_n-D: '<S11>/Dyc_kappa_a2_scheduling'
   *
   * Block description for '<S11>/Dyc_kappa_a2_scheduling':
   *  u: 1
   */
  rtb_o1qe = look1_ifbu16n6lftu16n12DfIf_binlcs(rtb_o3hm,
    (&(Dyc_kappa_a2_x_scheduling[0])), (&(Dyc_kappa_a2_y_scheduling[0])), 11U);

  /* Switch: '<S11>/Switch (1)' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S22>/Compare'
   *  S-Function (sfix_bitop): '<S11>/Bitwise Operator'
   */
  if (((*rt_f3r3I) & ((uint32_T)7U)) == ((uint32_T)4U)) {
  } else {
    rtb_byzy = rtb_o1qe;
  }

  /* End of Switch: '<S11>/Switch (1)' */

  /* Switch: '<S11>/Switch (3)' incorporates:
   *  Constant: '<S11>/Constant (1)'
   *  Constant: '<S11>/Dyc_kappa_a2_boost_factor_neg'
   *
   * Block description for '<S11>/Dyc_kappa_a2_boost_factor_neg':
   *  u: 1
   */
  if ((int32_T)(*rt_hny3I)) {
    rtb_o1qe = ((real32_T)Dyc_kappa_a2_boost_factor_neg) * 0.0009765625F;
  } else {
    rtb_o1qe = 1.0F;
  }

  /* End of Switch: '<S11>/Switch (3)' */

  /* Switch: '<S11>/Switch (4)' incorporates:
   *  Constant: '<S21>/Constant'
   *  Gain: '<S11>/Dyc_kappa_a2_factor'
   *  Gain: '<S11>/Dyc_kappa_a2_pos_corr_factor'
   *  Product: '<S11>/Product (1)'
   *  Product: '<S11>/Product (2)'
   *  RelationalOperator: '<S21>/Compare'
   *
   * Block description for '<S11>/Dyc_kappa_a2_factor':
   *  u: 1
   *
   * Block description for '<S11>/Dyc_kappa_a2_pos_corr_factor':
   *  u: 1
   */
  if (tmp_ > 0.0F) {
    rtb_o1qe = rtb_lmkm * ((((real32_T)Dyc_kappa_a2_pos_corr_factor) *
      0.000244140625F) * rtb_byzy);
  } else {
    rtb_o1qe *= (((real32_T)Dyc_kappa_a2_factor) * 0.000244140625F) * rtb_byzy;
  }

  /* End of Switch: '<S11>/Switch (4)' */

  /* Lookup_n-D: '<S11>/Dyc_kappa_a3_scheduling'
   *
   * Block description for '<S11>/Dyc_kappa_a3_scheduling':
   *  u: 1
   */
  rtb_lmkm = look1_ifbu16n6lftu16n12DfIf_binlcs(rtb_o3hm,
    (&(Dyc_kappa_a3_x_scheduling[0])), (&(Dyc_kappa_a3_y_scheduling[0])), 10U);

  /* Gain: '<S11>/Dyc_kappa_a3_factor'
   *
   * Block description for '<S11>/Dyc_kappa_a3_factor':
   *  u: 1
   */
  rtb_lmkm *= ((real32_T)Dyc_kappa_a3_factor) * 0.000244140625F;

  /* Lookup_n-D: '<S11>/DYC_Kappa_A4_Scheduling'
   *
   * Block description for '<S11>/DYC_Kappa_A4_Scheduling':
   *  u: 1
   */
  look1_iflf_binlc(rtb_o3hm,
                   DMC_Lat_DYC_Dynamic_Compensation_Filter_ConstP.DYC_Kappa_A4_Scheduling_bp01Data,
                   DMC_Lat_DYC_Dynamic_Compensation_Filter_ConstP.DYC_Kappa_A4_Scheduling_tableData,
                   10U);

  /* Switch: '<S10>/Switch (1)' */
  if (((int32_T)rtb_ppfk) != ((int32_T)0)) {
    rtb_o1qe = 0.3F;
  }

  if (((int32_T)rtb_ppfk) != ((int32_T)0)) {
    rtb_lmkm = 0.0F;
  }

  /* End of Switch: '<S10>/Switch (1)' */

  /* Switch: '<S10>/Switch (2)' */
  rtb_a3js = rtb_o1qe;
  if ((int32_T)rtb_jzya) {
    rtb_a3js = 0.0F;
  }

  rtb_o1qe = rtb_a3js;
  rtb_a3js = rtb_lmkm;
  if ((int32_T)rtb_jzya) {
    rtb_a3js = 0.0F;
  }

  /* End of Switch: '<S10>/Switch (2)' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S9>/Constant'
   *  DotProduct: '<S9>/Dot Product'
   *  RelationalOperator: '<S16>/Compare'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator'
   *  Sum: '<S9>/Add'
   *
   * Block requirements for '<S9>/Dot Product':
   *  1. Velocity dependent phase delay compensation
   */
  if ((((int32_T)Dyc_compensation_mode) & ((int32_T)3)) == ((int32_T)2)) {
    rtb_o1qe = rtb_otrw + ((rtb_crzr + (tmp_ * rtb_o1qe)) + (rtb_absf * rtb_a3js));
  } else {
    rtb_o1qe = 0.0F;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Switch: '<S4>/Switch (3)' incorporates:
   *  Gain: '<S4>/Sac_ts (2)'
   *  Sum: '<S4>/Add (2)'
   *  UnitDelay: '<S4>/Unit Delay (1)'
   *  UnitDelay: '<S4>/Unit Delay (2)'
   *
   * Block description for '<S4>/Sac_ts (2)':
   *  u: seconds
   */
  if ((int32_T)rtb_) {
  } else {
    rtb_f2qz = ((((real32_T)Sac_ts) * 3.05175781E-5F) *
                DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE)
      + DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S4>/Switch (3)' */

  /* Sum: '<S6>/Add (1)' incorporates:
   *  Gain: '<S6>/Sac_ts (1)'
   *  UnitDelay: '<S6>/Unit Delay (1)'
   *
   * Block description for '<S6>/Sac_ts (1)':
   *  u: seconds
   */
  rtb_absf = ((((real32_T)Sac_ts) * 3.05175781E-5F) * rtb_plyj) +
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm;

  /* Gain: '<S41>/DYC_Ay_Linear_Fading_Constant' incorporates:
   *  Abs: '<S41>/Abs'
   *  Constant: '<S41>/DYC_Ay_Linear_Treshold'
   *  Product: '<S41>/Product (1)'
   *  Product: '<S41>/Product (2)'
   *  Sum: '<S41>/Sub'
   *
   * Block description for '<S41>/DYC_Ay_Linear_Fading_Constant':
   *  u: s^2/m
   *
   * Block description for '<S41>/DYC_Ay_Linear_Treshold':
   *  u: m/s^2
   */
  rtb_plyj = 0.5F * (((real32_T)fabs((real_T)((real32_T)((*rt_gd42I) *
    ((*rt_ngfdI) * (*rt_ngfdI)))))) - 4.0F);

  /* MinMax: '<S54>/Minimum' */
  if (1.0F <= rtb_plyj) {
    rtb_plyj = 1.0F;
  }

  /* End of MinMax: '<S54>/Minimum' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S41>/Constant'
   *  Constant: '<S53>/Constant'
   *  RelationalOperator: '<S53>/Compare'
   *  S-Function (sfix_bitop): '<S41>/Bitwise Operator'
   */
  if ((((int32_T)Dyc_compensation_mode) & ((int32_T)512)) == ((int32_T)512)) {
    /* MinMax: '<S54>/Maximum' */
    if (0.0F >= rtb_plyj) {
      rtb_plyj = 0.0F;
    }

    /* End of MinMax: '<S54>/Maximum' */
  } else {
    rtb_plyj = 0.0F;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Gain: '<S43>/MpsToKph' */
  rtb_otrw = 3.6F * (*rt_ngfdI);

  /* Lookup_n-D: '<S43>/Dyc_kappa_angle_t_sched_gen_aes'
   *
   * Block description for '<S43>/Dyc_kappa_angle_t_sched_gen_aes':
   *  u: deg*m
   */
  rtb_crzr = look1_ifbu16n6lftu16n5DfIf_binlcs(rtb_otrw,
    (&(Dyc_kappa_angle_t_x_schedul_aes[0])), (&(Dyc_kappa_angle_t_y_schedul_aes
    [0])), 11U);

  /* Lookup_n-D: '<S43>/Dyc_kappa_angle_t_schedul_gen'
   *
   * Block description for '<S43>/Dyc_kappa_angle_t_schedul_gen':
   *  u: deg*m
   */
  rtb_lmkm = look1_ifbu16n6lftu16n5DfIf_binlcs(rtb_otrw,
    (&(Dyc_kappa_angle_t_x_schedul_gen[0])), (&(Dyc_kappa_angle_t_y_schedul_gen
    [0])), 11U);

  /* Switch: '<S43>/Switch (1)'
   *
   * Block requirements for '<S43>/Switch (1)':
   *  1. Generic Curvature Feed-forward Control Selection
   */
  if ((int32_T)(*rt_eltpI)) {
  } else {
    rtb_crzr = rtb_lmkm;
  }

  /* End of Switch: '<S43>/Switch (1)' */

  /* Product: '<S43>/Product (1)' incorporates:
   *  Constant: '<S43>/Dyc_kappa_angle_gen_corr_factor'
   *
   * Block description for '<S43>/Dyc_kappa_angle_gen_corr_factor':
   *  u: 1
   */
  rtb_lmkm = rtb_crzr * (((real32_T)Dyc_kappa_angle_gen_corr_factor) *
    0.000244140625F);

  /* Lookup_n-D: '<S45>/Dyc_kappa_angle_ldp_corr_sch' incorporates:
   *  Gain: '<S45>/MpsToKph'
   *
   * Block description for '<S45>/Dyc_kappa_angle_ldp_corr_sch':
   *  u: 1
   */
  rtb_crzr = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_ngfdI),
    (&(Dyc_kappa_angle_t_x_schedul_gen[0])), (&(Dyc_kappa_angle_ldp_corr_y_sch[0])),
    11U);

  /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
   *  Constant: '<S35>/Lat_ldp_counter_preload'
   *
   * Block description for '<S35>/Lat_ldp_counter_preload':
   *  u: 1
   */
  tmp_ = ((real32_T)Lat_ldp_counter_preload) * 0.0009765625F;

  /* Switch: '<S35>/Switch (1)' incorporates:
   *  Constant: '<S35>/Lat_ldp_switch_decrement'
   *  Logic: '<S35>/And Logical Operator (2)'
   *  Logic: '<S35>/Not Logical Operator (2)'
   *  Sum: '<S35>/Sub'
   *  UnitDelay: '<S35>/Unit Delay (1)'
   *  UnitDelay: '<S35>/Unit Delay (2)'
   *
   * Block description for '<S35>/Lat_ldp_switch_decrement':
   *  u: 1
   */
  if ((!DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_f1n2) &&
      ((int32_T)(*rt_hny3I))) {
  } else {
    tmp_ = DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt
      - (((real32_T)Lat_ldp_switch_decrement) * 0.0009765625F);
  }

  /* End of Switch: '<S35>/Switch (1)' */

  /* Switch: '<S35>/Switch (2)' incorporates:
   *  Constant: '<S35>/Constant (1)'
   *  Logic: '<S35>/And Logical Operator (1)'
   *  Logic: '<S35>/Not Logical Operator (1)'
   *  UnitDelay: '<S35>/Unit Delay (1)'
   */
  if ((!(*rt_hny3I)) && ((int32_T)
                         DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_f1n2))
  {
    tmp_ = 1.0F;
  }

  /* End of Switch: '<S35>/Switch (2)' */

  /* MinMax: '<S35>/Maximum' */
  if (tmp_ >= 0.0F) {
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt = tmp_;
  } else {
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt = 0.0F;
  }

  /* End of MinMax: '<S35>/Maximum' */

  /* MinMax: '<S35>/Minimum' */
  if (DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt <=
      1.0F) {
    tmp_ = DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt;
  } else {
    tmp_ = 1.0F;
  }

  /* End of MinMax: '<S35>/Minimum' */

  /* Sum: '<S45>/Add' incorporates:
   *  Constant: '<S45>/Constant (1)'
   *  Product: '<S45>/Product (1)'
   *  Sum: '<S45>/Sub'
   */
  rtb_crzr = (rtb_crzr * tmp_) + (1.0F - tmp_);

  /* S-Function (sfix_bitop): '<S45>/Bitwise Operator' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   */
  rtb_a2gd = (uint16_T)((int32_T)(((int32_T)Dyc_compensation_mode) & ((int32_T)
    16384)));

  /* Switch: '<S45>/Switch (1)' incorporates:
   *  Constant: '<S45>/Constant (3)'
   *
   * Block requirements for '<S45>/Switch (1)':
   *  1. Generic Curvature Feed-forward Control Selection
   */
  if (((int32_T)rtb_a2gd) != ((int32_T)0)) {
    rtb_o3hm = rtb_crzr;
  } else {
    rtb_o3hm = 1.0F;
  }

  /* End of Switch: '<S45>/Switch (1)' */

  /* Product: '<S43>/Product (3)' */
  rtb_a3js = rtb_lmkm * rtb_o3hm;

  /* Lookup_n-D: '<S43>/Dyc_kappa_angle_t_sch_gen_neg_aes'
   *
   * Block description for '<S43>/Dyc_kappa_angle_t_sch_gen_neg_aes':
   *  u: deg*m
   */
  rtb_lmkm = look1_ifbu16n6lftu16n5DfIf_binlcs(rtb_otrw,
    (&(Dyc_kappa_angle_t_x_schedul_aes[0])), (&(Dyc_kappa_angle_t_y_sch_aes_neg
    [0])), 11U);

  /* Lookup_n-D: '<S43>/Dyc_kappa_angle_t_sch_gen_neg'
   *
   * Block description for '<S43>/Dyc_kappa_angle_t_sch_gen_neg':
   *  u: deg*m
   */
  rtb_o3hm = look1_ifbu16n6lftu16n5DfIf_binlcs(rtb_otrw,
    (&(Dyc_kappa_angle_t_x_schedul_gen[0])), (&(Dyc_kappa_angle_t_y_sch_gen_neg
    [0])), 11U);

  /* Switch: '<S43>/Switch (2)'
   *
   * Block requirements for '<S43>/Switch (2)':
   *  1. Generic Curvature Feed-forward Control Selection
   */
  if ((int32_T)(*rt_eltpI)) {
  } else {
    rtb_lmkm = rtb_o3hm;
  }

  /* End of Switch: '<S43>/Switch (2)' */

  /* Switch: '<S45>/Switch (2)' incorporates:
   *  Constant: '<S45>/Constant (3)'
   *
   * Block requirements for '<S45>/Switch (2)':
   *  1. Generic Curvature Feed-forward Control Selection
   */
  if (((int32_T)rtb_a2gd) != ((int32_T)0)) {
    rtb_crzr = 1.0F;
  }

  /* End of Switch: '<S45>/Switch (2)' */

  /* Switch: '<S43>/Switch (3)' incorporates:
   *  Constant: '<S43>/Dyc_kappa_angle_gen_cor_fct_neg'
   *  Constant: '<S46>/Constant'
   *  Product: '<S43>/Product (2)'
   *  Product: '<S43>/Product (4)'
   *  RelationalOperator: '<S46>/Compare'
   *
   * Block description for '<S43>/Dyc_kappa_angle_gen_cor_fct_neg':
   *  u: 1
   *
   * Block requirements for '<S43>/Switch (3)':
   *  1. Generic Curvature Feed-forward Control Selection
   */
  if ((*rt_gd42I) > 0.0F) {
    rtb_crzr = rtb_a3js;
  } else {
    rtb_crzr *= rtb_lmkm * (((real32_T)Dyc_kappa_angle_gen_cor_fct_neg) *
      0.000244140625F);
  }

  /* End of Switch: '<S43>/Switch (3)' */

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S40>/VEH_Vehicle_Wheel_Base'
   *  Constant: '<S44>/Constant (1)'
   *  Constant: '<S44>/Lat_ldp_kappa_gain'
   *  Constant: '<S50>/Constant'
   *  Gain: '<S40>/VEH_Vehicle_Selfsteering_Factor'
   *  Gain: '<S51>/Gain'
   *  Product: '<S40>/Product'
   *  Product: '<S43>/Product (5)'
   *  Product: '<S44>/Product (1)'
   *  RelationalOperator: '<S50>/Compare'
   *  S-Function (sfix_bitop): '<S40>/Bitwise Operator'
   *  Sum: '<S40>/Add1'
   *  Sum: '<S44>/Add'
   *  Sum: '<S44>/Sub'
   *
   * Block description for '<S40>/VEH_Vehicle_Wheel_Base':
   *  u: rad*m
   *
   * Block description for '<S44>/Lat_ldp_kappa_gain':
   *  u: 1
   *
   * Block description for '<S40>/VEH_Vehicle_Selfsteering_Factor':
   *  u: kg*rad/N
   *
   * Block requirements for '<S40>/Switch':
   *  1. Feed-forward Control Selection
   */
  if ((((int32_T)Dyc_compensation_mode) & ((int32_T)16)) == ((int32_T)16)) {
    rtb_crzr *= ((((real32_T)Lat_ldp_kappa_gain) * 0.0009765625F) * tmp_) +
      (1.0F - tmp_);
  } else {
    rtb_crzr = 57.2957802F * (2.712F + (0.0021F * ((*rt_ngfdI) * (*rt_ngfdI))));
  }

  /* End of Switch: '<S40>/Switch' */

  /* Product: '<S38>/Product (1)' incorporates:
   *  Constant: '<S38>/Constant'
   *  Sum: '<S38>/Sub'
   */
  rtb_a3js = (1.0F - rtb_plyj) * rtb_crzr;

  /* Lookup_n-D: '<S38>/DYC_Kappa_Angle_T_Factor_High_Ay' incorporates:
   *  Gain: '<S38>/MpsToKph'
   *
   * Block description for '<S38>/DYC_Kappa_Angle_T_Factor_High_Ay':
   *  u: deg*m
   */
  rtb_crzr = look1_iflf_binlc(3.6F * (*rt_ngfdI),
    DMC_Lat_DYC_Dynamic_Compensation_Filter_ConstP.pooled6,
    DMC_Lat_DYC_Dynamic_Compensation_Filter_ConstP.DYC_Kappa_Angle_T_Factor_High_Ay_tableData,
    11U);

  /* Sum: '<S38>/Add' incorporates:
   *  Product: '<S38>/Product (2)'
   */
  DYC_Angle_Per_Kappa = rtb_a3js + (rtb_crzr * rtb_plyj);

  /* Lookup_n-D: '<S43>/Dyc_kappa_angle_t_schedul_nom'
   *
   * Block description for '<S43>/Dyc_kappa_angle_t_schedul_nom':
   *  u: deg*m
   */
  rtb_otrw = look1_ifbu16n6lftu16n5DfIf_binlcs(rtb_otrw,
    (&(Dyc_kappa_angle_t_x_schedul_gen[0])), (&(Dyc_kappa_angle_t_y_schedul_nom
    [0])), 11U);

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant (2)'
   *  Product: '<S57>/Product (1)'
   *  Product: '<S57>/Product (2)'
   *  RelationalOperator: '<S56>/Compare'
   *  S-Function (sfix_bitop): '<S33>/Bitwise Operator'
   *  Sum: '<S57>/Add'
   *  Sum: '<S57>/Sub'
   */
  if ((((int32_T)Dyc_compensation_mode) & ((int32_T)64)) == ((int32_T)64)) {
    rtb_plyj = tmp_ + ((1.0F - tmp_) * (*rt_erh2I));
  } else {
    rtb_plyj = 1.0F;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Sum: '<S34>/Add' incorporates:
   *  Constant: '<S34>/Hec_yaw_rate_filter_coeff'
   *  Product: '<S34>/Product'
   *  Product: '<S34>/Product (1)'
   *  Sum: '<S34>/Sub'
   *  UnitDelay: '<S34>/Unit Delay'
   *
   * Block description for '<S34>/Hec_yaw_rate_filter_coeff':
   *  u: 1
   */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE_dnmf +=
    ((((*rt_ngfdI) * (*rt_cjpeI)) * rtb_o1qe) -
     DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE_dnmf) *
    (((real32_T)Hec_yaw_rate_filter_coeff) * 3.05175781E-5F);

  /* Product: '<S63>/Product' */
  rtb_crzr = ((*rt_ngfdI) * (*rt_ngfdI)) * (*rt_gd42I);

  /* MinMax: '<S63>/Minimum' */
  if (rtb_crzr <= 6.0F) {
  } else {
    rtb_crzr = 6.0F;
  }

  /* End of MinMax: '<S63>/Minimum' */

  /* MinMax: '<S63>/Maximum' */
  if (rtb_crzr >= -6.0F) {
  } else {
    rtb_crzr = -6.0F;
  }

  /* End of MinMax: '<S63>/Maximum' */

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S62>/VEH_Force_Long_Tire_Factor'
   *  Constant: '<S62>/VEH_Vehicle_Reduced_Mass'
   *
   * Block description for '<S62>/VEH_Force_Long_Tire_Factor':
   *  u: deg
   *
   * Block description for '<S62>/VEH_Vehicle_Reduced_Mass':
   *  u: kg
   */
  rtb_lmkm = (0.00019887244F * rtb_crzr) * ((real32_T)(*rt_kkebI));

  /* MinMax: '<S62>/Minimum' */
  if (rtb_lmkm <= 2.0F) {
  } else {
    rtb_lmkm = 2.0F;
  }

  /* End of MinMax: '<S62>/Minimum' */

  /* Sum: '<S68>/Add' incorporates:
   *  Gain: '<S68>/Sac_ts'
   *  UnitDelay: '<S68>/Unit Delay (1)'
   *  UnitDelay: '<S68>/Unit Delay (2)'
   *
   * Block description for '<S68>/Sac_ts':
   *  u: seconds
   */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_jmdn +=
    (((real32_T)Sac_ts) * 3.05175781E-5F) *
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_iuzq;

  /* MinMax: '<S62>/Maximum' */
  if (rtb_lmkm >= -2.0F) {
  } else {
    rtb_lmkm = -2.0F;
  }

  /* Gain: '<S64>/DYC_Filter_Omega' incorporates:
   *  MinMax: '<S62>/Maximum'
   *  Sum: '<S64>/Sub'
   *
   * Block description for '<S64>/DYC_Filter_Omega':
   *  u: rad/s
   */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_iuzq = 20.0F *
    (rtb_lmkm -
     DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_jmdn);

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<Root>/Dyc_compensation_mode (1)1'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S61>/Constant'
   *  Gain: '<S64>/DYC_Filter_Tau'
   *  RelationalOperator: '<S61>/Compare'
   *  S-Function (sfix_bitop): '<S36>/Bitwise Operator'
   *  Sum: '<S64>/Add'
   *
   * Block description for '<S64>/DYC_Filter_Tau':
   *  u: seconds
   *
   * Block requirements for '<S36>/Switch':
   *  1. Compensation Angle Selection
   */
  if ((((int32_T)Dyc_compensation_mode) & ((int32_T)256)) == ((int32_T)256)) {
    rtb_crzr = 0.0F;
  } else {
    rtb_crzr = (0.1F *
                DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_iuzq)
      + DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_jmdn;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Product: '<S37>/Product (3)' incorporates:
   *  Gain: '<S34>/Dyc_kappa_angle_lpf_corr_factor'
   *  Product: '<S37>/Product (1)'
   *  Product: '<S37>/Product (2)'
   *  Sum: '<S37>/Add'
   *
   * Block description for '<S34>/Dyc_kappa_angle_lpf_corr_factor':
   *  u: 1
   */
  DYC_Steer_Angle_Feedforward = ((((rtb_otrw * (*rt_e4hoI)) +
    (DYC_Angle_Per_Kappa * rtb_o1qe)) + ((((real32_T)
    Dyc_kappa_angle_lpf_corr_factor) * 0.000244140625F) *
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE_dnmf)) +
    rtb_crzr) * rtb_plyj;

  /* DataTypeConversion: '<S37>/Data Type Conversion' */
  DYC_Steer_Angle_Feedforward_dbg = (int16_T)((real32_T)floor
    (DYC_Steer_Angle_Feedforward / 0.001526F));

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  *rt_gd42sI = rtb_otrw;

  /* Update for UnitDelay: '<S4>/Unit Delay (2)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE = rtb_f2qz;

  /* Update for UnitDelay: '<S4>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE = rtb_ndp3;

  /* Update for UnitDelay: '<S6>/Unit Delay (2)' incorporates:
   *  Gain: '<S6>/Sac_ts (2)'
   *  Sum: '<S6>/Add (2)'
   *  UnitDelay: '<S6>/Unit Delay (1)'
   *  UnitDelay: '<S6>/Unit Delay (2)'
   */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_oxw2 +=
    (((real32_T)Sac_ts) * 3.05175781E-5F) *
    DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm;

  /* Update for UnitDelay: '<S6>/Unit Delay (3)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay3_DSTATE = rtb_ejpd;

  /* Update for UnitDelay: '<S6>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm =
    rtb_absf;

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE = *rt_erh2sI;

  /* Update for UnitDelay: '<S35>/Unit Delay (1)' */
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_f1n2 =
    *rt_hny3I;
}

/* Model initialize function */
void DMC_Lat_DYC_Dynamic_Compensation_Filter_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) sde_memset((void *)&DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork, 0,
                    sizeof(rtDW_DMC_Lat_DYC_Dynamic_Compensation_Filter_T));
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_oxw2 = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay3_DSTATE = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_posm = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_g5qt = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay_DSTATE_dnmf = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay1_DSTATE_iuzq = 0.0F;
  DMC_Lat_DYC_Dynamic_Compensation_Filter_DWork.UnitDelay2_DSTATE_jmdn = 0.0F;
}
