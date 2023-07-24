/**************************************************************************
COPYRIGHT (C) $Date: 2020/06/24 07:23:22CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/LDPSA/DPLSMI_SEN/DPLSMI/i/project.pj $
$Log: DPLSMI.c  $
Revision 1.4.1.3.1.1 2020/06/24 07:23:22CEST Iordachescu, Roxana03 (uidq9891) 
automatically created
File          : DPLSMI
Generated on  : Tue 23.06.2020 at 15:07:48 (UTC+01:00)
MD5           : [821848370  1514256860  2573952706  1966901796 0](DPLSMI)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
ASIL class    : QM
Matlab version: 9.1.0.1012177 (R2016b) Update 7
SDA version   : 10.0
Hot fixes     : SDA-Core: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,105,106,107,108,109,110,111,112
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "DPLSMI.h"
#include "DPLSMI_private.h"
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
/* Named constants for Chart: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI'/StateMachineLDP' */
#define DPLSMI_IN_ACTIVE               ((uint8)1U)
#define DPLSMI_IN_DISABLED             ((uint8)2U)
#define DPLSMI_IN_ERROR                ((uint8)1U)
#define DPLSMI_IN_NOT_PRESENT          ((uint8)2U)
#define DPLSMI_IN_NO_ACTIVE_CHILD      ((uint8)0U)
#define DPLSMI_IN_PASSIVE              ((uint8)3U)
#define DPLSMI_IN_PRESENT              ((uint8)3U)
#define DPLSMI_IN_RAMPOUT              ((uint8)4U)
#define DPLSMI_IN_REQUEST              ((uint8)5U)
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
#define DPLSMI_START_SEC_DATA_8
#include "DPLSMI_MemMap.h"
static uint8 BI_dplsmi_SysState_nu;
/* 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI'/StateMachineLDP' */
static uint8 DW_dplsmi_Unit_Delay_DSTATE_n;
static uint8 DW_dplsmi_Unit_Delay_DSTATE_j;
static uint8 DW_dplsmi_Unit_Delay_DSTATE_b;
static uint8 DW_dplsmi_Unit_Delay_DSTATE_d;
static uint8 DW_dplsmi_Template_DSTATE;
static uint8 DW_dplsmi_Unit_Delay1_DSTATE;
static uint8 DW_dplsmi_UnitDelay5_DSTATE;
static uint8 DW_dplsmi_Unit_Delay4_DSTATE;
static uint8 DW_dplsmi_Unit_Delay1_DSTATE_d;
static uint8 DW_dplsmi_Template_DSTATE_d;
static uint8 DW_dplsmi_Template1_DSTATE;
static uint8 DW_dplsmi_Unit_Delay1_DSTATE_a;
static uint8 DW_dplsmi_Template_DSTATE_j;
static uint8 DW_dplsmi_Template1_DSTATE_a;
static uint8 DW_dplsmi_is_active_c5_DPLSMI_cg;
static uint8 DW_dplsmi_is_c5_DPLSMI_cg;
static uint8 DW_dplsmi_is_PRESENT;
#define DPLSMI_STOP_SEC_DATA_8
#include "DPLSMI_MemMap.h"
#define DPLSMI_START_SEC_DATA_32
#include "DPLSMI_MemMap.h"
static float32 DW_dplsmi_UnitDelay1_DSTATE;
static float32 DW_dplsmi_Unit_Delay2_DSTATE;
static float32 DW_dplsmi_Unit_Delay_DSTATE;
static float32 DW_dplsmi_UnitDelay1_DSTATE_n;
static float32 DW_dplsmi_Unit_Delay2_DSTATE_g;
static float32 DW_dplsmi_Unit_Delay_DSTATE_f;
static float32 DW_dplsmi_Unit_Delay_DSTATE_o;
static float32 DW_dplsmi_Unit_Delay_DSTATE_m;
static float32 DW_dplsmi_UnitDelay1_DSTATE_nj;
static float32 DW_dplsmi_Unit_Delay3_DSTATE;
static float32 DW_dplsmi_Unit_Delay_DSTATE_a;
#define DPLSMI_STOP_SEC_DATA_32
#include "DPLSMI_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPLSMI/DPLSMI/INI'/DPLSMI_SenReset'
 * Block description for: 'sda:DPLSMI/DPLSMI/INI'/DPLSMI_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLSMI_SenReset
