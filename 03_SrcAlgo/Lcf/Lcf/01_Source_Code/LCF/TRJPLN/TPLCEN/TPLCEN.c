/**************************************************************************
COPYRIGHT (C) $Date: 2019/06/25 09:53:07CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJPLN/TPLCEN_VEH/TPLCEN/i/project.pj $
$Log: TPLCEN.c  $
Revision 1.5 2019/06/25 09:53:07CEST Zhu, Qiangqiang (uid41532) 
automatically created
File          : TPLCEN
Generated on  : Tue 25.06.2019 at 08:03:45 (UTC+01:00)
MD5           : [1401445290  3596708261  1234204926   358485962 0](TPLCEN)
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
#include "TPLCEN.h"
#include "TPLCEN_Private.h"
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
#define TPLCEN_START_SEC_DATA_8
#include "TPLCEN_MemMap.h"
static uint8 BI_tplcen_VectorConcatenate[4];
/* 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering'/Vector Concatenate' */
static uint8 DW_tplcen_Unit_Delay1_DSTATE;
static uint8 DW_tplcen_Unit_Delay3_DSTATE;
static uint8 DW_tplcen_UnitDelay_DSTATE_l;
static uint8 DW_tplcen_Unit_Delay3_DSTATE_h;
static uint8 DW_tplcen_Unit_Delay3_DSTATE_l;
static uint8 DW_tplcen_Unit_Delay3_DSTATE_b;
static uint8 DW_tplcen_UnitDelay1_DSTATE_k;
static uint8 DW_tplcen_Unit_Delay1_DSTATE_p;
static uint8 DW_tplcen_Unit_Delay_DSTATE_h;
static uint8 DW_tplcen_Unit_Delay1_DSTATE_l;
static uint8 DW_tplcen_Unit_Delay3_DSTATE_j;
static uint8 DW_tplcen_Unit_Delay2_DSTATE;
static uint8 DW_tplcen_Unit_Delay8_DSTATE;
static uint8 DW_tplcen_Unit_Delay1_DSTATE_d;
static uint8 DW_tplcen_UnitDelay_DSTATE_h;
static uint8 DW_tplcen_Unit_Delay_DSTATE_kz;
static uint8 DW_tplcen_Unit_Delay1_DSTATE_b;
#define TPLCEN_STOP_SEC_DATA_8
#include "TPLCEN_MemMap.h"
#define TPLCEN_START_SEC_DATA_32
#include "TPLCEN_MemMap.h"
static float32 DW_tplcen_Unit_Delay_DSTATE;
static float32 DW_tplcen_Unit_Delay_DSTATE_k;
static float32 DW_tplcen_Unit_Delay_DSTATE_l;
static float32 DW_tplcen_Unit_Delay4_DSTATE;
static float32 DW_tplcen_Unit_Delay5_DSTATE;
static float32 DW_tplcen_Unit_Delay6_DSTATE;
static float32 DW_tplcen_Unit_Delay7_DSTATE;
static float32 DW_tplcen_Unit_Delay_DSTATE_m;
static float32 DW_tplcen_Unit_Delay_DSTATE_a;
static float32 DW_tplcen_UnitDelay1_DSTATE;
static float32 DW_tplcen_UnitDelay_DSTATE;
#define TPLCEN_STOP_SEC_DATA_32
#include "TPLCEN_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TPLCEN/TPLCEN/INI'/TPLCEN_VehReset'
 * Block description for: 'sda:TPLCEN/TPLCEN/INI'/TPLCEN_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLCEN_VehReset
