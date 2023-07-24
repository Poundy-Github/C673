/**************************************************************************
COPYRIGHT (C) $Date: 2020/06/24 07:38:47CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/LDPSA/DPLSMW_SEN/DPLSMW/i/project.pj $
$Log: DPLSMW.c  $
Revision 1.4.1.2.1.1 2020/06/24 07:38:47CEST Iordachescu, Roxana03 (uidq9891) 
automatically created
File          : DPLSMW
Generated on  : Tue 23.06.2020 at 16:12:56 (UTC+01:00)
MD5           : [388790938    65684497   286353564  1925527410 0](DPLSMW)
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
#include "DPLSMW.h"
#include "DPLSMW_private.h"
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
/* Named constants for Chart: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW'/StateMachineLDW' */
#define DPLSMW_IN_ACTIVE               ((uint8)1U)
#define DPLSMW_IN_DISABLED             ((uint8)2U)
#define DPLSMW_IN_ERROR                ((uint8)1U)
#define DPLSMW_IN_NOT_PRESENT          ((uint8)2U)
#define DPLSMW_IN_NO_ACTIVE_CHILD      ((uint8)0U)
#define DPLSMW_IN_PASSIVE              ((uint8)3U)
#define DPLSMW_IN_PRESENT              ((uint8)3U)
#define DPLSMW_IN_RAMPOUT              ((uint8)4U)
#define DPLSMW_IN_REQUEST              ((uint8)5U)
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
#define DPLSMW_START_SEC_DATA_8
#include "DPLSMW_MemMap.h"
static uint8 BI_dplsmw_SysState_nu;
/* 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW'/StateMachineLDW' */
static uint8 DW_dplsmw_Unit_Delay_DSTATE_p;
static uint8 DW_dplsmw_Unit_Delay_DSTATE_n;
static uint8 DW_dplsmw_Unit_Delay_DSTATE_p0;
static uint8 DW_dplsmw_Unit_Delay_DSTATE_m;
static uint8 DW_dplsmw_Template_DSTATE;
static uint8 DW_dplsmw_UnitDelay2_DSTATE_o;
static uint8 DW_dplsmw_UnitDelay5_DSTATE;
static uint8 DW_dplsmw_Unit_Delay_DSTATE_c;
static uint8 DW_dplsmw_Unit_Delay4_DSTATE;
static uint8 DW_dplsmw_Unit_Delay_DSTATE_b;
static uint8 DW_dplsmw_Template_DSTATE_e;
static uint8 DW_dplsmw_Template1_DSTATE;
static uint8 DW_dplsmw_Template_DSTATE_g;
static uint8 DW_dplsmw_Template1_DSTATE_g;
static uint8 DW_dplsmw_is_active_c12_DPLSMW_cg;
static uint8 DW_dplsmw_is_c12_DPLSMW_cg;
static uint8 DW_dplsmw_is_PRESENT;
#define DPLSMW_STOP_SEC_DATA_8
#include "DPLSMW_MemMap.h"
#define DPLSMW_START_SEC_DATA_32
#include "DPLSMW_MemMap.h"
static float32 DW_dplsmw_UnitDelay1_DSTATE;
static float32 DW_dplsmw_Unit_Delay2_DSTATE;
static float32 DW_dplsmw_Unit_Delay_DSTATE;
static float32 DW_dplsmw_UnitDelay1_DSTATE_l;
static float32 DW_dplsmw_Unit_Delay2_DSTATE_f;
static float32 DW_dplsmw_Unit_Delay_DSTATE_l;
static float32 DW_dplsmw_Unit_Delay_DSTATE_d;
static float32 DW_dplsmw_UnitDelay1_DSTATE_n;
static float32 DW_dplsmw_UnitDelay1_DSTATE_i;
static float32 DW_dplsmw_Unit_Delay3_DSTATE;
static float32 DW_dplsmw_UnitDelay1_DSTATE_o;
#define DPLSMW_STOP_SEC_DATA_32
#include "DPLSMW_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPLSMW/DPLSMW/INI'/DPLSMW_SenReset'
 * Block description for: 'sda:DPLSMW/DPLSMW/INI'/DPLSMW_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLSMW_SenReset
