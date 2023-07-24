/**************************************************************************
COPYRIGHT (C) $Date: 2020/06/24 07:51:43CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/RDPSA/DPRSMI_SEN/DPRSMI/i/project.pj $
$Log: DPRSMI.c  $
Revision 1.4.1.4.1.1 2020/06/24 07:51:43CEST Iordachescu, Roxana03 (uidq9891) 
automatically created
File          : DPRSMI
Generated on  : Tue 23.06.2020 at 14:08:47 (UTC+01:00)
MD5           : [348289137  2095883919  1129781642  1658132042 0](DPRSMI)
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
#include "DPRSMI.h"
#include "DPRSMI_private.h"
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
/* Named constants for Chart: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI'/StateMachineRDP' */
#define DPRSMI_IN_ACTIVE               ((uint8)1U)
#define DPRSMI_IN_DISABLED             ((uint8)2U)
#define DPRSMI_IN_ERROR                ((uint8)1U)
#define DPRSMI_IN_NOT_PRESENT          ((uint8)2U)
#define DPRSMI_IN_NO_ACTIVE_CHILD      ((uint8)0U)
#define DPRSMI_IN_PASSIVE              ((uint8)3U)
#define DPRSMI_IN_PRESENT              ((uint8)3U)
#define DPRSMI_IN_RAMPOUT              ((uint8)4U)
#define DPRSMI_IN_REQUEST              ((uint8)5U)
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
#define DPRSMI_START_SEC_DATA_8
#include "DPRSMI_MemMap.h"
static uint8 BI_dprsmi_SysState_nu;
/* 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI'/StateMachineRDP' */
static uint8 DW_dprsmi_Unit_Delay_DSTATE_i;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_g;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_as;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_kr;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_in;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_b;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_e;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_n;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_m;
static uint8 DW_dprsmi_Unit_Delay_DSTATE_f;
static uint8 DW_dprsmi_Template_DSTATE;
static uint8 DW_dprsmi_Unit_Delay1_DSTATE_o;
static uint8 DW_dprsmi_UnitDelay5_DSTATE;
static uint8 DW_dprsmi_UnitDelay2_DSTATE;
static uint8 DW_dprsmi_Unit_Delay4_DSTATE;
static uint8 DW_dprsmi_Unit_Delay1_DSTATE_b;
static uint8 DW_dprsmi_Template_DSTATE_n;
static uint8 DW_dprsmi_Template1_DSTATE;
static uint8 DW_dprsmi_Unit_Delay1_DSTATE_p;
static uint8 DW_dprsmi_Template_DSTATE_k;
static uint8 DW_dprsmi_Template1_DSTATE_b;
static uint8 DW_dprsmi_Template_DSTATE_g;
static uint8 DW_dprsmi_Template1_DSTATE_i;
static uint8 DW_dprsmi_is_active_c14_DPRSMI_cg;
static uint8 DW_dprsmi_is_c14_DPRSMI_cg;
static uint8 DW_dprsmi_is_PRESENT;
#define DPRSMI_STOP_SEC_DATA_8
#include "DPRSMI_MemMap.h"
#define DPRSMI_START_SEC_DATA_32
#include "DPRSMI_MemMap.h"
static float32 DW_dprsmi_UnitDelay1_DSTATE;
static float32 DW_dprsmi_Unit_Delay2_DSTATE;
static float32 DW_dprsmi_Unit_Delay1_DSTATE;
static float32 DW_dprsmi_Unit_Delay_DSTATE;
static float32 DW_dprsmi_UnitDelay1_DSTATE_e;
static float32 DW_dprsmi_Unit_Delay2_DSTATE_d;
static float32 DW_dprsmi_Unit_Delay_DSTATE_d;
static float32 DW_dprsmi_UnitDelay1_DSTATE_d;
static float32 DW_dprsmi_Unit_Delay2_DSTATE_b;
static float32 DW_dprsmi_Unit_Delay1_DSTATE_e;
static float32 DW_dprsmi_Unit_Delay_DSTATE_p;
static float32 DW_dprsmi_UnitDelay1_DSTATE_c;
static float32 DW_dprsmi_Unit_Delay2_DSTATE_p;
static float32 DW_dprsmi_Unit_Delay_DSTATE_dy;
static float32 DW_dprsmi_Unit_Delay_DSTATE_l;
static float32 DW_dprsmi_Unit_Delay_DSTATE_a;
static float32 DW_dprsmi_UnitDelay1_DSTATE_n;
static float32 DW_dprsmi_Unit_Delay3_DSTATE;
static float32 DW_dprsmi_Unit_Delay_DSTATE_k;
#define DPRSMI_STOP_SEC_DATA_32
#include "DPRSMI_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:DPRSMI/DPRSMI/INI'/DPRSMI_SenReset'
 * Block description for: 'sda:DPRSMI/DPRSMI/INI'/DPRSMI_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRSMI_SenReset
