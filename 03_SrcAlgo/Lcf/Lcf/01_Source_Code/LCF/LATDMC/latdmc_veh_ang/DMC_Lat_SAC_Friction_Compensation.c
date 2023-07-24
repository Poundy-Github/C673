/* $Header: DMC_Lat_SAC_Friction_Compensation.c 1.22 2020/08/20 10:43:10CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_SAC_Friction_Compensation.c
   C source code generated on           : Mon Aug 17 20:47:42 2020
   Filename of Simulink Model           : DMC_Lat_SAC_Friction_Compensation.mdl/.slx
   Revision of Simulink Model           : 1.2315
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
#include "DMC_Lat_SAC_Friction_Compensation.h"
#include "DMC_Lat_SAC_Friction_Compensation_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   PARA: signed_int16_t Sac_one_by_ts, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_activ_source, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_6, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_7, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_comp_b1_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_comp_omega, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_static_friction_torque, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_torque_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_linear_slope, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_torque, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_friction_comp_x_scheduling, [, ], 1  12,
   PARA: signed_int16_t Sac_friction_comp_torque_cw, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_error_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_control_error_gain, [, ], 1  1,
   CALL: DMC_Lat_SAC_Friction_Compensation_step()
   CALL: DMC_Lat_SAC_Friction_Compensation_initialize(0)
   FILE: DMC_Lat_SAC_Friction_Compensation.c
 ***************************************************************************************************
 */

/* Block states (auto storage) */
rtDW_DMC_Lat_SAC_Friction_Compensation_T DMC_Lat_SAC_Friction_Compensation_DWork;

