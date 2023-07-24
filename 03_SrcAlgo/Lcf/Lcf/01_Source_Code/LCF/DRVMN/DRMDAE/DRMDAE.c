/**************************************************************************
COPYRIGHT (C) $Date: 2020/03/02 09:09:00CET $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/DRVMN/DRMDAE_VEH/DRMDAE/i/project.pj $
$Log: DRMDAE.c  $
Revision 1.4 2020/03/02 09:09:00CET Grama, Victor (uib08724) (uib08724) 
automatically created
File          : DRMDAE
Generated on  : Mon 02.03.2020 at 09:56:40 (UTC+01:00)
MD5           : [2425719008   955234536  1170206780  3542566772 0](DRMDAE)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,105,106
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DRMDAE.h"
#include "DRMDAE_private.h"
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
/* Named constants for Chart: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/DriverAttentionStateMachine' */
#define DRMDAE_IN_HandsOnRequest       ((uint8)1U)
#define DRMDAE_IN_NoWarning            ((uint8)2U)
#define DRMDAE_IN_TakeOverRequest      ((uint8)3U)
#define DRMDAE_IN_TriggerDegradation   ((uint8)4U)
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
#define DRMDAE_START_SEC_DATA_8
#include "DRMDAE_MemMap.h"
static uint8 BI_drmdae_DRMDAE_SysWarning_nu;
/* 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/DriverAttentionStateMachine' */
static uint8 DW_drmdae_Unit_Delay_DSTATE_c;
static uint8 DW_drmdae_Unit_Delay1_DSTATE;
static uint8 DW_drmdae_Unit_Delay_DSTATE_ca;
static uint8 DW_drmdae_Unit_Delay_DSTATE_l;
static uint8 DW_drmdae_Unit_Delay_DSTATE_j;
static uint8 DW_drmdae_Unit_Delay_DSTATE_d;
static uint8 DW_drmdae_Unit_Delay_DSTATE_e;
static uint8 DW_drmdae_Unit_Delay_DSTATE_k;
static uint8 DW_drmdae_Unit_Delay_DSTATE_jm;
static uint8 DW_drmdae_UnitDelay2_DSTATE;
static uint8 DW_drmdae_UnitDelay1_DSTATE_h;
static uint8 DW_drmdae_UnitDelay1_DSTATE_b;
static uint8 DW_drmdae_UnitDelay1_DSTATE_ga;
static uint8 DW_drmdae_is_active_c14_DRMDAE_cg;
static uint8 DW_drmdae_is_c14_DRMDAE_cg;
#define DRMDAE_STOP_SEC_DATA_8
#include "DRMDAE_MemMap.h"
#define DRMDAE_START_SEC_DATA_32
#include "DRMDAE_MemMap.h"
static float32 DW_drmdae_UnitDelay1_DSTATE;
static float32 DW_drmdae_UnitDelay1_DSTATE_o;
static float32 DW_drmdae_UnitDelay1_DSTATE_g;
static float32 DW_drmdae_UnitDelay_DSTATE;
static float32 DW_drmdae_UnitDelay_DSTATE_d;
static float32 DW_drmdae_UnitDelay_DSTATE_h;
static uint32 DW_drmdae_Unit_Delay_DSTATE;
#define DRMDAE_STOP_SEC_DATA_32
#include "DRMDAE_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DRMDAE/DRMDAE/INI'/DRMDAE_VehReset'
 * Block description for: 'sda:DRMDAE/DRMDAE/INI'/DRMDAE_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DRMDAE_VehReset
