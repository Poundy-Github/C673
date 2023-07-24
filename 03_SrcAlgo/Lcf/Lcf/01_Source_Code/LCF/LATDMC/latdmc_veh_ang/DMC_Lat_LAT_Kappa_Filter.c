/* $Header: DMC_Lat_LAT_Kappa_Filter.c 1.26 2020/08/20 10:42:58CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_LAT_Kappa_Filter.c
   C source code generated on           : Mon Aug 17 20:47:04 2020
   Filename of Simulink Model           : DMC_Lat_LAT_Kappa_Filter.mdl/.slx
   Revision of Simulink Model           : 1.266
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
#include "DMC_Lat_LAT_Kappa_Filter.h"
#include "DMC_Lat_LAT_Kappa_Filter_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: unsigned_int16_t Lat_kappa_discharge_slope, [, ], 1  1,
   PARA: signed_int16_t Lat_kappa_discharge_min_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_direct_feedthrough_kappa, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_discharge_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_gradient_aes, [, ], 1  1,
   PARA: unsigned_int16_t Lat_max_kappa_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_lateral_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_max_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_max_kappa_grad_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_max_kappa_grad_x_scheduling, [, ], 1  12,
   CALL: DMC_Lat_LAT_Kappa_Filter_step()
   CALL: DMC_Lat_LAT_Kappa_Filter_initialize(0)
   FILE: DMC_Lat_LAT_Kappa_Filter.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_LAT_Kappa_Filter_T DMC_Lat_LAT_Kappa_Filter_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_LAT_Kappa_Filter' */
void DMC_Lat_LAT_Kappa_Filter_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE_afmt = 0.0F;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay (1)' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay (2)' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay (3)' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay3_DSTATE = 0.0F;
}

