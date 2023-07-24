/**************************************************************************
COPYRIGHT (C) $Date: 2020/06/24 08:03:33CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/RDPSA/DPRSMW_SEN/DPRSMW/i/project.pj $
$Log: DPRSMW.c  $
Revision 1.5.1.4.1.1 2020/06/24 08:03:33CEST Iordachescu, Roxana03 (uidq9891) 
automatically created
File          : DPRSMW
Generated on  : Tue 23.06.2020 at 12:45:39 (UTC+01:00)
MD5           : [2935190898  4204686680  2356397885   989701722 0](DPRSMW)
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
#include "DPRSMW.h"
#include "DPRSMW_private.h"
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
/* Named constants for Chart: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW'/StateMachineRDP' */
#define DPRSMW_IN_ACTIVE               ((uint8)1U)
#define DPRSMW_IN_DISABLED             ((uint8)2U)
#define DPRSMW_IN_ERROR                ((uint8)1U)
#define DPRSMW_IN_NOT_PRESENT          ((uint8)2U)
#define DPRSMW_IN_NO_ACTIVE_CHILD      ((uint8)0U)
#define DPRSMW_IN_PASSIVE              ((uint8)3U)
#define DPRSMW_IN_PRESENT              ((uint8)3U)
#define DPRSMW_IN_RAMPOUT              ((uint8)4U)
#define DPRSMW_IN_REQUEST              ((uint8)5U)
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
#define DPRSMW_START_SEC_DATA_8
#include "DPRSMW_MemMap.h"
static uint8 BI_dprsmw_SysState_nu;
/* 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW'/StateMachineRDP' */
static uint8 DW_dprsmw_Unit_Delay_DSTATE_c;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_a;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_f;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_k;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_ks;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_o;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_g;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_de;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_n;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_ki;
static uint8 DW_dprsmw_Template_DSTATE;
static uint8 DW_dprsmw_UnitDelay2_DSTATE_j;
static uint8 DW_dprsmw_UnitDelay5_DSTATE;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_ga;
static uint8 DW_dprsmw_UnitDelay4_DSTATE;
static uint8 DW_dprsmw_Unit_Delay4_DSTATE;
static uint8 DW_dprsmw_Unit_Delay_DSTATE_p;
static uint8 DW_dprsmw_Template_DSTATE_m;
static uint8 DW_dprsmw_Template1_DSTATE;
static uint8 DW_dprsmw_Template1_DSTATE_g;
static uint8 DW_dprsmw_Template_DSTATE_d;
static uint8 DW_dprsmw_Template_DSTATE_n;
static uint8 DW_dprsmw_Template1_DSTATE_e;
static uint8 DW_dprsmw_is_active_c14_DPRSMW_cg;
static uint8 DW_dprsmw_is_c14_DPRSMW_cg;
static uint8 DW_dprsmw_is_PRESENT;
#define DPRSMW_STOP_SEC_DATA_8
#include "DPRSMW_MemMap.h"
#define DPRSMW_START_SEC_DATA_32
#include "DPRSMW_MemMap.h"
static float32 DW_dprsmw_UnitDelay1_DSTATE;
static float32 DW_dprsmw_Unit_Delay2_DSTATE;
static float32 DW_dprsmw_Unit_Delay1_DSTATE;
static float32 DW_dprsmw_Unit_Delay_DSTATE;
static float32 DW_dprsmw_UnitDelay1_DSTATE_e;
static float32 DW_dprsmw_Unit_Delay2_DSTATE_d;
static float32 DW_dprsmw_Unit_Delay_DSTATE_d;
static float32 DW_dprsmw_UnitDelay1_DSTATE_k;
static float32 DW_dprsmw_Unit_Delay2_DSTATE_db;
static float32 DW_dprsmw_Unit_Delay1_DSTATE_p;
static float32 DW_dprsmw_Unit_Delay_DSTATE_h;
static float32 DW_dprsmw_UnitDelay1_DSTATE_b;
static float32 DW_dprsmw_Unit_Delay2_DSTATE_c;
static float32 DW_dprsmw_Unit_Delay_DSTATE_b;
static float32 DW_dprsmw_Unit_Delay_DSTATE_bk;
static float32 DW_dprsmw_UnitDelay1_DSTATE_d;
static float32 DW_dprsmw_UnitDelay1_DSTATE_ez;
static float32 DW_dprsmw_Unit_Delay3_DSTATE;
static float32 DW_dprsmw_UnitDelay1_DSTATE_o;
#define DPRSMW_STOP_SEC_DATA_32
#include "DPRSMW_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPRSMW/DPRSMW/INI'/DPRSMW_SenReset'
 * Block description for: 'sda:DPRSMW/DPRSMW/INI'/DPRSMW_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRSMW_SenReset