#include "Pse_DPLSMI.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLSMI_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant1'/Constant' */
    SET_S_DPLSMI_FunctionAborted_bool(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant10'/Constant' */
    SET_D_DPLSMI_DlcLeThreshold_met(0.0F);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant11'/Constant' */
    SET_D_DPLSMI_TlcRiThreshold_sec(0.0F);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant12'/Constant' */
    SET_S_DPLSMI_ReadyToTrigger_bool(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant13'/Constant' */
    SET_D_DPLSMI_TlcLeThreshold_sec(0.0F);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant2'/Constant' */
    SET_D_DPLSMI_DlcRiThreshold_met(0.0F);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant3'/Constant' */
    SET_D_DPLSMI_SysStateLDP_btf(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant4'/Constant' */
    SET_D_DPLSMI_TriggerRi_btf(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant5'/Constant' */
    SET_D_DPLSMI_StrongReady_btf(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant6'/Constant' */
    SET_D_DPLSMI_Cancel_btf(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant7'/Constant' */
    SET_D_DPLSMI_WeakReady_btf(0U);
    /* Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/Constant8'/Constant' */
    SET_D_DPLSMI_TriggerLe_btf(0U);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition1'/Signal Conversion3' incorporates:
                                            *  Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition1'/state_source'
                                            */
    SET_S_DPLSMI_SysStateLDP_nu(((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition2'/Signal Conversion3' incorporates:
                                                           *  Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition2'/state_source'
                                                           */
    SET_S_DPLSMI_DangerousSide_nu(((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition3'/Signal Conversion3' incorporates:
                                                            *  Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition3'/state_source'
                                                            */
    SET_S_DPLSMI_SysStateLDPLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition4'/Signal Conversion3' incorporates:
                                                            *  Constant: 'sda:DPLSMI/DPLSMI/INI/DPLSMI_SenReset/from_data_definition4'/state_source'
                                                            */
    SET_S_DPLSMI_SysStateLDPRi_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
}
#include "Pse_DPLSMI.h"
/*
 * Output and update for function-call system: 'sda:DPLSMI/DPLSMI'/DPLSMI_SenProcess'
 * Block description for: 'sda:DPLSMI/DPLSMI'/DPLSMI_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLSMI_SenProcess
#include "Pse_DPLSMI.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLSMI_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_UnaryMinus;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_g0;
    float32 rtb_Abs_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_df;
    float32 rtb_ip_lookup_fxpt_sfun_7_dg;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_Abs_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_bg;
    float32 rtb_Abs_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_dy;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Abs_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_Abs_ou;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_Abs_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_iz;
    float32 rtb_Abs_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_jm;
    float32 rtb_ip_lookup_fxpt_sfun_7_mg;
    float32 rtb_ip_lookup_fxpt_sfun_7_ee;
    float32 rtb_ip_lookup_fxpt_sfun_7_eu;
    float32 rtb_ip_lookup_fxpt_sfun_7_dyj;
    float32 rtb_ip_lookup_fxpt_sfun_7_mv;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate_j[8];
    uint8 rtb_VectorConcatenate_e[8];
    uint8 rtb_VectorConcatenate_a[8];
    uint8 rtb_VectorConcatenate_p[8];
    uint8 rtb_VectorConcatenate_n[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_h;
    uint8 rtb_Switch_f4;
    uint8 rtb_LT_a;
    float32 rtb_Mul;
    uint8 rtb_RelationalOperator1_f;
    uint8 rtb_LT_d;
    uint8 rtb_DataTypeConversion_en;
    uint8 rtb_UnitDelay1_c;
    uint8 rtb_RelationalOperator1_a;
    uint8 rtb_EQ_hv;
    uint8 rtb_EQ_g1;
    uint8 rtb_LogicalOperator_p;
    uint8 rtb_Switch_hy;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_GT;
    uint8 rtb_GT_h;
    uint8 rtb_DataTypeConversion_cz;
    uint8 rtb_GT_l0;
    uint8 rtb_LT_j;
    uint8 rtb_DataTypeConversion_lw;
    uint8 rtb_EQ_p5;
    uint8 rtb_EQ_hk;
    uint8 rtb_EQ_k0;
    uint8 rtb_LogicalOperator_e;
    uint8 rtb_LT_lw;
    uint8 rtb_EQ_es;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_mh;
    uint8 rtb_EQ_ge;
    uint8 rtb_EQ_fr;
    uint8 rtb_EQ_c;
    uint8 rtb_EQ_bn;
    uint8 rtb_EQ_jw;
    uint8 rtb_DataTypeConversion_b;
    uint8 rtb_DataTypeConversion_ox;
    uint8 rtb_DataTypeConversion_j;
    uint8 rtb_DataTypeConversion_d1;
    uint8 rtb_EQ_ps;
    uint8 rtb_EQ_ft;
    uint8 rtb_EQ_kn;
    uint8 rtb_EQ_od;
    uint8 rtb_EQ_hp;
    uint8 rtb_EQ_d2;
    uint8 rtb_EQ_nc;
    uint8 rtb_UnitDelay2;
    uint8 rtb_EQ_bz;
    uint8 rtb_DataTypeConversion_d;
    uint8 rtb_DataTypeConversion_n;
    uint8 rtb_DataTypeConversion_i;
    uint8 rtb_EQ_id;
    uint8 rtb_NE_gg;
    uint8 rtb_NE_dp;
    uint8 rtb_DataTypeConversion_pr;
    uint8 rtb_GT_mp;
    uint8 rtb_NE_my;
    uint8 rtb_NE_do;
    uint8 rtb_NE_hb;
    uint8 rtb_NE_b4;
    uint8 rtb_DataTypeConversion_eh;
    uint8 rtb_LogicalOperator_kw;
    uint8 rtb_Switch_gh;
    uint8 rtb_DataTypeConversion_fo;
    uint8 rtb_Switch_aw;
    uint8 rtb_DataTypeConversion_ae;
    uint8 rtb_DataTypeConversion_a;
    uint8 rtb_Switch_ks;
    float32 rtb_Switch;
    float32 rtb_Switch_pv;
    float32 rtb_Switch_jm;
    float32 rtb_Switch2_m;
    float32 rtb_Switch2_l;
    float32 rtb_Switch2_i2;
    float32 rtb_Switch_fc;
    float32 rtb_Switch2_lt;
    float32 rtb_Switch_ba;
    uint8 LogicalOperator_c;
    uint8 LogicalOperator_k;
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LDPSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LDPSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LDPSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDPSwitch_bool'
         */
    if (((sint32)GET_P_DPLSMI_LDPSwitchEnable_bool()) != 0) {
        rtb_Switch_f4 = GET_S_LCFRCV_LDPSwitch_bool();
    } else {
        rtb_Switch_f4 = GET_P_DPLSMI_LDPSwitch_bool();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LDPSwitch/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_Switch_f4;
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDPDlcLimitLe_met'
         */
    if (((sint32)GET_P_LDP_DlcLimitCustom_bool()) != 0) {
        rtb_Switch_jm = GET_S_CUSTOM_LDPDlcLimitLe_met();
    } else {
        rtb_Switch_jm = GET_P_DPLSMI_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/LT/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         */
    rtb_LT_a = (uint8)(GET_S_DPLSIA_DlcLeLDP_met() < rtb_Switch_jm);
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDPMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator8/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch7/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_LDPMode_nu()) == 3) {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_mg = F32_PTR_IP1D(GETA_Y_DPLSMI_VXMD3TrigDlc_met (), &x_dps);
        }
        rtb_Switch_pv = rtb_ip_lookup_fxpt_sfun_7_mg;
    } else if (((sint32)GET_S_LCFRCV_LDPMode_nu()) == 2) {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ee = F32_PTR_IP1D(GETA_Y_DPLSMI_VXMD2TrigDlc_met (), &x_dps);
        }
        rtb_Switch_pv = rtb_ip_lookup_fxpt_sfun_7_ee;
    } else {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_eu = F32_PTR_IP1D(GETA_Y_DPLSMI_VXMD1TrigDlc_met (), &x_dps);
        }
        rtb_Switch_pv = rtb_ip_lookup_fxpt_sfun_7_eu;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' */
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPLSMI_LWTrigDlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul = rtb_Switch_pv * rtb_ip_lookup_fxpt_sfun_7;
    /* UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Neg4/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_DPLSIA_VelLatLeLDP_mps'
         */
    rtb_UnaryMinus = -GET_S_DPLSIA_VelLatLeLDP_mps();
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LaneBoundaryInterface/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LaneBoundaryInterface/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDPOn_bool()) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LaneBoundaryInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDPDlcTrgLe_met'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
         *  Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/EQ1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
         */
    if (((sint32)GET_P_LDP_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_fc = GET_S_CUSTOM_LDPDlcTrgLe_met();
    } else {
        if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_i = f32_abs_f32(rtb_Switch);
            /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_i, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_iz = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_fc = -rtb_ip_lookup_fxpt_sfun_7_iz;
        } else if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_e = f32_abs_f32(rtb_Switch);
            /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_e, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_jm = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_fc = rtb_ip_lookup_fxpt_sfun_7_jm;
        } else {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant8'/Constant'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_fc = 0.0F;
        }
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPLSMI_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_fc += rtb_Mul * rtb_ip_lookup_fxpt_sfun_7_m;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDPMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_LDPMode_nu()) == 3) {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_df = F32_PTR_IP1D(GETA_Y_DPLSMI_VXMD3TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_pv = rtb_ip_lookup_fxpt_sfun_7_df;
    } else if (((sint32)GET_S_LCFRCV_LDPMode_nu()) == 2) {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_dg = F32_PTR_IP1D(GETA_Y_DPLSMI_VXMD2TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_pv = rtb_ip_lookup_fxpt_sfun_7_dg;
    } else {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D(GETA_Y_DPLSMI_VXMD1TrigTlc_sec(), &x_dps);
        }
        rtb_Switch_pv = rtb_ip_lookup_fxpt_sfun_7_n;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' */
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_DPLSMI_LWTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Divide2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_pv *= rtb_ip_lookup_fxpt_sfun_7_b;
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_DPLSMI_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/EQ1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
        /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_l = f32_abs_f32(rtb_Switch);
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_l, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_bg = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch = -rtb_ip_lookup_fxpt_sfun_7_bg;
    } else if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
        /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_j = f32_abs_f32(rtb_Switch);
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_j, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_dy = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch = rtb_ip_lookup_fxpt_sfun_7_dy;
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant8'/Constant'
                 */
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Divide5/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch += rtb_Switch_pv * rtb_ip_lookup_fxpt_sfun_7_g;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_TlcLeLDP_sec'
         */
    rtb_LT_d = (uint8)(GET_S_DPLSIA_TlcLeLDP_sec() < rtb_Switch);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator5/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND2/Functionality'/AND'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1'
         */
    rtb_DataTypeConversion_en = (uint8)((((((sint32) GET_P_DPLSMI_TriggerCondEnable_btm()) & 1) != 0) && (GET_S_DPLSIA_DlcLeLDP_met() < rtb_Switch_fc)) || ((((((sint32) GET_P_DPLSMI_TriggerCondEnable_btm()) & 2) != 0) && (GET_S_DPLSIA_DlcLeLDP_met() < GET_P_DPLSMI_TlcDistanceMin_met())) && ((DW_dplsmi_UnitDelay1_DSTATE <= 0.0F) && (((sint32)rtb_LT_d) != 0))));
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant9'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDP_bool'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND4/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND9/Functionality'/AND'
         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPLSMI_SafeSituationState_btm()) & 1) != 0) && (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPLSMI_SafeSituationState_btm()) & 2) != 0) && (((sint32) BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPLSMI_SafeSituationState_btm()) & 4) != 0) && (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPLSMI_SafeSituationState_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPLSMI_SafeSituationState_btm()) & 16) != 0) && (!(((sint32) GET_S_DPLSIA_LnBndLeValidLDP_bool()) != 0)))) {
        rtb_Switch_hy = 0U;
    } else if (GET_S_DPLSIA_DlcLeLDP_met() > (rtb_Switch_fc + GET_P_DPLSMI_SafeSituationOffset_met())) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_hy = 1U;
    } else {
        rtb_Switch_hy = DW_dplsmi_Unit_Delay_DSTATE_n;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2'
         */
    rtb_LogicalOperator_p = (uint8)((DW_dplsmi_Unit_Delay2_DSTATE <= 0.0F) && (((sint32)rtb_Switch_hy) != 0));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDPLe_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND5/Functionality'/AND'
         */
    rtb_EQ_g1 = (uint8)((((sint32)GET_S_DPLSIA_SideCondLDPLe_btf()) & ((sint32) GET_P_DPLSMI_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND3/Functionality'/AND'
         */
    rtb_EQ_hv = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMI_FctCustomTrgLe_btm())) == 0);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND8/Functionality'/AND'
         */
    rtb_DataTypeConversion = (uint8)(((((((sint32)rtb_LT_a) != 0) && (((sint32) rtb_DataTypeConversion_en) != 0)) && (((sint32)rtb_LogicalOperator_p) != 0)) && (((sint32)rtb_EQ_g1) != 0)) && (((sint32)rtb_EQ_hv) != 0));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         */
    rtb_GT = (uint8)(GET_S_DPLSIA_DlcLeLDP_met() > GET_P_DPLSMI_DlcLimitMin_met());
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_c = (uint8)((!(((sint32)DW_dplsmi_Unit_Delay_DSTATE_j) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant6'/Constant'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit_Delay'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_lt = DW_dplsmi_Unit_Delay_DSTATE;
    } else {
        rtb_Switch2_lt = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter5'/Constant'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_c) != 0) {
        rtb_Switch2_lt = GET_P_DPLSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_lt > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_lt -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_lt = 0.0F;
            }
            /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_f = (uint8)(rtb_Switch2_lt > 0.0F);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant9'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND4/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_cz = (uint8)(((((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMI_FctCustomBSMLe_btm())) != 0) && ((((sint32) GET_P_DPLSMI_TriggerCondEnable_btm()) & 4) != 0)) && (((sint32) rtb_DataTypeConversion) != 0)) || ((((sint32)rtb_GT) != 0) && (((sint32) rtb_RelationalOperator1_f) != 0)));
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDPDlcLimitRi_met'
         */
    if (((sint32)GET_P_LDP_DlcLimitCustom_bool()) != 0) {
        rtb_Switch_jm = GET_S_CUSTOM_LDPDlcLimitRi_met();
    } else {
        rtb_Switch_jm = GET_P_DPLSMI_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator7/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg4/Functionality'/Unary Minus'
         */
    rtb_GT_h = (uint8)(GET_S_DPLSIA_DlcRiLDP_met() > (-rtb_Switch_jm));
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LaneBoundaryInterface/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LaneBoundaryInterface/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDPOn_bool()) != 0) {
        rtb_Switch_jm = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_jm = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/LaneBoundaryInterface/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDPDlcTrgRi_met'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDP_mps'
         *  Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/EQ3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
         */
    if (((sint32)GET_P_LDP_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_ba = GET_S_CUSTOM_LDPDlcTrgRi_met();
    } else {
        if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_o = f32_abs_f32(rtb_Switch_jm);
            /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_o, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_ba = -rtb_ip_lookup_fxpt_sfun_7_f;
        } else if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_ou = f32_abs_f32(rtb_Switch_jm);
            /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_ou, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_ba = rtb_ip_lookup_fxpt_sfun_7_k;
        } else {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant9'/Constant'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_ba = 0.0F;
        }
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPLSIA_VelLatRiLDP_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_DPLSMI_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_ba += rtb_Mul * rtb_ip_lookup_fxpt_sfun_7_l;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' */
    /* UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus' */
    rtb_Mul = -rtb_Switch_ba;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator1/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus'
         */
    rtb_GT_l0 = (uint8)(GET_S_DPLSIA_DlcRiLDP_met() > (-rtb_Switch_ba));
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPLSIA_VelLatRiLDP_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_DPLSMI_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/EQ3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Neg2/Functionality'/Unary Minus'
         */
    if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
        /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs = f32_abs_f32(rtb_Switch_jm);
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_g0 = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_ba = -rtb_ip_lookup_fxpt_sfun_7_g0;
    } else if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
        /* Abs: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_f = f32_abs_f32(rtb_Switch_jm);
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_f, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPLSMI_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_ba = rtb_ip_lookup_fxpt_sfun_7_j;
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant9'/Constant'
                 */
        rtb_Switch_ba = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDP_mps'
         *  Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Divide6/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_ba += rtb_Switch_pv * rtb_ip_lookup_fxpt_sfun_7_c;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator3/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_TlcRiLDP_sec'
         */
    rtb_LT_j = (uint8)(GET_S_DPLSIA_TlcRiLDP_sec() < rtb_Switch_ba);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND4/Functionality'/AND'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg3/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1'
         */
    rtb_DataTypeConversion_lw = (uint8)((((((sint32) GET_P_DPLSMI_TriggerCondEnable_btm()) & 1) != 0) && (((sint32)rtb_GT_l0) != 0)) || ((((((sint32)GET_P_DPLSMI_TriggerCondEnable_btm()) & 2) != 0) && (GET_S_DPLSIA_DlcRiLDP_met() > (-GET_P_DPLSMI_TlcDistanceMin_met()))) && ((DW_dplsmi_UnitDelay1_DSTATE_n <= 0.0F) && (((sint32)rtb_LT_j) != 0))));
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant9'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDP_bool'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND4/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND9/Functionality'/AND'
         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPLSMI_SafeSituationState_btm()) & 1) != 0) && (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPLSMI_SafeSituationState_btm()) & 2) != 0) && (((sint32) BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPLSMI_SafeSituationState_btm()) & 4) != 0) && (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPLSMI_SafeSituationState_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPLSMI_SafeSituationState_btm()) & 16) != 0) && (!(((sint32) GET_S_DPLSIA_LnBndRiValidLDP_bool()) != 0)))) {
        rtb_UnitDelay1_c = 0U;
    } else if (GET_S_DPLSIA_DlcRiLDP_met() < (rtb_Mul - GET_P_DPLSMI_SafeSituationOffset_met())) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_UnitDelay1_c = 1U;
    } else {
        rtb_UnitDelay1_c = DW_dplsmi_Unit_Delay_DSTATE_b;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2'
         */
    rtb_LogicalOperator_e = (uint8)((DW_dplsmi_Unit_Delay2_DSTATE_g <= 0.0F) && (((sint32)rtb_UnitDelay1_c) != 0));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDPRi_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND5/Functionality'/AND'
         */
    rtb_EQ_k0 = (uint8)((((sint32)GET_S_DPLSIA_SideCondLDPRi_btf()) & ((sint32) GET_P_DPLSMI_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND1/Functionality'/AND'
         */
    rtb_EQ_hk = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMI_FctCustomTrgRi_btm())) == 0);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator1/Functionality'/AND'
         */
    rtb_GT_l0 = (uint8)(((((((sint32)rtb_GT_h) != 0) && (((sint32) rtb_DataTypeConversion_lw) != 0)) && (((sint32)rtb_LogicalOperator_e) != 0)) && (((sint32)rtb_EQ_k0) != 0)) && (((sint32)rtb_EQ_hk) != 0));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg1/Functionality'/Unary Minus'
         */
    rtb_LT_lw = (uint8)(GET_S_DPLSIA_DlcRiLDP_met() < (-GET_P_DPLSMI_DlcLimitMin_met()));
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_k = (uint8)((!(((sint32)DW_dplsmi_Unit_Delay_DSTATE_d) != 0)) && (((sint32)rtb_GT_l0) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant6'/Constant'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit_Delay'
         */
    if (((sint32)rtb_LT_lw) >= 1) {
        rtb_Switch_pv = DW_dplsmi_Unit_Delay_DSTATE_f;
    } else {
        rtb_Switch_pv = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter5'/Constant'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_k) != 0) {
        rtb_Switch_pv = GET_P_DPLSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_lw) != 0) {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch_pv > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch_pv -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch_pv = 0.0F;
            }
            /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_a = (uint8)(rtb_Switch_pv > 0.0F);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant9'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND2/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_o = (uint8)(((((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMI_FctCustomBSMRi_btm())) != 0) && ((((sint32) GET_P_DPLSMI_TriggerCondEnable_btm()) & 4) != 0)) && (((sint32)rtb_GT_l0) != 0)) || ((((sint32)rtb_LT_lw) != 0) && (((sint32)rtb_RelationalOperator1_a) != 0)));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_mh = (uint8)((((sint32)rtb_DataTypeConversion_cz) != 0) || (((sint32)rtb_DataTypeConversion_o) != 0));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_mh;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND1/Functionality'/AND'
         */
    rtb_EQ_es = (uint8)((((sint32)GET_S_DPLSIA_SpecificLDP_btf()) & ((sint32) GET_P_DPLSMI_StrgRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND3/Functionality'/AND'
         */
    rtb_EQ_p5 = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMI_StrgRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter12'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter13'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND6/Functionality'/AND'
         */
    rtb_EQ_ge = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPLSMI_StrgRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND2/Functionality'/AND'
         */
    rtb_EQ_fr = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMI_StrgRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND4/Functionality'/AND'
         */
    rtb_EQ_c = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPLSMI_StrgRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND5/Functionality'/AND'
         */
    rtb_EQ_bn = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPLSMI_StrgRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter14'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Application Parameter15'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/AND7/Functionality'/AND'
         */
    rtb_EQ_jw = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMI_StrgRdyFctCustom_btm())) == 0);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter12'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter14'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDP_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Abort/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_b = (uint8)((((((((((sint32) GET_S_DPLSIA_SpecificLDP_btf()) & ((sint32)GET_P_DPLSMI_AbortSpecific_btm())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMI_AbortVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPLSMI_AbortDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMI_AbortFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPLSMI_AbortFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPLSMI_AbortFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMI_AbortFctCustom_btm())) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ox = (uint8)(!(((sint32)rtb_DataTypeConversion_b) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_j = (uint8)((((((((((sint32)rtb_EQ_es) != 0) && (((sint32)rtb_EQ_p5) != 0)) && (((sint32)rtb_EQ_ge) != 0)) && (((sint32) rtb_EQ_fr) != 0)) && (((sint32)rtb_EQ_c) != 0)) && (((sint32)rtb_EQ_bn) != 0)) && (((sint32)rtb_EQ_jw) != 0)) && (((sint32)rtb_DataTypeConversion_ox) != 0));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion_j;
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Not1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter12'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter14'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDP_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Not1/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Suppresion/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_d1 = (uint8)(!((((((((((sint32) GET_S_DPLSIA_SpecificLDP_btf()) & ((sint32)GET_P_DPLSMI_SuppressSpecific_btm ())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMI_SuppressVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPLSMI_SuppressDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMI_SuppressFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPLSMI_SuppressFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPLSMI_SuppressFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMI_SuppressFctCustom_btm())) != 0)));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND1/Functionality'/AND'
         */
    rtb_EQ_ps = (uint8)((((sint32)GET_S_DPLSIA_SpecificLDP_btf()) & ((sint32) GET_P_DPLSMI_WeakRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND3/Functionality'/AND'
         */
    rtb_EQ_ft = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMI_WeakRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter12'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND6/Functionality'/AND'
         */
    rtb_EQ_kn = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPLSMI_WeakRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND2/Functionality'/AND'
         */
    rtb_EQ_od = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMI_WeakRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND4/Functionality'/AND'
         */
    rtb_EQ_hp = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPLSMI_WeakRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND5/Functionality'/AND'
         */
    rtb_EQ_d2 = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPLSMI_WeakRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/AND7/Functionality'/AND'
         */
    rtb_EQ_nc = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMI_WeakRdyFctCustom_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/RelatOperator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/from_data_definition5'/state_source'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady'/Unit Delay2'
         */
    rtb_EQ_bz = (uint8)(((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/P_LDPSA_BlockingTimeDuration_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime'/Template'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
         */
    if ((((sint32)DW_dplsmi_Template_DSTATE) != 0) && (!(((sint32)rtb_EQ_bz) != 0))) {
        rtb_Switch_jm = GET_P_DPLSMI_BlockingTimeDuration_sec();
    } else if (DW_dplsmi_Unit_Delay_DSTATE_o > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
                 */
        rtb_Switch_jm = DW_dplsmi_Unit_Delay_DSTATE_o - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch_jm = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Not/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/OR/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/OR1/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Not/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady'/Unit Delay2'
         */
    rtb_DataTypeConversion_d = (uint8)(!(((((sint32)BI_dplsmi_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) rtb_EQ_bz) != 0)) || (rtb_Switch_jm > 0.0F)));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_n = (uint8)(((((((((((sint32) rtb_DataTypeConversion_d1) != 0) && (((sint32)rtb_EQ_ps) != 0)) && (((sint32) rtb_EQ_ft) != 0)) && (((sint32)rtb_EQ_kn) != 0)) && (((sint32)rtb_EQ_od) != 0)) && (((sint32)rtb_EQ_hp) != 0)) && (((sint32)rtb_EQ_d2) != 0)) && (((sint32)rtb_EQ_nc) != 0)) && (((sint32)rtb_DataTypeConversion_d) != 0));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_n;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/from_data_definition2'/state_source'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation'/Unit Delay1'
         */
    rtb_UnitDelay2 = (uint8)(((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay1'
         */
    if ((!(((sint32)DW_dplsmi_Unit_Delay1_DSTATE) != 0)) && (((sint32)rtb_UnitDelay2) != 0)) {
        rtb_Switch2_m = GET_P_DPLSMI_DegrTimeOut_sec();
    } else if (DW_dplsmi_Unit_Delay_DSTATE_m > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay'
                 */
        rtb_Switch2_m = DW_dplsmi_Unit_Delay_DSTATE_m - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_m = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' */
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/Equality1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_EQ_id = (uint8)(((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8)E_LCF_FunctionV3Type_E_LCF_LDP_nu)));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysStOffLatDMC_bool'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/AND1/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/AND2/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/NOT/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/NOT1/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_pr = (uint8)((((sint32)rtb_UnitDelay2) != 0) && (((!(rtb_Switch2_m > 0.0F)) || (!(((sint32)rtb_EQ_id) != 0))) || ((((sint32) rtb_EQ_id) != 0) && (((sint32)GET_S_LCFRCV_SysStOffLatDMC_bool()) != 0))));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_pr;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND1/Functionality'/AND'
         */
    rtb_NE_dp = (uint8)((((sint32)GET_P_DPLSMI_FinishCondEnable_btm()) & 1) == 0);
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_DPLSMI_LWHazardFinishTol_met(), &x_dps);
    }
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  Inport: '<Root>/S_DPLTTG_LeTgtTrajPosY0_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg/Functionality'/Unary Minus'
         */
    rtb_GT_mp = (uint8)(GET_S_DPLTTG_LeTgtTrajPosY0_met() > (-rtb_ip_lookup_fxpt_sfun_7_h));
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_DPLSMI_LWNoHazardFinishTol_met(), &x_dps);
    }
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_i = (uint8)((((sint32) GET_P_DPLSMI_FinishCondEnable_btm()) & 2) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND3/Functionality'/AND'
         */
    rtb_NE_do = (uint8)((((sint32)GET_P_DPLSMI_FinishCondEnable_btm()) & 4) == 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND4/Functionality'/AND'
         */
    rtb_NE_b4 = (uint8)((((sint32)GET_P_DPLSMI_FinishCondEnable_btm()) & 8) == 0);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_NoHazardFinishTol_met2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  Inport: '<Root>/S_DPLSIA_VelLatLeLDP_mps'
         *  Inport: '<Root>/S_DPLTTG_LeTgtTrajPosY0_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator4/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator5/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator9/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR1/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR2/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator11/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator14/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator15/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator2/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator5/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator6/Functionality'/GT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg1/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg4/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_eh = (uint8)(((((((sint32)DW_dplsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((sint32)rtb_NE_dp) != 0) || ((((sint32)rtb_GT_mp) != 0) && (GET_S_DPLTTG_LeTgtTrajPosY0_met() < rtb_ip_lookup_fxpt_sfun_7_i)))) && ((((sint32)rtb_DataTypeConversion_i) != 0) || ((GET_S_ABPLBP_LeLnClthHeading_rad() < GET_P_DPLSMI_NoHazardFinishHeadAng_rad()) && (GET_S_ABPLBP_LeLnClthHeading_rad() > (-GET_P_DPLSMI_HazardFinishHeadAng_rad()))))) && ((((sint32)rtb_NE_do) != 0) || ((GET_S_DPLSIA_VelLatLeLDP_mps() < GET_P_DPLSMI_NoHazardFinishVelLat_mps()) && (GET_S_DPLSIA_VelLatLeLDP_mps() > (-GET_P_DPLSMI_HazardFinishVelLat_mps()))))) && ((((sint32)rtb_NE_b4) != 0) || ((GET_S_DPLSIA_DlcLeLDP_met() > GET_P_DPLSMI_HazardFinishDlc_met()) && (GET_S_DPLSIA_DlcLeLDP_met() < GET_P_DPLSMI_NoHazardFinishDlc_met()))));
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_DPLSMI_LWHazardFinishTol_met(), &x_dps);
    }
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator7/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  Inport: '<Root>/S_DPLTTG_RiTgtTrajPosY0_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_GT_mp = (uint8)(GET_S_DPLTTG_RiTgtTrajPosY0_met() < rtb_ip_lookup_fxpt_sfun_7_e);
    /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D (GETA_Y_DPLSMI_LWNoHazardFinishTol_met(), &x_dps);
    }
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps5'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps6'/Constant'
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDP_mps'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator11/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator12/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator13/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg6/Functionality'/Unary Minus'
         */
    rtb_NE_do = (uint8)((((sint32)rtb_NE_do) != 0) || ((GET_S_DPLSIA_VelLatRiLDP_mps() > (-GET_P_DPLSMI_NoHazardFinishVelLat_mps())) && (GET_S_DPLSIA_VelLatRiLDP_mps () < GET_P_DPLSMI_HazardFinishVelLat_mps())));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_NoHazardFinishTol_met3'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator16/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator17/Functionality'/GT'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg5/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg8/Functionality'/Unary Minus'
         */
    rtb_NE_b4 = (uint8)((((sint32)rtb_NE_b4) != 0) || ((GET_S_DPLSIA_DlcRiLDP_met() < (-GET_P_DPLSMI_HazardFinishDlc_met())) && (GET_S_DPLSIA_DlcRiLDP_met() > (-GET_P_DPLSMI_NoHazardFinishDlc_met()))));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  Inport: '<Root>/S_DPLTTG_RiTgtTrajPosY0_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR3/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator10/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator8/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator9/Functionality'/GT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg3/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_NE_b4 = (uint8)(((((((sint32)DW_dplsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((((sint32) rtb_NE_dp) != 0) || ((((sint32)rtb_GT_mp) != 0) && (GET_S_DPLTTG_RiTgtTrajPosY0_met() > (-rtb_ip_lookup_fxpt_sfun_7_d))))) && ((((sint32)rtb_DataTypeConversion_i) != 0) || ((GET_S_ABPLBP_RiLnClthHeading_rad() > (-GET_P_DPLSMI_NoHazardFinishHeadAng_rad())) && (GET_S_ABPLBP_RiLnClthHeading_rad() < GET_P_DPLSMI_HazardFinishHeadAng_rad ())))) && (((sint32)rtb_NE_do) != 0)) && (((sint32)rtb_NE_b4) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_eh = (uint8)((((sint32)rtb_DataTypeConversion_eh) != 0) || (((sint32)rtb_NE_b4) != 0));
    /* Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
         */
    rtb_LogicalOperator_kw = (uint8)((DW_dplsmi_UnitDelay1_DSTATE_nj <= 0.0F) && (((sint32)rtb_DataTypeConversion_eh) != 0));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate[5] = rtb_LogicalOperator_kw;
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND1/Functionality'/AND'
         */
    rtb_NE_b4 = (uint8)((((sint32)GET_S_DPLSIA_SpecificLDP_btf()) & ((sint32) GET_P_DPLSMI_CancelSpecific_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND3/Functionality'/AND'
         */
    rtb_NE_hb = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMI_CancelVehSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ5/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter12'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND6/Functionality'/AND'
         */
    rtb_NE_do = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPLSMI_CancelDrvSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND2/Functionality'/AND'
         */
    rtb_NE_my = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMI_CancelFctStCtr_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND4/Functionality'/AND'
         */
    rtb_NE_dp = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPLSMI_CancelFctStErr_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ4/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND5/Functionality'/AND'
         */
    rtb_NE_gg = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPLSMI_CancelFctStNotAv_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator4/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Constant'/Constant'
         *  Inport: '<Root>/S_DPLSIA_VelLatLeLDP_mps'
         */
    rtb_DataTypeConversion_i = (uint8)(GET_S_DPLSIA_VelLatLeLDP_mps() > 0.0F);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met1'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator1/Functionality'/GT'
         */
    rtb_Switch_gh = (uint8)((((sint32)rtb_DataTypeConversion_i) != 0) && (GET_S_DPLSIA_DlcLeLDP_met() > GET_P_DPLSMI_NoHazardCancelDlc_met()));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_DPLTTG_LeTgtTrajPosY0_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator7/Functionality'/GT'
         */
    rtb_DataTypeConversion_i = (uint8)((((sint32)rtb_DataTypeConversion_i) != 0) && (GET_S_DPLTTG_LeTgtTrajPosY0_met() > GET_P_DPLSMI_NoHazardCancelTol_met()));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator3/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_fo = (uint8)(((GET_S_DPLSIA_DlcLeLDP_met() < (-GET_P_DPLSMI_HazardCancelTol_met())) || (((sint32)rtb_Switch_gh) != 0)) || (((sint32)rtb_DataTypeConversion_i) != 0));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator8/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Constant1'/Constant'
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDP_mps'
         */
    rtb_DataTypeConversion_i = (uint8)(GET_S_DPLSIA_VelLatRiLDP_mps() < 0.0F);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator2/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Neg2/Functionality'/Unary Minus'
         */
    rtb_Switch_aw = (uint8)((((sint32)rtb_DataTypeConversion_i) != 0) && (GET_S_DPLSIA_DlcRiLDP_met() < (-GET_P_DPLSMI_NoHazardCancelDlc_met())));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met3'/Constant'
         *  Inport: '<Root>/S_DPLTTG_RiTgtTrajPosY0_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator12/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Neg1/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_i = (uint8)((((sint32)rtb_DataTypeConversion_i) != 0) && (GET_S_DPLTTG_RiTgtTrajPosY0_met() < (-GET_P_DPLSMI_NoHazardCancelTol_met ())));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met1'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDP_met'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator9/Functionality'/GT'
         */
    rtb_DataTypeConversion_ae = (uint8)(((GET_S_DPLSIA_DlcRiLDP_met() > GET_P_DPLSMI_HazardCancelTol_met()) || (((sint32)rtb_Switch_aw) != 0)) || (((sint32)rtb_DataTypeConversion_i) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/from_data_definition2'/state_source'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator6/Functionality'/EQ'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_aw = (uint8)((((sint32)DW_dplsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32) rtb_DataTypeConversion_ae) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/from_data_definition1'/state_source'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator2/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator5/Functionality'/EQ'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_aw = (uint8)(((((sint32)DW_dplsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && (((sint32) rtb_DataTypeConversion_fo) != 0)) || (((sint32)rtb_Switch_aw) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Logical Operator12/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Constant1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Constant2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Constant3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDP_bool'
         *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDP_bool'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDPLe_btf'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDPRi_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Logical Operator12/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Logical Operator9/Functionality'/AND'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/NOT/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/NOT1/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/OR/Functionality'/OR'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/Relational Operator8/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/SideConditions/AND4/Functionality'/AND'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_gh = (uint8)(((((sint32)DW_dplsmi_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((((sint32)GET_S_DPLSIA_SideCondLDPLe_btf()) & ((sint32) GET_P_DPLSMI_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMI_FctCustomCancelLe_btm())) != 0)) || (!(((sint32)GET_S_DPLSIA_LnBndLeValidLDP_bool()) != 0)))) || ((((sint32)DW_dplsmi_UnitDelay5_DSTATE) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((((((sint32) GET_S_DPLSIA_SideCondLDPRi_btf()) & ((sint32)GET_P_DPLSMI_SideCondCancel_btm ())) != 0) || ((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMI_FctCustomCancelRi_btm())) != 0)) || (!(((sint32) GET_S_DPLSIA_LnBndRiValidLDP_bool()) != 0)))));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter15'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter16'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter17'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter18'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ7/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ8/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND8/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND9/Functionality'/AND'
         */
    rtb_DataTypeConversion_i = (uint8)(((((sint32) GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32) GET_P_DPLSMI_QuTrajPlanCancel_btm())) != 0) || ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32)GET_P_DPLSMI_QuTrajCtrCancel_btm ())) != 0));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/Relational Operator11/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/from_data_definition'/state_source'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay3'
         */
    rtb_GT_mp = (uint8)(((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDP_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Product: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4'
         */
    if ((!(((sint32)DW_dplsmi_Unit_Delay4_DSTATE) != 0)) && (((sint32)rtb_GT_mp) != 0)) {
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_LaneWidth_met */
            FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDP_met(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_dyj = F32_PTR_IP1D (GETA_Y_DPLSMI_LWContrMaxDurScal_nu(), &x_dps);
        }
        /* S-Function Block sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_mv = F32_PTR_IP1D (GETA_Y_DPLSMI_VXContrMaxDur_sec(), &x_dps);
        }
        rtb_Switch2_l = rtb_ip_lookup_fxpt_sfun_7_mv * rtb_ip_lookup_fxpt_sfun_7_dyj;
    } else if (DW_dplsmi_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
                 */
        rtb_Switch2_l = DW_dplsmi_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch2_l = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_sfun_setbit = (uint8)(!(rtb_Switch2_l > 0.0F));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((sint32)rtb_GT_mp) != 0) && (((sint32) rtb_sfun_setbit) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_a = (uint8)(((((((((((((sint32)rtb_NE_b4) != 0) || (((sint32)rtb_NE_hb) != 0)) || (((sint32)rtb_NE_do) != 0)) || (((sint32) rtb_NE_my) != 0)) || (((sint32)rtb_NE_dp) != 0)) || (((sint32)rtb_NE_gg) != 0)) || ((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMI_CancelFctCustom_btm())) != 0)) || (((sint32)rtb_Switch_aw) != 0)) || (((sint32)rtb_Switch_gh) != 0)) || (((sint32)rtb_DataTypeConversion_i) != 0)) || (((sint32)rtb_sfun_setbit) != 0));
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_DataTypeConversion_a;
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/ErrorStateLDP/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/ErrorStateLDP/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/ErrorStateLDP/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ErrorStateLDP_bool'
         */
    if (((sint32)GET_P_DPLSMI_ErrorStateLDPEnable_bool()) != 0) {
        rtb_Switch_ks = GET_S_LCFRCV_ErrorStateLDP_bool();
    } else {
        rtb_Switch_ks = GET_P_DPLSMI_ErrorStateLDP_bool();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/ErrorStateLDP/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Switch_ks;
    /* S-Function (sfun_setbit): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate[0];
                for (i1=0; i1 < 8; i1++) {
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
        rtb_sfun_setbit_h = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/D_SysStateLDP/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMI_SysStateLDP_btf(rtb_sfun_setbit_h);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_j[0] = rtb_NE_b4;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_j[2] = rtb_NE_my;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_j[4] = rtb_Switch_aw;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_j[5] = rtb_Switch_gh;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_j[6] = rtb_DataTypeConversion_i;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_j[7] = rtb_sfun_setbit;
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_j[1] = (uint8)((((sint32)rtb_NE_hb) != 0) || (((sint32) rtb_NE_do) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/OR1/Functionality'/OR'
         */
    rtb_VectorConcatenate_j[3] = (uint8)((((sint32)rtb_NE_dp) != 0) || (((sint32) rtb_NE_gg) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_j[0];
                for (i1=0; i1 < 8; i1++) {
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
        rtb_sfun_setbit_h = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMI_Cancel_btf(rtb_sfun_setbit_h);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/NOT/Functionality'/Data Type Conversion' incorporates:
                                                  *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/Application Parameter2'/Constant'
                                                  *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/NOT/Functionality'/NOT'
                                                  */
    rtb_sfun_setbit_h = (uint8)(!(((sint32)GET_P_DPLSMI_LatDMCClearEnable_bool()) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStOnLatDMC_bool'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/OR/Functionality'/OR'
         */
    rtb_sfun_setbit_h = (uint8)((((sint32)rtb_sfun_setbit_h) != 0) || (((sint32) GET_S_LCFRCV_SysStOnLatDMC_bool()) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/EQ1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/LDPClearance/AND3/Functionality'/AND'
         */
    rtb_NE_dp = (uint8)((((((sint32)rtb_sfun_setbit_h) != 0) && ((((sint32) GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32) GET_P_DPLSMI_QuTrajPlanClearance_btm())) == 0)) && ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32) GET_P_DPLSMI_QuTrajCtrClearance_btm())) == 0)) && (((sint32)rtb_EQ_id) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/AND/Functionality'/AND'
         */
    rtb_EQ_id = (uint8)(((((sint32)rtb_DataTypeConversion_j) != 0) && (((sint32) rtb_DataTypeConversion_n) != 0)) && (((sint32)rtb_DataTypeConversion_mh) != 0));
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/P_LDPSA_BlockingTimeDuration_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut'/Unit_Delay'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut'/Unit_Delay1'
         */
    if ((!(((sint32)DW_dplsmi_Unit_Delay1_DSTATE_d) != 0)) && (((sint32)rtb_EQ_id) != 0)) {
        rtb_Switch2_i2 = GET_P_DPLSMI_RequestTimeOut_sec();
    } else if (DW_dplsmi_Unit_Delay_DSTATE_a > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut'/Unit_Delay'
                 */
        rtb_Switch2_i2 = DW_dplsmi_Unit_Delay_DSTATE_a - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_i2 = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING'/fcg' */
    /* Chart: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI'/StateMachineLDP' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition5'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition6'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/from_data_definition8'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/Application Parameter1'/Constant'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *
         * Block description for 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI'/StateMachineLDP':
         *  X.2.1.1.3
         */
    /* Gateway: DPLSMI_cg/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP */
    /* During: DPLSMI_cg/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP */
    if (((uint32)((sint32)DW_dplsmi_is_active_c5_DPLSMI_cg)) == 0U) {
        /* Entry: DPLSMI_cg/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP */
        DW_dplsmi_is_active_c5_DPLSMI_cg = 1U;
        /* Entry Internal: DPLSMI_cg/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP */
        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':66' */
        if (!(((sint32)GET_P_LDP_Existing_nu()) != 0)) {
            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':74' */
            DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_NOT_PRESENT;
            /* Entry 'NOT_PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':3' */
            BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
        } else if ((((sint32)GET_P_LDP_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_ks) != 0))) {
            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':83' */
            DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_PRESENT;
            /* Entry Internal 'PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':107' */
            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':72' */
            if (!(((sint32)rtb_Switch_f4) != 0)) {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':71' */
                DW_dplsmi_is_PRESENT = DPLSMI_IN_DISABLED;
                /* Entry 'DISABLED': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':1' */
                BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
            } else {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':70' */
                DW_dplsmi_is_PRESENT = DPLSMI_IN_PASSIVE;
                /* Entry 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                BI_dplsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
            }
        } else {
            if ((((sint32)GET_P_LDP_Existing_nu()) != 0) && (((sint32)rtb_Switch_ks) != 0)) {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':82' */
                DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':12' */
                BI_dplsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            }
        }
    } else {
        switch (DW_dplsmi_is_c5_DPLSMI_cg) {
        case DPLSMI_IN_ERROR:
            /* During 'ERROR': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':12' */
            if ((!(((sint32)rtb_Switch_ks) != 0)) || (!(((sint32)GET_P_LDP_Existing_nu ()) != 0))) {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':59' */
                if (!(((sint32)GET_P_LDP_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':74' */
                    DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':3' */
                    BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_LDP_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_ks) != 0))) {
                    /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':83' */
                    DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':107' */
                    /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':72' */
                    if (!(((sint32)rtb_Switch_f4) != 0)) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':71' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':1' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':70' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                } else {
                    if ((((sint32)GET_P_LDP_Existing_nu()) != 0) && (((sint32) rtb_Switch_ks) != 0)) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':82' */
                        DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':12' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        case DPLSMI_IN_NOT_PRESENT:
            /* During 'NOT_PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':3' */
            if (((sint32)GET_P_LDP_Existing_nu()) != 0) {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':81' */
                if (!(((sint32)GET_P_LDP_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':74' */
                    DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':3' */
                    BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_LDP_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_ks) != 0))) {
                    /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':83' */
                    DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':107' */
                    /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':72' */
                    if (!(((sint32)rtb_Switch_f4) != 0)) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':71' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':1' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':70' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                } else {
                    if ((((sint32)GET_P_LDP_Existing_nu()) != 0) && (((sint32) rtb_Switch_ks) != 0)) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':82' */
                        DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':12' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        default:
            /* During 'PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':107' */
            if (!(((sint32)GET_P_LDP_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':58' */
                /* Exit Internal 'PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':107' */
                DW_dplsmi_is_PRESENT = DPLSMI_IN_NO_ACTIVE_CHILD;
                DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_NOT_PRESENT;
                /* Entry 'NOT_PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':3' */
                BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
            } else if ((((sint32)rtb_Switch_ks) != 0) && (((sint32) GET_P_LDP_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':76' */
                /* Exit Internal 'PRESENT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':107' */
                DW_dplsmi_is_PRESENT = DPLSMI_IN_NO_ACTIVE_CHILD;
                DW_dplsmi_is_c5_DPLSMI_cg = DPLSMI_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':12' */
                BI_dplsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                switch (DW_dplsmi_is_PRESENT) {
                case DPLSMI_IN_ACTIVE:
                    /* During 'ACTIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':10' */
                    if ((((((sint32)rtb_LogicalOperator_kw) != 0) || (((sint32) rtb_DataTypeConversion_a) != 0)) || (!(((sint32) rtb_DataTypeConversion_j) != 0))) || (!(((sint32)rtb_NE_dp) != 0))) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':65' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':64' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    }
                    break;
                case DPLSMI_IN_DISABLED:
                    /* During 'DISABLED': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':1' */
                    if (((sint32)rtb_Switch_f4) != 0) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':17' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                    break;
                case DPLSMI_IN_PASSIVE:
                    /* During 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                    if (!(((sint32)rtb_Switch_f4) != 0)) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':18' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':1' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        if (((((sint32)rtb_DataTypeConversion_j) != 0) && (((sint32) rtb_DataTypeConversion_n) != 0)) && (((sint32) rtb_DataTypeConversion_mh) != 0)) {
                            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':80' */
                            DW_dplsmi_is_PRESENT = DPLSMI_IN_REQUEST;
                            /* Entry 'REQUEST': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':9' */
                            BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu);
                        }
                    }
                    break;
                case DPLSMI_IN_RAMPOUT:
                    /* During 'RAMPOUT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':64' */
                    if (((sint32)rtb_DataTypeConversion_pr) != 0) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':78' */
                        if (!(((sint32)rtb_Switch_f4) != 0)) {
                            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':71' */
                            DW_dplsmi_is_PRESENT = DPLSMI_IN_DISABLED;
                            /* Entry 'DISABLED': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':1' */
                            BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                        } else {
                            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':70' */
                            DW_dplsmi_is_PRESENT = DPLSMI_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                            BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                default:
                    /* During 'REQUEST': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':9' */
                    if ((((sint32)rtb_NE_dp) != 0) && (!(((sint32)rtb_DataTypeConversion_j) != 0))) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':143' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':64' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    } else if ((((sint32)rtb_NE_dp) != 0) && (((sint32) rtb_DataTypeConversion_j) != 0)) {
                        /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':20' */
                        DW_dplsmi_is_PRESENT = DPLSMI_IN_ACTIVE;
                        /* Entry 'ACTIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':10' */
                        BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu);
                    } else {
                        if ((!(((sint32)rtb_NE_dp) != 0)) && ((!(rtb_Switch2_i2 > 0.0F)) || (!(((sint32)rtb_DataTypeConversion_j) != 0)))) {
                            /* Transition: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':22' */
                            DW_dplsmi_is_PRESENT = DPLSMI_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineLDP':8' */
                            BI_dplsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI'/StateMachineLDP' */
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/from_data_definition'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/from_data_definition5'/state_source'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Relational Operator2/Functionality'/EQ'
         */
    rtb_Switch_f4 = (uint8)(((((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide'/Template'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide'/Template1'
         */
    if (((sint32)DW_dplsmi_Template1_DSTATE) != 0) {
        rtb_DataTypeConversion_cz = DW_dplsmi_Template_DSTATE_d;
    } else if (((sint32)rtb_DataTypeConversion_cz) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_cz = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT);
    } else if (((sint32)rtb_DataTypeConversion_o) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_cz = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT);
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_cz = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/from_data_definition3'/state_source'
         */
    if (((sint32)rtb_Switch_f4) != 0) {
        rtb_DataTypeConversion_o = rtb_DataTypeConversion_cz;
    } else {
        rtb_DataTypeConversion_o = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/Switch4/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation'/Unit_Delay1'
         */
    if (((sint32)rtb_UnitDelay2) != 0) {
        rtb_DataTypeConversion_mh = DW_dplsmi_Unit_Delay1_DSTATE_a;
    } else {
        rtb_DataTypeConversion_mh = rtb_DataTypeConversion_b;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/Switch4/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/branch'/copy1' */
    SET_S_DPLSMI_FunctionAborted_bool(rtb_DataTypeConversion_mh);
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_DataTypeConversion_eh) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
                 */
        if (DW_dplsmi_UnitDelay1_DSTATE_nj > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmi_UnitDelay1_DSTATE_nj -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_OnTargetFinishTime_sec'/Constant'
                 */
        DW_dplsmi_UnitDelay1_DSTATE_nj = GET_P_DPLSMI_OnTargetFinishTime_sec();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_e[0] = rtb_GT;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_e[1] = rtb_RelationalOperator1_f;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_e[2] = LogicalOperator_c;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_e[3] = rtb_LT_a;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_e[4] = rtb_DataTypeConversion_en;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_e[5] = rtb_LogicalOperator_p;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_e[6] = rtb_EQ_g1;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_e[7] = rtb_EQ_hv;
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_hy) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2'
                 */
        if (DW_dplsmi_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmi_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter1'/Constant'
                 */
        DW_dplsmi_Unit_Delay2_DSTATE = GET_P_DPLSMI_SafeSituationDelay_sec();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_d) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1'
                 */
        if (DW_dplsmi_UnitDelay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmi_UnitDelay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter2'/Constant'
                 */
        DW_dplsmi_UnitDelay1_DSTATE = GET_P_DPLSMI_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_e[0];
                for (i1=0; i1 < 8; i1++) {
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
        rtb_sfun_setbit_h = temp;
    }
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_a[0] = rtb_LT_lw;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_a[1] = rtb_RelationalOperator1_a;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_a[2] = LogicalOperator_k;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_a[3] = rtb_GT_h;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_a[4] = rtb_DataTypeConversion_lw;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_a[5] = rtb_LogicalOperator_e;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_a[6] = rtb_EQ_k0;
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_a[7] = rtb_EQ_hk;
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_UnitDelay1_c) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2'
                 */
        if (DW_dplsmi_Unit_Delay2_DSTATE_g > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmi_Unit_Delay2_DSTATE_g -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter1'/Constant'
                 */
        DW_dplsmi_Unit_Delay2_DSTATE_g = GET_P_DPLSMI_SafeSituationDelay_sec();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_j) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1'
                 */
        if (DW_dplsmi_UnitDelay1_DSTATE_n > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmi_UnitDelay1_DSTATE_n -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter3'/Constant'
                 */
        DW_dplsmi_UnitDelay1_DSTATE_n = GET_P_DPLSMI_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_a[0];
                for (i1=0; i1 < 8; i1++) {
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
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Logical Operator1/Functionality'/AND'
         */
    rtb_LT_a = (uint8)((((sint32)rtb_DataTypeConversion_n) != 0) && (((sint32) rtb_DataTypeConversion_j) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[0] = (uint8)(!(((sint32)rtb_EQ_es) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[1] = (uint8)(!(((sint32)rtb_EQ_p5) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[2] = (uint8)(!(((sint32)rtb_EQ_ge) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[3] = (uint8)(!(((sint32)rtb_EQ_fr) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[4] = (uint8)(!(((sint32)rtb_EQ_c) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[5] = (uint8)(!(((sint32)rtb_EQ_bn) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[6] = (uint8)(!(((sint32)rtb_EQ_jw) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_p[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_ox) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_p[0];
                for (i1=0; i1 < 8; i1++) {
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
        rtb_Switch_aw = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/StrongReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMI_StrongReady_btf(rtb_Switch_aw);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT/Functionality'/Data Type Conversion' incorporates:
                                                   *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT/Functionality'/NOT'
                                                   */
    rtb_VectorConcatenate_n[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_d1) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[1] = (uint8)(!(((sint32)rtb_EQ_ps) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT2/Functionality'/NOT'
         */
    rtb_Switch_aw = (uint8)(!(((sint32)rtb_EQ_kn) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[3] = (uint8)(!(((sint32)rtb_EQ_od) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[4] = (uint8)(!(((sint32)rtb_EQ_hp) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[5] = (uint8)(!(((sint32)rtb_EQ_d2) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[6] = (uint8)(!(((sint32)rtb_EQ_nc) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_n[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/NOT8/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_n[2] = (uint8)((!(((sint32)rtb_EQ_ft) != 0)) || (((sint32)rtb_Switch_aw) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_n[0];
                for (i1=0; i1 < 8; i1++) {
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
        rtb_Switch_aw = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMI_WeakReady_btf(rtb_Switch_aw);
    /* DataTypeConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/NOT/Functionality'/Data Type Conversion' incorporates:
                                                 *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/NOT/Functionality'/NOT'
                                                 */
    rtb_LT_d = (uint8)(!(((sint32)rtb_Switch_ks) != 0));
    /* S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND11/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter3'/Constant'
         */
    rtb_Switch_aw = (uint8)(((sint32)GET_P_DPLSMI_DebugDrvSt_btm()) & ((sint32) GET_P_DPLSMI_CancelDrvSt_btm()));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Constant11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/OR3/Functionality'/OR'
         */
    rtb_DataTypeConversion_en = (uint8)((((sint32)((uint8)(((sint32)((uint8) (((sint32)GET_P_DPLSMI_StrgRdyDrvSt_btm()) & ((sint32) GET_P_DPLSMI_DebugDrvSt_btm())))) | ((sint32)rtb_Switch_aw)))) & ((sint32) GET_S_VDPDRV_DrvStInvalid_btf())) != 0);
    /* S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND4/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter7'/Constant'
         */
    rtb_Switch_aw = (uint8)(((sint32)GET_P_DPLSMI_DebugSpecific_btm()) & ((sint32)GET_P_DPLSMI_CancelSpecific_btm()));
    /* RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Constant9'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/OR2/Functionality'/OR'
         */
    rtb_LogicalOperator_p = (uint8)((((sint32)((uint8)(((sint32)((uint8) (((sint32)GET_P_DPLSMI_StrgRdySpecific_btm()) & ((sint32) GET_P_DPLSMI_DebugSpecific_btm())))) | ((sint32)rtb_Switch_aw)))) & ((sint32) GET_S_DPLSIA_SpecificLDP_btf())) != 0);
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Constant4'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDP_bool'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDPRi_btf'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/NOT1/Functionality'/NOT'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/NEQ6/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND7/Functionality'/AND'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch11/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch12/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch8/Functionality'/Switch'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch9/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState'/Template'
         *  UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState'/Template1'
         */
    if (((sint32)DW_dplsmi_Template1_DSTATE_a) != 0) {
        rtb_DataTypeConversion_b = DW_dplsmi_Template_DSTATE_j;
    } else if (((sint32)rtb_LogicalOperator_kw) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_SUCCESSFUL);
    } else if (((sint32)rtb_DataTypeConversion_b) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition9'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_ABORT);
    } else if (((sint32)rtb_DataTypeConversion_o) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Application Parameter5'/Constant'
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Constant13'/Constant'
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition15'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDP_bool'
                 *  Inport: '<Root>/S_DPLSIA_SideCondLDPLe_btf'
                 *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/NOT/Functionality'/NOT'
                 *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/NEQ2/Functionality'/NE'
                 *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND3/Functionality'/AND'
                 *  S-Function (sfix_bitop): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/AND5/Functionality'/AND'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        if (((((((sint32)GET_P_DPLSMI_SideCondDebug_btm()) & ((sint32) GET_P_DPLSMI_SideCondCancel_btm())) & ((sint32) GET_S_DPLSIA_SideCondLDPLe_btf())) != 0) || (((sint32) rtb_DataTypeConversion_en) != 0)) || (((sint32)rtb_LogicalOperator_p) != 0)) {
            rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
        } else if (((sint32)rtb_DataTypeConversion_fo) != 0) {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition14'/state_source'
                         */
            rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
        } else if (!(((sint32)GET_S_DPLSIA_LnBndLeValidLDP_bool()) != 0)) {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition13'/state_source'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch10/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
        } else {
            /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition2'/state_source'
                         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch7/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch6/Functionality'/Switch' */
    } else if (((((sint32)rtb_DataTypeConversion_en) != 0) || (((sint32) rtb_LogicalOperator_p) != 0)) || (((((sint32) GET_P_DPLSMI_SideCondDebug_btm()) & ((sint32) GET_P_DPLSMI_SideCondCancel_btm())) & ((sint32) GET_S_DPLSIA_SideCondLDPRi_btf())) != 0)) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition11'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
    } else if (((sint32)rtb_DataTypeConversion_ae) != 0) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition10'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
    } else if (!(((sint32)GET_S_DPLSIA_LnBndRiValidLDP_bool()) != 0)) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition8'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
    } else {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition16'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch12/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition6'/state_source'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Relational Operator5/Functionality'/EQ'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch3/Functionality'/Switch'
         */
    if (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) {
        rtb_Switch_aw = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_TRIGGER);
    } else if (((sint32)BI_dplsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition5'/state_source'
                 */
        rtb_Switch_aw = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_RUNNING);
    } else {
        rtb_Switch_aw = rtb_DataTypeConversion_b;
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDP_bool'
         *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_o) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch3'/copy1' */
        SET_S_DPLSMI_SysStateLDPLe_nu(rtb_Switch_aw);
    } else if (((((sint32)GET_S_DPLSIA_LnBndLeValidLDP_bool()) != 0) && (((sint32) rtb_LT_a) != 0)) && (((sint32)rtb_LT_d) != 0)) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/from_data_definition2'/state_source'
                 *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch3'/copy1'
                 */
        SET_S_DPLSMI_SysStateLDPLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL));
    } else {
        /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch3'/copy1' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch2/Functionality'/Switch'
                 */
        SET_S_DPLSMI_SysStateLDPLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/from_data_definition10'/state_source'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Relational Operator1/Functionality'/EQ'
         */
    if (((sint32)rtb_DataTypeConversion_o) != ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        /* Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/from_data_definition8'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDP_bool'
                 *  Logic: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/AND1/Functionality'/AND'
                 */
        if (((((sint32)GET_S_DPLSIA_LnBndRiValidLDP_bool()) != 0) && (((sint32) rtb_LT_a) != 0)) && (((sint32)rtb_LT_d) != 0)) {
            rtb_Switch_aw = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL);
        } else {
            rtb_Switch_aw = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL);
        }
        /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch1'/copy1' */
    SET_S_DPLSMI_SysStateLDP_nu(BI_dplsmi_SysState_nu);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch10'/copy1' */
    SET_D_DPLSMI_TriggerLe_btf(rtb_sfun_setbit_h);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch11'/copy1' */
    SET_D_DPLSMI_TriggerRi_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch2'/copy1' */
    SET_S_DPLSMI_SysStateLDPRi_nu(rtb_Switch_aw);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch4'/copy1' */
    SET_S_DPLSMI_DangerousSide_nu(rtb_DataTypeConversion_o);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch5'/copy1' */
    SET_S_DPLSMI_ReadyToTrigger_bool(rtb_LT_a);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch6'/copy1' */
    SET_D_DPLSMI_DlcLeThreshold_met(rtb_Switch_fc);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch7'/copy1' */
    SET_D_DPLSMI_DlcRiThreshold_met(rtb_Mul);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch8'/copy1' */
    SET_D_DPLSMI_TlcLeThreshold_sec(rtb_Switch);
    /* SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/branch9'/copy1' */
    SET_D_DPLSMI_TlcRiThreshold_sec(rtb_Switch_ba);
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE_n = rtb_Switch_hy;
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmi_Unit_Delay_DSTATE_j = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE = rtb_Switch2_lt;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE_b = rtb_UnitDelay1_c;
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmi_Unit_Delay_DSTATE_d = rtb_GT_l0;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE_f = rtb_Switch_pv;
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime'/Template' incorporates:
         *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmi_Template_DSTATE = rtb_EQ_bz;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE_o = rtb_Switch_jm;
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmi_Unit_Delay1_DSTATE = rtb_UnitDelay2;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE_m = rtb_Switch2_m;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs'/Unit Delay5' */
    DW_dplsmi_UnitDelay5_DSTATE = rtb_DataTypeConversion_o;
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmi_Unit_Delay4_DSTATE = rtb_GT_mp;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3' */
    DW_dplsmi_Unit_Delay3_DSTATE = rtb_Switch2_l;
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmi_Unit_Delay1_DSTATE_d = rtb_EQ_id;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/TimeOut'/Unit_Delay' */
    DW_dplsmi_Unit_Delay_DSTATE_a = rtb_Switch2_i2;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide'/Template' */
    DW_dplsmi_Template_DSTATE_d = rtb_DataTypeConversion_cz;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/DangerousSide'/Template1' */
    DW_dplsmi_Template1_DSTATE = rtb_Switch_f4;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/StateMachineInputs/Degradation'/Unit_Delay1' */
    DW_dplsmi_Unit_Delay1_DSTATE_a = rtb_DataTypeConversion_mh;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState'/Template' */
    DW_dplsmi_Template_DSTATE_j = rtb_DataTypeConversion_b;
    /* Update for UnitDelay: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState'/Template1' incorporates:
         *  Constant: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/from_data_definition12'/state_source'
         *  RelationalOperator: 'sda:DPLSMI/DPLSMI/DPLSMI_SenProcess/OPM/M_DPLSMI/SysState/SysState/Relational Operator1/Functionality'/EQ'
         */
    DW_dplsmi_Template1_DSTATE_a = (uint8)(((sint32)BI_dplsmi_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
}
#include "Pse_DPLSMI.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
