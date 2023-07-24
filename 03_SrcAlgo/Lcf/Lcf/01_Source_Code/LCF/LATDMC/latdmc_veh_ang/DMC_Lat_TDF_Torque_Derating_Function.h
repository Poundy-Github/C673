/* $Header: DMC_Lat_TDF_Torque_Derating_Function.h 1.24 2020/08/20 10:43:20CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Lat_TDF_Torque_Derating_Function.h
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
#ifndef RTW_HEADER_DMC_Lat_TDF_Torque_Derating_Function_h_
#define RTW_HEADER_DMC_Lat_TDF_Torque_Derating_Function_h_
#include <math.h>
#ifndef DMC_Lat_TDF_Torque_Derating_Function_COMMON_INCLUDES_
# define DMC_Lat_TDF_Torque_Derating_Function_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DMC_Lat_TDF_Torque_Derating_Function_COMMON_INCLUDES_ */

#include "DMC_Lat_TDF_Torque_Derating_Function_types.h"

/* Shared type includes */

#include "look1_ifbu16n6lftu16n10DfIf_binlcs.h"
#include "look1_iflfIs32_binlc.h"
#include "look1_iflf_binlc.h"

/* user code (top of header file) */
#include "dmc_ac.h"

/* Block states (auto storage) for model 'DMC_Lat_TDF_Torque_Derating_Function' */
#ifndef DMC_Lat_TDF_Torque_Derating_Function_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S88>/Unit Delay' */
  real32_T UnitDelay_DSTATE_g1pc;      /* '<S54>/Unit Delay' */
  real32_T UnitDelay_DSTATE_gc34;      /* '<S61>/Unit Delay' */
  real32_T UnitDelay_DSTATE_lcum;      /* '<S39>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ppxw;      /* '<S41>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kyf0;      /* '<S13>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hvql;      /* '<S2>/Unit Delay' */
  real32_T UnitDelay_DSTATE_izut;      /* '<S1>/Unit Delay' */
  real32_T UnitDelay_DSTATE_f5gl;      /* '<S67>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kgpf;      /* '<S69>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mubn;      /* '<S65>/Unit Delay' */
  real32_T UnitDelay_DSTATE_pl4q;      /* '<S23>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mnse;      /* '<S80>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hcxb;      /* '<S22>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ee10;      /* '<S25>/Unit Delay' */
  real32_T UnitDelay_DSTATE_lkk5;      /* '<S73>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ciud;      /* '<S47>/Unit Delay' */
  real32_T UnitDelay_DSTATE_axa2;      /* '<S72>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mkon;      /* '<S84>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S13>/Unit Delay1' */
} rtDW_DMC_Lat_TDF_Torque_Derating_Function_T;

#endif                                 /*DMC_Lat_TDF_Torque_Derating_Function_MDLREF_HIDE_CHILD_*/

extern void DMC_Lat_TDF_Torque_Derating_Function_Init(void);
extern void DMC_Lat_TDF_Torque_Derating_Function(const real32_T *rt_erh2I, const
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
  real32_T *rt_ezus0I, real32_T *rt_orb0mI, real32_T *rt_pdp2qI);

/* Model reference registration function */
extern void DMC_Lat_TDF_Torque_Derating_Function_initialize(void);

#ifndef DMC_Lat_TDF_Torque_Derating_Function_MDLREF_HIDE_CHILD_

/* Block states (auto storage) */
extern rtDW_DMC_Lat_TDF_Torque_Derating_Function_T
  DMC_Lat_TDF_Torque_Derating_Function_DWork;

