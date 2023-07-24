/**************************************************************************
COPYRIGHT (C) $Date: 2019/06/25 18:24:19CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJPLN/TPLLCO_VEH/TPLLCO/i/project.pj $
$Log: TPLLCO.c  $
Revision 1.6 2019/06/25 18:24:19CEST Zhu, Qiangqiang (uid41532) 
automatically created
File          : TPLLCO
Generated on  : Tue 25.06.2019 at 12:50:55 (UTC+01:00)
MD5           : [2278189306  1017022656  1129465787  2164377801 0](TPLLCO)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79,81,82
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TPLLCO.h"
#include "TPLLCO_Private.h"
/* Specific Includes */

/* Code Analysis Options */
// PRQA S 0380,0857 ++ // 2020-02-18; uidj2187; summary: too many macro definitions; reason: all output signals and parameters are macros and are generated
// PRQA S 0404 ++ // 2020-02-13; uidj2187; summary: more than one read access to volatile object between sequence points; reason: no side effects since volatile parameters are independent of each other
// PRQA S 0614 ++ // 2020-02-18; uidj2187; summary: too many block scope identifies; reason: ok since code is auto generated
// PRQA S 0779,0791 ++ // 2020-02-13; uidj2187; summary: identifier is not unique within the specified number of significant characters; reason: code is auto-generated and compiler can handle longer identifiers
// PRQA S 2211 ++ // 2020-02-23; uidj2187; summary: identifier misallignment; reason: auto code generation for stack identifiers
// PRQA S 2741,2742,2991,2992,2995,2996 ++ // 2020-02-23; uidj2187; summary: 'if' controlling expression is constant; reason: project-specific constant expression in generic code. Expression not constant in other projects
// PRQA S 2981,2982,2983 ++ // 2020-02-23; uidj2187; summary: redundant initialization; reason: good practice to always initialize variables
// PRQA S 2985,2986 ++ // 2020-02-23; uidj2187; summary: redundant operation; reason: project-specific expression in generic code. Operation not redundant in other projects
// PRQA S 3120 ++ // 2020-02-23; uidj2187; summary: hard-coded 'magic' integer constant; reason: constant will never change
// PRQA S 3203 ++ // 2020-02-23; uidj2187; summary: variable is set but never used; reason: auto-generated code
// PRQA S 3212 ++ // 2020-02-23; uidj2187; summary: redundant cast; reason: it is better to play safe
// PRQA S 3229 ++ // 2020-02-24; uidj2187; summary: unused file scope static variable; reason: auto-generated code
// PRQA S 3334 ++ // 2020-02-24; uidj2187; summary: variable declaration hides a more global declaration; reason: auto-generated code
// PRQA S 3344 ++ // 2020-02-24; uidj2187; summary: controlling expression is not an 'essentially Boolean' expression; reason: espression is a boolean variable of type uint8
// PRQA S 3395 ++ // 2020-03-19; uidj2187; summary: extra parentheses recommended; reason: operator precedence is clear. No ambiguity.
// PRQA S 3408 ++ // 2020-03-20; uidj2187; summary: no declaration found for externally linked variable; reason: variable is constant and not used externally
// PRQA S 3415 ++ // 2020-03-20; uidj2187; summary: possible side effects in right hand operand of '&&' or '||'; reason: no side-effects in expression
// PRQA S 3432 ++ // 2020-03-20; uidj2187; summary: unparenthesized macro argument; reason: no side effects in macro F32_PTR_IP2D in SDA library
// PRQA S 3469 ++ // 2020-03-24; uidj2187; summary: function-like macro could be replaced by equivalent function call; reason: design decision
// PRQA S 3472,3719,3741,3742,3774 ++ // 2020-03-24; uidj2187; summary: implicit type conversion; reason: safe implicit up cast in auto generated code
// PRQA S 3782,3794 ++ // 2020-03-25; uidj2187; summary: implicit type down cast; reason: misintepretation of function return type
// PRQA S 4115,4116 ++ // 2020-03-25; uidj2187; summary: operand of !, && or || is not a boolean expression; reason: safe use of uint8 as boolean
// PRQA S 4119 ++ // 2020-03-25; uidj2187; summary: result of floating point operation cast to an integral type; reason: intentional cast

