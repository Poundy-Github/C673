/**************************************************************************
COPYRIGHT (C) $Date: 2019/07/03 09:35:56CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJCTR/TCTEST_VEH/TCTEST/i/project.pj $
$Log: TCTEST.c  $
Revision 1.4.1.4 2019/07/03 09:35:56CEST Schrader, Moritz (uia92406) (uia92406) 
automatically created
File          : TCTEST
Generated on  : Wed 03.07.2019 at 09:23:13 (UTC+01:00)
MD5           : [2370201497   302540489   802595725  2191176004 0](TCTEST)
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
#include "TCTEST.h"
#include "TCTEST_private.h"
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
#define TCTEST_START_SEC_DATA_8
#include "TCTEST_MemMap.h"
static uint8 DW_tctest_Unit_Delay_DSTATE_ei;
#define TCTEST_STOP_SEC_DATA_8
#include "TCTEST_MemMap.h"
#define TCTEST_START_SEC_DATA_32
#include "TCTEST_MemMap.h"
static float32 DW_tctest_Unit_Delay4_DSTATE;
static float32 DW_tctest_Unit_Delay_DSTATE;
static float32 DW_tctest_Unit_Delay6_DSTATE;
static float32 DW_tctest_Unit_Delay_DSTATE_n;
static float32 DW_tctest_Unit_Delay1_DSTATE;
static float32 DW_tctest_Unit_Delay2_DSTATE;
static float32 DW_tctest_Unit_Delay3_DSTATE;
static float32 DW_tctest_Unit_Delay4_DSTATE_k;
static float32 DW_tctest_Unit_Delay_DSTATE_a[2];
static float32 DW_tctest_Unit_Delay1_DSTATE_j;
static float32 DW_tctest_Unit_Delay6_DSTATE_h;
static float32 DW_tctest_Unit_Delay_DSTATE_e;
static float32 DW_tctest_Unit_Delay1_DSTATE_e;
static float32 DW_tctest_Unit_Delay2_DSTATE_i;
static float32 DW_tctest_Unit_Delay3_DSTATE_m;
static float32 DW_tctest_Unit_Delay4_DSTATE_j;
static float32 DW_tctest_Unit_Delay_DSTATE_nf[3];
static float32 DW_tctest_Unit_Delay4_DSTATE_e;
static float32 DW_tctest_Unit_Delay4_DSTATE_k3;
static float32 DW_tctest_Unit_Delay1_DSTATE_l;
static float32 DW_tctest_Unit_Delay6_DSTATE_i;
static float32 DW_tctest_Unit_Delay2_DSTATE_e;
static float32 DW_tctest_Unit_Delay_DSTATE_e5;
static float32 DW_tctest_Unit_Delay_DSTATE_a0;
static float32 DW_tctest_Unit_Delay1_DSTATE_b;
static float32 DW_tctest_Unit_Delay2_DSTATE_b;
static float32 DW_tctest_Unit_Delay3_DSTATE_mt;
static float32 DW_tctest_Unit_Delay4_DSTATE_d;
static float32 DW_tctest_Unit_Delay_DSTATE_c[4];
static float32 DW_tctest_Unit_Delay4_DSTATE_b;
static float32 DW_tctest_Unit_Delay1_DSTATE_a;
static float32 DW_tctest_UnitDelay2_DSTATE;
static float32 DW_tctest_Unit_Delay4_DSTATE_f;
static float32 DW_tctest_UnitDelay2_DSTATE_h;
static float32 DW_tctest_UnitDelay2_DSTATE_b;
static float32 DW_tctest_Unit_Delay4_DSTATE_ex;
static float32 DW_tctest_Unit_Delay4_DSTATE_m;
static float32 DW_tctest_Unit_Delay6_DSTATE_hj;
static float32 DW_tctest_Unit_Delay4_DSTATE_n;
static float32 DW_tctest_Unit_Delay_DSTATE_h[3];
static float32 DW_tctest_UnitDelay2_DSTATE_d;
static float32 DW_tctest_Unit_Delay_DSTATE_p;
static float32 DW_tctest_UnitDelay2_DSTATE_m;
static float32 DW_tctest_Unit_Delay4_DSTATE_o;
static float32 DW_tctest_Unit_Delay4_DSTATE_og;
static float32 DW_tctest_Unit_Delay4_DSTATE_g;
static float32 DW_tctest_Unit_Delay4_DSTATE_jr;
#define TCTEST_STOP_SEC_DATA_32
#include "TCTEST_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TCTEST/TCTEST'/TCTEST_VehReset'
 * Block description for: 'sda:TCTEST/TCTEST'/TCTEST_VehReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTEST_VehReset
#include "Pse_TCTEST.h"
/* Short description:  */
void TCTEST_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant'/Constant' */
    SET_S_TCTEST_SObsBeta_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant1'/Constant' */
    SET_S_TCTEST_QualifierService_nu(0U);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant10'/Constant' */
    SET_D_TCTEST_CrObsCrosswindRaw_New(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant11'/Constant' */
    SET_S_TCTEST_MccA11_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant12'/Constant' */
    SET_D_TCTEST_PlObsDeltaTheta_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant13'/Constant' */
    SET_S_TCTEST_MccA12_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant14'/Constant' */
    SET_S_TCTEST_MccA21_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant15'/Constant' */
    SET_D_TCTEST_PlObsDeltaY_met(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant16'/Constant' */
    SET_S_TCTEST_MccA22_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant17'/Constant' */
    SET_S_TCTEST_CurSteerAngle_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant18'/Constant' */
    SET_S_TCTEST_MccB11_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant19'/Constant' */
    SET_S_TCTEST_MccB21_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant2'/Constant' */
    SET_D_TCTEST_SteerAngleVDY_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant20'/Constant' */
    SET_D_TCTEST_HdrMul_perc(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant21'/Constant' */
    SET_D_TCTEST_HdrMul_bool(0U);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant22'/Constant' */
    SET_D_TCTEST_HdrMean_perc(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant23'/Constant' */
    SET_D_TCTEST_HdrMean_bool(0U);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant24'/Constant' */
    SET_D_TCTEST_KObsKappa_1pm(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant25'/Constant' */
    SET_S_TCTEST_KObsKappa_1pm(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant26'/Constant' */
    SET_S_TCTEST_CrObsCrosswind_New(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant27'/Constant' */
    SET_S_TCTEST_MccH11Cw_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant28'/Constant' */
    SET_S_TCTEST_MccH21Cw_nu(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant3'/Constant' */
    SET_D_TCTEST_SObsBeta_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant4'/Constant' */
    SET_S_TCTEST_PlObsDeltaTheta_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant5'/Constant' */
    SET_S_TCTEST_PlObsDeltaY_met(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant6'/Constant' */
    SET_D_TCTEST_SteerAngleLaDMC_rad(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant7'/Constant' */
    SET_D_TCTEST_SObsPsiDot_rps(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant8'/Constant' */
    SET_D_TCTEST_InPlObsDeltaY_met(0.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehReset/Constant9'/Constant' */
    SET_D_TCTEST_InPlObsCurvature_1pm(0.0F);
}
#include "Pse_TCTEST.h"
/*
 * Output and update for function-call system: 'sda:TCTEST/TCTEST'/TCTEST_VehProcess'
 * Block description for: 'sda:TCTEST/TCTEST'/TCTEST_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTEST_VehProcess
#include "Pse_TCTEST.h"
/* Short description:  */
void TCTEST_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Switch;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_b;
    float32 rtb_Switch2_c;
    float32 rtb_ip_lookup_fxpt_sfun_7_o1;
    float32 rtb_ip_lookup_fxpt_sfun_7_ml;
    float32 rtb_ip_lookup_fxpt_sfun_7_oa;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_et;
    float32 rtb_ip_lookup_fxpt_sfun_7_om;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_eq;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    float32 rtb_ip_lookup_fxpt_sfun_7_bq;
    float32 rtb_ip_lookup_fxpt_sfun_7_gb;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Div_ca;
    float32 rtb_Unit_Delay_e;
    float32 rtb_SFunction;
    float32 rtb_Sum_jw[4];
    float32 rtb_Div_cr;
    float32 rtb_Unit_Delay4_a;
    float32 rtb_SFunction_k;
    float32 rtb_Div_j;
    float32 rtb_Unit_Delay1_p;
    float32 rtb_SFunction_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_n;
    float32 rtb_ip_lookup_fxpt_sfun_7_k;
    float32 rtb_Div_aa;
    float32 rtb_Unit_Delay_g;
    float32 rtb_SFunction_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_bb;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_ij;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_k3;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    float32 rtb_ip_lookup_fxpt_sfun_7_k4;
    float32 rtb_Switch_kf;
    float32 rtb_Mul_od;
    uint32 rtb_sfun_setbit;
    uint16 rtb_conversion_sfunction2;
    uint8 rtb_VectorConcatenate[14];
    uint8 rtb_DataTypeConversion;
    float32 rtb_Sum_ps;
    float32 rtb_Div;
    float32 rtb_Div_iz;
    float32 rtb_Sum_ibd;
    float32 rtb_Div_pl;
    float32 rtb_Div_e;
    float32 rtb_Mul_bh;
    float32 rtb_Div_e2;
    float32 rtb_Div_hq;
    float32 rtb_Sum_nm;
    float32 rtb_SystemMatrixA[6];
    float32 rtb_SystemMatrixA_d[9];
    float32 rtb_Unit_Delay_eq[3];
    uint8 rtb_NE;
    uint8 rtb_EQ;
    float32 rtb_Mul_d5[2];
    float32 rtb_Sum_lt;
    float32 rtb_Unit_Delay_h[2];
    float32 rtb_Switch_o;
    float32 rtb_Unit_Delay_d;
    float32 rtb_Unit_Delay1;
    float32 rtb_Unit_Delay2;
    float32 rtb_Unit_Delay3;
    float32 rtb_VectorConcatenate2[4];
    float32 rtb_MeasDeviationVector[2];
    float32 rtb_Switch_a;
    float32 rtb_Unit_Delay_c;
    float32 rtb_Unit_Delay1_i;
    float32 rtb_Unit_Delay2_d;
    float32 rtb_Unit_Delay3_g;
    float32 rtb_Switch6_it;
    float32 rtb_SystemMatrixA_m[12];
    float32 rtb_Mul_j0[3];
    float32 rtb_Mul_gu[4];
    float32 rtb_Max;
    float32 rtb_Multiport_Switch;
    float32 rtb_Unit_Delay_g0[4];
    float32 rtb_Div_f;
    float32 rtb_Unit_Delay_mw;
    float32 rtb_Unit_Delay1_c;
    float32 rtb_Unit_Delay2_g;
    float32 rtb_Unit_Delay3_o;
    float32 rtb_SystemMatrixA_p[16];
    uint8 rtb_GE_p;
    uint8 rtb_Switch_m;
    float32 rtb_Switch_j;
    float32 rtb_Div_p;
    uint8 rtb_RelationalOperator1;
    uint8 rtb_RelationalOperator;
    uint8 rtb_RelationalOperator1_l;
    uint8 rtb_RelationalOperator_n;
    float32 rtb_Unit_Delay_bm[3];
    float32 rtb_SecondColumnOfA[3];
    float32 rtb_Switch6_b;
    float32 rtb_SystemMatrixA_l[9];
    float32 rtb_Switch6_np;
    uint8 rtb_RelationalOperator1_my;
    float32 rtb_Sum_kj;
    uint8 rtb_RelationalOperator_m;
    float32 rtb_Switch6_jp;
    float32 rtb_Switch6_c;
    float32 rtb_Switch6_oi;
    float32 rtb_Switch2_e;
    float32 rtb_Switch_jd;
    float32 rtb_Switch_b;
    float32 rtb_Switch_c0;
    float32 rtb_Switch_k;
    float32 rtb_Sum_ayv[2];
    float32 rtb_Sum_jz[3];
    sint32 i;
    float32 rtb_SystemMatrixA_4[3];
    float32 rtb_Unit_Delay_p[3];
    float32 rtb_Mul_ka[4];
    sint32 i_0;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Switch1/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Application Parameter1'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Relational Operator/Functionality'/LT'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Relational Operator1/Functionality'/GE'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch'
         */
    if (GET_P_TCTEST_MinimumSpeed_mps() < f32_abs_f32(GET_S_LCFRCV_VehVelX_mps())) {
        rtb_Switch = GET_S_LCFRCV_VehVelX_mps();
    } else if (GET_S_LCFRCV_VehVelX_mps() >= 0.0F) {
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch' */
        rtb_Switch = GET_P_TCTEST_MinimumSpeed_mps();
    } else {
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Application Parameter'/Constant'
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Gain/Functionality'/Mul'
                 */
        rtb_Switch = -GET_P_TCTEST_MinimumSpeed_mps();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/EnforceMinimumVelocityMagnitude/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division/GT/Functionality'/GT'
         */
    if (f32_abs_f32(rtb_Switch) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = rtb_Switch;
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division/Switch/Functionality'/Switch' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Y_TCTEST_PreviewDistX_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TCTEST_PreviewDistX_met(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Y_TCTEST_PreviewDistX_met/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_iz = rtb_ip_lookup_fxpt_sfun_7 + GET_P_VEH_DistCogToFrontAxle_m();
    /* DTC_F32 : sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/DTC_F32'/conversion_sfunction2 */
    rtb_conversion_sfunction2 = GET_P_VEH_Mass_kg();
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division4/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division4/Constant3'/Constant'
         *  DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/DTC_F32'/Data Type Conversion'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division4/GT/Functionality'/GT'
         */
    if (((float32)((sint32)rtb_conversion_sfunction2)) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Mul_bh = (float32)rtb_conversion_sfunction2;
    } else {
        rtb_Mul_bh = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division4/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division4/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Constant1'/Constant'
         */
    rtb_Sum_ibd = 1.0F / rtb_Mul_bh;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division1/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division1/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division1/Constant3'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division2/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division1/GT/Functionality'/GT'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division2/Switch/Functionality'/Switch'
         */
    if (GET_P_VEH_Inertia_kgm2() > GET_P_LCF_AlmostZero_nu()) {
        rtb_Mul_bh = GET_P_VEH_Inertia_kgm2();
        rtb_Div_e2 = GET_P_VEH_Inertia_kgm2();
    } else {
        rtb_Mul_bh = GET_P_LCF_AlmostZero_nu();
        rtb_Div_e2 = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division1/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division3/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division3/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division3/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division3/GT/Functionality'/GT'
         */
    if (f32_abs_f32(rtb_Switch) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Div = rtb_Switch;
    } else {
        rtb_Div = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division3/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant10'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant11'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant7'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division1/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division2/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Division3/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Mul4/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Mul5/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Sum/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A11/Sum2/Functionality'/Sum'
         */
    rtb_Sum_ibd = ((((GET_P_VEH_DistCogToFrontAxle_m() * rtb_Div_iz) / rtb_Mul_bh) + rtb_Sum_ibd) * ((-GET_P_VEH_CorStiffFrontAxle_Npr()) / rtb_Switch6_np)) - ((rtb_Sum_ibd - ((rtb_Div_iz * GET_P_VEH_DistCogToRearAxle_m()) / rtb_Div_e2)) * (GET_P_VEH_CorStiffRearAxle_Npr() / rtb_Div));
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul3/Functionality'/Mul' */
    rtb_Div = rtb_Switch * rtb_Switch;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division/GT/Functionality'/GT'
         */
    if (f32_abs_f32(rtb_Div) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = rtb_Div;
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division1/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division1/Constant3'/Constant'
         *  DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/DTC_F32'/Data Type Conversion'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division1/GT/Functionality'/GT'
         */
    if (((float32)((sint32)rtb_conversion_sfunction2)) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Mul_bh = (float32)rtb_conversion_sfunction2;
    } else {
        rtb_Mul_bh = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division1/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division1/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Constant1'/Constant'
         */
    rtb_Div_pl = 1.0F / rtb_Mul_bh;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division4/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division4/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division4/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division4/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Div) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Div = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division4/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division2/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division2/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division2/Constant3'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division3/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division2/GT/Functionality'/GT'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division3/Switch/Functionality'/Switch'
         */
    if (GET_P_VEH_Inertia_kgm2() > GET_P_LCF_AlmostZero_nu()) {
        rtb_Mul_bh = GET_P_VEH_Inertia_kgm2();
        rtb_Div_e2 = GET_P_VEH_Inertia_kgm2();
    } else {
        rtb_Mul_bh = GET_P_LCF_AlmostZero_nu();
        rtb_Div_e2 = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division2/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Sum5/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant10'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant11'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant7'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Constant2'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division2/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division3/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Division4/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul4/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul5/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul6/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Mul7/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Sum/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A12/Sum4/Functionality'/Sum'
         */
    rtb_Div_e = ((((rtb_Div_pl - ((GET_P_VEH_DistCogToRearAxle_m() * rtb_Div_iz) / rtb_Mul_bh)) * (GET_P_VEH_CorStiffRearAxle_Npr() / rtb_Switch6_np)) * (GET_P_VEH_DistCogToRearAxle_m() + rtb_Div_iz)) - (((((rtb_Div_iz * GET_P_VEH_DistCogToFrontAxle_m()) / rtb_Div_e2) + rtb_Div_pl) * (GET_P_VEH_CorStiffFrontAxle_Npr() / rtb_Div)) * (GET_P_VEH_DistCogToFrontAxle_m() - rtb_Div_iz))) - 1.0F;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Division/GT/Functionality'/GT'
         */
    if (GET_P_VEH_Inertia_kgm2() > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = GET_P_VEH_Inertia_kgm2();
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Division/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant10'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant11'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant7'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Mul8/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Mul9/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A21/Sum4/Functionality'/Sum'
         */
    rtb_Div_pl = ((GET_P_VEH_CorStiffRearAxle_Npr() * GET_P_VEH_DistCogToRearAxle_m()) - (GET_P_VEH_CorStiffFrontAxle_Npr() * GET_P_VEH_DistCogToFrontAxle_m())) / rtb_Switch6_np;
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Mul3/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         */
    rtb_Div = rtb_Switch * GET_P_VEH_Inertia_kgm2();
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Division/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Div) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Div = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Division/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant10'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant11'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant7'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Mul10/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Mul8/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Mul9/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Sum4/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc A22/Sum5/Functionality'/Sum'
         */
    rtb_Div = (-(((GET_P_VEH_CorStiffFrontAxle_Npr() * GET_P_VEH_DistCogToFrontAxle_m()) * (GET_P_VEH_DistCogToFrontAxle_m() - rtb_Div_iz)) + ((rtb_Div_iz + GET_P_VEH_DistCogToRearAxle_m()) * (GET_P_VEH_DistCogToRearAxle_m() * GET_P_VEH_CorStiffRearAxle_Npr())))) / rtb_Div;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division/GT/Functionality'/GT'
         */
    if (f32_abs_f32(rtb_Switch) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = rtb_Switch;
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division1/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division1/Constant3'/Constant'
         *  DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/DTC_F32'/Data Type Conversion'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division1/GT/Functionality'/GT'
         */
    if (((float32)((sint32)rtb_conversion_sfunction2)) > GET_P_LCF_AlmostZero_nu()) {
        rtb_Mul_bh = (float32)rtb_conversion_sfunction2;
    } else {
        rtb_Mul_bh = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division1/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division2/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division2/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division2/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division2/GT/Functionality'/GT'
         */
    if (GET_P_VEH_Inertia_kgm2() > GET_P_LCF_AlmostZero_nu()) {
        rtb_Div_e2 = GET_P_VEH_Inertia_kgm2();
    } else {
        rtb_Div_e2 = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division2/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Mul3/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant10'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Constant1'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division1/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Division2/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Mul8/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B11/Sum5/Functionality'/Sum'
         */
    rtb_Mul_bh = (((GET_P_VEH_DistCogToFrontAxle_m() * rtb_Div_iz) / rtb_Div_e2) + (1.0F / rtb_Mul_bh)) * (GET_P_VEH_CorStiffFrontAxle_Npr() / rtb_Switch6_np);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Division/GT/Functionality'/GT'
         */
    if (GET_P_VEH_Inertia_kgm2() > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = GET_P_VEH_Inertia_kgm2();
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Division/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant10'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant5'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc B12/Mul8/Functionality'/Mul'
         */
    rtb_Div_e2 = (GET_P_VEH_CorStiffFrontAxle_Npr() * GET_P_VEH_DistCogToFrontAxle_m()) / rtb_Switch6_np;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division/GT/Functionality'/GT'
         */
    if (GET_P_VEH_Inertia_kgm2() > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = GET_P_VEH_Inertia_kgm2();
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Constant2'/Constant'
         */
    rtb_Div_hq = GET_P_VEH_CenterOfPressure_met() / rtb_Switch6_np;
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Constant9'/Constant'
         */
    rtb_Mul_od = GET_P_VEH_Inertia_kgm2() * rtb_Switch;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division1/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division1/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division1/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division1/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Mul_od) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Mul_od = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division1/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Mul/Functionality'/Mul' incorporates:
         *  DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/DTC_F32'/Data Type Conversion'
         */
    rtb_Sum_ps = ((float32)rtb_conversion_sfunction2) * rtb_Switch;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division2/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division2/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division2/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division2/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Sum_ps) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Sum_ps = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division2/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Constant'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Constant2'/Constant'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division1/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Division2/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Calc Single Track State Space Coefficitents/Calc H11_Crosswind/Mul1/Functionality'/Mul'
         */
    rtb_Sum_nm = ((GET_P_VEH_CenterOfPressure_met() * rtb_Div_iz) / rtb_Mul_od) + (1.0F / rtb_Sum_ps);
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain11_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Mul_od = F32_PTR_IP1D(GETA_Y_TCTEST_CrObsLueGain11_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain11_nu/Functionality'/dtcrwv' */
    rtb_SystemMatrixA[0] = rtb_Mul_od;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain21_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Mul_od = F32_PTR_IP1D(GETA_Y_TCTEST_CrObsLueGain21_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain21_nu/Functionality'/dtcrwv' */
    rtb_SystemMatrixA[1] = rtb_Mul_od;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain31_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Mul_od = F32_PTR_IP1D(GETA_Y_TCTEST_CrObsLueGain31_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain31_nu/Functionality'/dtcrwv' */
    rtb_SystemMatrixA[2] = rtb_Mul_od;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain12_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Mul_od = F32_PTR_IP1D(GETA_Y_TCTEST_CrObsLueGain12_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain12_nu/Functionality'/dtcrwv' */
    rtb_SystemMatrixA[3] = rtb_Mul_od;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain22_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Mul_od = F32_PTR_IP1D(GETA_Y_TCTEST_CrObsLueGain22_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain22_nu/Functionality'/dtcrwv' */
    rtb_SystemMatrixA[4] = rtb_Mul_od;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain32_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Mul_od = F32_PTR_IP1D(GETA_Y_TCTEST_CrObsLueGain32_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create Observer Feedback Matrix/Y_TCTEST_CrObsLueGain32_nu/Functionality'/dtcrwv' */
    rtb_SystemMatrixA[5] = rtb_Mul_od;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtFirstColumnOfAIn1' */
    rtb_SystemMatrixA_d[0] = rtb_Sum_ibd;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtFirstColumnOfAIn2' */
    rtb_SystemMatrixA_d[1] = rtb_Div_pl;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtSecondColumnOfAIn1' */
    rtb_SystemMatrixA_d[3] = rtb_Div_e;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtSecondColumnOfAIn2' */
    rtb_SystemMatrixA_d[4] = rtb_Div;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn1' */
    rtb_SystemMatrixA_d[6] = rtb_Sum_nm;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn2' */
    rtb_SystemMatrixA_d[7] = rtb_Div_hq;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements/Constant11'/Constant' */
    rtb_SystemMatrixA_d[8] = 0.0F;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements/Constant3'/Constant' */
    rtb_SystemMatrixA_d[5] = 0.0F;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements/Constant5'/Constant' */
    rtb_SystemMatrixA_d[2] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtInputVectorBIn1' */
    rtb_Unit_Delay_eq[0] = rtb_Mul_bh;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements'/ConcatBufferAtInputVectorBIn2' */
    rtb_Unit_Delay_eq[1] = rtb_Div_e2;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Create State Space System Elements/Constant17'/Constant' */
    rtb_Unit_Delay_eq[2] = 0.0F;
    /* MinMax: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Max = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeVeh_sec(), GET_P_LCF_AlmostZero_nu());
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Freeze and Enable/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Freeze and Enable/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_NE = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) != ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF)));
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion = (uint8)(!(((sint32)rtb_NE) != 0));
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Freeze and Enable/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Freeze and Enable/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) == ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)));
    /* S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset'/Unit_Delay'
         */
    rtb_DataTypeConversion = (uint8)(((((sint32)rtb_DataTypeConversion) != 0) || ((((sint32)DW_tctest_Unit_Delay_DSTATE_ei) != 0) && (!(((sint32)rtb_EQ) != 0)))) || (((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING'/fcg' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain1_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D(GETA_Y_TCTEST_SObsLueGain1_nu(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain1_nu/Functionality/odtc'/Sum' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_od = rtb_ip_lookup_fxpt_sfun_7_o;
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain1_nu/Functionality'/dtcrwv' */
    rtb_Mul_d5[0] = rtb_Mul_od;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain2_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D(GETA_Y_TCTEST_SObsLueGain2_nu(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain2_nu/Functionality/odtc'/Sum' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain2_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Mul_od = rtb_ip_lookup_fxpt_sfun_7_m;
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Y_TCTEST_SObsLueGain2_nu/Functionality'/dtcrwv' */
    rtb_Mul_d5[1] = rtb_Mul_od;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Sum5/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/Unit_Delay6'
         */
    rtb_Sum_lt = GET_S_LCFRCV_VehYawRate_rps() - DW_tctest_Unit_Delay6_DSTATE;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/ConcatBufferAtVector Concatenate3In1' */
    rtb_Unit_Delay_h[0] = rtb_Mul_bh;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/ConcatBufferAtVector Concatenate3In2' */
    rtb_Unit_Delay_h[1] = rtb_Div_e2;
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/deg to rad/Mul/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/deg to rad/Constant'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/deg to rad/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SteerAngleLatDMC_deg'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/deg to rad/Div/Functionality/Div'/Div'
         */
    rtb_Mul_od = (GET_S_LCFRCV_SteerAngleLatDMC_deg() / 180.0F) * 3.14159F;
    /* Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_OffCompStWheelAngle_rad'
         */
    rtb_Abs = f32_abs_f32(GET_S_LCFRCV_OffCompStWheelAngle_rad());
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Y_TCTEST_StwGearRatio_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_StwGearRatio_rad */
        FDPS_PTR_F32(GETA_X_TCTEST_StwGearRatio_rad(), rtb_Abs, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_b = F32_PTR_IP1D(GETA_Y_TCTEST_StwGearRatio_nu(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Y_TCTEST_StwGearRatio_nu/Functionality/odtc'/Sum' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Y_TCTEST_StwGearRatio_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Div_iz = rtb_ip_lookup_fxpt_sfun_7_b;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Division/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Div_iz) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Div_iz = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/SteerRatio/Division/Div1/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_OffCompStWheelAngle_rad'
         */
    rtb_Div_iz = GET_S_LCFRCV_OffCompStWheelAngle_rad() / rtb_Div_iz;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/Constant'/Constant'
         */
    if (((sint32)GET_P_TCTEST_UseSteerAngleLatDMC_nu()) != 0) {
        rtb_Switch_o = rtb_Mul_od;
    } else {
        rtb_Switch_o = rtb_Div_iz;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Select Source of Steer Angle/Switch/Functionality'/Switch' */
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay' */
    rtb_Unit_Delay_d = DW_tctest_Unit_Delay_DSTATE_n;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay1' */
    rtb_Unit_Delay1 = DW_tctest_Unit_Delay1_DSTATE;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay2' */
    rtb_Unit_Delay2 = DW_tctest_Unit_Delay2_DSTATE;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay3' */
    rtb_Unit_Delay3 = DW_tctest_Unit_Delay3_DSTATE;
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency/Constant1'/Constant'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay2'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay4'
         */
    switch (GET_P_TCTEST_DelayCyclesDeltaSs_nu()) {
    case 0:
        rtb_Sum_ps = rtb_Switch_o;
        break;
    case 1:
        rtb_Sum_ps = DW_tctest_Unit_Delay_DSTATE_n;
        break;
    case 2:
        rtb_Sum_ps = DW_tctest_Unit_Delay1_DSTATE;
        break;
    case 3:
        rtb_Sum_ps = DW_tctest_Unit_Delay2_DSTATE;
        break;
    case 4:
        rtb_Sum_ps = DW_tctest_Unit_Delay3_DSTATE;
        break;
    default:
        rtb_Sum_ps = DW_tctest_Unit_Delay4_DSTATE_k;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Multiport_Switch' */
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate2[0] = rtb_Sum_ibd;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate2[1] = rtb_Div_pl;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/ConcatBufferAtVector Concatenate1In1' */
    rtb_VectorConcatenate2[2] = rtb_Div_e;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/ConcatBufferAtVector Concatenate1In2' */
    rtb_VectorConcatenate2[3] = rtb_Div;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Sum9/Functionality'/Sum' incorporates:
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Product1/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Product4/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Sum8/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/Unit_Delay'
         */
    for (i = 0; i < 2; i++) {
        rtb_Switch6_np = 0.0F;
        for (i_0 = 0; i_0 < 2; i_0++) {
            rtb_Switch6_np += rtb_VectorConcatenate2[(i_0 << 1) + i] * DW_tctest_Unit_Delay_DSTATE_a[i_0];
        }
        rtb_Sum_ayv[i] = ((rtb_Mul_d5[i] * rtb_Sum_lt) + (rtb_Unit_Delay_h[i] * rtb_Sum_ps)) + rtb_Switch6_np;
    }
    /* End of Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Sum9/Functionality'/Sum' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_lt = 0.0F;
    } else {
        rtb_Sum_lt = (rtb_Max * rtb_Sum_ayv[0]) + DW_tctest_Unit_Delay_DSTATE;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Switch1'
         */
    if (rtb_Sum_lt >= 3.1415F) {
        rtb_Sum_lt = 3.1415F;
    } else {
        if (rtb_Sum_lt <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1'/MN'
                         */
            rtb_Sum_lt = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1/INTEGRATORK_REL1/Functionality'/Switch2' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Constant'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/P_TCTEST_SObsActive_nu'/Constant'
         */
    if (((sint32)GET_P_TCTEST_SObsActive_nu()) != 0) {
        rtb_Switch_a = rtb_Sum_lt;
    } else {
        rtb_Switch_a = 0.0F;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum1/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer'/Unit_Delay1'
         */
    rtb_MeasDeviationVector[0] = rtb_Switch_a - DW_tctest_Unit_Delay1_DSTATE_j;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum5/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer'/Unit_Delay6'
         */
    rtb_MeasDeviationVector[1] = GET_S_LCFRCV_VehYawRate_rps() - DW_tctest_Unit_Delay6_DSTATE_h;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay' */
    rtb_Unit_Delay_c = DW_tctest_Unit_Delay_DSTATE_e;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay1' */
    rtb_Unit_Delay1_i = DW_tctest_Unit_Delay1_DSTATE_e;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay2' */
    rtb_Unit_Delay2_d = DW_tctest_Unit_Delay2_DSTATE_i;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay3' */
    rtb_Unit_Delay3_g = DW_tctest_Unit_Delay3_DSTATE_m;
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency/Constant1'/Constant'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay2'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay4'
         */
    switch (GET_P_TCTEST_DelayCyclesDeltaSs_nu()) {
    case 0:
        rtb_Sum_ps = rtb_Switch_o;
        break;
    case 1:
        rtb_Sum_ps = DW_tctest_Unit_Delay_DSTATE_e;
        break;
    case 2:
        rtb_Sum_ps = DW_tctest_Unit_Delay1_DSTATE_e;
        break;
    case 3:
        rtb_Sum_ps = DW_tctest_Unit_Delay2_DSTATE_i;
        break;
    case 4:
        rtb_Sum_ps = DW_tctest_Unit_Delay3_DSTATE_m;
        break;
    default:
        rtb_Sum_ps = DW_tctest_Unit_Delay4_DSTATE_j;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Multiport_Switch' */
    for (i = 0; i < 3; i++) {
        /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Product1/Functionality'/Mul' incorporates:
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum8/Functionality'/Sum'
                 */
        rtb_SystemMatrixA_4[i] = 0.0F;
        for (i_0 = 0; i_0 < 2; i_0++) {
            rtb_SystemMatrixA_4[i] += rtb_SystemMatrixA[(3 * i_0) + i] * rtb_MeasDeviationVector[i_0];
        }
        /* End of Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Product1/Functionality'/Mul' */
        /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum3/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Product4/Functionality'/Mul'
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum8/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer'/Unit_Delay'
                 */
        rtb_Switch6_np = 0.0F;
        for (i_0 = 0; i_0 < 3; i_0++) {
            rtb_Switch6_np += rtb_SystemMatrixA_d[(3 * i_0) + i] * DW_tctest_Unit_Delay_DSTATE_nf[i_0];
        }
        rtb_Unit_Delay_p[i] = (rtb_Unit_Delay_eq[i] * rtb_Sum_ps) + rtb_Switch6_np;
        /* End of Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum3/Functionality'/Sum' */
        /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Sum8/Functionality'/Sum' */
        rtb_Sum_jz[i] = rtb_SystemMatrixA_4[i] + rtb_Unit_Delay_p[i];
    }
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL'/IV'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch6'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1'/Unit_Delay4'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch6_it = 0.0F;
        rtb_Sum_ps = 0.0F;
    } else {
        rtb_Switch6_it = (rtb_Max * rtb_Sum_jz[0]) + DW_tctest_Unit_Delay4_DSTATE;
        rtb_Sum_ps = (rtb_Max * rtb_Sum_jz[1]) + DW_tctest_Unit_Delay4_DSTATE_e;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_it >= 3.1415F) {
        rtb_Switch6_it = 3.1415F;
    } else {
        if (rtb_Switch6_it <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_it = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Sum_ps >= 3.1415F) {
        rtb_Switch2_e = 3.1415F;
    } else if (rtb_Sum_ps <= -3.1415F) {
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL'/MN'
                 */
        rtb_Switch2_e = -3.1415F;
    } else {
        rtb_Switch2_e = rtb_Sum_ps;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Sum_ps = 0.0F;
    } else {
        rtb_Sum_ps = (rtb_Max * rtb_Sum_jz[2]) + DW_tctest_Unit_Delay4_DSTATE_k3;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Sum_ps >= 100000.0F) {
        rtb_Switch2_c = 100000.0F;
    } else if (rtb_Sum_ps <= -100000.0F) {
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL'/MN'
                 */
        rtb_Switch2_c = -100000.0F;
    } else {
        rtb_Switch2_c = rtb_Sum_ps;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch2' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain11_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_o1 = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain11_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain11_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain11_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[0] = rtb_ip_lookup_fxpt_sfun_7_o1;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain21_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ml = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain21_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain21_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain21_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[1] = rtb_ip_lookup_fxpt_sfun_7_ml;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain31_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_oa = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain31_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain31_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain31_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[2] = rtb_ip_lookup_fxpt_sfun_7_oa;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain41_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain41_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain41_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain41_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[3] = rtb_ip_lookup_fxpt_sfun_7_e;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain12_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_et = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain12_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain12_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain12_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[4] = rtb_ip_lookup_fxpt_sfun_7_et;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain22_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_om = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain22_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain22_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain22_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[5] = rtb_ip_lookup_fxpt_sfun_7_om;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain32_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain32_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain32_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain32_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[6] = rtb_ip_lookup_fxpt_sfun_7_g;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain42_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_eq = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain42_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain42_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain42_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[7] = rtb_ip_lookup_fxpt_sfun_7_eq;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain13_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain13_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain13_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain13_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[8] = rtb_ip_lookup_fxpt_sfun_7_p;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain23_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_bq = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain23_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain23_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain23_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[9] = rtb_ip_lookup_fxpt_sfun_7_bq;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain33_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_gb = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain33_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain33_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain33_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[10] = rtb_ip_lookup_fxpt_sfun_7_gb;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain43_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), rtb_Switch, &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsLueGain43_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain43_nu/Functionality'/dtcrwv' incorporates:
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create Observer Feedback Matrix/Y_TCTEST_PlObsLueGain43_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_SystemMatrixA_m[11] = rtb_ip_lookup_fxpt_sfun_7_l;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum1/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay1'
         */
    rtb_Mul_j0[0] = rtb_Switch_a - DW_tctest_Unit_Delay1_DSTATE_l;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum5/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay6'
         */
    rtb_Mul_j0[1] = GET_S_LCFRCV_VehYawRate_rps() - DW_tctest_Unit_Delay6_DSTATE_i;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Sum1/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TPLFBT_CurDistY_met'
         *  Inport: '<Root>/S_TPLFBT_TrajDistY_met'
         */
    rtb_Sum_ps = GET_S_TPLFBT_TrajDistY_met() - GET_S_TPLFBT_CurDistY_met();
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum2/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay2'
         */
    rtb_Mul_j0[2] = rtb_Sum_ps - DW_tctest_Unit_Delay2_DSTATE_e;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtDisturbanceVectorHIn1' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant14'/Constant'
         */
    rtb_Mul_gu[0] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtDisturbanceVectorHIn2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant14'/Constant'
         */
    rtb_Mul_gu[1] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtDisturbanceVectorHIn3' */
    rtb_Mul_gu[2] = rtb_Switch;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant16'/Constant' */
    rtb_Mul_gu[3] = 0.0F;
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Lowpass for Curvature/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Constant3'/Constant'
         *  MinMax: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Lowpass for Curvature/Max/Functionality'/Max'
         */
    rtb_Div_ca = rtb_Max / f32_max_f32_f32(GET_P_TCTEST_PT1PlObsInCurvature_sec(), rtb_Max);
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Lowpass for Curvature'/Unit_Delay' */
    rtb_Unit_Delay_e = DW_tctest_Unit_Delay_DSTATE_e5;
    /* S-Function (sfun_mmv): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Lowpass for Curvature/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction = GET_S_TPLFBT_TrajTgtCrv_1pm();
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay_e, GET_S_TPLFBT_TrajTgtCrv_1pm(), rtb_Div_ca);
    }
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Constant2'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Constant8'/Constant'
         *  Inport: '<Root>/S_TCTFFC_Crv_1pm'
         *  Inport: '<Root>/S_TPLFBT_TrajTgtCrv_1pm'
         */
    switch (GET_P_TCTEST_IssPlObsCurvature_nu()) {
    case 1:
        rtb_Multiport_Switch = GET_S_TPLFBT_TrajTgtCrv_1pm();
        break;
    case 2:
        rtb_Multiport_Switch = rtb_SFunction;
        break;
    case 3:
        rtb_Multiport_Switch = GET_S_TCTFFC_Crv_1pm();
        break;
    default:
        rtb_Multiport_Switch = 0.0F;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature'/Multiport_Switch' */
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtInputVectorBIn1' */
    rtb_Unit_Delay_g0[0] = rtb_Mul_bh;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtInputVectorBIn2' */
    rtb_Unit_Delay_g0[1] = rtb_Div_e2;
    /* UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Neg4/Functionality'/Unary Minus' */
    rtb_Unit_Delay_g0[2] = -rtb_Mul_bh;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant17'/Constant' */
    rtb_Unit_Delay_g0[3] = 0.0F;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay' */
    rtb_Unit_Delay_mw = DW_tctest_Unit_Delay_DSTATE_a0;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay1' */
    rtb_Unit_Delay1_c = DW_tctest_Unit_Delay1_DSTATE_b;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay2' */
    rtb_Unit_Delay2_g = DW_tctest_Unit_Delay2_DSTATE_b;
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay3' */
    rtb_Unit_Delay3_o = DW_tctest_Unit_Delay3_DSTATE_mt;
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency/Constant1'/Constant'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay2'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay4'
         */
    switch (GET_P_TCTEST_DelayCyclesDeltaSs_nu()) {
    case 0:
        rtb_Div_f = rtb_Switch_o;
        break;
    case 1:
        rtb_Div_f = DW_tctest_Unit_Delay_DSTATE_a0;
        break;
    case 2:
        rtb_Div_f = DW_tctest_Unit_Delay1_DSTATE_b;
        break;
    case 3:
        rtb_Div_f = DW_tctest_Unit_Delay2_DSTATE_b;
        break;
    case 4:
        rtb_Div_f = DW_tctest_Unit_Delay3_DSTATE_mt;
        break;
    default:
        rtb_Div_f = DW_tctest_Unit_Delay4_DSTATE_d;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Multiport_Switch' */
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtFirstColumnOfAIn1' */
    rtb_SystemMatrixA_p[0] = rtb_Sum_ibd;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtFirstColumnOfAIn2' */
    rtb_SystemMatrixA_p[1] = rtb_Div_pl;
    /* UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Neg5/Functionality'/Unary Minus' */
    rtb_SystemMatrixA_p[2] = -rtb_Sum_ibd;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant5'/Constant' */
    rtb_SystemMatrixA_p[3] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtSecondColumnOfAIn1' */
    rtb_SystemMatrixA_p[4] = rtb_Div_e;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtSecondColumnOfAIn2' */
    rtb_SystemMatrixA_p[5] = rtb_Div;
    /* UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Neg6/Functionality'/Unary Minus' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant10'/Constant'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Sum1/Functionality'/Sum'
         */
    rtb_SystemMatrixA_p[6] = -(rtb_Div_e + 1.0F);
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant3'/Constant' */
    rtb_SystemMatrixA_p[7] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn1' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant11'/Constant'
         */
    rtb_SystemMatrixA_p[8] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant11'/Constant'
         */
    rtb_SystemMatrixA_p[9] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn3' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant11'/Constant'
         */
    rtb_SystemMatrixA_p[10] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn4' */
    rtb_SystemMatrixA_p[11] = rtb_Switch;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtFourthColumnOfAIn1' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant12'/Constant'
         */
    rtb_SystemMatrixA_p[12] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtFourthColumnOfAIn2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant12'/Constant'
         */
    rtb_SystemMatrixA_p[13] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtFourthColumnOfAIn3' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant12'/Constant'
         */
    rtb_SystemMatrixA_p[14] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements'/ConcatBufferAtFourthColumnOfAIn4' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Create State Space System Elements/Constant12'/Constant'
         */
    rtb_SystemMatrixA_p[15] = 0.0F;
    for (i = 0; i < 4; i++) {
        /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Product1/Functionality'/Mul' incorporates:
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum8/Functionality'/Sum'
                 */
        rtb_VectorConcatenate2[i] = 0.0F;
        for (i_0 = 0; i_0 < 3; i_0++) {
            rtb_VectorConcatenate2[i] += rtb_SystemMatrixA_m[(i_0 << 2) + i] * rtb_Mul_j0[i_0];
        }
        /* End of Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Product1/Functionality'/Mul' */
        /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum4/Functionality'/Sum' incorporates:
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Product2/Functionality'/Mul'
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Product4/Functionality'/Mul'
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum3/Functionality'/Sum'
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum8/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay'
                 */
        rtb_Switch6_np = 0.0F;
        for (i_0 = 0; i_0 < 4; i_0++) {
            rtb_Switch6_np += rtb_SystemMatrixA_p[(i_0 << 2) + i] * DW_tctest_Unit_Delay_DSTATE_c[i_0];
        }
        rtb_Mul_ka[i] = ((rtb_Unit_Delay_g0[i] * rtb_Div_f) + rtb_Switch6_np) + (rtb_Mul_gu[i] * rtb_Multiport_Switch);
        /* End of Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum4/Functionality'/Sum' */
        /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Sum8/Functionality'/Sum' */
        rtb_Sum_jw[i] = rtb_VectorConcatenate2[i] + rtb_Mul_ka[i];
    }
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/LOWPASST_RE3/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant12'/Constant'
         *  MinMax: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Max/Functionality'/Max'
         */
    rtb_Div_cr = rtb_Max / f32_max_f32_f32(GET_P_TCTEST_HdrDThetaDotPT1Time_sec(), rtb_Max);
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests'/Unit_Delay4' */
    rtb_Unit_Delay4_a = DW_tctest_Unit_Delay4_DSTATE_b;
    /* S-Function (sfun_mmv): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/LOWPASST_RE3/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_k = 0.0F;
    } else {
        rtb_SFunction_k = f32_mmv_f32_f32_f32( rtb_Unit_Delay4_a, rtb_Sum_jw[2], rtb_Div_cr);
    }
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/LOWPASST_RE1/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant10'/Constant'
         *  MinMax: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Max1/Functionality'/Max'
         */
    rtb_Div_j = rtb_Max / f32_max_f32_f32(GET_P_TCTEST_HdrDYDotPT1Time_sec(), rtb_Max);
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests'/Unit_Delay1' */
    rtb_Unit_Delay1_p = DW_tctest_Unit_Delay1_DSTATE_a;
    /* S-Function (sfun_mmv): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/LOWPASST_RE1/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_g = 0.0F;
    } else {
        rtb_SFunction_g = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_p, rtb_Sum_jw[3], rtb_Div_j);
    }
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Switch5/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Constant15'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Constant8'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/from_data_definition'/state_source'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/from_data_definition1'/state_source'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_MCTLFC_ControllingFunction_nu'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/AND1/Functionality'/AND'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/NOT2/Functionality'/NOT'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/EQ2/Functionality'/EQ'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Switch6/Functionality'/Switch'
         */
    if ((!(((sint32)((uint8)E_LCF_FunctionV3Type_E_LCF_OFF_nu)) == ((sint32) GET_S_MCTLFC_ControllingFunction_nu()))) && (!(((sint32) GET_S_MCTLFC_ControllingFunction_nu()) == ((sint32)((uint8) E_LCF_FunctionV3Type_E_LCF_TJA_nu))))) {
        rtb_Switch_m = 3U;
    } else if (((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) {
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Switch6/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Constant9'/Constant'
                 */
        rtb_Switch_m = 2U;
    } else {
        rtb_Switch_m = 1U;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Determine Active Param Set/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant5'/Constant'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/AND/Functionality'/AND'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/NOT/Functionality'/NOT'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Switch/Functionality'/Switch'
         */
    if ((((sint32)rtb_NE) != 0) && (!(((sint32)rtb_EQ) != 0))) {
        /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Sum/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant11'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant7'/Constant'
                 */
        rtb_Div_f = GET_P_TCTEST_HdrDThetaDotEnd_rps() - GET_P_TCTEST_HdrDThetaDotStart_rps();
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division/Switch/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division/Abs/Functionality'/Abs'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division/Constant3'/Constant'
                 *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division/GT/Functionality'/GT'
                 */
        if (!(f32_abs_f32(rtb_Div_f) > GET_P_LCF_AlmostZero_nu())) {
            rtb_Div_f = GET_P_LCF_AlmostZero_nu();
        }
        /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division/Switch/Functionality'/Switch' */
        /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Mul/Functionality'/Mul' incorporates:
                 *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Abs3/Functionality'/Abs'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant6'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant7'/Constant'
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division/Div1/Functionality/Div'/Div'
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Sum6/Functionality'/Sum'
                 */
        rtb_Div_f = (100.0F / rtb_Div_f) * (f32_abs_f32(rtb_SFunction_k) - GET_P_TCTEST_HdrDThetaDotStart_rps());
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit'/MX'
                 *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit/Functionality'/Relational Operator'
                 */
        if (100.0F >= rtb_Div_f) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit'/MN'
                         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit/Functionality'/Relational Operator1'
                         */
            if (0.0F <= rtb_Div_f) {
                rtb_Switch_jd = rtb_Div_f;
            } else {
                rtb_Switch_jd = 0.0F;
            }
            /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit/Functionality'/Switch1' */
        } else {
            rtb_Switch_jd = 100.0F;
        }
        /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit/Functionality'/Switch' */
        /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Sum1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant13'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant14'/Constant'
                 */
        rtb_Div_f = GET_P_TCTEST_HdrDYDotEnd_mps() - GET_P_TCTEST_HdrDYDotStart_mps();
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division1/Switch/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division1/Abs/Functionality'/Abs'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division1/Constant3'/Constant'
                 *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division1/GT/Functionality'/GT'
                 */
        if (!(f32_abs_f32(rtb_Div_f) > GET_P_LCF_AlmostZero_nu())) {
            rtb_Div_f = GET_P_LCF_AlmostZero_nu();
        }
        /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division1/Switch/Functionality'/Switch' */
        /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Mul1/Functionality'/Mul' incorporates:
                 *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Abs4/Functionality'/Abs'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant13'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant3'/Constant'
                 *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division1/Div1/Functionality/Div'/Div'
                 *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Sum2/Functionality'/Sum'
                 */
        rtb_Div_f = (100.0F / rtb_Div_f) * (f32_abs_f32(rtb_SFunction_g) - GET_P_TCTEST_HdrDYDotStart_mps());
        /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1'/MX'
                 *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1/Functionality'/Relational Operator'
                 */
        if (100.0F >= rtb_Div_f) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1'/MN'
                         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1/Functionality'/Relational Operator1'
                         */
            if (0.0F <= rtb_Div_f) {
                rtb_Switch_b = rtb_Div_f;
            } else {
                rtb_Switch_b = 0.0F;
            }
            /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1/Functionality'/Switch1' */
        } else {
            rtb_Switch_b = 100.0F;
        }
        /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Limit1/Functionality'/Switch' */
    } else {
        rtb_Switch_jd = 0.0F;
        rtb_Switch_b = 0.0F;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division2/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division2/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Constant4'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division2/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division2/GT/Functionality'/GT'
         */
    if (100.0F > GET_P_LCF_AlmostZero_nu()) {
        rtb_Switch6_np = 100.0F;
    } else {
        rtb_Switch6_np = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division2/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division2/Div1/Functionality/Div'/Div' incorporates:
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Mul2/Functionality'/Mul'
         */
    rtb_Div_f = (rtb_Switch_jd * rtb_Switch_b) / rtb_Switch6_np;
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch4' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant16'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant17'/Constant'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant18'/Constant'
         */
    switch (rtb_Switch_m) {
    case 1:
        rtb_Switch_kf = GET_P_TCTEST_HdrMeanDYWght_nu();
        /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch3' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant16'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant8'/Constant'
                 */
        rtb_Switch_j = GET_P_TCTEST_HdrMeanDThetaWght_nu();
        break;
    case 2:
        rtb_Switch_kf = GET_P_TCTEST_HdrMeanDYWghtOf_nu();
        /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch3' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant17'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant9'/Constant'
                 */
        rtb_Switch_j = GET_P_TCTEST_HdrMeanDThetaWghtOf_nu();
        break;
    default:
        rtb_Switch_kf = GET_P_TCTEST_HdrMeanDYWghtSf_nu();
        /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch3' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant15'/Constant'
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Constant18'/Constant'
                 */
        rtb_Switch_j = GET_P_TCTEST_HdrMeanDThetaWghtSf_nu();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch4' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Sum4/Functionality'/Sum' */
    rtb_Div_p = rtb_Switch_kf + rtb_Switch_j;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division3/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division3/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division3/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division3/GT/Functionality'/GT'
         */
    if (!(f32_abs_f32(rtb_Div_p) > GET_P_LCF_AlmostZero_nu())) {
        rtb_Div_p = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division3/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Division3/Div1/Functionality/Div'/Div' incorporates:
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Mul3/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Mul4/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Sum3/Functionality'/Sum'
         */
    rtb_Div_p = ((rtb_Switch_jd * rtb_Switch_j) + (rtb_Switch_b * rtb_Switch_kf)) / rtb_Div_p;
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMeanThreshOf_perc/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMeanThreshSf_perc/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMeanThresh_perc/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m) {
    case 1:
        /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMeanThresh_perc/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_TCTEST_HdrMeanThresh_perc(), &dps_result_ln);
    }
    rtb_Switch_jd = rtb_ip_lookup_fxpt_sfun_7_i;
    break;
    case 2:
        /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMeanThreshOf_perc/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_ij = F32_PTR_IP1D (GETA_Y_TCTEST_HdrMeanThreshOf_perc(), &dps_result_ln);
    }
    rtb_Switch_jd = rtb_ip_lookup_fxpt_sfun_7_ij;
    break;
    default:
        /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMeanThreshSf_perc/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D (GETA_Y_TCTEST_HdrMeanThreshSf_perc(), &dps_result_ln);
    }
    rtb_Switch_jd = rtb_ip_lookup_fxpt_sfun_7_d;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch1' */
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/GE/Functionality'/GE' */
    rtb_GE_p = (uint8)(rtb_Div_p >= rtb_Switch_jd);
    /* MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch2' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMulThreshOf_perc/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMulThreshSf_perc/Functionality'/ip_lookup_fxpt_sfun_7'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMulThresh_perc/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    switch (rtb_Switch_m) {
    case 1:
        /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMulThresh_perc/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k3 = F32_PTR_IP1D (GETA_Y_TCTEST_HdrMulThresh_perc(), &dps_result_ln);
    }
    rtb_Switch_jd = rtb_ip_lookup_fxpt_sfun_7_k3;
    break;
    case 2:
        /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMulThreshOf_perc/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_TCTEST_HdrMulThreshOf_perc(), &dps_result_ln);
    }
    rtb_Switch_jd = rtb_ip_lookup_fxpt_sfun_7_j;
    break;
    default:
        /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters/Y_TCTEST_HdrMulThreshSf_perc/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k4 = F32_PTR_IP1D (GETA_Y_TCTEST_HdrMulThreshSf_perc(), &dps_result_ln);
    }
    rtb_Switch_jd = rtb_ip_lookup_fxpt_sfun_7_k4;
    break;
    }
    /* End of MultiPortSwitch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/Select HDR Parameters'/Multiport Switch2' */
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests/GE1/Functionality'/GE' */
    rtb_Switch_m = (uint8)(rtb_Div_f >= rtb_Switch_jd);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_jd = 0.0F;
    } else {
        rtb_Switch_jd = (rtb_Max * rtb_Sum_jw[2]) + DW_tctest_Unit_Delay4_DSTATE_f;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch_jd >= 3.1415F) {
        rtb_Switch_jd = 3.1415F;
    } else {
        if (rtb_Switch_jd <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch_jd = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3/INTEGRATORK_REL/Functionality'/Switch2' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Y_TCTEST_PlObsDeltaThetaSat_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_n = F32_PTR_IP1D (GETA_Y_TCTEST_PlObsDeltaThetaSat_rad(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Y_TCTEST_PlObsDeltaThetaSat_rad/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Y_TCTEST_PlObsDeltaThetaSat_rad/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_b = rtb_ip_lookup_fxpt_sfun_7_n;
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Relational Operator1' incorporates:
         *  UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Neg/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1 = (uint8)((-rtb_Switch_b) <= rtb_Switch_jd);
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Relational Operator' */
    rtb_RelationalOperator = (uint8)(rtb_Switch_b >= rtb_Switch_jd);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze1/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze1'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_b = DW_tctest_UnitDelay2_DSTATE;
    } else {
        if (((sint32)rtb_RelationalOperator) != 0) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Switch1' incorporates:
                         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Switch'
                         *  UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Neg/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1) != 0) {
                rtb_Switch_b = rtb_Switch_jd;
            } else {
                rtb_Switch_b = -rtb_Switch_b;
            }
            /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Switch1' */
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze1/Switch2/Functionality'/Switch' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Y_TCTEST_SObsBetaSat_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_InputVehVelSat_met */
        FDPS_PTR_F32(GETA_X_TCTEST_InputVehVelSat_met(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_k = F32_PTR_IP1D(GETA_Y_TCTEST_SObsBetaSat_rad(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Y_TCTEST_SObsBetaSat_rad/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Y_TCTEST_SObsBetaSat_rad/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_j = rtb_ip_lookup_fxpt_sfun_7_k;
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Relational Operator1' incorporates:
         *  UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Neg/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_l = (uint8)((-rtb_Switch_j) <= rtb_Switch_a);
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Relational Operator' */
    rtb_RelationalOperator_n = (uint8)(rtb_Switch_j >= rtb_Switch_a);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze2/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze2'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_j = DW_tctest_UnitDelay2_DSTATE_h;
    } else {
        if (((sint32)rtb_RelationalOperator_n) != 0) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Switch1' incorporates:
                         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Switch'
                         *  UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Neg/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_l) != 0) {
                rtb_Switch_j = rtb_Switch_a;
            } else {
                rtb_Switch_j = -rtb_Switch_j;
            }
            /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Switch1' */
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze2/Switch2/Functionality'/Switch' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create Observer Feedback Matrix1/Y_TCTEST_KObsLueGain11_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Switch_kf = F32_PTR_IP1D(GETA_Y_TCTEST_KObsLueGain11_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create Observer Feedback Matrix1/Y_TCTEST_KObsLueGain11_nu/Functionality'/dtcrwv' */
    rtb_Unit_Delay_bm[0] = rtb_Switch_kf;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create Observer Feedback Matrix1/Y_TCTEST_KObsLueGain21_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Switch_kf = F32_PTR_IP1D(GETA_Y_TCTEST_KObsLueGain21_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create Observer Feedback Matrix1/Y_TCTEST_KObsLueGain21_nu/Functionality'/dtcrwv' */
    rtb_Unit_Delay_bm[1] = rtb_Switch_kf;
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create Observer Feedback Matrix1/Y_TCTEST_KObsLueGain31_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_Switch_kf = F32_PTR_IP1D(GETA_Y_TCTEST_KObsLueGain31_nu(), &dps_result_ln);
    }
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create Observer Feedback Matrix1/Y_TCTEST_KObsLueGain31_nu/Functionality'/dtcrwv' */
    rtb_Unit_Delay_bm[2] = rtb_Switch_kf;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch_a = 0.0F;
    } else {
        rtb_Switch_a = (rtb_Max * rtb_Sum_jw[3]) + DW_tctest_Unit_Delay4_DSTATE_m;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch_a >= 10.0F) {
        rtb_Switch_a = 10.0F;
    } else {
        if (rtb_Switch_a <= -10.0F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch_a = -10.0F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Sum5/Functionality'/Sum' incorporates:
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1'/Unit_Delay6'
         */
    rtb_Switch_kf = rtb_Switch_a - DW_tctest_Unit_Delay6_DSTATE_hj;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Constant2'/Constant' */
    rtb_SecondColumnOfA[0] = 0.0F;
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch6_b = 0.0F;
    } else {
        rtb_Switch6_b = (rtb_Max * rtb_Sum_jw[1]) + DW_tctest_Unit_Delay4_DSTATE_n;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_b >= 3.1415F) {
        rtb_Switch6_b = 3.1415F;
    } else {
        if (rtb_Switch6_b <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_b = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Sum2/Functionality'/Sum' */
    rtb_SecondColumnOfA[1] = rtb_Switch6_b + rtb_Sum_jw[0];
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Constant1'/Constant' */
    rtb_SecondColumnOfA[2] = 0.0F;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant5'/Constant' */
    rtb_SystemMatrixA_l[0] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements'/ConcatBufferAtFirstColumnOfAIn2' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_SystemMatrixA_l[1] = GET_S_LCFRCV_VehVelX_mps();
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant1'/Constant' */
    rtb_SystemMatrixA_l[2] = 0.0F;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant2'/Constant' */
    rtb_SystemMatrixA_l[3] = 0.0F;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant3'/Constant' */
    rtb_SystemMatrixA_l[4] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements'/ConcatBufferAtSecondColumnOfAIn3' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_SystemMatrixA_l[5] = GET_S_LCFRCV_VehVelX_mps();
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn1' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant4'/Constant'
         */
    rtb_SystemMatrixA_l[6] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant4'/Constant'
         */
    rtb_SystemMatrixA_l[7] = 0.0F;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements'/ConcatBufferAtThirdColumnOfAIn3' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Create State Space System Elements/Constant4'/Constant'
         */
    rtb_SystemMatrixA_l[8] = 0.0F;
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Sum8/Functionality'/Sum' incorporates:
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Product1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Sum1/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1'/Unit_Delay'
         */
    for (i = 0; i < 3; i++) {
        rtb_Switch6_np = 0.0F;
        for (i_0 = 0; i_0 < 3; i_0++) {
            rtb_Switch6_np += rtb_SystemMatrixA_l[(3 * i_0) + i] * DW_tctest_Unit_Delay_DSTATE_h[i_0];
        }
        rtb_Unit_Delay_eq[i] = (rtb_Unit_Delay_bm[i] * rtb_Switch_kf) + (rtb_Switch6_np - rtb_SecondColumnOfA[i]);
    }
    /* End of Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Sum8/Functionality'/Sum' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch6_np = 0.0F;
    } else {
        rtb_Switch6_np = (rtb_Max * rtb_Unit_Delay_eq[0]) + DW_tctest_Unit_Delay4_DSTATE_ex;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_np >= 1.0F) {
        rtb_Switch6_np = 1.0F;
    } else {
        if (rtb_Switch6_np <= -1.0F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_np = -1.0F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze3/Switch2/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze3'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_c0 = DW_tctest_UnitDelay2_DSTATE_b;
    } else {
        rtb_Switch_c0 = rtb_Switch6_np;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze3/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output3/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output3/Constant6'/Constant'
         */
    if (((sint32)rtb_NE) != 0) {
        rtb_Switch_kf = rtb_Switch_c0;
    } else {
        rtb_Switch_kf = 0.0F;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output3/Switch4/Functionality'/Switch' */
    /* Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Lowpass/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Constant4'/Constant'
         *  MinMax: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Lowpass/Max/Functionality'/Max'
         */
    rtb_Div_aa = rtb_Max / f32_max_f32_f32(GET_P_TCTEST_PT1CrObsCrosswind_sec(), rtb_Max);
    /* UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Lowpass'/Unit_Delay' */
    rtb_Unit_Delay_g = DW_tctest_Unit_Delay_DSTATE_p;
    /* S-Function (sfun_mmv): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Lowpass/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion != 0U) {
        rtb_SFunction_e = rtb_Switch2_c;
    } else {
        rtb_SFunction_e = f32_mmv_f32_f32_f32( rtb_Unit_Delay_g, rtb_Switch2_c, rtb_Div_aa);
    }
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze4/Switch2/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze4'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_k = DW_tctest_UnitDelay2_DSTATE_d;
    } else {
        rtb_Switch_k = rtb_SFunction_e;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze4/Switch2/Functionality'/Switch' */
    /* S-Function Block sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Y_TCTEST_PlObsDeltaYSat_m/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTEST_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTEST_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_bb = F32_PTR_IP1D(GETA_Y_TCTEST_PlObsDeltaYSat_m(), &dps_result_ln);
    }
    /* Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Y_TCTEST_PlObsDeltaYSat_m/Functionality/odtc'/Sum' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Y_TCTEST_PlObsDeltaYSat_m/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Sum_kj = rtb_ip_lookup_fxpt_sfun_7_bb;
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Relational Operator1' incorporates:
         *  UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Neg/Functionality'/Unary Minus'
         */
    rtb_RelationalOperator1_my = (uint8)((-rtb_Sum_kj) <= rtb_Switch_a);
    /* RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Relational Operator' */
    rtb_RelationalOperator_m = (uint8)(rtb_Sum_kj >= rtb_Switch_a);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze5/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze5'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Sum_kj = DW_tctest_UnitDelay2_DSTATE_m;
    } else {
        if (((sint32)rtb_RelationalOperator_m) != 0) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Switch1' incorporates:
                         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Switch'
                         *  UnaryMinus: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Neg/Functionality'/Unary Minus'
                         */
            if (((sint32)rtb_RelationalOperator1_my) != 0) {
                rtb_Sum_kj = rtb_Switch_a;
            } else {
                rtb_Sum_kj = -rtb_Sum_kj;
            }
            /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Switch1' */
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze5/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL'/IV'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Switch6'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1'/Unit_Delay4'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch6_jp = 0.0F;
        rtb_Switch6_c = 0.0F;
    } else {
        rtb_Switch6_jp = (rtb_Max * rtb_Unit_Delay_eq[1]) + DW_tctest_Unit_Delay4_DSTATE_o;
        rtb_Switch6_c = (rtb_Max * rtb_Unit_Delay_eq[2]) + DW_tctest_Unit_Delay4_DSTATE_og;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_jp >= 3.1415F) {
        rtb_Switch6_jp = 3.1415F;
    } else {
        if (rtb_Switch6_jp <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_jp = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_c >= 5.0F) {
        rtb_Switch6_c = 5.0F;
    } else {
        if (rtb_Switch6_c <= -5.0F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_c = -5.0F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Switch6_oi = 0.0F;
    } else {
        rtb_Switch6_oi = (rtb_Max * rtb_Sum_jw[0]) + DW_tctest_Unit_Delay4_DSTATE_g;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Switch6_oi >= 3.1415F) {
        rtb_Switch6_oi = 3.1415F;
    } else {
        if (rtb_Switch6_oi <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL'/MN'
                         */
            rtb_Switch6_oi = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1/INTEGRATORK_REL/Functionality'/Switch2' */
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/And'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Not1'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/Limit/Functionality'/Not2'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Course Angle Deviation/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate[9] = (uint8)(((((sint32)rtb_RelationalOperator) != 0) && (!(((sint32)rtb_RelationalOperator1) != 0))) || (!(((sint32) rtb_RelationalOperator) != 0)));
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/And'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Not1'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/Limit/Functionality'/Not2'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Lateral Deviation/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate[11] = (uint8)(((((sint32)rtb_RelationalOperator_m) != 0) && (!(((sint32)rtb_RelationalOperator1_my) != 0))) || (!(((sint32) rtb_RelationalOperator_m) != 0)));
    /* DataTypeConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/And'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Not1'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/Limit/Functionality'/Not2'
         *  Logic: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Saturation of Side Slip Angle/OR/Functionality'/OR'
         */
    rtb_VectorConcatenate[3] = (uint8)(((((sint32)rtb_RelationalOperator_n) != 0) && (!(((sint32)rtb_RelationalOperator1_l) != 0))) || (!(((sint32) rtb_RelationalOperator_n) != 0)));
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2'/Unit_Delay4'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        rtb_Max = 0.0F;
    } else {
        rtb_Max = (rtb_Max * rtb_Sum_ayv[1]) + DW_tctest_Unit_Delay4_DSTATE_jr;
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Max >= 3.1415F) {
        rtb_Max = 3.1415F;
    } else {
        if (rtb_Max <= -3.1415F) {
            /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL'/MN'
                         */
            rtb_Max = -3.1415F;
        }
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2/INTEGRATORK_REL/Functionality'/Switch2' */
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_NE;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn13' */
    rtb_VectorConcatenate[12] = rtb_Switch_m;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn14' */
    rtb_VectorConcatenate[13] = rtb_GE_p;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_EQ;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_DataTypeConversion;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn5' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/Constant1'/Constant'
         */
    rtb_VectorConcatenate[4] = 0U;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn6' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/Constant1'/Constant'
         */
    rtb_VectorConcatenate[5] = 0U;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn7' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/Constant1'/Constant'
         */
    rtb_VectorConcatenate[6] = 0U;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn8' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/Constant1'/Constant'
         */
    rtb_VectorConcatenate[7] = 0U;
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier'/ConcatBufferAtVector ConcatenateIn9' incorporates:
         *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/Constant1'/Constant'
         */
    rtb_VectorConcatenate[8] = 0U;
    /* Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/Constant2'/Constant' */
    rtb_VectorConcatenate[10] = 0U;
    /* S-Function (sfun_setbit): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/TCTEST Qualifier/set_bit/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint32 temp = 0U;
        {
            uint32 set_mask = 0;
            uint32 reset_mask = 0;
            const uint8 selection_vec[14] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate[0];
                for (i1=0; i1 < 14; i1++) {
                    if (!u1[i1]) {
                        /* reset */
                        reset_mask = reset_mask | u32_bit_u8( selection_vec [i1]);
                    } else {
                        /* set */
                        set_mask = set_mask | u32_bit_u8( selection_vec [i1]);
                    }
                }
            }
            temp = (temp & ~reset_mask) | set_mask ;
        }
        rtb_sfun_setbit = temp;
    }
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch1'/copy1' */
    SET_S_TCTEST_QualifierService_nu(rtb_sfun_setbit);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output2/Switch4/Functionality'/Switch' incorporates:
                                                         *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output4/Switch4/Functionality'/Switch'
                                                         */
    if (((sint32)rtb_NE) != 0) {
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch10'/copy1' */
        SET_S_TCTEST_SObsBeta_rad(rtb_Switch_j);
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch27'/copy1' */
        SET_S_TCTEST_CrObsCrosswind_New(rtb_Switch_k);
    } else {
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch10'/copy1' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output2/Constant6'/Constant'
                 */
        SET_S_TCTEST_SObsBeta_rad(0.0F);
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch27'/copy1' incorporates:
                                                *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output4/Constant6'/Constant'
                                                */
        SET_S_TCTEST_CrObsCrosswind_New(0.0F);
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output2/Switch4/Functionality'/Switch' */
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch11'/copy1' */
    SET_S_TCTEST_MccA11_nu(rtb_Sum_ibd);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch12'/copy1' */
    SET_S_TCTEST_MccA12_nu(rtb_Div_e);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch13'/copy1' */
    SET_D_TCTEST_PlObsDeltaTheta_rad(rtb_Switch_jd);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch14'/copy1' */
    SET_S_TCTEST_MccA21_nu(rtb_Div_pl);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch15'/copy1' */
    SET_S_TCTEST_MccA22_nu(rtb_Div);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch16'/copy1' */
    SET_D_TCTEST_PlObsDeltaY_met(rtb_Switch_a);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch17'/copy1' */
    SET_S_TCTEST_MccB11_nu(rtb_Mul_bh);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch18'/copy1' */
    SET_S_TCTEST_CurSteerAngle_rad(rtb_Switch_o);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch19'/copy1' */
    SET_S_TCTEST_MccB21_nu(rtb_Div_e2);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch2'/copy1' */
    SET_D_TCTEST_SObsBeta_rad(rtb_Sum_lt);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch20'/copy1' */
    SET_S_TCTEST_MccH11Cw_nu(rtb_Sum_nm);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch21'/copy1' */
    SET_D_TCTEST_HdrMul_perc(rtb_Div_f);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch22'/copy1' */
    SET_D_TCTEST_HdrMul_bool(rtb_Switch_m);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch23'/copy1' */
    SET_D_TCTEST_HdrMean_perc(rtb_Div_p);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch24'/copy1' */
    SET_D_TCTEST_HdrMean_bool(rtb_GE_p);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch25'/copy1' */
    SET_D_TCTEST_KObsKappa_1pm(rtb_Switch6_np);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch26'/copy1' */
    SET_S_TCTEST_KObsKappa_1pm(rtb_Switch_kf);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch28'/copy1' */
    SET_S_TCTEST_MccH21Cw_nu(rtb_Div_hq);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch29'/copy1' */
    SET_D_TCTEST_CrObsCrosswindRaw_New(rtb_Switch2_c);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch3'/copy1' */
    SET_D_TCTEST_SteerAngleVDY_rad(rtb_Div_iz);
    /* Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output5/Switch4/Functionality'/Switch' incorporates:
                                                  *  Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output1/Switch4/Functionality'/Switch'
                                                  */
    if (((sint32)rtb_NE) != 0) {
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch4'/copy1' */
        SET_S_TCTEST_PlObsDeltaY_met(rtb_Sum_kj);
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch5'/copy1' */
        SET_S_TCTEST_PlObsDeltaTheta_rad(rtb_Switch_b);
    } else {
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch4'/copy1' incorporates:
                 *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output5/Constant6'/Constant'
                 */
        SET_S_TCTEST_PlObsDeltaY_met(0.0F);
        /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch5'/copy1' incorporates:
                                                *  Constant: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output1/Constant6'/Constant'
                                                */
        SET_S_TCTEST_PlObsDeltaTheta_rad(0.0F);
    }
    /* End of Switch: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Enable Output5/Switch4/Functionality'/Switch' */
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch6'/copy1' */
    SET_D_TCTEST_SteerAngleLaDMC_rad(rtb_Mul_od);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch7'/copy1' */
    SET_D_TCTEST_SObsPsiDot_rps(rtb_Max);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch8'/copy1' */
    SET_D_TCTEST_InPlObsDeltaY_met(rtb_Sum_ps);
    /* SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/branch9'/copy1' */
    SET_D_TCTEST_InPlObsCurvature_1pm(rtb_Multiport_Switch);
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x1'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE = rtb_Switch6_it;
    /* S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctest_Unit_Delay_DSTATE_ei = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Determine Reset/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x1'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE = rtb_Sum_lt;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/Unit_Delay6' */
    DW_tctest_Unit_Delay6_DSTATE = rtb_Max;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_n = rtb_Switch_o;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay1' */
    DW_tctest_Unit_Delay1_DSTATE = rtb_Unit_Delay_d;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay2' */
    DW_tctest_Unit_Delay2_DSTATE = rtb_Unit_Delay1;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay3' */
    DW_tctest_Unit_Delay3_DSTATE = rtb_Unit_Delay2;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Select Latency'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_k = rtb_Unit_Delay3;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_a[0] = rtb_Sum_lt;
    DW_tctest_Unit_Delay_DSTATE_a[1] = rtb_Max;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer'/Unit_Delay1' */
    DW_tctest_Unit_Delay1_DSTATE_j = rtb_Switch6_it;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer'/Unit_Delay6' */
    DW_tctest_Unit_Delay6_DSTATE_h = rtb_Switch2_e;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_e = rtb_Switch_o;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay1' */
    DW_tctest_Unit_Delay1_DSTATE_e = rtb_Unit_Delay_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay2' */
    DW_tctest_Unit_Delay2_DSTATE_i = rtb_Unit_Delay1_i;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay3' */
    DW_tctest_Unit_Delay3_DSTATE_m = rtb_Unit_Delay2_d;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Select Latency'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_j = rtb_Unit_Delay3_g;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_nf[0] = rtb_Switch6_it;
    DW_tctest_Unit_Delay_DSTATE_nf[1] = rtb_Switch2_e;
    DW_tctest_Unit_Delay_DSTATE_nf[2] = rtb_Switch2_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x2'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_e = rtb_Switch2_e;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Crosswind Observer/Integrator x3'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_k3 = rtb_Switch2_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay1' */
    DW_tctest_Unit_Delay1_DSTATE_l = rtb_Switch6_oi;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay6' */
    DW_tctest_Unit_Delay6_DSTATE_i = rtb_Switch6_b;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay2' */
    DW_tctest_Unit_Delay2_DSTATE_e = rtb_Switch_a;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Input Source Select for Curvature/Lowpass for Curvature'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_e5 = rtb_SFunction;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_a0 = rtb_Switch_o;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay1' */
    DW_tctest_Unit_Delay1_DSTATE_b = rtb_Unit_Delay_mw;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay2' */
    DW_tctest_Unit_Delay2_DSTATE_b = rtb_Unit_Delay1_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay3' */
    DW_tctest_Unit_Delay3_DSTATE_mt = rtb_Unit_Delay2_g;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Select Latency'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_d = rtb_Unit_Delay3_o;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_c[0] = rtb_Switch6_oi;
    DW_tctest_Unit_Delay_DSTATE_c[1] = rtb_Switch6_b;
    DW_tctest_Unit_Delay_DSTATE_c[2] = rtb_Switch_jd;
    DW_tctest_Unit_Delay_DSTATE_c[3] = rtb_Switch_a;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_b = rtb_SFunction_k;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Detection of high dynamic requests'/Unit_Delay1' */
    DW_tctest_Unit_Delay1_DSTATE_a = rtb_SFunction_g;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze1'/Unit Delay2' */
    DW_tctest_UnitDelay2_DSTATE = rtb_Switch_b;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x3'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_f = rtb_Switch_jd;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze2'/Unit Delay2' */
    DW_tctest_UnitDelay2_DSTATE_h = rtb_Switch_j;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze3'/Unit Delay2' */
    DW_tctest_UnitDelay2_DSTATE_b = rtb_Switch_c0;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x3'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_ex = rtb_Switch6_np;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x4'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_m = rtb_Switch_a;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1'/Unit_Delay6' */
    DW_tctest_Unit_Delay6_DSTATE_hj = rtb_Switch6_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x2'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_n = rtb_Switch6_b;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_h[0] = rtb_Switch6_np;
    DW_tctest_Unit_Delay_DSTATE_h[1] = rtb_Switch6_jp;
    DW_tctest_Unit_Delay_DSTATE_h[2] = rtb_Switch6_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze4'/Unit Delay2' */
    DW_tctest_UnitDelay2_DSTATE_d = rtb_Switch_k;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Lowpass'/Unit_Delay' */
    DW_tctest_Unit_Delay_DSTATE_p = rtb_SFunction_e;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Freeze5'/Unit Delay2' */
    DW_tctest_UnitDelay2_DSTATE_m = rtb_Sum_kj;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x1'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_o = rtb_Switch6_jp;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/KObs V1/Integrator x2'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_og = rtb_Switch6_c;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Plant Observer/Integrator x1'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_g = rtb_Switch6_oi;
    /* Update for UnitDelay: 'sda:TCTEST/TCTEST/TCTEST_VehProcess/M_TCTEST/Side Slip Angle Observer/Integrator x2'/Unit_Delay4' */
    DW_tctest_Unit_Delay4_DSTATE_jr = rtb_Max;
}
#include "Pse_TCTEST.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
