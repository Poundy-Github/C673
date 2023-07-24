/* $Header: DMC_Soc_Lat_SAC_Damping_Filter.h 1.4 2020/08/20 10:43:41CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc_Lat_SAC_Damping_Filter.h
   C source code generated on           : Mon Aug 17 20:49:04 2020
   Filename of Simulink Model           : DMC_Soc_Lat_SAC_Damping_Filter.mdl/.slx
   Revision of Simulink Model           : 1.19
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
#ifndef RTW_HEADER_DMC_Soc_Lat_SAC_Damping_Filter_h_
#define RTW_HEADER_DMC_Soc_Lat_SAC_Damping_Filter_h_
#include <math.h>
#ifndef DMC_Soc_Lat_SAC_Damping_Filter_COMMON_INCLUDES_
# define DMC_Soc_Lat_SAC_Damping_Filter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DMC_Soc_Lat_SAC_Damping_Filter_COMMON_INCLUDES_ */

#include "DMC_Soc_Lat_SAC_Damping_Filter_types.h"

/* Shared type includes */

#include "look1_ifbu16n6lftu16n10DfIf_binlcs.h"

/* user code (top of header file) */
#include "dmc_ac.h"

/* Block states (auto storage) for model 'DMC_Soc_Lat_SAC_Damping_Filter' */
#ifndef DMC_Soc_Lat_SAC_Damping_Filter_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S6>/Unit Delay' */
  real32_T UnitDelay_DSTATE_l0ga;      /* '<S14>/Unit Delay' */
} rtDW_DMC_Soc_Lat_SAC_Damping_Filter_T;

#endif                                 /*DMC_Soc_Lat_SAC_Damping_Filter_MDLREF_HIDE_CHILD_*/

extern void DMC_Soc_Lat_SAC_Damping_Filter_Init(void);
extern void DMC_Soc_Lat_SAC_Damping_Filter(const real32_T *rt_erh2I, const
  real32_T *rt_gd42I, const uint32_T *rt_cpaoI, const real32_T *rt_e4hoI, const
  uint16_T *rt_ngfdI, const boolean_T *rt_f3r3I, const boolean_T *rt_kkebI,
  real32_T *rt_erh2sI);

/* Model reference registration function */
extern void DMC_Soc_Lat_SAC_Damping_Filter_initialize(void);

#ifndef DMC_Soc_Lat_SAC_Damping_Filter_MDLREF_HIDE_CHILD_

/* Block states (auto storage) */
extern rtDW_DMC_Soc_Lat_SAC_Damping_Filter_T
  DMC_Soc_Lat_SAC_Damping_Filter_DWork;

#endif                                 /*DMC_Soc_Lat_SAC_Damping_Filter_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope (1)' : Unused code path elimination
 * Block '<S1>/Scope (2)' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S4>/Display (1)' : Unused code path elimination
 * Block '<S4>/Display (2)' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S5>/Display' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S6>/Display' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
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
 * '<Root>' : 'DMC_Soc_Lat_SAC_Damping_Filter'
 * '<S1>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Control_Error_Membership_Selection'
 * '<S2>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Damping_Angle_Command_Computation'
 * '<S3>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Differential_Gain_Factor'
 * '<S4>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Differential_Gain_Factor_Fading'
 * '<S5>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Filter_Coefficient_Fading'
 * '<S6>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Steer_Angle_Rate_Estimation_and_Filtering'
 * '<S7>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Control_Error_Membership_Selection/Compare To Constant'
 * '<S8>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Control_Error_Membership_Selection/System Requirements'
 * '<S9>'   : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Damping_Angle_Command_Computation/SAC_Debug_Signal'
 * '<S10>'  : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Damping_Angle_Command_Computation/System Requirements'
 * '<S11>'  : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Differential_Gain_Factor/System Requirements'
 * '<S12>'  : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Differential_Gain_Factor_Fading/System Requirements'
 * '<S13>'  : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Filter_Coefficient_Fading/System Requirements'
 * '<S14>'  : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Steer_Angle_Rate_Estimation_and_Filtering/SAC_PT1_Filter'
 * '<S15>'  : 'DMC_Soc_Lat_SAC_Damping_Filter/SAC_Steer_Angle_Rate_Estimation_and_Filtering/System Requirements'
 */

/*-
 * Requirements for '<Root>': DMC_Soc_Lat_SAC_Damping_Filter
 */
#endif                                 /* RTW_HEADER_DMC_Soc_Lat_SAC_Damping_Filter_h_ */
