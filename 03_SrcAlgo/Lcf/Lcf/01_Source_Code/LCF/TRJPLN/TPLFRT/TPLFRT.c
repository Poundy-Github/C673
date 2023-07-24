/**************************************************************************
COPYRIGHT (C) $Date: 2019/06/14 09:58:08CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TRJPLN/TPLFRT_VEH/TPLFRT/i/project.pj $
$Log: TPLFRT.c  $
Revision 1.5 2019/06/14 09:58:08CEST Zhu, Qiangqiang (uid41532) 
automatically created
File          : TPLFRT
Generated on  : Fri 14.06.2019 at 09:38:32 (UTC+01:00)
MD5           : [2442643163  2633341575  3607572079   430551490 0](TPLFRT)
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
#include "TPLFRT.h"
#include "calFrenetTransformation.h"
#include "sda_sil_dummy.h"
#include "TPLFRT_Private.h"
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
#define TPLFRT_START_SEC_DATA_8
#include "TPLFRT_MemMap.h"
static uint8 DW_tplfrt_UnitDelay_DSTATE_j;
#define TPLFRT_STOP_SEC_DATA_8
#include "TPLFRT_MemMap.h"
#define TPLFRT_START_SEC_DATA_32
#include "TPLFRT_MemMap.h"
static float32 DW_tplfrt_UnitDelay_DSTATE;
static float32 DW_tplfrt_UnitDelay1_DSTATE;
static float32 DW_tplfrt_UnitDelay6_DSTATE[15];
static float32 DW_tplfrt_UnitDelay5_DSTATE[15];
static float32 DW_tplfrt_UnitDelay4_DSTATE[15];
static float32 DW_tplfrt_UnitDelay1_DSTATE_c[15];
static float32 DW_tplfrt_UnitDelay2_DSTATE;
static float32 DW_tplfrt_UnitDelay3_DSTATE;
#define TPLFRT_STOP_SEC_DATA_32
#include "TPLFRT_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TPLFRT/TPLFRT/INI'/TPLFRT_VehReset'
 * Block description for: 'sda:TPLFRT/TPLFRT/INI'/TPLFRT_VehReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLFRT_VehReset
#include "Pse_TPLFRT.h"
/* Short description: Not synchronized with ARAMIS */
void TPLFRT_VehReset(void)
{
    /* Function local data */
    sint32 i;
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant'/Constant' */
    SET_S_TPLFRT_CurDistY_met(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant1'/Constant' */
    SET_S_TPLFRT_CurDistY1stDeriv_mps(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant10'/Constant' */
    SET_S_TPLFRT_TrajDistYPrev_met(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant11'/Constant' */
    SET_S_TPLFRT_TrajDistY1stToPrev_mps(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant12'/Constant' */
    SET_S_TPLFRT_TrajDistY2ndToPrev_mps2(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant13'/Constant' */
    SET_S_TPLFRT_NumTgtPoints_nu(0U);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant14'/Constant' */
    SET_S_TPLFRT_TrajPlanningHorizon_sec(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant15'/Constant' */
    SET_S_TPLFRT_DistY1stToDevHead_mps(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant16'/Constant' */
    SET_S_TPLFRT_CurDistYPreview_met(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant17'/Constant' */
    SET_S_TPLFRT_CurDistY1stToPrev_mps(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant18'/Constant' */
    SET_S_TPLFRT_PreviewTimeHeading_sec(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant19'/Constant' */
    SET_S_TPLFRT_PlanHorizonVisRange_sec(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant2'/Constant' */
    SET_S_TPLFRT_CurDistY2ndDeriv_mps2(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant20'/Constant' */
    SET_S_TPLFRT_NumPointsCridrLeft_nu(0U);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant21'/Constant' */
    SET_S_TPLFRT_DistY2ndToDevHead_mps2(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant3'/Constant' */
    SET_S_TPLFRT_TrajVelRefCurve_mps(0.0F);
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant4'/Constant' */
    SET_S_TPLFRT_TrajAclRefCurve_mps2(0.0F);
    for (i = 0; i < 15; i++) {
        /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant5'/Constant' */
        SET_S_TPLFRT_TgtDistY_met((i),(0.0F));
        /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant6'/Constant' */
        SET_S_TPLFRT_TgtDistY1stDeriv_mps((i),(0.0F));
        /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant7'/Constant' */
        SET_S_TPLFRT_TgtDistY2ndDeriv_mps2((i),(0.0F));
    }
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant8'/Constant' */
    for (i = 0; i < 100; i++) {
        SET_S_TPLFRT_LeftDistY_met((i),(0.0F));
    }
    /* End of Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant8'/Constant' */
    /* Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant9'/Constant' */
    for (i = 0; i < 15; i++) {
        SET_S_TPLFRT_TgtPoints_nu((i),(0.0F));
    }
    /* End of Constant: 'sda:TPLFRT/TPLFRT/INI/TPLFRT_VehReset/Constant9'/Constant' */
}
#include "Pse_TPLFRT.h"
/*
 * Output and update for function-call system: 'sda:TPLFRT/TPLFRT'/TPLFRT_VehProcess'
 * Block description for: 'sda:TPLFRT/TPLFRT'/TPLFRT_VehProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TPLFRT_VehProcess
#include "Pse_TPLFRT.h"
/* Short description: Not synchronized with ARAMIS */
void TPLFRT_VehProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    calFTOutType rtb_FTOutputStruct;
    calFTInTypeV3 rtb_FTInputStruct;
    float32 rtb_SFunction1[15];
    float32 rtb_Sum_ck;
    float32 rtb_Switch_bh;
    float32 rtb_UnitDelay3;
    uint8 rtb_Switch_h;
    float32 rtb_Switch[15];
    float32 rtb_Switch_dl[15];
    float32 rtb_Switch_o[15];
    float32 rtb_Switch_n[15];
    sint32 i;
    /* Outputs for Atomic SubSystem: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM'/M_TPLFRT'
         *
         * Block description for 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM'/M_TPLFRT':
         *  X.2.1.1
         */
    /* Sum: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2/Add2/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_TPLFBT_TrajHeadingPrev_rad'
         *  Inport: '<Root>/S_TPLLCO_DevHeading_rad'
         *  Sum: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2/Add4/Functionality'/Sum'
         *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2'/Unit Delay1'
         */
    rtb_Sum_ck = (GET_S_TPLFBT_TrajHeadingPrev_rad() - DW_tplfrt_UnitDelay1_DSTATE) + GET_S_TPLLCO_DevHeading_rad();
    /* Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Application Parameter'/Constant'
         *  Inport: '<Root>/S_TPLFBT_TrajDistYPrev_met'
         *  Inport: '<Root>/S_TPLFBT_TrajHeadingPrev_rad'
         *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
         *  Inport: '<Root>/S_TPLLCO_ReplanDevDistY_met'
         *  Inport: '<Root>/S_TPLLCO_ReplanDevHeading_rad'
         *  Product: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Replan_Solution_1/Product/Functionality'/Mul'
         *  Sum: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Replan_Solution_1/Add/Functionality'/Sum'
         *  Sum: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Replan_Solution_1/Add1/Functionality'/Sum'
         *  Sum: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2/Add/Functionality'/Sum'
         *  Sum: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2/Add1/Functionality'/Sum'
         *  Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Switch1/Functionality'/Switch'
         *  Trigonometry: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Replan_Solution_1/Trigonom1/Functionality'/Trigonometric Function'
         *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2'/Unit Delay'
         */
    if (((sint32)GET_P_TPLFRT_CridrSwitchDetection_nu()) != 0) {
        rtb_Switch_bh = (GET_S_TPLFBT_TrajDistYPrev_met() - DW_tplfrt_UnitDelay_DSTATE) + GET_S_TPLLCO_DevDistY_met();
        rtb_UnitDelay3 = rtb_Sum_ck;
    } else {
        rtb_Switch_bh = (GET_S_TPLFBT_TrajDistYPrev_met() * f32_cos_f32 (GET_S_TPLLCO_ReplanDevHeading_rad())) - GET_S_TPLLCO_ReplanDevDistY_met();
        rtb_UnitDelay3 = GET_S_TPLFBT_TrajHeadingPrev_rad() - GET_S_TPLLCO_ReplanDevHeading_rad();
    }
    /* End of Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Switch/Functionality'/Switch' */
    /* BusCreator: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/FTInputStruct' incorporates:
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Application Parameter3'/Constant'
         *  Inport: '<Root>/S_CSCLTA_PlanningHorizon_sec'
         *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
         *  Inport: '<Root>/S_TPLCEN_TrajPlanEnbl_nu'
         *  Inport: '<Root>/S_TPLCEN_TrigTrajReplan_nu'
         *  Inport: '<Root>/S_TPLLCO_DevDistY_met'
         *  Inport: '<Root>/S_TPLLCO_DevHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_LeftCorridorCrv_1pm'
         *  Inport: '<Root>/S_TPLLCO_LeftCorridorHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_LeftCorridorLength_met'
         *  Inport: '<Root>/S_TPLLCO_LeftCorridorPosY0_met'
         *  Inport: '<Root>/S_TPLLCO_LeftCridrChngOfCrv_1pm2'
         *  Inport: '<Root>/S_TPLLCO_RiCridrChngOfCrv_1pm2'
         *  Inport: '<Root>/S_TPLLCO_RightCorridorCrv_1pm'
         *  Inport: '<Root>/S_TPLLCO_RightCorridorLength_met'
         *  Inport: '<Root>/S_TPLLCO_TargetCorridorCrv_1pm'
         *  Inport: '<Root>/S_TPLLCO_TargetCorridorPosY0_met'
         *  Inport: '<Root>/S_TPLLCO_TargetCridrHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_TargetCridrLength_met'
         *  Inport: '<Root>/S_TPLLCO_TgtCridrChngOfCrv_1pm2'
         *  MinMax: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Max/Functionality'/Max'
         */
    rtb_FTInputStruct.sf_DevDistY_met = GET_S_TPLLCO_DevDistY_met();
    rtb_FTInputStruct.sf_DevHeading_rad = GET_S_TPLLCO_DevHeading_rad();
    rtb_FTInputStruct.sf_CridrRightSg1_Crv_1pm = GET_S_TPLLCO_RightCorridorCrv_1pm ();
    rtb_FTInputStruct.sf_CridrRightSg1_ChOfCrv_1pm2 = GET_S_TPLLCO_RiCridrChngOfCrv_1pm2();
    rtb_FTInputStruct.sf_CridrRightSg1_Length_met = GET_S_TPLLCO_RightCorridorLength_met();
    rtb_FTInputStruct.sf_CridrLeftSg1_DistY_met = GET_S_TPLLCO_LeftCorridorPosY0_met();
    rtb_FTInputStruct.sf_CridrLeftSg1_Heading_rad = GET_S_TPLLCO_LeftCorridorHeading_rad();
    rtb_FTInputStruct.sf_CridrLeftSg1_Crv_1pm = GET_S_TPLLCO_LeftCorridorCrv_1pm();
    rtb_FTInputStruct.sf_CridrLeftSg1_ChOfCrv_1pm2 = GET_S_TPLLCO_LeftCridrChngOfCrv_1pm2();
    rtb_FTInputStruct.sf_CridrLeftSg1_Length_met = GET_S_TPLLCO_LeftCorridorLength_met();
    rtb_FTInputStruct.sf_TgtTrajSg1_DistY_met = GET_S_TPLLCO_TargetCorridorPosY0_met();
    rtb_FTInputStruct.sf_TgtTrajSg1_Heading_rad = GET_S_TPLLCO_TargetCridrHeading_rad();
    rtb_FTInputStruct.sf_TgtTrajSg1_Crv_1pm = GET_S_TPLLCO_TargetCorridorCrv_1pm();
    rtb_FTInputStruct.sf_TgtTrajSg1_ChngOfCrv_1pm2 = GET_S_TPLLCO_TgtCridrChngOfCrv_1pm2();
    rtb_FTInputStruct.sf_TgtTrajSg1_Length_met = GET_S_TPLLCO_TargetCridrLength_met();
    rtb_FTInputStruct.sf_TrajPlanEnbl_nu = GET_S_TPLCEN_TrajPlanEnbl_nu();
    rtb_FTInputStruct.sf_TrigRecalc_nu = GET_S_TPLCEN_TrigTrajReplan_nu();
    rtb_FTInputStruct.sf_PlanningHorizon_sec = f32_max_f32_f32 (GET_S_CSCLTA_PlanningHorizon_sec(), GET_P_TPLFRT_PlnHrznMinBarrier_sec());
    rtb_FTInputStruct.sf_CurCrvVehMotion_1pm = GET_S_LCFRCV_VehCrv_1pm();
    /* Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Start_Curvature/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Start_Curvature/Constant'/Constant'
         */
    if (((sint32)GET_P_TPLFRT_UseDMCSumCrv_nu()) != 0) {
        /* BusCreator: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/FTInputStruct' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_KappaSumCommand_1pm'
                 */
        rtb_FTInputStruct.sf_StartCrv_1pm = GET_S_LCFRCV_KappaSumCommand_1pm();
    } else {
        /* BusCreator: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/FTInputStruct' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_VehCrv_1pm'
                 */
        rtb_FTInputStruct.sf_StartCrv_1pm = GET_S_LCFRCV_VehCrv_1pm();
    }
    /* End of Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Start_Curvature/Switch2/Functionality'/Switch' */
    /* BusCreator: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/FTInputStruct' incorporates:
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Application Parameter1'/Constant'
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Application Parameter2'/Constant'
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Constant'/Constant'
         *  Inport: '<Root>/S_LCFRCV_VehAclX_mps2'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         *  Inport: '<Root>/S_TPLCEN_DelayVehGui_sec'
         *  Inport: '<Root>/S_TPLCEN_PredictionTimeHead_sec'
         *  Inport: '<Root>/S_TPLCEN_ReplanCurValues_nu'
         *  Inport: '<Root>/S_TPLCEN_ReplanModeArcLength_nu'
         *  Inport: '<Root>/S_TPLCEN_TrigReplanTgtTraj_nu'
         *  Inport: '<Root>/S_TPLFBT_TrajTgtCrvPrev_1pm'
         *  Inport: '<Root>/S_TPLLCO_LeftCorridorPosX0_met'
         *  Inport: '<Root>/S_TPLLCO_RightCorridorPosX0_met'
         *  Inport: '<Root>/S_TPLLCO_RightCorridorPosY0_met'
         *  Inport: '<Root>/S_TPLLCO_RightCridrHeading_rad'
         *  Inport: '<Root>/S_TPLLCO_TargetCorridorPosX0_met'
         */
    rtb_FTInputStruct.sf_EgoVelX_mps = GET_S_LCFRCV_VehVelX_mps();
    rtb_FTInputStruct.sf_EgoAclX_mps2 = GET_S_LCFRCV_VehAclX_mps2();
    rtb_FTInputStruct.sf_TgtCrvTrajPrev_1pm = GET_S_TPLFBT_TrajTgtCrvPrev_1pm();
    rtb_FTInputStruct.sf_TgtTrajSg1_DistX_met = GET_S_TPLLCO_TargetCorridorPosX0_met();
    rtb_FTInputStruct.sf_ReplanModeArcLength_nu = GET_S_TPLCEN_ReplanModeArcLength_nu();
    rtb_FTInputStruct.sf_LeftCridrActive_nu = GET_P_TPLFRT_CalcLeftCridrEnable_nu();
    rtb_FTInputStruct.sf_DistYTrajPrev_met = rtb_Switch_bh;
    rtb_FTInputStruct.sf_HeadingTrajPrev_rad = rtb_UnitDelay3;
    rtb_FTInputStruct.sf_CurHdngAndDeltaHdng_rad = rtb_Sum_ck;
    rtb_FTInputStruct.sf_PreviewTimeHeading_sec = GET_S_TPLCEN_PredictionTimeHead_sec();
    rtb_FTInputStruct.sf_DeadTime_sec = GET_S_TPLCEN_DelayVehGui_sec();
    rtb_FTInputStruct.sf_TrigTgtTrajCalc_nu = GET_S_TPLCEN_TrigReplanTgtTraj_nu();
    rtb_FTInputStruct.sf_CridrRightSg1_DistX_met = GET_S_TPLLCO_RightCorridorPosX0_met();
    rtb_FTInputStruct.sf_CridrLeftSg1_DistX_met = GET_S_TPLLCO_LeftCorridorPosX0_met();
    rtb_FTInputStruct.sf_UseTgtTrajX0_nu = GET_P_TPLFRT_UseTgtTrajX0_nu();
    rtb_FTInputStruct.sf_UseCridrRightX0_nu = 0U;
    rtb_FTInputStruct.sf_CridrRightSg1_Heading_rad = GET_S_TPLLCO_RightCridrHeading_rad();
    rtb_FTInputStruct.sf_CridrRightSg1_DistY_met = GET_S_TPLLCO_RightCorridorPosY0_met();
    rtb_FTInputStruct.sf_ReplanCurValues_nu = GET_S_TPLCEN_ReplanCurValues_nu();
    /* S-Function (sfun_calFrenetTransformation): 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/sfun_calFrenetTransformation' */
    rtb_FTOutputStruct = calFrenetTransformation((calFTInTypeV3*) &rtb_FTInputStruct);
    /* Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TPLCEN_TrigReplanTgtTraj_nu'
         *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay'
         */
    if (((sint32)GET_S_TPLCEN_TrigReplanTgtTraj_nu()) != 0) {
        rtb_Switch_h = rtb_FTOutputStruct.sf_NumTgtPoints_nu;
    } else {
        rtb_Switch_h = DW_tplfrt_UnitDelay_DSTATE_j;
    }
    /* End of Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch3/Functionality'/Switch' */
    for (i = 0; i < 15; i++) {
        /* Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_TPLCEN_TrigReplanTgtTraj_nu'
                 *  Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch4/Functionality'/Switch'
                 *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay1'
                 *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay4'
                 *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay5'
                 *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay6'
                 */
        if (((sint32)GET_S_TPLCEN_TrigReplanTgtTraj_nu()) != 0) {
            rtb_Switch[i] = rtb_FTOutputStruct.sf_TgtDistY_met[i];
            rtb_Switch_dl[i] = rtb_FTOutputStruct.sf_TgtDistY1stDeriv_nu[i];
            rtb_Switch_o[i] = rtb_FTOutputStruct.sf_TgtDistY2ndDeriv_nu[i];
            rtb_Switch_n[i] = rtb_FTOutputStruct.sf_TgtPoints_nu[i];
        } else {
            rtb_Switch[i] = DW_tplfrt_UnitDelay6_DSTATE[i];
            rtb_Switch_dl[i] = DW_tplfrt_UnitDelay5_DSTATE[i];
            rtb_Switch_o[i] = DW_tplfrt_UnitDelay4_DSTATE[i];
            rtb_Switch_n[i] = DW_tplfrt_UnitDelay1_DSTATE_c[i];
        }
        /* End of Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch/Functionality'/Switch' */
    }
    /* Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch5/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_TPLCEN_TrigReplanTgtTraj_nu'
         *  Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch6/Functionality'/Switch'
         *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay2'
         *  UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay3'
         */
    if (((sint32)GET_S_TPLCEN_TrigReplanTgtTraj_nu()) != 0) {
        rtb_Sum_ck = rtb_FTOutputStruct.sf_TrajPlanningHorizon_sec;
        rtb_Switch_bh = rtb_FTOutputStruct.sf_PlanHorizonVisRange_sec;
    } else {
        rtb_Sum_ck = DW_tplfrt_UnitDelay2_DSTATE;
        rtb_Switch_bh = DW_tplfrt_UnitDelay3_DSTATE;
    }
    /* End of Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch5/Functionality'/Switch' */
    /* Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/read_array/Functionality/C#BASE1#'/Constant'
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/read_array/Functionality/R#BASE1#'/Constant'
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1/Functionality/C#BASE1#'/Constant'
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1/Functionality/R#BASE1#'/Constant'
         *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/P_TPLFRT_TgtPointMin_sec'/Constant'
         *  S-Function (sfun_sdareadarray): 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/read_array/Functionality/selector'/S-Function1'
         */
    if (rtb_Switch_n[1 - 1] != 0.0F) {
        /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch7'/copy1' */
        for (i = 0; i < 15; i++) {
            SET_S_TPLFRT_TgtPoints_nu((i),(rtb_Switch_n[i]));
        }
    } else {
        /* Outputs for Atomic SubSystem: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1'/Functionality' */
        /* S-Function (sfun_sdawritearray): 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1/Functionality/assignment'/S-Function1' */
        /* working on block :
                   TPLFRT_cg/TPLFRT_cg/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1/Functionality/assignment/S-Function1
                 */
        /* 2 dim input signal but no matrix access */
        {
            sint32 i;
            for (i= 0; i < 15; i++) {
                rtb_SFunction1[i] = rtb_Switch_n[i];
            }
        }
        rtb_SFunction1[0] = GET_P_TPLFRT_TgtPointMin_sec();
        /* End of Outputs for SubSystem: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1'/Functionality' */
        /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch7'/copy1' incorporates:
                 *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1/Functionality/C#BASE1#'/Constant'
                 *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/write_array1/Functionality/R#BASE1#'/Constant'
                 *  Constant: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/P_TPLFRT_TgtPointMin_sec'/Constant'
                 */
        for (i = 0; i < 15; i++) {
            SET_S_TPLFRT_TgtPoints_nu((i),(rtb_SFunction1[i]));
        }
    }
    /* End of Switch: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Switch8/Functionality'/Switch' */
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch'/copy1' */
    SET_S_TPLFRT_PlanHorizonVisRange_sec(rtb_Switch_bh);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch1'/copy1' */
    SET_S_TPLFRT_TrajPlanningHorizon_sec(rtb_Sum_ck);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch10'/copy1' */
    SET_S_TPLFRT_TrajVelRefCurve_mps(rtb_FTOutputStruct.sf_TrajVel_mps);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch11'/copy1' */
    SET_S_TPLFRT_TrajAclRefCurve_mps2(rtb_FTOutputStruct.sf_TrajAcl_mps2);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch12'/copy1' */
    for (i = 0; i < 100; i++) {
        SET_S_TPLFRT_LeftDistY_met((i),(rtb_FTOutputStruct.sf_DistYLeft_met[i]));
    }
    /* End of SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch12'/copy1' */
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch13'/copy1' */
    SET_S_TPLFRT_TrajDistYPrev_met(rtb_FTOutputStruct.sf_TrajDistYPrevious_met);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch14'/copy1' */
    SET_S_TPLFRT_TrajDistY1stToPrev_mps (rtb_FTOutputStruct.sf_TrajDistYPrev1stDeriv_nu);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch15'/copy1' */
    SET_S_TPLFRT_TrajDistY2ndToPrev_mps2 (rtb_FTOutputStruct.sf_TrajDistYPrev2ndDeriv_nu);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch16'/copy1' */
    SET_S_TPLFRT_DistY1stToDevHead_mps(rtb_FTOutputStruct.sf_1stDerivDevHeading_nu);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch17'/copy1' */
    SET_S_TPLFRT_DistY2ndToDevHead_mps2 (rtb_FTOutputStruct.sf_2ndDerivDevHeading_nu);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch18'/copy1' */
    SET_S_TPLFRT_CurDistYPreview_met(rtb_FTOutputStruct.sf_DstYCurValuePreview_met);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch19'/copy1' */
    SET_S_TPLFRT_CurDistY1stToPrev_mps (rtb_FTOutputStruct.sf_DstY1stDrvCurValPrvw_mps);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch2'/copy1' */
    SET_S_TPLFRT_CurDistY_met(rtb_FTOutputStruct.sf_DistYCurValue_met);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch20'/copy1' */
    SET_S_TPLFRT_PreviewTimeHeading_sec (rtb_FTOutputStruct.sf_FrenTrafHeadingPrvw_sec);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch21'/copy1' */
    SET_S_TPLFRT_NumPointsCridrLeft_nu(rtb_FTOutputStruct.sf_NumPointsCridrLeft_nu);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch3'/copy1' */
    SET_S_TPLFRT_NumTgtPoints_nu(rtb_Switch_h);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch8'/copy1' */
    SET_S_TPLFRT_CurDistY1stDeriv_mps (rtb_FTOutputStruct.sf_DistY1stDerivCurValue_nu);
    /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch9'/copy1' */
    SET_S_TPLFRT_CurDistY2ndDeriv_mps2 (rtb_FTOutputStruct.sf_DistY2ndDerivCurValue_nu);
    /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2'/Unit Delay' incorporates:
                                                          *  Update for Inport: '<Root>/S_TPLLCO_DevDistY_met'
                                                          */
    DW_tplfrt_UnitDelay_DSTATE = GET_S_TPLLCO_DevDistY_met();
    /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/Calc_Trajectory_Prev_Cycle/Solution_2'/Unit Delay1' incorporates:
         *  Update for Inport: '<Root>/S_TPLLCO_DevHeading_rad'
         */
    DW_tplfrt_UnitDelay1_DSTATE = GET_S_TPLLCO_DevHeading_rad();
    /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay' */
    DW_tplfrt_UnitDelay_DSTATE_j = rtb_Switch_h;
    for (i = 0; i < 15; i++) {
        /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch4'/copy1' */
        SET_S_TPLFRT_TgtDistY_met((i),(rtb_Switch[i]));
        /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch5'/copy1' */
        SET_S_TPLFRT_TgtDistY1stDeriv_mps((i),(rtb_Switch_dl[i]));
        /* SignalConversion: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT/branch6'/copy1' */
        SET_S_TPLFRT_TgtDistY2ndDeriv_mps2((i),(rtb_Switch_o[i]));
        /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay6' */
        DW_tplfrt_UnitDelay6_DSTATE[i] = rtb_Switch[i];
        /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay5' */
        DW_tplfrt_UnitDelay5_DSTATE[i] = rtb_Switch_dl[i];
        /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay4' */
        DW_tplfrt_UnitDelay4_DSTATE[i] = rtb_Switch_o[i];
        /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay1' */
        DW_tplfrt_UnitDelay1_DSTATE_c[i] = rtb_Switch_n[i];
    }
    /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay2' */
    DW_tplfrt_UnitDelay2_DSTATE = rtb_Sum_ck;
    /* Update for UnitDelay: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM/M_TPLFRT'/Unit Delay3' */
    DW_tplfrt_UnitDelay3_DSTATE = rtb_Switch_bh;
    /* End of Outputs for SubSystem: 'sda:TPLFRT/TPLFRT/TPLFRT_VehProcess/OPM'/M_TPLFRT' */
}
#include "Pse_TPLFRT.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