#include "Pse_DPRSMI.h"
/* Short description: Not synchronized with ARAMIS */
void DPRSMI_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant1'/Constant' */
    SET_S_DPRSMI_FunctionAborted_bool(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant10'/Constant' */
    SET_S_DPRSMI_SysStateRDPLe_nu(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant11'/Constant' */
    SET_D_DPRSMI_DrcRiThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant12'/Constant' */
    SET_D_DPRSMI_TrcLeThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant13'/Constant' */
    SET_D_DPRSMI_DrcLeThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant14'/Constant' */
    SET_D_DPRSMI_DlcLeThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant15'/Constant' */
    SET_D_DPRSMI_DlcRiThreshold_met(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant16'/Constant' */
    SET_D_DPRSMI_TlcRiThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant17'/Constant' */
    SET_S_DPRSMI_ReadyToTrigger_bool(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant18'/Constant' */
    SET_D_DPRSMI_TlcLeThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant19'/Constant' */
    SET_D_DPRSMI_TrcRiThreshold_sec(0.0F);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant2'/Constant' */
    SET_S_DPRSMI_SysStateRDP_nu(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant20'/Constant' */
    SET_D_DPRSMI_TriggerReLe_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant21'/Constant' */
    SET_D_DPRSMI_TriggerLnReLe_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant22'/Constant' */
    SET_D_DPRSMI_TriggerLnLe_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant23'/Constant' */
    SET_D_DPRSMI_TriggerReRi_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant24'/Constant' */
    SET_D_DPRSMI_TriggerLnReRi_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant25'/Constant' */
    SET_D_DPRSMI_TriggerLnRi_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant3'/Constant' */
    SET_D_DPRSMI_SysStateRDP_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant4'/Constant' */
    SET_S_DPRSMI_DangerousSide_nu(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant5'/Constant' */
    SET_D_DPRSMI_StrongReady_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant6'/Constant' */
    SET_D_DPRSMI_Cancel_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant7'/Constant' */
    SET_D_DPRSMI_WeakReady_btf(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant8'/Constant' */
    SET_S_DPRSMI_TriggerReason_nu(0U);
    /* Constant: 'sda:DPRSMI/DPRSMI/INI/DPRSMI_SenReset/Constant9'/Constant' */
    SET_S_DPRSMI_SysStateRDPRi_nu(0U);
}
#include "Pse_DPRSMI.h"
/*
 * Output and update for function-call system: 'sda:DPRSMI/DPRSMI'/DPRSMI_SenProcess'
 * Block description for: 'sda:DPRSMI/DPRSMI'/DPRSMI_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_DPRSMI_SenProcess
#include "Pse_DPRSMI.h"
/* Short description: Not synchronized with ARAMIS */
void DPRSMI_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_UnaryMinus;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_UnaryMinus_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_jb;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_Abs_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_f;
    float32 rtb_ip_lookup_fxpt_sfun_7_lv;
    float32 rtb_ip_lookup_fxpt_sfun_7_fu;
    float32 rtb_ip_lookup_fxpt_sfun_7_fs;
    float32 rtb_Abs_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_de;
    float32 rtb_Abs_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_Abs_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_Abs_jd;
    float32 rtb_ip_lookup_fxpt_sfun_7_ma;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_hq;
    float32 rtb_ip_lookup_fxpt_sfun_7_fl;
    float32 rtb_Abs_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_Abs_ch;
    float32 rtb_ip_lookup_fxpt_sfun_7_jc;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_Abs_k;
    float32 rtb_ip_lookup_fxpt_sfun_7_h2;
    float32 rtb_Abs_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_hf;
    float32 rtb_ip_lookup_fxpt_sfun_7_ns;
    float32 rtb_Abs_cu;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Abs_aa;
    float32 rtb_ip_lookup_fxpt_sfun_7_pw;
    float32 rtb_ip_lookup_fxpt_sfun_7_et;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_bp;
    float32 rtb_ip_lookup_fxpt_sfun_7_mw;
    float32 rtb_Abs_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_oa;
    float32 rtb_Abs_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_ev;
    float32 rtb_ip_lookup_fxpt_sfun_7_bn;
    float32 rtb_Abs_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_jn;
    float32 rtb_Abs_aal;
    float32 rtb_ip_lookup_fxpt_sfun_7_fm;
    float32 rtb_ip_lookup_fxpt_sfun_7_jbi;
    float32 rtb_ip_lookup_fxpt_sfun_7_lk;
    float32 rtb_ip_lookup_fxpt_sfun_7_mg;
    float32 rtb_ip_lookup_fxpt_sfun_7_ho;
    float32 rtb_ip_lookup_fxpt_sfun_7_ff;
    float32 rtb_ip_lookup_fxpt_sfun_7_ky;
    float32 rtb_ip_lookup_fxpt_sfun_7_by;
    float32 rtb_Switch_hf;
    float32 rtb_ip_lookup_fxpt_sfun_7_nj;
    uint8 rtb_VectorConcatenate[8];
    uint8 rtb_VectorConcatenate_a[8];
    uint8 rtb_VectorConcatenate2[8];
    uint8 rtb_VectorConcatenate1[8];
    uint8 rtb_VectorConcatenate2_h[8];
    uint8 rtb_VectorConcatenate2_o[8];
    uint8 rtb_VectorConcatenate1_p[8];
    uint8 rtb_VectorConcatenate2_g[8];
    uint8 rtb_VectorConcatenate_h[8];
    uint8 rtb_VectorConcatenate_e[8];
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_b;
    uint8 rtb_sfun_setbit_p;
    uint8 rtb_sfun_setbit_a;
    uint8 rtb_sfun_setbit_e;
    uint8 rtb_sfun_setbit_c;
    uint8 rtb_Switch_do;
    uint8 rtb_GT;
    uint8 rtb_LT_p;
    uint8 rtb_DataTypeConversion_df;
    float32 rtb_Mul_f2;
    uint8 rtb_LT_fz;
    uint8 rtb_EQ_ad;
    uint8 rtb_UnitDelay1_d1;
    uint8 rtb_EQ_b1;
    uint8 rtb_RelationalOperator1_li;
    uint8 rtb_DataTypeConversion_e5;
    uint8 rtb_RelationalOperator1_pa;
    uint8 rtb_LogicalOperator_n;
    uint8 rtb_Switch_p3;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_ov;
    uint8 rtb_DataTypeConversion_dw;
    uint8 rtb_DataTypeConversion_dg;
    uint8 rtb_GT_cm;
    uint8 rtb_EQ_ho;
    uint8 rtb_LT_g;
    uint8 rtb_DataTypeConversion_c;
    float32 rtb_Mul_g;
    uint8 rtb_LT_ot;
    uint8 rtb_DataTypeConversion_bn;
    uint8 rtb_GT_ij;
    uint8 rtb_DataTypeConversion_ct;
    uint8 rtb_LT_bx;
    uint8 rtb_RelationalOperator1_h;
    uint8 rtb_LogicalOperator_ok;
    uint8 rtb_Switch_me;
    uint8 rtb_DataTypeConversion_fc;
    uint8 rtb_DataTypeConversion_cz;
    uint8 rtb_LT_hi;
    uint8 rtb_RelationalOperator1_l;
    uint8 rtb_DataTypeConversion_e1;
    uint8 rtb_RelationalOperator1_lu;
    uint8 rtb_LogicalOperator_g;
    uint8 rtb_Switch_k0;
    uint8 rtb_LT_ir;
    uint8 rtb_EQ_fs;
    uint8 rtb_DataTypeConversion_jc;
    uint8 rtb_DataTypeConversion_gz;
    uint8 rtb_LT_if;
    uint8 rtb_EQ_be;
    float32 rtb_Mul_j;
    uint8 rtb_LT_e2;
    uint8 rtb_DataTypeConversion_fm;
    uint8 rtb_GT_jn;
    uint8 rtb_DataTypeConversion_aq;
    uint8 rtb_EQ_io;
    uint8 rtb_EQ_k1;
    uint8 rtb_EQ_az;
    uint8 rtb_RelationalOperator1_ag;
    uint8 rtb_LogicalOperator_ip;
    uint8 rtb_DataTypeConversion_iy;
    uint8 rtb_DataTypeConversion_ex;
    uint8 rtb_DataTypeConversion_ke;
    uint8 rtb_EQ_md;
    uint8 rtb_EQ_mx;
    uint8 rtb_DataTypeConversion_g;
    uint8 rtb_DataTypeConversion_o0;
    uint8 rtb_DataTypeConversion_e;
    uint8 rtb_DataTypeConversion_f;
    uint8 rtb_EQ_hc;
    uint8 rtb_EQ_h1z;
    uint8 rtb_EQ_b5;
    uint8 rtb_EQ_gr;
    uint8 rtb_EQ_og2;
    uint8 rtb_EQ_jz;
    uint8 rtb_EQ_oq;
    uint8 rtb_UnitDelay1_d;
    uint8 rtb_EQ_lzr;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_dj;
    uint8 rtb_EQ_mq;
    uint8 rtb_DataTypeConversion_n0;
    uint8 rtb_NE_li;
    uint8 rtb_NE_gw;
    uint8 rtb_DataTypeConversion_ij;
    uint8 rtb_NE_cs2;
    float32 rtb_Switch_kh;
    uint8 rtb_LT_k;
    uint8 rtb_GT_d5;
    uint8 rtb_Switch_d1;
    uint8 rtb_Switch_gb;
    uint8 rtb_DataTypeConversion_gh;
    uint8 rtb_DataTypeConversion_fk;
    uint8 rtb_DataTypeConversion_ix;
    uint8 rtb_DataTypeConversion_ic;
    uint8 rtb_DataTypeConversion_a;
    uint8 rtb_Switch_b3;
    float32 rtb_Switch_n1;
    float32 rtb_Switch_la;
    float32 rtb_Switch_k;
    float32 rtb_Switch_lic;
    float32 rtb_Switch2_ok;
    float32 rtb_Switch2_hb;
    float32 rtb_Switch2_fc;
    float32 rtb_Switch_pa;
    float32 rtb_Switch2_ny;
    float32 rtb_Switch2_c;
    float32 rtb_Switch_a3;
    float32 rtb_Switch2_p;
    float32 rtb_Switch_mss;
    float32 rtb_Switch2_m5;
    uint8 LogicalOperator_dk;
    uint8 LogicalOperator_d;
    uint8 LogicalOperator_l;
    uint8 LogicalOperator_j;
    uint8 LogicalOperator_g;
    uint8 LogicalOperator_f;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/RDPSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/RDPSwitch/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/RDPSwitch/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDPSwitch_bool'
         */
    if (((sint32)GET_P_DPRSMI_RDPSwitchEnable_bool()) != 0) {
        rtb_Switch_do = GET_S_LCFRCV_RDPSwitch_bool();
    } else {
        rtb_Switch_do = GET_P_DPRSMI_RDPSwitch_bool();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/RDPSwitch/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_Switch_do;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         */
    rtb_GT = (uint8)(GET_S_DPRSIA_DrcLeRDP_met() > GET_P_DPRSMI_DrcLimitMin_met());
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDPMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Relational Operator3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_lv = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD3TrigTrc_sec (), &x_dps);
        }
        rtb_ip_lookup_fxpt_sfun_7_nj = rtb_ip_lookup_fxpt_sfun_7_lv;
    } else if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_fu = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD2TrigTrc_sec (), &x_dps);
        }
        rtb_ip_lookup_fxpt_sfun_7_nj = rtb_ip_lookup_fxpt_sfun_7_fu;
    } else {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_fs = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD1TrigTrc_sec (), &x_dps);
        }
        rtb_ip_lookup_fxpt_sfun_7_nj = rtb_ip_lookup_fxpt_sfun_7_fs;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch4/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_DPRSMI_LWTrigTrcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Divide2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_ip_lookup_fxpt_sfun_7_nj *= rtb_ip_lookup_fxpt_sfun_7;
    /* UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Neg1/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDP_mps'
         */
    rtb_UnaryMinus = -GET_S_DPRSIA_VelLatReLeRDP_mps();
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigTrcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Neg/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (GET_S_ABPREP_LeReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_g = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_g, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_de = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_n1 = -rtb_ip_lookup_fxpt_sfun_7_de;
    } else if (GET_S_ABPREP_LeReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_i = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_i, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_n1 = rtb_ip_lookup_fxpt_sfun_7_p;
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Constant8'/Constant'
                 */
        rtb_Switch_n1 = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Divide5/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_n1 += rtb_ip_lookup_fxpt_sfun_7_nj * rtb_ip_lookup_fxpt_sfun_7_d;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Relational Operator2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TrcLeRDP_sec'
         */
    rtb_LT_p = (uint8)(GET_S_DPRSIA_TrcLeRDP_sec() < rtb_Switch_n1);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDPMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Relational Operator8/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch7/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_et = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD3TrigDrc_met (), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_et;
    } else if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD2TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD2TrigDrc_met(), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_c;
    } else {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_bp = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD1TrigDrc_met (), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_bp;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch3/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_DPRSMI_LWTrigDrcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_f2 = rtb_Switch_lic * rtb_ip_lookup_fxpt_sfun_7_i;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDPDrcTrgLe_met'
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Neg/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDP_DrcTriggerCustom_bool()) != 0) {
        rtb_Switch_pa = GET_S_CUSTOM_RDPDrcTrgLe_met();
    } else {
        if (GET_S_ABPREP_LeReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_cu = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_cu, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICDrcOffset_met(), &x_dps);
            }
            rtb_Switch_pa = -rtb_ip_lookup_fxpt_sfun_7_b;
        } else if (GET_S_ABPREP_LeReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_aa = f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_aa, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_pw = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCDrcOffset_met(), &x_dps);
            }
            rtb_Switch_pa = rtb_ip_lookup_fxpt_sfun_7_pw;
        } else {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Constant8'/Constant'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_pa = 0.0F;
        }
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ns = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigDrcScalFact_nu(), &x_dps);
        }
        rtb_Switch_pa += rtb_Mul_f2 * rtb_ip_lookup_fxpt_sfun_7_ns;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Relational Operator1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1'
         */
    rtb_DataTypeConversion_df = (uint8)((((DW_dprsmi_UnitDelay1_DSTATE <= 0.0F) && (((sint32)rtb_LT_p) != 0)) && (GET_S_DPRSIA_DrcLeRDP_met() < GET_P_DPRSMI_TrcDistanceMin_met())) || (GET_S_DPRSIA_DrcLeRDP_met() < rtb_Switch_pa));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDPDrcLimitLe_met'
         */
    if (((sint32)GET_P_RDP_DrcLimitCustom_bool()) != 0) {
        rtb_Switch_k = GET_S_CUSTOM_RDPDrcLimitLe_met();
    } else {
        rtb_Switch_k = GET_P_DPRSMI_DrcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch3/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/LT/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         */
    rtb_LT_fz = (uint8)(GET_S_DPRSIA_DrcLeRDP_met() < rtb_Switch_k);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator4/Functionality'/AND'
         */
    rtb_EQ_ad = (uint8)((((sint32)rtb_DataTypeConversion_df) != 0) && (((sint32) rtb_LT_fz) != 0));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Constant9'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPRSMI_SafeSitStateRe_btm()) & 1) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMI_SafeSitStateRe_btm()) & 2) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMI_SafeSitStateRe_btm()) & 4) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMI_SafeSitStateRe_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMI_SafeSitStateRe_btm()) & 16) != 0) && (((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))))) {
        rtb_Switch_p3 = 0U;
    } else if (GET_S_DPRSIA_DrcLeRDP_met() > (rtb_Switch_pa + GET_P_DPRSMI_SafeSitOffsetRe_met())) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_p3 = 1U;
    } else {
        rtb_Switch_p3 = DW_dprsmi_Unit_Delay_DSTATE_i;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2'
         */
    rtb_LogicalOperator_n = (uint8)((DW_dprsmi_Unit_Delay2_DSTATE <= 0.0F) && (((sint32)rtb_Switch_p3) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs1/Functionality'/Abs'
         *  Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs2/Functionality'/Abs'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPREP_LeReClthCrv_1pm'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT2/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT3/Functionality'/LT'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum/Functionality'/Sum'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum1/Functionality'/Sum'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Neg/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_e5 = (uint8)((((sint32) GET_P_DPRSMI_TrgIgnoreLnContg_bool()) != 0) || (((((((sint32) GET_P_DPRSMI_LnOverlapEnable_bool()) != 0) && ((GET_S_DPRSIA_DrcLeRDP_met() - GET_S_DPRSIA_DlcLeRDP_met()) > (-GET_P_DPRSMI_LnOverlapInnerDist_met()))) && ((GET_S_DPRSIA_DrcLeRDP_met() - GET_S_DPRSIA_DlcLeRDP_met()) < GET_P_DPRSMI_LnOverlapOuterDist_met())) && (f32_abs_f32 (GET_S_ABPLBP_LeLnClthCrv_1pm()) < GET_P_DPRSMI_LnOverlapCrv_1pm())) && (f32_abs_f32(GET_S_ABPREP_LeReClthCrv_1pm()) < GET_P_DPRSMI_LnOverlapCrv_1pm ())));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ3/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((((sint32)rtb_EQ_ad) != 0) && (((sint32) rtb_LogicalOperator_n) != 0)) && ((((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))))) && (((sint32) rtb_DataTypeConversion_e5) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1'/Unit_Delay'
         */
    LogicalOperator_l = (uint8)((!(((sint32)DW_dprsmi_Unit_Delay_DSTATE_g) != 0)) && (((sint32)rtb_DataTypeConversion) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Constant1'/Constant'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay1'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_ny = DW_dprsmi_Unit_Delay1_DSTATE;
    } else {
        rtb_Switch2_ny = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_l) != 0) {
        rtb_Switch2_ny = GET_P_DPRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
                         */
            if (rtb_Switch2_ny > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_ny -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_ny = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant'
         */
    rtb_RelationalOperator1_pa = (uint8)(rtb_Switch2_ny > 0.0F);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDPLe_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND5/Functionality'/AND'
         */
    rtb_EQ_b1 = (uint8)((((sint32)GET_S_DPRSIA_SideCondRDPLe_btf()) & ((sint32) GET_P_DPRSMI_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/AND1/Functionality'/AND'
         */
    rtb_EQ_ov = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMI_FctCustomTrgLe_btm())) == 0);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_dw = (uint8)((((((sint32)rtb_GT) != 0) && (((sint32) rtb_RelationalOperator1_pa) != 0)) && (((sint32)rtb_EQ_b1) != 0)) && (((sint32)rtb_EQ_ov) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator16/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Logical Operator16/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_dg = (uint8)((((((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) && (((sint32) rtb_EQ_ad) != 0)) && (((sint32)rtb_LogicalOperator_n) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2'/Unit_Delay'
         */
    LogicalOperator_d = (uint8)((!(((sint32)DW_dprsmi_Unit_Delay_DSTATE_as) != 0)) && (((sint32)rtb_DataTypeConversion_dg) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay'
         */
    if (((sint32)rtb_GT) >= 1) {
        rtb_Switch2_c = DW_dprsmi_Unit_Delay_DSTATE;
    } else {
        rtb_Switch2_c = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec'/Constant'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_d) != 0) {
        rtb_Switch2_c = GET_P_DPRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_c > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_c -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_c = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_li = (uint8)(rtb_Switch2_c > 0.0F);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/GT1/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         */
    rtb_GT_cm = (uint8)(GET_S_DPRSIA_DlcLeRDP_met() > GET_P_DPRSMI_DlcLimitMin_met());
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EQ3/Functionality'/EQ'
         */
    rtb_EQ_ho = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDPMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Relational Operator3/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch8/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met3/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD3TrigTlc_sec(), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_a;
    } else if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_hq = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD2TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_hq;
    } else {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_fl = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD1TrigTlc_sec (), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_fl;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch4/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D (GETA_Y_DPRSMI_LWTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Divide2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_LWTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_lic *= rtb_ip_lookup_fxpt_sfun_7_e;
    /* UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Neg4/Functionality'/Unary Minus' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDP_mps'
         */
    rtb_UnaryMinus_f = -GET_S_DPRSIA_VelLatLnLeRDP_mps();
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus_f, &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Neg/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Neg1/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_LeLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs2/Functionality'/Abs' */
        rtb_Abs_o = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_o, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_la = -rtb_ip_lookup_fxpt_sfun_7_o;
    } else if (GET_S_ABPLBP_LeLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs1/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch'
                 */
        rtb_Abs_ch = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_ch, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_jc = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_la = rtb_ip_lookup_fxpt_sfun_7_jc;
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant8'/Constant'
                 */
        rtb_Switch_la = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Sum/Functionality'/Sum' incorporates:
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Divide5/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_la += rtb_Switch_lic * rtb_ip_lookup_fxpt_sfun_7_j;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Relational Operator5/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TlcLeRDP_sec'
         */
    rtb_LT_g = (uint8)(GET_S_DPRSIA_TlcLeRDP_sec() < rtb_Switch_la);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant14'/Constant'
         *  Inport: '<Root>/S_LCFRCV_RDPMode_nu'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Relational Operator8/Functionality'/EQ'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch7/Functionality'/Switch'
         */
    if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 3) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_jbi = F32_PTR_IP1D (GETA_Y_DPRSMI_VXMD3TrigDlc_met(), &x_dps);
        }
        rtb_Switch_k = rtb_ip_lookup_fxpt_sfun_7_jbi;
    } else if (((sint32)GET_S_LCFRCV_RDPMode_nu()) == 2) {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD2TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_lk = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD2TrigDlc_met (), &x_dps);
        }
        rtb_Switch_k = rtb_ip_lookup_fxpt_sfun_7_lk;
    } else {
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelX_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_mg = F32_PTR_IP1D(GETA_Y_DPRSMI_VXMD1TrigDlc_met (), &x_dps);
        }
        rtb_Switch_k = rtb_ip_lookup_fxpt_sfun_7_mg;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch3/Functionality'/Switch' */
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_DPRSMI_LWTrigDlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Divide1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_g = rtb_Switch_k * rtb_ip_lookup_fxpt_sfun_7_l;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDPDlcTrgLe_met'
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Divide3/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/LT/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Neg/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDP_DlcTriggerCustom_bool()) != 0) {
        rtb_Switch_a3 = GET_S_CUSTOM_RDPDlcTrgLe_met();
    } else {
        if (GET_S_ABPLBP_LeLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs2/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Abs_l = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_l, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_jn = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Switch_a3 = -rtb_ip_lookup_fxpt_sfun_7_jn;
        } else if (GET_S_ABPLBP_LeLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs1/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch'
                         */
            rtb_Abs_aal = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_aal, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_fm = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Switch_a3 = rtb_ip_lookup_fxpt_sfun_7_fm;
        } else {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant8'/Constant'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_a3 = 0.0F;
        }
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), rtb_UnaryMinus_f, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_bn = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_Switch_a3 += rtb_Mul_g * rtb_ip_lookup_fxpt_sfun_7_bn;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator3/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/LT1/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Relational Operator3/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1'
         */
    rtb_DataTypeConversion_c = (uint8)((((DW_dprsmi_UnitDelay1_DSTATE_e <= 0.0F) && (((sint32)rtb_LT_g) != 0)) && (GET_S_DPRSIA_DlcLeRDP_met() < GET_P_DPRSMI_TlcDistanceMin_met())) || (GET_S_DPRSIA_DlcLeRDP_met() < rtb_Switch_a3));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDPDlcLimitLe_met'
         */
    if (((sint32)GET_P_RDP_DlcLimitCustom_bool()) != 0) {
        rtb_Switch_k = GET_S_CUSTOM_RDPDlcLimitLe_met();
    } else {
        rtb_Switch_k = GET_P_DPRSMI_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch4/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/LT2/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         */
    rtb_LT_ot = (uint8)(GET_S_DPRSIA_DlcLeRDP_met() < rtb_Switch_k);
    /* Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         */
    rtb_Switch_k = GET_S_DPRSIA_DrcLeRDP_met() - GET_S_DPRSIA_DlcLeRDP_met();
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Relational Operator4/Functionality'/LT'
         */
    rtb_DataTypeConversion_bn = (uint8)((rtb_Switch_k < GET_P_DPRSMI_LnMrkRdEdgeDistMax_met()) && (rtb_Switch_k > GET_P_DPRSMI_LnMrkRdEdgeDistMin_met()));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Constant9'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Sum/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay'
         */
    if (((((((((sint32)GET_P_DPRSMI_SafeSitStateLn_btm()) & 1) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMI_SafeSitStateLn_btm()) & 2) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMI_SafeSitStateLn_btm()) & 4) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMI_SafeSitStateLn_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMI_SafeSitStateLn_btm()) & 16) != 0) && (!(((sint32) rtb_EQ_ho) != 0)))) {
        rtb_Switch_me = 0U;
    } else if (GET_S_DPRSIA_DlcLeRDP_met() > (rtb_Switch_a3 + GET_P_DPRSMI_SafeSitOffsetLn_met())) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_me = 1U;
    } else {
        rtb_Switch_me = DW_dprsmi_Unit_Delay_DSTATE_kr;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
         */
    rtb_LogicalOperator_ok = (uint8)((DW_dprsmi_Unit_Delay2_DSTATE_d <= 0.0F) && (((sint32)rtb_Switch_me) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator17/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Logical Operator17/Functionality'/AND'
         */
    rtb_DataTypeConversion_fc = (uint8)(((((((sint32)rtb_EQ_ho) != 0) && (((sint32)rtb_DataTypeConversion_c) != 0)) && (((sint32)rtb_LT_ot) != 0)) && (((sint32)rtb_DataTypeConversion_bn) != 0)) && (((sint32) rtb_LogicalOperator_ok) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_dk = (uint8)((!(((sint32)DW_dprsmi_Unit_Delay_DSTATE_in) != 0)) && (((sint32)rtb_DataTypeConversion_fc) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit_Delay'
         */
    if (((sint32)rtb_GT_cm) >= 1) {
        rtb_Switch2_p = DW_dprsmi_Unit_Delay_DSTATE_d;
    } else {
        rtb_Switch2_p = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_dk) != 0) {
        rtb_Switch2_p = GET_P_DPRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_GT_cm) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_p > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_p -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_p = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_h = (uint8)(rtb_Switch2_p > 0.0F);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator15/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator10/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/Logical Operator15/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_cz = (uint8)(((((sint32)rtb_DataTypeConversion_dw) != 0) || ((((((sint32)rtb_GT) != 0) && (((sint32)rtb_RelationalOperator1_li) != 0)) && (((sint32)rtb_EQ_b1) != 0)) && (((sint32)rtb_EQ_ov) != 0))) || ((((((sint32)rtb_GT_cm) != 0) && (((sint32)rtb_RelationalOperator1_h) != 0)) && (((sint32)rtb_EQ_b1) != 0)) && (((sint32)rtb_EQ_ov) != 0)));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Neg2/Functionality'/Unary Minus'
         */
    rtb_LT_hi = (uint8)(GET_S_DPRSIA_DrcRiRDP_met() < (-GET_P_DPRSMI_DrcLimitMin_met()));
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatReRiRDP_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigTrcScalFact_nu(), &x_dps);
    }
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (GET_S_ABPREP_RiReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_k = -rtb_ip_lookup_fxpt_sfun_7_m;
    } else if (GET_S_ABPREP_RiReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_j = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_j, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_f = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCTrcOffset_sec(), &x_dps);
        }
        rtb_Switch_k = rtb_ip_lookup_fxpt_sfun_7_f;
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Constant9'/Constant'
                 */
        rtb_Switch_k = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDP_mps'
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Divide6/Functionality'/Mul'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TrcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_k += rtb_ip_lookup_fxpt_sfun_7_nj * rtb_ip_lookup_fxpt_sfun_7_k;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Relational Operator6/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TrcRiRDP_sec'
         */
    rtb_LT_bx = (uint8)(GET_S_DPRSIA_TrcRiRDP_sec() < rtb_Switch_k);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDPDrcTrgRi_met'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDP_mps'
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDP_DrcTriggerCustom_bool()) != 0) {
        rtb_ip_lookup_fxpt_sfun_7_nj = GET_S_CUSTOM_RDPDrcTrgRi_met();
    } else {
        if (GET_S_ABPREP_RiReClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm ())) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_k = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_k, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_h2 = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICDrcOffset_met(), &x_dps);
            }
            rtb_Switch_mss = -rtb_ip_lookup_fxpt_sfun_7_h2;
        } else if (GET_S_ABPREP_RiReClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_a = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_a, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_hf = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCDrcOffset_met(), &x_dps);
            }
            rtb_Switch_mss = rtb_ip_lookup_fxpt_sfun_7_hf;
        } else {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Constant9'/Constant'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Switch_mss = 0.0F;
        }
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatReRiRDP_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigDrcScalFact_nu(), &x_dps);
        }
        rtb_ip_lookup_fxpt_sfun_7_nj = (rtb_Mul_f2 * rtb_ip_lookup_fxpt_sfun_7_n) + rtb_Switch_mss;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Switch8/Functionality'/Switch' */
    /* UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Neg4/Functionality'/Unary Minus' */
    rtb_Mul_f2 = -rtb_ip_lookup_fxpt_sfun_7_nj;
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator3/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/GT3/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Relational Operator2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Neg3/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DrcThresholds/Neg4/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1'
         */
    rtb_DataTypeConversion_ct = (uint8)((((DW_dprsmi_UnitDelay1_DSTATE_d <= 0.0F) && (((sint32)rtb_LT_bx) != 0)) && (GET_S_DPRSIA_DrcRiRDP_met() > (-GET_P_DPRSMI_TrcDistanceMin_met()))) || (GET_S_DPRSIA_DrcRiRDP_met() > (-rtb_ip_lookup_fxpt_sfun_7_nj)));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDPDrcLimitRi_met'
         */
    if (((sint32)GET_P_RDP_DrcLimitCustom_bool()) != 0) {
        rtb_ip_lookup_fxpt_sfun_7_nj = GET_S_CUSTOM_RDPDrcLimitRi_met();
    } else {
        rtb_ip_lookup_fxpt_sfun_7_nj = GET_P_DPRSMI_DrcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/GT/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Neg4/Functionality'/Unary Minus'
         */
    rtb_GT_ij = (uint8)(GET_S_DPRSIA_DrcRiRDP_met() > (-rtb_ip_lookup_fxpt_sfun_7_nj));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator4/Functionality'/AND'
         */
    rtb_EQ_ho = (uint8)((((sint32)rtb_DataTypeConversion_ct) != 0) && (((sint32) rtb_GT_ij) != 0));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Constant9'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/from_data_definition6'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay1'
         */
    if (((((((((sint32)GET_P_DPRSMI_SafeSitStateRe_btm()) & 1) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMI_SafeSitStateRe_btm()) & 2) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMI_SafeSitStateRe_btm()) & 4) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMI_SafeSitStateRe_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMI_SafeSitStateRe_btm()) & 16) != 0) && (((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))))) {
        rtb_Switch_k0 = 0U;
    } else if (GET_S_DPRSIA_DrcRiRDP_met() < (rtb_Mul_f2 - GET_P_DPRSMI_SafeSitOffsetRe_met())) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_k0 = 1U;
    } else {
        rtb_Switch_k0 = DW_dprsmi_Unit_Delay_DSTATE_b;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe'/Unit_Delay2'
         */
    rtb_LogicalOperator_g = (uint8)((DW_dprsmi_Unit_Delay2_DSTATE_b <= 0.0F) && (((sint32)rtb_Switch_k0) != 0));
    /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs1/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         */
    rtb_ip_lookup_fxpt_sfun_7_nj = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT1/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec5'/Constant'
         */
    rtb_LT_ir = (uint8)(rtb_ip_lookup_fxpt_sfun_7_nj < GET_P_DPRSMI_LnOverlapCrv_1pm());
    /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Abs2/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_ABPREP_RiReClthCrv_1pm'
         */
    rtb_ip_lookup_fxpt_sfun_7_nj = f32_abs_f32(GET_S_ABPREP_RiReClthCrv_1pm());
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/P_LDPSA_OnTargetFinishTime_sec4'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator5/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/LT2/Functionality'/LT'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum/Functionality'/Sum'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Sum3/Functionality'/Sum'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/RoadEdgeLaneMarkingOverlap/Neg1/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_e1 = (uint8)((((sint32) GET_P_DPRSMI_TrgIgnoreLnContg_bool()) != 0) || (((((((sint32) GET_P_DPRSMI_LnOverlapEnable_bool()) != 0) && ((GET_S_DPRSIA_DrcRiRDP_met() - GET_S_DPRSIA_DlcRiRDP_met()) < GET_P_DPRSMI_LnOverlapInnerDist_met())) && ((GET_S_DPRSIA_DrcRiRDP_met() - GET_S_DPRSIA_DlcRiRDP_met()) > (-GET_P_DPRSMI_LnOverlapOuterDist_met()))) && (((sint32)rtb_LT_ir) != 0)) && (rtb_ip_lookup_fxpt_sfun_7_nj < GET_P_DPRSMI_LnOverlapCrv_1pm())));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ3/Functionality'/EQ'
         */
    rtb_LT_ir = (uint8)((((((sint32)rtb_EQ_ho) != 0) && (((sint32) rtb_LogicalOperator_g) != 0)) && ((((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))))) && (((sint32) rtb_DataTypeConversion_e1) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3'/Unit_Delay'
         */
    LogicalOperator_f = (uint8)((!(((sint32)DW_dprsmi_Unit_Delay_DSTATE_e) != 0)) && (((sint32)rtb_LT_ir) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Constant1'/Constant'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay1'
         */
    if (((sint32)rtb_LT_hi) >= 1) {
        rtb_Switch_mss = DW_dprsmi_Unit_Delay1_DSTATE_e;
    } else {
        rtb_Switch_mss = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec7'/Constant'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_f) != 0) {
        rtb_Switch_mss = GET_P_DPRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_hi) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch1'
                         */
            if (rtb_Switch_mss > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch_mss -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch_mss = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE2/Functionality'/Constant'
         */
    rtb_RelationalOperator1_lu = (uint8)(rtb_Switch_mss > 0.0F);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDPRi_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND5/Functionality'/AND'
         */
    rtb_EQ_ad = (uint8)((((sint32)GET_S_DPRSIA_SideCondRDPRi_btf()) & ((sint32) GET_P_DPRSMI_SideCondEnable_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/AND1/Functionality'/AND'
         */
    rtb_EQ_fs = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMI_FctCustomTrgRi_btm())) == 0);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/AND1/Functionality'/AND'
         */
    rtb_DataTypeConversion_jc = (uint8)((((((sint32)rtb_LT_hi) != 0) && (((sint32)rtb_RelationalOperator1_lu) != 0)) && (((sint32)rtb_EQ_ad) != 0)) && (((sint32)rtb_EQ_fs) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator19/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Logical Operator19/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion_gz = (uint8)((((((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) && (((sint32) rtb_EQ_ho) != 0)) && (((sint32)rtb_LogicalOperator_g) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2'/Unit_Delay'
         */
    LogicalOperator_g = (uint8)((!(((sint32)DW_dprsmi_Unit_Delay_DSTATE_n) != 0)) && (((sint32)rtb_DataTypeConversion_gz) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay'
         */
    if (((sint32)rtb_LT_hi) >= 1) {
        rtb_Switch2_m5 = DW_dprsmi_Unit_Delay_DSTATE_p;
    } else {
        rtb_Switch2_m5 = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/P_LDPSA_OnTargetFinishTime_sec6'/Constant'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_g) != 0) {
        rtb_Switch2_m5 = GET_P_DPRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_hi) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Switch2_m5 > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Switch2_m5 -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Switch2_m5 = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_l = (uint8)(rtb_Switch2_m5 > 0.0F);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Neg4/Functionality'/Unary Minus'
         */
    rtb_LT_if = (uint8)(GET_S_DPRSIA_DlcRiRDP_met() < (-GET_P_DPRSMI_DlcLimitMin_met()));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EQ3/Functionality'/EQ'
         */
    rtb_EQ_be = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))));
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_VelY_mps */
        FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatLnRiRDP_mps(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_jb = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigTlcScalFact_nu(), &x_dps);
    }
    /* Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Divide6/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDP_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_VYTrigTlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_j = rtb_Switch_lic * rtb_ip_lookup_fxpt_sfun_7_jb;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Neg2/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (GET_S_ABPLBP_RiLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm())) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs3/Functionality'/Abs' */
        rtb_Abs_c = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_c, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_lic = -rtb_ip_lookup_fxpt_sfun_7_h;
    } else if (GET_S_ABPLBP_RiLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
        /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Abs4/Functionality'/Abs' incorporates:
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch'
                 */
        rtb_Abs_jd = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_Curvature_1pm */
            FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_jd, &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_ma = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCTlcOffset_sec(), &x_dps);
        }
        rtb_Switch_lic = rtb_ip_lookup_fxpt_sfun_7_ma;
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Constant9'/Constant'
                 */
        rtb_Switch_lic = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Switch5/Functionality'/Switch' */
    /* Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/TlcThresholds/Sum1/Functionality'/Sum' */
    rtb_Switch_lic += rtb_Mul_j;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator1/Functionality'/LT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_TlcRiRDP_sec'
         */
    rtb_LT_e2 = (uint8)(GET_S_DPRSIA_TlcRiRDP_sec() < rtb_Switch_lic);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Inport: '<Root>/S_CUSTOM_RDPDlcTrgRi_met'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDP_mps'
         *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Divide4/Functionality'/Mul'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/GT1/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/LT1/Functionality'/LT'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Neg3/Functionality'/Unary Minus'
         */
    if (((sint32)GET_P_RDP_DlcTriggerCustom_bool()) != 0) {
        rtb_ip_lookup_fxpt_sfun_7_nj = GET_S_CUSTOM_RDPDlcTrgRi_met();
    } else {
        if (GET_S_ABPLBP_RiLnClthCrv_1pm() < (-GET_P_DPRSMI_CurveDetectThreshold_1pm ())) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs3/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_p = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvICDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_p, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_oa = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvICDlcOffset_met(), &x_dps);
            }
            rtb_Mul_j = -rtb_ip_lookup_fxpt_sfun_7_oa;
        } else if (GET_S_ABPLBP_RiLnClthCrv_1pm() > GET_P_DPRSMI_CurveDetectThreshold_1pm()) {
            /* Abs: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Abs4/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch'
                         */
            rtb_Abs_m = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_CrvOCDlcOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_m, &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_ev = F32_PTR_IP1D (GETA_Y_DPRSMI_CrvOCDlcOffset_met(), &x_dps);
            }
            rtb_Mul_j = rtb_ip_lookup_fxpt_sfun_7_ev;
        } else {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch6/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Constant9'/Constant'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch5/Functionality'/Switch'
                         */
            rtb_Mul_j = 0.0F;
        }
        /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Y_DPLSMI_VYTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT x_dps;
            /* Calculate value */
            /* Find indices on X Axis: X_LCF_VelY_mps */
            FDPS_PTR_F32(GETA_X_LCF_VelY_mps(), GET_S_DPRSIA_VelLatLnRiRDP_mps(), &x_dps);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_mw = F32_PTR_IP1D (GETA_Y_DPRSMI_VYTrigDlcScalFact_nu(), &x_dps);
        }
        rtb_ip_lookup_fxpt_sfun_7_nj = (rtb_Mul_g * rtb_ip_lookup_fxpt_sfun_7_mw) + rtb_Mul_j;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Switch8/Functionality'/Switch' */
    /* UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus' */
    rtb_Mul_g = -rtb_ip_lookup_fxpt_sfun_7_nj;
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant1'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/GT2/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator4/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Neg3/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/DlcThresholds/Neg4/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1'
         */
    rtb_DataTypeConversion_fm = (uint8)((((DW_dprsmi_UnitDelay1_DSTATE_c <= 0.0F) && (((sint32)rtb_LT_e2) != 0)) && (GET_S_DPRSIA_DlcRiRDP_met() > (-GET_P_DPRSMI_TlcDistanceMin_met()))) || (GET_S_DPRSIA_DlcRiRDP_met() > (-rtb_ip_lookup_fxpt_sfun_7_nj)));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_RDPDlcLimitRi_met'
         */
    if (((sint32)GET_P_RDP_DlcLimitCustom_bool()) != 0) {
        rtb_ip_lookup_fxpt_sfun_7_nj = GET_S_CUSTOM_RDPDlcLimitRi_met();
    } else {
        rtb_ip_lookup_fxpt_sfun_7_nj = GET_P_DPRSMI_DlcLimitMax_met();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Thresholds/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/GT3/Functionality'/GT' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Neg1/Functionality'/Unary Minus'
         */
    rtb_GT_jn = (uint8)(GET_S_DPRSIA_DlcRiRDP_met() > (-rtb_ip_lookup_fxpt_sfun_7_nj));
    /* Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Sum/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         */
    rtb_ip_lookup_fxpt_sfun_7_nj = GET_S_DPRSIA_DlcRiRDP_met() - GET_S_DPRSIA_DrcRiRDP_met();
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec3'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND2/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Relational Operator5/Functionality'/LT'
         */
    rtb_DataTypeConversion_aq = (uint8)((rtb_ip_lookup_fxpt_sfun_7_nj < GET_P_DPRSMI_LnMrkRdEdgeDistMax_met()) && (rtb_ip_lookup_fxpt_sfun_7_nj > GET_P_DPRSMI_LnMrkRdEdgeDistMin_met()));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Constant9'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LaneChangeDetected_bool'
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND3/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND6/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND8/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Logical Operator2/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/LT/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RelatOperator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RelatOperator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Relational Operator5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/AND9/Functionality'/AND'
         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Sum1/Functionality'/Sum'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay1'
         */
    if (((((((((sint32)GET_P_DPRSMI_SafeSitStateLn_btm()) & 1) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)))) || (((((sint32) GET_P_DPRSMI_SafeSitStateLn_btm()) & 2) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))))) || (((((sint32)GET_P_DPRSMI_SafeSitStateLn_btm()) & 4) != 0) && (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))))) || (((((sint32) GET_P_DPRSMI_SafeSitStateLn_btm()) & 8) != 0) && (((sint32) GET_S_ABPLBP_LaneChangeDetected_bool()) != 0))) || (((((sint32) GET_P_DPRSMI_SafeSitStateLn_btm()) & 16) != 0) && (!(((sint32) rtb_EQ_be) != 0)))) {
        rtb_UnitDelay1_d1 = 0U;
    } else if (GET_S_DPRSIA_DlcRiRDP_met() < (rtb_Mul_g - GET_P_DPRSMI_SafeSitOffsetLn_met())) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_UnitDelay1_d1 = 1U;
    } else {
        rtb_UnitDelay1_d1 = DW_dprsmi_Unit_Delay_DSTATE_m;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/RSFLIPFLOP/Functionality'/Switch' */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
         */
    rtb_LogicalOperator_ip = (uint8)((DW_dprsmi_Unit_Delay2_DSTATE_p <= 0.0F) && (((sint32)rtb_UnitDelay1_d1) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator20/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator20/Functionality'/AND'
         */
    rtb_DataTypeConversion_iy = (uint8)(((((((sint32)rtb_EQ_be) != 0) && (((sint32)rtb_DataTypeConversion_fm) != 0)) && (((sint32)rtb_GT_jn) != 0)) && (((sint32)rtb_DataTypeConversion_aq) != 0)) && (((sint32) rtb_LogicalOperator_ip) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality'/Comparison'
         */
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_j = (uint8)((!(((sint32)DW_dprsmi_Unit_Delay_DSTATE_f) != 0)) && (((sint32)rtb_DataTypeConversion_iy) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Constant5'/Constant'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit_Delay'
         */
    if (((sint32)rtb_LT_if) >= 1) {
        rtb_Mul_j = DW_dprsmi_Unit_Delay_DSTATE_dy;
    } else {
        rtb_Mul_j = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Switch/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/P_LDPSA_OnTargetFinishTime_sec4'/Constant'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
         */
    if (((sint32)LogicalOperator_j) != 0) {
        rtb_Mul_j = GET_P_DPRSMI_TriggerHoldingTime_sec();
    } else {
        if (((sint32)rtb_LT_if) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch1'
                         */
            if (rtb_Mul_j > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
                rtb_Mul_j -= GET_S_LCFRCV_SysCycleTimeSen_sec();
            } else {
                rtb_Mul_j = 0.0F;
            }
            /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch2' */
        }
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_RelationalOperator1_ag = (uint8)(rtb_Mul_j > 0.0F);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator15/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator10/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/Logical Operator15/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_ex = (uint8)(((((sint32)rtb_DataTypeConversion_jc) != 0) || ((((((sint32)rtb_LT_hi) != 0) && (((sint32)rtb_RelationalOperator1_l) != 0)) && (((sint32)rtb_EQ_ad) != 0)) && (((sint32)rtb_EQ_fs) != 0))) || ((((((sint32)rtb_LT_if) != 0) && (((sint32)rtb_RelationalOperator1_ag) != 0)) && (((sint32)rtb_EQ_ad) != 0)) && (((sint32)rtb_EQ_fs) != 0)));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Logical Operator/Functionality'/OR'
         */
    rtb_DataTypeConversion_ke = (uint8)((((sint32)rtb_DataTypeConversion_cz) != 0) || (((sint32)rtb_DataTypeConversion_ex) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_ke;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND1/Functionality'/AND'
         */
    rtb_EQ_az = (uint8)((((sint32)GET_S_DPRSIA_SpecificRDP_btf()) & ((sint32) GET_P_DPRSMI_StrgRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND3/Functionality'/AND'
         */
    rtb_EQ_k1 = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMI_StrgRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter13'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND6/Functionality'/AND'
         */
    rtb_EQ_io = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPRSMI_StrgRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND2/Functionality'/AND'
         */
    rtb_EQ_be = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMI_StrgRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND4/Functionality'/AND'
         */
    rtb_EQ_ho = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPRSMI_StrgRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND5/Functionality'/AND'
         */
    rtb_EQ_md = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPRSMI_StrgRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/AND7/Functionality'/AND'
         */
    rtb_EQ_mx = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMI_StrgRdyFctCustom_btm())) == 0);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDP_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND7/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Abort/AND3/Functionality'/AND'
         */
    rtb_DataTypeConversion_g = (uint8)((((((((((sint32) GET_S_DPRSIA_SpecificRDP_btf()) & ((sint32)GET_P_DPRSMI_AbortSpecific_btm())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMI_AbortVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPRSMI_AbortDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMI_AbortFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPRSMI_AbortFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPRSMI_AbortFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMI_AbortFctCustom_btm())) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_DataTypeConversion_o0 = (uint8)(!(((sint32)rtb_DataTypeConversion_g) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_e = (uint8)((((((((((sint32)rtb_EQ_az) != 0) && (((sint32)rtb_EQ_k1) != 0)) && (((sint32)rtb_EQ_io) != 0)) && (((sint32) rtb_EQ_be) != 0)) && (((sint32)rtb_EQ_ho) != 0)) && (((sint32)rtb_EQ_md) != 0)) && (((sint32)rtb_EQ_mx) != 0)) && (((sint32)rtb_DataTypeConversion_o0) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion_e;
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Not1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter14'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDP_btf'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Not1/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ4/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ5/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/NEQ6/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND3/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND4/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND5/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Suppresion/AND7/Functionality'/AND'
         */
    rtb_DataTypeConversion_f = (uint8)(!((((((((((sint32) GET_S_DPRSIA_SpecificRDP_btf()) & ((sint32)GET_P_DPRSMI_SuppressSpecific_btm ())) != 0) || ((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMI_SuppressVehSt_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPRSMI_SuppressDrvSt_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMI_SuppressFctStCtr_btm())) != 0)) || ((((sint32) GET_S_VDPDRV_SysStError_btf()) & ((sint32)GET_P_DPRSMI_SuppressFctStErr_btm())) != 0)) || ((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32) GET_P_DPRSMI_SuppressFctStNotAv_btm())) != 0)) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMI_SuppressFctCustom_btm())) != 0)));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator3/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter11'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter17'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND4/Functionality'/AND'
         */
    rtb_EQ_hc = (uint8)((((sint32)GET_S_DPRSIA_SpecificRDP_btf()) & ((sint32) GET_P_DPRSMI_WeakRdySpecific_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND6/Functionality'/AND'
         */
    rtb_EQ_h1z = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32) GET_P_DPRSMI_WeakRdyVehSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND2/Functionality'/AND'
         */
    rtb_EQ_b5 = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32) GET_P_DPRSMI_WeakRdyDrvSt_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator4/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND5/Functionality'/AND'
         */
    rtb_EQ_gr = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMI_WeakRdyFctStCtr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter16'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter8'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND7/Functionality'/AND'
         */
    rtb_EQ_og2 = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPRSMI_WeakRdyFctStErr_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter15'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND8/Functionality'/AND'
         */
    rtb_EQ_jz = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPRSMI_WeakRdyFctStNotAv_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Relational Operator1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/AND1/Functionality'/AND'
         */
    rtb_EQ_oq = (uint8)((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMI_WeakRdyFctCustom_btm())) == 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/RelatOperator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/from_data_definition1'/state_source'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady'/Unit Delay1'
         */
    rtb_EQ_lzr = (uint8)(((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/P_LDPSA_BlockingTimeDuration_sec1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template'
         */
    if ((((sint32)DW_dprsmi_Template_DSTATE) != 0) && (!(((sint32)rtb_EQ_lzr) != 0))) {
        rtb_Switch2_ok = GET_P_DPRSMI_BlockingTimeDuration_sec();
    } else if (DW_dprsmi_Unit_Delay_DSTATE_l > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay'
                 */
        rtb_Switch2_ok = DW_dprsmi_Unit_Delay_DSTATE_l - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_ok = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Not/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/OR/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/OR2/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Not/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/RelatOperator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady'/Unit Delay1'
         */
    rtb_DataTypeConversion_o = (uint8)(!(((((sint32)BI_dprsmi_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) || (((sint32) rtb_EQ_lzr) != 0)) || (rtb_Switch2_ok > 0.0F)));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator/Functionality'/AND'
         */
    rtb_DataTypeConversion_dj = (uint8)(((((((((((sint32) rtb_DataTypeConversion_f) != 0) && (((sint32)rtb_EQ_hc) != 0)) && (((sint32) rtb_EQ_h1z) != 0)) && (((sint32)rtb_EQ_b5) != 0)) && (((sint32)rtb_EQ_gr) != 0)) && (((sint32)rtb_EQ_og2) != 0)) && (((sint32)rtb_EQ_jz) != 0)) && (((sint32)rtb_EQ_oq) != 0)) && (((sint32)rtb_DataTypeConversion_o) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate[3] = rtb_DataTypeConversion_dj;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/Equality1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_EQ_mq = (uint8)(((sint32)GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8)E_LCF_FunctionV3Type_E_LCF_RDP_nu)));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/Relational Operator5/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/from_data_definition2'/state_source'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation'/Unit Delay1'
         */
    rtb_UnitDelay1_d = (uint8)(((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/Application Parameter1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay1'
         */
    if ((!(((sint32)DW_dprsmi_Unit_Delay1_DSTATE_o) != 0)) && (((sint32) rtb_UnitDelay1_d) != 0)) {
        rtb_Switch2_hb = GET_P_DPRSMI_DegrTimeOut_sec();
    } else if (DW_dprsmi_Unit_Delay_DSTATE_a > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay'
                 */
        rtb_Switch2_hb = DW_dprsmi_Unit_Delay_DSTATE_a - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_hb = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysStOffLatDMC_bool'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/AND1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/AND2/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/NOT/Functionality'/NOT'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/NOT1/Functionality'/NOT'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_ij = (uint8)((((!(((sint32)rtb_EQ_mq) != 0)) || (((sint32)GET_S_LCFRCV_SysStOffLatDMC_bool()) != 0)) || (!(rtb_Switch2_hb > 0.0F))) && (((sint32)rtb_UnitDelay1_d) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_ij;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND1/Functionality'/AND'
         */
    rtb_NE_gw = (uint8)((((sint32)GET_P_DPRSMI_FinishCondEnable_btm()) & 1) == 0);
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_nj = F32_PTR_IP1D (GETA_Y_DPRSMI_LWHazardFinishTol_met(), &x_dps);
    }
    /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Y_DPLSMI_LWNoHazardFinishTol_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT x_dps;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
        /* Direct accesing curve (used as module input) */
        rtb_Switch_hf = F32_PTR_IP1D(GETA_Y_DPRSMI_LWNoHazardFinishTol_met(), &x_dps);
    }
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ1/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant7'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND2/Functionality'/AND'
         */
    rtb_DataTypeConversion_n0 = (uint8)((((sint32) GET_P_DPRSMI_FinishCondEnable_btm()) & 2) == 0);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ3/Functionality'/EQ'
         */
    rtb_NE_cs2 = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPREP_LeReHeading_rad'
         */
    if (((sint32)rtb_NE_cs2) != 0) {
        rtb_Switch_kh = GET_S_ABPREP_LeReHeading_rad();
    } else {
        rtb_Switch_kh = GET_S_ABPLBP_LeLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator1/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad2'/Constant'
         */
    rtb_LT_k = (uint8)(rtb_Switch_kh < GET_P_DPRSMI_NoHazardFinishHeadAng_rad());
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator11/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad3'/Constant'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg4/Functionality'/Unary Minus'
         */
    rtb_GT_d5 = (uint8)(rtb_Switch_kh > (-GET_P_DPRSMI_HazardFinishHeadAng_rad()));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ6/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND3/Functionality'/AND'
         */
    rtb_Switch_gb = (uint8)((((sint32)GET_P_DPRSMI_FinishCondEnable_btm()) & 4) == 0);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDP_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDP_mps'
         */
    if (((sint32)rtb_NE_cs2) != 0) {
        rtb_Switch_kh = GET_S_DPRSIA_VelLatReLeRDP_mps();
    } else {
        rtb_Switch_kh = GET_S_DPRSIA_VelLatLnLeRDP_mps();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps4'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator2/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator6/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg5/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit = (uint8)((rtb_Switch_kh < GET_P_DPRSMI_NoHazardFinishVelLat_mps()) && (rtb_Switch_kh > (-GET_P_DPRSMI_HazardFinishVelLat_mps())));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR6/Functionality'/OR'
         */
    rtb_sfun_setbit = (uint8)((((sint32)rtb_Switch_gb) != 0) || (((sint32) rtb_sfun_setbit) != 0));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ7/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant5'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Constant8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TriggerConditionEnable_btm'/Constant'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/AND4/Functionality'/AND'
         */
    rtb_sfun_setbit_b = (uint8)((((sint32)GET_P_DPRSMI_FinishCondEnable_btm()) & 8) == 0);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch4/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         */
    if (((sint32)rtb_NE_cs2) != 0) {
        rtb_Switch_kh = GET_S_DPRSIA_DrcLeRDP_met();
    } else {
        rtb_Switch_kh = GET_S_DPRSIA_DlcLeRDP_met();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch4/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_NoHazardFinishTol_met2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_DPRTTG_LeTgtTrajPosY0_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator2/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator4/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator9/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR1/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR8/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator14/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator15/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator5/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_sfun_setbit = (uint8)(((((((sint32)DW_dprsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && ((((sint32)rtb_NE_gw) != 0) || ((GET_S_DPRTTG_LeTgtTrajPosY0_met() > (-rtb_ip_lookup_fxpt_sfun_7_nj)) && (GET_S_DPRTTG_LeTgtTrajPosY0_met() < rtb_Switch_hf)))) && ((((sint32)rtb_DataTypeConversion_n0) != 0) || ((((sint32)rtb_LT_k) != 0) && (((sint32)rtb_GT_d5) != 0)))) && (((sint32) rtb_sfun_setbit) != 0)) && ((((sint32)rtb_sfun_setbit_b) != 0) || ((rtb_Switch_kh > GET_P_DPRSMI_HazardFinishDlc_met()) && (rtb_Switch_kh < GET_P_DPRSMI_NoHazardFinishDlc_met()))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition7'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/EQ5/Functionality'/EQ'
         */
    rtb_NE_cs2 = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPREP_RiReHeading_rad'
         */
    if (((sint32)rtb_NE_cs2) != 0) {
        rtb_Switch_kh = GET_S_ABPREP_RiReHeading_rad();
    } else {
        rtb_Switch_kh = GET_S_ABPLBP_RiLnClthHeading_rad();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator10/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad1'/Constant'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg3/Functionality'/Unary Minus'
         */
    rtb_LT_k = (uint8)(rtb_Switch_kh > (-GET_P_DPRSMI_NoHazardFinishHeadAng_rad()));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator8/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_TargetLateralHeading_rad4'/Constant'
         */
    rtb_GT_d5 = (uint8)(rtb_Switch_kh < GET_P_DPRSMI_HazardFinishHeadAng_rad());
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDP_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDP_mps'
         */
    if (((sint32)rtb_NE_cs2) != 0) {
        rtb_Switch_kh = GET_S_DPRSIA_VelLatReRiRDP_mps();
    } else {
        rtb_Switch_kh = GET_S_DPRSIA_VelLatLnRiRDP_mps();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_VelXMin_mps3'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator11/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR7/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator12/Functionality'/GT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator13/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg1/Functionality'/Unary Minus'
         */
    rtb_Switch_gb = (uint8)((((sint32)rtb_Switch_gb) != 0) || ((rtb_Switch_kh > (-GET_P_DPRSMI_NoHazardFinishVelLat_mps())) && (rtb_Switch_kh < GET_P_DPRSMI_HazardFinishVelLat_mps())));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         */
    if (((sint32)rtb_NE_cs2) != 0) {
        rtb_Switch_kh = GET_S_DPRSIA_DrcRiRDP_met();
    } else {
        rtb_Switch_kh = GET_S_DPRSIA_DlcRiRDP_met();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Switch5/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_HazardFinishTol_met3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_NoHazardFinishTol_met3'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator8/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR9/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator16/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator17/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg6/Functionality'/Unary Minus'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg8/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit_b = (uint8)((((sint32)rtb_sfun_setbit_b) != 0) || ((rtb_Switch_kh < (-GET_P_DPRSMI_HazardFinishDlc_met())) && (rtb_Switch_kh > (-GET_P_DPRSMI_NoHazardFinishDlc_met()))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_DPRTTG_RiTgtTrajPosY0_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator6/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator7/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR2/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator7/Functionality'/LT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Relational Operator9/Functionality'/GT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Neg2/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_sfun_setbit_b = (uint8)(((((((sint32)DW_dprsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && ((((sint32)rtb_NE_gw) != 0) || ((GET_S_DPRTTG_RiTgtTrajPosY0_met() < rtb_ip_lookup_fxpt_sfun_7_nj) && (GET_S_DPRTTG_RiTgtTrajPosY0_met() > (-rtb_Switch_hf))))) && ((((sint32)rtb_DataTypeConversion_n0) != 0) || ((((sint32)rtb_LT_k) != 0) && (((sint32)rtb_GT_d5) != 0)))) && (((sint32) rtb_Switch_gb) != 0)) && (((sint32)rtb_sfun_setbit_b) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/Logical Operator/Functionality'/OR'
         */
    rtb_sfun_setbit_b = (uint8)((((sint32)rtb_sfun_setbit) != 0) || (((sint32) rtb_sfun_setbit_b) != 0));
    /* Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Logical Operator' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant1'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator1'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
         */
    rtb_GT_d5 = (uint8)((DW_dprsmi_UnitDelay1_DSTATE_n <= 0.0F) && (((sint32) rtb_sfun_setbit_b) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate[5] = rtb_GT_d5;
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter4'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND1/Functionality'/AND'
         */
    rtb_sfun_setbit = (uint8)((((sint32)GET_S_DPRSIA_SpecificRDP_btf()) & ((sint32)GET_P_DPRSMI_CancelSpecific_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_VDPDRV_VehStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND3/Functionality'/AND'
         */
    rtb_Switch_gb = (uint8)((((sint32)GET_S_VDPDRV_VehStInvalid_btf()) & ((sint32)GET_P_DPRSMI_CancelVehSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ6/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter13'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter14'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND7/Functionality'/AND'
         */
    rtb_Switch_d1 = (uint8)((((sint32)GET_S_VDPDRV_DrvStInvalid_btf()) & ((sint32)GET_P_DPRSMI_CancelDrvSt_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ2/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter6'/Constant'
         *  Inport: '<Root>/S_VDPDRV_ActiveStCtrl_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND2/Functionality'/AND'
         */
    rtb_NE_cs2 = (uint8)((((sint32)GET_S_VDPDRV_ActiveStCtrl_btf()) & ((sint32) GET_P_DPRSMI_CancelFctStCtr_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ3/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter9'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStError_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND4/Functionality'/AND'
         */
    rtb_NE_gw = (uint8)((((sint32)GET_S_VDPDRV_SysStError_btf()) & ((sint32) GET_P_DPRSMI_CancelFctStErr_btm())) != 0);
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ4/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter10'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_SysStNotAvailable_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND5/Functionality'/AND'
         */
    rtb_NE_li = (uint8)((((sint32)GET_S_VDPDRV_SysStNotAvailable_btf()) & ((sint32)GET_P_DPRSMI_CancelFctStNotAv_btm())) != 0);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/from_data_definition6'/state_source'
         *  Inport: '<Root>/S_DPRSIA_DlcLeRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcLeRDP_met'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnLeRDP_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReLeRDP_mps'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/EQ3/Functionality'/EQ'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Switch2/Functionality'/Switch'
         */
    if ((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
        rtb_Switch_kh = GET_S_DPRSIA_DrcLeRDP_met();
        rtb_Switch_hf = GET_S_DPRSIA_VelLatReLeRDP_mps();
    } else {
        rtb_Switch_kh = GET_S_DPRSIA_DlcLeRDP_met();
        rtb_Switch_hf = GET_S_DPRSIA_VelLatLnLeRDP_mps();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/GT/Functionality'/GT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Constant'/Constant'
         */
    rtb_DataTypeConversion_n0 = (uint8)(rtb_Switch_hf > 0.0F);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met2'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator5/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator1/Functionality'/GT'
         */
    rtb_sfun_setbit_e = (uint8)((((sint32)rtb_DataTypeConversion_n0) != 0) && (rtb_Switch_kh > GET_P_DPRSMI_NoHazardCancelDlc_met()));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met'/Constant'
         *  Inport: '<Root>/S_DPRTTG_LeTgtTrajPosY0_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator7/Functionality'/GT'
         */
    rtb_DataTypeConversion_n0 = (uint8)((((sint32)rtb_DataTypeConversion_n0) != 0) && (GET_S_DPRTTG_LeTgtTrajPosY0_met() > GET_P_DPRSMI_NoHazardCancelTol_met()));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator3/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Neg1/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit_e = (uint8)(((rtb_Switch_kh < (-GET_P_DPRSMI_HazardCancelTol_met())) || (((sint32)rtb_sfun_setbit_e) != 0)) || (((sint32)rtb_DataTypeConversion_n0) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/from_data_definition5'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator2/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator5/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_gh = (uint8)((((sint32)DW_dprsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && (((sint32)rtb_sfun_setbit_e) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/EQ4/Functionality'/EQ'
         */
    rtb_sfun_setbit_e = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_DPRSIA_DlcRiRDP_met'
         *  Inport: '<Root>/S_DPRSIA_DrcRiRDP_met'
         *  Inport: '<Root>/S_DPRSIA_VelLatLnRiRDP_mps'
         *  Inport: '<Root>/S_DPRSIA_VelLatReRiRDP_mps'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Switch3/Functionality'/Switch'
         */
    if (((sint32)rtb_sfun_setbit_e) != 0) {
        rtb_Switch_kh = GET_S_DPRSIA_DrcRiRDP_met();
        rtb_Switch_hf = GET_S_DPRSIA_VelLatReRiRDP_mps();
    } else {
        rtb_Switch_kh = GET_S_DPRSIA_DlcRiRDP_met();
        rtb_Switch_hf = GET_S_DPRSIA_VelLatLnRiRDP_mps();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/LT/Functionality'/LT' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Constant1'/Constant'
         */
    rtb_sfun_setbit_e = (uint8)(rtb_Switch_hf < 0.0F);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met3'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator2/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Neg3/Functionality'/Unary Minus'
         */
    rtb_DataTypeConversion_n0 = (uint8)((((sint32)rtb_sfun_setbit_e) != 0) && (rtb_Switch_kh < (-GET_P_DPRSMI_NoHazardCancelDlc_met())));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_NoHazardCancelTol_met1'/Constant'
         *  Inport: '<Root>/S_DPRTTG_RiTgtTrajPosY0_met'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator12/Functionality'/LT'
         *  UnaryMinus: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Neg2/Functionality'/Unary Minus'
         */
    rtb_sfun_setbit_e = (uint8)((((sint32)rtb_sfun_setbit_e) != 0) && (GET_S_DPRTTG_RiTgtTrajPosY0_met() < (-GET_P_DPRSMI_NoHazardCancelTol_met())));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/P_LDPSA_HazardCancelTol_met1'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator6/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator9/Functionality'/GT'
         */
    rtb_sfun_setbit_e = (uint8)(((rtb_Switch_kh > GET_P_DPRSMI_HazardCancelTol_met()) || (((sint32)rtb_DataTypeConversion_n0) != 0)) || (((sint32)rtb_sfun_setbit_e) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/from_data_definition4'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator3/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Relational Operator6/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_fk = (uint8)((((sint32)DW_dprsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32)rtb_sfun_setbit_e) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/CLatDev/Logical Operator1/Functionality'/OR'
         */
    rtb_sfun_setbit_e = (uint8)((((sint32)rtb_DataTypeConversion_gh) != 0) || (((sint32)rtb_DataTypeConversion_fk) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition10'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition11'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator3/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator10/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator11/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator9/Functionality'/EQ'
         */
    rtb_sfun_setbit_p = (uint8)(((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) || (((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY)))) || (((sint32) GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition6'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition7'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator2/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator5/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay2'
         */
    rtb_sfun_setbit_c = (uint8)((((sint32)DW_dprsmi_UnitDelay2_DSTATE) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32)DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND3/Functionality'/AND'
         */
    rtb_sfun_setbit_c = (uint8)((((sint32)rtb_sfun_setbit_p) != 0) && (((sint32) rtb_sfun_setbit_c) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator14/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDPLe_btf'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND4/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator1/Functionality'/OR'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator14/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ2/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ3/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator6/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND7/Functionality'/AND'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay2'
         */
    rtb_sfun_setbit_c = (uint8)(((((((sint32)GET_S_DPRSIA_SideCondRDPLe_btf()) & ((sint32)GET_P_DPRSMI_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMI_FctCustomCancelLe_btm())) != 0)) || ((((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) && ((((sint32) DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))))) || (((sint32) rtb_sfun_setbit_c) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition2'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator7/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator4/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_ix = (uint8)((((sint32)DW_dprsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) && (((sint32)rtb_sfun_setbit_c) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition14'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition8'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator4/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator14/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator7/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay2'
         */
    rtb_sfun_setbit_c = (uint8)((((sint32)DW_dprsmi_UnitDelay2_DSTATE) == ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition15'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator17/Functionality'/EQ'
         */
    rtb_sfun_setbit_c = (uint8)((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) && (((sint32)rtb_sfun_setbit_c) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition12'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition13'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition18'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator10/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator12/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator13/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator18/Functionality'/EQ'
         */
    rtb_sfun_setbit_p = (uint8)(((((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG))) || (((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY)))) || (((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition16'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition17'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND5/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator6/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator15/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator16/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay2'
         */
    rtb_sfun_setbit_p = (uint8)((((sint32)rtb_sfun_setbit_p) != 0) && ((((sint32) DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_CONTG))) || (((sint32) DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH)))));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/P_LDPSA_TriggerConditionEnable_btm4'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDPRi_btf'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ1/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/NEQ4/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/AND8/Functionality'/AND'
         */
    rtb_sfun_setbit_c = (uint8)(((((((sint32)GET_S_DPRSIA_SideCondRDPRi_btf()) & ((sint32)GET_P_DPRSMI_SideCondCancel_btm())) != 0) || ((((sint32) GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32)GET_P_DPRSMI_FctCustomCancelRi_btm())) != 0)) || (((sint32)rtb_sfun_setbit_c) != 0)) || (((sint32)rtb_sfun_setbit_p) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/from_data_definition3'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Logical Operator9/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/TriggerReasonCancellingConditions/Relational Operator8/Functionality'/EQ'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5'
         */
    rtb_DataTypeConversion_ic = (uint8)((((sint32)DW_dprsmi_UnitDelay5_DSTATE) == ((sint32)((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) && (((sint32)rtb_sfun_setbit_c) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator10/Functionality'/OR'
         */
    rtb_sfun_setbit_c = (uint8)((((sint32)rtb_DataTypeConversion_ix) != 0) || (((sint32)rtb_DataTypeConversion_ic) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter15'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter16'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter17'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter18'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator8/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ7/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ8/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND8/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND9/Functionality'/AND'
         */
    rtb_sfun_setbit_p = (uint8)(((((sint32)GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32)GET_P_DPRSMI_QuTrajPlanCancel_btm())) != 0) || ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32)GET_P_DPRSMI_QuTrajCtrCancel_btm ())) != 0));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Relational Operator11/Functionality'/EQ' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/from_data_definition1'/state_source'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay3'
         */
    rtb_LT_k = (uint8)(((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4'
         */
    if ((!(((sint32)DW_dprsmi_Unit_Delay4_DSTATE) != 0)) && (((sint32)rtb_LT_k) != 0)) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/from_data_definition2'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/from_data_definition4'/state_source'
                 *  Inport: '<Root>/S_ABPLBP_LaneWidth_met'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/OR/Functionality'/OR'
                 *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Mul/Functionality'/Mul'
                 *  Product: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Mul1/Functionality'/Mul'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Relational Operator1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Relational Operator2/Functionality'/EQ'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay2'
                 */
        if ((((sint32)DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY))) || (((sint32) DW_dprsmi_UnitDelay2_DSTATE) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS)))) {
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_LaneWidth_met */
                FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_ho = F32_PTR_IP1D (GETA_Y_DPRSMI_LWContrMaxDurReScal_nu(), &x_dps);
            }
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_VelX_mps */
                FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_ff = F32_PTR_IP1D (GETA_Y_DPRSMI_VXContrMaxDurRe_sec(), &x_dps);
            }
            rtb_Switch_kh = rtb_ip_lookup_fxpt_sfun_7_ff * rtb_ip_lookup_fxpt_sfun_7_ho;
        } else {
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_LWTrigDlcScalFact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_LaneWidth_met */
                FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_ABPLBP_LaneWidth_met(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_ky = F32_PTR_IP1D (GETA_Y_DPRSMI_LWContrMaxDurLnScal_nu(), &x_dps);
            }
            /* S-Function Block sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Y_DPLSMI_VXMD1TrigDlc_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT x_dps;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_VelX_mps */
                FDPS_PTR_F32(GETA_X_LCF_VelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &x_dps);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_by = F32_PTR_IP1D (GETA_Y_DPRSMI_VXContrMaxDurLn_sec(), &x_dps);
            }
            rtb_Switch_kh = rtb_ip_lookup_fxpt_sfun_7_by * rtb_ip_lookup_fxpt_sfun_7_ky;
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/Switch/Functionality'/Switch' */
    } else if (DW_dprsmi_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3'
                 */
        rtb_Switch_kh = DW_dprsmi_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                 */
        rtb_Switch_kh = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/AND/Functionality'/AND'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_n0 = (uint8)((((sint32)rtb_LT_k) != 0) && (!(rtb_Switch_kh > 0.0F)));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter12'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Application Parameter7'/Constant'
         *  Inport: '<Root>/S_CUSTOM_PrjSpecQu_btf'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator5/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/NEQ5/Functionality'/NE'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/AND6/Functionality'/AND'
         */
    rtb_DataTypeConversion_a = (uint8)(((((((((((((sint32)rtb_sfun_setbit) != 0) || (((sint32)rtb_Switch_gb) != 0)) || (((sint32)rtb_Switch_d1) != 0)) || (((sint32)rtb_NE_cs2) != 0)) || (((sint32)rtb_NE_gw) != 0)) || (((sint32) rtb_NE_li) != 0)) || ((((sint32)GET_S_CUSTOM_PrjSpecQu_btf()) & ((sint32) GET_P_DPRSMI_CancelFctCustom_btm())) != 0)) || (((sint32)rtb_sfun_setbit_e) != 0)) || (((sint32)rtb_sfun_setbit_c) != 0)) || (((sint32)rtb_sfun_setbit_p) != 0)) || (((sint32)rtb_DataTypeConversion_n0) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_DataTypeConversion_a;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/ErrorStateRDP/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/ErrorStateRDP/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/ErrorStateRDP/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_LCFRCV_ErrorStateRDP_bool'
         */
    if (((sint32)GET_P_DPRSMI_ErrorStateRDPEnable_bool()) != 0) {
        rtb_Switch_b3 = GET_S_LCFRCV_ErrorStateRDP_bool();
    } else {
        rtb_Switch_b3 = GET_P_DPRSMI_ErrorStateRDP_bool();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/ErrorStateRDP/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Switch_b3;
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_a = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/D_SysStateRDP/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMI_SysStateRDP_btf(rtb_sfun_setbit_a);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_a[0] = rtb_sfun_setbit;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_a[2] = rtb_NE_cs2;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_a[4] = rtb_sfun_setbit_e;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_a[5] = rtb_sfun_setbit_c;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_a[6] = rtb_sfun_setbit_p;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_a[7] = rtb_DataTypeConversion_n0;
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator7/Functionality'/OR'
         */
    rtb_VectorConcatenate_a[1] = (uint8)((((sint32)rtb_Switch_gb) != 0) || (((sint32)rtb_Switch_d1) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/Logical Operator9/Functionality'/OR'
         */
    rtb_VectorConcatenate_a[3] = (uint8)((((sint32)rtb_NE_gw) != 0) || (((sint32) rtb_NE_li) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/set_bit/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_a = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMI_Cancel_btf(rtb_sfun_setbit_a);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/NOT/Functionality'/Data Type Conversion' incorporates:
                                                  *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/Application Parameter2'/Constant'
                                                  *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/NOT/Functionality'/NOT'
                                                  */
    rtb_sfun_setbit_a = (uint8)(!(((sint32)GET_P_DPRSMI_LatDMCClearEnable_bool()) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysStOnLatDMC_bool'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/OR/Functionality'/OR'
         */
    rtb_sfun_setbit_a = (uint8)((((sint32)rtb_sfun_setbit_a) != 0) || (((sint32) GET_S_LCFRCV_SysStOnLatDMC_bool()) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/Application Parameter3'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/Application Parameter5'/Constant'
         *  Inport: '<Root>/S_TCTCLM_QuServTrajCtr_nu'
         *  Inport: '<Root>/S_TPLFBT_QuStatusTrajPlan_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/EQ1/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/RDPClearance/AND3/Functionality'/AND'
         */
    rtb_NE_gw = (uint8)((((((sint32)rtb_sfun_setbit_a) != 0) && ((((sint32) GET_S_TPLFBT_QuStatusTrajPlan_nu()) & ((sint32) GET_P_DPRSMI_QuTrajPlanClearance_btm())) == 0)) && ((((sint32) GET_S_TCTCLM_QuServTrajCtr_nu()) & ((sint32) GET_P_DPRSMI_QuTrajCtrClearance_btm())) == 0)) && (((sint32)rtb_EQ_mq) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/AND/Functionality'/AND'
         */
    rtb_EQ_mq = (uint8)(((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32) rtb_DataTypeConversion_dj) != 0)) && (((sint32)rtb_DataTypeConversion_ke) != 0));
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality'/Comparison'
         */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/P_LDPSA_BlockingTimeDuration_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut'/Unit_Delay'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut'/Unit_Delay1'
         */
    if ((!(((sint32)DW_dprsmi_Unit_Delay1_DSTATE_b) != 0)) && (((sint32)rtb_EQ_mq) != 0)) {
        rtb_Switch2_fc = GET_P_DPRSMI_RequestTimeOut_sec();
    } else if (DW_dprsmi_Unit_Delay_DSTATE_k > GET_S_LCFRCV_SysCycleTimeSen_sec()) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut'/Unit_Delay'
                 */
        rtb_Switch2_fc = DW_dprsmi_Unit_Delay_DSTATE_k - GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2_fc = 0.0F;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Switch' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING'/fcg' */
    /* Chart: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI'/StateMachineRDP' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition5'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/from_data_definition6'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/Application Parameter1'/Constant'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/TIMERRETRIGGER_RE/Functionality'/Relational Operator1'
         *
         * Block description for 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI'/StateMachineRDP':
         *  X.2.1.1.2
         */
    /* Gateway: DPRSMI_cg/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP */
    /* During: DPRSMI_cg/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP */
    if (((uint32)((sint32)DW_dprsmi_is_active_c14_DPRSMI_cg)) == 0U) {
        /* Entry: DPRSMI_cg/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP */
        DW_dprsmi_is_active_c14_DPRSMI_cg = 1U;
        /* Entry Internal: DPRSMI_cg/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP */
        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':132' */
        if (!(((sint32)GET_P_RDP_Existing_nu()) != 0)) {
            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':139' */
            DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_NOT_PRESENT;
            /* Entry 'NOT_PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':137' */
            BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
        } else if ((((sint32)GET_P_RDP_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_b3) != 0))) {
            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':155' */
            DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_PRESENT;
            /* Entry Internal 'PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':149' */
            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':152' */
            if (!(((sint32)rtb_Switch_do) != 0)) {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':133' */
                DW_dprsmi_is_PRESENT = DPRSMI_IN_DISABLED;
                /* Entry 'DISABLED': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':142' */
                BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
            } else {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':143' */
                DW_dprsmi_is_PRESENT = DPRSMI_IN_PASSIVE;
                /* Entry 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                BI_dprsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
            }
        } else {
            if ((((sint32)GET_P_RDP_Existing_nu()) != 0) && (((sint32)rtb_Switch_b3) != 0)) {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':150' */
                DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':131' */
                BI_dprsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            }
        }
    } else {
        switch (DW_dprsmi_is_c14_DPRSMI_cg) {
        case DPRSMI_IN_ERROR:
            /* During 'ERROR': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':131' */
            if ((!(((sint32)rtb_Switch_b3) != 0)) || (!(((sint32)GET_P_RDP_Existing_nu ()) != 0))) {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':141' */
                if (!(((sint32)GET_P_RDP_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':139' */
                    DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':137' */
                    BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_RDP_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_b3) != 0))) {
                    /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':155' */
                    DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':149' */
                    /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':152' */
                    if (!(((sint32)rtb_Switch_do) != 0)) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':133' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':142' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':143' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                } else {
                    if ((((sint32)GET_P_RDP_Existing_nu()) != 0) && (((sint32) rtb_Switch_b3) != 0)) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':150' */
                        DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':131' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        case DPRSMI_IN_NOT_PRESENT:
            /* During 'NOT_PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':137' */
            if (((sint32)GET_P_RDP_Existing_nu()) != 0) {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':129' */
                if (!(((sint32)GET_P_RDP_Existing_nu()) != 0)) {
                    /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':139' */
                    DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_NOT_PRESENT;
                    /* Entry 'NOT_PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':137' */
                    BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
                } else if ((((sint32)GET_P_RDP_Existing_nu()) != 0) && (!(((sint32) rtb_Switch_b3) != 0))) {
                    /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':155' */
                    DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_PRESENT;
                    /* Entry Internal 'PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':149' */
                    /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':152' */
                    if (!(((sint32)rtb_Switch_do) != 0)) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':133' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':142' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':143' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                } else {
                    if ((((sint32)GET_P_RDP_Existing_nu()) != 0) && (((sint32) rtb_Switch_b3) != 0)) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':150' */
                        DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_ERROR;
                        /* Entry 'ERROR': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':131' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
                    }
                }
            }
            break;
        default:
            /* During 'PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':149' */
            if (!(((sint32)GET_P_RDP_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':145' */
                /* Exit Internal 'PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':149' */
                DW_dprsmi_is_PRESENT = DPRSMI_IN_NO_ACTIVE_CHILD;
                DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_NOT_PRESENT;
                /* Entry 'NOT_PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':137' */
                BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_NOTPRESENT_nu);
            } else if ((((sint32)rtb_Switch_b3) != 0) && (((sint32) GET_P_RDP_Existing_nu()) != 0)) {
                /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':144' */
                /* Exit Internal 'PRESENT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':149' */
                DW_dprsmi_is_PRESENT = DPRSMI_IN_NO_ACTIVE_CHILD;
                DW_dprsmi_is_c14_DPRSMI_cg = DPRSMI_IN_ERROR;
                /* Entry 'ERROR': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':131' */
                BI_dprsmi_SysState_nu = ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_ERROR_nu);
            } else {
                switch (DW_dprsmi_is_PRESENT) {
                case DPRSMI_IN_ACTIVE:
                    /* During 'ACTIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':146' */
                    if ((((((sint32)rtb_GT_d5) != 0) || (((sint32)rtb_DataTypeConversion_a) != 0)) || (!(((sint32)rtb_DataTypeConversion_e) != 0))) || (!(((sint32)rtb_NE_gw) != 0))) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':153' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':148' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    }
                    break;
                case DPRSMI_IN_DISABLED:
                    /* During 'DISABLED': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':142' */
                    if (((sint32)rtb_Switch_do) != 0) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':128' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_PASSIVE;
                        /* Entry 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                    }
                    break;
                case DPRSMI_IN_PASSIVE:
                    /* During 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                    if (!(((sint32)rtb_Switch_do) != 0)) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':151' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_DISABLED;
                        /* Entry 'DISABLED': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':142' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                    } else {
                        if (((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32) rtb_DataTypeConversion_dj) != 0)) && (((sint32) rtb_DataTypeConversion_ke) != 0)) {
                            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':154' */
                            DW_dprsmi_is_PRESENT = DPRSMI_IN_REQUEST;
                            /* Entry 'REQUEST': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':156' */
                            BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu);
                        }
                    }
                    break;
                case DPRSMI_IN_RAMPOUT:
                    /* During 'RAMPOUT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':148' */
                    if (((sint32)rtb_DataTypeConversion_ij) != 0) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':130' */
                        if (!(((sint32)rtb_Switch_do) != 0)) {
                            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':133' */
                            DW_dprsmi_is_PRESENT = DPRSMI_IN_DISABLED;
                            /* Entry 'DISABLED': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':142' */
                            BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_DISABLED_nu);
                        } else {
                            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':143' */
                            DW_dprsmi_is_PRESENT = DPRSMI_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                            BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                default:
                    /* During 'REQUEST': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':156' */
                    if ((((sint32)rtb_NE_gw) != 0) && (!(((sint32)rtb_DataTypeConversion_e) != 0))) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':138' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_RAMPOUT;
                        /* Entry 'RAMPOUT': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':148' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu);
                    } else if ((((sint32)rtb_NE_gw) != 0) && (((sint32) rtb_DataTypeConversion_e) != 0)) {
                        /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':147' */
                        DW_dprsmi_is_PRESENT = DPRSMI_IN_ACTIVE;
                        /* Entry 'ACTIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':146' */
                        BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu);
                    } else {
                        if ((!(((sint32)rtb_NE_gw) != 0)) && ((!(rtb_Switch2_fc > 0.0F)) || (!(((sint32)rtb_DataTypeConversion_e) != 0)))) {
                            /* Transition: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':134' */
                            DW_dprsmi_is_PRESENT = DPRSMI_IN_PASSIVE;
                            /* Entry 'PASSIVE': 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineRDP':140' */
                            BI_dprsmi_SysState_nu = ((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_PASSIVE_nu);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    /* End of Chart: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI'/StateMachineRDP' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/from_data_definition1'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/from_data_definition2'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/from_data_definition3'/state_source'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Logical Operator/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Relational Operator1/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Relational Operator2/Functionality'/EQ'
         */
    rtb_Switch_do = (uint8)(((((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide'/Template'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide'/Template1'
         */
    if (((sint32)DW_dprsmi_Template1_DSTATE) != 0) {
        rtb_DataTypeConversion_ke = DW_dprsmi_Template_DSTATE_n;
    } else if (((sint32)rtb_DataTypeConversion_cz) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition5'/state_source'
                 */
        rtb_DataTypeConversion_ke = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT);
    } else if (((sint32)rtb_DataTypeConversion_ex) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition4'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_ke = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT);
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/from_data_definition1'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_ke = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/from_data_definition4'/state_source'
         */
    if (((sint32)rtb_Switch_do) != 0) {
        rtb_DataTypeConversion_ij = rtb_DataTypeConversion_ke;
    } else {
        rtb_DataTypeConversion_ij = ((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_NONE);
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/Switch4/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation'/Unit_Delay1'
         */
    if (((sint32)rtb_UnitDelay1_d) != 0) {
        rtb_NE_gw = DW_dprsmi_Unit_Delay1_DSTATE_p;
    } else {
        rtb_NE_gw = rtb_DataTypeConversion_g;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/Switch4/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/branch'/copy1' */
    SET_S_DPRSMI_FunctionAborted_bool(rtb_NE_gw);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_sfun_setbit_b) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1'
                 */
        if (DW_dprsmi_UnitDelay1_DSTATE_n > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_UnitDelay1_DSTATE_n -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/P_LDPSA_OnTargetFinishTime_sec'/Constant'
                 */
        DW_dprsmi_UnitDelay1_DSTATE_n = GET_P_DPRSMI_OnTargetFinishTime_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationFinish/TURNONDELAYTIME/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/AND3/Functionality'/AND'
         */
    rtb_VectorConcatenate2[3] = (uint8)((((sint32)rtb_LT_ot) != 0) && (((sint32) rtb_DataTypeConversion_bn) != 0));
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2[0] = rtb_GT_cm;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2[1] = rtb_RelationalOperator1_h;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In3' */
    rtb_VectorConcatenate2[2] = LogicalOperator_dk;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In5' */
    rtb_VectorConcatenate2[4] = rtb_DataTypeConversion_c;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In6' */
    rtb_VectorConcatenate2[5] = rtb_LogicalOperator_ok;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In7' */
    rtb_VectorConcatenate2[6] = rtb_EQ_b1;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In8' */
    rtb_VectorConcatenate2[7] = rtb_EQ_ov;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_me) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
                 */
        if (DW_dprsmi_Unit_Delay2_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_Unit_Delay2_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/Application Parameter1'/Constant'
                 */
        DW_dprsmi_Unit_Delay2_DSTATE_d = GET_P_DPRSMI_SafeSitDelayLn_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_g) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1'
                 */
        if (DW_dprsmi_UnitDelay1_DSTATE_e > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_UnitDelay1_DSTATE_e -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/Application Parameter2'/Constant'
                 */
        DW_dprsmi_UnitDelay1_DSTATE_e = GET_P_DPRSMI_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/set_bit2/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_a = temp;
    }
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1[0] = rtb_GT;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1[1] = rtb_RelationalOperator1_li;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In3' */
    rtb_VectorConcatenate1[2] = LogicalOperator_d;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1[3] = rtb_DataTypeConversion_df;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In5' */
    rtb_VectorConcatenate1[4] = rtb_LT_fz;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In6' */
    rtb_VectorConcatenate1[5] = rtb_LogicalOperator_n;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In7' */
    rtb_VectorConcatenate1[6] = rtb_EQ_b1;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In8' */
    rtb_VectorConcatenate1[7] = rtb_EQ_ov;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2_h[0] = rtb_GT;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2_h[1] = rtb_RelationalOperator1_pa;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In3' */
    rtb_VectorConcatenate2_h[2] = LogicalOperator_l;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In4' */
    rtb_VectorConcatenate2_h[3] = rtb_DataTypeConversion_e5;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In5' */
    rtb_VectorConcatenate2_h[4] = rtb_LT_fz;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In6' */
    rtb_VectorConcatenate2_h[5] = rtb_LogicalOperator_n;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In7' */
    rtb_VectorConcatenate2_h[6] = rtb_EQ_b1;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In8' */
    rtb_VectorConcatenate2_h[7] = rtb_EQ_ov;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_p3) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2'
                 */
        if (DW_dprsmi_Unit_Delay2_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_Unit_Delay2_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/Application Parameter3'/Constant'
                 */
        DW_dprsmi_Unit_Delay2_DSTATE = GET_P_DPRSMI_SafeSitDelayRe_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_p) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1'
                 */
        if (DW_dprsmi_UnitDelay1_DSTATE > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_UnitDelay1_DSTATE -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/Application Parameter2'/Constant'
                 */
        DW_dprsmi_UnitDelay1_DSTATE = GET_P_DPRSMI_TrcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/set_bit1/Functionality'/sfun_setbit' */
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
        rtb_sfun_setbit_c = temp;
    }
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/set_bit2/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate2_h[0];
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
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2_o[0] = rtb_LT_if;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2_o[1] = rtb_RelationalOperator1_ag;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In3' */
    rtb_VectorConcatenate2_o[2] = LogicalOperator_j;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In5' */
    rtb_VectorConcatenate2_o[4] = rtb_DataTypeConversion_fm;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In6' */
    rtb_VectorConcatenate2_o[5] = rtb_LogicalOperator_ip;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In7' */
    rtb_VectorConcatenate2_o[6] = rtb_EQ_ad;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/ConcatBufferAtVector Concatenate2In8' */
    rtb_VectorConcatenate2_o[7] = rtb_EQ_fs;
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Logical Operator3/Functionality'/AND'
         */
    rtb_VectorConcatenate2_o[3] = (uint8)((((sint32)rtb_GT_jn) != 0) && (((sint32)rtb_DataTypeConversion_aq) != 0));
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_UnitDelay1_d1) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2'
                 */
        if (DW_dprsmi_Unit_Delay2_DSTATE_p > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_Unit_Delay2_DSTATE_p -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/Application Parameter1'/Constant'
                 */
        DW_dprsmi_Unit_Delay2_DSTATE_p = GET_P_DPRSMI_SafeSitDelayLn_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_e2) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1'
                 */
        if (DW_dprsmi_UnitDelay1_DSTATE_c > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_UnitDelay1_DSTATE_c -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/Application Parameter2'/Constant'
                 */
        DW_dprsmi_UnitDelay1_DSTATE_c = GET_P_DPRSMI_TlcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/set_bit2/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate2_o[0];
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
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate1_p[0] = rtb_LT_hi;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate1_p[1] = rtb_RelationalOperator1_l;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In3' */
    rtb_VectorConcatenate1_p[2] = LogicalOperator_g;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In4' */
    rtb_VectorConcatenate1_p[3] = rtb_DataTypeConversion_ct;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In5' */
    rtb_VectorConcatenate1_p[4] = rtb_GT_ij;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In6' */
    rtb_VectorConcatenate1_p[5] = rtb_LogicalOperator_g;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In7' */
    rtb_VectorConcatenate1_p[6] = rtb_EQ_ad;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate1In8' */
    rtb_VectorConcatenate1_p[7] = rtb_EQ_fs;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In1' */
    rtb_VectorConcatenate2_g[0] = rtb_LT_hi;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In2' */
    rtb_VectorConcatenate2_g[1] = rtb_RelationalOperator1_lu;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In3' */
    rtb_VectorConcatenate2_g[2] = LogicalOperator_f;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In4' */
    rtb_VectorConcatenate2_g[3] = rtb_DataTypeConversion_e1;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In5' */
    rtb_VectorConcatenate2_g[4] = rtb_GT_ij;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In6' */
    rtb_VectorConcatenate2_g[5] = rtb_LogicalOperator_g;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In7' */
    rtb_VectorConcatenate2_g[6] = rtb_EQ_ad;
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/ConcatBufferAtVector Concatenate2In8' */
    rtb_VectorConcatenate2_g[7] = rtb_EQ_fs;
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_Switch_k0) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe'/Unit_Delay2'
                 */
        if (DW_dprsmi_Unit_Delay2_DSTATE_b > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe'/Unit_Delay2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_Unit_Delay2_DSTATE_b -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe'/Unit_Delay2' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/Application Parameter2'/Constant'
                 */
        DW_dprsmi_Unit_Delay2_DSTATE_b = GET_P_DPRSMI_SafeSitDelayRe_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe/TURNONDELAYTIME/Functionality'/Switch2' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    if (((sint32)rtb_LT_bx) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Constant'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Relational Operator'
                 *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1'
                 */
        if (DW_dprsmi_UnitDelay1_DSTATE_d > 0.0F) {
            /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            DW_dprsmi_UnitDelay1_DSTATE_d -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch4' */
    } else {
        /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit Delay1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/Application Parameter2'/Constant'
                 */
        DW_dprsmi_UnitDelay1_DSTATE_d = GET_P_DPRSMI_TrcValidMinTime_sec();
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/TURNONDELAYTIME/Functionality'/Switch2' */
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate1_p[0];
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
        rtb_sfun_setbit_b = temp;
    }
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/set_bit2/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate2_g[0];
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
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Logical Operator10/Functionality'/AND'
         */
    rtb_GT = (uint8)((((sint32)rtb_DataTypeConversion_e) != 0) && (((sint32) rtb_DataTypeConversion_dj) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[0] = (uint8)(!(((sint32)rtb_EQ_az) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[1] = (uint8)(!(((sint32)rtb_EQ_k1) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[2] = (uint8)(!(((sint32)rtb_EQ_io) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator5/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[5] = (uint8)(!(((sint32)rtb_EQ_md) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[6] = (uint8)(!(((sint32)rtb_EQ_mx) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[3] = (uint8)(!(((sint32)rtb_EQ_be) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[4] = (uint8)(!(((sint32)rtb_EQ_ho) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/Logical Operator9/Functionality'/NOT'
         */
    rtb_VectorConcatenate_h[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_o0) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_h[0];
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
        rtb_Switch_gb = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/StrongReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMI_StrongReady_btf(rtb_Switch_gb);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Switch3/Functionality'/Switch' incorporates:
                                                   *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                                                   *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                                                   *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch'
                                                   *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch9/Functionality'/Switch'
                                                   *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason'/Template'
                                                   *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason'/Template1'
                                                   */
    if (((sint32)DW_dprsmi_Template1_DSTATE_b) != 0) {
        rtb_DataTypeConversion_dw = DW_dprsmi_Template_DSTATE_k;
    } else if (((sint32)rtb_DataTypeConversion_dw) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition6'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition7'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/EQ2/Functionality'/EQ'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 */
        if (((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) {
            rtb_DataTypeConversion_dw = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS);
        } else {
            rtb_DataTypeConversion_dw = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY);
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch3/Functionality'/Switch' */
    } else if (((sint32)rtb_DataTypeConversion_cz) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dw = GET_S_DPRSIA_TriggerReasonLeRDP_nu();
    } else if (((sint32)rtb_DataTypeConversion_jc) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition2'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition4'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition5'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/EQ1/Functionality'/EQ'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch'
                 */
        if (((sint32)GET_S_DPRSIA_TriggerReasonRiRDP_nu()) == ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_BOTH))) {
            rtb_DataTypeConversion_dw = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_LN_OPPOS);
        } else {
            rtb_DataTypeConversion_dw = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_RDEDG_ONLY);
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch4/Functionality'/Switch' */
    } else if (((sint32)rtb_DataTypeConversion_ex) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch9/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dw = GET_S_DPRSIA_TriggerReasonRiRDP_nu();
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerReason/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_dw = ((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG);
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator1/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[4] = (uint8)(!(((sint32)rtb_EQ_og2) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator10/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator10/Functionality'/NOT'
         */
    rtb_Switch_gb = (uint8)(!(((sint32)rtb_EQ_b5) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator2/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[6] = (uint8)(!(((sint32)rtb_EQ_oq) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator3/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[0] = (uint8)(!(((sint32)rtb_DataTypeConversion_f) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator4/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator4/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[1] = (uint8)(!(((sint32)rtb_EQ_hc) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator6/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator6/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[3] = (uint8)(!(((sint32)rtb_EQ_gr) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator7/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator7/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[5] = (uint8)(!(((sint32)rtb_EQ_jz) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator8/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator8/Functionality'/NOT'
         */
    rtb_VectorConcatenate_e[7] = (uint8)(!(((sint32)rtb_DataTypeConversion_o) != 0));
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/Logical Operator5/Functionality'/NOT'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate_e[2] = (uint8)((!(((sint32)rtb_EQ_h1z) != 0)) || (((sint32)rtb_Switch_gb) != 0));
    /* S-Function (sfun_setbit): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/set_bit/Functionality'/sfun_setbit' */
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
        rtb_Switch_gb = temp;
    }
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/set_bit/Functionality'/DTC_out' */
    SET_D_DPRSMI_WeakReady_btf(rtb_Switch_gb);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/branch2'/copy1' */
    SET_S_DPRSMI_TriggerReason_nu(rtb_DataTypeConversion_dw);
    /* DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/NOT/Functionality'/Data Type Conversion' incorporates:
                                                                *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/NOT/Functionality'/NOT'
                                                                */
    rtb_EQ_ho = (uint8)(!(((sint32)rtb_Switch_b3) != 0));
    /* S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND11/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter3'/Constant'
         */
    rtb_Switch_gb = (uint8)(((sint32)GET_P_DPRSMI_DebugDrvSt_btm()) & ((sint32) GET_P_DPRSMI_CancelDrvSt_btm()));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter1'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Constant11'/Constant'
         *  Inport: '<Root>/S_VDPDRV_DrvStInvalid_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND1/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND10/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/OR3/Functionality'/OR'
         */
    rtb_DataTypeConversion_cz = (uint8)((((sint32)((uint8)(((sint32)((uint8) (((sint32)GET_P_DPRSMI_StrgRdyDrvSt_btm()) & ((sint32) GET_P_DPRSMI_DebugDrvSt_btm())))) | ((sint32)rtb_Switch_gb)))) & ((sint32) GET_S_VDPDRV_DrvStInvalid_btf())) != 0);
    /* S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND4/Functionality'/AND' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter7'/Constant'
         */
    rtb_Switch_gb = (uint8)(((sint32)GET_P_DPRSMI_DebugSpecific_btm()) & ((sint32)GET_P_DPRSMI_CancelSpecific_btm()));
    /* RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter6'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Constant9'/Constant'
         *  Inport: '<Root>/S_DPRSIA_SpecificRDP_btf'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND2/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/OR2/Functionality'/OR'
         */
    rtb_Switch_gb = (uint8)((((sint32)((uint8)(((sint32)((uint8)(((sint32) GET_P_DPRSMI_StrgRdySpecific_btm()) & ((sint32) GET_P_DPRSMI_DebugSpecific_btm())))) | ((sint32)rtb_Switch_gb)))) & ((sint32) GET_S_DPRSIA_SpecificRDP_btf())) != 0);
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter8'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Constant4'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm2'/Constant'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_DPRSIA_SideCondRDPRi_btf'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/OR1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/NEQ6/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Relational Operator2/Functionality'/EQ'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND6/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND7/Functionality'/AND'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch11/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch12/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch8/Functionality'/Switch'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch9/Functionality'/Switch'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState'/Template'
         *  UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState'/Template1'
         */
    if (((sint32)DW_dprsmi_Template1_DSTATE_i) != 0) {
        rtb_DataTypeConversion_g = DW_dprsmi_Template_DSTATE_g;
    } else if (((sint32)rtb_GT_d5) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition1'/state_source'
                 */
        rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_SUCCESSFUL);
    } else if (((sint32)rtb_DataTypeConversion_g) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition9'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_ABORT);
    } else if (((sint32)rtb_DataTypeConversion_ij) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Application Parameter5'/Constant'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Constant13'/Constant'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/P_LDPSA_TriggerConditionEnable_btm1'/Constant'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition15'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_SideCondRDPLe_btf'
                 *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/OR/Functionality'/OR'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/NEQ2/Functionality'/NE'
                 *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND3/Functionality'/AND'
                 *  S-Function (sfix_bitop): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/AND5/Functionality'/AND'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch10/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch7/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        if (((((((sint32)GET_P_DPRSMI_SideCondDebug_btm()) & ((sint32) GET_P_DPRSMI_SideCondCancel_btm())) & ((sint32) GET_S_DPRSIA_SideCondRDPLe_btf())) != 0) || (((sint32) rtb_DataTypeConversion_cz) != 0)) || (((sint32)rtb_Switch_gb) != 0)) {
            rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
        } else if (((sint32)rtb_DataTypeConversion_gh) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition14'/state_source'
                         */
            rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
        } else if (((sint32)rtb_DataTypeConversion_ix) != 0) {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition13'/state_source'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch10/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
        } else {
            /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch10/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition2'/state_source'
                         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch7/Functionality'/Switch'
                         */
            rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch6/Functionality'/Switch' */
    } else if (((((sint32)rtb_DataTypeConversion_cz) != 0) || (((sint32) rtb_Switch_gb) != 0)) || (((((sint32) GET_P_DPRSMI_SideCondDebug_btm()) & ((sint32) GET_P_DPRSMI_SideCondCancel_btm())) & ((sint32) GET_S_DPRSIA_SideCondRDPRi_btf())) != 0)) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch11/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition11'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_DRV);
    } else if (((sint32)rtb_DataTypeConversion_fk) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition10'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LAT_DEV);
    } else if (((sint32)rtb_DataTypeConversion_ic) != 0) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition8'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch9/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_LANE);
    } else {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition16'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch11/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch12/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch5/Functionality'/Switch'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch8/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_g = ((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_CNCL_OTHER);
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition6'/state_source'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Relational Operator5/Functionality'/EQ'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch3/Functionality'/Switch'
         */
    if (((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) {
        rtb_Switch_gb = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_TRIGGER);
    } else if (((sint32)BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch3/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition5'/state_source'
                 */
        rtb_Switch_gb = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_RUNNING);
    } else {
        rtb_Switch_gb = rtb_DataTypeConversion_g;
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition4'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_DPRSIA_TriggerReasonLeRDP_nu'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/AND8/Functionality'/AND'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/NEQ/Functionality'/NE'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_ij) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
        /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch3'/copy1' */
        SET_S_DPRSMI_SysStateRDPLe_nu(rtb_Switch_gb);
    } else if (((((sint32)rtb_GT) != 0) && (((sint32)rtb_EQ_ho) != 0)) && (((sint32)GET_S_DPRSIA_TriggerReasonLeRDP_nu()) != ((sint32) ((uint8)E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG)))) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition2'/state_source'
                 *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch3'/copy1'
                 */
        SET_S_DPRSMI_SysStateRDPLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL));
    } else {
        /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch3'/copy1' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition3'/state_source'
                 *  Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch2/Functionality'/Switch'
                 */
        SET_S_DPRSMI_SysStateRDPLe_nu(((uint8) E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL));
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition10'/state_source'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Relational Operator1/Functionality'/EQ'
         */
    if (((sint32)rtb_DataTypeConversion_ij) != ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
        /* Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition1'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition6'/state_source'
                 *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/from_data_definition8'/state_source'
                 *  Inport: '<Root>/S_DPRSIA_TriggerReasonRiRDP_nu'
                 *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/AND1/Functionality'/AND'
                 *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/NEQ1/Functionality'/NE'
                 */
        if (((((sint32)rtb_GT) != 0) && (((sint32)rtb_EQ_ho) != 0)) && (((sint32) GET_S_DPRSIA_TriggerReasonRiRDP_nu()) != ((sint32)((uint8) E_DPRSMI_TrgReasType_E_DPRSMI_TRGREAS_NO_RDEDG)))) {
            rtb_Switch_gb = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_AVL);
        } else {
            rtb_Switch_gb = ((uint8)E_LCF_SysStateDirectionType_E_LCF_SSD_LN_NOT_AVL);
        }
        /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/Switch3/Functionality'/Switch' */
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch1'/copy1' */
    SET_S_DPRSMI_SysStateRDP_nu(BI_dprsmi_SysState_nu);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch10'/copy1' */
    SET_D_DPRSMI_DrcLeThreshold_met(rtb_Switch_pa);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch11'/copy1' */
    SET_D_DPRSMI_DrcRiThreshold_met(rtb_Mul_f2);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch12'/copy1' */
    SET_D_DPRSMI_TrcLeThreshold_sec(rtb_Switch_n1);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch13'/copy1' */
    SET_D_DPRSMI_TrcRiThreshold_sec(rtb_Switch_k);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch14'/copy1' */
    SET_D_DPRSMI_TriggerReLe_btf(rtb_sfun_setbit_c);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch15'/copy1' */
    SET_D_DPRSMI_TriggerLnReLe_btf(rtb_sfun_setbit_p);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch16'/copy1' */
    SET_D_DPRSMI_TriggerLnLe_btf(rtb_sfun_setbit_a);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch17'/copy1' */
    SET_D_DPRSMI_TriggerReRi_btf(rtb_sfun_setbit_b);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch18'/copy1' */
    SET_D_DPRSMI_TriggerLnReRi_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch19'/copy1' */
    SET_D_DPRSMI_TriggerLnRi_btf(rtb_sfun_setbit_e);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch2'/copy1' */
    SET_S_DPRSMI_SysStateRDPRi_nu(rtb_Switch_gb);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch4'/copy1' */
    SET_S_DPRSMI_DangerousSide_nu(rtb_DataTypeConversion_ij);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch5'/copy1' */
    SET_S_DPRSMI_ReadyToTrigger_bool(rtb_GT);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch6'/copy1' */
    SET_D_DPRSMI_DlcLeThreshold_met(rtb_Switch_a3);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch7'/copy1' */
    SET_D_DPRSMI_DlcRiThreshold_met(rtb_Mul_g);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch8'/copy1' */
    SET_D_DPRSMI_TlcLeThreshold_sec(rtb_Switch_la);
    /* SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/branch9'/copy1' */
    SET_D_DPRSMI_TlcRiThreshold_sec(rtb_Switch_lic);
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/SafeSituationLe'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_i = rtb_Switch_p3;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay_DSTATE_g = rtb_DataTypeConversion;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising1/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay1' */
    DW_dprsmi_Unit_Delay1_DSTATE = rtb_Switch2_ny;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay_DSTATE_as = rtb_DataTypeConversion_dg;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerRoadEdge'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE = rtb_Switch2_c;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/SafeSituationLn'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_kr = rtb_Switch_me;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay_DSTATE_in = rtb_DataTypeConversion_fc;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerLeft/TriggerLaneMarking'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_d = rtb_Switch2_p;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/SafeSituationRe'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_b = rtb_Switch_k0;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay_DSTATE_e = rtb_LT_ir;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising3/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay1' */
    DW_dprsmi_Unit_Delay1_DSTATE_e = rtb_Switch_mss;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay_DSTATE_n = rtb_DataTypeConversion_gz;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge/EdgeRising2/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerRoadEdge'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_p = rtb_Switch2_m5;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/SafeSituationLn'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_m = rtb_UnitDelay1_d1;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay_DSTATE_f = rtb_DataTypeConversion_iy;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking/EdgeRising/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/GenerateDangerousSituationTrigger/TriggerRight/TriggerLaneMarking'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_dy = rtb_Mul_j;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling'/Template' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Template_DSTATE = rtb_EQ_lzr;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime/EdgeFalling/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/WeakReady/BlockingTime'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_l = rtb_Switch2_ok;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay1_DSTATE_o = rtb_UnitDelay1_d;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation/DegradationWatchDog'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_a = rtb_Switch2_hb;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay5' */
    DW_dprsmi_UnitDelay5_DSTATE = rtb_DataTypeConversion_ij;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs'/Unit Delay2' */
    DW_dprsmi_UnitDelay2_DSTATE = rtb_DataTypeConversion_dw;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay4' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay4_DSTATE = rtb_LT_k;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration/EDGERISING1'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/CancelCond/MaxDuration'/Unit_Delay3' */
    DW_dprsmi_Unit_Delay3_DSTATE = rtb_Switch_kh;
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_dprsmi_Unit_Delay1_DSTATE_b = rtb_EQ_mq;
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/TimeOut'/Unit_Delay' */
    DW_dprsmi_Unit_Delay_DSTATE_k = rtb_Switch2_fc;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide'/Template' */
    DW_dprsmi_Template_DSTATE_n = rtb_DataTypeConversion_ke;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/DangerousSide'/Template1' */
    DW_dprsmi_Template1_DSTATE = rtb_Switch_do;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/Degradation'/Unit_Delay1' */
    DW_dprsmi_Unit_Delay1_DSTATE_p = rtb_NE_gw;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason'/Template' */
    DW_dprsmi_Template_DSTATE_k = rtb_DataTypeConversion_dw;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason'/Template1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/from_data_definition3'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/from_data_definition6'/state_source'
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/from_data_definition7'/state_source'
         *  DataTypeConversion: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Logical Operator1/Functionality'/Data Type Conversion'
         *  Logic: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Logical Operator1/Functionality'/OR'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/StateMachineInputs/TriggerReason/Relational Operator5/Functionality'/EQ'
         */
    DW_dprsmi_Template1_DSTATE_b = (uint8)(((((sint32)BI_dprsmi_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))) || (((sint32) BI_dprsmi_SysState_nu) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))));
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState'/Template' */
    DW_dprsmi_Template_DSTATE_g = rtb_DataTypeConversion_g;
    /* Update for UnitDelay: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState'/Template1' incorporates:
         *  Constant: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/from_data_definition12'/state_source'
         *  RelationalOperator: 'sda:DPRSMI/DPRSMI/DPRSMI_SenProcess/OPM/M_DPRSMI/SysState/SysState/Relational Operator1/Functionality'/EQ'
         */
    DW_dprsmi_Template1_DSTATE_i = (uint8)(((sint32)BI_dprsmi_SysState_nu) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu)));
}
#include "Pse_DPRSMI.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
