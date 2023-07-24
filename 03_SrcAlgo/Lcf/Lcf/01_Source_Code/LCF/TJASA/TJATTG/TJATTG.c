/**************************************************************************
COPYRIGHT (C) $Date: 2019/08/29 10:04:43CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.
The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------
$ProjectName: /ADAS/SW/Components/LCF_LateralControlFunctions/03_Design/03_Code_Generation/Generic/LCF/Model/TJASA/TJATTG_SEN/TJATTG/i/project.pj $
$Log: TJATTG.c  $
Revision 1.5 2019/08/29 10:04:43CEST Werum, Gregor (uidq2175) 
Module test update according to findings (FCT_CMP_TJASA_1577, FCT_CMP_TJASA_2145)
Revision 1.43 2019/06/14 14:47:22CEST Fen, Alexander (TFPE05) 
ZDV protection added
File          : TJATTG
Generated on  : Fri 14.06.2019 at 14:35:41 (UTC+01:00)
MD5           : [838288378  4106767285   195537089  2543126060 0](TJATTG)
Environment information:
Processor     : 32 Bit generic
Platform      : EMS3
SDA version   : 10.0
Hot fixes     : SDA-Core: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,79
Add-ons       : -
*************************************************************************/
/* Lint specific include */
#include "lintopt_acg.h"
/* General includes */
#include "TJATTG.h"
#include "TJATTG_private.h"
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
#define TJATTG_START_SEC_DATA_8
#include "TJATTG_MemMap.h"
static uint8 BI_tjattg_LogicalOperator_p;
/* 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_tjattg_LogicalOperator_e;
/* 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_tjattg_LogicalOperator_e0;
/* 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_tjattg_LogicalOperator_i;
/* 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_tjattg_LogicalOperator_i0;
/* 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 BI_tjattg_LogicalOperator_b;
/* 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' */
static uint8 DW_tjattg_Unit_Delay2_DSTATE_a;
static uint8 DW_tjattg_Unit_Delay1_DSTATE_f;
static uint8 DW_tjattg_Unit_Delay5_DSTATE_k;
static uint8 DW_tjattg_Unit_Delay5_DSTATE_i;
static uint8 DW_tjattg_Unit_Delay4_DSTATE_l;
static uint8 DW_tjattg_Unit_Delay7_DSTATE;
static uint8 DW_tjattg_Unit_Delay6_DSTATE_h;
static uint8 DW_tjattg_Unit_Delay3_DSTATE_l;
static uint8 DW_tjattg_Unit_Delay2_DSTATE_cx;
static uint8 DW_tjattg_Unit_Delay1_DSTATE_j;
static uint8 DW_tjattg_Unit_Delay_DSTATE_l;
static uint8 DW_tjattg_Unit_Delay9_DSTATE;
static uint8 DW_tjattg_Unit_Delay8_DSTATE;
static uint8 DW_tjattg_Unit_Delay_DSTATE_fj;
static uint8 DW_tjattg_Unit_Delay1_DSTATE_p;
static uint8 DW_tjattg_Unit_Delay3_DSTATE_m;
static uint8 DW_tjattg_Unit_Delay5_DSTATE_j;
static uint8 DW_tjattg_Unit_Delay_DSTATE_az;
static uint8 DW_tjattg_Unit_Delay2_DSTATE_l;
static uint8 DW_tjattg_Unit_Delay2_DSTATE_f;
static uint8 DW_tjattg_Unit_Delay2_DSTATE_p;
static uint8 DW_tjattg_Unit_Delay_DSTATE_lt;
static uint8 DW_tjattg_Unit_Delay1_DSTATE_a;
static uint8 DW_tjattg_Unit_Delay1_DSTATE_b;
static uint8 DW_tjattg_Unit_Delay_DSTATE_fi;
static uint8 DW_tjattg_Unit_Delay_DSTATE_o0;
static uint8 DW_tjattg_Unit_Delay_DSTATE_kt;
static uint8 DW_tjattg_Unit_Delay_DSTATE_g;
static uint8 DW_tjattg_Unit_Delay_DSTATE_na;
static uint8 DW_tjattg_Unit_Delay_DSTATE_nk;
#define TJATTG_STOP_SEC_DATA_8
#include "TJATTG_MemMap.h"
#define TJATTG_START_SEC_DATA_32
#include "TJATTG_MemMap.h"
static float32 DW_tjattg_Unit_Delay_DSTATE;
static float32 DW_tjattg_Unit_Delay_DSTATE_e;
static float32 DW_tjattg_Unit_Delay_DSTATE_o;
static float32 DW_tjattg_Unit_Delay1_DSTATE;
static float32 DW_tjattg_Unit_Delay_DSTATE_n;
static float32 DW_tjattg_Unit_Delay_DSTATE_m;
static float32 DW_tjattg_Unit_Delay_DSTATE_d;
static float32 DW_tjattg_Unit_Delay_DSTATE_c;
static float32 DW_tjattg_Unit_Delay_DSTATE_a;
static float32 DW_tjattg_Unit_Delay_DSTATE_cg;
static float32 DW_tjattg_Unit_Delay_DSTATE_i;
static float32 DW_tjattg_Unit_Delay2_DSTATE;
static float32 DW_tjattg_Unit_Delay_DSTATE_b;
static float32 DW_tjattg_Unit_Delay_DSTATE_n5;
static float32 DW_tjattg_Unit_Delay_DSTATE_oj;
static float32 DW_tjattg_Unit_Delay_DSTATE_f;
static float32 DW_tjattg_Unit_Delay_DSTATE_h;
static float32 DW_tjattg_Unit_Delay_DSTATE_p;
static float32 DW_tjattg_Unit_Delay_DSTATE_hs;
static float32 DW_tjattg_Unit_Delay_DSTATE_ie;
static float32 DW_tjattg_Unit_Delay_DSTATE_eg;
static float32 DW_tjattg_Unit_Delay_DSTATE_ij;
static float32 DW_tjattg_Unit_Delay_DSTATE_k;
static float32 DW_tjattg_Unit_Delay_DSTATE_h4;
static float32 DW_tjattg_Unit_Delay_DSTATE_ba;
static float32 DW_tjattg_Unit_Delay2_DSTATE_n;
static float32 DW_tjattg_Unit_Delay_2_DSTATE;
static float32 DW_tjattg_Unit_Delay1_DSTATE_n;
static float32 DW_tjattg_Unit_Delay5_DSTATE;
static float32 DW_tjattg_Unit_Delay1_DSTATE_k;
static float32 DW_tjattg_Unit_Delay_3_DSTATE;
static float32 DW_tjattg_Unit_Delay3_DSTATE;
static float32 DW_tjattg_Unit_Delay_4_DSTATE;
static float32 DW_tjattg_Unit_Delay4_DSTATE;
static float32 DW_tjattg_Unit_Delay_5_DSTATE;
static float32 DW_tjattg_Unit_Delay5_DSTATE_g;
static float32 DW_tjattg_Unit_Delay_6_DSTATE;
static float32 DW_tjattg_Unit_Delay6_DSTATE;
static float32 DW_tjattg_Unit_Delay_1_DSTATE;
static float32 DW_tjattg_Unit_Delay2_DSTATE_h;
static float32 DW_tjattg_Unit_Delay_8_DSTATE;
static float32 DW_tjattg_Unit_Delay1_DSTATE_kv;
static float32 DW_tjattg_Unit_Delay_9_DSTATE;
static float32 DW_tjattg_Unit_Delay3_DSTATE_i;
static float32 DW_tjattg_Unit_Delay_10_DSTATE;
static float32 DW_tjattg_Unit_Delay4_DSTATE_b;
static float32 DW_tjattg_Unit_Delay_11_DSTATE;
static float32 DW_tjattg_Unit_Delay5_DSTATE_l;
static float32 DW_tjattg_Unit_Delay_12_DSTATE;
static float32 DW_tjattg_Unit_Delay6_DSTATE_a;
static float32 DW_tjattg_Unit_Delay_7_DSTATE;
static float32 DW_tjattg_Unit_Delay2_DSTATE_c;
static float32 DW_tjattg_Unit_Delay_14_DSTATE;
static float32 DW_tjattg_Unit_Delay1_DSTATE_d;
static float32 DW_tjattg_Unit_Delay_15_DSTATE;
static float32 DW_tjattg_Unit_Delay3_DSTATE_if;
static float32 DW_tjattg_Unit_Delay_16_DSTATE;
static float32 DW_tjattg_Unit_Delay4_DSTATE_a;
static float32 DW_tjattg_Unit_Delay_17_DSTATE;
static float32 DW_tjattg_Unit_Delay5_DSTATE_b;
static float32 DW_tjattg_Unit_Delay_18_DSTATE;
static float32 DW_tjattg_Unit_Delay6_DSTATE_f;
static float32 DW_tjattg_Unit_Delay_13_DSTATE;
static float32 DW_tjattg_Unit_Delay1_1_DSTATE;
static float32 DW_tjattg_Unit_Delay1_2_DSTATE;
static float32 DW_tjattg_Unit_Delay1_3_DSTATE;
static float32 DW_tjattg_Unit_Delay1_4_DSTATE;
static float32 DW_tjattg_Unit_Delay1_5_DSTATE;
static float32 DW_tjattg_Unit_Delay1_6_DSTATE;
static float32 DW_tjattg_Unit_Delay1_7_DSTATE;
static float32 DW_tjattg_Unit_Delay1_8_DSTATE;
static float32 DW_tjattg_Unit_Delay1_9_DSTATE;
static float32 DW_tjattg_Unit_Delay1_10_DSTATE;
static float32 DW_tjattg_Unit_Delay1_11_DSTATE;
static float32 DW_tjattg_Unit_Delay1_12_DSTATE;
static float32 DW_tjattg_Unit_Delay1_13_DSTATE;
static float32 DW_tjattg_Unit_Delay1_14_DSTATE;
static float32 DW_tjattg_Unit_Delay1_15_DSTATE;
static float32 DW_tjattg_Unit_Delay1_16_DSTATE;
static float32 DW_tjattg_Unit_Delay1_17_DSTATE;
static float32 DW_tjattg_Unit_Delay1_18_DSTATE;
#define TJATTG_STOP_SEC_DATA_32
#include "TJATTG_MemMap.h"
/* End of General Declarations */
/* Specific Declarations */
/* End of Specific Declarations */
/* Embedded Coder utility function definitions */
/* no forward declarations needed */
/* no utility functions needed */
/* End of Embedded Coder utility function definitions */
/* General Functions */
/*
 * Output and update for function-call system: 'sda:TJATTG/TJATTG/INI'/TJATTG_SenReset'
 * Block description for: 'sda:TJATTG/TJATTG/INI'/TJATTG_SenReset'
 *   X.1.1
 */