#include "Pse_DRMDAE.h"
/* Short description: Not synchronized with ARAMIS */
void DRMDAE_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant1'/Constant' */
    SET_S_DRMDAE_DrvAttention_perc(0.0F);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant10'/Constant' */
    SET_D_DRMDAE_CriticalEventsNo_nu(0U);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant2'/Constant' */
    SET_S_DRMDAE_AbuseWarning_bool(0U);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant3'/Constant' */
    SET_S_DRMDAE_DrvAttentionConf_perc(0);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant4'/Constant' */
    SET_D_DRMDAE_AbuseWarnDuration_sec(0.0F);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant5'/Constant' */
    SET_D_DRMDAE_HoffTrigger_nu(0U);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant6'/Constant' */
    SET_D_DRMDAE_ElapsedTime_sec(0.0F);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant7'/Constant' */
    SET_D_DRMDAE_ResetWarnCnt_nu(0U);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant8'/Constant' */
    SET_D_DRMDAE_ActToi_nu(0U);
    /* Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/Constant9'/Constant' */
    SET_D_DRMDAE_SpeedOk_bool(0U);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/from_data_definition4'/Signal Conversion3' incorporates:
                                            *  Constant: 'sda:DRMDAE/DRMDAE/INI/DRMDAE_VehReset/from_data_definition4'/state_source'
                                            */
    SET_S_DRMDAE_SysWarning_nu(((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_NOWNG));
}
#include "Pse_DRMDAE.h"
/*
 * Output and update for function-call system: 'sda:DRMDAE/DRMDAE'/DRMDAE_VehProcess'
 * Block description for: 'sda:DRMDAE/DRMDAE'/DRMDAE_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DRMDAE_VehProcess
#include "Pse_DRMDAE.h"
/* Short description: Not synchronized with ARAMIS */
void DRMDAE_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    uint16 rtb_sfun_setbit;
    uint8 rtb_Switch_c;
    uint8 rtb_NE;
    float32 rtb_Switch_eq;
    uint8 rtb_GT;
    uint8 rtb_Switch_l;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_ft;
    uint8 rtb_EQ;
    float32 rtb_Switch;
    float32 rtb_Sum;
    float32 rtb_Sum_hi;
    uint8 rtb_Switch_j;
    uint16 rtb_Switch_h1;
    uint8 rtb_Switch_m;
    uint8 rtb_Switch_h4;
    uint8 rtb_Switch_f;
    uint32 qY;
    /* S-Function (sfix_bitop): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/AND1/Functionality'/AND' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/P_DRMDAE_RlvntConfFct_btf'/Constant'
         *  Inport: '<Root>/S_HMIOC_AvailableFunction_btf'
         */
    rtb_Switch_c = (uint8)(((sint32)GET_S_HMIOC_AvailableFunction_btf()) & ((sint32)GET_P_DRMDAE_RlvntConfFct_btf()));
    /* RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/Constant2'/Constant'
         */
    rtb_NE = (uint8)(0 != ((sint32)rtb_Switch_c));
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Constant1'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Constant5'/Constant'
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck'/Unit_Delay'
         */
    if (((sint32)DW_drmdae_Unit_Delay_DSTATE_c) != 0) {
        rtb_Switch = GET_P_DRMDAE_SpeedMin_mps() - GET_P_DRMDAE_SpeedLimitHyst_mps();
    } else {
        rtb_Switch = GET_P_DRMDAE_SpeedMin_mps();
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/GT/Functionality'/GT' incorporates:
         *  Abs: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Abs/Functionality'/Abs'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_GT = (uint8)(f32_abs_f32(GET_S_LCFRCV_VehVelX_mps()) > rtb_Switch);
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_DRMHOD_HandsOffConfirmed_bool'
         */
    if (((sint32)rtb_GT) != 0) {
        rtb_Switch_l = GET_S_DRMHOD_HandsOffConfirmed_bool();
    } else {
        rtb_Switch_l = 0U;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Logical NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Logical NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion = (uint8)(!(((sint32)rtb_Switch_l) != 0));
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Limit/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Limit'/MX'
         *  Inport: '<Root>/S_LCFRCV_ActFctLevel_nu'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Limit/Functionality'/Relational Operator'
         */
    if (9 >= ((sint32)GET_S_LCFRCV_ActFctLevel_nu())) {
        rtb_Switch_j = GET_S_LCFRCV_ActFctLevel_nu();
    } else {
        rtb_Switch_j = 9U;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Limit/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_ft = (uint8)((((sint32)rtb_Switch_c) != 0) && (((sint32)rtb_Switch_l) != 0));
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/Gain_const'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_LCFRCV_VehSync4LCO_us'
         *  Product: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/Gain/Functionality'/Mul'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/GT/Functionality'/GT'
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/Sum/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE'/Unit_Delay'
         */
    if (DW_drmdae_Unit_Delay_DSTATE > GET_S_LCFRCV_VehSync4LCO_us()) {
        rtb_Switch = GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        /* Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/Sum/Functionality'/Sum' */
        qY = GET_S_LCFRCV_VehSync4LCO_us() - DW_drmdae_Unit_Delay_DSTATE;
        if (qY > GET_S_LCFRCV_VehSync4LCO_us()) {
            qY = 0U;
        }
        rtb_Switch = ((float32)qY) * 1.0E-6F;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/Switch/Functionality'/Switch' */
    /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay'
         *
         * Block description for 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay':
         *  .1.1.1.1
         */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant2'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Constant'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Gain_const'/Constant'
         *  MinMax: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/MinMax/Functionality'/Min'
         *  Product: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Gain/Functionality'/Mul'
         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array/Functionality/selector'/Selector'
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay'/Unit Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay'/Unit Delay1'
         */
    if (((sint32)DW_drmdae_UnitDelay1_DSTATE_ga) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array'/Functionality' */
        rtb_Switch_eq = f32_min_f32_f32(DW_drmdae_UnitDelay_DSTATE_h + rtb_Switch, GET_P_DRMDAE_DebHorAfterHandsOff_sec((rtb_Switch_j)) * 2.0F);
        /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array'/Functionality' */
    } else {
        rtb_Switch_eq = 0.0F;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant2'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Constant1'/Constant'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Relational Operator/Functionality'/GE'
         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array/Functionality/selector'/Selector'
         */
    if (((sint32)rtb_DataTypeConversion_ft) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array'/Functionality' */
        rtb_Switch_m = (uint8)(rtb_Switch_eq >= GET_P_DRMDAE_DebHorAfterHandsOff_sec((rtb_Switch_j)));
        /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array'/Functionality' */
    } else {
        rtb_Switch_m = 0U;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay/Switch1/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay'/Unit Delay' */
    DW_drmdae_UnitDelay_DSTATE_h = rtb_Switch_eq;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay'/Unit Delay1' */
    DW_drmdae_UnitDelay1_DSTATE_ga = rtb_DataTypeConversion_ft;
    /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay' */
    /* UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/FixPt Unit Delay1' */
    rtb_DataTypeConversion_ft = BI_drmdae_DRMDAE_SysWarning_nu;
    /* RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/from_data_definition2'/state_source'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/FixPt Unit Delay1'
         */
    rtb_EQ = (uint8)(((sint32)((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_ATVNREQ)) == ((sint32)BI_drmdae_DRMDAE_SysWarning_nu));
    /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay1'
         *
         * Block description for 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay1':
         *  .1.1.1.2
         */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant4'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Constant'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Gain_const'/Constant'
         *  MinMax: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/MinMax/Functionality'/Min'
         *  Product: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Gain/Functionality'/Mul'
         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array1/Functionality/selector'/Selector'
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1'/Unit Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1'/Unit Delay1'
         */
    if (((sint32)DW_drmdae_UnitDelay1_DSTATE_b) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array1'/Functionality' */
        rtb_Switch_eq = f32_min_f32_f32(DW_drmdae_UnitDelay_DSTATE_d + rtb_Switch, GET_P_DRMDAE_DebounceTorAfterHor_sec((rtb_Switch_j)) * 2.0F);
        /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array1'/Functionality' */
    } else {
        rtb_Switch_eq = 0.0F;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant4'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Constant1'/Constant'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Relational Operator/Functionality'/GE'
         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array1/Functionality/selector'/Selector'
         */
    if (((sint32)rtb_EQ) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array1'/Functionality' */
        rtb_Switch_h4 = (uint8)(rtb_Switch_eq >= GET_P_DRMDAE_DebounceTorAfterHor_sec((rtb_Switch_j)));
        /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array1'/Functionality' */
    } else {
        rtb_Switch_h4 = 0U;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1/Switch1/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1'/Unit Delay' */
    DW_drmdae_UnitDelay_DSTATE_d = rtb_Switch_eq;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay1'/Unit Delay1' */
    DW_drmdae_UnitDelay1_DSTATE_b = rtb_EQ;
    /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay1' */
    /* RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Equality7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/from_data_definition1'/state_source'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/FixPt Unit Delay1'
         */
    rtb_EQ = (uint8)(((sint32)BI_drmdae_DRMDAE_SysWarning_nu) == ((sint32)((uint8) E_DRMDAE_SysWarnType_E_DRMDAE_TOR)));
    /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay2'
         *
         * Block description for 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay2':
         *  .1.1.1.3
         */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Constant'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Gain_const'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant5'/Constant'
         *  MinMax: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/MinMax/Functionality'/Min'
         *  Product: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Gain/Functionality'/Mul'
         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2/Functionality/selector'/Selector'
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2'/Unit Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2'/Unit Delay1'
         */
    if (((sint32)DW_drmdae_UnitDelay1_DSTATE_h) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2'/Functionality' */
        rtb_Switch_eq = f32_min_f32_f32(DW_drmdae_UnitDelay_DSTATE + rtb_Switch, GET_P_DRMDAE_TrigDegrAftTorTime_sec((rtb_Switch_j)) * 2.0F);
        /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2'/Functionality' */
    } else {
        rtb_Switch_eq = 0.0F;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Switch2/Functionality'/Switch' */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2'/Unit Delay' */
    DW_drmdae_UnitDelay_DSTATE = rtb_Switch_eq;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2'/Unit Delay1' */
    DW_drmdae_UnitDelay1_DSTATE_h = rtb_EQ;
    /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay2' */
    /* Chart: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/DriverAttentionStateMachine' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/from_data_definition'/state_source'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/from_data_definition1'/state_source'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/from_data_definition2'/state_source'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/from_data_definition3'/state_source'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant5'/Constant'
         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2/Functionality/selector'/Selector'
         *  Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Switch1/Functionality'/Switch'
         *
         * Block description for 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/DriverAttentionStateMachine':
         *  .1.2
         */
    /* Gateway: DRMDAE_cg/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine */
    /* During: DRMDAE_cg/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine */
    if (((uint32)((sint32)DW_drmdae_is_active_c14_DRMDAE_cg)) == 0U) {
        /* Entry: DRMDAE_cg/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine */
        DW_drmdae_is_active_c14_DRMDAE_cg = 1U;
        /* Entry Internal: DRMDAE_cg/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine */
        /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':10' */
        DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_NoWarning;
        /* Entry 'NoWarning': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':3' */
        BI_drmdae_DRMDAE_SysWarning_nu = ((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_NOWNG);
    } else {
        switch (DW_drmdae_is_c14_DRMDAE_cg) {
        case DRMDAE_IN_HandsOnRequest:
            /* During 'HandsOnRequest': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':15' */
            /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':24' */
            if ((!(((sint32)rtb_NE) != 0)) || (((sint32)rtb_DataTypeConversion) != 0)) {
                /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':29' */
                DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_NoWarning;
                /* Entry 'NoWarning': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':3' */
                BI_drmdae_DRMDAE_SysWarning_nu = ((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_NOWNG);
            } else {
                /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2'/Functionality' */
                if ((((sint32)rtb_Switch_h4) != 0) && (GET_P_DRMDAE_TrigDegrAftTorTime_sec((rtb_Switch_j)) == 0.0F)) {
                    /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':58' */
                    DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_TriggerDegradation;
                    /* Entry 'TriggerDegradation': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':46' */
                    BI_drmdae_DRMDAE_SysWarning_nu = ((uint8) E_DRMDAE_SysWarnType_E_DRMDAE_DEGRTRIG);
                } else {
                    if ((((sint32)rtb_Switch_h4) != 0) && (GET_P_DRMDAE_TrigDegrAftTorTime_sec((rtb_Switch_j)) > 0.0F)) {
                        /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':19' */
                        DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_TakeOverRequest;
                        /* Entry 'TakeOverRequest': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':16' */
                        BI_drmdae_DRMDAE_SysWarning_nu = ((uint8) E_DRMDAE_SysWarnType_E_DRMDAE_TOR);
                    }
                }
                /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2'/Functionality' */
            }
            break;
        case DRMDAE_IN_NoWarning:
            /* During 'NoWarning': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':3' */
            if (((((sint32)rtb_Switch_m) != 0) && (((sint32)rtb_NE) != 0)) && (!(((sint32)rtb_DataTypeConversion) != 0))) {
                /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':28' */
                DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_HandsOnRequest;
                /* Entry 'HandsOnRequest': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':15' */
                BI_drmdae_DRMDAE_SysWarning_nu = ((uint8) E_DRMDAE_SysWarnType_E_DRMDAE_ATVNREQ);
            }
            break;
        case DRMDAE_IN_TakeOverRequest:
            /* During 'TakeOverRequest': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':16' */
            /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':25' */
            if ((!(((sint32)rtb_NE) != 0)) || (((sint32)rtb_DataTypeConversion) != 0)) {
                /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':29' */
                DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_NoWarning;
                /* Entry 'NoWarning': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':3' */
                BI_drmdae_DRMDAE_SysWarning_nu = ((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_NOWNG);
            } else {
                /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay2'
                                 *
                                 * Block description for 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay2':
                                 *  .1.1.1.3
                                 */
                if (((sint32)rtb_EQ) != 0) {
                    /* Outputs for Atomic SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2'/Functionality' */
                    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Switch1/Functionality'/Switch' incorporates:
                                         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/Constant5'/Constant'
                                         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Relational Operator/Functionality'/GE'
                                         *  Selector: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2/Functionality/selector'/Selector'
                                         */
                    rtb_EQ = (uint8)(rtb_Switch_eq >= GET_P_DRMDAE_TrigDegrAftTorTime_sec((rtb_Switch_j)));
                    /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/read_array2'/Functionality' */
                } else {
                    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Switch1/Functionality'/Switch' incorporates:
                                         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay/VariableTimeTurnOnDelay2/Constant1'/Constant'
                                         */
                    rtb_EQ = 0U;
                }
                /* End of Outputs for SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/GenerateConditionsWarning/ConditionsWarningDisplay'/VariableTimeTurnOnDelay2' */
                if (((sint32)rtb_EQ) != 0) {
                    /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':47' */
                    DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_TriggerDegradation;
                    /* Entry 'TriggerDegradation': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':46' */
                    BI_drmdae_DRMDAE_SysWarning_nu = ((uint8) E_DRMDAE_SysWarnType_E_DRMDAE_DEGRTRIG);
                }
            }
            break;
        default:
            /* During 'TriggerDegradation': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':46' */
            /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':51' */
            if ((!(((sint32)rtb_NE) != 0)) || (((sint32)rtb_DataTypeConversion) != 0)) {
                /* Transition: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':29' */
                DW_drmdae_is_c14_DRMDAE_cg = DRMDAE_IN_NoWarning;
                /* Entry 'NoWarning': 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/DriverAttentionStateMachine':3' */
                BI_drmdae_DRMDAE_SysWarning_nu = ((uint8)E_DRMDAE_SysWarnType_E_DRMDAE_NOWNG);
            }
            break;
        }
    }
    /* End of Chart: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning'/DriverAttentionStateMachine' */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/Constant2'/Constant'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (sfun_setbit): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/set_bit1/Functionality'/sfun_setbit'
         */
    if (((sint32)GET_S_MCTLFC_ControllingFunction_nu()) != 0) {
        /* S-Function (sfun_setbit): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/set_bit1/Functionality'/sfun_setbit' */
        {
            uint16 temp = ((uint16)0U);
            temp = temp | u16_bit_u8( GET_S_MCTLFC_ControllingFunction_nu());
            rtb_sfun_setbit = temp;
        }
        rtb_Switch_h1 = rtb_sfun_setbit;
    } else {
        rtb_Switch_h1 = 0U;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/Constant2'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/Constant5'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ActToi_nu'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/GT/Functionality'/GT'
         *  S-Function (sfix_bitop): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CriticalSituationCheck/AND1/Functionality'/AND'
         */
    rtb_NE = (uint8)(((((sint32)GET_P_DRMDAE_AbuseFunctions_btf()) & ((sint32) rtb_Switch_h1)) > 0) && (((sint32)GET_S_LCFRCV_ActToi_nu()) != 0));
    /* DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/OR/Functionality'/OR'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/AND1/Functionality'/AND'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/NOT/Functionality'/NOT'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring'/Unit_Delay1'
         */
    rtb_DataTypeConversion = (uint8)(((!(((sint32)rtb_Switch_l) != 0)) && (((sint32)rtb_NE) != 0)) || (((sint32)DW_drmdae_Unit_Delay1_DSTATE) != 0));
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/180sTimer/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/180sTimer/Constant2'/Constant'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/180sTimer'/Unit Delay1'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum = 0.0F;
    } else {
        rtb_Sum = DW_drmdae_UnitDelay1_DSTATE;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/180sTimer/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/180sTimer/Add1/Functionality'/Sum' */
    rtb_Sum += rtb_Switch;
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/RSFLIPFLOP/Functionality'/Constant'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/OR2/Functionality'/OR'
         *  Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions'/Unit_Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling'/Unit_Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1'/Unit_Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1'/Unit_Delay'
         */
    if (((((sint32)DW_drmdae_Unit_Delay_DSTATE_ca) != 0) && (!(((sint32)rtb_NE) != 0))) || ((((sint32)DW_drmdae_Unit_Delay_DSTATE_l) != 0) && (!(((sint32) rtb_Switch_l) != 0)))) {
        rtb_Switch_j = 0U;
    } else {
        /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1'/fcg' incorporates:
                 *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality'/Comparison'
                 */
        if ((!(((sint32)DW_drmdae_Unit_Delay_DSTATE_j) != 0)) && (((sint32)rtb_NE) != 0)) {
            /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/RSFLIPFLOP/Functionality'/Constant1'
                         */
            rtb_Switch_j = 1U;
        } else {
            rtb_Switch_j = DW_drmdae_Unit_Delay_DSTATE_d;
        }
        /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1'/fcg' */
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/RSFLIPFLOP/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/AND3/Functionality'/AND'
         */
    rtb_Switch_m = (uint8)((((sint32)rtb_NE) != 0) && (((sint32)rtb_Switch_l) != 0));
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/AND2/Functionality'/AND'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising'/Unit_Delay'
         */
    rtb_Switch_h4 = (uint8)((((sint32)rtb_Switch_j) != 0) && ((!(((sint32) DW_drmdae_Unit_Delay_DSTATE_e) != 0)) && (((sint32)rtb_Switch_m) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/RSFLIPFLOP/Functionality'/Constant'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator'/Unit_Delay'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling'/Unit_Delay'
         */
    if ((((sint32)DW_drmdae_Unit_Delay_DSTATE_k) != 0) && (!(((sint32)rtb_Switch_h4) != 0))) {
        rtb_EQ = 0U;
    } else if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_EQ = 1U;
    } else {
        rtb_EQ = DW_drmdae_Unit_Delay_DSTATE_jm;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/RSFLIPFLOP/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING'/fcg' */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Constant2'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Constant3'/Constant'
         *  Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter'/Unit Delay1'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_f = 0U;
        rtb_Switch_eq = GET_P_DRMDAE_Abuse1stDuration_sec();
    } else {
        rtb_Switch_f = DW_drmdae_UnitDelay2_DSTATE;
        rtb_Switch_eq = DW_drmdae_UnitDelay1_DSTATE_o;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Add2/Functionality'/Sum' incorporates:
         *  Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Switch6/Functionality'/Switch'
         */
    rtb_Switch_f = u8_u32(((uint32)(((sint32)rtb_Switch_h4) != 0)) + ((uint32) ((sint32)rtb_Switch_f)));
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Constant1'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Constant4'/Constant'
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Constant6'/Constant'
         *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/GE/Functionality'/GE'
         */
    if ((((sint32)rtb_Switch_h4) != 0) && (((sint32)rtb_Switch_f) >= ((sint32) GET_P_DRMDAE_1stIncCycle_nu()))) {
        rtb_Sum_hi = GET_P_DRMDAE_IncNextWarning_sec();
    } else {
        rtb_Sum_hi = 0.0F;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter/Add1/Functionality'/Sum' */
    rtb_Sum_hi += rtb_Switch_eq;
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Switch/Functionality'/Switch' incorporates:
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Add2/Functionality'/Sum'
         *  Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer'/Unit Delay1'
         */
    if (((sint32)rtb_Switch_h4) != 0) {
        rtb_Switch_eq = rtb_Switch + rtb_Sum_hi;
    } else if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Constant2'/Constant'
                 */
        rtb_Switch_eq = 0.0F;
    } else {
        rtb_Switch_eq = DW_drmdae_UnitDelay1_DSTATE_g;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/from_data_definition4'/state_source'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/CalculateSystemWarning/Equality2/Functionality'/EQ'
         */
    if (((sint32)rtb_Switch_c) != 0) {
        rtb_Switch_c = (uint8)(((sint32)((uint8) E_DRMDAE_SysWarnType_E_DRMDAE_DEGRTRIG)) == ((sint32) rtb_DataTypeConversion_ft));
    } else {
        rtb_Switch_c = rtb_Switch_l;
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch1'/copy1' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Constant2'/Constant'
         */
    SET_S_DRMDAE_DrvAttentionConf_perc(100);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch10'/copy1' */
    SET_D_DRMDAE_SpeedOk_bool(rtb_GT);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch11'/copy1' */
    SET_D_DRMDAE_CriticalEventsNo_nu(rtb_Switch_f);
    /* Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Switch/Functionality'/Switch' */
    if (((sint32)rtb_Switch_c) != 0) {
        /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch2'/copy1' incorporates:
                 *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Constant1'/Constant'
                 */
        SET_S_DRMDAE_DrvAttention_perc(-100.0F);
    } else {
        /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch2'/copy1' incorporates:
                 *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Constant2'/Constant'
                 */
        SET_S_DRMDAE_DrvAttention_perc(100.0F);
    }
    /* End of Switch: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/SignalMapping/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch3'/copy1' */
    SET_S_DRMDAE_SysWarning_nu(BI_drmdae_DRMDAE_SysWarning_nu);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch4'/copy1' incorporates:
                                                            *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Constant3'/Constant'
                                                            *  DataTypeConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Logical Operator/Functionality'/Data Type Conversion'
                                                            *  Logic: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Logical Operator/Functionality'/OR'
                                                            *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Relational Operator8/Functionality'/GT'
                                                            */
    SET_S_DRMDAE_AbuseWarning_bool((uint8)((((sint32)rtb_Switch_h4) != 0) || (rtb_Switch_eq > 1.0E-5F)));
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch5'/copy1' */
    SET_D_DRMDAE_AbuseWarnDuration_sec(rtb_Sum_hi);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch6'/copy1' */
    SET_D_DRMDAE_HoffTrigger_nu(rtb_Switch_h4);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch7'/copy1' */
    SET_D_DRMDAE_ElapsedTime_sec(rtb_Sum);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch8'/copy1' */
    SET_D_DRMDAE_ResetWarnCnt_nu(rtb_EQ);
    /* SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/branch9'/copy1' */
    SET_D_DRMDAE_ActToi_nu(rtb_NE);
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/VelocityCheck'/Unit_Delay' */
    DW_drmdae_Unit_Delay_DSTATE_c = rtb_GT;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_VehSync4LCO_us'
         */
    DW_drmdae_Unit_Delay_DSTATE = GET_S_LCFRCV_VehSync4LCO_us();
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring'/Unit_Delay1' incorporates:
         *  Constant: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/Constant2'/Constant'
         *  RelationalOperator: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/GT/Functionality'/GT'
         */
    DW_drmdae_Unit_Delay1_DSTATE = (uint8)(rtb_Sum > GET_P_DRMDAE_ConsecIntervTimer_sec());
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/180sTimer'/Unit Delay1' */
    DW_drmdae_UnitDelay1_DSTATE = rtb_Sum;
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_drmdae_Unit_Delay_DSTATE_ca = rtb_NE;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_drmdae_Unit_Delay_DSTATE_l = rtb_Switch_l;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeFalling1/EDGEFALLING'/fcg' */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_drmdae_Unit_Delay_DSTATE_j = rtb_NE;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising1/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions'/Unit_Delay' */
    DW_drmdae_Unit_Delay_DSTATE_d = rtb_Switch_j;
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_drmdae_Unit_Delay_DSTATE_e = rtb_Switch_m;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/TriggerConditions/EdgeRising/EDGERISING1'/fcg' */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_drmdae_Unit_Delay_DSTATE_k = rtb_Switch_h4;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator/EdgeFalling/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/ResetGenerator'/Unit_Delay' */
    DW_drmdae_Unit_Delay_DSTATE_jm = rtb_EQ;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter'/Unit Delay1' */
    DW_drmdae_UnitDelay1_DSTATE_o = rtb_Sum_hi;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/WarningDurationCounter'/Unit Delay2' */
    DW_drmdae_UnitDelay2_DSTATE = rtb_Switch_f;
    /* Update for UnitDelay: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer'/Unit Delay1' incorporates:
         *  Sum: 'sda:DRMDAE/DRMDAE/DRMDAE_VehProcess/OPM/M_DRMDAE/DriverAbuseMonitoring/FollowUpTimer/Add1/Functionality'/Sum'
         */
    DW_drmdae_UnitDelay1_DSTATE_g = rtb_Switch_eq - rtb_Switch;
}
#include "Pse_DRMDAE.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