#include "Pse_DPRSMW.h"
/* Short description: Not synchronized with ARAMIS */
void DPRSMW_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant1'/Constant' */
    SET_S_DPRSMW_SysStateRDWRi_nu(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant10'/Constant' */
    SET_D_DPRSMW_TrcRiThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant11'/Constant' */
    SET_D_DPRSMW_DrcRiThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant12'/Constant' */
    SET_D_DPRSMW_DlcRiThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant13'/Constant' */
    SET_D_DPRSMW_TlcLeThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant14'/Constant' */
    SET_D_DPRSMW_DrcLeThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant15'/Constant' */
    SET_D_DPRSMW_TlcRiThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant16'/Constant' */
    SET_D_DPRSMW_DlcLeThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant17'/Constant' */
    SET_S_DPRSMW_ReadyToTrigger_bool(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant18'/Constant' */
    SET_D_DPRSMW_TrcLeThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant19'/Constant' */
    SET_D_DPRSMW_TriggerReLe_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant2'/Constant' */
    SET_S_DPRSMW_SysStateRDW_nu(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant20'/Constant' */
    SET_D_DPRSMW_TriggerLnReLe_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant21'/Constant' */
    SET_D_DPRSMW_TriggerLnLe_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant22'/Constant' */
    SET_D_DPRSMW_TriggerReRi_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant23'/Constant' */
    SET_D_DPRSMW_TriggerLnReRi_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant24'/Constant' */
    SET_D_DPRSMW_TriggerLnRi_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant3'/Constant' */
    SET_D_DPRSMW_SysStateRDW_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant4'/Constant' */
    SET_S_DPRSMW_DangerousSide_nu(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant5'/Constant' */
    SET_D_DPRSMW_StrongReady_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant6'/Constant' */
    SET_D_DPRSMW_Cancel_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant7'/Constant' */
    SET_D_DPRSMW_WeakReady_btf(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant8'/Constant' */
    SET_S_DPRSMW_TriggerReason_nu(0U);
    /* Constant: 'sda:DPRSMW/DPRSMW/INI/DPRSMW_SenReset/Constant9'/Constant' */
    SET_S_DPRSMW_SysStateRDWLe_nu(0U);
}
#include "Pse_DPRSMW.h"
/*
 * Output and update for function-call system: 'sda:DPRSMW/DPRSMW'/DPRSMW_SenProcess'
 * Block description for: 'sda:DPRSMW/DPRSMW'/DPRSMW_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRSMW_SenProcess
#include "Pse_DPRSMW.h"
/* Short description: Not synchronized with ARAMIS */
void DPRSMW_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_UnaryMinus;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_UnaryMinus_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_lb;
    float32 rtb_ip_lookup_fxpt_sfun_7_pn;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_pq;
    float32 rtb_Abs_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_ht;
    float32 rtb_ip_lookup_fxpt_sfun_7_go;
    float32 rtb_ip_lookup_fxpt_sfun_7_hw;
    float32 rtb_Abs_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Abs_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_cb;
    float32 rtb_Abs_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_Abs_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_bf;
    float32 rtb_ip_lookup_fxpt_sfun_7_iz;
    float32 rtb_ip_lookup_fxpt_sfun_7_fz;
    float32 rtb_ip_lookup_fxpt_sfun_7_ep;
    float32 rtb_Abs_fz;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_Abs_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_k4;
    float32 rtb_ip_lookup_fxpt_sfun_7_c0;
    float32 rtb_Abs_jq;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_Abs_b;
    float32 rtb_ip_lookup_fxpt_sfun_7_b0;
    float32 rtb_ip_lookup_fxpt_sfun_7_c1;
    float32 rtb_Abs_bn;
    float32 rtb_ip_lookup_fxpt_sfun_7_cj;
    float32 rtb_Abs_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_js;
    float32 rtb_ip_lookup_fxpt_sfun_7_oc;
    float32 rtb_ip_lookup_fxpt_sfun_7_ji;
    float32 rtb_ip_lookup_fxpt_sfun_7_hc;
    float32 rtb_Abs_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_cp;
    float32 rtb_Abs_gb;
    float32 rtb_ip_lookup_fxpt_sfun_7_e5;
    float32 rtb_ip_lookup_fxpt_sfun_7_ej;
    float32 rtb_Abs_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_hm;
    float32 rtb_Abs_gj;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_lb5;
    float32 rtb_ip_lookup_fxpt_sfun_7_gn;
    float32 rtb_ip_lookup_fxpt_sfun_7_hg;
    float32 rtb_ip_lookup_fxpt_sfun_7_pqb;
    float32 rtb_ip_lookup_fxpt_sfun_7_p5;
    float32 rtb_ip_lookup_fxpt_sfun_7_e1;
    float32 rtb_ip_lookup_fxpt_sfun_7_lu;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate_c[8];
    uint8 rtb_VectorConcatenate_n[8];
    uint8 rtb_VectorConcatenate_e[8];
    uint8 rtb_VectorConcatenate1[8];
    uint8 rtb_VectorConcatenate2[8];
    uint8 rtb_VectorConcatenate1_k[8];
    uint8 rtb_VectorConcatenate2_p[8];
    uint8 rtb_VectorConcatenate_cu[8];
    uint8 rtb_VectorConcatenate_m[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_p;
    uint8 rtb_sfun_setbit_j;
    uint8 rtb_sfun_setbit_o;
    uint8 rtb_sfun_setbit_h;
    uint8 rtb_sfun_setbit_l;
    uint8 rtb_sfun_setbit_a;
    uint8 rtb_Switch_fk;
    uint8 rtb_GT;
    uint8 rtb_LT_i5;
    uint8 rtb_DataTypeConversion_jz;
    float32 rtb_Mul_a;
    uint8 rtb_LT_bz;
    uint8 rtb_RelationalOperator1_b5;
    uint8 rtb_UnitDelay2;
    uint8 rtb_EQ_jt;
    uint8 rtb_RelationalOperator1_p;
    uint8 rtb_DataTypeConversion_g;
    uint8 rtb_DataTypeConversion_ne;
    uint8 rtb_LogicalOperator_ec;
    uint8 rtb_Switch_ig0;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_l4;
    uint8 rtb_DataTypeConversion_j0;
    uint8 rtb_DataTypeConversion_bx;
    uint8 rtb_GT_gl;
    uint8 rtb_EQ_bi;
    uint8 rtb_LT_hv;
    uint8 rtb_DataTypeConversion_og;
    float32 rtb_Mul_p;
    uint8 rtb_DataTypeConversion_d;
    uint8 rtb_GT_f3;
    uint8 rtb_DataTypeConversion_bu;
    uint8 rtb_RelationalOperator1_c;
    uint8 rtb_LT_mx;
    uint8 rtb_LogicalOperator_ia;
    uint8 rtb_Switch_k2;
    uint8 rtb_DataTypeConversion_kb;
    uint8 rtb_DataTypeConversion_m;
    uint8 rtb_LT_js;
    uint8 rtb_RelationalOperator1_g0;
    uint8 rtb_DataTypeConversion_dk;
    uint8 rtb_DataTypeConversion_na;
    uint8 rtb_LogicalOperator_a;
    uint8 rtb_Switch_bn;
    uint8 rtb_DataTypeConversion_fg;
    uint8 rtb_EQ_la;
    uint8 rtb_EQ_nh;
    uint8 rtb_DataTypeConversion_b;
    uint8 rtb_DataTypeConversion_jd;
    uint8 rtb_LT_gj;
    uint8 rtb_EQ_g3;
    uint8 rtb_LT_g4;
    uint8 rtb_DataTypeConversion_j;
    uint8 rtb_DataTypeConversion_e;
    uint8 rtb_EQ_fg;
    uint8 rtb_EQ_pa;
    uint8 rtb_RelationalOperator1_h;
    uint8 rtb_EQ_kv;
    uint8 rtb_LogicalOperator_lr;
    uint8 rtb_DataTypeConversion_cx;
    uint8 rtb_DataTypeConversion_g0;
    uint8 rtb_DataTypeConversion_pp;
    uint8 rtb_EQ_b2;
    uint8 rtb_EQ_ko;
    uint8 rtb_DataTypeConversion_dt;
    uint8 rtb_DataTypeConversion_ou;
    uint8 rtb_DataTypeConversion_ks;
    uint8 rtb_DataTypeConversion_ld;
    uint8 rtb_EQ_pz;
    uint8 rtb_EQ_nb;
    uint8 rtb_EQ_jm;
    uint8 rtb_EQ_eb;
    uint8 rtb_EQ_jf;
    uint8 rtb_EQ_mv;
    uint8 rtb_EQ_gk;
    uint8 rtb_UnitDelay1_h;
    uint8 rtb_EQ_ll0;
    uint8 rtb_DataTypeConversion_c1;
    uint8 rtb_DataTypeConversion_a;
    uint8 rtb_DataTypeConversion_dv;
    float32 rtb_Sum_hc;
    uint8 rtb_DataTypeConversion_p;
    uint8 rtb_NE_p3;
    uint8 rtb_Switch_cc;
    float32 rtb_Switch_j5;
    uint8 rtb_Switch_h;
    uint8 rtb_LogicalOperator_c;
    uint8 rtb_DataTypeConversion_dwg;
    uint8 rtb_DataTypeConversion_n;
    uint8 rtb_DataTypeConversion_c;
    uint8 rtb_DataTypeConversion_lp;
    uint8 rtb_EQ_as;
    uint8 rtb_DataTypeConversion_ml1;
    uint8 rtb_DataTypeConversion_ih;
    uint8 rtb_Switch_km;
    float32 rtb_Switch_cx;
    float32 rtb_Switch_kc;
    float32 rtb_Switch_pn;
    float32 rtb_Switch_fe;
    float32 rtb_Switch_of;
    float32 rtb_Switch2_p;
    float32 rtb_Switch2_o;
    float32 rtb_Switch_l3;
    float32 rtb_Switch2_eh;
    float32 rtb_Switch2_lk;
    float32 rtb_Switch_cy;
    float32 rtb_Switch2_bg;
    float32 rtb_Switch_i0;
    float32 rtb_Switch2_gq;
    uint8 LogicalOperator_h;
    uint8 LogicalOperator_k;
    uint8 LogicalOperator_c;
    uint8 LogicalOperator_a;
    uint8 LogicalOperator_f;
    uint8 LogicalOperator_p;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/RDWSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/RDWSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/RDWSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDWSwitch_bool'
         */
    if (((sint32)GET_P_DPRSMW_RDWSwitchEnable_bool()) != 0) {
        rtb_Switch_fk = GET_S_LCFRCV_RDWSwitch_bool();
    } else {
        rtb_Switch_fk = GET_P_DPRSMW_RDWSwitch_bool();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/RDWSwitch/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_Switch_fk;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         */
    rtb_GT = (uint8)(GET_S_DPRSIA_DrcLeRDW_met() > GET_P_DPRSMW_DrcLimitMin_met());
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDWMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Relational Operator3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ht = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD3TrigTrc_sec (), &x_dps);
        }
        rtb_Switch_cx = rtb_ip_lookup_fxpt_sfun_7_ht;
    } else if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_go = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD2TrigTrc_sec (), &x_dps);
        }
        rtb_Switch_cx = rtb_ip_lookup_fxpt_sfun_7_go;
    } else {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_hw = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD1TrigTrc_sec (), &x_dps);
        }
        rtb_Switch_cx = rtb_ip_lookup_fxpt_sfun_7_hw;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch4/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPRSMW_LWTrigTrcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Divide2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_cx *= rtb_ip_lookup_fxpt_sfun_7;
    /* UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Neg1/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDW_mps'
         */
    rtb_UnaryMinus = -GET_S_DPRSIA_VelLatReLeRDW_mps();
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigTrcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Neg/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (GET_S_ABPREP_LeReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_c = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_c, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_kc = -rtb_ip_lookup_fxpt_sfun_7_b;
    } else if (GET_S_ABPREP_LeReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_p = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_p, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_cb = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_kc = rtb_ip_lookup_fxpt_sfun_7_cb;
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Constant8'/Constant'
                 */
        rtb_Switch_kc = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Divide5/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_kc += rtb_Switch_cx * rtb_ip_lookup_fxpt_sfun_7_k;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Relational Operator2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TrcLeRDW_sec'
         */
    rtb_LT_i5 = (uint8)(GET_S_DPRSIA_TrcLeRDW_sec() < rtb_Switch_kc);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDWMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Relational Operator8/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch7/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_js = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD3TrigDrc_met (), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_js;
    } else if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_oc = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD2TrigDrc_met (), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_oc;
    } else {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ji = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD1TrigDrc_met (), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_ji;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch3/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_DPRSMW_LWTrigDrcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_a = rtb_Switch_of * rtb_ip_lookup_fxpt_sfun_7_e;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDWDrcTrgLe_met'
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Neg/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDW_DrcTriggerCustom_bool()) != 0) {
        rtb_Switch_l3 = GET_S_CUSTOM_RDWDrcTrgLe_met();
    } else {
        if (GET_S_ABPREP_LeReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_bn = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_bn, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_cj = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICDrcOffset_met(), &x_dps);
            }
            rtb_Switch_l3 = -rtb_ip_lookup_fxpt_sfun_7_cj;
        } else if (GET_S_ABPREP_LeReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_a = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_a, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCDrcOffset_met(), &x_dps);
            }
            rtb_Switch_l3 = rtb_ip_lookup_fxpt_sfun_7_d;
        } else {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Constant8'/Constant'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_l3 = 0.0F;
        }
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_c1 = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigDrcScalFact_nu(), &x_dps);
        }
        rtb_Switch_l3 += rtb_Mul_a * rtb_ip_lookup_fxpt_sfun_7_c1;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant1'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Relational Operator1/Functionality'/LT'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1'
         */
    rtb_DataTypeConversion_jz = (uint8)((((DW_dprsmw_UnitDelay1_DSTATE <= 0.0F) && (((sint32)rtb_LT_i5) != 0)) && (GET_S_DPRSIA_DrcLeRDW_met() < GET_P_DPRSMW_TrcDistanceMin_met())) || (GET_S_DPRSIA_DrcLeRDW_met() < rtb_Switch_l3));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDWDrcLimitLe_met'
         */
    if (((sint32)GET_P_RDW_DrcLimitCustom_bool()) != 0) {
        rtb_Switch2_gq = GET_S_CUSTOM_RDWDrcLimitLe_met();
    } else {
        rtb_Switch2_gq = GET_P_DPRSMW_DrcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/LT/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         */
    rtb_LT_bz = (uint8)(GET_S_DPRSIA_DrcLeRDW_met() < rtb_Switch2_gq);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator4/Functionality'/AND'
         */
    rtb_RelationalOperator1_b5 = (uint8)((((sint32)rtb_DataTypeConversion_jz) != 0) && (((sint32)rtb_LT_bz) != 0));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant9'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition6'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPRSMW_SafeSitStateRe_btm()) & 1) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMW_SafeSitStateRe_btm()) & 2) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMW_SafeSitStateRe_btm()) & 4) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMW_SafeSitStateRe_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMW_SafeSitStateRe_btm()) & 16) != 0) && (((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))))) {
        rtb_Switch_ig0 = 0U;
    } else if (GET_S_DPRSIA_DrcLeRDW_met() > (rtb_Switch_l3 + GET_P_DPRSMW_SafeSitOffsetRe_met())) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_ig0 = 1U;
    } else {
        rtb_Switch_ig0 = DW_dprsmw_Unit_Delay_DSTATE_c;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2'
         */
    rtb_LogicalOperator_ec = (uint8)((DW_dprsmw_Unit_Delay2_DSTATE <= 0.0F) && (((sint32)rtb_Switch_ig0) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs1/Functionality'/Abs'
         *  Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs2/Functionality'/Abs'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDW_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator7/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT2/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT3/Functionality'/LT'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum/Functionality'/Sum'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum1/Functionality'/Sum'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_g = (uint8)((((sint32) GET_P_DPRSMW_TrgIgnoreLnContg_bool()) != 0) || (((((((sint32) GET_P_DPRSMW_LnOverlapEnable_bool()) != 0) && ((GET_S_DPRSIA_DrcLeRDW_met() - GET_S_DPRSIA_DlcLeRDW_met()) > (-GET_P_DPRSMW_LnOverlapInnerDist_met()))) && ((GET_S_DPRSIA_DrcLeRDW_met() - GET_S_DPRSIA_DlcLeRDW_met()) < GET_P_DPRSMW_LnOverlapOuterDist_met())) && (f32_abs_f32 (GET_S_ABPLBP_LeLnClthCrv_1pm()) < GET_P_DPRSMW_LnOverlapCrv_1pm())) && (f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm()) < GET_P_DPRSMW_LnOverlapCrv_1pm ())));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ3/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((((sint32)rtb_RelationalOperator1_b5) != 0) && (((sint32)rtb_LogicalOperator_ec) != 0)) && ((((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))))) && (((sint32) rtb_DataTypeConversion_g) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2'/Unit_Delay'
         */
    LogicalOperator_c = (uint8)((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_a) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Constant1'/Constant'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay1'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_eh = DW_dprsmw_Unit_Delay1_DSTATE;
    } else {
        rtb_Switch2_eh = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec6'/Constant'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_c) != 0) {
        rtb_Switch2_eh = GET_P_DPRSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
                         */
            if (rtb_Switch2_eh > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_eh -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_eh = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter5'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator6/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/NOT3/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_ne = (uint8)(((((sint32)rtb_DataTypeConversion) != 0) || (!(((sint32)GET_P_DPRSMW_TriggerAlwaysOn_bool()) != 0))) && (rtb_Switch2_eh > 0.0F));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDWLe_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND5/Functionality'/AND'
         */
    rtb_EQ_jt = (uint8)((((sint32)GET_S_DPRSIA_SideCondRDWLe_btf()) & ((sint32) GET_P_DPRSMW_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND1/Functionality'/AND'
         */
    rtb_EQ_l4 = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMW_FctCustomTrgLe_btm())) == 0);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_j0 = (uint8)((((((sint32)rtb_GT) != 0) && (((sint32) rtb_DataTypeConversion_ne) != 0)) && (((sint32)rtb_EQ_jt) != 0)) && (((sint32)rtb_EQ_l4) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator16/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator16/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_bx = (uint8)((((((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) && (((sint32) rtb_RelationalOperator1_b5) != 0)) && (((sint32)rtb_LogicalOperator_ec) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3'/Unit_Delay'
         */
    LogicalOperator_k = (uint8)((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_f) != 0)) && (((sint32)rtb_DataTypeConversion_bx) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_lk = DW_dprsmw_Unit_Delay_DSTATE;
    } else {
        rtb_Switch2_lk = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec5'/Constant'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_k) != 0) {
        rtb_Switch2_lk = GET_P_DPRSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_lk > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_lk -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_lk = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_b5 = (uint8)(rtb_Switch2_lk > 0.0F);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/GT1/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDW_met'
         */
    rtb_GT_gl = (uint8)(GET_S_DPRSIA_DlcLeRDW_met() > GET_P_DPRSMW_DlcLimitMin_met());
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EQ3/Functionality'/EQ'
         */
    rtb_EQ_bi = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDWMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_iz = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD3TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_iz;
    } else if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_fz = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD2TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_fz;
    } else {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ep = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD1TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_ep;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_DPRSMW_LWTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Divide2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_of *= rtb_ip_lookup_fxpt_sfun_7_p;
    /* UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Neg4/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDW_mps'
         */
    rtb_UnaryMinus_n = -GET_S_DPRSIA_VelLatLnLeRDW_mps();
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus_n, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Neg/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_LeLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_fz = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_fz, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_pn = -rtb_ip_lookup_fxpt_sfun_7_j;
    } else if (GET_S_ABPLBP_LeLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_j = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_j, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_k4 = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_pn = rtb_ip_lookup_fxpt_sfun_7_k4;
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant8'/Constant'
                 */
        rtb_Switch_pn = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Divide5/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_pn += rtb_Switch_of * rtb_ip_lookup_fxpt_sfun_7_h;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Relational Operator5/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TlcLeRDW_sec'
         */
    rtb_LT_hv = (uint8)(GET_S_DPRSIA_TlcLeRDW_sec() < rtb_Switch_pn);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDWMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator8/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch7/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_lb5 = F32_PTR_IP1D (GETA_Y_DPRSMW_VXMD3TrigDlc_met(), &x_dps);
        }
        rtb_Switch_fe = rtb_ip_lookup_fxpt_sfun_7_lb5;
    } else if (((sint32)GET_S_LCFRCV_RDWMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_gn = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD2TrigDlc_met (), &x_dps);
        }
        rtb_Switch_fe = rtb_ip_lookup_fxpt_sfun_7_gn;
    } else {
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_hg = F32_PTR_IP1D(GETA_Y_DPRSMW_VXMD1TrigDlc_met (), &x_dps);
        }
        rtb_Switch_fe = rtb_ip_lookup_fxpt_sfun_7_hg;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_DPRSMW_LWTrigDlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_p = rtb_Switch_fe * rtb_ip_lookup_fxpt_sfun_7_l;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDWDlcTrgLe_met'
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Neg/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDW_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_cy = GET_S_CUSTOM_RDWDlcTrgLe_met();
    } else {
        if (GET_S_ABPLBP_LeLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_i = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_i, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_hm = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_cy = -rtb_ip_lookup_fxpt_sfun_7_hm;
        } else if (GET_S_ABPLBP_LeLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_gj = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_gj, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_cy = rtb_ip_lookup_fxpt_sfun_7_m;
        } else {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant8'/Constant'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_cy = 0.0F;
        }
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus_n, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ej = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_cy += rtb_Mul_p * rtb_ip_lookup_fxpt_sfun_7_ej;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDWDlcLimitLe_met'
         */
    if (((sint32)GET_P_RDW_DlcLimitCustom_bool()) != 0) {
        rtb_Switch2_gq = GET_S_CUSTOM_RDWDlcLimitLe_met();
    } else {
        rtb_Switch2_gq = GET_P_DPRSMW_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator3/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Relational Operator3/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1'
         */
    rtb_DataTypeConversion_og = (uint8)(((((DW_dprsmw_UnitDelay1_DSTATE_e <= 0.0F) && (((sint32)rtb_LT_hv) != 0)) && (GET_S_DPRSIA_DlcLeRDW_met() < GET_P_DPRSMW_TlcDistanceMin_met())) || (GET_S_DPRSIA_DlcLeRDW_met() < rtb_Switch_cy)) && (GET_S_DPRSIA_DlcLeRDW_met() < rtb_Switch2_gq));
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDW_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         */
    rtb_Switch_fe = GET_S_DPRSIA_DrcLeRDW_met() - GET_S_DPRSIA_DlcLeRDW_met();
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Relational Operator4/Functionality'/LT'
         */
    rtb_DataTypeConversion_d = (uint8)((rtb_Switch_fe < GET_P_DPRSMW_LnMrkRdEdgeDistMax_met()) && (rtb_Switch_fe > GET_P_DPRSMW_LnMrkRdEdgeDistMin_met()));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant9'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPRSMW_SafeSitStateLn_btm()) & 1) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMW_SafeSitStateLn_btm()) & 2) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMW_SafeSitStateLn_btm()) & 4) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMW_SafeSitStateLn_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMW_SafeSitStateLn_btm()) & 16) != 0) && (!(((sint32) rtb_EQ_bi) != 0)))) {
        rtb_Switch_k2 = 0U;
    } else if (GET_S_DPRSIA_DlcLeRDW_met() > (rtb_Switch_cy + GET_P_DPRSMW_SafeSitOffsetLn_met())) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_k2 = 1U;
    } else {
        rtb_Switch_k2 = DW_dprsmw_Unit_Delay_DSTATE_k;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
         */
    rtb_LogicalOperator_ia = (uint8)((DW_dprsmw_Unit_Delay2_DSTATE_d <= 0.0F) && (((sint32)rtb_Switch_k2) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator17/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator17/Functionality'/AND'
         */
    rtb_DataTypeConversion_kb = (uint8)((((((sint32)rtb_EQ_bi) != 0) && (((sint32)rtb_DataTypeConversion_og) != 0)) && (((sint32) rtb_DataTypeConversion_d) != 0)) && (((sint32)rtb_LogicalOperator_ia) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1'/Unit_Delay'
         */
    LogicalOperator_h = (uint8)((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_ks) != 0)) && (((sint32)rtb_DataTypeConversion_kb) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit_Delay'
         */
    if (((sint32)rtb_GT_gl) >= 1) {
        rtb_Switch2_bg = DW_dprsmw_Unit_Delay_DSTATE_d;
    } else {
        rtb_Switch2_bg = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_h) != 0) {
        rtb_Switch2_bg = GET_P_DPRSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT_gl) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_bg > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_bg -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_bg = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_c = (uint8)(rtb_Switch2_bg > 0.0F);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator15/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter3'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator10/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator15/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/NOT2/Functionality'/NOT'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_m = (uint8)(((((sint32)rtb_DataTypeConversion_j0) != 0) || ((((((sint32)rtb_GT) != 0) && (((((sint32)rtb_DataTypeConversion_bx) != 0) || (!(((sint32)GET_P_DPRSMW_TriggerAlwaysOn_bool()) != 0))) && (((sint32)rtb_RelationalOperator1_b5) != 0))) && (((sint32)rtb_EQ_jt) != 0)) && (((sint32)rtb_EQ_l4) != 0))) || ((((((sint32)rtb_GT_gl) != 0) && (((((sint32)rtb_DataTypeConversion_kb) != 0) || (!(((sint32) GET_P_DPRSMW_TriggerAlwaysOn_bool()) != 0))) && (((sint32) rtb_RelationalOperator1_c) != 0))) && (((sint32)rtb_EQ_jt) != 0)) && (((sint32)rtb_EQ_l4) != 0)));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Neg4/Functionality'/Unary Minus'
         */
    rtb_LT_js = (uint8)(GET_S_DPRSIA_DrcRiRDW_met() < (-GET_P_DPRSMW_DrcLimitMin_met()));
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatReRiRDW_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigTrcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (GET_S_ABPREP_RiReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_pq = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_fe = -rtb_ip_lookup_fxpt_sfun_7_pq;
    } else if (GET_S_ABPREP_RiReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_g = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_g, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_fe = rtb_ip_lookup_fxpt_sfun_7_g;
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Constant9'/Constant'
                 */
        rtb_Switch_fe = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDW_mps'
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Divide6/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_fe += rtb_Switch_cx * rtb_ip_lookup_fxpt_sfun_7_f;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Relational Operator6/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TrcRiRDW_sec'
         */
    rtb_LT_mx = (uint8)(GET_S_DPRSIA_TrcRiRDW_sec() < rtb_Switch_fe);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDWDrcTrgRi_met'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDW_mps'
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDW_DrcTriggerCustom_bool()) != 0) {
        rtb_Switch_cx = GET_S_CUSTOM_RDWDrcTrgRi_met();
    } else {
        if (GET_S_ABPREP_RiReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm ())) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_jq = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_jq, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICDrcOffset_met(), &x_dps);
            }
            rtb_Switch_i0 = -rtb_ip_lookup_fxpt_sfun_7_o;
        } else if (GET_S_ABPREP_RiReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_b = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_b, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_b0 = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCDrcOffset_met(), &x_dps);
            }
            rtb_Switch_i0 = rtb_ip_lookup_fxpt_sfun_7_b0;
        } else {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Constant9'/Constant'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_i0 = 0.0F;
        }
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatReRiRDW_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_c0 = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigDrcScalFact_nu(), &x_dps);
        }
        rtb_Switch_cx = (rtb_Mul_a * rtb_ip_lookup_fxpt_sfun_7_c0) + rtb_Switch_i0;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Switch8/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch11'/copy1' incorporates:
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Neg4/Functionality'/Unary Minus'
         */
    SET_D_DPRSMW_DrcRiThreshold_met(-rtb_Switch_cx);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
                                                       *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter4'/Constant'
                                                       *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant1'
                                                       *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
                                                       *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator2/Functionality'/AND'
                                                       *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator3/Functionality'/OR'
                                                       *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Logical Operator'
                                                       *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/GT1/Functionality'/GT'
                                                       *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Relational Operator2/Functionality'/GT'
                                                       *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator1'
                                                       *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Neg3/Functionality'/Unary Minus'
                                                       *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Neg4/Functionality'/Unary Minus'
                                                       *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1'
                                                       */
    rtb_DataTypeConversion_bu = (uint8)((((DW_dprsmw_UnitDelay1_DSTATE_k <= 0.0F) && (((sint32)rtb_LT_mx) != 0)) && (GET_S_DPRSIA_DrcRiRDW_met() > (-GET_P_DPRSMW_TrcDistanceMin_met()))) || (GET_S_DPRSIA_DrcRiRDW_met() > (-rtb_Switch_cx)));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDWDrcLimitRi_met'
         */
    if (((sint32)GET_P_RDW_DrcLimitCustom_bool()) != 0) {
        rtb_Switch2_gq = GET_S_CUSTOM_RDWDrcLimitRi_met();
    } else {
        rtb_Switch2_gq = GET_P_DPRSMW_DrcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Relational Operator1/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Neg2/Functionality'/Unary Minus'
         */
    rtb_GT_f3 = (uint8)(GET_S_DPRSIA_DrcRiRDW_met() > (-rtb_Switch2_gq));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator4/Functionality'/AND'
         */
    rtb_EQ_bi = (uint8)((((sint32)rtb_DataTypeConversion_bu) != 0) && (((sint32) rtb_GT_f3) != 0));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Constant9'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/from_data_definition6'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RSFLIPFLOP/Functionality'/Switch1'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DrcThresholds/Neg4/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay2'
         */
    if (((((((((sint32)GET_P_DPRSMW_SafeSitStateRe_btm()) & 1) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMW_SafeSitStateRe_btm()) & 2) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMW_SafeSitStateRe_btm()) & 4) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMW_SafeSitStateRe_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMW_SafeSitStateRe_btm()) & 16) != 0) && (((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))))) {
        rtb_Switch_bn = 0U;
    } else if (GET_S_DPRSIA_DrcRiRDW_met() < ((-rtb_Switch_cx) - GET_P_DPRSMW_SafeSitOffsetRe_met())) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_bn = 1U;
    } else {
        rtb_Switch_bn = DW_dprsmw_Unit_Delay_DSTATE_o;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi'/Unit_Delay2'
         */
    rtb_LogicalOperator_a = (uint8)((DW_dprsmw_Unit_Delay2_DSTATE_db <= 0.0F) && (((sint32)rtb_Switch_bn) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs1/Functionality'/Abs'
         *  Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs2/Functionality'/Abs'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDW_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator7/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT2/Functionality'/LT'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum/Functionality'/Sum'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum3/Functionality'/Sum'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Neg1/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_dk = (uint8)((((sint32) GET_P_DPRSMW_TrgIgnoreLnContg_bool()) != 0) || (((((((sint32) GET_P_DPRSMW_LnOverlapEnable_bool()) != 0) && ((GET_S_DPRSIA_DrcRiRDW_met() - GET_S_DPRSIA_DlcRiRDW_met()) < GET_P_DPRSMW_LnOverlapInnerDist_met())) && ((GET_S_DPRSIA_DrcRiRDW_met() - GET_S_DPRSIA_DlcRiRDW_met()) > (-GET_P_DPRSMW_LnOverlapOuterDist_met()))) && (f32_abs_f32 (GET_S_ABPLBP_RiLnClthCrv_1pm()) < GET_P_DPRSMW_LnOverlapCrv_1pm())) && (f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm()) < GET_P_DPRSMW_LnOverlapCrv_1pm ())));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ3/Functionality'/EQ'
         */
    rtb_DataTypeConversion_fg = (uint8)((((((sint32)rtb_EQ_bi) != 0) && (((sint32)rtb_LogicalOperator_a) != 0)) && ((((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))))) && (((sint32) rtb_DataTypeConversion_dk) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter5'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator6/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/NOT3/Functionality'/NOT'
         */
    rtb_DataTypeConversion_na = (uint8)((((sint32)rtb_DataTypeConversion_fg) != 0) || (!(((sint32)GET_P_DPRSMW_TriggerAlwaysOn_bool()) != 0)));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3'/Unit_Delay'
         */
    LogicalOperator_p = (uint8)((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_g) != 0)) && (((sint32)rtb_DataTypeConversion_fg) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Constant1'/Constant'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay1'
         */
    if (((sint32)rtb_LT_js) >= 1) {
        rtb_Mul_a = DW_dprsmw_Unit_Delay1_DSTATE_p;
    } else {
        rtb_Mul_a = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec7'/Constant'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_p) != 0) {
        rtb_Mul_a = GET_P_DPRSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_js) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
                         */
            if (rtb_Mul_a > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Mul_a -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Mul_a = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant'
         */
    rtb_RelationalOperator1_g0 = (uint8)(rtb_Mul_a > 0.0F);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDWRi_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND5/Functionality'/AND'
         */
    rtb_EQ_la = (uint8)((((sint32)GET_S_DPRSIA_SideCondRDWRi_btf()) & ((sint32) GET_P_DPRSMW_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND1/Functionality'/AND'
         */
    rtb_EQ_nh = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMW_FctCustomTrgRi_btm())) == 0);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/AND1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_b = (uint8)((((((sint32)rtb_LT_js) != 0) && ((((sint32)rtb_DataTypeConversion_na) != 0) && (((sint32) rtb_RelationalOperator1_g0) != 0))) && (((sint32)rtb_EQ_la) != 0)) && (((sint32)rtb_EQ_nh) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator19/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator19/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_jd = (uint8)((((((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) && (((sint32) rtb_EQ_bi) != 0)) && (((sint32)rtb_LogicalOperator_a) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2'/Unit_Delay'
         */
    LogicalOperator_f = (uint8)((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_de) != 0)) && (((sint32)rtb_DataTypeConversion_jd) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay'
         */
    if (((sint32)rtb_LT_js) >= 1) {
        rtb_Switch_i0 = DW_dprsmw_Unit_Delay_DSTATE_h;
    } else {
        rtb_Switch_i0 = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec6'/Constant'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_f) != 0) {
        rtb_Switch_i0 = GET_P_DPRSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_js) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch_i0 > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch_i0 -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch_i0 = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_p = (uint8)(rtb_Switch_i0 > 0.0F);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDW_met'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Neg4/Functionality'/Unary Minus'
         */
    rtb_LT_gj = (uint8)(GET_S_DPRSIA_DlcRiRDW_met() < (-GET_P_DPRSMW_DlcLimitMin_met()));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EQ3/Functionality'/EQ'
         */
    rtb_EQ_g3 = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))));
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatLnRiRDW_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Divide6/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDW_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_cx = rtb_Switch_of * rtb_ip_lookup_fxpt_sfun_7_c;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_RiLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs_f = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_f, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_of = -rtb_ip_lookup_fxpt_sfun_7_i;
    } else if (GET_S_ABPLBP_RiLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_d = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_d, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_bf = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_of = rtb_ip_lookup_fxpt_sfun_7_bf;
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Constant9'/Constant'
                 */
        rtb_Switch_of = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/TlcThresholds/Sum1/Functionality'/Sum' */
    rtb_Switch_of += rtb_Switch_cx;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator1/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TlcRiRDW_sec'
         */
    rtb_LT_g4 = (uint8)(GET_S_DPRSIA_TlcRiRDW_sec() < rtb_Switch_of);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDWDlcTrgRi_met'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDW_mps'
         *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDW_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_cx = GET_S_CUSTOM_RDWDlcTrgRi_met();
    } else {
        if (GET_S_ABPLBP_RiLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm ())) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_e = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_e, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_cp = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_cx = -rtb_ip_lookup_fxpt_sfun_7_cp;
        } else if (GET_S_ABPLBP_RiLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_gb = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_gb, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_e5 = F32_PTR_IP1D (GETA_Y_DPRSMW_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_cx = rtb_ip_lookup_fxpt_sfun_7_e5;
        } else {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Constant9'/Constant'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_cx = 0.0F;
        }
        /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatLnRiRDW_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_hc = F32_PTR_IP1D (GETA_Y_DPRSMW_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_cx += rtb_Mul_p * rtb_ip_lookup_fxpt_sfun_7_hc;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' */
    /* UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus' */
    rtb_Mul_p = -rtb_Switch_cx;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDWDlcLimitRi_met'
         */
    if (((sint32)GET_P_RDW_DlcLimitCustom_bool()) != 0) {
        rtb_Switch2_gq = GET_S_CUSTOM_RDWDlcLimitRi_met();
    } else {
        rtb_Switch2_gq = GET_P_DPRSMW_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator4/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Neg1/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Neg3/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1'
         */
    rtb_DataTypeConversion_j = (uint8)(((((DW_dprsmw_UnitDelay1_DSTATE_b <= 0.0F) && (((sint32)rtb_LT_g4) != 0)) && (GET_S_DPRSIA_DlcRiRDW_met() > (-GET_P_DPRSMW_TlcDistanceMin_met()))) || (GET_S_DPRSIA_DlcRiRDW_met() > (-rtb_Switch_cx))) && (GET_S_DPRSIA_DlcRiRDW_met() > (-rtb_Switch2_gq)));
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDW_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         */
    rtb_Switch_cx = GET_S_DPRSIA_DlcRiRDW_met() - GET_S_DPRSIA_DrcRiRDW_met();
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec4'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator5/Functionality'/LT'
         */
    rtb_DataTypeConversion_e = (uint8)((rtb_Switch_cx < GET_P_DPRSMW_LnMrkRdEdgeDistMax_met()) && (rtb_Switch_cx > GET_P_DPRSMW_LnMrkRdEdgeDistMin_met()));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant9'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay2'
         */
    if (((((((((sint32)GET_P_DPRSMW_SafeSitStateLn_btm()) & 1) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMW_SafeSitStateLn_btm()) & 2) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMW_SafeSitStateLn_btm()) & 4) != 0) && (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMW_SafeSitStateLn_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMW_SafeSitStateLn_btm()) & 16) != 0) && (!(((sint32) rtb_EQ_g3) != 0)))) {
        rtb_UnitDelay2 = 0U;
    } else if (GET_S_DPRSIA_DlcRiRDW_met() < (rtb_Mul_p - GET_P_DPRSMW_SafeSitOffsetLn_met())) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_UnitDelay2 = 1U;
    } else {
        rtb_UnitDelay2 = DW_dprsmw_Unit_Delay_DSTATE_n;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
         */
    rtb_LogicalOperator_lr = (uint8)((DW_dprsmw_Unit_Delay2_DSTATE_c <= 0.0F) && (((sint32)rtb_UnitDelay2) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator20/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator20/Functionality'/AND'
         */
    rtb_DataTypeConversion_cx = (uint8)((((((sint32)rtb_EQ_g3) != 0) && (((sint32)rtb_DataTypeConversion_j) != 0)) && (((sint32) rtb_DataTypeConversion_e) != 0)) && (((sint32)rtb_LogicalOperator_lr) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1'/Unit_Delay'
         */
    LogicalOperator_a = (uint8)((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_ki) != 0)) && (((sint32)rtb_DataTypeConversion_cx) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit_Delay'
         */
    if (((sint32)rtb_LT_gj) >= 1) {
        rtb_Switch2_gq = DW_dprsmw_Unit_Delay_DSTATE_b;
    } else {
        rtb_Switch2_gq = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_a) != 0) {
        rtb_Switch2_gq = GET_P_DPRSMW_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_gj) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_gq > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_gq -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_gq = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_h = (uint8)(rtb_Switch2_gq > 0.0F);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator15/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter3'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator10/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator15/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND1/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/NOT2/Functionality'/NOT'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/AND2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/NOT2/Functionality'/NOT'
         */
    rtb_DataTypeConversion_g0 = (uint8)(((((sint32)rtb_DataTypeConversion_b) != 0) || ((((((sint32)rtb_LT_js) != 0) && (((((sint32)rtb_DataTypeConversion_jd) != 0) || (!(((sint32)GET_P_DPRSMW_TriggerAlwaysOn_bool()) != 0))) && (((sint32)rtb_RelationalOperator1_p) != 0))) && (((sint32)rtb_EQ_la) != 0)) && (((sint32)rtb_EQ_nh) != 0))) || ((((((sint32)rtb_LT_gj) != 0) && (((((sint32)rtb_DataTypeConversion_cx) != 0) || (!(((sint32) GET_P_DPRSMW_TriggerAlwaysOn_bool()) != 0))) && (((sint32) rtb_RelationalOperator1_h) != 0))) && (((sint32)rtb_EQ_la) != 0)) && (((sint32)rtb_EQ_nh) != 0)));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_pp = (uint8)((((sint32)rtb_DataTypeConversion_m) != 0) || (((sint32)rtb_DataTypeConversion_g0) != 0));
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_pp;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND1/Functionality'/AND'
         */
    rtb_EQ_kv = (uint8)((((sint32)GET_S_DPRSIA_SpecificRDW_btf()) & ((sint32) GET_P_DPRSMW_StrgRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND3/Functionality'/AND'
         */
    rtb_EQ_pa = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMW_StrgRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter13'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND6/Functionality'/AND'
         */
    rtb_EQ_fg = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPRSMW_StrgRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND2/Functionality'/AND'
         */
    rtb_EQ_g3 = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMW_StrgRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND4/Functionality'/AND'
         */
    rtb_EQ_bi = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPRSMW_StrgRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND5/Functionality'/AND'
         */
    rtb_EQ_b2 = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPRSMW_StrgRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/AND7/Functionality'/AND'
         */
    rtb_EQ_ko = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMW_StrgRdyFctCustom_btm())) == 0);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDW_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Abort/AND4/Functionality'/AND'
         */
    rtb_DataTypeConversion_dt = (uint8)((((((((((sint32) GET_S_DPRSIA_SpecificRDW_btf()) & ((sint32)GET_P_DPRSMW_AbortSpecific_btm())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMW_AbortVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPRSMW_AbortDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMW_AbortFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPRSMW_AbortFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPRSMW_AbortFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMW_AbortFctCustom_btm())) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ou = (uint8)(!(((sint32)rtb_DataTypeConversion_dt) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_ks = (uint8)((((((((((sint32)rtb_EQ_kv) != 0) && (((sint32)rtb_EQ_pa) != 0)) && (((sint32)rtb_EQ_fg) != 0)) && (((sint32) rtb_EQ_g3) != 0)) && (((sint32)rtb_EQ_bi) != 0)) && (((sint32)rtb_EQ_b2) != 0)) && (((sint32)rtb_EQ_ko) != 0)) && (((sint32)rtb_DataTypeConversion_ou) != 0));
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion_ks;
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Not1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDW_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Not1/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Suppresion/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_ld = (uint8)(!((((((((((sint32) GET_S_DPRSIA_SpecificRDW_btf()) & ((sint32)GET_P_DPRSMW_SuppressSpecific_btm ())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMW_SuppressVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPRSMW_SuppressDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMW_SuppressFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPRSMW_SuppressFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPRSMW_SuppressFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMW_SuppressFctCustom_btm())) != 0)));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter17'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND4/Functionality'/AND'
         */
    rtb_EQ_pz = (uint8)((((sint32)GET_S_DPRSIA_SpecificRDW_btf()) & ((sint32) GET_P_DPRSMW_WeakRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND6/Functionality'/AND'
         */
    rtb_EQ_nb = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMW_WeakRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND2/Functionality'/AND'
         */
    rtb_EQ_jm = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPRSMW_WeakRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND5/Functionality'/AND'
         */
    rtb_EQ_eb = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMW_WeakRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter16'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND7/Functionality'/AND'
         */
    rtb_EQ_jf = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPRSMW_WeakRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter15'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND8/Functionality'/AND'
         */
    rtb_EQ_mv = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPRSMW_WeakRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/AND1/Functionality'/AND'
         */
    rtb_EQ_gk = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMW_WeakRdyFctCustom_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/RelatOperator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/from_data_definition1'/state_source'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady'/Unit Delay1'
         */
    rtb_EQ_ll0 = (uint8)(((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/P_LDPSA_BlockingTimeDuration_sec1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template'
         */
    if ((((sint32)DW_dprsmw_Template_DSTATE) != 0) && (!(((sint32)rtb_EQ_ll0) != 0))) {
        rtb_Switch2_p = GET_P_DPRSMW_BlockingTimeDuration_sec();
    } else if (DW_dprsmw_Unit_Delay_DSTATE_bk > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
                 */
        rtb_Switch2_p = DW_dprsmw_Unit_Delay_DSTATE_bk - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_p = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Not/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/OR/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/OR2/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Not/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady'/Unit Delay1'
         */
    rtb_DataTypeConversion_c1 = (uint8)(!(((((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32)rtb_EQ_ll0) != 0)) || (rtb_Switch2_p > 0.0F)));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_a = (uint8)(((((((((((sint32) rtb_DataTypeConversion_ld) != 0) && (((sint32)rtb_EQ_pz) != 0)) && (((sint32) rtb_EQ_nb) != 0)) && (((sint32)rtb_EQ_jm) != 0)) && (((sint32)rtb_EQ_eb) != 0)) && (((sint32)rtb_EQ_jf) != 0)) && (((sint32)rtb_EQ_mv) != 0)) && (((sint32)rtb_EQ_gk) != 0)) && (((sint32)rtb_DataTypeConversion_c1) != 0));
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_a;
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_dv = (uint8)(!(((sint32)rtb_DataTypeConversion_ks) != 0));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND1/Functionality'/AND'
         */
    rtb_sfun_setbit_l = (uint8)((((sint32)GET_P_DPRSMW_FinishCondEnable_btm()) & 1) == 0);
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_lb = F32_PTR_IP1D (GETA_Y_DPRSMW_LWHazardFinishTol_met(), &x_dps);
    }
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_cx = GET_P_DPRSMW_TgtTrajPosY0_met() - rtb_ip_lookup_fxpt_sfun_7_lb;
    /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_pn = F32_PTR_IP1D (GETA_Y_DPRSMW_LWNoHazardFinishTol_met(), &x_dps);
    }
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_hc = GET_P_DPRSMW_TgtTrajPosY0_met() + rtb_ip_lookup_fxpt_sfun_7_pn;
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant7'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND2/Functionality'/AND'
         */
    rtb_NE_p3 = (uint8)((((sint32)GET_P_DPRSMW_FinishCondEnable_btm()) & 2) == 0);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ3/Functionality'/EQ'
         */
    rtb_Switch_cc = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPREP_LeReHeading_rad'
         */
    if (((sint32)rtb_Switch_cc) != 0) {
        rtb_Switch_j5 = GET_S_ABPREP_LeReHeading_rad();
    } else {
        rtb_Switch_j5 = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad3'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator11/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg5/Functionality'/Unary Minus'
         */
    rtb_Switch_h = (uint8)((rtb_Switch_j5 < GET_P_DPRSMW_NoHazardFinishHeadAng_rad()) && (rtb_Switch_j5 > (-GET_P_DPRSMW_HazardFinishHeadAng_rad())));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR1/Functionality'/OR'
         */
    rtb_Switch_h = (uint8)((((sint32)rtb_NE_p3) != 0) || (((sint32)rtb_Switch_h) != 0));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND3/Functionality'/AND'
         */
    rtb_sfun_setbit_p = (uint8)((((sint32)GET_P_DPRSMW_FinishCondEnable_btm()) & 4) == 0);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDW_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDW_mps'
         */
    if (((sint32)rtb_Switch_cc) != 0) {
        rtb_Switch_j5 = GET_S_DPRSIA_VelLatReLeRDW_mps();
    } else {
        rtb_Switch_j5 = GET_S_DPRSIA_VelLatLnLeRDW_mps();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant5'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Constant8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/AND4/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((sint32)GET_P_DPRSMW_FinishCondEnable_btm()) & 8) == 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/from_data_definition'/state_source'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay1'
         */
    rtb_UnitDelay1_h = (uint8)(((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/P_LDPSA_TargetLateralHeading_rad'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW'/Unit Delay1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW'/Unit_Delay'
         */
    if ((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_ga) != 0)) && (((sint32) rtb_UnitDelay1_h) != 0)) {
        rtb_Switch2_o = GET_P_DPRSMW_FinishMinDuration_sec();
    } else if (DW_dprsmw_UnitDelay1_DSTATE_ez > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW'/Unit Delay1'
                 */
        rtb_Switch2_o = DW_dprsmw_UnitDelay1_DSTATE_ez - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_o = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_sfun_setbit_o = (uint8)((rtb_Switch2_o > 0.0F) && (((sint32) rtb_UnitDelay1_h) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/NOT/Functionality'/NOT'
         */
    rtb_sfun_setbit_o = (uint8)(!(((sint32)rtb_sfun_setbit_o) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR8/Functionality'/OR'
         */
    rtb_sfun_setbit_j = (uint8)((((sint32)rtb_sfun_setbit) != 0) || (((sint32) rtb_sfun_setbit_o) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator4/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator5/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator2/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator5/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator6/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg6/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_sfun_setbit_j = (uint8)(((((((sint32)DW_dprsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((sint32)rtb_sfun_setbit_l) != 0) || ((GET_S_DPRSIA_DrcLeRDW_met() > rtb_Switch_cx) && (GET_S_DPRSIA_DrcLeRDW_met() < rtb_Sum_hc)))) && (((sint32) rtb_Switch_h) != 0)) && ((((sint32)rtb_sfun_setbit_p) != 0) || ((rtb_Switch_j5 < GET_P_DPRSMW_NoHazardFinishVelLat_mps()) && (rtb_Switch_j5 > (-GET_P_DPRSMW_HazardFinishVelLat_mps()))))) && (((sint32) rtb_sfun_setbit_j) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator6/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator7/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator9/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg4/Functionality'/Unary Minus'
         */
    rtb_Switch_h = (uint8)((GET_S_DPRSIA_DrcRiRDW_met() < (-rtb_Switch_cx)) && (GET_S_DPRSIA_DrcRiRDW_met() > (-rtb_Sum_hc)));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR2/Functionality'/OR'
         */
    rtb_Switch_h = (uint8)((((sint32)rtb_sfun_setbit_l) != 0) || (((sint32) rtb_Switch_h) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/EQ5/Functionality'/EQ'
         */
    rtb_Switch_cc = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPREP_RiReHeading_rad'
         */
    if (((sint32)rtb_Switch_cc) != 0) {
        rtb_Switch_j5 = GET_S_ABPREP_RiReHeading_rad();
    } else {
        rtb_Switch_j5 = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad4'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator10/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator8/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg3/Functionality'/Unary Minus'
         */
    rtb_NE_p3 = (uint8)((((sint32)rtb_NE_p3) != 0) || ((rtb_Switch_j5 > (-GET_P_DPRSMW_NoHazardFinishHeadAng_rad())) && (rtb_Switch_j5 < GET_P_DPRSMW_HazardFinishHeadAng_rad())));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDW_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDW_mps'
         */
    if (((sint32)rtb_Switch_cc) != 0) {
        rtb_Switch_j5 = GET_S_DPRSIA_VelLatReRiRDW_mps();
    } else {
        rtb_Switch_j5 = GET_S_DPRSIA_VelLatLnRiRDW_mps();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps3'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator11/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator12/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator13/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Neg1/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit_p = (uint8)((((sint32)rtb_sfun_setbit_p) != 0) || ((rtb_Switch_j5 > (-GET_P_DPRSMW_NoHazardFinishVelLat_mps())) && (rtb_Switch_j5 < GET_P_DPRSMW_HazardFinishVelLat_mps())));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/OR9/Functionality'/OR'
         */
    rtb_sfun_setbit_o = (uint8)((((sint32)rtb_sfun_setbit) != 0) || (((sint32) rtb_sfun_setbit_o) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition2'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator4/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_sfun_setbit_o = (uint8)(((((((sint32)DW_dprsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32)rtb_Switch_h) != 0)) && (((sint32)rtb_NE_p3) != 0)) && (((sint32) rtb_sfun_setbit_p) != 0)) && (((sint32)rtb_sfun_setbit_o) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/OR'
         */
    rtb_sfun_setbit_j = (uint8)((((sint32)rtb_sfun_setbit_j) != 0) || (((sint32) rtb_sfun_setbit_o) != 0));
    /* Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
         */
    rtb_LogicalOperator_c = (uint8)((DW_dprsmw_UnitDelay1_DSTATE_d <= 0.0F) && (((sint32)rtb_sfun_setbit_j) != 0));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND1/Functionality'/AND'
         */
    rtb_sfun_setbit_o = (uint8)((((sint32)GET_S_DPRSIA_SpecificRDW_btf()) & ((sint32)GET_P_DPRSMW_CancelSpecific_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND3/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32)GET_P_DPRSMW_CancelVehSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ6/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND7/Functionality'/AND'
         */
    rtb_sfun_setbit_p = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPRSMW_CancelDrvSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND2/Functionality'/AND'
         */
    rtb_Switch_h = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMW_CancelFctStCtr_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND4/Functionality'/AND'
         */
    rtb_Switch_cc = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPRSMW_CancelFctStErr_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ4/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND5/Functionality'/AND'
         */
    rtb_NE_p3 = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPRSMW_CancelFctStNotAv_btm())) != 0);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/OR4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/EQ3/Functionality'/EQ'
         */
    rtb_DataTypeConversion_p = (uint8)((((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDW_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDW_met'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDW_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDW_mps'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_p) != 0) {
        rtb_Switch_j5 = GET_S_DPRSIA_DrcLeRDW_met();
        rtb_Switch_cx = GET_S_DPRSIA_VelLatReLeRDW_mps();
    } else {
        rtb_Switch_j5 = GET_S_DPRSIA_DlcLeRDW_met();
        rtb_Switch_cx = GET_S_DPRSIA_VelLatLnLeRDW_mps();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Switch/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met'/Constant'
         */
    rtb_Sum_hc = GET_P_DPRSMW_TgtTrajPosY0_met() + GET_P_DPRSMW_NoHazardCancelTol_met();
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Constant'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/from_data_definition5'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator3/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator5/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator7/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Neg1/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_dwg = (uint8)((((sint32)DW_dprsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((rtb_Switch_j5 < (-GET_P_DPRSMW_HazardCancelTol_met())) || ((rtb_Switch_cx > 0.0F) && (rtb_Switch_j5 > rtb_Sum_hc))));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDW_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDW_met'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDW_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDW_mps'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/EQ4/Functionality'/EQ'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Switch3/Functionality'/Switch'
         */
    if ((((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
        rtb_Switch_j5 = GET_S_DPRSIA_DrcRiRDW_met();
        rtb_Switch_cx = GET_S_DPRSIA_VelLatReRiRDW_mps();
    } else {
        rtb_Switch_j5 = GET_S_DPRSIA_DlcRiRDW_met();
        rtb_Switch_cx = GET_S_DPRSIA_VelLatLnRiRDW_mps();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/from_data_definition4'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/OR'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator12/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator6/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Relational Operator9/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Neg2/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_n = (uint8)((((sint32)DW_dprsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((rtb_Switch_j5 > GET_P_DPRSMW_HazardCancelTol_met()) || ((rtb_Switch_cx < 0.0F) && (rtb_Switch_j5 < (-rtb_Sum_hc)))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/OR'
         */
    rtb_DataTypeConversion_p = (uint8)((((sint32)rtb_DataTypeConversion_dwg) != 0) || (((sint32)rtb_DataTypeConversion_n) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition6'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator3/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay4'
         */
    rtb_sfun_setbit_l = (uint8)((((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) DW_dprsmw_UnitDelay4_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator11/Functionality'/EQ'
         */
    rtb_sfun_setbit_l = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) && (((sint32)rtb_sfun_setbit_l) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition10'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition11'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition12'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator10/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator12/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator2/Functionality'/EQ'
         */
    rtb_sfun_setbit_h = (uint8)(((((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY)))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition8'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition9'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator3/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator5/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator9/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay4'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND3/Functionality'/AND'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)rtb_sfun_setbit_h) != 0) && (((sint32) rtb_sfun_setbit_a) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant3'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDWLe_btf'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ3/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND5/Functionality'/AND'
         */
    rtb_sfun_setbit_a = (uint8)(((((((sint32)GET_S_DPRSIA_SideCondRDWLe_btf()) & ((sint32)GET_P_DPRSMW_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMW_FctCustomCancelLe_btm())) != 0)) || (((sint32)rtb_sfun_setbit_l) != 0)) || (((sint32)rtb_sfun_setbit_a) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition2'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator4/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_c = (uint8)((((sint32)DW_dprsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && (((sint32)rtb_sfun_setbit_a) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition15'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition16'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator17/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator6/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay4'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) DW_dprsmw_UnitDelay4_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition17'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator14/Functionality'/EQ'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) && (((sint32)rtb_sfun_setbit_a) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator11/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition13'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition14'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator11/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator13/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator15/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator16/Functionality'/EQ'
         */
    rtb_sfun_setbit_h = (uint8)(((((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY)))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition18'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition19'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator10/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator18/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator19/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay4'
         */
    rtb_sfun_setbit_l = (uint8)((((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND4/Functionality'/AND'
         */
    rtb_sfun_setbit_h = (uint8)((((sint32)rtb_sfun_setbit_h) != 0) && (((sint32) rtb_sfun_setbit_l) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDWRi_btf'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator6/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ4/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND8/Functionality'/AND'
         */
    rtb_sfun_setbit_a = (uint8)(((((((sint32)GET_S_DPRSIA_SideCondRDWRi_btf()) & ((sint32)GET_P_DPRSMW_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMW_FctCustomCancelRi_btm())) != 0)) || (((sint32)rtb_sfun_setbit_a) != 0)) || (((sint32)rtb_sfun_setbit_h) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition3'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator8/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_lp = (uint8)((((sint32)DW_dprsmw_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32)rtb_sfun_setbit_a) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/OR'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)rtb_DataTypeConversion_c) != 0) || (((sint32)rtb_DataTypeConversion_lp) != 0));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Relational Operator11/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/from_data_definition4'/state_source'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay3'
         */
    rtb_EQ_as = (uint8)(((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4'
         */
    if ((!(((sint32)DW_dprsmw_Unit_Delay4_DSTATE) != 0)) && (((sint32)rtb_EQ_as) != 0)) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/from_data_definition2'/state_source'
                 *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/OR/Functionality'/OR'
                 *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Mul/Functionality'/Mul'
                 *  Product: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Mul1/Functionality'/Mul'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Relational Operator1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Relational Operator2/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay4'
                 */
        if ((((sint32)DW_dprsmw_UnitDelay4_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) DW_dprsmw_UnitDelay4_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_LaneWidth_met */
                FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_pqb = F32_PTR_IP1D (GETA_Y_DPRSMW_LWContrMaxDurReScal_nu(), &x_dps);
            }
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_VelX_mps */
                FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_p5 = F32_PTR_IP1D (GETA_Y_DPRSMW_VXContrMaxDurRe_sec(), &x_dps);
            }
            rtb_Switch_cx = rtb_ip_lookup_fxpt_sfun_7_p5 * rtb_ip_lookup_fxpt_sfun_7_pqb;
        } else {
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_LaneWidth_met */
                FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_e1 = F32_PTR_IP1D (GETA_Y_DPRSMW_LWContrMaxDurLnScal_nu(), &x_dps);
            }
            /* S-Function Block sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_VelX_mps */
                FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_lu = F32_PTR_IP1D (GETA_Y_DPRSMW_VXContrMaxDurLn_sec(), &x_dps);
            }
            rtb_Switch_cx = rtb_ip_lookup_fxpt_sfun_7_lu * rtb_ip_lookup_fxpt_sfun_7_e1;
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/Switch/Functionality'/Switch' */
    } else if (DW_dprsmw_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
                 */
        rtb_Switch_cx = DW_dprsmw_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch_cx = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_sfun_setbit_h = (uint8)(!(rtb_Switch_cx > 0.0F));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/AND'
         */
    rtb_sfun_setbit_h = (uint8)((((sint32)rtb_EQ_as) != 0) && (((sint32) rtb_sfun_setbit_h) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/NEQ5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/AND6/Functionality'/AND'
         */
    rtb_DataTypeConversion_ml1 = (uint8)((((((((((((sint32)rtb_sfun_setbit_o) != 0) || (((sint32)rtb_sfun_setbit) != 0)) || (((sint32)rtb_sfun_setbit_p) != 0)) || (((sint32)rtb_Switch_h) != 0)) || (((sint32)rtb_Switch_cc) != 0)) || (((sint32)rtb_NE_p3) != 0)) || ((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMW_CancelFctCustom_btm())) != 0)) || (((sint32) rtb_DataTypeConversion_p) != 0)) || (((sint32)rtb_sfun_setbit_a) != 0)) || (((sint32)rtb_sfun_setbit_h) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_ih = (uint8)((((((sint32)rtb_DataTypeConversion_dt) != 0) || (((sint32)rtb_DataTypeConversion_dv) != 0)) || (((sint32) rtb_LogicalOperator_c) != 0)) || (((sint32)rtb_DataTypeConversion_ml1) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator2/Functionality'/AND'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation'/Unit Delay2'
         */
    rtb_sfun_setbit_l = (uint8)((((sint32)DW_dprsmw_UnitDelay2_DSTATE_j) != 0) && ((!(((sint32)DW_dprsmw_Unit_Delay_DSTATE_p) != 0)) && (((sint32) rtb_DataTypeConversion_ih) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Add2/Functionality'/Sum'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer'/Unit Delay1'
         */
    if (((sint32)rtb_sfun_setbit_l) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Application Parameter2'/Constant'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Constant'/Constant'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch3/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_dt) != 0) {
            rtb_Sum_hc = GET_P_DPRSMW_AbortDegrDuration_sec();
        } else if (((sint32)rtb_DataTypeConversion_dv) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Application Parameter4'/Constant'
                         */
            rtb_Sum_hc = GET_P_DPRSMW_StrgRdyDegrDuration_sec();
        } else if (((sint32)rtb_LogicalOperator_c) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Application Parameter1'/Constant'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch'
                         */
            rtb_Sum_hc = GET_P_DPRSMW_FinishDegrDuration_sec();
        } else if (((sint32)rtb_DataTypeConversion_ml1) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Application Parameter3'/Constant'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch2/Functionality'/Switch'
                         */
            rtb_Sum_hc = GET_P_DPRSMW_CancelDegrDuration_sec();
        } else {
            rtb_Sum_hc = 0.0F;
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Switch/Functionality'/Switch' */
        rtb_Switch_j5 = GET_S_LCFRCV_SysCycleTimeSen_sec() + rtb_Sum_hc;
    } else {
        rtb_Switch_j5 = DW_dprsmw_UnitDelay1_DSTATE_o;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Constant3'/Constant'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Relational Operator8/Functionality'/GT'
         */
    rtb_sfun_setbit_l = (uint8)((((sint32)rtb_sfun_setbit_l) != 0) || (rtb_Switch_j5 > 1.0E-5F));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/Logical Operator10/Functionality'/NOT'
         */
    rtb_DataTypeConversion_dv = (uint8)(!(((sint32)rtb_sfun_setbit_l) != 0));
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_dv;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate[5] = rtb_LogicalOperator_c;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_DataTypeConversion_ml1;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/ErrorStateRDW/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/ErrorStateRDW/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/ErrorStateRDW/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ErrorStateRDW_bool'
         */
    if (((sint32)GET_P_DPRSMW_ErrorStateRDWEnable_bool()) != 0) {
        rtb_Switch_km = GET_S_LCFRCV_ErrorStateRDW_bool();
    } else {
        rtb_Switch_km = GET_P_DPRSMW_ErrorStateRDW_bool();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/ErrorStateRDW/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Switch_km;
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_l = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/D_SysStateRDW/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMW_SysStateRDW_btf(rtb_sfun_setbit_l);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_c[0] = rtb_sfun_setbit_o;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_c[2] = rtb_Switch_h;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_c[3] = rtb_Switch_cc;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_c[4] = rtb_NE_p3;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_c[5] = rtb_DataTypeConversion_p;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_c[6] = rtb_sfun_setbit_a;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_c[7] = rtb_sfun_setbit_h;
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/Logical Operator7/Functionality'/OR'
         */
    rtb_VectorConcatenate_c[1] = (uint8)((((sint32)rtb_sfun_setbit) != 0) || (((sint32)rtb_sfun_setbit_p) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_c[0];
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
        rtb_sfun_setbit_a = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMW_Cancel_btf(rtb_sfun_setbit_a);
    /* Chart: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW'/StateMachineRDP' incorporates:
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition1'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition2'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition3'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition4'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition5'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/from_data_definition6'/state_source'
                                                  *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/Application Parameter1'/Constant'
                                                  *
                                                  * Block description for 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW'/StateMachineRDP':
                                                  *  X.2.1.1.2
                                                  */
    /* Gateway: DPRSMW_cg/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP */
    /* During: DPRSMW_cg/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP */
    if (((uint32)((sint32)DW_dprsmw_is_active_c14_DPRSMW_cg)) == 0U) {
        /* Entry: DPRSMW_cg/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP */
        DW_dprsmw_is_active_c14_DPRSMW_cg = 1U;
        /* Entry Internal: DPRSMW_cg/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP */
        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':66' */
        if (!(((sint32)GET_P_RDW_Existing_nu()) != 0)) {
            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':74' */
            DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_NOT_PRESENT;
            /* Entry 'NOT_PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':3' */
            BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
        } else if ((((sint32)GET_P_RDW_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_km) != 0))) {
            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':83' */
            DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_PRESENT;
            /* Entry Internal 'PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':107' */
            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':72' */
            if (((sint32)rtb_Switch_fk) != 0) {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':70' */
                DW_dprsmw_is_PRESENT = DPRSMW_IN_PASSIVE;
                /* Entry 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                BI_dprsmw_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
            } else {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':71' */
                DW_dprsmw_is_PRESENT = DPRSMW_IN_DISABLED;
                /* Entry 'DISABLED': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':1' */
                BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
            }
        } else {
            if ((((sint32)GET_P_RDW_Existing_nu()) != 0) && (((sint32)rtb_Switch_km) != 0)) {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':82' */
                DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':12' */
                BI_dprsmw_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            }
        }
    } else {
        switch (DW_dprsmw_is_c14_DPRSMW_cg) {
        case DPRSMW_IN_ERROR:
            /* During 'ERROR': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':12' */
            if ((!(((sint32)rtb_Switch_km) != 0)) || (!(((sint32)GET_P_RDW_Existing_nu ()) != 0))) {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':59' */
                if (!(((sint32)GET_P_RDW_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':74' */
                    DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':3' */
                    BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_RDW_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_km) != 0))) {
                    /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':83' */
                    DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':107' */
                    /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':72' */
                    if (((sint32)rtb_Switch_fk) != 0) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':70' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    } else {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':71' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':1' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    }
                } else {
                    if ((((sint32)GET_P_RDW_Existing_nu()) != 0) && (((sint32) rtb_Switch_km) != 0)) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':82' */
                        DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':12' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        case DPRSMW_IN_NOT_PRESENT:
            /* During 'NOT_PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':3' */
            if (((sint32)GET_P_RDW_Existing_nu()) != 0) {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':81' */
                if (!(((sint32)GET_P_RDW_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':74' */
                    DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':3' */
                    BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_RDW_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_km) != 0))) {
                    /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':83' */
                    DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':107' */
                    /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':72' */
                    if (((sint32)rtb_Switch_fk) != 0) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':70' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    } else {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':71' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':1' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    }
                } else {
                    if ((((sint32)GET_P_RDW_Existing_nu()) != 0) && (((sint32) rtb_Switch_km) != 0)) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':82' */
                        DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':12' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        default:
            /* During 'PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':107' */
            if (!(((sint32)GET_P_RDW_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':58' */
                /* Exit Internal 'PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':107' */
                DW_dprsmw_is_PRESENT = DPRSMW_IN_NO_ACTIVE_CHILD;
                DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_NOT_PRESENT;
                /* Entry 'NOT_PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':3' */
                BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
            } else if ((((sint32)rtb_Switch_km) != 0) && (((sint32) GET_P_RDW_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':76' */
                /* Exit Internal 'PRESENT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':107' */
                DW_dprsmw_is_PRESENT = DPRSMW_IN_NO_ACTIVE_CHILD;
                DW_dprsmw_is_c14_DPRSMW_cg = DPRSMW_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':12' */
                BI_dprsmw_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                switch (DW_dprsmw_is_PRESENT) {
                case DPRSMW_IN_ACTIVE:
                    /* During 'ACTIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':10' */
                    if (((((sint32)rtb_LogicalOperator_c) != 0) || (((sint32) rtb_DataTypeConversion_ml1) != 0)) || (!(((sint32) rtb_DataTypeConversion_ks) != 0))) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':65' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':64' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    }
                    break;
                case DPRSMW_IN_DISABLED:
                    /* During 'DISABLED': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':1' */
                    if (((sint32)rtb_Switch_fk) != 0) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':17' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                    break;
                case DPRSMW_IN_PASSIVE:
                    /* During 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                    if (!(((sint32)rtb_Switch_fk) != 0)) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':18' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':1' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        if (((((sint32)rtb_DataTypeConversion_ks) != 0) && (((sint32) rtb_DataTypeConversion_a) != 0)) && (((sint32) rtb_DataTypeConversion_pp) != 0)) {
                            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':80' */
                            DW_dprsmw_is_PRESENT = DPRSMW_IN_REQUEST;
                            /* Entry 'REQUEST': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':9' */
                            BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu);
                        }
                    }
                    break;
                case DPRSMW_IN_RAMPOUT:
                    /* During 'RAMPOUT': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':64' */
                    if (((sint32)rtb_DataTypeConversion_dv) != 0) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':78' */
                        if (((sint32)rtb_Switch_fk) != 0) {
                            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':70' */
                            DW_dprsmw_is_PRESENT = DPRSMW_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                            BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        } else {
                            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':71' */
                            DW_dprsmw_is_PRESENT = DPRSMW_IN_DISABLED;
                            /* Entry 'DISABLED': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':1' */
                            BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                        }
                    }
                    break;
                default:
                    /* During 'REQUEST': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':9' */
                    if ((((sint32)rtb_DataTypeConversion_ks) != 0) && (((sint32) rtb_DataTypeConversion_pp) != 0)) {
                        /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':20' */
                        DW_dprsmw_is_PRESENT = DPRSMW_IN_ACTIVE;
                        /* Entry 'ACTIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':10' */
                        BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu);
                    } else {
                        if ((!(((sint32)rtb_DataTypeConversion_ks) != 0)) || (!(((sint32) rtb_DataTypeConversion_pp) != 0))) {
                            /* Transition: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':22' */
                            DW_dprsmw_is_PRESENT = DPRSMW_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineRDP':8' */
                            BI_dprsmw_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW'/StateMachineRDP' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/from_data_definition3'/state_source'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Relational Operator2/Functionality'/EQ'
         */
    rtb_Switch_fk = (uint8)(((((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide'/Template'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide'/Template1'
         */
    if (((sint32)DW_dprsmw_Template1_DSTATE) != 0) {
        rtb_DataTypeConversion_pp = DW_dprsmw_Template_DSTATE_m;
    } else if (((sint32)rtb_DataTypeConversion_m) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition5'/state_source'
                 */
        rtb_DataTypeConversion_pp = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT);
    } else if (((sint32)rtb_DataTypeConversion_g0) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_pp = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT);
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition1'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_pp = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/from_data_definition4'/state_source'
         */
    if (((sint32)rtb_Switch_fk) != 0) {
        rtb_NE_p3 = rtb_DataTypeConversion_pp;
    } else {
        rtb_NE_p3 = ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_sfun_setbit_j) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
                 */
        if (DW_dprsmw_UnitDelay1_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_UnitDelay1_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_OnTargetFinishTime_sec'/Constant'
                 */
        DW_dprsmw_UnitDelay1_DSTATE_d = GET_P_DPRSMW_OnTargetFinishTime_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_n[0] = rtb_GT_gl;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_n[1] = rtb_RelationalOperator1_c;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_n[2] = LogicalOperator_h;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_n[3] = rtb_DataTypeConversion_d;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_n[4] = rtb_DataTypeConversion_og;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_n[5] = rtb_LogicalOperator_ia;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_n[6] = rtb_EQ_jt;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_n[7] = rtb_EQ_l4;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_k2) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
                 */
        if (DW_dprsmw_Unit_Delay2_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_Unit_Delay2_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Application Parameter1'/Constant'
                 */
        DW_dprsmw_Unit_Delay2_DSTATE_d = GET_P_DPRSMW_SafeSitDelayLn_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_hv) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1'
                 */
        if (DW_dprsmw_UnitDelay1_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_UnitDelay1_DSTATE_e -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter2'/Constant'
                 */
        DW_dprsmw_UnitDelay1_DSTATE_e = GET_P_DPRSMW_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_a = temp;
    }
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1[0] = rtb_GT;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1[1] = rtb_RelationalOperator1_b5;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In3' */
    rtb_VectorConcatenate1[2] = LogicalOperator_k;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1[3] = rtb_DataTypeConversion_jz;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In5' */
    rtb_VectorConcatenate1[4] = rtb_LT_bz;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In6' */
    rtb_VectorConcatenate1[5] = rtb_LogicalOperator_ec;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In7' */
    rtb_VectorConcatenate1[6] = rtb_EQ_jt;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In8' */
    rtb_VectorConcatenate1[7] = rtb_EQ_l4;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_e[0] = rtb_GT;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_e[1] = rtb_DataTypeConversion_ne;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_e[2] = LogicalOperator_c;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_e[3] = rtb_DataTypeConversion_g;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_e[4] = rtb_LT_bz;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_e[5] = rtb_LogicalOperator_ec;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_e[6] = rtb_EQ_jt;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_e[7] = rtb_EQ_l4;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_ig0) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2'
                 */
        if (DW_dprsmw_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Application Parameter3'/Constant'
                 */
        DW_dprsmw_Unit_Delay2_DSTATE = GET_P_DPRSMW_SafeSitDelayRe_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_i5) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1'
                 */
        if (DW_dprsmw_UnitDelay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_UnitDelay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter2'/Constant'
                 */
        DW_dprsmw_UnitDelay1_DSTATE = GET_P_DPRSMW_TrcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/set_bit/Functionality'/sfun_setbit' */
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
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_j = temp;
    }
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2[0] = rtb_LT_gj;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2[1] = rtb_RelationalOperator1_h;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In3' */
    rtb_VectorConcatenate2[2] = LogicalOperator_a;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In4' */
    rtb_VectorConcatenate2[3] = rtb_DataTypeConversion_e;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In5' */
    rtb_VectorConcatenate2[4] = rtb_DataTypeConversion_j;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In6' */
    rtb_VectorConcatenate2[5] = rtb_LogicalOperator_lr;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In7' */
    rtb_VectorConcatenate2[6] = rtb_EQ_la;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In8' */
    rtb_VectorConcatenate2[7] = rtb_EQ_nh;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_UnitDelay2) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
                 */
        if (DW_dprsmw_Unit_Delay2_DSTATE_c > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_Unit_Delay2_DSTATE_c -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Application Parameter1'/Constant'
                 */
        DW_dprsmw_Unit_Delay2_DSTATE_c = GET_P_DPRSMW_SafeSitDelayLn_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_g4) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1'
                 */
        if (DW_dprsmw_UnitDelay1_DSTATE_b > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_UnitDelay1_DSTATE_b -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter2'/Constant'
                 */
        DW_dprsmw_UnitDelay1_DSTATE_b = GET_P_DPRSMW_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/set_bit2/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate2[0];
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
        rtb_sfun_setbit_o = temp;
    }
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1_k[0] = rtb_LT_js;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1_k[1] = rtb_RelationalOperator1_p;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In3' */
    rtb_VectorConcatenate1_k[2] = LogicalOperator_f;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1_k[3] = rtb_DataTypeConversion_bu;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In5' */
    rtb_VectorConcatenate1_k[4] = rtb_GT_f3;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In6' */
    rtb_VectorConcatenate1_k[5] = rtb_LogicalOperator_a;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In7' */
    rtb_VectorConcatenate1_k[6] = rtb_EQ_la;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In8' */
    rtb_VectorConcatenate1_k[7] = rtb_EQ_nh;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2_p[0] = rtb_DataTypeConversion_na;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2_p[1] = rtb_RelationalOperator1_g0;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In3' */
    rtb_VectorConcatenate2_p[2] = LogicalOperator_p;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In4' */
    rtb_VectorConcatenate2_p[3] = rtb_DataTypeConversion_dk;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In5' */
    rtb_VectorConcatenate2_p[4] = rtb_GT_f3;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In6' */
    rtb_VectorConcatenate2_p[5] = rtb_LogicalOperator_a;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In7' */
    rtb_VectorConcatenate2_p[6] = rtb_EQ_la;
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In8' */
    rtb_VectorConcatenate2_p[7] = rtb_EQ_nh;
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_bn) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi'/Unit_Delay2'
                 */
        if (DW_dprsmw_Unit_Delay2_DSTATE_db > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_Unit_Delay2_DSTATE_db -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/Application Parameter3'/Constant'
                 */
        DW_dprsmw_Unit_Delay2_DSTATE_db = GET_P_DPRSMW_SafeSitDelayRe_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_mx) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1'
                 */
        if (DW_dprsmw_UnitDelay1_DSTATE_k > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmw_UnitDelay1_DSTATE_k -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter2'/Constant'
                 */
        DW_dprsmw_UnitDelay1_DSTATE_k = GET_P_DPRSMW_TrcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1_k[0];
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
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/set_bit2/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate2_p[0];
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
        rtb_sfun_setbit_p = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Logical Operator10/Functionality'/AND'
         */
    rtb_GT = (uint8)((((sint32)rtb_DataTypeConversion_ks) != 0) && (((sint32) rtb_DataTypeConversion_a) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[0] = (uint8)(!(((sint32)rtb_EQ_kv) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[1] = (uint8)(!(((sint32)rtb_EQ_pa) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[2] = (uint8)(!(((sint32)rtb_EQ_fg) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[5] = (uint8)(!(((sint32)rtb_EQ_b2) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[6] = (uint8)(!(((sint32)rtb_EQ_ko) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[3] = (uint8)(!(((sint32)rtb_EQ_g3) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[4] = (uint8)(!(((sint32)rtb_EQ_bi) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_cu[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_ou) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_cu[0];
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
        rtb_Switch_h = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/StrongReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMW_StrongReady_btf(rtb_Switch_h);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Switch1/Functionality'/Switch' incorporates:
                                                  *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                                                  *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                                                  *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch'
                                                  *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch9/Functionality'/Switch'
                                                  *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason'/Template'
                                                  *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason'/Template1'
                                                  */
    if (((sint32)DW_dprsmw_Template_DSTATE_d) != 0) {
        rtb_DataTypeConversion_j0 = DW_dprsmw_Template1_DSTATE_g;
    } else if (((sint32)rtb_DataTypeConversion_j0) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition6'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition7'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/EQ2/Functionality'/EQ'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 */
        if (((sint32)GET_S_DPRSIA_TriggerReasonLeRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) {
            rtb_DataTypeConversion_j0 = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS);
        } else {
            rtb_DataTypeConversion_j0 = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY);
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch3/Functionality'/Switch' */
    } else if (((sint32)rtb_DataTypeConversion_m) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_j0 = GET_S_DPRSIA_TriggerReasonLeRDW_nu();
    } else if (((sint32)rtb_DataTypeConversion_b) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition2'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition4'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition5'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/EQ1/Functionality'/EQ'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch'
                 */
        if (((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) {
            rtb_DataTypeConversion_j0 = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS);
        } else {
            rtb_DataTypeConversion_j0 = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY);
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch4/Functionality'/Switch' */
    } else if (((sint32)rtb_DataTypeConversion_g0) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch9/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_j0 = GET_S_DPRSIA_TriggerReasonRiRDW_nu();
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_j0 = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG);
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[5] = (uint8)(!(((sint32)rtb_EQ_mv) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator10/Functionality'/NOT'
         */
    rtb_Switch_h = (uint8)(!(((sint32)rtb_EQ_jm) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_ld) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[1] = (uint8)(!(((sint32)rtb_EQ_pz) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[3] = (uint8)(!(((sint32)rtb_EQ_eb) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[4] = (uint8)(!(((sint32)rtb_EQ_jf) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[6] = (uint8)(!(((sint32)rtb_EQ_gk) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_m[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_c1) != 0));
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/Logical Operator5/Functionality'/NOT'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_m[2] = (uint8)((!(((sint32)rtb_EQ_nb) != 0)) || (((sint32)rtb_Switch_h) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_m[0];
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
        rtb_Switch_h = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMW_WeakReady_btf(rtb_Switch_h);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/branch2'/copy1' */
    SET_S_DPRSMW_TriggerReason_nu(rtb_DataTypeConversion_j0);
    /* DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/NOT/Functionality'/Data Type Conversion' incorporates:
                                                                *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/NOT/Functionality'/NOT'
                                                                */
    rtb_EQ_bi = (uint8)(!(((sint32)rtb_Switch_km) != 0));
    /* S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND11/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter3'/Constant'
         */
    rtb_Switch_h = (uint8)(((sint32)GET_P_DPRSMW_DebugDrvSt_btm()) & ((sint32) GET_P_DPRSMW_CancelDrvSt_btm()));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Constant11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/OR3/Functionality'/OR'
         */
    rtb_DataTypeConversion_m = (uint8)((((sint32)((uint8)(((sint32)((uint8) (((sint32)GET_P_DPRSMW_StrgRdyDrvSt_btm()) & ((sint32) GET_P_DPRSMW_DebugDrvSt_btm())))) | ((sint32)rtb_Switch_h)))) & ((sint32) GET_S_VDPDRV_DrvStInvalid_btf())) != 0);
    /* S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND4/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter7'/Constant'
         */
    rtb_Switch_h = (uint8)(((sint32)GET_P_DPRSMW_DebugSpecific_btm()) & ((sint32) GET_P_DPRSMW_CancelSpecific_btm()));
    /* RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Constant9'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDW_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/OR2/Functionality'/OR'
         */
    rtb_Switch_h = (uint8)((((sint32)((uint8)(((sint32)((uint8)(((sint32) GET_P_DPRSMW_StrgRdySpecific_btm()) & ((sint32) GET_P_DPRSMW_DebugSpecific_btm())))) | ((sint32)rtb_Switch_h)))) & ((sint32) GET_S_DPRSIA_SpecificRDW_btf())) != 0);
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Constant4'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDWRi_btf'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/NEQ6/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND7/Functionality'/AND'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch11/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch12/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch8/Functionality'/Switch'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch9/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState'/Template'
         *  UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState'/Template1'
         */
    if (((sint32)DW_dprsmw_Template1_DSTATE_e) != 0) {
        rtb_DataTypeConversion_dt = DW_dprsmw_Template_DSTATE_n;
    } else if (((sint32)rtb_LogicalOperator_c) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_SUCCESSFUL);
    } else if (((sint32)rtb_DataTypeConversion_dt) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition9'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_ABORT);
    } else if (((sint32)rtb_NE_p3) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Application Parameter5'/Constant'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Constant13'/Constant'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition15'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_SideCondRDWLe_btf'
                 *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/NEQ2/Functionality'/NE'
                 *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND3/Functionality'/AND'
                 *  S-Function (sfix_bitop): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/AND5/Functionality'/AND'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        if (((((((sint32)GET_P_DPRSMW_SideCondDebug_btm()) & ((sint32) GET_P_DPRSMW_SideCondCancel_btm())) & ((sint32) GET_S_DPRSIA_SideCondRDWLe_btf())) != 0) || (((sint32) rtb_DataTypeConversion_m) != 0)) || (((sint32)rtb_Switch_h) != 0)) {
            rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
        } else if (((sint32)rtb_DataTypeConversion_dwg) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition14'/state_source'
                         */
            rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
        } else if (((sint32)rtb_DataTypeConversion_c) != 0) {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition13'/state_source'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch10/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
        } else {
            /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition2'/state_source'
                         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch7/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch6/Functionality'/Switch' */
    } else if (((((sint32)rtb_DataTypeConversion_m) != 0) || (((sint32) rtb_Switch_h) != 0)) || (((((sint32) GET_P_DPRSMW_SideCondDebug_btm()) & ((sint32) GET_P_DPRSMW_SideCondCancel_btm())) & ((sint32) GET_S_DPRSIA_SideCondRDWRi_btf())) != 0)) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition11'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
    } else if (((sint32)rtb_DataTypeConversion_n) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition10'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
    } else if (((sint32)rtb_DataTypeConversion_lp) != 0) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition8'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
    } else {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition16'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch12/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dt = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition6'/state_source'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Relational Operator5/Functionality'/EQ'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch3/Functionality'/Switch'
         */
    if (((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) {
        rtb_Switch_h = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_TRIGGER);
    } else if (((sint32)BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition5'/state_source'
                 */
        rtb_Switch_h = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_RUNNING);
    } else {
        rtb_Switch_h = rtb_DataTypeConversion_dt;
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDW_nu'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_NE_p3) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch3'/copy1' */
        SET_S_DPRSMW_SysStateRDWLe_nu(rtb_Switch_h);
    } else if (((((sint32)rtb_GT) != 0) && (((sint32) GET_S_DPRSIA_TriggerReasonLeRDW_nu()) != ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG)))) && (((sint32)rtb_EQ_bi) != 0)) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition2'/state_source'
                 *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch3'/copy1'
                 */
        SET_S_DPRSMW_SysStateRDWLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL));
    } else {
        /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch3'/copy1' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch2/Functionality'/Switch'
                 */
        SET_S_DPRSMW_SysStateRDWLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition10'/state_source'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Relational Operator1/Functionality'/EQ'
         */
    if (((sint32)rtb_NE_p3) != ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        /* Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition6'/state_source'
                 *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/from_data_definition8'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDW_nu'
                 *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/AND1/Functionality'/AND'
                 *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/NEQ1/Functionality'/NE'
                 */
        if (((((sint32)rtb_GT) != 0) && (((sint32)GET_S_DPRSIA_TriggerReasonRiRDW_nu ()) != ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG)))) && (((sint32)rtb_EQ_bi) != 0)) {
            rtb_Switch_h = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL);
        } else {
            rtb_Switch_h = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL);
        }
        /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch1'/copy1' */
    SET_S_DPRSMW_SysStateRDW_nu(BI_dprsmw_SysState_nu);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch10'/copy1' */
    SET_D_DPRSMW_DrcLeThreshold_met(rtb_Switch_l3);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch12'/copy1' */
    SET_D_DPRSMW_TrcLeThreshold_sec(rtb_Switch_kc);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch13'/copy1' */
    SET_D_DPRSMW_TrcRiThreshold_sec(rtb_Switch_fe);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch14'/copy1' */
    SET_D_DPRSMW_TriggerReLe_btf(rtb_sfun_setbit_j);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch15'/copy1' */
    SET_D_DPRSMW_TriggerLnReLe_btf(rtb_sfun_setbit_h);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch16'/copy1' */
    SET_D_DPRSMW_TriggerLnLe_btf(rtb_sfun_setbit_a);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch17'/copy1' */
    SET_D_DPRSMW_TriggerReRi_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch18'/copy1' */
    SET_D_DPRSMW_TriggerLnReRi_btf(rtb_sfun_setbit_p);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch19'/copy1' */
    SET_D_DPRSMW_TriggerLnRi_btf(rtb_sfun_setbit_o);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch2'/copy1' */
    SET_S_DPRSMW_SysStateRDWRi_nu(rtb_Switch_h);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch4'/copy1' */
    SET_S_DPRSMW_DangerousSide_nu(rtb_NE_p3);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch5'/copy1' */
    SET_S_DPRSMW_ReadyToTrigger_bool(rtb_GT);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch6'/copy1' */
    SET_D_DPRSMW_DlcLeThreshold_met(rtb_Switch_cy);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch7'/copy1' */
    SET_D_DPRSMW_DlcRiThreshold_met(rtb_Mul_p);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch8'/copy1' */
    SET_D_DPRSMW_TlcLeThreshold_sec(rtb_Switch_pn);
    /* SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/branch9'/copy1' */
    SET_D_DPRSMW_TlcRiThreshold_sec(rtb_Switch_of);
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_c = rtb_Switch_ig0;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_a = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay1' */
    DW_dprsmw_Unit_Delay1_DSTATE = rtb_Switch2_eh;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_f = rtb_DataTypeConversion_bx;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE = rtb_Switch2_lk;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_k = rtb_Switch_k2;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_ks = rtb_DataTypeConversion_kb;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_d = rtb_Switch2_bg;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRi'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_o = rtb_Switch_bn;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_g = rtb_DataTypeConversion_fg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay1' */
    DW_dprsmw_Unit_Delay1_DSTATE_p = rtb_Mul_a;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_de = rtb_DataTypeConversion_jd;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_h = rtb_Switch_i0;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_n = rtb_UnitDelay2;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_ki = rtb_DataTypeConversion_cx;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising1/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_b = rtb_Switch2_gq;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Template_DSTATE = rtb_EQ_ll0;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay' */
    DW_dprsmw_Unit_Delay_DSTATE_bk = rtb_Switch2_p;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation'/Unit Delay2' */
    DW_dprsmw_UnitDelay2_DSTATE_j = rtb_DataTypeConversion_dv;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay5' */
    DW_dprsmw_UnitDelay5_DSTATE = rtb_NE_p3;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_ga = rtb_UnitDelay1_h;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/GenerateDangerousSituationFinish/MinTimeRDW'/Unit Delay1' */
    DW_dprsmw_UnitDelay1_DSTATE_ez = rtb_Switch2_o;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs'/Unit Delay4' */
    DW_dprsmw_UnitDelay4_DSTATE = rtb_DataTypeConversion_j0;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay4_DSTATE = rtb_EQ_as;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3' */
    DW_dprsmw_Unit_Delay3_DSTATE = rtb_Switch_cx;
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmw_Unit_Delay_DSTATE_p = rtb_DataTypeConversion_ih;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer'/Unit Delay1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Sum: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/Degradation/FollowUpTimer/Add1/Functionality'/Sum'
         */
    DW_dprsmw_UnitDelay1_DSTATE_o = rtb_Switch_j5 - GET_S_LCFRCV_SysCycleTimeSen_sec ();
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide'/Template' */
    DW_dprsmw_Template_DSTATE_m = rtb_DataTypeConversion_pp;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/DangerousSide'/Template1' */
    DW_dprsmw_Template1_DSTATE = rtb_Switch_fk;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason'/Template1' */
    DW_dprsmw_Template1_DSTATE_g = rtb_DataTypeConversion_j0;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason'/Template' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/from_data_definition4'/state_source'
         *  DataTypeConversion: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Logical Operator/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/StateMachineInputs/TriggerReason/Relational Operator2/Functionality'/EQ'
         */
    DW_dprsmw_Template_DSTATE_d = (uint8)(((((sint32)BI_dprsmw_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32) BI_dprsmw_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState'/Template' */
    DW_dprsmw_Template_DSTATE_n = rtb_DataTypeConversion_dt;
    /* Update for UnitDelay: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState'/Template1' incorporates:
         *  Constant: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/from_data_definition12'/state_source'
         *  RelationalOperator: 'sda:DPRSMW/DPRSMW/DPRSMW_SenProcess/OPM/M_DPRSMW/SysState/SysState/Relational Operator1/Functionality'/EQ'
         */
    DW_dprsmw_Template1_DSTATE_e = (uint8)(((sint32)BI_dprsmw_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
}
#include "Pse_DPRSMW.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