#include "Pse_DPLSMW.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLSMW_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant1'/Constant' */
    SET_D_DPLSMW_TlcRiThreshold_sec(0.0F);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant10'/Constant' */
    SET_D_DPLSMW_TriggerLe_btf(0U);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant12'/Constant' */
    SET_S_DPLSMW_ReadyToTrigger_bool(0U);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant2'/Constant' */
    SET_D_DPLSMW_DlcLeThreshold_met(0.0F);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant3'/Constant' */
    SET_D_DPLSMW_SysStateLDW_btf(0U);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant4'/Constant' */
    SET_D_DPLSMW_TlcLeThreshold_sec(0.0F);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant5'/Constant' */
    SET_D_DPLSMW_StrongReady_btf(0U);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant6'/Constant' */
    SET_D_DPLSMW_Cancel_btf(0U);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant7'/Constant' */
    SET_D_DPLSMW_WeakReady_btf(0U);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant8'/Constant' */
    SET_D_DPLSMW_DlcRiThreshold_met(0.0F);
    /* Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/Constant9'/Constant' */
    SET_D_DPLSMW_TriggerRi_btf(0U);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition1'/Signal Conversion3' incorporates:
                                            *  Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition1'/state_source'
                                            */
    SET_S_DPLSMW_SysStateLDWRi_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition2'/Signal Conversion3' incorporates:
                                                            *  Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition2'/state_source'
                                                            */
    SET_S_DPLSMW_SysStateLDW_nu(((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition3'/Signal Conversion3' incorporates:
                                                           *  Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition3'/state_source'
                                                           */
    SET_S_DPLSMW_DangerousSide_nu(((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition5'/Signal Conversion3' incorporates:
                                                            *  Constant: 'sda:DPLSMW/DPLSMW/INI/DPLSMW_SenReset/from_data_definition5'/state_source'
                                                            */
    SET_S_DPLSMW_SysStateLDWLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
}
#include "Pse_DPLSMW.h"
/*
 * Output and update for function-call system: 'sda:DPLSMW/DPLSMW'/DPLSMW_SenProcess'
 * Block description for: 'sda:DPLSMW/DPLSMW'/DPLSMW_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPLSMW_SenProcess
#include "Pse_DPLSMW.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void DPLSMW_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_UnaryMinus;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_af;
    float32 rtb_Abs_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_md;
    float32 rtb_ip_lookup_fxpt_sfun_7_ac;
    float32 rtb_Abs_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_gw;
    float32 rtb_Abs_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_gi;
    float32 rtb_ip_lookup_fxpt_sfun_7_if;
    float32 rtb_Abs_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_Abs_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_m4;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Abs_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_jt;
    float32 rtb_Abs_dl;
    float32 rtb_ip_lookup_fxpt_sfun_7_jtj;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_m3;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_hc;
    float32 rtb_ip_lookup_fxpt_sfun_7_pl;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate_n[8];
    uint8 rtb_VectorConcatenate_i[8];
    uint8 rtb_VectorConcatenate1[8];
    uint8 rtb_VectorConcatenate_e[8];
    uint8 rtb_VectorConcatenate_a[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_e;
    uint8 rtb_Switch_fs;
    uint8 rtb_LT_af;
    float32 rtb_Mul;
    uint8 rtb_DataTypeConversion_fc;
    uint8 rtb_LT_ms;
    uint8 rtb_DataTypeConversion_ls;
    uint8 rtb_UnitDelay1_p;
    uint8 rtb_DataTypeConversion_hi;
    uint8 rtb_EQ_bi;
    uint8 rtb_EQ_eko;
    uint8 rtb_LogicalOperator_j;
    uint8 rtb_Switch_flt;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_GT;
    uint8 rtb_GT_j3;
    uint8 rtb_DataTypeConversion_h2;
    uint8 rtb_GT_nb;
    uint8 rtb_LT_a;
    uint8 rtb_DataTypeConversion_ab;
    uint8 rtb_EQ_dk;
    uint8 rtb_EQ_kn;
    uint8 rtb_EQ_dm;
    uint8 rtb_LogicalOperator_f;
    uint8 rtb_LT_f;
    uint8 rtb_EQ_in;
    uint8 rtb_DataTypeConversion_hu;
    uint8 rtb_DataTypeConversion_e;
    uint8 rtb_EQ_pv;
    uint8 rtb_EQ_gp;
    uint8 rtb_EQ_e4;
    uint8 rtb_EQ_jp;
    uint8 rtb_EQ_lp;
    uint8 rtb_DataTypeConversion_a0;
    uint8 rtb_DataTypeConversion_h;
    uint8 rtb_DataTypeConversion_hh;
    uint8 rtb_DataTypeConversion_ml;
    uint8 rtb_EQ_kym;
    uint8 rtb_EQ_bk;
    uint8 rtb_EQ_hs;
    uint8 rtb_EQ_pn;
    uint8 rtb_EQ_el;
    uint8 rtb_EQ_j;
    uint8 rtb_EQ_h;
    uint8 rtb_UnitDelay2;
    uint8 rtb_EQ_px;
    uint8 rtb_DataTypeConversion_nf;
    uint8 rtb_DataTypeConversion_i;
    uint8 rtb_DataTypeConversion_ho;
    uint8 rtb_DataTypeConversion_k;
    float32 rtb_Switch_o1;
    uint8 rtb_DataTypeConversion_g5;
    uint8 rtb_NE_fq;
    uint8 rtb_NE_bi;
    uint8 rtb_NE_bot;
    uint8 rtb_NE_nb;
    uint8 rtb_NE_dn;
    uint8 rtb_Switch_mc;
    uint8 rtb_Switch_ae;
    uint8 rtb_LogicalOperator_o;
    uint8 rtb_DataTypeConversion_co;
    uint8 rtb_DataTypeConversion_pe;
    uint8 rtb_EQ_dru;
    uint8 rtb_DataTypeConversion_b2;
    uint8 rtb_DataTypeConversion_n;
    uint8 rtb_Switch_nt;
    float32 rtb_Switch;
    float32 rtb_Switch_p;
    float32 rtb_Switch_gh;
    float32 rtb_Switch2_e;
    float32 rtb_Switch2_m;
    float32 rtb_Switch_kr;
    float32 rtb_Switch2_p;
    float32 rtb_Switch_lg;
    uint8 LogicalOperator_o;
    uint8 LogicalOperator_m;
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/LDWSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/LDWSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/LDWSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDWSwitch_bool'
         */
    if (((sint32)GET_P_DPLSMW_LDWSwitchEnable_bool()) != 0) {
        rtb_Switch_fs = GET_S_LCFRCV_LDWSwitch_bool();
    } else {
        rtb_Switch_fs = GET_P_DPLSMW_LDWSwitch_bool();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/LDWSwitch/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_Switch_fs;
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDWDlcLimitLe_met'
         */
    if (((sint32)GET_P_LDW_DlcLimitCustom_bool()) != 0) {
        rtb_Switch_gh = GET_S_CUSTOM_LDWDlcLimitLe_met();
    } else {
        rtb_Switch_gh = GET_P_DPLSMW_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator6/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDW_met'
         */
    rtb_LT_af = (uint8)(GET_S_DPLSIA_DlcLeLDW_met() < rtb_Switch_gh);
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDWMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator8/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch7/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_LDWMode_nu()) == 3) {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D(GETA_Y_DPLSMW_VXMD3TrigDlc_met(), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_l;
    } else if (((sint32)GET_S_LCFRCV_LDWMode_nu()) == 2) {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m3 = F32_PTR_IP1D(GETA_Y_DPLSMW_VXMD2TrigDlc_met (), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_m3;
    } else {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D(GETA_Y_DPLSMW_VXMD1TrigDlc_met(), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_n;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' */
    /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDW_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPLSMW_LWTrigDlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDW_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul = rtb_Switch_p * rtb_ip_lookup_fxpt_sfun_7;
    /* UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Neg4/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_DPLSIA_VelLatLeLDW_mps'
         */
    rtb_UnaryMinus = -GET_S_DPLSIA_VelLatLeLDW_mps();
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SafetyInterface/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SafetyInterface/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDWOn_bool()) != 0) {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrvSIF_1pm();
    } else {
        rtb_Switch = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SafetyInterface/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDWDlcTrgLe_met'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
         *  Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/EQ1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
         */
    if (((sint32)GET_P_LDW_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_kr = GET_S_CUSTOM_LDWDlcTrgLe_met();
    } else {
        if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_k = f32_abs_f32(rtb_Switch);
            /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_k, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_jt = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_kr = -rtb_ip_lookup_fxpt_sfun_7_jt;
        } else if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_dl = f32_abs_f32(rtb_Switch);
            /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_dl, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_jtj = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_kr = rtb_ip_lookup_fxpt_sfun_7_jtj;
        } else {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant8'/Constant'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_kr = 0.0F;
        }
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_DPLSMW_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_kr += rtb_Mul * rtb_ip_lookup_fxpt_sfun_7_b;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_LDWMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_LDWMode_nu()) == 3) {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D(GETA_Y_DPLSMW_VXMD3TrigTlc_sec(), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_j;
    } else if (((sint32)GET_S_LCFRCV_LDWMode_nu()) == 2) {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_md = F32_PTR_IP1D(GETA_Y_DPLSMW_VXMD2TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_md;
    } else {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ac = F32_PTR_IP1D(GETA_Y_DPLSMW_VXMD1TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_ac;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' */
    /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDW_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_DPLSMW_LWTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Divide2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDW_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_p *= rtb_ip_lookup_fxpt_sfun_7_i;
    /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D (GETA_Y_DPLSMW_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeLe_enum'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/EQ1/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
        /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_e = f32_abs_f32(rtb_Switch);
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_e, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_gw = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch = -rtb_ip_lookup_fxpt_sfun_7_gw;
    } else if (((sint32)GET_S_DPLSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
        /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_h = f32_abs_f32(rtb_Switch);
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_h, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_gi = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch = rtb_ip_lookup_fxpt_sfun_7_gi;
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant8'/Constant'
                 */
        rtb_Switch = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Divide5/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch += rtb_Switch_p * rtb_ip_lookup_fxpt_sfun_7_a;
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_TlcLeLDW_sec'
         */
    rtb_LT_ms = (uint8)(GET_S_DPLSIA_TlcLeLDW_sec() < rtb_Switch);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDW_met'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND2/Functionality'/AND'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1'
         */
    rtb_DataTypeConversion_ls = (uint8)((((((sint32) GET_P_DPLSMW_TriggerCondEnable_btm()) & 1) != 0) && (GET_S_DPLSIA_DlcLeLDW_met() < rtb_Switch_kr)) || ((((((sint32) GET_P_DPLSMW_TriggerCondEnable_btm()) & 2) != 0) && (GET_S_DPLSIA_DlcLeLDW_met() < GET_P_DPLSMW_TlcDistanceMin_met())) && ((DW_dplsmw_UnitDelay1_DSTATE <= 0.0F) && (((sint32)rtb_LT_ms) != 0))));
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Constant9'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/from_data_definition5'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDW_met'
         *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDW_bool'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND4/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/AND9/Functionality'/AND'
         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPLSMW_SafeSituationState_btm()) & 1) != 0) && (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPLSMW_SafeSituationState_btm()) & 2) != 0) && (((sint32) BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPLSMW_SafeSituationState_btm()) & 4) != 0) && (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPLSMW_SafeSituationState_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPLSMW_SafeSituationState_btm()) & 16) != 0) && (!(((sint32) GET_S_DPLSIA_LnBndLeValidLDW_bool()) != 0)))) {
        rtb_Switch_flt = 0U;
    } else if (GET_S_DPLSIA_DlcLeLDW_met() > (rtb_Switch_kr + GET_P_DPLSMW_SafeSituationOffset_met())) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_flt = 1U;
    } else {
        rtb_Switch_flt = DW_dplsmw_Unit_Delay_DSTATE_p;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2'
         */
    rtb_LogicalOperator_j = (uint8)((DW_dplsmw_Unit_Delay2_DSTATE <= 0.0F) && (((sint32)rtb_Switch_flt) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDWLe_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND5/Functionality'/AND'
         */
    rtb_EQ_eko = (uint8)((((sint32)GET_S_DPLSIA_SideCondLDWLe_btf()) & ((sint32) GET_P_DPLSMW_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND3/Functionality'/AND'
         */
    rtb_EQ_bi = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMW_FctCustomTrgLe_btm())) == 0);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator3/Functionality'/AND'
         */
    rtb_DataTypeConversion = (uint8)(((((((sint32)rtb_LT_af) != 0) && (((sint32) rtb_DataTypeConversion_ls) != 0)) && (((sint32)rtb_LogicalOperator_j) != 0)) && (((sint32)rtb_EQ_eko) != 0)) && (((sint32)rtb_EQ_bi) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDW_met'
         */
    rtb_GT = (uint8)(GET_S_DPLSIA_DlcLeLDW_met() > GET_P_DPLSMW_DlcLimitMin_met());
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_o = (uint8)((!(((sint32)DW_dplsmw_Unit_Delay_DSTATE_n) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant6'/Constant'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit_Delay'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_p = DW_dplsmw_Unit_Delay_DSTATE;
    } else {
        rtb_Switch2_p = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter5'/Constant'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_o) != 0) {
        rtb_Switch2_p = GET_P_DPLSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_p > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_p -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_p = 0.0F;
            }
            /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_fc = (uint8)(((((sint32)rtb_DataTypeConversion) != 0) || (!(((sint32)GET_P_DPLSMW_TriggerAlwaysOn_bool()) != 0))) && (rtb_Switch2_p > 0.0F));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant9'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND8/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Relational Operator3/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_h2 = (uint8)(((((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMW_FctCustomBSMLe_btm())) != 0) && ((((sint32) GET_P_DPLSMW_TriggerCondEnable_btm()) & 4) != 0)) && (((sint32) rtb_DataTypeConversion) != 0)) || ((((sint32)rtb_GT) != 0) && (((sint32) rtb_DataTypeConversion_fc) != 0)));
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDWDlcLimitRi_met'
         */
    if (((sint32)GET_P_LDW_DlcLimitCustom_bool()) != 0) {
        rtb_Switch_gh = GET_S_CUSTOM_LDWDlcLimitRi_met();
    } else {
        rtb_Switch_gh = GET_P_DPLSMW_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator6/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg1/Functionality'/Unary Minus'
         */
    rtb_GT_j3 = (uint8)(GET_S_DPLSIA_DlcRiLDW_met() > (-rtb_Switch_gh));
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SafetyInterface/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SafetyInterface/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvSIF_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    if (((sint32)GET_P_DPLSIA_SafetyIfaceLDWOn_bool()) != 0) {
        rtb_Switch_gh = GET_S_ABPLBP_RiLnClthCrvSIF_1pm();
    } else {
        rtb_Switch_gh = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SafetyInterface/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_LDWDlcTrgRi_met'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDW_mps'
         *  Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/EQ3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
         */
    if (((sint32)GET_P_LDW_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_lg = GET_S_CUSTOM_LDWDlcTrgRi_met();
    } else {
        if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_d = f32_abs_f32(rtb_Switch_gh);
            /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_d, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_lg = -rtb_ip_lookup_fxpt_sfun_7_p;
        } else if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_c = f32_abs_f32(rtb_Switch_gh);
            /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_c, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_m4 = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_lg = rtb_ip_lookup_fxpt_sfun_7_m4;
        } else {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant9'/Constant'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_lg = 0.0F;
        }
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPLSIA_VelLatRiLDW_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_if = F32_PTR_IP1D (GETA_Y_DPLSMW_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_lg += rtb_Mul * rtb_ip_lookup_fxpt_sfun_7_if;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' */
    /* UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus' */
    rtb_Mul = -rtb_Switch_lg;
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator1/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus'
         */
    rtb_GT_nb = (uint8)(GET_S_DPLSIA_DlcRiLDW_met() > (-rtb_Switch_lg));
    /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPLSIA_VelLatRiLDW_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_DPLSMW_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition2'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSIA_CurveTypeRi_enum'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/EQ3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Neg2/Functionality'/Unary Minus'
         */
    if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
        /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs = f32_abs_f32(rtb_Switch_gh);
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_af = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_lg = -rtb_ip_lookup_fxpt_sfun_7_af;
    } else if (((sint32)GET_S_DPLSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
        /* Abs: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_p = f32_abs_f32(rtb_Switch_gh);
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_p, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPLSMW_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_lg = rtb_ip_lookup_fxpt_sfun_7_m;
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant9'/Constant'
                 */
        rtb_Switch_lg = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDW_mps'
         *  Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Divide6/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_lg += rtb_Switch_p * rtb_ip_lookup_fxpt_sfun_7_g;
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator3/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPLSIA_TlcRiLDW_sec'
         */
    rtb_LT_a = (uint8)(GET_S_DPLSIA_TlcRiLDW_sec() < rtb_Switch_lg);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND4/Functionality'/AND'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg3/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1'
         */
    rtb_DataTypeConversion_ab = (uint8)((((((sint32) GET_P_DPLSMW_TriggerCondEnable_btm()) & 1) != 0) && (((sint32)rtb_GT_nb) != 0)) || ((((((sint32)GET_P_DPLSMW_TriggerCondEnable_btm()) & 2) != 0) && (GET_S_DPLSIA_DlcRiLDW_met() > (-GET_P_DPLSMW_TlcDistanceMin_met()))) && ((DW_dplsmw_UnitDelay1_DSTATE_l <= 0.0F) && (((sint32)rtb_LT_a) != 0))));
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Constant9'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/from_data_definition5'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDW_bool'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND3/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND4/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND5/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND8/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/AND9/Functionality'/AND'
         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPLSMW_SafeSituationState_btm()) & 1) != 0) && (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPLSMW_SafeSituationState_btm()) & 2) != 0) && (((sint32) BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPLSMW_SafeSituationState_btm()) & 4) != 0) && (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPLSMW_SafeSituationState_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPLSMW_SafeSituationState_btm()) & 16) != 0) && (!(((sint32) GET_S_DPLSIA_LnBndRiValidLDW_bool()) != 0)))) {
        rtb_UnitDelay1_p = 0U;
    } else if (GET_S_DPLSIA_DlcRiLDW_met() < (rtb_Mul - GET_P_DPLSMW_SafeSituationOffset_met())) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_UnitDelay1_p = 1U;
    } else {
        rtb_UnitDelay1_p = DW_dplsmw_Unit_Delay_DSTATE_p0;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2'
         */
    rtb_LogicalOperator_f = (uint8)((DW_dplsmw_Unit_Delay2_DSTATE_f <= 0.0F) && (((sint32)rtb_UnitDelay1_p) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDWRi_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND5/Functionality'/AND'
         */
    rtb_EQ_dm = (uint8)((((sint32)GET_S_DPLSIA_SideCondLDWRi_btf()) & ((sint32) GET_P_DPLSMW_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND1/Functionality'/AND'
         */
    rtb_EQ_kn = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMW_FctCustomTrgRi_btm())) == 0);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator4/Functionality'/AND'
         */
    rtb_GT_nb = (uint8)(((((((sint32)rtb_GT_j3) != 0) && (((sint32) rtb_DataTypeConversion_ab) != 0)) && (((sint32)rtb_LogicalOperator_f) != 0)) && (((sint32)rtb_EQ_dm) != 0)) && (((sint32)rtb_EQ_kn) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Neg4/Functionality'/Unary Minus'
         */
    rtb_LT_f = (uint8)(GET_S_DPLSIA_DlcRiLDW_met() < (-GET_P_DPLSMW_DlcLimitMin_met()));
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_m = (uint8)((!(((sint32)DW_dplsmw_Unit_Delay_DSTATE_m) != 0)) && (((sint32)rtb_GT_nb) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant6'/Constant'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit_Delay'
         */
    if (((sint32)rtb_LT_f) >= 1) {
        rtb_Switch_gh = DW_dplsmw_Unit_Delay_DSTATE_l;
    } else {
        rtb_Switch_gh = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter1'/Constant'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_m) != 0) {
        rtb_Switch_gh = GET_P_DPLSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_f) != 0) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch_gh > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch_gh -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch_gh = 0.0F;
            }
            /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND8/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_hi = (uint8)(((((sint32)rtb_GT_nb) != 0) || (!(((sint32)GET_P_DPLSMW_TriggerAlwaysOn_bool()) != 0))) && (rtb_Switch_gh > 0.0F));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant9'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND6/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Relational Operator2/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_hu = (uint8)(((((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMW_FctCustomBSMRi_btm())) != 0) && ((((sint32) GET_P_DPLSMW_TriggerCondEnable_btm()) & 4) != 0)) && (((sint32)rtb_GT_nb) != 0)) || ((((sint32)rtb_LT_f) != 0) && (((sint32)rtb_DataTypeConversion_hi) != 0)));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_e = (uint8)((((sint32)rtb_DataTypeConversion_h2) != 0) || (((sint32)rtb_DataTypeConversion_hu) != 0));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_e;
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND1/Functionality'/AND'
         */
    rtb_EQ_in = (uint8)((((sint32)GET_S_DPLSIA_SpecificLDW_btf()) & ((sint32) GET_P_DPLSMW_StrgRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND3/Functionality'/AND'
         */
    rtb_EQ_dk = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMW_StrgRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter12'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter13'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND6/Functionality'/AND'
         */
    rtb_EQ_pv = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPLSMW_StrgRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND2/Functionality'/AND'
         */
    rtb_EQ_gp = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMW_StrgRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND4/Functionality'/AND'
         */
    rtb_EQ_e4 = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPLSMW_StrgRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND5/Functionality'/AND'
         */
    rtb_EQ_jp = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPLSMW_StrgRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter14'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Application Parameter15'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/AND7/Functionality'/AND'
         */
    rtb_EQ_lp = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMW_StrgRdyFctCustom_btm())) == 0);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter12'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter14'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDW_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Abort/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_a0 = (uint8)((((((((((sint32) GET_S_DPLSIA_SpecificLDW_btf()) & ((sint32)GET_P_DPLSMW_AbortSpecific_btm())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMW_AbortVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPLSMW_AbortDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMW_AbortFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPLSMW_AbortFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPLSMW_AbortFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMW_AbortFctCustom_btm())) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_h = (uint8)(!(((sint32)rtb_DataTypeConversion_a0) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_hh = (uint8)((((((((((sint32)rtb_EQ_in) != 0) && (((sint32)rtb_EQ_dk) != 0)) && (((sint32)rtb_EQ_pv) != 0)) && (((sint32) rtb_EQ_gp) != 0)) && (((sint32)rtb_EQ_e4) != 0)) && (((sint32)rtb_EQ_jp) != 0)) && (((sint32)rtb_EQ_lp) != 0)) && (((sint32)rtb_DataTypeConversion_h) != 0));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion_hh;
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Not1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter12'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter14'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter5'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDW_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Not1/Functionality'/NOT'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Suppresion/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_ml = (uint8)(!((((((((((sint32) GET_S_DPLSIA_SpecificLDW_btf()) & ((sint32)GET_P_DPLSMW_SuppressSpecific_btm ())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMW_SuppressVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPLSMW_SuppressDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMW_SuppressFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPLSMW_SuppressFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPLSMW_SuppressFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMW_SuppressFctCustom_btm())) != 0)));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND1/Functionality'/AND'
         */
    rtb_EQ_kym = (uint8)((((sint32)GET_S_DPLSIA_SpecificLDW_btf()) & ((sint32) GET_P_DPLSMW_WeakRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND3/Functionality'/AND'
         */
    rtb_EQ_bk = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMW_WeakRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter12'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND6/Functionality'/AND'
         */
    rtb_EQ_hs = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPLSMW_WeakRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND2/Functionality'/AND'
         */
    rtb_EQ_pn = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMW_WeakRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND4/Functionality'/AND'
         */
    rtb_EQ_el = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPLSMW_WeakRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND5/Functionality'/AND'
         */
    rtb_EQ_j = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPLSMW_WeakRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/AND7/Functionality'/AND'
         */
    rtb_EQ_h = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMW_WeakRdyFctCustom_btm())) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/RelatOperator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/from_data_definition5'/state_source'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady'/Unit Delay2'
         */
    rtb_EQ_px = (uint8)(((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/P_LDPSA_BlockingTimeDuration_sec1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template'
         */
    if ((((sint32)DW_dplsmw_Template_DSTATE) != 0) && (!(((sint32)rtb_EQ_px) != 0))) {
        rtb_Switch2_e = GET_P_DPLSMW_BlockingTimeDuration_sec();
    } else if (DW_dplsmw_Unit_Delay_DSTATE_d > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
                 */
        rtb_Switch2_e = DW_dplsmw_Unit_Delay_DSTATE_d - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_e = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Not/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/OR/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/OR1/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Not/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady'/Unit Delay2'
         */
    rtb_DataTypeConversion_nf = (uint8)(!(((((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32)rtb_EQ_px) != 0)) || (rtb_Switch2_e > 0.0F)));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_i = (uint8)(((((((((((sint32) rtb_DataTypeConversion_ml) != 0) && (((sint32)rtb_EQ_kym) != 0)) && (((sint32)rtb_EQ_bk) != 0)) && (((sint32)rtb_EQ_hs) != 0)) && (((sint32) rtb_EQ_pn) != 0)) && (((sint32)rtb_EQ_el) != 0)) && (((sint32)rtb_EQ_j) != 0)) && (((sint32)rtb_EQ_h) != 0)) && (((sint32)rtb_DataTypeConversion_nf) != 0));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_i;
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ho = (uint8)(!(((sint32)rtb_DataTypeConversion_hh) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_k = (uint8)((((sint32) GET_P_DPLSMW_FinishCondEnable_btm()) & 1) == 0);
    /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDW_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_DPLSMW_LWHazardFinishTol_met(), &x_dps);
    }
    /* Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDW_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_p = GET_P_DPLSMW_TgtTrajPosY0_met() - rtb_ip_lookup_fxpt_sfun_7_h;
    /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDW_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_DPLSMW_LWNoHazardFinishTol_met(), &x_dps);
    }
    /* Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDW_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_o1 = GET_P_DPLSMW_TgtTrajPosY0_met() + rtb_ip_lookup_fxpt_sfun_7_f;
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND2/Functionality'/AND'
         */
    rtb_NE_fq = (uint8)((((sint32)GET_P_DPLSMW_FinishCondEnable_btm()) & 2) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND3/Functionality'/AND'
         */
    rtb_NE_bot = (uint8)((((sint32)GET_P_DPLSMW_FinishCondEnable_btm()) & 4) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant11'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant12'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND6/Functionality'/AND'
         */
    rtb_NE_dn = (uint8)((((sint32)GET_P_DPLSMW_FinishCondEnable_btm()) & 8) == 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/from_data_definition'/state_source'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay2'
         */
    rtb_UnitDelay2 = (uint8)(((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps5'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW'/Unit Delay1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW'/Unit_Delay'
         */
    if ((!(((sint32)DW_dplsmw_Unit_Delay_DSTATE_c) != 0)) && (((sint32) rtb_UnitDelay2) != 0)) {
        rtb_Switch2_m = GET_P_DPLSMW_FinishMinDuration_sec();
    } else if (DW_dplsmw_UnitDelay1_DSTATE_i > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW'/Unit Delay1'
                 */
        rtb_Switch2_m = DW_dplsmw_UnitDelay1_DSTATE_i - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_m = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_Switch_mc = (uint8)(!((rtb_Switch2_m > 0.0F) && (((sint32)rtb_UnitDelay2) != 0)));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/OR'
         */
    rtb_Switch_ae = (uint8)((((sint32)rtb_NE_dn) != 0) || (((sint32) rtb_Switch_mc) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDW_met'
         *  Inport: '<Root>/S_DPLSIA_VelLatLeLDW_mps'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator4/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator5/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator9/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR1/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator11/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator14/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator2/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator5/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator6/Functionality'/GT'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg1/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg3/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_ae = (uint8)(((((((sint32)DW_dplsmw_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((sint32) rtb_DataTypeConversion_k) != 0) || ((GET_S_DPLSIA_DlcLeLDW_met() > rtb_Switch_p) && (GET_S_DPLSIA_DlcLeLDW_met() < rtb_Switch_o1)))) && ((((sint32)rtb_NE_fq) != 0) || ((GET_S_ABPLBP_LeLnClthHeading_rad() < GET_P_DPLSMW_NoHazardFinishHeadAng_rad()) && (GET_S_ABPLBP_LeLnClthHeading_rad() > (-GET_P_DPLSMW_HazardFinishHeadAng_rad ()))))) && ((((sint32)rtb_NE_bot) != 0) || ((GET_S_DPLSIA_VelLatLeLDW_mps() < GET_P_DPLSMW_NoHazardFinishVelLat_mps()) && (GET_S_DPLSIA_VelLatLeLDW_mps() > (-GET_P_DPLSMW_HazardFinishVelLat_mps()))))) && (((sint32)rtb_Switch_ae) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps3'/Constant'
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDW_mps'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator11/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator12/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator13/Functionality'/LT'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg6/Functionality'/Unary Minus'
         */
    rtb_NE_bot = (uint8)((((sint32)rtb_NE_bot) != 0) || ((GET_S_DPLSIA_VelLatRiLDW_mps() > (-GET_P_DPLSMW_NoHazardFinishVelLat_mps())) && (GET_S_DPLSIA_VelLatRiLDW_mps() < GET_P_DPLSMW_HazardFinishVelLat_mps())));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/OR'
         */
    rtb_Switch_mc = (uint8)((((sint32)rtb_NE_dn) != 0) || (((sint32) rtb_Switch_mc) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR3/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator10/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator7/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator8/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator9/Functionality'/GT'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg4/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg5/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_Switch_mc = (uint8)(((((((sint32)DW_dplsmw_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((((sint32) rtb_DataTypeConversion_k) != 0) || ((GET_S_DPLSIA_DlcRiLDW_met() < (-rtb_Switch_p)) && (GET_S_DPLSIA_DlcRiLDW_met() > (-rtb_Switch_o1))))) && ((((sint32)rtb_NE_fq) != 0) || ((GET_S_ABPLBP_RiLnClthHeading_rad() > (-GET_P_DPLSMW_NoHazardFinishHeadAng_rad())) && (GET_S_ABPLBP_RiLnClthHeading_rad() < GET_P_DPLSMW_HazardFinishHeadAng_rad())))) && (((sint32)rtb_NE_bot) != 0)) && (((sint32)rtb_Switch_mc) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/OR'
         */
    rtb_Switch_ae = (uint8)((((sint32)rtb_Switch_ae) != 0) || (((sint32) rtb_Switch_mc) != 0));
    /* Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
         */
    rtb_LogicalOperator_o = (uint8)((DW_dplsmw_UnitDelay1_DSTATE_n <= 0.0F) && (((sint32)rtb_Switch_ae) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND1/Functionality'/AND'
         */
    rtb_Switch_mc = (uint8)((((sint32)GET_S_DPLSIA_SpecificLDW_btf()) & ((sint32) GET_P_DPLSMW_CancelSpecific_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND3/Functionality'/AND'
         */
    rtb_NE_dn = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPLSMW_CancelVehSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ5/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter11'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter12'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND6/Functionality'/AND'
         */
    rtb_NE_nb = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPLSMW_CancelDrvSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND2/Functionality'/AND'
         */
    rtb_NE_bot = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPLSMW_CancelFctStCtr_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter7'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND4/Functionality'/AND'
         */
    rtb_NE_bi = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPLSMW_CancelFctStErr_btm())) != 0);
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ4/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter10'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND5/Functionality'/AND'
         */
    rtb_NE_fq = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPLSMW_CancelFctStNotAv_btm())) != 0);
    /* Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met'/Constant'
         */
    rtb_Switch_o1 = GET_P_DPLSMW_TgtTrajPosY0_met() + GET_P_DPLSMW_NoHazardCancelTol_met();
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Constant'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcLeLDW_met'
         *  Inport: '<Root>/S_DPLSIA_VelLatLeLDW_mps'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator3/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator7/Functionality'/GT'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_co = (uint8)((GET_S_DPLSIA_DlcLeLDW_met() < (-GET_P_DPLSMW_HazardCancelTol_met())) || ((GET_S_DPLSIA_VelLatLeLDW_mps() > 0.0F) && (GET_S_DPLSIA_DlcLeLDW_met() > rtb_Switch_o1)));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met2'/Constant'
         *  Inport: '<Root>/S_DPLSIA_DlcRiLDW_met'
         *  Inport: '<Root>/S_DPLSIA_VelLatRiLDW_mps'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator12/Functionality'/LT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator9/Functionality'/GT'
         *  UnaryMinus: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Neg1/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_pe = (uint8)((GET_S_DPLSIA_DlcRiLDW_met() > GET_P_DPLSMW_HazardCancelTol_met()) || ((GET_S_DPLSIA_VelLatRiLDW_mps() < 0.0F) && (GET_S_DPLSIA_DlcRiLDW_met() < (-rtb_Switch_o1))));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/from_data_definition2'/state_source'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator5/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator6/Functionality'/EQ'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_g5 = (uint8)(((((sint32)DW_dplsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && (((sint32)rtb_DataTypeConversion_co) != 0)) || ((((sint32) DW_dplsmw_UnitDelay5_DSTATE) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32) rtb_DataTypeConversion_pe) != 0)));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDW_bool'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NOT1/Functionality'/NOT'
         */
    rtb_sfun_setbit = (uint8)(!(((sint32)GET_S_DPLSIA_LnBndRiValidLDW_bool()) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Constant3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDWRi_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NEQ4/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/AND4/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((((sint32)GET_S_DPLSIA_SideCondLDWRi_btf()) & ((sint32)GET_P_DPLSMW_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMW_FctCustomCancelRi_btm())) != 0)) || (((sint32)rtb_sfun_setbit) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/from_data_definition3'/state_source'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Relational Operator8/Functionality'/EQ'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_sfun_setbit = (uint8)((((sint32)DW_dplsmw_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32) rtb_sfun_setbit) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Logical Operator12/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Constant1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Constant2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDW_bool'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDWLe_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Logical Operator12/Functionality'/OR'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NOT/Functionality'/NOT'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/Relational Operator4/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/SideConditions/AND3/Functionality'/AND'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_sfun_setbit = (uint8)(((((sint32)DW_dplsmw_UnitDelay5_DSTATE) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((((sint32)GET_S_DPLSIA_SideCondLDWLe_btf()) & ((sint32) GET_P_DPLSMW_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPLSMW_FctCustomCancelLe_btm())) != 0)) || (!(((sint32)GET_S_DPLSIA_LnBndLeValidLDW_bool()) != 0)))) || (((sint32)rtb_sfun_setbit) != 0));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/Relational Operator11/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/from_data_definition1'/state_source'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay3'
         */
    rtb_EQ_dru = (uint8)(((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPLSIA_LaneWidthLDW_met'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Product: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/Mul/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4'
         */
    if ((!(((sint32)DW_dplsmw_Unit_Delay4_DSTATE) != 0)) && (((sint32)rtb_EQ_dru) != 0)) {
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_LaneWidth_met */
            FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_DPLSIA_LaneWidthLDW_met(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_hc = F32_PTR_IP1D (GETA_Y_DPLSMW_LWContrMaxDurScal_nu(), &x_dps);
        }
        /* S-Function Block sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_pl = F32_PTR_IP1D (GETA_Y_DPLSMW_VXContrMaxDur_sec(), &x_dps);
        }
        rtb_Switch_p = rtb_ip_lookup_fxpt_sfun_7_pl * rtb_ip_lookup_fxpt_sfun_7_hc;
    } else if (DW_dplsmw_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
                 */
        rtb_Switch_p = DW_dplsmw_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec ();
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch_p = 0.0F;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/AND'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_k = (uint8)((((sint32)rtb_EQ_dru) != 0) && (!(rtb_Switch_p > 0.0F)));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter13'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_b2 = (uint8)((((((((((((sint32)rtb_Switch_mc) != 0) || (((sint32)rtb_NE_dn) != 0)) || (((sint32)rtb_NE_nb) != 0)) || (((sint32) rtb_NE_bot) != 0)) || (((sint32)rtb_NE_bi) != 0)) || (((sint32)rtb_NE_fq) != 0)) || ((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPLSMW_CancelFctCustom_btm())) != 0)) || (((sint32) rtb_DataTypeConversion_g5) != 0)) || (((sint32)rtb_sfun_setbit) != 0)) || (((sint32)rtb_DataTypeConversion_k) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_n = (uint8)((((((sint32)rtb_DataTypeConversion_a0) != 0) || (((sint32)rtb_DataTypeConversion_ho) != 0)) || (((sint32) rtb_LogicalOperator_o) != 0)) || (((sint32)rtb_DataTypeConversion_b2) != 0));
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator2/Functionality'/AND'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising'/Unit_Delay'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation'/Unit Delay2'
         */
    rtb_sfun_setbit_e = (uint8)((((sint32)DW_dplsmw_UnitDelay2_DSTATE_o) != 0) && ((!(((sint32)DW_dplsmw_Unit_Delay_DSTATE_b) != 0)) && (((sint32) rtb_DataTypeConversion_n) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer'/Unit Delay1'
         */
    if (((sint32)rtb_sfun_setbit_e) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Application Parameter2'/Constant'
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Constant'/Constant'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch3/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_a0) != 0) {
            rtb_Switch_o1 = GET_P_DPLSMW_AbortDegrDuration_sec();
        } else if (((sint32)rtb_DataTypeConversion_ho) != 0) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Application Parameter4'/Constant'
                         */
            rtb_Switch_o1 = GET_P_DPLSMW_StrgRdyDegrDuration_sec();
        } else if (((sint32)rtb_LogicalOperator_o) != 0) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Application Parameter1'/Constant'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_o1 = GET_P_DPLSMW_FinishDegrDuration_sec();
        } else if (((sint32)rtb_DataTypeConversion_b2) != 0) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Application Parameter3'/Constant'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch2/Functionality'/Switch'
                         */
            rtb_Switch_o1 = GET_P_DPLSMW_CancelDegrDuration_sec();
        } else {
            rtb_Switch_o1 = 0.0F;
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Switch/Functionality'/Switch' */
        rtb_Switch_o1 += GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        rtb_Switch_o1 = DW_dplsmw_UnitDelay1_DSTATE_o;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Constant3'/Constant'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Relational Operator8/Functionality'/GT'
         */
    rtb_sfun_setbit_e = (uint8)((((sint32)rtb_sfun_setbit_e) != 0) || (rtb_Switch_o1 > 1.0E-5F));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/Logical Operator10/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ho = (uint8)(!(((sint32)rtb_sfun_setbit_e) != 0));
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_ho;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate[5] = rtb_LogicalOperator_o;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_DataTypeConversion_b2;
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/ErrorStateLDW/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/ErrorStateLDW/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/ErrorStateLDW/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ErrorStateLDW_bool'
         */
    if (((sint32)GET_P_DPLSMW_ErrorStateLDWEnable_bool()) != 0) {
        rtb_Switch_nt = GET_S_LCFRCV_ErrorStateLDW_bool();
    } else {
        rtb_Switch_nt = GET_P_DPLSMW_ErrorStateLDW_bool();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/ErrorStateLDW/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Switch_nt;
    /* S-Function (sfun_setbit): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_e = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/D_SysStateLDW/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMW_SysStateLDW_btf(rtb_sfun_setbit_e);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_n[0] = rtb_Switch_mc;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_n[2] = rtb_NE_bot;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_n[3] = rtb_NE_bi;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_n[4] = rtb_NE_fq;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_n[5] = rtb_DataTypeConversion_g5;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_n[6] = rtb_sfun_setbit;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_n[7] = rtb_DataTypeConversion_k;
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/OR'
         */
    rtb_VectorConcatenate_n[1] = (uint8)((((sint32)rtb_NE_dn) != 0) || (((sint32) rtb_NE_nb) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_e = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMW_Cancel_btf(rtb_sfun_setbit_e);
    /* Chart: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW'/StateMachineLDW' incorporates:
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition1'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition2'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition3'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition4'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition5'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition6'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/from_data_definition8'/state_source'
                                                  *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/Application Parameter1'/Constant'
                                                  *
                                                  * Block description for 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW'/StateMachineLDW':
                                                  *  X.2.1.1.3
                                                  */
    /* Gateway: DPLSMW_cg/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW */
    /* During: DPLSMW_cg/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW */
    if (((uint32)((sint32)DW_dplsmw_is_active_c12_DPLSMW_cg)) == 0U) {
        /* Entry: DPLSMW_cg/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW */
        DW_dplsmw_is_active_c12_DPLSMW_cg = 1U;
        /* Entry Internal: DPLSMW_cg/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW */
        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':66' */
        if (!(((sint32)GET_P_LDW_Existing_nu()) != 0)) {
            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':74' */
            DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_NOT_PRESENT;
            /* Entry 'NOT_PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':3' */
            BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
        } else if ((((sint32)GET_P_LDW_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_nt) != 0))) {
            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':83' */
            DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_PRESENT;
            /* Entry Internal 'PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':107' */
            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':72' */
            if (((sint32)rtb_Switch_fs) != 0) {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':70' */
                DW_dplsmw_is_PRESENT = DPLSMW_IN_PASSIVE;
                /* Entry 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                BI_dplsmw_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
            } else {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':71' */
                DW_dplsmw_is_PRESENT = DPLSMW_IN_DISABLED;
                /* Entry 'DISABLED': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':1' */
                BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
            }
        } else {
            if ((((sint32)GET_P_LDW_Existing_nu()) != 0) && (((sint32)rtb_Switch_nt) != 0)) {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':82' */
                DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':12' */
                BI_dplsmw_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            }
        }
    } else {
        switch (DW_dplsmw_is_c12_DPLSMW_cg) {
        case DPLSMW_IN_ERROR:
            /* During 'ERROR': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':12' */
            if ((!(((sint32)rtb_Switch_nt) != 0)) || (!(((sint32)GET_P_LDW_Existing_nu ()) != 0))) {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':59' */
                if (!(((sint32)GET_P_LDW_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':74' */
                    DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':3' */
                    BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_LDW_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_nt) != 0))) {
                    /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':83' */
                    DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':107' */
                    /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':72' */
                    if (((sint32)rtb_Switch_fs) != 0) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':70' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    } else {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':71' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':1' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    }
                } else {
                    if ((((sint32)GET_P_LDW_Existing_nu()) != 0) && (((sint32) rtb_Switch_nt) != 0)) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':82' */
                        DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':12' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        case DPLSMW_IN_NOT_PRESENT:
            /* During 'NOT_PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':3' */
            if (((sint32)GET_P_LDW_Existing_nu()) != 0) {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':81' */
                if (!(((sint32)GET_P_LDW_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':74' */
                    DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':3' */
                    BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_LDW_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_nt) != 0))) {
                    /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':83' */
                    DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':107' */
                    /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':72' */
                    if (((sint32)rtb_Switch_fs) != 0) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':70' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    } else {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':71' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':1' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    }
                } else {
                    if ((((sint32)GET_P_LDW_Existing_nu()) != 0) && (((sint32) rtb_Switch_nt) != 0)) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':82' */
                        DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':12' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        default:
            /* During 'PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':107' */
            if (!(((sint32)GET_P_LDW_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':58' */
                /* Exit Internal 'PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':107' */
                DW_dplsmw_is_PRESENT = DPLSMW_IN_NO_ACTIVE_CHILD;
                DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_NOT_PRESENT;
                /* Entry 'NOT_PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':3' */
                BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
            } else if ((((sint32)rtb_Switch_nt) != 0) && (((sint32) GET_P_LDW_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':76' */
                /* Exit Internal 'PRESENT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':107' */
                DW_dplsmw_is_PRESENT = DPLSMW_IN_NO_ACTIVE_CHILD;
                DW_dplsmw_is_c12_DPLSMW_cg = DPLSMW_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':12' */
                BI_dplsmw_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                switch (DW_dplsmw_is_PRESENT) {
                case DPLSMW_IN_ACTIVE:
                    /* During 'ACTIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':10' */
                    if (((((sint32)rtb_LogicalOperator_o) != 0) || (((sint32) rtb_DataTypeConversion_b2) != 0)) || (!(((sint32) rtb_DataTypeConversion_hh) != 0))) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':65' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':64' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    }
                    break;
                case DPLSMW_IN_DISABLED:
                    /* During 'DISABLED': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':1' */
                    if (((sint32)rtb_Switch_fs) != 0) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':17' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                    break;
                case DPLSMW_IN_PASSIVE:
                    /* During 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                    if (!(((sint32)rtb_Switch_fs) != 0)) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':18' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':1' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        if (((((sint32)rtb_DataTypeConversion_hh) != 0) && (((sint32) rtb_DataTypeConversion_i) != 0)) && (((sint32) rtb_DataTypeConversion_e) != 0)) {
                            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':80' */
                            DW_dplsmw_is_PRESENT = DPLSMW_IN_REQUEST;
                            /* Entry 'REQUEST': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':9' */
                            BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu);
                        }
                    }
                    break;
                case DPLSMW_IN_RAMPOUT:
                    /* During 'RAMPOUT': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':64' */
                    if (((sint32)rtb_DataTypeConversion_ho) != 0) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':78' */
                        if (((sint32)rtb_Switch_fs) != 0) {
                            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':70' */
                            DW_dplsmw_is_PRESENT = DPLSMW_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                            BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        } else {
                            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':71' */
                            DW_dplsmw_is_PRESENT = DPLSMW_IN_DISABLED;
                            /* Entry 'DISABLED': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':1' */
                            BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                        }
                    }
                    break;
                default:
                    /* During 'REQUEST': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':9' */
                    if ((((sint32)rtb_DataTypeConversion_hh) != 0) && (((sint32) rtb_DataTypeConversion_e) != 0)) {
                        /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':20' */
                        DW_dplsmw_is_PRESENT = DPLSMW_IN_ACTIVE;
                        /* Entry 'ACTIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':10' */
                        BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu);
                    } else {
                        if ((!(((sint32)rtb_DataTypeConversion_hh) != 0)) || (!(((sint32) rtb_DataTypeConversion_e) != 0))) {
                            /* Transition: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':22' */
                            DW_dplsmw_is_PRESENT = DPLSMW_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineLDW':8' */
                            BI_dplsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW'/StateMachineLDW' */
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/from_data_definition'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/from_data_definition1'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/from_data_definition5'/state_source'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Relational Operator2/Functionality'/EQ'
         */
    rtb_Switch_fs = (uint8)(((((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide'/Template'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide'/Template1'
         */
    if (((sint32)DW_dplsmw_Template1_DSTATE) != 0) {
        rtb_DataTypeConversion_h2 = DW_dplsmw_Template_DSTATE_e;
    } else if (((sint32)rtb_DataTypeConversion_h2) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_h2 = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT);
    } else if (((sint32)rtb_DataTypeConversion_hu) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition2'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_h2 = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT);
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_h2 = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/from_data_definition3'/state_source'
         */
    if (((sint32)rtb_Switch_fs) != 0) {
        rtb_DataTypeConversion_hu = rtb_DataTypeConversion_h2;
    } else {
        rtb_DataTypeConversion_hu = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_ae) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
                 */
        if (DW_dplsmw_UnitDelay1_DSTATE_n > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmw_UnitDelay1_DSTATE_n -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_OnTargetFinishTime_sec'/Constant'
                 */
        DW_dplsmw_UnitDelay1_DSTATE_n = GET_P_DPLSMW_OnTargetFinishTime_sec();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_i[0] = rtb_GT;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_i[1] = rtb_DataTypeConversion_fc;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_i[2] = LogicalOperator_o;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_i[3] = rtb_LT_af;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_i[4] = rtb_DataTypeConversion_ls;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_i[5] = rtb_LogicalOperator_j;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_i[6] = rtb_EQ_eko;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_i[7] = rtb_EQ_bi;
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_flt) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2'
                 */
        if (DW_dplsmw_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmw_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/Application Parameter1'/Constant'
                 */
        DW_dplsmw_Unit_Delay2_DSTATE = GET_P_DPLSMW_SafeSituationDelay_sec();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_ms) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1'
                 */
        if (DW_dplsmw_UnitDelay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmw_UnitDelay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Application Parameter2'/Constant'
                 */
        DW_dplsmw_UnitDelay1_DSTATE = GET_P_DPLSMW_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_i[0];
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
        rtb_sfun_setbit_e = temp;
    }
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1[0] = rtb_LT_f;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1[1] = rtb_DataTypeConversion_hi;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In3' */
    rtb_VectorConcatenate1[2] = LogicalOperator_m;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1[3] = rtb_GT_j3;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In5' */
    rtb_VectorConcatenate1[4] = rtb_DataTypeConversion_ab;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In6' */
    rtb_VectorConcatenate1[5] = rtb_LogicalOperator_f;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In7' */
    rtb_VectorConcatenate1[6] = rtb_EQ_dm;
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/ConcatBufferAtVector Concatenate1In8' */
    rtb_VectorConcatenate1[7] = rtb_EQ_kn;
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_UnitDelay1_p) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2'
                 */
        if (DW_dplsmw_Unit_Delay2_DSTATE_f > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmw_Unit_Delay2_DSTATE_f -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/Application Parameter1'/Constant'
                 */
        DW_dplsmw_Unit_Delay2_DSTATE_f = GET_P_DPLSMW_SafeSituationDelay_sec();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_a) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1'
                 */
        if (DW_dplsmw_UnitDelay1_DSTATE_l > 0.0F) {
            /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dplsmw_UnitDelay1_DSTATE_l -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Application Parameter3'/Constant'
                 */
        DW_dplsmw_UnitDelay1_DSTATE_l = GET_P_DPLSMW_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1[0];
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
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Logical Operator1/Functionality'/AND'
         */
    rtb_LT_af = (uint8)((((sint32)rtb_DataTypeConversion_hh) != 0) && (((sint32) rtb_DataTypeConversion_i) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[0] = (uint8)(!(((sint32)rtb_EQ_in) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[1] = (uint8)(!(((sint32)rtb_EQ_dk) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[2] = (uint8)(!(((sint32)rtb_EQ_pv) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[3] = (uint8)(!(((sint32)rtb_EQ_gp) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[4] = (uint8)(!(((sint32)rtb_EQ_e4) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[5] = (uint8)(!(((sint32)rtb_EQ_jp) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[6] = (uint8)(!(((sint32)rtb_EQ_lp) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_h) != 0));
    /* S-Function (sfun_setbit): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/set_bit/Functionality'/sfun_setbit' */
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
        rtb_Switch_ae = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/StrongReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMW_StrongReady_btf(rtb_Switch_ae);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT/Functionality'/Data Type Conversion' incorporates:
                                                   *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT/Functionality'/NOT'
                                                   */
    rtb_VectorConcatenate_a[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_ml) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_a[1] = (uint8)(!(((sint32)rtb_EQ_kym) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT2/Functionality'/NOT'
         */
    rtb_Switch_ae = (uint8)(!(((sint32)rtb_EQ_bk) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_a[3] = (uint8)(!(((sint32)rtb_EQ_pn) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_a[4] = (uint8)(!(((sint32)rtb_EQ_el) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_a[5] = (uint8)(!(((sint32)rtb_EQ_j) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_a[6] = (uint8)(!(((sint32)rtb_EQ_h) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_a[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_nf) != 0));
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/NOT8/Functionality'/NOT'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_a[2] = (uint8)((((sint32)rtb_Switch_ae) != 0) || (!(((sint32)rtb_EQ_hs) != 0)));
    /* S-Function (sfun_setbit): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/set_bit/Functionality'/sfun_setbit' */
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
        rtb_Switch_ae = temp;
    }
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPLSMW_WeakReady_btf(rtb_Switch_ae);
    /* DataTypeConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/NOT/Functionality'/Data Type Conversion' incorporates:
                                                 *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/NOT/Functionality'/NOT'
                                                 */
    rtb_LT_ms = (uint8)(!(((sint32)rtb_Switch_nt) != 0));
    /* S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND11/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter3'/Constant'
         */
    rtb_Switch_ae = (uint8)(((sint32)GET_P_DPLSMW_DebugDrvSt_btm()) & ((sint32) GET_P_DPLSMW_CancelDrvSt_btm()));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter1'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Constant11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/OR3/Functionality'/OR'
         */
    rtb_DataTypeConversion_ls = (uint8)((((sint32)((uint8)(((sint32)((uint8) (((sint32)GET_P_DPLSMW_StrgRdyDrvSt_btm()) & ((sint32) GET_P_DPLSMW_DebugDrvSt_btm())))) | ((sint32)rtb_Switch_ae)))) & ((sint32) GET_S_VDPDRV_DrvStInvalid_btf())) != 0);
    /* S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND4/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter7'/Constant'
         */
    rtb_Switch_ae = (uint8)(((sint32)GET_P_DPLSMW_DebugSpecific_btm()) & ((sint32)GET_P_DPLSMW_CancelSpecific_btm()));
    /* RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Constant9'/Constant'
         *  Inport: '<Root>/S_DPLSIA_SpecificLDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/OR2/Functionality'/OR'
         */
    rtb_Switch_ae = (uint8)((((sint32)((uint8)(((sint32)((uint8)(((sint32) GET_P_DPLSMW_StrgRdySpecific_btm()) & ((sint32) GET_P_DPLSMW_DebugSpecific_btm())))) | ((sint32)rtb_Switch_ae)))) & ((sint32) GET_S_DPLSIA_SpecificLDW_btf())) != 0);
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter8'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Constant4'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDW_bool'
         *  Inport: '<Root>/S_DPLSIA_SideCondLDWRi_btf'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/NOT1/Functionality'/NOT'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/NEQ6/Functionality'/NE'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND7/Functionality'/AND'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch11/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch12/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch8/Functionality'/Switch'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch9/Functionality'/Switch'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState'/Template'
         *  UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState'/Template1'
         */
    if (((sint32)DW_dplsmw_Template1_DSTATE_g) != 0) {
        rtb_DataTypeConversion_a0 = DW_dplsmw_Template_DSTATE_g;
    } else if (((sint32)rtb_LogicalOperator_o) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_SUCCESSFUL);
    } else if (((sint32)rtb_DataTypeConversion_a0) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition9'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_ABORT);
    } else if (((sint32)rtb_DataTypeConversion_hu) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Application Parameter5'/Constant'
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Constant13'/Constant'
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition15'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDW_bool'
                 *  Inport: '<Root>/S_DPLSIA_SideCondLDWLe_btf'
                 *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/NOT/Functionality'/NOT'
                 *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/NEQ2/Functionality'/NE'
                 *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND3/Functionality'/AND'
                 *  S-Function (sfix_bitop): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/AND5/Functionality'/AND'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        if (((((((sint32)GET_P_DPLSMW_SideCondDebug_btm()) & ((sint32) GET_P_DPLSMW_SideCondCancel_btm())) & ((sint32) GET_S_DPLSIA_SideCondLDWLe_btf())) != 0) || (((sint32) rtb_DataTypeConversion_ls) != 0)) || (((sint32)rtb_Switch_ae) != 0)) {
            rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
        } else if (((sint32)rtb_DataTypeConversion_co) != 0) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition14'/state_source'
                         */
            rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
        } else if (!(((sint32)GET_S_DPLSIA_LnBndLeValidLDW_bool()) != 0)) {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition13'/state_source'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch10/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
        } else {
            /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition2'/state_source'
                         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch7/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch6/Functionality'/Switch' */
    } else if (((((sint32)rtb_DataTypeConversion_ls) != 0) || (((sint32) rtb_Switch_ae) != 0)) || (((((sint32) GET_P_DPLSMW_SideCondDebug_btm()) & ((sint32) GET_P_DPLSMW_SideCondCancel_btm())) & ((sint32) GET_S_DPLSIA_SideCondLDWRi_btf())) != 0)) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition11'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
    } else if (((sint32)rtb_DataTypeConversion_pe) != 0) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition10'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
    } else if (!(((sint32)GET_S_DPLSIA_LnBndRiValidLDW_bool()) != 0)) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition8'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
    } else {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition16'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch12/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_a0 = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition3'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition6'/state_source'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Relational Operator5/Functionality'/EQ'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch3/Functionality'/Switch'
         */
    if (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) {
        rtb_Switch_ae = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_TRIGGER);
    } else if (((sint32)BI_dplsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition5'/state_source'
                 */
        rtb_Switch_ae = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_RUNNING);
    } else {
        rtb_Switch_ae = rtb_DataTypeConversion_a0;
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_DPLSIA_LnBndLeValidLDW_bool'
         *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_hu) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch3'/copy1' */
        SET_S_DPLSMW_SysStateLDWLe_nu(rtb_Switch_ae);
    } else if (((((sint32)GET_S_DPLSIA_LnBndLeValidLDW_bool()) != 0) && (((sint32) rtb_LT_af) != 0)) && (((sint32)rtb_LT_ms) != 0)) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/from_data_definition2'/state_source'
                 *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch3'/copy1'
                 */
        SET_S_DPLSMW_SysStateLDWLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL));
    } else {
        /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch3'/copy1' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch2/Functionality'/Switch'
                 */
        SET_S_DPLSMW_SysStateLDWLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/from_data_definition10'/state_source'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Relational Operator1/Functionality'/EQ'
         */
    if (((sint32)rtb_DataTypeConversion_hu) != ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        /* Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/from_data_definition5'/state_source'
                 *  Inport: '<Root>/S_DPLSIA_LnBndRiValidLDW_bool'
                 *  Logic: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/AND1/Functionality'/AND'
                 */
        if (((((sint32)GET_S_DPLSIA_LnBndRiValidLDW_bool()) != 0) && (((sint32) rtb_LT_af) != 0)) && (((sint32)rtb_LT_ms) != 0)) {
            rtb_Switch_ae = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL);
        } else {
            rtb_Switch_ae = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL);
        }
        /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch1'/copy1' */
    SET_S_DPLSMW_SysStateLDW_nu(BI_dplsmw_SysState_nu);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch12'/copy1' */
    SET_D_DPLSMW_TriggerLe_btf(rtb_sfun_setbit_e);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch13'/copy1' */
    SET_D_DPLSMW_TriggerRi_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch2'/copy1' */
    SET_S_DPLSMW_SysStateLDWRi_nu(rtb_Switch_ae);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch4'/copy1' */
    SET_S_DPLSMW_DangerousSide_nu(rtb_DataTypeConversion_hu);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch5'/copy1' */
    SET_S_DPLSMW_ReadyToTrigger_bool(rtb_LT_af);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch6'/copy1' */
    SET_D_DPLSMW_DlcLeThreshold_met(rtb_Switch_kr);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch7'/copy1' */
    SET_D_DPLSMW_DlcRiThreshold_met(rtb_Mul);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch8'/copy1' */
    SET_D_DPLSMW_TlcLeThreshold_sec(rtb_Switch);
    /* SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/branch9'/copy1' */
    SET_D_DPLSMW_TlcRiThreshold_sec(rtb_Switch_lg);
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/SafeSituation'/Unit_Delay' */
    DW_dplsmw_Unit_Delay_DSTATE_p = rtb_Switch_flt;
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmw_Unit_Delay_DSTATE_n = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft'/Unit_Delay' */
    DW_dplsmw_Unit_Delay_DSTATE = rtb_Switch2_p;
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/SafeSituation'/Unit_Delay' */
    DW_dplsmw_Unit_Delay_DSTATE_p0 = rtb_UnitDelay1_p;
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmw_Unit_Delay_DSTATE_m = rtb_GT_nb;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight'/Unit_Delay' */
    DW_dplsmw_Unit_Delay_DSTATE_l = rtb_Switch_gh;
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template' incorporates:
         *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmw_Template_DSTATE = rtb_EQ_px;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay' */
    DW_dplsmw_Unit_Delay_DSTATE_d = rtb_Switch2_e;
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation'/Unit Delay2' */
    DW_dplsmw_UnitDelay2_DSTATE_o = rtb_DataTypeConversion_ho;
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs'/Unit Delay5' */
    DW_dplsmw_UnitDelay5_DSTATE = rtb_DataTypeConversion_hu;
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmw_Unit_Delay_DSTATE_c = rtb_UnitDelay2;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeLDW'/Unit Delay1' */
    DW_dplsmw_UnitDelay1_DSTATE_i = rtb_Switch2_m;
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmw_Unit_Delay4_DSTATE = rtb_EQ_dru;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3' */
    DW_dplsmw_Unit_Delay3_DSTATE = rtb_Switch_p;
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dplsmw_Unit_Delay_DSTATE_b = rtb_DataTypeConversion_n;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer'/Unit Delay1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Sum: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/Degradation/FollowUpTimer/Add1/Functionality'/Sum'
         */
    DW_dplsmw_UnitDelay1_DSTATE_o = rtb_Switch_o1 - GET_S_LCFRCV_SysCycleTimeSen_sec ();
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide'/Template' */
    DW_dplsmw_Template_DSTATE_e = rtb_DataTypeConversion_h2;
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/StateMachineInputs/DangerousSide'/Template1' */
    DW_dplsmw_Template1_DSTATE = rtb_Switch_fs;
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState'/Template' */
    DW_dplsmw_Template_DSTATE_g = rtb_DataTypeConversion_a0;
    /* Update for UnitDelay: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState'/Template1' incorporates:
         *  Constant: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/from_data_definition12'/state_source'
         *  RelationalOperator: 'sda:DPLSMW/DPLSMW/DPLSMW_SenProcess/OPM/M_DPLSMW/SysState/SysState/Relational Operator1/Functionality'/EQ'
         */
    DW_dplsmw_Template1_DSTATE_g = (uint8)(((sint32)BI_dplsmw_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
}
#include "Pse_DPLSMW.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
