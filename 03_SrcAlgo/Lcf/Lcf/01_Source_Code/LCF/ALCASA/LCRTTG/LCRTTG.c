/**************************************************************************
COPYRIGHT (C) $Date: 2019/08/19 14:45:19CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/ALCASA/LCRTTG_SEN/LCRTTG/i/project.pj $
$Log: LCRTTG.c  $
Revision 1.5 2019/08/19 14:45:19CEST Mariut, Felix (uidp0906) 
automatically created
File          : LCRTTG
Generated on  : Wed 31.07.2019 at 12:54:30 (UTC+01:00)
MD5           : [3873056582  4003875246  4094461129  2280589971 0](LCRTTG)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-RPT: 1,2 SDA-Core: 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79,80,81,82,83,84,87
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "LCRTTG.h"
#include "LCRTTG_private.h"
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
#define LCRTTG_START_SEC_DATA_8
#include "LCRTTG_MemMap.h"
static uint8 BI_lcrttg_LogicalOperator;
/* 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 DW_lcrttg_FixPtUnitDelay3_DSTATE;
static uint8 DW_lcrttg_FixPtUnitDelay3_DSTATE_e;
static uint8 DW_lcrttg_Unit_Delay_DSTATE;
#define LCRTTG_STOP_SEC_DATA_8
#include "LCRTTG_MemMap.h"
#define LCRTTG_START_SEC_DATA_32
#include "LCRTTG_MemMap.h"
static float32 DW_lcrttg_FixPtUnitDelay1_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay4_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay1_DSTATE_k;
static float32 DW_lcrttg_FixPtUnitDelay4_DSTATE_n;
static float32 DW_lcrttg_FixPtUnitDelay5_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay4_DSTATE_e;
static float32 DW_lcrttg_Unit_Delay1_DSTATE;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_b;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_e;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_k;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_n;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_i;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_d;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_m;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_c;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_a;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_ed;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_ns;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_p;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_df;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_m0;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_ix;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_aq;
static float32 DW_lcrttg_Unit_Delay1_DSTATE_ib;
static float32 DW_lcrttg_FixPtUnitDelay2_1_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_10_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_11_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_12_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_13_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_14_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_15_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_16_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_17_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_18_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_2_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_3_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_4_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_5_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_6_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_7_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_8_DSTATE;
static float32 DW_lcrttg_FixPtUnitDelay2_9_DSTATE;
#define LCRTTG_STOP_SEC_DATA_32
#include "LCRTTG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:LCRTTG/LCRTTG'/LCRTTG_SenReset'
 * Block description for: 'sda:LCRTTG/LCRTTG'/LCRTTG_SenReset'
 *   X.1
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRTTG_SenReset
#include "Pse_LCRTTG.h"
/* Short description:  */
void LCRTTG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant1'/Constant' */
    SET_S_LCRTTG_LeCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant10'/Constant' */
    SET_S_LCRTTG_RiCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant11'/Constant' */
    SET_S_LCRTTG_RiCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant12'/Constant' */
    SET_S_LCRTTG_RiCridrBndLength_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant13'/Constant' */
    SET_S_LCRTTG_TgtTrajPosX0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant14'/Constant' */
    SET_S_LCRTTG_LeTgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant15'/Constant' */
    SET_S_LCRTTG_TgtTrajHeadAng_rad(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant16'/Constant' */
    SET_S_LCRTTG_TgtTrajCrv_1pm(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant17'/Constant' */
    SET_S_LCRTTG_TgtTrajLength_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant19'/Constant' */
    SET_S_LCRTTG_RiTgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant2'/Constant' */
    SET_S_LCRTTG_LeCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant20'/Constant' */
    SET_S_LCRTTG_TgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant24'/Constant' */
    SET_S_LCRTTG_TgtTrajCrvChng_1pm2(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant3'/Constant' */
    SET_S_LCRTTG_LeCridrBndHeadAng_rad(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant4'/Constant' */
    SET_S_LCRTTG_LeCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant5'/Constant' */
    SET_S_LCRTTG_LeCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant6'/Constant' */
    SET_S_LCRTTG_LeCridrBndLength_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant7'/Constant' */
    SET_S_LCRTTG_RiCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant8'/Constant' */
    SET_S_LCRTTG_RiCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenReset/Constant9'/Constant' */
    SET_S_LCRTTG_RiCridrBndHeadAng_rad(0.0F);
}
#include "Pse_LCRTTG.h"
/*
 * Output and update for function-call system: 'sda:LCRTTG/LCRTTG'/LCRTTG_SenProcess'
 * Block description for: 'sda:LCRTTG/LCRTTG'/LCRTTG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_LCRTTG_SenProcess
#include "Pse_LCRTTG.h"
/* Short description:  */
void LCRTTG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_S_LCRTTG_LeCridrBndPosX0_met;
    float32 rtb_S_LCRTTG_RiCridrBndCrv_1pm;
    float32 rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2;
    float32 rtb_S_LCRTTG_RiCridrBndLength_met;
    float32 rtb_S_LCRTTG_TgtTrajPosX0_met;
    float32 rtb_ip_lookup_fxpt_sfun_7;
    float32 rtb_S_LCRTTG_TgtTrajPosY0_met;
    float32 rtb_S_LCRTTG_TgtTrajHeadAng_rad;
    float32 rtb_S_LCRTTG_TgtTrajCrv_1pm;
    float32 rtb_S_LCRTTG_TgtTrajCrvChng_1pm2;
    float32 rtb_S_LCRTTG_TgtTrajLength_met;
    float32 rtb_S_LCRTTG_LeCridrBndPosY0_met;
    float32 rtb_S_LCRTTG_LeCridrBndHeadAng_rad;
    float32 rtb_S_LCRTTG_LeCridrBndCrv_1pm;
    float32 rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2;
    float32 rtb_S_LCRTTG_LeCridrBndLength_met;
    float32 rtb_S_LCRTTG_RiCridrBndPosX0_met;
    float32 rtb_S_LCRTTG_RiCridrBndPosY0_met;
    float32 rtb_S_LCRTTG_RiCridrBndHeadAng_rad;
    float32 rtb_Div_o;
    float32 rtb_Unit_Delay1;
    float32 rtb_SFunction;
    float32 rtb_Div_j;
    float32 rtb_Unit_Delay1_g;
    float32 rtb_SFunction_b;
    float32 rtb_Div_i;
    float32 rtb_Unit_Delay1_n;
    float32 rtb_SFunction_g;
    float32 rtb_Div_f;
    float32 rtb_Unit_Delay1_j;
    float32 rtb_SFunction_i;
    float32 rtb_Div_f3;
    float32 rtb_Unit_Delay1_i;
    float32 rtb_SFunction_f;
    float32 rtb_Div_l;
    float32 rtb_Unit_Delay1_js;
    float32 rtb_SFunction_o;
    float32 rtb_Div_e;
    float32 rtb_Unit_Delay1_p;
    float32 rtb_SFunction_f1;
    float32 rtb_Div_op;
    float32 rtb_Unit_Delay1_nf;
    float32 rtb_SFunction_b0;
    float32 rtb_Div_eq;
    float32 rtb_Unit_Delay1_jg;
    float32 rtb_SFunction_j;
    float32 rtb_Div_ic;
    float32 rtb_Unit_Delay1_m;
    float32 rtb_SFunction_c;
    float32 rtb_Div_p;
    float32 rtb_Unit_Delay1_nw;
    float32 rtb_SFunction_cj;
    float32 rtb_Div_g;
    float32 rtb_Unit_Delay1_e;
    float32 rtb_SFunction_e;
    float32 rtb_Div_a;
    float32 rtb_Unit_Delay1_ei;
    float32 rtb_SFunction_ol;
    float32 rtb_Div_pu;
    float32 rtb_Unit_Delay1_l;
    float32 rtb_SFunction_k;
    float32 rtb_Div_m;
    float32 rtb_Unit_Delay1_a;
    float32 rtb_SFunction_e4;
    float32 rtb_Div_j3;
    float32 rtb_Unit_Delay1_c;
    float32 rtb_SFunction_bg;
    float32 rtb_Div_ik;
    float32 rtb_Unit_Delay1_m0;
    float32 rtb_SFunction_bl;
    float32 rtb_Div_i3;
    float32 rtb_Unit_Delay1_li;
    float32 rtb_SFunction_oj;
    float32 rtb_Abs;
    float32 rtb_ip_lookup_fxpt_sfun_7_d;
    float32 rtb_Abs_i;
    float32 rtb_ip_lookup_fxpt_sfun_7_l;
    float32 rtb_Abs_iv;
    float32 rtb_ip_lookup_fxpt_sfun_7_c;
    float32 rtb_Abs_h;
    float32 rtb_ip_lookup_fxpt_sfun_7_j;
    uint8 rtb_EQ;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_EQ_nh;
    uint8 rtb_EQ_px;
    float32 rtb_Div;
    float32 rtb_S_LCRTTG_LeCridrBndPosY0_met_l;
    float32 rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2_gm;
    float32 rtb_S_LCRTTG_RiCridrBndLength_met_n;
    float32 rtb_S_LCRTTG_TgtTrajPosX0_met_o;
    float32 rtb_S_LCRTTG_TgtTrajPosY0_met_e;
    float32 rtb_S_LCRTTG_TgtTrajHeadAng_rad_f;
    float32 rtb_S_LCRTTG_TgtTrajCrv_1pm_n;
    float32 rtb_S_LCRTTG_TgtTrajCrvChng_1pm2_e;
    float32 rtb_S_LCRTTG_TgtTrajLength_met_oz;
    float32 rtb_Sum_ls;
    float32 rtb_S_LCRTTG_LeCridrBndHeadAng_rad_b;
    float32 rtb_Sum;
    float32 rtb_S_LCRTTG_LeCridrBndCrv_1pm_c;
    float32 rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2_i;
    float32 rtb_S_LCRTTG_LeCridrBndLength_met_e;
    float32 rtb_S_LCRTTG_RiCridrBndPosX0_met_cl;
    float32 rtb_S_LCRTTG_RiCridrBndPosY0_met_o;
    float32 rtb_S_LCRTTG_RiCridrBndHeadAng_rad_g;
    float32 rtb_S_LCRTTG_RiCridrBndCrv_1pm_g;
    float32 rtb_Switch;
    float32 rtb_Switch_l;
    float32 rtb_Switch_p;
    float32 rtb_Switch_k4;
    float32 rtb_Switch_hg;
    float32 rtb_Switch_e;
    float32 rtb_Switch_o;
    /* RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT)));
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch3/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_LCRSIA_LaneWidth_met'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay3'
         */
    if (((sint32)DW_lcrttg_FixPtUnitDelay3_DSTATE) != 0) {
        rtb_Switch = DW_lcrttg_FixPtUnitDelay1_DSTATE;
    } else {
        rtb_Switch = GET_S_LCRSIA_LaneWidth_met();
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch3/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/from_data_definition'/state_source'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         *  Logic: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Relational Operator/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Relational Operator1/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu))) || (((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu))));
    /* RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/Relational Operator2/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
         */
    rtb_EQ_nh = (uint8)(((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32) ((uint8)E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT)));
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Left/Constant4'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Right/Constant7'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Right/Constant8'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Right/Constant9'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Target/Constant4'/Constant'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_EQ) != 0) {
            rtb_S_LCRTTG_LeCridrBndPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
            rtb_S_LCRTTG_RiCridrBndCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
            rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
            rtb_S_LCRTTG_RiCridrBndLength_met = GET_S_ABPLBP_LeLnClthLength_met();
        } else {
            rtb_S_LCRTTG_LeCridrBndPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
            rtb_S_LCRTTG_RiCridrBndCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
            rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
            rtb_S_LCRTTG_RiCridrBndLength_met = GET_S_ABPLBP_RiLnClthLength_met();
        }
        /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 */
        if (((sint32)rtb_EQ_nh) != 0) {
            rtb_S_LCRTTG_TgtTrajPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
        } else {
            rtb_S_LCRTTG_TgtTrajPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
        }
        /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_LCRTTG_LeCridrBndPosX0_met = 0.0F;
        rtb_S_LCRTTG_RiCridrBndCrv_1pm = 0.0F;
        rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2 = 0.0F;
        rtb_S_LCRTTG_RiCridrBndLength_met = 0.0F;
        rtb_S_LCRTTG_TgtTrajPosX0_met = 0.0F;
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/P_DPLTTG_TargetLaneCenterEnable_nu'/Constant'
         *  Inport: '<Root>/S_LCRSIA_TgtCntrLnEnable_bool'
         *  Logic: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/AND/Functionality'/AND'
         */
    rtb_EQ_px = (uint8)((((sint32)GET_S_LCRSIA_TgtCntrLnEnable_bool()) != 0) && (((sint32)GET_P_LCRTTG_TgtCntrLnEnable_nu()) != 0));
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Div/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant1'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant2'/Constant'
         */
    rtb_Div = GET_P_VEH_Width_met() / 2.0F;
    /* S-Function Block sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Y_LCRTTG_LWTargetLatDist_met/Functionality'/ip_lookup_fxpt_sfun_7 */
    {
        FDPS_RESULT dps_result_ln;
        /* Calculate value */
        /* Find indices on X Axis: X_LCF_LaneWidth_met */
        FDPS_PTR_F32(GETA_X_LCF_LaneWidth_met(), GET_S_LCRSIA_LaneWidth_met(), &dps_result_ln);
        /* Direct accesing curve (used as module input) */
        rtb_ip_lookup_fxpt_sfun_7 = F32_PTR_IP1D(GETA_Y_LCRTTG_LWTargetLatDist_met(), &dps_result_ln);
    }
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch3/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant3'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition2'/state_source'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_LCRSIA_CurveTypeLe_enum'
         *  MinMax: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Min/Functionality'/Min'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/EQ/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/EQ1/Functionality'/EQ'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum4/Functionality'/Sum'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch4/Functionality'/Switch'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch5/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay1'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay3'
         */
    if (((sint32)DW_lcrttg_FixPtUnitDelay3_DSTATE_e) != 0) {
        rtb_Switch_e = DW_lcrttg_FixPtUnitDelay1_DSTATE_k;
    } else {
        if (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Abs2/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch4/Functionality'/Switch'
                         */
            rtb_Abs_iv = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Y_LCRTTG_CrvICTgtOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_iv, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_c = F32_PTR_IP1D (GETA_Y_LCRTTG_CrvICTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_e = -rtb_ip_lookup_fxpt_sfun_7_c;
        } else if (((sint32)GET_S_LCRSIA_CurveTypeLe_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Abs1/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch4/Functionality'/Switch'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch5/Functionality'/Switch'
                         */
            rtb_Abs_h = f32_abs_f32(GET_S_ABPLBP_LeLnClthCrv_1pm());
            /* S-Function Block sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Y_LCRTTG_CrvOCTgtOffset_met/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_h, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_j = F32_PTR_IP1D (GETA_Y_LCRTTG_CrvOCTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_e = rtb_ip_lookup_fxpt_sfun_7_j;
        } else {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch5/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant8'/Constant'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch4/Functionality'/Switch'
                         */
            rtb_Switch_e = 0.0F;
        }
        /* Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum2/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition3'/state_source'
                 *  Inport: '<Root>/S_LCRSIA_CurveTypeLe_enum'
                 *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/EQ1/Functionality'/EQ'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch4/Functionality'/Switch'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch5/Functionality'/Switch'
                 */
        rtb_Switch_e += rtb_ip_lookup_fxpt_sfun_7;
        rtb_Switch_e = rtb_Div + f32_min_f32_f32(rtb_Switch_e, GET_P_LCRTTG_TgtMaxDistance_met());
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch3/Functionality'/Switch' */
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum/Functionality'/Sum'
         */
    if (((sint32)rtb_EQ_px) != 0) {
        rtb_Switch_l = GET_S_ABPLBP_CntrLnClthPosY0_met();
    } else {
        rtb_Switch_l = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch_e;
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/GT/Functionality'/GT'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Sum7/Functionality'/Sum'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum7/Functionality'/Sum'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Switch1/Functionality'/Switch'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch10/Functionality'/Switch'
         *  UnaryMinus: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay3'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay4'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev'/FixPt Unit Delay4'
         */
    if (((sint32)DW_lcrttg_FixPtUnitDelay3_DSTATE_e) != 0) {
        rtb_Switch_p = DW_lcrttg_FixPtUnitDelay4_DSTATE_n;
        rtb_Switch_l = DW_lcrttg_FixPtUnitDelay4_DSTATE;
    } else {
        if ((-GET_P_LCRTTG_TgtMaxLatDev_met()) > rtb_Switch_l) {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Sum6/Functionality'/Sum'
                         *  UnaryMinus: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Neg/Functionality'/Unary Minus'
                         */
            rtb_Switch_p = rtb_Switch_l - (-GET_P_LCRTTG_TgtMaxLatDev_met());
        } else {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Constant1'/Constant'
                         */
            rtb_Switch_p = 0.0F;
        }
        rtb_Switch_l = GET_S_ABPLBP_LeLnClthPosY0_met() - (rtb_Switch_l - rtb_Switch_p);
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev/Switch10/Functionality'/Switch' */
    /* Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum8/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         */
    rtb_Sum_ls = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch_l;
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch8/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant4'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition4'/state_source'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_LCRSIA_CurveTypeRi_enum'
         *  MinMax: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Min1/Functionality'/Min'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/EQ3/Functionality'/EQ'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum5/Functionality'/Sum'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch6/Functionality'/Switch'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch7/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay2'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay3'
         */
    if (((sint32)DW_lcrttg_FixPtUnitDelay3_DSTATE_e) != 0) {
        rtb_Div = DW_lcrttg_FixPtUnitDelay2_DSTATE;
    } else {
        if (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_INNER))) {
            /* Abs: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Abs3/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch6/Functionality'/Switch'
                         */
            rtb_Abs = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Y_LCRTTG_CrvICTgtOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_d = F32_PTR_IP1D (GETA_Y_LCRTTG_CrvICTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_o = -rtb_ip_lookup_fxpt_sfun_7_d;
        } else if (((sint32)GET_S_LCRSIA_CurveTypeRi_enum()) == ((sint32)((uint8) E_LCF_CurveType_E_LCF_CURVE_OUTER))) {
            /* Abs: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Abs4/Functionality'/Abs' incorporates:
                         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch6/Functionality'/Switch'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch7/Functionality'/Switch'
                         */
            rtb_Abs_i = f32_abs_f32(GET_S_ABPLBP_RiLnClthCrv_1pm());
            /* S-Function Block sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Y_LCRTTG_CrvOCTgtOffset_met1/Functionality'/ip_lookup_fxpt_sfun_7 */
            {
                FDPS_RESULT dps_result_ln;
                /* Calculate value */
                /* Find indices on X Axis: X_LCF_Curvature_1pm */
                FDPS_PTR_F32(GETA_X_LCF_Curvature_1pm(), rtb_Abs_i, &dps_result_ln);
                /* Direct accesing curve (used as module input) */
                rtb_ip_lookup_fxpt_sfun_7_l = F32_PTR_IP1D (GETA_Y_LCRTTG_CrvOCTgtOffset_met(), &dps_result_ln);
            }
            rtb_Switch_o = rtb_ip_lookup_fxpt_sfun_7_l;
        } else {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch7/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant9'/Constant'
                         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch6/Functionality'/Switch'
                         */
            rtb_Switch_o = 0.0F;
        }
        /* Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum3/Functionality'/Sum' incorporates:
                 *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition5'/state_source'
                 *  Inport: '<Root>/S_LCRSIA_CurveTypeRi_enum'
                 *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/EQ3/Functionality'/EQ'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch6/Functionality'/Switch'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch7/Functionality'/Switch'
                 */
        rtb_Switch_o += rtb_ip_lookup_fxpt_sfun_7;
        rtb_Div += f32_min_f32_f32(rtb_Switch_o, GET_P_LCRTTG_TgtMaxDistance_met());
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch8/Functionality'/Switch' */
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch9/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_EQ_px) != 0) {
        rtb_Switch_k4 = GET_S_ABPLBP_CntrLnClthPosY0_met();
    } else {
        rtb_Switch_k4 = rtb_Div + GET_S_ABPLBP_RiLnClthPosY0_met();
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch9/Functionality'/Switch' */
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Switch10/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/LT/Functionality'/LT'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Sum7/Functionality'/Sum'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum6/Functionality'/Sum'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Switch1/Functionality'/Switch'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch11/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay3'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay5'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1'/FixPt Unit Delay4'
         */
    if (((sint32)DW_lcrttg_FixPtUnitDelay3_DSTATE_e) != 0) {
        rtb_Switch_o = DW_lcrttg_FixPtUnitDelay4_DSTATE_e;
        rtb_Switch_k4 = DW_lcrttg_FixPtUnitDelay5_DSTATE;
    } else {
        if (GET_P_LCRTTG_TgtMaxLatDev_met() < rtb_Switch_k4) {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/P_DPLTTG_TargetLaneCenterEnable_nu3'/Constant'
                         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Sum6/Functionality'/Sum'
                         */
            rtb_Switch_o = rtb_Switch_k4 - GET_P_LCRTTG_TgtMaxLatDev_met();
        } else {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Constant1'/Constant'
                         */
            rtb_Switch_o = 0.0F;
        }
        rtb_Switch_k4 = (rtb_Switch_k4 - rtb_Switch_o) - GET_S_ABPLBP_RiLnClthPosY0_met();
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1/Switch10/Functionality'/Switch' */
    /* Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Sum9/Functionality'/Sum' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         */
    rtb_Sum = GET_S_ABPLBP_RiLnClthPosY0_met() + rtb_Switch_k4;
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Left/Constant5'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Left/Constant6'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Left/Constant7'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Left/Constant8'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Left/Constant9'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Right/Constant4'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Right/Constant5'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Right/Constant6'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Target/Constant5'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Target/Constant6'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Target/Constant7'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Target/Constant8'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/DefaultValues/Target/Constant9'/Constant'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Constant'/Constant'
                 *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition'/state_source'
                 *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/from_data_definition1'/state_source'
                 *  Inport: '<Root>/S_LCRSMI_DangerousSide_nu'
                 *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Relational Operator1/Functionality'/EQ'
                 *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Relational Operator2/Functionality'/EQ'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch1/Functionality'/Switch'
                 */
        if (((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_LEFT))) {
            rtb_S_LCRTTG_TgtTrajPosY0_met = rtb_Sum_ls;
        } else if (((sint32)GET_S_LCRSMI_DangerousSide_nu()) == ((sint32)((uint8) E_LCF_DangerousSideType_E_LCF_DANGEROUSSIDE_RIGHT))) {
            /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch1/Functionality'/Switch' */
            rtb_S_LCRTTG_TgtTrajPosY0_met = rtb_Sum;
        } else {
            rtb_S_LCRTTG_TgtTrajPosY0_met = 0.0F;
        }
        /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/Switch/Functionality'/Switch' */
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch'
                 */
        if (((sint32)rtb_EQ_nh) != 0) {
            rtb_S_LCRTTG_TgtTrajHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
            rtb_S_LCRTTG_TgtTrajCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
            rtb_S_LCRTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
            rtb_S_LCRTTG_TgtTrajLength_met = GET_S_ABPLBP_LeLnClthLength_met();
        } else {
            rtb_S_LCRTTG_TgtTrajHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
            rtb_S_LCRTTG_TgtTrajCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
            rtb_S_LCRTTG_TgtTrajCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
            rtb_S_LCRTTG_TgtTrajLength_met = GET_S_ABPLBP_RiLnClthLength_met();
        }
        /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/Switch/Functionality'/Switch' */
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
                 *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Sum/Functionality'/Sum'
                 *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch'
                 *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch1/Functionality'/Switch'
                 */
        if (((sint32)rtb_EQ) != 0) {
            rtb_S_LCRTTG_LeCridrBndPosY0_met = GET_S_ABPLBP_LeLnClthPosY0_met();
            rtb_S_LCRTTG_LeCridrBndHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
            rtb_S_LCRTTG_LeCridrBndCrv_1pm = GET_S_ABPLBP_LeLnClthCrv_1pm();
            rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
            rtb_S_LCRTTG_LeCridrBndLength_met = GET_S_ABPLBP_LeLnClthLength_met();
            rtb_S_LCRTTG_RiCridrBndPosX0_met = GET_S_ABPLBP_LeLnClthPosX0_met();
            rtb_S_LCRTTG_RiCridrBndPosY0_met = GET_S_ABPLBP_LeLnClthPosY0_met() - rtb_Switch;
            rtb_S_LCRTTG_RiCridrBndHeadAng_rad = GET_S_ABPLBP_LeLnClthHeading_rad();
        } else {
            rtb_S_LCRTTG_LeCridrBndPosY0_met = rtb_Switch + GET_S_ABPLBP_RiLnClthPosY0_met();
            rtb_S_LCRTTG_LeCridrBndHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
            rtb_S_LCRTTG_LeCridrBndCrv_1pm = GET_S_ABPLBP_RiLnClthCrv_1pm();
            rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2 = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
            rtb_S_LCRTTG_LeCridrBndLength_met = GET_S_ABPLBP_RiLnClthLength_met();
            rtb_S_LCRTTG_RiCridrBndPosX0_met = GET_S_ABPLBP_RiLnClthPosX0_met();
            rtb_S_LCRTTG_RiCridrBndPosY0_met = GET_S_ABPLBP_RiLnClthPosY0_met();
            rtb_S_LCRTTG_RiCridrBndHeadAng_rad = GET_S_ABPLBP_RiLnClthHeading_rad();
        }
        /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor/Switch/Functionality'/Switch' */
    } else {
        rtb_S_LCRTTG_TgtTrajPosY0_met = 0.0F;
        rtb_S_LCRTTG_TgtTrajHeadAng_rad = 0.0F;
        rtb_S_LCRTTG_TgtTrajCrv_1pm = 0.0F;
        rtb_S_LCRTTG_TgtTrajCrvChng_1pm2 = 0.0F;
        rtb_S_LCRTTG_TgtTrajLength_met = 0.0F;
        rtb_S_LCRTTG_LeCridrBndPosY0_met = 10.0F;
        rtb_S_LCRTTG_LeCridrBndHeadAng_rad = 0.0F;
        rtb_S_LCRTTG_LeCridrBndCrv_1pm = 0.0F;
        rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2 = 0.0F;
        rtb_S_LCRTTG_LeCridrBndLength_met = 0.0F;
        rtb_S_LCRTTG_RiCridrBndPosX0_met = 0.0F;
        rtb_S_LCRTTG_RiCridrBndPosY0_met = -10.0F;
        rtb_S_LCRTTG_RiCridrBndHeadAng_rad = 0.0F;
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/Switch/Functionality'/Switch' */
    /* RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Relational Operator/Functionality'/EQ' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         */
    rtb_EQ = (uint8)(((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32) ((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)));
    /* S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising'/Unit_Delay'
         */
    BI_lcrttg_LogicalOperator = (uint8)((!(((sint32)DW_lcrttg_Unit_Delay_DSTATE) != 0)) && (((sint32)rtb_EQ) != 0));
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING'/fcg' */
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/Constant'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/GT/Functionality'/GT'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_LCRTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Switch_hg = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Switch_hg = GET_P_LCRTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckLe/Constant1'/Constant'
         */
    rtb_Switch_hg = f32_max_f32_f32(rtb_Switch_hg, 1.0E-5F);
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_o = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1 = DW_lcrttg_Unit_Delay1_DSTATE;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction = rtb_S_LCRTTG_LeCridrBndPosX0_met;
    } else {
        rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay1, rtb_S_LCRTTG_LeCridrBndPosX0_met, rtb_Div_o);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_j = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_g = DW_lcrttg_Unit_Delay1_DSTATE_b;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_b = rtb_S_LCRTTG_LeCridrBndPosY0_met;
    } else {
        rtb_SFunction_b = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_g, rtb_S_LCRTTG_LeCridrBndPosY0_met, rtb_Div_j);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_i = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_n = DW_lcrttg_Unit_Delay1_DSTATE_e;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_g = rtb_S_LCRTTG_LeCridrBndHeadAng_rad;
    } else {
        rtb_SFunction_g = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_n, rtb_S_LCRTTG_LeCridrBndHeadAng_rad, rtb_Div_i);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_f = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_j = DW_lcrttg_Unit_Delay1_DSTATE_k;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_i = rtb_S_LCRTTG_LeCridrBndCrv_1pm;
    } else {
        rtb_SFunction_i = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_j, rtb_S_LCRTTG_LeCridrBndCrv_1pm, rtb_Div_f);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_f3 = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_i = DW_lcrttg_Unit_Delay1_DSTATE_n;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_f = rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2;
    } else {
        rtb_SFunction_f = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_i, rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2, rtb_Div_f3);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_l = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_js = DW_lcrttg_Unit_Delay1_DSTATE_i;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_o = rtb_S_LCRTTG_LeCridrBndLength_met;
    } else {
        rtb_SFunction_o = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_js, rtb_S_LCRTTG_LeCridrBndLength_met, rtb_Div_l);
    }
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/Constant'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/GT/Functionality'/GT'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_LCRTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Switch_hg = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Switch_hg = GET_P_LCRTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckRi/Constant1'/Constant'
         */
    rtb_Switch_hg = f32_max_f32_f32(rtb_Switch_hg, 1.0E-5F);
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_e = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_p = DW_lcrttg_Unit_Delay1_DSTATE_d;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_f1 = rtb_S_LCRTTG_RiCridrBndPosX0_met;
    } else {
        rtb_SFunction_f1 = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_p, rtb_S_LCRTTG_RiCridrBndPosX0_met, rtb_Div_e);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_op = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_nf = DW_lcrttg_Unit_Delay1_DSTATE_m;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_b0 = rtb_S_LCRTTG_RiCridrBndPosY0_met;
    } else {
        rtb_SFunction_b0 = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_nf, rtb_S_LCRTTG_RiCridrBndPosY0_met, rtb_Div_op);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_eq = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_jg = DW_lcrttg_Unit_Delay1_DSTATE_c;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_j = rtb_S_LCRTTG_RiCridrBndHeadAng_rad;
    } else {
        rtb_SFunction_j = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_jg, rtb_S_LCRTTG_RiCridrBndHeadAng_rad, rtb_Div_eq);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_ic = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_m = DW_lcrttg_Unit_Delay1_DSTATE_a;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_c = rtb_S_LCRTTG_RiCridrBndCrv_1pm;
    } else {
        rtb_SFunction_c = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_m, rtb_S_LCRTTG_RiCridrBndCrv_1pm, rtb_Div_ic);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_p = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_nw = DW_lcrttg_Unit_Delay1_DSTATE_ed;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_cj = rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2;
    } else {
        rtb_SFunction_cj = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_nw, rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2, rtb_Div_p);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_g = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_e = DW_lcrttg_Unit_Delay1_DSTATE_ns;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_e = rtb_S_LCRTTG_RiCridrBndLength_met;
    } else {
        rtb_SFunction_e = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_e, rtb_S_LCRTTG_RiCridrBndLength_met, rtb_Div_g);
    }
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/Constant'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/P_DPLTTG_TgtTrjPT1TimeConst_sec'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/GT/Functionality'/GT'
         *  Sum: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/Sum/Functionality'/Sum'
         */
    if (GET_S_LCFRCV_SysCycleTimeSen_sec() > GET_P_LCRTTG_TgtTrjPT1TimeConst_sec()) {
        rtb_Switch_hg = GET_S_LCFRCV_SysCycleTimeSen_sec() + 1.0E-5F;
    } else {
        rtb_Switch_hg = GET_P_LCRTTG_TgtTrjPT1TimeConst_sec();
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/Switch/Functionality'/Switch' */
    /* MinMax: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/Max/Functionality'/Max' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/TimeConstCheckTgt/Constant1'/Constant'
         */
    rtb_Switch_hg = f32_max_f32_f32(rtb_Switch_hg, 1.0E-5F);
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_a = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter'/Unit_Delay1' */
    rtb_Unit_Delay1_ei = DW_lcrttg_Unit_Delay1_DSTATE_p;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_ol = rtb_S_LCRTTG_TgtTrajPosX0_met;
    } else {
        rtb_SFunction_ol = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_ei, rtb_S_LCRTTG_TgtTrajPosX0_met, rtb_Div_a);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_pu = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1'/Unit_Delay1' */
    rtb_Unit_Delay1_l = DW_lcrttg_Unit_Delay1_DSTATE_df;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_k = rtb_S_LCRTTG_TgtTrajPosY0_met;
    } else {
        rtb_SFunction_k = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_l, rtb_S_LCRTTG_TgtTrajPosY0_met, rtb_Div_pu);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_m = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2'/Unit_Delay1' */
    rtb_Unit_Delay1_a = DW_lcrttg_Unit_Delay1_DSTATE_m0;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_e4 = rtb_S_LCRTTG_TgtTrajHeadAng_rad;
    } else {
        rtb_SFunction_e4 = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_a, rtb_S_LCRTTG_TgtTrajHeadAng_rad, rtb_Div_m);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_j3 = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3'/Unit_Delay1' */
    rtb_Unit_Delay1_c = DW_lcrttg_Unit_Delay1_DSTATE_ix;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_bg = rtb_S_LCRTTG_TgtTrajCrv_1pm;
    } else {
        rtb_SFunction_bg = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_c, rtb_S_LCRTTG_TgtTrajCrv_1pm, rtb_Div_j3);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_ik = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4'/Unit_Delay1' */
    rtb_Unit_Delay1_m0 = DW_lcrttg_Unit_Delay1_DSTATE_aq;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_bl = rtb_S_LCRTTG_TgtTrajCrvChng_1pm2;
    } else {
        rtb_SFunction_bl = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_m0, rtb_S_LCRTTG_TgtTrajCrvChng_1pm2, rtb_Div_ik);
    }
    /* Product: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         */
    rtb_Div_i3 = GET_S_LCFRCV_SysCycleTimeSen_sec() / rtb_Switch_hg;
    /* UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5'/Unit_Delay1' */
    rtb_Unit_Delay1_li = DW_lcrttg_Unit_Delay1_DSTATE_ib;
    /* S-Function (sfun_mmv): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_lcrttg_LogicalOperator != 0U) {
        rtb_SFunction_oj = rtb_S_LCRTTG_TgtTrajLength_met;
    } else {
        rtb_SFunction_oj = f32_mmv_f32_f32_f32( rtb_Unit_Delay1_li, rtb_S_LCRTTG_TgtTrajLength_met, rtb_Div_i3);
    }
    /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Application Parameter2'/Constant'
         *  Constant: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout/from_data_definition'/state_source'
         *  Inport: '<Root>/S_LCRSMI_SysStateALCA_nu'
         *  Logic: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Logical Operator/Functionality'/NOT'
         *  RelationalOperator: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout/Relational Operator2/Functionality'/EQ'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch'
         *  Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2'
         */
    if (((sint32)GET_S_LCRSMI_SysStateALCA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
        rtb_Switch_hg = DW_lcrttg_FixPtUnitDelay2_1_DSTATE;
        rtb_S_LCRTTG_RiCridrBndCrv_1pm_g = DW_lcrttg_FixPtUnitDelay2_10_DSTATE;
        rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2_gm = DW_lcrttg_FixPtUnitDelay2_11_DSTATE;
        rtb_S_LCRTTG_RiCridrBndLength_met_n = DW_lcrttg_FixPtUnitDelay2_12_DSTATE;
        rtb_S_LCRTTG_TgtTrajPosX0_met_o = DW_lcrttg_FixPtUnitDelay2_13_DSTATE;
        rtb_S_LCRTTG_TgtTrajPosY0_met_e = DW_lcrttg_FixPtUnitDelay2_14_DSTATE;
        rtb_S_LCRTTG_TgtTrajHeadAng_rad_f = DW_lcrttg_FixPtUnitDelay2_15_DSTATE;
        rtb_S_LCRTTG_TgtTrajCrv_1pm_n = DW_lcrttg_FixPtUnitDelay2_16_DSTATE;
        rtb_S_LCRTTG_TgtTrajCrvChng_1pm2_e = DW_lcrttg_FixPtUnitDelay2_17_DSTATE;
        rtb_S_LCRTTG_TgtTrajLength_met_oz = DW_lcrttg_FixPtUnitDelay2_18_DSTATE;
        rtb_S_LCRTTG_LeCridrBndPosY0_met_l = DW_lcrttg_FixPtUnitDelay2_2_DSTATE;
        rtb_S_LCRTTG_LeCridrBndHeadAng_rad_b = DW_lcrttg_FixPtUnitDelay2_3_DSTATE;
        rtb_S_LCRTTG_LeCridrBndCrv_1pm_c = DW_lcrttg_FixPtUnitDelay2_4_DSTATE;
        rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2_i = DW_lcrttg_FixPtUnitDelay2_5_DSTATE;
        rtb_S_LCRTTG_LeCridrBndLength_met_e = DW_lcrttg_FixPtUnitDelay2_6_DSTATE;
        rtb_S_LCRTTG_RiCridrBndPosX0_met_cl = DW_lcrttg_FixPtUnitDelay2_7_DSTATE;
        rtb_S_LCRTTG_RiCridrBndPosY0_met_o = DW_lcrttg_FixPtUnitDelay2_8_DSTATE;
        rtb_S_LCRTTG_RiCridrBndHeadAng_rad_g = DW_lcrttg_FixPtUnitDelay2_9_DSTATE;
    } else if (!(((sint32)GET_P_LCRTTG_TargetTrajPT1Active_nu()) != 0)) {
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_Switch_hg = rtb_S_LCRTTG_LeCridrBndPosX0_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_RiCridrBndCrv_1pm_g = rtb_S_LCRTTG_RiCridrBndCrv_1pm;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2_gm = rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_RiCridrBndLength_met_n = rtb_S_LCRTTG_RiCridrBndLength_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_TgtTrajPosX0_met_o = rtb_S_LCRTTG_TgtTrajPosX0_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_TgtTrajPosY0_met_e = rtb_S_LCRTTG_TgtTrajPosY0_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_TgtTrajHeadAng_rad_f = rtb_S_LCRTTG_TgtTrajHeadAng_rad;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_TgtTrajCrv_1pm_n = rtb_S_LCRTTG_TgtTrajCrv_1pm;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_TgtTrajCrvChng_1pm2_e = rtb_S_LCRTTG_TgtTrajCrvChng_1pm2;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_TgtTrajLength_met_oz = rtb_S_LCRTTG_TgtTrajLength_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_LeCridrBndPosY0_met_l = rtb_S_LCRTTG_LeCridrBndPosY0_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_LeCridrBndHeadAng_rad_b = rtb_S_LCRTTG_LeCridrBndHeadAng_rad;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_LeCridrBndCrv_1pm_c = rtb_S_LCRTTG_LeCridrBndCrv_1pm;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2_i = rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_LeCridrBndLength_met_e = rtb_S_LCRTTG_LeCridrBndLength_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_RiCridrBndPosX0_met_cl = rtb_S_LCRTTG_RiCridrBndPosX0_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_RiCridrBndPosY0_met_o = rtb_S_LCRTTG_RiCridrBndPosY0_met;
        /* Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/Switch/Functionality'/Switch' */
        rtb_S_LCRTTG_RiCridrBndHeadAng_rad_g = rtb_S_LCRTTG_RiCridrBndHeadAng_rad;
    } else {
        rtb_Switch_hg = rtb_SFunction;
        rtb_S_LCRTTG_RiCridrBndCrv_1pm_g = rtb_SFunction_c;
        rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2_gm = rtb_SFunction_cj;
        rtb_S_LCRTTG_RiCridrBndLength_met_n = rtb_SFunction_e;
        rtb_S_LCRTTG_TgtTrajPosX0_met_o = rtb_SFunction_ol;
        rtb_S_LCRTTG_TgtTrajPosY0_met_e = rtb_SFunction_k;
        rtb_S_LCRTTG_TgtTrajHeadAng_rad_f = rtb_SFunction_e4;
        rtb_S_LCRTTG_TgtTrajCrv_1pm_n = rtb_SFunction_bg;
        rtb_S_LCRTTG_TgtTrajCrvChng_1pm2_e = rtb_SFunction_bl;
        rtb_S_LCRTTG_TgtTrajLength_met_oz = rtb_SFunction_oj;
        rtb_S_LCRTTG_LeCridrBndPosY0_met_l = rtb_SFunction_b;
        rtb_S_LCRTTG_LeCridrBndHeadAng_rad_b = rtb_SFunction_g;
        rtb_S_LCRTTG_LeCridrBndCrv_1pm_c = rtb_SFunction_i;
        rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2_i = rtb_SFunction_f;
        rtb_S_LCRTTG_LeCridrBndLength_met_e = rtb_SFunction_o;
        rtb_S_LCRTTG_RiCridrBndPosX0_met_cl = rtb_SFunction_f1;
        rtb_S_LCRTTG_RiCridrBndPosY0_met_o = rtb_SFunction_b0;
        rtb_S_LCRTTG_RiCridrBndHeadAng_rad_g = rtb_SFunction_j;
    }
    /* End of Switch: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout/Switch1/Functionality'/Switch' */
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch'/copy1' */
    SET_S_LCRTTG_LeCridrBndPosX0_met(rtb_Switch_hg);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch1'/copy1' */
    SET_S_LCRTTG_LeCridrBndPosY0_met(rtb_S_LCRTTG_LeCridrBndPosY0_met_l);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch10'/copy1' */
    SET_S_LCRTTG_RiCridrBndCrvChng_1pm2(rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2_gm);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch11'/copy1' */
    SET_S_LCRTTG_RiCridrBndLength_met(rtb_S_LCRTTG_RiCridrBndLength_met_n);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch12'/copy1' */
    SET_S_LCRTTG_TgtTrajPosX0_met(rtb_S_LCRTTG_TgtTrajPosX0_met_o);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch13'/copy1' */
    SET_S_LCRTTG_TgtTrajPosY0_met(rtb_S_LCRTTG_TgtTrajPosY0_met_e);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch14'/copy1' */
    SET_S_LCRTTG_TgtTrajHeadAng_rad(rtb_S_LCRTTG_TgtTrajHeadAng_rad_f);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch15'/copy1' */
    SET_S_LCRTTG_TgtTrajCrv_1pm(rtb_S_LCRTTG_TgtTrajCrv_1pm_n);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch16'/copy1' */
    SET_S_LCRTTG_TgtTrajCrvChng_1pm2(rtb_S_LCRTTG_TgtTrajCrvChng_1pm2_e);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch17'/copy1' */
    SET_S_LCRTTG_TgtTrajLength_met(rtb_S_LCRTTG_TgtTrajLength_met_oz);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch19'/copy1' */
    SET_S_LCRTTG_LeTgtTrajPosY0_met(rtb_Sum_ls);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch2'/copy1' */
    SET_S_LCRTTG_LeCridrBndHeadAng_rad(rtb_S_LCRTTG_LeCridrBndHeadAng_rad_b);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch20'/copy1' */
    SET_S_LCRTTG_RiTgtTrajPosY0_met(rtb_Sum);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch3'/copy1' */
    SET_S_LCRTTG_LeCridrBndCrv_1pm(rtb_S_LCRTTG_LeCridrBndCrv_1pm_c);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch4'/copy1' */
    SET_S_LCRTTG_LeCridrBndCrvChng_1pm2(rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2_i);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch5'/copy1' */
    SET_S_LCRTTG_LeCridrBndLength_met(rtb_S_LCRTTG_LeCridrBndLength_met_e);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch6'/copy1' */
    SET_S_LCRTTG_RiCridrBndPosX0_met(rtb_S_LCRTTG_RiCridrBndPosX0_met_cl);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch7'/copy1' */
    SET_S_LCRTTG_RiCridrBndPosY0_met(rtb_S_LCRTTG_RiCridrBndPosY0_met_o);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch8'/copy1' */
    SET_S_LCRTTG_RiCridrBndHeadAng_rad(rtb_S_LCRTTG_RiCridrBndHeadAng_rad_g);
    /* SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/branch9'/copy1' */
    SET_S_LCRTTG_RiCridrBndCrv_1pm(rtb_S_LCRTTG_RiCridrBndCrv_1pm_g);
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay1' */
    DW_lcrttg_FixPtUnitDelay1_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/LeftRightCorridor'/FixPt Unit Delay3' */
    DW_lcrttg_FixPtUnitDelay3_DSTATE = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay4' */
    DW_lcrttg_FixPtUnitDelay4_DSTATE = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay3' */
    DW_lcrttg_FixPtUnitDelay3_DSTATE_e = rtb_DataTypeConversion;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay1' */
    DW_lcrttg_FixPtUnitDelay1_DSTATE_k = rtb_Switch_e;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev'/FixPt Unit Delay4' */
    DW_lcrttg_FixPtUnitDelay4_DSTATE_n = rtb_Switch_p;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay5' */
    DW_lcrttg_FixPtUnitDelay5_DSTATE = rtb_Switch_k4;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_DSTATE = rtb_Div;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/ALCA_TargetTrajGeneratorSys/TargetCorridor/TargetLateralDistanceCalculation1/LeTgtMaxLatDev1'/FixPt Unit Delay4' */
    DW_lcrttg_FixPtUnitDelay4_DSTATE_e = rtb_Switch_o;
    /* S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_lcrttg_Unit_Delay_DSTATE = rtb_EQ;
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/EdgeRising/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE = rtb_SFunction;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter1'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_b = rtb_SFunction_b;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter2'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_e = rtb_SFunction_g;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter3'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_k = rtb_SFunction_i;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter4'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_n = rtb_SFunction_f;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsLe/PT1Filter5'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_i = rtb_SFunction_o;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_d = rtb_SFunction_f1;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter1'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_m = rtb_SFunction_b0;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter2'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_c = rtb_SFunction_j;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter3'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_a = rtb_SFunction_c;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter4'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_ed = rtb_SFunction_cj;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsRi/PT1Filter5'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_ns = rtb_SFunction_e;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_p = rtb_SFunction_ol;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter1'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_df = rtb_SFunction_k;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter2'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_m0 = rtb_SFunction_e4;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter3'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_ix = rtb_SFunction_bg;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter4'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_aq = rtb_SFunction_bl;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Filter_ALCA_TargetTraj/PT1FilterClothoidParamsTgt/PT1Filter5'/Unit_Delay1' */
    DW_lcrttg_Unit_Delay1_DSTATE_ib = rtb_SFunction_oj;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_1_DSTATE = rtb_Switch_hg;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_10_DSTATE = rtb_S_LCRTTG_RiCridrBndCrv_1pm_g;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_11_DSTATE = rtb_S_LCRTTG_RiCridrBndCrvChng_1pm2_gm;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_12_DSTATE = rtb_S_LCRTTG_RiCridrBndLength_met_n;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_13_DSTATE = rtb_S_LCRTTG_TgtTrajPosX0_met_o;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_14_DSTATE = rtb_S_LCRTTG_TgtTrajPosY0_met_e;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_15_DSTATE = rtb_S_LCRTTG_TgtTrajHeadAng_rad_f;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_16_DSTATE = rtb_S_LCRTTG_TgtTrajCrv_1pm_n;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_17_DSTATE = rtb_S_LCRTTG_TgtTrajCrvChng_1pm2_e;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_18_DSTATE = rtb_S_LCRTTG_TgtTrajLength_met_oz;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_2_DSTATE = rtb_S_LCRTTG_LeCridrBndPosY0_met_l;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_3_DSTATE = rtb_S_LCRTTG_LeCridrBndHeadAng_rad_b;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_4_DSTATE = rtb_S_LCRTTG_LeCridrBndCrv_1pm_c;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_5_DSTATE = rtb_S_LCRTTG_LeCridrBndCrvChng_1pm2_i;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_6_DSTATE = rtb_S_LCRTTG_LeCridrBndLength_met_e;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_7_DSTATE = rtb_S_LCRTTG_RiCridrBndPosX0_met_cl;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_8_DSTATE = rtb_S_LCRTTG_RiCridrBndPosY0_met_o;
    /* Update for UnitDelay: 'sda:LCRTTG/LCRTTG/LCRTTG_SenProcess/OPM/Rampout'/FixPt Unit Delay2' */
    DW_lcrttg_FixPtUnitDelay2_9_DSTATE = rtb_S_LCRTTG_RiCridrBndHeadAng_rad_g;
}
#include "Pse_LCRTTG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
