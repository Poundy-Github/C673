/* $Header: DMC_Soc_Lat_MOT_Modulation_Torque.c 1.20 2020/08/20 10:43:37CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc_Lat_MOT_Modulation_Torque.c
   C source code generated on           : Mon Aug 17 20:48:56 2020
   Filename of Simulink Model           : DMC_Soc_Lat_MOT_Modulation_Torque.mdl/.slx
   Revision of Simulink Model           : 1.27
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
#include "DMC_Soc_Lat_MOT_Modulation_Torque.h"
#include "DMC_Soc_Lat_MOT_Modulation_Torque_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: unsigned_int16_t Mot_modulation_duty_cycle, [, ], 1  1,
   PARA: unsigned_int16_t Mot_signal_gen_freq_modulation, [, ], 1  1,
   PARA: unsigned_int16_t Mot_signal_gen_frequency_base, [, ], 1  1,
   PARA: unsigned_int16_t Mot_torque_duty_cycle, [, ], 1  1,
   PARA: unsigned_int16_t Mot_torque_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Mot_mean_value_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: signed_int16_t Mot_signal_gen_amplitude, [, ], 1  1,
   CALL: DMC_Soc_Lat_MOT_Modulation_Torque_step()
   CALL: DMC_Soc_Lat_MOT_Modulation_Torque_initialize(0)
   FILE: DMC_Soc_Lat_MOT_Modulation_Torque.c
 ***************************************************************************************************
 */

/* Block signals (auto storage) */
rtB_DMC_Soc_Lat_MOT_Modulation_Torque_T DMC_Soc_Lat_MOT_Modulation_Torque_B;

/* Block states (auto storage) */
rtDW_DMC_Soc_Lat_MOT_Modulation_Torque_T DMC_Soc_Lat_MOT_Modulation_Torque_DWork;

/* Initial conditions for referenced model: 'DMC_Soc_Lat_MOT_Modulation_Torque' */
void DMC_Soc_Lat_MOT_Modulation_Torque_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_bbni = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_k2sb = 0.0F;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_fnko = 0.0F;
}

