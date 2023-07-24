/**************************************************************************
COPYRIGHT (C) $Date: 2019/05/28 12:51:36CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJPLN/TPLTJC_VEH/TPLTJC/i/project.pj $
$Log: TPLTJC.c  $
Revision 1.3 2019/05/28 12:51:36CEST Zhu, Qiangqiang (uid41532) 
automatically created
File          : TPLTJC
Generated on  : Wed 22.05.2019 at 15:12:32 (UTC+01:00)
MD5           : [263937307  1810245264  3015507998  2233728956 0](TPLTJC)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TPLTJC.h"
#include "calOptTrajektorie.h"
#include "TPLTJC_private.h"
#include "sda_sil_dummy.h"
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
#define TPLTJC_START_SEC_DATA_8
#include "TPLTJC_MemMap.h"
static uint8 BI_tpltjc_sfunc_MatrixInverseOK_nu;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch'/copy1' */
static uint8 BI_tpltjc_sfunc_MaxJerkOK_nu;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch2'/copy1' */
#define TPLTJC_STOP_SEC_DATA_8
#include "TPLTJC_MemMap.h"
#define TPLTJC_START_SEC_DATA_32
#include "TPLTJC_MemMap.h"
static float32 BI_tpltjc_Switch;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Switch/Functionality'/Switch' */
static float32 BI_tpltjc_Switch_l;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Switch1/Functionality'/Switch' */
static float32 BI_tpltjc_sfunc_TrajParam_nu[6];
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch4'/copy1' */
static float32 BI_tpltjc_sfunc_MaxJerkTraj_mps3;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch5'/copy1' */
static float32 BI_tpltjc_sfunc_MaxAclTraj_mps2;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch6'/copy1' */
static float32 BI_tpltjc_sfunc_TrajCalcTimeTrajEnd_sec;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch7'/copy1' */
static float32 BI_tpltjc_sfunc_ArcLengthTrajEnd_met;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch8'/copy1' */
static float32 BI_tpltjc_sfunc_OptimalCost_nu;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch9'/copy1' */
static float32 BI_tpltjc_P0;
/* 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/TriggeredPassP0'/P0' */
static float32 DW_tpltjc_UnitDelay_1_DSTATE;
static float32 DW_tpltjc_UnitDelay_2_DSTATE;
static float32 DW_tpltjc_UnitDelay_3_DSTATE;
static float32 DW_tpltjc_Unit_Delay3_DSTATE;
static float32 DW_tpltjc_Unit_Delay_DSTATE[6];
static float32 DW_tpltjc_Unit_Delay_DSTATE_b;
static float32 DW_tpltjc_Unit_Delay_DSTATE_i;
static float32 DW_tpltjc_Unit_Delay2_DSTATE;
static float32 DW_tpltjc_Unit_Delay1_DSTATE;
static float32 DW_tpltjc_UnitDelay1_DSTATE;
static float32 DW_tpltjc_UnitDelay2_DSTATE;
static float32 DW_tpltjc_UnitDelay_DSTATE;
static float32 DW_tpltjc_UnitDelay3_DSTATE;
#define TPLTJC_STOP_SEC_DATA_32
#include "TPLTJC_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TPLTJC/TPLTJC/INI'/TPLTJC_VehReset'
 * Block description for: 'sda:TPLTJC/TPLTJC/INI'/TPLTJC_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLTJC_VehReset
