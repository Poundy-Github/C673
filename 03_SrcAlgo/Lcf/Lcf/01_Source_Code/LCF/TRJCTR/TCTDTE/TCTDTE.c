/**************************************************************************
COPYRIGHT (C) $Date: 2019/06/07 12:53:07CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJCTR/TCTDTE_VEH/TCTDTE/i/project.pj $
$Log: TCTDTE.c  $
Revision 1.2.1.2 2019/06/07 12:53:07CEST Schrader, Moritz (uia92406) (uia92406) 
automatically created
File          : TCTDTE
Generated on  : Fri 07.06.2019 at 12:37:25 (UTC+01:00)
MD5           : [4242246007  1064729596  4072982354  3785138561 0](TCTDTE)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TCTDTE.h"
#include "TCTDTE_private.h"
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
#define TCTDTE_START_SEC_DATA_8
#include "TCTDTE_MemMap.h"
static uint8 DW_tctdte_Unit_Delay_DSTATE_mt;
#define TCTDTE_STOP_SEC_DATA_8
#include "TCTDTE_MemMap.h"
#define TCTDTE_START_SEC_DATA_32
#include "TCTDTE_MemMap.h"
static float32 DW_tctdte_Unit_Delay_DSTATE;
static float32 DW_tctdte_Unit_Delay_DSTATE_l;
static float32 DW_tctdte_Unit_Delay3_DSTATE;
static float32 DW_tctdte_Unit_Delay3_DSTATE_k;
static float32 DW_tctdte_Unit_Delay3_DSTATE_i;
static float32 DW_tctdte_Unit_Delay3_DSTATE_p;
static float32 DW_tctdte_Unit_Delay_DSTATE_j;
static float32 DW_tctdte_Unit_Delay1_DSTATE;
static float32 DW_tctdte_Unit_Delay2_DSTATE;
static float32 DW_tctdte_Unit_Delay3_DSTATE_o;
static float32 DW_tctdte_Unit_Delay4_DSTATE;
static float32 DW_tctdte_Unit_Delay_DSTATE_h;
static float32 DW_tctdte_Unit_Delay_DSTATE_m;
static float32 DW_tctdte_Unit_Delay1_DSTATE_d;
static float32 DW_tctdte_Unit_Delay2_DSTATE_p;
static float32 DW_tctdte_Unit_Delay3_DSTATE_d;
static float32 DW_tctdte_Unit_Delay3_DSTATE_n;
static float32 DW_tctdte_Unit_Delay3_DSTATE_e;
static float32 DW_tctdte_Unit_Delay_DSTATE_lo;
static float32 DW_tctdte_Unit_Delay3_DSTATE_j;
static float32 DW_tctdte_Unit_Delay3_DSTATE_jz;
static float32 DW_tctdte_Unit_Delay3_DSTATE_i0;
static float32 DW_tctdte_Unit_Delay5_DSTATE;
static float32 DW_tctdte_Unit_Delay1_DSTATE_m;
static float32 DW_tctdte_Unit_Delay_DSTATE_he;
static float32 DW_tctdte_Unit_Delay2_DSTATE_g;
static float32 DW_tctdte_Unit_Delay3_DSTATE_c;
static float32 DW_tctdte_Unit_Delay3_DSTATE_o2;
static float32 DW_tctdte_Unit_Delay5_DSTATE_e;
static float32 DW_tctdte_Unit_Delay1_DSTATE_o;
static float32 DW_tctdte_Unit_Delay_DSTATE_d;
static float32 DW_tctdte_Unit_Delay_DSTATE_m0;
static float32 DW_tctdte_Unit_Delay1_DSTATE_h;
static float32 DW_tctdte_Unit_Delay2_DSTATE_e;
static float32 DW_tctdte_Unit_Delay3_DSTATE_g;
static float32 DW_tctdte_Unit_Delay4_DSTATE_p;
static float32 DW_tctdte_Unit_Delay_DSTATE_i;
static float32 DW_tctdte_Unit_Delay1_DSTATE_b;
static float32 DW_tctdte_Unit_Delay2_DSTATE_o;
static float32 DW_tctdte_Unit_Delay3_DSTATE_ck;
static float32 DW_tctdte_Unit_Delay4_DSTATE_f;
static float32 DW_tctdte_UnitDelay2_DSTATE;
static float32 DW_tctdte_UnitDelay2_DSTATE_d;
static float32 DW_tctdte_UnitDelay2_DSTATE_n;
static float32 DW_tctdte_UnitDelay2_DSTATE_l;
static float32 DW_tctdte_UnitDelay2_DSTATE_c;
#define TCTDTE_STOP_SEC_DATA_32
#include "TCTDTE_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TCTDTE/TCTDTE/INI'/TCTDTE_VehReset'
 * Block description for: 'sda:TCTDTE/TCTDTE/INI'/TCTDTE_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTDTE_VehReset
#include "Pse_TCTDTE.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTDTE_VehReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant1'/Constant' */
    SET_S_TCTDTE_CrvReqDstrbComp_1pm(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant10'/Constant' */
    SET_S_TCTDTE_MccGLaDmcDenS1_nu(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant11'/Constant' */
    SET_S_TCTDTE_MccGLaDmcDenS2_nu(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant13'/Constant' */
    SET_D_TCTDTE_CrvReqBnkAglComp_1pm(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant14'/Constant' */
    SET_S_TCTDTE_MccGLaDmcDenS3_nu(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant15'/Constant' */
    SET_S_TCTDTE_MccGLaDmcNumS0_nu(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant16'/Constant' */
    SET_S_TCTDTE_MccGLaDmcNumS1_nu(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant17'/Constant' */
    SET_D_TCTDTE_DeltaSetBnkAglComp_rad(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant18'/Constant' */
    SET_S_TCTDTE_DeltaSetBnkAglComp_rad(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant19'/Constant' */
    SET_D_TCTDTE_CrvReqDistrbStmTf_1pm(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant2'/Constant' */
    SET_S_TCTDTE_CrvReqBnkAglComp_1pm(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant20'/Constant' */
    SET_D_TCTDTE_DeltaSetDstrbStmTf_rad(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant3'/Constant' */
    SET_S_TCTDTE_DeltaSetDstrbComp_rad(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant4'/Constant' */
    SET_D_TCTDTE_DeltaSetCroWiComp_rad(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant5'/Constant' */
    SET_S_TCTDTE_DeltaSetCroWiComp_rad(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant6'/Constant' */
    SET_D_TCTDTE_DeltaSetCroWiComp_deg(0.0F);
    /* Constant: 'sda:TCTDTE/TCTDTE/INI/TCTDTE_VehReset/Constant9'/Constant' */
    SET_S_TCTDTE_MccGLaDmcDenS0_nu(0.0F);
}
#include "Pse_TCTDTE.h"
/*
 * Output and update for function-call system: 'sda:TCTDTE/TCTDTE'/TCTDTE_VehProcess'
 * Block description for: 'sda:TCTDTE/TCTDTE'/TCTDTE_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TCTDTE_VehProcess
#include "Pse_TCTDTE.h"
/* Short description: Converted settings not yet synchronized with ARAMIS! */
void TCTDTE_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_ip_lookup_fxpt_sfun_7_e;
    float32 rtb_ip_lookup_fxpt_sfun_7_g;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_Div_e;
    float32 rtb_SFunction;
    float32 rtb_Div_h;
    float32 rtb_SFunction_n;
    float32 rtb_Div_e0;
    float32 rtb_SFunction_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_gr;
    float32 rtb_ip_lookup_fxpt_sfun_7_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_a;
    float32 rtb_ip_lookup_fxpt_sfun_7_lz;
    float32 rtb_ip_lookup_fxpt_sfun_7_e0;
    float32 rtb_Mul_oa;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_ip_lookup_fxpt_sfun_7_o;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    uint8 rtb_DataTypeConversion_h;
    float32 rtb_Switch_d4;
    float32 rtb_Switch_g0;
    float32 rtb_Multiport_Switch;
    float32 rtb_Mul;
    uint8 rtb_NE;
    uint8 rtb_EQ;
    float32 rtb_Mul_hn;
    float32 rtb_Max;
    float32 rtb_Div_k4;
    float32 rtb_Div_dh;
    float32 rtb_Div_fku;
    float32 rtb_Div_f;
    float32 rtb_Unit_Delay2;
    float32 rtb_Unit_Delay3;
    float32 rtb_Div_pp;
    float32 rtb_Switch6_c;
    float32 rtb_Switch6_e;
    float32 rtb_Div_ft;
    float32 rtb_Unit_Delay1_fu;
    float32 rtb_Unit_Delay2_h;
    float32 rtb_Unit_Delay3_f;
    float32 rtb_Unit_Delay_dq;
    float32 rtb_Unit_Delay1_e4;
    float32 rtb_Unit_Delay2_m;
    float32 rtb_Unit_Delay3_n;
    float32 rtb_Switch_cx;
    float32 rtb_Mul_ei;
    float32 rtb_Switch_l1;
    float32 rtb_Switch_fkr;
    float32 rtb_Sum_o2;
    float32 rtb_Switch_k;
    float32 rtb_Sum_f5;
    float32 rtb_Switch_ny;
    float32 rtb_Sum_d3;
    float32 rtb_Switch_m;
    float32 rtb_Sum_iq;
    float32 rtb_Switch_fe;
    float32 rtb_Mul_jq;
    float32 rtb_Mul_oy;
    float32 rtb_Switch_ky;
    /* Outputs for Atomic SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE'
         *
         * Block description for 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE':
         *  X.2.1
         */
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS0_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TCTDTE_GLaDmcDenS0_nu(), &dps_result_ln);
    }
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS1_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D(GETA_Y_TCTDTE_GLaDmcDenS1_nu(), &dps_result_ln);
    }
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS2_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D(GETA_Y_TCTDTE_GLaDmcDenS2_nu(), &dps_result_ln);
    }
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS3_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_e = F32_PTR_IP1D(GETA_Y_TCTDTE_GLaDmcDenS3_nu(), &dps_result_ln);
    }
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS0_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_g = F32_PTR_IP1D(GETA_Y_TCTDTE_GLaDmcNumS0_nu(), &dps_result_ln);
    }
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D(GETA_Y_TCTDTE_GLaDmcNumS1_nu(), &dps_result_ln);
    }
    /* Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_RoadBankAngle_rad'
         */
    rtb_Multiport_Switch = f32_abs_f32(GET_S_LCFRCV_RoadBankAngle_rad());
    /* Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Abs/Functionality'/Abs' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Switch_cx = f32_abs_f32(GET_S_LCFRCV_VehVelX_mps());
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Application Parameter1'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Relational Operator/Functionality'/LT'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Relational Operator1/Functionality'/GE'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch'
         */
    if (GET_P_TCTDTE_MinimumSpeed_mps() < rtb_Switch_cx) {
        rtb_Switch_cx = GET_S_LCFRCV_VehVelX_mps();
    } else if (GET_S_LCFRCV_VehVelX_mps() >= 0.0F) {
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch' */
        rtb_Switch_cx = GET_P_TCTDTE_MinimumSpeed_mps();
    } else {
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Application Parameter'/Constant'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Gain/Functionality'/Mul'
                 */
        rtb_Switch_cx = -GET_P_TCTDTE_MinimumSpeed_mps();
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/EnforceMinimumVelocityMagnitude/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Mul2/Functionality'/Mul' */
    rtb_Mul = rtb_Switch_cx * rtb_Switch_cx;
    /* RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Freeze and Enable/NEQ/Functionality'/NE' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Freeze and Enable/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_NE = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) != ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_OFF)));
    /* RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Freeze and Enable/Equality/Functionality'/EQ' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Freeze and Enable/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TPLFBT_TrajGuiQualifier_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_TPLFBT_TrajGuiQualifier_nu()) == ((sint32) ((uint8)E_LCF_TGQ_Type_E_LCF_TGQ_REQ_FREEZE)));
    /* S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality'/Logical Operator1'
         *  Logic: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/NOT/Functionality'/NOT'
         *  Logic: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/OR1/Functionality'/OR'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset'/Unit_Delay'
         */
    rtb_DataTypeConversion_h = (uint8)((!(((sint32)rtb_NE) != 0)) || ((((sint32) DW_tctdte_Unit_Delay_DSTATE_mt) != 0) && (!(((sint32)rtb_EQ) != 0))));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING'/fcg' */
    /* MinMax: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         */
    rtb_Max = f32_max_f32_f32(GET_S_LCFRCV_SysCycleTimeVeh_sec(), GET_P_LCF_AlmostZero_nu());
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Product/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Constant'/Constant'
         *  Trigonometry: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Trigonom/Functionality'/Trigonometric Function'
         */
    rtb_Mul_hn = f32_sin_f32(rtb_Multiport_Switch) * 9.8F;
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Mul2/Functionality'/Mul' */
    rtb_Switch_cx *= rtb_Switch_cx;
    /* Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Division/Abs/Functionality'/Abs' */
    rtb_Multiport_Switch = f32_abs_f32(rtb_Switch_cx);
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Division/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Division/GT/Functionality'/GT'
         */
    if (!(rtb_Multiport_Switch > GET_P_LCF_AlmostZero_nu())) {
        rtb_Switch_cx = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Division/Switch/Functionality'/Switch' */
    /* Signum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Sign/Functionality'/Sign' incorporates:
         *  Inport: '<Root>/S_LCFRCV_RoadBankAngle_rad'
         */
    if (GET_S_LCFRCV_RoadBankAngle_rad() < 0.0F) {
        rtb_Multiport_Switch = -1.0F;
    } else if (GET_S_LCFRCV_RoadBankAngle_rad() > 0.0F) {
        rtb_Multiport_Switch = 1.0F;
    } else if (GET_S_LCFRCV_RoadBankAngle_rad() == 0.0F) {
        rtb_Multiport_Switch = 0.0F;
    } else {
        rtb_Multiport_Switch = GET_S_LCFRCV_RoadBankAngle_rad();
    }
    /* End of Signum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Sign/Functionality'/Sign' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Mul3/Functionality'/Mul' incorporates:
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Division/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Gain/Functionality'/Mul'
         */
    rtb_Switch_cx = (rtb_Mul_hn / rtb_Switch_cx) * (-rtb_Multiport_Switch);
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/PT1 Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/PT1 Filter/Constant1'/Constant'
         *  MinMax: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/PT1 Filter/Max/Functionality'/Max'
         */
    rtb_Div_e = rtb_Max / f32_max_f32_f32(GET_P_TCTDTE_PT1CrvReqBAC_sec(), rtb_Max);
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/PT1 Filter'/Unit_Delay' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay_DSTATE_l;
    /* S-Function (sfun_mmv): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/PT1 Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_h != 0U) {
        rtb_SFunction = rtb_Switch_cx;
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Multiport_Switch, rtb_Switch_cx, rtb_Div_e);
    }
    /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Sum4/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TCTEST_MccA11_nu'
         *  Inport: '<Root>/S_TCTEST_MccA21_nu'
         *  Inport: '<Root>/S_TCTEST_MccB11_nu'
         *  Inport: '<Root>/S_TCTEST_MccB21_nu'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul7/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul8/Functionality'/Mul'
         */
    rtb_Switch_cx = (GET_S_TCTEST_MccA21_nu() * GET_S_TCTEST_MccB11_nu()) - (GET_S_TCTEST_MccA11_nu() * GET_S_TCTEST_MccB21_nu());
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u'/Unit_Delay3' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1'/IV'
         *  Inport: '<Root>/S_TCTEST_CrObsCrosswind_New'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Mul_hn = 0.0F;
        rtb_Multiport_Switch = GET_S_TCTEST_CrObsCrosswind_New();
    } else {
        /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Mul1/Functionality'/Mul' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/Constant'/Constant'
                 */
        rtb_Mul_ei = GET_P_TCTDTE_BnkAglCrvReqGrd_1pms() * rtb_Max;
        /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Add/Functionality'/Sum' incorporates:
                 *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation'/Unit_Delay'
                 */
        rtb_Mul_hn = rtb_SFunction - DW_tctdte_Unit_Delay_DSTATE;
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' incorporates:
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator'
                 *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality/Add1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation'/Unit_Delay'
                 */
        if (rtb_Mul_hn > rtb_Mul_ei) {
            rtb_Mul_hn = rtb_Mul_ei + DW_tctdte_Unit_Delay_DSTATE;
        } else {
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Mul/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/Constant'/Constant'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/Mul3/Functionality'/Mul'
                         */
            rtb_Mul_ei = (-GET_P_TCTDTE_BnkAglCrvReqGrd_1pms()) * rtb_Max;
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' incorporates:
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Relational Operator1'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality/Add2/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation'/Unit_Delay'
                         */
            if (rtb_Mul_hn < rtb_Mul_ei) {
                rtb_Mul_hn = rtb_Mul_ei + DW_tctdte_Unit_Delay_DSTATE;
            } else {
                rtb_Mul_hn = rtb_SFunction;
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch6' */
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch5' */
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation/GRADIENTLIMITER1/Functionality/Subfunctionality'/Switch2' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u/Div2/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_TCTEST_CrObsCrosswind_New'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u/Sum4/Functionality'/Sum'
         */
    rtb_Mul_ei = (GET_S_TCTEST_CrObsCrosswind_New() - rtb_Multiport_Switch) / rtb_Max;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u_dot'/Unit_Delay3' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_k;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u_dot/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Multiport_Switch = rtb_Mul_ei;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u_dot/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u_dot/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u_dot/Sum4/Functionality'/Sum'
         */
    rtb_Div_k4 = (rtb_Mul_ei - rtb_Multiport_Switch) / rtb_Max;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y'/Unit_Delay3' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_i;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TCTEST_CurSteerAngle_rad'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Multiport_Switch = GET_S_TCTEST_CurSteerAngle_rad();
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y/Div2/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_TCTEST_CurSteerAngle_rad'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y/Sum4/Functionality'/Sum'
         */
    rtb_Div_dh = (GET_S_TCTEST_CurSteerAngle_rad() - rtb_Multiport_Switch) / rtb_Max;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y_dot'/Unit_Delay3' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_p;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y_dot/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Multiport_Switch = rtb_Div_dh;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y_dot/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y_dot/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y_dot/Sum4/Functionality'/Sum'
         */
    rtb_Div_fku = (rtb_Div_dh - rtb_Multiport_Switch) / rtb_Max;
    /* Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Division/Abs/Functionality'/Abs' */
    rtb_Multiport_Switch = f32_abs_f32(rtb_Switch_cx);
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Division/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Division/GT/Functionality'/GT'
         */
    if (!(rtb_Multiport_Switch > GET_P_LCF_AlmostZero_nu())) {
        rtb_Switch_cx = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Division/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Division/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Constant'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Constant2'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Constant3'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Constant4'/Constant'
         *  Inport: '<Root>/S_TCTEST_CrObsCrosswind_New'
         *  Inport: '<Root>/S_TCTEST_MccA11_nu'
         *  Inport: '<Root>/S_TCTEST_MccA12_nu'
         *  Inport: '<Root>/S_TCTEST_MccA21_nu'
         *  Inport: '<Root>/S_TCTEST_MccA22_nu'
         *  Inport: '<Root>/S_TCTEST_MccB11_nu'
         *  Inport: '<Root>/S_TCTEST_MccB21_nu'
         *  Inport: '<Root>/S_TCTEST_MccH11Cw_nu'
         *  Inport: '<Root>/S_TCTEST_MccH21Cw_nu'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul3/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul4/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul5/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Mul6/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul10/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul2/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul4/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul5/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul6/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul7/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul8/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Mul9/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Sum/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Create State Space System Elements/Sum5/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Sum/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Sum3/Functionality'/Sum'
         */
    rtb_Div_f = (((((((((GET_S_TCTEST_MccA12_nu() * GET_S_TCTEST_MccH21Cw_nu()) + GET_S_TCTEST_MccH21Cw_nu()) - (GET_S_TCTEST_MccA22_nu() * GET_S_TCTEST_MccH11Cw_nu())) * rtb_Mul_ei) * GET_P_TCTDTE_CroCGainS1_nu()) + (((GET_S_TCTEST_MccA21_nu() * GET_S_TCTEST_MccH11Cw_nu()) - (GET_S_TCTEST_MccA11_nu() * GET_S_TCTEST_MccH21Cw_nu())) * GET_S_TCTEST_CrObsCrosswind_New())) + ((rtb_Div_k4 * GET_S_TCTEST_MccH11Cw_nu()) * GET_P_TCTDTE_CroCGainS2_nu())) - ((((GET_S_TCTEST_MccA12_nu() * GET_S_TCTEST_MccB21_nu()) + GET_S_TCTEST_MccB21_nu()) - (GET_S_TCTEST_MccA22_nu() * GET_S_TCTEST_MccB11_nu())) * (rtb_Div_dh * GET_P_TCTDTE_CroCGainS1_nu()))) - ((rtb_Div_fku * GET_S_TCTEST_MccB11_nu()) * GET_P_TCTDTE_CroCGainS2_nu())) / rtb_Switch_cx;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay' */
    rtb_Div_k4 = DW_tctdte_Unit_Delay_DSTATE_j;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay1' */
    rtb_Div_fku = DW_tctdte_Unit_Delay1_DSTATE;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay2' */
    rtb_Unit_Delay2 = DW_tctdte_Unit_Delay2_DSTATE;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay3' */
    rtb_Unit_Delay3 = DW_tctdte_Unit_Delay3_DSTATE_o;
    /* MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency/Constant'/Constant'
         *  Inport: '<Root>/S_TCTEST_CurSteerAngle_rad'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay2'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay4'
         */
    switch (GET_P_TCTDTE_DelayCyclesDeltaDi_nu()) {
    case 0:
        rtb_Switch_cx = GET_S_TCTEST_CurSteerAngle_rad();
        break;
    case 1:
        rtb_Switch_cx = DW_tctdte_Unit_Delay_DSTATE_j;
        break;
    case 2:
        rtb_Switch_cx = DW_tctdte_Unit_Delay1_DSTATE;
        break;
    case 3:
        rtb_Switch_cx = DW_tctdte_Unit_Delay2_DSTATE;
        break;
    case 4:
        rtb_Switch_cx = DW_tctdte_Unit_Delay3_DSTATE_o;
        break;
    default:
        rtb_Switch_cx = DW_tctdte_Unit_Delay4_DSTATE;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Multiport_Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Q_do/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Q_do/Constant'/Constant'
         *  MinMax: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Q_do/Max/Functionality'/Max'
         */
    rtb_Div_h = rtb_Max / f32_max_f32_f32(GET_P_TCTDTE_TConstSteerAngle_sec(), rtb_Max);
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Q_do'/Unit_Delay' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay_DSTATE_h;
    /* S-Function (sfun_mmv): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Q_do/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_h != 0U) {
        rtb_SFunction_n = rtb_Switch_cx;
    } else {
        rtb_SFunction_n = f32_mmv_f32_f32_f32( rtb_Multiport_Switch, rtb_Switch_cx, rtb_Div_h);
    }
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_dot'/Unit_Delay3' */
    rtb_Switch_cx = DW_tctdte_Unit_Delay3_DSTATE_d;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_dot/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_cx = GET_S_LCFRCV_VehYawRate_rps();
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_dot/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_dot/Div2/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_dot/Sum4/Functionality'/Sum'
         */
    rtb_Div_pp = (GET_S_LCFRCV_VehYawRate_rps() - rtb_Switch_cx) / rtb_Max;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_l1 = 0.0F;
    } else {
        if (((sint32)rtb_NE) != 0) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Switch1/Functionality'/Switch' incorporates:
                         *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Abs/Functionality'/Abs'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Application Parameter1'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Constant1'/Constant'
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Relational Operator/Functionality'/LT'
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Relational Operator1/Functionality'/GE'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         */
            if (GET_P_TCTDTE_MinimumSpeed_mps() < f32_abs_f32(GET_S_LCFRCV_VehVelX_mps ())) {
                rtb_Switch_l1 = GET_S_LCFRCV_VehVelX_mps();
            } else if (GET_S_LCFRCV_VehVelX_mps() >= 0.0F) {
                /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch' */
                rtb_Switch_l1 = GET_P_TCTDTE_MinimumSpeed_mps();
            } else {
                /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Switch/Functionality'/Switch' incorporates:
                                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Application Parameter'/Constant'
                                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Gain/Functionality'/Mul'
                                 */
                rtb_Switch_l1 = -GET_P_TCTDTE_MinimumSpeed_mps();
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/EnforceMinimumVelocityMagnitude/Switch1/Functionality'/Switch' */
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a1/Mul8/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant10'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant5'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant8'/Constant'
                         *  DataTypeConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/DTC'/Data Type Conversion'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a1/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a1/Mul6/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a1/Mul7/Functionality'/Mul'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         */
            rtb_Sum_iq = (((rtb_Switch_l1 * rtb_Switch_l1) * GET_P_VEH_CorStiffFrontAxle_Npr()) * GET_P_VEH_DistCogToFrontAxle_m()) * ((float32) GET_P_VEH_Mass_kg());
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul6/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Constant1'/Constant'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         */
            rtb_Switch_fe = rtb_Sum_iq * GET_P_TCTDTE_TConstSteerAngle_sec();
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Division/Switch/Functionality'/Switch' incorporates:
                         *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Division/Abs/Functionality'/Abs'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Division/Constant3'/Constant'
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Division/GT/Functionality'/GT'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         */
            if (!(f32_abs_f32(rtb_Switch_fe) > GET_P_LCF_AlmostZero_nu())) {
                rtb_Switch_fe = GET_P_LCF_AlmostZero_nu();
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Division/Switch/Functionality'/Switch' */
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a0/Mul7/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant10'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant11'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant5'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant7'/Constant'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a0/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a0/Mul6/Functionality'/Mul'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc a0/Sum3/Functionality'/Sum'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         */
            rtb_Mul_jq = ((rtb_Switch_l1 * GET_P_VEH_CorStiffFrontAxle_Npr()) * GET_P_VEH_CorStiffRearAxle_Npr()) * (GET_P_VEH_DistCogToFrontAxle_m() + GET_P_VEH_DistCogToRearAxle_m());
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul3/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Constant'/Constant'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul5/Functionality'/Mul'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Sum5/Functionality'/Sum'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay1'
                         */
            rtb_Mul_oy = ((rtb_Mul_jq * GET_P_TCTDTE_TConstSteerAngle_sec()) + rtb_Sum_iq) * DW_tctdte_Unit_Delay1_DSTATE_d;
            /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Sum/Functionality'/Sum' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant5'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant7'/Constant'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         */
            rtb_Sum_iq = GET_P_VEH_DistCogToRearAxle_m() + GET_P_VEH_DistCogToFrontAxle_m();
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_2dot/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_2dot'/Unit_Delay3'
                         */
            if (((sint32)rtb_DataTypeConversion_h) != 0) {
                rtb_Multiport_Switch = rtb_Div_pp;
            } else {
                rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_n;
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_2dot/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant10'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant11'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant5'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant7'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant8'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Constant9'/Constant'
                         *  DataTypeConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/DTC'/Data Type Conversion'
                         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul10/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul11/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul6/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul7/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul8/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Mul9/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul11/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul6/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul7/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Mul9/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b2/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b2/Mul6/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b2/Mul7/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_2dot/Div2/Functionality/Div'/Div'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Division/Div1/Functionality/Div'/Div'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Mul4/Functionality'/Mul'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b0/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Calc b1/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_2dot/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Sum3/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay2'
                         */
            rtb_Switch_l1 = ((((((((((GET_P_VEH_DistCogToFrontAxle_m() * GET_P_VEH_DistCogToFrontAxle_m()) * GET_P_VEH_CorStiffFrontAxle_Npr()) + ((GET_P_VEH_DistCogToRearAxle_m() * GET_P_VEH_DistCogToRearAxle_m()) * GET_P_VEH_CorStiffRearAxle_Npr())) * (rtb_Switch_l1 * ((float32) GET_P_VEH_Mass_kg()))) + ((GET_P_VEH_CorStiffFrontAxle_Npr() + GET_P_VEH_CorStiffRearAxle_Npr()) * (GET_P_VEH_Inertia_kgm2() * rtb_Switch_l1))) * rtb_Div_pp) + (((((rtb_Switch_l1 * rtb_Switch_l1) * ((float32)GET_P_VEH_Mass_kg())) * ((GET_P_VEH_CorStiffRearAxle_Npr() * GET_P_VEH_DistCogToRearAxle_m()) - (GET_P_VEH_CorStiffFrontAxle_Npr() * GET_P_VEH_DistCogToFrontAxle_m()))) + ((GET_P_VEH_CorStiffFrontAxle_Npr() * GET_P_VEH_CorStiffRearAxle_Npr()) * (rtb_Sum_iq * rtb_Sum_iq))) * GET_S_LCFRCV_VehYawRate_rps())) + ((((rtb_Switch_l1 * rtb_Switch_l1) * ((float32)GET_P_VEH_Mass_kg())) * GET_P_VEH_Inertia_kgm2()) * ((rtb_Div_pp - rtb_Multiport_Switch) / rtb_Max))) - rtb_Mul_oy) - (DW_tctdte_Unit_Delay2_DSTATE_p * rtb_Mul_jq)) / rtb_Switch_fe;
        } else {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Constant2'/Constant'
                         */
            rtb_Switch_l1 = 0.0F;
        }
        rtb_Switch_l1 = (rtb_Max * rtb_Switch_l1) + DW_tctdte_Unit_Delay1_DSTATE_d;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Switch1'
         */
    if (rtb_Switch_l1 >= 10000.0F) {
        rtb_Switch_l1 = 10000.0F;
    } else {
        if (rtb_Switch_l1 <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1'/MN'
                         */
            rtb_Switch_l1 = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL1/Functionality'/Switch2' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Sum_iq = 0.0F;
    } else {
        rtb_Sum_iq = (rtb_Max * rtb_Switch_l1) + DW_tctdte_Unit_Delay_DSTATE_m;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Switch1'
         */
    if (rtb_Sum_iq >= 10000.0F) {
        rtb_Sum_iq = 10000.0F;
    } else {
        if (rtb_Sum_iq <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL'/MN'
                         */
            rtb_Sum_iq = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/INTEGRATORK_REL/Functionality'/Switch2' */
    /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Sum1/Functionality'/Sum' */
    rtb_Switch_fe = rtb_SFunction_n - rtb_Sum_iq;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1'/Unit_Delay3' */
    rtb_Switch_cx = DW_tctdte_Unit_Delay3_DSTATE_e;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_cx = rtb_Switch_fe;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/Sum4/Functionality'/Sum'
         */
    rtb_Switch_cx = (rtb_Switch_fe - rtb_Switch_cx) / rtb_Max;
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/Constant'/Constant'
         *  MinMax: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/Max/Functionality'/Max'
         */
    rtb_Div_e0 = rtb_Max / f32_max_f32_f32(0.03F, rtb_Max);
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1'/Unit_Delay' */
    rtb_Multiport_Switch = DW_tctdte_Unit_Delay_DSTATE_lo;
    /* S-Function (sfun_mmv): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1/LOWPASST_RE/Functionality'/S-Function' */
    if (rtb_DataTypeConversion_h != 0U) {
        rtb_SFunction_d = rtb_Switch_cx;
    } else {
        rtb_SFunction_d = f32_mmv_f32_f32_f32( rtb_Multiport_Switch, rtb_Switch_cx, rtb_Div_e0);
    }
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 2'/Unit_Delay3' */
    rtb_Switch_cx = DW_tctdte_Unit_Delay3_DSTATE_j;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 2/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_cx = rtb_SFunction_d;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 2/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 2/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 2/Sum4/Functionality'/Sum'
         */
    rtb_Mul_jq = (rtb_SFunction_d - rtb_Switch_cx) / rtb_Max;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Mul_oy = 0.0F;
    } else {
        if (((sint32)rtb_NE) != 0) {
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul8/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Constant1'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Constant4'/Constant'
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul4/Functionality'/Mul'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Switch/Functionality'/Switch'
                         */
            rtb_Mul_oy = (GET_P_TCTDTE_DmcT1comp_sec() * GET_P_TCTDTE_DmcT2comp_sec()) * rtb_ip_lookup_fxpt_sfun_7_c;
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Division/Switch/Functionality'/Switch' incorporates:
                         *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Division/Abs/Functionality'/Abs'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Division/Constant3'/Constant'
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Division/GT/Functionality'/GT'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Switch/Functionality'/Switch'
                         */
            if (!(f32_abs_f32(rtb_Mul_oy) > GET_P_LCF_AlmostZero_nu())) {
                rtb_Mul_oy = GET_P_LCF_AlmostZero_nu();
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Division/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 3/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 3'/Unit_Delay3'
                         */
            if (((sint32)rtb_DataTypeConversion_h) != 0) {
                rtb_Multiport_Switch = rtb_Mul_jq;
            } else {
                rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_jz;
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 3/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Constant1'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Constant2'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Constant3'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Constant4'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSetDot/Constant1'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSetDot/Constant2'/Constant'
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS0_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS1_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS2_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS3_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS0_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Mul1/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Mul12/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSetDot/Mul12/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 3/Div2/Functionality/Div'/Div'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Division/Div1/Functionality/Div'/Div'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul10/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul11/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul6/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Mul9/Functionality'/Mul'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS0_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS2_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS3_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS0_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Sum5/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSet2Dot/Sum7/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSetDot/Sum5/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Coefficient for deltaSetDot/Sum7/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 3/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Sum6/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay1'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay3'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay5'
                         */
            rtb_Mul_oy = (((((((rtb_ip_lookup_fxpt_sfun_7 * rtb_Switch_fe) + (rtb_ip_lookup_fxpt_sfun_7_m * rtb_SFunction_d)) + (rtb_ip_lookup_fxpt_sfun_7_l * rtb_Mul_jq)) + (((rtb_Mul_jq - rtb_Multiport_Switch) / rtb_Max) * rtb_ip_lookup_fxpt_sfun_7_e)) - ((((GET_P_TCTDTE_DmcT1comp_sec() * GET_P_TCTDTE_DmcT2comp_sec()) * rtb_ip_lookup_fxpt_sfun_7_g) + ((GET_P_TCTDTE_DmcT1comp_sec() + GET_P_TCTDTE_DmcT2comp_sec()) * rtb_ip_lookup_fxpt_sfun_7_c)) * DW_tctdte_Unit_Delay1_DSTATE_m)) - (DW_tctdte_Unit_Delay5_DSTATE * rtb_ip_lookup_fxpt_sfun_7_g)) - ((((GET_P_TCTDTE_DmcT1comp_sec() + GET_P_TCTDTE_DmcT2comp_sec()) * rtb_ip_lookup_fxpt_sfun_7_g) + rtb_ip_lookup_fxpt_sfun_7_c) * DW_tctdte_Unit_Delay3_DSTATE_i0)) / rtb_Mul_oy;
        } else {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Constant2'/Constant'
                         */
            rtb_Mul_oy = 0.0F;
        }
        rtb_Mul_oy = (rtb_Max * rtb_Mul_oy) + DW_tctdte_Unit_Delay1_DSTATE_m;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Switch1'
         */
    if (rtb_Mul_oy >= 10000.0F) {
        rtb_Mul_oy = 10000.0F;
    } else {
        if (rtb_Mul_oy <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2'/MN'
                         */
            rtb_Mul_oy = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL2/Functionality'/Switch2' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch6_c = 0.0F;
    } else {
        rtb_Switch6_c = (rtb_Max * rtb_Mul_oy) + DW_tctdte_Unit_Delay_DSTATE_he;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Switch1'
         */
    if (rtb_Switch6_c >= 10000.0F) {
        rtb_Switch6_c = 10000.0F;
    } else {
        if (rtb_Switch6_c <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1'/MN'
                         */
            rtb_Switch6_c = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL1/Functionality'/Switch2' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay2'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch6_e = 0.0F;
    } else {
        rtb_Switch6_e = (rtb_Max * rtb_Switch6_c) + DW_tctdte_Unit_Delay2_DSTATE_g;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Switch1'
         */
    if (rtb_Switch6_e >= 10000.0F) {
        rtb_Switch6_e = 10000.0F;
    } else {
        if (rtb_Switch6_e <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3'/MN'
                         */
            rtb_Switch6_e = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/INTEGRATORK_REL3/Functionality'/Switch2' */
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta'/Unit_Delay3' */
    rtb_Switch_cx = DW_tctdte_Unit_Delay3_DSTATE_c;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta/Switch/Functionality'/Switch' */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_cx = rtb_Switch_fe;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta/Switch/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta/Div2/Functionality/Div'/Div' incorporates:
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta/Sum4/Functionality'/Sum'
         */
    rtb_Div_ft = (rtb_Switch_fe - rtb_Switch_cx) / rtb_Max;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality/Add/Functionality'/Sum'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay1'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Switch_fkr = 0.0F;
    } else {
        if (((sint32)rtb_NE) != 0) {
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Mul/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Constant'/Constant'
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
                         */
            rtb_Mul_oa = GET_S_LCFRCV_VehVelX_mps() * 3.6F;
            /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Y_TCTDTE_KappaAngle_degm/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TCTDTE_KappaAngle_kph */
                FDPS_PTR_F32(GETA_X_TCTDTE_KappaAngle_kph(), rtb_Mul_oa, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D(GETA_Y_TCTDTE_KappaAngle_degm (), &dps_result_ln);
            }
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Division/Switch/Functionality'/Switch' incorporates:
                         *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Division/Abs/Functionality'/Abs'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Constant2'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Division/Constant3'/Constant'
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Division/GT/Functionality'/GT'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
                         */
            if (180.0F > GET_P_LCF_AlmostZero_nu()) {
                rtb_Multiport_Switch = 180.0F;
            } else {
                rtb_Multiport_Switch = GET_P_LCF_AlmostZero_nu();
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Division/Switch/Functionality'/Switch' */
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Division/Div1/Functionality/Div'/Div' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Constant'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Constant3'/Constant'
                         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Mul/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Y_TCTDTE_KappaAngle_degm/Functionality/odtc'/Product'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/deg_to_rad/Mul1/Functionality'/Mul'
                         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Y_TCTDTE_KappaAngle_degm/Functionality'/ip_lookup_fxpt_sfun_7'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
                         */
            rtb_Switch_fkr = (3.14159274F * rtb_ip_lookup_fxpt_sfun_7_d) / rtb_Multiport_Switch;
            /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul5/Functionality'/Mul' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant8'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant9'/Constant'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul1/Functionality'/Mul'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
                         */
            rtb_Switch_ky = (GET_P_TCTDTE_DmcT1comp_sec() * GET_P_TCTDTE_DmcT2comp_sec ()) * rtb_Switch_fkr;
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Division/Switch/Functionality'/Switch' incorporates:
                         *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Division/Abs/Functionality'/Abs'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Division/Constant3'/Constant'
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Division/GT/Functionality'/GT'
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
                         */
            if (!(f32_abs_f32(rtb_Switch_ky) > GET_P_LCF_AlmostZero_nu())) {
                rtb_Switch_ky = GET_P_LCF_AlmostZero_nu();
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Division/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta_dot/Switch/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta_dot'/Unit_Delay3'
                         */
            if (((sint32)rtb_DataTypeConversion_h) != 0) {
                rtb_Multiport_Switch = rtb_Div_ft;
            } else {
                rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_o2;
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta_dot/Switch/Functionality'/Switch' */
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant1'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant3'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant5'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant6'/Constant'
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant7'/Constant'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta_dot/Div2/Functionality/Div'/Div'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Division/Div1/Functionality/Div'/Div'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul2/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul3/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul4/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul6/Functionality'/Mul'
                         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Mul7/Functionality'/Mul'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta_dot/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Sum/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Sum1/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Sum2/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Sum3/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Sum4/Functionality'/Sum'
                         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Sum5/Functionality'/Sum'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay1'
                         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay5'
                         */
            rtb_Switch_fkr = ((((((GET_P_TCTDTE_DmcT1_sec() + GET_P_TCTDTE_DmcT2_sec()) * rtb_Div_ft) + rtb_Switch_fe) + (((rtb_Div_ft - rtb_Multiport_Switch) / rtb_Max) * (GET_P_TCTDTE_DmcT1_sec() * GET_P_TCTDTE_DmcT2_sec()))) - (((GET_P_TCTDTE_DmcT1comp_sec() + GET_P_TCTDTE_DmcT2comp_sec()) * DW_tctdte_Unit_Delay1_DSTATE_o) * rtb_Switch_fkr)) - (DW_tctdte_Unit_Delay5_DSTATE_e * rtb_Switch_fkr)) / rtb_Switch_ky;
        } else {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Switch/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Constant2'/Constant'
                         */
            rtb_Switch_fkr = 0.0F;
        }
        rtb_Switch_fkr = (rtb_Max * rtb_Switch_fkr) + DW_tctdte_Unit_Delay1_DSTATE_o;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Switch1'
         */
    if (rtb_Switch_fkr >= 10000.0F) {
        rtb_Switch_fkr = 10000.0F;
    } else {
        if (rtb_Switch_fkr <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2'/MN'
                         */
            rtb_Switch_fkr = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL2/Functionality'/Switch2' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Switch6' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1'/IV'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality/Mul/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality/Add/Functionality'/Sum'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_h) != 0) {
        rtb_Max = 0.0F;
    } else {
        rtb_Max = (rtb_Max * rtb_Switch_fkr) + DW_tctdte_Unit_Delay_DSTATE_d;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Switch6' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1'/MN'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1'/MX'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Relational Operator1'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Relational Operator3'
         *  Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Switch1'
         */
    if (rtb_Max >= 10000.0F) {
        rtb_Max = 10000.0F;
    } else {
        if (rtb_Max <= -10000.0F) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1'/MN'
                         */
            rtb_Max = -10000.0F;
        }
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/INTEGRATORK_REL1/Functionality'/Switch2' */
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay' */
    rtb_Switch_ky = DW_tctdte_Unit_Delay_DSTATE_m0;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay1' */
    rtb_Unit_Delay1_fu = DW_tctdte_Unit_Delay1_DSTATE_h;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay2' */
    rtb_Unit_Delay2_h = DW_tctdte_Unit_Delay2_DSTATE_e;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay3' */
    rtb_Unit_Delay3_f = DW_tctdte_Unit_Delay3_DSTATE_g;
    /* MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM/Constant'/Constant'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay2'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay4'
         */
    switch (GET_P_TCTDTE_DelayCyclesLaDMC_nu()) {
    case 0:
        rtb_Switch_cx = rtb_Max;
        break;
    case 1:
        rtb_Switch_cx = DW_tctdte_Unit_Delay_DSTATE_m0;
        break;
    case 2:
        rtb_Switch_cx = DW_tctdte_Unit_Delay1_DSTATE_h;
        break;
    case 3:
        rtb_Switch_cx = DW_tctdte_Unit_Delay2_DSTATE_e;
        break;
    case 4:
        rtb_Switch_cx = DW_tctdte_Unit_Delay3_DSTATE_g;
        break;
    default:
        rtb_Switch_cx = DW_tctdte_Unit_Delay4_DSTATE_p;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Multiport_Switch' */
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay' */
    rtb_Unit_Delay_dq = DW_tctdte_Unit_Delay_DSTATE_i;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay1' */
    rtb_Unit_Delay1_e4 = DW_tctdte_Unit_Delay1_DSTATE_b;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay2' */
    rtb_Unit_Delay2_m = DW_tctdte_Unit_Delay2_DSTATE_o;
    /* UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay3' */
    rtb_Unit_Delay3_n = DW_tctdte_Unit_Delay3_DSTATE_ck;
    /* MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Multiport_Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1/Constant'/Constant'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay1'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay2'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay3'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay4'
         */
    switch (GET_P_TCTDTE_DelayCyclesLaDMC_nu()) {
    case 0:
        rtb_Multiport_Switch = rtb_Switch6_e;
        break;
    case 1:
        rtb_Multiport_Switch = DW_tctdte_Unit_Delay_DSTATE_i;
        break;
    case 2:
        rtb_Multiport_Switch = DW_tctdte_Unit_Delay1_DSTATE_b;
        break;
    case 3:
        rtb_Multiport_Switch = DW_tctdte_Unit_Delay2_DSTATE_o;
        break;
    case 4:
        rtb_Multiport_Switch = DW_tctdte_Unit_Delay3_DSTATE_ck;
        break;
    default:
        rtb_Multiport_Switch = DW_tctdte_Unit_Delay4_DSTATE_f;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Multiport_Switch' */
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain kappa_do_STM/Y_TCTDTE_GainKappaDstrbReq_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_gr = F32_PTR_IP1D (GETA_Y_TCTDTE_GainKappaDstrbReq_nu(), &dps_result_ln);
    }
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain kappa_do_STM/Mul2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain kappa_do_STM/Y_TCTDTE_GainKappaDstrbReq_nu/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain kappa_do_STM/Y_TCTDTE_GainKappaDstrbReq_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Switch_cx *= rtb_ip_lookup_fxpt_sfun_7_gr;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Sum_o2 = DW_tctdte_UnitDelay2_DSTATE;
    } else {
        /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTDTE_InputVehVelSat_met */
            FDPS_PTR_F32(GETA_X_TCTDTE_InputVehVelSat_met(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_e0 = F32_PTR_IP1D(GETA_Y_TCTDTE_VelXToMaxCrv_1pm (), &dps_result_ln);
        }
        /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Sum' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Sum_o2 = rtb_ip_lookup_fxpt_sfun_7_e0;
        /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Gain/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Switch_k = -rtb_ip_lookup_fxpt_sfun_7_e0;
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Saturation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Gain/Functionality'/Mul'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Saturation/Relational Operator/Functionality'/GE'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (rtb_Switch_cx >= (-rtb_ip_lookup_fxpt_sfun_7_e0)) {
            rtb_Switch_k = rtb_Switch_cx;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Saturation/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Saturation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Saturation/Relational Operator1/Functionality'/LE'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (rtb_Switch_k <= rtb_ip_lookup_fxpt_sfun_7_e0) {
            rtb_Sum_o2 = rtb_Switch_k;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv/Saturation/Switch1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain kappa_BankAngle/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain kappa_BankAngle/Constant1'/Constant'
         */
    rtb_Switch_k = rtb_Mul_hn * GET_P_TCTDTE_CrvReqBnkAglGain_nu();
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze1/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze1'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Sum_f5 = DW_tctdte_UnitDelay2_DSTATE_d;
    } else {
        /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTDTE_InputVehVelSat_met */
            FDPS_PTR_F32(GETA_X_TCTDTE_InputVehVelSat_met(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_lz = F32_PTR_IP1D(GETA_Y_TCTDTE_VelXToMaxCrv_1pm (), &dps_result_ln);
        }
        /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Sum' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Sum_f5 = rtb_ip_lookup_fxpt_sfun_7_lz;
        /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Gain/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Switch_ny = -rtb_ip_lookup_fxpt_sfun_7_lz;
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Saturation/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Gain/Functionality'/Mul'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Saturation/Relational Operator/Functionality'/GE'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (rtb_Switch_k >= (-rtb_ip_lookup_fxpt_sfun_7_lz)) {
            rtb_Switch_ny = rtb_Switch_k;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Saturation/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Saturation/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Saturation/Relational Operator1/Functionality'/LE'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Y_TCTDTE_VelXToMaxCrv_1pm/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (rtb_Switch_ny <= rtb_ip_lookup_fxpt_sfun_7_lz) {
            rtb_Sum_f5 = rtb_Switch_ny;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationCrv1/Saturation/Switch1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze1/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain DeltaSet_CrossWind/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain DeltaSet_CrossWind/Constant'/Constant'
         *  UnaryMinus: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Neg/Functionality'/Unary Minus'
         */
    rtb_Div_f = (-rtb_Div_f) * GET_P_TCTDTE_CroWindDeltaSetGain_nu();
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze2/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze2'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_ny = DW_tctdte_UnitDelay2_DSTATE_n;
    } else {
        /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Y_TCTDTE_CroWindDeltaSetSat_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D (GETA_Y_TCTDTE_CroWindDeltaSetSat_rad(), &dps_result_ln);
        }
        /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Gain/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 */
        rtb_Switch_ny = -rtb_ip_lookup_fxpt_sfun_7_p;
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Saturation/Switch/Functionality'/Switch' incorporates:
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Gain/Functionality'/Mul'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Saturation/Relational Operator/Functionality'/GE'
                 */
        if (rtb_Div_f >= (-rtb_ip_lookup_fxpt_sfun_7_p)) {
            rtb_Switch_ny = rtb_Div_f;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Saturation/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Saturation/Switch1/Functionality'/Switch' incorporates:
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Saturation/Relational Operator1/Functionality'/LE'
                 */
        if (!(rtb_Switch_ny <= rtb_ip_lookup_fxpt_sfun_7_p)) {
            rtb_Switch_ny = rtb_ip_lookup_fxpt_sfun_7_p;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta1/Saturation/Switch1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze2/Switch2/Functionality'/Switch' */
    /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain delta_do_STM/Y_TCTDTE_DeltaSetDstrbGain_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
        FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7_h = F32_PTR_IP1D (GETA_Y_TCTDTE_DeltaSetDstrbGain_nu(), &dps_result_ln);
    }
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain delta_do_STM/Mul2/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain delta_do_STM/Y_TCTDTE_DeltaSetDstrbGain_nu/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain delta_do_STM/Y_TCTDTE_DeltaSetDstrbGain_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    rtb_Multiport_Switch *= rtb_ip_lookup_fxpt_sfun_7_h;
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze3/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality'/ip_lookup_fxpt_sfun_7'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze3'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Sum_d3 = DW_tctdte_UnitDelay2_DSTATE_l;
    } else {
        /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_a = F32_PTR_IP1D (GETA_Y_TCTDTE_DeltaSetDstrbSat_rad(), &dps_result_ln);
        }
        /* Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality/odtc'/Sum' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        rtb_Sum_d3 = rtb_ip_lookup_fxpt_sfun_7_a;
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Limit/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality/odtc'/Product'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Limit/Functionality'/Relational Operator'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Y_TCTDTE_DeltaSetDstrbSat_rad/Functionality'/ip_lookup_fxpt_sfun_7'
                 */
        if (rtb_ip_lookup_fxpt_sfun_7_a >= rtb_Multiport_Switch) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Limit/Functionality'/Switch1' incorporates:
                         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Limit/Functionality'/Relational Operator1'
                         *  UnaryMinus: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Neg/Functionality'/Unary Minus'
                         */
            if ((-rtb_ip_lookup_fxpt_sfun_7_a) <= rtb_Multiport_Switch) {
                rtb_Sum_d3 = rtb_Multiport_Switch;
            } else {
                rtb_Sum_d3 = -rtb_ip_lookup_fxpt_sfun_7_a;
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Limit/Functionality'/Switch1' */
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Saturation/Limit/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze3/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain DeltaSet_BankAngle/Mul2/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Gain DeltaSet_BankAngle/Constant1'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Constant1'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Constant2'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Constant4'/Constant'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Mul1/Functionality'/Mul'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Mul4/Functionality'/Mul'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Sum/Functionality'/Sum'
         *  Sum: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/Curvature2SteerAngle/Sum1/Functionality'/Sum'
         */
    rtb_Mul = (((GET_P_VEH_SelfSteeringGrd_nu() * rtb_Mul) + (GET_P_VEH_DistCogToFrontAxle_m() + GET_P_VEH_DistCogToRearAxle_m())) * rtb_Mul_hn) * GET_P_TCTDTE_DeltaSetBnkAglGain_nu();
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze4/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze4'/Unit Delay2'
         */
    if (((sint32)rtb_EQ) != 0) {
        rtb_Switch_m = DW_tctdte_UnitDelay2_DSTATE_c;
    } else {
        /* S-Function Block sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Y_TCTDTE_DeltaSetBnkAglSat_rad/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TCTDTE_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TCTDTE_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_o = F32_PTR_IP1D (GETA_Y_TCTDTE_DeltaSetBnkAglSat_rad(), &dps_result_ln);
        }
        /* Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Gain/Functionality'/Mul' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 */
        rtb_Switch_m = -rtb_ip_lookup_fxpt_sfun_7_o;
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Saturation/Switch/Functionality'/Switch' incorporates:
                 *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Gain/Functionality'/Mul'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Saturation/Relational Operator/Functionality'/GE'
                 */
        if (rtb_Mul >= (-rtb_ip_lookup_fxpt_sfun_7_o)) {
            rtb_Switch_m = rtb_Mul;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Saturation/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Saturation/Switch1/Functionality'/Switch' incorporates:
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Saturation/Relational Operator1/Functionality'/LE'
                 */
        if (!(rtb_Switch_m <= rtb_ip_lookup_fxpt_sfun_7_o)) {
            rtb_Switch_m = rtb_ip_lookup_fxpt_sfun_7_o;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/SaturationDelta/Saturation/Switch1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze4/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant5'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant8'/Constant'
         */
    if (((sint32)GET_P_TCTDTE_BnkAglCompActive_nu()) != 0) {
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output4/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output4/Constant6'/Constant'
                 */
        if (((sint32)rtb_NE) != 0) {
            rtb_Switch_d4 = rtb_Switch_m;
        } else {
            rtb_Switch_d4 = 0.0F;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output4/Switch4/Functionality'/Switch' */
    } else {
        rtb_Switch_d4 = 0.0F;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch4/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant7'/Constant'
         */
    if (((sint32)GET_P_TCTDTE_CroWindCompActive_nu()) != 0) {
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output2/Switch4/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output2/Constant6'/Constant'
                 */
        if (((sint32)rtb_NE) != 0) {
            rtb_Switch_g0 = rtb_Switch_ny;
        } else {
            rtb_Switch_g0 = 0.0F;
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output2/Switch4/Functionality'/Switch' */
    } else {
        rtb_Switch_g0 = 0.0F;
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch4/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE'/Multiport Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant12'/Constant'
         */
    switch (GET_P_TCTDTE_Dss_nu()) {
    case 0:
        /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch4'/copy1' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant11'/Constant'
                 */
        SET_S_TCTDTE_DeltaSetDstrbComp_rad(0.0F);
        break;
    case 1:
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch5/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant9'/Constant'
                 */
        if (((sint32)GET_P_TCTDTE_DistrbCompActive_nu()) != 0) {
            /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output3/Switch4/Functionality'/Switch' */
            if (((sint32)rtb_NE) != 0) {
                /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch4'/copy1' */
                SET_S_TCTDTE_DeltaSetDstrbComp_rad(rtb_Sum_d3);
            } else {
                /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch4'/copy1' incorporates:
                                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output3/Constant6'/Constant'
                                 */
                SET_S_TCTDTE_DeltaSetDstrbComp_rad(0.0F);
            }
            /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output3/Switch4/Functionality'/Switch' */
        } else {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch4'/copy1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant6'/Constant'
                         */
            SET_S_TCTDTE_DeltaSetDstrbComp_rad(0.0F);
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch5/Functionality'/Switch' */
        break;
    default:
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Seleect absolute maximum/Switch5/Functionality'/Switch' incorporates:
                 *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Seleect absolute maximum/Abs/Functionality'/Abs'
                 *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Seleect absolute maximum/Abs1/Functionality'/Abs'
                 *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Seleect absolute maximum/GT/Functionality'/GT'
                 */
        if (f32_abs_f32(rtb_Switch_d4) > f32_abs_f32(rtb_Switch_g0)) {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch4'/copy1' */
            SET_S_TCTDTE_DeltaSetDstrbComp_rad(rtb_Switch_d4);
        } else {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch4'/copy1' */
            SET_S_TCTDTE_DeltaSetDstrbComp_rad(rtb_Switch_g0);
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Seleect absolute maximum/Switch5/Functionality'/Switch' */
        break;
    }
    /* End of MultiPortSwitch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE'/Multiport Switch' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant2'/Constant'
         */
    if (((sint32)GET_P_TCTDTE_DistrbCompActive_nu()) != 0) {
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output/Switch4/Functionality'/Switch' */
        if (((sint32)rtb_NE) != 0) {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch1'/copy1' */
            SET_S_TCTDTE_CrvReqDstrbComp_1pm(rtb_Sum_o2);
        } else {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch1'/copy1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output/Constant6'/Constant'
                         */
            SET_S_TCTDTE_CrvReqDstrbComp_1pm(0.0F);
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output/Switch4/Functionality'/Switch' */
    } else {
        /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch1'/copy1' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant1'/Constant'
                 */
        SET_S_TCTDTE_CrvReqDstrbComp_1pm(0.0F);
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant10'/Constant'
         */
    if (((sint32)GET_P_TCTDTE_BnkAglCompActive_nu()) != 0) {
        /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output1/Switch4/Functionality'/Switch' */
        if (((sint32)rtb_NE) != 0) {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch2'/copy1' */
            SET_S_TCTDTE_CrvReqBnkAglComp_1pm(rtb_Sum_f5);
        } else {
            /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch2'/copy1' incorporates:
                         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output1/Constant6'/Constant'
                         */
            SET_S_TCTDTE_CrvReqBnkAglComp_1pm(0.0F);
        }
        /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Enable Output1/Switch4/Functionality'/Switch' */
    } else {
        /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch2'/copy1' incorporates:
                 *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Constant4'/Constant'
                 */
        SET_S_TCTDTE_CrvReqBnkAglComp_1pm(0.0F);
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Switch2/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING'/fcg' incorporates:
         *  SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tctdte_Unit_Delay_DSTATE_mt = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Determine Reset/EDGEFALLING'/fcg' */
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/GradientLimitation'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE = rtb_Mul_hn;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/CompensateBankAngleRoad/PT1 Filter'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_l = rtb_SFunction;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u'/Unit_Delay3' incorporates:
         *  Update for Inport: '<Root>/S_TCTEST_CrObsCrosswind_New'
         */
    DW_tctdte_Unit_Delay3_DSTATE = GET_S_TCTEST_CrObsCrosswind_New();
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of u_dot'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_k = rtb_Mul_ei;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y'/Unit_Delay3' incorporates:
         *  Update for Inport: '<Root>/S_TCTEST_CurSteerAngle_rad'
         */
    DW_tctdte_Unit_Delay3_DSTATE_i = GET_S_TCTEST_CurSteerAngle_rad();
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Crosswind Compensation/Disturbance Compensation regarding Crosswind/Discrete Derivative of y_dot'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_p = rtb_Div_dh;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_TCTEST_CurSteerAngle_rad'
         */
    DW_tctdte_Unit_Delay_DSTATE_j = GET_S_TCTEST_CurSteerAngle_rad();
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay1' */
    DW_tctdte_Unit_Delay1_DSTATE = rtb_Div_k4;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay2' */
    DW_tctdte_Unit_Delay2_DSTATE = rtb_Div_fku;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_o = rtb_Unit_Delay2;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select Latency'/Unit_Delay4' */
    DW_tctdte_Unit_Delay4_DSTATE = rtb_Unit_Delay3;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Q_do'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_h = rtb_SFunction_n;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_m = rtb_Sum_iq;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay1' */
    DW_tctdte_Unit_Delay1_DSTATE_d = rtb_Switch_l1;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta'/Unit_Delay2' */
    DW_tctdte_Unit_Delay2_DSTATE_p = rtb_Sum_iq;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_dot'/Unit_Delay3' incorporates:
         *  Update for Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    DW_tctdte_Unit_Delay3_DSTATE_d = GET_S_LCFRCV_VehYawRate_rps();
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse Vehicle Dynamics psi_dot -> delta/Discrete Derivative psi_2dot'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_n = rtb_Div_pp;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_e = rtb_Switch_fe;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 1'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_lo = rtb_SFunction_d;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 2'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_j = rtb_SFunction_d;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d/Discrete Derivative 3'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_jz = rtb_Mul_jq;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_i0 = rtb_Switch6_c;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay5' */
    DW_tctdte_Unit_Delay5_DSTATE = rtb_Switch6_e;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay1' */
    DW_tctdte_Unit_Delay1_DSTATE_m = rtb_Mul_oy;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_he = rtb_Switch6_c;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> delta_set)*Q_d'/Unit_Delay2' */
    DW_tctdte_Unit_Delay2_DSTATE_g = rtb_Switch6_e;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_c = rtb_Switch_fe;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d/Discrete Derivative of delta_dot'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_o2 = rtb_Div_ft;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay5' */
    DW_tctdte_Unit_Delay5_DSTATE_e = rtb_Max;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay1' */
    DW_tctdte_Unit_Delay1_DSTATE_o = rtb_Switch_fkr;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Inverse DMC Dynamic (delta -> kappa)*Q_d'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_d = rtb_Max;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_m0 = rtb_Max;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay1' */
    DW_tctdte_Unit_Delay1_DSTATE_h = rtb_Switch_ky;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay2' */
    DW_tctdte_Unit_Delay2_DSTATE_e = rtb_Unit_Delay1_fu;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_g = rtb_Unit_Delay2_h;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM'/Unit_Delay4' */
    DW_tctdte_Unit_Delay4_DSTATE_p = rtb_Unit_Delay3_f;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay' */
    DW_tctdte_Unit_Delay_DSTATE_i = rtb_Switch6_e;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay1' */
    DW_tctdte_Unit_Delay1_DSTATE_b = rtb_Unit_Delay_dq;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay2' */
    DW_tctdte_Unit_Delay2_DSTATE_o = rtb_Unit_Delay1_e4;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay3' */
    DW_tctdte_Unit_Delay3_DSTATE_ck = rtb_Unit_Delay2_m;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Disturbance Observer/Select LaDMC Latency STM1'/Unit_Delay4' */
    DW_tctdte_Unit_Delay4_DSTATE_f = rtb_Unit_Delay3_n;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze'/Unit Delay2' */
    DW_tctdte_UnitDelay2_DSTATE = rtb_Sum_o2;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze1'/Unit Delay2' */
    DW_tctdte_UnitDelay2_DSTATE_d = rtb_Sum_f5;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze2'/Unit Delay2' */
    DW_tctdte_UnitDelay2_DSTATE_n = rtb_Switch_ny;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze3'/Unit Delay2' */
    DW_tctdte_UnitDelay2_DSTATE_l = rtb_Sum_d3;
    /* Update for UnitDelay: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Freeze4'/Unit Delay2' */
    DW_tctdte_UnitDelay2_DSTATE_c = rtb_Switch_m;
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch10'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS1_nu/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    SET_S_TCTDTE_MccGLaDmcDenS1_nu(rtb_ip_lookup_fxpt_sfun_7_m);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch11'/copy1' incorporates:
                                                                   *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                                                                   *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS2_nu/Functionality/odtc'/Product'
                                                                   *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS2_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                                                                   */
    SET_S_TCTDTE_MccGLaDmcDenS2_nu(rtb_ip_lookup_fxpt_sfun_7_l);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch12'/copy1' incorporates:
                                                                   *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                                                                   *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS3_nu/Functionality/odtc'/Product'
                                                                   *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS3_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                                                                   */
    SET_S_TCTDTE_MccGLaDmcDenS3_nu(rtb_ip_lookup_fxpt_sfun_7_e);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch13'/copy1' incorporates:
                                                                   *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                                                                   *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS0_nu/Functionality/odtc'/Product'
                                                                   *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS0_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                                                                   */
    SET_S_TCTDTE_MccGLaDmcNumS0_nu(rtb_ip_lookup_fxpt_sfun_7_g);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch14'/copy1' incorporates:
                                                                   *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                                                                   *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality/odtc'/Product'
                                                                   *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcNumS1_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                                                                   */
    SET_S_TCTDTE_MccGLaDmcNumS1_nu(rtb_ip_lookup_fxpt_sfun_7_c);
    /* End of Outputs for SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE' */
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch15'/copy1' */
    SET_S_TCTDTE_DeltaSetBnkAglComp_rad(rtb_Switch_d4);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch16'/copy1' */
    SET_D_TCTDTE_CrvReqBnkAglComp_1pm(rtb_Switch_k);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch17'/copy1' */
    SET_D_TCTDTE_CrvReqDistrbStmTf_1pm(rtb_Switch_cx);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch19'/copy1' */
    SET_D_TCTDTE_DeltaSetBnkAglComp_rad(rtb_Mul);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch20'/copy1' */
    SET_D_TCTDTE_DeltaSetDstrbStmTf_rad(rtb_Multiport_Switch);
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch3'/copy1' */
    SET_S_TCTDTE_DeltaSetCroWiComp_rad(rtb_Switch_g0);
    /* Outputs for Atomic SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE'
                                                         *
                                                         * Block description for 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE':
                                                         *  X.2.1
                                                         */
    /* Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Division/Switch/Functionality'/Switch' incorporates:
         *  Abs: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Division/Abs/Functionality'/Abs'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Constant3'/Constant'
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Division/Constant3'/Constant'
         *  RelationalOperator: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Division/GT/Functionality'/GT'
         */
    if (3.14159274F > GET_P_LCF_AlmostZero_nu()) {
        rtb_Multiport_Switch = 3.14159274F;
    } else {
        rtb_Multiport_Switch = GET_P_LCF_AlmostZero_nu();
    }
    /* End of Switch: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Division/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch5'/copy1' incorporates:
         *  Constant: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Constant2'/Constant'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Division/Div1/Functionality/Div'/Div'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/rad to deg/Mul1/Functionality'/Mul'
         */
    SET_D_TCTDTE_DeltaSetCroWiComp_deg((rtb_Div_f * 180.0F) / rtb_Multiport_Switch);
    /* End of Outputs for SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE' */
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch6'/copy1' */
    SET_D_TCTDTE_DeltaSetCroWiComp_rad(rtb_Div_f);
    /* Outputs for Atomic SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE'
                                                     *
                                                     * Block description for 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE':
                                                     *  X.2.1
                                                     */
    /* SignalConversion: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/branch9'/copy1' incorporates:
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Product: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS0_nu/Functionality/odtc'/Product'
         *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess/M_TCTDTE/Calc Single Track DiffEq Coefficitents/Y_TCTDTE_GLaDmcDenS0_nu/Functionality'/ip_lookup_fxpt_sfun_7'
         */
    SET_S_TCTDTE_MccGLaDmcDenS0_nu(rtb_ip_lookup_fxpt_sfun_7);
    /* End of Outputs for SubSystem: 'sda:TCTDTE/TCTDTE/TCTDTE_VehProcess'/M_TCTDTE' */
}
#include "Pse_TCTDTE.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