#include "Pse_TPLCEN.h"
/* Short description: Not synchronized with ARAMIS */
void TPLCEN_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant'/Constant' */
    SET_S_TPLCEN_TrajPlanEnbl_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant1'/Constant' */
    SET_S_TPLCEN_TrigTrajReplan_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant10'/Constant' */
    SET_D_TPLCEN_CorridorJumpDetected_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant11'/Constant' */
    SET_S_TPLCEN_EnblSpecPlanStrategy_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant12'/Constant' */
    SET_S_TPLCEN_DelayVehGui_sec(0.0F);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant13'/Constant' */
    SET_D_TPLCEN_LatDMCReqFinished_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant14'/Constant' */
    SET_S_TPLCEN_PredictionTimeCrv_sec(0.0F);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant15'/Constant' */
    SET_S_TPLCEN_PredictionTimeHead_sec(0.0F);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant2'/Constant' */
    SET_S_TPLCEN_ReplanModeArcLength_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant3'/Constant' */
    SET_S_TPLCEN_ReplanCurValues_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant4'/Constant' */
    SET_S_TPLCEN_ReplanTgtValues_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant5'/Constant' */
    SET_D_TPLCEN_TrigCustFctChange_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant6'/Constant' */
    SET_S_TPLCEN_TrajGuiQuChange_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant7'/Constant' */
    SET_D_TPLCEN_TrigLargeDeviation_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant8'/Constant' */
    SET_S_TPLCEN_TrigCustFctActn_nu(0U);
    /* Constant: 'sda:TPLCEN/TPLCEN/INI/TPLCEN_VehReset/Constant9'/Constant' */
    SET_S_TPLCEN_TrigReplanTgtTraj_nu(0U);
}
#include "Pse_TPLCEN.h"
/*
 * Output and update for function-call system: 'sda:TPLCEN/TPLCEN'/TPLCEN_VehProcess'
 * Block description for: 'sda:TPLCEN/TPLCEN'/TPLCEN_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLCEN_VehProcess
#include "Pse_TPLCEN.h"
/* Short description: Not synchronized with ARAMIS */
void TPLCEN_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    uint8 rtb_sfun_setbit;
    uint8 rtb_DataTypeConversion_nu;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_k;
    uint8 rtb_EQ_d;
    uint8 rtb_DataTypeConversion_mz;
    float32 rtb_Abs;
    uint8 rtb_DataTypeConversion_a;
    uint8 rtb_DataTypeConversion_ak;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_DataTypeConversion_m1;
    uint8 rtb_DataTypeConversion_e2;
    uint8 rtb_Switch_h;
    uint8 rtb_DataTypeConversion_n;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_ke;
    uint8 rtb_LT;
    uint8 rtb_DataTypeConversion_du;
    uint8 rtb_DataTypeConversion_cr;
    uint8 rtb_DataTypeConversion_d;
    float32 rtb_Switch2_f;
    float32 rtb_Min_p;
    float32 rtb_Mul_n;
    float32 rtb_Sum_f;
    float32 rtb_Mul_o;
    float32 rtb_Mul_h;
    float32 rtb_Max_a;
    /* Outputs for Atomic SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM'/M_TPLCEN'
         *
         * Block description for 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM'/M_TPLCEN':
         *  X.2.1.1
         */
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant4'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant5'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Equality5/Functionality'/EQ'
         */
    if (((sint32)GET_P_TPLCEN_ActivebyRampout_nu()) != 0) {
        rtb_DataTypeConversion_mz = (uint8)(((sint32)GET_S_CSCLTA_SysStateLCF_enum ()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    } else {
        rtb_DataTypeConversion_mz = 0U;
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition2'/state_source'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Equality3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Equality4/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) GET_S_CSCLTA_SysStateLCF_enum())) || (((sint32)GET_S_CSCLTA_SysStateLCF_enum ()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((sint32)rtb_DataTypeConversion_mz) != 0));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NEQ/Functionality'/NE'
         */
    rtb_DataTypeConversion_k = (uint8)((((sint32)rtb_DataTypeConversion) != 0) && (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) != ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_OFF_nu))));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Application Parameter'/Constant'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator3/Functionality'/AND'
         */
    rtb_DataTypeConversion_nu = (uint8)((((sint32)GET_P_TPLCEN_TrajPlanEnable_nu ()) != 0) && (((sint32)rtb_DataTypeConversion_k) != 0));
    /* RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Equality1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         */
    rtb_EQ_d = (uint8)(((sint32)GET_S_CSCLTA_TrajGuiQualifier_nu()) == ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_REFCHNG)));
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Constant2'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysStOffLatDMC_bool'
         */
    if (((sint32)GET_P_TPLCEN_ActivebyRampout_nu()) != 0) {
        rtb_DataTypeConversion_mz = GET_S_LCFRCV_SysStOffLatDMC_bool();
    } else {
        rtb_DataTypeConversion_mz = 1U;
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/from_data_definition1'/state_source'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Logical Operator1/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Equality2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Equality5/Functionality'/EQ'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange'/Unit Delay'
         */
    rtb_DataTypeConversion_mz = (uint8)(((((sint32) GET_S_CSCLTA_TrajGuiQualifier_nu()) == ((sint32)((uint8) E_LCF_TGQ_Type_E_LCF_TGQ_REQ))) && (((sint32)DW_tplcen_UnitDelay_DSTATE_l) == ((sint32)((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)))) && (((sint32) rtb_DataTypeConversion_mz) != 0));
    /* Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_EPS_ManualTrqActualVal_Nm'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm());
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Constant'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Relational Operator1/Functionality'/GE'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1'/Unit_Delay'
         */
    if (rtb_Abs >= GET_P_TPLCEN_ManualTrqMax_Nm()) {
        rtb_Switch2_f = GET_P_TPLCEN_ManualTrqMaxTime_sec();
    } else if (DW_tplcen_Unit_Delay_DSTATE_k > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1'/Unit_Delay'
                 */
        rtb_Switch2_f = DW_tplcen_Unit_Delay_DSTATE_k - GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_f = 0.0F;
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Abs1/Functionality'/Abs'
         *  Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Abs2/Functionality'/Abs'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Application Parameter1'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_TPLFBT_CtrlErrDistY_met'
         *  Inport: '<Root>/S_TPLFBT_CtrlErrHeadAglPrev_rad'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Relational Operator2/Functionality'/GE'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Relational Operator3/Functionality'/GE'
         */
    rtb_DataTypeConversion_ak = (uint8)((f32_abs_f32 (GET_S_TPLFBT_CtrlErrDistY_met()) >= GET_P_TPLCEN_ErrDistY_met()) || (f32_abs_f32(GET_S_TPLFBT_CtrlErrHeadAglPrev_rad()) >= GET_P_TPLCEN_ErrHeadAglPrev_rad()));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_m = (uint8)((!(rtb_Switch2_f > 0.0F)) && (((sint32) rtb_DataTypeConversion_ak) != 0));
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality'/Comparison'
         */
    /* Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising'/Unit_Delay3'
         */
    BI_tplcen_VectorConcatenate[0] = (uint8)((!(((sint32)DW_tplcen_Unit_Delay3_DSTATE_h) != 0)) && (((sint32)rtb_DataTypeConversion_m) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality'/Comparison'
         */
    /* Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2'/Unit_Delay3'
         */
    BI_tplcen_VectorConcatenate[1] = (uint8)((!(((sint32)DW_tplcen_Unit_Delay3_DSTATE_l) != 0)) && (((sint32)rtb_DataTypeConversion_ak) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3'/fcg' */
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Constant2'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/LE/Functionality'/LE'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer'/Unit_Delay'
         */
    if (rtb_Abs <= GET_P_TPLCEN_ManualTrqMin_Nm()) {
        rtb_Abs = GET_P_TPLCEN_ManualTrqMinTime_sec();
    } else if (DW_tplcen_Unit_Delay_DSTATE_l > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer'/Unit_Delay'
                 */
        rtb_Abs = DW_tplcen_Unit_Delay_DSTATE_l - GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Abs = 0.0F;
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_m1 = (uint8)((((sint32)rtb_DataTypeConversion_ak) != 0) && (!(rtb_Abs > 0.0F)));
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering'/ConcatBufferAtVector ConcatenateIn3' */
    BI_tplcen_VectorConcatenate[2] = rtb_DataTypeConversion_m1;
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality'/Comparison'
         */
    /* Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1'/Unit_Delay3'
         */
    BI_tplcen_VectorConcatenate[3] = (uint8)((!(((sint32)DW_tplcen_Unit_Delay3_DSTATE_b) != 0)) && (((sint32)rtb_DataTypeConversion_m1) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3'/fcg' */
    /* S-Function (sfun_setbit): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[4] = { 0U, 1U, 2U, 3U };
            {
                sint32 i1;
                const uint8 *u1 = &BI_tplcen_VectorConcatenate[0];
                for (i1=0; i1 < 4; i1++) {
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
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Constant4'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Constant5'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/from_data_definition'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EQ/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/AND/Functionality'/AND'
         *  S-Function (sfun_setbit): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/set_bit/Functionality'/sfun_setbit'
         */
    rtb_DataTypeConversion_a = (uint8)(((((sint32)rtb_sfun_setbit) & ((sint32) GET_P_TPLCEN_ReplanLargeErrorMode_nu())) != 0) && (((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Constant'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/from_data_definition'/state_source'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/from_data_definition3'/state_source'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/AND/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Equality3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/Equality4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/NEQ/Functionality'/NE'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange'/Unit Delay1'
         */
    rtb_DataTypeConversion_e2 = (uint8)(((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE)) != ((sint32) DW_tplcen_UnitDelay1_DSTATE_k)) && ((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ))))) && (((sint32)GET_P_TPLCEN_AllowReplanOBF_nu()) != 0));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NEQ1/Functionality'/NE'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay1'
         */
    rtb_DataTypeConversion_n = (uint8)(((((sint32)rtb_DataTypeConversion_k) != 0) && (((sint32)DW_tplcen_Unit_Delay_DSTATE_h) != 0)) && (((sint32) DW_tplcen_Unit_Delay1_DSTATE_l) != ((sint32) GET_S_MCTLFC_ControllingFunction_nu())));
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant10'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant7'/Constant'
         */
    if (((sint32)GET_P_TPLCEN_EnableFcnChngDetect_nu()) != 0) {
        rtb_Switch_h = rtb_DataTypeConversion_n;
    } else {
        rtb_Switch_h = 1U;
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch5/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant15'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition11'/state_source'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition12'/state_source'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition13'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND6/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND8/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NOT2/Functionality'/NOT'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NOT3/Functionality'/NOT'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ7/Functionality'/EQ'
         */
    rtb_DataTypeConversion_o = (uint8)(!((((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))) && (((!(((sint32) GET_P_TPLCEN_EnableJumpDetectOFRQ_nu()) != 0)) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ)))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF))))));
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch4/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Abs/Functionality'/Abs'
         *  Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Abs1/Functionality'/Abs'
         *  Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Abs2/Functionality'/Abs'
         *  Abs: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Abs3/Functionality'/Abs'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant6'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant8'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant9'/Constant'
         *  DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND7/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
         *  Inport: '<Root>/S_TPLLCO_DevHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_TargetPathHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_TargetPathY0_met'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND7/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/GE2/Functionality'/GE'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/GE3/Functionality'/GE'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/LE1/Functionality'/LE'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/LE2/Functionality'/LE'
         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP/Functionality/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1/Functionality/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2/Functionality/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3/Functionality/Sum/Functionality'/Sum'
         *  Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch3/Functionality'/Switch'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay4'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay5'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay6'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay7'
         */
    if (((sint32)GET_P_TPLCEN_UseJumpDetection_nu()) != 0) {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant12'/Constant'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant13'/Constant'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant14'/Constant'
                 *  Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch7/Functionality'/Switch'
                 */
        if (((sint32)GET_P_TPLCEN_EnableJumpDetectOBF_nu()) != 0) {
            rtb_DataTypeConversion_o = 1U;
        } else {
            if (((sint32)GET_P_TPLCEN_UseJumpDetectOBFTrig_nu()) != 0) {
                /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch7/Functionality'/Switch' incorporates:
                                 *  DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/OR3/Functionality'/Data Type Conversion'
                                 *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/OR3/Functionality'/OR'
                                 */
                rtb_DataTypeConversion_o = (uint8)((((sint32)rtb_DataTypeConversion_n) != 0) || (((sint32)rtb_DataTypeConversion_o) != 0));
            }
        }
        /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch6/Functionality'/Switch' */
        /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3'/fcg' incorporates:
                 *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3'/Functionality'
                 */
        rtb_DataTypeConversion_n = (uint8)((((sint32)rtb_DataTypeConversion_o) != 0) && ((((f32_abs_f32(GET_S_TPLLCO_DevDistY_met() - DW_tplcen_Unit_Delay4_DSTATE) >= GET_P_TPLCEN_ReIniDeltaDistY_met()) || (GET_P_TPLCEN_ReIniDeltaDistY_met() <= f32_abs_f32 (GET_S_TPLLCO_TargetPathY0_met() - DW_tplcen_Unit_Delay5_DSTATE))) || (f32_abs_f32(GET_S_TPLLCO_DevHeading_rad() - DW_tplcen_Unit_Delay6_DSTATE) >= GET_P_TPLCEN_ReIniDeltaHead_rad())) || (GET_P_TPLCEN_ReIniDeltaHead_rad() <= f32_abs_f32 (GET_S_TPLLCO_TargetPathHeading_rad() - DW_tplcen_Unit_Delay7_DSTATE))));
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3'/fcg' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2'/fcg' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1'/fcg' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP'/fcg' */
    } else if (((sint32)GET_P_TPLCEN_ReplanbyTJA2X_nu()) != 0) {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant1'/Constant'
                 */
        rtb_DataTypeConversion_n = 1U;
    } else {
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition'/state_source'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition6'/state_source'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition7'/state_source'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition8'/state_source'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition9'/state_source'
                 *  DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NOT/Functionality'/Data Type Conversion'
                 *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND2/Functionality'/AND'
                 *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NOT/Functionality'/NOT'
                 *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ2/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ3/Functionality'/EQ'
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/EQ4/Functionality'/EQ'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay2'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay3'
                 */
        rtb_DataTypeConversion_n = (uint8)(!(((((((sint32) DW_tplcen_Unit_Delay3_DSTATE_j) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))) || (((sint32) DW_tplcen_Unit_Delay3_DSTATE_j) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ)))) || (((sint32) DW_tplcen_Unit_Delay3_DSTATE_j) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) || (((sint32) DW_tplcen_Unit_Delay3_DSTATE_j) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ)))) && (((sint32) DW_tplcen_Unit_Delay2_DSTATE) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu)))));
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_n = (uint8)((((sint32)rtb_Switch_h) != 0) && (((sint32)rtb_DataTypeConversion_n) != 0));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant11'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition10'/state_source'
         *  Inport: '<Root>/S_LCFRCV_SysStReqLatDMC_bool'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND4/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/AND5/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/NEQ2/Functionality'/NE'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay8'
         */
    rtb_DataTypeConversion_o = (uint8)(((((sint32) GET_S_MCTLFC_ControllingFunction_nu()) != ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))) && ((((sint32) DW_tplcen_Unit_Delay8_DSTATE) != 0) && (!(((sint32) GET_S_LCFRCV_SysStReqLatDMC_bool()) != 0)))) && (((sint32) GET_P_TPLCEN_ReIniWrtDMCReq_nu()) != 0));
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI'/Functionality'
         */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality'/Logical Operator2'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI/Functionality'/Relational Operator'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2'/Unit_Delay1'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising'/Unit_Delay3'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI'/Unit_Delay1'
         */
    rtb_DataTypeConversion_ke = (uint8)((((sint32)rtb_DataTypeConversion_nu) != 0) && ((((((((!(((sint32)DW_tplcen_Unit_Delay1_DSTATE) != 0)) && (((sint32) rtb_DataTypeConversion_k) != 0)) || ((!(((sint32)DW_tplcen_Unit_Delay3_DSTATE) != 0)) && (((sint32)rtb_EQ_d) != 0))) || (((sint32)rtb_DataTypeConversion_mz) != 0)) || (((sint32)rtb_DataTypeConversion_a) != 0)) || (((sint32) rtb_DataTypeConversion_e2) != ((sint32)DW_tplcen_Unit_Delay1_DSTATE_p))) || (((sint32)rtb_DataTypeConversion_n) != 0)) || (((sint32) rtb_DataTypeConversion_o) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1'/fcg' */
    /* RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Relational Operator/Functionality'/LT' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Application Parameter1'/Constant'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Conv_kph_to_mps_const'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Conv_kph_to_mps/Functionality'/Mul'
         */
    rtb_LT = (uint8)(GET_S_LCFRCV_VehVelX_mps() < (GET_P_TPLCEN_VMinTimeBasedTraj_kph() * 0.277778F));
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI'/Functionality'
         */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI/Functionality'/Relational Operator'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI'/Unit_Delay1'
         */
    rtb_DataTypeConversion_du = (uint8)((((sint32)rtb_DataTypeConversion_ke) != 0) || (((sint32)rtb_LT) != ((sint32)DW_tplcen_Unit_Delay1_DSTATE_d)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI'/fcg' */
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER'/IV'
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER'/IV'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2'
         */
    if (((sint32)rtb_DataTypeConversion_du) != 0) {
        rtb_Min_p = 0.0F;
        rtb_Sum_f = 0.0F;
    } else {
        /* S-Function Block sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Y_TPLCEN_DeadTimeVehCtrl_sec/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TPLCEN_PotVecDynVelX_mps */
            FDPS_PTR_F32(GETA_X_TPLCEN_PotVecDynVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TPLCEN_DeadTimeVehCtrl_sec (), &dps_result_ln);
        }
        /* MinMax: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/MinMax/Functionality'/Min' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 */
        rtb_Min_p = f32_min_f32_f32(1.0F, rtb_ip_lookup_fxpt_sfun_7);
        /* Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp'/Unit_Delay'
                 */
        rtb_Sum_f = rtb_Min_p - DW_tplcen_Unit_Delay_DSTATE;
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Div/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant3'/Constant'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant6'/Constant'
                 *  MinMax: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Max/Functionality'/Max'
                 *  Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Div/Functionality/DivDefault'/Div'
                 */
        rtb_Max_a = rtb_Min_p / f32_max_f32_f32(GET_P_TPLCEN_DTGradLimitDuration_sec (), 0.02F);
        /* Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 */
        rtb_Mul_n = rtb_Max_a * GET_S_LCFRCV_SysCycleTimeVeh_sec();
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp'/Unit_Delay'
                 */
        if (rtb_Sum_f > rtb_Mul_n) {
            rtb_Min_p = rtb_Mul_n + DW_tplcen_Unit_Delay_DSTATE;
        } else {
            /* Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  UnaryMinus: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/Neg/Functionality'/Unary Minus'
                         */
            rtb_Max_a = (-rtb_Max_a) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp'/Unit_Delay'
                         */
            if (rtb_Sum_f < rtb_Max_a) {
                rtb_Min_p = rtb_Max_a + DW_tplcen_Unit_Delay_DSTATE;
            }
            /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
        /* MinMax: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/MinMax1/Functionality'/Min' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant4'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_PredictionTimeCrv_sec'
                 */
        rtb_Sum_f = f32_min_f32_f32(GET_P_TPLCEN_MaxPredictionTime_sec(), GET_S_CSCLTA_PredictionTimeCrv_sec());
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Div1/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant1'/Constant'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant7'/Constant'
                 *  MinMax: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Max1/Functionality'/Max'
                 *  Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Div1/Functionality/DivDefault'/Div'
                 */
        rtb_Mul_n = rtb_Sum_f / f32_max_f32_f32(GET_P_TPLCEN_PTCrvGradLimitDur_sec(), 0.06F);
        /* Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp'/Unit_Delay'
                 */
        rtb_Max_a = rtb_Sum_f - DW_tplcen_Unit_Delay_DSTATE_m;
        /* Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 */
        rtb_Mul_o = rtb_Mul_n * GET_S_LCFRCV_SysCycleTimeVeh_sec();
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp'/Unit_Delay'
                 */
        if (rtb_Max_a > rtb_Mul_o) {
            rtb_Sum_f = rtb_Mul_o + DW_tplcen_Unit_Delay_DSTATE_m;
        } else {
            /* Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  UnaryMinus: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/Neg/Functionality'/Unary Minus'
                         */
            rtb_Mul_n = (-rtb_Mul_n) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp'/Unit_Delay'
                         */
            if (rtb_Max_a < rtb_Mul_n) {
                rtb_Sum_f = rtb_Mul_n + DW_tplcen_Unit_Delay_DSTATE_m;
            }
            /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
    SET_S_TPLCEN_DelayVehGui_sec(rtb_Min_p);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
    SET_S_TPLCEN_PredictionTimeCrv_sec(rtb_Sum_f);
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
                                                     *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER'/IV'
                                                     */
    if (((sint32)rtb_DataTypeConversion_du) != 0) {
        rtb_Max_a = 0.0F;
    } else {
        /* MinMax: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/MinMax2/Functionality'/Min' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant5'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_PredTimeHeadAng_sec'
                 */
        rtb_Max_a = f32_min_f32_f32(GET_P_TPLCEN_MaxPredictionTime_sec(), GET_S_CSCLTA_PredTimeHeadAng_sec());
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Div2/Functionality/DivDefault'/Switch' incorporates:
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant2'/Constant'
                 *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Constant8'/Constant'
                 *  MinMax: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Max2/Functionality'/Max'
                 *  Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/Div2/Functionality/DivDefault'/Div'
                 */
        rtb_Mul_o = rtb_Max_a / f32_max_f32_f32(GET_P_TPLCEN_PTHeadGradLimitDur_sec(), 0.06F);
        /* Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp'/Unit_Delay'
                 */
        rtb_Mul_n = rtb_Max_a - DW_tplcen_Unit_Delay_DSTATE_a;
        /* Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 */
        rtb_Mul_h = rtb_Mul_o * GET_S_LCFRCV_SysCycleTimeVeh_sec();
        /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp'/Unit_Delay'
                 */
        if (rtb_Mul_n > rtb_Mul_h) {
            rtb_Max_a = rtb_Mul_h + DW_tplcen_Unit_Delay_DSTATE_a;
        } else {
            /* Product: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  UnaryMinus: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/Neg/Functionality'/Unary Minus'
                         */
            rtb_Mul_o = (-rtb_Mul_o) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
            /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp'/Unit_Delay'
                         */
            if (rtb_Mul_n < rtb_Mul_o) {
                rtb_Max_a = rtb_Mul_o + DW_tplcen_Unit_Delay_DSTATE_a;
            }
            /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp/GRADIENTLIMITER/Functionality'/Signal Conversion1' */
    SET_S_TPLCEN_PredictionTimeHead_sec(rtb_Max_a);
    /* RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer/Relational Operator1/Functionality'/GT' incorporates:
                                                      *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Application Parameter3'/Constant'
                                                      *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                                                      *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer/Add1/Functionality'/Sum'
                                                      *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer'/Unit Delay1'
                                                      */
    rtb_DataTypeConversion_du = (uint8)(DW_tplcen_UnitDelay1_DSTATE > (GET_P_TPLCEN_CyCTimeTrajCalc_sec() - GET_S_LCFRCV_SysCycleTimeVeh_sec()));
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer/Logical Operator6/Functionality'/OR'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer'/Unit Delay'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan'/Unit Delay'
         */
    if ((((sint32)rtb_DataTypeConversion_du) != 0) || (((sint32) DW_tplcen_UnitDelay_DSTATE_h) != 0)) {
        rtb_Mul_n = GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        rtb_Mul_n = DW_tplcen_UnitDelay_DSTATE;
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI'/Functionality'
         */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Constant'/Constant'
         *  Inport: '<Root>/S_CSCLTA_TriggerReplan_nu'
         *  Inport: '<Root>/S_TPLLCO_TriggerReplan_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/AND/Functionality'/AND'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator4/Functionality'/OR'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator6/Functionality'/AND'
         *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI/Functionality'/Relational Operator'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI'/Unit_Delay1'
         */
    rtb_DataTypeConversion_cr = (uint8)(((((sint32)rtb_LT) != ((sint32) DW_tplcen_Unit_Delay1_DSTATE_b)) || (((((sint32) GET_P_TPLCEN_LCOReplanEnable_nu()) != 0) && (((sint32) GET_S_TPLLCO_TriggerReplan_nu()) != 0)) && (((sint32) GET_S_CSCLTA_TriggerReplan_nu()) != 0))) && (((sint32) rtb_DataTypeConversion_nu) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI'/fcg' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_d = (uint8)((((sint32)rtb_DataTypeConversion_cr) != 0) || (((sint32)rtb_DataTypeConversion_ke) != 0));
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Application Parameter4'/Constant'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Logical Operator7/Functionality'/AND'
         */
    rtb_DataTypeConversion_du = (uint8)((((sint32)rtb_DataTypeConversion_du) != 0) && (((sint32)GET_P_TPLCEN_CycEnable_nu()) != 0));
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TPLTJC_TrajEnd_nu'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Logical Operator5/Functionality'/OR'
         *  UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising'/Unit_Delay'
         */
    rtb_DataTypeConversion_du = (uint8)((((!(((sint32) DW_tplcen_Unit_Delay_DSTATE_kz) != 0)) && (((sint32)GET_S_TPLTJC_TrajEnd_nu()) != 0)) || (((sint32)rtb_DataTypeConversion_d) != 0)) || (((sint32) rtb_DataTypeConversion_du) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Logical Operator4/Functionality'/AND'
         */
    rtb_DataTypeConversion_du = (uint8)((((sint32)rtb_DataTypeConversion_du) != 0) && (((sint32)rtb_DataTypeConversion_nu) != 0));
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/branch'/copy1' */
    SET_S_TPLCEN_TrigTrajReplan_nu(rtb_DataTypeConversion_du);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/branch'/copy1' */
    SET_S_TPLCEN_TrigCustFctActn_nu(rtb_DataTypeConversion_ke);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/branch3'/copy1' */
    SET_S_TPLCEN_ReplanTgtValues_nu(rtb_DataTypeConversion_cr);
    /* Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch1/Functionality'/Switch' incorporates:
                                                                  *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant2'/Constant'
                                                                  *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Constant3'/Constant'
                                                                  *  Constant: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/from_data_definition1'/state_source'
                                                                  *  DataTypeConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Logical Operator1/Functionality'/Data Type Conversion'
                                                                  *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
                                                                  *  Logic: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Logical Operator1/Functionality'/AND'
                                                                  *  RelationalOperator: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Equality1/Functionality'/EQ'
                                                                  */
    if (((sint32)GET_P_TPLCEN_AllowSpePlanStrategy_nu()) != 0) {
        SET_S_TPLCEN_EnblSpecPlanStrategy_nu((uint8)((((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))) && (((sint32)rtb_DataTypeConversion) != 0)));
    } else {
        SET_S_TPLCEN_EnblSpecPlanStrategy_nu(0U);
    }
    /* End of Switch: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/branch1'/copy1' */
    SET_S_TPLCEN_TrajGuiQuChange_nu(rtb_DataTypeConversion_mz);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/branch2'/copy1' */
    SET_D_TPLCEN_TrigLargeDeviation_nu(rtb_DataTypeConversion_a);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/branch3'/copy1' */
    SET_D_TPLCEN_TrigCustFctChange_nu(rtb_Switch_h);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/branch4'/copy1' */
    SET_D_TPLCEN_CorridorJumpDetected_nu(rtb_DataTypeConversion_n);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/branch5'/copy1' */
    SET_D_TPLCEN_LatDMCReqFinished_nu(rtb_DataTypeConversion_o);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/branch1'/copy1' */
    SET_S_TPLCEN_TrigReplanTgtTraj_nu(rtb_DataTypeConversion_d);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/branch2'/copy1' */
    SET_S_TPLCEN_ReplanCurValues_nu(rtb_DataTypeConversion_ke);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/branch3'/copy1' */
    SET_S_TPLCEN_TrajPlanEnbl_nu(rtb_DataTypeConversion_nu);
    /* SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/branch4'/copy1' */
    SET_S_TPLCEN_ReplanModeArcLength_nu(rtb_LT);
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/DeadTimeRampUp'/Unit_Delay' */
    DW_tplcen_Unit_Delay_DSTATE = rtb_Min_p;
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay1_DSTATE = rtb_DataTypeConversion_k;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdegeRising2/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay3_DSTATE = rtb_EQ_d;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdegeRising/EDGERISING3'/fcg' */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange'/Unit Delay' incorporates:
         *  Update for Inport: '<Root>/S_CSCLTA_TrajGuiQualifier_nu'
         */
    DW_tplcen_UnitDelay_DSTATE_l = GET_S_CSCLTA_TrajGuiQualifier_nu();
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer1'/Unit_Delay' */
    DW_tplcen_Unit_Delay_DSTATE_k = rtb_Switch2_f;
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay3_DSTATE_h = rtb_DataTypeConversion_m;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising/EDGERISING3'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay3_DSTATE_l = rtb_DataTypeConversion_ak;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising2/EDGERISING3'/fcg' */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/Timer'/Unit_Delay' */
    DW_tplcen_Unit_Delay_DSTATE_l = rtb_Abs;
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1'/Unit_Delay3' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay3_DSTATE_b = rtb_DataTypeConversion_m1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_Driver_Implus_Steering/EdegeRising1/EDGERISING3'/fcg' */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange'/Unit Delay1' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tplcen_UnitDelay1_DSTATE_k = GET_S_TJASTM_LatCtrlMode_nu();
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay1_DSTATE_p = rtb_DataTypeConversion_e2;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/TrajGuiQuChange/EdgeBI/EDGEBI'/fcg' */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay' */
    DW_tplcen_Unit_Delay_DSTATE_h = rtb_DataTypeConversion_k;
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    DW_tplcen_Unit_Delay1_DSTATE_l = GET_S_MCTLFC_ControllingFunction_nu();
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay4' incorporates:
         *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
         */
    DW_tplcen_Unit_Delay4_DSTATE = GET_S_TPLLCO_DevDistY_met();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay5' incorporates:
         *  Inport: '<Root>/S_TPLLCO_TargetPathY0_met'
         */
    DW_tplcen_Unit_Delay5_DSTATE = GET_S_TPLLCO_TargetPathY0_met();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP1'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay6' incorporates:
         *  Inport: '<Root>/S_TPLLCO_DevHeading_rad'
         */
    DW_tplcen_Unit_Delay6_DSTATE = GET_S_TPLLCO_DevHeading_rad();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP2'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay7' incorporates:
         *  Inport: '<Root>/S_TPLLCO_TargetPathHeading_rad'
         */
    DW_tplcen_Unit_Delay7_DSTATE = GET_S_TPLLCO_TargetPathHeading_rad();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState/DELTAONESTEP3'/fcg' */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay3' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tplcen_Unit_Delay3_DSTATE_j = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay2' incorporates:
         *  Update for Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    DW_tplcen_Unit_Delay2_DSTATE = GET_S_MCTLFC_ControllingFunction_nu();
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/LCF_SysState'/Unit_Delay8' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_SysStReqLatDMC_bool'
         */
    DW_tplcen_Unit_Delay8_DSTATE = GET_S_LCFRCV_SysStReqLatDMC_bool();
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay1_DSTATE_d = rtb_LT;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/EdgeBI/EDGEBI'/fcg' */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeCrvRampUp'/Unit_Delay' */
    DW_tplcen_Unit_Delay_DSTATE_m = rtb_Sum_f;
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Delay_Pred_VehCtrl/PredictionTimeHeadRampUp'/Unit_Delay' */
    DW_tplcen_Unit_Delay_DSTATE_a = rtb_Max_a;
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer'/Unit Delay1' */
    DW_tplcen_UnitDelay1_DSTATE = rtb_Mul_n;
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan'/Unit Delay' */
    DW_tplcen_UnitDelay_DSTATE_h = rtb_DataTypeConversion_du;
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer'/Unit Delay' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Sum: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/Cycle_Timer/Add/Functionality'/Sum'
         */
    DW_tplcen_UnitDelay_DSTATE = rtb_Mul_n + GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising'/Unit_Delay' incorporates:
         *  Inport: '<Root>/S_TPLTJC_TrajEnd_nu'
         */
    DW_tplcen_Unit_Delay_DSTATE_kz = GET_S_TPLTJC_TrajEnd_nu();
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Time_and_Trigger_for_Replan/EdgeRising/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI'/fcg' incorporates:
         *  SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI'/Functionality'
         */
    /* Update for UnitDelay: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI/Functionality'/Signal Conversion'
         */
    DW_tplcen_Unit_Delay1_DSTATE_b = rtb_LT;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM/M_TPLCEN/Calc_Trigger_TrajPlan/Calc_Trigger_and_Enable/EdgeBI/EDGEBI'/fcg' */
    /* End of Outputs for SubSystem: 'sda:TPLCEN/TPLCEN/TPLCEN_VehProcess/OPM'/M_TPLCEN' */
}
#include "Pse_TPLCEN.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
