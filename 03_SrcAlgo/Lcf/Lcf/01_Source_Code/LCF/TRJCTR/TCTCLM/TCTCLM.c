/**************************************************************************
COPYRIGHT (C) $Date: 2019/06/26 12:57:27CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJCTR/TCTCLM_VEH/TCTCLM/i/project.pj $
$Log: TCTCLM.c  $
Revision 1.4.1.4 2019/06/26 12:57:27CEST Schrader, Moritz (uia92406) (uia92406) 
automatically created
File          : TCTCLM
Generated on  : Wed 26.06.2019 at 12:41:07 (UTC+01:00)
MD5           : [3163422898  3112126963  3066547933  1362837869 0](TCTCLM)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TCTCLM.h"
#include "TCTCLM_private.h"
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
#define TCTCLM_START_SEC_DATA_8
#include "TCTCLM_MemMap.h"
static uint8 DW_tctclm_Unit_Delay_DSTATE_fo;
static uint8 DW_tctclm_Unit_Delay13_DSTATE;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_p;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_d;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_n;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_p5;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_nu;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_c;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_i;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_p3;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_ck;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_j;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_pn;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_g;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_cw;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_p5d;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_jg;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_b;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_b2;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_gr;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_a;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_h;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_jl;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_i4;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_ir;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_dg;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_jw;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_f;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_l;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_g3;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_k;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_kq;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_fl;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_m;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_e;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_i0;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_o;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_pa;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_js;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_nj;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_ip;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_i0y;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_lj;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_oj;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_jm;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_ld;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_m3;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_hw;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_kw;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_ei;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_dm;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_ks;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_jo;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_hi;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_bb;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_j5;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_lu;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_fm;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_bs;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_lx;
static uint8 DW_tctclm_Unit_Delay13_DSTATE_dn;
static uint8 DW_tctclm_Unit_Delay2_DSTATE_p;
static uint8 DW_tctclm_Unit_Delay_DSTATE_p;
static uint8 DW_tctclm_Unit_Delay_DSTATE_ks;
static uint8 DW_tctclm_Unit_Delay1_DSTATE_g;
#define TCTCLM_STOP_SEC_DATA_8
#include "TCTCLM_MemMap.h"
#define TCTCLM_START_SEC_DATA_32
#include "TCTCLM_MemMap.h"
static float32 DW_tctclm_UnitDelay5_DSTATE;
static float32 DW_tctclm_UnitDelay1_DSTATE;
static float32 DW_tctclm_Unit_Delay_DSTATE;
static float32 DW_tctclm_Unit_Delay_DSTATE_k;
static float32 DW_tctclm_Unit_Delay_DSTATE_l;
static float32 DW_tctclm_Unit_Delay1_DSTATE;
static float32 DW_tctclm_Unit_Delay3_DSTATE;
static float32 DW_tctclm_Unit_Delay_DSTATE_f;
static float32 DW_tctclm_Unit_Delay1_DSTATE_c;
static float32 DW_tctclm_Unit_Delay2_DSTATE;
#define TCTCLM_STOP_SEC_DATA_32
#include "TCTCLM_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TCTCLM/TCTCLM/INI'/TCTCLM_VehReset'
 * Block description for: 'sda:TCTCLM/TCTCLM/INI'/TCTCLM_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTCLM_VehReset
#include "Pse_TCTCLM.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTCLM_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant'/Constant' */
    SET_S_TCTCLM_Limiter_TgtCrv_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant1'/Constant' */
    SET_S_TCTCLM_LimiterWarning_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant10'/Constant' */
    SET_D_TCTCLM_FlagTimerLastCall_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant11'/Constant' */
    SET_D_TCTCLM_PlausibCheckActive_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant12'/Constant' */
    SET_D_TCTCLM_FrozenVehCrv_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant13'/Constant' */
    SET_D_TCTCLM_SumCtrlSignal_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant14'/Constant' */
    SET_D_TCTCLM_PlausiChkUpLimit_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant15'/Constant' */
    SET_D_TCTCLM_PlausiChkLowLimit_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant16'/Constant' */
    SET_D_TCTCLM_UnplsblDrctnOfRqst_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant17'/Constant' */
    SET_D_TCTCLM_QuServErrMemSet_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant19'/Constant' */
    SET_D_TCTCLM_LimiterWthtErrCntr_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant2'/Constant' */
    SET_D_TCTCLM_QuServErrMemReset_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant3'/Constant' */
    SET_S_TCTCLM_QuServTrajCtr_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant4'/Constant' */
    SET_D_TCTCLM_QualifierService_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant5'/Constant' */
    SET_S_TCTCLM_Ffc_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant6'/Constant' */
    SET_S_TCTCLM_FbcDc_1pm(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant7'/Constant' */
    SET_D_TCTCLM_PlausibCheckPrecond_nu(0U);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant8'/Constant' */
    SET_S_TCTCLM_DeltaFCmd_deg(0.0F);
    /* Constant: 'sda:TCTCLM/TCTCLM/INI/TCTCLM_VehReset/Constant9'/Constant' */
    SET_D_TCTCLM_TimerValue_sec(0.0F);
}
#include "Pse_TCTCLM.h"
/*
 * Output and update for function-call system: 'sda:TCTCLM/TCTCLM'/TCTCLM_VehProcess'
 * Block description for: 'sda:TCTCLM/TCTCLM'/TCTCLM_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTCLM_VehProcess
#include "Pse_TCTCLM.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTCLM_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_ca;
    uint8 rtb_sfun_setbit;
    uint8 rtb_sfun_setbit_b;
    uint8 rtb_sfun_setbit_c;
    uint8 rtb_VectorConcatenate[7];
    uint8 rtb_VectorConcatenate_o[8];
    uint8 rtb_VectorConcatenate_k[3];
    uint8 rtb_SFunction;
    uint8 rtb_DataTypeConversion_h;
    float32 rtb_Switch_k;
    float32 rtb_Switch_gz;
    uint8 rtb_DataTypeConversion;
    float32 rtb_Switch;
    uint8 rtb_Switch1_gq;
    uint8 rtb_DataTypeConversion_m;
    float32 rtb_Switch_ft;
    float32 rtb_Mul;
    float32 rtb_Switch_dl;
    uint8 rtb_RelationalOperator;
    float32 rtb_Mul_c;
    uint8 rtb_RelationalOperator1;
    uint8 rtb_DataTypeConversion_k;
    uint8 rtb_Switch_lo;
    uint8 rtb_Switch1_dv;
    uint8 rtb_Sum_ia;
    uint8 rtb_Switch1_iu;
    uint8 rtb_Sum_bx;
    uint8 rtb_Switch1_k;
    uint8 rtb_Sum_gt;
    uint8 rtb_Switch1_d;
    uint8 rtb_Sum_ed;
    uint8 rtb_Switch1_ej;
    uint8 rtb_Sum_ad;
    uint8 rtb_Switch1_ka;
    uint8 rtb_Sum_a4;
    uint8 rtb_Switch1_fq;
    uint8 rtb_Sum_nor;
    uint8 rtb_Switch1_fh;
    uint8 rtb_Sum_g5;
    uint8 rtb_Switch1_ed;
    uint8 rtb_Sum_eh;
    float32 rtb_Mul_n;
    uint8 rtb_Sum_ga;
    uint8 rtb_Sum_na;
    uint8 rtb_Sum_bdn;
    uint8 rtb_Sum_nqw;
    uint8 rtb_Sum_dc;
    uint8 rtb_Switch1_bs;
    uint8 rtb_Sum_c;
    uint8 rtb_Switch1_ds;
    uint8 rtb_Sum_oz;
    uint8 rtb_Switch1_eh;
    uint8 rtb_Sum_iv;
    float32 rtb_Mul_gy;
    uint8 rtb_RelationalOperator_jk;
    uint8 rtb_RelationalOperator1_e;
    uint8 rtb_Sum_o1;
    uint8 rtb_Sum_as;
    uint8 rtb_Sum_gfe;
    uint8 rtb_Sum_ni;
    uint8 rtb_Sum_pv;
    uint8 rtb_Switch1_it;
    uint8 rtb_Sum_ox;
    uint8 rtb_Switch1_i0;
    uint8 rtb_Sum_fh;
    uint8 rtb_Switch1_ep;
    uint8 rtb_Sum_d;
    uint8 rtb_Sum_cty;
    uint8 rtb_Sum_fn;
    uint8 rtb_Sum_b0b;
    uint8 rtb_Sum_n;
    uint8 rtb_Sum_oa;
    uint8 rtb_Switch1_ol;
    uint8 rtb_Sum_o2;
    uint8 rtb_Switch1_e;
    uint8 rtb_Sum_bp;
    uint8 rtb_Switch1_f4;
    uint8 rtb_Sum_kp;
    float32 rtb_Mul_mv;
    uint8 rtb_RelationalOperator_fk;
    float32 rtb_Mul_m0;
    uint8 rtb_RelationalOperator1_l;
    uint8 rtb_Sum_ps;
    uint8 rtb_Sum_il;
    uint8 rtb_Sum_mi;
    uint8 rtb_Sum_gg;
    uint8 rtb_Sum_h3;
    uint8 rtb_Sum_af;
    uint8 rtb_Switch1_mh;
    uint8 rtb_Sum_a3;
    uint8 rtb_Switch1_l2;
    uint8 rtb_Sum_o;
    uint8 rtb_Sum_b5;
    uint8 rtb_Sum_nk;
    uint8 rtb_Sum_caj;
    uint8 rtb_Sum_da;
    uint8 rtb_Sum_ck;
    uint8 rtb_Sum_cj;
    uint8 rtb_Sum_hg;
    uint8 rtb_Switch1_m;
    uint8 rtb_Sum_np;
    uint8 rtb_Min;
    uint8 rtb_Min_o;
    float32 rtb_Switch2_o;
    float32 rtb_Sum_h;
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess'/M_TCTCLM' */
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/Logical Operator3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/from_data_definition'/state_source'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_CSCLTA_LimiterActivated_nu'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         *  Inport: '<Root>/S_LCFRCV_VehOdoState_nu'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/Logical Operator1/Functionality'/AND'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/Logical Operator3/Functionality'/AND'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Check Preconditions for Check of Correct Direction of Request/EQ1/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)GET_S_LCFRCV_VehOdoState_nu()) != 0) && (((sint32)GET_S_CSCLTA_LimiterActivated_nu()) != 0)) && ((((sint32) GET_S_CSCLTA_SysStateLCF_enum()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32) GET_S_CSCLTA_SysStateLCF_enum()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)))));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/CycleTimer/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_CSCLTA_LimiterTimeDuration_sec'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/Logical Operator4/Functionality'/OR'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/NOT/Functionality'/NOT'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/CycleTimer/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/CycleTimer'/Unit Delay1'
         */
    if ((!(((sint32)rtb_DataTypeConversion) != 0)) || (((sint32) GET_S_TPLCEN_ReplanCurValues_nu()) != 0)) {
        rtb_Switch = GET_S_CSCLTA_LimiterTimeDuration_sec();
    } else {
        rtb_Switch = DW_tctclm_UnitDelay1_DSTATE - GET_S_LCFRCV_SysCycleTimeVeh_sec();
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/CycleTimer/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/Logical Operator2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/Constant'/Constant'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/Logical Operator2/Functionality'/AND'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/GT/Functionality'/GT'
         */
    rtb_DataTypeConversion_h = (uint8)((((sint32)rtb_DataTypeConversion) != 0) && (rtb_Switch > 0.0F));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Determine Current Curvature Freeze/Switch8/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Determine Current Curvature Freeze'/Unit Delay5'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_k = DW_tctclm_UnitDelay5_DSTATE;
    } else {
        rtb_Switch_k = GET_S_LCFRCV_VehCrv_1pm();
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Determine Current Curvature Freeze/Switch8/Functionality'/Switch' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTLGC_DeltaFCmd_deg'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd'/Unit_Delay'
         */
    rtb_Switch_dl = GET_S_TCTLGC_DeltaFCmd_deg() - DW_tctclm_Unit_Delay_DSTATE;
    /* S-Function Block sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_GrdLimitDeltaFCmd_deg/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTCLM_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTCLM_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TCTCLM_GrdLimitDeltaFCmd_deg (), &dps_result_ln);
    }
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_GrdLimitDeltaFCmd_deg/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Selector: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array/Functionality/selector'/Selector'
         */
    rtb_Switch_ft = GET_Y_TCTCLM_GrdLimitGain_nu ((GET_S_MCTLFC_ControllingFunction_nu())) * rtb_ip_lookup_fxpt_sfun_7;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Mul = rtb_Switch_ft * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator = (uint8)(rtb_Switch_dl > rtb_Mul);
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/Neg1/Functionality'/Unary Minus'
         */
    rtb_Mul_c = (-rtb_Switch_ft) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1 = (uint8)(rtb_Switch_dl < rtb_Mul_c);
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/NEQ/Functionality'/NE'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/Unit_Delay'
         */
    rtb_DataTypeConversion_k = (uint8)((((sint32) GET_S_MCTLFC_ControllingFunction_nu()) != ((sint32) DW_tctclm_Unit_Delay_DSTATE_fo)) || (((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator) != 0) {
        rtb_DataTypeConversion_m = 0U;
    } else {
        rtb_DataTypeConversion_m = rtb_RelationalOperator1;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/AND/Functionality'/AND'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_m = (uint8)(((((sint32)rtb_DataTypeConversion_m) != 0) || (((sint32)rtb_RelationalOperator) != 0)) && (!(((sint32) rtb_DataTypeConversion_k) != 0)));
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/from_data_definition'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    rtb_Switch1_gq = (uint8)(((sint32)GET_S_MCTLFC_ControllingFunction_nu()) != ((sint32)((uint8)E_LCF_FunctionV3Type_E_LCF_OFF_nu)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Constant6'/Constant'
         */
    if (((sint32)rtb_Switch1_gq) != 0) {
        rtb_Switch_lo = rtb_DataTypeConversion_m;
    } else {
        rtb_Switch_lo = 0U;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_dv = 0U;
        rtb_Switch1_iu = 0U;
    } else {
        rtb_Switch1_dv = DW_tctclm_Unit_Delay13_DSTATE;
        rtb_Switch1_iu = DW_tctclm_Unit_Delay13_DSTATE_p;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum4/Functionality'/Sum' */
    rtb_Sum_ia = u8_u32(((uint32)rtb_Switch_lo) + ((uint32)((sint32) rtb_Switch1_dv)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum1/Functionality'/Sum' */
    rtb_Sum_bx = u8_u32(((uint32)rtb_Sum_ia) + ((uint32)((sint32) rtb_Switch1_iu)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_k = 0U;
        rtb_Switch1_d = 0U;
    } else {
        rtb_Switch1_k = DW_tctclm_Unit_Delay13_DSTATE_d;
        rtb_Switch1_d = DW_tctclm_Unit_Delay13_DSTATE_n;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum2/Functionality'/Sum' */
    rtb_Sum_gt = u8_u32(((uint32)rtb_Sum_bx) + ((uint32)((sint32)rtb_Switch1_k)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum3/Functionality'/Sum' */
    rtb_Sum_ed = u8_u32(((uint32)rtb_Sum_gt) + ((uint32)((sint32)rtb_Switch1_d)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_ej = 0U;
        rtb_Switch1_ka = 0U;
    } else {
        rtb_Switch1_ej = DW_tctclm_Unit_Delay13_DSTATE_p5;
        rtb_Switch1_ka = DW_tctclm_Unit_Delay13_DSTATE_nu;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum5/Functionality'/Sum' */
    rtb_Sum_ad = u8_u32(((uint32)rtb_Sum_ed) + ((uint32)((sint32) rtb_Switch1_ej)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum6/Functionality'/Sum' */
    rtb_Sum_a4 = u8_u32(((uint32)rtb_Sum_ad) + ((uint32)((sint32) rtb_Switch1_ka)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_fq = 0U;
        rtb_Switch1_fh = 0U;
    } else {
        rtb_Switch1_fq = DW_tctclm_Unit_Delay13_DSTATE_c;
        rtb_Switch1_fh = DW_tctclm_Unit_Delay13_DSTATE_i;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum7/Functionality'/Sum' */
    rtb_Sum_nor = u8_u32(((uint32)rtb_Sum_a4) + ((uint32)((sint32) rtb_Switch1_fq)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum8/Functionality'/Sum' */
    rtb_Sum_g5 = u8_u32(((uint32)rtb_Sum_nor) + ((uint32)((sint32) rtb_Switch1_fh)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8/DELAY_RE'/IV'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_ed = 0U;
    } else {
        rtb_Switch1_ed = DW_tctclm_Unit_Delay13_DSTATE_p3;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum9/Functionality'/Sum' */
    rtb_Sum_eh = u8_u32(((uint32)rtb_Sum_g5) + ((uint32)((sint32) rtb_Switch1_ed)));
    /* MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Constant5'/Constant'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Sum10/Functionality'/Sum'
         */
    switch (GET_P_TCTCLM_ErrCntrCyclesToCheck_nu()) {
    case 0:
        rtb_Sum_ia = rtb_Switch_lo;
        break;
    case 1:
        break;
    case 2:
        rtb_Sum_ia = rtb_Sum_bx;
        break;
    case 3:
        rtb_Sum_ia = rtb_Sum_gt;
        break;
    case 4:
        rtb_Sum_ia = rtb_Sum_ed;
        break;
    case 5:
        rtb_Sum_ia = rtb_Sum_ad;
        break;
    case 6:
        rtb_Sum_ia = rtb_Sum_a4;
        break;
    case 7:
        rtb_Sum_ia = rtb_Sum_nor;
        break;
    case 8:
        rtb_Sum_ia = rtb_Sum_g5;
        break;
    case 9:
        rtb_Sum_ia = rtb_Sum_eh;
        break;
    default:
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9/DELAY_RE/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9/DELAY_RE'/IV'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_k) != 0) {
            rtb_Min_o = 0U;
        } else {
            rtb_Min_o = DW_tctclm_Unit_Delay13_DSTATE_ck;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9/DELAY_RE/Functionality'/Switch1' */
        rtb_Sum_ia = u8_u32(((uint32)rtb_Sum_eh) + ((uint32)((sint32)rtb_Min_o)));
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3'/Multiport_Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/Constant4'/Constant'
         */
    rtb_VectorConcatenate[0] = (uint8)(((sint32)rtb_Sum_ia) >= ((sint32) GET_P_TCTCLM_ErrCntrDisengageThr_nu()));
    /* S-Function Block sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_LimitDeltaFCmd_deg/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTCLM_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTCLM_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D(GETA_Y_TCTCLM_LimitDeltaFCmd_deg(), &dps_result_ln);
    }
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Mul1/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_LimitDeltaFCmd_deg/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Selector: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array/Functionality/selector'/Selector'
         */
    rtb_Mul_n = GET_Y_TCTCLM_LimitGain_nu((GET_S_MCTLFC_ControllingFunction_nu())) * rtb_ip_lookup_fxpt_sfun_7_e;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array'/Functionality' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Inport: '<Root>/S_TCTLGC_DeltaFCmd_deg'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Mul = GET_S_TCTLGC_DeltaFCmd_deg();
    } else if (((sint32)rtb_RelationalOperator) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd'/Unit_Delay'
                 */
        rtb_Mul += DW_tctclm_Unit_Delay_DSTATE;
    } else if (((sint32)rtb_RelationalOperator1) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd'/Unit_Delay'
                 */
        rtb_Mul = rtb_Mul_c + DW_tctclm_Unit_Delay_DSTATE;
    } else {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Inport: '<Root>/S_TCTLGC_DeltaFCmd_deg'
                 *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul = GET_S_TCTLGC_DeltaFCmd_deg();
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Relational Operator' */
    rtb_RelationalOperator = (uint8)(rtb_Mul_n >= rtb_Mul);
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Relational Operator1' incorporates:
         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Neg/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1 = (uint8)((-rtb_Mul_n) <= rtb_Mul);
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/And'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Not1'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Not2'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/OR1/Functionality'/OR'
         */
    rtb_Sum_ia = (uint8)(((((sint32)rtb_RelationalOperator) != 0) && (!(((sint32) rtb_RelationalOperator1) != 0))) || (!(((sint32)rtb_RelationalOperator) != 0)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Constant6'/Constant'
         */
    if (((sint32)rtb_Switch1_gq) != 0) {
        rtb_Sum_bx = rtb_Sum_ia;
    } else {
        rtb_Sum_bx = 0U;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_gt = 0U;
        rtb_Sum_ad = 0U;
    } else {
        rtb_Sum_gt = DW_tctclm_Unit_Delay13_DSTATE_j;
        rtb_Sum_ad = DW_tctclm_Unit_Delay13_DSTATE_pn;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum4/Functionality'/Sum' */
    rtb_Sum_ed = u8_u32(((uint32)rtb_Sum_bx) + ((uint32)((sint32)rtb_Sum_gt)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum1/Functionality'/Sum' */
    rtb_Sum_ga = u8_u32(((uint32)rtb_Sum_ed) + ((uint32)((sint32)rtb_Sum_ad)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_a4 = 0U;
        rtb_Sum_nor = 0U;
    } else {
        rtb_Sum_a4 = DW_tctclm_Unit_Delay13_DSTATE_g;
        rtb_Sum_nor = DW_tctclm_Unit_Delay13_DSTATE_cw;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum2/Functionality'/Sum' */
    rtb_Sum_na = u8_u32(((uint32)rtb_Sum_ga) + ((uint32)((sint32)rtb_Sum_a4)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum3/Functionality'/Sum' */
    rtb_Sum_bdn = u8_u32(((uint32)rtb_Sum_na) + ((uint32)((sint32)rtb_Sum_nor)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_g5 = 0U;
        rtb_Sum_eh = 0U;
    } else {
        rtb_Sum_g5 = DW_tctclm_Unit_Delay13_DSTATE_p5d;
        rtb_Sum_eh = DW_tctclm_Unit_Delay13_DSTATE_jg;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum5/Functionality'/Sum' */
    rtb_Sum_nqw = u8_u32(((uint32)rtb_Sum_bdn) + ((uint32)((sint32)rtb_Sum_g5)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum6/Functionality'/Sum' */
    rtb_Sum_dc = u8_u32(((uint32)rtb_Sum_nqw) + ((uint32)((sint32)rtb_Sum_eh)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_bs = 0U;
        rtb_Switch1_ds = 0U;
    } else {
        rtb_Switch1_bs = DW_tctclm_Unit_Delay13_DSTATE_b;
        rtb_Switch1_ds = DW_tctclm_Unit_Delay13_DSTATE_b2;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum7/Functionality'/Sum' */
    rtb_Sum_c = u8_u32(((uint32)rtb_Sum_dc) + ((uint32)((sint32)rtb_Switch1_bs)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum8/Functionality'/Sum' */
    rtb_Sum_oz = u8_u32(((uint32)rtb_Sum_c) + ((uint32)((sint32)rtb_Switch1_ds)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8/DELAY_RE'/IV'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_eh = 0U;
    } else {
        rtb_Switch1_eh = DW_tctclm_Unit_Delay13_DSTATE_gr;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum9/Functionality'/Sum' */
    rtb_Sum_iv = u8_u32(((uint32)rtb_Sum_oz) + ((uint32)((sint32) rtb_Switch1_eh)));
    /* MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Constant5'/Constant'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Sum10/Functionality'/Sum'
         */
    switch (GET_P_TCTCLM_ErrCntrCyclesToCheck_nu()) {
    case 0:
        rtb_Sum_ed = rtb_Sum_bx;
        break;
    case 1:
        break;
    case 2:
        rtb_Sum_ed = rtb_Sum_ga;
        break;
    case 3:
        rtb_Sum_ed = rtb_Sum_na;
        break;
    case 4:
        rtb_Sum_ed = rtb_Sum_bdn;
        break;
    case 5:
        rtb_Sum_ed = rtb_Sum_nqw;
        break;
    case 6:
        rtb_Sum_ed = rtb_Sum_dc;
        break;
    case 7:
        rtb_Sum_ed = rtb_Sum_c;
        break;
    case 8:
        rtb_Sum_ed = rtb_Sum_oz;
        break;
    case 9:
        rtb_Sum_ed = rtb_Sum_iv;
        break;
    default:
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9/DELAY_RE/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9/DELAY_RE'/IV'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_k) != 0) {
            rtb_Min_o = 0U;
        } else {
            rtb_Min_o = DW_tctclm_Unit_Delay13_DSTATE_a;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9/DELAY_RE/Functionality'/Switch1' */
        rtb_Sum_ed = u8_u32(((uint32)rtb_Sum_iv) + ((uint32)((sint32)rtb_Min_o)));
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter'/Multiport_Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/Constant4'/Constant'
         */
    rtb_VectorConcatenate[1] = (uint8)(((sint32)rtb_Sum_ed) >= ((sint32) GET_P_TCTCLM_ErrCntrDisengageThr_nu()));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTLGC_FFCrv_1pm'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC'/Unit_Delay'
         */
    rtb_Switch_ft = GET_S_TCTLGC_FFCrv_1pm() - DW_tctclm_Unit_Delay_DSTATE_k;
    /* S-Function Block sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_GrdLimitFfc_1pms/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTCLM_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTCLM_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D(GETA_Y_TCTCLM_GrdLimitFfc_1pms(), &dps_result_ln);
    }
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Mul4/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_GrdLimitFfc_1pms/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Selector: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array/Functionality/selector'/Selector'
         */
    rtb_Switch_dl = GET_Y_TCTCLM_GrdLimitGain_nu ((GET_S_MCTLFC_ControllingFunction_nu())) * rtb_ip_lookup_fxpt_sfun_7_c;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Mul_gy = rtb_Switch_dl * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_jk = (uint8)(rtb_Switch_ft > rtb_Mul_gy);
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/Neg1/Functionality'/Unary Minus'
         */
    rtb_Switch_dl = (-rtb_Switch_dl) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_e = (uint8)(rtb_Switch_ft < rtb_Switch_dl);
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_jk) != 0) {
        rtb_Sum_ed = 0U;
    } else {
        rtb_Sum_ed = rtb_RelationalOperator1_e;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/AND/Functionality'/AND'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/OR/Functionality'/OR'
         */
    rtb_Sum_ga = (uint8)(((((sint32)rtb_Sum_ed) != 0) || (((sint32) rtb_RelationalOperator_jk) != 0)) && (!(((sint32)rtb_DataTypeConversion_k) != 0)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Constant6'/Constant'
         */
    if (((sint32)rtb_Switch1_gq) != 0) {
        rtb_Sum_na = rtb_Sum_ga;
    } else {
        rtb_Sum_na = 0U;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_ed = 0U;
        rtb_Sum_nqw = 0U;
    } else {
        rtb_Sum_ed = DW_tctclm_Unit_Delay13_DSTATE_h;
        rtb_Sum_nqw = DW_tctclm_Unit_Delay13_DSTATE_jl;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum4/Functionality'/Sum' */
    rtb_Sum_bdn = u8_u32(((uint32)rtb_Sum_na) + ((uint32)((sint32)rtb_Sum_ed)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum1/Functionality'/Sum' */
    rtb_Sum_o1 = u8_u32(((uint32)rtb_Sum_bdn) + ((uint32)((sint32)rtb_Sum_nqw)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_dc = 0U;
        rtb_Sum_c = 0U;
    } else {
        rtb_Sum_dc = DW_tctclm_Unit_Delay13_DSTATE_i4;
        rtb_Sum_c = DW_tctclm_Unit_Delay13_DSTATE_ir;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum2/Functionality'/Sum' */
    rtb_Sum_as = u8_u32(((uint32)rtb_Sum_o1) + ((uint32)((sint32)rtb_Sum_dc)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum3/Functionality'/Sum' */
    rtb_Sum_gfe = u8_u32(((uint32)rtb_Sum_as) + ((uint32)((sint32)rtb_Sum_c)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_oz = 0U;
        rtb_Sum_iv = 0U;
    } else {
        rtb_Sum_oz = DW_tctclm_Unit_Delay13_DSTATE_dg;
        rtb_Sum_iv = DW_tctclm_Unit_Delay13_DSTATE_jw;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum5/Functionality'/Sum' */
    rtb_Sum_ni = u8_u32(((uint32)rtb_Sum_gfe) + ((uint32)((sint32)rtb_Sum_oz)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum6/Functionality'/Sum' */
    rtb_Sum_pv = u8_u32(((uint32)rtb_Sum_ni) + ((uint32)((sint32)rtb_Sum_iv)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_it = 0U;
        rtb_Switch1_i0 = 0U;
    } else {
        rtb_Switch1_it = DW_tctclm_Unit_Delay13_DSTATE_f;
        rtb_Switch1_i0 = DW_tctclm_Unit_Delay13_DSTATE_l;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum7/Functionality'/Sum' */
    rtb_Sum_ox = u8_u32(((uint32)rtb_Sum_pv) + ((uint32)((sint32) rtb_Switch1_it)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum8/Functionality'/Sum' */
    rtb_Sum_fh = u8_u32(((uint32)rtb_Sum_ox) + ((uint32)((sint32) rtb_Switch1_i0)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8/DELAY_RE'/IV'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_ep = 0U;
    } else {
        rtb_Switch1_ep = DW_tctclm_Unit_Delay13_DSTATE_g3;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum9/Functionality'/Sum' */
    rtb_Sum_d = u8_u32(((uint32)rtb_Sum_fh) + ((uint32)((sint32)rtb_Switch1_ep)));
    /* MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Constant5'/Constant'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Sum10/Functionality'/Sum'
         */
    switch (GET_P_TCTCLM_ErrCntrCyclesToCheck_nu()) {
    case 0:
        rtb_Sum_bdn = rtb_Sum_na;
        break;
    case 1:
        break;
    case 2:
        rtb_Sum_bdn = rtb_Sum_o1;
        break;
    case 3:
        rtb_Sum_bdn = rtb_Sum_as;
        break;
    case 4:
        rtb_Sum_bdn = rtb_Sum_gfe;
        break;
    case 5:
        rtb_Sum_bdn = rtb_Sum_ni;
        break;
    case 6:
        rtb_Sum_bdn = rtb_Sum_pv;
        break;
    case 7:
        rtb_Sum_bdn = rtb_Sum_ox;
        break;
    case 8:
        rtb_Sum_bdn = rtb_Sum_fh;
        break;
    case 9:
        rtb_Sum_bdn = rtb_Sum_d;
        break;
    default:
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9/DELAY_RE/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9/DELAY_RE'/IV'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_k) != 0) {
            rtb_Min_o = 0U;
        } else {
            rtb_Min_o = DW_tctclm_Unit_Delay13_DSTATE_k;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9/DELAY_RE/Functionality'/Switch1' */
        rtb_Sum_bdn = u8_u32(((uint32)rtb_Sum_d) + ((uint32)((sint32)rtb_Min_o)));
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4'/Multiport_Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/Constant4'/Constant'
         */
    rtb_VectorConcatenate[2] = (uint8)(((sint32)rtb_Sum_bdn) >= ((sint32) GET_P_TCTCLM_ErrCntrDisengageThr_nu()));
    /* S-Function Block sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_LimitFfc_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTCLM_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTCLM_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D(GETA_Y_TCTCLM_LimitFfc_1pm(), &dps_result_ln);
    }
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_LimitFfc_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Selector: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array/Functionality/selector'/Selector'
         */
    rtb_Mul_c = GET_Y_TCTCLM_LimitGain_nu((GET_S_MCTLFC_ControllingFunction_nu())) * rtb_ip_lookup_fxpt_sfun_7_m;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array'/Functionality' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Inport: '<Root>/S_TCTLGC_FFCrv_1pm'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Mul_gy = GET_S_TCTLGC_FFCrv_1pm();
    } else if (((sint32)rtb_RelationalOperator_jk) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC'/Unit_Delay'
                 */
        rtb_Mul_gy += DW_tctclm_Unit_Delay_DSTATE_k;
    } else if (((sint32)rtb_RelationalOperator1_e) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC'/Unit_Delay'
                 */
        rtb_Mul_gy = rtb_Switch_dl + DW_tctclm_Unit_Delay_DSTATE_k;
    } else {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Inport: '<Root>/S_TCTLGC_FFCrv_1pm'
                 *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul_gy = GET_S_TCTLGC_FFCrv_1pm();
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Relational Operator' */
    rtb_RelationalOperator_jk = (uint8)(rtb_Mul_c >= rtb_Mul_gy);
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Relational Operator1' incorporates:
         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Neg/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_e = (uint8)((-rtb_Mul_c) <= rtb_Mul_gy);
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/And'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Not1'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Not2'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/OR1/Functionality'/OR'
         */
    rtb_Sum_bdn = (uint8)(((((sint32)rtb_RelationalOperator_jk) != 0) && (!(((sint32)rtb_RelationalOperator1_e) != 0))) || (!(((sint32) rtb_RelationalOperator_jk) != 0)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Constant6'/Constant'
         */
    if (((sint32)rtb_Switch1_gq) != 0) {
        rtb_Sum_o1 = rtb_Sum_bdn;
    } else {
        rtb_Sum_o1 = 0U;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_as = 0U;
        rtb_Sum_ni = 0U;
    } else {
        rtb_Sum_as = DW_tctclm_Unit_Delay13_DSTATE_kq;
        rtb_Sum_ni = DW_tctclm_Unit_Delay13_DSTATE_fl;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum4/Functionality'/Sum' */
    rtb_Sum_gfe = u8_u32(((uint32)rtb_Sum_o1) + ((uint32)((sint32)rtb_Sum_as)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum1/Functionality'/Sum' */
    rtb_Sum_cty = u8_u32(((uint32)rtb_Sum_gfe) + ((uint32)((sint32)rtb_Sum_ni)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_pv = 0U;
        rtb_Sum_ox = 0U;
    } else {
        rtb_Sum_pv = DW_tctclm_Unit_Delay13_DSTATE_m;
        rtb_Sum_ox = DW_tctclm_Unit_Delay13_DSTATE_e;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum2/Functionality'/Sum' */
    rtb_Sum_fn = u8_u32(((uint32)rtb_Sum_cty) + ((uint32)((sint32)rtb_Sum_pv)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum3/Functionality'/Sum' */
    rtb_Sum_b0b = u8_u32(((uint32)rtb_Sum_fn) + ((uint32)((sint32)rtb_Sum_ox)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_fh = 0U;
        rtb_Sum_d = 0U;
    } else {
        rtb_Sum_fh = DW_tctclm_Unit_Delay13_DSTATE_i0;
        rtb_Sum_d = DW_tctclm_Unit_Delay13_DSTATE_o;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum5/Functionality'/Sum' */
    rtb_Sum_n = u8_u32(((uint32)rtb_Sum_b0b) + ((uint32)((sint32)rtb_Sum_fh)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum6/Functionality'/Sum' */
    rtb_Sum_oa = u8_u32(((uint32)rtb_Sum_n) + ((uint32)((sint32)rtb_Sum_d)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_ol = 0U;
        rtb_Switch1_e = 0U;
    } else {
        rtb_Switch1_ol = DW_tctclm_Unit_Delay13_DSTATE_pa;
        rtb_Switch1_e = DW_tctclm_Unit_Delay13_DSTATE_js;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum7/Functionality'/Sum' */
    rtb_Sum_o2 = u8_u32(((uint32)rtb_Sum_oa) + ((uint32)((sint32) rtb_Switch1_ol)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum8/Functionality'/Sum' */
    rtb_Sum_bp = u8_u32(((uint32)rtb_Sum_o2) + ((uint32)((sint32)rtb_Switch1_e)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8/DELAY_RE'/IV'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_f4 = 0U;
    } else {
        rtb_Switch1_f4 = DW_tctclm_Unit_Delay13_DSTATE_nj;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum9/Functionality'/Sum' */
    rtb_Sum_kp = u8_u32(((uint32)rtb_Sum_bp) + ((uint32)((sint32) rtb_Switch1_f4)));
    /* MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Constant5'/Constant'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Sum10/Functionality'/Sum'
         */
    switch (GET_P_TCTCLM_ErrCntrCyclesToCheck_nu()) {
    case 0:
        rtb_Sum_gfe = rtb_Sum_o1;
        break;
    case 1:
        break;
    case 2:
        rtb_Sum_gfe = rtb_Sum_cty;
        break;
    case 3:
        rtb_Sum_gfe = rtb_Sum_fn;
        break;
    case 4:
        rtb_Sum_gfe = rtb_Sum_b0b;
        break;
    case 5:
        rtb_Sum_gfe = rtb_Sum_n;
        break;
    case 6:
        rtb_Sum_gfe = rtb_Sum_oa;
        break;
    case 7:
        rtb_Sum_gfe = rtb_Sum_o2;
        break;
    case 8:
        rtb_Sum_gfe = rtb_Sum_bp;
        break;
    case 9:
        rtb_Sum_gfe = rtb_Sum_kp;
        break;
    default:
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9/DELAY_RE/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9/DELAY_RE'/IV'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_k) != 0) {
            rtb_Min_o = 0U;
        } else {
            rtb_Min_o = DW_tctclm_Unit_Delay13_DSTATE_ip;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9/DELAY_RE/Functionality'/Switch1' */
        rtb_Sum_gfe = u8_u32(((uint32)rtb_Sum_kp) + ((uint32)((sint32)rtb_Min_o)));
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1'/Multiport_Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/Constant4'/Constant'
         */
    rtb_VectorConcatenate[3] = (uint8)(((sint32)rtb_Sum_gfe) >= ((sint32) GET_P_TCTCLM_ErrCntrDisengageThr_nu()));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Add/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTLGC_CtrlCrv_DE_1pm'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC'/Unit_Delay'
         */
    rtb_Switch_ft = GET_S_TCTLGC_CtrlCrv_DE_1pm() - DW_tctclm_Unit_Delay_DSTATE_l;
    /* S-Function Block sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_GrdLimitFbcDc_1pms/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTCLM_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTCLM_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D(GETA_Y_TCTCLM_GrdLimitFbcDc_1pms(), &dps_result_ln);
    }
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Mul5/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_GrdLimitFbcDc_1pms/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Selector: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array/Functionality/selector'/Selector'
         */
    rtb_Switch_dl = GET_Y_TCTCLM_GrdLimitGain_nu ((GET_S_MCTLFC_ControllingFunction_nu())) * rtb_ip_lookup_fxpt_sfun_7_g;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Mul1/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Mul_mv = rtb_Switch_dl * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator' */
    rtb_RelationalOperator_fk = (uint8)(rtb_Switch_ft > rtb_Mul_mv);
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Mul/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/Neg1/Functionality'/Unary Minus'
         */
    rtb_Mul_m0 = (-rtb_Switch_dl) * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Relational Operator1' */
    rtb_RelationalOperator1_l = (uint8)(rtb_Switch_ft < rtb_Mul_m0);
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Constant4'
         */
    if (((sint32)rtb_RelationalOperator_fk) != 0) {
        rtb_Sum_gfe = 0U;
    } else {
        rtb_Sum_gfe = rtb_RelationalOperator1_l;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch7' */
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/AND/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/AND/Functionality'/AND'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/OR/Functionality'/OR'
         */
    rtb_Min = (uint8)(((((sint32)rtb_Sum_gfe) != 0) || (((sint32) rtb_RelationalOperator_fk) != 0)) && (!(((sint32)rtb_DataTypeConversion_k) != 0)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Constant6'/Constant'
         */
    if (((sint32)rtb_Switch1_gq) != 0) {
        rtb_Sum_cty = rtb_Min;
    } else {
        rtb_Sum_cty = 0U;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_gfe = 0U;
        rtb_Sum_b0b = 0U;
    } else {
        rtb_Sum_gfe = DW_tctclm_Unit_Delay13_DSTATE_i0y;
        rtb_Sum_b0b = DW_tctclm_Unit_Delay13_DSTATE_lj;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum4/Functionality'/Sum' */
    rtb_Sum_fn = u8_u32(((uint32)rtb_Sum_cty) + ((uint32)((sint32)rtb_Sum_gfe)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum1/Functionality'/Sum' */
    rtb_Sum_ps = u8_u32(((uint32)rtb_Sum_fn) + ((uint32)((sint32)rtb_Sum_b0b)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_n = 0U;
        rtb_Sum_oa = 0U;
    } else {
        rtb_Sum_n = DW_tctclm_Unit_Delay13_DSTATE_oj;
        rtb_Sum_oa = DW_tctclm_Unit_Delay13_DSTATE_jm;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum2/Functionality'/Sum' */
    rtb_Sum_il = u8_u32(((uint32)rtb_Sum_ps) + ((uint32)((sint32)rtb_Sum_n)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum3/Functionality'/Sum' */
    rtb_Sum_mi = u8_u32(((uint32)rtb_Sum_il) + ((uint32)((sint32)rtb_Sum_oa)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_o2 = 0U;
        rtb_Sum_bp = 0U;
    } else {
        rtb_Sum_o2 = DW_tctclm_Unit_Delay13_DSTATE_ld;
        rtb_Sum_bp = DW_tctclm_Unit_Delay13_DSTATE_m3;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum5/Functionality'/Sum' */
    rtb_Sum_gg = u8_u32(((uint32)rtb_Sum_mi) + ((uint32)((sint32)rtb_Sum_o2)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum6/Functionality'/Sum' */
    rtb_Sum_h3 = u8_u32(((uint32)rtb_Sum_gg) + ((uint32)((sint32)rtb_Sum_bp)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_kp = 0U;
        rtb_Switch1_mh = 0U;
    } else {
        rtb_Sum_kp = DW_tctclm_Unit_Delay13_DSTATE_hw;
        rtb_Switch1_mh = DW_tctclm_Unit_Delay13_DSTATE_kw;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum7/Functionality'/Sum' */
    rtb_Sum_af = u8_u32(((uint32)rtb_Sum_h3) + ((uint32)((sint32)rtb_Sum_kp)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum8/Functionality'/Sum' */
    rtb_Sum_a3 = u8_u32(((uint32)rtb_Sum_af) + ((uint32)((sint32) rtb_Switch1_mh)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8/DELAY_RE'/IV'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_l2 = 0U;
    } else {
        rtb_Switch1_l2 = DW_tctclm_Unit_Delay13_DSTATE_ei;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum9/Functionality'/Sum' */
    rtb_Sum_o = u8_u32(((uint32)rtb_Sum_a3) + ((uint32)((sint32)rtb_Switch1_l2)));
    /* MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Constant5'/Constant'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Sum10/Functionality'/Sum'
         */
    switch (GET_P_TCTCLM_ErrCntrCyclesToCheck_nu()) {
    case 0:
        rtb_Sum_fn = rtb_Sum_cty;
        break;
    case 1:
        break;
    case 2:
        rtb_Sum_fn = rtb_Sum_ps;
        break;
    case 3:
        rtb_Sum_fn = rtb_Sum_il;
        break;
    case 4:
        rtb_Sum_fn = rtb_Sum_mi;
        break;
    case 5:
        rtb_Sum_fn = rtb_Sum_gg;
        break;
    case 6:
        rtb_Sum_fn = rtb_Sum_h3;
        break;
    case 7:
        rtb_Sum_fn = rtb_Sum_af;
        break;
    case 8:
        rtb_Sum_fn = rtb_Sum_a3;
        break;
    case 9:
        rtb_Sum_fn = rtb_Sum_o;
        break;
    default:
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9/DELAY_RE/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9/DELAY_RE'/IV'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_k) != 0) {
            rtb_Min_o = 0U;
        } else {
            rtb_Min_o = DW_tctclm_Unit_Delay13_DSTATE_dm;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9/DELAY_RE/Functionality'/Switch1' */
        rtb_Sum_fn = u8_u32(((uint32)rtb_Sum_o) + ((uint32)((sint32)rtb_Min_o)));
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5'/Multiport_Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/Constant4'/Constant'
         */
    rtb_VectorConcatenate[4] = (uint8)(((sint32)rtb_Sum_fn) >= ((sint32) GET_P_TCTCLM_ErrCntrDisengageThr_nu()));
    /* S-Function Block sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_LimitFbcDc_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTCLM_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTCLM_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ca = F32_PTR_IP1D(GETA_Y_TCTCLM_LimitFbcDc_1pm(), &dps_result_ln);
    }
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array'/Functionality' */
    /* Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Mul3/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Y_TCTCLM_LimitFbcDc_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  Selector: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array/Functionality/selector'/Selector'
         */
    rtb_Switch_dl = GET_Y_TCTCLM_LimitGain_nu((GET_S_MCTLFC_ControllingFunction_nu ())) * rtb_ip_lookup_fxpt_sfun_7_ca;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ReadAxis1/read_array'/Functionality' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Inport: '<Root>/S_TCTLGC_CtrlCrv_DE_1pm'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Mul_mv = GET_S_TCTLGC_CtrlCrv_DE_1pm();
    } else if (((sint32)rtb_RelationalOperator_fk) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC'/Unit_Delay'
                 */
        rtb_Mul_mv += DW_tctclm_Unit_Delay_DSTATE_l;
    } else if (((sint32)rtb_RelationalOperator1_l) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                 *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC'/Unit_Delay'
                 */
        rtb_Mul_mv = rtb_Mul_m0 + DW_tctclm_Unit_Delay_DSTATE_l;
    } else {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch6' incorporates:
                 *  Inport: '<Root>/S_TCTLGC_CtrlCrv_DE_1pm'
                 *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch5'
                 */
        rtb_Mul_mv = GET_S_TCTLGC_CtrlCrv_DE_1pm();
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC/GRADIENTLIMITER/Functionality/Subfunctionality'/Switch2' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Relational Operator' */
    rtb_RelationalOperator_fk = (uint8)(rtb_Switch_dl >= rtb_Mul_mv);
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Relational Operator1' incorporates:
         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Neg/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_l = (uint8)((-rtb_Switch_dl) <= rtb_Mul_mv);
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/And'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Not1'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Not2'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/OR1/Functionality'/OR'
         */
    rtb_Sum_fn = (uint8)(((((sint32)rtb_RelationalOperator_fk) != 0) && (!(((sint32)rtb_RelationalOperator1_l) != 0))) || (!(((sint32) rtb_RelationalOperator_fk) != 0)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Constant6'/Constant'
         */
    if (((sint32)rtb_Switch1_gq) != 0) {
        rtb_Sum_ps = rtb_Sum_fn;
    } else {
        rtb_Sum_ps = 0U;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_gq = 0U;
        rtb_Sum_il = 0U;
    } else {
        rtb_Switch1_gq = DW_tctclm_Unit_Delay13_DSTATE_ks;
        rtb_Sum_il = DW_tctclm_Unit_Delay13_DSTATE_jo;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum4/Functionality'/Sum' */
    rtb_Min_o = u8_u32(((uint32)rtb_Sum_ps) + ((uint32)((sint32)rtb_Switch1_gq)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum1/Functionality'/Sum' */
    rtb_Sum_b5 = u8_u32(((uint32)rtb_Min_o) + ((uint32)((sint32)rtb_Sum_il)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_mi = 0U;
        rtb_Sum_gg = 0U;
    } else {
        rtb_Sum_mi = DW_tctclm_Unit_Delay13_DSTATE_hi;
        rtb_Sum_gg = DW_tctclm_Unit_Delay13_DSTATE_bb;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum2/Functionality'/Sum' */
    rtb_Sum_nk = u8_u32(((uint32)rtb_Sum_b5) + ((uint32)((sint32)rtb_Sum_mi)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum3/Functionality'/Sum' */
    rtb_Sum_caj = u8_u32(((uint32)rtb_Sum_nk) + ((uint32)((sint32)rtb_Sum_gg)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_h3 = 0U;
        rtb_Sum_af = 0U;
    } else {
        rtb_Sum_h3 = DW_tctclm_Unit_Delay13_DSTATE_j5;
        rtb_Sum_af = DW_tctclm_Unit_Delay13_DSTATE_lu;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum5/Functionality'/Sum' */
    rtb_Sum_da = u8_u32(((uint32)rtb_Sum_caj) + ((uint32)((sint32)rtb_Sum_h3)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum6/Functionality'/Sum' */
    rtb_Sum_ck = u8_u32(((uint32)rtb_Sum_da) + ((uint32)((sint32)rtb_Sum_af)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6/DELAY_RE'/IV'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7/DELAY_RE'/IV'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7/DELAY_RE/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6'/Unit_Delay13'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Sum_a3 = 0U;
        rtb_Sum_o = 0U;
    } else {
        rtb_Sum_a3 = DW_tctclm_Unit_Delay13_DSTATE_fm;
        rtb_Sum_o = DW_tctclm_Unit_Delay13_DSTATE_bs;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum7/Functionality'/Sum' */
    rtb_Sum_cj = u8_u32(((uint32)rtb_Sum_ck) + ((uint32)((sint32)rtb_Sum_a3)));
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum8/Functionality'/Sum' */
    rtb_Sum_hg = u8_u32(((uint32)rtb_Sum_cj) + ((uint32)((sint32)rtb_Sum_o)));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8/DELAY_RE/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8/DELAY_RE'/IV'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8'/Unit_Delay13'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        rtb_Switch1_m = 0U;
    } else {
        rtb_Switch1_m = DW_tctclm_Unit_Delay13_DSTATE_lx;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8/DELAY_RE/Functionality'/Switch1' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum9/Functionality'/Sum' */
    rtb_Sum_np = u8_u32(((uint32)rtb_Sum_hg) + ((uint32)((sint32)rtb_Switch1_m)));
    /* MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Constant5'/Constant'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Sum10/Functionality'/Sum'
         */
    switch (GET_P_TCTCLM_ErrCntrCyclesToCheck_nu()) {
    case 0:
        rtb_Min_o = rtb_Sum_ps;
        break;
    case 1:
        break;
    case 2:
        rtb_Min_o = rtb_Sum_b5;
        break;
    case 3:
        rtb_Min_o = rtb_Sum_nk;
        break;
    case 4:
        rtb_Min_o = rtb_Sum_caj;
        break;
    case 5:
        rtb_Min_o = rtb_Sum_da;
        break;
    case 6:
        rtb_Min_o = rtb_Sum_ck;
        break;
    case 7:
        rtb_Min_o = rtb_Sum_cj;
        break;
    case 8:
        rtb_Min_o = rtb_Sum_hg;
        break;
    case 9:
        rtb_Min_o = rtb_Sum_np;
        break;
    default:
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9/DELAY_RE/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9/DELAY_RE'/IV'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9'/Unit_Delay13'
                 */
        if (((sint32)rtb_DataTypeConversion_k) != 0) {
            rtb_Min_o = 0U;
        } else {
            rtb_Min_o = DW_tctclm_Unit_Delay13_DSTATE_dn;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9/DELAY_RE/Functionality'/Switch1' */
        rtb_Min_o = u8_u32(((uint32)rtb_Sum_np) + ((uint32)((sint32)rtb_Min_o)));
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2'/Multiport_Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/GE1/Functionality'/GE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/Constant4'/Constant'
         */
    rtb_VectorConcatenate[5] = (uint8)(((sint32)rtb_Min_o) >= ((sint32) GET_P_TCTCLM_ErrCntrDisengageThr_nu()));
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch15'/copy1' incorporates:
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning'/Unit_Delay2'
         */
    SET_D_TCTCLM_UnplsblDrctnOfRqst_nu(DW_tctclm_Unit_Delay2_DSTATE_p);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Qualifier'/ConcatBufferAtVector ConcatenateIn7' incorporates:
                                                                        *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning'/Unit_Delay2'
                                                                        */
    rtb_VectorConcatenate[6] = DW_tctclm_Unit_Delay2_DSTATE_p;
    /* S-Function (sfun_setbit): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Qualifier/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[7] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate[0];
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
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant1'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant2'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant3'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant4'/Constant'
         *  DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/OR/Functionality'/Data Type Conversion'
         *  Inport: '<Root>/S_TCTCDC_QualifierService_nu'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/GT1/Functionality'/GT'
         *  S-Function (sfix_bitop): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/AND/Functionality'/AND'
         *  S-Function (sfix_bitop): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/AND3/Functionality'/AND'
         */
    if (((sint32)GET_P_TCTCLM_QuServiceOverride_nu()) != 0) {
        rtb_Min_o = GET_P_TCTCLM_QuServiceOverride_nu();
    } else {
        rtb_Min_o = (uint8)(((((sint32)GET_S_TCTCDC_QualifierService_nu()) & ((sint32)GET_P_TCTCLM_WtchdgCDCQuSv_btm())) > 0) || ((((sint32) rtb_sfun_setbit) & ((sint32)GET_P_TCTCLM_WtchdgCLMQuSv_btm())) > 0));
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/NEQ1/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_CSCLTA_SysStateLCF_enum'
         */
    rtb_Sum_nk = (uint8)(((sint32)GET_S_CSCLTA_SysStateLCF_enum()) != ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/NOT1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/NOT1/Functionality'/NOT'
         */
    rtb_SFunction = (uint8)(!(((sint32)rtb_Sum_nk) != 0));
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/AND2/Functionality'/AND'
         */
    rtb_SFunction = (uint8)((((sint32)rtb_Min_o) != 0) && (((sint32) rtb_SFunction) != 0));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant6'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant7'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Relational Operator2'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Switch'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Switch2'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay1'
         */
    if (((sint32)rtb_SFunction) != 0) {
        rtb_Mul_m0 = GET_P_TCTCLM_QuServiceMinTime_sec();
        rtb_Switch2_o = GET_P_TCTCLM_QuServiceMaxTime_sec();
    } else {
        if (DW_tctclm_Unit_Delay1_DSTATE > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
            /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality/Sum/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay1'
                         */
            rtb_Mul_m0 = DW_tctclm_Unit_Delay1_DSTATE - GET_S_LCFRCV_SysCycleTimeVeh_sec ();
        } else {
            /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Switch2' incorporates:
                         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Constant2'
                         */
            rtb_Mul_m0 = 0.0F;
        }
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Constant2'
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Relational Operator2'
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality/Sum/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay3'
                 */
        if (DW_tctclm_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
            rtb_Switch2_o = DW_tctclm_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeVeh_sec();
        } else {
            rtb_Switch2_o = 0.0F;
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Switch2' */
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Relational Operator1' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE1/Functionality'/Constant'
         */
    rtb_Sum_b5 = (uint8)(rtb_Mul_m0 > 0.0F);
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Constant'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/NOT/Functionality'/NOT'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/TIMERRETRIGGER_RE2/Functionality'/Relational Operator1'
         */
    rtb_SFunction = (uint8)(!(rtb_Switch2_o > 0.0F));
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/OR1/Functionality'/OR'
         */
    rtb_Sum_nk = (uint8)((((sint32)rtb_SFunction) != 0) || (((sint32)rtb_Sum_nk) != 0));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/SRFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/SRFLIPFLOP/Functionality'/Constant'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/SRFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay'
         */
    if (((sint32)rtb_Sum_b5) != 0) {
        rtb_Sum_caj = 1U;
    } else if (((sint32)rtb_Sum_nk) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/SRFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/SRFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Sum_caj = 0U;
    } else {
        rtb_Sum_caj = DW_tctclm_Unit_Delay_DSTATE_p;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/SRFLIPFLOP/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Constant8'/Constant'
         */
    if (((sint32)GET_P_TCTCLM_QuServiceErrMemAct_nu()) != 0) {
        rtb_Min_o = rtb_Sum_caj;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog/Switch1/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request/GT1/Functionality'/GT' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request/Constant2'/Constant'
         */
    rtb_SFunction = (uint8)(((sint32)rtb_Min_o) > 0);
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request/Switch/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request'/Unit_Delay'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request'/Unit_Delay2'
         */
    if (((sint32)rtb_SFunction) != 0) {
        rtb_Switch_dl = DW_tctclm_Unit_Delay_DSTATE_f;
        rtb_Mul_c = DW_tctclm_Unit_Delay1_DSTATE_c;
        rtb_Mul_n = DW_tctclm_Unit_Delay2_DSTATE;
    } else {
        if (((sint32)rtb_RelationalOperator_fk) != 0) {
            /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Switch1' incorporates:
                         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Switch'
                         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Neg/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_l) != 0) {
                rtb_Switch_dl = rtb_Mul_mv;
            } else {
                rtb_Switch_dl = -rtb_Switch_dl;
            }
            /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FBC incl. DC/Limit/Functionality'/Switch1' */
        }
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Switch' */
        if (((sint32)rtb_RelationalOperator_jk) != 0) {
            /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Switch1' incorporates:
                         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Neg/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_e) != 0) {
                rtb_Mul_c = rtb_Mul_gy;
            } else {
                rtb_Mul_c = -rtb_Mul_c;
            }
            /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Switch1' */
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of FFC/Limit/Functionality'/Switch' */
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Switch' */
        if (((sint32)rtb_RelationalOperator) != 0) {
            /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Switch1' incorporates:
                         *  UnaryMinus: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Neg/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1) != 0) {
                rtb_Mul_n = rtb_Mul;
            } else {
                rtb_Mul_n = -rtb_Mul_n;
            }
            /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Switch1' */
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Limit of DeltaFCmd/Limit/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_o[0] = rtb_DataTypeConversion_m;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_o[1] = rtb_Sum_ia;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_o[2] = rtb_Sum_ga;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn4' */
    rtb_VectorConcatenate_o[3] = rtb_Sum_bdn;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate_o[4] = rtb_Min;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate_o[5] = rtb_Sum_fn;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/logical_value'/Signal Conversion' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/logical_value'/Constant'
         */
    rtb_SFunction = 0U;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate_o[6] = rtb_SFunction;
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate_o[7] = rtb_SFunction;
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay/DELAY_RE/Functionality'/Switch4' incorporates:
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8/DELAY_RE/Functionality'/Switch4'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9/DELAY_RE/Functionality'/Switch4'
         */
    if (((sint32)rtb_DataTypeConversion_k) != 0) {
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_j = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_pn = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_g = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_cw = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_p5d = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_jg = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_b = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_b2 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_gr = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_a = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_kq = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_fl = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_m = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_e = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_i0 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_o = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_pa = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_js = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_nj = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_ip = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_ks = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_jo = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_hi = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_bb = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_j5 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_lu = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_fm = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_bs = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_lx = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_dn = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_p = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_d = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_n = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_p5 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_nu = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_c = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_i = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_p3 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_ck = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_h = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_jl = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_i4 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_ir = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_dg = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_jw = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_f = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_l = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_g3 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_k = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_i0y = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_lj = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_oj = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_jm = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_ld = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_m3 = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_hw = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_kw = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_ei = 0U;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9'/Unit_Delay13' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9/DELAY_RE'/IV'
                 */
        DW_tctclm_Unit_Delay13_DSTATE_dm = 0U;
    } else {
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_j = rtb_Sum_bx;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay1'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_pn = rtb_Sum_gt;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay2'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_g = rtb_Sum_ad;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay3'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_cw = rtb_Sum_a4;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay4'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_p5d = rtb_Sum_nor;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay5'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_jg = rtb_Sum_g5;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay6'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_b = rtb_Sum_eh;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay7'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_b2 = rtb_Switch1_bs;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay8'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_gr = rtb_Switch1_ds;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay9'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_a = rtb_Switch1_eh;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_kq = rtb_Sum_o1;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay1'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_fl = rtb_Sum_as;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay2'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_m = rtb_Sum_ni;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay3'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_e = rtb_Sum_pv;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay4'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_i0 = rtb_Sum_ox;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay5'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_o = rtb_Sum_fh;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay6'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_pa = rtb_Sum_d;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay7'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_js = rtb_Switch1_ol;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay8'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_nj = rtb_Switch1_e;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter1/delay9'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_ip = rtb_Switch1_f4;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_ks = rtb_Sum_ps;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay1'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_jo = rtb_Switch1_gq;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay2'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_hi = rtb_Sum_il;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay3'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_bb = rtb_Sum_mi;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay4'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_j5 = rtb_Sum_gg;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay5'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_lu = rtb_Sum_h3;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay6'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_fm = rtb_Sum_af;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay7'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_bs = rtb_Sum_a3;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay8'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_lx = rtb_Sum_o;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter2/delay9'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_dn = rtb_Switch1_m;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE = rtb_Switch_lo;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay1'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_p = rtb_Switch1_dv;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay2'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_d = rtb_Switch1_iu;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay3'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_n = rtb_Switch1_k;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay4'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_p5 = rtb_Switch1_d;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay5'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_nu = rtb_Switch1_ej;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay6'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_c = rtb_Switch1_ka;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay7'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_i = rtb_Switch1_fq;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay8'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_p3 = rtb_Switch1_fh;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter3/delay9'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_ck = rtb_Switch1_ed;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_h = rtb_Sum_na;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay1'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_jl = rtb_Sum_ed;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay2'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_i4 = rtb_Sum_nqw;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay3'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_ir = rtb_Sum_dc;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay4'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_dg = rtb_Sum_c;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay5'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_jw = rtb_Sum_oz;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay6'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_f = rtb_Sum_iv;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay7'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_l = rtb_Switch1_it;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay8'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_g3 = rtb_Switch1_i0;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter4/delay9'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_k = rtb_Switch1_ep;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_i0y = rtb_Sum_cty;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay1'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_lj = rtb_Sum_gfe;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay2'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_oj = rtb_Sum_b0b;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay3'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_jm = rtb_Sum_n;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay4'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_ld = rtb_Sum_oa;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay5'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_m3 = rtb_Sum_o2;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay6'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_hw = rtb_Sum_bp;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay7'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_kw = rtb_Sum_kp;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay8'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_ei = rtb_Switch1_mh;
        /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter5/delay9'/Unit_Delay13' */
        DW_tctclm_Unit_Delay13_DSTATE_dm = rtb_Switch1_l2;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/ErrorCounter/delay/DELAY_RE/Functionality'/Switch4' */
    /* S-Function (sfun_setbit): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[8] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_o[0];
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
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/Logical NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/Logical NOT/Functionality'/NOT'
         */
    rtb_SFunction = (uint8)(!(((sint32)rtb_DataTypeConversion) != 0));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Constant'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Constant3'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Constant1'/Constant'
         *  Inport: '<Root>/S_TCTLGC_DeltaFCmd_deg'
         *  Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Division/Div/Functionality/Div'/Div'
         *  Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Mul2/Functionality'/Mul'
         */
    if (((sint32)GET_P_TCTCLM_FbcCrvInterface_nu()) != 0) {
        rtb_Switch_ft = rtb_Switch_dl;
    } else {
        /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Sum1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Constant1'/Constant'
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Constant2'/Constant'
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Constant4'/Constant'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Mul/Functionality'/Mul'
                 *  Product: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Sum/Functionality'/Sum'
                 */
        rtb_Switch_ft = (((GET_S_LCFRCV_VehVelX_mps() * GET_S_LCFRCV_VehVelX_mps()) * GET_P_VEH_SelfSteeringGrd_nu()) + GET_P_VEH_DistCogToFrontAxle_m()) + GET_P_VEH_DistCogToRearAxle_m();
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Division/Switch/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Division/Abs/Functionality'/Abs'
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Division/Constant5'/Constant'
                 *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Division/GT/Functionality'/GT'
                 */
        if (!(f32_abs_f32(rtb_Switch_ft) > GET_P_LCF_AlmostZero_nu())) {
            rtb_Switch_ft = GET_P_LCF_AlmostZero_nu();
        }
        /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Conversion of steer angle rqeuest to curvature request/Division/Switch/Functionality'/Switch' */
        rtb_Switch_ft = ((GET_S_TCTLGC_DeltaFCmd_deg() * 3.14159F) / 180.0F) / rtb_Switch_ft;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Constant3'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Constant4'/Constant'
         */
    if (((sint32)GET_P_TCTCLM_FfcCrvInterface_nu()) != 0) {
        rtb_Sum_h = rtb_Mul_c;
    } else {
        rtb_Sum_h = 0.0F;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Switch1/Functionality'/Switch' */
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Sum1/Functionality'/Sum' */
    rtb_Switch_ft += rtb_Sum_h;
    /* Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Sum2/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTDTE_CrvReqBnkAglComp_1pm'
         *  Inport: '<Root>/S_TCTDTE_CrvReqDstrbComp_1pm'
         */
    rtb_Sum_h = GET_S_TCTDTE_CrvReqDstrbComp_1pm() + GET_S_TCTDTE_CrvReqBnkAglComp_1pm();
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's upper limit for the plausibility check/Switch6/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's upper limit for the plausibility check/Constant10'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's upper limit for the plausibility check/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_LCFRCV_LaneStatusLaKMC_st'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's upper limit for the plausibility check/EQ/Functionality'/EQ'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's upper limit for the plausibility check/Add1/Functionality'/Sum'
         */
    if (((sint32)GET_S_LCFRCV_LaneStatusLaKMC_st()) == ((sint32)((uint8) E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_LEFT_LANE))) {
        rtb_Switch_gz = rtb_Switch_k + rtb_Sum_h;
    } else {
        rtb_Switch_gz = 1.0F;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's upper limit for the plausibility check/Switch6/Functionality'/Switch' */
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's lower limit for the plausibility check/Switch7/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's lower limit for the plausibility check/Constant11'/Constant'
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's lower limit for the plausibility check/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCFRCV_LaneStatusLaKMC_st'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's lower limit for the plausibility check/EQ/Functionality'/EQ'
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's lower limit for the plausibility check/Add2/Functionality'/Sum'
         */
    if (((sint32)GET_S_LCFRCV_LaneStatusLaKMC_st()) == ((sint32)((uint8) E_LCF_LaKMCLaneStatusType_E_LCF_DEPARTING_RIGHT_LANE))) {
        rtb_Sum_h += rtb_Switch_k;
    } else {
        rtb_Sum_h = -1.0F;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Determine control signal's lower limit for the plausibility check/Switch7/Functionality'/Switch' */
    /* RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/CycleTimer/GE/Functionality'/GE' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_DataTypeConversion_k = (uint8)(rtb_Switch >= GET_S_LCFRCV_SysCycleTimeVeh_sec());
    /* S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality'/Logical Operator1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not'/Unit_Delay'
         */
    rtb_DataTypeConversion_m = (uint8)((((sint32)DW_tctclm_Unit_Delay_DSTATE_ks) != 0) && (!(((sint32)rtb_DataTypeConversion_k) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING'/fcg' */
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/AND1/Functionality'/AND'
         *  Logic: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Plausibility Check/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Plausibility Check/GT/Functionality'/GT'
         *  RelationalOperator: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Plausibility Check of the Control Signal -> Check the Direction of Request/Plausibility Check/LT/Functionality'/LT'
         */
    rtb_Switch1_gq = (uint8)(((rtb_Switch_ft > rtb_Switch_gz) || (rtb_Switch_ft < rtb_Sum_h)) && (((sint32)rtb_DataTypeConversion_m) != 0));
    /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/RSFLIPFLOP/Functionality'/Constant'
         *  Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning'/Unit_Delay1'
         */
    if (((sint32)rtb_SFunction) != 0) {
        rtb_Switch_lo = 0U;
    } else if (((sint32)rtb_Switch1_gq) != 0) {
        /* Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/RSFLIPFLOP/Functionality'/Constant1'
                 */
        rtb_Switch_lo = 1U;
    } else {
        rtb_Switch_lo = DW_tctclm_Unit_Delay1_DSTATE_g;
    }
    /* End of Switch: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning/RSFLIPFLOP/Functionality'/Switch' */
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate_k[0] = rtb_Min_o;
    /* S-Function (sfun_getbit_77): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/get_bit4/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/get_bit4/Functionality'/Const_bit_sel_param'
         */
    rtb_SFunction = flag_get_u32_u8(GET_S_TCTEST_QualifierService_nu(), ((uint8) 12U));
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/get_bit4/Functionality'/DTC_out' */
    rtb_VectorConcatenate_k[1] = rtb_SFunction;
    /* S-Function (sfun_getbit_77): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/get_bit1/Functionality'/S-Function' incorporates:
         *  Constant: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/get_bit1/Functionality'/Const_bit_sel_param'
         */
    rtb_SFunction = flag_get_u32_u8(GET_S_TCTEST_QualifierService_nu(), ((uint8) 13U));
    /* DataTypeConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/get_bit1/Functionality'/DTC_out' */
    rtb_VectorConcatenate_k[2] = rtb_SFunction;
    /* S-Function (sfun_setbit): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Merge Qualifier Signals/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint8 temp = ((uint8)0U);
        {
            uint8 set_mask = 0;
            uint8 reset_mask = 0;
            const uint8 selection_vec[3] = { 0U, 4U, 5U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate_k[0];
                for (i1=0; i1 < 3; i1++) {
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
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Determine Current Curvature Freeze'/Unit Delay5' */
    DW_tctclm_UnitDelay5_DSTATE = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/CycleTimer'/Unit Delay1' */
    DW_tctclm_UnitDelay1_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of DeltaFCmd'/Unit_Delay' */
    DW_tctclm_Unit_Delay_DSTATE = rtb_Mul;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         */
    DW_tctclm_Unit_Delay_DSTATE_fo = GET_S_MCTLFC_ControllingFunction_nu();
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FFC'/Unit_Delay' */
    DW_tctclm_Unit_Delay_DSTATE_k = rtb_Mul_gy;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Gradient Limiter and Saturation/Gradient Limitation of FBC incl. DC'/Unit_Delay' */
    DW_tctclm_Unit_Delay_DSTATE_l = rtb_Mul_mv;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning'/Unit_Delay2' */
    DW_tctclm_Unit_Delay2_DSTATE_p = rtb_Switch_lo;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay1' */
    DW_tctclm_Unit_Delay1_DSTATE = rtb_Mul_m0;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay3' */
    DW_tctclm_Unit_Delay3_DSTATE = rtb_Switch2_o;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/TCTCLM Watchdog'/Unit_Delay' */
    DW_tctclm_Unit_Delay_DSTATE_p = rtb_Sum_caj;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request'/Unit_Delay' */
    DW_tctclm_Unit_Delay_DSTATE_f = rtb_Switch_dl;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request'/Unit_Delay1' */
    DW_tctclm_Unit_Delay1_DSTATE_c = rtb_Mul_c;
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Freeze control signals in case of function degradation request'/Unit_Delay2' */
    DW_tctclm_Unit_Delay2_DSTATE = rtb_Mul_n;
    /* S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctclm_Unit_Delay_DSTATE_ks = rtb_DataTypeConversion_k;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Timer -> Determine if the Plausibility Check is active or not/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Hold Warning'/Unit_Delay1' */
    DW_tctclm_Unit_Delay1_DSTATE_g = rtb_Switch_lo;
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess'/M_TCTCLM' */
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch'/copy1' */
    SET_S_TCTCLM_QuServTrajCtr_nu(rtb_sfun_setbit_c);
    /* Outputs for Atomic SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess'/M_TCTCLM' */
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch1'/copy1' incorporates:
         *  Sum: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/M_TCTCLM/Sum/Functionality'/Sum'
         */
    SET_S_TCTCLM_Limiter_TgtCrv_1pm(rtb_Mul_c + rtb_Switch_dl);
    /* End of Outputs for SubSystem: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess'/M_TCTCLM' */
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch10'/copy1' */
    SET_D_TCTCLM_FlagTimerLastCall_nu(rtb_DataTypeConversion_m);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch11'/copy1' */
    SET_D_TCTCLM_PlausibCheckActive_nu(rtb_DataTypeConversion_h);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch12'/copy1' */
    SET_D_TCTCLM_FrozenVehCrv_1pm(rtb_Switch_k);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch13'/copy1' */
    SET_D_TCTCLM_PlausiChkUpLimit_1pm(rtb_Switch_gz);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch14'/copy1' */
    SET_D_TCTCLM_PlausiChkLowLimit_1pm(rtb_Sum_h);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch16'/copy1' */
    SET_D_TCTCLM_SumCtrlSignal_1pm(rtb_Switch_ft);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch17'/copy1' */
    SET_D_TCTCLM_QuServErrMemReset_nu(rtb_Sum_nk);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch19'/copy1' */
    SET_D_TCTCLM_LimiterWthtErrCntr_nu(rtb_sfun_setbit_b);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch2'/copy1' */
    SET_S_TCTCLM_LimiterWarning_nu(rtb_Switch1_gq);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch3'/copy1' */
    SET_D_TCTCLM_QuServErrMemSet_nu(rtb_Sum_b5);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch4'/copy1' */
    SET_D_TCTCLM_QualifierService_nu(rtb_sfun_setbit);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch5'/copy1' */
    SET_S_TCTCLM_Ffc_1pm(rtb_Mul_c);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch6'/copy1' */
    SET_S_TCTCLM_FbcDc_1pm(rtb_Switch_dl);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch7'/copy1' */
    SET_S_TCTCLM_DeltaFCmd_deg(rtb_Mul_n);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch8'/copy1' */
    SET_D_TCTCLM_PlausibCheckPrecond_nu(rtb_DataTypeConversion);
    /* SignalConversion: 'sda:TCTCLM/TCTCLM/TCTCLM_VehProcess/branch9'/copy1' */
    SET_D_TCTCLM_TimerValue_sec(rtb_Switch);
}
#include "Pse_TCTCLM.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
