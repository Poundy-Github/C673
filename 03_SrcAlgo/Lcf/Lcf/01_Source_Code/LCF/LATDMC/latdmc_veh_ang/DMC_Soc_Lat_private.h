/* $Header: DMC_Soc_Lat_private.h 1.62 2020/08/20 10:43:39CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc_Lat_private.h
   C source code generated on           : Wed Aug 19 16:25:20 2020
   Filename of Simulink Model           : DMC_Soc_Lat.mdl/.slx
   Revision of Simulink Model           : 1.4551
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
#ifndef RTW_HEADER_DMC_Soc_Lat_private_h_
#define RTW_HEADER_DMC_Soc_Lat_private_h_
#include "rtwtypes.h"


/* Includes for objects with custom storage classes. */
#include "dmc_ac.h"

/* Disable QAC for word size consistence check using limits.h ==> */
/* PRQA S 1-65535 LABEL_QAC_PRIVATE */
#ifndef PORTABLE_WORDSIZES
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif                                 /* PORTABLE_WORDSIZES */

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/LAT_Kappa_Dot_Filter_Coeff'
   *   '<S6>/Constant5'
   *   '<S13>/Constant'
   *   '<S13>/Constant10'
   *   '<S13>/Constant12'
   *   '<S13>/Constant14'
   *   '<S13>/Constant16'
   *   '<S13>/Constant18'
   *   '<S13>/Constant2'
   *   '<S13>/Constant4'
   *   '<S13>/Constant6'
   *   '<S13>/Constant8'
   *   '<S22>/Constant'
   *   '<S29>/Constant2'
   *   '<S498>/Constant'
   *   '<S46>/Constant1'
   *   '<S46>/Constant10'
   *   '<S221>/Constant1'
   *   '<S221>/Constant10'
   *   '<S221>/Constant4'
   *   '<S222>/Constant'
   *   '<S222>/Constant10'
   *   '<S222>/Constant12'
   *   '<S222>/Constant14'
   *   '<S222>/Constant16'
   *   '<S222>/Constant18'
   *   '<S222>/Constant2'
   *   '<S222>/Constant4'
   *   '<S222>/Constant6'
   *   '<S222>/Constant8'
   *   '<S224>/Constant3'
   *   '<S230>/Constant2'
   *   '<S230>/Constant4'
   *   '<S250>/Constant1'
   *   '<S250>/Saturation2'
   *   '<S252>/Constant1'
   *   '<S282>/Constant1'
   *   '<S282>/Constant3'
   *   '<S282>/Constant4'
   *   '<S282>/Constant6'
   *   '<S298>/Constant'
   *   '<S298>/Constant1'
   *   '<S462>/Saturation'
   *   '<S462>/Saturation2'
   *   '<S488>/Constant1'
   *   '<S488>/Constant5'
   *   '<S488>/Constant6'
   *   '<S488>/Lat_pre_trigger_time'
   *   '<S68>/Constant5'
   *   '<S162>/Min_CAM_Lateral_Error_Qualifier'
   *   '<S256>/Constant5'
   *   '<S257>/Constant1'
   *   '<S257>/Constant4'
   *   '<S261>/Constant1'
   *   '<S261>/Constant2'
   *   '<S264>/Constant2'
   *   '<S278>/MaxLim'
   *   '<S466>/Constant'
   *   '<S478>/Constant'
   *   '<S478>/Constant1'
   *   '<S478>/Constant2'
   *   '<S489>/Relay'
   *   '<S490>/Relay'
   *   '<S108>/Constant2'
   *   '<S108>/Saturation2'
   *   '<S109>/Constant2'
   *   '<S109>/Constant3'
   *   '<S111>/Constant'
   *   '<S112>/Constant'
   *   '<S113>/Constant'
   *   '<S168>/Constant'
   *   '<S168>/Constant1'
   *   '<S168>/Constant2'
   *   '<S168>/Constant3'
   *   '<S168>/Max'
   *   '<S168>/Max1'
   *   '<S168>/Max_Factor_FactorDecrease'
   *   '<S168>/Max_Factor_FactorIncrease'
   *   '<S168>/Min1'
   *   '<S168>/Min2'
   *   '<S169>/Constant'
   *   '<S169>/Max'
   *   '<S169>/Min_Factor_For_Waiting_Counter'
   *   '<S212>/Constant'
   *   '<S480>/Constant'
   *   '<S480>/Relay'
   *   '<S117>/Constant'
   *   '<S213>/Constant3'
   *   '<S213>/Constant4'
   */
  real32_T pooled3;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Alg_Loop_Delay12'
   *   '<S1>/Unit Delay'
   *   '<S4>/Unit Delay'
   *   '<S6>/Constant6'
   *   '<S7>/Unit Delay'
   *   '<S8>/Unit Delay'
   *   '<S9>/Unit Delay1'
   *   '<S13>/Constant1'
   *   '<S13>/Constant11'
   *   '<S13>/Constant13'
   *   '<S13>/Constant15'
   *   '<S13>/Constant17'
   *   '<S13>/Constant19'
   *   '<S13>/Constant3'
   *   '<S13>/Constant5'
   *   '<S13>/Constant7'
   *   '<S13>/Constant9'
   *   '<S15>/Alg loop1'
   *   '<S17>/Constant1'
   *   '<S17>/Alg loop'
   *   '<S17>/Alg loop2'
   *   '<S17>/Alg loop3'
   *   '<S17>/Alg loop4'
   *   '<S17>/Unit Delay alg loop'
   *   '<S19>/Unit Delay2'
   *   '<S29>/Constant'
   *   '<S29>/Alg_Loop_Delay'
   *   '<S29>/Alg_Loop_Delay1'
   *   '<S29>/Alg_Loop_Delay10'
   *   '<S29>/Alg_Loop_Delay11'
   *   '<S29>/Alg_Loop_Delay12'
   *   '<S29>/Alg_Loop_Delay13'
   *   '<S29>/Alg_Loop_Delay14'
   *   '<S29>/Alg_Loop_Delay15'
   *   '<S29>/Alg_Loop_Delay16'
   *   '<S29>/Alg_Loop_Delay17'
   *   '<S29>/Alg_Loop_Delay18'
   *   '<S29>/Alg_Loop_Delay2'
   *   '<S29>/Alg_Loop_Delay20'
   *   '<S29>/Alg_Loop_Delay21'
   *   '<S29>/Alg_Loop_Delay22'
   *   '<S29>/Alg_Loop_Delay23'
   *   '<S29>/Alg_Loop_Delay3'
   *   '<S29>/Alg_Loop_Delay4'
   *   '<S29>/Alg_Loop_Delay5'
   *   '<S29>/Alg_Loop_Delay6'
   *   '<S29>/Alg_Loop_Delay7'
   *   '<S29>/Alg_Loop_Delay8'
   *   '<S29>/Alg_Loop_Delay9'
   *   '<S496>/Constant'
   *   '<S496>/Unit Delay3'
   *   '<S497>/Unit Delay3'
   *   '<S498>/Unit Delay'
   *   '<S498>/Unit Delay1'
   *   '<S498>/Unit Delay10'
   *   '<S498>/Unit Delay11'
   *   '<S498>/Unit Delay12'
   *   '<S498>/Unit Delay13'
   *   '<S498>/Unit Delay14'
   *   '<S498>/Unit Delay2'
   *   '<S498>/Unit Delay3'
   *   '<S498>/Unit Delay4'
   *   '<S498>/Unit Delay5'
   *   '<S498>/Unit Delay6'
   *   '<S498>/Unit Delay7'
   *   '<S498>/Unit Delay8'
   *   '<S498>/Unit Delay9'
   *   '<S500>/Constant'
   *   '<S500>/Constant1'
   *   '<S500>/Constant2'
   *   '<S500>/Constant3'
   *   '<S546>/Constant'
   *   '<S35>/Constant3'
   *   '<S38>/Constant10'
   *   '<S38>/Constant4'
   *   '<S39>/Constant3'
   *   '<S39>/Unit Delay'
   *   '<S42>/Constant2'
   *   '<S42>/Constant5'
   *   '<S42>/Constant7'
   *   '<S47>/Alg_Loop'
   *   '<S48>/Constant'
   *   '<S48>/Constant4'
   *   '<S49>/Unit Delay alg loop'
   *   '<S49>/Unit Delay alg loop1'
   *   '<S461>/Constant4'
   *   '<S461>/LAT_Const'
   *   '<S27>/Unit Delay'
   *   '<S204>/Constant1'
   *   '<S205>/Constant4'
   *   '<S206>/Constant2'
   *   '<S207>/Constant1'
   *   '<S207>/Constant2'
   *   '<S207>/Constant3'
   *   '<S207>/Constant4'
   *   '<S207>/Unit Delay'
   *   '<S221>/Constant2'
   *   '<S221>/Constant3'
   *   '<S221>/Constant5'
   *   '<S221>/Unit Delay1'
   *   '<S222>/Constant1'
   *   '<S222>/Constant11'
   *   '<S222>/Constant13'
   *   '<S222>/Constant15'
   *   '<S222>/Constant17'
   *   '<S222>/Constant19'
   *   '<S222>/Constant3'
   *   '<S222>/Constant5'
   *   '<S222>/Constant7'
   *   '<S222>/Constant9'
   *   '<S224>/Constant1'
   *   '<S224>/Constant6'
   *   '<S230>/Constant5'
   *   '<S230>/Unit Delay2'
   *   '<S250>/Constant2'
   *   '<S250>/Constant3'
   *   '<S250>/Saturation2'
   *   '<S250>/Switch2'
   *   '<S250>/Unit Delay'
   *   '<S250>/Unit Delay1'
   *   '<S252>/Constant5'
   *   '<S252>/Constant8'
   *   '<S253>/Constant4'
   *   '<S273>/Constant'
   *   '<S282>/Constant5'
   *   '<S283>/Constant3'
   *   '<S291>/Unit Delay'
   *   '<S294>/No_Time_Constant'
   *   '<S296>/Unit Delay (1)'
   *   '<S296>/Unit Delay (2)'
   *   '<S296>/Unit Delay (3)'
   *   '<S462>/Constant2'
   *   '<S462>/Constant5'
   *   '<S462>/Constant7'
   *   '<S462>/Discrete-Time Integrator1'
   *   '<S462>/Saturation'
   *   '<S462>/Saturation2'
   *   '<S462>/Unit Delay1'
   *   '<S462>/Unit Delay3'
   *   '<S488>/Constant'
   *   '<S488>/Constant10'
   *   '<S488>/Constant12'
   *   '<S488>/Constant3'
   *   '<S488>/Constant4'
   *   '<S488>/Unit Delay1'
   *   '<S68>/Constant1'
   *   '<S163>/Unit Delay'
   *   '<S167>/Unit Delay1'
   *   '<S167>/Unit Delay2'
   *   '<S209>/Constant1'
   *   '<S209>/Constant2'
   *   '<S209>/Constant3'
   *   '<S209>/Unit Delay'
   *   '<S210>/Unit Delay'
   *   '<S214>/Constant1'
   *   '<S214>/Constant2'
   *   '<S214>/Constant3'
   *   '<S214>/Constant5'
   *   '<S214>/Unit Delay2'
   *   '<S215>/Unit Delay'
   *   '<S241>/Unit Delay'
   *   '<S242>/Unit Delay'
   *   '<S243>/Constant1'
   *   '<S243>/Constant10'
   *   '<S243>/Constant11'
   *   '<S243>/Constant2'
   *   '<S243>/Constant3'
   *   '<S243>/Constant8'
   *   '<S244>/Constant1'
   *   '<S244>/Constant9'
   *   '<S247>/Constant11'
   *   '<S247>/Constant2'
   *   '<S247>/Constant3'
   *   '<S247>/Constant8'
   *   '<S248>/Unit Delay'
   *   '<S249>/Unit Delay'
   *   '<S255>/Unit Delay'
   *   '<S257>/Constant5'
   *   '<S257>/Constant6'
   *   '<S257>/Unit Delay1'
   *   '<S261>/Constant3'
   *   '<S263>/Constant1'
   *   '<S263>/Unit Delay'
   *   '<S264>/Constant1'
   *   '<S275>/Unit Delay'
   *   '<S278>/MinLim'
   *   '<S279>/Unit Delay'
   *   '<S284>/Unit Delay'
   *   '<S285>/Constant'
   *   '<S285>/Unit Delay'
   *   '<S286>/Unit Delay'
   *   '<S287>/Unit Delay'
   *   '<S288>/Unit Delay'
   *   '<S290>/Unit Delay'
   *   '<S299>/MinSatVal'
   *   '<S301>/Constant'
   *   '<S304>/Constant'
   *   '<S305>/Constant'
   *   '<S467>/Constant'
   *   '<S475>/UD'
   *   '<S476>/UD'
   *   '<S478>/Discrete-Time Integrator'
   *   '<S489>/Constant1'
   *   '<S489>/Discrete-Time Integrator'
   *   '<S490>/Constant1'
   *   '<S490>/Constant5'
   *   '<S490>/Unit Delay1'
   *   '<S106>/Constant2'
   *   '<S106>/Constant5'
   *   '<S106>/Unit Delay1'
   *   '<S107>/Constant2'
   *   '<S107>/Constant5'
   *   '<S107>/Unit Delay1'
   *   '<S108>/Constant1'
   *   '<S108>/Saturation2'
   *   '<S108>/Unit Delay'
   *   '<S168>/Min'
   *   '<S168>/Min3'
   *   '<S168>/Min4'
   *   '<S168>/Min_Factor_FactorDecrease'
   *   '<S168>/Min_Factor_FactorIncrease'
   *   '<S169>/Min'
   *   '<S178>/Constant'
   *   '<S179>/Constant'
   *   '<S180>/Constant'
   *   '<S181>/Constant'
   *   '<S200>/Constant'
   *   '<S201>/Unit Delay'
   *   '<S216>/Constant4'
   *   '<S216>/Unit Delay1'
   *   '<S259>/Constant'
   *   '<S266>/Constant'
   *   '<S268>/Constant1'
   *   '<S269>/Unit Delay'
   *   '<S309>/Unit Delay'
   *   '<S480>/Constant1'
   *   '<S480>/Discrete-Time Integrator'
   *   '<S78>/Unit Delay'
   *   '<S79>/Unit Delay'
   *   '<S117>/Constant1'
   *   '<S118>/Unit Delay'
   *   '<S119>/Unit Delay'
   *   '<S184>/Constant1'
   *   '<S184>/Item_1'
   *   '<S184>/Item_2'
   *   '<S184>/Item_3'
   *   '<S184>/Item_4'
   *   '<S184>/Item_5'
   *   '<S185>/Constant2'
   *   '<S185>/Resettable Delay1'
   *   '<S185>/Resettable Delay2'
   *   '<S185>/Resettable Delay3'
   *   '<S185>/Unit Delay'
   *   '<S185>/Unit Delay1'
   *   '<S185>/Unit Delay3'
   *   '<S187>/Constant'
   *   '<S189>/Constant'
   *   '<S191>/Constant'
   *   '<S193>/Constant'
   *   '<S195>/Constant'
   *   '<S213>/Discrete-Time Integrator2'
   *   '<S213>/Discrete-Time Integrator3'
   *   '<S270>/Unit Delay1'
   *   '<S82>/Unit Delay1'
   *   '<S86>/Unit Delay1'
   *   '<S87>/Unit Delay1'
   *   '<S120>/Unit Delay'
   *   '<S121>/Unit Delay'
   */
  real32_T pooled4;

  /* Expression: single([0 0 0 0 0 0 0 0 0]) %[5 5 5 5 5 5 5 5 5]  %[15 14 13 12 10] %[50 49 48 47 45]
   * Referenced by: '<S169>/Maximum_Waiting_Counter_Scheduling'
   */
  real32_T Maximum_Waiting_Counter_Scheduling_tableData[9];

  /* Expression: single([10 30 50 70 90 110 130 150 170])
   * Referenced by: '<S169>/Maximum_Waiting_Counter_Scheduling'
   */
  real32_T Maximum_Waiting_Counter_Scheduling_bp01Data[9];

  /* Computed Parameter: u_Mean_Speed_Segments_Value
   * Referenced by: '<S167>/10_Mean_Speed_Segments'
   */
  real32_T u_Mean_Speed_Segments_Value[10];

  /* Computed Parameter: u_Speed_Segments_Value
   * Referenced by: '<S167>/10_Speed_Segments'
   */
  real32_T u_Speed_Segments_Value[11];

  /* Computed Parameter: u_Mean_Speed_Segments_Value_pinx
   * Referenced by: '<S167>/20_Mean_Speed_Segments'
   */
  real32_T u_Mean_Speed_Segments_Value_pinx[20];

  /* Computed Parameter: u_Speed_Segments_Value_hx55
   * Referenced by: '<S167>/20_Speed_Segments'
   */
  real32_T u_Speed_Segments_Value_hx55[21];

  /* Computed Parameter: _Mean_Speed_Segments_Value
   * Referenced by: '<S167>/5_Mean_Speed_Segments'
   */
  real32_T _Mean_Speed_Segments_Value[5];

  /* Computed Parameter: _Speed_Segments_Value
   * Referenced by: '<S167>/5_Speed_Segments'
   */
  real32_T _Speed_Segments_Value[6];

  /* Pooled Parameter (Expression: 100)
   * Referenced by:
   *   '<S17>/Constant5'
   *   '<S17>/Gain2'
   *   '<S37>/Gain2'
   *   '<S488>/Constant9'
   */
  real32_T pooled15;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S83>/PRF_T_Const_Scheduling'
   *   '<S83>/Prf_omega_Scheduling'
   */
  real32_T pooled31[12];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S83>/PRF_T_Const_Scheduling'
   *   '<S83>/Prf_omega_Scheduling'
   */
  real32_T pooled32[12];

  /* Expression: Sac_trq_angle_factor_y_schedul
   * Referenced by: '<S260>/SAC_Trq_Angle_Factor_Scheduling'
   */
  real32_T SAC_Trq_Angle_Factor_Scheduling_tableData[11];

  /* Expression: Sac_trq_angle_factor_x_schedul
   * Referenced by: '<S260>/SAC_Trq_Angle_Factor_Scheduling'
   */
  real32_T SAC_Trq_Angle_Factor_Scheduling_bp01Data[11];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Alg loop1'
   *   '<S2>/Unit Delay'
   *   '<S2>/Unit Delay1'
   *   '<S2>/Unit Delay2'
   *   '<S2>/Unit Delay3'
   *   '<S5>/Alg_Loop'
   *   '<S5>/Alg_Loop1'
   *   '<S5>/Alg_Loop2'
   *   '<S5>/Alg_Loop3'
   *   '<S17>/Constant6'
   *   '<S17>/Constant7'
   *   '<S17>/Alg loop1'
   *   '<S17>/Alg loop5'
   *   '<S17>/Alg loop6'
   *   '<S29>/Constant9'
   *   '<S29>/Alg_Loop_Delay19'
   *   '<S491>/Constant2'
   *   '<S35>/Constant1'
   *   '<S36>/Alg_loop'
   *   '<S40>/Alg Loop'
   *   '<S40>/Alg Loop1'
   *   '<S206>/Alg_loop1'
   *   '<S206>/Unit Delay'
   *   '<S206>/Unit Delay1'
   *   '<S207>/Unit Delay1'
   *   '<S226>/Unit Delay10'
   *   '<S226>/Unit Delay11'
   *   '<S226>/Unit Delay9'
   *   '<S227>/Unit Delay3'
   *   '<S462>/Unit Delay5'
   *   '<S165>/Unit Delay'
   *   '<S233>/Constant'
   *   '<S233>/Unit Delay1'
   *   '<S234>/Constant'
   *   '<S234>/Unit Delay1'
   *   '<S235>/Constant'
   *   '<S235>/Unit Delay1'
   *   '<S236>/Constant'
   *   '<S236>/Unit Delay1'
   *   '<S237>/Constant'
   *   '<S237>/Unit Delay1'
   *   '<S238>/Constant'
   *   '<S238>/Unit Delay1'
   *   '<S239>/Constant'
   *   '<S239>/Unit Delay1'
   *   '<S240>/Constant'
   *   '<S240>/Unit Delay1'
   *   '<S243>/Unit Delay'
   *   '<S243>/Unit Delay1'
   *   '<S245>/Unit Delay1'
   *   '<S245>/Unit Delay3'
   *   '<S175>/Constant'
   *   '<S199>/Initialisation_Flag'
   *   '<S220>/Constant1'
   *   '<S220>/Constant4'
   *   '<S484>/Constant1'
   *   '<S484>/Constant4'
   *   '<S185>/Unit Delay2'
   */
  boolean_T pooled65;
} ConstParam_DMC_Soc_Lat_T;

/* Constant parameters (auto storage) */
extern const ConstParam_DMC_Soc_Lat_T DMC_Soc_Lat_ConstP;

/* <== Enable QAC again after word size consistence check using limits.h has been done. */
/* PRQA L:LABEL_QAC_PRIVATE */
#endif                                 /* RTW_HEADER_DMC_Soc_Lat_private_h_ */