/* Initial conditions for referenced model: 'DMC_Lat_SAC_Friction_Compensation' */
void DMC_Lat_SAC_Friction_Compensation_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_pcsn = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_mkix = 0.0F;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_keg1 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S90>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_ieql = 0.0F;

  /* InitializeConditions for UnitDelay: '<S88>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_fgwe = 0.0F;
}

/* Output and update for referenced model: 'DMC_Lat_SAC_Friction_Compensation' */
void DMC_Lat_SAC_Friction_Compensation(const real32_T *rt_erh2I, const uint32_T *
  rt_gd42I, const real32_T *rt_cpaoI, const real32_T *rt_e4hoI, const boolean_T *
  rt_ngfdI, const real32_T *rt_f3r3I, real32_T *rt_erh2sI)
{
  real32_T rtb_;
  real32_T rtb_kpvz;
  real32_T rtb_pglt;
  real32_T rtb_fonk;
  uint16_T rtb_ctdt;

  /* Lookup_n-D: '<Root>/SAC_Friction_Comp_Scheduling' incorporates:
   *  Gain: '<Root>/Gain'
   */
  rtb_ = look1_ifbu16n6lftu16n10DfIf_binlcs(3.6F * (*rt_cpaoI),
    (&(Sac_friction_comp_x_scheduling[0])), (&(Sac_friction_comp_y_scheduling[0])),
    11U);

  /* Gain: '<S10>/SAC_Frequency' incorporates:
   *  Sum: '<S10>/Add'
   *  UnitDelay: '<S10>/Unit Delay'
   */
  rtb_kpvz = ((real32_T)Sac_one_by_ts) * ((*rt_e4hoI) -
    DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE);

  /* Gain: '<S2>/SAC_Frequency' incorporates:
   *  Sum: '<S2>/Add'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_pglt = ((real32_T)Sac_one_by_ts) * ((*rt_erh2I) -
    DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_pcsn);

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Constant: '<S9>/Sac_friction_comp_activ_source'
   */
  if (((real32_T)Sac_friction_comp_activ_source) > 4.0F) {
    rtb_fonk = 4.0F;
  } else if (((real32_T)Sac_friction_comp_activ_source) < 1.0F) {
    rtb_fonk = 1.0F;
  } else {
    rtb_fonk = (real32_T)Sac_friction_comp_activ_source;
  }

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Gain: '<S3>/SAC_Frequency'
   *  Gain: '<S9>/VEH_Delta_F_Cmd_Weight'
   *  Gain: '<S9>/VEH_Delta_F_Dot_Weight'
   *  Saturate: '<S9>/Saturation'
   *  Sum: '<S3>/Add'
   *  Sum: '<S9>/Add'
   *  UnitDelay: '<S3>/Unit Delay'
   *
   * Block requirements for '<S9>/Multiport Switch':
   *  1. Slope Source Selection (1)
   *  2. Slope Source Selection (2)
   *  3. Slope Source Selection (3)
   */
  switch ((int32_T)rtb_fonk) {
   case 1:
    break;

   case 2:
    rtb_kpvz = rtb_pglt;
    break;

   case 3:
    rtb_kpvz = (0.5F * rtb_kpvz) + (0.5F * rtb_pglt);
    break;

   default:
    rtb_kpvz = ((real32_T)Sac_one_by_ts) * ((*rt_f3r3I) -
      DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_mkix);
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* Sum: '<S8>/Add1' incorporates:
   *  UnitDelay: '<S8>/Unit Delay'
   */
  rtb_kpvz -= DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_keg1;

  /* Sum: '<S8>/Add2' incorporates:
   *  Constant: '<S8>/Sac_pt1_filter_coeff_6'
   *  Product: '<S8>/Product'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_keg1 += rtb_kpvz *
    (((real32_T)Sac_pt1_filter_coeff_6) * 3.05175781E-5F);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Sac_friction_comp_torque'
   *  Constant: '<S5>/Sac_friction_comp_torque_cw'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_keg1 >= 0.0F) {
    rtb_ctdt = Sac_friction_comp_torque;
  } else {
    rtb_ctdt = (uint16_T)Sac_friction_comp_torque_cw;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S7>/Add2' incorporates:
   *  Gain: '<S7>/Sac_friction_comp_error_gain'
   *  Gain: '<S7>/Sac_friction_comp_linear_slope'
   *  Gain: '<S7>/Sac_friction_control_error_gain'
   */
  rtb_pglt = ((((real32_T)Sac_friction_comp_error_gain) * 0.03125F) *
              ((((real32_T)Sac_friction_comp_linear_slope) * 0.0009765625F) *
               DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_keg1)) +
    ((((real32_T)Sac_friction_control_error_gain) * 0.03125F) * (*rt_f3r3I));

  /* Saturate: '<S7>/Saturation' */
  if (rtb_pglt > 1.0F) {
    rtb_pglt = 1.0F;
  } else {
    if (rtb_pglt < -1.0F) {
      rtb_pglt = -1.0F;
    }
  }

  /* Gain: '<S87>/Sac_frc_comp_omega' incorporates:
   *  Product: '<Root>/Product'
   *  Saturate: '<S7>/Saturation'
   *  Sum: '<S87>/Sub'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  rtb_fonk = (((real32_T)Sac_frc_comp_omega) * 0.0009765625F) * (((rtb_ *
    (((real32_T)rtb_ctdt) * 0.0009765625F)) * rtb_pglt) -
    DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_ieql);

  /* Sum: '<S88>/Add2' incorporates:
   *  Constant: '<S88>/Sac_pt1_filter_coeff_7'
   *  DataTypeConversion: '<S88>/Data Type Conversion'
   *  Gain: '<S87>/Sac_frc_comp_b1_factor'
   *  Gain: '<S87>/Sac_frc_torque_corr_factor'
   *  Product: '<S88>/Product'
   *  Sum: '<S87>/Add'
   *  Sum: '<S88>/Add1'
   *  UnitDelay: '<S88>/Unit Delay'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_fgwe +=
    ((((((real32_T)Sac_frc_comp_b1_factor) * 0.0009765625F) * rtb_fonk) +
      ((((real32_T)Sac_frc_torque_corr_factor) * 0.0009765625F) *
       DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_ieql)) -
     DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_fgwe) *
    (((real32_T)Sac_pt1_filter_coeff_7) * 3.05175781E-5F);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S91>/Compare'
   *  RelationalOperator: '<S92>/Compare'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator2'
   */
  if (((((*rt_gd42I) & ((uint32_T)1024U)) == ((uint32_T)1024U)) || (((*rt_gd42I)
         & ((uint32_T)7U)) == ((uint32_T)0U))) || ((int32_T)(*rt_ngfdI))) {
    *rt_erh2sI = 0.0F;
  } else {
    /* DataTypeConversion: '<S89>/Data Type Conversion' incorporates:
     *  Constant: '<S89>/Sac_frc_static_friction_torque'
     */
    rtb_pglt = ((real32_T)Sac_frc_static_friction_torque) * 0.0009765625F;

    /* MinMax: '<S89>/MinMax1' */
    if (DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_fgwe <=
        rtb_pglt) {
      rtb_pglt = DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_fgwe;
    }

    /* End of MinMax: '<S89>/MinMax1' */

    /* Gain: '<S89>/Gain' incorporates:
     *  Constant: '<S89>/Sac_frc_static_friction_torque'
     *  DataTypeConversion: '<S89>/Data Type Conversion'
     */
    *rt_erh2sI = -(((real32_T)Sac_frc_static_friction_torque) * 0.0009765625F);

    /* MinMax: '<S89>/MinMax2' */
    if (rtb_pglt >= (*rt_erh2sI)) {
      *rt_erh2sI = rtb_pglt;
    }

    /* End of MinMax: '<S89>/MinMax2' */
  }

  /* End of Switch: '<S6>/Switch' */

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE = *rt_e4hoI;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_pcsn = *rt_erh2I;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_mkix = *rt_f3r3I;

  /* Update for UnitDelay: '<S90>/Unit Delay' incorporates:
   *  Gain: '<S90>/Sac_ts'
   *  Sum: '<S90>/Add'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_ieql += (((real32_T)
    Sac_ts) * 3.05175781E-5F) * rtb_fonk;
}

/* Model initialize function */
void DMC_Lat_SAC_Friction_Compensation_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE = 0.0F;
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_pcsn = 0.0F;
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_mkix = 0.0F;
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_keg1 = 0.0F;
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_ieql = 0.0F;
  DMC_Lat_SAC_Friction_Compensation_DWork.UnitDelay_DSTATE_fgwe = 0.0F;
}