#define RUNNABLE_ID RUNNABLE_ID_TJATTG_SenReset
#include "Pse_TJATTG.h"
/* Short description: Not synchronized with ARAMIS */
void TJATTG_SenReset(void)
{
    /* Function local data */
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant'/Constant' */
    SET_S_TJATTG_LeCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant1'/Constant' */
    SET_S_TJATTG_LeCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant10'/Constant' */
    SET_S_TJATTG_RiCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant11'/Constant' */
    SET_S_TJATTG_RiCridrBndLength_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant12'/Constant' */
    SET_S_TJATTG_TgtTrajPosX0_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant13'/Constant' */
    SET_S_TJATTG_TgtTrajPosY0_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant14'/Constant' */
    SET_S_TJATTG_TgtTrajHeadAng_rad(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant15'/Constant' */
    SET_S_TJATTG_TgtTrajCrv_1pm(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant16'/Constant' */
    SET_S_TJATTG_TgtTrajCrvChng_1pm2(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant17'/Constant' */
    SET_S_TJATTG_TgtTrajLength_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant18'/Constant' */
    SET_D_TJATTG_TgtCorridorInvalid_btf(0U);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant19'/Constant' */
    SET_S_TJATTG_PredictionEnable_bool(0U);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant2'/Constant' */
    SET_S_TJATTG_LeCridrBndHeadAng_rad(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant20'/Constant' */
    SET_S_TJATTG_TransTriggerReplan_bool(0U);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant3'/Constant' */
    SET_S_TJATTG_LeCridrBndCrv_1pm(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant4'/Constant' */
    SET_S_TJATTG_LeCridrBndCrvChng_1pm2(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant5'/Constant' */
    SET_S_TJATTG_LeCridrBndLength_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant6'/Constant' */
    SET_S_TJATTG_RiCridrBndPosX0_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant7'/Constant' */
    SET_S_TJATTG_RiCridrBndPosY0_met(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant8'/Constant' */
    SET_S_TJATTG_RiCridrBndHeadAng_rad(0.0F);
    /* Constant: 'sda:TJATTG/TJATTG/INI/TJATTG_SenReset/Constant9'/Constant' */
    SET_S_TJATTG_RiCridrBndCrv_1pm(0.0F);
}
#include "Pse_TJATTG.h"
/*
 * Output and update for function-call system: 'sda:TJATTG/TJATTG'/TJATTG_SenProcess'
 * Block description for: 'sda:TJATTG/TJATTG'/TJATTG_SenProcess'
 *   X.2
 */
#define RUNNABLE_ID RUNNABLE_ID_TJATTG_SenProcess
#include "Pse_TJATTG.h"
/* Short description: Not synchronized with ARAMIS */
void TJATTG_SenProcess(void)
{
    /* Function local data */
    /* local block i/o variables */
    float32 rtb_Div;
    float32 rtb_Switch_i;
    float32 rtb_Unit_Delay_j;
    float32 rtb_SFunction;
    float32 rtb_Div_o;
    float32 rtb_Switch_p;
    float32 rtb_Unit_Delay_g;
    float32 rtb_SFunction_b;
    float32 rtb_Div_g;
    float32 rtb_Switch_o;
    float32 rtb_Unit_Delay_gs;
    float32 rtb_SFunction_d;
    float32 rtb_Div_oe;
    float32 rtb_Switch_ov;
    float32 rtb_Unit_Delay_m;
    float32 rtb_SFunction_l;
    float32 rtb_Div_b;
    float32 rtb_Switch_pp;
    float32 rtb_Unit_Delay_hj;
    float32 rtb_SFunction_m;
    float32 rtb_Div_ou;
    float32 rtb_Switch_na;
    float32 rtb_Unit_Delay_oa;
    float32 rtb_SFunction_j;
    uint16 rtb_sfun_setbit;
    uint8 rtb_SignalConversion1;
    uint8 rtb_VectorConcatenate[16];
    uint8 rtb_Switch_jmj;
    uint8 rtb_DataTypeConversion_f;
    uint8 rtb_DataTypeConversion;
    uint8 rtb_DataTypeConversion_ir;
    uint8 rtb_DataTypeConversion_b4;
    uint8 rtb_DataTypeConversion_ji;
    uint8 rtb_DataTypeConversion_lq;
    uint8 rtb_DataTypeConversion_h5;
    uint8 rtb_DataTypeConversion_c5;
    uint8 rtb_DataTypeConversion_o;
    uint8 rtb_DataTypeConversion_a4;
    uint8 rtb_DataTypeConversion_d;
    float32 rtb_Switch;
    uint8 rtb_DataTypeConversion_i;
    uint8 rtb_Switch_kog;
    uint8 rtb_Switch_pi;
    uint8 rtb_Switch_hs;
    uint8 rtb_DataTypeConversion_ab;
    float32 rtb_Mul;
    float32 rtb_Sum_bg;
    float32 rtb_Mul_ac;
    float32 rtb_Switch_crb;
    float32 rtb_Switch1_g;
    float32 rtb_Sum;
    uint8 rtb_DataTypeConversion_k;
    float32 rtb_Switch_mv;
    float32 rtb_Sum_mx;
    uint8 rtb_DataTypeConversion_g;
    float32 rtb_Switch_dw;
    float32 rtb_Mul_nl;
    float32 rtb_Switch1_h;
    float32 rtb_Switch_cl;
    float32 rtb_Switch1;
    float32 rtb_Mul_oo;
    float32 rtb_MathFunction;
    float32 rtb_Switch_l4;
    float32 rtb_Switch_lqw;
    float32 rtb_Mul_k5;
    float32 rtb_MathFunction_k;
    float32 rtb_Switch_n;
    float32 rtb_Mul_cy;
    float32 rtb__Heading_rad_d;
    float32 rtb__Crv_1pm_l1;
    float32 rtb__Crv_1pm_go;
    float32 rtb__ChngOfCrv_1pm2_ji;
    float32 rtb__ChngOfCrv_1pm2_k;
    float32 rtb__ChngOfCrv_1pm2_ai;
    float32 rtb__TrajLength_met_hg;
    float32 rtb__TrajLength_met_i;
    float32 rtb__TrajLength_met_p;
    float32 rtb_Div_j;
    float32 rtb__PosX0_met_mb;
    float32 rtb__PosY0_met_le;
    float32 rtb_Switch_hw;
    float32 rtb__Crv_1pm_e1;
    float32 rtb__ChngOfCrv_1pm2_l;
    float32 rtb__TrajLength_met_ih;
    float32 rtb__PosX0_met_g;
    float32 rtb__Crv_1pm;
    float32 rtb__ChngOfCrv_1pm2;
    float32 rtb_Switch_l;
    float32 rtb_Switch_iz;
    float32 rtb_Switch3;
    float32 rtb_Switch_aec;
    float32 rtb_Switch_bxu;
    float32 rtb_Switch_g;
    float32 rtb_Switch_cv;
    float32 rtb_Switch_ey;
    float32 rtb_Sum_hf;
    float32 rtb_Switch_oa;
    float32 rtb_Switch_e;
    float32 rtb_Switch_ph;
    float32 rtb_Switch_kw;
    float32 rtb_Switch_h;
    float32 rtb_Switch_k2;
    float32 rtb_Switch_kv;
    uint8 LogicalOperator_n;
    uint8 SignalConversion;
    /* Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/Constant1'/Constant' */
    rtb_VectorConcatenate[3] = 0U;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/from_data_definition4'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/from_data_definition6'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/OR/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/OR2/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/OR3/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/OR5/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/Relational Operator4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/Relational Operator5/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/Relational Operator6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/Relational Operator8/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckLaneUpdateConditions/Relational Operator9/Functionality'/EQ'
         */
    rtb_DataTypeConversion = (uint8)((((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC_RQ)))) || ((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))))) || ((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))));
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn1' */
    rtb_VectorConcatenate[0] = rtb_DataTypeConversion;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition10'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition14'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition16'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition17'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition18'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition8'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_TJASLC_ManeuverState_nu'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/AND3/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/OR1/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/OR2/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ10/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ11/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ12/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ7/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ8/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForEgoLaneSelection/EQ9/Functionality'/EQ'
         */
    rtb_DataTypeConversion_f = (uint8)(((((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC_RQ)))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ)))) || ((((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC))) && ((((((sint32) GET_S_TJASLC_ManeuverState_nu()) == ((sint32)((uint8) E_TJASLC_MnvStateType_E_TJASLC_LCPSTART))) || (((sint32) GET_S_TJASLC_ManeuverState_nu()) == ((sint32)((uint8) E_TJASLC_MnvStateType_E_TJASLC_NEWEGO)))) || (((sint32) GET_S_TJASLC_ManeuverState_nu()) == ((sint32)((uint8) E_TJASLC_MnvStateType_E_TJASLC_LCMEND)))) || (((sint32) GET_S_TJASLC_ManeuverState_nu()) == ((sint32)((uint8) E_TJASLC_MnvStateType_E_TJASLC_ABORT))))));
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn10' */
    rtb_VectorConcatenate[9] = rtb_DataTypeConversion_f;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/AND2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/from_data_definition14'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_TJASLC_ManeuverState_nu'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/AND2/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/EQ8/Functionality'/EQ'
         */
    rtb_Switch_jmj = (uint8)((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC))) && ((((sint32)GET_S_TJASLC_ManeuverState_nu()) == ((sint32)((uint8) E_TJASLC_MnvStateType_E_TJASLC_LATMVSTART))) || (((sint32) GET_S_TJASLC_ManeuverState_nu()) == ((sint32)((uint8) E_TJASLC_MnvStateType_E_TJASLC_LCMSTART)))));
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/from_data_definition15'/state_source'
         *  Inport: '<Root>/S_TJASLC_LaneChangeTrig_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/EQ4/Functionality'/EQ'
         */
    rtb_DataTypeConversion_ir = (uint8)((((sint32)rtb_Switch_jmj) != 0) && (((sint32)((uint8)E_TJASTM_LnChngTriggerType_E_TJASTM_LNCHNG_LEFT_TRIG)) == ((sint32)GET_S_TJASLC_LaneChangeTrig_nu())));
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn11' */
    rtb_VectorConcatenate[10] = rtb_DataTypeConversion_ir;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/from_data_definition1'/state_source'
         *  Inport: '<Root>/S_TJASLC_LaneChangeTrig_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/AND1/Functionality'/AND'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CheckSystemStatesForAdjacentLaneSelection/EQ6/Functionality'/EQ'
         */
    rtb_DataTypeConversion_b4 = (uint8)((((sint32)rtb_Switch_jmj) != 0) && (((sint32)GET_S_TJASLC_LaneChangeTrig_nu()) == ((sint32)((uint8) E_TJASTM_LnChngTriggerType_E_TJASTM_LNCHNG_RIGHT_TRIG))));
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn12' */
    rtb_VectorConcatenate[11] = rtb_DataTypeConversion_b4;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND6/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition14'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND6/Functionality'/AND'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ13/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ14/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions'/Unit_Delay5'
         */
    rtb_Switch_jmj = (uint8)((((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) GET_S_TJASTM_SysStateTJA_nu())) && (((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) DW_tjattg_Unit_Delay5_DSTATE_k)));
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/OR/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition8'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition12'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition14'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition8'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND7/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND8/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/AND2/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/AND5/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/OR/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ13/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ14/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ5/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ5/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions'/Unit_Delay1'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay4'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay5'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay6'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay7'
         */
    rtb_DataTypeConversion_ji = (uint8)(((((((sint32)GET_S_TJASTM_LatCtrlMode_nu ()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF))) && (((sint32)DW_tjattg_Unit_Delay1_DSTATE_f) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)))) && (((sint32) rtb_Switch_jmj) != 0)) || ((((sint32)rtb_Switch_jmj) != 0) && (((((sint32) DW_tjattg_Unit_Delay5_DSTATE_i) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))) && (((sint32) DW_tjattg_Unit_Delay4_DSTATE_l) != 0)))) || ((((sint32)rtb_Switch_jmj) != 0) && (((((sint32)DW_tjattg_Unit_Delay7_DSTATE) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))) && (((sint32) DW_tjattg_Unit_Delay6_DSTATE_h) != 0))));
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/OR3/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition10'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition2'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition3'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition9'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/Constant2'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition1'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition15'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition17'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition3'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND1/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND10/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND4/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND9/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/AND1/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/AND7/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/OR3/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ16/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ18/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ10/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ9/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions'/Unit_Delay1'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay3'
         */
    rtb_DataTypeConversion_h5 = (uint8)(((((((sint32)rtb_Switch_jmj) != 0) && ((((((sint32)DW_tjattg_Unit_Delay3_DSTATE_l) != 0) && (((sint32) GET_S_TJACMB_CombinedMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) && (((sint32) GET_P_TJATTG_TriggerReplanCMBLC2OF_bool()) != 0))) || ((((sint32) rtb_Switch_jmj) != 0) && (((((sint32)DW_tjattg_Unit_Delay2_DSTATE_cx) != 0) && (((sint32)GET_S_TJACMB_CombinedMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))))) || (((((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32) DW_tjattg_Unit_Delay1_DSTATE_f) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)))) && (((sint32) rtb_Switch_jmj) != 0))) || (((((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32)DW_tjattg_Unit_Delay1_DSTATE_f) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))) && (((sint32) rtb_Switch_jmj) != 0)));
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/Constant'/Constant'
         *  Inport: '<Root>/S_TJALKA_LanePredictValid_bool'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/AND/Functionality'/AND'
         */
    rtb_DataTypeConversion_c5 = (uint8)((((sint32) GET_P_TJATTG_NewPredEnable_bool()) != 0) && (((sint32) GET_S_TJALKA_LanePredictValid_bool()) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/Constant1'/Constant'
         *  Inport: '<Root>/S_TJALKA_LanePredictValid_bool'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/AND1/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/NOT/Functionality'/NOT'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/NOT1/Functionality'/NOT'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/OR/Functionality'/OR'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Switch1'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising'/Unit_Delay1'
         */
    if ((!(((sint32)GET_S_TJALKA_LanePredictValid_bool()) != 0)) || ((!(((sint32) GET_P_TJALKA_RampoutPredictOn_bool()) != 0)) && (((sint32) DW_tjattg_Unit_Delay_DSTATE_fj) != 0))) {
        /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Signal Conversion1' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Constant'
                 */
        rtb_SignalConversion1 = 0U;
    } else {
        /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING'/fcg' incorporates:
                 *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING'/Functionality'
                 */
        /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
                 *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality'/Comparison'
                 */
        if ((!(((sint32)DW_tjattg_Unit_Delay1_DSTATE_p) != 0)) && (((sint32) rtb_DataTypeConversion_c5) != 0)) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Switch1' incorporates:
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Constant1'
                         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Signal Conversion1'
                         */
            rtb_SignalConversion1 = 1U;
        } else {
            /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Signal Conversion1' incorporates:
                         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl'/Unit_Delay3'
                         */
            rtb_SignalConversion1 = DW_tjattg_Unit_Delay3_DSTATE_m;
        }
        /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
        /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING'/fcg' */
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/RSFLIPFLOP/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality'/SignalConversion'
         */
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality/SignalConversion'/Signal Conversion' */
    SignalConversion = rtb_SignalConversion1;
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality'/Comparison'
         */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/AND1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/from_data_definition14'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/AND1/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality'/Logical Operator1'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality/Comparison'/Logical Operator'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EQ14/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions'/Unit_Delay5'
         */
    rtb_DataTypeConversion_o = (uint8)(((((sint32)DW_tjattg_Unit_Delay5_DSTATE_j) != 0) && (!(((sint32)rtb_SignalConversion1) != 0))) && (((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) GET_S_TJASTM_SysStateTJA_nu())));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions/EDGEFALLING2'/fcg' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/OR2/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition4'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition11'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition18'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition6'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition7'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND11/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND2/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/AND3/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/AND3/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/AND4/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ11/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ12/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ7/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ8/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ4/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/EQ6/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions'/Unit_Delay1'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay1'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay8'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay9'
         */
    rtb_DataTypeConversion_a4 = (uint8)((((((((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC))) && (((sint32) DW_tjattg_Unit_Delay1_DSTATE_f) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))) && (((sint32) rtb_Switch_jmj) != 0)) || ((((sint32)rtb_Switch_jmj) != 0) && (((((sint32) DW_tjattg_Unit_Delay1_DSTATE_j) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)))) && (((sint32) DW_tjattg_Unit_Delay_DSTATE_l) != 0)))) || ((((sint32)rtb_Switch_jmj) != 0) && (((((sint32)DW_tjattg_Unit_Delay9_DSTATE) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)))) && (((sint32) DW_tjattg_Unit_Delay8_DSTATE) != 0)))) || (((sint32)rtb_DataTypeConversion_o) != 0));
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_d = (uint8)(((((sint32)rtb_DataTypeConversion_ji) != 0) || (((sint32)rtb_DataTypeConversion_h5) != 0)) || (((sint32) rtb_DataTypeConversion_a4) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/Passive/from_data_definition13'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart/from_data_definition13'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Constant2'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/OR1/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart/AND/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart/NOT1/Functionality'/NOT'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/Passive/EQ13/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart/EQ1/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart/EQ13/Functionality'/EQ'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM'/Unit_Delay'
         */
    if (((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_az) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)))) && (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_SALC)))) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_PASSIVE)))) {
        rtb_Switch = 0.0F;
    } else {
        rtb_Switch = DW_tjattg_Unit_Delay_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/Constant2'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Constant1'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/AND/Functionality'/AND'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Logical Operator'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Relational Operator1'
         */
    rtb_DataTypeConversion_i = (uint8)(((((sint32)rtb_DataTypeConversion_d) != 0) || (rtb_Switch > 0.0F)) && (((sint32)GET_P_TJATTG_TransHandleEnable_bool()) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3/Switch1/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler1/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler2/Switch1/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_i) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3/Switch3/Functionality'/Switch' incorporates:
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3/NOT/Functionality'/NOT'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler/Switch3/Functionality'/Switch'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler1/Switch3/Functionality'/Switch'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler2/Switch3/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler1'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler2'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3'/Unit_Delay2'
                 */
        if (!(((sint32)rtb_DataTypeConversion_d) != 0)) {
            rtb_Switch_jmj = DW_tjattg_Unit_Delay2_DSTATE_a;
            rtb_Switch_kog = DW_tjattg_Unit_Delay2_DSTATE_l;
            rtb_Switch_pi = DW_tjattg_Unit_Delay2_DSTATE_f;
            rtb_Switch_hs = DW_tjattg_Unit_Delay2_DSTATE_p;
        } else {
            rtb_Switch_jmj = rtb_DataTypeConversion_o;
            rtb_Switch_kog = rtb_DataTypeConversion_h5;
            rtb_Switch_pi = rtb_DataTypeConversion_a4;
            rtb_Switch_hs = rtb_DataTypeConversion_ji;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3/Switch3/Functionality'/Switch' */
    } else {
        rtb_Switch_jmj = rtb_DataTypeConversion_o;
        rtb_Switch_kog = rtb_DataTypeConversion_h5;
        rtb_Switch_pi = rtb_DataTypeConversion_a4;
        rtb_Switch_hs = rtb_DataTypeConversion_ji;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3/Switch1/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/OR/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/OR/Functionality'/OR'
         */
    rtb_DataTypeConversion_lq = (uint8)((((((sint32)rtb_Switch_jmj) != 0) || (((sint32)rtb_Switch_kog) != 0)) || (((sint32)rtb_Switch_pi) != 0)) || (((sint32)rtb_Switch_hs) != 0));
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn13' */
    rtb_VectorConcatenate[12] = rtb_DataTypeConversion_lq;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn14' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/Constant2'/Constant'
         */
    rtb_VectorConcatenate[13] = 0U;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn15' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/Constant2'/Constant'
         */
    rtb_VectorConcatenate[14] = 0U;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn16' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/Constant2'/Constant'
         */
    rtb_VectorConcatenate[15] = 0U;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/OR1/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/from_data_definition5'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/from_data_definition6'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/from_data_definition7'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/OR1/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/OR3/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/OR4/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/Relational Operator2/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/Relational Operator3/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/Relational Operator6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckObjectUpdateConditions/Relational Operator7/Functionality'/EQ'
         */
    rtb_DataTypeConversion_ab = (uint8)(((((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB_RQ)) == ((sint32) GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32)GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_CMB)))) || ((((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF_RQ)) == ((sint32)GET_S_TJASTM_LatCtrlMode_nu())) || (((sint32) GET_S_TJASTM_LatCtrlMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)))));
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate[1] = rtb_DataTypeConversion_ab;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[2] = rtb_SignalConversion1;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn5' */
    rtb_VectorConcatenate[4] = rtb_DataTypeConversion_i;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn6' */
    rtb_VectorConcatenate[5] = rtb_Switch_hs;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn7' */
    rtb_VectorConcatenate[6] = rtb_Switch_pi;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn8' */
    rtb_VectorConcatenate[7] = rtb_Switch_kog;
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16'/ConcatBufferAtVector ConcatenateIn9' */
    rtb_VectorConcatenate[8] = rtb_Switch_jmj;
    /* S-Function (sfun_setbit): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/Debug/MappingUint16/set_bit1/Functionality'/sfun_setbit' */
    {
        /* mask selection vector from setbit block */
        uint16 temp = ((uint16)0U);
        {
            uint16 set_mask = 0;
            uint16 reset_mask = 0;
            const uint8 selection_vec[16] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U };
            {
                sint32 i1;
                const uint8 *u1 = &rtb_VectorConcatenate[0];
                for (i1=0; i1 < 16; i1++) {
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
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_crb = DW_tjattg_Unit_Delay_DSTATE_e;
    } else {
        rtb_Switch_crb = GET_S_ABPLBP_RiLnClthLength_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/Switch/Functionality'/Switch' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/P/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_VehYawRate_rps'
         */
    rtb_Mul = GET_S_LCFRCV_VehYawRate_rps() * GET_S_LCFRCV_SysCycleTimeSen_sec();
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising'/Unit_Delay'
         */
    LogicalOperator_n = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_lt) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_lt = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/EdgeRising/EDGERISING'/fcg' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE/Functionality'/Switch1' incorporates:
         *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Neg1/Functionality'/Unary Minus'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay'
         */
    if (((sint32)LogicalOperator_n) != 0) {
        rtb_Switch1 = -rtb_Mul;
    } else {
        rtb_Switch1 = DW_tjattg_Unit_Delay_DSTATE_o;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE/Functionality'/Switch1' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Prod/Functionality'/Mul' incorporates:
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  Inport: '<Root>/S_LCFRCV_VehVelX_mps'
         */
    rtb_Sum_bg = GET_S_LCFRCV_SysCycleTimeSen_sec() * GET_S_LCFRCV_VehVelX_mps();
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Product1/Functionality'/Mul' incorporates:
         *  Trigonometry: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Trigonom1/Functionality'/Trigonometric Function'
         *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Neg/Functionality'/Unary Minus'
         */
    rtb_Mul_ac = f32_cos_f32(-rtb_Switch1) * rtb_Sum_bg;
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE1/Functionality'/Switch1' incorporates:
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay1'
         */
    if (((sint32)LogicalOperator_n) != 0) {
        rtb_Switch1_g = rtb_Mul_ac;
    } else {
        rtb_Switch1_g = DW_tjattg_Unit_Delay1_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE1/Functionality'/Switch1' */
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/Sum/Functionality'/Sum' */
    rtb_Sum = rtb_Switch_crb - rtb_Switch1_g;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/Constant'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/LT/Functionality'/LT'
         */
    rtb_DataTypeConversion_k = (uint8)((rtb_Sum < GET_P_TJATTG_PredResetTrajLength_met()) && (((sint32)rtb_SignalConversion1) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthLength_met'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_mv = DW_tjattg_Unit_Delay_DSTATE_n;
    } else {
        rtb_Switch_mv = GET_S_ABPLBP_CntrLnClthLength_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/Switch/Functionality'/Switch' */
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/Sum/Functionality'/Sum' */
    rtb_Sum_mx = rtb_Switch_mv - rtb_Switch1_g;
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/AND/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/Constant'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/AND/Functionality'/AND'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/LT/Functionality'/LT'
         */
    rtb_DataTypeConversion_g = (uint8)((rtb_Sum_mx < GET_P_TJATTG_PredResetTrajLength_met()) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising'/Unit_Delay'
         */
    BI_tjattg_LogicalOperator_b = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_fi) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_fi = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/fcg' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/Max/Functionality'/Max'
         */
    rtb_Div = GET_S_LCFRCV_SysCycleTimeSen_sec() / f32_max_f32_f32 (GET_P_TJATTG_PredCrvChngPT1_sec(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze1/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrvChng_1pm2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze1'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_i = DW_tjattg_Unit_Delay_DSTATE_m;
    } else {
        rtb_Switch_i = GET_S_ABPLBP_CntrLnClthCrvChng_1pm2();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze1/Switch1/Functionality'/Switch' */
    /* UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict'/Unit_Delay' */
    rtb_Unit_Delay_j = DW_tjattg_Unit_Delay_DSTATE_d;
    /* S-Function (sfun_mmv): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_tjattg_LogicalOperator_b != 0U) {
        rtb_SFunction = rtb_Switch_i;
    } else {
        if (rtb_SignalConversion1 != 0U) {
            rtb_SFunction = f32_mmv_f32_f32_f32( rtb_Unit_Delay_j, 0.0F, rtb_Div);
        } else {
            rtb_SFunction = rtb_Unit_Delay_j;
        }
    }
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising'/Unit_Delay'
         */
    BI_tjattg_LogicalOperator_i0 = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_o0) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_o0 = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/fcg' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/Max/Functionality'/Max'
         */
    rtb_Div_o = GET_S_LCFRCV_SysCycleTimeSen_sec() / f32_max_f32_f32 (GET_P_TJATTG_PredCrvPT1_sec(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze2/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrv_1pm'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze2'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_p = DW_tjattg_Unit_Delay_DSTATE_c;
    } else {
        rtb_Switch_p = GET_S_ABPLBP_CntrLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze2/Switch/Functionality'/Switch' */
    /* UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict'/Unit_Delay' */
    rtb_Unit_Delay_g = DW_tjattg_Unit_Delay_DSTATE_a;
    /* S-Function (sfun_mmv): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_tjattg_LogicalOperator_i0 != 0U) {
        rtb_SFunction_b = rtb_Switch_p;
    } else {
        if (rtb_SignalConversion1 != 0U) {
            rtb_SFunction_b = f32_mmv_f32_f32_f32( rtb_Unit_Delay_g, 0.0F, rtb_Div_o);
        } else {
            rtb_SFunction_b = rtb_Unit_Delay_g;
        }
    }
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze3/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze4/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze3'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze4'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_dw = DW_tjattg_Unit_Delay_DSTATE_cg;
        rtb_Switch_cl = DW_tjattg_Unit_Delay_DSTATE_i;
    } else {
        rtb_Switch_dw = GET_S_ABPLBP_CntrLnClthHeading_rad();
        rtb_Switch_cl = GET_S_ABPLBP_CntrLnClthPosY0_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze3/Switch/Functionality'/Switch' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Product2/Functionality'/Mul' incorporates:
         *  Trigonometry: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Trigonom/Functionality'/Trigonometric Function'
         *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Neg/Functionality'/Unary Minus'
         */
    rtb_Mul_nl = rtb_Sum_bg * f32_sin_f32(-rtb_Switch1);
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE2/Functionality'/Switch1' incorporates:
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay2'
         */
    if (((sint32)LogicalOperator_n) != 0) {
        rtb_Switch1_h = rtb_Mul_nl;
    } else {
        rtb_Switch1_h = DW_tjattg_Unit_Delay2_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE2/Functionality'/Switch1' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Mul7/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/X_Yaw/Sum3/Functionality'/Sum'
         */
    rtb_Mul_oo = ((((rtb_Switch1_g * rtb_Switch1_g) * 0.5F) * rtb_Switch_p) + ((rtb_Switch1_g * rtb_Switch_dw) + (rtb_Switch_cl - rtb_Switch1_h))) * rtb_Switch1;
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Sum5/Functionality'/Sum' */
    rtb_Sum_bg = rtb_Switch1_g - rtb_Mul_oo;
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Y_Yaw/Sum3/Functionality'/Sum'
         */
    rtb_Sum_bg = (((rtb_Sum_bg * rtb_Sum_bg) * 0.5F) * rtb_Switch_p) + ((rtb_Sum_bg * rtb_Switch_dw) + (rtb_Switch_cl - rtb_Switch1_h));
    /* Sqrt: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/MathFunction/Functionality'/MathFunction' incorporates:
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Sum/Functionality'/Sum'
         */
    rtb_MathFunction = f32_sqrt_f32((rtb_Mul_oo * rtb_Mul_oo) + (rtb_Sum_bg * rtb_Sum_bg));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrvChng_1pm2'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthLength_met'
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosY0_met'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Max/Functionality'/Max'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Sum5/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Sum6/Functionality'/Sum'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Mul3/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Mul4/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Mul5/Functionality'/Mul'
                 *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/GT/Functionality'/GT'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Sum3/Functionality'/Sum'
                 *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Neg/Functionality'/Unary Minus'
                 */
        if (rtb_Switch1_h > ((((rtb_Switch1_g * rtb_Switch1_g) * 0.5F) * rtb_Switch_p) + ((rtb_Switch1_g * rtb_Switch_dw) + rtb_Switch_cl))) {
            rtb_MathFunction = -rtb_MathFunction;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/PosY0/Switch/Functionality'/Switch' */
        rtb_Mul_oo = (((rtb_Switch1_g - rtb_Mul_oo) * rtb_Switch_p) + rtb_Switch_dw) + rtb_Switch1;
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/Constant2'/Constant'
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/NOT/Functionality'/NOT'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Sum5/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Heading/Sum6/Functionality'/Sum'
                 */
        if (!(((sint32)GET_P_TJATTG_PredFreezeCrv_bool()) != 0)) {
            rtb__Crv_1pm = rtb_SFunction_b;
        } else {
            rtb__Crv_1pm = rtb_Switch_p;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/Constant2'/Constant'
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/NOT/Functionality'/NOT'
                 */
        if (!(((sint32)GET_P_TJATTG_PredFreezeCrvChng_bool()) != 0)) {
            rtb__ChngOfCrv_1pm2 = rtb_SFunction;
        } else {
            rtb__ChngOfCrv_1pm2 = rtb_Switch_i;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict/Switch/Functionality'/Switch' */
        rtb_Sum_mx = f32_max_f32_f32(GET_P_TJATTG_LnPredMinTrajLength_met(), rtb_Sum_mx);
    } else {
        rtb_MathFunction = GET_S_ABPLBP_CntrLnClthPosY0_met();
        rtb_Mul_oo = GET_S_ABPLBP_CntrLnClthHeading_rad();
        rtb__Crv_1pm = GET_S_ABPLBP_CntrLnClthCrv_1pm();
        rtb__ChngOfCrv_1pm2 = GET_S_ABPLBP_CntrLnClthCrvChng_1pm2();
        rtb_Sum_mx = GET_S_ABPLBP_CntrLnClthLength_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising'/Unit_Delay'
         */
    BI_tjattg_LogicalOperator_i = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_kt) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_kt = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/fcg' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/Max/Functionality'/Max'
         */
    rtb_Div_g = GET_S_LCFRCV_SysCycleTimeSen_sec() / f32_max_f32_f32 (GET_P_TJATTG_PredCrvChngPT1_sec(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze1/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze1'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_o = DW_tjattg_Unit_Delay_DSTATE_b;
    } else {
        rtb_Switch_o = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze1/Switch1/Functionality'/Switch' */
    /* UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict'/Unit_Delay' */
    rtb_Unit_Delay_gs = DW_tjattg_Unit_Delay_DSTATE_n5;
    /* S-Function (sfun_mmv): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_tjattg_LogicalOperator_i != 0U) {
        rtb_SFunction_d = rtb_Switch_o;
    } else {
        if (rtb_SignalConversion1 != 0U) {
            rtb_SFunction_d = f32_mmv_f32_f32_f32( rtb_Unit_Delay_gs, 0.0F, rtb_Div_g);
        } else {
            rtb_SFunction_d = rtb_Unit_Delay_gs;
        }
    }
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising'/Unit_Delay'
         */
    BI_tjattg_LogicalOperator_e0 = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_g) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_g = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/fcg' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/Max/Functionality'/Max'
         */
    rtb_Div_oe = GET_S_LCFRCV_SysCycleTimeSen_sec() / f32_max_f32_f32 (GET_P_TJATTG_PredCrvPT1_sec(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze2/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze2'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_ov = DW_tjattg_Unit_Delay_DSTATE_oj;
    } else {
        rtb_Switch_ov = GET_S_ABPLBP_LeLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze2/Switch/Functionality'/Switch' */
    /* UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict'/Unit_Delay' */
    rtb_Unit_Delay_m = DW_tjattg_Unit_Delay_DSTATE_f;
    /* S-Function (sfun_mmv): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_tjattg_LogicalOperator_e0 != 0U) {
        rtb_SFunction_l = rtb_Switch_ov;
    } else {
        if (rtb_SignalConversion1 != 0U) {
            rtb_SFunction_l = f32_mmv_f32_f32_f32( rtb_Unit_Delay_m, 0.0F, rtb_Div_oe);
        } else {
            rtb_SFunction_l = rtb_Unit_Delay_m;
        }
    }
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze3/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze4/Switch/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/LengthPredict/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze3'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze4'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/LengthPredict'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_l4 = DW_tjattg_Unit_Delay_DSTATE_h;
        rtb_Switch_lqw = DW_tjattg_Unit_Delay_DSTATE_p;
        rtb_Switch_l = DW_tjattg_Unit_Delay_DSTATE_hs;
    } else {
        rtb_Switch_l4 = GET_S_ABPLBP_LeLnClthHeading_rad();
        rtb_Switch_lqw = GET_S_ABPLBP_LeLnClthPosY0_met();
        rtb_Switch_l = GET_S_ABPLBP_LeLnClthLength_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze3/Switch/Functionality'/Switch' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Mul7/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/X_Yaw/Sum3/Functionality'/Sum'
         */
    rtb_Mul_k5 = ((((rtb_Switch1_g * rtb_Switch1_g) * 0.5F) * rtb_Switch_ov) + ((rtb_Switch1_g * rtb_Switch_l4) + (rtb_Switch_lqw - rtb_Switch1_h))) * rtb_Switch1;
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Sum5/Functionality'/Sum' */
    rtb_Sum_bg = rtb_Switch1_g - rtb_Mul_k5;
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Y_Yaw/Sum3/Functionality'/Sum'
         */
    rtb_Sum_bg = (((rtb_Sum_bg * rtb_Sum_bg) * 0.5F) * rtb_Switch_ov) + ((rtb_Sum_bg * rtb_Switch_l4) + (rtb_Switch_lqw - rtb_Switch1_h));
    /* Sqrt: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/MathFunction/Functionality'/MathFunction' incorporates:
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Sum/Functionality'/Sum'
         */
    rtb_MathFunction_k = f32_sqrt_f32((rtb_Mul_k5 * rtb_Mul_k5) + (rtb_Sum_bg * rtb_Sum_bg));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrvChng_1pm2'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthLength_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosY0_met'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Max/Functionality'/Max'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Sum5/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Sum6/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/LengthPredict/Sum/Functionality'/Sum'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Mul3/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Mul4/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Mul5/Functionality'/Mul'
                 *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/GT/Functionality'/GT'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Sum3/Functionality'/Sum'
                 *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Neg/Functionality'/Unary Minus'
                 */
        if (rtb_Switch1_h > ((((rtb_Switch1_g * rtb_Switch1_g) * 0.5F) * rtb_Switch_ov) + ((rtb_Switch1_g * rtb_Switch_l4) + rtb_Switch_lqw))) {
            rtb_MathFunction_k = -rtb_MathFunction_k;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/PosY0/Switch/Functionality'/Switch' */
        rtb__Heading_rad_d = (((rtb_Switch1_g - rtb_Mul_k5) * rtb_Switch_ov) + rtb_Switch_l4) + rtb_Switch1;
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/Constant2'/Constant'
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/NOT/Functionality'/NOT'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Sum5/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Heading/Sum6/Functionality'/Sum'
                 */
        if (!(((sint32)GET_P_TJATTG_PredFreezeCrv_bool()) != 0)) {
            rtb__Crv_1pm_l1 = rtb_SFunction_l;
        } else {
            rtb__Crv_1pm_l1 = rtb_Switch_ov;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/Constant2'/Constant'
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/NOT/Functionality'/NOT'
                 */
        if (!(((sint32)GET_P_TJATTG_PredFreezeCrvChng_bool()) != 0)) {
            rtb__ChngOfCrv_1pm2_ji = rtb_SFunction_d;
        } else {
            rtb__ChngOfCrv_1pm2_ji = rtb_Switch_o;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict/Switch/Functionality'/Switch' */
        rtb__TrajLength_met_hg = f32_max_f32_f32 (GET_P_TJATTG_LnPredMinTrajLength_met(), rtb_Switch_l - rtb_Switch1_g);
    } else {
        rtb_MathFunction_k = GET_S_ABPLBP_LeLnClthPosY0_met();
        rtb__Heading_rad_d = GET_S_ABPLBP_LeLnClthHeading_rad();
        rtb__Crv_1pm_l1 = GET_S_ABPLBP_LeLnClthCrv_1pm();
        rtb__ChngOfCrv_1pm2_ji = GET_S_ABPLBP_LeLnClthCrvChng_1pm2();
        rtb__TrajLength_met_hg = GET_S_ABPLBP_LeLnClthLength_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Switch/Functionality'/Switch' */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising'/Unit_Delay'
         */
    BI_tjattg_LogicalOperator_e = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_na) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_na = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/EdgeRising/EDGERISING'/fcg' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/Max/Functionality'/Max'
         */
    rtb_Div_b = GET_S_LCFRCV_SysCycleTimeSen_sec() / f32_max_f32_f32 (GET_P_TJATTG_PredCrvChngPT1_sec(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze1/Switch1/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze1'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_pp = DW_tjattg_Unit_Delay_DSTATE_ie;
    } else {
        rtb_Switch_pp = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze1/Switch1/Functionality'/Switch' */
    /* UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict'/Unit_Delay' */
    rtb_Unit_Delay_hj = DW_tjattg_Unit_Delay_DSTATE_eg;
    /* S-Function (sfun_mmv): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_tjattg_LogicalOperator_e != 0U) {
        rtb_SFunction_m = rtb_Switch_pp;
    } else {
        if (rtb_SignalConversion1 != 0U) {
            rtb_SFunction_m = f32_mmv_f32_f32_f32( rtb_Unit_Delay_hj, 0.0F, rtb_Div_b);
        } else {
            rtb_SFunction_m = rtb_Unit_Delay_hj;
        }
    }
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/Comparison'
         */
    /* Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/Comparison'/Logical Operator' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/Logical Operator2'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising'/Unit_Delay'
         */
    BI_tjattg_LogicalOperator_p = (uint8)((!(((sint32)DW_tjattg_Unit_Delay_DSTATE_nk) != 0)) && (((sint32)rtb_SignalConversion1) != 0));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising'/Unit_Delay' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay_DSTATE_nk = rtb_SignalConversion1;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/EdgeRising/EDGERISING'/fcg' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/LOWPASST_RE/m_calc/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/Constant3'/Constant'
         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/Max/Functionality'/Max'
         */
    rtb_Div_ou = GET_S_LCFRCV_SysCycleTimeSen_sec() / f32_max_f32_f32 (GET_P_TJATTG_PredCrvPT1_sec(), GET_S_LCFRCV_SysCycleTimeSen_sec());
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze2/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze2'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Switch_na = DW_tjattg_Unit_Delay_DSTATE_ij;
    } else {
        rtb_Switch_na = GET_S_ABPLBP_RiLnClthCrv_1pm();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze2/Switch/Functionality'/Switch' */
    /* UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict'/Unit_Delay' */
    rtb_Unit_Delay_oa = DW_tjattg_Unit_Delay_DSTATE_k;
    /* S-Function (sfun_mmv): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/LOWPASST_RE/Functionality'/S-Function' */
    if (BI_tjattg_LogicalOperator_p != 0U) {
        rtb_SFunction_j = rtb_Switch_na;
    } else {
        if (rtb_SignalConversion1 != 0U) {
            rtb_SFunction_j = f32_mmv_f32_f32_f32( rtb_Unit_Delay_oa, 0.0F, rtb_Div_ou);
        } else {
            rtb_SFunction_j = rtb_Unit_Delay_oa;
        }
    }
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze3/Switch/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze4/Switch/Functionality'/Switch'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze3'/Unit_Delay'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze4'/Unit_Delay'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        rtb_Mul_k5 = DW_tjattg_Unit_Delay_DSTATE_h4;
        rtb_Switch_n = DW_tjattg_Unit_Delay_DSTATE_ba;
    } else {
        rtb_Mul_k5 = GET_S_ABPLBP_RiLnClthHeading_rad();
        rtb_Switch_n = GET_S_ABPLBP_RiLnClthPosY0_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze3/Switch/Functionality'/Switch' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Mul7/Functionality'/Mul' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/X_Yaw/Sum3/Functionality'/Sum'
         */
    rtb_Mul_cy = ((((rtb_Switch1_g * rtb_Switch1_g) * 0.5F) * rtb_Switch_na) + ((rtb_Switch1_g * rtb_Mul_k5) + (rtb_Switch_n - rtb_Switch1_h))) * rtb_Switch1;
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Sum5/Functionality'/Sum' */
    rtb_Sum_bg = rtb_Switch1_g - rtb_Mul_cy;
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Sum2/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Mul2/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Y_Yaw/Sum3/Functionality'/Sum'
         */
    rtb_Sum_bg = (((rtb_Sum_bg * rtb_Sum_bg) * 0.5F) * rtb_Switch_na) + ((rtb_Sum_bg * rtb_Mul_k5) + (rtb_Switch_n - rtb_Switch1_h));
    /* Sqrt: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/MathFunction/Functionality'/MathFunction' incorporates:
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Sum/Functionality'/Sum'
         */
    rtb_Sum_bg = f32_sqrt_f32((rtb_Mul_cy * rtb_Mul_cy) + (rtb_Sum_bg * rtb_Sum_bg));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Constant'/Constant'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrvChng_1pm2'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthCrv_1pm'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthHeading_rad'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthLength_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosY0_met'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Max/Functionality'/Max'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Mul3/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Sum2/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Sum5/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Sum6/Functionality'/Sum'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Switch/Functionality'/Switch'
         */
    if (((sint32)rtb_SignalConversion1) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Mul2/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Mul3/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Mul4/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Mul5/Functionality'/Mul'
                 *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/GT/Functionality'/GT'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Sum3/Functionality'/Sum'
                 *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Neg/Functionality'/Unary Minus'
                 */
        if (rtb_Switch1_h > ((((rtb_Switch1_g * rtb_Switch1_g) * 0.5F) * rtb_Switch_na) + ((rtb_Switch1_g * rtb_Mul_k5) + rtb_Switch_n))) {
            rtb_Sum_bg = -rtb_Sum_bg;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/PosY0/Switch/Functionality'/Switch' */
        rtb_Mul_cy = (((rtb_Switch1_g - rtb_Mul_cy) * rtb_Switch_na) + rtb_Mul_k5) + rtb_Switch1;
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/Constant2'/Constant'
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/NOT/Functionality'/NOT'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Mul3/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Sum2/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Sum5/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Heading/Sum6/Functionality'/Sum'
                 */
        if (!(((sint32)GET_P_TJATTG_PredFreezeCrv_bool()) != 0)) {
            rtb__Crv_1pm_go = rtb_SFunction_j;
        } else {
            rtb__Crv_1pm_go = rtb_Switch_na;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict/Switch/Functionality'/Switch' */
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/Constant2'/Constant'
                 *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/NOT/Functionality'/NOT'
                 */
        if (!(((sint32)GET_P_TJATTG_PredFreezeCrvChng_bool()) != 0)) {
            rtb__ChngOfCrv_1pm2_ai = rtb_SFunction_m;
        } else {
            rtb__ChngOfCrv_1pm2_ai = rtb_Switch_pp;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict/Switch/Functionality'/Switch' */
        rtb__TrajLength_met_p = f32_max_f32_f32(GET_P_TJATTG_LnPredMinTrajLength_met (), rtb_Sum);
    } else {
        rtb_Sum_bg = GET_S_ABPLBP_RiLnClthPosY0_met();
        rtb_Mul_cy = GET_S_ABPLBP_RiLnClthHeading_rad();
        rtb__Crv_1pm_go = GET_S_ABPLBP_RiLnClthCrv_1pm();
        rtb__ChngOfCrv_1pm2_ai = GET_S_ABPLBP_RiLnClthCrvChng_1pm2();
        rtb__TrajLength_met_p = GET_S_ABPLBP_RiLnClthLength_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE/Functionality'/Switch4' incorporates:
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE/Functionality'/Switch3'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE1/Functionality'/Switch3'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE1/Functionality'/Switch4'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE2/Functionality'/Switch3'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE2/Functionality'/Switch4'
         */
    if (((sint32)LogicalOperator_n) != 0) {
        /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay' incorporates:
                 *  UnaryMinus: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/Neg1/Functionality'/Unary Minus'
                 */
        DW_tjattg_Unit_Delay_DSTATE_o = -rtb_Mul;
    } else if (((sint32)rtb_SignalConversion1) != 0) {
        /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay' incorporates:
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/A/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE/Functionality'/Switch3'
                 */
        DW_tjattg_Unit_Delay_DSTATE_o = rtb_Switch1 - rtb_Mul;
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE1/Functionality'/Switch3' incorporates:
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/A1/Functionality'/Sum'
                 */
        rtb_Mul_ac += rtb_Switch1_g;
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE2/Functionality'/Switch3' incorporates:
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/A2/Functionality'/Sum'
                 */
        rtb_Mul_nl += rtb_Switch1_h;
    } else {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE1/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay1'
                 */
        rtb_Mul_ac = DW_tjattg_Unit_Delay1_DSTATE;
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE2/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay2'
                 */
        rtb_Mul_nl = DW_tjattg_Unit_Delay2_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie/DELAY_RE/Functionality'/Switch4' */
    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
         *
         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
         *  X.2.1.1.6
         */
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectLeftClothoid/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectLeftClothoid/Application Parameter2'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectLeftClothoid/Gain_const'/Constant'
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosY0_met'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectLeftClothoid/Gain/Functionality'/Mul'
         */
    rtb_Switch1 = (GET_P_TJATTG_ObjFolVirtLnWdth_met() * 0.5F) + GET_S_ODPFOH_TgtObjPosY0_met();
    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Constant'/Constant'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch'
         */
    if (((sint32)rtb_DataTypeConversion_f) != 0) {
        rtb_DataTypeConversion_f = 0U;
    } else if (((sint32)rtb_DataTypeConversion_ir) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Constant1'/Constant'
                 */
        rtb_DataTypeConversion_f = 1U;
    } else if (((sint32)rtb_DataTypeConversion_b4) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Constant2'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_f = 2U;
    } else {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Constant3'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_f = 3U;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Constant1'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ir = (uint8)(!(((sint32) GET_P_TJATTG_EnableVirtAdjLane_bool()) != 0));
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
         */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb_Switch1_g = GET_S_ABPLBP_LeLnClthPosX0_met();
        break;
    case 1:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch1/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_LeAdjLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Switch1_g = GET_S_ABPALP_LeAdjLnClthPosX0_met();
        } else {
            rtb_Switch1_g = GET_S_ABPLBP_LeLnClthPosX0_met();
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch1/Functionality'/Switch' */
        break;
    case 2:
        rtb_Switch1_g = GET_S_ABPLBP_RiLnClthPosX0_met();
        break;
    default:
        rtb_Switch1_g = GET_S_ABPLBP_LeLnClthPosX0_met();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/AND/Functionality'/AND'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch'
         */
    if ((((sint32)rtb_DataTypeConversion) != 0) && (((sint32) rtb_DataTypeConversion_ab) != 0)) {
        rtb_DataTypeConversion_b4 = 0U;
    } else if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant1'/Constant'
                 */
        rtb_DataTypeConversion_b4 = 1U;
    } else if (((sint32)rtb_DataTypeConversion_ab) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant2'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b4 = 2U;
    } else {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant3'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_b4 = 3U;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                 *  X.2.1.1.6
                 */
        rtb_Switch1_g = GET_S_ODPFOH_TgtObjPosX0_met();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb_Switch1_g = GET_S_TJACMB_CombinedPosX0_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
                                 *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                                 */
                switch (rtb_DataTypeConversion_b4) {
                case 0:
                    rtb_Switch1_g = GET_S_TJACMB_CombinedPosX0_met();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                                         *  X.2.1.1.6
                                         */
                    rtb_Switch1_g = GET_S_ODPFOH_TgtObjPosX0_met();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
                    break;
                default:
                    rtb_Switch1_g = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch2/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPALP_LeAdjLnClthPosY0_met'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ir) != 0) {
        rtb_Mul = GET_S_ABPALP_LeAdjLnClthPosY0_met();
    } else {
        rtb_Mul = GET_P_TJATTG_VirtAdjLaneWidth_met() + rtb_MathFunction_k;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb_Switch1_h = rtb_MathFunction_k;
        break;
    case 1:
        rtb_Switch1_h = rtb_Mul;
        break;
    case 2:
        rtb_Switch1_h = rtb_Sum_bg;
        break;
    default:
        rtb_Switch1_h = rtb_MathFunction_k;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        rtb_Switch1_h = rtb_Switch1;
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedLePosY0_met'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb_Switch1_h = GET_S_TJACMB_CombinedLePosY0_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant1'/Constant'
                                 *  Inport: '<Root>/S_TJACMB_CombinedLePosY0_met'
                                 */
                switch (rtb_DataTypeConversion_b4) {
                case 0:
                    rtb_Switch1_h = GET_S_TJACMB_CombinedLePosY0_met();
                    break;
                case 1:
                    break;
                case 2:
                    rtb_Switch1_h = rtb_Switch1;
                    break;
                default:
                    rtb_Switch1_h = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb_Switch1 = rtb__Heading_rad_d;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
        rtb_Sum = rtb__Crv_1pm_l1;
        break;
    case 1:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch3/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_LeAdjLnClthHeading_rad'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Switch1 = GET_S_ABPALP_LeAdjLnClthHeading_rad();
        } else {
            rtb_Switch1 = rtb__Heading_rad_d;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch3/Functionality'/Switch' */
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch4/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_LeAdjLnClthCrv_1pm'
                 *  MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Sum = GET_S_ABPALP_LeAdjLnClthCrv_1pm();
        } else {
            rtb_Sum = rtb__Crv_1pm_l1;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch4/Functionality'/Switch' */
        break;
    case 2:
        rtb_Switch1 = rtb_Mul_cy;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
        rtb_Sum = rtb__Crv_1pm_go;
        break;
    default:
        rtb_Switch1 = rtb__Heading_rad_d;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
        rtb_Sum = rtb__Crv_1pm_l1;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                 *  X.2.1.1.6
                 */
        rtb_Switch1 = GET_S_ODPFOH_TgtObjHeadAng_rad();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedHeading_rad'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb_Switch1 = GET_S_TJACMB_CombinedHeading_rad();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant2'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
                                 *  Inport: '<Root>/S_TJACMB_CombinedHeading_rad'
                                 */
                switch (rtb_DataTypeConversion_b4) {
                case 0:
                    rtb_Switch1 = GET_S_TJACMB_CombinedHeading_rad();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                                         *  X.2.1.1.6
                                         */
                    rtb_Switch1 = GET_S_ODPFOH_TgtObjHeadAng_rad();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
                    break;
                default:
                    rtb_Switch1 = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__ChngOfCrv_1pm2_k = rtb__ChngOfCrv_1pm2_ji;
        break;
    case 1:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch5/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_LeAdjLnClthCrvChng_1pm2'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb__ChngOfCrv_1pm2_k = GET_S_ABPALP_LeAdjLnClthCrvChng_1pm2();
        } else {
            rtb__ChngOfCrv_1pm2_k = rtb__ChngOfCrv_1pm2_ji;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch5/Functionality'/Switch' */
        break;
    case 2:
        rtb__ChngOfCrv_1pm2_k = rtb__ChngOfCrv_1pm2_ai;
        break;
    default:
        rtb__ChngOfCrv_1pm2_k = rtb__ChngOfCrv_1pm2_ji;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                 *  X.2.1.1.6
                 */
        rtb_Sum = GET_S_ODPFOH_TgtObjCrv_1pm();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedCrv_1pm'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb_Sum = GET_S_TJACMB_CombinedCrv_1pm();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant3'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
                                 *  Inport: '<Root>/S_TJACMB_CombinedCrv_1pm'
                                 */
                switch (rtb_DataTypeConversion_b4) {
                case 0:
                    rtb_Sum = GET_S_TJACMB_CombinedCrv_1pm();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                                         *  X.2.1.1.6
                                         */
                    rtb_Sum = GET_S_ODPFOH_TgtObjCrv_1pm();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
                    break;
                default:
                    rtb_Sum = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__TrajLength_met_i = rtb__TrajLength_met_hg;
        break;
    case 1:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch6/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_LeAdjLnClthLength_met'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb__TrajLength_met_i = GET_S_ABPALP_LeAdjLnClthLength_met();
        } else {
            rtb__TrajLength_met_i = rtb__TrajLength_met_hg;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Switch6/Functionality'/Switch' */
        break;
    case 2:
        rtb__TrajLength_met_i = rtb__TrajLength_met_p;
        break;
    default:
        rtb__TrajLength_met_i = rtb__TrajLength_met_hg;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrvChng_1pm2'
         *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                 *  X.2.1.1.6
                 */
        rtb__ChngOfCrv_1pm2_k = GET_S_ODPFOH_TgtObjCrvChng_1pm2();
        rtb__TrajLength_met_i = GET_S_ODPFOH_TgtObjLength_met();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedCrvChng_1pm2'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__ChngOfCrv_1pm2_k = GET_S_TJACMB_CombinedCrvChng_1pm2();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant4'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjCrvChng_1pm2'
                                 *  Inport: '<Root>/S_TJACMB_CombinedCrvChng_1pm2'
                                 */
                switch (rtb_DataTypeConversion_b4) {
                case 0:
                    rtb__ChngOfCrv_1pm2_k = GET_S_TJACMB_CombinedCrvChng_1pm2();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                                         *  X.2.1.1.6
                                         */
                    rtb__ChngOfCrv_1pm2_k = GET_S_ODPFOH_TgtObjCrvChng_1pm2();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
                    break;
                default:
                    rtb__ChngOfCrv_1pm2_k = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch' */
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedLength_met'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__TrajLength_met_i = GET_S_TJACMB_CombinedLength_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant5'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
                                 *  Inport: '<Root>/S_TJACMB_CombinedLength_met'
                                 */
                switch (rtb_DataTypeConversion_b4) {
                case 0:
                    rtb__TrajLength_met_i = GET_S_TJACMB_CombinedLength_met();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid':
                                         *  X.2.1.1.6
                                         */
                    rtb__TrajLength_met_i = GET_S_ODPFOH_TgtObjLength_met();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectLeftClothoid' */
                    break;
                default:
                    rtb__TrajLength_met_i = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ir = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch1/Functionality'/Switch' incorporates:
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_i) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch6/Functionality'/Switch' incorporates:
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Switch_iz = DW_tjattg_Unit_Delay2_DSTATE_n;
        } else {
            rtb_Switch_iz = DW_tjattg_Unit_Delay_2_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch6/Functionality'/Switch' */
    } else {
        rtb_Switch_iz = DW_tjattg_Unit_Delay_2_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Constant6'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3'
         */
    if (((sint32)rtb_DataTypeConversion_d) != 0) {
        rtb_Switch3 = 0.0F;
    } else if (((sint32)rtb_DataTypeConversion_i) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Switch3 = DW_tjattg_Unit_Delay1_DSTATE_n + GET_S_LCFRCV_SysCycleTimeSen_sec();
    } else {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch3' incorporates:
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA'/Unit_Delay1'
                 */
        rtb_Switch3 = DW_tjattg_Unit_Delay1_DSTATE_n;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/STOPWATCH_RE/Functionality'/Switch2' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch6/Functionality'/Switch' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/OR/Functionality'/OR'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime'/Unit_Delay5'
         */
    if ((((((sint32)rtb_DataTypeConversion_o) != 0) || (((sint32) rtb_DataTypeConversion_a4) != 0)) || (((sint32) rtb_DataTypeConversion_ji) != 0)) || (((sint32) rtb_DataTypeConversion_h5) != 0)) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Constant8'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch1/Functionality'/Switch'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch2/Functionality'/Switch'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch3/Functionality'/Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_o) != 0) {
            rtb_Switch_kv = GET_P_TJATTG_TransDurationPredct_sec();
        } else if (((sint32)rtb_DataTypeConversion_a4) != 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch1/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Constant5'/Constant'
                         */
            rtb_Switch_kv = GET_P_TJATTG_TransDurationLD_sec();
        } else if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Constant6'/Constant'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch1/Functionality'/Switch'
                         */
            rtb_Switch_kv = GET_P_TJATTG_TransDurationOD_sec();
        } else if (((sint32)rtb_DataTypeConversion_h5) != 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch3/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Constant7'/Constant'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch2/Functionality'/Switch'
                         */
            rtb_Switch_kv = GET_P_TJATTG_TransDurationCMB_sec();
        } else {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Constant2'/Constant'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch1/Functionality'/Switch'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch3/Functionality'/Switch'
                         */
            rtb_Switch_kv = 1.0F;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch/Functionality'/Switch' */
    } else {
        rtb_Switch_kv = DW_tjattg_Unit_Delay5_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime/Switch6/Functionality'/Switch' */
    /* Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Normalize/Div1/Functionality/Div'/Div' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Constant1'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Constant3'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Normalize/Constant1'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Normalize/Constant4'/Constant'
         *  MinMax: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Max/Functionality'/Max'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Div/Functionality/Div'/Div'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Mul/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Normalize/Sum/Functionality'/Sum'
         *  Trigonometry: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA/Trigonom/Functionality'/Trigonometric Function'
         */
    rtb_Div_j = (f32_cos_f32((rtb_Switch3 / f32_max_f32_f32(rtb_Switch_kv, GET_P_LCF_AlmostZero_nu())) * 3.14159274F) + 1.0F) / 2.0F;
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch11/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch3/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch4/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch5/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/Switch1/Functionality'/Switch'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_i) != 0) {
        rtb_Switch1_h = ((1.0F - rtb_Div_j) * rtb_Switch1_h) + (rtb_Switch_iz * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch7/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch8/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay1'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay3'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Switch_aec = DW_tjattg_Unit_Delay1_DSTATE_k;
            rtb_Switch_bxu = DW_tjattg_Unit_Delay3_DSTATE;
        } else {
            rtb_Switch_aec = DW_tjattg_Unit_Delay_3_DSTATE;
            rtb_Switch_bxu = DW_tjattg_Unit_Delay_4_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch7/Functionality'/Switch' */
        rtb_Switch1 = ((1.0F - rtb_Div_j) * rtb_Switch1) + (rtb_Switch_aec * rtb_Div_j);
        rtb_Sum = ((1.0F - rtb_Div_j) * rtb_Sum) + (rtb_Switch_bxu * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch9/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Constant'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch10/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay4'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay5'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Switch_g = DW_tjattg_Unit_Delay4_DSTATE;
            rtb_Switch_cv = DW_tjattg_Unit_Delay5_DSTATE_g;
        } else {
            rtb_Switch_g = DW_tjattg_Unit_Delay_5_DSTATE;
            rtb_Switch_cv = DW_tjattg_Unit_Delay_6_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch9/Functionality'/Switch' */
        rtb__ChngOfCrv_1pm2_k = ((1.0F - rtb_Div_j) * rtb__ChngOfCrv_1pm2_k) + (rtb_Switch_g * rtb_Div_j);
        rtb__TrajLength_met_i = ((1.0F - rtb_Div_j) * rtb__TrajLength_met_i) + (rtb_Switch_cv * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch12/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Constant'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum1/Functionality'/Sum'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay6'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ir) != 0) {
            rtb_Switch_ey = DW_tjattg_Unit_Delay6_DSTATE;
        } else {
            rtb_Switch_ey = DW_tjattg_Unit_Delay_1_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch12/Functionality'/Switch' */
        rtb_Switch1_g = ((1.0F - rtb_Div_j) * rtb_Switch1_g) + (rtb_Switch_ey * rtb_Div_j);
    } else {
        rtb_Switch_aec = DW_tjattg_Unit_Delay_3_DSTATE;
        rtb_Switch_bxu = DW_tjattg_Unit_Delay_4_DSTATE;
        rtb_Switch_g = DW_tjattg_Unit_Delay_5_DSTATE;
        rtb_Switch_cv = DW_tjattg_Unit_Delay_6_DSTATE;
        rtb_Switch_ey = DW_tjattg_Unit_Delay_1_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Switch1' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Constant'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Relational Operator'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Switch2'
         */
    if (((sint32)rtb_DataTypeConversion_d) != 0) {
        rtb_Switch = rtb_Switch_kv;
    } else {
        if (rtb_Switch > 0.0F) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Switch2' incorporates:
                         *  Inport: '<Root>/S_LCFRCV_SysCycleTimeSen_sec'
                         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality/Add/Functionality'/Sum'
                         */
            rtb_Switch -= GET_S_LCFRCV_SysCycleTimeSen_sec();
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM/TURNOFFDELAYTIME/Functionality'/Switch1' */
    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
         *
         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
         *  X.2.1.1.13
         */
    /* Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectRightClothoid/Sum/Functionality'/Sum' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectRightClothoid/Application Parameter2'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectRightClothoid/Gain_const'/Constant'
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosY0_met'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ObjectRightClothoid/Gain/Functionality'/Mul'
         */
    rtb_Sum_hf = GET_S_ODPFOH_TgtObjPosY0_met() - (GET_P_TJATTG_ObjFolVirtLnWdth_met() * 0.5F);
    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Constant1'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ji = (uint8)(!(((sint32) GET_P_TJATTG_EnableVirtAdjLane_bool()) != 0));
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
         */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__PosX0_met_mb = GET_S_ABPLBP_RiLnClthPosX0_met();
        break;
    case 1:
        rtb__PosX0_met_mb = GET_S_ABPLBP_LeLnClthPosX0_met();
        break;
    case 2:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_RiAdjLnClthPosX0_met'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb__PosX0_met_mb = GET_S_ABPALP_RiAdjLnClthPosX0_met();
        } else {
            rtb__PosX0_met_mb = GET_S_ABPLBP_RiLnClthPosX0_met();
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch/Functionality'/Switch' */
        break;
    default:
        rtb__PosX0_met_mb = GET_S_ABPLBP_RiLnClthPosX0_met();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/AND/Functionality'/AND'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch'
         */
    if ((((sint32)rtb_DataTypeConversion) != 0) && (((sint32) rtb_DataTypeConversion_ab) != 0)) {
        rtb_DataTypeConversion_h5 = 0U;
    } else if (((sint32)rtb_DataTypeConversion) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant1'/Constant'
                 */
        rtb_DataTypeConversion_h5 = 1U;
    } else if (((sint32)rtb_DataTypeConversion_ab) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant2'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_h5 = 2U;
    } else {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Constant3'/Constant'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch'
                 */
        rtb_DataTypeConversion_h5 = 3U;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                 *  X.2.1.1.13
                 */
        rtb__PosX0_met_mb = GET_S_ODPFOH_TgtObjPosX0_met();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__PosX0_met_mb = GET_S_TJACMB_CombinedPosX0_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
                                 *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                                 */
                switch (rtb_DataTypeConversion_h5) {
                case 0:
                    rtb__PosX0_met_mb = GET_S_TJACMB_CombinedPosX0_met();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                                         *  X.2.1.1.13
                                         */
                    rtb__PosX0_met_mb = GET_S_ODPFOH_TgtObjPosX0_met();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
                    break;
                default:
                    rtb__PosX0_met_mb = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Constant2'/Constant'
         *  Inport: '<Root>/S_ABPALP_RiAdjLnClthPosY0_met'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Sum1/Functionality'/Sum'
         */
    if (((sint32)rtb_DataTypeConversion_ji) != 0) {
        rtb_Switch_hw = GET_S_ABPALP_RiAdjLnClthPosY0_met();
    } else {
        rtb_Switch_hw = rtb_Sum_bg - GET_P_TJATTG_VirtAdjLaneWidth_met();
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__PosY0_met_le = rtb_Sum_bg;
        break;
    case 1:
        rtb__PosY0_met_le = rtb_MathFunction_k;
        break;
    case 2:
        rtb__PosY0_met_le = rtb_Switch_hw;
        break;
    default:
        rtb__PosY0_met_le = rtb_Sum_bg;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        rtb__PosY0_met_le = rtb_Sum_hf;
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedRiPosY0_met'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__PosY0_met_le = GET_S_TJACMB_CombinedRiPosY0_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant1'/Constant'
                                 *  Inport: '<Root>/S_TJACMB_CombinedRiPosY0_met'
                                 */
                switch (rtb_DataTypeConversion_h5) {
                case 0:
                    rtb__PosY0_met_le = GET_S_TJACMB_CombinedRiPosY0_met();
                    break;
                case 1:
                    break;
                case 2:
                    rtb__PosY0_met_le = rtb_Sum_hf;
                    break;
                default:
                    rtb__PosY0_met_le = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb_Sum_hf = rtb_Mul_cy;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
        rtb__Crv_1pm_e1 = rtb__Crv_1pm_go;
        break;
    case 1:
        rtb_Sum_hf = rtb__Heading_rad_d;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
        rtb__Crv_1pm_e1 = rtb__Crv_1pm_l1;
        break;
    case 2:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch2/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_RiAdjLnClthHeading_rad'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb_Sum_hf = GET_S_ABPALP_RiAdjLnClthHeading_rad();
        } else {
            rtb_Sum_hf = rtb_Mul_cy;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch2/Functionality'/Switch' */
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch3/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_RiAdjLnClthCrv_1pm'
                 *  MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb__Crv_1pm_e1 = GET_S_ABPALP_RiAdjLnClthCrv_1pm();
        } else {
            rtb__Crv_1pm_e1 = rtb__Crv_1pm_go;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch3/Functionality'/Switch' */
        break;
    default:
        rtb_Sum_hf = rtb_Mul_cy;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
        rtb__Crv_1pm_e1 = rtb__Crv_1pm_go;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                 *  X.2.1.1.13
                 */
        rtb_Sum_hf = GET_S_ODPFOH_TgtObjHeadAng_rad();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedHeading_rad'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb_Sum_hf = GET_S_TJACMB_CombinedHeading_rad();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant2'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
                                 *  Inport: '<Root>/S_TJACMB_CombinedHeading_rad'
                                 */
                switch (rtb_DataTypeConversion_h5) {
                case 0:
                    rtb_Sum_hf = GET_S_TJACMB_CombinedHeading_rad();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                                         *  X.2.1.1.13
                                         */
                    rtb_Sum_hf = GET_S_ODPFOH_TgtObjHeadAng_rad();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
                    break;
                default:
                    rtb_Sum_hf = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__ChngOfCrv_1pm2_l = rtb__ChngOfCrv_1pm2_ai;
        break;
    case 1:
        rtb__ChngOfCrv_1pm2_l = rtb__ChngOfCrv_1pm2_ji;
        break;
    case 2:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch4/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_RiAdjLnClthCrvChng_1pm2'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb__ChngOfCrv_1pm2_l = GET_S_ABPALP_RiAdjLnClthCrvChng_1pm2();
        } else {
            rtb__ChngOfCrv_1pm2_l = rtb__ChngOfCrv_1pm2_ai;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch4/Functionality'/Switch' */
        break;
    default:
        rtb__ChngOfCrv_1pm2_l = rtb__ChngOfCrv_1pm2_ai;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                 *  X.2.1.1.13
                 */
        rtb__Crv_1pm_e1 = GET_S_ODPFOH_TgtObjCrv_1pm();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedCrv_1pm'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__Crv_1pm_e1 = GET_S_TJACMB_CombinedCrv_1pm();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant3'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
                                 *  Inport: '<Root>/S_TJACMB_CombinedCrv_1pm'
                                 */
                switch (rtb_DataTypeConversion_h5) {
                case 0:
                    rtb__Crv_1pm_e1 = GET_S_TJACMB_CombinedCrv_1pm();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                                         *  X.2.1.1.13
                                         */
                    rtb__Crv_1pm_e1 = GET_S_ODPFOH_TgtObjCrv_1pm();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
                    break;
                default:
                    rtb__Crv_1pm_e1 = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__TrajLength_met_ih = rtb__TrajLength_met_p;
        break;
    case 1:
        rtb__TrajLength_met_ih = rtb__TrajLength_met_hg;
        break;
    case 2:
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch5/Functionality'/Switch' incorporates:
                 *  Inport: '<Root>/S_ABPALP_RiAdjLnClthLength_met'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb__TrajLength_met_ih = GET_S_ABPALP_RiAdjLnClthLength_met();
        } else {
            rtb__TrajLength_met_ih = rtb__TrajLength_met_p;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Switch5/Functionality'/Switch' */
        break;
    default:
        rtb__TrajLength_met_ih = rtb__TrajLength_met_p;
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch1'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrvChng_1pm2'
         *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                 *
                 * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                 *  X.2.1.1.13
                 */
        rtb__ChngOfCrv_1pm2_l = GET_S_ODPFOH_TgtObjCrvChng_1pm2();
        rtb__TrajLength_met_ih = GET_S_ODPFOH_TgtObjLength_met();
        /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedCrvChng_1pm2'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__ChngOfCrv_1pm2_l = GET_S_TJACMB_CombinedCrvChng_1pm2();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant4'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjCrvChng_1pm2'
                                 *  Inport: '<Root>/S_TJACMB_CombinedCrvChng_1pm2'
                                 */
                switch (rtb_DataTypeConversion_h5) {
                case 0:
                    rtb__ChngOfCrv_1pm2_l = GET_S_TJACMB_CombinedCrvChng_1pm2();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                                         *  X.2.1.1.13
                                         */
                    rtb__ChngOfCrv_1pm2_l = GET_S_ODPFOH_TgtObjCrvChng_1pm2();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
                    break;
                default:
                    rtb__ChngOfCrv_1pm2_l = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch' */
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedLength_met'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__TrajLength_met_ih = GET_S_TJACMB_CombinedLength_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection/Else/Constant5'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
                                 *  Inport: '<Root>/S_TJACMB_CombinedLength_met'
                                 */
                switch (rtb_DataTypeConversion_h5) {
                case 0:
                    rtb__TrajLength_met_ih = GET_S_TJACMB_CombinedLength_met();
                    break;
                case 1:
                    break;
                case 2:
                    /* Outputs for Atomic SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid'
                                         *
                                         * Block description for 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid':
                                         *  X.2.1.1.13
                                         */
                    rtb__TrajLength_met_ih = GET_S_ODPFOH_TgtObjLength_met();
                    /* End of Outputs for SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/ObjectRightClothoid' */
                    break;
                default:
                    rtb__TrajLength_met_ih = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion_ji = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch11/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch3/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch4/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch5/Functionality'/Switch'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_i) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch6/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch7/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay1'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb_Switch_oa = DW_tjattg_Unit_Delay2_DSTATE_h;
            rtb_Switch_e = DW_tjattg_Unit_Delay1_DSTATE_kv;
        } else {
            rtb_Switch_oa = DW_tjattg_Unit_Delay_8_DSTATE;
            rtb_Switch_e = DW_tjattg_Unit_Delay_9_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch6/Functionality'/Switch' */
        rtb__PosY0_met_le = ((1.0F - rtb_Div_j) * rtb__PosY0_met_le) + (rtb_Switch_oa * rtb_Div_j);
        rtb_Sum_hf = ((1.0F - rtb_Div_j) * rtb_Sum_hf) + (rtb_Switch_e * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Constant'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch9/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay3'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay4'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb_Switch_ph = DW_tjattg_Unit_Delay3_DSTATE_i;
            rtb_Switch_kw = DW_tjattg_Unit_Delay4_DSTATE_b;
        } else {
            rtb_Switch_ph = DW_tjattg_Unit_Delay_10_DSTATE;
            rtb_Switch_kw = DW_tjattg_Unit_Delay_11_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch8/Functionality'/Switch' */
        rtb__Crv_1pm_e1 = ((1.0F - rtb_Div_j) * rtb__Crv_1pm_e1) + (rtb_Switch_ph * rtb_Div_j);
        rtb__ChngOfCrv_1pm2_l = ((1.0F - rtb_Div_j) * rtb__ChngOfCrv_1pm2_l) + (rtb_Switch_kw * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Constant'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch12/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay5'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay6'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion_ji) != 0) {
            rtb_Switch_h = DW_tjattg_Unit_Delay5_DSTATE_l;
            rtb_Switch_k2 = DW_tjattg_Unit_Delay6_DSTATE_a;
        } else {
            rtb_Switch_h = DW_tjattg_Unit_Delay_12_DSTATE;
            rtb_Switch_k2 = DW_tjattg_Unit_Delay_7_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch10/Functionality'/Switch' */
        rtb__TrajLength_met_ih = ((1.0F - rtb_Div_j) * rtb__TrajLength_met_ih) + (rtb_Switch_h * rtb_Div_j);
        rtb__PosX0_met_mb = ((1.0F - rtb_Div_j) * rtb__PosX0_met_mb) + (rtb_Switch_k2 * rtb_Div_j);
    } else {
        rtb_Switch_oa = DW_tjattg_Unit_Delay_8_DSTATE;
        rtb_Switch_e = DW_tjattg_Unit_Delay_9_DSTATE;
        rtb_Switch_ph = DW_tjattg_Unit_Delay_10_DSTATE;
        rtb_Switch_kw = DW_tjattg_Unit_Delay_11_DSTATE;
        rtb_Switch_h = DW_tjattg_Unit_Delay_12_DSTATE;
        rtb_Switch_k2 = DW_tjattg_Unit_Delay_7_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch1/Functionality'/Switch' */
    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' incorporates:
         *  Inport: '<Root>/S_ABPLBP_CntrLnClthPosX0_met'
         *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
         *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
         */
    switch (rtb_DataTypeConversion_f) {
    case 0:
        rtb__PosX0_met_g = GET_S_ABPLBP_CntrLnClthPosX0_met();
        break;
    case 1:
        rtb__PosX0_met_g = GET_S_ABPLBP_LeLnClthPosX0_met();
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Constant'/Constant'
                 *  Inport: '<Root>/S_ABPLBP_LeLnClthPosX0_met'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Mul/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/LeftAdjacentLane/Sum/Functionality'/Sum'
                 */
        rtb_MathFunction = (rtb_MathFunction_k + rtb_Mul) * 0.5F;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb_Mul_oo = rtb__Heading_rad_d;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb__Crv_1pm = rtb__Crv_1pm_l1;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb__ChngOfCrv_1pm2 = rtb__ChngOfCrv_1pm2_ji;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb_Sum_mx = rtb__TrajLength_met_hg;
        break;
    case 2:
        rtb__PosX0_met_g = GET_S_ABPLBP_RiLnClthPosX0_met();
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Constant'/Constant'
                 *  Inport: '<Root>/S_ABPLBP_RiLnClthPosX0_met'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Mul/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/RightAdjacentLane/Sum/Functionality'/Sum'
                 */
        rtb_MathFunction = (rtb_Sum_bg + rtb_Switch_hw) * 0.5F;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb_Mul_oo = rtb_Mul_cy;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb__Crv_1pm = rtb__Crv_1pm_go;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb__ChngOfCrv_1pm2 = rtb__ChngOfCrv_1pm2_ai;
        /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
        rtb_Sum_mx = rtb__TrajLength_met_p;
        break;
    default:
        rtb__PosX0_met_g = GET_S_ABPLBP_CntrLnClthPosX0_met();
        break;
    }
    /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/SALC_CorridorShift/BusSwitch2'/Multiport_Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Constant'/Constant'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/AND/Functionality'/AND'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
         */
    if ((((sint32)rtb_DataTypeConversion) != 0) && (((sint32) rtb_DataTypeConversion_ab) != 0)) {
        rtb_DataTypeConversion = 0U;
    } else {
        if (((sint32)rtb_DataTypeConversion) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch' incorporates:
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Constant2'/Constant'
                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Constant3'/Constant'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Switch1/Functionality'/Switch'
                         */
            if (((sint32)rtb_DataTypeConversion_ab) != 0) {
                rtb_DataTypeConversion = 2U;
            } else {
                rtb_DataTypeConversion = 3U;
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Switch2/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/CreateSwitch/Switch/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' incorporates:
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrvChng_1pm2'
         *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
         *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
         *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
         *  Inport: '<Root>/S_ODPFOH_TgtObjPosY0_met'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
         */
    if (((sint32)rtb_Switch_hs) != 0) {
        rtb__PosX0_met_g = GET_S_ODPFOH_TgtObjPosX0_met();
        rtb_MathFunction = GET_S_ODPFOH_TgtObjPosY0_met();
        rtb_Mul_oo = GET_S_ODPFOH_TgtObjHeadAng_rad();
        rtb__Crv_1pm = GET_S_ODPFOH_TgtObjCrv_1pm();
        rtb__ChngOfCrv_1pm2 = GET_S_ODPFOH_TgtObjCrvChng_1pm2();
        rtb_Sum_mx = GET_S_ODPFOH_TgtObjLength_met();
    } else {
        if (((sint32)rtb_Switch_pi) == 0) {
            /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' incorporates:
                         *  Inport: '<Root>/S_TJACMB_CombinedCrvChng_1pm2'
                         *  Inport: '<Root>/S_TJACMB_CombinedCrv_1pm'
                         *  Inport: '<Root>/S_TJACMB_CombinedHeading_rad'
                         *  Inport: '<Root>/S_TJACMB_CombinedLength_met'
                         *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                         *  Inport: '<Root>/S_TJACMB_CombinedPosY0_met'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch4/Functionality'/Switch'
                         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch'
                         */
            if (((sint32)rtb_Switch_kog) != 0) {
                rtb__PosX0_met_g = GET_S_TJACMB_CombinedPosX0_met();
                rtb_MathFunction = GET_S_TJACMB_CombinedPosY0_met();
                rtb_Mul_oo = GET_S_TJACMB_CombinedHeading_rad();
                rtb__Crv_1pm = GET_S_TJACMB_CombinedCrv_1pm();
                rtb__ChngOfCrv_1pm2 = GET_S_TJACMB_CombinedCrvChng_1pm2();
                rtb_Sum_mx = GET_S_TJACMB_CombinedLength_met();
            } else {
                /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant'/Constant'
                                 *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
                                 *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                                 */
                switch (rtb_DataTypeConversion) {
                case 0:
                    rtb__PosX0_met_g = GET_S_TJACMB_CombinedPosX0_met();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_TJACMB_CombinedPosX0_met'
                                         *  Inport: '<Root>/S_TJACMB_CombinedPosY0_met'
                                         */
                    rtb_MathFunction = GET_S_TJACMB_CombinedPosY0_met();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_TJACMB_CombinedHeading_rad'
                                         */
                    rtb_Mul_oo = GET_S_TJACMB_CombinedHeading_rad();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_TJACMB_CombinedCrv_1pm'
                                         */
                    rtb__Crv_1pm = GET_S_TJACMB_CombinedCrv_1pm();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_TJACMB_CombinedCrvChng_1pm2'
                                         */
                    rtb__ChngOfCrv_1pm2 = GET_S_TJACMB_CombinedCrvChng_1pm2();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_TJACMB_CombinedLength_met'
                                         */
                    rtb_Sum_mx = GET_S_TJACMB_CombinedLength_met();
                    break;
                case 1:
                    break;
                case 2:
                    rtb__PosX0_met_g = GET_S_ODPFOH_TgtObjPosX0_met();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_ODPFOH_TgtObjPosX0_met'
                                         *  Inport: '<Root>/S_ODPFOH_TgtObjPosY0_met'
                                         */
                    rtb_MathFunction = GET_S_ODPFOH_TgtObjPosY0_met();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_ODPFOH_TgtObjHeadAng_rad'
                                         */
                    rtb_Mul_oo = GET_S_ODPFOH_TgtObjHeadAng_rad();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_ODPFOH_TgtObjCrv_1pm'
                                         */
                    rtb__Crv_1pm = GET_S_ODPFOH_TgtObjCrv_1pm();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_ODPFOH_TgtObjCrvChng_1pm2'
                                         */
                    rtb__ChngOfCrv_1pm2 = GET_S_ODPFOH_TgtObjCrvChng_1pm2();
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Inport: '<Root>/S_ODPFOH_TgtObjLength_met'
                                         */
                    rtb_Sum_mx = GET_S_ODPFOH_TgtObjLength_met();
                    break;
                default:
                    rtb__PosX0_met_g = 0.0F;
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant'/Constant'
                                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant1'/Constant'
                                         */
                    rtb_MathFunction = 0.0F;
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant2'/Constant'
                                         */
                    rtb_Mul_oo = 0.0F;
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant3'/Constant'
                                         */
                    rtb__Crv_1pm = 0.0F;
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant4'/Constant'
                                         */
                    rtb__ChngOfCrv_1pm2 = 0.0F;
                    /* MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' incorporates:
                                         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection/Else/Constant5'/Constant'
                                         */
                    rtb_Sum_mx = 0.0F;
                    break;
                }
                /* End of MultiPortSwitch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/TargetCorridorSelection'/Multiport_Switch' */
            }
            /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch6/Functionality'/Switch' */
        }
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/IV_Selection/Switch2/Functionality'/Switch' */
    /* DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/NOT/Functionality'/Data Type Conversion' incorporates:
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/NOT/Functionality'/NOT'
         */
    rtb_DataTypeConversion = (uint8)(!(((sint32)rtb_DataTypeConversion_d) != 0));
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch1/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Constant'/Constant'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Constant'/Constant'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Mul1/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Mul/Functionality'/Mul'
         *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Mul1/Functionality'/Mul'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/A_Filter/Sum1/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Sum/Functionality'/Sum'
         *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/A_Filter/Sum1/Functionality'/Sum'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering4/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering5/Switch1/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch11/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch2/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch3/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch4/Functionality'/Switch'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch5/Functionality'/Switch'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
         */
    if (((sint32)rtb_DataTypeConversion_i) != 0) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch6/Functionality'/Switch' incorporates:
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch7/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay1'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay2'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb_MathFunction_k = DW_tjattg_Unit_Delay2_DSTATE_c;
            rtb__Heading_rad_d = DW_tjattg_Unit_Delay1_DSTATE_d;
        } else {
            rtb_MathFunction_k = DW_tjattg_Unit_Delay_14_DSTATE;
            rtb__Heading_rad_d = DW_tjattg_Unit_Delay_15_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch6/Functionality'/Switch' */
        rtb_MathFunction = ((1.0F - rtb_Div_j) * rtb_MathFunction) + (rtb_MathFunction_k * rtb_Div_j);
        rtb_Mul_oo = ((1.0F - rtb_Div_j) * rtb_Mul_oo) + (rtb__Heading_rad_d * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch8/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Constant'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering/A_Filter/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering1/A_Filter/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch9/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay3'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay4'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb__Crv_1pm_l1 = DW_tjattg_Unit_Delay3_DSTATE_if;
            rtb__ChngOfCrv_1pm2_ji = DW_tjattg_Unit_Delay4_DSTATE_a;
        } else {
            rtb__Crv_1pm_l1 = DW_tjattg_Unit_Delay_16_DSTATE;
            rtb__ChngOfCrv_1pm2_ji = DW_tjattg_Unit_Delay_17_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch8/Functionality'/Switch' */
        rtb__Crv_1pm = ((1.0F - rtb_Div_j) * rtb__Crv_1pm) + (rtb__Crv_1pm_l1 * rtb_Div_j);
        rtb__ChngOfCrv_1pm2 = ((1.0F - rtb_Div_j) * rtb__ChngOfCrv_1pm2) + (rtb__ChngOfCrv_1pm2_ji * rtb_Div_j);
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch10/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Constant'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Constant'/Constant'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Mul1/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul/Functionality'/Mul'
                 *  Product: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Mul1/Functionality'/Mul'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering2/A_Filter/Sum1/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum/Functionality'/Sum'
                 *  Sum: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/A_Filtering3/A_Filter/Sum1/Functionality'/Sum'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch12/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay5'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay6'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay'
                 */
        if (((sint32)rtb_DataTypeConversion) != 0) {
            rtb__TrajLength_met_hg = DW_tjattg_Unit_Delay5_DSTATE_b;
            rtb_Sum_bg = DW_tjattg_Unit_Delay6_DSTATE_f;
        } else {
            rtb__TrajLength_met_hg = DW_tjattg_Unit_Delay_18_DSTATE;
            rtb_Sum_bg = DW_tjattg_Unit_Delay_13_DSTATE;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch10/Functionality'/Switch' */
        rtb_Sum_mx = ((1.0F - rtb_Div_j) * rtb_Sum_mx) + (rtb__TrajLength_met_hg * rtb_Div_j);
        rtb__PosX0_met_g = ((1.0F - rtb_Div_j) * rtb__PosX0_met_g) + (rtb_Sum_bg * rtb_Div_j);
    } else {
        rtb_MathFunction_k = DW_tjattg_Unit_Delay_14_DSTATE;
        rtb__Heading_rad_d = DW_tjattg_Unit_Delay_15_DSTATE;
        rtb__Crv_1pm_l1 = DW_tjattg_Unit_Delay_16_DSTATE;
        rtb__ChngOfCrv_1pm2_ji = DW_tjattg_Unit_Delay_17_DSTATE;
        rtb__TrajLength_met_hg = DW_tjattg_Unit_Delay_18_DSTATE;
        rtb_Sum_bg = DW_tjattg_Unit_Delay_13_DSTATE;
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze/Switch1/Functionality'/Switch' */
    /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Switch/Functionality'/Switch' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/from_data_definition4'/state_source'
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/from_data_definition5'/state_source'
         *  Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/OR2/Functionality'/OR'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/EQ6/Functionality'/EQ'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/EQ7/Functionality'/EQ'
         *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Switch/Functionality'/Switch'
         */
    if (!((((sint32)((uint8)E_LCF_SysStateType_E_LCF_SYSSTATE_REQUEST_nu)) == ((sint32)GET_S_TJASTM_SysStateTJA_nu())) || (((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_CONTROLLING_nu)) == ((sint32) GET_S_TJASTM_SysStateTJA_nu())))) {
        /* Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Switch1/Functionality'/Switch' incorporates:
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/from_data_definition3'/state_source'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LaneCenter/Constant4'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LaneCenter/Constant5'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LaneCenter/Constant6'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LaneCenter/Constant7'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LaneCenter/Constant8'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LaneCenter/Constant9'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LeftBoundary/Constant4'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LeftBoundary/Constant5'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LeftBoundary/Constant6'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LeftBoundary/Constant7'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LeftBoundary/Constant8'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/LeftBoundary/Constant9'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/RightBoundary/Constant4'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/RightBoundary/Constant5'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/RightBoundary/Constant6'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/RightBoundary/Constant7'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/RightBoundary/Constant8'/Constant'
                 *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Else/RightBoundary/Constant9'/Constant'
                 *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/EQ4/Functionality'/EQ'
                 *  Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Switch1/Functionality'/Switch'
                 *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1'
                 */
        if (((sint32)GET_S_TJASTM_SysStateTJA_nu()) == ((sint32)((uint8) E_LCF_SysStateType_E_LCF_SYSSTATE_RAMPOUT_nu))) {
            rtb_Switch1_g = DW_tjattg_Unit_Delay1_1_DSTATE;
            rtb__Crv_1pm_e1 = DW_tjattg_Unit_Delay1_10_DSTATE;
            rtb__ChngOfCrv_1pm2_l = DW_tjattg_Unit_Delay1_11_DSTATE;
            rtb__TrajLength_met_ih = DW_tjattg_Unit_Delay1_12_DSTATE;
            rtb__PosX0_met_g = DW_tjattg_Unit_Delay1_13_DSTATE;
            rtb_MathFunction = DW_tjattg_Unit_Delay1_14_DSTATE;
            rtb_Mul_oo = DW_tjattg_Unit_Delay1_15_DSTATE;
            rtb__Crv_1pm = DW_tjattg_Unit_Delay1_16_DSTATE;
            rtb__ChngOfCrv_1pm2 = DW_tjattg_Unit_Delay1_17_DSTATE;
            rtb_Sum_mx = DW_tjattg_Unit_Delay1_18_DSTATE;
            rtb_Switch1_h = DW_tjattg_Unit_Delay1_2_DSTATE;
            rtb_Switch1 = DW_tjattg_Unit_Delay1_3_DSTATE;
            rtb_Sum = DW_tjattg_Unit_Delay1_4_DSTATE;
            rtb__ChngOfCrv_1pm2_k = DW_tjattg_Unit_Delay1_5_DSTATE;
            rtb__TrajLength_met_i = DW_tjattg_Unit_Delay1_6_DSTATE;
            rtb__PosX0_met_mb = DW_tjattg_Unit_Delay1_7_DSTATE;
            rtb__PosY0_met_le = DW_tjattg_Unit_Delay1_8_DSTATE;
            rtb_Sum_hf = DW_tjattg_Unit_Delay1_9_DSTATE;
        } else {
            rtb_Switch1_g = 0.0F;
            rtb__Crv_1pm_e1 = 0.0F;
            rtb__ChngOfCrv_1pm2_l = 0.0F;
            rtb__TrajLength_met_ih = 0.0F;
            rtb__PosX0_met_g = 0.0F;
            rtb_MathFunction = 0.0F;
            rtb_Mul_oo = 0.0F;
            rtb__Crv_1pm = 0.0F;
            rtb__ChngOfCrv_1pm2 = 0.0F;
            rtb_Sum_mx = 0.0F;
            rtb_Switch1_h = 0.0F;
            rtb_Switch1 = 0.0F;
            rtb_Sum = 0.0F;
            rtb__ChngOfCrv_1pm2_k = 0.0F;
            rtb__TrajLength_met_i = 0.0F;
            rtb__PosX0_met_mb = 0.0F;
            rtb__PosY0_met_le = 0.0F;
            rtb_Sum_hf = 0.0F;
        }
        /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Switch1/Functionality'/Switch' */
    }
    /* End of Switch: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling/Switch/Functionality'/Switch' */
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch1'/copy1' */
    SET_S_TJATTG_LeCridrBndPosY0_met(rtb_Switch1_h);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch10'/copy1' */
    SET_S_TJATTG_RiCridrBndCrvChng_1pm2(rtb__ChngOfCrv_1pm2_l);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch11'/copy1' */
    SET_S_TJATTG_RiCridrBndCrv_1pm(rtb__Crv_1pm_e1);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch12'/copy1' */
    SET_S_TJATTG_RiCridrBndLength_met(rtb__TrajLength_met_ih);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch13'/copy1' */
    SET_S_TJATTG_PredictionEnable_bool(rtb_SignalConversion1);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch14'/copy1' */
    SET_S_TJATTG_TgtTrajLength_met(rtb_Sum_mx);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch15'/copy1' */
    SET_S_TJATTG_TransTriggerReplan_bool(rtb_DataTypeConversion_lq);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch16'/copy1' */
    SET_S_TJATTG_TgtTrajPosX0_met(rtb__PosX0_met_g);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch17'/copy1' */
    SET_S_TJATTG_TgtTrajPosY0_met(rtb_MathFunction);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch18'/copy1' */
    SET_S_TJATTG_TgtTrajCrv_1pm(rtb__Crv_1pm);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch19'/copy1' */
    SET_S_TJATTG_TgtTrajHeadAng_rad(rtb_Mul_oo);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch2'/copy1' */
    SET_S_TJATTG_LeCridrBndPosX0_met(rtb_Switch1_g);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch20'/copy1' */
    SET_S_TJATTG_TgtTrajCrvChng_1pm2(rtb__ChngOfCrv_1pm2);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch21'/copy1' */
    SET_D_TJATTG_TgtCorridorInvalid_btf(rtb_sfun_setbit);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch3'/copy1' */
    SET_S_TJATTG_LeCridrBndHeadAng_rad(rtb_Switch1);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch4'/copy1' */
    SET_S_TJATTG_LeCridrBndCrvChng_1pm2(rtb__ChngOfCrv_1pm2_k);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch5'/copy1' */
    SET_S_TJATTG_LeCridrBndCrv_1pm(rtb_Sum);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch6'/copy1' */
    SET_S_TJATTG_LeCridrBndLength_met(rtb__TrajLength_met_i);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch7'/copy1' */
    SET_S_TJATTG_RiCridrBndPosY0_met(rtb__PosY0_met_le);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch8'/copy1' */
    SET_S_TJATTG_RiCridrBndPosX0_met(rtb__PosX0_met_mb);
    /* SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/branch9'/copy1' */
    SET_S_TJATTG_RiCridrBndHeadAng_rad(rtb_Sum_hf);
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler3'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_a = rtb_Switch_jmj;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tjattg_Unit_Delay1_DSTATE_f = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions'/Unit_Delay5' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_SysStateTJA_nu'
         */
    DW_tjattg_Unit_Delay5_DSTATE_k = GET_S_TJASTM_SysStateTJA_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay5' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tjattg_Unit_Delay5_DSTATE_i = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay4' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition4'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ4/Functionality'/EQ'
         */
    DW_tjattg_Unit_Delay4_DSTATE_l = (uint8)(((sint32)GET_S_TJACMB_CombinedMode_nu ()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)));
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay7' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tjattg_Unit_Delay7_DSTATE = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay6' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition9'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ9/Functionality'/EQ'
         */
    DW_tjattg_Unit_Delay6_DSTATE_h = (uint8)(((sint32)GET_S_TJACMB_CombinedMode_nu ()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)));
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay3' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition2'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ2/Functionality'/EQ'
         */
    DW_tjattg_Unit_Delay3_DSTATE_l = (uint8)(((sint32)GET_S_TJACMB_CombinedMode_nu ()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)));
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay2' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition16'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ17/Functionality'/EQ'
         */
    DW_tjattg_Unit_Delay2_DSTATE_cx = (uint8)(((sint32) GET_S_TJACMB_CombinedMode_nu()) == ((sint32)((uint8) E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)));
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay1' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tjattg_Unit_Delay1_DSTATE_j = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition13'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ15/Functionality'/EQ'
         */
    DW_tjattg_Unit_Delay_DSTATE_l = (uint8)(((sint32)GET_S_TJACMB_CombinedMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_OF)));
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay9' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tjattg_Unit_Delay9_DSTATE = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions'/Unit_Delay8' incorporates:
         *  Constant: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/from_data_definition10'/state_source'
         *  Inport: '<Root>/S_TJACMB_CombinedMode_nu'
         *  RelationalOperator: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CombinedModeTransitions/EQ10/Functionality'/EQ'
         */
    DW_tjattg_Unit_Delay8_DSTATE = (uint8)(((sint32)GET_S_TJACMB_CombinedMode_nu()) == ((sint32)((uint8)E_TJASTM_LatCtrlMdV4Type_E_TJASTM_LATCTRLMD_LC)));
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality'/Comparison'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality'/Comparison'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction'/Unit_Delay' incorporates:
         *  DataTypeConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/OR/Functionality'/Data Type Conversion'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/OR/Functionality'/OR'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality'/Logical Operator2'
         *  Logic: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality/Comparison'/Logical Operator'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict'/Unit_Delay1'
         *  UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict'/Unit_Delay1'
         */
    DW_tjattg_Unit_Delay_DSTATE_fj = (uint8)(((!(((sint32) DW_tjattg_Unit_Delay1_DSTATE_a) != 0)) && (((sint32)rtb_DataTypeConversion_k) != 0)) || ((!(((sint32)DW_tjattg_Unit_Delay1_DSTATE_b) != 0)) && (((sint32) rtb_DataTypeConversion_g) != 0)));
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING'/fcg' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING'/fcg' */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay1_DSTATE_p = rtb_DataTypeConversion_c5;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl/EdgeRising/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictionControl'/Unit_Delay3' */
    DW_tjattg_Unit_Delay3_DSTATE_m = rtb_SignalConversion1;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeControl/CheckPredictionConditions'/Unit_Delay5' */
    DW_tjattg_Unit_Delay5_DSTATE_j = SignalConversion;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SALC_ManeuverStart'/Unit_Delay' incorporates:
         *  Update for Inport: '<Root>/S_TJASTM_LatCtrlMode_nu'
         */
    DW_tjattg_Unit_Delay_DSTATE_az = GET_S_TJASTM_LatCtrlMode_nu();
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/TurnOffDelayTimeCUSTOM'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE = rtb_Switch;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler1'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_l = rtb_Switch_kog;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler2'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_f = rtb_Switch_pi;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionSpecificEnabler'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_p = rtb_Switch_hs;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_e = rtb_Switch_crb;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_DSTATE = rtb_Mul_ac;
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay1_DSTATE_a = rtb_DataTypeConversion_k;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/LengthPredict/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_n = rtb_Switch_mv;
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING'/fcg' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING'/Functionality'
         */
    /* S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' incorporates:
         *  SubSystem: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality'/SignalConversion'
         */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict'/Unit_Delay1' incorporates:
         *  SignalConversion: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality/SignalConversion'/Signal Conversion'
         */
    DW_tjattg_Unit_Delay1_DSTATE_b = rtb_DataTypeConversion_g;
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING/Functionality/sequencer'/Function-Call Generator' */
    /* End of Outputs for S-Function (fcncallgen): 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/LengthPredict/EDGERISING'/fcg' */
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze1'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_m = rtb_Switch_i;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvChngPredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_d = rtb_SFunction;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze2'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_c = rtb_Switch_p;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/CurvaturePredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_a = rtb_SFunction_b;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze3'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_cg = rtb_Switch_dw;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLaneCenterCorridor/Subsystem/Freeze4'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_i = rtb_Switch_cl;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictVehicleOdometrie'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE = rtb_Mul_nl;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze1'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_b = rtb_Switch_o;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvChngPredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_n5 = rtb_SFunction_d;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze2'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_oj = rtb_Switch_ov;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/CurvaturePredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_f = rtb_SFunction_l;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze3'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_h = rtb_Switch_l4;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/Freeze4'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_p = rtb_Switch_lqw;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictLeftLaneBoundary/Subsystem/LengthPredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_hs = rtb_Switch_l;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze1'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_ie = rtb_Switch_pp;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvChngPredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_eg = rtb_SFunction_m;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze2'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_ij = rtb_Switch_na;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/CurvaturePredict'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_k = rtb_SFunction_j;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze3'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_h4 = rtb_Mul_k5;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LanePrediction/PredictRightLaneBoundary/Subsystem/Freeze4'/Unit_Delay' */
    DW_tjattg_Unit_Delay_DSTATE_ba = rtb_Switch_n;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_n = rtb_Switch_iz;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_2_DSTATE = rtb_Switch1_h;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/CalculateTransitionFactorA'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_DSTATE_n = rtb_Switch3;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/ModeTransitionHandling/ObserveModeTransitions/SetTransitionTime/SetTransitionTime'/Unit_Delay5' */
    DW_tjattg_Unit_Delay5_DSTATE = rtb_Switch_kv;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_DSTATE_k = rtb_Switch_aec;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_3_DSTATE = rtb_Switch1;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay3' */
    DW_tjattg_Unit_Delay3_DSTATE = rtb_Switch_bxu;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_4_DSTATE = rtb_Sum;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay4' */
    DW_tjattg_Unit_Delay4_DSTATE = rtb_Switch_g;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_5_DSTATE = rtb__ChngOfCrv_1pm2_k;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay5' */
    DW_tjattg_Unit_Delay5_DSTATE_g = rtb_Switch_cv;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_6_DSTATE = rtb__TrajLength_met_i;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/LeftCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay6' */
    DW_tjattg_Unit_Delay6_DSTATE = rtb_Switch_ey;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_1_DSTATE = rtb_Switch1_g;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_h = rtb_Switch_oa;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_8_DSTATE = rtb__PosY0_met_le;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_DSTATE_kv = rtb_Switch_e;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_9_DSTATE = rtb_Sum_hf;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay3' */
    DW_tjattg_Unit_Delay3_DSTATE_i = rtb_Switch_ph;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_10_DSTATE = rtb__Crv_1pm_e1;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay4' */
    DW_tjattg_Unit_Delay4_DSTATE_b = rtb_Switch_kw;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_11_DSTATE = rtb__ChngOfCrv_1pm2_l;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay5' */
    DW_tjattg_Unit_Delay5_DSTATE_l = rtb_Switch_h;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_12_DSTATE = rtb__TrajLength_met_ih;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/RightCorridorBoundaryGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay6' */
    DW_tjattg_Unit_Delay6_DSTATE_a = rtb_Switch_k2;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_7_DSTATE = rtb__PosX0_met_mb;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay2' */
    DW_tjattg_Unit_Delay2_DSTATE_c = rtb_MathFunction_k;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_14_DSTATE = rtb_MathFunction;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_DSTATE_d = rtb__Heading_rad_d;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_15_DSTATE = rtb_Mul_oo;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay3' */
    DW_tjattg_Unit_Delay3_DSTATE_if = rtb__Crv_1pm_l1;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_16_DSTATE = rtb__Crv_1pm;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay4' */
    DW_tjattg_Unit_Delay4_DSTATE_a = rtb__ChngOfCrv_1pm2_ji;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_17_DSTATE = rtb__ChngOfCrv_1pm2;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay5' */
    DW_tjattg_Unit_Delay5_DSTATE_b = rtb__TrajLength_met_hg;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_18_DSTATE = rtb_Sum_mx;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorGeneration/ModeTransitionFilter/TransitionFilter/Freeze_IV/Freeze'/Unit_Delay6' */
    DW_tjattg_Unit_Delay6_DSTATE_f = rtb_Sum_bg;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG'/Unit_Delay' */
    DW_tjattg_Unit_Delay_13_DSTATE = rtb__PosX0_met_g;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_1_DSTATE = rtb_Switch1_g;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_2_DSTATE = rtb_Switch1_h;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_3_DSTATE = rtb_Switch1;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_4_DSTATE = rtb_Sum;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_5_DSTATE = rtb__ChngOfCrv_1pm2_k;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_6_DSTATE = rtb__TrajLength_met_i;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_7_DSTATE = rtb__PosX0_met_mb;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_8_DSTATE = rtb__PosY0_met_le;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_9_DSTATE = rtb_Sum_hf;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_10_DSTATE = rtb__Crv_1pm_e1;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_11_DSTATE = rtb__ChngOfCrv_1pm2_l;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_12_DSTATE = rtb__TrajLength_met_ih;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_13_DSTATE = rtb__PosX0_met_g;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_14_DSTATE = rtb_MathFunction;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_15_DSTATE = rtb_Mul_oo;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_16_DSTATE = rtb__Crv_1pm;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_17_DSTATE = rtb__ChngOfCrv_1pm2;
    /* Update for UnitDelay: 'sda:TJATTG/TJATTG/TJATTG_SenProcess/TJATTG/TJATTG/TargetCorridorStateHandling'/Unit_Delay1' */
    DW_tjattg_Unit_Delay1_18_DSTATE = rtb_Sum_mx;
}
#include "Pse_TJATTG.h"
/* End of General Functions */
/* Specific Functions */
/* End of Specific Functions */