/* Output and update for referenced model: 'DMC_Soc_Lat_MOT_Modulation_Torque' */
void DMC_Soc_Lat_MOT_Modulation_Torque(const boolean_T *rt_erh2I, const int16_T *
  rt_gd42I, real32_T *rt_erh2sI)
{
  boolean_T rtb_;
  real32_T rtb_ltjx;
  boolean_T rtb_cf1d;
  real32_T rtb_jcuf;
  real32_T rtb_hmxs;
  uint16_T tmp_;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S14>/Mot_torque_duty_cycle'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  if (DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE < (((real32_T)
        Mot_torque_duty_cycle) * 0.0009765625F)) {
    rtb_ltjx = 1.0F;
  } else {
    rtb_ltjx = -1.0F;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S9>/Mot_signal_gen_amplitude'
   */
  DMC_Soc_Lat_MOT_Modulation_Torque_B.Product = rtb_ltjx * (((real32_T)
    Mot_signal_gen_amplitude) * 0.0009765625F);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S12>/Mot_modulation_duty_cycle'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  if (DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_bbni <
      (((real32_T)Mot_modulation_duty_cycle) * 0.0009765625F)) {
    rtb_ltjx = 1.0F;
  } else {
    rtb_ltjx = -1.0F;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  RelationalOperator: '<S4>/Relational Operator2'
   */
  rtb_ = (boolean_T)((int32_T)(((*rt_gd42I) != ((int16_T)0)) && (((!(*rt_erh2I))
    && ((*rt_gd42I) != ((int16_T)255))) && ((*rt_gd42I) >= ((int16_T)1)))));

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S16>/Compare'
   */
  rtb_cf1d = (boolean_T)((int32_T)((rtb_ltjx > 0.0F) && ((int32_T)rtb_)));

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if ((int32_T)rtb_cf1d) {
    rtb_ltjx = DMC_Soc_Lat_MOT_Modulation_Torque_B.Product;
  } else {
    rtb_ltjx = 0.0F;
  }

  /* End of Switch: '<S6>/Switch' */

  /* MinMax: '<S3>/MinMax' */
  if (rtb_ltjx >= 0.0F) {
  } else {
    rtb_ltjx = 0.0F;
  }

  /* End of MinMax: '<S3>/MinMax' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Gain: '<S3>/Gain'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator'
   */
  if (((int16_T)((*rt_gd42I) & ((int16_T)1))) != ((int16_T)0)) {
    rtb_ltjx = -rtb_ltjx;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S5>/Add1' incorporates:
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_ltjx -= DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_k2sb;

  /* Signum: '<S5>/Sign1' */
  if (rtb_ltjx < 0.0F) {
    rtb_jcuf = -1.0F;
  } else if (rtb_ltjx > 0.0F) {
    rtb_jcuf = 1.0F;
  } else {
    rtb_jcuf = rtb_ltjx;
  }

  /* End of Signum: '<S5>/Sign1' */

  /* Gain: '<S5>/Sac_ts' */
  if (((int32_T)Sac_ts) > ((int32_T)511)) {
    tmp_ = MAX_uint16_T;
  } else {
    tmp_ = (uint16_T)(Sac_ts << ((int8_T)7));
  }

  /* Abs: '<S5>/Abs2' incorporates:
   *  Constant: '<S5>/Mot_torque_gradient'
   *  Gain: '<S5>/Sac_ts'
   *  Product: '<S5>/Product1'
   */
  rtb_hmxs = (real32_T)fabs((real_T)((real32_T)(rtb_jcuf * (((real32_T)
    ((uint32_T)(((uint32_T)tmp_) * ((uint32_T)Mot_torque_gradient)))) *
    2.32830644E-10F))));

  /* Abs: '<S5>/Abs1' */
  rtb_ltjx = (real32_T)fabs((real_T)rtb_ltjx);

  /* MinMax: '<S5>/MinMax' */
  if (rtb_hmxs <= rtb_ltjx) {
    rtb_ltjx = rtb_hmxs;
  }

  /* Sum: '<S5>/Add2' incorporates:
   *  MinMax: '<S5>/MinMax'
   *  Product: '<S5>/Product2'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_k2sb += rtb_jcuf *
    rtb_ltjx;

  /* Sum: '<S2>/Add2' incorporates:
   *  Constant: '<S2>/Mot_mean_value_filter_coeff'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Add1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_fnko +=
    (DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_k2sb -
     DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_fnko) *
    (((real32_T)Mot_mean_value_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<Root>/Add' */
  *rt_erh2sI = DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_k2sb -
    DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_fnko;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  MOT_Modulated_Torque_dbg = (int16_T)((real32_T)floor((*rt_erh2sI) / 0.001F));

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Mot_signal_gen_freq_modulation'
   *  Gain: '<S13>/Sac_Ts'
   *  Sum: '<S13>/Add'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  if ((int32_T)rtb_) {
    rtb_hmxs = ((((real32_T)Sac_ts) * 3.05175781E-5F) * (((real32_T)
      Mot_signal_gen_freq_modulation) * 0.0009765625F)) +
      DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_bbni;
  } else {
    rtb_hmxs = 0.0F;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S13>/Constant3'
   *  RelationalOperator: '<S13>/Relational Operator1'
   */
  if (rtb_hmxs >= 1.0F) {
    /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_bbni = 0.0F;
  } else {
    /* Update for UnitDelay: '<S13>/Unit Delay' */
    DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_bbni = rtb_hmxs;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Mot_signal_gen_frequency_base'
   *  Gain: '<S15>/Sac_ts'
   *  Sum: '<S15>/Add'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  if ((int32_T)rtb_cf1d) {
    rtb_hmxs = ((((real32_T)Sac_ts) * 3.05175781E-5F) * (((real32_T)
      Mot_signal_gen_frequency_base) * 0.0009765625F)) +
      DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE;
  } else {
    rtb_hmxs = 0.0F;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S15>/Constant2'
   *  RelationalOperator: '<S15>/Relational Operator1'
   */
  if (rtb_hmxs >= 1.0F) {
    /* Update for UnitDelay: '<S15>/Unit Delay' incorporates:
     *  Constant: '<S15>/Constant3'
     */
    DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE = 0.0F;
  } else {
    /* Update for UnitDelay: '<S15>/Unit Delay' */
    DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE = rtb_hmxs;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Switch: '<S2>/Switch' */
  if ((int32_T)rtb_cf1d) {
  } else {
    /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
     *  Constant: '<S2>/Constant'
     */
    DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_fnko = 0.0F;
  }

  /* End of Switch: '<S2>/Switch' */
}

/* Model initialize function */
void DMC_Soc_Lat_MOT_Modulation_Torque_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    DMC_Soc_Lat_MOT_Modulation_Torque_B.Product = 0.0F;
  }

  /* states (dwork) */
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_bbni = 0.0F;
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_k2sb = 0.0F;
  DMC_Soc_Lat_MOT_Modulation_Torque_DWork.UnitDelay_DSTATE_fnko = 0.0F;
}
