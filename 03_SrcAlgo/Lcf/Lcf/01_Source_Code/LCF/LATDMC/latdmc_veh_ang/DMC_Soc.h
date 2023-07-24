/* $Header: DMC_Soc.h 1.65 2020/08/20 10:43:57CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc.h
   C source code generated on           : Wed Aug 19 16:27:04 2020
   Filename of Simulink Model           : DMC_Soc.mdl/.slx
   Revision of Simulink Model           : 1.3096
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
#ifndef RTW_HEADER_DMC_Soc_h_
#define RTW_HEADER_DMC_Soc_h_
#include <math.h>
#ifndef DMC_Soc_COMMON_INCLUDES_
# define DMC_Soc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "dmc_ac.h"
#endif                                 /* DMC_Soc_COMMON_INCLUDES_ */

#include "DMC_Soc_types.h"

/* Shared type includes */


/* Child system includes */
#define DMC_Soc_Lat_MDLREF_HIDE_CHILD_
#include "DMC_Soc_Lat.h"
#define DMC_Long_MDLREF_HIDE_CHILD_
#include "DMC_Long.h"
#define DMC_Lat_Brake_MDLREF_HIDE_CHILD_
#include "DMC_Lat_Brake.h"
#include "look1_is16lftf_binlc.h"
#include "look1_is16lfts16n10DfIf_binlcr.h"
#include "rt_roundf.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#include "dmc_ac.h"

/* Block signals (auto storage) */
typedef struct {
  int16_T LAT_Lateral_Controller_By_Brake_o1;/* '<S3>/LAT_Lateral_Controller_By_Brake' */
  int16_T LAT_Lateral_Controller_By_Brake_o2;/* '<S3>/LAT_Lateral_Controller_By_Brake' */
  int16_T LAT_Lateral_Controller_By_Brake_o4;/* '<S3>/LAT_Lateral_Controller_By_Brake' */
  uint8_T LAT_Lateral_Controller_By_Brake_o3;/* '<S3>/LAT_Lateral_Controller_By_Brake' */
} BlockIO_DMC_Soc_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Steer_gain_tableData
   * Referenced by: '<S8>/Steer_gain!'
   */
  real32_T Steer_gain_tableData[6];

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S5>/Constant1'
   */
  real32_T Constant1_Value;

  /* Pooled Parameter (Expression: 0)
   * Referenced by:
   *   '<S5>/Constant2'
   *   '<S5>/Constant3'
   *   '<S18>/enabled'
   */
  int16_T pooled6;

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S5>/Constant4'
   */
  int16_T Constant4_Value[4];

  /* Computed Parameter: Constant_Value_exs4
   * Referenced by: '<Root>/Constant'
   */
  boolean_T Constant_Value_exs4;
} ConstParam_DMC_Soc_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  int16_T VEH_WHEEL_VELOCITY_FRONT_LEFT;/* '<Root>/VEH_WHEEL_VELOCITY_FRONT_LEFT' */
  int16_T VEH_WHEEL_VELOCITY_FRONT_RIGHT;/* '<Root>/VEH_WHEEL_VELOCITY_FRONT_RIGHT' */
  int16_T VEH_WHEEL_VELOCITY_REAR_LEFT;/* '<Root>/VEH_WHEEL_VELOCITY_REAR_LEFT' */
  int16_T VEH_WHEEL_VELOCITY_REAR_RIGHT;/* '<Root>/VEH_WHEEL_VELOCITY_REAR_RIGHT' */
  int16_T VEH_WHEEL_VELOCITY_FRONT_LEFT_QF;/* '<Root>/VEH_WHEEL_VELOCITY_FRONT_LEFT_QF' */
  int16_T VEH_WHEEL_VELOCITY_FRONT_RIGHT_QF;/* '<Root>/VEH_WHEEL_VELOCITY_FRONT_RIGHT_QF' */
  int16_T VEH_WHEEL_VELOCITY_REAR_LEFT_QF;/* '<Root>/VEH_WHEEL_VELOCITY_REAR_LEFT_QF' */
  int16_T VEH_WHEEL_VELOCITY_REAR_RIGHT_QF;/* '<Root>/VEH_WHEEL_VELOCITY_REAR_RIGHT_QF' */
} ExternalInputs_DMC_Soc_T;

/* Block signals (auto storage) */
extern BlockIO_DMC_Soc_T DMC_Soc_B;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_DMC_Soc_T DMC_Soc_U;

/* Constant parameters (auto storage) */
extern const ConstParam_DMC_Soc_T DMC_Soc_ConstP;