#endif                                 /*DMC_Lat_TDF_Torque_Derating_Function_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope3' : Unused code path elimination
 * Block '<S3>/Scope4' : Unused code path elimination
 * Block '<S3>/Scope5' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S4>/Scope2' : Unused code path elimination
 * Block '<S23>/Display' : Unused code path elimination
 * Block '<Root>/Switch2' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S7>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S9>/Abs1' : Unused code path elimination
 * Block '<S9>/Display1' : Unused code path elimination
 * Block '<S9>/Display4' : Unused code path elimination
 * Block '<S9>/Relational Operator2' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S9>/Scope11' : Unused code path elimination
 * Block '<S9>/Scope12' : Unused code path elimination
 * Block '<S9>/Scope13' : Unused code path elimination
 * Block '<S9>/Scope14' : Unused code path elimination
 * Block '<S9>/Scope15' : Unused code path elimination
 * Block '<S9>/Scope16' : Unused code path elimination
 * Block '<S9>/Scope17' : Unused code path elimination
 * Block '<S9>/Scope18' : Unused code path elimination
 * Block '<S9>/Scope20' : Unused code path elimination
 * Block '<S9>/Scope4' : Unused code path elimination
 * Block '<S9>/Scope7' : Unused code path elimination
 * Block '<S9>/Scope8' : Unused code path elimination
 * Block '<S9>/Scope9' : Unused code path elimination
 * Block '<S39>/Display' : Unused code path elimination
 * Block '<S33>/Display' : Unused code path elimination
 * Block '<S33>/Display1' : Unused code path elimination
 * Block '<S33>/Scope1' : Unused code path elimination
 * Block '<S33>/Scope2' : Unused code path elimination
 * Block '<S41>/Display' : Unused code path elimination
 * Block '<S34>/Scope1' : Unused code path elimination
 * Block '<S34>/Scope2' : Unused code path elimination
 * Block '<S47>/Display' : Unused code path elimination
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S10>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope2' : Unused code path elimination
 * Block '<S13>/Display12' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S13>/Scope1' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S14>/Scope1' : Unused code path elimination
 * Block '<S14>/Scope2' : Unused code path elimination
 * Block '<S15>/Display' : Unused code path elimination
 * Block '<S15>/Display1' : Unused code path elimination
 * Block '<S15>/Display2' : Unused code path elimination
 * Block '<S15>/Display3' : Unused code path elimination
 * Block '<S15>/Display4' : Unused code path elimination
 * Block '<S15>/Product1' : Unused code path elimination
 * Block '<S15>/Scope1' : Unused code path elimination
 * Block '<S15>/Scope2' : Unused code path elimination
 * Block '<S51>/Display19' : Unused code path elimination
 * Block '<S51>/Scope' : Unused code path elimination
 * Block '<S51>/Tdf_trq_derating_min_init_trq' : Unused code path elimination
 * Block '<S52>/Scope' : Unused code path elimination
 * Block '<S61>/Display' : Unused code path elimination
 * Block '<S53>/Scope' : Unused code path elimination
 * Block '<S53>/Scope1' : Unused code path elimination
 * Block '<S53>/Scope2' : Unused code path elimination
 * Block '<S53>/Scope3' : Unused code path elimination
 * Block '<S54>/Scope' : Unused code path elimination
 * Block '<S54>/Scope1' : Unused code path elimination
 * Block '<S54>/Scope2' : Unused code path elimination
 * Block '<S57>/Scope' : Unused code path elimination
 * Block '<S57>/Scope1' : Unused code path elimination
 * Block '<S59>/Display' : Unused code path elimination
 * Block '<S59>/Display1' : Unused code path elimination
 * Block '<S60>/Scope' : Unused code path elimination
 * Block '<S63>/Display' : Unused code path elimination
 * Block '<S63>/Scope' : Unused code path elimination
 * Block '<S63>/Scope1' : Unused code path elimination
 * Block '<S63>/Scope2' : Unused code path elimination
 * Block '<S16>/Scope' : Unused code path elimination
 * Block '<S16>/Scope1' : Unused code path elimination
 * Block '<S16>/Scope2' : Unused code path elimination
 * Block '<S16>/Scope3' : Unused code path elimination
 * Block '<S16>/Scope4' : Unused code path elimination
 * Block '<S16>/Scope5' : Unused code path elimination
 * Block '<S16>/Scope6' : Unused code path elimination
 * Block '<S66>/Display1' : Unused code path elimination
 * Block '<S69>/Display' : Unused code path elimination
 * Block '<S69>/Display1' : Unused code path elimination
 * Block '<S68>/Display6' : Unused code path elimination
 * Block '<S72>/Display' : Unused code path elimination
 * Block '<S72>/Display1' : Unused code path elimination
 * Block '<S73>/Scope' : Unused code path elimination
 * Block '<S73>/Scope1' : Unused code path elimination
 * Block '<S74>/Display3' : Unused code path elimination
 * Block '<S74>/Display4' : Unused code path elimination
 * Block '<S74>/Scope' : Unused code path elimination
 * Block '<S74>/Scope1' : Unused code path elimination
 * Block '<S75>/Display' : Unused code path elimination
 * Block '<S75>/Scope' : Unused code path elimination
 * Block '<S75>/Scope1' : Unused code path elimination
 * Block '<S75>/Scope2' : Unused code path elimination
 * Block '<S75>/Scope3' : Unused code path elimination
 * Block '<S18>/Add1' : Unused code path elimination
 * Block '<S18>/Constant2' : Unused code path elimination
 * Block '<S18>/Evtl_Nonlinear_Function' : Unused code path elimination
 * Block '<S18>/Product3' : Unused code path elimination
 * Block '<S18>/Scope1' : Unused code path elimination
 * Block '<S18>/Scope2' : Unused code path elimination
 * Block '<S18>/Scope3' : Unused code path elimination
 * Block '<S18>/Scope4' : Unused code path elimination
 * Block '<S80>/Scope' : Unused code path elimination
 * Block '<S80>/Scope1' : Unused code path elimination
 * Block '<S82>/Scope' : Unused code path elimination
 * Block '<S82>/Scope1' : Unused code path elimination
 * Block '<S82>/Scope2' : Unused code path elimination
 * Block '<S83>/Scope' : Unused code path elimination
 * Block '<S83>/Scope1' : Unused code path elimination
 * Block '<S81>/Scope' : Unused code path elimination
 * Block '<S81>/Scope1' : Unused code path elimination
 * Block '<S19>/Scope4' : Unused code path elimination
 * Block '<S84>/Scope' : Unused code path elimination
 * Block '<S84>/Scope1' : Unused code path elimination
 * Block '<S84>/Scope2' : Unused code path elimination
 * Block '<S86>/Display' : Unused code path elimination
 * Block '<S85>/Display1' : Unused code path elimination
 * Block '<S85>/Display2' : Unused code path elimination
 * Block '<S85>/Scope' : Unused code path elimination
 * Block '<S85>/Scope1' : Unused code path elimination
 * Block '<S78>/Display' : Unused code path elimination
 * Block '<S79>/Scope' : Unused code path elimination
 * Block '<S79>/Scope1' : Unused code path elimination
 * Block '<S79>/Scope2' : Unused code path elimination
 * Block '<S21>/Display' : Unused code path elimination
 * Block '<S88>/Display' : Unused code path elimination
 * Block '<S21>/Scope' : Unused code path elimination
 * Block '<S21>/Scope1' : Unused code path elimination
 * Block '<S21>/Scope2' : Unused code path elimination
 * Block '<S21>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S9>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S33>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Lpf' : Eliminated nontunable gain of 1
 * Block '<S83>/TDF_Switch_Falling_Rate' : Eliminated nontunable gain of 1
 * Block '<S83>/TDF_Switch_Rising_Rate' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DMC_Lat_TDF_Torque_Derating_Function'
 * '<S1>'   : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Pt1_Filter_Default_1_Dual_Slope'
 * '<S2>'   : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Pt1_Filter_Default_1_Single_Slope'
 * '<S3>'   : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Sac_Integ_Limit_Scale'
 * '<S4>'   : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Saturation_Derating_Factor'
 * '<S5>'   : 'DMC_Lat_TDF_Torque_Derating_Function/SAC_Variable_Stiffness_Definition'
 * '<S6>'   : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Composite_Derating_Factor'
 * '<S7>'   : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Derating_Mode'
 * '<S8>'   : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Dos_Limit_Scale'
 * '<S9>'   : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification'
 * '<S10>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_EPS_Torque_Request'
 * '<S11>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Feed_Forward_Torque_Derating'
 * '<S12>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Idle_Control_Derating'
 * '<S13>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Integrator_Reset_Condition'
 * '<S14>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Integrator_Derating'
 * '<S15>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating'
 * '<S16>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating'
 * '<S17>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Load_Compensation_Derating'
 * '<S18>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Requested_Damping_Level'
 * '<S19>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating'
 * '<S20>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Supportive_Steering'
 * '<S21>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Unbalance_Compensation'
 * '<S22>'  : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Saturation_Derating_Factor/TDF_Raw_Saturation_Derating_Factor'
 * '<S23>'  : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Saturation_Derating_Factor/TDF_Saturation_Derating_Factor'
 * '<S24>'  : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Saturation_Derating_Factor/TDF_Raw_Saturation_Derating_Factor/TDF_Saturation'
 * '<S25>'  : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Saturation_Derating_Factor/TDF_Saturation_Derating_Factor/LAT_Derating_Factor_Filter'
 * '<S26>'  : 'DMC_Lat_TDF_Torque_Derating_Function/LAT_Saturation_Derating_Factor/TDF_Saturation_Derating_Factor/TDF_Saturation'
 * '<S27>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/LAT_Derating_Level_Fading'
 * '<S28>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/LAT_Torque_Saturation_Scaling'
 * '<S29>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/LDP_Left_Lane_Mode_Selection'
 * '<S30>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn'
 * '<S31>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn1'
 * '<S32>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn2'
 * '<S33>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_State_Derating_Factor_Selection'
 * '<S34>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Torque_Request_Factor'
 * '<S35>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Vehicle_Steer_Torque_Compensation_Fcator'
 * '<S36>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Vehicle_Steer_Torque_Factor'
 * '<S37>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn/TDF_Torque_Request_Factor_Saturation'
 * '<S38>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn1/TDF_Torque_Request_Factor_Saturation'
 * '<S39>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn2/LAT_Pt1_Filter'
 * '<S40>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Pac_Control_State_Membship_Fcn2/TDF_Torque_Request_Factor_Saturation1'
 * '<S41>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Torque_Request_Factor/LAT_Pt1_Filter'
 * '<S42>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Torque_Request_Factor/TDF_Torque_Request_Factor_Saturation'
 * '<S43>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Vehicle_Steer_Torque_Compensation_Fcator/TDF_Slope_Factor_Selection'
 * '<S44>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Vehicle_Steer_Torque_Compensation_Fcator/TDF_Vehicle_Steer_Torque_Comp_Factor_Saturation'
 * '<S45>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Vehicle_Steer_Torque_Factor/TDF_Vehicle_Steer_Torque_Factor_Saturation'
 * '<S46>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Driver_Steer_Classification/TDF_Vehicle_Steer_Torque_Factor/TDF_Vehicle_Steer_Torque_Factor_Saturation1'
 * '<S47>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_EPS_Torque_Request/LAT_Eps_Torque_Filter'
 * '<S48>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Idle_Control_Derating/Encoder'
 * '<S49>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Idle_Control_Derating/TDF_Idle_Mono_Flop'
 * '<S50>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/LAT_Derating_Level_Fading'
 * '<S51>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Initial_Driver_Torque'
 * '<S52>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Ldp_Threshold_Fading'
 * '<S53>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Maximum_Steering_Torque'
 * '<S54>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Steer_Troque_Sample'
 * '<S55>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Factor '
 * '<S56>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Factor 1'
 * '<S57>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Factor_Higher_Frequency_Path'
 * '<S58>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Slope'
 * '<S59>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Slope1'
 * '<S60>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Threshold'
 * '<S61>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Maximum_Steering_Torque/LAT_Pt1_Filter'
 * '<S62>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Slope/TDF_Torque_Derating_Slope_Selection'
 * '<S63>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Threshold/TDF_Torque_Derating_Threshold_Scheduling'
 * '<S64>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Torque_Derating/TDF_Torque_Derating_Threshold/TDF_Torque_Derating_Threshold_Selection'
 * '<S65>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/LAT_Pt1_Filter'
 * '<S66>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Control_Error_Factor'
 * '<S67>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Saturated_Angle_Command_Error'
 * '<S68>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Velocity_Factor'
 * '<S69>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Control_Error_Factor/LAT_Pt1_Dual_Slope_Filter'
 * '<S70>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Control_Error_Factor/TDF_Saturation'
 * '<S71>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Saturated_Angle_Command_Error/TDF_Saturation'
 * '<S72>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Linear_Velocity_Derating/TDF_Velocity_Factor/LAT_Pt1_Dual_Slope_Filter'
 * '<S73>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Load_Compensation_Derating/LAT_Pt1_Filter_Dual_Slope'
 * '<S74>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Load_Compensation_Derating/SAC_Variable_Stiffness_Definition'
 * '<S75>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Load_Compensation_Derating/TDF_Compensation_Factor_Fading'
 * '<S76>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/LAT_Rate_Limited_Switch'
 * '<S77>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_Driver_Torque_Detection'
 * '<S78>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_Saturation'
 * '<S79>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_State_Derating_Factor_Selection'
 * '<S80>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/LAT_Rate_Limited_Switch/TDF_State_Derating_Integration'
 * '<S81>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/LAT_Rate_Limited_Switch/TDF_State_Derating_Mode'
 * '<S82>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/LAT_Rate_Limited_Switch/TDF_State_Derating_Integration/TDF_Switch_Rate_Mode'
 * '<S83>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/LAT_Rate_Limited_Switch/TDF_State_Derating_Integration/TDF_Switch_Rate_Selection'
 * '<S84>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_Driver_Torque_Detection/TDF_State_Der_Active'
 * '<S85>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_Driver_Torque_Detection/TDF_State_Derating'
 * '<S86>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_Driver_Torque_Detection/TDF_State_Der_Active/TDF_Saturation'
 * '<S87>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_State_Derating/TDF_State_Derating_Factor_Selection/Compare To Constant'
 * '<S88>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Unbalance_Compensation/LAT_Pt1_Filter'
 * '<S89>'  : 'DMC_Lat_TDF_Torque_Derating_Function/TDF_Unbalance_Compensation/TDF_Steering_Angle_Saturation'
 */

/*-
 * Requirements for '<Root>': DMC_Lat_TDF_Torque_Derating_Function
 *  1. Steer torque sample
 *  2. Threshold fading
 */
#endif                                 /* RTW_HEADER_DMC_Lat_TDF_Torque_Derating_Function_h_ */