/* Private Definitions */
/* General Defines */
/* End of General Defines */
/* Specific Defines */
/* End of Specific Defines */
/* General Types */
/*_not_init_def_struct_*/
/* End of General Types */
/* Specific Types */
/* End of Specific Types */
/* General Enumerates */
/* End of General Enumerates */
/* Specific Enumerates */
/* End of Specific Enumerates */
/* General Definitions */
/*_not_init_def_*/
/* End of General Definitions */
/* Specific definitions */
/*UtilityMacros*/
/* End of Specific Definitions */
/* General Declarations */
#define TPLLCO_START_SEC_DATA_8
#include "TPLLCO_MemMap.h"
static uint8 BI_tpllco_DTC_out;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/set_bit1/Functionality'/DTC_out' */
static uint8 BI_tpllco_DataTypeConversion;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/OR/Functionality'/Data Type Conversion' */
static uint8 BI_tpllco_Assignment[4];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array1/Functionality/assignment'/Assignment' */
static uint8 BI_tpllco_DataTypeConversion_g;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/OR/Functionality'/Data Type Conversion' */
static uint8 BI_tpllco_Assignment_b[4];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array1/Functionality/assignment'/Assignment' */
static uint8 BI_tpllco_DataTypeConversion_m;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/OR/Functionality'/Data Type Conversion' */
static uint8 BI_tpllco_Assignment_a[4];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array1/Functionality/assignment'/Assignment' */
static uint8 BI_tpllco_LogicalOperator;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_tpllco_Unit_Delay10;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay10' */
static uint8 BI_tpllco_DataTypeConversion_n;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND2/Functionality'/Data Type Conversion' */
static uint8 BI_tpllco_DataTypeConversion_c;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND3/Functionality'/Data Type Conversion' */
static uint8 DW_tpllco_UnitDelay1_DSTATE;
static uint8 DW_tpllco_Unit_Delay_DSTATE_b;
static uint8 DW_tpllco_Unit_Delay1_DSTATE_c;
static uint8 DW_tpllco_Unit_Delay_DSTATE_h;
static uint8 DW_tpllco_Unit_Delay2_DSTATE_j;
static uint8 DW_tpllco_Unit_Delay4_DSTATE;
static uint8 DW_tpllco_Unit_Delay10_DSTATE;
static uint8 DW_tpllco_Unit_Delay4_DSTATE_j;
static uint8 DW_tpllco_Unit_Delay7_DSTATE;
static uint8 DW_tpllco_Unit_Delay6_DSTATE;
static uint8 DW_tpllco_Unit_Delay2_DSTATE_lz;
static boolean DW_tpllco_Subsystem_MODE;
static boolean DW_tpllco_Set_Dev_ReplanDelta_MODE;
static boolean DW_tpllco_Plausibility_Check_MODE;
static boolean DW_tpllco_Calc_ReplanDelta_MODE;
#define TPLLCO_STOP_SEC_DATA_8
#include "TPLLCO_MemMap.h"
#define TPLLCO_START_SEC_DATA_32
#include "TPLLCO_MemMap.h"
static float32 BI_tpllco_Div;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_b;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_c;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_e;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_f;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_d;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco__TPLLCO_RightOri_rad;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/DTC8'/Data Type Conversion' */
static float32 BI_tpllco_copy1[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/branch'/copy1' */
static float32 BI_tpllco_copy1_l[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/branch1'/copy1' */
static float32 BI_tpllco_Sum[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Subtract1/Functionality'/Sum' */
static float32 BI_tpllco_Sum_j;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' */
static float32 BI_tpllco_VectorConcatenate[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation'/Vector Concatenate' */
static float32 BI_tpllco_Div_i;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_VectorConcatenate_d[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point'/Vector Concatenate' */
static float32 BI_tpllco_Switch;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch3/Functionality'/Switch' */
static float32 BI_tpllco_Switch_f;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch4/Functionality'/Switch' */
static float32 BI_tpllco_Sum_g[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Subtract1/Functionality'/Sum' */
static float32 BI_tpllco_Sum_o;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' */
static float32 BI_tpllco_Div_l;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Sum_n;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Subtract2/Functionality'/Sum' */
static float32 BI_tpllco_Sum_f;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Subtract1/Functionality'/Sum' */
static float32 BI_tpllco_Sum_np;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Add1/Functionality'/Sum' */
static float32 BI_tpllco_Sum_ji;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Add6/Functionality'/Sum' */
static float32 BI_tpllco_Sum_f5;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add6/Functionality'/Sum' */
static float32 BI_tpllco_Switch_o;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' */
static float32 BI_tpllco_Switch_h;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Switch' */
static float32 BI_tpllco_Switch_of;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' */
static float32 BI_tpllco_Div_fo;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_VectorConcatenate_i[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2'/Vector Concatenate' */
static float32 BI_tpllco_Div_dc;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_fb;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_k;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Sum_d;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add6/Functionality'/Sum' */
static float32 BI_tpllco_Switch_m;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' */
static float32 BI_tpllco_Switch_e;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Switch' */
static float32 BI_tpllco_Switch_mv;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' */
static float32 BI_tpllco_Div_m;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_VectorConcatenate_o[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2'/Vector Concatenate' */
static float32 BI_tpllco_Div_bt;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_g;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Sum_je;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' */
static float32 BI_tpllco_VectorConcatenate_a[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/Vector Concatenate' */
static float32 BI_tpllco_Div_ei;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Switch_j;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' */
static float32 BI_tpllco_Div_gx;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_eq;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_g1;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Mul;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Mul/Functionality'/Mul' */
static float32 BI_tpllco_Unit_Delay;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay' */
static float32 BI_tpllco_Unit_Delay1;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay1' */
static float32 BI_tpllco_Unit_Delay2;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay2' */
static float32 BI_tpllco_SignalConversion1;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Signal Conversion1' */
static float32 BI_tpllco_Sum_o4;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum7/Functionality'/Sum' */
static float32 BI_tpllco_Switch_l;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch5/Functionality'/Switch' */
static float32 BI_tpllco_Switch_k;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Div/Functionality/DivDefault'/Switch' */
static float32 BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_Sum_b;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum4/Functionality'/Sum' */
static float32 BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_TgtTrajLength_met_d;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
static float32 BI_tpllco__EgoDist[2];
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Vector Concatenate' */
static float32 BI_tpllco_Div_p;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_fc;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 BI_tpllco_Div_fp;
/* 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' */
static float32 DW_tpllco_Unit_Delay2_DSTATE;
static float32 DW_tpllco_VehDeltaOriArray_DSTATE[25];
static float32 DW_tpllco_VehDeltaDistArray_DSTATE[25];
static float32 DW_tpllco_Unit_Delay_DSTATE_f;
static float32 DW_tpllco_Unit_Delay1_DSTATE[2];
static float32 DW_tpllco_Unit_Delay_1_DSTATE;
static float32 DW_tpllco_Unit_Delay_2_DSTATE;
static float32 DW_tpllco_Unit_Delay_3_DSTATE;
static float32 DW_tpllco_Unit_Delay_4_DSTATE;
static float32 DW_tpllco_Unit_Delay_5_DSTATE;
static float32 DW_tpllco_UnitDelay3_DSTATE;
static float32 DW_tpllco_Unit_Delay1_DSTATE_g;
static float32 DW_tpllco_Unit_Delay3_DSTATE;
static float32 DW_tpllco_Unit_Delay_DSTATE_d;
static float32 DW_tpllco_Unit_Delay3_DSTATE_l;
static float32 DW_tpllco_Unit_Delay1_DSTATE_a3;
static float32 DW_tpllco_Unit_Delay9_DSTATE;
static float32 DW_tpllco_Unit_Delay13_13_DSTATE;
static float32 DW_tpllco_Unit_Delay13_14_DSTATE;
static float32 DW_tpllco_Unit_Delay13_15_DSTATE;
static float32 DW_tpllco_Unit_Delay13_16_DSTATE;
static float32 DW_tpllco_Unit_Delay13_17_DSTATE;
static float32 DW_tpllco_Unit_Delay13_1_DSTATE;
static float32 DW_tpllco_Unit_Delay13_10_DSTATE;
static float32 DW_tpllco_Unit_Delay13_11_DSTATE;
static float32 DW_tpllco_Unit_Delay13_12_DSTATE;
static float32 DW_tpllco_Unit_Delay13_18_DSTATE;
static float32 DW_tpllco_Unit_Delay13_2_DSTATE;
static float32 DW_tpllco_Unit_Delay13_3_DSTATE;
static float32 DW_tpllco_Unit_Delay13_4_DSTATE;
static float32 DW_tpllco_Unit_Delay13_5_DSTATE;
static float32 DW_tpllco_Unit_Delay13_6_DSTATE;
static float32 DW_tpllco_Unit_Delay13_7_DSTATE;
static float32 DW_tpllco_Unit_Delay13_8_DSTATE;
static float32 DW_tpllco_Unit_Delay13_9_DSTATE;
#define TPLLCO_STOP_SEC_DATA_32
#include "TPLLCO_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TPLLCO/TPLLCO/INI'/TPLLCO_VehReset'
 * Block description for: 'sda:TPLLCO/TPLLCO/INI'/TPLLCO_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLLCO_VehReset
#include "Pse_TPLLCO.h"
/* Short description: Not synchronized with ARAMIS */
void TPLLCO_VehReset(void)
{
    /* Function local data */
    sint32 i;
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant'/Constant' */
    SET_S_TPLLCO_TriggerReplan_nu(0U);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant1'/Constant' */
    SET_S_TPLLCO_DevHeading_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant10'/Constant' */
    SET_S_TPLLCO_LeftCorridorHeading_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant11'/Constant' */
    SET_S_TPLLCO_RightCorridorPosY0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant12'/Constant' */
    SET_S_TPLLCO_RightCorridorCrv_1pm(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant13'/Constant' */
    SET_S_TPLLCO_RightCridrHeading_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant14'/Constant' */
    SET_S_TPLLCO_RightCorridorPosX0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant15'/Constant' */
    SET_S_TPLLCO_RiCridrChngOfCrv_1pm2(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant16'/Constant' */
    SET_S_TPLLCO_TargetCorridorCrv_1pm(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant17'/Constant' */
    SET_S_TPLLCO_TargetCridrLength_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant18'/Constant' */
    SET_S_TPLLCO_TgtCridrChngOfCrv_1pm2(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant19'/Constant' */
    SET_S_TPLLCO_TargetCridrHeading_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant2'/Constant' */
    SET_S_TPLLCO_DevDistY_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant20'/Constant' */
    SET_S_TPLLCO_RightCorridorLength_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant21'/Constant' */
    SET_S_TPLLCO_TargetCorridorPosY0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant22'/Constant' */
    SET_S_TPLLCO_TargetCorridorPosX0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant23'/Constant' */
    SET_S_TPLLCO_MeasDeltaT_sec(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant24'/Constant' */
    SET_S_TPLLCO_TargetPathY0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant25'/Constant' */
    SET_S_TPLLCO_TargetPathHeading_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant26'/Constant' */
    SET_S_TPLLCO_TargetPathCrv_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant27'/Constant' */
    SET_D_TPLLCO_PlausiCheckStatus_nu(0U);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant28'/Constant' */
    SET_S_TPLLCO_PlausiCheckStatus_nu(0U);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant29'/Constant' */
    SET_D_TPLLCO_RightOri_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant3'/Constant' */
    SET_S_TPLLCO_ReplanDevHeading_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant30'/Constant' */
    SET_D_TPLLCO_DeltaProjPosX_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant31'/Constant' */
    SET_D_TPLLCO_DeltaProjPosY_met(0.0F);
    for (i = 0; i < 4; i++) {
        /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant32'/Constant' */
        SET_D_TPLLCO_RiCridrTransDev_met((i),(0.0F));
        /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant33'/Constant' */
        SET_D_TPLLCO_TgtCridrTransDev_met((i),(0.0F));
        /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant34'/Constant' */
        SET_D_TPLLCO_LeCridrTransDev_met((i),(0.0F));
    }
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant35'/Constant' */
    SET_D_TPLLCO_CCCDeviation_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant36'/Constant' */
    SET_D_TPLLCO_CCCTestPointDistX_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant37'/Constant' */
    SET_D_TPLLCO_CCCLength_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant38'/Constant' */
    SET_D_TPLLCO_CCCReset_nu(0U);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant39'/Constant' */
    SET_D_TPLLCO_CCCPassedPerc_nu(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant4'/Constant' */
    SET_S_TPLLCO_LeftCorridorPosY0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant40'/Constant' */
    SET_D_TPLLCO_CCCWarning_nu(0U);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant41'/Constant' */
    SET_D_TPLLCO_CCCInvalid_nu(0U);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant42'/Constant' */
    SET_D_TPLLCO_EgoHeadingPre_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant43'/Constant' */
    SET_D_TPLLCO_EgoDistYPre_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant44'/Constant' */
    SET_D_TPLLCO_CCCEgoYawangle_rad(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant45'/Constant' */
    SET_D_TPLLCO_CCCEgoDistX_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant46'/Constant' */
    SET_D_TPLLCO_CCCEgoDistY_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant5'/Constant' */
    SET_S_TPLLCO_LeftCorridorPosX0_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant6'/Constant' */
    SET_S_TPLLCO_ReplanDevDistY_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant7'/Constant' */
    SET_S_TPLLCO_LeftCorridorCrv_1pm(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant8'/Constant' */
    SET_S_TPLLCO_LeftCorridorLength_met(0.0F);
    /* Constant: 'sda:TPLLCO/TPLLCO/INI/TPLLCO_VehReset/Constant9'/Constant' */
    SET_S_TPLLCO_LeftCridrChngOfCrv_1pm2(0.0F);
}
#include "Pse_TPLLCO.h"
/*
 * Output and update for function-call system: 'sda:TPLLCO/TPLLCO'/TPLLCO_VehProcess'
 * Block description for: 'sda:TPLLCO/TPLLCO'/TPLLCO_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLLCO_VehProcess
#include "Pse_TPLLCO.h"
/* Short description: Not synchronized with ARAMIS */
void TPLLCO_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_conversion_sfunction2;
    float32 rtb_Mul_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_MathFunction;
    float32 rtb_MathFunction_i;
    float32 rtb_conversion_sfunction2_i;
    float32 rtb_Mul_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_MathFunction_k;
    float32 rtb_MathFunction_f;
    float32 rtb_conversion_sfunction2_j;
    float32 rtb_Mul_bzx;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_MathFunction_o;
    float32 rtb_MathFunction_fr;
    float32 rtb_MathFunction_ka;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Div_h;
    float32 rtb_Unit_Delay3;
    float32 rtb_SFunction;
    float32 rtb_ip_lookup_fxpt_sfun_7_g1;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_MathFunction_l;
    float32 rtb_MathFunction_g;
    float32 rtb_MathFunction_j;
    float32 rtb_MathFunction_m;
    float32 rtb_MathFunction_jl;
    float32 rtb_MathFunction_ox;
    float32 rtb_MathFunction_n;
    float32 rtb_MathFunction_l2;
    float32 rtb_MathFunction_iq;
    float32 rtb_MathFunction_a;
    float32 rtb_MathFunction_l1;
    float32 rtb_MathFunction_aj;
    float32 rtb_MathFunction_e;
    float32 rtb_MathFunction_h;
    float32 rtb_MathFunction_ee;
    sint8 rtb_ForIterator;
    sint8 rtb_ForIterator_k;
    sint8 rtb_ForIterator_e;
    sint8 rtb_conversion_sfunction2_e;
    sint8 rtb_conversion_sfunction2_m;
    sint8 rtb_conversion_sfunction2_en;
    uint8 rtb_VectorConcatenate_d[7];
    uint8 rtb_VectorConcatenate1[5];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_n;
    uint8 rtb_Switch_lp;
    float32 rtb_Assignment2[25];
    float32 rtb_Switch_gv;
    float32 rtb_Assignment[25];
    float32 rtb_Switch_oi;
    float32 rtb_Mul_a3;
    float32 rtb_Switch1_lx;
    float32 rtb_Switch1_h;
    float32 rtb_Max_af;
    uint8 rtb_GT_c;
    uint8 rtb_DataTypeConversion_on;
    uint8 rtb_DataTypeConversion_pk;
    uint8 rtb_Switch2_b;
    uint8 rtb_GT_kn;
    sint8 s889_iter;
    float32 rtb__EgoDist_m[2];
    float32 rtb_S_CSCLTA_TgtTrajLength_met;
    sint32 s3224_iter;
    float32 rtb_S_CSCLTA_LeCridrBndPosY0_met;
    float32 rtb_S_CSCLTA_LeCridrBndHeadAng_rad;
    float32 rtb_S_CSCLTA_LeCridrBndCrv_1pm;
    float32 rtb_S_CSCLTA_LeCridrBndCrvChng_1pm2;
    float32 rtb_S_CSCLTA_LeCridrBndLength_met;
    float32 rtb_S_CSCLTA_TgtTrajPosX0_met;
    float32 rtb_S_CSCLTA_TgtTrajPosY0_met;
    float32 rtb_S_CSCLTA_TgtTrajHeadAng_rad;
    float32 rtb_S_CSCLTA_TgtTrajCrv_1pm;
    float32 rtb_S_CSCLTA_TgtTrajCrvChng_1pm2;
    float32 rtb_VectorConcatenate_e[2];
    float32 rtb_Mul_h4;
    float32 rtb_Mul_f2;
    float32 rtb_Switch_ha;
    float32 rtb_Sum_mr[2];
    float32 rtb_TrigonometricFunction_eq;
    float32 rtb_VectorConcatenate_b[2];
    float32 rtb_VectorConcatenate_a[2];
    float32 rtb_Mul_mx[2];
    float32 rtb_VectorConcatenate_eq[2];
    float32 rtb_VectorConcatenate_l[2];
    float32 rtb_VectorConcatenate_f2[2];
    float32 rtb_VectorConcatenate_pd[2];
    float32 rtb_VectorConcatenate_bh[2];
    float32 rtb_Sum_mo;
    float32 rtb_Mul_pv;
    float32 rtb_Sum_oy;
    float32 rtb_Mul_fo[2];
    float32 rtb_Mul_mxn[2];
    float32 rtb_Mul_ei;
    float32 rtb_Sum_dg;
    float32 rtb_Sum_gx;
    float32 rtb_Sum_aft;
    float32 rtb_Sum_kq;
    float32 rtb_Sum_fc;
    float32 rtb_Mul_eq4[2];
    sint32 i;
    float32 rtb_VectorConcatenate_nj[2];
    float32 rtb_VectorConcatenate_m[2];
    float32 rtb_VectorConcatenate_jg[2];
    /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM'/M_TPLLCO'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM'/M_TPLLCO':
         *  X.2.1.1
         */
    /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check'/Subsystem' incorporates:
         *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Enable'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check'/Subsystem':
         *  X.2.1.1.4.1
         */
    /* Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/AND/Functionality'/AND' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Constant6'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/from_data_definition'/state_source'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/from_data_definition1'/state_source'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/from_data_definition2'/state_source'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/from_data_definition3'/state_source'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/from_data_definition4'/state_source'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/NEQ1/Functionality'/NE'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         */
    if (((((((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))) && ((((((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ)))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ))))) && (((sint32)GET_S_CSCLTA_TrajGuiQualifier_nu()) != ((sint32)((uint8) E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)))) && (((sint32) GET_P_TPLLCO_CCCEnable_nu()) != 0)) > 0) {
        if (!((sint32)DW_tpllco_Subsystem_MODE)) {
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay' */
            DW_tpllco_Unit_Delay_DSTATE_d = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay10' */
            DW_tpllco_Unit_Delay10_DSTATE = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay3' */
            DW_tpllco_Unit_Delay3_DSTATE_l = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay1' */
            DW_tpllco_Unit_Delay1_DSTATE_a3 = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay4' */
            DW_tpllco_Unit_Delay4_DSTATE_j = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay9' */
            DW_tpllco_Unit_Delay9_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay7' */
            DW_tpllco_Unit_Delay7_DSTATE = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay6' */
            DW_tpllco_Unit_Delay6_DSTATE = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_13_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_14_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_15_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_16_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_17_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay2' */
            DW_tpllco_Unit_Delay2_DSTATE_lz = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_1_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_10_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_11_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_12_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_18_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_2_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_3_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_4_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_5_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_6_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_7_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_8_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
            DW_tpllco_Unit_Delay13_9_DSTATE = 0.0F;
            DW_tpllco_Subsystem_MODE = (uint8)1U;
        }
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 */
        rtb_Mul_a3 = GET_S_LCFRCV_SysCycleTimeVeh_sec() * GET_S_LCFRCV_VehVelX_mps();
        /* UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay10' */
        BI_tpllco_Unit_Delay10 = DW_tpllco_Unit_Delay10_DSTATE;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3'/IV'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul4/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality/Add/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay3'
                 */
        if (((sint32)BI_tpllco_Unit_Delay10) != 0) {
            rtb_Switch1_lx = 0.0F;
        } else {
            rtb_Switch1_lx = (GET_S_LCFRCV_VehYawRate_rps() * GET_S_LCFRCV_SysCycleTimeVeh_sec()) + DW_tpllco_Unit_Delay3_DSTATE_l;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Switch1' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3'/MN'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3'/MX'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Relational Operator1'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Relational Operator3'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Switch2'
                 */
        if (rtb_Switch1_lx >= 100000.0F) {
            rtb_Switch1_lx = 100000.0F;
        } else {
            if (rtb_Switch1_lx <= -1.0E+6F) {
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Switch2' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3'/MN'
                                 */
                rtb_Switch1_lx = -1.0E+6F;
            }
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Switch3' */
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL3/Functionality'/Signal Conversion1' */
        BI_tpllco_SignalConversion1 = rtb_Switch1_lx;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL'/IV'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1'/IV'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality/Add/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality/Add/Functionality'/Sum'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Switch1'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Trigonom/Functionality'/Trigonometric Function'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Trigonom1/Functionality'/Trigonometric Function'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay1'
                 */
        if (((sint32)BI_tpllco_Unit_Delay10) != 0) {
            rtb_Switch1_h = 0.0F;
            rtb_Mul_a3 = 0.0F;
        } else {
            rtb_Switch1_h = (rtb_Mul_a3 * f32_cos_f32(BI_tpllco_SignalConversion1)) + DW_tpllco_Unit_Delay_DSTATE_d;
            rtb_Mul_a3 = (f32_sin_f32(BI_tpllco_SignalConversion1) * rtb_Mul_a3) + DW_tpllco_Unit_Delay1_DSTATE_a3;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Switch1' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL'/MN'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL'/MX'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Relational Operator1'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Relational Operator3'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Switch2'
                 */
        if (rtb_Switch1_h >= 1.0E+6F) {
            rtb_Switch1_h = 1.0E+6F;
        } else {
            if (rtb_Switch1_h <= -1.0E+6F) {
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Switch2' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL'/MN'
                                 */
                rtb_Switch1_h = -1.0E+6F;
            }
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Switch3' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Switch3' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1'/MN'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1'/MX'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Relational Operator1'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Relational Operator3'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Switch2'
                 */
        if (rtb_Mul_a3 >= 1.0E+6F) {
            rtb_Mul_a3 = 1.0E+6F;
        } else {
            if (rtb_Mul_a3 <= -1.0E+6F) {
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Switch2' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1'/MN'
                                 */
                rtb_Mul_a3 = -1.0E+6F;
            }
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Switch3' */
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Max/Functionality'/Max' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant6'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajLength_met'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul1/Functionality'/Mul'
                 */
        rtb_Max_af = f32_max_f32_f32(GET_P_TPLLCO_CCCMinTestDistX_met(), GET_P_TPLLCO_CCCTestDisXPerc_nu() * GET_S_CSCLTA_TgtTrajLength_met());
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Corridor_Trajectory_Equation':
                 *  X.2.1.1.4.1.1
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.4.1.1.1
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajHeadAng_rad'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_fc = (GET_S_CSCLTA_TgtTrajHeadAng_rad() + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_h = f32_floor_f32(BI_tpllco_Div_fc);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajHeadAng_rad'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_dg = (GET_S_CSCLTA_TgtTrajHeadAng_rad() + 1.57079506F) - (rtb_MathFunction_h * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_dg >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_dg -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_dg >= -0.0174532775F) {
                rtb_Sum_dg = -(0.0174532775F + rtb_Sum_dg);
            } else {
                rtb_Sum_dg = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_dg = 0.0174532775F - rtb_Sum_dg;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' incorporates:
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajPosX0_met'
                 */
        rtb_Sum_mo = rtb_Max_af - GET_S_CSCLTA_TgtTrajPosX0_met();
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
        rtb_Mul_h4 = rtb_Sum_mo * rtb_Sum_mo;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.4.1.1.1
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajCrvChng_1pm2'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajCrv_1pm'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajHeadAng_rad'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajPosY0_met'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_Sum_dg = (((f32_tan_f32(GET_S_CSCLTA_TgtTrajHeadAng_rad() + rtb_Sum_dg) * rtb_Sum_mo) + ((GET_S_CSCLTA_TgtTrajCrv_1pm() * rtb_Mul_h4) * 0.5F)) + (((rtb_Mul_h4 * rtb_Sum_mo) * GET_S_CSCLTA_TgtTrajCrvChng_1pm2()) * 0.166666672F)) + GET_S_CSCLTA_TgtTrajPosY0_met();
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Corridor_Trajectory_Equation' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum7/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul7/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul9/Functionality'/Mul'
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Signal Conversion1'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum6/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Trigonom6/Functionality'/Trigonometric Function'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Trigonom7/Functionality'/Trigonometric Function'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Neg/Functionality'/Unary Minus'
                 */
        BI_tpllco_Sum_o4 = (((-f32_sin_f32(BI_tpllco_SignalConversion1)) * rtb_Sum_dg) + (rtb_Max_af * f32_cos_f32(BI_tpllco_SignalConversion1))) + rtb_Switch1_h;
        /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/GT/Functionality'/GT' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajLength_met'
                 */
        rtb_GT_c = (uint8)(GET_S_CSCLTA_TgtTrajLength_met() > 0.0F);
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality'/Comparison'
                 */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/OR/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality'/Logical Operator2'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality/Comparison'/Logical Operator'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/OR/Functionality'/OR'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay4'
                 */
        rtb_DataTypeConversion_on = (uint8)(((!(((sint32) DW_tpllco_Unit_Delay4_DSTATE_j) != 0)) && (((sint32)rtb_GT_c) != 0)) || (((sint32)BI_tpllco_Unit_Delay10) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING'/fcg' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch5/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajLength_met'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay9'
                 */
        if (((sint32)rtb_DataTypeConversion_on) != 0) {
            BI_tpllco_Switch_l = GET_S_CSCLTA_TgtTrajLength_met();
        } else {
            BI_tpllco_Switch_l = DW_tpllco_Unit_Delay9_DSTATE;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch5/Functionality'/Switch' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Div/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant8'/Constant'
                 *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Max1/Functionality'/Max'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Div/Functionality/DivDefault'/Div'
                 */
        BI_tpllco_Switch_k = BI_tpllco_Sum_o4 / f32_max_f32_f32(BI_tpllco_Switch_l, 0.0001F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/COUNTER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/COUNTER_RE'/IV'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant10'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant5'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/COUNTER_RE/Functionality'/Constant3'
                 *  Inport: '<Root>/S_ABPLBP_LeCrvQuality_perc'
                 *  Inport: '<Root>/S_ABPLBP_LeLnQuality_perc'
                 *  Inport: '<Root>/S_ABPLBP_RiCrvQuality_perc'
                 *  Inport: '<Root>/S_ABPLBP_RiLnQuality_perc'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/OR3/Functionality'/OR'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/OR4/Functionality'/OR'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Div/Functionality/DivDefault'/Div'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Div1/Functionality/DivDefault'/Div'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/LT1/Functionality'/LT'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/LT2/Functionality'/LT'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/COUNTER_RE/Functionality/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay6'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay7'
                 */
        if ((((sint32)DW_tpllco_Unit_Delay7_DSTATE) != 0) || ((((sint32)(((uint32) u8_u32(((uint32)GET_S_ABPLBP_LeLnQuality_perc()) + ((uint32) ((sint32)GET_S_ABPLBP_RiLnQuality_perc())))) >> 1)) < ((sint32) GET_P_TPLLCO_CCCMinLnQuality_Perc())) || (((sint32)(((uint32)u8_u32 (((uint32)GET_S_ABPLBP_LeCrvQuality_perc()) + ((uint32)((sint32) GET_S_ABPLBP_RiCrvQuality_perc())))) >> 1)) < ((sint32) GET_P_TPLLCO_CCCMinCrvQuality_Perc())))) {
            rtb_Switch2_b = 0U;
        } else {
            rtb_Switch2_b = u8_u32(1U + ((uint32)((sint32)DW_tpllco_Unit_Delay6_DSTATE)));
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/COUNTER_RE/Functionality'/Switch2' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajCrvChng_1pm2'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajCrv_1pm'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajHeadAng_rad'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajPosX0_met'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajPosY0_met'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_on) != 0) {
            BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f = GET_S_CSCLTA_TgtTrajPosX0_met();
            BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p = GET_S_CSCLTA_TgtTrajPosY0_met();
            BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k = GET_S_CSCLTA_TgtTrajHeadAng_rad();
            BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i = GET_S_CSCLTA_TgtTrajCrv_1pm();
            BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d = GET_S_CSCLTA_TgtTrajCrvChng_1pm2();
        } else {
            BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f = DW_tpllco_Unit_Delay13_13_DSTATE;
            BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p = DW_tpllco_Unit_Delay13_14_DSTATE;
            BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k = DW_tpllco_Unit_Delay13_15_DSTATE;
            BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i = DW_tpllco_Unit_Delay13_16_DSTATE;
            BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d = DW_tpllco_Unit_Delay13_17_DSTATE;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Reference_Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Reference_Corridor_Trajectory_Equation':
                 *  X.2.1.1.4.1.2
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.4.1.2.1
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_p = (BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_e = f32_floor_f32(BI_tpllco_Div_p);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_mo = (BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k + 1.57079506F) - (rtb_MathFunction_e * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_mo >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_mo -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_mo >= -0.0174532775F) {
                rtb_Sum_mo = -(0.0174532775F + rtb_Sum_mo);
            } else {
                rtb_Sum_mo = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_mo = 0.0174532775F - rtb_Sum_mo;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Add3/Functionality'/Sum' */
        rtb_Mul_h4 = BI_tpllco_Sum_o4 - BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
        rtb_Mul_f2 = rtb_Mul_h4 * rtb_Mul_h4;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.4.1.2.1
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum4/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul6/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Mul8/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Signal Conversion1'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Add1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum3/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum5/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Trigonom4/Functionality'/Trigonometric Function'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Trigonom5/Functionality'/Trigonometric Function'
                 */
        BI_tpllco_Sum_b = ((((f32_tan_f32(BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k + rtb_Sum_mo) * rtb_Mul_h4) + ((BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i * rtb_Mul_f2) * 0.5F)) + (((rtb_Mul_f2 * rtb_Mul_h4) * BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d) * 0.166666672F)) + BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p) - (((f32_cos_f32(BI_tpllco_SignalConversion1) * rtb_Sum_dg) + (rtb_Max_af * f32_sin_f32(BI_tpllco_SignalConversion1))) + rtb_Mul_a3);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Reference_Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Reference_Corridor_Trajectory_Equation' */
        /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/GT2/Functionality'/GT' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Abs/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant2'/Constant'
                 */
        rtb_GT_kn = (uint8)(f32_abs_f32(BI_tpllco_Sum_b) > GET_P_TPLLCO_CCCThresholdMaxDev_met());
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant7'/Constant'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/NOT/Functionality'/NOT'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/LE/Functionality'/LE'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/RSFLIPFLOP/Functionality'/Switch'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay2'
                 */
        if ((((sint32)rtb_GT_kn) != 0) && (!(BI_tpllco_Switch_k <= GET_P_TPLLCO_CCCValidMaxPerc_nu()))) {
            rtb_GT_kn = DW_tpllco_Unit_Delay2_DSTATE_lz;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/RSFLIPFLOP/Functionality'/Switch1' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND4/Functionality'/Data Type Conversion' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Abs1/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant13'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant4'/Constant'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND4/Functionality'/AND'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/OR2/Functionality'/OR'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/LE2/Functionality'/LE'
                 */
        rtb_DataTypeConversion_pk = (uint8)((((sint32)rtb_GT_kn) != 0) && ((f32_abs_f32(BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i) <= GET_P_TPLLCO_CCCMaxCurvature_1pm()) || (((sint32) GET_P_TPLLCO_CCCEnableInCurve_nu()) != 0)));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Sum1/Functionality'/Sum' incorporates:
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Signal Conversion1'
                 */
        rtb_Max_af = BI_tpllco_Switch_l - rtb_Switch1_h;
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND2/Functionality'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant12'/Constant'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND2/Functionality'/AND'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/LE1/Functionality'/LE'
                 */
        BI_tpllco_DataTypeConversion_n = (uint8)((((sint32)rtb_DataTypeConversion_pk) != 0) && (rtb_Max_af <= GET_P_TPLLCO_CCCMinValidLength_met()));
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND3/Functionality'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant11'/Constant'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND3/Functionality'/AND'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/GT3/Functionality'/GT'
                 */
        BI_tpllco_DataTypeConversion_c = (uint8)((rtb_Max_af > 0.0F) && (((sint32) rtb_DataTypeConversion_pk) != 0));
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/ConcatBufferAtVector ConcatenateIn1' incorporates:
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL/Functionality'/Signal Conversion1'
                 */
        BI_tpllco__EgoDist[0] = rtb_Switch1_h;
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/ConcatBufferAtVector ConcatenateIn2' incorporates:
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/ACCUMULATOR_REL1/Functionality'/Signal Conversion1'
                 */
        BI_tpllco__EgoDist[1] = rtb_Mul_a3;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_CSCLTA_LeCridrBndCrvChng_1pm2'
                 *  Inport: '<Root>/S_CSCLTA_LeCridrBndCrv_1pm'
                 *  Inport: '<Root>/S_CSCLTA_LeCridrBndHeadAng_rad'
                 *  Inport: '<Root>/S_CSCLTA_LeCridrBndLength_met'
                 *  Inport: '<Root>/S_CSCLTA_LeCridrBndPosX0_met'
                 *  Inport: '<Root>/S_CSCLTA_LeCridrBndPosY0_met'
                 *  Inport: '<Root>/S_CSCLTA_RiCridrBndCrvChng_1pm2'
                 *  Inport: '<Root>/S_CSCLTA_RiCridrBndCrv_1pm'
                 *  Inport: '<Root>/S_CSCLTA_RiCridrBndHeadAng_rad'
                 *  Inport: '<Root>/S_CSCLTA_RiCridrBndLength_met'
                 *  Inport: '<Root>/S_CSCLTA_RiCridrBndPosX0_met'
                 *  Inport: '<Root>/S_CSCLTA_RiCridrBndPosY0_met'
                 *  Inport: '<Root>/S_CSCLTA_TgtTrajLength_met'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_on) != 0) {
            BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h = GET_S_CSCLTA_LeCridrBndPosX0_met();
            BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d = GET_S_CSCLTA_RiCridrBndCrv_1pm();
            BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l = GET_S_CSCLTA_RiCridrBndCrvChng_1pm2();
            BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j = GET_S_CSCLTA_RiCridrBndLength_met();
            BI_tpllco_S_CSCLTA_TgtTrajLength_met_d = GET_S_CSCLTA_TgtTrajLength_met();
            BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j = GET_S_CSCLTA_LeCridrBndPosY0_met();
            BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l = GET_S_CSCLTA_LeCridrBndHeadAng_rad();
            BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o = GET_S_CSCLTA_LeCridrBndCrv_1pm();
            BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f = GET_S_CSCLTA_LeCridrBndCrvChng_1pm2();
            BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o = GET_S_CSCLTA_LeCridrBndLength_met();
            BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a = GET_S_CSCLTA_RiCridrBndPosX0_met();
            BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g = GET_S_CSCLTA_RiCridrBndPosY0_met();
            BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h = GET_S_CSCLTA_RiCridrBndHeadAng_rad();
        } else {
            BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h = DW_tpllco_Unit_Delay13_1_DSTATE;
            BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d = DW_tpllco_Unit_Delay13_10_DSTATE;
            BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l = DW_tpllco_Unit_Delay13_11_DSTATE;
            BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j = DW_tpllco_Unit_Delay13_12_DSTATE;
            BI_tpllco_S_CSCLTA_TgtTrajLength_met_d = DW_tpllco_Unit_Delay13_18_DSTATE;
            BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j = DW_tpllco_Unit_Delay13_2_DSTATE;
            BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l = DW_tpllco_Unit_Delay13_3_DSTATE;
            BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o = DW_tpllco_Unit_Delay13_4_DSTATE;
            BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f = DW_tpllco_Unit_Delay13_5_DSTATE;
            BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o = DW_tpllco_Unit_Delay13_6_DSTATE;
            BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a = DW_tpllco_Unit_Delay13_7_DSTATE;
            BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g = DW_tpllco_Unit_Delay13_8_DSTATE;
            BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h = DW_tpllco_Unit_Delay13_9_DSTATE;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Switch8/Functionality'/Switch' */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay' */
        DW_tpllco_Unit_Delay_DSTATE_d = rtb_Switch1_h;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay10' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant14'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant3'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant9'/Constant'
                 *  DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND/Functionality'/Data Type Conversion'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/AND/Functionality'/AND'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/OR1/Functionality'/OR'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/GE2/Functionality'/GE'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/GT1/Functionality'/GT'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/LT/Functionality'/LT'
                 */
        DW_tpllco_Unit_Delay10_DSTATE = (uint8)(((GET_P_TPLLCO_CCCResetMaxDistX_met() < BI_tpllco_Sum_o4) || (BI_tpllco_Switch_k > GET_P_TPLLCO_CCCResetMaxPerc_nu())) && (((sint32)rtb_Switch2_b) >= ((sint32)GET_P_TPLLCO_CCCMinQuCycle_nu())));
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay3' */
        DW_tpllco_Unit_Delay3_DSTATE_l = rtb_Switch1_lx;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay1' */
        DW_tpllco_Unit_Delay1_DSTATE_a3 = rtb_Mul_a3;
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality'/SignalConversion'
                 */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay4' incorporates:
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
                 */
        DW_tpllco_Unit_Delay4_DSTATE_j = rtb_GT_c;
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/EDGERISING'/fcg' */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay9' */
        DW_tpllco_Unit_Delay9_DSTATE = BI_tpllco_Switch_l;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay7' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/Constant15'/Constant'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem/GE3/Functionality'/GE'
                 */
        DW_tpllco_Unit_Delay7_DSTATE = (uint8)(((sint32)rtb_Switch2_b) >= 250);
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay6' */
        DW_tpllco_Unit_Delay6_DSTATE = rtb_Switch2_b;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_13_DSTATE = BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_14_DSTATE = BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_15_DSTATE = BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_16_DSTATE = BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_17_DSTATE = BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay2' */
        DW_tpllco_Unit_Delay2_DSTATE_lz = rtb_GT_kn;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_1_DSTATE = BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_10_DSTATE = BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_11_DSTATE = BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_12_DSTATE = BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_18_DSTATE = BI_tpllco_S_CSCLTA_TgtTrajLength_met_d;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_2_DSTATE = BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_3_DSTATE = BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_4_DSTATE = BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_5_DSTATE = BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_6_DSTATE = BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_7_DSTATE = BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_8_DSTATE = BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/Unit_Delay13' */
        DW_tpllco_Unit_Delay13_9_DSTATE = BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h;
    } else {
        if (DW_tpllco_Subsystem_MODE) {
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCDeviation_met' */
            BI_tpllco_Sum_b = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCTestPointDistX_met' */
            BI_tpllco_Sum_o4 = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCLength_met' */
            BI_tpllco_Switch_l = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCReset_nu' */
            BI_tpllco_Unit_Delay10 = 0U;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCPassedPerc_nu' */
            BI_tpllco_Switch_k = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCInvalid_nu' */
            BI_tpllco_DataTypeConversion_n = 0U;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/EgoMotion' */
            BI_tpllco_SignalConversion1 = 0.0F;
            for (i = 0; i < 2; i++) {
                BI_tpllco__EgoDist[i] = 0.0F;
            }
            /* End of Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/EgoMotion' */
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/D_TPLLCO_CCCWarning_nu' */
            BI_tpllco_DataTypeConversion_c = 0U;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Subsystem'/AllCorridors_Reference' */
            BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h = 0.0F;
            BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j = 0.0F;
            BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l = 0.0F;
            BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o = 0.0F;
            BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f = 0.0F;
            BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o = 0.0F;
            BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a = 0.0F;
            BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g = 0.0F;
            BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h = 0.0F;
            BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d = 0.0F;
            BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l = 0.0F;
            BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j = 0.0F;
            BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f = 0.0F;
            BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p = 0.0F;
            BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k = 0.0F;
            BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i = 0.0F;
            BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d = 0.0F;
            BI_tpllco_S_CSCLTA_TgtTrajLength_met_d = 0.0F;
            DW_tpllco_Subsystem_MODE = (uint8)0U;
        }
    }
    /* End of Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/AND/Functionality'/AND' */
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check'/Subsystem' */
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Constant10'/Constant'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/AND1/Functionality'/AND'
         */
    rtb_GT_c = (uint8)((((sint32)BI_tpllco_DataTypeConversion_c) != 0) && (((sint32) GET_P_TPLLCO_CCCAllowOverwrite_nu()) != 0));
    /* UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan'/Unit Delay1' */
    rtb_sfun_setbit_n = DW_tpllco_UnitDelay1_DSTATE;
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Application Parameter'/Constant'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/AND/Functionality'/AND'
         */
    rtb_sfun_setbit_n = (uint8)((((sint32)rtb_sfun_setbit_n) != 0) && (((sint32) GET_P_TPLLCO_SupressDoubleTrigRpl_nu()) != 0));
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/NOT/Functionality'/NOT'
         */
    rtb_sfun_setbit_n = (uint8)(!(((sint32)rtb_sfun_setbit_n) != 0));
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Application Parameter1'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Gain_const'/Constant'
         *  Inport: '<Root>/S_CSCLTA_SensorTStamp_sec'
         *  Inport: '<Root>/S_LCFRCV_SenToVehTStamp_us'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Gain/Functionality'/Mul'
         */
    if (((sint32)GET_P_TPLLCO_UseSensorTStamp_nu()) != 0) {
        rtb_Switch1_lx = GET_S_CSCLTA_SensorTStamp_sec();
    } else {
        rtb_Switch1_lx = ((float32)GET_S_LCFRCV_SenToVehTStamp_us()) * 1.0E-6F;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Abs/Functionality'/Abs'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Compare To Constant_const'/Constant'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Compare To Constant/Functionality'/GT'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Subtract6/Functionality'/Sum'
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan'/Unit_Delay2'
         */
    rtb_sfun_setbit_n = (uint8)((((sint32)rtb_sfun_setbit_n) != 0) && (f32_abs_f32(rtb_Switch1_lx - DW_tpllco_Unit_Delay2_DSTATE) > 0.001F));
    /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/from_data_definition'/state_source'
         *  Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         */
    rtb_DataTypeConversion_on = (uint8)(((sint32)((uint8) E_LCF_TGQ_Type_E_LCF_TGQ_REQ_REFCHNG)) == ((sint32) GET_S_CSCLTA_TrajGuiQualifier_nu()));
    /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Equality1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         */
    rtb_Switch2_b = (uint8)(((sint32)GET_S_CSCLTA_TrajGuiQualifier_nu()) == ((sint32)((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ)));
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/Logical Operator/Functionality'/OR'
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising'/Unit_Delay'
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1'/Unit_Delay1'
         */
    rtb_GT_kn = (uint8)(((((sint32)rtb_sfun_setbit_n) != 0) || ((!(((sint32) DW_tpllco_Unit_Delay_DSTATE_b) != 0)) && (((sint32)rtb_DataTypeConversion_on) != 0))) || ((!(((sint32)DW_tpllco_Unit_Delay1_DSTATE_c) != 0)) && (((sint32) rtb_Switch2_b) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_CSCLTA_LatencyCompActivated_nu'
         *  Inport: '<Root>/S_LCFRCV_VehOdoState_nu'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Logical Operator2/Functionality'/AND'
         */
    rtb_DataTypeConversion_pk = (uint8)((((sint32) GET_S_CSCLTA_LatencyCompActivated_nu()) != 0) && (((sint32) GET_S_LCFRCV_VehOdoState_nu()) != 0));
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/VehSwitch/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/VehSwitch/Constant2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/P/Functionality'/Mul'
         */
    if (((sint32)rtb_DataTypeConversion_pk) != 0) {
        rtb_Switch_gv = GET_S_LCFRCV_VehYawRate_rps() * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        rtb_Switch_gv = 0.0F;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/VehSwitch/Switch1/Functionality'/Switch' */
    /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/Assignment2' incorporates:
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/VehDeltaOriArray'
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator'/Unit_Delay'
         */
    for (i = 0; i < 25; i++) {
        rtb_Assignment2[i] = DW_tpllco_VehDeltaOriArray_DSTATE[i];
    }
    rtb_Assignment2[DW_tpllco_Unit_Delay_DSTATE_h] = rtb_Switch_gv;
    /* End of Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/Assignment2' */
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/VehSwitch/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/VehSwitch/Constant4'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/Prod/Functionality'/Mul'
         */
    if (((sint32)rtb_DataTypeConversion_pk) != 0) {
        rtb_Switch_oi = GET_S_LCFRCV_SysCycleTimeVeh_sec() * GET_S_LCFRCV_VehVelX_mps();
    } else {
        rtb_Switch_oi = 0.0F;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/Odometry_from_Speed_and_YawRate/VehSwitch/Switch3/Functionality'/Switch' */
    /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/Assignment' incorporates:
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/VehDeltaDistArray'
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator'/Unit_Delay'
         */
    for (i = 0; i < 25; i++) {
        rtb_Assignment[i] = DW_tpllco_VehDeltaDistArray_DSTATE[i];
    }
    rtb_Assignment[DW_tpllco_Unit_Delay_DSTATE_h] = rtb_Switch_oi;
    /* End of Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/Assignment' */
    /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position'/InterpolationVehPos' incorporates:
         *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos'/Enable'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position'/InterpolationVehPos':
         *  X.2.1.1.1.1.2
         */
    if (((sint32)rtb_GT_kn) > 0) {
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Constant1'/Constant'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Div/Functionality/DivDefault'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_pk) != 0) {
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Application Parameter4'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Application Parameter5'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Gain_const'/Constant'
                         *  Inport: '<Root>/S_CSCLTA_SensorTStamp_sec'
                         *  Inport: '<Root>/S_LCFRCV_VehSync4LCO_us'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Gain/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Add1/Functionality'/Sum'
                         */
            if (((sint32)GET_P_TPLLCO_TimeDiffSwitch_nu()) != 0) {
                rtb_Switch1_h = GET_P_TPLLCO_TimeDiff_sec();
            } else {
                rtb_Switch1_h = (((float32)GET_S_LCFRCV_VehSync4LCO_us()) * 1.0E-6F) - GET_S_CSCLTA_SensorTStamp_sec();
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Application Parameter1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Compare To Constant_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Gain1_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Gain1/Functionality'/Mul'
                         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/GE/Functionality'/GE'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Add2/Functionality'/Sum'
                         */
            if (!(rtb_Switch1_h >= 0.0F)) {
                rtb_Switch1_h += (float32)u32_f32(((float32)GET_P_TPLLCO_OdoMaxTime_us()) * 1.0E-6F);
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Switch1/Functionality'/Switch' */
        } else {
            rtb_Switch1_h = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Switch2/Functionality'/Switch' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Div/Functionality/DivDefault'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Div/Functionality/DivDefault'/Div'
                 */
        rtb_Switch1_h /= GET_S_LCFRCV_SysCycleTimeVeh_sec();
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Min/Functionality'/Min' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Constant3'/Constant'
                 *  DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/to_resolution/Functionality/DTC_fxp'/Data Type Conversion'
                 *  DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/to_resolution/Functionality/DTC_round'/Data Type Conversion'
                 */
        rtb_Switch1_h = f32_min_f32_f32(25.0F, (float32)s32_f32(rtb_Switch1_h));
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Mul/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 */
        BI_tpllco_Mul = rtb_Switch1_h * GET_S_LCFRCV_SysCycleTimeVeh_sec();
        /* Math: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/modulo1'/modulo' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Calc_Latency_Time/Add3/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator'/Unit_Delay'
                 */
        rtb_DataTypeConversion_pk = (uint8)(((sint32)u8_f32(((float32) DW_tpllco_Unit_Delay_DSTATE_h) - rtb_Switch1_h)) % 25);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/Constant'/Constant'
                 */
        rtb_Switch1_h++;
        /* Outputs for Iterator SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation'/For_Iterator' incorporates:
                 *  ForIterator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/For Iterator'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation'/For_Iterator':
                 *  X.2.1.1.1.1.2.2.1
                 */
        /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay' */
        rtb_Sum_dg = 0.0F;
        /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay1' */
        rtb_Mul_a3 = 0.0F;
        /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay2' */
        rtb_Max_af = 0.0F;
        for (s889_iter = 0; ((sint32)s889_iter) < ((sint32)((sint8)rtb_Switch1_h));
                s889_iter = (sint8)(((sint32)s889_iter) + 1)) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Subtract/Functionality'/Sum' */
            i = ((sint32)rtb_DataTypeConversion_pk) + ((sint32)s889_iter);
            if (i > 255) {
                i = 255;
            }
            /* Math: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/modulo'/modulo' incorporates:
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Subtract/Functionality'/Sum'
                         */
            rtb_Switch_lp = (uint8)(((sint32)((uint8)i)) % 25);
            /* UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay' */
            BI_tpllco_Unit_Delay = rtb_Sum_dg;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Subtract1/Functionality'/Sum' incorporates:
                         *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Multiport_Switch1'
                         */
            rtb_Sum_dg = BI_tpllco_Unit_Delay + rtb_Assignment2[rtb_Switch_lp];
            /* UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay1' */
            BI_tpllco_Unit_Delay1 = rtb_Mul_a3;
            /* UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay2' */
            BI_tpllco_Unit_Delay2 = rtb_Max_af;
            /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay1' incorporates:
                         *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Multiport_Switch2'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Mul1/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Subtract2/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Trigonom1/Functionality'/Trigonometric Function'
                         */
            rtb_Mul_a3 = (f32_cos_f32(rtb_Sum_dg) * rtb_Assignment[rtb_Switch_lp]) + BI_tpllco_Unit_Delay1;
            /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Unit_Delay2' incorporates:
                         *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator'/Multiport_Switch2'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Mul/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Subtract3/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation/For_Iterator/Trigonom/Functionality'/Trigonometric Function'
                         */
            rtb_Max_af = (rtb_Assignment[rtb_Switch_lp] * f32_sin_f32(rtb_Sum_dg)) + BI_tpllco_Unit_Delay2;
        }
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/InterpolationVehPos/Interpolation'/For_Iterator' */
    }
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position'/InterpolationVehPos' */
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Constant'/Constant'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndCrvChng_1pm2'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndCrv_1pm'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndHeadAng_rad'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndPosX0_met'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndPosY0_met'
         *  Inport: '<Root>/S_CSCLTA_TgtTrajLength_met'
         *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch8/Functionality'/Switch'
         */
    if (((sint32)rtb_GT_c) != 0) {
        rtb_Switch1_h = BI_tpllco_SignalConversion1;
        for (i = 0; i < 2; i++) {
            rtb__EgoDist_m[i] = BI_tpllco__EgoDist[i];
        }
        rtb_Mul_a3 = BI_tpllco_S_CSCLTA_RiCridrBndPosX0_met_a;
        rtb_Max_af = BI_tpllco_S_CSCLTA_RiCridrBndPosY0_met_g;
        rtb_Sum_dg = BI_tpllco_S_CSCLTA_RiCridrBndHeadAng_rad_h;
        rtb_Sum_mo = BI_tpllco_S_CSCLTA_RiCridrBndCrv_1pm_d;
        rtb_Mul_h4 = BI_tpllco_S_CSCLTA_RiCridrBndCrvChng_1pm2_l;
        rtb_S_CSCLTA_TgtTrajLength_met = BI_tpllco_S_CSCLTA_TgtTrajLength_met_d;
    } else {
        rtb_Switch1_h = 0.0F;
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check'/ConcatBufferAtVector ConcatenateIn2' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Constant'/Constant'
                 */
        rtb__EgoDist_m[1] = 0.0F;
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check'/ConcatBufferAtVector ConcatenateIn1' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Constant'/Constant'
                 */
        rtb__EgoDist_m[0] = 0.0F;
        rtb_Mul_a3 = GET_S_CSCLTA_RiCridrBndPosX0_met();
        rtb_Max_af = GET_S_CSCLTA_RiCridrBndPosY0_met();
        rtb_Sum_dg = GET_S_CSCLTA_RiCridrBndHeadAng_rad();
        rtb_Sum_mo = GET_S_CSCLTA_RiCridrBndCrv_1pm();
        rtb_Mul_h4 = GET_S_CSCLTA_RiCridrBndCrvChng_1pm2();
        rtb_S_CSCLTA_TgtTrajLength_met = GET_S_CSCLTA_TgtTrajLength_met();
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/from_data_definition1'/state_source'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/EQ2/Functionality'/EQ'
         */
    rtb_sfun_setbit_n = (uint8)((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF))));
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/from_data_definition'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/EQ/Functionality'/EQ'
         */
    rtb_DataTypeConversion_pk = (uint8)((((sint32)rtb_sfun_setbit_n) != 0) && (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))));
    /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation'/Translate_Rotate_Cridr_CoordSystem' incorporates:
         *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Enable'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation'/Translate_Rotate_Cridr_CoordSystem':
         *  X.2.1.1.1.3
         */
    if (((sint32)rtb_GT_kn) > 0) {
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Subtract2/Functionality'/Sum' */
        rtb_Mul_f2 = rtb_Switch1_h + BI_tpllco_Unit_Delay;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Calc_Ctrl_Point'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Calc_Ctrl_Point':
                 *  X.2.1.1.1.3.1
                 */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Application Parameter1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Constant'/Constant'
                 *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Min/Functionality'/Min'
                 */
        if (((sint32)GET_P_TPLLCO_PreviewDistXEnable_nu()) != 0) {
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistXOBF_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistX_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         */
            if (((sint32)rtb_DataTypeConversion_pk) != 0) {
                /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistXOBF_met/Functionality'/ip_lookup_fxpt_sfun_7 */
                {
                    FDPS_RESULT dps_result_ln;
                    /* Calculate value */
                    /* Find indices on X Axis: X_TPLLCO_VehVelX_mps */
                    FDPS_PTR_F32(GETA_X_TPLLCO_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
                    /* Direct accesing curve (used as module input) */
                    rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_TPLLCO_PreviewDistXOBF_met(), &dps_result_ln);
                }
                rtb_Switch_ha = rtb_ip_lookup_fxpt_sfun_7_g;
            } else {
                /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistX_met/Functionality'/ip_lookup_fxpt_sfun_7 */
                {
                    FDPS_RESULT dps_result_ln;
                    /* Calculate value */
                    /* Find indices on X Axis: X_TPLLCO_VehVelX_mps */
                    FDPS_PTR_F32(GETA_X_TPLLCO_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
                    /* Direct accesing curve (used as module input) */
                    rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_TPLLCO_PreviewDistX_met(), &dps_result_ln);
                }
                rtb_Switch_ha = rtb_ip_lookup_fxpt_sfun_7_b;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Switch2/Functionality'/Switch' */
            rtb_Switch_ha = f32_min_f32_f32(rtb_Switch_ha, rtb_S_CSCLTA_TgtTrajLength_met);
        } else {
            rtb_Switch_ha = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Switch1/Functionality'/Switch' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Product1/Functionality'/Mul' incorporates:
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Trigonom1/Functionality'/Trigonometric Function'
                 */
        BI_tpllco_VectorConcatenate_d[0] = rtb_Switch_ha * f32_cos_f32(rtb_Mul_f2);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Product2/Functionality'/Mul' incorporates:
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Ctrl_Point/Trigonom/Functionality'/Trigonometric Function'
                 */
        BI_tpllco_VectorConcatenate_d[1] = f32_sin_f32(rtb_Mul_f2) * rtb_Switch_ha;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Calc_Ctrl_Point' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Subtract/Functionality'/Sum' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Subtract1/Functionality'/Sum'
                 */
        rtb_Sum_mr[0] = (rtb__EgoDist_m[0] + BI_tpllco_Unit_Delay1) + BI_tpllco_VectorConcatenate_d[0];
        rtb_Sum_mr[1] = (rtb__EgoDist_m[1] + BI_tpllco_Unit_Delay2) + BI_tpllco_VectorConcatenate_d[1];
        /* Outputs for Iterator SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Calc_Veh_Projection' incorporates:
                 *  ForIterator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/For Iterator'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Calc_Veh_Projection':
                 *  X.2.1.1.1.3.2
                 */
        /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Unit_Delay' */
        rtb_Mul_f2 = 0.0F;
        /* Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Application Parameter'/Constant' */
        for (s3224_iter = 1; s3224_iter <= ((sint32)GET_P_TPLLCO_NumIter_nu());
                s3224_iter++) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Subtract/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Constant3'/Constant'
                         *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Index Vector3'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Unit_Delay'
                         */
            rtb_Mul_f2 = rtb_Sum_mr[0] - rtb_Mul_f2;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Cridr_Trajectory_Equation'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Cridr_Trajectory_Equation':
                         *  X.2.1.1.1.3.2.1
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.1.3.2.1.2
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div_i = (rtb_Sum_dg + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_ka = f32_floor_f32(BI_tpllco_Div_i);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_Switch_ha = (rtb_Sum_dg + 1.57079506F) - (rtb_MathFunction_ka * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_Switch_ha >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_Switch_ha -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_Switch_ha >= -0.0174532775F) {
                    rtb_S_CSCLTA_LeCridrBndPosY0_met = -(0.0174532775F + rtb_Switch_ha);
                } else {
                    rtb_S_CSCLTA_LeCridrBndPosY0_met = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_S_CSCLTA_LeCridrBndPosY0_met = 0.0174532775F - rtb_Switch_ha;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                         */
            rtb_Switch_ha = f32_tan_f32(rtb_Sum_dg + rtb_S_CSCLTA_LeCridrBndPosY0_met);
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Add3/Functionality'/Sum' */
            rtb_S_CSCLTA_LeCridrBndPosY0_met = rtb_Mul_f2 - rtb_Mul_a3;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product5/Functionality'/Mul' */
            rtb_S_CSCLTA_LeCridrBndHeadAng_rad = rtb_S_CSCLTA_LeCridrBndPosY0_met * rtb_S_CSCLTA_LeCridrBndPosY0_met;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product6/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum1/Functionality'/Sum'
                         */
            rtb_S_CSCLTA_LeCridrBndCrv_1pm = (((((rtb_S_CSCLTA_LeCridrBndHeadAng_rad * rtb_S_CSCLTA_LeCridrBndPosY0_met) * rtb_Mul_h4) * 0.166666672F) + ((rtb_Sum_mo * rtb_S_CSCLTA_LeCridrBndHeadAng_rad) * 0.5F)) + (rtb_Switch_ha * rtb_S_CSCLTA_LeCridrBndPosY0_met)) + rtb_Max_af;
            /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Min/Functionality'/Min' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain3_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant4'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant5'/Constant'
                         *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Max/Functionality'/Max'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product4/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum3/Functionality'/Sum'
                         */
            rtb_S_CSCLTA_LeCridrBndHeadAng_rad = f32_min_f32_f32(f32_max_f32_f32 (((rtb_Mul_h4 * rtb_S_CSCLTA_LeCridrBndHeadAng_rad) * 0.5F) + ((rtb_Sum_mo * rtb_S_CSCLTA_LeCridrBndPosY0_met) + rtb_Switch_ha), -1.0F), 1.0F);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' incorporates:
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Abs/Functionality'/Abs'
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Abs1/Functionality'/Abs'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant2'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant3'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul4/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum2/Functionality'/Sum'
                         */
            BI_tpllco_Sum_j = (0.785398185F * rtb_S_CSCLTA_LeCridrBndHeadAng_rad) - (((f32_abs_f32(rtb_S_CSCLTA_LeCridrBndHeadAng_rad) - 1.0F) * rtb_S_CSCLTA_LeCridrBndHeadAng_rad) * ((f32_abs_f32 (rtb_S_CSCLTA_LeCridrBndHeadAng_rad) * 0.0663F) + 0.2447F));
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain_const1'/Constant'
                         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit/Functionality'/Relational Operator'
                         */
            if (100.0F >= rtb_Mul_f2) {
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit/Functionality'/Switch1' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain_const2'/Constant'
                                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit/Functionality'/Relational Operator1'
                                 */
                if (-100.0F <= rtb_Mul_f2) {
                    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit'/Signal Conversion' */
                    BI_tpllco_VectorConcatenate[0] = rtb_Mul_f2;
                } else {
                    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit'/Signal Conversion' */
                    BI_tpllco_VectorConcatenate[0] = -100.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit/Functionality'/Switch1' */
            } else {
                /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit'/Signal Conversion' */
                BI_tpllco_VectorConcatenate[0] = 100.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit/Functionality'/Switch' */
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain_const3'/Constant'
                         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1/Functionality'/Relational Operator'
                         */
            if (100.0F >= rtb_S_CSCLTA_LeCridrBndCrv_1pm) {
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1/Functionality'/Switch1' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain_const4'/Constant'
                                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1/Functionality'/Relational Operator1'
                                 */
                if (-100.0F <= rtb_S_CSCLTA_LeCridrBndCrv_1pm) {
                    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1'/Signal Conversion' */
                    BI_tpllco_VectorConcatenate[1] = rtb_S_CSCLTA_LeCridrBndCrv_1pm;
                } else {
                    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1'/Signal Conversion' */
                    BI_tpllco_VectorConcatenate[1] = -100.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1/Functionality'/Switch1' */
            } else {
                /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1'/Signal Conversion' */
                BI_tpllco_VectorConcatenate[1] = 100.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Cridr_Trajectory_Equation/Limit1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Cridr_Trajectory_Equation' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Subtract1/Functionality'/Sum' */
            for (i = 0; i < 2; i++) {
                BI_tpllco_Sum[i] = rtb_Sum_mr[i] - BI_tpllco_VectorConcatenate[i];
            }
            /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Subtract1/Functionality'/Sum' */
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Divide/Functionality/DivDefault'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Divide/In3'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Divide/Functionality/DivDefault'/Div'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Mul/Functionality'/Mul'
                         */
            if (BI_tpllco_Sum[1] != 0.0F) {
                rtb_Mul_f2 = (-BI_tpllco_Sum[0]) / BI_tpllco_Sum[1];
            } else {
                rtb_Mul_f2 = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Divide/Functionality/DivDefault'/Switch' */
            /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Max/Functionality'/Max' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Constant4'/Constant'
                         */
            rtb_Mul_f2 = f32_max_f32_f32(rtb_Mul_f2, -1.0F);
            /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Min/Functionality'/Min' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Constant5'/Constant'
                         */
            rtb_Mul_f2 = f32_min_f32_f32(rtb_Mul_f2, 1.0F);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Subtract2/Functionality'/Sum' incorporates:
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Abs/Functionality'/Abs'
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Abs1/Functionality'/Abs'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Constant'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Constant2'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Constant3'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Mul4/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/ApproxAtan/Sum3/Functionality'/Sum'
                         */
            rtb_Switch_ha = BI_tpllco_Sum_j - ((0.785398185F * rtb_Mul_f2) - (((f32_abs_f32 (rtb_Mul_f2) - 1.0F) * rtb_Mul_f2) * ((f32_abs_f32(rtb_Mul_f2) * 0.0663F) + 0.2447F)));
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Rotate_Anticlockwise'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Rotate_Anticlockwise':
                         *  X.2.1.1.1.3.2.2
                         */
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Rotate_Anticlockwise/Trigonom1/Functionality'/Trigonometric Function' */
            rtb_Mul_f2 = f32_cos_f32(rtb_Switch_ha);
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Rotate_Anticlockwise/Trigonom/Functionality'/Trigonometric Function' */
            rtb_Switch_ha = f32_sin_f32(rtb_Switch_ha);
            /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Unit_Delay' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Rotate_Anticlockwise/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Rotate_Anticlockwise/Product2/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection/Rotate_Anticlockwise/Sum of Elements/Functionality'/Sum'
                         */
            rtb_Mul_f2 = (BI_tpllco_Sum[0] * rtb_Mul_f2) + (BI_tpllco_Sum[1] * (-rtb_Switch_ha));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Calc_Veh_Projection'/Rotate_Anticlockwise' */
        }
        /* End of Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/Application Parameter'/Constant' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem'/Calc_Veh_Projection' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/DTC8'/Data Type Conversion' */
        BI_tpllco__TPLLCO_RightOri_rad = BI_tpllco_Sum_j;
        for (i = 0; i < 2; i++) {
            /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/branch'/copy1' */
            BI_tpllco_copy1[i] = BI_tpllco_VectorConcatenate[i];
            /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Translate_Rotate_Cridr_CoordSystem/branch1'/copy1' */
            BI_tpllco_copy1_l[i] = BI_tpllco_Sum[i];
        }
    }
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation'/Translate_Rotate_Cridr_CoordSystem' */
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch8/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_CSCLTA_LeCridrBndCrvChng_1pm2'
         *  Inport: '<Root>/S_CSCLTA_LeCridrBndCrv_1pm'
         *  Inport: '<Root>/S_CSCLTA_LeCridrBndHeadAng_rad'
         *  Inport: '<Root>/S_CSCLTA_LeCridrBndLength_met'
         *  Inport: '<Root>/S_CSCLTA_LeCridrBndPosX0_met'
         *  Inport: '<Root>/S_CSCLTA_LeCridrBndPosY0_met'
         *  Inport: '<Root>/S_CSCLTA_RiCridrBndLength_met'
         *  Inport: '<Root>/S_CSCLTA_TgtTrajCrvChng_1pm2'
         *  Inport: '<Root>/S_CSCLTA_TgtTrajCrv_1pm'
         *  Inport: '<Root>/S_CSCLTA_TgtTrajHeadAng_rad'
         *  Inport: '<Root>/S_CSCLTA_TgtTrajPosX0_met'
         *  Inport: '<Root>/S_CSCLTA_TgtTrajPosY0_met'
         *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch8/Functionality'/Switch'
         */
    if (((sint32)rtb_GT_c) != 0) {
        rtb_Switch_ha = BI_tpllco_S_CSCLTA_LeCridrBndPosX0_met_h;
        rtb_S_CSCLTA_LeCridrBndPosY0_met = BI_tpllco_S_CSCLTA_LeCridrBndPosY0_met_j;
        rtb_S_CSCLTA_LeCridrBndHeadAng_rad = BI_tpllco_S_CSCLTA_LeCridrBndHeadAng_rad_l;
        rtb_S_CSCLTA_LeCridrBndCrv_1pm = BI_tpllco_S_CSCLTA_LeCridrBndCrv_1pm_o;
        rtb_S_CSCLTA_LeCridrBndCrvChng_1pm2 = BI_tpllco_S_CSCLTA_LeCridrBndCrvChng_1pm2_f;
        rtb_S_CSCLTA_LeCridrBndLength_met = BI_tpllco_S_CSCLTA_LeCridrBndLength_met_o;
        rtb_Mul_f2 = BI_tpllco_S_CSCLTA_RiCridrBndLength_met_j;
        rtb_S_CSCLTA_TgtTrajPosX0_met = BI_tpllco_S_CSCLTA_TgtTrajPosX0_met_f;
        rtb_S_CSCLTA_TgtTrajPosY0_met = BI_tpllco_S_CSCLTA_TgtTrajPosY0_met_p;
        rtb_S_CSCLTA_TgtTrajHeadAng_rad = BI_tpllco_S_CSCLTA_TgtTrajHeadAng_rad_k;
        rtb_S_CSCLTA_TgtTrajCrv_1pm = BI_tpllco_S_CSCLTA_TgtTrajCrv_1pm_i;
        rtb_S_CSCLTA_TgtTrajCrvChng_1pm2 = BI_tpllco_S_CSCLTA_TgtTrajCrvChng_1pm2_d;
    } else {
        rtb_Switch_ha = GET_S_CSCLTA_LeCridrBndPosX0_met();
        rtb_S_CSCLTA_LeCridrBndPosY0_met = GET_S_CSCLTA_LeCridrBndPosY0_met();
        rtb_S_CSCLTA_LeCridrBndHeadAng_rad = GET_S_CSCLTA_LeCridrBndHeadAng_rad();
        rtb_S_CSCLTA_LeCridrBndCrv_1pm = GET_S_CSCLTA_LeCridrBndCrv_1pm();
        rtb_S_CSCLTA_LeCridrBndCrvChng_1pm2 = GET_S_CSCLTA_LeCridrBndCrvChng_1pm2();
        rtb_S_CSCLTA_LeCridrBndLength_met = GET_S_CSCLTA_LeCridrBndLength_met();
        rtb_Mul_f2 = GET_S_CSCLTA_RiCridrBndLength_met();
        rtb_S_CSCLTA_TgtTrajPosX0_met = GET_S_CSCLTA_TgtTrajPosX0_met();
        rtb_S_CSCLTA_TgtTrajPosY0_met = GET_S_CSCLTA_TgtTrajPosY0_met();
        rtb_S_CSCLTA_TgtTrajHeadAng_rad = GET_S_CSCLTA_TgtTrajHeadAng_rad();
        rtb_S_CSCLTA_TgtTrajCrv_1pm = GET_S_CSCLTA_TgtTrajCrv_1pm();
        rtb_S_CSCLTA_TgtTrajCrvChng_1pm2 = GET_S_CSCLTA_TgtTrajCrvChng_1pm2();
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/Switch8/Functionality'/Switch' */
    /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs'/Set_AllCorridors' incorporates:
         *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors'/Enable'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs'/Set_AllCorridors':
         *  X.2.1.1.1.2.1
         */
    if (((sint32)rtb_GT_kn) > 0) {
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor'/Coordinate_Transformation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor'/Coordinate_Transformation':
                 *  X.2.1.1.1.2.1.1.2
                 */
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/MinMax/Functionality'/Max' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Application Parameter1'/Constant'
                 */
        rtb_TrigonometricFunction_eq = f32_max_f32_f32 (rtb_S_CSCLTA_LeCridrBndLength_met, GET_P_TPLLCO_CoordTrafoMinLength_met());
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Gain1_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Gain1/Functionality'/Mul'
                 */
        rtb_Sum_oy = (rtb_TrigonometricFunction_eq * 0.5F) + rtb_Switch_ha;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add2/Functionality'/Sum' */
        rtb_TrigonometricFunction_eq += rtb_Switch_ha;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation':
                 *  X.2.1.1.1.2.1.1.2.1
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.1.2.1.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_g1 = (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_aj = f32_floor_f32(BI_tpllco_Div_g1);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_kq = (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + 1.57079506F) - (rtb_MathFunction_aj * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_kq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_kq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_kq >= -0.0174532775F) {
                rtb_Sum_kq = -(0.0174532775F + rtb_Sum_kq);
            } else {
                rtb_Sum_kq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_kq = 0.0174532775F - rtb_Sum_kq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' */
        rtb_Sum_gx = rtb_TrigonometricFunction_eq - rtb_Switch_ha;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
        rtb_Mul_pv = rtb_Sum_gx * rtb_Sum_gx;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.1.2.1.2
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_b[1] = (((f32_tan_f32 (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + rtb_Sum_kq) * rtb_Sum_gx) + ((rtb_S_CSCLTA_LeCridrBndCrv_1pm * rtb_Mul_pv) * 0.5F)) + (((rtb_Mul_pv * rtb_Sum_gx) * rtb_S_CSCLTA_LeCridrBndCrvChng_1pm2) * 0.166666672F)) + rtb_S_CSCLTA_LeCridrBndPosY0_met;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain2'/Data Type Conversion' */
        rtb_VectorConcatenate_b[0] = rtb_TrigonometricFunction_eq;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add3/Functionality'/Sum' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_b[i] -= BI_tpllco_copy1[i];
        }
        /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add3/Functionality'/Sum' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add4/Functionality'/Sum' */
        rtb_Sum_mr[0] = rtb_Switch_ha - BI_tpllco_copy1[0];
        rtb_Sum_mr[1] = rtb_S_CSCLTA_LeCridrBndPosY0_met - BI_tpllco_copy1[1];
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1':
                 *  X.2.1.1.1.2.1.1.2.5
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.1.2.5.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_eq = (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_l1 = f32_floor_f32(BI_tpllco_Div_eq);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + 1.57079506F) - (rtb_MathFunction_l1 * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_TrigonometricFunction_eq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_TrigonometricFunction_eq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_TrigonometricFunction_eq >= -0.0174532775F) {
                rtb_TrigonometricFunction_eq = -(0.0174532775F + rtb_TrigonometricFunction_eq);
            } else {
                rtb_TrigonometricFunction_eq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_TrigonometricFunction_eq = 0.0174532775F - rtb_TrigonometricFunction_eq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Add3/Functionality'/Sum' */
        rtb_Sum_kq = rtb_Sum_oy - rtb_Switch_ha;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul/Functionality'/Mul' */
        rtb_Sum_gx = rtb_Sum_kq * rtb_Sum_kq;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.1.2.5.2
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_a[1] = (((f32_tan_f32 (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + rtb_TrigonometricFunction_eq) * rtb_Sum_kq) + ((rtb_S_CSCLTA_LeCridrBndCrv_1pm * rtb_Sum_gx) * 0.5F)) + (((rtb_Sum_gx * rtb_Sum_kq) * rtb_S_CSCLTA_LeCridrBndCrvChng_1pm2) * 0.166666672F)) + rtb_S_CSCLTA_LeCridrBndPosY0_met;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain2'/Data Type Conversion' */
        rtb_VectorConcatenate_a[0] = rtb_Sum_oy;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add6/Functionality'/Sum' */
        rtb_Sum_oy = rtb_S_CSCLTA_LeCridrBndHeadAng_rad - BI_tpllco__TPLLCO_RightOri_rad;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1':
                 *  X.2.1.1.1.2.1.1.2.2
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Neg/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Neg/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product1/Functionality'/Mul' */
        rtb_Mul_mxn[0] = rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_b[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Neg/Functionality'/Unary Minus'
                 */
        rtb_VectorConcatenate_b[0] = (rtb_VectorConcatenate_b[0] * rtb_Sum_kq) + (rtb_VectorConcatenate_b[1] * (-rtb_TrigonometricFunction_eq));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_b[1] = (rtb_Sum_kq * rtb_VectorConcatenate_b[1]) + rtb_Mul_mxn[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2':
                 *  X.2.1.1.1.2.1.1.2.3
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Neg1/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Neg1/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product1/Functionality'/Mul' */
        rtb_Mul_mxn[0] = rtb_TrigonometricFunction_eq * rtb_Sum_mr[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Neg/Functionality'/Unary Minus'
                 */
        rtb_Sum_mr[0] = (rtb_Sum_mr[0] * rtb_Sum_kq) + (rtb_Sum_mr[1] * (-rtb_TrigonometricFunction_eq));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product1/Functionality'/Mul'
                 */
        rtb_Sum_mr[1] = (rtb_Sum_kq * rtb_Sum_mr[1]) + rtb_Mul_mxn[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2' */
        for (i = 0; i < 2; i++) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add5/Functionality'/Sum' */
            rtb_VectorConcatenate_a[i] -= BI_tpllco_copy1[i];
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add7/Functionality'/Sum' */
            rtb_VectorConcatenate_b[i] -= rtb_Sum_mr[i];
        }
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3':
                 *  X.2.1.1.1.2.1.1.2.4
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Neg2/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Neg2/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product1/Functionality'/Mul' */
        rtb_Mul_mxn[0] = rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_a[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Neg/Functionality'/Unary Minus'
                 */
        rtb_VectorConcatenate_a[0] = (rtb_VectorConcatenate_a[0] * rtb_Sum_kq) + (rtb_VectorConcatenate_a[1] * (-rtb_TrigonometricFunction_eq));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_a[1] = (rtb_Sum_kq * rtb_VectorConcatenate_a[1]) + rtb_Mul_mxn[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add8/Functionality'/Sum' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_a[i] -= rtb_Sum_mr[i];
        }
        /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add8/Functionality'/Sum' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.1.2.6
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_gx = (rtb_Sum_oy + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_a = f32_floor_f32(BI_tpllco_Div_gx);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = (rtb_Sum_oy + 1.57079506F) - (rtb_MathFunction_a * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_TrigonometricFunction_eq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_TrigonometricFunction_eq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_TrigonometricFunction_eq >= -0.0174532775F) {
                rtb_Sum_kq = -(0.0174532775F + rtb_TrigonometricFunction_eq);
            } else {
                rtb_Sum_kq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_kq = 0.0174532775F - rtb_TrigonometricFunction_eq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/TanNinety_V4/Add4/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = f32_tan_f32(rtb_Sum_oy + rtb_Sum_kq);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Add9/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product1/Functionality'/Mul'
                 */
        rtb_Mul_fo[0] = rtb_VectorConcatenate_a[1] - (rtb_VectorConcatenate_a[0] * rtb_TrigonometricFunction_eq);
        rtb_Mul_fo[1] = rtb_VectorConcatenate_b[1] - (rtb_VectorConcatenate_b[0] * rtb_TrigonometricFunction_eq);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Mul/Functionality'/Mul' */
        rtb_Mul_mxn[0] = rtb_VectorConcatenate_b[0] * rtb_VectorConcatenate_b[0];
        rtb_Mul_mxn[1] = rtb_VectorConcatenate_a[0] * rtb_VectorConcatenate_a[0];
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product/Functionality'/Mul' */
        rtb_VectorConcatenate_nj[0] = rtb_VectorConcatenate_b[0];
        rtb_VectorConcatenate_nj[1] = rtb_VectorConcatenate_a[0];
        for (i = 0; i < 2; i++) {
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Mul4/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Gain2_const'/Constant'
                         */
            rtb_Mul_mx[i] = rtb_Mul_mxn[i] * 0.5F;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Gain3/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Gain3_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product/Functionality'/Mul'
                         */
            rtb_VectorConcatenate_a[i] = (rtb_VectorConcatenate_nj[i] * rtb_Mul_mxn[i]) * 0.166666672F;
        }
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Subtract/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product2/Functionality'/Mul'
                 */
        rtb_TrigonometricFunction_eq = (rtb_VectorConcatenate_a[0] * rtb_Mul_mx[1]) - (rtb_VectorConcatenate_a[1] * rtb_Mul_mx[0]);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Div/In3'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product6/In3'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Div'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product5/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Div'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Subtract1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Subtract2/Functionality'/Sum'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Switch'
                 */
        if (rtb_TrigonometricFunction_eq != 0.0F) {
            for (i = 0; i < 2; i++) {
                rtb_Mul_mx[i] *= rtb_Mul_fo[i];
                rtb_Mul_fo[i] *= rtb_VectorConcatenate_a[i];
            }
            BI_tpllco_Switch_j = (rtb_Mul_mx[1] - rtb_Mul_mx[0]) / rtb_TrigonometricFunction_eq;
            rtb_TrigonometricFunction_eq = (rtb_Mul_fo[0] - rtb_Mul_fo[1]) / rtb_TrigonometricFunction_eq;
        } else {
            BI_tpllco_Switch_j = 0.0F;
            rtb_TrigonometricFunction_eq = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Application Parameter1'/Constant'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Relational Operator/Functionality'/LT'
                 */
        if (rtb_S_CSCLTA_LeCridrBndLength_met < GET_P_TPLLCO_CoordTrafoMinLength_met ()) {
            rtb_Sum_kq = rtb_S_CSCLTA_LeCridrBndLength_met;
        } else {
            rtb_Sum_kq = rtb_VectorConcatenate_b[0];
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor'/Coordinate_Transformation' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Constant'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Add2/Functionality'/Sum'
                 */
        BI_tpllco_Sum_np = rtb_Sum_kq - (0.0F - rtb_Sum_mr[0]);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Add6/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Constant'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Add2/Functionality'/Sum'
                 */
        BI_tpllco_Sum_ji = ((0.0F - rtb_Sum_mr[0]) * BI_tpllco_Switch_j) + rtb_TrigonometricFunction_eq;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation'/Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation'/Corridor_Trajectory_Equation':
                 *  X.2.1.1.1.2.1.1.1.1
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.1.1.1.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_ei = (rtb_Sum_oy + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_iq = f32_floor_f32(BI_tpllco_Div_ei);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_kq = (rtb_Sum_oy + 1.57079506F) - (rtb_MathFunction_iq * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_kq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_kq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_kq >= -0.0174532775F) {
                rtb_Sum_gx = -(0.0174532775F + rtb_Sum_kq);
            } else {
                rtb_Sum_gx = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_gx = 0.0174532775F - rtb_Sum_kq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 */
        rtb_Sum_oy = f32_tan_f32(rtb_Sum_oy + rtb_Sum_gx);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Constant'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
                 */
        rtb_Sum_gx = (0.0F - rtb_Sum_mr[0]) * (0.0F - rtb_Sum_mr[0]);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Constant'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 */
        BI_tpllco_VectorConcatenate_a[1] = (((((0.0F - rtb_Sum_mr[0]) * rtb_Sum_gx) * BI_tpllco_Switch_j) * 0.166666672F) + (((0.0F - rtb_Sum_mr[0]) * rtb_Sum_oy) + ((rtb_TrigonometricFunction_eq * rtb_Sum_gx) * 0.5F))) + rtb_Sum_mr[1];
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Min/Functionality'/Min' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain3_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant4'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant5'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Constant'/Constant'
                 *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Max/Functionality'/Max'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product4/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum3/Functionality'/Sum'
                 */
        rtb_Sum_gx = f32_min_f32_f32(f32_max_f32_f32((((BI_tpllco_Switch_j * rtb_Sum_gx) * 0.5F) + rtb_Sum_oy) + ((0.0F - rtb_Sum_mr[0]) * rtb_TrigonometricFunction_eq), -1.0F), 1.0F);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Abs/Functionality'/Abs'
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Abs1/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant2'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant3'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul4/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum2/Functionality'/Sum'
                 */
        BI_tpllco_Sum_je = (0.785398185F * rtb_Sum_gx) - (((f32_abs_f32(rtb_Sum_gx) - 1.0F) * rtb_Sum_gx) * ((f32_abs_f32(rtb_Sum_gx) * 0.0663F) + 0.2447F));
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain2'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Constant'/Constant'
                 */
        BI_tpllco_VectorConcatenate_a[0] = 0.0F;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_LeftCorridor/Trajectory_Translation'/Corridor_Trajectory_Equation' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation'/Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation'/Corridor_Trajectory_Equation':
                 *  X.2.1.1.1.2.1.2.1.1
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.2.1.1.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_k = (rtb_Sum_dg + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_jl = f32_floor_f32(BI_tpllco_Div_k);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_oy = (rtb_Sum_dg + 1.57079506F) - (rtb_MathFunction_jl * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_oy >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_oy -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_oy >= -0.0174532775F) {
                rtb_TrigonometricFunction_eq = -(0.0174532775F + rtb_Sum_oy);
            } else {
                rtb_TrigonometricFunction_eq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_TrigonometricFunction_eq = 0.0174532775F - rtb_Sum_oy;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 */
        rtb_Sum_oy = f32_tan_f32(rtb_Sum_dg + rtb_TrigonometricFunction_eq);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 */
        rtb_TrigonometricFunction_eq = BI_tpllco_copy1[0] - rtb_Mul_a3;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
        rtb_Sum_kq = rtb_TrigonometricFunction_eq * rtb_TrigonometricFunction_eq;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 */
        rtb_VectorConcatenate_eq[1] = ((((rtb_Sum_mo * rtb_Sum_kq) * 0.5F) + (rtb_Sum_oy * rtb_TrigonometricFunction_eq)) + (((rtb_Sum_kq * rtb_TrigonometricFunction_eq) * rtb_Mul_h4) * 0.166666672F)) + rtb_Max_af;
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Min/Functionality'/Min' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain3_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant4'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant5'/Constant'
                 *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Max/Functionality'/Max'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Product4/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Sum3/Functionality'/Sum'
                 */
        rtb_Sum_kq = f32_min_f32_f32(f32_max_f32_f32((((rtb_Mul_h4 * rtb_Sum_kq) * 0.5F) + rtb_Sum_oy) + (rtb_Sum_mo * rtb_TrigonometricFunction_eq), -1.0F), 1.0F);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Abs/Functionality'/Abs'
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Abs1/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant2'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Constant3'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Mul4/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/ApproxAtan/Sum2/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = (0.785398185F * rtb_Sum_kq) - (((f32_abs_f32 (rtb_Sum_kq) - 1.0F) * rtb_Sum_kq) * ((f32_abs_f32(rtb_Sum_kq) * 0.0663F) + 0.2447F));
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Corridor_Trajectory_Equation/Gain2'/Data Type Conversion' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 */
        rtb_VectorConcatenate_eq[0] = BI_tpllco_copy1[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation'/Corridor_Trajectory_Equation' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Add2/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 */
        rtb_Sum_gx = BI_tpllco_copy1[0] - rtb_Mul_a3;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Add6/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Product1/Functionality'/Mul'
                 */
        rtb_Sum_kq = (rtb_Sum_gx * rtb_Mul_h4) + rtb_Sum_mo;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Trajectory_Translation/Add1/Functionality'/Sum' */
        rtb_Sum_oy = rtb_Mul_f2 - rtb_Sum_gx;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Coordinate_Transformation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Coordinate_Transformation':
                 *  X.2.1.1.1.2.1.2.2
                 */
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/MinMax/Functionality'/Max' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Application Parameter1'/Constant'
                 */
        rtb_Mul_pv = f32_max_f32_f32(rtb_Sum_oy, GET_P_TPLLCO_CoordTrafoMinLength_met());
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Gain1_const'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Gain1/Functionality'/Mul'
                 */
        rtb_Sum_gx = (rtb_Mul_pv * 0.5F) + BI_tpllco_copy1[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add2/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 */
        rtb_Mul_pv += BI_tpllco_copy1[0];
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation':
                 *  X.2.1.1.1.2.1.2.2.1
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.2.2.1.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_g = (rtb_TrigonometricFunction_eq + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_l2 = f32_floor_f32(BI_tpllco_Div_g);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_fc = (rtb_TrigonometricFunction_eq + 1.57079506F) - (rtb_MathFunction_l2 * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_fc >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_fc -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_fc >= -0.0174532775F) {
                rtb_Sum_fc = -(0.0174532775F + rtb_Sum_fc);
            } else {
                rtb_Sum_fc = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_fc = 0.0174532775F - rtb_Sum_fc;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 */
        rtb_Sum_aft = rtb_Mul_pv - BI_tpllco_copy1[0];
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
        rtb_Mul_ei = rtb_Sum_aft * rtb_Sum_aft;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.2.2.1.2
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_l[1] = (((f32_tan_f32(rtb_TrigonometricFunction_eq + rtb_Sum_fc) * rtb_Sum_aft) + ((rtb_Sum_kq * rtb_Mul_ei) * 0.5F)) + (((rtb_Mul_ei * rtb_Sum_aft) * rtb_Mul_h4) * 0.166666672F)) + rtb_VectorConcatenate_eq[1];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain2'/Data Type Conversion' */
        rtb_VectorConcatenate_l[0] = rtb_Mul_pv;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation' */
        for (i = 0; i < 2; i++) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add4/Functionality'/Sum' */
            rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_eq[i] - BI_tpllco_copy1[i];
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add3/Functionality'/Sum' */
            rtb_VectorConcatenate_l[i] -= BI_tpllco_copy1[i];
        }
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1':
                 *  X.2.1.1.1.2.1.2.2.5
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.2.2.5.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_bt = (rtb_TrigonometricFunction_eq + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_n = f32_floor_f32(BI_tpllco_Div_bt);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Mul_pv = (rtb_TrigonometricFunction_eq + 1.57079506F) - (rtb_MathFunction_n * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Mul_pv >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Mul_pv -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Mul_pv >= -0.0174532775F) {
                rtb_Mul_pv = -(0.0174532775F + rtb_Mul_pv);
            } else {
                rtb_Mul_pv = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Mul_pv = 0.0174532775F - rtb_Mul_pv;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Add3/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Constant'/Constant'
                 *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Index Vector'
                 */
        rtb_Sum_fc = rtb_Sum_gx - BI_tpllco_copy1[0];
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul/Functionality'/Mul' */
        rtb_Sum_aft = rtb_Sum_fc * rtb_Sum_fc;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.2.2.5.2
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_f2[1] = (((f32_tan_f32(rtb_TrigonometricFunction_eq + rtb_Mul_pv) * rtb_Sum_fc) + ((rtb_Sum_kq * rtb_Sum_aft) * 0.5F)) + (((rtb_Sum_aft * rtb_Sum_fc) * rtb_Mul_h4) * 0.166666672F)) + rtb_VectorConcatenate_eq[1];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain2'/Data Type Conversion' */
        rtb_VectorConcatenate_f2[0] = rtb_Sum_gx;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add6/Functionality'/Sum' */
        BI_tpllco_Sum_d = rtb_TrigonometricFunction_eq - BI_tpllco__TPLLCO_RightOri_rad;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1':
                 *  X.2.1.1.1.2.1.2.2.2
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Neg/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Neg/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product1/Functionality'/Mul' */
        rtb_VectorConcatenate_b[0] = rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_l[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Neg/Functionality'/Unary Minus'
                 */
        rtb_VectorConcatenate_l[0] = (rtb_VectorConcatenate_l[0] * rtb_Sum_kq) + (rtb_VectorConcatenate_l[1] * (-rtb_TrigonometricFunction_eq));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_l[1] = (rtb_Sum_kq * rtb_VectorConcatenate_l[1]) + rtb_VectorConcatenate_b[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2':
                 *  X.2.1.1.1.2.1.2.2.3
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Neg1/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Neg1/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Neg/Functionality'/Unary Minus'
                 */
        BI_tpllco_VectorConcatenate_o[0] = (rtb_VectorConcatenate_a[0] * rtb_Sum_kq) + (rtb_VectorConcatenate_a[1] * (-rtb_TrigonometricFunction_eq));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product1/Functionality'/Mul'
                 */
        BI_tpllco_VectorConcatenate_o[1] = (rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_a[0]) + (rtb_Sum_kq * rtb_VectorConcatenate_a[1]);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2' */
        for (i = 0; i < 2; i++) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add5/Functionality'/Sum' */
            rtb_VectorConcatenate_f2[i] -= BI_tpllco_copy1[i];
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add7/Functionality'/Sum' */
            rtb_VectorConcatenate_l[i] -= BI_tpllco_VectorConcatenate_o[i];
        }
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3':
                 *  X.2.1.1.1.2.1.2.2.4
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Neg2/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Neg2/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product1/Functionality'/Mul' */
        rtb_VectorConcatenate_a[0] = rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_f2[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Neg/Functionality'/Unary Minus'
                 */
        rtb_VectorConcatenate_f2[0] = (rtb_VectorConcatenate_f2[0] * rtb_Sum_kq) + (rtb_VectorConcatenate_f2[1] * (-rtb_TrigonometricFunction_eq));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_f2[1] = (rtb_Sum_kq * rtb_VectorConcatenate_f2[1]) + rtb_VectorConcatenate_a[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add8/Functionality'/Sum' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_f2[i] -= BI_tpllco_VectorConcatenate_o[i];
        }
        /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add8/Functionality'/Sum' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.2.2.6
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_m = (BI_tpllco_Sum_d + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_ox = f32_floor_f32(BI_tpllco_Div_m);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = (BI_tpllco_Sum_d + 1.57079506F) - (rtb_MathFunction_ox * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_TrigonometricFunction_eq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_TrigonometricFunction_eq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_TrigonometricFunction_eq >= -0.0174532775F) {
                rtb_Sum_kq = -(0.0174532775F + rtb_TrigonometricFunction_eq);
            } else {
                rtb_Sum_kq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_kq = 0.0174532775F - rtb_TrigonometricFunction_eq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/TanNinety_V4/Add4/Functionality'/Sum'
                 */
        rtb_Mul_pv = f32_tan_f32(BI_tpllco_Sum_d + rtb_Sum_kq);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Add9/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_eq[0] = rtb_VectorConcatenate_f2[1] - (rtb_VectorConcatenate_f2[0] * rtb_Mul_pv);
        rtb_VectorConcatenate_eq[1] = rtb_VectorConcatenate_l[1] - (rtb_VectorConcatenate_l[0] * rtb_Mul_pv);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Mul/Functionality'/Mul' */
        rtb_VectorConcatenate_a[0] = rtb_VectorConcatenate_l[0] * rtb_VectorConcatenate_l[0];
        rtb_VectorConcatenate_a[1] = rtb_VectorConcatenate_f2[0] * rtb_VectorConcatenate_f2[0];
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product/Functionality'/Mul' */
        rtb_VectorConcatenate_m[0] = rtb_VectorConcatenate_l[0];
        rtb_VectorConcatenate_m[1] = rtb_VectorConcatenate_f2[0];
        for (i = 0; i < 2; i++) {
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Mul4/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Gain2_const'/Constant'
                         */
            rtb_VectorConcatenate_b[i] = rtb_VectorConcatenate_a[i] * 0.5F;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Gain3/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Gain3_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product/Functionality'/Mul'
                         */
            rtb_VectorConcatenate_f2[i] = (rtb_VectorConcatenate_m[i] * rtb_VectorConcatenate_a[i]) * 0.166666672F;
        }
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Subtract/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product2/Functionality'/Mul'
                 */
        rtb_TrigonometricFunction_eq = (rtb_VectorConcatenate_f2[0] * rtb_VectorConcatenate_b[1]) - (rtb_VectorConcatenate_f2[1] * rtb_VectorConcatenate_b[0]);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Div/In3'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product6/In3'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Div'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product5/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Div'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Subtract1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Subtract2/Functionality'/Sum'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Switch'
                 */
        if (rtb_TrigonometricFunction_eq != 0.0F) {
            for (i = 0; i < 2; i++) {
                rtb_VectorConcatenate_b[i] *= rtb_VectorConcatenate_eq[i];
                rtb_VectorConcatenate_eq[i] *= rtb_VectorConcatenate_f2[i];
            }
            BI_tpllco_Switch_m = (rtb_VectorConcatenate_b[1] - rtb_VectorConcatenate_b[0]) / rtb_TrigonometricFunction_eq;
            BI_tpllco_Switch_e = (rtb_VectorConcatenate_eq[0] - rtb_VectorConcatenate_eq[1]) / rtb_TrigonometricFunction_eq;
        } else {
            BI_tpllco_Switch_m = 0.0F;
            BI_tpllco_Switch_e = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Application Parameter1'/Constant'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Relational Operator/Functionality'/LT'
                 */
        if (rtb_Sum_oy < GET_P_TPLLCO_CoordTrafoMinLength_met()) {
            BI_tpllco_Switch_mv = rtb_Sum_oy;
        } else {
            BI_tpllco_Switch_mv = rtb_VectorConcatenate_l[0];
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_RightCorridor'/Coordinate_Transformation' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor'/Coordinate_Transformation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor'/Coordinate_Transformation':
                 *  X.2.1.1.1.2.1.3.1
                 */
        /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/MinMax/Functionality'/Max' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Application Parameter1'/Constant'
                 */
        rtb_TrigonometricFunction_eq = f32_max_f32_f32 (rtb_S_CSCLTA_TgtTrajLength_met, GET_P_TPLLCO_CoordTrafoMinLength_met());
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Gain1_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Gain1/Functionality'/Mul'
                 */
        rtb_Sum_oy = (rtb_TrigonometricFunction_eq * 0.5F) + rtb_S_CSCLTA_TgtTrajPosX0_met;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add2/Functionality'/Sum' */
        rtb_TrigonometricFunction_eq += rtb_S_CSCLTA_TgtTrajPosX0_met;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation':
                 *  X.2.1.1.1.2.1.3.1.1
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.3.1.1.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_fb = (rtb_S_CSCLTA_TgtTrajHeadAng_rad + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_m = f32_floor_f32(BI_tpllco_Div_fb);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_kq = (rtb_S_CSCLTA_TgtTrajHeadAng_rad + 1.57079506F) - (rtb_MathFunction_m * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_kq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_kq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_kq >= -0.0174532775F) {
                rtb_Sum_kq = -(0.0174532775F + rtb_Sum_kq);
            } else {
                rtb_Sum_kq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_Sum_kq = 0.0174532775F - rtb_Sum_kq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' */
        rtb_Sum_gx = rtb_TrigonometricFunction_eq - rtb_S_CSCLTA_TgtTrajPosX0_met;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
        rtb_Mul_pv = rtb_Sum_gx * rtb_Sum_gx;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.3.1.1.2
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_pd[1] = (((f32_tan_f32(rtb_S_CSCLTA_TgtTrajHeadAng_rad + rtb_Sum_kq) * rtb_Sum_gx) + ((rtb_S_CSCLTA_TgtTrajCrv_1pm * rtb_Mul_pv) * 0.5F)) + (((rtb_Mul_pv * rtb_Sum_gx) * rtb_S_CSCLTA_TgtTrajCrvChng_1pm2) * 0.166666672F)) + rtb_S_CSCLTA_TgtTrajPosY0_met;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation'/TanNinety_V4' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation/Gain2'/Data Type Conversion' */
        rtb_VectorConcatenate_pd[0] = rtb_TrigonometricFunction_eq;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add3/Functionality'/Sum' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_pd[i] -= BI_tpllco_copy1[i];
        }
        /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add3/Functionality'/Sum' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add4/Functionality'/Sum' */
        rtb_VectorConcatenate_f2[0] = rtb_S_CSCLTA_TgtTrajPosX0_met - BI_tpllco_copy1[0];
        rtb_VectorConcatenate_f2[1] = rtb_S_CSCLTA_TgtTrajPosY0_met - BI_tpllco_copy1[1];
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1':
                 *  X.2.1.1.1.2.1.3.1.5
                 */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.3.1.5.2
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_dc = (rtb_S_CSCLTA_TgtTrajHeadAng_rad + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_j = f32_floor_f32(BI_tpllco_Div_dc);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = (rtb_S_CSCLTA_TgtTrajHeadAng_rad + 1.57079506F) - (rtb_MathFunction_j * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_TrigonometricFunction_eq >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_TrigonometricFunction_eq -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_TrigonometricFunction_eq >= -0.0174532775F) {
                rtb_TrigonometricFunction_eq = -(0.0174532775F + rtb_TrigonometricFunction_eq);
            } else {
                rtb_TrigonometricFunction_eq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_TrigonometricFunction_eq = 0.0174532775F - rtb_TrigonometricFunction_eq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Add3/Functionality'/Sum' */
        rtb_Sum_kq = rtb_Sum_oy - rtb_S_CSCLTA_TgtTrajPosX0_met;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul/Functionality'/Mul' */
        rtb_Sum_gx = rtb_Sum_kq * rtb_Sum_kq;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.3.1.5.2
                 */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain1_const'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain_const'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Product/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Product1/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/TanNinety_V4/Add4/Functionality'/Sum'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_bh[1] = (((f32_tan_f32(rtb_S_CSCLTA_TgtTrajHeadAng_rad + rtb_TrigonometricFunction_eq) * rtb_Sum_kq) + ((rtb_S_CSCLTA_TgtTrajCrv_1pm * rtb_Sum_gx) * 0.5F)) + (((rtb_Sum_gx * rtb_Sum_kq) * rtb_S_CSCLTA_TgtTrajCrvChng_1pm2) * 0.166666672F)) + rtb_S_CSCLTA_TgtTrajPosY0_met;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1'/TanNinety_V4' */
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Corridor_Trajectory_Equation1/Gain2'/Data Type Conversion' */
        rtb_VectorConcatenate_bh[0] = rtb_Sum_oy;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Corridor_Trajectory_Equation1' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add6/Functionality'/Sum' */
        BI_tpllco_Sum_f5 = rtb_S_CSCLTA_TgtTrajHeadAng_rad - BI_tpllco__TPLLCO_RightOri_rad;
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1':
                 *  X.2.1.1.1.2.1.3.1.2
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Neg/Functionality'/Unary Minus'
                 */
        rtb_Sum_oy = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Neg/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product1/Functionality'/Mul' */
        rtb_VectorConcatenate_eq[0] = rtb_Sum_oy * rtb_VectorConcatenate_pd[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Neg/Functionality'/Unary Minus'
                 */
        rtb_VectorConcatenate_pd[0] = (rtb_VectorConcatenate_pd[0] * rtb_TrigonometricFunction_eq) + (rtb_VectorConcatenate_pd[1] * (-rtb_Sum_oy));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_1/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_pd[1] = (rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_pd[1]) + rtb_VectorConcatenate_eq[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_1' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2':
                 *  X.2.1.1.1.2.1.3.1.3
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Neg1/Functionality'/Unary Minus'
                 */
        rtb_Sum_oy = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Neg1/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Neg/Functionality'/Unary Minus'
                 */
        BI_tpllco_VectorConcatenate_i[0] = (rtb_VectorConcatenate_f2[0] * rtb_TrigonometricFunction_eq) + (rtb_VectorConcatenate_f2[1] * (-rtb_Sum_oy));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_2/Product1/Functionality'/Mul'
                 */
        BI_tpllco_VectorConcatenate_i[1] = (rtb_Sum_oy * rtb_VectorConcatenate_f2[0]) + (rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_f2[1]);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_2' */
        for (i = 0; i < 2; i++) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add5/Functionality'/Sum' */
            rtb_VectorConcatenate_bh[i] -= BI_tpllco_copy1[i];
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add7/Functionality'/Sum' */
            rtb_VectorConcatenate_pd[i] -= BI_tpllco_VectorConcatenate_i[i];
        }
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3':
                 *  X.2.1.1.1.2.1.3.1.4
                 */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Neg2/Functionality'/Unary Minus'
                 */
        rtb_Sum_oy = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Neg2/Functionality'/Unary Minus'
                 */
        rtb_TrigonometricFunction_eq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product1/Functionality'/Mul' */
        rtb_VectorConcatenate_l[0] = rtb_Sum_oy * rtb_VectorConcatenate_bh[0];
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Sum of Elements/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product/Functionality'/Mul'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Neg/Functionality'/Unary Minus'
                 */
        rtb_VectorConcatenate_bh[0] = (rtb_VectorConcatenate_bh[0] * rtb_TrigonometricFunction_eq) + (rtb_VectorConcatenate_bh[1] * (-rtb_Sum_oy));
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Sum of Elements1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Rotate_Anticlockwise_3/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_bh[1] = (rtb_TrigonometricFunction_eq * rtb_VectorConcatenate_bh[1]) + rtb_VectorConcatenate_l[0];
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/Rotate_Anticlockwise_3' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add8/Functionality'/Sum' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_bh[i] -= BI_tpllco_VectorConcatenate_i[i];
        }
        /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add8/Functionality'/Sum' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/TanNinety_V4'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/TanNinety_V4':
                 *  X.2.1.1.1.2.1.3.1.6
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant1'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        BI_tpllco_Div_fo = (BI_tpllco_Sum_f5 + 1.57079506F) / 3.14159F;
        /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_g = f32_floor_f32(BI_tpllco_Div_fo);
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant2'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Add/Functionality'/Sum'
                 */
        rtb_Sum_oy = (BI_tpllco_Sum_f5 + 1.57079506F) - (rtb_MathFunction_g * 3.14159F);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant4'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Add1/Functionality'/Sum'
                 */
        if (rtb_Sum_oy >= 0.0174532775F) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant5'/Constant'
                         */
            rtb_Sum_oy -= 3.14159F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant6'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Constant7'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Sum/Functionality'/Sum'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                         */
            if (rtb_Sum_oy >= -0.0174532775F) {
                rtb_TrigonometricFunction_eq = -(0.0174532775F + rtb_Sum_oy);
            } else {
                rtb_TrigonometricFunction_eq = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Switch4/Functionality'/Switch' */
        } else {
            rtb_TrigonometricFunction_eq = 0.0174532775F - rtb_Sum_oy;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Switch1/Functionality'/Switch' */
        /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/TanNinety_V4/Add4/Functionality'/Sum'
                 */
        rtb_TrigonometricFunction_eq = f32_tan_f32(BI_tpllco_Sum_f5 + rtb_TrigonometricFunction_eq);
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation'/TanNinety_V4' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Add9/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product1/Functionality'/Mul'
                 */
        rtb_VectorConcatenate_f2[0] = rtb_VectorConcatenate_bh[1] - (rtb_VectorConcatenate_bh[0] * rtb_TrigonometricFunction_eq);
        rtb_VectorConcatenate_f2[1] = rtb_VectorConcatenate_pd[1] - (rtb_VectorConcatenate_pd[0] * rtb_TrigonometricFunction_eq);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Mul/Functionality'/Mul' */
        rtb_VectorConcatenate_l[0] = rtb_VectorConcatenate_pd[0] * rtb_VectorConcatenate_pd[0];
        rtb_VectorConcatenate_l[1] = rtb_VectorConcatenate_bh[0] * rtb_VectorConcatenate_bh[0];
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product/Functionality'/Mul' */
        rtb_VectorConcatenate_jg[0] = rtb_VectorConcatenate_pd[0];
        rtb_VectorConcatenate_jg[1] = rtb_VectorConcatenate_bh[0];
        for (i = 0; i < 2; i++) {
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Mul4/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Gain2_const'/Constant'
                         */
            rtb_VectorConcatenate_eq[i] = rtb_VectorConcatenate_l[i] * 0.5F;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Gain3/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Gain3_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product/Functionality'/Mul'
                         */
            rtb_VectorConcatenate_bh[i] = (rtb_VectorConcatenate_jg[i] * rtb_VectorConcatenate_l[i]) * 0.166666672F;
        }
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Subtract/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product2/Functionality'/Mul'
                 */
        rtb_Sum_oy = (rtb_VectorConcatenate_bh[0] * rtb_VectorConcatenate_eq[1]) - (rtb_VectorConcatenate_bh[1] * rtb_VectorConcatenate_eq[0]);
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Div/In3'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product6/In3'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Div'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product3/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product5/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Div'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Subtract1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Subtract2/Functionality'/Sum'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Product6/Functionality/DivDefault'/Switch'
                 */
        if (rtb_Sum_oy != 0.0F) {
            for (i = 0; i < 2; i++) {
                rtb_VectorConcatenate_eq[i] *= rtb_VectorConcatenate_f2[i];
                rtb_VectorConcatenate_f2[i] *= rtb_VectorConcatenate_bh[i];
            }
            BI_tpllco_Switch_o = (rtb_VectorConcatenate_eq[1] - rtb_VectorConcatenate_eq[0]) / rtb_Sum_oy;
            BI_tpllco_Switch_h = (rtb_VectorConcatenate_f2[0] - rtb_VectorConcatenate_f2[1]) / rtb_Sum_oy;
        } else {
            BI_tpllco_Switch_o = 0.0F;
            BI_tpllco_Switch_h = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Div/Functionality/DivDefault'/Switch' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Application Parameter1'/Constant'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Relational Operator/Functionality'/LT'
                 */
        if (rtb_S_CSCLTA_TgtTrajLength_met < GET_P_TPLLCO_CoordTrafoMinLength_met()) {
            BI_tpllco_Switch_of = rtb_S_CSCLTA_TgtTrajLength_met;
        } else {
            BI_tpllco_Switch_of = rtb_VectorConcatenate_pd[0];
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor/Coordinate_Transformation/Switch/Functionality'/Switch' */
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_AllCorridors/Set_TargetCorridor'/Coordinate_Transformation' */
    }
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs'/Set_AllCorridors' */
    /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO'/Corridor_Trajectory_Equation'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO'/Corridor_Trajectory_Equation':
         *  X.2.1.1.2
         */
    /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation'/TanNinety_V4'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation'/TanNinety_V4':
         *  X.2.1.1.2.2
         */
    /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
         */
    BI_tpllco_Div_fp = (BI_tpllco_Sum_f5 + 1.57079506F) / 3.14159F;
    /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
    rtb_MathFunction_ee = f32_floor_f32(BI_tpllco_Div_fp);
    /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
         */
    rtb_Sum_oy = (BI_tpllco_Sum_f5 + 1.57079506F) - (rtb_MathFunction_ee * 3.14159F);
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
         */
    if (rtb_Sum_oy >= 0.0174532775F) {
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                 */
        rtb_Sum_oy -= 3.14159F;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                 */
        if (rtb_Sum_oy >= -0.0174532775F) {
            rtb_TrigonometricFunction_eq = -(0.0174532775F + rtb_Sum_oy);
        } else {
            rtb_TrigonometricFunction_eq = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
    } else {
        rtb_TrigonometricFunction_eq = 0.0174532775F - rtb_Sum_oy;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
    /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function' incorporates:
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
         */
    rtb_Sum_oy = f32_tan_f32(BI_tpllco_Sum_f5 + rtb_TrigonometricFunction_eq);
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation'/TanNinety_V4' */
    /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/constant_value'/Constant'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
         */
    rtb_Sum_kq = (0.0F - BI_tpllco_VectorConcatenate_i[0]) * (0.0F - BI_tpllco_VectorConcatenate_i[0]);
    /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/constant_value'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Gain1_const'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Gain_const'/Constant'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
         */
    SET_S_TPLLCO_TargetPathY0_met((((((0.0F - BI_tpllco_VectorConcatenate_i[0]) * rtb_Sum_kq) * BI_tpllco_Switch_o) * 0.166666672F) + (((0.0F - BI_tpllco_VectorConcatenate_i[0]) * rtb_Sum_oy) + ((BI_tpllco_Switch_h * rtb_Sum_kq) * 0.5F))) + BI_tpllco_VectorConcatenate_i[1]);
    /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Min/Functionality'/Min' incorporates:
                                               *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/constant_value'/Constant'
                                               *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Gain3_const'/Constant'
                                               *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Constant4'/Constant'
                                               *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Constant5'/Constant'
                                               *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Max/Functionality'/Max'
                                               *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Gain3/Functionality'/Mul'
                                               *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Product3/Functionality'/Mul'
                                               *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Product4/Functionality'/Mul'
                                               *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
                                               *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Sum2/Functionality'/Sum'
                                               *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Sum3/Functionality'/Sum'
                                               */
    rtb_Sum_kq = f32_min_f32_f32(f32_max_f32_f32((((BI_tpllco_Switch_o * rtb_Sum_kq) * 0.5F) + rtb_Sum_oy) + ((0.0F - BI_tpllco_VectorConcatenate_i[0]) * BI_tpllco_Switch_h), -1.0F), 1.0F);
    /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' incorporates:
         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Abs/Functionality'/Abs'
         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Abs1/Functionality'/Abs'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Constant'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Constant1'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Constant2'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Constant3'/Constant'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Mul1/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Mul2/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Mul3/Functionality'/Mul'
         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Mul4/Functionality'/Mul'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/ApproxAtan/Sum2/Functionality'/Sum'
         */
    SET_S_TPLLCO_TargetPathHeading_rad((0.785398185F * rtb_Sum_kq) - (((f32_abs_f32(rtb_Sum_kq) - 1.0F) * rtb_Sum_kq) * ((f32_abs_f32(rtb_Sum_kq) * 0.0663F) + 0.2447F)));
    /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Sum4/Functionality'/Sum' incorporates:
                                            *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/constant_value'/Constant'
                                            *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Product2/Functionality'/Mul'
                                            *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Corridor_Trajectory_Equation/Add3/Functionality'/Sum'
                                            */
    SET_S_TPLLCO_TargetPathCrv_rad(((0.0F - BI_tpllco_VectorConcatenate_i[0]) * BI_tpllco_Switch_o) + BI_tpllco_Switch_h);
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO'/Corridor_Trajectory_Equation' */
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/branch1'/copy1' */
    SET_D_TPLLCO_CCCPassedPerc_nu(BI_tpllco_Switch_k);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/branch2'/copy1' */
    SET_D_TPLLCO_CCCReset_nu(BI_tpllco_Unit_Delay10);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/branch3'/copy1' */
    SET_D_TPLLCO_CCCLength_met(BI_tpllco_Switch_l);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/branch4'/copy1' */
    SET_D_TPLLCO_CCCTestPointDistX_met(BI_tpllco_Sum_o4);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Course_Consistence_Check/branch5'/copy1' */
    SET_D_TPLLCO_CCCDeviation_met(BI_tpllco_Sum_b);
    /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Add1/Functionality'/Sum' incorporates:
                                                *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Constant4'/Constant'
                                                *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator'/Unit_Delay'
                                                */
    rtb_sfun_setbit_n = u8_u32(((uint32)((sint32)DW_tpllco_Unit_Delay_DSTATE_h)) + 1U);
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Constant'/Constant'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Relational  Operator1/Functionality'/LT'
         */
    if (((sint32)rtb_sfun_setbit_n) < 25) {
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator'/Unit_Delay' */
        DW_tpllco_Unit_Delay_DSTATE_h = rtb_sfun_setbit_n;
    } else {
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator'/Unit_Delay' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Constant1'/Constant'
                 */
        DW_tpllco_Unit_Delay_DSTATE_h = 0U;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data/IndexGenerator/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Constant2'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Constant3'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Equality2/Functionality'/EQ'
         */
    if (((sint32)GET_P_TPLLCO_CalculationbyRampout_nu()) != 0) {
        rtb_sfun_setbit_n = (uint8)(((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)) == ((sint32) GET_S_CSCLTA_SysStateLCF_enum()));
    } else {
        rtb_sfun_setbit_n = 0U;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Constant'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Constant1'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/from_data_definition'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Equality/Functionality'/EQ'
         */
    if (((sint32)GET_P_TPLLCO_CalculationbyRequest_nu()) != 0) {
        rtb_Switch_lp = (uint8)(((sint32)GET_S_CSCLTA_SysStateLCF_enum()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)));
    } else {
        rtb_Switch_lp = 0U;
    }
    /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Switch/Functionality'/Switch' */
    /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs'/Set_Dev_ReplanDelta' incorporates:
         *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Enable'
         *
         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs'/Set_Dev_ReplanDelta':
         *  X.2.1.1.1.2.2
         */
    /* Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/OR/Functionality'/OR' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Application Parameter'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/LOWPASST_RE'/E'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/Equality1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Y_TPLLCO_VehCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay2'
         */
    if ((((((sint32)rtb_sfun_setbit_n) != 0) || (((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) GET_S_CSCLTA_SysStateLCF_enum()))) || (((sint32)rtb_Switch_lp) != 0)) > 0) {
        if (!((sint32)DW_tpllco_Set_Dev_ReplanDelta_MODE)) {
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay2' */
            DW_tpllco_Unit_Delay2_DSTATE_j = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading'/Unit_Delay' */
            DW_tpllco_Unit_Delay_DSTATE_f = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Unit_Delay1' */
            for (i = 0; i < 2; i++) {
                DW_tpllco_Unit_Delay1_DSTATE[i] = 0.0F;
            }
            /* End of InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Unit_Delay1' */
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
            DW_tpllco_Unit_Delay_1_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
            DW_tpllco_Unit_Delay_2_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
            DW_tpllco_Unit_Delay_3_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
            DW_tpllco_Unit_Delay_4_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
            DW_tpllco_Unit_Delay_5_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit Delay3' */
            DW_tpllco_UnitDelay3_DSTATE = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay1' */
            DW_tpllco_Unit_Delay1_DSTATE_g = 0.0F;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay4' */
            DW_tpllco_Unit_Delay4_DSTATE = 0U;
            /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay3' */
            DW_tpllco_Unit_Delay3_DSTATE = 0.0F;
            DW_tpllco_Set_Dev_ReplanDelta_MODE = (uint8)1U;
        }
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Subtract5/Functionality'/Sum' */
        rtb_Sum_oy = BI_tpllco_Unit_Delay - BI_tpllco__TPLLCO_RightOri_rad;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading/Subtract7/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading'/Unit_Delay'
                 */
        rtb_Switch_gv += DW_tpllco_Unit_Delay_DSTATE_f;
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Subtract1/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Mul/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Mul1/Functionality'/Mul'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Trigonom/Functionality'/Trigonometric Function'
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Trigonom1/Functionality'/Trigonometric Function'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Unit_Delay1'
                 */
        rtb_VectorConcatenate_bh[0] = (f32_cos_f32(rtb_Switch_gv) * rtb_Switch_oi) + DW_tpllco_Unit_Delay1_DSTATE[0];
        rtb_VectorConcatenate_bh[1] = (rtb_Switch_oi * f32_sin_f32(rtb_Switch_gv)) + DW_tpllco_Unit_Delay1_DSTATE[1];
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Calc_Ctrl_Point'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Calc_Ctrl_Point':
                 *  X.2.1.1.1.2.2.3.2
                 */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Application Parameter1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Constant'/Constant'
                 *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Min/Functionality'/Min'
                 */
        if (((sint32)GET_P_TPLLCO_PreviewDistXEnable_nu()) != 0) {
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Switch2/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistXOBF_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistX_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         */
            if (((sint32)rtb_DataTypeConversion_pk) != 0) {
                /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistXOBF_met/Functionality'/ip_lookup_fxpt_sfun_7 */
                {
                    FDPS_RESULT dps_result_ln;
                    /* Calculate value */
                    /* Find indices on X Axis: X_TPLLCO_VehVelX_mps */
                    FDPS_PTR_F32(GETA_X_TPLLCO_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
                    /* Direct accesing curve (used as module input) */
                    rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_TPLLCO_PreviewDistXOBF_met(), &dps_result_ln);
                }
                rtb_Switch_oi = rtb_ip_lookup_fxpt_sfun_7_n;
            } else {
                /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Y_TPLLCO_PreviewDistX_met/Functionality'/ip_lookup_fxpt_sfun_7 */
                {
                    FDPS_RESULT dps_result_ln;
                    /* Calculate value */
                    /* Find indices on X Axis: X_TPLLCO_VehVelX_mps */
                    FDPS_PTR_F32(GETA_X_TPLLCO_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
                    /* Direct accesing curve (used as module input) */
                    rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_TPLLCO_PreviewDistX_met(), &dps_result_ln);
                }
                rtb_Switch_oi = rtb_ip_lookup_fxpt_sfun_7_c;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Switch2/Functionality'/Switch' */
            rtb_Switch_oi = f32_min_f32_f32(rtb_Switch_oi, rtb_S_CSCLTA_TgtTrajLength_met);
        } else {
            rtb_Switch_oi = 0.0F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Switch1/Functionality'/Switch' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Product1/Functionality'/Mul' incorporates:
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Trigonom1/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_e[0] = rtb_Switch_oi * f32_cos_f32(rtb_Switch_gv);
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Product2/Functionality'/Mul' incorporates:
                 *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Calc_Ctrl_Point/Trigonom/Functionality'/Trigonometric Function'
                 */
        rtb_VectorConcatenate_e[1] = f32_sin_f32(rtb_Switch_gv) * rtb_Switch_oi;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Calc_Ctrl_Point' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Subtract4/Functionality'/Sum' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_e[i] += rtb_VectorConcatenate_bh[i];
        }
        /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Subtract4/Functionality'/Sum' */
        /* Outputs for Iterator SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_Veh_Projection' incorporates:
                 *  ForIterator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/For Iterator'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_Veh_Projection':
                 *  X.2.1.1.1.2.2.5
                 */
        /* InitializeConditions for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Unit Delay' */
        rtb_Switch_oi = 0.0F;
        for (s3224_iter = 1; s3224_iter <= ((sint32)GET_P_TPLLCO_NumIter_nu());
                s3224_iter++) {
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Subtract/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Constant3'/Constant'
                         *  MultiPortSwitch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Index Vector3'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Unit Delay'
                         */
            rtb_Switch_oi = rtb_VectorConcatenate_e[0] - rtb_Switch_oi;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Cridr_Trajectory_Equation'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Cridr_Trajectory_Equation':
                         *  X.2.1.1.1.2.2.5.1
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.1.2.2.5.1.2
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay'
                         */
            BI_tpllco_Div_l = (DW_tpllco_Unit_Delay_3_DSTATE + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_l = f32_floor_f32(BI_tpllco_Div_l);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay'
                         */
            rtb_TrigonometricFunction_eq = (DW_tpllco_Unit_Delay_3_DSTATE + 1.57079506F) - (rtb_MathFunction_l * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_TrigonometricFunction_eq >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_TrigonometricFunction_eq -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_TrigonometricFunction_eq >= -0.0174532775F) {
                    rtb_Sum_kq = -(0.0174532775F + rtb_TrigonometricFunction_eq);
                } else {
                    rtb_Sum_kq = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_Sum_kq = 0.0174532775F - rtb_TrigonometricFunction_eq;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function' incorporates:
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay'
                         */
            rtb_TrigonometricFunction_eq = f32_tan_f32(DW_tpllco_Unit_Delay_3_DSTATE + rtb_Sum_kq);
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Add3/Functionality'/Sum' incorporates:
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay'
                         */
            rtb_Sum_kq = rtb_Switch_oi - DW_tpllco_Unit_Delay_1_DSTATE;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product5/Functionality'/Mul' */
            rtb_Sum_gx = rtb_Sum_kq * rtb_Sum_kq;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Add1/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product6/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum1/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay'
                         */
            rtb_Mul_eq4[1] = (((((rtb_Sum_gx * rtb_Sum_kq) * DW_tpllco_Unit_Delay_5_DSTATE) * 0.166666672F) + ((DW_tpllco_Unit_Delay_4_DSTATE * rtb_Sum_gx) * 0.5F)) + (rtb_TrigonometricFunction_eq * rtb_Sum_kq)) + DW_tpllco_Unit_Delay_2_DSTATE;
            /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Min/Functionality'/Min' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain3_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant4'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant5'/Constant'
                         *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Max/Functionality'/Max'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Product4/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Sum3/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay'
                         */
            rtb_Sum_gx = f32_min_f32_f32(f32_max_f32_f32(((DW_tpllco_Unit_Delay_5_DSTATE * rtb_Sum_gx) * 0.5F) + ((DW_tpllco_Unit_Delay_4_DSTATE * rtb_Sum_kq) + rtb_TrigonometricFunction_eq), -1.0F), 1.0F);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum3/Functionality'/Sum' incorporates:
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Abs/Functionality'/Abs'
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Abs1/Functionality'/Abs'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant2'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Constant3'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Mul4/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/ApproxAtan/Sum2/Functionality'/Sum'
                         */
            BI_tpllco_Sum_o = (0.785398185F * rtb_Sum_gx) - (((f32_abs_f32(rtb_Sum_gx) - 1.0F) * rtb_Sum_gx) * ((f32_abs_f32(rtb_Sum_gx) * 0.0663F) + 0.2447F));
            /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/Gain2'/Data Type Conversion' */
            rtb_Mul_eq4[0] = rtb_Switch_oi;
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Cridr_Trajectory_Equation' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Subtract1/Functionality'/Sum' */
            for (i = 0; i < 2; i++) {
                BI_tpllco_Sum_g[i] = rtb_VectorConcatenate_e[i] - rtb_Mul_eq4[i];
            }
            /* End of Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Subtract1/Functionality'/Sum' */
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Divide/Functionality/DivDefault'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Divide/In3'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Divide/Functionality/DivDefault'/Div'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Neg/Functionality'/Unary Minus'
                         */
            if (BI_tpllco_Sum_g[1] != 0.0F) {
                rtb_Switch_oi = (-BI_tpllco_Sum_g[0]) / BI_tpllco_Sum_g[1];
            } else {
                rtb_Switch_oi = 0.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Divide/Functionality/DivDefault'/Switch' */
            /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Max/Functionality'/Max' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Constant4'/Constant'
                         */
            rtb_Switch_oi = f32_max_f32_f32(rtb_Switch_oi, -1.0F);
            /* MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Min/Functionality'/Min' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Constant5'/Constant'
                         */
            rtb_Switch_oi = f32_min_f32_f32(rtb_Switch_oi, 1.0F);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Subtract2/Functionality'/Sum' incorporates:
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Abs/Functionality'/Abs'
                         *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Abs1/Functionality'/Abs'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Constant'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Constant2'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Constant3'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Mul4/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/ApproxAtan/Sum3/Functionality'/Sum'
                         */
            rtb_TrigonometricFunction_eq = BI_tpllco_Sum_o - ((0.785398185F * rtb_Switch_oi) - (((f32_abs_f32(rtb_Switch_oi) - 1.0F) * rtb_Switch_oi) * ((f32_abs_f32 (rtb_Switch_oi) * 0.0663F) + 0.2447F)));
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Rotate_Anticlockwise'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Rotate_Anticlockwise':
                         *  X.2.1.1.1.2.2.5.2
                         */
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Rotate_Anticlockwise/Trigonom1/Functionality'/Trigonometric Function' */
            rtb_Switch_oi = f32_cos_f32(rtb_TrigonometricFunction_eq);
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Rotate_Anticlockwise/Trigonom/Functionality'/Trigonometric Function' */
            rtb_TrigonometricFunction_eq = f32_sin_f32(rtb_TrigonometricFunction_eq);
            /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Unit Delay' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Rotate_Anticlockwise/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Rotate_Anticlockwise/Product2/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Rotate_Anticlockwise/Sum of Elements/Functionality'/Sum'
                         */
            rtb_Switch_oi = (BI_tpllco_Sum_g[0] * rtb_Switch_oi) + (BI_tpllco_Sum_g[1] * (-rtb_TrigonometricFunction_eq));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection'/Rotate_Anticlockwise' */
        }
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_Veh_Projection' */
        /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Subtract1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Application Parameter'/Constant'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Projection/Cridr_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 */
        rtb_TrigonometricFunction_eq = rtb_Switch_gv - BI_tpllco_Sum_o;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch1/Functionality'/Switch' */
        if (((sint32)rtb_GT_kn) != 0) {
            rtb_Switch_oi = rtb_Sum_oy;
        } else {
            rtb_Switch_oi = rtb_TrigonometricFunction_eq;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch1/Functionality'/Switch' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/norm_1'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/norm_1':
                 *  X.2.1.1.1.2.2.6
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/Mul/Functionality'/Mul' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_e[i] = BI_tpllco_Sum_g[i] * BI_tpllco_Sum_g[i];
        }
        /* End of Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/Mul/Functionality'/Mul' */
        /* Signum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/Sign/Functionality'/Sign' */
        if (BI_tpllco_Sum_g[1] < 0.0F) {
            rtb_Sum_gx = -1.0F;
        } else if (BI_tpllco_Sum_g[1] > 0.0F) {
            rtb_Sum_gx = 1.0F;
        } else if (BI_tpllco_Sum_g[1] == 0.0F) {
            rtb_Sum_gx = 0.0F;
        } else {
            rtb_Sum_gx = BI_tpllco_Sum_g[1];
        }
        /* End of Signum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/Sign/Functionality'/Sign' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/Mul1/Functionality'/Mul' incorporates:
                 *  Sqrt: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_1/Sum of Elements/Functionality'/Sum'
                 */
        rtb_Sum_kq = f32_sqrt_f32(rtb_VectorConcatenate_e[0] + rtb_VectorConcatenate_e[1]) * rtb_Sum_gx;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/norm_1' */
        /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/norm_0'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/norm_0':
                 *  X.2.1.1.1.2.2.4
                 */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/Mul/Functionality'/Mul' */
        for (i = 0; i < 2; i++) {
            rtb_VectorConcatenate_e[i] = BI_tpllco_copy1_l[i] * BI_tpllco_copy1_l[i];
        }
        /* End of Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/Mul/Functionality'/Mul' */
        /* Signum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/Sign/Functionality'/Sign' */
        if (BI_tpllco_copy1_l[1] < 0.0F) {
            rtb_Sum_gx = -1.0F;
        } else if (BI_tpllco_copy1_l[1] > 0.0F) {
            rtb_Sum_gx = 1.0F;
        } else if (BI_tpllco_copy1_l[1] == 0.0F) {
            rtb_Sum_gx = 0.0F;
        } else {
            rtb_Sum_gx = BI_tpllco_copy1_l[1];
        }
        /* End of Signum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/Sign/Functionality'/Sign' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/Mul1/Functionality'/Mul' incorporates:
                 *  Sqrt: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/MathFunction/Functionality'/MathFunction'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/norm_0/Sum of Elements/Functionality'/Sum'
                 */
        rtb_Mul_pv = f32_sqrt_f32(rtb_VectorConcatenate_e[0] + rtb_VectorConcatenate_e[1]) * rtb_Sum_gx;
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/norm_0' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Logical NOT/Functionality'/NOT'
                 */
        if (!(((sint32)rtb_GT_kn) != 0)) {
            rtb_Sum_fc = rtb_Sum_kq;
        } else {
            rtb_Sum_fc = rtb_Mul_pv;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch/Functionality'/Switch' */
        /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_ReplanDelta' incorporates:
                 *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/Enable'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_ReplanDelta':
                 *  X.2.1.1.1.2.2.1
                 */
        if ((((((sint32)DW_tpllco_Unit_Delay2_DSTATE_j) != 0) && (((sint32)rtb_GT_kn) != 0)) && (((sint32)GET_P_TPLLCO_ReplanDevEnable_nu()) != 0)) > 0) {
            if (!((sint32)DW_tpllco_Calc_ReplanDelta_MODE)) {
                DW_tpllco_Calc_ReplanDelta_MODE = (uint8)1U;
            }
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Application Parameter5'/Constant'
                         *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Switch1/Functionality'/Switch'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit Delay3'
                         *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay1'
                         */
            if (((sint32)GET_P_TPLLCO_UseOdoReplan_nu()) == 0) {
                rtb_TrigonometricFunction_eq = DW_tpllco_UnitDelay3_DSTATE;
                rtb_Sum_kq = DW_tpllco_Unit_Delay1_DSTATE_g;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Switch/Functionality'/Switch' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Subtract2/Functionality'/Sum' */
            BI_tpllco_Sum_n = rtb_TrigonometricFunction_eq - rtb_Switch_oi;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Subtract1/Functionality'/Sum' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Product2/Functionality'/Mul'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta/Trigonom/Functionality'/Trigonometric Function'
                         */
            BI_tpllco_Sum_f = (f32_cos_f32(BI_tpllco_Sum_n) * rtb_Sum_kq) - rtb_Sum_fc;
        } else {
            if (DW_tpllco_Calc_ReplanDelta_MODE) {
                /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevHeading_rad'
                                 *
                                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevHeading_rad':
                                 *
                                 *  FAS35up.Name=%TPLLCO_ReplanDevHeading_rad
                                 */
                BI_tpllco_Sum_n = 0.0F;
                /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevDistY_met'
                                 *
                                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevDistY_met':
                                 *
                                 *  FAS35up.Name=%TPLLCO_ReplanDevDistY_met
                                 */
                BI_tpllco_Sum_f = 0.0F;
                DW_tpllco_Calc_ReplanDelta_MODE = (uint8)0U;
            }
        }
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_ReplanDelta' */
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Constant2'/Constant'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/AND/Functionality'/AND'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Product/Functionality'/Mul'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Sum of Elements/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Sum of Elements1/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Subtract2/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay2'
                 */
        if (((sint32)rtb_GT_kn) != 0) {
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Rotate_Anticlockwise_1'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Rotate_Anticlockwise_1':
                         *  X.2.1.1.1.2.2.3.1
                         */
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Trigonom/Functionality'/Trigonometric Function' incorporates:
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Neg/Functionality'/Unary Minus'
                         */
            rtb_TrigonometricFunction_eq = f32_sin_f32(-BI_tpllco__TPLLCO_RightOri_rad);
            /* Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Trigonom1/Functionality'/Trigonometric Function' incorporates:
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Neg/Functionality'/Unary Minus'
                         */
            rtb_Sum_kq = f32_cos_f32(-BI_tpllco__TPLLCO_RightOri_rad);
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Product/Functionality'/Mul' incorporates:
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Neg/Functionality'/Unary Minus'
                         */
            rtb_Mul_eq4[1] = BI_tpllco_VectorConcatenate_d[1] * (-rtb_TrigonometricFunction_eq);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Sum of Elements1/Functionality'/Sum' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Rotate_Anticlockwise_1/Product1/Functionality'/Mul'
                         */
            rtb_TrigonometricFunction_eq = (rtb_TrigonometricFunction_eq * BI_tpllco_VectorConcatenate_d[0]) + (rtb_Sum_kq * BI_tpllco_VectorConcatenate_d[1]);
            rtb_VectorConcatenate_bh[0] = 0.0F - ((BI_tpllco_VectorConcatenate_d[0] * rtb_Sum_kq) + rtb_Mul_eq4[1]);
            rtb_VectorConcatenate_bh[1] = rtb_Mul_pv - rtb_TrigonometricFunction_eq;
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Rotate_Anticlockwise_1' */
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position/Switch/Functionality'/Switch' */
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality'/Comparison'
                 */
        /* Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality'/Logical Operator2'
                 *  UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay4'
                 */
        BI_tpllco_LogicalOperator = (uint8)((!(((sint32)DW_tpllco_Unit_Delay4_DSTATE) != 0)) && (((sint32)rtb_DataTypeConversion_pk) != 0));
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING'/fcg' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant1'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant3'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  MinMax: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Max/Functionality'/Max'
                 */
        rtb_Div_h = GET_S_LCFRCV_SysCycleTimeVeh_sec() / f32_max_f32_f32 (GET_P_TPLLCO_VehCrvPT1TimeConst_sec(), 0.025F);
        /* UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay3' */
        rtb_Unit_Delay3 = DW_tpllco_Unit_Delay3_DSTATE;
        /* S-Function (sfun_mmv): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/LOWPASST_RE/Functionality'/S-Function' */
        if (BI_tpllco_LogicalOperator != 0U) {
            rtb_SFunction = GET_S_LCFRCV_VehCrv_1pm();
        } else {
            rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay3, GET_S_LCFRCV_VehCrv_1pm(), rtb_Div_h);
        }
        /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Y_TPLLCO_VehCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TPLLCO_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TPLLCO_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_g1 = F32_PTR_IP1D(GETA_Y_TPLLCO_VehCrvFactor_nu(), &dps_result_ln);
        }
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant2'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/LOWPASST_RE'/E'
                 *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Y_TPLLCO_VehCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (((sint32)GET_P_TPLLCO_VehCrvPT1Enable_nu()) != 0) {
            rtb_Sum_gx = rtb_SFunction;
        } else {
            rtb_Sum_gx = GET_S_LCFRCV_VehCrv_1pm();
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch2/Functionality'/Switch' */
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Mul/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Y_TPLLCO_VehCrvFactor_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Sum_kq = rtb_Sum_gx * rtb_ip_lookup_fxpt_sfun_7_g1;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Mul3/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant4'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Mul2/Functionality'/Mul'
                 */
        rtb_TrigonometricFunction_eq = ((BI_tpllco_VectorConcatenate_i[0] * BI_tpllco_VectorConcatenate_i[0]) * 0.5F) * rtb_Sum_kq;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Mul4/Functionality'/Mul' incorporates:
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Neg/Functionality'/Unary Minus'
                 */
        rtb_Sum_kq *= -BI_tpllco_VectorConcatenate_i[0];
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Constant5'/Constant'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/AND1/Functionality'/AND'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch4/Functionality'/Switch'
                 */
        if ((((sint32)rtb_DataTypeConversion_pk) != 0) && (((sint32) GET_P_TPLLCO_UseEgoPredict_nu()) != 0)) {
            BI_tpllco_Switch = rtb_TrigonometricFunction_eq + rtb_Sum_fc;
            BI_tpllco_Switch_f = rtb_Sum_kq + rtb_Switch_oi;
        } else {
            BI_tpllco_Switch = rtb_Sum_fc;
            BI_tpllco_Switch_f = rtb_Switch_oi;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Switch3/Functionality'/Switch' */
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/branch'/copy1' */
        SET_D_TPLLCO_EgoHeadingPre_rad(rtb_Sum_kq);
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/branch1'/copy1' */
        SET_D_TPLLCO_EgoDistYPre_met(rtb_TrigonometricFunction_eq);
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay2' */
        DW_tpllco_Unit_Delay2_DSTATE_j = 1U;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading/Switch/Functionality'/Switch' */
        if (((sint32)rtb_GT_kn) != 0) {
            /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading'/Unit_Delay' */
            DW_tpllco_Unit_Delay_DSTATE_f = rtb_Sum_oy;
        } else {
            /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading'/Unit_Delay' */
            DW_tpllco_Unit_Delay_DSTATE_f = rtb_Switch_gv;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Veh_Heading/Switch/Functionality'/Switch' */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Unit_Delay1' */
        for (i = 0; i < 2; i++) {
            DW_tpllco_Unit_Delay1_DSTATE[i] = rtb_VectorConcatenate_bh[i];
        }
        /* End of Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_Vehicle_Position'/Unit_Delay1' */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
        DW_tpllco_Unit_Delay_1_DSTATE = BI_tpllco_VectorConcatenate_o[0];
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
        DW_tpllco_Unit_Delay_2_DSTATE = BI_tpllco_VectorConcatenate_o[1];
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
        DW_tpllco_Unit_Delay_3_DSTATE = BI_tpllco_Sum_d;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
        DW_tpllco_Unit_Delay_4_DSTATE = BI_tpllco_Switch_e;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay' */
        DW_tpllco_Unit_Delay_5_DSTATE = BI_tpllco_Switch_m;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit Delay3' */
        DW_tpllco_UnitDelay3_DSTATE = rtb_Sum_oy;
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay1' */
        DW_tpllco_Unit_Delay1_DSTATE_g = rtb_Mul_pv;
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality'/SignalConversion'
                 */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay4' incorporates:
                 *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
                 */
        DW_tpllco_Unit_Delay4_DSTATE = rtb_DataTypeConversion_pk;
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/EDGERISING'/fcg' */
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Unit_Delay3' */
        DW_tpllco_Unit_Delay3_DSTATE = rtb_SFunction;
    } else {
        if (DW_tpllco_Set_Dev_ReplanDelta_MODE) {
            /* Disable for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_ReplanDelta'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_ReplanDelta':
                         *  X.2.1.1.1.2.2.1
                         */
            if (DW_tpllco_Calc_ReplanDelta_MODE) {
                /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevHeading_rad'
                                 *
                                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevHeading_rad':
                                 *
                                 *  FAS35up.Name=%TPLLCO_ReplanDevHeading_rad
                                 */
                BI_tpllco_Sum_n = 0.0F;
                /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevDistY_met'
                                 *
                                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta/Calc_ReplanDelta'/TPLLCO_ReplanDevDistY_met':
                                 *
                                 *  FAS35up.Name=%TPLLCO_ReplanDevDistY_met
                                 */
                BI_tpllco_Sum_f = 0.0F;
                DW_tpllco_Calc_ReplanDelta_MODE = (uint8)0U;
            }
            /* End of Disable for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/Calc_ReplanDelta' */
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_DevDistY_met'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_DevDistY_met':
                         *
                         *  FAS35up.Name=%TPLLCO_DevDistY_met
                         */
            BI_tpllco_Switch = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_DevHeading_rad'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_DevHeading_rad':
                         *
                         *  FAS35up.Name=%TPLLCO_DevHeading_rad
                         */
            BI_tpllco_Switch_f = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_ReplanDevDistY_met'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_ReplanDevDistY_met':
                         *
                         *  FAS35up.Name=%TPLLCO_ReplanDevDistY_met
                         */
            BI_tpllco_Sum_f = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_ReplanDevHeading_rad'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/TPLLCO_ReplanDevHeading_rad':
                         *
                         *  FAS35up.Name=%TPLLCO_ReplanDevHeading_rad
                         */
            BI_tpllco_Sum_n = 0.0F;
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/D_TPLLCO_EgoHeadingPre_rad'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/D_TPLLCO_EgoHeadingPre_rad':
                         *
                         *  FAS35up.Name=%TPLLCO_DevHeading_rad
                         */
            SET_D_TPLLCO_EgoHeadingPre_rad(0.0F);
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/D_TPLLCO_EgoDistYPre_met'
                                                        *
                                                        * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Set_Dev_ReplanDelta'/D_TPLLCO_EgoDistYPre_met':
                                                        *
                                                        *  FAS35up.Name=%TPLLCO_DevHeading_rad
                                                        */
            SET_D_TPLLCO_EgoDistYPre_met(0.0F);
            DW_tpllco_Set_Dev_ReplanDelta_MODE = (uint8)0U;
        }
    }
    /* End of Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs/Trigger/OR/Functionality'/OR' */
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Set_Outputs'/Set_Dev_ReplanDelta' */
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/branch'/copy1' */
    SET_S_TPLLCO_MeasDeltaT_sec(BI_tpllco_Mul);
    /* Outputs for Enabled SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO'/Plausibility_Check' incorporates:
                                            *  EnablePort: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/Enable'
                                            *
                                            * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO'/Plausibility_Check':
                                            *  X.2.1.1.3
                                            */
    /* Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/AND/Functionality'/AND' incorporates:
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant10'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant5'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant7'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant8'/Constant'
         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant9'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/NOT/Functionality'/NOT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolCrv_rad/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolVelX_rad/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
         */
    if (((!(((sint32)rtb_GT_c) != 0)) && (((sint32)rtb_GT_kn) != 0)) > 0) {
        if (!((sint32)DW_tpllco_Plausibility_Check_MODE)) {
            DW_tpllco_Plausibility_Check_MODE = (uint8)1U;
        }
        /* Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Abs3/Functionality'/Abs' */
        rtb_Abs = f32_abs_f32(rtb_S_CSCLTA_TgtTrajCrv_1pm);
        /* Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Abs4/Functionality'/Abs' */
        rtb_Mul_pv = f32_abs_f32(rtb_S_CSCLTA_TgtTrajHeadAng_rad);
        /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/GT/Functionality'/GT' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Abs11/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant6'/Constant'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Sum6/Functionality'/Sum'
                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Neg/Functionality'/Unary Minus'
                 */
        rtb_DataTypeConversion_pk = (uint8)(f32_abs_f32(BI_tpllco_Switch - (-rtb_Max_af)) > GET_P_TPLLCO_DistYCheckTolerance_met());
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector Concatenate1In1' */
        rtb_VectorConcatenate1[0] = rtb_DataTypeConversion_pk;
        /* Outputs for Iterator SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY2' incorporates:
                 *  ForIterator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/For Iterator'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY2':
                 *  X.2.1.1.3.3
                 */
        for (s889_iter = 1; ((sint32)s889_iter) < 5; s889_iter = (sint8)(((sint32) s889_iter) + 1)) {
            rtb_ForIterator = s889_iter;
            /* DTC_F32 : sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/DTC_F32'/conversion_sfunction2 */
            rtb_conversion_sfunction2 = 4.0F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Div/Functionality/DivDefault'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Div/In3'/Constant'
                         *  DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/DTC_F1'/Data Type Conversion'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Div/Functionality/DivDefault'/Div'
                         */
            if (rtb_conversion_sfunction2 != 0.0F) {
                /* DTC_F32 : sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/DTC_F1'/conversion_sfunction2 */
                rtb_conversion_sfunction2_e = rtb_ForIterator;
                rtb_Sum_fc = ((float32)rtb_conversion_sfunction2_e) / rtb_conversion_sfunction2;
            } else {
                rtb_Sum_fc = 1.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Div/Functionality/DivDefault'/Switch' */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Mul/Functionality'/Mul' */
            rtb_Mul_l = rtb_S_CSCLTA_TgtTrajLength_met * rtb_Sum_fc;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Sum19/Functionality'/Sum' */
            rtb_Sum_fc = rtb_Mul_l - BI_tpllco_copy1[0];
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/Corridor_Trajectory_Equation'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/Corridor_Trajectory_Equation':
                         *  X.2.1.1.3.3.1
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.3.3.1.1
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div_b = (rtb_S_CSCLTA_TgtTrajHeadAng_rad + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_i = f32_floor_f32(BI_tpllco_Div_b);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_Switch_oi = (rtb_S_CSCLTA_TgtTrajHeadAng_rad + 1.57079506F) - (rtb_MathFunction_i * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_Switch_oi >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_Switch_oi -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_Switch_oi >= -0.0174532775F) {
                    rtb_Switch_oi = -(0.0174532775F + rtb_Switch_oi);
                } else {
                    rtb_Switch_oi = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_Switch_oi = 0.0174532775F - rtb_Switch_oi;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' */
            rtb_Switch_gv = rtb_Mul_l - rtb_S_CSCLTA_TgtTrajPosX0_met;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
            rtb_Sum_oy = rtb_Switch_gv * rtb_Switch_gv;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.3.3.1.1
                         */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Sum20/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Add1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                         */
            rtb_Switch_oi = ((((f32_tan_f32(rtb_S_CSCLTA_TgtTrajHeadAng_rad + rtb_Switch_oi) * rtb_Switch_gv) + ((rtb_S_CSCLTA_TgtTrajCrv_1pm * rtb_Sum_oy) * 0.5F)) + (((rtb_Sum_oy * rtb_Switch_gv) * rtb_S_CSCLTA_TgtTrajCrvChng_1pm2) * 0.166666672F)) + rtb_S_CSCLTA_TgtTrajPosY0_met) - BI_tpllco_copy1[1];
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation'/TanNinety_V4' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/Corridor_Trajectory_Equation' */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/Corridor_Trajectory_Equation1'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/Corridor_Trajectory_Equation1':
                         *  X.2.1.1.3.3.2
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1'/TanNinety_V4':
                         *  X.2.1.1.3.3.2.1
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div = (BI_tpllco_Sum_f5 + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction = f32_floor_f32(BI_tpllco_Div);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_Switch_gv = (BI_tpllco_Sum_f5 + 1.57079506F) - (rtb_MathFunction * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_Switch_gv >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_Switch_gv -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_Switch_gv >= -0.0174532775F) {
                    rtb_Switch_gv = -(0.0174532775F + rtb_Switch_gv);
                } else {
                    rtb_Switch_gv = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_Switch_gv = 0.0174532775F - rtb_Switch_gv;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Add3/Functionality'/Sum' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Mul13/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Mul16/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Sum21/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Trigonom10/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Trigonom9/Functionality'/Trigonometric Function'
                         */
            rtb_Sum_oy = ((rtb_Sum_fc * f32_cos_f32(BI_tpllco__TPLLCO_RightOri_rad)) + (rtb_Switch_oi * f32_sin_f32(BI_tpllco__TPLLCO_RightOri_rad))) - BI_tpllco_VectorConcatenate_i[0];
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Mul/Functionality'/Mul' */
            rtb_TrigonometricFunction_eq = rtb_Sum_oy * rtb_Sum_oy;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1'/TanNinety_V4':
                         *  X.2.1.1.3.3.2.1
                         */
            /* Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Abs/Functionality'/Abs' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Product1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Mul14/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Mul15/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Add1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Add4/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Sum17/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/Trigonom/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Trigonom11/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Trigonom12/Functionality'/Trigonometric Function'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Neg3/Functionality'/Unary Minus'
                         */
            rtb_Sum_fc = f32_abs_f32(((rtb_Sum_fc * f32_sin_f32 (-BI_tpllco__TPLLCO_RightOri_rad)) + (rtb_Switch_oi * f32_cos_f32 (BI_tpllco__TPLLCO_RightOri_rad))) - ((((f32_tan_f32(BI_tpllco_Sum_f5 + rtb_Switch_gv) * rtb_Sum_oy) + ((BI_tpllco_Switch_h * rtb_TrigonometricFunction_eq) * 0.5F)) + (((rtb_TrigonometricFunction_eq * rtb_Sum_oy) * BI_tpllco_Switch_o) * 0.166666672F)) + BI_tpllco_VectorConcatenate_i[1]));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1'/TanNinety_V4' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2'/Corridor_Trajectory_Equation1' */
            /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLLCO_TestPointPosX_met */
                FDPS_PTR_F32(GETA_X_TPLLCO_TestPointPosX_met(), rtb_Mul_l, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_TPLLCO_AllowedDevPosY_met(), &dps_result_ln);
            }
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array1'/Functionality' */
            /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array1/Functionality/assignment'/Assignment' incorporates:
                         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/GT/Functionality'/GT'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         */
            BI_tpllco_Assignment[((sint32)rtb_ForIterator) - 1] = (uint8)(rtb_Sum_fc > rtb_ip_lookup_fxpt_sfun_7_h);
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array1'/Functionality' */
            /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/OR/Functionality'/Data Type Conversion' incorporates:
                         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/OR/Functionality'/OR'
                         */
            BI_tpllco_DataTypeConversion = (uint8)((((((sint32)BI_tpllco_Assignment[0]) != 0) || (((sint32)BI_tpllco_Assignment[1]) != 0)) || (((sint32)BI_tpllco_Assignment[2]) != 0)) || (((sint32)BI_tpllco_Assignment[3]) != 0));
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array'/Functionality' */
            /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array/Functionality/assignment'/Assignment' */
            SET_D_TPLLCO_TgtCridrTransDev_met(((sint32)rtb_ForIterator) - 1, (rtb_Sum_fc));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/write_array'/Functionality' */
        }
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY2' */
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector Concatenate1In3' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant9'/Constant'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY2/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 */
        rtb_VectorConcatenate1[2] = BI_tpllco_DataTypeConversion;
        /* Outputs for Iterator SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY' incorporates:
                 *  ForIterator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/For Iterator'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY':
                 *  X.2.1.1.3.1
                 */
        for (s889_iter = 1; ((sint32)s889_iter) < 5; s889_iter = (sint8)(((sint32) s889_iter) + 1)) {
            rtb_ForIterator_e = s889_iter;
            /* DTC_F32 : sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/DTC_F1'/conversion_sfunction2 */
            rtb_conversion_sfunction2_j = 4.0F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Div/Functionality/DivDefault'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Div/In3'/Constant'
                         *  DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/DTC_F32'/Data Type Conversion'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Div/Functionality/DivDefault'/Div'
                         */
            if (rtb_conversion_sfunction2_j != 0.0F) {
                /* DTC_F32 : sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/DTC_F32'/conversion_sfunction2 */
                rtb_conversion_sfunction2_en = rtb_ForIterator_e;
                rtb_Sum_fc = ((float32)rtb_conversion_sfunction2_en) / rtb_conversion_sfunction2_j;
            } else {
                rtb_Sum_fc = 1.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Div/Functionality/DivDefault'/Switch' */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Mul/Functionality'/Mul' */
            rtb_Mul_bzx = rtb_S_CSCLTA_LeCridrBndLength_met * rtb_Sum_fc;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Sum19/Functionality'/Sum' */
            rtb_Sum_fc = rtb_Mul_bzx - BI_tpllco_copy1[0];
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/Corridor_Trajectory_Equation'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/Corridor_Trajectory_Equation':
                         *  X.2.1.1.3.1.1
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.3.1.1.1
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div_d = (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_fr = f32_floor_f32(BI_tpllco_Div_d);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_S_CSCLTA_TgtTrajLength_met = (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + 1.57079506F) - (rtb_MathFunction_fr * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_S_CSCLTA_TgtTrajLength_met >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_S_CSCLTA_TgtTrajLength_met -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_S_CSCLTA_TgtTrajLength_met >= -0.0174532775F) {
                    rtb_S_CSCLTA_TgtTrajLength_met = -(0.0174532775F + rtb_S_CSCLTA_TgtTrajLength_met);
                } else {
                    rtb_S_CSCLTA_TgtTrajLength_met = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_S_CSCLTA_TgtTrajLength_met = 0.0174532775F - rtb_S_CSCLTA_TgtTrajLength_met;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' */
            rtb_S_CSCLTA_TgtTrajPosX0_met = rtb_Mul_bzx - rtb_Switch_ha;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
            rtb_S_CSCLTA_TgtTrajPosY0_met = rtb_S_CSCLTA_TgtTrajPosX0_met * rtb_S_CSCLTA_TgtTrajPosX0_met;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.3.1.1.1
                         */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Sum20/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Add1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                         */
            rtb_S_CSCLTA_TgtTrajLength_met = ((((f32_tan_f32 (rtb_S_CSCLTA_LeCridrBndHeadAng_rad + rtb_S_CSCLTA_TgtTrajLength_met) * rtb_S_CSCLTA_TgtTrajPosX0_met) + ((rtb_S_CSCLTA_LeCridrBndCrv_1pm * rtb_S_CSCLTA_TgtTrajPosY0_met) * 0.5F)) + (((rtb_S_CSCLTA_TgtTrajPosY0_met * rtb_S_CSCLTA_TgtTrajPosX0_met) * rtb_S_CSCLTA_LeCridrBndCrvChng_1pm2) * 0.166666672F)) + rtb_S_CSCLTA_LeCridrBndPosY0_met) - BI_tpllco_copy1[1];
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation'/TanNinety_V4' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/Corridor_Trajectory_Equation' */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/Corridor_Trajectory_Equation1'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/Corridor_Trajectory_Equation1':
                         *  X.2.1.1.3.1.2
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1'/TanNinety_V4':
                         *  X.2.1.1.3.1.2.1
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div_f = (BI_tpllco_Sum_je + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_o = f32_floor_f32(BI_tpllco_Div_f);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_S_CSCLTA_TgtTrajPosX0_met = (BI_tpllco_Sum_je + 1.57079506F) - (rtb_MathFunction_o * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_S_CSCLTA_TgtTrajPosX0_met >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_S_CSCLTA_TgtTrajPosX0_met -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_S_CSCLTA_TgtTrajPosX0_met >= -0.0174532775F) {
                    rtb_S_CSCLTA_TgtTrajPosX0_met = -(0.0174532775F + rtb_S_CSCLTA_TgtTrajPosX0_met);
                } else {
                    rtb_S_CSCLTA_TgtTrajPosX0_met = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_S_CSCLTA_TgtTrajPosX0_met = 0.0174532775F - rtb_S_CSCLTA_TgtTrajPosX0_met;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Add3/Functionality'/Sum' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Mul13/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Mul16/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Sum21/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Trigonom10/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Trigonom9/Functionality'/Trigonometric Function'
                         */
            rtb_S_CSCLTA_TgtTrajPosY0_met = ((rtb_Sum_fc * f32_cos_f32 (BI_tpllco__TPLLCO_RightOri_rad)) + (rtb_S_CSCLTA_TgtTrajLength_met * f32_sin_f32(BI_tpllco__TPLLCO_RightOri_rad))) - BI_tpllco_VectorConcatenate_a[0];
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Mul/Functionality'/Mul' */
            rtb_S_CSCLTA_TgtTrajHeadAng_rad = rtb_S_CSCLTA_TgtTrajPosY0_met * rtb_S_CSCLTA_TgtTrajPosY0_met;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1'/TanNinety_V4':
                         *  X.2.1.1.3.1.2.1
                         */
            /* Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Abs/Functionality'/Abs' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Product1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Mul14/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Mul15/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Add1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Add4/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Sum17/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/Trigonom/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Trigonom11/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Trigonom12/Functionality'/Trigonometric Function'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Neg3/Functionality'/Unary Minus'
                         */
            rtb_Sum_fc = f32_abs_f32(((rtb_Sum_fc * f32_sin_f32 (-BI_tpllco__TPLLCO_RightOri_rad)) + (rtb_S_CSCLTA_TgtTrajLength_met * f32_cos_f32(BI_tpllco__TPLLCO_RightOri_rad))) - ((((f32_tan_f32(BI_tpllco_Sum_je + rtb_S_CSCLTA_TgtTrajPosX0_met) * rtb_S_CSCLTA_TgtTrajPosY0_met) + ((BI_tpllco_Sum_ji * rtb_S_CSCLTA_TgtTrajHeadAng_rad) * 0.5F)) + (((rtb_S_CSCLTA_TgtTrajHeadAng_rad * rtb_S_CSCLTA_TgtTrajPosY0_met) * BI_tpllco_Switch_j) * 0.166666672F)) + BI_tpllco_VectorConcatenate_a[1]));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1'/TanNinety_V4' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY'/Corridor_Trajectory_Equation1' */
            /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLLCO_TestPointPosX_met */
                FDPS_PTR_F32(GETA_X_TPLLCO_TestPointPosX_met(), rtb_Mul_bzx, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D (GETA_Y_TPLLCO_AllowedDevPosY_met(), &dps_result_ln);
            }
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array1'/Functionality' */
            /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array1/Functionality/assignment'/Assignment' incorporates:
                         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/GT/Functionality'/GT'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         */
            BI_tpllco_Assignment_a[((sint32)rtb_ForIterator_e) - 1] = (uint8)(rtb_Sum_fc > rtb_ip_lookup_fxpt_sfun_7_k);
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array1'/Functionality' */
            /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/OR/Functionality'/Data Type Conversion' incorporates:
                         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/OR/Functionality'/OR'
                         */
            BI_tpllco_DataTypeConversion_m = (uint8)((((((sint32)BI_tpllco_Assignment_a[0]) != 0) || (((sint32)BI_tpllco_Assignment_a[1]) != 0)) || (((sint32)BI_tpllco_Assignment_a[2]) != 0)) || (((sint32)BI_tpllco_Assignment_a[3]) != 0));
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array'/Functionality' */
            /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array/Functionality/assignment'/Assignment' */
            SET_D_TPLLCO_LeCridrTransDev_met(((sint32)rtb_ForIterator_e) - 1, (rtb_Sum_fc));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/write_array'/Functionality' */
        }
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY' */
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector Concatenate1In4' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant10'/Constant'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 */
        rtb_VectorConcatenate1[3] = BI_tpllco_DataTypeConversion_m;
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn1' */
        rtb_VectorConcatenate_d[0] = rtb_DataTypeConversion_pk;
        /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/GT1/Functionality'/GT' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Abs/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant'/Constant'
                 */
        rtb_DataTypeConversion_pk = (uint8)(f32_abs_f32(BI_tpllco_VectorConcatenate_o[1]) > 0.001F);
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn2' */
        rtb_VectorConcatenate_d[1] = rtb_DataTypeConversion_pk;
        /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/GT2/Functionality'/GT' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Abs1/Functionality'/Abs'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant1'/Constant'
                 */
        rtb_Switch_lp = (uint8)(f32_abs_f32(BI_tpllco_Sum_d) > 0.001F);
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_d[2] = rtb_Switch_lp;
        /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Mul8/Functionality'/Mul' */
        rtb_Sum_fc = BI_tpllco_Switch_of * BI_tpllco_Switch_of;
        /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Div1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant16'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant2'/Constant'
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Div1/In3'/Constant'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Div1/Functionality/DivDefault'/Div'
                 *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Mul7/Functionality'/Mul'
                 */
        if (rtb_Sum_fc != 0.0F) {
            rtb_Sum_fc = (GET_P_TPLLCO_CrvCheckTolerance_met() * 2.0F) / rtb_Sum_fc;
        } else {
            rtb_Sum_fc = 1.0E-5F;
        }
        /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Div1/Functionality/DivDefault'/Switch' */
        /* RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/GT3/Functionality'/GT' incorporates:
                 *  Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Abs2/Functionality'/Abs'
                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Sum/Functionality'/Sum'
                 */
        rtb_sfun_setbit = (uint8)(f32_abs_f32(BI_tpllco_Switch_e - rtb_Sum_mo) > rtb_Sum_fc);
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn4' */
        rtb_VectorConcatenate_d[3] = rtb_sfun_setbit;
        /* Outputs for Iterator SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY1' incorporates:
                 *  ForIterator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/For Iterator'
                 *
                 * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY1':
                 *  X.2.1.1.3.2
                 */
        for (s889_iter = 1; ((sint32)s889_iter) < 5; s889_iter = (sint8)(((sint32) s889_iter) + 1)) {
            rtb_ForIterator_k = s889_iter;
            /* DTC_F32 : sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/DTC_F32'/conversion_sfunction2 */
            rtb_conversion_sfunction2_i = 4.0F;
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Div/Functionality/DivDefault'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Div/In3'/Constant'
                         *  DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/DTC_F1'/Data Type Conversion'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Div/Functionality/DivDefault'/Div'
                         */
            if (rtb_conversion_sfunction2_i != 0.0F) {
                /* DTC_F32 : sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/DTC_F1'/conversion_sfunction2 */
                rtb_conversion_sfunction2_m = rtb_ForIterator_k;
                rtb_Sum_fc = ((float32)rtb_conversion_sfunction2_m) / rtb_conversion_sfunction2_i;
            } else {
                rtb_Sum_fc = 1.0F;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Div/Functionality/DivDefault'/Switch' */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Mul/Functionality'/Mul' */
            rtb_Mul_h = rtb_Mul_f2 * rtb_Sum_fc;
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Sum19/Functionality'/Sum' */
            rtb_Sum_fc = rtb_Mul_h - BI_tpllco_copy1[0];
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/Corridor_Trajectory_Equation'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/Corridor_Trajectory_Equation':
                         *  X.2.1.1.3.2.1
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.3.2.1.1
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div_e = (rtb_Sum_dg + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_f = f32_floor_f32(BI_tpllco_Div_e);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_S_CSCLTA_TgtTrajLength_met = (rtb_Sum_dg + 1.57079506F) - (rtb_MathFunction_f * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_S_CSCLTA_TgtTrajLength_met >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_S_CSCLTA_TgtTrajLength_met -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_S_CSCLTA_TgtTrajLength_met >= -0.0174532775F) {
                    rtb_S_CSCLTA_TgtTrajLength_met = -(0.0174532775F + rtb_S_CSCLTA_TgtTrajLength_met);
                } else {
                    rtb_S_CSCLTA_TgtTrajLength_met = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_S_CSCLTA_TgtTrajLength_met = 0.0174532775F - rtb_S_CSCLTA_TgtTrajLength_met;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Add3/Functionality'/Sum' */
            rtb_Switch_ha = rtb_Mul_h - rtb_Mul_a3;
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Mul/Functionality'/Mul' */
            rtb_S_CSCLTA_LeCridrBndPosY0_met = rtb_Switch_ha * rtb_Switch_ha;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation'/TanNinety_V4':
                         *  X.2.1.1.3.2.1.1
                         */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Sum20/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Product1/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Add1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Add4/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/Trigonom/Functionality'/Trigonometric Function'
                         */
            rtb_S_CSCLTA_TgtTrajLength_met = ((((f32_tan_f32(rtb_Sum_dg + rtb_S_CSCLTA_TgtTrajLength_met) * rtb_Switch_ha) + ((rtb_Sum_mo * rtb_S_CSCLTA_LeCridrBndPosY0_met) * 0.5F)) + (((rtb_S_CSCLTA_LeCridrBndPosY0_met * rtb_Switch_ha) * rtb_Mul_h4) * 0.166666672F)) + rtb_Max_af) - BI_tpllco_copy1[1];
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation'/TanNinety_V4' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/Corridor_Trajectory_Equation' */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/Corridor_Trajectory_Equation1'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/Corridor_Trajectory_Equation1':
                         *  X.2.1.1.3.2.2
                         */
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1'/TanNinety_V4':
                         *  X.2.1.1.3.2.2.1
                         */
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/DivByZeroProtection/Div/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                         */
            BI_tpllco_Div_c = (BI_tpllco_Sum_d + 1.57079506F) / 3.14159F;
            /* S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction' */
            rtb_MathFunction_k = f32_floor_f32(BI_tpllco_Div_c);
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant1'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant2'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/Mul/Functionality'/Mul'
                         *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Add/Functionality'/Sum'
                         */
            rtb_Switch_ha = (BI_tpllco_Sum_d + 1.57079506F) - (rtb_MathFunction_k * 3.14159F);
            /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant4'/Constant'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Add1/Functionality'/Sum'
                         */
            if (rtb_Switch_ha >= 0.0174532775F) {
                /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Add2/Functionality'/Sum' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant5'/Constant'
                                 */
                rtb_Switch_ha -= 3.14159F;
                /* Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant6'/Constant'
                                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Constant7'/Constant'
                                 *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Sum/Functionality'/Sum'
                                 *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Neg/Functionality'/Unary Minus'
                                 */
                if (rtb_Switch_ha >= -0.0174532775F) {
                    rtb_Switch_ha = -(0.0174532775F + rtb_Switch_ha);
                } else {
                    rtb_Switch_ha = 0.0F;
                }
                /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Switch4/Functionality'/Switch' */
            } else {
                rtb_Switch_ha = 0.0174532775F - rtb_Switch_ha;
            }
            /* End of Switch: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Switch1/Functionality'/Switch' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1'/TanNinety_V4' */
            /* Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Add3/Functionality'/Sum' incorporates:
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Mul13/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Mul16/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Sum21/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Trigonom10/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Trigonom9/Functionality'/Trigonometric Function'
                         */
            rtb_S_CSCLTA_LeCridrBndPosY0_met = ((rtb_Sum_fc * f32_cos_f32 (BI_tpllco__TPLLCO_RightOri_rad)) + (rtb_S_CSCLTA_TgtTrajLength_met * f32_sin_f32(BI_tpllco__TPLLCO_RightOri_rad))) - BI_tpllco_VectorConcatenate_o[0];
            /* Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Mul/Functionality'/Mul' */
            rtb_S_CSCLTA_LeCridrBndHeadAng_rad = rtb_S_CSCLTA_LeCridrBndPosY0_met * rtb_S_CSCLTA_LeCridrBndPosY0_met;
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1'/TanNinety_V4'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1'/TanNinety_V4':
                         *  X.2.1.1.3.2.2.1
                         */
            /* Abs: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Abs/Functionality'/Abs' incorporates:
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Gain1_const'/Constant'
                         *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Gain_const'/Constant'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Gain/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Gain1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Product/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Product1/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Mul14/Functionality'/Mul'
                         *  Product: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Mul15/Functionality'/Mul'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Add1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Add4/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Sum17/Functionality'/Sum'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/Trigonom/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Trigonom11/Functionality'/Trigonometric Function'
                         *  Trigonometry: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Trigonom12/Functionality'/Trigonometric Function'
                         *  UnaryMinus: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Neg3/Functionality'/Unary Minus'
                         */
            rtb_Sum_fc = f32_abs_f32(((rtb_Sum_fc * f32_sin_f32 (-BI_tpllco__TPLLCO_RightOri_rad)) + (rtb_S_CSCLTA_TgtTrajLength_met * f32_cos_f32(BI_tpllco__TPLLCO_RightOri_rad))) - ((((f32_tan_f32(BI_tpllco_Sum_d + rtb_Switch_ha) * rtb_S_CSCLTA_LeCridrBndPosY0_met) + ((BI_tpllco_Switch_e * rtb_S_CSCLTA_LeCridrBndHeadAng_rad) * 0.5F)) + (((rtb_S_CSCLTA_LeCridrBndHeadAng_rad * rtb_S_CSCLTA_LeCridrBndPosY0_met) * BI_tpllco_Switch_m) * 0.166666672F)) + BI_tpllco_VectorConcatenate_o[1]));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1'/TanNinety_V4' */
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1'/Corridor_Trajectory_Equation1' */
            /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLLCO_TestPointPosX_met */
                FDPS_PTR_F32(GETA_X_TPLLCO_TestPointPosX_met(), rtb_Mul_h, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_TPLLCO_AllowedDevPosY_met(), &dps_result_ln);
            }
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array1'/Functionality' */
            /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array1/Functionality/assignment'/Assignment' incorporates:
                         *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/GT/Functionality'/GT'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
                         */
            BI_tpllco_Assignment_b[((sint32)rtb_ForIterator_k) - 1] = (uint8)(rtb_Sum_fc > rtb_ip_lookup_fxpt_sfun_7_p);
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array1'/Functionality' */
            /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/OR/Functionality'/Data Type Conversion' incorporates:
                         *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/OR/Functionality'/OR'
                         */
            BI_tpllco_DataTypeConversion_g = (uint8)((((((sint32)BI_tpllco_Assignment_b[0]) != 0) || (((sint32)BI_tpllco_Assignment_b[1]) != 0)) || (((sint32)BI_tpllco_Assignment_b[2]) != 0)) || (((sint32)BI_tpllco_Assignment_b[3]) != 0));
            /* Outputs for Atomic SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array'/Functionality' */
            /* Assignment: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array/Functionality/assignment'/Assignment' */
            SET_D_TPLLCO_RiCridrTransDev_met(((sint32)rtb_ForIterator_k) - 1, (rtb_Sum_fc));
            /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/write_array'/Functionality' */
        }
        /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/DivationDistY1' */
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn5' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant5'/Constant'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Y_TPLLCO_AllowedDevPosY_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 *  S-Function (sf_fxpop_ecmath_f32): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/DivationDistY1/Corridor_Trajectory_Equation1/TanNinety_V4/Modulo/MathFunction/Functionality'/MathFunction'
                 */
        rtb_VectorConcatenate_d[4] = BI_tpllco_DataTypeConversion_g;
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn6' */
        rtb_VectorConcatenate_d[5] = BI_tpllco_DataTypeConversion;
        /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/ConcatBufferAtVector ConcatenateIn7' */
        rtb_VectorConcatenate_d[6] = BI_tpllco_DataTypeConversion_m;
        /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolVelX_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TPLLCO_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TPLLCO_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D (GETA_Y_TPLLCO_TgtCridrHeadTolVelX_rad(), &dps_result_ln);
        }
        /* S-Function Block sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolCrv_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TPLLCO_CorridorCurvature_1pm */
            FDPS_PTR_F32(GETA_X_TPLLCO_CorridorCurvature_1pm(), rtb_Abs, &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_TPLLCO_TgtCridrHeadTolCrv_rad(), &dps_result_ln);
        }
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/OR/Functionality'/Data Type Conversion' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/OR/Functionality'/OR'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolCrv_rad/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolVelX_rad/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_VectorConcatenate1[1] = (uint8)((((((sint32)rtb_DataTypeConversion_pk) != 0) || (((sint32)rtb_Switch_lp) != 0)) || (((sint32)rtb_sfun_setbit) != 0)) || (((sint32)BI_tpllco_DataTypeConversion_g) != 0));
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/OR1/Functionality'/Data Type Conversion' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/OR1/Functionality'/OR'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/GT4/Functionality'/GT'
                 *  RelationalOperator: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/LT/Functionality'/LT'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolCrv_rad/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Y_TPLLCO_TgtCridrHeadTolVelX_rad/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_VectorConcatenate1[4] = (uint8)((rtb_ip_lookup_fxpt_sfun_7_l < rtb_Mul_pv) || (rtb_Mul_pv > rtb_ip_lookup_fxpt_sfun_7));
        /* S-Function (sfun_setbit): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/set_bit/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint8 temp = ((uint8)0U);
            {
                uint8 set_mask = 0;
                uint8 reset_mask = 0;
                const uint8 selection_vec[7] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U };
                {
                    sint32 i1;
                    const uint8 *u1 = &rtb_VectorConcatenate_d[0];
                    for (i1=0; i1 < 7; i1++) {
                        if (!u1[i1]) {
                            /* reset */
                            reset_mask = reset_mask | u8_bit_u8( selection_vec [i1]);
                        } else {
                            /* set */
                            set_mask = set_mask | u8_bit_u8( selection_vec [i1]);
                        }
                    }
                }
                temp = (temp & ~reset_mask) | set_mask ;
            }
            rtb_sfun_setbit = temp;
        }
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/set_bit/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant7'/Constant'
                 */
        SET_D_TPLLCO_PlausiCheckStatus_nu(rtb_sfun_setbit);
        /* S-Function (sfun_setbit): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/set_bit1/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint8 temp = ((uint8)0U);
            {
                uint8 set_mask = 0;
                uint8 reset_mask = 0;
                const uint8 selection_vec[5] = { 0U, 1U, 2U, 3U, 4U };
                {
                    sint32 i1;
                    const uint8 *u1 = &rtb_VectorConcatenate1[0];
                    for (i1=0; i1 < 5; i1++) {
                        if (!u1[i1]) {
                            /* reset */
                            reset_mask = reset_mask | u8_bit_u8( selection_vec [i1]);
                        } else {
                            /* set */
                            set_mask = set_mask | u8_bit_u8( selection_vec [i1]);
                        }
                    }
                }
                temp = (temp & ~reset_mask) | set_mask ;
            }
            rtb_sfun_setbit = temp;
        }
        /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/set_bit1/Functionality'/DTC_out' incorporates:
                 *  Constant: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check/Constant8'/Constant'
                 */
        BI_tpllco_DTC_out = rtb_sfun_setbit;
    } else {
        if (DW_tpllco_Plausibility_Check_MODE) {
            /* Disable for Outport: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/D_TPLLCO_PlausiCheckStatus_nu'
                         *
                         * Block description for 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Plausibility_Check'/D_TPLLCO_PlausiCheckStatus_nu':
                         *
                         *  FAS35up.Name=%TPLLCO_ReplanDevHeading_nu
                         */
            SET_D_TPLLCO_PlausiCheckStatus_nu(0U);
            DW_tpllco_Plausibility_Check_MODE = (uint8)0U;
        }
    }
    /* End of Logic: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/AND/Functionality'/AND' */
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO'/Plausibility_Check' */
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch'/copy1' */
    SET_S_TPLLCO_TriggerReplan_nu(rtb_GT_kn);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch1'/copy1' */
    SET_S_TPLLCO_DevDistY_met(BI_tpllco_Switch);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch10'/copy1' */
    SET_S_TPLLCO_LeftCorridorLength_met(BI_tpllco_Sum_np);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch11'/copy1' */
    SET_S_TPLLCO_RightCorridorPosX0_met(BI_tpllco_VectorConcatenate_o[0]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch12'/copy1' */
    SET_S_TPLLCO_RightCorridorPosY0_met(BI_tpllco_VectorConcatenate_o[1]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch13'/copy1' */
    SET_S_TPLLCO_RightCridrHeading_rad(BI_tpllco_Sum_d);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch14'/copy1' */
    SET_S_TPLLCO_RightCorridorCrv_1pm(BI_tpllco_Switch_e);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch15'/copy1' */
    SET_S_TPLLCO_RiCridrChngOfCrv_1pm2(BI_tpllco_Switch_m);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch16'/copy1' */
    SET_S_TPLLCO_RightCorridorLength_met(BI_tpllco_Switch_mv);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch17'/copy1' */
    SET_S_TPLLCO_TargetCorridorPosX0_met(BI_tpllco_VectorConcatenate_i[0]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch18'/copy1' */
    SET_S_TPLLCO_TargetCorridorPosY0_met(BI_tpllco_VectorConcatenate_i[1]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch19'/copy1' */
    SET_S_TPLLCO_TargetCridrHeading_rad(BI_tpllco_Sum_f5);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch2'/copy1' */
    SET_S_TPLLCO_DevHeading_rad(BI_tpllco_Switch_f);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch20'/copy1' */
    SET_S_TPLLCO_TargetCorridorCrv_1pm(BI_tpllco_Switch_h);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch21'/copy1' */
    SET_S_TPLLCO_TgtCridrChngOfCrv_1pm2(BI_tpllco_Switch_o);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch22'/copy1' */
    SET_S_TPLLCO_TargetCridrLength_met(BI_tpllco_Switch_of);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch23'/copy1' */
    SET_D_TPLLCO_RightOri_rad(BI_tpllco__TPLLCO_RightOri_rad);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch24'/copy1' */
    SET_D_TPLLCO_DeltaProjPosX_met(BI_tpllco_copy1_l[0]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch25'/copy1' */
    SET_D_TPLLCO_DeltaProjPosY_met(BI_tpllco_copy1_l[1]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch26'/copy1' */
    SET_D_TPLLCO_CCCInvalid_nu(BI_tpllco_DataTypeConversion_n);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch27'/copy1' */
    SET_D_TPLLCO_CCCWarning_nu(rtb_GT_c);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch28'/copy1' */
    SET_D_TPLLCO_CCCEgoYawangle_rad(rtb_Switch1_h);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch29'/copy1' */
    SET_D_TPLLCO_CCCEgoDistX_met(rtb__EgoDist_m[0]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch3'/copy1' */
    SET_S_TPLLCO_ReplanDevDistY_met(BI_tpllco_Sum_f);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch30'/copy1' */
    SET_D_TPLLCO_CCCEgoDistY_met(rtb__EgoDist_m[1]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch4'/copy1' */
    SET_S_TPLLCO_ReplanDevHeading_rad(BI_tpllco_Sum_n);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch5'/copy1' */
    SET_S_TPLLCO_LeftCorridorPosX0_met(BI_tpllco_VectorConcatenate_a[0]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch6'/copy1' */
    SET_S_TPLLCO_LeftCorridorPosY0_met(BI_tpllco_VectorConcatenate_a[1]);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch7'/copy1' */
    SET_S_TPLLCO_LeftCorridorHeading_rad(BI_tpllco_Sum_je);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch8'/copy1' */
    SET_S_TPLLCO_LeftCorridorCrv_1pm(BI_tpllco_Sum_ji);
    /* SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/branch9'/copy1' */
    SET_S_TPLLCO_LeftCridrChngOfCrv_1pm2(BI_tpllco_Switch_j);
    /* S-Function (sfun_setbit): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = BI_tpllco_DTC_out;
        if (!BI_tpllco_DataTypeConversion_n) {
            /* reset */
            temp = temp & (~u8_bit_u8( (uint8) 5U));
        } else {
            /* set */
            temp = temp | u8_bit_u8( (uint8) 5U);
        }
        rtb_sfun_setbit_n = temp;
    }
    /* DataTypeConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/set_bit1/Functionality'/DTC_out' */
    SET_S_TPLLCO_PlausiCheckStatus_nu(rtb_sfun_setbit_n);
    /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan'/Unit Delay1' */
    DW_tpllco_UnitDelay1_DSTATE = rtb_GT_kn;
    /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan'/Unit_Delay2' */
    DW_tpllco_Unit_Delay2_DSTATE = rtb_Switch1_lx;
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tpllco_Unit_Delay_DSTATE_b = rtb_DataTypeConversion_on;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tpllco_Unit_Delay1_DSTATE_c = rtb_Switch2_b;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Calc_Trigger_Replan/EdgeRising1/EDGERISING1'/fcg' */
    for (i = 0; i < 25; i++) {
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/VehDeltaOriArray' */
        DW_tpllco_VehDeltaOriArray_DSTATE[i] = rtb_Assignment2[i];
        /* Update for UnitDelay: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM/M_TPLLCO/Latency_Compensation/Calc_Current_Veh_Position/Management_Odometry_Data'/VehDeltaDistArray' */
        DW_tpllco_VehDeltaDistArray_DSTATE[i] = rtb_Assignment[i];
    }
    /* End of Outputs for SubSystem: 'sda:TPLLCO/TPLLCO/TPLLCO_VehProcess/OPM'/M_TPLLCO' */
}
#include "Pse_TPLLCO.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