/* Model entry point functions */
extern void DMC_Soc_initialize(void);
extern void DMC_Soc_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/Data Type Conversion1' : Unused code path elimination
 * Block '<S14>/Data Type Conversion10' : Unused code path elimination
 * Block '<S14>/Data Type Conversion11' : Unused code path elimination
 * Block '<S14>/Data Type Conversion12' : Unused code path elimination
 * Block '<S14>/Data Type Conversion13' : Unused code path elimination
 * Block '<S14>/Data Type Conversion14' : Unused code path elimination
 * Block '<S14>/Data Type Conversion15' : Unused code path elimination
 * Block '<S14>/Data Type Conversion2' : Unused code path elimination
 * Block '<S14>/Data Type Conversion3' : Unused code path elimination
 * Block '<S14>/Data Type Conversion4' : Unused code path elimination
 * Block '<S14>/Data Type Conversion8' : Unused code path elimination
 * Block '<S17>/Assignment' : Unused code path elimination
 * Block '<S17>/Reshape' : Unused code path elimination
 * Block '<S14>/km//h to m//s1' : Unused code path elimination
 * Block '<S14>/km//h to m//s3' : Unused code path elimination
 * Block '<S14>/km//h to m//s4' : Unused code path elimination
 * Block '<S14>/km//h to m//s5' : Unused code path elimination
 * Block '<S8>/Display' : Unused code path elimination
 * Block '<S8>/Display1' : Unused code path elimination
 * Block '<S8>/SSI_R_EPS_STEER_AG_' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S18>/Data Type Conversion' : Unused code path elimination
 * Block '<S18>/Data Type Conversion1' : Unused code path elimination
 * Block '<S18>/Data Type Conversion2' : Unused code path elimination
 * Block '<S18>/Data Type Conversion3' : Unused code path elimination
 * Block '<S18>/Scope' : Unused code path elimination
 * Block '<S12>/Display' : Unused code path elimination
 * Block '<S12>/Display1' : Unused code path elimination
 * Block '<S24>/DTProp1' : Unused code path elimination
 * Block '<S24>/DTProp2' : Unused code path elimination
 * Block '<S25>/DTProp1' : Unused code path elimination
 * Block '<S25>/DTProp2' : Unused code path elimination
 * Block '<S12>/Veh_steer_gear_ratio_y_tab' : Unused code path elimination
 * Block '<S13>/LO1' : Unused code path elimination
 * Block '<S4>/Data Type Conversion17' : Unused code path elimination
 * Block '<S4>/Data Type Conversion22' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S4>/Scope3' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S14>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion14' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion21' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion22' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion23' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion21' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion23' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion26' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion27' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion28' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion29' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion30' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion31' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion32' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion33' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion34' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion35' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion37' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion39' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion42' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion43' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion44' : Eliminate redundant data type conversion
 * Block '<S12>/Data Type Conversion45' : Eliminate redundant data type conversion
 * Block '<S24>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S25>/Modify Scaling Only' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion16' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion18' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion19' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion20' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion23' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion25' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion27' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion28' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion9' : Eliminate redundant data type conversion
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
 * '<Root>' : 'DMC_Soc'
 * '<S1>'   : 'DMC_Soc/DMC_Input_Interface'
 * '<S2>'   : 'DMC_Soc/DocBlock'
 * '<S3>'   : 'DMC_Soc/LaDMC'
 * '<S4>'   : 'DMC_Soc/LaDMC_Output_Interface'
 * '<S5>'   : 'DMC_Soc/LoDMC'
 * '<S6>'   : 'DMC_Soc/LoDMC_Output_Interface'
 * '<S7>'   : 'DMC_Soc/DMC_Input_Interface/EBS_Output'
 * '<S8>'   : 'DMC_Soc/DMC_Input_Interface/EPS_Output'
 * '<S9>'   : 'DMC_Soc/DMC_Input_Interface/LaDMC_Eeprom_Data'
 * '<S10>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_Iuc_Data'
 * '<S11>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check'
 * '<S12>'  : 'DMC_Soc/DMC_Input_Interface/LaKMC_Output'
 * '<S13>'  : 'DMC_Soc/DMC_Input_Interface/LoDMC_Inputs'
 * '<S14>'  : 'DMC_Soc/DMC_Input_Interface/EBS_Output/VED Signal Provider'
 * '<S15>'  : 'DMC_Soc/DMC_Input_Interface/EBS_Output/VED Signal Provider/Degrees to Radians'
 * '<S16>'  : 'DMC_Soc/DMC_Input_Interface/EBS_Output/VED Signal Provider/Degrees to Radians1'
 * '<S17>'  : 'DMC_Soc/DMC_Input_Interface/EBS_Output/VED Signal Provider/For Iterator Subsystem'
 * '<S18>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check/DMC_Degradation_Evaluation'
 * '<S19>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check/DMC_Degradation_Permanent_Disable_Ramp_Down_Conditions'
 * '<S20>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check/DMC_Degradation_Permanent_Disable_Shut_Off_Conditions'
 * '<S21>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check/DMC_Degradation_Temporary_Disable_Conditions'
 * '<S22>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check/System Requirements'
 * '<S23>'  : 'DMC_Soc/DMC_Input_Interface/LaDMC_SoC_Degradation_Check/DMC_Degradation_Permanent_Disable_Shut_Off_Conditions/Compare To Constant'
 * '<S24>'  : 'DMC_Soc/DMC_Input_Interface/LaKMC_Output/Extract Bits'
 * '<S25>'  : 'DMC_Soc/DMC_Input_Interface/LaKMC_Output/Extract Bits1'
 * '<S26>'  : 'DMC_Soc/DMC_Input_Interface/LaKMC_Output/Radians to Degrees'
 * '<S27>'  : 'DMC_Soc/DMC_Input_Interface/LaKMC_Output/Radians to Degrees1'
 */

/*-
 * Requirements for '<Root>': DMC_Soc
 *
 * Inherited requirements for '<S1>/LaDMC_SoC_Degradation_Check':
 *  1. LaDMC SoC Degradation Check
 *  2. Shut Off Permanent Degradation
 *  3. Ramp Down Permanent Degradation
 *  4. Temporary Degradation
 *  5. No Degradation

 */
#endif                                 /* RTW_HEADER_DMC_Soc_h_ */