/* Output and update for referenced model: 'DMC_Lat_LAT_Kappa_Filter' */
void DMC_Lat_LAT_Kappa_Filter(const real32_T *rt_erh2I, const boolean_T
  *rt_gd42I, const real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const boolean_T
  *rt_ngfdI, const boolean_T *rt_f3r3I, const real32_T *rt_kkebI, const
  boolean_T *rt_hny3I, real32_T *rt_erh2sI)
{
  uint16_T tmp_;
  real32_T rtb_;
  real32_T rtb_ov5i;
  real32_T rtb_filh;
  real32_T rtb_mctr;
  real32_T rtb_pbw3;

  /* Switch: '<S1>/Switch' */
  if ((int32_T)(*rt_gd42I)) {
    rtb_ = *rt_erh2I;
  } else {
    rtb_ = *rt_kkebI;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Sum: '<S4>/Add (1)' incorporates:
   *  Constant: '<S4>/Lat_kappa_filter_coeff'
   *  Product: '<S4>/Product'
   *  Sum: '<S4>/Sub'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE += (rtb_ -
    DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE) * (((real32_T)
    Lat_kappa_filter_coeff) * 3.05175781E-5F);

  /* Sum: '<S23>/Sub' incorporates:
   *  UnitDelay: '<S23>/Unit Delay'
   */
  rtb_ = DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE -
    DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE_afmt;

  /* Abs: '<S5>/Abs' */
  rtb_ov5i = (real32_T)fabs((real_T)rtb_);

  /* Switch: '<S31>/Switch (1)' incorporates:
   *  Constant: '<S31>/Lat_kappa_gradient_aes'
   *  Constant: '<S31>/Lat_kappa_gradient_ldp'
   */
  if ((int32_T)(*rt_hny3I)) {
    rtb_pbw3 = ((real32_T)Lat_kappa_gradient_aes) * 3.05175781E-5F;
  } else {
    rtb_pbw3 = 1.0F;
  }

  /* End of Switch: '<S31>/Switch (1)' */

  /* MinMax: '<S29>/MinMax' incorporates:
   *  Constant: '<S29>/Lat_kappa_discharge_gradient'
   *  Constant: '<S29>/Lat_max_kappa_gradient'
   */
  if (Lat_max_kappa_gradient >= Lat_kappa_discharge_gradient) {
    tmp_ = Lat_max_kappa_gradient;
  } else {
    tmp_ = Lat_kappa_discharge_gradient;
  }

  /* Sum: '<S28>/Sub (2)' incorporates:
   *  Constant: '<S28>/Lat_kappa_discharge_min_error'
   */
  rtb_filh = rtb_ov5i - (((real32_T)Lat_kappa_discharge_min_error) * 2.0E-5F);

  /* MinMax: '<S28>/MinMax (2)' */
  if (0.0F >= rtb_filh) {
    rtb_filh = 0.0F;
  }

  /* Gain: '<S28>/Lat_kappa_discharge_slope' incorporates:
   *  MinMax: '<S28>/MinMax (2)'
   */
  rtb_mctr = ((real32_T)Lat_kappa_discharge_slope) * rtb_filh;

  /* MinMax: '<S28>/MinMax (4)'
   *
   * Block requirements for '<S28>/MinMax (4)':
   *  1. Minimum Lateral Error
   */
  if (rtb_mctr <= 1.0F) {
  } else {
    rtb_mctr = 1.0F;
  }

  /* Sum: '<S28>/Sub (1)' incorporates:
   *  Abs: '<S28>/Abs'
   *  Constant: '<S28>/Lat_kappa_max_lateral_error'
   */
  rtb_filh = ((real32_T)fabs((real_T)(*rt_e4hoI))) - (((real32_T)
    Lat_kappa_max_lateral_error) * 0.0009765625F);

  /* MinMax: '<S28>/MinMax (1)' */
  if (0.0F >= rtb_filh) {
    rtb_filh = 0.0F;
  }

  /* Gain: '<S28>/Lat_kappa_lateral_error_slope' incorporates:
   *  MinMax: '<S28>/MinMax (1)'
   */
  rtb_filh *= ((real32_T)Lat_kappa_lateral_error_slope) * 0.0009765625F;

  /* MinMax: '<S28>/MinMax (3)'
   *
   * Block requirements for '<S28>/MinMax (3)':
   *  1. Minimum Lateral Error
   */
  if (rtb_filh <= 1.0F) {
  } else {
    rtb_filh = 1.0F;
  }

  /* Product: '<S28>/Product' incorporates:
   *  MinMax: '<S28>/MinMax (3)'
   *  MinMax: '<S28>/MinMax (4)'
   *
   * Block requirements for '<S28>/MinMax (3)':
   *  1. Minimum Lateral Error
   *
   * Block requirements for '<S28>/MinMax (4)':
   *  1. Minimum Lateral Error
   */
  rtb_filh *= rtb_mctr;

  /* Lookup_n-D: '<S29>/LAT_Max_Kappa_Grad_Scheduling' incorporates:
   *  Gain: '<S29>/Gain'
   */
  rtb_mctr = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_cpaoI),
    (&(Lat_max_kappa_grad_x_scheduling[0])), (&(Lat_max_kappa_grad_y_scheduling
    [0])), 11U);

  /* Switch: '<S31>/Switch (2)' incorporates:
   *  Constant: '<S29>/Lat_max_kappa_gradient'
   *  Constant: '<S30>/Constant'
   *  Logic: '<S31>/Logical Operator'
   *  MinMax: '<S29>/MinMax'
   *  Product: '<S29>/Product'
   *  Product: '<S30>/Product (1)'
   *  Product: '<S30>/Product (2)'
   *  Sum: '<S30>/Add'
   *  Sum: '<S30>/Sub'
   */
  if ((((int32_T)(*rt_f3r3I)) || ((int32_T)(*rt_ngfdI))) || ((int32_T)(*rt_hny3I)))
  {
  } else {
    rtb_pbw3 = ((((real32_T)tmp_) * 3.05175781E-5F) * rtb_filh) + ((rtb_mctr *
      (((real32_T)Lat_max_kappa_gradient) * 3.05175781E-5F)) * (1.0F - rtb_filh));
  }

  /* End of Switch: '<S31>/Switch (2)' */

  /* Gain: '<S31>/Sac_ts'
   *
   * Block description for '<S31>/Sac_ts':
   *  u: seconds
   */
  rtb_pbw3 *= ((real32_T)Sac_ts) * 3.05175781E-5F;

  /* Sum: '<S5>/Sub' */
  rtb_filh = rtb_ov5i - rtb_pbw3;

  /* MinMax: '<S25>/Max' */
  if (rtb_filh >= 0.0F) {
  } else {
    rtb_filh = 0.0F;
  }

  /* End of MinMax: '<S25>/Max' */

  /* Signum: '<S23>/Sign' */
  if (rtb_ < 0.0F) {
    rtb_ = -1.0F;
  } else {
    if (rtb_ > 0.0F) {
      rtb_ = 1.0F;
    }
  }

  /* End of Signum: '<S23>/Sign' */

  /* Product: '<S23>/Product (1)' */
  rtb_pbw3 *= rtb_;

  /* Abs: '<S23>/Abs' */
  rtb_pbw3 = (real32_T)fabs((real_T)rtb_pbw3);

  /* MinMax: '<S23>/MinMax' */
  if (rtb_pbw3 <= rtb_ov5i) {
    rtb_ov5i = rtb_pbw3;
  }

  /* Sum: '<S23>/Add' incorporates:
   *  MinMax: '<S23>/MinMax'
   *  Product: '<S23>/Product (2)'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE_afmt += rtb_ * rtb_ov5i;

  /* MinMax: '<S25>/Min' incorporates:
   *  Constant: '<S25>/Lat_direct_feedthrough_kappa'
   */
  rtb_mctr = ((real32_T)Lat_direct_feedthrough_kappa) * 3.05175781E-5F;
  if (rtb_mctr <= rtb_filh) {
    rtb_filh = rtb_mctr;
  }

  /* Sum: '<S5>/Add' incorporates:
   *  MinMax: '<S25>/Min'
   *  Product: '<S5>/Product'
   */
  *rt_erh2sI = (rtb_filh * rtb_) +
    DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE_afmt;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  LAT_Kappa_Filter_Output_dbg = (int16_T)((real32_T)floor((*rt_erh2sI) / 2.0E-5F));

  /* UnitDelay: '<S26>/Unit Delay (1)' */
  rtb_filh = DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay1_DSTATE;

  /* UnitDelay: '<S26>/Unit Delay (2)' */
  rtb_mctr = DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay2_DSTATE;

  /* Switch: '<S23>/Switch' */
  if ((int32_T)(*rt_gd42I)) {
  } else {
    /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
     *  Gain: '<S26>/Gain'
     *  Sum: '<S26>/Add'
     *  UnitDelay: '<S26>/Unit Delay (1)'
     *  UnitDelay: '<S26>/Unit Delay (2)'
     *  UnitDelay: '<S26>/Unit Delay (3)'
     */
    DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE_afmt = 0.25F *
      (((DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE +
         DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay1_DSTATE) +
        DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay2_DSTATE) +
       DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay3_DSTATE);
  }

  /* End of Switch: '<S23>/Switch' */

  /* Update for UnitDelay: '<S26>/Unit Delay (1)' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay1_DSTATE =
    DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S26>/Unit Delay (2)' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay2_DSTATE = rtb_filh;

  /* Update for UnitDelay: '<S26>/Unit Delay (3)' */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay3_DSTATE = rtb_mctr;
}

/* Model initialize function */
void DMC_Lat_LAT_Kappa_Filter_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay_DSTATE_afmt = 0.0F;
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay1_DSTATE = 0.0F;
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay2_DSTATE = 0.0F;
  DMC_Lat_LAT_Kappa_Filter_DWork.UnitDelay3_DSTATE = 0.0F;
}