#include "Pse_TPLTJC.h"
/* Short description: Not synchronized with ARAMIS */
void TPLTJC_VehReset(void)
{
    /* Function local data */
    sint32 i;
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant'/Constant' */
    SET_S_TPLTJC_TrajDistY_met(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant1'/Constant' */
    SET_S_TPLTJC_TrajDistY1stDeriv_mps(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant10'/Constant' */
    SET_S_TPLTJC_YDt2TrjFmKpPrevDT_mps2(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant11'/Constant' */
    SET_S_TPLTJC_YDt3TrjFmKpPrevDT_mps3(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant12'/Constant' */
    SET_S_TPLTJC_YDt2TrjFmKpPrev_mps2(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant13'/Constant' */
    SET_S_TPLTJC_EndPointTrajectory_nu(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant14'/Constant' */
    SET_S_TPLTJC_TrajDistYFmPrev_met(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant15'/Constant' */
    SET_D_TPLTJC_PassedTrajLenPercent_nu(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant16'/Constant' */
    SET_D_TPLTJC_MaxJerkTraj_mps3(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant17'/Constant' */
    SET_D_TPLTJC_MaxJerkOK_nu(0U);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant18'/Constant' */
    SET_D_TPLTJC_MaxAclTraj_mps2(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant19'/Constant' */
    SET_D_TPLTJC_OptimalCost_nu(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant2'/Constant' */
    SET_S_TPLTJC_TrajDistY2ndDeriv_mps2(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant20'/Constant' */
    SET_D_TPLTJC_WeightTgtDistY_nu(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant21'/Constant' */
    SET_D_TPLTJC_WeightEndTime_nu(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant3'/Constant' */
    SET_S_TPLTJC_TrajDistY3rdDeriv_mps3(0.0F);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant4'/Constant' */
    SET_S_TPLTJC_QuStatusTrajPlan_nu(0U);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant5'/Constant' */
    for (i = 0; i < 6; i++) {
        SET_S_TPLTJC_TrajParam_nu((i),(0.0F));
    }
    /* End of Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant5'/Constant' */
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant6'/Constant' */
    SET_S_TPLTJC_TrajEnd_nu(0U);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant7'/Constant' */
    SET_S_TPLTJC_LengthOK_nu(0U);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant8'/Constant' */
    SET_S_TPLTJC_MatrixInverseOK_nu(0U);
    /* Constant: 'sda:TPLTJC/TPLTJC/INI/TPLTJC_VehReset/Constant9'/Constant' */
    SET_S_TPLTJC_YDtTrjFmHeadPrev_mps(0.0F);
}
#include "Pse_TPLTJC.h"
/*
 * Output and update for function-call system: 'sda:TPLTJC/TPLTJC'/TPLTJC_VehProcess'
 * Block description for: 'sda:TPLTJC/TPLTJC'/TPLTJC_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLTJC_VehProcess
#include "Pse_TPLTJC.h"
/* Short description: Not synchronized with ARAMIS */
void TPLTJC_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    calOptInTypeV3 rtb_OptInputStruct;
    calOptOutTypeV4 rtb_OptOutputStruct;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_ip_lookup_fxpt_sfun_7_m;
    float32 rtb_ip_lookup_fxpt_sfun_7_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_p;
    uint16 rtb_sfun_setbit;
    uint8 rtb_VectorConcatenate[9];
    float32 rtb_Switch_ob[6];
    float32 rtb_Mul_gr;
    float32 rtb_Mul_i2;
    float32 rtb_Switch_cz;
    float32 rtb_Mul_oc;
    float32 rtb_Sum_mn;
    float32 rtb_Switch_bt;
    float32 rtb_Mul_aa;
    float32 rtb_Switch_ny;
    float32 rtb_Switch_hg;
    float32 rtb_Sum_f;
    float32 rtb_Switch;
    float32 rtb_Switch_d;
    float32 rtb_Switch_c;
    float32 rtb_Switch2;
    float32 rtb_MathFunction_a;
    float32 rtb_MathFunction;
    float32 rtb_Switch_iu;
    float32 rtb_Switch_g;
    float32 rtb_Sum_jp;
    float32 rtb_Sum_mm;
    float32 rtb_Sum_ex;
    sint32 i;
    /* Outputs for Atomic SubSystem: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM'/M_TPLTJC'
         *
         * Block description for 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM'/M_TPLTJC':
         *  X.2.1.1
         */
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Inport: '<Root>/S_TPLCEN_ReplanTgtValues_nu'
         *  Inport: '<Root>/S_TPLFRT_CurDistY1stDeriv_mps'
         *  Inport: '<Root>/S_TPLFRT_CurDistY2ndDeriv_mps2'
         *  Inport: '<Root>/S_TPLFRT_CurDistY_met'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch3/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch4/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch5/Functionality'/Switch'
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit Delay'
         */
    if (((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) {
        rtb_Switch = GET_S_TPLFRT_CurDistY_met();
        rtb_Switch_d = GET_S_TPLFRT_CurDistY1stDeriv_mps();
        rtb_Switch_c = GET_S_TPLFRT_CurDistY2ndDeriv_mps2();
    } else if (((sint32)GET_S_TPLCEN_ReplanTgtValues_nu()) != 0) {
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch3/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_TPLFRT_TrajDistYPrev_met'
                 */
        rtb_Switch = GET_S_TPLFRT_TrajDistYPrev_met();
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch4/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_TPLFRT_TrajDistY1stToPrev_mps'
                 */
        rtb_Switch_d = GET_S_TPLFRT_TrajDistY1stToPrev_mps();
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch5/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_TPLFRT_TrajDistY2ndToPrev_mps2'
                 */
        rtb_Switch_c = GET_S_TPLFRT_TrajDistY2ndToPrev_mps2();
    } else {
        rtb_Switch = DW_tpltjc_UnitDelay_1_DSTATE;
        rtb_Switch_d = DW_tpltjc_UnitDelay_2_DSTATE;
        rtb_Switch_c = DW_tpltjc_UnitDelay_3_DSTATE;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Start_Values/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Constant1'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Constant1'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Relational Operator'
         *  RelationalOperator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Relational Operator2'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Switch2'
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay3'
         */
    if ((((sint32)GET_S_TPLCEN_ReplanCurValues_nu()) != 0) && (DW_tpltjc_Unit_Delay3_DSTATE <= 0.0F)) {
        rtb_Switch2 = GET_P_TPLTJC_AllowedTimetoCross_sec();
    } else if (DW_tpltjc_Unit_Delay3_DSTATE > GET_S_LCFRCV_SysCycleTimeVeh_sec()) {
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Switch2' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                 *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality/Sum/Functionality'/Sum'
                 */
        rtb_Switch2 = DW_tpltjc_Unit_Delay3_DSTATE - GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Switch2' incorporates:
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Constant2'
                 */
        rtb_Switch2 = 0.0F;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/TIMER_RE/Functionality'/Switch' */
    /* Outputs for Enabled SubSystem: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Calc_Trajectory_Parameters' incorporates:
         *  EnablePort: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters'/TriggerTrajectoryRecalculation'
         *
         * Block description for 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Calc_Trajectory_Parameters':
         *  X.2.1.1.3
         */
    /* Inport: '<Root>/S_TPLCEN_TrigTrajReplan_nu' */
    if (((sint32)GET_S_TPLCEN_TrigTrajReplan_nu()) > 0) {
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Application Parameter'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Application Parameter2'/Constant'
                 *  Inport: '<Root>/S_CSCLTA_WeightEndTime_nu'
                 *  Inport: '<Root>/S_CSCLTA_WeightTgtDistY_nu'
                 *  Inport: '<Root>/S_TPLFRT_TrajPlanningHorizon_sec'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WghtTgtDistYCharact_nu/Functionality/odtc'/Product'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WghtTgtTimeCharact_nu1/Functionality/odtc'/Product'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WeightEndTime_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WghtTgtDistYCharact_nu/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  S-Function (ip_lookup_fxpt_sfun_7): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WghtTgtTimeCharact_nu1/Functionality'/ip_lookup_fxpt_sfun_7'
                 *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Switch1/Functionality'/Switch'
                 */
        if (((sint32)GET_P_TPLTJC_ParamCostFctInternal_nu()) != 0) {
            BI_tpltjc_Switch = GET_P_TPLTJC_WeightTgtDistY_nu();
            /* S-Function Block sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WeightEndTime_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLTJC_PlanningHorizon_sec */
                FDPS_PTR_F32(GETA_X_TPLTJC_PlanningHorizon_sec(), GET_S_TPLFRT_TrajPlanningHorizon_sec(), &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_TPLTJC_WeightEndTime_nu(), &dps_result_ln);
            }
            BI_tpltjc_Switch_l = rtb_ip_lookup_fxpt_sfun_7;
        } else {
            /* S-Function Block sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WghtTgtDistYCharact_nu/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLTJC_WghtTgtDistYCustFct_nu */
                FDPS_PTR_F32(GETA_X_TPLTJC_WghtTgtDistYCustFct_nu(), GET_S_CSCLTA_WeightTgtDistY_nu(), &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_i = F32_PTR_IP1D (GETA_Y_TPLTJC_WghtTgtDistYCharact_nu(), &dps_result_ln);
            }
            BI_tpltjc_Switch = rtb_ip_lookup_fxpt_sfun_7_i;
            /* S-Function Block sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Y_TPLTJC_WghtTgtTimeCharact_nu1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_TPLTJC_WghtTgtTimeCustFct_nu */
                FDPS_PTR_F32(GETA_X_TPLTJC_WghtTgtTimeCustFct_nu(), GET_S_CSCLTA_WeightEndTime_nu(), &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_m = F32_PTR_IP1D (GETA_Y_TPLTJC_WghtTgtTimeCharact_nu(), &dps_result_ln);
            }
            BI_tpltjc_Switch_l = rtb_ip_lookup_fxpt_sfun_7_m;
        }
        /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Custom_Application_Parameters/Switch/Functionality'/Switch' */
        /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Add/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Application Parameter2'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Constant'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Constant2'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Constant3'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Constant6'/Constant'
                 *  MinMax: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Max/Functionality'/Max'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Divide/Functionality/Div'/Div'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Divide1/Functionality/Div'/Div'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Mul/Functionality'/Mul'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Mul2/Functionality'/Mul'
                 */
        rtb_MathFunction_a = ((GET_P_VEH_WidthWithMirrors_met() * GET_P_VEH_WidthWithMirrors_met()) / 16.0F) + ((GET_P_VEH_Length_met() * GET_P_VEH_Length_met()) / f32_max_f32_f32((float32)(((sint32) GET_P_TPLTJC_NumCircles_nu()) * ((sint32)GET_P_TPLTJC_NumCircles_nu())), 2.0F));
        /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Add1/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Constant1'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Constant4'/Constant'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Divide2/Functionality/Div'/Div'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/Mul3/Functionality'/Mul'
                 */
        rtb_MathFunction = rtb_MathFunction_a - ((GET_P_VEH_WidthWithMirrors_met() * GET_P_VEH_WidthWithMirrors_met()) / 16.0F);
        /* Sqrt: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/MathFunction/Functionality'/MathFunction' */
        rtb_MathFunction_a = f32_sqrt_f32(rtb_MathFunction_a);
        /* Sqrt: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Calc_Vehicle_Shape_Circle_Approximation/MathFunction1/Functionality'/MathFunction' */
        rtb_MathFunction = f32_sqrt_f32(rtb_MathFunction);
        /* S-Function Block sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Y_TPLTJC_MaxAclY_mps2/Functionality'/ip_lookup_fxpt_sfun_7 */
        {
            FDPS_RESULT dps_result_ln;
            /* Calculate value */
            /* Find indices on X Axis: X_TPLTJC_VehVelX_mps */
            FDPS_PTR_F32(GETA_X_TPLTJC_VehVelX_mps(), GET_S_LCFRCV_VehVelX_mps(), &dps_result_ln);
            /* Direct accesing curve (used as module input) */
            rtb_ip_lookup_fxpt_sfun_7_p = F32_PTR_IP1D(GETA_Y_TPLTJC_MaxAclY_mps2(), &dps_result_ln);
        }
        /* BusCreator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters'/OptInputStruct' incorporates:
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Application Parameter2'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Application Parameter3'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Constant'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Constant1'/Constant'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit1/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit2/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit3/Functionality'/Const_bit_sel_param'
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit4/Functionality'/Const_bit_sel_param'
                 *  Inport: '<Root>/S_CSCLTA_DistYTolLeTgtArea_met'
                 *  Inport: '<Root>/S_CSCLTA_DistYTolRiTgtArea_met'
                 *  Inport: '<Root>/S_CSCLTA_FTireAclMax_mps2'
                 *  Inport: '<Root>/S_CSCLTA_FTireAclMin_mps2'
                 *  Inport: '<Root>/S_CSCLTA_MaxJerkAllowed_mps3'
                 *  Inport: '<Root>/S_CSCLTA_ObstacleAclX_mps2'
                 *  Inport: '<Root>/S_CSCLTA_ObstacleDistX_met'
                 *  Inport: '<Root>/S_CSCLTA_ObstacleDistY_met'
                 *  Inport: '<Root>/S_CSCLTA_ObstacleVelX_mps'
                 *  Inport: '<Root>/S_CSCLTA_ObstacleWidth_met'
                 *  Inport: '<Root>/S_CSCLTA_TrajPlanServQu_nu'
                 *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
                 *  Inport: '<Root>/S_TPLCEN_DelayVehGui_sec'
                 *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
                 *  Inport: '<Root>/S_TPLFRT_LeftDistY_met'
                 *  Inport: '<Root>/S_TPLFRT_NumPointsCridrLeft_nu'
                 *  Inport: '<Root>/S_TPLFRT_NumTgtPoints_nu'
                 *  Inport: '<Root>/S_TPLFRT_PlanHorizonVisRange_sec'
                 *  Inport: '<Root>/S_TPLFRT_TgtDistY1stDeriv_mps'
                 *  Inport: '<Root>/S_TPLFRT_TgtDistY2ndDeriv_mps2'
                 *  Inport: '<Root>/S_TPLFRT_TgtDistY_met'
                 *  Inport: '<Root>/S_TPLFRT_TgtPoints_nu'
                 *  Inport: '<Root>/S_TPLFRT_TrajAclRefCurve_mps2'
                 *  Inport: '<Root>/S_TPLFRT_TrajPlanningHorizon_sec'
                 *  Inport: '<Root>/S_TPLFRT_TrajVelRefCurve_mps'
                 *  Inport: '<Root>/S_TPLLCO_LeftCorridorLength_met'
                 *  Inport: '<Root>/S_TPLLCO_LeftCorridorPosY0_met'
                 *  Inport: '<Root>/S_TPLLCO_RiCridrChngOfCrv_1pm2'
                 *  Inport: '<Root>/S_TPLLCO_RightCorridorCrv_1pm'
                 *  Inport: '<Root>/S_TPLLCO_RightCorridorLength_met'
                 *  MinMax: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Min1/Functionality'/Min'
                 *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Mul/Functionality'/Mul'
                 *  S-Function (sfun_getbit_77): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit/Functionality'/S-Function'
                 *  S-Function (sfun_getbit_77): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit1/Functionality'/S-Function'
                 *  S-Function (sfun_getbit_77): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit2/Functionality'/S-Function'
                 *  S-Function (sfun_getbit_77): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit3/Functionality'/S-Function'
                 *  S-Function (sfun_getbit_77): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Enable_Checks/get_bit4/Functionality'/S-Function'
                 */
        rtb_OptInputStruct.sfunc_DistYInit_nu = rtb_Switch;
        rtb_OptInputStruct.sfunc_DistY1stDerivInit_nu = rtb_Switch_d;
        rtb_OptInputStruct.sfunc_DistY2ndDerivInit_nu = rtb_Switch_c;
        rtb_OptInputStruct.sfunc_Kd = BI_tpltjc_Switch;
        rtb_OptInputStruct.sfunc_Kt = BI_tpltjc_Switch_l;
        rtb_OptInputStruct.sfunc_TrajCalcEgoVelX_mps = GET_S_LCFRCV_VehVelX_mps();
        rtb_OptInputStruct.sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm = GET_S_TPLLCO_RightCorridorCrv_1pm();
        rtb_OptInputStruct.sfunc_TolDistYRight_met = GET_S_CSCLTA_DistYTolRiTgtArea_met();
        rtb_OptInputStruct.sfunc_TolDistYLeft_met = GET_S_CSCLTA_DistYTolLeTgtArea_met();
        rtb_OptInputStruct.sfunc_CheckFtire_nu = ((uint8)flag_get_u8_u8 (GET_S_CSCLTA_TrajPlanServQu_nu(), ((uint8)2U)));
        rtb_OptInputStruct.sfunc_CheckCridrBoundaries_nu = ((uint8)flag_get_u8_u8 (GET_S_CSCLTA_TrajPlanServQu_nu(), ((uint8)0U)));
        rtb_OptInputStruct.sfunc_CheckObjects_nu = ((uint8)flag_get_u8_u8 (GET_S_CSCLTA_TrajPlanServQu_nu(), ((uint8)1U)));
        rtb_OptInputStruct.sfunc_CheckJerk_nu = ((uint8)flag_get_u8_u8 (GET_S_CSCLTA_TrajPlanServQu_nu(), ((uint8)3U)));
        rtb_OptInputStruct.sfunc_CheckLaneCross_nu = ((uint8)flag_get_u8_u8 (GET_S_CSCLTA_TrajPlanServQu_nu(), ((uint8)4U)));
        rtb_OptInputStruct.sfunc_AclPotVecMin_mps2 = GET_S_CSCLTA_FTireAclMin_mps2() * GET_P_TPLTJC_FTireAclMinScaling_nu();
        rtb_OptInputStruct.sfunc_AclPotVecMax_mps2 = f32_min_f32_f32 (rtb_ip_lookup_fxpt_sfun_7_p, GET_S_CSCLTA_FTireAclMax_mps2());
        for (i = 0; i < 15; i++) {
            rtb_OptInputStruct.sfunc_TrajCalcTgtDistY_met[i] = GET_S_TPLFRT_TgtDistY_met((i));
            rtb_OptInputStruct.sfunc_TrajCalcTgtDistY1stDeriv_nu[i] = GET_S_TPLFRT_TgtDistY1stDeriv_mps((i));
            rtb_OptInputStruct.sfunc_TrajCalcTgtDistY2ndDeriv_nu[i] = GET_S_TPLFRT_TgtDistY2ndDeriv_mps2((i));
            rtb_OptInputStruct.sfunc_teTrajCalcTgt_nu[i] = GET_S_TPLFRT_TgtPoints_nu ((i));
        }
        rtb_OptInputStruct.sfunc_TrajCalcNumTgtPoints_nu = GET_S_TPLFRT_NumTgtPoints_nu();
        rtb_OptInputStruct.sfunc_TrajCalcCircleRadius_met = rtb_MathFunction_a;
        rtb_OptInputStruct.sfunc_TrajCalcCircleDistance_met = rtb_MathFunction;
        rtb_OptInputStruct.sfunc_TrajCalcCridrRightSeg1_Length_met = GET_S_TPLLCO_RightCorridorLength_met();
        rtb_OptInputStruct.sfunc_TrajCalcCridrLeftSeg1_Length_met = GET_S_TPLLCO_LeftCorridorLength_met();
        rtb_OptInputStruct.sfunc_Obstacle_DistX_met = GET_S_CSCLTA_ObstacleDistX_met ();
        rtb_OptInputStruct.sfunc_Obstacle_DistY_met = GET_S_CSCLTA_ObstacleDistY_met ();
        rtb_OptInputStruct.sfunc_Obstacle_Width_met = GET_S_CSCLTA_ObstacleWidth_met ();
        for (i = 0; i < 100; i++) {
            rtb_OptInputStruct.sfunc_TrajCalcDistYLeft_met[i] = GET_S_TPLFRT_LeftDistY_met((i));
        }
        rtb_OptInputStruct.sfunc_ReplanModeArcLength_nu = GET_S_TPLCEN_ReplanModeArcLength_nu();
        rtb_OptInputStruct.sfunc_WeightArcLengthPlan_nu = GET_P_TPLTJC_WeightDistBased_nu();
        rtb_OptInputStruct.sfunc_TrajCalcPlanHorizonTraj_sec = GET_S_TPLFRT_TrajPlanningHorizon_sec();
        rtb_OptInputStruct.sfunc_TrajCalcPlanHorizonVisibility_sec = GET_S_TPLFRT_PlanHorizonVisRange_sec();
        rtb_OptInputStruct.sfunc_TrajCalcTrajVel_mps = GET_S_TPLFRT_TrajVelRefCurve_mps();
        rtb_OptInputStruct.sfunc_TrajCalcTrajAcl_mps2 = GET_S_TPLFRT_TrajAclRefCurve_mps2();
        rtb_OptInputStruct.sfunc_TrajCalcDeadTime_sec = GET_S_TPLCEN_DelayVehGui_sec ();
        rtb_OptInputStruct.sfunc_TrajCalcNCircles_nu = GET_P_TPLTJC_NumCircles_nu();
        rtb_OptInputStruct.sfunc_TrajCalcNumCridrPointsLeft_nu = GET_S_TPLFRT_NumPointsCridrLeft_nu();
        rtb_OptInputStruct.sfunc_TrajCalcObjVelX_mps = GET_S_CSCLTA_ObstacleVelX_mps ();
        rtb_OptInputStruct.sfunc_TrajCalcObjAclX_mps2 = GET_S_CSCLTA_ObstacleAclX_mps2();
        rtb_OptInputStruct.sfunc_CrvChng_1pm2 = GET_S_TPLLCO_RiCridrChngOfCrv_1pm2();
        rtb_OptInputStruct.sfunc_AllwdJerkMax_mps3 = GET_S_CSCLTA_MaxJerkAllowed_mps3();
        rtb_OptInputStruct.sfunc_LaneWidth_met = GET_S_TPLLCO_LeftCorridorPosY0_met();
        rtb_OptInputStruct.sfunc_VehicleWidth_met = GET_P_VEH_Width_met();
        rtb_OptInputStruct.sfunc_AllowedTimetoCross_sec = rtb_Switch2;
        /* End of BusCreator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters'/OptInputStruct' */
        /* S-Function (sfun_calOptTrajektorie): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters'/sfun_calOptTrajektorie' */
        rtb_OptOutputStruct = TrajCalc_CalcOptTrajectory((calOptInTypeV3*) &rtb_OptInputStruct);
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[0] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_FtireMinOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT1/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT1/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[1] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_FtireMaxOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT2/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT2/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[2] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_CollDetRightOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT3/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT3/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[3] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_CollDetLeftOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT4/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT4/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[4] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_CollDetObjOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT5/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT5/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[5] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_MatrixInverseOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT6/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT6/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[6] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_TrajLengthOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT7/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT7/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[7] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_MaxJerkOK_nu) != 0));
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT8/Functionality'/Data Type Conversion' incorporates:
                 *  Logic: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/NOT8/Functionality'/NOT'
                 */
        rtb_VectorConcatenate[8] = (uint8)(!(((sint32) rtb_OptOutputStruct.sfunc_LaneCrossOK_nu) != 0));
        /* S-Function (sfun_setbit): 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/set_bit1/Functionality'/sfun_setbit' */
        {
            /* mask selection vector from setbit block */
            uint16 temp = ((uint16)0U);
            {
                uint16 set_mask = 0;
                uint16 reset_mask = 0;
                const uint8 selection_vec[9] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U };
                {
                    sint32 i1;
                    const uint8 *u1 = &rtb_VectorConcatenate[0];
                    for (i1=0; i1 < 9; i1++) {
                        if (!u1[i1]) {
                            /* reset */
                            reset_mask = reset_mask | u16_bit_u8( selection_vec [i1]);
                        } else {
                            /* set */
                            set_mask = set_mask | u16_bit_u8( selection_vec [i1]);
                        }
                    }
                }
                temp = (temp & ~reset_mask) | set_mask ;
            }
            rtb_sfun_setbit = temp;
        }
        /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/Map_TrajCalc_QualifierStatus/set_bit1/Functionality'/DTC_out' */
        SET_S_TPLTJC_QuStatusTrajPlan_nu(rtb_sfun_setbit);
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch'/copy1' */
        BI_tpltjc_sfunc_MatrixInverseOK_nu = rtb_OptOutputStruct.sfunc_MatrixInverseOK_nu;
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch1'/copy1' */
        SET_S_TPLTJC_LengthOK_nu(rtb_OptOutputStruct.sfunc_TrajLengthOK_nu);
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch2'/copy1' */
        BI_tpltjc_sfunc_MaxJerkOK_nu = rtb_OptOutputStruct.sfunc_MaxJerkOK_nu;
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch4'/copy1' */
        for (i = 0; i < 6; i++) {
            BI_tpltjc_sfunc_TrajParam_nu[i] = rtb_OptOutputStruct.sfunc_TrajParam_nu[i];
        }
        /* End of SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch4'/copy1' */
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch5'/copy1' */
        BI_tpltjc_sfunc_MaxJerkTraj_mps3 = rtb_OptOutputStruct.sfunc_MaxJerkTraj_mps3;
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch6'/copy1' */
        BI_tpltjc_sfunc_MaxAclTraj_mps2 = rtb_OptOutputStruct.sfunc_MaxAclTraj_mps2;
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch7'/copy1' */
        BI_tpltjc_sfunc_TrajCalcTimeTrajEnd_sec = rtb_OptOutputStruct.sfunc_TrajCalcTimeTrajEnd_sec;
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch8'/copy1' */
        BI_tpltjc_sfunc_ArcLengthTrajEnd_met = rtb_OptOutputStruct.sfunc_ArcLengthTrajEnd_met;
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_Trajectory_Parameters/branch9'/copy1' */
        BI_tpltjc_sfunc_OptimalCost_nu = rtb_OptOutputStruct.sfunc_OptimalCost_nu;
    }
    /* End of Outputs for SubSystem: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Calc_Trajectory_Parameters' */
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Switch2/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay'
         */
    for (i = 0; i < 6; i++) {
        if (((sint32)BI_tpltjc_sfunc_MatrixInverseOK_nu) != 0) {
            rtb_Switch_ob[i] = BI_tpltjc_sfunc_TrajParam_nu[i];
        } else {
            rtb_Switch_ob[i] = DW_tpltjc_Unit_Delay_DSTATE[i];
        }
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Switch2/Functionality'/Switch' */
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Product/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_TPLFRT_TrajVelRefCurve_mps'
         */
    rtb_Switch = GET_S_TPLFRT_TrajVelRefCurve_mps() * GET_S_LCFRCV_SysCycleTimeVeh_sec();
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Distance_with_upper_Limit/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Inport: '<Root>/S_TPLCEN_TrigTrajReplan_nu'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Time_with_upper_Limit/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Distance_with_upper_Limit'/Unit_Delay'
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Time_with_upper_Limit'/Unit_Delay'
         */
    if (((sint32)GET_S_TPLCEN_TrigTrajReplan_nu()) != 0) {
        rtb_Switch_d = rtb_Switch;
        rtb_Switch_c = GET_S_LCFRCV_SysCycleTimeVeh_sec();
    } else {
        rtb_Switch_d = DW_tpltjc_Unit_Delay_DSTATE_b;
        rtb_Switch_c = DW_tpltjc_Unit_Delay_DSTATE_i;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Distance_with_upper_Limit/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Application Parameter1'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
         *  MinMax: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Distance_with_upper_Limit/MinMax/Functionality'/Min'
         *  MinMax: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Time_with_upper_Limit/MinMax/Functionality'/Min'
         */
    if (((sint32)GET_S_TPLCEN_ReplanModeArcLength_nu()) != 0) {
        rtb_MathFunction_a = f32_min_f32_f32(rtb_Switch_d, GET_P_TPLTJC_MaxArcLength_met());
    } else {
        rtb_MathFunction_a = f32_min_f32_f32(rtb_Switch_c, GET_P_TPLTJC_TMax_sec());
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Switch/Functionality'/Switch' */
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem/Product18/Functionality'/Mul' */
    rtb_MathFunction = rtb_MathFunction_a * rtb_MathFunction_a;
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem/Product22/Functionality'/Mul' */
    rtb_Mul_gr = rtb_MathFunction * rtb_MathFunction_a;
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem/Product23/Functionality'/Mul' */
    rtb_Mul_i2 = rtb_Mul_gr * rtb_MathFunction_a;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Sum4/Functionality'/Sum' incorporates:
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Product/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Product1/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Product2/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Product3/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Product4/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem/Product24/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY/Sum3/Functionality'/Sum'
         */
    rtb_Sum_f = (((((rtb_Switch_ob[1] * rtb_MathFunction_a) + rtb_Switch_ob[0]) + (rtb_Switch_ob[2] * rtb_MathFunction)) + (rtb_Switch_ob[3] * rtb_Mul_gr)) + (rtb_Switch_ob[4] * rtb_Mul_i2)) + ((rtb_Mul_i2 * rtb_MathFunction_a) * rtb_Switch_ob[5]);
    /* Outputs for Enabled SubSystem: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/TriggeredPassP0' incorporates:
         *  EnablePort: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/TriggeredPassP0'/Enable'
         *
         * Block description for 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/TriggeredPassP0':
         *  X.2.1.1.1.2.10
         */
    /* Inport: '<Root>/S_TPLCEN_TrigCustFctActn_nu' */
    if (((sint32)GET_S_TPLCEN_TrigCustFctActn_nu()) > 0) {
        /* Inport: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/TriggeredPassP0'/P0' */
        BI_tpltjc_P0 = rtb_Switch_ob[0];
    }
    /* End of Inport: '<Root>/S_TPLCEN_TrigCustFctActn_nu' */
    /* End of Outputs for SubSystem: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/TriggeredPassP0' */
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Switch1/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay1'
         *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay2'
         */
    if (((sint32)BI_tpltjc_sfunc_MatrixInverseOK_nu) != 0) {
        rtb_Switch_iu = BI_tpltjc_sfunc_ArcLengthTrajEnd_met;
        rtb_Switch_g = BI_tpltjc_sfunc_TrajCalcTimeTrajEnd_sec;
    } else {
        rtb_Switch_iu = DW_tpltjc_Unit_Delay2_DSTATE;
        rtb_Switch_g = DW_tpltjc_Unit_Delay1_DSTATE;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
         */
    if (((sint32)GET_S_TPLCEN_ReplanModeArcLength_nu()) != 0) {
        rtb_Switch_cz = rtb_Switch_iu;
    } else {
        rtb_Switch_cz = rtb_Switch_g;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Subsystem/Product18/Functionality'/Mul' */
    rtb_Sum_jp = rtb_Switch_cz * rtb_Switch_cz;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Sum1/Functionality'/Sum' incorporates:
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Product24/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Product25/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Sum/Functionality'/Sum'
         */
    rtb_Sum_mn = ((rtb_Switch_ob[1] * rtb_Switch_cz) + rtb_Switch_ob[0]) + (rtb_Switch_ob[2] * rtb_Sum_jp);
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Subsystem/Product22/Functionality'/Mul' */
    rtb_Sum_jp *= rtb_Switch_cz;
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Product23/Functionality'/Mul' */
    rtb_Mul_oc = rtb_Switch_ob[3] * rtb_Sum_jp;
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Subsystem/Product23/Functionality'/Mul' */
    rtb_Sum_jp *= rtb_Switch_cz;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Subtract1/Functionality'/Sum' incorporates:
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Product18/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Product22/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Subsystem/Product24/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Sum3/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/Sum4/Functionality'/Sum'
         */
    rtb_Sum_jp = (((rtb_Sum_mn + rtb_Mul_oc) + (rtb_Switch_ob[4] * rtb_Sum_jp)) + ((rtb_Sum_jp * rtb_Switch_cz) * rtb_Switch_ob[5])) - BI_tpltjc_P0;
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Divide/Functionality/DivDefault'/Switch' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Divide/In3'/Constant'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Divide/Functionality/DivDefault'/Div'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Subtract/Functionality'/Sum'
         */
    if (rtb_Sum_jp != 0.0F) {
        rtb_Sum_jp = (rtb_Sum_f - BI_tpltjc_P0) / rtb_Sum_jp;
    } else {
        rtb_Sum_jp = 100000.0F;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Divide/Functionality/DivDefault'/Switch' */
    /* Abs: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcPassedTrajLenPercentage/CalcPassedTrajLenPercentage/Abs/Functionality'/Abs' */
    SET_D_TPLTJC_PassedTrajLenPercent_nu(f32_abs_f32(rtb_Sum_jp));
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch3/Functionality'/Switch' incorporates:
                                                                     *  Inport: '<Root>/S_TPLCEN_PredictionTimeCrv_sec'
                                                                     *  Inport: '<Root>/S_TPLCEN_TrigTrajReplan_nu'
                                                                     *  Inport: '<Root>/S_TPLFRT_PreviewTimeHeading_sec'
                                                                     *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch4/Functionality'/Switch'
                                                                     *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay1'
                                                                     *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay2'
                                                                     */
    if (((sint32)GET_S_TPLCEN_TrigTrajReplan_nu()) != 0) {
        rtb_Sum_mn = GET_S_TPLFRT_PreviewTimeHeading_sec();
        rtb_Mul_oc = GET_S_TPLCEN_PredictionTimeCrv_sec();
    } else {
        rtb_Sum_mn = DW_tpltjc_UnitDelay1_DSTATE;
        rtb_Mul_oc = DW_tpltjc_UnitDelay2_DSTATE;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch3/Functionality'/Switch' */
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Add1/Functionality'/Sum' */
    rtb_Sum_jp = rtb_MathFunction_a + rtb_Sum_mn;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Add2/Functionality'/Sum' */
    rtb_Sum_ex = rtb_MathFunction_a + rtb_Mul_oc;
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
         *  RelationalOperator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Relational Operator2/Functionality'/LE'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch11/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch12/Functionality'/Switch'
         */
    if (((sint32)GET_S_TPLCEN_ReplanModeArcLength_nu()) != 0) {
        rtb_Sum_jp = rtb_MathFunction_a;
    } else {
        if ((((sint32)GET_P_TPLTJC_TimeTrajEndEnable_nu()) != 0) && (!(rtb_Sum_jp <= rtb_Switch_g))) {
            /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch12/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch11/Functionality'/Switch'
                         */
            rtb_Sum_jp = rtb_Switch_g;
        }
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch/Functionality'/Switch' */
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem1/Product18/Functionality'/Mul' */
    rtb_Switch_bt = rtb_Sum_jp * rtb_Sum_jp;
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem1/Product22/Functionality'/Mul' */
    rtb_Mul_aa = rtb_Switch_bt * rtb_Sum_jp;
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem1/Product23/Functionality'/Mul' */
    rtb_Sum_mm = rtb_Mul_aa * rtb_Sum_jp;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Sum4/Functionality'/Sum' incorporates:
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Product/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Product1/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Product2/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Product3/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Product4/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem1/Product1/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1/Sum3/Functionality'/Sum'
         */
    SET_S_TPLTJC_TrajDistYFmPrev_met((((((rtb_Switch_ob[1] * rtb_Sum_jp) + rtb_Switch_ob[0]) + (rtb_Switch_ob[2] * rtb_Switch_bt)) + (rtb_Switch_ob[3] * rtb_Mul_aa)) + (rtb_Switch_ob[4] * rtb_Sum_mm)) + ((rtb_Sum_mm * rtb_Sum_jp) * rtb_Switch_ob[5]));
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Sum3/Functionality'/Sum' incorporates:
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Constant14'/Constant'
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Constant15'/Constant'
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Constant16'/Constant'
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Constant17'/Constant'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product26/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product27/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product28/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product29/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product30/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product31/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product32/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product33/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Product34/Functionality'/Mul'
                                            *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Sum/Functionality'/Sum'
                                            *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Sum1/Functionality'/Sum'
                                            *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv/Sum2/Functionality'/Sum'
                                            */
    rtb_Mul_i2 = (((((rtb_Switch_ob[2] * rtb_MathFunction_a) * 2.0F) + rtb_Switch_ob[1]) + ((rtb_Switch_ob[3] * rtb_MathFunction) * 3.0F)) + ((rtb_Switch_ob[4] * rtb_Mul_gr) * 4.0F)) + ((rtb_Switch_ob[5] * rtb_Mul_i2) * 5.0F);
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Sum3/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Constant14'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Constant15'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Constant16'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Constant17'/Constant'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product26/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product27/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product28/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product29/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product30/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product31/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product32/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product33/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Product34/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY1stDeriv1/Sum2/Functionality'/Sum'
         */
    SET_S_TPLTJC_YDtTrjFmHeadPrev_mps((((((rtb_Switch_ob[2] * rtb_Sum_jp) * 2.0F) + rtb_Switch_ob[1]) + ((rtb_Switch_ob[3] * rtb_Switch_bt) * 3.0F)) + ((rtb_Switch_ob[4] * rtb_Mul_aa) * 4.0F)) + ((rtb_Switch_ob[5] * rtb_Sum_mm) * 5.0F));
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch2/Functionality'/Switch' incorporates:
                                            *  Inport: '<Root>/S_TPLCEN_DelayVehGui_sec'
                                            *  Inport: '<Root>/S_TPLCEN_PredictionTimeCrv_sec'
                                            *  Inport: '<Root>/S_TPLCEN_TrigTrajReplan_nu'
                                            *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch7/Functionality'/Switch'
                                            *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay'
                                            *  UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay3'
                                            */
    if (((sint32)GET_S_TPLCEN_TrigTrajReplan_nu()) != 0) {
        rtb_Switch_ny = GET_S_TPLCEN_PredictionTimeCrv_sec();
        rtb_Switch_hg = GET_S_TPLCEN_DelayVehGui_sec();
    } else {
        rtb_Switch_ny = DW_tpltjc_UnitDelay_DSTATE;
        rtb_Switch_hg = DW_tpltjc_UnitDelay3_DSTATE;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch2/Functionality'/Switch' */
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Sum1/Functionality'/Sum' incorporates:
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Sum/Functionality'/Sum'
         */
    rtb_Sum_mm = (rtb_MathFunction_a + rtb_Switch_ny) + rtb_Switch_hg;
    /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Application Parameter2'/Constant'
         *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
         *  RelationalOperator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Relational Operator1/Functionality'/LE'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch10/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch5/Functionality'/Switch'
         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch9/Functionality'/Switch'
         */
    if (((sint32)GET_S_TPLCEN_ReplanModeArcLength_nu()) != 0) {
        rtb_Sum_mm = rtb_MathFunction_a;
        rtb_Switch_bt = rtb_MathFunction_a;
    } else {
        if ((((sint32)GET_P_TPLTJC_TimeTrajEndEnable_nu()) != 0) && (!(rtb_Sum_mm <= rtb_Switch_g))) {
            /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch9/Functionality'/Switch' incorporates:
                         *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch10/Functionality'/Switch'
                         */
            rtb_Sum_mm = rtb_Switch_g;
        }
        /* Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Application Parameter1'/Constant'
                 *  RelationalOperator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Relational Operator/Functionality'/LE'
                 *  Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch6/Functionality'/Switch'
                 */
        if ((((sint32)GET_P_TPLTJC_TimeTrajEndEnable_nu()) != 0) && (!(rtb_Sum_ex <= rtb_Switch_g))) {
            rtb_Sum_ex = rtb_Switch_g;
        }
        /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch8/Functionality'/Switch' */
        rtb_Switch_bt = rtb_Sum_ex;
    }
    /* End of Switch: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Switch1/Functionality'/Switch' */
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem2/Product18/Functionality'/Mul' */
    rtb_Mul_aa = rtb_Sum_mm * rtb_Sum_mm;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Constant18'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Constant19'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Constant20'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Constant21'/Constant'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product35/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product36/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product37/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product38/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product39/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product40/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Product41/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem2/Product22/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv1/Sum1/Functionality'/Sum'
         */
    SET_S_TPLTJC_YDt2TrjFmKpPrevDT_mps2(((((rtb_Switch_ob[3] * rtb_Sum_mm) * 6.0F) + (rtb_Switch_ob[2] * 2.0F)) + ((rtb_Switch_ob[4] * rtb_Mul_aa) * 12.0F)) + (((rtb_Mul_aa * rtb_Sum_mm) * rtb_Switch_ob[5]) * 20.0F));
    /* Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem4/Product18/Functionality'/Mul' */
    rtb_Sum_jp = rtb_Switch_bt * rtb_Switch_bt;
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Constant18'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Constant19'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Constant20'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Constant21'/Constant'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product35/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product36/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product37/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product38/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product39/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product40/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Product41/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem4/Product22/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Sum/Functionality'/Sum'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv2/Sum1/Functionality'/Sum'
         */
    SET_S_TPLTJC_YDt2TrjFmKpPrev_mps2(((((rtb_Switch_ob[3] * rtb_Switch_bt) * 6.0F) + (rtb_Switch_ob[2] * 2.0F)) + ((rtb_Switch_ob[4] * rtb_Sum_jp) * 12.0F)) + (((rtb_Sum_jp * rtb_Switch_bt) * rtb_Switch_ob[5]) * 20.0F));
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Sum2/Functionality'/Sum' incorporates:
                                                                      *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Constant18'/Constant'
                                                                      *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Constant19'/Constant'
                                                                      *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Constant20'/Constant'
                                                                      *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Constant21'/Constant'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product35/Functionality'/Mul'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product36/Functionality'/Mul'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product37/Functionality'/Mul'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product38/Functionality'/Mul'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product39/Functionality'/Mul'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product40/Functionality'/Mul'
                                                                      *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Product41/Functionality'/Mul'
                                                                      *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Sum/Functionality'/Sum'
                                                                      *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/CalcTrajDistY2ndDeriv3/Sum1/Functionality'/Sum'
                                                                      */
    rtb_Mul_gr = ((((rtb_Switch_ob[3] * rtb_MathFunction_a) * 6.0F) + (rtb_Switch_ob[2] * 2.0F)) + ((rtb_Switch_ob[4] * rtb_MathFunction) * 12.0F)) + ((rtb_Switch_ob[5] * rtb_Mul_gr) * 20.0F);
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Sum1/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Constant1'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Constant2'/Constant'
         *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Constant3'/Constant'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Product18/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Product22/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Product23/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Product24/Functionality'/Mul'
         *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Product25/Functionality'/Mul'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem3/Sum/Functionality'/Sum'
         */
    SET_S_TPLTJC_TrajDistY3rdDeriv_mps3((((rtb_Switch_ob[4] * rtb_MathFunction_a) * 24.0F) + (rtb_Switch_ob[3] * 6.0F)) + ((rtb_Switch_ob[5] * rtb_MathFunction) * 60.0F));
    /* Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Sum1/Functionality'/Sum' incorporates:
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Constant1'/Constant'
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Constant2'/Constant'
                                            *  Constant: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Constant3'/Constant'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Product18/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Product22/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Product23/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Product24/Functionality'/Mul'
                                            *  Product: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Product25/Functionality'/Mul'
                                            *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj/Subsystem5/Sum/Functionality'/Sum'
                                            */
    SET_S_TPLTJC_YDt3TrjFmKpPrevDT_mps3((((rtb_Switch_ob[4] * rtb_Sum_mm) * 24.0F) + (rtb_Switch_ob[3] * 6.0F)) + ((rtb_Switch_ob[5] * rtb_Mul_aa) * 60.0F));
    /* DataTypeConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/DTC'/Data Type Conversion' incorporates:
                                                                          *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
                                                                          *  RelationalOperator: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Relational Operator/Functionality'/GE'
                                                                          *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Add/Functionality'/Sum'
                                                                          */
    SET_S_TPLTJC_TrajEnd_nu((uint8)(rtb_MathFunction_a >= (rtb_Switch_cz - GET_S_LCFRCV_SysCycleTimeVeh_sec())));
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch'/copy1' */
    SET_S_TPLTJC_MatrixInverseOK_nu(BI_tpltjc_sfunc_MatrixInverseOK_nu);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch10'/copy1' */
    SET_D_TPLTJC_WeightTgtDistY_nu(BI_tpltjc_Switch);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch11'/copy1' */
    SET_D_TPLTJC_WeightEndTime_nu(BI_tpltjc_Switch_l);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch2'/copy1' */
    SET_D_TPLTJC_MaxJerkOK_nu(BI_tpltjc_sfunc_MaxJerkOK_nu);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch3'/copy1' */
    SET_D_TPLTJC_MaxJerkTraj_mps3(BI_tpltjc_sfunc_MaxJerkTraj_mps3);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch4'/copy1' */
    SET_D_TPLTJC_MaxAclTraj_mps2(BI_tpltjc_sfunc_MaxAclTraj_mps2);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch5'/copy1' */
    SET_S_TPLTJC_EndPointTrajectory_nu(rtb_Switch_cz);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch6'/copy1' */
    SET_S_TPLTJC_TrajDistY_met(rtb_Sum_f);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch7'/copy1' */
    SET_S_TPLTJC_TrajDistY1stDeriv_mps(rtb_Mul_i2);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch8'/copy1' */
    SET_S_TPLTJC_TrajDistY2ndDeriv_mps2(rtb_Mul_gr);
    /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch9'/copy1' */
    SET_D_TPLTJC_OptimalCost_nu(BI_tpltjc_sfunc_OptimalCost_nu);
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit Delay' */
    DW_tpltjc_UnitDelay_1_DSTATE = rtb_Sum_f;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit Delay' */
    DW_tpltjc_UnitDelay_2_DSTATE = rtb_Mul_i2;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit Delay' */
    DW_tpltjc_UnitDelay_3_DSTATE = rtb_Mul_gr;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay3' */
    DW_tpltjc_Unit_Delay3_DSTATE = rtb_Switch2;
    for (i = 0; i < 6; i++) {
        /* SignalConversion: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/branch1'/copy1' */
        SET_S_TPLTJC_TrajParam_nu((i),(rtb_Switch_ob[i]));
        /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay' */
        DW_tpltjc_Unit_Delay_DSTATE[i] = rtb_Switch_ob[i];
    }
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Distance_with_upper_Limit'/Unit_Delay' incorporates:
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Distance_with_upper_Limit/Add/Functionality'/Sum'
         */
    DW_tpltjc_Unit_Delay_DSTATE_b = rtb_Switch + rtb_Switch_d;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Time_with_upper_Limit'/Unit_Delay' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeVeh_sec'
         *  Sum: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/Calc_TrajectoryEnd_Time_ArcLength_and_Flags/Accu_Time_with_upper_Limit/Add/Functionality'/Sum'
         */
    DW_tpltjc_Unit_Delay_DSTATE_i = GET_S_LCFRCV_SysCycleTimeVeh_sec() + rtb_Switch_c;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay2' */
    DW_tpltjc_Unit_Delay2_DSTATE = rtb_Switch_iu;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC'/Unit_Delay1' */
    DW_tpltjc_Unit_Delay1_DSTATE = rtb_Switch_g;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay1' */
    DW_tpltjc_UnitDelay1_DSTATE = rtb_Sum_mn;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay2' */
    DW_tpltjc_UnitDelay2_DSTATE = rtb_Mul_oc;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay' */
    DW_tpltjc_UnitDelay_DSTATE = rtb_Switch_ny;
    /* Update for UnitDelay: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM/M_TPLTJC/CalcLatTraj_PassedTrajLen/CalcTraj'/Unit Delay3' */
    DW_tpltjc_UnitDelay3_DSTATE = rtb_Switch_hg;
    /* End of Outputs for SubSystem: 'sda:TPLTJC/TPLTJC/TPLTJC_VehProcess/OPM'/M_TPLTJC' */
}
#include "Pse_TPLTJC.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
